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
 * ChatAppGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Chat App.
 *
 * Author:
 * -------
 * -------
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ChatAppGprot.h

   PURPOSE     : Chat application 

   REMARKS     : nil

   AUTHOR      : Alok Sharma     

   DATE     : Feb 18,04

**************************************************************/

#include "MMI_features.h"
#ifdef __MMI_MESSAGES_CHAT__

#ifndef _CHATGPROT_H
#define  _CHATGPROT_H

extern void EntryChatApp(void);
extern void SetChatHiliteHandlers(void);
extern void PreSendChatMsg(void);
extern S16 GetNumOfMessage(S16);
extern PU8 AllocMemory(S32, S16);
extern void ResetMemoryBuffer(S16);
extern void ResetRoundedFlag(S16);
extern void IncrementCounter(S16);
extern void EntryChatRoom(void);
extern void ExitChatRoom(void);

extern U16 CheckForChatNumber(PU8 number, U8 len, U8 type);
extern U8 CheckForChatMessage(void *data, int withobject, void *content);
extern U8 HandleChatMessage(void *data, void *content);

/* extern void temp_func(); */
extern void DisplayChatPopUpWindow(void);
extern void RemoveInvitationChar(void);

extern pBOOL CheckForInvitationMsg(PU8 data, S32 length, pBOOL flag);
extern void OnSMSChatSendSuccess(void);
extern void SetMessagechatRoomNo(S16 index);
extern S16 GetMessagechatRoomNo(void);
extern void ResetMessagechatRoomNo(void);
extern void SetCurrentChatRoomNo(S16 index);
extern S16 GetCurrentChatRoomNo(void);
extern void ResetCurrentChatRoomNo(void);
extern void EndChatRoom(void);
extern void ChatInboxInterface(PU8 destnum);
extern S16 CheckActiveChatRoom(void);
extern void FillChatRoomInfo(PU8 name, PU8 destnum, S32 index);
extern void DecrementCounter(S16 index);
extern void InitailizeMemoryManager(void);
extern void ClearChat(S16 index);
extern void ResetCounter(S16 index);
extern PU8 GetMemoryPointer(S16 index, S16 roomNoIndex);
extern U8 IsThereAnyNewChatMessage(void);
extern pBOOL NewChatMsgIndPresentForKeypadLock(void);
extern void DisplayNewChatMsgINDAfterKeypadUnlocked(void);
extern S8 GetChatRoomStatus(S16 index);
extern void RemoveHeaderInfo(void);
extern void ShowChatStatusIcon(S16 index);
extern void HideChatStatusIcon(S16 index);
extern void BlinkChatIcon(S16 index);
extern void ActivateChatRoom(S16 index);
extern pBOOL UpdateChatRoom(U16 index, U8);

extern void InitChatHeader(void);

extern void DeleteInvitationMessage(void);
extern void OnSMSChatSendAbort(void);
extern void OnSMSChatSendFailure(void);
extern void EntrySmsMemoryFullIndInChatApp(void);
extern void InsertTemplateToChat(S8 *templ);
extern void SetChatInboxIndex(U32 index);
extern U16 ChatUseNumberScreen(void);
extern U8 AdjustMemoryPointers(void);
extern S8 *mmi_msg_chat_get_invitation_pattern(void);
#endif /* _CHATGPROT_H */ 

#endif /* __MMI_MESSAGES_CHAT__ */ 

extern pBOOL ComparePhoneNum(PU8 src, PU8 dst);


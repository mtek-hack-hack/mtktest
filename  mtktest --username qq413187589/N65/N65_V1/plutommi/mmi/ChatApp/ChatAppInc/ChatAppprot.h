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
 * ChatApprot.h
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

   FILENAME : ChatAppprot.h

   PURPOSE     : Chat application 

   REMARKS     : nil

   AUTHOR      : Alok Sharma     

   DATE     : Feb 18,04

**************************************************************/

#include "MMI_features.h"
#ifdef __MMI_MESSAGES_CHAT__

#ifndef _CHATPROT_H
#define  _CHATPROT_H

extern void HighlightChatRooM1(void);
extern void HighlightChatRooM2(void);
extern void HighlightChatRoomInfo(void);
extern void HighlightChatStartMenu(void);
extern void HighlightChatResumeMenu(void);
extern void HighlightChatEndMenu(void);
extern void HighlightChatSend(void);
extern void HighlightChatReply(void);
extern void HighlightChatUseNumMethod(void);
extern void HighlightChatClearMethod(void);
extern void HighlightChatTempLeaveMethod(void);
extern void HighlightChatQuitMethod(void);
extern void HighlititeChatSaveOutBox(void);
extern void HighlightChatTemplate(void);
extern void HighlightChatPhbNum(void);
extern void HighlightChatPhbNam(void);
extern void HighlightChatInputMethod(void);

extern void EntryChatOption(void);
extern void EntryChatRoomOption(void);
extern void EntryChatWrite(void);
extern void EntryChatWriteOption(void);
extern void EntryChatRoomInfo(void);
extern void ExitChatRoomInfo(void);
extern void FillChatRoomActivationStruct(void);

extern void PreEntryChatQuitConfirm(void);
extern void PreSaveChatInfo(void);

extern void SaveChatRoomInfo(void);
extern void ClearChatRoom(void);
extern void EntryChatQuitConfirm(void);
extern void TempleaveChatApp(void);

extern void EnterPhoneBookForChatNumberApp(void);
extern void EnterPhoneBookForChatNameApp(void);
extern void SetNameNumberForChatScreen(U8 *, U8 *);
extern void SetNameNumberForChatScreenExt(S8* name, S8* number);
extern void GoBackHistoryFromChatInputMethod(void);
extern pBOOL CheckDuplicateNumber(PU8 DestinationNo, S32 index);
extern pBOOL CheckChatNumber(PU8 DestNum, S8 status, S32 index);
extern void FillChatRoomInfo(PU8 name, PU8 destnum, S32 index);

extern void ExitChatConfirm(void);
extern void ChatInboxInterface(PU8 destnum);
extern S16 CheckActiveChatRoom(void);
extern void ReplaceChatRoom(void);
extern void QuitChatRoom(void);
extern void EntryClearChatRoomConfirm(void);
extern void GoBackQuitScreen(void);

extern void ChatNumberScreenEmpty(void);
extern void ChatNumberScreenEmptyKeyHandler(void);
extern void ChatNumberScreenNotEmpty(void);
extern void ChatInlineHandler(S32 index);

extern void EntryChatReplaceConfirm(void);
extern void EndChatRoom(void);
extern void GoBackChatHistory(void);
extern void SaveChatMsgToOutBox(void);
extern S16 GetUCS2CharIndex(PS8 buffer);
extern void ShowSendingSMSChatProgressScreen(void);
extern void ExitChatWrite(void);
extern void GetHeader(PU8 dest, S16 index);
extern void AddHeadertoMessage(void);
extern PU8 CopyToBuffer(U8 packet[], S32 length, S16 index, U8 flag);

extern U16 IsNewChatSmsIndScrn(void);
extern void EntryNotifyNewChatMessageArrival(void);
extern void ExitNotifyNewChatMessageArrival(void);
extern void NotifymessageLeftSoftKeyFunction(void);
extern void GoBackHistoryFromNewChatMessageScreen(void);
extern void GoBackHistoryFromNewChatMessageScreenForEndKey(void);
extern U8 IsthereAnyNewChatMessage(void);
extern pBOOL NewChatMsgIndPresentForKeypadLock(void);
extern void DisplayNewChatMsgINDAfterKeypadUnlocked(void);

extern pBOOL ModifyChatRoom(U16 index, U8 flag, void *data, S8 *content);
extern void DeletenCharFromEMSBuffer(S16 count);
extern U32 GetChatInboxIndex(void);
extern U8 mmi_msg_chat_check_ussd_number(U16 *number, S32 number_len);

extern S8* mmi_msg_chat_skip_blank_header(U8* packet);

extern void mmi_msg_entry_chat_room_select(void);
extern void mmi_msg_exit_chat_room_select(void);
extern void mmi_msg_chat_select_room(void);

extern MMI_BOOL is_enter_from_sms_interface;

#endif /* _CHATPROT_H */ 
#endif /* __MMI_MESSAGES_CHAT__ */ 


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
 * ChatAppDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Chat app.
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

   FILENAME : ChatAppDef.h

   PURPOSE     : Chat application 

   REMARKS     : nil

   AUTHOR      : Alok Sharma     

   DATE     : Feb 18,04

**************************************************************/

#include "MMI_features.h"
#ifdef __MMI_MESSAGES_CHAT__

#ifndef _CHATDEF_H
#define  _CHATDEF_H

#include "MMIDataType.h"

typedef enum
{
    CHAT_SCREEN_ID = CHAT_BASE,
    CHAT_SCREEN_ROOM_ID,
    CHAT_SCREEN_START_NEW_ID,
    CHAT_OPTION_SCREEN_ID,
    CHAT_ROOM_SCREEN_ID,
    CHAT_ROOM_INFO_SCREEN_ID,
    CHAT_SCR_NICKNAME_ID,
    CHAT_SCR_DESTINATION_NUM_ID,
    CHAT_SCR_SAVE_QUERY,
    CHAT_OPTION_SCREEN_ID_2,
    SCR_NEWCHATMSGARRIVALNOTIFICATION,
    SCR_SENDING_CHAT_MESSAGE_STATUS,
    CHAT_SCR_NICKNAME_EDIT_ID,
    SCR_CHAT_CLEAR_QUERY,
    SCR_CHAT_QUIT_QUERY,
    SCR_CHAT_REPLACE_QUERY,
    SCR_CHAT_DESTINATION_INFO,
	SCR_ID_CHAT_ROOM_SELECT
} SCREENID_LIST_CHAT;

typedef enum
{
    CHAT_STRING_ID = CHAT_BASE + 1,
    CHAT_ROOM_MENU_TEXT,
    CHAT_STRING1,
    CHAT_STRING2,
    CHAT_ROOM_TEXT,
    CHAT_ROOM_INFO_STR,
    CHAT_ROOM_NEW_STR,
    CHAT_ROOM_RESUME,
    CHAT_ROOM_END,

    CHAT_PHB_NUM_STR,
    CHAT_PHB_NAME_STR,
    CHATROOM_NICKNAME,
    CHATROOM_DESTINATION,
    CHATROOM_EMPTY_ERROR,
    CHATROOM_DUPLICATE_ERROR,
    CHATROOM_NEW_MSG_RCVD,
    CHATROOM_STORAGE_FULL_ERROR,
    CHATROOM_LOCAL_DEFAULT,
    STR_GLOBAL_CHAT,
    STR_CHAT_USE_NUMBER,
    STR_CHAT_CLEAR_CHAT,
    STR_CHAT_TEMP_LEAVE,
    STR_CHAT_QUIT,
    STR_CHAT_WRITE_MESSAGE_TITLE,
    STR_CHAT_INVITATION,
    STR_SAVE_CHAT_INFO,
    STR_REPLACE_CHAT_INFO_QUERY,
    STR_CLEAR_CHAT_ROOM_QUERY,
    STR_QUIT_CHAT_ROOM_QUERY,
    STR_CHAT_FROM,
    STR_END_QUERY,
    STR_CHAT_EDIT_KEY,
    STR_CHAT_OPTIONS,
    STR_CHAT_SAVE,
    STR_CHAT_SAVE_SUCESS,
    STR_CHAT_SAVE_FAILED,
    STR_CHAT_SAVE_PARTIAL,
	STR_ID_CHAT_INVALID_NICKNAME,
	STR_ID_CHAT_ROOM_SELECT,
	STR_ID_CHAT_REPLACE_CHAT_SETTING,
	STR_ID_CHAT_END_AND_REPLACE_CHAT_SETTING
} STRING_LIST_CHAT;

typedef enum
{
    CHAT_IMAGE_ID = CHAT_BASE,
    CHAT_IMAGE_APP_ID,
    IMG_CHAT_NICKNAME,
    IMG_CHAT_DESTINATION
} IMAGE_LIST_CHAT;

/* void ExitChatApp(void); */

typedef enum
{
    CHAT_ROOM1,
    CHAT_ROOM2
} CHAT_ROOM_LIST;

typedef enum
{
    CHAT_STATUS_IDLE,
    CHAT_SEND_FAILED,
    CHAT_SEND_SUCCESS,
    ABORT_MSG
} CHAT_COMM_STATUS;
typedef enum
{
    RECEIVING_CHAT,
    SENDING_CHAT,
    RECEIVING_CHAT_TRUNCATE,
    SENDING_CHAT_TRUNCATE
} CHAT_MESSAGE_TYPE;
#endif /* _CHATDEF_H */ 

#endif /* __MMI_MESSAGES_CHAT__ */ 


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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * ChatApp.C
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
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Chat.c

   PURPOSE     : Chat application 

   REMARKS     : nil

   AUTHOR      : Alok Sharma     

   DATE     : Feb 18,04

**************************************************************/

#include "MMI_include.h"

#ifdef __MMI_MESSAGES_CHAT__

#ifndef _CHAT_APP_
#define _CHAT_APP_

#include "ChatAppResDef.h"
#include "ChatAppGprot.h"
#include "QuickAccessMenuItemProt.h"
#include "MiscFunctions.h"
// #include "OrganizerDcl.h"
#include "AlarmGProt.h"
#include "SettingGprots.h"
#include "SettingProt.h"
#include "MessagesExDcl.h"

#include "CalendarDef.h"
// #include "CalendarGProt.h"
#include "MainMenuDef.h"
#include "ChatGtype.h"
#include "wgui_status_icons.h"
#include "ChatAppprot.h"

/****************Static Variable Start*********/
typedef struct _CHAT_MEMEORY_DATA_STRUCT
{
    PU8 allocp;
    PU8 maxMemUsed;
    U8 isMemoryRounded;
} chatMemoryDataStruct;

static S16 gMessageChatRoomNo;
static S16 gCurrentChatRoomNo;
static U8 gChatBuffer[MAX_NO_OF_CHAT_ROOM][MAX_BUFFER_SIZE];

/****************Static Variable End*********/

/****************Static Function Start*********/
/****************Static Function End*********/

/****************Global Variable Start*********/
chat_context_struct g_chat_cntx;
chat_room_info_struct gChatRoomInfo[MAX_NO_OF_CHAT_ROOM];
chatMemoryDataStruct gChatMemoryData[MAX_NO_OF_CHAT_ROOM];
pBOOL gBlinkChatFlag[MAX_NO_OF_CHAT_ROOM];
const U16 gChatSmsIcon[MAX_NO_OF_CHAT_ROOM] = 
{
    STATUS_ICON_CHAT_INDICATION_ROOM1,
    STATUS_ICON_CHAT_INDICATION_ROOM2
};

extern chat_context_struct g_chat_cntx;
extern chat_room_info_struct gChatRoomInfo[MAX_NO_OF_CHAT_ROOM];
extern U32 mmi_phb_util_convert_number_to_int(PU8 number);

/****************Global Variable End*********/

/****************Function Start*********/
PU8 GetMemoryPointer(S16 index, S16 roomNoIndex);
S16 GetNumOfMessage(S16);

void IncrementCounter(S16);
void InitializeMemoryPointers(PS8 pointer[], S16 maxitems);
void SetMessagechatRoomNo(S16 index);
S16 GetMessagechatRoomNo(void);
void ResetMessagechatRoomNo(void);
void SetCurrentChatRoomNo(S16 index);
S16 GetCurrentChatRoomNo(void);
void ResetCurrentChatRoomNo(void);
void ActivateChatRoom(S16 index);
void DecrementCounter(S16 index);
S8 GetChatRoomStatus(S16 index);
void ShowChatStatusIcon(S16 index);
void HideChatStatusIcon(S16 index);
void BlinkChatIcon(S16 index);

/****************Function End*********/


/*****************************************************************************
 * FUNCTION
 *  InitializeChatApp
 * DESCRIPTION
 *  To Initialize Chat Variables at Boot time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeChatApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iRoomCount;
    S16 error;
    static chat_info_nvram_struct infoStruct[MAX_NO_OF_CHAT_ROOM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetChatHiliteHandlers();

    memset(&infoStruct, 0, MAX_NO_OF_CHAT_ROOM * sizeof(infoStruct));
    for (iRoomCount = 0; iRoomCount < MAX_NO_OF_CHAT_ROOM; iRoomCount++)
    {
        U16 index = (U16) iRoomCount + 1;

        if (ReadRecord
            (NVRAM_EF_CHAT_ROOM_INFO_LID, index, &infoStruct[iRoomCount], NVRAM_CHAT_ROOM_INFO_RECORD_SIZE, &error) < 0)
        {
            memset(&infoStruct[iRoomCount], 0, sizeof(infoStruct));
            WriteRecord(
                NVRAM_EF_CHAT_ROOM_INFO_LID,
                index,
                (void*)&infoStruct[iRoomCount],
                NVRAM_CHAT_ROOM_INFO_RECORD_SIZE,
                &error);
        }
        g_chat_cntx.chatRoomInfo[iRoomCount].status = MMI_MSG_CHAT_DISABLE;
        g_chat_cntx.chatRoomInfo[iRoomCount].chatRoomCounter = 0;
        mmi_ucs2cpy(
            (S8*) (g_chat_cntx.chatRoomInfo[iRoomCount].chatInfo.nickName),
            (S8*) infoStruct[iRoomCount].nickName);
        mmi_asc_to_ucs2(
            (S8*) (g_chat_cntx.chatRoomInfo[iRoomCount].chatInfo.destinationNo),
            (S8*) infoStruct[iRoomCount].destinationNo);
        HideChatStatusIcon(iRoomCount);
        g_chat_cntx.blinkChatFlag[iRoomCount] = FALSE;

    }

    InitChatHeader();
    ResetCurrentChatRoomNo();
    InitailizeMemoryManager();
    memset(g_chat_cntx.writeChatBuffer, 0, ((MAX_MSG_SIZE + 1) * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  InitailizeMemoryManager
 * DESCRIPTION
 *  It initializes memory buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitailizeMemoryManager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_NO_OF_CHAT_ROOM; index++)
    {
        ResetMemoryBuffer(index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryChatApp
 * DESCRIPTION
 *  Pre-Entry function of Chat Main Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryChatApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_enter_from_sms_interface = MMI_FALSE;
	EntryChatApp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_chat_del_chat_room_select_screen_callback
 * DESCRIPTION
 *  Delete chat room select screen callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_msg_chat_del_chat_room_select_screen_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_enter_from_sms_interface = MMI_FALSE;
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatApp
 * DESCRIPTION
 *  This is Entry function of Chat Option Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern const U16 gIndexIconsImageList[];

void EntryChatApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 numOfItems = 0;
    U8 iRoomCount = 0;
    U16 itemList[MAX_SUB_MENUS];
    U8 *itemStr[MAX_SUB_MENUS];
    U16 ChatRoomIconstates[MAX_NO_OF_CHAT_ROOM];
	U16 title_string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (is_enter_from_sms_interface)
	{
		EntryNewScreen(SCR_ID_CHAT_ROOM_SELECT, mmi_msg_exit_chat_room_select, mmi_msg_entry_chat_room_select, NULL);

    	guiBuffer = GetCurrGuiBuffer(SCR_ID_CHAT_ROOM_SELECT);
		SetDelScrnIDCallbackHandler(SCR_ID_CHAT_ROOM_SELECT, (HistoryDelCBPtr)mmi_msg_chat_del_chat_room_select_screen_callback);
		title_string_id = (U16)STR_ID_CHAT_ROOM_SELECT; //Select Chat Room string
	}
	else
	{
		EntryNewScreen(CHAT_SCREEN_ID, NULL, EntryChatApp, NULL);

		guiBuffer = GetCurrGuiBuffer(CHAT_SCREEN_ID);
		title_string_id = (U16)CHAT_ROOM_MENU_TEXT;
	}

    SetParentHandler(MENU_CHATAPP_ID);

    numOfItems = GetNumOfChild(MENU_CHATAPP_ID);

    GetSequenceStringIds(MENU_CHATAPP_ID, itemList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (iRoomCount = 0; iRoomCount < MAX_NO_OF_CHAT_ROOM; iRoomCount++)
    {
        itemStr[iRoomCount] = (U8*) GetString(itemList[iRoomCount]);
        if (g_chat_cntx.chatRoomInfo[iRoomCount].status == MMI_MSG_CHAT_DISABLE)
        {
            ChatRoomIconstates[iRoomCount] = 0;
        }
        else
        {
            ChatRoomIconstates[iRoomCount] = IMG_VICON;
        }
    }
	
    /*
     * ShowCategory52Screen(CHAT_ROOM_MENU_TEXT,CHAT_IMAGE_APP_ID,
     * STR_GLOBAL_OPTIONS,IMG_GLOBAL_OK,
     * STR_GLOBAL_BACK,IMG_GLOBAL_BACK,
     * numOfItems,itemList,ChatRoomIconstates,NULL,0,0,guiBuffer);
     */
    ShowCategory73Screen(
        title_string_id,
        CHAT_IMAGE_APP_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numOfItems,
        itemStr,
        ChatRoomIconstates,
        (U16*) gIndexIconsImageList,
        0,
        guiBuffer,
        ICON_ICON_TEXT);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  GetNumOfMessage
 * DESCRIPTION
 *  Returns Total Number of message in Chat Room
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  Total Number of Message in Chat Room
 *****************************************************************************/
S16 GetNumOfMessage(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_chat_cntx.chatRoomInfo[index].chatRoomCounter;
}


/*****************************************************************************
 * FUNCTION
 *  IncrementCounter
 * DESCRIPTION
 *  Increses Counter of Chat Room
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void IncrementCounter(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_chat_cntx.chatRoomInfo[index].chatRoomCounter++;
}


/*****************************************************************************
 * FUNCTION
 *  ResetCounter
 * DESCRIPTION
 *  Set Chat Room Counter to Zero
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCounter(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_chat_cntx.chatRoomInfo[index].chatRoomCounter = 0;
}


/*****************************************************************************
 * FUNCTION
 *  DecrementCounter
 * DESCRIPTION
 *  Decreases Chat Room Counter By one
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void DecrementCounter(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_chat_cntx.chatRoomInfo[index].chatRoomCounter--;
}


/*****************************************************************************
 * FUNCTION
 *  SetMessagechatRoomNo
 * DESCRIPTION
 *  It sets for which Chat Room New message has Arrived
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetMessagechatRoomNo(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMessageChatRoomNo = index;
}


/*****************************************************************************
 * FUNCTION
 *  GetMessagechatRoomNo
 * DESCRIPTION
 *  It message Chat Room No
 * PARAMETERS
 *  void
 * RETURNS
 *  Message Chat Room no[0/1]
 *****************************************************************************/
S16 GetMessagechatRoomNo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gMessageChatRoomNo;
}


/*****************************************************************************
 * FUNCTION
 *  ResetMessageChatRoomNo
 * DESCRIPTION
 *  Reset message Chat Room No
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetMessageChatRoomNo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMessageChatRoomNo = -1;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrentChatRoomNo
 * DESCRIPTION
 *  This sets Current Chat Room No
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentChatRoomNo(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrentChatRoomNo = index;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrentChatRoomNo
 * DESCRIPTION
 *  This returns Current Chat Room No
 * PARAMETERS
 *  void
 * RETURNS
 *  Message None
 *****************************************************************************/
S16 GetCurrentChatRoomNo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCurrentChatRoomNo;
}


/*****************************************************************************
 * FUNCTION
 *  ResetCurrentChatRoomNo
 * DESCRIPTION
 *  This sets Current Chat Room No to -1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCurrentChatRoomNo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrentChatRoomNo = -1;
}


/*****************************************************************************
 * FUNCTION
 *  ActivateChatRoom
 * DESCRIPTION
 *  This Activates Chat Room
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateChatRoom(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearChat(index);
    g_chat_cntx.chatRoomInfo[index].status = MMI_MSG_CHAT_ENABLE;
    ShowChatStatusIcon(index);
}


/*****************************************************************************
 * FUNCTION
 *  GetMemoryPointer
 * DESCRIPTION
 *  This Returns Chat Room Message Pointer
 * PARAMETERS
 *  index           [IN]        Chat Room No[0/1]
 *  roomNoIndex     [IN]        
 * RETURNS
 *  Pointer to a String
 *****************************************************************************/
PU8 GetMemoryPointer(S16 index, S16 roomNoIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_chat_cntx.chatRoomInfo[roomNoIndex].chatStrings[index].chat_message_string;
}


/*****************************************************************************
 * FUNCTION
 *  GetChatRoomStatus
 * DESCRIPTION
 *  This Returns Chat Room Status
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  Chat Room Status flag
 *****************************************************************************/
S8 GetChatRoomStatus(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_chat_cntx.chatRoomInfo[index].status;
}


/*****************************************************************************
 * FUNCTION
 *  ShowChatStatusIcon
 * DESCRIPTION
 *  This function sets Status icons
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void ShowChatStatusIcon(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IdleSetStatusIcon(gChatSmsIcon[index]);

}


/*****************************************************************************
 * FUNCTION
 *  HideChatStatusIcon
 * DESCRIPTION
 *  This function Hides Status icons
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void HideChatStatusIcon(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IdleResetStatusIcon(gChatSmsIcon[index]);
}


/*****************************************************************************
 * FUNCTION
 *  BlinkChatIcon
 * DESCRIPTION
 *  This function Blinks Status icons
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room No[0/1](?)
 * RETURNS
 *  void
 *****************************************************************************/
void BlinkChatIcon(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BlinkStatusIcon(gChatSmsIcon[index]);
    UpdateStatusIcons();
    g_chat_cntx.blinkChatFlag[index] = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  AllocMemory
 * DESCRIPTION
 *  It allocates memory from Memory pool
 * PARAMETERS
 *  len         [IN]        
 *  roomNum     [IN]        
 *  Total number of bytes & Chat room number(?)
 * RETURNS
 *  Pointer to Allocated memory
 *****************************************************************************/
PU8 AllocMemory(S32 len, S16 roomNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 currMessIndex = g_chat_cntx.chatRoomInfo[roomNum].chatRoomCounter - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the intend-to-add chat message is larger than the max buffer size, it is not allowed */
    if (len > MAX_BUFFER_SIZE)
    {
        return NULL;
    }

    /* the remaining space for the chatroom is not enough for the intend-to-add chat message */
    if (((gChatBuffer[roomNum] + MAX_BUFFER_SIZE) - gChatMemoryData[roomNum].allocp) < len)
    {
        /* maxMemUsed points to the end of the last chat message in the chatroom before adding the intend-to-add chat message */
        gChatMemoryData[roomNum].maxMemUsed = gChatMemoryData[roomNum].allocp;
        gChatMemoryData[roomNum].isMemoryRounded = 1;
    }

    if (gChatMemoryData[roomNum].isMemoryRounded)
    {
        U8 index, indexCount = 0;
        PU8 tempAllocBuf;

        /* the remaining space for the chatroom is not enough for the intend-to-add chat message */
        if ((gChatBuffer[roomNum] + MAX_BUFFER_SIZE) < (gChatMemoryData[roomNum].allocp + len))
        {
            /* allocp points to the start of the chatroom and it would be the start point of the intend-to-add chat message */
            gChatMemoryData[roomNum].allocp = gChatBuffer[roomNum];
            /* search for the chat message index that points to the start of the chatroom */
            for (index = 0; index < currMessIndex; index++)
            {
                if (g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index].chat_message_string == gChatBuffer[roomNum])
                {
                    break;
                }
                /* indexCount is the chat message index that points to the start of the chatroom */
                indexCount++;
            }
        }

        /* tempAllocBuf is the end point of the intend-to-add chat message */
        tempAllocBuf = gChatMemoryData[roomNum].allocp + len;

        for (index = indexCount; index < currMessIndex; index++)
        {
            /* the original chat message is out of the range of the intend-to-add chat message */
            if ((g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index].chat_message_string <
                 gChatMemoryData[roomNum].allocp) ||
                (g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index].chat_message_string > tempAllocBuf))
            {
                if (index > 0)
                {
                    /* the intend-to-add chat message is larger than all of the original chat messages, so all of the original chat messages would be removed */
                    if (gChatMemoryData[roomNum].maxMemUsed <= tempAllocBuf)
                    {
                        break;
                    }
                    /* index-1 is the last chat message in the range of the intend-to-add chat message so align it to the end point of the intend-to-add chat message */
                    g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index - 1].chat_message_string = tempAllocBuf;
                    /* set the truncate flag, the truncated content would be represented as (..) */
                    if (g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index - 1].flag == RECEIVING_CHAT)
                    {
                        g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index - 1].flag = RECEIVING_CHAT_TRUNCATE;
                    }
                    else if (g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index - 1].flag == SENDING_CHAT)
                    {
                        g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index - 1].flag = SENDING_CHAT_TRUNCATE;
                    }
                    /* indexCount decrement is because partial chat content of index-1 would appear in chatroom */
                    indexCount--;
                }
                break;
            }
            /* if the original chat message is not out of the range of the intend-to-add chat message and it aligns well so no truncate is needed */
            if ((g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index].chat_message_string == tempAllocBuf))
            {
                break;
            }
            /* indexCount is the start index of the chat message that would remain in the chatroom */
            indexCount++;
        }

        /* all of the original chat messages should be removed */
        if (indexCount == currMessIndex)
        {
            /* in case the content of the last chat message before adding the intend-to-add chat message is out of range */
            if (gChatMemoryData[roomNum].maxMemUsed > tempAllocBuf)
            {
                indexCount--;
                /* align the start point of the last chat message before adding the intend-to-add chat message to the end point of the intend-to-add chat message */
                g_chat_cntx.chatRoomInfo[roomNum].chatStrings[indexCount].chat_message_string = tempAllocBuf;
                /* set the truncate flag, the truncated content would be represented as (..) */
                if (g_chat_cntx.chatRoomInfo[roomNum].chatStrings[indexCount].flag == RECEIVING_CHAT)
                {
                    g_chat_cntx.chatRoomInfo[roomNum].chatStrings[indexCount].flag = RECEIVING_CHAT_TRUNCATE;
                }
                else if (g_chat_cntx.chatRoomInfo[roomNum].chatStrings[indexCount].flag == SENDING_CHAT)
                {
                    g_chat_cntx.chatRoomInfo[roomNum].chatStrings[indexCount].flag = SENDING_CHAT_TRUNCATE;
                }
            }
        }

        for (index = 0; indexCount && index < (currMessIndex - indexCount); index++)
        {
            g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index].chat_message_string =
                g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index + indexCount].chat_message_string;
            g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index].flag =
                g_chat_cntx.chatRoomInfo[roomNum].chatStrings[index + indexCount].flag;
        }

        for (index = indexCount; index > 0; index--)
        {
            g_chat_cntx.chatRoomInfo[roomNum].chatStrings[currMessIndex - index].chat_message_string = NULL;
            g_chat_cntx.chatRoomInfo[roomNum].chatStrings[currMessIndex - index].flag = 0;
        }

        g_chat_cntx.chatRoomInfo[roomNum].chatRoomCounter =
            g_chat_cntx.chatRoomInfo[roomNum].chatRoomCounter - indexCount;
    }
    gChatMemoryData[roomNum].allocp += len;
    return (gChatMemoryData[roomNum].allocp - len);
}


/*****************************************************************************
 * FUNCTION
 *  ResetMemoryBuffer
 * DESCRIPTION
 *  It resets memory buffer and other flags
 * PARAMETERS
 *  roomNum     [IN]        
 *  Chat room number(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ResetMemoryBuffer(S16 roomNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gChatMemoryData[roomNum].allocp = gChatBuffer[roomNum];
    gChatMemoryData[roomNum].maxMemUsed = gChatBuffer[roomNum];
    gChatMemoryData[roomNum].isMemoryRounded = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ResetRoundedFlag
 * DESCRIPTION
 *  It resets rounded flag
 * PARAMETERS
 *  roomNum     [IN]        
 *  Chat room number(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ResetRoundedFlag(S16 roomNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gChatMemoryData[roomNum].isMemoryRounded = 0;
}
#endif /* _CHAT_APP_ */ 
#endif /* __MMI_MESSAGES_CHAT__ */ 


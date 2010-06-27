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
 * ChatAppSendMsg.C
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

   FILENAME : ChatAppSendMsg.c

   PURPOSE     : Chat application 

   REMARKS     : nil

   AUTHOR      : Alok Sharma     

   DATE     : Feb 18,04

**************************************************************/
#include "MMI_include.h"
#ifdef __MMI_MESSAGES_CHAT__

#ifndef _CHAT_APPSENDMSG_
#define _CHAT_APPSENDMSG_

#include "CommonScreens.h"
#include "ProtocolEvents.h"

#include "ChatAppResDef.h"
#include "ChatGtype.h"
#include "ChatAppprot.h"
#include "ChatAppGexdcl.h"
#include "ChatAppGprot.h"
#include "EmsMiscell.h"

#include "MessagesExDcl.h"
#include "MessagesMiscell.h"
#include "SmsGuiInterfaceProt.h"
#include "ProtocolEvents.h"
#include "Gui_ems.h"
#include "wgui_status_icons.h"
#include "MessagesResourceData.h"
#include "IdleAppProt.h"
#include "SettingProfile.h"
#include "gpioInc.h"
#include "Asciiprot.h"
#include "AlarmFrameworkProt.h"

#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_SMS_Chat.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

/****************Static Variable Start*********/
static U16 gCurrScrnNewChatSmsInd = 0;
static S8 gHeader[3 * ENCODING_LENGTH];     /* ={": "}; */
static S8 gInvitation[4 * ENCODING_LENGTH]; /* ={":-)"}; */
static U16 gNewChatMsgScreenToDeleteFromHistory;
static pBOOL gChatMsgIndPresentForKeypadLock;
static U32 gChatInboxIndex;

#ifdef __MMI_DUAL_SIM_MASTER__
static E_MTPNP_AD_CHANNELS chat_new_msg_channel;
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_MASTER__
static E_MTPNP_AD_CHANNELS mmi_msg_chat_get_new_msg_channel(void);
static void mmi_msg_chat_set_new_msg_channel(U16 msg_index);
#endif /* __MMI_DUAL_SIM_MASTER__ */

/****************Static Variable End*********/
/****************Global Variable Start*********/
pBOOL gChatInvitation;
U8 gIsItChatSmsArrivalInd;
U8 gIsThereAnyNewChatSMSToInd;
pBOOL gChatRoomScreenPresent;

/****************Global Variable End*********/

/****************Function Start*********/
/****************Function End*********/

/***********Extern Variable Start*************/
extern chat_context_struct g_chat_cntx;
extern U16 gChatMsgFlag;
extern pBOOL gBlinkChatFlag[MAX_NO_OF_CHAT_ROOM];
extern pBOOL gInputBoxUcs2Flag;

/***********Extern Variable End*************/
extern PS8 lookUpNumber(PS8 number);
extern BOOL GetUCS2Flag(S8 *);
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern U8 DeInitMessagesEMSBuffer(msg_ems_data_struct *pE);
extern void GetNewChatMsgIndDisplayString(U8 *number, U8 length, U8 type);

/******************/
/* Handle Chat Header */
/******************/


/*****************************************************************************
 * FUNCTION
 *  InitChatHeader
 * DESCRIPTION
 *  Init chat header string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitChatHeader(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((PS8) gHeader, ":");
    mmi_asc_to_ucs2((PS8) gInvitation, ":-)");
}


/*****************************************************************************
 * FUNCTION
 *  GetHeader
 * DESCRIPTION
 *  It Gets Header string
 * PARAMETERS
 *  dest        [IN]        
 *  index       [IN]        
 *  Header String and Chat Room Number(?)
 * RETURNS
 *  void
 *****************************************************************************/
void GetHeader(PU8 dest, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    pBOOL flag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_chat_cntx.chatRoomInfo[index].chatRoomCounter == 0)
    {

        mmi_ucs2cpy((PS8) dest, gInvitation);
        flag = TRUE;

    }
    if ((mmi_ucs2strlen((PS8) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.nickName)) > 0)
    {
        if (flag == TRUE)
        {
            mmi_ucs2cat((PS8) dest, g_chat_cntx.chatRoomInfo[index].chatInfo.nickName);
        }
        else
        {
            mmi_ucs2cpy((PS8) dest, g_chat_cntx.chatRoomInfo[index].chatInfo.nickName);
        }
        mmi_ucs2cat((PS8) dest, gHeader);

    }
    else if (flag == TRUE)
    {
        mmi_ucs2cat((PS8) dest, gHeader);
    }
    else
    {
        mmi_ucs2cpy((PS8) dest, gHeader);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RemoveHeaderInfo
 * DESCRIPTION
 *  It Removes header info from message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RemoveHeaderInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 aHeader[(MAX_SMS_CHAT_HEADER_SIZE + 1) * ENCODING_LENGTH];
    S16 nStrLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetHeader(aHeader, GetCurrentChatRoomNo());
    nStrLen = (S16) mmi_ucs2strlen((PS8) aHeader);
    DeletenCharFromEMSBuffer(nStrLen);
}


/*****************************************************************************
 * FUNCTION
 *  AddHeadertoMessage
 * DESCRIPTION
 *  It adds Message header to Chat Message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AddHeadertoMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms;
    U8 aHeader[(MAX_SMS_CHAT_HEADER_SIZE + 1) * ENCODING_LENGTH];
    S32 nStrLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForEdit(&pEms, 0);
    ResetCurrentPosition(pEms);
    GetHeader(aHeader, GetCurrentChatRoomNo());
    nStrLen = mmi_ucs2strlen((PS8) aHeader);
    AddString(pEms, aHeader, (U16) (nStrLen * 2), NULL);    /* check length */
}


/*****************************************************************************
 * FUNCTION
 *  CopyToBuffer
 * DESCRIPTION
 *  It Copies Chat Room Data to Chat Buffer
 * PARAMETERS
 *  packet      [?]         
 *  length      [IN]        Chat room Number
 *  index       [IN]        
 *  flag        [IN]        
 * RETURNS
 *  Buffer pointer
 *****************************************************************************/
PU8 CopyToBuffer(U8 packet[], S32 length, S16 index, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 temp[MAX_DIGITS * ENCODING_LENGTH];
    S8 *name;
	S8 *pContent;
    PU8 pointer;
    U32 nLimiter = 0;
    S32 prelength = 0;
    S32 header_len;
	S32 content_len;
    BOOL noNickname = FALSE;
	BOOL noHeader = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pContent = mmi_msg_chat_skip_blank_header(packet);

    header_len = mmi_ucs2strlen((S8*) gHeader);
	content_len = mmi_ucs2strlen(pContent);
	
	if (content_len >= header_len)
    {
		if (mmi_ucs2str(pContent, gHeader) != NULL)
		{
	        if (mmi_ucs2ncmp(pContent, gHeader, header_len) == 0)
	        {
	            noNickname = TRUE;
	        }
		}
		else
		{
	        noNickname = TRUE;
			noHeader = TRUE;
		}
    }
	else
	{
	    noNickname = TRUE;
		noHeader = TRUE;
	}

    if (noNickname)
    {
        if (flag == SENDING_CHAT)
        {
            mmi_ucs2cpy(temp, GetString(CHATROOM_LOCAL_DEFAULT));
        }
        else
        {
            name = lookUpNumber((S8*) g_chat_cntx.chatRoomInfo[index].chatInfo.destinationNo);
            if (mmi_ucs2strlen(name))
            {
                mmi_ucs2cpy((S8*) temp, name);
            }
            else
            {
                mmi_ucs2cpy((S8*) temp, (S8*) g_chat_cntx.chatRoomInfo[index].chatInfo.destinationNo);
            }

			if(noHeader)
			{
				mmi_ucs2cat((S8*) temp, gHeader);
			}
        }
		
        prelength = (mmi_ucs2strlen(temp)) * ENCODING_LENGTH;
    }

	content_len = content_len * ENCODING_LENGTH;
    pointer = AllocMemory(prelength + content_len + 2, index);
    if (pointer != NULL)
    {   /* return NULL */
        if (prelength)
        {
            memcpy(pointer, temp, prelength);
        }
        memcpy((pointer + prelength), pContent, content_len);
        memcpy((pointer + prelength + content_len), &nLimiter, ENCODING_LENGTH);
    }

    return pointer;
}


/*****************************************************************************
 * FUNCTION
 *  DeletenCharFromEMSBuffer
 * DESCRIPTION
 *  It delets chars from EMS buffer
 * PARAMETERS
 *  count       [IN]        
 *  Total number of chars to be deleted(?)
 * RETURNS
 *  void
 *****************************************************************************/
void DeletenCharFromEMSBuffer(S16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForEdit(&pEms, 0);
    CancelCurrentPosition(pEms, (kal_uint16) (count + 1));
    GoToEndPosition(pEms);
}


/*****************************************************************************
 * FUNCTION
 *  RemoveInvitationChar
 * DESCRIPTION
 *  It removes invitation chars from message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RemoveInvitationChar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms;
    S16 len = (S16) mmi_ucs2strlen(gInvitation);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);
    ResetCurrentPosition(pEms);
    ForwardCurrentPosition(pEms, len);
    CancelCurrentPosition(pEms, (kal_uint16) (len + 1));
}


/*****************************************************************************
 * FUNCTION
 *  SetChatInboxIndex
 * DESCRIPTION
 *  Sets invition message index from inbox index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetChatInboxIndex(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gChatInboxIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  GetChatInboxIndex
 * DESCRIPTION
 *  It returns index of message
 * PARAMETERS
 *  void
 * RETURNS
 *  chat invitation index
 *****************************************************************************/
U32 GetChatInboxIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gChatInboxIndex;
}

/*****************/
/* Receive Chat Msg */
/*****************/


/*****************************************************************************
 * FUNCTION
 *  CheckForChatNumber
 * DESCRIPTION
 *  It Checks whether a new message is Chat room message or not
 * PARAMETERS
 *  number      [IN]        number length,type
 *  len         [IN]        
 *  type        [IN]        
 * RETURNS
 *  Status flag[0/1]
 *****************************************************************************/
U16 CheckForChatNumber(PU8 number, U8 len, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 num1[44];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_NO_OF_CHAT_ROOM; i++)
    {
        mmi_ucs2_to_asc((PS8) num1, (PS8) g_chat_cntx.chatRoomInfo[i].chatInfo.destinationNo);

        num1[42] = '\0';
        num1[43] = '\0';

        if ((ComparePhoneNum((PU8) num1, (PU8) number)) && (g_chat_cntx.chatRoomInfo[i].status == MMI_MSG_CHAT_ENABLE))
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
			if (MTPNP_PFAL_Get_Chat_Resume_Channel(i) == mmi_msg_chat_get_new_msg_channel())
		#endif /* __MMI_DUAL_SIM_MASTER__ */
			{
            	SetMessagechatRoomNo(i);
				return 1;
			}
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  CheckForChatMessage
 * DESCRIPTION
 *  It Checks whether a new message is Chat room message or not
 * PARAMETERS
 *  data            [?]         
 *  withobject      [IN]        
 *  content         [?]         
 *  Destination number,number length,type(?)
 * RETURNS
 *  Status flag[0/1]
 *****************************************************************************/
U8 CheckForChatMessage(void *data, int withobject, void *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_deliver_msg_struct *msginfo = (mmi_frm_sms_deliver_msg_struct*) data;
    U8 number[MAX_DIGITS_SMS + 1];
    U8 addrlen = 0;
    U8 type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the message with ems object or smart message should not be treated as a chat message */
    if ((withobject) || (msginfo->dcs == SMSAL_8BIT_DCS))
    {
        return FALSE;
    }

    /* incomplete message is not allowed to be dispatched to chat room */
    if (!mmi_frm_sms_check_awaited_complete_msg(msginfo->msg_data[0]))
    {
        return FALSE;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
	mmi_msg_chat_set_new_msg_channel(msginfo->index);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    memset((S8*) number, 0, (MAX_DIGITS_SMS + 1));
    addrlen = (msginfo->addr_number.length > MSG_NUM_LEN) ? MSG_NUM_LEN : msginfo->addr_number.length;
    if (msginfo->addr_number.type == CSMCC_INTERNATIONAL_ADDR)
    {
        number[0] = '+';
        type = 1;
    }
    memcpy(number + type, msginfo->addr_number.number, addrlen);
    /* chat message will dispatch to chatroom only if the current screen is chatroom or the chatroom screen is in the history */
    if (GetMessagesCurrScrnID() == CHAT_ROOM_SCREEN_ID || IsScreenPresent(CHAT_ROOM_SCREEN_ID))
    {
        /* if (CheckForChatNumber(number, addrlen, type) && CheckForInvitationMsg((U8*)unicodecontent, length, FALSE)) */
        if (CheckForChatNumber(number, addrlen, type))
        {
            if (type == 1)
            {
                GetNewChatMsgIndDisplayString(number, (U8) (addrlen + 1), type);
            }
            else
            {
                GetNewChatMsgIndDisplayString(number, addrlen, type);
            }
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckForInvitationMsg
 * DESCRIPTION
 *  It checks for invitation function
 * PARAMETERS
 *  data        [IN]        length and invitation flag
 *  length      [IN]        
 *  flag        [IN]        
 * RETURNS
 *  Status
 *****************************************************************************/
pBOOL CheckForInvitationMsg(PU8 data, S32 length, pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((S8*) gInvitation);
    if (length > 0)
    {
        if (mmi_ucs2ncmp((PS8) data, gInvitation, len) == 0)
        {
            gChatInvitation = flag;
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeleteInvitationMessage
 * DESCRIPTION
 *  Deletes invitation chars from Chat Invitation message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteInvitationMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gChatMsgFlag = 1;
    DeleteChatMsg((S32) GetChatInboxIndex());
    gChatInvitation = FALSE;
    g_chat_cntx.chatRoomInfo[index].status = MMI_MSG_CHAT_ENABLE;
    ShowChatStatusIcon(index);

}


/*****************************************************************************
 * FUNCTION
 *  DisplayChatPopUpWindow
 * DESCRIPTION
 *  It Displays Chat Pop Up on idle screen and adds message to Chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayChatPopUpWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gChatMsgIndPresentForKeypadLock = FALSE;
    gIsItChatSmsArrivalInd = TRUE;
    gIsThereAnyNewChatSMSToInd = TRUE;

#ifdef __MMI_DUAL_SIM_MASTER__
	if (mmi_msg_chat_get_new_msg_channel() == MTPNP_AD_CHANNEL_SLAVE)
	{
		mmi_msg_set_msg_type_as_slave();
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    PlayMessageArrivalTone();
    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);

    if (GetMessagesCurrScrnID() == CHAT_ROOM_SCREEN_ID)
    {
        if (GetMessagechatRoomNo() != GetCurrentChatRoomNo())
        {
            BlinkChatIcon(GetMessagechatRoomNo());
        }
    }
    else
    {
        BlinkChatIcon(GetMessagechatRoomNo());
    }

    if (IsMMIInIdleState() || IsNewChatSmsIndScrn())
    {
        ClearKeyEvents();
        MMI_ASSERT(g_idle_context.IsOnIdleScreen != 1 && g_idle_context.ScreenSaverRunFlag != 1);
        MMI_ASSERT(gCurrScrnNewChatSmsInd != SCR_NEWCHATMSGARRIVALNOTIFICATION);

        if ((IsScreenPresent(SCR_NEWCHATMSGARRIVALNOTIFICATION) == TRUE) || IsNewChatSmsIndScrn())
        {
            gNewChatMsgScreenToDeleteFromHistory = 1;
        }
        if (IsKeyPadLockState())
        {
            gChatMsgIndPresentForKeypadLock = TRUE;
            EntryIdleScreen();
        }
        else
        {
            EntryNotifyNewChatMessageArrival();
        }
    }
    else
    {
    #ifdef __MMI_LCD_PARTIAL_ON__
        LeavePartialOnScreenSaverIfOk();
    #endif 
        if (GetMessagesCurrScrnID() == CHAT_ROOM_SCREEN_ID)
        {
            if (GetMessagechatRoomNo() == GetCurrentChatRoomNo())
            {
                gIsItChatSmsArrivalInd = FALSE;
                gIsThereAnyNewChatSMSToInd = FALSE;
                EntryChatRoom();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HandleChatMessage
 * DESCRIPTION
 *  It Displays Chat Pop Up on idle screen and adds message to Chat room
 * PARAMETERS
 *  data        [?]     
 *  content     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 HandleChatMessage(void *data, void *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ModifyChatRoom(GetMessagechatRoomNo(), RECEIVING_CHAT, (void*)data, (S8*) content);
    DisplayChatPopUpWindow();
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  IsNewChatSmsIndScrn
 * DESCRIPTION
 *  Checks wheather new pop Chat message screen is on idle screen or not
 *  Currently no use, but keep for future implementation when idle receiving chat message
 * PARAMETERS
 *  void
 * RETURNS
 *  status[0/1]
 *****************************************************************************/
U16 IsNewChatSmsIndScrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gCurrScrnNewChatSmsInd == SCR_NEWCHATMSGARRIVALNOTIFICATION) ? 1 : 0;
}


/*****************************************************************************
 * FUNCTION
 *  EntryNotifyNewChatMessageArrival
 * DESCRIPTION
 *  It displays pop up for new Chat message received
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNotifyNewChatMessageArrival(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_NEWCHATMSGARRIVALNOTIFICATION, ExitNotifyNewChatMessageArrival, NULL, NULL);
    if (gNewChatMsgScreenToDeleteFromHistory)
    {
        DeleteNScrId(SCR_NEWCHATMSGARRIVALNOTIFICATION);
    }
    gCurrScrnNewChatSmsInd = SCR_NEWCHATMSGARRIVALNOTIFICATION;

    ShowCategory154Screen(
        CHATROOM_NEW_MSG_RCVD,
        CHAT_IMAGE_APP_ID,
        STR_GLOBAL_CHAT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_OK,
        (PU8) GetString(STR_CHAT_FROM),
        (PU8) GetNewChatSmsIndDisplayStr(),
        IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE,
        NULL);
    SetRightSoftkeyFunction(GoBackHistoryFromNewChatMessageScreen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NotifymessageLeftSoftKeyFunction, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistoryFromNewChatMessageScreenForEndKey, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitNotifyNewChatMessageArrival
 * DESCRIPTION
 *  Exit screen of new message arrival
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitNotifyNewChatMessageArrival(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrScrnNewChatSmsInd = 0;
}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistoryFromNewChatMessageScreen
 * DESCRIPTION
 *  Wrapper function for Calling GoBackHistory function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistoryFromNewChatMessageScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrScrnNewChatSmsInd = 0;
    gIsItChatSmsArrivalInd = FALSE;
    gIsThereAnyNewChatSMSToInd = FALSE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  NotifymessageLeftSoftKeyFunction
 * DESCRIPTION
 *  Goes to Chat room from Idle screen when Chat is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NotifymessageLeftSoftKeyFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsThereAnyNewChatSMSToInd = FALSE;
    SetCurrentChatRoomNo(GetMessagechatRoomNo());
    EntryChatRoom();
}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistoryFromNewChatMessageScreenForEndKey
 * DESCRIPTION
 *  Wrapper function for calling EndKey functionality
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistoryFromNewChatMessageScreenForEndKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNewChatMsgScreenToDeleteFromHistory = 0;
    gIsThereAnyNewChatSMSToInd = FALSE;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  IsThereAnyNewChatMessage
 * DESCRIPTION
 *  Returns whether there is new Chat message or not
 * PARAMETERS
 *  void
 * RETURNS
 *  status
 *****************************************************************************/
U8 IsThereAnyNewChatMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIsThereAnyNewChatSMSToInd;
}


/*****************************************************************************
 * FUNCTION
 *  NewChatMsgIndPresentForKeypadLock
 * DESCRIPTION
 *  It returns Keypad state when new Chat Messsage arrives
 * PARAMETERS
 *  void
 * RETURNS
 *  status
 *****************************************************************************/
pBOOL NewChatMsgIndPresentForKeypadLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gChatMsgIndPresentForKeypadLock;
}


/*****************************************************************************
 * FUNCTION
 *  DisplayNewChatMsgINDAfterKeypadUnlocked
 * DESCRIPTION
 *  It Sets flag for new chat message when keypad is unlocked
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayNewChatMsgINDAfterKeypadUnlocked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gChatMsgIndPresentForKeypadLock = FALSE;
    EntryNotifyNewChatMessageArrival();
}


/*****************************************************************************
 * FUNCTION
 *  ModifyChatRoom
 * DESCRIPTION
 *  It modifies Chat room upon arrival of new message and deletes from Inbox
 * PARAMETERS
 *  index       [IN]        
 *  flag        [IN]        
 *  data        [?]         
 *  content     [?]         
 * RETURNS
 *  status
 *****************************************************************************/
pBOOL ModifyChatRoom(U16 index, U8 flag, void *data, S8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_deliver_msg_struct *msgentry = (mmi_frm_sms_deliver_msg_struct*) data;
    //U16 length = msgentry->no_msg_data; /* it is not the actual length of the data, ex. the length of 706B is 2, not 1 */
    S16 len = 0;
    S8 *unicodecontent = NULL;
    PU8 point = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* content might be unicode or ascii, convert it to unicode and store it to unicodecontent */
    if (msgentry->dcs == SMSAL_UCS2_DCS)
    {
        len = (S16) mmi_ucs2strlen(content);
        unicodecontent = OslMalloc((len + 1) * 2);
        memcpy(unicodecontent, content, len * 2);
        memset(unicodecontent + len * 2, 0, 2);
    }
    else
    {
        len = strlen(content);
        unicodecontent = OslMalloc((len + 1) * 2);
        mmi_asc_n_to_ucs2(unicodecontent, content, len);
        memset(unicodecontent + len * 2, 0, 2);
    }

    if (CheckForInvitationMsg((U8*) unicodecontent, len, FALSE))
    {
        S32 invitation_len = (S32)mmi_ucs2strlen(gInvitation);
        memcpy((S8*) unicodecontent, (S8*) unicodecontent + invitation_len * 2, (len - invitation_len) * 2);
        memset((S8*) unicodecontent + (len - invitation_len) * 2, 0, invitation_len * 2);
    }

    IncrementCounter(index);
    point = CopyToBuffer((U8*) unicodecontent, (S32) mmi_ucs2strlen(unicodecontent) * 2, index, flag);
    if (point == NULL)
    {
        DisplayPopup((PU8) GetString(CHATROOM_STORAGE_FULL_ERROR), IMG_GLOBAL_ERROR, FALSE, 2000, ERROR_TONE);
        gChatMsgFlag = 0;
    }
    else
    {
        g_chat_cntx.chatRoomInfo[index].chatStrings[GetNumOfMessage(index) - 1].chat_message_string = point;
        g_chat_cntx.chatRoomInfo[index].chatStrings[GetNumOfMessage(index) - 1].flag = flag;
        mmi_frm_sms_delete_sms(NULL, MOD_MMI, MMI_FRM_SMS_APP_AWAITS, msgentry->index);
    }
    /* free unicodecontent buffer */
    if (unicodecontent != NULL)
    {
        OslMfree(unicodecontent);
        unicodecontent = NULL;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  UpdateChatRoom
 * DESCRIPTION
 *  It updates Chat room upon arrival of new message
 * PARAMETERS
 *  index       [IN]        
 *  flag        [IN]        
 * RETURNS
 *  status
 *****************************************************************************/
pBOOL UpdateChatRoom(U16 index, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms;
    PU8 point = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag == SENDING_CHAT)
    {
        GetEMSDataForEdit(&pEms, 0);
        if ((CheckForInvitationMsg(pEms->textBuffer, pEms->textLength, FALSE)))
        {
            S16 len = (S16) mmi_ucs2strlen(gInvitation);

            ResetCurrentPosition(pEms);
            ForwardCurrentPosition(pEms, len);
            DeletenCharFromEMSBuffer(len);
        }
    }
    else
    {
        GetEMSDataForView(&pEms, 0);
    }

    if (pEms->listHead == NULL)
    {

        IncrementCounter(index);
        point = CopyToBuffer(pEms->textBuffer, (S32) pEms->textLength, index, flag);
        if (point == NULL)
        {
            DisplayPopup((PU8) GetString(CHATROOM_STORAGE_FULL_ERROR), IMG_GLOBAL_ERROR, FALSE, 2000, ERROR_TONE);
            return FALSE;
        }
        g_chat_cntx.chatRoomInfo[index].chatStrings[GetNumOfMessage(index) - 1].chat_message_string = point;
        g_chat_cntx.chatRoomInfo[index].chatStrings[GetNumOfMessage(index) - 1].flag = flag;

        return TRUE;

    }
    return TRUE;

}

/**************/
/* Send Chat Msg */
/**************/
S8 *chatbuff;


/*****************************************************************************
 * FUNCTION
 *  CallbackChatMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CallbackChatMsg(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMI_FRM_SMS_OK:
            DisplayPopup(
                (PU8) GetString(STR_SMS_SEND_SUCCESS),
                IMG_SEND_SUCCESS_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
            mmi_frm_sms_delete_screen_history();
            OnSMSChatSendSuccess();
            break;
        case MMI_FRM_SMS_ABORT:
            /* do not keep chat content when sending fail */
            ReleaseEMSEditBuffer();
            DisplayPopup(
                (PU8) GetString(STR_ABORT_SENDING_SMS),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
            mmi_frm_sms_delete_screen_history();
            OnSMSChatSendAbort();
            break;
        case MMI_FRM_SMS_NOTREADY:
            DisplayPopup(
                (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                IMG_SEND_FAIL_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;

		case MMI_FRM_SMS_RETURN:
			break;

		case MMI_FRM_SMS_END:
		case MMI_FRM_SMS_END_FROM_SENDING:
            ReleaseEMSEditBuffer();
			break;

        default:
            /* do not keep chat content when sending fail */
            ReleaseEMSEditBuffer();
            DisplayPopup(
                (PU8) GetString(STR_SMS_SEND_FAILED),
                IMG_SEND_FAIL_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            mmi_frm_sms_delete_screen_history();
            OnSMSChatSendFailure();
            break;
    }
    if (chatbuff != NULL)
    {
        OslMfree(chatbuff);
        chatbuff = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SendChatMsg
 * DESCRIPTION
 *  It sends chat message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendChatMsg(void)
{
#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    U8 aHeader[(MAX_SMS_CHAT_HEADER_SIZE + 1) * ENCODING_LENGTH];
    U16 buffLen;
    U16 writeChatBufferCharNum;
    BOOL isUcs2Char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    writeChatBufferCharNum = mmi_ucs2strlen((PS8) g_chat_cntx.writeChatBuffer);
    isUcs2Char = mmi_frm_sms_check_UCS2((U16*) g_chat_cntx.writeChatBuffer, writeChatBufferCharNum);

    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
    if (GetUCS2Flag(g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.nickName) || gInputBoxUcs2Flag ||
        isUcs2Char)
    {
        sendData->dcs = SMSAL_UCS2_DCS;
    }
    else
    {
        sendData->dcs = SMSAL_DEFAULT_DCS;
    }
    mmi_ucs2_to_asc(
        (S8*) sendData->number,
        (S8*) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo);
    GetHeader(aHeader, GetCurrentChatRoomNo());
    sendData->stringlength = mmi_ucs2strlen((PS8) aHeader) + mmi_ucs2strlen((PS8) g_chat_cntx.writeChatBuffer);
    /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
    buffLen =
        (((sendData->stringlength + 1) * 2) <
         (MMI_FRM_SMS_MSG_LEN * 10)) ? ((sendData->stringlength + 1) * 2) : (MMI_FRM_SMS_MSG_LEN * 10);
    chatbuff = OslMalloc(buffLen);
    memset(chatbuff, 0, buffLen);
    mmi_ucs2cpy(chatbuff, (S8*) aHeader);
    mmi_ucs2cat(chatbuff, (S8*) g_chat_cntx.writeChatBuffer);
    sendData->string = OslMalloc(buffLen);
    memset(sendData->string, 0, buffLen);
    memcpy(sendData->string, chatbuff, buffLen);
    DeleteScreenIfPresent(CHAT_OPTION_SCREEN_ID_2);
    mmi_frm_sms_send_sms(CallbackChatMsg, MOD_MMI, sendData);
    OslMfree(sendData);

#else /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    U8 aHeader[(MAX_SMS_CHAT_HEADER_SIZE + 1) * ENCODING_LENGTH];
    U16 buffLen;
    U8 *handledBuffer = NULL;
    U8 *handledHeaderBuffer = NULL;
    U16 writeChatBufferCharNum;
    U16 headerCharNum;
    BOOL isUcs2Char = 0;

    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

    writeChatBufferCharNum = mmi_ucs2strlen((PS8) g_chat_cntx.writeChatBuffer);
    isUcs2Char = mmi_frm_sms_check_UCS2((U16*) g_chat_cntx.writeChatBuffer, writeChatBufferCharNum);
    if (GetUCS2Flag(g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.nickName) || gInputBoxUcs2Flag ||
        isUcs2Char)
    {
        sendData->dcs = SMSAL_UCS2_DCS;
    }
    else
    {
        sendData->dcs = SMSAL_DEFAULT_DCS;
    }
    mmi_ucs2_to_asc(
        (S8*) sendData->number,
        (S8*) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo);
    GetHeader(aHeader, GetCurrentChatRoomNo());
    headerCharNum = mmi_ucs2strlen((PS8) aHeader);

    if (sendData->dcs == SMSAL_DEFAULT_DCS)
    {
        handledHeaderBuffer = OslMalloc((headerCharNum * 2 + 1) * ENCODING_LENGTH);
        memset((S8*) handledHeaderBuffer, 0, ((headerCharNum * 2 + 1) * ENCODING_LENGTH));
        mmi_frm_sms_handle_extension_char((U16*) handledHeaderBuffer, (U16*) aHeader, headerCharNum);

        handledBuffer = OslMalloc((writeChatBufferCharNum * 2 + 1) * ENCODING_LENGTH);
        memset((S8*) handledBuffer, 0, ((writeChatBufferCharNum * 2 + 1) * ENCODING_LENGTH));
        mmi_frm_sms_handle_extension_char(
            (U16*) handledBuffer,
            (U16*) g_chat_cntx.writeChatBuffer,
            writeChatBufferCharNum);
    }
    else
    {
        handledHeaderBuffer = OslMalloc((headerCharNum + 1) * ENCODING_LENGTH);
        memset((S8*) handledHeaderBuffer, 0, ((headerCharNum + 1) * ENCODING_LENGTH));
        memcpy((S8*) handledHeaderBuffer, (S8*) aHeader, headerCharNum * ENCODING_LENGTH);

        handledBuffer = OslMalloc((writeChatBufferCharNum + 1) * ENCODING_LENGTH);
        memset((S8*) handledBuffer, 0, ((writeChatBufferCharNum + 1) * ENCODING_LENGTH));
        memcpy((S8*) handledBuffer, (S8*) g_chat_cntx.writeChatBuffer, writeChatBufferCharNum * ENCODING_LENGTH);
    }

    sendData->stringlength = mmi_ucs2strlen((PS8) handledHeaderBuffer) + mmi_ucs2strlen((PS8) handledBuffer);

    /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
    buffLen =
        (((sendData->stringlength + 1) * 2) <
         (MMI_FRM_SMS_MSG_LEN * 10)) ? ((sendData->stringlength + 1) * 2) : (MMI_FRM_SMS_MSG_LEN * 10);
    chatbuff = OslMalloc(buffLen);
    memset(chatbuff, 0, buffLen);

    mmi_ucs2cpy(chatbuff, (S8*) handledHeaderBuffer);
    mmi_ucs2cat(chatbuff, (S8*) handledBuffer);
    sendData->string = OslMalloc(buffLen);
    memset(sendData->string, 0, buffLen);
    memcpy(sendData->string, chatbuff, buffLen);

    if (chatbuff != NULL)
    {
        OslMfree(chatbuff);
        chatbuff = NULL;
    }
    buffLen = ((mmi_ucs2strlen((PS8) aHeader) + writeChatBufferCharNum) + 1) * 2;
    buffLen = ((buffLen) < (MMI_FRM_SMS_MSG_LEN * 10)) ? (buffLen) : (MMI_FRM_SMS_MSG_LEN * 10);
    chatbuff = OslMalloc(buffLen);
    memset(chatbuff, 0, buffLen);
    mmi_ucs2cpy(chatbuff, (S8*) aHeader);
    mmi_ucs2cat(chatbuff, (S8*) g_chat_cntx.writeChatBuffer);

    DeleteScreenIfPresent(CHAT_OPTION_SCREEN_ID_2);
    mmi_frm_sms_send_sms(CallbackChatMsg, MOD_MMI, sendData);
    OslMfree(sendData);
    OslMfree(handledBuffer);
    OslMfree(handledHeaderBuffer);
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  PreSendChatMsg
 * DESCRIPTION
 *  Before send chat message, check DCS and SC number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreSendChatMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    if (!IsScreenPresent(CHAT_SCREEN_START_NEW_ID))
    {
        ExitChatWrite();
    }
    SendChatMsg();
}


/*****************************************************************************
 * FUNCTION
 *  OnSMSChatSendAbort
 * DESCRIPTION
 *  It delets Screen from history upon abort of Message send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void OnSMSChatSendAbort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RemoveHeaderInfo();
    DeleteScreenIfPresent(CHAT_OPTION_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  OnSMSChatSendFailure
 * DESCRIPTION
 *  It delets Screen from history upon failure of Message send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void OnSMSChatSendFailure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(CHAT_SCREEN_START_NEW_ID);
    DeleteScreenIfPresent(CHAT_OPTION_SCREEN_ID);
    gInputBoxUcs2Flag = 0;
    memset(g_chat_cntx.writeChatBuffer, 0, ((MAX_MSG_SIZE + 1) * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  OnSMSChatSendSuccess
 * DESCRIPTION
 *  It delets Screen from history upon success of Message send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void OnSMSChatSendSuccess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetCurrentChatRoomNo();
    PU8 point = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(CHAT_ROOM_SCREEN_ID))
    {
        HistoryReplace(CHAT_ROOM_SCREEN_ID, CHAT_ROOM_SCREEN_ID, EntryChatRoom);
    }
    else if (IsScreenPresent(CHAT_SCREEN_START_NEW_ID))
    {
        HistoryReplace(CHAT_SCREEN_START_NEW_ID, CHAT_ROOM_SCREEN_ID, EntryChatRoom);
    }

    DeleteScreenIfPresent(CHAT_SCREEN_START_NEW_ID);
    DeleteScreenIfPresent(CHAT_OPTION_SCREEN_ID);

    if ((g_chat_cntx.chatRoomInfo[index].status == MMI_MSG_CHAT_DISABLE))
    {
        ActivateChatRoom(GetCurrentChatRoomNo());
    }

    gInputBoxUcs2Flag = 0;
    memset(g_chat_cntx.writeChatBuffer, 0, ((MAX_MSG_SIZE + 1) * ENCODING_LENGTH));
    IncrementCounter(index);
    if (CheckForInvitationMsg((U8*) chatbuff, mmi_ucs2strlen(chatbuff) * 2, FALSE))
    {
        S16 len = (S16) mmi_ucs2strlen(gInvitation);

        memcpy((S8*) chatbuff, (S8*) chatbuff + len * 2, mmi_ucs2strlen(chatbuff) * 2 - len * 2);
        memset((S8*) chatbuff + mmi_ucs2strlen(chatbuff) * 2 - len * 2, 0, len * 2);
    }
    point = CopyToBuffer((U8*) chatbuff, mmi_ucs2strlen(chatbuff) * 2, index, SENDING_CHAT);
    if (point == NULL)
    {
        DisplayPopup((PU8) GetString(CHATROOM_STORAGE_FULL_ERROR), IMG_GLOBAL_ERROR, FALSE, 2000, ERROR_TONE);
        return;
    }
    g_chat_cntx.chatRoomInfo[index].chatStrings[GetNumOfMessage(index) - 1].chat_message_string = point;
    g_chat_cntx.chatRoomInfo[index].chatStrings[GetNumOfMessage(index) - 1].flag = SENDING_CHAT;
}


/*****************************************************************************
 * FUNCTION
 *  CallbackSaveChatMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CallbackSaveChatMsg(void *status, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sendresult = *(U8*) status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMI_FRM_SMS_OK:
            if (sendresult == SMSAL_STO_UNSENT)
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_FAILED_SAVE_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_SAVE_SUCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
            }
            break;
        case MMI_FRM_SMS_MEMFULL:
            if (sendresult == SMSAL_STO_UNSENT)
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_SAVE_FAILED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SEND_SUCESS_SAVE_FILED),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
            }
            break;
        default:
            DisplayPopup(
                (PU8) GetString(STR_SMS_SEND_SAVE_FAILED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
    }
    if (IsScreenPresent(SCR_ID_MSG_WRITE))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_PROCESSING);
    }
    DeleteMessagesHistoryNodes();
    AlmEnableSPOF();
}


/*****************************************************************************
 * FUNCTION
 *  SaveChatMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveChatMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
    sendData->status = SMSAL_STO_UNSENT;
    memset((S8*) sendData->number, 0, MAX_DIGITS_SMS);
    mmi_frm_sms_save_sms(CallbackSaveChatMsg, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_chat_get_invitation_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_msg_chat_get_invitation_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) gInvitation;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_chat_skip_blank_header
 * DESCRIPTION
 *  Skip the blank characters of the recieve chat messages content header
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8* mmi_msg_chat_skip_blank_header(U8* packet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 *p = (U16*)packet;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
	{
		p++;
	}

	return (S8*)p;
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_chat_get_new_msg_channel
 * DESCRIPTION
 *  Get the new message channel(master or slave)
 * PARAMETERS
 *  void
 * RETURNS
 *  E_MTPNP_AD_CHANNELS
 *****************************************************************************/
static E_MTPNP_AD_CHANNELS mmi_msg_chat_get_new_msg_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return chat_new_msg_channel;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_chat_set_new_msg_channel
 * DESCRIPTION
 *  Set the new message channel
 * PARAMETERS
 *  msg_index	[IN]	L4 index of the message
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_chat_set_new_msg_channel(U16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_frm_msg_is_from_master_sim_by_l4_index(msg_index) == TRUE)
	{
		chat_new_msg_channel = MTPNP_AD_CHANNEL_MASTER;
	}
	else
	{
		chat_new_msg_channel = MTPNP_AD_CHANNEL_SLAVE;
	}
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* _CHAT_APPSENDMSG_ */ 
#endif /* __MMI_MESSAGES_CHAT__ */ 


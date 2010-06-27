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
 * ChatAppGuiInterface.C
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

   FILENAME : ChatAppGuiInterface.c

   PURPOSE     : To Provide GUI Interface functions  

   REMARKS     : nil

   AUTHOR      : Alok Sharma     

   DATE     : Feb 18,04

**************************************************************/

#include "MMI_include.h"

#ifdef __MMI_MESSAGES_CHAT__


#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "ProtocolEvents.h"

#include "ChatAppResDef.h"
#include "ChatGtype.h"
#include "ChatAppprot.h"
#include "ChatAppGexdcl.h"
#include "ChatAppGprot.h"
#include "EmsMiscell.h"

#include "SettingProfile.h"
#include "MessagesL4Def.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SmsGuiInterfaceType.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookDef.h"
#include "wgui_ems.h"
#include "ProfileGprots.h"

#include "MessagesResourceData.h"
#include "SMSAPI.h"
#include "SMSStruct.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_SMS_Chat.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */


/****************Static Variable Start*********/
static U8 gSetChatFlagNameNumber = 0;
static S32 gHilightedChatRoomInfoItem;
static U8 gNickname[(MAX_NICKNAME_LENGTH + 1) * ENCODING_LENGTH];
static U8 gDestinationNo[(MAX_PHONE_NUMBER_LENGTH + 2) * ENCODING_LENGTH];
static U16 gDetailChatRoomInfoImageList[4];
static pBOOL gQuitFlag;
static S16 currentMsgCount;
static S8 gNumbersList[(MAX_PHONE_NUMBER_LENGTH + 2) * ENCODING_LENGTH];
static MMI_BOOL mmi_chat_info_from_phb = MMI_FALSE;

/****************Static Variable End*********/

/****************Static Function Start*********/
/****************Static Function End*********/
/****************Global Variable Start*********/
pBOOL gInputBoxUcs2Flag;
pBOOL gOutBoxSaveFlag;
MMI_BOOL is_enter_from_sms_interface; 

/****************Global Variable End*********/

/****************Function Start*********/
 /****************Function End*********/

/*********Extern Variable**********/
/* Deepali */
extern chat_context_struct g_chat_cntx;
extern MMI_PHB_LIST_VIEW phbListView;
extern U8 gIsItChatSmsArrivalInd;
extern U8 gIsThereAnyNewChatSMSToInd;
extern wgui_inline_item wgui_inline_items[];
extern const U16 gChatSmsIcon[];

/*********Extern Function**********/
extern S32 GetInlineListMenuChanged(void);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern void ReleaseEMSEditBuffer(void);

 /**************************End****************************/


/*****************************************************************************
 * FUNCTION
 *  SetChatHiliteHandlers
 * DESCRIPTION
 *  It Sets Hilite Handler of Chat Menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetChatHiliteHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CHAT_ROOM1, HighlightChatRooM1);
    SetHiliteHandler(MENU_CHAT_ROOM2, HighlightChatRooM2);
    SetHiliteHandler(MENU_CHATROOM_INFO, HighlightChatRoomInfo);
#ifndef __MMI_DUAL_SIM_MASTER__
    SetHiliteHandler(MENU_START_NEW, HighlightChatStartMenu);
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetHiliteHandler(MENU_START_NEW, HighlightChatDualmodeStartMenu);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetHiliteHandler(MENU_RESUME_CHAT, HighlightChatResumeMenu);
    SetHiliteHandler(MENU_END_CHAT, HighlightChatEndMenu);

    SetHiliteHandler(MENU_CHATMSG_SEND, HighlightChatSend);
    SetHiliteHandler(MENU_CHATAPP_TEMPLATE, HighlightChatTemplate);
    SetHiliteHandler(MENU_CHAT_PHB_NUM, HighlightChatPhbNum);
    SetHiliteHandler(MENU_CHAT_PHB_NAM, HighlightChatPhbNam);
    SetHiliteHandler(MENU_CHAT_INPUT_METHOD, HighlightChatInputMethod);

    SetHiliteHandler(MENU_CHAT_REPLY_SCRN, HighlightChatReply);
    SetHiliteHandler(MENU_CHAT_USE_NUM_SCRN, HighlightChatUseNumMethod);
    SetHiliteHandler(MENU_CHAT_CLEAR_SCRN, HighlightChatClearMethod);
    SetHiliteHandler(MENU_CHAT_TEMP_SCRN, HighlightChatTempLeaveMethod);
    SetHiliteHandler(MENU_CHAT_QUIT_SCRN, HighlightChatQuitMethod);
    /* SetHiliteHandler (MENU_CHAT_SAVE,HighlititeChatSaveOutBox); */

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_SetDualmode_Chat_Handler();
#endif /* __MMI_DUAL_SIM_MASTER__ */
}

/****************/
/* Highlight Function */
/****************/


/*****************************************************************************
 * FUNCTION
 *  HighlightChatRooM1
 * DESCRIPTION
 *  Hilite function of Chat Room1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatRooM1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 lsk_string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCurrentChatRoomNo(CHAT_ROOM1);
	if (is_enter_from_sms_interface)
	{
		lsk_string_id = STR_GLOBAL_SELECT;
	}
	else
	{
		lsk_string_id = STR_GLOBAL_OPTIONS;
	}
	
    ChangeLeftSoftkey(lsk_string_id, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_msg_chat_select_room, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_chat_select_room, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatRooM2
 * DESCRIPTION
 *  Hilite function of Chat Room2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatRooM2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 lsk_string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCurrentChatRoomNo(CHAT_ROOM2);
	if (is_enter_from_sms_interface)
	{
		lsk_string_id = STR_GLOBAL_SELECT;
	}
	else
	{
		lsk_string_id = STR_GLOBAL_OPTIONS;
	}
	
    ChangeLeftSoftkey(lsk_string_id, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_msg_chat_select_room, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_chat_select_room, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatRoomInfo
 * DESCRIPTION
 *  Hilite function of Chat Room Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatRoomInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryChatRoomInfo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryChatRoomInfo, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatStartMenu
 * DESCRIPTION
 *  Hilite function of Chat Start Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatStartMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* reset message content in case the message in different chatroom using different encoding scheme */
    memset(g_chat_cntx.writeChatBuffer, 0, (MAX_MSG_SIZE + 1) * ENCODING_LENGTH);
    SetLeftSoftkeyFunction(EntryChatWrite, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryChatWrite, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatResumeMenu
 * DESCRIPTION
 *  Hilite function of Chat Resume Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatResumeMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    E_MTPNP_AD_CHANNELS channel;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    channel = MTPNP_PFAL_Get_Chat_Resume_Channel(GetCurrentChatRoomNo());
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, channel);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryChatRoom, KEY_EVENT_UP);
    SetKeyHandler(EntryChatRoom, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryChatRoom, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatEndMenu
 * DESCRIPTION
 *  Hilite function of Chat End Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatEndMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(PreEntryChatQuitConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(PreEntryChatQuitConfirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatSend
 * DESCRIPTION
 *  Hilite Send function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatSend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(PreSendChatMsg, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(PreSendChatMsg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);		
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatTemplate
 * DESCRIPTION
 *  Hilite ChatTemplate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatTemplate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_msg_entry_template_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_entry_template_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);		
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatPhbNum
 * DESCRIPTION
 *  Hilite Function for Phone Book Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatPhbNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EnterPhoneBookForChatNumberApp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EnterPhoneBookForChatNumberApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);	
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatPhbNam
 * DESCRIPTION
 *  Hilite Phone Book Name function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatPhbNam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EnterPhoneBookForChatNameApp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EnterPhoneBookForChatNameApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);		
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatInputMethod
 * DESCRIPTION
 *  Hilite Function for Chat Input Method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(CHAT_IMAGE_APP_ID);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	
    RegisterInputMethodScreenCloseFunction(GoBackHistoryFromChatInputMethod);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatReply
 * DESCRIPTION
 *  Hilite function of Chat Reply Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatReply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    E_MTPNP_AD_CHANNELS channel;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    channel = MTPNP_PFAL_Get_Chat_Resume_Channel(GetCurrentChatRoomNo());
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, channel);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* reset message content in case the message in different chatroom using different encoding scheme */
    memset(g_chat_cntx.writeChatBuffer, 0, (MAX_MSG_SIZE + 1) * ENCODING_LENGTH);
    SetLeftSoftkeyFunction(EntryChatWrite, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryChatWrite, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);			
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatUseNumMethod
 * DESCRIPTION
 *  Hilite function of Chat Use Number method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatUseNumMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_msg_entry_use_number, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_entry_use_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);		
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatClearMethod
 * DESCRIPTION
 *  Hilite Handler of Chat Clear Method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatClearMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClearChatRoomConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryClearChatRoomConfirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);		
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatTempLeaveMethod
 * DESCRIPTION
 *  Hilite Handler of Chat Temp Leave Method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatTempLeaveMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(TempleaveChatApp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(TempleaveChatApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);	
}


/*****************************************************************************
 * FUNCTION
 *  HighlightChatQuitMethod
 * DESCRIPTION
 *  Hilite Handler of Chat Quit Method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatQuitMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gQuitFlag = TRUE;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryChatQuitConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryChatQuitConfirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlititeChatSaveOutBox
 * DESCRIPTION
 *  This is Hilight Function of Chat save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlititeChatSaveOutBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(SaveChatMsgToOutBox, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(SaveChatMsgToOutBox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatOption
 * DESCRIPTION
 *  Entry function of Chat Room Option (before enter chat room)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 numOfItems = 0;
    U16 itemList[MAX_SUB_MENUS];
    U16 itemIcon[MAX_SUB_MENUS];
    U16 scrId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(CHAT_SCREEN_ROOM_ID, NULL, EntryChatOption, NULL);
    if (g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].status == MMI_MSG_CHAT_ENABLE)
    {
        scrId = MENU_ACTIVE_CHAT_ROOM;
    }
    else
    {
        scrId = MENU_DEACTIVE_CHAT_ROOM;
    }

    guiBuffer = GetCurrGuiBuffer(CHAT_SCREEN_ROOM_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetParentHandler(scrId);

    numOfItems = GetNumOfChild(scrId);

    GetSequenceStringIds(scrId, itemList);
    GetSequenceImageIds(scrId, itemIcon);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        CHAT_ROOM_TEXT,
        CHAT_IMAGE_APP_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numOfItems,
        itemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatRoomInfo
 * DESCRIPTION
 *  Entry function of Chat Room Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatRoomInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 inputBufferSize;
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(CHAT_ROOM_INFO_SCREEN_ID, ExitChatRoomInfo, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(CHAT_ROOM_INFO_SCREEN_ID);
    if (guiBuffer == NULL && mmi_chat_info_from_phb == MMI_FALSE)
    {
        mmi_ucs2cpy((S8*) gNickname, (S8*) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.nickName);
        mmi_ucs2cpy(
            (S8*) gDestinationNo,
            (S8*) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo);
        gHilightedChatRoomInfoItem = 1;
    }

    inputBuffer = GetCurrNInputBuffer(CHAT_ROOM_INFO_SCREEN_ID, &inputBufferSize);

    RegisterHighlightHandler(ChatInlineHandler);
    if (GetInlineDoneFlag(guiBuffer))
    {
        SetInlineDoneFlag(guiBuffer);
    }

    InitializeCategory57Screen();
    FillChatRoomActivationStruct();
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 4, inputBuffer);
    }

    if (mmi_chat_info_from_phb == MMI_TRUE)
    {
        set_wgui_inline_list_menu_status(MMI_TRUE);
    }

    ShowCategory57Screen(
        CHAT_ROOM_INFO_STR,
        CHAT_IMAGE_APP_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        4,
        gDetailChatRoomInfoImageList,
        wgui_inline_items,
        gHilightedChatRoomInfoItem,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(PreSaveChatInfo, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  ExitChatRoomInfo
 * DESCRIPTION
 *  Exit function of Chat Room Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitChatRoomInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    h.scrnID = CHAT_ROOM_INFO_SCREEN_ID;
    h.entryFuncPtr = EntryChatRoomInfo;
    gHilightedChatRoomInfoItem = (U8) GetHighlightedItem();
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatWrite
 * DESCRIPTION
 *  It provides Edit screen for writing Chat Message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatWrite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    if (!mmi_ucs2strlen((PS8) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo))
    {
        DisplayPopup((PU8) GetString(CHATROOM_EMPTY_ERROR), IMG_GLOBAL_WARNING, FALSE, 2000, WARNING_TONE);
    }
    else
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        EntryNewScreen(CHAT_SCREEN_START_NEW_ID, ExitChatWrite, EntryChatWrite, NULL);
        guiBuffer = GetCurrGuiBuffer(CHAT_SCREEN_START_NEW_ID);
    #if(0)
		if(GetUCS2Flag(g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.nickName))
			ShowCategory5Screen(STR_CHAT_WRITE_MESSAGE_TITLE, CHAT_IMAGE_APP_ID,
						  STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,g_chat_cntx.writeChatBuffer,MAX_MSG_SIZE_UCS2+1,guiBuffer);
		else
		ShowCategory5Screen(STR_CHAT_WRITE_MESSAGE_TITLE, CHAT_IMAGE_APP_ID,
						  STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,
						  STR_GLOBAL_BACK, IMG_GLOBAL_BACK,(S16)(INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|INPUT_TYPE_USE_ENCODING_BASED_LENGTH|INPUT_TYPE_FORTY_FOUR_LESS_CHARACTER|INPUT_TYPE_SMS_CHAT_MAX_LENGTH_HANDLING),g_chat_cntx.writeChatBuffer,MAX_MSG_SIZE+1,guiBuffer);
    #endif /* (0) */ 
        ShowCategory5Screen(
            STR_CHAT_WRITE_MESSAGE_TITLE,
            CHAT_IMAGE_APP_ID,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (S16) (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_FORTY_FOUR_LESS_CHARACTER),
            g_chat_cntx.writeChatBuffer,
            MAX_MSG_SIZE + 1,
            guiBuffer);

        SetLeftSoftkeyFunction(EntryChatWriteOption, KEY_EVENT_UP);
        SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(PreSendChatMsg, KEY_SEND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitChatWrite
 * DESCRIPTION
 *  Exit function of Chat Edit Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitChatWrite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetInputBoxUCS2Count())
    {
        gInputBoxUcs2Flag = 1;
    }
    else
    {
        gInputBoxUcs2Flag = 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryChatWriteOption
 * DESCRIPTION
 *  Entry function of Chat Option Screen (write message)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatWriteOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 numOfItems = 0;
    U16 itemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(CHAT_OPTION_SCREEN_ID, NULL, EntryChatWriteOption, NULL);

    gHilightedChatRoomInfoItem = 0;
    guiBuffer = GetCurrGuiBuffer(CHAT_OPTION_SCREEN_ID);
    SetParentHandler(MENU_CHAT_OPTION);
    numOfItems = GetNumOfChild(MENU_CHAT_OPTION);
    GetSequenceStringIds(MENU_CHAT_OPTION, itemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        CHAT_ROOM_TEXT,
        CHAT_IMAGE_APP_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numOfItems,
        itemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    GetCurrEndKeyDownHandler();
    SetKeyHandler(ExecCurrEndKeyDownHandler, KEY_END, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatRoom
 * DESCRIPTION
 *  Entry Screen for Chat Room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatRoom()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 numOfItems = 0;
    char *phNumber;
    S16 index = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	EntryNewScreen(CHAT_ROOM_SCREEN_ID, ExitChatRoom, EntryChatRoom, NULL);

  	DeleteScreenIfPresent(CHAT_ROOM_SCREEN_ID);

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        if (!IsScreenPresent(CHAT_SCREEN_ROOM_ID))
        {
            HistoryReplace(SCR_ID_MSG_INBOX_MSG, CHAT_SCREEN_ROOM_ID, EntryChatOption);
        }
    #ifdef __MMI_UNIFIED_MESSAGE__
        DeleteScreenIfPresent(SCR_ID_UM_INBOX);
    #else /* __MMI_UNIFIED_MESSAGE__ */
        DeleteScreenIfPresent(SCR_ID_MSG_INBOX_LIST);
    #endif /* __MMI_UNIFIED_MESSAGE__ */

    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        DeleteScreenIfPresent(SCR_ID_MSG_INBOX_LIST_OPTION);
    #endif
    
        DeleteScreenIfPresent(SCR_ID_MSG_INBOX_MSG);
        DeleteScreenIfPresent(SCR_ID_MSG_INBOX_OPTION);
    }

    guiBuffer = GetCurrGuiBuffer(CHAT_ROOM_SCREEN_ID);

    SetParentHandler(MENU_CHAT_ROOM_SCRN);

    numOfItems = GetNumOfMessage(index);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    phNumber = lookUpNumber((PS8) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo);
    if (phNumber)
    {
        if (mmi_ucs2cmp(phNumber, ""))
        {
            mmi_ucs2ncpy((PS8) gNumbersList, (PS8) phNumber, (U32) (sizeof(gNumbersList) / ENCODING_LENGTH) - 1);
        }
        else
        {
            mmi_ucs2ncpy(
                (PS8) gNumbersList,
                (PS8) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo,
                (U32) (sizeof(gNumbersList) / ENCODING_LENGTH) - 1);
        }
    }
    else
    {
        mmi_ucs2ncpy(
            (PS8) gNumbersList,
            (PS8) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo,
            (U32) (sizeof(gNumbersList) / ENCODING_LENGTH) - 1);
    }

    if (GetMessagechatRoomNo() == index)
    {
        gIsItChatSmsArrivalInd = FALSE;
        gIsThereAnyNewChatSMSToInd = FALSE;
    }
    /* !mmi_is_redrawing_bk_screens() is temp solution for small screen issue */
    if (g_chat_cntx.blinkChatFlag[index] && !mmi_is_redrawing_bk_screens())
    {
        /* do not update status icon before ShowCategoryScreen */
        HideStatusIcon(gChatSmsIcon[index]);
        ShowStatusIcon(gChatSmsIcon[index]);
        g_chat_cntx.blinkChatFlag[index] = FALSE;
    }

    SetMessagesCurrScrnID(CHAT_ROOM_SCREEN_ID);

    ShowCategory305Screen(
        0,
        CHAT_IMAGE_APP_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numOfItems,
        g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatStrings,
        guiBuffer,
        (PU8) gNumbersList,
        IMG_GLOBAL_OK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryChatRoomOption, KEY_EVENT_UP);
    GetCurrEndKeyDownHandler();
    SetKeyHandler(ExecCurrEndKeyDownHandler, KEY_END, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
   	DeleteScreenIfPresent(SCR_CHOOSE_CHAT);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  ExitChatRoom
 * DESCRIPTION
 *  Exit Screen for Chat Room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitChatRoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetMessagesCurrScrnID(0);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySmsMemoryFullIndInChatApp
 * DESCRIPTION
 *  Entry SMS memory full indication in chat room screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySmsMemoryFullIndInChatApp(void)   /* Magesh */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetMessagesCurrScrnID() == CHAT_ROOM_SCREEN_ID)
    {
        DisplayPopup((PU8) GetString(CHATROOM_STORAGE_FULL_ERROR), IMG_GLOBAL_ERROR, FALSE, 2000, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatRoomOption
 * DESCRIPTION
 *  Entry function for Chat Room option (chat room)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatRoomOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 numofitems = 0;
    U16 itemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(CHAT_OPTION_SCREEN_ID_2, NULL, EntryChatRoomOption, NULL);

    guiBuffer = GetCurrGuiBuffer(CHAT_OPTION_SCREEN_ID_2);
    SetParentHandler(MENU_CHAT_OPTION_SCRN);

    numofitems = GetNumOfChild(MENU_CHAT_OPTION_SCRN);

    GetSequenceStringIds(MENU_CHAT_OPTION_SCRN, itemList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        CHAT_IMAGE_APP_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numofitems,
        itemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  PreEntryChatQuitConfirm
 * DESCRIPTION
 *  Wrapper function of GotoQuitChatScreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryChatQuitConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gQuitFlag = FALSE;
    EntryChatQuitConfirm();
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatQuitConfirm
 * DESCRIPTION
 *  Ask from user before quitting from Chat Room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatQuitConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gQuitFlag == TRUE)
    {
        str = get_string(STR_QUIT_CHAT_ROOM_QUERY);
    }
    else
    {
        str = get_string(STR_END_QUERY);
    }
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(QuitChatRoom, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClearChatRoomConfirm
 * DESCRIPTION
 *  It confirms from User before clearing Chat Room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClearChatRoomConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_CLEAR_CHAT_ROOM_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ClearChatRoom, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryChatReplaceConfirm
 * DESCRIPTION
 *  This function Displace Yes/No pop up before replacing Chat Room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChatReplaceConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = GetCurrentChatRoomNo();
	U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_chat_cntx.chatRoomInfo[index].status == MMI_MSG_CHAT_ENABLE)
	{
		string_id = STR_ID_CHAT_END_AND_REPLACE_CHAT_SETTING;
	}
	else
	{
		string_id = STR_ID_CHAT_REPLACE_CHAT_SETTING;
	}
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(string_id),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ReplaceChatRoom, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EnterPhoneBookForChatNumberApp
 * DESCRIPTION
 *  This function calls phone book function to get Phone book number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterPhoneBookForChatNumberApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSetChatFlagNameNumber = CHAT_PHB_NUMBER;
	mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_NUMBER, SetNameNumberForChatScreenExt); 
}


/*****************************************************************************
 * FUNCTION
 *  EnterPhoneBookForChatNameApp
 * DESCRIPTION
 *  This function calls phonebook function to get phone book name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterPhoneBookForChatNameApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty number entry could be selected without checking */
    gSetChatFlagNameNumber = CHAT_PHB_NAME;
	mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_NAME, SetNameNumberForChatScreenExt);  
}


/*****************************************************************************
 * FUNCTION
 *  InsertTemplateToChat
 * DESCRIPTION
 *  To Insert template in Chat message
 * PARAMETERS
 *  templ       [?]     
 *  template to be inserted(?)
 * RETURNS
 *  void
 *****************************************************************************/
void InsertTemplateToChat(S8 *templ)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history temphistory;
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] InsertTemplateToChat *\n");

    if (templ)
    {
        memset(&temphistory, 0, sizeof(temphistory));
        GetHistory(CHAT_SCREEN_START_NEW_ID, &temphistory);
        AppendCategory5String(
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
            g_chat_cntx.writeChatBuffer,
            MAX_MSG_SIZE,
            (U8*) templ,
            temphistory.guiBuffer);
        if (GetHistoryScrID(CHAT_SCREEN_START_NEW_ID, &History) == ST_SUCCESS)
        {
            memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
        }
    }
    DeleteUptoScrID(CHAT_SCREEN_START_NEW_ID);
    GoBackHistory();
    DeInitTemplates();
}


/*****************************************************************************
 * FUNCTION
 *  SetNameNumberForChatScreen
 * DESCRIPTION
 *  This function Set Phone Book Name or Number to Edit screen
 * PARAMETERS
 *  name        [?]     Or number
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SetNameNumberForChatScreen(U8 name[], U8 number[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history temphistory;
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSetChatFlagNameNumber == CHAT_PHB_NAME)
    {
        if (mmi_ucs2strlen((S8*) name))
        {
            memset(&temphistory, 0, sizeof(history));
            GetHistory(CHAT_SCREEN_START_NEW_ID, &temphistory);
            AppendCategory5String(
                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                g_chat_cntx.writeChatBuffer,
                MAX_MSG_SIZE,
                name,
                temphistory.guiBuffer);
            if (GetHistoryScrID(CHAT_SCREEN_START_NEW_ID, &History) == ST_SUCCESS)
            {
                memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
            }
        }
        DeleteUptoScrID(CHAT_SCREEN_START_NEW_ID);
        GoBackHistory();
    }
    else if (gSetChatFlagNameNumber == CHAT_PHB_NUMBER)
    {
        if (mmi_ucs2strlen((S8*) number))
        {
            memset(&temphistory, 0, sizeof(history));
            GetHistory(CHAT_SCREEN_START_NEW_ID, &temphistory);
            AppendCategory5String(
                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                g_chat_cntx.writeChatBuffer,
                MAX_MSG_SIZE,
                number,
                temphistory.guiBuffer);
            if (GetHistoryScrID(CHAT_SCREEN_START_NEW_ID, &History) == ST_SUCCESS)
            {
                memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
            }
        }
        DeleteUptoScrID(CHAT_SCREEN_START_NEW_ID);
        GoBackHistory();
    }
    else if (gSetChatFlagNameNumber == CHAT_PHB_NUMBER_CHATROOMINFO)
    {
        if (mmi_ucs2strlen((PS8) number) > (MAX_DIGITS_SMS - 1))
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            return;
        }
        mmi_ucs2ncpy((S8*) gDestinationNo, (S8*) number, (MAX_DIGITS_SMS - 1));
        
        mmi_chat_info_from_phb = MMI_TRUE;
        EntryChatRoomInfo();
        mmi_chat_info_from_phb = MMI_FALSE;        

        DeleteNScrId(CHAT_ROOM_INFO_SCREEN_ID);                        
    }
}

/*****************************************************************************
 * FUNCTION
 *  SetNameNumberForChatScreenExt
 * DESCRIPTION
 *  This function Set Phone Book Name or Number to Edit screen
 * PARAMETERS
 *  name        [?]     Or number
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SetNameNumberForChatScreenExt(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetNameNumberForChatScreen((U8*) name, (U8*) number);
}

/*****************************************************************************
 * FUNCTION
 *  GoBackHistoryFromChatInputMethod
 * DESCRIPTION
 *  Wrapper function to call GoBackHistory from Input Method function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistoryFromChatInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(CHAT_SCREEN_START_NEW_ID);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ChatInlineHandler
 * DESCRIPTION
 *  Hilite Handler for Destination Number option of Chat Room Info
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ChatInlineHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
        case 1:
            gSetChatFlagNameNumber = 0;
            /* W05.48 Fix RSK Auto Back History Issue in touch Screen */
            EnableCategory57ScreenDone();
            if (GetInlineListMenuChanged())
            {
                ChangeRightSoftkey(STR_GLOBAL_DONE, IMAGE_ID_NULL);
            }
            break;
        case 3: /* check!!!! */
            if ((gDestinationNo != NULL) && (mmi_ucs2strlen((S8*) gDestinationNo)) == 0)
            {
                gSetChatFlagNameNumber = CHAT_PHB_NUMBER_CHATROOMINFO;
                phbListView = MMI_PHB_LIST_FOR_CHAT;
                ChangeLeftSoftkey(STR_SMS_COMMON_SEARCH, IMG_SMS_COMMON_NOIMAGE);
                SetLeftSoftkeyFunction(mmi_phb_list_pre_entry_second_level, KEY_EVENT_UP);
                ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            }
            /* W05.48 Fix RSK Auto Back History Issue in touch Screen */
            DisableCategory57ScreenDone();
            RegisterInputBoxEmptyFunction(ChatNumberScreenEmpty);
            RegisterInputBoxNotEmptyFunction(ChatNumberScreenNotEmpty);

            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ChatNumberScreenEmpty
 * DESCRIPTION
 *  This function is called when there is no data on Edit Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChatNumberScreenEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_SMS_COMMON_SEARCH, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(ChatNumberScreenEmptyKeyHandler, KEY_EVENT_UP);
    //W05.48 Fix RSK Auto Back History Issue in touch Screen
    //ChangeRightSoftkey (STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    //SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  ChatNumberScreenEmptyKeyHandler
 * DESCRIPTION
 *  This Left softkey handler when there is no data on Edit Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChatNumberScreenEmptyKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSetChatFlagNameNumber = CHAT_PHB_NUMBER_CHATROOMINFO;
	mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_NUMBER, SetNameNumberForChatScreenExt);
} 

/*****************************************************************************
 * FUNCTION
 *  ChatNumberScreenNotEmpty
 * DESCRIPTION
 *  This function is called when there is some data on Edit Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChatNumberScreenNotEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSetChatFlagNameNumber = 0;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(PreSaveChatInfo, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ChatInlineCustomFunction
 * DESCRIPTION
 *  This function fills Chat Room Activation recods
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChatInlineCustomFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(CHAT_IMAGE_APP_ID);
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  FillChatRoomActivationStruct
 * DESCRIPTION
 *  Fill chat room info for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FillChatRoomActivationStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(CHATROOM_NICKNAME));
    gDetailChatRoomInfoImageList[0] = IMG_CHAT_NICKNAME;
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[1],
        CHATROOM_NICKNAME,
        CHAT_IMAGE_APP_ID,
        (PU8) gNickname,
        MAX_NICKNAME_LENGTH + 1,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE));

    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], ChatInlineCustomFunction);
    gDetailChatRoomInfoImageList[1] = 0;
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(CHATROOM_DESTINATION));
    gDetailChatRoomInfoImageList[2] = IMG_CHAT_DESTINATION;

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    /* MMI SMS supports 20-digit number. */
    SetInlineItemTextEdit(
        &wgui_inline_items[3],
        (PU8) gDestinationNo,
        MAX_DIGITS_SMS,
        INPUT_TYPE_PHONE_NUMBER);
    DisableInlineItemHighlight(&wgui_inline_items[3]);

    gDetailChatRoomInfoImageList[3] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistoryPreChatInfoSaveKey
 * DESCRIPTION
 *  This is wrapper function for calling GobackHistory from Saving Chat Room Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistoryPreChatInfoSaveKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      CloseCategory57Screen(); 
    //      DeleteUptoScrID(CHAT_ROOM_INFO_ID);
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  PreSaveChatInfo
 * DESCRIPTION
 *  This function asks user Befor saving Chat Room info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreSaveChatInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!GetInlineListMenuChanged())
    {
        GoBackHistory();
        return;
    }
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_SAVE_CHAT_INFO),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(SaveChatRoomInfo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistoryPreChatInfoSaveKey, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SaveChatRoomInfo
 * DESCRIPTION
 *  This function Calls Number Check and number save functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveChatRoomInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CheckChatNumber(gDestinationNo, g_chat_cntx.chatRoomInfo[index].status, index))
    {
        FillChatRoomInfo(gNickname, gDestinationNo, index);
        DisplayPopup(
            (PU8) GetString(STR_SMS_SAVE_SUCESS),
            IMG_GLOBAL_ACTIVATED,
            FALSE,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(CHAT_ROOM_INFO_SCREEN_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  FillChatRoomInfo
 * DESCRIPTION
 *  This function Writes Chat Room Info on NVRAM
 * PARAMETERS
 *  name        [IN]        
 *  destnum     [IN]        
 *  index       [IN]        
 *  Nickname,Destination Number and Chat Room Number(?)
 * RETURNS
 *  void
 *****************************************************************************/
void FillChatRoomInfo(PU8 name, PU8 destnum, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S16 roomCount;
    chat_info_nvram_struct infostruct[MAX_NO_OF_CHAT_ROOM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) (g_chat_cntx.chatRoomInfo[index].chatInfo.nickName), (S8*) name);
    mmi_ucs2cpy((S8*) (g_chat_cntx.chatRoomInfo[index].chatInfo.destinationNo), (S8*) destnum);
    /* memset(&gChatRoomInfo[index].chatInfo.destinationNo[len*ENCODING_LENGTH],0,ENCODING_LENGTH); */
    for (roomCount = 0; roomCount < MAX_NO_OF_CHAT_ROOM; roomCount++)
    {
        U16 index = (U16) roomCount + 1;

        mmi_ucs2cpy(
            (S8*) (infostruct[roomCount].nickName),
            (S8*) g_chat_cntx.chatRoomInfo[roomCount].chatInfo.nickName);
        mmi_ucs2_to_asc(
            (S8*) (infostruct[roomCount].destinationNo),
            (S8*) (g_chat_cntx.chatRoomInfo[roomCount].chatInfo.destinationNo));
        WriteRecord(
            NVRAM_EF_CHAT_ROOM_INFO_LID,
            index,
            (void*)&infostruct[roomCount],
            NVRAM_CHAT_ROOM_INFO_RECORD_SIZE,
            &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckDuplicateNumber
 * DESCRIPTION
 *  This function Writes Chat Room Info on NVRAM
 * PARAMETERS
 *  DestNo      [IN]        
 *  index       [IN]        
 *  Destination number and Chat Room Number(?)
 * RETURNS
 *  status
 *****************************************************************************/
pBOOL CheckDuplicateNumber(PU8 DestNo, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num1[(MAX_PHONE_NUMBER_LENGTH + 2) * ENCODING_LENGTH];
    U8 num2[(MAX_PHONE_NUMBER_LENGTH + 2) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(num1, 0x00, (MAX_PHONE_NUMBER_LENGTH + 2) * ENCODING_LENGTH);
    memset(num2, 0x00, (MAX_PHONE_NUMBER_LENGTH + 2) * ENCODING_LENGTH);
    mmi_ucs2_to_asc((PS8) num1, (PS8) g_chat_cntx.chatRoomInfo[index].chatInfo.destinationNo);
    mmi_ucs2_to_asc((PS8) num2, (PS8) DestNo);
    if (mmi_phb_util_convert_number_to_int(num2) == INVALID_NUMBER)
    {
        return FALSE;
    }
    else
    {
        return ComparePhoneNum((PU8) num1, (PU8) num2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_chat_check_ussd_number
 * DESCRIPTION
 *  Check if the number is USSD string
 * PARAMETERS
 *  number          [?]         And Number length
 *  number_len      [IN]        
 * RETURNS
 *  TRUE means the number is USSD string, Otherwise FALSE
 *****************************************************************************/
U8 mmi_msg_chat_check_ussd_number(U16 *number, S32 number_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ussd_pattern = (U16) '#';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2ncmp((S8*) (number + number_len - 1), (S8*) & ussd_pattern, 1) == 0)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  CheckChatNumber
 * DESCRIPTION
 *  This function Checks for Duplicate Number
 * PARAMETERS
 *  DestNum     [IN]        
 *  status      [IN]        And Chat Room Number
 *  index       [IN]        
 * RETURNS
 *  status
 *****************************************************************************/
pBOOL CheckChatNumber(PU8 DestNum, S8 status, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = mmi_ucs2strlen((S8*) DestNum);
    S32 checkindex = (index == 0) ? 1 : 0;
    U8 ascii_num[MAX_PHONE_NUMBER_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(ascii_num, 0,MAX_PHONE_NUMBER_LENGTH);
    mmi_ucs2_n_to_asc((S8*) ascii_num, (S8*) DestNum, len * ENCODING_LENGTH);
    
    if (!len && (status == MMI_MSG_CHAT_ENABLE))
    {
        DisplayPopup((PU8) GetString(CHATROOM_EMPTY_ERROR), (U16) IMG_GLOBAL_ERROR, FALSE, 2000, ERROR_TONE);
        return FALSE;
    }

    /* else if (CheckDuplicateNumber(DestNum,checkindex) && mmi_ucs2strlen((PS8)DestNum)) */
    else if (CheckDuplicateNumber(DestNum, checkindex))
    {
        DisplayPopup((PU8) GetString(CHATROOM_DUPLICATE_ERROR), IMG_GLOBAL_ERROR, FALSE, 2000, ERROR_TONE);
        return FALSE;
    }
#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */
    else if (!mmi_frm_sms_check_dst_number(ascii_num, (U8) len))
    {
        DisplayPopup((PU8) GetString(STR_ID_PHB_NUM_INVALID), IMG_GLOBAL_ERROR, FALSE, 2000, ERROR_TONE);
        return FALSE;
    }
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  ChatUseNumberScreen
 * DESCRIPTION
 *  Wrapper function to call function which extracts number from chat message
 * PARAMETERS
 *  void
 * RETURNS
 *  total use number record
 *****************************************************************************/
U16 ChatUseNumberScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 totalusenumber = ObtainChatNumbersFromMessageTextWrapper(
                            (char*)g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo. destinationNo,
                            GetCurrentChatRoomNo());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return totalusenumber;
}


/*****************************************************************************
 * FUNCTION
 *  TempleaveChatApp
 * DESCRIPTION
 *  Temp leave function from Chat Room screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TempleaveChatApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(CHAT_SCREEN_ID))
    {
        GoBackToHistory(CHAT_SCREEN_ID);
    }
    else if (IsScreenPresent(CHAT_SCREEN_ROOM_ID) && 
             GetPreviousScrnIdOf(CHAT_SCREEN_ROOM_ID, &screen_id))
    {
        GoBackToHistory(screen_id);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBackChatHistory
 * DESCRIPTION
 *  Wrapper function of Gobackhistory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackChatHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  ExitChatConfirm
 * DESCRIPTION
 *  Exit Function of confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitChatConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  GoBackQuitScreen
 * DESCRIPTION
 *  GoBack Quit Chat Room Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackQuitScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(CHAT_OPTION_SCREEN_ID_2);
    DeleteScreenIfPresent(CHAT_ROOM_SCREEN_ID);
    DeleteScreenIfPresent(CHAT_SCREEN_ROOM_ID);
}


/*****************************************************************************
 * FUNCTION
 *  QuitChatRoom
 * DESCRIPTION
 *  This funtion quits from Chat room and goback to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void QuitChatRoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EndChatRoom();
    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        FALSE,
        MESSAGES_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE);
    GoBackQuitScreen();
}


/*****************************************************************************
 * FUNCTION
 *  EndChatRoom
 * DESCRIPTION
 *  This funtion Reset all Chat room variables and make it disable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EndChatRoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msgCount;
    S16 index = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetMessagechatRoomNo() == index)
    {
        gIsItChatSmsArrivalInd = FALSE;
        gIsThereAnyNewChatSMSToInd = FALSE;
    }
    g_chat_cntx.chatRoomInfo[index].status = MMI_MSG_CHAT_DISABLE;
    ResetMemoryBuffer(index);
    for (msgCount = 0; msgCount < g_chat_cntx.chatRoomInfo[index].chatRoomCounter; msgCount++)
    {
        g_chat_cntx.chatRoomInfo[index].chatStrings[msgCount].chat_message_string = NULL;
    }
    ResetCounter(index);
    HideChatStatusIcon(index);
#ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_PFAL_Set_Chat_Resume_Channel(MTPNP_AD_CHANNEL_NONE, index);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  ClearChatRoom
 * DESCRIPTION
 *  This function displays Done pop up and Calls Clear function for Chat Room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearChatRoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        FALSE,
        MESSAGES_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE);
    ClearChat(GetCurrentChatRoomNo());
    DeleteScreenIfPresent(CHAT_OPTION_SCREEN_ID_2);
}


/*****************************************************************************
 * FUNCTION
 *  ClearChat
 * DESCRIPTION
 *  This function clears Chat room by resseting all varaibles
 * PARAMETERS
 *  index       [IN]        
 *  Chat Room Number(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ClearChat(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msgCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetMemoryBuffer(index);
    for (msgCount = 0; msgCount < g_chat_cntx.chatRoomInfo[index].chatRoomCounter; msgCount++)
    {
        g_chat_cntx.chatRoomInfo[index].chatStrings[msgCount].chat_message_string = NULL;
    }

    ResetCounter(GetCurrentChatRoomNo());
}


/*****************************************************************************
 * FUNCTION
 *  ChatInboxInterface
 * DESCRIPTION
 *  This is an interface function when Chat is selected from Inbox
 * PARAMETERS
 *  destnum     [IN]        
 *  Destination number(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ChatInboxInterface(PU8 destnum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = 0;
    U8 ascii_num[MAX_PHONE_NUMBER_LENGTH + 1];
    S32 len = mmi_ucs2strlen((S8*)destnum);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ascii_num, 0, MAX_PHONE_NUMBER_LENGTH + 1);
    mmi_ucs2_n_to_asc((S8*)ascii_num, (S8*)destnum, len * ENCODING_LENGTH);
    
	if (!IsAPhoneNumber((S8*)destnum) || !mmi_frm_sms_check_dst_number(ascii_num, (U8)len))
    {
        DisplayPopup(
			(PU8)GetString(STR_ID_PHB_NUM_INVALID),
			IMG_GLOBAL_ERROR,
			FALSE,
			MESSAGES_POPUP_TIME_OUT,
			ERROR_TONE);
        return;
    }

    mmi_ucs2cpy((PS8)gNickname, "");
    mmi_ucs2cpy((PS8)gDestinationNo, (PS8)destnum);

	for (index = 0; index < MAX_NO_OF_CHAT_ROOM; index++)
	{
		if (CheckDuplicateNumber(destnum, index) == TRUE)
		{
			SetCurrentChatRoomNo(index);
			if (g_chat_cntx.chatRoomInfo[index].status == MMI_MSG_CHAT_DISABLE)
			{
                if (gChatInvitation)
                {
#ifdef __MMI_DUAL_SIM_MASTER__
					mmi_msg_chat_set_dual_mode_select_state(MMI_CHAT_SELECT_SMS_CHAT_MENU);
					EntryChooseChatScreen();
#else /* __MMI_DUAL_SIM_MASTER__ */
                    ActivateChatRoom(index);
                    UpdateChatRoom(index, RECEIVING_CHAT);
                    EntryChatRoom();
                    DeleteInvitationMessage();
#endif /* __MMI_DUAL_SIM_MASTER__ */
                }
                else
                {
					EntryChatOption();
                }
			}
			
			else
			{
				EntryChatRoom();
			}
			return;
		}

	}

	mmi_msg_entry_chat_room_select();
}


/*****************************************************************************
 * FUNCTION
 *  CheckActiveChatRoom
 * DESCRIPTION
 *  This function returns Chat room number if not active else -1
 * PARAMETERS
 *  void
 * RETURNS
 *  chat room count
 *****************************************************************************/
S16 CheckActiveChatRoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 chatRoomCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (chatRoomCount = 0; chatRoomCount < MAX_NO_OF_CHAT_ROOM; chatRoomCount++)
    {
        if (g_chat_cntx.chatRoomInfo[chatRoomCount].status == MMI_MSG_CHAT_DISABLE)
        {
            return chatRoomCount;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  ReplaceChatRoom
 * DESCRIPTION
 *  This function Replaces first Chat Room with currently selected Chat Room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReplaceChatRoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_chat_cntx.chatRoomInfo[index].status == MMI_MSG_CHAT_ENABLE)
	{
		EndChatRoom();
	}

    FillChatRoomInfo((PU8)gNickname, gDestinationNo, index);
	
    if (gChatInvitation)
    {
#ifdef __MMI_DUAL_SIM_MASTER__
		mmi_msg_chat_set_dual_mode_select_state(MMI_CHAT_SELECT_SMS_CHAT_MENU);
		EntryChooseChatScreen();
#else /* __MMI_DUAL_SIM_MASTER__ */        
		ActivateChatRoom(index);
        UpdateChatRoom(index, RECEIVING_CHAT);
        EntryChatRoom();
        DeleteInvitationMessage();
#endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    else
    {
        EntryChatOption();
    }

	DeleteScreenIfPresent(SCR_ID_CHAT_ROOM_SELECT);
}


/*****************************************************************************
 * FUNCTION
 *  GetChatMsgToOutBox
 * DESCRIPTION
 *  It get chat message to save to outbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetChatMsgToOutBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 nMessageCount;
    EMSData *pEms;
    S8 newLineChar[4], endOfChar[4];
    S16 totalMsgSize = 0, size = 0, totalMsgCount;
    S16 maxBufferSize = MAX_MSG_SIZE + MAX_SMS_CHAT_HEADER_SIZE;
    S16 maxUcsLength = MAX_MSG_SIZE_UCS2;
    S16 roomIndex = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totalMsgCount = GetNumOfMessage(roomIndex);
    if (totalMsgCount == 0)
    {
        return;
    }
    mmi_asc_to_ucs2((PS8) newLineChar, "\n");
    mmi_asc_to_ucs2((PS8) endOfChar, "\0");

    ReleaseEMSEditBuffer();
    GetEMSDataForEdit(&pEms, 1);
    ResetCurrentPosition(pEms);
/**********************************UCS CHECK *******************************/
    for (nMessageCount = 0; nMessageCount < totalMsgCount; nMessageCount++)
    {

        size =
            (S16) (mmi_ucs2strlen
                   ((S8*) g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].chat_message_string));
        if ((totalMsgSize + size + 1) <= maxBufferSize)
        {
            if (GetUCS2Flag((PS8) g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].chat_message_string))
            {

                if ((totalMsgSize + size + 1) <= maxUcsLength)
                {
                    maxBufferSize = maxUcsLength;
                    EMSSetDCS(pEms, SMSAL_UCS2_DCS);
                }
                else
                {
                    S16 UcsLength = 0;
                    S16 indexUcs = GetUCS2CharIndex((PS8) g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].
                                         chat_message_string);
                    if (indexUcs == -1)
                    {
                        break;
                    }
                    UcsLength = totalMsgSize + indexUcs + 1;
                    if (UcsLength <= maxBufferSize)
                    {
                        if (UcsLength <= maxUcsLength)
                        {
                            maxBufferSize = maxUcsLength;
                            EMSSetDCS(pEms, SMSAL_UCS2_DCS);

                        }
                        else
                        {
                            maxBufferSize = UcsLength;

                        }
                    }

                }
                break;
            }

            totalMsgSize += size + 1;
        }
        else
        {
            size = maxBufferSize - totalMsgSize - 1;
            if (size > 0)
            {
                if (GetUCS2Flag
                    ((PS8) g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].chat_message_string))
                {
                    S16 UcsLength = 0;
                    S16 indexUcs = GetUCS2CharIndex((PS8) g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].
                                         chat_message_string);
                    if (indexUcs == -1)
                    {
                        break;
                    }

                    UcsLength = totalMsgSize + indexUcs + 1;

                    if (UcsLength <= maxBufferSize)
                    {
                        maxBufferSize = UcsLength;
                    }
                    else
                    {
                        maxBufferSize = totalMsgSize;
                    }
                }
                break;
            }
        }
    }
/****************************UCS END************************************/

    totalMsgSize = 0;
    for (nMessageCount = 0; nMessageCount < totalMsgCount; nMessageCount++)
    {

        size =
            (S16) (mmi_ucs2strlen
                   ((S8*) g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].chat_message_string));
        if ((totalMsgSize + size + 1) <= maxBufferSize)
        {

            AddString(
                pEms,
                g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].chat_message_string,
                size,
                NULL);

            AddString(pEms, (PU8) newLineChar, 1, NULL);

            totalMsgSize += size + 1;
        }
        else
        {
            size = maxBufferSize - totalMsgSize - 1;
            if (size > 0)
            {

                AddString(
                    pEms,
                    g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].chat_message_string,
                    size,
                    NULL);
                AddString(pEms, (PU8) newLineChar, 1, NULL);
                g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nMessageCount].chat_message_string +=
                    size * ENCODING_LENGTH;
            }
            break;
        }

    }

    currentMsgCount = nMessageCount;
}


/*****************************************************************************
 * FUNCTION
 *  SaveChatMsgToOutBox
 * DESCRIPTION
 *  This  saves Chat Message to OutBox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveChatMsgToOutBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 roomIndex = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetChatMsgToOutBox();
    gOutBoxSaveFlag = TRUE;
    mmi_msg_set_phb_send_case(MMI_SAVE_CHAT);
    mmi_msg_get_number_from_phb(NULL, g_chat_cntx.chatRoomInfo[roomIndex].chatInfo.destinationNo);
}


/*****************************************************************************
 * FUNCTION
 *  AdjustMemoryPointers
 * DESCRIPTION
 *  This  Replaces Saved Pointers with renmaining chat data pointer
 * PARAMETERS
 *  void
 * RETURNS
 *  status
 *****************************************************************************/
extern void SaveChatMsg(void);
U8 AdjustMemoryPointers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 iCount, jCount, nCount, roomIndex;
    S16 remainingMsgCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    roomIndex = GetCurrentChatRoomNo();
    remainingMsgCount = g_chat_cntx.chatRoomInfo[roomIndex].chatRoomCounter - currentMsgCount;
    jCount = currentMsgCount;
    for (iCount = 0; iCount < remainingMsgCount; iCount++, jCount++)
    {
        g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[iCount].chat_message_string =
            g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[jCount].chat_message_string;
        g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[iCount].flag =
            g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[jCount].flag;

    }
    for (nCount = iCount; nCount < remainingMsgCount + currentMsgCount; nCount++)
    {
        g_chat_cntx.chatRoomInfo[roomIndex].chatStrings[nCount].chat_message_string = NULL;
    }

    if ((remainingMsgCount >= 0))
    {
        g_chat_cntx.chatRoomInfo[roomIndex].chatRoomCounter = remainingMsgCount;
        ResetRoundedFlag(roomIndex);
    }

    else
    {
        ClearChat(roomIndex);
    }

    if (GetNumOfMessage(roomIndex) > 0)
    {
        GetChatMsgToOutBox();
        gOutBoxSaveFlag = TRUE;
        SaveChatMsg();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetUCS2CharIndex
 * DESCRIPTION
 *  It returns UCS char position
 * PARAMETERS
 *  buffer      [IN]        
 *  Data Buffer(?)
 * RETURNS
 *  Ucs char position
 *****************************************************************************/
S16 GetUCS2CharIndex(PS8 buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index, bufferLen;
    S16 jCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bufferLen = (U8) (mmi_ucs2strlen(buffer) * ENCODING_LENGTH);
    jCount = -1;
    for (index = 1; index < bufferLen; index += 2)
    {
        jCount++;
        if (buffer[index] != 0x00)
        {
            return jCount;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_chat_room_select
 * DESCRIPTION
 *  entry chat room select screen function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_chat_room_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_enter_from_sms_interface = MMI_TRUE;
	EntryChatApp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_chat_room_select
 * DESCRIPTION
 *  exit chat room select screen function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_chat_room_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_enter_from_sms_interface = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_chat_select_room
 * DESCRIPTION
 *  select chat room
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_chat_select_room(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 index = GetCurrentChatRoomNo();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (is_enter_from_sms_interface)
	{
		if ((strlen((S8*)g_chat_cntx.chatRoomInfo[index].chatInfo.destinationNo) > 0) ||
			(mmi_ucs2strlen(g_chat_cntx.chatRoomInfo[index].chatInfo.nickName) > 0))
		{
			EntryChatReplaceConfirm();
		}
		else
		{	
			ReplaceChatRoom();
		}
	}
	else
	{
	    gChatInvitation = FALSE;
    	gDestinationNo[0] = '\0';
		EntryChatOption();
	}
}


#endif /* __MMI_MESSAGES_CHAT__ */ 


#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#ifdef __MMI_MESSAGES_CHAT__

#include "stdC.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"

#include "EventsGprot.h"
#include "HistoryGprot.h"
#include "GlobalMenuItems.h"
#include "GlobalConstants.h"
#include "Globaldefs.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_popup.h"
#include "wgui_status_icons.h"
#include "CustMenuRes.h"
#include "CommonScreens.h"
#include "Unicodexdcl.h"
#include "TimerEvents.h"
#include "DebugInitDef.h"
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
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookDef.h"
#include "wgui_ems.h"
#include "ProfileGprots.h"

#include "NVRAMEnum.h"
#include "NVRAMProt.h"
#include "MessagesResourceData.h"
#include "SMSAPI.h"
#include "l4dr.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif

#include "SettingDefs.h"

#include "MTPNP_PFAL_custom_hw.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Message_Data_Convert.h"
#include "MTPNP_PFAL_CellBroadcast.h"
#include "MTPNP_PFAL_MessageSetup.h"
#include "MTPNP_PFAL_SMS_Chat.h"

static void mmi_msg_chat_dual_mode_start_menu_handle(void);
static void mmi_msg_chat_select_menu_handle(E_MTPNP_AD_CHANNELS channel);
static void mmi_msg_chat_select_master_lsk_handle(void);
static void mmi_msg_chat_select_slave_lsk_handle(void);

static E_MTPNP_AD_CHANNELS g_chat_channel[MAX_NO_OF_CHAT_ROOM];

static chat_dual_mode_select_entry_state_enum dual_mode_select_enrty_state;

extern chat_context_struct g_chat_cntx;


void MTPNP_PFAL_SetDualmode_Chat_Handler(void)
{
    SetHiliteHandler(MENU_MTPNP_CHARSTART_MASTER_NEW, HighlightChatMasterStartMenu);
    SetHiliteHandler(MENU_MTPNP_CHARSTART_SLAVE_NEW, HighlightChatSlaveStartMenu);
}

void MTPNP_PFAL_Set_Chat_Resume_Channel(E_MTPNP_AD_CHANNELS channel, MTPNP_INT16 chat_room)
{
    g_chat_channel[chat_room] = channel;
}

E_MTPNP_AD_CHANNELS MTPNP_PFAL_Get_Chat_Resume_Channel(MTPNP_INT16 chat_room)
{
    return g_chat_channel[chat_room];
}


void mmi_msg_chat_set_dual_mode_select_state(chat_dual_mode_select_entry_state_enum state)
{
	dual_mode_select_enrty_state = state;
}


static void mmi_msg_chat_dual_mode_start_menu_handle(void)
{
    if (!mmi_ucs2strlen((PS8) g_chat_cntx.chatRoomInfo[GetCurrentChatRoomNo()].chatInfo.destinationNo))
    {
        DisplayPopup((PU8) GetString(CHATROOM_EMPTY_ERROR), IMG_GLOBAL_WARNING, FALSE, 2000, WARNING_TONE);
    }
	else
	{
		mmi_msg_chat_set_dual_mode_select_state(MMI_CHAT_SELECT_START_NEW_MENU);
		EntryChooseChatScreen();
	}
}


void HighlightChatDualmodeStartMenu(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_msg_chat_dual_mode_start_menu_handle, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_chat_dual_mode_start_menu_handle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


static void mmi_msg_chat_select_menu_handle(E_MTPNP_AD_CHANNELS channel)
{
	MTPNP_INT16 curr_room_no = GetCurrentChatRoomNo();
	
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, channel);
    MTPNP_PFAL_Set_Chat_Resume_Channel(channel, curr_room_no);

	switch(dual_mode_select_enrty_state)
	{
		case MMI_CHAT_SELECT_START_NEW_MENU:
		    memset(g_chat_cntx.writeChatBuffer, 0, (MAX_MSG_SIZE + 1) * ENCODING_LENGTH);
			EntryChatWrite();
			break;

		case MMI_CHAT_SELECT_SMS_CHAT_MENU:
            ActivateChatRoom(curr_room_no);
            UpdateChatRoom(curr_room_no, RECEIVING_CHAT);
            EntryChatRoom();
            DeleteInvitationMessage();
			break;

		default:
			MMI_ASSERT(0);
			break;
	}
}


static void mmi_msg_chat_select_master_lsk_handle(void)
{
	mmi_msg_chat_select_menu_handle(MTPNP_AD_CHANNEL_MASTER);
}


static void mmi_msg_chat_select_slave_lsk_handle(void)
{
	mmi_msg_chat_select_menu_handle(MTPNP_AD_CHANNEL_SLAVE);
}


void HighlightChatMasterStartMenu(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_msg_chat_select_master_lsk_handle, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_chat_select_master_lsk_handle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


void HighlightChatSlaveStartMenu(void)
{
#if 1
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_msg_chat_select_slave_lsk_handle, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_chat_select_slave_lsk_handle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void EntryChooseChatScreen(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
    MTPNP_UINT16 nDispAttribute;        /* Stores display attribue */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_CHOOSE_CHAT, MTPNP_NULL, EntryChooseChatScreen, MTPNP_NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CHOOSE_CHAT);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_START_NEW);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_START_NEW);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_START_NEW, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_START_NEW);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_START_NEW, ItemType);

    ShowCategory52Screen(STRING_MTPNP_SETTING, IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, ItemType, 0, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntryChatNotSupportScreen(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_CHAT_NOT_SUPPORT),
                 IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
}

void MTPNP_PFAL_Refresh_StatusBar_Chat_Display(E_MTPNP_AD_STATUS status)
{
    MTPNP_INT16 i;

	kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_Refresh_StatusBar_Chat_Display");

	switch(status)
	{
		case MTPNP_AD_FLIGHT:
	    	for (i = 0; i < MAX_NO_OF_CHAT_ROOM; i++)
	    	{
	    		if (g_chat_cntx.chatRoomInfo[i].status == MMI_MSG_CHAT_ENABLE)
	    		{
					SetCurrentChatRoomNo(i);
					EndChatRoom();
	    		}
	    	}
			break;
			
		case MTPNP_AD_CARD1:
			{
				MTPNP_INT16 preIndex = GetCurrentChatRoomNo();
				
		    	for (i = 0; i < MAX_NO_OF_CHAT_ROOM; i++)
		    	{
		    		if ((g_chat_cntx.chatRoomInfo[i].status == MMI_MSG_CHAT_ENABLE) &&
						(MTPNP_PFAL_Get_Chat_Resume_Channel(i) == MTPNP_AD_CHANNEL_SLAVE))
		    		{
						SetCurrentChatRoomNo(i);
						EndChatRoom();
		    		}
		    	}
				SetCurrentChatRoomNo(preIndex);
			}
			break;
			
		case MTPNP_AD_CARD2:
			{
				MTPNP_INT16 preIndex;
				preIndex = GetCurrentChatRoomNo();

		    	for (i = 0; i < MAX_NO_OF_CHAT_ROOM; i++)
		    	{
		    		if ((g_chat_cntx.chatRoomInfo[i].status == MMI_MSG_CHAT_ENABLE) &&
						(MTPNP_PFAL_Get_Chat_Resume_Channel(i) == MTPNP_AD_CHANNEL_MASTER))
		    		{
						SetCurrentChatRoomNo(i);
						EndChatRoom();
		    		}
		    	}
				SetCurrentChatRoomNo(preIndex);
			}
			break;
			
		case MTPNP_AD_DUALCARD:
		default:
			break;
	}
}

#endif /* __MMI_MESSAGES_CHAT__ */

#endif /* __MMI_DUAL_SIM_MASTER__ */

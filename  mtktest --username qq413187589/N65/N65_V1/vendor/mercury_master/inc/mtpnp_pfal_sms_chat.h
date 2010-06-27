#ifndef __MTPNP_PFAL_SMS_CHAT_H__
#define __MTPNP_PFAL_SMS_CHAT_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#ifdef __MMI_MESSAGES_CHAT__

typedef enum
{
	MMI_CHAT_SELECT_START_NEW_MENU,
	MMI_CHAT_SELECT_SMS_CHAT_MENU
}chat_dual_mode_select_entry_state_enum;


void MTPNP_PFAL_SetDualmode_Chat_Handler(void);

extern E_MTPNP_AD_CHANNELS MTPNP_PFAL_Get_Chat_Resume_Channel(MTPNP_INT16 chat_room);
extern void MTPNP_PFAL_Set_Chat_Resume_Channel(E_MTPNP_AD_CHANNELS channel, MTPNP_INT16 chat_room);

void HighlightChatDualmodeStartMenu(void);
void HighlightChatMasterStartMenu(void);
void HighlightChatSlaveStartMenu(void);

void EntryChooseChatScreen(void);
void EntryChatNotSupportScreen(void);

extern void mmi_msg_chat_set_dual_mode_select_state(chat_dual_mode_select_entry_state_enum state);

extern void MTPNP_PFAL_Refresh_StatusBar_Chat_Display(E_MTPNP_AD_STATUS status);

#endif /* __MMI_MESSAGES_CHAT__ */

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_SMS_CHAT_H__ */

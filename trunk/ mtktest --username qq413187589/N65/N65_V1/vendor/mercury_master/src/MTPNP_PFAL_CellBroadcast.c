#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "stdC.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"

/* ... Add More MMI header */
#include "EventsGprot.h"
#include "HistoryGprot.h"
#include "GlobalMenuItems.h"
#include "GlobalConstants.h"
#include "Globaldefs.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "CustMenuRes.h"
#include "CommonScreens.h"
#include "Unicodexdcl.h"
#include "TimerEvents.h"
#include "DebugInitDef.h"
#include "ProtocolEvents.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"

#include "Gui_ems.h"
#include "wgui_ems.h"
#include "GSM7BitDefaultAlphabet.h"

#include "NVRAMEnum.h"
#include "NVRAMProt.h"
#include "NVRAMType.h"

#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "SettingProt.h"
#include "PhoneBookGprot.h"

#include "GpioInc.h"
#include "KeyBrd.h"
#include "IdleAppDef.h"

#include "CallManagementGprot.h"
#include "nvram_user_defs.h"

#include "SMSApi.h"
#include "SMSStruct.h"

#include "MTPNP_AD_master_header.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "MTPNP_PFAL_Network.h"
#include "MTPNP_AD_resdef.h"
#include "mtpnp_pfal_cellbroadcast.h"

#include "MTPNP_PFAL_CC.h"

#define SWAP_USHORT(Var) *Var = *(unsigned short*)SwapEndian((void*)Var, sizeof(short))

extern const U16 LangEnumAndStrID[MAX_LANG_SUPPORT];
/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
/* cell broadcast messages main menu begin */
static void HighlightDMCBHandler(void);
static void mmi_msg_entry_dm_cb_main_menu(void);
static void HighlightCard2CBHandler(void);
static void mmi_msg_pre_entry_card2_cb_main_menu(void);
static void mmi_msg_get_card2_cb_mode_req(void);
static void mmi_msg_get_card2_cb_mode_rsp_active(void *info);
static void mmi_msg_entry_card2_cb_main_menu(void);
/* cell broadcast messages main menu end */

/* cell broadcast messages mode begin */
static void mmi_msg_highlight_card2_cb_mode(void);
static void mmi_msg_hint_card2_cb_mode(unsigned short index);
static void mmi_msg_subscribe_card2_cb(void);
static void mmi_msg_subscribe_card2_cb_req(MTPNP_UINT8 subscribe);
static void mmi_msg_subscribe_card2_cb_rsp(void *info);
static void mmi_msg_set_card2_cb_mode_req(MTPNP_UINT8 para);
static void mmi_msg_set_card2_cb_mode_rsp(void *info);
static void mmi_msg_refresh_card2_cb_main_menu(void);
/* cell broadcast messages mode end */

/* cell broadcast messages read begin */
static void mmi_msg_highlight_card2_cb_read_message(void);
static void mmi_msg_pre_entry_card2_cb_read_message(void);
static void mmi_msg_get_card2_cb_mode_rsp_display(void *info);
static void ReadCard2CbChnlInfoFromNvram(void);
static void WriteCard2CbChnlInfoToNvram(void);
static void mmi_msg_entry_card2_cb_read_message(void);
static pBOOL mmi_msg_cb_read_card2_message_get_item(S32 item_index, UI_string_type str_buff,
                                                    UI_image_type * img_buff_p, MTPNP_UINT8 str_img_mask);
static void mmi_msg_entry_card2_cb_message(void);
static void mmi_msg_delete_card2_cb_message(void);
static void mmi_msg_go_back_from_card2_cb_message(void);
static void mmi_msg_end_key_from_card2_cb_message(void);
/* cell broadcast messages read end */

/* cell broadcast messages language begin */
static void mmi_msg_highlight_card2_cb_language(void);
static void mmi_msg_pre_entry_card2_cb_language(void);
static void mmi_msg_get_card2_cb_mode_rsp_language(void *info);
static void mmi_msg_entry_card2_cb_language(void);
static void mmi_msg_select_card2_cb_language(void);
/* cell broadcast messages language end */

/* cell broadcast messages channel setting begin */
static void mmi_msg_highlight_card2_cb_channel_settings(void);
static void mmi_msg_entry_card2_cb_channel_settings(void);
/* cell broadcast messages channel setting end */

/* cell broadcast messages channel add begin */
static void mmi_msg_highlight_card2_cb_channel_add(void);
static void mmi_msg_pre_entry_card2_cb_channel_add(void);
static void mmi_msg_add_card2_cb_channel(unsigned short mi);
/* cell broadcast messages channel add end */

/* cell broadcast messages channel edit begin */
static void mmi_msg_highlight_card2_cb_channel_edit(void);
static void mmi_msg_pre_entry_card2_cb_channel_list_edit(void);
static void mmi_msg_pre_entry_card2_cb_channel_edit(void);
static void mmi_msg_entry_card2_cb_channel_edit(void);
static void mmi_msg_exit_card2_cb_channel_edit(void);
static void mmi_msg_set_card2_cb_channel_inline_item(void);
static void mmi_msg_pre_save_card2_cb_channel(void);
static void mmi_msg_save_card2_cb_channel(void);
static void mmi_msg_edit_card2_cb_channel(unsigned short mi);
/* cell broadcast messages channel edit end */

/* cell broadcast messages channel delete begin */
static void mmi_msg_highlight_card2_cb_channel_delete(void);
static void mmi_msg_pre_entry_card2_cb_channel_list_delete(void);
static void mmi_msg_entry_card2_cb_channel_list(void);
static pBOOL mmi_card2_msg_cb_channel_list_get_item(S32 item_index, UI_string_type str_buff,
                                                    UI_image_type * img_buff_p, MTPNP_UINT8 str_img_mask);
static S32 mmi_card2_msg_cb_channel_list_get_hint(S32 item_index, UI_string_type * hint_array);
static void mmi_msg_delete_card2_cb_channel(void);
/* cell broadcast messages channel delete end */

/* cell broadcast messages channel select begin */
static void mmi_msg_highlight_card2_cb_channel_select(void);
static void mmi_msg_pre_entry_card2_cb_channel_select(void);
static void mmi_msg_entry_card2_cb_channel_select(void);
static void mmi_msg_select_card2_cb_channel(void);
/* cell broadcast messages channel select end */

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
static MTPNP_UINT8 *mmi_msg_get_card2_new_cb_ind_string(void);
static void mmi_msg_entry_card2_new_cb_immediate_ind(void);
static void mmi_msg_entry_card2_new_cb_normal_ind(void);
#endif
static void mmi_card2_msg_delete_new_cb_message(void);
static void mmi_card2_msg_go_back_from_new_cb_ind(void);
static void mmi_card2_msg_end_key_from_new_cb_ind(void);
static void mmi_card2_msg_handle_new_cb_ind(void *info);
static void mmi_card2_msg_new_cb_ind(void);
static void ReadCard2CBMessageInfoFromNvram(void);
static void WriteCard2CBMessageInfoToNvram(void);
static void AddCard2CBMessage(unsigned short cbMI, MTPNP_UINT8 cbDCS, MTPNP_UINT8 cbPage, MTPNP_UINT8 * cbMsg,
                              unsigned short totalLen);
static MTPNP_UINT8 DeleteCard2CBMessage(MTPNP_UINT8 delete_index);
static void ReadCard2CBMessageContent(PU32 outLen, MTPNP_UINT8 * msgData, MTPNP_UINT16 msgLength, MTPNP_UINT8 dcs);
static void ConvertCard2CBForDisplay(MTPNP_UINT8 * data, MTPNP_UINT16 len, MTPNP_UINT8 format, U32 * outLen);
static void InitCard2CBNVRAMData(void);
static void ResetCard2CBInfoStructs(void);
static void DeInitCard2CellBroadcastApp(void);
static void mmi_card2_msg_pre_entry_cb_idle_use_number(void);
static void mmi_card2_msg_entry_cb_use_number(void);

static void mmi_card2_msg_cb_read_content_for_display(U8 index, U8 content_state, U8 unread_change);
static void mmi_card2_msg_cb_read_content_from_nvram(U8 start_page, U8 page_num, U8* buff);

static void mmi_card2_msg_pre_delete_new_cb_message(void);
static void mmi_msg_pre_entry_card2_cb_message(void);

static void mmi_msg_pre_entry_card2_cb_channel_settings(void);

static void mmi_card2_msg_cb_get_msg_list_index(S32 nIndex);


/**************************LOCAL*FUNCTION*DECLARE*END*************************/

static msg_cb_state_enum g_card2_cb_state;
static msg_cb_info_struct g_card2_cb_info;
static msg_cb_display_struct g_card2_cb_display;
static msg_cb_channel_nvram_struct g_card2_cbNvramStruct;
static msg_cb_msg_index_struct g_card2_cbMsgIndex;
static msg_cb_msg_info_struct g_card2_cbMsgInfo;
static U32 g_card2_dispCBLength = 0;
static MTPNP_UINT8 g_card2_IsCBMessageReadOperRequired = MTPNP_TRUE;
static MTPNP_UINT8 g_card2_dispCBMessage[NVRAM_SMS_CB_SMS_PAGE_SIZE * ENCODING_LENGTH * MAX_CB_MSG_PAGE + ENCODING_LENGTH];
static MTPNP_UINT16 g_card2_cbChnlEditorIcons[MAX_CB_CHNL_INLINE_ITEM] = {
    IMG_CB_CHNL_TITLE,
    IMG_SMS_COMMON_NOIMAGE,
    IMG_CB_CHNL_NUMBER,
    IMG_SMS_COMMON_NOIMAGE
};

static U8 IsCard2CBChannelFull = FALSE;
static U8 Card2L4cTotalMidNum;


void MTPNP_PFAL_InitCellBroadcastApp(void)
{
    SetHiliteHandler(MENU_MTPNP_DM_CB_MESSAGES, HighlightDMCBHandler);
    SetHiliteHandler(MENU_MTPNP_CB_MESSAGES, HighlightCard2CBHandler);
    SetHiliteHandler(MITEM_MTPNP_CB_SERVICE, mmi_msg_highlight_card2_cb_mode);
    SetHintHandler(MITEM_MTPNP_CB_SERVICE, mmi_msg_hint_card2_cb_mode);
    SetHiliteHandler(MITEM_MTPNP_CB_READ_MESSAGE, mmi_msg_highlight_card2_cb_read_message);
    SetHiliteHandler(MITEM_MTPNP_CB_LANGUAGE, mmi_msg_highlight_card2_cb_language);
    SetHiliteHandler(MITEM_MTPNP_CB_CHANNELS, mmi_msg_highlight_card2_cb_channel_settings);
    SetHiliteHandler(MITEM_MTPNP_CB_CHANNEL_ADD, mmi_msg_highlight_card2_cb_channel_add);
    SetHiliteHandler(MITEM_MTPNP_CB_CHANNEL_EDIT, mmi_msg_highlight_card2_cb_channel_edit);
    SetHiliteHandler(MITEM_MTPNP_CB_CHANNEL_DELETE, mmi_msg_highlight_card2_cb_channel_delete);
    SetHiliteHandler(MITEM_MTPNP_CB_CHANNEL_SELECT, mmi_msg_highlight_card2_cb_channel_select);

	ResetCard2CBInfoStructs();
	InitCard2CBNVRAMData();

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CB_MSG_IND, mmi_card2_msg_handle_new_cb_ind);
}

/* cell broadcast messages main menu begin */
static void HighlightDMCBHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_msg_entry_dm_cb_main_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_entry_dm_cb_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_entry_dm_cb_main_menu(void)
{
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_MSG_CB_MAIN_MENU, NULL, mmi_msg_entry_dm_cb_main_menu, 
                         MENU_MTPNP_DM_CB_MESSAGES, STR_CB_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION);
}

static void HighlightCard2CBHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_card2_cb_main_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_pre_entry_card2_cb_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_pre_entry_card2_cb_main_menu(void)
{
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_CB_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        return;
    }
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        return;
    }

    g_card2_cb_state = SMS_CB_SERVICE_MODE_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_active);
    mmi_msg_get_card2_cb_mode_req();
}

static void mmi_msg_get_card2_cb_mode_req(void)
{
    MTPNP_AD_Get_CB_Mode_Req();
}

static void mmi_msg_get_card2_cb_mode_rsp_active(void *info)
{
    ST_MTPNP_AD_GET_CB_MODE_RSP *msgRsp = (ST_MTPNP_AD_GET_CB_MODE_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP);
    if (msgRsp->result == MTPNP_TRUE)
    {
        g_card2_cb_info.mode = msgRsp->mode;
        MTPNP_OSAL_memset(g_card2_cb_display.mode, 0, ENCODING_LENGTH);
        if (g_card2_cb_info.mode == MTPNP_TRUE)
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_card2_cb_display.mode,
                                           (MTPNP_CHAR *) GetString((MTPNP_UINT16) STR_GLOBAL_ON));
        }
        else
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_card2_cb_display.mode,
                                           (MTPNP_CHAR *) GetString((MTPNP_UINT16) STR_GLOBAL_OFF));
        }
        mmi_msg_entry_card2_cb_main_menu();
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_CB_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
    }
}

static void mmi_msg_entry_card2_cb_main_menu(void)
{
    MTPNP_UINT8 *guiBuffer = MTPNP_NULL;
    MTPNP_UINT16 numItems = 0;
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];
    MTPNP_UINT8 *popUpList[MAX_SUB_MENUS];

    EntryNewScreen(SCR_MTPNP_MSG_CB_MAIN_MENU, mmi_msg_exit_generic, mmi_msg_entry_card2_cb_main_menu, MTPNP_NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_MAIN_MENU);

    numItems = GetNumOfChild_Ext(MENU_MTPNP_CB_MESSAGES);
    GetSequenceStringIds_Ext(MENU_MTPNP_CB_MESSAGES, nStrItemList);
    SetParentHandler(MENU_MTPNP_CB_MESSAGES);
    ConstructHintsList(MENU_MTPNP_CB_MESSAGES, popUpList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_MAIN_MENU);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_MAIN_MENU);

    ShowCategory52Screen(STR_CB_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION, STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK, numItems, nStrItemList,
                         (MTPNP_UINT16 *) gIndexIconsImageList, popUpList, 0, 0, guiBuffer);
}

/* cell broadcast messages main menu end */

/* cell broadcast messages mode begin */
static void mmi_msg_highlight_card2_cb_mode(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_subscribe_card2_cb, GoBackHistory);

    if (g_card2_cb_info.mode == MTPNP_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_hint_card2_cb_mode(unsigned short index)
{
    MTPNP_OSAL_memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) g_card2_cb_display.mode);
}

static void mmi_msg_subscribe_card2_cb(void)
{
    MTPNP_UINT8 mode = !g_card2_cb_info.mode;

    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CB_SUBSCRIBE_RSP, mmi_msg_subscribe_card2_cb_rsp);
    mmi_msg_subscribe_card2_cb_req(mode);
}

static void mmi_msg_subscribe_card2_cb_req(MTPNP_UINT8 subscribe)
{
    MTPNP_AD_Subscribe_CB_Req(subscribe);
}

static void mmi_msg_subscribe_card2_cb_rsp(void *info)
{
    MTPNP_BOOL *msgRsp = (MTPNP_BOOL *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_CB_SUBSCRIBE_RSP);
    if (*msgRsp)
    {
        if (g_card2_cb_state == SMS_CB_DEFAULT_SETTINGS_MODE_STATE)
        {
            MTPNP_UINT8 i = 0;

            for (i = 0; i < SMS_CB_MAX_ENTRY; i++)
            {
                g_card2_cb_info.cbchnlentry[i].mask = 1;
            }

            for (i = 0; i < SMS_CB_MAX_LANG; i++)
            {
                g_card2_cb_info.cblanentry[i].mask = 1;
            }
            g_card2_cb_info.dcsall = 1;
            MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP, mmi_msg_set_card2_cb_mode_rsp);
            mmi_msg_set_card2_cb_mode_req(SMSAL_CB_MI_MASK | SMSAL_CB_DCS_MASK);
        }
        else
        {
            MTPNP_UINT8 subscribe = (!g_card2_cb_info.mode);

            g_card2_cb_info.mode = subscribe;
            MTPNP_OSAL_memset(g_card2_cb_display.mode, 0, ENCODING_LENGTH);
            if (g_card2_cb_info.mode == MTPNP_TRUE)
            {
                MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_card2_cb_display.mode,
                                               (MTPNP_CHAR *) GetString((MTPNP_UINT16) STR_GLOBAL_ON));
            }
            else
            {
                MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_card2_cb_display.mode,
                                               (MTPNP_CHAR *) GetString((MTPNP_UINT16) STR_GLOBAL_OFF));
            }
            mmi_msg_refresh_card2_cb_main_menu();
        }
    }
    else
    {
        if (g_card2_cb_state == SMS_CB_DEFAULT_SETTINGS_MODE_STATE)
        {
            RstRestoreDisplayPopup(MTPNP_FALSE);
        }
        else
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_CB_ERROR_MESSAGE), IMG_GLOBAL_UNFINISHED, 1,
                         MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        }
    }
}

static void mmi_msg_set_card2_cb_mode_req(MTPNP_UINT8 para)
{
    ST_MTPNP_AD_SET_CB_MODE_REQ msgReq = { 0 };
    MTPNP_UINT8 i = 0;
    WriteCard2CbChnlInfoToNvram();

    if ((para & SMSAL_CB_MI) == SMSAL_CB_MI)
    {
        for (i = 0; i < SMS_CB_MAX_ENTRY; i++)
        {
            msgReq.info.mid[i] = SMSAL_CB_UNUSED_CBMI;
        }
        for (i = 0; i < g_card2_cb_info.totalmi; i++)
        {
            msgReq.info.mid[g_card2_cb_info.cbchnlentry[i].index] = g_card2_cb_info.cbchnlentry[i].mi;
        }
    }
    if (((para & SMSAL_CB_MI) == SMSAL_CB_MI) || ((para & SMSAL_CB_MI_MASK) == SMSAL_CB_MI_MASK))
    {
        for (i = 0; i < SMS_CB_MAX_ENTRY; i++)
        {
            msgReq.info.mid_mask[i] = 1;
        }
        for (i = 0; i < g_card2_cb_info.totalmi; i++)
        {
            msgReq.info.mid_mask[g_card2_cb_info.cbchnlentry[i].index] = g_card2_cb_info.cbchnlentry[i].mask;
        }
    }
    if ((para & SMSAL_CB_DCS_MASK) == SMSAL_CB_DCS_MASK)
    {
		para |= SMSAL_CB_DCS;
        for (i = 0; i < SMS_CB_MAX_LANG; i++)
        {
            msgReq.info.dcs_mask[i] = 1;
			msgReq.info.dcs[i] = SMSAL_CB_UNUSED_DCS;
        }
        for (i = 0; i < g_card2_cb_info.totaldcs; i++)
        {
            msgReq.info.dcs_mask[g_card2_cb_info.cblanentry[i].index] = g_card2_cb_info.cblanentry[i].mask;
            msgReq.info.dcs[g_card2_cb_info.cblanentry[i].index] = g_card2_cb_info.cblanentry[i].dcs;
        }
    }
    if ((para & SMSAL_CB_ALL_LANG) == SMSAL_CB_ALL_LANG)
    {
        msgReq.info.is_all_language_on = g_card2_cb_info.dcsall;
    }
    msgReq.info.para_ind = para;

    MTPNP_AD_Set_CB_Mode_Req(&msgReq);
}

static void mmi_msg_set_card2_cb_mode_rsp(void *info)
{
    ST_MTPNP_AD_SET_CB_MODE_RSP *msgRsp = (ST_MTPNP_AD_SET_CB_MODE_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP);
    if (msgRsp->result == MTPNP_TRUE)
    {
        switch (g_card2_cb_state)
        {
        case SMS_CB_DEFAULT_SETTINGS_MODE_STATE:
            if (msgRsp->result == MTPNP_TRUE)
                RstRestoreDisplayPopup(MTPNP_TRUE);
            else
                RstRestoreDisplayPopup(MTPNP_FALSE);
            break;
        case SMS_CB_CHNL_SELECT_STATE:
        case SMS_CB_CHNL_EDIT_STATE:
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_SAVE_SUCESS), IMG_GLOBAL_ACTIVATED, 1,
                         MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) SUCCESS_TONE);
            DeleteMessagesHistoryNodes();
            break;
			
        case SMS_CB_CHNL_ADD_STATE:
			    if (g_card2_cb_info.totalmi == Card2L4cTotalMidNum)
                {
                    IsCard2CBChannelFull = TRUE;
                }
                DisplayPopup(
                    (PU8) GetString(STR_ID_MSG_SMS_ADD_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
                DeleteMessagesHistoryNodes();
                break;
			
        case SMS_CB_CHNL_DELETE_STATE:
            if (IsCard2CBChannelFull == TRUE)
            {
                IsCard2CBChannelFull = FALSE;
            }
            if (g_msg_cntx.currHiliteIndex == g_card2_cb_info.totalmi)
            {
                g_msg_cntx.currHiliteIndex--;
            }
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_MESSAGES_DELETED_ID), IMG_GLOBAL_ACTIVATED, 1,
                         MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) SUCCESS_TONE);
            if (g_card2_cb_info.totalmi == 0)
            {
                DeleteScreenIfPresent(SCR_MTPNP_MSG_CB_CHANNEL_LIST);
            }
            break;
        case SMS_CB_LANGUAGE_STATE:
            if (msgRsp->result == MTPNP_TRUE)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_SAVE_SUCESS), IMG_GLOBAL_ACTIVATED, 1,
                             MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) SUCCESS_TONE);
                DeleteMessagesHistoryNodes();
            }
            else
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_MESSAGES_UNKNOWN_ERROR),
                             IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
                DeleteMessagesHistoryNodes();
            }
            break;
        }
    }
    else
    {
        if (g_card2_cb_state == SMS_CB_DEFAULT_SETTINGS_MODE_STATE)
        {
            RstRestoreDisplayPopup(MTPNP_FALSE);
        }
        else
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_CHANNEL_LIST);
            DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_CB_ERROR_MESSAGE), IMG_GLOBAL_UNFINISHED, 1,
                         MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
            DeleteMessagesHistoryNodes();
        }
    }
}

static void mmi_msg_refresh_card2_cb_main_menu(void)
{
    MTPNP_INT index = GetChildMenuIDIndexByParentMenuID(MENU_MTPNP_CB_MESSAGES, MITEM_MTPNP_CB_SERVICE);;
    if (index != -1)
    {
        Category52ChangeItemDescription(index, g_card2_cb_display.mode);
    }
    if (g_card2_cb_info.mode == MTPNP_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    SetLeftSoftkeyFunction(mmi_msg_subscribe_card2_cb, KEY_EVENT_UP);
    RedrawCategoryFunction();
}

/* cell broadcast messages mode end */

/* cell broadcast messages read begin */
static void mmi_msg_highlight_card2_cb_read_message(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_pre_entry_card2_cb_read_message, GoBackHistory);
}

static void mmi_msg_pre_entry_card2_cb_read_message(void)
{
    if (g_card2_cbMsgIndex.currCBTotal == 0)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT,
                     (MTPNP_UINT8) EMPTY_LIST_TONE);
    }
    else
    {
        g_card2_cb_state = SMS_CB_READ_MESSAGE_STATE;
        MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_display);
        mmi_msg_get_card2_cb_mode_req();
    }
}

static void mmi_msg_get_card2_cb_mode_rsp_display(void *info)
{
    ST_MTPNP_AD_GET_CB_MODE_RSP *msgRsp = (ST_MTPNP_AD_GET_CB_MODE_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP);
    if (msgRsp->result == MTPNP_TRUE)
    {
        MTPNP_UINT8 i = 0;
        MTPNP_UINT8 total = 0;
        MTPNP_UINT8 addindex = msgRsp->total_mid_num;

        ReadCard2CbChnlInfoFromNvram();

        Card2L4cTotalMidNum = msgRsp->total_mid_num;

        for (i = 0; i < msgRsp->total_mid_num; i++)
        {
            if (msgRsp->info.mid[i] != SMSAL_CB_UNUSED_CBMI)
            {
                MTPNP_UINT8 j = 0;

                g_card2_cb_info.cbchnlentry[total].mi = msgRsp->info.mid[i];
                g_card2_cb_info.cbchnlentry[total].mask = msgRsp->info.mid_mask[i];
                g_card2_cb_info.cbchnlentry[total].index = i;

                MTPNP_OSAL_memset(g_card2_cb_info.cbchnlentry[total].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
                while ((g_card2_cbNvramStruct.l4MidIndex[j] != i) && (j < SMS_CB_MAX_ENTRY))
                    j++;
                if (j == SMS_CB_MAX_ENTRY)
                {
                    MTPNP_OSAL_memset((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[total].name, 0,
                                      MAX_CB_CHNL_NAME_LENGTH);
                    g_card2_cb_info.cbchnlentry[total].dcs = PHB_ASCII;
                }
                else
                {
                    memcpy((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[total].name,
                           (MTPNP_CHAR *) g_card2_cbNvramStruct.chnlNames[j].name, MAX_CB_CHNL_NAME_LENGTH);
                    g_card2_cb_info.cbchnlentry[total].dcs = g_card2_cbNvramStruct.chnlNames[j].name_dcs;
                }
                total++;
            }
            else
            {
                if (addindex == msgRsp->total_mid_num)
                    addindex = i;
            }
        }
        g_card2_cb_info.totalmi = total;
        MTPNP_OSAL_memset(&g_card2_cbNvramStruct, 0xff, sizeof(msg_cb_channel_nvram_struct));
        for (i = 0; i < g_card2_cb_info.totalmi; i++)
        {
            g_card2_cbNvramStruct.l4MidIndex[i] = g_card2_cb_info.cbchnlentry[i].index;
            g_card2_cbNvramStruct.chnlNames[i].name_dcs = g_card2_cb_info.cbchnlentry[i].dcs;
            memcpy((MTPNP_CHAR *) g_card2_cbNvramStruct.chnlNames[i].name,
                   (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name, MAX_CB_CHNL_NAME_LENGTH + 1);
        }
        WriteCard2CbChnlInfoToNvram();

        switch (g_card2_cb_state)
        {
		case SMS_CB_CHNL_SETTING_STATE:
            if (g_card2_cb_info.totalmi == msgRsp->total_mid_num)
            {
                IsCard2CBChannelFull = TRUE;
            }
            mmi_msg_entry_card2_cb_channel_settings();
            break;

        case SMS_CB_CHNL_SELECT_STATE:
            if (g_card2_cb_info.totalmi == 0)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1,
                             MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) WARNING_TONE);
            }
            else
            {
                mmi_msg_entry_card2_cb_channel_select();
            }
            break;
        case SMS_CB_CHNL_EDIT_STATE:
        case SMS_CB_CHNL_DELETE_STATE:
            if (g_card2_cb_info.totalmi == 0)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1,
                             MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) WARNING_TONE);
            }
            else
            {
                mmi_msg_entry_card2_cb_channel_list();
            }
            break;
        case SMS_CB_CHNL_ADD_STATE:
            if (g_card2_cb_info.totalmi == msgRsp->total_mid_num)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_CB_CHNL_FULL), IMG_GLOBAL_WARNING, 1,
                             MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) WARNING_TONE);
            }
            else
            {
                g_card2_cb_display.addindex = addindex;
                MTPNP_OSAL_memset(g_card2_cb_display.name, 0, (MAX_CB_CHNL_NAME_LENGTH + 1) * ENCODING_LENGTH);
                MTPNP_OSAL_memset(g_card2_cb_display.mi, 0, (MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH);
                g_card2_cb_display.dcs = PHB_ASCII;
                mmi_msg_entry_card2_cb_channel_edit();
            }
            break;
        case SMS_CB_READ_MESSAGE_STATE:
            mmi_msg_entry_card2_cb_read_message();
            break;
        }
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_CB_ERROR_MESSAGE), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
    }
}

static void ReadCard2CbChnlInfoFromNvram(void)
{
    S16 error = 0;
    if (ReadRecord(NVRAM_EF_CARD2_CB_CHNL_LID, 1, &g_card2_cbNvramStruct, NVRAM_SMS_CB_CHNL_RECORD_SIZE, &error) < 0)
    {
    }
}

static void WriteCard2CbChnlInfoToNvram(void)
{
    S16 error = 0;
    if (WriteRecord(NVRAM_EF_CARD2_CB_CHNL_LID, 1, &g_card2_cbNvramStruct, NVRAM_SMS_CB_CHNL_RECORD_SIZE, &error) !=
        NVRAM_SMS_CB_CHNL_RECORD_SIZE)
    {
    }
}

static void mmi_msg_entry_card2_cb_read_message(void)
{
    MTPNP_UINT8 *guiBuffer = MTPNP_NULL;
    S32 hiliteitem = 0;
	
    EntryNewScreen(SCR_MTPNP_MSG_CB_MESSAGE_LIST, mmi_msg_exit_generic, mmi_msg_entry_card2_cb_read_message,
                   MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_MESSAGE_LIST);
    if ((guiBuffer != MTPNP_NULL)
        || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_MTPNP_MSG_CB_MESSAGE_LIST)
        || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_MTPNP_MSG_CB_MESSAGE))
    {
    	list_menu_category_history *h;

		hiliteitem = (g_card2_cb_display.msg_hilite_index < g_card2_cbMsgIndex.currCBTotal) ? g_card2_cb_display.msg_hilite_index : 0;
		h = (list_menu_category_history*)guiBuffer;
 		h->highlighted_item = (S16)hiliteitem;
	}

    RegisterHighlightHandler(mmi_card2_msg_cb_get_msg_list_index);

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_MESSAGE_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_MESSAGE_LIST);
    ShowCategory184Screen(STRING_MTPNP_CB_READ_MESSAGE, IMG_SMS_ENTRY_SCRN_CAPTION, STR_GLOBAL_OK, IMG_GLOBAL_OK,
                          STR_GLOBAL_BACK, IMG_GLOBAL_BACK, g_card2_cbMsgIndex.currCBTotal,
                          mmi_msg_cb_read_card2_message_get_item, MTPNP_NULL, hiliteitem, guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_pre_entry_card2_cb_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_pre_entry_card2_cb_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static pBOOL mmi_msg_cb_read_card2_message_get_item(S32 item_index, UI_string_type str_buff,
                                                    UI_image_type * img_buff_p, MTPNP_UINT8 str_img_mask)
{
    MTPNP_UINT8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];
    MTPNP_UINT8 i = 0;

    if ((item_index < 0) || (item_index >= g_card2_cbMsgIndex.currCBTotal))
        return FALSE;

    for (i = 0; i < g_card2_cb_info.totalmi; i++)
    {
        if ((g_card2_cb_info.cbchnlentry[i].mi == g_card2_cbMsgInfo.MsgMI[item_index])
            && (strlen((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name) > 0))
            break;
    }
    if (i < g_card2_cb_info.totalmi)
    {
        if (g_card2_cb_info.cbchnlentry[i].dcs == PHB_ASCII)
        {
            mmi_asc_to_ucs2((MTPNP_CHAR *) str_buff, (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name);
        }
        else
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff, (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name);
        }
    }
    else
    {
        MTPNP_OSAL_memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
        sprintf((MTPNP_CHAR *) number, "%d", g_card2_cbMsgInfo.MsgMI[item_index]);
        mmi_asc_to_ucs2((MTPNP_CHAR *) str_buff, (MTPNP_CHAR *) number);
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}

static void mmi_msg_entry_card2_cb_message(void)
{
    MTPNP_UINT8 *guiBuffer = MTPNP_NULL;

    EntryNewScreen(SCR_MTPNP_MSG_CB_MESSAGE, mmi_msg_exit_generic, mmi_msg_entry_card2_cb_message, MTPNP_NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_MESSAGE);

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_MESSAGE);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_MESSAGE);

    mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_DELETE_MESSAGE_QUERY, mmi_msg_delete_card2_cb_message, GoBackHistory);
    GetCurrEndKeyDownHandler();
    ShowCategory74Screen(
        STRING_MTPNP_CB_MESSAGE_BODY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_DELETE,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        (PU8) g_card2_dispCBMessage,
        (S32) g_card2_dispCBLength,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_msg_entry_confirm_generic, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_msg_go_back_from_card2_cb_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_go_back_from_card2_cb_message, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_end_key_from_card2_cb_message, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_card2_msg_entry_cb_use_number, KEY_SEND, KEY_EVENT_UP);
}

static void mmi_msg_delete_card2_cb_message(void)
{
    SetMessagesScrnIdDelUpToHistoryNodes(SCR_MTPNP_MSG_CB_MESSAGE);
    if (g_card2_cbMsgInfo.MsgPage[g_card2_cb_display.currindex] > 0)
    {
		if (g_card2_cbMsgIndex.pCBMsgContent != NULL)
		{
			OslMfree(g_card2_cbMsgIndex.pCBMsgContent);
			g_card2_cbMsgIndex.pCBMsgContent = NULL;
		}
		
        DeleteCard2CBMessage(g_card2_cb_display.currindex);
        WriteCBMessageInfoToNvram();
		
        if (g_card2_cbMsgIndex.currCBTotal == 0)
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_MESSAGE_LIST);
        }
        else
        {
            if (g_card2_cb_display.msg_hilite_index == (U8)g_card2_cbMsgIndex.currCBTotal)
            {
                g_card2_cb_display.msg_hilite_index--;
            }
            else if (g_card2_cb_display.msg_hilite_index > (U8)g_card2_cbMsgIndex.currCBTotal)
            {
                g_card2_cb_display.msg_hilite_index = 0;
            }

            SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_MESSAGE);
        }
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_DELETED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        g_card2_cb_display.currindex = MAX_STORE_CB_MSG;
        DeleteMessagesHistoryNodes();
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_MESSAGE_LIST);
        DisplayPopup(
            (PU8) GetString(STR_CB_ERROR_MESSAGE),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteMessagesHistoryNodes();
    }
}

static void mmi_msg_go_back_from_card2_cb_message(void)
{
	/* When new cb message arrival, it will add message or delete some message(no space to store it);
	 * If the cb_display.currindex changed In the cb message view screen,
	 * then back to the cb message list, the highlight will be change to 
	 * the original message index(cb_display.currindex)which the cb message view screen show.
	 */
	if (g_card2_cb_display.currindex != MAX_STORE_CB_MSG)
	{
		g_card2_cb_display.msg_hilite_index = g_card2_cb_display.currindex;
	}
	g_card2_cb_display.currindex = MAX_STORE_CB_MSG;

    GoBackHistory();
}

static void mmi_msg_end_key_from_card2_cb_message(void)
{
    g_card2_cb_display.currindex = MAX_STORE_CB_MSG;
    ExecCurrEndKeyDownHandler();
}

/* cell broadcast messages read end */

/* cell broadcast messages language begin */
static void mmi_msg_highlight_card2_cb_language(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_pre_entry_card2_cb_language, GoBackHistory);

}

static void mmi_msg_pre_entry_card2_cb_language(void)
{
    g_card2_cb_state = SMS_CB_LANGUAGE_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_language);
    mmi_msg_get_card2_cb_mode_req();
}

static void mmi_msg_get_card2_cb_mode_rsp_language(void *info)
{
    ST_MTPNP_AD_GET_CB_MODE_RSP *msgRsp = (ST_MTPNP_AD_GET_CB_MODE_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP);
    if (msgRsp->result == MTPNP_TRUE)
    {
        MTPNP_UINT8 i = 0;
        MTPNP_UINT8 total = 0;
        MTPNP_UINT8 firstByte = 0;
        MTPNP_UINT8 secondByte = 0;

        MTPNP_BOOL isCompress;
        MTPNP_BOOL isReserved;
        msg_cb_lang_enum langType;
        smsal_dcs_enum alphabetType;
        msg_cb_class_enum msgClass;

        for (i = 0; i < msgRsp->total_dcs_num; i++)
        {
            if (msgRsp->info.dcs[i] != SMSAL_CB_UNUSED_DCS)
            {
                firstByte = (msgRsp->info.dcs[i] & 0xff00) >> 8;
                secondByte = (msgRsp->info.dcs[i] & 0x00ff);
                if (firstByte == 0x00)
                {
                    DecodeCbsDcs(secondByte, 0, 0, 0, &langType, &alphabetType, &msgClass, (pBOOL*)&isCompress, (pBOOL*)&isReserved);
                }
                else
                {
                    MMICbsDecodeLang(firstByte, secondByte, &langType);
                }

                if ((langType != MMI_CBS0_LANG_UNSPECIFIED) && (langType != MMI_CBS_INVALID))
                {
                	MTPNP_UINT8 j;
					MTPNP_UINT8 is_duplicate = FALSE;
					
					for(j = 0; j < total; j++)
					{
						if(g_card2_cb_info.cblanentry[j].langType == langType)
						{
							is_duplicate = TRUE;
						}
					}

					if(is_duplicate == FALSE)
					{
						g_card2_cb_info.cblanentry[total].langType = langType;
	                    g_card2_cb_info.cblanentry[total].dcs = msgRsp->info.dcs[i];
	                    g_card2_cb_info.cblanentry[total].mask = msgRsp->info.dcs_mask[i];
	                    g_card2_cb_info.cblanentry[total].index = i;
	                    total++;
					}
                }
            }
            firstByte = 0;
            secondByte = 0;
        }
        g_card2_cb_info.totaldcs = total;
        g_card2_cb_info.dcsall = msgRsp->info.is_all_language_on;
        mmi_msg_entry_card2_cb_language();
    }
}

static void mmi_msg_entry_card2_cb_language(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT16 numItems;
    MTPNP_UINT8 i = 0;

    EntryNewScreen(SCR_MTPNP_MSG_CB_LANGUAGE, mmi_msg_exit_generic, mmi_msg_entry_card2_cb_language, MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_LANGUAGE);

    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) subMenuDataPtrs[0],
                                   (MTPNP_CHAR *) GetString((MTPNP_UINT16) STR_CB_ALL_LANGUAGES_FOR_SELECT),
                                   MAX_CB_CHNL_NAME_LENGTH * ENCODING_LENGTH);
    for (i = 0; i < g_card2_cb_info.totaldcs; i++)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) subMenuDataPtrs[i + 1],
                                       (MTPNP_CHAR *) GetString((MTPNP_UINT16)
                                                                LangEnumAndStrID[g_card2_cb_info.cblanentry[i].langType]));
        g_card2_cb_display.mask[i + 1] = g_card2_cb_info.cblanentry[i].mask;
    }
    g_card2_cb_display.mask[0] = g_card2_cb_info.dcsall;
    numItems = g_card2_cb_info.totaldcs + 1;

    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_LANGUAGE);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_LANGUAGE);

    mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_SAVE_CHANGES_QUERY, mmi_msg_select_card2_cb_language, Messages2GoBackHistory);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    ShowCategory140Screen(STR103_SCR101_CAPTION, IMG_SMS_ENTRY_SCRN_CAPTION, numItems,
                          (MTPNP_UINT8 **) subMenuDataPtrs, (MTPNP_UINT8 *) g_card2_cb_display.mask, 0, guiBuffer);
    SetLeftSoftkeyFunction(special_check_list_handle_left_softkey_up, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_select_card2_cb_language(void)
{
    MTPNP_UINT8 i = 0;

    for (i = 0; i < g_card2_cb_info.totaldcs; i++)
    {
        g_card2_cb_info.cblanentry[i].mask = g_card2_cb_display.mask[i + 1];
    }
    g_card2_cb_info.dcsall = g_card2_cb_display.mask[0];
    ClearAllKeyHandler();
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP, mmi_msg_set_card2_cb_mode_rsp);
    mmi_msg_set_card2_cb_mode_req(SMSAL_CB_DCS_MASK | SMSAL_CB_ALL_LANG);
}

/* cell broadcast messages language end */

/* cell broadcast messages channel setting begin */
static void mmi_msg_highlight_card2_cb_channel_settings(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_pre_entry_card2_cb_channel_settings, GoBackHistory);
}

static void mmi_msg_entry_card2_cb_channel_settings(void)
{
    MTPNP_UINT8 *guiBuffer = MTPNP_NULL;
    MTPNP_UINT16 numItems = 0;
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];

    EntryNewScreen(SCR_MTPNP_MSG_CB_CHANNEL_SETTINGS, mmi_msg_exit_generic, mmi_msg_entry_card2_cb_channel_settings,
                   MTPNP_NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_CHANNEL_SETTINGS);

    if (IsCard2CBChannelFull == TRUE)
    {
        mmi_frm_hide_menu_item(MITEM_MTPNP_CB_CHANNEL_ADD);
    }
    else
    {
        mmi_frm_unhide_menu_item(MITEM_MTPNP_CB_CHANNEL_ADD);
    }

    numItems = GetNumOfChild_Ext(MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS);
    GetSequenceStringIds_Ext(MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS, nStrItemList);
    SetParentHandler(MITEM_MTPNP_CB_CHANNEL_ENBL_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_CHANNEL_SETTINGS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_CHANNEL_SETTINGS);

    ShowCategory52Screen(STRING_MTPNP_CB_CHANNEL_ENBL_OPTIONS_CAPTION, IMG_SMS_ENTRY_SCRN_CAPTION, STR_GLOBAL_OK,
                         IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, numItems, nStrItemList,
                         (MTPNP_UINT16 *) gIndexIconsImageList, MTPNP_NULL, 0, 0, guiBuffer);
}

void mmi_msg_pre_entry_card2_cb_channel_bootup(void)
{
    g_card2_cb_state = SMS_CB_BOOT_UP_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_display);
    mmi_msg_get_card2_cb_mode_req();
}

/* cell broadcast messages channel setting end */

/* cell broadcast messages channel add begin */
static void mmi_msg_highlight_card2_cb_channel_add(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_pre_entry_card2_cb_channel_add, GoBackHistory);
}

static void mmi_msg_pre_entry_card2_cb_channel_add(void)
{
    g_card2_cb_state = SMS_CB_CHNL_ADD_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_display);
    mmi_msg_get_card2_cb_mode_req();
}

static void mmi_msg_add_card2_cb_channel(unsigned short mi)
{
    g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].index = g_card2_cb_display.addindex;
    g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].mask = 1;
    g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].mi = mi;
    MTPNP_OSAL_memset(g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].name, 0, ENCODING_LENGTH);
    if (GetUCS2Flag((MTPNP_CHAR *) g_card2_cb_display.name))
    {
        g_card2_cb_display.dcs = PHB_UCS2;
    }
    else
    {
        g_card2_cb_display.dcs = PHB_ASCII;
    }
    if (g_card2_cb_display.dcs == PHB_ASCII)
    {
        mmi_ucs2_to_asc((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].name,
                       (MTPNP_CHAR *) g_card2_cb_display.name);
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].name,
                                       (MTPNP_CHAR *) g_card2_cb_display.name);
    }
    g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].dcs = g_card2_cb_display.dcs;
    MTPNP_OSAL_memset(g_card2_cbNvramStruct.chnlNames[g_card2_cb_info.totalmi].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
    memcpy(g_card2_cbNvramStruct.chnlNames[g_card2_cb_info.totalmi].name,
           (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].name, MAX_CB_CHNL_NAME_LENGTH);
    g_card2_cbNvramStruct.chnlNames[g_card2_cb_info.totalmi].name_dcs = g_card2_cb_display.dcs;
    g_card2_cbNvramStruct.l4MidIndex[g_card2_cb_info.totalmi] = g_card2_cb_display.addindex;
    WriteCard2CbChnlInfoToNvram();
    g_card2_cb_info.totalmi++;
    ClearAllKeyHandler();
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP, mmi_msg_set_card2_cb_mode_rsp);
    mmi_msg_set_card2_cb_mode_req(SMSAL_CB_MI | SMSAL_CB_MI_MASK);
}

/* cell broadcast messages channel add end */

/* cell broadcast messages channel edit begin */
static void mmi_msg_highlight_card2_cb_channel_edit(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_pre_entry_card2_cb_channel_list_edit, GoBackHistory);
}

static void mmi_msg_pre_entry_card2_cb_channel_list_edit(void)
{
    g_card2_cb_state = SMS_CB_CHNL_EDIT_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_display);
    mmi_msg_get_card2_cb_mode_req();
}

static void mmi_msg_pre_entry_card2_cb_channel_edit(void)
{
    MTPNP_UINT8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];

    g_card2_cb_display.dcs = g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].dcs;
    if (g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].dcs == PHB_ASCII)
    {
        mmi_asc_to_ucs2((MTPNP_CHAR *) g_card2_cb_display.name,
                             (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name);
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_card2_cb_display.name,
                                       (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name);
    }

    MTPNP_OSAL_memset(number, 0, sizeof(number));
    sprintf((MTPNP_CHAR *) number, "%d", g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].mi);
    MTPNP_OSAL_memset(g_card2_cb_display.mi, 0, sizeof(g_card2_cb_display.mi));
    mmi_asc_n_to_ucs2((MTPNP_CHAR *) g_card2_cb_display.mi, (MTPNP_CHAR *) number, strlen((MTPNP_CHAR *) number));

    kal_prompt_trace(MOD_MMI, "[LJH]currHiliteIndex=%d, mi=%s, totalmi=%d", g_msg_cntx.currHiliteIndex,
                     number, g_card2_cb_info.totalmi);
    {
        MTPNP_UINT16 i;

        for (i = 0; i < g_card2_cb_info.totalmi; i++)
        {
            kal_prompt_trace(MOD_MMI, "[LJH]cbchnlentry[%d].name=%s, mi=%d", i,
                             g_card2_cb_info.cbchnlentry[i].name, g_card2_cb_info.cbchnlentry[i].mi);
        }
    }

    mmi_msg_entry_card2_cb_channel_edit();
}

static void mmi_msg_entry_card2_cb_channel_edit(void)
{
    MTPNP_UINT8 *guiBuffer = MTPNP_NULL;
    MTPNP_UINT8 *inputBuffer = MTPNP_NULL;
    MTPNP_UINT16 inputBufferSize = 0;
    EntryNewScreen(SCR_MTPNP_MSG_CB_CHANNEL_EDIT, mmi_msg_exit_card2_cb_channel_edit, MTPNP_NULL, MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_CHANNEL_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_MTPNP_MSG_CB_CHANNEL_EDIT, &inputBufferSize);
    InitializeCategory57Screen();
    mmi_msg_set_card2_cb_channel_inline_item();
    if (inputBuffer != MTPNP_NULL)
        SetCategory57Data(wgui_inline_items, MAX_CB_CHNL_INLINE_ITEM, inputBuffer);

    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_CHANNEL_EDIT);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_CHANNEL_EDIT);

    kal_prompt_trace(MOD_MMI, "[LJH]inputBuffer=%x", inputBuffer);
    {
        S8 string[256 + 1];
        MTPNP_UINT16 i;

        for (i = 0; i < 4; i++)
        {
            mmi_ucs2_to_asc((MTPNP_CHAR *) string, (MTPNP_CHAR *) wgui_inline_items[i].text_p);
            kal_prompt_trace(MOD_MMI, "[LJH]wgui_inline_items[%d].text_p=%s", i, string);
        }
    }

    ShowCategory57Screen(STR_CB_CHNL_EDITOR, IMG_SMS_ENTRY_SCRN_CAPTION, STR_GLOBAL_EDIT, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK, MAX_CB_CHNL_INLINE_ITEM, g_card2_cbChnlEditorIcons,
                         wgui_inline_items, 0, guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_msg_pre_save_card2_cb_channel, GoBackHistory);
}

static void mmi_msg_exit_card2_cb_channel_edit(void)
{
    history currHistory;
    MTPNP_UINT16 inputBufferSize = 0;
    S16 nHistory = 0;
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_MTPNP_MSG_CB_CHANNEL_EDIT;
    SetMessagesCurrScrnID(0);

    currHistory.scrnID = SCR_MTPNP_MSG_CB_CHANNEL_EDIT;
    CloseCategory57Screen();
    currHistory.entryFuncPtr = mmi_msg_entry_card2_cb_channel_edit;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) currHistory.inputBuffer, (MTPNP_CHAR *) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (MTPNP_UINT16) GetCategory57DataSize();
    GetCategory57Data((MTPNP_UINT8 *) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}

static void mmi_msg_set_card2_cb_channel_inline_item(void)
{
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (MTPNP_UINT8 *) GetString(STR_CB_CHNL_TITLE));
    SetInlineItemFullScreenEdit(&wgui_inline_items[1], STR_CB_CHNL_TITLE_FULL_EDIT, IMG_SMS_ENTRY_SCRN_CAPTION,
                                (MTPNP_UINT8 *) g_card2_cb_display.name, MAX_CB_CHNL_NAME_LENGTH + 1,
                                INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER |
                                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_msg_inline_generic_custom_function);
    SetInlineItemCaption(&wgui_inline_items[2], (MTPNP_UINT8 *) GetString(STR_CB_CHNL_NUMBER));
    SetInlineItemTextEdit(&wgui_inline_items[3], (MTPNP_UINT8 *) g_card2_cb_display.mi,
                          MAX_CB_CHNL_NUMBER_LENGTH + 1, INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[3]);
}

static void mmi_msg_pre_save_card2_cb_channel(void)
{
	U16 query_str_id;
	
    if (g_card2_cb_state == SMS_CB_CHNL_ADD_STATE)
    {
    	query_str_id = STR_ID_MSG_CB_ADD_CHANNEL_QUERY;
    }
    else
    {
    	query_str_id = STR_ID_MSG_SMS_SAVE_CHANGES_QUERY;	
    }

    mmi_msg_set_confirm_screen(query_str_id, mmi_msg_save_card2_cb_channel, Messages2GoBackHistory);
    mmi_msg_entry_confirm_generic();
}

static void mmi_msg_save_card2_cb_channel(void)
{
    U32 mi = 0;
    MTPNP_UINT8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH] = { 0, 0 };
    MTPNP_UINT16 length;
    MTPNP_UINT8 i = 0;

    if ((MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_card2_cb_display.mi)) == 0)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY), IMG_GLOBAL_EMPTY, 1,
                     MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        return;
    }
    MTPNP_OSAL_memset(&number, 0, (MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH);
    length =
        mmi_ucs2_n_to_asc((MTPNP_CHAR *) number, (MTPNP_CHAR *) g_card2_cb_display.mi,
                        (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_card2_cb_display.mi)) * ENCODING_LENGTH);
    number[length] = '\0';
    mi = atoi((MTPNP_CHAR *) number);
    if (mi > MAX_CB_CHNL_NUMBER)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_CB_CHNL_NUMBER_LEN_EXCEEDED), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        return;
    }
    for (i = 0; i < g_card2_cb_info.totalmi; i++)
    {
        if ((g_card2_cb_state == SMS_CB_CHNL_EDIT_STATE) && (i == g_msg_cntx.currHiliteIndex))
            continue;
        if (g_card2_cb_info.cbchnlentry[i].mi == (MTPNP_UINT16) mi)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_CB_CHNL_DUPLICATE_NUMBER_NOT_ALLOWED),
                         IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
            return;
        }
    }
    if (g_card2_cb_state == SMS_CB_CHNL_ADD_STATE)
    {
        mmi_msg_add_card2_cb_channel((MTPNP_UINT16) mi);
    }
    else
    {
        mmi_msg_edit_card2_cb_channel((MTPNP_UINT16) mi);
    }
}

static void mmi_msg_edit_card2_cb_channel(unsigned short mi)
{
    g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].mi = mi;
    MTPNP_OSAL_memset(g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
    if (GetUCS2Flag((MTPNP_CHAR *) g_card2_cb_display.name))
    {
        g_card2_cb_display.dcs = PHB_UCS2;
    }
    else
    {
        g_card2_cb_display.dcs = PHB_ASCII;
    }
    if (g_card2_cb_display.dcs == PHB_ASCII)
    {
        mmi_ucs2_n_to_asc((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name,
                        (MTPNP_CHAR *) g_card2_cb_display.name, MAX_CB_CHNL_NAME_LENGTH * ENCODING_LENGTH);
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].
                                       name, (MTPNP_CHAR *) g_card2_cb_display.name);
    }
    g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].dcs = g_card2_cb_display.dcs;
    MTPNP_OSAL_memset(g_card2_cbNvramStruct.chnlNames[g_msg_cntx.currHiliteIndex].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
    memcpy(g_card2_cbNvramStruct.chnlNames[g_msg_cntx.currHiliteIndex].name,
           (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name, MAX_CB_CHNL_NAME_LENGTH);
    g_card2_cbNvramStruct.chnlNames[g_msg_cntx.currHiliteIndex].name_dcs = g_card2_cb_display.dcs;
    WriteCard2CbChnlInfoToNvram();
    ClearAllKeyHandler();
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP, mmi_msg_set_card2_cb_mode_rsp);
    mmi_msg_set_card2_cb_mode_req(SMSAL_CB_MI);
}

/* cell broadcast messages channel edit end */

/* cell broadcast messages channel delete begin */
static void mmi_msg_highlight_card2_cb_channel_delete(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_pre_entry_card2_cb_channel_list_delete, GoBackHistory);
}

static void mmi_msg_pre_entry_card2_cb_channel_list_delete(void)
{
    g_card2_cb_state = SMS_CB_CHNL_DELETE_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_display);
    mmi_msg_get_card2_cb_mode_req();
}

static void mmi_msg_entry_card2_cb_channel_list(void)
{
    MTPNP_UINT8 *guiBuffer = MTPNP_NULL;
    S32 hiliteitem = 0;

    EntryNewScreen(SCR_MTPNP_MSG_CB_CHANNEL_LIST, mmi_msg_exit_generic, mmi_msg_entry_card2_cb_channel_list,
                   MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_CHANNEL_LIST);
    if (guiBuffer != MTPNP_NULL)
        hiliteitem = (g_msg_cntx.currHiliteIndex < g_card2_cb_info.totalmi) ? g_msg_cntx.currHiliteIndex : 0;
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_CHANNEL_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_CHANNEL_LIST);
    ShowCategory184Screen(STR_CB_CHNL_LIST, IMG_SMS_ENTRY_SCRN_CAPTION, STR_GLOBAL_OK, IMG_GLOBAL_OK,
                          STR_GLOBAL_BACK, IMG_GLOBAL_BACK, g_card2_cb_info.totalmi,
                          mmi_card2_msg_cb_channel_list_get_item, mmi_card2_msg_cb_channel_list_get_hint,
                          hiliteitem, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (g_card2_cb_state == SMS_CB_CHNL_EDIT_STATE)
        SetLeftSoftkeyFunction(mmi_msg_pre_entry_card2_cb_channel_edit, KEY_EVENT_UP);
    else
    {
        mmi_msg_set_confirm_screen(STR_ID_MSG_CB_DELETE_CHANNEL_QUERY, mmi_msg_delete_card2_cb_channel, GoBackHistory);
        SetLeftSoftkeyFunction(mmi_msg_entry_confirm_generic, KEY_EVENT_UP);
    }
}

static pBOOL mmi_card2_msg_cb_channel_list_get_item(S32 item_index, UI_string_type str_buff,
                                                    UI_image_type * img_buff_p, MTPNP_UINT8 str_img_mask)
{
    MTPNP_UINT8 number[MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1];

    if ((item_index < 0) || (item_index >= g_card2_cb_info.totalmi))
        return FALSE;

    if (strlen((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[item_index].name) == 0)
    {
        MTPNP_OSAL_memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
        sprintf((MTPNP_CHAR *) number, "%d", g_card2_cb_info.cbchnlentry[item_index].mi);
        mmi_asc_to_ucs2((MTPNP_CHAR *) str_buff, (MTPNP_CHAR *) number);
    }
    else
    {
        if (g_card2_cb_info.cbchnlentry[item_index].dcs == PHB_ASCII)
        {
            mmi_asc_to_ucs2((MTPNP_CHAR *) str_buff, (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[item_index].name);
        }
        else
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff,
                                           (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[item_index].name);
        }
    }

    *img_buff_p = get_image(IMG_CB_CHNL_TITLE);
    return TRUE;
}

static S32 mmi_card2_msg_cb_channel_list_get_hint(S32 item_index, UI_string_type * hint_array)
{
    MTPNP_UINT8 number[MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1];
    if (strlen((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[item_index].name) == 0)
        return 0;

    MTPNP_OSAL_memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
    sprintf((MTPNP_CHAR *) number, "%d", g_card2_cb_info.cbchnlentry[item_index].mi);
    mmi_asc_n_to_ucs2((MTPNP_CHAR *) hint_array[0], (MTPNP_CHAR *) number, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
    return 1;
}

static void mmi_msg_delete_card2_cb_channel(void)
{
    MTPNP_UINT8 i = 0;

    for (i = (g_msg_cntx.currHiliteIndex + 1); i < g_card2_cb_info.totalmi; i++)
    {
        memcpy(&g_card2_cb_info.cbchnlentry[i - 1], &g_card2_cb_info.cbchnlentry[i], sizeof(msg_cb_channel_struct));
    }
    g_card2_cb_info.totalmi--;
    g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].mi = SMSAL_CB_UNUSED_CBMI;
    g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].mask = 0;
    MTPNP_OSAL_memset(g_card2_cb_info.cbchnlentry[g_card2_cb_info.totalmi].name, 0, MAX_CB_CHNL_NAME_LENGTH);
    MTPNP_OSAL_memset(&g_card2_cbNvramStruct, 0xff, sizeof(msg_cb_channel_nvram_struct));
    for (i = 0; i < g_card2_cb_info.totalmi; i++)
    {
        g_card2_cbNvramStruct.l4MidIndex[i] = g_card2_cb_info.cbchnlentry[i].index;
        g_card2_cbNvramStruct.chnlNames[i].name_dcs = g_card2_cb_info.cbchnlentry[i].dcs;
        memcpy((MTPNP_CHAR *) g_card2_cbNvramStruct.chnlNames[i].name,
               (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name, MAX_CB_CHNL_NAME_LENGTH + 1);
    }
    WriteCard2CbChnlInfoToNvram();
    ClearAllKeyHandler();
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP, mmi_msg_set_card2_cb_mode_rsp);
    mmi_msg_set_card2_cb_mode_req(SMSAL_CB_MI | SMSAL_CB_MI_MASK);
}

/* cell broadcast messages channel delete end */

/* cell broadcast messages channel select begin */
static void mmi_msg_highlight_card2_cb_channel_select(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_pre_entry_card2_cb_channel_select, GoBackHistory);
}

static void mmi_msg_pre_entry_card2_cb_channel_select(void)
{
    g_card2_cb_state = SMS_CB_CHNL_SELECT_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_display);
    mmi_msg_get_card2_cb_mode_req();
}

static void mmi_msg_entry_card2_cb_channel_select(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT16 numItems;
    MTPNP_UINT8 i = 0;
    MTPNP_UINT8 selectall = MTPNP_TRUE;
    MTPNP_UINT8 number[MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1];

    EntryNewScreen(SCR_MTPNP_MSG_CB_CHANNEL_LIST, mmi_msg_exit_generic, mmi_msg_entry_card2_cb_channel_select,
                   MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_CB_CHANNEL_LIST);

    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) subMenuDataPtrs[0],
                                   (MTPNP_CHAR *) GetString((MTPNP_UINT16) STR_CB_ALL_CHANNELS_FOR_SELECT),
                                   MAX_CB_CHNL_NAME_LENGTH * ENCODING_LENGTH);
    for (i = 0; i < g_card2_cb_info.totalmi; i++)
    {
        if (strlen((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name) == 0)
        {
            MTPNP_OSAL_memset(number, 0, sizeof(number));
            sprintf((MTPNP_CHAR *) number, "%d", g_card2_cb_info.cbchnlentry[i].mi);
            mmi_asc_to_ucs2((MTPNP_CHAR *) subMenuDataPtrs[i + 1], (MTPNP_CHAR *) number);
        }
        else
        {
            if (g_card2_cb_info.cbchnlentry[i].dcs == PHB_ASCII)
                mmi_asc_to_ucs2((MTPNP_CHAR *) subMenuDataPtrs[i + 1],
                                     (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name);
            else
                MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) subMenuDataPtrs[i + 1],
                                               (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name);
        }
        g_card2_cb_display.mask[i + 1] = g_card2_cb_info.cbchnlentry[i].mask;
        if (g_card2_cb_display.mask[i + 1] == 0)
            selectall = MTPNP_FALSE;
    }

    g_card2_cb_display.mask[0] = selectall;
    numItems = g_card2_cb_info.totalmi + 1;

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_CHANNEL_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_CB_CHANNEL_LIST);

    mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_SAVE_CHANGES_QUERY, mmi_msg_select_card2_cb_channel, Messages2GoBackHistory);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    ShowCategory140Screen(STR_CB_SELECT_CHNL, IMG_SMS_ENTRY_SCRN_CAPTION, numItems,
                          (MTPNP_UINT8 **) subMenuDataPtrs, (MTPNP_UINT8 *) g_card2_cb_display.mask, 0, guiBuffer);
    SetLeftSoftkeyFunction(special_check_list_handle_left_softkey_up, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_select_card2_cb_channel(void)
{
    MTPNP_UINT8 i = 0;
    for (i = 0; i < g_card2_cb_info.totalmi; i++)
        g_card2_cb_info.cbchnlentry[i].mask = g_card2_cb_display.mask[i + 1];
    ClearAllKeyHandler();
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_CB_MODE_RSP, mmi_msg_set_card2_cb_mode_rsp);
    mmi_msg_set_card2_cb_mode_req(SMSAL_CB_MI_MASK);
}

/* cell broadcast messages channel select end */

/* cell broadcast messages new ind begin */
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
static MTPNP_UINT8 *mmi_msg_get_card2_new_cb_ind_string(void)
{
    MTPNP_UINT8 i = 0;
    MTPNP_UINT8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];
    static S8 temp[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];

    MTPNP_OSAL_memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
    for (i = 0; i < g_card2_cb_info.totalmi; i++)
    {
        if ((g_card2_cb_info.cbchnlentry[i].mi == g_card2_cbMsgInfo.MsgMI[g_card2_cbMsgIndex.currCBIndex])
            && (strlen((MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name) > 0))
            break;
    }
    if (i < g_card2_cb_info.totalmi)
    {
        if (g_card2_cb_info.cbchnlentry[i].dcs == PHB_ASCII)
        {
            mmi_asc_to_ucs2(temp, (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name);
        }
        else
        {
            MTPNP_PFAL_Unicode_String_Copy(temp, (MTPNP_CHAR *) g_card2_cb_info.cbchnlentry[i].name);
        }
    }
    else
    {
        sprintf((MTPNP_CHAR *) number, "%d", g_card2_cbMsgInfo.MsgMI[g_card2_cbMsgIndex.currCBIndex]);
        mmi_asc_to_ucs2(temp, (MTPNP_CHAR *) number);
    }
    return (MTPNP_UINT8 *) temp;
}

static void mmi_msg_entry_card2_new_cb_immediate_ind(void)
{
    EntryNewScreen(SCR_MTPNP_MSG_CB_MESSAGE_IDLE, mmi_msg_exit_generic, MTPNP_NULL, MTPNP_NULL);

    if (!IsKeyPadLockState())
    {
		mmi_card2_msg_cb_read_content_for_display(g_card2_cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, TRUE);

        SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_MESSAGE_IDLE);
        GetCurrEndKeyDownHandler();
        ShowCategory74Screen(
            STRING_MTPNP_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_DELETE,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) g_card2_dispCBMessage,
            (S32) g_card2_dispCBLength,
            NULL);
        SetLeftSoftkeyFunction(mmi_card2_msg_pre_delete_new_cb_message, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_card2_msg_go_back_from_new_cb_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_card2_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_card2_msg_pre_entry_cb_idle_use_number, KEY_SEND, KEY_EVENT_UP);
    }
    else
    {
		mmi_card2_msg_cb_read_content_for_display(g_card2_cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, FALSE);

        ShowCategory74Screen(
            STRING_MTPNP_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) g_card2_dispCBMessage,
            (S32) g_card2_dispCBLength,
            NULL);
        /* prevent category scrolling */
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
}

static void mmi_msg_entry_card2_new_cb_normal_ind(void)
{
    EntryNewScreen(SCR_MTPNP_MSG_CB_MESSAGE_IND, mmi_msg_exit_generic, MTPNP_NULL, MTPNP_NULL);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_MESSAGE_IND);
    GetCurrEndKeyDownHandler();

    if (!IsKeyPadLockState())
    {
        ShowCategory154Screen(0, 0, STR_SCR6035_LSK, IMG_SMS_COMMON_NOIMAGE, STR_GLOBAL_BACK,
                              IMG_SMS_COMMON_NOIMAGE, (MTPNP_UINT8 *) GetString(STRING_MTPNP_NEW_SLAVE_MESSAGE_FROM_ID),
                              (MTPNP_UINT8 *) mmi_msg_get_card2_new_cb_ind_string(),
                              IMG_NEW_MESSAGE_NOTIFICATION_MSG, MTPNP_NULL);
        SetRightSoftkeyFunction(mmi_card2_msg_go_back_from_new_cb_ind, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_msg_entry_card2_new_cb_immediate_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_card2_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        ShowCategory154Screen(
        	0,
        	0,
        	g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (MTPNP_UINT8 *) GetString(STRING_MTPNP_NEW_SLAVE_MESSAGE_FROM_ID),
            (MTPNP_UINT8 *) mmi_msg_get_card2_new_cb_ind_string(),
            IMG_NEW_MESSAGE_NOTIFICATION_MSG,
            MTPNP_NULL);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
}

void mmi_msg_entry_card2_new_cb_ind(void)
{
    if (g_card2_cb_display.immediate[g_card2_cbMsgIndex.currCBIndex] == MTPNP_TRUE)
        mmi_msg_entry_card2_new_cb_immediate_ind();
    else if (GetMessagesCurrScrnID() != SCR_MTPNP_MSG_CB_MESSAGE_IDLE)
        mmi_msg_entry_card2_new_cb_normal_ind();
}

#else
void mmi_msg_entry_card2_new_cb_ind(void)
{
	EntryNewScreen(SCR_MTPNP_MSG_CB_MESSAGE_IDLE, mmi_msg_exit_generic, MTPNP_NULL, MTPNP_NULL);

    if (IsKeyPadLockState() == 0)
    {
		mmi_msg_cb_read_content_for_display(g_card2_cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, TRUE);

        SetMessagesCurrScrnID(SCR_MTPNP_MSG_CB_MESSAGE_IDLE);
        GetCurrEndKeyDownHandler();
        ShowCategory74Screen(
            STRING_MTPNP_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_DELETE,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) g_card2_dispCBMessage,
            (S32) g_card2_dispCBLength,
            NULL);
        SetLeftSoftkeyFunction(mmi_card2_msg_pre_delete_new_cb_message, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_card2_msg_go_back_from_new_cb_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_card2_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_card2_msg_pre_entry_cb_idle_use_number, KEY_SEND, KEY_EVENT_UP);
    }
    else
    {
		mmi_msg_cb_read_content_for_display(g_card2_cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, FALSE);

        ShowCategory74Screen(
            STRING_MTPNP_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) g_card2_dispCBMessage,
            (S32) g_card2_dispCBLength,
            NULL);
        /* prevent category scrolling */
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
}
#endif

static void mmi_card2_msg_delete_new_cb_message(void)
{
    DeleteCard2CBMessage((MTPNP_UINT8)g_card2_cbMsgIndex.currCBIndex);
    WriteCard2CBMessageInfoToNvram();

    DisplayPopup(
        (PU8) GetString(STR_MESSAGES_DELETED_ID),
        IMG_GLOBAL_ACTIVATED,
        1,
        MESSAGES_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE);

	DeleteScreenIfPresent(SCR_MTPNP_MSG_CB_MESSAGE_IDLE);
    g_card2_cb_display.currindex = MAX_STORE_CB_MSG;
}

static void mmi_card2_msg_go_back_from_new_cb_ind(void)
{
	memset(g_card2_cb_display.unread, 0, MAX_STORE_CB_MSG);
	if (g_card2_cbMsgIndex.pCBMsgContent != NULL)
	{
		OslMfree(g_card2_cbMsgIndex.pCBMsgContent);
		g_card2_cbMsgIndex.pCBMsgContent = NULL;
		g_card2_cbMsgIndex.content_state = MMI_CB_CONTENT_NONE;
	}

    GoBackHistory();
}

static void mmi_card2_msg_end_key_from_new_cb_ind(void)
{
    memset(&g_card2_cb_display.unread, 0, MAX_STORE_CB_MSG);

	if (g_card2_cbMsgIndex.pCBMsgContent != NULL)
	{
		OslMfree(g_card2_cbMsgIndex.pCBMsgContent);
		g_card2_cbMsgIndex.pCBMsgContent = NULL;
		g_card2_cbMsgIndex.content_state = MMI_CB_CONTENT_NONE;
	}

    ExecCurrEndKeyDownHandler();
}

static void mmi_card2_msg_handle_new_cb_ind(void *info)
{
    ST_MTPNP_AD_CB_MSG_IND *CbsMsg = (ST_MTPNP_AD_CB_MSG_IND *) info;
    MTPNP_UINT8 i = 0;
    MTPNP_UINT8 deleteIndex = 0;
    MTPNP_UINT16 inCBMI = SMS_CB_UNUSED_CBMI;
    MTPNP_UINT8 inCBDCS = 0;
    MTPNP_UINT8 inCBPage = 0;
    MTPNP_UINT8 currCBPageTotal = 0;
	MTPNP_BOOL is_immediate_mode = MMI_FALSE;

    if (g_card2_IsCBMessageReadOperRequired)
    {
        g_card2_IsCBMessageReadOperRequired = MTPNP_FALSE;
        ReadCard2CBMessageInfoFromNvram();
    }
    inCBMI = CbsMsg->mi;
    inCBDCS = CbsMsg->dcs;
    inCBPage = ((CbsMsg->msg_length) / NVRAM_SMS_CB_SMS_PAGE_SIZE);
    if (((CbsMsg->msg_length) % NVRAM_SMS_CB_SMS_PAGE_SIZE) != 0)
    {
        inCBPage++;
	}

    inCBPage = (inCBPage > MAX_CB_MSG_PAGE) ? MAX_CB_MSG_PAGE : inCBPage;
	
    for (i = 0; i < g_card2_cbMsgIndex.currCBTotal; i++)
    {
        currCBPageTotal += g_card2_cbMsgInfo.MsgPage[i];
    }

	if ((CbsMsg->sn & 0xc000) == 0)
    {
		is_immediate_mode = MMI_TRUE;

    }
	
	if (((currCBPageTotal + inCBPage) <= NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL))
	{
		if (g_card2_cbMsgIndex.currCBTotal == MAX_STORE_CB_MSG)
		{
			for (deleteIndex = (MAX_STORE_CB_MSG - 1); ; deleteIndex--)
			{
				if (deleteIndex != g_card2_cb_display.currindex)
				{
					break;
				}

				if (deleteIndex == 0)
				{
					break;
				}
			}

            DeleteCard2CBMessage(deleteIndex);
        }
	}
	else
	{
		U8 curr_total_message = g_card2_cbMsgIndex.currCBTotal;

		/* Remove the oldest one */
		deleteIndex = curr_total_message - 1;
        for (i = 0; i < curr_total_message; i++)
        {
			if (deleteIndex == g_card2_cb_display.currindex)
			{
				deleteIndex--;
			}
			else
			{
				/* Note: cbMsgIndex.currCBTotal will decrement when delete a CB messaeg */
				currCBPageTotal -= DeleteCard2CBMessage(deleteIndex);
				deleteIndex--;

				if ((currCBPageTotal + inCBPage) <= NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL)
				{
					break;
				}
			}
        }
    }

    AddCard2CBMessage(inCBMI, inCBDCS, inCBPage, CbsMsg->msg_data, CbsMsg->msg_length);

    if (is_immediate_mode == MMI_TRUE)
    {
        g_card2_cb_display.immediate[0] = TRUE;
    }

    mmi_card2_msg_new_cb_ind();
}

static void mmi_card2_msg_new_cb_ind(void)
{
    TurnOnBacklight(1);

	g_card2_cbMsgIndex.content_state = MMI_CB_CONTENT_FOR_NEW_POPUP_IND;
    if (IsMMIInIdleState() || GetMessagesCurrScrnID() == SCR_MTPNP_MSG_CB_MESSAGE_IDLE ||
        GetMessagesCurrScrnID() == SCR_MTPNP_MSG_CB_MESSAGE_IND)
    {
        ClearKeyEvents();

        if (IsKeyPadLockState())
        {
            EntryIdleScreen();
        }
        else
        {
        #ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
            if (g_card2_cb_display.immediate[0] == TRUE)
            {
                g_card2_cbMsgIndex.currCBIndex = 0;
            	mmi_msg_entry_card2_new_cb_ind();
            }
            else if (GetMessagesCurrScrnID() != SCR_MTPNP_MSG_CB_MESSAGE_IDLE)
            {
                g_card2_cbMsgIndex.currCBIndex = 0;
            	mmi_msg_entry_card2_new_cb_ind();
            }
        #else /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */ 
            g_card2_cbMsgIndex.currCBIndex = 0;
            mmi_msg_entry_card2_new_cb_ind();
        #endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
        }
    }
    else if (GetMessagesCurrScrnID() == SCR_MTPNP_MSG_CB_MESSAGE_LIST)
    {
        mmi_msg_entry_card2_cb_read_message();
        DeleteScreenIfPresent(SCR_MTPNP_MSG_CB_MESSAGE_LIST);
    }
    WriteCard2CBMessageInfoToNvram();
}

static void ReadCard2CBMessageInfoFromNvram(void)
{
    S16 error = 0;
    S8 i = 0;

    if (ReadRecord(NVRAM_EF_CARD2_CB_SMS_INFO_LID, 1, &g_card2_cbMsgInfo, NVRAM_SMS_CB_SMS_INFO_SIZE, &error) < 0)
    {
    }

	for (i = 0; i < MAX_STORE_CB_MSG; i++)
	{
		if (g_card2_cbMsgInfo.MsgPage[i] == 0)
		{
			break;
		}
	}
	g_card2_cbMsgIndex.currCBTotal = i;
}

static void WriteCard2CBMessageInfoToNvram(void)
{
    S16 error = 0;
	
    if (WriteRecord(NVRAM_EF_CARD2_CB_SMS_INFO_LID, 1, &g_card2_cbMsgInfo, NVRAM_SMS_CB_SMS_INFO_SIZE,
                    &error) != NVRAM_SMS_CB_SMS_INFO_SIZE)
    {
    }
}

static void AddCard2CBMessage(unsigned short cbMI, MTPNP_UINT8 cbDCS, MTPNP_UINT8 cbPage, MTPNP_UINT8 * cbMsg,
                              unsigned short totalLen)
{
    MTPNP_INT16 error = 0;
	msg_cb_lang_enum langType;
	smsal_dcs_enum alphabetType;
	msg_cb_class_enum msgClass;
	MTPNP_BOOL isCompress;
	MTPNP_BOOL isReserved;
	MTPNP_UINT8 curr_total_page = 0;
	MTPNP_UINT8 i;
	MTPNP_UINT8* page_pointer;

	MMI_ASSERT(g_card2_cbMsgIndex.currCBTotal < MAX_STORE_CB_MSG)
	
	if (g_card2_cbMsgIndex.pCBMsgContent != NULL)
	{
		MTPNP_OSAL_memfree(g_card2_cbMsgIndex.pCBMsgContent);
	}
	g_card2_cbMsgIndex.pCBMsgContent = MTPNP_OSAL_malloc(cbPage * NVRAM_SMS_CB_SMS_PAGE_SIZE);

	memcpy(g_card2_cbMsgIndex.pCBMsgContent, cbMsg, totalLen);
	
    DecodeCbsDcs(
        cbDCS,
        cbMsg[0],
        cbMsg[1],
        cbMsg[2],
        &langType,
        &alphabetType,
        &msgClass,
        (pBOOL*)&isCompress,
        (pBOOL*)&isReserved);

    switch (alphabetType)
    {
        case SMSAL_DEFAULT_DCS:
        case SMSAL_RESERVED_DCS:
            MTPNP_OSAL_memset(
                g_card2_cbMsgIndex.pCBMsgContent + totalLen,
                0x0D,
                cbPage * NVRAM_SMS_CB_SMS_PAGE_SIZE - totalLen);
            break;
			
        case SMSAL_8BIT_DCS:
        case SMSAL_UCS2_DCS:
            MTPNP_OSAL_memset(
                g_card2_cbMsgIndex.pCBMsgContent + totalLen,
                0x00,
                cbPage * NVRAM_SMS_CB_SMS_PAGE_SIZE - totalLen);
            break;
    }

	if (g_card2_cbMsgIndex.currCBTotal > 0)
	{
		MTPNP_UINT8 dest_page = 0;
		MTPNP_UINT8 scr_page = 0;

		for (i = 0; i < g_card2_cbMsgIndex.currCBTotal; i++)
		{
			curr_total_page += g_card2_cbMsgInfo.MsgPage[i];
		}

		dest_page = curr_total_page + cbPage;
		if ((curr_total_page > 0) && (dest_page <= NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL))
		{
			MTPNP_UINT8 *page_buff;
			
			page_buff = MTPNP_OSAL_malloc(NVRAM_SMS_CB_SMS_PAGE_SIZE);
			
			scr_page = curr_total_page;

			/* Note: if wanted to handle the index = 0 page, the read or write record is (index + 1) */
			for(i = 0; i < curr_total_page; i++)
			{
		        if (ReadRecord(NVRAM_EF_CARD2_CB_SMS_LID, scr_page, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) < 0)
		        {
		        }

		        if (WriteRecord(NVRAM_EF_CARD2_CB_SMS_LID, dest_page, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
		            NVRAM_SMS_CB_SMS_PAGE_SIZE)
		        {
				}
				scr_page--;
				dest_page--;
			}
			MTPNP_OSAL_memfree(page_buff);
		}
		
		for (i = g_card2_cbMsgIndex.currCBTotal - 1; ; i--)
		{
            g_card2_cbMsgInfo.MsgDCS[i + 1] = g_card2_cbMsgInfo.MsgDCS[i];
            g_card2_cbMsgInfo.MsgPage[i + 1] = g_card2_cbMsgInfo.MsgPage[i];
            g_card2_cbMsgInfo.MsgMI[i + 1] = g_card2_cbMsgInfo.MsgMI[i];

			g_card2_cb_display.unread[i + 1] = g_card2_cb_display.unread[i];
			g_card2_cb_display.immediate[i + 1] = g_card2_cb_display.immediate[i];

			if (i == 0)
			{
				break;
			}
		}
	}

	page_pointer = g_card2_cbMsgIndex.pCBMsgContent;

    for (i = 0; (i < cbPage) && (i < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); i++)
    {
        MTPNP_UINT16 index = i + 1;

        if (WriteRecord(NVRAM_EF_CARD2_CB_SMS_LID, index, page_pointer, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
            NVRAM_SMS_CB_SMS_PAGE_SIZE)
        {
		}
		page_pointer += NVRAM_SMS_CB_SMS_PAGE_SIZE;
	}
    g_card2_cbMsgInfo.MsgDCS[0] = cbDCS;
    g_card2_cbMsgInfo.MsgPage[0] = cbPage;
    g_card2_cbMsgInfo.MsgMI[0] = cbMI;

	g_card2_cb_display.unread[0] = TRUE;
	g_card2_cb_display.immediate[0] = FALSE;

    g_card2_cbMsgIndex.currCBTotal++;

	if (g_card2_cbMsgIndex.currCBIndex != MAX_STORE_CB_MSG)
	{
		g_card2_cbMsgIndex.currCBIndex++;
	}

	if (g_card2_cb_display.currindex != MAX_STORE_CB_MSG)
	{
		g_card2_cb_display.currindex++;
	}

	if ((GetMessagesCurrScrnID() == SCR_MTPNP_MSG_CB_MESSAGE_LIST) &&
		(g_card2_cb_display.msg_hilite_index < (MAX_STORE_CB_MSG - 1)))
	{
		g_card2_cb_display.msg_hilite_index++;
	}
}

static MTPNP_UINT8 DeleteCard2CBMessage(MTPNP_UINT8 delete_index)
{
    MTPNP_INT16 error = 0;
    MTPNP_UINT8 i = 0;
	MTPNP_UINT8 *page_buff;
    MTPNP_UINT8 delete_page = g_card2_cbMsgInfo.MsgPage[delete_index];
	MTPNP_UINT8 dest_page = 0;
	MTPNP_UINT8 scr_page = 0;
	MTPNP_UINT8 move_page = 0;


	MMI_ASSERT(delete_index < g_card2_cbMsgIndex.currCBTotal);

	page_buff = MTPNP_OSAL_malloc(NVRAM_SMS_CB_SMS_PAGE_SIZE);

	for(i = 0; i < delete_index; i++)
	{
		dest_page += g_card2_cbMsgInfo.MsgPage[i];
	}

	g_card2_cbMsgIndex.currCBTotal--;
	if (delete_index < g_card2_cbMsgIndex.currCBTotal)
    {
    	scr_page = dest_page;
    	for (i = delete_index; i < g_card2_cbMsgIndex.currCBTotal; i++)
    	{
    		MTPNP_UINT16 j;
	
			scr_page += g_card2_cbMsgInfo.MsgPage[i];
			move_page = g_card2_cbMsgInfo.MsgPage[i + 1];
			
	        for (j = scr_page; j < (scr_page + move_page) && (j < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); j++)
	        {
	            MTPNP_UINT16 scr_index = j + 1;
				MTPNP_UINT16 dest_index = dest_page + 1;

	            if (ReadRecord(NVRAM_EF_CARD2_CB_SMS_LID, scr_index, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) < 0)
	            {
	            }

	            if (WriteRecord(NVRAM_EF_CARD2_CB_SMS_LID, dest_index, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
	                NVRAM_SMS_CB_SMS_PAGE_SIZE)
	            {
				}
				dest_page++;
	        }
			
            g_card2_cbMsgInfo.MsgDCS[i] = g_card2_cbMsgInfo.MsgDCS[i + 1];
            g_card2_cbMsgInfo.MsgPage[i] = g_card2_cbMsgInfo.MsgPage[i + 1];
            g_card2_cbMsgInfo.MsgMI[i] = g_card2_cbMsgInfo.MsgMI[i + 1];
			
			g_card2_cb_display.immediate[i] = g_card2_cb_display.immediate[i + 1];
			g_card2_cb_display.unread[i] = g_card2_cb_display.unread[i + 1];
    	}
    }

	/* reset the unused nvram space (Size = the delete cb message space size) */
	MTPNP_OSAL_memset(page_buff, 0, NVRAM_SMS_CB_SMS_PAGE_SIZE);
    for (i = dest_page; (i < (dest_page + delete_page)) && (i < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); i++)
    {
        MTPNP_UINT16 reset_index = i + 1;

        if (WriteRecord(NVRAM_EF_CARD2_CB_SMS_LID, reset_index, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
            NVRAM_SMS_CB_SMS_PAGE_SIZE)
        {
		}
    }
	MTPNP_OSAL_memfree(page_buff);

	/* reset the last cb message info */
    g_card2_cbMsgInfo.MsgDCS[g_card2_cbMsgIndex.currCBTotal] = 0;
    g_card2_cbMsgInfo.MsgPage[g_card2_cbMsgIndex.currCBTotal] = 0;
    g_card2_cbMsgInfo.MsgMI[g_card2_cbMsgIndex.currCBTotal] = SMS_CB_UNUSED_CBMI;

	/* reset the last cb message diplay info */
	g_card2_cb_display.immediate[g_card2_cbMsgIndex.currCBTotal] = FALSE;
	g_card2_cb_display.unread[g_card2_cbMsgIndex.currCBTotal] = FALSE;

	if (g_card2_cbMsgIndex.currCBIndex != MAX_STORE_CB_MSG)
	{
		if (delete_index == g_card2_cbMsgIndex.currCBIndex)
		{
			g_card2_cbMsgIndex.currCBIndex = MAX_STORE_CB_MSG;
		}
		else if (delete_index < g_card2_cbMsgIndex.currCBIndex)
		{
			g_card2_cbMsgIndex.currCBIndex--;
		}
	}

	if (g_card2_cb_display.currindex != MAX_STORE_CB_MSG)
	{
		if (delete_index == g_card2_cb_display.currindex)
		{
			g_card2_cb_display.currindex = MAX_STORE_CB_MSG;
		}
		else if (delete_index < g_card2_cb_display.currindex)
		{
			g_card2_cb_display.currindex--;
		}
	}

	if (GetMessagesCurrScrnID() == SCR_MTPNP_MSG_CB_MESSAGE_LIST)
	{
		if ((delete_index < g_card2_cb_display.msg_hilite_index) || 
			(g_card2_cb_display.msg_hilite_index == (U8)g_card2_cbMsgIndex.currCBTotal))
		{
			g_card2_cb_display.msg_hilite_index--;
		}
	}

    return delete_page;
}

static void ReadCard2CBMessageContent(PU32 outLen, MTPNP_UINT8 * msgData, MTPNP_UINT16 msgLength, MTPNP_UINT8 dcs)
{
    msg_cb_lang_enum langType;
    smsal_dcs_enum alphabetType;
    msg_cb_class_enum msgClass;
    MTPNP_BOOL isCompress;
    MTPNP_BOOL isReserved;
    MTPNP_UINT8 skipChar;

    skipChar =
        DecodeCbsDcs(dcs, msgData[0], msgData[1], msgData[2], &langType, &alphabetType, &msgClass, (pBOOL*)&isCompress,
                     (pBOOL*)&isReserved);

    if (isCompress == MTPNP_TRUE || isReserved == MTPNP_TRUE)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_DOES_NOT_SUPPORT), IMG_GLOBAL_WARNING, 0,
                     MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) WARNING_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        switch (alphabetType)
        {
        case SMSAL_DEFAULT_DCS:
            ConvertCard2CBForDisplay(msgData + skipChar, (MTPNP_UINT16) (msgLength - skipChar),
                                     SMSAL_DEFAULT_DCS, outLen);
            break;
        case SMSAL_8BIT_DCS:
            ConvertCard2CBForDisplay(msgData + skipChar, (MTPNP_UINT16) (msgLength - skipChar), SMSAL_8BIT_DCS, outLen);
            break;
        case SMSAL_UCS2_DCS:
            ConvertCard2CBForDisplay(msgData + skipChar, (MTPNP_UINT16) (msgLength - skipChar), SMSAL_UCS2_DCS, outLen);
            break;
        case SMSAL_RESERVED_DCS:
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_DOES_NOT_SUPPORT), IMG_GLOBAL_WARNING, 1,
                         MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) WARNING_TONE);
            DeleteMessagesHistoryNodes();
            break;
        default:
            ConvertCard2CBForDisplay(msgData + skipChar, (MTPNP_UINT16) (msgLength - skipChar),
                                     SMSAL_DEFAULT_DCS, outLen);
            break;
        }
		mmi_msg_cb_remove_fill_bit(g_card2_dispCBMessage, *outLen);
    }
}

static void ConvertCard2CBForDisplay(MTPNP_UINT8 * data, MTPNP_UINT16 len, MTPNP_UINT8 format, U32 * outLen)
{
    MTPNP_UINT16 outLength;

    if (len > 0)
    {
        switch (format)
        {
        case (MMI_DEFAULT_DCS):
            {
                MTPNP_UINT8 *tempData;
                tempData = OslMalloc(len);;
                ConvertGSM7BitDefaultEncodingToAscii(tempData, data, len, &outLength);
                mmi_asc_n_to_ucs2((MTPNP_CHAR *) g_card2_dispCBMessage, (MTPNP_CHAR *) tempData, outLength);
                MTPNP_OSAL_memset((void *) &g_card2_dispCBMessage[outLength * ENCODING_LENGTH], 0, ENCODING_LENGTH);
                OslMfree(tempData);
                if (outLen != MTPNP_NULL)
                    *outLen = (U32) outLength *ENCODING_LENGTH + ENCODING_LENGTH;
            }
            break;

        case (MMI_8BIT_DCS):
            mmi_asc_n_to_ucs2((MTPNP_CHAR *) g_card2_dispCBMessage, (MTPNP_CHAR *) data, len);
            MTPNP_OSAL_memset((void *) &g_card2_dispCBMessage[len * ENCODING_LENGTH], 0, ENCODING_LENGTH);
            if (outLen != MTPNP_NULL)
                *outLen = len * ENCODING_LENGTH + ENCODING_LENGTH;
            break;

        case (MMI_UCS2_DCS):
            MTPNP_OSAL_memset((void *) g_card2_dispCBMessage, 0, len + 1 + ENCODING_LENGTH);
            memcpy(g_card2_dispCBMessage, data, len);
            if (outLen != MTPNP_NULL)
                *outLen = len + ENCODING_LENGTH;
            {
                MTPNP_UINT16 *tempData;
                int i;
                tempData = (MTPNP_UINT16 *) g_card2_dispCBMessage;
                for (i = 0; i < len; i += 2)
                {
                    SWAP_USHORT(tempData);
                    tempData++;
                }
            }
            break;
        }
    }
    else
    {
        MTPNP_OSAL_memset((void *) g_card2_dispCBMessage, 0, ENCODING_LENGTH);
        if (outLen != MTPNP_NULL)
            *outLen = ENCODING_LENGTH;
    }
}

static void InitCard2CBNVRAMData(void)
{
    if (g_card2_IsCBMessageReadOperRequired)
    {
        g_card2_IsCBMessageReadOperRequired = MTPNP_FALSE;
        ReadCard2CBMessageInfoFromNvram();
    }
}

static void ResetCard2CBInfoStructs(void)
{
    MTPNP_OSAL_memset(&g_card2_cbNvramStruct, 0, sizeof(msg_cb_channel_nvram_struct));
    MTPNP_OSAL_memset(&g_card2_cbMsgInfo, 0, sizeof(msg_cb_msg_info_struct));
    MTPNP_OSAL_memset(&g_card2_cbMsgIndex, 0, sizeof(msg_cb_msg_index_struct));
	g_card2_cb_display.currindex = MAX_STORE_CB_MSG;
}

static void DeInitCard2CellBroadcastApp(void)
{
    WriteCard2CBMessageInfoToNvram();
    MTPNP_OSAL_memset(&g_card2_cbNvramStruct, 0, sizeof(msg_cb_channel_nvram_struct));
    MTPNP_OSAL_memset(&g_card2_cbMsgIndex, 0, sizeof(msg_cb_msg_info_struct));
    MTPNP_OSAL_memset(&g_card2_cbMsgIndex, 0, sizeof(msg_cb_msg_index_struct));
}


U8 mmi_card2_msg_need_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_card2_cbMsgIndex.currCBTotal == 0)
    {
        return FALSE;
    }
    for (i = (g_card2_cbMsgIndex.currCBTotal - 1);; i--)
    {
        if (g_card2_cb_display.unread[i] == TRUE)
        {
            g_card2_cbMsgIndex.currCBIndex = i;
            return TRUE;
        }
        if (i == 0)
        {
            break;
        }
    }
    return FALSE;
}

static void mmi_card2_msg_pre_entry_cb_idle_use_number(void)
{
    history h;
    S16 nHistory = 0;

    h.scrnID = SCR_MTPNP_MSG_CB_MESSAGE_IDLE;
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    h.entryFuncPtr = mmi_msg_entry_card2_new_cb_immediate_ind;
#else 
    h.entryFuncPtr = mmi_msg_entry_card2_new_cb_ind;
#endif 
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);

    mmi_card2_msg_entry_cb_use_number();
}

static void mmi_card2_msg_entry_cb_use_number(void)
{
    U16 numbersCount = 0;
    U8 *guiBuffer = NULL;
    S8 number[MAX_DIGITS_SMS * ENCODING_LENGTH];

    memset((S8*) number, 0, sizeof(number));
    numbersCount = ObtainNumbersFromMessageText((S8*) number, g_card2_dispCBMessage, (U16)g_card2_dispCBLength, 0);

    if (numbersCount > 0)
    {
        EntryNewScreen(SCR_ID_MSG_CB_USE_NUMBER_LIST, mmi_msg_exit_generic, mmi_card2_msg_entry_cb_use_number, NULL);
        GetCurrEndKeyDownHandler();

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_USE_NUMBER_LIST);
        RegisterHighlightHandler(GetHiliteIndex);
        SetMessagesCurrScrnID(SCR_ID_MSG_CB_USE_NUMBER_LIST);

        ShowCategory53Screen(
            STR_USE_NUMBER_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_DIAL,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numbersCount,
            (U8 **) g_msg_cntx.numbersList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);

       	SetLeftSoftkeyFunction(mmi_msg_dial_use_number_ext, KEY_EVENT_UP);
       	SetKeyHandler(mmi_msg_dial_use_number_ext, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		MTPNP_PFAL_CC_HandleSendKeys(mmi_msg_dial_use_number,KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_card2_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NONUMBER_NOTIFICATION),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
}


static void mmi_card2_msg_cb_read_content_for_display(U8 index, U8 content_state, U8 unread_change)
{
    U8 page = g_card2_cbMsgInfo.MsgPage[index];

	/* cbMsgIndex.pCBMsgContent store content from the new arrival cb message or NVRAM */
	/* If read the cb message in the read message box, always read the content from the NVRAM; */
	if ((content_state == MMI_CB_CONTENT_FOR_READ_MESSAGE) ||
		(g_card2_cbMsgIndex.content_state != content_state))
	{
		U8 start_page = 0;
		U8 i;

		if (g_card2_cbMsgIndex.pCBMsgContent != NULL)
		{
			MTPNP_OSAL_memfree(g_card2_cbMsgIndex.pCBMsgContent);
		}
		g_card2_cbMsgIndex.pCBMsgContent = OslMalloc(page * NVRAM_SMS_CB_SMS_PAGE_SIZE);
	
		for (i = 0; i < index; i++)
		{
			start_page += g_card2_cbMsgInfo.MsgPage[i];
		}
		mmi_card2_msg_cb_read_content_from_nvram(start_page, page, g_card2_cbMsgIndex.pCBMsgContent);
	}

	if (g_card2_cbMsgIndex.pCBMsgContent != NULL)
	{
		U8 dcs = g_card2_cbMsgInfo.MsgDCS[index];
		U16 msg_len = page * NVRAM_SMS_CB_SMS_PAGE_SIZE;

		ReadCard2CBMessageContent(
			(PU32)&g_card2_dispCBLength,
			g_card2_cbMsgIndex.pCBMsgContent,
			msg_len,
			dcs);
		
		OslMfree(g_card2_cbMsgIndex.pCBMsgContent);
		g_card2_cbMsgIndex.pCBMsgContent = NULL;
		g_card2_cbMsgIndex.content_state = MMI_CB_CONTENT_NONE;
	}
	
	if (unread_change == TRUE)
	{
		if (g_card2_cb_display.unread[index] == TRUE)
		{
			g_card2_cb_display.unread[index] = FALSE;
		}
	}
}

static void mmi_card2_msg_cb_read_content_from_nvram(U8 start_page, U8 page_num, U8* buff)
{
    S16 error = 0;
	U8* page_pointer = buff;
	U8 i;

    for (i = start_page; (i < (start_page + page_num)) && (i < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); i++)
    {
        U16 scr_index = (U16)i + 1;

        if (ReadRecord(NVRAM_EF_CARD2_CB_SMS_LID, scr_index, page_pointer, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) < 0)
        {
        }
		page_pointer += NVRAM_SMS_CB_SMS_PAGE_SIZE;
    }
}


static void mmi_card2_msg_pre_delete_new_cb_message(void)
{
    history h;
    S16 nHistory = 0;

    h.scrnID = SCR_MTPNP_MSG_CB_MESSAGE_IDLE;
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    h.entryFuncPtr = mmi_msg_entry_card2_new_cb_immediate_ind;
#else /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
	h.entryFuncPtr = mmi_msg_entry_card2_new_cb_ind;
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);

	mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_DELETE_MESSAGE_QUERY, mmi_card2_msg_delete_new_cb_message, GoBackHistory);
	mmi_msg_entry_confirm_generic();
}


static void mmi_msg_pre_entry_card2_cb_message(void)
{
    g_card2_cb_display.currindex = g_card2_cb_display.msg_hilite_index;
	mmi_card2_msg_cb_read_content_for_display(g_card2_cb_display.currindex, MMI_CB_CONTENT_FOR_READ_MESSAGE, TRUE);
	mmi_msg_entry_card2_cb_message();
}


static void mmi_msg_pre_entry_card2_cb_channel_settings(void)
{
    g_card2_cb_state = SMS_CB_CHNL_SETTING_STATE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_CB_MODE_RSP, mmi_msg_get_card2_cb_mode_rsp_display);
    mmi_msg_get_card2_cb_mode_req();
}


static void mmi_card2_msg_cb_get_msg_list_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_card2_cb_display.msg_hilite_index = (U8)nIndex;
}


#endif /* __MMI_DUAL_SIM_MASTER__ */


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
#include "PhoneBookProt.h"
#include "PhoneBookDef.h"

#include "GpioInc.h"
#include "KeyBrd.h"
#include "IdleAppDef.h"
#if defined(__MMI_UCM__)
#include "UCMGProt.h"
#endif /*__MMI_UCM__*/
#include "CallManagementGprot.h"
#include "callsetup.h"
#include "nvram_user_defs.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"

#include "MTPNP_AD_master_header.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "MTPNP_PFAL_Network.h"
#include "MTPNP_PFAL_VoiceMail.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_CC.h"

#include "GlobalScrEnum.h"

/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
/* voice mail main menu begin */
static void HighlightDMVoiceMailHandler(void);
static void mmi_msg_entry_dm_voice_mail_server(void);
static void HighlightCard2VoiceMailHandler(void);
static void mmi_msg_pre_entry_card2_voice_mail_server(void);
static void FreeCard2VoiceMailData(void);
static void mmi_msg_get_card2_mailbox_list_req(void);
static void mmi_frm_sms_get_card2_mailbox_info_req(void *dummy);
static void mmi_frm_sms_get_card2_mailbox_info_rsp(void *info);
static void mmi_msg_get_card2_mailbox_list_rsp(void *mailbox, module_type mod, U16 result);
static void mmi_msg_entry_card2_voice_mail_server(void);
static pBOOL mmi_msg_card2_voice_mail_server_get_item(S32 item_index, UI_string_type str_buff,
                                                      UI_image_type * img_buff_p, U8 str_img_mask);
static S32 mmi_msg_card2_voice_mail_server_get_hint(S32 item_index, UI_string_type * hint_array);
static void mmi_msg_go_back_from_card2_voice_mail_server(void);
static void mmi_msg_end_key_from_card2_voice_mail_server(void);
static void mmi_msg_entry_card2_voice_mail_server_option(void);
/* voice mail main menu end */

/* voice mail edit&dial begin */
static void mmi_msg_highlight_card2_voice_mail_server_edit(void);
static void mmi_msg_entry_card2_voice_mail_server_edit(void);
static void mmi_msg_exit_card2_voice_mail_server_edit(void);
static void mmi_msg_card2_voice_mail_server_edit_highlight_handler(S32 index);
static void mmi_msg_set_card2_mailbox_inline_item(void);
static void mmi_msg_set_card2_mailbox_inline_item_req(void);
static void mmi_frm_sms_set_card2_mailbox_info(PsFuncPtrU16 callback, module_type mod_src, void *mailbox);
static void mmi_frm_sms_set_card2_mailbox_info_req(void *inMsg);
static void mmi_frm_sms_set_card2_mailbox_info_rsp(void *info);
static void mmi_msg_set_card2_mailbox_inline_item_rsp(void *mailboxdetail, module_type mod, U16 result);
static void mmi_msg_highlight_card2_voice_mail_server_dial(void);
static void mmi_msg_dial_card2_mailbox_address(void);
static void mmi_msg_hightlight_dial_card2_mailbox_address(void);
extern void MakeCall(PS8 strNumber);
/* voice mail edit&dial begin */

/**************************LOCAL*FUNCTION*DECLARE*END*************************/
static U8 *pCard2MailBoxName[MAX_MAILBOX_PS_SUPPORT] = { NULL, NULL };
static U8 *pCard2MailBoxNumber[MAX_MAILBOX_PS_SUPPORT] = { NULL, NULL };
static U8 psCard2MailBoxDCS[MAX_MAILBOX_PS_SUPPORT];
static msg_mailbox_edit_struct psCard2MailboxEditInfo;
static msg_mailbox_edit_struct *Card2MailboxDetail;
static U16 Card2ProfileEditStrings[MAX_PROFILE_EDIT_ITEMS];
static U16 Card2ProfileEditIcons[MAX_PROFILE_EDIT_ITEMS] = {
    IMG_SMS_PROFILE_NAME,
    IMG_SMS_PROFILE_SC,
    IMG_SMS_PROFILE_VP,
    IMG_SMS_PROFILE_MSG_TYPE
};
static BOOL is_edit_card2_voicemail_from_idle;

void MTPNP_PFAL_InitVoiceMail(void)
{
    SetHiliteHandler(MENU_MTPNP_DM_VMAIL, HighlightDMVoiceMailHandler);
    SetHiliteHandler(MENU_MTPNP_VMAIL, HighlightCard2VoiceMailHandler);
    SetHiliteHandler(MITEM_MTPNP_VM_EDIT, mmi_msg_highlight_card2_voice_mail_server_edit);
    SetHiliteHandler(MITEM_MTPNP_VM_CONNECT_TO_VOICE, mmi_msg_highlight_card2_voice_mail_server_dial);
}

/* voice mail main menu begin */
static void HighlightDMVoiceMailHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_msg_entry_dm_voice_mail_server, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_entry_dm_voice_mail_server, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_entry_dm_voice_mail_server(void)
{
	g_msg_cntx.is_voicemail_from_idle = FALSE;
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_MSG_VOICE_MAIL, NULL, mmi_msg_entry_dm_voice_mail_server, 
                         MENU_MTPNP_DM_VMAIL, STR_VMAIL_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION);
}

static void HighlightCard2VoiceMailHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_card2_voice_mail_server, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_pre_entry_card2_voice_mail_server, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_pre_entry_card2_voice_mail_server(void)
{
    FreeCard2VoiceMailData();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup((PU8) GetString(STR_VOICE_MAIL_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
        return;
    }
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup((PU8) GetString(STR_VOICE_MAIL_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
        return;
    }
    
#ifdef __MMI_DUAL_SIM_MASTER__
	if (g_msg_cntx.is_voicemail_from_idle == FALSE)
#endif
	{
    	mmi_msg_get_card2_mailbox_list_req();
	}
#ifdef __MMI_DUAL_SIM_MASTER__
	else
	{
		mmi_msg_dial_card2_mailbox_req();
	}
#endif
}

static void FreeCard2VoiceMailData(void)
{
    U8 i = 0;

    for (i = 0; i < MAX_MAILBOX_PS_SUPPORT; i++)
    {
        if (pCard2MailBoxName[i])
        {
            OslMfree(pCard2MailBoxName[i]);
            pCard2MailBoxName[i] = NULL;
        }
        if (pCard2MailBoxNumber[i])
        {
            OslMfree(pCard2MailBoxNumber[i]);
            pCard2MailBoxNumber[i] = NULL;
        }
    }
	is_edit_card2_voicemail_from_idle = FALSE;
}

static void mmi_msg_get_card2_mailbox_list_req(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_card2_mailbox_info(mmi_msg_get_card2_mailbox_list_rsp, MOD_MMI);
}

void mmi_frm_sms_get_card2_mailbox_info(PsFuncPtrU16 callback, module_type mod_src)
{
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_card2_mailbox_info_req);
}

static void mmi_frm_sms_get_card2_mailbox_info_req(void *dummy)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MAILBOX_ADDRESS_RSP,
                                      mmi_frm_sms_get_card2_mailbox_info_rsp);

    MTPNP_AD_Get_Mailbox_Info_Req();
}

static void mmi_frm_sms_get_card2_mailbox_info_rsp(void *info)
{
    ST_MTPNP_AD_GET_MAILBOX_ADDRESS_RSP *msgRsp = (ST_MTPNP_AD_GET_MAILBOX_ADDRESS_RSP *) info;
    mmi_frm_sms_mailbox_struct mailboxInfo;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 i = 0;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MAILBOX_ADDRESS_RSP);
    if (msgRsp->result == TRUE)
    {
        U16 outlen = 0;
        mailboxInfo.mailboxNumber = msgRsp->mailbox_num;
        mailboxInfo.mailboxNameLength = msgRsp->alpha_length;
        for (i = 0; i < mailboxInfo.mailboxNumber; i++)
        {
            mailboxInfo.mailboxNameDcs[i] = msgRsp->mailbox_info[i].name.name_dcs;
            mailboxInfo.pMailBoxName[i] = CovertStringForPlatform(msgRsp->mailbox_info[i].name.name,
                                                                  msgRsp->mailbox_info[i].name.name_length,
                                                                  msgRsp->mailbox_info[i].name.name_dcs, &outlen);
            mailboxInfo.pMailBoxNumber[i] =
                ConvertL4NumberStructToDisplay(msgRsp->mailbox_info[i].number_info.number,
                                               msgRsp->mailbox_info[i].number_info.length,
                                               msgRsp->mailbox_info[i].number_info.type);
        }
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void *) &mailboxInfo, result);
    for (i = 0; i < mailboxInfo.mailboxNumber; i++)
    {
        if (mailboxInfo.pMailBoxName[i])
            OslMfree(mailboxInfo.pMailBoxName[i]);
        if (mailboxInfo.pMailBoxNumber[i])
            OslMfree(mailboxInfo.pMailBoxNumber[i]);
    }
}

static void mmi_msg_get_card2_mailbox_list_rsp(void *mailbox, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_frm_sms_mailbox_struct *mailboxlist = (mmi_frm_sms_mailbox_struct *) mailbox;
        U8 i = 0;
        if (mailboxlist->mailboxNumber == 0)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT,
                         (U8) EMPTY_LIST_TONE);
        }
        else
        {
            psCard2MailboxEditInfo.malboxNameLength = mailboxlist->mailboxNameLength;
            for (i = 0; i < mailboxlist->mailboxNumber; i++)
            {
                pCard2MailBoxName[i] = OslMalloc((MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
                MTPNP_PFAL_Unicode_String_Copy((S8 *) pCard2MailBoxName[i], (S8 *) mailboxlist->pMailBoxName[i]);

                pCard2MailBoxNumber[i] = OslMalloc((MAX_CC_ADDR_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
                MTPNP_PFAL_Unicode_String_Copy((S8 *) pCard2MailBoxNumber[i], (S8 *) mailboxlist->pMailBoxNumber[i]);

                psCard2MailBoxDCS[i] = mailboxlist->mailboxNameDcs[i];
            }
            mmi_msg_entry_card2_voice_mail_server();
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
}

static void mmi_msg_entry_card2_voice_mail_server(void)
{
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;

    EntryNewScreen(SCR_MTPNP_MSG_VOICE_MAIL_LIST, mmi_msg_exit_generic, mmi_msg_entry_card2_voice_mail_server, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_VOICE_MAIL_LIST);
    if (guiBuffer != NULL)
        hiliteitem = (g_msg_cntx.currHiliteIndex < MAX_MAILBOX_PS_SUPPORT) ? g_msg_cntx.currHiliteIndex : 0;
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_VOICE_MAIL_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_VOICE_MAIL_LIST);

    GetCurrEndKeyDownHandler();
    ShowCategory184Screen(STR_VMAIL_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
                          STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,
                          STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                          MAX_MAILBOX_PS_SUPPORT,
                          mmi_msg_card2_voice_mail_server_get_item,
                          mmi_msg_card2_voice_mail_server_get_hint, hiliteitem, guiBuffer);

    MTPNP_PFAL_CC_HandleSendKeys(mmi_msg_dial_card2_mailbox_address, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_msg_entry_card2_voice_mail_server_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_entry_card2_voice_mail_server_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_msg_go_back_from_card2_voice_mail_server, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_go_back_from_card2_voice_mail_server, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_end_key_from_card2_voice_mail_server, KEY_END, KEY_EVENT_DOWN);
}

static pBOOL mmi_msg_card2_voice_mail_server_get_item(S32 item_index, UI_string_type str_buff,
                                                      UI_image_type * img_buff_p, U8 str_img_mask)
{
    if ((item_index < 0) || (item_index >= MAX_MAILBOX_PS_SUPPORT))
        return FALSE;

    if (MTPNP_PFAL_Unicode_String_Length((S8 *) pCard2MailBoxName[item_index]) != 0)
    {
        MTPNP_PFAL_Unicode_String_Copy((S8 *) str_buff, (S8 *) pCard2MailBoxName[item_index]);
    }
    else if (MTPNP_PFAL_Unicode_String_Length((S8 *) pCard2MailBoxNumber[item_index]) != 0)
    {
        MTPNP_PFAL_Unicode_String_Copy((S8 *) str_buff, (S8 *) pCard2MailBoxNumber[item_index]);
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((S8 *) str_buff, (S8 *) GetString((U16) STR_GLOBAL_EMPTY_LIST));
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}

static S32 mmi_msg_card2_voice_mail_server_get_hint(S32 item_index, UI_string_type * hint_array)
{
    if ((MTPNP_PFAL_Unicode_String_Length((S8 *) pCard2MailBoxName[item_index]) != 0)
        && (MTPNP_PFAL_Unicode_String_Length((S8 *) pCard2MailBoxNumber[item_index]) != 0))
    {
        MTPNP_PFAL_Unicode_String_Copy((S8 *) hint_array[0], (S8 *) pCard2MailBoxNumber[item_index]);
        return 1;
    }
    else
    {
        return 0;
    }
}

static void mmi_msg_go_back_from_card2_voice_mail_server(void)
{
    FreeCard2VoiceMailData();
    GoBackHistory();
}

static void mmi_msg_end_key_from_card2_voice_mail_server(void)
{
    if (!isInCall())
    {
        FreeCard2VoiceMailData();
    }
    ExecCurrEndKeyDownHandler();
}

static void mmi_msg_entry_card2_voice_mail_server_option(void)
{
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    EntryNewScreen(SCR_MTPNP_MSG_VOICE_MAIL_OPTION, mmi_msg_exit_generic,
                   mmi_msg_entry_card2_voice_mail_server_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_VOICE_MAIL_OPTION);

    numItems = GetNumOfChild(MITEM_MTPNP_VOICE_MAIL_OPTION);
    GetSequenceStringIds(MITEM_MTPNP_VOICE_MAIL_OPTION, nStrItemList);
    SetParentHandler(MITEM_MTPNP_VOICE_MAIL_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_VOICE_MAIL_OPTION);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_VOICE_MAIL_OPTION);

    GetCurrEndKeyDownHandler();
    ShowCategory52Screen(STRING_MTPNP_VOICE_MAIL_OPTION_ID, IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         numItems, nStrItemList, (U16 *) gIndexIconsImageList, NULL, 0, 0, guiBuffer);
    SetKeyHandler(mmi_msg_end_key_from_card2_voice_mail_server, KEY_END, KEY_EVENT_DOWN);
}

/* voice mail main menu end */

/* voice mail edit&dial begin */
static void mmi_msg_highlight_card2_voice_mail_server_edit(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_entry_card2_voice_mail_server_edit, GoBackHistory);
}

static void mmi_msg_entry_card2_voice_mail_server_edit(void)
{
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize = 0;

    U8 numOfItems = MAX_MAILBOX_PS_SUPPORT;

    EntryNewScreen(SCR_MTPNP_MSG_VOICE_MAIL_EDIT, mmi_msg_exit_card2_voice_mail_server_edit, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_VOICE_MAIL_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_MTPNP_MSG_VOICE_MAIL_EDIT, &inputBufferSize);

    GetCurrEndKeyDownHandler();
    RegisterHighlightHandler(mmi_msg_card2_voice_mail_server_edit_highlight_handler);
    Card2ProfileEditStrings[0] = STR_VOICE_MAIL_NAME;
    Card2ProfileEditStrings[1] = STR_VOICE_MAIL_NUM;

	if (is_edit_card2_voicemail_from_idle == FALSE)
	{
	    psCard2MailboxEditInfo.mailboxIndex = g_msg_cntx.currHiliteIndex;
	    psCard2MailboxEditInfo.mailboxNameDcs = psCard2MailBoxDCS[psCard2MailboxEditInfo.mailboxIndex];
	}
    MTPNP_PFAL_Unicode_String_Copy((S8 *) psCard2MailboxEditInfo.mailboxName,
                                   (S8 *) pCard2MailBoxName[psCard2MailboxEditInfo.mailboxIndex]);
    MTPNP_PFAL_Unicode_String_Copy((S8 *) psCard2MailboxEditInfo.mailboxAddress,
                                   (S8 *) pCard2MailBoxNumber[psCard2MailboxEditInfo.mailboxIndex]);
    mmi_msg_set_card2_mailbox_inline_item();
    if (guiBuffer != NULL)
        SetCategory57Data(wgui_inline_items, numOfItems, inputBuffer);

    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_VOICE_MAIL_EDIT);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_VOICE_MAIL_EDIT);

    mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_set_card2_mailbox_inline_item_req, Messages2GoBackHistory);

    ShowCategory57Screen(STR_VMAIL_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_EDIT, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         numOfItems, Card2ProfileEditIcons, wgui_inline_items, 0, guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    SetKeyHandler(mmi_msg_end_key_from_card2_voice_mail_server, KEY_END, KEY_EVENT_DOWN);
}

static void mmi_msg_exit_card2_voice_mail_server_edit(void)
{
    history currHistory;
    U16 inputBufferSize = 0;
    S16 nHistory = 0;

    if (GetUCS2Flag((PS8) psCard2MailboxEditInfo.mailboxName))
    {
        psCard2MailboxEditInfo.mailboxNameDcs = PHB_UCS2;
    }
    else
    {
        psCard2MailboxEditInfo.mailboxNameDcs = PHB_ASCII;
    }
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_MTPNP_MSG_VOICE_MAIL_EDIT;
    SetMessagesCurrScrnID(0);

    currHistory.scrnID = SCR_MTPNP_MSG_VOICE_MAIL_EDIT;
    CloseCategory57Screen();
    currHistory.entryFuncPtr = mmi_msg_entry_card2_voice_mail_server_edit;
    MTPNP_PFAL_Unicode_String_Copy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8 *) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}

static void mmi_msg_card2_voice_mail_server_edit_highlight_handler(S32 index)
{
    ChangeTitleString((PU8) GetString(Card2ProfileEditStrings[index]));
    draw_title();

    if (index == 0)
    {
        if (psCard2MailboxEditInfo.malboxNameLength == 0)
        {
            ChangeLeftSoftkey(0, 0);
        }
    }
}

static void mmi_msg_set_card2_mailbox_inline_item(void)
{
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(&wgui_inline_items[0], STR_VOICE_MAIL_NAME, IMG_SMS_ENTRY_SCRN_CAPTION,
                                (PU8) psCard2MailboxEditInfo.mailboxName,
                                psCard2MailboxEditInfo.malboxNameLength + 1,
                                INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER |
                                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[0], mmi_msg_inline_generic_custom_function);
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8) psCard2MailboxEditInfo.mailboxAddress, MAX_DIGITS_SMS,
                          INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    DisableInlineItemHighlight(&wgui_inline_items[1]);
}

static void mmi_msg_set_card2_mailbox_inline_item_req(void)
{
    if (mmi_phb_op_check_valid_number((S8*)psCard2MailboxEditInfo.mailboxAddress) == FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_card2_mailbox_info(mmi_msg_set_card2_mailbox_inline_item_rsp, MOD_MMI,
                                       (void *) &psCard2MailboxEditInfo);
}

static void mmi_frm_sms_set_card2_mailbox_info(PsFuncPtrU16 callback, module_type mod_src, void *mailbox)
{
    msg_mailbox_edit_struct *data = OslMalloc(sizeof(msg_mailbox_edit_struct));
    memcpy(data, mailbox, sizeof(msg_mailbox_edit_struct));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_card2_mailbox_info_req);
}

static void mmi_frm_sms_set_card2_mailbox_info_req(void *inMsg)
{
    ST_MTPNP_AD_SET_MAILBOX_ADDRESS_REQ *msgReq;
    msg_mailbox_edit_struct *mailbox = (msg_mailbox_edit_struct *) inMsg;
    S8 mailboxAddress[MAX_DIGITS + 1];

    Card2MailboxDetail = OslMalloc(sizeof(msg_mailbox_edit_struct));
    memcpy(Card2MailboxDetail, mailbox, sizeof(msg_mailbox_edit_struct));
    msgReq = (ST_MTPNP_AD_SET_MAILBOX_ADDRESS_REQ *) OslConstructDataPtr(sizeof(*msgReq));

    if (mailbox->mailboxNameDcs == PHB_UCS2)
    {
        msgReq->name.name_dcs = MMI_PHB_UCS2;
        msgReq->name.name_length =
            ((U8) MTPNP_PFAL_Unicode_String_Length((PS8) mailbox->mailboxName)) * ENCODING_LENGTH;
        InputboxConvertDeviceEncodingToGSM((PU8) mailbox->mailboxName, msgReq->name.name, MAX_PROFILE_NAME_LEN,
                                           MMI_PHB_UCS2, 0, 1);
    }
    else
    {
        msgReq->name.name_dcs = MMI_PHB_ASCII;
        msgReq->name.name_length =
            InputboxConvertDeviceEncodingToGSM((PU8) mailbox->mailboxName, msgReq->name.name,
                                               MAX_PROFILE_NAME_LEN, MMI_PHB_ASCII, 0, 1) - 1;
    }
    memset(&msgReq->name.name[msgReq->name.name_length], 0, 1);

    memset(mailboxAddress, 0, MAX_DIGITS_SMS * ENCODING_LENGTH);
    mmi_ucs2_n_to_asc((PS8) mailboxAddress, (PS8) mailbox->mailboxAddress, MAX_DIGITS_SMS * ENCODING_LENGTH);
    msgReq->mailbox_num = mailbox->mailboxIndex;
    if (mailboxAddress[0] == '+')
    {
        msgReq->num_addr.type = CSMCC_INTERNATIONAL_ADDR;
        msgReq->num_addr.length =
            (strlen(mailboxAddress) > MAX_DIGITS_SMS) ? (MAX_DIGITS_SMS - 1) : (strlen(mailboxAddress) - 1);
        memcpy(msgReq->num_addr.number, mailboxAddress + 1, msgReq->num_addr.length);
    }
    else
    {
        msgReq->num_addr.type = CSMCC_DEFAULT_ADDR_TYPE;
        msgReq->num_addr.length =
            (strlen(mailboxAddress) > (MAX_DIGITS_SMS - 1)) ? (MAX_DIGITS_SMS - 1) : (strlen(mailboxAddress));
        memcpy(msgReq->num_addr.number, mailboxAddress, msgReq->num_addr.length);
    }
    memset(&msgReq->num_addr.number[msgReq->num_addr.length], 0, 1);

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_MAILBOX_ADDRESS_RSP,
                                      mmi_frm_sms_set_card2_mailbox_info_rsp);
    MTPNP_AD_Set_Mailbox_Address_Req(msgReq);
    OslMfree(inMsg);
    OslFreeDataPtr(msgReq);
}

static void mmi_frm_sms_set_card2_mailbox_info_rsp(void *info)
{
    ST_MTPNP_AD_SET_MAILBOX_ADDRESS_RSP *msgRsp = (ST_MTPNP_AD_SET_MAILBOX_ADDRESS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_MAILBOX_ADDRESS_RSP);

    if ((msgRsp->result) == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action(Card2MailboxDetail, result);
    OslMfree(Card2MailboxDetail);
}

static void mmi_msg_set_card2_mailbox_inline_item_rsp(void *mailboxdetail, module_type mod, U16 result)
{
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_VOICE_MAIL_OPTION);
    if (result == MMI_FRM_SMS_OK)
    {
        msg_mailbox_edit_struct *mailbox = (msg_mailbox_edit_struct *) mailboxdetail;

		if (is_edit_card2_voicemail_from_idle == FALSE)
		{
			MTPNP_PFAL_Unicode_String_Copy((S8 *) pCard2MailBoxName[mailbox->mailboxIndex], (S8 *) mailbox->mailboxName);
        	MTPNP_PFAL_Unicode_String_Copy((S8 *) pCard2MailBoxNumber[mailbox->mailboxIndex],
                                       (S8 *) mailbox->mailboxAddress);
		}
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
	if (is_edit_card2_voicemail_from_idle == TRUE)
	{
		DeleteScreenIfPresent(SCR_MTPNP_MSG_VOICE_MAIL_EDIT);
	}
	else
	{
    	DeleteMessagesHistoryNodes();
	}    
}

static void mmi_msg_highlight_card2_voice_mail_server_dial(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_hightlight_dial_card2_mailbox_address, GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_dial_card2_mailbox_address(void)
{
    if (MTPNP_PFAL_Unicode_String_Length((PS8) pCard2MailBoxNumber[g_msg_cntx.currHiliteIndex]) != 0)
    {
        MakeCall((PS8)pCard2MailBoxNumber[g_msg_cntx.currHiliteIndex]);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_VM_NO_NUMBER_TO_DIAL), IMG_GLOBAL_WARNING, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
}

static void mmi_msg_hightlight_dial_card2_mailbox_address(void)
{
    if (MTPNP_PFAL_Unicode_String_Length((PS8) pCard2MailBoxNumber[g_msg_cntx.currHiliteIndex]) != 0)
    {
        mmi_ucm_app_entry_dial_option((U8*)pCard2MailBoxNumber[g_msg_cntx.currHiliteIndex], NULL, NULL);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_VM_NO_NUMBER_TO_DIAL), IMG_GLOBAL_WARNING, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
}

static void mmi_msg_pre_entry_edit_card2_voicemail_num_from_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_edit_card2_voicemail_from_idle = TRUE;
	mmi_msg_entry_card2_voice_mail_server_edit();
}

static void mmi_msg_entry_set_card2_voicemail_number_confirm(U8 mailboxIndex, U8 mailboxNameDcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	psCard2MailboxEditInfo.mailboxIndex = mailboxIndex;
	psCard2MailboxEditInfo.mailboxNameDcs = mailboxNameDcs;
	
	mmi_msg_set_confirm_screen(STR_SMS_SET_VOICEMAIL_QUERY_ID, mmi_msg_pre_entry_edit_card2_voicemail_num_from_idle, GoBackHistory);
    mmi_msg_entry_confirm_generic();
}

static void mmi_msg_dial_card2_mailbox_rsp(void *mailbox, module_type mod, U16 result)
{
 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_number = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_frm_sms_mailbox_struct *mailboxlist = (mmi_frm_sms_mailbox_struct *) mailbox;
        U8 i = 0;
        if (mailboxlist->mailboxNumber == 0)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT,
                         (U8) EMPTY_LIST_TONE);
        }
        else
        {
        	U8 currentMailboxIndex;	
			
            psCard2MailboxEditInfo.malboxNameLength = mailboxlist->mailboxNameLength;
            for (i = 0; i < mailboxlist->mailboxNumber; i++)
            {
                pCard2MailBoxName[i] = OslMalloc((MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
                MTPNP_PFAL_Unicode_String_Copy((S8 *) pCard2MailBoxName[i], (S8 *) mailboxlist->pMailBoxName[i]);

                pCard2MailBoxNumber[i] = OslMalloc((MAX_CC_ADDR_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
                MTPNP_PFAL_Unicode_String_Copy((S8 *) pCard2MailBoxNumber[i], (S8 *) mailboxlist->pMailBoxNumber[i]);

                psCard2MailBoxDCS[i] = mailboxlist->mailboxNameDcs[i];
                if (mmi_ucs2strlen((PS8) pCard2MailBoxNumber[i]) != 0)
                {
                    is_number = MMI_TRUE;
                }
            }
            if (mailboxlist->mailboxNumber >= MAX_MAILBOX_PS_SUPPORT)
            {
                if (MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_1)
                {
					currentMailboxIndex = 0;
				}
				else
				{
					currentMailboxIndex = 1;
				}
            }
			else
			{
				currentMailboxIndex = 0;
			}
			
            if (is_number)
            {
                if (pCard2MailBoxNumber[currentMailboxIndex] != NULL &&
                    mmi_ucs2strlen((PS8) pCard2MailBoxNumber[currentMailboxIndex]) != 0)
                {                
        			mmi_ucm_app_entry_dial_option((U8*)pCard2MailBoxNumber[currentMailboxIndex], NULL, NULL);    			                   
                }
                else
                {	
                	if (mailboxlist->mailboxNumber >= MAX_MAILBOX_PS_SUPPORT)
					{
						mmi_msg_entry_set_card2_voicemail_number_confirm(currentMailboxIndex, mailboxlist->mailboxNameDcs[currentMailboxIndex]);
                	}
					else
					{
						/* Impossible case */
						MMI_ASSERT(0);     
					}
				}
            }
            else
            {
                if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_VOICE_MAIL_NOT_READY_YET),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                }
                else
                {
					mmi_msg_entry_set_card2_voicemail_number_confirm(currentMailboxIndex, mailboxlist->mailboxNameDcs[currentMailboxIndex]);
                }
            }
        }

    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
       
}


void mmi_msg_dial_card2_mailbox_req(void)
{
	FreeCard2VoiceMailData();
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    ShowCategoryDummyScreen();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_card2_mailbox_info(mmi_msg_dial_card2_mailbox_rsp, MOD_MMI);
}

/* voice mail edit&dial begin */

#endif /* __MMI_DUAL_SIM_MASTER__ */

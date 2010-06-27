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
#include "wgui_status_icons.h"
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

#include "CSP.h"
#include "FrameworkStruct.h"
#include "MainMenuDef.h"
#include "CallHistoryGProts.h"
#include "CallManagementGprot.h"
#include "CallhistoryEnum.h"
#include "MiscFunctions.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#include "PhoneBookDef.h"
#include "IdleAppProt.h"
#include "AlarmFrameworkProt.h"
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
#include "SMSFunc.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif

#include "MTPNP_AD_master_header.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "MTPNP_PFAL_Network.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_MessageSetup.h"

/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
/* message setup main menu begin */
static void mmi_msg_highlight_dm_msg_settings(void);
static void mmi_msg_entry_dm_msg_settings(void);
static void mmi_msg_highlight_card2_msg_settings(void);
static void mmi_msg_pre_entry_card2_msg_settings(void);
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
static void mmi_msg_get_card2_preferred_storage_req(void);
static void mmi_frm_sms_get_card2_preferred_storage(PsFuncPtrU16 callback, module_type mod_src);
static void mmi_frm_sms_get_card2_preferred_storage_req(void *dummy);
static void mmi_frm_sms_get_card2_preferred_storage_rsp(void *info);
static void mmi_msg_get_card2_preferred_storage_rsp(void *storage, module_type mod, U16 result);
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */
static void mmi_msg_entry_card2_msg_settings(void);
/* message setup main menu end */

/* message setup profile setting begin */
static void mmi_msg_highlight_card2_profile_settings(void);
static void mmi_msg_get_card2_profile_list_req(void);
static void mmi_frm_sms_get_card2_profile_num_req(void *dummy);
static void mmi_frm_sms_get_card2_profile_num_rsp(void *info);
static void mmi_msg_get_card2_profile_list_rsp(void *profilelist, module_type mod, U16 result);
static void mmi_frm_sms_get_card2_profile_name_req(void *inMsg);
static void mmi_frm_sms_get_card2_profile_name_rsp(void *info);
static void mmi_msg_entry_card2_profile_settings(void);
static void mmi_msg_get_card2_profile_highlight_index(S32 nIndex);
static void mmi_msg_save_card2_profile_active(void);
static void mmi_msg_set_card2_profile_active_req(U8 * index);
static void mmi_frm_sms_set_card2_profile_active(PsFuncPtrU16 callback, module_type mod_src, U8 * index);
static void mmi_msg_set_card2_profile_active_rsp(void *index, module_type mod_src, U16 result);
static void mmi_msg_get_card2_profile_inline_item_req(void);
static void mmi_frm_sms_get_card2_profile_detail(PsFuncPtrU16 callback, module_type mod_src, U8 index);
static void mmi_frm_sms_get_card2_profile_detail_req(void *inMsg);
static void mmi_frm_sms_get_card2_profile_detail_rsp(void *info);
static void mmi_msg_get_card2_profile_inline_item_rsp(void *profiledetail, module_type mod, U16 result);
static void mmi_msg_entry_card2_profile_edit(void);
static void mmi_msg_exit_card2_profile_edit(void);
static void mmi_msg_set_card2_profile_inline_item(void);
static void mmi_msg_profile_edit_card2_highlight_handler(S32 index);
static void mmi_msg_set_card2_profile_inline_item_req(void);
static void mmi_frm_sms_set_card2_profile_detail(PsFuncPtrU16 callback, module_type mod_src, void *profile);
static void mmi_frm_sms_set_card2_profile_detail_req(void *inMsg);
static void mmi_frm_sms_set_card2_profile_detail_rsp(void *info);
static void mmi_msg_set_card2_profile_inline_item_rsp(void *profiledetail, module_type mod, U16 result);
/* message setup profile setting end */

/* message setup common setting begin */
static void mmi_msg_highlight_card2_common_settings(void);
static void mmi_msg_get_card2_common_settings_req(void);
static void mmi_frm_sms_get_card2_common_settings_req(void *dummy);
static void mmi_frm_sms_get_card2_common_settings_rsp(void *info);
static void mmi_msg_get_card2_common_settings_rsp(void *data, module_type mod, U16 result);
static void mmi_msg_entry_card2_common_settings(void);
static void mmi_msg_set_card2_common_settings_req(void);
static void mmi_frm_sms_set_card2_common_settings(PsFuncPtrU16 callback, module_type mod_src, U8 * setting);
static void mmi_frm_sms_set_card2_common_settings_req(void *inMsg);
static void mmi_frm_sms_set_card2_common_settings_rsp(void *info);
static void mmi_msg_set_card2_common_settings_rsp(void *dummy, module_type mod, U16 result);
/* message setup common setting end */

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
/* message setup memory status begin */
static void mmi_msg_highlight_card2_memory_status(void);
static void mmi_msg_get_card2_memory_status_req(void);
static void mmi_frm_sms_get_card2_memory_status(PsFuncPtrU16 callback, module_type mod_src);
static void mmi_frm_sms_get_card2_memory_status_req(void *dummy);
static void mmi_frm_sms_get_card2_memory_status_rsp(void *info);
static void mmi_msg_get_card2_memory_status_rsp(void *data, module_type mod, U16 result);
static void mmi_msg_entry_card2_memory_status(void);
/* message setup memory status end */

/* message setup preferred storage begin */
static void mmi_msg_highlight_card2_preferred_storage(void);
static void mmi_msg_hint_card2_preferred_storage(unsigned short index);
static void mmi_msg_get_card2_preferred_memory_status_req(void);
static void mmi_msg_get_card2_preferred_memory_status_rsp(void *data, module_type mod, U16 result);
static void mmi_msg_entry_card2_preferred_storage(void);
static void mmi_msg_save_card2_preferred_storage(void);
static void mmi_msg_set_card2_preferred_storage_req(unsigned char storage);
static void mmi_frm_sms_set_card2_preferred_storage(PsFuncPtrU16 callback, module_type mod_src, U8 storage);
static void mmi_frm_sms_set_card2_preferred_storage_req(void *inMsg);
static void mmi_frm_sms_set_card2_preferred_storage_rsp(void *info);
static void mmi_msg_set_card2_preferred_storage_rsp(void *storage, module_type mod, U16 result);
/* message setup preferred storage end */
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */

/* send sms sc begin */
static void mmi_frm_sms_get_card2_sc_addr_rsp(void *info);
static void mmi_frm_sms_card2_sc_not_empty(void);
static void mmi_frm_sms_entry_card2_sc_done(void);
static void mmi_frm_sms_set_card2_sc_addr_req(void *inMsg);
static void mmi_frm_sms_set_card2_sc_addr_rsp(void *info);
/* send sms sc end */

/* sms waiting ind begin */
static void mmi_msg_handle_card2_msg_waiting_ind(void *info);
static void mmi_msg_set_card2_msg_waiting_icon(unsigned char line, unsigned char type, unsigned char set);
static void mmi_msg_card2_msg_waiting_ind(unsigned char type);
static void mmi_msg_entry_card2_msg_waiting_ind(void);
static unsigned char *mmi_msg_get_card2_msg_waiting_msg(void);
static void mmi_msg_go_back_from_card2_msg_waiting_ind(void);
static void mmi_msg_end_key_from_card2_msg_waiting_ind(void);
/* sms waiting ind end */

/* sms show begin */
static void HighlightDividedInboxHandler(void);
static void mmi_msg_entry_divided_inbox_menu(void);
static void HighlightDividedOutboxHandler(void);
static void mmi_msg_entry_divided_outbox_menu(void);
static void HighlightMasterInboxHandler(void);
static void HintMasterInboxHandler(U16 index);
static void HighlightSlaveInboxHandler(void);
static void HintSlaveInboxHandler(U16 index);
static void HighlightMasterOutboxHandler(void);
static void HintMasterOutboxHandler(U16 index);
static void HighlightSlaveOutboxHandler(void);
static void HintSlaveOutboxHandler(U16 index);
static U16 init_sms_show_list_index(U8 box_type, E_MTPNP_AD_FILTER_RULE rule);
static void mmi_msg_highlight_show_style(void);
static void mmi_msg_hint_show_style(U16 index);
static void mmi_msg_entry_show_style(void);
static void mmi_msg_save_show_style(void);
/* sms show end */

/**************************LOCAL*FUNCTION*DECLARE*END*************************/
extern void mmi_frm_sms_go_back_from_send(void);
extern void mmi_frm_sms_sc_empty(void);

extern mmi_frm_sms_send_struct *sendSMS;

extern unsigned short mmi_frm_sms_show_list_index[MMI_SMS_MAX_MSG_NUM]; /* list index to show */
static S32 sms_show_list_currIndex = 0;

static U16 card2profileEditStrings[MAX_PROFILE_EDIT_ITEMS];
static U8 *card2strBuff = NULL;
static U8 card2DeliveryRepyStates[2];
static msg_profile_list_struct *card2profileList;
static msg_profile_edit_struct *card2profileDetail;
static msg_profile_list_struct card2psProfileNameList;
static msg_profile_edit_struct card2psProfileEditInfo;
static PU8 card2vpItems[MAX_LFOUR_VP];
static PU8 card2msgTypeItems[MAX_LFOUR_MSG_TYPE];
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
static msg_mem_status_struct card2memStatus = { SMSAL_STORAGE_UNSPECIFIED, 0, 0, 0, 0 };
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */
static U16 card2defaultProfileNames[MAX_LFOUR_PROFILES] = {
    STR_SET0_MENUENTRY,
    STR_SET1_MENUENTRY,
    STR_SET2_MENUENTRY,
    STR_SET3_MENUENTRY
};

static U16 card2profileEditIcons[MAX_PROFILE_EDIT_ITEMS] = {
    IMG_SMS_PROFILE_NAME,
    IMG_SMS_PROFILE_SC,
    IMG_SMS_PROFILE_VP,
    IMG_SMS_PROFILE_MSG_TYPE
};

void MTPNP_PFAL_InitMessageSetup(void)
{
    SetHiliteHandler(MENU_MTPNP_DM_MSG_SETTINGS, mmi_msg_highlight_dm_msg_settings);
    SetHiliteHandler(MENU_MTPNP_MSG_SETTINGS_MENUID, mmi_msg_highlight_card2_msg_settings);
    SetHiliteHandler(MENU_MTPNP_PROFILE_SETTING, mmi_msg_highlight_card2_profile_settings);
    SetHiliteHandler(MENU_MTPNP_COMMONSETTING, mmi_msg_highlight_card2_common_settings);
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
    SetHiliteHandler(MENU_MTPNP_MEMSTATUS, mmi_msg_highlight_card2_memory_status);
    SetHiliteHandler(MENU_MTPNP_PREFEREDSTORAGE, mmi_msg_highlight_card2_preferred_storage);
    SetHintHandler(MENU_MTPNP_PREFEREDSTORAGE, mmi_msg_hint_card2_preferred_storage);
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_MSG_WAITING_IND, mmi_msg_handle_card2_msg_waiting_ind);


    SetHiliteHandler(MENU_MTPNP_SMS_MASTER_INBOX, HighlightMasterInboxHandler);
    SetHintHandler(MENU_MTPNP_SMS_MASTER_INBOX, HintMasterInboxHandler);
    SetHiliteHandler(MENU_MTPNP_SMS_SLAVE_INBOX, HighlightSlaveInboxHandler);
    SetHintHandler(MENU_MTPNP_SMS_SLAVE_INBOX, HintSlaveInboxHandler);
    SetHiliteHandler(MENU_MTPNP_SMS_MASTER_OUTBOX, HighlightMasterOutboxHandler);
    SetHintHandler(MENU_MTPNP_SMS_MASTER_OUTBOX, HintMasterOutboxHandler);
    SetHiliteHandler(MENU_MTPNP_SMS_SLAVE_OUTBOX, HighlightSlaveOutboxHandler);
    SetHintHandler(MENU_MTPNP_SMS_SLAVE_OUTBOX, HintSlaveOutboxHandler);
    SetHiliteHandler(MENU_MTPNP_SMS_SHOW_STYLE, mmi_msg_highlight_show_style);
    SetHintHandler(MENU_MTPNP_SMS_SHOW_STYLE, mmi_msg_hint_show_style);

    memset((S8 *) mmi_frm_sms_show_list_index, MMI_FRM_SMS_INVALID_NUM,
           sizeof(U16) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
}

/* message setup main menu begin */
static void mmi_msg_highlight_dm_msg_settings(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_entry_dm_msg_settings, GoBackHistory);
}

static void mmi_msg_entry_dm_msg_settings(void)
{
	mmi_frm_hide_menu_item(MENU_MTPNP_SMS_SHOW_STYLE);
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_MSG_SETTINGS, NULL, mmi_msg_entry_dm_msg_settings,
                         MENU_MTPNP_DM_MSG_SETTINGS, STR_UM_SMS_ID, IMG_MESSAGE_SMS_MENUENTRY);
#else /* __MMI_UNIFIED_MESSAGE__ */
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_MSG_SETTINGS, NULL, mmi_msg_entry_dm_msg_settings,
                         MENU_MTPNP_DM_MSG_SETTINGS, STR_MESSAGESETUP_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION);
#endif /* __MMI_UNIFIED_MESSAGE__ */
}

static void mmi_msg_highlight_card2_msg_settings(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_pre_entry_card2_msg_settings, GoBackHistory);
}

static void mmi_msg_pre_entry_card2_msg_settings(void)
{
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
        return;
    }
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
        return;
    }
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
    mmi_msg_get_card2_preferred_storage_req();
#else /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */
    mmi_msg_entry_card2_msg_settings();
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */
}

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
static void mmi_msg_get_card2_preferred_storage_req(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_card2_preferred_storage(mmi_msg_get_card2_preferred_storage_rsp, MOD_MMI);
}

static void mmi_frm_sms_get_card2_preferred_storage(PsFuncPtrU16 callback, module_type mod_src)
{
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_card2_preferred_storage_req);
}

static void mmi_frm_sms_get_card2_preferred_storage_req(void *dummy)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PREFERRED_STORAGE_RSP,
                                      mmi_frm_sms_get_card2_preferred_storage_rsp);

    MTPNP_AD_SMS_Get_Prefer_Storage_Req();
}

static void mmi_frm_sms_get_card2_preferred_storage_rsp(void *info)
{
    ST_MTPNP_AD_SMS_GET_PREFER_STORAGE_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_PREFER_STORAGE_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 storage = 0;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PREFERRED_STORAGE_RSP);
    if (msgRsp->result == TRUE)
    {
        if (msgRsp->info.mem2 == SMSAL_SM || msgRsp->info.mem2 == SMSAL_SM_PREFER)
        {
            storage = SMSAL_SM;
        }
        else
        {
            storage = SMSAL_ME;
        }
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void *) &storage, result);
}

static void mmi_msg_get_card2_preferred_storage_rsp(void *storage, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        card2memStatus.prefStorage = *(U8 *) storage;
        mmi_msg_entry_card2_msg_settings();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
}
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */

static void mmi_msg_entry_card2_msg_settings(void)
{
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    EntryNewScreen(SCR_MTPNP_MSG_SETTINGS, mmi_msg_exit_generic, mmi_msg_entry_card2_msg_settings, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_SETTINGS);
    numItems = GetNumOfChild_Ext(MENU_MTPNP_MSG_SETTINGS_MENUID);
    GetSequenceStringIds_Ext(MENU_MTPNP_MSG_SETTINGS_MENUID, nStrItemList);

    SetParentHandler(MENU_MTPNP_MSG_SETTINGS_MENUID);
    ConstructHintsList(MENU_MTPNP_MSG_SETTINGS_MENUID, popUpList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_SETTINGS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_SETTINGS);

    mmi_msg_set_msg_menu_highlight_handler();

    ShowCategory52Screen(STRING_MTPNP_MESSAGESETUP_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         numItems, nStrItemList, (U16 *) gIndexIconsImageList, (U8 **) popUpList, 0, 0, guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* message setup main menu end */

/* message setup profile setting begin */
static void mmi_msg_highlight_card2_profile_settings(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_get_card2_profile_list_req, GoBackHistory);
}

static void mmi_msg_get_card2_profile_list_req(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_card2_profile_list(mmi_msg_get_card2_profile_list_rsp, MOD_MMI);
}

void mmi_frm_sms_get_card2_profile_list(PsFuncPtrU16 callback, module_type mod_src)
{
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_card2_profile_num_req);
}

static void mmi_frm_sms_get_card2_profile_num_req(void *dummy)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_NUM_RSP, mmi_frm_sms_get_card2_profile_num_rsp);

    MTPNP_AD_SMS_Get_Profile_Num_Req();
}

static void mmi_frm_sms_get_card2_profile_num_rsp(void *info)
{
    ST_MTPNP_AD_SMS_GET_PROFILE_NUM_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_PROFILE_NUM_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    card2profileList = OslMalloc(sizeof(msg_profile_list_struct));
    card2profileList->currMaxPsProfiles = 0;
    card2profileList->currReqProfileNo = 0;
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_NUM_RSP);
    if (msgRsp->result == TRUE)
    {
        card2profileList->currMaxPsProfiles = msgRsp->profile_no;
        card2profileList->profileNameLength = msgRsp->name_len;
        result = MMI_FRM_SMS_OK;
    }
    if (card2profileList->currMaxPsProfiles == 0)
    {
        mmi_frm_sms_callback_action((void *) card2profileList, result);
        OslMfree(card2profileList);
    }
    else
    {
        mmi_frm_sms_get_card2_profile_name_req(&(card2profileList->currReqProfileNo));
    }
}

static void mmi_msg_get_card2_profile_list_rsp(void *profilelist, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        memset(&card2psProfileNameList, 0, sizeof(msg_profile_list_struct));
        memcpy((S8 *) & card2psProfileNameList, (S8 *) profilelist, sizeof(msg_profile_list_struct));
        if (card2psProfileNameList.currMaxPsProfiles > 0)
        {
            mmi_msg_entry_card2_profile_settings();
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT,
                         (U8) EMPTY_LIST_TONE);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
}

static void mmi_frm_sms_get_card2_profile_name_req(void *inMsg)
{
    MTPNP_UINT8 index = *(U8 *) inMsg;

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_PARAMS_RSP,
                                      mmi_frm_sms_get_card2_profile_name_rsp);
    MTPNP_AD_SMS_Get_Profile_Params_Req(index);
}

static void mmi_frm_sms_get_card2_profile_name_rsp(void *info)
{
    ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        U16 outLen = 0;
        U8 *tempbuf = NULL;

        tempbuf =
            CovertStringForPlatform(msgRsp->profile_name.name, msgRsp->profile_name.name_length,
                                    msgRsp->profile_name.name_dcs, &outLen);
        memcpy((PS8) card2profileList->profileName[card2profileList->currReqProfileNo], tempbuf, outLen);
        if (tempbuf)
        {
            OslMfree(tempbuf);
            tempbuf = NULL;
        }
        card2profileList->currReqProfileNo++;
        result = MMI_FRM_SMS_OK;
    }

    if ((card2profileList->currReqProfileNo >= card2profileList->currMaxPsProfiles) || (result == MMI_FRM_SMS_ERROR))
    {
        if (card2profileList->currMaxPsProfiles > 0)
        {
            S16 errorCode = 0;
            ReadValue(NVRAM_SLAVE_ACTIVE_PROFILE_IDX, &(card2profileList->currReqProfileNo), DS_BYTE, &errorCode);
            if (card2profileList->currReqProfileNo > card2profileList->currMaxPsProfiles)
            {
                card2profileList->currReqProfileNo = 0;
                WriteValue(NVRAM_SLAVE_ACTIVE_PROFILE_IDX, &(card2profileList->currReqProfileNo), DS_BYTE, &errorCode);
            }
        }

        mmi_frm_sms_callback_action((void *) card2profileList, result);
        OslMfree(card2profileList);
    }
    else
    {
        mmi_frm_sms_get_card2_profile_name_req(&(card2profileList->currReqProfileNo));
    }
}

static void mmi_msg_entry_card2_profile_settings(void)
{
    PU8 guiBuffer = NULL;
    S32 hiliteitem;
    S8 index = 0;

    EntryNewScreen(SCR_MTPNP_MSG_PROFILE_LIST, mmi_msg_exit_generic, mmi_msg_entry_card2_profile_settings, NULL);

    for (index = 0; (index < card2psProfileNameList.currMaxPsProfiles) && (index < MAX_LFOUR_PROFILES); index++)
    {
        if ((card2psProfileNameList.profileName[index][0] == '\0')
            && (card2psProfileNameList.profileName[index][1] == '\0'))
        {
            subMenuDataPtrs[index] = (PU8) GetString((U16) card2defaultProfileNames[index]);
        }
        else
        {
            subMenuDataPtrs[index] = (PU8) card2psProfileNameList.profileName[index];
        }
    }

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_PROFILE_LIST);
    if (guiBuffer != NULL)
    {
        hiliteitem = g_msg_cntx.currHiliteIndex;
    }
    else
    {
        hiliteitem = card2psProfileNameList.currReqProfileNo;
    }
    RegisterHighlightHandler(mmi_msg_get_card2_profile_highlight_index);

    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_PROFILE_LIST);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_PROFILE_LIST);

    ShowCategory36Screen(STRING_MTPNP_PROFILE_SETTING_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_EDIT, IMG_SMS_COMMON_NOIMAGE,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK, index, subMenuDataPtrs, (U16) hiliteitem, guiBuffer);
    SetLeftSoftkeyFunction(mmi_msg_get_card2_profile_inline_item_req, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_get_card2_profile_highlight_index(S32 nIndex)
{
    g_msg_cntx.currHiliteIndex = nIndex;
    if (g_msg_cntx.currHiliteIndex != card2psProfileNameList.currReqProfileNo)
    {
        mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_save_card2_profile_active, Messages2GoBackHistory);
        ChangeRightSoftkey(STR_GLOBAL_DONE, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_msg_entry_confirm_generic, KEY_EVENT_UP);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

static void mmi_msg_save_card2_profile_active(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_msg_set_card2_profile_active_req((U8 *) & (g_msg_cntx.currHiliteIndex));
}

static void mmi_msg_set_card2_profile_active_req(U8 * index)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_card2_profile_active(mmi_msg_set_card2_profile_active_rsp, MOD_MMI, index);
}

static void mmi_frm_sms_set_card2_profile_active(PsFuncPtrU16 callback, module_type mod_src, U8 * index)
{
    S16 errorCode = 0;

    WriteValue(NVRAM_SLAVE_ACTIVE_PROFILE_IDX, index, DS_BYTE, &errorCode);
    callback(index, mod_src, MMI_FRM_SMS_OK);
}

static void mmi_msg_set_card2_profile_active_rsp(void *index, module_type mod_src, U16 result)
{
    card2psProfileNameList.currReqProfileNo = *((U8 *) index);
    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT,
                 (U8) SUCCESS_TONE);
    DeleteMessagesHistoryNodes();
}

static void mmi_msg_get_card2_profile_inline_item_req(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_card2_profile_detail(mmi_msg_get_card2_profile_inline_item_rsp, MOD_MMI,
                                         (U8) g_msg_cntx.currHiliteIndex);
}

static void mmi_frm_sms_get_card2_profile_detail(PsFuncPtrU16 callback, module_type mod_src, U8 index)
{
    U8 *data = OslMalloc(sizeof(U8));
    memset(data, index, sizeof(U8));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_get_card2_profile_detail_req);
}

static void mmi_frm_sms_get_card2_profile_detail_req(void *inMsg)
{
    MTPNP_UINT8 index = *(U8 *) inMsg;

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_PARAMS_RSP,
                                      mmi_frm_sms_get_card2_profile_detail_rsp);
    MTPNP_AD_SMS_Get_Profile_Params_Req(index);
}

static void mmi_frm_sms_get_card2_profile_detail_rsp(void *info)
{
    ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    card2profileDetail = OslMalloc(sizeof(msg_profile_edit_struct));
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        U16 outLen = 0;
        U8 *tempbuff = NULL;
        U8 type = (msgRsp->sc_addr.type == CSMCC_INTERNATIONAL_ADDR) ? 1 : 0;
        tempbuff = CovertStringForPlatform(msgRsp->profile_name.name, msgRsp->profile_name.name_length,
                                           msgRsp->profile_name.name_dcs, &outLen);
        memset((PS8) card2profileDetail->profileName, 0, (MAX_PROFILE_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
        memcpy((PS8) card2profileDetail->profileName, tempbuff, (outLen * ENCODING_LENGTH));
        card2profileDetail->profileNameDcs = msgRsp->profile_name.name_dcs;
        if (tempbuff)
        {
            OslMfree(tempbuff);
            tempbuff = NULL;
        }
        card2profileDetail->vpIndex = (U32) msgRsp->vp;
        card2profileDetail->msgTypeIndex = (U32) msgRsp->pid;

        if (type)
        {
            mmi_asc_to_ucs2((PS8) card2profileDetail->scAddress, (PS8) "+");
        }
        mmi_asc_n_to_ucs2((PS8) card2profileDetail->scAddress + (type * ENCODING_LENGTH),
                              (PS8) msgRsp->sc_addr.number, msgRsp->sc_addr.length);
        memset((void *) &card2profileDetail->scAddress[(msgRsp->sc_addr.length + type) * ENCODING_LENGTH], 0,
               ENCODING_LENGTH);
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void *) card2profileDetail, result);
    OslMfree(card2profileDetail);
}

static void mmi_msg_get_card2_profile_inline_item_rsp(void *profiledetail, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        memcpy((S8 *) & card2psProfileEditInfo, (S8 *) profiledetail, sizeof(msg_profile_edit_struct));
        card2psProfileEditInfo.profileIndex = g_msg_cntx.currHiliteIndex;
        switch (card2psProfileEditInfo.vpIndex)
        {
        case SMSAL_VP_1_HR:
            card2psProfileEditInfo.vpIndex = 0;
            break;
        case SMSAL_VP_6_HR:
            card2psProfileEditInfo.vpIndex = 1;
            break;
        case SMSAL_VP_12_HR:
            card2psProfileEditInfo.vpIndex = 2;
            break;
        case SMSAL_VP_24_HR:
            card2psProfileEditInfo.vpIndex = 3;
            break;
        case SMSAL_VP_72_HR:
            card2psProfileEditInfo.vpIndex = 4;
            break;                
        case SMSAL_VP_1_WEEK:
            card2psProfileEditInfo.vpIndex = 5;
            break;
        case SMSAL_VP_MAX:
            card2psProfileEditInfo.vpIndex = 6;
            break;
        default:
            card2psProfileEditInfo.vpIndex = 6;
            break;
        }

        switch (card2psProfileEditInfo.msgTypeIndex)
        {
        case SMSAL_DEFAULT_PID:
            card2psProfileEditInfo.msgTypeIndex = 0;
            break;
        case SMSAL_G3_FAX_PID:
            card2psProfileEditInfo.msgTypeIndex = 1;
            break;
        case SMSAL_PAGING_PID:
            card2psProfileEditInfo.msgTypeIndex = 2;
            break;
        case SMSAL_EMAIL_PID:
            card2psProfileEditInfo.msgTypeIndex = 3;
            break;
        default:
            card2psProfileEditInfo.msgTypeIndex = 0;
            break;
        }
        mmi_msg_entry_card2_profile_edit();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
}

static void mmi_msg_entry_card2_profile_edit(void)
{
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize = 0;
    U8 numOfItems = MAX_PROFILE_EDIT_ITEMS;

    EntryNewScreen(SCR_MTPNP_MSG_PROFILE_EDIT, mmi_msg_exit_card2_profile_edit, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_PROFILE_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_MTPNP_MSG_PROFILE_EDIT, &inputBufferSize);

    RegisterHighlightHandler(mmi_msg_profile_edit_card2_highlight_handler);
    card2profileEditStrings[0] = STRING_MTPNP_PROFILE_NAME;
    card2profileEditStrings[1] = STRING_MTPNP_PROFILE_SC;
    card2profileEditStrings[2] = STRING_MTPNP_PROFILE_VP;
    card2profileEditStrings[3] = STRING_MTPNP_PROFILE_MSG_TYPE;

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        numOfItems--;
    }
    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        numOfItems--;
    }

    mmi_msg_set_card2_profile_inline_item();
    if (guiBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, numOfItems, inputBuffer);
    }

    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_PROFILE_EDIT);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_PROFILE_EDIT);

    mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_set_card2_profile_inline_item_req, Messages2GoBackHistory);

    ShowCategory57Screen(STRING_MTPNP_PROFILE_NAME, IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_EDIT, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         numOfItems, card2profileEditIcons, wgui_inline_items, 0, guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
}

static void mmi_msg_exit_card2_profile_edit(void)
{
    history currHistory;
    U16 inputBufferSize = 0;
    S16 nHistory = 0;

    if (GetUCS2Flag((PS8) card2psProfileEditInfo.profileName))
    {
        card2psProfileEditInfo.profileNameDcs = PHB_UCS2;
    }
    else
    {
        card2psProfileEditInfo.profileNameDcs = PHB_ASCII;
    }
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_MTPNP_MSG_PROFILE_EDIT;
    SetMessagesCurrScrnID(0);

    currHistory.scrnID = SCR_MTPNP_MSG_PROFILE_EDIT;
    CloseCategory57Screen();
    currHistory.entryFuncPtr = mmi_msg_entry_card2_profile_edit;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8 *) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}

static void mmi_msg_set_card2_profile_inline_item(void)
{
    U8 numOfMenuItems = 2;
    U8 numOfMsgTypes = 2;

    card2vpItems[0] = (PU8) GetString(STR_1HOUR_MENUENTRY);
    card2vpItems[1] = (PU8) GetString(STR_6HOUR_MENUENTRY);
    card2vpItems[2] = (PU8) GetString(STR_12HOUR_MENUENTRY);
    card2vpItems[3] = (PU8) GetString(STR_24HOUR_MENUENTRY);
    card2vpItems[4] = (PU8) GetString(STR_3DAY_MENUENTRY);
    card2vpItems[5] = (PU8) GetString(STR_1WEEK_MENUENTRY);
    card2vpItems[6] = (PU8) GetString(STR_63WEEKS_MENUENTRY);


    card2msgTypeItems[0] = (PU8) GetString(STR_TEXT_MENUENTRY);
    card2msgTypeItems[1] = (PU8) GetString(STR_FAX_MENUENTRY);
    if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_PAGING))
    {
        card2msgTypeItems[numOfMsgTypes] = (PU8) GetString(STR_PAGE_MENUENTRY);
        numOfMsgTypes++;
    }
    if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_EMAIL))
    {
        card2msgTypeItems[numOfMsgTypes] = (PU8) GetString(STR_MT_EMAIL_MENUENTRY);
        numOfMsgTypes++;
    }

    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);

    SetInlineItemFullScreenEdit(&wgui_inline_items[0], STRING_MTPNP_PROFILE_NAME, IMG_SMS_ENTRY_SCRN_CAPTION,
                                (PU8) card2psProfileEditInfo.profileName,
                                card2psProfileNameList.profileNameLength + 1,
                                INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER |
                                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[0], mmi_msg_inline_generic_custom_function);

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8) card2psProfileEditInfo.scAddress, MAX_DIGITS_SMS,
                          INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    DisableInlineItemHighlight(&wgui_inline_items[1]);

    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        SetInlineItemActivation(&wgui_inline_items[numOfMenuItems], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[numOfMenuItems], MAX_LFOUR_VP, card2vpItems,
                            &card2psProfileEditInfo.vpIndex);
        numOfMenuItems++;
    }

    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        SetInlineItemActivation(&wgui_inline_items[numOfMenuItems], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[numOfMenuItems], numOfMsgTypes, card2msgTypeItems,
                            &card2psProfileEditInfo.msgTypeIndex);
        numOfMenuItems++;
    }
}

static void mmi_msg_profile_edit_card2_highlight_handler(S32 index)
{
    ChangeTitleString((PU8) GetString(card2profileEditStrings[index]));
    draw_title();
}

static void mmi_msg_set_card2_profile_inline_item_req(void)
{
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        switch ((U8) card2psProfileEditInfo.vpIndex)
        {
        case 0:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_1_HR;
            break;
        case 1:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_6_HR;
            break;
        case 2:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_12_HR;
            break;
        case 3:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_24_HR;
            break;       
        case 4:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_72_HR;
            break;                
        case 5:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_1_WEEK;
            break;
        case 6:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_MAX;
            break;
        default:
            card2psProfileEditInfo.vpIndex = SMSAL_VP_MAX;
            break;
        }
    }
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        switch ((U8) card2psProfileEditInfo.msgTypeIndex)
        {
        case 0:
            card2psProfileEditInfo.msgTypeIndex = SMSAL_DEFAULT_PID;
            break;
        case 1:
            card2psProfileEditInfo.msgTypeIndex = SMSAL_G3_FAX_PID;
            break;
        case 2:
            if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_PAGING))
            {
                card2psProfileEditInfo.msgTypeIndex = SMSAL_PAGING_PID;
                break;
            }
        case 3:
            if (!IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_SM_MO_EMAIL))
            {
                card2psProfileEditInfo.msgTypeIndex = SMSAL_EMAIL_PID;
                break;
            }
        default:
            card2psProfileEditInfo.msgTypeIndex = SMSAL_DEFAULT_PID;
            break;
        }
    }
    ClearAllKeyHandler();
    mmi_frm_sms_set_card2_profile_detail(mmi_msg_set_card2_profile_inline_item_rsp, MOD_MMI,
                                         (void *) &card2psProfileEditInfo);
}

static void mmi_frm_sms_set_card2_profile_detail(PsFuncPtrU16 callback, module_type mod_src, void *profile)
{
    msg_profile_edit_struct *data = OslMalloc(sizeof(msg_profile_edit_struct));

    memcpy(data, profile, sizeof(msg_profile_edit_struct));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_card2_profile_detail_req);
}

static void mmi_frm_sms_set_card2_profile_detail_req(void *inMsg)
{
    ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_REQ *msgReq;
    msg_profile_edit_struct *profile = (msg_profile_edit_struct *) inMsg;
    S8 scAddress[MAX_DIGITS + 1];

    card2profileDetail = OslMalloc(sizeof(msg_profile_edit_struct));
    memcpy(card2profileDetail, profile, sizeof(msg_profile_edit_struct));
    msgReq = (ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_REQ *) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->para_ind = 0;
    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Validity_Period))
    {
        msgReq->vp = (U8) profile->vpIndex;
        msgReq->para_ind |= SMSAL_PARA_VP;
    }

    if (!IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Protocol_ID))
    {
        msgReq->pid = (U8) profile->msgTypeIndex;
        msgReq->para_ind |= SMSAL_PARA_PID;
    }

    if (profile->profileNameDcs == PHB_UCS2)
    {
        msgReq->profile_name.name_dcs = MMI_PHB_UCS2;
        msgReq->profile_name.name_length = ((U8) mmi_ucs2strlen((PS8) profile->profileName)) * ENCODING_LENGTH;
        InputboxConvertDeviceEncodingToGSM((PU8) profile->profileName, msgReq->profile_name.name,
                                           MAX_PROFILE_NAME_LEN, MMI_PHB_UCS2, 0, 1);
    }
    else
    {
        msgReq->profile_name.name_dcs = MMI_PHB_ASCII;
        msgReq->profile_name.name_length =
            InputboxConvertDeviceEncodingToGSM((PU8) profile->profileName, msgReq->profile_name.name,
                                               MAX_PROFILE_NAME_LEN, MMI_PHB_ASCII, 0, 1) - 1;
    }
    memset(&msgReq->profile_name.name[msgReq->profile_name.name_length], 0, 1);
    msgReq->para_ind |= SMSAL_PARA_PROFILE_NAME;

    memset(&scAddress, 0, MAX_DIGITS_SMS * ENCODING_LENGTH);
    mmi_ucs2_n_to_asc((PS8) scAddress, (PS8) profile->scAddress, MAX_DIGITS_SMS * ENCODING_LENGTH);
    msgReq->profile_no = profile->profileIndex;
    if (scAddress[0] == '+')
    {
        msgReq->sc_addr.type = CSMCC_INTERNATIONAL_ADDR;
        msgReq->sc_addr.length = (strlen(scAddress) > MAX_DIGITS_SMS) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress) - 1);
        memcpy(msgReq->sc_addr.number, scAddress + 1, msgReq->sc_addr.length);
    }
    else
    {
        msgReq->sc_addr.type = CSMCC_DEFAULT_ADDR_TYPE;
        msgReq->sc_addr.length =
            (strlen(scAddress) > (MAX_DIGITS_SMS - 1)) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress));
        memcpy(msgReq->sc_addr.number, scAddress, msgReq->sc_addr.length);
    }
    memset(&msgReq->sc_addr.number[msgReq->sc_addr.length], 0, 1);
    msgReq->para_ind |= SMSAL_PARA_SCA;

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_PROFILE_PARAMS_RSP,
                                      mmi_frm_sms_set_card2_profile_detail_rsp);
    MTPNP_AD_SMS_Set_Profile_Params_Req(msgReq);
    OslMfree(inMsg);
    OslIntFreeDataPtr(msgReq);
}

static void mmi_frm_sms_set_card2_profile_detail_rsp(void *info)
{
    ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_RSP *msgRsp = (ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void *) card2profileDetail, result);
    OslMfree(card2profileDetail);
}

static void mmi_msg_set_card2_profile_inline_item_rsp(void *profiledetail, module_type mod, U16 result)
{
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_PROFILE_EDIT);
    if (result == MMI_FRM_SMS_OK)
    {
        msg_profile_edit_struct *profile = (msg_profile_edit_struct *) profiledetail;
        mmi_ucs2cpy((S8 *) & card2psProfileNameList.profileName[card2psProfileEditInfo.profileIndex],
                         (S8 *) profile->profileName);
        switch (profile->vpIndex)
        {
        case SMSAL_VP_1_HR:
            card2psProfileEditInfo.vpIndex = 0;
            break;
        case SMSAL_VP_12_HR:
            card2psProfileEditInfo.vpIndex = 1;
            break;
        case SMSAL_VP_24_HR:
            card2psProfileEditInfo.vpIndex = 2;
            break;
        case SMSAL_VP_1_WEEK:
            card2psProfileEditInfo.vpIndex = 3;
            break;
        case SMSAL_VP_MAX:
            card2psProfileEditInfo.vpIndex = 4;
            break;
        default:
            card2psProfileEditInfo.vpIndex = 4;
            break;
        }

        switch (profile->msgTypeIndex)
        {
        case SMSAL_DEFAULT_PID:
            card2psProfileEditInfo.msgTypeIndex = 0;
            break;
        case SMSAL_G3_FAX_PID:
            card2psProfileEditInfo.msgTypeIndex = 1;
            break;
        case SMSAL_PAGING_PID:
            card2psProfileEditInfo.msgTypeIndex = 2;
            break;
        case SMSAL_EMAIL_PID:
            card2psProfileEditInfo.msgTypeIndex = 3;
            break;
        default:
            card2psProfileEditInfo.msgTypeIndex = 0;
            break;
        }
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
    DeleteMessagesHistoryNodes();
}

/* message setup profile setting end */

/* message setup common setting begin */
static void mmi_msg_highlight_card2_common_settings(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_get_card2_common_settings_req, GoBackHistory);

}

static void mmi_msg_get_card2_common_settings_req(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_get_card2_common_settings(mmi_msg_get_card2_common_settings_rsp, MOD_MMI);
}

void mmi_frm_sms_get_card2_common_settings(PsFuncPtrU16 callback, module_type mod_src)
{
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_card2_common_settings_req);
}

static void mmi_frm_sms_get_card2_common_settings_req(void *dummy)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_COMMON_PARAMS_RSP,
                                      mmi_frm_sms_get_card2_common_settings_rsp);
    MTPNP_AD_SMS_Get_Common_Params_Req();
}

static void mmi_frm_sms_get_card2_common_settings_rsp(void *info)
{
    ST_MTPNP_AD_SMS_GET_COMMON_PARAMS_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_COMMON_PARAMS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 settings[2] = { 0, 0 };

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_COMMON_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        settings[0] = msgRsp->status_report;
        settings[1] = msgRsp->reply_path;
        result = MMI_FRM_SMS_OK;

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
        g_frm_sms_cntx.mmi_frm_sms_slave_delivery_report_setting = msgRsp->status_report;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    }
    mmi_frm_sms_callback_action((void *) settings, result);
}

static void mmi_msg_get_card2_common_settings_rsp(void *data, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        U8 *DrRp = (U8 *) data;
        card2DeliveryRepyStates[0] = DrRp[0];
        card2DeliveryRepyStates[1] = DrRp[1];
        mmi_msg_entry_card2_common_settings();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
    }
}

static void mmi_msg_entry_card2_common_settings(void)
{
    U8 *guiBuffer;
    U16 numItems = 2;
    S32 maskingByte = -1;

    EntryNewScreen(SCR_MTPNP_MSG_COMMON_SETTINGS, mmi_msg_exit_generic, mmi_msg_entry_card2_common_settings, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_COMMON_SETTINGS);
    subMenuDataPtrs[0] = (PU8) GetString((U16) STR_DELIVERY_REPORT_MENUENTRY);
    subMenuDataPtrs[1] = (PU8) GetString((U16) STR_REPLY_PATH_MENUENTRY);

    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_COMMON_SETTINGS);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_COMMON_SETTINGS);

    mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_set_card2_common_settings_req, Messages2GoBackHistory);

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Del_Conf))
    {
        ResetBit(maskingByte, 0);
    }

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Reply_path))
    {
        ResetBit(maskingByte, 1);
    }

    MaskStringItems(subMenuDataPtrs, (U8) numItems, maskingByte);
    numItems = MaskItemsU8(card2DeliveryRepyStates, (U8) numItems, maskingByte);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    ShowCategory140Screen(STRING_MTPNP_COMMONSETTING_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
                          numItems, (U8 **) subMenuDataPtrs, (U8 *) card2DeliveryRepyStates, 0, guiBuffer);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_set_card2_common_settings_req(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_card2_common_settings(mmi_msg_set_card2_common_settings_rsp, MOD_MMI, card2DeliveryRepyStates);
}

static void mmi_frm_sms_set_card2_common_settings(PsFuncPtrU16 callback, module_type mod_src, U8 * setting)
{
    U8 *data = OslMalloc(sizeof(U8) * 2);

    memcpy(data, setting, sizeof(U8) * 2);
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_card2_common_settings_req);
}

static void mmi_frm_sms_set_card2_common_settings_req(void *inMsg)
{
    ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_REQ *msgReq;
    U8 *DrRp = (U8 *) inMsg;
    msgReq = (ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_REQ *) OslConstructDataPtr(sizeof(*msgReq));

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Del_Conf))
    {
        if (DrRp[0] == 0)
        {
            DrRp[0] = 0;
            DrRp[1] = 0;
        }
        else
        {
            DrRp[0] = 0;
            DrRp[1] = 1;
        }
    }

    msgReq->status_report = DrRp[0];
    msgReq->reply_path = DrRp[1];
    msgReq->para_ind = SMSAL_COM_PARA_STATUS_REP | SMSAL_COM_PARA_REPLY_PATH;

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    g_frm_sms_cntx.mmi_frm_sms_slave_delivery_report_temp_setting = msgReq->status_report;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_COMMON_PARAMS_RSP,
                                      mmi_frm_sms_set_card2_common_settings_rsp);
    MTPNP_AD_SMS_Set_Common_Params_Req(msgReq);
    OslMfree(inMsg);
    OslIntFreeDataPtr(msgReq);
}

static void mmi_frm_sms_set_card2_common_settings_rsp(void *info)
{
    ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_RSP *msgRsp = (ST_MTPNP_AD_SMS_SET_COMMON_PARAMS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_COMMON_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
        g_frm_sms_cntx.mmi_frm_sms_slave_delivery_report_setting = g_frm_sms_cntx.mmi_frm_sms_slave_delivery_report_temp_setting;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    }
    mmi_frm_sms_callback_action(NULL, result);
}

static void mmi_msg_set_card2_common_settings_rsp(void *dummy, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) WARNING_TONE);
    }
    DeleteMessagesHistoryNodes();
}

/* message setup common setting end */

#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
/* message setup memory status begin */
static void mmi_msg_highlight_card2_memory_status(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_get_card2_memory_status_req, GoBackHistory);

}

static void mmi_msg_get_card2_memory_status_req(void)
{
    if (!IsScreenPresent(SCR_MTPNP_MSG_MEMORY_STATUS))
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
    mmi_frm_sms_get_card2_memory_status(mmi_msg_get_card2_memory_status_rsp, MOD_MMI);
}

static void mmi_frm_sms_get_card2_memory_status(PsFuncPtrU16 callback, module_type mod_src)
{
    mmi_frm_sms_write_action(callback, mod_src, NULL, mmi_frm_sms_get_card2_memory_status_req);
}

static void mmi_frm_sms_get_card2_memory_status_req(void *dummy)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MSG_NUM_RSP, mmi_frm_sms_get_card2_memory_status_rsp);
    MTPNP_AD_SMS_Get_MSG_Num_Req();
}

static void mmi_frm_sms_get_card2_memory_status_rsp(void *info)
{
    ST_MTPNP_AD_SMS_GET_MSG_NUM_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_MSG_NUM_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;
    msg_mem_status_struct memory;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MSG_NUM_RSP);
    if (msgRsp->result == TRUE)
    {
        memory.simTotal = msgRsp->total_sim_num;
        memory.meTotal = msgRsp->total_me_num;
        memory.simUsed = msgRsp->in_sim_no + msgRsp->out_sim_no;
        memory.meUsed = msgRsp->in_me_no + msgRsp->out_me_no;
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void *) &memory, result);
}

static void mmi_msg_get_card2_memory_status_rsp(void *data, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        msg_mem_status_struct *memorystatus = (msg_mem_status_struct *) data;
        card2memStatus.simTotal = memorystatus->simTotal;
        card2memStatus.meTotal = memorystatus->meTotal;
        card2memStatus.simUsed = memorystatus->simUsed;
        card2memStatus.meUsed = memorystatus->meUsed;
        if (IsScreenPresent(SCR_MTPNP_MSG_MEMORY_STATUS))
        {
            HistoryReplace(SCR_MTPNP_MSG_MEMORY_STATUS, SCR_MTPNP_MSG_MEMORY_STATUS, mmi_msg_entry_card2_memory_status);
        }
        else
        {
            mmi_msg_entry_card2_memory_status();
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
    }
    AlmEnableExpiryHandler();
}

static void mmi_msg_entry_card2_memory_status(void)
{
    U8 *guiBuffer;
    U16 modeValue;
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    char spaceBuf[5];
    S8 memoryStatus[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];

    EntryNewScreen(SCR_MTPNP_MSG_MEMORY_STATUS, mmi_msg_exit_generic, mmi_msg_entry_card2_memory_status, NULL);
    memset(memoryStatus, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
    memset(spaceBuf, 0, 5);
    mmi_asc_to_ucs2(spaceBuf, "\n");

    mmi_ucs2cpy(memoryStatus, GetString(STRING_MTPNP_SMSSTATUS_TITLE));
    mmi_ucs2cat(memoryStatus, spaceBuf);

    mmi_ucs2cat(memoryStatus, GetString(STRING_MTPNP_SMS_MEMSTATUS_PREFIX_SIM));
    memset(tempBuf, 0, MAX_SUBMENU_CHARACTERS);
    if (card2memStatus.simTotal > 0)
    {
       // modeValue = ((card2memStatus.simUsed) * 100) % (card2memStatus.simTotal);
       // sprintf(tempBuf, "%d.%02d%%", ((card2memStatus.simUsed) * 100) / (card2memStatus.simTotal),
              //  (modeValue * 100) / (card2memStatus.simTotal));
              sprintf(tempBuf, "%d/%d", card2memStatus.simUsed, card2memStatus.simTotal);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat(memoryStatus, tempBufUnicode);
    }
    else
    {
        mmi_ucs2cat(memoryStatus, (S8 *) GetString(STR_SMS_DOES_NOT_SUPPORT));
    }
    mmi_ucs2cat(memoryStatus, spaceBuf);

    mmi_ucs2ncat(memoryStatus, GetString(STRING_MTPNP_SMS_MEMSTATUS_PREFIX_PHONE), 16);
    memset(tempBuf, 0, MAX_SUBMENU_CHARACTERS);
    if (card2memStatus.meTotal > 0)
    {
        //modeValue = ((card2memStatus.meUsed) * 100) % (card2memStatus.meTotal);
        //sprintf(tempBuf, "%d.%02d%%", ((card2memStatus.meUsed) * 100) / (card2memStatus.meTotal),
              //  ((modeValue) * 100) / (card2memStatus.meTotal));
              sprintf(tempBuf, "%d/%d", card2memStatus.meUsed, card2memStatus.meTotal);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2ncat(memoryStatus, tempBufUnicode, 16);
    }
    else
    {
        mmi_ucs2ncat(memoryStatus, (S8 *) GetString(STR_SMS_DOES_NOT_SUPPORT), 16);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_MEMORY_STATUS);
    if ((guiBuffer != NULL) || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_MTPNP_MSG_MEMORY_STATUS))
        DeleteNScrId(SCR_MTPNP_MSG_MEMORY_STATUS);

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_MEMORY_STATUS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_MEMORY_STATUS);

    ShowCategory7Screen(STR_SMSSTATUS_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION, 0, 0,
                        STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (PU8) memoryStatus, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* message setup memory status end */

/* message setup preferred storage begin */
static void mmi_msg_highlight_card2_preferred_storage(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                              mmi_msg_get_card2_preferred_memory_status_req, GoBackHistory);

}

static void mmi_msg_hint_card2_preferred_storage(unsigned short index)
{
    PU8 StorageStr;

    if (card2memStatus.prefStorage == 0)
    {
        StorageStr = (PU8) GetString((U16) STRING_MTPNP_SIM_STORAGE_MENUENTRY);
    }
    else
    {
        StorageStr = (PU8) GetString((U16) STRING_MTPNP_ME_STORAGE_MENUENTRY);
    }
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) StorageStr);
}

static void mmi_msg_get_card2_preferred_memory_status_req(void)
{
    if (!IsScreenPresent(SCR_MTPNP_MSG_PREFERRED_STORAGE))
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
    mmi_frm_sms_get_card2_memory_status(mmi_msg_get_card2_preferred_memory_status_rsp, MOD_MMI);
}

static void mmi_msg_get_card2_preferred_memory_status_rsp(void *data, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        msg_mem_status_struct *memorystatus = (msg_mem_status_struct *) data;

        card2memStatus.simTotal = memorystatus->simTotal;
        card2memStatus.meTotal = memorystatus->meTotal;
        card2memStatus.simUsed = memorystatus->simUsed;
        card2memStatus.meUsed = memorystatus->meUsed;
        if (IsScreenPresent(SCR_MTPNP_MSG_PREFERRED_STORAGE))
        {
            HistoryReplace(SCR_MTPNP_MSG_PREFERRED_STORAGE, SCR_MTPNP_MSG_PREFERRED_STORAGE,
                           mmi_msg_entry_card2_preferred_storage);
        }
        else
        {
            mmi_msg_entry_card2_preferred_storage();
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
    }
    AlmEnableExpiryHandler();
}

static void mmi_msg_entry_card2_preferred_storage(void)
{
    U8 *guiBuffer;
    U16 nNumofItem = 2;
    S32 hiliteitem;
    char tempBuf[MAX_SUBMENU_CHARACTERS];
	U16 modeValue;

    EntryNewScreen(SCR_MTPNP_MSG_PREFERRED_STORAGE, mmi_msg_exit_generic, mmi_msg_entry_card2_preferred_storage, NULL);

    memset(hintData[0], 0, MAX_SUB_MENU_HINT_SIZE);
    memset(hintData[1], 0, MAX_SUB_MENU_HINT_SIZE);

    if (card2memStatus.simTotal > 0)
    {
        //modeValue = ((card2memStatus.simUsed) * 100) % (card2memStatus.simTotal);
       // sprintf(tempBuf, "%d.%02d%%", ((card2memStatus.simUsed) * 100) / (card2memStatus.simTotal), (modeValue * 100) / (card2memStatus.simTotal));
sprintf(tempBuf, "%d/%d", card2memStatus.simUsed, card2memStatus.simTotal);  //huyi-20080504
        mmi_asc_to_ucs2((S8 *) hintData[0], tempBuf);
    }
    else
    {
        mmi_ucs2cpy((S8 *) hintData[0], (S8 *) GetString(STR_SMS_DOES_NOT_SUPPORT));
    }

    if (card2memStatus.meTotal > 0)
    {
       // modeValue = ((card2memStatus.meUsed) * 100) % (card2memStatus.meTotal);
        //sprintf(tempBuf, "%d.%02d%%", ((card2memStatus.meUsed) * 100) / (card2memStatus.meTotal), ((modeValue) * 100) / (card2memStatus.meTotal));
sprintf(tempBuf, "%d/%d", card2memStatus.meUsed, card2memStatus.meTotal);  //huyi-20080504
        mmi_asc_to_ucs2((S8 *) hintData[1], tempBuf);
    }
    else
    {
        mmi_ucs2cpy((S8 *) hintData[1], (S8 *) GetString(STR_SMS_DOES_NOT_SUPPORT));
    }

    hintDataPtrs[0] = hintData[0];
    hintDataPtrs[1] = hintData[1];


    subMenuDataPtrs[0] = (PU8) GetString(STRING_MTPNP_SIM_STORAGE_MENUENTRY);
    subMenuDataPtrs[1] = (PU8) GetString(STRING_MTPNP_ME_STORAGE_MENUENTRY);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_PREFERRED_STORAGE);
    if ((guiBuffer != NULL) || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_MTPNP_MSG_PREFERRED_STORAGE))
    {
        DeleteNScrId(SCR_MTPNP_MSG_PREFERRED_STORAGE);
        hiliteitem = g_msg_cntx.currHiliteIndex;
    }
    else
    {
        if (card2memStatus.prefStorage == 0)
        {
            hiliteitem = 0;
        }
        else
        {
            hiliteitem = 1;
        }
    }
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_MTPNP_MSG_PREFERRED_STORAGE);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_MSG_PREFERRED_STORAGE);

    ShowCategory109Screen(STRING_MTPNP_PREFEREDSTORAGE_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
                          STR_GLOBAL_OK, IMG_GLOBAL_OK,
                          STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                          nNumofItem, subMenuDataPtrs, hintDataPtrs, hiliteitem, guiBuffer);
    SetLeftSoftkeyFunction(mmi_msg_save_card2_preferred_storage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_msg_save_card2_preferred_storage(void)
{
    ClearAllKeyHandler();
    if (((g_msg_cntx.currHiliteIndex == 0) && (card2memStatus.prefStorage == 0))
        || ((g_msg_cntx.currHiliteIndex == 1) && (card2memStatus.prefStorage == 1)))
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else if (((g_msg_cntx.currHiliteIndex == 0) && (card2memStatus.simTotal == 0))
             || ((g_msg_cntx.currHiliteIndex == 1) && (card2memStatus.meTotal == 0)))
    {
        DisplayPopup((PU8) GetString(STR_SMS_DOES_NOT_SUPPORT), IMG_GLOBAL_WARNING, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        if (g_msg_cntx.currHiliteIndex == 0)
        {
            mmi_msg_set_card2_preferred_storage_req(SMSAL_SM_PREFER);
        }
        else if (g_msg_cntx.currHiliteIndex == 1)
        {
            mmi_msg_set_card2_preferred_storage_req(SMSAL_ME_PREFER);
        }
    }
}

static void mmi_msg_set_card2_preferred_storage_req(unsigned char storage)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_sms_set_card2_preferred_storage(mmi_msg_set_card2_preferred_storage_rsp, MOD_MMI, storage);
}

static void mmi_frm_sms_set_card2_preferred_storage(PsFuncPtrU16 callback, module_type mod_src, U8 storage)
{
    U8 *data = OslMalloc(sizeof(U8));

    memset(data, storage, sizeof(U8));
    mmi_frm_sms_write_action(callback, mod_src, data, mmi_frm_sms_set_card2_preferred_storage_req);
}

static void mmi_frm_sms_set_card2_preferred_storage_req(void *inMsg)
{
    ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_REQ msgReq;
    U8 storage = *(U8 *) inMsg;

    msgReq.mem2 = storage;
    msgReq.mem1 = SMSAL_STORAGE_UNSPECIFIED;
#ifdef __MMI_MESSAGES_PREFER_STORAGE_ONLY_FOR_MO_SMS__
    msgReq.mem3 = SMSAL_STORAGE_UNSPECIFIED;
#else 
    msgReq.mem3 = storage;
#endif 

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_PREFERRED_STORAGE_RSP,
                                      mmi_frm_sms_set_card2_preferred_storage_rsp);
    MTPNP_AD_SMS_Set_Prefer_Storage_Req(&msgReq);
}

static void mmi_frm_sms_set_card2_preferred_storage_rsp(void *info)
{
    ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_RSP *msgRsp = (ST_MTPNP_AD_SMS_SET_PREFER_STORAGE_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;
    U8 preferStorage = 0;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_PREFERRED_STORAGE_RSP);
    if ((msgRsp->result) == TRUE)
    {
        if (msgRsp->param.mem2 == SMSAL_SM || msgRsp->param.mem2 == SMSAL_SM_PREFER)
        {
            preferStorage = SMSAL_SM;
        }
        else
        {
            preferStorage = SMSAL_ME;
        }
        result = MMI_FRM_SMS_OK;
    }
    mmi_frm_sms_callback_action((void *) &preferStorage, result);
}

static void mmi_msg_set_card2_preferred_storage_rsp(void *storage, module_type mod, U16 result)
{
    if (result == MMI_FRM_SMS_OK)
    {
        card2memStatus.prefStorage = *(U8 *) storage;
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) SUCCESS_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR), IMG_GLOBAL_UNFINISHED, 1,
                     MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
        DeleteMessagesHistoryNodes();
    }
}

/* message setup preferred storage end */
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */

/* send sms sc begin */
void mmi_frm_sms_get_card2_sc_addr_req(void *inMsg)
{
    MTPNP_UINT8 index = *(U8 *) inMsg;

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_PARAMS_RSP, mmi_frm_sms_get_card2_sc_addr_rsp);
    MTPNP_AD_SMS_Get_Profile_Params_Req(index);
}

static void mmi_frm_sms_get_card2_sc_addr_rsp(void *info)
{
    ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_PROFILE_PARAMS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        if (msgRsp->sc_addr.length == 0)
        {
            mmi_frm_sms_entry_card2_sc();
        }
        else
        {
            sendSMS->sendcheck |= MMI_FRM_SMS_SC;
            mmi_frm_sms_send_sms_req();
        }
    }
    else
    {
        mmi_frm_sms_callback_action(NULL, result);
    }
}

void mmi_frm_sms_entry_card2_sc(void)
{
    U8 *guiBuffer;

    EntryNewScreen(SCR_ID_MSG_SC_NUMBER, NULL, mmi_frm_sms_entry_card2_sc, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SC_NUMBER);
    g_msg_cntx.msg_status = MSG_STATUS_INPUT_NUM;
    GetCurrEndKeyDownHandler();
    RegisterInputBoxEmptyFunction(mmi_frm_sms_sc_empty);
    RegisterInputBoxNotEmptyFunction(mmi_frm_sms_card2_sc_not_empty);

    ShowCategory5Screen(STR_SC_EMPTY_CAPTION_ID, IMG_SMS_ENTRY_SCRN_CAPTION,
                        STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE,
                        STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE,
                        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
                        (U8 *) g_frm_sms_cntx.mmi_frm_sms_number, MAX_DIGITS_SMS, guiBuffer);

    SetCategory5RightSoftkeyFunction(mmi_frm_sms_go_back_from_send, KEY_EVENT_UP);
}

static void mmi_frm_sms_card2_sc_not_empty(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_frm_sms_entry_card2_sc_done, KEY_EVENT_UP);
}

static void mmi_frm_sms_entry_card2_sc_done(void)
{
    S16 errorCode = 0;
    S8 nvramActiveProfileIndex = 0;
    msg_profile_edit_struct *profileSC = NULL;
	S8 scAddress[MAX_DIGITS + 1];

	memset(scAddress, 0, MAX_DIGITS + 1);
    mmi_ucs2_n_to_asc((PS8) scAddress, (PS8) g_frm_sms_cntx.mmi_frm_sms_number, (MAX_CC_ADDR_LEN *ENCODING_LENGTH));
    if (MMI_FALSE == mmi_frm_sms_check_dst_number((U8*)scAddress, (U8)strlen(scAddress)))
    {    	
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

        return;
    }
	profileSC = OslMalloc(sizeof(msg_profile_edit_struct));
    ReadValue(NVRAM_SLAVE_ACTIVE_PROFILE_IDX, &nvramActiveProfileIndex, DS_BYTE, &errorCode);
    profileSC->profileIndex = nvramActiveProfileIndex;
    mmi_ucs2cpy((S8 *) profileSC->scAddress, (S8 *) g_frm_sms_cntx.mmi_frm_sms_number);
    mmi_frm_sms_set_card2_sc_addr_req(profileSC);
    ClearInputEventHandler(MMI_DEVICE_ALL);
    OslMfree(profileSC);
}

static void mmi_frm_sms_set_card2_sc_addr_req(void *inMsg)
{
    ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_REQ *msgReq;
    msg_profile_edit_struct *profile = (msg_profile_edit_struct *) inMsg;
    S8 scAddress[MAX_DIGITS_SMS * ENCODING_LENGTH];
    msgReq = (ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_REQ *) OslConstructDataPtr(sizeof(*msgReq));

    memset(scAddress, 0, MAX_DIGITS_SMS * ENCODING_LENGTH);
    mmi_ucs2_n_to_asc((PS8) scAddress, (PS8) profile->scAddress, MAX_DIGITS_SMS * ENCODING_LENGTH);
    msgReq->profile_no = profile->profileIndex;
    if (scAddress[0] == '+')
    {
        msgReq->sc_addr.type = CSMCC_INTERNATIONAL_ADDR;
        msgReq->sc_addr.length = (strlen(scAddress) > MAX_DIGITS_SMS) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress) - 1);
        memcpy(msgReq->sc_addr.number, scAddress + 1, msgReq->sc_addr.length);
    }
    else
    {
        msgReq->sc_addr.type = CSMCC_DEFAULT_ADDR_TYPE;
        msgReq->sc_addr.length =
            (strlen(scAddress) > (MAX_DIGITS_SMS - 1)) ? (MAX_DIGITS_SMS - 1) : (strlen(scAddress));
        memcpy(msgReq->sc_addr.number, scAddress, msgReq->sc_addr.length);
    }
    memset(&msgReq->sc_addr.number[msgReq->sc_addr.length], 0, 1);
    msgReq->para_ind = SMSAL_PARA_SCA;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_PROFILE_PARAMS_RSP, mmi_frm_sms_set_card2_sc_addr_rsp);
    MTPNP_AD_SMS_Set_Profile_Params_Req(msgReq);
    OslIntFreeDataPtr(msgReq);
}

static void mmi_frm_sms_set_card2_sc_addr_rsp(void *info)
{
    ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_RSP *msgRsp = (ST_MTPNP_AD_SMS_SET_PROFILE_PARAMS_RSP *) info;
    U16 result = MMI_FRM_SMS_ERROR;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_PROFILE_PARAMS_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT,
                             (U8) SUCCESS_TONE, mmi_frm_sms_send_sms_req);
        DeleteScreenIfPresent(SCR_ID_MSG_SC_NUMBER);
        sendSMS->sendcheck |= MMI_FRM_SMS_SC;
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR), IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_MSG_SC_NUMBER);
        mmi_frm_sms_callback_action(NULL, result);
    }
}

/* send sms sc end */

/* sms waiting ind begin */
static void mmi_msg_handle_card2_msg_waiting_ind(void *info)
{
    ST_MTPNP_AD_SMS_MSG_WAITING_IND *msgInd = (ST_MTPNP_AD_SMS_MSG_WAITING_IND *) info;
	kal_prompt_trace(MOD_MMI, "mmi_msg_handle_card2_msg_waiting_ind msgInd->is_clear=%d", msgInd->is_clear);
    if (msgInd->is_clear)
    {
    	if (g_msg_cntx.msg_waiting_line_number == msgInd->line_no && g_msg_cntx.msg_waiting_ind == msgInd->ind_type + 1		
		&& g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].isSlave == TRUE)
		{
			if (GetMessagesCurrScrnID() == SCR_ID_MSG_MSG_WAITING_IND)
			{
				mmi_msg_go_back_from_msg_waiting_ind();
			}
			g_msg_cntx.msg_waiting_ind = 0;
		}
	        g_msg_cntx.msg_waiting_info[(msgInd->line_no)].number[msgInd->ind_type] = 0;	        
        mmi_msg_set_card2_msg_waiting_icon(msgInd->line_no, msgInd->ind_type, 0);
    }
    else
    {
        mmi_msg_set_card2_msg_waiting_icon(msgInd->line_no, msgInd->ind_type, 1);

        g_msg_cntx.msg_waiting_info[(msgInd->line_no)].number[msgInd->ind_type] = msgInd->waiting_num;
		g_msg_cntx.msg_waiting_info[(msgInd->line_no)].isSlave = TRUE;

        if (msgInd->is_from_storage)
        {
            return;
        }

        g_msg_cntx.msg_waiting_is_show_number = msgInd->is_show_num;
        g_msg_cntx.msg_waiting_line_number = msgInd->line_no;

        mmi_msg_card2_msg_waiting_ind(msgInd->ind_type);
    }
}

static void mmi_msg_set_card2_msg_waiting_icon(unsigned char line, unsigned char type, unsigned char set)
{
    U8 i = 0;
    U8 otherline = (line == 0 ? 1 : 0);
    U16 icon[] = {
        STATUS_ICON_UNREAD_VOICE_L1_SLAVE,
        STATUS_ICON_UNREAD_VOICE_L2_SLAVE,
        STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
        STATUS_ICON_UNREAD_FAX_L1_SLAVE,
        STATUS_ICON_UNREAD_FAX_L2_SLAVE,
        STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_L1_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_L2_SLAVE,
        STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
        STATUS_ICON_UNREAD_NET_L1_SLAVE,
        STATUS_ICON_UNREAD_NET_L2_SLAVE,
        STATUS_ICON_UNREAD_NET_L1L2_SLAVE,
    };

	kal_prompt_trace(MOD_MMI, "mmi_msg_set_card2_msg_waiting_icon line=%d", line);
	kal_prompt_trace(MOD_MMI, "mmi_msg_set_card2_msg_waiting_icon type=%d", type);
	kal_prompt_trace(MOD_MMI, "mmi_msg_set_card2_msg_waiting_icon set=%d", set);
    for (i = 0; i < (MAX_WAITING_LINE_NUM + 1); i++)
    {
        IdleResetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + i]);
		MTPNP_PFAL_Reset_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + i]);
    }
    if ((set > 0) && (g_msg_cntx.msg_waiting_info[otherline].number[type]))
    {
    	if (mmi_frm_sms_is_sms_valid() && mmi_bootup_is_sim2_valid())
		{
			IdleSetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + MAX_WAITING_LINE_NUM]);
		}        
		MTPNP_PFAL_Set_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + MAX_WAITING_LINE_NUM]);
    }
    else if (set > 0)
    {
    	if (mmi_frm_sms_is_sms_valid() && mmi_bootup_is_sim2_valid())
		{
			IdleSetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + line]);
		}        
		MTPNP_PFAL_Set_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + line]);
    }
    else if (g_msg_cntx.msg_waiting_info[otherline].number[type])
    {
    	if (mmi_frm_sms_is_sms_valid() && mmi_bootup_is_sim2_valid())
		{
			IdleSetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + otherline]);
		}        
		MTPNP_PFAL_Set_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + otherline]);
    }
}

static void mmi_msg_card2_msg_waiting_ind(unsigned char type)
{
    g_msg_cntx.msg_waiting_ind = type + 1;
    TurnOnBacklight(1);

    if (IsMMIInIdleState() || (GetMessagesCurrScrnID() == SCR_ID_MSG_MSG_WAITING_IND))
    {
    	mmi_msg_set_msg_type_as_slave();
        PlayMessageArrivalTone();
        ClearKeyEvents();
        if (IsKeyPadLockState())
        {
            EntryIdleScreen();
        }
        else
        {
            mmi_msg_entry_card2_msg_waiting_ind();
        }
    }
    else
    {
        if (!MTPNP_PFAL_CC_GetDGTotalCallCount() && !AlmIsTonePlaying())
        {
        	mmi_msg_set_msg_type_as_slave();
            mmi_msg_entry_new_msg_popup(g_msg_cntx.msg_waiting_ind);
        }
    }
}

static void mmi_msg_entry_card2_msg_waiting_ind(void)
{
    U8 *tempstr = mmi_msg_get_card2_msg_waiting_msg();

    EntryNewScreen(SCR_ID_MSG_MSG_WAITING_IND, mmi_msg_stop_msg_sub_anm, NULL, NULL);
    SetMessagesCurrScrnID(SCR_ID_MSG_MSG_WAITING_IND);
    ForceSubLCDScreen(mmi_msg_start_msg_sub_anm);


    GetCurrEndKeyDownHandler();
    ShowCategory141Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                          (U8 *) tempstr, IMG_NEW_VOICEMAIL_NOTIFICATION_MSG, NULL);

    SetRightSoftkeyFunction(mmi_msg_go_back_from_card2_msg_waiting_ind, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_end_key_from_card2_msg_waiting_ind, KEY_END, KEY_EVENT_DOWN);
}

static unsigned char *mmi_msg_get_card2_msg_waiting_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *tempStr = NULL;
    U8 ascii_num[16];
    U16 num = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].number[g_msg_cntx.msg_waiting_ind - 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (card2strBuff != NULL)
    {
        OslMfree(card2strBuff);
        card2strBuff = NULL;
    }
    card2strBuff = OslMalloc(64);

	if (g_msg_cntx.msg_waiting_is_show_number)
	{

        memset(ascii_num, 0, 16);
        sprintf((S8*) ascii_num, "%d ", num);
        mmi_asc_to_ucs2((S8*) card2strBuff, (S8*) ascii_num);

        switch (g_msg_cntx.msg_waiting_ind)
        {
            case MSG_NEW_VOICEMAIL:
                tempStr = (U8*) GetString((U16) STRING_MTPNP_SLAVE_VOICEMAIL_NUM_IND);
                break;
            case MSG_NEW_FAX:
                tempStr = (U8*) GetString((U16) STRING_MTPNP_SLAVE_FAX_NUM_IND);
                break;
            case MSG_NEW_EMAIL:
                tempStr = (U8*) GetString((U16) STRING_MTPNP_SLAVE_EMAIL_NUM_IND);
                break;
            default:
                tempStr = (U8*) GetString((U16) STRING_MTPNP_SLAVE_NET_OTHER_NUM_IND);
                break;
        }
        mmi_ucs2cat((S8*) card2strBuff, (S8*) tempStr);
    }
    else
    {
	    switch (g_msg_cntx.msg_waiting_ind)
	    {
		    case MSG_NEW_VOICEMAIL:
		        tempStr = (U8 *) GetString((U16) STRING_MTPNP_SLAVE_VOICEMAIL_IND);
		        break;
		    case MSG_NEW_FAX:
		        tempStr = (U8 *) GetString((U16) STRING_MTPNP_SLAVE_FAX_IND);
		        break;
		    case MSG_NEW_EMAIL:
		        tempStr = (U8 *) GetString((U16) STRING_MTPNP_SLAVE_EMAIL_IND);
		        break;
		    case MSG_NEW_NETOTHER:
		        tempStr = (U8 *) GetString((U16) STRING_MTPNP_SLAVE_NET_OTHER_IND);
		        break;
		    default:
		        tempStr = (U8 *) GetString((U16) STRING_MTPNP_SLAVE_VOICEMAIL_IND);
		        break;
    	}
        mmi_ucs2cpy((S8 *) card2strBuff, (S8 *) tempStr);   	
    }
	
    return card2strBuff;
}

static void mmi_msg_go_back_from_card2_msg_waiting_ind(void)
{
    g_msg_cntx.msg_waiting_ind = 0;
    if (card2strBuff != NULL)
    {
        OslMfree(card2strBuff);
        card2strBuff = NULL;
    }
    GoBackHistory();
}

static void mmi_msg_end_key_from_card2_msg_waiting_ind(void)
{
    g_msg_cntx.msg_waiting_ind = 0;
    if (card2strBuff != NULL)
    {
        OslMfree(card2strBuff);
        card2strBuff = NULL;
    }
    ExecCurrEndKeyDownHandler();
}

/* sms waiting ind end */

/* sms show begin */
static void HighlightDividedInboxHandler(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_entry_divided_inbox_menu, GoBackHistory);
}

static void mmi_msg_entry_divided_inbox_menu(void)
{
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_MSG_INBOX, NULL, mmi_msg_entry_divided_inbox_menu,
                         MESSAGES_MENU_INBOX_MENUID, STR_INBOX_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION);
	SetMessagesCurrScrnID(SCR_MTPNP_DM_MSG_INBOX);
}

static void HighlightDividedOutboxHandler(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK, IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_entry_divided_outbox_menu, GoBackHistory);
}

static void mmi_msg_entry_divided_outbox_menu(void)
{
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_MSG_OUTBOX, NULL, mmi_msg_entry_divided_outbox_menu,
                         MESSAGES_MENU_OUTBOX_MENUID, STR_OUTBOX_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION);
	SetMessagesCurrScrnID(SCR_MTPNP_DM_MSG_OUTBOX);
}

static void HighlightMasterInboxHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_master_inbox_list, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_pre_entry_master_inbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void HintMasterInboxHandler(U16 index)
{
    S8 LocalData[10];
    U16 size = init_sms_show_list_index(MMI_FRM_SMS_INBOX, MTPNP_AD_FILTER_MASTER);

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    if (MMI_FRM_SMS_INVALID_INDEX != size)
    {
	 	sprintf(LocalData, "%d ", size);
	    mmi_asc_to_ucs2((PS8) hintData[index], LocalData);
	    mmi_ucs2cat((PS8) hintData[index], GetString(STR_SMS_COUNT_POPUP_SUFFIX));
    }   
}

static void HighlightSlaveInboxHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_slave_inbox_list, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_pre_entry_slave_inbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void HintSlaveInboxHandler(U16 index)
{
    S8 LocalData[10];
    U16 size = init_sms_show_list_index(MMI_FRM_SMS_INBOX, MTPNP_AD_FILTER_SLAVE);

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    if (MMI_FRM_SMS_INVALID_INDEX != size)
    {
    	sprintf(LocalData, "%d ", size);
    	mmi_asc_to_ucs2((PS8) hintData[index], LocalData);
    	mmi_ucs2cat((PS8) hintData[index], GetString(STR_SMS_COUNT_POPUP_SUFFIX));
    }

}

static void HighlightMasterOutboxHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_master_outbox_list, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_pre_entry_master_outbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void HintMasterOutboxHandler(U16 index)
{
    S8 LocalData[10];
    U16 size = init_sms_show_list_index(MMI_FRM_SMS_OUTBOX, MTPNP_AD_FILTER_MASTER);

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    if (MMI_FRM_SMS_INVALID_INDEX != size)
    {
	    sprintf(LocalData, "%d ", size);
	    mmi_asc_to_ucs2((PS8) hintData[index], LocalData);
	    mmi_ucs2cat((PS8) hintData[index], GetString(STR_SMS_COUNT_POPUP_SUFFIX));
    } 
}

static void HighlightSlaveOutboxHandler(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_slave_outbox_list, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_pre_entry_slave_outbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void HintSlaveOutboxHandler(U16 index)
{
    S8 LocalData[10];
    U16 size = init_sms_show_list_index(MMI_FRM_SMS_OUTBOX, MTPNP_AD_FILTER_SLAVE);

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    if (MMI_FRM_SMS_INVALID_INDEX != size)
    {
	    sprintf(LocalData, "%d ", size);
	    mmi_asc_to_ucs2((PS8) hintData[index], LocalData);
	    mmi_ucs2cat((PS8) hintData[index], GetString(STR_SMS_COUNT_POPUP_SUFFIX));    
    }
}

static U16 init_sms_show_list_index(U8 box_type, E_MTPNP_AD_FILTER_RULE rule)
{
    U16 box_size;
    U16 show_size = 0;
    U16 i = 0;

    box_size = mmi_frm_sms_get_sms_list_size(box_type);
    if (box_size == MMI_FRM_SMS_INVALID_INDEX)
    {
        return MMI_FRM_SMS_INVALID_INDEX;
    }

    memset((S8 *) mmi_frm_sms_show_list_index, MMI_FRM_SMS_INVALID_NUM,
           sizeof(U16) * g_frm_sms_cntx.mmi_frm_sms_msg_box_size);
    switch (rule)
    {
    case MTPNP_AD_FILTER_ALL:
        show_size = box_size;
        break;

    case MTPNP_AD_FILTER_MASTER:
        for (i = 0; i < box_size; i++)
        {
            if (!mmi_frm_sms_record_is_slave_sms(box_type, i))
            {
                mmi_frm_sms_show_list_index[show_size++] = i;
            }
        }
        break;

    case MTPNP_AD_FILTER_SLAVE:
        for (i = 0; i < box_size; i++)
        {
            if (mmi_frm_sms_record_is_slave_sms(box_type, i))
            {
                mmi_frm_sms_show_list_index[show_size++] = i;
            }
        }
        break;
    }
    PRINT_INFORMATION("[LJH]box_type=%d, box_size=%d, rule=%d, show_size=%d", box_type, box_size, rule, show_size);

    return show_size;
}

void MTPNP_PFAL_SMS_Init_Show_Style(void)
{
    U8 style;
    S16 error;

    ReadValue(NVRAM_MTPNP_SMS_SHOW_STYLE, &style, DS_BYTE, &error);
    if (style != MTPNP_AD_SHOW_DIVIDED)
    {
        style = MTPNP_AD_SHOW_DIVIDED;
        WriteValue(NVRAM_MTPNP_SMS_SHOW_STYLE, &style, DS_BYTE, &error);
    }

    MTPNP_AD_SMS_Set_Show_Style(style);
    switch (style)
    {
    case MTPNP_AD_SHOW_MIXED:
        SetHiliteHandler(MESSAGES_MENU_INBOX_MENUID, HighlightInboxHandler);
        SetHintHandler(MESSAGES_MENU_INBOX_MENUID, HintInboxHandler);
        SetHiliteHandler(MESSAGES_MENU_OUTBOX_MENUID, HighlightOutboxHandler);
        SetHintHandler(MESSAGES_MENU_OUTBOX_MENUID, HintOutboxHandler);
        break;

    case MTPNP_AD_SHOW_DIVIDED:
        SetHiliteHandler(MESSAGES_MENU_INBOX_MENUID, HighlightDividedInboxHandler);
        SetHintHandler(MESSAGES_MENU_INBOX_MENUID, NULL);
        SetHiliteHandler(MESSAGES_MENU_OUTBOX_MENUID, HighlightDividedOutboxHandler);
        SetHintHandler(MESSAGES_MENU_OUTBOX_MENUID, NULL);
        break;
    }
}

static void mmi_msg_highlight_show_style(void)
{
    mmi_msg_highlight_generic(STR_GLOBAL_OK,
                              IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_entry_show_style, GoBackHistory);
}

static void mmi_msg_hint_show_style(U16 index)
{
    PU8 ShowStr;

    if (MTPNP_AD_SMS_Get_Show_Style() == MTPNP_AD_SHOW_MIXED)
    {
        ShowStr = (PU8) GetString((U16) STRING_MTPNP_SMS_SHOW_MIXED);
    }
    else
    {
        ShowStr = (PU8) GetString((U16) STRING_MTPNP_SMS_SHOW_DIVIDED);
    }
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) ShowStr);
}

static void mmi_msg_entry_show_style(void)
{
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    S32 hiliteitem;

    EntryNewScreen(SCR_MTPNP_SMS_SHOW_STYLE, mmi_msg_exit_generic, mmi_msg_entry_show_style, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_SMS_SHOW_STYLE);
    nNumofItem = GetNumOfChild(MENU_MTPNP_SMS_SHOW_STYLE);
    GetSequenceStringIds(MENU_MTPNP_SMS_SHOW_STYLE, nStrItemList);
    SetParentHandler(MENU_MTPNP_SMS_SHOW_STYLE);
    if (guiBuffer != NULL)
    {
        hiliteitem = g_msg_cntx.currHiliteIndex;
    }
    else
    {
        hiliteitem = (S32) MTPNP_AD_SMS_Get_Show_Style();
    }
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_MTPNP_SMS_SHOW_STYLE);
    SetMessagesScrnIdToDelHistoryNodes(SCR_MTPNP_SMS_SHOW_STYLE);

    ShowCategory11Screen(STRING_MTPNP_SMS_SHOW_STYLE,
                         IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16) hiliteitem, guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_save_show_style, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

static void mmi_msg_save_show_style(void)
{
    U8 style = g_msg_cntx.currHiliteIndex;
    S16 error;

    if (g_msg_cntx.currHiliteIndex != MTPNP_AD_SMS_Get_Show_Style())
    {
        WriteValue(NVRAM_MTPNP_SMS_SHOW_STYLE, &style, DS_BYTE, &error);
        MTPNP_PFAL_SMS_Init_Show_Style();
    }
    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT, (U8) SUCCESS_TONE);
    DeleteUptoScrID(SCR_MTPNP_DM_MSG_SETTINGS);
}

void mmi_msg_pre_entry_master_inbox_list(void)
{
    MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_MASTER);
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == 0)
    {
        DisplayPopup((U8 *) GetString(STR_GLOBAL_EMPTY),
                     IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT, (U8) EMPTY_LIST_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION,
                                      STR_LOADING_SMS, IMG_GLOBAL_PROGRESS, STR_LOADING_INBOX_BACK);
        mmi_msg_entry_processing_generic();
        /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_inbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                     IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
    }
    else
    {
        mmi_msg_entry_inbox_list();
    }

}

void mmi_msg_pre_entry_slave_inbox_list(void)
{
    MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_SLAVE);
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == 0)
    {
        DisplayPopup((U8 *) GetString(STR_GLOBAL_EMPTY),
                     IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT, (U8) EMPTY_LIST_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION,
                                      STR_LOADING_SMS, IMG_GLOBAL_PROGRESS, STR_LOADING_INBOX_BACK);
        mmi_msg_entry_processing_generic();
        /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_inbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                     IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
    }
    else
    {
        mmi_msg_entry_inbox_list();
    }
}

void mmi_msg_pre_entry_master_outbox_list(void)
{
    MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_MASTER);

    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == 0)
    {
        DisplayPopup((U8 *) GetString(STR_GLOBAL_EMPTY),
                     IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT, (U8) EMPTY_LIST_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION,
                                      STR_LOADING_SMS, IMG_GLOBAL_PROGRESS, STR_LOADING_OUTBOX_BACK);
        mmi_msg_entry_processing_generic();
        /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_outbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                     IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
    }
    else
    {
        mmi_msg_entry_outbox_list();
    }

}

void mmi_msg_pre_entry_slave_outbox_list(void)
{
    MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_SLAVE);
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == 0)
    {
        DisplayPopup((U8 *) GetString(STR_GLOBAL_EMPTY),
                     IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT, (U8) EMPTY_LIST_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION,
                                      STR_LOADING_SMS, IMG_GLOBAL_PROGRESS, STR_LOADING_OUTBOX_BACK);
        mmi_msg_entry_processing_generic();
        /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_outbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup((PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                     IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (U8) ERROR_TONE);
    }
    else
    {
        mmi_msg_entry_outbox_list();
    }
}

U16 MTPNP_PFAL_SMS_Get_SMS_List_Size(U8 type)
{
    U16 result = 0;

    result = init_sms_show_list_index(type, MTPNP_AD_SMS_Get_Filter_Rule());
    return result;
}

void MTPNP_PFAL_SMS_Set_Current_Index(S32 nIndex)
{
    if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_ALL)
    {
        g_msg_cntx.currBoxIndex = nIndex;
    }
    else
    {
        g_msg_cntx.currBoxIndex = mmi_frm_sms_show_list_index[nIndex];
    }

    sms_show_list_currIndex = nIndex;
}

S32 MTPNP_PFAL_SMS_Get_Current_Index(void)
{
	U16 i = 0;
	
	if (g_msg_cntx.currBoxIndex != MMI_FRM_SMS_INVALID_INDEX && 
		g_msg_cntx.currBoxIndex != mmi_frm_sms_show_list_index[sms_show_list_currIndex])
	{
		for (i = 0; i < MMI_SMS_MAX_MSG_NUM; i++)
		{
			if (g_msg_cntx.currBoxIndex == mmi_frm_sms_show_list_index[i])
			{
				sms_show_list_currIndex = i;
				break;
			}
		}
	}
    return sms_show_list_currIndex;
}

/*****************************************************************************
 * FUNCTION
 *  RefreshSMSDividedMenuList
 * DESCRIPTION
 *  Refresh SMS divide menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RefreshSMSDividedMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MTPNP_AD_SMS_Get_Show_Style() == MTPNP_AD_SHOW_DIVIDED)
	{
	    if (GetMessagesCurrScrnID() == SCR_MTPNP_DM_MSG_INBOX)
	    {
	        S32 menuItemId = -1;

	        menuItemId = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_INBOX_MENUID, MENU_MTPNP_SMS_MASTER_INBOX);
	        if (menuItemId != -1)
	        {
	        	HintMasterInboxHandler((U16)menuItemId);        	
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, (U8*)hintData[menuItemId]);
				
	        }
	        menuItemId = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_INBOX_MENUID, MENU_MTPNP_SMS_SLAVE_INBOX);
	        if (menuItemId != -1)
	        {
	       		HintSlaveInboxHandler((U16)menuItemId);        	
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, (U8*)hintData[menuItemId]);
	        }
			RedrawCategoryFunction();
	    }
	    if (GetMessagesCurrScrnID() == SCR_MTPNP_DM_MSG_OUTBOX)
	    {
	        S32 menuItemId = -1;

	        menuItemId = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_OUTBOX_MENUID, MENU_MTPNP_SMS_MASTER_OUTBOX);
	        if (menuItemId != -1)
	        {
	       		HintMasterOutboxHandler((U16)menuItemId);        	
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, (U8*)hintData[menuItemId]);
	        }
	        menuItemId = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_OUTBOX_MENUID, MENU_MTPNP_SMS_SLAVE_OUTBOX);
	        if (menuItemId != -1)
	        {
	        	HintSlaveOutboxHandler((U16)menuItemId);        	
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, (U8*)hintData[menuItemId]);
	        }
			RedrawCategoryFunction();
	    }
		
	}
}
/* sms show end */

#endif /* __MMI_DUAL_SIM_MASTER__ */

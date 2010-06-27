#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "GlobalDefs.h"
#include "GlobalConstants.h"
#include "EventsGprot.h"
#include "CustMenuRes.h"
#include "CustDataRes.h"
#include "wgui_categories.h"
#include "Wgui_categories_util.h"
#include "HistoryGprot.h"
#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "SettingDefs.h"
#include "SettingProfile.h"
#include "HistoryGprot.h"
#include "mainmenudef.h"
#include "CommonScreens.h"
#include "wgui_categories_inputsenum.h"
#include "SimDetectionDef.h"
#include "StdC.h"
#include "L4Dr1.h"
#include "L4Dr.h"
#include "FrameworkStruct.h"
#include "NetworkSetupDefs.h"
#include "NetworkSetupGProt.h"
#include "DebugInitDef.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "SettingProfile.h"
#include "SettingDefs.h"
#include "PrefNwksGprot.h"
#include "CommonScreens.h"
#include "MessagesExDcl.h"
#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
#include "MessagesResourceData.h"
#include "PreferredNwksStruct.h"
#include "PrefNwksGprot.h"
#include "StatusIconRes.h"
#include "CustResDef.h"
#include "nvram_enums.h"
#include "nvram_interface.h"
#include "CallManagementGprot.h"    /* IsInCall */
#include "CSP.h"    /* add for CPHS interface */

#include "MTPNP_AD_master_header.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "MTPNP_PFAL_Network.h"
#include "MTPNP_AD_resdef.h"

/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
/* network setup menu begin */
static void HighlightDMNETSETMain(void);
static void EntryDMNETSETMain(void);
static void HighlightCard2NETSETMain(void);
static void EntryCard2NETSETMain(void);
/* network setup menu end */

/* network setup msg queue begin */
static void NETSETCard2MsgQueuePush(U8 ItemType, FuncPtr CallBackFunc, U16 MsgID, PsFuncPtr CallBackRspHandler);
static void NETSETCard2MsgQueueProtocolHandler(void *info);
static void NETSETCard2MsgQueueTopAddOne(void);
static void NETSETCard2MsgQueueTopMinusOne(void);
static void NETSETCard2MsgQueueIndexAddOne(void);
static U8 NETSETCard2MsgQueueGetPreviousIndex(void);
static U8 NETSETCard2MsgQueueGetPreviousTop(void);
static U8 NETSETCard2MsgQueueCheckCurrOP(void);
static U8 NETSETCard2MsgQueueCheckLastOP(void);
/* network setup msg queue end */

/* network selection mode begin */
static void HighlightCard2NETSETSelectionMode(void);
static void HintCard2NETSETSelectionMode(U16 index);
static void EntryCard2NETSETSelectionMode(void);
static void ExitCard2NETSETSelectionMode(void);
static void NETSETCheckAndRestoreCard2Network(void);
static void RestorePreviousCard2Network(void);
static void NETSETCard2ManualNetworkRestoreReq(void);
/* network selection mode end */

/* preferred networks show begin */
static void HighlightCard2NETSETPreferredNetworks(void);
static void NETSETGetCard2PreferredNetworkReq(void);
static void NETSETGetCard2PreferredNetworkRsp(void *info);
static void EntryCard2NETSETShowPreferredList(void);
static U16 GetCard2PrefNwkNameFromPLMN(void);
static void HiliteCard2HandlerPrefList(S32 hiliteIdx);
static void ConstructCard2PreferredListHint(U8 ** hintArray);
static void EntryCard2NETSETShowPrefNwkOptions(void);
static void GoBackCard2NetworkSetup(void);
#ifndef __MMI_KEEP_ORI_STYLE__
static void HiliteCard2HandlerPrefNwkHideAddIfFull(S32 index);
#endif
/* preferred networks show end */

/* network selection manual beign */
static void HighlightCard2NETSETSelectionManual(void);
static void NETSETGetCard2PLMNListCheck(void);
static void NETSETCard2GetPLMNListReq(void);
static void NETSETCard2GetPLMNListRsp(void *info);
static void EntryCard2NETSETManualSearchProgress(void);
static void NETSETAbortCard2PLMNListReq(void);
static void NETSETAbortCard2PLMNListRsp(void *info);
static void AbortCard2GetPLMNListToIdle(void);
/* network selection manual end */

/* network selection manual list begin */
static void EntryCard2NETSETShowPlmnList(void);
static void ExitCard2NETSETShowPLMNList(void);
static void HiliteCard2HandlerShowPLMNList(S32 index);
static void GoBackCard2NetSelection(void);
static void NETSETCard2ManualSelectNetworkCheck(void);
static void NETSETCard2ManualSelectNetworkReq(void);
static void NETSETCard2ManuSelectNetworkRsp(void *info);
static void EntryCard2NETSETManualRegProgress(void);
static void AbortCard2ManualRegGoBack(void);
static void AbortCard2ManualRegToIdle(void);
/* network selection manual list end */

/* network selection auto beign */
static void HighlightCard2NETSETSelectionAuto(void);
static void NETSETCard2AutoSelectNetworkCheck(void);
static void NETSETCard2AutoNetworkSearchReq(void);
static void NETSETCard2AutoNetworkSearchRsp(void *info);
static void EntryCard2NETSETAutoSearchProgress(void);
static void AbortCard2AutoSearchGoBack(void);
static void AbortCard2AutoSearchToIdle(void);
/* network selection auto end */

#ifdef __MANUAL_MODE_NW_SEL__
static void HighlightCard2NETSETSelectionModeChoice(void);
static void EntryCard2NETSETSelectionModeReq(void);
static void EntryCard2NETSETSelectionModeRsp(void *info);
#endif

#ifdef __MMI_GPRS_FEATURES__
static void HighlightNETSETCard2GPRSConnectionMode(void);
static void HintNETSETCard2GPRSConnectionMode(U16 index);
static void NETSETCard2SetGPRSConnModeRspTimeoutHdlr(void);
static void NETSETCard2SetGPRSConnModeRspFailure(void);
static void NETSETCard2SetGPRSConnModeReq(void);
static void NETSETCard2SetGPRSConnModeTimeOut(void);
static void NETSETCard2SetGPRSConnModeRsp(void *info);
extern void NETSETCard2GetGPRSModeRsp(void* info);
extern void NETSETCard2GetGPRSModeReq(void);
#endif

/* preferred networks add list begin */
static void HighlightCard2NETSETAddPrefNwk(void);
static void EntryCard2NETSETAddNetworkPLMNList(void);
static void mmi_netset_card2_sort_plmn_list_by_alphabet(U16 total_record);
static S16 mmi_netset_card2_sort_2_entry_comapre(U16 bcd_a, U16 bcd_b);
static void mmi_netset_card2_sort_insert_new_entry(U16 index, U16 reference);
static void mmi_netset_card2_sort_plmn_list_by_default(U16 total_record);
static void HiliteCard2HandlerAddNetworkPLMNList(S32 hiliteIdx);
static pBOOL NETSETGetCard2PrefNetworkListItem(S32 item_index, UI_string_type str_buff, UI_image_type * img_buff_p,
                                               U8 str_img_mask);
static S32 NETSETGetCard2PrefNetworkListHint(S32 item_index, UI_string_type * hint_array);
/* preferred networks add list end */

/* preferred networks add options begin */
static void mmi_netset_card2_entry_add_from_list_options(void);
static void mmi_netset_card2_highlight_add_from_list_done(void);
static void mmi_netset_card2_entry_add_from_list_done(void);
static void mmi_netset_card2_highlight_sort_by_default(void);
static void mmi_netset_card2_entry_sort_by_default(void);
static void mmi_netset_card2_highlight_sort_by_alphabet(void);
static void mmi_netset_card2_entry_sort_by_alphabet(void);
/* preferred networks add options end */

/* preferred networks add priority, req&rsp begin */
static void EntryCard2NETSETAddNetworkPriority(void);
static void CheckThenAddCard2Network(void);
static U8 IsCard2NetworkDuplicated(void);
static void NETSETAddCard2PrefNetworkReq(void);
static void NETSETAddCard2PrefNetworkRsp(void *info);
static void ExitCard2NETSETShowPreferredListReGet(void);
/* preferred networks add priority, req&rsp end */

/* preferred networks new begin */
static void HighlightCard2NETSETNewPrefNwk(void);
static void EntryCard2NETSETNewNetwork(void);
static void ExitCard2NETSETNewNetwork(void);
static void FillCard2NewPrefNetworkInlineEditStruct(void);
/*
static U8 *InLinePriorityCard2Default(void);
static U8 *InLinePriorityCard2MinusOne(void);
static U8 *InLinePriorityCard2AddOne(void);
*/
static void HighlightCard2NewEntryHandler(S32 index);
static void SendCard2NewPrr(void);
/* preferred networks new end */

/* preferred networks delete begin */
static void HighlightCard2NETSETDelPrefNwk(void);
static void EntryCard2NETSETConfirmDeleteNetwork(void);
static void NETSETDeleteCard2PrefNetworkReq(void);
static void NETSETDeleteCard2PrefNetworkRsp(void *info);
/* preferred networks delete end */

/* preferred networks edit begin */
static void HighlightCard2NETSETEditPrefNwk(void);
static void EntryCard2NETSETEditNetwork(void);
static void NETSETCard2EditNetworkDeletePhaseReq(void);
static void NETSETCard2EditNetworkDeletePhaseRsp(void *info);
static void NETSETCard2EditNetworkAddPhaseReq(void);
static void NETSETCard2EditNetworkAddPhaseRsp(void *info);
/* preferred networks edit end */

static void mmi_netset_add_to_card2_plmn_list(U8* plmn_id);
static void mmi_netset_remove_from_card2_plmn_list(U8* plmn_id);
static U8 mmi_netset_find_in_card2_plmn_list(U8* plmn_id);


static void MTPNP_PFAL_NITZ_Ind(void *inMsg);
/**************************LOCAL*FUNCTION*DECLARE*END*************************/
/* 2006/02/16 USIM preferred network implementation */
extern S8 *gServiceString[3];   /* inline selection between 'GSM/GPRS', 'WCDMA', or 'Dual Mode' */

extern MTPNP_UCHAR g_slave_nw_providername[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
extern MTPNP_UCHAR g_slave_operatorname[MAX_LENGTH_OPERATOR_NAME * ENCODING_LENGTH];
extern MTPNP_UCHAR g_slave_servprovderName[MAX_LENGTH_SERVICE_PROVIDER * ENCODING_LENGTH];

extern U8 gPLMN_2[];

static PrefNetworkListContext gCard2PrefList = { 0 };
static PrefNetworkListDisplay gCard2PrefListDisplay = { 0 };
static NetworkSetupContext gCard2NetworkSetup = { 0 };
static NetworkSetupDisplay gCard2NetworkSetupDisplay = { 0 };
static NetworkSetupMsgQueue gCard2NetworkSetupMsgQueue = { 0 };
static U8 NITZ_NWFullName[MAX_NW_LEN *ENCODING_LENGTH];
static U8 NITZ_NWShortName[MAX_NW_LEN *ENCODING_LENGTH];

static U8 gCard2PrefListDelFlag;

void MTPNP_PFAL_Network_Init(void)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_NETWORK_ATTACH_IND, MTPNP_PFAL_Slave_Network_Attach);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_OPN_LOADED, MTPNP_PFAL_Slave_OPN_Loaded);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SPN_LOADED, MTPNP_PFAL_Slave_SPN_Loaded);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_PWRON_MASTER_RF, MTPNP_PFAL_PwrOn_MasterRF);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_PWROFF_MASTER_RF, MTPNP_PFAL_PwrOff_MasterRF);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_NW_TIME_ZONE_IND, MTPNP_PFAL_NITZ_Ind);
    MTPNP_PFAL_Network_Setup_Init();
}

void MTPNP_PFAL_Slave_Network_Attach(void *inMsg)
{
    MTPNP_PFAL_Refresh_Card2_Owner_Number();
    /* Update roaming state */
    if (MTPNP_AD_Card2_IsRoam())
    {
        IdleSetStatusIcon(STATUS_ICON_SLAVE_ROAMING);
    }
    else
    {
        IdleResetStatusIcon(STATUS_ICON_SLAVE_ROAMING);
    }
}

void MTPNP_PFAL_Slave_OPN_Loaded(void *inMsg)
{
    ST_MTPNP_DATA_TEF_CONTENT * tef_content = (ST_MTPNP_DATA_TEF_CONTENT *) inMsg;

    MTPNP_OSAL_memset(g_slave_operatorname, 0, MAX_LENGTH_OPERATOR_NAME * ENCODING_LENGTH);

    if (tef_content != MTPNP_NULL)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *)g_slave_operatorname,
                                                                        (MTPNP_CHAR *)(tef_content->content));
    }
}

void MTPNP_PFAL_Slave_SPN_Loaded(void *inMsg)
{
    ST_MTPNP_DATA_TEF_CONTENT * tef_content = (ST_MTPNP_DATA_TEF_CONTENT *) inMsg;

    MTPNP_OSAL_memset(g_slave_servprovderName, 0, MAX_LENGTH_SERVICE_PROVIDER * ENCODING_LENGTH);

    if (tef_content != MTPNP_NULL)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *)g_slave_servprovderName,
                                                                        (MTPNP_CHAR *)(tef_content->content));
    }
}

void MTPNP_PFAL_Network_Setup_Init(void)
{
    SetHiliteHandler(MENU_MTPNP_DM_NETWORK_SETUP, HighlightDMNETSETMain);
    SetHiliteHandler(MENU_MTPNP_NETWORK_SETUP, HighlightCard2NETSETMain);
    SetHiliteHandler(MENU_MTPNP_SELECTION_MODE, HighlightCard2NETSETSelectionMode);
    SetHintHandler(MENU_MTPNP_SELECTION_MODE, HintCard2NETSETSelectionMode);    /* hint */
    SetHiliteHandler(MENU_MTPNP_PREFERRED_NETWORKS, HighlightCard2NETSETPreferredNetworks);
    SetHiliteHandler(MENU_MTPNP_SELECTION_MODE_MANUAL, HighlightCard2NETSETSelectionManual);
    SetHiliteHandler(MENU_MTPNP_SELECTION_MODE_AUTOMATIC, HighlightCard2NETSETSelectionAuto);
#ifdef __MANUAL_MODE_NW_SEL__
    SetHiliteHandler(MENU_MTPNP_SELECTION_MODE_CHOICE, HighlightCard2NETSETSelectionModeChoice);
    SetHintHandler(MENU_MTPNP_SELECTION_MODE_CHOICE, HintCard2NETSETSelectionMode);     /* hint */
#endif
#ifdef __MMI_GPRS_FEATURES__
    SetHiliteHandler(MENU_MTPNP_GPRS_CONNECTION, HighlightNETSETCard2GPRSConnectionMode);
    SetHintHandler(MENU_MTPNP_GPRS_CONNECTION, HintNETSETCard2GPRSConnectionMode);
#endif /* __MMI_GPRS_FEATURES__ */ 

    SetHiliteHandler(MITEM_MTPNP_PRR_NWK_ADD, HighlightCard2NETSETAddPrefNwk);
    SetHiliteHandler(MITEM_MTPNP_PRR_NWK_NEW, HighlightCard2NETSETNewPrefNwk);
    SetHiliteHandler(MITEM_MTPNP_PRR_NWK_DELETE, HighlightCard2NETSETDelPrefNwk);
    SetHiliteHandler(MITEM_MTPNP_PRR_NWK_EDIT, HighlightCard2NETSETEditPrefNwk);

    SetHiliteHandler(MENU_MTPNP_ADD_FROM_LIST_DONE, mmi_netset_card2_highlight_add_from_list_done);
    SetHiliteHandler(MENU_MTPNP_ADD_FROM_LIST_SORT_BY_DEFAULT, mmi_netset_card2_highlight_sort_by_default);
    SetHiliteHandler(MENU_MTPNP_ADD_FROM_LIST_SORT_BY_ALPHABET, mmi_netset_card2_highlight_sort_by_alphabet);

#if 1
    mmi_frm_hide_menu_item(MENU_MTPNP_ADD_FROM_LIST_SORT_BY_DEFAULT);
    mmi_frm_hide_menu_item(MENU_MTPNP_ADD_FROM_LIST_SORT_BY_ALPHABET);
#endif

    gCard2NetworkSetup.reg_fail_flag = 0;
}

/* network setup menu begin */
static void HighlightDMNETSETMain(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryDMNETSETMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryDMNETSETMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void EntryDMNETSETMain(void)
{
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_NETSET_MAIN, NULL, EntryDMNETSETMain,
                        MENU_MTPNP_DM_NETWORK_SETUP, STR_ID_NETSET_MITEM9185, MAIN_MENU_TITLE_SETTINGS_ICON);
}

static void HighlightCard2NETSETMain(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __MMI_GPRS_FEATURES__
    SetLeftSoftkeyFunction(NETSETCard2GetGPRSModeReq, KEY_EVENT_UP);
#else /* __MMI_GPRS_FEATURES__ */
    SetLeftSoftkeyFunction(EntryCard2NETSETMain, KEY_EVENT_UP);
#endif /* __MMI_GPRS_FEATURES__ */

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_GPRS_FEATURES__
    SetKeyHandler(NETSETCard2GetGPRSModeReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* __MMI_GPRS_FEATURES__ */
    SetKeyHandler(EntryCard2NETSETMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_GPRS_FEATURES__ */

}

static void EntryCard2NETSETMain(void)
{
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 *NwType[MAX_SUB_MENUS];

    U32 maskingByte = -1;
    U32 HideItemId = -1;

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_cphs_rearrange_network_selection_menu(SIM2);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    EntryNewScreen(SCR_MTPNP_NETSET_MAIN, NULL, EntryCard2NETSETMain, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_MAIN);

    if (!is_test_sim(SIM2))
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_MTPNP_NETWORK_SETUP, MENU_MTPNP_GPRS_CONNECTION);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
    }

    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_NETWORK_SETUP);
    GetSequenceStringIds_Ext(MENU_MTPNP_NETWORK_SETUP, nStrItemList);

    SetParentHandler(MENU_MTPNP_NETWORK_SETUP);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_MTPNP_NETWORK_SETUP, NwType);

    if (!is_test_sim(SIM2))
    {
        nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
    }

    ShowCategory52Screen(STRING_MTPNP_SELECTION_MODE,
                         MAIN_MENU_TITLE_SETTINGS_ICON,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, NwType, 0, 0, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* network setup menu end */

/* network setup msg queue begin */
static void NETSETCard2MsgQueuePush(U8 ItemType, FuncPtr CallBackFunc, U16 MsgID, PsFuncPtr CallBackRspHandler)
{
    if (gCard2NetworkSetupMsgQueue.Index == gCard2NetworkSetupMsgQueue.Top)
    {
        (*CallBackFunc) ();
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].ItemType = ItemType;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].CallBackFunc = CallBackFunc;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].MsgID = MsgID;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].CallBackRspHandler = CallBackRspHandler;
        NETSETCard2MsgQueueTopAddOne();
        MTPNP_PFAL_Register_Event_Handler(MsgID, NETSETCard2MsgQueueProtocolHandler);
    }
    else if (NETSETCard2MsgQueueGetPreviousTop() == gCard2NetworkSetupMsgQueue.Index)
    {
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].ItemType = ItemType;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].CallBackFunc = CallBackFunc;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].MsgID = MsgID;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].CallBackRspHandler = CallBackRspHandler;
        NETSETCard2MsgQueueTopAddOne();
    }
    else if (gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].ItemType == NETWORK_RESTORE
             && ((ItemType == GET_PLMN_LIST) || (ItemType == BAND_SELECTION)))
    {
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].ItemType = ItemType;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].CallBackFunc = CallBackFunc;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].MsgID = MsgID;
        gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Top].CallBackRspHandler = CallBackRspHandler;
        NETSETCard2MsgQueueTopAddOne();
    }
    else
    {
        gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].ItemType = ItemType;
        gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackFunc = CallBackFunc;
        gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].MsgID = MsgID;
        gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = CallBackRspHandler;
    }
}

static void NETSETCard2MsgQueueProtocolHandler(void *info)
{
    if (gCard2NetworkSetupMsgQueue.Index == gCard2NetworkSetupMsgQueue.Top)
    {
        return;
    }

    NETSETCard2MsgQueueIndexAddOne();
    if (gCard2NetworkSetupMsgQueue.Index == gCard2NetworkSetupMsgQueue.Top)
    {
        if (gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousIndex()].CallBackRspHandler != NULL)
        {
            (*gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousIndex()].CallBackRspHandler) (info);
        }
    }
    else
    {
        (*gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Index].CallBackFunc) ();
        MTPNP_PFAL_Register_Event_Handler(gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Index].MsgID,
                                          NETSETCard2MsgQueueProtocolHandler);
    }
}

static void NETSETCard2MsgQueueTopAddOne(void)
{
    if ((gCard2NetworkSetupMsgQueue.Top + 1) < NETSETMSGQUEUESIZE)
    {
        gCard2NetworkSetupMsgQueue.Top++;
    }
    else
    {
        gCard2NetworkSetupMsgQueue.Top = 0;
    }
    ASSERT(gCard2NetworkSetupMsgQueue.Index != gCard2NetworkSetupMsgQueue.Top);
}

static void NETSETCard2MsgQueueTopMinusOne(void)
{
    ASSERT(gCard2NetworkSetupMsgQueue.Index != gCard2NetworkSetupMsgQueue.Top);
    gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = NULL;
    if (gCard2NetworkSetupMsgQueue.Top == 0)
    {
        gCard2NetworkSetupMsgQueue.Top = NETSETMSGQUEUESIZE - 1;
    }
    else
    {
        gCard2NetworkSetupMsgQueue.Top--;
    }
    gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = NULL;
}

static void NETSETCard2MsgQueueIndexAddOne(void)
{
    ASSERT(gCard2NetworkSetupMsgQueue.Index != gCard2NetworkSetupMsgQueue.Top);
    if ((gCard2NetworkSetupMsgQueue.Index + 1) < NETSETMSGQUEUESIZE)
    {
        gCard2NetworkSetupMsgQueue.Index++;
    }
    else
    {
        gCard2NetworkSetupMsgQueue.Index = 0;
    }
}

static U8 NETSETCard2MsgQueueGetPreviousIndex(void)
{
    if (gCard2NetworkSetupMsgQueue.Index == 0)
    {
        return (NETSETMSGQUEUESIZE - 1);
    }
    else
    {
        return (gCard2NetworkSetupMsgQueue.Index - 1);
    }
}

static U8 NETSETCard2MsgQueueGetPreviousTop(void)
{
    if (gCard2NetworkSetupMsgQueue.Top == 0)
    {
        return (NETSETMSGQUEUESIZE - 1);
    }
    else
    {
        return (gCard2NetworkSetupMsgQueue.Top - 1);
    }
}

static U8 NETSETCard2MsgQueueCheckCurrOP(void)
{
    return (gCard2NetworkSetupMsgQueue.Queue[gCard2NetworkSetupMsgQueue.Index].ItemType);
}

static U8 NETSETCard2MsgQueueCheckLastOP(void)
{
    return (gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].ItemType);
}

/* network setup msg queue end */

/* network selection mode begin */
static void HighlightCard2NETSETSelectionMode(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryCard2NETSETSelectionMode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCard2NETSETSelectionMode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void HintCard2NETSETSelectionMode(U16 index)
{
#ifdef __MANUAL_MODE_NW_SEL__
    if (MTPNP_AD_Get_PLMN_Selection_Mode() == MTPNP_AD_PLMN_AUTOMATIC)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_NETSET_AUTOMATIC));
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_NETSET_MANUAL));
    }
#else
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index],
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_NETSET_AUTOMATIC));
#endif
}

static void EntryCard2NETSETSelectionMode(void)
{
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
#ifdef __MANUAL_MODE_NW_SEL__
    U8 *NwType[MAX_SUB_MENUS];
#endif

    if (mmi_bootup_is_sim2_nw_registration_ok() == MMI_TRUE)
    {
        EntryNewScreen(SCR_MTPNP_NETSET_SELECTION_MODE, NULL, EntryCard2NETSETSelectionMode, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_SELECTION_MODE);
        nNumofItem = GetNumOfChild(MENU_MTPNP_SELECTION_MODE);
        GetSequenceStringIds(MENU_MTPNP_SELECTION_MODE, nStrItemList);
        SetParentHandler(MENU_MTPNP_SELECTION_MODE);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#ifdef __MANUAL_MODE_NW_SEL__
        ConstructHintsList(MENU_MTPNP_SELECTION_MODE, NwType);
#endif

#ifdef __MANUAL_MODE_NW_SEL__
        ShowCategory52Screen(STR_ID_NETSET_SCR9186_CAPTION, MAIN_MENU_TITLE_SETTINGS_ICON,
                             STR_GLOBAL_OK, IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                             nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, NwType, LIST_MENU, 0, guiBuffer);
#else
        ShowCategory15Screen(STR_ID_NETSET_SCR9186_CAPTION, MAIN_MENU_TITLE_SETTINGS_ICON,
                             STR_GLOBAL_OK, IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                             nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);
#endif
        SetKeyHandler(ExitCard2NETSETSelectionMode, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup((PU8) GetString(STRING_MTPNP_NETSET_SIM2_INVALID), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION,
                     ERROR_TONE);
    }
}

static void ExitCard2NETSETSelectionMode(void)
{
    NETSETCheckAndRestoreCard2Network();
    GoBackHistory();
}

static void NETSETCheckAndRestoreCard2Network(void)
{
    if (gCard2NetworkSetup.NetworkSelectAbort == MMI_TRUE)
    {
        RestorePreviousCard2Network();
        gCard2NetworkSetup.NetworkSelectAbort = MMI_FALSE;
    }
}

static void RestorePreviousCard2Network(void)
{
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };

    gCard2NetworkSetup.NetworkSelectAbort = MMI_FALSE;
    MTPNP_AD_Get_Network_ID(card2_plmn);
    if (card2_plmn[0] == '\0')
    {
        NETSETCard2MsgQueuePush(NETWORK_RESTORE, NETSETCard2AutoNetworkSearchReq, MTPNP_PFAL_MSG_NW_SET_PLMN_RSP, NULL);
    }
    else
    {
        NETSETCard2MsgQueuePush(NETWORK_RESTORE, NETSETCard2ManualNetworkRestoreReq,
                                MTPNP_PFAL_MSG_NW_SET_PLMN_RSP, NULL);
    }
}

static void NETSETCard2ManualNetworkRestoreReq(void)
{
    ST_MTPNP_AD_SET_PLMN_REQ set_req = { 0 };
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };

    MTPNP_AD_Get_Network_ID(card2_plmn);

    set_req.opcode = MMI_MANUAL_SEL;
    memcpy(set_req.oper, (PS8) card2_plmn, MTPNP_AD_MAX_PLMN_LEN);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
#endif
    MTPNP_AD_Set_PLMN_Req(&set_req);
}

/* network selection mode end */

/* preferred networks show begin */
static void HighlightCard2NETSETPreferredNetworks(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETGetCard2PreferredNetworkReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(NETSETGetCard2PreferredNetworkReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void NETSETGetCard2PreferredNetworkReq(void)
{
    ST_MTPNP_AD_GET_PREFERRED_NETWORK_REQ network_req;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_GET_PREFERRED_NETWORKS_RSP, NETSETGetCard2PreferredNetworkRsp);

    if (MTPNP_AD_Get_NoOfPLMNSupported() == 0)
    {
        gCard2PrefListDelFlag = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_MTPNP_NETSET_MAIN);
        return;
    }

    network_req.num = MTPNP_AD_Get_NoOfPLMNSupported();
    network_req.index = 0;
    network_req.file_idx_req = FILE_NONE;
    MTPNP_AD_Get_Preferred_Network_Req(&network_req);
}

/* diamond, 2005/12/07 Support the records not in order */
typedef struct
{
    U8 op;
    U8 index;
    U8 plmn[MAX_PLMN_LEN + 1];
    U8 rat;
} CARD2NETQUEUE;

static CARD2NETQUEUE *net_queue;
static U8 card2_queue_cnt = 0;
static U8 card2_send_cnt = 0;

void NETSETCard2ModifyNetworkRsp(void *info);

/*****************************************************************************
 * FUNCTION
 *  NETSETCard2ModifyNetworkByIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETCard2ModifyNetworkByIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ set_req;
    //MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    myMsgPtr =
        (mmi_smu_set_preferred_oper_list_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    myMsgPtr->opcode = net_queue[send_cnt].op;
    myMsgPtr->index = net_queue[send_cnt].index;
    memcpy(myMsgPtr->oper, net_queue[send_cnt].plmn, (MAX_PLMN_LEN + 1));
    myMsgPtr->rat = net_queue[send_cnt].rat;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SET_PREFERRED_NETWORKS_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(NETSETModifyNetworkRsp, PRT_SET_PREFERRED_NETWORKS_RSP);
    OslMsgSendExtQueue(&Message);
    send_cnt++;

    */
    
    set_req.index = net_queue[card2_send_cnt].index;
    set_req.opcode = net_queue[card2_send_cnt].op;
    set_req.rat =
        (gCard2PrefList.SimFileIdx == FILE_PLMNSEL_IDX) ? 0 : (U8) gCard2PrefListDisplay.CurrSelectService + 1;

}


/*****************************************************************************
 * FUNCTION
 *  NETSETCard2ModifyNetworkToQueue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op          [IN]        
 *  index       [IN]        
 *  plmn        [?]         
 *  rat         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETCard2ModifyNetworkToQueue(U8 op, U8 index, U8 *plmn, U8 rat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    net_queue[card2_queue_cnt].op = op;
    net_queue[card2_queue_cnt].index = index;
    memcpy(net_queue[card2_queue_cnt].plmn, plmn, MAX_PLMN_LEN + 1);
    net_queue[card2_queue_cnt].rat = rat;
    card2_queue_cnt++;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETCard2ModifyNetworkRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETCard2ModifyNetworkRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (card2_send_cnt == card2_queue_cnt)
    {
        OslMfree(net_queue);
        card2_send_cnt = 0;
        card2_queue_cnt = 0;
    }
    else
    {
        NETSETCard2ModifyNetworkByIndex();
    }
}

static void NETSETGetCard2PreferredNetworkRsp(void *info)
{
    ST_MTPNP_AD_GET_PREFERRED_NETWORK_RSP *network_rsp = (ST_MTPNP_AD_GET_PREFERRED_NETWORK_RSP *) info;
    U8 count;
    U8 index, done_flag;
    U8 *list_array;
    U16 pref_list_size, i;
    U8 *pref_list;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_GET_PREFERRED_NETWORKS_RSP);
    if (network_rsp->result == MTPNP_FALSE)
    {
        gCard2PrefListDelFlag = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
        return;
    }
    else
    {
        gCard2PrefList.SimFileIdx = network_rsp->file_idx_rsp;

        list_array = OslMalloc(network_rsp->retnum);
        pref_list_size = gCard2PrefList.PrefListSize;

        if (gCard2PrefList.PrefListSize == 0 || gCard2PrefList.comp_flag == 0)
        {
            pref_list = NULL;
        }
        else
        {
            pref_list = OslMalloc(gCard2PrefList.PrefListSize * (MAX_PLMN_LEN + 1));
            memcpy(pref_list, gCard2PrefList.PrefPLMN, gCard2PrefList.PrefListSize * (MAX_PLMN_LEN + 1));
        }

        if (network_rsp->retnum > 100)
        {
            net_queue = NULL;
        }
        else
        {
            net_queue = OslMalloc(network_rsp->retnum * 2 * sizeof(CARD2NETQUEUE));
        }

        for (count = 0, gCard2PrefList.PrefListSize = 0; count < network_rsp->retnum; count++)
        {
            if (gCard2PrefList.PrefListSize >= MAX_PREFFERED_PLMN)
            {
                break;
            }

            if ((network_rsp->oper_list[count * (MAX_PLMN_LEN + 1)] != 0X3F) &&
                (network_rsp->oper_list[count * (MAX_PLMN_LEN + 1)] != 0X00))
            {
                for (index = 0; index < (MAX_PLMN_LEN + 1); index++)
                {
                    /* gPrefList.PrefPLMN[count][index] = myMsgPtr->oper_list[index + count * (MAX_PLMN_LEN + 1)]; */
                    gCard2PrefList.PrefPLMN[gCard2PrefList.PrefListSize][index] =
                        network_rsp->oper_list[index + count * (MAX_PLMN_LEN + 1)];
                }
                gCard2PrefList.PrefPLMN[gCard2PrefList.PrefListSize][MAX_PLMN_LEN] = 0;
                
                if ((network_rsp->rat_list[count * 2] & 0x80) == 0x80 &&
                    (network_rsp->rat_list[count * 2 + 1] & 0x80) == 0x00)
                {
                    gCard2PrefList.rat[gCard2PrefList.PrefListSize] = L4C_RAT_UMTS;
                }
                else if ((network_rsp->rat_list[count * 2] & 0x80) == 0x00 &&
                    (network_rsp->rat_list[count * 2 + 1] & 0x80) == 0x80)
                {
                    gCard2PrefList.rat[gCard2PrefList.PrefListSize] = L4C_RAT_GSM;
                }
                else if ((network_rsp->rat_list[count * 2] & 0x80) == 0x80 &&
                    (network_rsp->rat_list[count * 2 + 1] & 0x80) == 0x80)
                {
                    gCard2PrefList.rat[gCard2PrefList.PrefListSize] = L4C_RAT_GSM_UMTS;
                }
                else
                {
                    gCard2PrefList.rat[gCard2PrefList.PrefListSize] = L4C_RAT_NONE;
                }
                
                if (gCard2PrefList.SimFileIdx != FILE_PLMNSEL_IDX)
                {
                    if ((network_rsp->rat_list[count * 2] & 0x80) == 0x80 &&
                        (network_rsp->rat_list[count * 2 + 1] & 0x80) == 0x00)
                    {
                        gCard2PrefListDisplay.PLMNListIcons[gCard2PrefList.PrefListSize] = IMG_SI_3G;
                    }
                    else if ((network_rsp->rat_list[count * 2] & 0x80) == 0x00 &&
                        (network_rsp->rat_list[count * 2 + 1] & 0x80) == 0x80)
                    {
                        gCard2PrefListDisplay.PLMNListIcons[gCard2PrefList.PrefListSize] = IMG_SI_2G;
                    }
                    else if ((network_rsp->rat_list[count * 2] & 0x80) == 0x80 &&
                        (network_rsp->rat_list[count * 2 + 1] & 0x80) == 0x80)
                    {
                        gCard2PrefListDisplay.PLMNListIcons[gCard2PrefList.PrefListSize] = (U16) IMG_SI_GPRS_INDICATOR;
                    }
                    else
                    {
                        gCard2PrefListDisplay.PLMNListIcons[gCard2PrefList.PrefListSize] = (U16) IMG_GLOBAL_DEFAULT;
                    }
                }
                
                gCard2PrefList.PrefListSize++;
                
                *(list_array + count) = MMI_TRUE;
                
                if (count == 0)
                {
                    continue;
                }
                
                if (*(list_array + count - 1) == MMI_FALSE && net_queue != NULL)
                {
                    /* There is a record not in order because its previous record is empty */
                    *(list_array + count) = MMI_FALSE;
                    /* delete it */
                    NETSETCard2ModifyNetworkToQueue(
                        SMU_REMOVE_PLMNSEL,
                        count,
                        gCard2PrefList.PrefPLMN[gCard2PrefList.PrefListSize - 1],
                        gCard2PrefList.rat[gCard2PrefList.PrefListSize - 1]);
                    /* add it */
                    for (index = 0; index < count; index++)
                    {
                        if (*(list_array + index) == MMI_FALSE)
                        {
                            break;
                        }
                    }
                    NETSETCard2ModifyNetworkToQueue(
                        SMU_ADD_PLMNSEL,
                        (U8) (gCard2PrefList.PrefListSize - 1),
                        gCard2PrefList.PrefPLMN[gCard2PrefList.PrefListSize - 1],
                        gCard2PrefList.rat[gCard2PrefList.PrefListSize - 1]);
                    *(list_array + index) = MMI_TRUE;
                }
            }
            else
            {
                /* diamond, 2005/12/07 Support the records not in order */
                *(list_array + count) = MMI_FALSE;
                /* break; */
            }
        }

        if (net_queue != NULL)
        {
            if (card2_queue_cnt > 0)
            {
                NETSETCard2ModifyNetworkByIndex();
            }
            else
            {
                OslMfree(net_queue);
            }
        }

        OslMfree(list_array);

        gCard2PrefListDisplay.PrefNwGotResponse = MMI_TRUE;

        if (!IsScreenPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST) == ST_SUCCESS)
        {
            if (gCard2PrefList.comp_flag == 0)   /* real show PLMN list screen */
            {
                EntryCard2NETSETShowPreferredList();
            }
            else    /* retry get PLMN list after Del or Edit PLMN */
            {
                gCard2PrefList.comp_flag = 0;
                
                if (pref_list_size != gCard2PrefList.PrefListSize)
                {
                    /* done */
                    done_flag = 1;
                }
                else
                {
                    for (i = 0; i < pref_list_size; i++)
                    {
                        if (strncmp((PS8)gCard2PrefList.PrefPLMN[i],
                            (PS8)(pref_list + i * (MAX_PLMN_LEN + 1)),
                            MAX_PLMN_LEN + 1) != 0)
                        {
                            break;
                        }
                    }
                    
                    if (i == pref_list_size)
                    {
                        /* not change */
                        done_flag = 0;
                    }
                    else
                    {
                        /* done */
                        done_flag = 1;
                    }
                }
                
                if (done_flag == 1)
                {
                    if (gCard2PrefListDelFlag)
                    {
                        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                    }
                    else
                    {
                        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                    }
                }
                else
                {
                    DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
                }
                
                if ((isInCall() && !IsWapCallPresent()) || isOutgoingCall())
                {
                    {
                        PRINT_INFORMATION("isInCall return %d", isInCall());
                        PRINT_INFORMATION("IsWapCallPresent return %d", IsWapCallPresent());
                        PRINT_INFORMATION("isOutgoingCall return %d", isOutgoingCall());
                    }
                    mmi_frm_add_history_before_cm_marker(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST, EntryCard2NETSETShowPreferredList);
                }
                else
                {
                    if (IsScreenPresent(SCR_MTPNP_NETSET_MAIN))
                    {
                        GenericExitScreen(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST, EntryCard2NETSETShowPreferredList);
                    }
                }
            }
        }
    }

    if (pref_list != NULL)
    {
        OslMfree(pref_list);
    }

    gCard2PrefListDelFlag = 0;
}

/*****************************************************************************
* FUNCTION
*  mmi_card2_netset_get_preferred_networks_item
* DESCRIPTION
*  Dynamically get preferred networks items
* PARAMETERS
*  item_index          [IN]        
*  str_buff            [IN]        
*  img_buff_p          [?]         
*  str_img_mask        [IN]        
* RETURNS
*  pBOOL
*****************************************************************************/
pBOOL mmi_card2_netset_get_preferred_networks_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      if((item_index < 0) || (item_index > MAX_PLMN_NO_LIST_LENGTH))
    //              return MMI_FALSE;
    
    mmi_ucs2cpy((S8*) str_buff, (S8*) gCard2PrefListDisplay.nStrItemList[item_index]);
    *img_buff_p = get_image(gCard2PrefListDisplay.PLMNListIcons[item_index]);
    
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_netset_get_preferred_networks_hint
* DESCRIPTION
*  Dynamically get preferred networks items
* PARAMETERS
*  item_index      [IN]        
*  hint_array      [?]         
*  UI_string_type str_buff(?)
* RETURNS
*  S32
*****************************************************************************/
S32 mmi_card2_netset_get_preferred_networks_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempDislpay[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((PS8) tempDislpay, (S8*) gCard2PrefList.PrefPLMN[item_index]);
    
    /* Skip the hint if the item data and hint data are the same as plmn number */
    if (mmi_ucs2cmp((S8*) gCard2PrefListDisplay.nStrItemList[item_index], (PS8) tempDislpay) == 0)
    {
        return MMI_FALSE;
    }
    
    mmi_ucs2cpy((PS8) * hint_array, (PS8) tempDislpay);
    return MMI_TRUE;
}


static void EntryCard2NETSETShowPreferredList(void)
{
    PU8 guiBuffer;

    EntryNewScreen(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST, NULL, EntryCard2NETSETShowPreferredList, NULL);

    if (gCard2PrefListDisplay.PrefNwGotResponse == MMI_TRUE)
    {
        guiBuffer = NULL;
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    }
    gCard2PrefListDisplay.PrefNwGotResponse = MMI_FALSE;
    GetCard2PrefNwkNameFromPLMN();
    RegisterHighlightHandler(HiliteCard2HandlerPrefList);

    if (!gCard2PrefList.PrefListSize)
    {
        gCard2PrefListDisplay.nStrItemList[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        ShowCategory6Screen(
            STR_ID_NETSET_PRF_NWK_TITLE,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            gCard2PrefListDisplay.nStrItemList,
            NULL,
            0,
            guiBuffer);
    }
    else
    {
        /* 2006/02/16 USIM preferred network implementation */
        if (gCard2PrefList.SimFileIdx != FILE_PLMNSEL_IDX)
        {
            ShowCategory184Screen(
                STR_ID_NETSET_PRF_NWK_TITLE,
                MAIN_MENU_TITLE_SETTINGS_ICON,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                gCard2PrefList.PrefListSize,
                mmi_card2_netset_get_preferred_networks_item,
                mmi_card2_netset_get_preferred_networks_hint,
                0,
                guiBuffer);
        }
        else
        {
            ShowCategory284Screen(
                STR_ID_NETSET_PRF_NWK_TITLE,
                MAIN_MENU_TITLE_SETTINGS_ICON,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                gCard2PrefList.PrefListSize,
                mmi_card2_netset_get_preferred_networks_item,
                mmi_card2_netset_get_preferred_networks_hint,
                0,
                guiBuffer);
        }
    }

    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryCard2NETSETShowPrefNwkOptions, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2NETSETShowPrefNwkOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackCard2NetworkSetup, KEY_EVENT_UP);
    SetKeyHandler(GoBackCard2NetworkSetup, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static U16 GetCard2PrefNwkNameFromPLMN(void)
{
    U16 count;
    U16 index = 0;

    if (gCard2PrefList.PrefListSize > MAX_PREFFERED_PLMN)
    {
        gCard2PrefList.PrefListSize = MAX_PREFFERED_PLMN;
    }

    for (count = 0; count < MAX_PREFFERED_PLMN; count++)
    {
        gCard2PrefListDisplay.nStrItemList[count] = NULL;
    }

    for (count = 0; count < gCard2PrefList.PrefListSize; count++, index++)
    {
        mmi_netset_retrieve_opname_from_plmn(gCard2PrefList.PrefPLMN[count],
                                             (U8 *) gCard2PrefListDisplay.PrefNetworkListDislpay[count]);
        gCard2PrefListDisplay.nStrItemList[count] = (PU8) gCard2PrefListDisplay.PrefNetworkListDislpay[count];
    }
    return count;
}

static void HiliteCard2HandlerPrefList(S32 hiliteIdx)
{
    gCard2PrefListDisplay.CurrSelPrefNetwork = (U8) hiliteIdx;
}

static void ConstructCard2PreferredListHint(U8 ** hintArray)
{
    U8 i;

    for (i = 0; i < gCard2PrefList.PrefListSize; i++)
    {
        memset((S8 *) hintData[i], 0, MAX_SUB_MENU_SIZE);
        mmi_asc_to_ucs2((S8 *) hintData[i], (S8 *) gCard2PrefList.PrefPLMN[i]);
        hintArray[i] = hintData[i];
    }
}

static void GoBackCard2NetworkSetup(void)
{
    GoBackToHistory(SCR_MTPNP_NETSET_MAIN);
}

#ifndef __MMI_KEEP_ORI_STYLE__
static void HiliteCard2HandlerPrefNwkHideAddIfFull(S32 index)
{
    if ((gCard2PrefList.PrefListSize >= MAX_PREFFERED_PLMN)
        || (gCard2PrefList.PrefListSize >= MTPNP_AD_Get_NoOfPLMNSupported()))
    {
        ExecuteCurrHiliteHandler(index + 2);
    }
    else
    {
        ExecuteCurrHiliteHandler(index);
    }
}
#endif

static void EntryCard2NETSETShowPrefNwkOptions(void)
{
    PU8 guiBuffer;
    U16 nStrItemList[15];
    U16 nNumofItem;
    U16 ItemIcons[15];

    EntryNewScreen(SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS, NULL, EntryCard2NETSETShowPrefNwkOptions, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS);
    nNumofItem = GetNumOfChild(MITEM_MTPNP_PRF_NWK_OPTIONS_PSEUDO);

    ItemIcons[0] = IMG_GLOBAL_L1;
    ItemIcons[1] = IMG_GLOBAL_L2;
    ItemIcons[2] = IMG_GLOBAL_L3;
    ItemIcons[3] = IMG_GLOBAL_L4;
    GetSequenceStringIds(MITEM_MTPNP_PRF_NWK_OPTIONS_PSEUDO, nStrItemList);
    SetParentHandler(MITEM_MTPNP_PRF_NWK_OPTIONS_PSEUDO);

#ifndef __MMI_KEEP_ORI_STYLE__
    RegisterHighlightHandler(HiliteCard2HandlerPrefNwkHideAddIfFull);
#else
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif

    if (gCard2PrefList.PrefListSize == 0)
    {
        nNumofItem = 2;
    }

#ifndef __MMI_KEEP_ORI_STYLE__
    if ((gCard2PrefList.PrefListSize >= MAX_PREFFERED_PLMN)
        || (gCard2PrefList.PrefListSize >= MTPNP_AD_Get_NoOfPLMNSupported()))
    {
        nNumofItem = 2;
        nStrItemList[0] = nStrItemList[2];
        nStrItemList[1] = nStrItemList[3];
    }
#endif

    ShowCategory15Screen(STR_GLOBAL_OPTIONS, MAIN_MENU_TITLE_SETTINGS_ICON,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, ItemIcons, LIST_MENU, 0, guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* preferred networks show end */

/* network selection manual beign */
static void HighlightCard2NETSETSelectionManual(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETGetCard2PLMNListCheck, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void NETSETGetCard2PLMNListCheck(void)
{
    NETSETCard2MsgQueuePush(GET_PLMN_LIST, NETSETCard2GetPLMNListReq,
                            MTPNP_PFAL_MSG_NW_GET_PLMN_LIST_RSP, NETSETCard2GetPLMNListRsp);

    EntryCard2NETSETManualSearchProgress();
}

static void NETSETCard2GetPLMNListReq(void)
{
    MTPNP_AD_Get_PLMN_List_Req();
}

static void NETSETCard2GetPLMNListRsp(void *info)
{
    ST_MTPNP_AD_GET_PLMN_LIST_RSP *get_rsp = (ST_MTPNP_AD_GET_PLMN_LIST_RSP *) info;
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };
    l4c_plmn_info_struct tempPLMNList;
    U16 i;

    SetDelScrnIDCallbackHandler(SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS, NULL);

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_NW_GET_PLMN_LIST_RSP);
    MTPNP_AD_Get_Network_ID(card2_plmn);

    if (gCard2NetworkSetup.PlmnList != NULL)
    {
        OslMfree(gCard2NetworkSetup.PlmnList);
        gCard2NetworkSetup.PlmnList = NULL;
    }

    gCard2NetworkSetup.PlmnList = OslMalloc(sizeof(mmi_nw_get_plmn_list_rsp_struct));
    gCard2NetworkSetup.PlmnList->result.flag = get_rsp->result.flag;
    gCard2NetworkSetup.PlmnList->result.cause = get_rsp->result.cause;
    gCard2NetworkSetup.PlmnList->length = get_rsp->length;
    memcpy(gCard2NetworkSetup.PlmnList->list, get_rsp->list,
           sizeof(l4c_rat_plmn_info_struct) * MTPNP_AD_MAX_PLMN_LIST_LEN);

    if (memcmp(card2_plmn, "46002", 5) == 0)
    {
        for (i = 0; i < gCard2NetworkSetup.PlmnList->length; i++)
        {
            if (memcmp(gCard2NetworkSetup.PlmnList->list[i].plmn_id, "46000", 5) == 0)
            {
                memcpy(&tempPLMNList, &(gCard2NetworkSetup.PlmnList->list[0]), sizeof(l4c_plmn_info_struct));
                memcpy(&(gCard2NetworkSetup.PlmnList->list[0]), &(gCard2NetworkSetup.PlmnList->list[i]),
                       sizeof(l4c_plmn_info_struct));
                memcpy(&(gCard2NetworkSetup.PlmnList->list[i]), &tempPLMNList, sizeof(l4c_plmn_info_struct));
            }
        }
    }

    if (gCard2NetworkSetup.PlmnList->result.flag != L4C_OK || gCard2NetworkSetup.PlmnList->length == 0 || isInCall())
    {
        if (gCard2NetworkSetup.PlmnList != NULL)
        {
            OslMfree(gCard2NetworkSetup.PlmnList);
            gCard2NetworkSetup.PlmnList = NULL;
        }
        DisplayPopup((PU8) GetString(STRING_MTPNP_NETSET_NW_LIST_FAIL), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION,
                     ERROR_TONE);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS);
    }
    else
    {
        for (i = 0; i < gCard2NetworkSetup.PlmnList->length; ++i)
        {
            if (gCard2NetworkSetupDisplay.PLMNName[i] != NULL)
            {
                OslMfree(gCard2NetworkSetupDisplay.PLMNName[i]);
                gCard2NetworkSetupDisplay.PLMNName[i] = NULL;
            }
            gCard2NetworkSetupDisplay.PLMNName[i] = OslMalloc(PLMN_NAME_LENGTH * ENCODING_LENGTH);
            memset((void *) gCard2NetworkSetupDisplay.PLMNName[i], 0, PLMN_NAME_LENGTH * ENCODING_LENGTH);
            mmi_netset_retrieve_opname_from_plmn(gCard2NetworkSetup.PlmnList->list[i].plmn_id,
                                                 gCard2NetworkSetupDisplay.PLMNName[i]);
        }
        EntryCard2NETSETShowPlmnList();
    }
}

U8 NETSETMTPNPManualSearchProgressDeleteHandler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSETAbortCard2PLMNListReq();
    return MMI_FALSE;
}

static void EntryCard2NETSETManualSearchProgress(void)
{
    EntryNewScreen(SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS, NULL, EntryCard2NETSETManualSearchProgress, NULL);

    ShowCategory66Screen(STR_ID_NETSET_MITEM9186, MAIN_MENU_TITLE_SETTINGS_ICON, 0, 0, STR_GLOBAL_CANCEL, IMG_ID_NETSET_ABORT_LSK,
                         (U8 *) GetString(STR_ID_NETSET_SEARCHIN_NW), IMG_ID_NETSET_NW_SEARCH, NULL);
    SetRightSoftkeyFunction(NETSETAbortCard2PLMNListReq, KEY_EVENT_UP);
    SetKeyHandler(AbortCard2GetPLMNListToIdle, KEY_END, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(
        SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS,
        (HistoryDelCBPtr) NETSETMTPNPManualSearchProgressDeleteHandler);
}

static void NETSETAbortCard2PLMNListReq(void)
{
    SetDelScrnIDCallbackHandler(SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS, NULL);

    if (NETSETCard2MsgQueueCheckCurrOP() == GET_PLMN_LIST)
    {
        if (gCard2NetworkSetupMsgQueue.Index != gCard2NetworkSetupMsgQueue.Top)
        {
            NETSETCard2MsgQueueTopMinusOne();
        }

        MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_NW_ABORT_PLMN_LIST_RSP, NETSETAbortCard2PLMNListRsp);
        MTPNP_AD_Abort_PLMN_List_Req();
    }
    else
    {
        if (NETSETCard2MsgQueueCheckLastOP() == GET_PLMN_LIST)
        {
            if (gCard2NetworkSetupMsgQueue.Index != gCard2NetworkSetupMsgQueue.Top)
            {
                NETSETCard2MsgQueueTopMinusOne();
            }
        }
        GoBackHistory();
    }
}

static void NETSETAbortCard2PLMNListRsp(void *info)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_NW_ABORT_PLMN_LIST_RSP);
    GoBackHistory();
}

static void AbortCard2GetPLMNListToIdle(void)
{
    SetDelScrnIDCallbackHandler(SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS, NULL);

    if (NETSETCard2MsgQueueCheckCurrOP() == GET_PLMN_LIST)
    {
        if (gCard2NetworkSetupMsgQueue.Index != gCard2NetworkSetupMsgQueue.Top)
        {
            NETSETCard2MsgQueueTopMinusOne();
        }

        MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_NW_ABORT_PLMN_LIST_RSP, NETSETAbortCard2PLMNListRsp);
        MTPNP_AD_Abort_PLMN_List_Req();
    }
    else
    {
        if (NETSETCard2MsgQueueCheckLastOP() == GET_PLMN_LIST)
        {
            if (gCard2NetworkSetupMsgQueue.Index != gCard2NetworkSetupMsgQueue.Top)
            {
                NETSETCard2MsgQueueTopMinusOne();
            }
        }
    }

    gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = NULL;
    DisplayIdleScreen();
}

/* network selection manual end */

/* network selection manual list begin */
extern S8 gHomePLMNNum_2[MAX_PLMN_LEN_MMI + 1];
extern U8 gPLMN_2[MAX_PLMN_LEN_MMI + 1];
static void EntryCard2NETSETShowPlmnList(void)
{
    U16 i;
    U8 *guiBuffer;
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };
    MTPNP_AD_Get_Network_ID(card2_plmn);

    {
        PRINT_INFORMATION("card2_plmn = %s", card2_plmn);
        PRINT_INFORMATION("gHomePLMNNum_2 = %s", gHomePLMNNum_2);
        PRINT_INFORMATION("gPLMN_2 = %s", gPLMN_2);
    }

    EntryNewScreen(SCR_MTPNP_NETSET_SHOW_PLMN_LIST, ExitCard2NETSETShowPLMNList, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_SHOW_PLMN_LIST);

    RegisterHighlightHandler(HiliteCard2HandlerShowPLMNList);
    if (gCard2NetworkSetupDisplay.PLMNListIcons != NULL)
    {
        OslMfree(gCard2NetworkSetupDisplay.PLMNListIcons);
        gCard2NetworkSetupDisplay.PLMNListIcons = NULL;
    }
    gCard2NetworkSetupDisplay.PLMNListIcons = OslMalloc((gCard2NetworkSetup.PlmnList->length * sizeof(U16)));

    for (i = 0; i < gCard2NetworkSetup.PlmnList->length; i++)
    {
        if (gCard2NetworkSetup.PlmnList->list[i].status == 3)
        {
            gCard2NetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
        }
        else
        {
            if (strcmp((PS8)card2_plmn, (PS8)gCard2NetworkSetup.PlmnList->list[i].plmn_id) == 0)
            {
                mmi_netset_remove_from_card2_plmn_list(gCard2NetworkSetup.PlmnList->list[i].plmn_id);
                gCard2NetworkSetupDisplay.PLMNListIcons[i] = 0;
            }
            else if (gCard2NetworkSetup.reg_fail_flag == 1 && gCard2NetworkSetupDisplay.CurrSelectNetwork == i)
            {
                PRINT_INFORMATION("reg_fail = 1 & plmn_id = %s , i = %d", gCard2NetworkSetup.PlmnList->list[i].plmn_id, i);
                mmi_netset_add_to_card2_plmn_list(gCard2NetworkSetup.PlmnList->list[i].plmn_id);
                gCard2NetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
            }
            else if (mmi_netset_find_in_card2_plmn_list(gCard2NetworkSetup.PlmnList->list[i].plmn_id) == 1)
            {
                PRINT_INFORMATION("plmn_id = %s, i = %d", gCard2NetworkSetup.PlmnList->list[i].plmn_id, i);
                gCard2NetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
            }
            else
            {
                gCard2NetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_UNKNOWN_PLMN;
            }
        }
    }

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
#ifdef __MMI_DUAL_MODE_SELF_TEST__
/* under construction !*/
#else /* __MMI_DUAL_MODE_SELF_TEST__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_MODE_SELF_TEST__ */ 
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 

    gCard2NetworkSetup.reg_fail_flag = 0;
    /*
    if (memcmp
        (gCard2NetworkSetup.PlmnList->list[0].plmn_id, card2_plmn,
         strlen((PS8) gCard2NetworkSetup.PlmnList->list[0].plmn_id)) == 0 || ((memcmp(card2_plmn, "46002", 5) == 0
                                                                               && memcmp(gCard2NetworkSetup.PlmnList->
                                                                                         list[0].plmn_id, "46000",
                                                                                         5) == 0)))
                                                                                         */
    if (mmi_netset_plmn_matching_criteria((U8*)gHomePLMNNum_2, gCard2NetworkSetup.PlmnList->list[0].plmn_id) ||
        ((memcmp(gHomePLMNNum_2, "46002", 5) == 0 && memcmp(gCard2NetworkSetup.PlmnList->list[0]. plmn_id, "46000", 5) == 0)))
    {
        gCard2NetworkSetupDisplay.PLMNListIcons[0] = (U16) IMG_ID_NETSET_PRF_HOME_PLMN;
    }

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 

    if (*gCard2NetworkSetupDisplay.PLMNName[0] != '\0')
    {
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
        ShowCategory84Screen(
            STR_ID_NETSET_SCR_SELECT_NETWORK_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gCard2NetworkSetup.PlmnList->length,
            gCard2NetworkSetupDisplay.PLMNName,
            gCard2NetworkSetupDisplay.PLMNListIcons,
            1,
            0,
            guiBuffer);
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
    }
    else
    {
        ShowCategory84Screen(STRING_MTPNP_NETSET_SELECT_NETWORK_CAPTION, MAIN_MENU_TITLE_SETTINGS_ICON,
                             STR_GLOBAL_OK, 
                             IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK, 
                             IMG_GLOBAL_BACK,
                             0, 
                             gCard2NetworkSetupDisplay.PLMNName, 
                             gCard2NetworkSetupDisplay.PLMNListIcons, 
                             1, 
                             0,
                             guiBuffer);

        SetKeyHandler(0, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(0, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(0, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(0, KEY_DOWN_ARROW, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(GoBackCard2NetSelection, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NETSETCard2ManualSelectNetworkCheck, KEY_EVENT_UP);
    SetKeyHandler(GoBackCard2NetSelection, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void ExitCard2NETSETShowPLMNList(void)
{
    history currHistory;
    S16 nHistory = 0;
    currHistory.scrnID = SCR_MTPNP_NETSET_SHOW_PLMN_LIST;
    currHistory.entryFuncPtr = (FuncPtr) EntryCard2NETSETShowPlmnList;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
    OslMfree(gCard2NetworkSetupDisplay.PLMNListIcons);
    gCard2NetworkSetupDisplay.PLMNListIcons = NULL;
}

static void HiliteCard2HandlerShowPLMNList(S32 index)
{
    gCard2NetworkSetupDisplay.TempCurrSelectNetwork = (U8) index;
}

static void GoBackCard2NetSelection(void)
{
    U16 i = 0;
    for (i = 0; i < gCard2NetworkSetup.PlmnList->length; i++)
    {
        if (gCard2NetworkSetupDisplay.PLMNName[i])
        {
            OslMfree(gCard2NetworkSetupDisplay.PLMNName[i]);
            gCard2NetworkSetupDisplay.PLMNName[i] = NULL;
        }
    }
    
    if (GetCurrScrnId() == SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS)
    {
        GoBacknHistory(1);
    }
    else
    {
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS);
        GoBackHistory();
    }

}

static void NETSETCard2ManualSelectNetworkCheck(void)
{
    gCard2NetworkSetupDisplay.CurrSelectNetwork = gCard2NetworkSetupDisplay.TempCurrSelectNetwork;

    NETSETCard2MsgQueuePush(NETWORK_SELECTION, NETSETCard2ManualSelectNetworkReq,
                            MTPNP_PFAL_MSG_NW_SET_PLMN_RSP, NETSETCard2ManuSelectNetworkRsp);
    EntryCard2NETSETManualRegProgress();
}

static void NETSETCard2ManualSelectNetworkReq(void)
{
    ST_MTPNP_AD_SET_PLMN_REQ set_req = { 0 };
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };

    MTPNP_AD_Get_Network_ID(card2_plmn);

    MTPNP_PFAL_Update_SIM2_GPRS_Status(L4C_NONE_GPRS);
    IdleResetStatusIcon(STATUS_ICON_SLAVE_ROAMING);

    set_req.opcode = MMI_MANUAL_SEL;
    memcpy(set_req.oper, gCard2NetworkSetup.PlmnList->list[gCard2NetworkSetupDisplay.CurrSelectNetwork].plmn_id,
           MTPNP_AD_MAX_PLMN_LEN);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
#endif

    strcpy((PS8) gCard2NetworkSetup.PLMNRequested,
           (PS8) gCard2NetworkSetup.PlmnList->list[gCard2NetworkSetupDisplay.CurrSelectNetwork].plmn_id);
    MTPNP_PFAL_Show_Idle_NW_Register();
    MTPNP_AD_Set_PLMN_Req(&set_req);
    gCard2NetworkSetup.reg_fail_flag = 0;
}

static void NETSETCard2ManuSelectNetworkRsp(void *info)
{
    ST_MTPNP_AD_SET_PLMN_RSP *set_rsp = (ST_MTPNP_AD_SET_PLMN_RSP *) info;
    U16 i = 0;

    if (set_rsp->result.flag == L4C_OK && set_rsp->status == L4C_RAC_OK
        && !strcmp((PS8) gCard2NetworkSetup.PLMNRequested, (PS8) set_rsp->plmn))
    {
        MTPNP_PFAL_RefreshNwProviderName(set_rsp->plmn);
        for (i = 0; i < gCard2NetworkSetup.PlmnList->length; i++)
        {
            if (gCard2NetworkSetupDisplay.PLMNName[i])
            {
                OslMfree(gCard2NetworkSetupDisplay.PLMNName[i]);
                gCard2NetworkSetupDisplay.PLMNName[i] = NULL;
            }
        }
        OslMfree(gCard2NetworkSetup.PlmnList);
        gCard2NetworkSetup.PlmnList = NULL;
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_MANUAL_SEARCH_PROGRESS);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PLMN_LIST);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_MANUAL_REG_PROGRESS);
    }
    else
    {
        MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };
        
        MTPNP_AD_Get_Network_ID(card2_plmn);
        MTPNP_PFAL_RefreshNwProviderName(card2_plmn);
        DisplayPopup((PU8) GetString(STD_ID_NETSET_NW_SELECT_FAIL), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION,
                     ERROR_TONE);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_MANUAL_REG_PROGRESS);

        if (set_rsp->status == L4C_RAC_LIMITED_SERVICE || set_rsp->status == L4C_RAC_ATTEMPT_TO_UPDATE)
        {
            gCard2NetworkSetup.reg_fail_flag = 1;
        }
    }
}

static void EntryCard2NETSETManualRegProgress(void)
{
    EntryNewScreen(SCR_MTPNP_NETSET_MANUAL_REG_PROGRESS, NULL, EntryCard2NETSETManualRegProgress, NULL);

    ShowCategory66Screen(STRING_MTPNP_SELECTION_MODE, MAIN_MENU_TITLE_SETTINGS_ICON, 0, 0, STR_GLOBAL_CANCEL, IMG_ID_NETSET_ABORT_LSK,
                         (U8 *) GetString(STR_ID_NETSET_REGISTERING_NW), IMG_ID_NETSET_NW_SEARCH, NULL);
    SetRightSoftkeyFunction(AbortCard2ManualRegGoBack, KEY_EVENT_UP);
    SetKeyHandler(AbortCard2ManualRegToIdle, KEY_END, KEY_EVENT_DOWN);
}

static void AbortCard2ManualRegGoBack(void)
{
#ifdef __MANUAL_MODE_NW_SEL__
    if (MTPNP_AD_Get_PLMN_Selection_Mode() == AUTOMATIC_MODE)
    {
        gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else
    gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif
    gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = NULL;
    /* GoBackToHistory(SCR_MTPNP_NETSET_SHOW_PLMN_LIST); */
    GoBackToHistory(SCR_MTPNP_NETSET_SELECTION_MODE);
}

static void AbortCard2ManualRegToIdle(void)
{
#ifdef __MANUAL_MODE_NW_SEL__
    if (MTPNP_AD_Get_PLMN_Selection_Mode() == AUTOMATIC_MODE)
    {
        gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else
    gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif
    gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = NULL;
    GoBackToHistory(SCR_MTPNP_NETSET_SHOW_PLMN_LIST);

    DisplayIdleScreen();
}

/* network selection manual list end */

/* network selection auto beign */
static void HighlightCard2NETSETSelectionAuto(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETCard2AutoSelectNetworkCheck, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void NETSETCard2AutoSelectNetworkCheck(void)
{
    NETSETCard2MsgQueuePush(NETWORK_SELECTION, NETSETCard2AutoNetworkSearchReq,
                            MTPNP_PFAL_MSG_NW_SET_PLMN_RSP, NETSETCard2AutoNetworkSearchRsp);
    EntryCard2NETSETAutoSearchProgress();
}

static void NETSETCard2AutoNetworkSearchReq(void)
{
    ST_MTPNP_AD_SET_PLMN_REQ set_req;

    set_req.opcode = MMI_AUTO_SELECT;
    memset(set_req.oper, 0, MAX_PLMN_LEN + 1);
    set_req.rat = L4C_RAT_NONE;

    MTPNP_PFAL_Update_SIM2_GPRS_Status(L4C_NONE_GPRS);
    IdleResetStatusIcon(STATUS_ICON_SLAVE_ROAMING);

    MTPNP_PFAL_Show_Idle_NW_Register();
    MTPNP_AD_Set_PLMN_Req(&set_req);
}

static void NETSETCard2AutoNetworkSearchRsp(void *info)
{
    ST_MTPNP_AD_SET_PLMN_RSP *set_rsp = (ST_MTPNP_AD_SET_PLMN_RSP *) info;

    if ((set_rsp->result.flag == L4C_OK) && (set_rsp->status == L4C_RAC_OK))
    {
        MTPNP_PFAL_RefreshNwProviderName(set_rsp->plmn);
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_AUTO_SEARCH_PROGRESS);
    }
    else
    {
        MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };

        MTPNP_AD_Get_Network_ID(card2_plmn);
        MTPNP_PFAL_RefreshNwProviderName(card2_plmn);
        DisplayPopup((PU8) GetString(STD_ID_NETSET_NW_SELECT_FAIL), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION,
                     ERROR_TONE);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_AUTO_SEARCH_PROGRESS);
    }
}

static void EntryCard2NETSETAutoSearchProgress(void)
{
    EntryNewScreen(SCR_MTPNP_NETSET_AUTO_SEARCH_PROGRESS, NULL, EntryCard2NETSETAutoSearchProgress, NULL);

    ShowCategory66Screen(STR_ID_NETSET_MITEM9186, MAIN_MENU_TITLE_SETTINGS_ICON, 0, 0, STR_GLOBAL_CANCEL, IMG_ID_NETSET_ABORT_LSK,
                         (U8 *) GetString(STR_ID_NETSET_REGISTERING_NW), IMG_ID_NETSET_NW_SEARCH, NULL);
    SetRightSoftkeyFunction(AbortCard2AutoSearchGoBack, KEY_EVENT_UP);
    SetKeyHandler(AbortCard2AutoSearchToIdle, KEY_END, KEY_EVENT_DOWN);
}

static void AbortCard2AutoSearchGoBack(void)
{
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };

#ifdef __MANUAL_MODE_NW_SEL__
    if (MTPNP_AD_Get_PLMN_Selection_Mode() == AUTOMATIC_MODE)
    {
        gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else
    gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif
    gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = NULL;

    if (g_pwr_context_2.CurrentServiceType == FULL_SERVICE && gPLMN_2[0] != 0)
    {
        MTPNP_PFAL_Change_Roaming_State();
    }

    MTPNP_AD_Get_Network_ID(card2_plmn);
    MTPNP_PFAL_RefreshNwProviderName(card2_plmn);
    GoBackToHistory(SCR_MTPNP_NETSET_SELECTION_MODE);
}

static void AbortCard2AutoSearchToIdle(void)
{
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN + 1] = { 0 };

#ifdef __MANUAL_MODE_NW_SEL__
    if (MTPNP_AD_Get_PLMN_Selection_Mode() == AUTOMATIC_MODE)
    {
        gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else
    gCard2NetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif
    gCard2NetworkSetupMsgQueue.Queue[NETSETCard2MsgQueueGetPreviousTop()].CallBackRspHandler = NULL;

    if (g_pwr_context_2.CurrentServiceType == FULL_SERVICE && gPLMN_2[0] != 0)
    {
        MTPNP_PFAL_Change_Roaming_State();
    }

    MTPNP_AD_Get_Network_ID(card2_plmn);
    MTPNP_PFAL_RefreshNwProviderName(card2_plmn);
    DisplayIdleScreen();
}

/* network selection auto end */

/* network selection change begin */
#ifdef __MANUAL_MODE_NW_SEL__
static void HighlightCard2NETSETSelectionModeChoice(void)
{
    ChangeLeftSoftkey(STRING_MTPNP_NETSET_CHANGE, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryCard2NETSETSelectionModeReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void EntryCard2NETSETSelectionModeReq(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_NW_SET_PLMN_SELECT_MODE_RSP, EntryCard2NETSETSelectionModeRsp);

    MTPNP_AD_Set_Select_Mode_Req();
}

static void EntryCard2NETSETSelectionModeRsp(void *info)
{
    MTPNP_BOOL result = *(MTPNP_BOOL *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_NW_SET_PLMN_SELECT_MODE_RSP);

    if (result == MTPNP_TRUE)
    {
        DisplayPopup((U8 *) GetString(STR_GLOBAL_DONE),
                     IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((U8 *) GetString(STR_GLOBAL_NOT_DONE),
                     IMG_GLOBAL_UNFINISHED, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    }
}
#endif /* __MANUAL_MODE_NW_SEL__ */
/* network selection change end */


#ifdef __MMI_GPRS_FEATURES__

//static U8 GPRSConnType = L4C_WHEN_NEEDED;

static void HighlightNETSETCard2GPRSConnectionMode(void)
{
    ChangeLeftSoftkey(STRING_MTPNP_NETSET_CHANGE, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETCard2SetGPRSConnModeReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void HintNETSETCard2GPRSConnectionMode(U16 index)
{
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (gCard2NetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_GPRS_CONNECTION_MODE_ALWAYS));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_GPRS_CONNECTION_MODE_WHENNEEDED));
    }
}

static void NETSETCard2SetGPRSConnModeRspTimeoutHdlr(void)
{
    if (IsScreenPresent(SCR_ID_NETSET_DUMMY_PROGRESS))  /* Any interrupt happens so don't display popup */
    {
        DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);
    }
}

static void NETSETCard2SetGPRSConnModeRspFailure(void)
{
    DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);

    if (gCard2NetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        gCard2NetworkSetup.GPRSConnType = L4C_WHEN_NEEDED;
    }
    else
    {
        gCard2NetworkSetup.GPRSConnType = L4C_ALWAYS;
    }
}

static void NETSETCard2SetGPRSConnModeReq(void)
{
    if (gCard2NetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        gCard2NetworkSetup.GPRSConnType = L4C_WHEN_NEEDED;
    }
    else
    {
        gCard2NetworkSetup.GPRSConnType = L4C_ALWAYS;
    }

    EntryNETSETGPRSConnectionProgress();
    NETSETCard2SetGPRSConnModeTimeOut();
}

static void NETSETCard2SetGPRSConnModeTimeOut(void)
{
    MYQUEUE Message;
    mmi_nw_set_gprs_connect_type_req_struct *msg = NULL;

    msg = (mmi_nw_set_gprs_connect_type_req_struct*)
        OslConstructDataPtr(sizeof(mmi_nw_set_gprs_connect_type_req_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;

    if (gCard2NetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        msg->type = L4C_ALWAYS;
    }
    else
    {
        msg->type = L4C_WHEN_NEEDED;
    }

    SetSlaveProtocolEventHandler(NETSETCard2SetGPRSConnModeRsp, PRT_NW_SET_GPRS_CONNECT_TYPE_RSP);
    Message.oslMsgId = PRT_NW_SET_GPRS_CONNECT_TYPE_REQ;
    Message.oslDataPtr = (oslParaType*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

static void NETSETCard2SetGPRSConnModeRsp(void *info)
{
    mmi_nw_set_gprs_connect_type_rsp_struct *local;

    local = (mmi_nw_set_gprs_connect_type_rsp_struct*) info;

    StopTimer(TIMER_SET_GPRS_MODE);

    if (local->result == MMI_TRUE)
    {
        StartTimer(TIMER_SET_GPRS_MODE, SET_GPRS_MODE_DELAY, NETSETCard2SetGPRSConnModeRspTimeoutHdlr);
    }
    else
    {
        StartTimer(TIMER_SET_GPRS_MODE, SET_GPRS_MODE_DELAY, NETSETCard2SetGPRSConnModeRspFailure);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETCard2GetGPRSModeReq
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETCard2GetGPRSModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    SetSlaveProtocolEventHandler(NETSETCard2GetGPRSModeRsp, PRT_NW_GET_GPRS_CONNECT_TYPE_RSP);
    /* format the message to get band selection */
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C_2;

    msgStruct.oslMsgId = PRT_NW_GET_GPRS_CONNECT_TYPE_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    
    /* send req to l4c_2 to get band selection */
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetGPRSModeRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETCard2GetGPRSModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_gprs_connect_type_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_nw_get_gprs_connect_type_rsp_struct*) info;

    PRINT_INFORMATION("Card2 GPRS connection type = %d", localPtr->type);

    if (localPtr->result == MMI_TRUE)
    {
        gCard2NetworkSetup.GPRSConnType = localPtr->type;
    }
    else
    {
        gCard2NetworkSetup.GPRSConnType = L4C_ALWAYS;    /* else take the default values */
    }

    EntryCard2NETSETMain();
    //mmi_netset_retrieve_current_modes();
}


#endif /* __MMI_GPRS_FEATURES__ */ 

/* preferred networks add list begin */
static void HighlightCard2NETSETAddPrefNwk(void)
{
    SetLeftSoftkeyFunction(EntryCard2NETSETAddNetworkPLMNList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCard2NETSETAddNetworkPLMNList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void EntryCard2NETSETAddNetworkPLMNList(void)
{
    U16 index;
    PU8 guiBuffer;

    EntryNewScreen(SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PLMN_LIST, NULL, EntryCard2NETSETAddNetworkPLMNList, NULL);

    for (index = 0;; index++)
    {
        if (bcdPlmnsToDisplayName[index].plmn_bcd == 0)
        {
            break;
        }
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    {
        mmi_netset_card2_sort_plmn_list_by_default(index);

#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    }

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PLMN_LIST);
    RegisterHighlightHandler(HiliteCard2HandlerAddNetworkPLMNList);

    ShowCategory284Screen(STRING_MTPNP_NETSET_PRF_ADD_SHW_NWK_TITLE,
                          MAIN_MENU_TITLE_SETTINGS_ICON,
                          STR_GLOBAL_OPTIONS,
                          IMG_GLOBAL_OK,
                          STR_GLOBAL_BACK,
                          IMG_GLOBAL_BACK,
                          index, NETSETGetCard2PrefNetworkListItem, NETSETGetCard2PrefNetworkListHint, 0, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_netset_card2_entry_add_from_list_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_card2_entry_add_from_list_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_netset_card2_sort_plmn_list_by_alphabet(U16 total_record)
{
    U16 i, j;
    S16 cmp1, cmp2;

    if (gCard2PrefListDisplay.SortingArray)
    {
        OslMfree(gCard2PrefListDisplay.SortingArray);
    }
    gCard2PrefListDisplay.SortingArray = OslMalloc(total_record * 2);

    gCard2PrefListDisplay.SortingArray[0] = 0;

    if (mmi_netset_card2_sort_2_entry_comapre(1, gCard2PrefListDisplay.SortingArray[0]) < 0)
    {
        mmi_netset_card2_sort_insert_new_entry(1, 0);
    }
    else
    {
        mmi_netset_card2_sort_insert_new_entry(1, 1);
    }

    for (i = 2; i < total_record; i++)
    {
        cmp1 = mmi_netset_card2_sort_2_entry_comapre(i, gCard2PrefListDisplay.SortingArray[0]);
        if (cmp1 < 0)
        {
            mmi_netset_card2_sort_insert_new_entry(i, 0);
        }
        else
        {
            for (j = 1; j < i; j++)
            {
                cmp2 = mmi_netset_card2_sort_2_entry_comapre(i, gCard2PrefListDisplay.SortingArray[j]);
                if (cmp2 < 0)
                {
                    break;
                }
                cmp1 = cmp2;
            }
            mmi_netset_card2_sort_insert_new_entry(i, j);
        }
    }
}

static S16 mmi_netset_card2_sort_2_entry_comapre(U16 bcd_a, U16 bcd_b)
{
    U8 i = 0, strlen_a, strlen_b;
    S8 *str_a = GetString((U16) (STR_PLMN_NAME_1 + bcdPlmnsToDisplayName[bcd_a].string_index));
    S8 *str_b = GetString((U16) (STR_PLMN_NAME_1 + bcdPlmnsToDisplayName[bcd_b].string_index));

    strlen_a = mmi_ucs2strlen(str_a);
    strlen_b = mmi_ucs2strlen(str_b);

    do
    {
        if (*(U16 *) (str_a + i) > *(U16 *) (str_b + i))
        {
            return 1;
        }
        else if (*(U16 *) (str_a + i) < *(U16 *) (str_b + i))
        {
            return -1;
        }
        else
        {
            i += ENCODING_LENGTH;
        }
    }
    while (i < strlen_a && i < strlen_b);

    if (strlen_a > strlen_b)
    {
        return 1;
    }
    else if (strlen_a < strlen_b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

static void mmi_netset_card2_sort_insert_new_entry(U16 index, U16 reference)
{
    U16 i, tmp1, tmp2;

    if (index == reference)
    {
        gCard2PrefListDisplay.SortingArray[index] = index;
    }
    else
    {
        tmp2 = index;
        for (i = reference; i <= index; i++)
        {
            tmp1 = gCard2PrefListDisplay.SortingArray[i];
            gCard2PrefListDisplay.SortingArray[i] = tmp2;
            tmp2 = tmp1;
        }
    }
}

static void mmi_netset_card2_sort_plmn_list_by_default(U16 total_record)
{
    U16 i;

    if (gCard2PrefListDisplay.SortingArray)
    {
        OslMfree(gCard2PrefListDisplay.SortingArray);
    }
    gCard2PrefListDisplay.SortingArray = OslMalloc(total_record * 2);

    for (i = 0; i < total_record; i++)
    {
        gCard2PrefListDisplay.SortingArray[i] = i;
    }
}

static void HiliteCard2HandlerAddNetworkPLMNList(S32 hiliteIdx)
{
    gCard2PrefListDisplay.CurrSelAddPLMN = (U16) hiliteIdx;
}

static pBOOL NETSETGetCard2PrefNetworkListItem(S32 item_index, UI_string_type str_buff, UI_image_type * img_buff_p,
                                               U8 str_img_mask)
{

    if (item_index < 0)
    {
        return FALSE;
    }

    MTPNP_PFAL_Unicode_String_Copy((S8 *) str_buff,
                                   GetString((U16)
                                             (bcdPlmnsToDisplayName[gCard2PrefListDisplay.SortingArray[item_index]].
                                              string_index + STR_PLMN_NAME_1)));
    *img_buff_p = NULL;

    return TRUE;
}

static S32 NETSETGetCard2PrefNetworkListHint(S32 item_index, UI_string_type * hint_array)
{
    U8 plmn_hint[MAX_PLMN_LEN_MMI + 1];

    mmi_netset_bcd_short_2_plmn_str(bcdPlmnsToDisplayName[gCard2PrefListDisplay.SortingArray[item_index]].plmn_bcd,
                                    plmn_hint);
    mmi_asc_to_ucs2((S8 *) * hint_array, (S8 *) plmn_hint);

    return TRUE;
}

/* preferred networks add list end */

/* preferred networks add options begin */
static void mmi_netset_card2_entry_add_from_list_options(void)
{
    PU8 guiBuffer;
    U16 nStrItemList[3];
    U16 nNumofItem;

    EntryNewScreen(SCR_MTPNP_ADD_FROM_LIST_OPTIONS, NULL, mmi_netset_card2_entry_add_from_list_options, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_ADD_FROM_LIST_OPTIONS);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_ADD_FROM_LIST_OPTIONS);

    GetSequenceStringIds_Ext(MENU_MTPNP_ADD_FROM_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_MTPNP_ADD_FROM_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         MAIN_MENU_TITLE_SETTINGS_ICON,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (PU16) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_netset_card2_highlight_add_from_list_done(void)
{
    SetLeftSoftkeyFunction(mmi_netset_card2_entry_add_from_list_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_card2_entry_add_from_list_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_netset_card2_entry_add_from_list_done(void)
{
    EntryCard2NETSETAddNetworkPriority();
}

static void mmi_netset_card2_highlight_sort_by_default(void)
{
    SetLeftSoftkeyFunction(mmi_netset_card2_entry_sort_by_default, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_netset_card2_entry_sort_by_default(void)
{
    gCard2PrefListDisplay.SortingMethod = 0;
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_MTPNP_ADD_FROM_LIST_OPTIONS);
}

static void mmi_netset_card2_highlight_sort_by_alphabet(void)
{
    SetLeftSoftkeyFunction(mmi_netset_card2_entry_sort_by_alphabet, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_netset_card2_entry_sort_by_alphabet(void)
{
    gCard2PrefListDisplay.SortingMethod = 1;
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_MTPNP_ADD_FROM_LIST_OPTIONS);
}

/* preferred networks add options end */

/* preferred networks add priority, req&rsp begin*/
static void EntryCard2NETSETAddNetworkPriority(void)
{
    PU8 guiBuffer;

    EntryNewScreen(SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PRIORITY, NULL, EntryCard2NETSETAddNetworkPriority, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PRIORITY);
    gCard2PrefListDisplay.PriorityVal = (S32) (gCard2PrefList.PrefListSize + 1);
    ShowCategory87Screen(STRING_MTPNP_NETSET_PRF_ADD_SHW_NWK_PRIORITY_TITLE, MAIN_MENU_TITLE_SETTINGS_ICON,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         1, (S32) (gCard2PrefList.PrefListSize + 1), &gCard2PrefListDisplay.PriorityVal, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(CheckThenAddCard2Network, KEY_EVENT_UP);
}

static void CheckThenAddCard2Network(void)
{
    if (IsCard2NetworkDuplicated() == 1 || (gCard2PrefListDisplay.PriorityVal > MAX_PREFFERED_PLMN)
        || (gCard2PrefListDisplay.PriorityVal > MTPNP_AD_Get_NoOfPLMNSupported()))
    {
        DisplayPopup((PU8) GetString(STR_ID_NETSET_PRF_NWK_ADDED_ERR), IMG_GLOBAL_UNFINISHED, 1,
                     ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    }
    else
    {
        NETSETAddCard2PrefNetworkReq();
    }
}

static U8 IsCard2NetworkDuplicated(void)
{
    U8 index;
    S8 pOutBuffer1[ENCODING_LENGTH * (MAX_PLMN_LEN + 1)];

    if (gCard2PrefListDisplay.IsNewPrefNetwork == 1)
    {
        memset(pOutBuffer1, 0, ENCODING_LENGTH * (MAX_PLMN_LEN + 1));
        mmi_ucs2_to_asc((PS8) pOutBuffer1, (PS8) gCard2PrefListDisplay.PlmnNew);
        for (index = 0; index < gCard2PrefList.PrefListSize; index++)
        {
            if ((strcmp(pOutBuffer1, (PS8) gCard2PrefList.PrefPLMN[index]) == 0))
            {
                return 1;
            }
        }
    }
    else
    {
        for (index = 0; index < gCard2PrefList.PrefListSize; index++)
        {
            if (bcdPlmnsToDisplayName[gCard2PrefListDisplay.SortingArray[gCard2PrefListDisplay.CurrSelAddPLMN]].plmn_bcd
                == mmi_netset_plmn_str_2_bcd_short(gCard2PrefList.PrefPLMN[index]))
            {
                return 1;
            }
        }
    }
    return 0;
}

static void NETSETAddCard2PrefNetworkReq(void)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ set_req;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP, NETSETAddCard2PrefNetworkRsp);

    set_req.index = gCard2PrefListDisplay.PriorityVal - 1;
    set_req.opcode = SMU_ADD_PLMNSEL;
    set_req.rat =
        (gCard2PrefList.SimFileIdx == FILE_PLMNSEL_IDX) ? 0 : (U8) gCard2PrefListDisplay.CurrSelectService + 1;

    memset(set_req.oper, 0, MAX_PLMN_LEN + 1);
    if (gCard2PrefListDisplay.IsNewPrefNetwork)
    {
        mmi_ucs2_to_asc((PS8) set_req.oper, (PS8) gCard2PrefListDisplay.PlmnNew);
        gCard2PrefListDisplay.IsNewPrefNetwork = 0;
    }
    else
    {
        U8 plmn[MAX_PLMN_LEN_MMI + 1];

        mmi_netset_bcd_short_2_plmn_str(bcdPlmnsToDisplayName
                                        [gCard2PrefListDisplay.SortingArray[gCard2PrefListDisplay.CurrSelAddPLMN]].
                                        plmn_bcd, plmn);
        memcpy(set_req.oper, plmn, (MAX_PLMN_LEN + 1));
    }

    MTPNP_AD_Set_Preferred_Network_Req(&set_req);
}

static void NETSETAddCard2PrefNetworkRsp(void *info)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *set_rsp = (ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP);

    if (set_rsp->result == MTPNP_FALSE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }

    /* diamond, 2006/05/25 Not use DeleteUptoScrID after set preferred network */
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PRIORITY);
    DeleteScreenIfPresent(SCR_MTPNP_ADD_FROM_LIST_OPTIONS);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_ADD_NEW_NETWORK_PLMN_LIST);
    
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_NEW_NETWORK);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);

    /*
    DeleteUptoScrID(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    */

    if (set_rsp->result == MMI_FALSE)
    {
        gCard2PrefList.comp_flag = 0;
        ExitCard2NETSETShowPreferredListReGet();
    }
    else
    {
        gCard2PrefList.comp_flag = 1;
        NETSETGetCard2PreferredNetworkReq();
    }
}

static void ExitCard2NETSETShowPreferredListReGet(void)
{
    U8 count;
    history Scr;
    U16 nHistory = 0;

    for (count = 0; count < gCard2PrefList.PrefListSize; ++count)
    {
        gCard2PrefListDisplay.nStrItemList[count] = NULL;
    }

    /* micha0531 */
    Scr.scrnID = SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST;
    Scr.entryFuncPtr = NETSETGetCard2PreferredNetworkReq;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    
    /* not always add this history to the top of history nodes */
    if ((isInCall() && !IsWapCallPresent()) || isOutgoingCall())
    {
        {
            PRINT_INFORMATION("isInCall return %d", isInCall());
            PRINT_INFORMATION("IsWapCallPresent return %d", IsWapCallPresent());
            PRINT_INFORMATION("isOutgoingCall return %d", isOutgoingCall());
        }
        InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
    }
    else
    {
        AddHistory(Scr);
    }

    /*
    GenericExitScreen(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST, NETSETGetCard2PreferredNetworkReq);
    */
}

/* preferred networks add priority, req&rsp end */

/* preferred networks new begin */
static void HighlightCard2NETSETNewPrefNwk(void)
{
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(EntryCard2NETSETNewNetwork, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2NETSETNewNetwork, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  InLineCard2PriorityUnchanged
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *InLineCard2PriorityUnchanged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    return gCard2PrefListDisplay.NewNwPriorityDisplay;
}


/*****************************************************************************
 * FUNCTION
 *  InLineCard2PriorityDefault
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *InLineCard2PriorityDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCard2PrefListDisplay.PriorityVal = gCard2PrefList.PrefListSize + 1;
    gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    return gCard2PrefListDisplay.NewNwPriorityDisplay;
}


/*****************************************************************************
 * FUNCTION
 *  InLineCard2PriorityMinusOne
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *InLineCard2PriorityMinusOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCard2PrefListDisplay.PriorityVal--;
    if (gCard2PrefListDisplay.PriorityVal <= 0)
    {
        gCard2PrefListDisplay.PriorityVal = gCard2PrefList.PrefListSize + 1;
    }

    gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    return gCard2PrefListDisplay.NewNwPriorityDisplay;
}


/*****************************************************************************
 * FUNCTION
 *  InLineCard2PriorityAddOne
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 *InLineCard2PriorityAddOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gCard2PrefListDisplay.PriorityVal < gCard2PrefList.PrefListSize + 1)
    {
        gCard2PrefListDisplay.PriorityVal++;
        gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    }
    else
    {
        gCard2PrefListDisplay.PriorityVal = 1;
        gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    }

    return gCard2PrefListDisplay.NewNwPriorityDisplay;
}


static void EntryCard2NETSETNewNetwork(void)
{
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    EntryNewScreen(SCR_MTPNP_NETSET_NEW_NETWORK, ExitCard2NETSETNewNetwork, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_NEW_NETWORK);
    inputBuffer = GetCurrNInputBuffer(SCR_MTPNP_NETSET_NEW_NETWORK, &inputBufferSize);

    InitializeCategory57Screen();
    FillCard2NewPrefNetworkInlineEditStruct();
    RegisterHighlightHandler(HighlightCard2NewEntryHandler);

    DisableCategory57ScreenDone();

    if (gCard2PrefList.SimFileIdx != FILE_PLMNSEL_IDX)
    {
        if (inputBuffer != NULL)
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLineCard2PriorityUnchanged,
                InLineCard2PriorityMinusOne,
                InLineCard2PriorityAddOne);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#else   
            SetCategory57Data(wgui_inline_items, 4, inputBuffer);
#endif
        }
        else
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLineCard2PriorityDefault,
                InLineCard2PriorityMinusOne,
                InLineCard2PriorityAddOne);
        }
        ShowCategory57Screen(
            STRING_MTPNP_NETSET_PRF_NWK_NEW,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#else   
            4,
#endif

            NULL,
            wgui_inline_items,
            1,
            guiBuffer);
    }
    else
    {
        if (inputBuffer != NULL)
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLineCard2PriorityUnchanged,
                InLineCard2PriorityMinusOne,
                InLineCard2PriorityAddOne);
            SetCategory57Data(wgui_inline_items, 4, inputBuffer);
        }
        else
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLineCard2PriorityDefault,
                InLineCard2PriorityMinusOne,
                InLineCard2PriorityAddOne);
        }
        ShowCategory57Screen(
            STRING_MTPNP_NETSET_PRF_NWK_NEW,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            4,
            NULL,
            wgui_inline_items,
            1,
            guiBuffer);
    }

/*
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 4, inputBuffer);
    }

    ShowCategory57Screen(STRING_MTPNP_NETSET_PRF_NWK_NEW, MAIN_MENU_TITLE_SETTINGS_ICON,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 4, NULL, wgui_inline_items, 1, guiBuffer);
    DisableCategory57ScreenDone();
*/ 
    SetCategory57RightSoftkeyFunctions(SendCard2NewPrr, GoBackHistory);
}

static void ExitCard2NETSETNewNetwork(void)
{
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    CloseCategory57Screen();
    Scr.scrnID = SCR_MTPNP_NETSET_NEW_NETWORK;
    Scr.entryFuncPtr = EntryCard2NETSETNewNetwork;
    mmi_ucs2cpy((S8 *) Scr.inputBuffer, (S8 *) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();
    GetCategory57Data((U8 *) Scr.inputBuffer);
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}

static void FillCard2NewPrefNetworkInlineEditStruct(void)
{
    memset(gCard2PrefListDisplay.PlmnNew, 0, (MAX_PLMN_LEN + 1) * ENCODING_LENGTH);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) (U8 *) GetString(STRING_MTPNP_NETSET_PRR_MCC_CAPTION));

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) (U8 *) GetString(STRING_MTPNP_NETSET_PRR_PR_CAPTION));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    if (gCard2PrefList.SimFileIdx != FILE_PLMNSEL_IDX)
    {
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
    }

    /*
    SetInlineItemUserDefinedSelect(&wgui_inline_items[3], InLinePriorityCard2Default, InLinePriorityCard2MinusOne,
                                   InLinePriorityCard2AddOne);
    */
    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8) gCard2PrefListDisplay.PlmnNew, MAX_PLMN_LEN + 1,
                          INPUT_TYPE_NUMERIC);
    SetInlineItemFullWidth(&wgui_inline_items[1]);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
}
/*
static U8 *InLinePriorityCard2Default(void)
{
    gCard2PrefListDisplay.PriorityVal = gCard2PrefList.PrefListSize + 1;
    gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    return gCard2PrefListDisplay.NewNwPriorityDisplay;
}

static U8 *InLinePriorityCard2MinusOne(void)
{
    gCard2PrefListDisplay.PriorityVal--;
    if (gCard2PrefListDisplay.PriorityVal <= 0)
    {
        gCard2PrefListDisplay.PriorityVal = 1;
    }
    gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    return gCard2PrefListDisplay.NewNwPriorityDisplay;
}

static U8 *InLinePriorityCard2AddOne(void)
{
    if (gCard2PrefListDisplay.PriorityVal < gCard2PrefList.PrefListSize + 1)
    {
        gCard2PrefListDisplay.PriorityVal++;
        gui_itoa(gCard2PrefListDisplay.PriorityVal, (UI_string_type) gCard2PrefListDisplay.NewNwPriorityDisplay, 10);
    }
    return gCard2PrefListDisplay.NewNwPriorityDisplay;
}
*/
static void HighlightCard2NewEntryHandler(S32 index)
{
    if (gCard2PrefListDisplay.PlmnNew[0] == 0)
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    }

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(SendCard2NewPrr, KEY_EVENT_UP);
}

static void SendCard2NewPrr(void)
{
    gCard2PrefListDisplay.IsNewPrefNetwork = 1;
    CloseCategory57Screen();
    if ((gCard2PrefListDisplay.PriorityVal > MTPNP_AD_Get_NoOfPLMNSupported())
        || (gCard2PrefListDisplay.PriorityVal > MAX_PREFFERED_PLMN) || (IsCard2NetworkDuplicated() == 1)
        || (mmi_ucs2strlen((PS8) gCard2PrefListDisplay.PlmnNew) < 5))
    {
        gCard2PrefListDisplay.IsNewPrefNetwork = 0;
        DisplayPopup((PU8) GetString(STR_ID_NETSET_PRF_NWK_ADDED_ERR), IMG_GLOBAL_UNFINISHED, 1,
                     ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    }
    else
    {
        if (gCard2PrefListDisplay.PriorityVal > gCard2PrefList.PrefListSize + 1)
        {
            gCard2PrefListDisplay.PriorityVal = gCard2PrefList.PrefListSize + 1;
        }
        NETSETAddCard2PrefNetworkReq();
    }
}

/* preferred networks new end */

/* preferred networks delete begin */
static void HighlightCard2NETSETDelPrefNwk(void)
{
    SetLeftSoftkeyFunction(EntryCard2NETSETConfirmDeleteNetwork, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void EntryCard2NETSETConfirmDeleteNetwork(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                   STR_GLOBAL_NO, IMG_GLOBAL_NO, get_string(STR_ID_SETTING_DELETE_ASK), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NETSETDeleteCard2PrefNetworkReq, KEY_EVENT_UP);
}

static void NETSETDeleteCard2PrefNetworkReq(void)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ set_req;

    /* set flag of del action */
    gCard2PrefListDelFlag = 1;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP, NETSETDeleteCard2PrefNetworkRsp);

    set_req.index = gCard2PrefListDisplay.CurrSelPrefNetwork;
    set_req.opcode = SMU_REMOVE_PLMNSEL;
    set_req.rat = gCard2PrefList.rat[gCard2PrefListDisplay.CurrSelPrefNetwork];
    memcpy(set_req.oper, gCard2PrefList.PrefPLMN[gCard2PrefListDisplay.CurrSelPrefNetwork], (MAX_PLMN_LEN + 1));

    MTPNP_AD_Set_Preferred_Network_Req(&set_req);
}

static void NETSETDeleteCard2PrefNetworkRsp(void *info)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *set_rsp = (ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP);

    if (set_rsp->result == MTPNP_FALSE)
    {
        gCard2PrefListDelFlag = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);

/*
    DeleteUptoScrID(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
*/
    if (set_rsp->result == MMI_FALSE)
    {
        gCard2PrefList.comp_flag = 0;
        gCard2PrefListDelFlag = 0;
        ExitCard2NETSETShowPreferredListReGet();
    }
    else
    {
        gCard2PrefList.comp_flag = 1;
        NETSETGetCard2PreferredNetworkReq();
    }

}

/* preferred networks delete end */

/* preferred networks edit begin */
static void HighlightCard2NETSETEditPrefNwk(void)
{
    SetLeftSoftkeyFunction(EntryCard2NETSETEditNetwork, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCard2NETSETEditNetwork, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void EntryCard2NETSETEditNetwork(void)
{
    PU8 guiBuffer;

    EntryNewScreen(SCR_MTPNP_NETSET_EDIT_NETWORK, NULL, EntryCard2NETSETEditNetwork, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_NETSET_EDIT_NETWORK);
    gCard2PrefListDisplay.PriorityVal = gCard2PrefListDisplay.CurrSelPrefNetwork + 1;
    ShowCategory87Screen(STRING_MTPNP_NETSET_PRF_ADD_SHW_NWK_PRIORITY_TITLE, MAIN_MENU_TITLE_SETTINGS_ICON,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         1, (S32) (gCard2PrefList.PrefListSize), &gCard2PrefListDisplay.PriorityVal, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NETSETCard2EditNetworkDeletePhaseReq, KEY_EVENT_UP);
}

static void NETSETCard2EditNetworkDeletePhaseReq(void)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ set_req;

    if (gCard2PrefListDisplay.PriorityVal == gCard2PrefListDisplay.CurrSelPrefNetwork + 1)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_EDIT_NETWORK);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
        
        if (IsScreenPresent(SCR_MTPNP_NETSET_MAIN))
        {
            GenericExitScreen(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST, EntryCard2NETSETShowPreferredList);
        }
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP, NETSETCard2EditNetworkDeletePhaseRsp);

    set_req.index = gCard2PrefListDisplay.CurrSelPrefNetwork;
    set_req.opcode = SMU_REMOVE_PLMNSEL;
    set_req.rat = gCard2PrefList.rat[gCard2PrefListDisplay.CurrSelPrefNetwork];
    memcpy(set_req.oper, gCard2PrefList.PrefPLMN[gCard2PrefListDisplay.CurrSelPrefNetwork], (MAX_PLMN_LEN + 1));

    MTPNP_AD_Set_Preferred_Network_Req(&set_req);
}

static void NETSETCard2EditNetworkDeletePhaseRsp(void *info)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *set_rsp = (ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP);

    if (set_rsp->result == MTPNP_FALSE || gCard2PrefList.PrefListSize <= gCard2PrefListDisplay.CurrSelPrefNetwork)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        
        /*
        DeleteUptoScrID(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
        */
        
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_EDIT_NETWORK);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS);
        DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);

        gCard2PrefList.comp_flag = 0;

        ExitCard2NETSETShowPreferredListReGet();
    }
    else
    {
        NETSETCard2EditNetworkAddPhaseReq();
    }
}

static void NETSETCard2EditNetworkAddPhaseReq(void)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_REQ set_req;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP, NETSETCard2EditNetworkAddPhaseRsp);

    set_req.index = gCard2PrefListDisplay.PriorityVal - 1;
    set_req.opcode = SMU_ADD_PLMNSEL;
    set_req.rat =
        (gCard2PrefList.SimFileIdx == FILE_PLMNSEL_IDX) ? 0 : (U8) gCard2PrefListDisplay.CurrSelectService + 1;
    memcpy(set_req.oper, gCard2PrefList.PrefPLMN[gCard2PrefListDisplay.CurrSelPrefNetwork], (MAX_PLMN_LEN + 1));

    MTPNP_AD_Set_Preferred_Network_Req(&set_req);
}

static void NETSETCard2EditNetworkAddPhaseRsp(void *info)
{
    ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *set_rsp = (ST_MTPNP_AD_SET_PREFERRED_NETWORK_RSP *) info;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SET_PREFERRED_NETWORKS_RSP);

    if (set_rsp->result == MTPNP_FALSE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }

    /*
    DeleteUptoScrID(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    */

    /* diamond, 2006/05/25 Not use DeleteUptoScrID after set preferred network */
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_EDIT_NETWORK);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREF_NWK_OPTIONS);
    DeleteScreenIfPresent(SCR_MTPNP_NETSET_SHOW_PREFERRED_LIST);
    
    if (set_rsp->result == MMI_FALSE)
    {
        gCard2PrefList.comp_flag = 0;
        ExitCard2NETSETShowPreferredListReGet();
    }
    else
    {
        gCard2PrefList.comp_flag = 1;
        NETSETGetCard2PreferredNetworkReq();
    }

}

/* preferred networks edit end */

static void mmi_netset_add_to_card2_plmn_list(U8* plmn_id)
{
    U8 i;

    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (strcmp((PS8)gCard2NetworkSetup.forbid_plmn_id[i], (PS8)plmn_id) == 0)
        {
            return;
        }

        if (gCard2NetworkSetup.forbid_plmn_id[i][0] == 0)
        {
            memcpy((PS8)gCard2NetworkSetup.forbid_plmn_id[i], (PS8)plmn_id, MAX_PLMN_LEN + 1);
            gCard2NetworkSetup.forbid_plmn[i] = 1;
            return;
        }
    }
}

static void mmi_netset_remove_from_card2_plmn_list(U8* plmn_id)
{
    U8 i;

    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (gCard2NetworkSetup.forbid_plmn_id[i][0] == 0)
        {
            return;
        }

        if (strcmp((PS8)gCard2NetworkSetup.forbid_plmn_id[i], (PS8)plmn_id) == 0)
        {
            memset(gCard2NetworkSetup.forbid_plmn_id[i], 0, MAX_PLMN_LEN + 1);
            gCard2NetworkSetup.forbid_plmn[i] = 0;
            return;
        }
    }
}

static U8 mmi_netset_find_in_card2_plmn_list(U8* plmn_id)
{
    U8 i;

    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (strcmp((PS8)gCard2NetworkSetup.forbid_plmn_id[i], (PS8)plmn_id) == 0 &&
            gCard2NetworkSetup.forbid_plmn[i] == 1)
        {
            return 1;
        }
    }

    return 0;
}

static void MTPNP_PFAL_NITZ_Ind(void *inMsg)
{
    ST_MTPNP_AD_NW_TIME_ZONE_IND *nitz = (ST_MTPNP_AD_NW_TIME_ZONE_IND *)inMsg;
    mmi_nw_time_zone_ind_struct *outMsg;
    U8 DeaultNWName[MAX_NW_LEN *ENCODING_LENGTH];
    U8 updateShortNW = 0, updateFullNW = 0;
    nitz_nw_name_struct nw_name; 
    S16 error;

    if (!PhnsetGetNITZFuncStatus())
    {
        return;
    }

    mmi_nitz_get_nitz_nw_name_sim2(NULL, DeaultNWName, MAX_NW_LEN *ENCODING_LENGTH, NULL);

    if (nitz->short_nw_nameP)
    {
        updateShortNW = mmi_nitz_get_nw_name(
                            nitz->short_nw_name_dcs,
                            nitz->short_nw_name_len,
                            (BOOL) nitz->short_nw_name_add_ci,
                            (S8*) NITZ_NWShortName,
                            (S8*) nitz->short_nw_name);
        PRINT_INFORMATION("[nitz]updateShortNW=%d", updateShortNW);
    }
    else
    {
        memset(NITZ_NWShortName, 0, MAX_NW_LEN * ENCODING_LENGTH);
        nitz->full_nw_name_len = 0;
    }

    if ((nitz->short_nw_nameP == 0 || nitz->short_nw_name_len == 0) && nitz->full_nw_nameP)
    {
        updateFullNW = mmi_nitz_get_nw_name(
                        nitz->full_nw_name_dcs,
                        nitz->full_nw_name_len,
                        (BOOL) nitz->full_nw_name_add_ci,
                        (S8*) NITZ_NWFullName,
                        (S8*) nitz->full_nw_name);
        PRINT_INFORMATION("[nitz]updateFullNW=%d", updateFullNW);
    }
    else    /* no time information, return */
    {
        memset(NITZ_NWFullName, 0, MAX_NW_LEN * ENCODING_LENGTH);
        nitz->short_nw_name_len = 0;
    }

    if (strlen((S8*) NITZ_NWShortName) != 0)
    {
        memcpy(&(nw_name.plmn),gPLMN_2, MAX_PLMN_LEN_MMI);
        memcpy(&(nw_name.name), &NITZ_NWShortName, MAX_NW_LEN *ENCODING_LENGTH);
        nw_name.add_ci = (U8) nitz->full_nw_name_add_ci;
        mmi_nitz_write_nw_name_to_nvram(2, &nw_name);
        
        mmi_idle_update_opname_from_nitz();
    }
    else if (strlen((S8*) NITZ_NWFullName) != 0)
    {
        memcpy(&(nw_name.plmn),gPLMN_2, MAX_PLMN_LEN_MMI);    
        memcpy(&nw_name.name, &NITZ_NWFullName, MAX_NW_LEN *ENCODING_LENGTH);
        nw_name.add_ci = (U8) nitz->full_nw_name_add_ci;
        mmi_nitz_write_nw_name_to_nvram(2, &nw_name);
        
        mmi_idle_update_opname_from_nitz();
    }
    else
    {
        memset(&(nw_name.plmn),0, MAX_PLMN_LEN_MMI);    
        memset(&nw_name.name, 0, MAX_NW_LEN *ENCODING_LENGTH);
        nw_name.add_ci = 0;
        mmi_nitz_write_nw_name_to_nvram(2, &nw_name);
        
        mmi_idle_update_opname_from_nitz();
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

    if ((MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && mmi_bootup_is_sim2_valid() == MMI_TRUE) ||
        (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD && mmi_bootup_is_sim2_valid() == MMI_TRUE && mmi_bootup_is_sim_valid() == MMI_FALSE))
    {
        outMsg = (mmi_nw_time_zone_ind_struct*)OslMalloc(sizeof(mmi_nw_time_zone_ind_struct));

        memset(outMsg, 0, sizeof(mmi_nw_time_zone_ind_struct));
        
        /* time zone */
        outMsg->nw_time_zoneP = nitz->nw_time_zoneP;
        outMsg->nw_time_zone = nitz->nw_time_zone;
        outMsg->nw_time_zone_time.time_zone = nitz->nw_time_zone;

        /* date/time */        
        outMsg->nw_time_zone_timeP = nitz->nw_time_zone_timeP;
        outMsg->nw_time_zone_time.year = (U8) (nitz->nw_time_zone_time.nYear);
        outMsg->nw_time_zone_time.month = nitz->nw_time_zone_time.nMonth;
        outMsg->nw_time_zone_time.day = nitz->nw_time_zone_time.nDay;
        outMsg->nw_time_zone_time.hour = nitz->nw_time_zone_time.nHour;
        outMsg->nw_time_zone_time.min = nitz->nw_time_zone_time.nMin;
        outMsg->nw_time_zone_time.sec = nitz->nw_time_zone_time.nSec;
        

        /* DST */
        outMsg->nw_day_light_saving_timeP = nitz->nw_day_light_saving_timeP;
        outMsg->nw_day_light_saving_time = nitz->nw_day_light_saving_time;

        NITZHandler((void*)outMsg);
        OslMfree(outMsg);
        return;
    }

    if (g_idle_context.IsOnIdleScreen)
    {
		EntryIdleScreen();
    }
}

/* master RF ctrl */
void MTPNP_PFAL_PwrOn_MasterRF(void *inMsg)
{
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 1;

    SetProtocolEventHandler(MTPNP_PFAL_PwrOn_MasterRF_Rsp, PRT_NW_CFUN_STATE_RSP);
    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType *) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);
}

void MTPNP_PFAL_PwrOff_MasterRF(void *inMsg)
{
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 4;

    SetProtocolEventHandler(MTPNP_PFAL_PwrOff_MasterRF_Rsp, PRT_NW_CFUN_STATE_RSP);
    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType *) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);
}

void MTPNP_PFAL_PwrOn_MasterRF_Rsp(void *info)
{
    mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct *) info;

    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);

    if (cfun_state_rsp->result == KAL_TRUE)
    {
        MTPNP_AD_MasterRF_PwrOn_Completed();
    }
}

void MTPNP_PFAL_PwrOff_MasterRF_Rsp(void *info)
{
    mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct *) info;

    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);

    if (cfun_state_rsp->result == KAL_TRUE)
    {
        MTPNP_AD_MasterRF_PwrOff_Completed();
    }
}

/* master RF ctrl */

/* read slave imei */
void MTPNP_PFAL_Get_Master_IMEI(MTPNP_UINT8 * imei)
{
    MTPNP_UCHAR imei_buf[9];

    if (imei == MTPNP_NULL)
        return;

    MTPNP_OSAL_memset(imei_buf, 0, 9);

    if (nvram_get_imei_value(8, imei_buf))
    {
        imei_buf[7] = imei_buf[7] | 0xf0;

        /* convert IMEI from BCD to ASCII and copy it into equip_string */
        convert_to_digit(imei_buf, imei);
    }
}

void MTPNP_PFAL_Refresh_Card2PLMN(void)
{
    MTPNP_UCHAR card2_plmn[SLAVE_NETWORK_ID_LEN];

    MTPNP_OSAL_memset(card2_plmn, 0, SLAVE_NETWORK_ID_LEN);
    MTPNP_AD_Get_Network_ID(card2_plmn);
    MTPNP_PFAL_RefreshNwProviderName(card2_plmn);
}

void MTPNP_PFAL_MMSRomaingIndication(MTPNP_UCHAR card2_roaming)
{
#ifdef MMS_SUPPORT
    wap_roaming_status_indication_callback(SIM2, (U32) card2_roaming);
#endif
}

#endif /* __MMI_DUAL_SIM_MASTER__ */

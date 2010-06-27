#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "GlobalMenuItems.h"
#include "GlobalDefs.h"
#include "GlobalConstants.h"
#include "HistoryGprot.h"
#include "CallHistoryEnum.h"
#include "EventsGprot.h"
#include "CommonScreens.h"
#include "CallsDefs.h"
#include "MainMenuDef.h"
#include "ShortcutsDefs.h"
#include "SettingProfile.h"
#include "PhoneBookTypes.h"
#include "PhoneBookResDef.h"
#include "MessagesMiscell.h"
#include "Nvram_common_defs.h"
#include "NVRAMEnum.h"
#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "AlarmProt.h"
#include "AlarmFrameworkProt.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"
#include "MessagesResourceData.h"
#include "MessagesExDcl.H"
#include "wgui_status_icons.h"
#include "PhoneBookGprot.h"
#include "IdleAppProt.h"
#include "CallHistoryGProts.h"
#include "SubLCDHistoryGprot.h "

#ifdef __MMI_UCM__
#include "UCMResDef.h"
#include "UCMGProt.h"
#endif /* __MMI_UCM__ */

#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_Callhistory.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_OSAL_common.h"

#ifdef __MMI_CH_OPTIONS_SENDSMS__
#include "SMSApi.h"
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */

#ifdef __MMI_CH_OPTIONS_SENDMMS__
#include "Wapadp.h"
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

#include "CallsLog.h"
#ifdef __MMI_GPRS_FEATURES__
#include "ProtocolEvents.h"
#endif /* __MMI_GPRS_FEATURES__ */
/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
static void HighlightDMCHISTMainMenu(void);
void EntryDMCHISTMainMenu(void);



extern void EV_ExitSlaveCHISTDialedListOptions(void) ;
extern void EV_ExitSlaveCHISTRecvdListOptions(void) ;
extern void EV_ExitSlaveCHISTMissedListOptions(void) ;

extern void EV_EntrySlaveCHISTViewDialedCallInfo(void) ;
extern void EV_EntrySlaveCHISTViewRecvdCallInfo(void) ;
extern void EV_EntrySlaveCHISTViewMissedCallInfo(void) ;


extern void EV_ExitSlaveCHISTViewDialedCall(void) ;
extern void EV_ExitSlaveCHISTViewRecvdCall(void) ;
extern void EV_ExitSlaveCHISTViewMissedCall(void) ;


extern void EV_MTPNP_PFAL_Call_Dialed(void);
extern void EV_MTPNP_PFAL_Call_Recved(void);
extern void EV_MTPNP_PFAL_Call_Missed(void);


/**************************LOCAL*FUNCTION*DECLARE*END*************************/

extern U8 addToHistory;
static ST_MTPNP_CALL_TIME_S g_Slave_Calltime;
static ST_MTPNP_CALLHIS_INFO Callhistiry_info[MTPNP_PFAL_MAX_CALLHISTORY_ENTRY];

static ST_MTPNP_CALLHIS_INFO dial_Callhistiry_info[MTPNP_PFAL_MAX_CALLHISTORY_ENTRY];
static ST_MTPNP_CALLHIS_INFO recv_Callhistiry_info[MTPNP_PFAL_MAX_CALLHISTORY_ENTRY];
static ST_MTPNP_CALLHIS_INFO miss_Callhistiry_info[MTPNP_PFAL_MAX_CALLHISTORY_ENTRY];


static MTPNP_PFAL_LASTMISSEDCALL_TYPE lastMissedCalltype = LASTMISSEDCALL_TYPE_NULL;
static MTPNP_UINT8 g_slave_chist_have_missed_call = 0;

extern pBOOL isInCall(void);
extern pBOOL IsWapCallPresent(void);
extern void MakeCall(PS8 strNumber);
extern void SetMissedCallFlag(pBOOL flag);

/* GPRS counter begin */
#ifdef __MMI_GPRS_FEATURES__
#include "CommonScreens.h"
U32 gSlavegprsTotalSent = 0;
U32 gSlavegprsTotalReceived = 0;
U32 gSlavegprsLastSent = 0;
U32 gSlavegprsLastReceived = 0;
#endif /* __MMI_GPRS_FEATURES__ */ 
/* GPRS counter end */

#if 1
// Huyanwei Add It For remark send key entry call history
static int g_get_call_history_by_send = 0 ;
static int g_get_call_history_by_send_type = 0;
#endif

void MTPNP_PFAL_SetLastMissedCallType(MTPNP_PFAL_LASTMISSEDCALL_TYPE type)
{
        lastMissedCalltype=type;
}

MTPNP_PFAL_LASTMISSEDCALL_TYPE MTPNP_PFAL_GetLastMissedCallType(void)
{
        return lastMissedCalltype;
}
    
static void DeleteCallLogSrc(void)
{
    DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_LIST);
    DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_LIST);
    DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_LIST);
    DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_INFO);
    DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_INFO);
    DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_INFO);
    DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_OPTION);
    DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_OPTION);
    DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_OPTION);
    DeleteScreenIfPresent(SCR_ID_CHIST_DUAL_CARD_MIXED_CALLLOG);
}

void MTPNP_PFAL_EntryDialedCallList(void)
{
    SetHiliteHandler(MENU_MTPNP_DM_CALL_HISTORY, HighlightDMCHISTMainMenu);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY, HighlightSlaveCHISTMainMenu);

    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_MISSED, HighlightSlaveCHISTMissedCalls);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_DIALED, HighlightSlaveCHISTDialedCalls);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_RECVD, HighlightSlaveCHISTRecvdCalls);

    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_DELETE, HighlightSlaveCHISTResetAllLogs);
    SetHiliteHandler(MENU_MTPNP_DELLOG_MISSED_CALLS, HighlightSlaveCHISTDeleteAllMissed);
    SetHiliteHandler(MENU_MTPNP_DELLOG_DIALED_CALLS, HighlightSlaveCHISTDeleteAllDialed);
    SetHiliteHandler(MENU_MTPNP_DELLOG_RECEIVED_CALLS, HighlightSlaveCHISTDeleteAllRecvd);
    SetHiliteHandler(MENU_MTPNP_ALL_CALLS, HighlightSlaveCHISTDeleteAllLogs);

    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_CALLTIME, HighlightSlaveCHISTCallTime);
    SetHiliteHandler(MENU_MTPNP_LAST_CALL_TIME, HighlightSlaveCHISTLastTime);
    SetHiliteHandler(MENU_MTPNP_CALL_OUT_TIME, HighlightSlaveCHISTSentTime);
    SetHiliteHandler(MENU_MTPNP_CALL_IN_TIME, HighlightSlaveCHISTRecvdTime);
    SetHiliteHandler(MENU_MTPNP_ALL_CALL_TIME, HighlightSlaveCHISTResetAllTime);

    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_SMSCOUNTER, HighlightSlaveCHISTSlaveSMSCount);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_SENT, HighlightSlaveCHISTSlaveSentSMS);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_RECEIVED, HighlightSlaveCHISTSlaveRecvdSMS);

    SetHiliteHandler(MENU_MTPNP_DIALED_CALL_MENU_INFO, HighlightSlaveCHISTInfoDialedNum);
    SetHiliteHandler(MENU_MTPNP_DIALED_CALL_MENU_DELETE, HighlightSlaveCHISTDeleteDialedNum);
    SetHiliteHandler(MENU_MTPNP_DIALED_CALL_MENU_SAVE, HighlightSlaveCHISTSaveDialedNum);
    SetHiliteHandler(MENU_MTPNP_DIALED_CALL_MENU_CALL, HighlightSIM2CHISTCall1DialedNum);
    SetHiliteHandler(MENU_MTPNP_DIALED_CALL_MENU_EDIT, HighlightSlaveCHISTEditDialedNum);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
    SetHiliteHandler(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS, HighlightSlaveCHISTSendSMSDialedNum);
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
    SetHiliteHandler(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS, HighlightSlaveCHISTSendMMSDialedNum);
#endif /* # __MMI_CH_OPTIONS_SENDMMS__ */

    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_MENU_INFO, HighlightSlaveCHISTInfoMissedNum);
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_MENU_DELETE, HighlightSlaveCHISTDeleteMissedNum);
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_MENU_SAVE, HighlightSlaveCHISTSaveMissedNum);
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_MENU_CALL, HighlightSIM2CHISTCall1MissedNum);
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_MENU_EDIT, HighlightSlaveCHISTEditMissedNum);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS, HighlightSlaveCHISTSendSMSMissedNum);
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS, HighlightSlaveCHISTSendMMSMissedNum);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */
    SetHiliteHandler(MENU_MTPNP_RECEIVED_CALL_MENU_INFO, HighlightSlaveCHISTInfoRecvdNum);
    SetHiliteHandler(MENU_MTPNP_RECEIVED_CALL_MENU_DELETE, HighlightSlaveCHISTDeleteRecvdNum);
    SetHiliteHandler(MENU_MTPNP_RECEIVED_CALL_MENU_SAVE, HighlightSlaveCHISTSaveRecvdNum);
    SetHiliteHandler(MENU_MTPNP_RECEIVED_CALL_MENU_CALL, HighlightSIM2CHISTCall1RecvdNum);
    SetHiliteHandler(MENU_MTPNP_RECEIVED_CALL_MENU_EDIT, HighlightSlaveCHISTEditRecvdNum);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
    SetHiliteHandler(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS, HighlightSlaveCHISTSendSMSRecvdNum);
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */
/* do not support sent mms from call history current */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
    SetHiliteHandler(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS, HighlightSlaveCHISTSendMMSRecvdNum);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */
    SetHintHandler(MENU_MTPNP_CALL_HISTORY_MISSED, HintSlaveCHISTMissedCalls);
    SetHintHandler(MENU_MTPNP_CALL_HISTORY_DIALED, HintSlaveCHISTDialedCalls);
    SetHintHandler(MENU_MTPNP_CALL_HISTORY_RECVD, HintSlaveCHISTRecvdCalls);

    SetHintHandler(MENU_MTPNP_DELLOG_MISSED_CALLS, HintSlaveCHISTDeleteAllMissed);
    SetHintHandler(MENU_MTPNP_DELLOG_DIALED_CALLS, HintSlaveCHISTDeleteAllDialed);
    SetHintHandler(MENU_MTPNP_DELLOG_RECEIVED_CALLS, HintSlaveCHISTDeleteAllRecvd);

    SetHintHandler(MENU_MTPNP_LAST_CALL_TIME, HintSlaveCHISTLastTime);
    SetHintHandler(MENU_MTPNP_CALL_OUT_TIME, HintSlaveCHISTSentTime);
    SetHintHandler(MENU_MTPNP_CALL_IN_TIME, HintSlaveCHISTRecvdTime);

    SetHintHandler(MENU_MTPNP_CALL_HISTORY_SENT, HintCHISTSlaveSentSMS);
    SetHintHandler(MENU_MTPNP_CALL_HISTORY_RECEIVED, HintCHISTSlaveRecvdSMS);

    InitSlaveCallHistoryContext();
}

void MTPNP_PFAL_CC_InitMissNotify(void)
{
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_NOTIFY_MASTER, HighlightCHISTMasterMissedNotify);
    SetHiliteHandler(MENU_MTPNP_MISSED_CALL_NOTIFY_SLAVE, HighlightCHISTSlaveMissedNotify);
    SetHintHandler(MENU_MTPNP_MISSED_CALL_NOTIFY_MASTER, HintCHISTMasterMissedNotify);
    SetHintHandler(MENU_MTPNP_MISSED_CALL_NOTIFY_SLAVE, HintCHISTSlaveMissedNotify);
}


#if !defined(__SENDKEY2_SUPPORT__) || defined(E8D)
void MTPNP_PFAL_CHIST_InitMixedCallLog(void)
{
    SetHiliteHandler(MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG_MASTER, HighlightCHISTDualMasterMixedCallLog);
    SetHiliteHandler(MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG_SLAVE, HighlightCHISTDualSlaveMixedCallLog);
}
#endif /* __SENDKEY2_SUPPORT__ */



static void HighlightDMCHISTMainMenu(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(EntryDMCHISTMainMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_UCM__
    SetKeyHandler(EntryDMCHISTMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_UCM__ */
}

void EntryDMCHISTMainMenu(void)
{
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_CALLHIS_MAIN_MENU, NULL, EntryDMCHISTMainMenu,
                         MENU_MTPNP_DM_CALL_HISTORY, MAIN_MENU_CALL_HISTORY_TEXT, GetRootTitleIcon(MAIN_MENU_CALL_HISTORY));
}

void HighlightSlaveCHISTMainMenu(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntrySlaveCHISTMainMenu, KEY_EVENT_UP);
    SetKeyHandler(EntrySlaveCHISTMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntrySlaveCHISTMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U16 ItemIcons[MAX_SUB_MENUS];
    U8 *PopUpList[MAX_SUB_MENUS];
    U16 LSKStr;
    U16 LSKImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S32       maskingByte=-1;
       S32               menuItemId=-1; */

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */

	 
#if 1
	// Huyanwei Add It 
	g_get_call_history_by_send =  0 ;
#endif
    /* Call Exit Handler */
#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    EntryNewScreen(SCR_MTPNP_CALLHIS_MAIN_MENU, wgui_restore_list_menu_slim_style, EntrySlaveCHISTMainMenu, NULL);
#else
    EntryNewScreen(SCR_MTPNP_CALLHIS_MAIN_MENU, NULL, EntrySlaveCHISTMainMenu, NULL);
#endif

    /* reset the indicies for dialed/recived/missed call list menus */
    Callhistiry_info->currRecvdCallIndex = 0;
    Callhistiry_info->currMissedCallIndex = 0;
    Callhistiry_info->currDialedCallIndex = 0;

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_CALLHIS_MAIN_MENU);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_CALL_HISTORY);    /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceStringIds_Ext(MENU_MTPNP_CALL_HISTORY, nStrItemList);    /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceImageIds_Ext(MENU_MTPNP_CALL_HISTORY, ItemIcons);        /* diamond, 2005/07/01 add _Ext to menu item functions */
    SetParentHandler(MENU_MTPNP_CALL_HISTORY);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);


    /* construct hint popup strings for menu items */
    ConstructHintsList(MENU_MTPNP_CALL_HISTORY, PopUpList);

#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
#endif

    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MENU_MTPNP_CALL_HISTORY);
#endif
    /* MTK Leo end */

    /* There may be no menu items in call log */
    if (nNumofItem == 0)
    {
        LSKStr = 0;
        LSKImg = 0;
    }
    else
    {
        LSKStr = STR_GLOBAL_OK;
        LSKImg = IMG_GLOBAL_OK;
    }
    /* Display the call history main screen */
    ShowCategory52Screen(STRING_MTPNP_CALL_HISTORY,
                         IMG_SCR_CALL_HISTORY_MAIN_MENU_CAPTION,
                         LSKStr, LSKImg, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nNumofItem, nStrItemList, ItemIcons, (U8 **) PopUpList, 0, 0,        /* u16callhist_curindex, */
                         guiBuffer);

    /* Register function with right softkey */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTResetAllLogs(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntrySlaveCHISTResetAllLogs, KEY_EVENT_UP);
    SetKeyHandler(EntrySlaveCHISTResetAllLogs, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntrySlaveCHISTResetAllLogs(void)
{
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U16 ItemIcons[MAX_SUB_MENUS];
    U8 *PopUpList[MAX_SUB_MENUS];

    /* Call Exit Handler */
#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    EntryNewScreen(SCR_MTPNP_CALLHISTORY_RESETCALL, wgui_restore_list_menu_slim_style, EntrySlaveCHISTResetAllLogs,
                   NULL);
#else

    EntryNewScreen(SCR_MTPNP_CALLHISTORY_RESETCALL, NULL, EntrySlaveCHISTResetAllLogs, NULL);
#endif

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_CALLHISTORY_RESETCALL);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_CALL_HISTORY_DELETE);
    GetSequenceStringIds_Ext(MENU_MTPNP_CALL_HISTORY_DELETE, nStrItemList);
    GetSequenceImageIds_Ext(MENU_MTPNP_CALL_HISTORY_DELETE, ItemIcons);
    SetParentHandler(MENU_MTPNP_CALL_HISTORY_DELETE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_MTPNP_CALL_HISTORY_DELETE, PopUpList);

#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
#endif

    /* Display the screen for the reset call logs */
    ShowCategory52Screen(STR_MENU8113_CALLHISTORY_RESETCALL,
                         IMG_SCR8056_CAPTION,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, ItemIcons, (U8 * *)PopUpList, 0, 0, guiBuffer);

    /* Register function with right softkey */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTDeleteAllMissed(void)
{
    U8 SlaveMissedCalls;
    //deleteallMissed=MTPNP_TRUE;
    SlaveMissedCalls = MTPNP_AD_Get_CallHistory_Missedcall();
    if (SlaveMissedCalls != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntrySlaveCHISTDeleteAllMissedConfirm, KEY_EVENT_UP);
    }

    else
    {
        ChangeLeftSoftkey(0, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTDeleteAllDialed(void)
{
    U8 SlaveDialedCalls;
    // deleteallDialed=MTPNP_TRUE;
    SlaveDialedCalls = MTPNP_AD_Get_CallHistory_Dialedcall();
    if (SlaveDialedCalls != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntrySlaveCHISTDeleteAllDialedConfirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTDeleteAllRecvd(void)
{
    U8 SlaveRecvdCalls;
    SlaveRecvdCalls = MTPNP_AD_Get_CallHistory_Recvdcall();
    // deleteallRecved=MTPNP_TRUE;
    if (SlaveRecvdCalls != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntrySlaveCHISTDeleteAllRecvdConfirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTDeleteAllLogs(void)
{
    U8 SlaveAllCalls;
    SlaveAllCalls =
        (MTPNP_AD_Get_CallHistory_Recvdcall() + MTPNP_AD_Get_CallHistory_Dialedcall() +
         MTPNP_AD_Get_CallHistory_Missedcall());
    if (SlaveAllCalls != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntrySlaveCHISTDeleteAllConfirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void MTPNP_PFAL_DelAllDialedCallHistory(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);

    MTPNP_AD_DelAllDialedCallHistory();
}

void MTPNP_PFAL_DelAllMissedCallHistory(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);

    MTPNP_AD_DelAllMissedCallHistory();
}

void MTPNP_PFAL_DelAllRecvedCallHistory(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);

    MTPNP_AD_DelAllRecvedCallHistory();
}

void MTPNP_PFAL_DelAllCallHistory(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);

    MTPNP_AD_DelAllCallHistory();
}

void EntrySlaveCHISTDeleteAllDialedConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_ID_CHIST_DELETE_QUERY), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_DelAllDialedCallHistory, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntrySlaveCHISTDeleteAllMissedConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_ID_CHIST_DELETE_QUERY), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_DelAllMissedCallHistory, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntrySlaveCHISTDeleteAllRecvdConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_ID_CHIST_DELETE_QUERY), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_DelAllRecvedCallHistory, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntrySlaveCHISTDeleteAllConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_ID_CHIST_DELETE_ALL_QUERY), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_DelAllCallHistory, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


#if 1
//Huyanwei Add It For CARD2 CAll Log(History)



extern void EntrySlaveReadCallHistoryBySend(void) ;
extern void EntrySlaveCallInfo(void) ;
extern void ev_slave_call_history_highlight(int ind);

static U8 *ev_slave_phoneNumbers[TOT_SIZE_OF_DIALED_LIST*3];
static U8 *ev_slave_phoneNames[TOT_SIZE_OF_DIALED_LIST*3];
 
static U8   ev_slave_DialedCalls=0, ev_slave_ReceivedCalls=0, ev_slave_MissedCalls=0;
static U8   ev_slave_current_call_history_index = 0 ;
#define READ_D   1
#define READ_R   2
#define READ_M  3


U8 *  sorted_name[/*MTPNP_AD_MAX_NAME_LEN*/ TOT_SIZE_OF_DIALED_LIST];
U8 *  sorted_number[ /* MTPNP_AD_MAX_CC_ADDR_LEN * 2 */ TOT_SIZE_OF_DIALED_LIST];	

typedef struct
{
	U8 * name ;
	U8 * number ;
	
	ST_MTPNP_AD_TIME starttime;
	ST_MTPNP_AD_TIME duration;
	MTPNP_UINT16 no_of_times;       
	
	MTPNP_CHAR CallLogType;
	MTPNP_CHAR CallLogOrginalIndex;
} ST_MTPNP_CALLHIS_LIST_INFO;
ST_MTPNP_CALLHIS_LIST_INFO CallHistoryListMapToOrginal[20];

void EntryCallingcallhistory(void)
{
	switch(CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogType)
	{
		case 0:
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\n Call Dial \r\n");
#endif
			EV_MTPNP_PFAL_Call_Dialed() ;
			break;
		case 1:			
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\n Call Recv \r\n");
#endif
			EV_MTPNP_PFAL_Call_Recved();
			break;
		case 2:
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\n Call Miss \r\n");
#endif
			EV_MTPNP_PFAL_Call_Missed() ;
			break;
		default :
			break;
	}	
}



//extern  CHISTSortCallLogsByTime();

#if 0
// Huyanwei Add It For Sort 
// Little ====> Big
void SortSlaveCardCalllogByTime(ST_MTPNP_CALLHIS_LIST_INFO * array,int size)
{
	ST_MTPNP_CALLHIS_LIST_INFO temp ;
	int i = 0 , j = 0 ;
	if( ( size <= 1 ) || (size >= 20 ))
		return ;

	for(i = 0 ; i < size-1; i++)
	{
		for(j = 0 ; j< size-1-i;j++)
		{
			if( CompareTime( array[j].starttime,array[j+1].starttime,NULL) == TIME_GREATER)
			{
				memcpy(&temp	, &array[j],sizeof(ST_MTPNP_CALLHIS_LIST_INFO));
				memcpy(&array[j] , &array[j+1],sizeof(ST_MTPNP_CALLHIS_LIST_INFO));
				memcpy(&array[j+1] ,&temp,sizeof(ST_MTPNP_CALLHIS_LIST_INFO));				
			}
		}
	}	
}
#else
//  Big ========> Little
void SortSlaveCardCalllogByTime(ST_MTPNP_CALLHIS_LIST_INFO * array,int size)
{
	ST_MTPNP_CALLHIS_LIST_INFO temp ;
	int i = 0 , j = 0 ;
	if(  size <= 1 )
		return ;

	for(i = 0 ; i < size-1; i++)
	{
		for(j = size -1  ; j > i; j --)
		{
			if( CompareTime( array[j].starttime,array[j-1].starttime,NULL) == TIME_GREATER)
			{
				memcpy(&temp	, &array[j],sizeof(ST_MTPNP_CALLHIS_LIST_INFO));
				memcpy(&array[j] , &array[j-1],sizeof(ST_MTPNP_CALLHIS_LIST_INFO));
				memcpy(&array[j-1] ,&temp,sizeof(ST_MTPNP_CALLHIS_LIST_INFO));				
			}
		}
	}	
}
#endif

#include "CallsResDef.h"

// As EntryCHISTViewMixedCallList()
void EntrySlaveCHISTViewAllCallList(void)
{

  U8 **phoneNumbers = ev_slave_phoneNumbers;
  U8 **phoneNames    = ev_slave_phoneNames;
  U8 *guiBuffer = NULL ;
  U16 Cat23DemoIcons[TOT_SIZE_OF_DIALED_LIST] ;
  U8 count = 0 ;
  
  U8 SlaveDialedCalls=ev_slave_DialedCalls;
  U8 SlaveReceivedCalls=ev_slave_ReceivedCalls ;
  U8 SlaveMissedCalls=ev_slave_MissedCalls;
  
  U16 index =  0 ;
  U8 name_len = 0 ;

    if (isInCall() && !IsWapCallPresent())
    {
        return;
    }

#if 1
     // Huyanwei Add It For Missed call icon
        // HideStatusIcon(STATUS_ICON_MISSED_CALL);
        MTPNP_AD_Set_MissedCallCount(0);
    #ifdef __MMI_DUAL_SIM_MASTER__
        HideStatusIcon(STATUS_ICON_CARD2MISSED_CALL);	
    #endif  /*__MMI_DUAL_SIM_MASTER__*/
        UpdateStatusIcons();
#endif

#if defined(NOKE_DEBUG)
    noke_dbg_printf("ev_slave_DialedCalls = %d,ev_slave_ReceivedCalls = %d ,ev_slave_MissedCalls = %d ",ev_slave_DialedCalls,ev_slave_ReceivedCalls,ev_slave_MissedCalls);
#endif
    EntryNewScreen(SCR8057_CALLS_LIST_MIXED, wgui_restore_list_menu_slim_style, EntrySlaveReadCallHistoryBySend, MMI_FULL_SCREEN);
    guiBuffer = GetCurrGuiBuffer(SCR8057_CALLS_LIST_MIXED);
    // RegisterHighlightHandler(CHISTGetCurrMixedCallIndex);	
    RegisterHighlightHandler(ev_slave_call_history_highlight);

     #if 1


	 #if 0
	for( count = 0 ; count < (SlaveDialedCalls+SlaveReceivedCalls+SlaveMissedCalls) ; count ++)
	{
		CallHistoryListMapToOrginal[count].name    =  phoneNames[count];
		CallHistoryListMapToOrginal[count].number =  phoneNumbers[count];		
		
		memcpy(&CallHistoryListMapToOrginal[count].starttime , &ev_slave_starttime[count],sizeof(ST_MTPNP_AD_TIME));	 
		
		CallHistoryListMapToOrginal[count].CallLogOrginalIndex = count ;
		
		if( count<SlaveDialedCalls)
		{
			CallHistoryListMapToOrginal[count].CallLogType = 0 ; // DIAL
		}
		else if( (count>= SlaveDialedCalls) && (count<SlaveDialedCalls+SlaveReceivedCalls))
		{
			CallHistoryListMapToOrginal[count].CallLogType =  1 ; // REc
		}
		else if( (count>=SlaveDialedCalls+SlaveReceivedCalls) && ( count <SlaveDialedCalls+SlaveReceivedCalls+SlaveMissedCalls))
		{
			CallHistoryListMapToOrginal[count].CallLogType = 2 ; // MISS
		}		
		
	}
	#else

	for( count = 0 ; count < SlaveDialedCalls ; count ++)
	{

		CallHistoryListMapToOrginal[count].CallLogType = 0 ; // Dial		
		CallHistoryListMapToOrginal[count].CallLogOrginalIndex = count ;	
		
		CallHistoryListMapToOrginal[count].name    =  phoneNames[count];
		CallHistoryListMapToOrginal[count].number =  phoneNumbers[count];				
	
		memcpy(&CallHistoryListMapToOrginal[count].starttime , &dial_Callhistiry_info[count].startTime,sizeof(ST_MTPNP_AD_TIME));	 		
		memcpy(&CallHistoryListMapToOrginal[count].duration, &dial_Callhistiry_info[count].duration,sizeof(ST_MTPNP_AD_TIME));	 	

#if defined(NOKE_DEBUG)
		noke_dbg_printf("Dial Sort Before: %d-%d-%d-%d-%d-%d\r\n"
			,dial_Callhistiry_info[count].startTime.nYear
			,dial_Callhistiry_info[count].startTime.nMonth
			,dial_Callhistiry_info[count].startTime.nDay
			,dial_Callhistiry_info[count].startTime.nHour
			,dial_Callhistiry_info[count].startTime.nMin
			,dial_Callhistiry_info[count].startTime.nSec
			);

		noke_dbg_printf("Dial Call Sort Before: %d-%d-%d-%d-%d-%d\r\n"
			,CallHistoryListMapToOrginal[count].starttime.nYear
			,CallHistoryListMapToOrginal[count].starttime.nMonth
			,CallHistoryListMapToOrginal[count].starttime.nDay
			,CallHistoryListMapToOrginal[count].starttime.nHour
			,CallHistoryListMapToOrginal[count].starttime.nMin
			,CallHistoryListMapToOrginal[count].starttime.nSec
			);
#endif		
		CallHistoryListMapToOrginal[count].no_of_times = dial_Callhistiry_info[count].no_of_times ;
		
	}

	for( count = (SlaveDialedCalls+0) ; count < (SlaveReceivedCalls+SlaveDialedCalls) ; count ++)
	{
		CallHistoryListMapToOrginal[count].CallLogType = 1 ; // Recv
		CallHistoryListMapToOrginal[count].CallLogOrginalIndex = count-SlaveDialedCalls  ;		
			
		CallHistoryListMapToOrginal[count].name    =  phoneNames[count];
		CallHistoryListMapToOrginal[count].number =  phoneNumbers[count];				
		
		memcpy(&CallHistoryListMapToOrginal[count].starttime , &recv_Callhistiry_info[count-SlaveDialedCalls].startTime,sizeof(ST_MTPNP_AD_TIME));	 		
		memcpy(&CallHistoryListMapToOrginal[count].duration,   &recv_Callhistiry_info[count-SlaveDialedCalls].duration,  sizeof(ST_MTPNP_AD_TIME));	

#if defined(NOKE_DEBUG)
		noke_dbg_printf("Recv Sort Before: %d-%d-%d-%d-%d-%d\r\n"
		,recv_Callhistiry_info[count-SlaveDialedCalls].startTime.nYear
		,recv_Callhistiry_info[count-SlaveDialedCalls].startTime.nMonth
		,recv_Callhistiry_info[count-SlaveDialedCalls].startTime.nDay
		,recv_Callhistiry_info[count-SlaveDialedCalls].startTime.nHour
		,recv_Callhistiry_info[count-SlaveDialedCalls].startTime.nMin
		,recv_Callhistiry_info[count-SlaveDialedCalls].startTime.nSec
		);

		noke_dbg_printf("Recv Call Sort Before: %d-%d-%d-%d-%d-%d\r\n"
		,CallHistoryListMapToOrginal[count].starttime.nYear
		,CallHistoryListMapToOrginal[count].starttime.nMonth
		,CallHistoryListMapToOrginal[count].starttime.nDay
		,CallHistoryListMapToOrginal[count].starttime.nHour
		,CallHistoryListMapToOrginal[count].starttime.nMin
		,CallHistoryListMapToOrginal[count].starttime.nSec
		);
#endif
		CallHistoryListMapToOrginal[count].no_of_times = recv_Callhistiry_info[count].no_of_times ;				

	}

	for( count = (SlaveReceivedCalls+SlaveDialedCalls) ; count < (SlaveReceivedCalls+SlaveDialedCalls+SlaveMissedCalls) ; count ++)
	{
		CallHistoryListMapToOrginal[count].CallLogType = 2 ; // Miss
		CallHistoryListMapToOrginal[count].CallLogOrginalIndex = count -(SlaveReceivedCalls+SlaveDialedCalls) ;		
		
		CallHistoryListMapToOrginal[count].name    =  phoneNames[count];
		CallHistoryListMapToOrginal[count].number =  phoneNumbers[count];				
		
		memcpy(&CallHistoryListMapToOrginal[count].starttime , &miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].startTime,sizeof(ST_MTPNP_AD_TIME));	 		
		memcpy(&CallHistoryListMapToOrginal[count].duration,   &miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].duration,  sizeof(ST_MTPNP_AD_TIME));	 

#if defined(NOKE_DEBUG)
		noke_dbg_printf("Miss Sort Before: %d-%d-%d-%d-%d-%d\r\n"
		,miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].startTime.nYear
		,miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].startTime.nMonth
		,miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].startTime.nDay
		,miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].startTime.nHour
		,miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].startTime.nMin
		,miss_Callhistiry_info[count -(SlaveReceivedCalls+SlaveDialedCalls)].startTime.nSec
		);

		noke_dbg_printf("Miss Call Sort Before: %d-%d-%d-%d-%d-%d\r\n"
		,CallHistoryListMapToOrginal[count].starttime.nYear
		,CallHistoryListMapToOrginal[count].starttime.nMonth
		,CallHistoryListMapToOrginal[count].starttime.nDay
		,CallHistoryListMapToOrginal[count].starttime.nHour
		,CallHistoryListMapToOrginal[count].starttime.nMin
		,CallHistoryListMapToOrginal[count].starttime.nSec
		);		
#endif
		CallHistoryListMapToOrginal[count].no_of_times = miss_Callhistiry_info[count].no_of_times ;						

	}
	
	#endif
	
	SortSlaveCardCalllogByTime(CallHistoryListMapToOrginal,SlaveDialedCalls+SlaveReceivedCalls+SlaveMissedCalls);

	for(count = 0 ; count < (SlaveDialedCalls+SlaveReceivedCalls+SlaveMissedCalls) ; count ++)
	{
		sorted_name[count] = CallHistoryListMapToOrginal[count].name;
		sorted_number[count] = CallHistoryListMapToOrginal[count].number;	
#if defined(NOKE_DEBUG)
		noke_dbg_printf("Sort After:%d-%d-%d-%d-%d-%d\r\n"
			,CallHistoryListMapToOrginal[count].starttime.nYear
			,CallHistoryListMapToOrginal[count].starttime.nMonth
			,CallHistoryListMapToOrginal[count].starttime.nDay
			,CallHistoryListMapToOrginal[count].starttime.nHour
			,CallHistoryListMapToOrginal[count].starttime.nMin
			,CallHistoryListMapToOrginal[count].starttime.nSec
			);
#endif
		switch(CallHistoryListMapToOrginal[count].CallLogType)
		{
			case 0:
				Cat23DemoIcons[count] = IMG_MTPNP_CARD2_MENU_DIALED_CALLS;
			break;
			case 1:
				Cat23DemoIcons[count] = IMG_MTPNP_CARD2_MENU_RECEIVED_CALLS;
			break;
			case 2:
				Cat23DemoIcons[count] = IMG_MTPNP_CARD2_MENU_MISSED_CALLS;
			break;
			default:
				break;
		}
	}
	
     #endif

	#if 1
	// Huyanwei Add it For REad missed call
	DeleteScreenIfPresent(ITEM_SCR_MISSED_CALL);		
	#endif

    if ((SlaveDialedCalls+SlaveReceivedCalls+SlaveMissedCalls) > 0)
    {
	     wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
	     if (GetExitScrnID() == SCR8057_CALLS_LIST_MIXED)
	        {
	            ShowCategory53Screen(
	                STR_SCR8057_CAPTION,
	                IMG_SCR8057_CAPTION,
	                STR_GLOBAL_OK,
	                IMG_GLOBAL_OK,
	                STR_GLOBAL_BACK,
	                IMG_GLOBAL_BACK,
	                SlaveDialedCalls+SlaveReceivedCalls+SlaveMissedCalls,
	                /* phoneNames */ sorted_name ,
	        	  (U16*) Cat23DemoIcons,
	                /* phoneNumbers */sorted_number ,
	                0,
	    	         /*0*/ ev_slave_current_call_history_index,
	                guiBuffer);
	       }

	      MTPNP_PFAL_CC_HandleSendKeys(EntryCallingcallhistory, KEY_EVENT_DOWN);
		  
	      SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);		  
	      SetKeyHandler(EntrySlaveCallInfo, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		  
	      SetLeftSoftkeyFunction(EntrySlaveCallInfo, KEY_EVENT_UP);
	      SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
		  
     }
     else    	
     {
		  //GoBackHistory(); // Huyanwei Del It 
/*shaokai modify it start 090902*/
		  //GoBackToHistory(MAIN_MENU_SCREENID);
		  GoBackToHistory(IDLE_SCREEN_ID);
/*shaokai modify it end 090902*/
		  
                DisplayPopup(
                (PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
                IMG_GLOBAL_EMPTY,
                1,
                CS_NOTIFYDURATION,
                EMPTY_LIST_TONE);

     }	 

}





void ev_slave_call_history_highlight(int ind)
{

#if 0
	if( ( ind >= 0 )  && (ind < ev_slave_DialedCalls))
	{
		Callhistiry_info->currDialedCallIndex = ind ;
	}
	else if ( (ind>= ev_slave_DialedCalls )  && (ind< (ev_slave_DialedCalls+ev_slave_ReceivedCalls)))
	{
		Callhistiry_info->currRecvdCallIndex = ind - ev_slave_DialedCalls ;
	}
	else if ( (ind >= (ev_slave_DialedCalls+ev_slave_ReceivedCalls ) ) && (ind < (ev_slave_DialedCalls+ev_slave_ReceivedCalls+ev_slave_MissedCalls)))
	{
		Callhistiry_info->currMissedCallIndex= ind - (ev_slave_DialedCalls+ev_slave_ReceivedCalls);
	}

	ev_slave_current_call_history_index  = ind  ;

#else

	if (CallHistoryListMapToOrginal[ind].CallLogType == 0)  // dial
	{
		memcpy(Callhistiry_info,dial_Callhistiry_info,sizeof(dial_Callhistiry_info));
		Callhistiry_info->currDialedCallIndex = CallHistoryListMapToOrginal[ind].CallLogOrginalIndex ;
	}
	else if (CallHistoryListMapToOrginal[ind].CallLogType == 1 )  // rec
	{
		memcpy(Callhistiry_info,recv_Callhistiry_info,sizeof(recv_Callhistiry_info));
		Callhistiry_info->currRecvdCallIndex  = CallHistoryListMapToOrginal[ind].CallLogOrginalIndex ;
	}
	else if (CallHistoryListMapToOrginal[ind].CallLogType == 2 )  // miss
	{
		memcpy(Callhistiry_info,miss_Callhistiry_info,sizeof(miss_Callhistiry_info));
		Callhistiry_info->currMissedCallIndex= CallHistoryListMapToOrginal[ind].CallLogOrginalIndex ;
	}
#if defined(NOKE_DEBUG)
	noke_dbg_printf("CallHistoryListMapToOrginal[ind].CallLogType = %d\r\nCallhistiry_info->currDialedCallIndex = %d\r\nCallhistiry_info->currRecvdCallIndex=%d\r\nCallhistiry_info->currMissedCallIndex = %d \r\n",CallHistoryListMapToOrginal[ind].CallLogType ,Callhistiry_info->currDialedCallIndex,Callhistiry_info->currRecvdCallIndex,Callhistiry_info->currMissedCallIndex);
#endif	
	ev_slave_current_call_history_index  =  ind   ;		
#endif
}


void EntrySlaveCallInfo(void)
{
	int Calllogtype  = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogType;
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nCalllogtype = %d  \r\n",Calllogtype) ;
	noke_dbg_printf("\r\nCallhistiry_info->currDialedCallIndex = %d\r\nCallhistiry_info->currRecvdCallIndex=%d\r\nCallhistiry_info->currMissedCallIndex = %d \r\n",Callhistiry_info->currDialedCallIndex,Callhistiry_info->currRecvdCallIndex,Callhistiry_info->currMissedCallIndex);
#endif
	switch (Calllogtype)
	{
		case 0:
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\nCall EntrySlaveCHISTView   DialedCallInfo  \r\n") ;
#endif
			Callhistiry_info->currDialedCallIndex = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex ;
			EV_EntrySlaveCHISTViewDialedCallInfo() ;
			break;
		case 1:
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\nCall EntrySlaveCHISTView   RecvdCallInfo  \r\n") ;
#endif
			Callhistiry_info->currRecvdCallIndex  = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex ;
			EV_EntrySlaveCHISTViewRecvdCallInfo();
			break;
		case 2:
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\nCall EntrySlaveCHISTView  MissedCallInfo  \r\n") ;
#endif
			Callhistiry_info->currMissedCallIndex= CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex ;
			EV_EntrySlaveCHISTViewMissedCallInfo();
			break;
	}
}


void GetSlaveCHISTAllCallListByType(int type)
{
	U8 **phoneNumbers= ev_slave_phoneNumbers;
	U8 **phoneNames=ev_slave_phoneNames;

	U16 Cat23DemoIcons[TOT_SIZE_OF_DIALED_LIST];
	U8 count =  0 ;
	U8 SlaveDialedCalls = 0 , SlaveReceivedCalls= 0 , SlaveMissedCalls = 0 ;
	U16 index = 0 ;
	U8 name_len =  0 ;

	switch( type )
	{
		case READ_D:
		  /* dialed */
		  SlaveDialedCalls = MTPNP_AD_Get_CallHistory_Dialedcall();
		  if( SlaveDialedCalls)
		  {
		     for (index = 0; index < SlaveDialedCalls && index < MTPNP_PFAL_MAX_CALLHISTORY_ENTRY ; index++)
		      {
		          name_len = MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) dial_Callhistiry_info[index].name);
		          MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) dial_Callhistiry_info[index].number);
			   MTPNP_AD_Get_DialedCallHistory_StratTime(index, &dial_Callhistiry_info[index].startTime);
			   dial_Callhistiry_info[index].no_of_times = MTPNP_AD_Get_DialedCallHistory_no_of_times(index);
			   dial_Callhistiry_info[index].duration = MTPNP_AD_Get_DialedCallHistory_duration(index);

#if defined(NOKE_DEBUG)
			   noke_dbg_printf("\r\nDial:%d-%d-%d-%d-%d-%d\r\n"
			,dial_Callhistiry_info[index].startTime.nYear
			,dial_Callhistiry_info[index].startTime.nMonth
			,dial_Callhistiry_info[index].startTime.nDay
			,dial_Callhistiry_info[index].startTime.nHour
			,dial_Callhistiry_info[index].startTime.nMin
			,dial_Callhistiry_info[index].startTime.nSec
			);
#endif
			   
		          if (name_len)
		          {
		              phoneNames[index] = (MTPNP_UINT8 *) dial_Callhistiry_info[index].name;
		              phoneNumbers[index] = (MTPNP_UINT8 *) dial_Callhistiry_info[index].number;
		          }
		          else
		          {
		              if (dial_Callhistiry_info[index].number[0] != 0)
		              {
		                  phoneNames[index] = (MTPNP_UINT8 *) dial_Callhistiry_info[index].number;
		              }
		              else
		              {
		                  phoneNames[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
		              }
		              phoneNumbers[index] = NULL;
		          }			   
		      }
		   }
		ev_slave_DialedCalls = index;
		break;
	case READ_R:

		/* received */
		SlaveReceivedCalls = MTPNP_AD_Get_CallHistory_Recvdcall();
		if(SlaveReceivedCalls)
		{
		     for (index = 0; index < SlaveReceivedCalls && index < MTPNP_PFAL_MAX_CALLHISTORY_ENTRY; index++)
		      {
		          name_len = MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) recv_Callhistiry_info[index].name);
		          MTPNP_AD_Get_RecvdCallHistory_Number(index, (MTPNP_UINT8 *) recv_Callhistiry_info[index].number);
			   MTPNP_AD_Get_RecvdCallHistory_StratTime(index, &recv_Callhistiry_info[index].startTime);
			   recv_Callhistiry_info[index].no_of_times = MTPNP_AD_Get_RecvdCallHistory_no_of_times(index);
			   recv_Callhistiry_info[index].duration = MTPNP_AD_Get_RecvdCallHistory_duration(index);	

#if defined(NOKE_DEBUG)
			   noke_dbg_printf("\r\nRecv:%d-%d-%d-%d-%d-%d\r\n"
			,recv_Callhistiry_info[index].startTime.nYear
			,recv_Callhistiry_info[index].startTime.nMonth
			,recv_Callhistiry_info[index].startTime.nDay
			,recv_Callhistiry_info[index].startTime.nHour
			,recv_Callhistiry_info[index].startTime.nMin
			,recv_Callhistiry_info[index].startTime.nSec
			);
#endif			   	
		          if (name_len)
		          {
		              phoneNames[index+ev_slave_DialedCalls] = (MTPNP_UINT8 *) recv_Callhistiry_info[index].name;
		              phoneNumbers[index+ev_slave_DialedCalls] = (MTPNP_UINT8 *) recv_Callhistiry_info[index].number;
		          }
		          else
		          {
		              if (recv_Callhistiry_info[index].number[0] != 0)
		              {
		                  phoneNames[index+ev_slave_DialedCalls] = (MTPNP_UINT8 *) recv_Callhistiry_info[index].number;
		              }
		              else
		              {
		                  phoneNames[index+ev_slave_DialedCalls] = (PU8) GetString(STR_UNKNOWN_NUMBER);
		              }
		              phoneNumbers[index+ev_slave_DialedCalls] = NULL;
		          }
		      }
		}
		ev_slave_ReceivedCalls = index;
		break;
	case READ_M:
		/* missed */

		SlaveMissedCalls =MTPNP_AD_Get_CallHistory_Missedcall();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("ev_slave_DialedCalls = %d,ev_slave_ReceivedCalls = %d ,SlaveMissedCalls = %d ",ev_slave_DialedCalls,ev_slave_ReceivedCalls,SlaveMissedCalls);
#endif
		if(SlaveMissedCalls)
		{
		     for (index = 0; index < SlaveMissedCalls  && index < MTPNP_PFAL_MAX_CALLHISTORY_ENTRY ; index++)
		      {
		          name_len = MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) miss_Callhistiry_info[index].name);
		          MTPNP_AD_Get_MissedCallHistory_Number(index, (MTPNP_UINT8 *) miss_Callhistiry_info[index].number);
  			   MTPNP_AD_Get_MissedCallHistory_StratTime(index, &miss_Callhistiry_info[index].startTime);

#if defined(NOKE_DEBUG)
    			   noke_dbg_printf("\r\nMiss:%d-%d-%d-%d-%d-%d\r\n"
			,miss_Callhistiry_info[index].startTime.nYear
			,miss_Callhistiry_info[index].startTime.nMonth
			,miss_Callhistiry_info[index].startTime.nDay
			,miss_Callhistiry_info[index].startTime.nHour
			,miss_Callhistiry_info[index].startTime.nMin
			,miss_Callhistiry_info[index].startTime.nSec
			);
#endif
   			   miss_Callhistiry_info[index].no_of_times = MTPNP_AD_Get_MissedCallHistory_no_of_times(index);
			   memset( &miss_Callhistiry_info[index].duration,0,sizeof(ST_MTPNP_AD_TIME));
		          if (name_len)
		          {
		              phoneNames[index+ev_slave_DialedCalls+ ev_slave_ReceivedCalls] = (MTPNP_UINT8 *) miss_Callhistiry_info[index].name;
		              phoneNumbers[index+ev_slave_DialedCalls+ ev_slave_ReceivedCalls] = (MTPNP_UINT8 *) miss_Callhistiry_info[index].number;
		          }
		          else
		          {
		              if (miss_Callhistiry_info[index].number[0] != 0)
		              {
		                  phoneNames[index+ev_slave_DialedCalls+ ev_slave_ReceivedCalls] = (MTPNP_UINT8 *) miss_Callhistiry_info[index].number;
		              }
		              else
		              {
		                  phoneNames[index+ev_slave_DialedCalls+ ev_slave_ReceivedCalls] = (PU8) GetString(STR_UNKNOWN_NUMBER);
		              }
		              phoneNumbers[index+ev_slave_DialedCalls+ ev_slave_ReceivedCalls] = NULL;
		          }
		      }
		}
		ev_slave_MissedCalls  = index;
		break;
	default:
		break;
	}

}


void EV_callHistory_slave_rsp_read_dialed_num()
{
	mmi_chist_set_sentreq_flag(MTPNP_FALSE);
	GetSlaveCHISTAllCallListByType(READ_D);
	g_get_call_history_by_send_type = READ_R;
	MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key();
	mmi_chist_set_sentreq_flag(TRUE);

}

void EV_callHistory_slave_rsp_read_received_num()
{
	mmi_chist_set_sentreq_flag(MTPNP_FALSE);
	GetSlaveCHISTAllCallListByType(READ_R);
	g_get_call_history_by_send_type = READ_M;
	MTPNP_PFAL_chist_slave_req_read_missed_num_by_key();
       mmi_chist_set_sentreq_flag(TRUE);
}

void EV_callHistory_slave_rsp_read_missed_num()
{
	mmi_chist_set_sentreq_flag(MTPNP_FALSE);
	GetSlaveCHISTAllCallListByType(READ_M);
	g_get_call_history_by_send_type =  0 ;
	EntrySlaveCHISTViewAllCallList();
	AlmEnableExpiryHandler();
	// g_get_call_history_by_send = 0 ; // Huyanwei del It 
}


// Huyanwei Add It 
void EntrySlaveReadCallHistoryBySend(void)
{
	ev_slave_DialedCalls = 0;
	ev_slave_ReceivedCalls =0;
	ev_slave_MissedCalls =0;

	g_get_call_history_by_send = 1 ;
	g_get_call_history_by_send_type = READ_D;

       // ev_slave_current_call_history_index =  0 ;

	MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key();
	mmi_chist_set_sentreq_flag(TRUE);
}

#endif


void MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntrySlaveCHISTViewDialedCallList();
        return;
    }
    
    if (mmi_chist_get_sentreq_flag() == TRUE)
    {
        return;
    }

    if (mmi_chist_get_processing_flag() == CALL_LOG_PROC_WRITE)
    {
        PRINT_INFORMATION("still writing, wait till write complete then read!!!!");
        mmi_chist_set_processing_flag(CALL_LOG_PROC_SYNC);
        return;
    }

    if (MTPNP_AD_Calllog_GetStatus() == MTPNP_TRUE)
    {
        AlmDisableExpiryHandler();
        /* clear all key event handler */
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        MTPNP_AD_slave_req_read_dialed_num();
        mmi_chist_set_sentreq_flag(TRUE);
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8054_CAPTION,
            IMG_SCR8054_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}

void MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntrySlaveCHISTViewDialedCallList();
        return;
    }

    if (mmi_chist_get_sentreq_flag()== TRUE)
    {
        return;
    }

    if (MTPNP_AD_Calllog_GetStatus() == MTPNP_TRUE)
    {
        AlmDisableExpiryHandler();
        /* clear all key event handler */
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        MTPNP_AD_slave_req_read_dialed_num();
        mmi_chist_set_sentreq_flag(TRUE);
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8054_CAPTION,
            IMG_SCR8054_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


void MTPNP_PFAL_chist_slave_rsp_read_dialed_num(void)
{
#if 0
// Huyanwei Add It 
	if (g_get_call_history_by_send == 1 )
	{
		EV_callHistory_slave_rsp_read_dialed_num();
		return  ;
	}
#endif
    mmi_chist_set_sentreq_flag(MTPNP_FALSE);
    EntrySlaveCHISTViewDialedCallList();
    AlmEnableExpiryHandler();
    return;
}


void HighlightSlaveCHISTDialedCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CH_MIXED_CALL_LOG__
    chis_p->isMixedStyle = FALSE;
#endif 
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    if (!call_log_on_idle)
#endif 
    {
        SetKeyHandler(MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    else
    {
        disable_tab_pane_keys();
    }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntrySlaveCHISTViewDialedCallList(void)
{
	    /*----------------------------------------------------------------*/
	    /* Local Variables                                                */
	    /*----------------------------------------------------------------*/
	    U8 *phoneNumbers[TOT_SIZE_OF_DIALED_LIST];
	    U8 *phoneNames[TOT_SIZE_OF_DIALED_LIST];
	    U8 *guiBuffer;
	    U16 Cat23DemoIcons[TOT_SIZE_OF_DIALED_LIST];
	    U8 count;
	    U8 SlaveDialedCalls;
	    U16 index;
	    U8 name_len;
		
	if (g_get_call_history_by_send != 1 )
	{
	    /*----------------------------------------------------------------*/
	    /* Code Body                                                      */
	    /*----------------------------------------------------------------*/
	    SlaveDialedCalls = MTPNP_AD_Get_CallHistory_Dialedcall();

	    if (isInCall() && !IsWapCallPresent())
	    {
	        return;
	    }

	    if (SlaveDialedCalls)
	    {
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
	        if (call_log_on_idle)
	        {
	            set_pre_tab_pane_display();
	            EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key, NULL);
	        }
	        else
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
	        {
	            /* from menu or from shorcut */
#ifndef __DISABLE_SHORTCUTS_MENU__
	            if (IsScreenPresent(MAIN_MENU_SCREENID) || IsScreenPresent(SCR_ID_SHCT_IDLE_SHORTCUT) ||
	                (GetExitScrnID() == SCR_ID_SHCT_IDLE_SHORTCUT))
#else /* __DISABLE_SHORTCUTS_MENU__ */
	            if (IsScreenPresent(MAIN_MENU_SCREENID))
#endif /* __DISABLE_SHORTCUTS_MENU__ */
	                EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key, NULL);
	            else
	            {
	                EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key, NULL);
	            }
	        }

	        guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_DIALED_CALLHIS_LIST);
	        RegisterHighlightHandler(GetSlaveCurrDialedCallHISIndex);

	        for (index = 0; index < SlaveDialedCalls && index < TOT_SIZE_OF_DIALED_LIST; index++)
	        {
	            name_len = MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
	            MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
	            if (name_len)
	            {
	                phoneNames[index] = (MTPNP_UINT8 *) Callhistiry_info[index].name;
	                phoneNumbers[index] = (MTPNP_UINT8 *) Callhistiry_info[index].number;
	            }
	            else
	            {
	                if (Callhistiry_info[index].number[0] != 0)
	                {
	                    phoneNames[index] = (MTPNP_UINT8 *) Callhistiry_info[index].number;
	                }
	                else
	                {
	                    phoneNames[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
	                }
	                phoneNumbers[index] = NULL;
	            }
	        }

	        for (count = 0; count < SlaveDialedCalls; count++)
	        {
	        #ifdef __MMI_DUAL_SIM_MASTER__
	            Cat23DemoIcons[count] = IMG_MTPNP_CARD2_MENU_DIALED_CALLS;
	        #else /* __MMI_DUAL_SIM_MASTER__ */
	            Cat23DemoIcons[count] = IMG_MENU8102_DIALED_CALLS;
	        #endif /* __MMI_DUAL_SIM_MASTER__ */
	        }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
	        set_force_all_hints_in_menuitem();
#endif
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
	        if (GetExitScrnID() == SCR_MTPNP_DIALED_CALLHIS_LIST)
	        {
	            ShowCategory53Screen(STR_DIALED_CAPTION,
	                                 IMG_DIALED_CAPTION,
	                                 STR_GLOBAL_OPTIONS,
	                                 IMG_GLOBAL_OPTIONS,
	                                 STR_GLOBAL_BACK,
	                                 IMG_GLOBAL_BACK,
	                                 SlaveDialedCalls,
	                                 phoneNames,
	                                 (U16 *) Cat23DemoIcons,
	                                 phoneNumbers, 0, Callhistiry_info->currDialedCallIndex, guiBuffer);
	        }
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
	        if (GetExitScrnID() == SCR_MTPNP_DIALED_CALLHIS_LIST)
	        {
	            ShowCategory53Screen(STR_DIALED_CAPTION,
	                                 IMG_DIALED_CAPTION,
	                                 STR_GLOBAL_OK,
	                                 IMG_GLOBAL_OK,
	                                 STR_GLOBAL_BACK,
	                                 IMG_GLOBAL_BACK,
	                                 SlaveDialedCalls,
	                                 phoneNames,
	                                 (U16 *) Cat23DemoIcons,
	                                 phoneNumbers, 0, Callhistiry_info->currDialedCallIndex, guiBuffer);
	        }
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */

	        MTPNP_PFAL_CC_HandleSendKeys(MTPNP_PFAL_Call_Dialed, KEY_EVENT_DOWN);
#ifdef __MMI_IP_KEY__
	/* under construction !*/
#endif

	        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
	        SetKeyHandler(EntrySlaveCHISTDialedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	        SetLeftSoftkeyFunction(EntrySlaveCHISTDialedListOptions, KEY_EVENT_UP);
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
	        SetKeyHandler(EntrySlaveCHISTViewDialedCallInfo, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	        SetLeftSoftkeyFunction(EntrySlaveCHISTViewDialedCallInfo, KEY_EVENT_UP);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */

	        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
	        if (call_log_on_idle)
	        {
	            set_post_tab_pane_display();
	        }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */

	    }
	    else
	    {
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
	        if (call_log_on_idle)
	        {
	            set_pre_tab_pane_display();
	            EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_dialed_num_by_key, NULL);
	            guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_DIALED_CALLHIS_LIST);

	            if (GetExitScrnID() == SCR_MTPNP_DIALED_CALLHIS_LIST)
	            {
	                ShowCategory53Screen(STR_DIALED_CAPTION,
	                                     IMG_DIALED_CAPTION,
	                                     0,
	                                     0,
	                                     STR_GLOBAL_BACK,
	                                     IMG_GLOBAL_BACK, SlaveDialedCalls, NULL, NULL, NULL, 0, 0, guiBuffer);
	            }
	            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	            set_post_tab_pane_display();
	        }
	        else
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
	        {
	            DisplayPopup((PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
	                         IMG_GLOBAL_EMPTY, 1, CS_NOTIFYDURATION, EMPTY_LIST_TONE);
	        }
	    }
	}
	else
	{
		if( g_get_call_history_by_send_type == READ_D )
			EV_callHistory_slave_rsp_read_dialed_num();
	}
    return;
}

void EntrySlaveCHISTDialedListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 index = Callhistiry_info->currDialedCallIndex;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_OPTION, ExitSlaveCHISTDialedListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;

    /* reset all menu */
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_DELETE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);

    if (Callhistiry_info[index].number[0] == 0 && Callhistiry_info[index].number[1] == 0)
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);
    }
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);        
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);    
        }
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */       
    }
    
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_DIALED_CALLHIS_OPTION);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_DIALED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_MTPNP_DIALED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         IMG_DIALED_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, 0, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


#if 1
void EV_EntrySlaveCHISTDialedListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = dial_Callhistiry_info  ;	
    U8 index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_OPTION, EV_ExitSlaveCHISTDialedListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;

    /* reset all menu */
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_DELETE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);

    if (Callhistiry_info[index].number[0] == 0 && Callhistiry_info[index].number[1] == 0)
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);
    }
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDSMS);        
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_DIALED_CALL_MENU_SENDMMS);    
        }
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */       
    }
    
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_DIALED_CALLHIS_OPTION);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_DIALED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(MENU_MTPNP_DIALED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_MTPNP_DIALED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         IMG_DIALED_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, 0, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif


void MTPNP_PFAL_chist_slave_req_read_missed_num_by_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_chist_get_sentreq_flag()== TRUE)
    {
        return;
    }

    if (MTPNP_AD_Calllog_GetStatus() == MTPNP_TRUE)
    {
        AlmDisableExpiryHandler();
        /* clear all key event handler */
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        MTPNP_AD_slave_req_read_missed_num();
        mmi_chist_set_sentreq_flag(TRUE);
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8054_CAPTION,
            IMG_SCR8054_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


void MTPNP_PFAL_chist_slave_rsp_read_missed_num(void)
{
#if 0
// Huyanwei Add It 
    if (g_get_call_history_by_send == 1 )
    	{
    		EV_callHistory_slave_rsp_read_missed_num();
		return  ;
    	}
#endif
    mmi_chist_set_sentreq_flag(MTPNP_FALSE);
    EntrySlaveCHISTViewMissedCallList();
    AlmEnableExpiryHandler();
    return;         
}


void HighlightSlaveCHISTMissedCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CH_MIXED_CALL_LOG__
    chis_p->isMixedStyle = FALSE;
#endif 
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    if (!call_log_on_idle)
#endif 
    {
        SetKeyHandler(MTPNP_PFAL_chist_slave_req_read_missed_num_by_key, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    else
    {
        disable_tab_pane_keys();
    }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_chist_slave_req_read_missed_num_by_key, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntrySlaveCHISTViewMissedCallList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *phoneNumbers[TOT_SIZE_OF_DIALED_LIST];
    U8 *phoneNames[TOT_SIZE_OF_DIALED_LIST];
    U8 *guiBuffer;
    U16 Cat23DemoIcons[TOT_SIZE_OF_DIALED_LIST];
    U8 count;
    U8 SlaveMissedCalls;
    U16 index;
    U8 name_len;

if(g_get_call_history_by_send !=1)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SlaveMissedCalls = MTPNP_AD_Get_CallHistory_Missedcall();
  
    if (MTPNP_AD_Get_MissedCallCount_BeforeView() != 0)
    {
        MTPNP_AD_Set_MissedCallCount(0);
        if (IsScreenPresent(SCR_MTPNP_MISSED_CALLHIS_LIST))
            DeleteUptoScrID(SCR_MTPNP_CALLHIS_MAIN_MENU);
    }

    g_slave_chist_have_missed_call = 0;
    MTPNP_PFAL_chist_set_have_missed_call();
    HideStatusIcon(STATUS_ICON_CARD2MISSED_CALL);
    UpdateStatusIcons();

    if (isInCall() && !IsWapCallPresent())
    {
        return;
    }

    if (SlaveMissedCalls)
    {
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_missed_num_by_key, NULL);
        }
        else
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
        {
            /* from menu or from shorcut */
#ifndef __DISABLE_SHORTCUTS_MENU__
            if (IsScreenPresent(MAIN_MENU_SCREENID) || IsScreenPresent(SCR_ID_SHCT_IDLE_SHORTCUT) ||
                (GetExitScrnID() == SCR_ID_SHCT_IDLE_SHORTCUT))
#else /* __DISABLE_SHORTCUTS_MENU__ */
            if (IsScreenPresent(MAIN_MENU_SCREENID))
#endif /* __DISABLE_SHORTCUTS_MENU__ */
                EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_missed_num_by_key, NULL);
            else
            {
                EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_missed_num_by_key, NULL);
            }
        }

        guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MISSED_CALLHIS_LIST);
        RegisterHighlightHandler(GetSlaveCurrMissedCallHISIndex);

        for (index = 0; index < SlaveMissedCalls && index < TOT_SIZE_OF_MISSED_LIST; index++)
        {
            name_len = MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
            MTPNP_AD_Get_MissedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);

            if (name_len)
            {
                phoneNames[index] = (MTPNP_UINT8 *) Callhistiry_info[index].name;
                phoneNumbers[index] = (MTPNP_UINT8 *) Callhistiry_info[index].number;
            }
            else
            {
                if (Callhistiry_info[index].number[0] != 0)
                {
                    phoneNames[index] = (MTPNP_UINT8 *) Callhistiry_info[index].number;
                }
                else
                {
                    phoneNames[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
                }
                phoneNumbers[index] = NULL;
            }
        }

        for (count = 0; count < SlaveMissedCalls; count++)
        {
#ifdef __MMI_VOIP__
            if (chis_p->dialedCalls[count].address_type == PHB_LN_VOIP)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_MISSED_CALLS;
            }
            else
#endif /* __MMI_VOIP__ */
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                Cat23DemoIcons[count] = IMG_MTPNP_CARD2_MENU_MISSED_CALLS;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                Cat23DemoIcons[count] = IMG_MENU8103_MISSED_CALLS;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
        }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_all_hints_in_menuitem();
#endif
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (GetExitScrnID() == SCR_MTPNP_MISSED_CALLHIS_LIST)
        {
            ShowCategory53Screen(STR_MISSED_CAPTION,
                                 IMG_MISSED_CAPTION,
                                 STR_GLOBAL_OPTIONS,
                                 IMG_GLOBAL_OPTIONS,
                                 STR_GLOBAL_BACK,
                                 IMG_GLOBAL_BACK,
                                 SlaveMissedCalls phoneNames, (U16 *) Cat23DemoIcons, phoneNumbers, 0, Callhistiry_info->currMissedCallIndex, guiBuffer);
        }
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        if (GetExitScrnID() == SCR_MTPNP_MISSED_CALLHIS_LIST)
        {
            ShowCategory53Screen(STR_MISSED_CAPTION,
                                 IMG_MISSED_CAPTION,
                                 STR_GLOBAL_OK,
                                 IMG_GLOBAL_OK,
                                 STR_GLOBAL_BACK,
                                 IMG_GLOBAL_BACK,
                                 SlaveMissedCalls, phoneNames, (U16 *) Cat23DemoIcons, phoneNumbers, 0, Callhistiry_info->currMissedCallIndex, guiBuffer);
        }
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        MTPNP_PFAL_CC_HandleSendKeys(MTPNP_PFAL_Call_Missed, KEY_EVENT_DOWN);

#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        SetKeyHandler(EntrySlaveCHISTMissedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntrySlaveCHISTMissedListOptions, KEY_EVENT_UP);
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        SetKeyHandler(EntrySlaveCHISTViewMissedCallInfo, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntrySlaveCHISTViewMissedCallInfo, KEY_EVENT_UP);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_post_tab_pane_display();
        }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */

    }
    else
    {
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_LIST, NULL, EntrySlaveCHISTViewMissedCallList, NULL);
            guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MISSED_CALLHIS_LIST);

            if (GetExitScrnID() == SCR_MTPNP_MISSED_CALLHIS_LIST)
            {
                ShowCategory53Screen(STR_MISSED_CAPTION,
                                     IMG_MISSED_CAPTION,
                                     0,
                                     0,
                                     STR_GLOBAL_BACK,
                                     IMG_GLOBAL_BACK, SlaveMissedCalls, NULL, NULL, NULL, 0, 0, guiBuffer);
            }
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            set_post_tab_pane_display();
        }
        else
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
        {
            DisplayPopup((PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
                         IMG_GLOBAL_EMPTY, 1, CS_NOTIFYDURATION, EMPTY_LIST_TONE);
        }
    }
    DeleteScreenIfPresent(SCR_MTPNP_CALL_HISTORY_NOTIFY);
	}
      else
      {
		if( g_get_call_history_by_send_type == READ_M )
			EV_callHistory_slave_rsp_read_missed_num();
	}	
    return;
}

void EntrySlaveCHISTMissedListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 index = Callhistiry_info->currMissedCallIndex; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_OPTION, ExitSlaveCHISTMissedListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;
    /* reset all menu */
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_DELETE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);

    if (Callhistiry_info[index].number[0] == 0 && Callhistiry_info[index].number[1] == 0)
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);
    }
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);        
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);    
        }
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */       
    }

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MISSED_CALLHIS_OPTION);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_MISSED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_MTPNP_MISSED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         IMG_MISSED_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, 0, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void EV_EntrySlaveCHISTMissedListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
	
    U8     index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;
    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = miss_Callhistiry_info  ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_OPTION, EV_ExitSlaveCHISTMissedListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;
    /* reset all menu */
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_DELETE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);

    if (Callhistiry_info[index].number[0] == 0 && Callhistiry_info[index].number[1] == 0)
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);
    }
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDSMS);        
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_MISSED_CALL_MENU_SENDMMS);    
        }
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */       
    }

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MISSED_CALLHIS_OPTION);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_MISSED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(MENU_MTPNP_MISSED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_MTPNP_MISSED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         IMG_MISSED_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, 0, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_chist_get_sentreq_flag()== TRUE)
    {
        return;
    }

    if (MTPNP_AD_Calllog_GetStatus() == MTPNP_TRUE)
    {
        AlmDisableExpiryHandler();
        /* clear all key event handler */
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        MTPNP_AD_slave_req_read_recvd_num();
        mmi_chist_set_sentreq_flag(TRUE);
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8054_CAPTION,
            IMG_SCR8054_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


void MTPNP_PFAL_chist_slave_rsp_read_recvd_num(void)
{
#if 0
// Huyanwei Add It 
	if (g_get_call_history_by_send == 1 )
	{
		EV_callHistory_slave_rsp_read_received_num();
		return  ;
	}
#endif

    mmi_chist_set_sentreq_flag(MTPNP_FALSE);
    EntrySlaveCHISTViewRecvdCallList();
    AlmEnableExpiryHandler();
    return;
	
}


void HighlightSlaveCHISTRecvdCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CH_MIXED_CALL_LOG__
    chis_p->isMixedStyle = FALSE;
#endif 
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    if (!call_log_on_idle)
#endif 
    {
        SetKeyHandler(MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    else
    {
        disable_tab_pane_keys();
    }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntrySlaveCHISTViewRecvdCallList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *phoneNumbers[TOT_SIZE_OF_DIALED_LIST];
    U8 *phoneNames[TOT_SIZE_OF_DIALED_LIST];
    U8 *guiBuffer;
    U16 Cat23DemoIcons[TOT_SIZE_OF_DIALED_LIST];
    U8 count;
    U8 SlaveRecvdCalls;
    U16 index;
    U8 name_len;
if( g_get_call_history_by_send !=1)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SlaveRecvdCalls = MTPNP_AD_Get_CallHistory_Recvdcall();

    if (isInCall() && !IsWapCallPresent())
    {
        return;
    }

    if (SlaveRecvdCalls)
    {
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key, NULL);
        }
        else
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
        {
            /* from menu or from shorcut */
#ifndef __DISABLE_SHORTCUTS_MENU__
            if (IsScreenPresent(MAIN_MENU_SCREENID) || IsScreenPresent(SCR_ID_SHCT_IDLE_SHORTCUT) ||
                (GetExitScrnID() == SCR_ID_SHCT_IDLE_SHORTCUT))
#else /* __DISABLE_SHORTCUTS_MENU__ */
            if (IsScreenPresent(MAIN_MENU_SCREENID))
#endif /* __DISABLE_SHORTCUTS_MENU__ */
                EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key, NULL);
            else
            {
                EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_LIST, NULL, MTPNP_PFAL_chist_slave_req_read_recvd_num_by_key, NULL);
            }
        }

        guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_RECVD_CALLHIS_LIST);
        RegisterHighlightHandler(GetSlaveCurrRecvdCallHISIndex);

        for (index = 0; index < SlaveRecvdCalls && index < TOT_SIZE_OF_RECVD_LIST; index++)
        {
            name_len = MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
            MTPNP_AD_Get_RecvdCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);

            if (name_len)
            {
                phoneNames[index] = (MTPNP_UINT8 *) Callhistiry_info[index].name;
                phoneNumbers[index] = (MTPNP_UINT8 *) Callhistiry_info[index].number;
            }
            else
            {
                if (Callhistiry_info[index].number[0] != 0)
                {
                    phoneNames[index] = (MTPNP_UINT8 *) Callhistiry_info[index].number;
                }
                else
                {
                    phoneNames[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
                }
                phoneNumbers[index] = NULL;
            }
        }

        for (count = 0; count < SlaveRecvdCalls; count++)
        {
#ifdef __MMI_VOIP__
            if (chis_p->dialedCalls[count].address_type == PHB_LN_VOIP)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_RECEIVED_CALLS;
            }
            else
#endif /* __MMI_VOIP__ */
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                Cat23DemoIcons[count] = IMG_MTPNP_CARD2_MENU_RECEIVED_CALLS;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                Cat23DemoIcons[count] = IMG_MENU8101_RECEIVED_CALLS;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
        }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_all_hints_in_menuitem();
#endif
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (GetExitScrnID() == SCR_MTPNP_RECVD_CALLHIS_LIST)
        {
            ShowCategory53Screen(STR_RECEIVED_CAPTION,
                                 IMG_RECEIVED_CAPTION,
                                 STR_GLOBAL_OPTIONS,
                                 IMG_GLOBAL_OPTIONS,
                                 STR_GLOBAL_BACK,
                                 IMG_GLOBAL_BACK,
                                 SlaveRecvdCalls, phoneNames, (U16 *) Cat23DemoIcons, phoneNumbers, 0, Callhistiry_info->currRecvdCallIndex, guiBuffer);
        }
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        if (GetExitScrnID() == SCR_MTPNP_RECVD_CALLHIS_LIST)
        {
            ShowCategory53Screen(STR_RECEIVED_CAPTION,
                                 IMG_RECEIVED_CAPTION,
                                 STR_GLOBAL_OK,
                                 IMG_GLOBAL_OK,
                                 STR_GLOBAL_BACK,
                                 IMG_GLOBAL_BACK,
                                 SlaveRecvdCalls, phoneNames, (U16 *) Cat23DemoIcons, phoneNumbers, 0, Callhistiry_info->currRecvdCallIndex, guiBuffer);
        }
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        MTPNP_PFAL_CC_HandleSendKeys(MTPNP_PFAL_Call_Recved, KEY_EVENT_DOWN);

#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        SetKeyHandler(EntrySlaveCHISTRecvdListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntrySlaveCHISTRecvdListOptions, KEY_EVENT_UP);
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        SetKeyHandler(EntrySlaveCHISTViewRecvdCallInfo, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntrySlaveCHISTViewRecvdCallInfo, KEY_EVENT_UP);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_post_tab_pane_display();
        }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */

    }
    else
    {
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_LIST, NULL, EntrySlaveCHISTViewRecvdCallList, NULL);
            guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_RECVD_CALLHIS_LIST);

            if (GetExitScrnID() == SCR_MTPNP_RECVD_CALLHIS_LIST)
            {
                ShowCategory53Screen(STR_RECEIVED_CAPTION,
                                     IMG_RECEIVED_CAPTION,
                                     0,
                                     0,
                                     STR_GLOBAL_BACK,
                                     IMG_GLOBAL_BACK, SlaveRecvdCalls, NULL, NULL, NULL, 0, 0, guiBuffer);
            }
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            set_post_tab_pane_display();
        }
        else
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
        {
            DisplayPopup((PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
                         IMG_GLOBAL_EMPTY, 1, CS_NOTIFYDURATION, EMPTY_LIST_TONE);
        }
    }
   }
   else
  {
		if( g_get_call_history_by_send_type == READ_R )
			EV_callHistory_slave_rsp_read_received_num();
}
    return;
}

void EntrySlaveCHISTRecvdListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 index = Callhistiry_info->currRecvdCallIndex; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_OPTION, ExitSlaveCHISTRecvdListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;
    /* reset all menu */
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_DELETE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);

    if (Callhistiry_info[index].number[0] == 0 && Callhistiry_info[index].number[1] == 0)
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);
    }
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);        
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);    
        }
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */       
    }


    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_RECVD_CALLHIS_OPTION);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         IMG_RECEIVED_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, 0, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void EV_EntrySlaveCHISTRecvdListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = recv_Callhistiry_info  ;
	
    U8 index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_OPTION, EV_ExitSlaveCHISTRecvdListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;
    /* reset all menu */
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_DELETE);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);

    if (Callhistiry_info[index].number[0] == 0 && Callhistiry_info[index].number[1] == 0)
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);
    }
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDSMS);        
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_RECEIVED_CALL_MENU_SENDMMS);    
        }
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */       
    }


    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_RECVD_CALLHIS_OPTION);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_MTPNP_RECEIVED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         IMG_RECEIVED_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, 0, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void ExitSlaveCHISTDialedListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_MTPNP_DIALED_CALLHIS_INFO))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_MTPNP_DIALED_CALLHIS_OPTION;
        currHistory.entryFuncPtr = EntrySlaveCHISTDialedListOptions;
        mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
#endif
            AddHistory(currHistory);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
#endif
    return;
}


void EV_ExitSlaveCHISTDialedListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_MTPNP_DIALED_CALLHIS_INFO))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_MTPNP_DIALED_CALLHIS_OPTION;
        currHistory.entryFuncPtr = EV_EntrySlaveCHISTDialedListOptions;
        mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
#endif
            AddHistory(currHistory);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
#endif
    return;
}

void ExitSlaveCHISTMissedListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_MTPNP_MISSED_CALLHIS_INFO))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_MTPNP_MISSED_CALLHIS_OPTION;
        currHistory.entryFuncPtr = EntrySlaveCHISTMissedListOptions;
        mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
#endif
            AddHistory(currHistory);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
#endif
    return;
}

void EV_ExitSlaveCHISTMissedListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_MTPNP_MISSED_CALLHIS_INFO))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_MTPNP_MISSED_CALLHIS_OPTION;
        currHistory.entryFuncPtr = EV_EntrySlaveCHISTMissedListOptions;
        mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
#endif
            AddHistory(currHistory);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
#endif
    return;
}

void ExitSlaveCHISTRecvdListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_MTPNP_RECVD_CALLHIS_INFO))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_MTPNP_RECVD_CALLHIS_OPTION;
        currHistory.entryFuncPtr = EntrySlaveCHISTRecvdListOptions;
        mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
#endif
            AddHistory(currHistory);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
#endif
    return;
}


void EV_ExitSlaveCHISTRecvdListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_MTPNP_RECVD_CALLHIS_INFO))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR_MTPNP_RECVD_CALLHIS_OPTION;
        currHistory.entryFuncPtr = EV_EntrySlaveCHISTRecvdListOptions;
        mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
#endif
            AddHistory(currHistory);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
#endif
    return;
}


void EntrySlaveCHISTViewDialedCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start = 0;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 
    U16 no_of_times;
    //MTPNP_UINT32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_INFO, ExitSlaveCHISTViewDialedCall, NULL, NULL);
    addToHistory = 1;
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_DIALED_CALLHIS_INFO);
    index = Callhistiry_info->currDialedCallIndex;
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n EntrySlaveCHISTViewDialedCallInfo  index  = %d  \r\n",index) ;
#endif
    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8 *) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
    MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);


#if 1
   {
    char AsciiBuffer[256]  ;
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].name);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("DiallName = %s\r\n",AsciiBuffer);
#endif
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].number);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("DiallNumber = %s\r\n",AsciiBuffer);
#endif
    }
#endif


    no_of_times = MTPNP_AD_Get_DialedCallHistory_no_of_times(index);
    Callhistiry_info[index].duration = MTPNP_AD_Get_DialedCallHistory_duration(index);

    if (Callhistiry_info[index].startTime.nDay != 0)
    {
        date_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_DATE_ENTRY;
        time_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_TIME_ENTRY;
    }
    if (Callhistiry_info[index].name[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].name);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8 *) subMenuDataPtrs[start + 1], "%d ", no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start + 1]);
    if (no_of_times == 1)
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* __PHB_LN_SINGLE_COUNT__ */
    // mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) duration);
    //Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;

    if (mmi_dt_mytime_2_utc_sec(&Callhistiry_info[index].duration, MMI_FALSE) != 0)
    {
        U8 value[20];
        sprintf(
            (S8*) value,
            "%02d:%02d:%02d",
            Callhistiry_info[index].duration.nHour,
            Callhistiry_info[index].duration.nMin,
            Callhistiry_info[index].duration.nSec);
        mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) value);
        Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    }
    noItems = start;
    ShowCategory84Screen(STR_SCR8069_CAPTION1,
                         IMG_SCR8069_CAPTION,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, noItems, subMenuDataPtrs, Cat23DemoIcons, LIST_MENU, 0, guiBuffer);

    MTPNP_PFAL_CC_HandleSendKeys(MTPNP_PFAL_Call_Dialed, KEY_EVENT_DOWN);
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntrySlaveCHISTDialedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySlaveCHISTDialedListOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EV_EntrySlaveCHISTViewDialedCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start = 0;
    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = dial_Callhistiry_info  ;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 
    U16 no_of_times;
    //MTPNP_UINT32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_DIALED_CALLHIS_INFO, EV_ExitSlaveCHISTViewDialedCall, NULL, NULL);
    addToHistory = 1;
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_DIALED_CALLHIS_INFO);
    index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n EntrySlaveCHISTViewDialedCallInfo  index  = %d  \r\n",index) ;
#endif
    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8 *) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
    
#if 1
   {
    char AsciiBuffer[256]  ;
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].name);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("DiallName = %s\r\n",AsciiBuffer);
#endif
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].number);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("DiallNumber = %s\r\n",AsciiBuffer);
#endif
    }
#endif

    no_of_times = Callhistiry_info[index].no_of_times;


    if (Callhistiry_info[index].startTime.nDay != 0)
    {
        date_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_DATE_ENTRY;
        time_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_TIME_ENTRY;
    }
    if (Callhistiry_info[index].name[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].name);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8 *) subMenuDataPtrs[start + 1], "%d ", no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start + 1]);
    if (no_of_times == 1)
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* __PHB_LN_SINGLE_COUNT__ */
    // mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) duration);
    //Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;

    if (mmi_dt_mytime_2_utc_sec(&Callhistiry_info[index].duration, MMI_FALSE) != 0)
    {
        U8 value[20];
        sprintf(
            (S8*) value,
            "%02d:%02d:%02d",
            Callhistiry_info[index].duration.nHour,
            Callhistiry_info[index].duration.nMin,
            Callhistiry_info[index].duration.nSec);
        mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) value);
        Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    }
    noItems = start;
    ShowCategory84Screen(STR_SCR8069_CAPTION1,
                         IMG_SCR8069_CAPTION,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, noItems, subMenuDataPtrs, Cat23DemoIcons, LIST_MENU, 0, guiBuffer);

    MTPNP_PFAL_CC_HandleSendKeys(EV_MTPNP_PFAL_Call_Dialed, KEY_EVENT_DOWN);
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EV_EntrySlaveCHISTDialedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EV_EntrySlaveCHISTDialedListOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void ExitSlaveCHISTViewDialedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_MTPNP_DIALED_CALLHIS_INFO;
    currHistory.entryFuncPtr = EntrySlaveCHISTViewDialedCallInfo;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}

void EV_ExitSlaveCHISTViewDialedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_MTPNP_DIALED_CALLHIS_INFO;
    currHistory.entryFuncPtr = EV_EntrySlaveCHISTViewDialedCallInfo;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}


void EntrySlaveCHISTViewMissedCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start = 0;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 
    U16 no_of_times;
    MTPNP_UINT32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_INFO, ExitSlaveCHISTViewMissedCall, NULL, NULL);
    addToHistory = 1;
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MISSED_CALLHIS_INFO);
    index = Callhistiry_info->currMissedCallIndex;
#if defined(NOKE_DEBUG)
noke_dbg_printf("\r\n EntrySlaveCHISTViewMissedCallInfo  index  = %d  \r\n",index) ;
#endif
    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8 *) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
    MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_MissedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);

#if 1
   {
    char AsciiBuffer[256]  ;
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].name);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("MisslName = %s\r\n",AsciiBuffer);
#endif
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].number);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("MisslNumber = %s\r\n",AsciiBuffer);
#endif
    }
#endif



    MTPNP_AD_Get_MissedCallHistory_StratTime(index, &Callhistiry_info[index].startTime);
    no_of_times = MTPNP_AD_Get_MissedCallHistory_no_of_times(index);
//    duration = MTPNP_AD_Get_MissedCallHistory_duration(index);
    if (Callhistiry_info[index].startTime.nDay != 0)
    {
        date_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_DATE_ENTRY;
        time_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_TIME_ENTRY;
    }
    if (Callhistiry_info[index].name[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].name);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8 *) subMenuDataPtrs[start + 1], "%d ", no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start + 1]);
    if (no_of_times == 1)
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* __PHB_LN_SINGLE_COUNT__ */
    // mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) duration);
    //Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;

    noItems = start;
    ShowCategory84Screen(STR_SCR8069_CAPTION1,
                         IMG_SCR8069_CAPTION,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, noItems, subMenuDataPtrs, Cat23DemoIcons, LIST_MENU, 0, guiBuffer);

    MTPNP_PFAL_CC_HandleSendKeys(MTPNP_PFAL_Call_Missed, KEY_EVENT_DOWN);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntrySlaveCHISTMissedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySlaveCHISTMissedListOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}



void EV_EntrySlaveCHISTViewMissedCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start = 0;
    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = miss_Callhistiry_info  ;


#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 
    U16 no_of_times;
    MTPNP_UINT32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_MISSED_CALLHIS_INFO, ExitSlaveCHISTViewMissedCall, NULL, NULL);
    addToHistory = 1;
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MISSED_CALLHIS_INFO);
    index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n EntrySlaveCHISTViewMissedCallInfo  index  = %d  \r\n",index) ;
#endif
    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8 *) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }

#if 1
   {
    char AsciiBuffer[256]  ;
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].name);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("MisslName = %s\r\n",AsciiBuffer);
#endif
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].number);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("MisslNumber = %s\r\n",AsciiBuffer);
#endif
    }
#endif

   no_of_times = Callhistiry_info[index].no_of_times;

    if (Callhistiry_info[index].startTime.nDay != 0)
    {
        date_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_DATE_ENTRY;
        time_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_TIME_ENTRY;
    }
    if (Callhistiry_info[index].name[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].name);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8 *) subMenuDataPtrs[start + 1], "%d ", no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start + 1]);
    if (no_of_times == 1)
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* __PHB_LN_SINGLE_COUNT__ */
    // mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) duration);
    //Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;

    noItems = start;
    ShowCategory84Screen(STR_SCR8069_CAPTION1,
                         IMG_SCR8069_CAPTION,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, noItems, subMenuDataPtrs, Cat23DemoIcons, LIST_MENU, 0, guiBuffer);

    MTPNP_PFAL_CC_HandleSendKeys(EV_MTPNP_PFAL_Call_Missed, KEY_EVENT_DOWN);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EV_EntrySlaveCHISTMissedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EV_EntrySlaveCHISTMissedListOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}




void ExitSlaveCHISTViewMissedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_MTPNP_MISSED_CALLHIS_INFO;
    currHistory.entryFuncPtr = EntrySlaveCHISTViewMissedCallInfo;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}

void EntrySlaveCHISTViewRecvdCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start = 0;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 
    U16 no_of_times;
    MTPNP_UINT32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_INFO, ExitSlaveCHISTViewRecvdCall, NULL, NULL);
    addToHistory = 1;
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_RECVD_CALLHIS_INFO);
    index = Callhistiry_info->currRecvdCallIndex;
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n EntrySlaveCHISTViewRecvdCallInfo  index  = %d  \r\n",index) ;
#endif
    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8 *) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
    MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_RecvdCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);

#if 1
   {
    char AsciiBuffer[256]  ;
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].name);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("RecvlName = %s\r\n",AsciiBuffer);
#endif
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].number);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("RecvNumber = %s\r\n",AsciiBuffer);
#endif
    }
#endif


    MTPNP_AD_Get_RecvdCallHistory_StratTime(index, &Callhistiry_info[index].startTime);
    no_of_times = MTPNP_AD_Get_RecvdCallHistory_no_of_times(index);
    Callhistiry_info[index].duration = MTPNP_AD_Get_RecvdCallHistory_duration(index);
//    duration = MTPNP_AD_Get_RecvdCallHistory_duration(index);
    if (Callhistiry_info[index].startTime.nDay != 0)
    {
        date_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_DATE_ENTRY;
        time_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_TIME_ENTRY;
    }
    if (Callhistiry_info[index].name[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].name);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8 *) subMenuDataPtrs[start + 1], "%d ", no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start + 1]);
    if (no_of_times == 1)
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* __PHB_LN_SINGLE_COUNT__ */
    // mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) duration);
    //Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    if (mmi_dt_mytime_2_utc_sec(&Callhistiry_info[index].duration, MMI_FALSE) != 0)
    {
        U8 value[20];
        sprintf(
            (S8*) value,
            "%02d:%02d:%02d",
            Callhistiry_info[index].duration.nHour,
            Callhistiry_info[index].duration.nMin,
            Callhistiry_info[index].duration.nSec);
        mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) value);
        Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    }
    noItems = start;
    ShowCategory84Screen(STR_SCR8069_CAPTION1,
                         IMG_SCR8069_CAPTION,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, noItems, subMenuDataPtrs, Cat23DemoIcons, LIST_MENU, 0, guiBuffer);

    MTPNP_PFAL_CC_HandleSendKeys(MTPNP_PFAL_Call_Recved, KEY_EVENT_DOWN);
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntrySlaveCHISTRecvdListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySlaveCHISTRecvdListOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void EV_EntrySlaveCHISTViewRecvdCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start = 0;
    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = recv_Callhistiry_info  ;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 
    U16 no_of_times;
    MTPNP_UINT32 duration;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MTPNP_RECVD_CALLHIS_INFO, EV_ExitSlaveCHISTViewRecvdCall, NULL, NULL);
    addToHistory = 1;
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_RECVD_CALLHIS_INFO);
    index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n EntrySlaveCHISTViewRecvdCallInfo  index  = %d  \r\n",index) ;
#endif
    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8 *) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
#if 1
   {
    char AsciiBuffer[256]  ;
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].name);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("RecvlName = %s\r\n",AsciiBuffer);
#endif
    memset(AsciiBuffer,0,256);
    mmi_ucs2_to_asc(AsciiBuffer,Callhistiry_info[index].number);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("RecvNumber = %s\r\n",AsciiBuffer);
#endif
    }
#endif


   no_of_times = Callhistiry_info[index].no_of_times ;
    if (Callhistiry_info[index].startTime.nDay != 0)
    {
        date_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_DATE_ENTRY;
        time_string((UI_time *) & Callhistiry_info[index].startTime, (UI_string_type) subMenuDataPtrs[start],
                    DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_TIME_ENTRY;
    }
    if (Callhistiry_info[index].name[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].name);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (Callhistiry_info[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) Callhistiry_info[index].number,
                        MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
            mmi_ucs2ncpy((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8 *) subMenuDataPtrs[start + 1], "%d ", no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start + 1]);
    if (no_of_times == 1)
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8 *) subMenuDataPtrs[start++], (S8 *) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* __PHB_LN_SINGLE_COUNT__ */
    // mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) duration);
    //Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    if (mmi_dt_mytime_2_utc_sec(&Callhistiry_info[index].duration, MMI_FALSE) != 0)
    {
        U8 value[20];
        sprintf(
            (S8*) value,
            "%02d:%02d:%02d",
            Callhistiry_info[index].duration.nHour,
            Callhistiry_info[index].duration.nMin,
            Callhistiry_info[index].duration.nSec);
        mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) value);
        Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    }
    noItems = start;
    ShowCategory84Screen(STR_SCR8069_CAPTION1,
                         IMG_SCR8069_CAPTION,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, noItems, subMenuDataPtrs, Cat23DemoIcons, LIST_MENU, 0, guiBuffer);

    MTPNP_PFAL_CC_HandleSendKeys(EV_MTPNP_PFAL_Call_Recved, KEY_EVENT_DOWN);
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EV_EntrySlaveCHISTRecvdListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EV_EntrySlaveCHISTRecvdListOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void ExitSlaveCHISTViewRecvdCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_MTPNP_RECVD_CALLHIS_INFO;
    currHistory.entryFuncPtr = EntrySlaveCHISTViewRecvdCallInfo;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}

void EV_ExitSlaveCHISTViewRecvdCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_MTPNP_RECVD_CALLHIS_INFO;
    currHistory.entryFuncPtr = EV_EntrySlaveCHISTViewRecvdCallInfo;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}

void MTPNP_PFAL_CHIST_Delete_Dial_From_Call_Log_Scrn(MTPNP_UINT8 type)
{
    switch (type)
    {
        case MTPNP_AD_LND:
            DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_OPTION);
            DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_INFO);
            DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_LIST);
            break;

        case MTPNP_AD_LNM:
            DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_OPTION);
            DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_INFO);
            DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_LIST);
            break;

        case MTPNP_AD_LNR:
            DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_OPTION);
            DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_INFO);
            DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_LIST);
            break;

        default:
            break;
    }
}

void InitSlaveCallHistoryContext(void)
{
    S16 pError;

    memset((U8 *) (&g_Slave_Calltime), 0, sizeof(ST_MTPNP_CALL_TIME_S));

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 4, (void *) &g_Slave_Calltime.last_call_time, sizeof(MYTIME), &pError);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 5, (void *) &g_Slave_Calltime.total_out_time, sizeof(MYTIME), &pError);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 6, (void *) &g_Slave_Calltime.total_in_time, sizeof(MYTIME), &pError);
}

BOOL CallHistorySlaveIsNeedToResetTimes(void)
{
    U8 count;
    U8 *buf;

    buf = (U8 *) & g_Slave_Calltime.last_call_time;
    for (count = 0; count < sizeof(ST_MTPNP_AD_TIME); count++)
    {
        if (buf[count] != 0)
            return TRUE;
    }
    buf = (U8 *) & g_Slave_Calltime.total_out_time;
    for (count = 0; count < sizeof(ST_MTPNP_AD_TIME); count++)
    {
        if (buf[count] != 0)
            return TRUE;
    }
    buf = (U8 *) & g_Slave_Calltime.total_in_time;
    for (count = 0; count < sizeof(ST_MTPNP_AD_TIME); count++)
    {
        if (buf[count] != 0)
            return TRUE;
    }
    return FALSE;
}

void ResetSlaveCallTime(void)
{
    S16 error = 0;
    memset((U8 *) (&g_Slave_Calltime), 0, sizeof(ST_MTPNP_CALL_TIME_S));

    WriteRecord(NVRAM_EF_CALL_TIME_LID, 4, (void *) &g_Slave_Calltime.last_call_time, sizeof(MYTIME), &error);

    WriteRecord(NVRAM_EF_CALL_TIME_LID, 5, (void *) &g_Slave_Calltime.total_out_time, sizeof(MYTIME), &error);

    WriteRecord(NVRAM_EF_CALL_TIME_LID, 6, (void *) &g_Slave_Calltime.total_in_time, sizeof(MYTIME), &error);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);

    DeleteUptoScrID(SCR_MTPNP_CALLTIME_SETUP_MAIN);
    return;
}

void CallHistorySlaveResetAllTimeConfirm(void)
{

    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_RESET_ALL_CALL_TIME_CONFIRM), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(ResetSlaveCallTime, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTCallTime(void)
{
    SetKeyHandler(EntrySlaveCHISTCallTime, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySlaveCHISTCallTime, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntrySlaveCHISTCallTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    U8 *displayBuffer[MAX_SUB_MENUS];
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_MTPNP_CALLTIME_SETUP_MAIN, NULL, EntrySlaveCHISTCallTime, NULL);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 4, (void *) &g_Slave_Calltime.last_call_time, sizeof(MYTIME), &error);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 5, (void *) &g_Slave_Calltime.total_out_time, sizeof(MYTIME), &error);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 6, (void *) &g_Slave_Calltime.total_in_time, sizeof(MYTIME), &error);


    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_CALLTIME_SETUP_MAIN);
    nNumofItem = GetNumOfChild(MENU_MTPNP_CALL_HISTORY_CALLTIME);
    GetSequenceStringIds(MENU_MTPNP_CALL_HISTORY_CALLTIME, nStrItemList);
    SetParentHandler(MENU_MTPNP_CALL_HISTORY_CALLTIME);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_MTPNP_CALL_HISTORY_CALLTIME, displayBuffer);

    /* Display Category1 Screen */
    ShowCategory52Screen(STR_MENU_CALL_TIME_SETUP,
                         IMG_MENU_CALL_TIMES,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, displayBuffer, 0, 0, guiBuffer);

    /* Register function with right softkey */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTLastTime(void)
{
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTSentTime(void)
{
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTRecvdTime(void)
{
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTResetAllTime(void)
{
    if (CallHistorySlaveIsNeedToResetTimes() == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(CallHistorySlaveResetAllTimeConfirm, KEY_EVENT_UP);
    }

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTSlaveSMSCount(void)
{
    /* Set the left/right arrow key handler on sms count selected */
    SetKeyHandler(EntryCHISTSlaveSMSCount, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTSlaveSMSCount, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void ExitCHISTSlaveSMSCount(void)
{
    history Scr;                /* Variable to hold the history data */
    S16 nHistory = 0;
    /* getting details of the current screen (to be added to history) */
    Scr.scrnID = SCR_MTPNP_SMS_COUNTER;
    Scr.entryFuncPtr = EntryCHISTSlaveSMSCount;
    mmi_ucs2cpy((S8 *) Scr.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    /* add the screen to history */
    AddHistory(Scr);
    SetMessagesCurrScrnID(0);
    return;
}

void EntryCHISTSlaveSMSCount(void)
{
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U8 *u8SmsCount[MAX_SUB_MENUS];      /* sms counters for display hint popups */

    EntryNewScreen(SCR_MTPNP_SMS_COUNTER, ExitCHISTSlaveSMSCount, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_SMS_COUNTER);
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_CALL_HISTORY_SMSCOUNTER);
    GetSequenceStringIds(MENU_MTPNP_CALL_HISTORY_SMSCOUNTER, nStrItemList);
    SetParentHandler(MENU_MTPNP_CALL_HISTORY_SMSCOUNTER);
    SetMessagesCurrScrnID(SCR_MTPNP_SMS_COUNTER);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_MTPNP_CALL_HISTORY_SMSCOUNTER, u8SmsCount);
    ShowCategory52Screen(STRING_MTPNP_MENU_SIM2_SMS_CAPTION, IMG_SCR8056_CAPTION, STR_SMS_COUNTER_LSK,
                         IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, u8SmsCount, 0, 0, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTInfoDialedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntrySlaveCHISTViewDialedCallInfo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTDeleteDialedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryDeleteSIM2DialedLogConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void EntryDeleteSIM2DialedLogConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_ENTRY_DELETED_CONFIRM), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_CallLog_Del_DialedNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void EntryDeleteSIM2RecvedLogConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_ENTRY_DELETED_CONFIRM), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_CallLog_Del_RecvedNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void EntryDeleteSIM2MissedLogConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_ENTRY_DELETED_CONFIRM), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_CallLog_Del_MissedNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_CallLog_Del_DialedNum(void)
{
    U8 index;
    
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

    index = Callhistiry_info->currDialedCallIndex;
    MTPNP_AD_DelDialedCallHistory(index);
}

void MTPNP_PFAL_CallLog_Del_RecvedNum(void)
{
    U8 index;
    
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
    
    index = Callhistiry_info->currRecvdCallIndex;
    MTPNP_AD_DelRecvedCallHistory(index);
}

void MTPNP_PFAL_CallLog_Del_MissedNum(void)
{
    U8 index;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

    index = Callhistiry_info->currMissedCallIndex;
    MTPNP_AD_DelMissedCallHistory(index);
}

void HighlightSlaveCHISTSaveDialedNum(void)
{
    SetKeyHandler(MTPNP_PFAL_Save_Dialed, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_Save_Dialed, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void MTPNP_PFAL_Save_Dialed(void)
{
    U8 index;
    
    index = Callhistiry_info->currDialedCallIndex;
#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send != 1 )	
#endif   	
   {
    MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
   }	
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        SaveNumberFromIdleScrn((S8 *) Callhistiry_info[index].name, MMI_PHB_ENTER_FROM_CALL_LOG);
    }
    else
    {
        SaveNumberFromIdleScrn((S8 *) Callhistiry_info[index].number, MMI_PHB_ENTER_FROM_CALL_LOG);
    }
}

void MTPNP_PFAL_Save_Recved(void)
{
    U8 index;

    index = Callhistiry_info->currRecvdCallIndex;

#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send != 1 )	
#endif   	
   {	
    MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_RecvdCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    }
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        SaveNumberFromIdleScrn((S8 *) Callhistiry_info[index].name, MMI_PHB_ENTER_FROM_CALL_LOG);
    }
    else
    {
        SaveNumberFromIdleScrn((S8 *) Callhistiry_info[index].number, MMI_PHB_ENTER_FROM_CALL_LOG);
    }
}

void MTPNP_PFAL_Save_Missed(void)
{
    U8 index;
    
    index = Callhistiry_info->currMissedCallIndex;

#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send != 1 )	
#endif   	
   {	
	    MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
	    MTPNP_AD_Get_MissedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    }
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        SaveNumberFromIdleScrn((S8 *) Callhistiry_info[index].name, MMI_PHB_ENTER_FROM_CALL_LOG);
    }
    else
    {
        SaveNumberFromIdleScrn((S8 *) Callhistiry_info[index].number, MMI_PHB_ENTER_FROM_CALL_LOG);
    }
}

void HighlightSIM2CHISTCall1DialedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __MMI_UCM__
    SetLeftSoftkeyFunction(MTPNP_PFAL_Call_Dialed, KEY_EVENT_UP);
#endif
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void MTPNP_PFAL_Call_Dialed(void)
{
    U8 index;

    addToHistory = 0;

    index = Callhistiry_info->currDialedCallIndex;
    MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        if (Callhistiry_info[index].name[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_SLAVE_DIALED_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR_MTPNP_DIALED_CALLHIS_OPTION)
            {
                mmi_ucm_app_entry_dial_option((U8 *) Callhistiry_info[index].name, MTPNP_PFAL_Call_Dialed_cbk, NULL);
            }
            else
        #endif
            {
                MakeCall((S8*) Callhistiry_info[index].name);
                MTPNP_PFAL_Call_Dialed_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_NONUMBER_TO_DIAL), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_SLAVE_DIALED_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR_MTPNP_DIALED_CALLHIS_OPTION)
        {
            mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].number, MTPNP_PFAL_Call_Dialed_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (Callhistiry_info[index].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) Callhistiry_info[index].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) Callhistiry_info[index].number);
            }
            MTPNP_PFAL_Call_Dialed_cbk(NULL);
        }
    }

}


void EV_MTPNP_PFAL_Call_Dialed(void)
{
    U8 index;

    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = dial_Callhistiry_info  ;

    addToHistory = 0;

    index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;
   
    if (Callhistiry_info[index].number[0] == 0)
    {
        if (Callhistiry_info[index].name[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_SLAVE_DIALED_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR_MTPNP_DIALED_CALLHIS_OPTION)
            {
                mmi_ucm_app_entry_dial_option((U8 *) Callhistiry_info[index].name, MTPNP_PFAL_Call_Dialed_cbk, NULL);
            }
            else
        #endif
            {
                MakeCall((S8*) Callhistiry_info[index].name);
                MTPNP_PFAL_Call_Dialed_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_NONUMBER_TO_DIAL), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_SLAVE_DIALED_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR_MTPNP_DIALED_CALLHIS_OPTION)
        {
            mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].number, MTPNP_PFAL_Call_Dialed_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (Callhistiry_info[index].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) Callhistiry_info[index].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) Callhistiry_info[index].number);
            }
            MTPNP_PFAL_Call_Dialed_cbk(NULL);
        }
    }

}



void MTPNP_PFAL_Call_Dialed_cbk(void *p)
{
    DeleteCallLogSrc();
}

void MTPNP_PFAL_Call_Recved(void)
{
    U8 index;

    addToHistory = 0;

    index = Callhistiry_info->currRecvdCallIndex;
    MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_RecvdCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        if (Callhistiry_info[index].name[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_SLAVE_RECVD_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR_MTPNP_RECVD_CALLHIS_OPTION)
            {       
                mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].name, MTPNP_PFAL_Call_Recvd_cbk, NULL);
            }
            else               
        #endif
            {
               MakeCall((S8*) Callhistiry_info[index].name);
               MTPNP_PFAL_Call_Recvd_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_NONUMBER_TO_DIAL), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_SLAVE_RECVD_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR_MTPNP_RECVD_CALLHIS_OPTION)
        { 
            mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].number, MTPNP_PFAL_Call_Recvd_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (Callhistiry_info[index].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) Callhistiry_info[index].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) Callhistiry_info[index].number);
            }
            MTPNP_PFAL_Call_Recvd_cbk(NULL);
        }
    }

}



void EV_MTPNP_PFAL_Call_Recved(void)
{
    U8 index;

    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = recv_Callhistiry_info  ;
	
    addToHistory = 0;

    index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        if (Callhistiry_info[index].name[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_SLAVE_RECVD_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR_MTPNP_RECVD_CALLHIS_OPTION)
            {       
                mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].name, MTPNP_PFAL_Call_Recvd_cbk, NULL);
            }
            else               
        #endif
            {
               MakeCall((S8*) Callhistiry_info[index].name);
               MTPNP_PFAL_Call_Recvd_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_NONUMBER_TO_DIAL), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_SLAVE_RECVD_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR_MTPNP_RECVD_CALLHIS_OPTION)
        { 
            mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].number, MTPNP_PFAL_Call_Recvd_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (Callhistiry_info[index].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) Callhistiry_info[index].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) Callhistiry_info[index].number);
            }
            MTPNP_PFAL_Call_Recvd_cbk(NULL);
        }
    }

}


void MTPNP_PFAL_Call_Recvd_cbk(void *p)
{
    DeleteCallLogSrc();
}


void MTPNP_PFAL_Call_Missed(void)
{
    U8 index;

    addToHistory = 0;

    index = Callhistiry_info->currMissedCallIndex;
    MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_MissedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        if (Callhistiry_info[index].name[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_SLAVE_MISSED_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR_MTPNP_MISSED_CALLHIS_OPTION)
            {       
                mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].name, MTPNP_PFAL_Call_Missed_cbk, NULL);
            }
            else               
        #endif
            {
                MakeCall((S8*) Callhistiry_info[index].name);
                MTPNP_PFAL_Call_Missed_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_NONUMBER_TO_DIAL), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_SLAVE_MISSED_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR_MTPNP_MISSED_CALLHIS_OPTION)
        { 
            mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].number, MTPNP_PFAL_Call_Missed_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (Callhistiry_info[index].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) Callhistiry_info[index].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) Callhistiry_info[index].number);
            }
            MTPNP_PFAL_Call_Missed_cbk(NULL);
        }
    }
}



void EV_MTPNP_PFAL_Call_Missed(void)
{
    U8 index;

    ST_MTPNP_CALLHIS_INFO  * Callhistiry_info = miss_Callhistiry_info  ;
	
    addToHistory = 0;

    index = CallHistoryListMapToOrginal[ev_slave_current_call_history_index].CallLogOrginalIndex;
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        if (Callhistiry_info[index].name[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_SLAVE_MISSED_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR_MTPNP_MISSED_CALLHIS_OPTION)
            {       
                mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].name, MTPNP_PFAL_Call_Missed_cbk, NULL);
            }
            else               
        #endif
            {
                MakeCall((S8*) Callhistiry_info[index].name);
                MTPNP_PFAL_Call_Missed_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_NONUMBER_TO_DIAL), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_SLAVE_MISSED_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR_MTPNP_MISSED_CALLHIS_OPTION)
        { 
            mmi_ucm_app_entry_dial_option((U8*) Callhistiry_info[index].number, MTPNP_PFAL_Call_Missed_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (Callhistiry_info[index].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) Callhistiry_info[index].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) Callhistiry_info[index].number);
            }
            MTPNP_PFAL_Call_Missed_cbk(NULL);
        }
    }
}

void MTPNP_PFAL_Call_Missed_cbk(void *p)
{
    DeleteCallLogSrc();
}


void MTPNP_PFAL_GetCallLogName(ST_MTPNP_AD_CALL_NAME *item)
{
    MTPNP_AD_REQ_CALL_RECORD_SCT *curr_hilite;
    MTPNP_UINT8 index;
    MTPNP_UINT8 name_dcs = 0;
    MTPNP_UINT8 name_len = 0;
    
    memset(item, 0, sizeof(ST_MTPNP_AD_CALL_NAME));

    switch (chis_p->dialFromCallLog)
    {
        case ITEM_SLAVE_DIALED_CALL:
            index = Callhistiry_info->currDialedCallIndex;
            name_len = MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
            MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
            name_dcs = MTPNP_AD_Get_DialedCallHistory_Name_DCS(index);
            break;
        case ITEM_SLAVE_MISSED_CALL:
            index = Callhistiry_info->currMissedCallIndex;
            name_len = MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
            MTPNP_AD_Get_MissedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
            name_dcs = MTPNP_AD_Get_MissedCallHistory_Name_DCS(index);
            break;
        case ITEM_SLAVE_RECVD_CALL:
            index = Callhistiry_info->currRecvdCallIndex;
            name_len = MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
            MTPNP_AD_Get_RecvdCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
            name_dcs = MTPNP_AD_Get_RecvdCallHistory_Name_DCS(index);
            break;
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        case ITEM_SLAVE_MIXED_CALL:
            index = Callhistiry_info->currDialedCallIndex;
            name_len = MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
            MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
            name_dcs = MTPNP_AD_Get_DialedCallHistory_Name_DCS(index);
            break;
    #endif 
        default:
            return;
    }

    if (Callhistiry_info[index].number[0] != 0)
    {
        if (CheckValidEmergencyNo1((S8*) Callhistiry_info[index].number, SIM2))	
        {
            mmi_ucs2ncpy((PS8) item->name, GetString(STR_EMERGENCY_NUMBER), MAX_PB_NAME_LENGTH);
            item->name_len = mmi_ucs2strlen((PS8) item->name);
            if (GetUCS2Flag((PS8) item->name))
            {
                item->dcs = MMI_PHB_UCS2;
            }
            else
            {
                item->dcs = MMI_PHB_ASCII;
            }
        }
        else
        {
            memcpy(item->name, Callhistiry_info[index].name, sizeof(item->name));
            item->name_len = name_len;
            item->dcs = name_dcs;
        }
    }
    return;
}

/*void MTPNP_PFAL_Call1_From_Dialed(void)
{
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);

    MTPNP_PFAL_Call_Dialed();
}

void MTPNP_PFAL_Call1_From_Recved(void)
{
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);

    MTPNP_PFAL_Call_Recved();
}

void MTPNP_PFAL_Call1_From_Missed(void)
{
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);

    MTPNP_PFAL_Call_Missed();
}

void MTPNP_PFAL_Call2_From_Dialed(void)
{
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);

    MTPNP_PFAL_Call_Dialed();
}

void MTPNP_PFAL_Call2_From_Recved(void)
{
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);

    MTPNP_PFAL_Call_Recved();
}

void MTPNP_PFAL_Call2_From_Missed(void)
{
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);

    MTPNP_PFAL_Call_Missed();
}*/

void HighlightSlaveCHISTEditDialedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_Edit_Dialed, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void MTPNP_PFAL_Edit_Dialed(void)
{
    U8 index;

    index = Callhistiry_info->currDialedCallIndex;
#if 0
     // Huyanwei Modify It 
     MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
     MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
#else	 
    if (g_get_call_history_by_send != 1 )	
    {
     MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
     MTPNP_AD_Get_DialedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    }
#endif
    if (Callhistiry_info[index].number[0] == 0)
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8 *) Callhistiry_info[index].name);
    }
    else
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8 *) Callhistiry_info[index].number);
    }

    g_idle_context.LongPressEnable = 1;
    
    IdleScreenDigitHandler();
}

void MTPNP_PFAL_Edit_Recved(void)
{
    U8 index;
    
    index = Callhistiry_info->currRecvdCallIndex;
#if 1
	// Huyanwei Add It 
   if (g_get_call_history_by_send != 1 )
#endif
    {
    MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_RecvdCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    }
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8 *) Callhistiry_info[index].name);
    }
    else
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8 *) Callhistiry_info[index].number);
    }

    g_idle_context.LongPressEnable = 1;
    IdleScreenDigitHandler();
}

void MTPNP_PFAL_Edit_Missed(void)
{
    U8 index;

    index = Callhistiry_info->currMissedCallIndex;
#if 1
	// Huyanwei Add It 
   if (g_get_call_history_by_send != 1 )
#endif
    {
    MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) Callhistiry_info[index].name);
    MTPNP_AD_Get_MissedCallHistory_Number(index, (MTPNP_UINT8 *) Callhistiry_info[index].number);
    }
    
    if (Callhistiry_info[index].number[0] == 0)
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8 *) Callhistiry_info[index].name);
    }
    else
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8 *) Callhistiry_info[index].number);
    }

    g_idle_context.LongPressEnable = 1;
    IdleScreenDigitHandler();
}

#ifdef __MMI_CH_OPTIONS_SENDSMS__
void HighlightSlaveCHISTSendSMSDialedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_SendSMS_From_Dialed, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */

#ifdef __MMI_CH_OPTIONS_SENDSMS__
void MTPNP_PFAL_SendSMS_From_Dialed(void)
{
    MTPNP_UINT8 index;
    MTPNP_UINT8 number[(MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH];
    MTPNP_CHAR name[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
    MTPNP_INT name_length = 0, number_length = 0;

    /* check SMS re-entering */
    if (IsMessagesReEntering())
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_MSG_NOT_READY_YET),
                     IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        return;
    }

    /* set interface for SMS */
    mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

    MTPNP_OSAL_memset(name, 0, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
    MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);

    index = Callhistiry_info->currDialedCallIndex;


#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send == 1 )
   {
       mmi_ucs2cpy((S8 *)number, (S8 *)Callhistiry_info[index].number);
       mmi_ucs2cpy((S8 *)name,(S8 *)Callhistiry_info[index].name );
   }
   else
#endif   
	{
	    MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) name);
	    MTPNP_AD_Get_DialedCallHistory_Number(index, number);
	}

    name_length = MTPNP_PFAL_Unicode_String_Length(name);
    number_length = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) number);

    /* check number */
    if (number_length <= (MAX_PB_NUMBER_LENGTH / ENCODING_LENGTH))
    {
        if (number_length == 0)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                         IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
        }
        else
        {
            mmi_msg_get_number_from_phb((U8 *) name, (U8 *) number);
        }
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                     IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
    }
}

void MTPNP_PFAL_SendSMS_From_Recved(void)
{
    MTPNP_UINT8 index;
    MTPNP_UINT8 number[(MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH];
    MTPNP_CHAR name[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
    MTPNP_INT name_length = 0, number_length = 0;

    /* check SMS re-entering */
    if (IsMessagesReEntering())
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_MSG_NOT_READY_YET),
                     IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        return;
    }

    /* set interface for SMS */
    mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

    MTPNP_OSAL_memset(name, 0, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
    MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);

    index = Callhistiry_info->currRecvdCallIndex;
#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send == 1 )
   {
       mmi_ucs2cpy((S8 *)number, (S8 *)Callhistiry_info[index].number);
       mmi_ucs2cpy((S8 *)name, (S8 *)Callhistiry_info[index].name );
   }
   else
#endif   
   {
    MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) name);
    MTPNP_AD_Get_RecvdCallHistory_Number(index, number);
    } 

    name_length = MTPNP_PFAL_Unicode_String_Length(name);
    number_length = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) number);

    /* check number */
    if (number_length <= (MAX_PB_NUMBER_LENGTH / ENCODING_LENGTH))
    {
        if (number_length == 0)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                         IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
        }
        else
        {
            mmi_msg_get_number_from_phb((U8 *) name, (U8 *) number);
        }
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                     IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
    }
}

void MTPNP_PFAL_SendSMS_From_Missed(void)
{
    MTPNP_UINT8 index;
    MTPNP_UINT8 number[(MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH];
    MTPNP_CHAR name[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
    MTPNP_INT name_length = 0, number_length = 0;

    /* check SMS re-entering */
    if (IsMessagesReEntering())
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_MSG_NOT_READY_YET),
                     IMG_GLOBAL_UNFINISHED, 1, MESSAGES_POPUP_TIME_OUT, (MTPNP_UINT8) ERROR_TONE);
        return;
    }

    /* set interface for SMS */
    mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

    MTPNP_OSAL_memset(name, 0, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
    MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);

    index = Callhistiry_info->currMissedCallIndex;
#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send == 1 )
   {
       mmi_ucs2cpy((S8 *)number, (S8 *)Callhistiry_info[index].number);
       mmi_ucs2cpy((S8 *)name, (S8 *)Callhistiry_info[index].name );
   }
   else
#endif   
   {
    MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) name);
    MTPNP_AD_Get_MissedCallHistory_Number(index, number);
    } 
    name_length = MTPNP_PFAL_Unicode_String_Length(name);
    number_length = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) number);

    /* check number */
    if (number_length <= (MAX_PB_NUMBER_LENGTH / ENCODING_LENGTH))
    {
        if (number_length == 0)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                         IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
        }
        else
        {
            mmi_msg_get_number_from_phb((U8 *) name, (U8 *) number);
        }
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                     IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
    }
}
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */

#ifdef __MMI_CH_OPTIONS_SENDMMS__
void HighlightSlaveCHISTSendMMSDialedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_SendMMS_From_Dialed, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

void HighlightSlaveCHISTInfoMissedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntrySlaveCHISTViewMissedCallInfo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void HighlightSlaveCHISTDeleteMissedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryDeleteSIM2MissedLogConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTSaveMissedNum(void)
{
    SetKeyHandler(MTPNP_PFAL_Save_Missed, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_Save_Missed, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSIM2CHISTCall1MissedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __MMI_UCM__
    SetLeftSoftkeyFunction(MTPNP_PFAL_Call_Missed, KEY_EVENT_UP);
#endif /*__MMI_UCM__*/
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTEditMissedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_Edit_Missed, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_CH_OPTIONS_SENDSMS__
void HighlightSlaveCHISTSendSMSMissedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_SendSMS_From_Missed, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */

#ifdef __MMI_CH_OPTIONS_SENDMMS__
void HighlightSlaveCHISTSendMMSMissedNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(MTPNP_PFAL_SendMMS_From_Missed, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

void HighlightSlaveCHISTInfoRecvdNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntrySlaveCHISTViewRecvdCallInfo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTDeleteRecvdNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryDeleteSIM2RecvedLogConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTSaveRecvdNum(void)
{
    SetKeyHandler(MTPNP_PFAL_Save_Recved, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_Save_Recved, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSIM2CHISTCall1RecvdNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __MMI_UCM__
    SetLeftSoftkeyFunction(MTPNP_PFAL_Call_Recved, KEY_EVENT_UP);
#endif /*__MMI_UCM__*/
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

/*void HighlightSIM2CHISTCall2RecvdNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_Call2_From_Dialed, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}*/

void HighlightSlaveCHISTEditRecvdNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_Edit_Recved, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_CH_OPTIONS_SENDSMS__
void HighlightSlaveCHISTSendSMSRecvdNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(MTPNP_PFAL_SendSMS_From_Recved, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif  /* __MMI_CH_OPTIONS_SENDSMS__ */

#ifdef __MMI_CH_OPTIONS_SENDMMS__
void HighlightSlaveCHISTSendMMSRecvdNum(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(MTPNP_PFAL_SendMMS_From_Recved, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

#ifdef __MMI_CH_OPTIONS_SENDMMS__
void MTPNP_PFAL_SendMMS_From_Dialed(void)
{
    MTPNP_UINT8 number[(MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH];
    MTPNP_INT name_length = 0, number_length = 0;
    MTPNP_UINT8 index;

#ifdef WAP_SUPPORT
    MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);

    index = Callhistiry_info->currDialedCallIndex;

#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send == 1 )
   {
       mmi_ucs2cpy((S8 *)number, (S8 *)Callhistiry_info[index].number);
       if (number[0] == 0)
       {
           MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);
	    mmi_ucs2cpy((S8 *)number,(S8 *)Callhistiry_info[index].name );
       }   
   }
   else
#endif    	
   {
       MTPNP_AD_Get_DialedCallHistory_Number(index, number);
       if (number[0] == 0)
       {
           MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);
           MTPNP_AD_Get_DialedCallHistory_Name(index, (MTPNP_UINT8 *) number);
       }   	
   }

    number_length = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) number);

    /* check number */
    if (number_length <= MAX_PB_NUMBER_LENGTH)
    {
        if (number_length == 0)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                         IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
        }
        else
        {
            mms_address_insert_hdlr((MTPNP_CHAR *) number);
        }
    }
    else
#endif
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                     IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
    }
}

void MTPNP_PFAL_SendMMS_From_Recved(void)
{
    MTPNP_UINT8 number[(MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH];
    MTPNP_INT name_length = 0, number_length = 0;
    MTPNP_UINT8 index;

#ifdef WAP_SUPPORT
    MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);

    index = Callhistiry_info->currRecvdCallIndex;


#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send == 1 )
   {
       mmi_ucs2cpy((S8 *)number, (S8 *)Callhistiry_info[index].number);
       if (number[0] == 0)
       {
           MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);
	    mmi_ucs2cpy((S8 *)number,(S8 *)Callhistiry_info[index].name );
       }   
   }
   else
#endif    	
   {
	    MTPNP_AD_Get_RecvdCallHistory_Number(index, number);	    
	    if (number[0] == 0)
	    {
	        MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);
	        MTPNP_AD_Get_RecvdCallHistory_Name(index, (MTPNP_UINT8 *) number);
	    }
   }

    number_length = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) number);

    /* check number */
    if (number_length <= MAX_PB_NUMBER_LENGTH)
    {
        if (number_length == 0)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                         IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
        }
        else
        {
            mms_address_insert_hdlr((MTPNP_CHAR *) number);
        }
    }
    else
#endif
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                     IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
    }
}

void MTPNP_PFAL_SendMMS_From_Missed(void)
{
    MTPNP_UINT8 number[(MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH];
    MTPNP_INT name_length = 0, number_length = 0;
    MTPNP_UINT8 index;

#ifdef WAP_SUPPORT
    MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);

    index = Callhistiry_info->currMissedCallIndex;

#if 1
   // Huyanwei Add It 
   if (g_get_call_history_by_send == 1 )
   {
       mmi_ucs2cpy((S8 *)number, (S8 *)Callhistiry_info[index].number);
       if (number[0] == 0)
       {
           MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);
	    mmi_ucs2cpy((S8 *)number,(S8 *)Callhistiry_info[index].name );
       }   
   }
   else
#endif   
   {
	    MTPNP_AD_Get_MissedCallHistory_Number(index, number);    
	    if (number[0] == 0)
	    {
	        MTPNP_OSAL_memset(number, 0, (MAX_CC_ADDR_LEN + 1) * ENCODING_LENGTH);
	        MTPNP_AD_Get_MissedCallHistory_Name(index, (MTPNP_UINT8 *) number);
	    }
    }
	
    number_length = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) number);

    /* check number */
    if (number_length <= MAX_PB_NUMBER_LENGTH)
    {
        if (number_length == 0)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                         IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
        }
        else
        {
            mms_address_insert_hdlr((MTPNP_CHAR *) number);
        }
    }
    else
#endif
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                     IMG_GLOBAL_UNFINISHED, 1, PHB_NOTIFY_TIMEOUT, (MTPNP_UINT8) ERROR_TONE);
    }
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */

/* sms count begin */
void CallHISResetSlaveSentSMS(void)
{
    MTPNP_AD_Reset_SMS_Count(MTPNP_SMSCOUNT_SENT);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_MTPNP_SMS_COUNTER);
}

void CallHISSlaveResetSentSlaveSMSConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_GPRS_RESET_COUNTER_QUERY), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(CallHISResetSlaveSentSMS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void HighlightSlaveCHISTSlaveSentSMS(void)
{
    if (MTPNP_AD_Get_SMS_Count(MTPNP_SMSCOUNT_SENT) == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_RESET, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(CallHISSlaveResetSentSlaveSMSConfirm, KEY_EVENT_UP);
    }
}

void HintCHISTSlaveSentSMS(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    MTPNP_UINT16 count = MTPNP_AD_Get_SMS_Count(MTPNP_SMSCOUNT_SENT);

    MTPNP_OSAL_memset(hintData[index], 0, sizeof(hintData[index]));
    if (count == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STR_SMS_NO_NUMBER), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((MTPNP_CHAR *) value, "%d ", count);
        mmi_asc_to_ucs2((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) value);
        MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STR_SMS_STRING));
    }
}

void CHISTResetSlaveRecvdSMS(void)
{
    MTPNP_AD_Reset_SMS_Count(MTPNP_SMSCOUNT_RECV);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_MTPNP_SMS_COUNTER);
}

void CallHISSlaveResetRecvdSlaveSMSConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_GPRS_RESET_COUNTER_QUERY), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(CHISTResetSlaveRecvdSMS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTSlaveRecvdSMS(void)
{
    if (MTPNP_AD_Get_SMS_Count(MTPNP_SMSCOUNT_RECV) == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_RESET, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(CallHISSlaveResetRecvdSlaveSMSConfirm, KEY_EVENT_UP);
    }
}

void HintCHISTSlaveRecvdSMS(U16 index)
{
    MTPNP_UINT8 value[MAX_SUB_MENU_HINT_SIZE];
    MTPNP_UINT16 count = MTPNP_AD_Get_SMS_Count(MTPNP_SMSCOUNT_RECV);

    MTPNP_OSAL_memset(hintData[index], 0, sizeof(hintData[index]));
    if (count == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STR_SMS_NO_NUMBER), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((MTPNP_CHAR *) value, "%d ", count);
        mmi_asc_to_ucs2((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) value);
        MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STR_SMS_STRING));
    }
}

/* sms count end */

void GetSlaveCurrDialedCallHISIndex(S32 ind)
{
    Callhistiry_info->currDialedCallIndex = (U8) ind;
    return;
}

void GetSlaveCurrRecvdCallHISIndex(S32 ind)
{
    Callhistiry_info->currRecvdCallIndex = (U8) ind;
    return;
}

void GetSlaveCurrMissedCallHISIndex(S32 ind)
{
    Callhistiry_info->currMissedCallIndex = (U8) ind;
    return;
}

void MTPNP_PFAL_Delete_Calllog_Success(void)
{
    MTPNP_AD_Set_MissedCallCount(0);
    HideStatusIcon(STATUS_ICON_CARD2MISSED_CALL);
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);

}

void MTPNP_PFAL_Delete_DialedCalllog_Success(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    if (MTPNP_AD_Get_CallHistory_Dialedcall() == 0)
    {
        DeleteBetweenScreen(SCR_MTPNP_DIALED_CALLHIS_LIST, SCR_MTPNP_DIALED_CALLHIS_OPTION);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_OPTION);
#else
        DeleteBetweenScreen(SCR_MTPNP_DIALED_CALLHIS_INFO, SCR_MTPNP_DIALED_CALLHIS_OPTION);
#endif
    return;

}

void MTPNP_PFAL_Delete_AllCalllogs_Success(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    return;

}

void MTPNP_PFAL_Delete_MissedCalllog_Success(void)
{
    MTPNP_PFAL_chist_set_have_missed_call_flag(0);
    MTPNP_PFAL_chist_set_have_missed_call();
    MTPNP_AD_Set_MissedCallCount(0);
    HideStatusIcon(STATUS_ICON_CARD2MISSED_CALL);    
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    if (MTPNP_AD_Get_CallHistory_Missedcall() == 0)
    {
        DeleteBetweenScreen(SCR_MTPNP_MISSED_CALLHIS_LIST, SCR_MTPNP_MISSED_CALLHIS_OPTION);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_OPTION);
#else
        DeleteBetweenScreen(SCR_MTPNP_MISSED_CALLHIS_INFO, SCR_MTPNP_MISSED_CALLHIS_OPTION);
#endif
    return;

}

void MTPNP_PFAL_Delete_RecvedCalllog_Success(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    if (MTPNP_AD_Get_CallHistory_Recvdcall() == 0)
    {
        DeleteBetweenScreen(SCR_MTPNP_RECVD_CALLHIS_LIST, SCR_MTPNP_RECVD_CALLHIS_OPTION);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_OPTION);
#else
        DeleteBetweenScreen(SCR_MTPNP_RECVD_CALLHIS_INFO, SCR_MTPNP_RECVD_CALLHIS_OPTION);
#endif
    return;

}

void MTPNP_PFAL_Delete_DialedCalllog_Failed(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                 ERROR_TONE);
    if (MTPNP_AD_Get_CallHistory_Dialedcall() == 0)
    {
        DeleteBetweenScreen(SCR_MTPNP_DIALED_CALLHIS_LIST, SCR_MTPNP_DIALED_CALLHIS_OPTION);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR_MTPNP_DIALED_CALLHIS_OPTION);
#else
        DeleteBetweenScreen(SCR_MTPNP_DIALED_CALLHIS_INFO, SCR_MTPNP_DIALED_CALLHIS_OPTION);
#endif
    return;

}

void MTPNP_PFAL_Delete_MissedCalllog_Failed(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                 ERROR_TONE);
    if (MTPNP_AD_Get_CallHistory_Missedcall() == 0)
    {
        DeleteBetweenScreen(SCR_MTPNP_MISSED_CALLHIS_LIST, SCR_MTPNP_MISSED_CALLHIS_OPTION);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR_MTPNP_MISSED_CALLHIS_OPTION);
#else
        DeleteBetweenScreen(SCR_MTPNP_MISSED_CALLHIS_INFO, SCR_MTPNP_MISSED_CALLHIS_OPTION);
#endif
    return;

}

void MTPNP_PFAL_Delete_RecvedCalllog_Failed(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                 ERROR_TONE);
    if (MTPNP_AD_Get_CallHistory_Recvdcall() == 0)
    {
        DeleteBetweenScreen(SCR_MTPNP_RECVD_CALLHIS_LIST, SCR_MTPNP_RECVD_CALLHIS_OPTION);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR_MTPNP_RECVD_CALLHIS_OPTION);
#else
        DeleteBetweenScreen(SCR_MTPNP_RECVD_CALLHIS_INFO, SCR_MTPNP_RECVD_CALLHIS_OPTION);
#endif
    return;

}

void MTPNP_PFAL_Delete_Calllog_Failed(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                 ERROR_TONE);
}

void HintSlaveCHISTDialedCalls(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (MTPNP_AD_Get_CallHistory_Dialedcall() == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((S8 *) hintData[index], (S8 *) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8 *) value, "%d ", MTPNP_AD_Get_CallHistory_Dialedcall());
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (MTPNP_AD_Get_CallHistory_Dialedcall() == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }
    }
    return;
}

void HintSlaveCHISTRecvdCalls(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (MTPNP_AD_Get_CallHistory_Recvdcall() == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((S8 *) hintData[index], (S8 *) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8 *) value, "%d ", MTPNP_AD_Get_CallHistory_Recvdcall());
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (MTPNP_AD_Get_CallHistory_Recvdcall() == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }
    }
    return;
}

void HintSlaveCHISTMissedCalls(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (MTPNP_AD_Get_CallHistory_Missedcall() == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((S8 *) hintData[index], (S8 *) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8 *) value, "%d ", MTPNP_AD_Get_CallHistory_Missedcall());
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (MTPNP_AD_Get_CallHistory_Missedcall() == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }    
    }
    return;
}

void HintSlaveCHISTDeleteAllDialed(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (MTPNP_AD_Get_CallHistory_Dialedcall() == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((S8 *) hintData[index], (S8 *) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8 *) value, "%d ", MTPNP_AD_Get_CallHistory_Dialedcall());
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (MTPNP_AD_Get_CallHistory_Dialedcall() == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }
    }
    return;
}

void HintSlaveCHISTDeleteAllRecvd(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (MTPNP_AD_Get_CallHistory_Recvdcall() == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((S8 *) hintData[index], (S8 *) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8 *) value, "%d ", MTPNP_AD_Get_CallHistory_Recvdcall());
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (MTPNP_AD_Get_CallHistory_Recvdcall() == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }
    }
    return;
}

void HintSlaveCHISTDeleteAllMissed(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (MTPNP_AD_Get_CallHistory_Missedcall() == 0)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((S8 *) hintData[index], (S8 *) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8 *) value, "%d ", MTPNP_AD_Get_CallHistory_Missedcall());
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (MTPNP_AD_Get_CallHistory_Missedcall() == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }    
    }
    return;
}

void HintSlaveCHISTLastTime(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    sprintf((S8 *) value, "%02d:%02d:%02d",
            g_Slave_Calltime.last_call_time.nHour,
            g_Slave_Calltime.last_call_time.nMin, g_Slave_Calltime.last_call_time.nSec);

    mmi_asc_to_ucs2((S8 *) hintData[index], (S8 *) value);

    return;
}

void HintSlaveCHISTSentTime(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    sprintf((S8 *) value, "%02d:%02d:%02d",
            g_Slave_Calltime.total_out_time.nHour,
            g_Slave_Calltime.total_out_time.nMin, g_Slave_Calltime.total_out_time.nSec);

    mmi_asc_to_ucs2((S8 *) hintData[index], (S8 *) value);

    return;
}

void HintSlaveCHISTRecvdTime(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    sprintf((S8 *) value, "%02d:%02d:%02d",
            g_Slave_Calltime.total_in_time.nHour,
            g_Slave_Calltime.total_in_time.nMin, g_Slave_Calltime.total_in_time.nSec);

    mmi_asc_to_ucs2((S8 *) hintData[index], (S8 *) value);

    return;
}

void LogSlaveCallDuration(ST_MTPNP_AD_SLAVE_CALL_INFO * callinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    kal_uint16 start_lid;
    kal_uint16 total_lid_for_one_type;
    nvram_ef_phb_ln_struct *temp_call_log;
    MYTIME start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_lid_for_one_type = (TOT_SIZE_OF_DIALED_LIST + TOT_SIZE_OF_ONE_LN_LIST -1)/TOT_SIZE_OF_ONE_LN_LIST;
    
    if (callinfo->orgination_flag == MTPNP_CM_CALL_MO)
    {
        start_lid = 1 + 3 * total_lid_for_one_type;
    }
    else if (callinfo->orgination_flag == MTPNP_CM_CALL_MT)
    {
        start_lid = 1 + 5 * total_lid_for_one_type;
    }
    else
    {
        return;
    }
    temp_call_log = OslMalloc(NVRAM_EF_PHB_LN_ENTRY_SIZE);
    if (temp_call_log)
    {
        int i;
        S8 *ucs2_number = OslMalloc((MAX_PB_NUMBER_LENGTH+1+1)* ENCODING_LENGTH);
        ReadRecord(NVRAM_EF_PHB_LN_ENTRY_LID, start_lid, temp_call_log, NVRAM_EF_PHB_LN_ENTRY_SIZE, &error);
        for (i=0; i< temp_call_log->no_entry; i++)
        {
            S8 tempNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
        #ifdef __MMI_VOIP__
            if (temp_call_log->array[i].addr_type != PHB_LN_CALL)
            {
                continue;
            }
        #endif /* __MMI_VOIP__ */
            ConvertRTC2MYTIME(&start_time, &temp_call_log->array[i].time);
            if (CompareTime(start_time, callinfo->start_time, NULL) == 0)
            {
                if (((temp_call_log->array[i].addr_bcd[0] & 0x90) == 0x90) && (temp_call_log->array[i].addr_bcd[0] != 0xFF))
                {
                    tempNumber[0] = '+';
                    mmi_phb_convert_to_digit((U8*) (tempNumber + 1), temp_call_log->array[i].addr_bcd + 1, MAX_PB_NUMBER_LENGTH + 1);
                }
                else
                {
                    mmi_phb_convert_to_digit(tempNumber, temp_call_log->array[i].addr_bcd + 1, MAX_PB_NUMBER_LENGTH + 1);
                }

                mmi_asc_to_ucs2((S8*) ucs2_number, (S8*) tempNumber);

                if (mmi_ucs2cmp((const S8*)ucs2_number, (const S8*)(&callinfo->call_number.number)) == 0)
                {
                    temp_call_log->array[i].call_duration = applib_get_time_difference_ext_in_second((applib_time_struct*)&callinfo->end_time, (applib_time_struct*)&callinfo->start_time);
                    WriteRecord(NVRAM_EF_PHB_LN_ENTRY_LID, start_lid, temp_call_log, NVRAM_EF_PHB_LN_ENTRY_SIZE, &error);
                    break;
                }
            }
        }
        OslMfree(ucs2_number);
        OslMfree(temp_call_log);
    }
}
void LogSlaveDialedCallDuration(ST_MTPNP_AD_SLAVE_CALL_INFO * callinfo)
{
    S16 error = 0;
    MYTIME *endTime, *beginTime;

    beginTime = (MYTIME *) & callinfo->start_time;
    endTime = (MYTIME *) & callinfo->end_time;
    if (CompareTime(*endTime, *beginTime, NULL) != TIME_EQUAL)
    {
        GetTimeDifference(endTime, beginTime, &g_Slave_Calltime.last_call_time);
        WriteRecord(NVRAM_EF_CALL_TIME_LID, 4, (void *) &g_Slave_Calltime.last_call_time, sizeof(MYTIME), &error);

        if (MTPNP_CM_CALL_MO == callinfo->orgination_flag)
        {
            IncrementTime(g_Slave_Calltime.total_out_time, g_Slave_Calltime.last_call_time,
                          &(g_Slave_Calltime.total_out_time));
            WriteRecord(NVRAM_EF_CALL_TIME_LID, 5, (void *) &g_Slave_Calltime.total_out_time, sizeof(MYTIME), &error);  //dialed call
        }
        else
        {
            IncrementTime(g_Slave_Calltime.total_in_time, g_Slave_Calltime.last_call_time,
                          &(g_Slave_Calltime.total_in_time));
            WriteRecord(NVRAM_EF_CALL_TIME_LID, 6, (void *) &g_Slave_Calltime.total_in_time, sizeof(MYTIME), &error);   //recevd call
        }
		LogSlaveCallDuration(callinfo);
    }
    return;
}

void MTPNP_PFAL_CHIST_SAT_Handler(void)
{
    if (MTPNP_AD_Calllog_GetIsReady() == MTPNP_TRUE && MTPNP_AD_Calllog_GetStatus() == MTPNP_FALSE)
    {
        MTPNP_AD_slave_req_read_dialed_num();
    }
    else if (mmi_chist_get_sentreq_flag()== TRUE)
    {
        mmi_chist_set_sentreq_flag(FALSE);
    }
}

void HighlightCHISTMasterMissedNotify(void)
{
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        ChangeLeftSoftkey(MISSED_LSK_STR, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(CHISTMasterMissedNotifyHandler, KEY_EVENT_UP);
        SetRightSoftkeyFunction(CHISTIgnoreMissedCallScreen, KEY_EVENT_UP);
        SetKeyHandler(CHISTMasterMissedNotifyHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(CHISTIgnoreMissedCallScreen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
    }
}

void HighlightCHISTSlaveMissedNotify(void)
{
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        ChangeLeftSoftkey(MISSED_LSK_STR, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(CHISTSlaveMissedNotifyHandler, KEY_EVENT_UP);
        SetRightSoftkeyFunction(CHISTIgnoreMissedCallScreen, KEY_EVENT_UP);
        SetKeyHandler(CHISTSlaveMissedNotifyHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(CHISTIgnoreMissedCallScreen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
    }
}

void HintCHISTMasterMissedNotify(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    sprintf((S8 *) value, "%d ", chis_p->nMissedCallBeforeView);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((S8 *) hintData[index], (S8 *) GetString(STR_MISSED_CALLS), MAX_GET_STRING_LEN);
}

void HintCHISTSlaveMissedNotify(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    sprintf((S8 *) value, "%d ", MTPNP_AD_Get_MissedCallCount_BeforeView());
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((S8 *) hintData[index], (S8 *) GetString(STR_MISSED_CALLS), MAX_GET_STRING_LEN);
}

void CHISTMasterMissedNotifyHandler(void)
{
    CHISTReadMissedNum();
    chis_p->currMissedCallIndex = 0;
    chis_p->nMissedCallBeforeView = 0;
}

void CHISTSlaveMissedNotifyHandler(void)
{
    chis_p->saveMissedScrn = FALSE;
    MTPNP_AD_slave_req_read_missed_num();
    MTPNP_AD_Set_MissedCallCount(0);
    HideStatusIcon(STATUS_ICON_CARD2MISSED_CALL);
}

/* below three function is service for master call history */
void MTPNP_PFAL_ReadDualModeMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;                          /* Buffer holding history data */
    U16 nStrItemList[MAX_SUB_MENUS];        /* Stores the strings id of submenus returned */
    U16 nNumofItem;                         /* Stores no of children in the submenu */
    U16 ItemIcons[MAX_SUB_MENUS];
    U8 *PopUpList[MAX_SUB_MENUS];
    U16 LSKStr;
    U16 LSKImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI,"EntryCHISTNotifyMissedCall master = %d",CHISTGetMissedCallCountBeforeView());
    kal_prompt_trace(MOD_MMI,"EntryCHISTNotifyMissedCall slave = %d",MTPNP_AD_Get_MissedCallCount_BeforeView());
    /* Call Exit Handler */
    if((CHISTGetMissedCallCountBeforeView() != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)) && (MTPNP_AD_Get_MissedCallCount_BeforeView() != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)))
    {
        ;//do nothing
    }
    else
    {
        if (CHISTGetMissedCallCountBeforeView() != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE))
        {
            CHISTReadMissedNum();
        }
        else if (MTPNP_AD_Get_MissedCallCount_BeforeView() != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE))
        {
            CHISTSlaveMissedNotifyHandler();
        }
        else
        {
            SetMissedCallFlag(FALSE);
            EntryIdleScreen();
        }
        return;
    }
    EntryNewScreen(SCR_MTPNP_CALL_HISTORY_NOTIFY, NULL, MTPNP_PFAL_ReadDualModeMissedNum, NULL);
   
    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_CALL_HISTORY_NOTIFY);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_MISSED_CALL_NOTIFY); 
    /* Retrieve string/image ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_MISSED_CALL_NOTIFY, nStrItemList);     
    GetSequenceImageIds_Ext(MENU_MTPNP_MISSED_CALL_NOTIFY, ItemIcons); 
    /* Set current parent id */
    SetParentHandler(MENU_MTPNP_MISSED_CALL_NOTIFY);
  
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* construct hint popup strings for menu items */
    ConstructHintsList(MENU_MTPNP_MISSED_CALL_NOTIFY, PopUpList);
      
     LSKStr = MISSED_LSK_STR;
     LSKImg = IMG_GLOBAL_OK;        
     if (g_keylock_context.gKeyPadLockFlag == 0)
     {
	    ShowCategory52Screen(
	        STRING_MTPNP_MISSED_CALL_NOTIFY,
	        GetRootTitleIcon(MAIN_MENU_CALL_HISTORY),
	        LSKStr,
	        LSKImg,
	        STR_GLOBAL_BACK,
	        IMG_GLOBAL_BACK,
	        nNumofItem,
	        nStrItemList,
	        ItemIcons,
	        (U8 **)PopUpList,
	        0,
	        0,  /* u16callhist_curindex, */
	        guiBuffer);
	   SetKeyHandler(CHISTIgnoreMissedCallScreen, KEY_END, KEY_EVENT_DOWN);    
     }
     else
     {
	    ShowCategory52Screen(
	        STRING_MTPNP_MISSED_CALL_NOTIFY,
	        GetRootTitleIcon(MAIN_MENU_CALL_HISTORY),
	        g_keylock_context.KeyLockLSKStringID,
               g_keylock_context.KeyLockLSKIconID,
               g_keylock_context.KeyLockRSKStringID,
               g_keylock_context.KeyLockRSKIconID,
	        nNumofItem,
	        nStrItemList,
	        ItemIcons,
	        (U8 **)PopUpList,
	        0,
	        0,  /* u16callhist_curindex, */
	        guiBuffer);
	     ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
     }
    ForceSubLCDScreen(EntrySubCHISTNotifyMissedCall);
    return;
}


void MTPNP_PFAL_CHIST_Rearrange_Missed_Call_Status_Icon(void)
{
    E_MTPNP_AD_SIMCARD_USABLE_SIDE state;

    state = MTPNP_AD_Get_UsableSide();
    HideStatusIcon(STATUS_ICON_MISSED_CALL);
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
    HideStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
#endif
    MTPNP_PFAL_CC_HideCard2MissIcon();

    switch(state)
    {
        case MTPNP_AD_DUALSIM_USABLE:
            if (CHISTGetMissedCallCountBeforeView() != 0 || mmi_chist_get_missed_call_flag() == 1)
            {
                ShowStatusIcon(STATUS_ICON_MISSED_CALL);
            #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
                ShowStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
            #endif
            }
            if (MTPNP_AD_Get_MissedCallCount_BeforeView() != 0 || MTPNP_PFAL_chist_get_have_missed_call_flag() == 1)
            {
                MTPNP_PFAL_CC_ShowCard2MissIcon();
            }
            break;                
                
        case MTPNP_AD_SIMCARD1_USABLE:
            if (CHISTGetMissedCallCountBeforeView() != 0 || mmi_chist_get_missed_call_flag() == 1)
            {
                ShowStatusIcon(STATUS_ICON_MISSED_CALL);
            #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
                ShowStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
            #endif
            }            
            break;

        case MTPNP_AD_SIMCARD2_USABLE:
            if (MTPNP_AD_Get_MissedCallCount_BeforeView() != 0 || MTPNP_PFAL_chist_get_have_missed_call_flag() == 1)
            {
                MTPNP_PFAL_CC_ShowCard2MissIcon();
            }        
            break;

        default:
            break;
    }
    UpdateStatusIcons(); 
}

void MTPNP_PFAL_chist_init_get_data_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 tempHaveMissedCall;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SLAVE_CHIST_HAVE_MISSED_CALL, &tempHaveMissedCall, DS_SHORT, &pError);     /* 2 bytes for DS_SHORT */
    g_slave_chist_have_missed_call = (U8) tempHaveMissedCall;
    
    if ((g_slave_chist_have_missed_call != 0 && g_slave_chist_have_missed_call != 1) || is_sim_replaced(0x01))
    {
        g_slave_chist_have_missed_call = 0;
        tempHaveMissedCall = g_slave_chist_have_missed_call;
        WriteValue(NVRAM_SLAVE_CHIST_HAVE_MISSED_CALL, &tempHaveMissedCall, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }
}

void MTPNP_PFAL_chist_set_have_missed_call_flag(MTPNP_UINT8 is_missed_call)
{
    g_slave_chist_have_missed_call = is_missed_call;
}

MTPNP_UINT8 MTPNP_PFAL_chist_get_have_missed_call_flag(void)
{
    return g_slave_chist_have_missed_call;
}

void MTPNP_PFAL_chist_set_have_missed_call(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 tempHaveMissedCall;    /* Temp Solution For Write 2 bytes NVRAM_PHB_NAME_LIST_FILTER */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_slave_chist_set_have_missed_call");

    tempHaveMissedCall = g_slave_chist_have_missed_call;
    WriteValue(NVRAM_SLAVE_CHIST_HAVE_MISSED_CALL, &tempHaveMissedCall, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
}

#if !defined(__SENDKEY2_SUPPORT__) || defined(E8D) 
void HighlightCHISTDualMasterMixedCallLog(void)
{
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(CHISTGetCallLogBySENDKey, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


void HighlightCHISTDualSlaveMixedCallLog(void)
{
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


void MTPNP_PFAL_ReadDualMixedCallLog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;                          /* Buffer holding history data */
    U16 nStrItemList[MAX_SUB_MENUS];        /* Stores the strings id of submenus returned */
    U16 nNumofItem;                         /* Stores no of children in the submenu */
    U16 ItemIcons[MAX_SUB_MENUS];
    U8 *PopUpList[MAX_SUB_MENUS];
    U8 usable_side_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    if (mmi_bootup_is_searching_or_idle_reached() != MMI_TRUE || mmi_bootup_is_sim2_searching_or_idle_reached() != MMI_TRUE)
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8056_CAPTION,
            IMG_SCR8056_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        return;
    }

    CHISTResetCallLogIndex();
    usable_side_status = MTPNP_AD_Get_UsableSide();
    if (usable_side_status != MTPNP_AD_DUALSIM_USABLE)
    {
        if (usable_side_status == MTPNP_AD_SIMCARD1_USABLE)
        {
            CHISTGetCallLogBySENDKey();
            return;
        }
        else if (usable_side_status == MTPNP_AD_SIMCARD2_USABLE)
        {
            MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key();
            return;            
        }
    }

    EntryNewScreen(SCR_ID_CHIST_DUAL_CARD_MIXED_CALLLOG, NULL, MTPNP_PFAL_ReadDualMixedCallLog, NULL);
   
    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CHIST_DUAL_CARD_MIXED_CALLLOG);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG); 
    /* Retrieve string/image ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG, nStrItemList);     
    GetSequenceImageIds_Ext(MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG, ItemIcons); 
    /* Set current parent id */
    SetParentHandler(MENU_ID_CHIST_DUAL_CARD_MIXED_CALL_LOG);
  
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
	    ShowCategory52Screen(
	        STR_SCR_CALL_HISTORY_MAIN_MENU_CAPTION,
	        GetRootTitleIcon(MAIN_MENU_CALL_HISTORY),
	        STR_GLOBAL_OK,
	        IMG_GLOBAL_OK,
	        STR_GLOBAL_BACK,
	        IMG_GLOBAL_BACK,
	        nNumofItem,
	        nStrItemList,
	        (U16 *)gIndexIconsImageList,
	        0,
	        0,
	        0,  /* u16callhist_curindex, */
	        guiBuffer);
    return;
}
#endif /* __SENDKEY2_SUPPORT__ */


/* GPRS counter begin*/
#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  InitGPRSCounter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_GPRSCounter_Init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, HighlightSlaveGPRSCount);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_GPRS_LASTSENT, HighlightSlaveGPRSCountLastSent);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_GPRS_LASTRECEIVED, HighlightSlaveGPRSCountLastRecieved);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_GPRS_ALLSENT, HighlightSlaveGPRSCountAllSent);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_GPRS_ALLRECEIVED, HighlightSlaveGPRSCountAllReceived);
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_GPRS_RESETCOUNTER, HighlightSlaveGPRSCountCounterReset);

    SetHintHandler(MENU_MTPNP_CALL_HISTORY_GPRS_LASTSENT, HintSlaveGPRSCountLastSent);
    SetHintHandler(MENU_MTPNP_CALL_HISTORY_GPRS_LASTRECEIVED, HintSlaveGPRSCountLastRecieved);
    SetHintHandler(MENU_MTPNP_CALL_HISTORY_GPRS_ALLSENT, HintSlaveGPRSCountAllSent);
    SetHintHandler(MENU_MTPNP_CALL_HISTORY_GPRS_ALLRECEIVED, HintSlaveGPRSCountAllReceived);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSlaveGPRSCount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSlaveGPRSCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_UNIT_TEST__

    gSlavegprsTotalSent = 0;
    gSlavegprsTotalReceived = 1025;
    gSlavegprsLastSent = 1048533;
    gSlavegprsLastReceived = 11048576;
    SetKeyHandler(EntryScrSlaveGPRSCounter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryScrSlaveGPRSCounter, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#else /* __MMI_GPRS_UNIT_TEST__ */ 

    SetKeyHandler(GetSlaveGPRSCountersRequest, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(GetSlaveGPRSCountersRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#endif /* __MMI_GPRS_UNIT_TEST__ */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSlaveGPRSCountLastSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSlaveGPRSCountLastSent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSlaveGPRSCountLastRecieved
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSlaveGPRSCountLastRecieved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSlaveGPRSCountAllSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSlaveGPRSCountAllSent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSlaveGPRSCountAllReceived
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSlaveGPRSCountAllReceived(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightSlaveGPRSCountCounterReset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSlaveGPRSCountCounterReset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSlavegprsTotalSent == 0 &&
        gSlavegprsTotalReceived == 0 &&
        gSlavegprsLastSent ==   0 &&
        gSlavegprsLastReceived == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntryScrSlaveGPRSRecvCounterResetConfirmation, KEY_EVENT_UP);
    }
}

/* micha0202 begin */


/*****************************************************************************
 * FUNCTION
 *  HintSlaveGPRSCountLastSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintSlaveGPRSCountLastSent(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gSlavegprsLastSent);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintSlaveGPRSCountLastRecieved
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintSlaveGPRSCountLastRecieved(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gSlavegprsLastReceived);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintSlaveGPRSCountAllSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintSlaveGPRSCountAllSent(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gSlavegprsTotalSent);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintGPRSCountAllReceived
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintSlaveGPRSCountAllReceived(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gSlavegprsTotalReceived);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetSlaveGPRSCountersRequest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetSlaveGPRSCountersRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    /* micha1020 */
    SetSlaveProtocolEventHandler(GetSlaveGPRSCountersResponse, PRT_MMI_PS_GET_GPRS_DATA_COUNTER_RSP);
    /* format message to send req for get plmn list */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    /* micha1020 */
    Message.oslMsgId = PRT_MMI_PS_GET_GPRS_DATA_COUNTER_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetGPRSCountersResponse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetSlaveGPRSCountersResponse(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__
    mmi_ps_get_gprs_data_counter_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearSlaveProtocolEventHandler(PRT_MMI_PS_GET_GPRS_DATA_COUNTER_RSP);
    localPtr = (mmi_ps_get_gprs_data_counter_rsp_struct*) info;

    if (localPtr->result == MMI_TRUE)
    {
        gSlavegprsTotalSent = localPtr->counter_info.total_tx_data;
        gSlavegprsTotalReceived = localPtr->counter_info.total_rx_data;
        gSlavegprsLastSent = localPtr->counter_info.last_tx_data;
        gSlavegprsLastReceived = localPtr->counter_info.last_rx_data;
    }
    else
    {
        gSlavegprsTotalSent = 0;
        gSlavegprsTotalReceived = 0;
        gSlavegprsLastSent = 0;
        gSlavegprsLastReceived = 0;
    }

    EntryScrSlaveGPRSCounter();
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrGPRSRecvCounterResetConfirmation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSlaveGPRSRecvCounterResetConfirmation(void)
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
        get_string(STR_GPRS_RESET_COUNTER_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* Set the left/right soft key funtions */
    SetLeftSoftkeyFunction(ResetSlaveGPRSCounterReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the exit handler for the current screen */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ResetGPRSCounterReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSlaveGPRSCounterReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_UNIT_TEST__

    gSlavegprsTotalSent = 0;
    gSlavegprsTotalReceived = 0;
    gSlavegprsLastSent = 0;
    gSlavegprsLastReceived = 0;
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_MTPNP_GPRS_COUNTER);

#else /* __MMI_GPRS_UNIT_TEST__ */ 

    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__

    MYQUEUE Message;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    /* micha1020 */
    SetSlaveProtocolEventHandler(ResetSlaveGPRSCounterRsp, PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP);
    /* format message to send req for get plmn list */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    /* micha1020 */
    Message.oslMsgId = PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

#endif /* __MMI_GPRS_FEATURES__ */ 

#endif /* __MMI_GPRS_UNIT_TEST__ */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  ResetGPRSCounterRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSlaveGPRSCounterRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__

    mmi_ps_reset_gprs_data_counter_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearSlaveProtocolEventHandler(PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP);
    localPtr = (mmi_ps_reset_gprs_data_counter_rsp_struct*) info;

    if (localPtr->result == MMI_TRUE)
    {
        gSlavegprsTotalSent = 0;
        gSlavegprsTotalReceived = 0;
        gSlavegprsLastSent = 0;
        gSlavegprsLastReceived = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_CONFIRM_SCREEN);
    return;

#endif /* __MMI_GPRS_FEATURES__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  EntryScrSlaveGPRSCounter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSlaveGPRSCounter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    // U16                  nDispAttribute; /* Stores display attribue */
    U8 *u8GPRSCount[MAX_SUB_MENUS];         /* sms counters for display hint popups */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_MTPNP_GPRS_COUNTER, NULL, EntryScrSlaveGPRSCounter, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_GPRS_COUNTER);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem( MENU_CALL_HISTORY_GPRSCOUNTER ); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* construct hint popups for the menu items */
    ConstructHintsList(MENU_MTPNP_CALL_HISTORY_GPRSCOUNTER, u8GPRSCount);
    /* Display Category52 Screen */
    ShowCategory52Screen(
        STR_GPRS_CAPTION,
        IMG_SCR8056_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        u8GPRSCount,
        0,
        0,
        guiBuffer);
    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#endif /* __MMI_GPRS_FEATURES__ */ 
/* GPRS counter end */
#endif /* __MMI_DUAL_SIM_MASTER__ */


/***********************************************
File name : MTPNP_PFAL_DM_Setup.h
Contents : initial the dual sim setting entry
History : Create by : Zhang Nan, Apr 12, 2007
************************************************/
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
#include "CallsDefs.h"
#include "CommonScreens.h"
#include "wgui_categories_inputsenum.h"
#include "SimDetectionDef.h"
#include "FrameworkStruct.h"
#include "CallManagementStruct.h"
#include "CallBarrng.h"
#include "CallWaiting.h"
#include "CallForwarding.h"
#include "PhoneSetup.h"
#include "NVRAMProt.h"
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
#include "SMSApi.h"
#include "SMSStruct.h"
#include "customer_ps_inc.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
#include "ems.h"
#include "SMSFunc.h"
#include "PhoneBookGprot.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "GlobalMenuItems.h"
#include "MessagesresourceData.h"
#include "CallSetUpEnum.h"
#include "vcard.h"
#include "CallSetUpEnum.h"
#include "wgui_categories_inputs.h"
#include "CallManagementGprot.h"    /* CB Src mark function */
#include "SettingGenum.h"
#include "SettingsGdcl.h"
#include "SecuritySetup.h"
#include "AlarmFrameworkProt.h" /* Enable and Disable Alarm */
#include "BTMMIScrGprots.h" /* BT functions */
#include "IrdaMMIGprots.h"  /* Irda function support */
#include "IrdaMMIScr.h"     /* Irda function support */
#include "CSP.h"
#include "ProfileGprots.h"
#include "SimDetectionGprot.h"

#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_Master_ADN.h"
#include "MTPNP_PFAL_Master_FDN.h"
#include "MTPNP_PFAL_Master_Callhistory.h"
#include "MTPNP_PFAL_Master_CallsCost.h"
#include "MTPNP_PFAL_Network.h"
#include "MTPNP_PFAL_CellBroadcast.h"
#include "MTPNP_PFAL_VoiceMail.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_MessageSetup.h"
#include "MTPNP_PFAL_HelpInfo.h"
#include "MTPNP_PFAL_custom_VEINT.h"
#include "MTPNP_PFAL_Debug.h"

#include "UCMResDef.h"
#include "MTPNP_PFAL_CC_UCM.h"
#include "MTPNP_PFAL_CHV_Verify.h"

#include "ProtocolEvents.h" 

#define DUALSIM_MODESWITCH_TIMEOUT	20000

#ifdef __MMI_BT_SUPPORT__
static pBOOL btNotReady = MMI_FALSE;
static pBOOL btGotRsp = MMI_FALSE;
#endif /* __MMI_BT_SUPPORT__ */ 

typedef struct _phnset_f_mode_req
{
    FuncPtr phnset_flight_mode_req;
    U8 state;
} PHNSETFMODEREQ;

/* only useful when during switch mode */ 
static DUALMODE_SWITCH_STATUS dm_switch_status;

MTPNP_UINT16 g_default_sel_item = 0;

extern const MTPNP_UINT16 gIndexIconsImageList[];
extern MTPNP_UINT8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];

static MTPNP_UINT8 g_slave_lineid_input;
#ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
static MTPNP_UINT8 g_slave_lineinfo[(MAX_PB_NUMBER_LENGTH + 25) * ENCODING_LENGTH];
#else
static MTPNP_UINT8 g_slave_lineinfo[25 * ENCODING_LENGTH];
#endif
extern MTPNP_CHAR g_slave_inputpwdbuffer[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
extern MTPNP_CHAR g_slave_inputNewpinbufferfirsttime[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
extern MTPNP_CHAR g_slave_inputnewpinbuffersecondtime[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
extern MTPNP_UCHAR g_slave_ownername[MAX_LENGTH_OWNER_NUMBER * ENCODING_LENGTH];
extern PHNSET_CNTX g_phnset_cntx;
extern pwr_context_struct g_pwr_context;

extern pBOOL mmi_bootup_get_active_flight_mode(void);
extern S32 mmi_is_redrawing_bk_screens(void);

extern void EntryScrEnterPIN(void);
extern void DualModeSwtichUpdate(void);

/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
static void HighlightDMCallSetting(void);
static void EntryDMCallSetupMain(void);

static void HighlightDMSecurity(void);
static void EntryDMSecurityMain(void);

static void HighlightCard2Pin1Passwd(void);
static void HighlightCard2Pin2Passwd(void);
static void EntryCard2SECSETChangePWOldPWD(void);
static void EntryCard2SECSETChangePWNewPWD(void);
static void EntryCard2SECSETChangePWCfmPWD(void);
static void EntryCard2SECSETPIN2(void);
void EntryCard2SECSETPUK2(void);
static void EntryCard2SECSETPUK2NewPIN2(void);
static void EntryCard2SECSETPUK2ConfirmPIN2(void);
static void ExitCard2SECSETSIMLockPIN1(void);
static void ExitCard2SECSETChangePWOldPWD(void);
static void ExitCard2SECSETChangePWNewPWD(void);
static void ExitCard2SECSETChangePWCfmPWD(void);
static void ExitCard2SECSETPIN2(void);
void ExitCard2SECSETPUK2(void);
static void ExitCard2SECSETNewPIN2(void);
static void ExitCard2SECSETNewPIN2Confirm(void);
static void ValidateCard2NewPin2(void);
static void SendCard2ReqToChangePwd(void);

static void DualModeSwitchStartCallBack(void);
static void DualModeSwitchCompleteCallBack(void);
static void DualModeSwitchFailCallBack(void);

#ifdef __MMI_WLAN_FEATURES__
static void DualModeSwtichUpdateWLAN(void);
#endif /* __MMI_WLAN_FEATURES__ */
#ifdef __MMI_BT_SUPPORT__
static void DualModeSwtichUpdateBT(void);
#endif /* __MMI_BT_SUPPORT__ */
#ifdef __MMI_IRDA_SUPPORT__
static void DualModeSwtichUpdateIRDA(void);
#endif /* __MMI_IRDA_SUPPORT__ */


static void FillDualModeSwitchStruct(E_MTPNP_AD_NVRAM_STATUS src_status, E_MTPNP_AD_NVRAM_STATUS dest_status);

static PHNSETFMODEREQ mmi_phnset_f_mode_req[] = 
{
#ifdef __MMI_WLAN_FEATURES__
    {DualModeSwtichUpdateWLAN, 1},
#endif
#ifdef __MMI_BT_SUPPORT__
    {DualModeSwtichUpdateBT, 1},
#endif
#ifdef __MMI_IRDA_SUPPORT__
    {DualModeSwtichUpdateIRDA, 1},
#endif
    {NULL, 0} /* dummy one, please add callbacks before this entity */
};

/**************************LOCAL*FUNCTION*DECLARE*END*************************/

extern void MTPNP_PFAL_Rearrange_RootScreen(DUALMODE_SWITCH_STATUS *dm_switch);
extern void MTPNP_PFAL_Rearrange_NetworkIcons(DUALMODE_SWITCH_STATUS *dm_switch);
extern void MTPNP_PFAL_Rearrange_SignalIcons(void);

void MTPNP_PFAL_Init(void)
{
    /* initialize status bar */
    MTPNP_PFAL_Show_StatusICON(STATUS_ICON_SIGNAL_STRENGTH);
    MTPNP_PFAL_Show_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH);
    MTPNP_PFAL_Set_Current_Slave_Signal_ID(STATUS_ICON_SLAVE_SIGNAL_STRENGTH);
    /* initialize status bar */

    MTPNP_PFAL_DM_Setup_Init();
    MTPNP_PFAL_PhoneSetting_Init();
    MTPNP_PFAL_CallSetting_Init();
    MTPNP_PFAL_CallHistory_Init();
    MTPNP_PFAL_SecuritySetting_Init();

    MTPNP_PFAL_Network_Init();
    MTPNP_PFAL_InitCellBroadcastApp();
    MTPNP_PFAL_InitVoiceMail();
    MTPNP_PFAL_InitMessageSetup();

    MTPNP_PFAL_Master_SMS_Init();

    MTPNP_PFAL_ADN_Init();
    MTPNP_PFAL_InitFixedDialList();
    MTPNP_PFAL_EntryDialedCallList();
    MTPNP_PFAL_CallsCost_Init();
    MTPNP_PFAL_GPRSCounter_Init();
    MTPNP_PFAL_CC_RegisterInitCB();
    MTPNP_PFAL_CC_InitEntrySelectSendkey();
    MTPNP_PFAL_CC_InitSelectCard();
    MTPNP_PFAL_CC_InitMissNotify();
#if !defined(__SENDKEY2_SUPPORT__) || defined(E8D)
    MTPNP_PFAL_CHIST_InitMixedCallLog();
#endif
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    MTPNP_PFAL_CC_InitCSKSelectCard();
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */

    MTPNP_PFAL_InitCallGroup();
    MTPNP_PFAL_InitOperationState();

}

void MTPNP_PFAL_DM_Setup_Init(void)
{
    /* hilite */
    SetHiliteHandler(MENU_MTPNP_SETTING, HighlightDMSetMain);
    SetHiliteHandler(MENU_MTPNP_DM_SETTING, HighlightStartupModeSetMain);

    SetHiliteHandler(MENU_MTPNP_DM_DUALCARD, HighlightDualCardSel);
    SetHiliteHandler(MENU_MTPNP_DM_CARD1, HighlightOnlyCard1Sel);
    SetHiliteHandler(MENU_MTPNP_DM_CARD2, HighlightOnlyCard2Sel);
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    SetHiliteHandler(MENU_MTPNP_DM_QUERY, HighlightDMQueryModeSel);
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
    SetHiliteHandler(MENU_MTPNP_DM_FLIGHT, HighlightDMFlightModeSel);

    /* help information */
    SetHiliteHandler(MENU_MTPNP_HELPINFO, HightlightShowMTPNPHelpInfo);

    /* hint */
    SetHintHandler(MENU_MTPNP_DM_SETTING, HintStartupModeSet);

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_VERIFY_SIM1, MTPNP_PFAL_Entry_SIM1CHV_Verify);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_VERIFY_SIM2, MTPNP_PFAL_Entry_SIM2CHV_Verify);
}

void MTPNP_PFAL_DM_Query_Init(void)
{
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    SetHiliteHandler(MENU_MTPNP_QUERY_SEL_DUALCARD, HighlightQuerySelDualMode);
    SetHiliteHandler(MENU_MTPNP_QUERY_SEL_CARD1, HighlightQuerySelCard1);
    SetHiliteHandler(MENU_MTPNP_QUERY_SEL_CARD2, HighlightQuerySelCard2);
    SetHiliteHandler(MENU_MTPNP_QUERY_SEL_FLIGHT, HighlightQuerySelFlight);
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
}

void MTPNP_PFAL_PhoneSetting_Init(void)
{
    SetHiliteHandler(MENU_MTPNP_PHONE_SETTING, HighlightCard2PhoneSetting);

    MTPNP_PFAL_MSISDN_Init();
}

void MTPNP_PFAL_CallSetting_Init(void)
{
    /* hilite */
    SetHiliteHandler(MENU_MTPNP_DM_CALL_SETTING, HighlightDMCallSetting);
    SetHiliteHandler(MENU_MTPNP_CALL_SETTING, HighlightSlaveCallSetting);
    SetHiliteHandler(MENU_MTPNP_CALL_ID, HighlightCard2CallID);
    SetHiliteHandler(MENU_MTPNP_CALL_ID_AUTO, HiliteCard2CallIDSetByNwk);
    SetHiliteHandler(MENU_MTPNP_CALL_ID_SHOW_ID, HiliteCard2CallIDShowCid);
    SetHiliteHandler(MENU_MTPNP_CALL_ID_HIDE_ID, HiliteCard2CallIDHideCid);
    SetHiliteHandler(MENU_MTPNP_LINE_SWITCH, HighlightCard2LineSwitch);
    SetHiliteHandler(MENU_MTPNP_CALL_WAIT, HiliteCard2CallWait);
    SetHiliteHandler(MENU_MTPNP_CALL_FORWARD, HiliteCard2CallForward);
    SetHiliteHandler(MENU_MTPNP_CALL_BARRING, HighlightCard2Barring);

    /* hint */
    SetHintHandler(MENU_MTPNP_CALL_ID, HintCard2CallID);
    SetHintHandler(MENU_MTPNP_LINE_SWITCH, HintCard2LineSwitch);
}

void MTPNP_PFAL_CallHistory_Init(void)
{
    /* hilite */

    /* hint */
}

void MTPNP_PFAL_SecuritySetting_Init(void)
{
    /* hilite */
    SetHiliteHandler(MENU_MTPNP_DM_SECURITY_SETTING, HighlightDMSecurity);
    SetHiliteHandler(MENU_MTPNP_SECURITY_SETTING, HighlightCard2Security);
    SetHiliteHandler(MENU_MTPNP_CHANGE_PASSWORD, HighlightCard2ChangePassword);
    SetHiliteHandler(MENU_MTPNP_SIM_LOCK, HighlightCard2SIMLock);
    SetHiliteHandler(MENU_MTPNP_CP_PIN1, HighlightCard2Pin1Passwd);
    SetHiliteHandler(MENU_MTPNP_CP_PIN2, HighlightCard2Pin2Passwd);

    /* hint */
    SetHintHandler(MENU_MTPNP_SIM_LOCK, HintCard2SIMLock);

    SetSlaveProtocolEventHandler(MTPNP_PFAL_ATCmd_Update_Chv, MSG_ID_MMI_SMU_VERIFY_PIN_RESULT_IND);
}

void MTPNP_PFAL_Goback_2_History(void)
{
    GoBacknHistory(1);
}

/* dual mode startup setting */
void EntryDMSetScreen(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
    MTPNP_UINT16 nDispAttribute;        /* Stores display attribue */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_DMSETUP, MTPNP_NULL, EntryDMSetScreen, MTPNP_NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_DMSETUP);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_SETTING);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_MTPNP_SETTING);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_SETTING, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_SETTING);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_MTPNP_SETTING, ItemType);

    ShowCategory52Screen(STRING_MTPNP_SETTING, MAIN_MENU_TITLE_DM_SETTINGS_ICON,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, ItemType, 0, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightDMSetMain(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryDMSetScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryDMSetScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

void EntryStartupModeSetScreen(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_INT nNumofItem;       /* Stores no of children in the submenu */
    MTPNP_UINT16 nDispAttribute;        /* Stores display attribue */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];
    MTPNP_UINT8 *subDGSetMenuDataPtrs[5];
    MTPNP_UINT i = 0;
    MTPNP_INT8 index = -1;
    MTPNP_UINT16 default_value = 0;
    E_MTPNP_AD_NVRAM_STATUS status = MTPNP_AD_NVRAM_DUALCARD;

    if (MTPNP_AD_Is_During_Mode_Switch())
    {
        return;
    }
    
    /* judge whether enable switch mode */
#ifndef __MMI_DUAL_SIM_SINGLE_CALL__
    if (!MTPNP_AD_Is_Enable_Mode_Switch())
#else
    if (!MTPNP_AD_Is_Enable_Mode_Switch() 
#ifdef __MTK_TARGET__
        || !mmi_bootup_is_power_on_mode_change_finish()
#endif
        )
#endif
    {
        kal_prompt_trace(MOD_MMI, "mmi_bootup_is_power_on_mode_change_finish() return %d",
            mmi_bootup_is_power_on_mode_change_finish());
        
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_DM_DISABLESWTH),
                     IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
        return;
    }

    /* update the switch table */
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    nNumofItem = MTPNP_AD_Update_Switch_Table();
#else /* __DM_PWR_ON_QUERY_SUPPORT__ */
    nNumofItem = MTPNP_AD_Update_Switch_Table() - 1;
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */

    status = MTPNP_AD_Get_Startup_Mode();

    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_DM_DUALCARD);
    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_DM_CARD1);
    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_DM_CARD2);
    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_DM_FLIGHT);
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_DM_QUERY);
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */

    for (i = 0; i < 5; i++)
    {
        if (!MTPNP_AD_Get_Mode_Item(i, &index))
        {
            if (status == i)
            {
                default_value = index;
            }

            switch (i)
            {
            case MTPNP_AD_NVRAM_DUALCARD:
                subDGSetMenuDataPtrs[index] = (MTPNP_UCHAR *) GetString(STRING_MTPNP_DM_DUALCARD);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_DM_DUALCARD);
                break;
            case MTPNP_AD_NVRAM_CARD1:
                subDGSetMenuDataPtrs[index] = (MTPNP_UCHAR *) GetString(STRING_MTPNP_DM_CARD1);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_DM_CARD1);
                break;
            case MTPNP_AD_NVRAM_CARD2:
                subDGSetMenuDataPtrs[index] = (MTPNP_UCHAR *) GetString(STRING_MTPNP_DM_CARD2);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_DM_CARD2);
                break;
            case MTPNP_AD_NVRAM_FLIGHT:
                subDGSetMenuDataPtrs[index] = (MTPNP_UCHAR *) GetString(STRING_MTPNP_DM_FLIGHT);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_DM_FLIGHT);
                break;
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
            case MTPNP_AD_NVRAM_QUERY:
                subDGSetMenuDataPtrs[index] = (MTPNP_UCHAR *) GetString(STRING_MTPNP_DM_QUERY);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_DM_QUERY);
                break;
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
            default:
                break;
            }
        }
    }

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_STARTUPMODESET, NULL, EntryStartupModeSetScreen, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_STARTUPMODESET);

    /* 3. Retrieve no of child of menu item to be displayed */
#if 0
/* under construction !*/
#endif

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_MTPNP_DM_SETTING);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_DM_SETTING, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_DM_SETTING);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_MTPNP_DM_SETTING, ItemType);

    ShowCategory36Screen(STRING_MTPNP_DM_SETTING, GetRootTitleIcon(MENU_MTPNP_DM_SETTING),
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, (MTPNP_UINT8 **) subDGSetMenuDataPtrs, default_value, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightStartupModeSetMain(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /*3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryStartupModeSetScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryStartupModeSetScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /*4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void HintStartupModeSet(MTPNP_UINT16 index)
{
    E_MTPNP_AD_NVRAM_STATUS status;

    MTPNP_AD_Update_Switch_Table();

    status = MTPNP_AD_Get_Startup_Mode();

    switch (status)
    {
    case MTPNP_AD_NVRAM_DUALCARD:
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_DM_DUALCARD));
        break;
    case MTPNP_AD_NVRAM_CARD1:
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STRING_MTPNP_DM_CARD1));
        break;
    case MTPNP_AD_NVRAM_CARD2:
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STRING_MTPNP_DM_CARD2));
        break;
    case MTPNP_AD_NVRAM_FLIGHT:
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_DM_FLIGHT));
        break;
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    case MTPNP_AD_NVRAM_QUERY:
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STRING_MTPNP_DM_QUERY));
        break;
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
    default:
        break;
    }
}

void HighlightDualCardSel(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(DualCardSel, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightOnlyCard1Sel(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(OnlyCard1Sel, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightOnlyCard2Sel(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(OnlyCard2Sel, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __DM_PWR_ON_QUERY_SUPPORT__
void HighlightDMQueryModeSel(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(DMQueryModeSel, KEY_EVENT_UP);
    SetKeyHandler(DMQueryModeSel, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */

void HighlightDMFlightModeSel(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(DMFlightModeSel, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void DualCardSel(void)
{
    E_MTPNP_AD_NVRAM_STATUS curr_dm_setting;

    curr_dm_setting = MTPNP_AD_Get_Startup_Mode();

    if (curr_dm_setting == MTPNP_AD_NVRAM_DUALCARD)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SWITCH_SAME_MODE),
                     IMG_GLOBAL_INFO, 0, ST_NOTIFYDURATION, WARNING_TONE);
        return;
    }

    FillDualModeSwitchStruct(curr_dm_setting, MTPNP_AD_NVRAM_DUALCARD);

    /* set temp flight dest status */
    MTPNP_AD_Set_DM_Switch_Tmp(MTPNP_AD_NVRAM_DUALCARD);

    /* entry switch progress screen */
    EntryDualModeSwitchProgress();

    /* Switch Mode to DualCard */
    MTPNP_PFAL_Switch_Mode(curr_dm_setting);
    
}


void OnlyCard1Sel(void)
{
    E_MTPNP_AD_NVRAM_STATUS curr_dm_setting;

    curr_dm_setting = MTPNP_AD_Get_Startup_Mode();

    if (curr_dm_setting == MTPNP_AD_NVRAM_CARD1)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SWITCH_SAME_MODE),
                     IMG_GLOBAL_INFO, 0, ST_NOTIFYDURATION, WARNING_TONE);
        return;
    }

    FillDualModeSwitchStruct(curr_dm_setting, MTPNP_AD_NVRAM_CARD1);

    MTPNP_AD_Set_DM_Switch_Tmp(MTPNP_AD_NVRAM_CARD1);

    /* entry switch progress screen */
    EntryDualModeSwitchProgress();

    MTPNP_PFAL_Switch_Mode(curr_dm_setting);
}

void OnlyCard2Sel(void)
{
    E_MTPNP_AD_NVRAM_STATUS curr_dm_setting;

    curr_dm_setting = MTPNP_AD_Get_Startup_Mode();

    if (curr_dm_setting == MTPNP_AD_NVRAM_CARD2)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SWITCH_SAME_MODE),
                     IMG_GLOBAL_INFO, 0, ST_NOTIFYDURATION, WARNING_TONE);
        return;
    }

    FillDualModeSwitchStruct(curr_dm_setting, MTPNP_AD_NVRAM_CARD2);

    MTPNP_AD_Set_DM_Switch_Tmp(MTPNP_AD_NVRAM_CARD2);

    /* entry switch progress screen */
    EntryDualModeSwitchProgress();

    MTPNP_PFAL_Switch_Mode(curr_dm_setting);
}

#ifdef __DM_PWR_ON_QUERY_SUPPORT__
void DMQueryModeSel(void)
{
    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_QUERY)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SWITCH_SAME_MODE),
                     IMG_GLOBAL_INFO, 0, ST_NOTIFYDURATION, WARNING_TONE);
        return;
    }

    MTPNP_AD_Set_DM_Switch_Tmp(MTPNP_AD_NVRAM_QUERY);

    /* direct update the nvram value and not change the dual mode status */
    DualModeSwitchComplete();
}
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */

void DMFlightModeSel(void)
{
    E_MTPNP_AD_NVRAM_STATUS curr_dm_setting;

    curr_dm_setting = MTPNP_AD_Get_Startup_Mode();

    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SWITCH_SAME_MODE),
                     IMG_GLOBAL_INFO, 0, ST_NOTIFYDURATION, WARNING_TONE);
        return;
    }

    FillDualModeSwitchStruct(curr_dm_setting, MTPNP_AD_NVRAM_FLIGHT);

    MTPNP_AD_Set_DM_Switch_Tmp(MTPNP_AD_NVRAM_FLIGHT);

    /* entry switch progress screen */
    EntryDualModeSwitchProgress();

    MTPNP_PFAL_Switch_Mode(curr_dm_setting);
}

void CancelDMSwitch(void)
{
    ExitDisplayPopupConfirm();

    GoBackHistory();
}

U8 DualModeIsSwitching(void)
{
    if (MTPNP_AD_Is_During_Mode_Switch() == MTPNP_TRUE)
    {
        return 1;
    }

    return 0;
}

void EntryDualModeSwitchProgressing(void)
{
    EntryNewScreen(SCR_DM_SWITCH_PROGRESS, NULL, EntryDualModeSwitchProgressing, NULL);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    ShowCategory66Screen(STRING_MTPNP_DM_SETTING,
                         GetRootTitleIcon(MENU_MTPNP_DM_SETTING), 0, 0, 0, 0,
                         (MTPNP_UINT8 *) GetString(STRING_MTPNP_DM_SWITCH), IMG_DM_SWITCH_PROGRESS, NULL);
}

void EntryDualModeSwitchProgressInIdle(void)
{
    EntryDualModeSwitchProgressing();
}

void EntryDualModeSwitchProgress(void)
{
    MTPNP_AD_During_Mode_Switch();

    EntryDualModeSwitchProgressing();

    DualModeSwitchStartCallBack();

    /*
    MTPNP_PFAL_Stop_Timer(MTPNP_MODESWITCH_TIMER);
    MTPNP_PFAL_Start_Timer(MTPNP_MODESWITCH_TIMER, DUALSIM_MODESWITCH_TIMEOUT, DualModeSwitchFailed);
    */
}

static void Terminate_Mode_Switch(void)
{
    if (GetActiveScreenId() != SCR_FLIGHT_MODE_PROGRESS)
    {
        DeleteScreenIfPresent(SCR_DM_SWITCH_PROGRESS);      /* progressing */
        DeleteScreenIfPresent(SCR_STARTUPMODESET);          /* mode switch menu */
        DeleteScreenIfPresent(SCR9003_INITIALSETUP);        /* phone setup */
        DeleteScreenIfPresent(SCR9000_SETTINGS);            /* setting */
        DeleteScreenIfPresent(MAIN_MENU_SCREENID);          /* main menu */
        DeleteScreenIfPresent(SCR_SIM_OPTION);              /* SIM option menu */
    }
    else
    {
        if (IsScreenPresent(SCR_SIM_INSERTION))
        {
            DeleteUptoScrID(SCR_SIM_INSERTION);
        }
        else if (IsScreenPresent(SCR_SIM_BLOCK))
        {
            DeleteUptoScrID(SCR_SIM_BLOCK);
        }
        else
        {
            DeleteUptoScrID(IDLE_SCREEN_ID);
        }
    }

    kal_prompt_trace(MOD_MMI, "Terminate_Mode_Switch: AlmEnableExpiryHandler");
    AlmEnableExpiryHandler();
    
    MTPNP_AD_terminate_Mode_Switch();
}

void DualModeSwitchCompleteUpdateStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "DualModeSwitchCompleteUpdateStatus()");

    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
        if (mmi_phnset_f_mode_req[i].state)
        {
            mmi_phnset_f_mode_req[i].state = 0;
            (*mmi_phnset_f_mode_req[i].phnset_flight_mode_req)();
            return;
        }
    }
    
#ifdef __MMI_BT_SUPPORT__
    /* if BT not response */
    if (btGotRsp)
    {
        return;
    }

    kal_prompt_trace(MOD_MMI, "Stop BT timer");

    StopTimer(MTPNP_SWITCHMODE_DEACTIVATE_BT_TIMER);
#endif /* __MMI_BT_SUPPORT__  */
    
    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
        mmi_phnset_f_mode_req[i].state = 1;
    }

#ifdef __MMI_BT_SUPPORT__
    btGotRsp = MMI_TRUE;
#endif 

    kal_prompt_trace(MOD_MMI, "End DualModeSwitchCompleteUpdateStatus()");

    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    
    Terminate_Mode_Switch();
}


void DualModeSwitchComplete(void)
{
/*
    MTPNP_PFAL_Stop_Timer(MTPNP_MODESWITCH_TIMER);
*/
    MTPNP_AD_Update_DM_Setup();
    MTPNP_PFAL_Update_FlightMode_Status();

    if ((MTPNP_AD_Get_Status() & MTPNP_AD_CARD2) == MTPNP_AD_CARD2)
    {
        /* slave is pwr on, should refresh slave plmn */
        MTPNP_PFAL_Refresh_Card2PLMN();
    }

    /* complete callback shall be executed before MTPNP rearrange status bar and menu items */
    DualModeSwitchCompleteCallBack();

    MTPNP_PFAL_Rearrange_StatusBar();
    MTPNP_PFAL_Rearrange_MenuItem();
    MTPNP_PFAL_Rearrange_SignalIcons();

    kal_prompt_trace(MOD_MMI, "DualModeSwitchComplete : DualModeSwitchCompleteUpdateStatus");
    DualModeSwitchCompleteUpdateStatus();

}

void DualModeSwitchFailed(void)
{
/*
    MTPNP_PFAL_Stop_Timer(MTPNP_MODESWITCH_TIMER);
    MTPNP_AD_Update_DM_Setup();
   
    MTPNP_PFAL_Update_FlightMode_Status();

    MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
    MTPNP_PFAL_Rearrange_StatusBar();
    MTPNP_PFAL_Rearrange_MenuItem();
*/ 

    DualModeSwitchFailCallBack();

    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, ST_NOTIFYDURATION, ERROR_TONE);

    Terminate_Mode_Switch();
}

E_MTPNP_AD_MODE_SWITCH_STATE MTPNP_PFAL_Switch_Mode(E_MTPNP_AD_NVRAM_STATUS curr_status)
{
    E_MTPNP_AD_MODE_SWITCH_STATE result = MTPNP_AD_SWITCH_FAILED;
    E_MTPNP_AD_NVRAM_STATUS switch_status_tmp;

#ifndef __MTK_TARGET__
    DualModeSwitchComplete();
    return MTPNP_AD_SWITCH_SUCCEED;
#endif

    switch_status_tmp = MTPNP_AD_Get_DM_Switch_Tmp();

    switch (switch_status_tmp)
    {
    case MTPNP_AD_NVRAM_DUALCARD:
        result = MTPNP_AD_Switch_To_DualCard(curr_status);
        break;
    case MTPNP_AD_NVRAM_CARD1:
        result = MTPNP_AD_Switch_To_Card1(curr_status);
        break;
    case MTPNP_AD_NVRAM_CARD2:
        result = MTPNP_AD_Switch_To_Card2(curr_status);
        break;
    case MTPNP_AD_NVRAM_FLIGHT:
        result = MTPNP_AD_Switch_To_FlightMode(curr_status);
        break;
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    case MTPNP_AD_NVRAM_QUERY:
        result = MTPNP_AD_SWITCH_SUCCEED;
        break;
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
    case MTPNP_AD_NVRAM_NONE:
    default:
        break;
    }

    return result;
}

void MTPNP_PFAL_Update_FlightMode_Status(void)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
}

static void FillDualModeSwitchStruct(E_MTPNP_AD_NVRAM_STATUS src_status, E_MTPNP_AD_NVRAM_STATUS dest_status)
{    
    kal_prompt_trace(MOD_MMI, "FillDualModeSwitchStruct");
    
    if (MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT)			/* Not Insert SIM1 */
    {
        if (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT)		/* Not Insert SIM2 */
        {
            dm_switch_status.sim_insert = MTPNP_NO_SIM_INSERTED;
        }
        else	/* Insert SIM2 */
        {
            dm_switch_status.sim_insert = MTPNP_ONLY_SIM2_INSERTED;
        }
    }
    else	/* Insert SIM1 */
    {
        if (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT)		/* Not Insert SIM2 */
        {
            dm_switch_status.sim_insert = MTPNP_ONLY_SIM1_INSERTED;
        }
        else	/* Insert SIM2 */
        {
            dm_switch_status.sim_insert = MTPNP_DUAL_SIM_INSERTED;
        }
	}

    switch(src_status)
    {
    case MTPNP_AD_NVRAM_DUALCARD:
        dm_switch_status.src_status = MTPNP_DAUL_SIM_CONFIG;
    	break;

    case MTPNP_AD_NVRAM_CARD1:
        dm_switch_status.src_status = MTPNP_SIM1_ONLY_CONFIG;
    	break;

    case MTPNP_AD_NVRAM_CARD2:
        dm_switch_status.src_status = MTPNP_SIM2_ONLY_CONFIG;
        break;

    case MTPNP_AD_NVRAM_FLIGHT:
        dm_switch_status.src_status = MTPNP_FLIGHTMODE_CONFIG;
        break;

    default:
        MMI_ASSERT(0);
        break;
    }

    switch(dest_status)
    {
    case MTPNP_AD_NVRAM_DUALCARD:
        dm_switch_status.dest_status = MTPNP_DAUL_SIM_CONFIG;
        break;
        
    case MTPNP_AD_NVRAM_CARD1:
        dm_switch_status.dest_status = MTPNP_SIM1_ONLY_CONFIG;
        break;
        
    case MTPNP_AD_NVRAM_CARD2:
        dm_switch_status.dest_status = MTPNP_SIM2_ONLY_CONFIG;
        break;
        
    case MTPNP_AD_NVRAM_FLIGHT:
        dm_switch_status.dest_status = MTPNP_FLIGHTMODE_CONFIG;
        break;
        
    default:
        MMI_ASSERT(0);
        break;
    }

    kal_prompt_trace(MOD_MMI, "sim_insert=%d,src_status=%d,dest_status=%d",
        dm_switch_status.sim_insert, dm_switch_status.src_status, dm_switch_status.dest_status);

}


void DualModeSwitchUpdateMenuItem(void)
{
    if ((dm_switch_status.dest_status != MTPNP_FLIGHTMODE_CONFIG) && (dm_switch_status.src_status == MTPNP_FLIGHTMODE_CONFIG))
    {
        kal_prompt_trace(MOD_MMI, "flight mode -> normal mode");
#ifdef __MMI_BT_SUPPORT__                
        kal_prompt_trace(MOD_MMI, "flight mode -> normal mode : unhide MENU_CONN_BT_MAIN");
        mmi_frm_unhide_menu_item(MENU_CONN_BT_MAIN);
#endif /* __MMI_BT_SUPPORT__ */
#ifdef __MMI_IRDA_SUPPORT__
        kal_prompt_trace(MOD_MMI, "flight mode -> normal mode : unhide MENU_CONN_IRDA_MAIN");
        mmi_frm_unhide_menu_item(MENU_CONN_IRDA_MAIN);
#endif /* __MMI_IRDA_SUPPORT__ */
    }
    else if ((dm_switch_status.dest_status == MTPNP_FLIGHTMODE_CONFIG) && (dm_switch_status.src_status != MTPNP_FLIGHTMODE_CONFIG))
    {
        kal_prompt_trace(MOD_MMI, "normal mode -> flight mode");
#ifdef __MMI_BT_SUPPORT__                
        kal_prompt_trace(MOD_MMI, "flight mode -> normal mode : hide MENU_CONN_BT_MAIN");
        mmi_frm_hide_menu_item(MENU_CONN_BT_MAIN);
#endif /* __MMI_BT_SUPPORT__ */
#ifdef __MMI_IRDA_SUPPORT__
        kal_prompt_trace(MOD_MMI, "flight mode -> normal mode : hide MENU_CONN_IRDA_MAIN");
        mmi_frm_hide_menu_item(MENU_CONN_IRDA_MAIN);
#endif /* __MMI_IRDA_SUPPORT__ */
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "sim_insert=%d,src_status=%d,dest_status=%d",
            dm_switch_status.sim_insert, dm_switch_status.src_status, dm_switch_status.dest_status);
    }
}



/* please add application's function in functions behind */
static void DualModeSwitchStartCallBack(void)
{
#if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IRDA_SUPPORT__)
    U8 i = 0;
#endif
    
    kal_prompt_trace(MOD_MMI, "DualModeSwitchStartCallBack");
    kal_prompt_trace(MOD_MMI, "sim_insert=%d,src_status=%d,dest_status=%d",
        dm_switch_status.sim_insert, dm_switch_status.src_status, dm_switch_status.dest_status);

    AlmDisableExpiryHandler();

#ifdef __MMI_BT_SUPPORT__
    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
        if (mmi_phnset_f_mode_req[i].phnset_flight_mode_req == DualModeSwtichUpdateBT)
        {
            mmi_phnset_f_mode_req[i].state = 1;
            break;
        }
    }
#endif /* __MMI_BT_SUPPORT__ */
    
#ifdef __MMI_IRDA_SUPPORT__
    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
        if (mmi_phnset_f_mode_req[i].phnset_flight_mode_req == DualModeSwtichUpdateIRDA)
        {
            mmi_phnset_f_mode_req[i].state = 1;
            break;
        }
    }
#endif /* __MMI_IRDA_SUPPORT__ */

}

static void DualModeSwitchCompleteCallBack(void)
{
    kal_prompt_trace(MOD_MMI, "DualModeSwitchCompleteCallBack");
    kal_prompt_trace(MOD_MMI, "sim_insert=%d,src_status=%d,dest_status=%d",
        dm_switch_status.sim_insert, dm_switch_status.src_status, dm_switch_status.dest_status);

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    kal_prompt_trace(MOD_MMI, "call mmi_idle_notify_dual_sim_status_to_wap");
    mmi_idle_notify_dual_sim_status_to_wap();
#endif   /* __MMI_DUAL_SIM_SINGLE_CALL__ */ 

    kal_prompt_trace(MOD_MMI, "call MTPNP_PFAL_Rearrange_RootScreen");
    MTPNP_PFAL_Rearrange_RootScreen(&dm_switch_status);
    
    kal_prompt_trace(MOD_MMI, "call MTPNP_PFAL_Rearrange_NetworkIcons");
    MTPNP_PFAL_Rearrange_NetworkIcons(&dm_switch_status);

    kal_prompt_trace(MOD_MMI, "call DualModeSwitchUpdateMenuItem");
    DualModeSwitchUpdateMenuItem();
}

static void DualModeSwitchFailCallBack(void)
{
    kal_prompt_trace(MOD_MMI, "DualModeSwitchFailCallBack");
    kal_prompt_trace(MOD_MMI, "sim_insert=%d,src_status=%d,dest_status=%d",
        dm_switch_status.sim_insert, dm_switch_status.src_status, dm_switch_status.dest_status);
}
/* END please add application's function in functions behind */


#ifdef __MMI_BT_SUPPORT__
static void DualModeSwitchUpdateBTTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "DualModeSwitchUpdateBTTimeout");
    
    DualModeSwitchCompleteUpdateStatus();
}

static void DualModeSwtichUpdateBT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 btSimPresent;
    U8 btChipPresent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btSimPresent = 1; /* always turn on */
    
#ifdef __MMI_BT_SUPPORT__
    btChipPresent = !btNotReady;
#else
    btChipPresent = 1;
#endif

    kal_prompt_trace(MOD_MMI, "DualModeSwtichUpdateBT()");

    if (btSimPresent && btChipPresent)
    {        
        btGotRsp = MMI_FALSE;

		kal_prompt_trace(MOD_MMI, "DualModeSwtichUpdateBT Start Timer");
				
        StartTimer(MTPNP_SWITCHMODE_DEACTIVATE_BT_TIMER, 40000, DualModeSwitchUpdateBTTimeout);
        
        /* current status not flight mode */
        if ((dm_switch_status.dest_status != MTPNP_FLIGHTMODE_CONFIG) && (dm_switch_status.src_status == MTPNP_FLIGHTMODE_CONFIG))
        {
            kal_prompt_trace(MOD_MMI, "call mmi_bt_reset_hw_on");
            mmi_bt_reset_hw_on();
        }
        else if ((dm_switch_status.dest_status == MTPNP_FLIGHTMODE_CONFIG) && (dm_switch_status.src_status != MTPNP_FLIGHTMODE_CONFIG))
        {
            kal_prompt_trace(MOD_MMI, "call mmi_bt_reset_hw_off");
            mmi_bt_reset_hw_off();
        }
        else
        {
            kal_prompt_trace(MOD_MMI, "DualModeSwtichUpdateBT() : DualModeSwitchCompleteUpdateStatus -- 1");
            DualModeSwitchCompleteUpdateStatus();
        }
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "DualModeSwtichUpdateBT() : DualModeSwitchCompleteUpdateStatus -- 2");
        DualModeSwitchCompleteUpdateStatus();
    }

}
#endif /* __MMI_BT_SUPPORT__ */


#ifdef __MMI_IRDA_SUPPORT__
static void DualModeSwtichUpdateIRDA(void)
{
    kal_prompt_trace(MOD_MMI, "call DualModeSwtichUpdateIRDA");

    if (MMI_IRDASCR_CNTX(irda_state) != MMIR_SCR_IRCLOSE && (dm_switch_status.dest_status == MTPNP_FLIGHTMODE_CONFIG))
    {
        if (mmi_irda_is_ircomm_active() == MMI_TRUE)
        {
            mmi_irda_ircomm_disconnect_request();
        }

        mmi_irda_exec_close_menu();
    }

    kal_prompt_trace(MOD_MMI, "DualModeSwtichUpdateIRDA() : DualModeSwitchCompleteUpdateStatus");
    DualModeSwitchCompleteUpdateStatus();
}
#endif /* __MMI_IRDA_SUPPORT__ */

#ifdef __MMI_WLAN_FEATURES__
void DualModeSwtichUpdateWLAN(void)
{
    kal_prompt_trace(MOD_MMI, "call DualModeSwtichUpdateWLAN");

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    DualModeSwitchCompleteUpdateStatus();
}
#endif /* __MMI_WLAN_FEATURES__ */

void HighlightQuerySelDualMode(void)
{
    SetLeftSoftkeyFunction(SelectDualCard, KEY_EVENT_UP);
}

void HighlightQuerySelCard1(void)
{
    SetLeftSoftkeyFunction(SelectCard1, KEY_EVENT_UP);
}

void HighlightQuerySelCard2(void)
{
    SetLeftSoftkeyFunction(SelectCard2, KEY_EVENT_UP);
}

void HighlightQuerySelFlight(void)
{
    SetLeftSoftkeyFunction(SelectFlightMode, KEY_EVENT_UP);
}

void SelectDualCard(void)
{
    MTPNP_PFAL_Exit_QueryScreen();

#if 0
/* under construction !*/
#endif

    if (MTPNP_AD_Get_PowerOn_Mode() == MTPNP_AD_POWERON_KEYPAD)
    {
        MTPNP_AD_Query_Select_DualCard_Startup();
    }
}

void SelectCard1(void)
{
    MTPNP_PFAL_Exit_QueryScreen();

#if 0
/* under construction !*/
#endif

    if (MTPNP_AD_Get_PowerOn_Mode() == MTPNP_AD_POWERON_KEYPAD)
    {
        MTPNP_AD_Query_Select_Card1_Startup();
    }
}

void SelectCard2(void)
{
    MTPNP_PFAL_Exit_QueryScreen();

#if 0
/* under construction !*/
#endif

    if (MTPNP_AD_Get_PowerOn_Mode() == MTPNP_AD_POWERON_KEYPAD)
    {
        MTPNP_AD_Query_Select_Card2_Startup();
    }
}

void SelectFlightMode(void)
{
    MTPNP_PFAL_Exit_QueryScreen();

#if 0
/* under construction !*/
#endif

    if (MTPNP_AD_Get_PowerOn_Mode() == MTPNP_AD_POWERON_KEYPAD)
    {
        MTPNP_AD_Query_Select_FlightMode_Startup();
    }
}

void MTPNP_PFAL_Entry_PowerOn_Query_Screen(void)
{
#ifdef __DM_PWR_ON_QUERY_SUPPORT__
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];
    MTPNP_UINT8 *subDGSetMenuDataPtrs[4];
    MTPNP_AD_FuncPtr default_func = MTPNP_NULL;
    MTPNP_UINT8 first_active = 0;
    MTPNP_UINT i = 0;
    MTPNP_INT8 index = -1;

    MTPNP_AD_PowerOn_Query_Screen_Need_Duration();
    g_default_sel_item = 0;

    ClearAllKeyHandler();

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_DM_QUERY, MTPNP_NULL, MTPNP_PFAL_Entry_PowerOn_Query_Screen, MTPNP_NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_DM_QUERY);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
#if 0
/* under construction !*/
#endif
    nNumofItem = MTPNP_AD_Update_Sel_Table();

    /* 4. Get attribute of menu to be displayed */
#if 0
/* under construction !*/
#endif

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceStringIds_Ext(MENU_MTPNP_QUERY, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_QUERY);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_MTPNP_QUERY, ItemType);

    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_QUERY_SEL_DUALCARD);
    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_QUERY_SEL_CARD1);
    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_QUERY_SEL_CARD2);
    MTPNP_PFAL_Hide_Menu(MENU_MTPNP_QUERY_SEL_FLIGHT);

    for (i = 0; i < 4; i++)
    {
        if (!MTPNP_AD_Get_Sel_Item(i, &index))
        {
            switch (i)
            {
            case MTPNP_AD_NVRAM_DUALCARD:
                subDGSetMenuDataPtrs[index] = (MTPNP_UINT8 *) GetString(STRING_MTPNP_DM_DUALCARD);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_QUERY_SEL_DUALCARD);
                if (first_active == 0)
                {
                    default_func = (MTPNP_AD_FuncPtr)SelectDualCard;
                }
                break;
            case MTPNP_AD_NVRAM_CARD1:
                subDGSetMenuDataPtrs[index] = (MTPNP_UINT8 *) GetString(STRING_MTPNP_DM_CARD1);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_QUERY_SEL_CARD1);
                if (first_active == 0)
                {
                    default_func = (MTPNP_AD_FuncPtr)SelectCard1;
                }
                break;
            case MTPNP_AD_NVRAM_CARD2:
                subDGSetMenuDataPtrs[index] = (MTPNP_UINT8 *) GetString(STRING_MTPNP_DM_CARD2);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_QUERY_SEL_CARD2);
                if (first_active == 0)
                {
                    default_func = (MTPNP_AD_FuncPtr)SelectCard2;
                }
                break;
            case MTPNP_AD_NVRAM_FLIGHT:
                subDGSetMenuDataPtrs[index] = (MTPNP_UINT8 *) GetString(STRING_MTPNP_DM_FLIGHT);
                MTPNP_PFAL_Show_Menu(MENU_MTPNP_QUERY_SEL_FLIGHT);
                if (first_active == 0)
                {
                    default_func = (MTPNP_AD_FuncPtr)SelectFlightMode;
                }
                break;
            default:
                break;
            }

            first_active++;
        }
    }

    MTPNP_PFAL_Assert(default_func != MTPNP_NULL, __FILE__, __LINE__);
    
    ShowCategory363Screen(STRING_MTPNP_SEL_POWERMODE, MAIN_MENU_TITLE_DM_SETTINGS_ICON,
                               STR_GLOBAL_OK, IMG_GLOBAL_OK,
                               MTPNP_NULL, MTPNP_NULL,
                               nNumofItem, (MTPNP_UINT8 **) subDGSetMenuDataPtrs, g_default_sel_item,
                           5, default_func, guiBuffer);
    
    playRequestedTone(WARNING_TONE);
#else /* __DM_PWR_ON_QUERY_SUPPORT__ */
    DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_DM_ERROR_MODE),
                 IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
#endif /* __DM_PWR_ON_QUERY_SUPPORT__ */
}

void MTPNP_PFAL_Exit_QueryScreen(void)
{
    if (MTPNP_AD_PowerOn_Query_Screen_Is_Need_Duration())
    {
        wgui_cat363_clear_callback();
        stopRequestedTone(WARNING_TONE);
        MTPNP_AD_PowerOn_Query_Screen_UnNeed_Duration();
    }
}

/* dual mode startup setting */

/* the card2 call setting */
static void HighlightDMCallSetting(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(EntryDMCallSetupMain, KEY_EVENT_UP);
    SetKeyHandler(EntryDMCallSetupMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void EntryDMCallSetupMain(void)
{
    ASSERT(0);
}

void HighlightSlaveCallSetting(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /*3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCard2CallSetupMain, KEY_EVENT_UP);

    SetKeyHandler(EntryCard2CallSetupMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /*4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntryCard2CallSetupMain(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];

    mmi_cphs_rearrange_call_main(SIM2);

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_SLAVECALLSETTING, NULL, EntryCard2CallSetupMain, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_SLAVECALLSETTING);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_CALL_SETTING);

    /* 4. Get attribute of menu to be displayed */
    /*nDispAttribute = GetDispAttributeOfItem(MENU_MTPNP_CALL_SETTING); */

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_CALL_SETTING, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_CALL_SETTING);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_MTPNP_CALL_SETTING, ItemType);

    ShowCategory52Screen(
                         STRING_MTPNP_CALL_SETTING,
                         GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, ItemType, 0, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightCard2CallID(void)
{
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /* set the left/right soft key functions handlers */

    SetLeftSoftkeyFunction(EntryCard2SetCallIDMain, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2SetCallIDMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntryCard2SetCallIDMain(void)
{
    MTPNP_UINT8 card2_callid_status;
    MTPNP_UINT16 nNumofItem;
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 index = 0;
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];

    card2_callid_status = MTPNP_AD_Get_Card2_Caller_ID_Status();

    switch (card2_callid_status)
    {
    case MTPNP_LOCAL_NUMBER_DETERMINED_BY_NETWORK:
        index = 0;
        break;
    case MTPNP_LOCAL_NUMBER_HIDE:
        index = 1;
        break;
    case MTPNP_LOCAL_NUMBER_SEND:
        index = 2;
        break;
    default:
        break;
    }

    EntryNewScreen(SCR_CARD2_CALLER_ID_MAIN, NULL, EntryCard2SetCallIDMain, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_CALLER_ID_MAIN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_CALL_ID);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU_CALLER_ID); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_CALL_ID, nStrItemList); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Set current parent id */
    SetParentHandler(MENU_MTPNP_CALL_ID);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Display Category1 Screen */
    ShowCategory15Screen(STRING_MTPNP_CALL_ID,
                     #ifdef __MMI_UCM__
                         GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
                     #else
                         MAIN_MENU_TITLE_SETTINGS_ICON,
                     #endif /* __MMI_UCM__ */
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, index, guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void HiliteCard2CallIDSetByNwk(void)
{
    MTPNP_AD_Update_Card2_Caller_ID_Status_Tmp(MTPNP_LOCAL_NUMBER_DETERMINED_BY_NETWORK);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(MTPNP_AD_Update_Card2_CallerID_Status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HiliteCard2CallIDShowCid(void)
{
    /* storing the menu item selected */
    MTPNP_AD_Update_Card2_Caller_ID_Status_Tmp(MTPNP_LOCAL_NUMBER_SEND);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(MTPNP_AD_Update_Card2_CallerID_Status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HiliteCard2CallIDHideCid(void)
{
    /* storing the menu item selected */
    MTPNP_AD_Update_Card2_Caller_ID_Status_Tmp(MTPNP_LOCAL_NUMBER_HIDE);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(MTPNP_AD_Update_Card2_CallerID_Status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HiliteCard2CallWait(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /*set call channel */
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETWaitingMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETWaitingMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

void HiliteCard2CallForward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /*set call channel */
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(EntryCALLSETForwardMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightCard2Barring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left/right soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /*set call channel */
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

void HintCard2CallID(MTPNP_UINT16 index)
{
    MTPNP_OSAL_memset((MTPNP_CHAR *) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    switch (MTPNP_AD_Get_Card2_Caller_ID_Status())
    {
    case MTPNP_LOCAL_NUMBER_DETERMINED_BY_NETWORK:
        MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_CLI_SET_NETWORK), MAX_SUBMENU_CHARACTERS);
        break;
    case MTPNP_LOCAL_NUMBER_HIDE:
        MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_CLI_HIDE_ID), MAX_SUBMENU_CHARACTERS);
        break;
    case MTPNP_LOCAL_NUMBER_SEND:
        MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) hintData[index],
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_CLI_SEND_ID), MAX_SUBMENU_CHARACTERS);
        break;
    default:
        break;
    }
}

void MTPNP_PFAL_CallID_Update_Succeed(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_CARD2_CALLER_ID_MAIN);
}

void MTPNP_PFAL_CallID_Update_Failed(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION,
                 ERROR_TONE);
    DeleteScreenIfPresent(SCR_CARD2_CALLER_ID_MAIN);
}

void HighlightCard2LineSwitch(void)
{
    g_slave_lineid_input = (MTPNP_UINT8) GetCurrHiliteID();
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_SETTING_LINE_SEL, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /* set the left/right soft key functions handlers */

    SetLeftSoftkeyFunction(MTPNP_PFAL_SelectLine, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HintCard2LineSwitch(MTPNP_UINT16 index)
{
    MTPNP_OSAL_memset((MTPNP_CHAR *) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_1)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_slave_lineinfo,
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_LSW_LINE1));
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_slave_lineinfo,
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_LSW_LINE2));
    }
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) g_slave_lineinfo);
}

void MTPNP_PFAL_SelectLine(void)
{
    MTPNP_UINT8 line_no;
    ClearAllKeyHandler();
    SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);

    if (MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_1)
    {
        line_no = MTPNP_AD_LINE_2;
    }
    else
    {
        line_no = MTPNP_AD_LINE_1;
    }

    MTPNP_AD_Select_LineID(line_no);
}

void MTPNP_PFAL_Line_Switching_Succeed(void)
{
#ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
    MTPNP_CHAR tempstr[10];
#endif

    if (MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_1)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_slave_lineinfo,
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_LSW_LINE1));
    }
    else if (MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_2)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_slave_lineinfo,
                                       (MTPNP_CHAR *) GetString(STRING_MTPNP_LSW_LINE2));
    }

    MTPNP_PFAL_Refresh_Card2_Owner_Number();

#ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) tempstr, (MTPNP_CHAR *) ",");
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) g_slave_lineinfo, (MTPNP_CHAR *) tempstr);
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) g_slave_lineinfo, (MTPNP_CHAR *) g_slave_ownername);
#endif /* __MMI_LINE_SWITCH_SHOW_NUMBER__ */

    if (GetActiveScreenId() == SCR_SLAVECALLSETTING)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[g_slave_lineid_input], (MTPNP_CHAR *) g_slave_lineinfo);
        Category52ChangeItemDescription(g_slave_lineid_input, (MTPNP_UINT8 *) g_slave_lineinfo);
        RedrawCategoryFunction();
        ClearAllKeyHandler();
        register_fixed_list_keys();
        HighlightCard2LineSwitch();
    }
    else
    {
        MTPNP_PFAL_Refresh_StatusBar();
    }
}

void MTPNP_PFAL_Line_Switching_Failed(void)
{
    ShowCategory2Screen(STRING_MTPNP_LINE_SET_TITLE, IMG_SLAVE_LINE_SET_TITLE,
                        STR_GLOBAL_OK, IMG_GLOBAL_OK, 0, 0, STRING_MTPNP_LINE1_SET_ERR, NULL);
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* the card2 call setting */

/* the card2 security setting */
static void HighlightDMSecurity(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntryDMSecurityMain, KEY_EVENT_UP);
    SetKeyHandler(EntryDMSecurityMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void EntryDMSecurityMain(void)
{
    if (!mmi_bootup_is_sim_valid() || MTPNP_PFAL_Is_Card1Absent())
    {
        mmi_frm_hide_menu_item(MENU9101_SECURITY);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU9101_SECURITY);
    }

    if (!mmi_bootup_is_sim2_valid() || MTPNP_PFAL_Is_Card2Absent())
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_SECURITY_SETTING);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_MTPNP_SECURITY_SETTING);
    }

    mmi_mtpnp_entry_menu(
        SCR_MTPNP_DM_SECSET,
        NULL,
        EntryDMSecurityMain,
        MENU_MTPNP_DM_SECURITY_SETTING,
        STR_MENU9101_SECURITY,
        MAIN_MENU_TITLE_SETTINGS_ICON);
}

void HighlightCard2Security(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_Security, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_AD_Get_SIM_Status_For_Security, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntryCard2SecurityMain(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];
    MTPNP_UINT16 nNumofItem;
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *SecurityType[MAX_SUB_MENUS];

    EntryNewScreen(SCR_CARD2_SECSETMAIN, NULL, EntryCard2SecurityMain, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSETMAIN);

    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_SECURITY_SETTING);

    GetSequenceStringIds_Ext(MENU_MTPNP_SECURITY_SETTING, nStrItemList);

    SetParentHandler(MENU_MTPNP_SECURITY_SETTING);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ConstructHintsList(MENU_MTPNP_SECURITY_SETTING, SecurityType);

    gSecuritySetupContext.from_secset = 1;

    ShowCategory52Screen(
        STRING_MTPNP_SECURITY_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (MTPNP_UINT16*) gIndexIconsImageList,
        SecurityType,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void HighlightCard2ChangePassword(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntryCard2SecurityChangePassword, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2SecurityChangePassword, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntryCard2SecurityChangePassword(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];
    MTPNP_UINT16 nNumofItem;
    MTPNP_UINT8 *guiBuffer;

    EntryNewScreen(SCR_CARD2_SECSET_CHANGE_PASSWORD, NULL, EntryCard2SecurityChangePassword, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_CHANGE_PASSWORD);

    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_CHANGE_PASSWORD);

    GetSequenceStringIds_Ext(MENU_MTPNP_CHANGE_PASSWORD, nStrItemList);

    SetParentHandler(MENU_MTPNP_CHANGE_PASSWORD);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_SCR9026_CHANGE_PASSWORD_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (MTPNP_UINT16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void HighlightCard2SIMLock(void)
{
    if (MTPNP_AD_SIM_CHV1_Is_Enable())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else if (MTPNP_AD_SIM_CHV1_Is_Disable())
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_Lock, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_AD_Get_SIM_Status_For_Lock, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void HighlightCard2Pin1Passwd(void)
{
    MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_SIM_CHV1);

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_Change, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_AD_Get_SIM_Status_For_Change, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void HighlightCard2Pin2Passwd(void)
{
    MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_SIM_CHV2);

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_Change, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_AD_Get_SIM_Status_For_Change, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HintCard2SIMLock(MTPNP_UINT16 index)
{
    kal_prompt_trace(MOD_MMI, "[CHV]MTPNP_AD_SIM_CHV1_Is_Enable()=%d", MTPNP_AD_SIM_CHV1_Is_Enable());

    MTPNP_OSAL_memset((MTPNP_CHAR*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (MTPNP_AD_SIM_CHV1_Is_Disable())
    {
        MTPNP_PFAL_Unicode_Memory_Copy(
            (MTPNP_CHAR*) hintData[index],
            (MTPNP_CHAR*) GetString(STR_GLOBAL_OFF),
            MAX_SUBMENU_CHARACTERS);
    }
    else if (MTPNP_AD_SIM_CHV1_Is_Enable())
    {
        MTPNP_PFAL_Unicode_Memory_Copy(
            (MTPNP_CHAR*) hintData[index],
            (MTPNP_CHAR*) GetString(STR_GLOBAL_ON),
            MAX_SUBMENU_CHARACTERS);
    }
}

void EntryCard2SIMLockPIN1(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;
    MTPNP_UINT8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    EntryNewScreen(SCR_CARD2_SECSET_SIM_LOCK_PIN1, ExitCard2SECSETSIMLockPIN1, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_SIM_LOCK_PIN1);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_SIM_LOCK_PIN1);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputpwdbuffer, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    MTPNP_PFAL_FillCountDownString(MTPNP_AD_SETTING_TYPE_CHV1, PassCountdownDisp);

#if defined UI_SMALL_PIN_EDITOR_SCREEN
    enable_resized_small_screen();
#endif 

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STRING_MTPNP_ENTER_CARD2PIN,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputpwdbuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(MTPNP_AD_SetSIMLockReq, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_AD_SetSIMLockReq, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(MTPNP_AD_SetSIMLockReq);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

static void EntryCard2SECSETChangePWOldPWD(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;
    MTPNP_UINT8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];
    MTPNP_UINT16 strid = MTPNP_NULL;

    switch (MTPNP_AD_Get_SIM_CurrentPassword())
    {
        case MTPNP_SIM_CHV1:
            if (MTPNP_AD_SIM_CHV1_Is_Disable())
            {
                DisplayPopup(
                    (MTPNP_UINT8*) GetString(STRING_MTPNP_ENABLE_CARD2_PIN),
                    IMG_GLOBAL_ERROR,
                    0,
                    ST_NOTIFYDURATION,
                    ERROR_TONE);
                return;
            }
            MTPNP_PFAL_FillCountDownString(MTPNP_AD_SETTING_TYPE_CHV1, PassCountdownDisp);
            strid = STRING_MTPNP_SETTING_OLD_CARD2_PIN;
            break;

        case MTPNP_SIM_CHV2:
            if (MTPNP_AD_Get_CHV2_Count() == 0)
            {
                if (MTPNP_AD_Get_UBCHV2_Count() == 0)
                {
                    DisplayPopup(
                        (MTPNP_UINT8*) GetString(STRING_MTPNP_SETTING_PIN2_BLOCK_MSG),
                        IMG_GLOBAL_ERROR,
                        0,
                        ST_NOTIFYDURATION,
                        ERROR_TONE);
                }
                else
                {
                    DeleteUptoScrID(SCR_CARD2_SECSET_CHANGE_PASSWORD);
                    ExitCard2SECSETPUK2();
                    DisplayPopup(
                        (MTPNP_UINT8*) GetString(STRING_MTPNP_PIN_BLOCKED_PUK2),
                        IMG_GLOBAL_ERROR,
                        0,
                        ST_NOTIFYDURATION,
                        ERROR_TONE);
                }
                return;
            }
            MTPNP_PFAL_FillCountDownString(MTPNP_AD_SETTING_TYPE_CHV2, PassCountdownDisp);
            strid = STRING_MTPNP_SETTING_OLD_CARD2_PIN2;
            break;
    }

    EntryNewScreen(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD, ExitCard2SECSETChangePWOldPWD, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputpwdbuffer, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        strid,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputpwdbuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryCard2SECSETChangePWNewPWD, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2SECSETChangePWNewPWD, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(EntryCard2SECSETChangePWNewPWD);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

static void EntryCard2SECSETChangePWNewPWD(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;
    MTPNP_UINT16 strid = MTPNP_NULL;

    switch (MTPNP_AD_Get_SIM_CurrentPassword())
    {
        case MTPNP_SIM_CHV1:
            strid = STRING_MTPNP_SETTING_NEW_CARD2_PIN;
            break;

        case MTPNP_SIM_CHV2:
            strid = STRING_MTPNP_SETTING_NEW_CARD2_PIN2;
            break;
    }

    EntryNewScreen(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD, ExitCard2SECSETChangePWNewPWD, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        strid,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputNewpinbufferfirsttime,
        MAX_PWD_LENGTH_MMI,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryCard2SECSETChangePWCfmPWD, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2SECSETChangePWCfmPWD, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(EntryCard2SECSETChangePWCfmPWD);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

static void EntryCard2SECSETChangePWCfmPWD(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;

    EntryNewScreen(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD, ExitCard2SECSETChangePWCfmPWD, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_SCR9031_CONFIRM_PW_CAPTION,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputnewpinbuffersecondtime,
        MAX_PWD_LENGTH_MMI,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SendCard2ReqToChangePwd, KEY_EVENT_UP);
    SetKeyHandler(SendCard2ReqToChangePwd, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(SendCard2ReqToChangePwd);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

static void EntryCard2SECSETPIN2(void)
{
    U8 *guiBuffer;
    U8 *inputBuffer;
    U8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    EntryNewScreen(SCR_CARD2_SECSET_PIN2, ExitCard2SECSETPIN2, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_PIN2);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_PIN2);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputpwdbuffer, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    MTPNP_PFAL_FillCountDownString(MTPNP_AD_SETTING_TYPE_CHV2, PassCountdownDisp);

#if defined UI_SMALL_PIN_EDITOR_SCREEN
    if (gFDLBDLContext.small_screen == 1)
    {
        enable_resized_small_screen();
    }
#endif 

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STRING_MTPNP_ENTER_CARD2PIN2,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputpwdbuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);

    MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_SIM_CHV2);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(MTPNP_AD_Validate_CHV, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_AD_Validate_CHV, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(MTPNP_AD_Validate_CHV);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

void EntryCard2SECSETPUK2(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;
    MTPNP_UINT8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    EntryNewScreen(SCR_CARD2_SECSET_PUK2, ExitCard2SECSETPUK2, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_PUK2);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_PUK2);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputpwdbuffer, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_SettingPukValidation);
    MTPNP_PFAL_FillCountDownString(MTPNP_AD_SETTING_TYPE_UBCHV2, PassCountdownDisp);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (!mmi_is_redrawing_bk_screens())
#endif
    {
        sprintf(g_idle_context.DialPadCallBuffer, ""); /* reset dial pad for input * to start ssc */
    }

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STRING_MTPNP_SETTING_ENTER_PUK2,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputpwdbuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);

    SetKeyHandler(SSCHandleEnterPUKFromSecset2, KEY_STAR, KEY_EVENT_DOWN);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryCard2SECSETPUK2NewPIN2, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2SECSETPUK2NewPIN2, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(EntryCard2SECSETPUK2NewPIN2);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) < MMI_MIN_PUK_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

static void EntryCard2SECSETPUK2NewPIN2(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;

    EntryNewScreen(SCR_CARD2_SECSET_PUK2_NEW_PIN2, ExitCard2SECSETNewPIN2, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STRING_MTPNP_SETTING_ENTER_NEW_PIN2,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputNewpinbufferfirsttime,
        MAX_PWD_LENGTH_MMI,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryCard2SECSETPUK2ConfirmPIN2, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2SECSETPUK2ConfirmPIN2, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(EntryCard2SECSETPUK2ConfirmPIN2);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

static void EntryCard2SECSETPUK2ConfirmPIN2(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;

    EntryNewScreen(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2, ExitCard2SECSETNewPIN2Confirm, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2);
    if (inputBuffer == NULL)
        MTPNP_OSAL_memset(g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    else
    {
        MTPNP_OSAL_memset(g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime, (MTPNP_CHAR*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_SCR9031_CONFIRM_PW_CAPTION,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputnewpinbuffersecondtime,
        MAX_PWD_LENGTH_MMI,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ValidateCard2NewPin2, KEY_EVENT_UP);
    SetKeyHandler(ValidateCard2NewPin2, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(ValidateCard2NewPin2);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

static void ExitCard2SECSETSIMLockPIN1(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_SIM_LOCK_PIN1;
    Scr.entryFuncPtr = EntryCard2SIMLockPIN1;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputpwdbuffer);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

static void ExitCard2SECSETChangePWOldPWD(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_CHANGEPW_OLD_PWD;
    Scr.entryFuncPtr = EntryCard2SECSETChangePWOldPWD;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputpwdbuffer);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

static void ExitCard2SECSETChangePWNewPWD(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_CHANGEPW_NEW_PWD;
    Scr.entryFuncPtr = EntryCard2SECSETChangePWNewPWD;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

static void ExitCard2SECSETChangePWCfmPWD(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_CHANGEPW_CFM_PWD;
    Scr.entryFuncPtr = EntryCard2SECSETChangePWCfmPWD;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

static void ExitCard2SECSETPIN2(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_PIN2;
    Scr.entryFuncPtr = EntryCard2SECSETPIN2;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputpwdbuffer);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

void ExitCard2SECSETPUK2(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_PUK2;
    Scr.entryFuncPtr = EntryCard2SECSETPUK2;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputpwdbuffer);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

static void ExitCard2SECSETNewPIN2(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_PUK2_NEW_PIN2;
    Scr.entryFuncPtr = EntryCard2SECSETPUK2NewPIN2;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

static void ExitCard2SECSETNewPIN2Confirm(void)
{
    history Scr;

    Scr.scrnID = SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2;
    Scr.entryFuncPtr = EntryCard2SECSETPUK2ConfirmPIN2;
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) Scr.inputBuffer, (MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

static void ValidateCard2NewPin2(void)
{
    historyNode *History;

    if (memcmp(
            (void*)g_slave_inputnewpinbuffersecondtime,
            (void*)g_slave_inputNewpinbufferfirsttime,
            (MAX_PWD_LENGTH_MMI - 1) * ENCODING_LENGTH) == 0)
    {
        MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_SIM_CHV2);
        MTPNP_AD_Set_CHV_Pass_CB(NULL);
        MTPNP_AD_Validate_PUK(g_slave_inputpwdbuffer, g_slave_inputNewpinbufferfirsttime);
    }
    else
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_CARD2_PIN2_DONOT_MATCH),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);
        DeleteUptoScrID(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
        if (GetHistoryScrID(SCR_CARD2_SECSET_PUK2_NEW_PIN2, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            if (History->guiBuffer != NULL)
                memset(History->guiBuffer, 0, 2);
        }
    }
}

static void SendCard2ReqToChangePwd(void)
{
    historyNode *History;
    U16 strid = STRING_MTPNP_CARD2_PIN_DONOT_MATCH;

    if (memcmp(
            (void*)g_slave_inputnewpinbuffersecondtime,
            (void*)g_slave_inputNewpinbufferfirsttime,
            (MAX_PWD_LENGTH_MMI - 1) * ENCODING_LENGTH) == 0)
    {
        MTPNP_AD_ReqToChangePwd(g_slave_inputpwdbuffer, g_slave_inputNewpinbufferfirsttime);
    }
    else
    {
        MTPNP_OSAL_memset(g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
        MTPNP_OSAL_memset(g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);

        switch (MTPNP_AD_Get_SIM_CurrentPassword())
        {
            case MTPNP_SIM_CHV1:
                strid = STRING_MTPNP_CARD2_PIN_DONOT_MATCH;
                break;

            case MTPNP_SIM_CHV2:
                strid = STRING_MTPNP_CARD2_PIN2_DONOT_MATCH;
                break;
        }

        DisplayPopup((MTPNP_UINT8*) GetString(strid), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
        if (GetHistoryScrID(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD, &History))
        {
            if (History->inputBuffer != NULL)
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            if (History->guiBuffer != NULL)
                memset(History->guiBuffer, 0, 2);
        }
    }
}

void MTPNP_PFAL_CHV_Change_Succeed(MTPNP_UINT8 type)
{
    kal_prompt_trace(MOD_MMI, "[CHV]type=%d", type);

    if (type == MTPNP_SIM_CHV1)
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_CARD2_PIN_CHANGE),
            IMG_GLOBAL_ACTIVATED,
            1,
            ST_NOTIFYDURATION,
            0);
    }
    else if (type == MTPNP_SIM_CHV2)
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_CARD2_PIN2_CHANGE),
            IMG_GLOBAL_ACTIVATED,
            1,
            ST_NOTIFYDURATION,
            0);
    }

    if (IsScreenPresent(SCR_CARD2_SECSET_CHANGE_PASSWORD))
    {
        DeleteUptoScrID(SCR_CARD2_SECSET_CHANGE_PASSWORD);
    }
    else
    {
        DeleteUptoScrID(IDLE_SCREEN_ID);
    }
}

void MTPNP_PFAL_CHV_Change_Failed(MTPNP_UINT8 type)
{
    historyNode *History;

    kal_prompt_trace(MOD_MMI, "[CHV]type=%d", type);

    if (type == MTPNP_SIM_CHV1)
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_WRONG_CARD2_PIN),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);
    }
    else if (type == MTPNP_SIM_CHV2)
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_WRONG_CARD2_PIN2),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);
    }

    if (IsScreenPresent(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD))
    {
        DeleteUptoScrID(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
        if (GetHistoryScrID(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD, &History))
        {
            if (History->inputBuffer != NULL)
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            if (History->guiBuffer != NULL)
                memset(History->guiBuffer, 0, 2);
        }
    }
    else
    {
        DeleteUptoScrID(IDLE_SCREEN_ID);
    }
}

void MTPNP_PFAL_SECSETSetSIMLockRsp(MTPNP_BOOL result)
{
    historyNode *History;
    /*U16 index = GetCurrHiliteID();*/

    kal_prompt_trace(
        MOD_MMI,
        "[CHV]MTPNP_AD_SIM_CHV1_Is_Enable()=%d, result=%d",
        MTPNP_AD_SIM_CHV1_Is_Enable(),
        result);

    if (result)
    {
        if (MTPNP_AD_SIM_CHV1_Is_Disable())
        {
            /*MTPNP_PFAL_Unicode_Memory_Copy(
                (MTPNP_CHAR*) hintData[index],
                (MTPNP_CHAR*) GetString(STR_GLOBAL_OFF),
                MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);*/
            DisplayPopup(
                (MTPNP_UINT8*) GetString(STRING_MTPNP_SETTING_CARD2_SIM_UNLOCK),
                IMG_GLOBAL_ACTIVATED,
                1,
                ST_NOTIFYDURATION,
                0);
        }
        else
        {
            /*MTPNP_PFAL_Unicode_Memory_Copy(
                (MTPNP_CHAR*) hintData[index],
                (MTPNP_CHAR*) GetString(STR_GLOBAL_ON),
                MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);*/
            DisplayPopup(
                (MTPNP_UINT8*) GetString(STRING_MTPNP_SETTING_CARD2_SIM_LOCK),
                IMG_GLOBAL_ACTIVATED,
                1,
                ST_NOTIFYDURATION,
                0);
        }
        DeleteNHistory(1);
    }
    else
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_WRONG_CARD2_PIN),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);

        if (GetHistoryScrID(SCR_CARD2_SECSET_SIM_LOCK_PIN1, &History))
        {
            if (History->inputBuffer != NULL)
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            if (History->guiBuffer != NULL)
                memset(History->guiBuffer, 0, 2);
        }
    }
}

void MTPNP_PFAL_Entry_UnblockPIN2(void)
{
    historyNode *History;

    DisplayPopup(
        (MTPNP_UINT8*) GetString(STRING_MTPNP_PIN_BLOCKED_PUK2),
        IMG_GLOBAL_ERROR,
        0,
        ST_NOTIFYDURATION,
        ERROR_TONE);
    ExitCard2SECSETPUK2();
    if (GetHistoryScrID(SCR_CARD2_SECSET_PUK2, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        if (History->guiBuffer != NULL)
            memset(History->guiBuffer, 0, 2);
    }
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

void MTPNP_PFAL_Entry_CHV_Change(MTPNP_UINT8 type)
{
    switch (type)
    {
        case MTPNP_SIM_CHV1:
            if (MTPNP_AD_SIM_CHV1_Is_Enable())
            {
                if (MTPNP_AD_Get_CHV1_Count() > 0)
                {
                    EntryCard2SECSETChangePWOldPWD();
                }
                else if (MTPNP_AD_Get_UBCHV1_Count() > 0)
                {
                    MTPNP_PFAL_Entry_UnblockPIN();
                }
                else
                {
                    MTPNP_PFAL_Entry_Card2_Blocked(MTPNP_SIM_CHV1);
                }
            }
            else
            {
                DisplayPopup(
                    (MTPNP_UINT8*) GetString(STRING_MTPNP_ENABLE_CARD2_PIN),
                    IMG_GLOBAL_ERROR,
                    0,
                    ST_NOTIFYDURATION,
                    ERROR_TONE);
            }
            break;

        case MTPNP_SIM_CHV2:
            if (MTPNP_AD_Get_CHV2_Count() > 0)
            {
                EntryCard2SECSETChangePWOldPWD();
            }
            else if (MTPNP_AD_Get_UBCHV2_Count() > 0)
            {
                historyNode *History;

                DisplayPopup(
                    (MTPNP_UINT8*) GetString(STRING_MTPNP_PIN_BLOCKED_PUK2),
                    IMG_GLOBAL_ERROR,
                    0,
                    ST_NOTIFYDURATION,
                    ERROR_TONE);
                ExitCard2SECSETPUK2();
                if (GetHistoryScrID(SCR_CARD2_SECSET_PUK2, &History) == ST_SUCCESS)
                {
                    if (History->inputBuffer != NULL)
                        memset(History->inputBuffer, 0, ENCODING_LENGTH);
                    if (History->guiBuffer != NULL)
                        memset(History->guiBuffer, 0, 2);
                }
            }
            else
            {
                DisplayPopup(
                    (MTPNP_UINT8*) GetString(STR_ID_PIN2_NOT_SUPPORT),
                    IMG_GLOBAL_ERROR,
                    0,
                    ST_NOTIFYDURATION,
                    ERROR_TONE);
            }
            break;
    }
}

void MTPNP_PFAL_Entry_CHV1_Lock()
{
    if (MTPNP_AD_Get_CHV1_Count() > 0)
    {
        EntryCard2SIMLockPIN1();
    }
    else if (MTPNP_AD_Get_UBCHV1_Count() > 0)
    {
        MTPNP_PFAL_Entry_UnblockPIN();
    }
    else
    {
        MTPNP_PFAL_Entry_Card2_Blocked(MTPNP_SIM_CHV1);
    }
}

void MTPNP_PFAL_Entry_CHV2_Status_Rsp()
{
    if (MTPNP_AD_Get_CHV2_Count() > 0)
    {
        if (gFDLBDLContext.is_set_toggle == 1)
        {
            gFDLBDLContext.is_set_toggle = 0;
            gFDLBDLContext.small_screen = 1;
        }
        else
        {
            gFDLBDLContext.small_screen = 0;
        }
        EntryCard2SECSETPIN2();
    }
    else if (MTPNP_AD_Get_UBCHV2_Count() > 0)
    {
        historyNode *History;

        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_PIN_BLOCKED_PUK2),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);
        ExitCard2SECSETPUK2();
        if (GetHistoryScrID(SCR_CARD2_SECSET_PUK2, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            if (History->guiBuffer != NULL)
                memset(History->guiBuffer, 0, 2);
        }
    }
    else
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STR_ID_PIN2_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            ERROR_TONE);
    }
}

void MTPNP_PFAL_Entry_Card2_Security(void)
{
    EntryCard2SecurityMain();
}

void MTPNP_PFAL_Entry_Card2_Not_Support(void)
{
    DisplayPopup(
        (MTPNP_UINT8*) GetString(STRING_MTPNP_CARD2_NOTSUPPORT),
        IMG_GLOBAL_ERROR,
        0,
        ST_NOTIFYDURATION,
        ERROR_TONE);
}

/* the card2 security setting */
void HighlightCard2PhoneSetting(void)
{
    /*1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /*2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /*3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCard2PhoneSetupMain, KEY_EVENT_UP);

    SetKeyHandler(EntryCard2PhoneSetupMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /*4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntryCard2PhoneSetupMain(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_CARD2_PHONE_SETTING, MTPNP_NULL, EntryCard2PhoneSetupMain, MTPNP_NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_PHONE_SETTING);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_PHONE_SETTING);

    /* 4. Get attribute of menu to be displayed */
    /*nDispAttribute = GetDispAttributeOfItem(MENU_MTPNP_CALL_SETTING); */

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_PHONE_SETTING, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_PHONE_SETTING);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_MTPNP_PHONE_SETTING, ItemType);

    ShowCategory52Screen(STRING_MTPNP_PHONE_SETTING, IMG_SI_CARD2_PHONESETTING,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, ItemType, 0, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* card2 phone setting */

void MTPNP_PFAL_Entry_SIM1CHV_Verify(void *param)
{
    MTPNP_UINT8 *p = (MTPNP_UINT8 *) param;

    /* If need verify PIN, need stop the the switch timeout timer */
/*
    MTPNP_PFAL_Stop_Timer(MTPNP_MODESWITCH_TIMER);
*/    
    if (*p == MTPNP_AD_SIMCARD_PIN_CANCELED)
    {
        EntryScrEnterPIN();
    }
}

void MTPNP_PFAL_Entry_SIM2CHV_Verify(void *param)
{
    MTPNP_UINT8 *p = (MTPNP_UINT8 *) param;

    /* If need verify PIN, need stop the the switch timeout timer */
/*
    MTPNP_PFAL_Stop_Timer(MTPNP_MODESWITCH_TIMER);
*/
    
    if (*p == MTPNP_AD_SIMCARD_PIN_CANCELED)
    {
        MTPNP_PFAL_Entry_EnterPIN();
    }
}

#endif // __MMI_DUAL_SIM_MASTER__

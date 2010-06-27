#include "MMI_features.h"

#if defined( __MMI_DUAL_SIM_MASTER__) && (! defined(__MMI_DUAL_SIM_SINGLE_CALL__))

#include "kal_non_specific_general_types.h"

#ifdef __MMI_ENGINEER_MODE__

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif

#include "stdC.h"
#include "GlobalConstants.h"
#include "DebugInitDef.h"
#include "wgui.h"
#include "GlobalStruct.h"
#include "PixtelDataTypes.h"
#include "wgui_categories.h"
#include "HistoryGprot.h"
#include "IdleAppProt.h"
#include "CustDataRes.h"
#include "ProtocolEvents.h"
#include "EventsGprot.h"
#include "DateTimeType.h"
#include "ThrdOsInterface.h"
#include "OSThreadInterfaceGprot.h"
#include "CustMenuRes.h"
#include "MiscFunctions.h"
#include "QueueGprot.h"
#include "TaskInit.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"
#include "EngineerModeTracer.h"
#include "NetworkSetupGProt.h"
#include "wgui_status_icons.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "GlobalDefs.h"
#include "CommonScreens.h"

#include "device.h"
#include "uart_sw.h"
#include "med_struct.h"
#include "mmi_msg_struct.h"
#include "L4Dr.h"
#include "custom_util.h"
#include "lcd_sw.h"
#include "resource_audio.h"
#include "NVRAMEnum.h"
#include "NVRAMProt.h"
#include "NVRAMType.h"
#include "SettingProfile.h"

#ifdef __MTK_TARGET__
#include "l1audio.h"
#endif

#ifdef __TST_MODULE__
#include "tst.h"                /* TST extern functions */
#endif /* __TST_MODULE__ */

#include "l4c_common_enum.h"

#include "FactoryModeDef.h"

#include "MTPNP_PFAL_Master_EngineerMode.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Network.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "MTPNP_PFAL_category_screen.h"

extern U8 FMGetCurrentTest(void);
extern void FMSetCurrentTest(U8 test);
extern void FM_Autotest_set_key_handlers(void);

/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
/* factory mode begin */
static void HighlightFMSlaveComm(void);
static void FMSlaveCommTestReq(void);
static void FMSlaveCommTestRsp(void *info);
static void FMSlaveCommTestFail(void);
static void HighlightFMSlaveMic(void);
static void EntrySlaveFMMic(void);
static void HighlightFMSlaveReceiver(void);
static void EntrySlaveFMReceiver(void);
static void HighlightFMSlaveSpeaker(void);
static void EntrySlaveFMLoudSpkHdlr(void);
static void HighlightFMSlaveHeadset(void);
static void EntrySlaveFMHeadset(void);
static void FMTestReqSlaveOn(U8 testType);
static void FMTestReqSlaveOff(U8 testType);
static void FMResetSlaveNoTestFlag(U8 testType);
/* factory mode end */

/* factory mode auto test begin */
static void FMSlaveCommAutoTestEnd(void *info);
static void FMSlaveCommAutoTestFail(void);
static void FMAutoTestSlaveMicEnd(void);
static void FMAutoTestSlaveReceiverEnd(void);
static void FMAutoTestSlaveSpeakerEnd(void);
static void FMAutoTestSlaveHeadsetEnd(void);
static void FM_Autotest_test_done_USC2string(const S8 * name);
/* factory mode auto test end */
/**************************LOCAL*FUNCTION*DECLARE*END*************************/
static MTPNP_UINT8 g_master_rssi = 0xff;
static MTPNP_UINT8 g_slave_rssi = 0xff;
static MTPNP_UINT8 g_master_network_status = 0xff;
static MTPNP_UINT8 g_slave_network_status = 0xff;

extern const MTPNP_UINT16 gIndexIconsImageList[];
extern MTPNP_UINT8 currentHighlightIndex;
extern MTPNP_CHAR UnicodeDisplayBuf[MAX_TEST_STRING_BUF * 4];

extern S8 EMFMUnicodeDisplayBuf[MAX_TEST_STRING_BUF * 2];
extern U8 EMFMAsciiDisplayBuf[MAX_TEST_STRING_BUF];
extern const testlet Tests[MAX_AUTO_TEST_ITEMS];
extern S16 currTestItem;
extern S16 gAutoTestListSize;

static MTPNP_BOOL SLAVE_ReceiverTestOn = MTPNP_FALSE;   /* Receiver */
static MTPNP_BOOL SLAVE_HeadsetTestOn = MTPNP_FALSE;    /* Headset Test */
static MTPNP_BOOL SLAVE_MicTestOn = MTPNP_FALSE;
static MTPNP_BOOL SLAVE_SpeakerTestOn = MTPNP_FALSE;
static MTPNP_BOOL FMAutoTestSlaveCommResult;

void MTPNP_PFAL_DualMode_EngineerMode_Init(void)
{
    SetHiliteHandler(MENU_MTPNP_EM_DUALMODE, HighlightDualModeEm);
    SetHiliteHandler(MENU_MTPNP_EM_SET_OP_SIDE, HighlightEmSetOpSide);
    SetHiliteHandler(MENU_EM_CHK_RSSI, HighlightEmChkRssi);
    SetHiliteHandler(MENU_EM_CALLBACK_PSN, HighlightEmCallbackPSN);
    SetHiliteHandler(MENU_EM_ASSERT_SLAVE, HighlightEmAssertSlave);

    if (MTPNP_AD_SW_Need_Register())
    {
        MTPNP_PFAL_Hide_Menu(MENU_EM_CALLBACK_PSN);
    }

    SetHiliteHandler(MENU_MTPNP_FM_COMM, HighlightFMSlaveComm);
    SetHiliteHandler(MENU_MTPNP_FM_MIC, HighlightFMSlaveMic);
    SetHiliteHandler(MENU_MTPNP_FM_SPEAKER, HighlightFMSlaveSpeaker);
    SetHiliteHandler(MENU_MTPNP_FM_RECEIVER, HighlightFMSlaveReceiver);
    SetHiliteHandler(MENU_MTPNP_FM_HEADSET, HighlightFMSlaveHeadset);
}

void HighlightDualModeEm(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryDualModeEm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryDualModeEm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

void EntryDualModeEm(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
    MTPNP_UINT16 nDispAttribute;        /* Stores display attribue */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_EM_DUALMODE, MTPNP_NULL, EntryDualModeEm, MTPNP_NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_EM_DUALMODE);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_EM_DUALMODE);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_MTPNP_EM_DUALMODE);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_EM_DUALMODE, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_EM_DUALMODE);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_MTPNP_EM_DUALMODE, ItemType);

    ShowCategory52Screen(STRING_MTPNP_EM, 0,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, ItemType, 0, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightEmCallbackPSN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryEmCallbackPSN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryEmCallbackPSN, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

void EntryEmCallbackPSN(void)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_STARTREG, StartPSNCallbackProgess);

    DisplayConfirmCountDown(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                            STR_GLOBAL_NO, IMG_GLOBAL_NO,
                            get_string(STRING_MTPNP_PSN_CALLBACK), IMG_GLOBAL_QUESTION,
                            WARNING_TONE, 10, GoBackHistory);

    ClearAllKeyHandler();
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(StartCallbackPSN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void StartCallbackPSN(void)
{
    MTPNP_AD_SW_Register();
}

void StartPSNCallbackProgess(void *pMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_STARTREG);

    GoBackHistory();

    EntryShowCallbackPSNProgress();
}

void EntryShowCallbackPSNProgress(void)
{
    MTPNP_UINT8 *guiBuffer;

    EntryNewScreen(SCR_CALLBACKPSNPROG, MTPNP_NULL, EntryShowCallbackPSNProgress, MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CALLBACKPSNPROG);
    SetParentHandler(MENU_EM_CALLBACK_PSN);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    MTPNP_OSAL_memset(UnicodeDisplayBuf, 0, sizeof(UnicodeDisplayBuf));

    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) UnicodeDisplayBuf,
                                   (const MTPNP_CHAR *) GetString(STRING_MTPNP_PSNCALLBACK_TIP));

    ShowCategory74Screen(STRING_MTPNP_PSN_CALLBACK, 0, (MTPNP_UINT16) NULL, 0, STR_GLOBAL_BACK, 0,
                         (MTPNP_UINT8 *) UnicodeDisplayBuf, sizeof(UnicodeDisplayBuf), guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void HighlightEmAssertSlave(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryEmAssertSlave, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryEmAssertSlave, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

void EntryEmAssertSlave(void)
{
    DisplayConfirmCountDown(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                            STR_GLOBAL_NO, IMG_GLOBAL_NO,
                            get_string(STRING_MTPNP_ASSERT_SLAVE), IMG_GLOBAL_QUESTION,
                            WARNING_TONE, 10, GoBackHistory);

    ClearAllKeyHandler();
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(MTPNP_PFAL_AssertSlave, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_AssertSlave(void)
{
    MTPNP_PFAL_EM_Assert_Slave();
    GoBackHistory();
}

void HighlightEmSetOpSide(void)
{
    SetLeftSoftkeyFunction(EntryEmSetOpSide, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void EntryEmSetOpSide(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT16 ItemList[] = {
        STRING_MTPNP_MASTER_TEST,
        STRING_MTPNP_SLAVE_TEST
    };
    MTPNP_UINT16 op_side_index;

    if (MTPNP_PFAL_Is_Operate_Slave())
    {
        op_side_index = MTPNP_OP_SLAVE_SIDE;
    }
    else
    {
        op_side_index = MTPNP_OP_MASTER_SIDE;
    }

    EntryNewScreen(SCR_EM_OP_SET_SIDE_MENU, NULL, EntryEmSetOpSide, MTPNP_NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_EM_OP_SET_SIDE_MENU);
    RegisterHighlightHandler(SetHighlightIndex);

    ShowCategory11Screen(STRING_MTPNP_EM_OP_SIDE,
                         0, STR_GLOBAL_OK, 0, STR_GLOBAL_BACK, 0, 2, ItemList, op_side_index, guiBuffer);

    SetLeftSoftkeyFunction(EmSetOpSide, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

void EmSetOpSide(void)
{
    MTPNP_UINT16 ItemList[] = {
        STRING_MTPNP_MASTER_TEST,
        STRING_MTPNP_SLAVE_TEST
    };
    MTPNP_UINT8 modeList[] = {
        MTPNP_OP_MASTER_SIDE,
        MTPNP_OP_SLAVE_SIDE
    };

    if (modeList[currentHighlightIndex] == MTPNP_OP_MASTER_SIDE)
    {
        MTPNP_PFAL_Operate_Master();
    }
    else
    {
        MTPNP_PFAL_Operate_Slave();
    }

    DisplayPopup((MTPNP_UINT8 *) GetString(ItemList[currentHighlightIndex]),
                 IMG_GLOBAL_OK, 1, 1000, (MTPNP_UINT8) SUCCESS_TONE);
}

void MTPNP_PFAL_Get_Slave_AudioProfile(MTPNP_UINT8 mode)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_SUCCEED,
                                      MTPNP_PFAL_Get_Slave_AudioProfile_Succeed);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_FAILED, MTPNP_PFAL_Get_Slave_AudioProfile_Failed);
    MTPNP_AD_Get_Audio_Profile(mode);
}

void MTPNP_PFAL_Get_Slave_AudioProfile_Succeed(void *data)
{
    ST_MTPNP_AD_AUDIO_PROFILE *profile = (ST_MTPNP_AD_AUDIO_PROFILE *) data;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_SUCCEED);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_FAILED);

    EmUpdateAudioProfile(profile->speech,
                         profile->keytone,
                         profile->melody,
                         profile->sound,
                         profile->mic,
                         profile->sidetone,
                         profile->tv_out_volume_gain,
                         profile->max_melody_volume_gain, profile->melody_volume_gain_step);
}

void MTPNP_PFAL_Get_Slave_AudioProfile_Failed(void *data)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_SUCCEED);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_GET_AUDIOPROF_FAILED);
}

void MTPNP_PFAL_Set_Slave_AudioProfile(void *profile)
{
    mmi_eq_set_audio_profile_req_struct *msg_p = (mmi_eq_set_audio_profile_req_struct *) profile;
    ST_MTPNP_AD_AUDIO_PROFILE send_profile;

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_SUCCEED,
                                      MTPNP_PFAL_Set_Slave_AudioProfile_Succeed);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_FAILED, MTPNP_PFAL_Set_Slave_AudioProfile_Failed);

    send_profile.mode = msg_p->audio_prof.mode;
    MTPNP_OSAL_memcpy(send_profile.melody, msg_p->audio_prof.melody, 7);
    MTPNP_OSAL_memcpy(send_profile.sound, msg_p->audio_prof.sound, 7);
    MTPNP_OSAL_memcpy(send_profile.keytone, msg_p->audio_prof.keytone, 7);
    MTPNP_OSAL_memcpy(send_profile.speech, msg_p->audio_prof.speech, 7);
    MTPNP_OSAL_memcpy(send_profile.mic, msg_p->audio_prof.mic, 7);
    send_profile.sidetone = msg_p->audio_prof.sidetone;
    send_profile.max_melody_volume_gain = msg_p->audio_prof.max_melody_volume_gain;
    send_profile.melody_volume_gain_step = msg_p->audio_prof.melody_volume_gain_step;
    MTPNP_OSAL_memcpy(send_profile.tv_out_volume_gain, msg_p->audio_prof.tv_out_volume_gain, 7);

    MTPNP_AD_Set_Audio_Profile(&send_profile);
}

void MTPNP_PFAL_Set_Slave_AudioProfile_Succeed(void *data)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_SUCCEED);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_FAILED);

    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
}

void MTPNP_PFAL_Set_Slave_AudioProfile_Failed(void *data)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_SUCCEED);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_EM_SET_AUDIOPROF_FAILED);

    EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
}

void HighlightEmChkRssi(void)
{
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
    SetLeftSoftkeyFunction(EntryChkRssi, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* ZN revise */
static MTPNP_UINT8 g_chk_rssi_info_buffer[128];

static void GetStringOfRssi(MTPNP_UINT8 master_rssi,
             MTPNP_UINT8 slave_rssi, MTPNP_UINT8 master_network, MTPNP_UINT8 slave_network)
{
    MTPNP_UINT8 AsciiDisplayBuf[64];

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, 64);
    MTPNP_OSAL_memset(g_chk_rssi_info_buffer, 0, 128);

    sprintf((MTPNP_CHAR *) AsciiDisplayBuf, "[M]nwk: %d\n[M]rssi: %d\n[S]nwk: %d\n[S]rssi: %d\n",
            master_network, master_rssi, slave_network, slave_rssi);

    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) g_chk_rssi_info_buffer, (MTPNP_CHAR *) AsciiDisplayBuf);
}

void EntryChkRssi(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 slave_status = 0xff;
    MTPNP_UINT8 slave_rssi = 0xff;

    EntryNewScreen(SCR_EM_CHK_RSSI, ExitChkRssi, EntryChkRssi, MTPNP_NULL);

    /* need slave report signal anywhere */
    MTPNP_AD_Set_QOS_Report_Frequency(MTPNP_QOS_RPT_ANY);
    /* register event handler */
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_NETWORK_ATTACH_IND);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_QOS_IND);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_NETWORK_ATTACH_IND, MTPNP_PFAL_EM_Slave_Network_Attach);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_QOS_IND, MTPNP_PFAL_EM_Slave_qos_Ind);

    guiBuffer = GetCurrGuiBuffer(SCR_EM_CHK_RSSI);
    SetParentHandler(MENU_EM_CHK_RSSI);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    slave_status = (MTPNP_UINT8) MTPNP_AD_Get_Card2ServiceType();
    slave_rssi = MTPNP_AD_Get_Slave_rssi();
    MTPNP_PFAL_Refresh_rssi(0xff, slave_rssi, 0xff, slave_status);

    /* ZN revise */
    ShowCategory74Screen(STRING_MTPNP_CHK_RSSI, 0, (MTPNP_UINT16) NULL, 0, STR_GLOBAL_BACK, 0, g_chk_rssi_info_buffer, 63, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void ExitChkRssi(void)
{
    MTPNP_AD_Set_QOS_Report_Frequency(MTPNP_QOS_RPT_GRID);

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_NETWORK_ATTACH_IND);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_QOS_IND);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_NETWORK_ATTACH_IND, MTPNP_PFAL_Slave_Network_Attach);
}

void MTPNP_PFAL_EM_Slave_Network_Attach(void *inMsg)
{
    MTPNP_UINT8 slave_status = 0xff;

    slave_status = (MTPNP_UINT8) MTPNP_AD_Get_Card2ServiceType();
    MTPNP_PFAL_Refresh_rssi(0xff, 0xff, 0xff, slave_status);
    ChangeCategory74MessageString(g_chk_rssi_info_buffer, 63);/* ZN revise */

    MTPNP_PFAL_Refresh_Card2_Owner_Number();
}

void MTPNP_PFAL_EM_Slave_qos_Ind(void *inMsg)
{
    MTPNP_UINT8 slave_rssi = 0xff;

    slave_rssi = MTPNP_AD_Get_Slave_rssi();
    MTPNP_PFAL_Refresh_rssi(0xff, slave_rssi, 0xff, 0xff);
    ChangeCategory74MessageString(g_chk_rssi_info_buffer, 63);    /* ZN revise */
}

void MTPNP_PFAL_Refresh_rssi(MTPNP_UINT8 master_rssi,
                             MTPNP_UINT8 slave_rssi,
                             MTPNP_UINT8 master_network_status, MTPNP_UINT8 slave_network_status)
{
    if (master_rssi < 0xff)
    {
        g_master_rssi = master_rssi;
    }
    if (slave_rssi < 0xff)
    {
        g_slave_rssi = slave_rssi;
    }
    if (master_network_status < 0xff)
    {
        g_master_network_status = master_network_status;
    }
    if (slave_network_status < 0xff)
    {
        g_slave_network_status = slave_network_status;
    }

    GetStringOfRssi(g_master_rssi, g_slave_rssi, g_master_network_status, g_slave_network_status);/* ZN revise */
}

/* factory mode begin */
static void HighlightFMSlaveComm(void)
{
    change_left_softkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(FMSlaveCommTestReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    redraw_left_softkey();
}

static void FMSlaveCommTestReq(void)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_FM_COMMTEST_RSP, FMSlaveCommTestRsp);
    MTPNP_AD_FM_Comm_Test_Req();
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, RECEIVER_DURATION + 2000, FMSlaveCommTestFail);
}

static void FMSlaveCommTestRsp(void *info)
{
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_ID_FM_AUTO_TEST_PASS), IMG_GLOBAL_OK, 0, 1000, 0);
}

static void FMSlaveCommTestFail(void)
{
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_ID_FM_AUTO_TEST_FAILED), IMG_GLOBAL_ERROR, 0, 1000, 0);
}

static void HighlightFMSlaveMic(void)
{
    SetLeftSoftkeyFunction(EntrySlaveFMMic, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    if (SLAVE_MicTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();
}

static void EntrySlaveFMMic(void)
{
    if (!SLAVE_MicTestOn)
    {
        SLAVE_MicTestOn = MTPNP_TRUE;
        change_left_softkey(STR_GLOBAL_OFF, 0);
        FMTestReqSlaveOn(FM_TEST_SLAVE_MIC);
    }
    else
    {
        SLAVE_MicTestOn = MTPNP_FALSE;
        change_left_softkey(STR_GLOBAL_ON, 0);
        FMTestReqSlaveOff(FM_TEST_SLAVE_MIC);
    }
    redraw_left_softkey();
}

static void HighlightFMSlaveReceiver(void)
{
    SetLeftSoftkeyFunction(EntrySlaveFMReceiver, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    if (SLAVE_ReceiverTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();
}

static void EntrySlaveFMReceiver(void)
{
    if (!SLAVE_ReceiverTestOn)
    {
        SLAVE_ReceiverTestOn = MTPNP_TRUE;
        change_left_softkey(STR_GLOBAL_OFF, 0);
        FMTestReqSlaveOn(FM_TEST_SLAVE_RECEIVER);
    }
    else
    {
        SLAVE_ReceiverTestOn = MTPNP_FALSE;
        change_left_softkey(STR_GLOBAL_ON, 0);
        FMTestReqSlaveOff(FM_TEST_SLAVE_RECEIVER);
    }
    redraw_left_softkey();
}

static void HighlightFMSlaveSpeaker(void)
{
    SetLeftSoftkeyFunction(EntrySlaveFMLoudSpkHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    if (SLAVE_SpeakerTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();
}

static void EntrySlaveFMLoudSpkHdlr(void)
{
    if (!SLAVE_SpeakerTestOn)
    {
        SLAVE_SpeakerTestOn = MTPNP_TRUE;
        change_left_softkey(STR_GLOBAL_OFF, 0);
        FMTestReqSlaveOn(FM_TEST_SLAVE_SPEAKER);
    }
    else
    {
        SLAVE_SpeakerTestOn = MTPNP_FALSE;
        change_left_softkey(STR_GLOBAL_ON, 0);
        FMTestReqSlaveOff(FM_TEST_SLAVE_SPEAKER);
    }
    redraw_left_softkey();
}

static void HighlightFMSlaveHeadset(void)
{
    SetLeftSoftkeyFunction(EntrySlaveFMHeadset, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    if (SLAVE_HeadsetTestOn)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    redraw_left_softkey();
}

static void EntrySlaveFMHeadset(void)
{
    if (!SLAVE_HeadsetTestOn)
    {
        SLAVE_HeadsetTestOn = MTPNP_TRUE;
        change_left_softkey(STR_GLOBAL_OFF, 0);
        FMTestReqSlaveOn(FM_TEST_SLAVE_HEADSET);
    }
    else
    {
        SLAVE_HeadsetTestOn = MTPNP_FALSE;
        change_left_softkey(STR_GLOBAL_ON, 0);
        FMTestReqSlaveOff(FM_TEST_SLAVE_HEADSET);
    }
    redraw_left_softkey();
}

static void FMTestReqSlaveOn(U8 testType)
{
    MTPNP_UINT8 on_off = 1;

    MTPNP_AD_SwitchAudioChanel(MTPNP_AUDIO_SLAVE);
    FMResetSlaveNoTestFlag(testType);
    kal_sleep_task(1);

    switch (testType)
    {
    case FM_TEST_SLAVE_MIC:
        MTPNP_AD_FM_Test_Mic_Req(on_off);
        break;

    case FM_TEST_SLAVE_SPEAKER:
        MTPNP_AD_FM_Test_Speaker_Req(on_off);
        MTPNP_PFAL_TurnOnExtAmplifier();
        break;

    case FM_TEST_SLAVE_RECEIVER:
        MTPNP_AD_FM_Test_Receiver_Req(on_off);
        break;

    case FM_TEST_SLAVE_HEADSET:
        MTPNP_AD_FM_Test_Headset_Req(on_off);
        break;
    }
}

static void FMTestReqSlaveOff(U8 testType)
{
    MTPNP_UINT8 on_off = 0;

    MTPNP_AD_SwitchAudioChanel(MTPNP_AUDIO_MASTER);

    switch (testType)
    {
    case FM_TEST_SLAVE_MIC:
        MTPNP_AD_FM_Test_Mic_Req(on_off);
        break;

    case FM_TEST_SLAVE_SPEAKER:
        MTPNP_AD_FM_Test_Speaker_Req(on_off);
        MTPNP_PFAL_TurnOffExtAmplifier();
        break;

    case FM_TEST_SLAVE_RECEIVER:
        MTPNP_AD_FM_Test_Receiver_Req(on_off);
        break;

    case FM_TEST_SLAVE_HEADSET:
        MTPNP_AD_FM_Test_Headset_Req(on_off);
        break;
    }
}

static void FMResetSlaveNoTestFlag(U8 testType)
{
    switch (testType)
    {
    case FM_TEST_SLAVE_COMM:
        SLAVE_ReceiverTestOn = MTPNP_FALSE;     /* Receiver */
        SLAVE_HeadsetTestOn = MTPNP_FALSE;      /* Headset Test */
        SLAVE_MicTestOn = MTPNP_FALSE;
        SLAVE_SpeakerTestOn = MTPNP_FALSE;
        MTPNP_PFAL_TurnOffExtAmplifier();
        break;

    case FM_TEST_SLAVE_MIC:
        SLAVE_ReceiverTestOn = MTPNP_FALSE;     /* Receiver */
        SLAVE_HeadsetTestOn = MTPNP_FALSE;      /* Headset Test */
        SLAVE_SpeakerTestOn = MTPNP_FALSE;
        MTPNP_PFAL_TurnOffExtAmplifier();
        break;

    case FM_TEST_SLAVE_SPEAKER:
        SLAVE_ReceiverTestOn = MTPNP_FALSE;     /* Receiver */
        SLAVE_HeadsetTestOn = MTPNP_FALSE;      /* Headset Test */
        SLAVE_MicTestOn = MTPNP_FALSE;
        break;

    case FM_TEST_SLAVE_RECEIVER:
        SLAVE_HeadsetTestOn = MTPNP_FALSE;      /* Headset Test */
        SLAVE_MicTestOn = MTPNP_FALSE;
        SLAVE_SpeakerTestOn = MTPNP_FALSE;
        MTPNP_PFAL_TurnOffExtAmplifier();
        break;

    case FM_TEST_SLAVE_HEADSET:
        SLAVE_ReceiverTestOn = MTPNP_FALSE;     /* Receiver */
        SLAVE_MicTestOn = MTPNP_FALSE;
        SLAVE_SpeakerTestOn = MTPNP_FALSE;
        MTPNP_PFAL_TurnOffExtAmplifier();
        break;
    }
}

void ExitSlaveFMMenu(void)
{
    if (SLAVE_SpeakerTestOn)
    {
        FMTestReqSlaveOff(FM_TEST_SLAVE_SPEAKER);
    }

    if (SLAVE_MicTestOn)
    {
        FMTestReqSlaveOff(FM_TEST_SLAVE_MIC);
    }

    if (SLAVE_HeadsetTestOn)
    {
        FMTestReqSlaveOff(FM_TEST_SLAVE_HEADSET);
    }

    if (SLAVE_ReceiverTestOn)
    {
        FMTestReqSlaveOff(FM_TEST_SLAVE_RECEIVER);
    }
}

void FMTestRestoreSlaveNormal(void)
{
    MTPNP_AD_SwitchAudioChanel(MTPNP_AUDIO_MASTER);
    SLAVE_ReceiverTestOn = MTPNP_FALSE;
    SLAVE_HeadsetTestOn = MTPNP_FALSE;
    SLAVE_MicTestOn = MTPNP_FALSE;
    SLAVE_SpeakerTestOn = MTPNP_FALSE;
    MTPNP_AD_FM_Test_RestoreNormal_Req();
}

/* factory mode end */

/* factory mode auto test begin */
void FMAutoTestSlaveComm(void)
{
    FMSetCurrentTest(FM_TEST_SLAVE_COMM);
    FMAutoTestSlaveCommResult = MTPNP_FALSE;
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_FM_COMMTEST_RSP, FMSlaveCommAutoTestEnd);
    MTPNP_AD_FM_Comm_Test_Req();
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_ROOT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) GetString(STRING_MTPNP_FM_COMM), NULL);
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, RECEIVER_DURATION + 2000, FMSlaveCommAutoTestFail);
    FM_Autotest_set_key_handlers();
}

static void FMSlaveCommAutoTestEnd(void *info)
{
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    FMSetCurrentTest(FM_TEST_SLAVE_COMM);
    FMAutoTestSlaveCommResult = MTPNP_TRUE;
    FM_Autotest_test_done_USC2string(Tests[FM_TEST_SLAVE_COMM].name);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_RESULT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) EMFMUnicodeDisplayBuf, NULL);
    FM_Autotest_set_key_handlers();
}

static void FMSlaveCommAutoTestFail(void)
{
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    FMSetCurrentTest(FM_TEST_SLAVE_COMM);
    FMAutoTestSlaveCommResult = MTPNP_FALSE;
    FM_Autotest_test_done_USC2string(Tests[FM_TEST_SLAVE_COMM].name);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_RESULT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) EMFMUnicodeDisplayBuf, NULL);
    FM_Autotest_set_key_handlers();
}

void FMAutoTestSlaveMic(void)
{
    FMSetCurrentTest(FM_TEST_SLAVE_MIC);
    Media_Stop();
    SLAVE_MicTestOn = MTPNP_TRUE;
    FMTestReqSlaveOn(FMGetCurrentTest());
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, MIC_DURATION, FMAutoTestSlaveMicEnd);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_ROOT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) GetString(STRING_MTPNP_FM_MIC), NULL);
    FM_Autotest_set_key_handlers();
}

static void FMAutoTestSlaveMicEnd(void)
{
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    SLAVE_MicTestOn = MTPNP_FALSE;
    FMTestReqSlaveOff(FMGetCurrentTest());
    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_SLAVE_MIC].name);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_RESULT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) EMFMUnicodeDisplayBuf, NULL);
    FM_Autotest_set_key_handlers();
}

void FMAutoTestSlaveReceiver(void)
{
    FMSetCurrentTest(FM_TEST_SLAVE_RECEIVER);
    Media_Stop();
    SLAVE_ReceiverTestOn = MTPNP_TRUE;
    FMTestReqSlaveOn(FMGetCurrentTest());
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, RECEIVER_DURATION, FMAutoTestSlaveReceiverEnd);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_ROOT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) GetString(STRING_MTPNP_FM_RECEIVER), NULL);
    FM_Autotest_set_key_handlers();
}

static void FMAutoTestSlaveReceiverEnd(void)
{

    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    SLAVE_ReceiverTestOn = MTPNP_FALSE;
    FMTestReqSlaveOff(FMGetCurrentTest());
    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_SLAVE_RECEIVER].name);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_RESULT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) EMFMUnicodeDisplayBuf, NULL);
    FM_Autotest_set_key_handlers();
}

void FMAutoTestSlaveSpeaker(void)
{
    FMSetCurrentTest(FM_TEST_SLAVE_SPEAKER);
    Media_Stop();
    SLAVE_SpeakerTestOn = MTPNP_TRUE;
    FMTestReqSlaveOn(FMGetCurrentTest());
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, SPEAKER_DURATION, FMAutoTestSlaveSpeakerEnd);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_ROOT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) GetString(STRING_MTPNP_FM_SPEAKER), NULL);
    FM_Autotest_set_key_handlers();
}

static void FMAutoTestSlaveSpeakerEnd(void)
{
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    FMTestReqSlaveOff(FMGetCurrentTest());
    SLAVE_SpeakerTestOn = MTPNP_FALSE;
    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_SLAVE_SPAKER].name);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_RESULT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) EMFMUnicodeDisplayBuf, NULL);
    FM_Autotest_set_key_handlers();
}

void FMAutoTestSlaveHeadset(void)
{
    Media_Stop();
    FMSetCurrentTest(FM_TEST_SLAVE_HEADSET);
    SLAVE_HeadsetTestOn = MTPNP_TRUE;
    FMTestReqSlaveOn(FMGetCurrentTest());
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER, HEADSET_DURATION, FMAutoTestSlaveHeadsetEnd);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_ROOT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) GetString(STRING_MTPNP_FM_HEADSET), NULL);
    FM_Autotest_set_key_handlers();
}

static void FMAutoTestSlaveHeadsetEnd(void)
{
    StopTimer(FM_AUTO_TEST_COMMNON_TIMER);
    SLAVE_HeadsetTestOn = MTPNP_FALSE;
    FMTestReqSlaveOff(FMGetCurrentTest());
    FM_Autotest_test_done_USC2string(Tests[FM_AUTOTEST_SLAVE_HEADSET].name);
    ShowCategory7Screen(STR_ID_FM_AUTO_TEST_RESULT, IMG_ID_FM_AUTO_TEST_ROOT,
                        STR_ID_FM_AUTO_TEST_PASS, IMG_GLOBAL_OK, STR_ID_FM_AUTO_TEST_FAIL,
                        IMG_GLOBAL_BACK, (MTPNP_UINT8 *) EMFMUnicodeDisplayBuf, NULL);
    FM_Autotest_set_key_handlers();
}

static void FM_Autotest_test_done_USC2string(const S8 * name)
{
    S8 name_ascii[MAX_TEST_ITEM_NAME_LEN];

    mmi_ucs2_to_asc((S8 *) name_ascii, (S8 *) name);

    sprintf((S8 *) EMFMAsciiDisplayBuf, "%s (%d/%d)\n", name_ascii, currTestItem + 1, gAutoTestListSize);

    mmi_asc_to_ucs2((S8 *) EMFMUnicodeDisplayBuf, (S8 *) EMFMAsciiDisplayBuf);

    mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, GetString(STR_GLOBAL_DONE));

    if (FMGetCurrentTest() == FM_TEST_SLAVE_COMM)
    {
        mmi_asc_to_ucs2((S8 *) EMFMAsciiDisplayBuf, "\n Test result:");
        mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, (S8 *) EMFMAsciiDisplayBuf);
        if (FMAutoTestSlaveCommResult == MTPNP_TRUE)
        {
            mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_PASS));
        }
        else
        {
            mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_FAIL));
        }
    }

    mmi_asc_to_ucs2((S8 *) EMFMAsciiDisplayBuf, ".\n\nSendkey: ");

    mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, (S8 *) EMFMAsciiDisplayBuf);

    mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_RETEST));

    mmi_asc_to_ucs2((S8 *) EMFMAsciiDisplayBuf, "\nEndkey: ");

    mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, (S8 *) EMFMAsciiDisplayBuf);

    mmi_ucs2cat((S8 *) EMFMUnicodeDisplayBuf, GetString(STR_ID_FM_AUTO_TEST_EXIT));
}

/* factory mode auto test end */

#endif /* __MMI_ENGINEER_MODE__ */

#endif /* __MMI_DUAL_SIM_MASTER__ && !__MMI_DUAL_SIM_SINGLE_CALL__ */

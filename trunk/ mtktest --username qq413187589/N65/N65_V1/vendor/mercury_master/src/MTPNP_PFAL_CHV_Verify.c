#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

/* MTK head files */
#include "wgui_status_icons.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "gui_data_types.h"
#include "GSM7BitDefaultAlphabet.h"
#include "wgui_categories_idlescreen.h"
#include "wgui_categories_popup.h"
#include "StatusIconRes.h"
#include "GlobalDefs.h"
#include "SettingProfile.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "HistoryGprot.h"
#include "CommonScreens.h"
#include "EventsGprot.h"
#include "GlobalConstants.h"
#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
#include "EventsGprot.h"
#include "wgui_categories_inputsenum.h"
#include "wgui_categories_inputs.h"
#include "ProfileGprots.h"
#include "Keybrd.h"
#include "PersonalizationDef.h"
#include "GlobalScrEnum.h"
#include "FlightModeGProt.h"
#include "CallManagementGProt.h"
#include "SettingGenum.h"
#include "SecuritySetup.h"
/* MTK head files */

/* MTPNP head files */
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_custom_hw.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_PFAL_CHV_Verify.h"
#include "MTPNP_PFAL_CC.h"
/* MTPNP head file */

MTPNP_CHAR g_slave_inputpwdbuffer[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
MTPNP_CHAR g_slave_inputNewpinbufferfirsttime[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];
MTPNP_CHAR g_slave_inputnewpinbuffersecondtime[MAX_PWD_LENGTH_MMI * ENCODING_LENGTH];

extern pBOOL isInCall(void);
extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
extern S32 mmi_is_redrawing_bk_screens(void);
extern void mmi_sim_error_hide_menu_items(void);

extern void EntryCard2SECSETPUK2(void);
extern void ExitCard2SECSETPUK2(void);

void MTPNP_PFAL_Clear_CHV_Input_Pwd(void)
{
    MTPNP_OSAL_memset((void*)g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    MTPNP_OSAL_memset((void*)g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    MTPNP_OSAL_memset((void*)g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
}

void MTPNP_PFAL_ClearAllKeyHandler(void)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}

void MTPNP_PFAL_Entry_IncorrectPIN(MTPNP_UINT8 type)
{
    U16 strid = 0;
    historyNode *History;

    switch (type)
    {
        case MTPNP_SIM_CHV1:
            strid = STRING_MTPNP_WRONG_CARD2_PIN;
            break;

        case MTPNP_SIM_CHV2:
            strid = STRING_MTPNP_WRONG_CARD2_PIN2;
            break;
    }

    DisplayPopup((MTPNP_UINT8*) GetString(strid), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (MTPNP_UINT8) ERROR_TONE);

    if (GetHistoryScrID(SCR_ENTERSLAVEPIN, &History) == ST_SUCCESS ||
        GetHistoryScrID(SCR_CARD2_SECSET_PIN2, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, 2);
        }
    }
}

void MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc(MTPNP_UINT8 *text, MTPNP_UINT8 *cursor, MTPNP_INT length)
{
    if ((length) < MIN_PASSWORD_LENGTH)
    {
        /* if length is short then disable lsk */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        /* if its valid length then enable lsk */
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(MTPNP_AD_Get_CB_CheckPwdLength(), KEY_POUND, KEY_EVENT_UP);
    }
}

void MTPNP_PFAL_SettingPukValidation(MTPNP_UINT8 *text, MTPNP_UINT8 *cursor, MTPNP_INT length)
{
    if ((length) < MMI_MIN_PUK_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetKeyHandler(MTPNP_AD_Get_CB_CheckPwdLength(), KEY_POUND, KEY_EVENT_UP);
    }
}

void MTPNP_PFAL_FillCountDownString(E_MTPNP_AD_SECURITYTYPE tpyeofpass, MTPNP_UINT8 *passcountdowndisp)
{
    MTPNP_CHAR temp1[10];
    MTPNP_CHAR temp2[20];

    if (passcountdowndisp == MTPNP_NULL)
        return;

    switch (tpyeofpass)
    {
        case MTPNP_AD_SETTING_TYPE_CHV1:
            sprintf(temp1, "%d", MTPNP_AD_Get_CHV1_Count());
            break;
        case MTPNP_AD_SETTING_TYPE_UBCHV1:
            sprintf(temp1, "%d", MTPNP_AD_Get_UBCHV1_Count());
            break;
        case MTPNP_AD_SETTING_TYPE_CHV2:
            sprintf(temp1, "%d", MTPNP_AD_Get_CHV2_Count());
            break;
        case MTPNP_AD_SETTING_TYPE_UBCHV2:
            sprintf(temp1, "%d", MTPNP_AD_Get_UBCHV2_Count());
            break;
    }

    MTPNP_PFAL_Ansii_To_Unicode_String(temp2, temp1);
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR*) passcountdowndisp, (MTPNP_CHAR*) GetString(STR_PASS_TRIALS_REMAIN));
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR*) passcountdowndisp, (MTPNP_CHAR*) temp2);
}

void MTPNP_PFAL_ShowMakeSOSCallScreen(void)
{
    ShowMakeSOSCallScr();
}

void MTPNP_PFAL_Cancel_SIM2_VerifyAndUnblock(void)
{
    if (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID)
    {
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_SIM_LOCK_PIN1);
        GoBackHistory();
    }
    else
    {
        DisplayConfirmCountDown(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STRING_MTPNP_CANCEL_CARD2PIN),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE,
            10,
            GoBackHistory);

        SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(MTPNP_PFAL_Cancel_SIM2_Verify, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

void MTPNP_PFAL_Cancel_SIM2_Verify(void)
{
    MTPNP_AD_SIM_PIN1_Verified_Finish();
    MTPNP_AD_Close_One_Cause_CancelPIN(MTPNP_FALSE);
    DeleteScreenIfPresent(SCR_ENTERSLAVEPIN);
    DeleteScreenIfPresent(SCR_CARD2_ENTER_PUK);
    DeleteScreenIfPresent(SCR_CARD2_ENTER_NEW_PIN);
    DeleteScreenIfPresent(SCR_CARD2_ENTER_CONFIRM_PIN);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_SIM_LOCK_PIN1);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
    GoBackHistory();
}

void MTPNP_PFAL_Cancel_SIM1_VerifyAndUnblock(void)
{
    if (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID)
    {
        DeleteUptoScrID(SCR_CARD2_SECSET_CHANGE_PASSWORD);
        GoBackHistory();
    }
    else
    {
        DisplayConfirmCountDown(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STRING_MTPNP_CANCEL_CARD1PIN),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE,
            10,
            GoBackHistory);

        SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(MTPNP_PFAL_Cancel_SIM1_Verify, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

void MTPNP_PFAL_Cancel_SIM1_Verify(void)
{
    MTPNP_AD_Close_One_Cause_CancelPIN(MTPNP_TRUE);
    DeleteScreenIfPresent(SCR_ENTER_PIN);
    DeleteScreenIfPresent(SCR_ENTER_PUK);
    DeleteScreenIfPresent(SCR_ENTER_NEW_PIN);
    DeleteScreenIfPresent(SCR_ENTER_CONFIRM_PIN);
    DeleteScreenIfPresent(SCR_ENTER_NP);
    DeleteScreenIfPresent(SCR_ENTER_NSP);
    DeleteScreenIfPresent(SCR_ENTER_CP);
    DeleteScreenIfPresent(SCR_ENTER_SP);
    DeleteScreenIfPresent(SCR_ENTER_SIMP);
#ifdef __MMI_SML_MENU__
    DeleteScreenIfPresent(SCR_ENTER_NS_SP);
    DeleteScreenIfPresent(SCR_ENTER_SIM_C);
#endif /* __MMI_SML_MENU__ */

    if (isInCall())
    {
        /* input PIN1 screen + incoming call + code accepted screen */
        mmi_frm_add_history_before_cm_marker(GLOBAL_SCR_DUMMY, mmi_bootup_exit_security_check);
    }
    else
    {
        /* input PIN1 screen + unfinished code accepted screen + incoming call */
        GenericExitScreen(GLOBAL_SCR_DUMMY, mmi_bootup_exit_security_check);
    }
}

MTPNP_UINT8 MTPNP_PFAL_Delete_EnterPIN_CB(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTPNP_AD_SIM_PIN1_Verified_Finish();
    return MMI_FALSE;
}

void MTPNP_PFAL_Exit_EnterPIN(void)
{
    history Scr;    /* Variable to hold the history data */

    Scr.scrnID = SCR_ENTERSLAVEPIN;
    Scr.entryFuncPtr = MTPNP_PFAL_Entry_EnterPIN;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) g_slave_inputpwdbuffer);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

void MTPNP_PFAL_Entry_EnterPIN(void)
{
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;
    MTPNP_UINT8 passcountdowndisp[MAX_PASS_COUNTDOWN_DISP];

    EntryNewScreen(SCR_ENTERSLAVEPIN, MTPNP_PFAL_Exit_EnterPIN, MTPNP_NULL, MTPNP_NULL);
    MTPNP_PFAL_ClearAllKeyHandler();

    g_pwr_context_2.PrevScreenIndicator = ENTER_PIN_SCR;

    if (!MTPNP_AD_SIM_PIN_Pwd_Is_Need_Save())
    {
        MTPNP_OSAL_memset((MTPNP_CHAR*) g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    MTPNP_AD_SIM_PIN_Pwd_Need_Save();

    guiBuffer = GetCurrGuiBuffer(SCR_ENTERSLAVEPIN);
    inputBuffer = GetCurrInputBuffer(SCR_ENTERSLAVEPIN);

    if (inputBuffer == NULL)
    {
        memset(g_slave_inputpwdbuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) g_slave_inputpwdbuffer, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);
    MTPNP_PFAL_FillCountDownString(MTPNP_AD_SETTING_TYPE_CHV1, passcountdowndisp);

    if (MTPNP_AD_Enable_Close_Card2PIN_Screen())
    {
        ShowCategory111Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_CANCEL,
            0,
            STRING_MTPNP_ENTER_CARD2PIN,
            INPUT_TYPE_NUMERIC_PASSWORD,
            (MTPNP_UINT8*) g_slave_inputpwdbuffer,
            MAX_PWD_LENGTH_MMI,
            passcountdowndisp,
            guiBuffer);

        SetCategory111RightSoftkeyFunction(MTPNP_PFAL_Cancel_SIM2_VerifyAndUnblock, KEY_EVENT_UP);
        SetKeyHandler(MTPNP_PFAL_GoTo_SOS_DialScr, KEY_SEND, KEY_EVENT_DOWN);
    }
    else
    {
        ShowCategory111Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_RSK_SOS,
            0,
            STRING_MTPNP_ENTER_CARD2PIN,
            INPUT_TYPE_NUMERIC_PASSWORD,
            (MTPNP_UINT8*) g_slave_inputpwdbuffer,
            MAX_PWD_LENGTH_MMI,
            passcountdowndisp,
            guiBuffer);

        if (mmi_bootup_get_active_flight_mode() == 1)
        {
            SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
        }
        else
        {
            SetCategory111RightSoftkeyFunction(MTPNP_PFAL_ShowMakeSOSCallScreen, KEY_EVENT_UP);
            SetKeyHandler(MTPNP_PFAL_GoTo_SOS_DialScr, KEY_SEND, KEY_EVENT_DOWN);
        }
    }

    MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_SIM_CHV1);
    SetLeftSoftkeyFunction(MTPNP_AD_Validate_CHV, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_AD_Validate_CHV, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(MTPNP_AD_Validate_CHV);
    if (MTPNP_PFAL_Unicode_String_Length((const MTPNP_CHAR*)g_slave_inputpwdbuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }

    SetDelScrnIDCallbackHandler(
        SCR_ENTERSLAVEPIN,
        (HistoryDelCBPtr) MTPNP_PFAL_Delete_EnterPIN_CB);
}

void MTPNP_PFAL_Entry_UnblockPIN(void)
{
    gSecuritySetupContext.PINBlocked_2 = 1;
    g_pwr_context_2.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;
    /* set the card2 status to work */
    MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_INVALID);

    if (mmi_secset_is_call_interrupt())
    {
        mmi_frm_add_history_before_cm_marker(SCR_CARD2_ENTER_PUK, MTPNP_PFAL_Entry_EnterPUK);
        return;
    }

    EntryNewScreen(SCR_POP_UP_HISTORY, MTPNP_PFAL_Exit_PINblocked, MTPNP_NULL, MTPNP_NULL);
    GenericExitScreen(SCR_CARD2_ENTER_PUK, MTPNP_PFAL_Entry_EnterPUK);
    ShowCategory123Screen(0, 0, 0, 0, 0, 0, STRING_MTPNP_PIN_BLOCKED_PUK, IMG_GLOBAL_WARNING, MTPNP_NULL);
    playRequestedTone(WARNING_TONE);
    MTPNP_PFAL_Start_Timer(CODE_VERIFIED_TIMER, CODE_VERIFIED_TIMEOUT, GoBackHistory);
    SetGroupKeyHandler(
        GoBackHistory,
        (MTPNP_UINT16*) PresentAllKeys,
        (MTPNP_UINT8) TOTAL_KEYS,
        (MTPNP_UINT16) KEY_EVENT_DOWN);

    DeleteScreenIfPresent(SCR_ENTERSLAVEPIN);
}

void MTPNP_PFAL_Exit_PINblocked(void)
{
    stopRequestedTone(WARNING_TONE);
    MTPNP_PFAL_Stop_Timer(CODE_VERIFIED_TIMER);
}

U8 MTPNP_PFAL_PUK_Delete_Handler(void *p)
{
    if (gSecuritySetupContext.PINBlocked_2 == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

void MTPNP_PFAL_Exit_EnterPUK(void)
{
    history Scr;    /* Variable to hold the history data */

    Scr.scrnID = SCR_CARD2_ENTER_PUK;
    Scr.entryFuncPtr = MTPNP_PFAL_Entry_EnterPUK;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) g_slave_inputpwdbuffer);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

void MTPNP_PFAL_Entry_EnterPUK(void)
{
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;
    MTPNP_UINT8 PassCountdownDisp[MAX_PASS_COUNTDOWN_DISP];

    EntryNewScreen(SCR_CARD2_ENTER_PUK, MTPNP_PFAL_Exit_EnterPUK, MTPNP_NULL, MTPNP_NULL);
    MTPNP_PFAL_ClearAllKeyHandler();

    g_pwr_context_2.PrevScreenIndicator = ENTER_PUK_SCR;

    if (!MTPNP_AD_SIM_PIN_Pwd_Is_Need_Save())
    {
        MTPNP_OSAL_memset((MTPNP_CHAR*) g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    MTPNP_AD_SIM_PIN_Pwd_Need_Save();

    gSecuritySetupContext.PINBlocked_2 = 1;
    g_pwr_context_2.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;
    /* set the card2 status to work */
    MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_INVALID);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_ENTER_PUK);
    inputBuffer = GetCurrInputBuffer(SCR_CARD2_ENTER_PUK);

    if (inputBuffer == NULL)
    {
        memset(g_slave_inputpwdbuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) g_slave_inputpwdbuffer, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(MTPNP_PFAL_SettingPukValidation);
    MTPNP_PFAL_FillCountDownString(MTPNP_AD_SETTING_TYPE_UBCHV1, PassCountdownDisp);

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (!mmi_is_redrawing_bk_screens())
#endif
    {
        sprintf(g_idle_context.DialPadCallBuffer, ""); /* reset dial pad for input * to start ssc */
    }

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_SETTING_SOS, //STR_GLOBAL_BACK,
        0, //IMG_GLOBAL_BACK,
        STRING_MTPNP_ENTER_CARD2PUK,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputpwdbuffer,
        MAX_PWD_LENGTH_MMI,
        PassCountdownDisp,
        guiBuffer);

    /* If this screen is deleted, call back function. */
    //SetDelScrnIDCallbackHandler(SCR_CARD2_ENTER_PUK, (HistoryDelCBPtr) MTPNP_PFAL_PUK_Delete_Handler);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Entry_EnterNewPIN_1st, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_Entry_EnterNewPIN_1st, KEY_POUND, KEY_EVENT_UP);
    SetKeyHandler(SSCHandleEnterPUKFromSecset2, KEY_STAR, KEY_EVENT_DOWN);

    if (mmi_bootup_get_active_flight_mode() == 1)
    {
        SetCategory111RightSoftkeyFunction(mmi_flight_mode_popup_in_dialing_sos, KEY_EVENT_UP);
    }
    else
    {
        SetCategory111RightSoftkeyFunction(MTPNP_PFAL_ShowMakeSOSCallScreen, KEY_EVENT_UP);
        SetKeyHandler(MTPNP_PFAL_GoTo_SOS_DialScr, KEY_SEND, KEY_EVENT_UP); 
    }

    MTPNP_AD_Set_CB_CheckPwdLength(MTPNP_PFAL_Entry_EnterNewPIN_1st);
    if (MTPNP_PFAL_Unicode_String_Length((const MTPNP_CHAR*)g_slave_inputpwdbuffer) < MMI_MIN_PUK_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

void MTPNP_PFAL_Entry_EnterNewPIN_1st(void)
{
    if (!MTPNP_AD_SIM_PIN_Pwd_Is_Need_Save())
    {
        MTPNP_OSAL_memset((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    else if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) < MMI_MIN_PUK_LENGTH)
    {
        if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) <= 0)
        {
            return;
        }
        else
        {
            MTPNP_OSAL_memset((MTPNP_CHAR*) g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
            MTPNP_PFAL_Show_Invalid_CHV_Length();
            return;
        }
    }
    MTPNP_AD_SIM_PIN_Pwd_Need_Save();

    EntryNewScreen(SCR_CARD2_ENTER_NEW_PIN, MTPNP_NULL, MTPNP_PFAL_Entry_EnterNewPIN_1st, MTPNP_NULL);
    MTPNP_PFAL_ClearAllKeyHandler();

    g_pwr_context_2.PrevScreenIndicator = ENTER_NEW_PIN;

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STRING_MTPNP_ENTER_CARD2_NEW_PIN,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputNewpinbufferfirsttime,
        MAX_PWD_LENGTH_MMI,
        MTPNP_NULL,
        MTPNP_NULL);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Entry_EnterNewPIN_2nd, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_Entry_EnterNewPIN_2nd, KEY_POUND, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(MTPNP_PFAL_Entry_EnterNewPIN_2nd);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime) < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

void MTPNP_PFAL_Entry_EnterNewPIN_2nd(void)
{
    if (!MTPNP_AD_SIM_PIN_Pwd_Is_Need_Save())
    {
        MTPNP_OSAL_memset((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    else if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime) <
             MMI_MIN_PASSWORD_LENGTH)
    {
        if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime) <= 0)
        {
            return;
        }
        else
        {
            MTPNP_OSAL_memset(
                (MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime,
                0,
                MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
            MTPNP_PFAL_Show_Invalid_CHV_Length();
            return;
        }
    }
    MTPNP_AD_SIM_PIN_Pwd_Need_Save();

    EntryNewScreen(SCR_CARD2_ENTER_CONFIRM_PIN, MTPNP_NULL, MTPNP_PFAL_Entry_EnterNewPIN_2nd, MTPNP_NULL);
    MTPNP_PFAL_ClearAllKeyHandler();

    g_pwr_context_2.PrevScreenIndicator = ENTER_CONFIRM_PIN;

    RegisterInputBoxValidationFunction(MTPNP_PFAL_RstrSettingPasswdScrSoftKeyFunc);

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STRING_MTPNP_ENTER_PIN_AGAIN,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (MTPNP_UINT8*) g_slave_inputnewpinbuffersecondtime,
        MAX_PWD_LENGTH_MMI,
        MTPNP_NULL,
        MTPNP_NULL);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Validate_1stAnd2ndPIN, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_Validate_1stAnd2ndPIN, KEY_POUND, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    MTPNP_AD_Set_CB_CheckPwdLength(MTPNP_PFAL_Validate_1stAnd2ndPIN);
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime) < MMI_MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

void MTPNP_PFAL_Validate_1stAnd2ndPIN(void)
{
    MTPNP_INT first_len, second_len;

    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime) < MMI_MIN_PASSWORD_LENGTH)
    {
        if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime) <= 0)
        {
            return;
        }
        else
        {
            MTPNP_OSAL_memset(
                (MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime,
                0,
                MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
            MTPNP_PFAL_Show_Invalid_CHV_Length();
            return;
        }
    }

    first_len = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime);
    second_len = MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime);

    if (first_len == second_len && memcmp(
            (MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime,
            (MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime,
            first_len * ENCODING_LENGTH) == 0)
    {
        MTPNP_AD_Set_SIM_CurrentPassword(MTPNP_SIM_CHV1);
        MTPNP_AD_Validate_PUK(g_slave_inputpwdbuffer, g_slave_inputNewpinbufferfirsttime);
    }
    else
    {
        MTPNP_PFAL_Entry_PIN_NotMatch();
    }
}

void MTPNP_PFAL_Entry_PIN_NotMatch(void)
{
    MTPNP_OSAL_memset((MTPNP_CHAR*) g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    MTPNP_OSAL_memset((MTPNP_CHAR*) g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    DisplayPopup(
        (MTPNP_UINT8*) GetString(STRING_MTPNP_CARD2_PIN_DONOT_MATCH),
        IMG_GLOBAL_ERROR,
        0,
        ST_NOTIFYDURATION,
        (MTPNP_UINT8) ERROR_TONE);
    DeleteUptoScrID(SCR_CARD2_ENTER_NEW_PIN);
}

void MTPNP_PFAL_Entry_IncorrectPUK(MTPNP_UINT8 type)
{
    historyNode *History;
    U16 strid = 0;
    U16 scrid = 0;

    extern S8 ssc_dialpad_buffer[];

    switch (type)
    {
        case MTPNP_SIM_CHV1:
            strid = STRING_MTPNP_INCORRECT_CARD2_PUK;
            scrid = SCR_CARD2_ENTER_PUK;
            break;

        case MTPNP_SIM_CHV2:
            strid = STRING_MTPNP_INCORRECT_CARD2_PUK2;
            scrid = SCR_CARD2_SECSET_PUK2;
            break;
    }

    DisplayPopup((MTPNP_UINT8*) GetString(strid), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, (U8) ERROR_TONE);
    mmi_ssc_delete_sim_operation_screens();

    if (!mmi_ssc_is_sim_operation((U8*) ssc_dialpad_buffer, MMI_UCS2_DCS) || IsScreenPresent(SCR_CARD2_ENTER_PUK) || IsScreenPresent(SCR_CARD2_SECSET_PUK2))
    {
        DeleteScreenIfPresent(SCR_ENTERSLAVEPIN);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_PUK);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_NEW_PIN);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_CONFIRM_PIN);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_SIM_LOCK_PIN1);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PIN2);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2);

        if (IsScreenPresent(GetCmMarkerScrnID()))
        {
            switch (type)
            {
                case MTPNP_SIM_CHV1:
                    mmi_frm_add_history_before_cm_marker(SCR_CARD2_ENTER_PUK, MTPNP_PFAL_Entry_EnterPUK);
                    break;

                case MTPNP_SIM_CHV2:
                    mmi_frm_add_history_before_cm_marker(SCR_CARD2_SECSET_PUK2, EntryCard2SECSETPUK2);
                    break;
            }
            return;
        }

        switch (type)
        {
            case MTPNP_SIM_CHV1:
                MTPNP_PFAL_Exit_EnterPUK();
                break;

            case MTPNP_SIM_CHV2:
                ExitCard2SECSETPUK2();
                break;
        }
    }

    if (GetHistoryScrID(scrid, &History) == ST_SUCCESS)
    {
        if (History->inputBuffer != NULL)
        {
            memset(History->inputBuffer, 0, ENCODING_LENGTH);
        }
        if (History->guiBuffer != NULL)
        {
            memset(History->guiBuffer, 0, 2);
        }
    }
}

void MTPNP_PFAL_Entry_Card2_Blocked(MTPNP_UINT8 type)
{
    if (type == MTPNP_SIM_CHV1)
    {
        /*
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_CARD2_SIM_BLOCK),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            (U8) ERROR_TONE);
        DeleteUptoScrID(IDLE_SCREEN_ID);
        */
        gSecuritySetupContext.PINBlocked_2 = 0;
        g_pwr_context_2.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;
        /* set the card2 status to work */
        MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_CHVBLOCKED);
        /* rearrange the menu item */
        MTPNP_PFAL_Rearrange_MenuItem();
        /* rearrange the status bar on idle screen */
        MTPNP_PFAL_Rearrange_StatusBar();
        mmi_sim_error_hide_menu_items();
        DisplayPopupCallBack(
            (PU8) GetString(STRING_MTPNP_CARD2_SIM_BLOCK),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE,
            mmi_idle_entry_dual_sim_root_screen);
    }
    else if (type == MTPNP_SIM_CHV2)
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STR_ID_PIN2_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            0,
            ST_NOTIFYDURATION,
            (U8) ERROR_TONE);
        DeleteNScrId(SCR_CARD2_SECSETMAIN);
    }
}

void MTPNP_PFAL_Delete_ScreenBeforeUnblockPIN(void)
{
    DeleteUptoScrID(SCR_ENTERSLAVEPIN);
    DeleteScreenIfPresent(SCR_ENTERSLAVEPIN);
    GoBackHistory();
}

void MTPNP_PFAL_Entry_SIM2_Verified_Screen(void)
{
    gSecuritySetupContext.PINBlocked_2 = 0;
    g_pwr_context_2.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;
    /* set the card2 status to work */
    MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_VALID);

    if (MTPNP_AD_Is_During_Mode_Switch())
    {
        /* entry switch progress screen */
        DeleteScreenIfPresent(SCR_ENTERSLAVEPIN);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_PUK);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_NEW_PIN);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_CONFIRM_PIN);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_SIM_LOCK_PIN1);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
        EntryDualModeSwitchProgress();
    }
    else
    {
        DisplayPopup(
            (MTPNP_UINT8*) GetString(STRING_MTPNP_CODE_VERIFIED),
            IMG_GLOBAL_ACTIVATED,
            0,
            2000,
            (MTPNP_UINT8) SUCCESS_TONE);
/*
        if (IsScreenPresent(SCR_CARD2_ENTER_PUK))
        {
            if (IsScreenPresent(SCR_SIM_BLOCK))
            {
                DeleteUptoScrID(SCR_SIM_BLOCK);
            }
            else if (IsScreenPresent(SCR_SIM_INSERTION))
            {
                DeleteUptoScrID(SCR_SIM_INSERTION);
            }
            else
            {
                DeleteUptoScrID(IDLE_SCREEN_ID);
            }
            return;
        }
*/
        DeleteScreenIfPresent(SCR_ENTERSLAVEPIN);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_PUK);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_NEW_PIN);
        DeleteScreenIfPresent(SCR_CARD2_ENTER_CONFIRM_PIN);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_SIM_LOCK_PIN1);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_OLD_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_NEW_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_CHANGEPW_CFM_PWD);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PIN2);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
        DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2);

        /* unlock PUK by SSC */
        mmi_ssc_delete_sim_operation_screens();
    }
}

void MTPNP_PFAL_Entry_SIM1_Verified_Screen(void)
{
    DeleteScreenIfPresent(SCR_ENTER_PIN);
    DeleteScreenIfPresent(SCR_ENTER_PUK);
    DeleteScreenIfPresent(SCR_ENTER_NEW_PIN);
    DeleteScreenIfPresent(SCR_ENTER_CONFIRM_PIN);
    DeleteScreenIfPresent(SCR_ENTER_NP);
    DeleteScreenIfPresent(SCR_ENTER_NSP);
    DeleteScreenIfPresent(SCR_ENTER_CP);
    DeleteScreenIfPresent(SCR_ENTER_SP);
    DeleteScreenIfPresent(SCR_ENTER_SIMP);
#ifdef __MMI_SML_MENU__
    DeleteScreenIfPresent(SCR_ENTER_NS_SP);
    DeleteScreenIfPresent(SCR_ENTER_SIM_C);
#endif /* __MMI_SML_MENU__ */

    EntryDualModeSwitchProgress();
}

void MTPNP_PFAL_Show_Invalid_CHV_Length(void)
{
    DisplayPopup(
        (MTPNP_UINT8*) GetString(STR_INVALID_PINPUKPLOCK_LENGTH_RUNNING_TEXT),
        IMG_GLOBAL_WARNING,
        0,
        2000,
        (MTPNP_UINT8) ERROR_TONE);
}

MTPNP_BOOL MTPNP_PFAL_Get_CHV_Value(MTPNP_CHAR *chv_value)
{
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) < MMI_MIN_PASSWORD_LENGTH)
    {
        if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR*) g_slave_inputpwdbuffer) <= 0)
        {
            return MTPNP_FALSE;
        }
        else
        {
            memset((MTPNP_CHAR*) g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
            MTPNP_PFAL_Show_Invalid_CHV_Length();
            return MTPNP_FALSE;
        }
    }
    ClearAllKeyHandler();

    MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR*) chv_value, (MTPNP_CHAR*) g_slave_inputpwdbuffer);

    return MTPNP_TRUE;
}


void MTPNP_PFAL_GoTo_SOS_DialScr(void)
{
    historyNode *History;

    if (g_pwr_context_2.PrevScreenIndicator == ENTER_NEW_PIN)
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) g_slave_inputNewpinbufferfirsttime);
        memset((S8*) g_slave_inputNewpinbufferfirsttime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    else if (g_pwr_context_2.PrevScreenIndicator == ENTER_CONFIRM_PIN)
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) g_slave_inputnewpinbuffersecondtime);
        memset((S8*) g_slave_inputnewpinbuffersecondtime, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, (S8*) g_slave_inputpwdbuffer);
        memset((S8*) g_slave_inputpwdbuffer, 0, MAX_PWD_LENGTH_MMI * ENCODING_LENGTH);

        if (g_idle_context.DialPadCallBuffer[0] != '\0')
        {
            EntryNewScreen(SCR_ID_PASSWORD_INPUT_DUMMY, NULL, NULL, NULL);

            if (GetHistoryScrID(SCR_ENTERSLAVEPIN, &History) == ST_SUCCESS ||
                GetHistoryScrID(SCR_CARD2_ENTER_PUK, &History) == ST_SUCCESS)
            {
                if (History->inputBuffer != NULL)
                {
                    memset(History->inputBuffer, 0, ENCODING_LENGTH);
                }
                if (History->guiBuffer != NULL)
                {
                    memset(History->guiBuffer, 0, 2);
                }
            }
        }
    }

    EntryScrEmergencyCallDialing();
}

void MTPNP_PFAL_ATCmd_Update_Chv(void *info)
{
    mmi_smu_verify_pin_result_ind_struct *at_verify_pin_ind = (mmi_smu_verify_pin_result_ind_struct *)info;

    switch (at_verify_pin_ind->next_type)
    {
        case MMI_SETTING_TYPE_NO_REQUIRED:
            if (gSecuritySetupContext.PINBlocked_2)
            {
                gSecuritySetupContext.PINBlocked_2 = 0;
                g_pwr_context_2.PowerOnSIMStatus &= ~MMI_SIM_STATUS_INVALID;  /* 0x01: Invalid SIM */
                /* set the card2 status to work */
                MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_VALID);
                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                DeleteScreenIfPresent(SCR_CARD2_ENTER_PUK);
                DeleteScreenIfPresent(SCR_CARD2_ENTER_NEW_PIN);
                DeleteScreenIfPresent(SCR_CARD2_ENTER_CONFIRM_PIN);
            }
            break;

        case MMI_SETTING_TYPE_UBCHV1:
            if (gSecuritySetupContext.PINBlocked_2)
            {
                MTPNP_PFAL_Entry_IncorrectPUK(MTPNP_SIM_CHV2);
            }
            else
            {
                memset(g_slave_inputpwdbuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1) * ENCODING_LENGTH);
                MTPNP_PFAL_Entry_UnblockPIN();
            }
            break;

        case MMI_SETTING_TYPE_SIM_CARD_BLOCKED:
            gSecuritySetupContext.PINBlocked_2 = 0;
            g_pwr_context_2.PowerOnSIMStatus |= MMI_SIM_STATUS_INVALID;
            /* set the card2 status to work */
            MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_CHVBLOCKED);
            /* rearrange the menu item */
            MTPNP_PFAL_Rearrange_MenuItem();
            /* rearrange the status bar on idle screen */
            MTPNP_PFAL_Rearrange_StatusBar();
            mmi_idle_entry_dual_sim_root_screen();
            break;

        default:
            break;
    }
}

#endif /* __MMI_DUAL_SIM_MASTER__ */


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
#include "SettingDefs.h"
#include "SettingProfile.h"
#include "PhoneBookTypes.h"
#include "MessagesMiscell.h"
#include "Wgui_title.h"
#include "Wgui_categories_popup.h"
#include "wgui_categories_inputs.h"

#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_CallsCost.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_AD_resdef.h"

extern U16 SetTitleStrings[2];
static ST_MTPNP_CALLCOST_INFO CallCost_info;
static double tempPpuValue;
static unsigned char tempCuCode[3];
static MTPNP_UINT8 g_slave_curr_call_cost_index;

void MTPNP_PFAL_CallsCost_Init(void)
{
    SetHiliteHandler(MENU_MTPNP_CALL_HISTORY_CALLCOST, HighlightSlaveCHISTCallCost);
    SetHiliteHandler(MENU_MTPNP_CALL_COST_LASTCALL, HighlightSlaveCHISTLastCost);
    SetHiliteHandler(MENU_MTPNP_CALL_COST_ALLCOST, HighlightSlaveCHISTAllCost);
    SetHiliteHandler(MENU_MTPNP_CALL_COST_PRICEUNIT, HighlightSlaveCHISTPriceAndUnit);
    SetHiliteHandler(MENU_MTPNP_CALL_COST_RESETCOUNTER, HighlightSlaveCHISTResetCost);
    SetHiliteHandler(MENU_MTPNP_CALL_COST_MAXCOUNT, HighlightSlaveCHISTMaxCost);

    SetHintHandler(MENU_MTPNP_CALL_COST_LASTCALL, HintSlaveCHISTLastCost);
    SetHintHandler(MENU_MTPNP_CALL_COST_ALLCOST, HintSlaveCHISTAllCost);
    SetHintHandler(MENU_MTPNP_CALL_COST_PRICEUNIT, HintSlaveCHISTPriceAndUnit);
    SetHintHandler(MENU_MTPNP_CALL_COST_MAXCOUNT, HintSlaveCHISTMaxCost);
}

void HighlightSlaveCHISTCallCost(void)
{
    MTPNP_PFAL_Set_Call_Cost_Hilite_Index(0);
    SetKeyHandler(MTPNP_PFAL_CHISTGetAOC, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(MTPNP_PFAL_CHISTGetAOC, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTLastCost(void)
{
    MTPNP_PFAL_Set_Call_Cost_Hilite_Index((MTPNP_UINT8) GetCurrHiliteID());
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTAllCost(void)
{
    MTPNP_PFAL_Set_Call_Cost_Hilite_Index((MTPNP_UINT8) GetCurrHiliteID());
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTPriceAndUnit(void)
{
    MTPNP_PFAL_Set_Call_Cost_Hilite_Index((MTPNP_UINT8) GetCurrHiliteID());
    ChangeLeftSoftkey(STR_CALL_COST_PRICEANDUNIT_VIEW_LSK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    MTPNP_AD_Set_CHV_Pass_CB(RspSIM2Pin2ForCallCostSetPUCTSuccess);
    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_CHV2, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTResetCost(void)
{
    MTPNP_PFAL_Set_Call_Cost_Hilite_Index((MTPNP_UINT8) GetCurrHiliteID());
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    MTPNP_AD_Set_CHV_Pass_CB(MTPNP_CARD2_CAI_ResetCallCostReq);
    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_CHV2, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

void HighlightSlaveCHISTMaxCost(void)
{
    MTPNP_PFAL_Set_Call_Cost_Hilite_Index((MTPNP_UINT8) GetCurrHiliteID());
    ChangeLeftSoftkey(STR_CALL_COST_PRICEANDUNIT_VIEW_LSK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    MTPNP_AD_Set_CHV_Pass_CB(RspSIM2Pin2ForCallCostSetMaxCostSuccess);
    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_CHV2, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


void HintSlaveCHISTLastCost(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    U32 ccm = MTPNP_AD_GetCCM();
    if ((ccm % 1000) != 0)
    {
        sprintf((S8 *) value, "%u.%u", ccm / 1000, ccm % 1000);
    }
    else
    {
        sprintf((S8 *) value, "%u", ccm / 1000);
    }

    mmi_asc_to_ucs2((S8 *) hintData[index], (S8 *) value);
}

void HintSlaveCHISTAllCost(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    U32 Acm = MTPNP_AD_GetACM();

    sprintf((S8 *) value, "%u", Acm);

    mmi_asc_to_ucs2((S8 *) hintData[index], (S8 *) value);
}

void HintSlaveCHISTPriceAndUnit(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    U32 ppu = (U32) MTPNP_AD_GetPPU();
    U8 *ppu_cur_code = MTPNP_AD_GetPPUCode();
    if (MTPNP_AD_GetPPU() - ppu == 0)
        sprintf((S8 *) value, "%u\0", (U32) MTPNP_AD_GetPPU());
    else
        sprintf((S8 *) value, "%u.%03d\0", ppu, (U32) ((MTPNP_AD_GetPPU() - ppu) * 1000));

    if (ppu_cur_code[0] != 0)
    {
        strcat((S8*) value, " ");
        strncat((S8 *) value, (S8 *) ppu_cur_code, 3);
    }
    mmi_asc_to_ucs2((S8 *) hintData[index], (S8 *) value);
}

void HintSlaveCHISTMaxCost(U16 index)
{
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    U32 ACM_Max = MTPNP_AD_GetACMMAX();

    kal_mem_set(value, 0, MAX_SUB_MENU_HINT_SIZE);
    kal_mem_set((S8 *) hintData[index], 0, MAX_SUB_MENU_HINT_SIZE);
    sprintf((S8 *) value, "%u", ACM_Max);
    mmi_asc_to_ucs2((S8 *) hintData[index], (S8 *) value);
}

void MTPNP_PFAL_Set_Call_Cost_Hilite_Index(MTPNP_UINT8 index)
{
    g_slave_curr_call_cost_index = index;
}

void RspSIM2Pin2ForCallCostSetMaxCostSuccess(void)
{
    DisplayPopup(
        (PU8) GetString(STR_SETTING_CODE_VERIFIED),
        IMG_GLOBAL_ACTIVATED,
        1,
        CS_NOTIFYDURATION,
        SUCCESS_TONE);
    MTPNP_CARD2_CAI_ResetMaxCost();
}

void RspSIM2Pin2ForCallCostSetPUCTSuccess(void)
{
    DisplayPopup(
        (PU8) GetString(STR_SETTING_CODE_VERIFIED),
        IMG_GLOBAL_ACTIVATED,
        1,
        CS_NOTIFYDURATION,
        SUCCESS_TONE);
    MTPNP_CARD2_EntryCHISTSetPriceUnit();
}

void MTPNP_CARD2_ExitCHISTSetPriceUnit(void)
{
    history currHistory;
    U16 inputBufferSize;        //added for inline edit history
    S16 nHistory = 0;

    CloseCategory57Screen();
    currHistory.scrnID = SCR_MTPNP_CALL_COST_PRICEANDUNIT_SET;
    currHistory.entryFuncPtr = MTPNP_CARD2_EntryCHISTSetPriceUnit;
    mmi_ucs2cpy((S8 *) currHistory.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);

    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8 *) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
    return;
}

void MTPNP_PFAL_CHISTGetAOC(void)
{
    AlmDisableExpiryHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);    
    MTPNP_AD_CHISTGetAOC();
}

double MTPNP_PFAL_Get_CAI_TempPPU(void)
{
    return tempPpuValue;
}

MTPNP_CHAR *MTPNP_PFAL_Get_CAI_TempCuCode(void)
{
    return (MTPNP_CHAR *) tempCuCode;
}

void MTPNP_PFAL_Update_CallCost_PUCT(void)
{
    MTPNP_AD_REQ_RESET_CALLCOST_SCT puct;
    U8 tempPPU[20];

    mmi_ucs2_to_asc((S8 *) puct.currency, (S8 *) CallCost_info.newCurrencyStr);
    mmi_ucs2_to_asc((S8 *) puct.ppu, (S8 *) CallCost_info.newPPUStr);
    tempPpuValue = atof((char *) tempPPU);
    strncpy((char *) tempCuCode, (char *) tempPPU, 3);

    MTPNP_AD_ResetCallCost_PUCT_Req(&puct);
}

void MTPNP_CARD2_EntryCHISTSetPriceUnitConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_GLOBAL_SAVE_ASK), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Update_CallCost_PUCT, KEY_EVENT_UP);
    SetRightSoftkeyFunction(MTPNP_CARD2_CHISTGoBackCallCostHistory, KEY_EVENT_UP);
    return;
}

void MTPNP_CARD2_CHISTValidatePriceUnit(void)
{
    U8 count = 0, num = 0;
    U8 temp_ppu[40];
    MTPNP_BOOL is_valid_str = MTPNP_TRUE;

    CloseCategory57Screen();
    mmi_ucs2_to_asc((S8 *) temp_ppu, (S8 *) CallCost_info.newPPUStr);

    while (temp_ppu[count] != 0)
    {
        if (temp_ppu[count] <= '9' && temp_ppu[count] >= '0')
        {
            num++;
        }
        if (temp_ppu[count++] == '.')
        {
            break;
        }
    }
    /* overflow */
    if ((count > 9 && num > 9) || count == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ALL_CALL_COSTS_ERROR_MSG),
            IMG_GLOBAL_WARNING,
            0,
            CS_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }

    /* check price unit */
    for (count = 0; count < 3; count++)
    { 
        if (CallCost_info.newCurrencyStr[2 * count] == '\0')
        {
            break;
        }
        if((CallCost_info.newCurrencyStr[2*count] == '.') || (CallCost_info.newCurrencyStr[2*count] == ',') || 
            (CallCost_info.newCurrencyStr[2*count] == '-') || (CallCost_info.newCurrencyStr[2*count] == '?') ||
            (CallCost_info.newCurrencyStr[2*count] == '!') || (CallCost_info.newCurrencyStr[2*count] == '\'') ||
            (CallCost_info.newCurrencyStr[2*count] == '@') || (CallCost_info.newCurrencyStr[2*count] == ':') ||
            (CallCost_info.newCurrencyStr[2*count] == '#') || (CallCost_info.newCurrencyStr[2*count] == '/') ||
            (CallCost_info.newCurrencyStr[2*count] == '_') || 
            ((CallCost_info.newCurrencyStr[2*count] >= '0') && (CallCost_info.newCurrencyStr[2*count] <= '9')))
        {
            is_valid_str = MTPNP_FALSE;
            break;
        }
    }
    
    if (!is_valid_str)
    {
        DisplayPopup(
            (PU8) GetString(STR_ALL_CALL_COSTS_ERROR_MSG),
            IMG_GLOBAL_WARNING,
            0,
            CS_NOTIFYDURATION,
            WARNING_TONE);
    }
    else
    {
        MTPNP_CARD2_EntryCHISTSetPriceUnitConfirm();
    }

    return;
}

void MTPNP_CARD2_HighlightPriceAndUnitHandler(S32 index)
{
    ChangeTitleString((PU8) GetString(SetTitleStrings[index]));
    draw_title();

    SetLeftSoftkeyFunction(MTPNP_CARD2_CHISTValidatePriceUnit, KEY_EVENT_UP);
}

void MTPNP_CARD2_EntryCHISTSetPriceUnit(void)
{
    U8 *guiBuffer;              /* Buffer holding history data */
    U8 *inputBuffer;            /* added for inline edit history */
    U16 inputBufferSize;        /* added for inline edit history */
    U16 DetailPriceUnitImageList[3];

    EntryNewScreen(SCR_MTPNP_CALL_COST_PRICEANDUNIT_SET, MTPNP_CARD2_ExitCHISTSetPriceUnit, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_CALL_COST_PRICEANDUNIT_SET);

    mmi_asc_to_ucs2((S8 *) CallCost_info.newCurrencyStr, (S8 *) MTPNP_AD_GetPPUCode());
    mmi_asc_to_ucs2((S8 *) CallCost_info.newPPUStr, (S8 *) MTPNP_AD_GetPPUStr());

    InitializeCategory57Screen();
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[0], (PU8) CallCost_info.newPPUStr, 20, INPUT_TYPE_DECIMAL_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[0]);
    SetTitleStrings[0] = STRING_MTPNP_MENU_CALL_COST_PRICEANDUNIT_SET_PRICE;
    DetailPriceUnitImageList[0] = IMG_GLOBAL_L1;
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8) CallCost_info.newCurrencyStr, 4,
                          INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    DisableInlineItemHighlight(&wgui_inline_items[1]);
    SetTitleStrings[1] = STRING_MTPNP_MENU_CALL_COST_PRICEANDUNIT_SET_UNIT;
    DetailPriceUnitImageList[1] = IMG_GLOBAL_L2;

    inputBuffer = GetCurrNInputBuffer(SCR_MTPNP_CALL_COST_PRICEANDUNIT_SET, &inputBufferSize);

    RegisterHighlightHandler(MTPNP_CARD2_HighlightPriceAndUnitHandler);

    if ((guiBuffer != NULL) && (guiBuffer[0] != 0))
    {
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);
    }
    DisableCategory57ScreenDone();

    ShowCategory57Screen(STRING_MTPNP_MENU_SCR_CALL_COST_PRICEANDUNIT_SET,
                         IMG_MTPNP_SCR_CALL_COST_PRICEANDUNIT_SET_CAPTION,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, 2, DetailPriceUnitImageList, wgui_inline_items, 0, guiBuffer);

    SetCategory57RightSoftkeyFunctions(MTPNP_CARD2_CHISTValidatePriceUnit, MTPNP_CARD2_CHISTGoBackCallCostHistory);

    return;
}


void MTPNP_CARD2_CAI_ResetCallCostReq(void)
{
    MTPNP_AD_CHISTResetCallCost();
}


void MTPNP_CARD2_CHISTGoBackCallCostHistory(void)
{
    GoBackToHistory(SCR_MTPNP_CALL_COST_MAIN);
}

void MTPNP_CARD2_CAI_SetAcmMaxReq(void)
{
    U8 tempMaxCost[10];
    unsigned long newMaxCost;
    mmi_ucs2_to_asc((S8 *) tempMaxCost, (S8 *) CallCost_info.newMaxCostStr);
    newMaxCost = atoi((S8 *) tempMaxCost);
    MTPNP_AD_CHISTResetMaxCost(newMaxCost);
}

void MTPNP_CARD2_EntryCHISTSetMaxCostConfirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_GLOBAL_SAVE_ASK), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_CARD2_CAI_SetAcmMaxReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(MTPNP_CARD2_CHISTGoBackCallCostHistory, KEY_EVENT_UP);
    return;
}

void MTPNP_CARD2_CHISTValidateMaxCost(void)
{
    if (!mmi_ucs2strlen((S8*) CallCost_info.newMaxCostStr) > 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ALL_CALL_COSTS_ERROR_MSG),
            IMG_GLOBAL_WARNING,
            0,
            CS_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }

    MTPNP_CARD2_EntryCHISTSetMaxCostConfirm();
    return;
}

void MTPNP_CARD2_ExitCHISTSetMaxCost(void)
{
    history Scr;                /* Variable to hold the history data */
    S16 nHistory = 0;

    Scr.scrnID = SCR_MTPNP_COST_SET;
    Scr.entryFuncPtr = MTPNP_CARD2_CAI_ResetMaxCost;
    mmi_ucs2cpy((S8 *) Scr.inputBuffer, (S8 *) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
    return;
}

void MTPNP_CARD2_CAI_ResetMaxCost(void)
{
    U8 *guiBuffer;
    U8 maxCost[10 *ENCODING_LENGTH];

    PRINT_INFORMATION("File: [%s]  Line: [%d] <<EntryScr104PbookNumberEdit.>\n", __FILE__, __LINE__);

    EntryNewScreen(SCR_MTPNP_COST_SET, MTPNP_CARD2_ExitCHISTSetMaxCost, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_COST_SET);

    if (guiBuffer == NULL)
    {
        sprintf((S8*) maxCost, "%u", MTPNP_AD_GetACMMAX());
        mmi_asc_to_ucs2((S8 *) CallCost_info.newMaxCostStr, (S8 *) maxCost);
    }
    ShowCategory5Screen(STRING_MTPNP_MAX_COST_SET_CAPTION,
                        IMG_MTPNP_SCR_MAX_COST_GET_CAPTION, STR_GLOBAL_OK,
                        IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                        INPUT_TYPE_NUMERIC, (PU8) CallCost_info.newMaxCostStr, 8, guiBuffer);

    SetLeftSoftkeyFunction(MTPNP_CARD2_CHISTValidateMaxCost, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(MTPNP_CARD2_CHISTGoBackCallCostHistory, KEY_EVENT_UP);
    return;
}


void EntrySlaveCHISTCallCost(void)
{
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    U8 *displayBuffer[MAX_SUB_MENUS];
    EntryNewScreen(SCR_MTPNP_CALL_COST_MAIN, NULL, MTPNP_AD_CHISTGetAOC, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_CALL_COST_MAIN);
    nNumofItem = GetNumOfChild(MENU_MTPNP_CALL_HISTORY_CALLCOST);
    GetSequenceStringIds(MENU_MTPNP_CALL_HISTORY_CALLCOST, nStrItemList);
    SetParentHandler(MENU_MTPNP_CALL_HISTORY_CALLCOST);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_MTPNP_CALL_HISTORY_CALLCOST, displayBuffer);

    ShowCategory52Screen(STR_MENU_CALL_COST_MAIN, IMG_SCR_CALL_COST_MAIN_CAP,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, nNumofItem, nStrItemList,
                         (U16 *) gIndexIconsImageList, displayBuffer, 0, g_slave_curr_call_cost_index, guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}

void MTPNP_PFAL_handle_GetAOCFinish(void)
{
    if (MTPNP_AD_GetAOCFinish() == 0)
    {
        return;
    }

    if (MTPNP_AD_GetAOCError() != 0)
    {
        kal_prompt_trace(MOD_MMI, "call cost file error");
    }

    /* because some call cost related files are optional,
       so we should allow user to enter call cost
       no matter MTPNP_AD_GetAOCError() is 0 or not */

    AlmEnableExpiryHandler();
    EntrySlaveCHISTCallCost();
}

void MTPNP_PFAL_handle_DelAOCSuccess(void)
{
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SAVE_TONE);
    DeleteUptoScrID(SCR_MTPNP_CALL_COST_MAIN);
}

void MTPNP_PFAL_handle_DelAOCFailed(void)
{
    DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    DeleteUptoScrID(SCR_MTPNP_CALL_COST_MAIN);
}

MTPNP_UINT MTPNP_PFAL_handle_UpdateACMMAXSuccess(void)
{
    MTPNP_UINT8 tempMaxCost[10];
    MTPNP_UINT acmmax;
    MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *) tempMaxCost, (MTPNP_CHAR *) CallCost_info.newMaxCostStr);
    acmmax = atoi((MTPNP_CHAR *) tempMaxCost);

    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SAVE_TONE);
    DeleteUptoScrID(SCR_MTPNP_CALL_COST_MAIN);
    return acmmax;
}

void MTPNP_PFAL_handle_UpdateACMMAXFailed(void)
{
    DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    DeleteUptoScrID(SCR_MTPNP_CALL_COST_MAIN);
}

void MTPNP_PFAL_handle_ReadError(void)
{
    GoBackHistory();
    DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, CS_NOTIFYDURATION, ERROR_TONE);
}

void MTPNP_PFAL_Show_CAI_processing(void)
{
    EntryNewScreen(SCR_MTPNP_CH_OP_WAITING, NULL, NULL, NULL);


    ShowCategory8Screen(STRING_MTPNP_MENU_SIM2_CALL_COST_MAIN, IMG_MTPNP_CARD2_CALL_COST_MAIN_MENU,
                        0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                        STRING_MTPNP_MENU_CALL_COST_PROCESSING, IMG_MTPNP_SCR_CALL_COST_PROCESS, NULL);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_Update_PUCT_handler_Success(void)
{
    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SAVE_TONE);
    DeleteUptoScrID(SCR_MTPNP_CALL_COST_MAIN);

}

void MTPNP_PFAL_Update_PUCT_handler_Unavaialable(void)
{
    DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 1, CS_NOTIFYDURATION, ERROR_TONE);
    DeleteUptoScrID(SCR_MTPNP_CALL_COST_MAIN);

}

void MTPNP_PFAL_Update_PUCT_handler_Failed(void)
{
    DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    DeleteUptoScrID(SCR_MTPNP_CALL_COST_MAIN);

}

#endif /* __MMI_DUAL_SIM_MASTER__ */

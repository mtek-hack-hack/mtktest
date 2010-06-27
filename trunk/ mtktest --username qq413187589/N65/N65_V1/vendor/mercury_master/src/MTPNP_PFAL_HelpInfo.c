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
#include "FactoryModeDef.h"
#include "CustDataRes.h"

#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_HelpInfo.h"

extern MTPNP_CHAR UnicodeDisplayBuf[MAX_TEST_STRING_BUF * 4];

void HightlightShowMTPNPHelpInfo(void)
{
    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();
    SetLeftSoftkeyFunction(EntryShowMTPNPHelpInfo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void EntryShowMTPNPHelpInfo(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 tempbuf[MAX_TEST_STRING_BUF * 2];
    MTPNP_UINT8 AsciiDisplayBuf[MAX_TEST_STRING_BUF];
    ST_MTPNP_AD_VERSION mtpnp_version;

    EntryNewScreen(SCR_DMHELPINFO, MTPNP_NULL, EntryShowMTPNPHelpInfo, MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_DMHELPINFO);
    SetParentHandler(MENU_MTPNP_HELPINFO);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    MTPNP_AD_Get_Revision(&mtpnp_version);

    MTPNP_OSAL_memset(UnicodeDisplayBuf, 0, sizeof(UnicodeDisplayBuf));

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) AsciiDisplayBuf, "[SDK master]");
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) AsciiDisplayBuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((MTPNP_CHAR *) AsciiDisplayBuf, " %06d\n", (MTPNP_CHAR *) mtpnp_version.master_sdk_revision);
    MTPNP_OSAL_memset(tempbuf, 0, sizeof(tempbuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) tempbuf, (MTPNP_CHAR *) AsciiDisplayBuf);
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) tempbuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) AsciiDisplayBuf, "[SDK slave]");
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) AsciiDisplayBuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((MTPNP_CHAR *) AsciiDisplayBuf, " %06d\n", (MTPNP_CHAR *) mtpnp_version.slave_sdk_revision);
    MTPNP_OSAL_memset(tempbuf, 0, sizeof(tempbuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) tempbuf, (MTPNP_CHAR *) AsciiDisplayBuf);
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) tempbuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) AsciiDisplayBuf, "[AD master]");
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) AsciiDisplayBuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((MTPNP_CHAR *) AsciiDisplayBuf, " %06d\n", (S8 *) mtpnp_version.master_adapter_revision);
    MTPNP_OSAL_memset(tempbuf, 0, sizeof(tempbuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) tempbuf, (MTPNP_CHAR *) AsciiDisplayBuf);
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) tempbuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) AsciiDisplayBuf, "[AD slave]");
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) AsciiDisplayBuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((MTPNP_CHAR *) AsciiDisplayBuf, " %06d\n", (MTPNP_CHAR *) mtpnp_version.slave_adapter_revision);
    MTPNP_OSAL_memset(tempbuf, 0, sizeof(tempbuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) tempbuf, (MTPNP_CHAR *) AsciiDisplayBuf);
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) tempbuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) AsciiDisplayBuf, "[Register state]");
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) AsciiDisplayBuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    if (MTPNP_AD_SW_Need_Register())
    {
        sprintf((MTPNP_CHAR *) AsciiDisplayBuf, " Unregistered\n");
    }
    else
    {
        sprintf((MTPNP_CHAR *) AsciiDisplayBuf, " Registered\n");
    }
    MTPNP_OSAL_memset(tempbuf, 0, sizeof(tempbuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) tempbuf, (MTPNP_CHAR *) AsciiDisplayBuf);
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) tempbuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) AsciiDisplayBuf, "[Register code]\n");
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) AsciiDisplayBuf);

    MTPNP_OSAL_memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((MTPNP_CHAR *) AsciiDisplayBuf, " %s\n", (MTPNP_CHAR *) mtpnp_version.register_value);
    MTPNP_OSAL_memset(tempbuf, 0, sizeof(tempbuf));
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) tempbuf, (MTPNP_CHAR *) AsciiDisplayBuf);
    MTPNP_PFAL_Unicode_Strcat((MTPNP_CHAR *) UnicodeDisplayBuf, (const MTPNP_CHAR *) tempbuf);

    if (MTPNP_AD_SW_Need_Register())
    {
        ShowCategory74Screen(STRING_MTPNP_HELPINFO, 0, STRING_MTPNP_REGISTER, 0, STR_GLOBAL_BACK, 0,
                             (MTPNP_UINT8 *) UnicodeDisplayBuf, sizeof(UnicodeDisplayBuf), guiBuffer);

        SetLeftSoftkeyFunction(EntryRegisterSW, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory74Screen(STRING_MTPNP_HELPINFO, 0, (MTPNP_UINT16) NULL, 0, STR_GLOBAL_BACK, 0,
                             (MTPNP_UINT8 *) UnicodeDisplayBuf, sizeof(UnicodeDisplayBuf), guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

void EntryRegisterSW(void)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_STARTREG, StartRegisterProgess);

    DisplayConfirmCountDown(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                            STR_GLOBAL_NO, IMG_GLOBAL_NO,
                            get_string(STRING_MTPNP_REGISTER_CONFIRM), IMG_GLOBAL_QUESTION,
                            WARNING_TONE, 10, GoBackHistory);

    ClearAllKeyHandler();
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(StartRegisterSW, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void EntryQueryRegisterSW(void)
{
    if (MTPNP_AD_SW_Need_Register())
    {
        MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_STARTREG, StartRegisterProgess);

        DisplayConfirmCountDown(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                                STR_GLOBAL_NO, IMG_GLOBAL_NO,
                                get_string(STRING_MTPNP_REGISTER_CONFIRM), IMG_GLOBAL_QUESTION,
                                WARNING_TONE, 10, MTPNP_AD_Bootup);

        ClearAllKeyHandler();
        SetKeyHandler(MTPNP_AD_Bootup, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(StartRegisterSW, KEY_EVENT_UP);
        SetRightSoftkeyFunction(MTPNP_AD_Bootup, KEY_EVENT_UP);
    }
    else
    {
        MTPNP_AD_Bootup();
    }
}

void StartRegisterProgess(void *pMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_STARTREG);

    GoBackHistory();

    EntryShowRegisterProgress();
}

void EntryShowRegisterProgress(void)
{
    MTPNP_UINT8 *guiBuffer;

    EntryNewScreen(SCR_REGISTERPROG, MTPNP_NULL, EntryShowRegisterProgress, MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_REGISTERPROG);
    SetParentHandler(MENU_MTPNP_HELPINFO);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    MTPNP_OSAL_memset(UnicodeDisplayBuf, 0, sizeof(UnicodeDisplayBuf));

    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) UnicodeDisplayBuf,
                                   (const MTPNP_CHAR *) GetString(STRING_MTPNP_REGISTER_TIP));

    ShowCategory74Screen(STRING_MTPNP_REGISTER, 0, (MTPNP_UINT16) NULL, 0, STR_GLOBAL_BACK, 0,
                         (MTPNP_UINT8 *) UnicodeDisplayBuf, sizeof(UnicodeDisplayBuf), guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void StartRegisterSW(void)
{
    MTPNP_AD_SW_Register();
}

#endif /* __MMI_DUAL_SIM_MASTER__ */

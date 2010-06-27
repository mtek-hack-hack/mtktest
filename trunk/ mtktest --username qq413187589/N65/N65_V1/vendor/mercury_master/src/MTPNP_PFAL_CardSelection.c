#include "MMI_Features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "stdC.h"
#include "L4Dr.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"
#include "DebugInitDef.h"
#include "MMI_trc.h"
#include "ProtocolEvents.h"
#include "EventsGprot.h"
#include "HistoryGprot.h"
#include "SubLCDHistoryGprot.h"
#include "GlobalDefs.h"
#include "GlobalStruct.h"
#include "GlobalScrEnum.h"
#include "WrapperGprot.h"
#include "KeyBrd.h"
#include "TimerEvents.h"
#include "wgui.h"
#include "Wgui_categories_popup.h"
#include "wgui_categories_CM.h"
#include "wgui_categories_util.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_multimedia.h"
#include "gdi_include.h"        /* for GDI's color define */
#include "ProfileGprots.h"
#include "BootUp.h"
#include "MessagesResourceData.h"

#include "AlarmFrameworkProt.h"
#include "SATDefs.h"
#include "SATGProts.h"
#include "SimDetectionGexdcl.h"
#include "gpioInc.h"
#include "CallSetUp.h"
#include "SettingDefs.h"
#include "wgui_status_icons.h"

#include "CallManagementIdDef.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
#include "CmErrorTypes.h"
#include "CmErrorHandlersProt.h"
#include "HistoryHelperProt.h"
#include "RedialHelperGProt.h"
#include "CommonStubsProt.h"
#include "PsCallHelperDef.h"
#include "PsCallHelperGprot.h"
#include "CallManagementGprot.h"
#include "OutgoingCallHelperProt.h"
#include "OutgoingCallManagementProt.h"
#include "MessagesResourceData.h"
#include "IncomingCallManagementProt.h"
#include "CommonScreens.h"      /* for popup window timer. */

#include "SettingGenum.h"
#include "ProfilesDefs.h"
#include "MTPNP_AD_resdef.h"
#include "CallSetUpEnum.h"
#include "IdleAppProt.h"

/* MTPNP Header file */
#include "MTPNP_AD_master_header.h"
#include "CommonStubsProt.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_custom_hw.h"

static FuncPtr mtpnpseldial1func = MTPNP_NULL;   /* action function pointer for select menu card1 dial and card2 dial */
static FuncPtr mtpnpseldial2func = MTPNP_NULL;

void MTPNP_PFAL_CC_SetDial1Func(FuncPtr dialfunc)
{
    mtpnpseldial1func = dialfunc;
}

void MTPNP_PFAL_CC_SetDial2Func(FuncPtr dialfunc)
{
    mtpnpseldial2func = dialfunc;
}

FuncPtr MTPNP_PFAL_CC_GetDial1Func(void)
{
    return mtpnpseldial1func;
}

FuncPtr MTPNP_PFAL_CC_GetDial2Func(void)
{
    return mtpnpseldial2func;
}

void MTPNP_PFAL_CC_ExeDial1Func(void)
{
    if (MTPNP_PFAL_CC_GetDial1Func() != MTPNP_NULL)
    {
        mtpnpseldial1func();
    }
    else
    {
        PRINT_INFORMATION("\nMTPNP_PFAL_CC_ExeDialFunc:ERROR\n");
    }
}

void MTPNP_PFAL_CC_ExeDial2Func(void)
{
    if (MTPNP_PFAL_CC_GetDial2Func() != MTPNP_NULL)
    {
        mtpnpseldial2func();
    }
    else
    {
        PRINT_INFORMATION("\nMTPNP_PFAL_CC_ExeDialFunc:ERROR\n");
    }
}

void MTPNP_PFAL_CC_ShowSelectCard(void)
{
    if (MTPNP_AD_DUALSIM_USABLE == MTPNP_AD_Get_UsableSide())
    {
        PRINT_INFORMATION("\n MTPNP_PFAL_CC_ShowSelectCard:SELECT\n");
        MTPNP_PFAL_CC_SelectCardScreen();
    }
    else if (MTPNP_AD_SIMCARD1_USABLE == MTPNP_AD_Get_UsableSide())
    {
        PRINT_INFORMATION("\n MTPNP_PFAL_CC_ShowSelectCard:CARD1\n");
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);

        if (MTPNP_PFAL_CC_GetDial1Func() != MTPNP_NULL)
        {
            MTPNP_PFAL_CC_ExeDial1Func();
        }
    }
    else if (MTPNP_AD_SIMCARD2_USABLE == MTPNP_AD_Get_UsableSide())
    {
        PRINT_INFORMATION("\n MTPNP_PFAL_CC_ShowSelectCard:CARD2\n");
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);

        if (MTPNP_PFAL_CC_GetDial2Func() != MTPNP_NULL)
        {
            MTPNP_PFAL_CC_ExeDial2Func();
        }
    }
    else
    {
        PRINT_INFORMATION("\n MTPNP_PFAL_CC_ShowSelectCard:ERROR\n");
        return;
    }
}

void MTPNP_PFAL_CC_SelectCardScreen(void)
{
    U16 nStrItemList[2];
    U16 nNumofItem;
    U8 *guiBuffer;
    MTPNP_BOOL isShowOption;
    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_SelectCardScreen");

    EntryNewScreen(SCR_MTPNP_SELECT_CARD, NULL, MTPNP_PFAL_CC_SelectCardScreen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_SELECT_CARD);

    nNumofItem = GetNumOfChild(MENU_MTPNP_SELECT_CARD);

    GetSequenceStringIds(MENU_MTPNP_SELECT_CARD, nStrItemList);

    SetParentHandler(MENU_MTPNP_SELECT_CARD);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(SLAVE_STR_CC_CSK_SELECT_NET, 0,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (PU16) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

void MTPNP_PFAL_CC_InitSelectCard(void)
{
    SetHiliteHandler(MENU_MTPNP_SELECT_CARD_1SELECTED, MTPNP_PFAL_CC_HiliteSelectCard1);
    SetHiliteHandler(MENU_MTPNP_SELECT_CARD_2SELECTED, MTPNP_PFAL_CC_HiliteSelectCard2);
}

void MTPNP_PFAL_CC_HiliteSelectCard1(void)
{
    SetLeftSoftkeyFunction(MTPNP_PFAL_CC_DialCard1, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_CC_HiliteSelectCard2(void)
{
    SetLeftSoftkeyFunction(MTPNP_PFAL_CC_DialCard2, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_CC_DialCard1(void)
{
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
    MTPNP_PFAL_CC_ExeDial1Func();
}

void MTPNP_PFAL_CC_DialCard2(void)
{
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
    MTPNP_PFAL_CC_ExeDial2Func();
}

#endif /* __MMI_DUAL_SIM_MASTER__ */
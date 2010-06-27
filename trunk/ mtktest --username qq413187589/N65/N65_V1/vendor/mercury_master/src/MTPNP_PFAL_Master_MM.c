/***********************************************
File name : MTPNP_AD_custom_MM.c
Contents : MTPNP AD custom module management file
History : Create by : Zhang Nan, apr 3, 2007
************************************************/
#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

/*MTK header file*/
#include "IdleAppDef.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "DEVICE.H"
#include "wgui_status_icons.h"
#include "bootup.h"
/*MTK header file*/

#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_MM.h"
#include "MTPNP_PFAL_custom_hw.h"

extern idle_context_struct g_idle_context;
extern pwr_context_struct g_pwr_context;
extern charbat_context_struct g_charbat_context;
extern MTPNP_UINT8 gInsertSimAppFlag;

extern void goto_opening_screen(void);
extern void QuitSystemOperation(void);
extern void FlightModeCheckBeforeAnimation(void);

void MTPNP_PFAL_MM_Init(void)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SLAVE_PLUGIN, MTPNP_PFAL_Custom_Slave_PlugIn);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SLAVE_START_FINISHED, MTPNP_PFAL_Custom_Startup_Finished);
}

void MTPNP_PFAL_Custom_Slave_PlugIn(void * inMsg)
{
    /*
       the function would be callback when slave module plug in
     */
}

void MTPNP_PFAL_Custom_Startup_Finished(void * inMsg)
{
    /*
       the function would be callback when slave module start up finish
     */
}

MTPNP_BOOL MTPNP_PFAL_Is_InIdlescreen(void)
{
    if (g_idle_context.IsOnIdleScreen)
        return MTPNP_TRUE;

    return MTPNP_FALSE;
}

MTPNP_BOOL MTPNP_PFAL_Is_InSIMErrorscreen(void)
{
    if (gInsertSimAppFlag == 1)
        return MTPNP_TRUE;

    return MTPNP_FALSE;
}

MTPNP_BOOL MTPNP_PFAL_Master_Is_Cause_Exception_Reboot(void)
{
#ifndef MMI_ON_WIN32
    if (g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION)
        return MTPNP_TRUE;
#endif

    return MTPNP_FALSE;
}

void MTPNP_PFAL_Entry_Idle_From_SIM_error(void)
{
    mmi_bootup_exit_security_check();   /* send message to it slef notify ready to go to idle */

    if (g_charbat_context.isChargerConnected == 1)
    {
        /* Hide status icon temporary, entry idle screen will start animation again */
        HideStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
        ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
        UpdateStatusIcons();
    }

    if (MTPNP_AD_SDK_Is_Startup_Finished())
    {
        /* rearrange the status bar on idle screen */
        MTPNP_PFAL_Rearrange_StatusBar();
        /* rearrange the menu item */
        MTPNP_PFAL_Rearrange_MenuItem();
    }

//    goto_opening_screen();
}

void MTPNP_PFAL_Shutdown_System(void)
{
#ifndef __MMI_DUAL_SIM_SINGLE_CALL__
    MTPNP_PFAL_GPIO_Deinit();

    MTPNP_PFAL_EndKey_Down();

    MTPNP_PFAL_Stop_Timer(MTPNP_RELEASE_SLAVE_PWRKEY_TIMER);
    MTPNP_PFAL_Start_Timer(MTPNP_RELEASE_SLAVE_PWRKEY_TIMER, SLAVE_PWRKEY_DOWN_TIMEOUT, MTPNP_PFAL_Shutdown_Timeout);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
}

void MTPNP_PFAL_Shutdown_Timeout(void)
{
    kal_prompt_trace(MTPNP_PFAL_Get_MTPNP_Task_Mod(), "MTPNP_PFAL_Shutdown_Timeout");

    MTPNP_PFAL_Stop_Timer(MTPNP_RELEASE_SLAVE_PWRKEY_TIMER);
    MTPNP_PFAL_Start_Timer(SYSTEM_SHUTDOWN, POWER_OFF_TIMER_STAGE_2, QuitSystemOperation);
}

#ifndef __MMI_DUAL_SIM_SINGLE_CALL__
void MTPNP_PFAL_boot_up(void * inMsg)
{
    if (MTPNP_AD_Get_Card1Status() > 0x0 &&
        MTPNP_AD_Get_Card2Status() > 0x0)
    {
        ClearProtocolEventHandler(MSG_ID_MTPNP_WAIT_DUALSIM_READY);
        FlightModeCheckBeforeAnimation();
    }
    else
    {
        MYQUEUE Message;

        SetProtocolEventHandler(MTPNP_PFAL_boot_up, MSG_ID_MTPNP_WAIT_DUALSIM_READY);
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_MMI;
        Message.oslMsgId = MSG_ID_MTPNP_WAIT_DUALSIM_READY;
        Message.oslDataPtr = NULL;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
}
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

#endif /* __MMI_DUAL_SIM_MASTER__ */

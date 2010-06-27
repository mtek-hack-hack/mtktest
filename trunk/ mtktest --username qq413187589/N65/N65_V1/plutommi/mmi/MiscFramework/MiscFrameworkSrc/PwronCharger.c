/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * PoweronCharger.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Power On when Charger connects 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_include.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 
#include "taskinit.h"
#include "BootUp.h"
#include "ProtocolEvents.h"
#include "MMITaskProt.h"
#include "AsyncEventsgprot.h"
#include "PowerOnChargerProt.h"
#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "AudioInc.h"
#include "IdleAppprot.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "gpioInc.h"
#include "SettingGprots.h"
#include "ProfileGprots.h"
#include "AlarmGprot.h"
#include "ProfileGprots.h"
#include "CallManagementGprot.h"
#include "AlarmFrameWorkProt.h"
#include "ProfileGprots.h"
#include "ScheduledPowerOnOffGprot.h"
#include "lcd_if.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBDeviceDefs.h"
#endif /* __MMI_USB_SUPPORT__ */ 

#include "lcd_sw.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "gpioInc.h"
#include "ComposeRingToneProts.h"

#ifdef __MMI_THEMES_APPLICATION__
#include "MMIThemes.h"
#endif 

#include "DownloadProtos.h"

#include "datetimetype.h"
#include "app_datetime.h"

#include "Mmiapi_struct.h"


/***************************************************************************** 
* Global Variable
*****************************************************************************/
charbat_context_struct g_charbat_context = 
{
    0,                  /* g_charbat_context.PowerOnCharger */
    0,                  /* g_charbat_context.PowerOnChargingPeriod */
    0,                  /* g_charbat_context.ChargingAbnormal */
    0,                  /* g_charbat_context.ChargingComplete */
    0,                  /* g_charbat_context.LowBatteryFlag */
    0,                  /* g_charbat_context.LowBatteryTxProhibitFlag */
    BATTERY_LEVEL_0,    /* g_charbat_context.chargerLevel */
    PMIC_VBAT_STATUS,   /* g_charbat_context.batteryStatus */
    0,                  /* g_charbat_context.isChargerConnected */
    0,                  /* g_charbat_context.LowBatteryCutOffCallCnt */
    0                   /* g_charbat_context.BatteryNotifyModId */    
};

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* Tells how  many times Battery low ind has been received. after 10 count it reset to -1 */
static U8 batteryLowCount = 0;
static U8 lowBatteryAlarmThreshold = LBAT_IDLE_DURCNT_NORMAL;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_devmgr_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

/***************************************************************************** 
* External Function
*****************************************************************************/
extern void QuitSystemOperation(void);

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
extern void PmgInitExtMelodyStruct(void);
#endif 

extern void ShutdownSystemOperation(void);

extern void PhnsetReadGPIOSetting(void);
extern void InitDownloadNVRAM(void);

#if defined(__MMI_ENGINEER_MODE__)
extern MMI_BOOL mmi_em_device_is_use_usb_as_uart_port(void);
#endif



/*****************************************************************************
 * FUNCTION
 *  PreChargeEnd
 * DESCRIPTION
 *  Leave pre-charge stage.
 * PARAMETERS
 *  msg     [IN]        Leaving pre-charge indication
 * RETURNS
 *  void
 *****************************************************************************/
static void PreChargeEnd(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  PreChrKeyPadDummyHdlr
 * DESCRIPTION
 *  Keypad dummy function when pre-charge stage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PreChrKeyPadDummyHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((U8*) GetString(STR_LOW_BATTERY), IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  InitializeChargingScr
 * DESCRIPTION
 *  Initialization for power on charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeChargingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitUnicodeSupport();

    gdi_init();

    PhnsetReadGPIOSetting();

#ifdef __MMI_USB_SUPPORT__
    InitMMIUsbContext();
#endif 

    InitFramework();

    InitHardwareEvents();
    InitTime();
    InitMMI_App();
    setup_UI_wrappers();
    PopulateResData();
    initialize_UI_demo();
    ShowChargingScr();

    InitProfileApp();

    /* Precharge Power On */
    if (g_pwr_context.PowerOnMode == POWER_ON_PRECHARGE)
    {
        SetProtocolEventHandler(PreChargeEnd, MSG_ID_MMI_EQ_LEAVE_PRECHARGE_IND);
    }

    TurnOnBacklight(1);

    InitDownloadNVRAM();
    initnvramprofapp();
    InitSettingNVRAM();
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
#ifndef WIN32
    InitRingToneComposer();
#endif
#endif 

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    PmgInitExtMelodyStruct();
#endif 

    InitAlarmFrameWork();

    StartLEDPatternCharging();
    g_charbat_context.PowerOnCharger = 1;
    AnimateStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    UpdateStatusIcons();
    InitChargerPwrOn();
    /* To wake up pending alarm */
    PendingAlarmReminder();
}


/*****************************************************************************
 * FUNCTION
 *  AlarmDisplayCharging
 * DESCRIPTION
 *  Handling of Charger connected on Power on Alarm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlarmDisplayCharging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_charbat_context.PowerOnCharger = 1;
    g_charbat_context.isChargerConnected = 1;
    StartLEDPatternCharging();
    ShowChargingScr();

    if (g_charbat_context.ChargingComplete)
    {
        HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    }
    else
    {
        AnimateStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    }

    UpdateStatusIcons();
    InitChargerPwrOn();
}


/*****************************************************************************
 * FUNCTION
 *  ShowChargingScr
 * DESCRIPTION
 *  Show charging screen when phone bootup bcos of charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowChargingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_CHARGER_POWER_ON);

    EntryNewScreen(SCR_CHARGER_POWER_ON, ExitChargingScr, NULL, NULL);
    entry_full_screen();
    DinitHistory();
    if (g_pwr_context.PowerOnMode == POWER_ON_PRECHARGE)
    {
        ShowCategory9Screen(0, IMG_CHARGER_POWER_ON, NULL);
    #ifndef __MMI_POWER_ON_OFF_BY_POWER_KEY__
        SetKeyHandler(PreChrKeyPadDummyHdlr, KEY_END, KEY_LONG_PRESS);
    #endif
        SetKeyHandler(PreChrKeyPadDummyHdlr, KEY_POWER, KEY_LONG_PRESS);    
        SetProtocolEventHandler(PreChargeEnd, MSG_ID_MMI_EQ_LEAVE_PRECHARGE_IND);
    }
    else
    {
        ShowCategory9Screen(0, IMG_CHARGER_POWER_ON, NULL);
    #ifndef __MMI_POWER_ON_OFF_BY_POWER_KEY__
        SetKeyHandler(ChargingPwnOnThanPwnOn, KEY_END, KEY_LONG_PRESS);
    #endif
        SetKeyHandler(ChargingPwnOnThanPwnOn, KEY_POWER, KEY_LONG_PRESS);            
    }

    ShowSubLCDScreen(ShowSubLCDChargingScr);
#ifndef __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__
    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    UpdateStatusIcons();
#endif /* __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__ */ 

    g_charbat_context.PowerOnChargingPeriod = 1;

}


/*****************************************************************************
 * FUNCTION
 *  ExitChargingScr
 * DESCRIPTION
 *  Exit power on charging screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitChargingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_CHARGER_POWER_ON;
    Scr.entryFuncPtr = ShowChargingScr;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    AddHistory(Scr);
    leave_full_screen();
    g_charbat_context.PowerOnChargingPeriod = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDChargingScr
 * DESCRIPTION
 *  Show power on charging screen on SUBLCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDChargingScr(void)
{
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsClamClose())
    {
        ExecSubLCDCurrExitHandler();
        ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
        SetSubLCDExitHandler(ExitSubLCDChargingScr);
    }
    else
    {
        ExecSubLCDCurrExitHandler();
        ShowCategory304Screen(IMG_SUBLCD_CHARGER_POWER_ON, 0);
        SetSubLCDExitHandler(ExitSubLCDChargingScr);
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_SUBLCD_CHARGER_POWER_ON, 0);
    SetSubLCDExitHandler(ExitSubLCDChargingScr);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDChargingScr
 * DESCRIPTION
 *  Exit power on charging screen from sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDChargingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    SubLCDHistory.entryFuncPtr = ShowSubLCDChargingScr;
    AddSubLCDHistory(&SubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  InitChargerPwrOn
 * DESCRIPTION
 *  Initialise protocol handlers for power on charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitChargerPwrOn()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
    SetProtocolEventHandler(PowerOffRsp, MSG_ID_MMI_EQ_POWER_OFF_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  ChargingPwnOnThanPwnOn
 * DESCRIPTION
 *  Fn to be called to power on the phone for long press of End key during power
 *  on charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChargingPwnOnThanPwnOn()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI should detect keypad power on itself when charging */
    MYQUEUE Message;
    mmi_eq_power_on_req_struct *myMsgPtr;

#if defined(__MMI_SUBLCD__)
    lcd_power_on(SUB_LCD, 0);
#endif 

    LCDBackLightOff();

    myMsgPtr = (mmi_eq_power_on_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_power_on_req_struct));
    myMsgPtr->fun = 1;
    myMsgPtr->rst = 0;
    PRINT_INFORMATION("[DevMngr-PMIC] CHARGER POWERKEY_ON");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_POWER_ON_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    g_charbat_context.PowerOnCharger = 0;
}



#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add it 

#ifndef WIN32
extern U8 IsBatteryLow(void);
#endif

static U8 IsMainBatteryCharging = 0 ; 

U8 GetMainBatteryChargeState()
{
	return IsMainBatteryCharging ;
}

void SetMainBatteryChargeState(U8 value)
{
	IsMainBatteryCharging = value % 2  ;
}


static U8 nBatteryTwoLevel = 0 ; // 0,1,2,3

void SetBatteryTwoLevel(U8 value)
{
	nBatteryTwoLevel = value ;
}

U8 GetBatteryTwoLevel()
{
	return nBatteryTwoLevel ;
}


static U8 nBatteryOneFull = 0;

void SetBatteryOneFull(U8 value)
{
	nBatteryOneFull = value ;
}

U8 GetBatteryOneFull()
{
	return nBatteryOneFull ;
}



static U8 nBatteryTwoFull = 0;

void SetBatteryTwoFull(U8 value)
{
	nBatteryTwoFull = value ;
}

U8 GetBatteryTwoFull()
{
	return nBatteryTwoFull ;
}

#ifndef MMI_ON_WIN32
extern kal_uint8 ExistSubBattery();
#endif

#endif


/*****************************************************************************
 * FUNCTION
 *  BatteryStatusRsp
 * DESCRIPTION
 *  Call back function for battery status indication.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryStatusRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_battery_status_ind_struct *p = (mmi_eq_battery_status_ind_struct*) info;
    U16 string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_charbat_context.batteryStatus = p->battery_status;
#ifdef __MTK_TARGET__
    g_charbat_context.chargerLevel = p->battery_voltage;
#endif 
    mmi_devmgr_charger_send_ack(p->battery_status);

    if (g_charbat_context.BatteryNotifyModId != 0)
    {
        mmi_send_battery_level_notify_ind_hdlr();
    }

    switch (p->battery_status)
    {
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_CHARGER_IN:
            string_id = STR_USB_CHARGER_CONNECTED;
            /* PASS */
    #endif /* __MMI_USB_SUPPORT__ */ 
        case PMIC_CHARGER_IN:
        {
            if (!string_id)
            {
                string_id = STR_CHARGER_CONNECTED;
            }

            g_charbat_context.isChargerConnected = 1;

#if defined(DOUBLE_BATTERY_SUPPORT)
		#ifndef WIN32
		//Huyanwei Add It 
		if(ExistSubBattery()  == 1)
		{		
			ChargeSwCtl( 1 ); //Switch Sub Battery
			SetMainBatteryChargeState(0);
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\rCharge message :Sub Battery\n");
#endif
		}
		else
		{
			ChargeSwCtl( 0 ); //Switch main Batter
			SetMainBatteryChargeState(1);
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\rCharge message :Main Battery\n");		 
#endif
		}
	#endif
#endif
			
        #ifdef __MMI_USB_SUPPORT__
            mmi_usb_set_background_still(MMI_FALSE);
        #endif 

            if (mmi_bootup_is_before_power_on() == MMI_TRUE)
            {
                PRINT_INFORMATION("[DevMngr-PMIC] CHARGER IN before power on indication");
            }
            else
            {
                if (mmi_bootup_is_in_power_on_period() == MMI_TRUE)
                {
                    IdleScreenChargerConnected(KAL_TRUE);
                }
                else
                {
                    g_charbat_context.ChargingComplete = 0; /* To prevent reentrence of charging complete screen */
                    TurnOnBacklight(1);

                    if (!g_charbat_context.PowerOnCharger && mmi_bootup_is_in_power_on_period() == MMI_FALSE)
                    {
                        BatteryIndicationPopup(string_id);
                        IdleScreenChargerConnected(KAL_FALSE);   /* swap for sublcd display */
                    }

                    if (g_charbat_context.LowBatteryFlag)   /* Charger plug in shall stop low battery LED pattern */
                    {
                        g_charbat_context.LowBatteryFlag = 0;
                        StopLEDPatternBatteryWarning(); /* disconnect charger, the abnormal led pattern shall stop */
                    }
                }
            }
            break;
        }
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_NO_CHARGER_IN:
        {
            g_charbat_context.isChargerConnected = 1;
            mmi_usb_set_background_still(MMI_TRUE);

            if (mmi_bootup_is_before_power_on() == MMI_TRUE)
            {
                PRINT_INFORMATION("[DevMngr-PMIC] CHARGER IN before power on indication");
            }
            else
            {
                if (mmi_bootup_is_in_power_on_period() == MMI_TRUE)
                {
                    IdleScreenChargerDisconnected();
                }
                else
                {
                    g_charbat_context.ChargingComplete = 0; /* To prevent reentrence of charging complete screen */
                    TurnOnBacklight(1);

                    if (!g_charbat_context.PowerOnCharger && mmi_bootup_is_in_power_on_period() == MMI_FALSE)
                    {
                        IdleScreenChargerDisconnected();   /* swap for sublcd display */
                    }

                    if (g_charbat_context.LowBatteryFlag)   /* Charger plug in shall stop low battery LED pattern */
                    {
                        g_charbat_context.LowBatteryFlag = 0;
                        StopLEDPatternBatteryWarning(); /* disconnect charger, the abnormal led pattern shall stop */
                    }
                }
            }   
            break;
        }
    #endif /* MMI_USB_SUPPORT */
    #ifdef __MMI_USB_SUPPORT__
        case PMIC_USB_NO_CHARGER_OUT:
        case PMIC_USB_CHARGER_OUT:
            string_id = STR_USB_CHARGER_REMOVED;
            /* PASS */
    #endif /* __MMI_USB_SUPPORT__ */ 
        case PMIC_CHARGER_OUT:
        {
            if (!string_id)
            {
                string_id = STR_CHARGER_REMOVED;
            }
            g_charbat_context.ChargingComplete = 0; /* to prevent reentrence of charging complete screen */
            g_charbat_context.isChargerConnected = 0;

        #ifdef __MMI_USB_SUPPORT__
            mmi_usb_set_background_still(MMI_TRUE);
        #endif 

            if (mmi_bootup_is_before_power_on() == MMI_TRUE)
            {
                PRINT_INFORMATION("[DevMngr-PMIC] CHARGER OUT before power on indication");
            }
            else
            {
                StopLEDPatternBatteryWarning();
                if (g_charbat_context.PowerOnCharger &&
                    mmi_alm_is_in_alarm() == 0 && g_pwr_context.PowerOnMode != POWER_ON_USB)
                {
                    Message.oslSrcId = MOD_MMI;
                    Message.oslDestId = MOD_L4C;
                    Message.oslMsgId = MSG_ID_MMI_EQ_POWER_OFF_REQ;
                    Message.oslDataPtr = NULL;
                    Message.oslPeerBuffPtr = NULL;
                    OslMsgSendExtQueue(&Message);
                }
                else
                {
                    if (mmi_bootup_is_in_power_on_period() == MMI_FALSE)
                    {
                        TurnOnBacklight(1);
                    #ifdef __USB_IN_NORMAL_MODE__
                        /* check is in mass storage mode */
                        if (!mmi_usb_is_in_mass_storage_mode() &&
                            (GetUsbStatus() != MMI_USBSTATUS_PICTBRIGE) &&
                            //(GetActiveScreenId() != POPUP_SCREENID) &&
                            (p->battery_status!=PMIC_USB_CHARGER_OUT))
                    #endif /* __USB_IN_NORMAL_MODE__ */                        
                        {
                            /* not in mass storage, can show the plug-out prompt */                        
                            BatteryIndicationPopup(string_id);
                        }
                    #if defined(__MMI_ENGINEER_MODE__)
                        if ((p->battery_status==PMIC_USB_CHARGER_OUT)&& mmi_em_device_is_use_usb_as_uart_port()==MMI_TRUE)
                        {
                            /* not in mass storage, can show the plug-out prompt */                        
                            BatteryIndicationPopup(string_id);                            
                        }
                    #endif /* __MMI_ENGINEER_MODE__*/
                        DeleteScreenIfPresent(SCR_CHARGER_POWER_ON);
                        StopLEDPatternCharging();
                    }

                    IdleScreenChargerDisconnected();

                    if (g_charbat_context.ChargingAbnormal)
                    {
                        g_charbat_context.ChargingAbnormal = 0;
                    }

                }
            }
            g_charbat_context.PowerOnCharger = 0;

            break;
        }

        case PMIC_CHARGE_COMPLETE:  /* battery full charged. */
        {
        #ifndef __MTK_TARGET__
            g_charbat_context.chargerLevel = BATTERY_LEVEL_3;
        #endif 



#if defined(DOUBLE_BATTERY_SUPPORT)
		#ifndef WIN32
		//Huyanwei Add It 
		if(GetMainBatteryChargeState() == 0)
		{
			SetBatteryTwoFull(1);
			ChargeSwCtl( 0 ); //Switch main Batter
	 		SetMainBatteryChargeState(1);
#if defined(NOKE_DEBUG)
			 noke_dbg_printf("\rCharge message :Sub Battery charge comlate \n");
#endif
		}
		else
		{
			//Do Nothing 
		        SetBatteryOneFull(1);
#if defined(NOKE_DEBUG)
	  	        noke_dbg_printf("\rCharge message :Main Battery charge comlate \n");
#endif
		}
		#endif
#endif



            if (mmi_bootup_is_before_power_on() == MMI_TRUE)
            {
                BatteryStatusIndication(BATTERY_LEVEL_3);
            }
            else
            {
                if (g_charbat_context.PowerOnCharger)
                {
                    /* To prevent reentrence of charging complete screen */
                    if (g_charbat_context.ChargingComplete == 0 && (AlmIsRTCPwron() == 0))
                    {
                        g_charbat_context.ChargingComplete = 1;

                    #ifdef __MMI_USB_SUPPORT__
                        if (g_pwr_context.PowerOnMode == POWER_ON_USB)
                        {
                            ShowUsbChgCmpltScr();
                        }
                        else
                    #endif /* __MMI_USB_SUPPORT__ */ 
                        {
                            ShowChargingCompleteScr();
                            StartLEDPatternFullCharging();
                            HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
                            ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
                            ChangeStatusIconLevel(STATUS_ICON_BATTERY_STRENGTH, 100);
                            ChangeStatusIconLevel(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 100);
                            UpdateStatusIcons();
                        }
                    }
                }
                /* Message for Power off Device;Deepali */
                else
                {
                #ifdef __MMI_LED_POWERON_CHARGEFULL__
                    g_charbat_context.ChargingComplete = 1;
                    StartLEDPatternFullCharging();
                #endif /* __MMI_LED_POWERON_CHARGEFULL__ */ 
                    IdleScreenBatteryFullCharged();
                }
            }
            break;
        }

        case PMIC_VBAT_STATUS:
        {
        #ifndef __MTK_TARGET__
            g_charbat_context.chargerLevel = p->battery_voltage;
        #endif 

		#if defined(DOUBLE_BATTERY_SUPPORT)
			#ifndef WIN32
			if(  IsBatteryLow()  == 1 )
			#endif
			{
				ev_dbg("Huyanwei Test LowBattery\r\n");
				BatteryStatusLowBatteryHandler(0);
			}
	     #else
                     BatteryStatusLowBatteryHandler(p->battery_voltage);
	     #endif		
		 
            BatteryStatusIndication(p->battery_voltage);
            break;
        }

        case PMIC_INVALID_BATTERY:
            ChargingAbnormalHandler(STR_INVALID_BATTERY);
            break;

        case PMIC_OVERBATTEMP:
            ChargingAbnormalHandler(STR_OVER_TEMP_BATTERY);
            break;

        case PMIC_OVERVOLPROTECT:
            ChargingAbnormalHandler(STR_OVER_VOLTAGE_BATTERY);
            break;

        case PMIC_OVERCHARGECURRENT:
            ChargingAbnormalHandler(STR_OVER_CURRENT_BATTERY);
            break;

        case PMIC_LOWBATTEMP:
            ChargingAbnormalHandler(STR_LOW_TEMP_BATTERY);
            break;

        case PMIC_CHARGING_TIMEOUT:
            ChargingAbnormalHandler(STR_CHARGING_TIMEOUT);
            break;

        case PMIC_INVALID_CHARGER:
            ChargingAbnormalHandler(STR_INVALID_CHARGER);
            break;

        case PMIC_LOWCHARGECURRENT:
            ChargingAbnormalHandler(STR_CHARGE_BAD_CONTACT);
            break;

        case PMIC_CHARGE_BAD_CONTACT:
            ChargingAbnormalHandler(STR_CHARGE_BAD_CONTACT);
            break;

        case PMIC_BATTERY_BAD_CONTACT:
            ChargingAbnormalHandler(STR_BATTERY_BAD_CONTACT);
            break;

        default:
            break;
    }

    /* Shall reset this flag in the end of msg handler func */
    SetInterruptPopupDisplay(POPUP_ALL_ON);
}


/*****************************************************************************
 * FUNCTION
 *  LowBatteryCommonAction
 * DESCRIPTION
 *  Handles the common action for low battery.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LowBatteryCommonAction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_in_power_on_period() == MMI_TRUE)
    {
        /* Reset low battery alarm counter,  low battery will alert right after finish power on procedure  */
        RESET_LOW_BATTERY_ALARM_CNT();
    }
    else
    {
        if (!g_charbat_context.isChargerConnected && batteryLowCount >= lowBatteryAlarmThreshold)
        {
            batteryLowCount = 0;
            BatteryIndicationPopup(STR_LOW_BATTERY);
            StartLEDPatternBatteryLow();
            ChgrPlayLowBatTone();
            BatteryStatusIndication(BATTERY_LOW_WARNING);
            PRINT_INFORMATION("[DevMngr-PMIC] PMIC_LOW_BATTERY");
        }
        //if (GetTotalCallCount() > 0 && g_charbat_context.LowBatteryTxProhibitFlag)
        if (isInCall() == MMI_TRUE && g_charbat_context.LowBatteryTxProhibitFlag)
        {
            g_charbat_context.LowBatteryCutOffCallCnt++;

            if (g_charbat_context.LowBatteryCutOffCallCnt >= LBAT_CALLDROP_CNT)
            {
                g_charbat_context.LowBatteryCutOffCallCnt = 0;
                DeInitCM();
            }
        }
        else
        {
            g_charbat_context.LowBatteryCutOffCallCnt = 0;
        }
    }

    g_charbat_context.LowBatteryFlag = 1;   /* for led pattern history */
    batteryLowCount++;
}


/*****************************************************************************
 * FUNCTION
 *  BatteryStatusLowBatteryHandler
 * DESCRIPTION
 *  his function handle low battery case.
 * PARAMETERS
 *  battery_voltage     [IN]        Battery level
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryStatusLowBatteryHandler(U8 battery_voltage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(
        MOD_MMI,
        "=LOWBAT=[Thre %d] [Cnt %d] [LBflag %d] [Txflag %d]",
        lowBatteryAlarmThreshold,
        batteryLowCount,
        g_charbat_context.LowBatteryFlag,
        g_charbat_context.LowBatteryTxProhibitFlag);
    switch (battery_voltage)
    {
            /*  
             * 1. After power on animation, will check the battery level again, if too low, will shutdown as well.
             * 2. When charger connected, shall ignore low battery indication  
             */
        case BATTERY_LOW_POWEROFF:  /* shutdown bcos of low battery */
        {
            if (!g_charbat_context.isChargerConnected && mmi_bootup_is_in_power_on_period() == MMI_FALSE)
            {
                PRINT_INFORMATION("[DevMngr-PMIC] LOW_BATTERY_POWER_OFF");
                ShowLowPowerShutdownScr();
            }
            break;
        }

        case BATTERY_LOW_TX_PROHIBIT:
        {
            if (g_charbat_context.LowBatteryTxProhibitFlag == 0)
            {
                /* Battery level changer, Change alert Threshold */
                g_charbat_context.LowBatteryTxProhibitFlag = 1; /* BATTERY_LOW_TX_PROHIBIT is a kind of low battery indication */

                //if (GetTotalCallCount() == 0)
                if (isInCall() == MMI_FALSE)
                {
                    SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_IDLE_DURCNT_PROHIBIT);
                    RESET_LOW_BATTERY_ALARM_CNT();
                }
                else
                {
                    SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_TALK_DURCNT_PROHIBIT);
                    RESET_LOW_BATTERY_ALARM_CNT();
                }
            }

            LowBatteryCommonAction();
            break;
        }

        case BATTERY_LOW_WARNING:
        {
            if (g_charbat_context.LowBatteryFlag == 0 || g_charbat_context.LowBatteryTxProhibitFlag == 1)
            {
                /* Battery level changer, Change alert Threshold */

                /* Battery level coming up from BATTERY_LOW_TX_PROHIBIT, reset flag */
                g_charbat_context.LowBatteryTxProhibitFlag = 0;

                //if (GetTotalCallCount() == 0)
                if (isInCall() == MMI_FALSE)
                {
                    SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_IDLE_DURCNT_NORMAL);
                    RESET_LOW_BATTERY_ALARM_CNT();
                }
                else
                {
                    SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_TALK_DURCNT_NORMAL);
                    RESET_LOW_BATTERY_ALARM_CNT();
                }
            }

            LowBatteryCommonAction();
            break;
        }

        case BATTERY_LEVEL_0:   /* pass */
        case BATTERY_LEVEL_1:   /* pass */
        case BATTERY_LEVEL_2:   /* pass */
        case BATTERY_LEVEL_3:   /* pass */
        default:
        {
            batteryLowCount = 0;                    /* reset low battery ind count */
            g_charbat_context.LowBatteryFlag = 0;   /* MTK added, Robin 1009 for status led history */
            g_charbat_context.LowBatteryTxProhibitFlag = 0;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  BatteryStatusIndication
 * DESCRIPTION
 *  This function shows the level on status icons of mainlcd nad sublcd.
 * PARAMETERS
 *  battery_voltage     [IN]        Battery level
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryStatusIndication(U8 battery_voltage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (battery_voltage)
    {
        case BATTERY_LOW_POWEROFF:      /* pass */
        case BATTERY_LOW_TX_PROHIBIT:   /* pass */
        case BATTERY_LOW_WARNING:       /* pass */
        case BATTERY_LEVEL_0:
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DevMngr-PMIC] Low Battery Warning: level = %d", battery_voltage);
            ChangeStatusIconLevel(STATUS_ICON_BATTERY_STRENGTH, 0);
        #ifdef __MMI_SUBLCD__
            ChangeStatusIconLevel(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 0);
        #endif 
            break;
        }

        case BATTERY_LEVEL_1:   /* pass */
        case BATTERY_LEVEL_2:   /* pass */
        case BATTERY_LEVEL_3:   /* pass */
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DevMngr-PMIC] Battery Level = %d", battery_voltage);
            ChangeStatusIconLevel((S16) STATUS_ICON_BATTERY_STRENGTH, (U8) (33 * (battery_voltage - BATTERY_LEVEL_0)));
        #ifdef __MMI_SUBLCD__
            ChangeStatusIconLevel(
                (S16) STATUS_ICON_SUBLCD_BATTERY_STRENGTH,
                (U8) (33 * (battery_voltage - BATTERY_LEVEL_0)));
        #endif /* __MMI_SUBLCD__ */ 
            break;
        }

        default:
        {
            PRINT_INFORMATION("Battery Status Indication unknown voltage ");
            ChangeStatusIconLevel(STATUS_ICON_BATTERY_STRENGTH, 33);
        #ifdef __MMI_SUBLCD__
            ChangeStatusIconLevel(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 33);
        #endif 
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  CHECK_MO_ALLOW
 * DESCRIPTION
 *  This function checks if outgoing call is allowed or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:  MO allowed
 *  MMI_FALSE: MO not allowed
 *****************************************************************************/
BOOL CHECK_MO_ALLOW(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.LowBatteryTxProhibitFlag == 0)
    {
        return MMI_TRUE;    /* allow MO call */
    }
    else
    {
        return MMI_FALSE;   /* prohibit MO call */
    }
}


/*****************************************************************************
 * FUNCTION
 *  IS_LOW_BATTERY
 * DESCRIPTION
 *  This function checks if battery is low.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:  voltage low
 *  MMI_FALSE: noe voltage low
 *****************************************************************************/
BOOL IS_LOW_BATTERY(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.LowBatteryFlag == 1)
    {
        return MMI_TRUE;    /* Low battery */
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SET_LOW_BATTERY_ALARM_THRESHOLD
 * DESCRIPTION
 *  TThis function sets the thresh hold for low battery alarm.
 * PARAMETERS
 *  cnt     [IN]        The thresh
 * RETURNS
 *  void
 *****************************************************************************/
void SET_LOW_BATTERY_ALARM_THRESHOLD(U8 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*********************************************************/
    /***** The threshold will be changed when:*****/
    /*********************************************************/
    /* 1. MT Call Accepted */
    /* 2. Call END */
    /* 3. Make MO Call */
    /* 4. SAT Call setup */
    /*********************************************************/
    if (lowBatteryAlarmThreshold == cnt)
    {
        return;
    }

    lowBatteryAlarmThreshold = cnt;
    batteryLowCount = lowBatteryAlarmThreshold;
}


/*****************************************************************************
 * FUNCTION
 *  RESET_LOW_BATTERY_ALARM_CNT
 * DESCRIPTION
 *  This function reset battery low alert count.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RESET_LOW_BATTERY_ALARM_CNT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Set counter to threshold value so that MMI will alert at next indication
     * (the indication will comes to MMI by 1 minute ( depends on custom setting) 
     */
    batteryLowCount = lowBatteryAlarmThreshold;
}


/*****************************************************************************
 * FUNCTION
 *  BatteryIndicationPopup
 * DESCRIPTION
 *  General popup fn for charger events.
 * PARAMETERS
 *  stringId        [IN]        String shows in the popup screen
 * RETURNS
 *  void
 *****************************************************************************/
void BatteryIndicationPopup(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pp_flag, tone_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Popup screen display permisstion flag
     * * Framework support Popup display permisstion flag
     * * Application who wanna stop popup has to intercept related messages and set the flag 
     */
    pp_flag = GetInterruptPopupDisplay();
    if ((pp_flag & POPUP_DSPL_ON) == 0 ||
        (pp_flag & POPUP_PMIC_ON) == 0)
    {
        return;
    }

    if (pp_flag & POPUP_TONE_ON)
    {
        tone_id = AUX_TONE;
    }

    /* Call End Transition, not allow to dispaly popup */
    if (GetTransitionToActiveFlag() == TRUE)
    {
        return;
    }

    if ( stringId == STR_LOW_BATTERY)
    {
        DisplayPopup((U8*) GetString(stringId), IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, tone_id);
    }
    else
    {
        DisplayPopup((U8*) GetString(stringId), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, tone_id);
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExitChargerPopUpScr
 * DESCRIPTION
 *  Exit Charger pop up screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitChargerPopUpScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(LOW_BATTERY_SCR_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  ChargingAbnormalHandler
 * DESCRIPTION
 *  Handle General Abnormal battery ind.
 * PARAMETERS
 *  stringId        [IN]        String shows in the popup screen
 * RETURNS
 *  void
 *****************************************************************************/
void ChargingAbnormalHandler(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.isChargerConnected && mmi_bootup_is_in_power_on_period() == MMI_FALSE)
    {
        AbnormalBatteryIndPopup(stringId);
        StartLEDPatternBatteryWarning();
        playRequestedTone(BATTERY_WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AbnormalBatteryIndPopup
 * DESCRIPTION
 *  Exit General Abnormal battery ind popup.
 * PARAMETERS
 *  stringId        [IN]        String shows in the popup screen
 * RETURNS
 *  void
 *****************************************************************************/
void AbnormalBatteryIndPopup(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 LocalStringId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_charbat_context.ChargingAbnormal = 1;
    EntryNewScreen(SCR_ABNORMAL_CHARGING, ExitAbnormalBatteryIndPopup, NULL, NULL);
    ClearKeyEvents();

    if (stringId != 0)
    {
        LocalStringId = stringId;
    }

    ShowCategory64Screen(LocalStringId, IMG_GLOBAL_WARNING, 0);
    ShowSubLCDScreen(ShowSubLCDAbnormalPopup);

    HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);

    ClearInputEventHandler(MMI_DEVICE_KEY);
    if (g_charbat_context.PowerOnCharger == 0)
    {
        HideStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
        ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    }
    else
    {
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);   /* Abnormal case */
        ClearKeyHandler(KEY_POWER, KEY_LONG_PRESS);   /* Abnormal case */
    }

    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  ExitAbnormalBatteryIndPopup
 * DESCRIPTION
 *  Exit General Abnormal battery ind popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitAbnormalBatteryIndPopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetInterruptPopupDisplay() == POPUP_ALL_ON)
    {
        GoBackSubLCDHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDAbnormalPopup
 * DESCRIPTION
 *  General Abnormal battery ind popup for sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDAbnormalPopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(IMG_SUBLCD_ABNORMAL_BATTERY, 0);
}


/*****************************************************************************
 * FUNCTION
 *  ShowLowPowerShutdownScr
 * DESCRIPTION
 *  Show Low power shutdown screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowLowPowerShutdownScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    DeInitFramework_KeyAndEventHandler();

    ShowCategory64Screen(STR_LOW_BATTERY_SHUTDOWN, IMG_GLOBAL_WARNING, NULL);
    BatteryStatusIndication(0);
    StartTimer(LOW_BATTERY_SCR_TIMER, LBAT_SHUTDOWN_SCR_TIMER_DUR, LowBatteryShutDownScrTimeout);

    ChgrPlayLowBatTone();
}


/*****************************************************************************
 * FUNCTION
 *  LowBatteryShutDownScrTimeout
 * DESCRIPTION
 *  Call back fn when Low Battery shutdown timer expired.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LowBatteryShutDownScrTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(LOW_BATTERY_SCR_TIMER);
#ifdef __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__
    QuitSystemOperation();
#else /* __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__ */ 
    /* if low battery shutdown at power on, do no play power off animation */
    if (mmi_bootup_is_in_power_on_period() == MMI_TRUE)
    {
        QuitSystemOperation();
    }
    else
    {
        ShutdownSystemOperation();
    }
#endif /* __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  IdleScreenChargerConnected
 * DESCRIPTION
 *  Update status icon display.
 * PARAMETERS
 *  playtone        [IN]        True/False
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenChargerConnected(U8 playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (playtone == KAL_TRUE)
    {
        playRequestedTone(AUX_TONE);
    }

    ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    AnimateStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    AnimateStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    UpdateStatusIcons();
    PRINT_INFORMATION("[DevMngr-PMIC] CHARGER IN");
}


/*****************************************************************************
 * FUNCTION
 *  IdleScreenChargerDisconnected
 * DESCRIPTION
 *  Update status icon display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenChargerDisconnected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pp_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pp_flag = GetInterruptPopupDisplay();
    if (pp_flag & POPUP_TONE_ON)
    {
        playRequestedTone(AUX_TONE);
    }
    HideStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    UpdateStatusIcons();
    BatteryStatusIndication(g_charbat_context.chargerLevel);
    PRINT_INFORMATION("[DevMngr-PMIC] CHARGER OUT");
}


/*****************************************************************************
 * FUNCTION
 *  IdleScreenBatteryFullCharged
 * DESCRIPTION
 *  Update status icon display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenBatteryFullCharged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It 
	#ifndef WIN32		
		if( ExistSubBattery() == 1)
	#else
		if( 0 )
	#endif				
		{
		    if(GetMainBatteryChargeState() == 0 )
		    {
			    //Huyanwei Add It For Battery II 
			    SetBatteryTwoLevel(3);  //FULL
			    SetBatteryTwoFull(1);
		    }
		    else
		    {
    			    SetBatteryOneFull(1);
			    HideStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
			    HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
			    ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
			    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
			    ChangeStatusIconLevel(STATUS_ICON_BATTERY_STRENGTH, 100);
			    ChangeStatusIconLevel(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 100);
		    }

		}
		else
		{
		    SetBatteryOneFull(1);
		    HideStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
		    HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
		    ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
		    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
		    ChangeStatusIconLevel(STATUS_ICON_BATTERY_STRENGTH, 100);
		    ChangeStatusIconLevel(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 100);
		}
#else

    HideStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    HideStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_BATTERY_STRENGTH);
    ShowStatusIcon(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
    ChangeStatusIconLevel(STATUS_ICON_BATTERY_STRENGTH, 100);
    ChangeStatusIconLevel(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 100);
	
#endif	

    UpdateStatusIcons();
    PRINT_INFORMATION("[DevMngr-PMIC] BATTERY FULL CHARGED");
}


/*****************************************************************************
 * FUNCTION
 *  ShowChargingCompleteScr
 * DESCRIPTION
 *  Show Charging Complete screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowChargingCompleteScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CHARGING_COMPLETE, NULL, ShowChargingCompleteScr, NULL);
    DinitHistory();
    ShowCategory9Screen(0, IMG_BATTERY_FULL_CHARGED, NULL);
    ShowSubLCDScreen(ShowSubLCDChargingCompleteScr);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
#ifndef __MMI_POWER_ON_OFF_BY_POWER_KEY__
    SetKeyHandler(ChargingPwnOnThanPwnOn, KEY_END, KEY_LONG_PRESS);
#endif
    SetKeyHandler(ChargingPwnOnThanPwnOn, KEY_POWER, KEY_LONG_PRESS);    
}


/*****************************************************************************
 * FUNCTION
 *  ShowSubLCDChargingCompleteScr
 * DESCRIPTION
 *  Show sublcd charging complete screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowSubLCDChargingCompleteScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (!IsClamClose())
    {
        ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
    }
    else
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    {
        ShowCategory304Screen(IMG_SUBLCD_CHARGING_COMPLETE, 0);
    }

    SetSubLCDExitHandler(ExitSubLCDChargingCompleteScr);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDChargingCompleteScr
 * DESCRIPTION
 *  Exit from sublcd charging complete screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDChargingCompleteScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistory.entryFuncPtr = ShowSubLCDChargingCompleteScr;
    AddSubLCDHistory(&SubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ChargerDetectTimeoutHdlr
 * DESCRIPTION
 *  Display Charger status after power on enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChargerDetectTimeoutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BOOTUP_CHARGER_DETECT_TIMER);

    if (g_charbat_context.isChargerConnected == 1)
    {
        IdleScreenChargerConnected(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ChgrPlayLowBatTone
 * DESCRIPTION
 *  Display Charger status after power on enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChgrPlayLowBatTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.isChargerConnected == 0)
    {
        playRequestedTone(BATTERY_LOW_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_devmgr_charger_send_ack
 * DESCRIPTION
 *  send ack to PS
 * PARAMETERS
 *  action          [IN]        
 *  Action(?)       [IN]        Battery_sttus
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_devmgr_charger_send_ack(U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action == PMIC_CHARGER_IN ||
        action == PMIC_CHARGER_OUT || 
        action == PMIC_USB_CHARGER_IN  || 
        action == PMIC_USB_CHARGER_OUT ||
        action == PMIC_USB_NO_CHARGER_OUT ||
        action == PMIC_USB_NO_CHARGER_IN   )
    {
        mmi_eq_battery_status_res_req_struct *param_ack;

        param_ack = OslConstructDataPtr(sizeof(mmi_eq_battery_status_res_req_struct));

        param_ack->status_type = action;

        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DevMngr-PMIC] Send Ack to PS: Action = %d", param_ack->status_type);

        mmi_devmgr_send_msg(MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ, param_ack, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_devmgr_send_msg
 * DESCRIPTION
 *  send message to PS
 * PARAMETERS
 *  msg_id              [IN]        Message id
 *  local_param_ptr     [IN]        Local parameter
 *  peer_buf_ptr        [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_devmgr_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (oslParaType*) local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_get_current_battery_level
 * DESCRIPTION
 *  Gets current battery level
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
U8 mmi_gpio_get_current_battery_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* please refer to battery_level_enum for the definition of battery level */
    return g_charbat_context.chargerLevel;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_get_battery_level_req_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_GET_BATTERY_LEVEL_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_get_battery_level_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_get_battery_level_req_struct *req = (mmiapi_get_battery_level_req_struct*) msg;
    mmiapi_get_battery_level_rsp_struct *rsp =
        (mmiapi_get_battery_level_rsp_struct*) OslConstructDataPtr(sizeof(mmiapi_get_battery_level_rsp_struct));

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp->battery_level = g_charbat_context.chargerLevel;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = req->src_mod_id;
    Message.oslMsgId = MSG_ID_MMIAPI_GET_BATTERY_LEVEL_RSP;
    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_battery_level_notify_start_req_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_START_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_battery_level_notify_start_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_battery_level_notify_start_req_struct *req = (mmiapi_battery_level_notify_start_req_struct*) msg;
    mmiapi_battery_level_notify_start_rsp_struct *rsp =
        (mmiapi_battery_level_notify_start_rsp_struct*) OslConstructDataPtr(sizeof(mmiapi_battery_level_notify_start_rsp_struct));

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_charbat_context.BatteryNotifyModId == 0)
    {
        /* default = 0, means unused now */
        g_charbat_context.BatteryNotifyModId = req->src_mod_id;
        rsp->result = TRUE;
    }
    else
    {
        /* default != 0, mean used now */
        rsp->result = FALSE;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = req->src_mod_id;
    Message.oslMsgId = MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_START_RSP;
    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_battery_level_notify_stop_req_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_STOP_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_battery_level_notify_stop_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_battery_level_notify_stop_req_struct *req = (mmiapi_battery_level_notify_stop_req_struct*) msg;
    mmiapi_battery_level_notify_stop_rsp_struct *rsp =
        (mmiapi_battery_level_notify_stop_rsp_struct*) OslConstructDataPtr(sizeof(mmiapi_battery_level_notify_stop_rsp_struct));

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_charbat_context.BatteryNotifyModId = 0;
    rsp->result = TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = req->src_mod_id;
    Message.oslMsgId = MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_STOP_RSP;
    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_battery_level_notify_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_send_battery_level_notify_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_battery_level_notify_ind_struct *rsp =
        (mmiapi_battery_level_notify_ind_struct*) OslConstructDataPtr(sizeof(mmiapi_battery_level_notify_ind_struct));

    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp->battery_level = g_charbat_context.chargerLevel;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = g_charbat_context.BatteryNotifyModId;
    Message.oslMsgId = MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_IND;
    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


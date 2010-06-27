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
 * EngineerModeDeviceSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode device prat
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_ENGINEER_MODE__    /* MTK Add Robin 1001 for saperate MMI feature by project */

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

/**************************************************************/
/*************************  Header Files *************************/
/**************************************************************/
#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"

#include "MainMenuDef.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"
#include "CustomCfg.h"
#include "audioInc.h"
#include "IdleAppDef.h"
#include "BootUp.h"
#include "CommonScreens.h"

#include "device.h"
#include "custom_em.h"
#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "pwm_sw.h"
#include "Gpio_sw.h"
#include "Pmic6318_sw.h"
#include "PowerOnChargerProt.h"
#include "rtc_sw.h"

#include "EngineerModeDeviceInc.h"
#include "SimDetectionGexdcl.h"

#if defined(NAND_SUPPORT)       /* && defined(MMI_ON_HARDWARE_P) */
#include "SettingProfile.h"     /* error tone */
#endif 

#ifdef __MTK_TARGET__
#ifdef __OTG_ENABLE__
#include "otg_if.h"
#endif 
#endif

#ifdef __MMI_FM_RADIO__
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "aud_defs.h"
#include "l1audio.h"
#endif /* #ifdef __MMI_FM_RADIO__ */

#include "fmt_def.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "gpioInc.h"
#include "gui.h"
#include "wgui_status_icons.h"

#include "adc_channel.h"

/**************************************************************/
/*********************** Global Variables *************************/
/**************************************************************/
extern U8 isEarphonePlugged;
extern U32 gClamOpenCnt;
extern U32 gClamCloseCnt;
extern U8 currentHighlightIndex;
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
UI_character_type InputBuf[8];

LCDSET LCDSetting;
PWMSET PWMSetting;

/* =======  Device -> GPIO ========= */
U8 gMenuListNum = 0;
U32 gGPIOState;
U32 gGPOState;

#ifdef __CUST_NEW__

#define IS_GPIO_SET(a)       ((gGPIOState & (0x1 << (a & ~GPIO_MAGIC_NUM))) >> (a & ~GPIO_MAGIC_NUM))
#define GPIO_STATE_SET(a)    (gGPIOState |= (0x1 << (a & ~GPIO_MAGIC_NUM)))
#define GPIO_STATE_UNSET(a)  (gGPIOState &= ~(0x1 << (a & ~GPIO_MAGIC_NUM)))
#define GPIO_STATE_TOGGLE(a) (gGPIOState ^= (0x1 << (a & ~GPIO_MAGIC_NUM)))

#define IS_GPO_SET(a)       ((gGPOState & (0x1 << (a & ~GPO_MAGIC_NUM))) >> (a & ~GPO_MAGIC_NUM))
#define GPO_STATE_SET(a)    (gGPOState |= (0x1 << (a & ~GPO_MAGIC_NUM)))
#define GPO_STATE_UNSET(a)  (gGPOState &= ~(0x1 << (a & ~GPO_MAGIC_NUM)))
#define GPO_STATE_TOGGLE(a) (gGPOState ^= (0x1 << (a & ~GPO_MAGIC_NUM)))

#else /* __CUST_NEW__ */ 

static U8 EmGpioIdxMenu2Tbl[GPIO_LABELID_MAX];

#define IS_GPIO_SET(a)       ((gGPIOState & (0x1 << a)) >> a)
#define GPIO_STATE_SET(a)    (gGPIOState |= (0x1 << a))
#define GPIO_STATE_UNSET(a)  (gGPIOState &= ~(0x1 << a))
#define GPIO_STATE_TOGGLE(a) (gGPIOState ^= (0x1 << a))

#define IS_GPO_SET(a)       ((gGPOState & (0x1 << a)) >> a)
#define GPO_STATE_SET(a)    (gGPOState |= (0x1 << a))
#define GPO_STATE_UNSET(a)  (gGPOState &= ~(0x1 << a))
#define GPO_STATE_TOGGLE(a) (gGPOState ^= (0x1 << a))
#endif /* __CUST_NEW__ */ 

/* =======  Device -> Set HW Default Level ========= */
typedef enum
{

    EM_HWLEVEL_MENU_MAINLCD_CNTST = 0,
#ifdef __MMI_SUBLCD__
    EM_HWLEVEL_MENU_SUBLCD_CNTST,
#endif 
    EM_HWLEVEL_MENU_BATTERY,
    EM_HWLEVEL_MENU_PWM_1,
    EM_HWLEVEL_MENU_PWM_2,
    EM_HWLEVEL_MENU_PWM_3,

    MAX_EM_HWLEVEL_MENU_NUM
} HW_LEVEL_MENULIST;

static U16 gHWLevelMenuID;
static U16 gHWLevelHilitItem;
static U8 gIsHWLevelInfoDirty;

U8 GPIOACTION = KAL_TRUE;
extern wgui_inline_item wgui_inline_items[];
U8 TextBuf[20];
WCHAR EMGPIOMode[4][2];
U8 *pEMGPIOMode[4];
WCHAR EMGPIODirection[2][4];
U8 *pEMGPIODirection[2];
WCHAR EMGPIOData[2][5];
U8 *pEMGPIOData[2];
S32 Gport = 0;
S32 Gdirection = 0;
S32 Glevel = 0;
S32 Gmode = 0;
U8 unicodebuf[20];

U16 register_pmic;
U8 val_register_pmic;

#if defined(MT6318)
typedef enum
{   /* don't change the position */
    EM_PMIC_6318_CMD_R_LED = 0,
    EM_PMIC_6318_CMD_G_LED,
    EM_PMIC_6318_CMD_B_LED,
    EM_PMIC_6318_CMD_KP_LED,
    EM_PMIC_6318_CMD_BL_LED,
    EM_PMIC_6318_CMD_R_LED_CURRENT = EM_PMIC_6318_CMD_R_LED,
    EM_PMIC_6318_CMD_G_LED_CURRENT = EM_PMIC_6318_CMD_G_LED,
    EM_PMIC_6318_CMD_B_LED_CURRENT = EM_PMIC_6318_CMD_B_LED,
    EM_PMIC_6318_CMD_KP_LED_DUTY = EM_PMIC_6318_CMD_KP_LED,
    EM_PMIC_6318_CMD_BL_LED_DUTY = EM_PMIC_6318_CMD_BL_LED,

    EM_PMIC_6318_CMD_CHR_STATUS = EM_PMIC_6318_CMD_BL_LED_DUTY + 1,

    EM_PMIC_6318_CMD_SET_CHR,
    EM_PMIC_6318_CMD_SET_CHR_CURRENT = EM_PMIC_6318_CMD_SET_CHR,
    EM_PMIC_6318_CMD_SET_USB_CHR,
    EM_PMIC_6318_CMD_SET_USB_CHR_CURRENT = EM_PMIC_6318_CMD_SET_USB_CHR,

    EM_PMIC_6318_CMD_KP_DIM_CLOCK = EM_PMIC_6318_CMD_SET_USB_CHR_CURRENT + 1,
    EM_PMIC_6318_CMD_KP_CHR_PUMP,
    EM_PMIC_6318_CMD_KP_PUMP_CURRENT,

    EM_PMIC_6318_CMD_BL_DIM_CLOCK,
    EM_PMIC_6318_CMD_BL_DIM_BYPASS,

    EM_PMIC_6318_CMD_AUD_SPEAKER,
    EM_PMIC_6318_CMD_AUD_SPEAKER_GAIN,

    EM_PMIC_6318_CMD_MISC_ISENSE_OUT,
    EM_PMIC_6318_CMD_MISC_VBAT_VOUT,
    EM_PMIC_6318_CMD_MISC_USB_PWR,
    EM_PMIC_6318_CMD_MISC_VASW_SEL,
    EM_PMIC_6318_CMD_MISC_VASW,
    EM_PMIC_6318_CMD_MISC_VMC_SEL,
    EM_PMIC_6318_CMD_MISC_VMC,
    EM_PMIC_6318_CMD_MISC_VIBRATOR,
    EM_PMIC_6318_CMD_MISC_VIBRATOR_VOUT,
    EM_PMIC_6318_CMD_BL_PWM_SETTING    
} EM_PMIC_CMD_TYPE;

typedef enum
{
    EM_PMIC_6318_CHR_OV_SPI = 0,
    EM_PMIC_6318_CHR_CHRDET,
    EM_PMIC_6318_CHR_BAT_ON,
    EM_PMIC_6318_CHR_AC_DET,
    EM_PMIC_6318_CHR_USB_DET,
    EM_PMIC_6318_CHR_CV,
    EM_PMIC_6318_CHR_CHRG_DIS,
    EM_PMIC_6318_CHR_MAX
} EM_PMIC_CHR_STATUS_TYPE;

pmic_led_type gEmPmic6318LedType[5] = {R_LED, G_LED, B_LED, KP_LED, BL_LED};
pmic_led_current gEmPmic6318LedCurrent[4] = {LED_CURRENT_12, LED_CURRENT_16, LED_CURRENT_20, LED_CURRENT_24};

U8 PmicStatusString[2][3] = { "X", "ON" };
S8 EMUnicodeDisplayBuf[100 * 2];

U16 PmicChrCurrent[8] = {50, 90, 150, 225, 300, 450, 650, 800};
U16 PmicRGBCurrent[4] = {12, 16, 20, 24};

U32 gEmPmicCMDStatus = 0x8; /* Each Bit describes an specific ON/OFF status in PMIC items  */

                                                        /* 0x8 = (1000)  means KP LED default-on. */

typedef struct
{
    U8 index;
    U8 ACChrCurValue;
    U8 RCurrentValue;
    U8 GCurrentValue;
    U8 BCurrentValue;
    U8 KPDutyValue;
    U16 KPDimValue;
    U8 KPPumpCurrent;
    U8 BLDutyValue;
    U16 BLDimValue;
    U8 AudSpkGain;
    EM_PMIC_CMD_TYPE CmdType;
    S32 currBLLevel;
    U32 CurrBLFreq;
    U32 CurrBLDuty;
} em_pmic_paras_struct;

em_pmic_paras_struct g_pmic_6318_cntx = {0};

#endif /* defined(MT6318) */ 

U8 TextBuf[20];
WCHAR EMPWMLevel[5][2];
U8 *pEMPWMLevel[5];
U8 currPWM = 0;

U32 PWMFreq[CUSTOM_EM_PWM_TYPE_MAX];
U32 PWMDuty[CUSTOM_EM_PWM_TYPE_MAX];

U32 currPWMFreq;
U32 currPWMDuty;
S32 currPWMLevel = 0;
U8 freqBuf[20];
U8 dutyBuf[20];

#ifdef __MMI_BT_SUPPORT__
#define BT_ADDRESS_LEN     (12)
#define BT_PASSWORD_LEN    (16)

U8 g_bt_device_address[BT_ADDRESS_LEN * 2 + 2];
U8 g_bt_password[BT_PASSWORD_LEN * 2 + 2];
#endif /* __MMI_BT_SUPPORT__ */ 

#ifdef __MMI_FM_RADIO__
typedef struct {
    U8        MonoCurrValue;
    U8        StereoCurrValue;
    U8        RSSICurrValue;
    U8        IFCountDeltaCurrValue;
    U8        req_type;    
    U8        RSSIInfoCurrSignallevel;
    U8        RSSIInfoCurrVolume;
    U16      rssi_info_freq;
} em_dev_fm_radio_struct;

em_dev_fm_radio_struct g_fm_radio_cntx={0};

U8 fm_radio_if_count_delta[5] = { 10, 15, 20, 25, 30 };

#define EM_FM_RADIO_RSSI_INFO_DURATION 500  /* 500 ms */
#endif /* #ifdef __MMI_FM_RADIO__ */

/* =======  Device -> LCD -> Set color ========= */

typedef struct {

    U16     int_red;       /* atoi value */
    U16     int_green;       /* atoi value */
    U16     int_blue;       /* atoi value */    
    U8      red[8];
    U8      green[8];
    U8      blue[8]; 
    S8      filepath[FMGR_PATH_BUFFER_SIZE];
    MMI_BOOL is_fmgr_init;    
    S32     cur_lcd_width;
    S32     cur_lcd_height;

#ifdef GDI_USING_LAYER_COLOR_FORMAT
    PU8         buf_ptr;
    gdi_handle  color_layer_handle;

#ifdef __MMI_SUBLCD__
    PU8         buf_ptr_sub;
    gdi_handle  color_layer_handle_sub;
#endif

#endif

} em_lcm_test_struct;

em_lcm_test_struct g_lcm_test_cntx={0};



#ifdef __MMI_EM_BT_RF_TEST__

typedef struct {

    U8     test_item;      
    S32    currHoping;
    S32    currPacketType;
    U8     currCtrlPwrLevel; 
    U8     *pEMBtRfHoping[2];
    U8      channel[6];
    U8     *pEMBtRfPacketType[6];

    U8      data_len[8];
    U8      poll_period[6];    
    U8      BdAddr[26];

    U8      last_cmd;
} em_bt_rf_test_struct;

em_bt_rf_test_struct g_bt_rf_test_cntx={0};


typedef enum
{
    EM_BT_RF_TEST_TYPE_POWER_ON = 0,
    EM_BT_RF_TEST_TYPE_TX ,
    EM_BT_RF_TEST_TYPE_RX,
    EM_BT_RF_TEST_TYPE_BD_ADDR,
    EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE,
    EM_BT_RF_TEST_TYPE_PWR_CTRL_LEVEL,
    EM_BT_RF_TEST_TYPE_MAX
} EM_BT_RF_TEST_TYPE;


typedef enum
{
    EM_BT_RF_TEST_HOPING_OFF = 0,
    EM_BT_RF_TEST_HOPING_ON
} EM_BT_RF_TEST_HOPING_TYPE;


typedef enum
{
    EM_BT_RF_TEST_PACKET_TYPE_DH1 = 0,
    EM_BT_RF_TEST_PACKET_TYPE_DH3,
    EM_BT_RF_TEST_PACKET_TYPE_DH5
} EM_BT_RF_TEST_PACKET_TYPE;


#endif /* __MMI_EM_BT_RF_TEST__ */


#ifdef __MMI_BT_MTK_SUPPORT__
#define __MMI_EM_BT_GET_CHIP_VERION__
#endif /* #ifdef __MMI_BT_MTK_SUPPORT__ */

#ifdef __MMI_EM_BT_GET_CHIP_VERION__
typedef struct
{
    U16          chip_ver;
    S8           chip_name[20];
} em_bt_chip_version_struct;

em_bt_chip_version_struct em_bt_chip_version[7]=
{
  {0x0000, "Unknown|no-pwr BT"},
  {0x01E3, "MT6601 E3"},
  {0x01E5, "MT6601 E5"},
  {0x11E1, "MT6611 E1"},
  {0x11E2, "MT6611 E2"},
  {0x11E3, "MT6611 E3"},
  {0x11E4, "MT6611 E4 "}
};

typedef struct
{
    U16          lmp_ver;
    S8           lmp_name[10];
} em_bt_lmp_version_struct;

em_bt_lmp_version_struct em_bt_lmp_version[4]=
{
  {0x0120, "BT V1.2"},
  {0x0200, "BT V2.0"},
  {0x0210, "BT V2.1"},
  {0x0300, "BT V3.0"}
};
#endif /* __MMI_EM_BT_GET_CHIP_VERION__ */


/**************************************************************/
/*********************** Extern functions *************************/
/**************************************************************/
extern void BatteryStatusRsp(void *info);
extern void GpioDetectInd(void *info);
extern void IdleScreenChargerConnected(U8 playtone);
extern void IdleScreenChargerDisconnected(void);
extern void IdleScreenBatteryFullCharged(void);
extern void BatteryStatusIndication(U8 battery_voltage);
extern void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId);

extern S8 *release_verno(void);

/**************************************************************/
/*********************** Code Body**** *************************/
/**************************************************************/

/****************************************
 **
 ** Menu Tree: Device --> LCD
 **
 ****************************************/
#define ___EM_DEVICE_LCD___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmLCDMenu, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmLCDMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmLCDMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_MENU_ID, NULL, EntryEmLCDMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_LCD_MENU_ID);
    nItems = GetNumOfChild(EM_DEV_LCD_MENU_ID);
    GetSequenceStringIds(EM_DEV_LCD_MENU_ID, ItemList);
    SetParentHandler(EM_DEV_LCD_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    ShowCategory52Screen(
        EM_DEV_LCD_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#undef ___EM_DEVICE_LCD___

/***********************************************
 **
 ** Menu Tree: Device --> LCD --> Main LCD
 **
 ***********************************************/
#define ___EM_DEVICE_LCD_MainLCD___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDMain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmLCDMainMenu, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmLCDMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmLCDMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_MAIN_MENU_ID, NULL, EntryEmLCDMainMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_LCD_MAIN_MENU_ID);
    nItems = GetNumOfChild(EM_DEV_LCD_MAIN_MENU_ID);
    GetSequenceStringIds(EM_DEV_LCD_MAIN_MENU_ID, ItemList);
    SetParentHandler(EM_DEV_LCD_MAIN_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    ShowCategory52Screen(
        EM_DEV_LCD_MAIN_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    LCDSetting.Type = CUSTOM_EM_LCD_MAIN;
    custom_em_lcd_get_value(&LCDSetting.Param, LCDSetting.Type);
}

#undef ___EM_DEVICE_LCD_MainLCD___

/***********************************************
 **
 ** Menu Tree: Device --> LCD --> Sub LCD
 **
 ***********************************************/
#define ___EM_DEVICE_LCD_SubLCD___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDSub
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDSub(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmLCDSubMenu, KEY_EVENT_UP);
#else /* __MMI_SUBLCD__ */ 
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
#endif /* __MMI_SUBLCD__ */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmLCDSubMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmLCDSubMenu(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_SUB_MENU_ID, NULL, EntryEmLCDSubMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_LCD_SUB_MENU_ID);
    nItems = GetNumOfChild(EM_DEV_LCD_SUB_MENU_ID);
    GetSequenceStringIds(EM_DEV_LCD_SUB_MENU_ID, ItemList);
    SetParentHandler(EM_DEV_LCD_SUB_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    ShowCategory52Screen(
        EM_DEV_LCD_SUB_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    LCDSetting.Type = CUSTOM_EM_LCD_SUB;
    custom_em_lcd_get_value(&LCDSetting.Param, LCDSetting.Type);

#endif /* __MMI_SUBLCD__ */ 
}

#undef ___EM_DEVICE_LCD_SubLCD___

/**********************************************************
 **
 ** Menu Tree: Device --> LCD --> (Main/Sub LCD) --> Set Contrast
 **
 **********************************************************/
#define ___EM_DEVICE_LCD_SetContrast___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDSetContrast
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDSetContrast(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmLCDSetContrast, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmLCDSetContrast
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmLCDSetContrast(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_EDITOR_SCR_ID, NULL, NULL, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_LCD_EDITOR_SCR_ID);

    kal_wsprintf(InputBuf, "%d", LCDSetting.Param.contrast[0]);
    /* ShowCategory16Screen(STR_GLOBAL_OK,NULL,STR_GLOBAL_BACK,NULL,(U8*)InputBuf, 8,history_buffer); */
    ShowCategory5Screen(
        EM_DEV_LCD_SET_PARAM_1_TEXT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmLCDSetLCDHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    /* SetCategory16RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP); */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    LCDSetting.Count = 0;
    LCDSetting.Func = CUSTOM_EM_LCD_FUNC_CONSTRAST;

}


/*****************************************************************************
 * FUNCTION
 *  LSKEmLCDSetLCDHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LSKEmLCDSetLCDHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Arg = 0;
    U8 Idx = 0;
    U8 *Param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2_to_asc((S8*) LCDSetting.ParamBuf, (S8*) InputBuf);
    Arg = atoi((S8*) LCDSetting.ParamBuf);
    if (Arg > 255)
    {
        Arg = 255;
    }

    switch (LCDSetting.Func)
    {
        case CUSTOM_EM_LCD_FUNC_BIAS:
            Idx = LCDSetting.Param.bias_idx;
            LCDSetting.Param.bias[LCDSetting.Count] = (U8) Arg;
            Param = LCDSetting.Param.bias;
            break;
        case CUSTOM_EM_LCD_FUNC_CONSTRAST:
            Idx = LCDSetting.Param.contrast_idx;
            LCDSetting.Param.contrast[LCDSetting.Count] = (U8) Arg;
            Param = LCDSetting.Param.contrast;
            break;
        case CUSTOM_EM_LCD_FUNC_LINERATE:
            Idx = LCDSetting.Param.linerate_idx;
            LCDSetting.Param.linerate[LCDSetting.Count] = (U8) Arg;
            Param = LCDSetting.Param.linerate;
            break;
        case CUSTOM_EM_LCD_FUNC_TEMPCOM:
            Idx = LCDSetting.Param.temp_compensate_idx;
            LCDSetting.Param.temp_compensate[LCDSetting.Count] = (U8) Arg;
            Param = LCDSetting.Param.temp_compensate;
            break;
        default:
            Arg = Idx;
            break;
    }

    LCDSetting.Count++;
    if (LCDSetting.Count < Idx)
    {
        EntryEmLCDSetLCDNextParam();
    }
    else
    {
        custom_em_lcd_set_value(&LCDSetting.Param, LCDSetting.Type);
        custom_em_lcd_exe_function(LCDSetting.Type, LCDSetting.Func, Param);
        EngineerModeSuccessNotice(EM_NOTICE_SUCCESS_TEXT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmLCDSetLCDNextParam
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmLCDSetLCDNextParam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;
    U32 title = EM_DEV_LCD_SET_PARAM_1_TEXT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_EDITOR_SCR_ID, NULL, NULL, NULL);

    history_buffer = GetCurrGuiBuffer(EM_DEV_LCD_EDITOR_SCR_ID);

    switch (LCDSetting.Func)
    {
        case CUSTOM_EM_LCD_FUNC_BIAS:
            kal_wsprintf(InputBuf, "%d", LCDSetting.Param.bias[LCDSetting.Count]);
            break;
        case CUSTOM_EM_LCD_FUNC_CONSTRAST:
            kal_wsprintf(InputBuf, "%d", LCDSetting.Param.contrast[LCDSetting.Count]);
            break;
        case CUSTOM_EM_LCD_FUNC_LINERATE:
            kal_wsprintf(InputBuf, "%d", LCDSetting.Param.linerate[LCDSetting.Count]);
            break;
        case CUSTOM_EM_LCD_FUNC_TEMPCOM:
            kal_wsprintf(InputBuf, "%d", LCDSetting.Param.temp_compensate[LCDSetting.Count]);
            break;
        default:
            kal_wsprintf(InputBuf, "");
            break;
    }
    title = EM_DEV_LCD_SET_PARAM_1_TEXT + LCDSetting.Count;

    ShowCategory5Screen(
        (U16) title,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmLCDSetLCDHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    /* SetCategory16RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP); */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

#undef ___EM_DEVICE_LCD_SetContrast___

/***********************************************************
 **
 ** Menu Tree: Device --> LCD --> (Main/Sub LCD) --> Set Bias Ratio
 **
 ***********************************************************/
#define ___EM_DEVICE_LCD_SetBiasRatio___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDSetBias
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDSetBias(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmLCDSetBias, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmLCDSetBias
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmLCDSetBias(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_EDITOR_SCR_ID, NULL, NULL, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_LCD_EDITOR_SCR_ID);

    kal_wsprintf(InputBuf, "%d", LCDSetting.Param.bias[0]);
    ShowCategory5Screen(
        EM_DEV_LCD_SET_PARAM_1_TEXT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmLCDSetLCDHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    LCDSetting.Count = 0;
    LCDSetting.Func = CUSTOM_EM_LCD_FUNC_BIAS;
}

/***********************************************************
 **
 ** Menu Tree: Device --> LCD --> (Main/Sub LCD) --> Set Line Rate
 **
 ***********************************************************/


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDSetLineRate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDSetLineRate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmLCDSetLineRate, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmLCDSetLineRate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmLCDSetLineRate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_EDITOR_SCR_ID, NULL, NULL, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_LCD_EDITOR_SCR_ID);

    kal_wsprintf(InputBuf, "%d", LCDSetting.Param.linerate[0]);
    ShowCategory5Screen(
        EM_DEV_LCD_SET_PARAM_1_TEXT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmLCDSetLCDHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    LCDSetting.Count = 0;
    LCDSetting.Func = CUSTOM_EM_LCD_FUNC_LINERATE;
}

#undef ___EM_DEVICE_LCD_SetBiasRatio___

/***********************************************************
 **
 ** Menu Tree: Device --> LCD --> (Main/Sub LCD) --> Set Temperature
 **
 ***********************************************************/
#define ___EM_DEVICE_LCD_SetTemperature___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDSetTemperature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDSetTemperature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EnrtyEmLCDSetTemperature, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EnrtyEmLCDSetTemperature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnrtyEmLCDSetTemperature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_EDITOR_SCR_ID, NULL, NULL, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_LCD_EDITOR_SCR_ID);

    kal_wsprintf(InputBuf, "%d", LCDSetting.Param.temp_compensate[0]);
    ShowCategory5Screen(
        EM_DEV_LCD_SET_PARAM_1_TEXT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmLCDSetLCDHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    /* SetCategory16RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP); */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    LCDSetting.Count = 0;
    LCDSetting.Func = CUSTOM_EM_LCD_FUNC_TEMPCOM;

}

#undef ___EM_DEVICE_LCD_SetTemperature___


/**************************************************************

	FUNCTION NAME		: ExitEmLCDInlineScreen()

  	PURPOSE				: nil

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void ExitEmLCDInlineScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDSetColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDSetColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EnrtyEmLCDSetColor, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EnrtyEmLCDSetColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnrtyEmLCDSetColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    U16 ImageList[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_LCD_EDITOR_SCR_ID, ExitEmLCDInlineScreen, EnrtyEmLCDSetColor, NULL);
    InitializeCategory57Screen();
    
    guiBuffer = GetCurrGuiBuffer(EM_DEV_LCD_EDITOR_SCR_ID);

    /* Red */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*)GetString(EM_DEV_LCD_RGB_R_TEXT));
    ImageList[0] = IMG_STATUS;
       
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8)g_lcm_test_cntx.red, 4, INPUT_TYPE_NUMERIC);
    ImageList[1] = 0;

    /* Green */
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*)GetString(EM_DEV_LCD_RGB_G_TEXT));
    ImageList[2] = IMG_STATUS;
       
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[3], (PU8)g_lcm_test_cntx.green, 4, INPUT_TYPE_NUMERIC);
    ImageList[3] = 0;

    /* Blue */
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*)GetString(EM_DEV_LCD_RGB_B_TEXT));
    ImageList[4] = IMG_STATUS;
       
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[5], (PU8)g_lcm_test_cntx.blue, 4, INPUT_TYPE_NUMERIC);
    ImageList[5] = 0;

    DisableCategory57ScreenDone();

    ShowCategory57Screen(EM_DEV_LCD_SET_COLOR_TEXT, 0, 
       	                 STR_GLOBAL_OK, 
       	                 IMG_GLOBAL_OK, 
       	                 STR_GLOBAL_BACK, 
       	                 IMG_GLOBAL_BACK,
				         6, ImageList, wgui_inline_items, 0, guiBuffer);	
      
    SetCategory57RightSoftkeyFunctions( EMLCMSetColorSendReq, GoBackHistory );

	SetCategory57LeftSoftkeyFunction(EMLCMSetColorSendReq);    

}


/**************************************************************

	FUNCTION NAME		: EMLCMSetColorSendReq

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void EMLCMSetColorSendReq(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    result = EMLCMSetColorCheckParameter();

    if (result == MMI_FALSE)
    {
        DisplayPopup((PU8)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
 	    return;
    }
    else
    {
        EMLCDSetColor((U8)g_lcm_test_cntx.int_red, (U8)g_lcm_test_cntx.int_green, (U8)g_lcm_test_cntx.int_blue);
    }
        
}


/**************************************************************

	FUNCTION NAME		: EMLCMSetColorCheckParameter

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
MMI_BOOL EMLCMSetColorCheckParameter(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  textbuf[20];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* To check input data is not NULL */
    if (!mmi_ucs2strlen((const S8*)g_lcm_test_cntx.red)
           ||  !mmi_ucs2strlen((const S8*)g_lcm_test_cntx.green)
           ||  !mmi_ucs2strlen((const S8*)g_lcm_test_cntx.blue))
        return MMI_FALSE;

    /* To check if Red is valid */    
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_lcm_test_cntx.red);
    g_lcm_test_cntx.int_red = atoi((const char *) textbuf);
    if (g_lcm_test_cntx.int_red > 255)
        return MMI_FALSE;
        
    /* To check if Green is valid */    
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_lcm_test_cntx.green);
    g_lcm_test_cntx.int_green = atoi((const char *) textbuf);
    if (g_lcm_test_cntx.int_green > 255)
        return MMI_FALSE;

    /* To check if Blue is valid */    
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_lcm_test_cntx.blue);
    g_lcm_test_cntx.int_blue = atoi((const char *) textbuf);
    if (g_lcm_test_cntx.int_blue > 255)
        return MMI_FALSE;

    return MMI_TRUE;        
}


/*****************************************************************************
 * FUNCTION
 *  EMLCDSetColor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMLCDSetColor(U8 red, U8 green, U8 blue)
{
#ifndef GDI_USING_LAYER_COLOR_FORMAT    
    BOOL source_key_enable;
    gdi_color source_key_value;
#endif

#ifdef __MMI_SUBLCD__    
    S32 lcd_width;
    S32 lcd_height;
#endif
    
    EntryNewScreen(GLOBAL_SCR_DUMMY, EMLCDSetColorExit, NULL, NULL);

    ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_OK, 0, NULL, NULL); 
    
    SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);

    /* Disable MMI Backlight Sleep mode */
    TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
    
    /* this will force title status to redraw (Main LCD) */
    entry_full_screen();
    
    /* this will force title status to redraw (Sub LCD) */
    hide_status_icon_bar(2);
    
    /* Stop playing Background LED pattern */
    StopLEDPatternBackGround();
    
    /* Turn Off Keypad light */
    KeyPadBackLightOff();

#ifdef GDI_USING_LAYER_COLOR_FORMAT

    /*************************/
    /* Set color to Main LCD */
    /*************************/    

    /* color layer */
    g_lcm_test_cntx.buf_ptr = (PU8) mmi_frm_scrmem_alloc((UI_device_width*UI_device_height*24)>>3);
    ASSERT(g_lcm_test_cntx.buf_ptr != NULL);

    /* create 24bit layer */
    gdi_layer_create_cf_using_outside_memory(   
        GDI_COLOR_FORMAT_24,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &g_lcm_test_cntx.color_layer_handle,
        (PU8) g_lcm_test_cntx.buf_ptr,
        (S32) ((UI_device_width*UI_device_height*24)>>3));
            
    gdi_layer_push_and_set_active(g_lcm_test_cntx.color_layer_handle);

    /* Disable GDI layer TRANSPARENT COLOR */        
    gdi_layer_set_source_key(FALSE,0);
        
    gdi_draw_solid_rect(0, 0, 
                        UI_device_width-1, 
                        UI_device_height-1, 
                        gdi_act_color_from_rgb(255,(U32)red, (U32)green, (U32)blue));

    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_lcm_test_cntx.color_layer_handle, 0, 0, 0);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    #ifdef __MMI_SUBLCD__

    /************************/
    /* Set color to Sub LCD */
    /************************/

    /* activate SUB lcd handle */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    gdi_layer_reset_clip();

    /* color layer */
    g_lcm_test_cntx.buf_ptr_sub = (PU8) mmi_frm_scrmem_alloc((lcd_width*lcd_height*24)>>3);
    ASSERT(g_lcm_test_cntx.buf_ptr_sub != NULL);

    /* create 24 bits layer */
    gdi_layer_create_cf_using_outside_memory(   
        GDI_COLOR_FORMAT_24,
        0,
        0,
        lcd_width,
        lcd_height,
        &g_lcm_test_cntx.color_layer_handle_sub,
        (PU8) g_lcm_test_cntx.buf_ptr_sub,
        (S32) ((lcd_width*lcd_height*24)>>3));
            
    gdi_layer_push_and_set_active(g_lcm_test_cntx.color_layer_handle_sub);

    /* Disable GDI layer TRANSPARENT COLOR */        
    gdi_layer_set_source_key(FALSE,0);
        
    gdi_draw_solid_rect(0, 0, 
                        lcd_width-1, 
                        lcd_height-1, 
                        gdi_act_color_from_rgb(255,(U32)red, (U32)green, (U32)blue));

    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_lcm_test_cntx.color_layer_handle_sub, 0, 0, 0);
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);

    /* activate Main LCD handle */
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    #endif /* #ifdef __MMI_SUBLCD__ */
    
#else /* #ifdef GDI_USING_LAYER_COLOR_FORMAT*/

    /*************************/
    /* Set color to Main LCD */
    /*************************/    
    gui_lock_double_buffer();

    /* Get gdi layer source key enable & source key value (TRANSPARENT COLOR) */
    gdi_layer_get_source_key(&source_key_enable,&source_key_value);
        
    /* Disable GDI layer TRANSPARENT COLOR */
    gdi_layer_set_source_key(FALSE,0);
        
    gdi_draw_solid_rect(0, 0, 
                        UI_device_width-1, 
                        UI_device_height-1, 
                        gdi_act_color_from_rgb(255,(U32)red, (U32)green, (U32)blue));

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);

    /* reset GDI layer TRANSPARENT COLOR */
    gdi_layer_set_source_key(source_key_enable,source_key_value);
        
    #ifdef __MMI_SUBLCD__
    /************************/
    /* Set color to Sub LCD */
    /************************/
    
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gui_lock_double_buffer();

    /* Get gdi layer source key enable & source key value (TRANSPARENT COLOR) */
    gdi_layer_get_source_key(&source_key_enable,&source_key_value);

    /* Disable GDI layer TRANSPARENT COLOR */        
    gdi_layer_set_source_key(FALSE,0);

    gdi_draw_solid_rect(0, 0, lcd_width-1, lcd_height-1, 
                        gdi_act_color_from_rgb(255,(U32)red, (U32)green, (U32)blue));

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0,0,lcd_width-1,lcd_height-1);

    /* reset GDI layer TRANSPARENT COLOR */
    gdi_layer_set_source_key(source_key_enable,source_key_value);
        
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    #endif /* #ifdef __MMI_SUBLCD__ */    
    
#endif /* #ifdef GDI_USING_LAYER_COLOR_FORMAT*/
                        
}

       
/*****************************************************************************
 * FUNCTION
 *  EMLCDSetColorExit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMLCDSetColorExit(void)
{
#ifdef GDI_USING_LAYER_COLOR_FORMAT

    /* free main lcd test occupied buffer */
    gdi_layer_free(g_lcm_test_cntx.color_layer_handle);
    mmi_frm_scrmem_free((void*)g_lcm_test_cntx.buf_ptr);    
    g_lcm_test_cntx.buf_ptr = NULL;

#ifdef __MMI_SUBLCD__
    /* free sub lcd test occupied buffer */
    gdi_layer_free(g_lcm_test_cntx.color_layer_handle_sub);
    mmi_frm_scrmem_free((void*)g_lcm_test_cntx.buf_ptr_sub);    
    g_lcm_test_cntx.buf_ptr_sub = NULL;
#endif /* #ifdef __MMI_SUBLCD__ */    
    
#endif /* #ifdef GDI_USING_LAYER_COLOR_FORMAT */

    /* Resume backlight timer */
    TurnOffBacklight();
    
    /* Resume playing Background LED pattern */
    StartLEDPatternBackGround();
    
    /* Resume SubLCD status redraw */
    show_status_icon_bar(2);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmLCDDiplayDemoPic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmLCDDiplayDemoPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EnrtyEmLCDDisplayDemoPic, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EnrtyEmLCDDisplayDemoPic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnrtyEmLCDDisplayDemoPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);    

#ifdef __MMI_FILE_MANAGER__
    mmi_fmgr_select_path_and_enter(
        APP_ENGINEERMODE,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root",
        EMLcdDisplayDemoPicSelected);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EMLcdDisplayDemoPicSelected
 * DESCRIPTION
 *  folder selected
 * PARAMETERS
 *  path            [IN]        Selected folder path
 *  is_short        [IN]        Is short filename
 * RETURNS
 *  void
 *****************************************************************************/
void EMLcdDisplayDemoPicSelected(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        //DeleteUptoScrID(EM_DEV_LCD_MENU_ID);
        GoBackHistory();
        return;
    }

    mmi_ucs2cpy((PS8) g_lcm_test_cntx.filepath, (PS8) path);

    /* enter Display Demo Picture screen */
    EMLcdDisplayDemoPicScr();

}


/*****************************************************************************
 * FUNCTION
 *  EMLcdDisplayDemoPicScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMLcdDisplayDemoPicScr(void)
{
    EntryNewScreen(EM_DEV_LCD_EDITOR_SCR_ID, EMLCDDisplayDemoPicExit, NULL, NULL);

    /* this will force title status to redraw */
    entry_full_screen();

    /* this will force title status to redraw (Sub LCD) */
    hide_status_icon_bar(2);
    
    /* stop MMI sleep */
    TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
    
    /* Stop playing Background LED pattern */
    StopLEDPatternBackGround();
    
    /* Turn Off Keypad light */
    KeyPadBackLightOff();

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    /* clear all keys handler */
    ClearInputEventHandler(MMI_DEVICE_ALL);

    g_lcm_test_cntx.is_fmgr_init = MMI_FALSE;
    
    EMLcdDisplayDemoPic();

    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    
}


/*****************************************************************************
 * FUNCTION
 *  EMLCDDisplayDemoPicExit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMLCDDisplayDemoPicExit(void)
{
    /* Resume backlight timer */
    TurnOffBacklight();    

    /* Resume playing Background LED pattern */
    StartLEDPatternBackGround();    

    /* Resume SubLCD status redraw */
    show_status_icon_bar(2);    
}


/*****************************************************************************
 * FUNCTION
 *  EMLcdDisplayDemoPic
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMLcdDisplayDemoPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S8 filepath[FMGR_PATH_BUFFER_SIZE];    
    S32 image_width;
    S32 image_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    GDI_RESULT gdi_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info((S32) (mmi_fmgr_kernel_get_cur_idx()), &file_info);

    if (FMGR_FILTER_IS_SET_IMAGE(&file_info.file_type))
    {
        /* Image Type */
        mmi_ucs2cpy(filepath, g_lcm_test_cntx.filepath);

        gdi_image_get_dimension_file(filepath, &image_width, &image_height);

        /* Draw image to Main LCD */
        g_lcm_test_cntx.cur_lcd_width = UI_device_width;
        g_lcm_test_cntx.cur_lcd_height = UI_device_height;

        gdi_layer_reset_clip();
        gdi_layer_clear(GDI_COLOR_BLACK);

        if ((g_lcm_test_cntx.cur_lcd_width >= image_width) && (g_lcm_test_cntx.cur_lcd_height >= image_height))
        {
            /* align preview window at the center of screen */
            image_offset_x = (g_lcm_test_cntx.cur_lcd_width - image_width) >> 1;
            image_offset_y = (g_lcm_test_cntx.cur_lcd_height - image_height) >> 1;

            gdi_ret = gdi_image_draw_file(image_offset_x, image_offset_y, (PS8) filepath);
        }
        else
        {
            /* resize */
            gdi_image_util_fit_bbox(g_lcm_test_cntx.cur_lcd_width, g_lcm_test_cntx.cur_lcd_height,
                                    image_width,
                                    image_height,
                                    &resized_offset_x,
                                    &resized_offset_y,
                                    &resized_width,
                                    &resized_height);

            gdi_ret = gdi_image_draw_resized_file(resized_offset_x, resized_offset_y,
                                                  resized_width,
                                                  resized_height,
                                                  filepath);
        }

        if (gdi_ret != GDI_SUCCEED)
        {
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! ERROR !!!");
        }
        gui_BLT_double_buffer(0,0,g_lcm_test_cntx.cur_lcd_width-1,g_lcm_test_cntx.cur_lcd_height-1);


    #ifdef __MMI_SUBLCD__
    
        /* Draw image to Sub LCD */
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_get_dimension(&g_lcm_test_cntx.cur_lcd_width, &g_lcm_test_cntx.cur_lcd_height);
        gdi_layer_reset_clip();
        gdi_layer_clear(GDI_COLOR_BLACK);

        if ((g_lcm_test_cntx.cur_lcd_width >= image_width) && (g_lcm_test_cntx.cur_lcd_height >= image_height))
        {
            /* align preview window at the center of screen */
            image_offset_x = (g_lcm_test_cntx.cur_lcd_width - image_width) >> 1;
            image_offset_y = (g_lcm_test_cntx.cur_lcd_height - image_height) >> 1;

            gdi_ret = gdi_image_draw_file(image_offset_x, image_offset_y, (PS8) filepath);
        }
        else
        {
            /* resize */
            gdi_image_util_fit_bbox(g_lcm_test_cntx.cur_lcd_width, g_lcm_test_cntx.cur_lcd_height,
                                    image_width,
                                    image_height,
                                    &resized_offset_x,
                                    &resized_offset_y,
                                    &resized_width,
                                    &resized_height);

            gdi_ret = gdi_image_draw_resized_file(resized_offset_x, resized_offset_y,
                                                  resized_width,
                                                  resized_height,
                                                  filepath);
        }
       
        if (gdi_ret != GDI_SUCCEED)
        {
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! ERROR !!!");
        }
        gui_BLT_double_buffer(0,0,g_lcm_test_cntx.cur_lcd_width-1,g_lcm_test_cntx.cur_lcd_height-1);

    #endif /* __MMI_SUBLCD__ */
    
    }
    else
    {
        DisplayPopup((PU8)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
        DeleteUptoScrID(EM_DEV_LCD_MENU_ID);
        return;
    }
}


/****************************************
 **
 ** Menu Tree: Device --> GPIO
 **
 ****************************************/
#define ___EM_DEVICE_GPIO___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmGPIO
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmGPIO(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmGPIOMenu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmGPIOMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmGPIOMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_GPIO_SCR_ID, NULL, EntryEmGPIOMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_GPIO_SCR_ID);
    nItems = GetNumOfChild(EM_DEV_GPIO_MENU_ID);
    GetSequenceStringIds(EM_DEV_GPIO_MENU_ID, ItemList);
    SetParentHandler(EM_DEV_GPIO_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    ShowCategory52Screen(
        EM_DEV_GPIO_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    gGPIOState = 0x0;
    gGPOState = 0x0;
    memset(InputBuf, 0, sizeof(InputBuf));
}

#undef ___EM_DEVICE_GPIO___

/****************************************
 **
 ** Menu Tree: Device --> GPIO --> List
 **
 ****************************************/
#define ___EM_DEVICE_GPIO_List___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmGPIOList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmGPIOList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmGPIOListMenu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightOnCertainEmGPIO
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOnCertainEmGPIO(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentHighlightIndex = (U8) nIndex;
    Idx = EmGpioIdxMenu2Tbl[currentHighlightIndex];

    if (((gpio_map_tbl[Idx].vaild == GPIO_VAILD) && IS_GPIO_SET(gpio_map_tbl[Idx].port))
        || ((gpio_map_tbl[Idx].vaild == GPO_VAILD) && IS_GPO_SET(gpio_map_tbl[Idx].port)))
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else if ((gpio_map_tbl[Idx].vaild == GPIO_VAILD) || (gpio_map_tbl[Idx].vaild == GPO_VAILD))
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ERROR, 0);
    }

    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EmPrepareGPIOList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPrepareGPIOList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j = 0;
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMenuListNum = 0;
    for (i = 0; i < GPIO_LABELID_MAX; i++)
    {
        if (gpio_map_tbl[i].vaild == GPIO_VAILD)
        {
            EmGpioIdxMenu2Tbl[j] = (U8) i;
            j++;
            sprintf(buffer, "%s", gpio_map_tbl[i].netname);
            mmi_asc_to_ucs2((PS8) subMenuData[gMenuListNum], buffer);
            subMenuDataPtrs[gMenuListNum] = subMenuData[gMenuListNum];
            gMenuListNum++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmGPIOListMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmGPIOListMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_GPIO_LIST_SCR_ID, NULL, EntryEmGPIOListMenu, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_DEV_GPIO_LIST_SCR_ID);

    RegisterHighlightHandler(HighlightOnCertainEmGPIO);

    EmPrepareGPIOList();
    if (gMenuListNum < 1)
    {
        ShowCategory6Screen(
            EM_DEV_GPIO_LIST_TEXT,
            0,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            gMenuListNum + 1,
            (PU8*) subMenuDataPtrs,
            NULL,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory6Screen(
            EM_DEV_GPIO_LIST_TEXT,
            0,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            gMenuListNum,
            (PU8*) subMenuDataPtrs,
            NULL,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(LSKEmGPIOListMenu, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  LSKEmGPIOListMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LSKEmGPIOListMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Idx = EmGpioIdxMenu2Tbl[currentHighlightIndex];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gpio_map_tbl[Idx].vaild)
    {
        case GPIO_VAILD:
            if (IS_GPIO_SET(gpio_map_tbl[Idx].port))
            {
                change_left_softkey(STR_GLOBAL_ON, 0);
                custom_em_gpio_stop(gpio_map_tbl[Idx].port);
            }
            else
            {
                change_left_softkey(STR_GLOBAL_OFF, 0);
                custom_em_gpio_start(gpio_map_tbl[Idx].port);
            }
            GPIO_STATE_TOGGLE(gpio_map_tbl[Idx].port);
            break;

        case GPO_VAILD:
            if (IS_GPO_SET(gpio_map_tbl[Idx].port))
            {
                change_left_softkey(STR_GLOBAL_ON, 0);
                custom_em_gpo_stop(gpio_map_tbl[Idx].port);
            }
            else
            {
                change_left_softkey(STR_GLOBAL_OFF, 0);
                custom_em_gpo_start(gpio_map_tbl[Idx].port);
            }
            GPO_STATE_TOGGLE(gpio_map_tbl[Idx].port);
            break;

        default:
            break;
    }

    redraw_left_softkey();

}

#undef ___EM_DEVICE_GPIO_List___

/****************************************
 **
 ** Menu Tree: Device --> GPIO --> Set
 **
 ****************************************/
#define ___EM_DEVICE_GPIO_Set___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmGPIOSet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmGPIOSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentHighlightIndex = SET_GPIO_ACTION;
    SetLeftSoftkeyFunction(EntryEmGPIOSet, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmGPOSet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmGPOSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentHighlightIndex = SET_GPO_ACTION;
    SetLeftSoftkeyFunction(EntryEmGPIOSet, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmGPIOSet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmGPIOSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;
    U16 text_id = EM_STR_GPIO_EDITOR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currentHighlightIndex == SET_GPO_ACTION)
    {
        text_id = EM_STR_GPO_EDITOR;
    }
    else
    {
        text_id = EM_STR_GPIO_EDITOR;
    }

    EntryNewScreen(EM_DEV_GPIO_EDITOR_SCR_ID, NULL, EntryEmGPIOSet, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_GPIO_EDITOR_SCR_ID);

    /* ShowCategory16Screen(STR_GLOBAL_OK,NULL,STR_GLOBAL_BACK,NULL,(U8*)InputBuf, 8,history_buffer); */
    ShowCategory5Screen(
        text_id,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmGPIOSetCertain, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ExitEMGPIODetail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEMGPIODetail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    currHistory.scrnID = EM_DEV_GPIO_VIEWER_SCR_ID;
    currHistory.entryFuncPtr = EntryEMGPIODetail;

    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  EMGPIOHighlightHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMGPIOHighlightHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  EMGPIODoneFunc
 * DESCRIPTION
 *  Set GPIO parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMGPIODoneFunc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GPIOACTION == KAL_TRUE)
    {
        GPIO_ModeSetup((kal_uint16) Gport, (kal_uint16) Gmode);
        /* DIRECTION............................ */
        GPIO_WriteIO((char)Glevel, (char)Gport);
    }
    else
    {
        GPO_ModeSetup((kal_uint16) Gport, (kal_uint16) Gmode);
        GPO_WriteIO((char)Glevel, (char)Gport);
    }
    /* DisplayPopup((PU8)GetString(EM_NOTICE_SUCCESS_TEXT), IMG_GLOBAL_DEFAULT, 0, EM_NOTIFY_DURATION, 0); */
    EngineerModeSuccessNotice(EM_NOTICE_SUCCESS_TEXT);
    DeleteScreenIfPresent(EM_DEV_GPIO_VIEWER_SCR_ID);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEMGPIODetail
 * DESCRIPTION
 *  Show GPIO detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEMGPIODetail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 ImageList[7];
    U8 textbuf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_GPIO_VIEWER_SCR_ID, ExitEMGPIODetail, NULL, NULL);
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(EM_DEV_GPIO_VIEWER_SCR_ID);

    inputBuffer = GetCurrNInputBuffer(EM_DEV_GPIO_VIEWER_SCR_ID, &inputBufferSize);

    RegisterHighlightHandler(EMGPIOHighlightHandler);

    /* PORT */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (GPIOACTION == KAL_TRUE)
    {
        sprintf((S8*) textbuf, "GPIO %d", (U16) Gport);
    }
    else
    {
        sprintf((S8*) textbuf, "GPO %d", (U16) Gport);
    }

    mmi_asc_to_ucs2((S8*) unicodebuf, (S8*) textbuf);
    SetInlineItemDisplayOnly(&wgui_inline_items[0], unicodebuf);
    /* DisableInlineItemHighlight(&wgui_inline_items[0]); */
    ImageList[0] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[1]), (U8*) GetString(EM_STR_GPIO_LEVEL));
    ImageList[1] = IMG_STATUS;

    /* Level */
    kal_wstrcpy((WCHAR*) EMGPIOData[0], (const WCHAR*)kal_toWCHAR("Low"));
    pEMGPIOData[0] = (U8*) (EMGPIOData[0]);
    kal_wstrcpy((WCHAR*) EMGPIOData[1], (const WCHAR*)kal_toWCHAR("High"));
    pEMGPIOData[1] = (U8*) (EMGPIOData[1]);
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[2], 2, (U8 **) & pEMGPIOData, (S32*) & Glevel);
    ImageList[2] = EM_DEV_GPIO_SET_ICON;

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[3]), (U8*) GetString(EM_STR_GPIO_MODE));
    ImageList[3] = IMG_STATUS;

    /* Mode */
    kal_wstrcpy((WCHAR*) EMGPIOMode[0], (const WCHAR*)kal_toWCHAR("0"));
    pEMGPIOMode[0] = (U8*) (EMGPIOMode[0]);
    kal_wstrcpy((WCHAR*) EMGPIOMode[1], (const WCHAR*)kal_toWCHAR("1"));
    pEMGPIOMode[1] = (U8*) (EMGPIOMode[1]);
    kal_wstrcpy((WCHAR*) EMGPIOMode[2], (const WCHAR*)kal_toWCHAR("2"));
    pEMGPIOMode[2] = (U8*) (EMGPIOMode[2]);
    kal_wstrcpy((WCHAR*) EMGPIOMode[3], (const WCHAR*)kal_toWCHAR("3"));
    pEMGPIOMode[3] = (U8*) (EMGPIOMode[3]);
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[4], 4, (U8 **) & pEMGPIOMode, (S32*) & Gmode);
    ImageList[4] = EM_DEV_GPIO_SET_ICON;

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[5]), (U8*) GetString(EM_STR_GPIO_DIRECTION));
    ImageList[5] = IMG_STATUS;

    /* Direction */
    if (GPIOACTION == KAL_TRUE)
    {
        kal_wstrcpy((WCHAR*) EMGPIODirection[0], (const WCHAR*)kal_toWCHAR("IN"));
        pEMGPIODirection[0] = (U8*) (EMGPIODirection[0]);
        kal_wstrcpy((WCHAR*) EMGPIODirection[1], (const WCHAR*)kal_toWCHAR("OUT"));
        pEMGPIODirection[1] = (U8*) (EMGPIODirection[1]);
        SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[6], 2, (U8 **) & pEMGPIODirection, (S32*) & Gdirection);
    }
    else    /* the Direction of GPO is always OUT */
    {
        kal_wstrcpy((WCHAR*) EMGPIODirection[0], (const WCHAR*)kal_toWCHAR("OUT"));
        pEMGPIODirection[0] = (U8*) (EMGPIODirection[0]);
        SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[6], 1, (U8 **) & pEMGPIODirection, (S32*) & Gdirection);
    }
    ImageList[6] = EM_DEV_GPIO_SET_ICON;

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 7, inputBuffer);
    }

    ShowCategory57Screen(
        (U16) ((GPIOACTION == KAL_TRUE) ? EM_STR_GPIO_EDITOR : EM_STR_GPO_EDITOR),
        EM_DEV_GPIO_SET_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        7,
        ImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EMGPIODoneFunc, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  LSKEmGPIOSetCertain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LSKEmGPIOSetCertain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 Arg = 0;
    U8 U8StrBuf[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) U8StrBuf, (S8*) InputBuf);
    Arg = (S8) atoi((S8*) U8StrBuf);
    /* Lisen 0906 */
    if (Arg >= GPIO_LABELID_MAX /* || Arg <= 0 */ )
    {
        EngineerModeErrorNotice((U16) NULL);
        return;
    }

    Gport = Arg;

    switch (currentHighlightIndex)
    {
        case SET_GPIO_ACTION:
            Gdirection = GPIO_ReturnDir(Arg);
            Glevel = GPIO_ReturnDout(Arg);
            Gmode = GPIO_ReturnMode(Arg);
            GPIOACTION = KAL_TRUE;
            EntryEMGPIODetail();
            break;

        case SET_GPO_ACTION:
            Gdirection = GPIO_ReturnDir(Arg);
            Glevel = GPO_ReturnDout(Arg);
            Gmode = GPO_ReturnMode(Arg);
            GPIOACTION = KAL_FALSE;
            EntryEMGPIODetail();
            break;

        default:
            EngineerModeErrorNotice((U16) NULL);
            break;
    }

}

#undef ___EM_DEVICE_GPIO_Set___

/****************************************
 **
 ** Menu Tree: Device --> PWM
 **
 ****************************************/
#define ___EM_DEVICE_PWM___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPWM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPWM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmPWMMenu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightOnCertainEmPWM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOnCertainEmPWM(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentHighlightIndex = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EmPreparePWMList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPreparePWMList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUSTOM_EM_PWM_TYPE_MAX; i++)
    {
        sprintf(buffer, "PWM%d", i + 1);
        mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
        subMenuDataPtrs[i] = subMenuData[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPWMMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPWMMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PWM_MENU_ID, NULL, EntryEmPWMMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PWM_MENU_ID);

    RegisterHighlightHandler(HighlightOnCertainEmPWM);

    EmPreparePWMList();

    ShowCategory6Screen(
        EM_DEV_PWM_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        3,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(EntryEMPWMDetail, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    PWMSetting.Count = 0;
    /* custom_em_pwm_get_value(PWMSetting.Param.freq, PWMSetting.Param.duty_cycle); */
}


/*****************************************************************************
 * FUNCTION
 *  LSKEmPWMMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LSKEmPWMMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 Arg = 0;

    U8 StrBuf[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PWMSetting.Count == 0)
    {
        EntryEmPWMSetParam();
        switch (currentHighlightIndex)
        {
            case 0:
                PWMSetting.Type = CUSTOM_EM_PWM_TYPE_1;
                break;
            case 1:
                PWMSetting.Type = CUSTOM_EM_PWM_TYPE_2;
                break;
            case 2:
                PWMSetting.Type = CUSTOM_EM_PWM_TYPE_3;
                break;
            default:
                PWMSetting.Type = CUSTOM_EM_PWM_TYPE_1;
                break;
        }
    }
    else if (PWMSetting.Count == 1)
    {
        mmi_ucs2_to_asc((S8*) StrBuf, (S8*) InputBuf);
        Arg = atoi((S8*) StrBuf);
        if (Arg > 9999999)
        {
            Arg = 9999999;
        }
        PWMSetting.Param.freq[currentHighlightIndex] = Arg;
        EntryEmPWMSetParam();
    }
    else
    {
        mmi_ucs2_to_asc((S8*) StrBuf, (S8*) InputBuf);
        Arg = atoi((S8*) StrBuf);
        if (Arg > 9999999)
        {
            Arg = 9999999;
        }
        PWMSetting.Param.duty_cycle[currentHighlightIndex] = Arg;

        if ((PWMSetting.Param.freq[currentHighlightIndex] == 0) ||
            (PWMSetting.Param.duty_cycle[currentHighlightIndex] == 0))
        {
            /* Divide by zero */
            EngineerModeErrorNotice(STR_GLOBAL_ERROR);
        }
        else
        {
            custom_em_pwm_start(
                PWMSetting.Type,
                PWMSetting.Param.freq[currentHighlightIndex],
                PWMSetting.Param.duty_cycle[currentHighlightIndex]);

            //custom_em_pwm_set_value(PWMSetting.Param.freq, PWMSetting.Param.duty_cycle);
            //EngineerModeSuccessNotice(EM_NOTICE_SUCCESS_TEXT);
            ShowCategory21Screen(
                EM_NOTICE_SUCCESS_TEXT,
                0,
                EM_DEV_PWM_STOP_TEXT,
                0,
                NULL,
                0,
                EM_DEV_PWM_START_TEXT,
                NULL);
            SetLeftSoftkeyFunction(LSKEmPWMStop, KEY_EVENT_UP);
        }

        return;
    }

    PWMSetting.Count++;

}


/*****************************************************************************
 * FUNCTION
 *  ExitEMPWMDetail
 * DESCRIPTION
 *  Show PWM detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEMPWMDetail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    currHistory.scrnID = EM_DEV_PWM_VIEWER_SCR_ID;
    currHistory.entryFuncPtr = EntryEMPWMDetail;

    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  EMPWMHighlightHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMPWMHighlightHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  EMPWMDoneFunc
 * DESCRIPTION
 *  Set GPIO parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMPWMDoneFunc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 textbuf[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    if ((!mmi_ucs2strlen((const S8*)freqBuf) && !mmi_ucs2strlen((const S8*)dutyBuf))
        || (mmi_ucs2strlen((const S8*)freqBuf) > 5 || mmi_ucs2strlen((const S8*)dutyBuf) > 3))
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
        DeleteScreenIfPresent(EM_DEV_PWM_VIEWER_SCR_ID);
        return;
    }
    /* convert the textedit buffer to currPWMFreq and currPWMDuty */
    mmi_ucs2_to_asc((PS8) textbuf, (PS8) freqBuf);
    currPWMFreq = atoi((const char*)textbuf);

    mmi_ucs2_to_asc((PS8) textbuf, (PS8) dutyBuf);
    currPWMDuty = atoi((const char*)textbuf);

    /* Set up PWMFreq and PWMDuty */
    if (currPWM == 0)
    {
        PWM1_Level_Info[currPWMLevel][0] = PWMFreq[currPWM] = currPWMFreq;
        PWM1_Level_Info[currPWMLevel][1] = PWMDuty[currPWM] = currPWMDuty;
    }
    else if (currPWM == 1)
    {
        PWM2_Level_Info[currPWMLevel][0] = PWMFreq[currPWM] = currPWMFreq;
        PWM2_Level_Info[currPWMLevel][1] = PWMDuty[currPWM] = currPWMDuty;
    }
    else if (currPWM == 2)
    {
        Alter_Level_Info[currPWMLevel][0] = PWMFreq[currPWM] = currPWMFreq;
        Alter_Level_Info[currPWMLevel][1] = PWMDuty[currPWM] = currPWMDuty;
    }

    custom_em_pwm_set_value((kal_uint16*) PWMFreq, (kal_uint8*) PWMDuty);
    custom_em_pwm_set_level(currPWM, (kal_uint8) currPWMLevel);
    custom_em_pwm_start(currPWM, currPWMFreq, currPWMDuty);

    SendSetHWLevelInfoReq();

    DeleteScreenIfPresent(EM_DEV_PWM_VIEWER_SCR_ID);
}


/*****************************************************************************
 * FUNCTION
 *  PWMLevelHighlightHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void PWMLevelHighlightHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 textbuf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currPWMLevel = index;

    if (currPWM == 0)
    {
        currPWMFreq = PWMFreq[currPWM] = PWM1_Level_Info[index][0];
        currPWMDuty = PWMDuty[currPWM] = PWM1_Level_Info[index][1];
    }
    else if (currPWM == 1)
    {
        currPWMFreq = PWMFreq[currPWM] = PWM2_Level_Info[index][0];
        currPWMDuty = PWMDuty[currPWM] = PWM2_Level_Info[index][1];
    }
    else if (currPWM == 2)
    {
        currPWMFreq = PWMFreq[currPWM] = Alter_Level_Info[index][0];
        currPWMDuty = PWMDuty[currPWM] = Alter_Level_Info[index][1];
    }

    /* Frequency */
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "%d", (U16) currPWMFreq);
    mmi_asc_to_ucs2((S8*) freqBuf, (S8*) textbuf);
    SetInlineItemTextEdit(&wgui_inline_items[4], (PU8) freqBuf, 20, INPUT_TYPE_NUMERIC);

    /* Duty */
    SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "%d", (U16) currPWMDuty);
    mmi_asc_to_ucs2((S8*) dutyBuf, (S8*) textbuf);
    SetInlineItemTextEdit(&wgui_inline_items[6], (PU8) dutyBuf, 20, INPUT_TYPE_NUMERIC);

    RedrawCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  EntryEMPWMDetail
 * DESCRIPTION
 *  Show PWM detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEMPWMDetail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 ImageList[7];
    U8 textbuf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PWM_VIEWER_SCR_ID, ExitEMPWMDetail, NULL, NULL);
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(EM_DEV_PWM_VIEWER_SCR_ID);

    inputBuffer = GetCurrNInputBuffer(EM_DEV_PWM_VIEWER_SCR_ID, &inputBufferSize);

    RegisterHighlightHandler(EMPWMHighlightHandler);

    /* Get the current setting */
    currPWM = currentHighlightIndex;
    currPWMLevel = custom_em_pwm_get_hw_current_level(currPWM) - 1;     /* 0-based */
    if (currPWMLevel >= CUSTOM_EM_PWM_LEVEL_MAX || currPWMLevel < 0)
    {
        currPWMLevel = 0;
    }

    custom_em_pwm_get_value((kal_uint16*) PWMFreq, (kal_uint8*) PWMDuty);

    if (currPWM == 0)
    {
        currPWMFreq = PWMFreq[currPWM] = PWM1_Level_Info[currPWMLevel][0];
        currPWMDuty = PWMDuty[currPWM] = PWM1_Level_Info[currPWMLevel][1];
    }
    else if (currPWM == 1)
    {
        currPWMFreq = PWMFreq[currPWM] = PWM2_Level_Info[currPWMLevel][0];
        currPWMDuty = PWMDuty[currPWM] = PWM2_Level_Info[currPWMLevel][1];
    }
    else if (currPWM == 2)
    {
        currPWMFreq = PWMFreq[currPWM] = Alter_Level_Info[currPWMLevel][0];
        currPWMDuty = PWMDuty[currPWM] = Alter_Level_Info[currPWMLevel][1];
    }

    /* PWM */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "PWM %d", currPWM + 1);
    mmi_asc_to_ucs2((S8*) unicodebuf, (S8*) textbuf);
    SetInlineItemDisplayOnly(&wgui_inline_items[0], unicodebuf);
    ImageList[0] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[1]), (U8*) GetString(EM_STR_PWM_LEVEL));
    ImageList[1] = IMG_STATUS;

    /* Level */
    kal_wstrcpy((WCHAR*) EMPWMLevel[0], (const WCHAR*)kal_toWCHAR("1"));
    pEMPWMLevel[0] = (U8*) (EMPWMLevel[0]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[1], (const WCHAR*)kal_toWCHAR("2"));
    pEMPWMLevel[1] = (U8*) (EMPWMLevel[1]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[2], (const WCHAR*)kal_toWCHAR("3"));
    pEMPWMLevel[2] = (U8*) (EMPWMLevel[2]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[3], (const WCHAR*)kal_toWCHAR("4"));
    pEMPWMLevel[3] = (U8*) (EMPWMLevel[3]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[4], (const WCHAR*)kal_toWCHAR("5"));
    pEMPWMLevel[4] = (U8*) (EMPWMLevel[4]);
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[2], 5, (U8 **) & pEMPWMLevel, (S32*) & currPWMLevel);
    ImageList[2] = 0;
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[2], PWMLevelHighlightHandler);

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[3]), (U8*) GetString(EM_STR_PWM_FREQUENCY));
    ImageList[3] = IMG_STATUS;

    /* Frequency */
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "%d", (U16) currPWMFreq);
    mmi_asc_to_ucs2((S8*) freqBuf, (S8*) textbuf);
    SetInlineItemTextEdit(&wgui_inline_items[4], (PU8) freqBuf, 20, INPUT_TYPE_NUMERIC);
    ImageList[4] = 0;

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[5]), (U8*) GetString(EM_STR_PWM_DUTY));
    ImageList[5] = IMG_STATUS;

    /* Duty */
    SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "%d", (U16) currPWMDuty);
    mmi_asc_to_ucs2((S8*) dutyBuf, (S8*) textbuf);
    SetInlineItemTextEdit(&wgui_inline_items[6], (PU8) dutyBuf, 20, INPUT_TYPE_NUMERIC);
    ImageList[6] = 0;

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 7, inputBuffer);
    }

    ShowCategory57Screen(
        EM_STR_PWM_EDITOR,
        EM_DEV_GPIO_SET_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        7,
        ImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EMPWMDoneFunc, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  LSKEmPWMStop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LSKEmPWMStop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_em_pwm_stop(PWMSetting.Type);
    custom_em_pwm_set_level(PWMSetting.Type, custom_em_pwm_get_hw_current_level(PWMSetting.Type));
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPWMSetParam
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPWMSetParam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 title = EM_DEV_PWM_SET_FREQ_TEXT;
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PWM_EDITOR_SCR_ID, NULL, NULL, NULL);

    history_buffer = GetCurrGuiBuffer(EM_DEV_PWM_EDITOR_SCR_ID);

    if (PWMSetting.Count == 0)
    {
        title = EM_DEV_PWM_SET_FREQ_TEXT;
        kal_wsprintf(InputBuf, "%d", PWMSetting.Param.freq[currentHighlightIndex]);
    }
    else
    {
        title = EM_DEV_PWM_SET_DUTY_TEXT;
        kal_wsprintf(InputBuf, "%d", PWMSetting.Param.duty_cycle[currentHighlightIndex]);
    }

    ShowCategory5Screen(
        (U16) title,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmPWMMenu, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    /* SetCategory16RightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP); */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

#undef ___EM_DEVICE_PWM___

#if defined(MT6318)


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMIC6318
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMIC6318(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmPMIC6318Menu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMIC6318Menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMIC6318Menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_SCR, NULL, EntryEmPMIC6318Menu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_SCR);

    nItems = GetNumOfChild(EM_DEV_PMIC_6318_MENU_ID);
    GetSequenceStringIds(EM_DEV_PMIC_6318_MENU_ID, ItemList);
    SetParentHandler(EM_DEV_PMIC_6318_MENU_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    ShowCategory52Screen(
        EM_DEV_PMIC_6318_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICRegisterEditor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICRegisterEditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmPMICRegisterEditor, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICRegisterEditor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICRegisterEditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_REGISTER_EDITOR_SCR, NULL, EntryEmPMICRegisterEditor, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_REGISTER_EDITOR_SCR);

    ShowCategory5Screen(
        EM_DEV_PMIC_6318_REGISTER_EDITOR_TEXT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(LSKEmPMICRegisterSetCertain, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EMPMICRegisterSendReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [IN]        
 *  register_index      [IN]        
 *  data                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMPMICRegisterSendReq(pmic_config_req_enum type, kal_uint16 register_index, kal_uint8 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_pmic_config_req_struct *msg_p;
    U8 tempbuf[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_pmic_config_req_struct));

    msg_p->request_type = type;

    switch (type)
    {
        case PMIC_READ_REG:
        {
            msg_p->request.read_reg.register_index = register_index;
            msg_p->request.read_reg.result = 0;
            break;
        }
        case PMIC_WRITE_REG:
        {
            msg_p->request.write_reg.register_index = register_index;
            msg_p->request.write_reg.data = data;
            break;
        }
        case PMIC_GET_CHR_STATE:
        {
            msg_p->request.chr_state.status = (chr_type) data;
            break;
        }
        case PMIC_GET_AC_USB:
        {
            msg_p->request.ac_usb_status.type = data;   /* 0: AC ; 1: USB */
            break;
        }
        case PMIC_CHR_ENABLE:
        {
            msg_p->request.chr_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_CHR_CURRENT_CTRL:
        {
            msg_p->request.chr_current_control.chr_current = currentHighlightIndex;
            break;
        }
        case PMIC_USB_CHR_ENABLE:
        {
            msg_p->request.usb_chr_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_GET_LED_CONFIG:
        {
            msg_p->request.led_config.type = gEmPmic6318LedType[data];
            break;
        }
        case PMIC_LED_ENABLE:
        {
            msg_p->request.led_enable.type = gEmPmic6318LedType[g_pmic_6318_cntx.CmdType];
            msg_p->request.led_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_LED_CONFIG:
        {
            msg_p->request.led_setting.led_conf.type = gEmPmic6318LedType[g_pmic_6318_cntx.CmdType];
            if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_KP_LED_DUTY)
            {
                mmi_ucs2_to_asc((S8*) tempbuf, (S8*) InputBuf);
                g_pmic_6318_cntx.KPDutyValue = atoi((S8*) tempbuf);
                if (g_pmic_6318_cntx.KPDutyValue > 100)
                {
                    g_pmic_6318_cntx.KPDutyValue = 100;
                }
                msg_p->request.led_setting.led_conf.duty_cycle = g_pmic_6318_cntx.KPDutyValue;
            }
            else if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_BL_LED_DUTY)
            {
                mmi_ucs2_to_asc((S8*) tempbuf, (S8*) InputBuf);
                g_pmic_6318_cntx.BLDutyValue = atoi((S8*) tempbuf);
                if (g_pmic_6318_cntx.BLDutyValue > 100)
                {
                    g_pmic_6318_cntx.BLDutyValue = 100;
                }
                msg_p->request.led_setting.led_conf.duty_cycle = g_pmic_6318_cntx.BLDutyValue;
            }
            else
            {
                msg_p->request.led_setting.led_conf.current = gEmPmic6318LedCurrent[data];
            }
            break;
        }
        case PMIC_RGB_DIM_CLK:
        {
            mmi_ucs2_to_asc((S8*) tempbuf, (S8*) InputBuf);
            g_pmic_6318_cntx.KPDimValue = atoi((S8*) tempbuf);
            if (g_pmic_6318_cntx.KPDimValue > 1000)
            {
                g_pmic_6318_cntx.KPDimValue = 1000;
            }
            msg_p->request.rgb_dim_clk_setting.dim_clk = g_pmic_6318_cntx.KPDimValue;
            break;
        }
        case PMIC_GET_RGB_DIM:
        {
            break;
        }
        case PMIC_CHR_PUMP_ENABLE:
        {
            msg_p->request.chr_pump_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_CHR_PUMP_CURRENT:
        {
            msg_p->request.chr_pump_current_level.level = data;
            break;
        }
        case PMIC_GET_BL_DIM:
        {
            break;
        }
        case PMIC_BL_DIV_BYPASS:
        {
            msg_p->request.bl_div_bypass_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_BL_DIM_CLK:
        {
            mmi_ucs2_to_asc((S8*) tempbuf, (S8*) InputBuf);
            g_pmic_6318_cntx.BLDimValue = atoi((S8*) tempbuf);
            if (g_pmic_6318_cntx.BLDimValue > 25000)
            {
                g_pmic_6318_cntx.BLDimValue = 25000;
            }
            msg_p->request.bl_dim_clk_setting.dim_clk = g_pmic_6318_cntx.BLDimValue;
            break;
        }
        case PMIC_GET_SPEAKER_STATE:
        {
            break;
        }
        case PMIC_GET_SPEAKER_GAIN:
        {
            break;
        }
        case PMIC_SPEAKER_ENABLE:
        {
            msg_p->request.speaker_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_SPEAKER_GAIN:
        {
            msg_p->request.speaker_gain.gain = data * 3;    /* 0-21dB, adjustmenet step=3dB */
            break;
        }
        case PMIC_GET_MISC_LDO_STATE:
        {
            msg_p->request.misc_ldo_state.type = data;
            break;
        }
        case PMIC_VIBRATOR_ENABLE:
        {
            msg_p->request.vibrator_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_VIBRATOR_SEL:
        {
            msg_p->request.vibrator_sel.value = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_VMC_ENABLE:
        {
            msg_p->request.vmc_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_VMC_SEL:
        {
            msg_p->request.vmc_sel.vmc_sel_value = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            
            break;
        }
        case PMIC_VASW_ENABLE:
        {
            msg_p->request.vasw_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_VASW_SEL:
        {
            msg_p->request.vasw_sel.value = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_USB_REG_ENABLE:
        {
            msg_p->request.usb_reg_enable.enable = (!EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType));
            break;
        }
        case PMIC_VBAT_ENABLE:
        {
            if (EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType))
            {
                msg_p->request.isense_enable.adc_value = PMIC_ADC_OFF;
            }
            else
            {
                msg_p->request.isense_enable.adc_value = PMIC_ADC_VBAT;
            }
            break;
        }
        case PMIC_ISENSE_ENABLE:
        {
            if (EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType))
            {
                msg_p->request.isense_enable.adc_value = PMIC_ADC_OFF;
            }
            else
            {
                msg_p->request.isense_enable.adc_value = PMIC_ADC_ISENSE;
            }
            break;
        }
        case PMIC_BL_PWM:
        {
            break;
        }
        default:
            ASSERT(0);
            break;
    }

    EngineerModeSendMsg(MSG_ID_MMI_EQ_PMIC_CONFIG_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EMPMICRegisterRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EMPMICRegisterRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    mmi_eq_pmic_config_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rsp_p->request_type)
    {
        case PMIC_READ_REG:
        {
            val_register_pmic = rsp_p->request.read_reg.result;
            EntryEMPMICRegisterDetail();
            break;
        }
        case PMIC_WRITE_REG:
        {
            EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
            break;
        }
        case PMIC_GET_CHR_STATE:
        {
            EntryEMPMICChargerStatus(rsp_p->request.chr_state.charger_status);
            break;
        }
        case PMIC_GET_AC_USB:
        {
            for (i = 0; i < 8; i++)
                if (rsp_p->request.ac_usb_status.current == PmicChrCurrent[i])
                {
                    break;
                }

            if (rsp_p->request.ac_usb_status.chr_enable)
            {
                EM_STATE_SET(gEmPmicCMDStatus, rsp_p->request.ac_usb_status.type + EM_PMIC_6318_CMD_SET_CHR);
            }
            else
            {
                EM_STATE_UNSET(gEmPmicCMDStatus, rsp_p->request.ac_usb_status.type + EM_PMIC_6318_CMD_SET_CHR);
            }

            g_pmic_6318_cntx.ACChrCurValue = i;
            EntryEmPMICSetCharger();
            break;
        }
        case PMIC_CHR_ENABLE:
        {
            break;
        }
        case PMIC_CHR_CURRENT_CTRL:
        {
            break;
        }
        case PMIC_USB_CHR_ENABLE:
        {
            break;
        }
        case PMIC_GET_LED_CONFIG:
        {
            for (i = 0; i < 4; i++)
                if (rsp_p->request.led_config.current == PmicRGBCurrent[i])
                {
                    break;
                }
            if (rsp_p->request.led_config.type == R_LED)
            {
                g_pmic_6318_cntx.RCurrentValue = i;
                EntryEmPMICRGBLED();
            }
            else if (rsp_p->request.led_config.type == G_LED)
            {
                g_pmic_6318_cntx.GCurrentValue = i;
                EntryEmPMICRGBLED();
            }
            else if (rsp_p->request.led_config.type == B_LED)
            {
                g_pmic_6318_cntx.BCurrentValue = i;
                EntryEmPMICRGBLED();
            }
            else if (rsp_p->request.led_config.type == KP_LED)
            {
                g_pmic_6318_cntx.KPDutyValue = (U8) rsp_p->request.led_config.duty;
                EntryEmPMICKPLED();
            }
            else if (rsp_p->request.led_config.type == BL_LED)
            {
                g_pmic_6318_cntx.BLDutyValue = (U8) rsp_p->request.led_config.duty;
                EntryEmPMICBLLED();
            }
            break;
        }
        case PMIC_GET_RGB_DIM:
        {
            g_pmic_6318_cntx.KPDimValue = rsp_p->request.rgb_dim.clk;
            g_pmic_6318_cntx.KPPumpCurrent = rsp_p->request.rgb_dim.pump_current;
            if (rsp_p->request.rgb_dim.pump_enable)
            {
                EM_STATE_SET(gEmPmicCMDStatus, EM_PMIC_6318_CMD_KP_CHR_PUMP);
            }
            else
            {
                EM_STATE_UNSET(gEmPmicCMDStatus, EM_PMIC_6318_CMD_KP_CHR_PUMP);
            }

            EntryEmPMICKPLED();
            break;
        }
        case PMIC_LED_ENABLE:
        {
            break;
        }
        case PMIC_LED_CONFIG:
        {
            break;
        }
        case PMIC_RGB_DIM_CLK:
        {
            break;
        }
        case PMIC_CHR_PUMP_ENABLE:
        {
            break;
        }
        case PMIC_CHR_PUMP_CURRENT:
        {
            break;
        }
        case PMIC_GET_BL_DIM:
        {
            g_pmic_6318_cntx.BLDimValue = rsp_p->request.bl_dim.clk;

            if (rsp_p->request.bl_dim.div_enable)
            {
                EM_STATE_SET(gEmPmicCMDStatus, EM_PMIC_6318_CMD_BL_DIM_BYPASS);
            }
            else
            {
                EM_STATE_UNSET(gEmPmicCMDStatus, EM_PMIC_6318_CMD_BL_DIM_BYPASS);
            }

            EntryEmPMICBLLED();
            break;
        }
        case PMIC_BL_DIV_BYPASS:
        {
            break;
        }
        case PMIC_BL_DIM_CLK:
        {
            break;
        }
        case PMIC_GET_SPEAKER_STATE:
        {
            if (rsp_p->request.speaker_state.state)
            {
                EM_STATE_SET(gEmPmicCMDStatus, EM_PMIC_6318_CMD_AUD_SPEAKER);
            }
            else
            {
                EM_STATE_UNSET(gEmPmicCMDStatus, EM_PMIC_6318_CMD_AUD_SPEAKER);
            }
            EntryEmPMICAudio();
            break;
        }
        case PMIC_GET_SPEAKER_GAIN:
        {
            g_pmic_6318_cntx.AudSpkGain = (rsp_p->request.speaker_gin.gain / 3);        /* 0-21dB, adjustmenet step=3dB */
            EntryEmPMICAudio();
            break;
        }
        case PMIC_SPEAKER_ENABLE:
        {
            break;
        }
        case PMIC_SPEAKER_GAIN:
        {
            break;
        }
        case PMIC_GET_MISC_LDO_STATE:
        {
            if (rsp_p->request.misc_ldo_state.enable)
            {
                EM_STATE_SET(gEmPmicCMDStatus, rsp_p->request.misc_ldo_state.type + EM_PMIC_6318_CMD_MISC_ISENSE_OUT);
            }
            else
            {
                EM_STATE_UNSET(gEmPmicCMDStatus, rsp_p->request.misc_ldo_state.type + EM_PMIC_6318_CMD_MISC_ISENSE_OUT);
            }

            EntryEmPMICMisc();

            break;
        }
        case PMIC_VIBRATOR_ENABLE:
        {
            break;
        }
        case PMIC_VIBRATOR_SEL:
        {
            break;
        }
        case PMIC_VMC_ENABLE:
        {
            break;
        }
        case PMIC_VMC_SEL:
        {
            break;
        }
        case PMIC_VASW_ENABLE:
        {
            break;
        }
        case PMIC_VASW_SEL:
        {
            break;
        }
        case PMIC_USB_REG_ENABLE:
        {
            break;
        }
        case PMIC_VBAT_ENABLE:
        {
            break;
        }
        case PMIC_ISENSE_ENABLE:
        {
            break;
        }
        case PMIC_BL_PWM:
        {
            break;
        }
        default:
            ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  LSKEmPMICRegisterSetCertain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LSKEmPMICRegisterSetCertain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 U8StrBuf[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) U8StrBuf, (S8*) InputBuf);
    register_pmic = (U16) atoi((S8*) U8StrBuf);

    register_pmic = (register_pmic << 12);
    /* Send message to L4 for the current register_pmic */
    EMPMICRegisterSendReq(PMIC_READ_REG, register_pmic, 0);
}


/*****************************************************************************
 * FUNCTION
 *  EMPMICRegisterHighlightHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMPMICRegisterHighlightHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  EMPMICRegisterDoneFunc
 * DESCRIPTION
 *  Set PMIC Register parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMPMICRegisterDoneFunc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 textbuf[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* convert the textedit buffer to currPWMFreq and currPWMDuty */
    mmi_ucs2_to_asc((PS8) textbuf, (PS8) freqBuf);
    val_register_pmic = (kal_uint8) atoi((const char*)textbuf);

    /* Set L4 for the current val_register_pmic */

    EMPMICRegisterSendReq(PMIC_WRITE_REG, (kal_uint16) register_pmic, (kal_uint8) val_register_pmic);

    DeleteScreenIfPresent(EM_DEV_PMIC_6318_REGISTER_VIEWER_SCR);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEMPMICRegisterDetail
 * DESCRIPTION
 *  Show PMIC Register detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEMPMICRegisterDetail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 ImageList[2];
    U8 textbuf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_REGISTER_VIEWER_SCR, ExitEMPMICRegisterDetail, NULL, NULL);
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_REGISTER_VIEWER_SCR);

    inputBuffer = GetCurrNInputBuffer(EM_DEV_PMIC_6318_REGISTER_VIEWER_SCR, &inputBufferSize);

    RegisterHighlightHandler(EMPMICRegisterHighlightHandler);

    /* Register */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "Register 0x%x", (U16) register_pmic);
    mmi_asc_to_ucs2((S8*) unicodebuf, (S8*) textbuf);
    SetInlineItemDisplayOnly(&wgui_inline_items[0], unicodebuf);
    ImageList[0] = IMG_STATUS;

    /* Value */
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "%d", val_register_pmic);
    mmi_asc_to_ucs2((S8*) freqBuf, (S8*) textbuf);
    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8) freqBuf, 20, INPUT_TYPE_NUMERIC);
    ImageList[1] = 0;

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);
    }

    ShowCategory57Screen(
        EM_DEV_PMIC_6318_REGISTER_EDITOR_TEXT,
        EM_DEV_GPIO_SET_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        ImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EMPMICRegisterDoneFunc, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitEMPMICRegisterDetail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEMPMICRegisterDetail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    currHistory.scrnID = EM_DEV_PMIC_6318_REGISTER_VIEWER_SCR;
    currHistory.entryFuncPtr = EntryEMPMICRegisterDetail;

    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  EmPMICSendRequest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICSendRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_pmic_6318_cntx.CmdType)
    {
        case EM_PMIC_6318_CMD_CHR_STATUS:
            g_pmic_6318_cntx.index = 0;
            EMPMICRegisterSendReq(PMIC_GET_CHR_STATE, 0, g_pmic_6318_cntx.index);
            break;

        case EM_PMIC_6318_CMD_SET_CHR:
            g_pmic_6318_cntx.index = EM_PMIC_6318_CMD_SET_CHR;
            EMPMICRegisterSendReq(PMIC_GET_AC_USB, 0, AC_CHR);
            break;

        case EM_PMIC_6318_CMD_R_LED:
            g_pmic_6318_cntx.index = EM_PMIC_6318_CMD_R_LED;
            EMPMICRegisterSendReq(PMIC_GET_LED_CONFIG, 0, g_pmic_6318_cntx.index);
            break;

        case EM_PMIC_6318_CMD_KP_LED:
            g_pmic_6318_cntx.index = EM_PMIC_6318_CMD_KP_LED;
            EMPMICRegisterSendReq(PMIC_GET_LED_CONFIG, 0, g_pmic_6318_cntx.index);
            break;

        case EM_PMIC_6318_CMD_BL_LED:
            g_pmic_6318_cntx.index = EM_PMIC_6318_CMD_BL_LED;
            EMPMICRegisterSendReq(PMIC_GET_LED_CONFIG, 0, g_pmic_6318_cntx.index);
            break;

        case EM_PMIC_6318_CMD_AUD_SPEAKER:
            g_pmic_6318_cntx.index = EM_PMIC_6318_CMD_AUD_SPEAKER;
            EMPMICRegisterSendReq(PMIC_GET_SPEAKER_STATE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_ISENSE_OUT:
            g_pmic_6318_cntx.index = 0;
            EMPMICRegisterSendReq(PMIC_GET_MISC_LDO_STATE, 0, g_pmic_6318_cntx.index);
            break;

        default:
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  ExecutePMICToggle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExecutePMICToggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = currentHighlightIndex;  /* to get the currenthighlightidnex , it's only for PMIC MISC. */

    switch (g_pmic_6318_cntx.CmdType)
    {
        case EM_PMIC_6318_CMD_SET_CHR:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, EM_DEV_PMIC_6318_SET_CHARGER_CHREN_MENU_ID);
            EMPMICRegisterSendReq(PMIC_CHR_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_SET_USB_CHR:
            index = GetIndexOfStringId(
                        EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID,
                        EM_DEV_PMIC_6318_SET_CHARGER_USB_CHREN_MENU_ID);
            EMPMICRegisterSendReq(PMIC_USB_CHR_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_R_LED:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_RGB_MENU_ID, EM_DEV_PMIC_6318_RGB_R_MENU_ID);
            EMPMICRegisterSendReq(PMIC_LED_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_G_LED:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_RGB_MENU_ID, EM_DEV_PMIC_6318_RGB_G_MENU_ID);
            EMPMICRegisterSendReq(PMIC_LED_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_B_LED:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_RGB_MENU_ID, EM_DEV_PMIC_6318_RGB_B_MENU_ID);
            EMPMICRegisterSendReq(PMIC_LED_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_KP_LED:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_KP_LED_MENU_ID, EM_DEV_PMIC_6318_KP_ENABLE_MENU_ID);
            EMPMICRegisterSendReq(PMIC_LED_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_KP_CHR_PUMP:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_KP_LED_MENU_ID, EM_DEV_PMIC_6318_KP_CHR_PUMP_EN_MENU_ID);
            EMPMICRegisterSendReq(PMIC_CHR_PUMP_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_BL_LED:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_BL_LED_MENU_ID, EM_DEV_PMIC_6318_BL_ENABLE_MENU_ID);
            EMPMICRegisterSendReq(PMIC_LED_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_BL_DIM_BYPASS:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_BL_LED_MENU_ID, EM_DEV_PMIC_6318_BL_DIM_BYPASS_MENU_ID);
            EMPMICRegisterSendReq(PMIC_BL_DIV_BYPASS, 0, 0);
            break;

        case EM_PMIC_6318_CMD_AUD_SPEAKER:
            index = GetIndexOfStringId(EM_DEV_PMIC_6318_AUDIO_MENU_ID, EM_DEV_PMIC_6318_AUDIO_SPEAKER_ENABLE_MENU_ID);
            EMPMICRegisterSendReq(PMIC_SPEAKER_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_VIBRATOR:
            EMPMICRegisterSendReq(PMIC_VIBRATOR_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_VIBRATOR_VOUT:
            EMPMICRegisterSendReq(PMIC_VIBRATOR_SEL, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_VMC:
            EMPMICRegisterSendReq(PMIC_VMC_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_VMC_SEL:
            EMPMICRegisterSendReq(PMIC_VMC_SEL, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_VASW:
            EMPMICRegisterSendReq(PMIC_VASW_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_VASW_SEL:
            EMPMICRegisterSendReq(PMIC_VASW_SEL, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_USB_PWR:
            EMPMICRegisterSendReq(PMIC_USB_REG_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_VBAT_VOUT:
            EMPMICRegisterSendReq(PMIC_VBAT_ENABLE, 0, 0);
            break;

        case EM_PMIC_6318_CMD_MISC_ISENSE_OUT:
            EMPMICRegisterSendReq(PMIC_ISENSE_ENABLE, 0, 0);
            break;

        default:
            break;
    }

    EM_STATE_TOGGLE(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType);

    if (EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType))
    {
        Category52ChangeItemDescription(index, (U8*) get_string(STR_GLOBAL_ON));
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        Category52ChangeItemDescription(index, (U8*) get_string(STR_GLOBAL_OFF));
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  EmPMICHiliteDescriptionOnOFF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICHiliteDescriptionOnOFF(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EM_IS_SET(gEmPmicCMDStatus, g_pmic_6318_cntx.CmdType))
    {
        Category52ChangeItemDescription(index, (U8*) get_string(STR_GLOBAL_ON));
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        Category52ChangeItemDescription(index, (U8*) get_string(STR_GLOBAL_OFF));
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICChargerStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICChargerStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_CHR_STATUS;

    SetLeftSoftkeyFunction(EmPMICSendRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEMPMICChargerStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  char_status     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEMPMICChargerStatus(kal_uint8 char_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 status[EM_PMIC_6318_CHR_MAX][5];
    U8 tmpbuf[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.index < EM_PMIC_6318_CHR_MAX)
    {
        sprintf((S8*) status[g_pmic_6318_cntx.index], "%3s", PmicStatusString[char_status & 0x1]);
        g_pmic_6318_cntx.index++;
        EMPMICRegisterSendReq(PMIC_GET_CHR_STATE, 0, g_pmic_6318_cntx.index);
    }
    else
    {
        sprintf(
            (S8*) tmpbuf,
            "OV_SPI: %3s\nCHRDET: %3s\nAC_DET: %3s\nUSB_DET: %3s\nBAT_ON: %3s\nCV: %3s\nCHRG_DIS: %3s\n",
            status[EM_PMIC_6318_CHR_OV_SPI],
            status[EM_PMIC_6318_CHR_CHRDET],
            status[EM_PMIC_6318_CHR_AC_DET],
            status[EM_PMIC_6318_CHR_USB_DET],
            status[EM_PMIC_6318_CHR_BAT_ON],
            status[EM_PMIC_6318_CHR_CV],
            status[EM_PMIC_6318_CHR_CHRG_DIS]);
        mmi_asc_to_ucs2((S8*) EMUnicodeDisplayBuf, (S8*) tmpbuf);

        EntryNewScreen(EM_DEV_PMIC_6318_CHARGER_STATUS_TEXT, NULL, NULL, NULL);

        ShowCategory7Screen(
            EM_DEV_PMIC_6318_CHARGER_STATUS_TEXT,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            (PU8) EMUnicodeDisplayBuf,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICSetCharger
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICSetCharger(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_SET_CHR;

    SetLeftSoftkeyFunction(EmPMICSendRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICSetCharger
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICSetCharger(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.index < EM_PMIC_6318_CMD_SET_USB_CHR)
    {
        g_pmic_6318_cntx.index++;
        EMPMICRegisterSendReq(PMIC_GET_AC_USB, 0, USB_CHR);
    }
    else
    {
        EntryNewScreen(EM_DEV_PMIC_6318_SET_CHARGER_SCR, NULL, EntryEmPMICSetCharger, NULL);
        guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_SET_CHARGER_SCR);
        nItems = GetNumOfChild(EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID);
        GetSequenceStringIds(EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, ItemList);
        SetParentHandler(EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID);

        for (i = 0; i < nItems; i++)
        {
            hintDataPtrs[i] = NULL;
        }

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        ShowCategory52Screen(
            EM_DEV_PMIC_6318_SET_CHARGER_TEXT,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U16*) gIndexIconsImageList,
            (U8 **) hintDataPtrs,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICSetChargerChrEn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICSetChargerChrEn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_SET_CHR;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, EM_DEV_PMIC_6318_SET_CHARGER_CHREN_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICSetChargerACCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICSetChargerACCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_SET_CHR_CURRENT;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICChrCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICChrCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICChrCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[] = 
    {
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_50_TEXT,
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_90_TEXT,
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_150_TEXT,
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_225_TEXT,
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_300_TEXT,
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_450_TEXT,
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_650_TEXT,
        EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_800_TEXT
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_SCR, NULL, EntryEmPMICChrCurrent, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_SCR);
    RegisterHighlightHandler(SetHighlightIndex);

    ShowCategory11Screen(
        EM_DEV_PMIC_6318_CHARGER_CURRENT_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        8,
        ItemList,
        (U16) g_pmic_6318_cntx.ACChrCurValue,
        guiBuffer);

    SetLeftSoftkeyFunction(EmPMICSetChrCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EmPMICSetChrCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICSetChrCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.ACChrCurValue = currentHighlightIndex;

    EMPMICRegisterSendReq(PMIC_CHR_CURRENT_CTRL, 0, 0);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_SET_CHARGER_SCR);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICSetChargerUSBChren
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICSetChargerUSBChren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_SET_USB_CHR;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, EM_DEV_PMIC_6318_SET_CHARGER_USB_CHREN_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICSetChargerUSBCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICSetChargerUSBCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_SET_USB_CHR_CURRENT;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICChrCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICRGB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICRGB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_R_LED;

    SetLeftSoftkeyFunction(EmPMICSendRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICRGBLED
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICRGBLED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.index < EM_PMIC_6318_CMD_B_LED)
    {
        g_pmic_6318_cntx.index++;
        EMPMICRegisterSendReq(PMIC_GET_LED_CONFIG, 0, g_pmic_6318_cntx.index);
    }
    else
    {
        EntryNewScreen(EM_DEV_PMIC_6318_RGB_LED_SCR, NULL, EntryEmPMICRGBLED, NULL);
        guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_RGB_LED_SCR);
        nItems = GetNumOfChild(EM_DEV_PMIC_6318_RGB_MENU_ID);
        GetSequenceStringIds(EM_DEV_PMIC_6318_RGB_MENU_ID, ItemList);
        SetParentHandler(EM_DEV_PMIC_6318_RGB_MENU_ID);

        for (i = 0; i < nItems; i++)
        {
            hintDataPtrs[i] = NULL;
        }

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        ShowCategory52Screen(
            EM_DEV_PMIC_6318_RGB_TEXT,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U16*) gIndexIconsImageList,
            0,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICRLEDEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICRLEDEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_R_LED;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_RGB_MENU_ID, EM_DEV_PMIC_6318_RGB_R_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICRCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICRCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_R_LED_CURRENT;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICRGBCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICRGBCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICRGBCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 highlite_value = 0;
    U8 *guiBuffer;
    U16 ItemList[] = 
    {
        EM_DEV_PMIC_RGB_LED_CURRENT_12_TEXT,
        EM_DEV_PMIC_RGB_LED_CURRENT_16_TEXT,
        EM_DEV_PMIC_RGB_LED_CURRENT_20_TEXT,
        EM_DEV_PMIC_RGB_LED_CURRENT_24_TEXT
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_RGB_CURRENT_SCR, NULL, EntryEmPMICRGBCurrent, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_RGB_CURRENT_SCR);
    RegisterHighlightHandler(SetHighlightIndex);

    if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_R_LED_CURRENT)
    {
        highlite_value = g_pmic_6318_cntx.RCurrentValue;
    }
    else if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_G_LED_CURRENT)
    {
        highlite_value = g_pmic_6318_cntx.GCurrentValue;
    }
    else if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_B_LED_CURRENT)
    {
        highlite_value = g_pmic_6318_cntx.BCurrentValue;
    }

    ShowCategory11Screen(
        EM_DEV_PMIC_RGB_LED_CURRENT_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        4,
        ItemList,
        highlite_value,
        guiBuffer);

    SetLeftSoftkeyFunction(EmPMICRGBSetCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EmPMICRGBSetCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICRGBSetCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_R_LED_CURRENT)
    {
        g_pmic_6318_cntx.RCurrentValue = currentHighlightIndex;
    }
    else if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_G_LED_CURRENT)
    {
        g_pmic_6318_cntx.GCurrentValue = currentHighlightIndex;
    }
    else if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_B_LED_CURRENT)
    {
        g_pmic_6318_cntx.BCurrentValue = currentHighlightIndex;
    }

    EMPMICRegisterSendReq(PMIC_LED_CONFIG, 0, currentHighlightIndex);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_RGB_LED_SCR);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICGLEDEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICGLEDEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_G_LED;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_RGB_MENU_ID, EM_DEV_PMIC_6318_RGB_G_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICGCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICGCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_G_LED_CURRENT;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICRGBCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICBLEDEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICBLEDEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_B_LED;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_RGB_MENU_ID, EM_DEV_PMIC_6318_RGB_B_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICBCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICBCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_B_LED_CURRENT;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICRGBCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICKPLED
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICKPLED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_KP_LED;

    SetLeftSoftkeyFunction(EmPMICSendRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICKPLED
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICKPLED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.index < EM_PMIC_6318_CMD_KP_LED + 1)
    {
        g_pmic_6318_cntx.index++;
        EMPMICRegisterSendReq(PMIC_GET_RGB_DIM, 0, 0);
    }
    else
    {
        EntryNewScreen(EM_DEV_PMIC_6318_KP_LED_SCR, NULL, EntryEmPMICKPLED, NULL);
        guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_KP_LED_SCR);
        nItems = GetNumOfChild(EM_DEV_PMIC_6318_KP_LED_MENU_ID);
        GetSequenceStringIds(EM_DEV_PMIC_6318_KP_LED_MENU_ID, ItemList);
        SetParentHandler(EM_DEV_PMIC_6318_KP_LED_MENU_ID);

        for (i = 0; i < nItems; i++)
        {
            hintDataPtrs[i] = NULL;
        }

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        ShowCategory52Screen(
            EM_DEV_PMIC_6318_KP_LED_TEXT,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U16*) gIndexIconsImageList,
            0,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICKPEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICKPEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_KP_LED;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_KP_LED_MENU_ID, EM_DEV_PMIC_6318_KP_ENABLE_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICKPDutyOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICKPDutyOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_KP_LED_DUTY;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICKPDutyOption, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICKPDutyOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICKPDutyOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_KP_DUTY_OPT_SCR, NULL, EntryEmPMICKPDutyOption, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_KP_DUTY_OPT_SCR);

    kal_wsprintf(InputBuf, "%d", g_pmic_6318_cntx.KPDutyValue);

    ShowCategory5Screen(
        EM_DEV_PMIC_6318_KP_DUTY_OPTION_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SetPMICKPDuty, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  SetPMICKPDuty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPMICKPDuty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMPMICRegisterSendReq(PMIC_LED_CONFIG, 0, 0);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_KP_LED_SCR);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICKPDimClk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICKPDimClk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_KP_DIM_CLOCK;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICKPDimClk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICKPDimClk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICKPDimClk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_KP_DIM_CLK_SCR, NULL, EntryEmPMICKPDimClk, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_KP_DIM_CLK_SCR);

    kal_wsprintf(InputBuf, "%d", g_pmic_6318_cntx.KPDimValue);

    ShowCategory5Screen(
        EM_DEV_PMIC_6318_KP_DIM_CLOCK_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SetPMICKPDIM, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  SetPMICKPDIM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPMICKPDIM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMPMICRegisterSendReq(PMIC_RGB_DIM_CLK, 0, 0);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_KP_LED_SCR);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICKPChrPumpEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICKPChrPumpEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_KP_CHR_PUMP;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_KP_LED_MENU_ID, EM_DEV_PMIC_6318_KP_CHR_PUMP_EN_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICKPChrPumpCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICKPChrPumpCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_KP_PUMP_CURRENT;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICKPChrPumpCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICKPChrPumpCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICKPChrPumpCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[] = 
    {
        EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL1_TEXT,
        EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL2_TEXT,
        EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL3_TEXT,
        EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL4_TEXT
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_KP_PUMP_CURRENT_SCR, NULL, EntryEmPMICKPChrPumpCurrent, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_KP_PUMP_CURRENT_SCR);
    RegisterHighlightHandler(SetHighlightIndex);

    ShowCategory11Screen(
        EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        4,
        ItemList,
        (U16) g_pmic_6318_cntx.KPPumpCurrent,
        guiBuffer);

    SetLeftSoftkeyFunction(EmPMICKPChrPumpSetCurrent, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  EmPMICKPChrPumpSetCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICKPChrPumpSetCurrent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.KPPumpCurrent = currentHighlightIndex;

    EMPMICRegisterSendReq(PMIC_CHR_PUMP_CURRENT, 0, currentHighlightIndex);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_KP_LED_SCR);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICBLLED
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICBLLED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_BL_LED;

    SetLeftSoftkeyFunction(EmPMICSendRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICBLLED
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICBLLED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 nItems = 4;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.index < EM_PMIC_6318_CMD_BL_LED + 1)
    {
        g_pmic_6318_cntx.index++;
        EMPMICRegisterSendReq(PMIC_GET_BL_DIM, 0, 0);
    }
    else
    {
        EntryNewScreen(EM_DEV_PMIC_6318_BL_LED_SCR, NULL, EntryEmPMICBLLED, NULL);
        guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_BL_LED_SCR);
        nItems = GetNumOfChild(EM_DEV_PMIC_6318_BL_LED_MENU_ID);
        GetSequenceStringIds(EM_DEV_PMIC_6318_BL_LED_MENU_ID, ItemList);
        SetParentHandler(EM_DEV_PMIC_6318_BL_LED_MENU_ID);

        for (i = 0; i < nItems; i++)
        {
            hintDataPtrs[i] = NULL;
        }

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        ShowCategory52Screen(
            EM_DEV_PMIC_6318_BL_LED_TEXT,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U16*) gIndexIconsImageList,
            0,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICBLEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICBLEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_BL_LED;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_BL_LED_MENU_ID, EM_DEV_PMIC_6318_BL_ENABLE_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICBLDutyOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICBLDutyOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_BL_LED_DUTY;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICBLDutyOption, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICBLDutyOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICBLDutyOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_BL_DUTY_OPT_SCR, NULL, EntryEmPMICBLDutyOption, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_BL_DUTY_OPT_SCR);

    kal_wsprintf(InputBuf, "%d", g_pmic_6318_cntx.BLDutyValue);

    ShowCategory5Screen(
        EM_DEV_PMIC_6318_BL_DUTY_OPTION_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SetPMICBLDuty, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  SetPMICBLDuty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPMICBLDuty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMPMICRegisterSendReq(PMIC_LED_CONFIG, 0, 0);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_BL_LED_SCR);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICBLDimClock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICBLDimClock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_BL_DIM_CLOCK;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICBLDimClk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICBLDimClk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICBLDimClk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_BL_DIM_CLK_SCR, NULL, EntryEmPMICBLDimClk, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_BL_DIM_CLK_SCR);

    kal_wsprintf(InputBuf, "%d", g_pmic_6318_cntx.BLDimValue);

    ShowCategory5Screen(
        EM_DEV_PMIC_6318_BL_DIM_CLOCK_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SetPMICBLDIM, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SetPMICBLDIM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPMICBLDIM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMPMICRegisterSendReq(PMIC_BL_DIM_CLK, 0, 0);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_BL_LED_SCR);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICBLDimBypassEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICBLDimBypassEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_BL_DIM_BYPASS;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_BL_LED_MENU_ID, EM_DEV_PMIC_6318_BL_DIM_BYPASS_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICAudio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICAudio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_AUD_SPEAKER;

    SetLeftSoftkeyFunction(EmPMICSendRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICAudio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICAudio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[8];
    U16 nItems;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.index < EM_PMIC_6318_CMD_AUD_SPEAKER_GAIN)
    {
        g_pmic_6318_cntx.index++;
        EMPMICRegisterSendReq(PMIC_GET_SPEAKER_GAIN, 0, 0);
    }
    else
    {
        EntryNewScreen(EM_DEV_PMIC_6318_AUDIO_SCR, NULL, EntryEmPMICAudio, NULL);
        guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_AUDIO_SCR);

        nItems = GetNumOfChild(EM_DEV_PMIC_6318_AUDIO_MENU_ID);
        GetSequenceStringIds(EM_DEV_PMIC_6318_AUDIO_MENU_ID, ItemList);
        SetParentHandler(EM_DEV_PMIC_6318_AUDIO_MENU_ID);

        for (i = 0; i < nItems; i++)
        {
            hintDataPtrs[i] = NULL;
        }

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        ShowCategory52Screen(
            EM_DEV_PMIC_6318_AUDIO_TEXT,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U16*) gIndexIconsImageList,
            0,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICAudioSpkEnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICAudioSpkEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_AUD_SPEAKER;

    index = GetIndexOfStringId(EM_DEV_PMIC_6318_AUDIO_MENU_ID, EM_DEV_PMIC_6318_AUDIO_SPEAKER_ENABLE_MENU_ID);
    EmPMICHiliteDescriptionOnOFF(index);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICAudioSpkGain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICAudioSpkGain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_AUD_SPEAKER_GAIN;

    change_left_softkey(STR_GLOBAL_OK, 0);
    redraw_left_softkey();

    SetLeftSoftkeyFunction(EntryEmPMICSpeakerGain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICSpeakerGain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICSpeakerGain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[] = 
    {
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN0_TEXT,
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN1_TEXT,
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN2_TEXT,
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN3_TEXT,
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN4_TEXT,
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN5_TEXT,
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN6_TEXT,
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN7_TEXT
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_AUDIO_SPK_GAIN_SCR, NULL, EntryEmPMICSpeakerGain, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_AUDIO_SPK_GAIN_SCR);
    RegisterHighlightHandler(SetHighlightIndex);

    ShowCategory11Screen(
        EM_DEV_PMIC_6318_AUDIO_AMPGAIN0_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        8,
        ItemList,
        (U16) g_pmic_6318_cntx.AudSpkGain,
        guiBuffer);

    SetLeftSoftkeyFunction(EmPMICAudSetSpkGain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  EmPMICAudSetSpkGain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICAudSetSpkGain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.CmdType == EM_PMIC_6318_CMD_AUD_SPEAKER_GAIN)
    {
        g_pmic_6318_cntx.AudSpkGain = currentHighlightIndex;
    }

    EMPMICRegisterSendReq(PMIC_SPEAKER_GAIN, 0, currentHighlightIndex);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteUptoScrID(EM_DEV_PMIC_6318_AUDIO_SCR);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICMisc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICMisc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_MISC_ISENSE_OUT;

    SetLeftSoftkeyFunction(EmPMICSendRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPMICMisc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPMICMisc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[] = 
    {
        EM_DEV_PMIC_6318_MISC_ISENSE_OUT_ENABLE_TEXT,
        EM_DEV_PMIC_6318_MISC_VBAT_OUT_ENABLE_TEXT,
        EM_DEV_PMIC_6318_MISC_USB_PWR_ENABLE_TEXT,
        EM_DEV_PMIC_6318_MISC_VA_SW_SEL_TEXT,
        EM_DEV_PMIC_6318_MISC_VA_SW_ENABLE_TEXT,
        EM_DEV_PMIC_6318_MISC_VMC_SEL_TEXT,
        EM_DEV_PMIC_6318_MISC_VMC_ENABLE_TEXT,
        EM_DEV_PMIC_6318_MISC_VIBRATOR_ENABLE_TEXT,
        EM_DEV_PMIC_6318_MISC_VIBRATOR_OUT_TEXT
    };
    U16 nItems = 9;
    U8 *guiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmic_6318_cntx.index < (EM_PMIC_6318_CMD_MISC_VIBRATOR_VOUT - EM_PMIC_6318_CMD_MISC_ISENSE_OUT))
    {
        g_pmic_6318_cntx.index++;
        EMPMICRegisterSendReq(PMIC_GET_MISC_LDO_STATE, 0, g_pmic_6318_cntx.index);
    }
    else
    {
        EntryNewScreen(EM_DEV_PMIC_6318_MISC_SCR, NULL, EntryEmPMICMisc, NULL);
        guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_MISC_SCR);

        for (i = 0; i < nItems; i++)
        {
            hintDataPtrs[i] = NULL;
        }

        RegisterHighlightHandler(EmPMICMiscSetHighlightIndex);

        ShowCategory52Screen(
            EM_DEV_PMIC_6318_MISC_TEXT,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            nItems,
            ItemList,
            (U16*) gIndexIconsImageList,
            0,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EmPMICMiscSetHighlightIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICMiscSetHighlightIndex(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentHighlightIndex = (U8) nIndex;
    g_pmic_6318_cntx.CmdType = currentHighlightIndex + EM_PMIC_6318_CMD_MISC_ISENSE_OUT;

    EmPMICHiliteDescriptionOnOFF(currentHighlightIndex);

    SetLeftSoftkeyFunction(ExecutePMICToggle, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmPMICLCMBLSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmPMICLCMBLSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CmdType = EM_PMIC_6318_CMD_BL_PWM_SETTING;
    
    SetLeftSoftkeyFunction(EntryPMICBLSettingMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPMICBLSettingMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPMICBLSettingMenu(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ImageList[6];
    U8 textbuf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_PMIC_6318_LCM_BL_SETTING_SCR, ExitPMICBLSettingMenu, EntryPMICBLSettingMenu, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(EM_DEV_PMIC_6318_LCM_BL_SETTING_SCR);

    /* Get the current setting */
    currPWMLevel = pmic_pwm_current_level() - 1;     /* 0-based */
    if (g_pmic_6318_cntx.currBLLevel >= CUSTOM_EM_PWM_LEVEL_MAX || g_pmic_6318_cntx.currBLLevel < 0)
    {
        g_pmic_6318_cntx.currBLLevel = 0;
    }

    g_pmic_6318_cntx.CurrBLFreq = PMIC6318_PWM_Level_Info[g_pmic_6318_cntx.currBLLevel][0];
    g_pmic_6318_cntx.CurrBLDuty = PMIC6318_PWM_Level_Info[g_pmic_6318_cntx.currBLLevel][1];

    /* Level */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[0]), (U8*) GetString(EM_STR_PWM_LEVEL));
    ImageList[0] = IMG_STATUS;

    /* reuse PWM variable */
    kal_wstrcpy((WCHAR*) EMPWMLevel[0], (const WCHAR*)kal_toWCHAR("1"));
    pEMPWMLevel[0] = (U8*) (EMPWMLevel[0]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[1], (const WCHAR*)kal_toWCHAR("2"));
    pEMPWMLevel[1] = (U8*) (EMPWMLevel[1]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[2], (const WCHAR*)kal_toWCHAR("3"));
    pEMPWMLevel[2] = (U8*) (EMPWMLevel[2]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[3], (const WCHAR*)kal_toWCHAR("4"));
    pEMPWMLevel[3] = (U8*) (EMPWMLevel[3]);
    kal_wstrcpy((WCHAR*) EMPWMLevel[4], (const WCHAR*)kal_toWCHAR("5"));
    pEMPWMLevel[4] = (U8*) (EMPWMLevel[4]);
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[1], 5, (U8**)pEMPWMLevel, &g_pmic_6318_cntx.currBLLevel);
    ImageList[1] = 0;
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[1], EmPMICBLLevelHighlightHandler);

    /* Frequency */
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[2]), (U8*) GetString(EM_STR_PWM_FREQUENCY));
    ImageList[2] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "%d", (U16) g_pmic_6318_cntx.CurrBLFreq);
    mmi_asc_to_ucs2((S8*) freqBuf, (S8*) textbuf);
    SetInlineItemTextEdit(&wgui_inline_items[3], (PU8) freqBuf, 20, INPUT_TYPE_NUMERIC);
    ImageList[3] = 0;

    /* Duty */
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[4]), (U8*) GetString(EM_STR_PWM_DUTY));
    ImageList[4] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) textbuf, "%d", (U16) g_pmic_6318_cntx.CurrBLDuty);
    mmi_asc_to_ucs2((S8*) dutyBuf, (S8*) textbuf);
    SetInlineItemTextEdit(&wgui_inline_items[5], (PU8) dutyBuf, 20, INPUT_TYPE_NUMERIC);
    ImageList[5] = 0;

    ShowCategory57Screen(
        EM_DEV_PMIC_6318_MISC_LCM_BL_SETTING_TEXT,
        EM_DEV_GPIO_SET_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        ImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EmPMICSetBLPWM, GoBackHistory);
    
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitPMICBLSettingMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPMICBLSettingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  EmPMICBLLevelHighlightHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICBLLevelHighlightHandler(S32 index)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 textbuf[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmic_6318_cntx.CurrBLFreq = PMIC6318_PWM_Level_Info[index][0];
    g_pmic_6318_cntx.CurrBLDuty = PMIC6318_PWM_Level_Info[index][1];

    /* Frequency */
    sprintf((S8*) textbuf, "%d", (U16) g_pmic_6318_cntx.CurrBLFreq);
    mmi_asc_to_ucs2((S8*) freqBuf, (S8*) textbuf);

    /* Duty */
    sprintf((S8*) textbuf, "%d", (U16) g_pmic_6318_cntx.CurrBLDuty);
    mmi_asc_to_ucs2((S8*) dutyBuf, (S8*) textbuf);
    
    redraw_fixed_list();
#endif /* #ifdef __MTK_TARGET__ */    
}


/*****************************************************************************
 * FUNCTION
 *  EmPMICSetBLPWM
 * DESCRIPTION
 *  Set PMIC 6318 BL PWM parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPMICSetBLPWM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 textbuf[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    if ((!mmi_ucs2strlen((const S8*)freqBuf) && !mmi_ucs2strlen((const S8*)dutyBuf))
        || (mmi_ucs2strlen((const S8*)freqBuf) > 5 || mmi_ucs2strlen((const S8*)dutyBuf) > 3))
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
        DeleteScreenIfPresent(EM_DEV_PMIC_6318_LCM_BL_SETTING_SCR);        
        return;
    }
    /* convert the textedit buffer to PWMFreq and PWMDuty */
    mmi_ucs2_to_asc((PS8) textbuf, (PS8) freqBuf);
    g_pmic_6318_cntx.CurrBLFreq = atoi((const char*)textbuf);

    mmi_ucs2_to_asc((PS8) textbuf, (PS8) dutyBuf);
    g_pmic_6318_cntx.CurrBLDuty = atoi((const char*)textbuf);

    /* Set up PWMFreq and PWMDuty */
    PMIC6318_PWM_Level_Info[g_pmic_6318_cntx.currBLLevel][0] = g_pmic_6318_cntx.CurrBLFreq;
    PMIC6318_PWM_Level_Info[g_pmic_6318_cntx.currBLLevel][1] = g_pmic_6318_cntx.CurrBLDuty;

    pmic_pwm_level(g_pmic_6318_cntx.currBLLevel);
    pmic_pwm_configure(g_pmic_6318_cntx.CurrBLFreq, g_pmic_6318_cntx.CurrBLDuty);
    pmic_pwm_start();

    EMPMICRegisterSendReq(PMIC_BL_PWM, 0, 0);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
    DeleteScreenIfPresent(EM_DEV_PMIC_6318_LCM_BL_SETTING_SCR);
}

#endif /* defined(MT6318) */ 

/****************************************
 **
 ** Menu Tree: Device --> EINT
 **
 ****************************************/
#define ___EM_DEVICE_EINT___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmEINT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmEINT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmEINTMenu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EmPrepareEINTList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPrepareEINTList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMenuListNum = 0;
    for (i = 0; i <= EINT_LABELID_MAX; i++)
    {
        if (eint_map_tbl[i].vaild == GPIO_VAILD)
        {

            sprintf(buffer, "%s %d", eint_map_tbl[i].netname, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
            subMenuDataPtrs[i] = subMenuData[i];
            gMenuListNum++;

        }
    }

    /* Initialize charger value */
    if (g_charbat_context.isChargerConnected == 1)
    {
        sprintf(buffer, "%s %d", eint_map_tbl[0].netname, 1);
        mmi_asc_to_ucs2((PS8) subMenuData[0], buffer);
        subMenuDataPtrs[0] = subMenuData[0];
    }
    /* Initialize earphone value */
    if (isEarphonePlugged == 1)
    {
        sprintf(buffer, "%s %d", eint_map_tbl[3].netname, 1);
        mmi_asc_to_ucs2((PS8) subMenuData[3], buffer);
        subMenuDataPtrs[3] = subMenuData[3];
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmEINTMenu
 * DESCRIPTION
 *  Entry function for EINT menun
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmEINTMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_EINT_MENU_ID, ExitEmEINTMenu, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_EINT_MENU_ID);

    /* RegisterHighlightHandler (HighlightOnCertainEmPWM); */

    EmPrepareEINTList();

    if (gMenuListNum < 1)
    {
        gMenuListNum++;
    }

    ShowCategory6Screen(
        EM_DEV_EINT_TEXT,
        (U16) 0,
        (U16) NULL,
        (U16) 0,
        STR_GLOBAL_BACK,
        (U16) 0,
        gMenuListNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(StopEmEINTMeun, KEY_EVENT_UP);

    //EINTProtocolEventHandlerFp[0] = EmGetProtocolEventHandler(MSG_ID_MMI_EQ_GPIO_DETECT_IND ) );
    // EINTProtocolEventHandlerFp[1] = EmGetProtocolEventHandler(MSG_ID_MMI_EQ_BATTERY_STATUS_IND ) );
    SetProtocolEventHandler(UpdateEmEINTGPIORecvHandler, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    SetProtocolEventHandler(UpdateEmEINTBatteryRecvHandler, PRT_BATTERY_STATUS_IND);
    /* StartTimer(203, 1000, TestUpdateEmEINT); */
}


/*****************************************************************************
 * FUNCTION
 *  UpdateEmEINTGPIORecvHandler
 * DESCRIPTION
 *  Helper function for EINT GPIO Recv
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateEmEINTGPIORecvHandler(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[32];
    mmi_eq_gpio_detect_ind_struct *gpio_detect_struct = (mmi_eq_gpio_detect_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gpio_detect_struct->gpio_device)
    {
        case EXT_DEV_NONE:
            sprintf(buffer, "%s %d", eint_map_tbl[1].netname, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[1], buffer);
            subMenuDataPtrs[1] = subMenuData[1];

            sprintf(buffer, "%s %d", eint_map_tbl[2].netname, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[2], buffer);
            subMenuDataPtrs[2] = subMenuData[2];

            sprintf(buffer, "%s %d", eint_map_tbl[3].netname, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[3], buffer);
            subMenuDataPtrs[3] = subMenuData[3];

            break;

        case EXT_DEV_UART:
            if (gpio_detect_struct->on_off == KAL_TRUE)
            {
                sprintf(buffer, "%s %d", eint_map_tbl[1].netname, 1);
            }
            else
            {
                sprintf(buffer, "%s %d", eint_map_tbl[1].netname, 0);
            }

            mmi_asc_to_ucs2((PS8) subMenuData[1], buffer);
            subMenuDataPtrs[1] = subMenuData[1];
            break;

        case EXT_DEV_KEY_1:
            sprintf(buffer, "%s %d", eint_map_tbl[2].netname, 1);
            mmi_asc_to_ucs2((PS8) subMenuData[2], buffer);
            subMenuDataPtrs[2] = subMenuData[2];
            break;

        case EXT_DEV_KEY_2:
            sprintf(buffer, "%s %d", eint_map_tbl[2].netname, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[2], buffer);
            subMenuDataPtrs[2] = subMenuData[2];
            break;

        case EXT_DEV_EARPHONE:
            if (gpio_detect_struct->on_off == KAL_TRUE)
            {
                sprintf(buffer, "%s %d", eint_map_tbl[3].netname, 1);
            }
            else
            {
                sprintf(buffer, "%s %d", eint_map_tbl[3].netname, 0);
            }

            mmi_asc_to_ucs2((PS8) subMenuData[3], buffer);
            subMenuDataPtrs[3] = subMenuData[3];
            break;

        case EXT_DEV_CLAM_OPEN:
            return; /* Not yet define */
            break;

        case EXT_DEV_CLAM_CLOSE:
            return; /* Not yet define */
            break;

        default:
            return;
    }

    UpdateEmEINT();
}


/*****************************************************************************
 * FUNCTION
 *  EMFMBatteryStatusMsgHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EMFMBatteryStatusMsgHandler(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_battery_status_ind_struct *BatState = (mmi_eq_battery_status_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* send ACK to UEM, Charger flow control mechanism. */
    mmi_devmgr_charger_send_ack(BatState->battery_status);
        
    switch (BatState->battery_status)
    {
        case PMIC_CHARGER_IN:
            g_charbat_context.isChargerConnected = 1;
            g_charbat_context.ChargingComplete = 0; /* MTK added, Robin 1009 to prevent reentrence of charging complete screen */
            IdleScreenChargerConnected(KAL_TRUE);
            break;

        case PMIC_CHARGER_OUT:
            g_charbat_context.ChargingComplete = 0; /* MTK added, Robin 1009 to prevent reentrence of charging complete screen */
            g_charbat_context.isChargerConnected = 0;
            IdleScreenChargerDisconnected();
            break;

        case PMIC_CHARGE_COMPLETE:
            IdleScreenBatteryFullCharged();
            break;

        case PMIC_VBAT_STATUS:
            BatteryStatusIndication(BatState->battery_voltage);
            break;

        case PMIC_OVERVOLPROTECT:
        case PMIC_OVERBATTEMP:
        case PMIC_LOWBATTEMP:
        case PMIC_OVERCHARGECURRENT:
        case PMIC_INVALID_BATTERY:
        case PMIC_INVALID_CHARGER:
        case PMIC_CHARGING_TIMEOUT:
        case PMIC_LOWCHARGECURRENT:
            break;

        default:
            BatteryStatusRsp(BatState);
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  UpdateEmEINTBatteryRecvHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateEmEINTBatteryRecvHandler(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 buffer[32];

    mmi_eq_battery_status_ind_struct *batstat_struct = (mmi_eq_battery_status_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (batstat_struct->battery_status)
    {

        case PMIC_CHARGER_IN:
        {
            sprintf(buffer, "%s %d", eint_map_tbl[0].netname, 1);
            mmi_asc_to_ucs2((PS8) subMenuData[0], buffer);
            subMenuDataPtrs[0] = subMenuData[0];
            break;
        }

        case PMIC_CHARGER_OUT:
        {
            sprintf(buffer, "%s %d", eint_map_tbl[0].netname, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[0], buffer);
            subMenuDataPtrs[0] = subMenuData[0];
            break;
        }

        default:
            EMFMBatteryStatusMsgHandler(inMsg);
            return;
    }

    EMFMBatteryStatusMsgHandler(inMsg);
    UpdateEmEINT();

}


/*****************************************************************************
 * FUNCTION
 *  UpdateEmEINT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateEmEINT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory6Screen(
        EM_DEV_EINT_TEXT,
        (U16) 0,
        (U16) NULL,
        (U16) 0,
        STR_GLOBAL_BACK,
        (U16) 0,
        gMenuListNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        NULL);

    SetRightSoftkeyFunction(StopEmEINTMeun, KEY_EVENT_UP);
    ReplaceNewScreenHandler(EM_DEV_EINT_MENU_ID, ExitEmEINTMenu, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  StopEmEINTMeun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopEmEINTMeun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetProtocolEventHandler( EINTProtocolEventHandlerFp[0], MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    //SetProtocolEventHandler( EINTProtocolEventHandlerFp[1], PRT_BATTERY_STATUS_IND);
    SetProtocolEventHandler(GpioDetectInd, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ExitEmEINTMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEmEINTMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(GpioDetectInd, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
}

#undef ___EM_DEVICE_PWM___

/****************************************
 **
 ** Menu Tree: Device --> ADC
 **
 ****************************************/
#define ___EM_DEVICE_ADC___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmADC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmADC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmADCMenu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EmPrepareADCList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPrepareADCList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMenuListNum = 0;
    for (i = 0; i < ADC_LABELID_MAX; i++)
    {
        if (adc_map_tbl[i].vaild == GPIO_VAILD)
        {

            sprintf(buffer, "%s %d", adc_map_tbl[i].netname, 0);
            mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
            subMenuDataPtrs[i] = subMenuData[i];
            gMenuListNum++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmADCMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmADCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_ADC_MENU_ID, ExitEmADCMenu, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_ADC_MENU_ID);

    /* RegisterHighlightHandler (HighlightOnCertainEmPWM); */

    EmPrepareADCList();

    if (gMenuListNum < 1)
    {
        gMenuListNum++;
    }

    ShowCategory6Screen(
        EM_DEV_ADC_TEXT,
        (U16) 0,
        (U16) NULL,
        (U16) 0,
        STR_GLOBAL_BACK,
        (U16) 0,
        gMenuListNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(StopEmADCMenu, KEY_EVENT_UP);
    SetProtocolEventHandler(EMFMBatteryStatusMsgHandler, PRT_BATTERY_STATUS_IND);
    SetProtocolEventHandler(UpdateEmADC, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
    SendEmADCStartReq();
}


/*****************************************************************************
 * FUNCTION
 *  SendEmADCStartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendEmADCStartReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeSendMsg(MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  SendEmADCStopReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendEmADCStopReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeSendMsg(MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  UpdateEmADC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateEmADC(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j = 0;
    S8 buffer[32];
    double adc_value = 0.0;
    mmi_eq_adc_all_channel_ind_struct *adc_struct = (mmi_eq_adc_all_channel_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i=0; i<ADC_LABELID_MAX; i++)
    {
        if (adc_map_tbl[i].vaild == GPIO_VAILD)
        {
            if (adc_map_tbl[i].port == ADC_VBAT)
    {
        adc_value = (double)adc_struct->vbat;
                sprintf(buffer, "%s %4.2f V", adc_map_tbl[i].netname, adc_value / 1000000.0);

                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_VBATTMP)
            {
                adc_value = (double)adc_struct->bat_temp;
                sprintf(buffer, "%s %4.2f C", adc_map_tbl[i].netname, adc_value / 1000.0);

                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_ACCESSORYID)
            {
                adc_value = (double)adc_struct->vaux;
                sprintf(buffer, "%s %4.2f V", adc_map_tbl[i].netname, adc_value / 1000000.0);
                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_VISENSE)
            {
                adc_value = (double)adc_struct->charge_current;
                if ((adc_struct->charge_current) & 0x80000000)
                {
                    sprintf(buffer, "%s n/a", adc_map_tbl[i].netname);
                }
                else
                {
                    sprintf(buffer, "%s %4.2f A", adc_map_tbl[i].netname, (adc_value) / 1000000.0);
                } 
                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
            else if (adc_map_tbl[i].port == ADC_VCHARGER)
            {
                adc_value = (double)adc_struct->vcharge;
                sprintf(buffer, "%s %4.2f V", adc_map_tbl[i].netname, adc_value / 1000000.0);

                mmi_asc_to_ucs2((PS8) subMenuData[j], buffer);
                subMenuDataPtrs[j] = subMenuData[j];
                j++;
            }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    ShowCategory6Screen(
        EM_DEV_ADC_TEXT,
        0,
        NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        j /* gMenuListNum */ ,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        NULL);

    SetRightSoftkeyFunction(StopEmADCMenu, KEY_EVENT_UP);
    ReplaceNewScreenHandler(EM_DEV_EINT_MENU_ID, ExitEmADCMenu, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  StopEmADCMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopEmADCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* StopTimer(204); */
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
    SendEmADCStopReq();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ExitEmADCMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEmADCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* StopTimer(204); */
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EQ_ADC_ALL_CHANNEL_IND);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);
    SendEmADCStopReq();
}

#undef  ___EM_DEVICE_ADC___

/****************************************
 **
 ** Menu Tree: Device --> Clam
 **
 ****************************************/
#define ___EM_DEVICE_Clam___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmClam
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmClam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryClamMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClamMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClamMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 buffer[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_CLAM_MENUID, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_CLAM_MENUID);
    gMenuListNum = 0;

    sprintf(buffer, "ClamOpen %u", gClamOpenCnt);
    mmi_asc_to_ucs2((PS8) subMenuData[0], buffer);
    subMenuDataPtrs[0] = subMenuData[0];
    gMenuListNum++;

    sprintf(buffer, "ClamClose %u", gClamCloseCnt);
    mmi_asc_to_ucs2((PS8) subMenuData[1], buffer);
    subMenuDataPtrs[1] = subMenuData[1];
    gMenuListNum++;

    ShowCategory6Screen(
        EM_DEV_CLAM_TEXT,
        (U16) 0,
        (U16) NULL,
        (U16) 0,
        STR_GLOBAL_BACK,
        (U16) 0,
        gMenuListNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#undef ___EM_DEVICE_Clam___

/****************************************
 **
 ** Menu Tree: Device --> HW Level
 **
 ****************************************/
#define ___EM_DEVICE_SetHwLevel___


/*****************************************************************************
 * FUNCTION
 *  HighlightEmHWLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmHWLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryHWLevelMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryHWLevelMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryHWLevelMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_HW_LEVEL_MENUID, NULL, EntryHWLevelMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_HW_LEVEL_MENUID);
    nItems = GetNumOfChild(EM_DEV_HW_LEVEL_MENUID);
    GetSequenceStringIds(EM_DEV_HW_LEVEL_MENUID, ItemList);
    SetParentHandler(EM_DEV_HW_LEVEL_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   /* ReturnRequiredNumberImageId(i); */
    }

    ShowCategory52Screen(
        EM_DEV_HW_LEVEL_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(GetHightlightAndEnterHWList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  GetHightlightAndEnterHWList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetHightlightAndEnterHWList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = (U8) GetHighlightedItem();

    switch (idx)
    {
        case EM_HWLEVEL_MENU_MAINLCD_CNTST: /* Main LCD Contrast */
            gHWLevelMenuID = EM_DEV_HW_LEVEL_MLCD_CON_MENUID;
            break;
    #ifdef __MMI_SUBLCD__
        case EM_HWLEVEL_MENU_SUBLCD_CNTST:  /* Sub LCD Contrast */
            gHWLevelMenuID = EM_DEV_HW_LEVEL_SLCD_CON_MENUID;
            break;
    #endif /* __MMI_SUBLCD__ */ 
        case EM_HWLEVEL_MENU_BATTERY:       /* Battery */
            gHWLevelMenuID = EM_DEV_HW_LEVEL_BATTERY_MENUID;
            break;
        case EM_HWLEVEL_MENU_PWM_1:         /* PWM 1 */
            gHWLevelMenuID = EM_DEV_HW_LEVEL_PWM1_MENUID;
            break;
        case EM_HWLEVEL_MENU_PWM_2:         /* PWM 2 */
            gHWLevelMenuID = EM_DEV_HW_LEVEL_PWM2_MENUID;
            break;
        case EM_HWLEVEL_MENU_PWM_3:         /* PWM 3 */
            gHWLevelMenuID = EM_DEV_HW_LEVEL_PWM3_MENUID;
            break;

        default:
            break;
    }

    PrepareHWLevelList();
}


/*****************************************************************************
 * FUNCTION
 *  PrepareHWLevelList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PrepareHWLevelList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMenuListNum = 0;
    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));
    memset(subMenuData, 0, sizeof(subMenuData));

    switch (gHWLevelMenuID)
    {
        case EM_DEV_HW_LEVEL_MLCD_CON_MENUID:   /* Main LCD Contrast */
            for (i = 0; i < LCD_CONTRAST_MAX_LEVEL; i++)
            {
                sprintf(buffer, "[LEV %2d] %d", (i + 1), MainLCD_Contrast_Level_Info[i]);
                mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
                subMenuDataPtrs[i] = subMenuData[i];
                gMenuListNum++;
            }
            break;
        #ifdef __MMI_SUBLCD__
        case EM_DEV_HW_LEVEL_SLCD_CON_MENUID:   /* Sub LCD Contrast */
            for (i = 0; i < LCD_CONTRAST_MAX_LEVEL; i++)
            {
                sprintf(buffer, "[LEV %2d] %d", (i + 1), SubLCD_Contrast_Level_Info[i]);
                mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
                subMenuDataPtrs[i] = subMenuData[i];
                gMenuListNum++;
            }
            break;
        #endif /* __MMI_SUBLCD__ */ 
        case EM_DEV_HW_LEVEL_BATTERY_MENUID:    /* Battery */
            for (i = 0; i < BATTERY_MAX_LEVEL; i++)
            {
                sprintf(buffer, "LEV%2d:%d", (i + 1), Battery_Level_Info[i]);
                mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
                subMenuDataPtrs[i] = subMenuData[i];
                gMenuListNum++;
            }
            break;
        case EM_DEV_HW_LEVEL_PWM1_MENUID:   /* PWM 1 */
            for (i = 0; i < PWM_MAX_LEVEL; i++)
            {
                sprintf(buffer, "[Freq %2d] %u", (i + 1), (U32) PWM1_Level_Info[i][0]);
                mmi_asc_to_ucs2((PS8) subMenuData[gMenuListNum], buffer);
                subMenuDataPtrs[gMenuListNum] = subMenuData[gMenuListNum];
                gMenuListNum++;

                sprintf(buffer, "[Duty %2d] %u", (i + 1), (U32) PWM1_Level_Info[i][1]);
                mmi_asc_to_ucs2((PS8) subMenuData[gMenuListNum], buffer);
                subMenuDataPtrs[gMenuListNum] = subMenuData[gMenuListNum];
                gMenuListNum++;
            }
            break;
        case EM_DEV_HW_LEVEL_PWM2_MENUID:   /* PWM 2 */
            for (i = 0; i < PWM_MAX_LEVEL; i++)
            {
                sprintf(buffer, "[Freq %2d] %u", (i + 1), (U32) PWM2_Level_Info[i][0]);
                mmi_asc_to_ucs2((PS8) subMenuData[gMenuListNum], buffer);
                subMenuDataPtrs[gMenuListNum] = subMenuData[gMenuListNum];
                gMenuListNum++;

                sprintf(buffer, "[Duty %2d] %u", (i + 1), (U32) PWM2_Level_Info[i][1]);
                mmi_asc_to_ucs2((PS8) subMenuData[gMenuListNum], buffer);
                subMenuDataPtrs[gMenuListNum] = subMenuData[gMenuListNum];
                gMenuListNum++;
            }
            break;
        case EM_DEV_HW_LEVEL_PWM3_MENUID:   /* PWM 3 */
            for (i = 0; i < PWM_MAX_LEVEL; i++)
            {
                sprintf(buffer, "[Freq %2d] %u", (i + 1), (U32) Alter_Level_Info[i][0]);
                mmi_asc_to_ucs2((PS8) subMenuData[gMenuListNum], buffer);
                subMenuDataPtrs[gMenuListNum] = subMenuData[gMenuListNum];
                gMenuListNum++;

                sprintf(buffer, "[Duty %2d] %u", (i + 1), (U32) Alter_Level_Info[i][1]);
                mmi_asc_to_ucs2((PS8) subMenuData[gMenuListNum], buffer);
                subMenuDataPtrs[gMenuListNum] = subMenuData[gMenuListNum];
                gMenuListNum++;
            }
            break;

        default:
            break;
    }

    EntryHWLevelDisplyDetail();
}


/*****************************************************************************
 * FUNCTION
 *  EntryHWLevelDisplyDetail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryHWLevelDisplyDetail()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(gHWLevelMenuID, NULL, EntryHWLevelDisplyDetail, NULL);
    guiBuffer = GetCurrGuiBuffer(gHWLevelMenuID);

    /* RegisterHighlightHandler(ExecuteCurrHiliteHandler); */

    ShowCategory6Screen(
        EM_DEV_HW_LEVEL_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        gMenuListNum,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(EntryChangeHWLevel, KEY_EVENT_UP);
    SetRightSoftkeyFunction(CheckHWLevelInfoDirty, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EmHWLevelInfoAccess
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Type        [IN]        
 *  Item        [IN]        
 *  action      [IN]        
 *  value       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EmHWLevelInfoAccess(U16 Type, U8 Item, U8 action, S32 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (Type)
    {
        case EM_DEV_HW_LEVEL_MLCD_CON_MENUID:
            if (action == EM_HW_LEVEL_ACT_GET)  /* GET */
            {
                *value = MainLCD_Contrast_Level_Info[Item];
            }
            else    /* SET */
            {
                if (*value > 255)
                {
                    *value = 255;
                }
                MainLCD_Contrast_Level_Info[Item] = (U8) * value;
            }
            break;
        #ifdef __MMI_SUBLCD__
        case EM_DEV_HW_LEVEL_SLCD_CON_MENUID:
            if (action == EM_HW_LEVEL_ACT_GET)  /* GET */
            {
                *value = SubLCD_Contrast_Level_Info[Item];
            }
            else    /* SET */
            {
                if (*value > 255)
                {
                    *value = 255;
                }
                SubLCD_Contrast_Level_Info[Item] = (U8) * value;
            }
            break;
        #endif /* __MMI_SUBLCD__ */ 
        case EM_DEV_HW_LEVEL_BATTERY_MENUID:
            if (action == EM_HW_LEVEL_ACT_GET)  /* GET */
            {
                *value = Battery_Level_Info[Item];
            }
            else    /* SET */
            {
                if (*value > 9999999)
                {
                    *value = 9999999;
                }
                Battery_Level_Info[Item] = (U32) * value;
            }
            break;

        case EM_DEV_HW_LEVEL_PWM1_MENUID:
            if (action == EM_HW_LEVEL_ACT_GET)  /* GET */
            {
                *value = PWM1_Level_Info[(Item / 2)][(Item % 2)];
            }
            else    /* SET */
            {
                if (*value > 9999999)
                {
                    *value = 9999999;
                }
                PWM1_Level_Info[(Item / 2)][(Item % 2)] = (U32) * value;
            }
            break;

        case EM_DEV_HW_LEVEL_PWM2_MENUID:
            if (action == EM_HW_LEVEL_ACT_GET)  /* GET */
            {
                *value = PWM2_Level_Info[(Item / 2)][(Item % 2)];
            }
            else    /* SET */
            {
                if (*value > 9999999)
                {
                    *value = 9999999;
                }
                PWM2_Level_Info[(Item / 2)][(Item % 2)] = (U32) * value;
            }
            break;

        case EM_DEV_HW_LEVEL_PWM3_MENUID:
            if (action == EM_HW_LEVEL_ACT_GET)  /* GET */
            {
                *value = Alter_Level_Info[(Item / 2)][(Item % 2)];
            }
            else    /* SET */
            {
                if (*value > 9999999)
                {
                    *value = 9999999;
                }
                Alter_Level_Info[(Item / 2)][(Item % 2)] = (U32) * value;
            }
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryChangeHWLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryChangeHWLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;
    S32 level;
    S8 ScrBuf[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Lisen 09062005 */
    gHWLevelHilitItem = (U16) GetHighlightedItem();

    EntryNewScreen(EM_DEV_HW_LEVEL_EDITOR_SCR_ID, NULL, EntryChangeHWLevel, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_HW_LEVEL_EDITOR_SCR_ID);

    EmHWLevelInfoAccess(gHWLevelMenuID, (U8) gHWLevelHilitItem, EM_HW_LEVEL_ACT_GET, &level);
    sprintf(ScrBuf, "%d", level);
    mmi_asc_to_ucs2((PS8) InputBuf, ScrBuf);
    ShowCategory5Screen(
        EM_DEV_LCD_SET_PARAM_1_TEXT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        8,
        history_buffer);

    SetLeftSoftkeyFunction(ApplyHWLevel, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ApplyHWLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ApplyHWLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ArgStrBuf[8];
    S32 Arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) ArgStrBuf, (S8*) InputBuf);
    Arg = atoi((S8*) ArgStrBuf);

    EmHWLevelInfoAccess(gHWLevelMenuID, (U8) gHWLevelHilitItem, EM_HW_LEVEL_ACT_SET, &Arg);
    gIsHWLevelInfoDirty = 1;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  CheckHWLevelInfoDirty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CheckHWLevelInfoDirty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gIsHWLevelInfoDirty)
    {
        ShowCategory2Screen(EM_UPDATE_TITLE_TEXT, 0, STR_GLOBAL_YES, 0, STR_GLOBAL_NO, 0, EM_UPDATE_QUERY_TEXT, NULL);
        SetLeftSoftkeyFunction(SendSetHWLevelInfoReq, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        ReplaceNewScreenHandler(EM_UPDATE_TITLE_TEXT, NULL, NULL);
    }
    else
    {
        GoBackHistory();
    }

}


/*****************************************************************************
 * FUNCTION
 *  SendSetHWLevelInfoReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendSetHWLevelInfoReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_eq_set_hw_level_req_struct *set_hw_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_hw_struct = OslConstructDataPtr(sizeof(mmi_eq_set_hw_level_req_struct));

    for (i = 0; i < 5; i++)
    {
        set_hw_struct->hw_profile.PWM1_freq_Level_Info[i] = PWM1_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM1_duty_Level_Info[i] = PWM1_Level_Info[i][1];

        set_hw_struct->hw_profile.PWM2_freq_Level_Info[i] = PWM2_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM2_duty_Level_Info[i] = PWM2_Level_Info[i][1];

        set_hw_struct->hw_profile.PWM3_freq_Level_Info[i] = Alter_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM3_duty_Level_Info[i] = Alter_Level_Info[i][1];
    }

    memcpy(
        set_hw_struct->hw_profile.MainLCD_Contrast_Level_Info,
        MainLCD_Contrast_Level_Info,
        sizeof(set_hw_struct->hw_profile.MainLCD_Contrast_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Bias_Level_Info,
        MainLCD_Bias_Level_Info,
        sizeof(set_hw_struct->hw_profile.MainLCD_Bias_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Linerate_Level_Info,
        MainLCD_Linerate_Level_Info,
        sizeof(set_hw_struct->hw_profile.MainLCD_Linerate_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Temp_Level_Info,
        MainLCD_Temp_Level_Info,
        sizeof(set_hw_struct->hw_profile.MainLCD_Temp_Level_Info));

#ifdef __MMI_SUBLCD__
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Contrast_Level_Info,
        SubLCD_Contrast_Level_Info,
        sizeof(set_hw_struct->hw_profile.SubLCD_Contrast_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Bias_Level_Info,
        SubLCD_Bias_Level_Info,
        sizeof(set_hw_struct->hw_profile.SubLCD_Bias_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Linerate_Level_Info,
        SubLCD_Linerate_Level_Info,
        sizeof(set_hw_struct->hw_profile.SubLCD_Linerate_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Temp_Level_Info,
        SubLCD_Temp_Level_Info,
        sizeof(set_hw_struct->hw_profile.SubLCD_Temp_Level_Info));
#endif /* __MMI_SUBLCD__ */ 

    memcpy(
        set_hw_struct->hw_profile.Battery_Level_Info,
        Battery_Level_Info,
        sizeof(set_hw_struct->hw_profile.Battery_Level_Info));

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ, set_hw_struct, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  SendSetHWLevelInfoRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SendSetHWLevelInfoRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_hw_level_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
    }
    DeleteScreenIfPresent(EM_DEV_PWM_VIEWER_SCR_ID);
    gIsHWLevelInfoDirty = 0;
}

#undef ___EM_DEVICE_SetHwLevel___

#if defined(NAND_SUPPORT)       /* && defined(MMI_ON_HARDWARE_P) */


/*****************************************************************************
 * FUNCTION
 *  HighlightEmNANDFormat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNANDFormat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmNANDFormatMenu, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmNANDFormatMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmNANDFormatMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    int reval = 0;
    WCHAR K_filename[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drive > FS_NO_ERROR)
    {
        kal_wsprintf(K_filename, "%c:", drive);
        if (FS_GetDevType(K_filename) == FS_DEVICE_TYPE_NAND && FS_GetDevType(K_filename) != FS_GetDevType(L"Z:\\"))
        {
            kal_wsprintf(K_filename, "\\\\.\\%c:", drive);
            reval = FS_GeneralFormat(K_filename, FS_FORMAT_LOW, NULL);
        }
    }
    /*
     * Fail Cause:
     * *        (R1) FS_GetDrive() get nothing
     * *        (R2) public/normal drive is not NAND Flash
     * *        (R3) system drive reside on NAND Flash
     */
    if (reval >= FS_NO_ERROR)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, EM_NOTIFY_DURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, EM_NOTIFY_DURATION, ERROR_TONE);
    }
}
#endif /* defined(NAND_SUPPORT) */ 

#ifdef __OTG_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  HighlightEmDevUSB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmDevUSB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmDevUSBMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmDevUSBMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmDevUSBMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[8];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_USB_SCR_ID, NULL, EntryEmDevUSBMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_USB_SCR_ID);
    nItems = GetNumOfChild(EM_DEVICE_USB_MENNUID);
    GetSequenceStringIds(EM_DEVICE_USB_MENNUID, ItemList);
    SetParentHandler(EM_DEVICE_USB_MENNUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        EM_DEV_USB_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmDevUSBOTGSRP
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmDevUSBOTGSRP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EmDevUSBOTGSRPMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EmDevUSBOTGSRPMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmDevUSBOTGSRPMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__    
    OTG_Init_SRP();
#endif
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, 0);
}
#endif /* __OTG_ENABLE__ */ 

#ifdef __MMI_BT_SUPPORT__       /* __MMI_BT_SUPPORT__ */
#include "SettingProfile.h"     /* for tone ID */
#include "BTMMIScrGprots.h"
#include "bluetooth_struct.h"

extern BOOL mmi_profiles_bt_connect_sco(void (*callback) (void));
extern BOOL mmi_profiles_bt_disconnect_sco(void);


/*****************************************************************************
 * FUNCTION
 *  InitEngineerModeBT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitEngineerModeBT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EM_BT_MENUID, HighlightEmBTMenu);

    /* general test */
    SetHiliteHandler(EM_BT_GENERNAL_TEST_MENUID, HighlightEmBTGeneralTestMenu);
    
    SetHiliteHandler(EM_BT_ENTRY_TEST_MENUID, HighlightEmBTTestMenu);
    SetHiliteHandler(EM_BT_ADD_AUDIO_CONNECTION_MENUID, HighlightEmBTAddAudioConnection);
    SetHiliteHandler(EM_BT_REMOVE_AUDIO_CONNECTION_MENUID, HighlightEmBTRemoveAudioConnection);
    SetHiliteHandler(EM_BT_ENTRY_LOOPBACK_MENUID, HighlightEmBTLoopback);

#if defined(__MMI_BT_MTK_SUPPORT__)
    SetHiliteHandler(EM_BT_EXIT_TEST_MODE_MENUID, HighlightEmBTExitTestMode);
#endif

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
    SetHiliteHandler(EM_BT_AVRCP_CMD_LIST_MENUID, HighlightEmBTAVRCPCmdList);
#endif


#ifdef __MMI_EM_BT_RF_TEST__
    SetHiliteHandler(EM_DEVICE_BT_RF_TEST_MENUID, HighlightEmDevBtRfTest);        

    SetHiliteHandler(EM_DEVICE_BT_RF_TEST_TX_MENUID, HighlightEmDevBtRfTX);        
    SetHiliteHandler(EM_DEVICE_BT_RF_TEST_RX_MENUID, HighlightEmDevBtRfRX);        
    SetHiliteHandler(EM_DEVICE_BT_RF_TEST_BD_ADDR_MENUID, HighlightEmDevBtRfBdAddr);        
    SetHiliteHandler(EM_DEVICE_BT_RF_TEST_MODE_MENUID, HighlightEmDevBtRfBdEnterTestMode);        

#endif /* __MMI_EM_BT_RF_TEST__ */


#ifdef __MMI_EM_BT_GET_CHIP_VERION__
    SetHiliteHandler(EM_BT_GET_CHIP_VERSION_MENUID, HighlightEmBTGetChipVersionMenu);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryEmBTMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryEmBTMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(EntryEmBTMenu, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTGeneralTestMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTGeneralTestMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryEmBTGeneralTestMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryEmBTGeneralTestMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(EntryEmBTGeneralTestMenu, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTTestMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTTestMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryEmBTTestMode, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTAddAudioConnection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTAddAudioConnection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryEmBTAddAudioConnection, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTRemoveAudioConnection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTRemoveAudioConnection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryEmBTRemoveAudioConnection, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTLoopback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTLoopback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryEmBTLoopback, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#if defined(__MMI_BT_MTK_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTExitTestMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmBTExitTestMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EMExitBTTestMode, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_BT_MTK_SUPPORT__) */


#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  HighlightEmBTAVRCPCmdList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_avrcp_ct_main(void);

void HighlightEmBTAVRCPCmdList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_bt_avrcp_ct_main, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  EntryEmBTMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmBTMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_BT_SCR_ID, NULL, EntryEmBTMenu, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_BT_SCR_ID);
    nItems = GetNumOfChild(EM_BT_MENUID);
    GetSequenceStringIds(EM_BT_MENUID, ItemList);
    SetParentHandler(EM_BT_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }
    for (i = 0; i < nItems; i++)
    {
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);  
    }


    ShowCategory52Screen(
        EM_BT_STR_ID,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  EntryEmBTGeneralTestMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmBTGeneralTestMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute, i;              /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *HintList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(EM_BT_GENERNAL_TEST_SCR_ID, NULL, EntryEmBTMenu, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(EM_BT_GENERNAL_TEST_SCR_ID);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(EM_BT_GENERNAL_TEST_MENUID);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(EM_BT_GENERNAL_TEST_MENUID);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(EM_BT_GENERNAL_TEST_MENUID, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(EM_BT_GENERNAL_TEST_MENUID /* ENGINEER_MODE_MENUID */ );

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(EM_BT_GENERNAL_TEST_MENUID, HintList);

    for (i = 0; i < nNumofItem; i++)
    {
        HintList[i] = NULL;
    }

    /* 9. Display Category screen */
    ShowCategory52Screen(
        EM_BT_GENERNAL_TEST_STR_ID,
        0 /* Title Icon */ ,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        HintList,
        0,
        0,
        guiBuffer);

    /* 10.Highlight handler will register function with softkey */
    /*
     * SetLeftSoftkeyFunction(mmi_irda_setup_exec,KEY_EVENT_UP);
     * SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
     * SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
     * SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
     */

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmBTTestMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmBTTestMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
#if defined(__MMI_BT_MTK_SUPPORT__)
    bt_test_mode_req_struct *param_ptr;
#endif

#if defined(__MMI_BT_MTK_SUPPORT__)

	param_ptr = (bt_test_mode_req_struct *)construct_local_para(
	  			  (kal_uint16)sizeof(bt_test_mode_req_struct), TD_CTRL);	
    param_ptr->mode = 1;	

#ifdef __GEMINI__
    param_ptr->dual_sim_uart_setting = PhnsetGetUARTConfig();
#endif

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = BT_APP_SAP;
    ilm_ptr->dest_mod_id = MOD_BT;

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_BT_TEST_MODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct *)param_ptr;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

#endif /* defined(__MMI_BT_MTK_SUPPORT__) */


    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmBTAddAudioConnection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmBTAddAudioConnection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_bt_hfp_sco_link_connect_req();
    mmi_profiles_bt_connect_sco(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmBTRemoveAudioConnection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmBTRemoveAudioConnection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_bt_hfp_sco_link_disconnect_req();
    mmi_profiles_bt_disconnect_sco();
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmBTLoopback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmBTLoopback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 ImageList[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_BT_LOOKBACK_SCR_ID, ExitEMBTLoopback, EntryEmBTLoopback, NULL);
    InitializeCategory57Screen();

    //g_bt_password[0] = 0;
    //g_bt_device_address[0] = 0;

    guiBuffer = GetCurrGuiBuffer(EM_BT_LOOKBACK_SCR_ID);
    inputBuffer = GetCurrNInputBuffer(EM_BT_LOOKBACK_SCR_ID, &inputBufferSize);

    RegisterHighlightHandler(SetHighlightIndex);

    /* BT Address */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[0]), (U8*) GetString(EM_BT_BD_ADDR_STR_ID));
    ImageList[0] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (PU8) g_bt_device_address,
        BT_ADDRESS_LEN + 1,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE);
    ImageList[1] = 0;

    /* BT Password */
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&(wgui_inline_items[2]), (U8*) GetString(EM_BT_BD_PASSWORD_STR_ID));
    ImageList[2] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[3], (PU8) g_bt_password, BT_PASSWORD_LEN + 1, INPUT_TYPE_NUMERIC);
    ImageList[3] = 0;

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 4, inputBuffer);
    }

    DisableCategory57ScreenDone();

    ShowCategory57Screen(
        EM_BT_LOOKBACK_STR_ID,
        EM_DEV_GPIO_SET_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        4,
        ImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EMBTLoopbackReq, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  ExitEMBTLoopback
 * DESCRIPTION
 *  exit bt loopback test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEMBTLoopback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  EMBTLoopbackReq
 * DESCRIPTION
 *  BT PCM loopback test request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMBTLoopbackReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 addrbuf[BT_ADDRESS_LEN + 1];
    U8 passwdbuf[BT_PASSWORD_LEN + 1];
    U32 lap = 0;
    U8 uap = 0;
    U16 nap = 0;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* check if bt address & password is None or too large */
    if ((!mmi_ucs2strlen((const S8*)g_bt_device_address) && !mmi_ucs2strlen((const S8*)g_bt_password))
        ||
        ((mmi_ucs2strlen((const S8*)g_bt_device_address) > BT_ADDRESS_LEN)
         || (mmi_ucs2strlen((const S8*)g_bt_password) > BT_PASSWORD_LEN)))
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
        DeleteUptoScrID(EM_BT_GENERNAL_TEST_SCR_ID);
        return;
    }

    mmi_ucs2_to_asc((PS8) addrbuf, (PS8) g_bt_device_address);

    /* Re-transfer BT address. And check if the bt address is valid.  */
    for (i = 0; i < 12; i++)
    {
        if (addrbuf[i] >= '0' && addrbuf[i] <= '9') /* 0 ~ 9 */
        {
            addrbuf[i] = addrbuf[i] - '0';
        }
        else if (addrbuf[i] >= 'A' && addrbuf[i] <= 'F')    /* A ~ F */
        {
            addrbuf[i] = addrbuf[i] - 'A' + 10;
        }
        else if (addrbuf[i] >= 'a' && addrbuf[i] <= 'f')    /* a ~ f */
        {
            addrbuf[i] = addrbuf[i] - 'a' + 10;
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
            DeleteUptoScrID(EM_BT_GENERNAL_TEST_SCR_ID);
            return;
        }
    }

    /* transfer bt address from U8 array to low-layer format */
    /* nap : array[0]~array[3] */
    for (i = 0; i < 4; i++)
    {
        nap |= ((U16) addrbuf[i] << (((3 - i) << 2)));
    }

    /* uap : array[4]~array[5] */
    for (i = 4; i < 6; i++)
    {
        uap |= ((U8) addrbuf[i] << (((5 - i) << 2)));
    }

    /* lap : array[6]~array[11] */
    for (i = 6; i < 12; i++)
    {
        lap |= ((U32) addrbuf[i] << (((11 - i) << 2)));
    }

    mmi_ucs2_to_asc((PS8) passwdbuf, (PS8) g_bt_password);

    /* enter in progress screen */
    EntryEmBTInProgress();

    /* call mmi_bt function to do pcm loopback test */
    mmi_bt_sco_far_end_loopback_test(lap, uap, nap, passwdbuf, (U8) strlen((const S8*)passwdbuf));

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmBTInProgress
 * DESCRIPTION
 *  BT progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmBTInProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_BT_PROGRESS_SCR, NULL, EntryEmBTInProgress, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_BT_PROGRESS_SCR);

    /* clear End key */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* Show progress screen */
    ShowCategory66Screen(
        EM_BT_LOOKBACK_STR_ID,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(EM_SOCKET_IN_PROGRESS_TEXT),    /* in progress */
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set RSK to abort progress */
    SetRightSoftkeyFunction(EmBTInProgressAbort, KEY_EVENT_UP);
    SetKeyHandler(EmBTInProgressAbort, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  EmBTNotifyLoopbackDoneCnf
 * DESCRIPTION
 *  Loopback test Done.
 *  This function will be called by MMI_BT
 *  after BT PCM loopback test is done.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmBTNotifyLoopbackDoneCnf(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result) /* success */
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_OK, 0, EM_NOTIFY_DURATION, 0);
    }
    else    /* fail */
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
    }

    DeleteUptoScrID(EM_BT_GENERNAL_TEST_SCR_ID);
}


/*****************************************************************************
 * FUNCTION
 *  EmBTInProgressAbort
 * DESCRIPTION
 *  BT progress abort
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmBTInProgressAbort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_sco_far_end_loopback_cancel_test();

    DisplayPopup((PU8) GetString(STR_GLOBAL_CANCEL), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
    DeleteUptoScrID(EM_BT_GENERNAL_TEST_SCR_ID);
}


#if defined(__MMI_BT_MTK_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  EMExitBTTestMode
 * DESCRIPTION
 *  Leave BT Test Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMExitBTTestMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_test_mode_req_struct *param_ptr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	param_ptr = (bt_test_mode_req_struct *)construct_local_para(
	  			  (kal_uint16)sizeof(bt_test_mode_req_struct), TD_CTRL);	
    param_ptr->mode = 2;	
#ifdef __GEMINI__
    param_ptr->dual_sim_uart_setting = PhnsetGetUARTConfig();
#endif

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = BT_APP_SAP;
    ilm_ptr->dest_mod_id = MOD_BT;

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_BT_TEST_MODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct *)param_ptr;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);


    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
}

#endif /* defined(__MMI_BT_MTK_SUPPORT__) */
#endif /* MMI_BT_SUPPORT */


#ifdef __MMI_FM_RADIO__
/**************************************************************
**	FUNCTION NAME		: EMFMRadioSendReq
**
** 	PURPOSE				: FM Radio send request function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EMFMRadioSendReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_fm_radio_config_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_fm_radio_config_req_struct));

    msg_p->request_type= g_fm_radio_cntx.req_type;
       
    switch(g_fm_radio_cntx.req_type)
    {
        case FM_RADIO_CMD_MONO:
        {
            g_fm_radio_cntx.MonoCurrValue = currentHighlightIndex;
            
            if (currentHighlightIndex == FM_RADIO_COMMON_DISABLE)
                msg_p->request.fm_radio_mono.mono_enable = FM_RADIO_COMMON_DISABLE;
            else if(currentHighlightIndex == FM_RADIO_COMMON_ENABLE)
                msg_p->request.fm_radio_mono.mono_enable = FM_RADIO_COMMON_ENABLE;
            else
                ASSERT(0);
            break;
        }
        case FM_RADIO_CMD_STEREO:
        {
            g_fm_radio_cntx.StereoCurrValue = currentHighlightIndex;
            
            if (currentHighlightIndex == FM_RADIO_COMMON_DISABLE)
                msg_p->request.fm_radio_stereo.stereo_enable = FM_RADIO_COMMON_DISABLE;
            else if (currentHighlightIndex == FM_RADIO_COMMON_ENABLE)
            {
                msg_p->request.fm_radio_stereo.stereo_enable = FM_RADIO_COMMON_ENABLE;
                msg_p->request.fm_radio_stereo.sblend_onoff = FM_RADIO_COMMON_ENABLE;
            }
            else if (currentHighlightIndex == FM_RADIO_COMMON_ENABLE_EXTRA)
            {
                msg_p->request.fm_radio_stereo.stereo_enable = FM_RADIO_COMMON_ENABLE;
                msg_p->request.fm_radio_stereo.sblend_onoff = FM_RADIO_COMMON_DISABLE;
            }
            else
                ASSERT(0);
            break;
        }
        case FM_RADIO_CMD_RSSI:
        {
            g_fm_radio_cntx.RSSICurrValue = currentHighlightIndex;
            
            msg_p->request.fm_radio_rssi.level =  g_fm_radio_cntx.RSSICurrValue+1; /* highlight base:0 , fm radio base : 1 */
            break;       	
        }
        case FM_RADIO_CMD_IF_COUNT:
        {
            g_fm_radio_cntx.IFCountDeltaCurrValue = currentHighlightIndex;
            
            msg_p->request.fm_radio_if.item_value = fm_radio_if_count_delta[g_fm_radio_cntx.IFCountDeltaCurrValue];
            break;       	
        }
  	 default:
	     ASSERT(0);
            break;
    }
    EngineerModeSendMsg(MSG_ID_MMI_EQ_FM_RADIO_CONFIG_REQ, msg_p, NULL);
}


/**************************************************************
**	FUNCTION NAME		: EMFMRadioSendRes
**
** 	PURPOSE				: FM Radio send request response function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EMFMRadioSendRes(void* inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);   
}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevFMRadio
**  	PURPOSE			: Hihglight handler of FM Radio menu Item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void HighlightEmDevFMRadio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmDevFMRadioMenu,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevFMRadioMenu
**  	PURPOSE			: Entry function of FM Radio menu item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void EntryEmDevFMRadioMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16	ItemList[8];
    U16	nItems;
    U8*	guiBuffer;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_radio_cntx.req_type == FM_RADIO_CMD_RSSI_INFO)
    {
        StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
        mdi_audio_stop_fmr();
    }

    EntryNewScreen(EM_DEV_FM_RADIO_SCR_ID, NULL, EntryEmDevFMRadioMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_FM_RADIO_SCR_ID);
    nItems = GetNumOfChild(EM_DEVICE_FM_RADIO_MENU_ID);
    GetSequenceStringIds(EM_DEVICE_FM_RADIO_MENU_ID,ItemList);
    SetParentHandler(EM_DEVICE_FM_RADIO_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(EM_DEV_FM_RADIO_TEXT,0,
	 	    	     STR_GLOBAL_OK ,0, STR_GLOBAL_BACK,0,
			     nItems, ItemList, (U16 *)gIndexIconsImageList, 0, 0, 0, guiBuffer);			 
   						  
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevFMRadioMono
**  	PURPOSE			: Hihglight handler of FM Radio Mono menu Item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void HighlightEmDevFMRadioMono(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_radio_cntx.req_type = FM_RADIO_CMD_MONO;
    SetLeftSoftkeyFunction(EntryEmDevFMRadioMonoMenu,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevFMRadioMonoMenu
**
**  	PURPOSE				: Entry function to FM Radio MONO menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmDevFMRadioMonoMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[] = 
    { 
        EM_DEV_SLEEPMODE_OFF_TEXT,        /* Disable */
        EM_DEV_SLEEPMODE_ON_TEXT          /* Enable */
    };    
    U8 nNumofItem = 2;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_FM_RADIO_MONO_SCR_ID, NULL, EntryEmDevFMRadioMonoMenu, NULL);
    guiBuffer = GetCurrGuiBuffer (EM_DEV_FM_RADIO_MONO_SCR_ID);
    RegisterHighlightHandler (SetHighlightIndex);
	
    ShowCategory11Screen (EM_DEV_FM_RADIO_MONO_TEXT, 0,
                                            STR_GLOBAL_OK, 0,
                                            STR_GLOBAL_BACK, 0,
                                            nNumofItem, nStrItemList, g_fm_radio_cntx.MonoCurrValue, guiBuffer);

    SetLeftSoftkeyFunction(EMFMRadioSendReq,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevFMRadioStereo
**  	PURPOSE			: Hihglight handler of FM Radio Stereo menu Item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void HighlightEmDevFMRadioStereo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_radio_cntx.req_type = FM_RADIO_CMD_STEREO;
    SetLeftSoftkeyFunction(EntryEmDevFMRadioStereoMenu,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevFMRadioStereoMenu
**
**  	PURPOSE				: Entry function to FM Radio Stereo menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmDevFMRadioStereoMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[] = 	
    {
            EM_DEV_SLEEPMODE_OFF_TEXT,           /* Disable */
            EM_DEV_FM_RADIO_STEREO_ENABLE_SBLEND_ON_TEXT,
            EM_DEV_FM_RADIO_STEREO_ENABLE_SBLEND_OFF_TEXT	  
    };   
    U8 nNumofItem = 3;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_FM_RADIO_STEREO_SCR_ID, NULL, EntryEmDevFMRadioStereoMenu, NULL);
    guiBuffer = GetCurrGuiBuffer (EM_DEV_FM_RADIO_STEREO_SCR_ID);
    RegisterHighlightHandler (SetHighlightIndex);
	
    ShowCategory11Screen (EM_DEV_FM_RADIO_STEREO_TEXT, 0,
                                             STR_GLOBAL_OK, 0,
                                             STR_GLOBAL_BACK, 0,
                                             nNumofItem, nStrItemList, g_fm_radio_cntx.StereoCurrValue, guiBuffer);

    SetLeftSoftkeyFunction(EMFMRadioSendReq,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevFMRadioRSSI
**  	PURPOSE			: Hihglight handler of FM Radio RSSI menu Item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void HighlightEmDevFMRadioRSSI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_radio_cntx.req_type = FM_RADIO_CMD_RSSI;
    SetLeftSoftkeyFunction(EntryEmDevFMRadioRSSIMenu,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevFMRadioRSSIMenu
**
**  	PURPOSE				: Entry function to FM Radio RSSI menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmDevFMRadioRSSIMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[]=
    {	
        EM_DEV_FM_RADIO_RSSI_LEVEL1_TEXT,
        EM_DEV_FM_RADIO_RSSI_LEVEL2_TEXT,
        EM_DEV_FM_RADIO_RSSI_LEVEL3_TEXT,
        EM_DEV_FM_RADIO_RSSI_LEVEL4_TEXT,
        EM_DEV_FM_RADIO_RSSI_LEVEL5_TEXT,
        EM_DEV_FM_RADIO_RSSI_LEVEL6_TEXT
    };
    U8* guiBuffer;
    U8 nNumofItem = 6;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_FM_RADIO_RSSI_SCR_ID, NULL, EntryEmDevFMRadioRSSIMenu, NULL);
    guiBuffer = GetCurrGuiBuffer (EM_DEV_FM_RADIO_RSSI_SCR_ID);
    RegisterHighlightHandler (SetHighlightIndex);

    ShowCategory11Screen (EM_DEV_FM_RADIO_RSSI_TEXT, 0,
                                            STR_GLOBAL_OK, 0,
                                            STR_GLOBAL_BACK, 0,
                                            nNumofItem, nStrItemList, g_fm_radio_cntx.RSSICurrValue, guiBuffer);

    SetLeftSoftkeyFunction(EMFMRadioSendReq,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevFMRadioIFCountDelta
**  	PURPOSE			: Hihglight handler of FM Radio IF Count Delta menu Item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void HighlightEmDevFMRadioIFCountDelta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_radio_cntx.req_type = FM_RADIO_CMD_IF_COUNT;
    SetLeftSoftkeyFunction(EntryEmDevFMRadioIFCountDeltaMenu,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevFMRadioIFCountDeltaMenu
**
**  	PURPOSE				: Entry function to FM Radio IF Count Delta menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmDevFMRadioIFCountDeltaMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[] =
    {	
        EM_DEV_FM_RADIO_IF_COUNT_DELTA_10_TEXT,
        EM_DEV_FM_RADIO_IF_COUNT_DELTA_15_TEXT,
        EM_DEV_FM_RADIO_IF_COUNT_DELTA_20_TEXT,
        EM_DEV_FM_RADIO_IF_COUNT_DELTA_25_TEXT,
        EM_DEV_FM_RADIO_IF_COUNT_DELTA_30_TEXT
    };
    U8* guiBuffer;
    U8 nNumofItem=5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_FM_RADIO_IF_COUNT_DELTA_SCR_ID, NULL, EntryEmDevFMRadioIFCountDeltaMenu, NULL);
    guiBuffer = GetCurrGuiBuffer (EM_DEV_FM_RADIO_IF_COUNT_DELTA_SCR_ID);
    RegisterHighlightHandler (SetHighlightIndex);

    ShowCategory11Screen (EM_DEV_FM_RADIO_IF_COUNT_DELTA_TEXT, 0,
                                            STR_GLOBAL_OK, 0,
                                            STR_GLOBAL_BACK, 0,
                                            nNumofItem, nStrItemList, g_fm_radio_cntx.IFCountDeltaCurrValue, guiBuffer);

    SetLeftSoftkeyFunction(EMFMRadioSendReq,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevFMRadioRSSIInfo
**  	PURPOSE			: Hihglight handler of FM Radio RSSI Info menu Item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void HighlightEmDevFMRadioRSSIInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fm_radio_cntx.req_type = FM_RADIO_CMD_RSSI_INFO;
    SetLeftSoftkeyFunction(EmDevFMRadioRSSIInfoInit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EmDevFMRadioRSSIInfoInit
**
**  	PURPOSE				: Init function to FM Radio RSSI Info 
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmDevFMRadioRSSIInfoInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* power on FM Radio , and callback can be null if nothing to be handled when interrupted */
    mdi_fmr_power_on_with_path( MDI_DEVICE_SPEAKER2, (mdi_callback) NULL);  

    /* set default volume */
    g_fm_radio_cntx.RSSIInfoCurrVolume = 3;  /* 0-6 */

    /* set default FM frequency */
    g_fm_radio_cntx.rssi_info_freq = 875;

    /* Show FM Radio RSSI Info Screen */
    EntryEmDevFMRadioRSSIInfoMenu(); 
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevFMRadioRSSIInfoMenu
**
**  	PURPOSE				: to show FM Radio RSSI Info screen
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmDevFMRadioRSSIInfoMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    S8 stringbuf[110];
    S8 tmpStr[12];
    S8 tmpStr_UCS2[24];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set audio volume */
    mdi_audio_set_volume( AUD_VOLUME_FMR,  g_fm_radio_cntx.RSSIInfoCurrVolume);

    /* set FM Radio Frequency */
    mdi_fmr_set_freq( g_fm_radio_cntx.rssi_info_freq );

   /* initialize display string */
    memset(stringbuf, 0, 100);

    /* frequency */
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "Fre:");
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);
    
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "  %d.%d \n\n",  g_fm_radio_cntx.rssi_info_freq/10, g_fm_radio_cntx.rssi_info_freq%10);
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);

    /* volume */
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "Vol:");
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);
    
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "    %d\n\n", g_fm_radio_cntx.RSSIInfoCurrVolume);
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);

    /* RSSI_info */
    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "RSSI:");
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);

    memset(tmpStr, 0, 10);
    sprintf(tmpStr, "  %d", g_fm_radio_cntx.RSSIInfoCurrSignallevel);
    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(stringbuf, tmpStr_UCS2);

    /* Entry New Screen & Show Category */
    EntryNewScreen(EM_DEV_FM_RADIO_RSSI_INFO_SCR_ID, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer (EM_DEV_FM_RADIO_RSSI_INFO_SCR_ID);
    
    ShowCategory7Screen(EM_DEV_FM_RADIO_RSSI_INFO_TEXT, 0, 0, 0,
                                            STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (PU8)stringbuf, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

    /* Register End key handler */
    SetKeyHandler(GoBackHistory, KEY_END , KEY_EVENT_DOWN);

    SetKeyHandler(EmDevFMRadioRSSIInfoLeftArrowHdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EmDevFMRadioRSSIInfoRightArrowHdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EmDevFMRadioRSSIInfoUpArrowHdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EmDevFMRadioRSSIInfoDownArrowHdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

}


/**************************************************************
**	FUNCTION NAME		: EmDevFMRadioRSSIInfoLeftArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Left Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmDevFMRadioRSSIInfoLeftArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);

    if (g_fm_radio_cntx.rssi_info_freq > 875)
        g_fm_radio_cntx.rssi_info_freq -= 1;

    EntryEmDevFMRadioRSSIInfoMenu();

    StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);            

}


/**************************************************************
**	FUNCTION NAME		: EmDevFMRadioRSSIInfoRightArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Right Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmDevFMRadioRSSIInfoRightArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
    
    if (g_fm_radio_cntx.rssi_info_freq < 1080)
        g_fm_radio_cntx.rssi_info_freq += 1;
    
    EntryEmDevFMRadioRSSIInfoMenu();

    StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);        

}


/**************************************************************
**	FUNCTION NAME		: EmDevFMRadioRSSIInfoUpArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Up Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmDevFMRadioRSSIInfoUpArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
    
    if (g_fm_radio_cntx.RSSIInfoCurrVolume < MAX_VOL_LEVEL - 1)
        g_fm_radio_cntx.RSSIInfoCurrVolume++;

    EntryEmDevFMRadioRSSIInfoMenu();

    StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);                
}


/**************************************************************
**	FUNCTION NAME		: EmDevFMRadioRSSIInfoDownArrowHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info Down Arrow Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmDevFMRadioRSSIInfoDownArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
    
    if (g_fm_radio_cntx.RSSIInfoCurrVolume > 0)
        g_fm_radio_cntx.RSSIInfoCurrVolume--;

    EntryEmDevFMRadioRSSIInfoMenu();

    StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);                    
}


/**************************************************************
**	FUNCTION NAME		: EMFMRadioRSSIInfoTimeoutHdlr
**
**  	PURPOSE				: Entry function to FM Radio RSSI Info timeout Hdler
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EMFMRadioRSSIInfoTimeoutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    g_fm_radio_cntx.RSSIInfoCurrSignallevel = FMR_GetSignalLevel(g_fm_radio_cntx.rssi_info_freq);

    EntryEmDevFMRadioRSSIInfoMenu();    

    StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);                        
#endif /* #ifdef __MTK_TARGET__ */
}

#endif /* #ifdef __MMI_FM_RADIO__ */


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevRTCXOSC
**
**  	PURPOSE			: High light function to RTC XOSC menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightEmDevRTCXOSC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmDevRTCXOSC, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevRTCXOSC
**
**  	PURPOSE			: Entry function to RTC XOSC menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmDevRTCXOSC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_RTC_XOSC_SCR_ID, NULL, NULL, NULL);
    history_buffer = GetCurrGuiBuffer(EM_DEV_RTC_XOSC_SCR_ID);

#ifdef __MTK_TARGET__
    kal_wsprintf(InputBuf, "%d", RTC_read_xosc_reg());
#endif 

    ShowCategory5Screen(
        EM_DEV_RTC_XOSC_TEXT,
        (U16) NULL,
        STR_GLOBAL_OK,
        (U16) NULL,
        STR_GLOBAL_BACK,
        (U16) NULL,
        INPUT_TYPE_NUMERIC,
        (U8*) InputBuf,
        4,
        history_buffer);

    SetLeftSoftkeyFunction(EmSetRTCXOSCHandler, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/**************************************************************
**	FUNCTION NAME		: EmSetRTCXOSCHandler
**
**  	PURPOSE			: Set RTC XOSC 
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmSetRTCXOSCHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value = 0;
    U8 ParamBuf[3];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    mmi_ucs2_to_asc((S8*)ParamBuf, (S8*)InputBuf);
    value = atoi((S8*)ParamBuf);
    if (value > 255)
    {
        value = 255;
    }
    
    RTC_write_xosc_reg((U8)value);

    EngineerModeSuccessNotice(EM_NOTICE_SUCCESS_TEXT);
    
#endif 
}


#ifdef __MMI_EM_BT_RF_TEST__
/**************************************************************
**	FUNCTION NAME		: HighlightEmDevBtRfTest
**
**  	PURPOSE			: High light function to Bluetooth RF Test menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightEmDevBtRfTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_POWER_ON;

    g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_POWER_ON;
    
    SetLeftSoftkeyFunction(EntryEmDevBtRfTestConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmDevBtRfTestConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmDevBtRfTestConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_is_power_on(MMI_FALSE))
    {
        DisplayPopup(
            (U8*) GetString(EM_DEV_BT_RF_TEST_TURN_OFF_BT_TEXT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    DisplayConfirm(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        get_string(EM_RF_TEST_GSM_CONFIRM_NOTIFY_TEST) ,
        IMG_GLOBAL_INFO,
        WARNING_TONE);

    SetLeftSoftkeyFunction(EmBtRfTestDisableSleepMode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/**************************************************************
**	FUNCTION NAME		: EmBtRfTestDisableSleepMode
**
**  PURPOSE				: BT RF Test Disable Sleep Mode
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmBtRfTestDisableSleepMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* re-register protocol event handler of MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP */
    SetProtocolEventHandler(EmBtRfTestSleepModeHdlr, MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP);    
    EngineerModeSetSleepModeReq(MMI_TRUE);     /* 1 means disable */
}


/**************************************************************
**	FUNCTION NAME		: EmBtRfTestSleepModeHdlr
**
**  PURPOSE				: BT RF Test Sleep Mode Handler
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmBtRfTestSleepModeHdlr(void* inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop MMI sleep mode */
    TurnOnBacklight(0);
             
#ifdef __FLIGHT_MODE_SUPPORT__
    /* Enter Flight mode */
    EmBtRfTestEnterFlightMode();
#else
    EmBtRfTestPowerOnBT();
#endif /* #ifdef __FLIGHT_MODE_SUPPORT__ */
}


#ifdef __FLIGHT_MODE_SUPPORT__
/**************************************************************
**	FUNCTION NAME		: EmBtRfTestEnterFlightMode
**
**  PURPOSE				: BT RF Test menu Enter Flight Mode
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmBtRfTestEnterFlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void mmi_em_enter_flight_mode(FuncPtr callback);
    
    mmi_em_enter_flight_mode((FuncPtr)EmBtRfTestPowerOnBT);

	/* Fion test */
	//EmBtRfTestPowerOnBT();
}
#endif /* __FLIGHT_MODE_SUPPORT__ */


/**************************************************************
**	FUNCTION NAME		: EmBtRfTestPowerOnBT
**
**  PURPOSE				: BT RF Test Disable Sleep Mode
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmBtRfTestPowerOnBT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EmBtRfTestPowerOnBTRspHdlr, MSG_ID_BT_ENGINEER_MODE_POWERON_CNF );    
    EMBtRfTestSendReq();
 
	/* Fion Add, Test */
	//EmBtRfTestPowerOnBTRspHdlr(NULL);

}


/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestPowerOnBTRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestPowerOnBTRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_poweron_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EntryEmDevBtRfTest();
    }
    else
    {
        EngineerModeErrorNotice(EM_AUD_SET_ERROR_TEXT);
		DeleteUptoScrID(EM_DEVICE_MENU_SCR);
    }
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevBtRfTest
**  	PURPOSE			: Entry function of BT RF Test menu item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void EntryEmDevBtRfTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16	ItemList[8];
    U16	nItems;
    U8*	guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_BT_RF_TEST_SCR_ID, NULL, EntryEmDevBtRfTest, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_BT_RF_TEST_SCR_ID);
    nItems = GetNumOfChild(EM_DEVICE_BT_RF_TEST_MENUID);
    GetSequenceStringIds(EM_DEVICE_BT_RF_TEST_MENUID,ItemList);
    SetParentHandler(EM_DEVICE_BT_RF_TEST_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(EM_DEV_BT_RF_TEST_TEXT,0,
                         STR_GLOBAL_OK ,0, STR_GLOBAL_BACK,0,
                         nItems, ItemList, 
                         (U16 *)gIndexIconsImageList, 0, 0, 0, guiBuffer);			 
   						  
    SetRightSoftkeyFunction(EmBtRfTestExit,KEY_EVENT_UP);

    /* Register END key handler */
    SetKeyHandler(EmBtRfTestExit,KEY_END,KEY_EVENT_DOWN);

}


/**************************************************************
**	FUNCTION NAME		: EmBtRfTestExit
**
**  PURPOSE				: BT RF Test menu Exit
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmBtRfTestExit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void ShutdownSystemOperation(void);

    ShutdownSystemOperation();
}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevBtRfTX
**
**  	PURPOSE			: High light function to BT RF Test TX menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightEmDevBtRfTX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_TX;
    
    SetLeftSoftkeyFunction(EntryEmDevBtRfTXRX, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevBtRfRX
**
**  	PURPOSE			: High light function to BT RF Test RX menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightEmDevBtRfRX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_RX;
    
    SetLeftSoftkeyFunction(EntryEmDevBtRfTXRX, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevBtRfTXRX
**  	PURPOSE			: Entry function of BT RF Test TX/RX menu item
**	INPUT PARAM		: void
**	OUTPUT PARAM		: void
**	RETURNS			: void
**	REMARKS			: nil
**************************************************************/
void EntryEmDevBtRfTXRX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    U16 ImageList[9];
    U16 title=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_POWER_ON) &&
         ((g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_TX) &&
         (g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_RX)))
    {
        DisplayPopup((PU8)GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
        return;
    }
    
    EntryNewScreen(EM_DEV_BT_RF_TEST_TXRX_SCR_ID, ExitEmDevBtRfTXRX, NULL, NULL);
    InitializeCategory57Screen();
	
    guiBuffer = GetCurrGuiBuffer(EM_DEV_BT_RF_TEST_TXRX_SCR_ID);
  
    RegisterHighlightHandler(HighlightHandlerEmBtRFTestTxRxnline);

    /* Hoping/Non Hoping */
    g_bt_rf_test_cntx.pEMBtRfHoping[0] = (U8*)GetString(EM_DEV_BT_RF_TEST_NO_HOPING_TEXT);
    g_bt_rf_test_cntx.pEMBtRfHoping[1] = (U8*)GetString(EM_DEV_BT_RF_TEST_HOPING_TEXT);
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[0], 2, (U8**)g_bt_rf_test_cntx.pEMBtRfHoping, &g_bt_rf_test_cntx.currHoping);    
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[0],HighlightHandlerBtRfTxRxHopingInline);    
    ImageList[0] = IMG_STATUS;

    /* channel */
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[1], (U8*)GetString(EM_DEV_BT_RF_TEST_CHANNEL_TEXT));
    ImageList[1] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[2], (PU8)g_bt_rf_test_cntx.channel, 3, INPUT_TYPE_DECIMAL_NUMERIC);
    ImageList[2] = 0;

    /* Packet Type */       
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[3], (U8*)GetString(EM_DEV_BT_RF_TEST_PACKET_TYPE_TEXT));
    ImageList[3] = IMG_STATUS;

    g_bt_rf_test_cntx.pEMBtRfPacketType[0] = (U8*)GetString(EM_DEV_BT_RF_TEST_PACKET_TYPE_DH1_TEXT);
    g_bt_rf_test_cntx.pEMBtRfPacketType[1] = (U8*)GetString(EM_DEV_BT_RF_TEST_PACKET_TYPE_DH3_TEXT);
    g_bt_rf_test_cntx.pEMBtRfPacketType[2] = (U8*)GetString(EM_DEV_BT_RF_TEST_PACKET_TYPE_DH5_TEXT);
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[4], 3, (U8**)g_bt_rf_test_cntx.pEMBtRfPacketType, &g_bt_rf_test_cntx.currPacketType);    
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[4],HighlightHandlerBtRfPacketTypeInline);    
    ImageList[4] = 0;

    /* Data Len. */    
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[5], (U8*)GetString(EM_DEV_BT_RF_TEST_DATA_LEN_TEXT));
    ImageList[5] = IMG_STATUS;
    
    SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[6], (PU8)g_bt_rf_test_cntx.data_len, 4, INPUT_TYPE_DECIMAL_NUMERIC);
    ImageList[6] = 0;

    /* Poll Period */    
    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[7], (U8*)GetString(EM_DEV_BT_RF_TEST_POLL_PERIOD_TEXT));
    ImageList[7] = IMG_STATUS;

    SetInlineItemActivation(&wgui_inline_items[8], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[8], (PU8)g_bt_rf_test_cntx.poll_period, 3, INPUT_TYPE_DECIMAL_NUMERIC);
    ImageList[8] = 0;  

    DisableCategory57ScreenDone();
     	
    if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_TX )
    {
        title = EM_RF_GSM_TX_TEST_TEXT;
    }
    else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_RX)
    {
        title = EM_RF_GSM_RX_TEST_TEXT;
    }

		
    ShowCategory57Screen(title, 0, 
                         STR_GLOBAL_OK, 
                         IMG_GLOBAL_OK, 
       	                 STR_GLOBAL_BACK, 
       	                 IMG_GLOBAL_BACK,
				         9, ImageList, wgui_inline_items, 0, guiBuffer);	
      
    SetCategory57RightSoftkeyFunctions( EMBtRfTestTXRXSendReq, GoBackHistory );
    //SetLeftSoftkeyFunction(EMBtRfTestTXRXSendReq, KEY_EVENT_UP);

    /* Register END key handler */
    SetKeyHandler(GoBackHistory,KEY_END,KEY_EVENT_DOWN);

}


/**************************************************************
**	FUNCTION NAME		: HighlightHandlerEmBtRFTestTxRxnline
**
**  PURPOSE				: Highlight handler of TXRX inline editor in input screen.
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightHandlerEmBtRFTestTxRxnline(S32 index) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EMBtRfTestTXRXSendReq, KEY_EVENT_UP);

    /* Register END key handler, for inline editor might register END key */
    SetKeyHandler(GoBackHistory,KEY_END,KEY_EVENT_DOWN);
}


/**************************************************************
**	FUNCTION NAME		: HighlightHandlerBtRfTxRxHopingInline
**
**  PURPOSE				: Highlight handler of BT Rf Hoping Inline highlight handler.
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightHandlerBtRfTxRxHopingInline(S32 index) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_bt_rf_test_cntx.currHoping)
    {
        case EM_BT_RF_TEST_HOPING_OFF:
        {
            sprintf(buffer,"0");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.channel, buffer);
//            SetInlineItemDisplayOnly(&wgui_inline_items[2], (PU8)g_bt_rf_test_cntx.channel);        
            break;
        }
        case EM_BT_RF_TEST_HOPING_ON:
        {
            sprintf(buffer,"0");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.channel, buffer);
//            SetInlineItemTextEdit(&wgui_inline_items[2], (PU8)g_bt_rf_test_cntx.channel, 3, INPUT_TYPE_DECIMAL_NUMERIC);
            break;
        }
        default:
            ASSERT(0);
    }

    switch(g_bt_rf_test_cntx.currPacketType)
    {
        case EM_BT_RF_TEST_PACKET_TYPE_DH1:
        {
            sprintf(buffer,"27");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.data_len, buffer);

            sprintf(buffer,"2");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.poll_period, buffer);

            break;
        }
        case EM_BT_RF_TEST_PACKET_TYPE_DH3:
        {
            sprintf(buffer,"183");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.data_len, buffer);

            sprintf(buffer,"6");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.poll_period, buffer);
            break;
        }
        case EM_BT_RF_TEST_PACKET_TYPE_DH5:
        {
            sprintf(buffer,"339");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.data_len, buffer);

            sprintf(buffer,"10");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.poll_period, buffer);
            break;
        }
        default:
            ASSERT(0);
    }
    
    redraw_fixed_list();
}


/**************************************************************
**	FUNCTION NAME		: HighlightHandlerBtRfPacketTypeInline
**
**  PURPOSE				: Highlight handler of BT Rf Packet type Inline highlight handler.
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightHandlerBtRfPacketTypeInline(S32 index) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_bt_rf_test_cntx.currPacketType)
    {
        case EM_BT_RF_TEST_PACKET_TYPE_DH1:
        {
            sprintf(buffer,"27");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.data_len, buffer);

            sprintf(buffer,"2");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.poll_period, buffer);

            break;
        }
        case EM_BT_RF_TEST_PACKET_TYPE_DH3:
        {
            sprintf(buffer,"183");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.data_len, buffer);

            sprintf(buffer,"6");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.poll_period, buffer);
            break;
        }
        case EM_BT_RF_TEST_PACKET_TYPE_DH5:
        {
            sprintf(buffer,"339");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.data_len, buffer);

            sprintf(buffer,"10");
            mmi_asc_to_ucs2((PS8)g_bt_rf_test_cntx.poll_period, buffer);
            break;
        }
        default:
            ASSERT(0);
    }

     redraw_fixed_list();
}


/**************************************************************

	FUNCTION NAME		: EMBtRfTestTXRXSendReq

  	PURPOSE				: Send BT RF Test req

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void EMBtRfTestTXRXSendReq(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* Send request to RF,  now req_type = RF_TEST_GSM_RX_TEST */
    g_bt_rf_test_cntx.currCtrlPwrLevel = 1;
    EMBtRfTestSendReq();

    /* show BT RF Testing screen */
//    EntryEmDevBtRfTesting();

}


/**************************************************************
**	FUNCTION NAME		: EMBtRfTestSendReq
**
** 	PURPOSE				: BT RF Test send request function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EMBtRfTestSendReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  textbuf[20];
    U8 value;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_bt_rf_test_cntx.test_item)
    {
        case EM_BT_RF_TEST_TYPE_POWER_ON:
        {
            
#ifdef __GEMINI__           
            bt_engineer_mode_poweron_req_struct* msg_p;
            msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_poweron_req_struct));
            msg_p->dual_sim_uart_setting = PhnsetGetUARTConfig();
            EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_POWERON_REQ, MOD_BT, (local_para_struct*)msg_p, NULL);
#else            
            EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_POWERON_REQ, MOD_BT, NULL, NULL);
#endif
            break;
        }
        case EM_BT_RF_TEST_TYPE_TX:
        {
            bt_engineer_mode_txrx_test_req_struct *msg_p;
            MMI_BOOL result = MMI_TRUE;

            result = EmBtRfTestCheckTXRXValue();

            if (result == MMI_FALSE)
            {
                DisplayPopup((PU8)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
                return;
            }
          
            g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_TX;
            SetProtocolEventHandler(EmBtRfTestTXRXRspHdlr, MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_CNF );    
            ClearInputEventHandler(MMI_DEVICE_ALL);

            msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_txrx_test_req_struct));

            msg_p->pattern = 1; /* means 0000 */

            if (g_bt_rf_test_cntx.currHoping == EM_BT_RF_TEST_HOPING_OFF)
            {
                msg_p->channel_hopping = 0;
                msg_p->tx_freq= 0; 
                msg_p->rx_freq= 0;
            }
            else /* EM_BT_RF_TEST_HOPING_ON */
            {
                msg_p->channel_hopping = 1;

                mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_bt_rf_test_cntx.channel);
                value = atoi((const char *) textbuf);
                msg_p->tx_freq= value; 
                msg_p->rx_freq= 0;
            }

            switch (g_bt_rf_test_cntx.currPacketType)
            {
                case EM_BT_RF_TEST_PACKET_TYPE_DH1:
                    msg_p->packet_type= 0x04;
                    break;

                case EM_BT_RF_TEST_PACKET_TYPE_DH3:
                    msg_p->packet_type= 0x0B;
                    break;

                case EM_BT_RF_TEST_PACKET_TYPE_DH5:
                    msg_p->packet_type= 0x0F;
                    break;
					
            }

            mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_bt_rf_test_cntx.data_len);
            value = atoi((const char *) textbuf);
            msg_p->packet_length= value;

            mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_bt_rf_test_cntx.poll_period);
            value = atoi((const char *) textbuf);
            msg_p->poll_period = value; 

            EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_REQ, MOD_BT, msg_p, NULL);

			/* Fion Add, Test */
            //EmBtRfTestTXRXRspHdlr(NULL);

            break;
        }
        case EM_BT_RF_TEST_TYPE_RX:
        {
            bt_engineer_mode_txrx_test_req_struct *msg_p;
            MMI_BOOL result = MMI_TRUE;

            result = EmBtRfTestCheckTXRXValue();

            if (result == MMI_FALSE)
            {
                DisplayPopup((PU8)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
                return;
            }

            g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_RX;
            
            SetProtocolEventHandler(EmBtRfTestTXRXRspHdlr, MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_CNF );    
	
            ClearInputEventHandler(MMI_DEVICE_ALL);
    
            msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_txrx_test_req_struct));

            msg_p->pattern = 1; /* means 0000 */

            if (g_bt_rf_test_cntx.currHoping == EM_BT_RF_TEST_HOPING_OFF)
            {
                msg_p->channel_hopping = 0;
                msg_p->tx_freq= 0; 
                msg_p->rx_freq= 0;
            }
            else /* EM_BT_RF_TEST_HOPING_ON */
            {
                msg_p->channel_hopping = 1;

                mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_bt_rf_test_cntx.channel);
                value = atoi((const char *) textbuf);
                msg_p->tx_freq= 0; 
                msg_p->rx_freq= value;
            }

            switch (g_bt_rf_test_cntx.currPacketType)
            {
                case EM_BT_RF_TEST_PACKET_TYPE_DH1:
                    msg_p->packet_type= 0x04;
                    break;

                case EM_BT_RF_TEST_PACKET_TYPE_DH3:
                    msg_p->packet_type= 0x0B;
                    break;

                case EM_BT_RF_TEST_PACKET_TYPE_DH5:
                    msg_p->packet_type= 0x0F;
                    break;
					
            }

            mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_bt_rf_test_cntx.data_len);
            value = atoi((const char *) textbuf);
            msg_p->packet_length= value;

            mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_bt_rf_test_cntx.poll_period);
            value = atoi((const char *) textbuf);
            msg_p->poll_period = value; 

            EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_TXRX_TEST_REQ, MOD_BT, msg_p, NULL);

            /* Fion Add, Test */
            //EmBtRfTestTXRXRspHdlr(NULL);

            break;
        }
        case EM_BT_RF_TEST_TYPE_BD_ADDR:
        {
            U8 i=0;
            U8 addrbuf[13];
            bt_set_bd_param_req_struct *msg_p;

            g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_BD_ADDR;
            
            msg_p = OslConstructDataPtr(sizeof(bt_set_bd_param_req_struct));

            mmi_ucs2_to_asc((PS8) addrbuf, (PS8) g_bt_rf_test_cntx.BdAddr);
            
            /* Re-transfer BT address. And check if the bt address is valid.  */
            for (i = 0; i < 12; i++)
            {
                if (addrbuf[i] >= '0' && addrbuf[i] <= '9') /* 0 ~ 9 */
                {
                    addrbuf[i] = addrbuf[i] - '0';
                }
                else if (addrbuf[i] >= 'A' && addrbuf[i] <= 'F')    /* A ~ F */
                {
                    addrbuf[i] = addrbuf[i] - 'A' + 10;
                }
                else if (addrbuf[i] >= 'a' && addrbuf[i] <= 'f')    /* a ~ f */
                {
                    addrbuf[i] = addrbuf[i] - 'a' + 10;
                }
                else
                {
                    DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
                    DeleteUptoScrID(EM_DEV_BT_RF_TEST_TESTING_SCR_ID);
                    return;
                }
            }

            for (i=0;i<12;i+=2)
            {
                msg_p->bd_addr[i/2] = addrbuf[i]+addrbuf[i+1]*16;
            }

            EngineerModeSendMsg_Ext(MSG_ID_BT_SET_BD_ADDR_REQ, MOD_BT, msg_p, NULL);

            break;       	
        }
        case EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE:
        {
            bt_test_mode_req_struct *msg_p;

            if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE)
            {
                if ((g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_POWER_ON) &&
                    (g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE))
                {
                    DisplayPopup((PU8)GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
                    return;
                }
            }

            g_bt_rf_test_cntx.last_cmd = EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE;
            
            msg_p = OslConstructDataPtr(sizeof(bt_test_mode_req_struct));
            msg_p->mode = MMI_TRUE;
#ifdef __GEMINI__
            msg_p->dual_sim_uart_setting = PhnsetGetUARTConfig();
#endif
            EngineerModeSendMsg_Ext(MSG_ID_BT_TEST_MODE_REQ, MOD_BT, msg_p, NULL);

            /* no response, display sucess directly */
            EntryEmDevBtRfTesting();
            //EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);

            break;       	
        }
	 default:
	     ASSERT(0);
            break;
    }
}


/**************************************************************
**	FUNCTION NAME		: EmBtRfTestCheckTXRXValue
**
**  PURPOSE				:  
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
MMI_BOOL EmBtRfTestCheckTXRXValue(void)
{
    U8 value;
    U8 textbuf[10];

    /* To check if channel is valid */
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_bt_rf_test_cntx.channel);
    value = atoi((const char *) textbuf);
    if (value > 78)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;    
}



/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestTXRXRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestTXRXRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_txrx_test_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EntryEmDevBtRfTesting();
    }
    else
    {
        EngineerModeErrorNotice((U16) NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestPwrCtrlLevelRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestPwrCtrlLevelRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_txrx_power_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice((U16) NULL);
    }
    else
    {
        EngineerModeErrorNotice((U16) NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmDevBtRfTesting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmDevBtRfTesting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 title=0, image=0;
    U8 *info;
    S8 buffer[32];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_DEV_BT_RF_TEST_TESTING_SCR_ID, NULL, EntryEmDevBtRfTesting, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_DEV_BT_RF_TEST_TESTING_SCR_ID);
    
    info = (PU8) subMenuData;
    
    if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_TX)
    {
        title = EM_DEV_BT_RF_TEST_TX_TEXT;

        mmi_ucs2cpy((PS8) info, (PS8) GetString(EM_DEV_BT_RF_TEST_CTRL_PWR_LEVEL_TEXT));
        mmi_ucs2cat((PS8) info, (PS8) L":\n\n\n");
        sprintf(buffer, "%d", (U16)g_bt_rf_test_cntx.currCtrlPwrLevel);
        mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        SetKeyHandler(EmBtRfTestPwrLevelUp, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(EmBtRfTestPwrLevelDown, KEY_DOWN_ARROW, KEY_EVENT_UP);
		
    }
    else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_RX)
    {
        title = EM_DEV_BT_RF_TEST_RX_TEXT;

        mmi_ucs2cpy((PS8) info, (PS8) GetString(EM_DEV_BT_RF_TEST_CTRL_PWR_LEVEL_TEXT));
        mmi_ucs2cat((PS8) info, (PS8) L":\n\n\n");
        sprintf(buffer, "%d", (U16)g_bt_rf_test_cntx.currCtrlPwrLevel);
        mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
        mmi_ucs2cat((PS8) info, (PS8) L"\n");

        SetKeyHandler(EmBtRfTestPwrLevelUp, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(EmBtRfTestPwrLevelDown, KEY_DOWN_ARROW, KEY_EVENT_UP);
		
    }
    else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_BD_ADDR)
    {
        mmi_ucs2cpy((PS8) info, (PS8) GetString(EM_GLOBAL_PROCESSING_TEXT));
        title = EM_DEV_BT_RF_TEST_BD_ADDR_TEXT;
        image = IMG_GLOBAL_PROGRESS;
    }
    else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE)
    {
        mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_GLOBAL_ACTIVATED));
        title = EM_DEV_BT_RF_TEST_MODE_TEXT;
        image = IMG_GLOBAL_PROGRESS;
    }

    /* Show progress screen */
    ShowCategory66Screen(
        title,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (PU8) subMenuData,
        image,
        NULL);

    if ((g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_TX)||
        (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_RX))
    {
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
		SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);
//        SetLeftSoftkeyFunction(EMRFTESTWifiTXContPKTCheckAndSendReq, KEY_EVENT_UP);
    }
    else if (g_bt_rf_test_cntx.test_item == EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE)
    {
		SetRightSoftkeyFunction(EmBtRfTestExit, KEY_EVENT_UP);
        SetKeyHandler(EmBtRfTestExit, KEY_END, KEY_EVENT_DOWN);
    }

    /* Set RSK to abort progress */
    

}


/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestPwrLevelUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestPwrLevelUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title=0;
    U8 *info;
    S8 buffer[32];
    bt_engineer_mode_power_test_req_struct *msg_p;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_bt_rf_test_cntx.currCtrlPwrLevel < 7)
    {
        g_bt_rf_test_cntx.currCtrlPwrLevel ++;
    }
    else
    {
        g_bt_rf_test_cntx.currCtrlPwrLevel  = 7;
    }

    title = EM_DEV_BT_RF_TEST_RX_TEXT;
    info = (PU8) subMenuData;
	
    mmi_ucs2cpy((PS8) info, (PS8) GetString(EM_DEV_BT_RF_TEST_CTRL_PWR_LEVEL_TEXT));
    mmi_ucs2cat((PS8) info, (PS8) L":\n\n\n");
    sprintf(buffer, "%d", (U16)g_bt_rf_test_cntx.currCtrlPwrLevel);
    mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* Show progress screen */
    ShowCategory66Screen(
        title,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (PU8) subMenuData,
        0,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);

    SetKeyHandler(EmBtRfTestPwrLevelUp, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(EmBtRfTestPwrLevelDown, KEY_DOWN_ARROW, KEY_EVENT_UP);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(EmBtRfTestPwrLevelUp, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(EmBtRfTestPwrLevelDown, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

    SetProtocolEventHandler(EmBtRfTestPwrCtrlLevelRspHdlr, MSG_ID_BT_ENGINEER_MODE_POWER_TEST_CNF );    
    msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_power_test_req_struct));
    msg_p->level = g_bt_rf_test_cntx.currCtrlPwrLevel;
    EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_POWER_TEST_REQ, MOD_BT, msg_p, NULL);

    /* Fion Add, Test */
    //EmBtRfTestPwrCtrlLevelRspHdlr(NULL);


}



/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestPwrLevelDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestPwrLevelDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title=0;
    U8 *info;
    S8 buffer[32];
    bt_engineer_mode_power_test_req_struct *msg_p;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_bt_rf_test_cntx.currCtrlPwrLevel > 1)
    {
        g_bt_rf_test_cntx.currCtrlPwrLevel --;
    }
    else
    {
        g_bt_rf_test_cntx.currCtrlPwrLevel = 1;
    }

    title = EM_DEV_BT_RF_TEST_RX_TEXT;
    info = (PU8) subMenuData;
	
    mmi_ucs2cpy((PS8) info, (PS8) GetString(EM_DEV_BT_RF_TEST_CTRL_PWR_LEVEL_TEXT));
    mmi_ucs2cat((PS8) info, (PS8) L":\n\n\n");
    sprintf(buffer, "%d", (U16)g_bt_rf_test_cntx.currCtrlPwrLevel);
    mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* Show progress screen */
    ShowCategory66Screen(
        title,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (PU8) subMenuData,
        0,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_DOWN);

    SetKeyHandler(EmBtRfTestPwrLevelUp, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(EmBtRfTestPwrLevelDown, KEY_DOWN_ARROW, KEY_EVENT_UP);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    SetKeyHandler(EmBtRfTestPwrLevelUp, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(EmBtRfTestPwrLevelDown, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 


    SetProtocolEventHandler(EmBtRfTestPwrCtrlLevelRspHdlr, MSG_ID_BT_ENGINEER_MODE_POWER_TEST_CNF );    
    msg_p = OslConstructDataPtr(sizeof(bt_engineer_mode_power_test_req_struct));
    msg_p->level = g_bt_rf_test_cntx.currCtrlPwrLevel;
    EngineerModeSendMsg_Ext(MSG_ID_BT_ENGINEER_MODE_POWER_TEST_REQ, MOD_BT, msg_p, NULL);

}


/**************************************************************

	FUNCTION NAME		: ExitEmDevBtRfTXRX()

  	PURPOSE				: Exit Em BT RF Test inline select screen

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void ExitEmDevBtRfTXRX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    h.scrnID = EM_DEV_BT_RF_TEST_TXRX_SCR_ID;
    h.entryFuncPtr = EntryEmDevBtRfTXRX;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevBtRfBdAddr
**
**  	PURPOSE			: High light function to BT RF Test BD Addr menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightEmDevBtRfBdAddr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_BD_ADDR;

    SetProtocolEventHandler(EmBtRfTestSetBdAddrRspHdlr, MSG_ID_BT_ENGINEER_MODE_CNF );    
	
    SetLeftSoftkeyFunction(EntryEmDevBtRfBdAddr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************
**	FUNCTION NAME		: EntryEmDevBtRfBdAddr
**
**  PURPOSE				: Enrty function for BT RF Test BD ADDR
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmDevBtRfBdAddr(void)
{
    U8* guiBuffer;
    U16 ImageList[2];

    if ((g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_POWER_ON) &&
        (g_bt_rf_test_cntx.last_cmd != EM_BT_RF_TEST_TYPE_BD_ADDR))
    {
        DisplayPopup((PU8)GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 0, EM_NOTIFY_DURATION, 0);
        return;
    }

    EntryNewScreen(EM_DEV_BT_RF_TEST_BD_ADDR_SCR_ID, ExitEmDevBtRfBdAddr, NULL, NULL);
    InitializeCategory57Screen();
	
    guiBuffer = GetCurrGuiBuffer(EM_DEV_BT_RF_TEST_BD_ADDR_SCR_ID);

   /* BD Addr */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*)GetString(EM_DEV_BT_RF_TEST_BD_ADDR_TEXT));
    ImageList[0] = 0;              
    
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8)g_bt_rf_test_cntx.BdAddr, 13, INPUT_TYPE_ALPHANUMERIC_LOWERCASE);
    ImageList[1] = IMG_STATUS;

    DisableCategory57ScreenDone();

    ShowCategory57Screen(EM_DEV_BT_RF_TEST_BD_ADDR_TEXT, 0, 
       	                 STR_GLOBAL_OK, 
       	                 IMG_GLOBAL_OK, 
       	                 STR_GLOBAL_BACK, 
       	                 IMG_GLOBAL_BACK,
				         2, ImageList, wgui_inline_items, 0, guiBuffer);	
    
    SetCategory57RightSoftkeyFunctions( EMBtRfTestSendReq, GoBackHistory );

    /* Register END key handler */
    SetKeyHandler(GoBackHistory,KEY_END,KEY_EVENT_DOWN);
   
}


/**************************************************************

	FUNCTION NAME		: ExitEmDevBtRfBdAddr()

  	PURPOSE				: Exit Em BT RF Test inline select screen

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void ExitEmDevBtRfBdAddr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  EmBtRfTestSetBdAddrRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtRfTestSetBdAddrRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_engineer_mode_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void ShutdownSystemOperation(void);
    
    if (rsp_p->result)
    {
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);

        ShowCategory64Screen(EM_NOTICE_SUCCESS_REBOOT_TEXT, IMG_GLOBAL_WARNING, 0);
        StartTimer(EM_NOTIFYDURATION_TIMER, 3000, ShutdownSystemOperation);
    }
    else
    {
        EngineerModeErrorNotice((U16) NULL);
    }
}


/**************************************************************
**	FUNCTION NAME		: HighlightEmDevBtRfBdEnterTestMode
**
**  	PURPOSE			: High light function to BT RF Test Test Mode menu
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightEmDevBtRfBdEnterTestMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bt_rf_test_cntx.test_item = EM_BT_RF_TEST_TYPE_ENTER_TEST_MODE;

    SetLeftSoftkeyFunction(EMBtRfTestSendReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}



#endif /* #ifdef __MMI_EM_BT_RF_TEST__ */


#ifdef __MMI_EM_BT_GET_CHIP_VERION__

/**************************************************************
**	FUNCTION NAME		: HighlightEmBTGetChipVersionMenu
**
**  	PURPOSE			: 
**
**	INPUT PARAMETERS	: index
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightEmBTGetChipVersionMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EmDevBtChipVersion, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);	
}


/**************************************************************

	FUNCTION NAME		: EmDevBtChipVersion

  	PURPOSE				: Send BT RF Test req

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void EmDevBtChipVersion(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_get_bt_version_cnf_struct test;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    SetProtocolEventHandler(EmBtGetChipVersionRspHdlr, MSG_ID_BT_GET_BT_VERSION_CNF );    
    EngineerModeSendMsg_Ext(MSG_ID_BT_GET_BT_VERSION_REQ, MOD_BT, NULL, NULL);

    /* Fion for test */
    EmBtGetChipVersionRspHdlr(&test);

}


/*****************************************************************************
 * FUNCTION
 *  EmBtGetChipVersionRspHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmBtGetChipVersionRspHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer, *info;
    S8 buffer[40];
    bt_get_bt_version_cnf_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EntryNewScreen(EM_BT_GET_CHIP_VERSION_SCR_ID, NULL, NULL, NULL);

        guiBuffer = GetCurrGuiBuffer(EM_BT_GET_CHIP_VERSION_SCR_ID);

        memset(subMenuData, 0, sizeof(subMenuData));
        info = (PU8) subMenuData;
        
        /* BT Chip version */
        sprintf(buffer, "BT Chip Version :");
        mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
        mmi_ucs2cat((PS8) info, (PS8) L"\n");
               
        for (i=0;i<(sizeof(em_bt_chip_version)/sizeof(em_bt_chip_version_struct));i++)
        {
            if (rsp_p->chip_version == em_bt_chip_version[i].chip_ver)
            {
                sprintf(buffer, "%s", em_bt_chip_version[i].chip_name);
                mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
                mmi_ucs2cat((PS8) info, (PS8) L"\n");
				break;
            }
        }

            
        /* BT Lmp version */
        sprintf(buffer, "BT Lmp Version :");
        mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
        mmi_ucs2cat((PS8) info, (PS8) L"\n");
        
        for (i=0;i<(sizeof(em_bt_lmp_version)/sizeof(em_bt_lmp_version_struct));i++)
        {
            if (rsp_p->lmp_version == em_bt_lmp_version[i].lmp_ver)
            {
                sprintf(buffer, "%s", em_bt_lmp_version[i].lmp_name);
                mmi_asc_to_ucs2((PS8) & info[mmi_ucs2strlen((PS8) info) << 1], (PS8) buffer);
                mmi_ucs2cat((PS8) info, (PS8) L"\n");
				break;
            }
        }

        ShowCategory74Screen(EM_BT_GET_CHIP_VERSION_STR_ID,
                            (U16) 0,
                            (U16) NULL,
                            (U16) 0,
                            STR_GLOBAL_BACK,
                            0,
                            (PU8) subMenuData,
                            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
                            guiBuffer);
        
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        EngineerModeErrorNotice((U16) NULL);
    }
}
#endif /* #ifdef __MMI_EM_BT_GET_CHIP_VERION__ */


#endif /* __MMI_ENGINEER_MODE__ */ 


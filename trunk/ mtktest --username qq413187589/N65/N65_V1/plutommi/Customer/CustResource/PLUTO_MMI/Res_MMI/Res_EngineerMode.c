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
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: Res_MtkApp.c

  	PURPOSE		: Populate Resource for MtkApp

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-15-2003

**************************************************************/

#include "MMI_features.h" 
#include "MMIDataType.h"
#include "EngineerModeResDef.h"
#include "PopulateRes.h"

/*********************************
 ** Engineer Mode Menu Enum
 **********************************/
typedef enum{
	MMI_EM_NETWORK_MENUCNT,              /* Network */
	MMI_EM_DEVICE_MENUCNT,               /* Device */
	MMI_EM_AUDIO_MENUCNT,                /* Audio */
	MMI_EM_GPRS_ACT_MENUCNT,             /* GPRS Act */
	MMI_EM_MISC_MENUCNT,		         /* Misc. */
	MMI_EM_AUTO_TEST_SETTING_MENUCNT,    /* Auto Test List */
	MMI_EM_PWR_DOWN_CONTROL_MENUCNT,     /* PWR down control */
	MMI_EM_SW_PATCH_MENUCNT,             /* SW Patch */
	MMI_EM_DEBUG_INFO_MENUCNT,           /* Debug Info */

#ifdef __TCPIP__
   MMI_EM_SOCKET_MENUCNT,                /* Socket Test */
#endif

#if defined(__MMI_BT_SUPPORT__)
	MMI_EM_BT_MENUCNT,                   /* Bluetooth */
#endif

	MMI_EM_PROFILING_MENUCNT,            /* Profiling */

#if defined(__FLIGHT_MODE_SUPPORT__) || defined(__WIFI_SUPPORT__)
    MMI_EM_RF_MENUCNT,                   /* RF Test Tool */ 
#endif    

#if defined(__VOIP__)
    MMI_EM_VOIP_MENUCNT,                 /* VOIP Test */
#endif

#if defined (__MMI_CSB_BROWSER__)
	MMI_EM_CS_BROWSER_MENUCNT,			 /* Category Screen Browser */
#endif

	MMI_EM_MENUCNT_NUM
} MMI_EM_MENUCNT_ENUM;

/*********************************
 ** Engineer Mode Functions
 **********************************/
#ifdef __MMI_ENGINEER_MODE__ //for saperate MMI feature by project

void populateEngineerModeMenu(void)
{
    U16 menu_item_count;

    /*****************************************************************/
    /****************************  Strings ***************************/
    /*****************************************************************/

    /******************* EM Init *********************/
	ADD_APPLICATION_STRING2 (ENGINEER_MODE_TEXT, "Engineer Mode", "Engineer Mode Menu LSK String");


    /***************** Network Info ******************/
	ADD_APPLICATION_STRING2 (EM_NETWORK_SETTING_TEXT , "Network Setting", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NETWORK_INFO_TEXT	,  "Network Info", "Engineer Mode Menu Caption String");

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */

	ADD_APPLICATION_STRING2 (EM_NETWORK_CELL_LOCK_TEXT	,  "Cell Lock", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NETWORK_1900_BAND_TEXT	,  "1900 Band", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NETWORK_ARFCN_TEXT	,  "Arfcn", "Engineer Mode Menu Caption String");	

	ADD_APPLICATION_STRING2 (EM_NET_RR_CELL_SEL_TEXT   , "RR Cell Sel", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_RR_CH_DSCR_TEXT    , "RR Ch Dscr", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_RR_CTRL_CH_TEXT    , "RR Ctrl Chan", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_RR_RACH_CTRL_TEXT  , "RR RACH Ctrl", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_RR_LAI_INFO_TEXT   , "RR LAI Info", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_RR_RADIO_LINK_TEXT , "RR Radio Link", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_RR_MEAS_REP_TEXT   , "RR Meas Rep", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_CC_CHAN_INFO_TEXT , "CC Chan Info", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_CC_CALL_INFO_TEXT  , "CC Call Info", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_CB_INFO_TEXT        , "CB Info", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_PLMN_INFO_TEXT      , "PLMN Info", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_GPRS_INFO_TEXT      , "GPRS Info", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NET_Si2Q_MI_INFO_TEXT      , "Si2Q/Mi Info", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NET_TBF_STATUS_TEXT      , "TBF Status", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NET_BLK_INFO_TEXT      , "Block Info", "Engineer Mode Menu Caption String");	

#if defined(__EM_MODE__)
	ADD_APPLICATION_STRING2 (EM_NET_NETWORK_EVENT_TEXT  , "Network Events", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NET_NETWORK_EVENT_START_TEXT  , "Start", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NET_NETWORK_EVENT_FILTER_TEXT  , "Filter", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NET_NETWORK_EVENT_SETTING_TEXT  , "Setting", "Engineer Mode Menu Caption String");		
	ADD_APPLICATION_STRING2 (EM_NET_NETWORK_EVENT_GROUP_TEXT  , "Event Group", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_NET_NETWORK_EVENT_SELECT_RING_TEXT  , "Select Ring", "Engineer Mode Menu Caption String");	
#endif /* defined(__EM_MODE__) */

    /******************** Device *********************/
	ADD_APPLICATION_STRING2 (EM_DEVICE_TEXT		, "Device", "Engineer Mode Menu Caption String");
    /* LCD */
    ADD_APPLICATION_STRING2 (EM_DEV_LCD_TEXT  , "LCD", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_LCD_MAIN_TEXT, "Main LCD", "Engineer Mode Menu Caption String");
#ifdef __MMI_SUBLCD__
   ADD_APPLICATION_STRING2 (EM_DEV_LCD_SUB_TEXT, "Sub LCD", "Engineer Mode Menu Caption String");
#endif
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_CONSTRAST_TEXT, "Set Contrast", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_BIAS_TEXT, "Set Bias Ratio", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_LINERATE_TEXT, "Set Line Rate", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_TEMPERATURE_TEXT, "Set temperature", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_PARAM_1_TEXT, "Set Param 1", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_PARAM_2_TEXT, "Set Param 2", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_PARAM_3_TEXT, "Set Param 3", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_PARAM_4_TEXT, "Set Param 4", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_PARAM_5_TEXT, "Set Param 5", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_SET_COLOR_TEXT, "Set Color", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_RGB_R_TEXT, "Red", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_RGB_G_TEXT, "Green", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_RGB_B_TEXT, "Blue", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_LCD_DISPLAY_DEMO_PIC_TEXT, "Diplay Demo Pic.", "Engineer Mode Menu Caption String");		

	/* GPIO */
	ADD_APPLICATION_STRING2 (EM_DEV_GPIO_TEXT, "GPIO", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_GPIO_LIST_TEXT, "List GPO/GPIO", "Engineer Mode Menu Caption String");
	//ADD_APPLICATION_STRING2 (EM_DEV_GPIO_SET_TEXT, "Toggle GPIO", "Engineer Mode Menu Caption String");
	//ADD_APPLICATION_STRING2 (EM_DEV_GPO_SET_TEXT, "Toggle GPO", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_GPIO_EDITOR, "GPIO Editor", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_GPO_EDITOR, "GPO Editor", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_GPIO_MODE , "Mode:", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_GPIO_DIRECTION , "Direction:", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_GPIO_LEVEL, "Current Level:", "Engineer Mode Menu Caption String");

    /* PWM */
	ADD_APPLICATION_STRING2 (EM_DEV_PWM_TEXT, "PWM", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_PWM_START_TEXT, "PWM Start, LSK to Stop", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_PWM_SET_FREQ_TEXT, "Set Freq", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_PWM_SET_DUTY_TEXT, "Set Duty Cycle", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_PWM_EDITOR, "PWM Editor", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_PWM_FREQUENCY,"Frequency:", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_PWM_DUTY, "Duty:", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_PWM_LEVEL, " Level:", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_PWNDOWN_CTRL_PDN_CON0, "PDN_con0", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_PWNDOWN_CTRL_PDN_CON1, "PDN_con1", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_PWNDOWN_CTRL_PDN_CON2, "PDN_con2", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_STR_PWNDOWN_CTRL_PDN_CON3, "PDN_con3", "Engineer Mode Menu Caption String");

    /* EINT */
	ADD_APPLICATION_STRING2 (EM_DEV_EINT_TEXT, "EINT", "Engineer Mode Menu Caption String");

	/* ADC */
	ADD_APPLICATION_STRING2 (EM_DEV_ADC_TEXT, "ADC", "Engineer Mode Menu Caption String");

    /* Clam */
#ifdef __MMI_CLAMSHELL__
	ADD_APPLICATION_STRING2 (EM_DEV_CLAM_TEXT, "CLAM", "Engineer Mode Menu Caption String");
#endif

	/* Set Default Level */
	ADD_APPLICATION_STRING2 (EM_DEV_HW_LEVEL_TEXT, "Set Default Level", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_HW_LEVEL_MLCD_CON_TEXT, "MainLCD Contrast", "Engineer Mode Menu Caption String");
#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_STRING2 (EM_DEV_HW_LEVEL_SLCD_CON_TEXT, "SubLCD Contrast", "Engineer Mode Menu Caption String");
#endif
	ADD_APPLICATION_STRING2 (EM_DEV_HW_LEVEL_BATTERY_TEXT, "Battery", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_HW_LEVEL_PWM1_TEXT, "PWM 1", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_HW_LEVEL_PWM2_TEXT, "PWM 2", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_HW_LEVEL_PWM3_TEXT, "PWM 3", "Engineer Mode Menu Caption String");

    /* Set UART */
	ADD_APPLICATION_STRING2 (EM_DEV_SET_UART_TEXT   , "Set UART", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_UART_SETTING_TEXT, "UART Setting", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_SET_UART_TST_PS_TEXT   , "TST-PS Config", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_SET_UART_TST_L1_TEXT   , "TST-L1 Config", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_SET_UART_PS_TEXT   , "PS Config", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_USB_PORT_TEXT   , "USB Port", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_SET_UART_ERROR_TEXT , "Not Allow or Conflict!", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_SET_UART_ERROR_PS_NOT_NULL_TEXT , "PS can't be NULL!", "Engineer Mode Menu Caption String");	
#if defined(__MA_L1__)
/* under construction !*/
#endif    
	ADD_APPLICATION_STRING2 (EM_DEV_UART_1_TEXT   , "UART 1", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_UART_2_TEXT   , "UART 2", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_UART_3_TEXT   , "UART 3", "Engineer Mode Menu Caption String");
	//ADD_APPLICATION_STRING2 (EM_DEV_UART_IRDA_TEXT   , "IRComm", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_AUTO_TEXT   , "AUTO", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_75_TEXT   , "75", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_150_TEXT   , "150", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_300_TEXT   , "300", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_600_TEXT   , "600", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_1200_TEXT   , "1200", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_2400_TEXT   , "2400", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_4800_TEXT   , "4800", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_7200_TEXT   , "7200", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_9600_TEXT   , "9600", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_14400_TEXT   , "14400", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_19200_TEXT   , "19200", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_28800_TEXT   , "28800", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_33900_TEXT   , "33900", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_38400_TEXT   , "38400", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_57600_TEXT   , "57600", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_115200_TEXT   , "115200", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_230400_TEXT   , "230400", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_460800_TEXT   , "460800", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BAUD_921600_TEXT   , "921600", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_UART_POWER_ONOFF_TEXT      , "UART POWER ON/OFF", "Engineer Mode Menu Caption String");	

	/* Ext. Camera */
#ifdef CAMERA_MODULE
	ADD_APPLICATION_STRING2 (EM_STR_EXT_CAMERA_TEXT , "Ext. Camera", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_EXT_CAMERA_WRITE_TEXT , "Write Parameter", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_EXT_CAMERA_READ_TEXT , "Read Parameter", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_EXT_CAMERA_COMMAND_TEXT , "Command", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_STR_EXT_CAMERA_PARA_TEXT , "Parameter", "Engineer Mode Menu Caption String");
#endif	

    /* Sleep Mode */
	ADD_APPLICATION_STRING2 (EM_DEV_SLEEPMODE_TEXT      , "Sleep Mode", "Engineer Mode Menu Caption String");

    /* DCM Mode */
#if defined(DCM_ENABLE)
	ADD_APPLICATION_STRING2 (EM_DEV_DCMMODE_TEXT      , "DCM Mode", "Engineer Mode Menu Caption String");
#endif	

    /* SWDBG */
    ADD_APPLICATION_STRING2 (EM_SWDBG_TEXT       , 		"SWDBG", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_OFF_TEXT       , 		"OFF", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_DSP_L1_TEXT       , 	"DSP L1", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_DSP_PS_TEXT       , 	"DSP PS", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_L1_PS_TEXT       , 	"L1 PS", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_MCU_TEXT       , 		"MCU", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_MCU_DSP_TEXT       , 		"MCU DSP", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_MCU_DSP_IRDBG_TEXT		,		 "MCU DSP IRDBG", "Engineer Mode Menu Caption String");	 
    ADD_APPLICATION_STRING2 (EM_SWDBG_DSP_L1_PS_TEXT      , "DSP L1 PS", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_SWDBG_RESET_TEXT		, "RESET", "Engineer Mode Menu Caption String");	

    /* NAND Format */
#if defined(NAND_SUPPORT) //&& defined(MMI_ON_HARDWARE_P) 
	ADD_APPLICATION_STRING2 (EM_DEV_NAND_FORMAT_TEXT, "NAND Format", "Engineer Mode Menu Caption String");
#endif

    /* USB SRP */
#ifdef __OTG_ENABLE__
	ADD_APPLICATION_STRING2 (EM_DEV_USB_TEXT, "USB", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_USB_OTG_SRP_TEXT, "OTG SRP", "Engineer Mode Menu Caption String");	
#endif

	//ADD_APPLICATION_STRING2 (EM_DEV_VDROP_TEXT, "V_DROP", "Engineer Mode Menu Caption String");

    /* PMIC6318 */	
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_TEXT, "PMIC 6318", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_REGISTER_EDITOR_TEXT, "Register R/W", "Engineer Mode Menu Caption String");
#if defined(MT6318)
    /* Charger Status */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_CHARGER_STATUS_TEXT, "Charger Status", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_CHARGER_OVSPI_TEXT, "OV SPI", "Engineer Mode Over Voltage String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_CHARGER_CHRDET_TEXT, "Charger Detect", "Engineer Mode Charger Detection String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_CHARGER_AC_DET_TEXT, "AC Detect", "Engineer Mode AC Detection String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_CHARGER_USB_DET_TEXT, "USB Detect", "Engineer Mode USB Detection String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_CHARGER_BAT_ON_TEXT, "Battery ON", "Engineer Mode Battery ON String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_CHARGER_CV_TEXT, "CV Mode", "Engineer Mode CV mode String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_CHARGER_CHRG_DIS_TEXT, "Charger_DIS", "Engineer Mode Charging String");       
    /* Set charger */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_TEXT, "Set Charger", "Engineer Mode Menu Caption String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CHREN_TEXT, "CHREN", "Engineer Mode Set Charger Enable String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_AC_CURRENT_TEXT, "AC Current", "Engineer Mode Set Charger AC Current String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_USB_CHREN_TEXT, "USB CHREN", "Engineer Mode Set Charger USB enable String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_USB_CURRENT_TEXT, "USB Current", "Engineer Mode Set Charger USB Current String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_50_TEXT, "Current 50mA", "Engineer Mode Set Charger Current 50 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_90_TEXT, "Current 90mA", "Engineer Mode Set Charger Current 90 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_150_TEXT, "Current 150mA", "Engineer Mode Set Charger Current 150 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_225_TEXT, "Current 225mA", "Engineer Mode Set Charger Current 225 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_300_TEXT, "Current 300mA", "Engineer Mode Set Charger Current 300 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_450_TEXT, "Current 450mA", "Engineer Mode Set Charger Current 450 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_650_TEXT, "Current 650mA", "Engineer Mode Set Charger Current 650 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_SET_CHARGER_CURRENT_800_TEXT, "Current 800mA", "Engineer Mode Set Charger Current 800 String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_CHARGER_CURRENT_TEXT, "Chr Current", "Engineer Mode Charger Current String");       
    /* RGB LED */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_RGB_TEXT, "RGB", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_R_LED_TEXT, "R LED", "Engineer Mode Menu R LED String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_R_LED_CURRENT_TEXT, "R Current", "Engineer Mode Menu R LED Current String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_G_LED_TEXT, "G LED", "Engineer Mode Menu G LED String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_G_LED_CURRENT_TEXT, "G Current", "Engineer Mode Menu G LED Current String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_B_LED_TEXT, "B LED", "Engineer Mode Menu B LED String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_B_LED_CURRENT_TEXT, "B Current", "Engineer Mode Menu B LED Current String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_RGB_LED_CURRENT_12_TEXT, "12 mA", "Engineer Mode Menu RGB LED Current 12 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_RGB_LED_CURRENT_16_TEXT, "16 mA", "Engineer Mode Menu RGB LED Current 16 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_RGB_LED_CURRENT_20_TEXT, "20 mA", "Engineer Mode Menu RGB LED Current 20 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_RGB_LED_CURRENT_24_TEXT, "24 mA", "Engineer Mode Menu RGB LED Current 24 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_RGB_LED_CURRENT_TEXT, "RGB CURRENT", "Engineer Mode Menu RGB LED Current  String");              
    /* KP LED */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_LED_TEXT, "KP LED", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_ENABLE_TEXT, "KP Enable", "Engineer Mode KP LED enable String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_DUTY_OPTION_TEXT, "Duty Cycle", "Engineer Mode KP LED Duty Cycle String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_DIM_CLOCK_TEXT, "DIM Clock", "Engineer Mode KP LED DIM Clock String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_CHR_PUMP_EN_TEXT, "CHR_PUMP_EN", "Engineer Mode KP LED CHR_PUMP_EN String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_TEXT, "CHRPUMP current", "Engineer Mode KP LED CHR_PUMP Current String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL1_TEXT, "Current Level 1", "Engineer Mode KP LED CHR_PUMP Current 1 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL2_TEXT, "Current Level 2", "Engineer Mode KP LED CHR_PUMP Current 2 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL3_TEXT, "Current Level 3", "Engineer Mode KP LED CHR_PUMP Current 3 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_LEVEL4_TEXT, "Current Level 4", "Engineer Mode KP LED CHR_PUMP Current 4 String");              
    /* BL LED */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_BL_LED_TEXT, "BL LED", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_BL_ENABLE_TEXT, "BL Enable", "Engineer Mode BL LED Enable String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_BL_DUTY_OPTION_TEXT, "Duty Cycle", "Engineer Mode BL LED Duty Cycle String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_BL_DIM_CLOCK_TEXT, "DIM Clock", "Engineer Mode BL LED DIM Clock String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_BL_DIM_BYPASS_TEXT, "DIM Bypass", "Engineer Mode BL LED DIM Bypass String");       
    /* Audio */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_TEXT, "Audio", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_SPEAKER_TEXT, "Speaker", "Engineer Mode Audio Speaker Enable String");
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN_TEXT, "AMP Gain", "Engineer Mode Audio Amplifier Gain String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN0_TEXT, "Speaker Gain 0", "Engineer Mode Audio Amplifier Gain 0 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN1_TEXT, "Speaker Gain 1", "Engineer Mode Audio Amplifier Gain 1 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN2_TEXT, "Speaker Gain 2", "Engineer Mode Audio Amplifier Gain 2 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN3_TEXT, "Speaker Gain 3", "Engineer Mode Audio Amplifier Gain 3 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN4_TEXT, "Speaker Gain 4", "Engineer Mode Audio Amplifier Gain 4 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN5_TEXT, "Speaker Gain 5", "Engineer Mode Audio Amplifier Gain 5 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN6_TEXT, "Speaker Gain 6", "Engineer Mode Audio Amplifier Gain 6 String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_AUDIO_AMPGAIN7_TEXT, "Speaker Gain 7", "Engineer Mode Audio Amplifier Gain 7 String");       
    /* Misc */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_TEXT, "Misc.", "Engineer Mode Menu Caption String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_VIBRATOR_ENABLE_TEXT, "Vibrator Enable", "Engineer Mode MISC Vibrator Enable String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_VIBRATOR_OUT_TEXT, "Vibrator VOUT", "Engineer Mode MISC Vibrator  OUT String");              
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_VMC_ENABLE_TEXT, "VMC", "Engineer Mode MISC VMC Enable String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_VMC_SEL_TEXT, "VMC Sel", "Engineer Mode MISC VMC Sel.  String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_VA_SW_ENABLE_TEXT, "VA SW", "Engineer Mode MISC VA SW Enable  String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_VA_SW_SEL_TEXT, "VA SW Sel", "Engineer Mode MISC VA SW Sel String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_USB_PWR_ENABLE_TEXT, "USB PWR", "Engineer Mode MISC USB PWR Enable String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_VBAT_OUT_ENABLE_TEXT, "VBAT V\OUT", "Engineer Mode MISC VBAT OUT Enable String");       
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_ISENSE_OUT_ENABLE_TEXT, "Isense OUT", "Engineer Mode MISC Isense Out Enable String");       
    /* LCM BL Setting */
    ADD_APPLICATION_STRING2 (EM_DEV_PMIC_6318_MISC_LCM_BL_SETTING_TEXT, "LCM BL Setting", "Engineer Mode 6318 LCM BL Setting String");       
#endif

    /* FM Radio */
#ifdef __MMI_FM_RADIO__
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_TEXT, "FM Radio", "Engineer Mode FM Radio Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_MONO_TEXT, "MONO", "Engineer Mode FM Radio MONO Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_STEREO_TEXT, "STEREO", "Engineer Mode FM Radio Stereo Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_STEREO_ENABLE_SBLEND_ON_TEXT, "Enable + Sblend On", "Engineer Mode FM Radio Stereo Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_STEREO_ENABLE_SBLEND_OFF_TEXT, "Enable + Sblend Off", "Engineer Mode FM Radio Stereo Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_TEXT, "RSSI", "Engineer Mode FM Radio RSSI Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_LEVEL1_TEXT, "Level 1", "Engineer Mode FM Radio RSSI Level 1 Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_LEVEL2_TEXT, "Level 2", "Engineer Mode FM Radio RSSI Level 2 Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_LEVEL3_TEXT, "Level 3", "Engineer Mode FM Radio RSSI Level 3 Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_LEVEL4_TEXT, "Level 4", "Engineer Mode FM Radio RSSI Level 4 Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_LEVEL5_TEXT, "Level 5", "Engineer Mode FM Radio RSSI Level 5 Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_LEVEL6_TEXT, "Level 6", "Engineer Mode FM Radio RSSI Level 6 Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_IF_COUNT_DELTA_TEXT, "IF Count Delta", "Engineer Mode FM Radio IF count delta Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_IF_COUNT_DELTA_10_TEXT, "10 kHz", "Engineer Mode FM Radio IF count delta 10 Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_IF_COUNT_DELTA_15_TEXT, "15 kHz", "Engineer Mode FM Radio IF count delta 15 Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_IF_COUNT_DELTA_20_TEXT, "20 kHz", "Engineer Mode FM Radio IF count delta 20 Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_IF_COUNT_DELTA_25_TEXT, "25 kHz", "Engineer Mode FM Radio IF count delta 25 Caption String");	
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_IF_COUNT_DELTA_30_TEXT, "30 kHz", "Engineer Mode FM Radio IF count delta 30 Caption String");		
	ADD_APPLICATION_STRING2 (EM_DEV_FM_RADIO_RSSI_INFO_TEXT, "RSSI Info.", "Engineer Mode FM Radio RSSI Info Menu Caption String");			
#endif /* #ifdef __MMI_FM_RADIO__ */

#if defined(__MMI_TVOUT__) 
	ADD_APPLICATION_STRING2 (EM_DEV_TVOUT_SETTING_TEXT, "TV-Out", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_TVOUT_SETTING_SWITCH_TEXT, "TV-Out On/Off", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_TVOUT_SETTING_TUNNING_TEXT, "TV-Out Tunning", "Engineer Mode Menu Caption String");
#endif /* __MMI_TVOUT__ */

	ADD_APPLICATION_STRING2 (EM_DEV_RTC_XOSC_TEXT, "RTC XOSC (WO)", "Engineer Mode Menu Caption String");

/* BT RF Test */
#ifdef __MMI_EM_BT_RF_TEST__

	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_TEXT, "Bluetooth RF Test", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_TX_TEXT, "TX Test", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_RX_TEXT, "RX Test", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_BD_ADDR_TEXT, "BD Address", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_MODE_TEXT, "Enter Test Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_NO_HOPING_TEXT, "No Hoping", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_HOPING_TEXT, "Hoping", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_CHANNEL_TEXT, "Channel", "Engineer Mode Menu Caption String");

	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_CTRL_PWR_LEVEL_TEXT, "Ctrl Pwr Lvl", "Engineer Mode Menu Caption String");

	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_PACKET_TYPE_TEXT, "Packet Type", "Engineer Mode Menu Caption String");

    ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_PACKET_TYPE_DH1_TEXT, "DH 1", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_PACKET_TYPE_DH3_TEXT, "DH 3", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_PACKET_TYPE_DH5_TEXT, "DH 5", "Engineer Mode Menu Caption String");
    
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_DATA_LEN_TEXT, "Data Len.", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_POLL_PERIOD_TEXT, "Poll Period", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_BT_RF_TEST_TURN_OFF_BT_TEXT, "Turn off BT first!", "Engineer Mode Menu Caption String");

#endif /* __MMI_EM_BT_RF_TEST__ */


   /* End of Device */


    /********************* Audio *********************/
	ADD_APPLICATION_STRING2 (EM_AUDIO_TEXT		, "Audio", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_FIR_TEXT , "FIR", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_SET_VOLUME_TEXT , "Set Volume", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_SPEECH_TEXT      , "Speech", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_SIDE_TONE_TEXT  , "Side Tone", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_KEY_TONE_TEXT   , "Key Tone", "Engineer Mode Menu Caption String");
	//ADD_APPLICATION_STRING2 (EM_AUD_CALL_TONE_TEXT  , "Call Tone", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_SOUND_TEXT  , "FM Radio", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_MELODY_TEXT  , "Melody", "Engineer Mode Menu Caption String");
	//ADD_APPLICATION_STRING2 (EM_AUD_MEDIA_TEXT , "Media", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_MICROPHONE_TEXT , "Microphone", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_AUD_RING_TONE_TEXT , "Ring Tone", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_SET_MODE_TEXT , "Set Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_NORMAL_MODE_TEXT    , "Normal Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_LOUDSP_MODE_TEXT    , "LoudSp Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_HEADSET_MODE_TEXT    , "Headset Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_SET_MAX_SWING_TEXT    , "Max Swing", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_VOLUME_0_TEXT    , "Volume 0", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_VOLUME_1_TEXT    , "Volume 1", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_VOLUME_2_TEXT    , "Volume 2", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_VOLUME_3_TEXT    , "Volume 3", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_VOLUME_4_TEXT    , "Volume 4", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_VOLUME_5_TEXT    , "Volume 5", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_VOLUME_6_TEXT    , "Volume 6", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_FIR_0_TEXT , "FIR 0", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_FIR_1_TEXT , "FIR 1", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_FIR_2_TEXT , "FIR 2", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_FIR_3_TEXT , "FIR 3", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_FIR_4_TEXT , "FIR 4", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_FIR_5_TEXT , "FIR 5", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_DIRECT_APPLY_TEXT    , "Direct Apply", "Engineer Mode Menu Caption String");
	/* Speech Enhancement */
	ADD_APPLICATION_STRING2 (EM_AUD_SPEECH_ENHANCEMENT_TEXT , "Speech Enhancement", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_COMMON_PARAMETERS_TEXT , "Common Parameters", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_BT_EARPHONE_MODE_TEXT , "BT Earphone Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_BT_CORDLESS_MODE_TEXT , "BT Cordless Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_AUX1_MODE_TEXT , "AUX1 Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_AUX2_MODE_TEXT , "AUX2 Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_AUX3_MODE_TEXT , "AUX3 Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_0_TEXT , "Parameter 0", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_1_TEXT , "Parameter 1", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_2_TEXT , "Parameter 2", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_3_TEXT , "Parameter 3", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_4_TEXT , "Parameter 4", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_5_TEXT , "Parameter 5", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_6_TEXT , "Parameter 6", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_7_TEXT , "Parameter 7", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_8_TEXT , "Parameter 8", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_9_TEXT , "Parameter 9", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_10_TEXT , "Parameter 10", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_PARAMETER_11_TEXT , "Parameter 11", "Engineer Mode Menu Caption String");
    /* 16 Level Linear Volume */
    ADD_APPLICATION_STRING2 (EM_AUD_16_LELVEL_VOLUME_TEXT , "16 Level Setting", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_AUD_16_LELVEL_MAX_GAIN_TEXT , "Max Analog Gain", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_AUD_16_LELVEL_STEP_TEXT , "Step", "Engineer Mode Menu Caption String");    

    /* AUD TV OUT */    
#if defined(TV_OUT_SUPPORT)
    ADD_APPLICATION_STRING2 (EM_AUD_TV_OUT_TEXT , "TV OUT", "Engineer Mode Menu Caption String");
#endif    
    /* Debug Info */
    ADD_APPLICATION_STRING2 (EM_AUD_DEBUG_INFO_TEXT , "Debug Info", "Engineer Mode Menu Caption String");

    /* Voice Memo */    
    ADD_APPLICATION_STRING2 (EM_AUD_AUTO_VM_SETTING_TEXT , "Auto Record Setting", "Engineer Mode Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_AUD_VM_SUPPORT_TEXT , "VM Support", "Engineer Mode Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_AUD_AUTO_VM_TEXT , "Auto Speech Record", "Engineer Mode Menu Caption String");    


    /******************** GPRS ACt *******************/	
	ADD_APPLICATION_STRING2 (EM_GPRS_ACT_TEXT	, "GPRS Act", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_AUTO_ATTACH_TEXT      , "Attach", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_1st_PDP_TEXT  , "1st PDP", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_2nd_PDP_TEXT  , "2nd PDP", "Engineer Mode Menu Caption String");

	ADD_APPLICATION_STRING2 (EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY_TEXT  , "As Primary", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_ACTIVATE_2ND_PDP_SECOND_TEXT  , "As Secondary", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_GPRS_ACTIVATE_PDP_TEXT      , "Activate PDP", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_DEACTIVATE_PDP_TEXT      , "Deactivate PDP", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_SEND_DATA_NORM_TEXT      , "Send Norm Data", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_SEND_DATA_HDR_TEXT      , "Send RLC Data", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_SEND_DATA_TEXT      , "Send Data", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PING_TEXT      , "PING", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PINGIP_TEXT      , "IP Addr:", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PINGSIZE_TEXT      , "Size:", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PINGCOUNT_TEXT      , "Count:", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PINGTIMEOUT_TEXT      , "Timeout:", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_1_TEXT      , "PDP Context 1", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_2_TEXT      , "PDP Context 2", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_3_TEXT      , "PDP Context 3", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_4_TEXT      , "PDP Context 4", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_5_TEXT      , "PDP Context 5", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_6_TEXT      , "PDP Context 6", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_7_TEXT      , "PDP Context 7", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_8_TEXT      , "PDP Context 8", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_9_TEXT      , "PDP Context 9", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_10_TEXT      , "PDP Context 10", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_11_TEXT      , "PDP Context 11", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_12_TEXT      , "PDP Context 12", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_13_TEXT      , "PDP Context 13", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_14_TEXT      , "PDP Context 14", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_15_TEXT      , "PDP Context 15", "Engineer Mode Menu Caption String");
#ifdef __R99__	   
       ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_30_TEXT	  , "PDP Context 30", "Engineer Mode Menu Caption String");
       ADD_APPLICATION_STRING2 (EM_GPRS_PDP_CONTEXT_31_TEXT	  , "PDP Context 31", "Engineer Mode Menu Caption String");	
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__)*/

#endif


    /******************** Band Sel *******************/	
	ADD_APPLICATION_STRING2 (EM_BAND_SEL_TEXT	, "GSM Band Sel.", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_BAND_900_TEXT      , "900 Band", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_BAND_1800_TEXT      , "1800 Band", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_BAND_DUAL_TEXT      , "Dual Band", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_BAND_1900_TEXT      , "1900 Band", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_BAND_850_TEXT      , "850 Band", "Engineer Mode Menu Caption String");
	//ADD_APPLICATION_STRING2 (EM_BAND_AUTO_TEXT      , "Auto", "Engineer Mode Menu Caption String");


    /********************** Misc *********************/	
	ADD_APPLICATION_STRING2 (EM_MISC_TEXT      , "Misc.", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUTO_ANSWER_TEXT      , "Auto Answer", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_HIGHSPEED_SIM_MENUID_TEXT      , "High Speed SIM", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_BACKLIGHT_TEXT      , "Backlight Mode", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SERIAL_PORT_EN_TEXT      , "Serial Port Enable", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUTO_RESET_TEXT     , "Assert Testing", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_MMI_DEBUG_TEXT, "MMI Debug", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_MEMORY_DUMP_TEXT, "Memory Dump", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_RAM_TEST_TEXT, "RAM Test", "Engineer Mode Menu Caption String");
    /* Cell Reselection */
	ADD_APPLICATION_STRING2 (EM_MISC_CELL_RESELECT_TEXT, "Cell Reselection", "Engineer Mode Menu Caption String"); 
	ADD_APPLICATION_STRING2 (EM_MISC_CELL_RESELECT_SUSPEND_TEXT, "Resume", "Engineer Mode Menu Caption String"); 
	ADD_APPLICATION_STRING2 (EM_MISC_CELL_RESELECT_RESUME_IN_TRANSFER_TEXT, "Suspend(Trans. State)", "Engineer Mode Menu Caption String"); 
	ADD_APPLICATION_STRING2 (EM_MISC_CELL_RESELECT_RESUME_IN_ALL_TEXT, "Suspend(All State)", "Engineer Mode Menu Caption String"); 	

#if defined(__MMI_EM_FIXED_GAIN_FOR_HELIOS2__)
	ADD_APPLICATION_STRING2 (EM_MISC_FIXED_GAIN_FOR_HELIOS2_TEXT, "Fixed Gain For Helios2", "Engineer Mode Menu Caption String"); 	
#endif /* __MMI_EM_FIXED_GAIN_FOR_HELIOS2__ */

#if defined(__MMI_EM_MT6223_DEBUG_MODE__)
    /* MT6223 Debug Mode */
	ADD_APPLICATION_STRING2(EM_MISC_MT6223_DEBUG_MODE_TEXT, "MT6223 Debug Mode", "Engineer Mode Menu Caption String"); 	
	ADD_APPLICATION_STRING2(EM_MISC_MT6223_DEBUG_NORMAL_MODE_TEXT, "Normal Mode", "Engineer Mode Menu Caption String"); 	
	ADD_APPLICATION_STRING2(EM_MISC_MT6223_DEBUG_ICE_TASK_MODE_TEXT, "ICE&Task ID Mode", "Engineer Mode Menu Caption String"); 	    
	ADD_APPLICATION_STRING2(EM_MISC_MT6223_DEBUG_SWDBG_MODE_TEXT, "SWDBG Mode", "Engineer Mode Menu Caption String"); 	
#endif /* __MMI_EM_MT6223_DEBUG_MODE__ */

    /* Cascade Menu */
#if defined(__MMI_CASCADE_MENU__)
    ADD_APPLICATION_STRING2(STR_ID_EM_MISC_CASCADE_MENU, "Cascade Menu Test", "Engineer Mode Cascading Menu Test");	
#endif /* defined(__MMI_CASCADE_MENU__) */

/* LSD Slower */
#if defined(MT6223P)
	ADD_APPLICATION_STRING2(EM_MISC_LSD_SLOWER_TEXT, "LSD Slower", "Engineer Mode Menu Caption String"); 	
	ADD_APPLICATION_STRING2(EM_MISC_LSD_SLOWER_TICKS_TEXT, "LSD Ticks(0-6)", "Engineer Mode Menu Caption String"); 	
#endif

    /* Frame Profiling */
    #ifdef __MMI_INTERACTIVE_PROFILNG__
    ADD_APPLICATION_STRING2 (EM_FRM_PROFILING_TEXT, "Frame Profiling", "Engineer Mode Menu Caption String");
    #endif
    
#ifdef __MMI_UI_BENCHMARK__
    ADD_APPLICATION_STRING2 (EM_UI_BENCHMARK_TEXT, "UI Benchmark", "Engineer Mode Menu Caption String");
#endif 
    ADD_APPLICATION_STRING2 (EM_GLOBAL_PROCESSING_TEXT, "Processing...", "Engineer Mode Menu Caption String");

	#if defined(__MMI_VIDEO_RECORDER__) && defined(ISP_SUPPORT)
		ADD_APPLICATION_STRING2 (EM_VIDEO_HI_BITRATE_TEXT, "Video High Bitrate", "Engineer Mode Menu Caption String");
	#endif /* __MMI_VIDEO_RECORDER__  && ISP_SUPPORT */

	ADD_APPLICATION_STRING2 (EM_AMR_TEXT	, "AMR", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_WAP_TEXT      , "WAP", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_WAP_ENABLE_DEBUG_TEXT      , "Assert for Debug", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_WAP_OFFLINE_PAGE_TEXT      , "Offline Page", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_TEXT      , "User Agent", "Engineer Mode Menu Caption String");

    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_MAUI_E800_TEXT      , "MAUI E800", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_NOKIA_N72_TEXT      , "Nokia N72", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_NOKIA_E70_TEXT      , "Nokia E70", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_NOKIA_N93_TEXT      , "Nokia N93", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_NOKIA_6680_TEXT      , "Nokia 6680", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_NOKIA_6280_TEXT      , "Nokia 6280", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_NOKIA_3230_TEXT      , "Nokia 3230", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_NOKIA_6230_TEXT      , "Nokia 6230", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_SE_W900I_TEXT      , "SE W900i", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_SE_W800I_TEXT      , "SE W800i", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_SE_K700i_TEXT      , "SE K700i", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_SE_Z800_TEXT      , "SE Z800", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_SAMSUNG_D608_TEXT      , "Samsung D608", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_USER_AGENT_MOTO_E1070_TEXT      , "Moto E1070", "Engineer Mode Menu Caption String");	

    ADD_APPLICATION_STRING2 (EM_WAP_ACCEPT_HEADER_TEXT      , "Accept Header", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_WAP_ACCEPT_HEADER_WAP121_TEXT      , "WAP 1.2.1", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_ACCEPT_HEADER_WAP20_TEXT      , "WAP 2.0", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_ACCEPT_HEADER_WML_TEXT      , "WML", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_ACCEPT_HEADER_XHTML_TEXT      , "XHTML", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_ACCEPT_HEADER_HTML_TEXT      , "HTML", "Engineer Mode Menu Caption String");	
	ADD_APPLICATION_STRING2 (EM_WAP_MMS_VERSION_TEXT       , "MMS Version", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_MMS_VERSION_MMS_DEFAULT_TEXT       , "MMS Default", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_MMS_VERSION_MMS10_TEXT       , "MMS 1.0", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_MMS_VERSION_MMS11_TEXT       , "MMS 1.1", "Engineer Mode Menu Caption String");	
    ADD_APPLICATION_STRING2 (EM_WAP_MMS_VERSION_MMS12_TEXT       , "MMS 1.2", "Engineer Mode Menu Caption String");	
    /* J2ME */
	ADD_APPLICATION_STRING2 (EM_J2ME_TCK_TEXT      , "J2ME TCK", "Engineer Mode Menu Caption String");

    /* Touch Screen */
#if defined(__MMI_TOUCH_SCREEN__)
	ADD_APPLICATION_STRING2 (EM_TOUCHSCREEN_TEXT,"Touch Screen", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_TOUCHSCREEN_TEST_TEXT, "Test","Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_TOUCHSCREEN_TEST_STATISTICS_TEXT, "Statistics","Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_TOUCHSCREEN_TEST_EXIT_TEXT, "Exit","Engineer Mode Menu Caption String");
#endif
    /* PWR Duration */
	ADD_APPLICATION_STRING2 (EM_POWER_ON_DURATION_TEXT      , "PWR Duration", "Engineer Mode Menu Caption String");


    /***************** Auto Test List ****************/	
	ADD_APPLICATION_STRING2 (EM_AUTO_TEST_SETTING_TEXT      , "Auto Test List", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUTO_TEST_OPTIONS_TEXT      , "Options", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUTO_TEST_ADD_TEXT      , "Add From List", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUTO_TEST_CHANGE_PRIORITY_TEXT      , "Change Priority", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUTO_TEST_ENTER_PRIORITY_TEXT      , "Enter Priority", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUTO_TEST_REMOVE_TEXT      , "Remove", "Engineer Mode Menu Caption String");


    /**************** PWR Down Control ***************/	
    ADD_APPLICATION_STRING2 (EM_PWR_DOWN_CONTROL_TEXT, "PWR Down Control", "Engineer Mode Menu Caption String");
    
    
    /******************** SW Patch *******************/	
    ADD_APPLICATION_STRING2 (EM_STR_SW_PATCH_DSP, "DSP Patch", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_SW_PATCH_TEXT, "SW PATCH SELECT", "Engineer Mode Menu Caption String");


    /******************* Debug Info ******************/	
    ADD_APPLICATION_STRING2 (STR_ID_EM_DEBUG_INFO, "Debug Info", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (STR_ID_EM_SYS_STATS, "System Stats", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (STR_ID_EM_WRITE_SYS_STATS, "Write Stats", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (STR_ID_EM_SAVING_STAT_PWROFF, "PWROFF Saving Stats", "Engineer Mode Menu Caption String");
       
#if defined(__FS_TRACE_SUPPORT__)  
    ADD_APPLICATION_STRING2 (STR_ID_EM_FS_TRACE, "FS trace", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (STR_ID_EM_FS_TRACE_ALL_OFF, "ALL OFF", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (STR_ID_EM_FS_TRACE_ALL_ERROR, "ALL Error", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (STR_ID_EM_FS_TRACE_ALL_API_ERROR, "ALL API + Error", "Engineer Mode Menu Caption String");    
#endif 

    ADD_APPLICATION_STRING2 (STR_ID_EM_LAST_EXCEPTION, "Last Exception", "Engineer Mode Menu Caption String");


    /******************* Socket Test *****************/	    
#ifdef __TCPIP__  
	ADD_APPLICATION_STRING2 (EM_SOCKET_TEXT, "Socket Test", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_DNS_TEXT, "DNS Query", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_HTTP_TEXT, "HTTP Get", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ECHO_TEXT, "ECHO", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_DATE_TEXT, "Date Query", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_TRACERT_TEXT, "TraceRt", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_TRACERT_START_TEXT, "Tracing route to ", "Engineer Mode Menu Caption String");

	ADD_APPLICATION_STRING2 (EM_SOCKET_DNS_DOMAIN_NAME_TEXT, "Domain Name", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_HTTP_URL_TEXT, "HTTP URL", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ECHO_SERVER_IP_TEXT, "Server IP", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ECHO_STRING_TEXT, "Echo String", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_TRACERT_REMOTE_IP_TEXT, "Remote IP", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_IN_PROGRESS_TEXT, "In Progress", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_RESULT_TEXT, "Result", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_INVAL_PARA_TEXT, "Invalid Input", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_PEER_NOT_REACHABLE_TEXT, "Peer Not Reachable", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_PEER_NO_RESPONSE_TEXT, "Peer No Response", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_CNT_RESET_BY_PEER_TEXT, "Connection Reset By Peer", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_BEARER_FAIL_TEXT, "Bearer Failed", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_UNKNOWN_APP_TEXT, "Unknown Application", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_BUSY_TEXT, "Busy Socket ", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_SOCKET_ERROR_NO_MEMORY_TEXT, "No Memory", "Engineer Mode Menu Caption String");

    /* BEGIN OF IPERF */
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_STR, "Iperf", "Engineer Mode Iperf Menu String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_IPERF_SETTING_STR, "Iperf Setting", "Engineer Mode Iperf Menu Title String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_TCP_TESTING_STR, "TCP Testng", "Iperf Menu TCP Testing String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_UDP_TESTING_STR, "UDP Testng", "Iperf Menu UDP Testing String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_TCP_SETTING_STR, "TCP Settng", "Iperf Menu TCP Setting Title String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_UDP_SETTING_STR, "UDP Settng", "Iperf Menu UDP Setting Title String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_DATA_ACCOUNT_STR, "Data Account", "Iperf Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_CLIENT_SERVER_STR, "Client/Server", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_RW_FILE_STR, "R/W File", "Read Write file for benchmarking");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_CLIENT_STR, "Client", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_SERVER_STR, "Server", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_FADDR_STR, "Faddr", "Iperf Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_LEN_STR, "Len", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_PORT_STR, "Port", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_WINDOW_STR, "Window", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_BUFFER_STR, "Buffer", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_MSS_STR, "MSS", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_BANDWIDTH_STR, "Bandwidth (Kbps)", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_NUM_BYTES_STR, "Num(Bytes)", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_TIME_SECS_STR, "Time(Secs)", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_TOS_STR, "ToS", "Iperf Menu Caption String");        
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_DUAL_STR, "Dual Test", "Iperf Menu Caption String");        
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_BEST_EFFORT_STR, "BEST_EFFORT", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_BACK_GROUND_STR, "BACK_GROUND", "Iperf Menu Caption String");        
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_VIDEO_STR, "VIDEO", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_VOICE_STR, "VOICE", "Iperf Menu Caption String");    
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_RUN_STR, "Run Iperf", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_LEN_ERR_STR, "Invalid Length", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_PORT_ERR_STR, "Invalid Port", "Iperf Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_WINDOW_ERR_STR, "Invalid Window", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_BUFFER_ERR_STR, "Invalid Buffer", "Iperf Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_MSS_ERR_STR, "Invalid MSS", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_BANDWIDTH_ERR_STR, "Invalid Bandwidth", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_NUM_BYTES_ERR_STR, "Invalid Num(Bytes)", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_TIME_SECS_ERR_STR, "Invalid Num(Bytes)", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_FADDR_ERR_STR, "Invalid Faddr", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_SERVER_DUAL_ERR_STR, "Not Support Server Dual Mode Testing", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_CNF_FAILED_ERR_STR, "Confirm Failed", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_PROGRESSING_STR, "Progressing", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_REPORT_STR, "Iperf Report", "Iperf Menu Caption String");   
    ADD_APPLICATION_STRING2 (EM_SOCKET_IPERF_TEST_FAILED_ERR_STR, "Test Failed", "Iperf Menu Caption String");   
    /* END 0F IPERF */
#endif /* TCPIP */


    /******************** Bluetooth ******************/
#if defined(__MMI_BT_SUPPORT__)
    ADD_APPLICATION_STRING2 (EM_BT_STR_ID, "Bluetooth", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_BT_ENTRY_TEST_STR_ID, "Start Testing", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_BT_DEBUG_TRACE_STR_ID, "Debug Trace", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_BT_ADD_AUDIO_CONNECTION_STR_ID, "Add Audio Conn", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_BT_REMOVE_AUDIO_CONNECTION_STR_ID, "Remove Audio Conn", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_BT_LOOKBACK_STR_ID, "Far End Lookback", "Engineer Mode Menu Caption String");       
    ADD_APPLICATION_STRING2 (EM_BT_BD_ADDR_STR_ID, "BD Address", "Engineer Mode Menu Caption String");       
    ADD_APPLICATION_STRING2 (EM_BT_BD_PASSWORD_STR_ID, "BD Password", "Engineer Mode Menu Caption String");           
#if defined(__MMI_BT_MTK_SUPPORT__)
    ADD_APPLICATION_STRING2 (EM_BT_EXIT_TEST_MODE_STR_ID, "Exit Test Mode", "Engineer Mode Menu Caption String");           
#endif /* defined(__MMI_BT_MTK_SUPPORT__) */
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
    ADD_APPLICATION_STRING2 (EM_BT_AVRCP_CMD_LIST_STR_ID, "AVRCP Command", "Engineer Mode Menu Caption String");
#endif


#ifdef __MMI_BT_MTK_SUPPORT__
#define __MMI_EM_BT_GET_CHIP_VERION__
#endif /* #ifdef __MMI_BT_MTK_SUPPORT__ */

#ifdef __MMI_EM_BT_GET_CHIP_VERION__
    ADD_APPLICATION_STRING2 (EM_BT_GENERNAL_TEST_STR_ID, "Genernal Test", "Engineer Mode Menu Caption String");
    ADD_APPLICATION_STRING2 (EM_BT_GET_CHIP_VERSION_STR_ID, "Get Chip Version", "Engineer Mode Menu Caption String");
#endif /* #ifdef __MMI_EM_BT_GET_CHIP_VERION__ */

#endif


    /******************** Profiling ******************/	
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING, "Profiling",	"Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (EM_PROFILING_DISPLAY_TIME_TEXT, "Display Time", "Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (EM_PROFILING_GDI_PROFILE_TEXT, "GDI Image Profile", "Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (EM_PROFILING_SCREEN_DELAY_TEXT, "Screen Delay (ms)", "Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (EM_PROFILING_MATRIX_DELAY_TEXT, "Matrix Delay (ms)", "Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (EM_PROFILING_LIST_DELAY_TEXT, "List Delay (ms)", "Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (EM_PROFILING_DELAY_OFFSET_TEXT,  "Time Offset (ms)", "Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_MULTIMEDIA, "Multimedia",	"Engineer Mode Profiling");

#if defined(__MMI_CAMERA__) && defined(__MMI_VIDEO_RECORDER__)	
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_AUTO_PLAY, "Auto Play Files",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_VDOREC, "Video Recorder",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_VDOPLY, "Video Player",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_CAMERA, "Camera",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_START, "Start",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SETTING, "Setting",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_EXTRA_LAYER, "Extra Layer",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_ROTATE, "Rotate",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_TV_OUT_MODE, "TV-Out Mode",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_RECORD_SIZE, "Record Size",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_PREVIEW_SIZE, "Preview Size",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_PLAY_SIZE, "Play Size",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_ROTATE_0, "Rotate 0",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_ROTATE_90, "Rotate 90",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_ROTATE_180, "Rotate 180",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_ROTATE_270, "Rotate 270",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_TV_FULL_SCREEN, "Full Screen",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_TV_LCD_SCREEN, "LCD Screen",	"Engineer Mode Profiling");	
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SIZE_SQCIF, "SQCIF (128x96)",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SIZE_QCIF, "QCIF (176x144)",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SIZE_CIF, "CIF (352x288)",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SIZE_QQVGA, "QQVGA (160x120)",	"Engineer Mode Profiling");
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SIZE_QVGA, "QQVGA (320x240)",	"Engineer Mode Profiling");	
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SIZE_VGA, "QQVGA (640x480)",	"Engineer Mode Profiling");	
	ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SIZE_LCD, "LCD Size",	"Engineer Mode Profiling");		
#endif /* __MMI_CAMERA__ && __MMI_VIDEO_RECORDER__ */

#ifdef __MMI_IMG_DEC_PROFILING__   
    ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_IMAGE_DECODE, "Image Decode",	"Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SINGLE_FOLDER, "Single Folder",	"Engineer Mode Profiling");
    ADD_APPLICATION_STRING2 (STR_ID_EM_PROFILING_SINGLE_FOLDER_ROTATE, "Single Folder(ROTATE)",	"Engineer Mode Profiling");
#endif /* __MMI_IMG_DEC_PROFILING__ */    

    /********************* RF Tool *******************/	
#if defined(__FLIGHT_MODE_SUPPORT__) || defined(__WIFI_SUPPORT__)
    /* RF Test Tool */
    ADD_APPLICATION_STRING2 (EM_RF_TEST_TOOL_TEXT, "RF Test Tool", "Engineer Mode RF Test Tool Menu Caption String");       
#endif 

    /* change to global usage. */
    ADD_APPLICATION_STRING2 (EM_RF_TEST_GSM_CONFIRM_NOTIFY_TEST,  "After test, MS will power off!!", "Engineer Mode RF Test GSM Menu Caption String");              
#if defined(__FLIGHT_MODE_SUPPORT__)
    /* GSM */
    ADD_APPLICATION_STRING2 (EM_RF_TEST_GSM_TEST,  "GSM", "Engineer Mode RF Test GSM Menu Caption String");              
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_TEST_TEXT,  "TX Test", "Engineer Mode RF Test GSM TX Text Menu Caption String");                     
    ADD_APPLICATION_STRING2 (EM_RF_GSM_RX_TEST_TEXT,  "RX Test", "Engineer Mode RF Test GSM RX Text Menu Caption String");                     
    ADD_APPLICATION_STRING2 (EM_RF_GSM_POWER_SCAN_TEXT,  "Power Scan", "Engineer Mode RF Test GSM Power Scan Menu Caption String");                     
    /* GSM -- Band */
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BAND_TEXT,  "Band", "Engineer Mode RF Test GSM Test String");                     
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BAND_GSM850_TEXT,  "GSM850", "Engineer Mode RF Test GSM Test String");                    
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BAND_GSM900_TEXT,  "GSM900", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BAND_DCS1800_TEXT,  "DCS1800", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BAND_PCS1900_TEXT,  "PCS1900", "Engineer Mode RF Test GSM Test String");  
    /* GSM -- ARFCN , TSC, PCL, AFC */
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_ARFCN_TEXT,  "ARFCN", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_TSC_TEXT,  "TSC", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_PCL_TEXT,  "PCL", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_AFC_TEXT,  "AFC", "Engineer Mode RF Test GSM Test String");  
    /* GSM -- TX Burst Type */
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_TYPE_TEXT,  "Burst Type", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_NB_TEXT,  "NB", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_NBALL_TEXT,  "NB-All 1", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_AB_TEXT,  "AB", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_CONTTX00_TEXT,  "Cont. TX-0000", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_CONTTX11_TEXT,  "Cont. TX-1111", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_CONTTX01_TEXT,  "Cont. TX-0101", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_BURST_CONTTX_RANDOM_TEXT,  "Cont. TX-Random", "Engineer Mode RF Test GSM Test String");  
    /* GSM -- Gain */
    ADD_APPLICATION_STRING2 (EM_RF_GSM_TX_GAIN_TEXT,  "Gain", "Engineer Mode RF Test GSM Test String");  
    /* GSM -- RX Burst Type */
    ADD_APPLICATION_STRING2 (EM_RF_GSM_RX_BURST_CONT_RX_TEXT,  "Continue RX", "Engineer Mode RF Test GSM Test String");  
    ADD_APPLICATION_STRING2 (EM_RF_GSM_RX_BURST_BURST_RX_TEXT,  "Burst RX", "Engineer Mode RF Test GSM Test String");  
#endif /* #if defined(__FLIGHT_MODE_SUPPORT__)  */

#if defined(__WIFI_SUPPORT__)
       /* WiFi */
       ADD_APPLICATION_STRING2 (EM_RF_TEST_WIFI_TEST,  "WiFi", "Engineer Mode RF Test WiFi Menu Caption String");              
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_TESTS_TEXT,  "TX Tests", "Engineer Mode RF Test WiFi TX Tests Menu Caption String");                     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_CONT_PKT_RX_TEXT,  "Cont PKT RX", "Engineer Mode RF Test WiFi PKT RX Menu Caption String");                     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_POWER_SAVE_TEXT,  "Power Save", "Engineer Mode RF Test WiFi Power Save Menu Caption String");                     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_TEXT,  "Register Access", "Engineer Mode RF Test WiFi Register Access Menu Caption String");                             
       /* WiFi TX */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_DAC_OFFSET_TEXT,  "TX DAC Offset", "Engineer Mode RF Test WiFi TX DAC Menu Caption String");                     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_OUTPUT_POWER_TEXT,  "TX Output Power", "Engineer Mode RF Test WiFi TX Output Power Menu Caption String");                     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CARRIER_SUPP_TEXT,  "TX Carrier Supp", "Engineer Mode RF Test WiFi TX Carrier Supp Menu Caption String");                     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_LOCAL_FREQUENCY_TEXT,  "Local Frequency", "Engineer Mode RF Test WiFi TX Local Freq. Menu Caption String");                     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CONT_PKT_TX_TEXT,  "Cont PKT TX", "Engineer Mode RF Test WiFi TX Cont PKT Menu Caption String");                            
       /* WiFi TX -- Domain */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_DOMAIN_TEXT,  "Domain", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_DOMAIN_US_TEXT,  "US", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_DOMAIN_JP_TEXT,  "JP", "Engineer Mode RF Test WiFi TX Caption String");                            
       /* WiFi TX -- Channel Freq. */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_TEXT,  "CH Freq (KHz)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_1_TEXT,  "2412000 (1)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_2_TEXT,  "2417000 (2)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_3_TEXT,  "2422000 (3)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_4_TEXT,  "2427000 (4)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_5_TEXT,  "2432000 (5)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_6_TEXT,  "2437000 (6)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_7_TEXT,  "2442000 (7)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_8_TEXT,  "2447000 (8)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_9_TEXT,  "2452000 (9)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_10_TEXT,  "2457000 (10)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_11_TEXT,  "2462000 (11)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_12_TEXT,  "2467000 (12)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_13_TEXT,  "2472000 (13)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_CH_FREQ_14_TEXT,  "2484000 (14)", "Engineer Mode RF Test WiFi TX Caption String");                            
       /* WiFi TX -- TX Rate */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_TEXT,  "TX Rate", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_1_TEXT,  "1M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_2_TEXT,  "2M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_3_TEXT,  "5.5M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_4_TEXT,  "11M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_5_TEXT,  "6M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_6_TEXT,  "9M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_7_TEXT,  "12M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_8_TEXT,  "18M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_9_TEXT,  "24M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_10_TEXT,  "36M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_11_TEXT,  "48M", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_RATE_12_TEXT,  "54M", "Engineer Mode RF Test WiFi TX Caption String");                            
       /* WiFi TX -- TX Ant, Gain, pkt Count, pkt Interval, pkt Length */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_ANT_TEXT,  "TX Ant", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_GAIN_TEXT,  "Gain (Hex)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PKT_COUNT_TEXT,  "PKT Count", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PKT_INTERVAL_TEXT,  "PKT Interval (us)", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PKT_LENGTH_TEXT,  "PKT Length (Byte)", "Engineer Mode RF Test WiFi TX Caption String");                            
       /* WiFi TX -- TX Pattern */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PATTERN_TEXT,  "TX Pattern", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PATTERN_ALL_0_TEXT,  "All 0", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PATTERN_ALL_1_TEXT,  "All 1", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PATTERN_ALTER_BITS_TEXT,  "Alter bits", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_PATTERN_RANDOM_TEXT,  "Random", "Engineer Mode RF Test WiFi TX Caption String");                            
       /* WiFi TX -- Short Peramble */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_SHORT_PERAMBLE_TEXT,  "Short Peramble", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_SHORT_PERAMBLE_TRUE_TEXT,  "TRUE", "Engineer Mode RF Test WiFi TX Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_SHORT_PERAMBLE_FALSE_TEXT,  "FALSE", "Engineer Mode RF Test WiFi TX Caption String");                                   
       /* WiFi TX -- MAC Header */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_TX_MAC_HEADER_TEXT,  "MAC Header (Hex)", "Engineer Mode RF Test WiFi TX Caption String");                            
       /* WiFi Power Save -- Mode */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_POWER_SAVE_MODE_TEXT,  "Mode", "Engineer Mode RF Test WiFi Power Save Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_POWER_SAVE_NORMAL_TEXT,  "Normal", "Engineer Mode RF Test WiFi Power Save Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_POWER_SAVE_IDLE_TEXT,  "Idle", "Engineer Mode RF Test WiFi Power Save Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_POWER_SAVE_SLEEP_TEXT,  "Sleep", "Engineer Mode RF Test WiFi Power Save Caption String");                            
       /* WiFi Register */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_MCR_TEXT,  "MCR", "Engineer Mode RF Test WiFi Register MCR Menu Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_BBCR_TEXT,  "BBCR", "Engineer Mode RF Test WiFi Register BBCR Menu Caption String");                            
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_EEPROM_TEXT,  "EEPROM", "Engineer Mode RF Test WiFi Register EEPROM Menu Caption String");                            
       /* WiFi Register -- Type */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_TYPE_TEXT,  "Type", "Engineer Mode RF Test WiFi Caption String");     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_16_TEXT,  "16", "Engineer Mode RF Test WiFi Caption String");     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_32_TEXT,  "32", "Engineer Mode RF Test WiFi Caption String");     
       /* WiFI Register -- Access */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_ACCESS_TEXT,  "Access", "Engineer Mode RF Test WiFi Caption String");     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_READ_TEXT,  "Read", "Engineer Mode RF Test WiFi Caption String");     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_WRITE_TEXT,  "Write", "Engineer Mode RF Test WiFi Caption String");            
       /* WiFi Register -- Address, index, data */
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_ADDRESS_TEXT,  "Address(Hex)", "Engineer Mode RF Test WiFi Caption String");     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_INDEX_TEXT,  "Index (Hex)", "Engineer Mode RF Test WiFi Caption String");     
       ADD_APPLICATION_STRING2 (EM_RF_WIFI_REGISTER_DATA_TEXT,  "Data (Hex)", "Engineer Mode RF Test WiFi Caption String");     

#endif   #if defined(__WIFI_SUPPORT__)

    /********************** VOIP *********************/	
#if defined(__VOIP__)
	ADD_APPLICATION_STRING2 (EM_VOIP_TEXT, "VOIP",	"Engineer Mode VOIP");		
	ADD_APPLICATION_STRING2 (EM_VOIP_P2P_CALL_TEXT, "P2P Call",	"Engineer Mode VOIP");		
	ADD_APPLICATION_STRING2 (EM_VOIP_REREGISTER_TIMER_TEXT, "Re-register Timer",	"Engineer Mode VOIP");		
	ADD_APPLICATION_STRING2 (EM_VOIP_CALL_REFRESH_TIMER_TEXT, "Call Refresh Timer",	"Engineer Mode VOIP");		
	ADD_APPLICATION_STRING2 (EM_VOIP_REFER_SUB_TIMER_TEXT, "Refer Sub Timer",	"Engineer Mode VOIP");		
	ADD_APPLICATION_STRING2 (EM_VOIP_MWI_SUB_TIMER_TEXT, "MWI Sub Timer",	"Engineer Mode VOIP");		
	ADD_APPLICATION_STRING2 (EM_VOIP_MWI_RETRY_TIME_TEXT, "MWI Retry Time",	"Engineer Mode VOIP");			
	ADD_APPLICATION_STRING2 (EM_VOIP_SETTINGS_TEXT, "Settings",	"Engineer Mode VOIP");			
	ADD_APPLICATION_STRING2 (EM_VOIP_SIP_SUPPORTED_TEXT, "SIP Supported",	"Engineer Mode VOIP");			
	ADD_APPLICATION_STRING2 (EM_VOIP_SIP_REQUIRE_TEXT, "SIP Require",	"Engineer Mode VOIP");				

	ADD_APPLICATION_STRING2 (EM_VOIP_UAS_Refresher_TEXT, "UAS Refresher",	"Engineer Mode Menu Caption String")
	ADD_APPLICATION_STRING2 (EM_VOIP_UAC_Refresher_TEXT, "UAC Refresher",	"Engineer Mode Menu Caption String")
	ADD_APPLICATION_STRING2 (EM_VOIP_UAS_TEXT, "UAS",	"Engineer Mode Menu Caption String")
	ADD_APPLICATION_STRING2 (EM_VOIP_UAC_TEXT, "UAC",	"Engineer Mode Menu Caption String")
	ADD_APPLICATION_STRING2 (EM_VOIP_RPORT_SUPPORT_TEXT, "RPort Support",	"Engineer Mode Menu Caption String")	
	ADD_APPLICATION_STRING2 (EM_VOIP_LOCAL_ADDR_TEXT, "Local Address",	"Engineer Mode Menu Caption String")		

    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_TEXT, "Log",   "Engineer Mode VOIP Log");
    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_CONTENT_TEXT, "Content",   "Engineer Mode vOIP Log Content");
    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_SETTINGS_TEXT, "Setting",  "VOIP Log Setting");
    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_AUTO_DELETE_TEXT, "Auto Delete",  "auto delete voip logs");
    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_DELETE_ALL_TEXT, "All",  "Delete all voip logs");
    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_DELETE_ONE_DAY_TEXT, "One Day",  "Delete all logs one day before");
    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_DELETE_HALF_MONTH_TEXT, "Half Month",  "Delete all logs half month before");
    ADD_APPLICATION_STRING2 (EM_VOIP_LOG_DELETE_ONE_MONTH_TEXT, "One Month",  "Delete all logs one month before");

#endif

    /********************* Common ********************/	
	ADD_APPLICATION_STRING2 (EM_SET_LSK_TEXT, "Set", "Engineer Mode Menu LSK String");
	//ADD_APPLICATION_STRING2 (EM_TOGGLE_LSK_TEXT, "On/Off", "Engineer Mode Menu LSK String");
	ADD_APPLICATION_STRING2 (EM_NOTICE_WARNING_TEXT	, "Warning", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NOTICE_SUCCESS_TEXT	, "Success", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_NOTICE_SUCCESS_REBOOT_TEXT, "Done.\nPoweroff in 3 sec", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_UPDATE_TITLE_TEXT   , "Update", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_UPDATE_QUERY_TEXT    , "Update Parameter?", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_UPDATE_ERROR_TEXT    , "Can't Update!!", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_UPDATE_SUCCESS_TEXT , "Parameter Updated!!", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_AUD_SET_SUCCESS_TEXT , "Successfully Set!!", "Engineer Mode Menu LSK String");
	ADD_APPLICATION_STRING2 (EM_AUD_SET_ERROR_TEXT , "Set Error!!", "Engineer Mode Menu LSK String");
	ADD_APPLICATION_STRING2 (EM_DEV_PWM_STOP_TEXT, "STOP", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_SLEEPMODE_ON_TEXT      , "Enable", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_SLEEPMODE_OFF_TEXT      , "Disable", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_DCMMODE_ON_TEXT      , "Enable", "Engineer Mode Menu Caption String");
	ADD_APPLICATION_STRING2 (EM_DEV_DCMMODE_OFF_TEXT      , "Disable", "Engineer Mode Menu Caption String");


    /*****************************************************************/
    /*****************************  Menus ****************************/
    /*****************************************************************/

    /******************* Main Menu *******************/
	ADD_APPLICATION_MENUITEM((ENGINEER_MODE_MENUID, IDLE_SCREEN_MENU_ID, MMI_EM_MENUCNT_NUM, 
   							EM_NETWORK_SETTING_MENUID,
   							EM_DEVICE_MENUID,
   							EM_AUDIO_MENUID,
   							EM_GPRS_ACT_MENUID,
   							EM_MISC_MENUID,		
   							EM_AUTO_TEST_SETTING_MENUID,
   							EM_PWR_DOWN_CONTROL_MENUID,
   							EM_SW_PATCH_MENUID,
   							EM_DEBUG_INFO_MENUID,
   						#ifdef __TCPIP__  
   							EM_SOCKET_MENUID,
   						#endif

                                                #if defined(__MMI_BT_SUPPORT__)
							EM_BT_MENUID,
						#endif			
						
							MENU_ID_EM_PROFILING,
                        #if defined(__FLIGHT_MODE_SUPPORT__) || defined(__WIFI_SUPPORT__)
                            EM_RF_TEST_TOOL_MENUID,
                        #endif                 
                        
                        #if defined(__VOIP__)
                            EM_VOIP_MENNUID,
                        #endif
						#if defined (__MMI_CSB_BROWSER__)
							CSB_MENUID,
						#endif
							SHOW, NONMOVEABLE, DISP_LIST,	ENGINEER_MODE_TEXT, ENGINEER_MODE_ICON));


    /***************** Network Info ******************/
    menu_item_count = 3;
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#endif 

#if defined(__EM_MODE__)
    menu_item_count++;  /* network events */
#endif

	ADD_APPLICATION_MENUITEM((EM_NETWORK_SETTING_MENUID, ENGINEER_MODE_MENUID, menu_item_count,
	                        EM_NETWORK_INFO_MENUID,
	                        EM_BAND_SEL_MENUID,
                        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)	                        
/* under construction !*/
	                    #endif
	                        EM_NETWORK_CELL_LOCK_MENUID,
	                    #if defined(__EM_MODE__)
    	                    EM_NETWORK_NETWORK_EVENT_MENUID,
    	                #endif
							SHOW, NONMOVEABLE, DISP_LIST, EM_NETWORK_SETTING_TEXT, EM_NETWORK_ICON));

	ADD_APPLICATION_MENUITEM((EM_NETWORK_INFO_MENUID, EM_NETWORK_SETTING_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_NETWORK_INFO_TEXT, EM_NETWORK_ICON));


#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */

	ADD_APPLICATION_MENUITEM((EM_NETWORK_CELL_LOCK_MENUID, EM_NETWORK_SETTING_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_NETWORK_CELL_LOCK_TEXT, 0));

#if defined(__EM_MODE__)
	ADD_APPLICATION_MENUITEM((EM_NETWORK_NETWORK_EVENT_MENUID, EM_NETWORK_SETTING_MENUID, 3, 
	                        EM_NETWORK_NW_EVENT_START_MENUID,
	                        EM_NETWORK_NW_EVENT_FILTER_MENUID,
	                        EM_NETWORK_NW_EVENT_SETTING_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_NET_NETWORK_EVENT_TEXT, 0));

	ADD_APPLICATION_MENUITEM((EM_NETWORK_NW_EVENT_START_MENUID, EM_NETWORK_NETWORK_EVENT_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_NET_NETWORK_EVENT_START_TEXT, 0));

	ADD_APPLICATION_MENUITEM((EM_NETWORK_NW_EVENT_FILTER_MENUID, EM_NETWORK_NETWORK_EVENT_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_NET_NETWORK_EVENT_FILTER_TEXT, 0));

	ADD_APPLICATION_MENUITEM((EM_NETWORK_NW_EVENT_SETTING_MENUID, EM_NETWORK_NETWORK_EVENT_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_NET_NETWORK_EVENT_SETTING_TEXT, 0));

#endif /* defined(__EM_MODE__) */

    /********************* Device ********************/
    menu_item_count = 9;
							
#ifdef __MMI_CLAMSHELL__
	menu_item_count++;
#endif

#ifdef CAMERA_MODULE
	menu_item_count++;
#endif

#if (defined(MT6229) || defined(MT6227) || defined(MT6228) || defined(MT6225) || defined(MT6268T) || defined(MT6230) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)) 
    menu_item_count++;
#endif

#if defined(NAND_SUPPORT) 
    menu_item_count++;
#endif

#if defined(MT6318)
    menu_item_count++;  // PMIC 6318
#endif

#if defined(__MMI_TVOUT__)
    menu_item_count++;
#endif

#ifdef __OTG_ENABLE__
    menu_item_count++;  
#endif

#if defined (DCM_ENABLE)
    menu_item_count++;
#endif

#ifdef __MMI_FM_RADIO__
    menu_item_count++;      /* FM Radio */
#endif    


	ADD_APPLICATION_MENUITEM((EM_DEVICE_MENUID, ENGINEER_MODE_MENUID, menu_item_count,
                             EM_DEV_LCD_MENU_ID,  
                             EM_DEV_GPIO_MENU_ID,  
                             EM_DEV_PWM_MENU_ID,  
                             EM_DEV_EINT_MENU_ID,  
                             EM_DEV_ADC_MENU_ID,  
                     
						 #ifdef __MMI_CLAMSHELL__
					         EM_DEV_CLAM_MENUID,
						 #endif /* __MMI_CLAMSHELL__ */	
						
					         EM_DEV_HW_LEVEL_MENUID,
                             EM_DEV_SET_UART_MENUID,
                             EM_DEV_SLEEPMODE_MENUID,    
                     
                         #if defined(DCM_ENABLE)
                             EM_DEV_DCMMODE_MENUID,
                         #endif                     
                     
	  					 #ifdef CAMERA_MODULE
                             EM_DEV_EXT_CAMERA_MENU_ID,           
						 #endif                     
						 #if (defined(MT6229) || defined(MT6227) || defined(MT6228) || defined(MT6225) || defined(MT6268T) || defined(MT6230) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)) 
                             EM_SWDBG_MENUID,
						 #endif                     
						
						 #if defined(NAND_SUPPORT) 
                             EM_NAND_FORMAT_MENUID,
						 #endif
						
						 #if defined(MT6318)
                             EM_DEV_PMIC_6318_MENU_ID,
						 #endif               

						 #ifdef __MMI_TVOUT__
						 	 EM_DEV_TVOUT_SETTING_MENUID,
						 #endif
						 
                         #ifdef __OTG_ENABLE__
  					         EM_DEVICE_USB_MENNUID,
                         #endif				
                         
                         #ifdef __MMI_FM_RADIO__                  
                             EM_DEVICE_FM_RADIO_MENU_ID,      /* FM Radio */
                         #endif
                             EM_DEVICE_RTC_XOSC_MENU_ID,      /* RTC XOSC */
							 SHOW, NONMOVEABLE, DISP_LIST,	EM_DEVICE_TEXT, EM_DEVICE_ICON));

   /* device */
#ifdef __MMI_SUBLCD__
    ADD_APPLICATION_MENUITEM((EM_DEV_LCD_MENU_ID, EM_DEVICE_MENUID, 2,
                            EM_DEV_LCD_MAIN_MENU_ID,
                            EM_DEV_LCD_SUB_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_TEXT, EM_DEV_LCD_ICON));
#else
    ADD_APPLICATION_MENUITEM((EM_DEV_LCD_MENU_ID, EM_DEVICE_MENUID, 1,
                            EM_DEV_LCD_MAIN_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_TEXT, EM_DEV_LCD_ICON));
#endif /* __MMI_SUBLCD__ */ 
   
    ADD_APPLICATION_MENUITEM((EM_DEV_GPIO_MENU_ID, EM_DEVICE_MENUID, 3,
                            EM_DEV_GPIO_LIST_MENU_ID,
                            EM_DEV_GPIO_SET_MENU_ID,
                            EM_DEV_GPO_SET_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_GPIO_TEXT, EM_DEV_GPIO_ICON));

#ifdef CAMERA_MODULE
    ADD_APPLICATION_MENUITEM((EM_DEV_EXT_CAMERA_MENU_ID, EM_DEVICE_MENUID, 2,
                            EM_DEV_EXT_CAMERA_WRITE_MENU_ID,
                            EM_DEV_EXT_CAMERA_READ_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_STR_EXT_CAMERA_TEXT,  EM_DEV_EXT_CAMERA_ICON));
#endif

    ADD_APPLICATION_MENUITEM((EM_DEV_PWM_MENU_ID, EM_DEVICE_MENUID, 3,
                            EM_DEV_PWM_SET_1_MENU_ID,
                            EM_DEV_PWM_SET_2_MENU_ID,
                            EM_DEV_PWM_SET_3_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_PWM_TEXT, EM_DEV_PWM_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_EINT_MENU_ID, EM_DEVICE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_EINT_TEXT, EM_DEV_EINT_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_ADC_MENU_ID, EM_DEVICE_MENUID, 0,
 							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_ADC_TEXT, EM_DEV_ADC_ICON));

#if defined(MT6318)
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_MENU_ID, EM_DEVICE_MENUID, 9,
                                  EM_DEV_PMIC_6318_REGISTER_EDITOR_MENU_ID,
                                  EM_DEV_PMIC_6318_CHARGER_STATUS_MENU_ID,
    						      EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID,
                                  EM_DEV_PMIC_6318_RGB_MENU_ID,
	                              EM_DEV_PMIC_6318_KP_LED_MENU_ID,
	   			                  EM_DEV_PMIC_6318_BL_LED_MENU_ID,
							      EM_DEV_PMIC_6318_AUDIO_MENU_ID,
							      EM_DEV_PMIC_6318_MISC_MENU_ID,
							      EM_DEV_PMIC_6318_LCM_BL_SETTING_MENU_ID,
							      SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_PMIC_6318_TEXT, EM_DEV_PMIC_6318_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_REGISTER_EDITOR_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_PMIC_6318_REGISTER_EDITOR_TEXT, EM_DEV_PMIC_6318_REGISTER_EDITOR_ICON));
 
    /* Charger Status */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_CHARGER_STATUS_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_CHARGER_STATUS_TEXT , 0));

    /* Set Charger */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 4,
			                EM_DEV_PMIC_6318_SET_CHARGER_CHREN_MENU_ID,
							EM_DEV_PMIC_6318_SET_CHARGER_AC_CURRENT_MENU_ID,
							EM_DEV_PMIC_6318_SET_CHARGER_USB_CHREN_MENU_ID,
						    EM_DEV_PMIC_6318_SET_CHARGER_USB_CURRENT_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_SET_CHARGER_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_SET_CHARGER_CHREN_MENU_ID, EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_SET_CHARGER_CHREN_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_SET_CHARGER_AC_CURRENT_MENU_ID, EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_SET_CHARGER_AC_CURRENT_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_SET_CHARGER_USB_CHREN_MENU_ID, EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_SET_CHARGER_USB_CHREN_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_SET_CHARGER_USB_CURRENT_MENU_ID, EM_DEV_PMIC_6318_SET_CHARGER_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_SET_CHARGER_USB_CURRENT_TEXT , 0));

    /* RGB LED */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_RGB_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 6,
   						    EM_DEV_PMIC_6318_RGB_R_MENU_ID,
						    EM_DEV_PMIC_6318_RGB_R_CURRENT_MENU_ID,
						    EM_DEV_PMIC_6318_RGB_G_MENU_ID,
						    EM_DEV_PMIC_6318_RGB_G_CURRENT_MENU_ID,
						    EM_DEV_PMIC_6318_RGB_B_MENU_ID,
						    EM_DEV_PMIC_6318_RGB_B_CURRENT_MENU_ID,
						    SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_RGB_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_RGB_R_MENU_ID, EM_DEV_PMIC_6318_RGB_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_R_LED_TEXT , 0));
 
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_RGB_R_CURRENT_MENU_ID, EM_DEV_PMIC_6318_RGB_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_R_LED_CURRENT_TEXT , 0));
   
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_RGB_G_MENU_ID, EM_DEV_PMIC_6318_RGB_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_G_LED_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_RGB_G_CURRENT_MENU_ID, EM_DEV_PMIC_6318_RGB_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_G_LED_CURRENT_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_RGB_B_MENU_ID, EM_DEV_PMIC_6318_RGB_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_B_LED_TEXT , 0));
   
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_RGB_B_CURRENT_MENU_ID, EM_DEV_PMIC_6318_RGB_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_B_LED_CURRENT_TEXT , 0));

    /* KP LED */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_KP_LED_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 5,
                   	        EM_DEV_PMIC_6318_KP_ENABLE_MENU_ID,
							EM_DEV_PMIC_6318_KP_DUTY_OPTION_MENU_ID,        	
							EM_DEV_PMIC_6318_KP_DIM_CLOCK_MENU_ID,
							EM_DEV_PMIC_6318_KP_CHR_PUMP_EN_MENU_ID,
							EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_KP_LED_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_KP_ENABLE_MENU_ID, EM_DEV_PMIC_6318_KP_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_KP_ENABLE_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_KP_DUTY_OPTION_MENU_ID, EM_DEV_PMIC_6318_KP_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_KP_DUTY_OPTION_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_KP_DIM_CLOCK_MENU_ID, EM_DEV_PMIC_6318_KP_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_KP_DIM_CLOCK_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_KP_CHR_PUMP_EN_MENU_ID, EM_DEV_PMIC_6318_KP_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_KP_CHR_PUMP_EN_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_MENU_ID, EM_DEV_PMIC_6318_KP_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_KP_CHR_PUMP_CURRENT_TEXT , 0));

    /* BL LED */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_BL_LED_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 4,
   					        EM_DEV_PMIC_6318_BL_ENABLE_MENU_ID,
							EM_DEV_PMIC_6318_BL_DUTY_OPTION_MENU_ID,
							EM_DEV_PMIC_6318_BL_DIM_CLOCK_MENU_ID,
							EM_DEV_PMIC_6318_BL_DIM_BYPASS_MENU_ID,   
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_BL_LED_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_BL_ENABLE_MENU_ID, EM_DEV_PMIC_6318_BL_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_BL_ENABLE_TEXT , 0));
 
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_BL_DUTY_OPTION_MENU_ID, EM_DEV_PMIC_6318_BL_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_BL_DUTY_OPTION_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_BL_DIM_CLOCK_MENU_ID, EM_DEV_PMIC_6318_BL_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_BL_DIM_CLOCK_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_BL_DIM_BYPASS_MENU_ID, EM_DEV_PMIC_6318_BL_LED_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_BL_DIM_BYPASS_TEXT , 0));

    /* Audio */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_AUDIO_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 2,
  					        EM_DEV_PMIC_6318_AUDIO_SPEAKER_ENABLE_MENU_ID,
                            EM_DEV_PMIC_6318_AUDIO_SPEAKER_GAIN_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_AUDIO_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_AUDIO_SPEAKER_ENABLE_MENU_ID, EM_DEV_PMIC_6318_AUDIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_AUDIO_SPEAKER_TEXT , 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_AUDIO_SPEAKER_GAIN_MENU_ID, EM_DEV_PMIC_6318_AUDIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_AUDIO_AMPGAIN_TEXT , 0));

    /* Misc */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_MISC_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_MISC_TEXT , 0));

    /* LCM BL Setting */
    ADD_APPLICATION_MENUITEM((EM_DEV_PMIC_6318_LCM_BL_SETTING_MENU_ID, EM_DEV_PMIC_6318_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,  EM_DEV_PMIC_6318_MISC_LCM_BL_SETTING_TEXT , 0));

#endif

#if defined(NAND_SUPPORT) 
    ADD_APPLICATION_MENUITEM((EM_NAND_FORMAT_MENUID, EM_DEVICE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_NAND_FORMAT_TEXT, EM_DEV_NAND_FORMAT_ICON));
#endif
   
#ifdef __OTG_ENABLE__
    ADD_APPLICATION_MENUITEM((EM_DEVICE_USB_MENNUID, EM_DEVICE_MENUID, 1,
                            EM_DEVICE_USB_OTG_SRP_MENNUID,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_USB_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_USB_OTG_SRP_MENNUID, EM_DEVICE_USB_MENNUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_USB_OTG_SRP_TEXT, 0));
#endif
   
#ifdef __MMI_CLAMSHELL__
    ADD_APPLICATION_MENUITEM((EM_DEV_CLAM_MENUID, EM_DEVICE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_CLAM_TEXT, EM_DEV_CLAM_ICON));
#endif 

#ifdef __MMI_SUBLCD__
    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_MENUID, EM_DEVICE_MENUID, 6,
						    EM_DEV_HW_LEVEL_MLCD_CON_MENUID,
							EM_DEV_HW_LEVEL_SLCD_CON_MENUID,
							EM_DEV_HW_LEVEL_BATTERY_MENUID,
							EM_DEV_HW_LEVEL_PWM1_MENUID,
							EM_DEV_HW_LEVEL_PWM2_MENUID,
							EM_DEV_HW_LEVEL_PWM3_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_HW_LEVEL_TEXT, EM_DEV_HW_LEVEL_ICON));
#else /* !__MMI_SUBLCD__ */
    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_MENUID, EM_DEVICE_MENUID, 5,
					        EM_DEV_HW_LEVEL_MLCD_CON_MENUID,
							EM_DEV_HW_LEVEL_BATTERY_MENUID,
							EM_DEV_HW_LEVEL_PWM1_MENUID,
							EM_DEV_HW_LEVEL_PWM2_MENUID,
							EM_DEV_HW_LEVEL_PWM3_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_HW_LEVEL_TEXT, EM_DEV_HW_LEVEL_ICON));
#endif /* __MMI_SUBLCD__  */


    ADD_APPLICATION_MENUITEM((EM_DEV_SET_UART_MENUID, EM_DEVICE_MENUID, 2,
                            EM_DEV_UART_SETTING_MENUID,
                            EM_DEV_UART_POWER_ONOFF_MENUID,
              				SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_SET_UART_TEXT, EM_DEV_SET_UART_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_UART_SETTING_MENUID, EM_DEV_SET_UART_MENUID, 0,
              				SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_UART_SETTING_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_UART_POWER_ONOFF_MENUID, EM_DEV_SET_UART_MENUID, 0,
              				SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_UART_POWER_ONOFF_TEXT, 0));


#ifdef __MMI_TVOUT__
	ADD_APPLICATION_MENUITEM((EM_DEV_TVOUT_SETTING_MENUID, EM_DEVICE_MENUID, 2,
 							EM_DEV_TVOUT_SETTING_SWITCH_MENUID,
							EM_DEV_TVOUT_SETTING_TUNNING_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_TVOUT_SETTING_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_TVOUT_SETTING_SWITCH_MENUID, EM_DEV_TVOUT_SETTING_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_TVOUT_SETTING_SWITCH_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEV_TVOUT_SETTING_TUNNING_MENUID, EM_DEV_TVOUT_SETTING_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_TVOUT_SETTING_TUNNING_TEXT, 0));							
#endif /* __MMI_TVOUT__ */

    ADD_APPLICATION_MENUITEM((EM_DEV_SLEEPMODE_MENUID, EM_DEVICE_MENUID, 2,
                            EM_DEV_SLEEPMODE_ON_MENUID,
                            EM_DEV_SLEEPMODE_OFF_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_SLEEPMODE_TEXT, EM_DEV_SLEEPMODE_ICON));

#if defined(DCM_ENABLE)
    ADD_APPLICATION_MENUITEM((EM_DEV_DCMMODE_MENUID, EM_DEVICE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_DCMMODE_TEXT, 0));
#endif

    /* FM Radio */
#ifdef __MMI_FM_RADIO__
    ADD_APPLICATION_MENUITEM((EM_DEVICE_FM_RADIO_MENU_ID, EM_DEVICE_MENUID, 5,
                       		EM_DEVICE_FM_RADIO_MONO_MENU_ID,
                       		EM_DEVICE_FM_RADIO_STEREO_MENU_ID,
                       		EM_DEVICE_FM_RADIO_RSSI_MENU_ID,
                       		EM_DEVICE_FM_RADIO_IF_COUNT_DELTA_MENU_ID,
                       		EM_DEVICE_FM_RADIO_RSSI_INFO_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_FM_RADIO_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_FM_RADIO_MONO_MENU_ID, EM_DEVICE_FM_RADIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_FM_RADIO_MONO_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_FM_RADIO_STEREO_MENU_ID, EM_DEVICE_FM_RADIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_FM_RADIO_STEREO_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_FM_RADIO_RSSI_MENU_ID, EM_DEVICE_FM_RADIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_FM_RADIO_RSSI_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_FM_RADIO_IF_COUNT_DELTA_MENU_ID, EM_DEVICE_FM_RADIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_FM_RADIO_IF_COUNT_DELTA_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_FM_RADIO_RSSI_INFO_MENU_ID, EM_DEVICE_FM_RADIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_FM_RADIO_RSSI_INFO_TEXT, 0));
#endif /* #ifdef __MMI_FM_RADIO__ */


    ADD_APPLICATION_MENUITEM((EM_DEV_SLEEPMODE_ON_MENUID, EM_DEV_SLEEPMODE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_SLEEPMODE_ON_TEXT, EM_DEV_SLEEPMODE_ON_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_SLEEPMODE_OFF_MENUID, EM_DEV_SLEEPMODE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_SLEEPMODE_OFF_TEXT, EM_DEV_SLEEPMODE_OFF_ICON));

   ADD_APPLICATION_MENUITEM((EM_DEV_LCD_MAIN_MENU_ID, EM_DEV_LCD_MENU_ID, 6,
                                    EM_DEV_LCD_SET_CONSTRAST_MENU_ID,
                                    EM_DEV_LCD_SET_BIAS_MENU_ID,
                                    EM_DEV_LCD_SET_LINERATE_MENU_ID,
                                    EM_DEV_LCD_SET_TEMPERATURE_MENU_ID,
                                    EM_DEV_LCD_SET_COLOR_MENU_ID,
                                    EM_DEV_LCD_DISPLAY_DEMO_PIC_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_MAIN_TEXT, EM_DEV_LCD_MAIN_ICON));
#ifdef __MMI_SUBLCD__
   ADD_APPLICATION_MENUITEM((EM_DEV_LCD_SUB_MENU_ID, EM_DEV_LCD_MENU_ID, 6,
                                    EM_DEV_LCD_SET_CONSTRAST_MENU_ID,
                                    EM_DEV_LCD_SET_BIAS_MENU_ID,
                                    EM_DEV_LCD_SET_LINERATE_MENU_ID,
                                    EM_DEV_LCD_SET_TEMPERATURE_MENU_ID,
                                    EM_DEV_LCD_SET_COLOR_MENU_ID,
                                    EM_DEV_LCD_DISPLAY_DEMO_PIC_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_SUB_TEXT, EM_DEV_LCD_SUB_ICON));
#endif

    ADD_APPLICATION_MENUITEM((EM_DEV_GPIO_LIST_MENU_ID, EM_DEV_GPIO_MENU_ID, 0,
                            SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_GPIO_LIST_TEXT, EM_DEV_GPIO_LIST_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_GPIO_SET_MENU_ID, EM_DEV_GPIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_STR_GPIO_EDITOR, EM_DEV_GPIO_SET_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_GPO_SET_MENU_ID, EM_DEV_GPIO_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_STR_GPO_EDITOR, EM_DEV_GPO_SET_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_MLCD_CON_MENUID, EM_DEV_HW_LEVEL_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_HW_LEVEL_MLCD_CON_TEXT, EM_DEV_HW_LEVEL_MLCD_CON_ICON));

#ifdef __MMI_SUBLCD__
    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_SLCD_CON_MENUID, EM_DEV_HW_LEVEL_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_HW_LEVEL_SLCD_CON_TEXT, EM_DEV_HW_LEVEL_SLCD_CON_ICON));
#endif

    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_BATTERY_MENUID, EM_DEV_HW_LEVEL_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_HW_LEVEL_BATTERY_TEXT, EM_DEV_HW_LEVEL_BATTERY_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_PWM1_MENUID, EM_DEV_HW_LEVEL_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_HW_LEVEL_PWM1_TEXT, EM_DEV_HW_LEVEL_PWM1_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_PWM2_MENUID, EM_DEV_HW_LEVEL_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_HW_LEVEL_PWM2_TEXT, EM_DEV_HW_LEVEL_PWM2_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_HW_LEVEL_PWM3_MENUID, EM_DEV_HW_LEVEL_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_HW_LEVEL_PWM3_TEXT, EM_DEV_HW_LEVEL_PWM3_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_LCD_SET_CONSTRAST_MENU_ID, EM_DEV_LCD_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_SET_CONSTRAST_TEXT, EM_DEV_LCD_SET_CONSTRAST_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_LCD_SET_BIAS_MENU_ID, EM_DEV_LCD_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_SET_BIAS_TEXT, EM_DEV_LCD_SET_BIAS_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_LCD_SET_LINERATE_MENU_ID, EM_DEV_LCD_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_SET_LINERATE_TEXT, EM_DEV_LCD_SET_LINERATE_ICON));

    ADD_APPLICATION_MENUITEM((EM_DEV_LCD_SET_TEMPERATURE_MENU_ID, EM_DEV_LCD_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_SET_TEMPERATURE_TEXT, EM_DEV_LCD_SET_TEMPERATURE_ICON));

   ADD_APPLICATION_MENUITEM((EM_DEV_LCD_SET_COLOR_MENU_ID, EM_DEV_LCD_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_SET_COLOR_TEXT, 0));
   ADD_APPLICATION_MENUITEM((EM_DEV_LCD_DISPLAY_DEMO_PIC_MENU_ID, EM_DEV_LCD_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_LCD_DISPLAY_DEMO_PIC_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_RTC_XOSC_MENU_ID, EM_DEVICE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_RTC_XOSC_TEXT, 0));



    /********************* Audio *********************/
    menu_item_count = 7;
    
#if defined(TV_OUT_SUPPORT)
	menu_item_count++;
#endif

    menu_item_count++;  /* for Debug Info */
    menu_item_count++;  /* for Auto VM Setting*/

	ADD_APPLICATION_MENUITEM((EM_AUDIO_MENUID, ENGINEER_MODE_MENUID, menu_item_count, 
							EM_AUD_SET_MODE_MENUID,
							EM_AUD_NORMAL_MODE_MENUID ,
							EM_AUD_LOUDSP_MODE_MENUID ,
							EM_AUD_HEADSET_MODE_MENUID ,
							EM_AUD_RING_TONE_MENUID    ,
							EM_AUD_SPEECH_ENHANCEMENT_MENUID,
							EM_AUD_SET_MAX_SWING_MENUID,
                        #if defined(TV_OUT_SUPPORT)                   
                            EM_AUD_TV_OUT_MENUID,
                        #endif
                            EM_AUD_DEBUG_INFO_MENUID,
                            EM_AUD_AUTO_VM_SETTING_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUDIO_TEXT, EM_AUDIO_ICON));

   /* audio */
	ADD_APPLICATION_MENUITEM((EM_AUD_RING_TONE_MENUID, EM_AUDIO_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_RING_TONE_TEXT, EM_AUD_RING_TONE_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_SET_MODE_MENUID, EM_AUDIO_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_SET_MODE_TEXT, EM_AUD_SET_MODE_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_NORMAL_MODE_MENUID, EM_AUDIO_MENUID, 7, 
							EM_AUD_FIR_MENUID,
							EM_AUD_SPEECH_MENUID,
							EM_AUD_KEY_TONE_MENUID,
							EM_AUD_MELODY_MENUID,
							EM_AUD_SOUND_MENUID,
							EM_AUD_MICROPHONE_MENUID,
							EM_AUD_SIDE_TONE_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_NORMAL_MODE_TEXT, EM_AUD_NORMAL_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_LOUDSP_MODE_MENUID, EM_AUDIO_MENUID, 6,
							EM_AUD_SPEECH_MENUID,
							EM_AUD_KEY_TONE_MENUID,
							EM_AUD_MELODY_MENUID,
							EM_AUD_SOUND_MENUID,
							EM_AUD_MICROPHONE_MENUID,
							EM_AUD_SIDE_TONE_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_LOUDSP_MODE_TEXT, EM_AUD_LOUDSP_MODE_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_HEADSET_MODE_MENUID, EM_AUDIO_MENUID, 6, 
							EM_AUD_SPEECH_MENUID,
							EM_AUD_KEY_TONE_MENUID,
							EM_AUD_MELODY_MENUID,
							EM_AUD_SOUND_MENUID,
							EM_AUD_MICROPHONE_MENUID,
							EM_AUD_SIDE_TONE_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_HEADSET_MODE_TEXT, EM_AUD_HEADSET_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPEECH_ENHANCEMENT_MENUID, EM_AUDIO_MENUID, 9, 
							EM_AUD_SPH_ENH_COMMON_PARA_MENUID,
							EM_AUD_SPH_ENH_NORMAL_MODE_MENUID,
							EM_AUD_SPH_ENH_HEADSET_MODE_MENUID,
							EM_AUD_SPH_ENH_LOUDSPK_MODE_MENUID,
							EM_AUD_SPH_ENH_BT_EARPHONE_MODE_MENUID,
							EM_AUD_SPH_ENH_BT_CORDLESS_MODE_MENUID,
							EM_AUD_SPH_ENH_AUX1_MODE_MENUID,
							EM_AUD_SPH_ENH_AUX2_MODE_MENUID,
							EM_AUD_SPH_ENH_AUX3_MODE_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_SPEECH_ENHANCEMENT_TEXT, EM_AUD_SPEECH_ENHANCEMENT_ICON));

#if defined(TV_OUT_SUPPORT)
	ADD_APPLICATION_MENUITEM((EM_AUD_TV_OUT_MENUID, EM_AUDIO_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_TV_OUT_TEXT, 0));
#endif

	ADD_APPLICATION_MENUITEM((EM_AUD_DEBUG_INFO_MENUID, EM_AUDIO_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_DEBUG_INFO_TEXT, 0));

	ADD_APPLICATION_MENUITEM((EM_AUD_AUTO_VM_SETTING_MENUID, EM_AUDIO_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_AUTO_VM_SETTING_TEXT, 0));

	ADD_APPLICATION_MENUITEM((EM_AUD_FIR_MENUID, EM_AUD_NORMAL_MODE_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_FIR_TEXT, EM_AUD_FIR_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_SPEECH_MENUID, EM_AUD_SET_VOLUME_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_SPEECH_TEXT, EM_AUD_SPEECH_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_KEY_TONE_MENUID, EM_AUD_SET_VOLUME_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_KEY_TONE_TEXT, EM_AUD_KEY_TONE_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_MELODY_MENUID, EM_AUD_SET_VOLUME_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_MELODY_TEXT, EM_AUD_MELODY_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_MICROPHONE_MENUID, EM_AUD_SET_VOLUME_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_MICROPHONE_TEXT, EM_AUD_MICROPHONE_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_SIDE_TONE_MENUID, EM_AUD_SET_VOLUME_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_SIDE_TONE_TEXT, EM_AUD_SIDE_TONE_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_SOUND_MENUID, EM_AUD_SET_VOLUME_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_SOUND_TEXT, EM_AUD_SOUND_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_COMMON_PARA_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_COMMON_PARAMETERS_TEXT, EM_AUD_COMMON_PARAMETERS_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_NORMAL_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_NORMAL_MODE_TEXT, EM_AUD_NORMAL_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_HEADSET_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_HEADSET_MODE_TEXT, EM_AUD_HEADSET_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_LOUDSPK_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_LOUDSP_MODE_TEXT, EM_AUD_LOUDSP_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_BT_EARPHONE_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_BT_EARPHONE_MODE_TEXT, EM_AUD_BT_EARPHONE_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_BT_CORDLESS_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_BT_CORDLESS_MODE_TEXT, EM_AUD_BT_CORDLESS_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_AUX1_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_AUX1_MODE_TEXT, EM_AUD_AUX1_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_AUX2_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_AUX2_MODE_TEXT, EM_AUD_AUX2_MODE_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUD_SPH_ENH_AUX3_MODE_MENUID, EM_AUD_SPEECH_ENHANCEMENT_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_AUX3_MODE_TEXT, EM_AUD_AUX3_MODE_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUD_SET_MAX_SWING_MENUID, EM_AUDIO_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUD_SET_MAX_SWING_TEXT, EM_AUD_SET_MAX_SWING_ICON));


    /******************** GPRS Act *******************/
    menu_item_count = 3;

#if (defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__))
    menu_item_count ++;
#endif

	ADD_APPLICATION_MENUITEM((EM_GPRS_ACT_MENUID, ENGINEER_MODE_MENUID, menu_item_count,
                            EM_GPRS_AUTO_ATTACH_MENUID,
                            EM_GPRS_1stPDP_MENUID,
                            EM_GPRS_2ndPDP_MENUID,
                        #if (defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__))
                  	        EM_GPRS_PING_MENUID,
                        #endif
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_ACT_TEXT, EM_GPRS_ACT_ICON));
   /* GPRS act */
   ADD_APPLICATION_MENUITEM((EM_GPRS_AUTO_ATTACH_MENUID, EM_GPRS_ACT_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_AUTO_ATTACH_TEXT, EM_GPRS_AUTO_ATTACH_ICON));

   /* 1st PDP */
   ADD_APPLICATION_MENUITEM((EM_GPRS_1stPDP_MENUID, EM_GPRS_ACT_MENUID, 3, 
                            EM_GPRS_ACTIVATE_PDP_MENUID,
                            EM_GPRS_DEACTIVATE_PDP_MENUID,
                            EM_GPRS_SEND_DATA_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_1st_PDP_TEXT, EM_GPRS_AUTO_ATTACH_ICON));

   /* 2nd PDP */
   ADD_APPLICATION_MENUITEM((EM_GPRS_2ndPDP_MENUID, EM_GPRS_ACT_MENUID, 3, 
                            EM_GPRS_ACTIVATE_2ND_PDP_MENUID,
                            EM_GPRS_DEACTIVATE_PDP_MENUID,
                            EM_GPRS_SEND_DATA_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_2nd_PDP_TEXT, 0));


   /* 1st PDP -- Activate PDP */
   ADD_APPLICATION_MENUITEM((EM_GPRS_ACTIVATE_PDP_MENUID, EM_GPRS_ACT_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_ACTIVATE_PDP_TEXT, EM_GPRS_ACT_ICON));

   /* 1st PDP -- De-Activate PDP */
   ADD_APPLICATION_MENUITEM((EM_GPRS_DEACTIVATE_PDP_MENUID, EM_GPRS_ACT_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_DEACTIVATE_PDP_TEXT, 0));

   /* 1st PDP -- Send Data */
   ADD_APPLICATION_MENUITEM((EM_GPRS_SEND_DATA_MENUID, EM_GPRS_ACT_MENUID, 2,
                            EM_GPRS_SEND_DATA_NORM_MENUID,   
                            EM_GPRS_SEND_DATA_HDR_MENUID,   
 							SHOW, NONMOVEABLE, DISP_LIST,EM_GPRS_SEND_DATA_TEXT, 0));

   /* 2nd PDP -- Activate 2nd PDP */
   ADD_APPLICATION_MENUITEM((EM_GPRS_ACTIVATE_2ND_PDP_MENUID, EM_GPRS_2ndPDP_MENUID, 2, 
                            EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY_MENUID,
                            EM_GPRS_ACTIVATE_2ND_PDP_SENCOND_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_ACTIVATE_PDP_TEXT, 0));

   /* 2nd PDP -- Activate 2nd PDP -- Primary */
   ADD_APPLICATION_MENUITEM((EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY_MENUID, EM_GPRS_2ndPDP_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY_TEXT, 0));

   /* 2nd PDP -- Activate 2nd PDP -- Secondary */
   ADD_APPLICATION_MENUITEM((EM_GPRS_ACTIVATE_2ND_PDP_SENCOND_MENUID, EM_GPRS_2ndPDP_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_ACTIVATE_2ND_PDP_SECOND_TEXT, 0));

#if (defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__))
   ADD_APPLICATION_MENUITEM((EM_GPRS_PING_MENUID, EM_GPRS_ACT_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_PING_TEXT, EM_GPRS_PING_ICON));
#endif

   ADD_APPLICATION_MENUITEM((EM_GPRS_SEND_DATA_NORM_MENUID, EM_GPRS_SEND_DATA_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_SEND_DATA_NORM_TEXT, EM_GPRS_SEND_DATA_NORM_ICON));

   ADD_APPLICATION_MENUITEM((EM_GPRS_SEND_DATA_HDR_MENUID, EM_GPRS_SEND_DATA_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_GPRS_SEND_DATA_HDR_TEXT, EM_GPRS_SEND_DATA_HDR_ICON));


    /******************* Band Sel. *******************/
	ADD_APPLICATION_MENUITEM((EM_BAND_SEL_MENUID, EM_NETWORK_SETTING_MENUID, 4,
	                        EM_BAND_900_MENUID,
	                        EM_BAND_1800_MENUID,
	                        EM_BAND_DUAL_MENUID,
	                        EM_BAND_1900_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_BAND_SEL_TEXT, EM_BAND_SEL_ICON));

    /* Band Selection */
    ADD_APPLICATION_MENUITEM((EM_BAND_900_MENUID, EM_BAND_SEL_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_BAND_900_TEXT, EM_BAND_900_ICON));
    ADD_APPLICATION_MENUITEM((EM_BAND_1800_MENUID, EM_BAND_SEL_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_BAND_1800_TEXT, EM_BAND_1800_ICON));
    ADD_APPLICATION_MENUITEM((EM_BAND_DUAL_MENUID, EM_BAND_DUAL_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_BAND_DUAL_TEXT, EM_BAND_DUAL_ICON));
    ADD_APPLICATION_MENUITEM((EM_BAND_1900_MENUID, EM_BAND_SEL_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_BAND_1900_TEXT, EM_BAND_1900_ICON));
    ADD_APPLICATION_MENUITEM((EM_BAND_850_MENUID, EM_BAND_SEL_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_BAND_850_TEXT, EM_BAND_850_ICON));


    /********************** Misc. ********************/    
	menu_item_count = 9;

#if defined(WAP_SUPPORT)
	menu_item_count += 1;
#endif

#ifdef __J2ME__
	menu_item_count += 1;
#endif

#if defined(__AMR_SUPPORT__)
	menu_item_count += 1;
#endif

#if defined(__MMI_TOUCH_SCREEN__)
	menu_item_count += 1;
#endif

#if defined(__MMI_VIDEO_RECORDER__) && defined(ISP_SUPPORT)
	menu_item_count += 1;   	/* Video - High Bitrate */
#endif


	menu_item_count += 1;       /* Cell Reselection */

#if defined(__MMI_EM_FIXED_GAIN_FOR_HELIOS2__)
    menu_item_count += 1;       /* Fixed Gain for Helios2 */
#endif /* __MMI_EM_FIXED_GAIN_FOR_HELIOS2__ */

#if defined(__MMI_EM_MT6223_DEBUG_MODE__)
    menu_item_count += 1;       /* MT6223 debug mode */
#endif

#if defined(MT6223P)
    menu_item_count +=1;        /* LSD Slower: ticks */
#endif

#if defined(__MMI_CASCADE_MENU__)
    menu_item_count +=1;            /* Cascade Menu */
#endif /* defined(__MMI_CASCADE_MENU__) */

    ADD_APPLICATION_MENUITEM((EM_MISC_MENUID, ENGINEER_MODE_MENUID, menu_item_count,
							EM_AUTO_ANSWER_MENUID,
							EM_HIGHSPEED_SIM_MENUID, 
							EM_POWER_ON_DURATION_MENUID,
							EM_BACKLIGHT_MENUID,
							EM_SERIAL_PORT_EN_MENUID,
							EM_AUTO_RESET_MENUID, 
							EM_RAM_TEST_MENUID,       	
							EM_MEMORY_DUMP_MENUID,		
							EM_MMI_DEBUG_MENUID, 
						#if defined(__AMR_SUPPORT__)
							EM_AMR_MENUID,
						#endif                          

						#if defined(WAP_SUPPORT)
							EM_WAP_MENUID,
						#endif  
						
						#ifdef __J2ME__
							EM_J2ME_TCK_MENUID,
						#endif                          

						#if defined(__MMI_TOUCH_SCREEN__)
							EM_TOUCHSCREEN_MENUID,
						#endif

						#if defined(__MMI_VIDEO_RECORDER__) && defined(ISP_SUPPORT)
							EM_VIDEO_HI_BITRATE_MENUID,
						#endif 	
							
						    EM_MISC_CELL_RESELECTION_MENUID,  /* Cell Reselection */ 

                        #if defined(__MMI_EM_FIXED_GAIN_FOR_HELIOS2__)
						    EM_MISC_FIXED_GAIN_FOR_HELIOS2_MENUID, /* Fixed Gain For Helios2 */
						#endif 

                        #if defined(__MMI_EM_MT6223_DEBUG_MODE__)
                        EM_MISC_MT_6223_DEBUG_MODE_MENU_ID,     /* MT6223 Debug Mode */
                        #endif 
                        #if defined(MT6223P)
                            EM_MISC_LSD_SLOWER_MENU_ID,          /* LSD Slower: ticks */
                        #endif
                        #if defined(__MMI_CASCADE_MENU__)
                            EM_MISC_CASCADE_MENU_MENU_ID,            /* Cascade Menu */
                        #endif /* defined(__MMI_CASCADE_MENU__) */
 					        SHOW, NONMOVEABLE, DISP_LIST, EM_MISC_TEXT, EM_MISC_ICON));

    /***************** Cascading Menu ******************/
#if defined(__MMI_CASCADE_MENU__)    
    ADD_APPLICATION_MENUITEM((
        EM_MISC_CASCADE_MENU_MENU_ID, 
        EM_MISC_MENUID, 
        0, 
        SHOW, 
        NONMOVEABLE, 
        DISP_LIST, 
        STR_ID_EM_MISC_CASCADE_MENU, 
        0));    
#endif /* defined(__MMI_CASCADE_MENU__) */

    /* Touch Screen */
#if defined(__MMI_TOUCH_SCREEN__)
	ADD_APPLICATION_MENUITEM((EM_TOUCHSCREEN_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_TOUCHSCREEN_TEXT, 0));
	
	ADD_APPLICATION_MENUITEM((EM_TOUCHSCREEN_TEST_OPTION_MENUID, EM_TOUCHSCREEN_MENUID, 2,
							EM_TOUCHSCREEN_TEST_STATISTICS_MENUID,
							EM_TOUCHSCREEN_TEST_EXIT_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_TOUCHSCREEN_TEST_TEXT, 0));

	ADD_APPLICATION_MENUITEM((EM_TOUCHSCREEN_TEST_STATISTICS_MENUID, EM_TOUCHSCREEN_TEST_OPTION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_TOUCHSCREEN_TEST_STATISTICS_TEXT, 0));
	
	ADD_APPLICATION_MENUITEM((EM_TOUCHSCREEN_TEST_EXIT_MENUID, EM_TOUCHSCREEN_TEST_OPTION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_TOUCHSCREEN_TEST_EXIT_TEXT, 0));
#endif

    ADD_APPLICATION_MENUITEM((EM_AUTO_ANSWER_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUTO_ANSWER_TEXT, EM_AUTO_ANSWER_ICON));

    ADD_APPLICATION_MENUITEM((EM_HIGHSPEED_SIM_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_HIGHSPEED_SIM_MENUID_TEXT, EM_HIGHSPEED_SIM_MENUID_ICON));

    ADD_APPLICATION_MENUITEM((EM_BACKLIGHT_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_BACKLIGHT_TEXT, EM_BACKLIGHT_ICON));

    ADD_APPLICATION_MENUITEM((EM_SERIAL_PORT_EN_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SERIAL_PORT_EN_TEXT, EM_SERIAL_PORT_EN_ICON));

    ADD_APPLICATION_MENUITEM((EM_AUTO_RESET_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUTO_RESET_TEXT, EM_AUTO_RESET_ICON));

    ADD_APPLICATION_MENUITEM((EM_AMR_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AMR_TEXT, EM_AMR_ICON));

    ADD_APPLICATION_MENUITEM((EM_MMI_DEBUG_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_MMI_DEBUG_TEXT, EM_MMI_DEBUG_ICON));

    ADD_APPLICATION_MENUITEM((EM_MEMORY_DUMP_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_MEMORY_DUMP_TEXT, EM_MEMORY_DUMP_ICON));

    ADD_APPLICATION_MENUITEM((EM_RAM_TEST_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_RAM_TEST_TEXT, EM_RAM_TEST_ICON));

   /* Cell Reselection */
    ADD_APPLICATION_MENUITEM((EM_MISC_CELL_RESELECTION_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_MISC_CELL_RESELECT_TEXT, 0));

#if defined(__MMI_EM_FIXED_GAIN_FOR_HELIOS2__)
   /* Fixed Gain for Helios2 */
    ADD_APPLICATION_MENUITEM((EM_MISC_FIXED_GAIN_FOR_HELIOS2_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_MISC_FIXED_GAIN_FOR_HELIOS2_TEXT, 0));
#endif


#if defined(__MMI_EM_MT6223_DEBUG_MODE__)
    /* MT6223 Debug Mode */
    ADD_APPLICATION_MENUITEM((EM_MISC_MT_6223_DEBUG_MODE_MENU_ID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_MISC_MT6223_DEBUG_MODE_TEXT, 0));
#endif 

#if defined(MT6223P)
    /* LSD Slower: ticks */
    ADD_APPLICATION_MENUITEM((EM_MISC_LSD_SLOWER_MENU_ID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_MISC_LSD_SLOWER_TEXT, 0));
#endif


#if defined(__MMI_VIDEO_RECORDER__) && defined(ISP_SUPPORT)
    ADD_APPLICATION_MENUITEM((EM_VIDEO_HI_BITRATE_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_VIDEO_HI_BITRATE_TEXT, 0));	
#endif
	

    ADD_APPLICATION_MENUITEM((EM_WAP_MENUID, EM_MISC_MENUID, 5,
                            EM_WAP_ENABLE_DEBUG_MENUID,
                            EM_WAP_USER_AGENT_MENUID,
                            EM_WAP_ACCEPT_HEADER_MENUID,
                            EM_WAP_MMS_VERSION_MENUID,
                            EM_WAP_OFFLINE_PAGE_MENUID,                          
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_TEXT, EM_WAP_ICON));
   
    ADD_APPLICATION_MENUITEM((EM_WAP_ENABLE_DEBUG_MENUID, EM_WAP_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_ENABLE_DEBUG_TEXT, EM_WAP_ENABLE_DEBUG_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_OFFLINE_PAGE_MENUID, EM_WAP_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_OFFLINE_PAGE_TEXT, EM_WAP_OFFLINE_PAGE_ICON));
   

    ADD_APPLICATION_MENUITEM((EM_WAP_USER_AGENT_MENUID, EM_WAP_MENUID, 0,
				  			SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_USER_AGENT_TEXT, EM_WAP_USER_AGENT_ICON));
   
    ADD_APPLICATION_MENUITEM((EM_WAP_ACCEPT_HEADER_MENUID, EM_WAP_MENUID, 5,
                            EM_WAP_ACCEPT_HEADER_WAP121_MENUID,
                            EM_WAP_ACCEPT_HEADER_WAP20_MENUID,
                            EM_WAP_ACCEPT_HEADER_WML_MENUID,
                            EM_WAP_ACCEPT_HEADER_XHTML_MENUID,	
                            EM_WAP_ACCEPT_HEADER_HTML_MENUID,
			 				SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_ACCEPT_HEADER_TEXT, EM_WAP_ACCEPT_HEADER_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_ACCEPT_HEADER_WAP121_MENUID, EM_WAP_ACCEPT_HEADER_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_ACCEPT_HEADER_WAP121_TEXT, EM_WAP_ACCEPT_HEADER_WAP121_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_ACCEPT_HEADER_WAP20_MENUID, EM_WAP_ACCEPT_HEADER_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_ACCEPT_HEADER_WAP20_TEXT, EM_WAP_ACCEPT_HEADER_WAP20_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_ACCEPT_HEADER_WML_MENUID, EM_WAP_ACCEPT_HEADER_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_ACCEPT_HEADER_WML_TEXT, EM_WAP_ACCEPT_HEADER_WML_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_ACCEPT_HEADER_XHTML_MENUID, EM_WAP_ACCEPT_HEADER_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_ACCEPT_HEADER_XHTML_TEXT, EM_WAP_ACCEPT_HEADER_XHTML_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_ACCEPT_HEADER_HTML_MENUID, EM_WAP_ACCEPT_HEADER_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_ACCEPT_HEADER_HTML_TEXT, EM_WAP_ACCEPT_HEADER_HTML_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_MMS_VERSION_MENUID, EM_WAP_MENUID, 4,
                            EM_WAP_MMS_VERSION_MMS_DEFAULT_MENUID,
                            EM_WAP_MMS_VERSION_MMS10_MENUID,
                            EM_WAP_MMS_VERSION_MMS11_MENUID,
                            EM_WAP_MMS_VERSION_MMS12_MENUID,
			 				SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_MMS_VERSION_TEXT, EM_WAP_MMS_VERSION_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_MMS_VERSION_MMS_DEFAULT_MENUID, EM_WAP_MMS_VERSION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_MMS_VERSION_MMS_DEFAULT_TEXT, EM_WAP_MMS_VERSION_MMS_DEFAULT_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_MMS_VERSION_MMS10_MENUID, EM_WAP_MMS_VERSION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_MMS_VERSION_MMS10_TEXT, EM_WAP_MMS_VERSION_MMS10_ICON));

    ADD_APPLICATION_MENUITEM((EM_WAP_MMS_VERSION_MMS11_MENUID, EM_WAP_MMS_VERSION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_MMS_VERSION_MMS11_TEXT, EM_WAP_MMS_VERSION_MMS11_ICON));
 
    ADD_APPLICATION_MENUITEM((EM_WAP_MMS_VERSION_MMS12_MENUID, EM_WAP_MMS_VERSION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_WAP_MMS_VERSION_MMS12_TEXT, EM_WAP_MMS_VERSION_MMS12_ICON));

    ADD_APPLICATION_MENUITEM((EM_POWER_ON_DURATION_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_POWER_ON_DURATION_TEXT, EM_POWER_ON_DURATION_ICON));

#ifdef __J2ME__
    ADD_APPLICATION_MENUITEM((EM_J2ME_TCK_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_J2ME_TCK_TEXT, EM_J2ME_TCK_ICON));
#endif

#if (defined(MT6229) || defined(MT6227) || defined(MT6228) || defined(MT6225) || defined(MT6268T) || defined(MT6230) || defined(MT6227D) || defined(MT6223) || defined(MT6223P)) 
#if (defined(MT6227) || defined(MT6227D))

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MENUID, EM_DEVICE_MENUID, 5,
   					        EM_SWDBG_OFF_MENUID ,
							EM_SWDBG_DSP_L1_PS_MENUID ,
							EM_SWDBG_L1_PS_MENUID ,
							EM_SWDBG_MCU_MENUID ,
							EM_SWDBG_RESET_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_TEXT, EM_SWDBG_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_OFF_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_OFF_TEXT, EM_SWDBG_OFF_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_DSP_L1_PS_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_DSP_L1_PS_TEXT, EM_SWDBG_DSP_L1_PS_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_L1_PS_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_L1_PS_TEXT, EM_SWDBG_L1_PS_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MCU_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_MCU_TEXT, EM_SWDBG_MCU_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_RESET_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_RESET_TEXT, EM_SWDBG_RESET_ICON));

#elif (defined(MT6228))	 

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MENUID, EM_DEVICE_MENUID, 6,
	  					    EM_SWDBG_OFF_MENUID ,
							EM_SWDBG_DSP_L1_PS_MENUID ,
							EM_SWDBG_L1_PS_MENUID ,
							EM_SWDBG_MCU_MENUID ,
							EM_SWDBG_MCU_DSP_MENUID,    /* Add for 6228 */
							EM_SWDBG_RESET_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_TEXT, EM_SWDBG_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_OFF_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_OFF_TEXT, EM_SWDBG_OFF_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_DSP_L1_PS_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_DSP_L1_PS_TEXT, EM_SWDBG_DSP_L1_PS_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_L1_PS_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_L1_PS_TEXT, EM_SWDBG_L1_PS_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MCU_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_MCU_TEXT, EM_SWDBG_MCU_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MCU_DSP_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_MCU_DSP_TEXT, EM_SWDBG_MCU_DSP_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_RESET_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_RESET_TEXT, EM_SWDBG_RESET_ICON));	

#else
    ADD_APPLICATION_MENUITEM((EM_SWDBG_MENUID, EM_DEVICE_MENUID, 8,
 						    EM_SWDBG_OFF_MENUID ,
							EM_SWDBG_DSP_L1_MENUID ,
							EM_SWDBG_DSP_PS_MENUID ,
							EM_SWDBG_L1_PS_MENUID ,
							EM_SWDBG_MCU_MENUID ,
							EM_SWDBG_MCU_DSP_MENUID ,
							EM_SWDBG_MCU_DSP_IRDBG_MENUID,
                            EM_SWDBG_RESET_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_TEXT, EM_SWDBG_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_OFF_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_OFF_TEXT, EM_SWDBG_OFF_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_DSP_L1_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_DSP_L1_TEXT, EM_SWDBG_DSP_L1_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_DSP_PS_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_DSP_PS_TEXT, EM_SWDBG_DSP_PS_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_L1_PS_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_L1_PS_TEXT, EM_SWDBG_L1_PS_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MCU_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_MCU_TEXT, EM_SWDBG_MCU_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MCU_DSP_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_MCU_DSP_TEXT, EM_SWDBG_MCU_DSP_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_MCU_DSP_IRDBG_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_MCU_DSP_IRDBG_TEXT, EM_SWDBG_MCU_DSP_IRDBG_ICON));

    ADD_APPLICATION_MENUITEM((EM_SWDBG_RESET_MENUID, EM_SWDBG_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SWDBG_RESET_TEXT, EM_SWDBG_RESET_ICON));
#endif
#endif


    /**************** Auto Test List *****************/
	ADD_APPLICATION_MENUITEM((EM_AUTO_TEST_SETTING_MENUID, ENGINEER_MODE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUTO_TEST_SETTING_TEXT, EM_AUTO_TEST_SETTING_ICON));

	ADD_APPLICATION_MENUITEM((EM_AUTO_TEST_OPTIONS_MENUID, 0, 3,
	                        EM_AUTO_TEST_ADD_MENUID,
	                        EM_AUTO_TEST_CHANGE_PRIORITY_MENUID,
 	                        EM_AUTO_TEST_REMOVE_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	STR_GLOBAL_OPTIONS, NULL));

	ADD_APPLICATION_MENUITEM((EM_AUTO_TEST_ADD_MENUID, EM_AUTO_TEST_OPTIONS_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUTO_TEST_ADD_TEXT, EM_AUTO_TEST_ADD_ICON));
	ADD_APPLICATION_MENUITEM((EM_AUTO_TEST_CHANGE_PRIORITY_MENUID, EM_AUTO_TEST_OPTIONS_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUTO_TEST_CHANGE_PRIORITY_TEXT, EM_AUTO_TEST_CHANGE_PRIORITY_ICON));
	ADD_APPLICATION_MENUITEM((EM_AUTO_TEST_REMOVE_MENUID, EM_AUTO_TEST_OPTIONS_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_AUTO_TEST_REMOVE_TEXT, EM_AUTO_TEST_REMOVE_ICON));


    /**************** PWR Down Control ***************/
	ADD_APPLICATION_MENUITEM((EM_PWR_DOWN_CONTROL_MENUID, ENGINEER_MODE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_PWR_DOWN_CONTROL_TEXT, EM_PWR_DOWN_CONTROL_ICON));


    /********************* SW Patch ******************/
	ADD_APPLICATION_MENUITEM((EM_SW_PATCH_MENUID, ENGINEER_MODE_MENUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SW_PATCH_TEXT, EM_SW_PATCH_ICON));


    /******************* Debug Info ******************/
    menu_item_count = 2;
#if defined(__FS_TRACE_SUPPORT__)  
    menu_item_count+=1;
#endif

	ADD_APPLICATION_MENUITEM((EM_DEBUG_INFO_MENUID, ENGINEER_MODE_MENUID, menu_item_count,

                         #if defined(__FS_TRACE_SUPPORT__)  
                             EM_FS_TRACE_MENUID,
                         #endif

                             EM_LAST_EXCEPTION_MENUID,
                             EM_SYS_STATS_MENUID,                          
    			             SHOW, NONMOVEABLE, DISP_LIST,	STR_ID_EM_DEBUG_INFO, IMG_ID_EM_DEBUG_INFO));

    /* FS Trace */
#if defined(__FS_TRACE_SUPPORT__)  
	ADD_APPLICATION_MENUITEM((EM_FS_TRACE_MENUID, ENGINEER_MODE_MENUID, 0,
							 SHOW, NONMOVEABLE, DISP_LIST,	STR_ID_EM_FS_TRACE, IMG_ID_EM_FS_TRACE));
#endif

    /* Last exception */
	ADD_APPLICATION_MENUITEM((EM_LAST_EXCEPTION_MENUID, ENGINEER_MODE_MENUID, 0,
							 SHOW, NONMOVEABLE, DISP_LIST,	STR_ID_EM_LAST_EXCEPTION, IMG_ID_EM_LAST_EXCEPTION));

    /* System Stats */
	ADD_APPLICATION_MENUITEM((EM_SYS_STATS_MENUID, EM_DEBUG_INFO_MENUID, 1,
                             EM_WRITE_SYS_STATS_MENUID,
    			             SHOW, NONMOVEABLE, DISP_LIST,	STR_ID_EM_SYS_STATS, IMG_ID_EM_SYS_STATS));

	ADD_APPLICATION_MENUITEM((EM_WRITE_SYS_STATS_MENUID, EM_SYS_STATS_MENUID, 0,
    			             SHOW, NONMOVEABLE, DISP_LIST,	STR_ID_EM_WRITE_SYS_STATS, IMG_ID_EM_WRITE_SYS_STATS));

	ADD_APPLICATION_MENUITEM((EM_SAVING_STAT_PWROFF_MENUID, EM_SYS_STATS_MENUID, 0,
    			             SHOW, NONMOVEABLE, DISP_LIST,	STR_ID_EM_SAVING_STAT_PWROFF, IMG_ID_EM_SAVING_STAT_PWROFF));


    /******************** Sock Test ******************/
#ifdef __TCPIP__
	ADD_APPLICATION_MENUITEM((EM_SOCKET_MENUID, ENGINEER_MODE_MENUID, 6, 
							 EM_SOCKET_DNS_MENUID,
							 EM_SOCKET_HTTP_MENUID,
							 EM_SOCKET_ECHO_MENUID,
							 EM_SOCKET_DATE_MENUID,
							 EM_SOCKET_TRACERT_MENUID,
							 EM_SOCKET_IPERF_MENUID,
                             SHOW, NONMOVEABLE, DISP_LIST, EM_SOCKET_TEXT, EM_SOCKET_ICON));
#endif /* __TCPIP__ */

#ifdef __TCPIP__ 
    /* socket test */
    ADD_APPLICATION_MENUITEM((EM_SOCKET_DNS_MENUID, EM_SOCKET_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SOCKET_DNS_TEXT, EM_SOCKET_DNS_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_HTTP_MENUID, EM_SOCKET_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SOCKET_HTTP_TEXT, EM_SOCKET_HTTP_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_ECHO_MENUID, EM_SOCKET_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SOCKET_ECHO_TEXT, EM_SOCKET_ECHO_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_DATE_MENUID, EM_SOCKET_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SOCKET_DATE_TEXT, EM_SOCKET_DATE_ICON));
    ADD_APPLICATION_MENUITEM((EM_SOCKET_TRACERT_MENUID, EM_SOCKET_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_SOCKET_TRACERT_TEXT, EM_SOCKET_DATE_ICON));

/* BEGIN OF IPERF */
    ADD_APPLICATION_MENUITEM((EM_SOCKET_IPERF_MENUID, EM_SOCKET_MENUID, 2,
                             EM_SOCKET_IPERF_TCP_MENUID,
                             EM_SOCKET_IPERF_UDP_MENUID,
                             SHOW, NONMOVEABLE, DISP_LIST, EM_SOCKET_IPERF_STR, EM_SOCKET_IPERF_ICON));
/* END OF IPERF */

    ADD_APPLICATION_MENUITEM((EM_SOCKET_DNS_OPTION_MENUID, 0, 2,
							EM_SOCKET_DNS_DONE_MENUID,
	  				        EM_SOCKET_DNS_INPUT_METHOD_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	STR_GLOBAL_OPTIONS, EM_SOCKET_DNS_OPTION_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_HTTP_OPTION_MENUID, 0, 2,
							EM_SOCKET_HTTP_DONE_MENUID,
	 				        EM_SOCKET_HTTP_INPUT_METHOD_MENUID,
							SHOW, NONMOVEABLE, DISP_LIST,	STR_GLOBAL_OPTIONS, EM_SOCKET_HTTP_OPTION_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_DNS_DONE_MENUID, EM_SOCKET_DNS_OPTION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	STR_GLOBAL_DONE, EM_SOCKET_DNS_DONE_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_DNS_INPUT_METHOD_MENUID, EM_SOCKET_DNS_OPTION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	STR_GLOBAL_INPUT_METHOD, EM_SOCKET_DNS_INPUT_METHOD_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_HTTP_DONE_MENUID, EM_SOCKET_HTTP_OPTION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	STR_GLOBAL_DONE, EM_SOCKET_HTTP_DONE_ICON));

    ADD_APPLICATION_MENUITEM((EM_SOCKET_HTTP_INPUT_METHOD_MENUID, EM_SOCKET_HTTP_OPTION_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	STR_GLOBAL_INPUT_METHOD, EM_SOCKET_HTTP_INPUT_METHOD_ICON));
#endif

	/* BEGIN OF IPERF */
    ADD_APPLICATION_MENUITEM((EM_SOCKET_IPERF_TCP_MENUID, EM_SOCKET_IPERF_MENUID, 0,
                             SHOW, NONMOVEABLE, DISP_LIST,   EM_SOCKET_IPERF_TCP_TESTING_STR, EM_SOCKET_IPERF_TCP_ICON));    
    ADD_APPLICATION_MENUITEM((EM_SOCKET_IPERF_UDP_MENUID, EM_SOCKET_IPERF_MENUID, 0,
                             SHOW, NONMOVEABLE, DISP_LIST,  EM_SOCKET_IPERF_UDP_TESTING_STR, EM_SOCKET_IPERF_UDP_ICON));
	/* END OF IPERF */

    /******************** Bluetooth ******************/
#if defined(__MMI_BT_SUPPORT__)

    menu_item_count = 1;
#if defined(__MMI_EM_BT_RF_TEST__)  
    menu_item_count+=1;
#endif

#ifdef __MMI_EM_BT_GET_CHIP_VERION__
    menu_item_count+=1;
#endif

	ADD_APPLICATION_MENUITEM((EM_BT_MENUID, ENGINEER_MODE_MENUID, menu_item_count,
	                         EM_BT_GENERNAL_TEST_MENUID,
	                     #ifdef __MMI_EM_BT_RF_TEST__
	                         EM_DEVICE_BT_RF_TEST_MENUID,
	                     #endif
                         #ifdef __MMI_EM_BT_GET_CHIP_VERION__
	                         EM_BT_GET_CHIP_VERSION_MENUID,
	                     #endif
    			             SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_STR_ID, EM_BT_IMG_ID));


/* General test */
    menu_item_count = 4;

#if defined(__MMI_BT_MTK_SUPPORT__)
    menu_item_count++;  /* Exit Test Mode */
#endif

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
    menu_item_count++;
#endif


    ADD_APPLICATION_MENUITEM((EM_BT_GENERNAL_TEST_MENUID, EM_BT_MENUID, menu_item_count,
    			             EM_BT_ENTRY_TEST_MENUID,
    			             EM_BT_ADD_AUDIO_CONNECTION_MENUID,
                             EM_BT_REMOVE_AUDIO_CONNECTION_MENUID,
                             EM_BT_ENTRY_LOOPBACK_MENUID,
                         #if defined(__MMI_BT_MTK_SUPPORT__)
                             EM_BT_EXIT_TEST_MODE_MENUID,
                         #endif

                         #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
                             EM_BT_AVRCP_CMD_LIST_MENUID,
                         #endif
    			             SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_GENERNAL_TEST_STR_ID, EM_BT_IMG_ID));

    ADD_APPLICATION_MENUITEM((EM_BT_ENTRY_TEST_MENUID, EM_BT_MENUID, 0,
    			             SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_ENTRY_TEST_STR_ID, EM_BT_ENTRY_TEST_IMG_ID));

    ADD_APPLICATION_MENUITEM((EM_BT_REMOVE_AUDIO_CONNECTION_MENUID, EM_BT_MENUID, 0,
    			             SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_REMOVE_AUDIO_CONNECTION_STR_ID, EM_BT_DEBUG_TRACE_IMG_ID));

    ADD_APPLICATION_MENUITEM((EM_BT_ADD_AUDIO_CONNECTION_MENUID, EM_BT_MENUID, 0,
    			             SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_ADD_AUDIO_CONNECTION_STR_ID, EM_BT_REMOVE_AUDIO_CONNECTION_IMG_ID));

	ADD_APPLICATION_MENUITEM((EM_BT_ENTRY_LOOPBACK_MENUID, EM_BT_MENUID, 0,
    			             SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_LOOKBACK_STR_ID, 0));

#if defined(__MMI_BT_MTK_SUPPORT__)
	ADD_APPLICATION_MENUITEM((EM_BT_EXIT_TEST_MODE_MENUID, EM_BT_MENUID, 0,
    			     SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_EXIT_TEST_MODE_STR_ID, 0));
#endif
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
    ADD_APPLICATION_MENUITEM((EM_BT_AVRCP_CMD_LIST_MENUID, EM_BT_MENUID, 0,
    			     SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_AVRCP_CMD_LIST_STR_ID, 0));
#endif

/* BT RF Test */
#ifdef __MMI_EM_BT_RF_TEST__
    ADD_APPLICATION_MENUITEM((EM_DEVICE_BT_RF_TEST_MENUID, EM_DEVICE_MENUID, 4,
                              EM_DEVICE_BT_RF_TEST_TX_MENUID,
                              EM_DEVICE_BT_RF_TEST_RX_MENUID,
                              EM_DEVICE_BT_RF_TEST_BD_ADDR_MENUID,
                              EM_DEVICE_BT_RF_TEST_MODE_MENUID,
					  		  SHOW, NONMOVEABLE, DISP_LIST,	EM_DEV_BT_RF_TEST_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_BT_RF_TEST_TX_MENUID, EM_DEVICE_BT_RF_TEST_MENUID, 0,
							  SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_BT_RF_TEST_TX_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_BT_RF_TEST_RX_MENUID, EM_DEVICE_BT_RF_TEST_MENUID, 0,
							  SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_BT_RF_TEST_RX_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_BT_RF_TEST_BD_ADDR_MENUID, EM_DEVICE_BT_RF_TEST_MENUID, 0,
							  SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_BT_RF_TEST_BD_ADDR_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_DEVICE_BT_RF_TEST_MODE_MENUID, EM_DEVICE_BT_RF_TEST_MENUID, 0,
							  SHOW, NONMOVEABLE, DISP_LIST, EM_DEV_BT_RF_TEST_MODE_TEXT, 0));

#endif /* __MMI_EM_BT_RF_TEST__ */

/* BT Get Chip Version */
#ifdef __MMI_EM_BT_GET_CHIP_VERION__
	ADD_APPLICATION_MENUITEM((EM_BT_GET_CHIP_VERSION_MENUID, EM_BT_MENUID, 0,
    			             SHOW, NONMOVEABLE, DISP_LIST,	EM_BT_GET_CHIP_VERSION_STR_ID, EM_BT_IMG_ID));
#endif /* __MMI_EM_BT_GET_CHIP_VERION__ */



#endif /* __MMI_BT_SUPPORT__ */


    /******************** Profiling ******************/
    menu_item_count = 0;

#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
	menu_item_count += 1;
#endif

#ifdef __MMI_INTERACTIVE_PROFILNG__
	menu_item_count += 1;      	/* frame profiling */
#endif

#ifdef __MMI_UI_BENCHMARK__
    menu_item_count += 1;       /* UI bench mark */
#endif

	ADD_APPLICATION_MENUITEM(( MENU_ID_EM_PROFILING, ENGINEER_MODE_MENUID, menu_item_count, 
                                                     #if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
							 MENU_ID_EM_PROFILING_MULTIMEDIA, /* child */
                                                     #endif
                                                     #ifdef __MMI_INTERACTIVE_PROFILNG__
                                                         EM_FRM_PROFILING_MENUID,
                                                     #endif

                                                     #ifdef __MMI_UI_BENCHMARK__
                                                         EM_UI_BENCHMARK_MENUID,
                                                     #endif
							 SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING, 0));

                        
#ifdef __MMI_INTERACTIVE_PROFILNG__
    ADD_APPLICATION_MENUITEM((EM_FRM_PROFILING_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_FRM_PROFILING_TEXT, EM_FRM_PROFILING_ICON));
#endif

#ifdef __MMI_UI_BENCHMARK__
    ADD_APPLICATION_MENUITEM((EM_UI_BENCHMARK_MENUID, EM_MISC_MENUID, 0, 
							SHOW, NONMOVEABLE, DISP_LIST,	EM_UI_BENCHMARK_TEXT, EM_FRM_PROFILING_ICON));
#endif 

#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)

	menu_item_count = 1;
    #ifdef __MMI_CAMERA__
 	    menu_item_count++;
    #endif 

    #ifdef __MMI_VIDEO_PLAYER__
	    menu_item_count++;
    #endif 

    #ifdef __MMI_VIDEO_RECORDER__
    	menu_item_count++;
    #endif 

    #ifdef __MMI_IMG_DEC_PROFILING__    
    	menu_item_count++;
    #endif 
	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_MULTIMEDIA, MENU_ID_EM_PROFILING, menu_item_count,
							MENU_ID_EM_PROFILING_AUTO_PLAY,
						#ifdef __MMI_CAMERA__
							MENU_ID_EM_PROFILING_CAMERA,
						#endif

						#ifdef __MMI_VIDEO_PLAYER__
						    MENU_ID_EM_PROFILING_VDOPLY, 
						#endif 
						
						#ifdef __MMI_VIDEO_RECORDER__
						    MENU_ID_EM_PROFILING_VDOREC,   
						#endif
                        #ifdef __MMI_IMG_DEC_PROFILING__
                            MENU_ID_EM_PROFILING_IMAGE_DECODE,
						#endif
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_MULTIMEDIA, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_AUTO_PLAY, MENU_ID_EM_PROFILING_MULTIMEDIA, 0, 
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_AUTO_PLAY, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_CAMERA, MENU_ID_EM_PROFILING_MULTIMEDIA, 2,
							MENU_ID_EM_PROFILING_CAMERA_START,
							MENU_ID_EM_PROFILING_CAMERA_SETTING,	
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_CAMERA, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_CAMERA_START, MENU_ID_EM_PROFILING_CAMERA, 0,
     						SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_START, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_CAMERA_SETTING, MENU_ID_EM_PROFILING_CAMERA, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_SETTING, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_VDOPLY, MENU_ID_EM_PROFILING_MULTIMEDIA, 2,
							MENU_ID_EM_PROFILING_VDOPLY_START,
							MENU_ID_EM_PROFILING_VDOPLY_SETTING,										
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_VDOPLY, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_VDOPLY_START, MENU_ID_EM_PROFILING_VDOPLY, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_START, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_VDOPLY_SETTING, MENU_ID_EM_PROFILING_VDOPLY, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_SETTING, 0));
										
	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_VDOREC, MENU_ID_EM_PROFILING_MULTIMEDIA, 2,
							MENU_ID_EM_PROFILING_VDOREC_START,
							MENU_ID_EM_PROFILING_VDOREC_SETTING,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_VDOREC, 0));		

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_VDOREC_START, MENU_ID_EM_PROFILING_VDOREC, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_START, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_VDOREC_SETTING, MENU_ID_EM_PROFILING_VDOREC, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_SETTING, 0));
									
#endif /* __MMI_CAMERA__ || __MMI_VIDEO_RECORDER__ || __MMI_VIDEO_PLAYER__ */

#ifdef __MMI_IMG_DEC_PROFILING__
	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_IMAGE_DECODE, MENU_ID_EM_PROFILING_MULTIMEDIA, 2,
                            MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER,
                            MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER_ROTATE,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_IMAGE_DECODE, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER, MENU_ID_EM_PROFILING_IMAGE_DECODE, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_SINGLE_FOLDER, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER_ROTATE, MENU_ID_EM_PROFILING_IMAGE_DECODE, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_ID_EM_PROFILING_SINGLE_FOLDER_ROTATE, 0));
#endif /* __MMI_IMG_DEC_PROFILING__ */    

    /********************** RF Tool *******************/
#if defined(__FLIGHT_MODE_SUPPORT__) || defined(__WIFI_SUPPORT__)

    menu_item_count = 0;

    #if defined(__FLIGHT_MODE_SUPPORT__)
        menu_item_count++;
    #endif

    #if defined(__WIFI_SUPPORT__)
        menu_item_count++;
    #endif

	ADD_APPLICATION_MENUITEM((EM_RF_TEST_TOOL_MENUID, ENGINEER_MODE_MENUID, menu_item_count, 
	                     #if defined(__FLIGHT_MODE_SUPPORT__)
						     EM_RF_TEST_GSM_MENUID,
					     #endif

                         #if defined(__WIFI_SUPPORT__)
                  		     EM_RF_TEST_WIFI_MENUID ,
                  		 #endif
						     SHOW, NONMOVEABLE, DISP_LIST, EM_RF_TEST_TOOL_TEXT, 0));

#endif /* defined(__FLIGHT_MODE_SUPPORT__) || defined(__WIFI_SUPPORT__) */

    /* GSM */
#if defined(__FLIGHT_MODE_SUPPORT__) 

	ADD_APPLICATION_MENUITEM((EM_RF_TEST_GSM_MENUID, EM_RF_TEST_TOOL_MENUID, 3, 
	                         EM_RF_GSM_TX_TEST_MENUID,
	                         EM_RF_GSM_RX_TEST_MENUID,
	                         EM_RF_GSM_POWER_SCAN_MENUID,
					 		 SHOW, NONMOVEABLE, DISP_LIST, EM_RF_TEST_GSM_TEST, 0));
    /* GSM -- TX */
	ADD_APPLICATION_MENUITEM((EM_RF_GSM_TX_TEST_MENUID, EM_RF_TEST_GSM_MENUID, 0, 
				 		     SHOW, NONMOVEABLE, DISP_LIST, EM_RF_GSM_TX_TEST_TEXT, 0));
							 		
	/* GSM -- RX */						 		 
	ADD_APPLICATION_MENUITEM((EM_RF_GSM_RX_TEST_MENUID, EM_RF_TEST_GSM_MENUID, 0, 
							 SHOW, NONMOVEABLE, DISP_LIST, EM_RF_GSM_RX_TEST_TEXT, 0));

    /* GSM -- Power Scan */
	ADD_APPLICATION_MENUITEM((EM_RF_GSM_POWER_SCAN_MENUID, EM_RF_TEST_GSM_MENUID, 0, 
							 SHOW, NONMOVEABLE, DISP_LIST, EM_RF_GSM_POWER_SCAN_TEXT, 0));

#endif /* defined(__FLIGHT_MODE_SUPPORT__)  */

#if defined(__WIFI_SUPPORT__)
       /* WiFi */
	ADD_APPLICATION_MENUITEM((EM_RF_TEST_WIFI_MENUID, EM_RF_TEST_TOOL_MENUID, 4, 
	                                                        EM_RF_WIFI_TX_TESTS_MENUID,
	                                                        EM_RF_WIFI_CONT_PKT_RX_MENUID,
	                                                        EM_RF_WIFI_POWER_SAVE_MENUID,
	                                                        EM_RF_WIFI_REGISTER_ACCESS_MENUID,
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_TEST_WIFI_TEST, 0));
       /* WiFi -- TX */
       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_TX_TESTS_MENUID, EM_RF_TEST_WIFI_MENUID, 5, 
                                                               EM_RF_WIFI_TX_DAC_OFFSET_MENUID,
                                                               EM_RF_WIFI_TX_OUTPUT_POWER_MENUID,
                                                               EM_RF_WIFI_TX_CARRIER_SUPP_MENUID,
                                                               EM_RF_WIFI_TX_LOCAL_FREQUENCY_MENUID,
                                                               EM_RF_WIFI_TX_CONT_PKT_TX_MENUID,
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_TX_TESTS_TEXT, 0));

       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_TX_DAC_OFFSET_MENUID, EM_RF_WIFI_TX_TESTS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_TX_DAC_OFFSET_TEXT, 0));

       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_TX_OUTPUT_POWER_MENUID, EM_RF_WIFI_TX_TESTS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_TX_OUTPUT_POWER_TEXT, 0));

       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_TX_CARRIER_SUPP_MENUID, EM_RF_WIFI_TX_TESTS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_TX_CARRIER_SUPP_TEXT, 0));

       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_TX_LOCAL_FREQUENCY_MENUID, EM_RF_WIFI_TX_TESTS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_TX_LOCAL_FREQUENCY_TEXT, 0));

       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_TX_CONT_PKT_TX_MENUID, EM_RF_WIFI_TX_TESTS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_TX_CONT_PKT_TX_TEXT, 0));

       /* WiFi -- RX */
       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_CONT_PKT_RX_MENUID, EM_RF_TEST_WIFI_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_CONT_PKT_RX_TEXT, 0));

       /* WiFi -- POWER SAVE */
       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_POWER_SAVE_MENUID, EM_RF_TEST_WIFI_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_POWER_SAVE_TEXT, 0));

       /* WiFi -- Register */
       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_REGISTER_ACCESS_MENUID, EM_RF_TEST_WIFI_MENUID, 3, 
                                                               EM_RF_WIFI_REGISTER_MCR_MENUID,
                                                               EM_RF_WIFI_REGISTER_BBCR_MENUID,
                                                               EM_RF_WIFI_REGISTER_EEPROM_MENUID,
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_REGISTER_TEXT, 0));
       
       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_REGISTER_MCR_MENUID, EM_RF_WIFI_REGISTER_ACCESS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_REGISTER_MCR_TEXT, 0));

       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_REGISTER_BBCR_MENUID, EM_RF_WIFI_REGISTER_ACCESS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_REGISTER_BBCR_TEXT, 0));

       ADD_APPLICATION_MENUITEM((EM_RF_WIFI_REGISTER_EEPROM_MENUID, EM_RF_WIFI_REGISTER_ACCESS_MENUID, 0, 
							 		SHOW, NONMOVEABLE, DISP_LIST, EM_RF_WIFI_REGISTER_EEPROM_TEXT, 0));
       
#endif


    /********************** VOIP *********************/
#if defined(__VOIP__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    ADD_APPLICATION_MENUITEM2((EM_VOIP_MENNUID, ENGINEER_MODE_MENUID,
                            EM_VOIP_SETTINGS_MENU_ID,
                            EM_VOIP_SIP_SUPPORTED_MENU_ID,
                            EM_VOIP_SIP_REQUIRE_MENU_ID,
                            EM_VOIP_LOG_MENU_ID,
                            MENU_ITEM_END,
							SHOW, NONMOVEABLE, DISP_LIST, EM_VOIP_TEXT, 0));


    ADD_APPLICATION_MENUITEM((EM_VOIP_SETTINGS_MENU_ID, EM_VOIP_MENNUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_VOIP_SETTINGS_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_VOIP_SIP_SUPPORTED_MENU_ID, EM_VOIP_MENNUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_VOIP_SIP_SUPPORTED_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_VOIP_SIP_REQUIRE_MENU_ID, EM_VOIP_MENNUID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_VOIP_SIP_REQUIRE_TEXT, 0));

    ADD_APPLICATION_MENUITEM((EM_VOIP_LOG_MENU_ID, EM_VOIP_MENNUID, 2,
                            EM_VOIP_LOG_VIEW_MENU_ID,
                            EM_VOIP_LOG_SETTINGS_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST, EM_VOIP_LOG_TEXT, 0));
    ADD_APPLICATION_MENUITEM((EM_VOIP_LOG_VIEW_MENU_ID, EM_VOIP_LOG_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_VIEW, 0));
    ADD_APPLICATION_MENUITEM((EM_VOIP_LOG_SETTINGS_MENU_ID, EM_VOIP_LOG_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, EM_VOIP_LOG_SETTINGS_TEXT, 0));
    
    ADD_APPLICATION_MENUITEM((EM_VOIP_LOG_OPTION_MENU_ID, 0, 3,
                            EM_VOIP_LOG_OPTION_VIEW_MENU_ID,
                            EM_VOIP_LOG_OPTION_DELETE_MENU_ID,
                            EM_VOIP_LOG_OPTION_DELETE_ALL_MENU_ID,
							SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPTIONS, 0));
    ADD_APPLICATION_MENUITEM((EM_VOIP_LOG_OPTION_VIEW_MENU_ID, EM_VOIP_LOG_OPTION_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_VIEW, 0));
    ADD_APPLICATION_MENUITEM((EM_VOIP_LOG_OPTION_DELETE_MENU_ID, EM_VOIP_LOG_OPTION_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_DELETE, 0));
    ADD_APPLICATION_MENUITEM((EM_VOIP_LOG_OPTION_DELETE_ALL_MENU_ID, EM_VOIP_LOG_OPTION_MENU_ID, 0,
							SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_DELETE_ALL, 0));

#endif  /*  __VOIP__ */


}
#endif /* __MMI_ENGINEER_MODE__ */




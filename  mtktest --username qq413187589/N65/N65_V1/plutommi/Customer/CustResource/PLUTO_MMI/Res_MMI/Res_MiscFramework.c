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

	FILENAME	: Res_MiscFramework.c

  	PURPOSE		: Populate Resource for MiscFramework

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-15-2003

**************************************************************/
#include "mmi_features.h"
#include "CustomCfg.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "PersonalizationResDef.h"
#include "PowerOnChargerResDef.h"
#include "QuickAccessMenuItemResDef.h"
#include "SimDetectionResDef.h"

//micha0406
#include "CustResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

/**************************************************************

	FUNCTION NAME		: PopulatePersonalizationRes()

  	PURPOSE				: Function to populate PERSONALIZATION Resources

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/

void PopulatePersonalizationRes(void)
{
	ADD_APPLICATION_STRING2(STR_ENTER_NP_MSG,"Enter NP Code:","Enter NP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_ENTER_NSP_MSG,"Enter NSP Code:","Enter NSP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_ENTER_CP_MSG,"Enter CP Code:","Enter CP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_ENTER_SIMP_MSG,"Enter SIMP Code:","Enter SIMP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_ENTER_SP_MSG,"Enter SP Code:","Enter SP Code Screen MSG.");

	ADD_APPLICATION_STRING2(STR_WRONG_SP_MSG,"Wrong SP Code!","Wrong SP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_WRONG_CP_MSG,"Wrong CP Code!","Wrong CP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_WRONG_NSP_MSG,"Wrong NSP Code!","Wrong NSP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_WRONG_NP_MSG,"Wrong NP Code!","Wrong NP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_WRONG_SIMP_MSG,"Wrong SIMP Code!","Wrong SIMP Code Screen MSG.");

/* SML menu implementation */
#ifdef __MMI_SML_MENU__
	ADD_APPLICATION_STRING2(STR_ENTER_NSSP_MSG,"Enter NS-SP Code:","Enter NSSP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_ENTER_SIMC_MSG,"Enter SIM-C Code:","Enter SIMC Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_WRONG_NSSP_MSG,"Wrong NS-SP Code!","Wrong NSSP Code Screen MSG.");
	ADD_APPLICATION_STRING2(STR_WRONG_SIMC_MSG,"Wrong SIM-C Code!","Wrong SIMC Code Screen MSG.");

	ADD_APPLICATION_STRING2(STR_ID_CATEGORY_NP_LOCK,"Network Personalization","NP");
	ADD_APPLICATION_STRING2(STR_ID_CATEGORY_NSP_LOCK,"Network Subset Personalization","NSP");
	ADD_APPLICATION_STRING2(STR_ID_CATEGORY_CP_LOCK,"Corporate Personalization","CP");
	ADD_APPLICATION_STRING2(STR_ID_CATEGORY_SP_LOCK,"Service Provider Personalization","SP");
	ADD_APPLICATION_STRING2(STR_ID_CATEGORY_SIMP_LOCK,"SIM Personalization","SIMP");
	ADD_APPLICATION_STRING2(STR_ID_CATEGORY_NSP_SP_LOCK,"NS-SP Personalization","NS-SP");
	ADD_APPLICATION_STRING2(STR_ID_CATEGORY_SIMP_CP_LOCK,"SIM-C Personalization","SIM-C");

	ADD_APPLICATION_STRING2(STR_ID_SML_LOCK_MENU,"Lock","Lock");
	ADD_APPLICATION_STRING2(STR_ID_SML_UNLOCK_MENU,"Unlock","Unlock");
	ADD_APPLICATION_STRING2(STR_ID_SML_ADD_MENU,"Add Data","Add");
	ADD_APPLICATION_STRING2(STR_ID_SML_REMOVE_MENU,"Remove Data","Remove");
	ADD_APPLICATION_STRING2(STR_ID_SML_DEACTIVATE_MENU,"Permanent Unlock","Deactivate");

	ADD_APPLICATION_STRING2(STR_ID_SML_REBOOT_MSG,"Need to reboot now!","Reboot");
	ADD_APPLICATION_STRING2(STR_ID_SML_QUREY_MSG,"Automatically get data from SIM?","Query");
	ADD_APPLICATION_STRING2(STR_ID_SML_BLOCK_MSG,"Blocked!","Blocked");
	ADD_APPLICATION_STRING2(STR_ID_SML_NO_EF_GID,"No EF GID in this SIM!","No GID");
	ADD_APPLICATION_STRING2(STR_ID_SML_INVALID_DATA,"Invalid Data!","Invalid Data");
	ADD_APPLICATION_STRING2(STR_ID_SML_AUTOKEY_CONFIRM,"Automatically generate key?","Auto Key");
	ADD_APPLICATION_STRING2(STR_ID_LAST_RETRY_MSG,"WARNING!\n Last try!","Last try");
	ADD_APPLICATION_STRING2(STR_ID_GENERAL_RETRY_MSG,"Invalid key entered!","Invalid key");
	ADD_APPLICATION_STRING2(STR_ID_UNLOCK_FIRST_MSG,"Unlock the category first!","Unlock first");
	ADD_APPLICATION_STRING2(STR_ID_EMPTY_CATEGORY_MSG,"No category available!","No category available");
	ADD_APPLICATION_STRING2(STR_ID_NO_RECORD_MSG,"No space to add!","No space to add");
	ADD_APPLICATION_STRING2(STR_ID_NO_DATA_MSG,"No data!","No data");

	ADD_APPLICATION_STRING2(STR_ID_SML_CAT_LOCKED,"This category is locked!","Locked");
	ADD_APPLICATION_STRING2(STR_ID_SML_CAT_UNLOCKED,"This category is unlocked!","Unlocked");
	ADD_APPLICATION_STRING2(STR_ID_SML_CAT_AUTOLOCKED,"This category is in auto lock state!","Auto lock");

	ADD_APPLICATION_STRING2(STR_ID_SML_AUTOLOCKED,"This SIM is auto locked!","Auto lock");
	ADD_APPLICATION_STRING2(STR_ID_SML_FAIL_TO_AUTOLOCK,"Auto lock failed!","Auto lock");

	ADD_APPLICATION_STRING2(STR_ID_SML_NP_DATA,"MCC+MNC","IMSI");
	ADD_APPLICATION_STRING2(STR_ID_SML_NSP_DATA,"MCC+MNC+HLR","IMSI");
	ADD_APPLICATION_STRING2(STR_ID_SML_SP_DATA,"GID1","GID1");
	ADD_APPLICATION_STRING2(STR_ID_SML_CP_DATA,"GID2","GID2");
	ADD_APPLICATION_STRING2(STR_ID_SML_SIMP_DATA,"IMSI","IMSI");
#endif
}

/**************************************************************

	FUNCTION NAME		: PopulateChgrPwrOnScrRes(void)

  	PURPOSE				: 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
	
void PopulateChgrPwrOnScrRes()
{
	//on reference phone ADD_APPLICATION_STRING(STR_CHARGER_POWER_ON,"Battery Charging");
	//on reference phone ADD_APPLICATION_STRING(STR_CHARGER_CHARGING_COMPLETE,"Charging Complete");

	ADD_APPLICATION_IMAGE2(IMG_CHARGER_POWER_ON,CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\CHARGING.gif","	Image Associated with Power On by Charger Screen");
	ADD_APPLICATION_IMAGE2(IMG_BATTERY_FULL_CHARGED,CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\charger\\\\CHARGF.bmp","	Image Associated with Charger Fully charged");

//MTK Leo end

	//ADD_APPLICATION_STRING2(STR_CHARGER_POWER_ON,"Charging","Message for Power On by Charger Screen");
	//ADD_APPLICATION_STRING2(STR_BATTERY_FULL_CHARGED,"Charge Complete","String Associated with Battery Fully Charged Screen.");
	ADD_APPLICATION_STRING2(STR_OVER_VOLTAGE_BATTERY,"Warning!Over Battery Voltage!!","String Associated with Over Voltage Screen");
	ADD_APPLICATION_STRING2(STR_OVER_TEMP_BATTERY,"Warning! Over Battery Temperature!!","String Associated with Over Temperature Screen");
	ADD_APPLICATION_STRING2(STR_LOW_BATTERY,"Battery Low","String Associated with Low battery Screen");
	ADD_APPLICATION_STRING2(STR_INVALID_BATTERY,"Warning! Invalid Battery!","String Associated with Invalid battery Screen");
	ADD_APPLICATION_STRING2(STR_OVER_CURRENT_BATTERY,"Warning! Over Charge Current!","String Associated with Over Charger current Screen"); //MTK Add, Robin 0924
	ADD_APPLICATION_STRING2(STR_CHARGER_CONNECTED,"Charger Connected!","String Displyed when Charger Connected.");
	ADD_APPLICATION_STRING2(STR_CHARGER_REMOVED,"Charger Removed!","String Displyed when Charger Removed.");
      
	ADD_APPLICATION_STRING2(STR_USB_CHARGER_CONNECTED,"USB Connected!","String Displyed when Charger Connected.");
	ADD_APPLICATION_STRING2(STR_USB_CHARGER_REMOVED,"USB Removed!","String Displyed when Charger Removed.");
      
	ADD_APPLICATION_STRING2(STR_CHARGING_TIMEOUT,"Warning! Charging Fail!","String Displyed when Charging Timeout.");
	ADD_APPLICATION_STRING2(STR_INVALID_CHARGER,"Warning! Invaild Charger!","String Displyed when Invalid Charger.");
	ADD_APPLICATION_STRING2(STR_LOW_TEMP_BATTERY,"Warning! Low Battery Temperature!","String Displyed when Low Temperature.");
	ADD_APPLICATION_STRING2(STR_LOW_BATTERY_SHUTDOWN,"Low Battery Shutdown!","String Displyed when Low battery shutdown.");
	//ADD_APPLICATION_STRING2(STR_LOW_CURRENT_BATTERY,"Warning! Low Charge Current!","String Displyed when charge current is low.");	
	ADD_APPLICATION_STRING2(STR_CHARGE_BAD_CONTACT,"Warning! Bad Contact -Charger!","String Displyed when charger bad contact.");	
	ADD_APPLICATION_STRING2(STR_BATTERY_BAD_CONTACT,"Warning! Bad Contact -Battery!","String Displyed when battery bad contact.");
	//MTK add Robin 1025 for Low battery MT prohibit
        ADD_APPLICATION_STRING2(STR_LOW_BATTERY_MT_PROHIBIT,"Battery Low! Not able to dial!","String Displyed when battery low, not able to MT.");	
        //MTK end

#ifdef __MMI_SUBLCD__
	//ADD_APPLICATION_STRING2(STR_SUBLCD_ABNORMAL_BATTERY,"Warning! Abnormal Battery Status","#NO_TRANS# String Associated with Abnormal Battery Status on Sub LCD");
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_CHARGER_POWER_ON,CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_char.gif","	Image Associated with SubLCD for Power On Charger Animation Screen.");
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_CHARGING_COMPLETE,CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_charok.bmp","	SubLCD Image Associated with Charging Complete.");
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_ABNORMAL_BATTERY,CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\SB_charwg.bmp","	SubLCD Image Associated with abnormal battery Screen.");
#endif

}

/**************************************************************

	FUNCTION NAME		: PopulateQuickAccessMenu()

  	PURPOSE				: Populate Quick Access Menu Data

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: This function is developer specific call to automate
						  default resource data population 

**************************************************************/
void PopulateQuickAccessData(void)
{
	/*Populate Menu Items */

	ADD_APPLICATION_STRING2(KPAD_SCR_UNLOCKED_MESSAGE_RUNNING_STR,"KeyPad Unlocked!","KeyPad Unlock Scr Caption.");
	ADD_APPLICATION_IMAGE2(IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE,CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\notification\\\\N_KEY.PNG","Img Associated with Keypad Lock Help Message Screen.");

#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__  //Robin 1223
	ADD_APPLICATION_STRING2(KPAD_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR,"Press # to Unlock Keypad","Key Pad Unlock Running Text.");
   #if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)				
	ADD_APPLICATION_STRING2(KPAD_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR,"Press RSK to Unlock Keypad","Key Pad Unlock Running Text.");
   #endif
#else  /* __MMI_KEYPAD_LOCK_PATTERN_2__ */
	ADD_APPLICATION_STRING2(KPAD_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR2,"Press * to Unlock Keypad","Key Pad Unlock Running Text.");
   #if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)				
	ADD_APPLICATION_STRING2(KPAD_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR2,"Press LSK to Unlock Keypad","Key Pad Unlock Running Text.");
   #endif
#endif
#ifdef __MMI_TOUCH_SCREEN__
	ADD_APPLICATION_STRING2(TOUCH_SCR_UNLOCKED_FIRST_HELP_MESSAGE_RUNNING_STR,"Press SEND key  to Unlock Keypad and Screen","Key Pad Unlock Running Text.");
	ADD_APPLICATION_STRING2(TOUCH_SCR_UNLOCKED_HELP_MESSAGE_RUNNING_STR,"Click Here to Unlock", "prompt user to click the image");
	ADD_APPLICATION_IMAGE2(IMG_TOUCH_SCR_PEN_CLICK_AREA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Calibration\\\\CALI_SMALL.gif","click the image to unlock screen");
#endif
}


/**************************************************************


	FUNCTION NAME		: PopulateSimDetectionMenuRes()

  	PURPOSE				: To Initialize the resources for the 
						  idle app 

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/

void PopulateSimDetectionMenuRes(void)
{

//micha0923, #169 begin
	ADD_APPLICATION_STRING2(STR_SIM_INVALID_SIM_TITLE,"Invalid SIM","Invalid SIM title.");
	ADD_APPLICATION_STRING2(STR_SIM_INVALID_SIM_TXT,"SIM card registration failed.","Invalid SIM text.");
//micha1217	
	ADD_APPLICATION_STRING2(STR_SIM_INVALID_SIM_SELECT_NETWORK_TXT,"Not avaliable for invalid SIM.","Invalid SIM network selection text.");
//micha0923, #169 begin

//	ADD_APPLICATION_STRING2(STR_SIM_INSERTION_RSK,"SOS","	RSK SOS screen String");
//	ADD_APPLICATION_IMAGE2(IMG_SIM_INSERTION_RSK,"..\\\\IMAGES\\\\EmptyImage.bmp","	Image Associated with Insert Sim Screen RSK.");
	ADD_APPLICATION_STRING2(STR_SIM_INSERTION_MSG,"Insert SIM","Insert the SIM card MEssage for SIM screen.");

	ADD_APPLICATION_STRING2(STR_SIM_ACCESS_ERROR_MSG,"SIM Access Error","SIM Access Error Message for SIM screen.");
#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_STRING2(STR_SUBLCD_SIM_INSERTION_MSG,"Insert SIM","#NO_TRANS# Insert the SIM card MEssage for SubLCD screen.");
	ADD_APPLICATION_STRING2(STR_SUBLCD_SIM_ACCESS_ERROR_MSG,"SIM Access Error","SIM Access Error Message for SIM screen.");
#endif

//	ADD_APPLICATION_STRING2(STR_SIM_BLOCK_RSK,"SOS"," Block SIM	RSK SOS screen String");
//	ADD_APPLICATION_IMAGE2(IMG_SIM_BLOCK_RSK,"..\\\\IMAGES\\\\EmptyImage.bmp","	Image Associated with Block Sim Screen RSK.");
	ADD_APPLICATION_STRING2(STR_SIM_BLOCK_MSG,"SIM Blocked","Blocked SIM card Message for SIM screen.");
#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_STRING2(STR_SUBLCD_SIM_BLOCK_MSG,"SIM Blocked","#NO_TRANS# Blocked SIM card Message for SUBLCD screen.");
#endif
	ADD_APPLICATION_STRING2(STR_ENTER_PIN_MSG,"Enter PIN:","Enter Pin Screen MSG.");
#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENTER_PIN_MSG,"Enter PIN","#NO_TRANS# Enter Pin SUB LCD Screen MSG.");
#endif
	ADD_APPLICATION_IMAGE2(IMG_ENTER_PIN_CAPTION,CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp","Img Associated with Enter PIN Caption");
//	ADD_APPLICATION_STRING2(STR_ENTER_PIN_RSK,"SOS","Make SOS Calls");
//	ADD_APPLICATION_IMAGE2(IMG_ENTER_PIN_RSK,"..\\\\IMAGES\\\\EmptyImage.bmp","Img Associated with Enter PIN RSK.");

	/* Etry Scr Entr PUK*/
#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENTER_PUK_MSG, "Enter PUK","#NO_TRANS# Enter PUK SUBLCD Scr Caption.");
#endif
	ADD_APPLICATION_STRING2(STR_ENTER_PUK_MSG,"Enter PUK:","Enter PUK Screen MSG.");
//	ADD_APPLICATION_STRING2(STR_ENTER_PUK_RSK, "SOS", "Make SOS Calls.");

	/*Entry Scr PIN incorrect*/
	ADD_APPLICATION_STRING2(STR_INCORRECT_PIN, "Wrong PIN!","Running text on PIN comparison screen.");

	/*Entry Scr PUK incorrect*/
	ADD_APPLICATION_STRING2(STR_INCORRECT_PUK, "Wrong PUK!","Running text for incorrct PUK.");

	/*Entry Scr PIN blocked */
	ADD_APPLICATION_STRING2(STR_PIN_BLOCKED_PUK, "PIN Blocked!","Running text on PIN Blocked Screen.");

	/*Enty Scr Enter New PIN first Time */
	ADD_APPLICATION_STRING2(STR_ENTER_NEW_PIN_MSG,"Enter New PIN:","Enter New Pin First Time Screen MSG.");
	/*Enty Scr Enter New PIN Again ie second Time */
	ADD_APPLICATION_STRING2(STR_ENTER_PIN_AGAIN_MSG,"Enter Again:","Confirm Pin Screen MSG.");

	/*Enty Scr Enter Pins don't match */
	ADD_APPLICATION_STRING2(STR_PIN_DONOT_MATCH, "Different PIN code!","Running Text of PIN Mismatch Screen.");

	/*Making SOS call , you need to display Call and Drop on the Scr MakEmergencyCall*/
	/* Robin 0726, Use Global defination */
	//ADD_APPLICATION_STRING2(KPAD_SCR_EMERGENCY_CALL_PIN_PUK_CANCEL, "Clear","RSK ssociated with Drop emergency Call.");	

	/* Phone unlock*/
	ADD_APPLICATION_STRING2(STR_ENTER_PHONELOCK_MSG,"Enter Phone Lock Code:","Enter Phone Lock Screen MSG.");
#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENTER_PHONELOCK_MSG, "Enter Code","#NO_TRANS# Enter PhoneLock SUBLCD Scr MSG.");
#endif
	/* Incorrect Phone Unlock */
	ADD_APPLICATION_STRING2(STR_INCORRECT_PHONELOCK, "Wrong Password!" ,"Incorrect Phone Lock Running text.");

	ADD_APPLICATION_STRING2(STR_CODE_VERIFIED, "Code Accepted" ,"String associated with Code Verified Screen.");

	ADD_APPLICATION_STRING2(STR_RSK_SOS, "SOS","RSK ssociated with All Pwd Req Screens.");	

	/* Entry Screen No Service Available*/
	
	ADD_APPLICATION_STRING2(STR_NO_SERVICE_RUNNING_TEXT,"Service Not Available!","No Service Running Text.");

	ADD_APPLICATION_STRING2(STR_NOT_SOS_NUMBER,"Emergency Call Only!","Not a SOS number screen Text.");

	/* Entry Scr for Invalid PUK , PIN , Phone Lock Length */
	ADD_APPLICATION_STRING2(STR_INVALID_PINPUKPLOCK_LENGTH_RUNNING_TEXT,"Invalid Length!","Running Text on Incorrect PIN/PUK length.");

	ADD_APPLICATION_STRING2(STR_DIAL_EMERGENCY_NUMBER,"Dial Emergency Number","Text on SOS Screen.");

	ADD_APPLICATION_STRING2(STR_INCORRECT_SSC,"Not Allowed!","Error Msg for Wrong SSC from Enter PUK Screen.");

    //MTK modified, Robin 1011, add blank in the tail of string

//Robin 1217, micha1119	
	ADD_APPLICATION_STRING2(STR_LIMITED_SERVICE,"Emergency","Limited Service String.");
    //MTK end

	ADD_APPLICATION_STRING2(STR_NO_SERVICE,"No Service","No Service String.");

	/*image assciated with welcome screen*/
	#ifdef LOW_COST_SUPPORT
	ADD_APPLICATION_IMAGE3(IMG_WELCOME_SCR,	CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo.bmp","Img Associated with Welcome Screen.");
	#else
	ADD_APPLICATION_IMAGE2(IMG_WELCOME_SCR,	CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\Greeting\\\\GREET."__MMI_RES_TYPE_ACTIVE_SCREEN__,"Img Associated with Welcome Screen.");
	#endif
//	ADD_APPLICATION_IMAGE2(IMG_SIM_INSERTION_MSG,CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\popupPage\\\\PP_WARN.bmp","	Image Associated with Insert Sim Screen MSG.");
#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif

#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_IMAGE2(IMG_SUBLCD_POWER_ON_SCR,	CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_ON.gif","Img Associated with SUBLCD Power On Screen.");
#endif

#if defined(  __FS_CHECKDRIVE_SUPPORT__ )
	ADD_APPLICATION_STRING2(STR_NAND_CHECK_TITLE,"Disk check","NAND Check");
	ADD_APPLICATION_STRING2(STR_NAND_CHECK,"Proceed disk check?","NAND Check?");
	ADD_APPLICATION_STRING2(STR_NAND_CHECK_PROCESSING,"Processing...","Processing");
#endif

	ADD_APPLICATION_STRING2(STR_ID_SIM_REFRESH,"SIM card is refreshing...","SIM REFRESH");

	ADD_APPLICATION_STRING2(STR_ID_NAND_QUOTA_OVER_DISK,"Quota over disk!","Quota over disk");
	ADD_APPLICATION_STRING2(STR_ID_NAND_QUOTA_USAGE_WARNING,"Quota usage warning!","Quota usage warning");
	ADD_APPLICATION_STRING2(STR_ID_NAND_DEVICE_NOT_SUPPORTED,"NAND device not support!","NAND device not support");
	ADD_APPLICATION_STRING2(STR_ID_NAND_USER_DRIVE_CORRUPT,"User drive is corrupt! Format?","User drive corrupt");
	ADD_APPLICATION_STRING2(STR_ID_NAND_SYSTEM_DRIVE_CORRUPT,"System drive is corrupt! Format?","System drive corrupt");
	ADD_APPLICATION_STRING2(STR_ID_NAND_VERSION_MISMATCH,"FDM version mismatch","FDM version mismatch");

	/*POPULATE OPTIONS MENU*/
	populateOptionMenu();
//MTK added by Joy for Aphorism compile option
//#if defined(MTK) || defined(KLM)
#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif
//MTK end	
	PopulatePLMNList();
	PopulatePersonalizationRes();


}

/**************************************************************

	FUNCTION NAME		: populateOptionMenu(void)

  	PURPOSE				: populating various resources



	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void populateOptionMenu(void)
{
#if defined(__MMI_VERSION_2__)
   ADD_APPLICATION_MENUITEM((MENU_SIM_OPTION_ID,0,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	1+
#endif
#ifndef __DISABLE_SHORTCUTS_MENU__
    1+
#endif
	8,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
		MAIN_MENU_OPTION_AVZONE_MENUID,
#endif
		MAIN_MENU_PHONEBOOK_NO_SIM_MENUID,
		MAIN_MENU_SETTINGS_NO_SIM_MENUID, /* diamond, 2005/12/23 Phone setup in option menu */
		MAIN_MENU_MULTIMEDIA_MENUID,
		MAIN_MENU_FILE_MNGR_MENUID,
		MAIN_MENU_FUNANDGAMES_MENUID,
		MAIN_MENU_PROFILES_MENUID,
		MAIN_MENU_ORGANIZER_MENUID,
		MAIN_MENU_EXTRA_MENUID,
#ifndef __DISABLE_SHORTCUTS_MENU__
		EXTRA_SHORTCUTS_MENUID,
#endif
		SHOW,NONMOVEABLE,DISP_LIST,STR_GLOBAL_OPTIONS,0));
#else /* __MMI_VERSION_2__ */
#ifdef __MMI_OP01_MENU_NOSIM_LIST__
	 ADD_APPLICATION_MENUITEM((MENU_SIM_OPTION_ID,0,
		8,
		MAIN_MENU_PHONEBOOK_NO_SIM_MENUID,
		MAIN_MENU_SETTINGS_NO_SIM_MENUID, /* diamond, 2005/12/23 Phone setup in option menu */
		MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID,
		MAIN_MENU_FILE_MNGR_MENUID,
		MAIN_MENU_FUNANDGAMES_MENUID,
		MAIN_MENU_PROFILES_MENUID,
		MAIN_MENU_ORGANIZER_NO_SIM_MENUID,
		MAIN_MENU_EXTRA_MENUID,
		SHOW,NONMOVEABLE,DISP_LIST,STR_GLOBAL_OPTIONS,0));
#else /* __MMI_OP01_MENU_NOSIM_LIST__ */
	ADD_APPLICATION_MENUITEM((MENU_SIM_OPTION_ID,0,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	1+
#endif
#ifdef __MMI_TOUCH_SCREEN__
	1+
#endif
	5,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
		MAIN_MENU_OPTION_AVZONE_MENUID,
#endif
		MAIN_MENU_PHONEBOOK_NO_SIM_MENUID,
		MAIN_MENU_MULTIMEDIA_MENUID,
		MAIN_MENU_FUNANDGAMES_MENUID, MAIN_MENU_PROFILES_MENUID, MAIN_MENU_ORGANIZER_MENUID,
#ifdef __MMI_TOUCH_SCREEN__
		MENU_SETTING_CALIBRATION,
#endif		
		SHOW,NONMOVEABLE,DISP_LIST,STR_GLOBAL_OPTIONS,0));
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */
#endif /* __MMI_VERSION_2__ */
	ADD_APPLICATION_STRING2(STR_SIM_OPTION_CAPTION	,"Menu Options","caption string of option menu.");

#ifdef __MMI_OP01_MENU_NOSIM_LIST__
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_PHONEBOOK_ICON,   CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_PB.pbm", "phonebook icon for sim option menu");
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_FUNANDGAMES_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_FG.pbm", "fun and game icon for sim option menu");
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_ORGANIZER_ICON,   CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_OR.pbm", "organizer icon for sim option menu");
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_SETTINGS_ICON,    CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_ST.pbm", "setting icon for sim option menu");
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_PROFILES_ICON,    CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_PR.pbm", "profile icon for sim option menu");
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_MULTIMEDIA_ICON,  CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_MM.pbm", "multimedia icon for sim option menu");
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_FILEMNGR_ICON,    CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_FM.pbm", "file manager icon for sim option menu");
    ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_EXTRA_ICON,       CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_EX.pbm", "extra icon for sim option menu");
#else /* __MMI_OP01_MENU_NOSIM_LIST__ */
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_PHONEBOOK_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_PB.pbm", "phonebook icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_MESSAGES_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_MG.pbm", "message icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_FUNANDGAMES_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_FG.pbm", "fun and game icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_ORGANIZER_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_OR.pbm", "organizer icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_SETTINGS_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_ST.pbm", "setting icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_PROFILES_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_PR.pbm", "profile icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_SHORTCUTS_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_SC.pbm", "shortcut icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_SERVICES_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_SV.pbm", "service icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_CALL_HISTORY_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_CA.pbm", "call history icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_MULTIMEDIA_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_MM.pbm", "multimedia icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_FILEMNGR_ICON,	CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_FM.pbm", "file manager icon for sim option menu");
	ADD_APPLICATION_IMAGE2(IMG_ID_OPTION_MENU_EXTRA_ICON,		CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_EX.pbm", "extra icon for sim option menu");
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */
}

/**************************************************************

	FUNCTION NAME		: PopulateAphorismList(void)

  	PURPOSE				: populating various resources



	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 
	
**************************************************************/
void PopulateAphorismList(void)
{
//MTK added by Joy for Aphorism compile option
//#if defined(MTK) || defined(KLM)	
	#if defined(__MMI_APHORISM__)
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
//MTK end	
}

/**************************************************************

	FUNCTION NAME		: PopulatePLMNList(void)

  	PURPOSE				: populating PLMN list



	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void PopulatePLMNList(void)
{
/* Do NOT modify the following line. It is a keyword for the PLMN automatic create tool */
/* plmncreate.exe: populate PLMN strings */
}

#endif



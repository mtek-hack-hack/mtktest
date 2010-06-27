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
 * Res_VRSI.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for populating resource of vocie recognition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VRSI__)

#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "GlobalDefs.h"             /* for global string */
#include "VRSIResDef.h"

typedef enum 
{
	VRSI_MENU_ENUM_RCG_ENABLE,
#if defined(__MMI_VRSI_TRAIN_TAG__)
	VRSI_MENU_ENUM_TRAIN_TAG,
#endif
#if defined(__MMI_VRSI_DIGIT_ADAPT__)
	VRSI_MENU_ENUM_DIGIT_ADAPT,
#endif
	VRSI_MENU_ENUM_TOTAL
} vrsi_menu_enum;


extern void PopulateVRSITrainTagRes(void);

/*****************************************************************************
* FUNCTION
*  PopulateVRSDRes
* DESCRIPTION
*   Populate All resource data for voice recognition Applications
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
void PopulateVRSIRes(void)
{
	/*Multimedia Menu Item*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_SETTING, MAIN_MENU_MULTIMEDIA_MENUID, 0,
		SHOW, NONMOVEABLE, 0, STR_ID_VRSI_SETTING, IMG_ID_VRSI_APP ));

	/*VRSI Setting Main Menu*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_SETTING_MAIN,0, VRSI_MENU_ENUM_TOTAL,
		MENU_ID_VRSI_SETTING_RCG,
		//MENU_ID_VRSI_SETTING_ANSWER_CALL,
#if defined(__MMI_VRSI_TRAIN_TAG__)		
		MENU_ID_VRSI_SETTING_TRAIN_TAG,
#endif
#if defined(__MMI_VRSI_DIGIT_ADAPT__)
		MENU_ID_VRSI_SETTING_DIGIT_ADAPT,
#endif		
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OK,IMG_GLOBAL_OK));

	/*VRSI Setting Sub Main Item*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_SETTING_RCG,MENU_ID_VRSI_SETTING_MAIN,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_ENABLE_RCG, 0));
#if defined(__MMI_VRSI_TRAIN_TAG__)
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_SETTING_TRAIN_TAG,MENU_ID_VRSI_SETTING_MAIN,5,
		MENU_ID_VRSI_TRAIN_NAME_LIST,
		MENU_ID_VRSI_TRAIN_SHORTCUT_LIST,
		MENU_ID_VRSI_TRAIN_CITY_LIST,		
		MENU_ID_VRSI_TRAIN_DELETE_ALL,
		MENU_ID_VRSI_TRAIN_TAG_STATUS,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_TRAIN_TAG, 0));
#endif
#if defined(__MMI_VRSI_DIGIT_ADAPT__)
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_SETTING_DIGIT_ADAPT,MENU_ID_VRSI_SETTING_MAIN,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_DIGIT_ADAPT, 0));
#endif		

	/*Add Strings*/
	ADD_APPLICATION_STRING2(STR_ID_VRSI_APP					,"Voice Command"				,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_SETTING				,"Voice Command Setting"	,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_INIT_PROCESSING		,"VR initializing"			,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_PROCESSING		,"Phone Book Processing Wait And Retry"			,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_ENABLE_RCG		,"Enable Recognition"			,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TRAIN_TAG		,"Train SD Tag"						,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DIGIT_ADAPT		,"Digit Adaptation"				,"Voice Command App String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_HELP		,"Help"				,"Voice Command App String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_REDIAL_DIALED		,"Dialed number"				,"Voice Command App String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_REDIAL_MISSED		,"Missed call"				,"Voice Command App String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_REDIAL_RECEIVED		,"Received call"				,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_PROFILE_SILENT		,"Slient Mode"				,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_SHORTCUT_ITEM		,"Shortcut Item"				,"Voice Command App String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_CITY_ITEM		,"City Name"				,"Voice Command App String");		

	/*Add Prompt String*/
	ADD_APPLICATION_STRING2(STR_ID_VRSI_HELP_PROMPT						,"Available commands: Dial, Query, Digit Dial, Exit, Help."				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR1_PROMPT					,"Please speak command"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR2_PROMPT					," has multiple numbers,"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE		,"mobile"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME			,"home"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE		,"office"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX			,"fax"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR2_PROMPT_CANCEL		," or cancel"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR3_PROMPT					," Found several "				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR3_PROMPT_SELECT		," please choose one entry"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR4_PROMPT					," Confirm, Cancel, or Reentry"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DIGIT_PROMPT						,"Please speak digit"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DIGIT_ADAPT_PROMPT				,"Please speak digit on screen after beep"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TRAIN_TAG_PROMPT1				,"Please speak after beep"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TRAIN_TAG_PROMPT2				,"Please speak again after beep"				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DIAL_PROMPT						,"Dial "				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DIALING_PROMPT						,"Dialing..."				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TTS_INVALID_CMD					,"Invalid command"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TTS_OPERATE_BY_KEY				,"Please use keypad to operate"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TTS_RECORD						,"Record "				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TTS_RECORD_NO_DATA			," has no data, please say again."				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TTS_NUMBER_NO_DATA				," has no number, please say again."				,"Voice Command Prompt String");	

	ADD_APPLICATION_STRING2(STR_ID_VRSI_TTS_FOUND				,"Found "				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_GRAMMAR5_PROMPT				," select, dial, previous, next, or reenter. "				,"Voice Command Prompt String");		
	ADD_APPLICATION_STRING2(STR_ID_VRSI_SPEAK_AGAIN_PROMPT				,"Please speak again"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_NO_NUMBER_PROMPT				,"has no number"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_SWITCHED_PROMPT				,"Switched to"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_CANT_SWITCH_PROMPT				,"Can not switch to"				,"Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_OPENING_PROMPT				,"is opening..."				,"Voice Command Prompt String");	

	ADD_APPLICATION_STRING2(STR_ID_VRSI_CITY_TIME			,"Current Time"				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_CITY_TIME_AM		,"AM"				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_CITY_TIME_PM		,"PM"				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_CITY_TIME_HOUR	," "				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_CITY_TIME_MINUTE	," "				,"Voice Command Prompt String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DELETE_ALL_QUESTION,    "Delete all?","Voice Command Prompt String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DELETE_QUESTION,        "Delete?", "Voice Command Promt String");
	/*Add Error Message String*/
	ADD_APPLICATION_STRING2(STR_ID_VRSI_INIT_FAIL,	"VR init fail, please try again."				,"Voice Command Error Message");		
	ADD_APPLICATION_STRING2(STR_ID_VRSI_LANG_NOT_SUPPORT		,"Language not support"				,"Voice Command Error Message");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_DIAL_DIGIT_TOO_LONG		,"Number too long"				,"Voice Command Error Message");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_NOT_READY		,"VR not ready"				,"Voice Command Error Message");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_RCG_NOT_FOUND		,"Not Found."				,"Voice Command Error Message");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_SD_TAG_FULL		,"SD Tag Full"				,"Voice Command Error Message");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_BUSY		,"VR Busy"				,"Voice Command Error Message");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_ALREADY_IN_MODE		,"Already in the mode"				,"Voice Command Error Message");

	/*Add Image*/
	ADD_APPLICATION_IMAGE2(IMG_ID_VRSI_APP,CUST_IMG_PATH"\\\\MainLCD\\\\VoiceRecg\\\\SB_Speak.pbm","Main Icon for Voice Command App");
	ADD_APPLICATION_IMAGE2(IMG_ID_VRSI_RECORDING,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\Speaking"__MMI_RES_TYPE_POPUP_SCREEN__,"Sound Recorder Recording");	
	ADD_APPLICATION_IMAGE2(IMG_ID_VRSI_SHORTCUT,CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Shortcut\\\\SB_SC.pbm","Shortcut icon");	


	/*Populate other resources*/
	PopulateVRSITrainTagRes();
}


void PopulateVRSITrainTagRes(void)
{
#if defined(__MMI_VRSI_TRAIN_TAG__)
	/*Train SD Tag Option Menu*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_NAME_LIST,MENU_ID_VRSI_SETTING_TRAIN_TAG,0,
	SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_NAME_LIST, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_SHORTCUT_LIST,MENU_ID_VRSI_SETTING_TRAIN_TAG,0,
	SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_SHORTCUT_LIST, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_CITY_LIST,MENU_ID_VRSI_SETTING_TRAIN_TAG,0,
	SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_CITY_LIST, 0));	
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_DELETE_ALL,MENU_ID_VRSI_SETTING_TRAIN_TAG,0,
	SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_DELETE_ALL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_TAG_STATUS,MENU_ID_VRSI_SETTING_TRAIN_TAG,0,
	SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_TRAIN_TAG_STATUS, 0));	

	/*Add Strings*/
	ADD_APPLICATION_STRING2(STR_ID_VRSI_NAME_LIST					,"Phonebook List"				,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_SHORTCUT_LIST					,"Shortcut List"				,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_CITY_LIST					,"City List"				,"Voice Command App String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_TRAIN_TAG_STATUS				,"SD Tag Status"	,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSI_PLAYBACK				,"Change"	,"Voice Command App String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSI_REFRESH_SIM				,"SIM changed, delete voice tag in SIM?"	,"Voice Command App String");	


	/*Train Name List Main Menu*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_OPTION_MAIN,0,3,
		MENU_ID_VRSI_TRAIN_OPTION_ADD,
		MENU_ID_VRSI_TRAIN_OPTION_DEL,
		MENU_ID_VRSI_TRAIN_OPTION_PLAY,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OK,IMG_GLOBAL_OK));

	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_OPTION_ADD,MENU_ID_VRSI_TRAIN_OPTION_MAIN,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_ADD, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_OPTION_DEL,MENU_ID_VRSI_TRAIN_OPTION_MAIN,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_DELETE, 0));	
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSI_TRAIN_OPTION_PLAY,MENU_ID_VRSI_TRAIN_OPTION_MAIN,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSI_PLAYBACK, 0));	
#endif		
}


#endif


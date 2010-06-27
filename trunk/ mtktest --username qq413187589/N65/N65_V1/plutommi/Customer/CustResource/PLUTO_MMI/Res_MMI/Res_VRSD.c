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
 * Res_VRSD.C
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "GlobalDefs.h"             /* for global string */
#include "VRSDResDef.h"

typedef enum 
{
#if defined (__MMI_VRSD_DIAL__)
	VRSD_MENU_ENUM_DIAL,
#endif
#if defined (__MMI_VRSD_REDIAL__)
	VRSD_MENU_ENUM_REDIAL,
#endif
#if defined(__MMI_VRSD_PROFILE__)
	VRSD_MENU_ENUM_PROFILE,
#endif 	
#if defined(__MMI_VRSD_AUDPLAYER__)
	VRSD_MENU_ENUM_AUDPLAYER,
#endif
#if defined(__MMI_VRSD_SHORTCUT__)
	VRSD_MENU_ENUM_SHORTCUT,
#endif
	VRSD_MENU_ENUM_TOTAL
} vrsd_menu_enum;

extern void PopulateVRSDMainRes(void);
extern void PopulateVRSDDialRes(void);
extern void PopulateVRSDRedialRes(void);
extern void PopulateVRSDProfileRes(void);
extern void PopulateVRSDAudPlayerRes(void);
extern void PopulateVRSDShortcutRes(void);

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
#if defined(__MMI_VRSD__)
void PopulateVRSDRes(void)
{
	/*Populate Voice Recognition and Main Resource*/
	PopulateVRSDMainRes();

	/*Populate Voice Dial Application Resource*/
#if defined(__MMI_VRSD_DIAL__)
	PopulateVRSDDialRes();
#endif

	/*Populate Voice Redial Application Resource*/
#if defined(__MMI_VRSD_REDIAL__)
	PopulateVRSDRedialRes();
#endif

	/*Populate Voice Profile Application Resource*/
#if defined(__MMI_VRSD_PROFILE__)	
	PopulateVRSDProfileRes();
#endif	

	/*Populate Voice Audio Player Application Resource*/
#if defined(__MMI_VRSD_AUDPLAYER__)	
	PopulateVRSDAudPlayerRes();
#endif	

	/*Populate Voice Shortcut Application Resource*/
#if defined(__MMI_VRSD_SHORTCUT__)	
	PopulateVRSDShortcutRes();
#endif	
}
#endif /*END defined(__MMI_VRSD__)*/

/*****************************************************************************
* FUNCTION
*  PopulateVRSDMainRes
* DESCRIPTION
*   Populate Voice Recognition and Main Resource
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#if defined(__MMI_VRSD__)
void PopulateVRSDMainRes(void)
{

	/*Multimedia Menu Item*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_APP, MAIN_MENU_MULTIMEDIA_MENUID, 0,
		SHOW, NONMOVEABLE, 0, STR_ID_VRSD_APP, IMG_ID_VRSD_APP ));

	/*VRSD Main Menu*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_MAIN_MENU,0, (VRSD_MENU_ENUM_TOTAL+3),
		MENU_ID_VRSD_RCG,
#if defined(__MMI_VRSD_DIAL__)		
		MENU_ID_VRSD_DIAL,
#endif
#if defined(__MMI_VRSD_REDIAL__)
		MENU_ID_VRSD_REDIAL,
#endif
#if defined(__MMI_VRSD_PROFILE__)
		MENU_ID_VRSD_PROFILE,
#endif
#if defined(__MMI_VRSD_AUDPLAYER__)
		MENU_ID_VRSD_AUD_PLAYER,
#endif
#if defined(__MMI_VRSD_SHORTCUT__)
		MENU_ID_VRSD_SHORTCUT,
#endif		
		MENU_ID_VRSD_DELETE_ALL,
		MENU_ID_VRSD_STATUS,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OK,IMG_GLOBAL_OK));

	/*VRSD Main Menu Item*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_RCG,MENU_ID_VRSD_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_RCG, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DIAL,MENU_ID_VRSD_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_DIAL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_REDIAL,MENU_ID_VRSD_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_REDIAL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_PROFILE,MENU_ID_VRSD_MAIN_MENU,5,
		MENU_ID_VRSD_PROFILE_MODE1,
		MENU_ID_VRSD_PROFILE_MODE2,
		MENU_ID_VRSD_PROFILE_MODE3,
		MENU_ID_VRSD_PROFILE_MODE4,
		//MENU_ID_VRSD_PROFILE_MODE5, /*Can't switch to headset mode*/
		MENU_ID_VRSD_PROFILE_MODE6,		
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_PROFILE, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_AUD_PLAYER,MENU_ID_VRSD_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_AUD_PLAYER, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_SHORTCUT,MENU_ID_VRSD_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_SHORTCUT, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DELETE_ALL,MENU_ID_VRSD_MAIN_MENU, (VRSD_MENU_ENUM_TOTAL+1),
		MENU_ID_VRSD_DELETE_ALL_ALL,
#if defined(__MMI_VRSD_DIAL__)
		MENU_ID_VRSD_DELETE_ALL_DIAL,
#endif
#if defined(__MMI_VRSD_REDIAL__)
		MENU_ID_VRSD_DELETE_ALL_REDIAL,
#endif
#if defined(__MMI_VRSD_PROFILE__)
		MENU_ID_VRSD_DELETE_ALL_PROFILE,
#endif
#if defined(__MMI_VRSD_AUDPLAYER__)
		MENU_ID_VRSD_DELETE_ALL_AUDPLAYER,
#endif
#if defined(__MMI_VRSD_SHORTCUT__)
		MENU_ID_VRSD_DELETE_ALL_SHORTCUT,
#endif
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_DELETE_ALL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_STATUS,MENU_ID_VRSD_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_TAG_STATUS, 0));

	/*Delete All Menu Item*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DELETE_ALL_ALL,MENU_ID_VRSD_DELETE_ALL,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_DELETE_ALL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DELETE_ALL_DIAL,MENU_ID_VRSD_DELETE_ALL,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_DIAL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DELETE_ALL_REDIAL,MENU_ID_VRSD_DELETE_ALL,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_REDIAL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DELETE_ALL_PROFILE,MENU_ID_VRSD_DELETE_ALL,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_PROFILE, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DELETE_ALL_AUDPLAYER,MENU_ID_VRSD_DELETE_ALL,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_AUD_PLAYER, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DELETE_ALL_SHORTCUT,MENU_ID_VRSD_DELETE_ALL,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_SHORTCUT, 0));


	/*Add Application String*/
	ADD_APPLICATION_STRING2(STR_ID_VRSD_APP		,"Voice Control"	,"Voice Command App String");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_RCG		,"Voice Recognition"	,"Voice Recognition String");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_DIAL	,"Voice Dial"		,"Voice Dial String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_REDIAL	,"Voice Redial"		,"Voice Redial String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_PROFILE	,"Voice Profile"	,"Voice Profile String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_AUD_PLAYER	,"Voice Audio Player"	,"Voice Audio Player String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_SHORTCUT	,"Voice Shortcut"	,"Voice Shortcut String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_TAG_STATUS	,"Voice Tag Usage"	,"Voice Tag Status String");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_CHANGE	,"Change"	,"Change Voice Tag");

	ADD_APPLICATION_STRING2(STR_ID_VRSD_VOICE_IN	,"Please Speak After Beep"	,"Prompt Speak String");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_VOICE_IN_AGAIN	,"Please Speak Again"	,"Prompt Speak String");	

	/*Error String*/
	ADD_APPLICATION_STRING2(STR_ID_VRSD_NO_TAG_EXIST	,"No Voice Tag Exists"	,"No voice tag exist message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_NO_EMPTY_TAG	,"All Voice Tag Used"	,"No voice tag available message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_RECV_VOICE_FAIL	,"Receive Voice Fail! Please try again"	,"MED error string message");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_NO_SOUND	,"No Sound"	,"MED error string message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_NO_MATCH	,"No Match"	,"MED error string message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_TOO_SIMILAR	,"Voice Too Similar"	,"MED error string message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_TOO_DIFFERENT	,"Voice Too Different"	,"MED error string message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_DISC_FULL	,"Disc Full"	,"MED error string message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_SPEAK_TOO_LONG	,"Speak too long"	,"MED error string message");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_SPEAK_TOO_SHORT	,"Speak too short"	,"MED error string message");	
	ADD_APPLICATION_STRING2(STR_ID_VRSD_WRONG_SESSION	,"Incorrect Session"	,"MED error string message");


	/*Add Application Image*/
	ADD_APPLICATION_IMAGE2(IMG_ID_VRSD_APP,CUST_IMG_PATH"\\\\MainLCD\\\\VoiceRecg\\\\SB_Speak.pbm","Main Icon for Voice Command App");
	ADD_APPLICATION_IMAGE2(IMG_ID_VRSD_RECORDING,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\Speaking"__MMI_RES_TYPE_POPUP_SCREEN__,"Sound Recorder Recording");
}
#endif

/*****************************************************************************
* FUNCTION
*  PopulateVRSDDialRes
* DESCRIPTION
*   Populate Voice Dial Application Resource
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#if defined(__MMI_VRSD_DIAL__)
void PopulateVRSDDialRes(void)
{

	/*Phonebook List Option Menu Item*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DIAL_PHB_OPTION,MITEM101_PBOOK_VIEW_OPTIONS,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_DIAL,IMG_ID_VRSD_APP));


	/*Voice Dial Main Menu*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DIAL_MAIN_MENU,0,3,
		MENU_ID_VRSD_DIAL_MAIN_ADD,
		MENU_ID_VRSD_DIAL_MAIN_CHANGE,
		MENU_ID_VRSD_DIAL_MAIN_DELETE,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OK,IMG_GLOBAL_OK));

	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DIAL_MAIN_ADD,MENU_ID_VRSD_DIAL_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_ADD, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DIAL_MAIN_CHANGE,MENU_ID_VRSD_DIAL_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_CHANGE, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_DIAL_MAIN_DELETE,MENU_ID_VRSD_DIAL_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_DELETE, 0));

	/*Add Application String*/
	ADD_APPLICATION_STRING2(STR_ID_VRSD_DIAL_REFRESH_SIM	,"SIM card changed. Do you want to delete all voice tag?"	,"Change SIM card message");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_DIAL_FOUND	,"Found:"	,"Found Voice Tag Result");
	ADD_APPLICATION_STRING2(STR_ID_VRSD_DIAL_AUTO_DIAL	,"Auto Dial In 4 Seconds..."	,"Auto Dial Out String");
	
}
#endif

/*****************************************************************************
* FUNCTION
*  PopulateVRSDRedialRes
* DESCRIPTION
*   Populate Voice Redial Application Resource
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#if defined(__MMI_VRSD_REDIAL__)
void PopulateVRSDRedialRes(void)
{
	ADD_APPLICATION_STRING2(STR_ID_VRSD_REDIAL_CALLLOG_EMPTY		,"No Last Dialed Number"	,"Voice redial error message");

	
}
#endif

/*****************************************************************************
* FUNCTION
*  PopulateVRSDProfileRes
* DESCRIPTION
*   Populate Voice Profile Application Resource
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#if defined(__MMI_VRSD_PROFILE__)
#include "UserProfilesResDef.h"

void PopulateVRSDProfileRes(void)
{
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_PROFILE_MODE1,MENU_ID_VRSD_PROFILE,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_PROFILES_GENERAL, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_PROFILE_MODE2,MENU_ID_VRSD_PROFILE,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_PROFILES_MEETING, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_PROFILE_MODE3,MENU_ID_VRSD_PROFILE,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_PROFILES_OUTDOOR, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_PROFILE_MODE4,MENU_ID_VRSD_PROFILE,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_PROFILES_INDOOR, 0));
/*	Can't switch to headset mode */
/*	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_PROFILE_MODE5,MENU_ID_VRSD_PROFILE,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_PROFILES_HEADSET, 0));
*/
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_PROFILE_MODE6,MENU_ID_VRSD_PROFILE,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_PROFILE_SILENT, 0));
		
	ADD_APPLICATION_STRING2(STR_ID_VRSD_PROFILE_SILENT		,"Silent"	,"Voice Command Profile Mode");

	ADD_APPLICATION_STRING2(STR_ID_VRSD_PROFILE_CANNOT_SWITCH		,"Can not change mode!"	,"Voice Command Error Message");
}
#endif

/*****************************************************************************
* FUNCTION
*  PopulateVRSDAudPlayerRes
* DESCRIPTION
*   Populate Voice Audio Player Application Resource
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#if defined(__MMI_VRSD_AUDPLAYER__)	
void PopulateVRSDAudPlayerRes(void)
{
}
#endif

/*****************************************************************************
* FUNCTION
*  PopulateVRSDShortcutRes
* DESCRIPTION
*   Populate Voice Shortcut Application Resource
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#if defined(__MMI_VRSD_SHORTCUT__)
void PopulateVRSDShortcutRes(void)
{
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_SHORTCUT_MAIN_MENU,0,3,
		MENU_ID_VRSD_SHORTCUT_MAIN_ADD,
		MENU_ID_VRSD_SHORTCUT_MAIN_CHANGE,
		MENU_ID_VRSD_SHORTCUT_MAIN_DELETE,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OK,IMG_GLOBAL_OK));

	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_SHORTCUT_MAIN_ADD,MENU_ID_VRSD_SHORTCUT_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_ADD, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_SHORTCUT_MAIN_CHANGE,MENU_ID_VRSD_SHORTCUT_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_VRSD_CHANGE, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_VRSD_SHORTCUT_MAIN_DELETE,MENU_ID_VRSD_SHORTCUT_MAIN_MENU,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_DELETE, 0));
}
#endif



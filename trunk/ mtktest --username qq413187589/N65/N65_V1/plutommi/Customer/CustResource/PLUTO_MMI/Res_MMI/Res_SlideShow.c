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
 *	Res_SlideShow.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Generate SlideShow Resources
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MMI_features.h"

#ifdef __MMI_SLIDESHOW__

#ifdef DEVELOPER_BUILD_FIRST_PASS

#include "PopulateRes.h"
#include "CustResDef.h"
#include "SlideShowResDef.h"
#include "GlobalMenuItems.h"

/*****************************************************************************
* FUNCTION
*	PopulateSlideShowStrRes
* DESCRIPTION
*	Generate SlideShow related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateSlideShowStrRes(void)
{	

	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_APP,						"Slide Show",		"[Menu-Slide Show]");

	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_NOTIFY_SELECT_FOLDER,
													"Select a Folder to Play",		    "[Notify-Slide Show]");

	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_PLAY,						"Play",				"[Menu-Play]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_SETTING,					"Setting",			"[Menu-Setting]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_RESUME,						"Resume",			"[Menu-Resume]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_PAUSE,						"Pause",			"[OSD-Pause]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_TYPE_OF_PLAY,				"Type Of Play",		"[Menu-Type Of Play]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_SPEED,						"Speed",			"[Menu-Slide Show]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_EFFECT,						"Effect",			"[Menu-Effect]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_BGM,						"BGM",				"[Menu-BGM]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_SOUND_EFFECT,				"Sound Effect",		"[Menu-Sound Effect]");

	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_HORIZONTAL_DISPLAY,
													"Horizontal Display",					"[Menu-Horizontal Display]");

	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_AUTO_ONCE,					"Auto Once",		"[Inline-Auto Once]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_AUTO_REPEAT,				"Auto Repeat",		"[Inline-Auto Repeat]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_MANUAL,						"Manual",			"[Inline-Manual]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_LOW,						"Low",				"[Inline-Low]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_MEDIUM,						"Medium",			"[Inline-Medium]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_FAST,						"Fast",				"[Inline-Fast]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_NORMAL,						"Normal",			"[Inline-Normal]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_FADE_IN,					"Fade In",			"[Inline-Fade In]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_SPLIT,						"Split",			"[Inline-Split]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_WIPE,						"Wipe",				"[Inline-Wipe]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_RANDOM,						"Random",			"[Inline-Random]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_SELECT_BGM,					"Select from File",	"[Inline-Select BGM]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_AUD1,						"Aud1",				"[Inline-Aud1]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_AUD2,						"Aud2",				"[Inline-Aud2]");
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_AUD3,						"Aud3",				"[Inline-Aud3]");		
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_ASSOCIATE_AUDIO,			"Associate Audio",	"[Inline-File Selected]");		
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_PLAY_AUDIO,					"Play Audio",		"[Inline-File Selected]");		
	ADD_APPLICATION_STRING2(STR_ID_SLIDSHOW_SAVE_SETTING,				"Save Settings?",	"[savesetting str]");		
	
	
}

/*****************************************************************************
* FUNCTION
*	PopulateSlideShowImgRes
* DESCRIPTION
*	Generate SlideShow related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateSlideShowImgRes(void)
{	
	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_APP,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_app_icon.pbm", "IMG_ID_SLIDSHOW_APP" );

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_SETTING_TYPE_OF_PLAY,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_type_of_play.pbm", "IMG_ID_SLIDSHOW_SETTING_TYPE_OF_PLAY" );

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_SETTING_SPEED,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_speed.pbm", "IMG_ID_SLIDSHOW_SETTING_SPEED" );

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_SETTING_EFFECT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_effect.pbm", "IMG_ID_SLIDSHOW_SETTING_EFFECT" );

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_SETTING_BACK_SOUND,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_back_aud.pbm", "IMG_ID_SLIDSHOW_SETTING_BACK_SOUND" );

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_SETTING_HORZ_DISPLAY,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_hdisplay.pbm", "IMG_ID_SLIDSHOW_SETTING_HORZ_DISPLAY" );

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_SETTING_SOUND_EFFECT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_sound_effect.pbm", "IMG_ID_SLIDSHOW_SETTING_SOUND_EFFECT" );

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_LEFT_ARROW,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_left_arrow.pbm", "IMG_ID_SLIDSHOW_LEFT_ARROW" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_LEFT_ARROW_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_left_arrow_sel.pbm", "IMG_ID_SLIDSHOW_LEFT_ARROW_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_RIGHT_ARROW,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_right_arrow.pbm", "IMG_ID_SLIDSHOW_RIGHT_ARROW" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_SLIDSHOW_RIGHT_ARROW_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SS_right_arrow_sel.pbm", "IMG_ID_SLIDSHOW_RIGHT_ARROW_SEL" );		

	/*Audio*/
	ADD_APPLICATION_AUDIO2(AUD_ID_SLIDSHOW_1, CUST_ADO_PATH"\\\\PhotoEditor\\\\slidshow_aud1.wav", "Slide Show Audio Res");
	ADD_APPLICATION_AUDIO2(AUD_ID_SLIDSHOW_2, CUST_ADO_PATH"\\\\PhotoEditor\\\\slidshow_aud2.wav", "Slide Show Audio Res");
	ADD_APPLICATION_AUDIO2(AUD_ID_SLIDSHOW_3, CUST_ADO_PATH"\\\\PhotoEditor\\\\slidshow_aud3.wav", "Slide Show Audio Res");
	
}


/*****************************************************************************
* FUNCTION
*	PopulateSlideShowMenuRes
* DESCRIPTION
*	Generate SlideShow related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateSlideShowMenuRes(void)
{	
#if defined(__MMI_VERSION_2__)
	ADD_APPLICATION_MENUITEM((	MENU_ID_SLIDSHOW_APP, 
		MAIN_MENU_MULTIMEDIA_MENUID,
		0,
		SHOW,
		NONMOVEABLE,
		DISP_LIST,
		STR_ID_SLIDSHOW_APP,
		IMG_ID_SLIDSHOW_APP));

    #ifdef __MMI_OP01_MENU_NOSIM_LIST__
        ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_APP, 
            MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID,
            0,
            SHOW,
            NONMOVEABLE,
            DISP_LIST,
            STR_ID_SLIDSHOW_APP,
            IMG_ID_SLIDSHOW_APP));
    #endif /* __MMI_OP01_MENU_NOSIM_LIST__ */
		
#endif	/* __MMI_VERSION_2__ */
	
	ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_APP, MENU_ID_PHOEDT_APP, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_SLIDSHOW_APP, IMG_ID_SLIDSHOW_APP));

	ADD_APPLICATION_MENUITEM((	MENU_ID_SLIDSHOW_OPTION, 
										0,
										2,
										MENU_ID_SLIDSHOW_PLAY,
										MENU_ID_SLIDSHOW_SETTING,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_GLOBAL_OPTIONS,
										0));	

	ADD_APPLICATION_MENUITEM((	MENU_ID_SLIDSHOW_OPTION_EDIT, 
										0,
										3,
										MENU_ID_SLIDSHOW_PLAY,
										MENU_ID_SLIDSHOW_SETTING,
										MENU_ID_SLIDSHOW_RESUME,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_GLOBAL_OPTIONS,
										0));	


	ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_RESUME, MENU_ID_SLIDSHOW_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_SLIDSHOW_RESUME, 0));	
	
	ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_PLAY, MENU_ID_SLIDSHOW_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_SLIDSHOW_PLAY, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_SETTING, MENU_ID_SLIDSHOW_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_SLIDSHOW_SETTING, 0));	
	
	ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_BGM_FILE_OPTION,0,2,
		MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY,
		MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_SELECT,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_SLIDSHOW_ASSOCIATE_AUDIO, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY,MENU_ID_SLIDSHOW_BGM_FILE_OPTION,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_SLIDSHOW_PLAY_AUDIO, 0));
	ADD_APPLICATION_MENUITEM((MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_SELECT,MENU_ID_SLIDSHOW_BGM_FILE_OPTION,0,
		SHOW, NONMOVEABLE, DISP_LIST,STR_ID_SLIDSHOW_SELECT_BGM,0));	
	
	
}


/*****************************************************************************
* FUNCTION
*	PopulateSlideShowRes
* DESCRIPTION
*	Generate Camrea related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateSlideShowRes(void)
{	
	PopulateSlideShowStrRes();
	PopulateSlideShowImgRes();	
	PopulateSlideShowMenuRes();		
}


#endif /* __MMI_SLIDESHOW__ */
#endif /* DEVELOPER_BUILD_FIRST_PASS */



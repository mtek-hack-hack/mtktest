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

	FILENAME	: Res_Stopwatch.c

  	PURPOSE		: Populate Resource for Stopwatch

	REMARKS		: nil

	AUTHOR		: Deepali

	DATE		: January-05-2004

**************************************************************/
#include "CustomCfg.h"

#include "MMI_features.h"
#ifdef __MMI_STOPWATCH__

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "StopwatchResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"
/**************************************************************

	FUNCTION NAME		: PopulateStopwatchStrRes()

  	PURPOSE				: To Populate the String resources for the 
						  Stopwatch screens

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/

void PopulateStopwatchStrRes(void)
{
	ADD_APPLICATION_STRING2(STR_STOPWATCH_TITLE,"Stopwatch","Stopwatch main screen title.");
	ADD_APPLICATION_STRING2(STR_TYPICAL_STOPWATCH,"Typical Stopwatch","Typical Stopwatch string for menu option.");
	ADD_APPLICATION_STRING2(STR_MULTIPURPOSE_STOPWATCH,"Multipurpose Stopwatch","Multipurpose Stopwatch string for menu option.");

	ADD_APPLICATION_STRING2(STR_SPLIT_TIMING,"Split Timing","Split Timing string for Typical Stopwatch menu option.");
	ADD_APPLICATION_STRING2(STR_LAP_TIMING,"Lap Timing","Lap Timing string for Typical Stopwatch menu option.");
	ADD_APPLICATION_STRING2(STR_VIEW_RECORD,"View record","View record string for Typical Stopwatch menu option.");

	ADD_APPLICATION_STRING2(STR_STOPWATCH_START,"Start"," String for Start key.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_STOP,"Stop","String for Stop key.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_SPLIT,"Split","String for Split key.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_LAP,"Lap","String for Lap key.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_RESUME,"Resume","String for Resume key.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_MEMORY_FULL,"Memory Full. Replace Old Record?","String for Memory Full.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_NOT_SAVED,"Not Saved!","String for Failed in saving.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_REPLACE_RECORD,"Replace Record","String for Replace Record screen Title.");
	ADD_APPLICATION_STRING2(STR_STOPWATCH_SAVE_STOPWATCH,"Save Stopwatch","String for Failed in saving.");

	//ADD_APPLICATION_STRING2(STR_STOPWATCH_LIST_EMPTY,"Empty","String for Empty List.");

	//ADD_APPLICATION_STRING2(STR_VIEW_STOPWATCH_LIST_OPTION_VIEW,"View","String for View Record Option View.");
	//ADD_APPLICATION_STRING2(STR_VIEW_STOPWATCH_LIST_OPTION_DELETEALL,"Delete All","String for View Record Option Delete All.");

	//ADD_APPLICATION_STRING2(STR_CONFIRM_DELETE_ALL_RECORD,"Delete All","String for confirmation of Delete All Record.");

	ADD_APPLICATION_STRING2(STR_EMPTY_NAME,"Empty Name!","String for Name Empty warning.");

	ADD_APPLICATION_STRING2(STR_MUTIPURPOSE_TITLE_MSG,"Stop Watch","String for MultiPurpose Stopwatch Title.");
	ADD_APPLICATION_STRING2(STR_MUTIPURPOSE_TITLE_SIDE_MSG,"Total","String for MultiPurpose Stopwatch side Title.");

	ADD_APPLICATION_STRING2(STR_DISCONTINUE_TIMER_QUERY,"Stop previous stopwatch?" ,"String to stop previous stopwatch popup.");
}

/**************************************************************

	FUNCTION NAME		: PopulateStopwatchImgRes()

  	PURPOSE				: To Populate the Image resources for the 
						  Stopwatch screens

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/

void PopulateStopwatchImgRes(void)
{	
	ADD_APPLICATION_IMAGE2(IMG_MULTIPURPOSE_TIMER1,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\LEFT.bmp","Image for MultiPurpose Timer1");
	ADD_APPLICATION_IMAGE2(IMG_MULTIPURPOSE_TIMER2,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\UP.bmp","Image for MultiPurpose Timer2");
	ADD_APPLICATION_IMAGE2(IMG_MULTIPURPOSE_TIMER3,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\RIGHT.bmp","Image for MultiPurpose Timer3");
	ADD_APPLICATION_IMAGE2(IMG_MULTIPURPOSE_TIMER4,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\DOWN.bmp","Image for MultiPurpose Timer4");
#if defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__)//041205 Calvin modified
	ADD_APPLICATION_IMAGE2(IMG_TYPICALSW_BACKGROUND,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW.png","Image for MultiPurpose Timer4");
	ADD_APPLICATION_IMAGE2(IMG_TYPICALSW_LIST_BACKGROUND,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_List_BG.bmp","SW_List_BG");
#else
	ADD_APPLICATION_IMAGE2(IMG_TYPICALSW_BACKGROUND,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW.gif","Image for MultiPurpose Timer4");
#endif
	ADD_APPLICATION_IMAGE2(IMG_STOPWATCH_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SB_STWCH.pbm","Image for Stopwatch submenu Icon");
}
/**************************************************************

	FUNCTION NAME		: PopulateStopwatchMenuItemRes()

  	PURPOSE				: To populate the Menu Item resources for the 
						  Stopwatch screens

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/

void PopulateStopwatchMenuItemRes(void)
{
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
    ADD_APPLICATION_MENUITEM((MENU_STOPWATCH,MAIN_MENU_EXTRA_MENUID,2,
#endif
		MENU_TYPICALSTOPWATCH,
		MENU_MULTIPURPOSEWATCH,
		SHOW, MOVEABLEACROSSPARENT|SHORTCUTABLE, DISP_LIST,STR_STOPWATCH_TITLE,IMG_STOPWATCH_ICON));

	ADD_APPLICATION_MENUITEM((MENU_TYPICALSTOPWATCH,MENU_STOPWATCH,3,
		MENU_SPLIT_TIMING,
		MENU_LAP_TIMING,
		MENU_VIEW_RECORD,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_TYPICAL_STOPWATCH,NULL));

	ADD_APPLICATION_MENUITEM((MENU_MULTIPURPOSEWATCH,MENU_STOPWATCH,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_MULTIPURPOSE_STOPWATCH,NULL));

	ADD_APPLICATION_MENUITEM((MENU_SPLIT_TIMING,MENU_TYPICALSTOPWATCH,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_SPLIT_TIMING,NULL));

	ADD_APPLICATION_MENUITEM((MENU_LAP_TIMING,MENU_TYPICALSTOPWATCH,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_LAP_TIMING,NULL));

	ADD_APPLICATION_MENUITEM((MENU_VIEW_RECORD,MENU_TYPICALSTOPWATCH,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_VIEW_RECORD,NULL));

	ADD_APPLICATION_MENUITEM((MENU_RECORD_SAVE_OPTIONS,0,2,
		MENU_SAVE_DONE,
		MENU_SAVE_INPUTMETHOD,
		SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));

	ADD_APPLICATION_MENUITEM((MENU_SAVE_DONE,MENU_RECORD_SAVE_OPTIONS,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_DONE,NULL));

	ADD_APPLICATION_MENUITEM((MENU_SAVE_INPUTMETHOD,MENU_RECORD_SAVE_OPTIONS,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_INPUT_METHOD,NULL));

	ADD_APPLICATION_MENUITEM((MENU_VIEW_RECORD_OPTIONS,0,3,
		MENU_OPTION_VR_VIEW,
		MENU_OPTION_VR_DELETE,
		MENU_OPTION_VR_DELETE_ALL,
		SHOW, NONMOVEABLE, DISP_LIST,STR_VIEW_RECORD,NULL));

	ADD_APPLICATION_MENUITEM((MENU_OPTION_VR_VIEW,MENU_VIEW_RECORD_OPTIONS,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_VIEW,NULL));

	ADD_APPLICATION_MENUITEM((MENU_OPTION_VR_DELETE,MENU_VIEW_RECORD_OPTIONS,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_DELETE,NULL));

	ADD_APPLICATION_MENUITEM((MENU_OPTION_VR_DELETE_ALL,MENU_VIEW_RECORD_OPTIONS,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_DELETE_ALL,NULL));
	
}
/**************************************************************

	FUNCTION NAME		: PopulateStopwatchRes()

  	PURPOSE				: To Populate the resources for the 
						  Stopwatch screens

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/

void PopulateStopwatchRes(void)
{
	PopulateStopwatchStrRes();
	PopulateStopwatchImgRes();
	PopulateStopwatchMenuItemRes();
}

#endif
#endif



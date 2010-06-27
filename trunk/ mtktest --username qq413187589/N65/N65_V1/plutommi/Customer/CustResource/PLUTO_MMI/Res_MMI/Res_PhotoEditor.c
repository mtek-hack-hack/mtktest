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
 *	Res_PhotoEditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Generate PhotoEditor Resources
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MMI_features.h"

#ifdef __MMI_PHOTOEDITOR__

#ifdef DEVELOPER_BUILD_FIRST_PASS

#include "PopulateRes.h"
#include "CustResDef.h"
#include "PhotoEditor.h"			/* Photo Editor data struct */
#include "phoEdtResDef.h"


/*****************************************************************************
* FUNCTION
*	PopulatePhotoEditorStrRes
* DESCRIPTION
*	Generate PhotoEditor related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulatePhotoEditorStrRes(void)
{	
	/************* Photo Editor **************/
	ADD_APPLICATION_STRING2(STR_ID_PHOEDT_APP_NAME,					"Photo Editor",	"[Menu-Photo Editor]");

	
	/************* Photo Art **************/
	ADD_APPLICATION_STRING2(STR_ID_PHOART_APP,						"Photo Artist",	"[Menu-Photo Artist]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_EXIT,						"Exit",				"[OSD-Exit]");

	/* clip menu */
	ADD_APPLICATION_STRING2(STR_ID_PHOART_CLIP,						"Clip",				"[Menu-Clip]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_AUTO_RESIZE,				"Auto Resize",		"[Menu-Auto Resize]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_MAINLCD_CLIP,			"MainLCD Clip",	"[Menu-MainLCD Clip]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_SUBLCD_CLIP,				"SubLCD Clip",		"[Menu-SubLCD Clip]");
	
	/* option menu */
	ADD_APPLICATION_STRING2(STR_ID_PHOART_SAVE_AS,					"Save As",			"[Menu-Save As]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_EFFECT,				"Add Effect",		"[Menu-Add Effect]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_FRAME,				"Add Frame",		"[Menu-Add Frame]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_ICON,					"Add Icon",			"[Menu-Add Icon]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_TEXT,					"Add Text",			"[Menu-Add Text]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST,					"Adjustment",		"[Menu-Adjustment]");	
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FLIP,						"Flip",				"[Menu-Flip]");	

	
	ADD_APPLICATION_STRING2(STR_ID_PHOART_EXPAND_CANVAS,			"Expand Canvas",	"[Menu-Expand Canvas]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_HELP,						"Help",				"[Menu-Help]");
	
	ADD_APPLICATION_STRING2(STR_ID_PHOART_EDIT_FILENAME,			"Edit Filename",	"[Title-Edit Filename]");
	

	/* selection title */
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_EFFECT_TITLE,			"[ Add Effect ]",	"[Title-Add Effect]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_FRAME_TITLE,			"[ Add Frame ]",	"[Title-Add Frame]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_ICON_TITLE,				"[ Add Icon ]",	"[Title-Add Icon]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADD_TEXT_TITLE,				"[ Add Text ]",	"[Title-Add Text]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FLIP_TITLE,					"[ Flip ]",			"[Title-Flip]");

#ifdef __MMI_PHOART_EFFECT_SUPPORT__    
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_BRIGHT_TITLE,		"[ Brightness ]",	"[Title-Brightness]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_CONTRAST_TITLE,	"[ Contrast ]",	"[Title-Contrast]");	
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_HUE_TITLE,			"[ Hue ]",			"[Title-Hue]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_SATURATION_TITLE,	"[ Saturation ]",	"[Title-Saturation]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_COLOR_R_TITLE,		"[ Color R ]",		"[Title-Color R]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_COLOR_G_TITLE,		"[ Color G ]",		"[Title-Color G]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_COLOR_B_TITLE,		"[ Color B ]",		"[Title-Color B]");
#endif /*  __MMI_PHOART_EFFECT_SUPPORT__  */

	
	/* add effect menu */
#ifdef __MMI_PHOART_EFFECT_SUPPORT__    
	#ifdef PHOART_FEATURE_EFFECT_GRAYSCALE
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_GRAYSCALE,		"Grayscale",		"[Menu-Grayscale]");
	#endif /* PHOART_FEATURE_EFFECT_GRAYSCALE */

	#ifdef PHOART_FEATURE_EFFECT_SEPIA
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_SEPIA,			"Sepia", 			"[Menu-Sepia]");
	#endif /* PHOART_FEATURE_EFFECT_SEPIA */

	#ifdef PHOART_FEATURE_EFFECT_SEPIA_GREEN
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_SEPIA_GREEN,	"Sepia Green", 	"[Menu-Sepia Green]");
	#endif /* PHOART_FEATURE_EFFECT_SEPIA_GREEN */

	#ifdef PHOART_FEATURE_EFFECT_SEPIA_BLUE
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_SEPIA_BLUE, 	"Sepia Blue",		"[Menu-Sepia Blue]");
	#endif /* PHOART_FEATURE_EFFECT_SEPIA_BLUE */

	#ifdef PHOART_FEATURE_EFFECT_COLOR_INVERT
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_COLOR_INVERT,	"Color Invert",	"[Menu-Color Invert]");
	#endif /* PHOART_FEATURE_EFFECT_COLOR_INVERT */

	#ifdef PHOART_FEATURE_EFFECT_GRAY_INVERT
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_GRAY_INVERT,	"Gray Invert", 	"[Menu-Gray Invert]");	
	#endif /* PHOART_FEATURE_EFFECT_GRAY_INVERT */

	#ifdef PHOART_FEATURE_EFFECT_WATER_COLOR
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_WATER_COLOR,	"Water Color", 	"[Menu-Water Color]");
	#endif /* PHOART_FEATURE_EFFECT_WATER_COLOR */
	
	#ifdef  PHOART_FEATURE_EFFECT_LIGHT_BLUR 
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_LIGHT_BLUR, 	"Light Blue",		"[Menu-Light Blur]");
	#endif /* PHOART_FEATURE_EFFECT_LIGHT_BLUR */

	#ifdef PHOART_FEATURE_EFFECT_BLUR
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_BLUR, 			"Blur",				"[Menu-Blur]");
	#endif /* PHOART_FEATURE_EFFECT_BLUR */
	
	#ifdef PHOART_FEATURE_EFFECT_STRONG_BLUR
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_STRONG_BLUR,	"Strong Blur", 	"[Menu-Strong Blur]");
	#endif /* PHOART_FEATURE_EFFECT_STRONG_BLUR */

	#ifdef PHOART_FEATURE_EFFECT_UNSHARP
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_UNSHARP, 		"Unsharp",			"[Menu-Unsharp]");
	#endif /* PHOART_FEATURE_EFFECT_UNSHARP */

	#ifdef PHOART_FEATURE_EFFECT_SHARPEN
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_SHARPEN, 		"Sharpen",			"[Menu-Sharpen]");
	#endif /* PHOART_FEATURE_EFFECT_SHARPEN */
	
	#ifdef PHOART_FEATURE_EFFECT_MORE_SHARPEN
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_MORE_SHARPEN,	"More Sharpen",	"[Menu-More Sharpen]");
	#endif /* PHOART_FEATURE_EFFECT_MORE_SHARPEN */

	#ifdef PHOART_FEATURE_EFFECT_MEDIAN
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_MEDIAN,			"Median",			"[Menu-Median]"); 
	#endif /* PHOART_FEATURE_EFFECT_MEDIAN */

	#ifdef PHOART_FEATURE_EFFECT_DILATION
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_DILATION,		"Dilation", 		"[Menu-Dilation]");
	#endif /* PHOART_FEATURE_EFFECT_DILATION */

	#ifdef  PHOART_FEATURE_EFFECT_EROSION 
		ADD_APPLICATION_STRING2(STR_ID_PHOART_EFFECT_EROSION,			"Erosion",			"[Menu-Erosion]");		
	#endif /* PHOART_FEATURE_EFFECT_EROSION */
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */

 	/* add frame menu */
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_1,					"Frame 1",			"[Menu-Frame 1]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_2,					"Frame 2",			"[Menu-Frame 2]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_3,					"Frame 3",			"[Menu-Frame 3]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_4,					"Frame 4",			"[Menu-Frame 4]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_5,					"Frame 5",			"[Menu-Frame 5]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_6,					"Frame 6",			"[Menu-Frame 6]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_7,					"Frame 7",			"[Menu-Frame 7]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_8,					"Frame 8",			"[Menu-Frame 8]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_9,					"Frame 9",			"[Menu-Frame 9]");
	ADD_APPLICATION_STRING2(STR_ID_PHOART_FRAME_10,					"Frame 10",			"[Menu-Frame 10]");

 	/* add text menu */
 	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_EDITOR,				"Edit Text",		"[Title-Edit Text]");	
   ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_TEXT_COLOR,		"Text Color",		"[Inline-Text Color]");	
  	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_BORDER_COLOR,		"Border Color",	"[Inline-Border Color]");		
 	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_SHADOW_COLOR,		"Shadow Color",	"[Inline-Shadow Color]");	
  	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_SIZE,				"Font Size",		"[Inline-Font Size]");			
 	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_ITALIC,				"Italic",			"[Inline-Italic]");	
 	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_SIZE_SMALL,		"Small Font",		"[Inline-Small Font]");	
  	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_SIZE_MEDIUM, 		"Medium Font",		"[Inline-Medium Font]");	
  	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_SIZE_LARGE,		"Large Font",		"[Inline-Large Font]");		
 	ADD_APPLICATION_STRING2(STR_ID_PHOART_TEXT_STYLE,				"Text Style",		"[Title-Text Style]");	

    /* adjust */
#ifdef __MMI_PHOART_EFFECT_SUPPORT__
 	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_IMAGE,			"Adjust Image",		"[Menu-Adjust Image]");	
 	ADD_APPLICATION_STRING2(STR_ID_PHOART_ADJUST_COLOR,			"Adjust Color",		"[Menu-Adjust Color]");		
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */

	/* help */
	ADD_APPLICATION_STRING2(STR_ID_PHOART_HELP_TITLE,				"Help",				"[Title-Help Desc]");	
  	ADD_APPLICATION_STRING2(STR_ID_PHOART_HELP_DESC,				"[Add Frame,Effect]\nUse left and right arrow key(or side key) to change selection.\n\n[Add Icon]\nUse side key to change selection. Use up, down, left, right arrow key to move, OK key to stamp. \n\n[Add Text]\nUse up, down, left, right arrow key to move, OK key to stamp.",		"[Content-Help Desc]");	

	
	
	/* notify */
	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_FREE_SPACE_NOT_ENOUGH,
									"Free space not enoguth. Please delete some file first",
									"[Notify-Free space not enough]");

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_UNLOCK_MEMORY_CARD,
									"Please unlocd memory card to save edited file",
									"[Notify-Unlock card]");

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_EXIT_CONFIRM,
									"Exit without saving?",
									"[Notify-Exit confirm]");

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_FILE_NOT_SAVED,
									"File not saved",
									"[Notify-File not saved]");

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_EMPTY_STRING,
									"Empty String!",
									"[Notify-Empty string]");

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_ALREADY_FULL_SCREEN,
									"Canvas already fullscreen size",
									"[Notify-Already fullscreen]");	

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_ASK_EXPAND_CANVAS,
									"Expand canvas to fullscreen size?",
									"[Notify-Expand to fullscreen]");	

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_IMAGE_TOO_WIDE,
									"Image too wide. Unable to clip",
									"[Notify-Image too wide. Unable to clip]");	

	ADD_APPLICATION_STRING2(STR_ID_PHOART_NOTIFY_CANCELED,
									"Canceled",
									"[Notify-Canceled]");	


	/************* Scene Master **************/
	ADD_APPLICATION_STRING2(STR_ID_SCENMAST_APP,						"Scene Master",	"[Menu-Scene Master]");


	
	/************* Image Tile **************/
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_APP,						"Image Tile",		"[Menu-Image Tile]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_TILE_2,						"2 Image Tile",		"[Menu-2 Tile]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_TILE_4,						"4 Image Tile",		"[Menu-4 Tile]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_TILE_9,						"9 Image Tile",		"[Menu-9 Tile]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_CLIP,							"Clip",		"[Menu-Clip]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_CLIP_IMAGE,					"Clip Image",		"[Menu-Tile Clip]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_AUTO_RESIZE,				"Auto Resize",		"[Menu-Auto Resize]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_SELECT_IMAGE,				"Select Image",		"[Menu-Select Image]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_SAVE_AS,						 "Save As",		"[Menu-Save As]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_EDIT_FILENAME,				"Edit Filename",		"[Menu-Edit Filename]");	
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_EXIT,						"Exit",				"[OSD-Exit]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_NOTIFY_IMAGE_TOO_WIDE,
									"Image too wide. Unable to clip",
									"[Notify-Image too wide. Unable to clip]");	
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_NOTIFY_FREE_SPACE_NOT_ENOUGH,
									"Free space not enoguth. Please delete some file first",
									"[Notify-Free space not enough]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_NOTIFY_UNLOCK_MEMORY_CARD,
									"Please unlocd memory card to save edited file",
									"[Notify-Unlock card]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_NOTIFY_EXIT_CONFIRM,
									"Exit without saving?",
									"[Notify-Exit confirm]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_NOTIFY_FILE_NOT_SAVED,
									"File not saved",
									"[Notify-File not saved]");
	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_NOTIFY_EMPTY_STRING,
									"Empty String!",
									"[Notify-Empty string]");

	ADD_APPLICATION_STRING2(STR_ID_IMGTILE_NOTIFY_DUPLICATE_FILE,
									"Duplicate Filename!",
									"[Notify-Duplicate Filename]");

}

/*****************************************************************************
* FUNCTION
*	PopulatePhotoEditorImgRes
* DESCRIPTION
*	Generate PhotoEditor related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulatePhotoEditorImgRes(void)
{	
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOEDT_APP_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SB_PhotoEditor.pbm", "IMG_ID_PHOEDT_APP_ICON" );
	

	/************* Photo Art **************/
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_APP_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\SB_PhotoArt.pbm", "IMG_ID_PHOART_APP_ICON" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_OPTION_ARROW,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_opt_arrow.gif", "IMG_ID_PHOART_OPTION_ARROW" );


	/* frame - use camera's frame */
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_1,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_01.gif", "IMG_ID_PHOART_FRAME_1" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_2,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_02.gif", "IMG_ID_PHOART_FRAME_2" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_3,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_03.gif", "IMG_ID_PHOART_FRAME_3" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_4,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_04.gif", "IMG_ID_PHOART_FRAME_4" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_5,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_05.gif", "IMG_ID_PHOART_FRAME_5" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_6,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_06.gif", "IMG_ID_PHOART_FRAME_6" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_7,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_07.gif", "IMG_ID_PHOART_FRAME_7" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_8,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_08.gif", "IMG_ID_PHOART_FRAME_8" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_9,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_09.gif", "IMG_ID_PHOART_FRAME_9" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FRAME_10,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_frame_10.gif", "IMG_ID_PHOART_FRAME_10" );	

	/* icons */
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_1,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_01.gif", "IMG_ID_PHOART_ICON_1" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_2,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_02.gif", "IMG_ID_PHOART_ICON_2" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_3,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_03.gif", "IMG_ID_PHOART_ICON_3" );

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_4,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_04.gif", "IMG_ID_PHOART_ICON_4" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_5,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_05.gif", "IMG_ID_PHOART_ICON_5" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_6,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_06.gif", "IMG_ID_PHOART_ICON_6" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_7,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_07.gif", "IMG_ID_PHOART_ICON_7" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_8,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_08.gif", "IMG_ID_PHOART_ICON_8" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_9,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_09.gif", "IMG_ID_PHOART_ICON_9" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_10,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_10.gif", "IMG_ID_PHOART_ICON_10" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_11,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_11.gif", "IMG_ID_PHOART_ICON_11" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_12,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_12.gif", "IMG_ID_PHOART_ICON_12" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_13,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_13.gif", "IMG_ID_PHOART_ICON_13" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_14,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_14.gif", "IMG_ID_PHOART_ICON_14" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_15,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_15.gif", "IMG_ID_PHOART_ICON_15" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_16,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_16.gif", "IMG_ID_PHOART_ICON_16" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_17,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_17.gif", "IMG_ID_PHOART_ICON_17" );	
	
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ICON_18,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_icon_18.gif", "IMG_ID_PHOART_ICON_18" );		

	/* text */
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_TEXT_TEXT_COLOR,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_text_color.pbm", "IMG_ID_PHOART_TEXT_TEXT_COLOR" );	
	
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_TEXT_BORDER_COLOR,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_text_border.pbm", "IMG_ID_PHOART_TEXT_BORDER_COLOR" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_TEXT_SHADOW_COLOR,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_text_shadow.pbm", "IMG_ID_PHOART_TEXT_SHADOW_COLOR" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_TEXT_SIZE,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_text_size.pbm", "IMG_ID_PHOART_TEXT_SIZE" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_TEXT_ITALIC,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_text_italic.pbm", "IMG_ID_PHOART_TEXT_ITALIC" );

#ifdef __MMI_PHOART_EFFECT_SUPPORT__
	/* adjust */
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_BRIGHTNESS,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_bright.gif", "IMG_ID_PHOART_ADJUST_BRIGHTNESS" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_CONTRAST,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_contrast.gif", "IMG_ID_PHOART_ADJUST_CONTRAST" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_HUE,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_hue.gif", "IMG_ID_PHOART_ADJUST_HUE" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_SATURATION,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_saturation.gif", "IMG_ID_PHOART_ADJUST_SATURATION" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_COLOR_R,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_color_r.gif", "IMG_ID_PHOART_ADJUST_COLOR_R" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_COLOR_G,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_color_g.gif", "IMG_ID_PHOART_ADJUST_COLOR_G" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_COLOR_B,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_color_b.gif", "IMG_ID_PHOART_ADJUST_COLOR_B" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_BRIGHTNESS_HILIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_bright_h.gif", "IMG_ID_PHOART_ADJUST_BRIGHTNESS_HILIGHT" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_CONTRAST_HILIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_contrast_h.gif", "IMG_ID_PHOART_ADJUST_CONTRAST_HILIGHT" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_HUE_HILIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_hue_h.gif", "IMG_ID_PHOART_ADJUST_HUE_HILIGHT" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_SATURATION_HILIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_saturation_h.gif", "IMG_ID_PHOART_ADJUST_SATURATION_HILIGHT" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_COLOR_R_HILIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_color_r_h.gif", "IMG_ID_PHOART_ADJUST_COLOR_R_HILIGHT" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_COLOR_G_HILIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_color_g_h.gif", "IMG_ID_PHOART_ADJUST_COLOR_G_HILIGHT" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_COLOR_B_HILIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_color_b_h.gif", "IMG_ID_PHOART_ADJUST_COLOR_B_HILIGHT" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_SLIDER,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_slider.gif", "IMG_ID_PHOART_ADJUST_SLIDER" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_ADJUST_BAR,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_adj_bar.gif", "IMG_ID_PHOART_ADJUST_BAR" );	
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FLIP_VER_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_ver.pbm", "IMG_ID_PHOART_FLIP_VER_ICON" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FLIP_VER_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_ver_sel.pbm", "IMG_ID_PHOART_FLIP_VER_ICON_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FLIP_HOR_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_hor.pbm", "IMG_ID_PHOART_FLIP_HOR_ICON" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_FLIP_HOR_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_flip_hor_sel.pbm", "IMG_ID_PHOART_FLIP_HOR_ICON_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_SCALE_UP_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_up.pbm", "IMG_ID_PHOART_SCALE_UP_ICON" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_SCALE_UP_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_up_sel.pbm", "IMG_ID_PHOART_SCALE_UP_ICON_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_SCALE_DOWN_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_down.pbm", "IMG_ID_PHOART_SCALE_DOWN_ICON" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_SCALE_DOWN_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_scale_down_sel.pbm", "IMG_ID_PHOART_SCALE_DOWN_ICON_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_EDIT_STAMP_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_edit_stamp_sel.pbm", "IMG_ID_PHOART_EDIT_STAMP_ICON" );	
		
	ADD_APPLICATION_IMAGE2(IMG_ID_PHOART_EDIT_STAMP_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\PA_edit_stamp.pbm", "IMG_ID_PHOART_EDIT_STAMP_ICON_SEL" );	

	/************* Image Tile **************/

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_APP,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_app_icon.pbm", "IMG_ID_IMGTILE_APP" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_TILE_2,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_tile_2.pbm", "IMG_ID_IMGTILE_TILE_2" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_TILE_4,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_tile_4.pbm", "IMG_ID_IMGTILE_TILE_4" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_TILE_9,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_tile_9.pbm", "IMG_ID_IMGTILE_TILE_9" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_2TILE_IMAGE_1,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_2tile_image_1.gif", "IMG_ID_IMGTILE_2TILE_IMAGE_1" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_2TILE_IMAGE_2,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_2tile_image_2.gif", "IMG_ID_IMGTILE_2TILE_IMAGE_2" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_4TILE_IMAGE_1,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_4tile_image_1.gif", "IMG_ID_IMGTILE_4TILE_IMAGE_1" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_4TILE_IMAGE_2,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_4tile_image_2.gif", "IMG_ID_IMGTILE_4TILE_IMAGE_2" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_4TILE_IMAGE_3,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_4tile_image_3.gif", "IMG_ID_IMGTILE_4TILE_IMAGE_3" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_4TILE_IMAGE_4,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_4tile_image_4.gif", "IMG_ID_IMGTILE_4TILE_IMAGE_4" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_1,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_1.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_1" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_2,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_2.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_2" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_3,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_3.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_3" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_4,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_4.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_4" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_5,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_5.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_5" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_6,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_6.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_6" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_7,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_7.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_7" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_8,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_8.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_8" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_9TILE_IMAGE_9,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_9tile_image_9.gif", "IMG_ID_IMGTILE_9TILE_IMAGE_9" );

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_FLIP_HOR_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_flip_hor.pbm", "IMG_ID_IMGTILE_FLIP_HOR_ICON" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_FLIP_HOR_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_flip_hor_sel.pbm", "IMG_ID_IMGTILE_FLIP_HOR_ICON_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_SCALE_UP_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_scale_up.pbm", "IMG_ID_IMGTILE_SCALE_UP_ICON" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_SCALE_UP_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_scale_up_sel.pbm", "IMG_ID_IMGTILE_SCALE_UP_ICON_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_SCALE_DOWN_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_scale_down.pbm", "IMG_ID_IMGTILE_SCALE_DOWN_ICON" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_IMGTILE_SCALE_DOWN_ICON_SEL,		
		CUST_IMG_PATH"\\\\MainLCD\\\\PhotoEditor\\\\IT_scale_down_sel.pbm", "IMG_ID_IMGTILE_SCALE_DOWN_ICON_SEL" );	

}


/*****************************************************************************
* FUNCTION
*	PopulatePhotoEditorMenuRes
* DESCRIPTION
*	Generate PhotoEditor related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulatePhotoEditorMenuRes(void)
{	

	/************* Photo Editor **************/
#if defined(__MMI_VERSION_2__)
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOEDT_APP, 
		MAIN_MENU_MULTIMEDIA_MENUID,
		PHOEDT_APP_COUNT,

		#ifdef __PHOEDT_FEATURE_PHOART__
			MENU_ID_PHOART_APP,
		#endif

		#ifdef __PHOEDT_FEATURE_SCENMAST__
			MENU_ID_SCENMAST_APP,
		#endif

		#ifdef __PHOEDT_FEATURE_IMGTILE__
			MENU_ID_IMGTILE_APP,
		#endif
	
		SHOW,
		NONMOVEABLE,
		DISP_LIST,
		STR_ID_PHOEDT_APP_NAME,
		IMG_ID_PHOEDT_APP_ICON));

#else
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOEDT_APP, 
		MAIN_MENU_MULTIMEDIA_MENUID,
		PHOEDT_APP_COUNT,

    #ifdef __PHOEDT_FEATURE_PHOART__
		MENU_ID_PHOART_APP,
    #endif

    #ifdef __PHOEDT_FEATURE_SCENMAST__
		MENU_ID_SCENMAST_APP,
    #endif

    #ifdef __PHOEDT_FEATURE_IMGTILE__
		MENU_ID_IMGTILE_APP,
    #endif
		SHOW,
		NONMOVEABLE,
		DISP_LIST,
		STR_ID_PHOEDT_APP_NAME,
		IMG_ID_PHOEDT_APP_ICON));

    #ifdef __MMI_OP01_MENU_NOSIM_LIST__
        ADD_APPLICATION_MENUITEM((MENU_ID_PHOEDT_APP, 
            MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID,
            PHOEDT_APP_COUNT,

        #ifdef __PHOEDT_FEATURE_PHOART__
            MENU_ID_PHOART_APP,
        #endif

        #ifdef __PHOEDT_FEATURE_SCENMAST__
            MENU_ID_SCENMAST_APP,
        #endif

        #ifdef __PHOEDT_FEATURE_IMGTILE__
            MENU_ID_IMGTILE_APP,
        #endif

            SHOW,
            NONMOVEABLE,
            DISP_LIST,
            STR_ID_PHOEDT_APP_NAME,
            IMG_ID_PHOEDT_APP_ICON));
    #endif /* __MMI_OP01_MENU_NOSIM_LIST__ */
		
#endif	/* __MMI_VERSION_2__ */
	


	
	/************* Photo Art **************/
	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_APP, MENU_ID_PHOEDT_APP, 0,
					SHOW, MOVEABLEACROSSPARENT|SHORTCUTABLE, 1, STR_ID_PHOART_APP, IMG_ID_PHOART_APP_ICON));	



	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOART_CLIP, 
										0,
										#ifdef __MMI_SUBLCD__
											3,
										#else
											2,
										#endif /* __MMI_SUBLCD__ */
										
										MENU_ID_PHOART_AUTO_RESIZE,
										MENU_ID_PHOART_MAINLCD_CLIP,

										#ifdef __MMI_SUBLCD__
											MENU_ID_PHOART_SUBLCD_CLIP,
										#endif /* __MMI_SUBLCD__ */	
																				
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_PHOART_CLIP,
										0));		


	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_AUTO_RESIZE, MENU_ID_PHOART_CLIP, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_AUTO_RESIZE, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_MAINLCD_CLIP, MENU_ID_PHOART_CLIP, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_MAINLCD_CLIP, 0));	
	
	#ifdef __MMI_SUBLCD__
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_SUBLCD_CLIP, MENU_ID_PHOART_CLIP, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_SUBLCD_CLIP, 0));	
	#endif /* __MMI_SUBLCD__ */	


#ifdef __MMI_PHOART_EFFECT_SUPPORT__
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOART_OPTION, 
										0,
									#ifndef __MMI_TOUCH_SCREEN__										
										9,
									#else
										8,
									#endif
										MENU_ID_PHOART_SAVE_AS,
										MENU_ID_PHOART_ADD_EFFECT,
										MENU_ID_PHOART_ADD_FRAME,
										MENU_ID_PHOART_ADD_ICON,
										MENU_ID_PHOART_ADD_TEXT,
										MENU_ID_PHOART_ADJUST_OPTION,
										MENU_ID_PHOART_FLIP,
										MENU_ID_PHOART_EXPAND_CANVAS,
									#ifndef __MMI_TOUCH_SCREEN__
										MENU_ID_PHOART_HELP,
									#endif
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_PHOART_CLIP,
										0));
#else  /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */
    ADD_APPLICATION_MENUITEM((  MENU_ID_PHOART_OPTION, 
                                        0,
                                    #ifndef __MMI_TOUCH_SCREEN__                                        
                                        7,
                                    #else
                                        6,
                                    #endif
                                        MENU_ID_PHOART_SAVE_AS,
                                        MENU_ID_PHOART_ADD_FRAME,
                                        MENU_ID_PHOART_ADD_ICON,
                                        MENU_ID_PHOART_ADD_TEXT,
                                        MENU_ID_PHOART_FLIP,
                                        MENU_ID_PHOART_EXPAND_CANVAS,
                                    #ifndef __MMI_TOUCH_SCREEN__
                                        MENU_ID_PHOART_HELP,
                                    #endif
                                        SHOW,
                                        NONMOVEABLE,
                                        DISP_LIST,
                                        STR_ID_PHOART_CLIP,
                                        0));
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */
	
	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_SAVE_AS, MENU_ID_PHOART_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_SAVE_AS, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_ADD_ICON, MENU_ID_PHOART_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_ADD_ICON, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_ADD_TEXT, MENU_ID_PHOART_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_ADD_TEXT, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EXPAND_CANVAS, MENU_ID_PHOART_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EXPAND_CANVAS, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_HELP, MENU_ID_PHOART_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_HELP, 0));


	/* editor option screen */
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOART_EDITOR_OPTION, 
										0,
										3,
										MENU_ID_PHOART_EDITOR_DONE,
										MENU_ID_PHOART_EDITOR_CANCEL,
										MENU_ID_PHOART_EDITOR_INPUT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_GLOBAL_OPTIONS,
										0));	


	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EDITOR_DONE, MENU_ID_PHOART_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_DONE, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EDITOR_CANCEL, MENU_ID_PHOART_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_CANCEL, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EDITOR_INPUT, MENU_ID_PHOART_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_INPUT_METHOD, 0));

	/* add effect */
#ifdef __MMI_PHOART_EFFECT_SUPPORT__    
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOART_ADD_EFFECT, 
										MENU_ID_PHOART_OPTION,
										PHOART_EFFECT_COUNT,
										
										#ifdef PHOART_FEATURE_EFFECT_GRAYSCALE
											MENU_ID_PHOART_EFFECT_GRAYSCALE,
										#endif
										
										#ifdef PHOART_FEATURE_EFFECT_SEPIA
											MENU_ID_PHOART_EFFECT_SEPIA,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_SEPIA_GREEN
											MENU_ID_PHOART_EFFECT_SEPIA_GREEN,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_SEPIA_BLUE
											MENU_ID_PHOART_EFFECT_SEPIA_BLUE,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_COLOR_INVERT
											MENU_ID_PHOART_EFFECT_COLOR_INVERT,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_GRAY_INVERT
											MENU_ID_PHOART_EFFECT_GRAY_INVERT,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_WATER_COLOR
											MENU_ID_PHOART_EFFECT_WATER_COLOR,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_LIGHT_BLUR
											MENU_ID_PHOART_EFFECT_LIGHT_BLUR,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_BLUR
											MENU_ID_PHOART_EFFECT_BLUR,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_STRONG_BLUR
											MENU_ID_PHOART_EFFECT_STRONG_BLUR,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_UNSHARP
											MENU_ID_PHOART_EFFECT_UNSHARP,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_SHARPEN
											MENU_ID_PHOART_EFFECT_SHARPEN,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_MORE_SHARPEN
											MENU_ID_PHOART_EFFECT_MORE_SHARPEN,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_MEDIAN
											MENU_ID_PHOART_EFFECT_MEDIAN,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_DILATION
											MENU_ID_PHOART_EFFECT_DILATION,
										#endif

										#ifdef PHOART_FEATURE_EFFECT_EROSION
											MENU_ID_PHOART_EFFECT_EROSION,
										#endif
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_PHOART_ADD_EFFECT,
										0));	

	#ifdef PHOART_FEATURE_EFFECT_GRAYSCALE
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_GRAYSCALE, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_GRAYSCALE, 0));
	#endif /* PHOART_FEATURE_EFFECT_GRAYSCALE */

	#ifdef PHOART_FEATURE_EFFECT_SEPIA
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_SEPIA, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_SEPIA, 0));
	#endif /* PHOART_FEATURE_EFFECT_SEPIA */

	#ifdef PHOART_FEATURE_EFFECT_SEPIA_GREEN
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_SEPIA_GREEN, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_SEPIA_GREEN, 0));
	#endif /* PHOART_FEATURE_EFFECT_SEPIA_GREEN */

	#ifdef PHOART_FEATURE_EFFECT_SEPIA_BLUE
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_SEPIA_BLUE, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_SEPIA_BLUE, 0));
	#endif /* PHOART_FEATURE_EFFECT_SEPIA_BLUE */

	#ifdef PHOART_FEATURE_EFFECT_COLOR_INVERT
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_COLOR_INVERT, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_COLOR_INVERT, 0));
	#endif /* PHOART_FEATURE_EFFECT_COLOR_INVERT */

	#ifdef PHOART_FEATURE_EFFECT_GRAY_INVERT
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_GRAY_INVERT, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_GRAY_INVERT, 0));
	#endif /* PHOART_FEATURE_EFFECT_GRAY_INVERT */

	#ifdef PHOART_FEATURE_EFFECT_WATER_COLOR
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_WATER_COLOR, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_WATER_COLOR, 0));
	#endif /* PHOART_FEATURE_EFFECT_WATER_COLOR */
	
	#ifdef  PHOART_FEATURE_EFFECT_LIGHT_BLUR 
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_LIGHT_BLUR, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_LIGHT_BLUR, 0));
	#endif /* PHOART_FEATURE_EFFECT_LIGHT_BLUR */

	#ifdef PHOART_FEATURE_EFFECT_BLUR
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_BLUR, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_BLUR, 0));
	#endif /* PHOART_FEATURE_EFFECT_BLUR */
	
	#ifdef PHOART_FEATURE_EFFECT_STRONG_BLUR
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_STRONG_BLUR, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_STRONG_BLUR, 0));
	#endif /* PHOART_FEATURE_EFFECT_STRONG_BLUR */

	#ifdef PHOART_FEATURE_EFFECT_UNSHARP
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_UNSHARP, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_UNSHARP, 0));
	#endif /* PHOART_FEATURE_EFFECT_UNSHARP */

	#ifdef PHOART_FEATURE_EFFECT_SHARPEN
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_SHARPEN, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_SHARPEN, 0));
	#endif /* PHOART_FEATURE_EFFECT_SHARPEN */
	
	#ifdef PHOART_FEATURE_EFFECT_MORE_SHARPEN
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_MORE_SHARPEN, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_MORE_SHARPEN, 0));
	#endif /* PHOART_FEATURE_EFFECT_MORE_SHARPEN */

	#ifdef PHOART_FEATURE_EFFECT_MEDIAN
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_MEDIAN, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_MEDIAN, 0));
	#endif /* PHOART_FEATURE_EFFECT_MEDIAN */

	#ifdef PHOART_FEATURE_EFFECT_DILATION
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_DILATION, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_DILATION, 0));	
	#endif /* PHOART_FEATURE_EFFECT_DILATION */

	#ifdef  PHOART_FEATURE_EFFECT_EROSION 
		ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_EFFECT_EROSION, MENU_ID_PHOART_ADD_EFFECT, 0,
						SHOW, NONMOVEABLE, 1, STR_ID_PHOART_EFFECT_EROSION, 0));			
	#endif /* PHOART_FEATURE_EFFECT_EROSION */
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */

	/* add frame */
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOART_ADD_FRAME, 
										MENU_ID_PHOART_OPTION,
										10,
										MENU_ID_PHOART_FRAME_1,
										MENU_ID_PHOART_FRAME_2,
										MENU_ID_PHOART_FRAME_3,
										MENU_ID_PHOART_FRAME_4,
										MENU_ID_PHOART_FRAME_5,
										MENU_ID_PHOART_FRAME_6,
										MENU_ID_PHOART_FRAME_7,
										MENU_ID_PHOART_FRAME_8,
										MENU_ID_PHOART_FRAME_9,
										MENU_ID_PHOART_FRAME_10,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_PHOART_ADD_FRAME,
										0));	


	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_1, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_1, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_2, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_2, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_3, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_3, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_4, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_4, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_5, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_5, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_6, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_6, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_7, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_7, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_8, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_8, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_9, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_9, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FRAME_10, MENU_ID_PHOART_ADD_FRAME, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FRAME_10, 0));




	/* text editor option */
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOART_TEXT_EDITOR_OPTION, 
										0,
										3,
										MENU_ID_PHOART_TEXT_EDITOR_DONE,
										MENU_ID_PHOART_TEXT_EDITOR_CANCEL,
										MENU_ID_PHOART_TEXT_EDITOR_INPUT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_GLOBAL_OPTIONS,
										0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_TEXT_EDITOR_DONE, MENU_ID_PHOART_TEXT_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_DONE, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_TEXT_EDITOR_CANCEL, MENU_ID_PHOART_TEXT_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_CANCEL, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_TEXT_EDITOR_INPUT, MENU_ID_PHOART_TEXT_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_INPUT_METHOD, 0));
	
	/* adjust */
#ifdef __MMI_PHOART_EFFECT_SUPPORT__
	ADD_APPLICATION_MENUITEM((	MENU_ID_PHOART_ADJUST_OPTION, 
										MENU_ID_PHOART_OPTION,
										2,
										MENU_ID_PHOART_ADJUST_IMAGE_ADJUST,
										MENU_ID_PHOART_ADJUST_COLOR_ADJUST,										
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_PHOART_ADJUST,
										0));	
	
	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_ADJUST_IMAGE_ADJUST, MENU_ID_PHOART_ADJUST_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_ADJUST_IMAGE, 0));

	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_ADJUST_COLOR_ADJUST, MENU_ID_PHOART_ADJUST_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_ADJUST_COLOR, 0));
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */

	/* flip */
	ADD_APPLICATION_MENUITEM((MENU_ID_PHOART_FLIP, MENU_ID_PHOART_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_PHOART_FLIP, 0));	

	
	/************* Scene Master **************/
	ADD_APPLICATION_MENUITEM((MENU_ID_SCENMAST_APP, MENU_ID_PHOEDT_APP, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_SCENMAST_APP, 0));
	
	
	/************* Image Tile **************/
	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_APP, MENU_ID_PHOEDT_APP, 3,
										MENU_ID_IMGTILE_TILE_2,
										MENU_ID_IMGTILE_TILE_4,
										MENU_ID_IMGTILE_TILE_9,
					SHOW, NONMOVEABLE, DISP_LIST, STR_ID_IMGTILE_APP, IMG_ID_IMGTILE_APP));	

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_TILE_2, MENU_ID_IMGTILE_APP, 0,										
					SHOW, NONMOVEABLE, 1, STR_ID_IMGTILE_TILE_2, IMG_ID_IMGTILE_TILE_2));

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_TILE_4, MENU_ID_IMGTILE_APP, 0,										
					SHOW, NONMOVEABLE, 1, STR_ID_IMGTILE_TILE_4, IMG_ID_IMGTILE_TILE_4));

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_TILE_9, MENU_ID_IMGTILE_APP, 0,										
					SHOW, NONMOVEABLE, 1, STR_ID_IMGTILE_TILE_9, IMG_ID_IMGTILE_TILE_9));

	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGTILE_CLIP_OPTION, 
										0,
										2,
										MENU_ID_IMGTILE_CLIP_IMAGE,
										MENU_ID_IMGTILE_AUTO_RESIZE,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_IMGTILE_CLIP,
										0));		


	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_CLIP_IMAGE, MENU_ID_IMGTILE_CLIP_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_IMGTILE_CLIP_IMAGE, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_AUTO_RESIZE, MENU_ID_IMGTILE_CLIP_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_IMGTILE_AUTO_RESIZE, 0));	

	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGTILE_OPTION, 
										0,
										2,
										MENU_ID_IMGTILE_SELECT,
										MENU_ID_IMGTILE_SAVE_AS,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_GLOBAL_OPTIONS,
										0));		


	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_SELECT, MENU_ID_IMGTILE_CLIP_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_IMGTILE_SELECT_IMAGE, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_SAVE_AS, MENU_ID_IMGTILE_CLIP_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_ID_IMGTILE_SAVE_AS, 0));

	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGTILE_EDITOR_OPTION, 
										0,
										3,
										MENU_ID_IMGTILE_EDITOR_DONE,
										MENU_ID_IMGTILE_EDITOR_CANCEL,
										MENU_ID_IMGTILE_EDITOR_INPUT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_GLOBAL_OPTIONS,
										0));	


	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_EDITOR_DONE, MENU_ID_IMGTILE_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_DONE, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_EDITOR_CANCEL, MENU_ID_IMGTILE_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_CANCEL, 0));	

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGTILE_EDITOR_INPUT, MENU_ID_IMGTILE_EDITOR_OPTION, 0,
					SHOW, NONMOVEABLE, 1, STR_GLOBAL_INPUT_METHOD, 0));


	

}


/*****************************************************************************
* FUNCTION
*	PopulatePhotoEditorRes
* DESCRIPTION
*	Generate Camrea related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulatePhotoEditorRes(void)
{	
	PopulatePhotoEditorStrRes();
	PopulatePhotoEditorImgRes();	
	PopulatePhotoEditorMenuRes();		
}


#endif /* __MMI_PHOTOEDITOR__ */
#endif /* DEVELOPER_BUILD_FIRST_PASS */



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
 *	 Res_Camera.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Generate Camera Resources
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MMI_features.h"

#if defined(__MMI_CAMERA__) || defined(__MMI_IMAGE_VIEWER__)

#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#define __MMI_CAMERA_ONLY__
#include "MMI_features_camera.h"
#include "CameraResDef.h"			/* include this for Camera related resource IDs */
#include "ImageViewerResDef.h"	/* include this for ImageViewer related resource IDs */ 

#include "PopulateRes.h"
#include "CustResDef.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/

#if defined(__MMI_CAMERA__)
/*****************************************************************************
* FUNCTION
*	PopulateCameraStrRes
* DESCRIPTION
*	Generate Camrea related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateCameraStrRes(void)
{	
	/*********** Camera App *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_APP_NAME,	"Camera", "[Camera App Name]");

	
	/*********** Option Menu *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_TO_IMGVIEW,				"To Image Viewer",		"[Menu-To ImageView]");	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_CAMERA_SETTING,			"Camera Setting",		"[Menu-Camera Setting]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SETTING,			"Image Setting",		"[Menu-Image Setting]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_SETTING,			"Effect Setting",		"[Menu-Effect Setting]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME,				"Add Frame",			"[Menu-Add Frame]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_SELF_CAPTURE,			"Self Capture",		"[Menu-Self Capture]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_STORAGE,					"Storage",				"[Menu-Storage]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_RESTORE_DEFAULT,		"Restore Default",	"[Menu-Restore Default]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_METERING,				"Auto Focus",			"[Menu-Auto Focus]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_MODE,				"Auto Focus Mode","[Menu-Auto Focus]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE,					"DSC Mode",			"[Menu-Shot Mode]");	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB,							"White Balance",		"[Menu-White Balance]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_HELP,					"Manual help",			"Please take a white paper to config manual white balance setting.");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EXIT,					"Exit",			"Exit");

	
	/*********** Camera Setting *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_FLASH,						"Flash",					"[Menu-Flash]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT,			"LED Highlight",		"[Menu-LED Highlight]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_SHUTTER_SOUND,			"Shutter Sound",		"[Menu-Shutter Sound]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV,							"EV",						"[Menu-EV]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NIGHT,						"Night Mode",			"[Menu-Night Mode]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_CLOSEUP,					"Closeup Mode",		"[Menu-Closeup Mode]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_BANDING,					"Banding",				"[Menu-Banding]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_AE_METER,					"AE Meter",				"[Menu-AE Meter]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ISO,						"ISO",					"[Menu-ISO]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_DELAY_TIMER,				"Delay Timer",			"[Menu-Delay Timer]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_CONT_SHOT,				"Cont Shot",			"[Menu-Cont Shot]");
	/*********** Image Setting *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE,				"Image Size",			"[Menu-Image Size]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_QTY,				"Image Quality",		"[Menu-Image Quality]");

	/*********** Effect Setting *************/

#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_NORMAL,				"Normal",			"[Menu-Normal]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_GRAYSCALE,			"Grayscale",		"[Menu-Grayscale]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_SEPIA,				"Sepia",				"[Menu-Sepia]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_SEPIA_GREEN,		"Sepia Green",		"[Menu-Sepia Green]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_SEPIA_BLUE,			"Sepia Blue",		"[Menu-Sepia Blue]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_COLOR_INVERT,		"Color Invert",	"[Menu-Color Invert]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_GRAY_INVERT,		"Gray Invert",		"[Menu-Gray Invert]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_BLACKBOARD,			"Blackboard",		"[Menu-Blackboard]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_WHITEBOARD,			"Whiteboard",		"[Menu-Whiteboard]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_COPPER_CARVING,	"Copper Carving",	"[Menu-Copper Carving]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_BLUE_CARVING,		"Blue Carving",	"[Menu-Blue Carving]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_EMBOSSMENT,			"Embossment",		"[Menu-Embossment]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CONTRAST,			"Contrast",			"[Menu-Contrast]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_JEAN__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_JEAN,					"Jean",				"[Menu-Jean]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_SKETCH,				"Sketch",			"[Menu-Sketch]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_OIL__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_OIL,					"Oil",				"[Menu-Oil]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_1,		"Custom FX1",		"[Menu-Custom FX1]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_2,		"Custom FX2",		"[Menu-Custom FX2]");
#endif

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_3,		"Custom FX3",		"[Menu-Custom FX3]");
#endif

	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_SET,							"Set",					"[Menu-Set]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT,				"Edit Effect",			"[Menu-Edit Effect]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_RESTORE_DEFAULT,	"Restore Default",	"[Menu-Restore Default]");	

	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_BRIGHTNESS,				"Brightness",			"[Option-Brightness]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_SATURATION,				"Saturation",			"[Option-Saturation]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_CONTRAST,					"Contrast",				"[Option-Contrast]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EFFECT_CUSTOM_FX_HUE,							"Hue",					"[Option-Hue]");	

	/*********** Add Frame *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_OFF,			"Off",		"[Menu-Frame Off]");

#ifdef __CAMERA_FEATURE_ADD_FRAME_NORMAL__										
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_NORMAL,		"Wallpaper Frame",	"[Sub Menu-Wall Paper Frame]");
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_TILESHOT__	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_TILESHOT,	"Tile Shot Frame",	"[Sub Menu-Tile Shot Frame]");
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_COLOR_IDX,	"Color Index Frame",	"[Sub Menu-Color Idx Frame]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_1__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_1,				"Frame 1",		"[Menu-Frame 1]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_2__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_2,				"Frame 2",		"[Menu-Frame 2]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_3__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_3,				"Frame 3",		"[Menu-Frame 3]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_4__)|| defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_4__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_4,				"Frame 4",		"[Menu-Frame 4]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_5__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_5__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_5,				"Frame 5",		"[Menu-Frame 5]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_6__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_6__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_6,				"Frame 6",		"[Menu-Frame 6]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_7__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_7__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_7,				"Frame 7",		"[Menu-Frame 7]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_8__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_8__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_8,				"Frame 8",		"[Menu-Frame 8]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_9__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_9__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_9,				"Frame 9",		"[Menu-Frame 9]");
#endif

#if defined(__CAMERA_FEATURE_ADD_FRAME_10__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_10__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_10,			"Frame 10",		"[Menu-Frame 10]");
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_CUSTOM_1,	"<Empty>",		"[Menu-<Empty>]");
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_CUSTOM_2,	"<Empty>",		"[Menu-<Empty>]");
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_CUSTOM_3,	"<Empty>",		"[Menu-<Empty>]");
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_CUSTOM_4,	"<Empty>",		"[Menu-<Empty>]");
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_CUSTOM_5,	"<Empty>",		"[Menu-<Empty>]");
#endif
		
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_SET,				"Set",				"[Menu-Set]");	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_DE_ASSOCIATE,	"De-Associate",	"[Menu-De-Associate]");	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_ADD_FRAME_REPLACE,			"Replace",			"[Menu-Replace]");		

	/*********** Cont Shot *************/
#ifdef __CAMERA_FEATURE_CONT_SHOT__
	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_CONT_SHOT_OFF,		"Off",			"[Menu-Off]");	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_CONT_SHOT_1,			"1 Shot",		"[Menu-A Shot]");	

	#ifdef __CAMERA_FEATURE_CONT_SHOT_2__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_CONT_SHOT_2,			"3 Shot",		"[Menu-B Shot]");	
	#endif

	#ifdef __CAMERA_FEATURE_CONT_SHOT_3__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_CONT_SHOT_3,			"5 Shot",		"[Menu-C Shot]");		
	#endif
	
	#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_CONT_SHOT_BURST,	"Burst Shot",	"[Menu-Burst Shot]");		
	#endif
	
	#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__ 
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_CONT_SHOT_TILE,	"Tile Shot",	"[Menu-Tile Shot]");		
	#endif

#endif /* __CAMERA_FEATURE_CONT_SHOT__ */

	/************ Delay Timer *************/

#ifdef __CAMERA_FEATURE_DELAY_TIMER__

		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DELAY_TIMER_OFF,	"Off",			"[Menu-Off]");	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DELAY_TIMER_1,		"5 secs",			"[Menu-A sec]");	
	#ifdef __CAMERA_FEATURE_DELAY_TIMER_2__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DELAY_TIMER_2,		"10 secs",		"[Menu-B sec]");	
	#endif

	#ifdef __CAMERA_FEATURE_DELAY_TIMER_3__	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DELAY_TIMER_3,		"15 secs",		"[Menu-C sec]");		
	#endif
	
#endif /* __CAMERA_FEATURE_DELAY_TIMER__ */

	/*********** Storage *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_STORAGE_PHONE,			"Phone",				"[Menu-Phone]");	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_STORAGE_MEMORY_CARD,	"Memory Card",		"[Menu-Memory Card]");		

	/*********** WB *************/
#ifdef __CAMERA_FEATURE_WB__

	#ifdef __CAMERA_FEATURE_WB_AUTO__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_AUTO, "Auto", "[WB Auto]");
	#endif 

	#ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_DAYLIGHT,	"Daylight",	"[WB Daylight]");
	#endif 
				
	#ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_TUNGSTEN,	"Tungsten",	"[WB Tungsten]");
	#endif 

	#ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_FLUORESCENT,	"Fluorescent",	"[WB Flurescent]");
	#endif  

	#ifdef __CAMERA_FEATURE_WB_CLOUD__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_CLOUD,	"Cloud",	"[WB Cloud]");
	#endif	

	#ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_INCANDESCENCE, "Incandescence", "[WB Incandescence]");
	#endif	

	#ifdef __CAMERA_FEATURE_WB_MANUAL__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_WB_MANUAL,"Manual","[WB Manual]");
	#endif	

#endif /* __CAMERA_FEATURE_WB__ */

/*********** Auto Focus *************/

#ifdef __CAMERA_AUTOFOCUS_METERING__
	#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_1_ZONE, "AF One Zone", "[AF - One Zone]");
	#endif
	#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_3_ZONE, "AF 3 Zone", "[AF - 3 Zone]");
	#endif
	#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_5_ZONE, "AF 5 Zone", "[AF - 5 Zone]");
	#endif
#endif

#ifdef __CAMERA_AUTOFOCUS_MODE__
	#ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_MODE_AUTO, "AF Auto", "[AF - Manual]");
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_MODE_MACRO, "AF Macro", "[AF - Macro]");
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_MODE_INFINITE, "AF Infinite", "[AF - Infinite]");
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AUTOFOCUS_MODE_MANUAL, "AF Manual", "[AF - Manual]");
	#endif
#endif

/*********** Shot Mode *************/
#ifdef __CAMERA_DSC_MODE__
	#ifdef __CAMERA_DSC_MODE_AUTO__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_AUTO,				"Auto",	"[Menuitem-Auto]");
	#endif 
	#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_SHUTTER_PRI,	"Shutter Priority",	"[Menuitem-Shutter Priority]");
	#endif 
	#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_APERTURE_PRI,	"Aperture Priority",	"[Menuitem-Aperture Priority]");
	#endif 
	#ifdef __CAMERA_DSC_MODE_PORTRAIT__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_PORTRAIT,		"Portrait",	"[Menuitem-Portrait]");
	#endif 
	#ifdef __CAMERA_DSC_MODE_LANDSCAPE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_LANDSCAPE,		"Landscape",	"[Menuitem-Landscape]");
	#endif 
	#ifdef __CAMERA_DSC_MODE_SPORT__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_SPORT,			"Sport",	"[Menuitem-Sport]");
	#endif 
	#ifdef __CAMERA_DSC_MODE_FLOWER__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_FLOWER,			"Flower",	"[Menuitem-Flower]");
	#endif 
	#ifdef __CAMERA_DSC_MODE_NIGHT__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_DSC_MODE_NIGHT,			"Night",	"[Menuitem-Night]");
	#endif 
	#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
        ADD_APPLICATION_STRING2(STR_ID_CAMERA_ISO,			"ISO",	"[ISO]");
	#endif 	

#endif /* __CAMERA_DSC_MODE__ */


	/*********** Flash *************/
#if defined(__CAMERA_FEATURE_FLASH__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_FLASH_OFF, 	"Off", 	"[Inline-Flash Off]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_FLASH_ON, 	"On", 	"[Inline-Flash On]");
#endif

#ifdef __CAMERA_FEATURE_FLASH__
	#ifdef __CAMERA_FEATURE_FLASH_AUTO__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_FLASH_AUTO, 	"Auto", 	"[Inline-Flash Auto]");
	#endif

	#ifdef __CAMERA_FEATURE_FLASH_REDEYE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_FLASH_REDEYE, 	"Red Eye Reduction", "[Inline-Red Eye Reduction]");
	#endif	
#endif /* __CAMERA_FEATURE_FLASH__ */


	/*********** Led Highlight - on/off *************/
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_OFF, "Off", 	"[Inline-Led Highlight Off]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_ON, 	"On", 	"[Inline-Led Highlight On]");
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */


	/*********** Led Hihighlight - 7 color *************/
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_OFF,	 	"Off",		"[Inline-Led Highlight Off]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_WHITE,	"White",	 	"[Inline-Led Highlight White]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_RED, 	"Red", 		"[Inline-Led Highlight Red]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_GREEN,	"Green", 	"[Inline-Led Highlight Green]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_BLUE, 	"Blue", 		"[Inline-Led Highlight Blue]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_YELLOW, "Yellow", 	"[Inline-Led Highlight Yellow]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_PURPLE, "Purple", 	"[Inline-Led Highlight Purple]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_LED_HIGHLIGHT_CYAN,	"Cyan", 		"[Inline-Led Highlight CYAN]");
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */

	/*********** Shutter Sound *************/
#ifdef __CAMERA_FEATURE_SHUTTER_SOUND__

	#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_SHUTTER_SOUND_OFF,	"Off",		"[Inline-Shutter Sound Off]");
	#endif 

	#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_1__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_SHUTTER_SOUND_1,	"Sound 1",	"[Inline-Shutter Sound 1]");
	#endif 

	#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_2__	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_SHUTTER_SOUND_2,	"Sound 2",	"[Inline-Shutter Sound 2]");
	#endif 

	#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_3__	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_SHUTTER_SOUND_3,	"Sound 3",	"[Inline-Shutter Sound 3]");
	#endif 
	
#endif /* __CAMERA_FEATURE_SHUTTER_SOUND__ */

	/*********** EV *************/
#ifdef __CAMERA_FEATURE_EV__

	#ifdef __CAMERA_FEATURE_EV_4__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_N4,	"EV -4",	"[Inline-EV -4]");
	#endif 
	
	#ifdef __CAMERA_FEATURE_EV_3__	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_N3,	"EV -3",	"[Inline-EV -3]");
	#endif 

	#ifdef __CAMERA_FEATURE_EV_2__	
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_N2,	"EV -2",	"[Inline-EV -2]");
	#endif
	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_N1,		"EV -1",	"[Inline-EV -1]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_0,		"EV 0",	"[Inline-EV 0]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_P1,		"EV +1",	"[Inline-EV +1]");

	#ifdef __CAMERA_FEATURE_EV_2__		
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_P2,	"EV +2",	"[Inline-EV +2]");
	#endif 

	#ifdef __CAMERA_FEATURE_EV_3__		
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_P3,	"EV +3",	"[Inline-EV +3]");
	#endif

	#ifdef __CAMERA_FEATURE_EV_4__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_EV_P4,	"EV +4",	"[Inline-EV +4]");
	#endif 
#endif /* __CAMERA_FEATURE_EV__ */

	/*********** Night *************/
#ifdef __CAMERA_FEATURE_NIGHT__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NIGHT_OFF,	"Off",	"[Inline-Night Off]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NIGHT_ON,		"On",		"[Inline-Night On]");
#endif /* __CAMERA_FEATURE_NIGHT__ */

	/*********** Closeup *************/
#ifdef __CAMERA_FEATURE_CLOSEUP__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_CLOSEUP_OFF,	"Off",	"[Inline-Closeup Off]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_CLOSEUP_ON,	"On",		"[Inline-Closeup On]");
#endif /* __CAMERA_FEATURE_CLOSEUP__ */

	/*********** Banding *************/
#ifdef __CAMERA_FEATURE_BANDING__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_BANDING_50HZ,	"50Hz",	"[Inline-Banding 50Hz]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_BANDING_60HZ,	"60Hz",	"[Inline-Banding 60Hz]");
#endif /* __CAMERA_FEATURE_BANDING__ */

	/*********** Image Size *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_2048x1536,	"2048x1536",	"[2048x1536]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_1600x1200,	"1600x1200",	"[1600x1200]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_1280x1024,	"1280x1024",	"[1280x1024]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_1280x960,	"1280x960",		"[1280x960]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_800x600,	"800x600",		"[800x600]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_640x480,	"640x480",		"[640x480]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_320x240,	"320x240",		"[320x240]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_160x120,	"160x120",		"[160x120]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_80x60,		"80x60",			"[80x60]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_80x56,		"80x56",			"[80x56]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_240x320,	"240x320",		"[240x320]");	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_176x220,	"176x220",		"[176x220]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_128x160,	"128x160",		"[128x160]");	
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_128x128,	"128x128",		"[128x128]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_96x64,		"96x64",			"[96x64]");		
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_128x85,		"128x85",		"[128x85]");		
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_SIZE_UNDEFINE,	"Undefined",	"[Undefined]");

	/*********** Iamge Qty *************/
#ifdef __CAMERA_FEATURE_IMAGE_QTY_FINE__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_QTY_FINE,		"Fine",		"[Inline-Image Qty Fine");		
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_HIGH__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_QTY_HIGH,		"High",		"[Inline-Image Qty High");		
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_QTY_NORMAL,	"Normal", 	"[Inline-Image Qty Normal");			
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_LOW__
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_QTY_LOW,		"Low",		"[Inline-Image Qty Low");	
#endif 

	/*********** ISO *************/
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__

	#ifdef __CAEMRA_FEATURE_ISO_AUTO__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_ISO_AUTO,	"Auto",	"[Inline-Auto]");
	#endif 

	#ifdef __CAEMRA_FEATURE_ISO_100__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_ISO_100,	"Low",	"[Inline-100]");
	#endif 

	#ifdef __CAEMRA_FEATURE_ISO_200__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_ISO_200,	"Medium",	"[Inline-200]");
	#endif 

	#ifdef __CAEMRA_FEATURE_ISO_400__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_ISO_400,	"High",	"[Inline-400]");
	#endif 

#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */


	/*********** AE Meter *************/
#ifdef __CAMERA_FEATURE_AE_METER__

	#ifdef __CAMERA_FEATURE_AE_METER_AUTO__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AE_METER_AUTO,		"Auto",		"[Inline-Auto]");
	#endif 

	#ifdef __CAMERA_FEATURE_AE_METER_SPOT__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AE_METER_SPOT,		"Spot",		"[Inline-Spot]");
	#endif 

	#ifdef __CAMERA_FEATURE_AE_METER_CENTER__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AE_METER_CENTER,	"Weight",	"[Inline-Weight]");
	#endif 

	#ifdef __CAMERA_FEATURE_AE_METER_AVERAGE__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_AE_METER_AVERAGE,	"Average",	"[Inline-Average]");
	#endif 

#endif /* __CAMERA_FEATURE_AE_METER__ */



	/*********** notify *************/
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_DISK_FULL,"Disk Full","[Notify-Disk Full]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_NO_MEMORY_CARD,"No Memory Card","[Notify-No Memory Card]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_WRITE_PROTECTION,"Memory card is locked.\nCan't write in.","[Notify-Write Protection]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_HW_NOT_READY,"Camera module not ready.","[Notify-HW Not Ready]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_ERROR,"Camera Error","[Notify-Camera Error]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_ON,"Switch preview to SubLCD","[Notify-Self Capture On]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_OFF,"Switch preview to MainLCD","[Notify-Self Capture Off]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOFITY_SELF_CAPTURE_SUBLCD_PREVIEW,"Press * switch to MainLCD","[Notify-Press * Back]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOFIFY_CAPTURING,"Capturing..","[Notify-Capturing..]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOFIFY_BURST_CAPTURING,"Burst Capturing..","[Notify-Burst Capturing..]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_SAVING,"Saving..","[Notify-Saving..]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_SAVING_FAIL,"Saving Fail","[Notify-Saving Fail..]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_RESTORE_DEFAULT_CONFIRM,"Restore Default?","[Notify-Restore??]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_SAVE_CONFIRM,"Save?","[Notify-Save?]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_CAPTURE_FAILED,"Capture Failed","[Notify-Capture Failed]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_SCREEN_CAPTURED,"Snapshot","[Notify-Screen Snapshot]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_BT_IS_WORKING,"BT is working! Turn it off.","[Notify-STR_ID_CAMERA_NOTIFY_BT_IS_WORKING]");
        ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_XENON_TIMEOUT,"Charging Timeout! Stop Charging and Turn Flash OFF!","[Notify-Charging timeout]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_NOTIFY_XENON_LOW_BATTERY,"Low Battery! Turn Flash OFF!","[Notify-Low Battery]");

	#ifdef __MMI_CAMERA_23KEY__
		ADD_APPLICATION_STRING2(STR_ID_CAMERA_RSK_CAPTURE,								"Capture",												"[RSK-Capture]");
	#endif 

	#if defined(DOUBLE_CAMERA_SUPPORT)
	//Huyanwei Add it 
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_DOUBLE_MODE,				"Camera Switch",		"[Camera Switch");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_DOUBLE_MODE_MASTER,		"Main Camera",		"[Main Camera]");
	ADD_APPLICATION_STRING2(STR_ID_CAMERA_IMAGE_DOUBLE_MODE_SILVER,		"Sub  Camera",		"[Sub  Camera]");
	#endif


}
	#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
		
	void ADD_CAMERA_ZOOM_IMAGE(S32 idx, char *filepath)
	{
		ADD_APPLICATION_IMAGE2(idx,filepath,"IMG_ID_CAMERA_OSD_ZOOM_OOXX" );
	}
		
	#endif

/*****************************************************************************
* FUNCTION
*	PopulateCameraImgRes
* DESCRIPTION
*	Generate Camrea related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateCameraImgRes(void)
{	

/* define camera osd iamge path */
	#if defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
		/* icon panel osd */
		#define CAMERA_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD_ICONBAR\\\\"
	#else
		/* basic osd */
		#define CAMERA_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\"
	#endif
		

#if defined(DOUBLE_CAMERA_SUPPORT)
	//Huyanwei Add it 
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_DOUBLE_0,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_double_0.pbm", "CAMERA_DOUBLE_0" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_DOUBLE_1,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\OSD\\\\CAM_double_1.pbm", "CAMERA_DOUBLE_1" );	
#endif

	
	
	/*********** App *************/
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_APP_ICON,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\SB_camera.pbm", 	"IMG_ID_CAMERA_APP_ICON" );

#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_PREVIEW_SUBLCD_ICON,		
		CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\Camera\\\\SB_Camera.gif", 	"IMG_ID_CAMERA_PREVIEW_SUBLCD_ICON" );
#endif 

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_FORWARD_TO_MMS,		
		CAMERA_OSD_PATH"CAM_TO_MMS.pbm", 	"IMG_ID_CAMERA_FORWARD_TO_MMS" );

	/*********** Menu *************/
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TO_IMGVIEW,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_ImgViewer.pbm", "IMG_ID_CAMERA_TO_IMGVIEW" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_CAMERA_SETTING,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_CamSetting.pbm", "IMG_ID_CAMERA_CAMERA_SETTING" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SETTING,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_ImgSetting.pbm", "IMG_ID_CAMERA_IMAGE_SETTING" );


#ifdef __CAMERA_FEATURE_EFFECT__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_EFFECT_SETTING,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Effect.pbm", "IMG_ID_CAMERA_EFFECT_SETTING" );
#endif

#ifdef __CAMERA_DSC_MODE__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_DSC_MODE,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_DSC_Mode.pbm", "IMG_ID_CAMERA_SCENE_MODE" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Frame.pbm", "IMG_ID_CAMERA_ADD_FRAME" );

	#ifdef __CAMERA_FEATURE_ADD_FRAME_NORMAL__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_NORMAL,		
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Frame.pbm", "IMG_ID_CAMERA_ADD_FRAME_NORMAL" );
	#endif

	#ifdef __CAMERA_FEATURE_ADD_FRAME_TILESHOT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_TILESHOT,
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Frame.pbm", "IMG_ID_CAMERA_ADD_FRAME_TILESHOT" );
	#endif

	#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_COLOR_IDX,
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Frame.pbm", "IMG_ID_CAMERA_ADD_FRAME_COLOR_IDX" );
	#endif
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */


#ifdef __CAMERA_FEATURE_CONT_SHOT__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_CONT_SHOT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_ContShot.pbm", "IMG_ID_CAMERA_CONT_SHOT" );
#endif /* __CAMERA_FEATURE_CONT_SHOT__ */


#ifdef __CAMERA_FEATURE_DELAY_TIMER__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_DELAY_TIMER,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Timer.pbm", "IMG_ID_CAMERA_DELAY_TIMER" );
#endif /* __CAMERA_FEATURE_DELAY_TIMER__ */


#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_SELF_CAPTURE,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_SelfCap.pbm", "IMG_ID_CAMERA_SELF_CAPTURE" );
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */

#ifdef __CAMERA_AUTOFOCUS__
	#ifdef __CAMERA_AUTOFOCUS_METERING__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_METERING,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_AF_METERING.pbm", "IMG_ID_CAMERA_AUTOFOCUS" );
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_MODE,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_AF_MODE.pbm", "IMG_ID_CAMERA_AUTOFOCUS_MODE" );
	#endif
#endif /* __CAMERA_AUTOFOCUS__ */


#ifdef __CAMERA_FEATURE_STORAGE__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_STORAGE,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Storage.pbm", "IMG_ID_CAMERA_STORAGE" );
#endif	/* __CAMERA_FEATURE_STORAGE__ */

		
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_RESTORE_DEFAULT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Restore.pbm", "IMG_ID_CAMERA_RESTORE_DEFAULT" );



	/*********** Camerar Setting *************/
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_WB,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_WB.pbm", "IMG_ID_CAMERA_WB" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_FLASH,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Flash.pbm", "IMG_ID_CAMERA_FLASH" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_LED_HIGHLIGHT,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Highlight.pbm", "IMG_ID_CAMERA_LED_HIGHLIGHT" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_SHUTTER_SOUND,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Sound.pbm", "IMG_ID_CAMERA_SHUTTER_SOUND" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_EV,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_EV.pbm", "IMG_ID_CAMERA_EV" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_NIGHT,		
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Night.pbm", "IMG_ID_CAMERA_NIGHT" );

	#ifdef __CAMERA_FEATURE_AE_METER__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AE_METER,		
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_AE_Meter.pbm", "IMG_ID_CAMERA_AE_METER" );
	#endif /* __CAMERA_DSC_MODE_ISO__ */

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_BANDING,		
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Banding.pbm", "IMG_ID_CAMERA_BANDING" );

	#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ISO,		
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_ISO.pbm", "IMG_ID_CAMERA_ISO" );
	#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */

	/*********** Image Setting *************/
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE,		
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Size.pbm", "IMG_ID_CAMERA_IMAGE_SIZE" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_QTY,		
			CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Quality.pbm", "IMG_ID_CAMERA_IMAGE_QTY" );

	/*********** WB *************/
#ifdef __CAMERA_FEATURE_WB__

	#ifdef __CAMERA_FEATURE_WB_AUTO__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_AUTO,		
			CAMERA_OSD_PATH"CAM_wb_auto.pbm", "IMG_ID_CAMERA_OSD_WB_AUTO" );
	#endif 

	#ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_DAYLIGHT,		
			CAMERA_OSD_PATH"CAM_wb_day.pbm", "IMG_ID_CAMERA_OSD_WB_DAYLIGHT" );
	#endif 
				
	#ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_TUNGSTEN,		
			CAMERA_OSD_PATH"CAM_wb_tung.pbm", "IMG_ID_CAMERA_OSD_WB_TUNGSTEN" );
	#endif 

	#ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_FLUORESCENT,		
			CAMERA_OSD_PATH"CAM_wb_fluo.pbm", "IMG_ID_CAMERA_OSD_WB_FLUORESCENT" );
	#endif  

	#ifdef __CAMERA_FEATURE_WB_CLOUD__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_CLOUD,		
			CAMERA_OSD_PATH"CAM_wb_cloud.pbm", "IMG_ID_CAMERA_OSD_WB_CLOUD" );
	#endif	

	#ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_INCANDESCENCE,		
			CAMERA_OSD_PATH"CAM_wb_incan.pbm", "IMG_ID_CAMERA_OSD_WB_INCANDESCENCE" );
	#endif	

	#ifdef __CAMERA_FEATURE_WB_MANUAL__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_MANUAL,		
			CAMERA_OSD_PATH"CAM_wb_manual.pbm", "IMG_ID_CAMERA_OSD_WB_MANUAL" );
	#endif	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_LEFT_ARROW_UP,		
		CAMERA_OSD_PATH"CAM_wb_left_arrow.pbm", "IMG_ID_CAMERA_OSD_WB_LEFT_ARROW_UP" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_RIGHT_ARROW_UP,		
		CAMERA_OSD_PATH"CAM_wb_right_arrow.pbm", "IMG_ID_CAMERA_OSD_WB_RIGHT_ARROW_UP" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_LEFT_ARROW_DOWN,		
		CAMERA_OSD_PATH"CAM_wb_left_arrow_sel.pbm", "IMG_ID_CAMERA_OSD_WB_LEFT_ARROW_DOWN" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_WB_RIGHT_ARROW_DOWN,		
		CAMERA_OSD_PATH"CAM_wb_right_arrow_sel.pbm", "IMG_ID_CAMERA_OSD_WB_RIGHT_ARROW_DOWN" );


#endif /* __CAMERA_FEATURE_WB__ */

	/*********** Flash *************/
#ifdef __CAMERA_FEATURE_FLASH__

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_FLASH_CHARGING,
		CAMERA_OSD_PATH"CAM_flash_charging.pbm", "IMG_ID_CAMERA_FLASH_CHARGING" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_FLASH_FULL,
		CAMERA_OSD_PATH"CAM_flash_full.pbm", "IMG_ID_CAMERA_FLASH_FULL" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_FLASH_OFF,		
		CAMERA_OSD_PATH"CAM_flash_off.pbm", "IMG_ID_CAMERA_OSD_FLASH_OFF" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_FLASH_ON,		
		CAMERA_OSD_PATH"CAM_flash_on.pbm", "IMG_ID_CAMERA_OSD_FLASH_ON" );

	#ifdef __CAMERA_FEATURE_FLASH_AUTO__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_FLASH_AUTO,		
			CAMERA_OSD_PATH"CAM_flash_auto.pbm", "IMG_ID_CAMERA_OSD_FLASH_AUTO" );
	#endif

	#ifdef __CAMERA_FEATURE_FLASH_REDEYE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_FLASH_REDEYE,		
			CAMERA_OSD_PATH"CAM_flash_redeye.pbm", "IMG_ID_CAMERA_OSD_FLASH_REDEYE" );
	#endif	

#endif /* __CAMERA_FEATURE_FLASH__ */

	/*********** Led Highlight *************/
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_OFF,		
			CAMERA_OSD_PATH"CAM_led_off.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_OFF" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_ON,		
			CAMERA_OSD_PATH"CAM_led_on.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_ON" );

#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_OFF,		
			CAMERA_OSD_PATH"CAM_led_off.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_OFF" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_WHITE,		
			CAMERA_OSD_PATH"CAM_led_white.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_WHITE" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_RED,		
			CAMERA_OSD_PATH"CAM_led_red.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_RED" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_GREEN,		
			CAMERA_OSD_PATH"CAM_led_green.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_GREEN" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_BLUE,		
			CAMERA_OSD_PATH"CAM_led_blue.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_BLUE" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_PURPLE,		
			CAMERA_OSD_PATH"CAM_led_purple.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_PURPLE" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_YELLOW,		
			CAMERA_OSD_PATH"CAM_led_yellow.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_YELLOW" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_CYAN,
			CAMERA_OSD_PATH"CAM_led_cyan.pbm", "IMG_ID_CAMERA_OSD_LED_HIGHLIGHT_CYAN" );

#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__ */

	/*********** EV *************/
#ifdef __CAMERA_FEATURE_EV__

	#ifdef __CAMERA_FEATURE_EV_4__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_P4,		
			CAMERA_OSD_PATH"CAM_ev_p4.pbm", "IMG_ID_CAMERA_OSD_EV_P4" );
	#endif 
	
	#ifdef __CAMERA_FEATURE_EV_3__	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_P3,		
			CAMERA_OSD_PATH"CAM_ev_p3.pbm", "IMG_ID_CAMERA_OSD_EV_P3" );
	#endif 

	#ifdef __CAMERA_FEATURE_EV_2__	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_P2,		
			CAMERA_OSD_PATH"CAM_ev_p2.pbm", "IMG_ID_CAMERA_OSD_EV_P2" );
	#endif
	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_P1,		
			CAMERA_OSD_PATH"CAM_ev_p1.pbm", "IMG_ID_CAMERA_OSD_EV_P1" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_0,		
			CAMERA_OSD_PATH"CAM_ev_0.pbm", "IMG_ID_CAMERA_OSD_EV_0" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_N1,		
			CAMERA_OSD_PATH"CAM_ev_n1.pbm", "IMG_ID_CAMERA_OSD_EV_N1" );

	#ifdef __CAMERA_FEATURE_EV_2__		
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_N2,		
			CAMERA_OSD_PATH"CAM_ev_n2.pbm", "IMG_ID_CAMERA_OSD_EV_N2" );
	#endif 

	#ifdef __CAMERA_FEATURE_EV_3__		
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_N3,		
			CAMERA_OSD_PATH"CAM_ev_n3.pbm", "IMG_ID_CAMERA_OSD_EV_N3" );
	#endif

	#ifdef __CAMERA_FEATURE_EV_4__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_N4,		
			CAMERA_OSD_PATH"CAM_ev_n4.pbm", "IMG_ID_CAMERA_OSD_EV_N4" );
	#endif 

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_INC,		
			CAMERA_OSD_PATH"CAM_ev_inc.pbm", "IMG_ID_CAMERA_OSD_EV_INC" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_INC_SEL,		
			CAMERA_OSD_PATH"CAM_ev_inc_sel.pbm", "IMG_ID_CAMERA_OSD_EV_INC_SEL" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_DEC,		
			CAMERA_OSD_PATH"CAM_ev_dec.pbm", "IMG_ID_CAMERA_OSD_EV_DEC" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EV_DEC_SEL,		
			CAMERA_OSD_PATH"CAM_ev_dec_sel.pbm", "IMG_ID_CAMERA_OSD_EV_DEC_SEL" );		
	

	
#endif /* __CAMERA_FEATURE_EV__ */

	/*********** Night *************/
#ifdef __CAMERA_FEATURE_NIGHT__

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_NIGHT_OFF,		
		CAMERA_OSD_PATH"CAM_night_off.pbm", "IMG_ID_CAMERA_OSD_NIGHT_OFF" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_NIGHT_ON,		
		CAMERA_OSD_PATH"CAM_night_on.pbm", "IMG_ID_CAMERA_OSD_NIGHT_ON" );
	
#endif /* __CAMERA_FEATURE_NIGHT__ */

	/*********** Closeup *************/
#ifdef __CAMERA_FEATURE_CLOSEUP__

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CLOSEUP_OFF,		
		CAMERA_OSD_PATH"CAM_close_off.pbm", "IMG_ID_CAMERA_OSD_CLOSEUP_OFF" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CLOSEUP_ON,		
		CAMERA_OSD_PATH"CAM_close_on.pbm", "IMG_ID_CAMERA_OSD_CLOSEUP_ON" );
	
#endif /* __CAMERA_FEATURE_CLOSEUP__ */

	/*********** Image Size *************/
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_2048x1536,
		CAMERA_OSD_PATH"CAM_imgsize_2048x1536.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_2048x1536" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_1600x1200,
		CAMERA_OSD_PATH"CAM_imgsize_1600x1200.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_1600x1200" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_1280x1024,
		CAMERA_OSD_PATH"CAM_imgsize_1280x1024.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_1280x1024" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_1280x960,
		CAMERA_OSD_PATH"CAM_imgsize_1280x960.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_1280x960" );	
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_800x600,
		CAMERA_OSD_PATH"CAM_imgsize_800x600.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_800x600" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_640x480,
		CAMERA_OSD_PATH"CAM_imgsize_640x480.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_640x480" );	
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_320x240,
		CAMERA_OSD_PATH"CAM_imgsize_320x240.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_320x240" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_160x120,
		CAMERA_OSD_PATH"CAM_imgsize_160x120.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_160x120" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_80x60,
		CAMERA_OSD_PATH"CAM_imgsize_80x60.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_80x60" );		
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_80x56,
		CAMERA_OSD_PATH"CAM_imgsize_80x56.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_80x56" );		

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_240x320,
		CAMERA_OSD_PATH"CAM_imgsize_240x320.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_240x320" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_176x220,
		CAMERA_OSD_PATH"CAM_imgsize_176x220.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_176x220" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_128x160,
		CAMERA_OSD_PATH"CAM_imgsize_128x160.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_128x160" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_128x128,
		CAMERA_OSD_PATH"CAM_imgsize_128x128.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_128x128" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_96x64,
		CAMERA_OSD_PATH"CAM_imgsize_96x64.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_96x64" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_128x85,
		CAMERA_OSD_PATH"CAM_imgsize_128x85.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_128x85" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_IMAGE_SIZE_UNDEFINE,
		CAMERA_OSD_PATH"CAM_imgsize_undef.pbm", "IMG_ID_CAMERA_IMAGE_SIZE_UNDEFINE" );		



	/*********** Iamge Qty *************/
#ifdef __CAMERA_FEATURE_IMAGE_QTY_LOW__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_IMAGE_QTY_LOW,		
		CAMERA_OSD_PATH"CAM_imgqty_low.pbm", "IMG_ID_CAMERA_OSD_IMAGE_QTY_LOW" );
#endif

#ifdef __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_IMAGE_QTY_NORMAL,		
		CAMERA_OSD_PATH"CAM_imgqty_normal.pbm", "IMG_ID_CAMERA_OSD_IMAGE_QTY_NORMAL" );
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_HIGH__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_IMAGE_QTY_HIGH,		
		CAMERA_OSD_PATH"CAM_imgqty_high.pbm", "IMG_ID_CAMERA_OSD_IMAGE_QTY_HIGH" );
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_FINE__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_IMAGE_QTY_FINE,		
		CAMERA_OSD_PATH"CAM_imgqty_fine.pbm", "IMG_ID_CAMERA_OSD_IMAGE_QTY_FINE" );
#endif 


	/*********** Auto Focus *************/
#ifdef __CAMERA_AUTOFOCUS_METERING__
	#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AUTOFOCUS_1_ZONE,			
			CAMERA_OSD_PATH"CAM_af_1_zone.pbm", "IMG_ID_CAMERA_OSD_AUTOFOCUS_1_ZONE" );	
	#endif
	#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AUTOFOCUS_3_ZONE,			
			CAMERA_OSD_PATH"CAM_af_3_zone.pbm", "IMG_ID_CAMERA_OSD_AUTOFOCUS_3_ZONE" );	
	#endif
	#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AUTOFOCUS_5_ZONE,			
			CAMERA_OSD_PATH"CAM_af_5_zone.pbm", "IMG_ID_CAMERA_OSD_AUTOFOCUS_5_ZONE" );	
	#endif
#endif

#ifdef __CAMERA_AUTOFOCUS_MODE__
	#ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_AUTO,			
			CAMERA_OSD_PATH"CAM_af_mode_auto.pbm", "IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_AUTO" );	
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_MACRO,			
			CAMERA_OSD_PATH"CAM_af_mode_macro.pbm", "IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_MACRO" );	
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_INFINITE,			
			CAMERA_OSD_PATH"CAM_af_mode_infinite.pbm", "IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_INFINITE" );	
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AUTOFOCUS_MODE_MANUAL,			
			CAMERA_OSD_PATH"CAM_af_mode_manual.pbm", "IMG_ID_CAMERA_OSD_AUTOFOCUS_MANUAL_MODE_MANURL" );	
	#endif

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_NORMAL_WHITE,			
		CAMERA_OSD_PATH"CAM_af_white_normal.gif", "IMG_ID_CAMERA_AUTOFOCUS_NORMAL_WHITE" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_NORMAL_RED,			
		CAMERA_OSD_PATH"CAM_af_red_normal.gif", "IMG_ID_CAMERA_AUTOFOCUS_NORMAL_RED" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_NORMAL_GREEN,
		CAMERA_OSD_PATH"CAM_af_green_normal.gif", "IMG_ID_CAMERA_AUTOFOCUS_NORMAL_GREEN" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_SMALL_WHITE,
		CAMERA_OSD_PATH"CAM_af_white_small.gif", "IMG_ID_CAMERA_AUTOFOCUS_SMALL_WHITE" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_SMALL_RED,
		CAMERA_OSD_PATH"CAM_af_red_small.gif", "IMG_ID_CAMERA_AUTOFOCUS_SMALL_RED" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_SMALL_GREEN,
		CAMERA_OSD_PATH"CAM_af_green_small.gif", "IMG_ID_CAMERA_AUTOFOCUS_SMALL_GREE" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_SMALL_GRAY,
		CAMERA_OSD_PATH"CAM_af_gray_small.gif", "IMG_ID_CAMERA_AUTOFOCUS_SMALL_GRAY" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_LARGE_WHITE,
		CAMERA_OSD_PATH"CAM_af_white_large.gif", "IMG_ID_CAMERA_AUTOFOCUS_LARGE_WHITE" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_LARGE_RED,
		CAMERA_OSD_PATH"CAM_af_red_large.gif", "IMG_ID_CAMERA_AUTOFOCUS_LARGE_RED" );	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_AUTOFOCUS_LARGE_GREEN,
		CAMERA_OSD_PATH"CAM_af_green_large.gif", "IMG_ID_CAMERA_AUTOFOCUS_LARGE_GREEN" );	
	#endif 


	
	/*********** DSC Mode *************/
#ifdef __CAMERA_DSC_MODE__
	#ifdef __CAMERA_DSC_MODE_AUTO__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_AUTO,		
			CAMERA_OSD_PATH"CAM_DSCmode_auto.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_AUTO" );	
	#endif 
	#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_SHUTTER_PRI,		
			CAMERA_OSD_PATH"CAM_DSCmode_shutter.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_SHUTTER_PRI" );		
	#endif 
	#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_APERTURE_PRI,		
			CAMERA_OSD_PATH"CAM_DSCmode_aperture.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_APERTURE_PRI" );		
	#endif 
	#ifdef __CAMERA_DSC_MODE_PORTRAIT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_PORTRAIT,		
			CAMERA_OSD_PATH"CAM_DSCmode_portrait.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_PORTRAIT" );		
	#endif 
	#ifdef __CAMERA_DSC_MODE_LANDSCAPE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_LANDSCAPE,		
			CAMERA_OSD_PATH"CAM_DSCmode_landscape.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_LANDSCAPE" );		
	#endif 
	#ifdef __CAMERA_DSC_MODE_SPORT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_SPORT,		
			CAMERA_OSD_PATH"CAM_DSCmode_spot.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_SPORT" );		
	#endif 
	#ifdef __CAMERA_DSC_MODE_FLOWER__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_FLOWER,		
			CAMERA_OSD_PATH"CAM_DSCmode_flower.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_FLOWER" );		
	#endif 
	#ifdef __CAMERA_DSC_MODE_NIGHT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DSC_MODE_NIGHT,		
			CAMERA_OSD_PATH"CAM_DSCmode_night.pbm", "IMG_ID_CAMERA_OSD_DSC_MODE_NIGHT" );		
	#endif 

	
#endif /* __CAMERA_DSC_MODE__ */

	/*********** ISO *************/
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__

	#ifdef __CAEMRA_FEATURE_ISO_AUTO__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ISO_AUTO,		
			CAMERA_OSD_PATH"CAM_iso_auto.pbm", "IMG_ID_CAMERA_OSD_ISO_AUTO" );			
	#endif 

	#ifdef __CAEMRA_FEATURE_ISO_100__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ISO_100,		
			CAMERA_OSD_PATH"CAM_iso_100.pbm", "IMG_ID_CAMERA_OSD_ISO_100" );			
	#endif 

	#ifdef __CAEMRA_FEATURE_ISO_200__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ISO_200,		
			CAMERA_OSD_PATH"CAM_iso_200.pbm", "IMG_ID_CAMERA_OSD_ISO_200" );			
	#endif 

	#ifdef __CAEMRA_FEATURE_ISO_400__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ISO_400,		
			CAMERA_OSD_PATH"CAM_iso_400.pbm", "IMG_ID_CAMERA_OSD_ISO_400" );			
	#endif 

#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */


	/*********** AE Meter *************/
#ifdef __CAMERA_FEATURE_AE_METER__

	#ifdef __CAMERA_FEATURE_AE_METER_AUTO__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AE_METER_AUTO,		
			CAMERA_OSD_PATH"CAM_ae_meter_auto.pbm", "IMG_ID_CAMERA_OSD_AE_METER_AUTO" );		
	#endif 

	#ifdef __CAMERA_FEATURE_AE_METER_SPOT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AE_METER_SPOT,		
			CAMERA_OSD_PATH"CAM_ae_meter_spot.pbm", "IMG_ID_CAMERA_OSD_AE_METER_SPOT" );		
	#endif 

	#ifdef __CAMERA_FEATURE_AE_METER_CENTER__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AE_METER_CENTER,		
			CAMERA_OSD_PATH"CAM_ae_meter_center.pbm", "IMG_ID_CAMERA_OSD_AE_METER_CENTER" );		
	#endif 

	#ifdef __CAMERA_FEATURE_AE_METER_AVERAGE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_AE_METER_AVERAGE,		
			CAMERA_OSD_PATH"CAM_ae_meter_average.pbm", "IMG_ID_CAMERA_OSD_AE_METER_AVERAGE" );		
	#endif 

#endif /* __CAMERA_FEATURE_AE_METER__ */



	/*********** Add Frame Icon *************/
#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_1,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_1" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_2,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_2" );
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_3,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_3" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_4,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_4" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_5,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_5" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_6,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_6" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_7,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_7" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_8,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_8" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_9,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_9" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ADD_FRAME_10,		
		CAMERA_OSD_PATH"CAM_add_frame.pbm", "IMG_ID_CAMERA_OSD_ADD_FRAME_10" );
#endif 



	/*********** Add Frame *************/
#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_1,		
		CAMERA_OSD_PATH"CAM_frame_01.gif", "IMG_ID_CAMERA_ADD_FRAME_1" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_2,		
		CAMERA_OSD_PATH"CAM_frame_02.gif", "IMG_ID_CAMERA_ADD_FRAME_2" );
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_3,		
		CAMERA_OSD_PATH"CAM_frame_03.gif", "IMG_ID_CAMERA_ADD_FRAME_3" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_4,		
		CAMERA_OSD_PATH"CAM_frame_04.gif", "IMG_ID_CAMERA_ADD_FRAME_4" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_5,		
		CAMERA_OSD_PATH"CAM_frame_05.gif", "IMG_ID_CAMERA_ADD_FRAME_5" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_6,		
		CAMERA_OSD_PATH"CAM_frame_06.gif", "IMG_ID_CAMERA_ADD_FRAME_6" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_7,		
		CAMERA_OSD_PATH"CAM_frame_07.gif", "IMG_ID_CAMERA_ADD_FRAME_7" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_8,		
		CAMERA_OSD_PATH"CAM_frame_08.gif", "IMG_ID_CAMERA_ADD_FRAME_8" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_9,		
		CAMERA_OSD_PATH"CAM_frame_09.gif", "IMG_ID_CAMERA_ADD_FRAME_9" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ADD_FRAME_10,		
		CAMERA_OSD_PATH"CAM_frame_10.gif", "IMG_ID_CAMERA_ADD_FRAME_10" );
#endif 


	/*********** Tile Add Frame *************/
#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_1,		
		CAMERA_OSD_PATH"CAM_tile_frame_01.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_1" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_2,		
		CAMERA_OSD_PATH"CAM_tile_frame_02.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_2" );
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_3,		
		CAMERA_OSD_PATH"CAM_tile_frame_03.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_3" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_4,		
		CAMERA_OSD_PATH"CAM_tile_frame_04.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_4" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_5,		
		CAMERA_OSD_PATH"CAM_tile_frame_05.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_5" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_6,		
		CAMERA_OSD_PATH"CAM_tile_frame_06.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_6" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_7,		
		CAMERA_OSD_PATH"CAM_tile_frame_07.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_7" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_8,		
		CAMERA_OSD_PATH"CAM_tile_frame_08.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_8" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_9,		
		CAMERA_OSD_PATH"CAM_tile_frame_09.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_9" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_TILE_ADD_FRAME_10,		
		CAMERA_OSD_PATH"CAM_tile_frame_10.gif", "IMG_ID_CAMERA_TILE_ADD_FRAME_10" );
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_1,
		CAMERA_OSD_PATH"CAM_color_idx_frame_01.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_1" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_1,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_01.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_1" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_2,
		CAMERA_OSD_PATH"CAM_color_idx_frame_02.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_2" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_2,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_02.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_2" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_3,
		CAMERA_OSD_PATH"CAM_color_idx_frame_03.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_3" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_3,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_03.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_3" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_4__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_4,
		CAMERA_OSD_PATH"CAM_color_idx_frame_04.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_4" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_4,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_04.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_4" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_5__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_5,
		CAMERA_OSD_PATH"CAM_color_idx_frame_05.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_5" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_5,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_05.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_5" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_6__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_6,
		CAMERA_OSD_PATH"CAM_color_idx_frame_06.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_6" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_6,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_06.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_6" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_7__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_7,
		CAMERA_OSD_PATH"CAM_color_idx_frame_07.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_7" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_7,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_07.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_7" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_8__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_8,
		CAMERA_OSD_PATH"CAM_color_idx_frame_08.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_8" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_8,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_08.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_8" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_9__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_9,
		CAMERA_OSD_PATH"CAM_color_idx_frame_09.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_9" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_9,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_09.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_9" );
#endif

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_10__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_10,
		CAMERA_OSD_PATH"CAM_color_idx_frame_10.gif","IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_10" );
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_10,
		CAMERA_OSD_PATH"CAM_color_idx2_frame_10.gif","IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_10" );
#endif

	/********** Cont Shot **********/
#ifdef __CAMERA_FEATURE_CONT_SHOT__

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_OFF,		
		CAMERA_OSD_PATH"CAM_cshot_off.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_OFF" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_1,		
		CAMERA_OSD_PATH"CAM_cshot_1.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_1" );

	#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_1,		
			CAMERA_OSD_PATH"CAM_cshot_1_bar.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_1" );
	#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */

	#ifdef __CAMERA_FEATURE_CONT_SHOT_2__
	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_2,		
			CAMERA_OSD_PATH"CAM_cshot_2.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_2" );
	
		#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
			ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_2,		
				CAMERA_OSD_PATH"CAM_cshot_2_bar.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_2" );
		#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */
		
	#endif /* __CAMERA_FEATURE_CONT_SHOT_2__ */ 

	#ifdef __CAMERA_FEATURE_CONT_SHOT_3__
	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_3,		
			CAMERA_OSD_PATH"CAM_cshot_3.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_3" );	

		#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
			ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_3,		
				CAMERA_OSD_PATH"CAM_cshot_3_bar.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_2" );
		#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */
		
	#endif /* __CAMERA_FEATURE_CONT_SHOT_3__ */

	#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_BURST,		
			CAMERA_OSD_PATH"CAM_cshot_burst.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_BURST" );	
	#endif

	#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CONT_SHOT_TILE,	
			CAMERA_OSD_PATH"CAM_cshot_tile.pbm", "IMG_ID_CAMERA_OSD_CONT_SHOT_TILE" );	
	#endif		

#endif /* __CAMERA_FEATURE_CONT_SHOT__ */

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
#endif


	/********** Delay Timer ***********/
#ifdef __CAMERA_FEATURE_DELAY_TIMER__

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DELAY_TIMER_OFF,		
		CAMERA_OSD_PATH"CAM_dtime_off.pbm", "IMG_ID_CAMERA_OSD_DELAY_TIMER_OFF" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DELAY_TIMER_1,		
		CAMERA_OSD_PATH"CAM_dtime_1.pbm", "IMG_ID_CAMERA_OSD_DELAY_TIMER_1" );

	#ifdef __CAMERA_FEATURE_DELAY_TIMER_2__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DELAY_TIMER_2,		
			CAMERA_OSD_PATH"CAM_dtime_2.pbm", "IMG_ID_CAMERA_OSD_DELAY_TIMER_2" );
	#endif

	#ifdef __CAMERA_FEATURE_DELAY_TIMER_3__	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_DELAY_TIMER_3,		
			CAMERA_OSD_PATH"CAM_dtime_3.pbm", "IMG_ID_CAMERA_OSD_DELAY_TIMER_3" );
	#endif
	
#endif /* __CAMERA_FEATURE_DELAY_TIMER__ */


#ifdef __CAMERA_FEATURE_ZOOM__

	/********** Zooming ***********/
	#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__

	{
		int i;
		for (i = 1; i<= CAMERA_FEATURE_ZOOM_COUNT; i++)
		{
			char tmp[200]; 
			sprintf (tmp,"%sCAM_zoom_%d.pbm",CAMERA_OSD_PATH,g_camera_feature_zoom[i-1]);
			ADD_CAMERA_ZOOM_IMAGE(IMG_ID_CAMERA_OSD_ZOOM_START + i,tmp);
		}
	}

	#else
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ZOOM_BAR,		
			CAMERA_OSD_PATH"CAM_zoom_bar.pbm", "IMG_ID_CAMERA_OSD_ZOOM_BAR" );
	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ZOOM_SLIDER,		
			CAMERA_OSD_PATH"CAM_zoom_slider.pbm", "IMG_ID_CAMERA_OSD_ZOOM_SLIDER" );

		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ZOOM_INC,		
			CAMERA_OSD_PATH"CAM_zoom_inc.pbm", "IMG_ID_CAMERA_OSD_ZOOM_INC" );
	
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ZOOM_DEC,		
			CAMERA_OSD_PATH"CAM_zoom_dec.pbm", "IMG_ID_CAMERA_OSD_ZOOM_DEC" );
	

	
			ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ZOOM_INC_SEL,		
				CAMERA_OSD_PATH"CAM_zoom_inc_sel.pbm", "IMG_ID_CAMERA_OSD_ZOOM_INC_SEL" );
	
			ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_ZOOM_DEC_SEL,		
				CAMERA_OSD_PATH"CAM_zoom_dec_sel.pbm", "IMG_ID_CAMERA_OSD_ZOOM_DEC_SEL" );		
	

	#endif

#endif /* __CAMERA_FEATURE_ZOOM__ */


	/*********** Effect *************/
#ifdef __CAMERA_FEATURE_EFFECT__

	#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_NORMAL,		
			CAMERA_OSD_PATH"CAM_fx_normal.pbm", "IMG_ID_CAMERA_OSD_EFFECT_NORMAL" );
	#endif 

	#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_GRAYSCALE,		
			CAMERA_OSD_PATH"CAM_fx_grayscale.pbm", "IMG_ID_CAMERA_OSD_EFFECT_GRAYSCALE" );
	#endif 
				
	#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_SEPIA,		
			CAMERA_OSD_PATH"CAM_fx_sepia.pbm", "IMG_ID_CAMERA_OSD_EFFECT_SEPIA" );
	#endif 

	#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_SEPIA_GREEN,		
			CAMERA_OSD_PATH"CAM_fx_sepia_g.pbm", "IMG_ID_CAMERA_OSD_EFFECT_SEPIA_GREEN" );
	#endif  

	#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_SEPIA_BLUE,		
			CAMERA_OSD_PATH"CAM_fx_sepia_b.pbm", "IMG_ID_CAMERA_OSD_EFFECT_SEPIA_BLUE" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_COLOR_INVERT,		
			CAMERA_OSD_PATH"CAM_fx_color_inv.pbm", "IMG_ID_CAMERA_OSD_EFFECT_COLOR_INVERT" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_GRAY_INVERT,		
			CAMERA_OSD_PATH"CAM_fx_gray_inv.pbm", "IMG_ID_CAMERA_OSD_EFFECT_GRAY_INVERT" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_BLACKBOARD,		
			CAMERA_OSD_PATH"CAM_fx_blackboard.pbm", "IMG_ID_CAMERA_OSD_EFFECT_BLACKBOARD" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_WHITEBOARD,		
			CAMERA_OSD_PATH"CAM_fx_whiteboard.pbm", "IMG_ID_CAMERA_OSD_EFFECT_WHITEBOARD" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_COPPER_CARVING,		
			CAMERA_OSD_PATH"CAM_fx_copper_carv.pbm", "IMG_ID_CAMERA_OSD_EFFECT_COPPER_CARVING" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_BLUE_CARVING,		
			CAMERA_OSD_PATH"CAM_fx_blue_carv.pbm", "IMG_ID_CAMERA_OSD_EFFECT_BLUE_CARVING" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_EMBOSSMENT,		
			CAMERA_OSD_PATH"CAM_fx_emobss.pbm", "IMG_ID_CAMERA_OSD_EFFECT_EMBOSSMENT" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_CONTRAST,		
			CAMERA_OSD_PATH"CAM_fx_contrast.pbm", "IMG_ID_CAMERA_OSD_EFFECT_CONTRAST" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_JEAN__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_JEAN,		
			CAMERA_OSD_PATH"CAM_fx_jean.pbm", "IMG_ID_CAMERA_OSD_EFFECT_JEAN" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_SKETCH,		
			CAMERA_OSD_PATH"CAM_fx_sketch.pbm", "IMG_ID_CAMERA_OSD_EFFECT_SKETCH" );
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_OIL__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_OIL,		
			CAMERA_OSD_PATH"CAM_fx_oil.pbm", "IMG_ID_CAMERA_OSD_EFFECT_OIL" );
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_1,		
			CAMERA_OSD_PATH"CAM_fx_cust1.pbm", "IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_1" );
	#endif		

	#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_2,		
			CAMERA_OSD_PATH"CAM_fx_cust2.pbm", "IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_2" );
	#endif		

	#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_3,		
			CAMERA_OSD_PATH"CAM_fx_cust3.pbm", "IMG_ID_CAMERA_OSD_EFFECT_CUSTOM_FX_3" );
	#endif		


#endif /* __CAMERA_FEATURE_EFFECT__ */

	/*********** capture button *************/
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CAPTURE,		
			CAMERA_OSD_PATH"CAM_capture.pbm", "IMG_ID_CAMERA_OSD_CAPTURE" );
	
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_CAPTURE_SEL,		
			CAMERA_OSD_PATH"CAM_capture_sel.pbm", "IMG_ID_CAMERA_OSD_CAPTURE_SEL" );

	/*********** Storage *************/
#ifdef __CAMERA_FEATURE_STORAGE__

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_STORAGE_PHONE,		
		CAMERA_OSD_PATH"CAM_store_phone.pbm", "IMG_ID_CAMERA_OSD_STORAGE_PHONE" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_OSD_STORAGE_MEMORY_CARD,		
		CAMERA_OSD_PATH"CAM_store_card.pbm", "IMG_ID_CAMERA_OSD_STORAGE_MEMORY_CARD" );

#endif /* __CAMERA_FEATURE_STORAGE__ */



	/*********** Custom FX *************/
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_CUSTOM_FX_BIRIGHTNESS,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Bright.pbm", "IMG_ID_CAMERA_CUSTOM_FX_BIRIGHTNESS" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_CUSTOM_FX_SATURATION,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Saturation.pbm", "IMG_ID_CAMERA_CUSTOM_FX_SATURATION" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_CUSTOM_FX_CONTRAST,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Contrast.pbm", "IMG_ID_CAMERA_CUSTOM_FX_CONTRAST" );

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_CUSTOM_FX_HUE,		
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\Camera\\\\Submenu\\\\CAM_Hue.pbm", "IMG_ID_CAMERA_CUSTOM_FX_HUE" );


	


#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ICONBAR_LEFT_ARROW,		
		CAMERA_OSD_PATH"CAM_IB_left_arrow.pbm", "IMG_ID_CAMERA_ICONBAR_LEFT_ARROW" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ICONBAR_LEFT_ARROW_SEL,		
		CAMERA_OSD_PATH"CAM_IB_left_arrow_sel.pbm", "IMG_ID_CAMERA_ICONBAR_LEFT_ARROW_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ICONBAR_RIGHT_ARROW,		
		CAMERA_OSD_PATH"CAM_ib_right_arrow.pbm", "IMG_ID_CAMERA_ICONBAR_RIGHT_ARROW" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ICONBAR_RIGHT_ARROW_SEL,		
		CAMERA_OSD_PATH"CAM_IB_right_arrow_sel.pbm", "IMG_ID_CAMERA_ICONBAR_RIGHT_ARROW_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ICONBAR_ITEM,		
		CAMERA_OSD_PATH"CAM_IB_item.pbm", "IMG_ID_CAMERA_ICONBAR_ITEM" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ICONBAR_ITEM_SEL,		
		CAMERA_OSD_PATH"CAM_IB_item_sel.pbm", "IMG_ID_CAMERA_ICONBAR_ITEM_SEL" );	

	ADD_APPLICATION_IMAGE2(IMG_ID_CAMERA_ICONBAR_ITEM_DIS,		
		CAMERA_OSD_PATH"CAM_IB_item_dis.pbm", "IMG_ID_CAMERA_ICONBAR_ITEM_DIS" );				

#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */


}

/*****************************************************************************
* FUNCTION
*	PopulateCameraMenuRes
* DESCRIPTION
*	Generate Camrea related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateCameraMenuRes(void)
{	
	/*********** Camera App *************/
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_APP, MAIN_MENU_AVZONE_MENU_ID,0,
		SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,1,MAIN_MENU_CAMERA_TEXT,MAIN_MENU_CAMERA_ICON));

	ADD_APPLICATION_MENUITEM((MAIN_MENU_OPTION_CAMERA_APP, MAIN_MENU_OPTION_AVZONE_MENUID,0,
		SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,1,STR_ID_CAMERA_APP_NAME	,IMG_ID_CAMERA_APP_ICON));
#else
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_APP, MAIN_MENU_MULTIMEDIA_MENUID,0,
		SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,1,STR_ID_CAMERA_APP_NAME	,IMG_ID_CAMERA_APP_ICON));
#endif
	
	/*********** Option Menu *************/
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_OPTION, 
										0,
										CAMERA_OPTION_ITEM_COUNT,
										MENU_ID_CAMERA_TO_IMGVIEW,
										MENU_ID_CAMERA_CAMERA_SETTING,
										MENU_ID_CAMERA_IMAGE_SETTING,
										#ifdef __CAMERA_FEATURE_WB__
										MENU_ID_CAMERA_WB,
										#endif

										#ifdef __CAMERA_DSC_MODE__
										MENU_ID_CAMERA_DSC_MODE,
										#endif

										#ifdef __CAMERA_FEATURE_ISO_SUPPORT__ 
										MENU_ID_CAMERA_ISO,
										#endif

										#ifdef __CAMERA_AUTOFOCUS_MODE__
										MENU_ID_CAMERA_AUTOFOCUS_MODE,
										#endif

										#ifdef __CAMERA_AUTOFOCUS_METERING__
										MENU_ID_CAMERA_AUTOFOCUS_METERING,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT__
										MENU_ID_CAMERA_EFFECT_SETTING,
										#endif

										#ifdef __CAMERA_FEATURE_ADD_FRAME__
										MENU_ID_CAMERA_ADD_FRAME,
										#endif

										#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
										MENU_ID_CAMERA_SELF_CAPTURE,
										#endif

										#ifdef __CAMERA_FEATURE_STORAGE__
										MENU_ID_CAMERA_STORAGE,
										#endif 
										
										MENU_ID_CAMERA_RESTORE_DEFAULT,
										0, 
										0, 
										1,
										STR_GLOBAL_OPTIONS,
										IMG_ID_CAMERA_APP_ICON));


	
	/*********** To ImageViewer *************/
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_TO_IMGVIEW, MENU_ID_CAMERA_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_TO_IMGVIEW,IMG_ID_CAMERA_TO_IMGVIEW));
	


	/***********  Camera Setting *************/
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_CAMERA_SETTING, MENU_ID_CAMERA_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_CAMERA_SETTING,IMG_ID_CAMERA_CAMERA_SETTING));

									
	/***********  Image Setting *************/
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_IMAGE_SETTING, MENU_ID_CAMERA_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_IMAGE_SETTING,IMG_ID_CAMERA_IMAGE_SETTING));

#ifdef __CAMERA_FEATURE_WB__
	/***********  WB *************/
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_WB, MENU_ID_CAMERA_OPTION,CAMERA_WB_ITEM_COUNT,
									#ifdef __CAMERA_FEATURE_WB_AUTO__
										MENU_ID_CAMERA_WB_AUTO,
									#endif 

									#ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
										MENU_ID_CAMERA_WB_DAYLIGHT, 
									#endif 
												
									#ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
										MENU_ID_CAMERA_WB_TUNGSTEN, 
									#endif 

									#ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
										MENU_ID_CAMERA_WB_FLUORESCENT, 
									#endif  

									#ifdef __CAMERA_FEATURE_WB_CLOUD__
										MENU_ID_CAMERA_WB_CLOUD, 
									#endif	

									#ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
										MENU_ID_CAMERA_WB_INCANDESCENCE, 
									#endif	

									#ifdef __CAMERA_FEATURE_WB_MANUAL__
										MENU_ID_CAMERA_WB_MANUAL, 
									#endif	
										0,0,1,STR_ID_CAMERA_WB,IMG_ID_CAMERA_WB));

	#ifdef __CAMERA_FEATURE_WB_AUTO__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_WB_AUTO, MENU_ID_CAMERA_WB,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_WB_AUTO,0));
	#endif 

	#ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_WB_DAYLIGHT, MENU_ID_CAMERA_WB,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_WB_DAYLIGHT,0));
	#endif 
				
	#ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_WB_TUNGSTEN, MENU_ID_CAMERA_WB,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_WB_TUNGSTEN,0));
	#endif 

	#ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_WB_FLUORESCENT, MENU_ID_CAMERA_WB,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_WB_FLUORESCENT,0));
	#endif  

	#ifdef __CAMERA_FEATURE_WB_CLOUD__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_WB_CLOUD, MENU_ID_CAMERA_WB,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_WB_CLOUD,0));
	#endif	

	#ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_WB_INCANDESCENCE, MENU_ID_CAMERA_WB,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_WB_INCANDESCENCE,0));
	#endif	

	#ifdef __CAMERA_FEATURE_WB_MANUAL__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_WB_MANUAL, MENU_ID_CAMERA_WB,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_WB_MANUAL,0));
	#endif	

#endif /* __CAMERA_FEATURE_WB__ */

#ifdef __CAMERA_AUTOFOCUS_METERING__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_AUTOFOCUS_METERING, MENU_ID_CAMERA_OPTION,CAMERA_AUTOFOCUS_ITEM_COUNT,
						#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
						MENU_ID_CAMERA_AUTOFOCUS_1_ZONE,
						#endif
						#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
						MENU_ID_CAMERA_AUTOFOCUS_3_ZONE,
						#endif
						#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
						MENU_ID_CAMERA_AUTOFOCUS_5_ZONE,
						#endif
						0,0,1,STR_ID_CAMERA_AUTOFOCUS_METERING,IMG_ID_CAMERA_AUTOFOCUS_METERING));								

	#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_AUTOFOCUS_1_ZONE, MENU_ID_CAMERA_AUTOFOCUS_METERING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_AUTOFOCUS_1_ZONE,0));
	#endif
	#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_AUTOFOCUS_3_ZONE, MENU_ID_CAMERA_AUTOFOCUS_METERING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_AUTOFOCUS_3_ZONE,0));
	#endif
	#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_AUTOFOCUS_5_ZONE, MENU_ID_CAMERA_AUTOFOCUS_METERING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_AUTOFOCUS_5_ZONE,0));
	#endif
#endif /* __CAMERA_AUTOFOCUS_METERING__ */

#ifdef __CAMERA_AUTOFOCUS_MODE__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_AUTOFOCUS_MODE, MENU_ID_CAMERA_OPTION,CAMERA_AUTOFOCUS_MODE_ITEM_COUNT,
						#ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
						MENU_ID_CAMERA_AUTOFOCUS_MODE_AUTO,
						#endif
						#ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
						MENU_ID_CAMERA_AUTOFOCUS_MODE_MACRO,
						#endif
						#ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
						MENU_ID_CAMERA_AUTOFOCUS_MODE_INFINITE,
						#endif
						#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
						MENU_ID_CAMERA_AUTOFOCUS_MODE_MANUAL,
						#endif
						0,0,1,STR_ID_CAMERA_AUTOFOCUS_MODE,IMG_ID_CAMERA_AUTOFOCUS_MODE));								

	#ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_AUTOFOCUS_MODE_AUTO, MENU_ID_CAMERA_AUTOFOCUS_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_AUTOFOCUS_MODE_AUTO,0));
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_AUTOFOCUS_MODE_MACRO, MENU_ID_CAMERA_AUTOFOCUS_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_AUTOFOCUS_MODE_MACRO,0));
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_AUTOFOCUS_MODE_INFINITE, MENU_ID_CAMERA_AUTOFOCUS_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_AUTOFOCUS_MODE_INFINITE,0));
	#endif
	#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_AUTOFOCUS_MODE_MANUAL, MENU_ID_CAMERA_AUTOFOCUS_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_AUTOFOCUS_MODE_MANUAL,0));
	#endif
#endif


#ifdef __CAMERA_DSC_MODE__
	/***********  DSC Mode *************/
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_DSC_MODE, 
										MENU_ID_CAMERA_OPTION,
										CAMERA_DSC_MODE_ITEM_COUNT,
					
										#ifdef __CAMERA_DSC_MODE_AUTO__
											MENU_ID_CAMERA_DSC_MODE_AUTO,
										#endif 
										
										#ifdef __CAMERA_DSC_MODE_PORTRAIT__
											MENU_ID_CAMERA_DSC_MODE_PORTRAIT,
										#endif

										#ifdef __CAMERA_DSC_MODE_LANDSCAPE__
											MENU_ID_CAMERA_DSC_MODE_LANDSCAPE,
										#endif

										#ifdef __CAMERA_DSC_MODE_SPORT__
											MENU_ID_CAMERA_DSC_MODE_SPORT,
										#endif 

										#ifdef __CAMERA_DSC_MODE_FLOWER__ 
											MENU_ID_CAMERA_DSC_MODE_FLOWER,
										#endif

										#ifdef __CAMERA_DSC_MODE_NIGHT__ 
											MENU_ID_CAMERA_DSC_MODE_NIGHT,
										#endif

										#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
											MENU_ID_CAMERA_DSC_MODE_SHUTTER_PRI,
										#endif

										#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
											MENU_ID_CAMERA_DSC_MODE_APERTURE_PRI,
										#endif

										0, 
										0, 
										1,
										STR_ID_CAMERA_DSC_MODE, 
										IMG_ID_CAMERA_DSC_MODE));



	#ifdef __CAMERA_DSC_MODE_AUTO__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_AUTO, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_AUTO,0));
	#endif 

	#ifdef __CAMERA_DSC_MODE_PORTRAIT__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_PORTRAIT, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_PORTRAIT,0));
	#endif

	#ifdef __CAMERA_DSC_MODE_LANDSCAPE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_LANDSCAPE, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_LANDSCAPE,0));
	#endif

	#ifdef __CAMERA_DSC_MODE_SPORT__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_SPORT, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_SPORT,0));
	#endif 

	#ifdef __CAMERA_DSC_MODE_FLOWER__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_FLOWER, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_FLOWER,0));
	#endif

	#ifdef __CAMERA_DSC_MODE_NIGHT__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_NIGHT, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_NIGHT,0));
	#endif

	#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_SHUTTER_PRI, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_SHUTTER_PRI,0));
	#endif

	#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_DSC_MODE_APERTURE_PRI, MENU_ID_CAMERA_DSC_MODE,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_DSC_MODE_APERTURE_PRI,0));
	#endif

	#ifdef __CAMERA_FEATURE_ISO_SUPPORT__ 
    	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_ISO, 
    								MENU_ID_CAMERA_OPTION,
    								CAMERA_ISO_ITEM_COUNT,
    			
    								#ifdef __CAEMRA_FEATURE_ISO_AUTO__
    									MENU_ID_CAMERA_ISO_AUTO,
    								#endif 
    								
    								#ifdef __CAEMRA_FEATURE_ISO_100__
    									MENU_ID_CAMERA_ISO_100,
    								#endif

    								#ifdef __CAEMRA_FEATURE_ISO_200__
    									MENU_ID_CAMERA_ISO_200,
    								#endif

    								#ifdef __CAEMRA_FEATURE_ISO_400__
    									MENU_ID_CAMERA_ISO_400,
    								#endif

    								0, 
    								0, 
    								1,
    								STR_ID_CAMERA_ISO, 
    								IMG_ID_CAMERA_ISO));
        #ifdef __CAEMRA_FEATURE_ISO_AUTO__
		    ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ISO_AUTO, MENU_ID_CAMERA_ISO,0,
			    			SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ISO_AUTO,IMG_ID_CAMERA_OSD_ISO_AUTO));
        #endif
        #ifdef __CAEMRA_FEATURE_ISO_100__
		    ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ISO_100, MENU_ID_CAMERA_ISO,0,
			    			SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ISO_100,IMG_ID_CAMERA_OSD_ISO_100));
        #endif
        #ifdef __CAEMRA_FEATURE_ISO_200__
            ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ISO_200, MENU_ID_CAMERA_ISO,0,
    						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ISO_200,IMG_ID_CAMERA_OSD_ISO_200));
        #endif
        #ifdef __CAEMRA_FEATURE_ISO_400__
		    ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ISO_400, MENU_ID_CAMERA_ISO,0,
			    			SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ISO_400,IMG_ID_CAMERA_OSD_ISO_400)); 
        #endif
	#endif

#endif /* __CAMERA_DSC_MODE__ */

#ifdef __CAMERA_FEATURE_EFFECT__
	/***********  Effect *************/
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_EFFECT_SETTING, 
										MENU_ID_CAMERA_OPTION,
										CAMERA_EFFECT_SETTING_ITEM_COUNT,
					
										#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
											MENU_ID_CAMERA_EFFECT_NORMAL,
										#endif 
										
										#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
											MENU_ID_CAMERA_EFFECT_GRAYSCALE,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
											MENU_ID_CAMERA_EFFECT_SEPIA,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
											MENU_ID_CAMERA_EFFECT_SEPIA_GREEN,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
											MENU_ID_CAMERA_EFFECT_SEPIA_BLUE,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
											MENU_ID_CAMERA_EFFECT_COLOR_INVERT,
										#endif 

										#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__ 
											MENU_ID_CAMERA_EFFECT_GRAY_INVERT,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__ 
											MENU_ID_CAMERA_EFFECT_BLACKBOARD,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__ 
											MENU_ID_CAMERA_EFFECT_WHITEBOARD,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__ 
											MENU_ID_CAMERA_EFFECT_COPPER_CARVING,
										#endif

										#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__ 
											MENU_ID_CAMERA_EFFECT_BLUE_CARVING,
										#endif										

										#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__ 
											MENU_ID_CAMERA_EFFECT_EMBOSSMENT,
										#endif	

										#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__ 
											MENU_ID_CAMERA_EFFECT_CONTRAST,
										#endif	

										#ifdef __CAMERA_FEATURE_EFFECT_JEAN__ 
											MENU_ID_CAMERA_EFFECT_JEAN,
										#endif		

										#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__ 
											MENU_ID_CAMERA_EFFECT_SKETCH,
										#endif	

										#ifdef __CAMERA_FEATURE_EFFECT_OIL__ 
											MENU_ID_CAMERA_EFFECT_OIL,
										#endif											

										#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ 
											MENU_ID_CAMERA_EFFECT_CUSTOM_FX_1,
										#endif	
										
										#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ 
											MENU_ID_CAMERA_EFFECT_CUSTOM_FX_2,
										#endif	

										#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ 
											MENU_ID_CAMERA_EFFECT_CUSTOM_FX_3,
										#endif	
										
										0, 
										0, 
										1,
										STR_ID_CAMERA_EFFECT_SETTING, 
										IMG_ID_CAMERA_EFFECT_SETTING));

	#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_NORMAL, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_NORMAL,0));
	#endif 

	#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_GRAYSCALE, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_GRAYSCALE,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_SEPIA, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_SEPIA,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_SEPIA_GREEN, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_SEPIA_GREEN,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_SEPIA_BLUE, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_SEPIA_BLUE,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_COLOR_INVERT, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_COLOR_INVERT,0));
	#endif 

	#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_GRAY_INVERT, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_GRAY_INVERT,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_BLACKBOARD, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_BLACKBOARD,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_WHITEBOARD, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_WHITEBOARD,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_COPPER_CARVING, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_COPPER_CARVING,0));
	#endif

	#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_BLUE_CARVING, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_BLUE_CARVING,0));
	#endif										

	#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_EMBOSSMENT, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_EMBOSSMENT,0));
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CONTRAST, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CONTRAST,0));
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_JEAN__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_JEAN, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_JEAN,0));
	#endif		

	#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_SKETCH, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_SKETCH,0));
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_OIL__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_OIL, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_OIL,0));
	#endif											

	#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CUSTOM_FX_1, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CUSTOM_FX_1,0));
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CUSTOM_FX_2, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CUSTOM_FX_2,0));
	#endif	

	#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ 
		ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CUSTOM_FX_3, MENU_ID_CAMERA_EFFECT_SETTING,0,
						SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CUSTOM_FX_3,0));
	#endif	

	/* custom fx edit */
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET_OPTION, 
										0,
										2,
										MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET,
										MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT,
										0, 
										0, 
										1,
										STR_GLOBAL_OPTIONS,	
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET, MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CUSTOM_FX_SET,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT, MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT,0));


	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_OPTION, 
										0,
										2,
										MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_SAVE,
										MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_RESTORE_DEFAULT,
										0, 
										0, 
										1,
										STR_GLOBAL_OPTIONS,	
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CUSTOM_FX_SET, MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CUSTOM_FX_SET,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT, MENU_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EFFECT_CUSTOM_FX_EDIT_EFFECT,0));

#endif /* __CAMERA_FEATURE_EFFECT__ */

	/*********** Add Frame Normal*************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_ADD_FRAME, 
										MENU_ID_CAMERA_OPTION,
										CAMERA_ADD_FRAME_TYPE_COUNT,

										#ifdef __CAMERA_FEATURE_ADD_FRAME_NORMAL__										
										MENU_ID_CAMERA_ADD_FRAME_NORMAL,
										#endif
										
										#ifdef __CAMERA_FEATURE_ADD_FRAME_TILESHOT__
										MENU_ID_CAMERA_ADD_FRAME_TILESHOT,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
										MENU_ID_CAMERA_ADD_FRAME_COLOR_IDX,
										#endif 
										0,
										0, 
										1,
										STR_ID_CAMERA_ADD_FRAME, 
										IMG_ID_CAMERA_ADD_FRAME));
#endif


#ifdef __CAMERA_FEATURE_ADD_FRAME_NORMAL__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_ADD_FRAME_NORMAL, 
										MENU_ID_CAMERA_ADD_FRAME,
										CAMERA_ADD_FRAME_ITEM_COUNT,

										MENU_ID_CAMERA_ADD_FRAME_OFF,

										#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
										MENU_ID_CAMERA_ADD_FRAME_1,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
										MENU_ID_CAMERA_ADD_FRAME_2,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
										MENU_ID_CAMERA_ADD_FRAME_3,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
										MENU_ID_CAMERA_ADD_FRAME_4,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
										MENU_ID_CAMERA_ADD_FRAME_5,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
										MENU_ID_CAMERA_ADD_FRAME_6,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
										MENU_ID_CAMERA_ADD_FRAME_7,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
										MENU_ID_CAMERA_ADD_FRAME_8,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
										MENU_ID_CAMERA_ADD_FRAME_9,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
										MENU_ID_CAMERA_ADD_FRAME_10,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__
										MENU_ID_CAMERA_ADD_FRAME_CUSTOM_1,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__
										MENU_ID_CAMERA_ADD_FRAME_CUSTOM_2,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__
										MENU_ID_CAMERA_ADD_FRAME_CUSTOM_3,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__
										MENU_ID_CAMERA_ADD_FRAME_CUSTOM_4,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__
										MENU_ID_CAMERA_ADD_FRAME_CUSTOM_5,
										#endif 
										0,
										0, 
										1,
										STR_ID_CAMERA_ADD_FRAME_NORMAL, 
										IMG_ID_CAMERA_ADD_FRAME_NORMAL));
#endif /* __CAMERA_FEATURE_ADD_FRAME_NORMAL__ */

	/*********** Add Frame TILESHOT *************/
#ifdef __CAMERA_FEATURE_ADD_FRAME_TILESHOT__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_ADD_FRAME_TILESHOT, 
										MENU_ID_CAMERA_ADD_FRAME,
										CAMERA_ADD_FRAME_ITEM_COUNT,

										MENU_ID_CAMERA_ADD_FRAME_OFF,

										#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
										MENU_ID_CAMERA_ADD_FRAME_1,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
										MENU_ID_CAMERA_ADD_FRAME_2,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
										MENU_ID_CAMERA_ADD_FRAME_3,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
										MENU_ID_CAMERA_ADD_FRAME_4,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
										MENU_ID_CAMERA_ADD_FRAME_5,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
										MENU_ID_CAMERA_ADD_FRAME_6,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
										MENU_ID_CAMERA_ADD_FRAME_7,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
										MENU_ID_CAMERA_ADD_FRAME_8,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
										MENU_ID_CAMERA_ADD_FRAME_9,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
										MENU_ID_CAMERA_ADD_FRAME_10,
										#endif 

										0,
										0, 
										1,
										STR_ID_CAMERA_ADD_FRAME_TILESHOT, 
										IMG_ID_CAMERA_ADD_FRAME_TILESHOT));

#endif /* __CAMERA_FEATURE_ADD_FRAME_TILESHOT__ */



	/*********** Add Frame Color Index Overlay *************/
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_ADD_FRAME_COLOR_IDX, 
										MENU_ID_CAMERA_ADD_FRAME,
										CAMERA_ADD_FRAME_COLOR_IDX_ITEM_COUNT,

										MENU_ID_CAMERA_ADD_FRAME_OFF,

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__
										MENU_ID_CAMERA_ADD_FRAME_1,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__
										MENU_ID_CAMERA_ADD_FRAME_2,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__
										MENU_ID_CAMERA_ADD_FRAME_3,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_4__
										MENU_ID_CAMERA_ADD_FRAME_4,
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_5__
										MENU_ID_CAMERA_ADD_FRAME_5,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_6__
										MENU_ID_CAMERA_ADD_FRAME_6,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_7__
										MENU_ID_CAMERA_ADD_FRAME_7,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_8__
										MENU_ID_CAMERA_ADD_FRAME_8,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_9__
										MENU_ID_CAMERA_ADD_FRAME_9,		
										#endif 

										#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_10__
										MENU_ID_CAMERA_ADD_FRAME_10,
										#endif 

										0,
										0, 
										1,
										STR_ID_CAMERA_ADD_FRAME_COLOR_IDX, 
										IMG_ID_CAMERA_ADD_FRAME_COLOR_IDX));

#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_OFF, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_OFF,0));

#if defined(__CAMERA_FEATURE_ADD_FRAME_1__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_1, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_1,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_2__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_2, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_2,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_3__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_3, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_3,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_4__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_4__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_4, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_4,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_5__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_5__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_5, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_5,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_6__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_6__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_6, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_6,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_7__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_7__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_7, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_7,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_8__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_8__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_8, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_8,0));		
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_9__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_9__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_9, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_9,0));
#endif 

#if defined(__CAMERA_FEATURE_ADD_FRAME_10__) || defined(__CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_10__)
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_10, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_10,0));
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_CUSTOM_1, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_CUSTOM_1,0));
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_CUSTOM_2, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_CUSTOM_2,0));
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_CUSTOM_3, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_CUSTOM_3,0));
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_CUSTOM_4, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_CUSTOM_4,0));
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_ADD_FRAME_CUSTOM_5, MENU_ID_CAMERA_ADD_FRAME_NORMAL,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_ADD_FRAME_CUSTOM_5,0));
#endif 






	/*********** Self Capture *************/
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_SELF_CAPTURE, MENU_ID_CAMERA_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_SELF_CAPTURE,IMG_ID_CAMERA_SELF_CAPTURE));



	/*********** Storage *************/
#ifdef __CAMERA_FEATURE_STORAGE__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_STORAGE, 
										MENU_ID_CAMERA_OPTION,
										2,
										MENU_ID_CAMERA_STORAGE_PHONE,
										MENU_ID_CAMERA_STORAGE_MEMORY_CARD,
										0, 
										0, 
										1,
										STR_ID_CAMERA_STORAGE, 
										IMG_ID_CAMERA_STORAGE));


	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_STORAGE_PHONE, MENU_ID_CAMERA_STORAGE,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_STORAGE_PHONE,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_STORAGE_MEMORY_CARD, MENU_ID_CAMERA_STORAGE,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_STORAGE_MEMORY_CARD,0));
#endif /* __CAMERA_FEATURE_STORAGE__ */

	/*********** Restore Default *************/
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_RESTORE_DEFAULT, MENU_ID_CAMERA_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_RESTORE_DEFAULT,IMG_ID_CAMERA_RESTORE_DEFAULT));

#ifdef __MMI_SUBLCD_CAMERA__
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_SUBLCD_OPTION, 
								0,
								CAMERA_SUBLCD_OPTION_COUNT,
								MENU_ID_CAMERA_SUBLCD_PREVIEW,
                            #if defined(__CAMERA_FEATURE_FLASH__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
								MENU_ID_CAMERA_SUBLCD_FLASH,
                            #endif
								MENU_ID_CAMERA_SUBLCD_EXIT,
								0, 
								0, 
								1,
								STR_GLOBAL_OPTIONS,
								IMG_ID_CAMERA_APP_ICON));

	/*********** sublcd preview *************/

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_SUBLCD_PREVIEW, MENU_ID_CAMERA_SUBLCD_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_APP_NAME,IMG_ID_CAMERA_APP_ICON));
#if defined(__CAMERA_FEATURE_FLASH__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
/*********** sublcd flash *************/
	ADD_APPLICATION_MENUITEM((	MENU_ID_CAMERA_SUBLCD_FLASH, 
	                            MENU_ID_CAMERA_SUBLCD_OPTION,
	                            2,
								MENU_ID_CAMERA_SUBLCD_FLASH_ON,
                                MENU_ID_CAMERA_SUBLCD_FLASH_OFF,
								0,
								0,
								1,
								STR_ID_CAMERA_FLASH,
								IMG_ID_CAMERA_FLASH));

	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_SUBLCD_FLASH_ON, MENU_ID_CAMERA_SUBLCD_FLASH,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_FLASH_ON,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_SUBLCD_FLASH_OFF, MENU_ID_CAMERA_SUBLCD_FLASH,0,
                    SHOW,NONMOVEABLE,1,STR_ID_CAMERA_FLASH_OFF,0));
#endif /* defined(__CAMERA_FEATURE_FLASH__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT__) */					

	/*********** sublcd exit *************/
	ADD_APPLICATION_MENUITEM((MENU_ID_CAMERA_SUBLCD_EXIT, MENU_ID_CAMERA_SUBLCD_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_CAMERA_EXIT,0));

#endif



}


/*****************************************************************************
* FUNCTION
*	PopulateCameraRes
* DESCRIPTION
*	Generate Camrea related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateCameraRes(void)
{	
	PopulateCameraStrRes();
	PopulateCameraImgRes();	
	PopulateCameraMenuRes();		
}
#endif /* __MMI_CAMERA__ */


#ifdef __MMI_IMAGE_VIEWER__
/*****************************************************************************
* FUNCTION
*	PopulateImageViewerRes
* DESCRIPTION
*	Generate ImageViewer related resources
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateImageViewerRes(void)
{
	/************************************************************************/
	/*   Create String                                                      */
	/************************************************************************/

	/* ImageViewer Application */
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_NAME,						"Image Viewer",			"ImageViewer name");

	/* Storage Setting */
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_VIEW_STYLE,				"View Mode",				"[Menu-View Mode]");
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_VIEW_STYLE_LIST,		"List Mode",				"[Menu-List Mode]");
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_VIEW_STYLE_MATRIX,	"Matrix Mode",				"[Menu-Matrix Mode]");

	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_STORAGE,					"Storage",				"[Menu-Storage]");
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_STORAGE_MEMORY_CARD,	"Memory Card",			"[Menu-Storage Memory Card]");
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_STORAGE_PHONE,			"Phone",					"[Menu-Storage Phone]");

	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_PRINT,					"Print",				"[Print]");
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_PRINT_NOT_SUPPORT,		"Image Type Not Support",				"[Print,not support]");

	/* Notify */
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_NOTIFY_NO_MEMORY_CARD,		"No Memory Card",	"[Notify-No memory card]");
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_NOTIFY_WRITE_PROTECTION,	"Memory card is locked, can't create \Photos folder",	"[Notify-Card locked, cant create folder]");
	ADD_APPLICATION_STRING2(STR_ID_IMGVIEW_NOTIFY_MULTIPART_NOT_SUPPORT, "IV Not Support Multipart ODF", "[Notify-Multimart not support]");

	/* Images */
#if defined(__MMI_IMAGEVIEWER_ADV__)
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_MAIN_ICON,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\SB_Viewer.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_BACKGROUND,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_bg.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_LEFT_ARROW_UP,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_left_up.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_LEFT_ARROW_DOWN,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_left_down.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_RIGHT_ARROW_UP,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_right_up.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_RIGHT_ARROW_DOWN,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_right_down.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_ZOOMIN_UP,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_zoomin_up.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_ZOOMIN_DOWN,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_zoomin_down.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_ZOOMOUT_UP,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_zoomout_up.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_ZOOMOUT_DOWN,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_zoomout_down.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_ROTATE_UP,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_rotate_up.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_ROTATE_DOWN,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_rotate_down.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_SCREEN_MODE_UP,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_screenmode_up.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_SCREEN_MODE_DOWN,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_screenmode_down.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_BACKGROUND_HORIZONTAL,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\viewer_bg_horizontal.pbm",	"ImageViewer icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_IMAGEVIEWER_DRM,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\drm.gif",	"ImageViewer DRM" );

#else
	ADD_APPLICATION_IMAGE2(IMG_ID_IMGVIEW_MAIN_ICON,
		CUST_IMG_PATH"\\\\MainLCD\\\\Camera\\\\ImageViewer\\\\SB_Viewer.pbm",	"ImageViewer icon" );
#endif
	/************************************************************************/
	/* Create Menu                                                          */
	/************************************************************************/

	/* Camera App*/
	ADD_APPLICATION_MENUITEM((MENU_ID_IMGVIEW_APP, MAIN_MENU_MULTIMEDIA_MENUID,0,
					SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,1,STR_ID_IMGVIEW_NAME,IMG_ID_IMGVIEW_MAIN_ICON));


	/* File Option Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGVIEW_FILE_OPTION, 
						0,	
					#ifdef __CAMERA_FEATURE_STORAGE__
						9,
					#else
						8,
					#endif /* __CAMERA_FEATURE_STORAGE__ */
						MENU_ID_IMGVIEW_VIEW_DETAIL,
						MENU_FMGR_GEN_OPTION_JPG_DETAIL,
						MENU_ID_IMGVIEW_VIEW_STYLE,
						MENU_FMGR_GEN_OPTION_FORWARD,
						MENU_FMGR_GEN_OPTION_RENAME,
						MENU_FMGR_GEN_OPTION_DELETE,
						MENU_FMGR_GEN_OPTION_DELETE_ALL,
						MENU_FMGR_GEN_OPTION_SORT,
					#ifdef __CAMERA_FEATURE_STORAGE__
						MENU_ID_IMGVIEW_STORAGE,
					#endif /* __CAMERA_FEATURE_STORAGE__ */
						0, 
						0, 
						1,
						STR_GLOBAL_OPTIONS,
						IMG_ID_IMGVIEW_MAIN_ICON));

	/* File Option Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGVIEW_FILE_OPTION_NO_SIM, 
						0,	
					#ifdef __CAMERA_FEATURE_STORAGE__
						8,
					#else
						7,
					#endif /* __CAMERA_FEATURE_STORAGE__ */
						MENU_ID_IMGVIEW_VIEW_DETAIL,
						MENU_FMGR_GEN_OPTION_JPG_DETAIL,
						MENU_ID_IMGVIEW_VIEW_STYLE,
						MENU_FMGR_GEN_OPTION_RENAME,
						MENU_FMGR_GEN_OPTION_DELETE,
						MENU_FMGR_GEN_OPTION_DELETE_ALL,
						MENU_FMGR_GEN_OPTION_SORT,
					#ifdef __CAMERA_FEATURE_STORAGE__
						MENU_ID_IMGVIEW_STORAGE,
					#endif /* __CAMERA_FEATURE_STORAGE__ */
						0, 
						0, 
						1,
						STR_GLOBAL_OPTIONS,
						IMG_ID_IMGVIEW_MAIN_ICON));


	/* Empty Folder Option Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGVIEW_EMPTY_FOLDER_OPTION, 
										0,	
									#ifdef __CAMERA_FEATURE_STORAGE__
										2,
									#else
										1,
									#endif /* __CAMERA_FEATURE_STORAGE__ */
										MENU_ID_IMGVIEW_VIEW_STYLE,
									#ifdef __CAMERA_FEATURE_STORAGE__
										MENU_ID_IMGVIEW_STORAGE,
									#endif /* __CAMERA_FEATURE_STORAGE__ */
										MENU_ID_IMGVIEW_VIEW_STYLE,
									#ifdef __CAMERA_FEATURE_STORAGE__
										MENU_ID_IMGVIEW_STORAGE,
									#endif /* __CAMERA_FEATURE_STORAGE__ */
										0, 
										0, 
										1,
										STR_GLOBAL_OPTIONS,
										IMG_ID_IMGVIEW_MAIN_ICON));


	/* Storage */
	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGVIEW_STORAGE, 
										0,
										2,
										MENU_ID_IMGVIEW_STORAGE_PHONE,
										MENU_ID_IMGVIEW_STORAGE_MEMORY_CARD,
										/* MENU_ID_CAMERA_STORAGE_USER_DEFINE, */
										0, 
										0, 
										1,
										STR_ID_IMGVIEW_STORAGE, 
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGVIEW_STORAGE_PHONE, MENU_ID_IMGVIEW_STORAGE,0,
					SHOW,NONMOVEABLE,1,STR_ID_IMGVIEW_STORAGE_PHONE,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGVIEW_STORAGE_MEMORY_CARD, MENU_ID_IMGVIEW_STORAGE,0,
					SHOW,NONMOVEABLE,1,STR_ID_IMGVIEW_STORAGE_MEMORY_CARD,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGVIEW_VIEW_DETAIL, MENU_ID_IMGVIEW_FILE_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_VIEW,0));



	/* View Style */
	ADD_APPLICATION_MENUITEM((	MENU_ID_IMGVIEW_VIEW_STYLE, 
										0,
										2,
										MENU_ID_IMGVIEW_VIEW_STYLE_LIST,
										MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX,
										0, 
										0, 
										1,
										STR_ID_IMGVIEW_VIEW_STYLE, 
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGVIEW_VIEW_STYLE_LIST, MENU_ID_IMGVIEW_VIEW_STYLE,0,
					SHOW,NONMOVEABLE,1,STR_ID_IMGVIEW_VIEW_STYLE_LIST,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX, MENU_ID_IMGVIEW_VIEW_STYLE,0,
					SHOW,NONMOVEABLE,1,STR_ID_IMGVIEW_VIEW_STYLE_MATRIX,0));

 
}
#endif /* __MMI_IMAGE_VIEWER__ */
#endif /* __MMI_CAMERA__ || __MMI_IMAGE_VIEWER__ */




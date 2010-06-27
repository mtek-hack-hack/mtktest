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
 *	 MMI_features_camera.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Define which Camera features should on/off
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CAMERA_FEATURES_H_
#define _CAMERA_FEATURES_H_

#include "MMI_features.h"

#if defined(OV9655)
#define __MMI_CAMERA_130M_SENSOR__
#endif


#ifdef __MMI_IMAGE_VIEWER__
/****************************************************************************
*
* EXIF CUSTOMIZATION
*
*****************************************************************************/
#ifdef __MMI_EXIF__
	#define __MMI_EXIF_MAKE__
	#define __MMI_EXIF_MODEL__
	//#define __MMI_EXIF_ORIENTATION__
	#define __MMI_EXIF_X_RESOLUTION__
	#define __MMI_EXIF_Y_RESOLUTION__
	//#define __MMI_EXIF_RESOLUTION_UNIT__
	#define __MMI_EXIF_SOFTWARE__
	#define __MMI_EXIF_DATE_TIME__
	#define __MMI_EXIF_YCBCR_POSITIONING__
	//#define __MMI_EXIF_EXIF_IFD__

	#define __MMI_EXIF_EXPOSURE_TIME__
	#define __MMI_EXIF_FNUMBER__
	#define __MMI_EXIF_EXPOSURE_PROGRAM__
	#define __MMI_EXIF_ISO_SPEED_RATINGS__
	#define __MMI_EXIF_EXIF_VERSION__
	#define __MMI_EXIF_DATE_TIME_ORIGINAL__
	#define __MMI_EXIF_DATE_TIME_DIGITIZED__
	//#define __MMI_EXIF_COMPONENTS_CONFIG__
	#define __MMI_EXIF_EXPOSURE_BIAS_VALUE__
	#define __MMI_EXIF_METERING_MODE__
	//#define __MMI_EXIF_LIGHT_SOURCE__
	#define __MMI_EXIF_FLASH__
	//#define __MMI_EXIF_MAKER_NOTE__
	//#define __MMI_EXIF_FLASHPIX_VERSION__
	#define __MMI_EXIF_COLOR_SPACE__
	#define __MMI_EXIF_PIXEL_X_DIMENSION__
	#define __MMI_EXIF_PIXEL_Y_DIMENSION__
	#define __MMI_EXIF_EXPOSURE_MODE__
	#define __MMI_EXIF_DIGITAL_ZOOM_RATIO__
	#define __MMI_EXIF_SCENE_CAPTURE_TYPE__
#endif

#endif


#if defined(__CAMERA_130W_CHEAT__) 
//Huyanwei Add It 
#define CAMERA_FEATURE_IMAGE_SIZE_LLL_WIDTH 			(640)
#define CAMERA_FEATURE_IMAGE_SIZE_LLL_HEIGHT 			(480)
#define CAMERA_FEATURE_PREVIEW_SIZE_LLL_WIDTH			(240)
#define CAMERA_FEATURE_PREVIEW_SIZE_LLL_HEIGHT			(180)
#define CAMERA_FEATURE_PREVIEW_LLL_ZOOM_LIMIT			(10)				
#endif



#ifdef __MMI_CAMERA__
/****************************************************************************
*
* Camera Common Features
*
*****************************************************************************/
#ifndef __MED_MEM_POOL__
#define __MED_MEM_POOL__
#endif

#ifdef __MMI_MMS__
#ifndef __MED_MEM_POOL__
    #define __MMI_CAMERA_MMS_SUPPORT__
#endif	
#endif

#if defined(ISP_SUPPORT)
    #define __COUNTDOWN_USING_MMA__
    /* Use Fast Zoom Since W05.50 */
    #define __CAMERA_FAST_ZOOM_SUPPORT__

    #if !defined(MT6219) 
    #define __MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__
    #endif  

    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)
    #define __MMI_CAMERA_HIGH_END__
    #endif
#endif

#ifdef HORIZONTAL_CAMERA
    #define __CAMERA_OSD_HORIZONTAL__
    #define __HORIZONTAL_CAMERA_WALLPAPER_ENABLE__
#endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
    #define __CAMERA_FEATURE_STORAGE__
#endif

#ifdef __MMI_TOUCH_SCREEN__
    #define __CAMERA_FEATURE_TOUCH_SCREEN__
    #define __CAMERA_FEATURE_TOUCH_CLICKICON__
#else
    //#define __CAMERA_FEATURE_ICONBAR_PANEL__
#endif 

#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
#define __CAMERA_FEATURE_XENON_FLASH__
#define __CAMERA_FEATURE_FLASH__
/* 2009.04.19 deleted by ghw for delete auto menu + */
//#define __CAMERA_FEATURE_FLASH_AUTO__ 
/* 2009.04.19 deleted by ghw for delete auto menu - */

    #if defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
        #define __CAMERA_FEATURE_FLASH_REDEYE__
    #endif
#elif defined(LED_FLASHLIGHT_SUPPORT)
	#define __CAMERA_FEATURE_FLASH__
/* 2009.04.19 deleted by ghw for delete auto menu + */
//#define __CAMERA_FEATURE_FLASH_AUTO__ 
/* 2009.04.19 deleted by ghw for delete auto menu - */
#elif defined(LED_ONOFF_SUPPORT)
	#define __CAMERA_FEATURE_LED_HIGHLIGHT__
	#define __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
	//#define __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
#endif


/* preview rotation */
#if defined(SENSOR_ON_BODY)
    #if defined(SENSOR_ROTATE_0)
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_0
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_0_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_0_MIRROR
    #elif defined(SENSOR_ROTATE_180)
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_180
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_180_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_180_MIRROR
    #else
        /* rotate 90, 270 not used yet */
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_0
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_0_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_0_MIRROR
    #endif
#elif defined(SENSOR_ON_COVER)
    #if defined(SENSOR_ROTATE_0)
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_0
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_0_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_180_MIRROR
    #elif defined(SENSOR_ROTATE_180)
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_180
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_180_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_0_MIRROR
    #else
        /* rotate 90, 270 not used yet */
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_0
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_0_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_180_MIRROR
    #endif
#else /* not define SENSOR_LCATION */
    #if defined(SENSOR_ROTATE_0)
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_0
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_0_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_180_MIRROR
    #elif defined(SENSOR_ROTATE_180)
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_180
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_180_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_0_MIRROR
    #else
        /* rotate 90, 270 not used yet */
        #define CAMERA_PREVIEW_MAINLCD_ROTATE           CAMERA_PREVIEW_ROTATE_0
        #define CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE  CAMERA_PREVIEW_ROTATE_0_MIRROR
        #define CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE CAMERA_PREVIEW_ROTATE_180_MIRROR
    #endif				
#endif /* SENSOR_LOCATION */		

    /* lcd rotate */
#ifdef __CAMERA_OSD_HORIZONTAL__
    #define CAMERA_LCM_MAINLCD_ROTATE           CAMERA_LCM_RORATE_270
#else
    #define CAMERA_LCM_MAINLCD_ROTATE           CAMERA_LCM_ROTATE_0
#endif
#define CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE      CAMERA_LCM_ROTATE_180
#define CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE     CAMERA_LCM_ROTATE_0

/* display rotate */
#define CAMERA_DISPLAY_ROTATE_0                 CAMERA_PREVIEW_ROTATE_0
#define CAMERA_DISPLAY_ROTATE_90                CAMERA_PREVIEW_ROTATE_90
#define CAMERA_DISPLAY_ROTATE_180               CAMERA_PREVIEW_ROTATE_180
#define CAMERA_DISPLAY_ROTATE_270               CAMERA_PREVIEW_RORATE_270
#define CAMERA_DISPLAY_ROTATE_RESET             255

/* Factory mode */
#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
    #define CAMERA_FACTORY_PREVIEW_WIDTH                (128)
    #define CAMERA_FACTORY_PREVIEW_HEIGHT               (128)
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
    #define CAMERA_FACTORY_PREVIEW_WIDTH                (128)
    #define CAMERA_FACTORY_PREVIEW_HEIGHT               (160)
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
    #define CAMERA_FACTORY_PREVIEW_WIDTH                (176)
    #define CAMERA_FACTORY_PREVIEW_HEIGHT               (220)
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
    #define CAMERA_FACTORY_PREVIEW_WIDTH                (240)
    #define CAMERA_FACTORY_PREVIEW_HEIGHT               (320)

    #ifdef __MTK_TARGET__
    #if defined(MT6228) || defined(MT6229) || defined(MT6230)
        #define __MMI_CAMERA_5_OSD_LAYER__
    #elif defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227D) || defined(MT6129)
        #define __MMI_CAMERA_3_OSD_LAYER__    
    #endif
    #endif

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    #define CAMERA_FACTORY_PREVIEW_WIDTH                (320)
    #define CAMERA_FACTORY_PREVIEW_HEIGHT               (240)

    #ifdef __MTK_TARGET__
    #if defined(MT6228) || defined(MT6229) || defined(MT6230)
        #define __MMI_CAMERA_5_OSD_LAYER__
    #elif defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227D) || defined(MT6129)
        #define __MMI_CAMERA_3_OSD_LAYER__    
    #endif
    #endif

#else /* other LCD size */
    #define CAMERA_FACTORY_PREVIEW_WIDTH                (128)
    #define CAMERA_FACTORY_PREVIEW_HEIGHT               (96)
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */




/****************************************************************************
*
* Camera Specific Features
*
*****************************************************************************/
#if defined(ISP_SUPPORT)
/***************************************************************************** 
*
*
* MT6219
*
*
*****************************************************************************/
	#if defined(MT6219) 

		/***************************************************************************** 
		* OSD
		*****************************************************************************/
		/* Zooming */
		#define __CAMERA_FEATURE_ZOOM__

		#define CAMERA_FEATURE_ZOOM_COUNT			(71)
		#ifdef __MMI_CAMERA_ONLY__
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
																							40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
																							70,71,72,73,74,75,76,77,78,79,80};
		#else
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT];
		#endif

		/***************************************************************************** 
		* Option Menu 
		*****************************************************************************/
		/* menu [Camera Setting] [Image Setting] [Effect Setting] [Restore Default] will always exist */

		#define __CAMERA_FEATURE_EFFECT__
		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_CONT_SHOT__
		#define __CAMERA_FEATURE_DELAY_TIMER__

		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
            #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
               #define __MMI_SUBLCD_CAMERA__
            #endif
			#define __CAMERA_FEATURE_SELF_CAPTURE__
		#endif

	    #ifdef AF_SUPPORT
			/***************************************************************************** 
			* Auto Exposure 
			*****************************************************************************/
			#define __CAMERA_FEATURE_AE_METER__

			#define __CAMERA_FEATURE_AE_METER_AUTO__
			#define __CAMERA_FEATURE_AE_METER_SPOT__
			#define __CAMERA_FEATURE_AE_METER_CENTER__
			#define __CAMERA_FEATURE_AE_METER_AVERAGE__

			/***************************************************************************** 
			* Auto Focus  
			*****************************************************************************/
			#define __CAMERA_AUTOFOCUS__

			#define __CAMERA_AUTOFOCUS_METERING__
			#define __CAMERA_AUTOFOCUS_1_ZONE__

			#define __CAMERA_AUTOFOCUS_MODE__
			#define __CAMERA_AUTOFOCUS_MODE_AUTO__

			#define CAMERA_AF_POSITION_1_X							(LCD_WIDTH/2)
			#define CAMERA_AF_POSITION_1_Y							(LCD_HEIGHT/2)
			#define CAMERA_AF_POSITION_2_X							(CAMERA_AF_POSITION_1_X + 40)
			#define CAMERA_AF_POSITION_2_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_3_X							(CAMERA_AF_POSITION_1_X - 40)
			#define CAMERA_AF_POSITION_3_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_4_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_4_Y							(CAMERA_AF_POSITION_1_Y	+ 40)
			#define CAMERA_AF_POSITION_5_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_5_Y							(CAMERA_AF_POSITION_1_Y - 40)

			/***************************************************************************** 
			* DSC Mode 
			*****************************************************************************/

			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_FLOWER__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
	    #endif		

		/***************************************************************************** 
		* Camera Setting
		*****************************************************************************/
		/********** settings  ***********/ 
		#define __CAMERA_FEATURE_SHUTTER_SOUND__
		#define __CAMERA_FEATURE_EV__
        #ifndef __CAMERA_DSC_MODE_NIGHT__
		#define __CAMERA_FEATURE_NIGHT__
        #endif
		//#define __CAMERA_FEATURE_CLOSEUP__
		#define __CAMERA_FEATURE_BANDING__

		/******* customizable shutter sound *********/
		#define __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_1__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_2__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_3__

		/******* customizable ev *********/
		/* default will have off [ev 0] and [ev +1] [ev -1] menu if __CAMERA_FEATURE_EV__ is turn on */
		#define __CAMERA_FEATURE_EV_2__
		#define __CAMERA_FEATURE_EV_3__
		#define __CAMERA_FEATURE_EV_4__


		/***************************************************************************** 
		* Image Setting
		*****************************************************************************/
		/* Notice, [Image Size] and [Image Qty] will always exist */

		#if defined(OV7670) || defined(OV7660) || defined(HV7131) || defined(PO3030K)
			/* 640x480 Sensor */

			#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(128)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
				
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(160)
				
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(160)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) ) 
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(220)	
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)		

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */


			#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(320)	


				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)		

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

			#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
	            /* it should be better customized by customer */
				//#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
	
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(960)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(80)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(60)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(40)		
		
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
		
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */
				
			#else /* other LCD size */
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(120)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(120)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)	

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
			
		#else
			/* other 1280x1024 sensor */

			/******* customizable image size *********/
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
				
			#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(128)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(128)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)	

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(160)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(160)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)	

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )  
			
				#ifdef __CAMERA_OSD_HORIZONTAL__
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(1024)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(800)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(600)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(26)
				#else
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(141)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)	
				#endif

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(30)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

			#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )

			#ifdef __CAMERA_OSD_HORIZONTAL__
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH			(1200)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(900)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT			(320)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT 		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT 		(20)	
			#else			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(320)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(192)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)	
			#endif
			
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

			#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
	            /* it should be better customized by customer */
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
	        
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(960)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(80)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(60)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(40)		
		
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
		
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */
								
			#else /* other LCD size */
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(LCD_HEIGHT)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(LCD_HEIGHT)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(LCD_HEIGHT)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)
				
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
		
		#endif /* CMOSE SENSOR */
		
		
		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH 	SUBLCD_WIDTH
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT 	SUBLCD_HEIGHT
		#endif 

		/******* customizable image qty *********/
		//#define __CAMERA_FEATURE_IMAGE_QTY_FINE__	/* turn of due to captured image too large */
		#define __CAMERA_FEATURE_IMAGE_QTY_HIGH__
		#define __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
		#define __CAMERA_FEATURE_IMAGE_QTY_LOW__


		/******* customizable effect *********/
		#define __CAMERA_FEATURE_EFFECT_NORMAL__
		#define __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		#define __CAMERA_FEATURE_EFFECT_SEPIA__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		#define __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		#define __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
		#define __CAMERA_FEATURE_EFFECT_BLACKBOARD__
		#define __CAMERA_FEATURE_EFFECT_WHITEBOARD__
		#define __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
		#define __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
		#define __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
		#define __CAMERA_FEATURE_EFFECT_CONTRAST__
		//#define __CAMERA_FEATURE_EFFECT_JEAN__ 	/* turn off due to some ISP will reuslt bad qty */
		#define __CAMERA_FEATURE_EFFECT_SKETCH__
		//#define __CAMERA_FEATURE_EFFECT_OIL__	/* turn off due to some ISP will reuslt bad qty */

		#if !defined(__CAMERA_FEATURE_TOUCH_SCREEN__)
			/* use OSD menu currently do not support enter custom effect edit screen */
			#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
			#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
			#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		#endif 

		/******* customizable cont shot *********/
		/* Notice, [Cont shot Off] and [Cont shot 1] will always exist if turn on __CAMERA_FEATURE_CONT_SHOT__*/
		#define __CAMERA_FEATURE_CONT_SHOT_2__
		#define __CAMERA_FEATURE_CONT_SHOT_3__
		//#define __CAMERA_FEATURE_CONT_SHOT_BURST__	/* 6219 not support */

		#define CAMERA_FEATURE_CONT_SHOT_1_COUNT					(1)
		#define CAMERA_FEATURE_CONT_SHOT_2_COUNT					(3)
		#define CAMERA_FEATURE_CONT_SHOT_3_COUNT					(5)
		#define CAMERA_FEATURE_CONT_SHOT_BURST_COUNT 			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL			(0)	

		/******* customizable delay timer *********/
		/* Notice, [Delay Timer Off] and [Delay Timer 1] will always exist if turn on __CAMERA_FEATURE_DELAY_TIMER__*/
		#define __CAMERA_FEATURE_DELAY_TIMER_2__
		#define __CAMERA_FEATURE_DELAY_TIMER_3__

		#define CAMERA_FEATURE_DELAY_TIMER_1_DURATION	(5)
		#define CAMERA_FEATURE_DELAY_TIMER_2_DURATION	(10)
		#define CAMERA_FEATURE_DELAY_TIMER_3_DURATION	(15)


		/* capture style */ 
		//#define __CAMERA_FEATURE_CAPTURE_TO_MEMORY__ 

		/* Misc define */
		#define CAMERA_SHUTTER_SOUND_VOLUMN			(LEVEL5)	/* LEVEL1 - LEVEL7 */
		#define CAMERA_SHORTCUT_KEY					(KEY_CAMERA)	
		#define CAMERA_CAPTURE_KEY						(KEY_CAMERA)
		#define CAMERA_CAPTURE_EXTRA_KEY1				(KEY_IP)			/* if no extra, set -1 */
		#define CAMERA_CAPTURE_EXTRA_KEY2				(-1)
		#define CAMERA_TOGGLE_SELF_CAPTURE_KEY		(KEY_STAR)
		#define CAMERA_TOGGLE_HIDE_OSD_KEY			(KEY_POUND)		
		#define CAMERA_EFFECT_KEY						(KEY_1)			/* if no use hotkey, set -1 */
		#define CAMERA_WB_KEY							(KEY_2)
		#define CAMERA_NIGHT_KEY						(KEY_6)
		#if defined(__CAMERA_FEATURE_FLASH__)
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(KEY_3)
		#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)	
			#define CAMERA_LED_HIGHLIGHT_KEY				(KEY_3)
			#define CAMERA_FLASH_KEY						(-1)
		#else 
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(-1)		
		#endif
		#define CAMERA_CONT_SHOT_KEY					(KEY_5)
		#define CAMERA_IMAGE_QTY_KEY					(KEY_7)
		#define CAMERA_IMAGE_SIZE_KEY					(KEY_8)
		#define CAMERA_DSC_MODE_KEY					(-1)			
		#define CAMERA_AE_METER_KEY 					(-1)		
		#if defined(__CAMERA_FEATURE_ISO_SUPPORT__)
			#define CAMERA_DELAY_TIMER_KEY			(-1)		
			#define CAMERA_ISO_KEY					(KEY_4)	
		#else
			#define CAMERA_DELAY_TIMER_KEY			(KEY_4)
			#define CAMERA_ISO_KEY					(-1)			
		#endif
		#define CAMERA_STORAGE_KEY						(-1)
        #define CAMERA_AF_METER_KEY                     (-1)
        #define CAMERA_AF_MODE_KEY                      (-1)

		/***************************************************************************** 
		* Default Setting 
		*****************************************************************************/
		/*********** Preview ***********/
		#define CAMERA_DEFAULT_SETTING_ZOOM_IDX			(0)	/* index - start from 0 */
		#define CAMERA_DEFAULT_SETTING_WB					CAMERA_SETTING_WB_AUTO
		#define CAMERA_DEFAULT_SETTING_FLASH				CAMERA_SETTING_FLASH_OFF
		#define CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT		CAMERA_SETTING_LED_HIGHLIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_SHUTTER_SOUND		CAMERA_SETTING_SHUTTER_SOUND_1
		#define CAMERA_DEFAULT_SETTING_EV					CAMERA_SETTING_EV_0	
		#define CAMERA_DEFAULT_SETTING_NIGHT				CAMERA_SETTING_NIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_CLOSEUP				CAMERA_SETTING_CLOSEUP_OFF
		#define CAMERA_DEFAULT_SETTING_BANDING				CAMERA_SETTING_BANDING_60HZ
		#define CAMERA_DEFAULT_SETTING_EFFECT				CAMERA_SETTING_EFFECT_NORMAL
		#define CAMERA_DEFAULT_SETTING_ADD_FRAME			CAMERA_SETTING_ADD_FRAME_OFF
		#define CAMERA_DEFAULT_SETTING_CONT_SHOT			CAMERA_SETTING_CONT_SHOT_OFF
		#define CAMERA_DEFAULT_SETTING_DELAY_TIMER		CAMERA_SETTING_DELAY_TIMER_OFF
		#define CAMERA_DEFAULT_SETTING_AE_METER			(0)
		#define CAMERA_DEFAULT_SETTING_ISO					(0)
		#define CAMERA_DEFAULT_SETTING_DSC_MODE			(0)				
		#define CAMERA_DEFAULT_SETTING_AUTOFOCUS			(0)

		#define CAMERA_DEFAULT_SETTING_SHUTTER_PRI		(0)
		#define CAMERA_DEFAULT_SETTING_APERTURE_PRI		(0)

		/* custom fx */
		#define CAMERA_DEFAULT_SETTING_BRIGHTNESS			(128)	
		#define CAMERA_DEFAULT_SETTING_SATURATION			(128)	
		#define CAMERA_DEFAULT_SETTING_CONTRAST			(128)	
		#define CAMERA_DEFAULT_SETTING_HUE					(0)	

		/* led highlight/flash value */
		#define CAMERA_DEFAULT_PREVIEW_LED_VALUE			(70)	
		#define CAMERA_DEFAULT_CAPTURE_LED_VALUE			(90)	
		#define CAMERA_DEFAULT_PREVIEW_FLASH_VALUE		(100) 	/* not used */
		#define CAMERA_DEFAULT_CAPTURE_FLASH_VALUE		(100)		/* not used */

		/* capture */
		#define CAMERA_DEFAULT_SETTING_IMAGE_SIZE			CAMERA_SETTING_IMAGE_SIZE_SS
		#define CAMERA_DEFAULT_SETTING_IMAGE_QTY			CAMERA_SETTING_IMAGE_QTY_NORMAL

		/***************************************************************************** 
		* Manual White Balance 
		*****************************************************************************/

		#define __CAMERA_FEATURE_WB__

		#define __CAMERA_FEATURE_WB_AUTO__
		#define __CAMERA_FEATURE_WB_DAYLIGHT__
		#define __CAMERA_FEATURE_WB_TUNGSTEN__
		#define __CAMERA_FEATURE_WB_FLUORESCENT__
		#define __CAMERA_FEATURE_WB_CLOUD__
		#define __CAMERA_FEATURE_WB_INCANDESCENCE__
		//#define __CAMERA_FEATURE_WB_MANUAL__


		/***************************************************************************** 
		* Add Frame 
		*****************************************************************************/

		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_ADD_FRAME_NORMAL__
		//#define __CAMERA_FEATURE_ADD_FRAME_TILESHOT__

		/******* customizable add frame *********/
		#define __CAMERA_FEATURE_ADD_FRAME_1__
		#define __CAMERA_FEATURE_ADD_FRAME_2__
        /*
		#define __CAMERA_FEATURE_ADD_FRAME_3__
		#define __CAMERA_FEATURE_ADD_FRAME_4__
		#define __CAMERA_FEATURE_ADD_FRAME_5__
		#define __CAMERA_FEATURE_ADD_FRAME_6__
		#define __CAMERA_FEATURE_ADD_FRAME_7__
		#define __CAMERA_FEATURE_ADD_FRAME_8__
		#define __CAMERA_FEATURE_ADD_FRAME_9__
		#define __CAMERA_FEATURE_ADD_FRAME_10__
		*/
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__		/* not implment yet */


		/***************************************************************************** 
		* END OF SETTING
		*****************************************************************************/
/***************************************************************************** 
*
*
* MT6225
*
*
*****************************************************************************/
	#elif defined(MT6225) || defined(MT6235)
		/***************************************************************************** 
		* OSD
		*****************************************************************************/
		/* Zooming */
		#define __CAMERA_FEATURE_ZOOM__

		#define CAMERA_FEATURE_ZOOM_COUNT			(71)
		#ifdef __MMI_CAMERA_ONLY__
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
																							40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
																							70,71,72,73,74,75,76,77,78,79,80};
		#else
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT];
		#endif

		/***************************************************************************** 
		* Option Menu 
		*****************************************************************************/
		/* menu [Camera Setting] [Image Setting] [Effect Setting] [Restore Default] will always exist */

		#define __CAMERA_FEATURE_EFFECT__
		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_CONT_SHOT__
		#define __CAMERA_FEATURE_DELAY_TIMER__

		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
            #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
               #define __MMI_SUBLCD_CAMERA__
            #endif
			#define __CAMERA_FEATURE_SELF_CAPTURE__
		#endif
	
		#ifdef AF_SUPPORT
			/***************************************************************************** 
			* Auto Exposure 
			*****************************************************************************/
			#define __CAMERA_FEATURE_AE_METER__

			#define __CAMERA_FEATURE_AE_METER_AUTO__
			#define __CAMERA_FEATURE_AE_METER_SPOT__
			#define __CAMERA_FEATURE_AE_METER_CENTER__
			#define __CAMERA_FEATURE_AE_METER_AVERAGE__

			/***************************************************************************** 
			* Auto Focus  
			*****************************************************************************/
			#define __CAMERA_AUTOFOCUS__

			#define __CAMERA_AUTOFOCUS_METERING__
			#define __CAMERA_AUTOFOCUS_1_ZONE__

			#define __CAMERA_AUTOFOCUS_MODE__
			#define __CAMERA_AUTOFOCUS_MODE_AUTO__

			#define CAMERA_AF_POSITION_1_X							(LCD_WIDTH/2)
			#define CAMERA_AF_POSITION_1_Y							(LCD_HEIGHT/2)
			#define CAMERA_AF_POSITION_2_X							(CAMERA_AF_POSITION_1_X + 40)
			#define CAMERA_AF_POSITION_2_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_3_X							(CAMERA_AF_POSITION_1_X - 40)
			#define CAMERA_AF_POSITION_3_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_4_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_4_Y							(CAMERA_AF_POSITION_1_Y	+ 40)
			#define CAMERA_AF_POSITION_5_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_5_Y							(CAMERA_AF_POSITION_1_Y - 40)
			
			/***************************************************************************** 
			* DSC Mode 
			*****************************************************************************/

			#define __CAMERA_DSC_MODE__
		
			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_FLOWER__
			#define __CAMERA_DSC_MODE_NIGHT__
			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
	    #else
			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_NIGHT__
			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#endif	

		/***************************************************************************** 
		* Camera Setting
		*****************************************************************************/
		/********** settings  ***********/ 
		#define __CAMERA_FEATURE_SHUTTER_SOUND__
		#define __CAMERA_FEATURE_EV__
		//#define __CAMERA_FEATURE_NIGHT__
		//#define __CAMERA_FEATURE_CLOSEUP__
		#define __CAMERA_FEATURE_BANDING__

		/******* customizable shutter sound *********/
		#define __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_1__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_2__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_3__

		/******* customizable ev *********/
		/* default will have off [ev 0] and [ev +1] [ev -1] menu if __CAMERA_FEATURE_EV__ is turn on */
		#define __CAMERA_FEATURE_EV_2__
		#define __CAMERA_FEATURE_EV_3__
		#define __CAMERA_FEATURE_EV_4__

		/***************************************************************************** 
		* Image Setting
		*****************************************************************************/
		/* Notice, [Image Size] and [Image Qty] will always exist */

			
		#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
		
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(80)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(60)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(128)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(128)
			
			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(2)  	/* SS, S, [M], L, LL */
			
		#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
		
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(80)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(60)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(160)
			
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(160)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(2)  	/* SS, S, [M], L, LL */
			
		#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
		
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
		
	        #ifdef __MMI_CAMERA_130M_SENSOR__        
				#ifdef __CAMERA_OSD_HORIZONTAL__
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(1024)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(800)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(600)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(26)
				#else
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(140)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)	
				#endif
	        #else
	            #ifdef __CAMERA_OSD_HORIZONTAL__
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(80)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(60)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(220)	
		
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)		
	            #else
	                #define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(80)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(60)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
	        		#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)	
	        	
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

	        		#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
	        		#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
	        		#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
	        		#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
	        		#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)
	            #endif
	        #endif

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)
			
			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(2)  	/* SS, S, [M], L, LL */

		#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
		
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

	        #ifdef __MMI_CAMERA_130M_SENSOR__        
				#ifdef __CAMERA_OSD_HORIZONTAL__
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH			(1200)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(900)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH			(800)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT			(600)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT			(320)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(320)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(320)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT 		(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT 		(20)	
				#else
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(192)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(180)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(180)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(180)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)	
				#endif
	        #else
	            #ifdef __CAMERA_OSD_HORIZONTAL__
	        		#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(80)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(60)
	        		#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
	        		#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)	
	        	
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
	        		#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)
		
	        		#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
	        		#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
	        		#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
	        		#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
	        		#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)		

	            #else
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(80)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(60)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(320)	
		
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(180)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(180)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(180)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(180)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(240)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)		
	            #endif
	        #endif

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)
			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(2)  	/* SS, S, [M], L, LL */

			#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
	            /* it should be better customized by customer */
	        #ifdef __MMI_CAMERA_130M_SENSOR__        
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
            #endif
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
	
        
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(960)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(80)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(60)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(40)		
		
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
		
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */



		#else /* other LCD size */
		
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(120)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(120)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(120)
			
			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)	

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	
			
			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(2)  	/* SS, S, [M], L, LL */
			
		#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
		
		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH 	SUBLCD_WIDTH
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT 	SUBLCD_HEIGHT
		#endif 

		/******* customizable image qty *********/
		//#define __CAMERA_FEATURE_IMAGE_QTY_FINE__	/* turn of due to captured image too large */
		#define __CAMERA_FEATURE_IMAGE_QTY_HIGH__
		#define __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
		#define __CAMERA_FEATURE_IMAGE_QTY_LOW__


		/******* customizable effect *********/
		#define __CAMERA_FEATURE_EFFECT_NORMAL__
		#define __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		#define __CAMERA_FEATURE_EFFECT_SEPIA__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		#define __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
	    #if !defined(YUV_SENSOR_SUPPORT)
			#define __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
			#define __CAMERA_FEATURE_EFFECT_BLACKBOARD__
			#define __CAMERA_FEATURE_EFFECT_WHITEBOARD__
			#define __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
	        //#define __CAMERA_FEATURE_EFFECT_JEAN__ 	/* turn off due to some ISP will reuslt bad qty */
			#define __CAMERA_FEATURE_EFFECT_SKETCH__
			//#define __CAMERA_FEATURE_EFFECT_OIL__	/* turn off due to some ISP will reuslt bad qty */
			#define __CAMERA_FEATURE_EFFECT_CONTRAST__
			#define __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
			#define __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
	    #endif

		#if !defined(__CAMERA_FEATURE_TOUCH_SCREEN__)
			/* use OSD menu currently do not support enter custom effect edit screen */
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		#endif 


		/******* customizable add frame *********/
		#define __CAMERA_FEATURE_ADD_FRAME_1__
		#define __CAMERA_FEATURE_ADD_FRAME_2__
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__		/* not implment yet */

			
		/******* customizable cont shot *********/
		/* Notice, [Cont shot Off] and [Cont shot 1] will always exist if turn on __CAMERA_FEATURE_CONT_SHOT__*/
		#define __CAMERA_FEATURE_CONT_SHOT_2__
		#define __CAMERA_FEATURE_CONT_SHOT_3__
		//#define __CAMERA_FEATURE_CONT_SHOT_BURST__

		#define CAMERA_FEATURE_CONT_SHOT_1_COUNT					(1)
		#define CAMERA_FEATURE_CONT_SHOT_2_COUNT					(3)
		#define CAMERA_FEATURE_CONT_SHOT_3_COUNT					(5)
		
		#define CAMERA_FEATURE_CONT_SHOT_BURST_COUNT 			(9)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW			(3)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL			(3)	

		/* MT6228 use non-blocking burst */
		#define __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__	/* non-blocking burst shot */
					

		/******* customizable delay timer *********/
		/* Notice, [Delay Timer Off] and [Delay Timer 1] will always exist if turn on __CAMERA_FEATURE_DELAY_TIMER__*/
		#define __CAMERA_FEATURE_DELAY_TIMER_2__
		#define __CAMERA_FEATURE_DELAY_TIMER_3__

		#define CAMERA_FEATURE_DELAY_TIMER_1_DURATION	(5)
		#define CAMERA_FEATURE_DELAY_TIMER_2_DURATION	(10)
		#define CAMERA_FEATURE_DELAY_TIMER_3_DURATION	(15)

		/* Misc define */
		#define CAMERA_SHUTTER_SOUND_VOLUMN			(LEVEL5)	/* LEVEL1 - LEVEL7 */
		#define CAMERA_SHORTCUT_KEY					(KEY_CAMERA)	
		#define CAMERA_CAPTURE_KEY						(KEY_0)
		#define CAMERA_CAPTURE_EXTRA_KEY1				(KEY_IP)			/* if no extra, set -1 */
		#define CAMERA_CAPTURE_EXTRA_KEY2				(KEY_POWER)
		#define CAMERA_TOGGLE_SELF_CAPTURE_KEY		(KEY_STAR)
		#define CAMERA_TOGGLE_HIDE_OSD_KEY			(KEY_POUND)		
		#define CAMERA_EFFECT_KEY						(KEY_1)			/* if no use hotkey, set -1 */
		#define CAMERA_WB_KEY							(KEY_2)
		#define CAMERA_NIGHT_KEY						(-1)
		#if defined(__CAMERA_FEATURE_FLASH__)
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(KEY_3)
		#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)	
			#define CAMERA_LED_HIGHLIGHT_KEY				(KEY_3)
			#define CAMERA_FLASH_KEY						(-1)
		#else
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(-1)		
		#endif
		#define CAMERA_CONT_SHOT_KEY					(KEY_5)
		#define CAMERA_IMAGE_QTY_KEY					(KEY_7)
		#define CAMERA_IMAGE_SIZE_KEY					(KEY_8)
		#define CAMERA_DSC_MODE_KEY					(KEY_6)			
		#define CAMERA_AE_METER_KEY 					(-1)		
		#if defined(__CAMERA_FEATURE_ISO_SUPPORT__)
			#define CAMERA_DELAY_TIMER_KEY			(-1)		
			#define CAMERA_ISO_KEY					(KEY_4)	
		#else
			#define CAMERA_DELAY_TIMER_KEY			(KEY_4)
			#define CAMERA_ISO_KEY					(-1)			
		#endif
        #define CAMERA_STORAGE_KEY						(-1)
        #define CAMERA_AF_METER_KEY                     (-1)
        #define CAMERA_AF_MODE_KEY                      (-1)

		/***************************************************************************** 
		* Default Setting 
		*****************************************************************************/
		/*********** Preview ***********/
		#define CAMERA_DEFAULT_SETTING_ZOOM_IDX			(0)	/* index - start from 0 */
		#define CAMERA_DEFAULT_SETTING_WB					CAMERA_SETTING_WB_AUTO
		#define CAMERA_DEFAULT_SETTING_FLASH				CAMERA_SETTING_FLASH_OFF
		#define CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT		CAMERA_SETTING_LED_HIGHLIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_SHUTTER_SOUND		CAMERA_SETTING_SHUTTER_SOUND_1
		#define CAMERA_DEFAULT_SETTING_EV					CAMERA_SETTING_EV_0	
		#define CAMERA_DEFAULT_SETTING_NIGHT				CAMERA_SETTING_NIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_CLOSEUP				CAMERA_SETTING_CLOSEUP_OFF
		#define CAMERA_DEFAULT_SETTING_BANDING				CAMERA_SETTING_BANDING_60HZ
		#define CAMERA_DEFAULT_SETTING_EFFECT				CAMERA_SETTING_EFFECT_NORMAL
		#define CAMERA_DEFAULT_SETTING_ADD_FRAME			CAMERA_SETTING_ADD_FRAME_OFF
		#define CAMERA_DEFAULT_SETTING_CONT_SHOT			CAMERA_SETTING_CONT_SHOT_OFF
		#define CAMERA_DEFAULT_SETTING_DELAY_TIMER		CAMERA_SETTING_DELAY_TIMER_OFF
		#define CAMERA_DEFAULT_SETTING_AE_METER			(0)
		#define CAMERA_DEFAULT_SETTING_ISO					(0)
		#define CAMERA_DEFAULT_SETTING_DSC_MODE			(0)
		#define CAMERA_DEFAULT_SETTING_AUTOFOCUS			(0)

		/* custom fx */
		#define CAMERA_DEFAULT_SETTING_BRIGHTNESS			(128)	
		#define CAMERA_DEFAULT_SETTING_SATURATION			(128)	
		#define CAMERA_DEFAULT_SETTING_CONTRAST			(128)	
		#define CAMERA_DEFAULT_SETTING_HUE					(0)	

		/* led highlight/flash value */
		#define CAMERA_DEFAULT_PREVIEW_LED_VALUE			(70)	
		#define CAMERA_DEFAULT_CAPTURE_LED_VALUE			(90)	
		#define CAMERA_DEFAULT_PREVIEW_FLASH_VALUE		(100) 	/* not used */
		#define CAMERA_DEFAULT_CAPTURE_FLASH_VALUE		(100)		/* not used */

		/* capture */
		#define CAMERA_DEFAULT_SETTING_IMAGE_SIZE			CAMERA_SETTING_IMAGE_SIZE_SS
		#define CAMERA_DEFAULT_SETTING_IMAGE_QTY			CAMERA_SETTING_IMAGE_QTY_NORMAL

		/***************************************************************************** 
		* Manual White Balance 
		*****************************************************************************/

		#define __CAMERA_FEATURE_WB__

		#define __CAMERA_FEATURE_WB_AUTO__
		#define __CAMERA_FEATURE_WB_DAYLIGHT__
		#define __CAMERA_FEATURE_WB_TUNGSTEN__
		#define __CAMERA_FEATURE_WB_FLUORESCENT__
		#define __CAMERA_FEATURE_WB_CLOUD__
		#define __CAMERA_FEATURE_WB_INCANDESCENCE__
		

		/***************************************************************************** 
		* Add Frame 
		*****************************************************************************/

		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_ADD_FRAME_NORMAL__
		//#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__

		#define CAMERA_ADD_FRAME_COLOR_IDX1_WIDTH 			(160)
		#define CAMERA_ADD_FRAME_COLOR_IDX1_HEIGHT 			(120)
		#define CAMERA_ADD_FRAME_COLOR_IDX2_WIDTH 			(300)
		#define CAMERA_ADD_FRAME_COLOR_IDX2_HEIGHT			(240)

		/***************************************************************************** 
		* END OF SETTING
		*****************************************************************************/
    #elif defined(MT6226) || defined(MT6226D) 
	/***************************************************************************** 
	* MT6226 - VGA sensor
	*****************************************************************************/
		
		/***************************************************************************** 
		* OSD
		*****************************************************************************/
		/* Zooming */
		#define __CAMERA_FEATURE_ZOOM__

		#define CAMERA_FEATURE_ZOOM_COUNT			(71)
		#ifdef __MMI_CAMERA_ONLY__
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
																							40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
																							70,71,72,73,74,75,76,77,78,79,80};
		#else
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT];
		#endif

		/***************************************************************************** 
		* Option Menu 
		*****************************************************************************/
		/* menu [Camera Setting] [Image Setting] [Effect Setting] [Restore Default] will always exist */

		#define __CAMERA_FEATURE_EFFECT__
		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_CONT_SHOT__
		#define __CAMERA_FEATURE_DELAY_TIMER__

		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
            #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
               #define __MMI_SUBLCD_CAMERA__
            #endif
			#define __CAMERA_FEATURE_SELF_CAPTURE__
		#endif

		#ifdef AF_SUPPORT
			/***************************************************************************** 
			* Auto Exposure 
			*****************************************************************************/
			#define __CAMERA_FEATURE_AE_METER__

			#define __CAMERA_FEATURE_AE_METER_AUTO__
			#define __CAMERA_FEATURE_AE_METER_SPOT__
			#define __CAMERA_FEATURE_AE_METER_CENTER__
			#define __CAMERA_FEATURE_AE_METER_AVERAGE__

			/***************************************************************************** 
			* Auto Focus  
			*****************************************************************************/
			#define __CAMERA_AUTOFOCUS__

			#define __CAMERA_AUTOFOCUS_METERING__
			#define __CAMERA_AUTOFOCUS_1_ZONE__

			#define __CAMERA_AUTOFOCUS_MODE__
			#define __CAMERA_AUTOFOCUS_MODE_AUTO__

			#define CAMERA_AF_POSITION_1_X							(LCD_WIDTH/2)
			#define CAMERA_AF_POSITION_1_Y							(LCD_HEIGHT/2)
			#define CAMERA_AF_POSITION_2_X							(CAMERA_AF_POSITION_1_X + 40)
			#define CAMERA_AF_POSITION_2_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_3_X							(CAMERA_AF_POSITION_1_X - 40)
			#define CAMERA_AF_POSITION_3_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_4_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_4_Y							(CAMERA_AF_POSITION_1_Y	+ 40)
			#define CAMERA_AF_POSITION_5_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_5_Y							(CAMERA_AF_POSITION_1_Y - 40)

			/***************************************************************************** 
			* DSC Mode 
			*****************************************************************************/

			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_FLOWER__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#else
			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#endif		

		/***************************************************************************** 
		* Camera Setting
		*****************************************************************************/
		/********** settings  ***********/ 
		#define __CAMERA_FEATURE_SHUTTER_SOUND__
		#define __CAMERA_FEATURE_EV__
		//#define __CAMERA_FEATURE_CLOSEUP__
		#define __CAMERA_FEATURE_BANDING__

		/******* customizable shutter sound *********/
		#define __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_1__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_2__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_3__

		/******* customizable ev *********/
		/* default will have off [ev 0] and [ev +1] [ev -1] menu if __CAMERA_FEATURE_EV__ is turn on */
		#define __CAMERA_FEATURE_EV_2__
		#define __CAMERA_FEATURE_EV_3__
		#define __CAMERA_FEATURE_EV_4__


		/***************************************************************************** 
		* Image Setting
		*****************************************************************************/
		/* Notice, [Image Size] and [Image Qty] will always exist */

		#if defined(OV7670) || defined(OV7660) || defined(HV7131) || defined(PO3030K)
			/* 640x480 Sensor */

			#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(128)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

                #ifdef __CAMERA_OSD_HORIZONTAL__
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    				
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)
                #else                
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    				
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(160)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)
                #endif
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) ) 
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

                #ifdef __CAMERA_OSD_HORIZONTAL__
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)
                #else
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)		
                #endif

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

                
                #ifdef __CAMERA_OSD_HORIZONTAL__ 
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)		
                #else
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)		
                #endif
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

			#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
	            /* it should be better customized by customer */
				//#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
	
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(960)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(80)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(60)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(40)		
		
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
		
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */

				
			#else /* other LCD size */
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(120)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(120)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)	

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
			
		#else
			/* other VGA sensor */

			/******* customizable image size *********/
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
				
			#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(128)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
                #ifdef __CAMERA_OSD_HORIZONTAL__
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    				
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)
                #else                
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    				
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(160)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)
                #endif
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )  
                #ifdef __CAMERA_OSD_HORIZONTAL__
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)
                #else
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)		
                #endif

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )

                #ifdef __CAMERA_OSD_HORIZONTAL__ 
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)		
                #else
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)		
                #endif
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */			
				
			#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
	            /* it should be better customized by customer */
				//#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
	
        
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(960)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(80)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(60)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(40)		
		
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
		
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */


			#else /* other LCD size */
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(120)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(120)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)	

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
		
		#endif /* CMOSE SENSOR */
		
		
		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH 	SUBLCD_WIDTH
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT 	SUBLCD_HEIGHT
		#endif 

		/******* customizable image qty *********/
		//#define __CAMERA_FEATURE_IMAGE_QTY_FINE__	/* turn of due to captured image too large */
		#define __CAMERA_FEATURE_IMAGE_QTY_HIGH__
		#define __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
		#define __CAMERA_FEATURE_IMAGE_QTY_LOW__


		/******* customizable effect *********/
		#define __CAMERA_FEATURE_EFFECT_NORMAL__
		#define __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		#define __CAMERA_FEATURE_EFFECT_SEPIA__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		#define __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		#define __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
		#define __CAMERA_FEATURE_EFFECT_BLACKBOARD__
		#define __CAMERA_FEATURE_EFFECT_WHITEBOARD__
		#define __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
		#define __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
		#define __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
		#define __CAMERA_FEATURE_EFFECT_CONTRAST__
		//#define __CAMERA_FEATURE_EFFECT_JEAN__ 	/* turn off due to some ISP will reuslt bad qty */
		#define __CAMERA_FEATURE_EFFECT_SKETCH__
		//#define __CAMERA_FEATURE_EFFECT_OIL__	/* turn off due to some ISP will reuslt bad qty */

		#if !defined(__CAMERA_FEATURE_TOUCH_SCREEN__)
			/* use OSD menu currently do not support enter custom effect edit screen */
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		#endif 

		/******* customizable cont shot *********/
		/* Notice, [Cont shot Off] and [Cont shot 1] will always exist if turn on __CAMERA_FEATURE_CONT_SHOT__*/
		#define __CAMERA_FEATURE_CONT_SHOT_2__
		#define __CAMERA_FEATURE_CONT_SHOT_3__
		//#define __CAMERA_FEATURE_CONT_SHOT_BURST__	/* 6219 not support */

		#define CAMERA_FEATURE_CONT_SHOT_1_COUNT					(1)
		#define CAMERA_FEATURE_CONT_SHOT_2_COUNT					(3)
		#define CAMERA_FEATURE_CONT_SHOT_3_COUNT					(5)
		#define CAMERA_FEATURE_CONT_SHOT_BURST_COUNT 			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL			(0)	

		/******* customizable delay timer *********/
		/* Notice, [Delay Timer Off] and [Delay Timer 1] will always exist if turn on __CAMERA_FEATURE_DELAY_TIMER__*/
		#define __CAMERA_FEATURE_DELAY_TIMER_2__
		#define __CAMERA_FEATURE_DELAY_TIMER_3__

		#define CAMERA_FEATURE_DELAY_TIMER_1_DURATION	(5)
		#define CAMERA_FEATURE_DELAY_TIMER_2_DURATION	(10)
		#define CAMERA_FEATURE_DELAY_TIMER_3_DURATION	(15)


		/* capture style */ 
		//#define __CAMERA_FEATURE_CAPTURE_TO_MEMORY__ 

		/* Misc define */
		#define CAMERA_SHUTTER_SOUND_VOLUMN			(LEVEL5)	/* LEVEL1 - LEVEL7 */
		#define CAMERA_SHORTCUT_KEY					(KEY_CAMERA)	
		#define CAMERA_CAPTURE_KEY						(KEY_CAMERA)
		#define CAMERA_CAPTURE_EXTRA_KEY1				(KEY_IP)			/* if no extra, set -1 */
		#define CAMERA_CAPTURE_EXTRA_KEY2				(-1)
		#define CAMERA_TOGGLE_SELF_CAPTURE_KEY		(KEY_STAR)
		#define CAMERA_TOGGLE_HIDE_OSD_KEY			(KEY_POUND)		
		#define CAMERA_EFFECT_KEY						(KEY_1)			/* if no use hotkey, set -1 */
		#define CAMERA_WB_KEY							(KEY_2)
		#define CAMERA_NIGHT_KEY						(-1)
		#if defined(__CAMERA_FEATURE_FLASH__)
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(KEY_3)
		#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)	
			#define CAMERA_LED_HIGHLIGHT_KEY				(KEY_3)
			#define CAMERA_FLASH_KEY						(-1)
		#else 
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(-1)		
		#endif
		#define CAMERA_CONT_SHOT_KEY					(KEY_5)
		#define CAMERA_IMAGE_QTY_KEY					(KEY_7)
		#define CAMERA_IMAGE_SIZE_KEY					(KEY_8)
		#define CAMERA_DSC_MODE_KEY					(KEY_6)			
		#define CAMERA_ISO_KEY							(-1)	
        #ifdef __CAMERA_FEATURE_AE_METER__
    		#define CAMERA_DELAY_TIMER_KEY				(-1)		
            #define CAMERA_AE_METER_KEY					(KEY_4)	
        #else
    		#define CAMERA_DELAY_TIMER_KEY				(KEY_4)
            #define CAMERA_AE_METER_KEY					(-1)			
        #endif
		#define CAMERA_STORAGE_KEY						(-1)
        #define CAMERA_AF_METER_KEY                     (-1)
        #define CAMERA_AF_MODE_KEY                      (-1)

		/***************************************************************************** 
		* Default Setting 
		*****************************************************************************/
		/*********** Preview ***********/
		#define CAMERA_DEFAULT_SETTING_ZOOM_IDX			(0)	/* index - start from 0 */
		#define CAMERA_DEFAULT_SETTING_WB					CAMERA_SETTING_WB_AUTO
		#define CAMERA_DEFAULT_SETTING_FLASH				CAMERA_SETTING_FLASH_OFF
		#define CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT		CAMERA_SETTING_LED_HIGHLIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_SHUTTER_SOUND		CAMERA_SETTING_SHUTTER_SOUND_1
		#define CAMERA_DEFAULT_SETTING_EV					CAMERA_SETTING_EV_0	
		#define CAMERA_DEFAULT_SETTING_NIGHT				CAMERA_SETTING_NIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_CLOSEUP				CAMERA_SETTING_CLOSEUP_OFF
		#define CAMERA_DEFAULT_SETTING_BANDING				CAMERA_SETTING_BANDING_60HZ
		#define CAMERA_DEFAULT_SETTING_EFFECT				CAMERA_SETTING_EFFECT_NORMAL
		#define CAMERA_DEFAULT_SETTING_ADD_FRAME			CAMERA_SETTING_ADD_FRAME_OFF
		#define CAMERA_DEFAULT_SETTING_CONT_SHOT			CAMERA_SETTING_CONT_SHOT_OFF
		#define CAMERA_DEFAULT_SETTING_DELAY_TIMER		CAMERA_SETTING_DELAY_TIMER_OFF
		#define CAMERA_DEFAULT_SETTING_AE_METER			(0)
		#define CAMERA_DEFAULT_SETTING_ISO					(0)
		#define CAMERA_DEFAULT_SETTING_DSC_MODE			(0)				
		#define CAMERA_DEFAULT_SETTING_AUTOFOCUS			(0)

		#define CAMERA_DEFAULT_SETTING_SHUTTER_PRI		(0)
		#define CAMERA_DEFAULT_SETTING_APERTURE_PRI		(0)

		/* custom fx */
		#define CAMERA_DEFAULT_SETTING_BRIGHTNESS			(128)	
		#define CAMERA_DEFAULT_SETTING_SATURATION			(128)	
		#define CAMERA_DEFAULT_SETTING_CONTRAST			(128)	
		#define CAMERA_DEFAULT_SETTING_HUE					(0)	

		/* led highlight/flash value */
		#define CAMERA_DEFAULT_PREVIEW_LED_VALUE			(70)	
		#define CAMERA_DEFAULT_CAPTURE_LED_VALUE			(90)	
		#define CAMERA_DEFAULT_PREVIEW_FLASH_VALUE		(100) 	/* not used */
		#define CAMERA_DEFAULT_CAPTURE_FLASH_VALUE		(100)		/* not used */

		/* capture */
		#define CAMERA_DEFAULT_SETTING_IMAGE_SIZE			CAMERA_SETTING_IMAGE_SIZE_SS
		#define CAMERA_DEFAULT_SETTING_IMAGE_QTY			CAMERA_SETTING_IMAGE_QTY_NORMAL

		/***************************************************************************** 
		* Manual White Balance 
		*****************************************************************************/

		#define __CAMERA_FEATURE_WB__

		#define __CAMERA_FEATURE_WB_AUTO__
		#define __CAMERA_FEATURE_WB_DAYLIGHT__
		#define __CAMERA_FEATURE_WB_TUNGSTEN__
		#define __CAMERA_FEATURE_WB_FLUORESCENT__
		#define __CAMERA_FEATURE_WB_CLOUD__
		#define __CAMERA_FEATURE_WB_INCANDESCENCE__
		//#define __CAMERA_FEATURE_WB_MANUAL__

		/***************************************************************************** 
		* Add Frame 
		*****************************************************************************/

		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_ADD_FRAME_NORMAL__


		/******* customizable add frame *********/
		#define __CAMERA_FEATURE_ADD_FRAME_1__
		#define __CAMERA_FEATURE_ADD_FRAME_2__
        /*
		#define __CAMERA_FEATURE_ADD_FRAME_3__
		#define __CAMERA_FEATURE_ADD_FRAME_4__
		#define __CAMERA_FEATURE_ADD_FRAME_5__
		#define __CAMERA_FEATURE_ADD_FRAME_6__
		#define __CAMERA_FEATURE_ADD_FRAME_7__
		#define __CAMERA_FEATURE_ADD_FRAME_8__
		#define __CAMERA_FEATURE_ADD_FRAME_9__
		#define __CAMERA_FEATURE_ADD_FRAME_10__
		*/
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__		/* not implment yet */


		/***************************************************************************** 
		* END OF SETTING
		*****************************************************************************/
    

    #elif defined(MT6226M)
	/***************************************************************************** 
    * MT6226M - 1.3M sensor
	*****************************************************************************/
		/***************************************************************************** 
		* OSD
		*****************************************************************************/
		/* Zooming */
		#define __CAMERA_FEATURE_ZOOM__

		#define CAMERA_FEATURE_ZOOM_COUNT			(71)
		#ifdef __MMI_CAMERA_ONLY__
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
																							40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
																							70,71,72,73,74,75,76,77,78,79,80};
		#else
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT];
		#endif

		/***************************************************************************** 
		* Option Menu 
		*****************************************************************************/
		/* menu [Camera Setting] [Image Setting] [Effect Setting] [Restore Default] will always exist */

		#define __CAMERA_FEATURE_EFFECT__
		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_CONT_SHOT__
		#define __CAMERA_FEATURE_DELAY_TIMER__

		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
            #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
               #define __MMI_SUBLCD_CAMERA__
            #endif
			#define __CAMERA_FEATURE_SELF_CAPTURE__
		#endif

		#ifdef AF_SUPPORT
			/***************************************************************************** 
			* Auto Exposure 
			*****************************************************************************/
			#define __CAMERA_FEATURE_AE_METER__

			#define __CAMERA_FEATURE_AE_METER_AUTO__
			#define __CAMERA_FEATURE_AE_METER_SPOT__
			#define __CAMERA_FEATURE_AE_METER_CENTER__
			#define __CAMERA_FEATURE_AE_METER_AVERAGE__

			/***************************************************************************** 
			* Auto Focus  
			*****************************************************************************/
			#define __CAMERA_AUTOFOCUS__

			#define __CAMERA_AUTOFOCUS_METERING__
			#define __CAMERA_AUTOFOCUS_1_ZONE__

			#define __CAMERA_AUTOFOCUS_MODE__
			#define __CAMERA_AUTOFOCUS_MODE_AUTO__

			#define CAMERA_AF_POSITION_1_X							(LCD_WIDTH/2)
			#define CAMERA_AF_POSITION_1_Y							(LCD_HEIGHT/2)
			#define CAMERA_AF_POSITION_2_X							(CAMERA_AF_POSITION_1_X + 40)
			#define CAMERA_AF_POSITION_2_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_3_X							(CAMERA_AF_POSITION_1_X - 40)
			#define CAMERA_AF_POSITION_3_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_4_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_4_Y							(CAMERA_AF_POSITION_1_Y	+ 40)
			#define CAMERA_AF_POSITION_5_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_5_Y							(CAMERA_AF_POSITION_1_Y - 40)

			/***************************************************************************** 
			* DSC Mode 
			*****************************************************************************/

			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_FLOWER__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#else
			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#endif		

		/***************************************************************************** 
		* Camera Setting
		*****************************************************************************/
		/********** settings  ***********/ 
		#define __CAMERA_FEATURE_SHUTTER_SOUND__
		#define __CAMERA_FEATURE_EV__
		//#define __CAMERA_FEATURE_CLOSEUP__
		#define __CAMERA_FEATURE_BANDING__

		/******* customizable shutter sound *********/
		#define __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_1__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_2__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_3__

		/******* customizable ev *********/
		/* default will have off [ev 0] and [ev +1] [ev -1] menu if __CAMERA_FEATURE_EV__ is turn on */
		#define __CAMERA_FEATURE_EV_2__
		#define __CAMERA_FEATURE_EV_3__
		#define __CAMERA_FEATURE_EV_4__


		/***************************************************************************** 
		* Image Setting
		*****************************************************************************/
		/* Notice, [Image Size] and [Image Qty] will always exist */

		/******* customizable image size *********/
		#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
		#define __CAMERA_FEATURE_IMAGE_SIZE_L__
		#define __CAMERA_FEATURE_IMAGE_SIZE_M__
		#define __CAMERA_FEATURE_IMAGE_SIZE_S__
		#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
		#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(128)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(128)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)	

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(160)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(160)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)	

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )  
		
			#ifdef __CAMERA_OSD_HORIZONTAL__
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(26)
			#else
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(141)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)	
			#endif

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(30)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

		#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )

		#ifdef __CAMERA_OSD_HORIZONTAL__
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH			(1200)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(900)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH			(800)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT			(600)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT			(320)

			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT 		(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT 		(20)	
		#else			
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(320)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(192)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(180)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(180)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(180)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)	
		#endif
		
			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

		#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
            /* it should be better customized by customer */
			#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#undef __CAMERA_FEATURE_IMAGE_SIZE_LL__
	        #endif
        
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(960)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(80)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(60)

			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(40)		
		
			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
		
			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */
					
		#else /* other LCD size */
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(LCD_HEIGHT)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(LCD_HEIGHT)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(LCD_HEIGHT)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)
			
			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
	
		
		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH 	SUBLCD_WIDTH
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT 	SUBLCD_HEIGHT
		#endif 

		/******* customizable image qty *********/
		//#define __CAMERA_FEATURE_IMAGE_QTY_FINE__	/* turn of due to captured image too large */
		#define __CAMERA_FEATURE_IMAGE_QTY_HIGH__
		#define __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
		#define __CAMERA_FEATURE_IMAGE_QTY_LOW__


		/******* customizable effect *********/
		#define __CAMERA_FEATURE_EFFECT_NORMAL__
		#define __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		#define __CAMERA_FEATURE_EFFECT_SEPIA__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		#define __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		#define __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
		#define __CAMERA_FEATURE_EFFECT_BLACKBOARD__
		#define __CAMERA_FEATURE_EFFECT_WHITEBOARD__
		#define __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
		#define __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
		#define __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
		#define __CAMERA_FEATURE_EFFECT_CONTRAST__
		//#define __CAMERA_FEATURE_EFFECT_JEAN__ 	/* turn off due to some ISP will reuslt bad qty */
		#define __CAMERA_FEATURE_EFFECT_SKETCH__
		//#define __CAMERA_FEATURE_EFFECT_OIL__	/* turn off due to some ISP will reuslt bad qty */

		#if !defined(__CAMERA_FEATURE_TOUCH_SCREEN__)
			/* use OSD menu currently do not support enter custom effect edit screen */
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		#endif 

		/******* customizable cont shot *********/
		/* Notice, [Cont shot Off] and [Cont shot 1] will always exist if turn on __CAMERA_FEATURE_CONT_SHOT__*/
		#define __CAMERA_FEATURE_CONT_SHOT_2__
		#define __CAMERA_FEATURE_CONT_SHOT_3__
		//#define __CAMERA_FEATURE_CONT_SHOT_BURST__	/* 6219 not support */

		#define CAMERA_FEATURE_CONT_SHOT_1_COUNT					(1)
		#define CAMERA_FEATURE_CONT_SHOT_2_COUNT					(3)
		#define CAMERA_FEATURE_CONT_SHOT_3_COUNT					(5)
		#define CAMERA_FEATURE_CONT_SHOT_BURST_COUNT 			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL			(0)	

		/******* customizable delay timer *********/
		/* Notice, [Delay Timer Off] and [Delay Timer 1] will always exist if turn on __CAMERA_FEATURE_DELAY_TIMER__*/
		#define __CAMERA_FEATURE_DELAY_TIMER_2__
		#define __CAMERA_FEATURE_DELAY_TIMER_3__

		#define CAMERA_FEATURE_DELAY_TIMER_1_DURATION	(5)
		#define CAMERA_FEATURE_DELAY_TIMER_2_DURATION	(10)
		#define CAMERA_FEATURE_DELAY_TIMER_3_DURATION	(15)


		/* capture style */ 
		//#define __CAMERA_FEATURE_CAPTURE_TO_MEMORY__ 

		/* Misc define */
		#define CAMERA_SHUTTER_SOUND_VOLUMN			(LEVEL5)	/* LEVEL1 - LEVEL7 */
		#define CAMERA_SHORTCUT_KEY					(KEY_CAMERA)	
		#define CAMERA_CAPTURE_KEY						(KEY_CAMERA)
		#define CAMERA_CAPTURE_EXTRA_KEY1				(KEY_IP)			/* if no extra, set -1 */
		#define CAMERA_CAPTURE_EXTRA_KEY2				(-1)
		#define CAMERA_TOGGLE_SELF_CAPTURE_KEY		(KEY_STAR)
		#define CAMERA_TOGGLE_HIDE_OSD_KEY			(KEY_POUND)		
		#define CAMERA_EFFECT_KEY						(KEY_1)			/* if no use hotkey, set -1 */
		#define CAMERA_WB_KEY							(KEY_2)
		#define CAMERA_NIGHT_KEY						(-1)
		#if defined(__CAMERA_FEATURE_FLASH__)
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(KEY_3)
		#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)	
			#define CAMERA_LED_HIGHLIGHT_KEY				(KEY_3)
			#define CAMERA_FLASH_KEY						(-1)
		#else 
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(-1)		
		#endif
		#define CAMERA_CONT_SHOT_KEY					(KEY_5)
		#define CAMERA_IMAGE_QTY_KEY					(KEY_7)
		#define CAMERA_IMAGE_SIZE_KEY					(KEY_8)
		#define CAMERA_DSC_MODE_KEY					(KEY_6)			
		#define CAMERA_ISO_KEY							(-1)	
        #ifdef __CAMERA_FEATURE_AE_METER__
    		#define CAMERA_DELAY_TIMER_KEY				(-1)		
            #define CAMERA_AE_METER_KEY					(KEY_4)	
        #else
    		#define CAMERA_DELAY_TIMER_KEY				(KEY_4)
            #define CAMERA_AE_METER_KEY					(-1)			
        #endif
		#define CAMERA_STORAGE_KEY						(-1)
        #define CAMERA_AF_METER_KEY                     (-1)
        #define CAMERA_AF_MODE_KEY                      (-1)

		/***************************************************************************** 
		* Default Setting 
		*****************************************************************************/
		/*********** Preview ***********/
		#define CAMERA_DEFAULT_SETTING_ZOOM_IDX			(0)	/* index - start from 0 */
		#define CAMERA_DEFAULT_SETTING_WB					CAMERA_SETTING_WB_AUTO
		#define CAMERA_DEFAULT_SETTING_FLASH				CAMERA_SETTING_FLASH_OFF
		#define CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT		CAMERA_SETTING_LED_HIGHLIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_SHUTTER_SOUND		CAMERA_SETTING_SHUTTER_SOUND_1
		#define CAMERA_DEFAULT_SETTING_EV					CAMERA_SETTING_EV_0	
		#define CAMERA_DEFAULT_SETTING_NIGHT				CAMERA_SETTING_NIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_CLOSEUP				CAMERA_SETTING_CLOSEUP_OFF
		#define CAMERA_DEFAULT_SETTING_BANDING				CAMERA_SETTING_BANDING_60HZ
		#define CAMERA_DEFAULT_SETTING_EFFECT				CAMERA_SETTING_EFFECT_NORMAL
		#define CAMERA_DEFAULT_SETTING_ADD_FRAME			CAMERA_SETTING_ADD_FRAME_OFF
		#define CAMERA_DEFAULT_SETTING_CONT_SHOT			CAMERA_SETTING_CONT_SHOT_OFF
		#define CAMERA_DEFAULT_SETTING_DELAY_TIMER		CAMERA_SETTING_DELAY_TIMER_OFF
		#define CAMERA_DEFAULT_SETTING_AE_METER			(0)
		#define CAMERA_DEFAULT_SETTING_ISO					(0)
		#define CAMERA_DEFAULT_SETTING_DSC_MODE			(0)				
		#define CAMERA_DEFAULT_SETTING_AUTOFOCUS			(0)

		#define CAMERA_DEFAULT_SETTING_SHUTTER_PRI		(0)
		#define CAMERA_DEFAULT_SETTING_APERTURE_PRI		(0)

		/* custom fx */
		#define CAMERA_DEFAULT_SETTING_BRIGHTNESS			(128)	
		#define CAMERA_DEFAULT_SETTING_SATURATION			(128)	
		#define CAMERA_DEFAULT_SETTING_CONTRAST			(128)	
		#define CAMERA_DEFAULT_SETTING_HUE					(0)	

		/* led highlight/flash value */
		#define CAMERA_DEFAULT_PREVIEW_LED_VALUE			(70)	
		#define CAMERA_DEFAULT_CAPTURE_LED_VALUE			(90)	
		#define CAMERA_DEFAULT_PREVIEW_FLASH_VALUE		(100) 	/* not used */
		#define CAMERA_DEFAULT_CAPTURE_FLASH_VALUE		(100)		/* not used */

		/* capture */
		#define CAMERA_DEFAULT_SETTING_IMAGE_SIZE			CAMERA_SETTING_IMAGE_SIZE_SS
		#define CAMERA_DEFAULT_SETTING_IMAGE_QTY			CAMERA_SETTING_IMAGE_QTY_NORMAL

		/***************************************************************************** 
		* Manual White Balance 
		*****************************************************************************/

		#define __CAMERA_FEATURE_WB__

		#define __CAMERA_FEATURE_WB_AUTO__
		#define __CAMERA_FEATURE_WB_DAYLIGHT__
		#define __CAMERA_FEATURE_WB_TUNGSTEN__
		#define __CAMERA_FEATURE_WB_FLUORESCENT__
		#define __CAMERA_FEATURE_WB_CLOUD__
		#define __CAMERA_FEATURE_WB_INCANDESCENCE__
		//#define __CAMERA_FEATURE_WB_MANUAL__

	

		/***************************************************************************** 
		* Add Frame 
		*****************************************************************************/

		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_ADD_FRAME_NORMAL__


		/******* customizable add frame *********/
		#define __CAMERA_FEATURE_ADD_FRAME_1__
		#define __CAMERA_FEATURE_ADD_FRAME_2__
        /*
		#define __CAMERA_FEATURE_ADD_FRAME_3__
		#define __CAMERA_FEATURE_ADD_FRAME_4__
		#define __CAMERA_FEATURE_ADD_FRAME_5__
		#define __CAMERA_FEATURE_ADD_FRAME_6__
		#define __CAMERA_FEATURE_ADD_FRAME_7__
		#define __CAMERA_FEATURE_ADD_FRAME_8__
		#define __CAMERA_FEATURE_ADD_FRAME_9__
		#define __CAMERA_FEATURE_ADD_FRAME_10__
		*/
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__		/* not implment yet */


		/***************************************************************************** 
		* END OF SETTING
		*****************************************************************************/


	#elif defined(MT6227D) || defined(MT6227)
	/***************************************************************************** 
	* MT6227 - 2M sensor
	*****************************************************************************/
		/***************************************************************************** 
		* OSD
		*****************************************************************************/
		/* Zooming */
		#define __CAMERA_FEATURE_ZOOM__

		#define CAMERA_FEATURE_ZOOM_COUNT			(71)
		#ifdef __MMI_CAMERA_ONLY__
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
																							40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
																							70,71,72,73,74,75,76,77,78,79,80};
		#else
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT];
		#endif

		/***************************************************************************** 
		* Option Menu 
		*****************************************************************************/
		/* menu [Camera Setting] [Image Setting] [Effect Setting] [Restore Default] will always exist */

		#define __CAMERA_FEATURE_EFFECT__
		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_CONT_SHOT__
		#define __CAMERA_FEATURE_DELAY_TIMER__

		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
            #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
               #define __MMI_SUBLCD_CAMERA__
            #endif
			#define __CAMERA_FEATURE_SELF_CAPTURE__
		#endif

		#ifdef AF_SUPPORT
			/***************************************************************************** 
			* Auto Exposure 
			*****************************************************************************/
			#define __CAMERA_FEATURE_AE_METER__

			#define __CAMERA_FEATURE_AE_METER_AUTO__
			#define __CAMERA_FEATURE_AE_METER_SPOT__
			#define __CAMERA_FEATURE_AE_METER_CENTER__
			#define __CAMERA_FEATURE_AE_METER_AVERAGE__

			/***************************************************************************** 
			* Auto Focus  
			*****************************************************************************/
			#define __CAMERA_AUTOFOCUS__

			#define __CAMERA_AUTOFOCUS_METERING__
			#define __CAMERA_AUTOFOCUS_1_ZONE__

			#define __CAMERA_AUTOFOCUS_MODE__
			#define __CAMERA_AUTOFOCUS_MODE_AUTO__

			#define CAMERA_AF_POSITION_1_X							(LCD_WIDTH/2)
			#define CAMERA_AF_POSITION_1_Y							(LCD_HEIGHT/2)
			#define CAMERA_AF_POSITION_2_X							(CAMERA_AF_POSITION_1_X + 40)
			#define CAMERA_AF_POSITION_2_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_3_X							(CAMERA_AF_POSITION_1_X - 40)
			#define CAMERA_AF_POSITION_3_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_4_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_4_Y							(CAMERA_AF_POSITION_1_Y	+ 40)
			#define CAMERA_AF_POSITION_5_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_5_Y							(CAMERA_AF_POSITION_1_Y - 40)

			/***************************************************************************** 
			* DSC Mode 
			*****************************************************************************/

			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_FLOWER__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#else
			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#endif		

		/***************************************************************************** 
		* Camera Setting
		*****************************************************************************/
		/********** settings  ***********/ 
		#define __CAMERA_FEATURE_SHUTTER_SOUND__
		#define __CAMERA_FEATURE_EV__
		//#define __CAMERA_FEATURE_CLOSEUP__
		#define __CAMERA_FEATURE_BANDING__

		/******* customizable shutter sound *********/
		#define __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_1__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_2__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_3__

		/******* customizable ev *********/
		/* default will have off [ev 0] and [ev +1] [ev -1] menu if __CAMERA_FEATURE_EV__ is turn on */
		#define __CAMERA_FEATURE_EV_2__
		#define __CAMERA_FEATURE_EV_3__
		#define __CAMERA_FEATURE_EV_4__


		/***************************************************************************** 
		* Image Setting
		*****************************************************************************/
		/* Notice, [Image Size] and [Image Qty] will always exist */

		#if defined(OV7670) || defined(OV7660) || defined(HV7131) || defined(PO3030K)
			/* 640x480 Sensor */

			#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(128)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

                #ifdef __CAMERA_OSD_HORIZONTAL__
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    				
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)
                #else                
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    				
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(160)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)
                #endif
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) ) 
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

                #ifdef __CAMERA_OSD_HORIZONTAL__
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)
                #else
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(132)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(176)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)		
                #endif

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				//#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

                
                #ifdef __CAMERA_OSD_HORIZONTAL__ 
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)		
                #else
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(0)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)	
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)	
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(180)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(0)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(240)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (20)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(0)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)		
                #endif
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

			#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    	
//				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
    	
            
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(960)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(80)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(60)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(40)		
    		
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
    		
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */
				
			#else /* other LCD size */
			
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(120)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(120)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(120)
				
				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)	

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	
				
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
			
		#else
			/* other 1280x1024 sensor */

			/******* customizable image size *********/
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
				
			#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(128)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(96)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(128)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(128)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)	

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))

                #ifdef __CAMERA_OSD_HORIZONTAL__			
                    #define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(120)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(160)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(128)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)	                
                #else
                    #define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
    				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
    				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
    				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
    				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
    				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(160)
    			
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(96)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(128)
    				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(160)

    				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
    				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
    				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
    				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
    				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)	
                #endif
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )  
			
				#ifdef __CAMERA_OSD_HORIZONTAL__
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1600)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1200)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(1280)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(1024)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(164)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(26)
				#else
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
					#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
					#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
					#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
					#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
					#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(141)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(132)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(176)
					#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

					#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
					#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
					#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
					#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
					#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(20)	
				#endif

				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(30)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

			#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )


			#ifdef __CAMERA_OSD_HORIZONTAL__
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH			(1600)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(1200)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT			(320)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT 		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT 		(20)	
			#else			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1600)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1200)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(320)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(30)	
			#endif
			
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    	
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
    	
            
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1600)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1200)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (960)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(240)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(12)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(24)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(26)		
    		
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
    		
				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */
				
				
			#else /* other LCD size */
			
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(LCD_HEIGHT)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(LCD_HEIGHT)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(LCD_HEIGHT)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(LCD_WIDTH)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(LCD_HEIGHT)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(10)
				
				#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
				#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
				
			#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
		
		#endif /* CMOSE SENSOR */
		
		
		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH 	SUBLCD_WIDTH
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT 	SUBLCD_HEIGHT
		#endif 

		/******* customizable image qty *********/
		//#define __CAMERA_FEATURE_IMAGE_QTY_FINE__	/* turn of due to captured image too large */
		#define __CAMERA_FEATURE_IMAGE_QTY_HIGH__
		#define __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
		#define __CAMERA_FEATURE_IMAGE_QTY_LOW__


		/******* customizable effect *********/
		#define __CAMERA_FEATURE_EFFECT_NORMAL__
		#define __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		#define __CAMERA_FEATURE_EFFECT_SEPIA__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		#define __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		#define __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
		#define __CAMERA_FEATURE_EFFECT_BLACKBOARD__
		#define __CAMERA_FEATURE_EFFECT_WHITEBOARD__
		#define __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
		#define __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
		#define __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
		#define __CAMERA_FEATURE_EFFECT_CONTRAST__
		//#define __CAMERA_FEATURE_EFFECT_JEAN__ 	/* turn off due to some ISP will reuslt bad qty */
		#define __CAMERA_FEATURE_EFFECT_SKETCH__
		//#define __CAMERA_FEATURE_EFFECT_OIL__	/* turn off due to some ISP will reuslt bad qty */

		#if !defined(__CAMERA_FEATURE_TOUCH_SCREEN__)
			/* use OSD menu currently do not support enter custom effect edit screen */
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		#endif 

		/******* customizable cont shot *********/
		/* Notice, [Cont shot Off] and [Cont shot 1] will always exist if turn on __CAMERA_FEATURE_CONT_SHOT__*/
		#define __CAMERA_FEATURE_CONT_SHOT_2__
		#define __CAMERA_FEATURE_CONT_SHOT_3__
		//#define __CAMERA_FEATURE_CONT_SHOT_BURST__	/* 6219 not support */

		#define CAMERA_FEATURE_CONT_SHOT_1_COUNT					(1)
		#define CAMERA_FEATURE_CONT_SHOT_2_COUNT					(3)
		#define CAMERA_FEATURE_CONT_SHOT_3_COUNT					(5)
		#define CAMERA_FEATURE_CONT_SHOT_BURST_COUNT 			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW			(0)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL			(0)	

		/******* customizable delay timer *********/
		/* Notice, [Delay Timer Off] and [Delay Timer 1] will always exist if turn on __CAMERA_FEATURE_DELAY_TIMER__*/
		#define __CAMERA_FEATURE_DELAY_TIMER_2__
		#define __CAMERA_FEATURE_DELAY_TIMER_3__

		#define CAMERA_FEATURE_DELAY_TIMER_1_DURATION	(5)
		#define CAMERA_FEATURE_DELAY_TIMER_2_DURATION	(10)
		#define CAMERA_FEATURE_DELAY_TIMER_3_DURATION	(15)


		/* capture style */ 
		//#define __CAMERA_FEATURE_CAPTURE_TO_MEMORY__ 

		/* Misc define */
		#define CAMERA_SHUTTER_SOUND_VOLUMN			(LEVEL5)	/* LEVEL1 - LEVEL7 */
		#define CAMERA_SHORTCUT_KEY					(KEY_CAMERA)	
		#define CAMERA_CAPTURE_KEY						(KEY_CAMERA)
		#define CAMERA_CAPTURE_EXTRA_KEY1				(KEY_IP)			/* if no extra, set -1 */
		#define CAMERA_CAPTURE_EXTRA_KEY2				(-1)
		#define CAMERA_TOGGLE_SELF_CAPTURE_KEY		(KEY_STAR)
		#define CAMERA_TOGGLE_HIDE_OSD_KEY			(KEY_POUND)		
		#define CAMERA_EFFECT_KEY						(KEY_1)			/* if no use hotkey, set -1 */
		#define CAMERA_WB_KEY							(KEY_2)
		#define CAMERA_NIGHT_KEY						(-1)
		#if defined(__CAMERA_FEATURE_FLASH__)
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(KEY_3)
		#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)	
			#define CAMERA_LED_HIGHLIGHT_KEY				(KEY_3)
			#define CAMERA_FLASH_KEY						(-1)
		#else 
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(-1)		
		#endif
		#define CAMERA_CONT_SHOT_KEY					(KEY_5)
		#define CAMERA_IMAGE_QTY_KEY					(KEY_7)
		#define CAMERA_IMAGE_SIZE_KEY					(KEY_8)
		#define CAMERA_DSC_MODE_KEY					(KEY_6)			
		#define CAMERA_AE_METER_KEY 					(-1)		
		#if defined(__CAMERA_FEATURE_ISO_SUPPORT__)
			#define CAMERA_DELAY_TIMER_KEY			(-1)		
			#define CAMERA_ISO_KEY					(KEY_4)	
		#else
			#define CAMERA_DELAY_TIMER_KEY			(KEY_4)
			#define CAMERA_ISO_KEY					(-1)			
		#endif
		#define CAMERA_STORAGE_KEY						(-1)
        #define CAMERA_AF_METER_KEY                     (-1)
        #define CAMERA_AF_MODE_KEY                      (-1)

		/***************************************************************************** 
		* Default Setting 
		*****************************************************************************/
		/*********** Preview ***********/
		#define CAMERA_DEFAULT_SETTING_ZOOM_IDX			(0)	/* index - start from 0 */
		#define CAMERA_DEFAULT_SETTING_WB					CAMERA_SETTING_WB_AUTO
		#define CAMERA_DEFAULT_SETTING_FLASH				CAMERA_SETTING_FLASH_OFF
		#define CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT		CAMERA_SETTING_LED_HIGHLIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_SHUTTER_SOUND		CAMERA_SETTING_SHUTTER_SOUND_1
		#define CAMERA_DEFAULT_SETTING_EV					CAMERA_SETTING_EV_0	
		#define CAMERA_DEFAULT_SETTING_NIGHT				CAMERA_SETTING_NIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_CLOSEUP				CAMERA_SETTING_CLOSEUP_OFF
		#define CAMERA_DEFAULT_SETTING_BANDING				CAMERA_SETTING_BANDING_60HZ
		#define CAMERA_DEFAULT_SETTING_EFFECT				CAMERA_SETTING_EFFECT_NORMAL
		#define CAMERA_DEFAULT_SETTING_ADD_FRAME			CAMERA_SETTING_ADD_FRAME_OFF
		#define CAMERA_DEFAULT_SETTING_CONT_SHOT			CAMERA_SETTING_CONT_SHOT_OFF
		#define CAMERA_DEFAULT_SETTING_DELAY_TIMER		CAMERA_SETTING_DELAY_TIMER_OFF
		#define CAMERA_DEFAULT_SETTING_AE_METER			(0)
		#define CAMERA_DEFAULT_SETTING_ISO					(0)
		#define CAMERA_DEFAULT_SETTING_DSC_MODE			(0)				
		#define CAMERA_DEFAULT_SETTING_AUTOFOCUS			(0)

		#define CAMERA_DEFAULT_SETTING_SHUTTER_PRI		(0)
		#define CAMERA_DEFAULT_SETTING_APERTURE_PRI		(0)

		/* custom fx */
		#define CAMERA_DEFAULT_SETTING_BRIGHTNESS			(128)	
		#define CAMERA_DEFAULT_SETTING_SATURATION			(128)	
		#define CAMERA_DEFAULT_SETTING_CONTRAST			(128)	
		#define CAMERA_DEFAULT_SETTING_HUE					(0)	

		/* led highlight/flash value */
		#define CAMERA_DEFAULT_PREVIEW_LED_VALUE			(70)	
		#define CAMERA_DEFAULT_CAPTURE_LED_VALUE			(90)	
		#define CAMERA_DEFAULT_PREVIEW_FLASH_VALUE		(100) 	/* not used */
		#define CAMERA_DEFAULT_CAPTURE_FLASH_VALUE		(100)		/* not used */

		/* capture */
		#define CAMERA_DEFAULT_SETTING_IMAGE_SIZE			CAMERA_SETTING_IMAGE_SIZE_SS
		#define CAMERA_DEFAULT_SETTING_IMAGE_QTY			CAMERA_SETTING_IMAGE_QTY_NORMAL

		/***************************************************************************** 
		* Manual White Balance 
		*****************************************************************************/

		#define __CAMERA_FEATURE_WB__

		#define __CAMERA_FEATURE_WB_AUTO__
		#define __CAMERA_FEATURE_WB_DAYLIGHT__
		#define __CAMERA_FEATURE_WB_TUNGSTEN__
		#define __CAMERA_FEATURE_WB_FLUORESCENT__
		#define __CAMERA_FEATURE_WB_CLOUD__
		#define __CAMERA_FEATURE_WB_INCANDESCENCE__
		//#define __CAMERA_FEATURE_WB_MANUAL__

	

		/***************************************************************************** 
		* Add Frame 
		*****************************************************************************/

		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_ADD_FRAME_NORMAL__


		/******* customizable add frame *********/
		#define __CAMERA_FEATURE_ADD_FRAME_1__
		#define __CAMERA_FEATURE_ADD_FRAME_2__
        /*
		#define __CAMERA_FEATURE_ADD_FRAME_3__
		#define __CAMERA_FEATURE_ADD_FRAME_4__
		#define __CAMERA_FEATURE_ADD_FRAME_5__
		#define __CAMERA_FEATURE_ADD_FRAME_6__
		#define __CAMERA_FEATURE_ADD_FRAME_7__
		#define __CAMERA_FEATURE_ADD_FRAME_8__
		#define __CAMERA_FEATURE_ADD_FRAME_9__
		#define __CAMERA_FEATURE_ADD_FRAME_10__
		*/
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__		/* not implment yet */


		/***************************************************************************** 
		* END OF SETTING
		*****************************************************************************/
    #elif defined(MT6228) || defined(MT6229) || defined(MT6238)
	/***************************************************************************** 
	* 
	* MT6228 MT6229 MT6238
	*
	*****************************************************************************/

		/***************************************************************************** 
		* OSD
		*****************************************************************************/
		/* Zooming */
		#define __CAMERA_FEATURE_ZOOM__

		#define CAMERA_FEATURE_ZOOM_COUNT			(71)
		#ifdef __MMI_CAMERA_ONLY__
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
																							40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
																							70,71,72,73,74,75,76,77,78,79,80};
		#else
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT];
		#endif

		/***************************************************************************** 
		* Option Menu 
		*****************************************************************************/
		/* menu [Camera Setting] [Image Setting] [Effect Setting] [Restore Default] will always exist */

		#define __CAMERA_FEATURE_EFFECT__
		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_CONT_SHOT__
		#define __CAMERA_FEATURE_DELAY_TIMER__

		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
            #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
               #define __MMI_SUBLCD_CAMERA__
            #endif
			#define __CAMERA_FEATURE_SELF_CAPTURE__
		#endif

		#ifdef AF_SUPPORT
			/***************************************************************************** 
			* Auto Exposure 
			*****************************************************************************/
			#define __CAMERA_FEATURE_AE_METER__

			#define __CAMERA_FEATURE_AE_METER_AUTO__
			#define __CAMERA_FEATURE_AE_METER_SPOT__
			#define __CAMERA_FEATURE_AE_METER_CENTER__
			#define __CAMERA_FEATURE_AE_METER_AVERAGE__

			/***************************************************************************** 
			* Auto Focus  
			*****************************************************************************/
			#define __CAMERA_AUTOFOCUS__

			#define __CAMERA_AUTOFOCUS_METERING__
			#define __CAMERA_AUTOFOCUS_1_ZONE__

			#define __CAMERA_AUTOFOCUS_MODE__
			#define __CAMERA_AUTOFOCUS_MODE_AUTO__

			#define CAMERA_AF_POSITION_1_X							(LCD_WIDTH/2)
			#define CAMERA_AF_POSITION_1_Y							(LCD_HEIGHT/2)
			#define CAMERA_AF_POSITION_2_X							(CAMERA_AF_POSITION_1_X + 40)
			#define CAMERA_AF_POSITION_2_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_3_X							(CAMERA_AF_POSITION_1_X - 40)
			#define CAMERA_AF_POSITION_3_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_4_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_4_Y							(CAMERA_AF_POSITION_1_Y	+ 40)
			#define CAMERA_AF_POSITION_5_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_5_Y							(CAMERA_AF_POSITION_1_Y - 40)
			
			/***************************************************************************** 
			* DSC Mode 
			*****************************************************************************/

			#define __CAMERA_DSC_MODE__
		
			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_FLOWER__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
	    #else
			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#endif	



		/***************************************************************************** 
		* Camera Setting
		*****************************************************************************/
		/********** settings  ***********/ 
		#define __CAMERA_FEATURE_SHUTTER_SOUND__
		#define __CAMERA_FEATURE_EV__
		//#define __CAMERA_FEATURE_NIGHT__
		//#define __CAMERA_FEATURE_CLOSEUP__
		#define __CAMERA_FEATURE_BANDING__

		/******* customizable shutter sound *********/
		#define __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_1__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_2__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_3__

		/******* customizable ev *********/
		/* default will have off [ev 0] and [ev +1] [ev -1] menu if __CAMERA_FEATURE_EV__ is turn on */
		#define __CAMERA_FEATURE_EV_2__
		#define __CAMERA_FEATURE_EV_3__
		#define __CAMERA_FEATURE_EV_4__

		/***************************************************************************** 
		* Image Setting
		*****************************************************************************/
		/* Notice, [Image Size] and [Image Qty] will always exist */

			
		#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))

			/******* customizable image size *********/
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(2048)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1536)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(1600)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(1200)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(128)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(103)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(128)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(40)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(40)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(40)	

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
		
			/******* customizable image size *********/
			#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
			#define __CAMERA_FEATURE_IMAGE_SIZE_L__
			#define __CAMERA_FEATURE_IMAGE_SIZE_M__
			#define __CAMERA_FEATURE_IMAGE_SIZE_S__
			#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(2048)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1536)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(1600)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(1200)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(160)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(103)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(160)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(40)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(40)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(40)	

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )

		
			#ifdef __CAMERA_OSD_HORIZONTAL__

				/******* customizable image size *********/
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1600)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1200)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(220)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)

    			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(1)  	/* SS, S, M, L, LL */
			#else

				/******* customizable image size *********/
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(220)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(141)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)	

    			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#endif

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(30)	


			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

			
		#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
		
		
			#ifdef __CAMERA_OSD_HORIZONTAL__
				/******* customizable image size *********/
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH			(1600)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(1200)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH				(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT			(320)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(320)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT 		(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT 		(20)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(1)  	/* SS, S, M, L, LL */

			#else	
				/******* customizable image size *********/
				#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
				#define __CAMERA_FEATURE_IMAGE_SIZE_L__
				#define __CAMERA_FEATURE_IMAGE_SIZE_M__
				#define __CAMERA_FEATURE_IMAGE_SIZE_S__
				#define __CAMERA_FEATURE_IMAGE_SIZE_SS__

				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1600)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1200)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(320)
			
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(192)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(180)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(240)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(320)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)	

				#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */

			#endif
			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* SS, S, M, L, LL */		
			
    	#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    	
    		#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_L__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_M__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_S__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
    	
            
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1600)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1200)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (960)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(800)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(600)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(240)

			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(12)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(24)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(26)		
    		
    		#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
    		
    		#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */


		#else /* other LCD size */
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(2048)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1536)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(1600)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(1200)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(LCD_HEIGHT)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(LCD_HEIGHT)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT 		(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH 			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH 			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH 			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT 		(LCD_HEIGHT)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)
			
			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
		
		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH 	SUBLCD_WIDTH
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT 	SUBLCD_HEIGHT
		#endif 

		/******* customizable image qty *********/
		//#define __CAMERA_FEATURE_IMAGE_QTY_FINE__	/* turn of due to captured image too large */
		#define __CAMERA_FEATURE_IMAGE_QTY_HIGH__
		#define __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
		#define __CAMERA_FEATURE_IMAGE_QTY_LOW__


		/******* customizable effect *********/
		#define __CAMERA_FEATURE_EFFECT_NORMAL__
		#define __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		#define __CAMERA_FEATURE_EFFECT_SEPIA__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		#define __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		#define __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
		#define __CAMERA_FEATURE_EFFECT_BLACKBOARD__
		#define __CAMERA_FEATURE_EFFECT_WHITEBOARD__
		#define __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
		#define __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
		#define __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
		#define __CAMERA_FEATURE_EFFECT_CONTRAST__
		//#define __CAMERA_FEATURE_EFFECT_JEAN__ 	/* turn off due to some ISP will reuslt bad qty */
		#define __CAMERA_FEATURE_EFFECT_SKETCH__
		//#define __CAMERA_FEATURE_EFFECT_OIL__	/* turn off due to some ISP will reuslt bad qty */

		#if !defined(__CAMERA_FEATURE_TOUCH_SCREEN__)
			/* use OSD menu currently do not support enter custom effect edit screen */
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		#endif 


		/******* customizable add frame *********/
		#define __CAMERA_FEATURE_ADD_FRAME_1__
		#define __CAMERA_FEATURE_ADD_FRAME_2__
        /*
		#define __CAMERA_FEATURE_ADD_FRAME_3__
		#define __CAMERA_FEATURE_ADD_FRAME_4__
		#define __CAMERA_FEATURE_ADD_FRAME_5__
		#define __CAMERA_FEATURE_ADD_FRAME_6__
		#define __CAMERA_FEATURE_ADD_FRAME_7__
		#define __CAMERA_FEATURE_ADD_FRAME_8__
		#define __CAMERA_FEATURE_ADD_FRAME_9__
		#define __CAMERA_FEATURE_ADD_FRAME_10__
		*/
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__		/* not implment yet */

			
		/******* customizable cont shot *********/
		/* Notice, [Cont shot Off] and [Cont shot 1] will always exist if turn on __CAMERA_FEATURE_CONT_SHOT__*/
		//#define __CAMERA_FEATURE_CONT_SHOT_2__
		//#define __CAMERA_FEATURE_CONT_SHOT_3__
		#define __CAMERA_FEATURE_CONT_SHOT_BURST__

		#define CAMERA_FEATURE_CONT_SHOT_1_COUNT					(1)
		#define CAMERA_FEATURE_CONT_SHOT_2_COUNT					(3)
		#define CAMERA_FEATURE_CONT_SHOT_3_COUNT					(5)
		
		#define CAMERA_FEATURE_CONT_SHOT_BURST_COUNT 			(9)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW			(3)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL			(3)	

		/* MT6228 use non-blocking burst */
		#define __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__	/* non-blocking burst shot */
					

		/******* customizable delay timer *********/
		/* Notice, [Delay Timer Off] and [Delay Timer 1] will always exist if turn on __CAMERA_FEATURE_DELAY_TIMER__*/
		#define __CAMERA_FEATURE_DELAY_TIMER_2__
		#define __CAMERA_FEATURE_DELAY_TIMER_3__

		#define CAMERA_FEATURE_DELAY_TIMER_1_DURATION	(5)
		#define CAMERA_FEATURE_DELAY_TIMER_2_DURATION	(10)
		#define CAMERA_FEATURE_DELAY_TIMER_3_DURATION	(15)

		/* Misc define */
		#define CAMERA_SHUTTER_SOUND_VOLUMN			(LEVEL5)	/* LEVEL1 - LEVEL7 */
		#define CAMERA_SHORTCUT_KEY					(KEY_CAMERA)	
		#define CAMERA_CAPTURE_KEY						(KEY_CAMERA)
		#define CAMERA_CAPTURE_EXTRA_KEY1				(KEY_IP)			/* if no extra, set -1 */
		#define CAMERA_CAPTURE_EXTRA_KEY2				(-1)
		#define CAMERA_TOGGLE_SELF_CAPTURE_KEY		(KEY_STAR)
		#define CAMERA_TOGGLE_HIDE_OSD_KEY			(KEY_POUND)		
		#define CAMERA_EFFECT_KEY						(KEY_1)			/* if no use hotkey, set -1 */
		#define CAMERA_WB_KEY							(KEY_2)
		#define CAMERA_NIGHT_KEY						(-1)
		#if defined(__CAMERA_FEATURE_FLASH__)
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(KEY_3)
		#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)	
			#define CAMERA_LED_HIGHLIGHT_KEY				(KEY_3)
			#define CAMERA_FLASH_KEY						(-1)
		#else
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(-1)		
		#endif
		#define CAMERA_CONT_SHOT_KEY					(KEY_5)
		#define CAMERA_IMAGE_QTY_KEY					(KEY_7)
		#define CAMERA_IMAGE_SIZE_KEY					(KEY_8)
		#define CAMERA_DSC_MODE_KEY					(KEY_6)			
		#define CAMERA_AE_METER_KEY 					(-1)		
		#if defined(__CAMERA_FEATURE_ISO_SUPPORT__)
			#define CAMERA_DELAY_TIMER_KEY			(-1)		
			#define CAMERA_ISO_KEY					(KEY_4)	
		#else
			#define CAMERA_DELAY_TIMER_KEY			(KEY_4)
			#define CAMERA_ISO_KEY					(-1)			
		#endif
        #define CAMERA_STORAGE_KEY						(-1)
        #define CAMERA_AF_METER_KEY                     (-1)
        #define CAMERA_AF_MODE_KEY                      (-1)

		/***************************************************************************** 
		* Default Setting 
		*****************************************************************************/
		/*********** Preview ***********/
		#define CAMERA_DEFAULT_SETTING_ZOOM_IDX			(0)	/* index - start from 0 */
		#define CAMERA_DEFAULT_SETTING_WB					CAMERA_SETTING_WB_AUTO
		#define CAMERA_DEFAULT_SETTING_FLASH				CAMERA_SETTING_FLASH_OFF
		#define CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT		CAMERA_SETTING_LED_HIGHLIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_SHUTTER_SOUND		CAMERA_SETTING_SHUTTER_SOUND_1
		#define CAMERA_DEFAULT_SETTING_EV					CAMERA_SETTING_EV_0	
		#define CAMERA_DEFAULT_SETTING_NIGHT				CAMERA_SETTING_NIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_CLOSEUP				CAMERA_SETTING_CLOSEUP_OFF
		#define CAMERA_DEFAULT_SETTING_BANDING				CAMERA_SETTING_BANDING_60HZ
		#define CAMERA_DEFAULT_SETTING_EFFECT				CAMERA_SETTING_EFFECT_NORMAL
		#define CAMERA_DEFAULT_SETTING_ADD_FRAME			CAMERA_SETTING_ADD_FRAME_OFF
		#define CAMERA_DEFAULT_SETTING_CONT_SHOT			CAMERA_SETTING_CONT_SHOT_OFF
		#define CAMERA_DEFAULT_SETTING_DELAY_TIMER		CAMERA_SETTING_DELAY_TIMER_OFF
		#define CAMERA_DEFAULT_SETTING_AE_METER			(0)
		#define CAMERA_DEFAULT_SETTING_ISO					(0)
		#define CAMERA_DEFAULT_SETTING_DSC_MODE			(0)
		#define CAMERA_DEFAULT_SETTING_AUTOFOCUS			(0)

		/* custom fx */
		#define CAMERA_DEFAULT_SETTING_BRIGHTNESS			(128)	
		#define CAMERA_DEFAULT_SETTING_SATURATION			(128)	
		#define CAMERA_DEFAULT_SETTING_CONTRAST			(128)	
		#define CAMERA_DEFAULT_SETTING_HUE					(0)	

		/* led highlight/flash value */
		#define CAMERA_DEFAULT_PREVIEW_LED_VALUE			(70)	
		#define CAMERA_DEFAULT_CAPTURE_LED_VALUE			(90)	
		#define CAMERA_DEFAULT_PREVIEW_FLASH_VALUE		(100) 	/* not used */
		#define CAMERA_DEFAULT_CAPTURE_FLASH_VALUE		(100)		/* not used */

		/* capture */
		#define CAMERA_DEFAULT_SETTING_IMAGE_SIZE			CAMERA_SETTING_IMAGE_SIZE_SS
		#define CAMERA_DEFAULT_SETTING_IMAGE_QTY			CAMERA_SETTING_IMAGE_QTY_NORMAL

		/***************************************************************************** 
		* Manual White Balance 
		*****************************************************************************/

		#define __CAMERA_FEATURE_WB__

		#define __CAMERA_FEATURE_WB_AUTO__
		#define __CAMERA_FEATURE_WB_DAYLIGHT__
		#define __CAMERA_FEATURE_WB_TUNGSTEN__
		#define __CAMERA_FEATURE_WB_FLUORESCENT__
		#define __CAMERA_FEATURE_WB_CLOUD__
		#define __CAMERA_FEATURE_WB_INCANDESCENCE__
		#define __CAMERA_FEATURE_WB_MANUAL__

		/***************************************************************************** 
		* Add Frame 
		*****************************************************************************/

		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_ADD_FRAME_NORMAL__
		//#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__

		#define CAMERA_ADD_FRAME_COLOR_IDX1_WIDTH 			(160)
		#define CAMERA_ADD_FRAME_COLOR_IDX1_HEIGHT 			(120)
		#define CAMERA_ADD_FRAME_COLOR_IDX2_WIDTH 			(300)
		#define CAMERA_ADD_FRAME_COLOR_IDX2_HEIGHT			(240)

		/***************************************************************************** 
		* END OF SETTING
		*****************************************************************************/
	#else
	/***************************************************************************** 
	*
	* MT6230 - 1.3M sensor
	*
	*****************************************************************************/
		/***************************************************************************** 
		* OSD
		*****************************************************************************/
		/* Zooming */
		#define __CAMERA_FEATURE_ZOOM__

		#define CAMERA_FEATURE_ZOOM_COUNT			(71)
		#ifdef __MMI_CAMERA_ONLY__
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
																							40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
																							70,71,72,73,74,75,76,77,78,79,80};
		#else
		extern int g_camera_feature_zoom[CAMERA_FEATURE_ZOOM_COUNT];
		#endif

		/***************************************************************************** 
		* Option Menu 
		*****************************************************************************/
		/* menu [Camera Setting] [Image Setting] [Effect Setting] [Restore Default] will always exist */

		#define __CAMERA_FEATURE_EFFECT__
		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_CONT_SHOT__
		#define __CAMERA_FEATURE_DELAY_TIMER__

		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
            #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
               #define __MMI_SUBLCD_CAMERA__
            #endif
			#define __CAMERA_FEATURE_SELF_CAPTURE__
		#endif

		#ifdef AF_SUPPORT
			/***************************************************************************** 
			* Auto Exposure 
			*****************************************************************************/
			#define __CAMERA_FEATURE_AE_METER__
		
			#define __CAMERA_FEATURE_AE_METER_AUTO__
			#define __CAMERA_FEATURE_AE_METER_SPOT__
			#define __CAMERA_FEATURE_AE_METER_CENTER__
			#define __CAMERA_FEATURE_AE_METER_AVERAGE__

			/***************************************************************************** 
			* Auto Focus  
			*****************************************************************************/
			#define __CAMERA_AUTOFOCUS__

			#define __CAMERA_AUTOFOCUS_METERING__
			#define __CAMERA_AUTOFOCUS_1_ZONE__

			#define __CAMERA_AUTOFOCUS_MODE__
			#define __CAMERA_AUTOFOCUS_MODE_AUTO__

			#define CAMERA_AF_POSITION_1_X							(LCD_WIDTH/2)
			#define CAMERA_AF_POSITION_1_Y							(LCD_HEIGHT/2)
			#define CAMERA_AF_POSITION_2_X							(CAMERA_AF_POSITION_1_X + 40)
			#define CAMERA_AF_POSITION_2_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_3_X							(CAMERA_AF_POSITION_1_X - 40)
			#define CAMERA_AF_POSITION_3_Y							(CAMERA_AF_POSITION_1_Y)
			#define CAMERA_AF_POSITION_4_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_4_Y							(CAMERA_AF_POSITION_1_Y	+ 40)
			#define CAMERA_AF_POSITION_5_X							(CAMERA_AF_POSITION_1_X)
			#define CAMERA_AF_POSITION_5_Y							(CAMERA_AF_POSITION_1_Y - 40)
			
			/***************************************************************************** 
			* DSC Mode 
			*****************************************************************************/
			#define __CAMERA_DSC_MODE__
		
			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_FLOWER__
			#define __CAMERA_DSC_MODE_NIGHT__
		
			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
	    #else
			#define __CAMERA_DSC_MODE__

			#define __CAMERA_DSC_MODE_AUTO__
			#define __CAMERA_DSC_MODE_NIGHT__

			// ONLY WHEN DSC MODE IS SUPPORT, ISO COULD BE TURNED ON WITH ISO_PRIORITY_SUPPORT
			#if defined(ISO_PRIORITY_SUPPORT)
				#define __CAMERA_FEATURE_ISO_SUPPORT__
	        
				#define __CAEMRA_FEATURE_ISO_AUTO__
				#define __CAEMRA_FEATURE_ISO_100__		
				#define __CAEMRA_FEATURE_ISO_200__		
				#define __CAEMRA_FEATURE_ISO_400__
			#endif
		#endif	

		/***************************************************************************** 
		* Camera Setting
		*****************************************************************************/
		/********** settings  ***********/ 
		#define __CAMERA_FEATURE_SHUTTER_SOUND__
		#define __CAMERA_FEATURE_EV__
		//#define __CAMERA_FEATURE_NIGHT__
		//#define __CAMERA_FEATURE_CLOSEUP__
		#define __CAMERA_FEATURE_BANDING__

		/******* customizable shutter sound *********/
		#define __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_1__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_2__
		#define __CAMERA_FEATURE_SHUTTER_SOUND_3__

		/******* customizable ev *********/
		/* default will have off [ev 0] and [ev +1] [ev -1] menu if __CAMERA_FEATURE_EV__ is turn on */
		#define __CAMERA_FEATURE_EV_2__
		#define __CAMERA_FEATURE_EV_3__
		#define __CAMERA_FEATURE_EV_4__

		/***************************************************************************** 
		* Image Setting
		*****************************************************************************/
		/* Notice, [Image Size] and [Image Qty] will always exist */
		/******* customizable image size *********/
		#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
		#define __CAMERA_FEATURE_IMAGE_SIZE_L__
		#define __CAMERA_FEATURE_IMAGE_SIZE_M__
		#define __CAMERA_FEATURE_IMAGE_SIZE_S__
		#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
			
		#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(128)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(128)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)	

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(128)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(160)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(103)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(96)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(128)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(160)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(30)	

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )  
		
			#ifdef __CAMERA_OSD_HORIZONTAL__
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(800)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(600)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(164)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(220)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(176)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(26)
			#else
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
				#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1024)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
				#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
				#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
				#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(176)
				#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(220)

				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(141)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(132)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(176)
				#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(220)

				#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
				#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
				#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
				#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(20)	
			#endif

			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(30)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */

		#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )

		#ifdef __CAMERA_OSD_HORIZONTAL__
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH			(1200)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT			(900)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH			(800)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT			(600)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT			(320)

			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH 		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT 		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT 		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT 		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH 		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT 		(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT 		(20)	
		#else			
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(320)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(192)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(180)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(180)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(180)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(320)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(20)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(40)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)	
		#endif
		
			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(40)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
    	#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    	
    		//#define __CAMERA_FEATURE_IMAGE_SIZE_LL__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_L__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_M__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_S__
    		#define __CAMERA_FEATURE_IMAGE_SIZE_SS__
    	
            
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1600)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 		(1200)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 		    (960)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(800)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(600)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 		(240)

			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT		(240)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH		(320)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(240)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT		(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT		    (10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(12)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(24)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT		(26)		
    		
    		#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(20)	
    		
    		#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(3)  	/* SS, S, [M], L, LL */
			
		#else /* other LCD size */
		
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH 			(1280)
			#define CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT 			(1024)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH 			(640)
			#define CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT 			(480)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH 			(320)
			#define CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT 			(240)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH 			(160)
			#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT 			(120)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH 			(LCD_HEIGHT)
			#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT 			(LCD_HEIGHT)
		
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_LL_HEIGHT		(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_L_HEIGHT			(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_M_HEIGHT			(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT			(LCD_HEIGHT)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH			(LCD_WIDTH)
			#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT		(LCD_HEIGHT)

			#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			(10)
			#define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			(10)	
			#define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(10)
			
			#define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(10)	

			#define CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX	(0)  	/* SS, S, M, L, LL */
			#define CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX		(0)  	/* [SS], S, M, L, LL */
			
		#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
		
		#if defined(__MMI_SUBLCD__) && defined(__MMI_SUBLCD_COLOR__)
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH 	SUBLCD_WIDTH
			#define CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT 	SUBLCD_HEIGHT
		#endif 

		/******* customizable image qty *********/
		//#define __CAMERA_FEATURE_IMAGE_QTY_FINE__	/* turn of due to captured image too large */
		#define __CAMERA_FEATURE_IMAGE_QTY_HIGH__
		#define __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
		#define __CAMERA_FEATURE_IMAGE_QTY_LOW__


		/******* customizable effect *********/
		#define __CAMERA_FEATURE_EFFECT_NORMAL__
		#define __CAMERA_FEATURE_EFFECT_GRAYSCALE__
		#define __CAMERA_FEATURE_EFFECT_SEPIA__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
		#define __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
		#define __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
		#define __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
		#define __CAMERA_FEATURE_EFFECT_BLACKBOARD__
		#define __CAMERA_FEATURE_EFFECT_WHITEBOARD__
		#define __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
		#define __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
		#define __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
		#define __CAMERA_FEATURE_EFFECT_CONTRAST__
		//#define __CAMERA_FEATURE_EFFECT_JEAN__ 	/* turn off due to some ISP will reuslt bad qty */
		#define __CAMERA_FEATURE_EFFECT_SKETCH__
		//#define __CAMERA_FEATURE_EFFECT_OIL__	/* turn off due to some ISP will reuslt bad qty */

		#if !defined(__CAMERA_FEATURE_TOUCH_SCREEN__)
			/* use OSD menu currently do not support enter custom effect edit screen */
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
			//#define __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
		#endif 


		/******* customizable add frame *********/
		#define __CAMERA_FEATURE_ADD_FRAME_1__
		#define __CAMERA_FEATURE_ADD_FRAME_2__
        /*
		#define __CAMERA_FEATURE_ADD_FRAME_3__
		#define __CAMERA_FEATURE_ADD_FRAME_4__
		#define __CAMERA_FEATURE_ADD_FRAME_5__
		#define __CAMERA_FEATURE_ADD_FRAME_6__
		#define __CAMERA_FEATURE_ADD_FRAME_7__
		#define __CAMERA_FEATURE_ADD_FRAME_8__
		#define __CAMERA_FEATURE_ADD_FRAME_9__
		#define __CAMERA_FEATURE_ADD_FRAME_10__
		*/
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__		/* not implment yet */
		//#define __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__		/* not implment yet */

			
		/******* customizable cont shot *********/
		/* Notice, [Cont shot Off] and [Cont shot 1] will always exist if turn on __CAMERA_FEATURE_CONT_SHOT__*/
		//#define __CAMERA_FEATURE_CONT_SHOT_2__
		//#define __CAMERA_FEATURE_CONT_SHOT_3__
		#define __CAMERA_FEATURE_CONT_SHOT_BURST__

		#define CAMERA_FEATURE_CONT_SHOT_1_COUNT					(1)
		#define CAMERA_FEATURE_CONT_SHOT_2_COUNT					(3)
		#define CAMERA_FEATURE_CONT_SHOT_3_COUNT					(5)
		
		#define CAMERA_FEATURE_CONT_SHOT_BURST_COUNT 			(9)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW			(3)	
		#define CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL			(3)	

		/* MT6228 use non-blocking burst */
		#define __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__	/* non-blocking burst shot */
					

		/******* customizable delay timer *********/
		/* Notice, [Delay Timer Off] and [Delay Timer 1] will always exist if turn on __CAMERA_FEATURE_DELAY_TIMER__*/
		#define __CAMERA_FEATURE_DELAY_TIMER_2__
		#define __CAMERA_FEATURE_DELAY_TIMER_3__

		#define CAMERA_FEATURE_DELAY_TIMER_1_DURATION	(5)
		#define CAMERA_FEATURE_DELAY_TIMER_2_DURATION	(10)
		#define CAMERA_FEATURE_DELAY_TIMER_3_DURATION	(15)

		/* Misc define */
		#define CAMERA_SHUTTER_SOUND_VOLUMN			(LEVEL5)	/* LEVEL1 - LEVEL7 */
		#define CAMERA_SHORTCUT_KEY					(KEY_CAMERA)	
		#define CAMERA_CAPTURE_KEY						(KEY_CAMERA)
		#define CAMERA_CAPTURE_EXTRA_KEY1				(KEY_IP)			/* if no extra, set -1 */
		#define CAMERA_CAPTURE_EXTRA_KEY2				(-1)
		#define CAMERA_TOGGLE_SELF_CAPTURE_KEY		(KEY_STAR)
		#define CAMERA_TOGGLE_HIDE_OSD_KEY			(KEY_POUND)		
		#define CAMERA_EFFECT_KEY						(KEY_1)			/* if no use hotkey, set -1 */
		#define CAMERA_WB_KEY							(KEY_2)
		#define CAMERA_NIGHT_KEY						(-1)
		#if defined(__CAMERA_FEATURE_FLASH__)
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(KEY_3)
		#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)	
			#define CAMERA_LED_HIGHLIGHT_KEY				(KEY_3)
			#define CAMERA_FLASH_KEY						(-1)
		#else
			#define CAMERA_LED_HIGHLIGHT_KEY				(-1)
			#define CAMERA_FLASH_KEY						(-1)		
		#endif
		#define CAMERA_CONT_SHOT_KEY					(KEY_5)
		#define CAMERA_IMAGE_QTY_KEY					(KEY_7)
		#define CAMERA_IMAGE_SIZE_KEY					(KEY_8)
		#define CAMERA_DSC_MODE_KEY					(KEY_6)			
		#define CAMERA_AE_METER_KEY 					(-1)		
		#if defined(__CAMERA_FEATURE_ISO_SUPPORT__)
			#define CAMERA_DELAY_TIMER_KEY			(-1)		
			#define CAMERA_ISO_KEY					(KEY_4)	
		#else
			#define CAMERA_DELAY_TIMER_KEY			(KEY_4)
			#define CAMERA_ISO_KEY					(-1)			
		#endif
        #define CAMERA_STORAGE_KEY						(-1)
        #define CAMERA_AF_METER_KEY                     (-1)
        #define CAMERA_AF_MODE_KEY                      (-1)

		/***************************************************************************** 
		* Default Setting 
		*****************************************************************************/
		/*********** Preview ***********/
		#define CAMERA_DEFAULT_SETTING_ZOOM_IDX			(0)	/* index - start from 0 */
		#define CAMERA_DEFAULT_SETTING_WB					CAMERA_SETTING_WB_AUTO
		#define CAMERA_DEFAULT_SETTING_FLASH				CAMERA_SETTING_FLASH_OFF
		#define CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT		CAMERA_SETTING_LED_HIGHLIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_SHUTTER_SOUND		CAMERA_SETTING_SHUTTER_SOUND_1
		#define CAMERA_DEFAULT_SETTING_EV					CAMERA_SETTING_EV_0	
		#define CAMERA_DEFAULT_SETTING_NIGHT				CAMERA_SETTING_NIGHT_OFF
		#define CAMERA_DEFAULT_SETTING_CLOSEUP				CAMERA_SETTING_CLOSEUP_OFF
		#define CAMERA_DEFAULT_SETTING_BANDING				CAMERA_SETTING_BANDING_60HZ
		#define CAMERA_DEFAULT_SETTING_EFFECT				CAMERA_SETTING_EFFECT_NORMAL
		#define CAMERA_DEFAULT_SETTING_ADD_FRAME			CAMERA_SETTING_ADD_FRAME_OFF
		#define CAMERA_DEFAULT_SETTING_CONT_SHOT			CAMERA_SETTING_CONT_SHOT_OFF
		#define CAMERA_DEFAULT_SETTING_DELAY_TIMER		CAMERA_SETTING_DELAY_TIMER_OFF
		#define CAMERA_DEFAULT_SETTING_AE_METER			(0)
		#define CAMERA_DEFAULT_SETTING_ISO					(0)
		#define CAMERA_DEFAULT_SETTING_DSC_MODE			(0)
		#define CAMERA_DEFAULT_SETTING_AUTOFOCUS			(0)

		/* custom fx */
		#define CAMERA_DEFAULT_SETTING_BRIGHTNESS			(128)	
		#define CAMERA_DEFAULT_SETTING_SATURATION			(128)	
		#define CAMERA_DEFAULT_SETTING_CONTRAST			(128)	
		#define CAMERA_DEFAULT_SETTING_HUE					(0)	

		/* led highlight/flash value */
		#define CAMERA_DEFAULT_PREVIEW_LED_VALUE			(70)	
		#define CAMERA_DEFAULT_CAPTURE_LED_VALUE			(90)	
		#define CAMERA_DEFAULT_PREVIEW_FLASH_VALUE		(100) 	/* not used */
		#define CAMERA_DEFAULT_CAPTURE_FLASH_VALUE		(100)		/* not used */

		/* capture */
		#define CAMERA_DEFAULT_SETTING_IMAGE_SIZE			CAMERA_SETTING_IMAGE_SIZE_SS
		#define CAMERA_DEFAULT_SETTING_IMAGE_QTY			CAMERA_SETTING_IMAGE_QTY_NORMAL

		/***************************************************************************** 
		* Manual White Balance 
		*****************************************************************************/

		#define __CAMERA_FEATURE_WB__

		#define __CAMERA_FEATURE_WB_AUTO__
		#define __CAMERA_FEATURE_WB_DAYLIGHT__
		#define __CAMERA_FEATURE_WB_TUNGSTEN__
		#define __CAMERA_FEATURE_WB_FLUORESCENT__
		#define __CAMERA_FEATURE_WB_CLOUD__
		#define __CAMERA_FEATURE_WB_INCANDESCENCE__
		#define __CAMERA_FEATURE_WB_MANUAL__

		/***************************************************************************** 
		* Add Frame 
		*****************************************************************************/

		#define __CAMERA_FEATURE_ADD_FRAME__
		#define __CAMERA_FEATURE_ADD_FRAME_NORMAL__
		//#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_1__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_2__
		#define __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX_3__

		#define CAMERA_ADD_FRAME_COLOR_IDX1_WIDTH 			(160)
		#define CAMERA_ADD_FRAME_COLOR_IDX1_HEIGHT 			(120)
		#define CAMERA_ADD_FRAME_COLOR_IDX2_WIDTH 			(300)
		#define CAMERA_ADD_FRAME_COLOR_IDX2_HEIGHT			(240)

		/***************************************************************************** 
		* END OF SETTING
		*****************************************************************************/

	#endif /* ISP chip version */
#endif /* ISP_SUPPORT */

#if defined(__VGA_8XZOOM__) && defined(ISP_SUPPORT)
    #undef CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT
	#define CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT			(80)

    #undef CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT
	#define CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT			    (80)

    #undef CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT
    #define CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT			    (80)	

    #undef CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT
    #define CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT			    (80)	

    #undef CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT
    #define CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT			(80)

    #undef CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT
    #define CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT		(80)
#endif

#ifdef __MMI_SUBLCD_CAMERA__
    #define SUBLCD_CAMERA_PREVIEW_WIDTH 	SUBLCD_WIDTH
    #define SUBLCD_CAMERA_PREVIEW_HEIGHT 	SUBLCD_HEIGHT
    #define SUBLCD_CAMERA_CAPTURE_WIDTH     (320)
    #define SUBLCD_CAMERA_CAPTURE_HEIGHT    (240)
#endif

#endif /* __MMI_CAMERA__ */
#endif /* _CAMERA_FEATURES_H_ */



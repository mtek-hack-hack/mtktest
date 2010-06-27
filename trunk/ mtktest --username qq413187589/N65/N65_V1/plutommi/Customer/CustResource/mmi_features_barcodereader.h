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
 *	 mmi_features_barcodereader.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_BARCODEREADER_FEATURES_H
#define MMI_BARCODEREADER_FEATURES_H

#include "MMI_features.h"

#ifdef __MMI_BARCODEREADER__

	#ifdef HORIZONTAL_CAMERA
		#define __MMI_HORIZONTAL_BARCODEREADER__
	#endif

    //#define __MMI_BARCODEREADER_MF_SUPPORT__
    #define __MMI_BARCODEREADER_EV_SUPPORT__

	#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))

	#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
    
	#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
        #ifndef __MMI_BARCODEREADER_OPERATOR1__
    	    #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH	176
	        #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 132
    	    #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
	        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 24
        #else
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH	LCD_WIDTH
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT (LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT)
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y (MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT)
        #endif
        
	#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
        #ifndef __MMI_BARCODEREADER_OPERATOR1__   
    	    #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH	240
	        #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 180
    	    #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
	        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 39
        #else
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH	LCD_WIDTH
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT (LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT)
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y (MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT)
        #endif
	#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
        #ifndef __MMI_BARCODEREADER_OPERATOR1__   
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH	240
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 180
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 20
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 27
        #else
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH	LCD_WIDTH
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT (LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT)
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
            #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y (MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT)
        #endif
    #endif

    #if ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
        #ifdef __MMI_HORIZONTAL_BARCODEREADER__
            #define MMI_BARCODEREADER_IMAGE_WIDTH 240
            #define MMI_BARCODEREADER_IMAGE_HEIGHT 320
        #else
            #define MMI_BARCODEREADER_IMAGE_WIDTH 320
            #define MMI_BARCODEREADER_IMAGE_HEIGHT 240
        #endif
    #else
        #ifndef __MMI_BARCODEREADER_OPERATOR1__
            #ifdef __MMI_HORIZONTAL_BARCODEREADER__
                #define MMI_BARCODEREADER_IMAGE_WIDTH 320
                #define MMI_BARCODEREADER_IMAGE_HEIGHT 240
            #else
                #define MMI_BARCODEREADER_IMAGE_WIDTH 320
                #define MMI_BARCODEREADER_IMAGE_HEIGHT 240
            #endif
        #else
            #define MMI_BARCODEREADER_IMAGE_WIDTH  242
            #define MMI_BARCODEREADER_IMAGE_HEIGHT 242    
        #endif
    #endif



	#ifdef __MMI_HORIZONTAL_BARCODEREADER__
		#define MMI_BARCODEREADER_LCM_MAINLCD_ROTATE MMI_BARCODEREADER_LCM_ROTATE_270
	#else
		#define MMI_BARCODEREADER_LCM_MAINLCD_ROTATE MMI_BARCODEREADER_LCM_ROTATE_0
	#endif

	
	#if defined(SENSOR_ON_BODY)
        #if defined(SENSOR_ROTATE_0)
	#define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #elif defined(SENSOR_ROTATE_180)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_180
        #else
            /* rotate 90, 270 not used yet */
	#define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #endif
    #elif defined(SENSOR_ON_COVER)
        #if defined(SENSOR_ROTATE_0)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #elif defined(SENSOR_ROTATE_180)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_180
        #else
            /* rotate 90, 270 not used yet */
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #endif
    #else /* not define SENSOR_LCATION */
        #if defined(SENSOR_ROTATE_0)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #elif defined(SENSOR_ROTATE_180)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_180
        #else
            /* rotate 90, 270 not used yet */
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #endif				
    #endif /* SENSOR_LOCATION */

	
	/****************************************************************************
	* Device Feature Customization 
	*****************************************************************************/

	#ifdef __MMI_TOUCH_SCREEN__
		#define __MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__
	#endif 

	#ifdef AF_SUPPORT
		#define __MMI_BARCODEREADER_AF_SUPPORT__
	#endif

	/****************************************************************************
	* Camera Feature Customization 
	*****************************************************************************/
	#define __MMI_BARCODEREADER_EV_2__
	#define __MMI_BARCODEREADER_EV_3__
	#define __MMI_BARCODEREADER_EV_4__


	#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
		#define __MMI_BARCODEREADER_FOCUS_MODE__ /* auto is default */
	
		#define __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
		    //#define __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        #endif

		#define MMI_BARCODEREADER_AF_POSITION_1_X							(LCD_WIDTH/2)
    	#define MMI_BARCODEREADER_AF_POSITION_1_Y							(MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y+MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT/2)
   	    #define MMI_BARCODEREADER_AF_POSITION_2_X							(0)
		#define MMI_BARCODEREADER_AF_POSITION_2_Y							(0)
		#define MMI_BARCODEREADER_AF_POSITION_3_X							(0)
		#define MMI_BARCODEREADER_AF_POSITION_3_Y							(0)
		#define MMI_BARCODEREADER_AF_POSITION_4_X							(0)
		#define MMI_BARCODEREADER_AF_POSITION_4_Y							(0)
		#define MMI_BARCODEREADER_AF_POSITION_5_X							(0)
		#define MMI_BARCODEREADER_AF_POSITION_5_Y							(0)
	#endif 

	#if defined(LED_ONOFF_SUPPORT) || defined(LED_FLASHLIGHT_SUPPORT)
	    #define __MMI_BARCODEREADER_FLASH__	
    #endif
    	
	#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
    	#define __MMI_BARCODEREADER_STORAGE__
    #endif
    #define __MMI_BARCODEREADER_BANDING__
	/****************************************************************************
	* Default Setting
	*****************************************************************************/
	#define MMI_BARCODEREADER_DEFAULT_SETTING_EV MMI_BARCODEREADER_SETTING_EV_0	
	#define MMI_BARCODEREADER_DEFAULT_SETTING_FOCUS_MODE MMI_BARCODEREADER_SETTING_FOCUS_MODE_AUTO
	#define MMI_BARCODEREADER_DEFAULT_SETTING_FLASH 	MMI_BARCODEREADER_SETTING_FLASH_OFF
    #define MMI_BARCODEREADER_DEFAULT_SETTING_BANDING   MMI_BARCODEREADER_SETTING_BANDING_50HZ


	/****************************************************************************
	* Key Map Setting
	*****************************************************************************/
	#define MMI_BARCODEREADER_FOCUS_MODE_KEY		(KEY_1)
	#define MMI_BARCODEREADER_FLASH_KEY				(KEY_2)
	#define MMI_BARCODEREADER_STORAGE_KEY			(KEY_3)
	#define MMI_BARCODEREADER_CAPTURE_EXTRA_KEY	    (KEY_IP)
	#define MMI_BARCODEREADER_CAPTURE_KEY			(KEY_CAMERA)


#endif /* __MMI_MMI_BARCODEREADER__ */
#endif /* _MMI_BARCODEREADER_FEATRUES_H_ */

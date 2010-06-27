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

/*******************************************************************************
* Filename:
* ---------
*	resource_fmradio_skins.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM radio main screen skin settings
*
* Author:
* -------
*	Tim Chen
*
*==============================================================================
* 				HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#include "gdi_lcd_config.h"

// dependent headers for FMRadioDef.h"
#include "PixtelDataTypes.h"
#include "gui_data_types.h"

#include "nvram_user_defs.h"
#include "FMRadioDef.h"
#include "FMRadioType.h"

#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) )
const mmi_fmrdo_skin_struct g_fmrdo_skins[] =
{
	{ // skin 1
		0, 0, 0, // LSK text border color
		255, 0, 255, // LSK text color
		0, 0, 0, // RSK text border color
		255, 0, 255, // RSK text color
		IMG_ID_FMRDO_SKIN_1_BACKGROUND, // background image
		255, 255, 255, // channel name text border color
		100, 100, 100, // channel name text color
		2, 2, // channel name x, y
		124, 20, // channel name w, h
		0, 255, 0, // frequency text on color
		0, 150, 0, // frequency text off color
		35, 35, // frequency x, y
		58, 12, // frequency w, h
		IMG_ID_FMRDO_SKIN_1_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		46, 49, // x, y
		7, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		20, 61, // tuner scale x, y
		0, // tuner scale ind offset
		1, 0, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN, // step down button down image
		28, 70, // step down button x, y
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN, // step up button down image
		89, 70, // step up button x, y
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		42, 77, // search button x, y
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN, // power button off down image
		56, 91, // power button x, y
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#ifndef __MMI_FM_SLIM_SKIN__
	, 
	{ // skin 2
		0, 0, 0, // LSK text border color
		255, 0, 255, // LSK text color
		0, 0, 0, // RSK text border color
		0, 255, 255, // RSK text color
		IMG_ID_FMRDO_SKIN_2_BACKGROUND, // background image
		255, 255, 255, // channel name text border color
		100, 100, 100, // channel name text color
		2, 2, // channel name x, y
		124, 20, // channel name w, h
		0, 255, 0, // frequency text on color
		0, 150, 0, // frequency text off color
		35, 35, // frequency x, y
		58, 12, // frequency w, h
		IMG_ID_FMRDO_SKIN_2_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		46, 49, // x, y
		7, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		20, 61, // tuner scale x, y
		0, // tuner scale ind offset
		1, 0, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_DOWN, // step down button down image
		28, 70, // step down button x, y
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_DOWN, // step up button down image
		89, 70, // step up button x, y
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		42, 77, // search button x, y
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_DOWN, // power button off down image
		56, 91, // power button x, y
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	} ,
	{ // skin 3
		0, 0, 0, // LSK text border color
		255, 0, 255, // LSK text color
		0, 0, 0, // RSK text border color
		0, 255, 255, // RSK text color
		IMG_ID_FMRDO_SKIN_3_BACKGROUND, // background image
		255, 255, 255, // channel name text border color
		100, 100, 100, // channel name text color
		2, 2, // channel name x, y
		124, 20, // channel name w, h
		0, 255, 0, // frequency text on color
		0, 150, 0, // frequency text off color
		35, 35, // frequency x, y
		58, 12, // frequency w, h
		IMG_ID_FMRDO_SKIN_3_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		46, 49, // x, y
		7, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		20, 61, // tuner scale x, y
		0, // tuner scale ind offset
		1, 0, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_DOWN, // step down button down image
		28, 70, // step down button x, y
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_DOWN, // step up button down image
		89, 70, // step up button x, y
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		42, 77, // search button x, y
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_DOWN, // power button off down image
		56, 91, // power button x, y
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#endif /* #ifndef __MMI_FM_SLIM_SKIN__ */	
};
#elif ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
#ifdef __MMI_TOUCH_SCREEN__
static const fmrdo_point_struct skin1_volume_inc_points[] = {{0,0},{12,0},{12,15},{12,15}};
static const fmrdo_point_struct skin1_volume_dec_points[] = {{0,0},{12,0},{12,15},{0,15}};
static const fmrdo_point_struct skin1_step_down_button_points[] = {{0,0},{14,0},{14,19},{0,19}};
static const fmrdo_point_struct skin1_step_up_button_points[] = {{0,0},{14,0},{14,19},{0,19}};
static const fmrdo_point_struct skin1_power_button_points[] = {{0,0},{21,0},{21,16},{0,16}};
static const fmrdo_point_struct skin1_search_button_points[] = {{0,0},{21,0},{21,15},{0,15},{1,20}};
static const fmrdo_point_struct skin1_setting_points[] = {{0,0},{16,0},{16,14},{0,14}};
static const fmrdo_point_struct skin1_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};

#ifndef __MMI_FM_SLIM_SKIN__
static const fmrdo_point_struct skin2_volume_inc_points[] = {{0,0},{9,0},{9,12},{0,12}};
static const fmrdo_point_struct skin2_volume_dec_points[] = {{0,0},{9,0},{9,12},{0,12}};
static const fmrdo_point_struct skin2_step_down_button_points[] = {{1,2},{22,2},{22,20},{1,20}};
static const fmrdo_point_struct skin2_step_up_button_points[] = {{0,2},{22,2},{22,20},{0,20}};
static const fmrdo_point_struct skin2_power_button_points[] = {{2,2},{25,2},{25,20},{2,20}};
static const fmrdo_point_struct skin2_search_button_points[] = {{0,3},{23,3},{23,20},{0,20}};
static const fmrdo_point_struct skin2_setting_points[] = {{1,1},{16,1},{16,14},{1,14}};
static const fmrdo_point_struct skin2_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};

static const fmrdo_point_struct skin3_volume_inc_points[] = {{0,0},{10,0},{10,10},{0,10}};
static const fmrdo_point_struct skin3_volume_dec_points[] = {{0,0},{10,0},{10,10},{0,10}};
static const fmrdo_point_struct skin3_step_down_button_points[] = {{0,0},{17,0},{17,15},{0,15}};
static const fmrdo_point_struct skin3_step_up_button_points[] = {{0,0},{17,0},{17,15},{0,15}};
static const fmrdo_point_struct skin3_power_button_points[] = {{0,0},{17,0},{17,15},{0,15}};
static const fmrdo_point_struct skin3_search_button_points[] = {{0,0},{16,0},{16,15},{0,15}};
static const fmrdo_point_struct skin3_setting_points[] = {{0,0},{16,0},{16,12},{0,12}};
static const fmrdo_point_struct skin3_frequency_points[] = {{0,0},{70,0},{70,12},{0,12}};
#endif /* #ifndef __MMI_FM_SLIM_SKIN__ */
#endif /* #ifdef __MMI_TOUCH_SCREEN__ */
const mmi_fmrdo_skin_struct g_fmrdo_skins[] =
{
	{ // skin 1
 		255,255,0, // LSK Border color
 		0,0,100, // LSK Text color
 		255,255,0, // RSK Border color
 		0,0,100, // RSK Text color
		IMG_ID_FMRDO_SKIN_1_BACKGROUND,  // background image
 		255,255,0, // CHANNEL_NAME Background color
 		0,0,100, // CHANNEL_NAME Text color
		2,2, //CHANNEL_NAME x, y
		124,20, //CHANNEL_NAME w, h
 		255,255,0, // FREQUENCY Text On color
 		0,0,100, // FREQUENCY Text Off color
		41,82, //FREQUENCY x, y
		53,14, //FREQUENCY w, h
		IMG_ID_FMRDO_SKIN_1_VOLUME,//VOLUME Image
		0,//VOLUME_BAR Scale Type-> 0: horizontal, 1: vertical
		87,125, //VOLUME_BAR x,y
		2,0,//VOLUME_BAR indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE,//TUNER_SCALE Image
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR,  //TUNER_SCALE_INDICATOR Image
		0,//TUNER_SCALE Scale Type-> 0: horizontal, 1: vertical
		17,50, //TUNER_SCALE x,y
		0,//ind offset. set to 0 for D15.Georgezhou 208.7.31
		0,1,//TUNER_SCALE start gap, end gap. set to 0,1 for D15.Georgezhou 2008.7.31
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP,//STEP_DOWN_BUTTON_UP Image
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN,//STEP_DOWN_BUTTON_DOWN Image
		9,108, //STEP_DOWN_BUTTON x,y
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP,//STEP_UP_BUTTON_UP Image
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN,//STEP_UP_BUTTON_DOWN Image
		65,108, //STEP_UP_BUTTON x,y
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP,//SEARCH_BUTTON_ON_UP Image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN,//SEARCH_BUTTON_ON_DOWN Image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP,//SEARCH_BUTTON_OFF_UP Image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN,//SEARCH_BUTTON_OFF_DOWN Image
		93,108, //SEARCH_BUTTON x,y
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP,//POWER_BUTTON_ON_UP Image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN,//POWER_BUTTON_ON_DOWN Image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP,//POWER_BUTTON_OFF_UP Image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN,//POWER_BUTTON_OFF_DOWN Image
		37,108, //POWER_BUTTON x,y
#ifdef __MMI_FM_RADIO_ANIMATION__
		37,118,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_1_ANIMATION,// animation backgroup image
#endif
#ifdef __MMI_TOUCH_SCREEN__
		106,125,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN,// volume_inc_down_image_id
		73,125,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		9,124,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_1_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_1_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin1_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin1_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin1_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin1_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin1_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin1_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_1_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_1_REC_PAUSE,	//record pause indication icon image
		109,99,	// record icon x, y
		IMG_ID_FMRDO_SKIN_1_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_1_NUM_COL, // record duration seperator icon
		67,103,	// recprd duration icon x, y
#endif		
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#ifndef __MMI_FM_SLIM_SKIN__	
	, 
	{ // skin 2
		0, 0, 0, // LSK text border color
		255, 0, 255, // LSK text color
		0, 0, 0, // RSK text border color
		255, 0, 255, // RSK text color
		IMG_ID_FMRDO_SKIN_2_BACKGROUND, // background image
		0, 0, 0, // channel name text border color
		70, 250, 205, // channel name text color
		0, 2, // channel name x, y
		124, 26, // channel name w, h
		255, 255, 255, // frequency text on color
		150, 150, 150, // frequency text off color
		25, 33, // frequency x, y
		70, 15, // frequency w, h
		IMG_ID_FMRDO_SKIN_2_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		18, 103, // volume bar x, y
		7, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		18, 58, // tuner scale x, y
		9, // tuner scale ind offset
		0, 0, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_DOWN, // step down button down image
		68, 116, // step down button x, y
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_DOWN, // step up button down image
		91, 116, // step up button x, y
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		40, 116, // search button x, y
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_DOWN, // power button off down image
		15, 116, // power button x, y
#ifdef __MMI_FM_RADIO_ANIMATION__
		40,112,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_2_ANIMATION,// animation backgroup image
#endif
#ifdef __MMI_TOUCH_SCREEN__
		49,102,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_2_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_2_VOLUME_INC_DOWN,// volume_inc_down_image_id
		6,102,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		105,83,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_2_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_2_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin2_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin2_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin2_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin2_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin2_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin2_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin2_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin2_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_2_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_2_REC_PAUSE,	//record pause indication icon image
		107,100,	// record icon x, y
		IMG_ID_FMRDO_SKIN_2_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_2_NUM_COL, // record duration seperator icon
		65,104,	// recprd duration icon x, y
#endif			
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	} ,
	{ // skin 3
		255, 255, 255, // LSK text border color
		213, 116, 146, // LSK text color
		255, 255, 255, // RSK text border color
		213, 116, 146, // RSK text color
		IMG_ID_FMRDO_SKIN_3_BACKGROUND, // background image
		90, 90, 90, // channel name text border color
		255, 255, 255, // channel name text color
		0, 2, // channel name x, y
		124, 26, // channel name w, h
		0, 0, 204, // frequency text on color
		150, 150, 150, // frequency text off color
		25, 34, // frequency x, y
		70, 15, // frequency w, h
		IMG_ID_FMRDO_SKIN_3_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		19, 95, // x, y
		7, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		11, 51, // tuner scale x, y
		9, // tuner scale ind offset
		1, 8, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_DOWN, // step down button down image
		69, 111, // step down button x, y
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_DOWN, // step up button down image
		92, 111, // step up button x, y
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		47, 111, // search button x, y
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_DOWN, // power button off down image
		24, 111, // power button x, y
#ifdef __MMI_FM_RADIO_ANIMATION__
		0,61,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_3_ANIMATION,// animation backgroup image
#endif		
#ifdef __MMI_TOUCH_SCREEN__
		48,95,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		8,95,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		107,81,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_3_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_3_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin3_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin3_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin3_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin3_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin3_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin3_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin3_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin3_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_3_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_3_REC_PAUSE,	//record pause indication icon image
		107,94,	// record icon x, y
		IMG_ID_FMRDO_SKIN_3_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_3_NUM_COL, // record duration seperator icon
		65,96,	// recprd duration icon x, y
#endif		
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#endif /* #ifndef __MMI_FM_SLIM_SKIN__ */	
};
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#ifdef __MMI_TOUCH_SCREEN__
static const fmrdo_point_struct skin1_volume_inc_points[] = {{1,1},{10,1},{10,10},{1,10}};
static const fmrdo_point_struct skin1_volume_dec_points[] = {{1,1},{10,1},{10,10},{1,10}};
static const fmrdo_point_struct skin1_step_down_button_points[] = {{1,1},{14,1},{14,14},{1,14}};
static const fmrdo_point_struct skin1_step_up_button_points[] = {{1,1},{11,1},{11,12},{1,12}};
static const fmrdo_point_struct skin1_power_button_points[] = {{1,1},{16,1},{16,16},{1,16}};
static const fmrdo_point_struct skin1_search_button_points[] = {{1,1},{45,1},{45,14},{1,14}};
static const fmrdo_point_struct skin1_setting_points[] = {{1,1},{29,1},{29,29},{1,29}};
static const fmrdo_point_struct skin_1_tuner_scale_points[] = {{1,1},{118,1},{118,37},{1,37}};//TUNER_SCALE
//static const fmrdo_point_struct skin1_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};

#ifndef __MMI_FM_SLIM_SKIN__
static const fmrdo_point_struct skin2_volume_inc_points[] = {{0,0},{25,0},{25,13},{0,13}};
static const fmrdo_point_struct skin2_volume_dec_points[] = {{0,0},{25,0},{25,13},{0,13}};
static const fmrdo_point_struct skin2_step_down_button_points[] = {{0,0},{25,0},{25,28},{0,28}};
static const fmrdo_point_struct skin2_step_up_button_points[] = {{0,0},{25,0},{25,28},{0,28}};
static const fmrdo_point_struct skin2_power_button_points[] = {{0,0},{25,0},{25,28},{0,28}};
static const fmrdo_point_struct skin2_search_button_points[] = {{0,0},{25,0},{25,28},{0,28}};
static const fmrdo_point_struct skin2_setting_points[] = {{0,0},{25,0},{25,28},{0,28}};
static const fmrdo_point_struct skin2_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};

static const fmrdo_point_struct skin3_volume_inc_points[] = {{1,0},{24,0},{24,11},{1,11}};
static const fmrdo_point_struct skin3_volume_dec_points[] = {{1,0},{24,0},{24,11},{1,11}};
static const fmrdo_point_struct skin3_step_down_button_points[] = {{0,0},{34,0},{34,34},{0,34}};
static const fmrdo_point_struct skin3_step_up_button_points[] = {{0,0},{34,0},{34,34},{0,34}};
static const fmrdo_point_struct skin3_power_button_points[] = {{0,0},{34,0},{34,34},{0,34}};
static const fmrdo_point_struct skin3_search_button_points[] = {{0,0},{34,0},{34,34},{0,34}};
static const fmrdo_point_struct skin3_setting_points[] = {{0,0},{34,0},{34,34},{0,34}};
static const fmrdo_point_struct skin3_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};
#endif /*#ifndef __MMI_FM_SLIM_SKIN__*/
#endif /*#ifdef __MMI_TOUCH_SCREEN__*/
const mmi_fmrdo_skin_struct g_fmrdo_skins[] =
{
	{ // skin 1
		255, 255, 0, // LSK text border color
		0, 0, 100, // LSK text color
		255, 255, 0, // RSK text border color
		0, 0, 100, // RSK text color
		IMG_ID_FMRDO_SKIN_1_BACKGROUND, // background image
		255, 255, 0, // channel name text border color
		0, 0, 100, // channel name text color
		29, 2, // channel name x, y
		124, 20, // channel name w, h
		255, 255, 0, // frequency text on color
		0, 0, 100, // frequency text off color
		61, 33, // frequency x, y
		58, 12, // frequency w, h
		IMG_ID_FMRDO_SKIN_1_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		79, 187, // volume bar x, y
		7, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		29, 87, // tuner scale x, y
		-10, // tuner scale ind offset
		19, 29, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN, // step down button down image
		56, 166, // step down button x, y
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN, // step up button down image
		113, 166, // step up button x, y
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		66, 48, // search button x, y
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN, // power button off down image
		83,165,   //136, 123,   edit by lijianxin 080716  // power button x, y
#ifdef __MMI_FM_RADIO_ANIMATION__   /*add by lijianxin 080716*/
		37,63,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_1_ANIMATION,// animation backgroup image
#endif
#ifdef __MMI_TOUCH_SCREEN__
		110,187,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN,// volume_inc_down_image_id
		64,187,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		21,165,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_1_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_1_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin1_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin1_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin1_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin1_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin1_setting_points, 4}, // setting_area
              {(const fmrdo_point_struct *)skin_1_tuner_scale_points, 4},
		//{(const fmrdo_point_struct *)skin1_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_1_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_1_REC_PAUSE,	//record pause indication icon image
		137,174,	// record icon x, y
		IMG_ID_FMRDO_SKIN_1_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_1_NUM_COL, // record duration seperator icon
		22,101,	// recprd duration icon x, y
#endif		
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#ifndef __MMI_FM_SLIM_SKIN__	
	, 
	{ // skin 2
		0, 0, 0, // LSK text border color
		255, 0, 255, // LSK text color
		0, 0, 0, // RSK text border color
		255, 0, 255, // RSK text color
		IMG_ID_FMRDO_SKIN_2_BACKGROUND, // background image
		0, 0, 0, // channel name text border color
		70, 250, 205, // channel name text color
		2, 2, // channel name x, y
		172, 20, // channel name w, h
		20, 81, 37, // frequency text on color
		150, 150, 150, // frequency text off color
		56, 56, // frequency x, y
		70, 12, // frequency w, h
		IMG_ID_FMRDO_SKIN_2_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		37, 114, // volume bar x, y
		9, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		29, 78, // tuner scale x, y
		7, // tuner scale ind offset
		0, 0, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_DOWN, // step down button down image
		46, 159, // step down button x, y
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_DOWN, // step up button down image
		72, 159, // step up button x, y
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		100, 159, // search button x, y
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_DOWN, // power button off down image
		129, 159, // power button x, y
#ifdef __MMI_TOUCH_SCREEN__
		58,131,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_2_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_2_VOLUME_INC_DOWN,// volume_inc_down_image_id
		29,131,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		24,159,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_2_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_2_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin2_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin2_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin2_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin2_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin2_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin2_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin2_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin2_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_2_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_2_REC_PAUSE,	//record pause indication icon image
		99,131,	// record icon x, y
		IMG_ID_FMRDO_SKIN_2_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_2_NUM_COL, // record duration seperator icon
		96,113,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	} ,
	{ // skin 3
		255, 255, 255, // LSK text border color
		213, 116, 146, // LSK text color
		255, 255, 255, // RSK text border color
		213, 116, 146, // RSK text color
		IMG_ID_FMRDO_SKIN_3_BACKGROUND, // background image
		90, 90, 90, // channel name text border color
		255, 255, 255, // channel name text color
		41, 10, // channel name x, y
		93, 20, // channel name w, h
		12, 52, 18, // frequency text on color
		150, 150, 150, // frequency text off color
		58, 51, // frequency x, y
		70, 12, // frequency w, h
		IMG_ID_FMRDO_SKIN_3_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		129, 109, // x, y
		9, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		26, 66, // tuner scale x, y
		5, // tuner scale ind offset
		0, 0, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_DOWN, // step down button down image
		34, 142, // step down button x, y
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_DOWN, // step up button down image
		105, 142, // step up button x, y
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		70, 130, // search button x, y
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_DOWN, // power button off down image
		70, 163, // power button x, y
#ifdef __MMI_TOUCH_SCREEN__
		96,100,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		95,114,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		6,163,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_3_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_3_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin3_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin3_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin3_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin3_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin3_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin3_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin3_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin3_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_3_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_3_REC_PAUSE,	//record pause indication icon image
		6,100,	// record icon x, y
		IMG_ID_FMRDO_SKIN_3_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_3_NUM_COL, // record duration seperator icon
		45,108,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#endif /* #ifndef __MMI_FM_SLIM_SKIN__ */	
};
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#ifdef __MMI_TOUCH_SCREEN__
static const fmrdo_point_struct skin1_volume_inc_points[] = {{1,0},{16,0},{16,18},{1,18}};
static const fmrdo_point_struct skin1_volume_dec_points[] = {{0,0},{15,0},{15,18},{0,18}};
static const fmrdo_point_struct skin1_step_down_button_points[] = {{0,0},{28,0},{28,25},{0,25}};
static const fmrdo_point_struct skin1_step_up_button_points[] = {{0,0},{28,0},{28,25},{0,25}};
static const fmrdo_point_struct skin1_power_button_points[] = {{2,1},{30,1},{30,27},{2,27}};
static const fmrdo_point_struct skin1_search_button_points[] = {{1,1},{66,1},{66,26},{1,26}};
static const fmrdo_point_struct skin1_setting_points[] = {{1,1},{25,1},{25,27},{1,27}};
static const fmrdo_point_struct skin1_frequency_points[] = {{0,0},{146,0},{146,11},{0,11}};

#ifndef __MMI_FM_SLIM_SKIN__
static const fmrdo_point_struct skin2_volume_inc_points[] = {{1,0},{12,0},{12,18},{1,18}};
static const fmrdo_point_struct skin2_volume_dec_points[] = {{0,0},{11,0},{11,18},{0,18}};
static const fmrdo_point_struct skin2_step_down_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_step_up_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_power_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_search_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_setting_points[] = {{1,1},{25,1},{25,27},{1,27}};
static const fmrdo_point_struct skin2_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};

static const fmrdo_point_struct skin3_volume_inc_points[] = {{1,0},{12,0},{12,18},{1,18}};
static const fmrdo_point_struct skin3_volume_dec_points[] = {{0,0},{11,0},{11,18},{0,18}};
static const fmrdo_point_struct skin3_step_down_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_step_up_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_power_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_search_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_setting_points[] = {{1,1},{25,1},{25,27},{1,27}};
static const fmrdo_point_struct skin3_frequency_points[] = {{0,0},{70,0},{70,12},{0,12}};
#endif /* #ifndef __MMI_FM_SLIM_SKIN__ */
#endif /* #ifdef __MMI_TOUCH_SCREEN__ */
const mmi_fmrdo_skin_struct g_fmrdo_skins[] =
{
	{ // skin 1
		0, 0, 0, // LSK text border color
		255,255,255, // LSK text color
		0, 0, 0, // RSK text border color
		255,255,255, // RSK text color
		IMG_ID_FMRDO_SKIN_1_BACKGROUND, // background image
		0, 0, 0, // channel name text border color
		250, 250,250, // channel name text color
		20, 3, // channel name x, y
		200, 26, // channel name w, h
		150,150,150, // frequency text on color
		159, 159, 159, // frequency text off color
		130, 140, // frequency x, y
		80, 15, // frequency w, h
		IMG_ID_FMRDO_SKIN_1_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		57, 246, // volume bar x, y
		0, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		63, 205, // tuner scale x, y
		18, // tuner scale ind offset
		0, 0, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN, // step down button down image
		8, 208, // step down button x, y
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN, // step up button down image
		208, 208, // step up button x, y
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		135, 242, // search button x, y
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN, // power button off down image
		97, 289, // power button x, y
#ifdef __MMI_FM_RADIO_ANIMATION__
		123,93,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_1_ANIMATION,// animation backgroup image
#endif
#ifdef __MMI_TOUCH_SCREEN__
		92,242,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN,// volume_inc_down_image_id
		3,242,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		205,242,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_1_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_1_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin1_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin1_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin1_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin1_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin1_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin1_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_1_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_1_REC_PAUSE,	//record pause indication icon image
		176,63,	// record icon x, y
		IMG_ID_FMRDO_SKIN_1_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_1_NUM_COL, // record duration seperator icon
		126,67,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}   //sk 0810
#ifndef __MMI_FM_SLIM_SKIN__	
	, 
	{ // skin 2
		0, 0, 0, // LSK text border color
		255, 0, 255, // LSK text color
		0, 0, 0, // RSK text border color
		255, 0, 255, // RSK text color
		IMG_ID_FMRDO_SKIN_2_BACKGROUND, // background image
		0, 0, 0, // channel name text border color
		70, 250, 205, // channel name text color
		20, 2, // channel name x, y
		200, 26, // channel name w, h
		255, 255, 255, // frequency text on color
		150, 150, 150, // frequency text off color
		80, 120, // frequency x, y
		80, 15, // frequency w, h
		IMG_ID_FMRDO_SKIN_2_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		67, 196, // volume bar x, y
		9, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_2_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		40, 47, // tuner scale x, y
		35, // tuner scale ind offset
		11, 14, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_DOWN, // step down button down image
		134, 230, // step down button x, y
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_DOWN, // step up button down image
		169, 230, // step up button x, y
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		97, 230, // search button x, y
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_DOWN, // power button off down image
		61, 230, // power button x, y
#ifdef __MMI_FM_RADIO_ANIMATION__
		40,112,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_2_ANIMATION,// animation backgroup image
#endif
#ifdef __MMI_TOUCH_SCREEN__
		100,194,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_2_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_2_VOLUME_INC_DOWN,// volume_inc_down_image_id
		48,194,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		35,234,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_2_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_2_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin2_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin2_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin2_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin2_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin2_power_button_points, 4}, // power_button_area
		{(const fmrdo_point_struct *)skin2_search_button_points, 4}, // search_button_area
		{(const fmrdo_point_struct *)skin2_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin2_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_2_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_2_REC_PAUSE,	//record pause indication icon image
		177,193,	// record icon x, y
		IMG_ID_FMRDO_SKIN_2_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_2_NUM_COL, // record duration seperator icon
		127,198,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	} ,
	{ // skin 3
		255, 255, 255, // LSK text border color
		213, 116, 146, // LSK text color
		255, 255, 255, // RSK text border color
		213, 116, 146, // RSK text color
		IMG_ID_FMRDO_SKIN_3_BACKGROUND, // background image
		90, 90, 90, // channel name text border color
		255, 255, 255, // channel name text color
		20, 26, // channel name x, y
		200, 26, // channel name w, h
		255, 255, 255, // frequency text on color
		150, 150, 150, // frequency text off color
		80, 62, // frequency x, y
		80, 15, // frequency w, h
		IMG_ID_FMRDO_SKIN_3_VOLUME, // volume image
		0, // volume bar type -> 0: horizontal, 1: vertical
		172, 205, // x, y
		9, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_3_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		51, 123, // tuner scale x, y
		32, // tuner scale ind offset
		6, 6, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_DOWN, // step down button down image
		45, 234, // step down button x, y
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_DOWN, // step up button down image
		92, 234, // step up button x, y
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		92, 191, // search button x, y
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_DOWN, // power button off down image
		45, 191, // power button x, y
#ifdef __MMI_FM_RADIO_ANIMATION__
		0,61,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_3_ANIMATION,// animation backgroup image
#endif		
#ifdef __MMI_TOUCH_SCREEN__
		213,201,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		146,201,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		9,191,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_3_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_3_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin3_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin3_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin3_step_down_button_points, 8}, // step_down_button_area
		{(const fmrdo_point_struct *)skin3_step_up_button_points, 8}, // step_up_button_area
		{(const fmrdo_point_struct *)skin3_power_button_points, 8}, // power_button_area
		{(const fmrdo_point_struct *)skin3_search_button_points, 8}, // search_button_area
		{(const fmrdo_point_struct *)skin3_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin3_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_3_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_3_REC_PAUSE,	//record pause indication icon image
		205,242,	// record icon x, y
		IMG_ID_FMRDO_SKIN_3_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_3_NUM_COL, // record duration seperator icon
		155,253,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#endif /*#ifndef __MMI_FM_SLIM_SKIN__*/	
};

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#ifdef __MMI_TOUCH_SCREEN__
static const fmrdo_point_struct skin1_volume_inc_points[] = {{3,3},{23,3},{23,23},{3,23}};
static const fmrdo_point_struct skin1_volume_dec_points[] = {{3,3},{23,3},{23,23},{3,23}};
static const fmrdo_point_struct skin1_step_down_button_points[] = {{0,0},{25,0},{25,22},{0,22}};
static const fmrdo_point_struct skin1_step_up_button_points[] = {{0,0},{25,0},{25,22},{0,22}};
static const fmrdo_point_struct skin1_power_button_points[] = {{4,4},{28,4},{28,25},{4,25}};
static const fmrdo_point_struct skin1_search_button_points[] = {{0,4},{30,4},{30,29},{0,29}};
static const fmrdo_point_struct skin1_setting_points[] = {{4,4},{30,4},{30,30},{4,30}};
static const fmrdo_point_struct skin1_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};

#ifndef __MMI_FM_SLIM_SKIN__
static const fmrdo_point_struct skin2_volume_inc_points[] = {{1,0},{12,0},{12,18},{1,18}};
static const fmrdo_point_struct skin2_volume_dec_points[] = {{0,0},{11,0},{11,18},{0,18}};
static const fmrdo_point_struct skin2_step_down_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_step_up_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_power_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_search_button_points[] = {{5,4},{32,4},{32,60},{5,50}};
static const fmrdo_point_struct skin2_setting_points[] = {{1,1},{25,1},{25,27},{1,27}};
static const fmrdo_point_struct skin2_frequency_points[] = {{0,0},{69,0},{69,11},{0,11}};

static const fmrdo_point_struct skin3_volume_inc_points[] = {{1,0},{12,0},{12,18},{1,18}};
static const fmrdo_point_struct skin3_volume_dec_points[] = {{0,0},{11,0},{11,18},{0,18}};
static const fmrdo_point_struct skin3_step_down_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_step_up_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_power_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_search_button_points[] = {{12,7},{38,7},{43,12},{43,36},{38,41},{12,41},{7,36},{7,12}};
static const fmrdo_point_struct skin3_setting_points[] = {{1,1},{25,1},{25,27},{1,27}};
static const fmrdo_point_struct skin3_frequency_points[] = {{0,0},{70,0},{70,12},{0,12}};
#endif /* #ifndef __MMI_FM_SLIM_SKIN__ */
#endif /* #ifdef __MMI_TOUCH_SCREEN__ */
const mmi_fmrdo_skin_struct g_fmrdo_skins[] =
{
	{ // skin 1
		0, 0, 0, // LSK text border color
		255, 255, 255, // LSK text color
		0, 0, 0, // RSK text border color
		255, 255, 255, // RSK text color
		IMG_ID_FMRDO_SKIN_1_BACKGROUND, // background image
		0, 0, 0, // channel name text border color
		255, 255, 255, // channel name text color
		60, 2, // channel name x, y
		200, 26, // channel name w, h
		125, 197, 7, // frequency text on color
		150, 150, 150, // frequency text off color
		82, 50, // frequency x, y
		90, 20, // frequency w, h
		IMG_ID_FMRDO_SKIN_1_VOLUME, // volume image
		1, // volume bar type -> 0: horizontal, 1: vertical
		229, 45, // volume bar x, y
		0, 0, // volume indicator start gap, end gap
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE, // tuner scale background image
		IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR, // tuner scale indicator image
		0, // tuner scale type -> // 0: horizontal, 1: vertical
		30, 75, // tuner scale x, y
		-3, // tuner scale ind offset
		4, 9, // tuner scale start gap, end gap
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP, // step down button up image
		IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN, // step down button down image
		235, 143, // step down button x, y
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP, // step up button up image
		IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN, // step up button down image
		280, 142, // step up button x, y
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP, // search button on up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN, // search button on down image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP, // search button off up image
		IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN, // search button off down image
		255, 112, // search button x, y
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP, // power button on up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN, // power button on down image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP, // power button off up image
		IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN, // power button off down image
		255, 163, // power button x, y
//#ifdef __MMI_FM_RADIO_ANIMATION__
		25,125,// animation backgroup x, y
		IMG_ID_FMRDO_SKIN_1_ANIMATION,// animation backgroup image
//#endif
#ifdef __MMI_TOUCH_SCREEN__
		275,42,// volume_inc_x, volume_inc_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN,// volume_inc_down_image_id
		275,74,// volume_dec_x, volume_dec_y,
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		57,151,// setting_x, setting_y
		IMG_ID_FMRDO_SKIN_1_SETTING_UP, // setting_up_image_id
		IMG_ID_FMRDO_SKIN_1_SETTING_DOWN, // setting_down_image_id
		{(const fmrdo_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
		{(const fmrdo_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
		{(const fmrdo_point_struct *)skin1_step_down_button_points, 4}, // step_down_button_area
		{(const fmrdo_point_struct *)skin1_step_up_button_points, 4}, // step_up_button_area
		{(const fmrdo_point_struct *)skin1_power_button_points, 6}, // power_button_area
		{(const fmrdo_point_struct *)skin1_search_button_points, 5}, // search_button_area
		{(const fmrdo_point_struct *)skin1_setting_points, 4}, // setting_area
		{(const fmrdo_point_struct *)skin1_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
		IMG_ID_FMRDO_SKIN_1_REC,	// record indication icon image
		IMG_ID_FMRDO_SKIN_1_REC_PAUSE,	//record pause indication icon image
		154,152,	// record icon x, y
		IMG_ID_FMRDO_SKIN_1_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
		IMG_ID_FMRDO_SKIN_1_NUM_COL, // record duration seperator icon
		100,160,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#ifndef __MMI_FM_SLIM_SKIN__	
	, 
	{ // skin 2
        0, 0, 0, // LSK text border color
        255, 255, 255, // LSK text color
        0, 0, 0, // RSK text border color
        255, 255, 255, // RSK text color
        IMG_ID_FMRDO_SKIN_1_BACKGROUND, // background image
        0, 0, 0, // channel name text border color
        255, 255, 255, // channel name text color
        60, 2, // channel name x, y
        200, 26, // channel name w, h
        125, 197, 7, // frequency text on color
        150, 150, 150, // frequency text off color
        85, 50, // frequency x, y
        90, 20, // frequency w, h
        IMG_ID_FMRDO_SKIN_1_VOLUME, // volume image
        1, // volume bar type -> 0: horizontal, 1: vertical
        229, 45, // volume bar x, y
        0, 0, // volume indicator start gap, end gap
        IMG_ID_FMRDO_SKIN_1_TUNER_SCALE, // tuner scale background image
        IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR, // tuner scale indicator image
        0, // tuner scale type -> // 0: horizontal, 1: vertical
        30, 75, // tuner scale x, y
        -3, // tuner scale ind offset
        4, 9, // tuner scale start gap, end gap
        IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP, // step down button up image
        IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN, // step down button down image
        235, 143, // step down button x, y
        IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP, // step up button up image
        IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN, // step up button down image
        280, 142, // step up button x, y
        IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP, // search button on up image
        IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN, // search button on down image
        IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP, // search button off up image
        IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN, // search button off down image
        255, 112, // search button x, y
        IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP, // power button on up image
        IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN, // power button on down image
        IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP, // power button off up image
        IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN, // power button off down image
        255, 163, // power button x, y
        //#ifdef __MMI_FM_RADIO_ANIMATION__
        25,125,// animation backgroup x, y
        IMG_ID_FMRDO_SKIN_1_ANIMATION,// animation backgroup image
        //#endif
#ifdef __MMI_TOUCH_SCREEN__
        275,42,// volume_inc_x, volume_inc_y,
        IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP,// volume_inc_up_image_id
        IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN,// volume_inc_down_image_id
        275,74,// volume_dec_x, volume_dec_y,
        IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP,// volume_dec_up_image_id
        IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
        57,151,// setting_x, setting_y
        IMG_ID_FMRDO_SKIN_1_SETTING_UP, // setting_up_image_id
        IMG_ID_FMRDO_SKIN_1_SETTING_DOWN, // setting_down_image_id
        {(const fmrdo_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
        {(const fmrdo_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
        {(const fmrdo_point_struct *)skin1_step_down_button_points, 4}, // step_down_button_area
        {(const fmrdo_point_struct *)skin1_step_up_button_points, 4}, // step_up_button_area
        {(const fmrdo_point_struct *)skin1_power_button_points, 6}, // power_button_area
        {(const fmrdo_point_struct *)skin1_search_button_points, 5}, // search_button_area
        {(const fmrdo_point_struct *)skin1_setting_points, 4}, // setting_area
        {(const fmrdo_point_struct *)skin1_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
        IMG_ID_FMRDO_SKIN_1_REC,	// record indication icon image
        IMG_ID_FMRDO_SKIN_1_REC_PAUSE,	//record pause indication icon image
        154,152,	// record icon x, y
        IMG_ID_FMRDO_SKIN_1_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
        IMG_ID_FMRDO_SKIN_1_NUM_COL, // record duration seperator icon
        100,160,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	} ,
	{ // skin 3
            0, 0, 0, // LSK text border color
            255, 255, 255, // LSK text color
            0, 0, 0, // RSK text border color
            255, 255, 255, // RSK text color
            IMG_ID_FMRDO_SKIN_1_BACKGROUND, // background image
            0, 0, 0, // channel name text border color
            255, 255, 255, // channel name text color
            60, 2, // channel name x, y
            200, 26, // channel name w, h
            125, 197, 7, // frequency text on color
            150, 150, 150, // frequency text off color
            85, 50, // frequency x, y
            90, 20, // frequency w, h
            IMG_ID_FMRDO_SKIN_1_VOLUME, // volume image
            1, // volume bar type -> 0: horizontal, 1: vertical
            229, 45, // volume bar x, y
            0, 0, // volume indicator start gap, end gap
            IMG_ID_FMRDO_SKIN_1_TUNER_SCALE, // tuner scale background image
            IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR, // tuner scale indicator image
            0, // tuner scale type -> // 0: horizontal, 1: vertical
            30, 75, // tuner scale x, y
            -3, // tuner scale ind offset
            4, 9, // tuner scale start gap, end gap
            IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP, // step down button up image
            IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN, // step down button down image
            235, 143, // step down button x, y
            IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP, // step up button up image
            IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN, // step up button down image
            280, 142, // step up button x, y
            IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP, // search button on up image
            IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN, // search button on down image
            IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP, // search button off up image
            IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN, // search button off down image
            255, 112, // search button x, y
            IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP, // power button on up image
            IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN, // power button on down image
            IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP, // power button off up image
            IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN, // power button off down image
            255, 163, // power button x, y
            //#ifdef __MMI_FM_RADIO_ANIMATION__
            25,125,// animation backgroup x, y
            IMG_ID_FMRDO_SKIN_1_ANIMATION,// animation backgroup image
            //#endif
#ifdef __MMI_TOUCH_SCREEN__
            275,42,// volume_inc_x, volume_inc_y,
            IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP,// volume_inc_up_image_id
            IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN,// volume_inc_down_image_id
            275,74,// volume_dec_x, volume_dec_y,
            IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP,// volume_dec_up_image_id
            IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
            57,151,// setting_x, setting_y
            IMG_ID_FMRDO_SKIN_1_SETTING_UP, // setting_up_image_id
            IMG_ID_FMRDO_SKIN_1_SETTING_DOWN, // setting_down_image_id
            {(const fmrdo_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
            {(const fmrdo_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
            {(const fmrdo_point_struct *)skin1_step_down_button_points, 4}, // step_down_button_area
            {(const fmrdo_point_struct *)skin1_step_up_button_points, 4}, // step_up_button_area
            {(const fmrdo_point_struct *)skin1_power_button_points, 6}, // power_button_area
            {(const fmrdo_point_struct *)skin1_search_button_points, 5}, // search_button_area
            {(const fmrdo_point_struct *)skin1_setting_points, 4}, // setting_area
            {(const fmrdo_point_struct *)skin1_frequency_points, 4}, // frequency_area
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
            IMG_ID_FMRDO_SKIN_1_REC,	// record indication icon image
            IMG_ID_FMRDO_SKIN_1_REC_PAUSE,	//record pause indication icon image
            154,152,	// record icon x, y
            IMG_ID_FMRDO_SKIN_1_NUM_0, // record duration time icon. base is 0, 1 is base plus 1, 2 is base plus 2, ...
            IMG_ID_FMRDO_SKIN_1_NUM_COL, // record duration seperator icon
            100,160,	// recprd duration icon x, y
#endif	
		FMRDO_BUTTON_SEARCH, FMRDO_BUTTON_POWER, FMRDO_BUTTON_STEP_DOWN, FMRDO_BUTTON_STEP_UP // up, down, left, right key mapping
	}
#endif /*#ifndef __MMI_FM_SLIM_SKIN__*/	
};

#endif
#endif // __MMI_FM_RADIO__





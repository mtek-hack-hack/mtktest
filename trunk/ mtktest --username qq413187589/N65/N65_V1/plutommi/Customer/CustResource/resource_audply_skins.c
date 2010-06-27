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
*	resource_audply_skins.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main screen skin settings
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

#ifdef __MMI_AUDIO_PLAYER__
#include "gdi_lcd_config.h"

// dependent headers for AudioPlayerDef.h"
#include "FrameworkStruct.h"
#include "GlobalConstants.h"
#include "FileMgr.h"

#include "AudioPlayerDef.h"

#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) )
const audply_skin_struct g_audply_skins[] =
{
	{	//skin1
		IMG_ID_AUDPLY_MAIN_SKIN1_BG, // bg_image_id
		76,124,178, // text_border_color_r, text_border_color_g, text_border_color_b
		80,176,0, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		248,248,249, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		10,31, // title_x, title_y
		110,17, // title_w, title_h
		38,52, // time_x, time_y
		48,10, // time_w, time_h
		60,21, // file_index_x, file_index_y
		60,10, // file_index_w, file_index_h
		17,65, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		100,62,0,// volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INDICATOR, // volumebar_ind_image_id
        11,81, // progressbar_x, progressbar_y
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR, // progressbar_image_id
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR_FAIL, // progressbar_fail_image_id		
		67,89, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DOWN, // prev_button_down_image_id
		93,89, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DOWN, // next_button_down_image_id
		36,89, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_DOWN, // pause_button_down_image_id
		11,89, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DOWN, // stop_button_down_image_id
		-1,-1,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		-1,-1,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#ifndef __MMI_SLIM_AUDIO_PLAYER__
	,
	{	//skin2
		IMG_ID_AUDPLY_MAIN_SKIN2_BG, // bg_image_id
		198,0,255, // text_border_color_r, text_border_color_g, text_border_color_b
		198,0,255, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,234,0, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		10,31, // title_x, title_y
		110,17, // title_w, title_h
		38,50, // time_x, time_y
		48,10, // time_w, time_h
		60,19, // file_index_x, file_index_y
		60,10, // file_index_w, file_index_h
		17,65, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		100,62,0,// volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INDICATOR, // volumebar_ind_image_id
        10,79,// progressbar_x, progressbar_y
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR, // progressbar_image_id
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR_FAIL, // progressbar_fail_image_id		
		70,86, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DOWN, // prev_button_down_image_id
		91,86, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DOWN, // next_button_down_image_id
		36,86, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_DOWN, // pause_button_down_image_id
		15,86, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DOWN, // stop_button_down_image_id
		-1,-1,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		-1,-1,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
	,
	{	//skin3
		IMG_ID_AUDPLY_MAIN_SKIN3_BG, // bg_image_id
		112,112,32, // text_border_color_r, text_border_color_g, text_border_color_b
		87,248,10, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		0,0,0, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		10,31, // title_x, title_y
		110,17, // title_w, title_h
		38,50,// time_x, time_y
		48,10,// time_w, time_h
		60,19, // file_index_x, file_index_y
		60,10, // file_index_w, file_index_h
		17,65, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		100,62,0,// volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INDICATOR, // volumebar_ind_image_id
        11,81, // progressbar_x, progressbar_y
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR, // progressbar_image_id
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR_FAIL, // progressbar_fail_image_id			
		68,90, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DOWN, // prev_button_down_image_id
	    92,90, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DOWN, // next_button_down_image_id
		36,90, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_DOWN, // pause_button_down_image_id
		12,90, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DOWN, // stop_button_down_image_id
		-1,-1,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		-1,-1,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#endif
};
#elif ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
#ifdef __MMI_TOUCH_SCREEN__

static const audply_point_struct skin1_seek_points[] = {{0,0},{114,0},{114,6},{0,6}};
static const audply_point_struct skin1_volume_inc_points[] = {{0,0},{8,0},{8,10},{0,10}};
static const audply_point_struct skin1_volume_dec_points[] = {{0,0},{8,0},{8,10},{0,10}};
static const audply_point_struct skin1_prev_button_points[] = {{2,2},{18,2},{18,20},{2,20}};
static const audply_point_struct skin1_next_button_points[] = {{2,2},{18,2},{18,20},{2,20}};
static const audply_point_struct skin1_play_button_points[] = {{1,1},{25,1},{25,24},{1,24}};
static const audply_point_struct skin1_stop_button_points[] = {{1,1},{21,1},{21,23},{1,23}};
static const audply_point_struct skin1_setting_points[] = {{1,4},{16,4},{16,17},{1,17}};
static const audply_point_struct skin1_repeat_points[] = {{1,0},{16,0},{16,10},{1,10}};
static const audply_point_struct skin1_shuffle_points[] = {{1,0},{13,0},{13,10},{1,10}};

static const audply_point_struct skin2_seek_points[] = {{0,0},{104,0},{104,7},{0,7}};
static const audply_point_struct skin2_volume_inc_points[] = {{0,1},{13,1},{13,15},{0,15}};
static const audply_point_struct skin2_volume_dec_points[] = {{0,1},{14,1},{14,15},{0,15}};
static const audply_point_struct skin2_prev_button_points[] = {{2,11},{20,11},{20,29},{2,29}};
static const audply_point_struct skin2_next_button_points[] = {{1,15},{19,15},{19,33},{1,33}};
static const audply_point_struct skin2_play_button_points[] = {{2,2},{30,2},{30,32},{2,32}};
static const audply_point_struct skin2_stop_button_points[] = {{2,11},{23,11},{23,33},{2,33}};
static const audply_point_struct skin2_setting_points[] = {{1,1},{18,1},{18,18},{1,18}};
static const audply_point_struct skin2_repeat_points[] = {{0,0},{17,0},{17,10},{0,10}};
static const audply_point_struct skin2_shuffle_points[] = {{0,0},{14,0},{14,10},{0,10}};

static const audply_point_struct skin3_seek_points[] = {{0,0},{104,0},{104,6},{0,6}};
static const audply_point_struct skin3_volume_inc_points[] = {{0,0},{7,0},{7,11},{0,11}};
static const audply_point_struct skin3_volume_dec_points[] = {{0,0},{7,0},{7,11},{0,11}};
static const audply_point_struct skin3_prev_button_points[] = {{0,0},{21,0},{21,17},{0,17}};
static const audply_point_struct skin3_next_button_points[] = {{0,0},{21,0},{21,17},{0,17}};
static const audply_point_struct skin3_play_button_points[] = {{0,0},{27,0},{27,17},{0,17}};
static const audply_point_struct skin3_stop_button_points[] = {{0,0},{19,0},{19,17},{0,17}};
static const audply_point_struct skin3_setting_points[] = {{0,0},{19,0},{19,17},{0,17}};
static const audply_point_struct skin3_repeat_points[] = {{0,0},{17,0},{17,10},{0,10}};
static const audply_point_struct skin3_shuffle_points[] = {{0,0},{14,0},{14,10},{0,10}};

#endif	/* __MMI_TOUCH_SCREEN__ */
const audply_skin_struct g_audply_skins[] =
{
	/* skin 1 */
	{
		IMG_ID_AUDPLY_MAIN_SKIN1_BG,	/* back ground image */
		128, 0, 128,						/* text border color (r, g, b) */
		66, 39, 114,						/* text foreground color (r, g, b) */
		0, 0, 0,						/* text background color (r, g, b) */
		16, 1, 96, 18,					/* title (x, y, w, h) */
		5, 103,	30, 12,					/* time (x, y, w, h) */
		93, 103,	30, 12,					/* file index (x, y, w, h) */
		22, 76,							/* play list icon (x, y) */
		{	/* play list images */
			IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_PHONE_ICON, 
			IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_CARD_ICON
		}, 
		51, 76, 0, 0,					/* volume bar (x, y, step_len, direction), image:1 */
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INDICATOR,
        17, 92,							/* progress bar (x, y), image:2 */
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR,
        IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR_FAIL,    		
		39, 124,						/* previous button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_ON,
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DOWN,
		76, 124,						/* next button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_ON,
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DOWN,
		53, 119,						/* play button (x, y), image:6 */
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_ON,
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DOWN,
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_ON,
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_DOWN,
		58, 141,						/* stop button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_ON,
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DOWN,
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		-1, -1,							/* animation (x, y), animation:1 */
		IMG_ID_AUDPLY_MAIN_SKIN1_ANIMATION,
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		89, 52,							/* repeat mode (x, y), image:3+3 */
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_UP,
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_UP,
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_UP,
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_DOWN,     
#endif /*__MMI_TOUCH_SCREEN__*/
		63, 52,							/* shuffle icon (x, y), image:2+2 */
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_UP,
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_UP,     
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_DOWN,  
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		73, 76,						/* volume increase button (x, y), image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_UP,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_DOWN,
		42, 76,							/* volume decrease button (x, y), image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_UP,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_DOWN,
#ifdef __MMI_TOUCH_SCREEN__
		58, 107,							/* setting icon (x, y) image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_UP,
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_DOWN,
		/* touch area */
		{(const audply_point_struct *)skin1_seek_points, 4}, 
		{(const audply_point_struct *)skin1_volume_inc_points, 4},
		{(const audply_point_struct *)skin1_volume_dec_points, 4}, 
		{(const audply_point_struct *)skin1_prev_button_points, 4},
		{(const audply_point_struct *)skin1_next_button_points, 4},
		{(const audply_point_struct *)skin1_play_button_points, 4},
		{(const audply_point_struct *)skin1_stop_button_points, 4},
		{(const audply_point_struct *)skin1_setting_points, 4},
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin1_repeat_points, 4},
		{(const audply_point_struct *)skin1_shuffle_points, 4},			
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif
		/* key map: (up, down, left, right) */
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT
	}

	
#ifndef __MMI_SLIM_AUDIO_PLAYER__
	,
	/* skin 2 */
	{
		IMG_ID_AUDPLY_MAIN_SKIN2_BG,	/* back ground image */
		0, 0, 0,						/* text border color (r, g, b) */
		72,112,48,//61, 94, 60,						/* text foreground color (r, g, b) */
		0, 0, 0,						/* text background color (r, g, b) */
		25, 40, 80, 17,					/* title (x, y, w, h) */
		40, 60,	48, 10,					/* time (x, y, w, h) */
		35, 25,	60, 10,					/* file index (x, y, w, h) */
		11, 74,							/* play list icon (x, y) */
		{	/* play list images */
			IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_PHONE_ICON, 
			IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_CARD_ICON
		}, 
		82, 73, 0, 0,					/* volume bar (x, y, step_len, direction), image:1 */
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INDICATOR,
        13, 92,							/* progress bar (x, y), image:2 */
        IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR,
        IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR_FAIL,    		
		81, 104,						/* previous button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_ON,
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DOWN,
		103, 104,						/* next button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_ON,
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DOWN,
		49, 104,						/* play button (x, y), image:6 */
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_ON,
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DOWN,
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_ON,
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_DOWN,
		24, 104,						/* stop button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_ON,
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DOWN,
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		-1, -1,							/* animation (x, y), animation:1 */
		IMG_ID_AUDPLY_MAIN_SKIN2_ANIMATION,
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		24, 74,							/* repeat mode (x, y), image:3+3 */
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_UP,
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_UP,
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_UP,
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_DOWN,     
#endif /*__MMI_TOUCH_SCREEN__*/
		43, 74,							/* shuffle icon (x, y), image:2+2 */
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_UP,
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_UP,     
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_DOWN,  
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		111, 73,						/* volume increase button (x, y), image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_UP,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_DOWN,
		67, 73,							/* volume decrease button (x, y), image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_UP,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_DOWN,
#ifdef __MMI_TOUCH_SCREEN__
		3, 104,							/* setting icon (x, y) image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_UP,
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_DOWN,
		/* touch area */
		{(const audply_point_struct *)skin2_seek_points, 4}, 
		{(const audply_point_struct *)skin2_volume_inc_points, 4},
		{(const audply_point_struct *)skin2_volume_dec_points, 4}, 
		{(const audply_point_struct *)skin2_prev_button_points, 4},
		{(const audply_point_struct *)skin2_next_button_points, 4},
		{(const audply_point_struct *)skin2_play_button_points, 4},
		{(const audply_point_struct *)skin2_stop_button_points, 4},
		{(const audply_point_struct *)skin2_setting_points, 4},
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin2_repeat_points, 4},
		{(const audply_point_struct *)skin2_shuffle_points, 4},			
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif
		/* key map: (up, down, left, right) */
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT
	}
	,
	/* skin 3 */
	{
		IMG_ID_AUDPLY_MAIN_SKIN3_BG,	/* back ground image */
		128,0,128,//0, 0, 0,						/* text border color (r, g, b) */
		66,39,114,//61, 94, 60,						/* text foreground color (r, g, b) */
		0, 0, 0,						/* text background color (r, g, b) */
		25, 40, 80, 17,					/* title (x, y, w, h) */
		40, 60,	48, 10,					/* time (x, y, w, h) */
		35, 25,	60, 10,					/* file index (x, y, w, h) */
		12, 84,							/* play list icon (x, y) */
		{	/* play list images */
			IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_PHONE_ICON, 
			IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_CARD_ICON
		}, 
		78, 84, 0, 0,					/* volume bar (x, y, step_len, direction), image:1 */
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INDICATOR,
		12, 109,							/* progress bar (x, y), image:2 */
        IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR,
        IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR_FAIL,    		
		79, 122,						/* previous button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_ON,
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DOWN,
		101, 122,						/* next button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_ON,
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DOWN,
		51, 122,						/* play button (x, y), image:6 */
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_ON,
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DOWN,
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_ON,
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_DOWN,
		31, 122,						/* stop button (x, y), image:4 */
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_ON,
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_OFF,
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DISABLED,
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DOWN,
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		-1, -1,							/* animation (x, y), animation:1 */
		IMG_ID_AUDPLY_MAIN_SKIN3_ANIMATION,
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		24, 84,							/* repeat mode (x, y), image:3+3 */
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_UP,
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_UP,
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_UP,
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_DOWN,     
#endif /*__MMI_TOUCH_SCREEN__*/
		41, 84,							/* shuffle icon (x, y), image:2+2 */
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_UP,
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_UP,     
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_DOWN,
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_DOWN,  
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		107, 84,						/* volume increase button (x, y), image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_UP,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_DOWN,
		69, 84,							/* volume decrease button (x, y), image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_UP,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_DOWN,
#ifdef __MMI_TOUCH_SCREEN__
		5, 122,							/* setting icon (x, y) image:2 */
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_UP,
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_DOWN,
		/* touch area */
		{(const audply_point_struct *)skin3_seek_points, 4}, 
		{(const audply_point_struct *)skin3_volume_inc_points, 4},
		{(const audply_point_struct *)skin3_volume_dec_points, 4}, 
		{(const audply_point_struct *)skin3_prev_button_points, 4},
		{(const audply_point_struct *)skin3_next_button_points, 4},
		{(const audply_point_struct *)skin3_play_button_points, 4},
		{(const audply_point_struct *)skin3_stop_button_points, 4},
		{(const audply_point_struct *)skin3_setting_points, 4},
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin3_repeat_points, 4},
		{(const audply_point_struct *)skin3_shuffle_points, 4},			
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif
		/* key map: (up, down, left, right) */
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT
	}
#endif
};
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#ifdef __MMI_TOUCH_SCREEN__

static const audply_point_struct skin1_seek_points[] = {{0,0},{131,0},{131,6},{0,6}};
static const audply_point_struct skin1_volume_inc_points[] = {{1,1},{13,1},{13,29},{1,29}};
static const audply_point_struct skin1_volume_dec_points[] = {{1,1},{13,1},{13,29},{1,29}};
static const audply_point_struct skin1_prev_button_points[] = {{1,1},{25,1},{25,25},{1,25}};
static const audply_point_struct skin1_next_button_points[] = {{1,1},{25,1},{25,25},{1,25}};
static const audply_point_struct skin1_play_button_points[] = {{1,1},{25,1},{25,25},{1,25}};
static const audply_point_struct skin1_stop_button_points[] = {{1,1},{25,1},{25,25},{1,25}};
static const audply_point_struct skin1_setting_points[] = {{1,1},{20,1},{20,20},{1,20}};
static const audply_point_struct skin1_repeat_points[] = {{0,0},{20,0},{20,20},{0,20}};
static const audply_point_struct skin1_shuffle_points[] = {{0,0},{20,0},{20,20},{0,20}};

static const audply_point_struct skin2_seek_points[] = {{0,0},{131,0},{131,7},{0,7}};
static const audply_point_struct skin2_volume_inc_points[] = {{1,1},{15,1},{15,22},{1,22}};
static const audply_point_struct skin2_volume_dec_points[] = {{1,1},{15,1},{15,22},{1,22}};
static const audply_point_struct skin2_prev_button_points[] = {{1,1},{23,1},{23,22},{1,22}};
static const audply_point_struct skin2_next_button_points[] = {{1,1},{23,1},{23,22},{1,22}};
static const audply_point_struct skin2_play_button_points[] = {{1,1},{27,1},{27,22},{1,22}};
static const audply_point_struct skin2_stop_button_points[] = {{1,1},{21,1},{21,22},{1,22}};
static const audply_point_struct skin2_setting_points[] = {{1,1},{21,1},{21,22},{1,22}};
static const audply_point_struct skin2_repeat_points[] = {{0,0},{22,0},{22,23},{0,23}};
static const audply_point_struct skin2_shuffle_points[] = {{0,0},{20,0},{20,23},{0,23}};

static const audply_point_struct skin3_seek_points[] = {{0,0},{131,0},{131,6},{0,6}};
static const audply_point_struct skin3_volume_inc_points[] = {{1,1},{15,1},{15,22},{1,22}};
static const audply_point_struct skin3_volume_dec_points[] = {{1,1},{15,1},{15,22},{1,22}};
static const audply_point_struct skin3_prev_button_points[] = {{1,1},{23,1},{23,22},{1,22}};
static const audply_point_struct skin3_next_button_points[] = {{1,1},{23,1},{23,22},{1,22}};
static const audply_point_struct skin3_play_button_points[] = {{1,1},{27,1},{27,22},{1,22}};
static const audply_point_struct skin3_stop_button_points[] = {{1,1},{21,1},{21,22},{1,22}};
static const audply_point_struct skin3_setting_points[] = {{1,1},{21,1},{21,22},{1,22}};
static const audply_point_struct skin3_repeat_points[] = {{0,0},{20,0},{20,20},{0,20}};
static const audply_point_struct skin3_shuffle_points[] = {{0,0},{20,0},{20,20},{0,20}};

#endif
const audply_skin_struct g_audply_skins[] =
{
	{	//skin1
		IMG_ID_AUDPLY_MAIN_SKIN1_BG, // bg_image_id
		255,255,0, // text_border_color_r, text_border_color_g, text_border_color_b
		255,255,255, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		0,0,0, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		25,2,   //18,26,   edit by lijianxin 080716 // title_x, title_y
		124,20,   //141,17,   edit by lijianxin 080716 // title_w, title_h
		6,27,   //106,50,   //edit by lijianxin 080716 // time_x, time_y
		82,20,// time_w, time_h
		91,27,   //20,50,   //edit by lijianxin 080716  // file_index_x, file_index_y
		82,20, // file_index_w, file_index_h
		68,136, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		18,169,7,   //25,175,0,   edit by lijianxin 080716 // volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INDICATOR, // volumebar_ind_image_id
		95,139,// progressbar_x, progressbar_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR, // progressbar_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		65,165, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DOWN, // prev_button_down_image_id
		119,165, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DOWN, // next_button_down_image_id
		92,165, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_DOWN, // pause_button_down_image_id
		146,165, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		9,52, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN1_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		26,83, // spectrum_display_x, spectrum_display_y
		124,20, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		85,53,138, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		10,68, // lyric_display_x , lyric_display_y
		155,48, // lyric_display_w , lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        	1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		46,135, // repeat_x, repeat_y
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_UP, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_UP, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		24, 135, // shuffle_x, shuffle_y
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_UP, // shuffle off
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_UP, // shuffle on       
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		48,164,   //53,168,   edit by lijianxin 080716 // volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_DOWN,// volume_inc_down_image_id
		5,164,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
             1,135,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_UP, // setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_DOWN, // setting_down_image_id
		{(const audply_point_struct *)skin1_seek_points, 4}, // progress_bar_area
		{(const audply_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin1_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin1_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin1_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin1_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin1_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin1_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin1_shuffle_points, 4}, // shuffle_area				
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#ifndef __MMI_SLIM_AUDIO_PLAYER__
	,
	{	//skin2
		IMG_ID_AUDPLY_MAIN_SKIN2_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		0,0,0, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		18,32,// title_x, title_y
		141,17,// title_w, title_h 
		107,56,// time_x, time_y
		44,10,// time_w, time_h
		20,56, // file_index_x, file_index_y
		60,10, // file_index_w, file_index_h
		48,140, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		23,170,0,// volumebar_x, volumebar_y,   volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INDICATOR, // volumebar_ind_image_id
       	23,127,// progressbar_x, progressbar_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR, // progressbar_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		122,166, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DOWN, // prev_button_down_image_id
		145,166, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DOWN, // next_button_down_image_id
		71,166, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_DOWN, // pause_button_down_image_id
		99,166, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		5,73, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN2_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		5,73, // spectrum_display_x, spectrum_display_y
		157,48, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		0,0,0, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		9,73, // lyric_display_x , lyric_display_y
		155,48, // lyric_display_w , lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        	1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		8,140, // repeat_x, repeat_y
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_UP, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_UP, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		28, 140, // shuffle_x, shuffle_y
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_UP, // shuffle off
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_UP, // shuffle on       
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		52,166,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_DOWN,// volume_inc_down_image_id
		7,166,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		145,140,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_UP,// setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_DOWN,// setting_down_image_id
		{(const audply_point_struct *)skin2_seek_points, 4}, // progress_bar_area	
		{(const audply_point_struct *)skin2_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin2_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin2_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin2_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin2_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin2_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin2_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin2_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin2_shuffle_points, 4}, // shuffle_area				
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
	,
	{	//skin3
		IMG_ID_AUDPLY_MAIN_SKIN3_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		0,0,0, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		14,37,// title_x, title_y
		141,17,// title_w, title_h
		104,60,// time_x, time_y
		44,10,// time_w, time_h
		17,60, // file_index_x, file_index_y
		60,10, // file_index_w, file_index_h
		50,145, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		25,172,0,// volumebar_x, volumebar_y,  volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INDICATOR, // volumebar_ind_image_id
		22,134,// progressbar_x, progressbar_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR, // progressbar_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		123,168, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DOWN, // prev_button_down_image_id
		147,168, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DOWN, // next_button_down_image_id
		72,168, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_DOWN, // pause_button_down_image_id
		101,168, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		5,77, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN3_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		5,77, // spectrum_display_x, spectrum_display_y
		157,48, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		0,0,0, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		9,77, // lyric_display_x , lyric_display_y
		155,48, // lyric_display_w , lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        	1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		10,145, // repeat_x, repeat_y
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_UP, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_UP, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		30, 145, // shuffle_x, shuffle_y
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_UP, // shuffle off
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_UP, // shuffle on       
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		53,168,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		8,168,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		147,145,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_UP,// setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_DOWN,// setting_down_image_id
		{(const audply_point_struct *)skin3_seek_points, 4}, // progress_bar_area
		{(const audply_point_struct *)skin3_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin3_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin3_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin3_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin3_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin3_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin3_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin3_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin3_shuffle_points, 4}, // shuffle_area				
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#endif  /* ~__MMI_SLIM_AUDIO_PLAYER__ */
};
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#ifdef __MMI_TOUCH_SCREEN__
static const audply_point_struct skin1_seek_points[] = {{0,0},{207,0},{207,10},{0,10}};
static const audply_point_struct skin1_volume_inc_points[] = {{0,1},{16,1},{16,24},{0,24}};
static const audply_point_struct skin1_volume_dec_points[] = {{1,1},{17,1},{17,24},{1,24}};
static const audply_point_struct skin1_prev_button_points[] = {{1,1},{25,1},{25,20},{1,20}};
static const audply_point_struct skin1_next_button_points[] = {{1,1},{25,1},{25,20},{1,20}};
static const audply_point_struct skin1_play_button_points[] = {{1,1},{25,1},{25,25},{1,25}};
static const audply_point_struct skin1_stop_button_points[] = {{1,1},{20,1},{20,20},{1,20}};
static const audply_point_struct skin1_setting_points[] = {{1,1},{32,1},{32,25},{1,25}};
static const audply_point_struct skin1_repeat_points[] = {{1,1},{32,1},{32,23},{1,23}};
static const audply_point_struct skin1_shuffle_points[] = {{1,1},{32,1},{32,24},{1,24}};

static const audply_point_struct skin2_seek_points[] = {{0,0},{194,0},{194,10},{0,10}};
static const audply_point_struct skin2_volume_inc_points[] = {{0,0},{16,0},{16,28},{0,28}};
static const audply_point_struct skin2_volume_dec_points[] = {{0,0},{16,0},{16,28},{0,28}};
static const audply_point_struct skin2_prev_button_points[] = {{0,0},{30,0},{30,24},{0,24}};
static const audply_point_struct skin2_next_button_points[] = {{0,0},{30,0},{30,24},{0,24}};
static const audply_point_struct skin2_play_button_points[] = {{0,0},{40,0},{40,28},{0,28}};
static const audply_point_struct skin2_stop_button_points[] = {{0,0},{28,0},{28,28},{0,28}};
static const audply_point_struct skin2_setting_points[] = {{0,0},{22,0},{22,28},{0,28}};
static const audply_point_struct skin2_repeat_points[] = {{0,0},{22,0},{22,28},{0,28}};
static const audply_point_struct skin2_shuffle_points[] = {{0,0},{22,0},{22,28},{0,28}};

static const audply_point_struct skin3_seek_points[] = {{0,0},{194,0},{194,10},{0,10}};
static const audply_point_struct skin3_volume_inc_points[] = {{0,0},{18,0},{18,30},{0,30}};
static const audply_point_struct skin3_volume_dec_points[] = {{0,0},{18,0},{18,30},{0,30}};
static const audply_point_struct skin3_prev_button_points[] = {{0,0},{31,0},{31,26},{0,26}};
static const audply_point_struct skin3_next_button_points[] = {{0,0},{31,0},{31,26},{0,26}};
static const audply_point_struct skin3_play_button_points[] = {{0,0},{42,0},{42,30},{0,30}};
static const audply_point_struct skin3_stop_button_points[] = {{0,0},{29,0},{29,30},{0,30}};
static const audply_point_struct skin3_setting_points[] = {{0,0},{20,0},{20,22},{0,22}};
static const audply_point_struct skin3_repeat_points[] = {{0,0},{20,0},{20,22},{0,22}};
static const audply_point_struct skin3_shuffle_points[] = {{0,0},{20,0},{20,22},{0,22}};
#endif /*__MMI_TOUCH_SCREEN__*/

const audply_skin_struct g_audply_skins[] =
{
	{	//skin1
		IMG_ID_AUDPLY_MAIN_SKIN1_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		255,255,255, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		31,44,// title_x, title_y
		177,23,// title_w, title_h
		209,198,// time_x, time_y
		104,18,// time_w, time_h
		17,69, // file_index_x, file_index_y
		190,65, // file_index_w, file_index_h
		65,216, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		186,265,0,// volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INDICATOR, // volumebar_ind_image_id
  	  	34,198,// progressbar_x, progressbar_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR, // progressbar_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		13,260, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_ON, // prev_button_on_image_ids
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DOWN, // prev_button_down_image_id
		95,260, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DOWN, // next_button_down_image_id
		56,260, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_DOWN, // pause_button_down_image_id
		138,261, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		33,83, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN1_ANIMATION, // animation_image_id
#endif
/*shaokai modify it start.090831*/
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		33,88, // spectrum_display_x, spectrum_display_y
		176,65/*95*/,//212,94, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		0,0,0, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		13,155/*143*/,//13,93, // lyric_display_x, lyric_display_y
		212,44,//212,94, // lyric_display_w, lyric_display_h
#endif
/*shaokai modify it end.090831*/
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        0, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		23,231, // repeat_x, repeat_y
		IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_UP, // repeat off
		IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_UP, // repeat all
		IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		81,232, // shuffle_x, shuffle_y
		IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_UP, // shuffle off
		IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_UP, // shuffle on		
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		219,266,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_DOWN,// volume_inc_down_image_id
		168,271,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		192,231,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_UP, // setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_DOWN, // setting_down_image_id
		{(const audply_point_struct *)skin1_seek_points, 4}, // seek_area
		{(const audply_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin1_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin1_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin1_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin1_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin1_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin1_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin1_shuffle_points, 4}, // shuffle_area				
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif /*__MMI_TOUCH_SCREEN__*/
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#ifndef __MMI_SLIM_AUDIO_PLAYER__
	,
	{	//skin2
		IMG_ID_AUDPLY_MAIN_SKIN2_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		2,88,137, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		18,42,// title_x, title_y
		200,22,// title_w, title_h
		134,68,// time_x, time_y
		80,18,// time_w, time_h
		18,68, // file_index_x, file_index_y
		96,18, // file_index_w, file_index_h
		67,219, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		36,264,0,// volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INDICATOR, // volumebar_ind_image_id
        23,193,// progressbar_x, progressbar_y
        IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR, // progressbar_image_id
        IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		159,255, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DOWN, // prev_button_down_image_id
		191,255, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DOWN, // next_button_down_image_id
		86,254, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_DOWN, // pause_button_down_image_id
		129,254, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		18,96, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN2_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		-1,-1,//18,96, // spectrum_display_x, spectrum_display_y
		-1,-1,//202,88, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		2,88,137, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		18,96, // lyric_display_x, lyric_display_y
		202,88, // lyric_display_w, lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		18,219, // repeat_x, repeat_y
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_UP, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_UP, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		42,219, // shuffle_x, shuffle_y
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_UP, // shuffle off
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_UP, // shuffle on       
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		67,254,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_DOWN,// volume_inc_down_image_id
		15,254,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		194,217,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_UP,// setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_DOWN,// setting_down_image_id
		{(const audply_point_struct *)skin2_seek_points, 4}, // seek_area
		{(const audply_point_struct *)skin2_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin2_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin2_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin2_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin2_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin2_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin2_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		{(const audply_point_struct *)skin2_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin2_shuffle_points, 4}, // shuffle_area
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif /*__MMI_TOUCH_SCREEN__*/
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
	,
	{	//skin3
		IMG_ID_AUDPLY_MAIN_SKIN3_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		78,7,104, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		24,56,// title_x, title_y
		194,22,// title_w, title_h
		130,83,// time_x, time_y
		80,18,// time_w, time_h
		26,83, // file_index_x, file_index_y
		90,18, // file_index_w, file_index_h
		68,217, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		37,258,0,// volumebar_x, volumebar_y, volumebar_ind_len
        0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INDICATOR, // volumebar_ind_image_id
    	24,196,// progressbar_x, progressbar_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR, // progressbar_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		161,251, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DOWN, // prev_button_down_image_id
		193,251, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DOWN, // next_button_down_image_id
		89,249, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_DOWN, // pause_button_down_image_id
		131,249, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		26,110, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN3_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		26,110, // spectrum_display_x, spectrum_display_y
		184,68, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		-1,-1,-1,//7,87,104, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		-1,-1,-1,//255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		-1,-1,//26,110, // lyric_display_x, lyric_display_y
		-1,-1,//184,68, // lyric_display_w, lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		18,217, // repeat_x, repeat_y
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_UP, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_UP, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		43,217, // shuffle_x, shuffle_y
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_UP, // shuffle off
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_UP, // shuffle on       
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		68,249,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		16,249,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		199,217,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_UP,// setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_DOWN,// setting_down_image_id
		{(const audply_point_struct *)skin3_seek_points, 4}, // seek_area
		{(const audply_point_struct *)skin3_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin3_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin3_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin3_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin3_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin3_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin3_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin3_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin3_shuffle_points, 4}, // shuffle_area				
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */
#endif /*__MMI_TOUCH_SCREEN__*/
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#endif
};

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#ifdef __MMI_TOUCH_SCREEN__
static const audply_point_struct skin1_seek_points[] = {{2,2},{176,2},{176,10},{2,10}};
static const audply_point_struct skin1_volume_inc_points[] = {{1,1},{20,1},{20,20},{1,20}};
static const audply_point_struct skin1_volume_dec_points[] = {{1,1},{20,1},{20,20},{1,20}};
static const audply_point_struct skin1_prev_button_points[] = {{2,2},{32,2},{32,32},{2,32}};
static const audply_point_struct skin1_next_button_points[] = {{2,2},{32,2},{32,32},{2,32}};
static const audply_point_struct skin1_play_button_points[] = {{2,2},{32,2},{32,32},{2,32}};
static const audply_point_struct skin1_stop_button_points[] = {{2,2},{32,2},{32,32},{2,32}};
static const audply_point_struct skin1_setting_points[] = {{1,1},{22,1},{22,22},{1,22}};
static const audply_point_struct skin1_repeat_points[] = {{1,1},{20,1},{20,20},{1,20}};
static const audply_point_struct skin1_shuffle_points[] = {{1,1},{20,1},{20,20},{1,20}};

static const audply_point_struct skin2_seek_points[] = {{0,0},{194,0},{194,10},{0,10}};
static const audply_point_struct skin2_volume_inc_points[] = {{0,0},{16,0},{16,28},{0,28}};
static const audply_point_struct skin2_volume_dec_points[] = {{0,0},{16,0},{16,28},{0,28}};
static const audply_point_struct skin2_prev_button_points[] = {{0,0},{30,0},{30,24},{0,24}};
static const audply_point_struct skin2_next_button_points[] = {{0,0},{30,0},{30,24},{0,24}};
static const audply_point_struct skin2_play_button_points[] = {{0,0},{40,0},{40,28},{0,28}};
static const audply_point_struct skin2_stop_button_points[] = {{0,0},{28,0},{28,28},{0,28}};
static const audply_point_struct skin2_setting_points[] = {{0,0},{22,0},{22,28},{0,28}};
static const audply_point_struct skin2_repeat_points[] = {{0,0},{22,0},{22,28},{0,28}};
static const audply_point_struct skin2_shuffle_points[] = {{0,0},{22,0},{22,28},{0,28}};

static const audply_point_struct skin3_seek_points[] = {{0,0},{194,0},{194,10},{0,10}};
static const audply_point_struct skin3_volume_inc_points[] = {{0,0},{18,0},{18,30},{0,30}};
static const audply_point_struct skin3_volume_dec_points[] = {{0,0},{18,0},{18,30},{0,30}};
static const audply_point_struct skin3_prev_button_points[] = {{0,0},{31,0},{31,26},{0,26}};
static const audply_point_struct skin3_next_button_points[] = {{0,0},{31,0},{31,26},{0,26}};
static const audply_point_struct skin3_play_button_points[] = {{0,0},{42,0},{42,30},{0,30}};
static const audply_point_struct skin3_stop_button_points[] = {{0,0},{29,0},{29,30},{0,30}};
static const audply_point_struct skin3_setting_points[] = {{0,0},{20,0},{20,22},{0,22}};
static const audply_point_struct skin3_repeat_points[] = {{0,0},{20,0},{20,22},{0,22}};
static const audply_point_struct skin3_shuffle_points[] = {{0,0},{20,0},{20,22},{0,22}};
#endif /*__MMI_TOUCH_SCREEN__*/

const audply_skin_struct g_audply_skins[] =
{
	{	//skin1
		IMG_ID_AUDPLY_MAIN_SKIN1_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		255,255,255,//102,208,255, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		27,38,// title_x, title_y
		157,23,// title_w, title_h
		204,82,// time_x, time_y
		104,18,// time_w, time_h
		210,53, // file_index_x, file_index_y
		92,18, // file_index_w, file_index_h
		272,156, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN1_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		223,128,0,// volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INDICATOR, // volumebar_ind_image_id
    	17,140,// progressbar_x, progressbar_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR, // progressbar_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		110,162, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PREV_DOWN, // prev_button_down_image_id
		153,162, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_NEXT_DOWN, // next_button_down_image_id
		24,162, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_PAUSE_DOWN, // pause_button_down_image_id
		67,162, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		24,81, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN1_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		24,82, // spectrum_display_x, spectrum_display_y
		165,47,//212,94, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		0,0,0, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		24,81,//13,93, // lyric_display_x, lyric_display_y
		165,48,//212,94, // lyric_display_w, lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		222,156, // repeat_x, repeat_y
		IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_UP, // repeat off
		IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_UP, // repeat all
		IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN1_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		247,156, // shuffle_x, shuffle_y
		IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_UP, // shuffle off
		IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_UP, // shuffle on		
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN1_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		287,126,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_INC_DOWN,// volume_inc_down_image_id
		200,126,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		207,181,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_UP, // setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_SETTING_DOWN, // setting_down_image_id
		{(const audply_point_struct *)skin1_seek_points, 4}, // seek_area
		{(const audply_point_struct *)skin1_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin1_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin1_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin1_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin1_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin1_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin1_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin1_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin1_shuffle_points, 4}, // shuffle_area				
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif /*__MMI_TOUCH_SCREEN__*/
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#ifndef __MMI_SLIM_AUDIO_PLAYER__
	,
	{	//skin2
		IMG_ID_AUDPLY_MAIN_SKIN2_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		2,88,137, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		18,42,// title_x, title_y
		200,22,// title_w, title_h
		134,68,// time_x, time_y
		80,18,// time_w, time_h
		18,68, // file_index_x, file_index_y
		96,18, // file_index_w, file_index_h
		67,219, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN2_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		36,264,0,// volumebar_x, volumebar_y, volumebar_ind_len
		0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INDICATOR, // volumebar_ind_image_id
        23,193,// progressbar_x, progressbar_y
        IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR, // progressbar_image_id
        IMG_ID_AUDPLY_MAIN_SKIN2_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		159,255, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PREV_DOWN, // prev_button_down_image_id
		191,255, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_NEXT_DOWN, // next_button_down_image_id
		86,254, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_PAUSE_DOWN, // pause_button_down_image_id
		129,254, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		18,96, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN2_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		-1,-1,//18,96, // spectrum_display_x, spectrum_display_y
		-1,-1,//202,88, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		2,88,137, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		18,96, // lyric_display_x, lyric_display_y
		202,88, // lyric_display_w, lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		18,219, // repeat_x, repeat_y
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_UP, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_UP, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN2_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		42,219, // shuffle_x, shuffle_y
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_UP, // shuffle off
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_UP, // shuffle on       
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN2_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		67,254,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_INC_DOWN,// volume_inc_down_image_id
		15,254,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		194,217,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_UP,// setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN2_SETTING_DOWN,// setting_down_image_id
		{(const audply_point_struct *)skin2_seek_points, 4}, // seek_area
		{(const audply_point_struct *)skin2_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin2_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin2_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin2_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin2_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin2_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin2_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		{(const audply_point_struct *)skin2_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin2_shuffle_points, 4}, // shuffle_area
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/		
#endif /*__MMI_TOUCH_SCREEN__*/
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
	,
	{	//skin3
		IMG_ID_AUDPLY_MAIN_SKIN3_BG, // bg_image_id
		0,0,0, // text_border_color_r, text_border_color_g, text_border_color_b
		78,7,104, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		255,255,255, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		24,56,// title_x, title_y
		194,22,// title_w, title_h
		130,83,// time_x, time_y
		80,18,// time_w, time_h
		26,83, // file_index_x, file_index_y
		90,18, // file_index_w, file_index_h
		68,217, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_MAIN_SKIN3_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		37,258,0,// volumebar_x, volumebar_y, volumebar_ind_len
        0, //volumebar_direction
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INDICATOR, // volumebar_ind_image_id
    	24,196,// progressbar_x, progressbar_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR, // progressbar_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PROGRESSBAR_FAIL, // progressbar_fail_image_id
		161,251, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PREV_DOWN, // prev_button_down_image_id
		193,251, // next_button_x, next_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_NEXT_DOWN, // next_button_down_image_id
		89,249, // play_button_x, play_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_PAUSE_DOWN, // pause_button_down_image_id
		131,249, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_STOP_DOWN, // stop_button_down_image_id
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
		26,110, // animation_x, animation_y
		IMG_ID_AUDPLY_MAIN_SKIN3_ANIMATION, // animation_image_id
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
		26,110, // spectrum_display_x, spectrum_display_y
		184,68, // spectrum_display_w, spectrum_display_h
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
		-1,-1,-1,//7,87,104, // lyric_fg_color_r,lyric_fg_color_g, lyric_fg_color_b
		-1,-1,-1,//255,255,255, // lyric_border_color_r, lyric_border_color_g, lyric_border_color_b
		-1,-1,//26,110, // lyric_display_x, lyric_display_y
		-1,-1,//184,68, // lyric_display_w, lyric_display_h
#endif
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
        1, // spectrum_lyrics_exclusive
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
		18,217, // repeat_x, repeat_y
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_UP, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_UP, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_UP, // repeat one
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ALL_DOWN, // repeat all
        IMG_ID_AUDPLY_MAIN_SKIN3_REPEAT_ONE_DOWN, // repeat one        
#endif /*__MMI_TOUCH_SCREEN__*/
		43,217, // shuffle_x, shuffle_y
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_UP, // shuffle off
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_UP, // shuffle on       
#ifdef __MMI_TOUCH_SCREEN__
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_OFF_DOWN, // repeat off
        IMG_ID_AUDPLY_MAIN_SKIN3_SHUFFLE_ON_DOWN, // repeat all   
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
		68,249,// volume_inc_x, volume_inc_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_UP,// volume_inc_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_INC_DOWN,// volume_inc_down_image_id
		16,249,// volume_dec_x, volume_dec_y,
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_UP,// volume_dec_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_VOLUME_DEC_DOWN,// volume_dec_down_image_id
#ifdef __MMI_TOUCH_SCREEN__
		199,217,// setting_x, setting_y
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_UP,// setting_up_image_id
		IMG_ID_AUDPLY_MAIN_SKIN3_SETTING_DOWN,// setting_down_image_id
		{(const audply_point_struct *)skin3_seek_points, 4}, // seek_area
		{(const audply_point_struct *)skin3_volume_inc_points, 4}, // volume_inc_area
		{(const audply_point_struct *)skin3_volume_dec_points, 4}, // volume_dec_area
		{(const audply_point_struct *)skin3_prev_button_points, 4}, // prev_button_area
		{(const audply_point_struct *)skin3_next_button_points, 4}, // next_button_area
		{(const audply_point_struct *)skin3_play_button_points, 4}, // play_button_area
		{(const audply_point_struct *)skin3_stop_button_points, 4}, // stop_button_area
		{(const audply_point_struct *)skin3_setting_points, 4}, // setting_area
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__		
		{(const audply_point_struct *)skin3_repeat_points, 4}, // repeat_area
		{(const audply_point_struct *)skin3_shuffle_points, 4}, // shuffle_area				
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */
#endif /*__MMI_TOUCH_SCREEN__*/
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
	}
#endif
};

#endif
#endif /* __MMI_AUDIO_PLAYER__ */




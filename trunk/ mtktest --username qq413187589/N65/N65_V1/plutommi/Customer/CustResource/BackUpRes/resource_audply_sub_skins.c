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

#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
const audply_sub_skin_struct g_audply_skins_sub[] =
{
		IMG_ID_AUDPLY_SUB_SKIN_BG, // bg_image_id
		76,124,178, // text_border_color_r, text_border_color_g, text_border_color_b
		80,176,0, // text_fg_color_r, text_fg_color_g, text_fg_color_b
		248,248,249, // text_bg_color_r, text_bg_color_g, text_bg_color_b
		2,4,// title_x, title_y
		88,28,// title_w, title_h
		1,33,// time_x, time_y
		33,10,// time_w, time_h
		34,33, // file_index_x, file_index_y
		60,10, // file_index_w, file_index_h
		17,65, // playlisticon_x, playlisticon_y
		{IMG_ID_AUDPLY_SUB_SKIN_PLAYLIST_PHONE_ICON, IMG_ID_AUDPLY_SUB_SKIN_PLAYLIST_CARD_ICON}, // playlisticon_images_id[NO_OF_LIST]
		2,51,2,// volumebar_x, volumebar_y, volumebar_ind_left
		0,// volumebar_direction
		IMG_ID_AUDPLY_SUB_SKIN_VOLUME_INDICATOR, // volumebar_ind_image_id
		33,45, // prev_button_x, prev_button_y
		IMG_ID_AUDPLY_SUB_SKIN_PREV_ON, // prev_button_on_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PREV_OFF, // prev_button_off_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PREV_DISABLED, // prev_button_disabled_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PREV_DOWN, // prev_button_down_image_id
		75,45, // next_button_x, next_button_y
		IMG_ID_AUDPLY_SUB_SKIN_NEXT_ON, // next_button_on_image_id
		IMG_ID_AUDPLY_SUB_SKIN_NEXT_OFF, // next_button_off_image_id
		IMG_ID_AUDPLY_SUB_SKIN_NEXT_DISABLED, // next_button_disabled_image_id
		IMG_ID_AUDPLY_SUB_SKIN_NEXT_DOWN, // next_button_down_image_id
		54,45, // play_button_x, play_button_y
		IMG_ID_AUDPLY_SUB_SKIN_PLAY_ON, // play_button_on_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PLAY_OFF, // play_button_off_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PLAY_DISABLED, // play_button_disabled_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PLAY_DOWN, // play_button_down_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PAUSE_ON, // pause_button_on_image_id
		IMG_ID_AUDPLY_SUB_SKIN_PAUSE_DOWN, // pause_button_down_image_id
		49,92, // stop_button_x, stop_button_y
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_ON, // stop_button_on_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_OFF, // stop_button_off_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DISABLED, // stop_button_disabled_image_id
		IMG_ID_AUDPLY_MAIN_SKIN1_STOP_DOWN, // stop_button_down_image_id
		AUDPLY_MAIN_PLAY, AUDPLY_MAIN_STOP, AUDPLY_MAIN_PREV, AUDPLY_MAIN_NEXT // up, down, left, right key mapping
};
#endif
#endif

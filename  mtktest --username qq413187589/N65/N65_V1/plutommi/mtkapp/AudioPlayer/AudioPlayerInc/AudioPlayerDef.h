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
*  AudioPlayerDef.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main screen
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
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
 * rebase maintrunk.MAUI_MBJ on 2007-4-23 10:20:01.
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

#ifndef AUDIO_PLAYER_DEF_H
#define AUDIO_PLAYER_DEF_H

#include "FrameworkStruct.h"
#include "GlobalConstants.h"
#include "FileMgr.h"

#include "AudioPlayerResDef.h"

#ifdef __MMI_AUDIO_PLAYER__

typedef enum
{
    LIST_FROM_PHONE,
    LIST_FROM_CARD,
    NO_OF_LIST
} audply_playlist_enum;

typedef enum
{
    SKIN1,
#ifndef __MMI_SLIM_AUDIO_PLAYER__
    SKIN2,
    SKIN3,
#endif /* __MMI_SLIM_AUDIO_PLAYER__ */ 
    NO_OF_SKIN
} audply_skin_enum;

/*skins for sub LCD SKIN1_SUB for 96X64 SKIN2_SUB for 128X128*/
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
typedef enum
{
    SKIN1_SUB,
    NO_OF_SKIN_SUB
}audply_skin_enum_sub;
#endif

typedef enum
{
    REPEAT_OFF,
    REPEAT_ONE,
    REPEAT_ALL
} audply_repeat_enum;

typedef enum
{
    SHUFFLE_OFF,
    SHUFFLE_ON
} audply_shuffle_enum;

typedef enum
{
    HORIZONTAL_VOL_BAR,
    VERTICAL_VOL_BAR
} audply_vol_bar_enum;

typedef enum
{
    NON_UCS2,
    UCS2_LITTLE_ENDIAN,
    UCS2_BIG_ENDIAN
} audply_UCS2_encode_enum;

typedef enum
{
    AUDPLY_MAIN_DISABLED = -1,
    AUDPLY_MAIN_PLAY = 0,
    AUDPLY_MAIN_PREV,
    AUDPLY_MAIN_NEXT,
    AUDPLY_MAIN_STOP,
    NO_OF_AUDPLY_MAIN_BUTTONS,
    AUDPLY_MAIN_PAUSE
} audply_main_buttons_enum;

#define MAX_DAF_VIEW_FIELDS   10

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
#define  AUDPLY_LYRIC_MAX_LINE_COUNT      200   /* pre-defined number of lyirc lines */
#define  AUDPLY_LYRIC_STR_BUFF_MAX_SIZE   5000  /* pre-defined max lyric string buffer size : bytes */
#define  AUDPLY_LYRIC_TMP_BUFF_MAX_SIZE   128   /* pre-defined max lyric buffer size for one line : bytes ; must be two bytes aligned */

typedef enum
{
    LINE_START,
    LINE_END,
    TAG_START,
    TAG_END,
    TAG_LYRIC1,
    TAG_TIME1,
    TAG_TIME2,
    TAG_TIME3,
    TAG_MS,
    TAG_ID_AR,
    TAG_ID_TI,
    TAG_ID_AL,
    TAG_ID_BY,
    TAG_ID_OFFSET
} audply_lyric_parse_status_enum;

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    AUDPLY_PEN_NONE,
    AUDPLY_PEN_LSK,
    AUDPLY_PEN_RSK,
    AUDPLY_PEN_SEEK,
    AUDPLY_PEN_MAIN_PREV,
    AUDPLY_PEN_MAIN_NEXT,
    AUDPLY_PEN_MAIN_STOP,
    AUDPLY_PEN_MAIN_PLAY,
    AUDPLY_PEN_MAIN_SETTING,
//    AUDPLY_PEN_MAIN_PLAY_LIST,
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__    
    AUDPLY_PEN_MAIN_REPEAT,
    AUDPLY_PEN_MAIN_SHUFFLE,
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
    AUDPLY_PEN_MAIN_VOLUME_INC,
    AUDPLY_PEN_MAIN_VOLUME_DEC,
    AUDPLY_PEN_COUNT
} AUDPLY_PEN_STATE;
#endif

#define MAX_PLAY_LIST_NUM  1024
#define MAX_PLAY_LIST_BYTES   (MAX_PLAY_LIST_NUM/8)

#define ClrBitSet( index, bitset )     ((bitset)[(index)>>3] &= ~(1<<((index)&0x07)))
#define SetBitSet( index, bitset )     ((bitset)[(index)>>3] |= (1<<((index)&0x07)))
#define IsBitSetOn( index, bitset )    ((bitset)[(index)>>3] & (1<<((index)&0x07)))


#define BUILD_CACHE_SIZE (2*1024)  /*audio build cache size*/
#define BUILD_CACHE_FILE_BUF_SIZE 1024 /*audio build cache file buffer size*/
#define BUILD_CACHE_PROC_BUF_SIZE (32*1024) /*audio build cache process buffer size*/

typedef enum
{
    
#ifdef DAF_DECODE
    DAF_FORMAT_FOR_CACHE,
#ifdef MUSICAM_DECODE    
    MP2_FORMAT_FOR_CACHE,
#endif
#endif 
    AMR_FORMAT_FOR_CACHE,
#ifdef AAC_DECODE
    AAC_FORMAT_FOR_CACHE,
#endif 
#ifdef AMRWB_DECODE
    AWB_FORMAT_FOR_CACHE,
#endif 
#ifdef __DRM_V02__
    ODF_FORMAT_FOR_CACHE,
#endif
    /*number of file types,counting from BEGINING, defines in 
    audio_file_lower_exts that need to build cache to seek*/
    NEED_TO_BUILD_CACHE_NUM
} need_to_build_cache_format_enum;

typedef enum
{
    
    AMR_FORMAT_NOT_SUPPORT_A2DP,
    NOT_SUPPORT_A2DP_NUM
} not_support_a2dp_enum;

typedef enum
{
    AUDPLY_PLAYER_SETTING =0 ,
    AUDPLY_DISPLAY_SETTING,
    AUDPLY_SOUND_EFFECT_SETTING,
    AUDPLY_BT_SETTING  
}two_layer_settings_enum;

#ifdef __MMI_SLIM_AUDIO_PLAYER__
#define PLAY_LIST_BUFF_SIZE   8
#else 
#define PLAY_LIST_BUFF_SIZE   16
#endif 

#define PLAY_LIST_RECORD_SIZE ((FMGR_MAX_PATH_LEN+1)*ENCODING_LENGTH)
#ifdef __MMI_MY_FAVORITE__
#define MUSIC_FOLDER L"Audio\\My Music\\"
#else
#define MUSIC_FOLDER L"My Music\\"
#endif /* __MMI_MY_FAVORITE__ */

typedef enum
{
#ifdef DAF_DECODE
    AUDPLY_AUDIO_FILE_TYPE_DAF,
#ifdef MUSICAM_DECODE    
    AUDPLY_AUDIO_FILE_TYPE_MP2,
#endif
#endif 
    AUDPLY_AUDIO_FILE_TYPE_AMR,
#ifdef AAC_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AAC,
#endif 
#ifdef AMRWB_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AWB,
#endif 
    AUDPLY_AUDIO_FILE_TYPE_WAV,
    AUDPLY_AUDIO_FILE_TYPE_MID,
    AUDPLY_AUDIO_FILE_TYPE_IMY,
//    AUDPLY_AUDIO_FILE_TYPE_VM,
#ifdef AIFF_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AIF,
    AUDPLY_AUDIO_FILE_TYPE_AIFF,
    AUDPLY_AUDIO_FILE_TYPE_AIFC,
#endif /* AIFF_DECODE */
#ifdef AU_DECODE
    AUDPLY_AUDIO_FILE_TYPE_AU,
    AUDPLY_AUDIO_FILE_TYPE_SND,
#endif /* AU_DECODE */
#ifdef AAC_DECODE
    AUDPLY_AUDIO_FILE_TYPE_M4A,
#endif 
#ifdef YAMAHA_MA3
    AUDPLY_AUDIO_FILE_TYPE_MMF,
#endif 
#ifdef WMA_DECODE
    AUDPLY_AUDIO_FILE_TYPE_WMA,
#endif 
#if defined(__MMI_PURE_AUDIO__)
    AUDPLY_AUDIO_FILE_TYPE_3GP,
    AUDPLY_AUDIO_FILE_TYPE_MP4,
#endif
#ifdef __DRM_V02__
    AUDPLY_AUDIO_FILE_TYPE_ODF,
#endif
    NO_AUDIO_FILE_TYPES
} audply_audio_file_type_enum;

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    S16 x;
    S16 y;
} audply_point_struct;

typedef struct
{
    const audply_point_struct *points;
    S16 num;
} audply_polygon_area_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

typedef struct
{
    U16 bg_image_id;
    U8 text_border_color_r, text_border_color_g, text_border_color_b;
    U8 text_fg_color_r, text_fg_color_g, text_fg_color_b;
    U8 text_bg_color_r, text_bg_color_g, text_bg_color_b;
    S16 title_x, title_y;
    S16 title_w, title_h;
    S16 time_x, time_y;
    S16 time_w, time_h;
    S16 file_index_x, file_index_y;
    S16 file_index_w, file_index_h;
    S16 playlisticon_x, playlisticon_y;
    U16 playlisticon_images_id[NO_OF_LIST];
    S16 volumebar_x, volumebar_y, volumebar_ind_len;
    U8  volumebar_direction;
    U16 volumebar_ind_image_id;
    S16 progressbar_x, progressbar_y;
    U16 progressbar_image_id;
    U16 progressbar_fail_image_id;
    S16 prev_button_x, prev_button_y;
    U16 prev_button_on_image_id, prev_button_off_image_id, prev_button_disabled_image_id, prev_button_down_image_id;
    S16 next_button_x, next_button_y;
    U16 next_button_on_image_id, next_button_off_image_id, next_button_disabled_image_id, next_button_down_image_id;
    S16 play_button_x, play_button_y;
    U16 play_button_on_image_id, play_button_off_image_id, play_button_disabled_image_id, play_button_down_image_id;
    U16 pause_button_on_image_id, pause_button_down_image_id;
    S16 stop_button_x, stop_button_y;
    U16 stop_button_on_image_id, stop_button_off_image_id, stop_button_disabled_image_id, stop_button_down_image_id;
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    S16 animation_x, animation_y;
    U16 animation_image_id;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    S16 spectrum_display_x, spectrum_display_y;
    S16 spectrum_display_w, spectrum_display_h;
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    U8 lyric_fg_color_r, lyric_fg_color_g, lyric_fg_color_b;
    U8 lyric_border_color_r, lyric_border_color_g, lyric_border_color_b;
    S16 lyric_display_x, lyric_display_y;
    S16 lyric_display_w, lyric_display_h;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
#if defined( __MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) 
    U8 spectrum_lyrics_exclusive ;
#endif
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
    S16 repeat_x, repeat_y;
    U16 repeat_off_up_image_id, repeat_all_up_image_id, repeat_one_up_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    U16 repeat_off_down_image_id, repeat_all_down_image_id, repeat_one_down_image_id;
#endif
    S16 shuffle_x, shuffle_y;
    U16 shuffle_off_up_image_id, shuffle_on_up_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    U16 shuffle_off_down_image_id, shuffle_on_down_image_id;    
#endif
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 
    S16 volume_inc_x, volume_inc_y;
    U16 volume_inc_up_image_id, volume_inc_down_image_id;
    S16 volume_dec_x, volume_dec_y;
    U16 volume_dec_up_image_id, volume_dec_down_image_id;
#ifdef __MMI_TOUCH_SCREEN__
    S16 setting_x, setting_y;
    U16 setting_up_image_id, setting_down_image_id;
    audply_polygon_area_struct seek_area;
    audply_polygon_area_struct volume_inc_area;
    audply_polygon_area_struct volume_dec_area;
    audply_polygon_area_struct prev_button_area;
    audply_polygon_area_struct next_button_area;
    audply_polygon_area_struct play_button_area;
    audply_polygon_area_struct stop_button_area;
    audply_polygon_area_struct setting_area;
//    audply_polygon_area_struct play_list_area;
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__    
    audply_polygon_area_struct repeat_area;
    audply_polygon_area_struct shuffle_area;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */     
#endif /* __MMI_TOUCH_SCREEN__ */ 
    U8 up_key_mapping, down_key_mapping, left_key_mapping, right_key_mapping;
} audply_skin_struct;

#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
typedef struct
{
    U16 bg_image_id;
    U8 text_border_color_r, text_border_color_g, text_border_color_b;
    U8 text_fg_color_r, text_fg_color_g, text_fg_color_b;
    U8 text_bg_color_r, text_bg_color_g, text_bg_color_b;
    S16 title_x, title_y;
    S16 title_w, title_h;
    S16 time_x, time_y;
    S16 time_w, time_h;
    S16 file_index_x, file_index_y;
    S16 file_index_w, file_index_h;
    S16 playlisticon_x, playlisticon_y;
    U16 playlisticon_images_id[NO_OF_LIST];
    S16 volumebar_x, volumebar_y, volumebar_ind_len;
    U8  volumebar_direction;
    U16 volumebar_ind_image_id;
    S16 prev_button_x, prev_button_y;
    U16 prev_button_on_image_id, prev_button_off_image_id, prev_button_disabled_image_id, prev_button_down_image_id;
    S16 next_button_x, next_button_y;
    U16 next_button_on_image_id, next_button_off_image_id, next_button_disabled_image_id, next_button_down_image_id;
    S16 play_button_x, play_button_y;
    U16 play_button_on_image_id, play_button_off_image_id, play_button_disabled_image_id, play_button_down_image_id;
    U16 pause_button_on_image_id, pause_button_down_image_id;
    S16 stop_button_x, stop_button_y;
    U16 stop_button_on_image_id, stop_button_off_image_id, stop_button_disabled_image_id, stop_button_down_image_id;
    U8 up_key_mapping, down_key_mapping, left_key_mapping, right_key_mapping;
} audply_sub_skin_struct;
#endif

//#define PRESENT_LIST_FILE ((g_audply.present_list == LIST_FROM_PHONE) ? phone_list_name: card_list_name)
//#define PRESENT_LIST_ROOT ((g_audply.present_list == LIST_FROM_PHONE) ? root_dir_phone: root_dir_card)
#define MARK_DRIVE(path) ((path)[0] = (UI_character_type)g_audply.present_list)
#define MARK_DRIVE_PS8(path) ((path)[0] = (S8)g_audply.present_list, (path)[1] = 0)
#define MARK_LNAME(path) ((path)[0] = L'L')
#define MARK_SNAME(path) ((path)[0] = L'S')
#define MARK_LNAME2(path) ((path)[0] = 'L',(path)[1] = 0)
#define MARK_SNAME2(path) ((path)[0] = 'S',(path)[1] = 0)
#define IS_LNAME(path) ((path)[0] == L'L')
#define IS_SNAME(path) ((path)[0] == L'S')
#define IS_LNAME2(path) ((path)[0] == 'L' && (path)[1] == 0)
#define IS_SNAME2(path) ((path)[0] == 'S' && (path)[1] == 0)
#define EOS(nob) ((nob)>1 ? ((nob)>>1)-1: 0)


typedef enum
{
    AUDPLY_ACTION_COPY,
    AUDPLY_ACTION_DELETE,
    AUDPLY_ACTION_DELETE_FAIL,
    AUDPLY_ACTION_RENAME,
    AUDPLY_ACTION_MOVE,
    MAX_AUDPLY_ACTION
} AUDPLY_UPDATE_LIST_ACTION_ENUM;

#endif /* __MMI_AUDIO_PLAYER__ */ 

typedef enum
{
    STATE_IDLE,
    STATE_PLAY,
    STATE_PAUSED,
    NO_OF_STATE
} audply_state_enum;

typedef enum
{
	AUDPLY_SETTING_STORAGE,
	AUDPLY_SETTING_LIST_AUTO_GEN,
#ifndef __MMI_SLIM_AUDIO_PLAYER__
	AUDPLY_SETTING_SKIN,
#endif
	AUDPLY_SETTING_REPEAT,
	AUDPLY_SETTING_SHUFFLE,
#ifndef __MMI_AUDIO_PLAYER_ON_SUBLCD__    	
	AUDPLY_SETTING_BACKGROUND_PLAY,
#endif
#ifdef __MMI_AUDIO_EQUALIZER__
    AUDPLY_SETTING_EQUALIZER,
#endif
#ifdef __MMI_AUDIO_TIME_STRETCH__
    AUDPLY_SETTING_TIME_STRETCH,
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    AUDPLY_SETTING_3D_EFFECT,
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    AUDPLY_SETTING_AUDIO_SURROUND,
#endif
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    AUDPLY_SETTING_SPECTRUM_DISPLAY,
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    AUDPLY_SETTING_LYRICS_DISPLAY,
#endif
#ifdef __MMI_A2DP_SUPPORT__
    AUDPLY_SETTING_BLUETOOTH_A2DP_OUTPUT,
    AUDPLY_SETTING_BLUETOOTH_A2DP_HEADSET,
#endif /* __MMI_A2DP_SUPPORT__ */
    AUDPLY_SETTING_ITEM_COUNT
} AUDPLY_SETTING_ITEM_ENUM;

#endif /* AUDIO_PLAYER_DEF_H */ 


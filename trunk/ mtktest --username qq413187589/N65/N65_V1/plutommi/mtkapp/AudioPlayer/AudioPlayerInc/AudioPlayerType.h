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
*  AudioPlayerType.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player type definition
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
 * created by clearfsimport
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

#ifndef _AUDIO_PLAYER_TYPE_H
#define _AUDIO_PLAYER_TYPE_H

/*
 * Need to include:
 * (1) gui_data_types.h
 * (3) kal_release.h
 * (4) Conversions.h
 * (5) FrameworkStruct.h
 * (6) GlobalConstants.h
 * (7) FileMgr.h
 * (8) AudioPlayerDef.h
 */
#ifdef __MMI_AUDIO_PLAYER__

#include "aud_id3_parser.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

typedef struct
{
    S32 n_total_items;
    S32 pick_index;
    S32 pick_count;
    U8 bitset[MAX_PLAY_LIST_BYTES];
    U32 duration; /*song duration in MS*/
    U32 progress_speed; /*progress speed choosed according to duration*/

    /* settings */
    U8 list_auto_gen;
    U8 preferred_list;
    U8 skin;
    U8 repeat_mode;     /* 0: off, 1: repeat one, 2: repeat all */
    U8 random_mode;     /* 0: off, 1: on */
    U8 background_play; /* o: off, 1: on */
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__ 
    U8 spectrum_style;  /* 0: off,  1, 2(, 3): styles */
#endif 
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    U8 lyrics_display;  /* o: off, 1: on */
#endif

    /* cmd & states */
    UI_character_type title[FMGR_MAX_FILE_LEN];
#ifdef __MMI_SUBLCD__
    UI_character_type sub_title[FMGR_MAX_FILE_LEN];
#endif
    UI_character_type filefullname[FMGR_MAX_PATH_LEN + 1];
    /*the file name that cache content belongs to*/
    UI_character_type prev_filefullname[FMGR_MAX_PATH_LEN + 1];
    BOOL file_name_identical;
    U8 state;
    U8 state_before_longpress;
    BOOL seekable; /*indicate if it is seekable or not*/
    BOOL need_to_build_cache; /*need to build cache to seek*/

    U8* audio_cache_file_buf_p ; /*ptr for build cache file buffer*/
    U8* audio_cache_proc_buf_p ; /*ptr for build cache process buffer*/

    /*except the two kinds are  non-seekable formats so do not need to build cache either*/
    BOOL restorable;
    BOOL need_restore; /*indicate if it needs to be restored to suspending point*/
    BOOL wait_next;
    BOOL need_replay;  /*inidcate if it needs to be replayed once it is suspeneded*/
    BOOL continue_playing; /*indicate need to pick next song to play after previous song is not playable*/

#if defined(MT6223) || defined(MT6223P)
    BOOL support_A2DP;
#endif

    BOOL in_main_screen;
    BOOL in_list_screen;
    U8 volume;

    /* buffer for dynamic load */
    S32 buff_head;
    S32 n_buff_items;
    UI_character_type buff_filename[PLAY_LIST_BUFF_SIZE][FMGR_MAX_FILE_LEN];

    /* duration */
    U32 old_play_time;  /*the lastest play time shown on main screen*/
    U32 new_play_time;  /*the latest play time get from hardware*/

    /* present play list */
    U8 present_list;
    BOOL is_subLCD_shown;

#ifdef __MMI_AUDIO_TIME_STRETCH__
    U16 speed;
    U8 speed_set_times;
#endif /* __MMI_AUDIO_TIME_STRETCH__ */ 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    BOOL in_sub_screen;       /*audio player on sub LCD main screen*/
    BOOL in_sub_list_screen; /*audio player on sub LCD play list screen*/
#endif
} audply_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
} audply_main_title_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
} audply_main_time_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
} audply_main_file_index_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 list_icon[NO_OF_LIST];
} audply_main_playlisticon_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    S16 ind_len;
    PU8 ind_img;
    U8  bar_direction; /* 0:horizonal, 1: vertical */
} audply_main_volumebar_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 img;
    PU8 img_fail ;
}audply_main_progressbar_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
    BOOL down;
} audply_main_volumectrl_struct;

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
    BOOL down;
} audply_main_setting_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 on_img, off_img, disabled_img, down_img;
} audply_main_button_struct;

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
typedef struct
{
    S16 x, y;
    S16 w, h;
    S32 img_handle;
    PU8 animation_img;
} audply_main_animation_struct;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 

#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 off_up_img, all_up_img, one_up_img;
#ifdef __MMI_TOUCH_SCREEN__      
    PU8 off_down_img, all_down_img, one_down_img;
    BOOL down;
#endif /* __MMI_TOUCH_SCREEN__ */
} audply_main_repeat_struct;
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 off_up_img, on_up_img;
#ifdef __MMI_TOUCH_SCREEN__  
    PU8 off_down_img, on_down_img;
    BOOL down;
#endif /*__MMI_TOUCH_SCREEN__*/
} audply_main_shuffle_struct;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__

#define FIND_TAG_END                                              \
do{                                                                 \
   if ((cur_char = (U16*)mmi_ucs2chr((S8*)cur_char, L']')) == NULL)\
         return TRUE;                                             \
   else                                                           \
      status = TAG_END;                                           \
}while(0)

#define TRIM_LEFT                                                  \
do{                                                                  \
   cur_char = (U16*)mmi_ucs2trim_left((S8*)cur_char,(S8*)L" \t\r\n");\
   if (!cur_char)                                                  \
      return TRUE;                                                 \
}while(0)

typedef struct audply_lyric_line
{
    S32 time;
    S8 *line_lyric1;
    struct audply_lyric_line *next;
} audply_lyric_line_struct;

typedef struct
{
    BOOL is_ready;
    S32 lyric_count;
    UI_character_type lyric_file_path[(FMGR_MAX_PATH_LEN + 5) *ENCODING_LENGTH];
    audply_lyric_line_struct lyric[AUDPLY_LYRIC_MAX_LINE_COUNT];

    audply_lyric_line_struct *first_line;
    audply_lyric_line_struct *cur_line;
    S32 offset_time;
    mmi_chset_enum lrc_encoding_chset;
} audply_lyric_struct;

typedef struct
{
    S16 start_x;
    S16 start_y;
    S32 width;
    S32 height;
    color lyric_fg_color;
    color lyric_border_color;
    GDI_HANDLE target_layer;
} audply_lyric_printing_struct;

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)

typedef struct
{
    U32 file_offset;
    U32 cache_offset;
    U32 cache_size;
    U32 cache_limit;
    PS8 cache_buffer_ptr;
} audply_auto_update_cache_struct;

typedef struct
{
    UI_character_type old_path[FMGR_MAX_PATH_LEN];
    UI_character_type new_path[FMGR_MAX_PATH_LEN];
    FS_HANDLE present_list;
    FS_HANDLE temp_file;
    U32 counter;
    U32 deleted;
    U32 offset;
    U32 old_path_len;
    U8 action_type;
    MMI_BOOL is_folder;
} audply_auto_update_struct;
#endif /* defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */

#endif /* __MMI_AUDIO_PLAYER__ */ 

#endif /* _AUDIO_PLAYER_TYPE_H */ 


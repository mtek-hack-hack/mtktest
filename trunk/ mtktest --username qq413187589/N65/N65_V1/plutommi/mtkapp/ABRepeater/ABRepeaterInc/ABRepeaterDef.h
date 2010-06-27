/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  ABRepeater.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repeater main screen
*
* Author:
* -------
*  Tarun Bakshi
*
********************************************************************************************/

#ifndef AB_REPEATER_DEF_H
#define AB_REPEATER_DEF_H

#ifdef __MMI_AB_REPEATER__

#include "ABRepeaterResDef.h"

typedef enum
{
    ABREPEAT_MAIN_DISABLED = -1,
    ABREPEAT_MAIN_PLAY = 0,
    ABREPEAT_MAIN_REWIND,
    ABREPEAT_MAIN_FORWARD,
    ABREPEAT_MAIN_STOP,
    ABREPEAT_MAIN_PAUSE,
    NO_OF_ABREPEAT_MAIN_AUDIO_BUTTONS
} abrepeat_main_buttons_enum;

typedef enum
{

    AB_SECTION0 = 0,
    AB_SECTION1,
    AB_SECTION2,
    AB_SECTION3,
    AB_SECTION4,
    AB_SECTION5,
    AB_SECTION6,
    AB_SECTION7,
    AB_SECTION8,
    AB_SECTION9,
    MAX_AB_POINT
} abrepeat_absection_enum;

#define MAX_VOL_LEVEL      7

#define MAX_AB_SETTING_SCREEN_DIGITS      13
//manish for avoiding crasing in case of big file names
#define MAX_AB_STORAGE_PATH_LEN   FMGR_MAX_PATH_LEN
typedef enum
{
    AB_STATE_IDLE,
    AB_STATE_PLAY,
    AB_STATE_PAUSED,
    AB_NO_OF_STATE
} abrepeat_state_enum;

/* manish adding this enum for Interrupts handling */
typedef enum
{
    NOTHING = 0,
    PLAY_COMPLETED,
    PLAY_STOPPED
} abrepeat_temp_status_enum;

typedef enum
{
    AB_SECTION_DISABLED = -1,
    AB_SECTION_FIRST_SET,
    AB_SECTION_COMPLETE_SET,
    AB_SECTION_NON_PLAYING,
    AB_SECTION_PLAYING
} abrepeat_absection_draw_state;

typedef enum
{
    LIST_FROM_PHONE_AB,
    LIST_FROM_CARD_AB,
    NO_OF_LIST_AB
} abrepeat_playlist_enum;

typedef enum
{
    AB_SET_IDLE = 0,
    AB_SET_PARTIAL
} abrepeat_abset_state_enum;

typedef struct
{
    S16 ab_section_x, ab_section_y;
    U16 ab_section_button_img_id;
} abrepeat_absection_button_skin_struct;

typedef struct
{
    U16 main_bg_img_id;
    U8 text_ab_border_color_r, text_ab_border_color_g, text_ab_border_color_b;
    U8 text_main_fg_color_r, text_main_fg_color_g, text_main_fg_color_b;
    U8 text_main_bg_color_r, text_main_bg_color_g, text_main_bg_color_b;
    U8 audio_bg_color_r, audio_bg_color_g, audio_bg_color_b;
    U8 absection_color_r, absection_color_g, absection_color_b;
    S16 title_ab_x, title_ab_y;
    S16 title_ab_w, title_ab_h;
    S16 volumebar_ab_x, volumebar_ab_y, volumebar_ab_ind_left;
    U16 volumebar_ab_ind_image_id;
    S16 volume_dec_x,volume_dec_y;
    U16 volume_dec_button_up_img_id,volume_dec_button_down_img_id;
    
    S16 volume_inc_x,volume_inc_y;
    U16 volume_inc_button_up_img_id,volume_inc_button_down_img_id;
    
    S16 rewind_button_x, rewind_button_y;
    U16 rewind_button_up_image_id, rewind_button_down_image_id;

    S16 forward_button_x, forward_button_y;
    U16 forward_button_up_image_id, forward_button_down_image_id;

    S16 play_ab_button_x, play_ab_button_y;
    U16 play_ab_button_up_image_id, play_ab_button_down_image_id;
    U16 pause_ab_button_up_image_id, pause_ab_button_down_image_id;

    S16 stop_ab_button_x, stop_ab_button_y;
    U16 stop_ab_button_up_image_id, stop_ab_button_down_image_id;

    S16 once_always_button_x, once_always_button_y;
    U16 once_always_button_up_img_id, once_always_button_down_img_id;
    U16 once_always_button_off_up_img_id, once_always_button_off_down_img_id;
    U16 once_always_button_disable_img_id;

    S16 mode_set_button_x, mode_set_button_y;
    U16 setting_mode_button_up_image_id, setting_mode_button_down_image_id;
    U16 play_mode_button_up_image_id, play_mode_button_down_image_id;

    S16 progress_bar_x, progress_bar_y, progress_bar_ind_off_y;
    U16 progress_bar_img_id, progress_bar_ind_img_id;
    S16 ab_aud_file_rect_x, ab_aud_file_rect_y;
    U16 progress_bar_rect_img_id;

    abrepeat_absection_button_skin_struct ab_section_button_skin[MAX_AB_POINT];
    U16 absection_playing_img_id;
    U16 absection_partial_set_img_id;
    U16 absection_partial_set_down_img_id;
    U16 absection_set_sction_img_id;
    U16 absection_set_sction_down_img_id;
    U16 absection_nonset_section_img_id;
    U16 absection_nonset_section_down_img_id;
    U8 up_ab_key_mapping, down_ab_key_mapping, left_ab_key_mapping, right_ab_key_mapping;

} abrepeat_skin_struct;

#define NO_OF_AB_SKIN   1


#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    AB_PEN_NONE = -1,
    AB_PEN_SECTION0,
    AB_PEN_SECTION1,
    AB_PEN_SECTION2,
    AB_PEN_SECTION3,
    AB_PEN_SECTION4,
    AB_PEN_SECTION5,
    AB_PEN_SECTION6,
    AB_PEN_SECTION7,
    AB_PEN_SECTION8,
    AB_PEN_SECTION9,
    AB_PEN_LSK,
    AB_PEN_RSK,
    AB_PEN_MAIN_PLAY,
    AB_PEN_MAIN_STOP,
    AB_PEN_MAIN_FORWARD,
    AB_PEN_MAIN_REWIND,
    AB_PEN_SET_MODE,
    AB_PEN_SET_REPLAY,
    AB_PEN_VOLUME_INC,
    AB_PEN_VOLUME_DEC,
    AB_PEN_ICON_OBJ_COUNT

}abrepeat_pen_obj_enum;

#endif /* __MMI_TOUCH_SCREEN__ */ 

typedef enum
{
    AB_SETTING_MODE,
    AB_PLAY_MODE
}abrepeat_mode_enum;

typedef enum
{
    AB_MAIN_LSK,
    AB_MAIN_RSK
}abrepeat_key_type_enum;

typedef enum
{
    AB_REPLAY_DISABLE,
    AB_REPLAY_ONCE,
    AB_REPLAY_ALWAYS
}abrepeat_replay_btn_state_enum;


#define ABR_CACHE_SIZE (2058 + CACHE_HEADER_SIZE)
#define ABR_FILE_BUF_SIZE 1024
#define ABR_PROC_BUF_SIZE (32*1024)
#define ABREPEAT_APP_ASM_BUF_SIZE (40*1024)//(ABR_FILE_BUF_SIZE + ABR_PROC_BUF_SIZE)

#define ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY  200
#endif /* __MMI_AB_REPEATER__ */ 

#endif /* AB_REPEATER_DEF_H */ 


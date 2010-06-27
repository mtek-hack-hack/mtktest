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
*  ABRepeaterType.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repeater type definition
*
* Author:
* -------
*  Tarun Bakshi
*
*************************************************************************************/

#ifndef _AB_REPEATER_TYPE_H
#define _AB_REPEATER_TYPE_H

/*
 * Need to include:
 * (1) FileSystemDef.h
 * (2) FileMgr.h
 */
#ifdef __MMI_AB_REPEATER__

typedef struct 
{
    S16 pos_x;
    S16 pos_y;
    S16 width;
    S16 height;
}abrepeat_area_struct;

typedef struct 
{
    abrepeat_area_struct area;
    PU8 img;
}abrepeat_icon_struct;

typedef struct 
{ 
    abrepeat_area_struct area;
    PU8 up_img;
    PU8 down_img;
}abrepeat_up_down_icon_struct;

typedef struct 
{
    abrepeat_area_struct area;
    PU8 up_img;
    PU8 down_img;
    PU8 disable_img;
}abrepeat_disable_icon_struct;

typedef struct 
{
    abrepeat_area_struct area;
    PU8 on_up_img, on_down_img;
    PU8 off_up_img, off_down_img;
    PU8 disable_img;
}abrepeat_onoff_disable_icon_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    S16 ind_left;
    PU8 ind_img;
} abrepeat_volumebar_struct;

typedef struct
{
    S16 x, y;
    S16 w, h, ind_off_y, ind_w, ind_h;
    PU8 img, ind_img;
} abrepeat_progress_bar_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 img;
} abrepeat_progress_bar_rect_struct;

typedef struct
{
    UI_character_type title[FMGR_MAX_FILE_LEN + 1];
    UI_character_type filefullname[FMGR_MAX_PATH_LEN + 1];  
    
    U32 total_offset;    
    U32 prgbar_cur_offset;
    U32 cur_setab_start_offset;
    U32 fwd_rew_units;    
#ifdef __MTK_TARGET__
    U32 audio_checksum; /*move here for preplay check*/
    U32 audio_file_size;    /*file size for validation process and preplay check*/
#endif

    BOOL is_main_sel_btn_down;
    BOOL is_absection_sel_btn_down;
    BOOL is_init_scrolling_text;
    BOOL is_replay_on;
    BOOL is_short_name;
    
    S16 curr_play_section;
    S16 curr_set_section;

    U8 volume;
    U8 skin;
    U8 state;
    signed char main_selected_button;
    signed char cur_mode;
    signed char abkey_state;
    signed char replay_btn_state; 
} abrepeat_struct;

typedef struct  
{
#ifdef __MMI_TOUCH_SCREEN__
    abrepeat_area_struct area_lsk;
    abrepeat_area_struct area_rsk;
#endif /*__MMI_TOUCH_SCREEN__*/
    abrepeat_area_struct area_title;    
    abrepeat_icon_struct absection_btns[MAX_AB_POINT];

    abrepeat_up_down_icon_struct vol_inc;
    abrepeat_up_down_icon_struct vol_dec;  
    abrepeat_up_down_icon_struct set_mode;
    abrepeat_up_down_icon_struct play_mode;
    abrepeat_up_down_icon_struct audio_btns[NO_OF_ABREPEAT_MAIN_AUDIO_BUTTONS];
    
    abrepeat_onoff_disable_icon_struct btn_replay; 

    abrepeat_progress_bar_struct progress_bar;    
    abrepeat_progress_bar_rect_struct progress_bar_rect;
    abrepeat_volumebar_struct volumebar;

    PU8 main_bg_img;
    PU8 absection_play_img;
    PU8 absection_partial_set_img;
    PU8 absection_partial_set_down_img;
    PU8 absection_set_img;
    PU8 absection_set_down_img;
    PU8 absection_nonset_img;
    PU8 absection_nonset_down_img;
    UI_string_type main_LSK_text;
    UI_string_type main_RSK_text;

    color text_bg_color;
    color text_fg_color;
    color text_border_color;
    color audio_file_played_color; 
    color absection_color;
    
    S16 operation_button_w;
    S16 operation_button_h;

    U8 main_skin_index;

#ifdef __MMI_TOUCH_SCREEN__
    signed char touch_obj;
#endif /*__MMI_TOUCH_SCREEN__*/
    

}abrepeat_main_scr_struct;


typedef struct
{
    U32 abstart;
    U32 abend;
    U16 keyindex;
} ab_data_struct;


#endif /* __MMI_AB_REPEATER__ */ 

#endif /* _AB_REPEATER_TYPE_H */ 


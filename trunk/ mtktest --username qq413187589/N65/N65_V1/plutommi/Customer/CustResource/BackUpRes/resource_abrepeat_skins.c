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
*	resource_abrepeat_skins.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repater main screen skin settings
*
* Author:
* -------
*	Tarun Bakshi
*
***********************************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_AB_REPEATER__
#include "gdi_lcd_config.h"

// dependent headers for ABRepeaterDef.h"
#include "FrameworkStruct.h"
#include "GlobalConstants.h"
#include "FileMgr.h"

#include "ABRepeaterResDef.h"
#include "ABRepeaterDef.h"
#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) )
const abrepeat_skin_struct g_abrepeat_skins[] =
{
    {	
        IMG_ID_ABREPEAT_MAIN_SKIN1_BG, //main_bg_img_id;
        64,0,128,//text_ab_border_color_r, text_ab_border_color_g, text_ab_border_color_b;
        255,255,0,//text_main_fg_color_r, text_main_fg_color_g, text_main_fg_color_b;
        192,192,192,//text_main_bg_color_r, text_main_bg_color_g, text_main_bg_color_b;
        255,248,220,//audio_bg_color_r, audio_bg_color_g, audio_bg_color_b;
        238,130,238,//absection_color_r,absection_color_g,absection_color_b;
        12,2,//title_ab_x, title_ab_y;
        104,14,//title_ab_w, title_ab_h;
        5,99,6,//volumebar_ab_x, volumebar_ab_y, volumebar_ab_ind_left;
        IMG_ID_ABREPEAT_VOLUME,//volumebar_ab_ind_image_id;
        
        5,108,//volume_dec_x,volume_dec_y;
        IMG_ID_ABREPEAT_VOLUME_DEC_UP,IMG_ID_ABREPEAT_VOLUME_DEC_DOWN, //volume_dec_button_up_img_id,volume_dec_button_down_img_id;
        
        23,108, //volume_inc_x,volume_inc_y;
        IMG_ID_ABREPEAT_VOLUME_INC_UP,IMG_ID_ABREPEAT_VOLUME_INC_DOWN, //volume_inc_button_up_img_id,volume_inc_button_down_img_id;
        
        67,94,//rewind_button_x, rewind_button_y;
        IMG_ID_ABREPEAT_REW_UP,IMG_ID_ABREPEAT_REW_DOWN,//rewind_button_up_image_id, rewindprev_button_down_image_id;
        
        82,94,//forward_button_x, forward_button_y;
        IMG_ID_ABREPEAT_FWD_UP,IMG_ID_ABREPEAT_FWD_DOWN,//forward_button_up_image_id, forward_button_down_image_id;
        
        31,94,//play_ab_button_x, play_ab_button_y;
        IMG_ID_ABREPEAT_PLAY_UP,IMG_ID_ABREPEAT_PLAY_DOWN,//play_ab_button_up_image_id, play_ab_button_down_image_id;
        IMG_ID_ABREPEAT_PAUSE_UP,IMG_ID_ABREPEAT_PAUSE_DOWN,//pause_ab_button_up_image_id, pause_ab_button_down_image_id;
        52,94 ,//stop_ab_button_x, stop_ab_button_y;
        IMG_ID_ABREPEAT_STOP_UP,IMG_ID_ABREPEAT_STOP_DOWN,//stop_ab_button_up_image_id, stop_ab_button_down_image_id;
        
        101,94,//once_always_button_x,once_always_button_y;
        IMG_ID_ABREPEAT_REPEAT_UP,IMG_ID_ABREPEAT_REPEAT_DOWN,//once_always_button_up_img_id,once_always_button_down_img_id;
        IMG_ID_ABREPEAT_REPEAT_OFF_UP,IMG_ID_ABREPEAT_REPEAT_OFF_DOWN,
        IMG_ID_ABREPEAT_REPEAT_DISABLE,//once always button disabled(Setting Screen)
        
        115,99, //mode_set_button_x, mode_set_button_y;
        IMG_ID_ABREPEAT_SETTING_MODE_UP,IMG_ID_ABREPEAT_SETTING_MODE_DOWN,//setting_mode_button_up_image_id, setting_mode_button_down_image_id;
        IMG_ID_ABREPEAT_PLAY_MODE_UP,IMG_ID_ABREPEAT_PLAY_MODE_DOWN,//play_mode_button_up_image_id, play_mode_button_down_image_id;	
        
        8,17,3,//progress_bar_x,progrss_bar_y;
        IMG_ID_ABREPEAT_PROGRESS_BAR,IMG_ID_ABREPEAT_INDICATOR,//progress_bar_img_id,progress_bar_ind_img_id;
        16,23,//ab_aud_file_rect_x,ab_aud_file_rect_y;    
        IMG_ID_ABREPEAT_PROG_BAR_EMPTY,
            
        { 
            102,65,IMG_ID_ABREPEAT_BUTTON0,
            10,40,IMG_ID_ABREPEAT_BUTTON1,
            33,40,IMG_ID_ABREPEAT_BUTTON2,
            56,40,IMG_ID_ABREPEAT_BUTTON3,
            79,40,IMG_ID_ABREPEAT_BUTTON4,
            102,40,IMG_ID_ABREPEAT_BUTTON5,
            10,65,IMG_ID_ABREPEAT_BUTTON6,
            33,65,IMG_ID_ABREPEAT_BUTTON7,
            56,65,IMG_ID_ABREPEAT_BUTTON8,
            79,65,IMG_ID_ABREPEAT_BUTTON9,
        },//ab_section_button_skin[MAX_AB_POINT];
        
        IMG_ID_ABREPEAT_ABSECTION_PLAYING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING_DOWN,
        IMG_ID_ABREPEAT_AB_SETSECTION,
        IMG_ID_ABREPEAT_AB_SETSECTION_DOWN,
        IMG_ID_ABREPEAT_AB_NONSETSECTION,
        IMG_ID_ABREPEAT_AB_NONSETSECTION_DOWN,
        //up_ab_key_mapping, down_ab_key_mapping, left_ab_key_mapping, right_ab_key_mapping;
        ABREPEAT_MAIN_PLAY, ABREPEAT_MAIN_STOP, ABREPEAT_MAIN_REWIND, ABREPEAT_MAIN_FORWARD // up, down, left, right key mapping
        
    }
};
#elif ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
const abrepeat_skin_struct g_abrepeat_skins[] =
{
    {	
        IMG_ID_ABREPEAT_MAIN_SKIN1_BG, //main_bg_img_id;
        64,0,128,//text_ab_border_color_r, text_ab_border_color_g, text_ab_border_color_b;
        255,255,0,//text_main_fg_color_r, text_main_fg_color_g, text_main_fg_color_b;
        192,192,192,//text_main_bg_color_r, text_main_bg_color_g, text_main_bg_color_b;
        253,173,32,//audio_bg_color_r, audio_bg_color_g, audio_bg_color_b;
        238,130,238,//absection_color_r,absection_color_g,absection_color_b;
        12,3,//title_ab_x, title_ab_y;
        104,14,//title_ab_w, title_ab_h;
        92,129,7,//volumebar_ab_x, volumebar_ab_y, volumebar_ab_ind_left;
        IMG_ID_ABREPEAT_VOLUME,//volumebar_ab_ind_image_id;
            
        81,126,//volume_dec_x,volume_dec_y;
        IMG_ID_ABREPEAT_VOLUME_DEC_UP,IMG_ID_ABREPEAT_VOLUME_DEC_DOWN, //volume_dec_button_up_img_id,volume_dec_button_down_img_id;
            
        114,126, //volume_inc_x,volume_inc_y;
        IMG_ID_ABREPEAT_VOLUME_INC_UP,IMG_ID_ABREPEAT_VOLUME_INC_DOWN, //volume_inc_button_up_img_id,volume_inc_button_down_img_id;
            
        19,120,//rewind_button_x, rewind_button_y;
        IMG_ID_ABREPEAT_REW_UP,IMG_ID_ABREPEAT_REW_DOWN,//rewind_button_up_image_id, rewindprev_button_down_image_id;
            
        48,120,//forward_button_x, forward_button_y;
        IMG_ID_ABREPEAT_FWD_UP,IMG_ID_ABREPEAT_FWD_DOWN,//forward_button_up_image_id, forward_button_down_image_id;
            
        29,86,//play_ab_button_x, play_ab_button_y;
        IMG_ID_ABREPEAT_PLAY_UP,IMG_ID_ABREPEAT_PLAY_DOWN,//play_ab_button_up_image_id, play_ab_button_down_image_id;
        IMG_ID_ABREPEAT_PAUSE_UP,IMG_ID_ABREPEAT_PAUSE_DOWN,//pause_ab_button_up_image_id, pause_ab_button_down_image_id;
        6,94 ,//stop_ab_button_x, stop_ab_button_y;
        IMG_ID_ABREPEAT_STOP_UP,IMG_ID_ABREPEAT_STOP_DOWN,//stop_ab_button_up_image_id, stop_ab_button_down_image_id;
            
        81,90,//once_always_button_x,once_always_button_y;
        IMG_ID_ABREPEAT_REPEAT_UP,IMG_ID_ABREPEAT_REPEAT_DOWN,//once_always_button_up_img_id,once_always_button_down_img_id;
        IMG_ID_ABREPEAT_REPEAT_OFF_UP,IMG_ID_ABREPEAT_REPEAT_OFF_DOWN,
        IMG_ID_ABREPEAT_REPEAT_DISABLE,//once always button disabled(Setting Screen)
            
        99,90, //mode_set_button_x, mode_set_button_y;
        IMG_ID_ABREPEAT_SETTING_MODE_UP,IMG_ID_ABREPEAT_SETTING_MODE_DOWN,//setting_mode_button_up_image_id, setting_mode_button_down_image_id;
        IMG_ID_ABREPEAT_PLAY_MODE_UP,IMG_ID_ABREPEAT_PLAY_MODE_DOWN,//play_mode_button_up_image_id, play_mode_button_down_image_id;
            
        6,18,3,//progress_bar_x,progrss_bar_y,progress_bar_ind_off_y;
        IMG_ID_ABREPEAT_PROGRESS_BAR,IMG_ID_ABREPEAT_INDICATOR,//progress_bar_img_id,progress_bar_ind_img_id;
        11,23,//ab_aud_file_rect_x,ab_aud_file_rect_y;
        IMG_ID_ABREPEAT_PROG_BAR_EMPTY,
            
        { 
            99,65,IMG_ID_ABREPEAT_BUTTON0,
            11,42,IMG_ID_ABREPEAT_BUTTON1,
            33,42,IMG_ID_ABREPEAT_BUTTON2,
            55,42,IMG_ID_ABREPEAT_BUTTON3,
            77,42,IMG_ID_ABREPEAT_BUTTON4,
            99,42,IMG_ID_ABREPEAT_BUTTON5,
            11,65,IMG_ID_ABREPEAT_BUTTON6,
            33,65,IMG_ID_ABREPEAT_BUTTON7,
            55,65,IMG_ID_ABREPEAT_BUTTON8,
            77,65,IMG_ID_ABREPEAT_BUTTON9,
                
        },//ab_section_button_skin[MAX_AB_POINT];
        
        IMG_ID_ABREPEAT_ABSECTION_PLAYING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING_DOWN,
        IMG_ID_ABREPEAT_AB_SETSECTION,
        IMG_ID_ABREPEAT_AB_SETSECTION_DOWN,
        IMG_ID_ABREPEAT_AB_NONSETSECTION,
        IMG_ID_ABREPEAT_AB_NONSETSECTION_DOWN,
        //up_ab_key_mapping, down_ab_key_mapping, left_ab_key_mapping, right_ab_key_mapping;
        ABREPEAT_MAIN_PLAY, ABREPEAT_MAIN_STOP, ABREPEAT_MAIN_REWIND, ABREPEAT_MAIN_FORWARD // up, down, left, right key mapping
        
    }
};
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
const abrepeat_skin_struct g_abrepeat_skins[] =
{
    {	
        IMG_ID_ABREPEAT_MAIN_SKIN1_BG, //main_bg_img_id;
        64,0,128,//text_ab_border_color_r, text_ab_border_color_g, text_ab_border_color_b;
        255,255,0,//text_main_fg_color_r, text_main_fg_color_g, text_main_fg_color_b;
        192,192,192,//text_main_bg_color_r, text_main_bg_color_g, text_main_bg_color_b;
        253,173,32,//audio_bg_color_r, audio_bg_color_g, audio_bg_color_b;
        238,130,238,//absection_color_r,absection_color_g,absection_color_b;
        12,4,//title_ab_x, title_ab_y;
        152,20,//title_ab_w, title_ab_h;
        124,173,8,//volumebar_ab_x, volumebar_ab_y, volumebar_ab_ind_left;
        IMG_ID_ABREPEAT_VOLUME,//volumebar_ab_ind_image_id;
            
        109,172,//volume_dec_x,volume_dec_y;
        IMG_ID_ABREPEAT_VOLUME_DEC_UP,IMG_ID_ABREPEAT_VOLUME_DEC_DOWN, //volume_dec_button_up_img_id,volume_dec_button_down_img_id;
            
        159,172, //volume_inc_x,volume_inc_y;
        IMG_ID_ABREPEAT_VOLUME_INC_UP,IMG_ID_ABREPEAT_VOLUME_INC_DOWN, //volume_inc_button_up_img_id,volume_inc_button_down_img_id;
            
        26,163,//rewind_button_x, rewind_button_y;
        IMG_ID_ABREPEAT_REW_UP,IMG_ID_ABREPEAT_REW_DOWN,//rewind_button_up_image_id, rewindprev_button_down_image_id;
            
        65,163,//forward_button_x, forward_button_y;
        IMG_ID_ABREPEAT_FWD_UP,IMG_ID_ABREPEAT_FWD_DOWN,//forward_button_up_image_id, forward_button_down_image_id;
            
        40,117,//play_ab_button_x, play_ab_button_y;
        IMG_ID_ABREPEAT_PLAY_UP,IMG_ID_ABREPEAT_PLAY_DOWN,//play_ab_button_up_image_id, play_ab_button_down_image_id;
        IMG_ID_ABREPEAT_PAUSE_UP,IMG_ID_ABREPEAT_PAUSE_DOWN,//pause_ab_button_up_image_id, pause_ab_button_down_image_id;
        9,127 ,//stop_ab_button_x, stop_ab_button_y;
        IMG_ID_ABREPEAT_STOP_UP,IMG_ID_ABREPEAT_STOP_DOWN,//stop_ab_button_up_image_id, stop_ab_button_down_image_id;
            
        111,122,//once_always_button_x,once_always_button_y;
        IMG_ID_ABREPEAT_REPEAT_UP,IMG_ID_ABREPEAT_REPEAT_DOWN,//once_always_button_up_img_id,once_always_button_down_img_id;
        IMG_ID_ABREPEAT_REPEAT_OFF_UP,IMG_ID_ABREPEAT_REPEAT_OFF_DOWN,
        IMG_ID_ABREPEAT_REPEAT_DISABLE,//once always button disabled(Setting Screen)
            
        135,122, //mode_set_button_x, mode_set_button_y;
        IMG_ID_ABREPEAT_SETTING_MODE_UP,IMG_ID_ABREPEAT_SETTING_MODE_DOWN,//setting_mode_button_up_image_id, setting_mode_button_down_image_id;
        IMG_ID_ABREPEAT_PLAY_MODE_UP,IMG_ID_ABREPEAT_PLAY_MODE_DOWN,//play_mode_button_up_image_id, play_mode_button_down_image_id;
            
        9,25,3,//progress_bar_x,progrss_bar_y,progress_bar_ind_off_y;
        IMG_ID_ABREPEAT_PROGRESS_BAR,IMG_ID_ABREPEAT_INDICATOR,//progress_bar_img_id,progress_bar_ind_img_id;
        14,32,//ab_aud_file_rect_x,ab_aud_file_rect_y;
        IMG_ID_ABREPEAT_PROG_BAR_EMPTY,
            
        { 
            135,87,IMG_ID_ABREPEAT_BUTTON0,
            15,57,IMG_ID_ABREPEAT_BUTTON1,
            45,57,IMG_ID_ABREPEAT_BUTTON2,
            75,57,IMG_ID_ABREPEAT_BUTTON3,
            105,57,IMG_ID_ABREPEAT_BUTTON4,
            135,57,IMG_ID_ABREPEAT_BUTTON5,
            15,87,IMG_ID_ABREPEAT_BUTTON6,
            45,87,IMG_ID_ABREPEAT_BUTTON7,
            75,87,IMG_ID_ABREPEAT_BUTTON8,
            105,87,IMG_ID_ABREPEAT_BUTTON9,
                
        },//ab_section_button_skin[MAX_AB_POINT];
        
        IMG_ID_ABREPEAT_ABSECTION_PLAYING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING_DOWN,
        IMG_ID_ABREPEAT_AB_SETSECTION,
        IMG_ID_ABREPEAT_AB_SETSECTION_DOWN,
        IMG_ID_ABREPEAT_AB_NONSETSECTION,
        IMG_ID_ABREPEAT_AB_NONSETSECTION_DOWN,
        //up_ab_key_mapping, down_ab_key_mapping, left_ab_key_mapping, right_ab_key_mapping;
        ABREPEAT_MAIN_PLAY, ABREPEAT_MAIN_STOP, ABREPEAT_MAIN_REWIND, ABREPEAT_MAIN_FORWARD // up, down, left, right key mapping
        
    }
};
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
const abrepeat_skin_struct g_abrepeat_skins[] =
{
    {	
        IMG_ID_ABREPEAT_MAIN_SKIN1_BG, //main_bg_img_id;
        64,0,128,//text_ab_border_color_r, text_ab_border_color_g, text_ab_border_color_b;
        255,255,0,//text_main_fg_color_r, text_main_fg_color_g, text_main_fg_color_b;
        192,192,192,//text_main_bg_color_r, text_main_bg_color_g, text_main_bg_color_b;
        255,248,220,//audio_bg_color_r, audio_bg_color_g, audio_bg_color_b;
        238,130,238,//absection_color_r,absection_color_g,absection_color_b;
        12,8,//title_ab_x, title_ab_y;
        216,25,//title_ab_w, title_ab_h;
        171,266,6,//volumebar_ab_x, volumebar_ab_y, volumebar_ab_ind_left;
        IMG_ID_ABREPEAT_VOLUME,//volumebar_ab_ind_image_id;
            
        148,262,//volume_dec_x,volume_dec_y;
        IMG_ID_ABREPEAT_VOLUME_DEC_UP,IMG_ID_ABREPEAT_VOLUME_DEC_DOWN, //volume_dec_button_up_img_id,volume_dec_button_down_img_id;
            
        201,262,//volume_inc_x,volume_inc_y;
        IMG_ID_ABREPEAT_VOLUME_INC_UP,IMG_ID_ABREPEAT_VOLUME_INC_DOWN, //volume_inc_button_up_img_id,volume_inc_button_down_img_id;
            
        18,221,//rewind_button_x, rewind_button_y;
        IMG_ID_ABREPEAT_REW_UP,IMG_ID_ABREPEAT_REW_DOWN,//rewind_button_up_image_id, rewindprev_button_down_image_id;
            
        99,221,//forward_button_x, forward_button_y;
        IMG_ID_ABREPEAT_FWD_UP,IMG_ID_ABREPEAT_FWD_DOWN,//forward_button_up_image_id, forward_button_down_image_id;
            
        57,191,//play_ab_button_x, play_ab_button_y;
        IMG_ID_ABREPEAT_PLAY_UP,IMG_ID_ABREPEAT_PLAY_DOWN,//play_ab_button_up_image_id, play_ab_button_down_image_id;
        IMG_ID_ABREPEAT_PAUSE_UP,IMG_ID_ABREPEAT_PAUSE_DOWN,//pause_ab_button_up_image_id, pause_ab_button_down_image_id;
        60,251 ,//stop_ab_button_x, stop_ab_button_y;
        IMG_ID_ABREPEAT_STOP_UP,IMG_ID_ABREPEAT_STOP_DOWN,//stop_ab_button_up_image_id, stop_ab_button_down_image_id;
            
        152,198,//once_always_button_x,once_always_button_y;
        IMG_ID_ABREPEAT_REPEAT_UP,IMG_ID_ABREPEAT_REPEAT_DOWN,//once_always_button_up_img_id,once_always_button_down_img_id;
        IMG_ID_ABREPEAT_REPEAT_OFF_UP,IMG_ID_ABREPEAT_REPEAT_OFF_DOWN,
        IMG_ID_ABREPEAT_REPEAT_DISABLE,//once always button disabled(Setting Screen)
            
        190,198,//mode_set_button_x, mode_set_button_y;
        IMG_ID_ABREPEAT_SETTING_MODE_UP,IMG_ID_ABREPEAT_SETTING_MODE_DOWN,//setting_mode_button_up_image_id, setting_mode_button_down_image_id;
        IMG_ID_ABREPEAT_PLAY_MODE_UP,IMG_ID_ABREPEAT_PLAY_MODE_DOWN,//play_mode_button_up_image_id, play_mode_button_down_image_id;	
            
        30,50,4,//progress_bar_x,progrss_bar_y,progress_bar_ind_off_y;
        IMG_ID_ABREPEAT_PROGRESS_BAR,IMG_ID_ABREPEAT_INDICATOR,//progress_bar_img_id,progress_bar_ind_img_id;
        42,59,//ab_aud_file_rect_x,ab_aud_file_rect_y;
        IMG_ID_ABREPEAT_PROG_BAR_EMPTY,
            
        { 
            184,132,IMG_ID_ABREPEAT_BUTTON0,
            28,91,IMG_ID_ABREPEAT_BUTTON1,
            67,91,IMG_ID_ABREPEAT_BUTTON2,
            106,91,IMG_ID_ABREPEAT_BUTTON3,
            145,91,IMG_ID_ABREPEAT_BUTTON4,
            184,91,IMG_ID_ABREPEAT_BUTTON5,
            28,132,IMG_ID_ABREPEAT_BUTTON6,
            67,132,IMG_ID_ABREPEAT_BUTTON7,
            106,132,IMG_ID_ABREPEAT_BUTTON8,
            145,132,IMG_ID_ABREPEAT_BUTTON9,
                
        },//ab_section_button_skin[MAX_AB_POINT];
        
        IMG_ID_ABREPEAT_ABSECTION_PLAYING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING_DOWN,
        IMG_ID_ABREPEAT_AB_SETSECTION,
        IMG_ID_ABREPEAT_AB_SETSECTION_DOWN,
        IMG_ID_ABREPEAT_AB_NONSETSECTION,
        IMG_ID_ABREPEAT_AB_NONSETSECTION_DOWN,
        //up_ab_key_mapping, down_ab_key_mapping, left_ab_key_mapping, right_ab_key_mapping;
        ABREPEAT_MAIN_PLAY, ABREPEAT_MAIN_STOP, ABREPEAT_MAIN_REWIND, ABREPEAT_MAIN_FORWARD // up, down, left, right key mapping
        
    }
};
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
const abrepeat_skin_struct g_abrepeat_skins[] =
{
    {	
        IMG_ID_ABREPEAT_MAIN_SKIN1_BG, //main_bg_img_id;
        64,0,128,//text_ab_border_color_r, text_ab_border_color_g, text_ab_border_color_b;
        255,255,0,//text_main_fg_color_r, text_main_fg_color_g, text_main_fg_color_b;
        192,192,192,//text_main_bg_color_r, text_main_bg_color_g, text_main_bg_color_b;
        255,248,220,//audio_bg_color_r, audio_bg_color_g, audio_bg_color_b;
        238,130,238,//absection_color_r,absection_color_g,absection_color_b;
        12,8,//title_ab_x, title_ab_y;
        296,25,//title_ab_w, title_ab_h;
        24,102,0,//volumebar_ab_x, volumebar_ab_y, volumebar_ab_ind_left;
        IMG_ID_ABREPEAT_VOLUME,//volumebar_ab_ind_image_id;
        27,158,//S16 volume_dec_x,volume_dec_y;
        IMG_ID_ABREPEAT_VOLUME_DEC_UP,IMG_ID_ABREPEAT_VOLUME_DEC_DOWN, //volume_dec_button_up_img_id,volume_dec_button_down_img_id;
        
        27,91, //S16 volume_inc_x,volume_inc_y;
        IMG_ID_ABREPEAT_VOLUME_INC_UP,IMG_ID_ABREPEAT_VOLUME_INC_DOWN, //volume_inc_button_up_img_id,volume_inc_button_down_img_id;
        
        218,140,//rewind_button_x, rewind_button_y;
        IMG_ID_ABREPEAT_REW_UP,IMG_ID_ABREPEAT_REW_DOWN,//rewind_button_up_image_id, rewindprev_button_down_image_id;
        
        276,140,//forward_button_x, forward_button_y;
        IMG_ID_ABREPEAT_FWD_UP,IMG_ID_ABREPEAT_FWD_DOWN,//forward_button_up_image_id, forward_button_down_image_id;
        
        240,107,//play_ab_button_x, play_ab_button_y;
        IMG_ID_ABREPEAT_PLAY_UP,IMG_ID_ABREPEAT_PLAY_DOWN,//play_ab_button_up_image_id, play_ab_button_down_image_id;
        IMG_ID_ABREPEAT_PAUSE_UP,IMG_ID_ABREPEAT_PAUSE_DOWN,//pause_ab_button_up_image_id, pause_ab_button_down_image_id;
        245,161 ,//stop_ab_button_x, stop_ab_button_y;
        IMG_ID_ABREPEAT_STOP_UP,IMG_ID_ABREPEAT_STOP_DOWN,//stop_ab_button_up_image_id, stop_ab_button_down_image_id;
        
        250,56,//once_always_button_x,once_always_button_y;
        IMG_ID_ABREPEAT_REPEAT_UP,IMG_ID_ABREPEAT_REPEAT_DOWN,//once_always_button_up_img_id,once_always_button_down_img_id;
        IMG_ID_ABREPEAT_REPEAT_OFF_UP,IMG_ID_ABREPEAT_REPEAT_OFF_DOWN,
        IMG_ID_ABREPEAT_REPEAT_DISABLE,//once always button disabled(Setting Screen)
        
        272,56,//mode_set_button_x, mode_set_button_y;
        IMG_ID_ABREPEAT_SETTING_MODE_UP,IMG_ID_ABREPEAT_SETTING_MODE_DOWN,//setting_mode_button_up_image_id, setting_mode_button_down_image_id;
        IMG_ID_ABREPEAT_PLAY_MODE_UP,IMG_ID_ABREPEAT_PLAY_MODE_DOWN,//play_mode_button_up_image_id, play_mode_button_down_image_id;
        
        48,58,4,//progress_bar_x,progrss_bar_y,progress_bar_ind_off_y;
        IMG_ID_ABREPEAT_PROGRESS_BAR,IMG_ID_ABREPEAT_INDICATOR,//progress_bar_img_id,progress_bar_ind_img_id;
        49,59,//ab_aud_file_rect_x,ab_aud_file_rect_y;
        IMG_ID_ABREPEAT_PROG_BAR_EMPTY,
        
        { 
            170,124,IMG_ID_ABREPEAT_BUTTON0,
            50,90,IMG_ID_ABREPEAT_BUTTON1,
            80,90,IMG_ID_ABREPEAT_BUTTON2,
            110,90,IMG_ID_ABREPEAT_BUTTON3,
            140,90,IMG_ID_ABREPEAT_BUTTON4,
            170,90,IMG_ID_ABREPEAT_BUTTON5,
            50,124,IMG_ID_ABREPEAT_BUTTON6,
            80,124,IMG_ID_ABREPEAT_BUTTON7,
            110,124,IMG_ID_ABREPEAT_BUTTON8,
            140,124,IMG_ID_ABREPEAT_BUTTON9,
            
        },//ab_section_button_skin[MAX_AB_POINT];
        
        IMG_ID_ABREPEAT_ABSECTION_PLAYING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING,
        IMG_ID_ABREPEAT_ABSECTION_RECORDING_DOWN,
        IMG_ID_ABREPEAT_AB_SETSECTION,
        IMG_ID_ABREPEAT_AB_SETSECTION_DOWN,
        IMG_ID_ABREPEAT_AB_NONSETSECTION,
        IMG_ID_ABREPEAT_AB_NONSETSECTION_DOWN,
        //up_ab_key_mapping, down_ab_key_mapping, left_ab_key_mapping, right_ab_key_mapping;
        ABREPEAT_MAIN_PLAY, ABREPEAT_MAIN_STOP, ABREPEAT_MAIN_REWIND, ABREPEAT_MAIN_FORWARD // up, down, left, right key mapping
        
    }
};
#endif

#endif /* __MMI_AB_REPEATER__ */


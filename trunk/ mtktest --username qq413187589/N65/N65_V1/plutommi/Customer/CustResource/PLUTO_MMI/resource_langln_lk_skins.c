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
*  resource_langln_lk_skins.c	
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Listening King skin layout
*
* Author:
* -------
*  Haibin Qiang(mbj06073)	
*
***********************************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_LANGLN_LK__
#include "gdi_lcd_config.h"

#include "FrameworkStruct.h"
#include "GlobalConstants.h"
#include "FileMgr.h"

#include "LanglnResDef.h"
#include "LanglnLKDef.h"
#if ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
const langln_lk_skin_struct g_langln_lk_skins[] =
{
    {	
        IMG_ID_LANGLN_LK_BG,//U16 main_bg_img_id;
        
        2, 169, //S16 play_btn_x, play_btn_y;
        IMG_ID_LANGLN_LK_PLAY_BTN_UP, IMG_ID_LANGLN_LK_PLAY_BTN_DOWN,//U16 play_btn_up_img_id, play_btn_down_img_id;
        IMG_ID_LANGLN_LK_PAUSE_BTN_UP, IMG_ID_LANGLN_LK_PAUSE_BTN_DOWN,//U16 pause_btn_up_img_id, pause_btn_down_img_id;
        IMG_ID_LANGLN_LK_RESND_BTN_UP, IMG_ID_LANGLN_LK_RESND_BTN_DOWN,//U16 resnd_btn_up_img_id, resnd_btn_down_img_id;
        IMG_ID_LANGLN_LK_RESNDING_BTN_UP, IMG_ID_LANGLN_LK_RESNDING_BTN_DOWN, //U16 resnding_btn_up_img_id, resnding_btn_down_img_id;
        
        30, 179,//S16 stop_btn_x, stop_btn_y;
        IMG_ID_LANGLN_LK_STOP_BTN_UP, IMG_ID_LANGLN_LK_STOP_BTN_DOWN,//U16 stop_btn_up_img_id, stop_btn_down_img_id;
        IMG_ID_LANGLN_LK_PLAYSND_BTN_UP, IMG_ID_LANGLN_LK_PLAYSND_BTN_DOWN,//U16 playsnd_btn_up_img_id, playsnd_btn_down_img_id;
        
        71, 181,//S16 next_btn_x, next_btn_y;
        IMG_ID_LANGLN_LK_NEXT_BTN_UP, IMG_ID_LANGLN_LK_NEXT_BTN_DOWN,//U16 next_btn_up_img_id, next_btn_down_img_id;
        
        51, 181,//S16 pre_btn_x, pre_btn_y;
        IMG_ID_LANGLN_LK_PRE_BTN_UP, IMG_ID_LANGLN_LK_PRE_BTN_DOWN,//U16 pre_btn_up_img_id, pre_btn_down_img_id;
        
        101, 165, //S16 abs_btn_x, abs_btn_y;
        IMG_ID_LANGLN_LK_ABS_IDLE_BTN_UP, IMG_ID_LANGLN_LK_ABS_IDLE_BTN_DOWN,//U16 abs_idle_btn_up_img_id, abs_idle_btn_down_img_id;
        IMG_ID_LANGLN_LK_ABS_PARTIAL_BTN_UP, IMG_ID_LANGLN_LK_ABS_PARTIAL_BTN_DOWN,//U16 abs_partial_btn_up_img_id, abs_partial_btn_down_img_id;
        IMG_ID_LANGLN_LK_ABS_SET_BTN_UP, IMG_ID_LANGLN_LK_ABS_SET_BTN_DOWN,//U16 abs_set_btn_up_img_id, abs_set_btn_down_img_id;
        
        47, 165, 48, //S16 speed_inc_btn_x, speed_inc_btn_y, speed_bg_img_x;
        IMG_ID_LANGLN_LK_SPEED_INC_BTN_UP, IMG_ID_LANGLN_LK_SPEED_INC_BTN_DOWN,//U16 speed_inc_btn_up_img_id, speed_inc_btn_down_img_id;
        IMG_ID_LANGLN_LK_SPEED_INC_BTN_DIS,//U16 speed_inc_btn_dis_img_id;
        IMG_ID_LANGLN_LK_SP_BTNS_DIS_BG, //U16 speed_dis_bg_img_id;
        
        91, 165, //S16 speed_dec_btn_x, speed_dec_btn_y;
        IMG_ID_LANGLN_LK_SPEED_DEC_BTN_UP, IMG_ID_LANGLN_LK_SPEED_DEC_BTN_DOWN,//U16 speed_dec_btn_up_img_id, speed_dec_btn_down_img_id;
        IMG_ID_LANGLN_LK_SPEED_DEC_BTN_DIS,//U16 speed_dec_btn_dis_img_id;
        
        57, 165, //S16 speed_value_x, speed_value_y;
        IMG_ID_LANGLN_LK_SPEED_SLOW2, //U16 speed_slow2_img_id;
        IMG_ID_LANGLN_LK_SPEED_SLOW1, //U16 speed_slow1_img_id;
        IMG_ID_LANGLN_LK_SPEED_NORMAL, //U16 speed_normal_img_id;
        IMG_ID_LANGLN_LK_SPEED_FAST1, //U16 speed_fast1_img_id;
        IMG_ID_LANGLN_LK_SPEED_FAST2, //U16 speed_fast2_img_id;
        

        119, 165, //S16 circulate_btn_x, circulate_btn_y;
        IMG_ID_LANGLN_LK_CIRCULATE_BTN_UP, IMG_ID_LANGLN_LK_CIRCULATE_BTN_DOWN,//U16 circulate_btn_up_img_id, circulate_btn_down_img_id;
        IMG_ID_LANGLN_LK_CIRCULATE_ON_BTN_UP, IMG_ID_LANGLN_LK_CIRCULATE_ON_BTN_DOWN,//U16 circulate_on_btn_up_img_id, circulate_on_btn_down_img_id;
        
        137, 165, //S16 key_word_btn_x, key_word_btn_y;
        IMG_ID_LANGLN_LK_KEY_WORD_BTN_UP, IMG_ID_LANGLN_LK_KEY_WORD_BTN_DOWN,//U16 key_word_btn_up_img_id, key_word_btn_down_img_id;
        IMG_ID_LANGLN_LK_KEY_WORD_BTN_DIS,//U16 key_word_btn_dis_img_id;
        
        155, 165,//S16 mode_btn_x, mode_btn_y;
        IMG_ID_LANGLN_LK_MODE_BTN_LISTEN, IMG_ID_LANGLN_LK_MODE_BTN_SPEAK,//U16 mode_listen_btn_img_id, mode_speak_btn_img_id;
        
        5, 148,//S16 total_time_area_x1, total_time_area_y1;
        IMG_ID_LANGLN_LK_DURATION_TIME_BG,//U16 duration_area_img_id;
        
        78, 153,//S16 progress_bar_x, progress_bar_y;
        IMG_ID_LANGLN_LK_PROGRESS_BAR_BG,//U16 progress_bar_img_id;
        
        78, 153, //S16 progress_bar_rect_x, progress_bar_rect_y;
        IMG_ID_LANGLN_LK_PROGRESS_BAR_RECT,//U16 progress_bar_rect_img_id;
        0, 255, 255,//U8 progress_bar_color_r, progress_bar_color_g, progress_bar_color_b;
        255, 0, 0,//U8 progress_bar_abs_color_r, progress_bar_abs_color_g, progress_bar_abs_color_b;
        
        78, 181, //S16 record_tip_area_x1, record_tip_area_y1;
        IMG_ID_LANGLN_LK_RECORD_INFO_BG, //U16 record_tips_bg_img_id;
        
        101, 165,//S16 buttons_dis_area_x, buttons_dis_area_y;
        IMG_ID_LANGLN_LK_BTNS_DIS_AREA_BG,//U16 buttons_dis_area_img_id;
        
        51, 181,//S16 next_pre_dis_area_x, next_pre_dis_area_y;
        IMG_ID_LANGLN_LK_PRE_NEXT_DIS_BG,//S16 next_pre_dis_area_img_id;
        
        /*up and down arrow key is mapping text scroll*/
        /*please not use KEY_ARROW_UP and KEY_ARROW_DOWN*/
        /*LISTEN mode buttons mapping keys*/
        KEY_LEFT_ARROW, KEY_RIGHT_ARROW,//U8 previous_btn_mapping_key, next_btn_mapping_key;
        KEY_1, KEY_2,//U8 play_btn_mapping_key, stop_btn_mapping_key;
        KEY_3, KEY_4,//U8 abs_btn_mapping_key, circulate_btn_mapping_key;
        KEY_7, KEY_8,//U8 speed_inc_btn_mapping_key, speed_dec_btn_mappint_key;
        KEY_5 ,//U8 key_word_btn_mapping_key;
        
        /*mode switch button mapping key, both in LISTEN mode and SPEAK mode*/
        KEY_6, //U8 mode_switch_btn_mapping_key;
        
        /*SPEAK mode buttons mapping keys*/
        KEY_1, //U8 sound_record_btn_mapping_key;
        KEY_2 //U8 replay_record_btn_mapping_key;
    }
};
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
const langln_lk_skin_struct g_langln_lk_skins[] =
{
    {	
        IMG_ID_LANGLN_LK_BG,//U16 main_bg_img_id;
        
        6, 252, //S16 play_btn_x, play_btn_y;
        IMG_ID_LANGLN_LK_PLAY_BTN_UP, IMG_ID_LANGLN_LK_PLAY_BTN_DOWN,//U16 play_btn_up_img_id, play_btn_down_img_id;
        IMG_ID_LANGLN_LK_PAUSE_BTN_UP, IMG_ID_LANGLN_LK_PAUSE_BTN_DOWN,//U16 pause_btn_up_img_id, pause_btn_down_img_id;
        IMG_ID_LANGLN_LK_RESND_BTN_UP, IMG_ID_LANGLN_LK_RESND_BTN_DOWN,//U16 resnd_btn_up_img_id, resnd_btn_down_img_id;
        IMG_ID_LANGLN_LK_RESNDING_BTN_UP, IMG_ID_LANGLN_LK_RESNDING_BTN_DOWN, //U16 resnding_btn_up_img_id, resnding_btn_down_img_id;
        
        45, 266,//S16 stop_btn_x, stop_btn_y;
        IMG_ID_LANGLN_LK_STOP_BTN_UP, IMG_ID_LANGLN_LK_STOP_BTN_DOWN,//U16 stop_btn_up_img_id, stop_btn_down_img_id;
        IMG_ID_LANGLN_LK_PLAYSND_BTN_UP, IMG_ID_LANGLN_LK_PLAYSND_BTN_DOWN,//U16 playsnd_btn_up_img_id, playsnd_btn_down_img_id;
        
        100, 268,//S16 next_btn_x, next_btn_y;
        IMG_ID_LANGLN_LK_NEXT_BTN_UP, IMG_ID_LANGLN_LK_NEXT_BTN_DOWN,//U16 next_btn_up_img_id, next_btn_down_img_id;
        
        73, 268,//S16 pre_btn_x, pre_btn_y;
        IMG_ID_LANGLN_LK_PRE_BTN_UP, IMG_ID_LANGLN_LK_PRE_BTN_DOWN,//U16 pre_btn_up_img_id, pre_btn_down_img_id;
        
        131, 244, //S16 abs_btn_x, abs_btn_y;
        IMG_ID_LANGLN_LK_ABS_IDLE_BTN_UP, IMG_ID_LANGLN_LK_ABS_IDLE_BTN_DOWN,//U16 abs_idle_btn_up_img_id, abs_idle_btn_down_img_id;
        IMG_ID_LANGLN_LK_ABS_PARTIAL_BTN_UP, IMG_ID_LANGLN_LK_ABS_PARTIAL_BTN_DOWN,//U16 abs_partial_btn_up_img_id, abs_partial_btn_down_img_id;
        IMG_ID_LANGLN_LK_ABS_SET_BTN_UP, IMG_ID_LANGLN_LK_ABS_SET_BTN_DOWN,//U16 abs_set_btn_up_img_id, abs_set_btn_down_img_id;
        
        69, 244, 70, //S16 speed_inc_btn_x, speed_inc_btn_y, speed_bg_img_x;
        IMG_ID_LANGLN_LK_SPEED_INC_BTN_UP, IMG_ID_LANGLN_LK_SPEED_INC_BTN_DOWN,//U16 speed_inc_btn_up_img_id, speed_inc_btn_down_img_id;
        IMG_ID_LANGLN_LK_SPEED_INC_BTN_DIS,//U16 speed_inc_btn_dis_img_id;
        IMG_ID_LANGLN_LK_SP_BTNS_DIS_BG, //U16 speed_dis_bg_img_id;
        
        118, 244, //S16 speed_dec_btn_x, speed_dec_btn_y;
        IMG_ID_LANGLN_LK_SPEED_DEC_BTN_UP, IMG_ID_LANGLN_LK_SPEED_DEC_BTN_DOWN,//U16 speed_dec_btn_up_img_id, speed_dec_btn_down_img_id;
        IMG_ID_LANGLN_LK_SPEED_DEC_BTN_DIS,//U16 speed_dec_btn_dis_img_id;
        
        81, 244, //S16 speed_value_x, speed_value_y;
        IMG_ID_LANGLN_LK_SPEED_SLOW2, //U16 speed_slow2_img_id;
        IMG_ID_LANGLN_LK_SPEED_SLOW1, //U16 speed_slow1_img_id;
        IMG_ID_LANGLN_LK_SPEED_NORMAL, //U16 speed_normal_img_id;
        IMG_ID_LANGLN_LK_SPEED_FAST1, //U16 speed_fast1_img_id;
        IMG_ID_LANGLN_LK_SPEED_FAST2, //U16 speed_fast2_img_id;
        

        157, 244, //S16 circulate_btn_x, circulate_btn_y;
        IMG_ID_LANGLN_LK_CIRCULATE_BTN_UP, IMG_ID_LANGLN_LK_CIRCULATE_BTN_DOWN,//U16 circulate_btn_up_img_id, circulate_btn_down_img_id;
        IMG_ID_LANGLN_LK_CIRCULATE_ON_BTN_UP, IMG_ID_LANGLN_LK_CIRCULATE_ON_BTN_DOWN,//U16 circulate_on_btn_up_img_id, circulate_on_btn_down_img_id;
        
        183, 244, //S16 key_word_btn_x, key_word_btn_y;
        IMG_ID_LANGLN_LK_KEY_WORD_BTN_UP, IMG_ID_LANGLN_LK_KEY_WORD_BTN_DOWN,//U16 key_word_btn_up_img_id, key_word_btn_down_img_id;
        IMG_ID_LANGLN_LK_KEY_WORD_BTN_DIS,//U16 key_word_btn_dis_img_id;
        
        209, 244,//S16 mode_btn_x, mode_btn_y;
        IMG_ID_LANGLN_LK_MODE_BTN_LISTEN, IMG_ID_LANGLN_LK_MODE_BTN_SPEAK,//U16 mode_listen_btn_img_id, mode_speak_btn_img_id;
        
        6, 219,//S16 total_time_area_x1, total_time_area_y1;
        IMG_ID_LANGLN_LK_DURATION_TIME_BG,//U16 duration_area_img_id;
        
        95, 225,//S16 progress_bar_x, progress_bar_y;
        IMG_ID_LANGLN_LK_PROGRESS_BAR_BG,//U16 progress_bar_img_id;
        
        96, 226, //S16 progress_bar_rect_x, progress_bar_rect_y;
        IMG_ID_LANGLN_LK_PROGRESS_BAR_RECT,//U16 progress_bar_rect_img_id;
        0, 255, 255,//U8 progress_bar_color_r, progress_bar_color_g, progress_bar_color_b;
        255, 0, 0,//U8 progress_bar_abs_color_r, progress_bar_abs_color_g, progress_bar_abs_color_b;
        
        91, 267, //S16 record_tip_area_x1, record_tip_area_y1;
        IMG_ID_LANGLN_LK_RECORD_INFO_BG, //U16 record_tips_bg_img_id;
        
        131, 244,//S16 buttons_dis_area_x, buttons_dis_area_y;
        IMG_ID_LANGLN_LK_BTNS_DIS_AREA_BG,//U16 buttons_dis_area_img_id;
        
        73, 267,//S16 next_pre_dis_area_x, next_pre_dis_area_y;
        IMG_ID_LANGLN_LK_PRE_NEXT_DIS_BG,//S16 next_pre_dis_area_img_id;
        
        /*up and down arrow key is mapping text scroll*/
        /*please not use KEY_ARROW_UP and KEY_ARROW_DOWN*/
        /*LISTEN mode buttons mapping keys*/
        KEY_LEFT_ARROW, KEY_RIGHT_ARROW,//U8 previous_btn_mapping_key, next_btn_mapping_key;
        KEY_1, KEY_2,//U8 play_btn_mapping_key, stop_btn_mapping_key;
        KEY_3, KEY_4,//U8 abs_btn_mapping_key, circulate_btn_mapping_key;
        KEY_7, KEY_8,//U8 speed_inc_btn_mapping_key, speed_dec_btn_mappint_key;
        KEY_5 ,//U8 key_word_btn_mapping_key;
        
        /*mode switch button mapping key, both in LISTEN mode and SPEAK mode*/
        KEY_6, //U8 mode_switch_btn_mapping_key;
        
        /*SPEAK mode buttons mapping keys*/
        KEY_1, //U8 sound_record_btn_mapping_key;
        KEY_2 //U8 replay_record_btn_mapping_key;
    }
};
#endif

#endif /* __MMI_LANGLN_LK__ */


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
*  FMRadioMainScreen.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main screen drawing prototype
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef _FM_RADIO_MAIN_SCREEN_H
#define _FM_RADIO_MAIN_SCREEN_H

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__
/*
 * Need to include:
 * (1) xxx.h
 * (2) yyy.h
 */

typedef struct
{
    S16 x, y;
    S16 w, h;
} fmrdo_main_rect_struct;

typedef struct
{
    U8 type;    /* 0: horizontal, 1: vertical */
    U8 ind_start_gap;
    U8 ind_end_gap;
    S16 x, y;
    S16 w, h;
    PU8 bg_img;
} fmrdo_main_volume_struct;

typedef struct
{
    U8 type;    /* 0: horizontal, 1: vertical */
    signed char ind_offset;
    U8 ind_start_gap;
    U8 ind_end_gap;
    S16 x, y;
    S16 w, h;
    S16 ind_w, ind_h;
    PU8 bg_img, ind_img;
} fmrdo_main_tuner_scale_struct;

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
} fmrdo_main_push_button_struct;

#ifdef __MMI_FM_RADIO_ANIMATION__
typedef struct
{
    S16 x, y;
    /* S16 w, h; */
    S32 img_handle;
    PU8 animation_img;
} fmrdo_main_animation_struct;
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 up_img, down_img;
    BOOL down;
} fmrdo_main_push_down_button_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

typedef struct
{
    S16 x, y;
    S16 w, h;
    PU8 on_up_img, on_down_img;
    PU8 off_up_img, off_down_img;
} fmrdo_main_toggle_button_struct;

typedef struct
{
    UI_string_type LSK_text;
    UI_string_type RSK_text;

    color LSK_text_border_color;
    color LSK_text_color;
    color RSK_text_border_color;
    color RSK_text_color;

    color frequency_text_on_color;
    color frequency_text_off_color;

    color channel_name_text_color;
    color channel_name_text_border_color;

    PU8 bg_img;
    fmrdo_main_volume_struct volume;
    fmrdo_main_tuner_scale_struct tuner_scale;
    fmrdo_main_push_button_struct step_down_button;
    fmrdo_main_push_button_struct step_up_button;
    fmrdo_main_toggle_button_struct search_button;
    fmrdo_main_toggle_button_struct power_button;
#ifdef __MMI_FM_RADIO_ANIMATION__
    fmrdo_main_animation_struct animation;
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    fmrdo_main_push_down_button_struct setting_button;
    fmrdo_main_push_down_button_struct volume_inc_button;
    fmrdo_main_push_down_button_struct volume_dec_button;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    fmrdo_main_rect_struct channel_name;
    fmrdo_main_rect_struct frequency;

    scrolling_text channel_name_scroll;
    UI_character_type channel_name_str[MAX_NAME_INPUT_LEN + 10];

#if defined(__MMI_FM_RADIO_RECORD__)
    fmrdo_main_toggle_button_struct rec_button;
    fmrdo_main_toggle_button_struct rec_pause_button;
    U16 rec_base_num_id;
    U16 rec_num_col_id;
    S16 timer_hr_0_offset_x;
    S16 timer_hr_1_offset_x;
    S16 timer_col_0_offset_x;
    S16 timer_min_0_offset_x;
    S16 timer_min_1_offset_x;
    S16 timer_col_1_offset_x;
    S16 timer_sec_0_offset_x;
    S16 timer_sec_1_offset_x;
    S16 timer_offset_y;
    S16 timer_offset_x2;
    S16 timer_offset_y2;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    U8 skin_index;
    BOOL is_ready;
    BOOL is_channel_name_scroll_ready;
} fmrdo_main_draw_struct;

extern void mmi_fmrdo_redraw_subLCD(BOOL is_show);
extern void mmi_fmrdo_exit_subLCD(void);
extern void mmi_fmrdo_exit_mainscreen(void);

extern void mmi_fmrdo_init_main_images(S32 skin_index);
extern void mmi_fmrdo_show_main(U16 left_softkey, U16 right_softkey, U8 skin_index);
extern void mmi_fmrdo_hide_main(void);
extern void mmi_fmrdo_redraw_main_LSK_down(void);
extern void mmi_fmrdo_redraw_main_RSK_down(void);
extern void mmi_fmrdo_scroll_channel_name_hdlr(void);
extern void mmi_fmrdo_redraw_main_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_fmrdo_redraw_main_all(void);
extern void mmi_fmrdo_redraw_main_frequency(U16 freq, BOOL is_shown);
extern void mmi_fmrdo_redraw_main_channel_name(UI_string_type other_str);
extern void mmi_fmrdo_redraw_main_channel_tuner(U16 freq);
extern void mmi_fmrdo_redraw_main_volume(void);
extern void mmi_fmrdo_redraw_main_push_button(U8 button, BOOL is_down);
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
extern void mmi_fmrdo_sub_show_main(U16 left_softkey, U16 right_softkey, U8 skin_index);
extern void mmi_fmrdo_sub_hide_main(void);
extern void mmi_fmrdo_sub_redraw_frequency(U16 freq, BOOL is_shown);
extern void mmi_fmrdo_sub_init_main_images(S32 skin_index);
extern void mmi_fmrdo_sub_redraw_main_all(void);
#endif

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_fmrdo_redraw_main_push_down_button(U8 button, BOOL is_down);
#endif 
extern void mmi_fmrdo_redraw_main_toggle_button(U8 button, BOOL is_down, BOOL is_on, BOOL is_shown);

#ifdef __MMI_FM_RADIO_ANIMATION__
extern void mmi_fmrdo_animation_start(void);
extern void mmi_fmrdo_animation_stop(void);
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#if defined(__MMI_FM_RADIO_RECORD__)
extern void mmi_fmrdo_change_main_SK_record(void);
extern void mmi_fmrdo_change_main_SK_pause(void);
extern void mmi_fmrdo_restore_main_SK(void);
extern void mmi_fmrdo_redraw_main_time_duration(BOOL is_shown);
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#endif /* __MMI_FM_RADIO__ */ 
#endif /* _FM_RADIO_MAIN_SCREEN_H */ 


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
*  FMRadioMainScreen.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main screen drawing program
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_FM_RADIO__

#include "CommonScreens.h"

#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
/* MTK Leo add 20050301, add touch screen support for FM Radio */
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
/* MTK Leo end */
#include "wgui_softkeys.h"

#ifdef __GDI_MEMORY_PROFILE_2__
GDI_HANDLE fmrdo_osd_layer;
GDI_HANDLE fmrdo_skin_layer;
BOOL is_fmrdo_skin_layer_drawn = FALSE;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

static fmrdo_main_draw_struct fmrdo_main_draw;  /* all memeber variables are zero initial */

extern mmi_fmrdo_struct g_fmrdo;                    /* defined in FMRadioSrc.c */
extern S32 UI_device_width;                         /* from gui_wrapper.c */
extern S32 UI_device_height;                        /* from gui_wrapper.c */
extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
extern const mmi_fmrdo_sub_skin_struct g_fmrdo_subLCD_skins[];
extern S32 new_gdi_buffer[];

#define EXTRA_GDI_BUFFER_SIZE 12288

extern void (*SUBLCD_ExitCategoryFunction) (void) ;
extern S32(*SUBLCD_GetCategoryHistorySize) (void);
extern void (*SUBLCD_RedrawCategoryFunction) (void);
extern U8 *(*SUBLCD_GetCategoryHistory) (U8 *buffer);

#endif

extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);
extern BOOL r2lMMIFlag; /* definedi n gui_inputs.c */

#define FMRDO_LSK_X_OFFSET 7
#define FMRDO_LSK_Y_OFFSET 2
#define FMRDO_RSK_X_OFFSET 6
#define FMRDO_RSK_Y_OFFSET 2
#ifdef __MMI_TOUCH_SCREEN__
/* MTK Leo add 20050301, add touch screen support for FM Radio */
typedef enum
{
    FMRDO_PEN_NONE,
    FMRDO_PEN_LSK,
    FMRDO_PEN_RSK,
    FMRDO_PEN_MAIN_STEP_UP,
    FMRDO_PEN_MAIN_STEP_DOWN,
    FMRDO_PEN_MAIN_POWER,
    FMRDO_PEN_MAIN_SEARCH,
    FMRDO_PEN_MAIN_SETTING,
    FMRDO_PEN_MAIN_VOLUME_INC,
    FMRDO_PEN_MAIN_VOLUME_DEC,
    FMRDO_PEN_MAIN_FREQ,
    FMRDO_PEN_COUNT
} FMRDO_PEN_STATE;
typedef enum
{
    FMRDO_PEN_SK_UP,
    FMRDO_PEN_SK_DOWN
} FMRDO_SOFTKEY_STATE;

S32 fmrdo_pen_event_on_object = FMRDO_PEN_NONE;
static mmi_pen_point_struct LSK_points[4];
static mmi_pen_point_struct RSK_points[4];
static mmi_pen_polygon_area_struct LSK_area;
static mmi_pen_polygon_area_struct RSK_area;

/* MTK Leo end */
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* sub LCD */
#ifdef __MMI_SUBLCD__
scrolling_text fmrdo_sub_LCD_scrolling_title;
scrolling_text *fmrdo_sub_LCD_scrolling_title_p = NULL;
extern bitmap *current_LCD_device_bitmap;   /* defined in wgui.c */
extern bitmap main_LCD_device_bitmap;       /* defined in wingui.c */
extern bitmap sub_LCD_device_bitmap;        /* defined in wingui.c */
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_main_images
 * DESCRIPTION
 *  
 * PARAMETERS
 *  skin_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_main_images(S32 skin_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

#if defined(__MMI_FM_RADIO_RECORD__)
    S32 w2, h2;
#endif 
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[skin_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LSK */
    fmrdo_main_draw.LSK_text_border_color = gui_color(skin_p->LSK_text_border_color_r, skin_p->LSK_text_border_color_g, skin_p->LSK_text_border_color_b);
    fmrdo_main_draw.LSK_text_color = gui_color(skin_p->LSK_text_color_r, skin_p->LSK_text_color_g, skin_p->LSK_text_color_b);

    /* RSK */
    fmrdo_main_draw.RSK_text_border_color = gui_color(skin_p->RSK_text_border_color_r, skin_p->RSK_text_border_color_g, skin_p->RSK_text_border_color_b);
    fmrdo_main_draw.RSK_text_color = gui_color(skin_p->RSK_text_color_r, skin_p->RSK_text_color_g, skin_p->RSK_text_color_b);

    /* background */
    fmrdo_main_draw.bg_img = (PU8) GetImage(skin_p->bg_image_id);

    /* channel name */
    fmrdo_main_draw.channel_name_text_border_color = gui_color(
                                                        skin_p->channel_name_text_border_color_r,
                                                        skin_p->channel_name_text_border_color_g,
                                                        skin_p->channel_name_text_border_color_b);
    fmrdo_main_draw.channel_name_text_color = gui_color(
                                                skin_p->channel_name_text_color_r,
                                                skin_p->channel_name_text_color_g,
                                                skin_p->channel_name_text_color_b);
    fmrdo_main_draw.channel_name.x = skin_p->channel_name_x;
    fmrdo_main_draw.channel_name.y = skin_p->channel_name_y;
    fmrdo_main_draw.channel_name.w = skin_p->channel_name_w;
    fmrdo_main_draw.channel_name.h = skin_p->channel_name_h;

    /* frequency */
    fmrdo_main_draw.frequency_text_on_color = gui_color(
                                                skin_p->frequency_text_on_color_r,
                                                skin_p->frequency_text_on_color_g,
                                                skin_p->frequency_text_on_color_b);
    fmrdo_main_draw.frequency_text_off_color = gui_color(
                                                skin_p->frequency_text_off_color_r,
                                                skin_p->frequency_text_off_color_g,
                                                skin_p->frequency_text_off_color_b);
    fmrdo_main_draw.frequency.x = skin_p->frequency_x;
    fmrdo_main_draw.frequency.y = skin_p->frequency_y;
    fmrdo_main_draw.frequency.w = skin_p->frequency_w;
    fmrdo_main_draw.frequency.h = skin_p->frequency_h;

    /* volume */
    fmrdo_main_draw.volume.bg_img = (PU8) GetImage(skin_p->volume_image_id);
    fmrdo_main_draw.volume.type = skin_p->volume_bar_type;  /* 0: horizontal, 1: vertical */
    fmrdo_main_draw.volume.x = skin_p->volume_bar_x;
    fmrdo_main_draw.volume.y = skin_p->volume_bar_y;
    gui_measure_image(fmrdo_main_draw.volume.bg_img, &w, &h);
    fmrdo_main_draw.volume.w = (S16) w;
    fmrdo_main_draw.volume.h = (S16) h;
    fmrdo_main_draw.volume.ind_start_gap = skin_p->volume_ind_start_gap;
    fmrdo_main_draw.volume.ind_end_gap = skin_p->volume_ind_end_gap;

#ifdef __MMI_FM_RADIO_ANIMATION__
    /* animation */
    fmrdo_main_draw.animation.x = skin_p->animation_x;
    fmrdo_main_draw.animation.y = skin_p->animation_y;
    fmrdo_main_draw.animation.animation_img = (PU8) GetImage(skin_p->animation_image_id);
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifdef __MMI_TOUCH_SCREEN__
    /* volume inc & dec control */
    fmrdo_main_draw.volume_inc_button.x = skin_p->volume_inc_x;
    fmrdo_main_draw.volume_inc_button.y = skin_p->volume_inc_y;
    fmrdo_main_draw.volume_inc_button.up_img = (PU8) GetImage(skin_p->volume_inc_up_image_id);
    fmrdo_main_draw.volume_inc_button.down_img = (PU8) GetImage(skin_p->volume_inc_down_image_id);
    gui_measure_image(fmrdo_main_draw.volume_inc_button.up_img, &w, &h);
    fmrdo_main_draw.volume_inc_button.w = (S16) w;
    fmrdo_main_draw.volume_inc_button.h = (S16) h;
    fmrdo_main_draw.volume_inc_button.down = FALSE;

    fmrdo_main_draw.volume_dec_button.x = skin_p->volume_dec_x;
    fmrdo_main_draw.volume_dec_button.y = skin_p->volume_dec_y;
    fmrdo_main_draw.volume_dec_button.up_img = (PU8) GetImage(skin_p->volume_dec_up_image_id);
    fmrdo_main_draw.volume_dec_button.down_img = (PU8) GetImage(skin_p->volume_dec_down_image_id);
    gui_measure_image(fmrdo_main_draw.volume_dec_button.up_img, &w, &h);
    fmrdo_main_draw.volume_dec_button.w = (S16) w;
    fmrdo_main_draw.volume_dec_button.h = (S16) h;
    fmrdo_main_draw.volume_dec_button.down = FALSE;

    /* setting icon */
    fmrdo_main_draw.setting_button.x = skin_p->setting_x;
    fmrdo_main_draw.setting_button.y = skin_p->setting_y;
    fmrdo_main_draw.setting_button.up_img = (PU8) GetImage(skin_p->setting_up_image_id);
    fmrdo_main_draw.setting_button.down_img = (PU8) GetImage(skin_p->setting_down_image_id);
    gui_measure_image(fmrdo_main_draw.setting_button.up_img, &w, &h);
    fmrdo_main_draw.setting_button.w = (S16) w;
    fmrdo_main_draw.setting_button.h = (S16) h;
    fmrdo_main_draw.setting_button.down = FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* tuner scale */
    fmrdo_main_draw.tuner_scale.bg_img = (PU8) GetImage(skin_p->tuner_scale_bg_image_id);
    fmrdo_main_draw.tuner_scale.ind_img = (PU8) GetImage(skin_p->tuner_scale_ind_image_id);
    fmrdo_main_draw.tuner_scale.type = skin_p->tuner_scale_type;        /* 0: horizontal, 1: vertical */
    fmrdo_main_draw.tuner_scale.x = skin_p->tuner_scale_x;
    fmrdo_main_draw.tuner_scale.y = skin_p->tuner_scale_y;
    gui_measure_image(fmrdo_main_draw.tuner_scale.bg_img, &w, &h);
    fmrdo_main_draw.tuner_scale.w = (S16) w;
    fmrdo_main_draw.tuner_scale.h = (S16) h;
    gui_measure_image(fmrdo_main_draw.tuner_scale.ind_img, &w, &h);
    fmrdo_main_draw.tuner_scale.ind_w = (S16) w;
    fmrdo_main_draw.tuner_scale.ind_h = (S16) h;
    fmrdo_main_draw.tuner_scale.ind_offset = skin_p->tunner_scale_ind_offset;
    fmrdo_main_draw.tuner_scale.ind_start_gap = skin_p->tuner_scale_start_gap;
    fmrdo_main_draw.tuner_scale.ind_end_gap = skin_p->tuner_scale_end_gap;

    /* step down button */
    fmrdo_main_draw.step_down_button.up_img = (PU8) GetImage(skin_p->step_down_button_up_image_id);
    fmrdo_main_draw.step_down_button.down_img = (PU8) GetImage(skin_p->step_down_button_down_image_id);
    fmrdo_main_draw.step_down_button.x = skin_p->step_down_button_x;
    fmrdo_main_draw.step_down_button.y = skin_p->step_down_button_y;
    gui_measure_image(fmrdo_main_draw.step_down_button.up_img, &w, &h);
    fmrdo_main_draw.step_down_button.w = (S16) w;
    fmrdo_main_draw.step_down_button.h = (S16) h;

    /* step up button */
    fmrdo_main_draw.step_up_button.up_img = (PU8) GetImage(skin_p->step_up_button_up_image_id);
    fmrdo_main_draw.step_up_button.down_img = (PU8) GetImage(skin_p->step_up_button_down_image_id);
    fmrdo_main_draw.step_up_button.x = skin_p->step_up_button_x;
    fmrdo_main_draw.step_up_button.y = skin_p->step_up_button_y;
    gui_measure_image(fmrdo_main_draw.step_up_button.up_img, &w, &h);
    fmrdo_main_draw.step_up_button.w = (S16) w;
    fmrdo_main_draw.step_up_button.h = (S16) h;

    /* search button */
    fmrdo_main_draw.search_button.on_up_img = (PU8) GetImage(skin_p->search_button_on_up_image_id);
    fmrdo_main_draw.search_button.on_down_img = (PU8) GetImage(skin_p->search_button_on_down_image_id);
    fmrdo_main_draw.search_button.off_up_img = (PU8) GetImage(skin_p->search_button_off_up_image_id);
    fmrdo_main_draw.search_button.off_down_img = (PU8) GetImage(skin_p->search_button_off_down_image_id);
    fmrdo_main_draw.search_button.x = skin_p->search_button_x;
    fmrdo_main_draw.search_button.y = skin_p->search_button_y;
    gui_measure_image(fmrdo_main_draw.search_button.on_up_img, &w, &h);
    fmrdo_main_draw.search_button.w = (S16) w;
    fmrdo_main_draw.search_button.h = (S16) h;

    /* power button */
    fmrdo_main_draw.power_button.on_up_img = (PU8) GetImage(skin_p->power_button_on_up_image_id);
    fmrdo_main_draw.power_button.on_down_img = (PU8) GetImage(skin_p->power_button_on_down_image_id);
    fmrdo_main_draw.power_button.off_up_img = (PU8) GetImage(skin_p->power_button_off_up_image_id);
    fmrdo_main_draw.power_button.off_down_img = (PU8) GetImage(skin_p->power_button_off_down_image_id);
    fmrdo_main_draw.power_button.x = skin_p->power_button_x;
    fmrdo_main_draw.power_button.y = skin_p->power_button_y;
    gui_measure_image(fmrdo_main_draw.power_button.on_up_img, &w, &h);
    fmrdo_main_draw.power_button.w = (S16) w;
    fmrdo_main_draw.power_button.h = (S16) h;

#if defined(__MMI_FM_RADIO_RECORD__)
    /* Record Indication Icon */
    fmrdo_main_draw.rec_button.on_up_img = (PU8) GetImage(skin_p->rec_button_image_id); /* Use same image for all */
    fmrdo_main_draw.rec_button.on_down_img = (PU8) GetImage(skin_p->rec_button_image_id);
    fmrdo_main_draw.rec_button.off_up_img = (PU8) GetImage(skin_p->rec_button_image_id);
    fmrdo_main_draw.rec_button.off_down_img = (PU8) GetImage(skin_p->rec_button_image_id);
    fmrdo_main_draw.rec_button.x = skin_p->rec_button_x;
    fmrdo_main_draw.rec_button.y = skin_p->rec_button_y;
    gui_measure_image(fmrdo_main_draw.rec_button.on_up_img, &w, &h);
    fmrdo_main_draw.rec_button.w = (S16) w;
    fmrdo_main_draw.rec_button.h = (S16) h;

    /* Pause Indication Icon */
    fmrdo_main_draw.rec_pause_button.on_up_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);     /* Use same image for all */
    fmrdo_main_draw.rec_pause_button.on_down_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);
    fmrdo_main_draw.rec_pause_button.off_up_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);
    fmrdo_main_draw.rec_pause_button.off_down_img = (PU8) GetImage(skin_p->rec_pause_button_image_id);
    fmrdo_main_draw.rec_pause_button.x = skin_p->rec_button_x;
    fmrdo_main_draw.rec_pause_button.y = skin_p->rec_button_y;
    gui_measure_image(fmrdo_main_draw.rec_pause_button.on_up_img, &w, &h);
    fmrdo_main_draw.rec_pause_button.w = (S16) w;
    fmrdo_main_draw.rec_pause_button.h = (S16) h;

    /* Record Duration */
    fmrdo_main_draw.rec_base_num_id = skin_p->rec_duration_number_id_base;
    fmrdo_main_draw.rec_num_col_id = skin_p->rec_duration_number_col_image_id;

    gui_measure_image((PU8) GetImage(fmrdo_main_draw.rec_base_num_id), &w, &h);
    gui_measure_image((PU8) GetImage(fmrdo_main_draw.rec_num_col_id), &w2, &h2);

    fmrdo_main_draw.timer_hr_0_offset_x = skin_p->rec_duration_x;
    fmrdo_main_draw.timer_hr_1_offset_x = fmrdo_main_draw.timer_hr_0_offset_x + w;
    fmrdo_main_draw.timer_col_0_offset_x = fmrdo_main_draw.timer_hr_1_offset_x + w;
    fmrdo_main_draw.timer_min_0_offset_x = fmrdo_main_draw.timer_col_0_offset_x + w2;
    fmrdo_main_draw.timer_min_1_offset_x = fmrdo_main_draw.timer_min_0_offset_x + w;
    fmrdo_main_draw.timer_col_1_offset_x = fmrdo_main_draw.timer_min_1_offset_x + w;
    fmrdo_main_draw.timer_sec_0_offset_x = fmrdo_main_draw.timer_col_1_offset_x + w2;
    fmrdo_main_draw.timer_sec_1_offset_x = fmrdo_main_draw.timer_sec_0_offset_x + w;

    fmrdo_main_draw.timer_offset_y = skin_p->rec_duration_y;
    fmrdo_main_draw.timer_offset_x2 = fmrdo_main_draw.timer_sec_1_offset_x + w;
    fmrdo_main_draw.timer_offset_y2 = fmrdo_main_draw.timer_offset_y + h;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_subLCD_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_subLCD_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(x1, y1, x2, y2, c);
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_subLCD_text_scroll_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_subLCD_text_scroll_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    gui_handle_scrolling_text(&fmrdo_sub_LCD_scrolling_title);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_subLCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_show     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_subLCD(BOOL is_show)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color text_color = gui_color(0, 0, 0);
    S32 x1, y1, x2, y2, x, y, str_w, str_h;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;
    UI_string_type title;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_ready)
    {
        return;
    }

    mmi_fmrdo_set_subLCD_shown(TRUE);

    UI_set_sub_LCD_graphics_context();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    if (fmrdo_sub_LCD_scrolling_title_p != NULL)
    {
        gui_scrolling_text_stop(fmrdo_sub_LCD_scrolling_title_p);
        fmrdo_sub_LCD_scrolling_title_p = NULL;
    }

    /* clear background */
    x1 = 0;
    y1 = 13;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - 1;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    mmi_fmrdo_redraw_subLCD_background(x1, y1, x2, y2);

    if (is_show)
    {
        title = (UI_string_type) mmi_fmrdo_get_channel_name_or_freq();

        /* draw song name */
        gui_set_font(&MMI_medium_font);
        gui_measure_string(title, &str_w, &str_h);
        x = (UI_device_width - str_w) / 2;
        y = 12 + (UI_device_height - 12 - str_h) / 2;
        if (x >= 0)
        {
            gui_push_text_clip();
            gui_set_text_clip(x, y, x + str_w - 1, y + str_h - 1);
            gui_set_text_color(text_color);
            gui_move_text_cursor(x, y);
            gui_print_text(title);
            gui_pop_text_clip();
        }
        else
        {
            /* scroll */
            x = 0;
            fmrdo_sub_LCD_scrolling_title_p = &fmrdo_sub_LCD_scrolling_title;
            gui_create_scrolling_text(
                fmrdo_sub_LCD_scrolling_title_p,
                x + 2,
                y,
                UI_device_width - 4,
                str_h,
                title,
                mmi_fmrdo_subLCD_text_scroll_handler,
                mmi_fmrdo_redraw_subLCD_background,
                text_color,
                text_color);
            fmrdo_sub_LCD_scrolling_title_p->text_font = MMI_medium_font;
            gui_show_scrolling_text(fmrdo_sub_LCD_scrolling_title_p);
        }
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_subLCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_subLCD()
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_subLCD_shown)
    {
        bitmap *saved_graphics_context = current_LCD_device_bitmap;

        UI_set_sub_LCD_graphics_context();

        if (fmrdo_sub_LCD_scrolling_title_p != NULL)
        {
            gui_scrolling_text_stop(fmrdo_sub_LCD_scrolling_title_p);
            fmrdo_sub_LCD_scrolling_title_p = NULL;
        }
        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }

        mmi_fmrdo_set_subLCD_shown(FALSE);
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_show_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left_softkey        [IN]        
 *  right_softkey       [IN]        
 *  skin_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_show_main(U16 left_softkey, U16 right_softkey, U8 skin_index)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_multi_layer_enable();

    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&fmrdo_osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &fmrdo_skin_layer);
    gdi_layer_set_blt_layer(fmrdo_skin_layer, fmrdo_osd_layer, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* Init images, always get image in ENFB project */
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    if (!fmrdo_main_draw.is_ready || fmrdo_main_draw.skin_index != skin_index)
#endif
    {
        mmi_fmrdo_init_main_images(skin_index);
        fmrdo_main_draw.skin_index = skin_index;
        fmrdo_main_draw.is_ready = TRUE;
        fmrdo_main_draw.is_channel_name_scroll_ready = FALSE;
    }
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if((fmrdo_main_draw.skin_index == 0) && (skin_index == 0))
    {
        mmi_fmrdo_init_main_images(skin_index);
    }
#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/
    
#ifdef __GDI_MEMORY_PROFILE_2__
    is_fmrdo_skin_layer_drawn = FALSE;
#endif 

    clear_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(left_softkey);
    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(right_softkey);
    SetKeyHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK, KEY_EVENT_DOWN);

    /* associate functions */
    ExitCategoryFunction = mmi_fmrdo_hide_main;
    RedrawCategoryFunction = mmi_fmrdo_redraw_main_all;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    /* draw screen */
    mmi_fmrdo_redraw_main_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hide_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hide_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_flatten_to_base(fmrdo_skin_layer, fmrdo_osd_layer, 0, 0);
    gdi_layer_free(fmrdo_skin_layer);
    gdi_layer_multi_layer_disable();

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(fmrdo_osd_layer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
#ifdef __MMI_TOUCH_SCREEN__
    fmrdo_main_draw.volume_dec_button.down = FALSE;
    fmrdo_main_draw.volume_inc_button.down = FALSE;
    fmrdo_main_draw.setting_button.down = FALSE;

    fmrdo_pen_event_on_object = FMRDO_PEN_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_FM_RADIO_ANIMATION__
    /* stop animation */
    mmi_fmrdo_animation_stop();
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 
    /* associate functions */
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_LSK_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_LSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(fmrdo_main_draw.LSK_text_color);
    gui_set_text_border_color(fmrdo_main_draw.LSK_text_border_color);

    /* show LSK */
    gui_measure_string(fmrdo_main_draw.LSK_text, &str_w, &str_h);
    x1 = FMRDO_LSK_X_OFFSET;
    y1 = UI_device_height - str_h - FMRDO_LSK_Y_OFFSET;
    x2 = str_w + FMRDO_LSK_X_OFFSET;
    y2 = UI_device_height - FMRDO_LSK_Y_OFFSET;
    gui_push_clip();
    gui_set_clip(x1 - 2, y1 - 2, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1 - 2, y1 - 2, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    gui_print_bordered_text(fmrdo_main_draw.LSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1 - 2, y1 - 2, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_RSK_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_RSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(fmrdo_main_draw.RSK_text_color);
    gui_set_text_border_color(fmrdo_main_draw.RSK_text_border_color);

    /* show RSK */
    gui_measure_string(fmrdo_main_draw.RSK_text, &str_w, &str_h);
    x1 = UI_device_width - str_w - FMRDO_RSK_X_OFFSET;
    y1 = UI_device_height - str_h - FMRDO_RSK_Y_OFFSET;
    x2 = UI_device_width - FMRDO_RSK_X_OFFSET;
    y2 = UI_device_height - FMRDO_RSK_Y_OFFSET;
    gui_push_clip();
    gui_set_clip(x1 - 2, y1 - 2, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1 - 2, y1 - 2, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    gui_print_bordered_text(fmrdo_main_draw.RSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1 - 2, y1 - 2, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_LSK_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_LSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(fmrdo_main_draw.LSK_text_color);
    gui_set_text_border_color(fmrdo_main_draw.LSK_text_border_color);

    /* show LSK */
    gui_measure_string(fmrdo_main_draw.LSK_text, &str_w, &str_h);
    x1 = FMRDO_LSK_X_OFFSET - 1;
    y1 = UI_device_height - str_h - FMRDO_LSK_Y_OFFSET - 1;
    x2 = str_w + FMRDO_LSK_X_OFFSET - 1;
    y2 = UI_device_height - FMRDO_LSK_Y_OFFSET - 1;
    gui_push_clip();
    gui_set_clip(x1, y1 - 1, UI_device_width / 2 - 10, y2 + 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1 - 1, UI_device_width / 2 - 10, y2 + 1, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    gui_print_bordered_text(fmrdo_main_draw.LSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1 - 1, UI_device_width / 2 - 10, y2 + 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_RSK_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_RSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(fmrdo_main_draw.RSK_text_color);
    gui_set_text_border_color(fmrdo_main_draw.RSK_text_border_color);

    /* show RSK */
    gui_measure_string(fmrdo_main_draw.RSK_text, &str_w, &str_h);
    x1 = UI_device_width - str_w - FMRDO_RSK_X_OFFSET - 1;
    y1 = UI_device_height - str_h - FMRDO_RSK_Y_OFFSET - 1;
    x2 = UI_device_width - FMRDO_RSK_X_OFFSET - 1;
    y2 = UI_device_height - FMRDO_RSK_Y_OFFSET - 1;
    gui_push_clip();
    gui_set_clip(UI_device_width / 2 + 10, y1 - 1, x2 + 1, y2 + 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(UI_device_width / 2 + 10, y1 - 1, x2 + 1, y2 + 1, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 
    gui_pop_clip();
    gui_push_text_clip();
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    gui_print_bordered_text(fmrdo_main_draw.RSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_device_width / 2 + 10, y1 - 1, x2 + 1, y2 + 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scroll_channel_name_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scroll_channel_name_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&fmrdo_main_draw.channel_name_scroll);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    /* we don't set clip here because its caller will do that */
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_push_text_clip();

    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

#ifdef __GDI_MEMORY_PROFILE_2__
    if (!is_fmrdo_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
        /* main background */
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);

        /* animation */
    #ifdef __MMI_FM_RADIO_ANIMATION__
        fmrdo_main_draw.animation.img_handle = GDI_ERROR_HANDLE;
        if (g_fmrdo.is_power_on)
        {
            gdi_image_draw_animation(
                fmrdo_main_draw.animation.x,
                fmrdo_main_draw.animation.y,
                fmrdo_main_draw.animation.animation_img,
                &fmrdo_main_draw.animation.img_handle);
        }
        else
        {
            gdi_image_draw(
                fmrdo_main_draw.animation.x,
                fmrdo_main_draw.animation.y,
                fmrdo_main_draw.animation.animation_img);
        }
    #endif /* __MMI_FM_RADIO_ANIMATION__ */ 

    #ifdef __GDI_MEMORY_PROFILE_2__
        /* tuner scale background */
        gui_show_image(
            fmrdo_main_draw.tuner_scale.x,
            fmrdo_main_draw.tuner_scale.y,
            fmrdo_main_draw.tuner_scale.bg_img);
        is_fmrdo_skin_layer_drawn = TRUE;
        gdi_layer_pop_and_restore_active();
    }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* show LSK */
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(fmrdo_main_draw.LSK_text_color);
    gui_set_text_border_color(fmrdo_main_draw.LSK_text_border_color);
    gui_measure_string(fmrdo_main_draw.LSK_text, &str_w, &str_h);

    x1 = FMRDO_LSK_X_OFFSET - 1;
    y1 = UI_device_height - str_h - FMRDO_LSK_Y_OFFSET - 1;
    x2 = str_w + FMRDO_LSK_X_OFFSET - 1;
    y2 = UI_device_height - FMRDO_LSK_Y_OFFSET - 1;
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    gui_print_bordered_text(fmrdo_main_draw.LSK_text);
#ifdef __MMI_TOUCH_SCREEN__
    LSK_area.num = 4;
    LSK_area.points = (mmi_pen_point_struct*) LSK_points;
    LSK_points[0].x = LSK_points[3].x = x1;
    LSK_points[0].y = LSK_points[1].y = y1;
    LSK_points[1].x = LSK_points[2].x = x2 + 1;
    LSK_points[2].y = LSK_points[3].y = y2 + 1;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* show RSK */
    gui_set_text_color(fmrdo_main_draw.RSK_text_color);
    gui_set_text_border_color(fmrdo_main_draw.RSK_text_border_color);
    gui_measure_string(fmrdo_main_draw.RSK_text, &str_w, &str_h);
    x1 = UI_device_width - str_w - FMRDO_RSK_X_OFFSET - 1;
    y1 = UI_device_height - str_h - FMRDO_RSK_Y_OFFSET - 1;
    x2 = UI_device_width - FMRDO_RSK_X_OFFSET - 1;
    y2 = UI_device_height - FMRDO_RSK_Y_OFFSET - 1;
    gui_set_text_clip(x1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    gui_print_bordered_text(fmrdo_main_draw.RSK_text);
#ifdef __MMI_TOUCH_SCREEN__
    RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = x1;
    RSK_points[0].y = RSK_points[1].y = y1;
    RSK_points[1].x = RSK_points[2].x = x2 + 1;
    RSK_points[2].y = RSK_points[3].y = y2 + 1;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    gui_pop_text_clip();
    gui_pop_clip();

    /* draw components */
    mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
    mmi_fmrdo_redraw_main_channel_name(0);
    mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.frequency);
    mmi_fmrdo_redraw_main_volume();
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_DOWN,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)));
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_UP,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)));
    mmi_fmrdo_redraw_main_toggle_button(
        FMRDO_BUTTON_SEARCH,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH)),
        g_fmrdo.is_search_on,
        TRUE);
    mmi_fmrdo_redraw_main_toggle_button(
        FMRDO_BUTTON_POWER,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_POWER)),
        g_fmrdo.is_power_on,
        TRUE);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_fmrdo_redraw_main_push_down_button(0, fmrdo_main_draw.volume_dec_button.down);
    mmi_fmrdo_redraw_main_push_down_button(1, fmrdo_main_draw.volume_inc_button.down);
    mmi_fmrdo_redraw_main_push_down_button(2, fmrdo_main_draw.setting_button.down);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freq            [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_frequency(U16 freq, BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 x1 = fmrdo_main_draw.frequency.x;
    S32 y1 = fmrdo_main_draw.frequency.y;
    S32 x2 = fmrdo_main_draw.frequency.x + fmrdo_main_draw.frequency.w - 1;
    S32 y2 = fmrdo_main_draw.frequency.y + fmrdo_main_draw.frequency.h - 1;
    S32 prefix_str_w, prefix_str_h, str_w, str_h;
    UI_character_type prefix_str[] = L"FM ";
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(str, "%d.%d", freq / 10, freq % 10);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    /* background & text */
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 

    if (is_shown)
    {
        gui_push_text_clip();
        gui_set_text_clip(x1, y1, x2, y2);

        if (g_fmrdo.is_power_on)
        {
            gui_set_text_color(fmrdo_main_draw.frequency_text_on_color);
        }
        else
        {
            gui_set_text_color(fmrdo_main_draw.frequency_text_off_color);
        }

        gui_set_font(&MMI_medium_font);
        gui_measure_string(str, &str_w, &str_h);
        gui_set_font(&MMI_small_font);
        gui_measure_string(prefix_str, &prefix_str_w, &prefix_str_h);
        x = x1 + (fmrdo_main_draw.frequency.w - str_w - prefix_str_w) / 2;
        y = y1 + (fmrdo_main_draw.frequency.h - str_h) / 2;

        /* prefix "FM " */
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x + prefix_str_w - 1, y + str_h - prefix_str_h - 1);
        }
        else
        {
            gui_move_text_cursor(x, y + str_h - prefix_str_h - 1);
        }
        gui_print_text(prefix_str);

        /* frequency number */
        gui_set_font(&MMI_medium_font);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x + prefix_str_w + str_w - 1, y);
        }
        else
        {
            gui_move_text_cursor(x + prefix_str_w - 1, y);
        }
        gui_print_text(str);

        gui_pop_text_clip();
    }
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_channel_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  other_str       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_channel_name(UI_string_type other_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.channel_name.x;
    S32 y1 = fmrdo_main_draw.channel_name.y;
    S32 x2 = fmrdo_main_draw.channel_name.x + fmrdo_main_draw.channel_name.w - 1;
    S32 y2 = fmrdo_main_draw.channel_name.y + fmrdo_main_draw.channel_name.h - 1;
    S32 str_w, str_h;
    UI_string_type str;
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    UI_string_type prefix_str;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (other_str == 0)
    {
        if (g_fmrdo.channel_index >= 0)
        {
            str = fmrdo_main_draw.channel_name_str;
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
            if(g_fmrdo.in_subLCD_main_screen)
            {
                prefix_str = (UI_string_type)GetString(STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_NAME_CH);
                kal_wsprintf(str,"%w %d",prefix_str,g_fmrdo.channel_index+1);
            }
            else
        #endif
            {
                kal_wsprintf(str, "%d. %w", g_fmrdo.channel_index + 1, g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
            }
        }
        else
        {
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
            if(g_fmrdo.in_subLCD_main_screen)
            {
                str = (UI_string_type)GetString(STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_NAME_RADIO);
            }
            else
        #endif
            {
                str = (UI_string_type) GetString(STR_ID_FMRDO_TITLE);
            }
                
        }
    }
    else
    {
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
            if(g_fmrdo.in_subLCD_main_screen)
            {
                str = (UI_string_type)GetString(STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_NAME_SEARCH);
            }
            else
        #endif
            {
                str = other_str;
            }
    }

    /* stop previous scroll text */
    if (!fmrdo_main_draw.is_channel_name_scroll_ready)
    {
        gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
    }
    else
    {
        fmrdo_main_draw.is_channel_name_scroll_ready = TRUE;
    }

    gui_create_scrolling_text(
        &fmrdo_main_draw.channel_name_scroll,
        x1 + 2,
        y1 + 1,
        fmrdo_main_draw.channel_name.w - 4,
        fmrdo_main_draw.channel_name.h - 2,
        str,
        mmi_fmrdo_scroll_channel_name_hdlr,
        mmi_fmrdo_redraw_main_background,
        fmrdo_main_draw.channel_name_text_color,
        fmrdo_main_draw.channel_name_text_border_color);
    fmrdo_main_draw.channel_name_scroll.text_font = MMI_medium_font;
    fmrdo_main_draw.channel_name_scroll.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    /* stop scrolling if necessary */
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);
#ifdef __MMI_FM_RADIO_ON_SUBLCD__
    if(g_fmrdo.in_subLCD_main_screen)
    {
        gui_set_font(&MMI_small_font); 
    }
    else
#endif
    {
        gui_set_font(&MMI_medium_font);
    }
    gui_measure_string(str, &str_w, &str_h);

    /* background */
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 

    /* text */
    if (str_w > fmrdo_main_draw.channel_name.w - 4)
    {
        /* scrolling */
        gui_change_scrolling_text(&fmrdo_main_draw.channel_name_scroll, str);
        gui_show_scrolling_text(&fmrdo_main_draw.channel_name_scroll);
    }
    else
    {
        /* no scrolling */
        gui_push_text_clip();
        gui_set_text_clip(x1, y1, x2, y2);

        gui_set_text_color(fmrdo_main_draw.channel_name_text_color);
        gui_set_text_border_color(fmrdo_main_draw.channel_name_text_border_color);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.channel_name.w + str_w) / 2,
                y1 + (fmrdo_main_draw.channel_name.h - str_h) / 2);
        }
        else
        {
            gui_move_text_cursor(
                x1 + (fmrdo_main_draw.channel_name.w - str_w) / 2,
                y1 + (fmrdo_main_draw.channel_name.h - str_h) / 2);
        }
        gui_print_bordered_text(str);
        gui_pop_text_clip();
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_channel_tuner
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_channel_tuner(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.tuner_scale.x;
    S32 y1 = fmrdo_main_draw.tuner_scale.y;
    S32 x2 = fmrdo_main_draw.tuner_scale.x + fmrdo_main_draw.tuner_scale.w - 1;
    S32 y2 = fmrdo_main_draw.tuner_scale.y + fmrdo_main_draw.tuner_scale.h - 1;
    S32 delta;

#ifndef __GDI_MEMORY_PROFILE_2__
    BOOL outside = FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmrdo_main_draw.tuner_scale.type == 0)  /* 0: horizontal, 1: vertical */
    {
        if (fmrdo_main_draw.tuner_scale.ind_offset < 0)
        {
            y1 += fmrdo_main_draw.tuner_scale.ind_offset;
        }
        delta =
            fmrdo_main_draw.tuner_scale.y + fmrdo_main_draw.tuner_scale.ind_offset + fmrdo_main_draw.tuner_scale.ind_h -
            1;
        if (delta > y2)
        {
            y2 = delta;
        #ifndef __GDI_MEMORY_PROFILE_2__
            outside = TRUE;
        #endif 
        }
    }
    else
    {
        if (fmrdo_main_draw.tuner_scale.ind_offset < 0)
        {
            x1 += fmrdo_main_draw.tuner_scale.ind_offset;
        }

        delta =
            fmrdo_main_draw.tuner_scale.x + fmrdo_main_draw.tuner_scale.ind_offset + fmrdo_main_draw.tuner_scale.ind_w -
            1;
        if (delta > x2)
        {
            x2 = delta;
        #ifndef __GDI_MEMORY_PROFILE_2__
            outside = TRUE;
        #endif 
        }
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_clip(x1, y1, x2, y2);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    if (outside)
    {
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);   /* background */
    }

    /* tuner scale background */
    gui_show_image(fmrdo_main_draw.tuner_scale.x, fmrdo_main_draw.tuner_scale.y, fmrdo_main_draw.tuner_scale.bg_img);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* tuner scale indicator */
    if (fmrdo_main_draw.tuner_scale.type == 0)  /* 0: horizontal, 1: vertical */
    {
        S32 w = fmrdo_main_draw.tuner_scale.w - fmrdo_main_draw.tuner_scale.ind_start_gap -
            fmrdo_main_draw.tuner_scale.ind_end_gap - fmrdo_main_draw.tuner_scale.ind_w;
        gui_show_image(
            fmrdo_main_draw.tuner_scale.x + fmrdo_main_draw.tuner_scale.ind_start_gap + (freq - MIN_FM_FREQUENCY) * w / FM_BANDWIDTH,
            fmrdo_main_draw.tuner_scale.y + fmrdo_main_draw.tuner_scale.ind_offset,
            fmrdo_main_draw.tuner_scale.ind_img);
    }
    else
    {
        S32 h = fmrdo_main_draw.tuner_scale.h - fmrdo_main_draw.tuner_scale.ind_start_gap -
            fmrdo_main_draw.tuner_scale.ind_end_gap - fmrdo_main_draw.tuner_scale.ind_h;
        gui_show_image(
            fmrdo_main_draw.tuner_scale.x + fmrdo_main_draw.tuner_scale.ind_offset,
            fmrdo_main_draw.tuner_scale.y + fmrdo_main_draw.tuner_scale.ind_start_gap + (freq - MIN_FM_FREQUENCY) * h / FM_BANDWIDTH,
            fmrdo_main_draw.tuner_scale.ind_img);
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = fmrdo_main_draw.volume.x;
    S32 y1 = fmrdo_main_draw.volume.y;
    S32 x2 = fmrdo_main_draw.volume.x + fmrdo_main_draw.volume.w - 1;
    S32 y2 = fmrdo_main_draw.volume.y + fmrdo_main_draw.volume.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_clip(x1, y1, x2, y2);

    /* background */
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 

    /* volume */
    if (fmrdo_main_draw.volume.type == 0)   /* 0: horizontal, 1: vertical */
    {
        S32 delta = ((U32) g_fmrdo.volume + 1) * (fmrdo_main_draw.volume.w - fmrdo_main_draw.volume.ind_start_gap -
                                                  fmrdo_main_draw.volume.ind_end_gap) / MAX_VOL_LEVEL;
        gui_set_clip(x1, y1, x1 + fmrdo_main_draw.volume.ind_start_gap + delta - 1, y2);
    }
    else
    {
        S32 delta = ((U32) g_fmrdo.volume + 1) * (fmrdo_main_draw.volume.h - fmrdo_main_draw.volume.ind_start_gap -
                                                  fmrdo_main_draw.volume.ind_end_gap) / MAX_VOL_LEVEL;
        gui_set_clip(x1, y2 - fmrdo_main_draw.volume.ind_start_gap - delta - 1, x2, y2);
    }

    gui_show_image(x1, y1, fmrdo_main_draw.volume.bg_img);

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_push_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button      [IN]        
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_push_button(U8 button, BOOL is_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_push_button_struct *push_button_p;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
        case FMRDO_BUTTON_STEP_UP:
            push_button_p = &fmrdo_main_draw.step_up_button;
            break;
        case FMRDO_BUTTON_STEP_DOWN:
            push_button_p = &fmrdo_main_draw.step_down_button;
            break;
        default:
            return;
    }
    x1 = push_button_p->x;
    y1 = push_button_p->y;
    x2 = push_button_p->x + push_button_p->w - 1;
    y2 = push_button_p->y + push_button_p->h - 1;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_clip(x1, y1, x2, y2);

    /* button */
    if (is_down)
    {
        gui_show_image(x1, y1, push_button_p->down_img);
    }
    else
    {
        gui_show_image(x1, y1, push_button_p->up_img);
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_toggle_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button          [IN]        
 *  is_down         [IN]        
 *  is_on           [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_toggle_button(U8 button, BOOL is_down, BOOL is_on, BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_toggle_button_struct *toggle_button_p;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
        case FMRDO_BUTTON_POWER:
            toggle_button_p = &fmrdo_main_draw.power_button;
            break;
        case FMRDO_BUTTON_SEARCH:
            toggle_button_p = &fmrdo_main_draw.search_button;
        #ifdef __MMI_FM_RADIO_ON_SUBLCD__
            if(g_fmrdo.in_subLCD_main_screen)
            {
                 x1 = toggle_button_p->x;
                 y1 = toggle_button_p->y;
                 x2 = toggle_button_p->x + toggle_button_p->w - 1;
                 y2 = toggle_button_p->y + toggle_button_p->h - 1;

                 #if(UI_DOUBLE_BUFFER_SUPPORT)
                 gui_lock_double_buffer();
                 #endif 

                 gui_push_clip();

                 gui_set_clip(x1, y1, x2, y2);
                 switch(g_fmrdo.subLCD_operation_mode)
                 {
                     case FMRDO_SUB_LCD_STEP_MODE:
                        gui_show_image(x1, y1, toggle_button_p->on_up_img);
                        break;
                     case FMRDO_SUB_LCD_CHANNEL_MODE:
                        gui_show_image(x1, y1, toggle_button_p->on_down_img);
                        break;
                     case FMRDO_SUB_LCD_SEARCH_MODE:
                        gui_show_image(x1, y1, toggle_button_p->off_up_img);
                        break;
                     default:
                        break;
                 }
                 gui_pop_clip();
                 #if(UI_DOUBLE_BUFFER_SUPPORT)
                 gui_unlock_double_buffer();
                 gui_BLT_double_buffer(x1, y1, x2, y2);
                 #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
                 return;
            }
        #endif /*__MMI_FM_RADIO_ON_SUBLCD__*/
            break;
    #if defined(__MMI_FM_RADIO_RECORD__)
        case FMRDO_BUTTON_REC:
            toggle_button_p = &fmrdo_main_draw.rec_button;
            break;
        case FMRDO_BUTTON_REC_PAUSE:
            toggle_button_p = &fmrdo_main_draw.rec_pause_button;
            break;
    #endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
        default:
            return;
    }
    x1 = toggle_button_p->x;
    y1 = toggle_button_p->y;
    x2 = toggle_button_p->x + toggle_button_p->w - 1;
    y2 = toggle_button_p->y + toggle_button_p->h - 1;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_clip(x1, y1, x2, y2);

    if (is_shown)
    {
        /* button */
        if (is_on)
        {
            if (is_down)
            {
                gui_show_image(x1, y1, toggle_button_p->on_down_img);
            }
            else
            {
                gui_show_image(x1, y1, toggle_button_p->on_up_img);
            }
        }
        else
        {
            if (is_down)
            {
                gui_show_image(x1, y1, toggle_button_p->off_down_img);
            }
            else
            {
                gui_show_image(x1, y1, toggle_button_p->off_up_img);
            }
        }
    }
    else    /* Clear to background */
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    #else 
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);
    #endif 
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/* MTK Leo add 20050301, add touch screen support for FM Radio */
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_push_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button      [IN]        0 = volume_dec_button, 1 = volume_inc_button, 2 = setting_button
 *  is_down     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_push_down_button(U8 button, BOOL is_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmrdo_main_push_down_button_struct *push_down_button_p;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
        case 0:
            push_down_button_p = &fmrdo_main_draw.volume_dec_button;
            break;
        case 1:
            push_down_button_p = &fmrdo_main_draw.volume_inc_button;
            break;
        case 2:
            push_down_button_p = &fmrdo_main_draw.setting_button;
            break;
        default:
            return;
    }
    x1 = push_down_button_p->x;
    y1 = push_down_button_p->y;
    x2 = push_down_button_p->x + push_down_button_p->w - 1;
    y2 = push_down_button_p->y + push_down_button_p->h - 1;
    push_down_button_p->down = is_down;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, (is_down ? push_down_button_p->down_img : push_down_button_p->up_img));
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

#if defined(__MMI_FM_RADIO_RECORD__)
#define FMRDO_REC_X1 178 //sc.wu fm record
#define FMRDO_REC_Y1 164
#define FMRDO_REC_X2 205
#define FMRDO_REC_Y2 193

MMI_BOOL mmi_pen_check_inside_rec(mmi_pen_point_struct pos)
{
    if(pos.x >= FMRDO_REC_X1 && pos.x<= FMRDO_REC_X2)
        {
            if(pos.y >= FMRDO_REC_Y1 && pos.y <= FMRDO_REC_Y2)
                {                    
                    return TRUE;
                }
        }    

    return FALSE;
}

void mmi_fmrdo_pen_down_hdlr_custom_ele(mmi_pen_point_struct pos)
{
#ifndef  FM_RADIO_WITH_TV
	FuncPtr currFuncPtr = NULL;
				
    if(mmi_pen_check_inside_rec(pos))
    	{
        	//mmi_fmrdo_release_record_button();
        	currFuncPtr = currKeyFuncPtrs[KEY_ENTER][KEY_EVENT_UP];

		if (currFuncPtr == NULL)
		{
			currFuncPtr = currKeyFuncPtrs[KEY_LSK][KEY_EVENT_UP];
		}
		
		(*currFuncPtr)();		
    	}	
#else
    if(mmi_pen_check_inside_rec(pos))
        mmi_fmrdo_release_record_button();
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmrdo_pen_event_on_object = FMRDO_PEN_NONE;

    for (i = FMRDO_PEN_LSK; i < FMRDO_PEN_COUNT; i++)
    {
        switch (i)
        {
            case FMRDO_PEN_LSK:
                area = (mmi_pen_polygon_area_struct*) & LSK_area;
                point = pos;
                break;
            case FMRDO_PEN_RSK:
                area = (mmi_pen_polygon_area_struct*) & RSK_area;
                point = pos;
                break;
            case FMRDO_PEN_MAIN_STEP_UP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->step_up_button_area;
                point.x = pos.x - skin_p->step_up_button_x;
                point.y = pos.y - skin_p->step_up_button_y;
                break;
            case FMRDO_PEN_MAIN_STEP_DOWN:
                area = (mmi_pen_polygon_area_struct*) & skin_p->step_down_button_area;
                point.x = pos.x - skin_p->step_down_button_x;
                point.y = pos.y - skin_p->step_down_button_y;
                break;
            case FMRDO_PEN_MAIN_POWER:
                area = (mmi_pen_polygon_area_struct*) & skin_p->power_button_area;
                point.x = pos.x - skin_p->power_button_x;
                point.y = pos.y - skin_p->power_button_y;
                break;
            case FMRDO_PEN_MAIN_SEARCH:
                area = (mmi_pen_polygon_area_struct*) & skin_p->search_button_area;
                point.x = pos.x - skin_p->search_button_x;
                point.y = pos.y - skin_p->search_button_y;
                break;
            case FMRDO_PEN_MAIN_SETTING:
                area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
                point.x = pos.x - skin_p->setting_x;
                point.y = pos.y - skin_p->setting_y;
                break;
            case FMRDO_PEN_MAIN_VOLUME_INC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
                point.x = pos.x - skin_p->volume_inc_x;
                point.y = pos.y - skin_p->volume_inc_y;
                break;
            case FMRDO_PEN_MAIN_VOLUME_DEC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
                point.x = pos.x - skin_p->volume_dec_x;
                point.y = pos.y - skin_p->volume_dec_y;
                break;
            case FMRDO_PEN_MAIN_FREQ:
                area = (mmi_pen_polygon_area_struct*) & skin_p->frequency_area;
                point.x = pos.x - skin_p->frequency_x;
                point.y = pos.y - skin_p->frequency_y;
                break;
        }
        if (mmi_pen_check_inside_polygon(area, point))
        {
            fmrdo_pen_event_on_object = i;
            break;
        }
    }

    switch (fmrdo_pen_event_on_object)
    {
        case FMRDO_PEN_LSK:
            mmi_fmrdo_redraw_main_LSK_down();
            ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            break;
        case FMRDO_PEN_RSK:
            mmi_fmrdo_redraw_main_RSK_down();
            ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            break;
        case FMRDO_PEN_MAIN_STEP_UP:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_press_step_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_STEP_DOWN:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_press_step_down_button();
            }
            break;
        case FMRDO_PEN_MAIN_POWER:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_press_power_button();
            }
            break;
        case FMRDO_PEN_MAIN_SEARCH:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_press_search_button();
            }
            break;
        case FMRDO_PEN_MAIN_SETTING:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_redraw_main_push_down_button(2, TRUE);
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_INC:
            mmi_fmrdo_redraw_main_push_down_button(1, TRUE);
            break;
        case FMRDO_PEN_MAIN_VOLUME_DEC:
            mmi_fmrdo_redraw_main_push_down_button(0, TRUE);
            break;
        case FMRDO_PEN_MAIN_FREQ:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_entry_channel_list();
            }
            break;
    }
#if defined(__MMI_FM_RADIO_RECORD__)
    if(fmrdo_pen_event_on_object == FMRDO_PEN_NONE) //sc.wu fm record
        {
            mmi_fmrdo_pen_down_hdlr_custom_ele(pos);
        }
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmrdo_pen_event_on_object)
    {
        case FMRDO_PEN_MAIN_STEP_UP:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_release_step_up_button();
            }
            break;
        case FMRDO_PEN_MAIN_STEP_DOWN:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_release_step_down_button();
            }
            break;
        case FMRDO_PEN_MAIN_SEARCH:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_release_search_button();
            }
            break;
        case FMRDO_PEN_MAIN_POWER:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_release_power_button();
            }
            break;
        case FMRDO_PEN_MAIN_SETTING:
            if (g_fmrdo.state != FMRDO_STATE_RECORD && g_fmrdo.state != FMRDO_STATE_RECORD_PAUSE)
            {
                mmi_fmrdo_redraw_main_push_down_button(2, FALSE);
                mmi_fmrdo_entry_settings();
            }
            break;
        case FMRDO_PEN_MAIN_VOLUME_DEC:
            mmi_fmrdo_redraw_main_push_down_button(0, FALSE);
            mmi_fmrdo_dec_volume();
            break;
        case FMRDO_PEN_MAIN_VOLUME_INC:
            mmi_fmrdo_redraw_main_push_down_button(1, FALSE);
            mmi_fmrdo_inc_volume();
            break;
        case FMRDO_PEN_LSK:
            mmi_fmrdo_redraw_main_LSK_up();
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
            }
            break;
        case FMRDO_PEN_RSK:
            mmi_fmrdo_redraw_main_RSK_up();
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fmrdo_pen_event_on_object)
    {
    #if (0) /* Not handle these four buttons */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (0) */ 
        case FMRDO_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                mmi_fmrdo_redraw_main_LSK_down();
            }
            else
            {
                mmi_fmrdo_redraw_main_LSK_up();
            }
            break;
        case FMRDO_PEN_RSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                mmi_fmrdo_redraw_main_RSK_down();
            }
            else
            {
                mmi_fmrdo_redraw_main_RSK_up();
            }
            break;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* MTK Leo end */

#ifdef __MMI_FM_RADIO_ANIMATION__


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_animation_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_animation_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_push_and_set_active(fmrdo_skin_layer);
#endif 

    /* animation */
#ifdef __MMI_FM_RADIO_ANIMATION__
    fmrdo_main_draw.animation.img_handle = GDI_ERROR_HANDLE;
    gdi_image_draw_animation(
        fmrdo_main_draw.animation.x,
        fmrdo_main_draw.animation.y,
        fmrdo_main_draw.animation.animation_img,
        &fmrdo_main_draw.animation.img_handle);
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_pop_and_restore_active();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_animation_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_animation_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop animation */
    if (fmrdo_main_draw.animation.img_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(fmrdo_main_draw.animation.img_handle);
    }
}
#endif /* __MMI_FM_RADIO_ANIMATION__ */ 

#if defined(__MMI_FM_RADIO_RECORD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_change_main_SK_record
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_change_main_SK_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(STR_ID_FMRDO_PAUSE);
    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(STR_ID_FMRDO_STOP);

    mmi_fmrdo_redraw_main_LSK_up();
    mmi_fmrdo_redraw_main_RSK_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_change_main_SK_pause
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for pause
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_change_main_SK_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(STR_ID_FMRDO_RESUME);
    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(STR_ID_FMRDO_STOP);

    mmi_fmrdo_redraw_main_LSK_up();
    mmi_fmrdo_redraw_main_RSK_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_restore_main_SK
 * DESCRIPTION
 *  Redraw main screen LSK and RSK for restore back to play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_restore_main_SK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmrdo_main_draw.LSK_text = (UI_string_type) GetString(STR_GLOBAL_OPTIONS);
    fmrdo_main_draw.RSK_text = (UI_string_type) GetString(STR_GLOBAL_BACK);

    mmi_fmrdo_redraw_main_LSK_up();
    mmi_fmrdo_redraw_main_RSK_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_redraw_main_time_duration
 * DESCRIPTION
 *  Draw time duration for FM radio record
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_redraw_main_time_duration(BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    U32 rec_time = 4232;
    U16 hour, min, sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rec_time = (U32) (g_fmrdo.rec.duration * 0.004615 + 0.5);

    hour = rec_time / 3600;
    min = (rec_time - hour * 3600) / 60;
    sec = (rec_time - hour * 3600 - min * 60);

    x1 = fmrdo_main_draw.timer_hr_0_offset_x;
    y1 = fmrdo_main_draw.timer_offset_y;
    x2 = fmrdo_main_draw.timer_offset_x2;
    y2 = fmrdo_main_draw.timer_offset_y2;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    if (is_shown)
    {
        /* hh:mm:ss */
        gui_show_image(
            fmrdo_main_draw.timer_hr_0_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (hour / 10))));
        gui_show_image(
            fmrdo_main_draw.timer_hr_1_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (hour % 10))));
        gui_show_image(fmrdo_main_draw.timer_col_0_offset_x, y1, (PU8) GetImage(fmrdo_main_draw.rec_num_col_id));
        gui_show_image(
            fmrdo_main_draw.timer_min_0_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (min / 10))));
        gui_show_image(
            fmrdo_main_draw.timer_min_1_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (min % 10))));
        gui_show_image(fmrdo_main_draw.timer_col_1_offset_x, y1, (PU8) GetImage(fmrdo_main_draw.rec_num_col_id));
        gui_show_image(
            fmrdo_main_draw.timer_sec_0_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (sec / 10))));
        gui_show_image(
            fmrdo_main_draw.timer_sec_1_offset_x,
            y1,
            (PU8) GetImage((U16) (fmrdo_main_draw.rec_base_num_id + (sec % 10))));
    }
    else    /* Clear to background */
    {
    #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    #else 
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);
    #endif 
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#ifdef __MMI_FM_RADIO_ON_SUBLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_show_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left_softkey        [IN]        
 *  right_softkey       [IN]        
 *  skin_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_show_main(U16 left_softkey, U16 right_softkey, U8 skin_index)
{
  #ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction();
    UI_set_sub_LCD_graphics_context();
    gdi_layer_multi_layer_enable();

    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&fmrdo_osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_create_using_outside_memory(0,0,UI_device_width,UI_device_height,&fmrdo_skin_layer,(U8*)new_gdi_buffer,EXTRA_GDI_BUFFER_SIZE);
    //gdi_layer_create(0, 0, UI_device_width, UI_device_height, &fmrdo_skin_layer);
    gdi_layer_set_blt_layer(fmrdo_skin_layer, fmrdo_osd_layer, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
  /* init images */
     if (!fmrdo_main_draw.is_ready || fmrdo_main_draw.skin_index != skin_index)
     {
         mmi_fmrdo_sub_init_main_images(skin_index);
         fmrdo_main_draw.skin_index = skin_index;
         fmrdo_main_draw.is_ready = TRUE;
         fmrdo_main_draw.is_channel_name_scroll_ready = FALSE;
     }
    /*if the skin_index in main lcd is 0 and so it's in sub lcd,need initing images.*/
     if((fmrdo_main_draw.skin_index == 0) && (skin_index == 0))
         {
             mmi_fmrdo_sub_init_main_images(skin_index);
         }

   #ifdef __GDI_MEMORY_PROFILE_2__
    is_fmrdo_skin_layer_drawn = FALSE;
  #endif 
       SUBLCD_ExitCategoryFunction = MMI_dummy_function;
       SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
       SUBLCD_GetCategoryHistory = dummy_get_history;
       SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
       mmi_fmrdo_sub_redraw_main_all();       
       UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_hide_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_hide_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&fmrdo_main_draw.channel_name_scroll);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_flatten_to_base(fmrdo_skin_layer, fmrdo_osd_layer, 0, 0);
    gdi_layer_free(fmrdo_skin_layer);
    gdi_layer_multi_layer_disable();

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(fmrdo_osd_layer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    /* associate functions */
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_redraw_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  freq            [IN]        
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_redraw_frequency(U16 freq, BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 x1 = fmrdo_main_draw.frequency.x;
    S32 y1 = fmrdo_main_draw.frequency.y;
    S32 x2 = fmrdo_main_draw.frequency.x + fmrdo_main_draw.frequency.w - 1;
    S32 y2 = fmrdo_main_draw.frequency.y + fmrdo_main_draw.frequency.h - 1;
    S32 str_w, str_h;
    UI_character_type str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(str, "[%d.%d]", freq / 10, freq % 10);
        
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    /* background & text */
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gui_show_image(0, 0, fmrdo_main_draw.bg_img);
#endif 

    if (is_shown)
    {
        gui_push_text_clip();
        gui_set_text_clip(x1, y1, x2, y2);

        if (g_fmrdo.is_power_on)
        {
            gui_set_text_color(fmrdo_main_draw.frequency_text_on_color);
        }
        else
        {
            gui_set_text_color(fmrdo_main_draw.frequency_text_off_color);
        }

        gui_set_font(&MMI_small_font);

        gui_measure_string(str, &str_w, &str_h);

        x = x1 + (fmrdo_main_draw.frequency.w - str_w ) / 2;
        y = y1 + (fmrdo_main_draw.frequency.h - str_h) / 2;

        /* frequency number */
        
        if (r2lMMIFlag)
        {
         
            gui_move_text_cursor(x + str_w - 1, y);
        }
        else
        {
     
            gui_move_text_cursor(x - 1, y - 1);
            
        }
        gui_print_text(str);

        gui_pop_text_clip();
    }
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_init_main_images
 * DESCRIPTION
 *  
 * PARAMETERS
 *  skin_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_init_main_images(S32 skin_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmrdo_sub_skin_struct *skin_p = &g_fmrdo_subLCD_skins[skin_index];
    S32 w, h; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* background */
    fmrdo_main_draw.bg_img = (PU8) GetImage(skin_p->bg_image_id);

    /* channel name */
    fmrdo_main_draw.channel_name_text_border_color = gui_color(
                                                        skin_p->channel_name_text_border_color_r,
                                                        skin_p->channel_name_text_border_color_g,
                                                        skin_p->channel_name_text_border_color_b);
    fmrdo_main_draw.channel_name_text_color = gui_color(
                                                skin_p->channel_name_text_color_r,
                                                skin_p->channel_name_text_color_g,
                                                skin_p->channel_name_text_color_b);
    fmrdo_main_draw.channel_name.x = skin_p->channel_name_x;
    fmrdo_main_draw.channel_name.y = skin_p->channel_name_y;
    fmrdo_main_draw.channel_name.w = skin_p->channel_name_w;
    fmrdo_main_draw.channel_name.h = skin_p->channel_name_h;

    /* frequency */
    fmrdo_main_draw.frequency_text_on_color = gui_color(
                                                skin_p->frequency_text_on_color_r,
                                                skin_p->frequency_text_on_color_g,
                                                skin_p->frequency_text_on_color_b);
    fmrdo_main_draw.frequency_text_off_color = gui_color(
                                                skin_p->frequency_text_off_color_r,
                                                skin_p->frequency_text_off_color_g,
                                                skin_p->frequency_text_off_color_b);
    fmrdo_main_draw.frequency.x = skin_p->frequency_x;
    fmrdo_main_draw.frequency.y = skin_p->frequency_y;
    fmrdo_main_draw.frequency.w = skin_p->frequency_w;
    fmrdo_main_draw.frequency.h = skin_p->frequency_h;

    /* volume */
    fmrdo_main_draw.volume.bg_img = (PU8) GetImage(skin_p->volume_image_id);
    fmrdo_main_draw.volume.type = skin_p->volume_bar_type;  /* 0: horizontal, 1: vertical */
    fmrdo_main_draw.volume.x = skin_p->volume_bar_x;
    fmrdo_main_draw.volume.y = skin_p->volume_bar_y;
    gui_measure_image(fmrdo_main_draw.volume.bg_img, &w, &h);
    fmrdo_main_draw.volume.w = (S16) w;
    fmrdo_main_draw.volume.h = (S16) h;
    fmrdo_main_draw.volume.ind_start_gap = skin_p->volume_ind_start_gap;
    fmrdo_main_draw.volume.ind_end_gap = skin_p->volume_ind_end_gap;



    /* tuner scale */
    fmrdo_main_draw.tuner_scale.bg_img = (PU8) GetImage(skin_p->tuner_scale_bg_image_id);
    fmrdo_main_draw.tuner_scale.ind_img = (PU8) GetImage(skin_p->tuner_scale_ind_image_id);
    fmrdo_main_draw.tuner_scale.type = skin_p->tuner_scale_type;        /* 0: horizontal, 1: vertical */
    fmrdo_main_draw.tuner_scale.x = skin_p->tuner_scale_x;
    fmrdo_main_draw.tuner_scale.y = skin_p->tuner_scale_y;
    gui_measure_image(fmrdo_main_draw.tuner_scale.bg_img, &w, &h);
    fmrdo_main_draw.tuner_scale.w = (S16) w;
    fmrdo_main_draw.tuner_scale.h = (S16) h;
    gui_measure_image(fmrdo_main_draw.tuner_scale.ind_img, &w, &h);
    fmrdo_main_draw.tuner_scale.ind_w = (S16) w;
    fmrdo_main_draw.tuner_scale.ind_h = (S16) h;
    fmrdo_main_draw.tuner_scale.ind_offset = skin_p->tunner_scale_ind_offset;
    fmrdo_main_draw.tuner_scale.ind_start_gap = skin_p->tuner_scale_start_gap;
    fmrdo_main_draw.tuner_scale.ind_end_gap = skin_p->tuner_scale_end_gap;

    /* step down button */
    fmrdo_main_draw.step_down_button.up_img = (PU8) GetImage(skin_p->step_down_button_up_image_id);
    fmrdo_main_draw.step_down_button.down_img = (PU8) GetImage(skin_p->step_down_button_down_image_id);
    fmrdo_main_draw.step_down_button.x = skin_p->step_down_button_x;
    fmrdo_main_draw.step_down_button.y = skin_p->step_down_button_y;
    gui_measure_image(fmrdo_main_draw.step_down_button.up_img, &w, &h);
    fmrdo_main_draw.step_down_button.w = (S16) w;
    fmrdo_main_draw.step_down_button.h = (S16) h;

    /* step up button */
    fmrdo_main_draw.step_up_button.up_img = (PU8) GetImage(skin_p->step_up_button_up_image_id);
    fmrdo_main_draw.step_up_button.down_img = (PU8) GetImage(skin_p->step_up_button_down_image_id);
    fmrdo_main_draw.step_up_button.x = skin_p->step_up_button_x;
    fmrdo_main_draw.step_up_button.y = skin_p->step_up_button_y;
    gui_measure_image(fmrdo_main_draw.step_up_button.up_img, &w, &h);
    fmrdo_main_draw.step_up_button.w = (S16) w;
    fmrdo_main_draw.step_up_button.h = (S16) h;

    /* search button */
    fmrdo_main_draw.search_button.on_up_img = (PU8) GetImage(skin_p->search_button_on_up_image_id);
    fmrdo_main_draw.search_button.on_down_img = (PU8) GetImage(skin_p->search_button_on_down_image_id);
    fmrdo_main_draw.search_button.off_up_img = (PU8) GetImage(skin_p->search_button_off_up_image_id);
    fmrdo_main_draw.search_button.off_down_img = (PU8) GetImage(skin_p->search_button_off_down_image_id);
    fmrdo_main_draw.search_button.x = skin_p->search_button_x;
    fmrdo_main_draw.search_button.y = skin_p->search_button_y;
    gui_measure_image(fmrdo_main_draw.search_button.on_up_img, &w, &h);
    fmrdo_main_draw.search_button.w = (S16) w;
    fmrdo_main_draw.search_button.h = (S16) h;

    /* power button */
    fmrdo_main_draw.power_button.on_up_img = (PU8) GetImage(skin_p->power_button_on_up_image_id);
    fmrdo_main_draw.power_button.on_down_img = (PU8) GetImage(skin_p->power_button_on_down_image_id);
    fmrdo_main_draw.power_button.off_up_img = (PU8) GetImage(skin_p->power_button_off_up_image_id);
    fmrdo_main_draw.power_button.off_down_img = (PU8) GetImage(skin_p->power_button_off_down_image_id);
    fmrdo_main_draw.power_button.x = skin_p->power_button_x;
    fmrdo_main_draw.power_button.y = skin_p->power_button_y;
    gui_measure_image(fmrdo_main_draw.power_button.on_up_img, &w, &h);
    fmrdo_main_draw.power_button.w = (S16) w;
    fmrdo_main_draw.power_button.h = (S16) h;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_sub_redraw_main_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_sub_redraw_main_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_push_text_clip();

    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

#ifdef __GDI_MEMORY_PROFILE_2__
    if (!is_fmrdo_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(fmrdo_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
        /* main background */
        gui_show_image(0, 0, fmrdo_main_draw.bg_img);

        /* animation */

    #ifdef __GDI_MEMORY_PROFILE_2__
        /* tuner scale background */
        gui_show_image(
            fmrdo_main_draw.tuner_scale.x,
            fmrdo_main_draw.tuner_scale.y,
            fmrdo_main_draw.tuner_scale.bg_img);
        is_fmrdo_skin_layer_drawn = TRUE;
        gdi_layer_pop_and_restore_active();
    }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gui_pop_text_clip();
    gui_pop_clip();
    /* draw components */

    mmi_fmrdo_sub_redraw_frequency(g_fmrdo.frequency, TRUE);
 
    mmi_fmrdo_redraw_main_channel_name(0);
    mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.frequency);
    mmi_fmrdo_redraw_main_volume();
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_DOWN,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)));
    mmi_fmrdo_redraw_main_push_button(
        FMRDO_BUTTON_STEP_UP,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)));
    mmi_fmrdo_redraw_main_toggle_button(
        FMRDO_BUTTON_SEARCH,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH)),
        g_fmrdo.is_search_on,
        TRUE);
    mmi_fmrdo_redraw_main_toggle_button(
        FMRDO_BUTTON_POWER,
        (BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_POWER)),
        g_fmrdo.is_power_on,
        TRUE);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


#endif /* __MMI_FM_RADIO_ON_SUBLCD__ */

#endif /* __MMI_FM_RADIO__ */ 


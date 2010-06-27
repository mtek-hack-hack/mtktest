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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   wgui_categories_PE.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Picture Editor related categoreis.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Include MMI header file */
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"
#include "GlobalDefs.h"
#include "gui_data_types.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "EventsDef.h"
#include "gui_themes.h"
#include "gui.h"
#include "wgui.h"
#include "CustThemesRes.h"
#include "wgui_inputs.h"
#include "wgui_categories.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_defs.h"
#include "wgui_softkeys.h"
#include "wgui_categories_PE.h"
#include "DebugInitDef.h"
#include "gui_color_slider.h"
#include "gdi_include.h"
#include "wgui_draw_manager.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

/*
 * type definition
 */
#define RED_COLOR   MMI_CAT91_COLOR_SLIDER_RED_COLOR 
#define GREEN_COLOR MMI_CAT91_COLOR_SLIDER_GREEN_COLOR 
#define BLUE_COLOR  MMI_CAT91_COLOR_SLIDER_BLUE_COLOR 
#define TOTAL_COLOR MMI_CAT91_COLOR_SLIDER_TOTAL_COLOR 

typedef struct
{
    color cColor;
    mmi_cat91_color_slider_enum highlighted_slider;
} mmi_cat91_history_struct;

/*
 * Define
 */
#define SLIDER_BAR_WIDTH                  (UI_device_width-10)
#define SLIDER_BAR_HEIGHT                 (10)
#define SLIDER_BAR_GAP                    (14)
#define SELECTED_COLOR_AREA_WIDTH         (40)
#define SELECTED_COLOR_AREA_HEIGHT        (14)

/* 
 * Local Variable
 */
static color_slider cat91_color_slider[TOTAL_COLOR];
static U8 *cat91_color_value[TOTAL_COLOR];
static S32 cat91_selected_color_x;
static S32 cat91_selected_color_y;

#ifdef __MMI_TOUCH_SCREEN__
static S32 cat91_color_slider_bar_y1;
static S32 cat91_color_slider_bar_y2;
static S32 cat91_color_slider_bar_y3;
static S32 cat91_color_slider_bar_y3_bottom;
#endif /* __MMI_TOUCH_SCREEN__ */ 
static color cat91_highlight_color = {122, 211, 255, 100};
static mmi_cat91_color_slider_enum *cat91_highlighted_slider;

static U8 color_slider_gc_percentages[] = 
{
    100
};

static color red_color_slider_gc_colors[] = 
{
    {0, 0, 0, 100},
    {255, 0, 0, 100},
};

static gradient_color red_color_slider_gc = 
{
    red_color_slider_gc_colors,
    color_slider_gc_percentages,
    2
};

static color green_color_slider_gc_colors[] = 
{
    {0, 0, 0, 100},
    {0, 255, 0, 100},
};

static gradient_color green_color_slider_gc = 
{
    green_color_slider_gc_colors,
    color_slider_gc_percentages,
    2
};

static color blue_color_slider_gc_colors[] = 
{
    {0, 0, 0, 100},
    {0, 0, 245, 100},   /* FIXME. avoid transparent color */
};

static gradient_color blue_color_slider_gc = 
{
    blue_color_slider_gc_colors,
    color_slider_gc_percentages,
    2
};

static UI_filled_area red_color_slider_filler = 
{
    UI_FILLED_AREA_TYPE_GRADIENT_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    NULL,
    &red_color_slider_gc,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0,
};

static UI_filled_area green_color_slider_filler = 
{
    UI_FILLED_AREA_TYPE_GRADIENT_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    NULL,
    &green_color_slider_gc,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0,
};

static UI_filled_area blue_color_slider_filler = 
{
    UI_FILLED_AREA_TYPE_GRADIENT_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    NULL,
    &blue_color_slider_gc,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0,
};

/*
 * Global Variable
 */

/*
 * Global Function
 */
extern BOOL r2lMMIFlag;
extern horizontal_select MMI_inline_select_menu;
extern void UI_dummy_menuitem_displayed_function(S32 index, S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * FUNCTION
 *  cat91_draw_highlight
 * DESCRIPTION
 *  Draw Highlight color slider area of category91
 * PARAMETERS
 *  x1      [IN]        Start-point of x-coordinate
 *  y1      [IN]        Start-point of y-coordinate
 *  x2      [IN]        End-point of x-coordinate
 *  y2      [IN]        End-point of y-coordinate
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_draw_highlight(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(
        x1,
        y1,
        x2,
        y2,
        gdi_act_color_from_rgb(255, cat91_highlight_color.r, cat91_highlight_color.g, cat91_highlight_color.b));
}


/*****************************************************************************
 * FUNCTION
 *  cat91_redraw_selected_color
 * DESCRIPTION
 *  Draw selected color preview area of category91
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_redraw_selected_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 area_width = SELECTED_COLOR_AREA_WIDTH, area_height = SELECTED_COLOR_AREA_HEIGHT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*cat91_color_value[RED_COLOR] == 0 && *cat91_color_value[GREEN_COLOR] == 0 &&
        *cat91_color_value[BLUE_COLOR] >= 248)
    {
        *cat91_color_value[BLUE_COLOR] = 247;
    }

    gdi_draw_solid_rect(
        cat91_selected_color_x,
        cat91_selected_color_y,
        cat91_selected_color_x + area_width - 1,
        cat91_selected_color_y + area_height - 1,
        gdi_act_color_from_rgb(255, *cat91_color_value[RED_COLOR], *cat91_color_value [GREEN_COLOR], *cat91_color_value [BLUE_COLOR]));
}


/*****************************************************************************
 * FUNCTION
 *  cat91_show_color_sliders
 * DESCRIPTION
 *  Draw color sliders of category91
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cat91_show_color_sliders(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color_slider *cs = &cat91_color_slider[*cat91_highlighted_slider];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    cat91_draw_highlight(0, cs->y - 4, UI_device_width - 1, cs->y + cs->height + cs->sheight + 2);

#ifdef __MMI_TOUCH_SCREEN__
    cat91_color_slider_bar_y1 = cat91_color_slider[RED_COLOR].y - 4;
    cat91_color_slider_bar_y2 = cat91_color_slider[GREEN_COLOR].y - 4;
    cat91_color_slider_bar_y3 = cat91_color_slider[BLUE_COLOR].y - 4;
    cat91_color_slider_bar_y3_bottom =
        cat91_color_slider[BLUE_COLOR].y + cat91_color_slider[BLUE_COLOR].height +
        cat91_color_slider[BLUE_COLOR].sheight + 2;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    gui_color_slider_show(&cat91_color_slider[RED_COLOR]);
    gui_color_slider_show(&cat91_color_slider[GREEN_COLOR]);
    gui_color_slider_show(&cat91_color_slider[BLUE_COLOR]);

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  cat91_setup_color_sliders
 * DESCRIPTION
 *  Setup color sliders for category91
 * PARAMETERS
 *  R       [IN/OUT]        Value of color Red
 *  G       [IN/OUT]        Value of color Green
 *  B       [IN/OUT]        Value of color Blue
 * RETURNS
 *  void
 *****************************************************************************/
static void cat91_setup_color_sliders(U8 *R, U8 *G, U8 *B)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y1, y2, y3;
    S32 width = SLIDER_BAR_WIDTH, height = SLIDER_BAR_HEIGHT, gap = SLIDER_BAR_GAP;
    S32 area_height = SELECTED_COLOR_AREA_HEIGHT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat91_color_value[RED_COLOR] = R;
    cat91_color_value[GREEN_COLOR] = G;
    cat91_color_value[BLUE_COLOR] = B;

    cat91_selected_color_x = (UI_device_width >> 1) - 20;
    cat91_selected_color_y = (MMI_title_y + MMI_title_height) + 2;

    x = UI_device_width - width - 2;
    y1 = cat91_selected_color_y + area_height + 10;
    y2 = y1 + height + gap - 1;
    y3 = y2 + height + gap - 1;

    gui_color_slider_create(&cat91_color_slider[RED_COLOR], x, y1, width, height);
    gui_color_slider_set_filler(&cat91_color_slider[RED_COLOR], &red_color_slider_filler);
    gui_color_slider_set_range(&cat91_color_slider[RED_COLOR], 32);
    gui_color_slider_set_value(&cat91_color_slider[RED_COLOR], (*R) >> 3);
    gui_color_slider_set_hide_function(&cat91_color_slider[RED_COLOR], cat91_draw_highlight);

    gui_color_slider_create(&cat91_color_slider[GREEN_COLOR], x, y2, width, height);
    gui_color_slider_set_filler(&cat91_color_slider[GREEN_COLOR], &green_color_slider_filler);
    gui_color_slider_set_range(&cat91_color_slider[GREEN_COLOR], 32);
    gui_color_slider_set_value(&cat91_color_slider[GREEN_COLOR], (*G) >> 3);
    gui_color_slider_set_hide_function(&cat91_color_slider[GREEN_COLOR], cat91_draw_highlight);

    gui_color_slider_create(&cat91_color_slider[BLUE_COLOR], x, y3, width, height);
    gui_color_slider_set_filler(&cat91_color_slider[BLUE_COLOR], &blue_color_slider_filler);
    gui_color_slider_set_range(&cat91_color_slider[BLUE_COLOR], 31);
    gui_color_slider_set_value(&cat91_color_slider[BLUE_COLOR], (*B) >> 3);
    gui_color_slider_set_hide_function(&cat91_color_slider[BLUE_COLOR], cat91_draw_highlight);
}


/*****************************************************************************
 * FUNCTION
 *  cat91_redraw_content_area
 * DESCRIPTION
 *  Draw content area of category91
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_redraw_content_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 width = SELECTED_COLOR_AREA_WIDTH, height = SELECTED_COLOR_AREA_HEIGHT;
    color hc = gui_color(196, 196, 196);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* Decide the region */
    x1 = 0;
    y1 = (MMI_title_y + MMI_title_height);
    x2 = UI_device_width - 1;
    y2 = (MMI_title_y + MMI_title_height) + MMI_content_height - 1;

    gdi_layer_reset_clip();

    /* clear background */
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);

    /* draw the preview area for selected color */
    gdi_draw_rect(
        cat91_selected_color_x - 1,
        cat91_selected_color_y - 1,
        cat91_selected_color_x + width,
        cat91_selected_color_y + height,
        GDI_COLOR_BLACK);
    cat91_redraw_selected_color();
    gdi_draw_line(
        0,
        cat91_selected_color_y + height + 2,
        UI_device_width - 1,
        cat91_selected_color_y + height + 2,
        gdi_act_color_from_rgb(255, hc.r, hc.g, hc.b));

    /* show all color sliders */
    cat91_show_color_sliders();

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  cat91_increase_current_value
 * DESCRIPTION
 *  Increate the value of active color slider
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_increase_current_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color_slider *cs;
    S32 x1, y1, x2, y2;
    U8 *cp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Decide the region */
    x1 = MMI_content_x;
    y1 = MMI_content_y;
    x2 = MMI_content_x + MMI_content_width - 1;
    y2 = MMI_content_y + MMI_content_height - 1;

    /* Decide the active color slider */
    cs = &cat91_color_slider[*cat91_highlighted_slider];
    cp = cat91_color_value[*cat91_highlighted_slider];

    /* Hide active color slider */
    gui_color_slider_hide(cs);

    /* Calculate new value */
    cs->value++;
    if (cs->value >= cs->range)
    {
        cs->value = cs->range - 1;
    }
    *cp = (U8) (cs->value << 3);

    /* Show active color slider */
    gui_color_slider_show(cs);

    /* Update selected color preview area */
    cat91_redraw_selected_color();

    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  cat91_decrease_current_value
 * DESCRIPTION
 *  Decreate the value of active color slider
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_decrease_current_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color_slider *cs;
    S32 x1, y1, x2, y2;
    U8 *cp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Decide the region */
    x1 = MMI_content_x;
    y1 = MMI_content_y;
    x2 = MMI_content_x + MMI_content_width - 1;
    y2 = MMI_content_y + MMI_content_height - 1;

    /* Decide the active color slider */
    cs = &cat91_color_slider[*cat91_highlighted_slider];
    cp = cat91_color_value[*cat91_highlighted_slider];    

    /* Hide active color slider */
    gui_color_slider_hide(cs);

    cs->value--;
    if (cs->value < 0)
    {
        cs->value = 0;
    }
    *cp = (U8) (cs->value << 3);

    /* Show active color slider */
    gui_color_slider_show(cs);

    /* Update selected color preview area */
    cat91_redraw_selected_color();

    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  cat91_goto_previous_slider
 * DESCRIPTION
 *  Change to previous color slider
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_goto_previous_slider(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*cat91_highlighted_slider > RED_COLOR)
    {
        (*cat91_highlighted_slider)--;
    }

    cat91_redraw_content_area();
}


/*****************************************************************************
 * FUNCTION
 *  cat91_goto_next_slider
 * DESCRIPTION
 *  Change to next color slider
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_goto_next_slider(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*cat91_highlighted_slider < TOTAL_COLOR - 1)
    {
        (*cat91_highlighted_slider)++;
    }

    cat91_redraw_content_area();
}


/*****************************************************************************
 * FUNCTION
 *  cat91_keyboard_key_handler
 * DESCRIPTION
 *  Function to handle keyboard key events.
 * PARAMETERS
 *  vkey_code       [IN]        Key code
 *  key_state       [IN]        Key_state
 * RETURNS
 *  void
 *****************************************************************************/
void cat91_keyboard_key_handler(S32 vkey_code, S32 key_state)
{
#if 0 /*(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)*/
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
/* under construction !*/
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}

#if defined(__MMI_TOUCH_SCREEN__)


/*****************************************************************************
 * FUNCTION
 *  category91_control_area_pen_handler
 * DESCRIPTION
 *  Function to handle pen events.
 * PARAMETERS
 *  point           [IN]        Coordinate of pen position
 *  pen_event       [IN]        Type of pen event
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL category91_control_area_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    gui_slide_control_pen_event_enum slide_event;
    gui_pen_event_param_struct slide_param;
    static color_slider *current_color_slider;
    static U8 *current_color_pointer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
        {
            S32 pen_down_slider = -1;
            color_slider *cs = NULL;
            U8 *cp = NULL;

            current_color_slider = NULL;
            current_color_pointer = NULL;

            if (wgui_color_slider_translate_pen_event
                (&cat91_color_slider[RED_COLOR], pen_event, point.x, point.y, &slide_event, &slide_param))
            {
                pen_down_slider = 0;
                cs = &cat91_color_slider[RED_COLOR];
                cp = cat91_color_value[RED_COLOR];
            }
            else if (wgui_color_slider_translate_pen_event
                     (&cat91_color_slider[GREEN_COLOR], pen_event, point.x, point.y, &slide_event, &slide_param))
            {
                pen_down_slider = 1;
                cs = &cat91_color_slider[GREEN_COLOR];
                cp = cat91_color_value[GREEN_COLOR];
            }
            else if (wgui_color_slider_translate_pen_event
                     (&cat91_color_slider[BLUE_COLOR], pen_event, point.x, point.y, &slide_event, &slide_param))
            {
                pen_down_slider = 2;
                cs = &cat91_color_slider[BLUE_COLOR];
                cp = cat91_color_value[BLUE_COLOR];
            }

            if (pen_down_slider >= 0)
            {
                current_color_slider = cs;
                current_color_pointer = cp;

                if (pen_down_slider != *cat91_highlighted_slider)
                {
                    *cat91_highlighted_slider = pen_down_slider;
                    cat91_redraw_content_area();
                }

                if (GUI_SLIDE_CONTROL_PEN_JUMP_TO_I == slide_event)
                {
                    gui_lock_double_buffer();
                    gui_color_slider_hide(cs);
                    cs->value = (S32) slide_param._u.i;
                    gui_color_slider_show(cs);
                    *cp = (U8) (cs->value << 3);
                    cat91_redraw_selected_color();
                    gui_unlock_double_buffer();
                    gui_BLT_double_buffer(
                        MMI_content_x,
                        MMI_content_y,
                        MMI_content_x + MMI_content_width - 1,
                        MMI_content_y + MMI_content_height - 1);
                }
            }
            else
            {
                /* Change highlight if needed */
                if (point.y > cat91_color_slider_bar_y3_bottom)
                {
                    pen_down_slider = -1;
                }
                else if (point.y >= cat91_color_slider_bar_y3)
                {
                    pen_down_slider = 2;
                }
                else if (point.y >= cat91_color_slider_bar_y2)
                {
                    pen_down_slider = 1;
                }
                else if (point.y >= cat91_color_slider_bar_y1)
                {
                    pen_down_slider = 0;
                }

                if (pen_down_slider >= 0 && pen_down_slider != *cat91_highlighted_slider)
                {
                    *cat91_highlighted_slider = pen_down_slider;
                    cat91_redraw_content_area();
                }
                else
                {
                    ret = MMI_FALSE;
                }
            }
            break;
        }

        default:

            if (current_color_slider)
            {
                wgui_color_slider_translate_pen_event(
                    current_color_slider,
                    pen_event,
                    point.x,
                    point.y,
                    &slide_event,
                    &slide_param);
                if (GUI_SLIDE_CONTROL_PEN_JUMP_TO_I == slide_event)
                {
                    gui_lock_double_buffer();
                    gui_color_slider_hide(current_color_slider);
                    current_color_slider->value = (S32) slide_param._u.i;
                    gui_color_slider_show(current_color_slider);
                    *current_color_pointer = (U8) (current_color_slider->value << 3);
                    cat91_redraw_selected_color();
                    gui_unlock_double_buffer();
                    gui_BLT_double_buffer(
                        MMI_content_x,
                        MMI_content_y,
                        MMI_content_x + MMI_content_width - 1,
                        MMI_content_y + MMI_content_height - 1);
                }

                if (pen_event == MMI_PEN_EVENT_UP || pen_event == MMI_PEN_EVENT_ABORT)
                {
                    current_color_slider = NULL;
                    current_color_pointer = NULL;
                }
            }
            break;

    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  category91_control_area_pen_down_handler
 * DESCRIPTION
 *  Function to handle pen down event
 * PARAMETERS
 *  point       [IN]        Coordinate of pen position
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL category91_control_area_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category91_control_area_pen_handler(point, MMI_PEN_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  category91_control_area_pen_move_handler
 * DESCRIPTION
 *  Function to handle pen move event
 * PARAMETERS
 *  point       [IN]        Coordinate of pen position
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL category91_control_area_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category91_control_area_pen_handler(point, MMI_PEN_EVENT_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  category91_control_area_pen_longtap_handler
 * DESCRIPTION
 *  Function to handle pen longtap event
 * PARAMETERS
 *  point       [IN]        Coordinate of pen position
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL category91_control_area_pen_longtap_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category91_control_area_pen_handler(point, MMI_PEN_EVENT_LONG_TAP);
}


/*****************************************************************************
 * FUNCTION
 *  category91_control_area_pen_repeat_handler
 * DESCRIPTION
 *  Function to handle pen repeat event
 * PARAMETERS
 *  point       [IN]        Coordinate of pen position
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL category91_control_area_pen_repeat_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category91_control_area_pen_handler(point, MMI_PEN_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  category91_control_area_pen_up_handler
 * DESCRIPTION
 *  Function to handle pen up event
 * PARAMETERS
 *  point       [IN]        Coordinate of pen position
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL category91_control_area_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category91_control_area_pen_handler(point, MMI_PEN_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  category91_control_area_pen_abort_handler
 * DESCRIPTION
 *  Function to handle pen abort event
 * PARAMETERS
 *  point       [IN]        Coordinate of pen position
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL category91_control_area_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category91_control_area_pen_handler(point, MMI_PEN_EVENT_ABORT);
}

#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  DrawCate91CategoryControlArea
 * DESCRIPTION
 *  Function to draw category controll area of category91
 * PARAMETERS
 *  coordinate      [IN]        Coordinate of pen position
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate91CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat91_redraw_content_area();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory91Screen
 * DESCRIPTION
 *  Displays the color picker screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the Right softkey
 *  R                       [IN]        Pointer to value of color red
 *  G                       [IN]        Pointer to value of color green
 *  B                       [IN]        Pointer to value of color blue
 *  highlighted_slider      [IN]        highlighted zlider
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory91Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *R,
        U8 *G,
        U8 *B,
        mmi_cat91_color_slider_enum *highlighted_slider,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    MMI_menu_shortcut_number = -1;

    /* Setup softkeys */
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    /* Setup title */
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    /* Get color information from history buffer */
    if (history_buffer != NULL)
    {
        mmi_cat91_history_struct *hist = (mmi_cat91_history_struct *)history_buffer;
        
        *R = hist->cColor.r;
        *G = hist->cColor.g;
        *B = hist->cColor.b;
        *highlighted_slider = hist->highlighted_slider;
    }

    /* Setup color sliders */
    cat91_setup_color_sliders(R, G, B);
    cat91_highlighted_slider = highlighted_slider;

    register_keyboard_key_handler(cat91_keyboard_key_handler);

    /* Setup key handlers */
    SetKeyHandler(cat91_goto_previous_slider, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(cat91_goto_next_slider, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(cat91_decrease_current_value, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(cat91_increase_current_value, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    gdi_layer_unlock_frame_buffer();
    ExitCategoryFunction = UI_dummy_function;

    dm_reset_context();
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory91History, dummy_get_history_size);
    dm_add_rectangle(*current_MMI_theme->UI_white_color, 1);
    dm_register_category_controlled_callback(DrawCate91CategoryControlArea);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY91_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(
        category91_control_area_pen_down_handler,
        MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(category91_control_area_pen_up_handler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
        category91_control_area_pen_move_handler,
        MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
        category91_control_area_pen_repeat_handler,
        MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
        category91_control_area_pen_longtap_handler,
        MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
        category91_control_area_pen_abort_handler,
        MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory91History
 * DESCRIPTION
 *  Gets the history buffer for the color picker screen
 * PARAMETERS
 *  history_buffer      [IN/OUT]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
U8 *GetCategory91History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cat91_history_struct *hist = (mmi_cat91_history_struct *)history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hist->cColor.r = *cat91_color_value[RED_COLOR];
    hist->cColor.g = *cat91_color_value[GREEN_COLOR];
    hist->cColor.b = *cat91_color_value[BLUE_COLOR];
    hist->highlighted_slider = *cat91_highlighted_slider;

    return (history_buffer);
}


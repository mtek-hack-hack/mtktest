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
*  ABRepeaterMainScreen.c
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
*============================================================================
*             HISTORY
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
* 
* 
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


#include "MMI_include.h"

#ifdef __MMI_AB_REPEATER__


#include "gui_data_types.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Conversions.h"
#include "FileMgr.h"
#include "ABRepeaterResDef.h"
#include "ABRepeaterDef.h"
#include "ABRepeaterType.h"
#include "ABRepeaterProt.h"
#include "ABRepeaterMainScreen.h"

extern S32 MMI_title_height;            /* from wgui_categories.c */
extern S32 UI_device_width;             /* from gui_wrapper.c */
extern S32 UI_device_height;            /* from gui_wrapper.c */
extern BOOL r2lMMIFlag; /* defined in gui_inputs.c */

static abrepeat_main_scr_struct g_abr_mainscr;
static scrolling_text abrepeat_main_scrolling_title;
static BOOL ab_init_images_done = FALSE;

#ifdef __GDI_MEMORY_PROFILE_2__
GDI_HANDLE abrepeat_osd_layer;
GDI_HANDLE abrepeat_skin_layer;
BOOL is_abrepeat_skin_layer_drawn = FALSE;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

extern abrepeat_struct g_abrepeat;  /* from ABRepeaterSrc.c */
extern signed char g_mmi_abrepeat_draw_refer_state[MAX_AB_POINT];
extern BOOL g_mmi_abrepeat_start_progress;
extern BOOL g_mmi_abrepeat_end_progress;
extern BOOL g_mmi_abrepeat_section_deleted;
extern ab_data_struct g_mmi_abrepeat_abplay_data[MAX_AB_POINT];
extern const abrepeat_skin_struct g_abrepeat_skins[NO_OF_AB_SKIN];      /* from ABRepeaterSrc.c */

/* manish adding these vars */
extern BOOL g_mmi_abrepeat_record_exist[MAX_AB_POINT];


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_show_mainscreen
* DESCRIPTION
*  show ab  repeater main screen
* PARAMETERS
*  title               [IN]        
*  left_softkey        [IN]        
*  right_softkey       [IN]        
*  skin                [IN]        
*  U8* history_buffer(?)
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_show_mainscreen(U16 title, U16 left_softkey, U16 right_softkey, S8 skin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();
    
    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&abrepeat_osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &abrepeat_skin_layer);
    gdi_layer_set_blt_layer(abrepeat_skin_layer, abrepeat_osd_layer, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
    /* init images */
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    if (!ab_init_images_done || g_abr_mainscr.main_skin_index != skin)
#endif
    {
        mmi_abrepeat_init_main_screen_images(skin);
        g_abr_mainscr.main_skin_index = skin;
        ab_init_images_done = TRUE;
    }
    
#ifdef __GDI_MEMORY_PROFILE_2__
    is_abrepeat_skin_layer_drawn = FALSE;
#endif 
    
    clear_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    /* clear_screen(); */
    g_abr_mainscr.main_LSK_text = (UI_string_type) GetString(left_softkey);
    g_abr_mainscr.main_RSK_text = (UI_string_type) GetString(right_softkey);
    SetKeyHandler(mmi_abrepeat_mainscr_LSK_down_hldr, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_abrepeat_mainscr_RSK_down_hldr, KEY_RSK, KEY_EVENT_DOWN);
    
    SetKeyHandler(mmi_abrepeat_entry_option, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_rsk_action, KEY_RSK, KEY_EVENT_UP);
    
    /* associate functions */
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    
    /* draw screen */
    mmi_abrepeat_redraw_main_screen();
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_main_LSK_down_hldr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_mainscr_LSK_down_hldr(void)
{
    mmi_abrepeat_redraw_LSK(TRUE);
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_main_RSK_down_hldr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_mainscr_RSK_down_hldr(void)
{
    mmi_abrepeat_redraw_RSK(TRUE);
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_RSK
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_RSK(BOOL bPressed)
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
    
    gui_push_text_clip();
    
    gui_set_font(&MMI_medium_font);
    if(bPressed)
    {
        gui_set_text_color(*((current_MMI_theme)->LSK_down_text_color));
    }
    else
    {
        gui_set_text_color(*((current_MMI_theme)->LSK_up_text_color));
    }
    gui_set_text_border_color(*((current_MMI_theme)->softkey_text_border_color));

    wgui_softkey_get_offset(g_abr_mainscr.main_RSK_text, &x1, &y1, MMI_RIGHT_SOFTKEY);
    gui_measure_string(g_abr_mainscr.main_RSK_text, &str_w, &str_h);
    if(r2lMMIFlag)
    {
        x2 = x1 + 1;
        x1 = x1 - str_w;
    }
    else
    {
        x2 = x1 + str_w + 1;
    }
    y2 = y1 + str_h + 1;
    
    if (bPressed)
    {
        x1++;
        y1++;
    }
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1 - 2, y1 - 2, x2 , y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1 - 2, y1 - 2, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_draw(0, 0, g_abr_mainscr.main_bg_img);
#endif
    gdi_layer_pop_clip();
    gui_set_text_clip(x1-1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + str_w, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    gui_print_bordered_text(g_abr_mainscr.main_RSK_text);
    
    gui_pop_text_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1 - 2, y1 - 2, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_LSK
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_LSK(BOOL bPressed)
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
    
    gui_push_text_clip();
    
    gui_set_font(&MMI_medium_font);
    if(bPressed)
    {
        gui_set_text_color(*((current_MMI_theme)->RSK_down_text_color));
    }
    else
    {
        gui_set_text_color(*((current_MMI_theme)->RSK_up_text_color));
    }
    gui_set_text_border_color(*((current_MMI_theme)->softkey_text_border_color));
    
    wgui_softkey_get_offset(g_abr_mainscr.main_LSK_text, &x1, &y1, MMI_LEFT_SOFTKEY);
    gui_measure_string(g_abr_mainscr.main_LSK_text, &str_w, &str_h);
    if (r2lMMIFlag)
    {
        x2 = x1 + 1;
        x1 = x1 - str_w;
    }
    else
    {
        x2 = x1 + str_w + 1;
    }
    y2 = y1 + str_h + 1;

    if (bPressed)
    {
        x1++;
        y1++;
    }
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1 - 2, y1 - 2, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1 - 2, y1 - 2, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_draw(0, 0, g_abr_mainscr.main_bg_img);
#endif 
    gdi_layer_pop_clip();
    gui_set_text_clip(x1-1, y1 - 1, x2, y2);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + str_w, y1);
    }
    else
    {
        gui_move_text_cursor(x1, y1);
    }
    
    gui_print_bordered_text(g_abr_mainscr.main_LSK_text);
    
    gui_pop_text_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1 - 2, y1 - 2, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

#if defined(__MMI_MAINLCD_240X400__)
/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_statusbar_bg_callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_statusbar_bg_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(0, 0, UI_device_width - 1, MMI_status_bar_height - 1);
    gdi_image_draw(0,0,g_abr_mainscr.main_bg_img);
    gdi_layer_pop_clip();

}
#endif /*defined(__MMI_MAINLCD_240X400__)*/

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_main_screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    gui_push_clip();
    gui_push_text_clip();
    
    /* background ,head, LSK, and RSK */
#ifdef __GDI_MEMORY_PROFILE_2__
    if (!is_abrepeat_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(abrepeat_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
        gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
        gui_show_image(0, 0, g_abr_mainscr.main_bg_img);
#ifdef __GDI_MEMORY_PROFILE_2__
        is_abrepeat_skin_layer_drawn = TRUE;
        gdi_layer_pop_and_restore_active();
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(*((current_MMI_theme)->title_text_color)); 
    gui_set_text_border_color(*((current_MMI_theme)->title_text_border_color));

     /*if show title status area*/
#if defined(__MMI_MAINLCD_240X400__)
#ifdef GUI_COMMON_SHOW_STATUS_ICON
    register_hide_status_icon_bar(0, mmi_abrepeat_redraw_statusbar_bg_callback);
    show_status_icon_bar(0);
    show_status_icons();
#endif  /*GUI_COMMON_SHOW_STATUS_ICON*/
    gui_measure_string((UI_string_type)GetString(STR_ID_ABREPEAT_TITLE), &str_w, &str_h);
    x1 = (UI_device_width - str_w)>>1;
    y1 = 20 + ((45 - str_h)>>1);
    if (r2lMMIFlag)
    {
        gui_set_text_clip(x1 - str_w, y1 - 1, x1, y1+ str_h);
    }
    else
    {
        gui_set_text_clip(x1, y1 - 1, x1 + str_w, y1+ str_h);
    }
    
    gui_move_text_cursor(x1, y1);
    gui_print_bordered_text((UI_string_type)GetString(STR_ID_ABREPEAT_TITLE));
#endif

    /* show LSK */
    wgui_softkey_get_offset(g_abr_mainscr.main_LSK_text, &x1, &y1, MMI_LEFT_SOFTKEY);
    gui_measure_string(g_abr_mainscr.main_LSK_text, &str_w, &str_h);
    if (r2lMMIFlag)
    {
        gui_set_text_clip(x1 - str_w, y1 - 1, x1, y1+ str_h);
    }
    else
    {
        gui_set_text_clip(x1, y1 - 1, x1 + str_w, y1+ str_h);
    }

    gui_move_text_cursor(x1, y1);
    gui_print_bordered_text(g_abr_mainscr.main_LSK_text);
    
#ifdef __MMI_TOUCH_SCREEN__
    g_abr_mainscr.area_lsk.pos_x = x1;
    g_abr_mainscr.area_lsk.pos_y = y1;
    g_abr_mainscr.area_lsk.width = str_w;
    g_abr_mainscr.area_lsk.height = str_h;
#endif
    
    /* show RSK */
    gui_measure_string(g_abr_mainscr.main_RSK_text, &str_w, &str_h);
    wgui_softkey_get_offset(g_abr_mainscr.main_RSK_text, &x1, &y1, MMI_RIGHT_SOFTKEY);
    
    if (r2lMMIFlag)
    {
        gui_set_text_clip(x1 - str_w, y1 - 1, x1, y1 + str_h);
    }
    else
    {
        gui_set_text_clip(x1, y1 - 1, x1 + str_w, y1 + str_h);
    }
    gui_move_text_cursor(x1, y1);
    
    gui_print_bordered_text(g_abr_mainscr.main_RSK_text);
    
#ifdef __MMI_TOUCH_SCREEN__
    g_abr_mainscr.area_rsk.pos_x = x1;
    g_abr_mainscr.area_rsk.pos_y = y1;
    g_abr_mainscr.area_rsk.width = str_w;
    g_abr_mainscr.area_rsk.height = str_h;
#endif
    
    gui_pop_text_clip();
    gui_pop_clip();
    
    mmi_abrepeat_redraw_main_title();
    mmi_abrepeat_redraw_main_volumebar();
    mmi_abrepeat_redraw_volumectrl(FALSE, FALSE);
    mmi_abrepeat_redraw_volumectrl(TRUE, FALSE);
    mmi_abrepeat_redraw_progress_bar();
    StartTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER, ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY, mmi_abrepeat_timer);
    mmi_abrepeat_redraw_main_buttons();
    
    for (i = 0; i < MAX_AB_POINT; i++)
    {
        mmi_abrepeat_redraw_absection_buttons(i);
    }
    mmi_abrepeat_redraw_once_always_button(FALSE);
    mmi_abrepeat_redraw_mode_switch_button(FALSE);
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_main_title
* DESCRIPTION
*  redraw ab repeater main title
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_main_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height, w;
    S32 x1 = g_abr_mainscr.area_title.pos_x;
    S32 y1 = g_abr_mainscr.area_title.pos_y;
    S32 x2 = g_abr_mainscr.area_title.pos_x + g_abr_mainscr.area_title.width - 1;
    S32 y2 = g_abr_mainscr.area_title.pos_y + g_abr_mainscr.area_title.height - 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    /* title */
    gui_scrolling_text_stop(&abrepeat_main_scrolling_title);
    gui_set_font(&MMI_medium_font);
    gui_measure_string(g_abrepeat.title, &w, &character_height);
    if (w > g_abr_mainscr.area_title.width)
    {
        /* scrolling */
        if (!g_abrepeat.is_init_scrolling_text)
        {
            gui_scrolling_text_stop(&abrepeat_main_scrolling_title);
            gui_create_scrolling_text(
                &abrepeat_main_scrolling_title,
                x1,
                y1,
                g_abr_mainscr.area_title.width,
                g_abr_mainscr.area_title.height,
                g_abrepeat.title,
                mmi_abrepeat_scroll_main_title_handler,
                mmi_abrepeat_redraw_main_title_background,
                *((current_MMI_theme)->title_text_color),
                *((current_MMI_theme)->title_text_border_color));

            abrepeat_main_scrolling_title.text_font = MMI_medium_font;
            abrepeat_main_scrolling_title.flags |=UI_SCROLLING_TEXT_BORDERED_TEXT;
            g_abrepeat.is_init_scrolling_text = TRUE;
        }
        
        gui_change_scrolling_text(&abrepeat_main_scrolling_title, g_abrepeat.title);
        gui_show_scrolling_text(&abrepeat_main_scrolling_title);
    }
    else
    {
        /* background */
        mmi_abrepeat_redraw_main_title_background(x1-1, y1-1, x2, y2);
        
        gui_push_text_clip();
        gui_set_text_clip(x1-1, y1-1, x2, y2);
        gui_set_text_color(*((current_MMI_theme)->title_text_color)); 
        gui_set_text_border_color(*((current_MMI_theme)->title_text_border_color));
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (g_abr_mainscr.area_title.width + w) / 2, y1);
        }
        else
        {
            gui_move_text_cursor(x1 + (g_abr_mainscr.area_title.width - w) / 2, y1);
        }
        gui_set_line_height(character_height);
        gui_print_bordered_text(g_abrepeat.title);
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
*  mmi_abrepeat_scroll_main_title_handler
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_scroll_main_title_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&abrepeat_main_scrolling_title);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_main_title_background
* DESCRIPTION
*  redraw ab repeater main title background
* PARAMETERS
*  x1      [IN]        
*  y1      [IN]        
*  x2      [IN]        
*  y2      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_main_title_background(S32 x1, S32 y1, S32 x2, S32 y2)
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
    gui_fill_rectangle(x1, y1, x2, y2, g_abr_mainscr.text_bg_color);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_main_volumebar
* DESCRIPTION
*  redraw AB repeater  main volume bar
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_main_volumebar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = g_abr_mainscr.volumebar.x;
    S32 y1 = g_abr_mainscr.volumebar.y;
    S32 x2 = g_abr_mainscr.volumebar.x + g_abr_mainscr.volumebar.w - 1;
    S32 y2 = g_abr_mainscr.volumebar.y + g_abr_mainscr.volumebar.h - 1;
    U32 dv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    dv = g_abr_mainscr.volumebar.h - ((U32) g_abrepeat.volume + 1) * (g_abr_mainscr.volumebar.h -
        g_abr_mainscr.volumebar.ind_left) /
        MAX_VOL_LEVEL;
        
    if (dv > (U32) g_abr_mainscr.volumebar.h)
    {
        dv = (U32) g_abr_mainscr.volumebar.h;
    }
#else
    dv = g_abr_mainscr.volumebar.ind_left + ((U32) g_abrepeat.volume + 1) * (g_abr_mainscr.volumebar.w -
        g_abr_mainscr.volumebar.ind_left) /
        MAX_VOL_LEVEL;
    
    if (dv > (U32) g_abr_mainscr.volumebar.w)
    {
        dv = (U32) g_abr_mainscr.volumebar.w;
    }
#endif

    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    /* background & indicator */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_fill_rectangle(x1, y1, x2, y2, g_abr_mainscr.text_bg_color);
#if ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    gui_set_clip(x1, y1 + dv, x2, y2);
    gui_show_image(x1, y1 + dv, g_abr_mainscr.volumebar.ind_img);
#else
    gui_set_clip(x1, y1, x1 + dv, y2);
    gui_show_image(x1, y1, g_abr_mainscr.volumebar.ind_img);
#endif

    gui_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_main_button
* DESCRIPTION
*  redraw ab repeater a button in main screen
* PARAMETERS
*  btn_idx     [IN]        
*  bPressed        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_main_button(U8 btn_idx, BOOL bPressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    abrepeat_up_down_icon_struct *button_p;
    S32 x1, x2, y1, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (btn_idx >= NO_OF_ABREPEAT_MAIN_AUDIO_BUTTONS)
    {
        return;
    }
    
    button_p = &g_abr_mainscr.audio_btns[btn_idx];
    x1 = button_p->area.pos_x;
    y1 = button_p->area.pos_y;
    x2 = button_p->area.pos_x + button_p->area.width - 1;
    y2 = button_p->area.pos_y + button_p->area.height - 1;
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    gui_show_image(x1, y1, bPressed ? button_p->down_img : button_p->up_img);
    
    gui_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_main_buttons
* DESCRIPTION
*  redraw ab repeater  main play buttons
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_main_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signed char i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = ABREPEAT_MAIN_REWIND; i < ABREPEAT_MAIN_PAUSE; i++)
    {
        mmi_abrepeat_redraw_main_button(
            i,
            (BOOL)((g_abrepeat.main_selected_button == i) && g_abrepeat.is_main_sel_btn_down));
    }
    
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_PLAY)
    {
        if (g_abrepeat.is_main_sel_btn_down)
        {
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, TRUE);
        }
        else
        {
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PAUSE, FALSE);
        }
    }
    else if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_PAUSE)
    {
        if (g_abrepeat.is_main_sel_btn_down)
        {
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PAUSE, TRUE);
        }
        else
        {
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, FALSE);
        }
    }
    else
    {
        mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, FALSE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_exit_mainscreen
* DESCRIPTION
*  exit AB repeater main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_exit_mainscreen(void)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_flatten_to_base(abrepeat_skin_layer, abrepeat_osd_layer, 0, 0);
    gdi_layer_free(abrepeat_skin_layer);
    gdi_layer_multi_layer_disable();
    
    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(abrepeat_osd_layer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    gui_scrolling_text_stop(&abrepeat_main_scrolling_title);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_absection_buttons
* DESCRIPTION
*  redraw ab repeater  AB section key buttons(0~9)
* PARAMETERS
*  absection       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_absection_buttons(S32 absection)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = g_abr_mainscr.absection_btns[absection].area.pos_x;
    S32 y1 = g_abr_mainscr.absection_btns[absection].area.pos_y;
    S32 x2 = g_abr_mainscr.absection_btns[absection].area.pos_x + g_abr_mainscr.absection_btns[absection].area.width - 1;
    S32 y2 = g_abr_mainscr.absection_btns[absection].area.pos_y + g_abr_mainscr.absection_btns[absection].area.height - 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (absection < 0)
    {
        return;
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    /* ab section button */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, g_abr_mainscr.absection_btns[absection].img);   /* draw the digit image */
    
    x1 += (g_abr_mainscr.absection_btns[absection].area.width- g_abr_mainscr.operation_button_w)/2;
    y1 += g_abr_mainscr.absection_btns[absection].area.height - g_abr_mainscr.operation_button_h;
    x2 = x1 + g_abr_mainscr.operation_button_w;
    gui_set_clip(x1, y1, x2, y2);
    switch (g_mmi_abrepeat_draw_refer_state[absection])
    {
    case AB_SECTION_DISABLED:
        if (g_abrepeat.is_absection_sel_btn_down == TRUE)
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_nonset_down_img);
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_nonset_img);
        }
        break;
    case AB_SECTION_FIRST_SET:
        if (g_abrepeat.is_absection_sel_btn_down == TRUE)
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_partial_set_down_img);
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_partial_set_img);
        }
        break;
    case AB_SECTION_COMPLETE_SET:
        if (g_abrepeat.is_absection_sel_btn_down == TRUE)
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_set_down_img);
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_set_img);
        }
        break;
    case AB_SECTION_NON_PLAYING:
        if (g_abrepeat.is_absection_sel_btn_down == TRUE)
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_set_down_img);
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.absection_set_img);
        }
        break;
    case AB_SECTION_PLAYING:
        gui_show_image(x1, y1, g_abr_mainscr.absection_play_img);
        break;
    default:
        gui_show_image(x1, y1, g_abr_mainscr.absection_nonset_img);
        break;
    }
    
    gui_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_once_always_button
* DESCRIPTION
*  redraw ab repeater  Once/ALways or repeat button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_once_always_button(BOOL bPressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = g_abr_mainscr.btn_replay.area.pos_x;
    S32 y1 = g_abr_mainscr.btn_replay.area.pos_y;
    S32 x2 = g_abr_mainscr.btn_replay.area.pos_x + g_abr_mainscr.btn_replay.area.width - 1;
    S32 y2 = g_abr_mainscr.btn_replay.area.pos_y + g_abr_mainscr.btn_replay.area.height - 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    /* ab section button */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    if (g_abrepeat.replay_btn_state == AB_REPLAY_DISABLE)
    {
        gui_show_image(x1, y1, g_abr_mainscr.btn_replay.disable_img);
    }
    else if(g_abrepeat.replay_btn_state == AB_REPLAY_ONCE)
    {   
        if (bPressed)
        {
            gui_show_image(x1, y1, g_abr_mainscr.btn_replay.off_down_img); 
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.btn_replay.off_up_img); 
        }           
    }
    else /*AB_REPLAY_ALWAYS*/
    {
        if (bPressed)
        {
            gui_show_image(x1, y1, g_abr_mainscr.btn_replay.on_down_img);
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.btn_replay.on_up_img);
        }         
    }
    
    gui_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_progress_bar
* DESCRIPTION
*  redraw ab repeater  Progress bar and Indicator image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_progress_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    S32 x1 = g_abr_mainscr.progress_bar.x;
    S32 y1 = g_abr_mainscr.progress_bar.y;
    S32 x2 = g_abr_mainscr.progress_bar.x + g_abr_mainscr.progress_bar.w - 1;
    S32 y2 = g_abr_mainscr.progress_bar.y + g_abr_mainscr.progress_bar.h;
    S32 in_x1, in_y1, in_x2, in_y2;
    
    S32 rect_x1 = g_abr_mainscr.progress_bar_rect.x;
    S32 rect_y1 = g_abr_mainscr.progress_bar_rect.y;
    S32 rect_x2 = g_abr_mainscr.progress_bar_rect.x + g_abr_mainscr.progress_bar_rect.w - 1;
    S32 rect_y2 = g_abr_mainscr.progress_bar_rect.y + g_abr_mainscr.progress_bar_rect.h - 1;
    
    /* U16 total_offset; */
    S32 start_offset_x; /* current_offset; */
    //U32 current_offset; /* call the expected api to get the current offset */
    S32 audio_played_x;
    float temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_abrepeat.prgbar_cur_offset > g_abrepeat.total_offset)
    {
        return ;
    }
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    /* ab section button */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, g_abr_mainscr.progress_bar.img);
    
    gui_set_clip(rect_x1, rect_y1, rect_x2, rect_y2);
    gui_show_image(rect_x1, rect_y1, g_abr_mainscr.progress_bar_rect.img);
    
    temp = (float)((float)(rect_x2 - rect_x1) / (float)(g_abrepeat.total_offset));
    audio_played_x = (S32)(temp*g_abrepeat.prgbar_cur_offset);
    
    ///g_mmi_abrepeat_start_progress is set only during recording
    ////in Setting Screen
    if (!g_mmi_abrepeat_start_progress && !g_mmi_abrepeat_end_progress) /* normal  playing mode */
    {
        if (g_abrepeat.curr_play_section >= 0)  /* /ab section play */
        {
            /* manish put condition here  so that even no single pixel */
            if (temp != 0)
            {
                start_offset_x = (S32) (g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abstart * temp);
                gui_fill_rectangle(rect_x1, rect_y1, start_offset_x + rect_x1, rect_y2, g_abr_mainscr.audio_file_played_color);
                gui_fill_rectangle(
                    start_offset_x + rect_x1,
                    rect_y1,
                    audio_played_x + rect_x1,
                    rect_y2,
                    g_abr_mainscr.absection_color);
            }
        }
        else
        {
            if (audio_played_x != 0)
            {
                gui_fill_rectangle(rect_x1, rect_y1, audio_played_x + rect_x1, rect_y2, g_abr_mainscr.audio_file_played_color);
            }
        }
    }
    else    /* ab section recording play */
    {
        start_offset_x = (S32) (g_abrepeat.cur_setab_start_offset * temp);
        gui_fill_rectangle(rect_x1, rect_y1, start_offset_x + rect_x1, rect_y2, g_abr_mainscr.audio_file_played_color);
        if (g_mmi_abrepeat_end_progress)
        {
            g_mmi_abrepeat_end_progress = FALSE;
            gui_fill_rectangle(
                start_offset_x + rect_x1,
                rect_y1,
                audio_played_x + rect_x1,
                rect_y2,
                g_abr_mainscr.audio_file_played_color);
        }
        else    /* recording state */
        {
            gui_fill_rectangle(start_offset_x + rect_x1, rect_y1, audio_played_x + rect_x1, rect_y2, g_abr_mainscr.absection_color);
        }
        
    }
    
    /* Indication bar coordinates */
    in_x1 = (audio_played_x - (g_abr_mainscr.progress_bar.ind_w >> 1)) + rect_x1;
    in_y1 = y1 + g_abr_mainscr.progress_bar.ind_off_y;
    in_x2 = (audio_played_x + (g_abr_mainscr.progress_bar.ind_w >> 1)) + rect_x1;
    in_y2 = in_y1 + g_abr_mainscr.progress_bar.ind_h;
    gui_set_clip(in_x1, in_y1, in_x2, in_y2);
    gui_show_image(in_x1, in_y1, g_abr_mainscr.progress_bar.ind_img);
    
    gui_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_init_main_screen_images
* DESCRIPTION
*  init AB repeater main screen images
* PARAMETERS
*  skin        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_init_main_screen_images(S8 skin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const abrepeat_skin_struct *skinab_p = &g_abrepeat_skins[skin];
    S32 i, w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bg */
    g_abr_mainscr.main_bg_img = (PU8) GetImage(skinab_p->main_bg_img_id);
    
    /* scr_text_border_color, text fg, bg color */
    g_abr_mainscr.text_border_color = gui_color(
        skinab_p->text_ab_border_color_r,
        skinab_p->text_ab_border_color_g,
        skinab_p->text_ab_border_color_b);
    g_abr_mainscr.text_fg_color = gui_color(
        skinab_p->text_main_fg_color_r,
        skinab_p->text_main_fg_color_g,
        skinab_p->text_main_fg_color_b);
#ifdef __GDI_MEMORY_PROFILE_2__
    g_abr_mainscr.text_bg_color = gui_color(0, 0, 255);   /* transparent */
#else /* __GDI_MEMORY_PROFILE_2__ */ 
    g_abr_mainscr.text_bg_color = gui_color(
        skinab_p->text_main_bg_color_r,
        skinab_p->text_main_bg_color_g,
        skinab_p->text_main_bg_color_b);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    
    g_abr_mainscr.audio_file_played_color = gui_color(
        skinab_p->audio_bg_color_r,
        skinab_p->audio_bg_color_g,
        skinab_p->audio_bg_color_b);
    
    g_abr_mainscr.absection_color = gui_color(skinab_p->absection_color_r, skinab_p->absection_color_g, skinab_p->absection_color_b);
    /* title */
    g_abr_mainscr.area_title.pos_x = skinab_p->title_ab_x;
    g_abr_mainscr.area_title.pos_y = skinab_p->title_ab_y;
    g_abr_mainscr.area_title.width = skinab_p->title_ab_w;
    g_abr_mainscr.area_title.height = skinab_p->title_ab_h;
    
    /* volume */
    g_abr_mainscr.volumebar.x = skinab_p->volumebar_ab_x;
    g_abr_mainscr.volumebar.y = skinab_p->volumebar_ab_y;
    g_abr_mainscr.volumebar.ind_left = skinab_p->volumebar_ab_ind_left;
    g_abr_mainscr.volumebar.ind_img = (PU8) GetImage(skinab_p->volumebar_ab_ind_image_id);
    gui_measure_image(g_abr_mainscr.volumebar.ind_img, &w, &h);
    g_abr_mainscr.volumebar.w = (S16) w;
    g_abr_mainscr.volumebar.h = (S16) h;
    
    g_abr_mainscr.vol_dec.area.pos_x = skinab_p->volume_dec_x;
    g_abr_mainscr.vol_dec.area.pos_y = skinab_p->volume_dec_y;
    g_abr_mainscr.vol_dec.up_img = (PU8)GetImage(skinab_p->volume_dec_button_up_img_id);
    g_abr_mainscr.vol_dec.down_img = (PU8)GetImage(skinab_p->volume_dec_button_down_img_id);
    gui_measure_image(g_abr_mainscr.vol_dec.up_img, &w, &h);
    g_abr_mainscr.vol_dec.area.width = (S16)w;
    g_abr_mainscr.vol_dec.area.height = (S16)h;
    
    g_abr_mainscr.vol_inc.area.pos_x = skinab_p->volume_inc_x;
    g_abr_mainscr.vol_inc.area.pos_y = skinab_p->volume_inc_y;
    g_abr_mainscr.vol_inc.up_img = (PU8)GetImage(skinab_p->volume_inc_button_up_img_id);
    g_abr_mainscr.vol_inc.down_img = (PU8)GetImage(skinab_p->volume_inc_button_down_img_id);
    gui_measure_image(g_abr_mainscr.vol_inc.up_img, &w, &h);
    g_abr_mainscr.vol_inc.area.width = (S16)w;
    g_abr_mainscr.vol_inc.area.height = (S16)h;
    
    g_abr_mainscr.btn_replay.area.pos_x = skinab_p->once_always_button_x;
    g_abr_mainscr.btn_replay.area.pos_y = skinab_p->once_always_button_y;
    g_abr_mainscr.btn_replay.on_up_img = (PU8) GetImage(skinab_p->once_always_button_up_img_id);
    g_abr_mainscr.btn_replay.on_down_img = (PU8) GetImage(skinab_p->once_always_button_down_img_id);
    g_abr_mainscr.btn_replay.off_down_img = (PU8) GetImage(skinab_p->once_always_button_off_down_img_id);
    g_abr_mainscr.btn_replay.off_up_img = (PU8) GetImage(skinab_p->once_always_button_off_up_img_id);
    g_abr_mainscr.btn_replay.disable_img = (PU8) GetImage(skinab_p->once_always_button_disable_img_id);
    gui_measure_image(g_abr_mainscr.btn_replay.on_up_img, &w, &h);
    g_abr_mainscr.btn_replay.area.width = (S16)w;
    g_abr_mainscr.btn_replay.area.height = (S16)h;
    
    g_abr_mainscr.set_mode.area.pos_x = g_abr_mainscr.play_mode.area.pos_x = skinab_p->mode_set_button_x;
    g_abr_mainscr.set_mode.area.pos_y = g_abr_mainscr.play_mode.area.pos_y = skinab_p->mode_set_button_y;
    g_abr_mainscr.set_mode.up_img = (PU8) GetImage(skinab_p->setting_mode_button_up_image_id);
    g_abr_mainscr.set_mode.down_img = (PU8) GetImage(skinab_p->setting_mode_button_down_image_id);
    g_abr_mainscr.play_mode.up_img = (PU8) GetImage(skinab_p->play_mode_button_up_image_id);
    g_abr_mainscr.play_mode.down_img = (PU8) GetImage(skinab_p->play_mode_button_down_image_id);
    gui_measure_image(g_abr_mainscr.set_mode.up_img, &w, &h);
    g_abr_mainscr.set_mode.area.width = g_abr_mainscr.play_mode.area.width = w;
    g_abr_mainscr.set_mode.area.height = g_abr_mainscr.play_mode.area.height = h;
    
    /* Progress bar image coordinates */
    g_abr_mainscr.progress_bar.x = skinab_p->progress_bar_x;
    g_abr_mainscr.progress_bar.y = skinab_p->progress_bar_y;
    g_abr_mainscr.progress_bar.img = (PU8) GetImage(skinab_p->progress_bar_img_id);
    gui_measure_image(g_abr_mainscr.progress_bar.img, &w, &h);
    g_abr_mainscr.progress_bar.w = (S16) w;
    g_abr_mainscr.progress_bar.h = (S16) h;
    
    /* Indicator arrow image coordinates */
    g_abr_mainscr.progress_bar.ind_img = (PU8) GetImage(skinab_p->progress_bar_ind_img_id);
    gui_measure_image(g_abr_mainscr.progress_bar.ind_img, &w, &h);
    g_abr_mainscr.progress_bar.ind_w = (S16) w;
    g_abr_mainscr.progress_bar.ind_h = (S16) h;
    g_abr_mainscr.progress_bar.ind_off_y = skinab_p->progress_bar_ind_off_y;
    
    g_abr_mainscr.progress_bar_rect.x = skinab_p->ab_aud_file_rect_x;
    g_abr_mainscr.progress_bar_rect.y = skinab_p->ab_aud_file_rect_y;
    g_abr_mainscr.progress_bar_rect.img = (PU8) GetImage(skinab_p->progress_bar_rect_img_id);
    gui_measure_image(g_abr_mainscr.progress_bar_rect.img, &w, &h);
    g_abr_mainscr.progress_bar_rect.w = (S16) w;
    g_abr_mainscr.progress_bar_rect.h = (S16) h;
    
    /* AB section buttons */
    for (i = 0; i < MAX_AB_POINT; i++)
    {
        g_abr_mainscr.absection_btns[i].area.pos_x = skinab_p->ab_section_button_skin[i].ab_section_x;
        g_abr_mainscr.absection_btns[i].area.pos_y = skinab_p->ab_section_button_skin[i].ab_section_y;
        g_abr_mainscr.absection_btns[i].img = (PU8) GetImage(skinab_p->ab_section_button_skin[i].ab_section_button_img_id);
        gui_measure_image(g_abr_mainscr.absection_btns[i].img, &w, &h);
        g_abr_mainscr.absection_btns[i].area.width = (S16) w;
        g_abr_mainscr.absection_btns[i].area.height = (S16) h;
    }
    
    /* play, pause, stop, prev, next buttons */
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].area.pos_x = skinab_p->rewind_button_x;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].area.pos_y = skinab_p->rewind_button_y;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].up_img = (PU8) GetImage(skinab_p->rewind_button_up_image_id);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].down_img = (PU8) GetImage(skinab_p->rewind_button_down_image_id);
    gui_measure_image(g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].up_img, &w, &h);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].area.width = (S16) w;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].area.height = (S16) h;
    
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].area.pos_x = skinab_p->forward_button_x;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].area.pos_y = skinab_p->forward_button_y;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].up_img = (PU8) GetImage(skinab_p->forward_button_up_image_id);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].down_img = (PU8) GetImage(skinab_p->forward_button_down_image_id);
    gui_measure_image(g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].up_img, &w, &h);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].area.width = (S16) w;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].area.height = (S16) h;
    
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].area.pos_x = g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PAUSE].area.pos_x =
        skinab_p->play_ab_button_x;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].area.pos_y = g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PAUSE].area.pos_y =
        skinab_p->play_ab_button_y;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].up_img = (PU8) GetImage(skinab_p->play_ab_button_up_image_id);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].down_img = (PU8) GetImage(skinab_p->play_ab_button_down_image_id);
    gui_measure_image(g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].up_img, &w, &h);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].area.width = g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PAUSE].area.width = (S16) w;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].area.height = g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PAUSE].area.height = (S16) h;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PAUSE].up_img = (PU8) GetImage(skinab_p->pause_ab_button_up_image_id);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PAUSE].down_img = (PU8) GetImage(skinab_p->pause_ab_button_down_image_id);
    
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].area.pos_x = skinab_p->stop_ab_button_x;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].area.pos_y = skinab_p->stop_ab_button_y;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].up_img = (PU8) GetImage(skinab_p->stop_ab_button_up_image_id);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].down_img = (PU8) GetImage(skinab_p->stop_ab_button_down_image_id);
    gui_measure_image(g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].up_img, &w, &h);
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].area.width = (S16) w;
    g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].area.height = (S16) h;
    
    g_abr_mainscr.absection_play_img = (PU8) GetImage(skinab_p->absection_playing_img_id);
    
    g_abr_mainscr.absection_partial_set_img = (PU8) GetImage(skinab_p->absection_partial_set_img_id);
    g_abr_mainscr.absection_partial_set_down_img = (PU8) GetImage(skinab_p->absection_partial_set_down_img_id);
    g_abr_mainscr.absection_set_img = (PU8) GetImage(skinab_p->absection_set_sction_img_id);
    g_abr_mainscr.absection_set_down_img = (PU8) GetImage(skinab_p->absection_set_sction_down_img_id);
    g_abr_mainscr.absection_nonset_img = (PU8) GetImage(skinab_p->absection_nonset_section_img_id);
    g_abr_mainscr.absection_nonset_down_img = (PU8) GetImage(skinab_p->absection_nonset_section_down_img_id);
    
    gui_measure_image(g_abr_mainscr.absection_play_img, &w, &h);
    g_abr_mainscr.operation_button_w = (S16) w;
    g_abr_mainscr.operation_button_h = (S16) h;
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_mode_switch_button
* DESCRIPTION
*  redraw AB Repeater main mode switch button
* PARAMETERS
*  bPressed         [IN]      
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_mode_switch_button(BOOL bPressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = g_abr_mainscr.set_mode.area.pos_x;
    S32 y1 = g_abr_mainscr.set_mode.area.pos_y;
    S32 x2 = g_abr_mainscr.set_mode.area.pos_x + g_abr_mainscr.set_mode.area.width - 1;
    S32 y2 = g_abr_mainscr.set_mode.area.pos_y + g_abr_mainscr.set_mode.area.height - 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    /* ab section button */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    if (AB_SETTING_MODE == g_abrepeat.cur_mode)
    {
        if (bPressed)
        {
            gui_show_image(x1, y1, g_abr_mainscr.set_mode.down_img);
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.set_mode.up_img);
        }
    }
    else /*play mode*/
    {
        if (bPressed)
        {
            gui_show_image(x1, y1, g_abr_mainscr.play_mode.down_img);
        }
        else
        {
            gui_show_image(x1, y1, g_abr_mainscr.play_mode.up_img);
        } 
    }
    
    gui_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_pen_check_inside_area
* DESCRIPTION
*  
* PARAMETERS
*  pos_p     [IN]        
*  area_p    [IN]
* RETURNS
*  void
*****************************************************************************/
BOOL mmi_abrepeat_pen_check_inside_area(const mmi_pen_point_struct *pos_p, const abrepeat_area_struct *area_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pos_x = pos_p->x;
    S16 pos_y = pos_p->y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= area_p->pos_x) 
        &&(pos_y >= area_p->pos_y)
        &&(pos_x < (area_p->pos_x + area_p->width))
        &&(pos_y < (area_p->pos_y + area_p->height)))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }  
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_pen_check_inside_area_sk
* DESCRIPTION
*  
* PARAMETERS
*  pos_p     [IN]        
*  area_p    [IN]
* RETURNS
*  void
*****************************************************************************/
BOOL mmi_abrepeat_pen_check_inside_area_sk(const mmi_pen_point_struct *pos_p, const abrepeat_area_struct *area_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pos_x = pos_p->x;
    S16 pos_y = pos_p->y;

    S16 x1, x2, y1, y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        x2 = area_p->pos_x;
        x1 = area_p->pos_x - area_p->width;
    }
    else
    {
        x1 = area_p->pos_x;
        x2 = area_p->pos_x + area_p->width;
    }
    
    y1 = area_p->pos_y;
    y2 = area_p->pos_y + area_p->height;

    
    if ((pos_x >= x1) 
        &&(pos_y >= y1)
        &&(pos_x < x2)
        &&(pos_y < y2))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }  
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_pen_down_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_abr_mainscr.touch_obj = AB_PEN_NONE;
    
    /*lsk*/
    if (mmi_abrepeat_pen_check_inside_area_sk(&pos, &g_abr_mainscr.area_lsk))
    {
        g_abr_mainscr.touch_obj = AB_PEN_LSK;
        ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
        return;
    }
    
    /*rsk*/
    if (mmi_abrepeat_pen_check_inside_area_sk(&pos, &g_abr_mainscr.area_rsk))
    {
        g_abr_mainscr.touch_obj = AB_PEN_RSK;
        ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
        return;
    }
    
    /*ab section number icon*/
    for (i = 0; i < MAX_AB_POINT; i++)
    {
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.absection_btns[i].area))
        {
            g_abr_mainscr.touch_obj = i+AB_PEN_SECTION0;
            if (AB_SETTING_MODE == g_abrepeat.cur_mode)
            {
                mmi_abrepeat_setting_press_digit_down_hdlr((U16)(KEY_0+i));
            }
            else
            {
                mmi_abrepeat_play_press_digit_down_hdlr((U16)(KEY_0+i));
            }
            return;
        }
    }
    
    /*play icon*/
    if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].area))
    {
        g_abr_mainscr.touch_obj = AB_PEN_MAIN_PLAY;
        mmi_abrepeat_press_play_button_down();
        return;
    }
    
    /*stop icon*/
    if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].area))
    {
        g_abr_mainscr.touch_obj = AB_PEN_MAIN_STOP;
        mmi_abrepeat_press_stop_button_down();
        return;
    }
    
    /*forward icon*/
    if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].area))
    {
        g_abr_mainscr.touch_obj = AB_PEN_MAIN_FORWARD;
        mmi_abrepeat_press_forward_button_down();
        return;
    }
    
    /*rewind icon*/
    if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].area))
    {
        g_abr_mainscr.touch_obj = AB_PEN_MAIN_REWIND;
        mmi_abrepeat_press_rewind_button_down();
        return;
    }
    
    /*mode set icon, set_mode and play_mode is same*/
    if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.set_mode.area))
    {
        g_abr_mainscr.touch_obj = AB_PEN_SET_MODE;
        if (AB_SETTING_MODE == g_abrepeat.cur_mode)
        {
            mmi_abrepeat_setting_press_digit_down_hdlr(KEY_POUND);
        }
        else
        {
            mmi_abrepeat_play_press_digit_down_hdlr(KEY_POUND);
        }
        
        return;
    }
    
    /*replay icon*/
    if (AB_PLAY_MODE == g_abrepeat.cur_mode)
    {
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.btn_replay.area))
        {
            g_abr_mainscr.touch_obj = AB_PEN_SET_REPLAY;
            mmi_abrepeat_play_press_digit_down_hdlr(KEY_STAR);
            return;
        }
    }
    
    /*volume inc icon*/
    if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.vol_inc.area))
    {
        g_abr_mainscr.touch_obj = AB_PEN_VOLUME_INC;
        mmi_abrepeat_redraw_volumectrl(TRUE, TRUE);
        return;
    }
    
    /*volume dec icon*/
    if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.vol_dec.area))
    {
        g_abr_mainscr.touch_obj = AB_PEN_VOLUME_DEC;
        mmi_abrepeat_redraw_volumectrl(FALSE, TRUE);
        return;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_pen_up_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 btn_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abr_mainscr.touch_obj == AB_PEN_NONE)
    {
        return;
    }
    
    if (g_abr_mainscr.touch_obj >= AB_PEN_SECTION0
        && g_abr_mainscr.touch_obj <= AB_PEN_SECTION9)
    {   
        btn_idx = g_abr_mainscr.touch_obj-AB_PEN_SECTION0;
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.absection_btns[btn_idx].area))
        {
            if (AB_SETTING_MODE == g_abrepeat.cur_mode)
            {
                mmi_abrepeat_setting_press_digit_up_hdlr((U16)(btn_idx+KEY_0));
            }
            else
            {
                mmi_abrepeat_play_press_digit_up_hdlr((U16)(btn_idx+KEY_0));
            }
        } 
        
        g_abr_mainscr.touch_obj = AB_PEN_NONE;
        return;
    }
    
    switch(g_abr_mainscr.touch_obj)
    {
    case AB_PEN_LSK:
        if (mmi_abrepeat_pen_check_inside_area_sk(&pos, &g_abr_mainscr.area_lsk))
        {
            mmi_abrepeat_redraw_LSK(FALSE);
            ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
        }
        break;
        
    case AB_PEN_RSK:
        if (mmi_abrepeat_pen_check_inside_area_sk(&pos, &g_abr_mainscr.area_rsk))
        {
            mmi_abrepeat_redraw_RSK(FALSE);
            ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
        }
        break;
        
    case AB_PEN_MAIN_PLAY:
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].area))
        {
            mmi_abrepeat_press_play_button_up();
        }
        break;
        
    case AB_PEN_MAIN_STOP:
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].area))
        {
            mmi_abrepeat_press_stop_button_up();
        }
        break;
        
    case AB_PEN_MAIN_FORWARD:  
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].area))
        {
            mmi_abrepeat_press_forward_button_up();  
        }
        break;
        
    case AB_PEN_MAIN_REWIND:
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].area))
        {
            mmi_abrepeat_press_rewind_button_up();
        }
        break;
        
    case AB_PEN_SET_MODE:       
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.set_mode.area))
        {
            if (AB_SETTING_MODE == g_abrepeat.cur_mode)
            {
                mmi_abrepeat_setting_press_digit_up_hdlr(KEY_POUND);
            }
            else
            {
                mmi_abrepeat_play_press_digit_up_hdlr(KEY_POUND);
            }
        }
        break;
        
    case AB_PEN_SET_REPLAY:
        if (AB_PLAY_MODE == g_abrepeat.cur_mode)
        {
            if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.btn_replay.area))
            {
                mmi_abrepeat_play_press_digit_up_hdlr(KEY_STAR);
            }
        }
        break;
        
    case AB_PEN_VOLUME_INC:
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.vol_inc.area))
        {
            mmi_abrepeat_redraw_volumectrl(TRUE, FALSE);
            mmi_abrepeat_press_inc_volume();      
        }
        break;
        
    case AB_PEN_VOLUME_DEC: 
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.vol_dec.area))
        {
            mmi_abrepeat_redraw_volumectrl(FALSE, FALSE);
            mmi_abrepeat_press_dec_volume();
        }
        break;
    }
    
    g_abr_mainscr.touch_obj = AB_PEN_NONE;
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_pen_move_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 btn_idx;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abr_mainscr.touch_obj == AB_PEN_NONE)
    {
        return;
    }
    
    if (g_abr_mainscr.touch_obj >= AB_PEN_SECTION0 
        && g_abr_mainscr.touch_obj <= AB_PEN_SECTION9)
    {      
        btn_idx = g_abr_mainscr.touch_obj - AB_PEN_SECTION0;
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.absection_btns[btn_idx].area))
        {
            if (AB_SETTING_MODE == g_abrepeat.cur_mode)
            {
                mmi_abrepeat_setting_press_digit_down_hdlr((U16)btn_idx);
            }
            else
            {
                mmi_abrepeat_play_press_digit_down_hdlr((U16)btn_idx);
            }
        }
        else
        {
            /*After a long press and pen move out the button,the flag should clear */
            g_mmi_abrepeat_section_deleted = FALSE;
            g_abrepeat.is_absection_sel_btn_down = FALSE;
            mmi_abrepeat_redraw_absection_buttons(btn_idx);
            /*in pen down handler, has redraw the pressed main button
            so here redraw back to up main button*/
            if (g_abrepeat.cur_mode == AB_PLAY_MODE && g_mmi_abrepeat_record_exist[btn_idx] == TRUE)
            {
                if (g_abrepeat.state == AB_STATE_PLAY)
                {
                    mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PAUSE, FALSE);
                }
                else
                {
                    mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, FALSE);
                }
            }
        }
        return;
    }
    
    switch(g_abr_mainscr.touch_obj)
    {
    case AB_PEN_LSK:
        if (mmi_abrepeat_pen_check_inside_area_sk(&pos, &g_abr_mainscr.area_lsk))
        {
            mmi_abrepeat_redraw_LSK(TRUE);            
        }
        else
        {
            mmi_abrepeat_redraw_LSK(FALSE); 
        }
        break;
        
    case AB_PEN_RSK:
        if (mmi_abrepeat_pen_check_inside_area_sk(&pos, &g_abr_mainscr.area_rsk))
        {
            mmi_abrepeat_redraw_RSK(TRUE);
        }
        else
        {
            mmi_abrepeat_redraw_RSK(FALSE);
        }
        break;
        
    case AB_PEN_MAIN_PLAY:
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_PLAY].area))
        {
            mmi_abrepeat_press_play_button_down();
        }
        else
        {
            g_abrepeat.is_main_sel_btn_down = FALSE;
            if (AB_STATE_PLAY == g_abrepeat.state) 
            {
                mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PAUSE, FALSE);
            }
            else /*PAUSED or IDLE*/
            { 
                mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, FALSE);
            }
        }
        break;
        
    case AB_PEN_MAIN_STOP:
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_STOP].area))
        {
            mmi_abrepeat_press_stop_button_down();     
        }
        else
        {
            g_abrepeat.is_main_sel_btn_down = FALSE;
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_STOP, FALSE);    
        }
        break;
        
    case AB_PEN_MAIN_FORWARD:  
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_FORWARD].area))
        {    
            mmi_abrepeat_press_forward_button_down();
        }
        else
        {
            g_abrepeat.is_main_sel_btn_down = FALSE;
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_FORWARD, FALSE);
        }
        break;
        
    case AB_PEN_MAIN_REWIND:
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.audio_btns[ABREPEAT_MAIN_REWIND].area))
        {
            mmi_abrepeat_press_rewind_button_down();
        }
        else
        {
            g_abrepeat.is_main_sel_btn_down = FALSE;
            mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_REWIND, FALSE);
        }
        break;
        
    case AB_PEN_SET_MODE:    
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.set_mode.area))
        {
            if (g_abrepeat.cur_mode == AB_SETTING_MODE)
            {
                mmi_abrepeat_setting_press_digit_down_hdlr(KEY_POUND);
            }
            else
            {
                mmi_abrepeat_play_press_digit_down_hdlr(KEY_POUND);
            }
        } 
        else
        {
            mmi_abrepeat_redraw_mode_switch_button(FALSE);
        }
        break; 
        
    case AB_PEN_SET_REPLAY:
        if (mmi_abrepeat_pen_check_inside_area(&pos,& g_abr_mainscr.btn_replay.area))
        {
            mmi_abrepeat_play_press_digit_down_hdlr(KEY_STAR);
        }
        else
        {
            mmi_abrepeat_redraw_once_always_button(FALSE);
        }
        break;
        
    case AB_PEN_VOLUME_INC:      
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.vol_inc.area))
        {
            mmi_abrepeat_redraw_volumectrl(TRUE, TRUE);
        }
        else
        {
            mmi_abrepeat_redraw_volumectrl(TRUE, FALSE);
        }
        break;
        
    case AB_PEN_VOLUME_DEC:      
        if (mmi_abrepeat_pen_check_inside_area(&pos, &g_abr_mainscr.vol_dec.area))
        {
            mmi_abrepeat_redraw_volumectrl(FALSE, TRUE);
        }  
        else
        {
            mmi_abrepeat_redraw_volumectrl(FALSE, FALSE);
        }
        break;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_pen_long_tap_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (AB_SETTING_MODE == g_abrepeat.cur_mode)
    {
        for (i = 0; i < MAX_AB_POINT; i++)
        {
            if (mmi_abrepeat_pen_check_inside_area(&pos,& g_abr_mainscr.absection_btns[i].area))
            {
                mmi_abrepeat_setting_long_press_digit_hdlr((U16)(KEY_0+i));  
                return;
            }
        }
    }
}

#endif /*__MMI_TOUCH_SCREEN__*/


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_volumectrl
* DESCRIPTION
*  redraw abrepeater main volume inc / dec control
* PARAMETERS
*  bInc         [IN]
*  bPressed     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_volumectrl(BOOL bInc, BOOL bPressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    abrepeat_up_down_icon_struct *volctrl_p = (bInc ? &g_abr_mainscr.vol_inc : &g_abr_mainscr.vol_dec);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = volctrl_p->area.pos_x;
    y1 = volctrl_p->area.pos_y;
    x2 = volctrl_p->area.pos_x + volctrl_p->area.width - 1;
    y2 = volctrl_p->area.pos_y + volctrl_p->area.height - 1;
    
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    
    /* background & indicator */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, (bPressed ? volctrl_p->down_img : volctrl_p->up_img));
    gui_pop_clip();
    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


#endif /* __MMI_AB_REPEATER__ */ 


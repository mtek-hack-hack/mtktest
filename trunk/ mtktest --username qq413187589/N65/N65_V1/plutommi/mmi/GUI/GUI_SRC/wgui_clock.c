/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  wgui_clock.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  clock related funtions
 *
 * Author:
 * -------
 * -------
 *
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
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/


#include "GlobalDefs.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "gui_themes.h"
#include "wgui_categories.h"
#include "wgui_clock.h"
#include "gui_clock.h"
#include "MMI_features.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "DateTimeGprot.h"
#include "DateTimeType.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_defs.h"

/*clock list*/
gui_clock_struct g_wgui_clock_list[WGUI_CLOCK_MAX_ITEMS];
/*first time to init clock component*/
static MMI_BOOL g_wgui_clock_first_time_init = MMI_TRUE;


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_init
 * DESCRIPTION
 *  init the clocks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_clock_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_clock_first_time_init)
    {
        for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
        {
            g_wgui_clock_list[i].active = MMI_FALSE;
        }

        g_wgui_clock_first_time_init = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_create
 * DESCRIPTION
 *  create a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  x               [IN]        Start x posiion
 *  y               [IN]        Start y position
 *  width           [IN]        Width of clock
 *  height          [IN]        Height of clock
 *  clock_type      [IN]        Type of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_create(U32 clock_id, S32 x, S32 y, S32 width, S32 height, gui_clock_type_enum clock_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clock_init();

    if (clock_id >= WGUI_CLOCK_MAX_ITEMS)
    {
        return;    
    }

    if (clock_type >= GUI_CLOCK_TYPE_END_OF_ENUM)
    {
        return;    
    }

    if (clock_id >= WGUI_CLOCK_MAX_ITEMS_MAIN_LCD && clock_type <= GUI_CLOCK_TYPE_DIGITAL_TIME)
    {
        return;
     }

    if (clock_id < WGUI_CLOCK_MAX_ITEMS_MAIN_LCD && clock_type >GUI_CLOCK_TYPE_DIGITAL_TIME)
    {
        return;    
    }

    gui_clock_create(&g_wgui_clock_list[clock_id], x, y, width, height, clock_type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close
 * DESCRIPTION
 *  close a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close(U32 clock_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_close(&g_wgui_clock_list[clock_id]);  
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close_all
 * DESCRIPTION
 *  close all clock components
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i< WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        gui_clock_close(&g_wgui_clock_list[i]); 
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close_main_lcd
 * DESCRIPTION
 *  close all clock components in main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close_main_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS_MAIN_LCD; i ++)
    {
        gui_clock_close(&g_wgui_clock_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_close_sub_lcd
 * DESCRIPTION
 *  close all clock components in sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_close_sub_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = WGUI_CLOCK_MAX_ITEMS_MAIN_LCD; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        gui_clock_close(&g_wgui_clock_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_show
 * DESCRIPTION
 *  show a clock component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;
    GDI_HANDLE old_lcd, old_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE)
        {
            GDI_LOCK;
            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);
        
            gui_clock_show(&g_wgui_clock_list[i]);  

            gdi_layer_blt_previous(
                g_wgui_clock_list[i].x,
                g_wgui_clock_list[i].y,
                g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1, 
                g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1);
            
            gdi_layer_pop_and_restore_active();            
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_show_main_lcd
 * DESCRIPTION
 *  show all clock components in main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_show_main_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_HANDLE old_lcd, old_layer;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS_MAIN_LCD; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE)
        {
            GDI_LOCK;
            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);
            /*shaokai add it start.090901*/
        
			if (i == 1)	
			{
				color col = {128,0,0,100};
				g_wgui_clock_list[i].date_text_border_color = col;
			}
			/*shaokai add it end.090901*/
            gui_clock_show(&g_wgui_clock_list[i]);  

            gdi_layer_blt_previous(
                g_wgui_clock_list[i].x,
                g_wgui_clock_list[i].y,
                g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1, 
                g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1);
            
            gdi_layer_pop_and_restore_active();            
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;
            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_show_sub_lcd
 * DESCRIPTION
 *  show all clock components in sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_show_sub_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_HANDLE old_lcd, old_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = WGUI_CLOCK_MAX_ITEMS_MAIN_LCD; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE)
        {
            GDI_LOCK;
            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);
        
            gui_clock_show(&g_wgui_clock_list[i]);  

            gdi_layer_blt_previous(
                g_wgui_clock_list[i].x,
                g_wgui_clock_list[i].y,
                g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1, 
                g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1);
            
            gdi_layer_pop_and_restore_active();            
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;
            
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_update
 * DESCRIPTION
 *  update clock components
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_HANDLE old_lcd, old_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if (g_wgui_clock_list[i].active == MMI_TRUE)
        {
            GDI_LOCK;            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);

            gui_clock_update(&g_wgui_clock_list[i]);    
            
            gdi_layer_blt_previous(
                g_wgui_clock_list[i].x,
                g_wgui_clock_list[i].y,
                g_wgui_clock_list[i].x + g_wgui_clock_list[i].width - 1, 
                g_wgui_clock_list[i].y + g_wgui_clock_list[i].height - 1);
            
            gdi_layer_pop_and_restore_active();            
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_update_main_lcd
 * DESCRIPTION
 *  update all clock components in main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_update_main_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_HANDLE old_lcd, old_layer;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS_MAIN_LCD; i ++)
    {
        if(g_wgui_clock_list[i].active == MMI_TRUE)
        {
            GDI_LOCK;            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);

            gui_clock_update(&g_wgui_clock_list[i]);    
            
            gdi_layer_pop_and_restore_active();            
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_update_sub_lcd
 * DESCRIPTION
 *  update all clock components in sub lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_update_sub_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    GDI_HANDLE old_lcd, old_layer;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = WGUI_CLOCK_MAX_ITEMS_MAIN_LCD; i < WGUI_CLOCK_MAX_ITEMS; i ++)
    {
        if(g_wgui_clock_list[i].active == MMI_TRUE)
        {
            GDI_LOCK;            
            gdi_layer_get_active(&old_layer);
            gdi_lcd_get_active(&old_lcd);
            
            gdi_lcd_set_active(g_wgui_clock_list[i].target_lcd);
            gdi_layer_push_and_set_active(g_wgui_clock_list[i].target_layer);

            gui_clock_update(&g_wgui_clock_list[i]);    
            
            gdi_layer_pop_and_restore_active();            
            gdi_lcd_set_active(old_lcd);
            gdi_layer_set_active(old_layer);
            
            GDI_UNLOCK;

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_move
 * DESCRIPTION
 *  move a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  x               [IN]        Start x posiion
 *  y               [IN]        Start y position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_move(U32 clock_id, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_move(&g_wgui_clock_list[clock_id], x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_resize
 * DESCRIPTION
 *  resize a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  width           [IN]        Width of clock
 *  height          [IN]        Height of clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_resize(U32 clock_id, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_resize(&g_wgui_clock_list[clock_id], width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time
 * DESCRIPTION
 *  set the time of a clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  newtime         [IN]        New time of the clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time(U32 clock_id, applib_time_struct newtime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_time(&g_wgui_clock_list[clock_id], newtime);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_get_time
 * DESCRIPTION
 *  get the time of a clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  time            [IN]        Current time of the clock
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_get_time(U32 clock_id, applib_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_get_time(&g_wgui_clock_list[clock_id], time);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_hide_function
 * DESCRIPTION
 *  set the hide callback function of the clock
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  f               [IN]        New hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_hide_function(U32 clock_id, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }
    
    gui_clock_set_hide_function(&g_wgui_clock_list[clock_id], f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_analog_clock_hour_hand_color
 * DESCRIPTION
 *  set the color of anlog clock's hour hand
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of hour hand
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_analog_clock_hour_hand_color(U32 clock_id, color new_color)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_analog_clock_hour_hand_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_analog_clock_min_hand_color
 * DESCRIPTION
 *  set the color of anlog clock's minute hand
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of minute hand
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_analog_clock_min_hand_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }
    
    gui_clock_set_analog_clock_min_hand_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_font
 * DESCRIPTION
 *  set the font of date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_font        [IN]        New font of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_font(U32 clock_id, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_date_text_font(&g_wgui_clock_list[clock_id], new_font);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_color
 * DESCRIPTION
 *  set the color of date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_date_text_color(&g_wgui_clock_list[clock_id], new_color);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_border_color
 * DESCRIPTION
 *  set the border color of date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New border color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_border_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_date_text_border_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_font
 * DESCRIPTION
 *  set the font of time text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_font        [IN]        New font of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_font(U32 clock_id, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_time_text_font(&g_wgui_clock_list[clock_id], new_font);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_color
 * DESCRIPTION
 *  set the color of time text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_color(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_time_text_color(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_border_color
 * DESCRIPTION
 *  set the border color of time text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New border color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_border_color (U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_time_text_border_color(&g_wgui_clock_list[clock_id], new_color);
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_font_sub_lcd
 * DESCRIPTION
 *  set the font of date text in sub lcd
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_font        [IN]        New font of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_font_sub_lcd(U32 clock_id, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_date_text_font_sub_lcd(&g_wgui_clock_list[clock_id], new_font);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_color_sub_lcd
 * DESCRIPTION
 *  set the color of date text in sub lcd
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_color_sub_lcd(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_date_text_color_sub_lcd(&g_wgui_clock_list[clock_id], new_color);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_date_text_border_color_sub_lcd
 * DESCRIPTION
 *  set the border color of date text in sub lcd
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New border color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_date_text_border_color_sub_lcd(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_date_text_border_color_sub_lcd(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_font_sub_lcd
 * DESCRIPTION
 *  set the font of time text in sub lcd
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_font        [IN]        New font of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_font_sub_lcd(U32 clock_id, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_time_text_font_sub_lcd(&g_wgui_clock_list[clock_id], new_font);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_color_sub_lcd
 * DESCRIPTION
 *  set the color of time text in sub lcd
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_color_sub_lcd(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_time_text_color_sub_lcd(&g_wgui_clock_list[clock_id], new_color);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_time_text_border_color_sub_lcd
 * DESCRIPTION
 *  set the border color of time text in sub lcd
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_color       [IN]        New border color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_time_text_border_color_sub_lcd(U32 clock_id, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_time_text_border_color_sub_lcd(&g_wgui_clock_list[clock_id], new_color);

}
#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_gap_between_two_lines
 * DESCRIPTION
 *  set the gap between time text and date text
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  new_gap         [IN]        New gap between time text and date text
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_gap_between_two_lines(U32 clock_id, S32 new_gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clock_id > WGUI_CLOCK_MAX_ITEMS)
    {
        return;
    }

    gui_clock_set_gap_between_two_lines(&g_wgui_clock_list[clock_id], new_gap);
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_measure_time_text
 * DESCRIPTION
 *  get the width and height of time text
 * PARAMETERS
 *  clock_id            [IN]        
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 *  font                [IN]        Font
 *  clock_type(?)       [IN]        Clock type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_measure_time_text(U32 clock_id, S32 *w, S32 *h, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_clock_measure_time_text(&g_wgui_clock_list[clock_id], w, h,  font);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_measure_date_text
 * DESCRIPTION
 *  get the width and height of date text
 * PARAMETERS
 *  clock_id            [IN]        
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 *  font                [IN]        Font
 *  clock_type(?)       [IN]        Clock type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_measure_date_text(U32 clock_id, S32 *w, S32 *h, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_clock_measure_date_text(&g_wgui_clock_list[clock_id], w, h, font);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clock_set_text_border_enable
 * DESCRIPTION
 *  enable the border text or not
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  enable          [IN]        Enable
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_text_border_enable(U32 clock_id,  MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_clock_set_text_border_enable(&g_wgui_clock_list[clock_id], enable);
}

/*****************************************************************************
 * FUNCTION
 *  gui_clock_close
 * DESCRIPTION
 *  close a clock component
 * PARAMETERS
 *  clock_id        [IN]        Id of clock component
 *  on_idle [IN]        clock on idle or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clock_set_on_idle(U32 clock_id,  MMI_BOOL on_idle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_clock_set_on_idle(&g_wgui_clock_list[clock_id], on_idle);
}



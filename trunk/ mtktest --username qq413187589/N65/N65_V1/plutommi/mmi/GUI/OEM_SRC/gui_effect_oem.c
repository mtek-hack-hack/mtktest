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
 *  gui_effect_oem.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GUI Effect Engine OEM Layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui_categories_defs.h"
#include "gdi_include.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"
#include "gui_effect_oem.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static U32         g_gui_effect_layer_buffer[GUI_EFFECT_LAYER_SIZE / sizeof(U32)];
static gdi_handle  g_gui_effect_layer = GDI_ERROR_HANDLE;
static gdi_handle  g_layer[4];

static gui_effect_struct    gui_slide_effect;
static gui_effect_struct    *g_slide_effect = &gui_slide_effect;

/* default level 1 lies above the background layer */
static S32 g_gui_effect_blt_layer_level = 1;

/* static function prototypes */
static void gui_effect_free_layer(gdi_handle layer);
static void gui_effect_clear_layer(gdi_handle layer);
static void gui_effect_slide_run(void);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_effect_free_layer
 * DESCRIPTION
 *  Free the gui effect layer.
 * PARAMETERS
 *  layer       [IN]    layer handle
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_free_layer(gdi_handle layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (layer > 0)
    {
        gdi_layer_free(layer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_clear_layer
 * DESCRIPTION
 *  Clear the gui effect layer.
 * PARAMETERS
 *  layer       [IN]    layer handle
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_clear_layer(gdi_handle layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer);      
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_slide_run
 * DESCRIPTION
 *  Sliding effect timer callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_effect_slide_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, end_time, timer_run_time;
    S32 next_timer_duration;

    S32 layer_offset_x, layer_offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&start_time);
    
    gui_effect_set_blt_layer();
    gdi_layer_push_and_set_active(g_gui_effect_layer);

    layer_offset_x = g_slide_effect->start_x + (g_slide_effect->end_x - g_slide_effect->start_x) * g_slide_effect->current_frame_index / g_slide_effect->frame_count;
    layer_offset_y = g_slide_effect->start_y + (g_slide_effect->end_y - g_slide_effect->start_y) * g_slide_effect->current_frame_index / g_slide_effect->frame_count;

    gdi_layer_set_position(layer_offset_x, layer_offset_y);

    /* call show function */
    if (g_slide_effect->show_callback)
    {
        g_slide_effect->show_callback(layer_offset_x, layer_offset_y, g_slide_effect->width, g_slide_effect->height);
    }

    /* 
     * hide the old rectangle 
     */    
    /* lock the frame buffer for better performance since hiding old rectangle may introduce many blts */
    gdi_layer_lock_frame_buffer();

    /* The blt rect must include the current rectangle. */    
    gdi_layer_blt_previous(layer_offset_x, layer_offset_y, layer_offset_x + g_slide_effect->width - 1, layer_offset_y + g_slide_effect->height - 1);
    
    if (g_slide_effect->hide_callback)
    {
        g_slide_effect->hide_callback(g_slide_effect->old_x, g_slide_effect->old_y, g_slide_effect->width, g_slide_effect->height);
    }    
    gdi_layer_blt_previous(g_slide_effect->old_x, g_slide_effect->old_y, g_slide_effect->old_x + g_slide_effect->width - 1, g_slide_effect->old_y + g_slide_effect->height - 1);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);

    /* save current position */
    g_slide_effect->old_x = layer_offset_x;
    g_slide_effect->old_y = layer_offset_y;

    gdi_layer_pop_and_restore_active();
    gui_effect_restore_blt_layer();

    kal_get_time(&end_time); 

    g_slide_effect->current_frame_index++;

    if (g_slide_effect->current_frame_index > g_slide_effect->frame_count)
    {                   
        g_slide_effect->state = GUI_EFFECT_STATE_DONE;
    
        if (g_slide_effect->finish_callback)
        {
            g_slide_effect->finish_callback(g_slide_effect->old_x, g_slide_effect->old_y, g_slide_effect->old_x + g_slide_effect->width - 1, g_slide_effect->old_y + g_slide_effect->height - 1);
        }

        return;
    }

    /*
     *  start the timer for the next frame.
     */
    timer_run_time = kal_ticks_to_milli_secs(end_time - start_time);
    next_timer_duration = GUI_EFFECT_TIME_UNIT - timer_run_time;
    if (next_timer_duration <= 0)
    {
        next_timer_duration = 0;
    }

    gui_start_timer(next_timer_duration, gui_effect_slide_run);
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  gui_rect_get_intersection_rect
 * DESCRIPTION
 *  Get the intersection rectangle of two input rectangles.
 * PARAMETERS
 *  rect1             [IN]  rectangle 1
 *  rect2             [IN]  rectangle 2
 *  result_rect       [IN]  intersection rectangle
 * RETURNS
 *  0: Not intersected. 1: Intersected.
 *****************************************************************************/
S32 gui_rect_get_intersection(gui_rect *rect1, gui_rect *rect2, gui_rect *result_rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     start_x, start_y, end_x, end_y;
    S32     ax1, ay1, ax2, ay2;            
    S32     bx1, by1, bx2, by2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GUI_RECT_TO_POINT(*rect1, ax1, ay1, ax2, ay2);
    GUI_RECT_TO_POINT(*rect2, bx1, by1, bx2, by2);
        
    /* Two rects are not overlapped. */
    if ((ax1 > bx2) || (ay1 > by2) || (ax2 < bx1) || (ay2 < by1))
    {
        return 0;
    }

    /* calculate the overlapped rect */
    start_y = GUI_EFFECT_MAX(ay1, by1);
    end_y = GUI_EFFECT_MIN(ay2, by2);
    start_x = GUI_EFFECT_MAX(ax1, bx1);
    end_x = GUI_EFFECT_MIN(ax2, bx2);

    result_rect->x = start_x;
    result_rect->y = start_y;
    result_rect->width = end_x - start_x + 1;
    result_rect->height = end_y - start_y + 1;
 
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_image_with_alpha
 * DESCRIPTION
 *  Draw an image with alpha channels. The underlying layers of the output layer
 *  will be flattened to the output layer first, and then the image is drawed to
 *  the output layer.
 * PARAMETERS
 *  x                  [IN]     x
 *  y                  [IN]     y
 *  out_rect           [IN]     output rect
 *  image              [IN]     image
 *  output_layer       [IN]     output layer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_draw_image_with_alpha(S32 x, S32 y, gui_rect *out_rect, PU8 image, gdi_handle output_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     iw, ih;
    S32     i;
    gdi_handle layer[4];
    gdi_handle old_src_layer;

    S32     x1, y1, x2, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension(image, &iw, &ih);
    gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);

    for (i = 4 - 1; i >= 0; i--)
    {
        if (layer[i] == output_layer)
        {
            layer[i] = GDI_NULL_HANDLE;
            break;
        }

        layer[i] = GDI_NULL_HANDLE;        
    }

    /* the active layer is not found in the blt layers. */
    if (i == -1)
    {
        return;
    }

    gdi_layer_push_and_set_active(output_layer);
    gdi_layer_push_clip();

    GUI_RECT_TO_POINT(*out_rect, x1, y1, x2, y2);

    gdi_layer_set_clip(x1, y1, x2, y2);
    old_src_layer = gdi_image_abm_set_source_layer(output_layer);    
    
    /* only flatten all lower layers to the active layer */
    gdi_layer_flatten_with_clipping(layer[0], layer[1], layer[2], layer[3]);            
    gdi_image_draw(x, y, image);    
    
    gdi_image_abm_set_source_layer(old_src_layer);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_set_blt_layer
 * DESCRIPTION
 *  Insert the effect layer into blt layers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_set_blt_layer(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         i;
    gdi_handle  layer[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* save for later restoration */
    gdi_layer_get_blt_layer(&g_layer[0], &g_layer[1], &g_layer[2], &g_layer[3]);

    gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);

    /* prevent including the effect layer into blt layers twice */
    if ((layer[0] == g_gui_effect_layer) || 
        (layer[1] == g_gui_effect_layer) || 
        (layer[2] == g_gui_effect_layer) || 
        (layer[3] == g_gui_effect_layer))
    {
        return;
    }

    for (i = 4 - 1; i > g_gui_effect_blt_layer_level; i--)
    {
       layer[i] = layer[i - 1];
    }

    layer[i] = g_gui_effect_layer;
    
    gdi_layer_set_blt_layer(layer[0], layer[1], layer[2], layer[3]);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_restore_blt_layer
 * DESCRIPTION
 *  Restore blt layers modified by gui_effect_set_blt_layer().
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_restore_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_set_blt_layer(g_layer[0], g_layer[1], g_layer[2], g_layer[3]);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_create
 * DESCRIPTION
 *  Initialize the gui effect engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_height = GUI_EFFECT_LAYER_SIZE / (UI_device_width * GUI_EFFECT_LAYER_BYTE_PER_PIXEL);

    gui_effect_free_layer(g_gui_effect_layer);
    
    gdi_layer_create_cf_using_outside_memory(
        GUI_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        UI_device_width,
        layer_height,
        &g_gui_effect_layer,
        (U8*)g_gui_effect_layer_buffer,
        GUI_EFFECT_LAYER_SIZE);

    gui_effect_clear_layer(g_gui_effect_layer);

    memset(g_slide_effect, 0, sizeof(gui_effect_struct));
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_close
 * DESCRIPTION
 *  De-initialize the gui effect engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle  l1, l2, l3, l4;
    MMI_BOOL    is_sliding_finished;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw the last frame to the main base layer */
    if (g_slide_effect->is_executed)
    {
        gdi_layer_lock_frame_buffer();        

        /* if the sliding effect is running, go to the last frame. */
        if (g_slide_effect->state == GUI_EFFECT_STATE_RUNNING)
        {
            is_sliding_finished = MMI_FALSE;
            gui_effect_slide_draw_last_frame();        
        }
        else
        {
            is_sliding_finished = MMI_TRUE;
        }

        /* flatten the effect layer to the active layer (main base layer) */
        // TODO: Only needed for small screens.
        gdi_layer_get_blt_layer(&l1, &l2, &l3, &l4);
        gdi_layer_push_clip();
        gdi_layer_set_clip(g_slide_effect->old_x, g_slide_effect->old_y, g_slide_effect->old_x + g_slide_effect->width - 1, g_slide_effect->old_y + g_slide_effect->height - 1);
        gdi_layer_flatten_with_clipping(l1, l2, l3, l4);    
        gdi_layer_pop_clip();
        gdi_layer_unlock_frame_buffer();

        /* blt out the last frame */
        if (is_sliding_finished == MMI_FALSE)
        {
            gdi_layer_blt_previous(0, 0, 0, 0);
        }
    }
 
    gui_effect_slide_close();
    
    g_slide_effect->state = GUI_EFFECT_STATE_READY;
    g_slide_effect->hide_callback = NULL;  
    g_slide_effect->is_executed = 0;

    gui_effect_clear_layer(g_gui_effect_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_register_hide_callback
 * DESCRIPTION
 *  Register the hide callback
 * PARAMETERS
 *  hide_cb       [IN]  hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_register_hide_callback(gui_effect_funcptr_type hide_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slide_effect->hide_callback = hide_cb;
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_slide_create
 * DESCRIPTION
 *  Create the slide effect.
 * PARAMETERS
 *  start_x                 [IN]    start x
 *  start_y                 [IN]    start y
 *  end_x                   [IN]    end x
 *  end_y                   [IN]    end y
 *  width                   [IN]    width
 *  height                  [IN]    height
 *  duration                [IN]    duration in ms
 *  show_cb                 [IN]    show callback function
 *  finish_cb               [IN]    finish callback function
 *  start_frame_index       [IN]    start frame index
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_slide_create(S32 start_x, S32 start_y, S32 end_x, S32 end_y, S32 width, S32 height, S32 duration, gui_effect_funcptr_type show_cb, gui_effect_funcptr_type finish_cb, S32 start_frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slide_effect->is_executed = 1;
    
    g_slide_effect->frame_count = duration / GUI_EFFECT_TIME_UNIT;   
        
    if (start_frame_index == GUI_EFFECT_FRAME_LAST)
    {
        g_slide_effect->current_frame_index = g_slide_effect->frame_count;        
    }
    else
    {
        g_slide_effect->current_frame_index = start_frame_index;
    }

    g_slide_effect->width = width;
    g_slide_effect->height = height;

    g_slide_effect->start_x = start_x;
    g_slide_effect->start_y = start_y;
    
    g_slide_effect->end_x = end_x;
    g_slide_effect->end_y = end_y;

    g_slide_effect->show_callback = show_cb;
    g_slide_effect->finish_callback = finish_cb;

    gdi_layer_lock_frame_buffer();

    if (g_slide_effect->hide_callback &&
        (g_slide_effect->state != GUI_EFFECT_STATE_READY))
    {
        g_slide_effect->hide_callback(g_slide_effect->old_x, g_slide_effect->old_y, g_slide_effect->width, g_slide_effect->height);
    }
     
    gdi_layer_unlock_frame_buffer();

    g_slide_effect->state = GUI_EFFECT_STATE_RUNNING;
    
    g_slide_effect->hide_callback = NULL;

    if (duration == 0)
    {
        g_slide_effect->current_frame_index = 1;
        g_slide_effect->frame_count = 1;
    }

    gui_effect_slide_run();
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_slide_close
 * DESCRIPTION
 *  Close the slide effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_slide_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(gui_effect_slide_run);
    if (g_slide_effect->state == GUI_EFFECT_STATE_RUNNING)
    {
        g_slide_effect->state = GUI_EFFECT_STATE_CANCEL;
    }    
    gui_effect_clear_layer(g_gui_effect_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_effect_slide_draw_last_frame
 * DESCRIPTION
 *  Skip to the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_effect_slide_draw_last_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slide_effect->current_frame_index = g_slide_effect->frame_count;
    gui_effect_slide_run();
}


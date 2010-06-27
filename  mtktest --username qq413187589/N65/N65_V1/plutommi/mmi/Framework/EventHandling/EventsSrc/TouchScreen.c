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
 *   TouchScreen.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Low-level Touch Screen API - interface between driver or PC simulator
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

#include "MMI_features.h"

#ifdef __MMI_TOUCH_PANEL_SHORTCUT__
//#include "touch_panel_shortcut_custom.h"
//Huyanwei del it 
#endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */

/* Save stroke data in filesystem for analysis of recognition rate */
#undef MMI_PEN_SAVE_STROKE_IN_FILE


#define MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(event)   do               \
                {                                                   \
                    if (g_pen_cntx.pre_pen_callback_fp)             \
                    {                                               \
                        g_pen_cntx.pre_pen_callback_fp((U16)event); \
                    }                                               \
                }while(0)

#define MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(event)   do              \
                {                                                   \
                    if (g_pen_cntx.post_pen_callback_fp)            \
                    {                                               \
                        g_pen_cntx.post_pen_callback_fp((U16)event);\
                    }                                               \
                }while(0)


/*****************************************************************************
 * In case that handwriting area is overlapped with an editor, we need to 
 * define a way to move cursor inside the editor.
 *
 * Three approaches are supported:
 *
 * 1. !defined(MMI_PEN_SUPPORT_STROKE_LONGTAP) and single-block --> (MMI_PEN_STROKE_MIN_OFFSET > 0)
 *
 * In the first stroke (after mmi_pen_begin_strokes_of_character()), 
 * stroke down in handwriting area is translated to Pen Down event first until pen is 
 * moved across predefined distance MMI_PEN_STROKE_MIN_OFFSET.
 *
 * For example, driver events are converted to MMI events in the first stroke like:
 *
 * STROKE_DOWN, STROKE_UP --> MMI_PEN_EVENT_DOWN, MMI_PEN_EVENT_UP
 *       (stroke buffer is empty, handwriting area is reset to default)
 *
 * STROKE_DOWN, STROKE_MOVE (< MMI_PEN_STROKE_MIN_OFFSET), STROKE_UP --> 
 *       MMI_PEN_EVENT_DOWN, MMI_PEN_EVENT_UP
 *       (the STROKE_MOVE before STROKE_UP is dropped, 
 *        stroke buffer is empty, handwriting area is reset to default)
 *
 * STROKE_DOWN, STROKE_MOVE (> MMI_PEN_STROKE_MIN_OFFSET), STROKE_UP -->
 *       MMI_PEN_EVENT_DOWN, MMI_PEN_EVENT_ABORT, MMI_PEN_STROKE_DOWN, 
 *                           MMI_PEN_STROKE_MOVE, MMI_PEN_STROKE_UP
 *       (The original Pen Down event is aborted, and the first stroke is created)
 *
 * 2. !defined(MMI_PEN_SUPPORT_STROKE_LONGTAP) and multi-block --> 
 * 
 * Handwriting area and non-handwriting area are not overlapped. This is the simplest case.
 *
 * Unnecessary to translate driver pen events.
 *
 * 3. defined(MMI_PEN_SUPPORT_STROKE_LONGTAP) --> (MMI_PEN_STROKE_MIN_OFFSET == 0)
 *
 * In the first stroke (after mmi_pen_begin_strokes_of_character()), 
 * stroke down are translated to Stroke Down event directly. However, when pen stays at the 
 * pen down position within MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET after MMI_PEN_STROKE_LONGTAP_TIME,
 * Stroke LongTap event is generated. Editor will interpret the subsequent 
 * Stroke Move events as editor cursor control commands.
 *
 * For example, driver events are converted to MMI events in the first stroke like:
 *
 * STROKE_DOWN, STROKE_UP --> MMI_PEN_STROKE_DOWN, MMI_PEN_STROKE_UP
 *       (The first stroke is created, and stroke buffer is not empty.)
 *
 * STROKE_DOWN, STROKE_MOVE, STROKE_UP --> 
 *       MMI_PEN_STROKE_DOWN, MMI_PEN_STROKE_MOVE, MMI_PEN_STROKE_UP
 *       (The first stroke is created, and stroke buffer is not empty.)
 *
 * STROKE_DOWN, STROKE_MOVE (1st), STROKE_LONGTAP, STROKE_MOVE (2nd), STROKE_UP -->
 *       MMI_PEN_STROKE_DOWN, MMI_PEN_STROKE_MOVE (1st), MMI_PEN_STROKE_LONGTAP, 
 *       MMI_PEN_STROKE_MOVE (2nd), MMI_PEN_STROKE_UP
 *       (The first stroke is aborted, handwriting area is reset to default, 
 *        Stroke buffer is cleared.)
 *       (NOTE: after STROKE_LONGTAP, we decrease the sampling rate to MMI_PEN_SAMPLING_PERIOD_1)
 *
 * Note that after the first stroke is created, STROKE_LONGTAP events generated by driver are ignored.
 *
 ****************************************************************************/

#if ( defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)) && !defined(__MTK_TARGET__)

/*****************************************************************************
 *
 * WIN32 integration 
 * PC Simulator & MODIS
 *
 ****************************************************************************/
#include "MMI_features.h"
#include "stdC.h"
#include "l4dr.h"
#include "MMIDataType.h"
#include "TimerEvents.h"
#include "FrameworkGprot.h"        
#include "FrameworkProt.h"  
#include "gui_data_types.h"
#include "gui.h"
#include "IdleAppProt.h"
#include "DebugInitDef.h"
#include "lcd_sw_rnd.h" /* LCD width/height */
#include "time.h"       /* time() */
#include "gdi_include.h"
#include "ScreenRotationGprot.h"
#include "touch_panel_custom.h" /* get handwriting pad setting */


static void mmi_pen_MODIS_start_timer(void);
static void mmi_pen_MODIS_flush_queue(void);

/***************************************************************************** 
* Define
*****************************************************************************/

#define MMI_PEN_MAX_HANDWRITING_REGION (3)

#undef MMI_PEN_UNIT_TEST

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef struct
{
    /* mmi_pen_block() & mmi_pen_unblock() */
    U32 is_blocked:1;

    /* mmi_pen_enable() & mmi_pen_disable() */
    U32 is_enabled:1;

    /* mmi_pen_reset() set 'is_pen_down' to 0 */
    U32 is_pen_down:1;

    /* The current pen down/move/up is a stroke */
    U32 is_stroke_event:1;

    /* Checking offset with g_pen_stroke_min_offset */
    U32 is_pending_stroke_event:1;

    /* A first stroke is created. This flag is cleared in mmi_pen_begin_strokes_of_character() */
    U32 is_stroke_created:1;

    /* Stroke LongTap event is generated. */
    U32 is_stroke_longtap_event_generated:1;

    /* Set in mmi_pen_end_strokes_of_character(), 
       do not enqueue incoming strokes until mmi_pen_begin_strokes_of_character() is invoked again */
    U32 is_all_stroke_finished:1;

    /* wait for 1: pen long-tap 0: pen repeat (event-based) */
    U32 is_waiting_long_tap_event:1;

    /* 
     * Set by mmi_pen_change_handwriting_area() and mmi_pen_stop_capture_strokes().
     * Close stroke and reset touch screen when pen is up. 
     */
    U32 reset_stroke_on_pen_up:1;

    /* The position where pen is tapped down */
    mmi_pen_point_struct pen_down_pos;

    /* Block index of handwriting area */
    S32 stroke_down_block_index;

    /* The current pen position */
    mmi_pen_point_struct pen_current_pos;

    /* For Pen Repeat */
    mmi_pen_point_struct pen_repeat_origin_pos;

    /* For stroke */
    S32 num_points_queued;
    
    /* pre callback function: registered by the application */
    func_ptr_short pre_pen_callback_fp;
    
    /* post callback function: registered by the application */
    func_ptr_short post_pen_callback_fp;
} mmi_pen_context_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

static mmi_pen_context_struct g_pen_cntx;

static mmi_pen_hdlr g_pen_event_table[MMI_PEN_EVENT_TYPE_MAX];
static mmi_pen_hdlr g_pen_stroke_table[MMI_PEN_STROKE_TYPE_MAX];
static void (*g_pen_stroke_pre_move) (void);
static void (*g_pen_stroke_post_move) (void);

static int g_pen_num_stroke_area;   /* 0 if stroke area is not enabled */
static mmi_pen_handwriting_area_struct g_pen_stroke_areas[MMI_PEN_MAX_HANDWRITING_REGION];
static mmi_pen_handwriting_area_struct g_pen_ext_stroke_area;
static int g_pen_stroke_min_offset;
static S32 g_pen_stroke_max_points;
static mmi_pen_point_struct *g_pen_stroke_points;

/***************************************************************************** 
* Local Function
*****************************************************************************/

static void mmi_pen_MODIS_tp_ind(void *);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_fix_point_bound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN/OUT]     
 *  y       [INT/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_fix_point_bound(S16 *x, S16 *y, MMI_BOOL check_multi_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_handwriting_area_struct *block;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*x < 0)
    {
        *x = 0;
    }
    else if (*x >= UI_device_width)
    {
        *x = UI_device_width - 1;
    }
    if (*y < 0)
    {
        *y = 0;
    }
    else if (*y >= UI_device_height)
    {
        *y = UI_device_height - 1;
    }

    if (check_multi_block)
    {
        MMI_ASSERT(g_pen_cntx.stroke_down_block_index >= 0 &&
                   g_pen_cntx.stroke_down_block_index < g_pen_num_stroke_area);

        block = &g_pen_stroke_areas[g_pen_cntx.stroke_down_block_index];
        
        if (*x < block->x1)
        {
            *x = block->x1;
        }
        else if (*x > block->x2)
        {
            *x = block->x2;
        }
        
        if (*y < block->y1)
        {
            *y = block->y1;
        }
        else if (*y > block->y2)
        {
            *y = block->y2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_pixel_diff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos1        [IN]        
 *  pos2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S16 mmi_pen_simulator_pixel_diff(mmi_pen_point_struct pos1, mmi_pen_point_struct pos2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 diff_x = pos1.x - pos2.x;
    S16 diff_y = pos1.y - pos2.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (diff_x < 0)
    {
        diff_x = -diff_x;
    }
    if (diff_y < 0)
    {
        diff_y = -diff_y;
    }
    return diff_x + diff_y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_in_stroke_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  The index of block. 0 for block-0 or extended area, -1 if not found.
 *****************************************************************************/
static S32 mmi_pen_simulator_in_stroke_area(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_stroke_created &&
        (g_pen_ext_stroke_area.x2 >= 0) && /* Test if the extended handwriting area is enabled */
        x >= g_pen_ext_stroke_area.x1 && x <= g_pen_ext_stroke_area.x2 &&
        y >= g_pen_ext_stroke_area.y1 && y <= g_pen_ext_stroke_area.y2)
    {
        return 0;
    }

    for (i = 0; i < g_pen_num_stroke_area; i++)
    {
        if (x >= g_pen_stroke_areas[i].x1 && x <= g_pen_stroke_areas[i].x2 &&
            y >= g_pen_stroke_areas[i].y1 && y <= g_pen_stroke_areas[i].y2)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_push_stroke_point
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_push_stroke_point(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points - 2)
    {
        return;
    }
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = x;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = y;
    g_pen_cntx.num_points_queued++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_push_stroke_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_push_stroke_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points - 1)
    {
        MMI_ASSERT(0);  /* queue full */
        return;
    }
#if defined(__MMI_HANWANG__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
#elif defined(__MMI_PENPOWER__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
#else 
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
#endif 
    g_pen_cntx.num_points_queued++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_push_char_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_push_char_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points)
    {
        MMI_ASSERT(0);  /* queue full */
        return;
    }
#if defined(__MMI_HANWANG__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
#elif defined(__MMI_PENPOWER__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
#else 
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
#endif 
    g_pen_cntx.num_points_queued++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_repeat_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_repeat_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down);

    if (g_pen_cntx.is_waiting_long_tap_event)
    {
        if (g_pen_event_table[MMI_PEN_EVENT_LONG_TAP])
        {
            (g_pen_event_table[MMI_PEN_EVENT_LONG_TAP]) (g_pen_cntx.pen_down_pos);
        }

        g_pen_cntx.is_waiting_long_tap_event = 0;
    }
    else
    {
        if (g_pen_event_table[MMI_PEN_EVENT_REPEAT])
        {
            (g_pen_event_table[MMI_PEN_EVENT_REPEAT]) (g_pen_cntx.pen_repeat_origin_pos);
        }
    }

    /* touch screen might be disabled/reset inside pen handler */
    if (g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down)
    {
        gui_start_timer(MMI_PEN_REPEAT_TIME * 10, mmi_pen_simulator_repeat_hdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_stroke_longtap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_stroke_longtap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down && g_pen_cntx.is_stroke_event);

    g_pen_cntx.is_stroke_longtap_event_generated = 1;

    if (g_pen_stroke_table[MMI_PEN_STROKE_LONGTAP])
    {
        (g_pen_stroke_table[MMI_PEN_STROKE_LONGTAP]) (g_pen_cntx.pen_current_pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_button_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_simulator_button_down_hdlr(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_cntx.is_enabled || g_pen_cntx.is_all_stroke_finished)
    {
        return;
    }

    MMI_DBG_ASSERT(!g_pen_cntx.is_pen_down);

    mmi_pen_simulator_fix_point_bound(&x, &y, MMI_FALSE);
    pos.x = x;
    pos.y = y;
    g_pen_cntx.pen_down_pos = g_pen_cntx.pen_current_pos = g_pen_cntx.pen_repeat_origin_pos = pos;
    g_pen_cntx.is_pen_down = 1;
    g_pen_cntx.is_stroke_event = 0;
    g_pen_cntx.is_pending_stroke_event = 0;
    g_pen_cntx.is_stroke_longtap_event_generated = 0;
    /* Not reset is_stroke_created */
    g_pen_cntx.is_waiting_long_tap_event = 0;

    if ((g_pen_cntx.stroke_down_block_index = mmi_pen_simulator_in_stroke_area(x, y)) >= 0)
    {
        if (!g_pen_cntx.is_stroke_created && g_pen_stroke_min_offset > 0)
        {
            g_pen_cntx.is_pending_stroke_event = 1;

            /* Fire pen down event. For example, it will display key down on virtual keyboard */
            if (g_pen_event_table[MMI_PEN_EVENT_DOWN])
            {
                (g_pen_event_table[MMI_PEN_EVENT_DOWN]) (pos);
            }
        }
        else
        {
            if (!g_pen_cntx.is_stroke_created) /* StrokeLongTap is used in the first stroke only */
            {
                gui_start_timer(MMI_PEN_STROKE_LONGTAP_TIME * 10, mmi_pen_simulator_stroke_longtap_hdlr);
            }
            
            g_pen_cntx.is_stroke_event = 1;
            g_pen_cntx.is_stroke_created = 1;

            if (g_pen_stroke_table[MMI_PEN_STROKE_DOWN])
            {
                (g_pen_stroke_table[MMI_PEN_STROKE_DOWN]) (pos);
            }

            /* Put stroke point after stroke down handler because multi-block handwriting may invoke
             * mmi_pen_begin_strokes_of_character() and mmi_pen_end_strokes_of_character() in 
             * Stroke Down handler.
             */
            if (g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down && g_pen_stroke_max_points > 0)
            {
                mmi_pen_simulator_push_stroke_point(x, y);
            }
        }
    }
    else
    {

        /* Note that Pen Down handler might call mmi_pen_reset() */
        if (g_pen_event_table[MMI_PEN_EVENT_DOWN])
        {
            (g_pen_event_table[MMI_PEN_EVENT_DOWN]) (pos);
        }

        /* touch screen might be disabled inside pen handler */
        if (g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down)
        {
            g_pen_cntx.is_waiting_long_tap_event = 1;
            gui_start_timer(MMI_PEN_REPEAT_TIME * 10, mmi_pen_simulator_repeat_hdlr);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_button_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_simulator_button_move_hdlr(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct pos;
    MMI_BOOL restart_repeat_timer = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_cntx.is_enabled || !g_pen_cntx.is_pen_down)
    {
        return;
    }

    mmi_pen_simulator_fix_point_bound(&x, &y, g_pen_cntx.is_stroke_event && (g_pen_num_stroke_area > 1));
    pos.x = x;
    pos.y = y;
    g_pen_cntx.pen_current_pos = pos;

    if (g_pen_cntx.is_pending_stroke_event)
    {
        if (mmi_pen_simulator_pixel_diff(pos, g_pen_cntx.pen_down_pos) > g_pen_stroke_min_offset)
        {
            g_pen_cntx.is_pending_stroke_event = 0;
            g_pen_cntx.is_stroke_event = 1;
            g_pen_cntx.is_stroke_created = 1;

            /* Abort previous pen down event */
            if (g_pen_event_table[MMI_PEN_EVENT_ABORT])
            {
                MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
                (g_pen_event_table[MMI_PEN_EVENT_ABORT]) (pos);
                MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
            }

            mmi_pen_simulator_push_stroke_point(g_pen_cntx.pen_down_pos.x, g_pen_cntx.pen_down_pos.y);
            mmi_pen_simulator_push_stroke_point(x, y);

            if (g_pen_stroke_table[MMI_PEN_STROKE_DOWN])
            {
                (g_pen_stroke_table[MMI_PEN_STROKE_DOWN]) (g_pen_cntx.pen_down_pos);
            }

            if (g_pen_stroke_pre_move)
            {
                g_pen_stroke_pre_move();
            }

            if (g_pen_stroke_table[MMI_PEN_STROKE_MOVE])
            {
                (g_pen_stroke_table[MMI_PEN_STROKE_MOVE]) (pos);
            }

            if (g_pen_stroke_post_move)
            {
                g_pen_stroke_post_move();
            }

        }
        /* Otherwise, ignore the move event */
    }
    else if (g_pen_cntx.is_stroke_event)
    {
        if (g_pen_stroke_pre_move)
        {
            g_pen_stroke_pre_move();
        }

        if (g_pen_stroke_table[MMI_PEN_STROKE_MOVE])
        {
            (g_pen_stroke_table[MMI_PEN_STROKE_MOVE]) (pos);
        }

        if (g_pen_stroke_post_move)
        {
            g_pen_stroke_post_move();
        }

        mmi_pen_simulator_push_stroke_point(x, y);

        if (mmi_pen_simulator_pixel_diff(pos, g_pen_cntx.pen_down_pos) > MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET)
        {
            gui_cancel_timer(mmi_pen_simulator_stroke_longtap_hdlr);
        }
    }
    else
    {
        if (g_pen_event_table[MMI_PEN_EVENT_MOVE])
        {
            (g_pen_event_table[MMI_PEN_EVENT_MOVE]) (pos);
        }

        if (mmi_pen_simulator_pixel_diff(pos, g_pen_cntx.pen_repeat_origin_pos) > MMI_PEN_SKIP_LONGTAP_OFFSET)
        {
            g_pen_cntx.is_waiting_long_tap_event = 0;   /* Wait Pen Repeat because Pen LongTap only happens at the pen down position */
            g_pen_cntx.pen_repeat_origin_pos = pos;
            gui_cancel_timer(mmi_pen_simulator_repeat_hdlr);
            if (g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down)
            {
                gui_start_timer(MMI_PEN_REPEAT_TIME * 10, mmi_pen_simulator_repeat_hdlr);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_button_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_simulator_button_up_hdlr(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_cntx.is_enabled || !g_pen_cntx.is_pen_down)
    {
        return;
    }

    mmi_pen_simulator_fix_point_bound(&x, &y, g_pen_cntx.is_stroke_event && (g_pen_num_stroke_area > 1));
    pos.x = x;
    pos.y = y;
    g_pen_cntx.pen_current_pos = pos;
    g_pen_cntx.is_pen_down = 0;

    if (g_pen_cntx.is_pending_stroke_event)
    {
        if (g_pen_event_table[MMI_PEN_EVENT_UP])
        {
            (g_pen_event_table[MMI_PEN_EVENT_UP]) (g_pen_cntx.pen_down_pos);
        }
    }
    else if (g_pen_cntx.is_stroke_event)
    {
        if (g_pen_stroke_table[MMI_PEN_STROKE_UP])
        {
            (g_pen_stroke_table[MMI_PEN_STROKE_UP]) (pos);
        }
        mmi_pen_simulator_push_stroke_point(x, y);
        mmi_pen_simulator_push_stroke_end();

        gui_cancel_timer(mmi_pen_simulator_stroke_longtap_hdlr);
        if (g_pen_cntx.is_stroke_longtap_event_generated)
        {
            /* Clear strokes */
            mmi_pen_end_strokes_of_character();
            mmi_pen_begin_strokes_of_character();
        }
    }
    else
    {
        gui_cancel_timer(mmi_pen_simulator_repeat_hdlr);

        if (g_pen_event_table[MMI_PEN_EVENT_UP])
        {
            (g_pen_event_table[MMI_PEN_EVENT_UP]) (pos);
        }
    }

    if (g_pen_cntx.reset_stroke_on_pen_up)
    {
        if (g_pen_stroke_max_points > 0)
        {
            mmi_pen_end_strokes_of_character();
            mmi_pen_reset();
            mmi_pen_begin_strokes_of_character();
        }
        else
        {
            mmi_pen_reset();
        }
    }
}

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* Dummy pen handler */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_dummy_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_dummy_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_sampling_period
 * DESCRIPTION
 *  
 * PARAMETERS
 *  low         [IN]        
 *  high        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_sampling_period(kal_uint32 low, kal_uint32 high)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DUMMY */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_timeout_period
 * DESCRIPTION
 *  
 * PARAMETERS
 *  longtap             [IN]        
 *  repeat              [IN]        
 *  stroke_longtap      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_timeout_period(kal_uint32 longtap, kal_uint32 repeat, kal_uint32 stroke_longtap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DUMMY */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_move_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_based         [IN]        
 *  stroke_based        [IN]        
 *  long_tap            [IN]        
 *  stroke_long_tap     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_move_offset(
        kal_uint32 event_based,
        kal_uint32 stroke_based,
        kal_uint32 long_tap,
        kal_uint32 stroke_long_tap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DUMMY */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_init
 * DESCRIPTION
 *  Initialize pen system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HANDWRITING_PAD__
    mmi_frm_setup_default_pen_handler();
#endif
    g_pen_cntx.pre_pen_callback_fp = NULL;
    g_pen_cntx.post_pen_callback_fp = NULL;
    
    SetProtocolEventHandler(mmi_pen_MODIS_tp_ind, MSG_ID_TP_EVENT_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_block
 * DESCRIPTION
 *  Block pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_disable();
    g_pen_cntx.is_blocked = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_unblock
 * DESCRIPTION
 *  Unblock pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_unblock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_cntx.is_blocked = 0;
    mmi_pen_enable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_enable
 * DESCRIPTION
 *  Enable pen system
 *  
 *  Note: typically on Keypad Up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_blocked || g_pen_cntx.is_enabled)
    {
        return;
    }

    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.is_enabled = 1;


    mmi_pen_MODIS_start_timer();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_disable
 * DESCRIPTION
 *  Disable pen system
 *  
 *  Note: typically on Keypad Down because we don't want to use keypad and touch screen
 *  at the same time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_blocked || !g_pen_cntx.is_enabled)
    {
        return;
    }

    gui_cancel_timer(mmi_pen_simulator_repeat_hdlr);

    if (g_pen_cntx.is_pen_down)
    {
        if (g_pen_event_table[MMI_PEN_EVENT_ABORT])
        {
            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
            (g_pen_event_table[MMI_PEN_EVENT_ABORT]) (g_pen_cntx.pen_current_pos);
            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
        }
    }

    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));

    mmi_pen_MODIS_flush_queue();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_reset
 * DESCRIPTION
 *  Reset the status of touch screen
 *  - Flush event queue
 *  - If the pen is currently tapped down, ignore all subsequent pen events until the pen is up.
 *  
 *  Note: typically on MMI screen switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_blocked || !g_pen_cntx.is_enabled)
    {
        return;
    }

    gui_cancel_timer(mmi_pen_simulator_repeat_hdlr);

    if (g_pen_cntx.is_pen_down)
    {
        gui_cancel_timer(mmi_pen_simulator_repeat_hdlr);

        if (g_pen_event_table[MMI_PEN_EVENT_ABORT])
        {
            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
            (g_pen_event_table[MMI_PEN_EVENT_ABORT]) (g_pen_cntx.pen_current_pos);
            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
        }
    }

    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.is_enabled = 1;

    mmi_pen_MODIS_flush_queue();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_state
 * DESCRIPTION
 *  Get the current state of touch screen.
 * PARAMETERS
 *  is_enabled      [OUT]  Pen is enabled or not.      
 *  is_pen_down     [OUT]  Pen is tapped down or not.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_get_state(kal_bool *is_enabled, kal_bool *is_pen_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_enabled)
    {
        *is_enabled = KAL_TRUE;
        if (g_pen_cntx.is_pen_down)
        {
            *is_pen_down = KAL_TRUE;
        }
        else
        {
            *is_pen_down = KAL_FALSE;
        }
    }
    else
    {
        *is_enabled = KAL_FALSE;
        *is_pen_down = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_calibration
 * DESCRIPTION
 *  Start pen calibration
 * PARAMETERS
 *  num         [IN]        Number of calibration points
 *  points      [IN]        Calibration points
 * RETURNS
 *  void
 * REMARKS
 *  After mmi_pen_reset(), the calibration process is terminated.
 *****************************************************************************/
void mmi_pen_start_calibration(kal_uint16 num, const mmi_pen_point_struct *points)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DUMMY */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_set_calibration_data
 * DESCRIPTION
 *  Assign driver calibration data
 * PARAMETERS
 *  data        [IN] The driver calibration data      
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void mmi_pen_set_calibration_data(const mmi_pen_calibration_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DUMMY */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_read_calibration_data
 * DESCRIPTION
 *  Read the current value of driver calibration data.
 * PARAMETERS
 *  data        [OUT] the current driver calibration data.       
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void mmi_pen_read_calibration_data(mmi_pen_calibration_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DUMMY */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_down_handler
 * DESCRIPTION
 *  Register the Pen Down handler
 * PARAMETERS
 *  pen_fp      [IN]  Callback function for Pen Down event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_DOWN] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_long_tap_handler
 * DESCRIPTION
 *  Register the Pen LongTap handler
 *  
 *  LongTap handler is invoked when  the pen is tapped for a period of time
 *  and stays at the same place where it is tapped down.
 *  
 *  It is invoked atmost one time before pen up.
 * PARAMETERS
 *  pen_fp      [IN]   Callback function for Pen LongTap event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_LONG_TAP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_repeat_handler
 * DESCRIPTION
 *  Register the Pen Repeat handler.
 *  
 *  Repeat handler is invoked after LongTap handler.
 *  However, unlike LongTap handler, Repeat handler is invoked even if
 *  it does not stays at the same place as Pen Down.
 *  
 *  it might be invoked more than one times before pen up.
 * PARAMETERS
 *  pen_fp      [IN]  Callback function for Pen Repeat event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_REPEAT] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_move_handler
 * DESCRIPTION
 *  Register the Pen Move handler.
 *  
 *  The invocation frequency of Pen Move handler is typically less than driver sampling rate.
 * PARAMETERS
 *  pen_fp      [IN]   Callback function for Pen Move event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_MOVE] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_up_handler
 * DESCRIPTION
 *  Register the Pen Up handler.
 * PARAMETERS
 *  pen_fp      [IN]  Callback function for Pen Up event.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_UP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_abort_handler
 * DESCRIPTION
 *  Register the Pen Abort handler.
 * PARAMETERS
 *  pen_fp      [IN]  Callback function for Pen Abort event.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_abort_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_ABORT] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_capture_strokes
 * DESCRIPTION
 *  Win32 port of mmi_pen_start_capture_strokes
 * PARAMETERS
 *  max_points          [IN]        Maximum number of points can be en-queued.
 *  point_array         [IN]        Array for storing sampled points in strokes.
 *  num_regions         [IN]        Number of handwriting regions
 *  region_array        [IN]        Handwriting regions
 *  ext_region          [IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_start_capture_strokes(
        kal_uint32 max_points,
        mmi_pen_point_struct *point_array,
        kal_uint32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Multi-block mode does not have extended region. Otherwise, it cannot switch to another 
       block and multi-block feature is broken. */
    MMI_ASSERT(ext_region == NULL || num_regions == 1);
    
    if (num_regions > MMI_PEN_MAX_HANDWRITING_REGION)
    {
        num_regions = MMI_PEN_MAX_HANDWRITING_REGION;
    }
    
    g_pen_num_stroke_area = num_regions;
    memcpy(g_pen_stroke_areas, region_array, sizeof(mmi_pen_handwriting_area_struct) * num_regions);

    if (ext_region)
    {
        g_pen_ext_stroke_area = *ext_region;
    }
    else
    {
        g_pen_ext_stroke_area.x1 = -1;
        g_pen_ext_stroke_area.x2 = -1;
        g_pen_ext_stroke_area.y1 = -1;
        g_pen_ext_stroke_area.y2 = -1;
    }

    if (num_regions == 1)
    {
        g_pen_stroke_min_offset = MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset = 0;
    }

    g_pen_stroke_max_points = max_points;
    g_pen_stroke_points = point_array;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_change_handwriting_area
 * DESCRIPTION
 *  Win32 port of mmi_pen_change_handwriting_area
 * PARAMETERS
 *  num_regions         [IN]        Number of handwriting regions
 *  region_array        [IN]        Handwriting regions
 *  ext_region          [IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_change_handwriting_area(
        kal_uint32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_stroke_max_points == 0) /* Handwriting is not enabled */
    {
        /* MMI_DBG_ASSERT(0); */
        return;
    }

    /* Multi-block mode does not have extended region */
    MMI_ASSERT(ext_region == NULL || num_regions == 1);
    
    if (num_regions > MMI_PEN_MAX_HANDWRITING_REGION)
    {
        num_regions = MMI_PEN_MAX_HANDWRITING_REGION;
    }

    g_pen_num_stroke_area = num_regions;
    memcpy(g_pen_stroke_areas, region_array, sizeof(mmi_pen_handwriting_area_struct) * num_regions);

    if (ext_region)
    {
        g_pen_ext_stroke_area = *ext_region;
    }
    else
    {
        g_pen_ext_stroke_area.x1 = -1;
        g_pen_ext_stroke_area.x2 = -1;
        g_pen_ext_stroke_area.y1 = -1;
        g_pen_ext_stroke_area.y2 = -1;
    }

    if (num_regions == 1)
    {
        g_pen_stroke_min_offset = MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset = 0;
    }

    /* 
     * We will call mmi_pen_reset() *later* on Pen Up or Stroke Up event.
     *
     * There might be many pending events in driver queue if MMI task is blocked by 
     * other time-consuming jobs. If there are pending stroke events in driver queue, 
     * it is better to flush driver queue.
     *
     */
    if (!g_pen_cntx.is_pen_down)
    {
        /* Clear strokes */
        mmi_pen_end_strokes_of_character();
        mmi_pen_reset();
        mmi_pen_begin_strokes_of_character();
    }
    else
    {
        /* 
         * NOTE: we *cannot* call mmi_pen_reset().
         *
         * For example, assume mmi_pen_change_handwriting_area() is invoked on Button Down.
         * If we invoke mmi_pen_reset() here, it will send MMI_PEN_EVENT_ABORT and reset the button.
         */
        g_pen_cntx.reset_stroke_on_pen_up = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_stop_capture_strokes
 * DESCRIPTION
 *  Stop capturing stroke
 *  
 *  Note: it should be used before mmi_pen_reset() because it does not flush driver pen queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_stop_capture_strokes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_num_stroke_area = 0;
    g_pen_stroke_max_points = 0;
    g_pen_stroke_points = NULL;

    /* 
     * We will call mmi_pen_reset() *later* on Pen Up or Stroke Up event.
     *
     * There might be many pending events in driver queue if MMI task is blocked by 
     * other time-consuming jobs. If there are pending stroke events in driver queue, 
     * it is better to flush driver queue.
     *
     */
    if (!g_pen_cntx.is_pen_down)
    {
        mmi_pen_reset();
    }
    else
    {
        /* 
         * NOTE: we *cannot* call mmi_pen_reset().
         *
         * For example, assume mmi_pen_stop_capture_strokes() is invoked when scrollbar of inline editor 
         * is scrolled on Pen Move event and the highlighed single-line editor is un-highlighted. 
         * If we invoke mmi_pen_reset() here, it will send MMI_PEN_EVENT_ABORT and reset the scrolling of scrollbar.
         */
        g_pen_cntx.reset_stroke_on_pen_up = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_down_handler
 * DESCRIPTION
 *  Register the Stroke Down handler
 * PARAMETERS
 *  pen_fp      [IN]   Callback function for Stroke Down event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_down_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_table[MMI_PEN_STROKE_DOWN] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_move_handler
 * DESCRIPTION
 *  Register the Stroke Move handler
 * PARAMETERS
 *  begin_fp        [IN]        Callback function before multiple Stroke Move events
 *  end_fp          [IN]        Callback function after multiple Stroke Move events
 *  pen_fp          [IN]        Callback function for Stroke Move event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_move_handler(void (*begin_fp) (void), void (*end_fp) (void), mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_pre_move = begin_fp;
    g_pen_stroke_table[MMI_PEN_STROKE_MOVE] = pen_fp;
    g_pen_stroke_post_move = end_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_up_handler
 * DESCRIPTION
 *  Register the Stroke Up handler
 * PARAMETERS
 *  pen_fp      [IN]       Callback function for Stroke Up event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_up_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_table[MMI_PEN_STROKE_UP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_longtap_handler
 * DESCRIPTION
 *  Register the Stroke Longtap handler
 * PARAMETERS
 *  pen_fp      [IN]        Callback function for Stroke Longtap event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_longtap_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_table[MMI_PEN_STROKE_LONGTAP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_peek_stroke_state
 * DESCRIPTION
 *  Check if there is any unfinished strokes.
 * PARAMETERS
 *  has_unfinished_stroke       [OUT]       Whether there are more strokes to come
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_peek_stroke_state(MMI_BOOL *has_unfinished_stroke)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_pen_down && g_pen_cntx.is_stroke_created)
    {
        *has_unfinished_stroke = MMI_TRUE;
    }
    else
    {
        *has_unfinished_stroke = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_begin_strokes_of_character
 * DESCRIPTION
 *  Start to write a new character
 *  
 *  It is typically coupled with mmi_pen_end_strokes_of_character(), which stops en-queueing
 *  strokes inside 'point_array'.
 *  In mmi_pen_begin_strokes_of_character(), MMI continue to en-queue strokes from the head of 'point_array'.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_begin_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(g_pen_num_stroke_area > 0);

    g_pen_cntx.num_points_queued = 0;
    g_pen_cntx.is_stroke_created = 0;
    g_pen_cntx.is_all_stroke_finished = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_end_strokes_of_character
 * DESCRIPTION
 *  End a written character.
 *  
 *  The following procedures are executed
 *  o Reset handwriting area to original size
 *  o Stop en-queueing new strokes inside 'point_array'. (But incoming strokes are still en-queued in driver ring buffer)
 *  o Append end marker (0xffff, 0xffff) in 'point_array'
 *  This API should be used only if there is no unfinished stroke (checked by mmi_pen_peek_stroke_state()).
 *  After it returns, we may pass 'point_array' to handwriting recognition engine.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_end_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_pen_simulator_push_char_end();
    g_pen_cntx.is_all_stroke_finished = 1;  /* To block further Pen Down */

#ifdef MMI_PEN_SAVE_STROKE_IN_FILE
    {
        extern void mmi_pen_save_stroke_in_file(mmi_pen_point_struct *, S32);

        mmi_pen_save_stroke_in_file(g_pen_stroke_points, g_pen_cntx.num_points_queued);
    }
#endif /* MMI_PEN_SAVE_STROKE_IN_FILE */ 
}

/****************************************************************
 * 
 * MODIS support 
 *
 * Because the pen handlers might take a long time to execute, race condition is easy to happen.
 *
 ***************************************************************/

#define MMI_PEN_MODIS_QUEUE_SIZE 1024

typedef struct
{
    S16 type;   /* 0 down, 1 move, 2 up */
    S16 x;
    S16 y;
} mmi_pen_MODIS_queue_item_struct;

static volatile int g_mmi_pen_MODIS_qhead;  /* modified by MMI thread */
static volatile int g_mmi_pen_MODIS_qtail;  /* modified by windows message loop thread */
static mmi_pen_MODIS_queue_item_struct g_mmi_pen_MODIS_queue[MMI_PEN_MODIS_QUEUE_SIZE];

static MMI_BOOL g_mmi_pen_MODIS_timer_flag;

/* By Windows main thread */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_point
 * DESCRIPTION
 *   En-queue the stroke events into g_mmi_pen_MODIS_queue array.
 * PARAMETERS
 *  type        [IN]   stroke event type.     
 *  x           [IN]   x coordinate.     
 *  y           [IN]   y coordinate.      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_MODIS_enqueue_point(S16 type, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int tail = g_mmi_pen_MODIS_qtail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_pen_MODIS_queue[tail].type = type;
    g_mmi_pen_MODIS_queue[tail].x = x;
    g_mmi_pen_MODIS_queue[tail].y = y;
    if (++tail == MMI_PEN_MODIS_QUEUE_SIZE)
    {
        tail = 0;
    }
    g_mmi_pen_MODIS_qtail = tail;
    MMI_ASSERT(tail != g_mmi_pen_MODIS_qhead);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_down
 * DESCRIPTION
 *  En-queue the stroke down events into g_mmi_pen_MODIS_queue array.
 *  Remark: Executed from non-MMI task
 * PARAMETERS
 *  x       [IN]  x coordinate      
 *  y       [IN]  y coordinate      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_down(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_MODIS_enqueue_point(0, x, y);
    
    /* 
     * Because polling timer is aligned timer, and it will be suspended if 
     * the backlight is turned off. We need to send primitive MSG_ID_TP_EVENT_IND
     * to MMI task in order to resume non-aligned timer.
     */
    message.oslMsgId = MSG_ID_TP_EVENT_IND;
    message.oslDataPtr = NULL;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_L4C;
    message.oslDestId = MOD_MMI;
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_move
 * DESCRIPTION
 *  En-queue the stroke move events into g_mmi_pen_MODIS_queue array.
 * PARAMETERS
 *  x       [IN]   x coordinate     
 *  y       [IN]   y coordinate     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_move(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_MODIS_enqueue_point(1, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_up
 * DESCRIPTION
 *  En-queue the stroke up events into g_mmi_pen_MODIS_queue array.
 * PARAMETERS
 *  x       [IN]  x coordinate      
 *  y       [IN]  y coordinate      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_up(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_MODIS_enqueue_point(2, x, y);
}

/* By MMI thread */
#ifdef __MMI_HANDWRITING_PAD__


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_draw_control_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_draw_control_area()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    for (i = 0; i < TP_AREA_MAX_NUM; i++)
    {
        if (IS_ENABLE_FLAG(tp_area_table[i].flag, TP_CONTROL_AREA))
        {
            int index = 0;
            mmi_pen_point_struct pos1, pos2;

            pos1 = tp_area_table[i].pos[index];
            index++;
            while ((tp_area_table[i].pos[index].x != -1) && (tp_area_table[i].pos[index].y != -1))
            {
                pos2 = tp_area_table[i].pos[index];
                gdi_draw_line(pos1.x, pos1.y, pos2.x, pos2.y, GDI_COLOR_RED);
                pos1 = pos2;
                index++;
            }
            pos2 = tp_area_table[i].pos[0];
            gdi_draw_line(pos1.x, pos1.y, pos2.x, pos2.y, GDI_COLOR_RED);

        }
        else
        {
            /* handwriting area */
        }
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}
#endif /* __MMI_HANDWRITING_PAD__ */ 

#ifdef __MMI_TOUCH_PANEL_SHORTCUT__


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_tp_shortcut
 * DESCRIPTION
 *  This function used for check whether is the pen event's location in touch
 *  panel shortcut's region. If the location is in the region, it will call
 *  the related shortcut handler.
 * PARAMETERS
 *  pt          [IN/OUT]        The pen event's location.
 *  event       [IN]            The type of pen event.   
 * RETURNS
 *  Returns MMI_TURE if the shortcut handler processed the pen event,
 *  otherwise returns MMI_FALSE. 
 *****************************************************************************/
static MMI_BOOL mmi_pen_check_tp_shortcut(mmi_pen_MODIS_queue_item_struct* pt, S16 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct pos;
	S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pos.x = pt->x;
	pos.y = pt->y;

    Trace2(TRACE_GROUP_1, "[Pen] (modis) mmi_pen_check_tp_shortcut (%d, %d)", pos.x, pos.y);
    if (mmi_pen_check_inside_polygon((mmi_pen_polygon_area_struct *)&g_tp_shortcut_total_polygon, pos))
    {
        while (count < TP_SHORTCUT_NUMBER)
        {
            if (mmi_pen_check_inside_polygon
                ((mmi_pen_polygon_area_struct*) & (g_tp_shortcut_area_tbl[count].polygon), pos))
            {	
				if (NULL != g_tp_shortcut_area_tbl[count].hdlr)
				{
					switch (event)
                    {
                        case 0: /* down */
                            return g_tp_shortcut_area_tbl[count].hdlr(pos, MMI_PEN_EVENT_DOWN);
                            
                        case 2: /* up */
                            return g_tp_shortcut_area_tbl[count].hdlr(pos, MMI_PEN_EVENT_UP);

                        case 1: /* move */
                            return g_tp_shortcut_area_tbl[count].hdlr(pos, MMI_PEN_EVENT_MOVE);

                        default:
                            return MMI_FALSE;                        
					}
				}
                return MMI_FALSE;
            }
            count++;
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_MODIS_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_MODIS_queue_item_struct *pt, *pt_end;
    int new_head, saved_tail;
    MMI_BOOL has_events = MMI_FALSE;
    static MMI_BOOL entered = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_cntx.is_enabled)
    {
        g_mmi_pen_MODIS_qhead = g_mmi_pen_MODIS_qtail = 0;

        StartTimer(PEN_POLLING_TIMER, 20, mmi_pen_MODIS_timer_hdlr);
        return;
    }

    /* Avoid re-entrance of this function. Typically it's becuase NVRAM routines invoke timer 
       handler again */
    if (entered)
    {
        return;
    }
    entered = MMI_TRUE;

    g_mmi_pen_MODIS_timer_flag = MMI_TRUE;

    saved_tail = g_mmi_pen_MODIS_qtail;
    pt = g_mmi_pen_MODIS_queue + g_mmi_pen_MODIS_qhead;

    if (saved_tail < g_mmi_pen_MODIS_qhead)
    {
        pt_end = g_mmi_pen_MODIS_queue + MMI_PEN_MODIS_QUEUE_SIZE;
        new_head = 0;
    }
    else
    {
        pt_end = g_mmi_pen_MODIS_queue + saved_tail;
        new_head = saved_tail;
    }

    if (pt < pt_end)
    {
        has_events = MMI_TRUE;
    }

    while (pt < pt_end)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
        {
            S32 tmp_x = pt->x, tmp_y = pt->y;

            /* W06.04 Replace functions for GDI LCD Rotate */
            gdi_rotate_map_absolute_hw_to_lcd(&tmp_x, &tmp_y);
            /* gdi_layer_map_rotated_coordinates(gdi_layer_get_base_layer_rotation(), &tmp_x, &tmp_y); */
            pt->x = (S16) tmp_x;
            pt->y = (S16) tmp_y;
        }
    #endif /* __MMI_SCREEN_ROTATE__ */ 

        #ifdef __MMI_TOUCH_PANEL_SHORTCUT__
        if(!mmi_pen_check_tp_shortcut(pt, pt->type))
    #endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */
        {

            switch (pt->type)
            {
                case 0:
                    mmi_pen_simulator_button_down_hdlr(pt->x, pt->y);
                    break;
                case 1:
                    mmi_pen_simulator_button_move_hdlr(pt->x, pt->y);
                    break;
                case 2:
                    mmi_pen_simulator_button_up_hdlr(pt->x, pt->y);
                    break;
                default:
                    ASSERT(0);
            }

        }
        pt++;
        if (!g_mmi_pen_MODIS_timer_flag)
        {
            break;  /* mmi_pen_reset was invoked */
        }
    }

    /* Update queue when no mmi_pen_disable() and mmi_pen_reset() inside previous pen handler */
    if (g_mmi_pen_MODIS_timer_flag)
    {
        g_mmi_pen_MODIS_qhead = new_head;
    }

    g_mmi_pen_MODIS_timer_flag = MMI_FALSE;

    if (has_events)
    {
        mmi_idle_key_event_backlight_check();
    #ifdef __MMI_LCD_PARTIAL_ON__
        /* Switch screen and flush pen events */
        LeavePartialOnScreenSaverIfOk();
    #endif /* __MMI_LCD_PARTIAL_ON__ */ 
    }

#ifdef __MMI_HANDWRITING_PAD__
    mmi_pen_draw_control_area();
#endif 

    StartTimer(PEN_POLLING_TIMER, 20, mmi_pen_MODIS_timer_hdlr);

    entered = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_flush_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_MODIS_flush_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_pen_MODIS_qtail = 0;
    g_mmi_pen_MODIS_qhead = 0;
    g_mmi_pen_MODIS_timer_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_MODIS_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(PEN_POLLING_TIMER, 20, mmi_pen_MODIS_timer_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_tp_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_MODIS_tp_ind(void *param /* unused */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_MODIS_timer_hdlr();
}


/****************************************************************
 * Unit test
 ***************************************************************/

#ifdef MMI_PEN_UNIT_TEST

/*
 * The simple drawing application is not efficent in order 
 * * to follow PC Simualator architecture 
 */

#include "wgui_categories.h"
#include "GlobalDefs.h"
#include "HistoryGprot.h"

static mmi_pen_point_struct mmi_pen_test_last_pos;

static U8 mmi_pen_draw_buffer[LCD_WIDTH * LCD_HEIGHT / 8];


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_clear_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_clear_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_pen_draw_buffer, 0, sizeof(mmi_pen_draw_buffer));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_draw_point
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_draw_point(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x < 0 || x >= LCD_WIDTH || y < 0 || y >= LCD_HEIGHT)
    {
        return;
    }

    offset = y * LCD_WIDTH + x;
    mmi_pen_draw_buffer[offset >> 3] |= (1 << (offset & 0x07));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_draw_from_buffer
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
static void mmi_pen_test_draw_from_buffer(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y;
    S32 offset;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = c.b = 0;
    c.alpha = 255;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    for (y = y1; y <= y2; y++)
    {
        offset = y * LCD_WIDTH;
        for (x = x1; x <= x2; x++)
        {
            if (mmi_pen_draw_buffer[offset >> 3] & (1 << (offset & 0x07)))
            {
                gui_putpixel(x, y, c);
            }
            offset++;
        }
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_refresh_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_refresh_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    mmi_pen_test_draw_from_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_draw_line
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
static void mmi_pen_test_draw_line(S16 x1, S16 y1, S16 x2, S16 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_diff = abs(x2 - x1);
    S16 y_diff = abs(y2 - y1);
    S16 x_incr, y_incr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x1 > x2)
    {
        x_incr = -1;
    }
    else
    {
        x_incr = 1;
    }
    if (y1 > y2)
    {
        y_incr = -1;
    }
    else
    {
        y_incr = 1;
    }

    if (x_diff >= y_diff)
    {
        S16 pr_diff = y_diff << 1;
        S16 pru_diff = pr_diff - (x_diff << 1);
        S16 p = pr_diff - x_diff;

        for (; x_diff >= 0; x_diff--)
        {
            mmi_pen_test_draw_point(x1, y1);
            if (p > 0)
            {
                x1 += x_incr;
                y1 += y_incr;
                p += pru_diff;
            }
            else
            {
                x1 += x_incr;
                p += pr_diff;
            }
        }
    }
    else
    {
        S16 pr_diff = x_diff << 1;
        S16 pru_diff = pr_diff - (y_diff << 1);
        S16 p = pr_diff - y_diff;

        for (; y_diff >= 0; y_diff--)
        {
            mmi_pen_test_draw_point(x1, y1);
            if (p > 0)
            {
                x1 += x_incr;
                y1 += y_incr;
                p += pru_diff;
            }
            else
            {
                y1 += y_incr;
                p += pr_diff;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_draw_rectangle
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
static void mmi_pen_test_draw_rectangle(S16 x1, S16 y1, S16 x2, S16 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_test_draw_line(x1, y1, x1, y2);
    mmi_pen_test_draw_line(x1, y2, x2, y2);
    mmi_pen_test_draw_line(x2, y2, x2, y1);
    mmi_pen_test_draw_line(x2, y1, x1, y1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_draw_filled_rectangle
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
static void mmi_pen_test_draw_filled_rectangle(S16 x1, S16 y1, S16 x2, S16 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (x = x1; x <= x2; x++)
    {
        for (y = y1; y <= y2; y++)
        {
            mmi_pen_test_draw_point(x, y);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_test_last_pos = pos;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_move(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_test_draw_line(mmi_pen_test_last_pos.x, mmi_pen_test_last_pos.y, pos.x, pos.y);
    mmi_pen_test_last_pos = pos;

    mmi_pen_test_refresh_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_up(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_long_tap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_long_tap(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_test_draw_filled_rectangle((S16) (pos.x - 2), (S16) (pos.y - 2), (S16) (pos.x + 2), (S16) (pos.y + 2));
    mmi_pen_test_refresh_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_test_repeat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_test_repeat(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_test_draw_rectangle((S16) (pos.x - 4), (S16) (pos.y - 4), (S16) (pos.x + 4), (S16) (pos.y + 4));
    mmi_pen_test_refresh_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_exit_pen_test_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_exit_pen_test_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_reset();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_redraw_pen_test_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_redraw_pen_test_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    RedrawCategoryFunction();
    mmi_pen_test_draw_from_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_pen_test_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_pen_test_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(0, NULL, mmi_exit_pen_test_screen, NULL);

    ShowCategory66Screen(STR_GLOBAL_UNFINISHED, 0, 0, 0, STR_GLOBAL_BACK, 0, (U8*) L"", 0, NULL);
    RedrawCategoryFunction = mmi_redraw_pen_test_screen;    /* For PC simulator architecture */

    mmi_pen_test_clear_screen();

    mmi_pen_register_down_handler(mmi_pen_test_down);
    mmi_pen_register_move_handler(mmi_pen_test_move);
    mmi_pen_register_up_handler(mmi_pen_test_up);
    mmi_pen_register_long_tap_handler(mmi_pen_test_long_tap);
    mmi_pen_register_repeat_handler(mmi_pen_test_repeat);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_entry_pen_test_screen();
}

#endif /* MMI_PEN_UNIT_TEST */ 

#elif ( !defined(__MMI_TOUCH_SCREEN__) || !defined(__MMI_HANDWRITING_PAD__) ) && !defined(__MTK_TARGET__)

#include "MMIDataType.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_down(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_move(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_up(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#elif ( defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) ) && defined(__MTK_TARGET__)

/*****************************************************************************
 *
 * Target integration 
 *
 ****************************************************************************/

#include "stdC.h"
#include "MMIDataType.h"
#include "TimerEvents.h"
#include "KeyBrd.h"
#include "TaskInit.h"
#include "MMITaskProt.h"
#include "FrameworkStruct.h"
#include "EventsGprot.h"
#include "EventsDcl.h"
#include "EventsDef.h"
#include "gui_data_types.h"
#include "gui.h"

#include "GpioInc.h"
#include "IdleAppProt.h"

#include "TouchScreenGprot.h"
#include "DebugInitDef.h"

#include "Touch_Panel.h"

#include "Drv_Comm.h"   /*  mmi_pen_touch_panel_sendilm() */

#include "gdi_include.h"
#include "ScreenRotationGprot.h"

#include "touch_panel_custom.h" /* get handwriting pad setting */

// TODO: make ext_region as NULL
//add by ljm 2007.9.7 start
#include "IdleAppdef.h"
//extern BOOL If_FlightMode(void);	
//extern BOOL IfUNLockScreen;	
extern BOOL IfAlmScreen;	
extern BOOL g_PopupMsg;	
extern BOOL If_Main_menu;
extern idle_context_struct  g_idle_context;
//add by ljm 2007.9.7 end
/***************************************************************************** 
* Define
*****************************************************************************/
/* Time between Pen Long-tap and Pen Repeat */

#define MMI_PEN_POLLING_PERIOD            (4 * 10)      /* ms */

/* Size of look-ahead buffer */
#define MMI_PEN_LOOKAHEAD_BUFFER_SIZE     (25)

/* 
 * Delayed polling period time. (We allow only 5 Pen Down event per sec) 
 * We restrict the frequency of incoming Pen Down events in MMI framework instead of 
 * driver debounce time because driver debounce time needs to be smaller than sampling period. 
 */
#define MMI_PEN_DEBOUNCE_POLLING_DELAY    (1000 / 5 - MMI_PEN_POLLING_PERIOD)


#define MMI_PENDING_MSG_THRESHOLD         (5)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    /* mmi_pen_block() & mmi_pen_unblock() */
    U32 is_blocked:1;

    /* mmi_pen_enable() & mmi_pen_disable() */
    U32 is_enabled:1;

    /* After PEN_DOWN, mmi_pen_reset() set 'is_pen_down' to 0 */
    U32 is_pen_down:1;

    /* Debug only. After STROKE_DOWN, mmi_pen_reset() set 'is_stroke_down' to 0 */
    U32 is_stroke_down:1;

    /* Pen down in hand-writing area, but we still do not know if it is a stroke */
    U32 is_pending_stroke_event:1;

    /* 
     * Set by mmi_pen_change_handwriting_area() and mmi_pen_stop_capture_strokes().
     * Close stroke and reset touch screen when pen is up. 
     */
    U32 reset_stroke_on_pen_up:1;

    /*
     * Reset sampling rate when pen is reset. 
     * This is used when we change the sampling rate temporarily.
     */
    U32 restore_sampling_rate_on_reset:1;

    /* Pen down position */
    mmi_pen_point_struct pen_down_pos;

    /* The current pen position */
    mmi_pen_point_struct pen_current_pos;

    /* Block index of handwriting area */
    S32 stroke_down_block_index;

    /* For stroke */
    S32 num_points_queued;

    /* Number of events in look-ahead buffer */
    S32 num_lookahead_events;
    
    /* pre callback function: registered by the application */
    func_ptr_short pre_pen_callback_fp;
    
    /* post callback function: registered by the application */
    func_ptr_short post_pen_callback_fp;
} mmi_pen_context_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* Global pen context that is reset in mmi_pen_reset() and mmi_pen_disable() */
static mmi_pen_context_struct g_pen_cntx;

/* Only normal poweron initialize touch screen. Otherwise, touch screen is not initialized */
static kal_bool g_pen_initialized;

/*
 * Whether the timer for mmi_pen_poll_hdlr() is started
 * 
 * 'g_pen_polling_timer_started' is not put inside g_pen_cntx because 
 * 1. We want to restrict the frequency of incoming pen events
 * 2. When polling timer is started, we do not stop it.
 * 3. 'g_pen_polling_timer_started' should not be cleared in mmi_pen_reset() or mmi_pen_disable()
 */
MMI_BOOL g_pen_polling_timer_started;

/* Whether MSG_ID_TP_EVENT_IND is already en-queued in MMI external queue */
/* It is not put inside g_pen_cntx for similar reason like g_pen_polling_timer_started */
U32 g_pen_is_driver_indication_in_queue;

static mmi_pen_hdlr g_pen_event_table[MMI_PEN_EVENT_TYPE_MAX];
static mmi_pen_hdlr g_pen_stroke_table[MMI_PEN_STROKE_TYPE_MAX];
static void (*g_pen_stroke_pre_move) (void);
static void (*g_pen_stroke_post_move) (void);

/* 
 * Stroke buffer 
 */
static S32 g_pen_stroke_max_points;
static mmi_pen_point_struct *g_pen_stroke_points;

/* Used for the new multi-block feature.
   Note: the data can be put into driver, but we do not want to change driver interface 
   because customers may port their driver */
static mmi_pen_handwriting_area_struct g_pen_stroke_areas[HAND_WRITING_AREA_NUM];
static S32 g_pen_num_stroke_area;

/* Minimum square distance (diff_x^2 + diff_y^2)  */
static S16 g_pen_stroke_min_offset_square;

/* 
 * Lookahead buffer  
 */
static TouchPanelEventStruct g_pen_lookahead_buffer[MMI_PEN_LOOKAHEAD_BUFFER_SIZE];

//add by ljm 2007.9.8 start
#include "EmailAppGProt.h"
void mmi_main_app_quit()
{
#ifdef __MMI_EMAIL__//05.11.10 pan add
			if (mmi_email_util_get_stop_cause()==EMAIL_MODULE_ACTIVE_NOW)
			{
				mmi_email_main_quit_to_app();
			}
#endif
#ifdef __MMI_QQ__//05.11.10 pan add
			if (mmi_qq_check_active())
			{
				QQExit2ScrIdle();
			}
#endif
#ifdef __CMS_WAP__//05.11.22 pan add
			//mmi_wap_main_quite_to_app(); 
			//cancel by ljm 2007.9.8
			mmi_mms_main_quite_to_app();
			//CmsProcessIdleEvent();
#endif
#ifdef __POLLEX_WAPMMS__//WAP&MMS
			Pollex_Destroy();
#endif
}

extern void EntryMainMenuFromIdleScreen(void);
extern void mmi_phb_entry_main_menu(void);
extern void EntrySMSMainMenuList(void);
extern void mmi_camera_entry_app_screen(void);
extern void mmi_vdoply_entry_app(void);


void IdleShortcutGotoMainMenu(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	EntryMainMenuFromIdleScreen();
}
void IdleShortcutGotoPhoneBook(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	mmi_phb_entry_main_menu(); 					
}
void IdleShortcutGotoSMS(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	EntrySMSMainMenuList();
}
void IdleShortcutGotoCAMERA(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
#ifndef WIN32
	mmi_camera_entry_app_screen();// add by ljm 2007.9.8
#endif
}
void IdleShortcutGotoPlayer(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	mmi_audply_entry_main();
}
void IdleShortcutGotoMp4Player(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	mmi_vdoply_entry_app();
}
void IdleShortcutGotoPhnSet(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	//EntryScrSettingMenu();//add by ljm 2007.9.8
	EntryShctInMainMenu( );
}
void IdleShortcutGotoFM(void)
{
#ifdef FM_RADIO_ENABLE
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	//EntryScrSettingMenu();//add by ljm 2007.9.8
	mmi_fmrdo_entry_main( );
#endif
}


//ghw add It
void IdleShortcutGotoVideoPlayer(void)
{
	mmi_main_app_quit();//05.11.22 pan add
	mmi_frm_sms_end_key_from_send();//wlf
	DisplayIdleScreen();
	//EntryScrSettingMenu();//add by ljm 2007.9.8
       mmi_vdoply_entry_app();
}

BOOL IdleShortcutDisplayConfirm(void (*f)(void))
{
	if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
	{
		(*f)();
		return TRUE;
	}
	return FALSE;
}


//add by ljm 2007.9.8 end


/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_distance_square
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos1        [IN]        
 *  pos2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S16 mmi_pen_get_distance_square(mmi_pen_point_struct pos1, mmi_pen_point_struct pos2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 diff_x = pos1.x - pos2.x;
    S16 diff_y = pos1.y - pos2.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (diff_x < 0)
    {
        diff_x = -diff_x;
    }
    if (diff_y < 0)
    {
        diff_y = -diff_y;
    }
    return (diff_x * diff_x) + (diff_y * diff_y);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_push_stroke_point
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_push_stroke_point(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points - 2)
    {
        /* Leave the last two slots for (-1, 0) and (-1, -1) */
        return;
    }
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = x;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = y;
    g_pen_cntx.num_points_queued++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_push_stroke_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_push_stroke_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points - 1)
    {
        return;
    }
#if defined(__MMI_HANWANG__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
#elif defined(__MMI_PENPOWER__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
#else 
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
#endif 
    g_pen_cntx.num_points_queued++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_push_char_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_push_char_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points)
    {
        MMI_DBG_ASSERT(0);  /* queue full */
        return;
    }
#if defined(__MMI_HANWANG__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
#elif defined(__MMI_PENPOWER__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
#else 
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
#endif 
    g_pen_cntx.num_points_queued++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookup_handwriting_block
 * DESCRIPTION
 *  Search which handwriting block contains a point (multi-block mode)
 * PARAMETERS
 *  x       [IN]
 *  y       [IN]
 * RETURNS
 *  The index of handwriting block. 0 for block-0 or extended area, -1 if not found.
 *****************************************************************************/
static S32 mmi_pen_lookup_handwriting_block(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_pen_num_stroke_area; i++)
    {
        if (x >= g_pen_stroke_areas[i].x1 && x <= g_pen_stroke_areas[i].x2 &&
            y >= g_pen_stroke_areas[i].y1 && y <= g_pen_stroke_areas[i].y2)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_fix_multi_block_pen_position
 * DESCRIPTION
 *  Restrict stroke position to the current handwriting block
 * PARAMETERS
 *  pos       [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_fix_multi_block_pen_position(mmi_pen_point_struct *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_handwriting_area_struct *block;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_pen_cntx.stroke_down_block_index >= 0 &&
               g_pen_cntx.stroke_down_block_index < g_pen_num_stroke_area);

    block = &g_pen_stroke_areas[g_pen_cntx.stroke_down_block_index];
    
    if (pos->x < block->x1)
    {
        pos->x = block->x1;
    }
    else if (pos->x > block->x2)
    {
        pos->x = block->x2;
    }
    
    if (pos->y < block->y1)
    {
        pos->y = block->y1;
    }
    else if (pos->y > block->y2)
    {
        pos->y = block->y2;
    }    
}


/*
 * Look-ahead buffer of pen events (used in mmi_pen_poll_hdlr())
 *
 * If our MMI is blocked and fails to process incoming pen events fast enough, 
 * it may have unexpected results (e.g. extq full) unless we drop certain pending events.
 */

/* 
 * Fill the data in lookahead buffer. 
 *
 * The sampling rate of pen events (MMI_PEN_SAMPLING_PERIOD_1) is very high,
 * If we find paired Pen Down/Up, it means that MMI is blocked.
 *
 * 1. If there are consecutive Pen Move events, keep the last one.
 * 2. If there are paired "Pen Down ~ Pen Up", drop it.
 *
 * We do not drop stroke events because it is used by handwriting engine.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookahead_buffer_fill_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_lookahead_buffer_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rindex, windex;
    S32 first_down_index, last_up_index;
    TouchPanelEventStruct touch_data;

#ifdef __MMI_SCREEN_ROTATE__
    /* U8 gdi_rotate_value; */
    MMI_BOOL screen_rotated = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
    {
        /* Even if GDI base layer is rotated, we do not translate pen coordinates 
           unless mmi_frm_screen_rotate() is invoked. */
        screen_rotated = MMI_TRUE;
    }
    /* gdi_rotate_value = gdi_layer_get_base_layer_rotation(); */
#endif /* __MMI_SCREEN_ROTATE__ */ 

    for (windex = g_pen_cntx.num_lookahead_events; windex < MMI_PEN_LOOKAHEAD_BUFFER_SIZE; windex++)
    {
        if (!touch_panel_get_event(&touch_data))
        {
            break;
        }

    #ifdef __MMI_SCREEN_ROTATE__
        if (screen_rotated)
        {
            S32 tmp_x = touch_data.x_adc, tmp_y = touch_data.y_adc;

            /* W06.04 Replace functions for GDI LCD Rotate */
            gdi_rotate_map_absolute_hw_to_lcd(&tmp_x, &tmp_y);
            /* gdi_layer_map_rotated_coordinates(gdi_rotate_value, &tmp_x, &tmp_y); */
            touch_data.x_adc = (kal_int16) tmp_x;
            touch_data.y_adc = (kal_int16) tmp_y;
        }
    #endif /* __MMI_SCREEN_ROTATE__ */ 

        g_pen_lookahead_buffer[windex] = touch_data;
    }
    g_pen_cntx.num_lookahead_events = windex;

    if (g_pen_cntx.num_lookahead_events == 0)
    {
        return; /* Exit point */
    }

    /* Remove paired Pen Down/Up */
    first_down_index = -1;
    last_up_index = -1;
    for (rindex = 1 /* not including the first event */ ; rindex < g_pen_cntx.num_lookahead_events; rindex++)
    {
        switch (g_pen_lookahead_buffer[rindex].event)
        {
            case PEN_DOWN:
                if (first_down_index < 0)
                {
                    first_down_index = rindex;
                }
                break;

            case PEN_UP:
                last_up_index = rindex;
                break;

            case PEN_MOVE:
            case PEN_LONGTAP:
            case PEN_REPEAT:
                break;

            default:
                /* Some events can not be dropped */
                first_down_index = -1;
        }
    }

    if (first_down_index > 0 && last_up_index > first_down_index)
    {
        if (last_up_index < g_pen_cntx.num_lookahead_events - 1)
        {
            Trace2(MMI_FW_TRC_G1_FRM, "[Pen] Drop lookahead buffer (%d - %d) \n", first_down_index, last_up_index);
            memmove(
                &g_pen_lookahead_buffer[first_down_index],
                &g_pen_lookahead_buffer[last_up_index + 1],
                sizeof(TouchPanelEventStruct) * (g_pen_cntx.num_lookahead_events - 1 - last_up_index));
        }
        g_pen_cntx.num_lookahead_events -= (last_up_index - first_down_index + 1);
    }

    /* 
     * If there are multiple Pen Move events queued, it means that pen handler can not 
     * process the events fast enough. We should drop Pen Move events before the last one in queue.
     */
    for (windex = 0, rindex = 0; rindex < g_pen_cntx.num_lookahead_events; rindex++)
    {
        if (g_pen_lookahead_buffer[rindex].event == PEN_MOVE &&
            rindex < g_pen_cntx.num_lookahead_events - 1 && g_pen_lookahead_buffer[rindex + 1].event == PEN_MOVE)
        {
            /* Drop this Pen Move event. */
            continue;
        }

        if (windex != rindex)
        {
            g_pen_lookahead_buffer[windex] = g_pen_lookahead_buffer[rindex];
        }
        windex++;
    }
    g_pen_cntx.num_lookahead_events = windex;
}

/* Buffered version of touch_panel_peek_event() */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookahead_buffer_peek_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_data      [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_pen_lookahead_buffer_peek_event(TouchPanelEventStruct *touch_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_cntx.num_lookahead_events)
    {
        mmi_pen_lookahead_buffer_fill_data();
    }
    if (g_pen_cntx.num_lookahead_events)
    {
        *touch_data = g_pen_lookahead_buffer[0];
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/* Buffered version of touch_panel_get_event() */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookahead_buffer_get_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_data      [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_pen_lookahead_buffer_get_event(TouchPanelEventStruct *touch_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_lookahead_buffer_fill_data();

    if (g_pen_cntx.num_lookahead_events > 0)
    {
        *touch_data = g_pen_lookahead_buffer[0];
        g_pen_cntx.num_lookahead_events--;
        for (i = 0; i < g_pen_cntx.num_lookahead_events; i++)
        {
            g_pen_lookahead_buffer[i] = g_pen_lookahead_buffer[i + 1];
        }

        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#ifdef __MMI_TOUCH_PANEL_SHORTCUT__


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_tp_shortcut
 * DESCRIPTION
 *  This function used for check whether is the pen event's location in touch
 *  panel shortcut's region. If the location is in the region, it will call
 *  the related shortcut handler.
 *  If the type of pen event is STROKE_MOVE or STROKE_UP, it will fix the 
 *  location to the nearest LCD boundary.
 * PARAMETERS
 *  pos         [IN/OUT]        The pen event's location.
 *  event       [IN]            The type of pen event.
 * RETURNS
 *  Returns MMI_TURE if the shortcut handler processed the pen event,
 *  otherwise returns MMI_FALSE. 
 *****************************************************************************/
static MMI_BOOL mmi_pen_check_tp_shortcut(mmi_pen_point_struct *pos, Touch_Panel_Event_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0; 

#if 0
//Huyanwei Modify It
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut (%d, %d), event:%d", pos->x, pos->y, event);
    if (mmi_pen_check_inside_polygon((mmi_pen_polygon_area_struct*)(&g_tp_shortcut_total_polygon), *pos))
    {
        Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut <in touch panel shortcut area (%d)>", TP_SHORTCUT_NUMBER);
        if ((STROKE_MOVE == event)||(STROKE_UP == event))
        {
            pos->y = LCD_HEIGHT - 1;
        }
        else
        {
            while (count < TP_SHORTCUT_NUMBER)
            {
            	Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut <search index %d>", count);
                if (mmi_pen_check_inside_polygon
                    ((mmi_pen_polygon_area_struct*) (&(g_tp_shortcut_area_tbl[count].polygon)), *pos))
                {
                    switch (event)
                    {
                        case PEN_DOWN:
                            Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut index:%d down", count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_DOWN);
                            
                        case PEN_UP:
                            Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut index:%d up", count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_UP);

                        case PEN_MOVE:
                            Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut index:%d move", count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_MOVE);
                            
                        case PEN_LONGTAP:
                            Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut index:%d longtap", count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_LONG_TAP);
                            
                        case PEN_REPEAT:
                            Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut index:%d repeat", count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_REPEAT);

                        case PEN_ABORT:
                            Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut index:%d abort", count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_ABORT);

                        default:
                            Trace2(TRACE_GROUP_1, "[Pen] mmi_pen_check_tp_shortcut index:%d default", count);
                            return MMI_FALSE;                        
                    }
                }
                count++;
            }
        }
    }
    return MMI_FALSE;    
#else
	if( (pos->x >=  0  ) && (pos->x <= 239  ) &&  (pos->y >= 325 ) &&  (pos->y <= 350 ) )
	{
		return MMI_FALSE ;		
	}
	else
	{
		return MMI_TRUE;
	}

#endif
}
#endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */ 

/*
 * Core polling loop for pen events
 */

#if 1

//Huyanwei Add it  For Touch Panel Shotcut

//#include "CallhistoryEnum.h"
#include "CallsResDef.h"
#include "IdleAppDef.h"
extern idle_context_struct g_idle_context ;

static void Function1(void)
{
	#if 0
	   if((check_sim_card_status()==NORMAL_SIM_PRESENCE) && (mmi_bootup_get_active_flight_mode()==0) &&(g_idle_context.IsOnIdleScreen) ) 
   	#else
	if ( SCR8055_CALLS_LIST_DIALED != GetActiveScreenId() )
	#endif
        {
        	CHISTGetCallLogBySENDKey();
	}
   
}

//#include "VdoPlyScrEnum.h"
#include "VdoPlyResDef.h"
static void Function2(void)
{
	#if 0
	if((g_idle_context.IsOnIdleScreen) || ( (check_sim_card_status()==SIM_CARD_NOT_INSERTED)&&((GetActiveScreenId()==SCR_SIM_INSERTION)||(GetActiveScreenId()==SCR_SIM_BLOCK))  ) ) //P_6226_M17_bw_0005 重新修改对IDLESCREEN的判断
	#else
	if( GetActiveScreenId()  != SCR_ID_VDOPLY_APP ) 
	#endif
	{
		mmi_vdoply_entry_app();
	}
}


//#include "MessagesResourceData.h"
#include "MessagesResourceData.h"
static void Function3(void)
{
#if 0
	//Huyanwei Modify It
      if((check_sim_card_status()==NORMAL_SIM_PRESENCE) && (mmi_bootup_get_active_flight_mode()==0) &&(g_idle_context.IsOnIdleScreen)) 
#else
      if( GetActiveScreenId() != SCR_ID_MSG_MAIN_MENU)  		
#endif
	{
		EntryScrMessagesMenuList();
	}
}

#include "SimDetectionResDef.h"
#include "sim_common_enums.h"
static void Function4(void) 
{
        if((g_idle_context.IsOnIdleScreen)  )//P_6226_M17_bw_0005 重新修改对IDLESCREEN的判断
	   mmi_audply_entry_main();
}


#include "IdleAppResDef.h"
static void Function5(void)
{
      if(g_idle_context.IsOnIdleScreen)
      {
         if((mmi_bootup_get_active_flight_mode()==0) ) 
         {

	#ifdef __MMI_VAS__  //P_6226_M17_bw_0003 新屏没有增值服务时，把最后一个丝印的功能暂时去掉
	           ValueAddedServiceHiliteHandler_Ext();/*P_6226_M11_bw_Z0008 调整VAS菜单hilight时的操作, 在hilight时不初始化必要变量. 改在进入功能时初始化. 这样可以加快在菜单浏览的速度. */
	#endif
         }
      }
      else
      {
      	if((GetActiveScreenId()!=IDLE_SCREEN_ID) && (GetActiveScreenId()!=SCR_SIM_INSERTION)&&(GetActiveScreenId()!=SCR_SIM_BLOCK)  ) //P_6226_M17_bw_0005 重新修改对IDLESCREEN的判断
      	   ExecuteCurrKeyHandler(KEY_END,KEY_EVENT_DOWN);
      }	       

}


extern void mmi_phb_entry_main_menu(void);

#include "PhoneBookResDef.h"

static void Function6(void)
{
#if 0
      if((check_sim_card_status()==NORMAL_SIM_PRESENCE) && (mmi_bootup_get_active_flight_mode()==0) &&(g_idle_context.IsOnIdleScreen) ) 
     {
     	//mmi_phb_idle_enter_phb_list();
	mmi_phb_entry_main_menu();
     }		
   	//    mmi_phb_quick_search_list_pre_entry();
#else
	if( GetActiveScreenId() != SCR_PBOOK_MAIN_MENU )
	{
		mmi_phb_entry_main_menu();
	}
#endif
}

extern void HandleIdleScreenDigitEntry();
extern void EntryIdleScreen();

static void Function7(void)
{
	if(IDLE_SCREEN_DIGIT_HANDLER_ID  != GetActiveScreenId()  )
	     HandleIdleScreenDigitEntry();
}

static void Function8(void)
{
	if(IDLE_SCREEN_ID != GetActiveScreenId() )
		    EntryIdleScreen();
}


#include "MainMenuDef.h"
#include "SimDetectionDef.h"

static void Function9(void)
{
	//if( (MAIN_MENU_SCREENID != GetActiveScreenId() ) && ( SCR_SIM_OPTION  != GetActiveScreenId()) )
	{
	    EntryMainMenuFromIdleScreen();
	}
}

extern void mmi_camera_entry_app_screen(void) ;

static void Function10(void)
{
	mmi_camera_entry_app_screen();
}

extern void mmi_phb_idle_enter_phb_list(void);

static void Function11(void)
{
      if(g_idle_context.IsOnIdleScreen)
      {
         if((mmi_bootup_get_active_flight_mode()==0) ) 
         {

	#ifdef __MMI_VAS__  //P_6226_M17_bw_0003 新屏没有增值服务时，把最后一个丝印的功能暂时去掉
	           ValueAddedServiceHiliteHandler_Ext();/*P_6226_M11_bw_Z0008 调整VAS菜单hilight时的操作, 在hilight时不初始化必要变量. 改在进入功能时初始化. 这样可以加快在菜单浏览的速度. */
	#endif
         }
      }
      else
      {
      	if((GetActiveScreenId()!=IDLE_SCREEN_ID) && (GetActiveScreenId()!=SCR_SIM_INSERTION)&&(GetActiveScreenId()!=SCR_SIM_BLOCK)  ) //P_6226_M17_bw_0005 重新修改对IDLESCREEN的判断
      	   ExecuteCurrKeyHandler(KEY_END,KEY_EVENT_DOWN);
      }	   
}

static void Function12(void)
{
      if((mmi_bootup_get_active_flight_mode()==0) &&(g_idle_context.IsOnIdleScreen)) 
	EntryScrMessagesMenuList();
}

static void Function13(void)
{
	if((g_idle_context.IsOnIdleScreen) || ( ((GetActiveScreenId()==SCR_SIM_INSERTION)||(GetActiveScreenId()==SCR_SIM_BLOCK))  ) ) //P_6226_M17_bw_0005 重新修改对IDLESCREEN的判断
	   mmi_phb_idle_enter_phb_list();
}

static void Function14(void)
{
   if((mmi_bootup_get_active_flight_mode()==0) &&(g_idle_context.IsOnIdleScreen) ) 
           CHISTGetCallLogBySENDKey();
   
}
 extern void mmi_audply_check_fmr_state_idle(void);

static void Function15(void) 
{
        if((g_idle_context.IsOnIdleScreen) || ( ((GetActiveScreenId()==SCR_SIM_INSERTION)||(GetActiveScreenId()==SCR_SIM_BLOCK))  ) )//P_6226_M17_bw_0005 重新修改对IDLESCREEN的判断
	    mmi_audply_check_fmr_state_idle();
          //mmi_audply_entry_main();
}

extern void mmi_entry_analog_tv(void) ;

static void Function16(void)
{
	#if 0 //defined(ANALOG_TV_SUPPORT)
	mmi_entry_analog_tv() ;
	#else
	if( GetActiveScreenId()  != SCR_ID_VDOPLY_APP ) 
	{
		mmi_vdoply_entry_app();
	}
	#endif
}


#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_poll_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_poll_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanelEventStruct data;
    MMI_BOOL is_stroke_move = MMI_FALSE;
    MMI_BOOL has_incoming_event = MMI_FALSE;
    MMI_BOOL delay_polling_timer = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_polling_timer_started = MMI_FALSE;

    Trace2(
        MMI_FW_TRC_G1_FRM,
        "[Pen] mmi_pen_poll_hdlr() - %d %d \n",
        (int)g_pen_cntx.is_enabled,
        (int)g_pen_cntx.num_lookahead_events);

    if (!g_pen_cntx.is_enabled)
    {
        /* Note: We do not stop polling timer even in mmi_pen_disable() */
        return;
    }

    while (!delay_polling_timer && mmi_pen_lookahead_buffer_get_event(&data))
    {
        mmi_pen_point_struct pos;

        if (!g_pen_cntx.is_enabled)
        {
            /* Previous pen handlers might call mmi_pen_disable(), but
               we should already flush driver pen queue on mmi_pen_disable() */
           MMI_DBG_ASSERT(0);
            break;
        }

        /* Although pen events (move, repeat) should keep backlight on, 
           Playing i-melody may turn on/off backlight actively. 
           We do not call mmi_pen_reset() when pen is down because some apps 
           may not handle Pen Abort event. */
        if (!IsBacklightOn() && !g_pen_cntx.is_pen_down)
        {
            Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_poll_hdlr() - no backlight\n");

            mmi_idle_key_event_backlight_check();
            /* only allow pen action when backlight is controlled by AP */
            if (mmi_gpio_get_backlight_timer_state() != MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER)
            {	
                mmi_pen_reset();    /* flush queue */
                return;
            }
        }

        pos.x = (S16) data.x_adc;
        pos.y = (S16) data.y_adc;
	
   #if 0
	//add by ljm 2007.9.4 start
	if(pos.y >= UI_device_height&&(!isInCall()))
	{
		if(/*(!IfUNLockScreen)&&*/(!mmi_bootup_get_active_flight_mode())&&(!IfAlmScreen)&&(!g_PopupMsg)&&(g_idle_context.IsOnIdleScreen != 0)||(If_Main_menu == TRUE))	//hezhe add 2005-10-27
		{
		
				if(data.event == PEN_DOWN)
				{
#if 0//#if(UI_DOUBLE_BUFFER_SUPPORT)

				gui_lock_double_buffer();
#endif	
					if(pos.x <= (UI_device_width/5))//主菜单
					{
								//if(IdleShortcutDisplayConfirm(IdleShortcutGotoMainMenu))
						if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
						{
							IdleShortcutGotoMainMenu( );
						}
					}
					else if(pos.x <= (UI_device_width/5*2))//通讯录
					{
						//if(IdleShortcutDisplayConfirm(IdleShortcutGotoSMS))								
						if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
						{
						IdleShortcutGotoPhoneBook( );
						}
					}
					else if(pos.x <= (UI_device_width/5*3))	//短消息
					{

						//if(IdleShortcutDisplayConfirm(IdleShortcutGotoPlayer))	
						if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
						{
						IdleShortcutGotoSMS( );
						}
					}
					else if(pos.x <= (UI_device_width/5*4))	//摄像头
					{
								//if(IdleShortcutDisplayConfirm(IdleShortcutGotoMp4Player))
						if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
						{
							IdleShortcutGotoCAMERA( );
						}
					}else
					{
								//if(IdleShortcutDisplayConfirm(IdleShortcutGotoFM))
						if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
						{
		//				IdleShortcutGotoFM( );
                                        IdleShortcutGotoVideoPlayer(); //ghw
						}
					
				      }
#if 0//#if(UI_DOUBLE_BUFFER_SUPPORT)
			gui_unlock_double_buffer();
			gui_BLT_double_buffer( 0, 0, UI_device_width-1, UI_device_height-1);
#endif		
	              break;
			}
		
		}
      }
//add by ljm 2007.9.4 end

    #endif /* 0 */ 
        has_incoming_event = MMI_TRUE;

#if 0
     //Huyanwei Modify It
    #ifdef __MMI_TOUCH_PANEL_SHORTCUT__
        if(!mmi_pen_check_tp_shortcut(&pos, data.event))
    #endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */
#endif	
        {


            if (is_stroke_move && (data.event != STROKE_MOVE))
            {
                is_stroke_move = MMI_FALSE;
                if (g_pen_stroke_post_move)
                {
                    g_pen_stroke_post_move();
                }
            }
    
            g_pen_cntx.pen_current_pos = pos;
    
            switch (data.event)
            {
                    /* Call pen handler after setting context variables because pen handler might invoke mmi_pen_reset() */
                case PEN_DOWN:
                    MMI_DBG_ASSERT(!g_pen_cntx.is_pen_down);
                    g_pen_cntx.is_pen_down = 1;
                    g_pen_cntx.pen_down_pos = pos;

#if 0
//Huyanwei Add It 

		if((g_keylock_context.gKeyPadLockFlag == 0) && (pos.y >= 325) && (pos.y <= 350) )
		{
			//Huyanwei Touch Here
			{
				if( (pos.x >= 15) && (pos.x <= 45) )
				{
					if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
					{
						mmi_main_app_quit();//05.11.22 pan add
						mmi_frm_sms_end_key_from_send();//wlf
						DisplayIdleScreen();
						//Function1();
						//Function8();
						Function9();
					}
				}
				else if( (pos.x >= 60) && (pos.x <= 90) )
				{
					if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
					{
				
						mmi_main_app_quit();//05.11.22 pan add
						mmi_frm_sms_end_key_from_send();//wlf
						DisplayIdleScreen();
						//Function2();
						//Function6();
						Function3();	
					}
				}
				else if( (pos.x >= 105 ) && (pos.x <= 135) )
				{
					if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
					{				
						mmi_main_app_quit();//05.11.22 pan add
						mmi_frm_sms_end_key_from_send();//wlf
						DisplayIdleScreen();
						Function6();
					}
				}
				else if( (pos.x >= 150 ) && (pos.x <= 180 ) )
				{
					if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
					{
						mmi_main_app_quit();//05.11.22 pan add
						mmi_frm_sms_end_key_from_send();//wlf
						DisplayIdleScreen();
						//Function4();
						//Function7();
						Function14();
					}
				}
				else if( (pos.x >= 195) && (pos.x <= 225) )
				{
					if((g_idle_context.IsOnIdleScreen == 1)||(If_Main_menu == TRUE))
					{
						mmi_main_app_quit();//05.11.22 pan add
						mmi_frm_sms_end_key_from_send();//wlf
						DisplayIdleScreen();
						//Function5();
						//Function4();
						Function15();
					}
				}
						
			}
				
		}
		else					
#endif
		{
	                    if (g_pen_event_table[MMI_PEN_EVENT_DOWN])
	                    {
	                        MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_DOWN);
	                        (g_pen_event_table[MMI_PEN_EVENT_DOWN]) (pos);
	                        MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_DOWN);
	                    }
		}
                    break;
                    
                case PEN_UP:
                    MMI_DBG_ASSERT(g_pen_cntx.is_pen_down);
                    g_pen_cntx.is_pen_down = 0;
                    if (g_pen_event_table[MMI_PEN_EVENT_UP])
                    {
                        MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_UP);
                        (g_pen_event_table[MMI_PEN_EVENT_UP]) (pos);
                        MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_UP);
                    }
    
                    if (g_pen_cntx.reset_stroke_on_pen_up)
                    {
                        if (g_pen_stroke_max_points > 0)
                        {
                            mmi_pen_end_strokes_of_character();
                            mmi_pen_reset();
                            mmi_pen_begin_strokes_of_character();
                        }
                        else
                        {
                            mmi_pen_reset();
                        }
                    }
    
                    /* Delay processing futher events */
                    delay_polling_timer = MMI_TRUE;
    
                    break;
                    
                case PEN_MOVE:
                    MMI_DBG_ASSERT(g_pen_cntx.is_pen_down);
                    if (g_pen_event_table[MMI_PEN_EVENT_MOVE])
                    {
                        MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_MOVE);
                        (g_pen_event_table[MMI_PEN_EVENT_MOVE]) (pos);
                        MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_MOVE);
                    }
                    break;
                    
                case PEN_LONGTAP:
                    MMI_DBG_ASSERT(g_pen_cntx.is_pen_down);
                    if (g_pen_event_table[MMI_PEN_EVENT_LONG_TAP])
                    {
                        MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_LONG_TAP);
                        (g_pen_event_table[MMI_PEN_EVENT_LONG_TAP]) (pos);
                        MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_LONG_TAP);
                    }
                    break;
                    
                case PEN_REPEAT:
                    MMI_DBG_ASSERT(g_pen_cntx.is_pen_down);
                    if (g_pen_event_table[MMI_PEN_EVENT_REPEAT])
                    {
                        MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_REPEAT);
                        (g_pen_event_table[MMI_PEN_EVENT_REPEAT]) (pos);
                        MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_REPEAT);
                    }
                    break;
                    
                case PEN_ABORT:
                    /* Driver queue full */
                    mmi_pen_reset();
                    break;
                    
                case TP_UNKNOWN_EVENT:
                    MMI_ASSERT(0);
                    break;
                    
                case STROKE_MOVE:
                    MMI_DBG_ASSERT(g_pen_cntx.is_stroke_down && g_pen_cntx.is_pen_down);
                    /* mmi_pen_reset() should be used after mmi_pen_stop_capture_strokes() such that enqueued stroke events are flushed. */
                    MMI_DBG_ASSERT(g_pen_stroke_max_points > 0);
                    if (g_pen_cntx.is_pending_stroke_event)
                    {
                        if (mmi_pen_get_distance_square(g_pen_cntx.pen_down_pos, pos) > g_pen_stroke_min_offset_square)
                        {
                            g_pen_cntx.is_pending_stroke_event = 0;
                            g_pen_stroke_min_offset_square = 0; /* The next stroke does not have minimum offset */
                            /* Pen Down -> Pen Move -> Pen Abort -> Stroke Down -> Stroke Move -> Stroke Up 
                               There is no stroke points queued before the first stroke is created
                               If we set 'reset_stroke_on_pen_up' in previous Pen Down handler and invoke mmi_pen_reset() in Stroke Up, 
                               all stroke points in between are discarded */
                            g_pen_cntx.reset_stroke_on_pen_up = 0;
    
                            /* Abort previous Pen Down event */
                            if (g_pen_event_table[MMI_PEN_EVENT_ABORT])
                            {
                                MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
                                (g_pen_event_table[MMI_PEN_EVENT_ABORT]) (g_pen_cntx.pen_down_pos);
                                MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
                            }
    
                            /* Handle Stroke Down */
                            mmi_pen_push_stroke_point(g_pen_cntx.pen_down_pos.x, g_pen_cntx.pen_down_pos.y);
                            if (g_pen_stroke_table[MMI_PEN_STROKE_DOWN])
                            {
                                MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_STROKE_DOWN);
                                (g_pen_stroke_table[MMI_PEN_STROKE_DOWN]) (g_pen_cntx.pen_down_pos);
                                MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_STROKE_DOWN);
                            }
    
                            /* Pre-Stroke-Move */
                            MMI_DBG_ASSERT(!is_stroke_move);
                            is_stroke_move = MMI_TRUE;
                            if (g_pen_stroke_pre_move)
                            {
                                g_pen_stroke_pre_move();
                            }
    
                            /* Stroke Move */
                            mmi_pen_push_stroke_point(pos.x, pos.y);
                            if (g_pen_stroke_table[MMI_PEN_STROKE_MOVE])
                            {
                                MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_STROKE_MOVE);
                                (g_pen_stroke_table[MMI_PEN_STROKE_MOVE]) (pos);
                                MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_STROKE_MOVE);
                            }
                        }
                    }
                    else
                    {
                        if (g_pen_num_stroke_area > 1)
                        {
                            mmi_pen_fix_multi_block_pen_position(&pos);
                        }
                        
                        if (!is_stroke_move)
                        {
                            is_stroke_move = MMI_TRUE;
                            if (g_pen_stroke_pre_move)
                            {
                                g_pen_stroke_pre_move();
                            }
                        }
    
                        mmi_pen_push_stroke_point(pos.x, pos.y);
                        if (g_pen_stroke_table[MMI_PEN_STROKE_MOVE])
                        {
                            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_STROKE_MOVE);
                            (g_pen_stroke_table[MMI_PEN_STROKE_MOVE]) (pos);
                            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_STROKE_MOVE);
                        }
                    }
                    break;
                    
                case STROKE_DOWN:
                    MMI_DBG_ASSERT(!g_pen_cntx.is_stroke_down && !g_pen_cntx.is_pen_down);
                    /* mmi_pen_reset() should be used after mmi_pen_stop_capture_strokes() such that enqueued stroke events are flushed. */
                    MMI_DBG_ASSERT(g_pen_stroke_max_points > 0);
                    g_pen_cntx.is_stroke_down = 1;
                    g_pen_cntx.is_pen_down = 1;
                    g_pen_cntx.pen_down_pos = pos;
    
                    g_pen_cntx.stroke_down_block_index = mmi_pen_lookup_handwriting_block(pos.x, pos.y);
                    if (g_pen_num_stroke_area > 1 && g_pen_cntx.stroke_down_block_index < 0)
                    {
                        /* MMI framework and driver have intergration problem.
                           Maybe the current driver does not support multi-block, 
                           or driver does not disable extended handwriting area properly in
                           multi-block mode. */
                        MMI_ASSERT(0);
                    }
    
                    if (g_pen_stroke_min_offset_square > 0)
                    {
                        g_pen_cntx.is_pending_stroke_event = 1;
    
                        /* Fire pen down event. For example, it will display key down on virtual keyboard. */
                        if (g_pen_event_table[MMI_PEN_EVENT_DOWN])
                        {
                            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_DOWN);
                            (g_pen_event_table[MMI_PEN_EVENT_DOWN]) (g_pen_cntx.pen_down_pos);
                            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_DOWN);
                        }
                    }
                    else
                    {
                        g_pen_cntx.is_pending_stroke_event = 0;
    
                        if (g_pen_stroke_table[MMI_PEN_STROKE_DOWN])
                        {
                            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_STROKE_DOWN);
                            (g_pen_stroke_table[MMI_PEN_STROKE_DOWN]) (pos);
                            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_STROKE_DOWN);
                        }
                        
                        /* Put stroke point after stroke down handler because multi-block handwriting may invoke
                         * mmi_pen_begin_strokes_of_character() and mmi_pen_end_strokes_of_character() in 
                         * Stroke Down handler.
                         */
                        if (g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down && g_pen_stroke_max_points > 0)
                        {
                            mmi_pen_push_stroke_point(pos.x, pos.y);
                        }                    
                    }
                    break;
                    
                case STROKE_UP:
                    MMI_DBG_ASSERT(g_pen_cntx.is_stroke_down && g_pen_cntx.is_pen_down);
                    /* mmi_pen_reset() should be used after mmi_pen_stop_capture_strokes() such that enqueued stroke events are flushed. */
                    MMI_DBG_ASSERT(g_pen_stroke_max_points > 0);
                    g_pen_cntx.is_stroke_down = 0;
                    g_pen_cntx.is_pen_down = 0;
    
                    if (g_pen_cntx.is_pending_stroke_event)
                    {
                        g_pen_cntx.is_pending_stroke_event = 0;
    
                        /*
                         * Flush driver queue and lookahead buffer:
                         * Otherwise, it might restore handwriting area (touch_panel_reset_handwriting)
                         * while stroke-based mode is already entered.
                         */
                        g_pen_cntx.reset_stroke_on_pen_up = 1;
    
                        /* Note: if pen up handler invokes mmi_pen_reset(), g_pen_cntx.reset_stroke_on_pen_up is cleared */
                        if (g_pen_event_table[MMI_PEN_EVENT_UP])
                        {
                            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_UP);
                            (g_pen_event_table[MMI_PEN_EVENT_UP]) (g_pen_cntx.pen_down_pos);
                            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_UP);
                        }
    
                        /* Delay processing further events */
                        delay_polling_timer = MMI_TRUE;
                    }
                    else
                    {
                        /* 
                         * Because touch panel can not detect pen position in Stroke Up event,
                         * we do not put the point into stroke queue
                         */
                        if (g_pen_num_stroke_area > 1)
                        {
                            mmi_pen_fix_multi_block_pen_position(&pos);
                        }
                        
                        mmi_pen_push_stroke_end();
                        if (g_pen_stroke_table[MMI_PEN_STROKE_UP])
                        {
                            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_STROKE_UP);
                            (g_pen_stroke_table[MMI_PEN_STROKE_UP]) (pos);
                            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_STROKE_UP);
                        }
                    }
    
                    /* Clear strokes and reset handwriting area */
                    if (g_pen_cntx.reset_stroke_on_pen_up)
                    {
                        if (g_pen_stroke_max_points > 0)
                        {
                            mmi_pen_end_strokes_of_character();
                            mmi_pen_reset();
                            mmi_pen_begin_strokes_of_character();
                        }
                        else
                        {
                            mmi_pen_reset();
                        }
                    }
    
                    break;
    
                #ifdef MMI_PEN_SUPPORT_STROKE_LONGTAP
                case STROKE_LONGTAP:
                    /* 
                     * 1. degrade sampling rate
                     * 2. reset strokes on pen on
                     */
                    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_1);
    
                    g_pen_cntx.reset_stroke_on_pen_up = 1;
                    g_pen_cntx.restore_sampling_rate_on_reset = 1;
                    if (g_pen_stroke_table[MMI_PEN_STROKE_LONGTAP])
                    {
                        MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_STROKE_LONGTAP);
                        (g_pen_stroke_table[MMI_PEN_STROKE_LONGTAP]) (pos);
                        MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_STROKE_LONGTAP);
                    }
    
                    break;
                #else /* MMI_PEN_SUPPORT_STROKE_LONGTAP */ 
                case STROKE_LONGTAP:
                    break;
                #endif /* MMI_PEN_SUPPORT_STROKE_LONGTAP */ 
    
                default:
                    MMI_ASSERT(0);
            }
    
        } /* if(!mmi_pen_check_tp_shortcut(&pos, data.event)) */
        mmi_frm_fetch_msg_from_extQ_to_circularQ();

        if ((OslNumOfCircularQMsgs() > MMI_PENDING_MSG_THRESHOLD) && delay_polling_timer)
        {
            break; 
        }
        
    }

    if (is_stroke_move)
    {
        if (g_pen_stroke_post_move)
        {
            g_pen_stroke_post_move();
        }
    }


    if (has_incoming_event)
    {
        if (!mmi_shutdown_is_in_power_off_period())
        {
            mmi_idle_key_event_backlight_check();
        }
    #ifdef __MMI_LCD_PARTIAL_ON__
        /* Switch screen and flush pen events */
        LeavePartialOnScreenSaverIfOk();
    #endif /* __MMI_LCD_PARTIAL_ON__ */ 
    }

    /* Either look-ahead buffer is empty or we need to skip the polling  */
    MMI_ASSERT(g_pen_cntx.num_lookahead_events == 0 || delay_polling_timer);

    if (delay_polling_timer)
    {
        /* Start a timer even if !g_pen_cntx.is_enabled && !g_pen_cntx.is_pen_down && g_pen_cntx.num_lookahead_events == 0 */
        StartTimer(PEN_POLLING_TIMER, MMI_PEN_DEBOUNCE_POLLING_DELAY, mmi_pen_poll_hdlr);
        g_pen_polling_timer_started = MMI_TRUE;

        Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_poll_hdlr() - delay polling timer \n");
    }
    else if (g_pen_cntx.is_pen_down)
    {
        /* Previous pen handlers might call mmi_pen_disable(), then g_pen_cntx.is_pen_down = 0.  */
        MMI_DBG_ASSERT(g_pen_cntx.is_enabled);
        StartTimer(PEN_POLLING_TIMER, MMI_PEN_POLLING_PERIOD, mmi_pen_poll_hdlr);
        g_pen_polling_timer_started = MMI_TRUE;
    }
}

/*
 * Refernece: touch_panel_sendilm() 
 * THIS FUNCTION IS EXECUTED IN DRIVER CONTEXT
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_touch_panel_sendilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]         unused
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_touch_panel_sendilm(void *param /* unused */ , Touch_Panel_Event_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *tp_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dummy function */
    if (state == PEN_DOWN || state == STROKE_DOWN)
    {
        if (!g_pen_is_driver_indication_in_queue)
        {
            g_pen_is_driver_indication_in_queue = 1;
            DRV_BuildPrimitive(tp_ilm, MOD_TP_TASK, MOD_MMI, MSG_ID_TP_EVENT_IND, NULL);
            msg_send_ext_queue(tp_ilm);
        }
    }
}

/* Protocol event handler of MSG_ID_TP_EVENT_IND */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_touch_panel_event_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]     unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_touch_panel_event_ind(void *param /* unused */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(
        MMI_FW_TRC_G1_FRM,
        "[Pen] mmi_pen_touch_panel_event_in - %d, %d\n",
        (int)g_pen_polling_timer_started,
        (int)g_pen_cntx.is_enabled);

    g_pen_is_driver_indication_in_queue = 0;

    if (!g_pen_polling_timer_started && g_pen_cntx.is_enabled)
    {
        mmi_pen_poll_hdlr();
    }
}

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* Dummy pen handler */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_dummy_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_dummy_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(pos);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_init
 * DESCRIPTION
 *  Initialize pen system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HANDWRITING_PAD__
    mmi_frm_setup_default_pen_handler();
#endif 

    g_pen_initialized = KAL_TRUE;
    g_pen_cntx.pre_pen_callback_fp = NULL;
    g_pen_cntx.post_pen_callback_fp = NULL;

    mmi_pen_stop_capture_strokes();
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_timeout_period(MMI_PEN_LONGTAP_TIME, MMI_PEN_REPEAT_TIME, MMI_PEN_STROKE_LONGTAP_TIME);
    mmi_pen_config_move_offset(
        MMI_PEN_SKIP_MOVE_OFFSET,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_LONGTAP_OFFSET,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET);

    touch_panel_cb_registration(mmi_pen_touch_panel_sendilm, NULL);
    SetProtocolEventHandler(mmi_pen_touch_panel_event_ind, MSG_ID_TP_EVENT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_block
 * DESCRIPTION
 *  Block pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 *  mmi_pen_enable()/mmi_pen_disable() are ignored when pen is blocked.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_disable();
    g_pen_cntx.is_blocked = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_unblock
 * DESCRIPTION
 *  Unblock pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 *  mmi_pen_enable()/mmi_pen_disable() are ignored when pen is blocked.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_unblock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_cntx.is_blocked = 0;
    mmi_pen_enable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_sampling_period
 * DESCRIPTION
 *  Config sampling period of Event-based and Stroke-Based
 * PARAMETERS
 *  low         [IN]        Sampling period in non-handwriting area (multiple of 10ms)
 *  high        [IN]        Sampling period in handwriting area (multiple of 10ms)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_sampling_period(kal_uint32 low, kal_uint32 high)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    touch_panle_conf_sample_period(low, high);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_timeout_period
 * DESCRIPTION
 *  Config timeout period for LongTap and Repeat
 * PARAMETERS
 *  longtap             [IN]        Timeout period for Pen LongTap event (multiple of 10ms).
 *  repeat              [IN]        Timeout period for Pen Repeat event (multiple of 10ms).
 *  stroke_longtap      [IN]        Timeout period for Stroke LongTap event (multiple of 10ms).
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_timeout_period(kal_uint32 longtap, kal_uint32 repeat, kal_uint32 stroke_longtap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    touch_panle_conf_timeout_period(longtap, repeat, stroke_longtap);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_move_offset
 * DESCRIPTION
 *  Config
 * PARAMETERS
 *  event_based         [IN]        Minimum move offset for Pen Move event
 *  stroke_based        [IN]        Minimum move offset for Stroke Move event
 *  long_tap            [IN]        Maximum move offset for Pen LongTap event
 *  stroke_long_tap     [IN]        Maximum move offset for Stroke LongTap event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_move_offset(
        kal_uint32 event_based,
        kal_uint32 stroke_based,
        kal_uint32 long_tap,
        kal_uint32 stroke_long_tap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    touch_panel_conf_move_offset(
        (kal_uint16) event_based,
        (kal_uint16) stroke_based,
        (kal_uint16) long_tap,
        (kal_uint16) stroke_long_tap);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_enable
 * DESCRIPTION
 *  Enable pen system
 *  
 *  Note: typically on Keypad Up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  If g_pen_initialized is not true, we do not enable touch screen because
 *  TP task might not be running
 *****************************************************************************/
void mmi_pen_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_enable()\n");

    if (!g_pen_initialized || g_pen_cntx.is_blocked || g_pen_cntx.is_enabled)
    {
        return;
    }

    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.is_enabled = 1;

    touch_panel_enable(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_disable
 * DESCRIPTION
 *  Disable pen system
 *  
 *  Note: typically on Keypad Down because we don't want to use keypad and touch screen
 *  at the same time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_disable()\n");

    if (!g_pen_initialized || g_pen_cntx.is_blocked || !g_pen_cntx.is_enabled)
    {
        return;
    }

    touch_panel_enable(KAL_FALSE);
    touch_panel_flush();

    if (g_pen_cntx.is_pen_down)
    {
        /* For both stroke-based and event-based */
        if (g_pen_event_table[MMI_PEN_EVENT_ABORT])
        {
            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
            (g_pen_event_table[MMI_PEN_EVENT_ABORT]) (g_pen_cntx.pen_current_pos);
            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
        }
    }

    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_reset
 * DESCRIPTION
 *  Reset the status of touch screen
 *  - Flush event queue
 *  - If the pen is currently tapped down, ignore all subsequent pen events until the pen is up.
 *  
 *  Note: typically on MMI screen switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_reset()\n");

    if (!g_pen_initialized || g_pen_cntx.is_blocked || !g_pen_cntx.is_enabled)
    {
        return;
    }

    if (g_pen_cntx.restore_sampling_rate_on_reset)
    {
        mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    }

    if (g_pen_cntx.is_pen_down)
    {
        /* For both stroke-based and event-based */
        if (g_pen_event_table[MMI_PEN_EVENT_ABORT])
        {
            MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
            (g_pen_event_table[MMI_PEN_EVENT_ABORT]) (g_pen_cntx.pen_current_pos);
            MMI_PEN_EXECUTE_POST_CALLBACK_FUNC(MMI_PEN_EVENT_ABORT);
        }
    }

    touch_panel_reset(KAL_TRUE);

    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.is_enabled = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_state
 * DESCRIPTION
 *  Get the current state of touch screen
 * PARAMETERS
 *  is_enabled      [OUT]         
 *  is_pen_down     [OUT]         
 * RETURNS
 *  void
 * REMARKS
 *  It returns the current state *inside MMI task*, real pen state might be changed, but
 *  the driver indication might not be processed yet.
 *****************************************************************************/
void mmi_pen_get_state(kal_bool *is_enabled, kal_bool *is_pen_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_enabled)
    {
        *is_enabled = KAL_TRUE;
        if (g_pen_cntx.is_pen_down)
        {
            *is_pen_down = KAL_TRUE;
        }
        else
        {
            *is_pen_down = KAL_FALSE;
        }
    }
    else
    {
        *is_enabled = KAL_FALSE;
        *is_pen_down = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_calibration
 * DESCRIPTION
 *  Start pen calibration
 * PARAMETERS
 *  num         [IN]        Number of calibration points
 *  points      [IN]        Calibration points
 * RETURNS
 *  void
 * REMARKS
 *  After mmi_pen_reset(), the calibration process is terminated.
 *****************************************************************************/
void mmi_pen_start_calibration(kal_uint16 num, const mmi_pen_point_struct *points)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_start_calibration()\n");
    MMI_ASSERT(g_pen_initialized);

    touch_panel_start_cali((TouchPanelCoordStruct*) points, num);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_set_calibration_data
 * DESCRIPTION
 *  Assign driver calibration data
 * PARAMETERS
 *  data        [IN]        
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void mmi_pen_set_calibration_data(const mmi_pen_calibration_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanelCaliStruct cali;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(sizeof(mmi_pen_calibration_struct) == sizeof(TouchPanelCaliStruct));
    memcpy(&cali, data, sizeof(TouchPanelCaliStruct));
    touch_panel_set_cali(cali);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_read_calibration_data
 * DESCRIPTION
 *  Read the current value of driver calibration data
 * PARAMETERS
 *  data        [OUT]       
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void mmi_pen_read_calibration_data(mmi_pen_calibration_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanelCaliStruct cali;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(sizeof(mmi_pen_calibration_struct) == sizeof(TouchPanelCaliStruct));
    touch_panel_read_cali(&cali);
    memcpy(data, &cali, sizeof(TouchPanelCaliStruct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_down_handler
 * DESCRIPTION
 *  Register the Pen Down handler
 * PARAMETERS
 *  pen_fp      [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_DOWN] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_long_tap_handler
 * DESCRIPTION
 *  Register the Pen LongTap handler
 *  
 *  LongTap handler is invoked when  the pen is tapped for a period of time
 *  and stays at the same place where it is tapped down.
 *  
 *  It is invoked atmost one time before pen up.
 * PARAMETERS
 *  pen_fp      [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_LONG_TAP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_repeat_handler
 * DESCRIPTION
 *  Register the Pen Repeat handler.
 *  
 *  Repeat handler is invoked after LongTap handler.
 *  However, unlike LongTap handler, Repeat handler is invoked even if
 *  it does not stays at the same place as Pen Down.
 *  
 *  it might be invoked more than one times before pen up.
 * PARAMETERS
 *  pen_fp      [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_REPEAT] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_move_handler
 * DESCRIPTION
 *  Register the Pen Move handler.
 *  
 *  The invocation frequency of Pen Move handler is typically less than driver sampling rate.
 * PARAMETERS
 *  pen_fp      [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_MOVE] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_up_handler
 * DESCRIPTION
 *  Register the Pen Up handler.
 * PARAMETERS
 *  pen_fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_UP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_abort_handler
 * DESCRIPTION
 *  Register the Pen Abort handler.
 * PARAMETERS
 *  pen_fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_abort_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_event_table[MMI_PEN_EVENT_ABORT] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_capture_strokes
 * DESCRIPTION
 *  Start to capture stroke inside the handwriting area.
 *
 *  This API is typically used in entry function of editor screen.
 *
 *  The points are en-queued in 'point_array' in the following format:
 * 
 *  Each point contains two 16-bit integers for x, y coordinates. Two strokes are separated with
 *  marker (0xffff, 0), and all strokes of one character are ended with (0xffff, 0xffff) by
 *  mmi_pen_end_strokes_of_character(). The parameter 'max_points' should also include the memory 
 *  used by markers.
 *  (x0, y0) (x1, y1)  (0xffff, 0), (0xffff, 0), (0xffff, 0xffff)
 *  
 *  We has the following types of stroke-based handler
 *  - Stroke Down
 *  - Stroke Move
 *  - Stroke Up
 *  - Stroke LongTap (#ifdef MMI_PEN_SUPPORT_STROKE_LONGTAP)
 *  However, it does not have Stroke Repeat handler.
 *  
 *  In single-block mode ('num_regions' > 1), it enters stroke-based mode when pen is down in 
 *  handwriting area and then moves across MMI_PEN_STROKE_MIN_OFFSET pixels.
 *
 *  In multi-block mode ('num_regions' > 1), it enters stroke-based mode immediately after pen 
 *  is down in handwriting area.
 * 
 *  Note: the parameter 'ext_region' can only be used in single-block mode.
 * 
 * PARAMETERS
 *  max_points          [IN]        Maximum number of points can be en-queued.
 *  point_array         [IN]        Array for storing sampled points in strokes.
 *  num_regions         [IN]        Number of handwriting regions
 *  region_array        [IN]        Handwriting regions
 *  ext_region          [IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_start_capture_strokes(
        kal_uint32 max_points,
        mmi_pen_point_struct *point_array,
        kal_uint32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    TouchPanelHandAreaStruct area[HAND_WRITING_AREA_NUM];
    TouchPanelHandAreaStruct ext_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_start_capture_strokes()\n");

    /* Multi-block mode does not have extended region. Otherwise, it cannot switch to another 
       block and multi-block feature is broken. */
    MMI_ASSERT(ext_region == NULL || num_regions == 1);
    if (num_regions > HAND_WRITING_AREA_NUM)
    {
        num_regions = HAND_WRITING_AREA_NUM;
    }

    for (i = 0; i < num_regions; i++)
    {
        area[i].min.x = (kal_int16) region_array[i].x1;
        area[i].min.y = (kal_int16) region_array[i].y1;
        area[i].max.x = (kal_int16) region_array[i].x2;
        area[i].max.y = (kal_int16) region_array[i].y2;
    }

    if (ext_region == NULL) /* No extended area */
    {
    #ifdef __MMI_TOUCH_SCREEN__
        ext_area.min.x = -1;
        ext_area.min.y = -1;
        ext_area.max.x = -1;
        ext_area.max.y = -1;
    #else /* __MMI_TOUCH_SCREEN__ */ 
        /* change to full region for handwriting automatically */
        // TODO: should we change this?
        ext_area.min.x = TOUCH_PANEL_COORD_X_START;
        ext_area.min.y = TOUCH_PANEL_COORD_Y_START;
        ext_area.max.x = (kal_int16) TOUCH_PANEL_COORD_X_END - 1;
        ext_area.max.y = (kal_int16) TOUCH_PANEL_COORD_Y_END - 1;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    else
    {
        ext_area.min.x = (kal_int16) ext_region->x1;
        ext_area.min.y = (kal_int16) ext_region->y1;
        ext_area.max.x = (kal_int16) ext_region->x2;
        ext_area.max.y = (kal_int16) ext_region->y2;
    }

    touch_panel_conf_handwriting(area, num_regions, &ext_area);

    g_pen_stroke_max_points = max_points;
    g_pen_stroke_points = point_array;
    
    g_pen_num_stroke_area = num_regions;
    memcpy(g_pen_stroke_areas, region_array, sizeof(mmi_pen_handwriting_area_struct) * num_regions);
    
    /* Stroke minimum offset is used by single-block mode only */
    if (num_regions == 1)
    {
        g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset_square = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_change_handwriting_area
 * DESCRIPTION
 *  Change hand-written area.
 *  It is typically used when changing input language.
 *  
 *  It will
 *  1. reset handwriting and g_pen_stroke_min_offset_square
 *  2. mmi_pen_reset() to flush queue.
 * PARAMETERS
 *  num_regions         [IN]        Number of handwriting regions
 *  region_array        [IN]        Handwriting regions
 *  ext_region          [IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_change_handwriting_area(
        kal_uint32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    TouchPanelHandAreaStruct area[HAND_WRITING_AREA_NUM];
    TouchPanelHandAreaStruct ext_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_change_handwriting_area()\n");

    if (g_pen_stroke_max_points == 0)
    {
        /* MMI_DBG_ASSERT(0); */
        return;
    }

    /* Multi-block mode does not have extended region */
    MMI_ASSERT(ext_region == NULL || num_regions == 1);

    /* Change handwriting area */
    if (num_regions > HAND_WRITING_AREA_NUM)
    {
        num_regions = HAND_WRITING_AREA_NUM;
    }

    for (i = 0; i < num_regions; i++)
    {
        area[i].min.x = (kal_int16) region_array[i].x1;
        area[i].min.y = (kal_int16) region_array[i].y1;
        area[i].max.x = (kal_int16) region_array[i].x2;
        area[i].max.y = (kal_int16) region_array[i].y2;
    }

    if (ext_region == NULL)
    {
        ext_area.min.x = -1;
        ext_area.min.y = -1;
        ext_area.max.x = -1;
        ext_area.max.y = -1;
    }
    else
    {
        // TODO: should we change this?    
        ext_area.min.x = (kal_int16) ext_region->x1;
        ext_area.min.y = (kal_int16) ext_region->y1;
        ext_area.max.x = (kal_int16) ext_region->x2;
        ext_area.max.y = (kal_int16) ext_region->y2;
    }

    touch_panel_conf_handwriting(area, num_regions, &ext_area);

    g_pen_num_stroke_area = num_regions;
    memcpy(g_pen_stroke_areas, region_array, sizeof(mmi_pen_handwriting_area_struct) * num_regions);

    /* Stroke minimum offset is used by single-block mode only */
    if (num_regions == 1)
    {
        g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset_square = 0;
    }

    /* 
     * We will call mmi_pen_reset() *later* on Pen Up or Stroke Up event.
     *
     * There might be many pending events in driver queue if MMI task is blocked by 
     * other time-consuming jobs. If there are pending stroke events in driver queue, 
     * it is better to flush driver queue.
     *
     */
    if (!g_pen_cntx.is_pen_down)
    {
        /* Clear strokes */
        mmi_pen_end_strokes_of_character();
        mmi_pen_reset();
        mmi_pen_begin_strokes_of_character();
    }
    else
    {
        /* 
         * NOTE: we *cannot* call mmi_pen_reset().
         *
         * For example, assume mmi_pen_change_handwriting_area() is invoked on Button Down.
         * If we invoke mmi_pen_reset() here, it will send MMI_PEN_EVENT_ABORT and reset the button.
         */
        g_pen_cntx.reset_stroke_on_pen_up = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_stop_capture_strokes
 * DESCRIPTION
 *  Stop capturing stroke
 *  
 *  Note: mmi_pen_reset() should be used to flush flush driver pen queue
 *  after this function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_stop_capture_strokes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanelHandAreaStruct area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_stop_capture_strokes()\n");

    area.max.x = -1;
    area.max.y = -1;
    area.min.x = -1;
    area.min.y = -1;
    touch_panel_conf_handwriting(&area, 1, &area);
    g_pen_stroke_max_points = 0;
    g_pen_stroke_points = NULL;

    /*
     * unfinished stroke is illegal. Applications need to check mmi_pen_peek_stroke_state()
     * * before using mmi_pen_stop_capture_strokes().
     */
    MMI_DBG_ASSERT(!g_pen_cntx.is_stroke_down);

    /* 
     * We will call mmi_pen_reset() *later* on Pen Up or Stroke Up event.
     *
     * There might be many pending events in driver queue if MMI task is blocked by 
     * other time-consuming jobs. If there are pending stroke events in driver queue, 
     * it is better to flush driver queue.
     *
     */
    if (!g_pen_cntx.is_pen_down)
    {
        mmi_pen_reset();
    }
    else
    {
        /* 
         * NOTE: we *cannot* call mmi_pen_reset().
         *
         * For example, assume mmi_pen_stop_capture_strokes() is invoked when scrollbar of inline editor 
         * is scrolled on Pen Move event and the highlighed single-line editor is un-highlighted. 
         * If we invoke mmi_pen_reset() here, it will send MMI_PEN_EVENT_ABORT and reset the scrolling of scrollbar.
         */
        g_pen_cntx.reset_stroke_on_pen_up = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_down_handler
 * DESCRIPTION
 *  Register the Stroke Down handler
 * PARAMETERS
 *  pen_fp      [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_down_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_table[MMI_PEN_STROKE_DOWN] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_move_handler
 * DESCRIPTION
 *  Register the Stroke Move handler
 * PARAMETERS
 *  begin_fp        [IN]        
 *  end_fp          [IN]        
 *  pen_fp          [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_move_handler(void (*begin_fp) (void), void (*end_fp) (void), mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_pre_move = begin_fp;
    g_pen_stroke_table[MMI_PEN_STROKE_MOVE] = pen_fp;
    g_pen_stroke_post_move = end_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_up_handler
 * DESCRIPTION
 *  Register the Stroke Up handler
 * PARAMETERS
 *  pen_fp      [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_up_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_table[MMI_PEN_STROKE_UP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_longtap_handler
 * DESCRIPTION
 *  Register the Stroke LongTap handler
 * PARAMETERS
 *  pen_fp      [IN]        Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_longtap_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_stroke_table[MMI_PEN_STROKE_LONGTAP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_peek_stroke_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  has_unfinished_stroke       [OUT]       Whether there are more strokes to come
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_peek_stroke_state(MMI_BOOL *has_unfinished_stroke)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_pen_down)
    {
        *has_unfinished_stroke = MMI_TRUE;
    }
    else
    {
        TouchPanelEventStruct data;

        if (!mmi_pen_lookahead_buffer_peek_event(&data))
        {
            *has_unfinished_stroke = MMI_FALSE;
        }
        else
        {
            /* Even if it is a PEN_ABORT, we still need to handle it */
            *has_unfinished_stroke = MMI_TRUE;
        }
    }

    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_peek_stroke_state() - %d\n", (int)*has_unfinished_stroke);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_begin_strokes_of_character
 * DESCRIPTION
 *  Start to write a new character
 *  
 *  It is typically coupled with mmi_pen_end_strokes_of_character(), which stops en-queueing
 *  strokes inside 'point_array'.
 *  In mmi_pen_begin_strokes_of_character(), MMI continue to en-queue strokes from the head of 'point_array'.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_begin_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_begin_strokes_of_character()\n");

    g_pen_cntx.num_points_queued = 0;

    /* Note: touch_panel_reset_handwriting() is invoked both in mmi_pen_begin_strokes_of_character()
       and mmi_pen_end_strokes_of_character() due to some driver implementation reason */
    touch_panel_reset_handwriting();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_end_strokes_of_character
 * DESCRIPTION
 *  End a written character.
 *  
 *  The following procedures are executed
 *  o Reset handwriting area to original size
 *  o Stop en-queueing new strokes inside 'point_array'. (But incoming strokes are still en-queued in driver ring buffer)
 *  o Append end marker (0xffff, 0xffff) in 'point_array'
 *  This API should be used only if there is no unfinished stroke (checked by mmi_pen_peek_stroke_state()).
 *  After it returns, we may pass 'point_array' to handwriting recognition engine.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_end_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_end_strokes_of_character()\n");
 
    mmi_pen_push_char_end();

    touch_panel_reset_handwriting();

    /* Stroke minimum offset is used by single-block mode only */
    if (g_pen_num_stroke_area == 1)
    {
        g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset_square = 0;
    }

#ifdef MMI_PEN_SAVE_STROKE_IN_FILE
    {
        extern void mmi_pen_save_stroke_in_file(mmi_pen_point_struct *, S32);

        mmi_pen_save_stroke_in_file(g_pen_stroke_points, g_pen_cntx.num_points_queued);
    }
#endif /* MMI_PEN_SAVE_STROKE_IN_FILE */ 
}

#else 

/* Make ARM compiler happy */
int g_touch_screen_dummy;

#endif 

#ifdef __MMI_HANDWRITING_PAD__
/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* the current active control area */
static S16 actived_control_area = -1;

/* convert the pen event to the key event */
static S32 mmi_pen_key_event[] = 
{
    WM_KEYPRESS,            /* MMI_PEN_EVENT_DOWN, */
    WM_KEYRELEASE,          /* MMI_PEN_EVENT_UP, */
    DRV_WM_KEYLONGPRESS,    /* MMI_PEN_EVENT_LONG_TAP, */
    DRV_WM_KEYREPEATED,     /* MMI_PEN_EVENT_REPEAT, */
    -1,                     /* MMI_PEN_EVENT_MOVE, */
    -1                      /* MMI_PEN_EVENT_ABORT, */
};


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_inside_control_area
 * DESCRIPTION
 *  Check the pen event if in the control area
 *  We will check the pen event for each control area that defined
 *  in tp_area_table[]
 * PARAMETERS
 *  pos     [IN]        Pen event position
 * RETURNS
 *  S32   return the index of tp_area_table[]; return -1 if can't found
 *****************************************************************************/
S32 mmi_pen_check_inside_control_area(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL is_find = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gilbert */
    for (i = 0; i < TP_AREA_MAX_NUM /* (sizeof(tp_area_table)/sizeof(tp_area_struct)) */ ; i++)
    {
        if (IS_ENABLE_FLAG(tp_area_table[i].flag, TP_CONTROL_AREA))
        {
            mmi_pen_polygon_area_struct polygon = {0};

            /* control area */
            polygon.points = (mmi_pen_point_struct*) tp_area_table[i].pos;
            polygon.num = 0;
            /* count the side number of the polygon */
            while ((polygon.points[polygon.num].x != -1) && (polygon.points[polygon.num].y != -1))
            {
                polygon.num++;
            }
            /* Check if the point is inside the polygon */
            if (mmi_pen_check_inside_polygon(&polygon, pos))
            {
                is_find = MMI_TRUE;
                break;
            }
        }
        else
        {
            /* handwriting area */
        }
    }

    /* 
     * If point is inside someone polygon, 
     * return the index of tp_area_table or return -1. 
     */
    return (is_find) ? i : -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_general_pen_handler
 * DESCRIPTION
 *  The mmi_general_pen_handler in __MMI_HANDWRITING_PAD__
 *  It only handle the pen events for the cotnrol areas, and it
 *  process the evenst according the control area setting.
 * PARAMETERS
 *  type            [IN]        Pen event type
 *  point           [IN]        Pen event position
 *  active_i        [IN]        The active control area index
 * RETURNS
 *  S32   return the index of tp_area_table[]
 *  return -1 if can't found
 *****************************************************************************/
static S16 mmi_general_pen_handler(U32 type, mmi_pen_point_struct point, S16 active_i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index = mmi_pen_check_inside_control_area(point)) >= 0)
    {
        if (IS_ENABLE_FLAG(tp_area_table[index].flag, TP_MAPPING_KEY))
        {

            if ((mmi_pen_key_event[type] != -1) && ((active_i == -1) || (index == active_i)))
            {
                U16 KeyMapIndex = tp_area_table[index].flag & TP_MAPPING_KEY_MASK;

                mmi_frm_convert_process_key_event((U32) mmi_pen_key_event[type], (U16) KeyMapIndex);
            }
            else
            {
                /* No mapping driver key event; Do nothing */
            }
        }
        else if (IS_ENABLE_FLAG(tp_area_table[index].flag, TP_CUSTOM_HANDLE))
        {
            /* custom want to handle this control area */
            if ((index == active_i) &&
                (tp_area_table[index].hdlr_table != NULL) && (tp_area_table[index].hdlr_table[type] != NULL))
            {
                (tp_area_table[index].hdlr_table[type]) (point);
            }
        }
        else
        {
            ASSERT(0);
        }
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_general_pen_down_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        Pen event position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_general_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_general_pen_down_handler (%d, %d)", point.x, point.y);
    ClearKeyEvents();
    actived_control_area = mmi_general_pen_handler(MMI_PEN_EVENT_DOWN, point, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_general_pen_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        Pen event position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_general_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_general_pen_up_handler (%d, %d)", point.x, point.y);
    mmi_general_pen_handler(MMI_PEN_EVENT_UP, point, actived_control_area);
    actived_control_area = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_general_pen_long_tap_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        Pen event position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_general_pen_long_tap_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_general_pen_long_tap_handler (%d, %d)", point.x, point.y);
    mmi_general_pen_handler(MMI_PEN_EVENT_LONG_TAP, point, actived_control_area);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_general_pen_repeat_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        Pen event position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_general_pen_repeat_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_general_pen_repeat_handler (%d, %d)", point.x, point.y);
    mmi_general_pen_handler(MMI_PEN_EVENT_REPEAT, point, actived_control_area);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_general_pen_move_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        Pen event position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_general_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 area_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_general_pen_move_handler (%d, %d)", point.x, point.y);
    actived_control_area = mmi_general_pen_handler(MMI_PEN_EVENT_MOVE, point, actived_control_area);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_general_pen_abort_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        Pen event position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_general_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_general_pen_abort_handler (%d, %d)", point.x, point.y);
    mmi_general_pen_handler(MMI_PEN_EVENT_ABORT, point, actived_control_area);
    ClearKeyEvents();
    actived_control_area = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_setup_default_pen_handler
 * DESCRIPTION
 *  the default pen handlers for the handwriting pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_setup_default_pen_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_frm_setup_default_pen_handler");

    g_pen_event_table[MMI_PEN_EVENT_DOWN] = mmi_general_pen_down_handler;
    g_pen_event_table[MMI_PEN_EVENT_UP] = mmi_general_pen_up_handler;
    g_pen_event_table[MMI_PEN_EVENT_LONG_TAP] = mmi_general_pen_long_tap_handler;
    g_pen_event_table[MMI_PEN_EVENT_REPEAT] = mmi_general_pen_repeat_handler;
    g_pen_event_table[MMI_PEN_EVENT_MOVE] = mmi_general_pen_move_handler;
    g_pen_event_table[MMI_PEN_EVENT_ABORT] = mmi_general_pen_abort_handler;
}

#endif /* __MMI_HANDWRITING_PAD__ */ 

/*****************************************************************************
* 
*  Utility functions
* 
*****************************************************************************/

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_set_event_handler_callback
 * DESCRIPTION
 *  The application could set the pen callback function 
 *  (pre- and post- callback function)
 *  We will invoke the callback when touch-screen calls the pen event handler.
 * PARAMETERS
 *  pre_fp      [IN]         
 *  post_fp     [IN]        
 * RETURNS
 * void
 *****************************************************************************/
void mmi_pen_set_event_handler_callback(func_ptr_short pre_fp, func_ptr_short post_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_set_event_handler_callback pre:%x, post:%x", pre_fp, post_fp);
    if (g_pen_cntx.pre_pen_callback_fp == NULL && g_pen_cntx.post_pen_callback_fp == NULL)
    {
        g_pen_cntx.pre_pen_callback_fp = pre_fp;
        g_pen_cntx.post_pen_callback_fp = post_fp;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_reset_event_handler_callback
 * DESCRIPTION
 *  The application could set the pen callback function 
 *  (pre- and post- callback function)
 *  We will invoke the callback when touch-screen calls the pen event handler.
 * PARAMETERS
 *  pre_fp      [IN]         
 *  post_fp     [IN]        
 * RETURNS
 * void
 *****************************************************************************/
void mmi_pen_reset_event_handler_callback(func_ptr_short pre_fp, func_ptr_short post_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Trace2(MMI_FW_TRC_G1_FRM, "[Pen] mmi_pen_reset_event_handler_callback pre:%x, post:%x", pre_fp, post_fp);
    if (g_pen_cntx.pre_pen_callback_fp == pre_fp)
    {
        g_pen_cntx.pre_pen_callback_fp = NULL;
    }
    if (g_pen_cntx.post_pen_callback_fp == post_fp)
    {
        g_pen_cntx.post_pen_callback_fp = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_inside_polygon
 * DESCRIPTION
 *  Check if a point is inside a polygon.
 *  A optimized algorithm is used here
 * PARAMETERS
 *  polygon     [IN]         
 *  pos         [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL c = MMI_FALSE;
    S16 i, j;
    S16 nPoints = polygon->num;
    mmi_pen_point_struct *outline = polygon->points;
    S16 x = pos.x;
    S16 y = pos.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = nPoints - 1; i < nPoints; j = i++)
    {
        mmi_pen_point_struct *a = &outline[i];
        mmi_pen_point_struct *b = &outline[j];

        if (((a->y <= y && y < b->y) || (b->y <= y && y < a->y)) &&
            (x < (b->x - a->x) * (y - a->y) / (b->y - a->y) + a->x))
        {
            c = !c;
        }
    }
    Trace2(TRACE_GROUP_1, "[Pen] <%d,%d> check_inside_polygon: (%d, %d) (%d, %d) (%d, %d) (%d, %d); result:%d", pos.x, pos.y, 
    											outline[0].x, outline[0].y, outline[1].x, outline[1].y, outline[2].x, outline[2].y, outline[3].x, outline[3].y, c);

    return c;
}

/*****************************************************************************
* 
*  Statistics on recognition rate
*  
*****************************************************************************/

#ifdef MMI_PEN_SAVE_STROKE_IN_FILE

#include "Fat_fs.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_save_stroke_in_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  array           [IN]         
 *  num_points      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_save_stroke_in_file(mmi_pen_point_struct *array, S32 num_points)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_index;
    S8 path[256];
    S8 path_ascii[128];
    int drive_letter;
    FS_HANDLE handle;
    U32 written_cnt, read_cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive_letter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_DRIVE_V_NORMAL);
    if (drive_letter < 0)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    sprintf(path_ascii, "%c:\\stroke", drive_letter);
    mmi_asc_to_ucs2(path, path_ascii);
    FS_CreateDir((WCHAR*) path);

    sprintf(path_ascii, "%c:\\stroke\\@index", drive_letter);
    mmi_asc_to_ucs2(path, path_ascii);

    handle = FS_Open((WCHAR*) path, FS_CREATE | FS_READ_WRITE);
    if (handle < 0)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    FS_Read(handle, &file_index, sizeof(S32), &read_cnt);
    if (read_cnt != sizeof(S32))
    {
        file_index = 0;
    }
    else
    {
        file_index++;
    }
    FS_Seek(handle, 0, FS_FILE_BEGIN);
    FS_Write(handle, &file_index, sizeof(S32), &written_cnt);
    MMI_DBG_ASSERT(written_cnt == sizeof(S32));
    FS_Close(handle);

#ifdef __MMI_HANWANG__
    sprintf(path_ascii, "%c:\\stroke\\h%d", drive_letter, file_index++);
#else 
    sprintf(path_ascii, "%c:\\stroke\\p%d", drive_letter, file_index++);
#endif 
    mmi_asc_to_ucs2(path, path_ascii);

    handle = FS_Open((WCHAR*) path, FS_CREATE | FS_CREATE_ALWAYS);
    if (handle < 0)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    FS_Write(handle, array, num_points * sizeof(mmi_pen_point_struct), &written_cnt);
    MMI_DBG_ASSERT(num_points * sizeof(mmi_pen_point_struct) == written_cnt);

    FS_Close(handle);
}

#if !defined(__MTK_TARGET__)

#include "stdio.h"
#include "EditorPenGprot.h"
extern S32 mmi_pen_editor_hand_writing_get_candidates(
            U16 *stroke_buffer,
            UI_character_type *candidate_array,
            mmi_pen_editor_input_type_enum h_w_type,
            S32 number);
extern void mmi_pen_editor_hand_writing_initailize(void);

#define MMI_PEN_LOCAL_STROKE_FOLDER       "D:\\fs\\DRIVE_D\\stroke\\"


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_convert_format_penpower_and_hanwang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stroke_buf      [IN/OUT]         
 *  point_cnt       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_convert_format_penpower_and_hanwang(mmi_pen_point_struct *stroke_buf, int point_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (point_cnt--)
    {
        if (stroke_buf->x == -1 && stroke_buf->y == 0)
        {
            stroke_buf->y = -1;
        }
        else if (stroke_buf->x == -1 && stroke_buf->y == -1)
        {
            stroke_buf->y = 0;
        }

        stroke_buf++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_write_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fp                  [IN/OUT]         
 *  index               [IN]        
 *  num_candidates      [IN]        
 *  candidates          [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_write_result(FILE *fp, S32 index, S32 num_candidates, UI_character_type *candidates)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[256];
    S8 buf_ascii[128];
    int slen;
    int ret;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(buf_ascii, "%d\t%d\t", index, num_candidates);
    slen = strlen(buf_ascii);
    mmi_asc_to_ucs2(buf, buf_ascii);
    ret = fwrite(buf, slen * 2, 1, fp);
    MMI_ASSERT(ret == 1);
    for (i = 0; i < num_candidates; i++)
    {
        UI_character_type ch = *candidates++;

        /* ch = (ch >> 8) | ((ch & 0x00FF) << 8); */
        ret = fwrite(&ch, sizeof(UI_character_type), 1, fp);
        MMI_ASSERT(ret == 1);
    }
    fwrite(L"\r\n", 2, 2, fp);
}

/* Output stoke\@result */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_analyze_stroke_in_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_analyze_stroke_in_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *output;   /* result */
    FILE *input;
    int file_cnt;
    int index;
    char pathname[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_editor_hand_writing_initailize();

#ifdef __MMI_HANWANG__
    output = fopen(MMI_PEN_LOCAL_STROKE_FOLDER "@result_hw", "wb");
#else 
    output = fopen(MMI_PEN_LOCAL_STROKE_FOLDER "@result_pp", "wb");
#endif 
    if (!output)
    {
        MMI_ASSERT(0);
    }
    fwrite("\xFF\xFE", 2, 1, output);   /* BOM of UCS2 */

    input = fopen(MMI_PEN_LOCAL_STROKE_FOLDER "@index", "rb");
    if (!input)
    {
        MMI_ASSERT(0);
    }
    if (fread(&file_cnt, sizeof(int), 1, input) != 1)
    {
        MMI_ASSERT(0);
    }
    fclose(input);
    file_cnt++;

    for (index = 0; index < file_cnt; index++)
    {
        MMI_BOOL hanwang_format = MMI_TRUE;
        S32 num_candidates;
        UI_character_type candidate_buffer[10];
        long file_size;
        char *stroke_buf;

        /* Hanwang */
        sprintf(pathname, MMI_PEN_LOCAL_STROKE_FOLDER "h%d", index);
        input = fopen(pathname, "rb");
        if (!input)
        {
            /* Pen power */
            hanwang_format = MMI_FALSE;

            sprintf(pathname, MMI_PEN_LOCAL_STROKE_FOLDER "p%d", index);
            input = fopen(pathname, "rb");
            if (!input)
            {
                printf("Cannot open stroke file %d\r\n", index);
                continue;
            }
        }

        fseek(input, 0, SEEK_END);
        file_size = ftell(input);
        fseek(input, 0, SEEK_SET);

        MMI_ASSERT(!(file_size & 3));

        stroke_buf = (char*)malloc(file_size);
        if (fread(stroke_buf, 1, file_size, input) != file_size)
        {
            MMI_ASSERT(0);
        }

        fclose(input);

    #ifdef __MMI_HANWANG__
        if (!hanwang_format)
    #else 
        if (hanwang_format)
    #endif 
        {
            mmi_pen_convert_format_penpower_and_hanwang((mmi_pen_point_struct*) stroke_buf, file_size >> 2);
        }

        num_candidates = mmi_pen_editor_hand_writing_get_candidates(
                            (U16*) stroke_buf,
                            candidate_buffer,
                            PEN_EDITOR_TRADITIONAL_CHINESE,
                            10);

        free(stroke_buf);

        mmi_pen_write_result(output, index, num_candidates, candidate_buffer);
    }

    fclose(output);
}

#endif /* !defined(__MTK_TARGET__) */ 

#endif /* MMI_PEN_SAVE_STROKE_IN_FILE */ 

#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 


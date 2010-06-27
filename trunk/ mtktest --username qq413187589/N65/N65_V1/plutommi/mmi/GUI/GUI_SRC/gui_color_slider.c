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
 *   gui_color_slider.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  UI component - Color picker
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */


#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"
#include "GlobalDefs.h"
#include "gui_data_types.h"
#include "gui_color_slider.h"
#include "DebugInitDef.h"
#include "wgui_categories_defs.h"

/*****************************************************************************
 * FUNCTION
 *  gui_color_slider_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN/OUT]         
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_color_slider_create(color_slider *s, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->x = x;
    s->y = y;
    s->width = width;
    s->height = height;
    s->range = 0;
    s->value = 0;
    s->filler = NULL;
    s->flags = 0;

    s->simage = GUI_COLOR_SLIDER_ARROW_IMAGE_ID;
    gdi_image_get_dimension_id(s->simage, &s->swidth, &s->sheight);
    s->shide = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_color_slider_set_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN/OUT]         
 *  range       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_color_slider_set_range(color_slider *s, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->range = range;
}


/*****************************************************************************
 * FUNCTION
 *  gui_color_slider_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN/OUT]         
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_color_slider_set_value(color_slider *s, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0)
    {
        value = 0;
    }

    if (value >= s->range)
    {
        value = s->range - 1;
    }

    s->value = value;
}


/*****************************************************************************
 * FUNCTION
 *  gui_color_slider_set_filler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN/OUT]     
 *  f       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_color_slider_set_filler(color_slider *s, UI_filled_area *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->filler = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_color_slider_set_hide_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN/OUT]         
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_color_slider_set_hide_function(color_slider *s, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->shide = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_color_slider_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_color_slider_show(color_slider *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, width, sx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = s->x;
    y1 = s->y;
    x2 = x1 + s->width - 1;
    y2 = y1 + s->height - 1;
    if (s->filler != NULL)
    {
        gui_draw_filled_area(x1, y1, x2, y2, s->filler);
    }

    width = x2 - x1 - 1;
    if (s->range > 0)
    {
        sx = (width - (s->swidth >> 1)) * s->value / (s->range - 1);
    }
    else
    {
        sx = 0;
    }
    s->sx1 = x1 + sx + 2 - (s->swidth >> 1);
    s->sy1 = y2 + 1;
    s->sx2 = s->sx1 + s->swidth - 1;
    s->sy2 = s->sy1 + s->sheight - 1;
    gdi_image_draw_id(s->sx1, s->sy1, s->simage);
}


/*****************************************************************************
 * FUNCTION
 *  gui_color_slider_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_color_slider_hide(color_slider *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sx1, sy1, sx2, sy2;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->shide == NULL)
    {
        return;
    }

    sx1 = s->sx1;
    sy1 = s->sy1;
    sx2 = s->sx2;
    sy2 = s->sy2;
    x1 = s->x;
    y1 = s->y;
    x2 = x1 + s->width - 1;
    y2 = y1 + s->height - 1;

    if (x1 < sx1)
    {
        sx1 = x1;
    }

    if (y1 < sy1)
    {
        sy1 = y1;
    }

    if (x2 > sx2)
    {
        sx2 = x2;
    }

    if (y2 > sy2)
    {
        sy2 = y2;
    }
    s->shide(sx1, sy1, sx2, sy2);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_color_slider_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN/OUT]         
 *  x           [IN]        
 *  value       [OUT]         
 *  state       [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_color_slider_translate_pen_position(
        color_slider *s,
        S16 x,
        S32 *value,
        gui_slide_control_pen_state_enum *state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *state = GUI_SLIDE_CONTROL_PEN_STATE_SLIDE;
    *value = s->value;
    if (x < s->sx1 && s->value > 0)
    {
        x -= s->x - (s->swidth >> 1);
        if (x < 0)
        {
            x = 0;
        }
        *state = GUI_SLIDE_CONTROL_PEN_STATE_AREA1;
        *value = x * s->range / (s->width + s->swidth);
    }
    else if (x > s->sx2 && s->value < s->range - 1)
    {
        x -= s->x - (s->swidth >> 1);
        if (x > s->width + s->swidth - 1)
        {
            x = s->width + s->swidth - 1;
        }
        *state = GUI_SLIDE_CONTROL_PEN_STATE_AREA2;
        *value = x * s->range / (s->width + s->swidth);
    }

    MMI_DBG_ASSERT(*value >= 0 && *value <= s->range - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_slider_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s               [IN/OUT]         
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  slide_event     [OUT]         
 *  slide_param     [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL wgui_color_slider_translate_pen_event(
        color_slider *s,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_slide_control_pen_event_enum *slide_event,
        gui_pen_event_param_struct *slide_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    S32 new_value;
    gui_slide_control_pen_state_enum new_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *slide_event = GUI_SLIDE_CONTROL_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(slide_param);

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, s->x, s->y, s->width, s->height + s->sheight))
            {
                wgui_color_slider_translate_pen_position(s, x, &new_value, &new_state);
                s->pen_state = new_state;

                if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA1)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->value - 1);
                }
                else if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA2)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->value + 1);
                }
            }
            else
            {
                ret = MMI_FALSE;
                s->pen_state = GUI_SLIDE_CONTROL_PEN_STATE_INVALID;
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_MOVE:
            if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA1)
            {
                wgui_color_slider_translate_pen_position(s, x, &new_value, &new_state);
                if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA1)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->value - 1);
                }
            }
            else if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA2)
            {
                wgui_color_slider_translate_pen_position(s, x, &new_value, &new_state);
                if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA2)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->value + 1);
                }
            }
            else if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_SLIDE)
            {
                wgui_color_slider_translate_pen_position(s, x, &new_value, &new_state);
                if (new_value != s->value)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, new_value);
                }
            }
            else
            {
                /* Ignore the event */
            }
            break;

        case MMI_PEN_EVENT_UP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_ABORT:
            /* Do nothing */
            break;
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


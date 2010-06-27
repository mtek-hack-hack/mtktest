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
 * Filename:
 * ---------
 *  wgui_panel.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Panel - UI component
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

 /*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#include "gui_panel.h"
#include "wgui_panel.h"
#include "EventsGprot.h"

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

static gui_panel_struct MMI_panel;

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

static void wgui_panel_general_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    gui_panel_general_key_handler(&MMI_panel, keycode, keytype);
}

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/

void wgui_panel_create(
        S32 x, 
        S32 y, 
        S32 width, 
        S32 height, 
        gui_util_painter_struct background,
        MMI_BOOL display_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_panel_create(
        &MMI_panel,
        x,
        y,
        width,
        height,
        background,
        display_focus,
        0);
}

void wgui_panel_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: stop animation timer
}

void wgui_panel_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_panel_show(&MMI_panel);
}

void wgui_panel_set_element_focus(
        S32 element_index,
        MMI_BOOL update_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_panel_set_element_focus(
        &MMI_panel,
        element_index,
        update_display);
}

void wgui_panel_set_element_image_id(
        S32 element_index,
        gui_panel_elem_state_enum state,
        MMI_ID_TYPE image_id)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_panel_set_element_image_id(
            &MMI_panel,
            element_index,
            state,
            image_id);
}


S32 wgui_panel_add_element(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U16 keycode,
        FuncPtr down_event_callback,
        FuncPtr up_event_callback,
        FuncPtr repeat_event_callback,
        gui_util_painter_struct normal_painter,
        gui_util_painter_struct down_painter,
        gui_util_painter_struct focussed_painter,
        gui_util_painter_struct disabled_painter,
        MMI_BOOL redraw_bg_after_state_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_panel_add_element(
            &MMI_panel,
            x,
            y,
            width,
            height,
            keycode,
            down_event_callback,
            up_event_callback,
            repeat_event_callback,
            normal_painter,
            down_painter,
            focussed_painter,
            disabled_painter,            
            redraw_bg_after_state_changed);
}


void wgui_panel_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 elem_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (elem_idx = 0; elem_idx < MMI_panel.element_count; elem_idx++)
    {
        gui_panel_element_struct *e = &MMI_panel.elements[elem_idx];
        if (e->keycode != KEY_INVALID)
        {
            SetKeyHandler(wgui_panel_general_key_handler, e->keycode, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_panel_general_key_handler, e->keycode, KEY_EVENT_UP);
            SetKeyHandler(wgui_panel_general_key_handler, e->keycode, KEY_LONG_PRESS);
            SetKeyHandler(wgui_panel_general_key_handler, e->keycode, KEY_REPEAT);
        }
    }
}


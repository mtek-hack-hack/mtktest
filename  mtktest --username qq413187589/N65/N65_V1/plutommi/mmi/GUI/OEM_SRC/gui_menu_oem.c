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
 *  gui_menu_oem.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GUI Menu OEM Layer
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
#ifdef __MMI_UI_LIST_SLIDE_EFFECT__
static UI_filled_area slide_highlight_effect_transparent_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,
    UI_IMAGE_ID_NULL,
    NULL,
    {0,0,255,100},  /* transparent color */
    {0,0,0,100},
    {0,0,0,100},
    {0,0,0,100},
    0
};

static UI_filled_area *old_menu_item_focussed_filler = NULL;
static U8 g_list_effect_slide_disable = 0;
static S32 g_old_list_highlight_x, g_old_list_highlight_y;

/* static function prototypes */
static void gui_list_effect_slide_draw_highlight_filler(S32 x, S32 y, S32 width, S32 height);
static S32 gui_list_effect_slide_is_highlight_item_two_line(void);
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

#ifdef __MMI_UI_LIST_SLIDE_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_draw_highlight_filler
 * DESCRIPTION
 *  Show list effet highlight during slidig.
 * PARAMETERS
 *  x       [IN]    x
 *  y       [IN]    y
 *  w       [IN]    width
 *  h       [IN]    height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_list_effect_slide_draw_highlight_filler(S32 x, S32 y, S32 width, S32 height)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_common_menuitem_base_struct *m;
    S32     ax, ay;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(0, 0, width - 1, height - 1);
    gdi_image_abm_get_source_layer_position(&ax, &ay);
    gdi_image_abm_set_source_layer_position(x, y);

    gui_draw_filled_area(0, 0, width - 1, height - 1, m->focussed_filler);
    
    gdi_image_abm_set_source_layer_position(ax, ay);

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_is_highlight_item_two_line
 * DESCRIPTION
 *  Check if the current highlighted item is two-line.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: single line. 1: two line.
 *****************************************************************************/
static S32 gui_list_effect_slide_is_highlight_item_two_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_menuitem_is_two_line(
            MMI_fixed_list_menu.items[MMI_fixed_list_menu.highlighted_item], 
            MMI_fixed_list_menu.common_item_data);
}

#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#ifdef __MMI_UI_LIST_SLIDE_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_start
 * DESCRIPTION
 *  List highlight slide effect start call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_effect_slide_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_common_menuitem_base_struct *m;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;

    g_list_effect_slide_disable = 0;        

    if ((gui_get_current_list_effect() != MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE) || 
        (MMI_current_menu_type != LIST_MENU) ||
        (m->flags & UI_MENUITEM_DISABLE_HIGHLIGHT) ||
        gui_list_effect_slide_is_highlight_item_two_line() || 
        (m->focussed_filler->b == NULL))
    {
        g_list_effect_slide_disable = 1;

        return;
    }

    g_old_list_highlight_x = MMI_fixed_list_menu.highlight_x;
    g_old_list_highlight_y = MMI_fixed_list_menu.highlight_y;

    gui_effect_slide_create(
        g_old_list_highlight_x, 
        g_old_list_highlight_y,
        g_old_list_highlight_x,
        g_old_list_highlight_y,
        m->width,
        m->height,
        GUI_EFFECT_LIST_SLIDE_DURATION,
        gui_list_effect_slide_draw_highlight_filler,
        NULL,
        GUI_EFFECT_FRAME_FIRST);

    gui_effect_slide_close();
            
    old_menu_item_focussed_filler = m->focussed_filler;
    m->selected_filler = &slide_highlight_effect_transparent_filler;
    m->focussed_filler = &slide_highlight_effect_transparent_filler;

    gui_effect_set_blt_layer();

    gdi_layer_lock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_end
 * DESCRIPTION
 *  List highlight slide effect end call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_effect_slide_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_common_menuitem_base_struct *m;
    S32 start_frame;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_list_effect_slide_disable)
    {
        return;
    }

    m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;
    
    // gui_effect_restore_blt_layer();
 
    /* Do nothing if the highlight filler is changed. for example...theme change. */
    if (m->focussed_filler != &slide_highlight_effect_transparent_filler)
    {
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, 0, 0);

        return;
    }

    if (gui_list_effect_slide_is_highlight_item_two_line())
    {
        /* 
         * Do not restore the focussed filler since the filler has been changed to two line.
         * Currently, no sliding is allowed from any items to two-line items.
         */
        start_frame = GUI_EFFECT_FRAME_LAST;
    }
    else
    {   
        m->selected_filler = old_menu_item_focussed_filler;
        m->focussed_filler = old_menu_item_focussed_filler;           
        start_frame = GUI_EFFECT_FRAME_FIRST;
    }

    gui_effect_slide_create(
        g_old_list_highlight_x, 
        g_old_list_highlight_y,
        MMI_fixed_list_menu.highlight_x,
        MMI_fixed_list_menu.highlight_y,
        m->width,
        m->height,
        GUI_EFFECT_LIST_SLIDE_DURATION,
        gui_list_effect_slide_draw_highlight_filler,
        NULL,
        start_frame);

    m->selected_filler = old_menu_item_focussed_filler;
    m->focussed_filler = old_menu_item_focussed_filler;
    
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_stop
 * DESCRIPTION
 *  List highlight slide effect stop call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_effect_slide_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_effect_slide_close();
}


/*****************************************************************************
 * FUNCTION
 *  gui_list_effect_slide_is_enable
 * DESCRIPTION
 *  Check if the slide effect is enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  0: disable. 1: enable.
 *****************************************************************************/
S32 gui_list_effect_slide_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)(!g_list_effect_slide_disable);
}

#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */



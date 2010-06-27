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
 *   wgui_categories_calendar.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  calendar related funtions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "GlobalDefs.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "gui_themes.h"
#include "wgui_categories.h"
#include "wgui_status_icons.h"
#include "wgui_softkeys.h"
#include "wgui_categories_calendar.h"
#include "MMI_features.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "DateTimeGprot.h"
#include "DateTimeType.h"
#include "wgui_categories_defs.h"
#include "wgui_softkeys.h"
#include "wgui_categories_defs.h"
#include "CalendarDef.h"        /* Calendar image */
#include "CalendarProt.h"
#include "wgui_calendar.h"
#include "Gui_Setting.h"
#include "ScrMemMgrGprot.h"
#include "ScreenRotationGprot.h"

static U8* cat83_cell_cache_buf = NULL;
static U8* cat83_popup_cache_buf = NULL;
U8 *Cat8x_status_bar_string = NULL;


/*****************************************************************************
 * FUNCTION
 *  ExitCategory83Screen
 * DESCRIPTION
 *  exit function of category83
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory83Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat8x_status_bar_string = NULL; 
    reset_softkeys();

    wgui_calendar_close();

    if (cat83_cell_cache_buf != NULL)
    {
        mmi_frm_scrmem_free(cat83_cell_cache_buf);
        cat83_cell_cache_buf = NULL;
    }

    if (cat83_popup_cache_buf != NULL)
    {
        mmi_frm_scrmem_free(cat83_popup_cache_buf);
        cat83_popup_cache_buf = NULL;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory83HistorySize
 * DESCRIPTION
 *  Gets the history buffer size of category 83
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory83HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory83History
 * DESCRIPTION
 *  Gets the history buffer of category 83
 * PARAMETERS
 *  history_buffer      [?]     
 * RETURNS
 *  return history buffer
 *****************************************************************************/
U8 *GetCategory83History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat8x_set_status_string
 * DESCRIPTION
 *  Set status bar string for 83
 *  If app want to show string on status bar,this function must be called before ShowCategory8XScreen.
 * PARAMETERS
 *  message         [IN]    Message to show on status bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat8x_set_status_string(U8* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
    Cat8x_status_bar_string = message;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory83Screen
 * DESCRIPTION
 *  category screen of integrated calendar (monthly/weekly and menstral)
 * PARAMETERS
 *  bg_id                       [IN]        
 *  horizon_string_list         [IN]        Horizontal string list
 *  cell                    [IN]        2 dimension cell array
 *  num_of_row                  [IN]        Number of row
 *  num_of_column               [IN]        Number of column
 *  current_row                 [IN]        Row of current time
 *  current_column              [IN]        Column of current time
 *  highlighted_row             [IN]        Highlighted row
 *  highlighted_column          [IN]        Highlighted column
 *  cell_bg_fill_type           [IN]        
 *  cell_text_display_type      [IN]        
 *  cell_icon_display_type      [IN]        
 *  is_status_bar               [IN]        
 *  cell_fill_type(?)           [IN]        Cell bg color fill type
 *  title(?)                    [IN]        Title string
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory83Screen(
                    UI_image_ID_type bg_id,
                    U8 **horizon_string_list,
                    gui_calendar_cell_struct *cell,
                    U32 num_of_row,
                    U32 num_of_column,
                    U32 current_row,
                    U32 current_column,
                    U32 highlighted_row,
                    U32 highlighted_column,
                    U8 cell_bg_fill_type,
                    U8 cell_text_display_type,
                    U8 cell_icon_display_type,
                    MMI_BOOL is_status_bar,
                    U8 *str_LeftSoftkey,
                    U8 *str_rightSoftkey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    color c = *(current_MMI_theme->UI_black_color);
    color wc = *(current_MMI_theme->UI_white_color);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetupCategoryKeyHandlers();
    
    cat83_cell_cache_buf = (U8*)mmi_frm_scrmem_alloc(CALENDAR_CACHE_CELL_SIZE);
    cat83_popup_cache_buf = (U8*)mmi_frm_scrmem_alloc(CALENDAR_CACHE_POPUP_SIZE);
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
    wgui_calendar_create(GUI_CALENDAR_NORMAL, num_of_row, num_of_column, cat83_cell_cache_buf, cat83_popup_cache_buf);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
#else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
    wgui_calendar_create(GUI_CALENDAR_SMALL, num_of_row, num_of_column, cat83_cell_cache_buf, cat83_popup_cache_buf);
    #if defined(__MMI_MAINLCD_320X240__)
        wgui_set_wallpaper_on_bottom(MMI_TRUE);
    #endif
#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 

    wgui_calendar_set_bg(bg_id);
    wgui_calendar_set_cell_array(cell, cell_bg_fill_type, cell_text_display_type, cell_icon_display_type);

    wgui_calendar_set_current(current_row, current_column);
    wgui_calendar_set_highlight(highlighted_row, highlighted_column);
    
    if (Cat8x_status_bar_string != NULL)
    {
        dm_add_string((UI_string_type) Cat8x_status_bar_string, &MMI_default_font, wc, c, NULL);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_calendar_set_pen_unable();
        #endif /*__MMI_TOUCH_SCREEN__*/
    }
    ExitCategoryFunction = ExitCategory83Screen;
    RedrawCategoryFunction = dm_redraw_category_screen;
    GetCategoryHistory = GetCategory83History;
    GetCategoryHistorySize = GetCategory83HistorySize;
    
    set_left_softkey_label((UI_string_type)str_LeftSoftkey);
    set_right_softkey_label((UI_string_type)str_rightSoftkey);

    dm_data.s32CatId = MMI_CATEGORY83_ID;
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        dm_data.s32CatId = (is_status_bar == MMI_FALSE) ? MMI_CATEGORY83_ID_NO_STATUS : MMI_CATEGORY83_ID;
#endif
    dm_data.s32ScrId = GetActiveScreenId();
    if (is_status_bar == MMI_FALSE)
    {
        dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_NO_STATUS_BAR | DM_SET_NEW_LAYER_ACTIVE;    
        hide_status_icons();
    }
    else
    {
        dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SET_NEW_LAYER_ACTIVE;    
    }
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_query_snapshot_area
 * DESCRIPTION
 *  Get snapshot layer size
 * PARAMETERS
 *  x           [OUT]       X
 *  y           [OUT]       Y
 *  width       [OUT]       Width
 *  height      [OUT]       Height
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_query_snapshot_area(S32 *x, S32 *y, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = 0;
    *y = 0;
    *width = MAIN_LCD_DEVICE_WIDTH;
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)   	    
    *height =
        MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT -
        g_wgui_calendar.horizontal_select_height;
#else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
    *height = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - g_wgui_calendar.horizontal_select_height;
#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    *height -= g_wgui_calendar.infobox_height;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_save_snapshot
 * DESCRIPTION
 *  save snapshot for category 83
 * PARAMETERS
 *  layer_buffer        [OUT]       Application provides full screen size layer buffer
 *  buf_size            [IN]        The size of buffer for error checking
 *  filename            [IN]        File path and name in file system to be stored the snapshot
 * RETURNS
 *  S32             CAL_SNAPSHOT_RET_SUCCESS:    Success
 *                  CAL_SNAPSHOT_RET_BUFFER_ERR: Buffer error
 *                  CAL_SNAPSHOT_RET_GDI_ERR:    GDI error
 *****************************************************************************/
S32 wgui_cat83_save_snapshot(U8* layer_buffer, U32 buf_size, U8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, width, height, src_offset_y, src_hight;
    GDI_RESULT ret;
    U8 *src_layer_ptr = NULL;
    gdi_handle base_handle = GDI_NULL_HANDLE;
    gdi_handle src_layer_handle_1 = GDI_NULL_HANDLE;
    gdi_handle src_layer_handle_2 = GDI_NULL_HANDLE;
    gdi_handle dest_layer_handle = GDI_NULL_HANDLE;
    gdi_rect_struct dest_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)   		
    src_offset_y = MMI_STATUS_BAR_HEIGHT + g_wgui_calendar.horizontal_select_height;
#else
    src_offset_y = g_wgui_calendar.horizontal_select_height;
#endif 

    src_hight = MAIN_LCD_DEVICE_HEIGHT - src_offset_y - MMI_BUTTON_BAR_HEIGHT;
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    src_hight -= g_wgui_calendar.infobox_height;
#endif

    wgui_cat83_query_snapshot_area(&x, &y, &width, &height);
    
    if ((layer_buffer == NULL) || (buf_size < ((width * height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3)))
    {
        return CAL_SNAPSHOT_RET_BUFFER_ERR;
    }

    /* Create dest layer */
    ret = gdi_layer_create_using_outside_memory(x, y, width, height, &dest_layer_handle, layer_buffer, buf_size);
    if (ret != GDI_SUCCEED)
    {
        return CAL_SNAPSHOT_RET_GDI_ERR;
    }

    /* Blt all layer to temp */
    src_layer_handle_1 = dm_get_layer_handle(0);
    src_layer_handle_2 = dm_get_layer_handle(1);
    
    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_push_and_set_active(base_handle);
    gdi_layer_flatten_to_base(src_layer_handle_1, src_layer_handle_2, 0, 0);
    
    /* blt selected area */
    ret = gdi_layer_get_buffer_ptr(&src_layer_ptr);
    if (ret != GDI_SUCCEED)
    {        
        gdi_layer_pop_and_restore_active();
        gdi_layer_free(dest_layer_handle);
        wgui_calendar_update_base_layer();
        return CAL_SNAPSHOT_RET_GDI_ERR;
    }
    
    dest_clip.x1 = x;
    dest_clip.y1 = y;
    dest_clip.x2 = width;
    dest_clip.y2 = height;
    gdi_2d_memory_blt(
        src_layer_ptr,
        MAIN_LCD_DEVICE_WIDTH,
        0,
        src_offset_y,
        MAIN_LCD_DEVICE_WIDTH,
        src_hight,
        layer_buffer,
        MAIN_LCD_DEVICE_WIDTH,
        0,
        0,
        dest_clip,
        GDI_MAINLCD_BIT_PER_PIXEL); /* copy buffer data from calendar base layer to the new layer you just create */
    gdi_layer_pop_and_restore_active();
    wgui_calendar_update_base_layer();

    if (filename != NULL)
    {
        ret = gdi_layer_save_jpeg_file(dest_layer_handle, (PS8)filename);
        if (ret != GDI_SUCCEED)
        {
            gdi_layer_free(dest_layer_handle);
            return CAL_SNAPSHOT_RET_GDI_ERR;
        }
    }
    gdi_layer_free(dest_layer_handle);
    return CAL_SNAPSHOT_RET_SUCCESS;
}


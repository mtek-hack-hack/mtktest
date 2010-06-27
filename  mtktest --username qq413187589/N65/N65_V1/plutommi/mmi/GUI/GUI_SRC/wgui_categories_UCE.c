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
 *  wgui_categories_UCE.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Unified Composer Editor related categories. 
 *
 *  [Category280]       MMS/SMS Editor
 *
 * Author: Sukrit K Mehra (PMT0050)
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "StdC.h"
#include "L4Dr1.h"

#ifdef __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
/* framework related include */
#include "EventsGprot.h"
#include "FrameworkStruct.h"
#include "EventsDef.h"
#include "Unicodexdcl.h"
#include "DebugInitDef.h"
#include "app_mem.h"
#include "Gdi_include.h"
#include "app_str.h"

/* gui related include */
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_softkeys.h"
#include "wgui_categories.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_UCE.h"
#include "wgui_draw_manager.h"
#if defined(__MMI_AUDIO_PLAYER__) || defined (__MMI_VIDEO_PLAYER__)
#include "mdi_datatype.h"
#endif 
#ifdef __MMI_VIDEO_PLAYER__
#include "mdi_video.h"
#endif 
#if defined(__MMI_TOUCH_SCREEN__)
#include "EditorPenGprot.h"
#endif 

#ifdef __MMI_T9__
extern void InuptMethodEnterCategory5(void);
#elif defined __MMI_ZI__
extern void ZiInuptMethodEnterCategory5(void);
#elif defined __MMI_CSTAR__
extern void CstarInputMethodEnterCategory5( void );
#elif defined __MMI_KA__
extern void KonkaInuptMethodEnterCategory5(void);
#elif defined __MMI_ITAP__
/* under construction !*/
#endif 


/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
#define CAT280_MIN_LINE_HEIGHT 26
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 4
#elif defined(__MMI_MAINLCD_176X220__)
#define CAT280_MIN_LINE_HEIGHT 20
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 6
#elif defined(__MMI_MAINLCD_128X160__)
#define CAT280_MIN_LINE_HEIGHT 19
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 3
#else /* 128x128 display */
#define CAT280_MIN_LINE_HEIGHT 19
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 3
#endif 

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static wgui_uce_context_struct g_wgui_uce_cntx;
static wgui_uce_text_change_callback g_wgui_uce_text_change_callback = NULL;
static wgui_uce_get_message_size_callback g_wgui_uce_get_message_size_callback = NULL;

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
static U8 editor_scr_bg_opacity;
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */ 

#ifdef __MMI_VIDEO_PLAYER__
static MMI_BOOL cat280_got_size = MMI_FALSE;
static U16 cat280_video_width = 0;
static U16 cat280_video_height = 0;
#endif /* __MMI_VIDEO_PLAYER__ */

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*
 * GSM 7BIT EXTENSION CHARACTERS
 * 
 * 0x20AC => Euro Char
 * 0x5E => ^
 * 0x7B => {
 * 0x7D => }
 * 0x5C => \
 * 0x5B => [
 * 0x7E => ~
 * 0x5D => ]
 * 0x7C => |
 * 
 */

#define UCE_TEST_GSM_EXTENDED(c) \
(  (c==0x20AC)                   \
|| (c==0x5E)                     \
|| (c==0x7B)                     \
|| (c==0x7D)                     \
|| (c==0x5C)                     \
|| (c==0x5B)                     \
|| (c==0x7E)                     \
|| (c==0x5D)                     \
|| (c==0x7C)                     \
)


/*****************************************************************************
 * FUNCTION
 *  category280_text_input_callback
 * DESCRIPTION
 * Used to validate input with application's using callbacks to application layer.
 * This function itself is called on every character insertion/deletion from multiline input. 
 * Always updates the category's text info context. 
 * PARAMETERS
 *  event       [IN]        Event type
 *  C           [IN]        GSM 7BIT EXTENSION CHARACTERS
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category280_text_input_callback(gui_multi_line_input_box_change_event_enum event, U16 C)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_uce_text_info_struct post_change;
    wgui_uce_text_change_result_enum result = WGUI_UCE_TEXT_CHANGE_ALLOWED; /* for compile warning */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((void*)&post_change, (void*)&g_wgui_uce_cntx.text_info, sizeof(wgui_uce_text_info_struct));

    switch (event)
    {
        case GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR:
            ++post_change.char_count;
            if (UCE_TEST_GSM_EXTENDED(C))
            {
                ++post_change.extension_char_count;
            }
            else
            {
                if ((C >> 8) != 0x00)
                {
                    ++post_change.UCS2_count;
                }
            }
            post_change.utf8_msg_len += app_unicode_to_utf8_len(C); 
            break;
        case GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR:
            --post_change.char_count;
            if (UCE_TEST_GSM_EXTENDED(C))
            {
                --post_change.extension_char_count;
            }
            else
            {
                if ((C >> 8) != 0x00)
                {
                    --post_change.UCS2_count;
                }
            }
            post_change.utf8_msg_len -= app_unicode_to_utf8_len(C);
            break;
        case GUI_MULTI_LINE_INPUT_BOX_DELETEALL:
            memset((void*)&post_change, 0, sizeof(wgui_uce_text_info_struct));
            memset((void*)g_wgui_uce_cntx.text_buffer, 0, sizeof(U16));        /* First two bytes are NULL that means string lenght is zero */
            break;
        default:
            ASSERT(0);  /* Wrong Event Type From Multiline Input Box */
    }
    result = g_wgui_uce_text_change_callback(&post_change);

    switch (result)
    {
        case WGUI_UCE_TEXT_CHANGE_ALLOWED:
            memcpy((void*)&g_wgui_uce_cntx.text_info, (void*)&post_change, sizeof(wgui_uce_text_info_struct));        /* .: post change scenario accepted by UCA */
            return MMI_TRUE;
        case WGUI_UCE_TEXT_CHANGE_NOT_ALLOWED:
            return MMI_FALSE;
        default:
            ASSERT(0);  /* Wrong Return Type From UCA */
            return MMI_FALSE;
    }

}

#define ICON_MARGIN_Y 1
#define ICON_MARGIN_X 4


/*****************************************************************************
 * FUNCTION
 *  category280_draw_msg_size
 * DESCRIPTION
 *  Used to draw message size in top right/left corner depending upon r2lMMIFlag
 * PARAMETERS
 *  x1      [IN]        Start x
 *  y1      [IN]        Start Y
 *  x2      [IN]        End x
 *  y2      [IN]        End y
 * RETURNS
 *  void
 *****************************************************************************/
static void category280_draw_msg_size(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X240__)
    color info_bar_rgb = gui_color32(255, 255, 255, 75);
#else
    color info_bar_rgb = current_information_bar_theme->background_color;
#endif
    color font_color = *current_MMI_theme->remaining_length_text_color;
    U16 str[32];
    U8 msgtypestr[16];

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_320X240__)
    stFontAttribute *f = &MMI_medium_font;
#else /* defined(__MMI_TOUCH_SCREEN__) */ 
    stFontAttribute *f = &MMI_small_font;
#endif /* defined(__MMI_TOUCH_SCREEN__) */
    S32 w, h; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(f);

    gui_lock_double_buffer();

    if (g_wgui_uce_cntx.msg_type == WGUI_UCE_MSG_TYPE_MMS)
    {
        FLOAT size = (FLOAT) g_wgui_uce_get_message_size_callback(&g_wgui_uce_cntx.text_info, g_wgui_uce_cntx.msg_type) / (FLOAT) 1024.0;

        if (size != 0.0)
        {
            if (size < 0.1)
            {
                size = (FLOAT) 0.1;
            }
        }

        y2 -= ((y2 - y1) >> 1) + 2;

        mmi_ucs2_to_asc((S8*)msgtypestr, GetString(WGUI_UCE_MMS_STRING_ID));
        gui_sprintf(str, "%s: %.1f KB", msgtypestr, size);
    }
    else
    {
        mmi_ucs2_to_asc((S8*)msgtypestr, GetString(WGUI_UCE_SMS_STRING_ID));
        gui_sprintf(str, "%s: %d", msgtypestr, g_wgui_uce_get_message_size_callback(&g_wgui_uce_cntx.text_info, g_wgui_uce_cntx.msg_type));
    }

    gui_set_font(f);
    gui_measure_string(str, &w, &h);

    if (r2lMMIFlag)
    {
        x2 -= ((x2 - x1) >> 1);
    }
    else
    {
        x1 += ((x2 - x1) >> 1);
    }

    if ((x2 - x1) < w)
    {
        if (r2lMMIFlag)
        {
            x2 = x1 + w + 2;
        }
        else
        {
            x1 = x2 - w - 2;
        }
    }

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_reset_text_clip();
    gui_set_text_clip(x1, y1, x2, y2);


#if defined(__MMI_MAINLCD_320X240__)
        gui_set_transparent_source_layer(dm_get_scr_bg_layer());
        gui_fill_transparent_color(x1, y1, x2, y2, info_bar_rgb);
#else    
    {
        S32 bx1 = x1, bx2 = x2, mw, mh;
        U16 str2[32];

        if (g_wgui_uce_cntx.msg_type == WGUI_UCE_MSG_TYPE_MMS)
        {
            gui_sprintf(str2, "%s: %.1f KB", msgtypestr, 888.8f);
            gui_measure_string(str2, &mw, &mh);
            if ((bx2 - bx1) < mw)
            {
                if (r2lMMIFlag)
                {
                    bx2 = bx1 + mw + 2;
                }
                else
                {
                    bx1 = bx2 - mw - 2;
                }
            }
        }
        gui_push_clip();
        gui_set_clip(bx1, y1, bx2, y2);
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(bx1, y1, bx2, y2, GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gui_fill_rectangle(bx1, y1, bx2, y2, info_bar_rgb);
        }
        gui_pop_clip();
    }
#endif

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + 2 + w, y1 + (y2 - y1 - h) / 2);
    }
    else
    {
        gui_move_text_cursor(x2 - 2 - w, y1 + (y2 - y1 - h) / 2);
    }

    gui_set_font(f);
    gui_set_text_color(font_color);
    gui_print_text(str);

    gui_pop_clip();
    gui_unlock_double_buffer();
    //gui_BLT_double_buffer(x1, y1, x2, y2);
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  category280_draw_info_bar
 * DESCRIPTION
 *  Used to draw info bar 
 * PARAMETERS
 *  x1      [IN]        Start x
 *  y1      [IN]        Start Y
 *  x2      [IN]        End x
 *  y2      [IN]        End y
 * RETURNS
 *  void
 *****************************************************************************/
static void category280_draw_info_bar(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X240__)
    color info_bar_rgb = gui_color32(255, 255, 255, 75);
#else
    color info_bar_rgb = current_information_bar_theme->background_color;
#endif
    color font_color = *current_MMI_theme->remaining_length_text_color;
    U16 str[32];
    U8 msgtypestr[16];

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_320X240__)
    stFontAttribute *f = &MMI_medium_font;
#else 
    stFontAttribute *f = &MMI_small_font;
#endif 
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    /* Text */
    gui_reset_text_clip();
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_font(f);
    gui_set_text_color(font_color);

    if (g_wgui_uce_cntx.msg_type == WGUI_UCE_MSG_TYPE_MMS)
    {
        FLOAT size = (FLOAT) g_wgui_uce_get_message_size_callback(&g_wgui_uce_cntx.text_info, g_wgui_uce_cntx.msg_type) / (FLOAT) 1024.0;
        S32 icon_x1;
        S32 icon_x2;
        S32 icon_y1;
        S32 icon_y2;

        S32 y_offset = y1 + ((y2 - y1) >> 1) ;
        color slide_info_rbg;
        UI_HLS_color slide_info_hls;

        gui_RGB_to_HLS(info_bar_rgb, &slide_info_hls);
        slide_info_hls.l += 10;

        gui_HLS_to_RGB(slide_info_hls, &slide_info_rbg);

#if defined(__MMI_MAINLCD_320X240__)
        gui_set_transparent_source_layer(dm_get_scr_bg_layer());
        gui_fill_transparent_color(x1, y1, x2, y2, info_bar_rgb);
#else
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gui_fill_rectangle(x1, y1, x2, y2, info_bar_rgb);
            gui_fill_rectangle(x1, y1 + ((y2 - y1) >> 1), x2, y2, slide_info_rbg);
        }
#endif

        /* show input method */
#if defined(__MMI_MAINLCD_320X240__)
        if (r2lMMIFlag)
        {
            wgui_multiline_inputbox_show_current_input_method(x2 - ((x2 - x1) >> 2), y1, x2, y2);
        }
        else
        {
            wgui_multiline_inputbox_show_current_input_method(x1, y1, x1 + ((x2 - x1) >> 2), y2);
        }
#else
        if (r2lMMIFlag)
        {
            wgui_multiline_inputbox_show_current_input_method(x2 - ((x2 - x1) >> 1), y1, x2, y2 - ((y2 - y1) >> 1));
        }
        else
        {
            wgui_multiline_inputbox_show_current_input_method(x1, y1, x2 - ((x2 - x1) >> 1), y2 - ((y2 - y1) >> 1));
        }
#endif
        
        /* Slide Number */
        gui_sprintf(str, "(%d/%d)", g_wgui_uce_cntx.current_slide,g_wgui_uce_cntx.total_slides);
        gui_set_font(f);
        gui_measure_string(str, &width, &height);
#if defined(__MMI_MAINLCD_320X240__)
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + 2 + width, y_offset + (y2 - y_offset - height) / 2);
        }
        else
        {
            gui_move_text_cursor(x2 - 2 - width, y_offset + (y2 - y_offset - height) / 2);
        }
#else
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x2 - 2, y_offset + (y2 - y_offset - height) / 2);
        }
        else
        {
            gui_move_text_cursor(x2 - 2 - width, y_offset + (y2 - y_offset - height) / 2);
        }
#endif
        gui_set_font(f);
        gui_set_text_color(font_color);
        gui_print_text(str);
        /* Slide Icons */
        
        /* Show attachment icon */
        gui_measure_image((PU8) GetImage(WGUI_UCE_ATTACHFILE_ICON_IMAGE_ID), &width, &height);
#if defined(__MMI_MAINLCD_320X240__)
        icon_x1 = (r2lMMIFlag) ? (x2 - ((x2 - x1) >> 1)) : (x1 + ((x2 - x1) >> 2));
        icon_x2 = icon_x1 + width - 1;
        icon_y1 = y1 + ((y2 - y1 - height) >> 1);
        icon_y2 = icon_y1 + height - 1;
#else
        icon_x1 = current_MMI_theme->scrollbar_size;
        icon_x2 = icon_x1 + width - 1;
        icon_y1 = y_offset + ICON_MARGIN_Y;
        icon_y2 = icon_y1 + height - 1;
#endif

        gui_show_image(icon_x1, icon_y1, (PU8) GetImage(WGUI_UCE_ATTACHFILE_ICON_IMAGE_ID));

        if (g_wgui_uce_cntx.is_attachment == MMI_FALSE)
        {
            gui_greyscale_rectangle(
                icon_x1,
                icon_y1,
                icon_x2,
                icon_y2,
                MMI_BG_GREYSCALE_VALUE,
                MMI_BG_GREYSCALE_BLACK_VALUE);
        }

        /* show audio icon */
        gui_measure_image((PU8) GetImage(WGUI_UCE_AUDIO_ICON_IMAGE_ID), &width, &height);
        icon_x1 = icon_x2 + ICON_MARGIN_X;
        icon_x2 = icon_x1 + width - 1;

        gui_show_image(icon_x1, icon_y1, (PU8) GetImage(WGUI_UCE_AUDIO_ICON_IMAGE_ID));

        if (g_wgui_uce_cntx.is_audio == MMI_FALSE)
        {
            gui_greyscale_rectangle(
                icon_x1,
                icon_y1,
                icon_x2,
                icon_y2,
                MMI_BG_GREYSCALE_VALUE,
                MMI_BG_GREYSCALE_BLACK_VALUE);
        }

        /* show icon for video or image */
        if (g_wgui_uce_cntx.is_video == MMI_TRUE)
        {
            gui_measure_image((PU8) GetImage(WGUI_UCE_VIDEO_ICON_IMAGE_ID), &width, &height);
            icon_x1 = icon_x2 + ICON_MARGIN_X;
            icon_x2 = icon_x1 + width - 1;

            gui_show_image(icon_x1, icon_y1, (PU8) GetImage(WGUI_UCE_VIDEO_ICON_IMAGE_ID));
        }
        else
        {
            gui_measure_image((PU8) GetImage(WGUI_UCE_PICTURE_ICON_IMAGE_ID), &width, &height);
            icon_x1 = icon_x2 + ICON_MARGIN_X;
            icon_x2 = icon_x1 + width - 1;

            gui_show_image(icon_x1, icon_y1, (PU8) GetImage(WGUI_UCE_PICTURE_ICON_IMAGE_ID));
        }

		if (g_wgui_uce_cntx.is_image == MMI_FALSE && g_wgui_uce_cntx.is_video == MMI_FALSE)
        {
            gui_greyscale_rectangle(
                icon_x1,
                icon_y1,
                icon_x2,
                icon_y2,
                MMI_BG_GREYSCALE_VALUE,
                MMI_BG_GREYSCALE_BLACK_VALUE);
        }

        if (size != 0.0)
        {
            if (size < 0.1)
            {
                size = (FLOAT) 0.1;
            }
        }
        y2 -= ((y2 - y1) >> 1) + 2;
        mmi_ucs2_to_asc((S8*)msgtypestr, GetString(WGUI_UCE_MMS_STRING_ID));
        gui_sprintf(str, "%s: %.1f KB", msgtypestr, size);
    }
    else
    {

        mmi_ucs2_to_asc((S8*)msgtypestr, GetString(WGUI_UCE_SMS_STRING_ID)); 
        gui_sprintf(str, "%s: %d", msgtypestr, g_wgui_uce_get_message_size_callback(&g_wgui_uce_cntx.text_info, g_wgui_uce_cntx.msg_type));

#if defined(__MMI_MAINLCD_320X240__)
        gui_set_transparent_source_layer(dm_get_scr_bg_layer());
        gui_fill_transparent_color(x1, y1, x2, y2, info_bar_rgb);
#else
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gui_fill_rectangle(x1, y1, x2, y2, info_bar_rgb);
        }
#endif

        if (r2lMMIFlag)
        {
            wgui_multiline_inputbox_show_current_input_method(x2 - ((x2 - x1) >> 1), y1, x2, y2);
        }
        else
        {
            wgui_multiline_inputbox_show_current_input_method(x1, y1, x2 - ((x2 - x1) >> 1), y2);
        }
    }


    gui_set_font(f);
    gui_measure_string(str, &width, &height);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + 2 + width, y1 + (y2 - y1 - height) / 2);
    }
    else
    {
        gui_move_text_cursor(x2 - 2 - width, y1 + (y2 - y1 - height) / 2);
    }


    gui_set_font(f);
    gui_set_text_color(font_color);
    gui_print_text(str);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_show_preview_from_cached_buffer
 * DESCRIPTION
 *  used to show the contents of thumbnail buffer
 * PARAMETERS
 *  x_offset        [IN]        Start x
 *  y_offset        [IN]        Start Y
 *  width           [IN]        Area width
 *  height          [IN]        Area height
 * RETURNS
 *  Whether able to display conents of thumbnail buffer
 *****************************************************************************/
static void wgui_uce_show_preview_from_cached_buffer(S32 x_offset, S32 y_offset, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    S32 x, y, y_multiple;
    U16 *buf = (U16*) g_wgui_uce_cntx.thumbnail_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);


  if ((clip_x2 < x_offset) || (clip_x1 > x_offset + width - 1) || (clip_y2 < y_offset) ||
        (clip_y1 > y_offset + height - 1))
    {
        return; 
		/* sometimes mutli line input would want to draw the preview outside clip area */  
    }


    if (clip_x1 < x_offset)
    {
        clip_x1 = x_offset;
    }

    if (clip_y1 < y_offset)
    {
        clip_y1 = y_offset;
    }

    if (clip_x2 > x_offset + width - 1)
    {
        clip_x2 = x_offset + width - 1;
    }

    if (clip_y2 > y_offset + height - 1)
    {
        clip_y2 = y_offset + height - 1;
    }

    clip_x1 -= x_offset;
    clip_y1 -= y_offset;
    clip_x2 -= x_offset;
    clip_y2 -= y_offset;

    for (y = clip_y1; y <= clip_y2; y++)
    {
        y_multiple = y * width;
        for (x = clip_x1; x <= clip_x2; x++)
        {
            GDI_SET_BUFFER_PIXEL2(x + x_offset, y + y_offset, buf[y_multiple + x]);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_load_video_first_frame_into_cache
 * DESCRIPTION
 *  loads video first frame into category thumbnail buffer
 * PARAMETERS
 *  video_x             [IN]        Start x
 *  video_y             [IN]        Start Y
 *  video_width         [IN]        Area width
 *  video_height        [IN]        Area height
 * RETURNS
 *  Whether able to load video first frame into buffer
 *****************************************************************************/
static MMI_BOOL wgui_uce_load_video_first_frame_into_cache(S32 video_x, S32 video_y, S32 video_width, S32 video_height)
{

#ifdef __MMI_VIDEO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT mdi_ret;
    mdi_video_info_struct video_clip;

    gdi_handle cache_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("UCE: Video Frame Width: %d Height: %d", video_width, video_height);
    if (gdi_layer_create_using_outside_memory
        (video_x, video_y, video_width, video_height, &cache_layer, (U8*) g_wgui_uce_cntx.thumbnail_buffer,
         CAT280_THUMBNAIL_BUFFER_SIZE) != GDI_LAYER_SUCCEED)
    {
        return MMI_FALSE;
    }

    mdi_ret = mdi_video_ply_open_clip_file((S8*) g_wgui_uce_cntx.file_path, &video_clip);
    if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
    {
        /* draw the first frame of the video */
        memset((void*)g_wgui_uce_cntx.thumbnail_buffer, 0, CAT280_THUMBNAIL_BUFFER_SIZE);
        mdi_video_ply_seek_and_get_frame((U64) 0, cache_layer);
        mdi_video_ply_close_clip_file();
    }

    gdi_layer_free(cache_layer);

    return MMI_TRUE;
#else /* __MMI_VIDEO_PLAYER__ */ 
    return MMI_FALSE;
#endif /* __MMI_VIDEO_PLAYER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_load_image_into_cache
 * DESCRIPTION
 *  Load image into category thumbnail buffer
 * PARAMETERS
 *  img_x           [IN]        Start x
 *  img_y           [IN]        Start Y
 *  img_width       [IN]        Area width
 *  img_height      [IN]        Area height
 * RETURNS
 *  Whether able to load image into category buffer
 *****************************************************************************/
static MMI_BOOL wgui_uce_load_image_into_cache(S32 img_x, S32 img_y, S32 img_width, S32 img_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle cache_layer;
	MMI_BOOL ret=MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If not enough memory in buffer than layer creation will assert */

    PRINT_INFORMATION("UCE: Video Frame Width: %d Height: %d", img_width, img_height);
    if (gdi_layer_create_using_outside_memory
        (0, 0, img_width, img_height, &cache_layer, (U8*) g_wgui_uce_cntx.thumbnail_buffer,
         CAT280_THUMBNAIL_BUFFER_SIZE) != GDI_LAYER_SUCCEED)
    {
        return MMI_FALSE;
    }

    gdi_layer_push_and_set_active(cache_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_clip(0, 0, img_width - 1, img_height - 1);
    gdi_layer_set_position(img_x, img_y);
    gdi_draw_solid_rect(0, 0, img_width - 1, img_height - 1, GDI_COLOR_WHITE);
	
	if (gdi_image_draw_resized_file(0, 0, img_width, img_height, (S8*) g_wgui_uce_cntx.file_path) != GDI_SUCCEED)
	{
		PRINT_INFORMATION("UCE: GDI Failed to draw %s", (S8*) g_wgui_uce_cntx.file_path);
		ret = MMI_FALSE;
	}

    gdi_layer_pop_and_restore_active();
    gdi_layer_free(cache_layer);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_show_object_preview
 * DESCRIPTION
 *  Show video first frame or image preview:
 * PARAMETERS
 *  preview_x           [IN]        Start x
 *  preview_y           [IN]        Start Y
 *  preview_width       [IN]        Area width
 *  preview_height      [IN]        Area height
 * RETURNS
 *  whether able to display preview
 *****************************************************************************/
static MMI_BOOL wgui_uce_show_object_preview(S32 preview_x, S32 preview_y, S32 preview_width, S32 preview_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width = 0, img_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_uce_cntx.is_image)
    {
        if (GDI_SUCCEED != gdi_image_get_dimension_file((S8*) g_wgui_uce_cntx.file_path, &img_width, &img_height))
        {
            return MMI_FALSE;
        }
    }
    else if (g_wgui_uce_cntx.is_video)
    {
    #ifdef __MMI_VIDEO_PLAYER__
        if (cat280_got_size == MMI_FALSE)
        {
            MDI_RESULT mdi_ret;
            mdi_video_info_struct video_clip;

            mdi_ret = mdi_video_ply_open_clip_file((S8*) g_wgui_uce_cntx.file_path, &video_clip);
            cat280_got_size = MMI_TRUE;
            if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
            {
                img_height = cat280_video_height = video_clip.height;
                img_width = cat280_video_width = video_clip.width;
                mdi_video_ply_close_clip_file();
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else
        {
            img_width = cat280_video_width;
            img_height = cat280_video_height;
        }
    #else /* __MMI_VIDEO_PLAYER__ */ 
        return MMI_FALSE;
    #endif /* __MMI_VIDEO_PLAYER__ */ 
    }

    if ((img_width <= 0) || (img_height <= 0))
    {
        return MMI_FALSE;
    }

	/* drawable region larger than image */
	if ( preview_width > img_width  && preview_height > img_height )
	{
		/* align image at the center of preview rectangle */
		preview_x += ((preview_width - img_width) >> 1);
		preview_width = img_width;
		preview_y += ((preview_height - img_height) >> 1);
		preview_height = img_height;
	}
	else
	{
		S32 resized_offset_x, resized_offset_y, resized_width, resized_height;

		gdi_image_util_fit_bbox(
			preview_width,
			preview_height,
			img_width,
			img_height,
			&resized_offset_x,
			&resized_offset_y,
			&resized_width,
			&resized_height);

		/* check resized width and height */
		if (resized_width == 0)
		{
			resized_width = 1;
			resized_offset_x--;
		}
		if (resized_height == 0)
		{
			resized_height = 1;
			resized_offset_y--;
		}
        
		preview_width = resized_width;
		preview_height = resized_height;
		preview_x += resized_offset_x;
		preview_y += resized_offset_y;
	}

    /* Get Memory for thumbnail */
    if (g_wgui_uce_cntx.thumbnail_buffer == NULL)
    {
        /* If object is deleted, then screen has to be exited so the buffer will be deallocated in category exit */
        g_wgui_uce_cntx.thumbnail_buffer = (U8*) applib_mem_screen_alloc(CAT280_THUMBNAIL_BUFFER_SIZE);

        if (NULL == g_wgui_uce_cntx.thumbnail_buffer)
        {
            return MMI_FALSE;
        }

        if (g_wgui_uce_cntx.is_image)
        {
            if (MMI_FALSE == wgui_uce_load_image_into_cache(preview_x, preview_y, preview_width, preview_height))
            {
                return MMI_FALSE;
            }
        }
        else if (g_wgui_uce_cntx.is_video)
        {
            if (MMI_FALSE == wgui_uce_load_video_first_frame_into_cache(preview_x, preview_y, preview_width, preview_height))
            {
                return MMI_FALSE;
            }
        }

    }

    wgui_uce_show_preview_from_cached_buffer(preview_x, preview_y, preview_width, preview_height);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_show_default_preview
 * DESCRIPTION
 *  show default preview based on image id
 * PARAMETERS
 *  preview_x           [IN]        Start x
 *  preview_y           [IN]        Start Y
 *  preview_width       [IN]        Area width
 *  preview_height      [IN]        Area height
 * RETURNS
 *  whether able to display preview or not
 *****************************************************************************/
static MMI_BOOL wgui_uce_show_default_preview(S32 preview_x, S32 preview_y, S32 preview_width, S32 preview_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width = 0;
    S32 img_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_SUCCEED != gdi_image_get_dimension_id(g_wgui_uce_cntx.default_image_id, &img_width, &img_height))
    {
        return MMI_FALSE;
    }
	
	/* drawable region larger than image */
	if ( preview_width > img_width  && preview_height > img_height )
	{
		/* align image at the center of preview rectangle */
		preview_x += ((preview_width - img_width) >> 1);
		preview_width = img_width;
		preview_y += ((preview_height - img_height) >> 1);
		preview_height = img_height;
	}
	else
	{
		S32 resized_offset_x, resized_offset_y, resized_width, resized_height;

		gdi_image_util_fit_bbox(
			preview_width,
			preview_height,
			img_width,
			img_height,
			&resized_offset_x,
			&resized_offset_y,
			&resized_width,
			&resized_height);
		preview_width = resized_width;
		preview_height = resized_height;
		preview_x += resized_offset_x;
		preview_y += resized_offset_y;
	}

    if (GDI_SUCCEED != gdi_image_draw_resized_id(
                        preview_x,
                        preview_y,
                        preview_width,
                        preview_height,
                        g_wgui_uce_cntx.default_image_id))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  category280_draw_object_preview
 * DESCRIPTION
 *  Used to draw footer or header area of multiline input box
 * PARAMETERS
 *  yoffset     [IN]        Offset Y
 *  clip_x1     [IN]        Start X
 *  clip_y1     [IN]        Start Y
 *  clip_x2     [IN]        End X
 *  clip_y2     [IN]        End Y
 * RETURNS
 *  void
 *****************************************************************************/
static void category280_draw_object_preview(MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 draw_x, draw_y, draw_width, draw_height;
    MMI_BOOL error_code = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }
    
    ASSERT(g_wgui_uce_cntx.is_image || g_wgui_uce_cntx.is_video);       /* No Media still trying to preview ... assert */

    /* Wire Frame Color */
    c.alpha = current_MMI_theme->inputbox_selector_color->alpha;
    c.r = current_MMI_theme->inputbox_selector_color->r;
    c.g = current_MMI_theme->inputbox_selector_color->g;
    c.b = current_MMI_theme->inputbox_selector_color->b;

    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    /* Draw Wire Frame To Contain Image */
    if (r2lMMIFlag)
    {
        draw_x = current_MMI_theme->scrollbar_size + CAT280_HMARGIN - 1;
        draw_width = MMI_content_width - current_MMI_theme->scrollbar_size - (CAT280_HMARGIN << 1);
    }
    else
    {
        draw_x = CAT280_HMARGIN - 1;
        draw_width = MMI_content_width - current_MMI_theme->scrollbar_size - (CAT280_HMARGIN << 1);
    }

    draw_y = yoffset + CAT280_VMARGIN;
    draw_height = CAT280_THUMBNAIL_FRAME_HEIGHT - (CAT280_VMARGIN << 1);

    gui_draw_rectangle(draw_x, draw_y, draw_x + draw_width, draw_y + draw_height, c);

    /* Draw Preview Inside Frame */
    draw_x += CAT280_HMARGIN;
    draw_y += CAT280_VMARGIN;
    draw_width -= (CAT280_HMARGIN << 1);
    draw_height -= (CAT280_VMARGIN << 1);

    if ( g_wgui_uce_cntx.default_image_id )
    {
        error_code = wgui_uce_show_default_preview(draw_x, draw_y, draw_width, draw_height);
    }
    else
    {
        error_code = wgui_uce_show_object_preview(draw_x, draw_y, draw_width, draw_height);
    }

    if (error_code == MMI_FALSE)
    {
        S32 img_width, img_height;

		/* Since Draw has failed once */
		g_wgui_uce_cntx.default_image_id = WGUI_DEFAULT_PREVIEW_IMAGE_ID; 
        /* Draw Defualt Image Owned by UCE */
        if (GDI_SUCCEED != gdi_image_get_dimension_id(WGUI_DEFAULT_PREVIEW_IMAGE_ID, &img_width, &img_height))
        {
            /* Check Resources */
            ASSERT(0);
        }

		if ( draw_width > img_width  && draw_height > img_height )
		{
			/* align image at the center of preview rectangle */
            draw_x += ((draw_width - img_width) >> 1);
            draw_width = img_width;
            draw_y += ((draw_height - img_height) >> 1);
            draw_height = img_height;
		}
		else
		{
			S32 resized_offset_x, resized_offset_y, resized_width, resized_height;

			gdi_image_util_fit_bbox(
				draw_width,
				draw_height,
				img_width,
				img_height,
				&resized_offset_x,
				&resized_offset_y,
				&resized_width,
				&resized_height);
			draw_width = resized_width;
			draw_height = resized_height;
			draw_x += resized_offset_x;
			draw_y += resized_offset_y;
		}


        if (GDI_SUCCEED != gdi_image_draw_resized_id(draw_x, draw_y, draw_width, draw_height, WGUI_DEFAULT_PREVIEW_IMAGE_ID))
        {
            /* Check Resources: Image ID */
            ASSERT(0);
        }
		
    }

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory280Screen
 * DESCRIPTION
 *  Called on exit category: releases screen based memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory280Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_MMI_current_input_type();
    reset_softkeys();
    reset_multitaps();
    wgui_close_inputbox(); /* Calls *InputMethodExitCategory */
	
    if (g_wgui_uce_cntx.thumbnail_buffer != NULL)
    {
        applib_mem_screen_free(g_wgui_uce_cntx.thumbnail_buffer);
        g_wgui_uce_cntx.thumbnail_buffer = NULL;
    }

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    dm_set_scr_bg_opacity(editor_scr_bg_opacity);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

#ifdef __MMI_VIDEO_PLAYER__
    cat280_got_size = MMI_FALSE;
    cat280_video_width = 0;
    cat280_video_height = 0;
#endif /* __MMI_VIDEO_PLAYER__ */
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory280History
 * DESCRIPTION
 *  return pointer to GUI buffer
 * PARAMETERS
 *  history_buffer      [IN]     History buffer
 * RETURNS
 *  pointer to history buffer
 *****************************************************************************/
static U8 *GetCategory280History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_multiline_inputbox_category_history(MMI_CATEGORY280_ID, history_buffer, MMI_current_input_type);
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory280HistorySize
 * DESCRIPTION
 *  Get history size
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 Category 280 History Size
 *****************************************************************************/
static S32 GetCategory280HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(multiline_inputbox_category_history);
}


/*****************************************************************************
 * FUNCTION
 *  DrawCategory280ControlledArea
 * DESCRIPTION
 *  Draw Category Controlled Area
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCategory280ControlledArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Elvis for redrawing spelling or candidate boxes */
    if (RedrawSpellingOrCandidateBoxesFunction)
    {
        RedrawSpellingOrCandidateBoxesFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  category280_virtual_keypad_callback
 * DESCRIPTION
 *  resizes the multiline input box to accomodate editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category280_virtual_keypad_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_editor_resize_multiline_input_box_for_vk();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  category280_hide_multitap
 * DESCRIPTION
 *  Hides Multitap area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void category280_hide_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We fill the multitap bar across the screen instead of using MMI_multitap_x & MMI_multitap_width */
    color c = *(current_MMI_theme->information_bar_color);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_reset_clip();
    gui_fill_rectangle(0, MMI_multitap_y, UI_device_width - 1, MMI_multitap_y + MMI_multitap_height - 1, c);

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, MMI_multitap_y, UI_device_width - 1, MMI_multitap_y + MMI_multitap_height + 1);
}

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_insert_text
 * DESCRIPTION
 *  Copied text into category buffer and updates the text info of category.
 *  APP will call this to start to edit a slide whose info APP already has
 * PARAMETERS
 *  text_info       [OUT]     Text info buffer
 *  text_buffer     [OUT]     Text buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_uce_insert_text(wgui_uce_text_info_struct *text_info, U8 *text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Copy into text buffer for current slide */
    mmi_ucs2ncpy((PS8) g_wgui_uce_cntx.text_buffer, (PS8) text_buffer, g_wgui_uce_cntx.text_buffer_size);

    /* Copy text info as current text info */
    memcpy(&g_wgui_uce_cntx.text_info, text_info, sizeof(wgui_uce_text_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_get_current_text_info
 * DESCRIPTION
 *  APP uses this utility function to get the text info for current buffer
 * PARAMETERS
 *  current_text_info       [OUT]     Current text info
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_uce_get_current_text_info(wgui_uce_text_info_struct *current_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(current_text_info, &g_wgui_uce_cntx.text_info, sizeof(wgui_uce_text_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_get_text_info_for_buffer
 * DESCRIPTION
 *  APP can use this utility function to get the text info of buffer.
 *  Note: This function is used with wgui_uce_insert_text, to edit a saved text sms/mms as fresh.
 *  To insert template use wgui_uce_insert_text_template 
 * PARAMETERS
 *  text_info       [OUT]     Text info buffer
 *  text_buffer     [IN]      Text buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_uce_get_text_info_for_buffer(wgui_uce_text_info_struct *text_info, U8 *text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 counter;
    U32 len;
    U16 C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((PS8) text_buffer) ;

    /* What if the length of the text is more than the buffer the category has for insertion */
    /* We will update context only upto the limit we allow it to be inserted */

    if ((g_wgui_uce_cntx.text_buffer_size) < len)
    {
        len = g_wgui_uce_cntx.text_buffer_size;
    }

    text_info->char_count = len;

    for (counter = 0; counter < (len*ENCODING_LENGTH); counter += ENCODING_LENGTH)
    {
        /* text_buffer maybe at odd address so better get into a local */
        C = ((U16) text_buffer[counter + 1] << 8) | ((U8) text_buffer[counter]);
        if (UCE_TEST_GSM_EXTENDED(C))
        {
            ++text_info->extension_char_count;
        }
        else
        {
            if (text_buffer[counter + 1] != 0x00)
            {
                ++text_info->UCS2_count;
            }
        }
        text_info->utf8_msg_len += app_unicode_to_utf8_len(C); // TODO: Optimize multiple function calls. Replace with one function
    }
}

/*
 * Inserts partially. Input callbacks will be called and text info will be updated.automatically 
 */


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_insert_text_template
 * DESCRIPTION
 *  Inserts partially. Input callbacks will be called and text info will be updated.
 * PARAMETERS
 *  string          [IN]        String to insert
 *  no_of_char      [IN]        Non-used
 *  guibuffer       [IN]        History buffer
 * RETURNS
 *  number of characters inserted
 *****************************************************************************/
U32 wgui_uce_insert_text_template(U8 *string, U16 no_of_char, U8 *guibuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 char_count_before_insertion = g_wgui_uce_cntx.text_info.char_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_multiline_inputbox_append_string(
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        g_wgui_uce_cntx.text_buffer,
        g_wgui_uce_cntx.text_buffer_size,
        (U8*) string,
        guibuffer,
        MMI_CATEGORY280_ID,
        category280_text_input_callback);
    return (g_wgui_uce_cntx.text_info.char_count - char_count_before_insertion);
}


/*****************************************************************************
 * FUNCTION
 *  SetCategory280RightSoftkeyFunction
 * DESCRIPTION
 *  Used to set the right softkey function. This has to called by application.
 * PARAMETERS
 *  f       [IN]        RightSoftkey function 
 *  k       [IN]        Key event type
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory280RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(k);
    wgui_inputbox_RSK_function = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_add_object
 * DESCRIPTION
 *  Used to add an object, screen has to re-enter after add object
 * PARAMETERS
 *  object                  [IN]        Object to add
 *  file_path               [IN]        File path
 *  default_image_id        [IN]        Default image ID
 *  alignment_type          [IN]        Alignment Type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_uce_add_object(
        wgui_uce_msg_type_enum object,
        U16 *file_path,
        U16 default_image_id,
        wgui_uce_layout_type_enum alignment_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object)
    {
        case WGUI_UCE_OBJECT_TYPE_ATTACHMENT:
            g_wgui_uce_cntx.is_attachment = MMI_TRUE;
            break;
        case WGUI_UCE_OBJECT_TYPE_AUDIO:
            g_wgui_uce_cntx.is_audio = MMI_TRUE;
            break;
        case WGUI_UCE_OBJECT_TYPE_IMAGE:
            ASSERT(file_path || default_image_id);
            g_wgui_uce_cntx.is_image = MMI_TRUE;
            g_wgui_uce_cntx.layout = alignment_type;
            if (file_path)
            {
                mmi_ucs2ncpy((PS8) g_wgui_uce_cntx.file_path, (PS8) file_path, FMGR_MAX_PATH_LEN);
            }
            g_wgui_uce_cntx.default_image_id = default_image_id;
            break;
        case WGUI_UCE_OBJECT_TYPE_VIDEO:
            ASSERT(file_path || default_image_id);            
            g_wgui_uce_cntx.is_video = MMI_TRUE;
            g_wgui_uce_cntx.layout = alignment_type;
            if (file_path)
            {
                mmi_ucs2ncpy((PS8) g_wgui_uce_cntx.file_path, (PS8) file_path, FMGR_MAX_PATH_LEN);
            }            
            g_wgui_uce_cntx.default_image_id = default_image_id;
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_delete_object
 * DESCRIPTION
 *  This is used to delete an object, screen has to re-enter again.
 * PARAMETERS
 *  object      [IN]        Object to delete
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_uce_delete_object(wgui_uce_msg_type_enum object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object)
    {
        case WGUI_UCE_OBJECT_TYPE_ATTACHMENT:
            g_wgui_uce_cntx.is_attachment = MMI_FALSE;
            break;
        case WGUI_UCE_OBJECT_TYPE_AUDIO:
            g_wgui_uce_cntx.is_audio = MMI_FALSE;
            break;
        case WGUI_UCE_OBJECT_TYPE_IMAGE:
            g_wgui_uce_cntx.is_image = MMI_FALSE;
            break;
        case WGUI_UCE_OBJECT_TYPE_VIDEO:
            g_wgui_uce_cntx.is_video = MMI_FALSE;
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_uce_initialize_editor
 * DESCRIPTION
 *  Initialize the editor context called on entering new slides, editing saved msg etc
 * PARAMETERS
 *  text_buffer             [IN]        Text string buffer
 *  text_buffer_size        [IN]        Buffer size
 *  new_slide_number        [IN]        New slide number
 *  total_slide_number      [IN]        Total slide number
 *  get_msg_size            [IN]        Get message size callback
 *  text_change             [IN]        Text change callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_uce_initialize_editor(
        U8 *text_buffer,
        U16 text_buffer_size,
        U8 new_slide_number,
        U8 total_slide_number,
        wgui_uce_get_message_size_callback get_msg_size,
        wgui_uce_text_change_callback text_change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Tricky since the category is never uninitialised the callback remain forever active
       if user calls showcateogry w/o initialising, wrong callbacks will be called from showcategory */
    ASSERT(get_msg_size);
    ASSERT(text_change);
    memset(&g_wgui_uce_cntx, 0, sizeof(wgui_uce_context_struct));
    g_wgui_uce_cntx.current_slide = new_slide_number;
    g_wgui_uce_cntx.total_slides = total_slide_number;
    g_wgui_uce_cntx.text_buffer = text_buffer;
    g_wgui_uce_cntx.text_buffer_size = text_buffer_size;
    g_wgui_uce_text_change_callback = text_change;
    g_wgui_uce_get_message_size_callback = get_msg_size;
    g_wgui_uce_cntx.thumbnail_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory280Screen
 * DESCRIPTION
 *  This the show category function, basically we set some options on basis on msg type here.
 *  wgui_uce_initialize_editor should be called once before we call ShowCategory280Screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  msg_type                [IN]        Msg type
 *  input_method_type       [IN]        Input method type
 *  gui_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory280Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        wgui_uce_msg_type_enum msg_type,
        S16 input_method_type,
        U8 *gui_buffer)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 inputbox_height;
    U16 header_height = 0;
    U16 footer_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setupcontext */

    g_wgui_uce_cntx.msg_type = msg_type;    /* we need to store it in msg_type because we need to draw info bar. */

    /* Setup layout */
    if (g_wgui_uce_cntx.msg_type == WGUI_UCE_MSG_TYPE_MMS)
    {
        if (g_wgui_uce_cntx.is_video || g_wgui_uce_cntx.is_image)
        {
            if (g_wgui_uce_cntx.layout == WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_TOP)
            {
                header_height = CAT280_THUMBNAIL_FRAME_HEIGHT;
            }
            else if (g_wgui_uce_cntx.layout == WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_BOTTOM)
            {
                footer_height = CAT280_THUMBNAIL_FRAME_HEIGHT;
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    gui_lock_double_buffer();

    /* Title */
    MMI_title_string = (PU16) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);
    /* Short Cuts */
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    /* Softkeys */
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    /* Input box */
#ifdef __MMI_T9__
    InuptMethodEnterCategory5();
#elif defined __MMI_ZI__
    ZiInuptMethodEnterCategory5();
#elif defined __MMI_CSTAR__
    CstarInputMethodEnterCategory5();
#elif defined __MMI_KA__
    KonkaInuptMethodEnterCategory5();
#elif defined __MMI_ITAP__
/* under construction !*/
#endif 
    register_hide_multitap(category280_hide_multitap);

    wgui_setup_inputbox_ext(
        0,
        MMI_content_y,
        MMI_content_width,
        MMI_content_height - MMI_multitap_height,
        g_wgui_uce_cntx.text_buffer,
        g_wgui_uce_cntx.text_buffer_size,
        MMI_CATEGORY280_ID,
        get_string(right_softkey),
        get_image(right_softkey_icon),
        input_method_type,
        gui_buffer,
        1,
        UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE,
        (S16) (footer_height + header_height + CAT280_MIN_LINE_HEIGHT * 2),
        CAT280_MIN_LINE_HEIGHT,
        (S16) header_height,
        (S16) footer_height,
        NULL);

    inputbox_height = MMI_content_height - MMI_multitap_height - wgui_inputbox_information_bar_height;

    if (MMI_multiline_inputbox.height > inputbox_height)
    {
        gui_resize_multi_line_input_box(&MMI_multiline_inputbox, MMI_multiline_inputbox.width, inputbox_height);
    }

    /* Setup Input box Callbacks */
    wgui_multiline_inputbox_register_change_event_handler(category280_text_input_callback);

    if (g_wgui_uce_cntx.msg_type == WGUI_UCE_MSG_TYPE_MMS)
    {
        wgui_multiline_inputbox_register_infobar_callback(
            category280_draw_info_bar,
            category280_draw_msg_size,
#if defined(__MMI_MAINLCD_320X240__)
            30 /* about 2 times of small font height */
#else
            INFORMATION_BAR_HEIGHT << 1
#endif
            );
        if (g_wgui_uce_cntx.layout == WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_TOP)
        {
            MMI_multiline_inputbox.header_callback = category280_draw_object_preview;
        }
        else if (g_wgui_uce_cntx.layout == WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_BOTTOM)
        {
            MMI_multiline_inputbox.footer_callback = category280_draw_object_preview;
        }
    }
    else
    {
        wgui_multiline_inputbox_register_infobar_callback(
            category280_draw_info_bar,
            category280_draw_msg_size,
            INFORMATION_BAR_HEIGHT);
    }

    set_MMI_multitap_theme();

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    dm_get_scr_bg_opacity(&editor_scr_bg_opacity);
    dm_set_scr_bg_opacity((U8)(current_MMI_theme->bg_opacity_low));
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    gui_unlock_double_buffer();

    /* Setup standard category handler */
    ExitCategoryFunction = ExitCategory280Screen;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory280History, GetCategory280HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY280_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32flags |= DM_SHOW_VKPAD;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCategory280ControlledArea);
    dm_register_vkpad_callback(category280_virtual_keypad_callback);
    dm_redraw_category_screen();
}

#endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */


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
 *   gui_virtual_keyboard.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Virtual keyboard - UI component
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
#include "gui_virtual_keyboard.h"
#include "wgui_virtual_keyboard.h"
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_util.h"       /* get_image() */
#include "DebugInitDef.h"

/*
 * FIXME.
 *
 * 1. Currently we only support one matrix layout per keyboard.
 * 2. Use static memory to avoid out-of-memory in control buffer
 *
 */

extern BOOL r2lMMIFlag;

/***************************************************************************** 
* Define
*****************************************************************************/

#define VKBD_DIFF_HALF(a, b)  ((a) >= (b) ? (((a)-(b))>>1) : 0)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_clear_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_clear_selected_key(virtual_keyboard_selection_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->matrix_index = -1;
    s->matrix_column = -1;
    s->matrix_row = -1;
    s->custom_key_index = -1;
    s->key_width = 0;
    s->key_height = 0;
    s->key_x = 0;
    s->key_y = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_check_dead_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static BOOL gui_virtual_keyboard_check_dead_key(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ch)
    {
        case 0x60:  /* ` */
        case 0xB4:
        case 0x5E:  /* ^ */
        case 0xA8:
        case 0x7E:  /* ~ */
        case 0x02C7:
        case 0x0385:
        case 0x0384:
        case 0x00B8:
        case 0x02DB:
            return MMI_TRUE;
        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_char_center_align
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch                  [IN]        
 *  key_x               [IN]        
 *  key_y               [IN]        
 *  key_width           [IN]        
 *  key_height          [IN]        
 *  glyph_width         [OUT]         
 *  glyph_height        [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_show_char_center_align(
                UI_character_type ch,
                S32 key_x,
                S32 key_y,
                S32 key_width,
                S32 key_height,
                S32 *glyph_width,
                S32 *glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bbox_x, bbox_y, bbox_width, bbox_height;
    S32 char_x, char_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == (UI_character_type) '_')  /* '_' is special because it will get confused with '-' */
    {
        gui_measure_character(ch, glyph_width, glyph_height);
        char_x = key_x + VKBD_DIFF_HALF(key_width, *glyph_width);
        char_y = key_y + VKBD_DIFF_HALF(key_width, *glyph_height);
    }
    else
    {
        Get_CharBoundingBox(ch, glyph_width, glyph_height, &bbox_x, &bbox_y, &bbox_width, &bbox_height);

        char_x = key_x + VKBD_DIFF_HALF(key_width, bbox_width) - bbox_x;
        char_y = key_y + VKBD_DIFF_HALF(key_height, bbox_height) - bbox_y;

        /* HACK. the number of remaing pixels is odd. */
        /* It is not always correct depending on the baseline of the font database */
        /* The magic number bbox_y + "1" can be modified */
        if (((key_height - bbox_height) & 1) && (bbox_y > *glyph_height - bbox_height - bbox_y))
        {
            char_y++;
        }

    }
#if 0	
    // Huyanwei Modify it For Thai 
    gui_print_character_at_xy(ch, char_x, char_y);
#else

#if defined(LANG_TH_SUPPORT)
	if (( (ch > 0x0E00) && ( ch < 0x0E3B ) ) || ((ch > 0x0E3E) && (ch < 0x0E5C)))
	{
	
	    //gui_print_character_at_xy(ch, char_x, char_y);		    
 	   gdi_image_draw(char_x,char_y,(PU8) get_image(THAI_IMAGE_0+ch-0x0E00));	    
	    
	}
	else
#endif		
	{		
		gui_print_character_at_xy(ch, char_x, char_y);	
	}

#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_convert_custom_img
 * DESCRIPTION
 *  Convert some image ID of custom key because some images are displayed 
 *  differently in multi-block handwriting
 * PARAMETERS 
 *  v           [IN/OUT]         
 *  id          [IN]        image ID of custom key
 * RETURNS
 *  Converted image id
 *****************************************************************************/
static MMI_ID_TYPE gui_virtual_keyboard_convert_custom_img(virtual_keyboard *v, MMI_ID_TYPE id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Phone number keyboard layout coexist with multi-block but it has IMG_VKBD_CUSTOM_HIDE key */
    if (!(v->flags & GUI_VKBD_FLAG_MULTI_BLOCK_MODE) ||
        v->lang_type == GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER)
    {
        if (id == IMG_VKBD_CUSTOM_HIDE_SMALL)
            return IMG_VKBD_CUSTOM_HIDE;
        else
        return id;
    }
    else if (id == IMG_VKBD_CUSTOM_HIDE)
    {
        return IMG_VKBD_CUSTOM_SWITCH_HANDWRITING;
    }
    else if (id == IMG_VKBD_CUSTOM_SHOW)
    {
        return IMG_VKBD_CUSTOM_SWITCH_KEYBOARD;
    }
    else
    {
        return id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_is_key_disabled
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v           [IN/OUT]         
 *  event       [IN]        
 *  ch          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_key_disabled(
                    virtual_keyboard *v,
                    gui_virtual_keyboard_pen_enum event,
                    UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->allowed_characters)
    {
        MMI_BOOL disabled = MMI_TRUE;
	S32 i;

        /* gui_set_virtual_keyboard_allowed_characters() and 
           gui_set_virtual_board_disable_list() are mutually-exclusive */
	MMI_DBG_ASSERT(v->disabled_chars[0] == 0);
	/* we will allow IME to disable special symbols even allowed_characters has content */
	for (i = 0;  i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
	{
	    if (v->disabled_symbols[i] == GUI_VKBD_PEN_NONE)
	    {
	        break;
	    }
	    MMI_DBG_ASSERT(v->disabled_symbols[i] == GUI_VKBD_PEN_HIDE ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_SHOW ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_CAPSLOCK);
	}

        switch (event)
        {
                // TODO: GUI_VKBD_PEN_EUROSYMB is not supported
            case GUI_VKBD_PEN_HIDE:
            case GUI_VKBD_PEN_SHOW:
            case GUI_VKBD_PEN_CAPSLOCK:
		 {
		     disabled = MMI_FALSE;
		     for (i = 0;  i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
		     {
			  if (v->disabled_symbols[i] == GUI_VKBD_PEN_NONE)
			  {
			      break;
			  }
			  if (v->disabled_symbols[i] == event)
			  {
			      disabled = MMI_TRUE;
			      break;
			  }
		     }
		 }
		 break;

            case GUI_VKBD_PEN_BAKSPACE:
            case GUI_VKBD_PEN_DISPLAY_AREA:
                /* GUI_VKBD_PEN_DISPLAY_AREA is always enabled because it's display only */
                disabled = MMI_FALSE;
                break;

            case GUI_VKBD_PEN_NEWLINE:
                ch = (UI_character_type) '\n';
                event = GUI_VKBD_PEN_CHAR_I;
                break;

            case GUI_VKBD_PEN_SPACE:
                ch = (UI_character_type) ' ';
                event = GUI_VKBD_PEN_CHAR_I;
                break;

            case GUI_VKBD_PEN_SYMBPICKER:
            {
                /* Check existence of non-alphanumeric character */
                const UI_character_type *pch = v->allowed_characters;
                UI_character_type tmp;

                while ((tmp = *pch++) != 0)
                {
                    if (tmp == (UI_character_type) '\\' ||  /* Assume the next character to be punctuation */
                        !(tmp == (UI_character_type) '-' ||
                          (tmp >= (UI_character_type) 'a' && tmp <= (UI_character_type) 'z') ||
                          (tmp >= (UI_character_type) 'A' && tmp <= (UI_character_type) 'Z') ||
                          (tmp >= (UI_character_type) '0' && tmp <= (UI_character_type) '9')))
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                }
                break;
            }
        }

        if (event == GUI_VKBD_PEN_CHAR_I)
        {
            const UI_character_type *pch = v->allowed_characters;
            S32 idx;

            for (idx = 0; pch[idx]; idx++)
            {
                UI_character_type tmp = pch[idx];

                if (tmp == (UI_character_type) '-' && idx > 0 && pch[idx + 1])
                {
                    if (ch >= pch[idx - 1] && ch <= pch[idx + 1])
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                    idx++;
                }
                else
                {
                    if (tmp == (UI_character_type) '\\' && pch[idx + 1])
                    {
                        tmp = pch[++idx];
                    }

                    if (tmp == ch)
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                }
            }
        }

        return disabled;
    }
    else
    {
        if (event == GUI_VKBD_PEN_CHAR_I)
        {
            UI_character_type *ptr = v->disabled_chars, tmp;

            if (ch == 0)
            {
                return MMI_TRUE;
            }

            while ((tmp = *ptr++) != 0)
            {
                if (tmp == ch)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
        else if (event == GUI_VKBD_PEN_NONE)
        {
            return MMI_TRUE;
        }
        else
        {
            gui_virtual_keyboard_pen_enum *ptr = v->disabled_symbols, tmp;

            while ((tmp = *ptr++) != GUI_VKBD_PEN_NONE)
            {
                if (tmp == event)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
    }
}

#ifdef __MMI_TOUCH_SCREEN__

/* Return > 0 if dead key sequence is completed */


/*****************************************************************************
 * FUNCTION
 *  gui_get_dead_key_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_type           [IN]        
 *  input_string        [IN]         
 *  input_len           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_get_dead_key_symbol(
                    gui_virtual_keyboard_language_enum lang_type,
                    U16 *input_string,
                    S32 input_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 n_entry;
    const gui_keyboard_language_struct *lang;
    const gui_dead_key_map_struct *t;
    const gui_dead_key_symbol_struct *d;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lang = MMI_virtual_keyboard_language_map[lang_type].virtual_keyboard_language;

    if (!lang->enable_dead_key)
    {
        return 0;
    }

    t = &gui_dead_key_symbol_table[lang_type];

    n_entry = t->nentry;

    d = &t->dead_key_symbol[0];
    for (i = 0; i < n_entry; i++)
    {
        if (input_len != d->nInputLen)
        {
            continue;
        }

        if (memcmp(d->input_char, input_string, d->nInputLen * 2) == 0)
        {
            return d->output_char;
        }
        d++;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 *  ch      [OUT]     
 *  evt     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static BOOL gui_virtual_keyboard_get_selected_key(
                virtual_keyboard *v,
                UI_character_type *ch,
                gui_virtual_keyboard_pen_enum *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_language_struct *lang;
    virtual_keyboard_selection_struct *s = &v->selected_key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ch = 0;
    *evt = GUI_VKBD_PEN_NONE;

    lang = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_language;

    if (s->matrix_index < 0 && s->custom_key_index < 0)
    {
        return MMI_FALSE;
    }

    if (s->matrix_index >= 0)
    {
        MMI_DBG_ASSERT(s->matrix_column >= 0 && s->matrix_row >= 0);
        *evt = GUI_VKBD_PEN_CHAR_I;
        *ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else
    {
        *evt = lang->custom_key_type[s->custom_key_index];
        *ch = lang->custom_string[s->custom_key_index];
    }

    MMI_DBG_ASSERT(!*ch || *evt == GUI_VKBD_PEN_CHAR_I);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_dead_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 *  ch      [IN/OUT]     
 *  evt     [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_translate_dead_key(
                virtual_keyboard *v,
                UI_character_type *ch,
                gui_virtual_keyboard_pen_enum *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_language_struct *lang;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lang = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_language;

    if (lang->enable_dead_key)
    {
        if (*evt == GUI_VKBD_PEN_CHAR_I)
        {
            if (gui_virtual_keyboard_check_dead_key(*ch))
            {
                v->dead_key_input[0] = *ch;
                *ch = 0;
                *evt = GUI_VKBD_PEN_DEAD_KEY;
            }
            else if (v->dead_key_input[0])
            {
                /* Only two key combination is currently supported */
                UI_character_type ret;

                v->dead_key_input[1] = *ch;
                if ((ret = gui_get_dead_key_symbol(v->lang_type, v->dead_key_input, 2)) != 0)
                {
                    *ch = ret;
                }
                /* Otherwise, use the original key */

                v->dead_key_input[0] = 0;
            }
        }
        else
        {
            v->dead_key_input[0] = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_clear_dead_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_clear_dead_key(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->dead_key_input[0] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_cache_and_show_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_cache_and_show_selected_key(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2, y1, y2;
    S32 glyph_width, glyph_height;
    virtual_keyboard_selection_struct *s;
    const gui_keyboard_language_struct *lang;
    UI_character_type ch = 0;
    PU8 img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lang = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_language;
    s = &v->selected_key;

    MMI_DBG_ASSERT(s->custom_key_index >= 0 || s->matrix_index >= 0);

    if (s->custom_key_index >= 0 && lang->custom_key_type[s->custom_key_index] == GUI_VKBD_PEN_DISPLAY_AREA)
    {
        /* We do not select Display Area. Furthermore, it costs too much memory to cache the area */
        return;
    }

    x1 = s->key_x;
    y1 = s->key_y;
    x2 = x1 + s->key_width - 1;
    y2 = y1 + s->key_height - 1;

    /* Use a fixed size to avoid running out of certain control buffer bucket size */
    MMI_DBG_ASSERT((((S32) s->key_width * s->key_height * gdi_layer_get_bit_per_pixel() + 7) >> 3) <=
                   MMI_virtual_keyboard_bitmap_cache_size);
    v->selected_key_cached = 1;
#if 1
    {
        /* Workaround. We might not be able allocate large control buffer */
        #ifdef __MMI_MAINLCD_320X240__
            #if (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_32)
                    static char bitmap_buffer[6400];    
            #elif (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_24)
                    static char bitmap_buffer[4800];   
            #else
                    static char bitmap_buffer[3200];
            #endif
        #else    
            #if (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_32)
                    static char bitmap_buffer[5000];    
            #elif (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_24)
                    static char bitmap_buffer[3750];   
            #else
                    static char bitmap_buffer[2500];
            #endif
        #endif /*__MMI_MAINLCD_320X240__*/

        MMI_ASSERT(MMI_virtual_keyboard_bitmap_cache_size < sizeof(bitmap_buffer));
        v->selected_key_bitmap.buf_ptr = (U8*) bitmap_buffer;
    }
#else /* 1 */ 
/* under construction !*/
#endif /* 1 */ 

    gui_lock_double_buffer();

    gdi_layer_push_clip();

    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->selected_key_bitmap);

/* Under 128x160 resolution, we draw highlight to be filled whole cell because the character may touch the four edges of cell */
#ifdef __MMI_MAINLCD_128X160__ 
    gui_draw_filled_area(x1, y1, x2, y2, v->keyboard_theme->key_down_filler);
#else
    gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, v->keyboard_theme->key_down_filler);
#endif

    if (s->matrix_index >= 0)
    {
        ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else if (s->custom_key_index >= 0 && lang->custom_string[s->custom_key_index])
    {
        ch = lang->custom_string[s->custom_key_index];
    }
    else
    {
        img = get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[s->custom_key_index]));
    }

    if (ch)
    {
        gui_set_font(v->keyboard_theme->text_font);
        gui_set_text_color(v->keyboard_theme->key_down_text_color);

        gui_virtual_keyboard_show_char_center_align(
            ch,
            s->key_x,
            s->key_y,
            s->key_width,
            s->key_height,
            &glyph_width,
            &glyph_height);
    }

    if (img)
    {
        gui_measure_image(img, &glyph_width, &glyph_height);
        gui_show_image(
            s->key_x + VKBD_DIFF_HALF(s->key_width, glyph_width),
            s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height),
            img);
    }

    gdi_layer_pop_clip();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_unselect_key_from_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_show_unselect_key_from_cache(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!v->selected_key_cached)
    {
        return;
    }

    x1 = v->selected_key.key_x;
    y1 = v->selected_key.key_y;
    x2 = x1 + v->selected_key.key_width - 1;
    y2 = y1 + v->selected_key.key_height - 1;

    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_draw(x1, y1, &v->selected_key_bitmap);
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);

    /* gui_free(v->selected_key_bitmap.buf_ptr); */
    v->selected_key_bitmap.buf_ptr = NULL;
    v->selected_key_cached = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]         
 *  x       [IN]        
 *  y       [IN]        
 *  s       [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static BOOL gui_virtual_keyboard_translate_pen_position(
                virtual_keyboard *v,
                S16 x,
                S16 y,
                virtual_keyboard_selection_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_layout_struct *layout;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layout = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_layout;

    gui_virtual_keyboard_clear_selected_key(s);

    for (i = 0; i < layout->n_matrix_key_layout; i++)
    {
        const gui_matrix_key_layout_struct *matrix;
        S32 matrix_x, matrix_y;

        matrix = &layout->matrix_layout[i];
        matrix_x = v->x + matrix->x;
        matrix_y = v->y + matrix->y;
        if (PEN_CHECK_BOUND(x, y, matrix_x, matrix_y, matrix->width, matrix->height))
        {
            s->matrix_index = i;

            s->matrix_column = (x - matrix_x) / (matrix->key_width + matrix->horizontal_key_gap);
            if (s->matrix_column >= matrix->n_columns)
            {
                s->matrix_column = matrix->n_columns - 1;
            }

            s->matrix_row = (y - matrix_y) / (matrix->key_height + matrix->vertical_key_gap);
            if (s->matrix_row >= matrix->n_rows)
            {
                s->matrix_row = matrix->n_rows - 1;
            }

            s->key_width = matrix->key_width;
            s->key_height = matrix->key_height;
            s->key_x = matrix_x + s->matrix_column * (matrix->key_width + matrix->horizontal_key_gap);
            s->key_y = matrix_y + s->matrix_row * (matrix->key_height + matrix->vertical_key_gap);
            return MMI_TRUE;
        }
    }

    for (i = 0; i < layout->n_custom_keys; i++)
    {
        const gui_custom_key_layout_struct *custom_key;
        S32 custom_key_x, custom_key_y;

        custom_key = &layout->custom_keys[i];
        custom_key_x = v->x + custom_key->x;
        custom_key_y = v->y + custom_key->y;

        if (PEN_CHECK_BOUND(x, y, custom_key_x, custom_key_y, custom_key->key_width, custom_key->key_height))
        {
            s->custom_key_index = i;

            s->key_width = custom_key->key_width;
            s->key_height = custom_key->key_height;
            s->key_x = custom_key_x;
            s->key_y = custom_key_y;
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/***************************************************************************** 
* Global Variable
*****************************************************************************/
UI_virtual_keyboard_theme *current_virtual_keyboard_theme = NULL;

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_current_theme
 * DESCRIPTION
 *  Applies the current theme for virtual keyboard.
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_current_theme(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(current_virtual_keyboard_theme);
    v->keyboard_theme = current_virtual_keyboard_theme;
    v->keyboard_theme->flags |= current_virtual_keyboard_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_theme
 * DESCRIPTION
 *  Applies the current theme for virtual keyboard.
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_theme(virtual_keyboard *v, UI_virtual_keyboard_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t);
    v->keyboard_theme = t;
    v->keyboard_theme->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_virtual_keyboard
 * DESCRIPTION
 *  Create virtual keyboard object
 * PARAMETERS
 *  v               [IN/OUT]    Is the virtual keyboard object
 *  x               [IN]        Is the left-top cornerd
 *  y               [IN]        Is the left-top cornerd
 *  lang_type       [IN]        Is language type to be used for the keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_virtual_keyboard(virtual_keyboard *v, S16 x, S16 y, gui_virtual_keyboard_language_enum lang_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
    v->width = MMI_virtual_keyboard_language_map[lang_type].virtual_keyboard_layout->width;
    v->height = MMI_virtual_keyboard_language_map[lang_type].virtual_keyboard_layout->height;
    v->lang_type = lang_type;
    v->flags = 0;
    v->allowed_characters = NULL;
    v->disp_area_text[0] = (UI_character_type) '\0';
    v->disabled_chars[0] = (UI_character_type) '\0';
    v->disabled_symbols[0] = GUI_VKBD_PEN_NONE;
    gui_set_virtual_keyboard_current_theme(v);

    memset(v->dead_key_input, 0, sizeof(v->dead_key_input));

    gui_virtual_keyboard_clear_selected_key(&v->selected_key);
    v->selected_key_bitmap.buf_ptr = NULL;
    v->selected_key_cached = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_virtual_keyboard
 * DESCRIPTION
 *  Move the virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  x       [IN]        Is the left-top cornerd
 *  y       [IN]        Is the left-top cornerd
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_virtual_keyboard(virtual_keyboard *v, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_virtual_keyboard
 * DESCRIPTION
 *  Show the virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_virtual_keyboard(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, y1, x2, y2;
    S32 glyph_width, glyph_height;
    UI_character_type key_char;
    S16 key_width, key_height;
    S16 key_x, key_y;
    const gui_keyboard_layout_struct *layout;
    const gui_keyboard_language_struct *lang;
    S16 i, j, k;
    BOOL enable_dead_key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = v->x;
    y1 = v->y;
    x2 = v->x + v->width - 1;
    y2 = v->y + v->height - 1;

    layout = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_layout;
    lang = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_language;

    enable_dead_key = lang->enable_dead_key;

    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);

    gui_show_image(x1, y1, (PU8) get_image(layout->ImageId));

    for (k = 0; k < layout->n_matrix_key_layout; k++)
    {
        S16 horizontal_text_gap, vertical_text_gap;
        S16 n_matrix_column, n_matrix_row;
        const gui_matrix_key_layout_struct *matrix;
        const UI_character_type *matrix_string;

        matrix = &layout->matrix_layout[k];
        horizontal_text_gap = matrix->horizontal_key_gap;
        vertical_text_gap = matrix->vertical_key_gap;

        n_matrix_column = matrix->n_columns;
        n_matrix_row = matrix->n_rows;

        key_x = v->x + matrix->x;
        key_y = v->y + matrix->y;
        key_width = matrix->key_width;
        key_height = matrix->key_height;

        gui_set_font(v->keyboard_theme->text_font);
        gui_set_text_color(v->keyboard_theme->key_up_text_color);

        for (i = 0; i < n_matrix_row; i++)
        {
            matrix_string = lang->matrix_string[i];
            for (j = 0; j < n_matrix_column; j++)
            {
                BOOL restore_text_color = MMI_FALSE;

                key_char = matrix_string[j];
                if (enable_dead_key && gui_virtual_keyboard_check_dead_key(key_char))
                {
                    gui_set_text_color(v->keyboard_theme->dead_key_up_text_color);
                    restore_text_color = MMI_TRUE;
                }
                gui_virtual_keyboard_show_char_center_align(
                    key_char,
                    key_x,
                    key_y,
                    key_width,
                    key_height,
                    &glyph_width,
                    &glyph_height);
                if (restore_text_color)
                {
                    gui_set_text_color(v->keyboard_theme->key_up_text_color);
                }

                if (gui_virtual_keyboard_is_key_disabled(v, GUI_VKBD_PEN_CHAR_I, key_char))
                {
                    gui_greyscale_rectangle(
                        key_x,
                        key_y,
                        key_x + key_width - 1,
                        key_y + key_height - 1,
                        MMI_VKBD_GRAYSCALE_VALUE,
                        MMI_BG_GREYSCALE_BLACK_VALUE);
                }

                key_x += horizontal_text_gap + key_width;
            }
            key_x = v->x + matrix->x;
            key_y += vertical_text_gap + key_height;
        }
    }

    for (i = 0; i < layout->n_custom_keys; i++)
    {
        PU8 custom_image;

        key_x = v->x + layout->custom_keys[i].x;
        key_y = v->y + layout->custom_keys[i].y;
        key_width = layout->custom_keys[i].key_width;
        key_height = layout->custom_keys[i].key_height;
        key_char = lang->custom_string[i];

        if (lang->custom_key_type[i] == GUI_VKBD_PEN_DISPLAY_AREA)
        {
            gui_set_text_color(v->keyboard_theme->disp_area_text_color);
            gui_measure_string((UI_string_type) v->disp_area_text, &glyph_width, &glyph_height);
            gui_move_text_cursor(
                key_x + VKBD_DIFF_HALF(key_width, glyph_width),
                key_y + VKBD_DIFF_HALF(key_height, glyph_height));
            gui_print_text((UI_string_type) v->disp_area_text);

            /* Restore text color */
            gui_set_text_color(v->keyboard_theme->key_up_text_color);
        }
        else if (!key_char)
        {
            custom_image = get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[i]));
            gui_measure_image(custom_image, &glyph_width, &glyph_height);
            gui_show_image(
                key_x + VKBD_DIFF_HALF(key_width, glyph_width),
                key_y + VKBD_DIFF_HALF(key_height, glyph_height),
                custom_image);
        }
        else
        {
            BOOL restore_text_color = MMI_FALSE;

            if (enable_dead_key && gui_virtual_keyboard_check_dead_key(key_char))
            {
                gui_set_text_color(v->keyboard_theme->dead_key_up_text_color);
                restore_text_color = MMI_TRUE;
            }
            gui_virtual_keyboard_show_char_center_align(
                key_char,
                key_x,
                key_y,
                key_width,
                key_height,
                &glyph_width,
                &glyph_height);
            if (restore_text_color)
            {
                gui_set_text_color(v->keyboard_theme->key_up_text_color);
            }
        }

        if (gui_virtual_keyboard_is_key_disabled(v, lang->custom_key_type[i], key_char))
        {
            gui_greyscale_rectangle(
                key_x,
                key_y,
                key_x + key_width - 1,
                key_y + key_height - 1,
                MMI_VKBD_GRAYSCALE_VALUE,
                MMI_BG_GREYSCALE_BLACK_VALUE);
        }
    }

    gui_pop_clip();
    gui_pop_text_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_display_area
 * DESCRIPTION
 *  Update text displayed on display area
 * PARAMETERS
 *  v           [IN/OUT]        
 *  string      [IN]        String to be displayed in display area
 *  redraw      [IN]        Whether to redraw the keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_display_area(virtual_keyboard *v, const U8 *string, BOOL redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_layout_struct *layout;
    const gui_keyboard_language_struct *lang;
    S32 x1, y1, x2, y2, glyph_width, glyph_height;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((S8*) v->disp_area_text, (const S8*)string, MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN);

    /* redraw the area only */
    if (redraw)
    {
        layout = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_layout;
        lang = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_language;

        gui_set_font(v->keyboard_theme->text_font);
        for (i = 0; i < layout->n_custom_keys; i++)
        {
            if (lang->custom_key_type[i] == GUI_VKBD_PEN_DISPLAY_AREA)
            {
                const gui_custom_key_layout_struct *custom_key = &layout->custom_keys[i];

                x1 = v->x + custom_key->x;
                y1 = v->y + custom_key->y;
                x2 = x1 + custom_key->key_width - 1;
                y2 = y1 + custom_key->key_height - 1;

                gui_lock_double_buffer();
                gui_push_clip();
                gui_push_text_clip();
                gui_set_clip(x1, y1, x2, y2);
                gui_set_text_clip(x1, y1, x2, y2);

                gui_show_image(x1, y1, get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[i])));
                gui_set_text_color(v->keyboard_theme->disp_area_text_color);
                gui_measure_string((UI_string_type) v->disp_area_text, &glyph_width, &glyph_height);
                gui_move_text_cursor(
                    x1 + VKBD_DIFF_HALF(custom_key->key_width, glyph_width),
                    y1 + VKBD_DIFF_HALF(custom_key->key_height, glyph_height));
                gui_print_text((UI_string_type) v->disp_area_text);

                gui_pop_clip();
                gui_pop_text_clip();
                gui_unlock_double_buffer();
                gui_BLT_double_buffer(x1, y1, x2, y2);

                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_multi_block_mode
 * DESCRIPTION
 *  Enter or leave multi-block handwriting mode. 
 *
 *  In multi-block handwriting mode, some keyboard icons are displayed differently.
 * PARAMETERS
 *  v           [IN/OUT]        
 *  enabled     [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_multi_block_mode(virtual_keyboard *v, MMI_BOOL enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enabled)
    {
        v->flags |= GUI_VKBD_FLAG_MULTI_BLOCK_MODE;
    }
    else
    {
        v->flags &= ~GUI_VKBD_FLAG_MULTI_BLOCK_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_allowed_characters
 * DESCRIPTION
 *  Only the allowd characters can be input on keyboard.
 *  This function and gui_set_virtual_board_disable_list() are mutually-exclusive.
 *  
 *  Control keys such as GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_SHOW... are enabled because
 *  they are not related to character insertion.
 *  
 *  `allowed_characters' may contain '-' for consecutive characters
 *  (Ex. 'a-z' for characters from a to z.)
 *  If we want to accept "-", please write it as '\-'.
 *  For example, '\-0-9.' represents "-0123456789."
 *  
 *  Example of valid characters in email addresss:
 *  wgui_set_virtual_keyboard_allowed_characters((const UI_character_type *) L"+_\\-.@A-Za-z0-9");
 *  (it is not a complete list of all characters allowed in RFC, but it satisfies almost all cases)
 * PARAMETERS
 *  v                   [IN/OUT]    Virtual keyboard
 *  allowed_chars       [IN]        Allowed characters
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_allowed_characters(virtual_keyboard *v, const UI_character_type *allowed_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->allowed_characters = allowed_chars;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_board_disable_list
 * DESCRIPTION
 *  Disable some keys on keyboard.
 *  This function and gui_set_virtual_keyboard_allowed_characters() are mutually-exclusive.
 * PARAMETERS
 *  v                       [IN/OUT]    Virtual keyboard
 *  disabled_chars          [IN]        Null-terminated array of disabled unicode characters
 *  disabled_symbols        [IN]        Ended by GUI_VKBD_PEN_NONE
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_board_disable_list(
        virtual_keyboard *v,
        const UI_character_type *disabled_chars,
        const gui_virtual_keyboard_pen_enum *disabled_symbols)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setup v->disabled_chars[] */
    for (i = 0; i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
    {
        if (!disabled_chars[i])
        {
            break;
        }

        v->disabled_chars[i] = disabled_chars[i];
    }

    MMI_DBG_ASSERT(i < MMI_VKBD_MAX_DISABLED_KEYS || !disabled_chars[i]);
    v->disabled_chars[i] = 0;

    /* Setup v->disabled_symbols[] */
    for (i = 0; i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
    {
        if (disabled_symbols[i] == GUI_VKBD_PEN_NONE)
        {
            break;
        }

        v->disabled_symbols[i] = disabled_symbols[i];
    }

    MMI_DBG_ASSERT(i < MMI_VKBD_MAX_DISABLED_KEYS || (disabled_symbols[i] == GUI_VKBD_PEN_NONE));
    v->disabled_symbols[i] = GUI_VKBD_PEN_NONE;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v               [IN/OUT]         
 *  x               [IN]        
 *  y               [IN]        
 *  pen_event       [IN]        
 *  vkbd_event      [OUT]         
 *  vkbd_param      [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_virtual_keyboard_translate_pen_event(
        virtual_keyboard *v,
        S16 x,
        S16 y,
        mmi_pen_event_type_enum pen_event,
        gui_virtual_keyboard_pen_enum *vkbd_event,
        gui_pen_event_param_struct *vkbd_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    const gui_keyboard_language_struct *lang;
    UI_character_type ch;
    gui_virtual_keyboard_pen_enum evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *vkbd_event = GUI_VKBD_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(vkbd_param);

    lang = MMI_virtual_keyboard_language_map[v->lang_type].virtual_keyboard_language;

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            v->key_down_accepted = MMI_FALSE;

            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
            {
                if (gui_virtual_keyboard_translate_pen_position(v, x, y, &v->selected_key))
                {
                    gui_virtual_keyboard_get_selected_key(v, &ch, &evt);
                    if ((evt == GUI_VKBD_PEN_NONE) || gui_virtual_keyboard_is_key_disabled(v, evt, ch))
                    {
                        /* Do nothing */
                    }
                    else
                    {
                        v->key_down_accepted = MMI_TRUE;

                        gui_virtual_keyboard_cache_and_show_selected_key(v);
                        /* 
                         * If Pen Down and Pen Up comes together, we should temporarily suspend MMI task. 
                         * Otherwise, user can not see pen down due to delayed LCM update.
                         */
                        kal_sleep_task(kal_milli_secs_to_ticks(30));
                    }
                }
            }
            else
            {
                return MMI_FALSE;
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (v->key_down_accepted)
            {
                virtual_keyboard_selection_struct s;

                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) &&
                    gui_virtual_keyboard_translate_pen_position(v, x, y, &s))
                {
                    if (memcmp(&v->selected_key, &s, sizeof(s)))
                    {
                        gui_virtual_keyboard_show_unselect_key_from_cache(v);
                        memcpy(&v->selected_key, &s, sizeof(s));
                        gui_virtual_keyboard_get_selected_key(v, &ch, &evt);
                        if (!((evt == GUI_VKBD_PEN_NONE) || gui_virtual_keyboard_is_key_disabled(v, evt, ch)))
                        {
                            gui_virtual_keyboard_cache_and_show_selected_key(v);
                        }
                    }
                }
                else
                {
                    gui_virtual_keyboard_show_unselect_key_from_cache(v);
                    gui_virtual_keyboard_clear_selected_key(&v->selected_key);
                }
            }

            break;

        case MMI_PEN_EVENT_UP:
            if (v->key_down_accepted)
            {
                gui_virtual_keyboard_show_unselect_key_from_cache(v);

                if (gui_virtual_keyboard_get_selected_key(v, &ch, &evt))
                {
                    if (gui_virtual_keyboard_is_key_disabled(v, evt, ch))
                    {
                        /*Do nothing*/
                    }
                    else
                    {
                    gui_virtual_keyboard_translate_dead_key(v, &ch, &evt);

                    if (evt == GUI_VKBD_PEN_SPACE)
                    {
                        evt = GUI_VKBD_PEN_CHAR_I;
                        ch = (UI_character_type) ' ';
                    }
                    else if (evt == GUI_VKBD_PEN_DEAD_KEY)
                    {
                        evt = GUI_VKBD_PEN_NONE;
                    }

                    *vkbd_event = evt;
                    if (evt == GUI_VKBD_PEN_CHAR_I)
                    {
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(vkbd_param, (int)ch);
                    }
                }
            }
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            gui_virtual_keyboard_show_unselect_key_from_cache(v);
            gui_virtual_keyboard_clear_dead_key(v);
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            /* Do nothing */
            break;
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


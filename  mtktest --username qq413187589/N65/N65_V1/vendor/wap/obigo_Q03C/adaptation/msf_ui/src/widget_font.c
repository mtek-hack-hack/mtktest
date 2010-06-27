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
 * widget_font.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Widget font processing
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "app_str.h"
#include "brs_cfg.h"    /* Optimize font height */

/****************************************************************
 Font
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_convert_to_system_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  font        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
stFontAttribute widget_convert_to_system_font(MsfFont *font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute f = {0, 0, 0, MEDIUM_FONT, 0, 1};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Our implementation fills zero for default value of style object */
    if (font->size == 0)
    {
        f.size = MEDIUM_FONT;
    }
    else if (font->size < BRS_CFG_LE_CSS_MEDIUM_FONT_SIZE_PX)
    {
        f.size = SMALL_FONT;
    }
    else if (font->size < BRS_CFG_LE_CSS_LARGE_FONT_SIZE_PX)
    {
        f.size = MEDIUM_FONT;
    }
    else
    {
        f.size = LARGE_FONT;
    }

    if (font->weight >= 6)
    {
        f.bold = 1;
    }

    if (font->fontStyle == MsfFontItalic)
    {
        f.italic = 1;
    }
    else if (font->fontStyle == MsfFontOblique)
    {
        f.oblique = 1;
    }

    return f;
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_string_width_deviation
 * DESCRIPTION
 *  Get the deviation of the string/word if the font style is bold, italic or oblique
 * PARAMETERS
 *  font			[IN]
 *  height			[IN]
 * RETURNS
 *  
 *****************************************************************************/
int widget_get_string_width_deviation(stFontAttribute font, int height)
{
    int deviation = 0;

    if (font.bold)
    {
        deviation = 1;
    }
    if (font.italic || font.oblique)
    {
        /* ref. gdi_tilt_table[] in gdi_font.c */
        deviation = height>>2;
    }
    return deviation;
}


/* extension */
/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetSystemFontSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetSystemFontSize()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // TODO: broken
    unsigned char i = (unsigned char)FontSizeEnum();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (i)
    {
        case SMALL_FONT:
            return 16;

        case MEDIUM_FONT:
            return 20;

        case LARGE_FONT:
            return 24;

        default:
            return 20;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetFontGetFamily
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nrOfFonts               [IN]        
 *  fontNames               [IN]         
 *  genericFont             [IN]        
 *  fontFamilyNumber        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetFontGetFamily(
        int nrOfFonts,
        char *fontNames,
        MsfGenericFont genericFont,
        MsfFontFamilyNumber *fontFamilyNumber)
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
 *  HDIa_widgetFontGetValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  font        [IN]     
 *  ascent      [OUT]     
 *  height      [OUT]     
 *  xHeight     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetFontGetValues(MsfFont *font, int *ascent, int *height, int *xHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h;  /* System font size */
    stFontAttribute f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f = widget_convert_to_system_font(font);
    // TODO: not handle different font families
    h = (int)Get_CharHeightOfAllLang(f.size);

    /* 
     * We need to return the right ascent, height and xHeight.
     * It will influence the focused rectangle and the gadget layout.
     */
    if (ascent)
    {
        *ascent = h * 15 / 17;
    }    
    if (xHeight)
    {
        *xHeight = *ascent * 2 / 3;
    }

    h += WIDGET_FONT_TOP_SPACING + WIDGET_FONT_BOTTOM_SPACING;  /* one pixel for spacing at top, two pixel for underline & bottom */
    if (height)
    {
        *height = h;
    }

    return 1;
}

/* Reference: widget_paint_gadget_input() */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGetInputboxWidthBySize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  char_cnt        [IN]        
 *  is_passwd       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtGetInputboxWidthBySize(int char_cnt, kal_bool is_passwd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 h, w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_passwd)
    {
        gui_measure_character(current_multi_line_input_box_theme->mask_character, &w, &h);
    }
    else
    {
        /* Because our font is variable width character, it is hard to calculate the real string width. */
        gui_measure_character((UI_character_type) 'A', &w, &h);
    }

    /* FIXME.  no predefined theme component for MMI_multiline_inputbox.text_x */
	return char_cnt * (w + current_multi_line_input_box_theme->text_gap) + MMI_multiline_inputbox.text_x * 2;
}

/****************************************************************
 *
 * Text rendering
 *
 ****************************************************************/

/*
 * FIXME. We should further expand widget_is_space(CHR_AT(str, index)) into 
 * * another macro because CHR_AT() is slow.
 */

#ifdef WIDGET_SMIL_DISABLE_WORD_WRAPPING
static int g_widget_ignore_space = 0;


/*****************************************************************************
 * FUNCTION
 *  widget_is_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  chr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_is_space(kal_uint16 chr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_widget_ignore_space)
    {
        return 0;
    }
    else
    {
        return chr <= CHR(' ');
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_not_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  chr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_is_not_space(kal_uint16 chr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_widget_ignore_space)
    {
        return 1;
    }
    else
    {
        return chr > CHR(' ');
    }
}
#else /* WIDGET_SMIL_DISABLE_WORD_WRAPPING */ 
#define widget_is_space(chr)        ((chr) <= CHR(' '))
#define widget_is_not_space(chr)    ((chr) > CHR(' '))
#endif /* WIDGET_SMIL_DISABLE_WORD_WRAPPING */ 

#define widget_goto_space(str,from)                         \
   {                                                        \
      while(CHR_AT(str,from)                                \
         && widget_is_not_space(CHR_AT(str,from)))          \
         (from)++;                                          \
      if(!CHR_AT(str,from)) from = -1;                      \
   }                                                        \

#define widget_jump_space(str,from)                            \
   {                                                           \
      while(CHR_AT(str,from)                                   \
         && widget_is_space(CHR_AT(str,from)))                 \
         (from)++;                                             \
      if(!CHR_AT(str,from)) from = -1;                         \
   }                                                           \

#define widget_ending_space_sum(cnt,str,len)                   \
   {                                                           \
      int index;                                               \
                                                               \
      cnt=0;                                                   \
      for(index = (len -1); index>=0;index--)                  \
      {                                                        \
         if(widget_is_not_space(CHR_AT(str,index))) break;     \
         (cnt)++;                                              \
      }                                                        \
   }                                                           \


#define WIDGET_STRING_SUBSIZE_CACHE_NUM         (3)
#define WIDGET_STRING_SUBSIZE_CACHE_CRITERIA    (80)

typedef struct
{
    MsfStringHandle string;
    int             index;
    int             nbrOfChars;
    kal_int16       maxWordWidth;
    kal_int16       totalWidth;
    kal_int16       height;
}widget_string_subsize_cache_struct;

static int g_new_font_api = 1;
static int widget_subsize_string_cache_index = 0;
static widget_string_subsize_cache_struct widget_subsize_string_cache[WIDGET_STRING_SUBSIZE_CACHE_NUM];



/*****************************************************************************
 * FUNCTION
 *  widget_get_string_width_height
 * DESCRIPTION
 *  Because the string length could not exceed MAX_SHOW_STRING_TEXT_LENGTH,
 *  we will cut the string and get its width & height.
 * PARAMETERS
 *  str             [IN]         
 *  s_id            [IN]        
 *  e_id            [IN]         
 *  w               [OUT]         
 *  h               [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
void widget_get_string_width_height(kal_uint8 *str, int s_id, int e_id, int *w, int *h)
{
    kal_int32 input_str_len = app_ucs2_strlen((const kal_int8*)str);
    
    if (e_id > input_str_len)
    {
        /* e_id should not be larger than string length */
        e_id = input_str_len;
    }

    *w = 0;
    *h = 0;
    if (str)
    {
        Get_StringWidthHeight_n((U8*) STR_AT(str, s_id), e_id - s_id, w, h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_word_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str             [IN]         
 *  index           [IN]        
 *  end_word        [OUT]         
 *  height          [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static int widget_word_width(kal_uint8 *str, int index, int *end_word, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *end_word = index;
    widget_goto_space(str, *end_word);
    if (*end_word < 0)
    {
        *end_word = STR_LEN(str);
    }

    widget_get_string_width_height(str, index, *end_word, &w, &h);
    *height = h;
    return (int)w;
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_max_word_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str             [IN]         
 *  index           [IN]        
 *  spaceWidth      [IN]        
 *  max_word_width  [OUT]         
 *  total_width     [OUT]         
 *  height          [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static int widget_get_max_word_width(kal_uint8 *str, int index, int end_index, int spaceWidth, int *max_word_width, int *total_width, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos, end_pos;
    int max_width = -1;
    int width = 0;
    S32 _w = 0, _h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* handle the first partial word */
    if (index > 0)
    {
        pos = index;
        widget_goto_space(str, pos);
        if (pos < 0)
        {
            pos = index;
        }
    }
    else
    {
        index = 0;
        pos = 0;
    }
    
    widget_get_string_width_height(str, index, pos, &_w, &_h);
    index = pos;
    if (_w && (max_width < _w))
    {
        max_width = _w;
    }
    width += _w;


    while (KAL_TRUE)
    {
        pos = index;
        widget_jump_space(str, pos);

        if (pos >= 0 && pos < end_index)
        {
            /* pos is at the first character of the word */
            width += spaceWidth * (pos - index);
            _w = widget_word_width(str,pos,&end_pos, &_h);
            
            if (end_pos <= end_index)
            {
                /* the word is in the calculated range */
                width += _w;
                if (max_width < _w)
                {
                    max_width = _w;
                }
            }
            else
            {
                /* the word exceeds the calculated range */
                widget_get_string_width_height(str, pos, end_index, &_w, &_h);
                width += _w;
                break;
            } /* if (end_pos <= end_index) */
            index = end_pos;
        }
        else
        {
            /* exceed the calculated rage when jumping the spaces */
            width += spaceWidth * (end_index - index);
            break;
        }
    } /* while (KAL_TRUE) */

    *max_word_width = max_width;
    *total_width = width;
    *height = _h;
    
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringGetSubSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [IN]        
 *  handle          [IN]        
 *  index           [IN]        
 *  nbrOfChars      [IN]        
 *  subwidth        [IN]        
 *  size            [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetStringGetSubSize(
        MsfStringHandle string,
        MSF_UINT32 handle,
        int index,
        int nbrOfChars,
        int subwidth,
        MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfFont font;
    stFontAttribute pfont;
    void *str = widget_string_content(string);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == 0)
    {
        MsfStyleHandle style = widget_get_style(string);

        WAP_RST_ASSERT(style);
        font = _STYLE(style)->font;
    }
    else
    {
        MsfStyleHandle style = HDIa_widgetGetBrush(handle);

        WAP_RST_ASSERT(style);
        font = _STYLE(style)->font;
    }

    pfont = widget_convert_to_system_font(&font);
    SetFont(pfont, 0);

    if (nbrOfChars == 0)
    {
        nbrOfChars = STR_LEN(STR_AT(str, index));
    }

    if (nbrOfChars <= 0)
    {
        size->width = 0;
        size->height = 0;
        return 1;
    }

    if (g_new_font_api && nbrOfChars > WIDGET_STRING_SUBSIZE_CACHE_CRITERIA)
    {
        int i = 0;
        
        /* search in widget_subsize_string_cache first */
        for (i = 0; i < WIDGET_STRING_SUBSIZE_CACHE_NUM; i++)
        {
            if (widget_subsize_string_cache[i].string == string &&
                widget_subsize_string_cache[i].index == index &&
                widget_subsize_string_cache[i].nbrOfChars == nbrOfChars)
            {
                /* find the string in the cache */
                if (subwidth)   /* Find the word with largest width */
                {
                    size->width = widget_subsize_string_cache[i].maxWordWidth;
                }
                else
                {
                    size->width = widget_subsize_string_cache[i].totalWidth;
                }
                size->height = widget_subsize_string_cache[i].height;

                return 1;
            }
        }
    }

    size->height = (S16) Get_CharHeightOfAllLang(pfont.size);

    if (subwidth && !g_new_font_api)   /* Find the word with largest width */
    {
        int end_index = index + nbrOfChars;
        int pos, end_pos;
        int width;
        int max_width = -1;

        /* search the widest word */
        if (index > 0)
        {
            pos = index;
            widget_goto_space(str, pos);
            if (pos < 0)
            {
                pos = index;
            }
        }
        else
        {
            pos = 0;
        }

        while (KAL_TRUE)
        {
            int _h;
            int _d = 0;

            widget_jump_space(str, pos);

            if (pos >= 0 && pos < end_index)
            {
				width = widget_word_width(str,pos,&end_pos, &_h);
                _d = widget_get_string_width_deviation(pfont, _h);
                if (end_pos <= end_index && max_width < width)
                {
                    max_width = width;
                }
                else if (max_width < 0)
                {
                    max_width = width;
                }
                pos = end_pos;
            }
            else
            {
                max_width += _d;
                size->width = max_width;
                return 1;
            }
        }
    }
    else if (subwidth && g_new_font_api)   /* Find the word with largest width */
    {
        int end_index = index + nbrOfChars;
        int spaceWidth = 0;
        int max_width = 0;
        S32 _w, _h;
        S32 _d = widget_get_string_width_deviation(pfont, size->height);

        Get_CharWidthHeight(CHR(' '), &spaceWidth, &_h);        
        widget_get_max_word_width(
            str, 
            index, 
            end_index, 
            spaceWidth, 
            &max_width, 
            &_w,
            &_h);

        max_width += _d;
        size->width = max_width;

        return 1;
    }
    else
    {
        int end_index = index + nbrOfChars;
        int len = STR_LEN(str);
        int width = 0;
        int spaceWidth = 0;
        S32 _w, _h;
        S32 _d = widget_get_string_width_deviation(pfont, size->height);

		Get_CharWidthHeight(CHR(' '), &spaceWidth, &_h);
        if (end_index > len)
        {
            width += spaceWidth * (end_index - len);
            end_index = len;
        }

        if (g_new_font_api && nbrOfChars > WIDGET_STRING_SUBSIZE_CACHE_CRITERIA)
        {
            int max_width = 0;

            widget_get_string_width_height(str, index, end_index, &_w, &_h);
            width += _w + _d;

            widget_get_max_word_width(
                str, 
                index, 
                end_index, 
                spaceWidth, 
                &max_width, 
                &width,
                &_h);

            max_width += _d;            

            /* Update the cache */            
            widget_subsize_string_cache[widget_subsize_string_cache_index].string = string;
            widget_subsize_string_cache[widget_subsize_string_cache_index].index = index;
            widget_subsize_string_cache[widget_subsize_string_cache_index].nbrOfChars = nbrOfChars;
            widget_subsize_string_cache[widget_subsize_string_cache_index].maxWordWidth = max_width;
            widget_subsize_string_cache[widget_subsize_string_cache_index].totalWidth = width;
            widget_subsize_string_cache[widget_subsize_string_cache_index].height = size->height;
            widget_subsize_string_cache_index = (widget_subsize_string_cache_index + 1) % WIDGET_STRING_SUBSIZE_CACHE_NUM;
        }
        else
        {
            widget_get_string_width_height(str, index, end_index, &_w, &_h);
            width += _w + _d;
        }

        size->width = width;
        
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetStringGetVisible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string                          [IN]        
 *  handle                          [IN]        
 *  size                            [IN]         
 *  startIndex                      [IN]        
 *  includeInitialWhiteSpaces       [IN]        
 *  nbrOfCharacters                 [OUT]         
 *  nbrOfEndingWhiteSpaces          [OUT]         
 *  nbrOfInitialWhiteSpaces         [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetStringGetVisible(
        MsfStringHandle string,
        MSF_UINT32 handle,
        MsfSize *size,
        int startIndex,
        int includeInitialWhiteSpaces,
        int *nbrOfCharacters,
        int *nbrOfEndingWhiteSpaces,
        int *nbrOfInitialWhiteSpaces)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfFont font;
    stFontAttribute pfont;
    void *str = widget_string_content(string);

#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE
    widget_string_get_visible_cache_struct *cache_data = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: we do not handle the case (size->height != 0)

#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE
    if (string == WFONT_CTX->cache_string)
    {
        if (WIDGET_STRING_GET_VISIBLE_CACHE_FOUND == widget_lookup_string_get_visible_cache(handle, size, startIndex, includeInitialWhiteSpaces, &cache_data))
        {
            *nbrOfCharacters = (int)cache_data->nbrOfCharacters;
            *nbrOfEndingWhiteSpaces = (int)cache_data->nbrOfEndingWhiteSpaces;
            *nbrOfInitialWhiteSpaces = (int)cache_data->nbrOfInitialWhiteSpaces;
            return 1;
        }
    }
#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 

    memset(&font, 0, sizeof(font));

    if (handle == 0)
    {
        MsfStyleHandle style = widget_get_style(string);

        WAP_RST_ASSERT(style);
        font = _STYLE(style)->font;
    }
    else
    {
        MsfStyleHandle style = HDIa_widgetGetBrush(handle);

        WAP_RST_ASSERT(style);
        font = _STYLE(style)->font;
    }

    pfont = widget_convert_to_system_font(&font);
    SetFont(pfont, 0);

    str = STR_AT(str, startIndex);

    if (includeInitialWhiteSpaces == 0)
    {
        *nbrOfInitialWhiteSpaces = 0;
        widget_jump_space(str, *nbrOfInitialWhiteSpaces);
        if (*nbrOfInitialWhiteSpaces < 0)
        {
            /* 
             * The string contains all spaces
             *
             * Scenario: For 'abc '. Assume we can only display 'abc' in one line
             * and BRS try to render the second line with only a white space.
             * If we return *nbrOfInitialWhiteSpaces=0 & *nbrOfCharacters=1
             * for input string as 'abc ' and start_index as 3,
             * BRS will think that the word 'abc ' is too long to fit in a line.
             */
            *nbrOfInitialWhiteSpaces = STR_LEN(str);
        }

        str = STR_AT(str, *nbrOfInitialWhiteSpaces);
    }
    else
    {
        *nbrOfInitialWhiteSpaces = 0;
    }

    /* Initial white spaces are excluded (when necessary) */
    {
        int len = STR_LEN(str);
        int width;

        kal_int8 * input_str = NULL;

        int l, m = 0, r;
        int cmp = 0;
        S32 w, h;

        int len_in_cluster;

        if (len <= 0)
        {
            *nbrOfCharacters = 0;
            *nbrOfEndingWhiteSpaces = 0;
            goto return_true;
        }

        l = 0;
        r = len - 1;

        if (size->width != 0)
        {
            if (r >= size->width / 2)
            {
                r = (size->width / 2) - 1;
            }
            /* r should never be negative. */
            if (r < 0)
            {
                r = 0;
            }
        }

        /* If all of the string can fit into bound box */
        widget_get_string_width_height(str, 0, r + 1, &w, &h);
        width = w + widget_get_string_width_deviation(pfont, h);
        if (width < size->width)
        {
            widget_ending_space_sum(*nbrOfEndingWhiteSpaces, str, len);
            *nbrOfCharacters = len;
            goto return_true;
        }

        if (g_new_font_api)
        {
            input_str = (kal_int8 *)str;
            width = (size->width - 1) - widget_get_string_width_deviation(pfont, h);
            
            if (width > 0)
            {
                /* Get_StringWidthHeight_variant() returns the character numbers, but we need the index of string array. so we need to subtract 1. */
                m = Get_StringWidthHeight_variant((U8*)input_str, 0, len, &w, &h, width) - 1;

                if (w > width)
                {
                    m--;
                }
            }
            else
            {
                m = 0;
            }
            
            if (m==0 && !widget_is_space(CHR_AT(input_str, m)))
            {
                m--;
            }

            if (m < 0)  /* No char can fit into this box. */
            {
                /* Teleca said it should return 0 character. I don't know whether (m = -1) introduces a infinite loop in BRS */
                *nbrOfCharacters = 0;
                *nbrOfEndingWhiteSpaces = 0;
                goto return_true;
            }

        }
        else
        {
            input_str = (kal_int8 *)str;

            /* Binary search the visible substring */
            // TODO: We can optimize it because Get_StringWidthHeight_n is quite time-consuming
            while (l <= r)
            {
                m = (l + r) >> 1;
    
                /* detect the substring is in the bound box */
                Get_StringWidthHeight_n((U8*) input_str, m + 1, &w, &h);
                w += widget_get_string_width_deviation(pfont, h);
                width = w;
    
                /*
                 * adjust left, right index
                 * The string width should less than size->width
                 */
                cmp = (size->width - 1) - width;
    
                if (cmp < 0)
                {
                    r = m - 1;
                }
                else if (cmp >= 0)
                {
                    l = m + 1;
                }
                else
                {
                    break;
                }
            }
    
            if (cmp < 0)
            {
                /* if input_str[m] is space, we will reserve the space. */
                if (!widget_is_space(CHR_AT(input_str, m)))
                {
                    m--;
                }
            }
            /* Now str[m] is the last visible char */
    
            if (m < 0)  /* No char can fit into this box. */
            {
                /* Teleca said it should return 0 character. I don't know whether (m = -1) introduces a infinite loop in BRS */
                *nbrOfCharacters = 0;
                *nbrOfEndingWhiteSpaces = 0;
                goto return_true;
            }
        }   /* g_new_font_api */

        /* If str[m] is inside a partial word? */
        if (widget_is_not_space(CHR_AT(input_str, m)) && widget_is_not_space(CHR_AT(input_str, m + 1)))
        {
            int tmp;

            for (tmp = m - 1; tmp >= 0; tmp--)
            {
                if (widget_is_space(CHR_AT(input_str, tmp)))
                {
                    break;
                }
            }

            if (tmp > 0)    /* Find the last space before m */
            {
                m = tmp;
            }
            /* Otherwise, not even a single word fits within the size. Leave m as is. */
        }

        /* m is the index of the string, m+1 is the string length */
        len_in_cluster = Get_StringLength_InCluster((U8*)input_str, m + 5, m + 1);

        widget_ending_space_sum(*nbrOfEndingWhiteSpaces, input_str, len_in_cluster);
        *nbrOfCharacters = len_in_cluster/*m + 1*/;

        goto return_true;
    }

  return_true:
#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE
    if (cache_data)
    {
        cache_data->nbrOfCharacters = (kal_int16) * nbrOfCharacters;
        cache_data->nbrOfEndingWhiteSpaces = (kal_int16) * nbrOfEndingWhiteSpaces;
        cache_data->nbrOfInitialWhiteSpaces = (kal_int16) * nbrOfInitialWhiteSpaces;
    }
#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 

    return 1;
}

#ifdef WIDGET_SMIL_DISABLE_WORD_WRAPPING


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringGetSubSizeIgnoreSpace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [IN]        
 *  handle          [IN]        
 *  index           [IN]        
 *  nbrOfChars      [IN]        
 *  subwidth        [IN]        
 *  size            [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtStringGetSubSizeIgnoreSpace(
        MsfStringHandle string,
        MSF_UINT32 handle,
        int index,
        int nbrOfChars,
        int subwidth,
        MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_widget_ignore_space = 1;
    ret = HDIa_widgetStringGetSubSize(string, handle, index, nbrOfChars, subwidth, size);
    g_widget_ignore_space = 0;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringGetVisibleIgnoreSpace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string                          [IN]        
 *  handle                          [IN]        
 *  size                            [IN]         
 *  startIndex                      [IN]        
 *  includeInitialWhiteSpaces       [IN]        
 *  nbrOfCharacters                 [OUT]         
 *  nbrOfEndingWhiteSpaces          [OUT]         
 *  nbrOfInitialWhiteSpaces         [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtStringGetVisibleIgnoreSpace(
        MsfStringHandle string,
        MSF_UINT32 handle,
        MsfSize *size,
        int startIndex,
        int includeInitialWhiteSpaces,
        int *nbrOfCharacters,
        int *nbrOfEndingWhiteSpaces,
        int *nbrOfInitialWhiteSpaces)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_widget_ignore_space = 1;
    ret = HDIa_widgetStringGetVisible(
            string,
            handle,
            size,
            startIndex,
            includeInitialWhiteSpaces,
            nbrOfCharacters,
            nbrOfEndingWhiteSpaces,
            nbrOfInitialWhiteSpaces);
    g_widget_ignore_space = 0;
    return ret;
}
#endif /* WIDGET_SMIL_DISABLE_WORD_WRAPPING */ 

/****************************************************************
 *
 * Cache for HDIa_widgetStringGetVisible()
 *
 ***************************************************************/

#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE


/*****************************************************************************
 * FUNCTION
 *  widget_release_get_visible_cache_by_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_release_get_visible_cache_by_string(MsfStringHandle str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str && str == WFONT_CTX->cache_string)
    {
        if (WFONT_CTX->cache)
        {
            MSF_MEM_FREE(_H(WFONT_CTX->cache_string)->module_id, WFONT_CTX->cache);
            WFONT_CTX->cache = NULL;
        }
        WFONT_CTX->cache_string = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_lookup_string_get_visible_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle                          [IN]        
 *  size                            [IN]         
 *  startIndex                      [IN]        
 *  includeInitialWhiteSpaces       [IN]        
 *  item                            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
widget_string_get_visible_cache_result_enum
widget_lookup_string_get_visible_cache(
    MSF_UINT32 handle,
    MsfSize *size,
    int startIndex,
    int includeInitialWhiteSpaces,
    widget_string_get_visible_cache_struct **item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_string_get_visible_cache_struct *head, *tail, *min_item;
    kal_uint32 min_seqnum;
    kal_bool found = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* WAP_DBG_ASSERT(!WFONT_CTX->cache_handle ||WFONT_CTX->cache_handle == handle); */
    WFONT_CTX->cache_handle = handle;

    head = WFONT_CTX->cache;
    ASSERT(head);
    tail = head + WFONT_CTX->cache_item_cnt;

    if (WFONT_CTX->cache_item_cnt == WIDGET_STRING_GET_VISIBLE_CACHE_NITEMS)
    {
        /* To find the oldest item to replace */
        min_seqnum = 0xFFFFFFFF;
    }
    else
    {
        min_seqnum = 0;
    }

    min_item = NULL;
    /* Linear search */
    while (head < tail)
    {
        if (((int)head->start_index == startIndex) &&
            ((MSF_INT16) head->width == size->width) &&
            ((int)head->includeInitialWhiteSpaces == includeInitialWhiteSpaces))
        {
            found = KAL_TRUE;
            break;
        }

        if (head->seqnum < min_seqnum)
        {
            min_seqnum = head->seqnum;
            min_item = head;
        }

        head++;
    }

    if (found)  /* Found */
    {
        WFONT_CTX->cache_hit_cnt++;
        *item = head;
        return WIDGET_STRING_GET_VISIBLE_CACHE_FOUND;
    }
    else
    {
        WFONT_CTX->cache_miss_cnt++;
        WFONT_CTX->cache_seqnum++;

        if (WFONT_CTX->cache_item_cnt == WIDGET_STRING_GET_VISIBLE_CACHE_NITEMS)
        {
            /* Replace existing item */
            ASSERT(min_item);

            WFONT_CTX->cache_invalidation_cnt++;

            *item = min_item;
        }
        else
        {
            /* Append a new item */
            WFONT_CTX->cache_item_cnt++;

            *item = head;
        }

        (*item)->seqnum = WFONT_CTX->cache_seqnum;
        (*item)->includeInitialWhiteSpaces = (kal_int16) includeInitialWhiteSpaces;
        (*item)->start_index = (kal_int16) startIndex;
        (*item)->width = (kal_int16) size->width;

        /* ouput values not known yet */
        (*item)->nbrOfCharacters = 0;
        (*item)->nbrOfEndingWhiteSpaces = 0;
        (*item)->nbrOfInitialWhiteSpaces = 0;

        return WIDGET_STRING_GET_VISIBLE_CACHE_NEW_ENTRY;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringSetCacheGetVisible
 * DESCRIPTION
 *  Setup the cache of HDIa_widgetStringGetVisible for the MsfString
 * PARAMETERS
 *  string      [IN]        Target string handle
 * RETURNS
 *  void
 * REMARKS
 *  This is used to speed-up MMS SMIL scrolling. We must guarentee that the content of
 *  'string' stay unchanged before HDIa_widgetExtStringClearCacheGetVisible().
 *****************************************************************************/
void HDIa_widgetExtStringSetCacheGetVisible(MsfStringHandle string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_string_struct *s;
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WFONT_CTX->cache_string)
    {
        /* We do not support multiple strings */
        WAP_DBG_ASSERT(0);
        return;
    }
    if (!string || !IS_STRING_TYPE(string))
    {
        /* We do not support predefined string */
        WAP_DBG_ASSERT(IS_PRE_STRING_TYPE(string));
        return;
    }

    s = _STRING(string);

    WFONT_CTX->cache_string = string;
    size = WIDGET_STRING_GET_VISIBLE_CACHE_NITEMS * sizeof(widget_string_get_visible_cache_struct);
    WFONT_CTX->cache = MSF_MEM_ALLOC(s->module_id, size);
    memset(WFONT_CTX->cache, 0, size);

    WFONT_CTX->cache_handle = 0;
    WFONT_CTX->cache_seqnum = 1;
    WFONT_CTX->cache_item_cnt = 0;

    WFONT_CTX->cache_miss_cnt = 0;
    WFONT_CTX->cache_hit_cnt = 0;
    WFONT_CTX->cache_invalidation_cnt = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringClearCacheGetVisible
 * DESCRIPTION
 *  Clear cache of HDIa_widgetStringGetVisible for the MsfString
 * PARAMETERS
 *  string      [IN]        Target string handle
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void HDIa_widgetExtStringClearCacheGetVisible(MsfStringHandle string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_release_get_visible_cache_by_string(string);
}

#else /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringSetCacheGetVisible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtStringSetCacheGetVisible(MsfStringHandle string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dummy */
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStringClearCacheGetVisible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtStringClearCacheGetVisible(MsfStringHandle string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dummy */
}

#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 


/*****************************************************************************
 * FUNCTION
 *  widget_init_font
 * DESCRIPTION
 *  Initialization of font
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_widget_context.font_cntx, 0, sizeof(widget_font_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_font
 * DESCRIPTION
 *  De-initialization of font
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_font(void)
{
#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WFONT_CTX->cache)
    {
        /* The cache should be already released when releasing the MsfString */
        WAP_DBG_ASSERT(0);
        ASSERT(WFONT_CTX->cache_string);
        MSF_MEM_FREE(_H(WFONT_CTX->cache_string)->module_id, WFONT_CTX->cache);
        WFONT_CTX->cache = NULL;
    }
    WFONT_CTX->cache_string = 0;
#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 
}


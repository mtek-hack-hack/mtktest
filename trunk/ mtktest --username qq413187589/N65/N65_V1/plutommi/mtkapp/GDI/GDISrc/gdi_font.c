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
 *  gdi_font.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI low-level font library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "gdi_internal.h"
#include "gd_primitive.h"

#include "fontres.h"

#if defined(GDI_USING_2D_ENGINE) || defined(GDI_USING_2D_ENGINE_V2)
#include "2d_engine.h"
#endif 

const U32 gdi_tilt_table[61] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2,
    2, 2, 2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 5, 5, 5, 5, 5, 6, 6, 6,
    6, 7, 7, 7, 7, 8, 8, 8, 8, 8,
    9, 9, 9, 9, 10, 10, 10, 10, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13
};

#define MAX_TILT  13

static S32 text_clip_x1;    /* Left edge of text clip rectangle */
static S32 text_clip_y1;    /* Top edge of text clip rectangle  */
static S32 text_clip_x2;    /* Right edge of text clip rectangle   */
static S32 text_clip_y2;    /* Bottom edge of text clip rectangle  */

#ifdef GDI_USING_FONT_SINGLE_BANK_CACHE

static U32 gdi_font_single_bank_cache_buf[GDI_FONT_SINGLE_BANK_CACHE_SIZE/4];

#endif /* GDI_USING_FONT_SINGLE_BANK_CACHE */

static gd_put_pixel_func put_pixel;

#define put_pixel_with_clip(x,y,c)                    \
   {                                                  \
      if((x >= text_clip_x1) && (x <= text_clip_x2)   \
      &&(y >= text_clip_y1) && (y <= text_clip_y2))   \
         put_pixel(x,y,c);                            \
   }                                                  \

/* W05.50 Skip unnecessary action when the character is out of clip */
#define GDI_CHECK_CHAR_CLIP(x,y,char_width,char_height,NULL_ACTION)                 \
   {                                                                                \
      if((x -1 > text_clip_x2   )    || (x+char_width  +MAX_TILT +1 < text_clip_x1) \
      ||(y -1 > text_clip_y2) || (y+char_height +1 < text_clip_y1))                 \
         NULL_ACTION;                                                               \
   }                                                                                \

#define __GDI_SHOW_CHAR__  gdi_show_char_no_clip
#define __GDI_SET_PIXEL__  put_pixel
#include "gdi_font_show_char.h"
#undef __GDI_SHOW_CHAR__
#undef __GDI_SET_PIXEL__

#define __GDI_SHOW_CHAR__  gdi_show_char_with_clip
#define __GDI_SET_PIXEL__  put_pixel_with_clip
#include "gdi_font_show_char.h"
#undef __GDI_SHOW_CHAR__
#undef __GDI_SET_PIXEL__


/* 
 * ABM font engine 
 */

/*****************************************************************************
 * FUNCTION
 *  gdi_draw_font_by_abm
 * DESCRIPTION
 *  Wrapper for drawing a 1-bit bitmap font by the ABM decoder
 * PARAMETERS
 *  x                    [IN]   character x
 *  y                    [IN]   character y
 *  color                [IN]   text color
 *  font_data            [IN]   font data
 *  char_width           [IN]   character width
 *  char_height          [IN]   character height
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_draw_font_by_abm(
                S32 x, 
                S32 y, 
                gdi_color color, 
                U8 *font_data, 
                S32 char_width, 
                S32 char_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 16-byte ABM header for font information */
    U32 abm_font_header[4];
    U16* abm = (U16*)abm_font_header;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abm[0] = (U16)char_width;

#if (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16)
    abm[1] = (U16)char_height;    
#else /* (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16) */
    abm[1] = (U16)(char_height | 0x8000);    
#endif /* (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16) */

    /* 1-bit color font: 1 for transparent color, 1 for the character color. */
    abm[2] = 2;

    abm[3] = 0;
    abm[4] = 0;
    abm[5] = 0;

    *((U32*)&abm[6]) = (U32)color;
    
    gdi_image_abm_draw_font(x, y, (U8*)abm, font_data);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_show_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  color               [IN]        
 *  font_data           [?]         
 *  font_data_size      [IN]        
 *  char_width          [IN]        
 *  char_height         [IN]        
 *  font_attr           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_show_char(
        S32 x,
        S32 y,
        gdi_color color,
        U8 *font_data,
        U32 font_data_size,
        U16 char_width,
        U16 char_height,
        U8 font_attr)
{
#ifdef GDI_USING_FONT_SINGLE_BANK_CACHE
    if (font_data != (U8 *) gdi_font_single_bank_cache_buf)
    {
        MMI_ASSERT(GDI_FONT_SINGLE_BANK_CACHE_SIZE >= font_data_size);
        memcpy(gdi_font_single_bank_cache_buf, font_data, font_data_size);
        font_data = (U8*) gdi_font_single_bank_cache_buf;
    }
#endif 

    /* hardware font engine */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 

    #ifdef GDI_USING_2D_ENGINE_V2
    if(GDI_COLOR_FORMAT_16 <= gdi_act_layer->cf && gdi_act_layer->cf <= GDI_COLOR_FORMAT_32)
    if (!(font_attr & FONTATTRIB_UNDERLINE))
    {
        /* W05.50 Skip unnecessary action when the character is out of clip */
        GDI_CHECK_CHAR_CLIP(x, y, char_width, char_height, return);
        /* W06.04 Temp Solution for Italic Font */
        if (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE))
        {
            gdi_2d_set_tilt_table(gdi_tilt_table, char_height);
        }
        gdi_2d_draw_font(x, y, font_data, 0, char_width, char_height);
        return;
    }
    #endif 

    /* software font engine */
    if (font_attr == 0 && gdi_act_layer->bits_per_pixel >= 16)
    {   /* draw normal font by ABM decoder (ABM decoder only supports 16, 24, and 32 bpp.) */
        gdi_draw_font_by_abm(x, y, color, font_data, char_width, char_height);
    }
    else if ((x - 1 < text_clip_x1) || (x + char_width + MAX_TILT + 1 > text_clip_x2) ||
             (y - 1 < text_clip_y1) || (y + char_height + 1 > text_clip_y2))
    {
        /* W05.50 Skip unnecessary action when the character is out of clip */
        GDI_CHECK_CHAR_CLIP(x, y, char_width, char_height, return);
        gdi_show_char_with_clip(x, y, color, font_data, font_data_size, char_width, char_height, font_attr);
    }
    else
    {
        gdi_show_char_no_clip(x, y, color, font_data, font_data_size, char_width, char_height, font_attr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_show_char_bordered
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  text_color          [IN]        
 *  border_color        [IN]        
 *  font_data           [?]         
 *  font_data_size      [IN]        
 *  char_width          [IN]        
 *  char_height         [IN]        
 *  font_attr           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_show_char_bordered(
        S32 x,
        S32 y,
        gdi_color text_color,
        gdi_color border_color,
        U8 *font_data,
        U32 font_data_size,
        U16 char_width,
        U16 char_height,
        U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_FONT_SINGLE_BANK_CACHE
    MMI_ASSERT(GDI_FONT_SINGLE_BANK_CACHE_SIZE >= font_data_size);
    memcpy(gdi_font_single_bank_cache_buf, font_data, font_data_size);
    font_data = (U8*) gdi_font_single_bank_cache_buf;
#endif 
    
    /* hardware font engine */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef GDI_USING_2D_ENGINE_V2
    if(GDI_COLOR_FORMAT_16 <= gdi_act_layer->cf && gdi_act_layer->cf <= GDI_COLOR_FORMAT_32)
    if (!(font_attr & FONTATTRIB_UNDERLINE))
    {
        gdi_2d_set_font_attr(
            font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE),      /* is_tilt */
            FALSE,  /* /TODO: is_bold always be FALSE, it should make some change to pixcomfontengine.c, and turn on this HW feature */
            TRUE,   /* is_border */
            FALSE,  /* don't enable bg_color, */
            text_color,
            border_color);
        /* W06.04 Temp Solution for Italic Font */
        if (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE))
        {
            gdi_2d_set_tilt_table(gdi_tilt_table, char_height);
        }
        gdi_2d_draw_font(x, y, font_data, 0, char_width, char_height);
        return;
    }
#endif

    /* software font engine */
    {
        U8 font_attr1 = font_attr &= ~FONTATTRIB_UNDERLINE;

        gdi_show_char(x - 1, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr1);
        gdi_show_char(x - 1, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr1);
        gdi_show_char(x + 1, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr1);
        gdi_show_char(x + 1, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr1);
        gdi_show_char(x + 0, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr1);
        gdi_show_char(x + 0, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr1);
        gdi_show_char(x - 1, y + 0, border_color, font_data, font_data_size, char_width, char_height, font_attr1);
        gdi_show_char(x + 1, y + 0, border_color, font_data, font_data_size, char_width, char_height, font_attr1);

        gdi_show_char(x, y, text_color, font_data, font_data_size, char_width, char_height, font_attr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_font_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fg_color        [IN]        
 *  font_attr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_font_begin(gdi_color fg_color, U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;

#ifdef GDI_USING_2D_ENGINE
    if (GDI_LAYER.bits_per_pixel == 16)
    {
        g2d_font_begin(
            (U32) GDI_LAYER.buf_ptr,
            GDI_LAYER.width,
            font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE),
            GDI_LAYER.clipx1,
            GDI_LAYER.clipy1,
            GDI_LAYER.clipx2,
            GDI_LAYER.clipy2);

        g2d_font_color(fg_color);
    }
#endif /* GDI_USING_2D_ENGINE */ 

#ifdef GDI_USING_2D_ENGINE_V2
    if(GDI_COLOR_FORMAT_16 <= gdi_act_layer->cf && gdi_act_layer->cf <= GDI_COLOR_FORMAT_32)
    {
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer((gdi_handle) gdi_act_layer);
        gdi_2d_set_font_attr(
            font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE),  /* is_tilt */
            FALSE,  /* /TODO: is_bold always be FALSE, it should make some change to pixcomfontengine.c, and turn on this HW feature */
            FALSE,  /* is_border */
            FALSE,  /* don't enable bg_color, */
            fg_color,
            0);
    }
#endif

    put_pixel = gd_put_pixel[gdi_act_layer->cf];

    text_clip_x1 = GDI_LAYER.clipx1;
    text_clip_y1 = GDI_LAYER.clipy1;
    text_clip_x2 = GDI_LAYER.clipx2;
    text_clip_y2 = GDI_LAYER.clipy2;

}


/*****************************************************************************
 * FUNCTION
 *  gdi_font_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_font_end(void)
{
#ifdef GDI_USING_2D_ENGINE
    if (GDI_LAYER.bits_per_pixel == 16)
        g2d_font_end();
#endif

#ifdef GDI_USING_2D_ENGINE_V2
    if(GDI_COLOR_FORMAT_16 <= gdi_act_layer->cf && gdi_act_layer->cf <= GDI_COLOR_FORMAT_32)
    gdi_2d_end();
#endif 

    GDI_UNLOCK;
}


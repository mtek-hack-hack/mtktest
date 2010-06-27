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
 *  svg
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SVG tiny basic library
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
#include "MMI_include.h"
#if defined(SVG_SUPPORT)

#include "xml_def.h"

#include "svg_internal.h"
#include "svg_vpath.h"
#include "svg_svp.h"
#include "svg_render.h"
#include "svg_transform.h"
#include "svg_work_buffer.h"

#include "gui_themes.h"
#include "gd_primitive.h"

extern void UI_set_font(UI_font_type f);
extern void UI_measure_string(UI_string_type text, S32 *width, S32 *height);
extern void UI_set_current_text_color(color c);

/*****************************************************************************
 * FUNCTION
 *  svg_render_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  glyph       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svg_render_char(S32 x, S32 y, svg_element_t *glyph)
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
 *  svg_render_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  e       [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_render_text(svg_element_t *e)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (e->X.text.data == NULL || *((U16*) e->X.text.data) == 0)
    {
        return SVG_FAIL;
    }

    /* try to find custom font family */
    if (svg_context->style.flag & SVG_STYLE_FLAG_FONT_FAMILY)
    {
        float T[6];
        U32 count;
        U8 *str;
        U8 unicode[8];
        U8 hkern[4];
        float x, y;
        float fs;
        BOOL is_horizontal = TRUE;

        svg_element_t *font;

        font = (svg_element_t*) svg_hash_find(svg_context->font_family, svg_context->style.font_family, NULL);
        if (font == NULL)
        {
            return SVG_FAIL;    /* no this font family */
        }

        if (font->X.font.units_per_em > 0)
        {
            svg_context->units_per_em = font->X.font.units_per_em;
        }
        fs = svg_context->style.font_size / svg_context->units_per_em;

        x = e->X.text.x;
        y = e->X.text.y;

        svg_transform_translate(T, x, y);
        svg_transform_multiply(svg_context->style.transform, T, svg_context->style.transform);

        svg_transform_scale(T, fs, -fs);
        svg_transform_multiply(svg_context->style.transform, T, svg_context->style.transform);

        x = 0;
        y = 0;

        if (is_horizontal)
        {
            if (font->X.font.horiz_origin_x > 0)
            {
                x += font->X.font.horiz_origin_x;
            }
            if (font->X.font.horiz_origin_y > 0)
            {
                y += font->X.font.horiz_origin_y;
            }
        }
        else
        {
            if (font->X.font.horiz_origin_x > 0)
            {
                x += font->X.font.vert_origin_x;
            }
            if (font->X.font.horiz_origin_y > 0)
            {
                y += font->X.font.vert_origin_y;
            }
        }

        hkern[2] = hkern[3] = 0;
        unicode[2] = unicode[3] = 0;
        for (str = e->X.text.data, count = 0; str && *(U16*) str; count++)
        {
            svg_element_t *glyph;

            hkern[0] = hkern[2];
            hkern[1] = hkern[3];

            /* /TODO: may support multi bytes in here */
            hkern[2] = unicode[0] = str[0];
            hkern[3] = unicode[1] = str[1];
            str += 2;

            glyph = svg_hash_find_raw(font->X.font.glyph_hash, unicode, 4, NULL, NULL);
            if (glyph == NULL)
            {
                glyph = font->X.font.miss_glyph;
            }

            if (glyph != NULL)  /* render this char */
            {
                if (is_horizontal)
                {
                    if (glyph->X.glyph.horiz_origin_x > 0)
                    {
                        x += glyph->X.glyph.horiz_origin_x;
                    }
                    if (glyph->X.glyph.horiz_origin_y > 0)
                    {
                        y += glyph->X.glyph.horiz_origin_y;
                    }
                }
                else
                {
                    if (glyph->X.glyph.vert_origin_x > 0)
                    {
                        x += glyph->X.glyph.vert_origin_x;
                    }
                    if (glyph->X.glyph.vert_origin_y > 0)
                    {
                        y += glyph->X.glyph.vert_origin_y;
                    }
                }

                /* process hkern */
                if (count > 0)  /* not first char */
                {
                    S32 k;

                    if (font->X.font.hkern_hash)
                    {
                        k = (S32) svg_hash_find_raw(font->X.font.hkern_hash, hkern, 4, NULL, NULL);
                        x -= k;
                    }
                }

                /* start to render this glyph */
                if (glyph->X.glyph.path_data)
                {
                    svg_transform_translate(T, x, y);
                    svg_inherit_transform(T, svg_render_glyph, glyph);
                }

                /* increase the adv_x,adv_y */
                if (is_horizontal)
                {
                    if (glyph->X.glyph.horiz_adv_x > 0)
                    {
                        x += glyph->X.glyph.horiz_adv_x;
                    }
                    else
                    {
                        x += font->X.font.horiz_adv_x;
                    }
                }
                else
                {
                    if (glyph->X.glyph.vert_adv_y > 0)
                    {
                        y += glyph->X.glyph.vert_adv_y;
                    }
                    else
                    {
                        y += font->X.font.vert_adv_y;
                    }
                }

            }
            else
            {
                /* just jump position */
                if (is_horizontal)
                {
                    x += font->X.font.horiz_adv_x * fs;
                }
                else
                {
                    x += font->X.font.vert_adv_y * fs;
                }
            }
        }
    }
    else
    {
        float x1, y1, x2, y2;
        float nx1, nx2, ny1, ny2;
        float tx, ty;  /* for temp use */
        float T[6];
        S32 string_w, string_h;

        /* render text into work buffer */
        {
            stFontAttribute *font;
            color c;

            c.r = (U8) 255;
            c.g = (U8) 255;
            c.b = (U8) 255;
            c.alpha = (U8) 255;

            switch (atoi((char*)(svg_context->style.font_weight)))
            {
                case 100:
                case 200:
                case 300:
                    UI_set_font(font = &MMI_small_font);
                    break;
                case 400:
                case 500:
                    UI_set_font(font = &MMI_medium_font);
                    break;
                case 600:
                case 700:
                    UI_set_font(font = &MMI_medium_bold_font);
                    break;
                case 800:
                case 900:
                default:
                    UI_set_font(font = &MMI_large_font);
                    break;
            }
            /* gui_set_text_color(c); */
            UI_measure_string((U16*) e->X.text.data, &string_w, &string_h);
            if (string_w == 0 || string_h == 0)
            {
                return SVG_FAIL;
            }

            svg_wb_resize_with_height(string_h);
            gdi_layer_push_and_set_active((gdi_handle) svg_wb_layer);
            gdi_draw_solid_rect(0, 0, string_w, string_h, 0);

            UI_set_current_text_color(c);
            ShowString(0, 0, *font, 0, (U8*) e->X.text.data, string_h);
            //                              gui_move_text_cursor(0,0);
            //                              gui_print_text((U16*)e->X.text.data);
            gdi_layer_pop_and_restore_active();

        }

        // calculate the source rectangle, and apply the text_anchor attribute
        {
            S32 w;

            w  = string_w * svg_context->style.font_size / string_h;
            
            x1 = e->X.text.x;
            y1 = e->X.text.y - svg_context->style.font_size;
            
            x2 = x1 + w;
            y2 = y1 + svg_context->style.font_size;

            if(svg_context->style.flag & SVG_STYLE_FLAG_TEXT_ANCHOR)
            {
                if(svg_context->style.text_anchor == SVG_TEXT_ANCHOR_MIDDLE)
                    x1 -= w/2, x2-=w/2;
                else if(svg_context->style.text_anchor == SVG_TEXT_ANCHOR_END)
                    x1 -= w,   x2-=w;
            }
        }

        /* target bound box */
        svg_transform_pos(&nx1, &ny1, x1, y1, svg_context->style.transform);
        nx2 = nx1;
        ny2 = ny1;

        svg_transform_pos(&tx, &ty, x1, y2, svg_context->style.transform);
        if (tx < nx1)
        {
            nx1 = tx;
        }
        if (ty < ny1)
        {
            ny1 = ty;
        }
        if (tx > nx2)
        {
            nx2 = tx;
        }
        if (ty > ny2)
        {
            ny2 = ty;
        }

        svg_transform_pos(&tx, &ty, x2, y1, svg_context->style.transform);
        if (tx < nx1)
        {
            nx1 = tx;
        }
        if (ty < ny1)
        {
            ny1 = ty;
        }
        if (tx > nx2)
        {
            nx2 = tx;
        }
        if (ty > ny2)
        {
            ny2 = ty;
        }

        svg_transform_pos(&tx, &ty, x2, y2, svg_context->style.transform);
        if (tx < nx1)
        {
            nx1 = tx;
        }
        if (ty < ny1)
        {
            ny1 = ty;
        }
        if (tx > nx2)
        {
            nx2 = tx;
        }
        if (ty > ny2)
        {
            ny2 = ty;
        }

        /* clipping into svg canvas */
        SVG_CLIP_TWO_RECT(nx1, ny1, nx2, ny2,
                          svg_context->output_x1,
                          svg_context->output_y1, svg_context->output_x2, svg_context->output_y2, return SVG_OK;
            );
        SVG_CLIP_TWO_RECT(nx1, ny1, nx2, ny2,
						  gdi_act_layer->clipx1,
						  gdi_act_layer->clipy1,
						  gdi_act_layer->clipx2,
						  gdi_act_layer->clipy2,
						  return SVG_OK;
            );

        /* calculate mapping matrix */
        {
            float T1[6];

            /* mapping destination into original coord */
            svg_transform_invert(T, svg_context->style.transform);

            /* mapping resized image into original coord */
            svg_transform_translate(T1, -x1, -y1);
            svg_transform_multiply(T, T, T1);

            svg_transform_scale(T1, (float)string_w / (x2 - x1), (float)string_h / (y2 - y1));
            svg_transform_multiply(T, T, T1);
        }

        /* render string into svg canvas */
        {
            float x, y;
            float dx, dy;

            for (y = ny1; y < ny2; y++)
                for (x = nx1; x < nx2; x++)
                {
                    svg_transform_pos(&dx, &dy, x, y, T);
                    if (0 <= dx && dx < string_w)
                        if (0 <= dy && dy < string_h)
                        {
                            if (gd_get_buf_pixel_16((U8*) svg_wb_buffer, svg_wb_width, (S32) dx, (S32) dy))
                            {
                                gdi_act_put_pixel((int)x, (int)y, svg_context->style.fill_color);
                            }
                        }
                }
        }
    }
    return SVG_OK;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


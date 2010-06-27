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

// #define DEBUG_PRINT_RENDER_TREE

#include "xml_def.h"

#include "svg_internal.h"
#include "svg_vpath.h"
#include "svg_svp.h"
#include "svg_render.h"
#include "svg_parser.h"
#include "svg_transform.h"


typedef struct
{
    char *name;
      svg_enum(*render_func) (svg_element_t *node);
} RENDER_TABLE;

RENDER_TABLE render_table[] = 
{
    {"svg", NULL},
    {"group", NULL},
    {"defs", NULL},
    {"use", svg_render_use},
    {"symbol", NULL},
    {"path", svg_render_path},
    {"circle", svg_render_circle},
    {"ellipse", svg_render_ellipse},
    {"line", svg_render_line},
    {"rect", svg_render_rect},
    {"text", svg_render_text},
    {"gradient", NULL},
    {"gradient_stop", NULL},
    {"pattern", NULL},
    {"image", svg_render_image},
    {"animate", svg_render_animate},
    {"animateMotion", svg_render_animate_motion},
    {"font", NULL},
    {"glyph", NULL},
    {"polygon", svg_render_polygon},
    {"switch", NULL},

    {"NULL", NULL}  /* DUMMY END MARK */
};


/*****************************************************************************
 * FUNCTION
 *  svg_inherit_transform
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transform       [?]         
 *  callback        [IN]        
 *  node            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svg_inherit_transform(float transform[6], svg_enum(*callback) (svg_element_t *), svg_element_t *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_style_t backup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    backup = svg_context->style;

    svg_context->style.flag |= SVG_STYLE_FLAG_TRANSFORM;
    svg_transform_multiply(svg_context->style.transform, transform, svg_context->style.transform);

    callback(node);

    svg_context->style = backup;
}


/*****************************************************************************
 * FUNCTION
 *  svg_inherit_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 *  node            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svg_inherit_style(svg_enum(*callback) (svg_element_t *), svg_element_t *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_style_t backup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    backup = svg_context->style;

    if (node->style->flag & SVG_STYLE_FLAG_FONT_SIZE)
    {
        svg_context->style.font_size = node->style->font_size;
    }

    if (node->style->flag & SVG_STYLE_FLAG_TRANSFORM)
    {
        svg_transform_multiply(svg_context->style.transform, node->style->transform, svg_context->style.transform);
    }

    if (node->style->flag & SVG_STYLE_FLAG_COLOR)
    {
        svg_context->style.color = node->style->color;
    }

    if (node->style->flag & SVG_STYLE_FLAG_FILL)
    {
        svg_context->style.fill_color_type = node->style->fill_color_type;
        if (node->style->fill_color_type == SVG_COLOR_TYPE_USING_CURRENT_COLOR)
        {
            svg_context->style.fill_color = svg_context->style.color;
            svg_context->style.fill_color_type = SVG_COLOR_TYPE_HWRGB;
        }
        else
        {
            svg_context->style.fill_color = node->style->fill_color;
        }
    }

    if (node->style->flag & SVG_STYLE_FLAG_STROKE_SIZE)
    {
        svg_context->style.stroke_size = node->style->stroke_size;
    }

    if (node->style->flag & SVG_STYLE_FLAG_STROKE_COLOR)
    {
        svg_context->style.stroke_color_type = node->style->stroke_color_type;
        if (node->style->stroke_color_type == SVG_COLOR_TYPE_USING_CURRENT_COLOR)
        {
            svg_context->style.stroke_color = svg_context->style.color;
            svg_context->style.stroke_color_type = SVG_COLOR_TYPE_HWRGB;
        }
        else
        {
            svg_context->style.stroke_color = node->style->stroke_color;
        }

    }

    if (node->style->flag & SVG_STYLE_FLAG_FONT_WEIGHT)
    {
        svg_context->style.font_weight = svg_style_font_weight(node->style->font_weight, svg_context->style.font_weight);
    }

    if (node->style->flag & SVG_STYLE_FLAG_TEXT_ANCHOR)
    {
        svg_context->style.text_anchor = node->style->text_anchor;
    }

    if (node->style->flag & SVG_STYLE_FLAG_FONT_FAMILY)
    {
        svg_context->style.font_family = node->style->font_family;
    }

    if (node->style->flag & SVG_STYLE_FLAG_LINE_JOIN)
    {
        svg_context->style.join = node->style->join;
    }

    if (node->style->flag & SVG_STYLE_FLAG_LINE_CAP)
    {
        svg_context->style.cap = node->style->cap;
    }

    if (node->style->flag & SVG_STYLE_FLAG_LINE_MITER_LIMIT)
    {
        svg_context->style.miter_limit = node->style->miter_limit;
    }

    if (node->style->flag & SVG_STYLE_FLAG_STROKE_DASH)
    {
        svg_context->style.dash.offset = node->style->dash.offset;
        svg_context->style.dash.list = node->style->dash.list;
        svg_context->style.dash.n = node->style->dash.n;
    }

    svg_context->style.flag |= node->style->flag;

    /* self transform , for animate used. */
    svg_transform_multiply(svg_context->style.transform, node->animate_transform, svg_context->style.transform);

    callback(node);

    svg_context->style = backup;
}


/*****************************************************************************
 * FUNCTION
 *  svg_render
 * DESCRIPTION
 *  
 * PARAMETERS
 *  root        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_render(svg_element_t *root)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int level = 0;
    svg_element_t *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!gdi_image_progress_callback())
        SVG_RAISE(SVG_FAIL_TIMEOUT);

    if (root == NULL)
    {
        return SVG_FAIL;
    }

    if(svg_check_stack_overflow()!= SVG_OK)
        return SVG_FAIL_STACK_WILL_OVERFLOW;
                
    level++;

#ifdef DEBUG_PRINT_RENDER_TREE
    {
        extern int svg_memory_total;
        int i;

        printf("\n%d", svg_memory_total);
        for (i = 1; i < level; i++)
        {
            printf("  ");
        }
    }

    printf("<%s>", render_table[root->type].name);
    if (root->id)
    {
        printf("id(%s)", root->id);
    }
#endif /* DEBUG_PRINT_RENDER_TREE */ 

    /*
     * // process animate   
     * if(root->child && root->child->type == SVG_ELEMENT_TYPE_ANIMATE)
     * {
     * for(node = root->child;node;node = node->sib)
     * svg_render_animate(node);
     * }
     */
    /* rendering current node */
    if (render_table[root->type].render_func)
    {
        render_table[root->type].render_func(root);
    }

    /* visit childs */
    for (node = root->child; node; node = node->sib)
    {
        /* visit all child nodes */
        if (node->style == NULL /* no style & no animate_transform */
            && node->animate_transform[0] == 1
            && node->animate_transform[1] == 0
            && node->animate_transform[2] == 0
            && node->animate_transform[3] == 1 && node->animate_transform[4] == 0 && node->animate_transform[5] == 0)
        {
            svg_enum ret = svg_render(node);

            if (ret != SVG_OK)
            {
                return ret;
            }
        }
        else
        {
            svg_inherit_style(svg_render, node);
        }
    }

#ifdef DEBUG_PRINT_RENDER_TREE
    {
        extern int svg_memory_total;
        int i;

        printf("\n%d", svg_memory_total);
        for (i = 1; i < level; i++)
        {
            printf("  ");
        }
    }

    printf("</%s>", render_table[root->type].name);
    if (root->id)
    {
        printf("id(%s)", root->id);
    }
#endif /* DEBUG_PRINT_RENDER_TREE */ 

    level--;
    return SVG_OK;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


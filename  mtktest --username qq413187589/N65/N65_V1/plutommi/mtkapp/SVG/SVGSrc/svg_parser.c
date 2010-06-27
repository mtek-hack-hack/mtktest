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


#include "svg_internal.h"
#include "svg_vpath.h"
#include "svg_parser.h"
#include "svg_element.h"

static svg_element_t **svg_parser_container_list;
static S32 svg_parser_container_list_count;
static S32 svg_parser_container_list_max;

static S32 unknown_element_depth = 0;
static S32 not_render_element_depth = 0;

static const svg_parser_table_t SVG_PARSER_TABLE[] = 
{
    {"svg", svg_parser_element_svg, NULL, TRUE},
    {"g", svg_parser_element_group, NULL, TRUE},
    {"rect", svg_parser_element_rect, NULL, TRUE},
    {"line", svg_parser_element_line, NULL, TRUE},
    {"path", svg_parser_element_path, NULL, TRUE},
    {"animate", svg_parser_element_animate, NULL, TRUE},
    {"defs", svg_parser_element_defs, NULL, FALSE},
    {"font", svg_parser_element_font, NULL, FALSE},
    {"font-face", svg_parser_element_font_face, NULL, FALSE},
    {"missing-glyph", svg_parser_element_missing_glyph, NULL, FALSE},
    {"glyph", svg_parser_element_glyph, NULL, FALSE},
    {"text", svg_parser_element_text, svg_parser_element_text_data, TRUE},
    {"image", svg_parser_element_image, NULL, TRUE},
    {"animateMotion", svg_parser_element_animate_motion, NULL, TRUE},
    {"mpath", svg_parser_element_mpath, NULL, TRUE},
    {"circle", svg_parser_element_circle, NULL, TRUE},
    {"polygon", svg_parser_element_polygon, NULL, TRUE},
    {"hkern", svg_parser_element_hkern, NULL, FALSE},
    {"ellipse", svg_parser_element_ellipse, NULL, TRUE},
    {"polyline", svg_parser_element_polyline, NULL, TRUE},
    {"animateTransform", svg_parser_element_animate_motion, NULL, TRUE},
    {"switch", svg_parser_element_switch, NULL, TRUE},
    {"use", svg_parser_element_use, NULL, TRUE},
};

#define SVG_PARSER_TABLE_ITEMS (sizeof(SVG_PARSER_TABLE)/sizeof(SVG_PARSER_TABLE[0]))


/*****************************************************************************
 * FUNCTION
 *  svg_parser_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void svg_parser_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unknown_element_depth = 0;
    not_render_element_depth = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_read_start_element
 * DESCRIPTION
 *  
 * PARAMETERS
 *  no_used     [?]         
 *  el          [IN]        
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_read_start_element(void *no_used, const char *el, const char **attr, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;
    svg_element_t *element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!gdi_image_progress_callback())
        SVG_RAISE(SVG_FAIL_TIMEOUT);
    
    if (unknown_element_depth)
    {
        unknown_element_depth++;
        return;
    }
    if (el == NULL)
    {
        return;
    }

    if (strncmp(el, "svg:", 4) == 0)
    {
        el += 4;    /* ignore namespace 'svg:' */
    }

    for (index = 0; index < SVG_PARSER_TABLE_ITEMS; index++)
        if (strcmp(SVG_PARSER_TABLE[index].tag, el) == 0)
        {
            break;
        }
    if (index >= SVG_PARSER_TABLE_ITEMS)    /* didn't match any thing */
    {
        unknown_element_depth++;    /* this tag group we should ignore */
        return;
    }

    /* execute parse element function */
    if (SVG_PARSER_TABLE[index].parse_element)
        if (SVG_PARSER_TABLE[index].parse_element(&element, (U8 **) attr) != SVG_OK)
        {
            unknown_element_depth++;    /* parseing error, treat as unknown tag */
            return;
        }

    /* parse id */
    {
        U8 *id;

        /* have name, we should keep this name into hash */
        if (svg_attr_get_string((U8 **) attr, (U8*) "id", &id, NULL) == SVG_OK)
        {
            U8 *ret_id;

            svg_hash_add(svg_context->elements, id, element, &ret_id);  /* add into hash */
            element->id = ret_id;
        }
    }
    /* parse style */
    {
        svg_style_parser(&(element->style), (U8 **) attr);
    }

    /* add into parent */
    if (    /* not_render_element_depth == 0  && */
           SVG_PARSER_TABLE[index].need_add_to_render_tree)
    {
        svg_element_t *parent = svg_parser_container_top();

        if (parent)
        {

            /* parent is switch */
            if (parent->type == SVG_ELEMENT_TYPE_SWITCH
                /* AND still not find an true statement */
                && (parent->X.sw.can_be_execute
                    /* OR this statement is false */
                    || (element->style != NULL && (element->style->flag & SVG_STYLE_FLAG_SWITCH_FAIL))))
            {
                /* just ignore this node */
            }
            else
            {
                svg_element_add(parent, element);

                if (parent->type == SVG_ELEMENT_TYPE_SWITCH)
                {
                    parent->X.sw.can_be_execute = MMI_TRUE;
                }
            }
        }
        else
        {
            svg_context->root = element;
        }
    }

    if (not_render_element_depth || !SVG_PARSER_TABLE[index].need_add_to_render_tree)
    {
        not_render_element_depth++;
    }

    // push to container list if this element is container
    //if(SVG_PARSER_TABLE[index].is_container)
    svg_parser_container_push(element);
}


/*****************************************************************************
 * FUNCTION
 *  svg_read_end_element
 * DESCRIPTION
 *  
 * PARAMETERS
 *  no_used     [?]         
 *  el          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_read_end_element(void *no_used, const char *el, S32 error)
{
    if(!gdi_image_progress_callback())
        SVG_RAISE(SVG_FAIL_TIMEOUT);

    if (unknown_element_depth)
    {
        unknown_element_depth--;
        return;
    }
    if (not_render_element_depth)
    {
        not_render_element_depth--;
    }

    svg_parser_container_pop();
}


/*****************************************************************************
 * FUNCTION
 *  svg_read_data_element
 * DESCRIPTION
 *  
 * PARAMETERS
 *  no_used     [?]         
 *  el          [IN]        
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_read_data_element(void *no_used, const char *el, const char *value, int len, S32 error)
{
    int index;

    if(!gdi_image_progress_callback())
        SVG_RAISE(SVG_FAIL_TIMEOUT);
    
    if (unknown_element_depth)
    {
        return;
    }

    if (el == NULL)
    {
        return;
    }
    if (strncmp(el, "svg:", 4) == 0)
    {
        el += 4;    /* ignore namespace 'svg:' */
    }

    for (index = 0; index < SVG_PARSER_TABLE_ITEMS; index++)
        if (strcmp(SVG_PARSER_TABLE[index].tag, el) == 0)
        {
            break;
        }

    if (index >= SVG_PARSER_TABLE_ITEMS)    /* didn't match any thing */
    {
        return;
    }

    if (SVG_PARSER_TABLE[index].parse_data)
    {
        SVG_PARSER_TABLE[index].parse_data(svg_parser_container_top(), (U8*) value, (U32) len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_container_list_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void svg_parser_container_list_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_parser_container_list = NULL;
    svg_parser_container_list_max = 0;
    svg_parser_container_list_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_container_list_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void svg_parser_container_list_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (svg_parser_container_list)
    {
        svg_mem_free(svg_parser_container_list);
    }
    svg_parser_container_list = NULL;
    svg_parser_container_list_max = 0;
    svg_parser_container_list_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_container_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  container       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_parser_container_push(svg_element_t *container)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (svg_parser_container_list_count >= svg_parser_container_list_max)
    {
        svg_element_t **list =
            (svg_element_t **) svg_mem_malloc(sizeof(svg_element_t*) * (svg_parser_container_list_max + 16));
        if (svg_parser_container_list)
        {
            memcpy(list, svg_parser_container_list, sizeof(svg_element_t*) * svg_parser_container_list_max);
            svg_mem_free(svg_parser_container_list);
        }
        svg_parser_container_list = list;
        svg_parser_container_list_max += 16;
    }
    svg_parser_container_list[svg_parser_container_list_count++] = container;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_container_pop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
svg_element_t *svg_parser_container_pop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (svg_parser_container_list_count <= 0)
    {
        SVG_RAISE(SVG_FAIL_PARSER_FORMAT);
    }
    return svg_parser_container_list[--svg_parser_container_list_count];
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_container_top
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
svg_element_t *svg_parser_container_top(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (svg_parser_container_list_count)
    {
        return svg_parser_container_list[svg_parser_container_list_count - 1];
    }
    else
    {
        return NULL;
    }
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


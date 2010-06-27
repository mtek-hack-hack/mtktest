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
#include "svg_element.h"
#include "svg_vpath.h"
#include "svg_parser.h"
#include "svg_svp.h"
#include "svg_render.h"


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_animate_attributes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  e           [?]         
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_parser_element_animate_attributes(svg_element_t *e, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* attributeName */
    if (svg_attr_get_string(attr, (U8*) "attributeName", &data, (U8*) "") == SVG_OK)
    {
        e->X.animate.attribute_name = svg_const_pool(data);
    }

    /* calcMode */
    svg_attr_get_string(attr, (U8*) "calcMode", &data, (U8*) "linear");
    if (STRCMP(data, "discrete") == 0)
    {
        e->X.animate.calc_mode = SVG_ANIMATE_DISCRETE;
    }
    else if (STRCMP(data, "paced") == 0)
    {
        e->X.animate.calc_mode = SVG_ANIMATE_PACED;
    }
    else if (STRCMP(data, "spline") == 0)
    {
        e->X.animate.calc_mode = SVG_ANIMATE_SPLINE;
    }
    else
    {
        e->X.animate.calc_mode = SVG_ANIMATE_LINEAR;
    }

    /* additive */
    svg_attr_get_string(attr, (U8*) "additive", &data, (U8*) "replace");
    if (STRCMP(data, "sum") == 0)
    {
        e->X.animate.is_additive_sum = TRUE;    /* sum */
    }
    else
    {
        e->X.animate.is_additive_sum = FALSE;   /* replace */
    }

    /* accumulate */
    svg_attr_get_string(attr, (U8*) "accumulate", &data, (U8*) "none");
    if (STRCMP(data, "sum") == 0)
    {
        e->X.animate.is_accumulate = TRUE;  /* sum */
    }
    else
    {
        e->X.animate.is_accumulate = FALSE; /* none */
    }

    /* repeat_count */
    svg_attr_get_string(attr, (U8*) "repeatCount", &data, (U8*) "1");
    if (STRCMP(data, "indefinite") == 0)    /*  */
    {
        e->X.animate.repeat_count = 0;
    }
    else
    {
        e->X.animate.repeat_count = svg_strtod(data, &data);
    }

    /* values */
    if (svg_attr_get_string(attr, (U8*) "values", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.values = svg_const_pool(data);
    }

    /* from */
    if (svg_attr_get_string(attr, (U8*) "from", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.from = svg_const_pool(data);
    }
    /* to */
    if (svg_attr_get_string(attr, (U8*) "to", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.to = svg_const_pool(data);
    }

    /* by */
    if (svg_attr_get_string(attr, (U8*) "by", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.by = svg_const_pool(data);
    }

    /* begin */
    if (svg_attr_get_string(attr, (U8*) "begin", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.begin = svg_const_pool(data);
    }

    /* end */
    if (svg_attr_get_string(attr, (U8*) "end", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.end = svg_const_pool(data);
    }

    /* path */
    if (svg_attr_get_string(attr, (U8*) "path", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.path_data = svg_const_pool(data);
    }

    /* rotate */
    if (svg_attr_get_string(attr, (U8*) "rotate", &data, (U8*) "0") == SVG_OK)
    {
        if (STRCMP(data, "auto"))
        {
            e->X.animate.motion_rotate = SVG_ANIMATE_MOTION_ROTATE;
        }
        else if (STRCMP(data, "auto-reverse"))
        {
            e->X.animate.motion_rotate = SVG_ANIMATE_MOTION_ROTATE_REVERSE;
        }
    }

    /* dur */
	e->X.animate.dur = 1;// initialize to 1 seconds.
    if (svg_attr_get_string(attr, (U8*) "dur", &data, (U8*) "") == SVG_OK)
    {
        if (STRCMP(data, "indefinite") == 0 || STRCMP(data, "media") == 0)
        {
            e->X.animate.dur = 100000;//TODO: this should be handle this indefinite
        }
        else
        {
            svg_attr_get_clock_value(&e->X.animate.dur, attr, (U8*) "dur", (U8*) "0");
        }
    }

    /* fill */
    svg_attr_get_string(attr, (U8*) "fill", &data, (U8*) "remove");
    if (STRCMP(data, "freeze") == 0)
    {
        e->X.animate.is_freeze = TRUE;
    }
    else
    {
        e->X.animate.is_freeze = FALSE;
    }

    /* xlink:href */
    if (svg_attr_get_string(attr, (U8*) "xlink:href", &data, (U8*) NULL) == SVG_OK)
    {
        void *target_object = svg_hash_find(svg_context->elements, data + 1, NULL);

        if (target_object)
        {
            e->X.animate.object = target_object;
        }
    }

    /* animateTransform type */
    if (svg_attr_get_string(attr, (U8*) "type", &data, (U8*) "") == SVG_OK)
    {
        if (STRCMP(data, "translate") == 0)
        {
            e->X.animate.tramsform_type = SVG_TRANSFORM_TYPE_TRANSLATE;
        }
        else if (STRCMP(data, "rotate") == 0)
        {
            e->X.animate.tramsform_type = SVG_TRANSFORM_TYPE_ROTATE;
        }
        else if (STRCMP(data, "scale") == 0)
        {
            e->X.animate.tramsform_type = SVG_TRANSFORM_TYPE_SCALE;
        }
        else if (STRCMP(data, "skewX") == 0)
        {
            e->X.animate.tramsform_type = SVG_TRANSFORM_TYPE_SKEWX;
        }
        else if (STRCMP(data, "skewY") == 0)
        {
            e->X.animate.tramsform_type = SVG_TRANSFORM_TYPE_SKEWY;
        }
        else
        {
            e->X.animate.tramsform_type = SVG_TRANSFORM_TYPE_NONE;
        }
    }

    /* keySplines */
    if (svg_attr_get_string(attr, (U8*) "keySplines", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.keysplines = svg_const_pool(data);
    }

    /* keyTimes */
    if (svg_attr_get_string(attr, (U8*) "keyTimes", &data, (U8*) "0") == SVG_OK)
    {
        e->X.animate.keytimes = svg_const_pool(data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_animate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_animate(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_element_create(ret_element, SVG_ELEMENT_TYPE_ANIMATE);
    if (ret == SVG_OK)
    {
        svg_element_t *parent, *node;

        node = *ret_element;
        svg_parser_element_animate_attributes(node, attr);

        if (node->X.animate.object) /* already has target object */
        {
            parent = node->X.animate.object;
        }
        else
        {
            parent = svg_parser_container_top();    /* use parent as target object */
        }

        switch (parent->type)
        {
            case SVG_ELEMENT_TYPE_RECT:
                if (STRCMP(node->X.animate.attribute_name, "width") == 0)
                {
                    node->X.animate.variable_address = &parent->X.rect.width;
                    node->X.animate.variable_flag = SVG_VAR_TYPE_WIDTH;
                }
                else if (STRCMP(node->X.animate.attribute_name, "height") == 0)
                {
                    node->X.animate.variable_address = &parent->X.rect.height;
                    node->X.animate.variable_flag = SVG_VAR_TYPE_HEIGHT;
                }
                else if (STRCMP(node->X.animate.attribute_name, "x") == 0)
                {
                    node->X.animate.variable_address = &parent->X.rect.x;
                    node->X.animate.variable_flag = SVG_VAR_TYPE_WIDTH;
                }
                else if (STRCMP(node->X.animate.attribute_name, "y") == 0)
                {
                    node->X.animate.variable_address = &parent->X.rect.y;
                    node->X.animate.variable_flag = SVG_VAR_TYPE_HEIGHT;
                }
                break;
        }

        /* general attribute */
        if (parent->style == NULL)  /* default style value */
        {
            U8 *attr[3];

            attr[0] = node->X.animate.attribute_name;
            attr[1] = (U8*) "0";
            attr[2] = NULL;

            svg_style_parser(&parent->style, attr);
        }

        if (STRCMP(node->X.animate.attribute_name, "font-size") == 0)
        {
            node->X.animate.variable_address = &parent->style->font_size;
            node->X.animate.variable_flag = SVG_VAR_TYPE_FONT_SIZE;

            parent->style->flag |= SVG_STYLE_FLAG_FONT_SIZE;
        }
        else if (STRCMP(node->X.animate.attribute_name, "stroke-width") == 0)
        {
            node->X.animate.variable_address = &parent->style->stroke_size;
            node->X.animate.variable_flag = SVG_VAR_TYPE_WIDTH;

            parent->style->flag |= SVG_STYLE_FLAG_STROKE_SIZE;
        }
        else if (STRCMP(node->X.animate.attribute_name, "fill") == 0)
        {
            node->X.animate.variable_address = &parent->style->fill_color;
            node->X.animate.variable_flag = SVG_VAR_TYPE_COLOR;

            parent->style->flag |= SVG_STYLE_FLAG_FILL;
        }
        else if (STRCMP(node->X.animate.attribute_name, "stroke") == 0)
        {
            node->X.animate.variable_address = &parent->style->stroke_color;
            node->X.animate.variable_flag = SVG_VAR_TYPE_COLOR;
            parent->style->flag |= SVG_STYLE_FLAG_STROKE_COLOR;
        }

        /* fetch predefine value if unset */
		if(node->X.animate.variable_address)
        {
            if (node->X.animate.from == NULL && (node->X.animate.to || node->X.animate.by))
            {
                U8 data[32];

                sprintf((char*)data, "%lf", *(float*)node->X.animate.variable_address);
                node->X.animate.from = svg_const_pool(data);
            }
        }


        /* call render animate to initialize the variable */
        svg_render_animate(node);
    }
    return ret;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


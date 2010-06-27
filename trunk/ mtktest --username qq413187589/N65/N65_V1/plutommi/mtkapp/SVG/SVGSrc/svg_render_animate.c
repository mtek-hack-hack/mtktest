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
#include "svg_parser.h"


/*****************************************************************************
 * FUNCTION
 *  svg_render_animate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_render_animate(svg_element_t *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float begin = 0;
    float diff_time, diff_time1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node->X.animate.variable_address == NULL)
    {
        return SVG_FAIL;
    }

    if (node->X.animate.begin)
    {
        svg_to_clock_value(&begin, node->X.animate.begin);
    }

    diff_time = svg_context->current_time - begin;

    /* record the maximum end time */
    if (svg_context->max_end_time >= 0  /* not infinate loop */
        && svg_context->max_end_time < begin + node->X.animate.dur * node->X.animate.repeat_count)
    {
        svg_context->max_end_time = begin + node->X.animate.dur * node->X.animate.repeat_count;
    }

    if (diff_time >= 0 && diff_time <= node->X.animate.dur * node->X.animate.repeat_count + 1)
    {
        U8 data[64];
        U8 *from_unit = NULL;
        U8 *to_unit = NULL;
        float from = 0;
        float to = 0;
        float current_value;

        if (diff_time >= node->X.animate.dur * node->X.animate.repeat_count - 1)
        {
            diff_time = node->X.animate.dur * node->X.animate.repeat_count;
        }
        for (diff_time1 = diff_time; diff_time1 > node->X.animate.dur;)
        {
            diff_time1 -= node->X.animate.dur;
        }

        if (node->X.animate.from || node->X.animate.to || node->X.animate.by)
        {

            if (node->X.animate.from)
            {
                from_unit = node->X.animate.from;
                from = svg_strtod(from_unit, &from_unit);
            }
            if (node->X.animate.to)
            {
                to_unit = node->X.animate.to;
                to = svg_strtod(to_unit, &to_unit);
            }
            else if (node->X.animate.by)
            {
                to_unit = node->X.animate.by;
                to = from + svg_strtod(to_unit, &to_unit);
            }
            if (from_unit == NULL)
            {
                from_unit = to_unit;
            }

            switch (node->X.animate.calc_mode)
            {
                case SVG_ANIMATE_DISCRETE:
                    if (diff_time >= node->X.animate.dur && (diff_time1 <= 1 || diff_time1 == node->X.animate.dur))
                    {
                        current_value = to;
                    }
                    else
                    {
                        current_value = from;
                    }
                    break;
                case SVG_ANIMATE_SPLINE:
                    if (node->X.animate.keysplines)
                    {
                        float x1, y1, x2, y2;

                        if (svg_get_xy_from_keyspline(&x1, &y1, &x2, &y2, 0, node->X.animate.keysplines) == SVG_OK)
                        {
                            current_value = svg_interpolation_value_via_keyspline(
                                                from,
                                                to, /* low high */
                                                diff_time1 / node->X.animate.dur,     /* time */
                                                x1,
                                                y1,
                                                x2,
                                                y2);
                            break;
                        }
                    }
                default:
                case SVG_ANIMATE_LINEAR:
                    current_value = (from * (node->X.animate.dur - diff_time1) + to * diff_time1) / node->X.animate.dur;
                    break;
            }

            if (from_unit)
            {
                sprintf((char*)data, "%0.2lf%s", current_value, from_unit);
            }
            else
            {
                sprintf((char*)data, "%0.2lf", current_value);
            }

            /* write value into target variable */
            switch (node->X.animate.variable_flag)
            {
                case SVG_VAR_TYPE_WIDTH:
                    svg_to_length((float*)node->X.animate.variable_address, data, TRUE);
                    break;
                case SVG_VAR_TYPE_HEIGHT:
                    svg_to_length((float*)node->X.animate.variable_address, data, FALSE);
                    break;
                case SVG_VAR_TYPE_FONT_SIZE:
                    svg_to_length((float*)node->X.animate.variable_address, data, FALSE);
                    break;
                case SVG_VAR_TYPE_COLOR:
                {
                    U32 FA, FR, FG, FB;
                    U32 TA, TR, TG, TB;
                    U32 A, R, G, B;
                    gdi_color c;

                    svg_style_parse_color(&c, node->X.animate.from);
                    gdi_act_color_to_rgb(&FA, &FR, &FG, &FB, c);

                    svg_style_parse_color(&c, node->X.animate.to);
                    gdi_act_color_to_rgb(&TA, &TR, &TG, &TB, c);

                    A = (U8) ((FA * (node->X.animate.dur - diff_time1) + TA * diff_time1) / node->X.animate.dur);
                    R = (U8) ((FR * (node->X.animate.dur - diff_time1) + TR * diff_time1) / node->X.animate.dur);
                    G = (U8) ((FG * (node->X.animate.dur - diff_time1) + TG * diff_time1) / node->X.animate.dur);
                    B = (U8) ((FB * (node->X.animate.dur - diff_time1) + TB * diff_time1) / node->X.animate.dur);

                    *((U32*) node->X.animate.variable_address) = gdi_act_color_from_rgb(A, R, G, B);
                }
                    break;
            }

        }
        else if (node->X.animate.values)
        {
            switch (node->X.animate.variable_flag)
            {
                case SVG_VAR_TYPE_FONT_SIZE:
                case SVG_VAR_TYPE_HEIGHT:
                case SVG_VAR_TYPE_WIDTH:
                    svg_interpolation_values(
                        (float*)node->X.animate.variable_address,
                        node->X.animate.values,
                        (BOOL) (node->X.animate.variable_flag == SVG_VAR_TYPE_WIDTH),
                        node->X.animate.calc_mode,
                        node->X.animate.keysplines,
                        node->X.animate.keytimes,
                        diff_time1,
                        node->X.animate.dur);
                    break;
                default:
                    /* SVG_ASSERT(0); */
                    break;
            }
        }

    }
    return SVG_OK;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


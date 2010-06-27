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



/*****************************************************************************
 * FUNCTION
 *  svg_render_animate_motion
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_render_animate_motion(svg_element_t *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float begin = 0;
    float diff_time, diff_time1;
    svg_element_t *target;
    float *T;
    float T1[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node->X.animate.variable_address == NULL)
    {
        return SVG_FAIL;
    }

    target = (svg_element_t*) node->X.animate.variable_address;
    T = (float*)target->animate_transform;
    if (target->animate_transform_serial != svg_context->current_serial)
    {
        target->animate_transform_serial = svg_context->current_serial;
        svg_transform_identify(T);
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
        float xy[2];
        float rotate;

        if (diff_time >= node->X.animate.dur * node->X.animate.repeat_count)
        {
            diff_time = node->X.animate.dur * node->X.animate.repeat_count;
        }
        for (diff_time1 = diff_time; diff_time1 > node->X.animate.dur;)
        {
            diff_time1 -= node->X.animate.dur;
        }

        /* Is animate motion path */
        if (node->X.animate.motion_path_type)
        {
            switch (node->X.animate.motion_path_type)
            {
                case SVG_ANIMATE_MOTION_SEGMENT:
                case SVG_ANIMATE_MOTION_PATH:
                {
                    svg_vpath_interpolation(
                        node->X.animate.motion_path_type,
                        xy,
                        &rotate,
                        (svg_vpath_t*) node->X.animate.motion_path,
                        node->X.animate.calc_mode,
                        node->X.animate.keysplines,
                        node->X.animate.keytimes,
                        diff_time,
                        node->X.animate.dur);
                }
                    break;
                default:
                    SVG_ASSERT(0);
            }

            /* alignment to the normal vector */
            {
                svg_transform_translate(T1, xy[0], xy[1]);
                svg_transform_multiply(T, T1, T);

                switch (node->X.animate.motion_rotate)
                {
                    case SVG_ANIMATE_MOTION_ROTATE_NONE:
                        svg_transform_identify(T1);
                        break;
                    case SVG_ANIMATE_MOTION_ROTATE:
                        svg_transform_rotate_radian(T1, rotate);
                        break;
                    case SVG_ANIMATE_MOTION_ROTATE_REVERSE:
                        svg_transform_rotate_radian(T1, rotate + M_PI);
                }
                svg_transform_multiply(T, T1, T);
            }
        }
        else if (node->X.animate.tramsform_type)    /* Is animate transform */
        {
            switch (node->X.animate.tramsform_type)
            {
                case SVG_TRANSFORM_TYPE_TRANSLATE:
                {
                    BOOL is_width[2] = {TRUE, FALSE};
                    float from_xy[2];
                    float to_xy[2];
                    float current[2];
                    int cnt;

                    cnt = svg_interpolation_from_to(
                            current,
                            from_xy,
                            to_xy,
                            2,
                            node->X.animate.from,
                            node->X.animate.to,
                            node->X.animate.by,
                            is_width,
                            node->X.animate.calc_mode,
                            node->X.animate.keysplines,
                            diff_time1,
                            node->X.animate.dur);
                    if (cnt == 0)
                    {
                        current[1] = current[0] = 0;
                    }
                    else if (cnt == 1)
                    {
                        current[1] = current[0];
                    }

                    svg_transform_translate(T1, current[0], current[1]);
                    svg_transform_multiply(T, T1, T);

                    if (target->style)
                    {
                        svg_transform_set_translate(target->style->transform, 0, 0);
                    }
                }
                    break;
                case SVG_TRANSFORM_TYPE_SCALE:
                {
                    BOOL is_width[2] = {TRUE, FALSE};
                    float from[2];
                    float to[2];
                    float current[2];
                    int cnt;

                    cnt = svg_interpolation_from_to(
                            current,
                            from,
                            to,
                            2,
                            node->X.animate.from,
                            node->X.animate.to,
                            node->X.animate.by,
                            is_width,
                            node->X.animate.calc_mode,
                            node->X.animate.keysplines,
                            diff_time1,
                            node->X.animate.dur);
                    if (cnt == 0)
                    {
                        current[1] = current[0] = 1;
                    }
                    else if (cnt == 1)
                    {
                        current[1] = current[0];
                    }

                    svg_transform_scale(T1, current[0], current[1]);
                    svg_transform_multiply(T, T1, T);

                    if (target->style)
                    {
                        svg_transform_set_scale(target->style->transform, 1, 1);
                    }

                }
                    break;
                case SVG_TRANSFORM_TYPE_ROTATE:
                {
                    BOOL is_width[3] = {FALSE, TRUE, FALSE};
                    float from[3];
                    float to[3];
                    float current[3];
                    int cnt;

                    cnt = svg_interpolation_from_to(
                            current,
                            from,
                            to,
                            3,
                            node->X.animate.from,
                            node->X.animate.to,
                            node->X.animate.by,
                            is_width,
                            node->X.animate.calc_mode,
                            node->X.animate.keysplines,
                            diff_time1,
                            node->X.animate.dur);

                    if (cnt == 0)
                    {
                        current[2] = current[1] = current[0] = 0;
                    }
                    else if (cnt == 1)
                    {
                        current[2] = current[1] = 0;
                    }
                    else if (cnt == 2)
                    {
                        current[2] = 0;
                    }
                    svg_transform_rotate(T1, current[0]);
                    svg_transform_multiply(T, T1, T);

                    if (target->style)
                    {
                        svg_transform_set_rotate(target->style->transform, 0);
                    }

                }
                    break;
            }
        }

    }
    return SVG_OK;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


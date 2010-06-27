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
 *  svg_parser_element_animate_motion
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_animate_motion(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_element_create(ret_element, SVG_ELEMENT_TYPE_ANIMATE_MOTION);
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

        node->X.animate.variable_address = parent;
        node->X.animate.variable_flag = SVG_VAR_TYPE_TRANSFORM;

        if (node->X.animate.tramsform_type) /* is transform animate */
        {
            //SVG_DEBUG_ASSERT(0);
        }
        else    /* is animation motion */
        {

            if (node->X.animate.values) /* convert information into path */
            {
                float xy[2];
                svg_vpath_t *vpath;
                U8 *data = node->X.animate.values;

                vpath = svg_vpath_new(5);

                while (1)
                {
                    svg_to_xy_length(xy, data);
                    svg_vpath_line_to(vpath, xy[0], xy[1]);
                    data = (U8*) STRCHR(data, ';');
                    if (data)
                    {
                        data++;
                    }
                    else
                    {
                        break;
                    }
                }
                svg_vpath_update_length(vpath);
                node->X.animate.motion_path = (void*)vpath;
                node->X.animate.motion_path_type = SVG_ANIMATE_MOTION_SEGMENT;
            }
            else if (node->X.animate.from || node->X.animate.to || node->X.animate.by)
            {
                svg_vpath_t *vpath;
                float from[2] = {0, 0};
                float to[2] = {0, 0};

                if (node->X.animate.from)
                {
                    svg_to_xy_length(from, node->X.animate.from);
                }

                if (node->X.animate.to)
                {
                    svg_to_xy_length(to, node->X.animate.to);
                }
                else if (node->X.animate.by)
                {
                    svg_to_xy_length(to, node->X.animate.by);
                    to[0] += from[0];
                    to[1] += from[1];
                }

                vpath = svg_vpath_new(3);
                svg_vpath_move_to(vpath, from[0], from[1]);
                svg_vpath_line_to(vpath, to[0], to[1]);
                svg_vpath_update_length(vpath);

                node->X.animate.motion_path = (void*)vpath;
                node->X.animate.motion_path_type = SVG_ANIMATE_MOTION_SEGMENT;
            }
            else if (node->X.animate.path_data)
            {
                node->X.animate.motion_path = (void*)svg_parse_path_data((char*)node->X.animate.path_data);
                svg_vpath_update_length((svg_vpath_t*) node->X.animate.motion_path);
                node->X.animate.motion_path_type = SVG_ANIMATE_MOTION_PATH;
            }
        }

        /* call render animate to initialize the variable */
        if (node->X.animate.motion_path_type || node->X.animate.tramsform_type)
        {
            svg_render_animate_motion(node);
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_mpath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_mpath(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;
    svg_element_t *parent = svg_parser_container_top();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent)
        if (parent->type == SVG_ELEMENT_TYPE_ANIMATE_MOTION)
            if (svg_attr_get_string(attr, (U8*) "xlink:href", &data, (U8*) "0") == SVG_OK)
                if (*data == '#')
                {
                    svg_element_t *path;

                    path = (svg_element_t*) svg_hash_find(svg_context->elements, data + 1, NULL);
                    if (path)
                        if (path->type == SVG_ELEMENT_TYPE_PATH)
                        {
                            parent->X.animate.motion_path = (void*)path->X.path.vpath;
                            svg_vpath_update_length((svg_vpath_t*) parent->X.animate.motion_path);
                            parent->X.animate.motion_path_type = SVG_ANIMATE_MOTION_PATH;

                            svg_render_animate_motion(parent);
                        }

                }
    return SVG_FAIL;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


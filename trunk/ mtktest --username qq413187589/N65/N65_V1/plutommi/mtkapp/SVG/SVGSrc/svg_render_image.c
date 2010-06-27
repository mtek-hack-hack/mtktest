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
#include "svg_work_buffer.h"

#include "gd_primitive.h"
#include "svg_transform.h"


/*****************************************************************************
 * FUNCTION
 *  svg_render_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_render_image(svg_element_t *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float x1, y1, x2, y2;
    float nx1, nx2, ny1, ny2;
    float tx, ty;  /* for temp use */
    float T[6];
    S32 img_width, img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* origin bound box */
    x1 = node->X.image.x;
    y1 = node->X.image.y;
    x2 = x1 + node->X.image.width;
    y2 = y1 + node->X.image.height;

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

    // calculate resized image width/height
    // draw resized into working buffer
    if (node->X.image.is_from_file)
    {
        if (gdi_image_get_dimension_file((S8*) node->X.image.src, &img_width, &img_height) != GDI_SUCCEED)
        {
            return SVG_FAIL;
        }

    }
    else
    {
        gdi_image_get_dimension_mem(node->X.image.src_type,(U8*)node->X.image.src,node->X.image.src_len,&img_width,&img_height);
    }

    {
        svg_wb_resize_with_ratio(img_width, img_height);
        img_width = svg_wb_width;
        img_height = svg_wb_height;
    }
    gdi_layer_push_and_set_active((gdi_handle) svg_wb_layer);
    if (node->X.image.is_from_file)
    {
        gdi_image_draw_resized_file(0, 0, img_width, img_height, (S8*) node->X.image.src);
    }
    else
    {
        gdi_image_draw_resized_ext(
            0,
            0,
            img_width,
            img_height,
            (U8*) node->X.image.src,
            node->X.image.src_type,
            (U32) node->X.image.src_len);
    }
    gdi_layer_pop_and_restore_active();

    /* calculate mapping matrix */
    {
        float toR[6];
        float T1[6];

        /* mapping resized image into original coord */
        svg_transform_translate(T1, -x1, -y1);
        svg_transform_scale(T, (float)img_width / node->X.image.width, (float)img_height / node->X.image.height);
        svg_transform_multiply(toR, T, T1);
        /* mapping destination into original coord */
        svg_transform_invert(T, svg_context->style.transform);

        /* mapping destination into resized image coord */
        svg_transform_multiply(T, T, toR);
    }

    /* render image into svg canvas */
    {
        float x, y;
        float dx, dy;
        SVG_CLIP_TWO_RECT(
			nx1,
			ny1,
			nx2,
			ny2,
			gdi_act_layer->clipx1,
			gdi_act_layer->clipy1,
			gdi_act_layer->clipx2,
			gdi_act_layer->clipy2,
			return SVG_OK);

        for (y = ny1; y < ny2; y++)
            for (x = nx1; x < nx2; x++)
            {
                gdi_color c;

                svg_transform_pos(&dx, &dy, x, y, T);
                if (0 <= dx && dx < img_width)
                    if (0 <= dy && dy < img_height)
                    {
						U32 A,R,G,B;
                        c = gd_get_buf_pixel_16((U8*) svg_wb_buffer, svg_wb_width, (S32) dx, (S32) dy);
						gd_color_to_rgb_16(&A, &R, &G, &B, c);
                        gdi_act_put_pixel((int)x, (int)y, gdi_act_color_from_rgb(A,R,G,B));
                    }
            }
    }
    return SVG_OK;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


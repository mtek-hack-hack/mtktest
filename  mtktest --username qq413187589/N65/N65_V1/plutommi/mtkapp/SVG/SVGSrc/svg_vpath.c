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

#include "ctype.h"

#include "svg_internal.h"
#include "svg_vpath.h"
#define M_PI 3.14159265358979323846
#define EPSILON 1e-6


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  max_items       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_vpath_t *svg_vpath_new(U32 max_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 header_size = sizeof(svg_vpath_t);
    U32 path_size = sizeof(svg_pos_t) * (++max_items);

    svg_vpath_t *vpath = (svg_vpath_t*) svg_mem_malloc(header_size);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vpath == NULL)
    {
        return NULL;
    }

    vpath->max_len = max_items;

    vpath->path = (svg_pos_t*) svg_mem_malloc(path_size);
    if (vpath->path == NULL)
    {
        return NULL;
    }

    vpath->len = 0;
    vpath->open_index = -1;
    vpath->segments = 0;

    return vpath;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_vpath_free(svg_vpath_t *vpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_mem_free(vpath->path);
    svg_mem_free(vpath);
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_enlarge
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_enlarge(svg_vpath_t *vpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 max_items = vpath->max_len + 4;
    U32 path_size = sizeof(svg_pos_t) * max_items;

    svg_pos_t *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path = (svg_pos_t*) svg_mem_malloc(path_size);
    if (path == NULL)
    {
        return SVG_FAIL_NO_MEMORY;
    }

    /* copy data */
    memcpy(path, vpath->path, sizeof(svg_pos_t) * vpath->len);
    svg_mem_free(vpath->path);

    vpath->path = path;
    vpath->max_len = max_items;

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_dup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_vpath_t *svg_vpath_dup(svg_vpath_t *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 header_size = sizeof(svg_vpath_t);
    U32 path_size = sizeof(svg_pos_t) * (src->max_len);
    svg_vpath_t *vpath = (svg_vpath_t*) svg_mem_malloc(header_size);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(vpath, src, header_size);    /* copy source data */
    vpath->path = (svg_pos_t*) svg_mem_malloc(path_size);

    memcpy(vpath->path, src->path, path_size);  /* copy path data */

    return vpath;

}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_append
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]         
 *  cmd         [IN]        
 *  x           [IN]        
 *  y           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_append(svg_vpath_t *vpath, U8 cmd, float x, float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vpath->len == 0)
    {
        cmd = SVG_PATH_MOVE_TO;
    }

    if (cmd == SVG_PATH_MOVE_TO)
    {
        /* already in here , don't need to move */
        if (vpath->len > 1)
            if (fabs(vpath->path[vpath->len - 1].x - x) < EPSILON && fabs(vpath->path[vpath->len - 1].y - y) < EPSILON)
            {
                return SVG_OK;
            }

        if (vpath->len + 2 > vpath->max_len)
            if (svg_vpath_enlarge(vpath) != SVG_OK)
            {
                return SVG_FAIL_NO_MEMORY;
            }

        vpath->open_index = vpath->len;

        vpath->path[vpath->len].x = x;
        vpath->path[vpath->len].y = y;
        vpath->len++;

        vpath->path[vpath->len].x = x;
        vpath->path[vpath->len].y = y;
        vpath->len++;

    }
    else    /* LINE TO */
    {
        SVG_DEBUG_ASSERT(vpath->len > 0);

        /* the same position */
        if (fabs(vpath->path[vpath->len - 1].x - x) < EPSILON && fabs(vpath->path[vpath->len - 1].y - y) < EPSILON)
        {
            return SVG_OK;
        }

        if (vpath->len + 1 > vpath->max_len)
            if (svg_vpath_enlarge(vpath) != SVG_OK)
            {
                return SVG_FAIL_NO_MEMORY;
            }

        vpath->path[vpath->len].x = x;
        vpath->path[vpath->len].y = y;
        vpath->len++;
        vpath->segments++;
    }

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_move_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]         
 *  x           [IN]        
 *  y           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_move_to(svg_vpath_t *vpath, float x, float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return svg_vpath_append(vpath, SVG_PATH_MOVE_TO, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_line_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]         
 *  x           [IN]        
 *  y           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_line_to(svg_vpath_t *vpath, float x, float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return svg_vpath_append(vpath, SVG_PATH_LINE_TO, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_close(svg_vpath_t *vpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vpath->open_index >= 0)
        if (vpath->len > 0)
        {
            svg_vpath_append(
                vpath,
                SVG_PATH_LINE_TO,
                vpath->path[vpath->open_index].x,
                vpath->path[vpath->open_index].y);
            vpath->open_index = -1;
        }
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_transform
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath           [?]     
 *  transform       [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_transform(svg_vpath_t *vpath, float transform[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < vpath->len; i++)
    {
        float x, y;

        x = transform[0] * vpath->path[i].x + transform[2] * vpath->path[i].y + transform[4];
        y = transform[1] * vpath->path[i].x + transform[3] * vpath->path[i].y + transform[5];

        vpath->path[i].x = x;
        vpath->path[i].y = y;
    }
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_curve_to_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath           [?]         
 *  x0              [IN]        
 *  y0              [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  x3              [IN]        
 *  y3              [IN]        
 *  flatness        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_vpath_curve_to_internal(
        svg_vpath_t *vpath,
        float x0,
        float y0,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float flatness)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float x3_0, y3_0;
    float z3_0_dot;
    float z1_dot, z2_dot;
    float z1_perp, z2_perp;
    float max_perp_sq;

    float x_m, y_m;
    float xa1, ya1;
    float xa2, ya2;
    float xb1, yb1;
    float xb2, yb2;

    svg_check_stack_overflow();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x3_0 = x3 - x0;
    y3_0 = y3 - y0;

    /* z3_0_dot is dist z0-z3 squared */
    z3_0_dot = x3_0 * x3_0 + y3_0 * y3_0;

    if (z3_0_dot < 0.001)
    {
        goto nosubdivide;
    }

    // we can avoid subdivision if:
    // z1 has distance no more than flatness from the z0-z3 line
    // z1 is no more z0'ward than flatness past z0-z3
    // z1 is more z0'ward than z3'ward on the line traversing z0-z3
    // and correspondingly for z2 

    /* perp is distance from line, multiplied by dist z0-z3 */
    max_perp_sq = flatness * flatness * z3_0_dot;

    z1_perp = (y1 - y0) * x3_0 - (x1 - x0) * y3_0;
    if (z1_perp * z1_perp > max_perp_sq)
    {
        goto subdivide;
    }

    z2_perp = (y3 - y2) * x3_0 - (x3 - x2) * y3_0;
    if (z2_perp * z2_perp > max_perp_sq)
    {
        goto subdivide;
    }

    z1_dot = (x1 - x0) * x3_0 + (y1 - y0) * y3_0;
    if (z1_dot < 0 && z1_dot * z1_dot > max_perp_sq)
    {
        goto subdivide;
    }

    z2_dot = (x3 - x2) * x3_0 + (y3 - y2) * y3_0;
    if (z2_dot < 0 && z2_dot * z2_dot > max_perp_sq)
    {
        goto subdivide;
    }

    if (z1_dot + z1_dot > z3_0_dot)
    {
        goto subdivide;
    }

    if (z2_dot + z2_dot > z3_0_dot)
    {
        goto subdivide;
    }

  nosubdivide:
    svg_vpath_line_to(vpath, x3, y3);
    return;

  subdivide:
    xa1 = (x0 + x1) * 0.5;
    ya1 = (y0 + y1) * 0.5;
    xa2 = (x0 + 2 * x1 + x2) * 0.25;
    ya2 = (y0 + 2 * y1 + y2) * 0.25;
    xb1 = (x1 + 2 * x2 + x3) * 0.25;
    yb1 = (y1 + 2 * y2 + y3) * 0.25;
    xb2 = (x2 + x3) * 0.5;
    yb2 = (y2 + y3) * 0.5;
    x_m = (xa2 + xb1) * 0.5;
    y_m = (ya2 + yb1) * 0.5;
    svg_vpath_curve_to_internal(vpath, x0, y0, xa1, ya1, xa2, ya2, x_m, y_m, flatness);
    svg_vpath_curve_to_internal(vpath, x_m, y_m, xb1, yb1, xb2, yb2, x3, y3, flatness);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_curve_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]         
 *  x0          [IN]        
 *  y0          [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_curve_to(svg_vpath_t *vpath, float x0, float y0, float x1, float y1, float x2, float y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = y = 0;
    if (vpath->len > 0)
    {
        x = vpath->path[vpath->len - 1].x;
        y = vpath->path[vpath->len - 1].y;
    }
    svg_vpath_curve_to_internal(vpath, x, y, x0, y0, x1, y1, x2, y2, 1);
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_path_arc_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath               [?]         
 *  xc                  [IN]        
 *  yc                  [IN]        
 *  th0                 [IN]        
 *  th1                 [IN]        
 *  rx                  [IN]        
 *  ry                  [IN]        
 *  x_axis_rotation     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_path_arc_segment(
                svg_vpath_t *vpath,
                float xc,
                float yc,
                float th0,
                float th1,
                float rx,
                float ry,
                float x_axis_rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float sin_th, cos_th;
    float a00, a01, a10, a11;
    float x1, y1, x2, y2, x3, y3;
    float t;
    float th_half;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sin_th = sin(x_axis_rotation * (M_PI / 180.0));
    cos_th = cos(x_axis_rotation * (M_PI / 180.0));
    /* inverse transform compared with rsvg_path_arc */
    a00 = cos_th * rx;
    a01 = -sin_th * ry;
    a10 = sin_th * rx;
    a11 = cos_th * ry;

    th_half = 0.5 * (th1 - th0);
    t = (8.0 / 3.0) * sin(th_half * 0.5) * sin(th_half * 0.5) / sin(th_half);
    x1 = xc + cos(th0) - t * sin(th0);
    y1 = yc + sin(th0) + t * cos(th0);
    x3 = xc + cos(th1);
    y3 = yc + sin(th1);
    x2 = x3 + t * sin(th1);
    y2 = y3 - t * cos(th1);

    svg_vpath_curve_to(
        vpath,
        a00 * x1 + a01 * y1,
        a10 * x1 + a11 * y1,
        a00 * x2 + a01 * y2,
        a10 * x2 + a11 * y2,
        a00 * x3 + a01 * y3,
        a10 * x3 + a11 * y3);
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_arc_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath               [?]         
 *  rx                  [IN]        
 *  ry                  [IN]        
 *  x_axis_rotation     [IN]        
 *  large_arc_flag      [IN]        
 *  sweep_flag          [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_vpath_arc_to(
        svg_vpath_t *vpath,
        float rx,
        float ry,
        float x_axis_rotation,
        int large_arc_flag,
        int sweep_flag,
        float x,
        float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float sin_th, cos_th;
    float a00, a01, a10, a11;
    float x0, y0, x1, y1, xc, yc;
    float d, sfactor, sfactor_sq;
    float th0, th1, th_arc;
    float cpx, cpy;
    int i, n_segs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((rx == 0.0) || (ry == 0.0))
    {
        return;
    }

    cpx = cpy = 0;
    if (vpath->len > 0)
    {
        cpx = vpath->path[vpath->len - 1].x;
        cpy = vpath->path[vpath->len - 1].y;
    }

    sin_th = sin(x_axis_rotation * (M_PI / 180.0));
    cos_th = cos(x_axis_rotation * (M_PI / 180.0));
    a00 = cos_th / rx;
    a01 = sin_th / rx;
    a10 = -sin_th / ry;
    a11 = cos_th / ry;
    x0 = a00 * cpx + a01 * cpy;
    y0 = a10 * cpx + a11 * cpy;
    x1 = a00 * x + a01 * y;
    y1 = a10 * x + a11 * y;
    // (x0, y0) is current point in transformed coordinate space.
    //   (x1, y1) is new point in transformed coordinate space.
    // The arc fits a unit-radius circle in this space.

    d = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
    sfactor_sq = 1.0 / d - 0.25;
    if (sfactor_sq < 0)
    {
        sfactor_sq = 0;
    }
    sfactor = sqrt(sfactor_sq);
    if (sweep_flag == large_arc_flag)
    {
        sfactor = -sfactor;
    }
    xc = 0.5 * (x0 + x1) - sfactor * (y1 - y0);
    yc = 0.5 * (y0 + y1) + sfactor * (x1 - x0);

    /* (xc, yc) is center of the circle. */
    th0 = atan2(y0 - yc, x0 - xc);
    th1 = atan2(y1 - yc, x1 - xc);

    th_arc = th1 - th0;
    if (th_arc < 0 && sweep_flag)
    {
        th_arc += 2 * M_PI;
    }
    else if (th_arc > 0 && !sweep_flag)
    {
        th_arc -= 2 * M_PI;
    }

    n_segs = (int)ceil(fabs(th_arc / (M_PI * 0.5 + 0.001)));

    for (i = 0; i < n_segs; i++)
    {
        svg_path_arc_segment(
            vpath,
            xc,
            yc,
            th0 + i * th_arc / n_segs,
            th0 + (i + 1) * th_arc / n_segs,
            rx,
            ry,
            x_axis_rotation);
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_update_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_update_length(svg_vpath_t *vpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    svg_pos_t old = vpath->path[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vpath->path_length = 0;

    for (i = 1; i < vpath->len; i++)
        if (old.x != vpath->path[i].x || old.y != vpath->path[i].y)
        {
            float x, y;

            x = vpath->path[i].x;
            y = vpath->path[i].y;

            vpath->path_length += sqrt((old.x - x) * (old.x - x) + (old.y - y) * (old.y - y));
            old = vpath->path[i];
        }
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_interpolation1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  xy                  [?]         
 *  rotate              [?]         
 *  vpath               [?]         
 *  calc_mode           [IN]        
 *  current_time        [IN]        
 *  total_time          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_interpolation1(
            float xy[2],
            float *rotate,
            svg_vpath_t *vpath,
            svg_animate_calc_mode_enum calc_mode,
            float current_time,
            float total_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;
    float target_length;
    float len;
    svg_pos_t old;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (calc_mode == SVG_ANIMATE_LINEAR)
    {
        int seg, current_seg;
        float begin_time;
        float x, y;

        x = vpath->path[0].x;
        y = vpath->path[0].y;

        /* count how many segment */
        seg = 0;
        for (i = 1; i < vpath->len; i++)
        {
            if (vpath->path[i].x != x || vpath->path[i].y != y)
            {
                seg++;
                x = vpath->path[i].x;
                y = vpath->path[i].y;
            }
        }
        /* current is in which segment ( 0 .. seg) */
        if (current_time < total_time)
        {
            current_seg = (int)(current_time * seg / total_time);
            begin_time = total_time * current_seg / seg;
        }
        else
        {
            current_seg = seg;
            begin_time = total_time;
        }

        /* seek to current segment */
        x = vpath->path[0].x;
        y = vpath->path[0].y;
        for (i = 1, j = 0; i < vpath->len && j <= current_seg; i++)
        {
            if (vpath->path[i].x != x || vpath->path[i].y != y)
            {
                j++;
                if (j > current_seg)
                {
                    break;
                }
                x = vpath->path[i].x;
                y = vpath->path[i].y;
            }
        }
        if (i >= vpath->len)
        {
            i = vpath->len - 1;
        }

        /* calculate linear between old to l */
        if (current_time == total_time)
        {
            xy[0] = vpath->path[i].x;
            xy[1] = vpath->path[i].y;
        }
        else
        {
            float m = current_time - begin_time;

            xy[0] = x + (vpath->path[i].x - x) * m / (total_time / seg);
            xy[1] = y + (vpath->path[i].y - y) * m / (total_time / seg);
        }

        return SVG_OK;
    }

    target_length = vpath->path_length * current_time / total_time;

    len = 0;
    old = vpath->path[0];
    for (i = 1; i < vpath->len; i++)
        if (old.x != vpath->path[i].x || old.y != vpath->path[i].y)
        {
            float x, y;
            float l;

            x = vpath->path[i].x;
            y = vpath->path[i].y;

            l = sqrt((old.x - x) * (old.x - x) + (old.y - y) * (old.y - y));

            if (len + l >= target_length || i + 1 == vpath->len)
            {
                switch (calc_mode)
                {
                    case SVG_ANIMATE_DISCRETE:
                        if (target_length == vpath->path_length)
                        {
                            xy[0] = x;
                            xy[1] = y;
                        }
                        else
                        {
                            xy[0] = old.x;
                            xy[1] = old.y;
                        }
                        break;
                    default:
                    case SVG_ANIMATE_PACED:
                    {
                        float m = target_length - len;

                        xy[0] = old.x + (x - old.x) * m / l;
                        xy[1] = old.y + (y - old.y) * m / l;
                    }
                        break;
                }

                /* calculate rotate angle */
                *rotate = svg_vec_to_angle(x - old.x, y - old.y);

                return SVG_OK;
            }
            len += l;

            old = vpath->path[i];
        }
    xy[0] = old.x;
    xy[1] = old.y;
    *rotate = 0;

    return SVG_OK;

}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_to_close_vpath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_vpath_t *svg_vpath_to_close_vpath(svg_vpath_t *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_vpath_t *dest = svg_vpath_new(src->len);
    svg_pos_t *src_path = src->path;
    int src_len = src->len;
    int i;
    int begin_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < src_len; i++)
    {
        if (VPATH_IS_MOVETO(src_path, src_len, i))
        {
            svg_vpath_line_to(dest, src_path[begin_index].x, src_path[begin_index].y);
            begin_index = i;
            svg_vpath_move_to(dest, src_path[i].x, src_path[i].y);
            i++;    /* jump move item, because move item is two item */
        }
        else
        {
            svg_vpath_line_to(dest, src_path[i].x, src_path[i].y);
        }
    }

    svg_vpath_line_to(dest, src_path[begin_index].x, src_path[begin_index].y);

    return dest;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_interpolation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [IN]        
 *  xy                  [?]         
 *  rotate              [?]         
 *  vpath               [?]         
 *  calc_mode           [IN]        
 *  keysplines          [?]         
 *  keytimes            [?]         
 *  current_time        [IN]        
 *  total_time          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_vpath_interpolation(
            svg_animate_motion_type_enum type,
            float xy[2],
            float *rotate,
            svg_vpath_t *vpath,
            svg_animate_calc_mode_enum calc_mode,
            U8 *keysplines,
            U8 *keytimes,
            float current_time,
            float total_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret = SVG_FAIL;
    int cnt;
    float value;
    svg_string_t *str = NULL;
    U8 *segment_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *rotate = 0;

    /* find how many segments */
    if (type == SVG_ANIMATE_MOTION_PATH)
    {
        cnt = 2;
        segment_list = (U8*) "0;1";
    }
    else    /* SVG_ANIMATE_MOTION_SEGMENT */
    {
        float x = 0, y = 0;
        int i;
        U8 *buf[32];

        str = svg_str_new((U8*) "");
        cnt = 0;
        for (i = 1; i < vpath->len; i++)
        {
            if (i == 0 || vpath->path[i].x != x || vpath->path[i].y != y)
            {
                sprintf((char*)buf, "%d;", cnt);
                svg_str_append(str, (U8*) buf);
                cnt++;
                x = vpath->path[i].x;
                y = vpath->path[i].y;
            }
        }
        if (str->len > 0)   /* erase the ';' in the end string */
        {
            str->len--;
            str->data[str->len] = 0;
        }
        segment_list = str->data;
    }

    if (cnt >= 2)   /* have at least one segment */
    {
        if (svg_interpolation_values(
                &value,
                segment_list,
                FALSE,
                calc_mode,
                keysplines,
                keytimes,
                current_time,
                total_time) == SVG_OK)
        {
            int current_segment = (int)value;

            value -= current_segment;
            if (current_time >= total_time)
            {
                xy[0] = vpath->path[vpath->len - 1].x;
                xy[1] = vpath->path[vpath->len - 1].y;

                /* calculate rotate angle */
                *rotate = svg_vec_to_angle(
                            vpath->path[vpath->len - 1].x - vpath->path[vpath->len - 2].x,
                            vpath->path[vpath->len - 1].y - vpath->path[vpath->len - 2].y);
            }
            else
            {
                int i, j;
                float x, y;

                *rotate = 0;

                if (type == SVG_ANIMATE_MOTION_SEGMENT)
                {
                    /* seek to current segment */
                    x = vpath->path[0].x;
                    y = vpath->path[0].y;
                    for (i = 1, j = 0; i < vpath->len && j <= current_segment; i++)
                    {
                        if (vpath->path[i].x != x || vpath->path[i].y != y)
                        {
                            j++;
                            if (j > current_segment)
                            {
                                break;
                            }
                            x = vpath->path[i].x;
                            y = vpath->path[i].y;
                        }
                    }
                    if (i >= vpath->len)
                    {
                        i = vpath->len - 1;
                    }

                    xy[0] = x + (vpath->path[i].x - x) * value;
                    xy[1] = y + (vpath->path[i].y - y) * value;
                    /* calculate rotate angle */
                    *rotate = svg_vec_to_angle(vpath->path[i].x - x, vpath->path[i].y - y);
                }
                else    /* PATH */
                {
                    float target_length = vpath->path_length * value;
                    float len = 0;
                    svg_pos_t old;

                    old = vpath->path[0];
                    xy[0] = old.x;
                    xy[1] = old.y;
                    for (i = 1; i < vpath->len; i++)
                        if (old.x != vpath->path[i].x || old.y != vpath->path[i].y)
                        {
                            float x, y;
                            float l;

                            x = vpath->path[i].x;
                            y = vpath->path[i].y;

                            l = sqrt((old.x - x) * (old.x - x) + (old.y - y) * (old.y - y));

                            if (len + l >= target_length || i + 1 == vpath->len)
                            {
                                float m = target_length - len;

                                xy[0] = old.x + (x - old.x) * m / l;
                                xy[1] = old.y + (y - old.y) * m / l;
                                /* calculate rotate angle */
                                *rotate = svg_vec_to_angle(vpath->path[i].x - old.x, vpath->path[i].y - old.y);
                                break;
                            }
                            len += l;
                            old = vpath->path[i];
                        }
                }

            }

            ret = SVG_OK;
        }
    }
    if (str)
    {
        svg_str_delete(str);
    }

    return ret;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


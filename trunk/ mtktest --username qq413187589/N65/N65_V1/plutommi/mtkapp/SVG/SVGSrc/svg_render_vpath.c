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
#include "svg_transform.h"
#include "svg_svp.h"
#include "svg_intersect.h"
#include "svg_render.h"


#define EPSILON_2 1e-12
#define M_SQRT2        1.41421356237309504880   /* sqrt(2) */
#define M_PI 3.14159265358979323846


/*****************************************************************************
 * FUNCTION
 *  svg_render_arc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_vpath         [?]         
 *  xc              [IN]        
 *  yc              [IN]        
 *  x0              [IN]        
 *  y0              [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  radius          [IN]        
 *  flatness        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_render_arc(
                svg_vpath_t *p_vpath,
                float xc,
                float yc,
                float x0,
                float y0,
                float x1,
                float y1,
                float radius,
                float flatness)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float theta;
    float th_0, th_1;
    int n_pts;
    int i;
    float aradius;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aradius = fabs(radius);
    theta = 2 * M_SQRT2 * sqrt(flatness / aradius);
    th_0 = atan2(y0, x0);
    th_1 = atan2(y1, x1);
    if (radius > 0)
    {
        if (th_0 < th_1)
        {
            th_0 += M_PI * 2;
        }
        n_pts = (int)ceil((th_0 - th_1) / theta);
    }
    else
    {
        if (th_1 < th_0)
        {
            th_1 += M_PI * 2;
        }
        n_pts = (int)ceil((th_1 - th_0) / theta);
    }
    svg_vpath_line_to(p_vpath, xc + x0, yc + y0);

    for (i = 1; i < n_pts; i++)
    {
        theta = th_0 + (th_1 - th_0) * i / n_pts;
        svg_vpath_line_to(p_vpath, xc + cos(theta) * aradius, yc + sin(theta) * aradius);
    }
    svg_vpath_line_to(p_vpath, xc + x1, yc + y1);
}


/*****************************************************************************
 * FUNCTION
 *  svg_render_seg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  forw            [?]         
 *  rev             [?]         
 *  vpath           [?]         
 *  style           [?]         
 *  stroke_size     [IN]        
 *  i0              [IN]        
 *  i1              [IN]        
 *  i2              [IN]        
 *  flatness        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_render_seg(
                svg_vpath_t *forw,
                svg_vpath_t *rev,
                svg_pos_t *vpath,
                svg_style_t *style,
                float stroke_size,
                int i0,
                int i1,
                int i2,
                float flatness)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float dx0, dy0;
    float dx1, dy1;
    float dlx0, dly0;
    float dlx1, dly1;
    float dmx, dmy;
    float dmr2;
    float scale;
    float cross;
    int join;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The vectors of the lines from i0 to i1 and i1 to i2. */
    dx0 = vpath[i1].x - vpath[i0].x;
    dy0 = vpath[i1].y - vpath[i0].y;

    dx1 = vpath[i2].x - vpath[i1].x;
    dy1 = vpath[i2].y - vpath[i1].y;

    /* Set dl[xy]0 to the vector from i0 to i1, rotated counterclockwise 90 degrees, and scaled to the length of line_width. */
    scale = stroke_size / sqrt(dx0 * dx0 + dy0 * dy0);
    dlx0 = dy0 * scale;
    dly0 = -dx0 * scale;

    /* Set dl[xy]1 to the vector from i1 to i2, rotated counterclockwise  90 degrees, and scaled to the length of line_width. */
    scale = stroke_size / sqrt(dx1 * dx1 + dy1 * dy1);
    dlx1 = dy1 * scale;
    dly1 = -dx1 * scale;

    /* now, forw's last point is expected to be colinear along d[xy]0 to point i0 - dl[xy]0, and rev with i0 + dl[xy]0. */

    /* positive for positive area (i.e. left turn) */
    cross = dx1 * dy0 - dx0 * dy1;

    dmx = (dlx0 + dlx1) * 0.5;
    dmy = (dly0 + dly1) * 0.5;
    dmr2 = dmx * dmx + dmy * dmy;

    join = style->join;
    if (join == SVG_STROKE_JOIN_MITER && dmr2 * style->miter_limit * style->miter_limit < stroke_size * stroke_size)
    {
        join = SVG_STROKE_JOIN_BEVEL;
    }

    if (dmr2 > EPSILON_2)
    {
        scale = stroke_size * stroke_size / dmr2;
        dmx *= scale;
        dmy *= scale;
    }

    if (cross * cross < EPSILON_2 && dx0 * dx1 + dy0 * dy1 >= 0)
    {
        svg_vpath_line_to(forw, vpath[i1].x - dlx0, vpath[i1].y - dly0);
        svg_vpath_line_to(rev, vpath[i1].x + dlx0, vpath[i1].y + dly0);
    }
    else if (cross > 0)
    {
        /* left turn, forw is outside and rev is inside */
        if ((dmr2 > EPSILON_2) &&
            /* check that i1 + dm[xy] is inside i0-i1 rectangle */
            (dx0 + dmx) * dx0 + (dy0 + dmy) * dy0 > 0 &&
            /* and that i1 + dm[xy] is inside i1-i2 rectangle */
            ((dx1 - dmx) * dx1 + (dy1 - dmy) * dy1 > 0))
        {
            /* can safely add single intersection point */
            svg_vpath_line_to(rev, vpath[i1].x + dmx, vpath[i1].y + dmy);
        }
        else
        {
            /* need to loop-de-loop the inside */
            svg_vpath_line_to(rev, vpath[i1].x + dlx0, vpath[i1].y + dly0);
            svg_vpath_line_to(rev, vpath[i1].x, vpath[i1].y);
            svg_vpath_line_to(rev, vpath[i1].x + dlx1, vpath[i1].y + dly1);
        }

        if (join == SVG_STROKE_JOIN_BEVEL)
        {
            svg_vpath_line_to(forw, vpath[i1].x - dlx0, vpath[i1].y - dly0);
            svg_vpath_line_to(forw, vpath[i1].x - dlx1, vpath[i1].y - dly1);
        }
        else if (join == SVG_STROKE_JOIN_MITER)
        {
            svg_vpath_line_to(forw, vpath[i1].x - dmx, vpath[i1].y - dmy);
        }
        else if (join == SVG_STROKE_JOIN_ROUND)
        {
            svg_render_arc(forw, vpath[i1].x, vpath[i1].y, -dlx0, -dly0, -dlx1, -dly1, stroke_size, flatness);
        }
    }
    else
    {
        if ((dmr2 > EPSILON_2) &&
            /* check that i1 - dm[xy] is inside i0-i1 rectangle */
            (dx0 - dmx) * dx0 + (dy0 - dmy) * dy0 > 0 &&
            /* and that i1 - dm[xy] is inside i1-i2 rectangle */
            ((dx1 + dmx) * dx1 + (dy1 + dmy) * dy1 > 0))
        {
            svg_vpath_line_to(forw, vpath[i1].x - dmx, vpath[i1].y - dmy);
        }
        else
        {
            svg_vpath_line_to(forw, vpath[i1].x - dlx0, vpath[i1].y - dly0);
            svg_vpath_line_to(forw, vpath[i1].x, vpath[i1].y);
            svg_vpath_line_to(forw, vpath[i1].x - dlx1, vpath[i1].y - dly1);
        }

        if (join == SVG_STROKE_JOIN_BEVEL)
        {
            svg_vpath_line_to(rev, vpath[i1].x + dlx0, vpath[i1].y + dly0);
            svg_vpath_line_to(rev, vpath[i1].x + dlx1, vpath[i1].y + dly1);
        }
        else if (join == SVG_STROKE_JOIN_MITER)
        {
            svg_vpath_line_to(rev, vpath[i1].x + dmx, vpath[i1].y + dmy);
        }
        else if (join == SVG_STROKE_JOIN_ROUND)
        {
            svg_render_arc(rev, vpath[i1].x, vpath[i1].y, dlx0, dly0, dlx1, dly1, -stroke_size, flatness);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_render_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_result        [?]         
 *  vpath           [?]         
 *  style           [?]         
 *  stroke_size     [IN]        
 *  i0              [IN]        
 *  i1              [IN]        
 *  flatness        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_render_cap(
                svg_vpath_t *p_result,
                svg_vpath_t *vpath,
                svg_style_t *style,
                float stroke_size,
                int i0,
                int i1,
                float flatness)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float dx0, dy0;
    float dlx0, dly0;
    float scale;
    int n_pts;
    int i;
    svg_pos_t *path = vpath->path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dx0 = path[i1].x - path[i0].x;
    dy0 = path[i1].y - path[i0].y;

    scale = stroke_size / sqrt(dx0 * dx0 + dy0 * dy0);
    dlx0 = dy0 * scale;
    dly0 = -dx0 * scale;

    switch (style->cap)
    {
        case SVG_STROKE_CAP_BUTT:
            svg_vpath_line_to(p_result, path[i1].x - dlx0, path[i1].y - dly0);
            svg_vpath_line_to(p_result, path[i1].x + dlx0, path[i1].y + dly0);
            break;
        case SVG_STROKE_CAP_ROUND:
            n_pts = (int)ceil(M_PI / (2.0 * M_SQRT2 * sqrt(flatness / stroke_size)));
            svg_vpath_line_to(p_result, path[i1].x - dlx0, path[i1].y - dly0);
            for (i = 1; i < n_pts; i++)
            {
                float theta, c_th, s_th;

                theta = M_PI * i / n_pts;
                c_th = cos(theta);
                s_th = sin(theta);
                svg_vpath_line_to(
                    p_result,
                    path[i1].x - dlx0 * c_th - dly0 * s_th,
                    path[i1].y - dly0 * c_th + dlx0 * s_th);
            }
            svg_vpath_line_to(p_result, path[i1].x + dlx0, path[i1].y + dly0);
            break;
        case SVG_STROKE_CAP_SQUARE:
            svg_vpath_line_to(p_result, path[i1].x - dlx0 - dly0, path[i1].y - dly0 + dlx0);
            svg_vpath_line_to(p_result, path[i1].x + dlx0 - dly0, path[i1].y + dly0 + dlx0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_render_vpath_stroke
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath           [?]         
 *  style           [?]         
 *  stroke_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_vpath_t *svg_render_vpath_stroke(svg_vpath_t *vpath, svg_style_t *style, float stroke_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int begin_idx, end_idx;
    int i;
    svg_vpath_t *forw, *rev, *result;
    float flatness = 0.25;

    int last, this, next, second;
    float dx, dy;
    svg_pos_t *path = vpath->path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stroke_size *= 0.5;

    forw = svg_vpath_new(4);
    if (forw == NULL)
    {
        return NULL;
    }

    rev = svg_vpath_new(4);
    if (rev == NULL)
    {
        return NULL;
    }

    result = svg_vpath_new(4);
    if (result == NULL)
    {
        return NULL;
    }

    for (begin_idx = 0; begin_idx < vpath->len; begin_idx = end_idx)
    {
        this = begin_idx;
        forw->len = rev->len = 0;

        /* skip over identical points at the beginning of the subpath */
        for (i = this + 1; VPATH_IS_LINETO(path, vpath->len, i); i++)
        {
            dx = path[i].x - path[this].x;
            dy = path[i].y - path[this].y;
            if (dx * dx + dy * dy > EPSILON_2)
            {
                break;
            }
        }

        next = i;
        second = next;

        /* invariant: this doesn't coincide with next */
        while (VPATH_IS_LINETO(path, vpath->len, i) && i < vpath->len)
        {
            last = this;
            this = next;

            /* skip over identical points after the beginning of the subpath */
            for (i = this + 1; VPATH_IS_LINETO(path, vpath->len, i) && i < vpath->len; i++)
            {
                dx = path[i].x - path[this].x;
                dy = path[i].y - path[this].y;
                if (dx * dx + dy * dy > EPSILON_2)
                {
                    break;
                }
            }
            next = i;

            if (!VPATH_IS_LINETO(path, vpath->len, next) || next >= vpath->len)
            {
                if (path[this].x == path[begin_idx].x && path[this].y == path[begin_idx].y)
                {
                    int j;

                    /* path is closed, render join to beginning */
                    svg_render_seg(forw, rev, vpath->path, style, stroke_size, last, this, second, flatness);

                    /* do forward path */
                    svg_vpath_move_to(result, forw->path[forw->len - 1].x, forw->path[forw->len - 1].y);
                    for (j = 0; j < forw->len; j++)
                    {
                        svg_vpath_line_to(result, forw->path[j].x, forw->path[j].y);
                    }

                    /* do reverse path, reversed */
                    svg_vpath_move_to(result, rev->path[0].x, rev->path[0].y);
                    for (j = rev->len - 1; j >= 0; j--)
                    {
                        svg_vpath_line_to(result, rev->path[j].x, rev->path[j].y);
                    }
                }
                else    /* path is open */
                {
                    int j;

                    svg_render_cap(forw, vpath, style, stroke_size, last, this, flatness);
                    svg_vpath_move_to(result, forw->path[0].x, forw->path[0].y);
                    for (j = 1; j < forw->len; j++)
                    {
                        svg_vpath_line_to(result, forw->path[j].x, forw->path[j].y);
                    }

                    for (j = rev->len - 1; j >= 0; j--)
                    {
                        svg_vpath_line_to(result, rev->path[j].x, rev->path[j].y);
                    }

                    svg_render_cap(result, vpath, style, stroke_size, second, begin_idx, flatness);
                    svg_vpath_line_to(result, forw->path[0].x, forw->path[0].y);
                }
            }
            else
            {
                svg_render_seg(forw, rev, vpath->path, style, stroke_size, last, this, next, flatness);
            }
        }
        end_idx = next;
    }
    svg_vpath_free(forw);
    svg_vpath_free(rev);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  svg_render_vpath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_render_vpath(svg_vpath_t *vpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_vpath_t *orig_vpath = vpath;
    svg_vpath_t *outline;
    float stroke_size;
    svg_svp_t *svp, *svp1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vpath->len < 2)
    {
        return;
    }

    if (svg_context->style.stroke_size == 0)
    {
        svg_context->style.stroke_size = 1;
    }
    stroke_size = svg_context->style.stroke_size * svg_transform_expansion(svg_context->style.transform);

    /* transform whole path */
    svg_vpath_transform(vpath, svg_context->style.transform);

    if (svg_context->style.dash.n > 0)
    {
        svg_vpath_t *dash_path = svg_vpath_to_dash(vpath, &svg_context->style.dash);

        vpath = dash_path;
    }

    /* fill path */
    if (svg_context->style.flag & SVG_STYLE_FLAG_FILL)
        if (svg_context->style.fill_color_type != SVG_COLOR_TYPE_NONE)
        {
            svg_vpath_t *close_path;

            svg_context->render_color = svg_context->style.fill_color;
            if (svg_context->render_color == GDI_COLOR_TRANSPARENT)
            {
                svg_context->render_color ^= 1;
            }

            close_path = svg_vpath_to_close_vpath(vpath);

            svp = svg_svp_create_from_vpath(close_path);

            svg_vpath_free(close_path);

            svp1 = svg_svp_intersect_process(svp);
            svg_svp_free(svp);
            svp = svp1;

            svg_render_svp(svp);

            svg_svp_free(svp);
        }
    /* draw outline */
    if (svg_context->style.flag & (SVG_STYLE_FLAG_STROKE_SIZE | SVG_STYLE_FLAG_STROKE_COLOR))
        if (svg_context->style.stroke_color_type != SVG_COLOR_TYPE_NONE)
        {
            svg_context->render_color = svg_context->style.stroke_color;
            if (svg_context->render_color == GDI_COLOR_TRANSPARENT)
            {
                svg_context->render_color ^= 1;
            }
            outline = svg_render_vpath_stroke(vpath, &(svg_context->style), stroke_size);
            svp = svg_svp_create_from_vpath(outline);
            svg_vpath_free(outline);

            svp1 = svg_svp_intersect_process(svp);
            svg_svp_free(svp);
            svp = svp1;

            svg_render_svp(svp);

            svg_svp_free(svp);
        }

    if (orig_vpath != vpath)
    {
        svg_vpath_free(vpath);
    }
}

/* Return the length of the largest subpath within vpath */


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_dash_max_subpath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static int svg_vpath_dash_max_subpath(svg_vpath_t *vpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int max_subpath;
    int i;
    int start;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_subpath = 0;
    start = 0;
    for (i = 0; i < vpath->len; i++)
    {
        if (VPATH_IS_MOVETO(vpath->path, vpath->len, i))
        {
            if (i - start > max_subpath)
            {
                max_subpath = i - start;
            }
            start = i;
        }
    }
    if (i - start > max_subpath)
    {
        max_subpath = i - start;
    }

    return max_subpath;
}


/*****************************************************************************
 * FUNCTION
 *  svg_vpath_to_dash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 *  dash        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_vpath_t *svg_vpath_to_dash(svg_vpath_t *vpath, svg_dash_t *dash)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int max_subpath;
    float *dists;
    svg_vpath_t *result;
    int n_result, n_result_max;
    int start, end;
    int i;
    float total_dist;

    int offset, toggle;
    float phase;

    int offset_init, toggle_init;
    float phase_init;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_subpath = svg_vpath_dash_max_subpath(vpath);
    dists = svg_mem_malloc(sizeof(float) * max_subpath);

    n_result = 0;
    n_result_max = 16;
    result = svg_vpath_new(n_result_max);

    toggle_init = 1;
    offset_init = 0;
    phase_init = dash->offset;
    while (phase_init >= dash->list[offset_init])
    {
        toggle_init = !toggle_init;
        phase_init -= dash->list[offset_init];
        offset_init++;
        if (offset_init == dash->n)
        {
            offset_init = 0;
        }
    }

    for (start = 0; start < vpath->len; start = end)
    {
        for (end = start + 1; end < vpath->len && VPATH_IS_LINETO(vpath->path, vpath->len, end); end++)
        {
            ;
        }

        total_dist = 0;

        for (i = start; i < end - 1; i++)
        {
            float dx, dy;

            dx = vpath->path[i + 1].x - vpath->path[i].x;
            dy = vpath->path[i + 1].y - vpath->path[i].y;
            dists[i - start] = sqrt(dx * dx + dy * dy);
            total_dist += dists[i - start];
        }

        if (total_dist <= dash->list[offset_init] - phase_init)
        {
            if (toggle_init)
            {
                svg_vpath_move_to(result, vpath->path[start].x, vpath->path[start].y);
                for (i = start + 1; i < end; i++)
                {
                    svg_vpath_line_to(result, vpath->path[i].x, vpath->path[i].y);
                }
            }
        }
        else
        {
            float dist;

            phase = phase_init;
            offset = offset_init;
            toggle = toggle_init;
            dist = 0;
            i = start;

            if (toggle)
            {
                svg_vpath_move_to(result, vpath->path[i].x, vpath->path[i].y);
            }

            while (i != end - 1)
            {
                if (dists[i - start] - dist > dash->list[offset] - phase)
                {
                    float a;
                    float x, y;

                    dist += dash->list[offset] - phase;
                    a = dist / dists[i - start];
                    x = vpath->path[i].x + a * (vpath->path[i + 1].x - vpath->path[i].x);
                    y = vpath->path[i].y + a * (vpath->path[i + 1].y - vpath->path[i].y);
                    if (toggle)
                    {
                        svg_vpath_line_to(result, x, y);
                    }
                    else
                    {
                        svg_vpath_move_to(result, x, y);
                    }
                    toggle = !toggle;
                    phase = 0;
                    offset++;
                    if (offset == dash->n)
                    {
                        offset = 0;
                    }
                }
                else
                {
                    phase += dists[i - start] - dist;
                    i++;
                    dist = 0;
                    if (toggle)
                    {
                        svg_vpath_line_to(result, vpath->path[i].x, vpath->path[i].y);
                    }
                }
            }
        }
    }
    svg_mem_free(dists);
    return result;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


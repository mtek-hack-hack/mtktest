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

extern void gdi_memset16(U8 *address, U16 pixel, int size);

// #define SVG_DEBUG_DRAWING

typedef struct
{
    int x;
    int delta;  /* stored with 16 fractional bits */
} svg_render_step_t;

typedef struct
{
    int x;
    int alpha;
} svg_render_mask_run_t;

typedef struct
{
    svg_svp_t *svp;
    int x0, x1;
    int y;
    int seg_ix;

    int *active_segs;
    int n_active_segs;
    int *cursor;
    float *seg_x;
    float *seg_dx;

    svg_render_step_t *steps;
} svg_render_iter_t;


/*****************************************************************************
 * FUNCTION
 *  svp_render_insert_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i                   [IN]        
 *  active_segs         [?]         
 *  n_active_segs       [IN]        
 *  seg_x               [?]         
 *  seg_dx              [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void svp_render_insert_active(int i, int *active_segs, int n_active_segs, float *seg_x, float *seg_dx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int j;
    float x;
    int tmp1, tmp2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this is a cheap hack to get ^'s sorted correctly */
    x = seg_x[i] + 0.001 * seg_dx[i];
    for (j = 0; j < n_active_segs && seg_x[active_segs[j]] < x; j++)
    {
        ;
    }

    tmp1 = i;
    while (j < n_active_segs)
    {
        tmp2 = active_segs[j];
        active_segs[j] = tmp1;
        tmp1 = tmp2;
        j++;
    }
    active_segs[j] = tmp1;
}


/*****************************************************************************
 * FUNCTION
 *  svp_render_delete_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  active_segs         [?]         
 *  j                   [IN]        
 *  n_active_segs       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svp_render_delete_active(int *active_segs, int j, int n_active_segs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (k = j; k < n_active_segs; k++)
    {
        active_segs[k] = active_segs[k + 1];
    }
}

#define EPSILON 1e-6


/*****************************************************************************
 * FUNCTION
 *  svp_render_aa_iter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  svp     [?]         
 *  x0      [IN]        
 *  y0      [IN]        
 *  x1      [IN]        
 *  y1      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_render_iter_t *svp_render_aa_iter(svg_svp_t *svp, int x0, int y0, int x1, int y1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_render_iter_t *iter = (svg_render_iter_t*) svg_mem_malloc(sizeof(svg_render_iter_t));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter->svp = svp;
    iter->y = y0;
    iter->x0 = x0;
    iter->x1 = x1;
    iter->seg_ix = 0;

    iter->active_segs = (int*)svg_mem_malloc(sizeof(int) * svp->n_segs);
    iter->cursor = (int*)svg_mem_malloc(sizeof(int) * svp->n_segs);
    iter->seg_x = (float*)svg_mem_malloc(sizeof(float) * svp->n_segs);
    iter->seg_dx = (float*)svg_mem_malloc(sizeof(float) * svp->n_segs);
    iter->steps = (svg_render_step_t*) svg_mem_malloc(sizeof(svg_render_step_t) * x1 - x0);
    iter->n_active_segs = 0;

    return iter;
}

#define ADD_STEP(xpos, xdelta)                          \
  if (n_steps == 0 || steps[n_steps - 1].x < xpos)      \
    {                                                   \
      sx = n_steps;                                     \
      steps[sx].x = xpos;                               \
      steps[sx].delta = xdelta;                         \
      n_steps++;                                        \
    }                                                   \
  else                                                  \
    {                                                   \
      for (sx = n_steps; sx > 0; sx--)                  \
   {                                                    \
     if (steps[sx - 1].x == xpos)                       \
       {                                                \
         steps[sx - 1].delta += xdelta;                 \
         sx = n_steps;                                  \
         break;                                         \
       }                                                \
     else if (steps[sx - 1].x < xpos)                   \
       {                                                \
         break;                                         \
       }                                                \
   }                                                    \
      if (sx < n_steps)                                 \
   {                                                    \
     memmove (&steps[sx + 1], &steps[sx],               \
         (n_steps - sx) * sizeof(steps[0]));            \
     steps[sx].x = xpos;                                \
     steps[sx].delta = xdelta;                          \
     n_steps++;                                         \
   }                                                    \
    }


/*****************************************************************************
 * FUNCTION
 *  svp_render_aa_iter_step
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iter            [?]         
 *  p_start         [?]         
 *  p_steps         [IN]        
 *  p_n_steps       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svp_render_aa_iter_step(svg_render_iter_t *iter, int *p_start, svg_render_step_t **p_steps, int *p_n_steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_svp_t *svp = iter->svp;
    int *active_segs = iter->active_segs;
    int n_active_segs = iter->n_active_segs;
    int *cursor = iter->cursor;
    float *seg_x = iter->seg_x;
    float *seg_dx = iter->seg_dx;
    int i = iter->seg_ix;
    int j;
    int x0 = iter->x0;
    int x1 = iter->x1;
    int y = iter->y;
    int seg_index;

    int x;
    svg_render_step_t *steps = iter->steps;
    int n_steps;
    float y_top, y_bot;
    float x_top, x_bot;
    float x_min, x_max;
    int ix_min, ix_max;
    float delta;   /* delta should be int too? */
    int last, this;
    int xdelta;
    float rslope, drslope;
    int start;
    svg_seg_t *seg;
    int curs;
    float dy;

    int sx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* insert new active segments */
    for (; i < svp->n_segs && svp->segs[i].bbox[1] < y + 1; i++)
    {
        if (svp->segs[i].bbox[3] > y && svp->segs[i].bbox[0] < x1)
        {
            seg = &svp->segs[i];
            /* move cursor to topmost vector which overlaps [y,y+1) */
            for (curs = 0; seg->points[curs + 1].y < y; curs++)
            {
                ;
            }

            cursor[i] = curs;
            dy = seg->points[curs + 1].y - seg->points[curs].y;
            if (fabs(dy) >= EPSILON)
            {
                seg_dx[i] = (seg->points[curs + 1].x - seg->points[curs].x) / dy;
            }
            else
            {
                seg_dx[i] = 1e12;
            }
            seg_x[i] = seg->points[curs].x + (y - seg->points[curs].y) * seg_dx[i];
            svp_render_insert_active(i, active_segs, n_active_segs++, seg_x, seg_dx);
        }
    }

    n_steps = 0;

    /* render the runlengths, advancing and deleting as we go */
    start = 0x8000;

    for (j = 0; j < n_active_segs; j++)
    {
        seg_index = active_segs[j];
        seg = &svp->segs[seg_index];
        curs = cursor[seg_index];
        while (curs != seg->n_points - 1 && seg->points[curs].y < y + 1)
        {
            y_top = y;
            if (y_top < seg->points[curs].y)
            {
                y_top = seg->points[curs].y;
            }

            y_bot = y + 1;
            if (y_bot > seg->points[curs + 1].y)
            {
                y_bot = seg->points[curs + 1].y;
            }

            if (y_top != y_bot)
            {
                delta = (seg->dir ? 16711680.0 : -16711680.0) * (y_bot - y_top);
                x_top = seg_x[seg_index] + (y_top - y) * seg_dx[seg_index];
                x_bot = seg_x[seg_index] + (y_bot - y) * seg_dx[seg_index];
                if (x_top < x_bot)
                {
                    x_min = x_top;
                    x_max = x_bot;
                }
                else
                {
                    x_min = x_bot;
                    x_max = x_top;
                }

                ix_min = (int)floor(x_min);
                ix_max = (int)floor(x_max);
                if (ix_min >= x1)
                {
                    /* skip; it starts to the right of the render region */
                }
                else if (ix_max < x0)
                    /* it ends to the left of the render region */
                {
                    start += (int)delta;
                }
                else if (ix_min == ix_max)
                {
                    /* case 1, antialias a single pixel */
                    xdelta = (int)((ix_min + 1 - (x_min + x_max) * 0.5) * delta);

                    ADD_STEP(ix_min, xdelta) if (ix_min + 1 < x1)
                    {
                        xdelta = (int)delta - xdelta;

                    ADD_STEP(ix_min + 1, xdelta)}
                }
                else
                {
                    /* case 2, antialias a run */
                    rslope = 1.0 / fabs(seg_dx[seg_index]);
                    drslope = delta * rslope;
                    last = (int)(drslope * 0.5 * (ix_min + 1 - x_min) * (ix_min + 1 - x_min));

                    xdelta = last;
                    if (ix_min >= x0)
                    {
                        ADD_STEP(ix_min, xdelta) x = ix_min + 1;
                    }
                    else
                    {
                        start += last;
                        x = x0;
                    }
                    if (ix_max > x1)
                    {
                        ix_max = x1;
                    }
                    for (; x < ix_max; x++)
                    {
                        this = (int)((seg->dir ? 16711680.0 : -16711680.0) * rslope * (x + 0.5 - x_min));
                        xdelta = this - last;
                        last = this;

                    ADD_STEP(x, xdelta)}
                    if (x < x1)
                    {
                        this = (int)(delta * (1 - 0.5 * (x_max - ix_max) * (x_max - ix_max) * rslope));
                        xdelta = this - last;
                        last = this;

                        ADD_STEP(x, xdelta) if (x + 1 < x1)
                        {
                            xdelta = (int)(delta - last);
                        ADD_STEP(x + 1, xdelta)}
                    }
                }
            }

            curs++;
            if (curs != seg->n_points - 1 && seg->points[curs].y < y + 1)
            {
                dy = seg->points[curs + 1].y - seg->points[curs].y;
                if (fabs(dy) >= EPSILON)
                {
                    seg_dx[seg_index] = (seg->points[curs + 1].x - seg->points[curs].x) / dy;
                }
                else
                {
                    seg_dx[seg_index] = 1e12;
                }

                seg_x[seg_index] = seg->points[curs].x + (y - seg->points[curs].y) * seg_dx[seg_index];
            }
            /* break here, instead of duplicating predicate in while? */
        }

        if (seg->points[curs].y >= y + 1)
        {
            curs--;
            cursor[seg_index] = curs;
            seg_x[seg_index] += seg_dx[seg_index];
        }
        else
        {
            svp_render_delete_active(active_segs, j--, --n_active_segs);
        }
    }

    *p_start = start;
    *p_steps = steps;
    *p_n_steps = n_steps;

    iter->seg_ix = i;
    iter->n_active_segs = n_active_segs;
    iter->y++;
}


/*****************************************************************************
 * FUNCTION
 *  svp_render_aa_iter_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iter        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svp_render_aa_iter_done(svg_render_iter_t *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_mem_free(iter->steps);

    svg_mem_free(iter->seg_dx);
    svg_mem_free(iter->seg_x);
    svg_mem_free(iter->cursor);
    svg_mem_free(iter->active_segs);
    svg_mem_free(iter);
}


/*****************************************************************************
 * FUNCTION
 *  svp_render_aa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  svp                 [?]         
 *  x0                  [IN]        
 *  y0                  [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  callback            [IN]        
 *  callback_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svp_render_aa(
        svg_svp_t *svp,
        int x0,
        int y0,
        int x1,
        int y1,
        void (*callback) (void *callback_data, int y, int start, svg_render_step_t *steps, int n_steps),
        void *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_render_iter_t *iter;
    int y;
    int start;
    svg_render_step_t *steps;
    int n_steps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (svp->n_segs == 0)
    {
        return;
    }

    iter = svp_render_aa_iter(svp, x0, y0, x1, y1);

    for (y = y0; y <= y1; y++)
    {
        svp_render_aa_iter_step(iter, &start, &steps, &n_steps);
        (*callback) (callback_data, y, start, steps, n_steps);
    }

    svp_render_aa_iter_done(iter);
}

extern void svg_render_svp_callback(void *callback_data, int y, int start, svg_render_step_t *steps, int n_steps);


/*****************************************************************************
 * FUNCTION
 *  svg_render_svp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  svp     [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_render_svp(svg_svp_t *svp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float rect[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_svp_calculate_bounds(rect, svp);
    svg_context->render_bounds[0] = ((int)floor(rect[0])) - 1;
    svg_context->render_bounds[1] = ((int)floor(rect[1])) - 1;
    svg_context->render_bounds[2] = ((int)ceil(rect[2])) + 1;
    svg_context->render_bounds[3] = ((int)ceil(rect[3])) + 1;

    SVG_CLIP_TWO_RECT(
        svg_context->render_bounds[0],
        svg_context->render_bounds[1],
        svg_context->render_bounds[2],
        svg_context->render_bounds[3],
        gdi_act_layer->clipx1,
        gdi_act_layer->clipy1,
        gdi_act_layer->clipx2,
        gdi_act_layer->clipy2,
        return SVG_OK);

    if (svg_context->render_bounds[0] == svg_context->render_bounds[2]
        || svg_context->render_bounds[1] == svg_context->render_bounds[3])
    {
        return SVG_OK;
    }

    svp_render_aa(
        svp,
        svg_context->render_bounds[0],
        svg_context->render_bounds[1],
        svg_context->render_bounds[2],
        svg_context->render_bounds[3],
        svg_render_svp_callback,
        NULL);

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_render_svp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_data       [?]         
 *  y                   [IN]        
 *  start               [IN]        
 *  steps               [?]         
 *  n_steps             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_render_svp_callback(void *callback_data, int y, int start, svg_render_step_t *steps, int n_steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int n_run = 0;
    int i;
    int running_sum = start;
    int x0 = svg_context->render_bounds[0];
    int x1 = svg_context->render_bounds[2];
    int run_x0, run_x1;
    svg_render_mask_run_t *run =
        (svg_render_mask_run_t*) svg_mem_malloc(sizeof(svg_render_mask_run_t) *
                                                 (svg_context->render_bounds[2] - svg_context->render_bounds[0]+10));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_steps > 0)
    {
        run_x1 = steps[0].x;
        if (run_x1 > x0 && running_sum > 0x80ff)
        {
            run[0].x = x0;
            run[0].alpha = running_sum;
            n_run++;
        }

        for (i = 0; i < n_steps - 1; i++)
        {
            running_sum += steps[i].delta;
            run_x0 = run_x1;
            run_x1 = steps[i + 1].x;
            if (run_x1 > run_x0)
            {
                run[n_run].x = run_x0;
                run[n_run].alpha = running_sum;
                n_run++;
            }
        }
        if (x1 > run_x1)
        {
            running_sum += steps[n_steps - 1].delta;
            run[n_run].x = run_x1;
            run[n_run].alpha = running_sum;
            n_run++;
        }
        if (running_sum > 0x80ff)
        {
            run[n_run].x = x1;
            run[n_run].alpha = 0x8000;
            n_run++;
        }
    }
    else if ((running_sum >> 16) > 0)
    {
        run[0].x = x0;
        run[0].alpha = running_sum;
        run[1].x = x1;
        run[1].alpha = running_sum;
        n_run = 2;
    }

    {
        U32 tmp, run_alpha;
        int i;
        int x0, x1;
        U8 *lcd = (U8*) gdi_act_layer->buf_ptr + ((y * gdi_act_layer->width * gdi_act_layer->bits_per_pixel)>>3);

        for (i = 0; i < n_run - 1; i++)
        {
            tmp = (U32) run[i].alpha;
            if (tmp < 0x8100)
            {
                continue;
            }

            x0 = run[i].x;
            x1 = run[i + 1].x;

            if (x0 <= x1)
            {
                U8 *p = lcd + ((x0* gdi_act_layer->bits_per_pixel)>>3); 

                run_alpha = (tmp + (tmp >> 8) + (tmp >> 16) - 0x8000) >> 8;     /* range [0 .. 0x10000] */

				if(gdi_act_layer->bits_per_pixel==16)
                    gdi_memset16((U8*) p, (U16) svg_context->render_color, (x1 - x0 + 1) * 2);
				else
					gdi_draw_line(x0,y,x1,y, svg_context->render_color);


            #ifdef SVG_DEBUG_DRAWING
                {
                    static BOOL display_progress = MMI_FALSE;

                    if (display_progress)
                    {
                        gdi_layer_blt_previous(0, 0, 240, 320);
                    }
                }
            #endif /* SVG_DEBUG_DRAWING */ 
            }
        }
    }

    svg_mem_free(run);
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


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
#include "svg_pqueue.h"
#include "svg_vpath.h"
#include "svg_svp.h"
#include "svg_intersect.h"

typedef enum
{
    SVG_WIND_RULE_NONZERO,
    SVG_WIND_RULE_INTERSECT,
    SVG_WIND_RULE_ODDEVEN,
    SVG_WIND_RULE_POSITIVE
} svg_wind_rule_enum;

typedef struct svp_writer_t svp_writer_t;
typedef struct svp_writer_t
{
    int (*add_segment) (svp_writer_t *self, int wind_left, int delta_wind, float x, float y);
    void (*add_point) (svp_writer_t *self, int seg_id, float x, float y);
    void (*close_segment) (svp_writer_t *self, int seg_id);
} svp_writer_t;

typedef struct
{
    svp_writer_t super;
    svg_wind_rule_enum rule;
    svg_svp_t *svp;
    int *n_points_max;
} svg_writer_rewind_t;


/*****************************************************************************
 * FUNCTION
 *  svg_svp_writer_rewind_add_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  self            [?]         
 *  wind_left       [IN]        
 *  delta_wind      [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int svg_svp_writer_rewind_add_segment(svp_writer_t *self, int wind_left, int delta_wind, float x, float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_writer_rewind_t *swr = (svg_writer_rewind_t*) self;
    svg_svp_t *svp;
    svg_seg_t *seg;
    BOOL left_filled = 0, right_filled = 0;
    int wind_right = wind_left + delta_wind;
    int seg_num;
    int init_n_points_max = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (swr->rule)
    {
        case SVG_WIND_RULE_NONZERO:
            left_filled = (wind_left != 0);
            right_filled = (wind_right != 0);
            break;
        case SVG_WIND_RULE_INTERSECT:
            left_filled = (wind_left > 1);
            right_filled = (wind_right > 1);
            break;
        case SVG_WIND_RULE_ODDEVEN:
            left_filled = (wind_left & 1);
            right_filled = (wind_right & 1);
            break;
        case SVG_WIND_RULE_POSITIVE:
            left_filled = (wind_left > 0);
            right_filled = (wind_right > 0);
            break;
        default:
            SVG_ASSERT(0);  /* unknown wind rule */
    }
    if (left_filled == right_filled)
    {
        /* discard segment now */
        return -1;
    }
    svp = swr->svp;
    seg_num = svp->n_segs++;
    if (svp->max_segs == seg_num)
    {
        int om = svp->max_segs;
        int *new_n_points_max;

        svp = svg_svp_enlarge(svp);

        swr->svp = svp;

        new_n_points_max = (int*)svg_mem_malloc(sizeof(int) * svp->max_segs);
        memcpy(new_n_points_max, swr->n_points_max, sizeof(int) * om);
        svg_mem_free(swr->n_points_max);
        swr->n_points_max = new_n_points_max;
    }
    seg = &svp->segs[seg_num];
    seg->n_points = 1;
    seg->dir = right_filled;
    swr->n_points_max[seg_num] = init_n_points_max;
    seg->bbox[0] = x;
    seg->bbox[1] = y;
    seg->bbox[2] = x;
    seg->bbox[3] = y;
    seg->points = (svg_pos_t*) svg_mem_malloc(sizeof(svg_pos_t) * init_n_points_max);
    seg->points[0].x = x;
    seg->points[0].y = y;
    return seg_num;
}


/*****************************************************************************
 * FUNCTION
 *  svg_writer_rewind_add_point
 * DESCRIPTION
 *  
 * PARAMETERS
 *  self        [?]         
 *  seg_id      [IN]        
 *  x           [IN]        
 *  y           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_writer_rewind_add_point(svp_writer_t *self, int seg_id, float x, float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_writer_rewind_t *swr = (svg_writer_rewind_t*) self;
    svg_seg_t *seg;
    int n_points;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (seg_id < 0)
    {
        return;
    }
    seg = &swr->svp->segs[seg_id];
    n_points = seg->n_points++;
    if (swr->n_points_max[seg_id] == n_points)
    {
        int m = swr->n_points_max[seg_id] + 8;
        svg_pos_t *new_points = (svg_pos_t*) svg_mem_malloc(sizeof(svg_pos_t) * m);

        memcpy(new_points, seg->points, sizeof(svg_pos_t) * swr->n_points_max[seg_id]);
        svg_mem_free(seg->points);
        seg->points = new_points;
        swr->n_points_max[seg_id] = m;
    }
    seg->points[n_points].x = x;
    seg->points[n_points].y = y;
    if (x < seg->bbox[0])
    {
        seg->bbox[0] = x;
    }
    if (x > seg->bbox[2])
    {
        seg->bbox[2] = x;
    }
    seg->bbox[3] = y;
}


/*****************************************************************************
 * FUNCTION
 *  svg_writer_rewind_close_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  self        [?]         
 *  seg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_writer_rewind_close_segment(svp_writer_t *self, int seg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not needed for this simple implementation. A potential future optimization is to merge segments that can be merged safely. */
}


/*****************************************************************************
 * FUNCTION
 *  svg_writer_rewind_reap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  self        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_svp_t *svg_writer_rewind_reap(svp_writer_t *self)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_writer_rewind_t *swr = (svg_writer_rewind_t*) self;
    svg_svp_t *result = swr->svp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_mem_free(swr->n_points_max);
    svg_mem_free(swr);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  svg_writer_rewind_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rule        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svp_writer_t *svg_writer_rewind_new(svg_wind_rule_enum rule)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_writer_rewind_t *result = (svg_writer_rewind_t*) svg_mem_malloc(sizeof(svg_writer_rewind_t));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result->super.add_segment = svg_svp_writer_rewind_add_segment;
    result->super.add_point = svg_writer_rewind_add_point;
    result->super.close_segment = svg_writer_rewind_close_segment;

    result->rule = rule;

    result->svp = svg_svp_create();
    result->n_points_max = (int*)svg_mem_malloc(sizeof(int) * result->svp->max_segs);

    return &result->super;
}

/* Now, data structures for the active list */

/* Note: BNEG is 1 for \ lines, and 0 for /. Thus,
   x[(flags & BNEG) ^ 1] <= x[flags & BNEG] */
#define SVG_ACTIVE_FLAGS_BNEG 1

/* This flag is set if the segment has been inserted into the active
   list. */
#define SVG_ACTIVE_FLAGS_IN_ACTIVE 2

/* This flag is set when the segment is to be deleted in the
   horiz commit process. */
#define SVG_ACTIVE_FLAGS_DEL 4

/* This flag is set if the seg_id is a valid output segment. */
#define SVG_ACTIVE_FLAGS_OUT 8

/* This flag is set if the segment is in the horiz list. */
#define SVG_ACTIVE_FLAGS_IN_HORIZ 16

typedef struct svg_act_seg_t svg_act_seg_t;

typedef struct svg_act_seg_t
{
    int flags;
    int wind_left, delta_wind;
    svg_act_seg_t *left, *right;

    svg_seg_t *in_seg;
    int in_curs;
    float x[2];
    float y0, y1;
    float a, b, c; /* line equation; ax+by+c = 0 for the line, a^2 + b^2 = 1, and a>0 */

    /* bottom point and intersection point stack */
    int n_stack;
    int n_stack_max;
    svg_pos_t *stack;

    /* horiz commit list */
    svg_act_seg_t *horiz_left, *horiz_right;
    float horiz_x;
    int horiz_delta_wind;
    int seg_id;
} svg_act_seg_t;

typedef struct
{
    svg_svp_t *in;
    svp_writer_t *out;
    svg_pq_t *pq;
    svg_act_seg_t *active_head;
    float y;
    svg_act_seg_t *horiz_first;
    svg_act_seg_t *horiz_last;
    int in_curs;
} svg_intersect_cntx_t;

#define EPSILON_A 1e-5


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_setup_seg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  seg         [?]     
 *  pri_pt      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_setup_seg(svg_act_seg_t *seg, svg_pq_pos_t *pri_pt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_seg_t *in_seg = seg->in_seg;
    int in_curs = seg->in_curs++;
    float x0, y0, x1, y1;
    float dx, dy, s;
    float a, b, r2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x0 = in_seg->points[in_curs].x;
    y0 = in_seg->points[in_curs].y;
    x1 = in_seg->points[in_curs + 1].x;
    y1 = in_seg->points[in_curs + 1].y;
    pri_pt->x = x1;
    pri_pt->y = y1;
    dx = x1 - x0;
    dy = y1 - y0;
    r2 = dx * dx + dy * dy;
    s = r2 == 0 ? 1 : 1 / sqrt(r2);
    seg->a = a = dy * s;
    seg->b = b = -dx * s;
    seg->c = -(a * x0 + b * y0);
    seg->flags = (seg->flags & ~SVG_ACTIVE_FLAGS_BNEG) | (dx > 0);
    seg->x[0] = x0;
    seg->x[1] = x1;
    seg->y0 = y0;
    seg->y1 = y1;
    seg->n_stack = 1;
    seg->stack[0].x = x1;
    seg->stack[0].y = y1;
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_add_horiz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]     
 *  seg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_add_horiz(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_act_seg_t **pp = &ctx->horiz_last;
    svg_act_seg_t *place;
    svg_act_seg_t *place_right = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (place = *pp;
         place != NULL && (place->horiz_x > seg->horiz_x || (place->horiz_x == seg->horiz_x && place->b < seg->b));
         place = *pp)
    {
        place_right = place;
        pp = &place->horiz_left;
    }
    *pp = seg;
    seg->horiz_left = place;
    seg->horiz_right = place_right;
    if (place == NULL)
    {
        ctx->horiz_first = seg;
    }
    else
    {
        place->horiz_right = seg;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_push_pt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]         
 *  seg     [?]         
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_push_pt(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg, float x, float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_pq_pos_t *pri_pt;
    int n_stack = seg->n_stack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_stack == seg->n_stack_max)
    {
        int m = seg->n_stack_max + 8;
        svg_pos_t *new_stack = (svg_pos_t*) svg_mem_malloc(sizeof(svg_pos_t) * m);

        memcpy(new_stack, seg->stack, sizeof(svg_pos_t) * seg->n_stack_max);
        svg_mem_free(seg->stack);
        seg->stack = new_stack;
        seg->n_stack_max = m;
    }
    seg->stack[n_stack].x = x;
    seg->stack[n_stack].y = y;
    seg->n_stack++;

    seg->x[1] = x;
    seg->y1 = y;

    pri_pt = (svg_pq_pos_t*) svg_mem_malloc(sizeof(svg_pq_pos_t));
    pri_pt->x = x;
    pri_pt->y = y;
    pri_pt->data = seg;
    svg_pq_insert(ctx->pq, pri_pt);
}

typedef enum
{
    SVG_BREAK_LEFT = 1,
    SVG_BREAK_RIGHT = 2
} svg_break_flags_enum;


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_break
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx             [?]         
 *  seg             [?]         
 *  x_ref           [IN]        
 *  y               [IN]        
 *  break_flags     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static float svg_intersect_break(
                svg_intersect_cntx_t *ctx,
                svg_act_seg_t *seg,
                float x_ref,
                float y,
                svg_break_flags_enum break_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float x0, y0, x1, y1;
    svg_seg_t *in_seg = seg->in_seg;
    int in_curs = seg->in_curs;
    float x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x0 = in_seg->points[in_curs - 1].x;
    y0 = in_seg->points[in_curs - 1].y;
    x1 = in_seg->points[in_curs].x;
    y1 = in_seg->points[in_curs].y;
    x = x0 + (x1 - x0) * ((y - y0) / (y1 - y0));
    if ((break_flags == SVG_BREAK_LEFT && x > x_ref) || (break_flags == SVG_BREAK_RIGHT && x < x_ref))
    {
    }

    if (y > ctx->y)
    {
        svg_intersect_push_pt(ctx, seg, x, y);
    }
    else
    {
        seg->x[0] = x;
        seg->y0 = y;
        seg->horiz_x = x;
        svg_intersect_add_horiz(ctx, seg);
    }

    return x;
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_add_point
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx             [?]         
 *  x               [IN]        
 *  y               [IN]        
 *  seg             [?]         
 *  break_flags     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static svg_act_seg_t *svg_intersect_add_point(
                        svg_intersect_cntx_t *ctx,
                        float x,
                        float y,
                        svg_act_seg_t *seg,
                        svg_break_flags_enum break_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_act_seg_t *left, *right;
    float x_min = x, x_max = x;
    BOOL left_live, right_live;
    float d;
    float new_x;
    svg_act_seg_t *test, *result = NULL;
    float x_test;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    left = seg;
    if (left == NULL)
    {
        right = ctx->active_head;
    }
    else
    {
        right = left->right;
    }
    left_live = (break_flags & SVG_BREAK_LEFT) && (left != NULL);
    right_live = (break_flags & SVG_BREAK_RIGHT) && (right != NULL);
    while (left_live || right_live)
    {
        if (left_live)
        {
            if (x <= left->x[left->flags & SVG_ACTIVE_FLAGS_BNEG] && y != left->y0 && y < left->y1)
            {
                d = x_min * left->a + y * left->b + left->c;
                if (d < EPSILON_A)
                {
                    new_x = svg_intersect_break(ctx, left, x_min, y, SVG_BREAK_LEFT);
                    if (new_x > x_max)
                    {
                        x_max = new_x;
                        right_live = (right != NULL);
                    }
                    else if (new_x < x_min)
                    {
                        x_min = new_x;
                    }
                    left = left->left;
                    left_live = (left != NULL);
                }
                else
                {
                    left_live = FALSE;
                }
            }
            else
            {
                left_live = FALSE;
            }
        }
        else if (right_live)
        {
            if (x >= right->x[(right->flags & SVG_ACTIVE_FLAGS_BNEG) ^ 1] && y != right->y0 && y < right->y1)
            {
                d = x_max * right->a + y * right->b + right->c;
                if (d > -EPSILON_A)
                {
                    new_x = svg_intersect_break(ctx, right, x_max, y, SVG_BREAK_RIGHT);
                    if (new_x < x_min)
                    {
                        x_min = new_x;
                        left_live = (left != NULL);
                    }
                    else if (new_x >= x_max)
                    {
                        x_max = new_x;
                    }
                    right = right->right;
                    right_live = (right != NULL);
                }
                else
                {
                    right_live = FALSE;
                }
            }
            else
            {
                right_live = FALSE;
            }
        }
    }

    test = left == NULL ? ctx->active_head : left->right;
    result = left;
    if (test != NULL && test != right)
    {
        if (y == test->y0)
        {
            x_test = test->x[0];
        }
        else
        {
            x_test = test->x[1];
        }
        for (;;)
        {
            if (x_test <= x)
            {
                result = test;
            }
            test = test->right;
            if (test == right)
            {
                break;
            }
            new_x = x_test;
            if (new_x < x_test)
            {
                /* svg_intersect_add_point: non-ascending x */
            }
            x_test = new_x;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_swap_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx             [?]     
 *  left_seg        [?]     
 *  right_seg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_swap_active(svg_intersect_cntx_t *ctx, svg_act_seg_t *left_seg, svg_act_seg_t *right_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    right_seg->left = left_seg->left;
    if (right_seg->left != NULL)
    {
        right_seg->left->right = right_seg;
    }
    else
    {
        ctx->active_head = right_seg;
    }
    left_seg->right = right_seg->right;
    if (left_seg->right != NULL)
    {
        left_seg->right->left = left_seg;
    }
    left_seg->left = right_seg;
    right_seg->right = left_seg;
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_test_cross
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx             [?]         
 *  left_seg        [?]         
 *  right_seg       [?]         
 *  break_flags     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL svg_intersect_test_cross(
        svg_intersect_cntx_t *ctx,
        svg_act_seg_t *left_seg,
        svg_act_seg_t *right_seg,
        svg_break_flags_enum break_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float left_x0, left_y0, left_x1;
    float left_y1 = left_seg->y1;
    float right_y1 = right_seg->y1;
    float d;

    svg_seg_t *in_seg;
    int in_curs;
    float d0, d1, t;
    float x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (left_seg->y0 == right_seg->y0 && left_seg->x[0] == right_seg->x[0])
    {
        if (left_y1 < right_y1)
        {
            /* test left (x1, y1) against right segment */
            float left_x1 = left_seg->x[1];

            if (left_x1 < right_seg->x[(right_seg->flags & SVG_ACTIVE_FLAGS_BNEG) ^ 1] || left_y1 == right_seg->y0)
            {
                return FALSE;
            }
            d = left_x1 * right_seg->a + left_y1 * right_seg->b + right_seg->c;
            if (d < -EPSILON_A)
            {
                return FALSE;
            }
            else if (d < EPSILON_A)
            {
                float right_x1 = svg_intersect_break(ctx, right_seg, left_x1, left_y1, SVG_BREAK_RIGHT);

                if (left_x1 <= right_x1)
                {
                    return FALSE;
                }
            }
        }
        else if (left_y1 > right_y1)
        {
            /* Test right (x1, y1) against left segment */
            float right_x1 = right_seg->x[1];

            if (right_x1 > left_seg->x[left_seg->flags & SVG_ACTIVE_FLAGS_BNEG] || right_y1 == left_seg->y0)
            {
                return FALSE;
            }
            d = right_x1 * left_seg->a + right_y1 * left_seg->b + left_seg->c;
            if (d > EPSILON_A)
            {
                return FALSE;
            }
            else if (d > -EPSILON_A)
            {
                float left_x1 = svg_intersect_break(ctx, left_seg, right_x1, right_y1, SVG_BREAK_LEFT);

                if (left_x1 <= right_x1)
                {
                    return FALSE;
                }
            }
        }
        else
        {
            float left_x1 = left_seg->x[1];
            float right_x1 = right_seg->x[1];

            if (left_x1 <= right_x1)
            {
                return FALSE;
            }
        }
        svg_intersect_swap_active(ctx, left_seg, right_seg);
        return TRUE;
    }

    if (left_y1 < right_y1)
    {
        float left_x1 = left_seg->x[1];

        if (left_x1 < right_seg->x[(right_seg->flags & SVG_ACTIVE_FLAGS_BNEG) ^ 1] || left_y1 == right_seg->y0)
        {
            return FALSE;
        }
        d = left_x1 * right_seg->a + left_y1 * right_seg->b + right_seg->c;
        if (d < -EPSILON_A)
        {
            return FALSE;
        }
        else if (d < EPSILON_A)
        {
            float right_x1 = svg_intersect_break(ctx, right_seg, left_x1, left_y1, SVG_BREAK_RIGHT);

            if (left_x1 <= right_x1)
            {
                return FALSE;
            }
        }
    }
    else if (left_y1 > right_y1)
    {
        float right_x1 = right_seg->x[1];

        if (right_x1 > left_seg->x[left_seg->flags & SVG_ACTIVE_FLAGS_BNEG] || right_y1 == left_seg->y0)
        {
            return FALSE;
        }
        d = right_x1 * left_seg->a + right_y1 * left_seg->b + left_seg->c;

        if (d > EPSILON_A)
        {
            return FALSE;
        }
        else if (d > -EPSILON_A)
        {
            float left_x1 = svg_intersect_break(ctx, left_seg, right_x1, right_y1, SVG_BREAK_LEFT);

            if (left_x1 <= right_x1)
            {
                return FALSE;
            }
        }
    }
    else
    {
        float left_x1 = left_seg->x[1];
        float right_x1 = right_seg->x[1];

        if (left_x1 <= right_x1)
        {
            return FALSE;
        }
    }

    in_seg = left_seg->in_seg;
    in_curs = left_seg->in_curs;
    left_x0 = in_seg->points[in_curs - 1].x;
    left_y0 = in_seg->points[in_curs - 1].y;
    left_x1 = in_seg->points[in_curs].x;
    left_y1 = in_seg->points[in_curs].y;
    d0 = left_x0 * right_seg->a + left_y0 * right_seg->b + right_seg->c;
    d1 = left_x1 * right_seg->a + left_y1 * right_seg->b + right_seg->c;
    if (d0 == d1)
    {
        x = left_x0;
        y = left_y0;
    }
    else
    {
        t = d0 / (d0 - d1);
        if (t <= 0)
        {
            x = left_x0;
            y = left_y0;
        }
        else if (t >= 1)
        {
            x = left_x1;
            y = left_y1;
        }
        else
        {
            x = left_x0 + t * (left_x1 - left_x0);
            y = left_y0 + t * (left_y1 - left_y0);
        }
    }

    if (y < right_seg->y0)
    {
        x = right_seg->x[0];
        y = right_seg->y0;
    }
    else if (y > right_seg->y1)
    {
        x = right_seg->x[1];
        y = right_seg->y1;
    }
    else if (x < right_seg->x[(right_seg->flags & SVG_ACTIVE_FLAGS_BNEG) ^ 1])
    {
        x = right_seg->x[(right_seg->flags & SVG_ACTIVE_FLAGS_BNEG) ^ 1];
    }
    else if (x > right_seg->x[right_seg->flags & SVG_ACTIVE_FLAGS_BNEG])
    {
        x = right_seg->x[right_seg->flags & SVG_ACTIVE_FLAGS_BNEG];
    }

    if (y == left_seg->y0)
    {
        if (y != right_seg->y0)
        {
            svg_intersect_push_pt(ctx, right_seg, x, y);
            if ((break_flags & SVG_BREAK_RIGHT) && right_seg->right != NULL)
            {
                svg_intersect_add_point(ctx, x, y, right_seg->right, break_flags);
            }
        }
        else
        {
            svg_act_seg_t *winner, *loser;

            if (left_seg->a > right_seg->a)
            {
                winner = left_seg;
                loser = right_seg;
            }
            else
            {
                winner = right_seg;
                loser = left_seg;
            }
            loser->x[0] = winner->x[0];
            loser->horiz_x = loser->x[0];
            loser->horiz_delta_wind += loser->delta_wind;
            winner->horiz_delta_wind -= loser->delta_wind;
            svg_intersect_swap_active(ctx, left_seg, right_seg);
            return TRUE;
        }
    }
    else if (y == right_seg->y0)
    {
        svg_intersect_push_pt(ctx, left_seg, x, y);
        if ((break_flags & SVG_BREAK_LEFT) && left_seg->left != NULL)
        {
            svg_intersect_add_point(ctx, x, y, left_seg->left, break_flags);
        }
    }
    else
    {
        svg_intersect_push_pt(ctx, left_seg, x, y);
        svg_intersect_push_pt(ctx, right_seg, x, y);
        if ((break_flags & SVG_BREAK_LEFT) && left_seg->left != NULL)
        {
            svg_intersect_add_point(ctx, x, y, left_seg->left, break_flags);
        }
        if ((break_flags & SVG_BREAK_RIGHT) && right_seg->right != NULL)
        {
            svg_intersect_add_point(ctx, x, y, right_seg->right, break_flags);
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_active_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]     
 *  seg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_active_delete(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_act_seg_t *left = seg->left, *right = seg->right;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (left != NULL)
    {
        left->right = right;
    }
    else
    {
        ctx->active_head = right;
    }
    if (right != NULL)
    {
        right->left = left;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_active_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  seg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_active_free(svg_act_seg_t *seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (seg->stack)
    {
        svg_mem_free(seg->stack);
    }
    svg_mem_free(seg);
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_insert_cross
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]     
 *  seg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_insert_cross(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_act_seg_t *left = seg, *right = seg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (left != NULL)
        {
            svg_act_seg_t *leftc;

            for (leftc = left->left; leftc != NULL; leftc = leftc->left)
                if (!(leftc->flags & SVG_ACTIVE_FLAGS_DEL))
                {
                    break;
                }
            if (leftc != NULL && svg_intersect_test_cross(ctx, leftc, left, SVG_BREAK_LEFT))
            {
                if (left == right || right == NULL)
                {
                    right = left->right;
                }
            }
            else
            {
                left = NULL;
            }
        }
        else if (right != NULL && right->right != NULL)
        {
            svg_act_seg_t *rightc;

            for (rightc = right->right; rightc != NULL; rightc = rightc->right)
                if (!(rightc->flags & SVG_ACTIVE_FLAGS_DEL))
                {
                    break;
                }
            if (rightc != NULL && svg_intersect_test_cross(ctx, right, rightc, SVG_BREAK_RIGHT))
            {
                if (left == right || left == NULL)
                {
                    left = right->left;
                }
            }
            else
            {
                right = NULL;
            }
        }
        else
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_horiz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]         
 *  seg     [?]         
 *  x0      [IN]        
 *  x1      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_horiz(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg, float x0, float x1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_act_seg_t *hs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x0 == x1)
    {
        return;
    }

    hs = (svg_act_seg_t*) svg_mem_malloc(sizeof(svg_act_seg_t));

    hs->flags = SVG_ACTIVE_FLAGS_DEL | (seg->flags & SVG_ACTIVE_FLAGS_OUT);
    if (seg->flags & SVG_ACTIVE_FLAGS_OUT)
    {
        svp_writer_t *swr = ctx->out;

        swr->add_point(swr, seg->seg_id, x0, ctx->y);
    }
    hs->seg_id = seg->seg_id;
    hs->horiz_x = x0;
    hs->horiz_delta_wind = seg->delta_wind;
    hs->stack = NULL;

    hs->a = 0.0;
    hs->b = 0.0;
    hs->c = 0.0;

    seg->horiz_delta_wind -= seg->delta_wind;
    svg_intersect_add_horiz(ctx, hs);

    if (x0 > x1)
    {
        svg_act_seg_t *left;
        BOOL first = TRUE;

        for (left = seg->left; left != NULL; left = seg->left)
        {
            int left_bneg = left->flags & SVG_ACTIVE_FLAGS_BNEG;

            if (left->x[left_bneg] <= x1)
            {
                break;
            }
            if (left->x[left_bneg ^ 1] <= x1 && x1 * left->a + ctx->y * left->b + left->c >= 0)
            {
                break;
            }
            if (left->y0 != ctx->y && left->y1 != ctx->y)
            {
                svg_intersect_break(ctx, left, x1, ctx->y, SVG_BREAK_LEFT);
            }
            svg_intersect_swap_active(ctx, left, seg);
            if (first && left->right != NULL)
            {
                svg_intersect_test_cross(ctx, left, left->right, SVG_BREAK_RIGHT);
                first = FALSE;
            }
        }
    }
    else
    {
        svg_act_seg_t *right;
        BOOL first = TRUE;

        for (right = seg->right; right != NULL; right = seg->right)
        {
            int right_bneg = right->flags & SVG_ACTIVE_FLAGS_BNEG;

            if (right->x[right_bneg ^ 1] >= x1)
            {
                break;
            }
            if (right->x[right_bneg] >= x1 && x1 * right->a + ctx->y * right->b + right->c <= 0)
            {
                break;
            }
            if (right->y0 != ctx->y && right->y1 != ctx->y)
            {
                svg_intersect_break(ctx, right, x1, ctx->y, SVG_BREAK_LEFT);
            }
            svg_intersect_swap_active(ctx, seg, right);
            if (first && right->left != NULL)
            {
                svg_intersect_test_cross(ctx, right->left, right, SVG_BREAK_RIGHT);
                first = FALSE;
            }
        }
    }
    seg->x[0] = x1;
    seg->x[1] = x1;
    seg->horiz_x = x1;
    seg->flags &= ~SVG_ACTIVE_FLAGS_OUT;
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_insert_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]     
 *  seg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_insert_line(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (seg->y1 == seg->y0)
    {
        svg_intersect_horiz(ctx, seg, seg->x[0], seg->x[1]);
    }
    else
    {
        svg_intersect_insert_cross(ctx, seg);
        svg_intersect_add_horiz(ctx, seg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_process_intersection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]     
 *  seg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_process_intersection(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int n_stack = --seg->n_stack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    seg->x[1] = seg->stack[n_stack - 1].x;
    seg->y1 = seg->stack[n_stack - 1].y;
    seg->x[0] = seg->stack[n_stack].x;
    seg->y0 = seg->stack[n_stack].y;
    seg->horiz_x = seg->x[0];
    svg_intersect_insert_line(ctx, seg);
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_advance_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx         [?]     
 *  seg         [?]     
 *  pri_pt      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_advance_cursor(svg_intersect_cntx_t *ctx, svg_act_seg_t *seg, svg_pq_pos_t *pri_pt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_seg_t *in_seg = seg->in_seg;
    int in_curs = seg->in_curs;
    svp_writer_t *swr = seg->flags & SVG_ACTIVE_FLAGS_OUT ? ctx->out : NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (swr != NULL)
    {
        swr->add_point(swr, seg->seg_id, seg->x[1], seg->y1);
    }
    if (in_curs + 1 == in_seg->n_points)
    {
        svg_act_seg_t *left = seg->left, *right = seg->right;

        seg->flags |= SVG_ACTIVE_FLAGS_DEL;
        svg_intersect_add_horiz(ctx, seg);
        svg_intersect_active_delete(ctx, seg);
        if (left != NULL && right != NULL)
        {
            svg_intersect_test_cross(ctx, left, right, SVG_BREAK_LEFT | SVG_BREAK_RIGHT);
        }
        svg_mem_free(pri_pt);
    }
    else
    {
        seg->horiz_x = seg->x[1];
        svg_intersect_setup_seg(seg, pri_pt);
        svg_pq_insert(ctx->pq, pri_pt);
        svg_intersect_insert_line(ctx, seg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_add_seg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx         [?]     
 *  in_seg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_add_seg(svg_intersect_cntx_t *ctx, svg_seg_t *in_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_act_seg_t *seg = (svg_act_seg_t*) svg_mem_malloc(sizeof(svg_act_seg_t));
    svg_act_seg_t *test;
    float x0, y0;
    svg_act_seg_t *beg_range;
    svg_act_seg_t *last = NULL;
    svg_act_seg_t *left, *right;
    svg_pq_pos_t *pri_pt = (svg_pq_pos_t*) svg_mem_malloc(sizeof(svg_pq_pos_t));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    seg->flags = 0;
    seg->in_seg = in_seg;
    seg->in_curs = 0;

    seg->n_stack_max = 4;
    seg->stack = (svg_pos_t*) svg_mem_malloc(sizeof(svg_pos_t) * seg->n_stack_max);

    seg->horiz_delta_wind = 0;

    seg->wind_left = 0;

    pri_pt->data = seg;
    svg_intersect_setup_seg(seg, pri_pt);
    svg_pq_insert(ctx->pq, pri_pt);

    // Find insertion place for new segment
    // This is currently a left-to-right scan, but should be replaced
    // with a binary search as soon as it's validated.

    x0 = in_seg->points[0].x;
    y0 = in_seg->points[0].y;
    beg_range = NULL;
    for (test = ctx->active_head; test != NULL; test = test->right)
    {
        float d;
        int test_bneg = test->flags & SVG_ACTIVE_FLAGS_BNEG;

        if (x0 < test->x[test_bneg])
        {
            if (x0 < test->x[test_bneg ^ 1])
            {
                break;
            }
            d = x0 * test->a + y0 * test->b + test->c;
            if (d < 0)
            {
                break;
            }
        }
        last = test;
    }

    left = svg_intersect_add_point(ctx, x0, y0, last, SVG_BREAK_LEFT | SVG_BREAK_RIGHT);
    seg->left = left;
    if (left == NULL)
    {
        right = ctx->active_head;
        ctx->active_head = seg;
    }
    else
    {
        right = left->right;
        left->right = seg;
    }
    seg->right = right;
    if (right != NULL)
    {
        right->left = seg;
    }

    seg->delta_wind = in_seg->dir ? 1 : -1;
    seg->horiz_x = x0;
    svg_intersect_insert_line(ctx, seg);
}


/*****************************************************************************
 * FUNCTION
 *  svg_intersect_horiz_commit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_intersect_horiz_commit(svg_intersect_cntx_t *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_act_seg_t *seg;
    int winding_number = 0;
    int horiz_wind = 0;
    float last_x = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (seg = ctx->horiz_first; seg != NULL;)
    {
        /* Find a cluster with common horiz_x, */
        svg_act_seg_t *curs;
        float x = seg->horiz_x;

        /* Generate any horizontal segments. */
        if (horiz_wind != 0)
        {
            svp_writer_t *swr = ctx->out;
            int seg_id;

            seg_id = swr->add_segment(swr, winding_number, horiz_wind, last_x, ctx->y);
            swr->add_point(swr, seg_id, x, ctx->y);
            swr->close_segment(swr, seg_id);
        }

        /* Find first active segment in cluster. */

        for (curs = seg; curs != NULL && curs->horiz_x == x; curs = curs->horiz_right)
            if (!(curs->flags & SVG_ACTIVE_FLAGS_DEL))
            {
                break;
            }

        if (curs != NULL && curs->horiz_x == x)
        {
            // There exists at least one active segment in this cluster.
            // Find beginning of cluster.
            for (; curs->left != NULL; curs = curs->left)
                if (curs->left->horiz_x != x)
                {
                    break;
                }

            if (curs->left != NULL)
            {
                winding_number = curs->left->wind_left + curs->left->delta_wind;
            }
            else
            {
                winding_number = 0;
            }
            do
            {
                if (!(curs->flags & SVG_ACTIVE_FLAGS_OUT) || curs->wind_left != winding_number)
                {
                    svp_writer_t *swr = ctx->out;

                    if (curs->flags & SVG_ACTIVE_FLAGS_OUT)
                    {
                        swr->add_point(swr, curs->seg_id, curs->horiz_x, ctx->y);
                        swr->close_segment(swr, curs->seg_id);
                    }
                    curs->seg_id = swr->add_segment(swr, winding_number, curs->delta_wind, x, ctx->y);
                    curs->flags |= SVG_ACTIVE_FLAGS_OUT;
                }
                curs->wind_left = winding_number;
                winding_number += curs->delta_wind;
                curs = curs->right;
            } while (curs != NULL && curs->horiz_x == x);
        }

        /* Skip past cluster. */
        do
        {
            svg_act_seg_t *next = seg->horiz_right;

            seg->flags &= ~SVG_ACTIVE_FLAGS_IN_HORIZ;
            horiz_wind += seg->horiz_delta_wind;
            seg->horiz_delta_wind = 0;
            if (seg->flags & SVG_ACTIVE_FLAGS_DEL)
            {
                if (seg->flags & SVG_ACTIVE_FLAGS_OUT)
                {
                    svp_writer_t *swr = ctx->out;

                    swr->close_segment(swr, seg->seg_id);
                }
                svg_intersect_active_free(seg);
            }
            seg = next;
        } while (seg != NULL && seg->horiz_x == x);
        last_x = x;
    }
    ctx->horiz_first = NULL;
    ctx->horiz_last = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  svg_svp_intersector
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in      [?]     
 *  out     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_svp_intersector(svg_svp_t *in, svp_writer_t *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_intersect_cntx_t *ctx;
    svg_pq_t *pq;
    svg_pq_pos_t *first_point;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in->n_segs == 0)
    {
        return;
    }

    ctx = (svg_intersect_cntx_t*) svg_mem_malloc(sizeof(svg_intersect_cntx_t));
    ctx->in = in;
    ctx->out = out;
    pq = svg_pq_new();
    ctx->pq = pq;

    ctx->active_head = NULL;
    ctx->horiz_first = NULL;
    ctx->horiz_last = NULL;

    ctx->in_curs = 0;
    first_point = (svg_pq_pos_t*) svg_mem_malloc(sizeof(svg_pq_pos_t));
    first_point->x = in->segs[0].points[0].x;
    first_point->y = in->segs[0].points[0].y;
    first_point->data = NULL;
    ctx->y = first_point->y;
    svg_pq_insert(pq, first_point);

    while (!svg_pq_is_empty(pq))
    {
        svg_pq_pos_t *pri_point = svg_pq_pop(pq);
        svg_act_seg_t *seg = (svg_act_seg_t*) pri_point->data;

        if (ctx->y != pri_point->y)
        {
            svg_intersect_horiz_commit(ctx);
            ctx->y = pri_point->y;
        }

        if (seg == NULL)
        {
            svg_seg_t *in_seg = &in->segs[ctx->in_curs++];

            svg_intersect_add_seg(ctx, in_seg);
            if (ctx->in_curs < in->n_segs)
            {
                svg_seg_t *next_seg = &in->segs[ctx->in_curs];

                pri_point->x = next_seg->points[0].x;
                pri_point->y = next_seg->points[0].y;
                svg_pq_insert(pq, pri_point);
            }
            else
            {
                svg_mem_free(pri_point);
            }
        }
        else
        {
            int n_stack = seg->n_stack;

            if (n_stack > 1)
            {
                svg_intersect_process_intersection(ctx, seg);
                svg_mem_free(pri_point);
            }
            else
            {
                svg_intersect_advance_cursor(ctx, seg, pri_point);
            }
        }
    }
    svg_intersect_horiz_commit(ctx);
    svg_pq_free(pq);
    svg_mem_free(ctx);
}


/*****************************************************************************
 * FUNCTION
 *  svg_svp_intersect_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in      [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_svp_t *svg_svp_intersect_process(svg_svp_t *in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svp_writer_t *swr;
    svg_svp_t *out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (svg_context->style.flag & SVG_STYLE_FLAG_FILL_RULE_EVENODD)
    {
        swr = svg_writer_rewind_new(SVG_WIND_RULE_ODDEVEN);
    }
    else
    {
        swr = svg_writer_rewind_new(SVG_WIND_RULE_NONZERO);
    }

    svg_svp_intersector(in, swr);
    out = svg_writer_rewind_reap(swr);
    return out;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


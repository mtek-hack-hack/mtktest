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
#include "svg_svp.h"

#define EPSILON 0


/*****************************************************************************
 * FUNCTION
 *  svg_seg_compare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s1      [IN]        
 *  s2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int svg_seg_compare(const void *s1, const void *s2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_seg_t *seg1 = (svg_seg_t*) s1;
    svg_seg_t *seg2 = (svg_seg_t*) s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (seg1->points[0].y - EPSILON > seg2->points[0].y)
    {
        return 1;
    }
    else if (seg1->points[0].y + EPSILON < seg2->points[0].y)
    {
        return -1;
    }
    else if (seg1->points[0].x - EPSILON > seg2->points[0].x)
    {
        return 1;
    }
    else if (seg1->points[0].x + EPSILON < seg2->points[0].x)
    {
        return -1;
    }
    else if ((seg1->points[1].x - seg1->points[0].x) *
             (seg2->points[1].y - seg2->points[0].y) -
             (seg1->points[1].y - seg1->points[0].y) * (seg2->points[1].x - seg2->points[0].x) > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_svp_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
svg_svp_t *svg_svp_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_svp_t *svp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svp = svg_mem_malloc(sizeof(svg_svp_t));
    svp->max_segs = 1;
    svp->n_segs = 0;
    return svp;
}


/*****************************************************************************
 * FUNCTION
 *  svg_svp_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  svp     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_svp_free(svg_svp_t *svp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int n_segs = svp->n_segs;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < n_segs; i++)
    {
        svg_mem_free(svp->segs[i].points);
    }
    svg_mem_free(svp);
}


/*****************************************************************************
 * FUNCTION
 *  svg_svp_enlarge
 * DESCRIPTION
 *  
 * PARAMETERS
 *  svp     [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_svp_t *svg_svp_enlarge(svg_svp_t *svp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_svp_t *new_svp;
    int m = svp->max_segs + 8;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_svp = svg_mem_malloc(sizeof(svg_svp_t) + (m - 1) * sizeof(svg_seg_t));
    if (new_svp == NULL)
    {
        return NULL;
    }

    memcpy(new_svp, svp, sizeof(svg_svp_t) + (svp->max_segs - 1) * sizeof(svg_seg_t));
    svg_mem_free(svp);
    svp = new_svp;

    svp->max_segs = m;

    return svp;
}


/*****************************************************************************
 * FUNCTION
 *  reverse_points
 * DESCRIPTION
 *  
 * PARAMETERS
 *  points          [?]         
 *  n_points        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void reverse_points(svg_pos_t *points, int n_points)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    svg_pos_t tmp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (n_points >> 1); i++)
    {
        tmp_p = points[i];
        points[i] = points[n_points - (i + 1)];
        points[n_points - (i + 1)] = tmp_p;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_svp_create_from_vpath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vpath       [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_svp_t *svg_svp_create_from_vpath(svg_vpath_t *vpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_svp_t *svp;
    int n_segs;
    int dir;
    int new_dir;
    int i;
    svg_pos_t *points;
    int n_points, n_points_max;
    float x, y;
    float x_min, x_max;
    svg_pos_t *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svp = svg_svp_create();
    n_segs = 0;

    dir = 0;
    n_points = 0;
    n_points_max = 0;
    points = NULL;

    path = vpath->path;

    x = y = 0;
    x_min = x_max = 0;
    for (i = 0; i < vpath->len; i++)
    {
        if (VPATH_IS_MOVETO(path, vpath->len, i))   /* MOVETO */
        {
            if (points != NULL && n_points >= 2)
            {
                if (n_segs == svp->max_segs)
                {
                    svp = svg_svp_enlarge(svp);
                }

                svp->segs[n_segs].n_points = n_points;
                svp->segs[n_segs].dir = (dir > 0);
                if (dir < 0)
                {
                    reverse_points(points, n_points);
                }
                svp->segs[n_segs].points = points;
                svp->segs[n_segs].bbox[0] = x_min;
                svp->segs[n_segs].bbox[2] = x_max;
                svp->segs[n_segs].bbox[1] = points[0].y;
                svp->segs[n_segs].bbox[3] = points[n_points - 1].y;
                n_segs++;
                points = NULL;
            }

            if (points == NULL)
            {
                n_points_max = 4;
                points = svg_mem_malloc(n_points_max * sizeof(svg_pos_t));
            }

            n_points = 1;
            points[0].x = x = path[i].x;
            points[0].y = y = path[i].y;
            x_min = x;
            x_max = x;
            dir = 0;
            i++;    /* move to need drop one item */
        }
        else    /* LINETO */
        {
            new_dir = (path[i].y > y || (path[i].y == y && path[i].x > x)) ? 1 : -1;
            if (dir && dir != new_dir)
            {
                /* new segment */
                x = points[n_points - 1].x;
                y = points[n_points - 1].y;
                if (n_segs == svp->max_segs)
                {
                    svp = svg_svp_enlarge(svp);
                }

                svp->segs[n_segs].n_points = n_points;
                svp->segs[n_segs].dir = (dir > 0);
                if (dir < 0)
                {
                    reverse_points(points, n_points);
                }
                svp->segs[n_segs].points = points;
                svp->segs[n_segs].bbox[0] = x_min;
                svp->segs[n_segs].bbox[2] = x_max;
                svp->segs[n_segs].bbox[1] = points[0].y;
                svp->segs[n_segs].bbox[3] = points[n_points - 1].y;
                n_segs++;

                n_points = 1;
                n_points_max = 4;
                points = svg_mem_malloc(n_points_max * sizeof(svg_pos_t));
                points[0].x = x;
                points[0].y = y;
                x_min = x;
                x_max = x;
            }

            if (points != NULL)
            {
                if (n_points == n_points_max)
                {
                    svg_pos_t *new_points;
                    int n = n_points_max + 4;

                    new_points = svg_mem_malloc(sizeof(svg_pos_t) * n);
                    memcpy(new_points, points, n_points_max * sizeof(svg_pos_t));
                    svg_mem_free(points);
                    points = new_points;
                    n_points_max = n;
                }
                points[n_points].x = x = path[i].x;
                points[n_points].y = y = path[i].y;
                if (x < x_min)
                {
                    x_min = x;
                }
                else if (x > x_max)
                {
                    x_max = x;
                }
                n_points++;
            }
            dir = new_dir;
        }
    }

    /* finish insert svp tree */

    if (points != NULL)
    {
        if (n_points >= 2)
        {
            if (n_segs == svp->max_segs)
            {
                svp = svg_svp_enlarge(svp);
            }
            svp->segs[n_segs].n_points = n_points;
            svp->segs[n_segs].dir = (dir > 0);
            if (dir < 0)
            {
                reverse_points(points, n_points);
            }
            svp->segs[n_segs].points = points;
            svp->segs[n_segs].bbox[0] = x_min;
            svp->segs[n_segs].bbox[2] = x_max;
            svp->segs[n_segs].bbox[1] = points[0].y;
            svp->segs[n_segs].bbox[3] = points[n_points - 1].y;
            n_segs++;
        }
        else
        {
            svg_mem_free(points);
        }
    }

    svp->n_segs = n_segs;

    svg_qsort(&svp->segs, n_segs, sizeof(svg_seg_t), svg_seg_compare);
    return svp;
}


/*****************************************************************************
 * FUNCTION
 *  svg_svp_calculate_bounds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rect        [?]     
 *  svp         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_svp_calculate_bounds(float rect[4], svg_svp_t *svp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;
    float x, y;
    float bigx, littlex, bigy, littley, assignedonce;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bigx = littlex = bigy = littley = assignedonce = 0;

    for (i = 0; i < svp->n_segs; i++)
    {
        for (j = 0; j < svp->segs[i].n_points; j++)
        {
            x = svp->segs[i].points[j].x;
            y = svp->segs[i].points[j].y;

            if (!assignedonce)
            {
                bigx = x;
                littlex = x;
                bigy = y;
                littley = y;
                assignedonce = 1;
            }
            if (x > bigx)
            {
                bigx = x;
            }
            if (x < littlex)
            {
                littlex = x;
            }
            if (y > bigy)
            {
                bigy = y;
            }
            if (y < littley)
            {
                littley = y;
            }
        }
    }
    rect[0] = littlex;
    rect[1] = littley;
    rect[2] = bigx;
    rect[3] = bigy;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


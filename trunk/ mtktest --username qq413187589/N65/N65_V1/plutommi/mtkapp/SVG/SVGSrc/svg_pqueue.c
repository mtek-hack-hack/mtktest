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


/*****************************************************************************
 * FUNCTION
 *  svg_pq_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
svg_pq_t *svg_pq_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_pq_t *result = (svg_pq_t*) svg_mem_malloc(sizeof(svg_pq_t));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result->n_items = 0;
    result->n_items_max = 8;
    result->items = (svg_pq_pos_t **) svg_mem_malloc(sizeof(svg_pq_pos_t*) * result->n_items_max);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  svg_pq_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pq      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_pq_free(svg_pq_t *pq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_mem_free(pq->items);
    svg_mem_free(pq);
}


/*****************************************************************************
 * FUNCTION
 *  svg_pq_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pq      [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL svg_pq_is_empty(svg_pq_t *pq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pq->n_items == 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_pq_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pq          [?]         
 *  vacant      [IN]        
 *  missing     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svg_pq_up(svg_pq_t *pq, int vacant, svg_pq_pos_t *missing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_pq_pos_t **items = pq->items;
    int parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent = (vacant - 1) >> 1;
    while (vacant > 0 && (missing->y < items[parent]->y
                          || (missing->y == items[parent]->y && missing->x < items[parent]->x)))
    {
        items[vacant] = items[parent];
        vacant = parent;
        parent = (vacant - 1) >> 1;
    }

    items[vacant] = missing;
}


/*****************************************************************************
 * FUNCTION
 *  svg_pq_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pq          [?]     
 *  point       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_pq_insert(svg_pq_t *pq, svg_pq_pos_t *point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pq->n_items == pq->n_items_max)
    {
        int m = pq->n_items_max + 8;
        svg_pq_pos_t **new_items = (svg_pq_pos_t **) svg_mem_malloc(sizeof(svg_pq_pos_t **) * m);

        memcpy(new_items, pq->items, sizeof(svg_pq_pos_t **) * pq->n_items_max);
        svg_mem_free(pq->items);
        pq->items = new_items;
        pq->n_items_max = m;
    }
    svg_pq_up(pq, pq->n_items++, point);
}


/*****************************************************************************
 * FUNCTION
 *  svg_pq_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pq          [?]     
 *  missing     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_pq_down(svg_pq_t *pq, svg_pq_pos_t *missing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_pq_pos_t **items = pq->items;
    int vacant = 0, child = 2;
    int n = pq->n_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (child < n)
    {
        if (items[child - 1]->y < items[child]->y ||
            (items[child - 1]->y == items[child]->y && items[child - 1]->x < items[child]->x))
        {
            child--;
        }
        items[vacant] = items[child];
        vacant = child;
        child = (vacant + 1) << 1;
    }
    if (child == n)
    {
        items[vacant] = items[n - 1];
        vacant = n - 1;
    }

    svg_pq_up(pq, vacant, missing);
}


/*****************************************************************************
 * FUNCTION
 *  svg_pq_pop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pq      [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_pq_pos_t *svg_pq_pop(svg_pq_t *pq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_pq_pos_t *result = pq->items[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_pq_down(pq, pq->items[--pq->n_items]);
    return result;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


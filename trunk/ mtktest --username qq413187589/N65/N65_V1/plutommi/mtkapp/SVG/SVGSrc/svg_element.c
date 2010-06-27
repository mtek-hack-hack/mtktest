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
#include "svg_transform.h"


/*****************************************************************************
 * FUNCTION
 *  svg_element_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  element     [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_element_create(svg_element_t **element, svg_element_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *element = svg_mem_malloc(sizeof(svg_element_t));
    if (*element == NULL)
    {
        return SVG_FAIL_NO_MEMORY;
    }

    memset(*element, 0, sizeof(svg_element_t));

    (*element)->type = type;

    svg_transform_identify((*element)->animate_transform);

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_element_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent      [?]     
 *  child       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_element_add(svg_element_t *parent, svg_element_t *child)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_element_t *p = parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    child->sib = NULL;  /* just make sure sib list is clear */

    if (p->child == NULL)   /* first child */
    {
        p->child = child;
    }
    else
    {
        p = p->child;
        while (p->sib != NULL)
        {
            p = p->sib;
        }
        p->sib = child;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_element_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent      [?]     
 *  child       [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL svg_element_del(svg_element_t *parent, svg_element_t *child)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = FALSE;
    svg_element_t *p = parent;
    svg_element_t *c = child;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->child == NULL)
    {
        /* nothing to do */
    }
    else if (p->child == c) /* first child */
    {
        p->child = c->sib;  /* remove it */
        c->sib = NULL;
        ret = TRUE;
    }
    else
    {
        p = p->child;
        while (p->sib != NULL && p->sib != c)
        {
            p = p->sib;
        }

        if (p->sib == c)    /* in sib child */
        {
            p->sib = c->sib;    /* remove it */
            c->sib = NULL;
            ret = TRUE;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_element_del_all_child
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_element_del_all_child(svg_element_t *parent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent->child = NULL;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */


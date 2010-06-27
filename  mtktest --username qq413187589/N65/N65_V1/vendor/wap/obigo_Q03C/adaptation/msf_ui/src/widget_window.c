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
 * widget_window.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfWindow common routines
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
/****************************************************************
 WINDOW 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetWindowAddGadget
 * DESCRIPTION
 *  
 * PARAMETERS
 *  window          [IN]        
 *  gadget          [IN]        
 *  position        [?]         
 *  alignment       [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetWindowAddGadget(
        MsfWindowHandle window,
        MsfGadgetHandle gadget,
        MsfPosition *position,
        MsfAlignment *alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* widget_header_struct *a; */
    if (gadget == 0)
    {
        return 0;
    }

    widget_index_childs(index, window, gadget);
    if (index >= 0)
    {
        return 0;   /* already in window */
    }

    WAP_DBG_ASSERT(widget_check_object_validity(_H(window)) && widget_check_object_validity(_H(gadget)));

    /* set the gadget position, alignment */
    if (position)
    {
        _W(gadget)->position = *position;
    }
#ifndef WIDGET_COMPACT_RUNTIME_STRUCT
    if (alignment)
    {
        _W(gadget)->alignment = *alignment;
    }
#endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

    /* link gadget into window */
    widget_insert_last_childs(window, gadget);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
    /*
     * If the first gadget cannot be focused, but the second gadget can, we 
     * * should make the second gadget focused after insertion.
     */
    if (IS_FORM_TYPE(window))
    {
        widget_form_on_gadget_added(_H(window), _H(gadget));
    }
#endif /* 0 */ 

    /* widget_paint(); // Do we need this? */

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetWindowSetTicker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  window          [IN]        
 *  tickerText      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetWindowSetTicker(MsfWindowHandle window, MsfStringHandle tickerText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(0);  /* Unsupported */

#ifndef WIDGET_COMPACT_RUNTIME_STRUCT
    widget_set_attrib(_W(window), ticker, tickerText);
#endif 

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetWindowSetProperties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  window              [IN]        
 *  propertyMask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetWindowSetProperties(MsfWindowHandle window, int propertyMask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_ACTION_TYPE(window))
    {
        // We do not use propertyMask (inc. MSF_WINDOW_PROPERTY_TITLE) in MsfAction
        // but we support HDIa_widgetSetTitle for MsfAction
        return 0;
    }

    if (widget_get_current_focused_window() == _W(window))
    {
        if ((propertyMask & MSF_WINDOW_PROPERTY_BUSY) && !(_W(window)->property_mask & MSF_WINDOW_PROPERTY_BUSY))
        {
            widget_enable_status_bar(WIDGET_STATUS_BAR_BUSY);
        }
        else if (!(propertyMask & MSF_WINDOW_PROPERTY_BUSY) && (_W(window)->property_mask & MSF_WINDOW_PROPERTY_BUSY))
        {
            widget_disable_status_bar(WIDGET_STATUS_BAR_BUSY);
        }
    }

    _W(window)->property_mask = propertyMask;

    widget_paint();

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetWindowGetProperties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  window      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetWindowGetProperties(MsfWindowHandle window)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _W(window)->property_mask;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetWindowSpecificSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  window          [IN]        
 *  size            [?]         
 *  minimalSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetWindowSpecificSize(MsfWindowHandle window, MsfSize *size, int minimalSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *size = WGUI_CTX->display_size;
    return 1;
}


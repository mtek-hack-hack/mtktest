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
 * widget_screen.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfScreen creation/attributes
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
 SCREEN 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetScreenCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  notify              [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfScreenHandle HDIa_widgetScreenCreate(MSF_UINT8 modId, int notify, MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* create screen object */
    widget_screen_struct *w = widget_create_screen(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    widget_insert_last_childs((&WGUI_CTX->widget_root), w);

    /* setting screen */
    widget_set_attrib(w, style, defaultStyle);
    set_bit_flag(w->property_mask, MSF_WINDOW_PROPERTY_NOTIFY, notify);

    return (MsfScreenHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetScreenSetNotify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen      [IN]        
 *  notify      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetScreenSetNotify(MsfScreenHandle screen, int notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* subscribe notify function */
    set_bit_flag(_SCREEN(screen)->property_mask, MSF_WINDOW_PROPERTY_NOTIFY, notify);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetScreenAddWindow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen          [IN]        
 *  window          [IN]        
 *  position        [?]         
 *  nextScreen      [IN]        
 *  nextWindow      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetScreenAddWindow(
        MsfScreenHandle screen,
        MsfWindowHandle window,
        MsfPosition *position,
        MsfScreenHandle nextScreen,
        MsfWindowHandle nextWindow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (screen == 0 || window == 0)
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    WAP_DBG_ASSERT(widget_check_object_validity(_H(screen)) && widget_check_object_validity(_H(window)));

    widget_index_childs(index, screen, window);
    if (index >= 0)
    {
        return 0;   /* already in screen */
    }

    if (IS_DIALOG_TYPE(window))
    {   /* should ignore position */
        _DIALOG(window)->next_screen = _SCREEN(nextScreen);
        _DIALOG(window)->next_window = _W(nextWindow);
    }
    else    /* should ignore nextScreen, nextWindow */
    {
        _W(window)->position = *position;
    }

    /* link window into screen */
    widget_insert_last_childs(_H(screen), _H(window));
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetScreenActiveWindow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetScreenActiveWindow(MsfScreenHandle screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_get_active_childs(node, _H(screen));
    return (MsfWindowHandle) node;
}


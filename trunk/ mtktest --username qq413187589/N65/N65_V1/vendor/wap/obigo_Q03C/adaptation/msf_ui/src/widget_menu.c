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
 * widget_menu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * MsfChoice creation & attributes
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/*
 * Explanations:
 * 
 * - widget_menu_struct.profile_activated_index
 * 
 * Highlighted menu item in menu has MSF_CHOICE_ELEMENT_SELECTED,
 * and we display the menu item with MSF_CHOICE_ELEMENT_SELECTED as activated profile in profile menu 
 * inside widget_show_radio_list_menu().
 * 
 * In the current design, BRA restore MSF_CHOICE_ELEMENT_SELECTED to the activated profile when
 * profile menu is defocused and focused again.
 * 
 * However, if a popup (e.g. charger and USB) comes and exits, it will display the highlighted menu item as activated profile.
 * This is wrong. In order to solve this, we use 'profile_activated_index' to store the activated profile,
 * and use it until the MsfMenu is defocused. (Because user might activate another profile in other place)
 * (Obigo framework does not handle external non-widget screens)
 * 
 * This is tricky. It can be solved gracefully by replacing profile menu as CTK window.
 */

/****************************************************************
 MENU 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetMenuCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                       [IN]        
 *  type                        [IN]        
 *  size                        [IN]         
 *  implicitSelectAction        [IN]        
 *  elementPos                  [IN]         
 *  bitmask                     [IN]        
 *  propertyMask                [IN]        
 *  defaultStyle                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetMenuCreate(
                    MSF_UINT8 modId,
                    MsfChoiceType type,
                    MsfSize *size,
                    MsfActionHandle implicitSelectAction,
                    MsfElementPosition *elementPos,
                    int bitmask,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_menu_struct *w = widget_create_menu(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    if (type == MsfExclusiveChoiceDropDown)
    {
        type = MsfExclusiveChoice;
    }

    w->choice_type = type;

    if (size)
    {
        w->size = *size;
    }
    else
    {
        w->size = WGUI_CTX->default_display_size;
    }

    /*
     * For MMI display quality.
     * * (Not checked in HDIa_widgetSelectgroupCreate()) 
     */
    if (w->size.height > MMI_content_height)
    {
        w->size.height = MMI_content_height;
    }

    if (elementPos)
    {
        w->element_position = *elementPos;
    }
    w->element_bitmask = bitmask;
    w->property_mask = propertyMask;
    w->highlight_index = -1;
    w->profile_activated_index = -1;

    widget_set_attrib(w, style, defaultStyle);

    if (implicitSelectAction)
    {
        widget_insert_last_childs(w, implicitSelectAction);
    }
    widget_update_action_total_mask(_W(w));

    return (MsfWindowHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetMenuAppCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                       [IN]        
 *  implicitSelectAction        [IN]        
 *  elementPos                  [IN]         
 *  bitmask                     [IN]        
 *  propertyMask                [IN]        
 *  defaultStyle                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetMenuAppCreate(
                    MSF_UINT8 modId,
                    MsfActionHandle implicitSelectAction,
                    MsfElementPosition *elementPos,
                    int bitmask,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_menu_struct *w = widget_create_menu(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    w->choice_type = MsfImplicitChoice;

    w->size = WGUI_CTX->default_display_size;

    if (elementPos)
    {
        w->element_position = *elementPos;
    }
    w->element_bitmask = bitmask;
    w->property_mask = propertyMask;
    w->highlight_index = -1;
    w->profile_activated_index = -1;

    widget_set_attrib(w, style, defaultStyle);

    if (implicitSelectAction)
    {
        widget_insert_last_childs(w, implicitSelectAction);
    }
    widget_update_action_total_mask(_W(w));

    return (MsfWindowHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetMenuAppCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu                        [IN]        
 *  cb_func                     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void HDIa_widgetExtMenuRegisterHighlightHandle(
                    MsfWindowHandle menu,
                    MsfMenuExtHighlightHandle cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_menu_struct *w = (widget_menu_struct *)menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->highlight_handler = cb_func;
}


/****************************************************************
 CHOICE 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetChoiceSetElement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 *  index       [IN]        
 *  string1     [IN]        
 *  string2     [IN]        
 *  image1      [IN]        
 *  image2      [IN]        
 *  insert      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetChoiceSetElement(
        MSF_UINT32 choice,
        int index,
        MsfStringHandle string1,
        MsfStringHandle string2,
        MsfImageHandle image1,
        MsfImageHandle image2,
        int insert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    kal_bool is_added = KAL_FALSE;
    widget_choice_element_struct *node;
    widget_choice_element_struct *element = widget_create_choice_element(_H(choice)->module_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    element->module_id = _H(choice)->module_id;

    cnt = 0;
    foreach(_H(choice), CHOICE_ELEMENT, node,
        {
            if (cnt >= index)
            {
                if (!insert)
                {
                    /*
                     * e.g. Edit profile name, then go back to profile menu, 
                     * BRA would replace the menu item, and we need to 
                     * reserve the attribute of the replaced meu item 
                     */
                    element->state = node->state;
                    widget_replace_childs_by_index(choice, element, _i);
                }
                else
                {
                    widget_insert_childs_by_index(choice, element, _i);
                    _M(choice)->menu_items_sum++;
                }
                is_added = KAL_TRUE;
                break;
            }
            cnt++;
        }
    );
    if (!is_added)
    {
        widget_insert_last_childs(choice, element);
        index = _M(choice)->menu_items_sum;
        _M(choice)->menu_items_sum++;
    }

    widget_set_attrib(element, string1, string1);
    widget_set_attrib(element, string2, string2);
    widget_set_attrib(element, image1, image1);
    widget_set_attrib(element, image2, image2);

    /* widget_paint(); */

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetChoiceElemProperty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice          [IN]        
 *  index           [IN]        
 *  elementPos      [IN]         
 *  bitmask         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetChoiceElemProperty(MSF_UINT32 choice, int index, MsfElementPosition *elementPos, int bitmask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetChoiceRemoveElement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetChoiceRemoveElement(MSF_UINT32 choice, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    kal_bool is_removed = KAL_FALSE;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnt = 0;
    foreach(_H(choice), CHOICE_ELEMENT, node,
        {
            if (cnt == index)
            {
                widget_remove_childs_by_index(choice, _i);
                is_removed = KAL_TRUE;
                break;
            }
            cnt++;
        }
    );

    if (is_removed)
    {
        _M(choice)->menu_items_sum--;
        return 1;
    }
    else
    {
        return -1;
    }

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetChoiceGetElemState
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetChoiceGetElemState(MSF_UINT32 choice, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnt = 0;
    foreach(_H(choice), CHOICE_ELEMENT, node,
        {
            if (cnt == index)
            {
                if (IS_MENU_TYPE(choice))
                    if (node->state & MSF_CHOICE_ELEMENT_FOCUSED)
                        node->state |= MSF_CHOICE_ELEMENT_SELECTED;
                return node->state;
            }
            cnt++;
        }
    );

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetChoiceSetElemState
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 *  index       [IN]        
 *  state       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetChoiceSetElemState(MSF_UINT32 choice, int index, int state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* HACK. reset 'profile_activated_index' */
    if ((state & MSF_CHOICE_ELEMENT_SELECTED) && IS_MENU_TYPE(choice))
    {
        widget_menu_struct *menu = _M(choice);

        if (menu->profile_activated_index >= 0)
        {
            menu->profile_activated_index = -1;
        }
    }

    cnt = 0;
    foreach(_H(choice), CHOICE_ELEMENT, node,
        {
            if (cnt == index)
            {
                node->state = state; 
                if (state == MSF_CHOICE_ELEMENT_DISABLED)
                {
                    if(_M(choice)->highlight_index > cnt)
                    {
                        _M(choice)->highlight_index--;
                    }
                    _M(choice)->menu_items_sum--;
                }
                return 1;
            }
            cnt++;
        }
    );
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtChoiceSetElemFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 *  index       [IN]        
 *  flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtChoiceSetElemFlag(MSF_UINT32 choice, int index, MSF_UINT8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnt = 0;
    foreach(_H(choice), CHOICE_ELEMENT, node,
        {
            if (cnt == index)
            {
                node->flags |= flag;
                return 1;
            }
            cnt++;
        }
    );
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtChoiceUnsetElemFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 *  index       [IN]        
 *  flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtChoiceUnsetElemFlag(MSF_UINT32 choice, int index, MSF_UINT8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnt = 0;
    foreach(_H(choice), CHOICE_ELEMENT, node,
        {
            if (cnt == index)
            {
                node->flags &= (~flag);
                return 1;
            }
            cnt++;
        }
    );
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtChoiceGetFocusedElemFlags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 *  flags       [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtChoiceGetFocusedElemFlags(MSF_UINT32 choice, MSF_UINT8 *flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt;
    widget_choice_element_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnt = 0;
    foreach(_H(choice), CHOICE_ELEMENT, node,
        {
            if (node->state & MSF_CHOICE_ELEMENT_FOCUSED)
            {
                *flags = node->flags;
                return 1;
            }
            cnt++;
        }
    );
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetChoiceAttrProperty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice          [IN]        
 *  elementPos      [IN]         
 *  bitmask         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetChoiceAttrProperty(MSF_UINT32 choice, MsfElementPosition *elementPos, int bitmask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_MENU_TYPE(choice))
    {
        if (elementPos)
        {
            _M(choice)->element_position = *elementPos;
        }
        _M(choice)->element_bitmask = bitmask;
        return 1;
    }
    if (IS_GADGET_SELECT_GROUP_TYPE(choice))
    {
        if (elementPos)
        {
            _GADGET_SELECT_GROUP(choice)->element_position = *elementPos;
        }
        _GADGET_SELECT_GROUP(choice)->element_bitmask = bitmask;
        return 1;
    }
    WAP_RST_ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetChoiceSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choice      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetChoiceSize(MSF_UINT32 choice)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _M(choice)->menu_items_sum;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtMenuProfileStyle
 * DESCRIPTION
 *  Emulate profile selection menu for a multiple choice menu
 * PARAMETERS
 *  menu        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtMenuProfileStyle(MsfWindowHandle menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_MENU_TYPE(menu))
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    _M(menu)->menu_flags |= WIDGET_MENU_FLAG_PROFILE_STYLE;
}


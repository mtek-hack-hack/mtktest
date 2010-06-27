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
 * widget_action.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Widget MsfAction
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

/****************************************************************
 ACTION 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  power2count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 power2count(kal_uint32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (result = 0; !(x & 1); result++, x >>= 1)
    {
        ;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  widget_update_action_total_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  w       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_update_action_total_mask(widget_window_struct *w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_action_struct *act;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->total_action_mask = 0;
    foreach(w, ACTION, act,
            {
            //if((act->property_mask & MSF_ACTION_PROPERTY_ENABLED)
            //|| (act->property_mask == 0x8000))
            w->total_action_mask |= act->action_mask;});

}


/*****************************************************************************
 * FUNCTION
 *  widget_fire_action_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  act         [IN]         
 *  object      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_fire_action_object(MSF_UINT8 modId, widget_action_struct *act, MSF_UINT32 object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* However, MSF_ACTION_PROPERTY_ENABLED is not currently used now */
    if (act->property_mask & MSF_ACTION_PROPERTY_SINGLEACTION)
    {
        disable_bit_flag(act->property_mask, MSF_ACTION_PROPERTY_ENABLED);
    }

#ifdef WIDGET_DROP_KEY_ON_ACTION_SIGNALED
    /* Hack. Applications might create MsfMenu action without handling it */
    if (WGUI_CTX->is_widget_screen && act->action_mask != (1 << MsfMenu))
    {
        ClearAllKeyHandler();
        widget_init_key_queue();    /* flush key queue */
        widget_enable_clear_all_handler();
        widget_clear_all_handler();
    }
#endif /* WIDGET_DROP_KEY_ON_ACTION_SIGNALED */ 

    HDIc_widgetAction(modId, object, (MSF_UINT32) act);

    widget_send_update_event_to_wap();
}


/*****************************************************************************
 * FUNCTION
 *  widget_fire_action_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node            [IN]         
 *  action_mask     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_fire_action_internal(widget_window_struct *node, kal_uint32 action_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node->total_action_mask & action_mask)
    {
        widget_action_struct *act;

        foreach(node, ACTION, act,
                {
                if (act->action_mask == action_mask)
                {
                widget_fire_action_object(node->module_id, act, (MSF_UINT32) node); return KAL_TRUE;}
                }
        );
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_fire_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node            [IN]         
 *  key_event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_fire_action(widget_window_struct *node, MsfEventType key_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_event == MsfKey_Soft1 && WGUI_CTX->LSK_mask)
    {
        if (widget_fire_action_internal(node, WGUI_CTX->LSK_mask))
        {
            return KAL_TRUE;
        }
    }
    else if (key_event == MsfKey_Soft2 && WGUI_CTX->RSK_mask)
    {
        if (widget_fire_action_internal(node, WGUI_CTX->RSK_mask))
        {
            return KAL_TRUE;
        }
    }
    else if (key_event == MsfKey_Menu)
    {
        if (widget_fire_action_internal(node, 1 << MsfMenu))
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

/* sometimes we want to let keys other than LSK and RSK to fire these action */


/*****************************************************************************
 * FUNCTION
 *  widget_fire_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_fire_RSK(widget_window_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->RSK_mask)
    {
        return widget_fire_action_internal(node, WGUI_CTX->RSK_mask);
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_fire_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_fire_LSK(widget_window_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->LSK_mask)
    {
        return widget_fire_action_internal(node, WGUI_CTX->LSK_mask);
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetActionCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  label               [IN]        
 *  actionType          [IN]        
 *  priority            [IN]        
 *  propertyMask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfActionHandle HDIa_widgetActionCreate(
                    MSF_UINT8 modId,
                    MsfStringHandle label,
                    int actionType,
                    int priority,
                    int propertyMask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_action_struct *w = widget_create_action(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (propertyMask == 0x8000)
    {
        propertyMask = MSF_ACTION_PROPERTY_ENABLED;
    }

    widget_set_attrib(w, text, label);
    w->action_mask = 1 << actionType;
    w->priority = priority;
    w->property_mask = propertyMask;
    w->module_id = modId;

    return (MsfActionHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetActionSetAttr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action          [IN]        
 *  actionType      [IN]        
 *  priority        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetActionSetAttr(MsfActionHandle action, int actionType, int priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _ACTION(action)->action_mask = 1 << actionType;
    _ACTION(action)->priority = priority;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetActionGetAttr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action          [IN]        
 *  actionType      [OUT]         
 *  priority        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetActionGetAttr(MsfActionHandle action, int *actionType, int *priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *actionType = power2count(_ACTION(action)->action_mask);
    *priority = _ACTION(action)->priority;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetActionSetProperties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action              [IN]        
 *  propertyMask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetActionSetProperties(MsfActionHandle action, int propertyMask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (propertyMask == 0x8000)
    {
        propertyMask = MSF_ACTION_PROPERTY_ENABLED;
    }

    _ACTION(action)->property_mask = propertyMask;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetAddAction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  action      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetAddAction(MSF_UINT32 handle, MsfActionHandle action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_index_childs(index, handle, action);
    if (index >= 0)
    {
        return 0;   /* already in window */
    }

    widget_insert_last_childs(handle, action);

    widget_update_action_total_mask(_W(handle));

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetHandleMsfEvt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle              [IN]        
 *  msfEventType        [IN]        
 *  override            [IN]        
 *  unsubscribe         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetHandleMsfEvt(MSF_UINT32 handle, int msfEventType, int override, int unsubscribe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msfEventType == -1) /* handle all event */
    {
        if (unsubscribe)
        {
            _W(handle)->event_mask = 0;
        }
        else
        {
            _W(handle)->event_mask = (kal_uint32) - 1;
        }

        if (override)
        {
            _W(handle)->event_override = (kal_uint32) - 1;
        }
        else
        {
            _W(handle)->event_override = 0;
        }
    }
    else
    {
        set_bit_flag(_W(handle)->event_mask, 1 << msfEventType, !unsubscribe);
        set_bit_flag(_W(handle)->event_override, 1 << msfEventType, override);
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_hex_to_num
 * DESCRIPTION
 *  Standard Widget API
 *****************************************************************************/
#if 0   /* NOT IMPLEMENTED */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#if 0   /* Deprecated */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/****************************************************************
 ACCESS KEYS
 ****************************************************************/

/* 
 * Note that Obigo defines accesskey as static objects; however, we can not implement it
 * as static objects due to the combination of WAP accesskey is large. 
 * Instead, we add allocated MsfAccesskey objects in a queue and associate them with 
 * MsfScreen/MsfWindow/MsfGadget objects.
 * MsfAccesskey objects are not in widget free list, and they are not released by HDIa_widgetReleaseAll
 *
 * One gadgets/windows might have more than multiple accesskeys
 *
 */

#define IS_HEX(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

static kal_uint16 widget_hex_to_num(char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (c >= '0' && c <= '9')
    {
        return (kal_uint16) (c - '0');
    }
    else if (c >= 'a' && c <= 'z')
    {
        return (kal_uint16) (c - 'a') + 10;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return (kal_uint16) (c - 'A') + 10;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_accesskey_parse_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sym     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 widget_accesskey_parse_symbol(char *sym)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int key;
    kal_uint16 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sym || !sym[0])
    {
        return 0;
    }
#if 0   /* We use arrow key for scrolling web pages */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    /* Unsupported: volumeup, volumedown because they MsfKey_PageDown exceeds 31 */
    else if (sym[0] == '\\')
    {
        if (sym[1] && sym[2] && IS_HEX(sym[1]) && IS_HEX(sym[2]))
        {
            c = widget_hex_to_num(sym[1]) * 16 + widget_hex_to_num(sym[2]);
        }
        else
        {
            return 0;
        }
    }
    else if (sym[1])
    {
        return 0;   /* Unsupported key */
    }
    else
    {
        c = (kal_uint16) * sym;
    }

    key = -1;
    switch (c)
    {
        case '0':
            key = MsfKey_0;
            break;
        case '1':
            key = MsfKey_1;
            break;
        case '2':
            key = MsfKey_2;
            break;
        case '3':
            key = MsfKey_3;
            break;
        case '4':
            key = MsfKey_4;
            break;
        case '5':
            key = MsfKey_5;
            break;
        case '6':
            key = MsfKey_6;
            break;
        case '7':
            key = MsfKey_7;
            break;
        case '8':
            key = MsfKey_8;
            break;
        case '9':
            key = MsfKey_9;
            break;
        case '*':
            key = MsfKey_Star;
            break;
        case '#':
            key = MsfKey_Pound;
            break;
    }
    if (key >= 0)
    {
        WAP_DBG_ASSERT(key < 32);
        return 1 << key;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_accesskey_parse_phrase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phrase          [IN]         
 *  exclusion       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 widget_accesskey_parse_phrase(char *phrase, kal_uint32 exclusion)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *s1, *s2;
    kal_uint32 mask = 0;
    kal_uint32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!phrase || !phrase[0])
    {
        return 0;
    }

    WAP_DBG_ASSERT(strchr(phrase, ',') == NULL);

    s1 = phrase;
    while (*s1)
    {
        s2 = strchr(s1, ' ');
        if (s2)
        {
            *s2 = 0;
        }

        ret = widget_accesskey_parse_symbol(s1) & (~exclusion);
        mask |= ret;

        if (s2)
        {
            s2++;
            while (*s2 && *s2 == ' ')
            {
                s2++;
            }
            if (*s2 == 0)
            {
                break;
            }
            s1 = s2;
        }
        else
        {
            break;
        }
    }

    return mask;
}


/*****************************************************************************
 * FUNCTION
 *  widget_accesskey_parse_definition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  def             [IN]        
 *  exclusion       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 widget_accesskey_parse_definition(const char *def, kal_uint32 exclusion)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 mask = 0;
    char *mydef, *s1, *s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!def)
    {
        return mask;
    }

    /* strtok() is not thread-safe, and we can not use it */
    mydef = msf_cmmn_strdup(MSF_MODID_WIDGET, def);

    s1 = mydef;

    while (*s1 == ' ')
    {
        s1++;
    }

    while (*s1)
    {
        s2 = strchr(s1, ',');
        if (s2)
        {
            *s2 = 0;
        }

        mask = widget_accesskey_parse_phrase(s1, exclusion);
        if (mask)
        {
            break;
        }

        if (s2)
        {
            s1 = s2 + 1;
        }
        else
        {
            break;
        }
    }

    MSF_MEM_FREE(MSF_MODID_WIDGET, mydef);

    return mask;
}

/* En-queue to WGUI_CTX->accesskey_head */


/*****************************************************************************
 * FUNCTION
 *  widget_enqueue_accesskey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  accesskey       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_enqueue_accesskey(widget_accesskey_struct *accesskey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_accesskey_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We need to check the existence first */
    curr = WGUI_CTX->accesskey_head;
    while (curr)
    {
        if (curr == accesskey)
        {
            WAP_DBG_ASSERT(0);
            return KAL_FALSE;
        }
        curr = curr->accesskey_next;
    }

    /* Insert it */
    WAP_DBG_ASSERT(accesskey->accesskey_next == NULL);
    accesskey->accesskey_next = WGUI_CTX->accesskey_head;
    WGUI_CTX->accesskey_head = accesskey;
    return KAL_TRUE;
}

/* De-queue from WGUI_CTX->accesskey_head */


/*****************************************************************************
 * FUNCTION
 *  widget_dequeue_accesskey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  accesskey       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_dequeue_accesskey(widget_accesskey_struct *accesskey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_accesskey_struct *curr, *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(accesskey);

    if (WGUI_CTX->accesskey_head == accesskey)
    {
        WGUI_CTX->accesskey_head = accesskey->accesskey_next;
        accesskey->accesskey_next = NULL;
        return KAL_TRUE;
    }

    prev = WGUI_CTX->accesskey_head;
    curr = prev->accesskey_next;

    while (curr)
    {
        if (curr == accesskey)
        {
            prev->accesskey_next = accesskey->accesskey_next;
            accesskey->accesskey_next = NULL;
            return KAL_TRUE;
        }
        prev = curr;
        curr = curr->accesskey_next;
    }

    return KAL_FALSE;
}

/* Used by message event handler to find out the corresponding MsfAction handle */


/*****************************************************************************
 * FUNCTION
 *  widget_lookup_accesskey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd     [IN]        
 *  key     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfAccessKeyHandle widget_lookup_accesskey(MSF_UINT32 wnd, kal_uint16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_accesskey_struct *accesskey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wnd)
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    accesskey = WGUI_CTX->accesskey_head;
    while (accesskey)
    {
        if (accesskey->window == wnd && (accesskey->mask & (1 << key)))
        {
            return (MsfAccessKeyHandle) accesskey;
        }

        accesskey = accesskey->accesskey_next;
    }

    WAP_DBG_ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_delete_accesskey_by_window
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_delete_accesskey_by_window(MSF_UINT32 wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_accesskey_struct *accesskey, *next;
    kal_bool ret;
    kal_bool found = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wnd)
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    if (!IS_WINDOW_GADGET_TYPE(wnd) && !IS_SCREEN_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    accesskey = WGUI_CTX->accesskey_head;
    while (accesskey)
    {
        next = accesskey->accesskey_next;

        if (accesskey->window == wnd)
        {
            found = KAL_TRUE;

            /* Check it is already freed */
            WAP_DBG_ASSERT(IS_ACCESSKEY_TYPE(accesskey));

            ret = widget_dequeue_accesskey(accesskey);
            WAP_DBG_ASSERT(ret);
            /* Prevent from using it after deallocated */
            if (IS_ACCESSKEY_TYPE(accesskey))
            {
                accesskey->data_type = WIDGET_MAX_TYPE;
                MSF_MEM_FREE(MSF_MODID_WIDGET, accesskey);
            }
        }

        accesskey = next;
    }

    _W(wnd)->accesskey = 0;
    _W(wnd)->accesskey_override = 0;

    return found;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetAccessKey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle                  [IN]        
 *  accessKeyDefinition     [IN]         
 *  override                [IN]        
 *  index                   [IN]        
 *  visualise               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfAccessKeyHandle HDIa_widgetSetAccessKey(
                    MSF_UINT32 handle,
                    char *accessKeyDefinition,
                    int override,
                    int index,
                    int visualise)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 mask;
    widget_accesskey_struct *accesskey = NULL;
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(index);
    WIDGET_UNUSED(visualise);

    if (!accessKeyDefinition)
    {
        return 0;
    }

    if (!IS_WINDOW_GADGET_TYPE(handle) && !IS_SCREEN_TYPE(handle))
    {
        return 0;
    }

    if ((mask = widget_accesskey_parse_definition(
                    accessKeyDefinition,
                    _W(handle)->accesskey | _W(handle)->accesskey_override)) == 0)
    {
        return 0;
    }

    /*
     * Note: We do not allocate the accesskey as other widget objects (width widget_malloc) 
     * * and it is not inserted into widget free list
     */
    accesskey = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_accesskey_struct));
    memset(accesskey, 0, sizeof(widget_accesskey_struct));
    accesskey->data_type = WIDGET_ACCESSKEY_TYPE;
    accesskey->flag = WIDGET_FLAG_STATIC;   /* it is not statically-allocated, however, it do not contain widget_header_struct */
    accesskey->mask = mask;
    accesskey->window = handle;
    accesskey->accesskey_next = NULL;

    ret = widget_enqueue_accesskey(accesskey);
    WAP_DBG_ASSERT(ret);

    /* Screen, window, and gadget share common data structure */
    _W(handle)->accesskey |= mask;
    if (override)
    {
        _W(handle)->accesskey_override |= mask;
    }

    return (MsfAccessKeyHandle) accesskey;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetRemoveAccessKey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  accessKey       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetRemoveAccessKey(MSF_UINT32 handle, MsfAccessKeyHandle accessKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;
    widget_accesskey_struct *accesskey;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!accessKey || !IS_ACCESSKEY_TYPE(accessKey))
    {
        /* accessKey might be already released */
        WAP_DBG_ASSERT(0);
        return 0;
    }

    accesskey = _ACCESSKEY(accessKey);

    if (!handle || (!IS_WINDOW_GADGET_TYPE(handle) && !IS_SCREEN_TYPE(handle)))
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    WAP_DBG_ASSERT(accesskey->window == handle);

    _W(handle)->accesskey &= ~(accesskey->mask);
    _W(handle)->accesskey_override &= ~(accesskey->mask);

    ret = widget_dequeue_accesskey(_ACCESSKEY(accessKey));
    WAP_DBG_ASSERT(ret);

    /* Prevent using it after deallocated */
    accesskey->data_type = WIDGET_MAX_TYPE;
    MSF_MEM_FREE(MSF_MODID_WIDGET, accesskey);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDrawAccessKey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 *  accessKey       [IN]        
 *  position        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDrawAccessKey(MSF_UINT32 msfHandle, MsfAccessKeyHandle accessKey, MsfPosition *position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!accessKey || !IS_ACCESSKEY_TYPE(accessKey))
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtActionSetText
 * DESCRIPTION
 *     Change the text of action object
 * PARAMETERS
 *  action			[IN]        
 *  label			[IN]        
 * RETURNS
 *  
 *****************************************************************************/
void HDIa_widgetExtActionSetText(MsfActionHandle action, MsfStringHandle label)
{
    widget_action_struct *w = (widget_action_struct *)action;

    widget_set_attrib(w, text, label);
}



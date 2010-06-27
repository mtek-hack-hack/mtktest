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
 * widget_msg_hdr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Message flow driven by keypad
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
 * Note on keypad handling of widget and task interaction.
 *
 * Three kinds of methodology:
 *
 * A. Handled in widget_general_keyboard_handler() and widget_key_ind_handler()
 * - Keypad events are queued in WKEY_CTX
 * - MsfAction, MsfEvent are queued in WAP internal queue
 * - Use widget_send_update_event_to_wap() to notify wap task
 *
 * B. From CTK
 * - Currently invoked directly from MMI task.
 * - (FUTURE) Deliver keypad event in an internal queue and execute key handler in WAP task.
 *
 * C. SetKeyHandler/SetLeftSoftkeyFunction/... directly (This should be prevented!)
 * o Type 1: control MMI data/display (e.g. widget_menu_next_item)
 *    - (FUTURE) rename function name
 * o Type 2: control widget data (e.g. widget_dialog_left_softkey_dismiss_handler)
 *    - (FUTURE) ???
 */

/* Keycode => MsfEventType */
const MsfEventType key_map[] = 
{
    // TODO: protect against the case that keycode enum value is changed in MMI.
    /*
     * NOTE:
     * * MsfKey_PageDown should not be used because it exceeds 31
     */
    MsfKey_0,           /* KEY_0                              0 */
    MsfKey_1,           /* KEY_1                              1 */
    MsfKey_2,           /* KEY_2                              2 */
    MsfKey_3,           /* KEY_3                              3 */
    MsfKey_4,           /* KEY_4                              4 */
    MsfKey_5,           /* KEY_5                              5 */
    MsfKey_6,           /* KEY_6                              6 */
    MsfKey_7,           /* KEY_7                              7 */
    MsfKey_8,           /* KEY_8                              8 */
    MsfKey_9,           /* KEY_9                              9 */
    MsfKey_Soft1,       /* KEY_LSK                            10 */
    MsfKey_Soft2,       /* KEY_RSK                            11 */
    MsfKey_Yes,         /* KEY_CSK */
    MsfKey_Up,          /* KEY_UP_ARROW               12 */
    MsfKey_Down,        /* KEY_DOWN_ARROW     13 */
    MsfKey_Left,        /* KEY_LEFT_ARROW     14 */
    MsfKey_Right,       /* KEY_RIGHT_ARROW    15 */
    MsfKey_Yes,         /* KEY_SEND                   16 */
    MsfKey_No,          /* KEY_END                            17 */
    MsfKey_Clear,       /* KEY_CLEAR                  18 */
    MsfKey_Star,        /* KEY_STAR                   19 */
    MsfKey_Pound,       /* KEY_POUND                  20 */
    MsfKey_Up,          /* KEY_VOL_UP                 21 */
    MsfKey_Down,        /* KEY_VOL_DOWN               22 */
    MsfKey_Select,      /* KEY_QUICK_ACS              23 */
    /* KEY_ENTER can be mapped to MsfKey_Menu instead to create a menu in WAP. */
    MsfKey_Yes,         /* KEY_ENTER                  24 */
    MsfKey_Undefined,   /* KEY_EXTRA_1 */
    MsfKey_Undefined,   /* KEY_EXTRA_2 */
    MsfKey_Undefined,   /* KEY_PLAY_STOP */
    MsfKey_Undefined,   /* KEY_FWD */
    MsfKey_Undefined,   /* KEY_BACK */
    MsfKey_Undefined,   /* KEY_POWER */
    MsfKey_Undefined,   /* KEY_EXTRA_A */
    MsfKey_Undefined,   /* KEY_EXTRA_B */
#ifdef __SENDKEY2_SUPPORT__
    MsfKey_Undefined,   /* KEY_SEND1 */
    MsfKey_Undefined,   /* KEY_SEND2 */
#endif
    MsfKey_Undefined    /* MAX_KEYS */
};

/* Create a MsfEvent */


/*****************************************************************************
 * FUNCTION
 *  create_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keycode     [IN]        
 *  keytype     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MsfEvent create_event(kal_uint16 keycode, kal_uint16 keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfEvent event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(key_map[MAX_KEYS] == MsfKey_Undefined);

    switch (keytype)
    {
        case KEY_EVENT_UP:
            event.eventClass = MsfRelease;
            break;
        case KEY_EVENT_DOWN:
            event.eventClass = MsfPress;
            break;
        case KEY_REPEAT:
            event.eventClass = MsfRepeat;
            break;
    }
    event.eventType = key_map[keycode];

    return event;
}


/*****************************************************************************
 * FUNCTION
 *  widget_key_ind_handler
 * DESCRIPTION
 *  Input event processing core routine
 * PARAMETERS
 *  keycode     [IN]        
 *  keytype     [IN]        
 * RETURNS
 *  whether the key event is accepted as accesskey, user event, or action.
 *****************************************************************************/
kal_bool widget_key_ind_handler(kal_uint16 keycode, kal_uint16 keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen);
    WAP_DBG_ASSERT(WGUI_CTX->widget_root.childs_sum > 0);

    if (!WGUI_CTX->is_widget_screen)
    {
        return KAL_FALSE;
    }
    if (WGUI_CTX->widget_root.childs_sum == 0)
    {
        return KAL_FALSE;
    }

    if (keytype == KEY_EVENT_UP || keytype == KEY_EVENT_DOWN || keytype == KEY_REPEAT)
    {
        MsfEventType key = key_map[keycode];
        widget_header_struct *node;
        widget_window_struct *active_screen = NULL;
        widget_window_struct *active_window = NULL;

        /* widget_window_struct *active_gadget=NULL; */

        /////////////////////////////////////////////////////////////////////////////
        // 1. check the MsfEvent is overriden by Current Screen
        widget_get_active_childs(node, (&WGUI_CTX->widget_root));

        active_screen = _W(node);   /* find the current screen */
        if (active_screen && (active_screen->event_mask & active_screen->event_override & (1 << key)))  /* key was be overriden */
        {
            MsfEvent event = create_event(keycode, keytype);

            HDIc_widgetUserEvent(active_screen->module_id, (MSF_UINT32) active_screen, &event);
            return KAL_TRUE;
        }
        /////////////////////////////////////////////////////////////////////////////
        // 2. check Access Key
        if (active_screen && (active_screen->accesskey & active_screen->accesskey_override & (1 << key)))
        {
            WGUI_CTX->is_access_key_trigger = KAL_TRUE;
            HDIc_widgetAccessKey(
                active_screen->module_id,
                (MSF_UINT32) active_screen,
                widget_lookup_accesskey((MSF_UINT32) active_screen, (kal_uint16) key));
            return KAL_TRUE;
        }

        /////////////////////////////////////////////////////////////////////////////
        // 3. check the MsfEvent is overriden by Current Window
        if (active_screen)
        {
            widget_get_active_childs(node, active_screen);
            active_window = _W(node);   /* find the current Window */
            if (active_window && (active_window->event_mask & active_window->event_override & (1 << key)))      /* key was be overriden */
            {
                MsfEvent event = create_event(keycode, keytype);

                HDIc_widgetUserEvent(active_window->module_id, (MSF_UINT32) active_window, &event);
                return KAL_TRUE;
            }
        }
        /////////////////////////////////////////////////////////////////////////////
        // 4. check Access Key
        if (active_window && (active_window->accesskey & active_window->accesskey_override & (1 << key)))
        {
            WGUI_CTX->is_access_key_trigger = KAL_TRUE;
            HDIc_widgetAccessKey(
                active_window->module_id,
                (MSF_UINT32) active_window,
                widget_lookup_accesskey((MSF_UINT32) active_window, (kal_uint16) key));
            return KAL_TRUE;
        }

        /////////////////////////////////////////////////////////////////////////
        // 5. check the active gadget
        if (active_window)
        {
            widget_get_active_childs(node, active_window);
            /* active_gadget = _W(node);// find the current gadget */

            // 5.1 Change of parent MsfWindow focus & MsfWindow notification activated.
            //hjf our target didn't have pointer device, so the focus should not be changed by user.

            /* 5.2 State change of MsfGadget & MsfGadget state notification activated. */

            /* 5.3 event key mapped to user event. */
            foreach_childs(active_window, node,
                           {
                           if (!IS_FLAG_STATIC(node) && IS_GADGET_TYPE(node) && ((_W(node)->event_mask) & (1 << key)))  /* is the key be handled */
                           {
                           MsfEvent event = create_event(keycode, keytype);
                           HDIc_widgetUserEvent(node->module_id, (MSF_UINT32) node, &event); return KAL_TRUE;}
                           }
            );

            /* 5.4 Access key mapped to user event. */
            foreach_childs(active_window, node,
                           {
                           if (!IS_FLAG_STATIC(node) && IS_GADGET_TYPE(node) && (_W(node)->accesskey) & (1 << key))     /* is the key be handled */
                           {
                           WGUI_CTX->is_access_key_trigger = KAL_TRUE;
                           HDIc_widgetAccessKey(node->module_id,
                                                (MSF_UINT32) node,
                                                widget_lookup_accesskey((MSF_UINT32) node, (kal_uint16) key));
                           return KAL_TRUE;}
                           }
            );
        }
        /////////////////////////////////////////////////////////////////////////
        // 6. check the active window
        // 6.1 Change of MsfWindow focus & MsfWindow notification activated.
        //hjf our target didn't have pointer device, so the focus should not be changed by user.

        /* 6.2 Access key mapped to user event. */
        if (active_window && (active_window->accesskey & (1 << key)))
        {
            WGUI_CTX->is_access_key_trigger = KAL_TRUE;
            HDIc_widgetAccessKey(
                active_window->module_id,
                (MSF_UINT32) active_window,
                widget_lookup_accesskey((MSF_UINT32) active_window, (kal_uint16) key));
            return KAL_TRUE;
        }

        /* 6.3 MsfAction mapped to user event. */
        if (keytype == KEY_EVENT_UP && active_window)   /* action only need to process keyup */
            if (widget_fire_action(active_window, key))
            {
                return KAL_TRUE;
            }

        /* 6.4 handle the MsfEvent */
        if (keytype == KEY_EVENT_UP)
            if (active_window && (active_window->event_mask & (1 << key)))      /* is the key be handled */
            {
                MsfEvent event, event2;

                if (key == MsfKey_Yes && WGUI_CTX->in_paintbox)
                {
                    if (WGUI_CTX->disable_yes_key_in_paintbox)
                    {
                        return KAL_TRUE;    /* drop the key */
                    }
                    else
                    {
                        WGUI_CTX->disable_yes_key_in_paintbox = 1;      /* prevent sending duplicated MsfEvent */
                    }
                }

                event = create_event(keycode, KEY_EVENT_DOWN);
                HDIc_widgetUserEvent(active_window->module_id, (MSF_UINT32) active_window, &event);
                event2 = create_event(keycode, KEY_EVENT_UP);
                HDIc_widgetUserEvent(active_window->module_id, (MSF_UINT32) active_window, &event2);

                return KAL_TRUE;
            }
        /////////////////////////////////////////////////////////////////////////
        // 7. check the active screen
        // 7.1 check the access key
        if (active_screen && (active_screen->accesskey & (1 << key)))
        {
            WGUI_CTX->is_access_key_trigger = KAL_TRUE;
            HDIc_widgetAccessKey(
                active_screen->module_id,
                (MSF_UINT32) active_screen,
                widget_lookup_accesskey((MSF_UINT32) active_screen, (kal_uint16) key));
            return KAL_TRUE;
        }

        /* 7.2 MsfAction key mapped to user event. */
        if (keytype == KEY_EVENT_UP && active_screen)   /* action only need to process keyup */
            if (widget_fire_action(active_screen, key))
            {
                return KAL_TRUE;
            }

        /* 7.3 MsfEvent is handled by the MsfScreen */
        if (keytype == KEY_EVENT_UP)
            if (active_screen && (active_screen->event_mask & (1 << key)))
            {
                MsfEvent event = create_event(keycode, keytype);

                HDIc_widgetUserEvent(active_screen->module_id, (MSF_UINT32) active_screen, &event);
                return KAL_TRUE;
            }


        /* 8. Handle KEY_ENTER (center key) to emulate LSK. */
        /* If KEY_ENTER is mapped to MsfKey_Yes or MsfKey_Menu and it is already registered, 
         * If current window is MsfMenu and doesn't paint, we don't convert the KEY_ENTER to MsfKey_Soft1.
         * This function will return before this line and the following code will not be executed 
         */
        if (WGUI_CTX->current_window &&
            (!IS_MENU_TYPE(WGUI_CTX->current_window) ||
             (IS_MENU_TYPE(WGUI_CTX->current_window) && WGUI_CTX->is_painted_after_first_focus_changed)))
        {
            if (keytype == KEY_EVENT_UP && keycode == KEY_ENTER && active_window)
                if (widget_fire_action(active_window, MsfKey_Soft1))
                {
                    return KAL_TRUE;
                }

            if (keytype == KEY_EVENT_UP && keycode == KEY_ENTER && active_screen)
                if (widget_fire_action(active_screen, MsfKey_Soft1))
                {
                    return KAL_TRUE;
                }
        }

    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_send_update_event_to_wap
 * DESCRIPTION
 *  If we insert WAP internal queue (e.g. HDIc_widgetAction), we need to put at least one
 *  primitive in WAP external queue such that WAP will process internal queue later.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_send_update_event_to_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WIPC_CTX->update_event_is_sent)
    {
        ilm_struct *ilm_ptr = NULL;

        WIPC_CTX->update_event_is_sent = 1;
        /* First allocate a memory for an interlayer message structure */
        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->msg_id = MSG_ID_WAP_STATUS_UPDATE_IND; /* Set the message id */
        ilm_ptr->peer_buff_ptr = NULL;                  /* there are no peer message */
        ilm_ptr->local_para_ptr = NULL;                 /* there are no local message */
        SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }
}

#ifdef WPS_TASK_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  widget_send_update_event_to_wps
 * DESCRIPTION
 *  If we insert WPS internal queue (e.g. HDIc_socketConnect), we need to put at least one
 *  primitive in WPS external queue such that WPS will process internal queue later.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_send_update_event_to_wps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        ilm_struct *ilm_ptr = NULL;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        /* First allocate a memory for an interlayer message structure */
        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->msg_id = MSG_ID_WAP_STATUS_UPDATE_IND; /* Set the message id */
        ilm_ptr->peer_buff_ptr = NULL;                  /* there are no peer message */
        ilm_ptr->local_para_ptr = NULL;                 /* there are no local message */
        SEND_ILM(MOD_WAP, MOD_WPS, WPS_APP_SAP, ilm_ptr);
    }
}

#endif /* WPS_TASK_SUPPORT */ 


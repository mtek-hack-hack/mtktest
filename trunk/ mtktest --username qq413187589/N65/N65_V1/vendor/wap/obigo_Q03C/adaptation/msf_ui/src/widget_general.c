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
 * widget_general.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Basic widget manipulation 
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
#include "wgui.h"
#include "wgui_categories.h"
#include "wgui_categories_util.h"
#include "wgui_status_icons.h"
#include "simDetectionDef.h"

/* 
 * About the current memory management of WAP widget
 * 1. HDIa_memAlloc and HDIa_memFree must be paired with the same module ID; otherwise it
 * might produce memory corruption with Obigo's memory allocator.
 *
 * 2. In widget_malloc_mem & widget_free_mem, we always use the owner module to allocate its memory
 *
 * 3. Sometimes we use MSF_MODID_WIDGET to allocate data like drawing operations. Because 
 *  MSF_MEM_FREE_ALL(MSF_MODID_WIDGET) is always executed after MSF_MODID_WIDGET_RELEASE_ALL
 *  on other modules, it is safe from releasing memory of a widget object before MSF_WIDGET_RELEASE it.
 *
 *(FIXED issue of MSF_WIDGET_RELEASE_ALL on 2004.04.13 w04.13 
 * widget_malloc always use HDIa_getModuleID() to insert a block into widget free list.
 * If MEA calls a BRA function to allocate a string, the string will be inserted into MEA's widget free list
 * If we HDIa_widgetReleaseAll(MSF_MODID_MEA) before terminating BRA UI, the string will be released twice.)
 */

/****************************************************************
  Widget General
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDeviceGetProperties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  theDeviceProperties     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDeviceGetProperties(MsfDeviceProperties *theDeviceProperties)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    theDeviceProperties->displaySize.width = WGUI_CTX->display_size.width;
    theDeviceProperties->displaySize.height = WGUI_CTX->display_size.height;

    theDeviceProperties->isTouchScreen = WIDGET_HAVE_TOUCH_SCREEN;
    theDeviceProperties->hasDragAbility = WIDGET_HAVE_DRAG_ABILITY;
    theDeviceProperties->isColorDisplay = (DEVICE_COLOR_DEPTH != 1);
    theDeviceProperties->numberOfColors = 2 << DEVICE_COLOR_DEPTH;
    theDeviceProperties->supportedMsfEvents = 0xffffffff;   /* default support all event */

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_disable_multi_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_disable_multi_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reference: UI_common_screen_exit() */

    /* For cache of GUI menu background image */
    gui_free_multilayer_screen();
    gui_set_entry_new_screen(MMI_TRUE);

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    wgui_reset_wallpaper_on_bottom();
#endif 

    /* For menu background image cache */
#ifdef WIDGET_PRECACHE_IMAGE
    widget_MMI_free_precached_image_if_any();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_on_window_focus_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_on_window_focus_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->is_widget_screen)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        widget_MMI_reset_pen_on_screen_switch();
    #endif 
        HDIa_widgetExtCloseVideo();
        gui_cleanup();

        widget_disable_multi_layer();

        widget_enable_clear_all_handler();
        widget_clear_all_handler();

    #if defined (WIDGET_RESIDENT_STATUS_ICON) && defined (__MMI_WALLPAPER_ON_BOTTOM__)
    
        {
            /*
             * Here is very tricky. 
             * The widget handles status icon bars by itself (WAP task controls), 
             * but sometimes MMI task will updates at the same time. (ex. have blinking icons).
             * It causes the background of the status bar is white color not the wallpaper image.
             * We will hide status icon when the window changed focus and draw the status bar in widget_paint.
             */
            hide_status_icon_bar(0);
        }
    #endif /* WIDGET_RESIDENT_STATUS_ICON && __MMI_WALLPAPER_ON_BOTTOM__ */ 

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_integrated_enable(MMI_FALSE);
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_on_window_focus_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_on_window_focus_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ON_WINDOW_FOCUS_CHANGED);

    if (WGUI_CTX->is_widget_screen)
    {
        widget_close_status_icons_if_present();
    #ifdef WIDGET_RESIDENT_STATUS_ICON
        if (WGUI_CTX->dialog_with_hatch_background)
        {
            reset_title_status_icon();
            WGUI_CTX->dialog_with_hatch_background = 0;
        }
    #endif /* WIDGET_RESIDENT_STATUS_ICON */ 

        widget_restore_menu_background_if_required();

        /*
         * For example, the user might stay in menu *after*  it is switched to another MsfWindow (e.g. SMIL player) and 
         * * before widget_paint_hdlr() is executed. If we do not clear all keys, it might invoke gui_show_list_menu
         * * by pressing KeyUp/KeyDown, which allocates GDI layer again.
         */
        ClearAllKeyHandler();
        widget_init_key_queue();    /* flush key queue */

        if (WIPC_CTX->MMI_is_waiting)
        {
            /* MMI is blocking wait. */
            WAP_DBG_ASSERT(0);
            widget_MMI_on_window_focus_changed();
        }
        else
        {
            widget_execute_MMI(widget_MMI_on_window_focus_changed, KAL_TRUE);
        }

        /* NOTE: WGUI_CTX->is_widget_screen might be FALSE at this point after RPC request! */
    }

    WAP_DBG_ASSERT(!widget_is_sound_playing()); /* Non-fatal, but sound playing should be stopped before switching MsfWindow */
    widget_ctk_leave_screen_if_present(NULL, -1);
    widget_stop_all_paint_command();
    widget_stop_all_blinking();
    widget_stop_all_marquee();

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_stop_all_image_nb_draw();
#endif
    widget_init_fullscreen_menu();              /* Tricky. The parent of ChoiceMenu (fullscreen menu) must be focused to provide MsfActions. */

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ON_WINDOW_FOCUS_CHANGED_END);

    // TODO: stop animation
    // TODO: WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_window_gadget_displayed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_is_window_gadget_displayed(MSF_UINT32 msfHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msfHandle == 0)
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    if (IS_GADGET_TYPE(msfHandle))
    {
        h = _H(msfHandle)->parent;
    }
    else if (IS_WINDOW_TYPE(msfHandle))
    {
        h = _H(msfHandle);
    }
    else
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    if (h == NULL)
    {
        return KAL_FALSE;
    }

    if (h == (widget_header_struct*) WGUI_CTX->current_window)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_current_window_type
 * DESCRIPTION
 *  Is the current "focused" MsfWindow (not necessarily displayed) in this type?
 * PARAMETERS
 *  type        [IN]        Widget type
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_is_current_window_type(widget_data_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We do not use WGUI_CTX->current_window because WGUI_CTX->current_window is displayed */
    widget_header_struct *screen, *window;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_get_active_childs(screen, &WGUI_CTX->widget_root);
    if (!screen)
    {
        return KAL_FALSE;
    }
    widget_get_active_childs(window, screen);
    if (!window)
    {
        return KAL_FALSE;
    }
    return IS_DATA_TYPE(window, type) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_current_focused_window
 * DESCRIPTION
 *  Get the current focused window
 *  
 *  NOTE: WGUI_CTX->current_window is current "painted" window, and it might be NULL
 *  even if some MsfWindow is focused.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
widget_window_struct *widget_get_current_focused_window(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *screen, *window;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_get_active_childs(screen, &WGUI_CTX->widget_root);
    if (!screen)
    {
        return NULL;
    }
    widget_get_active_childs(window, screen);
    if (!window)
    {
        return NULL;
    }
    return _W(window);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetInFocus
 * DESCRIPTION
 *  
 *  
 *  In integration manual: all widgets involved that have the notification functionality enabled
 *  must be notified of the focus change
 *  
 *  However, in some cases (e.g. Send MsfNotifyFocus to another gadget when removing an text input gadget)
 *  BRS might think that use pointer device to click on another gadget.. and it might enter infinite loop.
 *  
 *  If paintbox window is in focus, we should prepare a clear screen
 *  for paintbox use. (this cannot be moved to widget_paint
 *  because BRS use low-level API to draw on the paintbox,
 *  where widget_paint only draw buttons, outside-look, ...
 * PARAMETERS
 *  handle      [IN]        
 *  focus       [IN]        (Hack: not to send notification)
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetInFocus(MSF_UINT32 handle, int focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *p;
    widget_header_struct *a;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle)
    {
        return 0;
    }

    p = _H(handle)->parent;
    if (!p)
    {
        return 0;
    }

    widget_get_active_childs(a, p);
    ///////////////////////////////////////////////////////////
    // get focus
    if (focus == 1)
    {
        if (a != _H(handle))
        {
            if (!IS_GADGET_TYPE(handle))    /* Any screen or window */
            {
                WGUI_CTX->is_painted_after_first_focus_changed = 0;
                widget_on_window_focus_changed();
            }

            widget_set_active_childs(p, _H(handle));

            /*
             * In paintbox, MsfNotifyFocus and MsfNotifyLostFocus usually represents a mouse event. 
             * * It might cause unexpected side effects.
             */
            if (a != NULL)
            {
                if (!IS_PAINTBOX_TYPE(p))
                {
                    widget_notify(_H(a), MsfNotifyLostFocus);
                }
    
                if (IS_FORM_TYPE(a))
                {
                    widget_form_on_defocused(_H(a));
                }
            }

            // TODO: If we set focus to another "screen", should we set MsfNotifyLostFocus to the old "window"?

            if (IS_SCREEN_TYPE(handle))
            {
                widget_header_struct *child;

                widget_get_active_childs(child, handle);

                if (child)
                {
                    kal_bool clear_screen_flag = KAL_TRUE;

                    if ((_H(a)->module_id == MSF_MODID_MEA && _H(handle)->module_id == MSF_MODID_SMA) || 
                        (_H(a)->module_id == MSF_MODID_SMA && _H(handle)->module_id == MSF_MODID_MEA))
                    {
                        /* If changing force in MEA and SMA MsfScreen, we don't want to clear screen */
                        clear_screen_flag = KAL_FALSE;
                    }
                    if (clear_screen_flag)
                    {
						if (!WGUI_CTX->current_window && IS_DIALOG_TYPE(child))
						{
                           /*
                            * If show MSfWindow in widget screen and it is MsfDialog,
                            * we will clear all screen
                            */
							clear_screen();
						}
						else
						{
							/* If change screen, we should clear screen first. */
							widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);
						}
                    }

                    HDIa_widgetSetInFocus((MSF_UINT32) child, 1);
                }
            }
        }

        /* If we send notification here. It might enter infinite loop in BRS */
        /* widget_notify(_H(handle),MsfNotifyFocus); */

        /* Tell BRS to update paintbox content */
        if (IS_PAINTBOX_TYPE(handle))
        {
            widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);
            widget_notify(_H(handle), MsfNotifyStateChange);
        }
        else if (IS_FORM_TYPE(handle))
        {
            widget_form_on_focused(_H(handle));
        }

        widget_send_update_event_to_wap();

        widget_set_current_object(_H(handle));
        widget_set_current_focus(_H(handle), KAL_TRUE);

        widget_paint();
    }
    /////////////////////////////////////////////////////////
    // lose focus
    else    /* focus == 0 || focus == -1 */
    {
        // TODO: Defocusing a gadget and a window/screen is different
        if (a == _H(handle))    /* handle is the active child */
        {
            if (!IS_GADGET_TYPE(handle))    /* Any screen or window */
            {
                WGUI_CTX->is_painted_after_first_focus_changed = 0;
                widget_on_window_focus_changed();
            }
            // It might cause problems
            //                      widget_notify(_H(handle),MsfNotifyLostFocus);

            if (IS_FORM_TYPE(handle))
            {
                widget_form_on_defocused(_H(handle));
            }

            widget_get_next_active_childs(a, p);
            if (a != NULL)  /* Focus to next node */
            {
                widget_hide_active_childs(p, handle);

                if (focus != -1)    /* Maybe we should always send notification */
                {
                    /*
                     * In paintbox, MsfNotifyFocus and MsfNotifyLostFocus usually represents a mouse event. 
                     * * It might cause unexpected side effects.
                     */
                    if (!IS_PAINTBOX_TYPE(p))
                    {
                        widget_notify(_H(a), MsfNotifyFocus);
                    }
                }

                /* e.g. A SEC screen disappear, BRS screen is focused, the paintbox should also be focused */
                if (IS_SCREEN_TYPE(a))
                {
                    widget_header_struct *child;

                    widget_get_active_childs(child, a);

                    if (child)
                    {
                        kal_bool clear_screen_flag = KAL_TRUE;

                        if ((_H(a)->module_id == MSF_MODID_MEA && _H(handle)->module_id == MSF_MODID_SMA) || 
                            (_H(a)->module_id == MSF_MODID_SMA && _H(handle)->module_id == MSF_MODID_MEA))
                        {
                            /* If changing force in MEA and SMA MsfScreen, we don't want to clear screen */
                            clear_screen_flag = KAL_FALSE;
                        }
                        if (clear_screen_flag)
                        {
                            /* If change screen, we should clear screen first. */
                            widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);
                        }

                        HDIa_widgetSetInFocus((MSF_UINT32) child, 1);
                    }
                }
                else if (IS_FORM_TYPE(a))   /* For example. Remove another window and the focus is changed to a form */
                {
                    widget_form_on_focused(_H(a));
                }
                else if (IS_PAINTBOX_TYPE(a))
                {
                    // if paintbox window is in focus, we should prepare a clear screen
                    // for paintbox use.
                    widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);

                    /* let BRS to update paintbox content */
                    widget_notify(_H(a), MsfNotifyStateChange);
                }

                widget_set_current_object(_H(a));

            }

            widget_send_update_event_to_wap();
            widget_paint();
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetHasFocus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetHasFocus(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *node;
    widget_header_struct *w = _H(handle);
    widget_header_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (w && w->parent)
    {
        p = w->parent;
        widget_get_active_childs(node, p);
        if (node != w)
        {
            return 0;
        }
        if (IS_SCREEN_TYPE(node))
        {
            return 1;
        }

        w = p;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetRelease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetRelease(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle)
    {
        return 0;
    }
    if (IS_FLAG_STATIC(handle))
    {
        return 0;
    }

    if (IS_ACCESSKEY_TYPE(handle))
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    /*
     * Prevent HDIa_widgetRelease the same widgets for more than one time
     * (Teleca code might HDIa_widgetRelease the same widget twice.)
     *
     * Note: this only reduce the chance of memory corruption, but not eliminate it.
     * It is possible to allocate another widget at the same memory address, which is HDIa_widgetRelease()-ed
     * for the previous widget.
     *
     */
    if (_H(handle)->data_type == WIDGET_MAX_TYPE)
    {
        WAP_DBG_ASSERT(0);
        return 1;
    }

    /* a screen and window only have one parent */
    if (IS_SCREEN_TYPE(handle) || IS_WINDOW_TYPE(handle))
    {
        NO_REF(handle);
    }
    DEC_REF(handle);
    if (HAS_REF(handle))
    {
        return 1;
    }

    widget_pause_paint();

    // TODO: should we do this in widget_free?
    foreach_childs(handle, node,
                   {
                   if (!IS_FLAG_STATIC(node)) widget_remove_childs(_H(handle), node);}
    );

    widget_free(_H(handle));

    widget_resume_paint();

    /*
     * Sometimes the window is released first, and the child gadgets 
     * * are released later. We should not call widget_prepare_to_leave_screen
     * * when releasing a gadget
     * * FIXME. move to HDIa_widgetRemove
     */
    if (IS_SCREEN_TYPE(handle) || IS_WINDOW_TYPE(handle))
    {
        if (widget_ready_to_leave_screen())
        {
            widget_prepare_to_leave_screen();
        }
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetReleaseAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetReleaseAll(MSF_UINT8 modId)
{
#ifdef WPS_TASK_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * With WPS support, STK module belongs to WPS task, but we should not use
     * * widget data structure in WPS task.
     * * We patched STK module such that it does not use any widget functions.
     */
    if (modId == MSF_MODID_STK)
    {
        WAP_DBG_ASSERT(WSYS_CTX->free_obj_list[MSF_MODID_STK] == NULL);
        return 1;
    }
#endif /* WPS_TASK_SUPPORT */ 

    widget_pause_paint();

    /* WAP does not always HDIa_widgetRemove before invoking  HDIa_widgetReleaseAll */
    widget_ctk_leave_screen_if_present(NULL, modId);

    widget_release_all(modId);

    widget_resume_paint();

    if (widget_ready_to_leave_screen())
    {
        widget_prepare_to_leave_screen();
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCopy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT32 HDIa_widgetCopy(MSF_UINT8 modId, MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_STRING_TYPE(handle) || IS_PRE_STRING_TYPE(handle))
    {
        MsfStringHandle str = widget_copy_string(modId, (MsfStringHandle) handle);

        return str;
    }
    else
    {
        WAP_RST_ASSERT(0);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetRemove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle                  [IN]        
 *  handleToBeRemoved       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetRemove(MSF_UINT32 handle, MSF_UINT32 handleToBeRemoved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = -1;
    int cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle || !handleToBeRemoved)
    {
        /* WAP_DBG_ASSERT(0); // Happened in exitSmilPlayer() */
        return -1;
    }
    WAP_DBG_ASSERT(widget_check_object_validity(_H(handle)) && widget_check_object_validity(_H(handleToBeRemoved)));

    if (IS_FLAG_STATIC(handleToBeRemoved))
    {
        return -1;
    }

    widget_pause_paint();

    if (IS_SCREEN_TYPE(handleToBeRemoved))
    {
        handle = (MSF_UINT32) & WGUI_CTX->widget_root;
    }
    if (_H(handle) == _H(WGUI_CTX->current_window) &&
        (IS_GADGET_INPUT_TYPE(handleToBeRemoved) | IS_MENU_TYPE(handleToBeRemoved)))
    {
        /* When the paintbox content is changed by network, there might be no keypad event or window focus change  */
        widget_clear_animator_on_key_accepted();
    }

#ifdef __MMI_TOUCH_SCREEN__
    widget_MMI_remove_pen_handler_if_necessary(_H(handleToBeRemoved));
#endif 
    widget_ctk_leave_screen_if_present(_H(handleToBeRemoved), -1);

    /* Check existence and remove it */
    widget_index_childs(cnt, _H(handle), _H(handleToBeRemoved));
    if (cnt != -1)
    {
        /*
         * The parameter -1 tell HDIa_widgetSetInFocus not to send MsfNotifyLostFocus notification 
         * * because BRS will enter an infinite loop when it remove an input gadget.
         */
        HDIa_widgetSetInFocus((MSF_UINT32) handleToBeRemoved, -1);
        /* Index is not 'cnt' here */
        widget_remove_childs(_H(handle), _H(handleToBeRemoved));
        result = 1;
    }

    if (IS_GADGET_BAR_TYPE(handleToBeRemoved))
    {
        widget_gadget_bar_struct *w;
        w = (widget_gadget_bar_struct *)handleToBeRemoved;
        if (w->bar_type == MsfHorizontalScrollBar)
        {
            WGUI_CTX->current_horizontal_scrollbar = NULL;
        }
    }

    WAP_DBG_ASSERT(result);

    if (IS_FORM_TYPE(handle))
    {
        widget_form_on_gadget_removed(_H(handle), _H(handleToBeRemoved));
    }

    /* Upate action mask */
    if (IS_ACTION_TYPE(handleToBeRemoved))
    {
        widget_update_action_total_mask(_W(handle));
    }

    widget_resume_paint();
    widget_paint();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetTitle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  title       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetTitle(MSF_UINT32 handle, MsfStringHandle title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStringHandle copystr;    /* if handle and title belongs to different task */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!title)
    {
        copystr = 0;
    }
    if (title && IS_FLAG_STATIC(title))
    {
        copystr = title;
    }
    else
    {
        copystr = widget_copy_string(_H(handle)->module_id, title);
    }

    if (_H(handle)->flag & WIDGET_FLAG_WINDOW)
    {
        widget_set_attrib(_W(handle), title, copystr);
        if (copystr && !IS_FLAG_STATIC(copystr))
        {
            DEC_REF(copystr);
        }
        if (!IS_GADGET_TYPE(handle))
        {
            widget_paint();
        }
    }
    else if (IS_ACTION_TYPE(handle))
    {
        widget_set_attrib(_ACTION(handle), text, copystr);
        if (copystr && !IS_FLAG_STATIC(copystr))
        {
            DEC_REF(copystr);
        }
    }
    else
    {
        /* Unsupported type */
        WAP_DBG_ASSERT(0);
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetBorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  borderStyle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetBorder(MSF_UINT32 handle, MsfLineStyle borderStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(0);

#ifndef WIDGET_COMPACT_RUNTIME_STRUCT

    if (_H(handle)->flag & WIDGET_FLAG_WINDOW)
    {
        _W(handle)->border_style = borderStyle;
    }

#endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  position        [IN]         
 *  alignment       [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetPosition(MSF_UINT32 handle, MsfPosition *position, MsfAlignment *alignment)
{
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_GADGET_IMAGE_TYPE(handle) && _GIMG(handle)->parent &&
        IS_FORM_TYPE(_GIMG(handle)->parent) && _FORM(_GIMG(handle)->parent)->sliding_info)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SET_POSITION);
        return 1;
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

    if (_H(handle)->flag & WIDGET_FLAG_WINDOW)
    {
        if (position)
        {
            _W(handle)->position = *position;
        }
    #ifndef WIDGET_COMPACT_RUNTIME_STRUCT
        if (alignment)
        {
            _W(handle)->alignment = *alignment;
        }
    #endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  size        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetSize(MSF_UINT32 handle, MsfSize *size)
{
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_GADGET_IMAGE_TYPE(handle) && _GIMG(handle)->parent &&
        IS_FORM_TYPE(_GIMG(handle)->parent) && _FORM(_GIMG(handle)->parent)->sliding_info)
    {
        /* It is possible to happen, and we block this operation */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SET_SIZE);
        return 1;
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

    if (IS_WINDOW_TYPE(handle))
    {
        _W(handle)->size = *size;
    }
    else if (IS_GADGET_TYPE(handle))
    {
        /* gui multiline inputbox will handle the situation when the width is too small */
        _W(handle)->size = *size;
    }
    else if (IS_IMAGE_TYPE(handle))
    {
        /*
         * By BRS marquee. We cannot handle this because we always get the actual 
         * * dimension from the image itself.
         */
        // WAP_DBG_ASSERT(0);
        // _IMG(handle)->size = *size;
    }
    else
    {
        WAP_DBG_ASSERT(0);
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  position        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetPosition(MSF_UINT32 handle, MsfPosition *position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *position = _W(handle)->position;
    return 1;
}

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

///////////////////////////////////////////////////////////
// Widget Extension
///////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtPaintboxInputFocus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtPaintboxInputFocus(MsfGadgetHandle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->selected_input_in_paintbox = handle;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtImageUtilFixBBox
 * DESCRIPTION
 *  play animation for certain frame by image ptr
 * PARAMETERS
 *  mode            [IN]        
 *  bbox_width      [IN]        
 *  bbox_height     [IN]        
 *  src_width       [IN]        
 *  src_height      [IN]        
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  dest_width      [IN]        
 *  dest_height     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtImageUtilFixBox(
        kal_int32 bbox_width,
        kal_int32 bbox_height,
        kal_int32 src_width,
        kal_int32 src_height,
        kal_int32 *offset_x,
        kal_int32 *offset_y,
        kal_int32 *dest_width,
        kal_int32 *dest_height)
{
    gdi_image_util_fit_bbox(
        bbox_width,
        bbox_height,
        src_width,
        src_height,
        offset_x,
        offset_y,
        dest_width,
        dest_height);
}





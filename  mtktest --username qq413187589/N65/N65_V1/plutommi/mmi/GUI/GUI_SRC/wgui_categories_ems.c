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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * wgui_categories_ems.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for EMS category screens.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* start - added by magesh */
#define ENABLE_EMS_TEST_SAVE_OBJECTS         1  /* 0- enable, 1-disable */
#define ENABLE_EMS_TEST_SAVE_PIC_OBJECTS     0  /* 1- enable, 0-disable */
#define ENABLE_EMS_TEST_SAVE_ANIA_OBJECTS    1  /* 1- enable, 0-disable */
#define ENABLE_EMS_TEST_SAVE_MELO_OBJECTS    0  /* 1- enable, 0-disable */
/* end - added by magesh */

#include "MMIDataType.h"
#include "MMI_features.h"

#include "TimerEvents.h"
#include "kal_release.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "conversions.h"

#include "HistoryGprot.h"
#include "DebugInitDef.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_defs.h"
#include "gdi_include.h"
#include "wgui_ems.h"
#include "wgui_categories_ems.h"
#include "wgui_touch_screen.h"
#include "MessagesResourceData.h"
#include "PhoneSetupGprots.h"
#if (defined(__MMI_FILE_MANAGER__))
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
#include "wgui_draw_manager.h"
#include "wgui_status_icons.h"
#include "EmsMiscell.h"

/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
/*PMT IRE END*/
#endif 
//#include "wgui_virtual_keyboard.h"
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
//#include "EditorPen.h"
#endif 

#ifdef __MMI_MESSAGES_EMS__
#include "ScrMemMgrGprot.h"

extern void initialize_EMS_objects(void);
extern void close_EMS_objects(void);

extern U8 *EMS_predefined_pictures[];
extern U8 *EMS_predefined_melodies[];

EMSObjData temp_EMS_obj_data;
#ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
small_image_selector_struct small_image_selector;
#endif 


/*****************************************************************************
 * FUNCTION
 *  CreateCategory143ObjectList
 * DESCRIPTION
 *  create 143 object list
 * PARAMETERS
 *  data            [IN]         data of objects
 *  object_list     [OUT]        list of objects
 * RETURNS
 *  void
 *****************************************************************************/
void CreateCategory143ObjectList(EMSData *data, EMSObject **object_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *p = data->listHead;
    EMSObject *q;
#if(ENABLE_EMS_TEST_SAVE_OBJECTS)
    S32 type;
#endif /* (ENABLE_EMS_TEST_SAVE_OBJECTS) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *object_list = q = NULL;
#if(ENABLE_EMS_TEST_SAVE_OBJECTS)
    if (data == NULL)
    {
        return;
    }
    if (data->listHead == NULL)
    {
        return;
    }
    while (p != NULL)
    {
        type = p->Type;
        /* reused object will not be put in category_143_object_list */
        if (
    #ifdef __EMS_REL5__
               (!EMSIsReusedObj(data, p)) &&
    #endif 
               ((type == EMS_TYPE_PIC) || (type == EMS_TYPE_USERDEF_ANM)
    #if defined(__MMI_IMELODY_SUPPORT__)
                || (type == EMS_TYPE_USERDEF_SND)
    #endif 
               ))
        {
            if (q == NULL)
            {
                *object_list = q = (EMSObject*) gui_malloc(sizeof(EMSObject));
                q->next = NULL;
                q->prev = NULL;
                q->data = p->data;
                q->OffsetToText = p->OffsetToText;
                q->PredefNo = p->PredefNo;
                q->Type = p->Type;
            }
            else
            {
                EMSObject *temp;

                temp = (EMSObject*) gui_malloc(sizeof(EMSObject));
                temp->next = NULL;
                temp->data = p->data;
                temp->OffsetToText = p->OffsetToText;
                temp->PredefNo = p->PredefNo;
                temp->Type = p->Type;
                temp->prev = q;
                q->next = temp;
                q = temp;
            }
        }
        p = p->next;
    }
#else /* (ENABLE_EMS_TEST_SAVE_OBJECTS) */ 
#if(ENABLE_EMS_TEST_SAVE_PIC_OBJECTS)   /* picture */
    temp_EMS_obj_data.picture.bitsPerPixel = 1;
    temp_EMS_obj_data.picture.hDim = 16;
    temp_EMS_obj_data.picture.vDim = 16;
    temp_EMS_obj_data.picture.pdu_length = 32;
    temp_EMS_obj_data.picture.pdu = (U8*) (EMS_sample_picture_object_PDU_11 + 8);
    *object_list = q = (EMSObject*) gui_malloc(sizeof(EMSObject));
    q->next = NULL;
    q->prev = NULL;
    q->data = &temp_EMS_obj_data;
    q->OffsetToText = 0;
    q->PredefNo = 0;
    q->Type = EMS_TYPE_PIC;
#endif /* (ENABLE_EMS_TEST_SAVE_PIC_OBJECTS) */ 
#if(ENABLE_EMS_TEST_SAVE_ANIA_OBJECTS)  /* animation */
    temp_EMS_obj_data.animation.bitsPerPixel = 1;
    temp_EMS_obj_data.animation.hDim = 8;
    temp_EMS_obj_data.animation.vDim = 8;
    temp_EMS_obj_data.animation.pdu_length = 32;
    temp_EMS_obj_data.animation.pdu = (U8*) (EMS_sample_animation_object_PDU_11 + 8);
    *object_list = q = (EMSObject*) gui_malloc(sizeof(EMSObject));
    q->next = NULL;
    q->prev = NULL;
    q->data = &temp_EMS_obj_data;
    q->OffsetToText = 0;
    q->PredefNo = 0;
    q->Type = EMS_TYPE_USERDEF_ANM;
#endif /* (ENABLE_EMS_TEST_SAVE_ANIA_OBJECTS) */ 
#if(ENABLE_EMS_TEST_SAVE_MELO_OBJECTS)  /* melodies */
    /* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
    temp_EMS_obj_data.sound.pdu_length =
        (U16) (EMS_sample_melody_object_PDU_1[1] | (EMS_sample_melody_object_PDU_1[2] << 8));
    temp_EMS_obj_data.sound.pdu = (U8*) (EMS_sample_melody_object_PDU_1 + 3);
    *object_list = q = (EMSObject*) gui_malloc(sizeof(EMSObject));
    q->next = NULL;
    q->prev = NULL;
    q->data = &temp_EMS_obj_data;
    q->OffsetToText = 0;
    q->PredefNo = 0;
    q->Type = EMS_TYPE_USERDEF_SND;
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    /* MTK end */
#endif /* (ENABLE_EMS_TEST_SAVE_MELO_OBJECTS) */ 
#endif /* (ENABLE_EMS_TEST_SAVE_OBJECTS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  FreeCategory143ObjectList
 * DESCRIPTION
 *  free object list of category 143
 * PARAMETERS
 *  object_list     [IN]        object list
 * RETURNS
 *  void
 *****************************************************************************/
void FreeCategory143ObjectList(EMSObject **object_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *q, *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object_list == NULL)
    {
        return;
    }
    q = *object_list;
    while (q != NULL)
    {
        temp = q;
        q = q->next;
        gui_free(temp);
    }
    *object_list = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  category_143_redraw_highlighted_item
 * DESCRIPTION
 *  Redraws the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 *category_143_object_list_index = NULL;
S32 category_143_object_list_n_items = 0;
vertical_scrollbar category143_vbar;
EMSObject *category_143_object_list;
EMSObject *category_143_current_object;
extern U8 EMS_view_mode;

void category_143_redraw_highlighted_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    color c;
#if 0
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    gui_reset_clip();
    c = gui_color(255, 255, 255);
#ifdef __MMI_WALLPAPER_ON_BOTTOM__//071007 ems bg
    gdi_draw_solid_rect(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1,
        GDI_COLOR_TRANSPARENT);
#else
    gui_fill_rectangle(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1,
        c);
#endif
    gui_set_clip(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - current_MMI_theme->scrollbar_size,
        MMI_content_height + 2);
    if (category_143_current_object != NULL)
    {
        gui_EMS_input_box_measure_object(category_143_current_object, &w, &h);
        x = (UI_device_width >> 1) - (w >> 1);
        y = (UI_device_height >> 1) - (h >> 1);
        gui_EMS_input_box_display_object(x, y, category_143_current_object, 1);
    }
    /* Uncomment below line for auto-disable scrollbar    */
    if (category_143_object_list_n_items > 1)
    {
        gui_set_vertical_scrollbar_range(&category143_vbar, category_143_object_list_n_items);
        gui_set_vertical_scrollbar_scale(&category143_vbar, 1);
        gui_set_vertical_scrollbar_value(&category143_vbar, *category_143_object_list_index);
        
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
/* under construction !*/
#endif

        if (r2lMMIFlag)
        {
            /* move vertical scrollbar to the left side */
            gui_move_vertical_scrollbar(
                    &category143_vbar, 
                    0, 
                    category143_vbar.y);
        }

        gui_show_vertical_scrollbar(&category143_vbar);
    }
    gui_BLT_double_buffer(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  category_143_highlight_handler
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  index       [IN]        index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void category_143_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_menu_shortcut_number = index + 1;
    if (!menu_shortcut_handler_display)
    {
        draw_title();
    }
    MMI_list_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  category_143_goto_item
 * DESCRIPTION
 *  goto item by index
 * PARAMETERS
 *  index       [IN]        index of item
 * RETURNS
 *  void
 *****************************************************************************/
void category_143_goto_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (category_143_object_list != NULL)
    {
        if (index < 0)
        {
            return; /* index=0; */
        }
        if (index > (category_143_object_list_n_items - 1))
        {
            return; /* index=category_143_image_list_n_items-1;  */
        }
        *category_143_object_list_index = index;
        category_143_current_object = category_143_object_list;
        if (category_143_current_object != NULL)
        {
            S32 i;

            for (i = 0; i < index; i++)
            {
                category_143_current_object = category_143_current_object->next;
            }
        }
    }
    category_143_redraw_highlighted_item();
    category_143_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  category_143_goto_previous_item
 * DESCRIPTION
 *  goto previous item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void category_143_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_143_object_list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index--;
    if (index < 0)
    {
        index = category_143_object_list_n_items - 1;
    }
    *category_143_object_list_index = index;
    if (category_143_current_object != NULL)
    {
        if (category_143_current_object->prev == NULL)
        {
            category_143_current_object = category_143_object_list;
            while (category_143_current_object->next != NULL)
            {
                category_143_current_object = category_143_current_object->next;
            }
        }
        else
        {
            category_143_current_object = category_143_current_object->prev;
        }
    }
    category_143_redraw_highlighted_item();
    category_143_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  category_143_goto_next_item
 * DESCRIPTION
 *  goto next item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void category_143_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_143_object_list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index++;
    if (index > (category_143_object_list_n_items - 1))
    {
        index = 0;
    }
    *category_143_object_list_index = index;
    if (category_143_current_object != NULL)
    {
        if (category_143_current_object->next == NULL)
        {
            category_143_current_object = category_143_object_list;
        }
        else
        {
            category_143_current_object = category_143_current_object->next;
        }
    }
    category_143_redraw_highlighted_item();
    category_143_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  category_143_key_handler
 * DESCRIPTION
 *  category 143 keypad handler
 * PARAMETERS
 *  vkey_code       [IN]       virtual key code 
 *  key_state       [IN]       key state
 * RETURNS
 *  void
 *****************************************************************************/
void category_143_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:    /* left */
                break;
            case 39:    /* right */
                break;
            case 38:
                category_143_goto_previous_item();
                break;
            case 40:
                category_143_goto_next_item();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  category_143_pen_down_hdlr
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  pos     [IN]        pen down position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL category_143_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category143_vbar.x, category143_vbar.y, category143_vbar.width, category143_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category143_vbar,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_143_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  category_143_pen_up_hdlr
 * DESCRIPTION
 *  pen up handler
 * PARAMETERS
 *  pos     [IN]        pen up position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL category_143_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category143_vbar.x, category143_vbar.y, category143_vbar.width, category143_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category143_vbar,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_143_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  category_143_pen_move_hdlr
 * DESCRIPTION
 *  Pen move handler
 * PARAMETERS
 *  pos     [IN]        pen move handler
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL category_143_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category143_vbar.x, category143_vbar.y, category143_vbar.width, category143_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category143_vbar,
            MMI_PEN_EVENT_MOVE,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_143_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  category_143_pen_repeat_hdlr
 * DESCRIPTION
 *  pen repeat handler
 * PARAMETERS
 *  pos     [IN]      pen repeat position  
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL category_143_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category143_vbar.x, category143_vbar.y, category143_vbar.width, category143_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category143_vbar,
            MMI_PEN_EVENT_REPEAT,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_143_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  DrawCate143CategoryControlArea
 * DESCRIPTION
 *  Draws the category143 category control area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate143CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    category_143_redraw_highlighted_item();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory143Screen
 * DESCRIPTION
 *  Displays the object list screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  object_list             [IN]        Array of items
 *  n_items                 [IN]        Number of items in the menu
 *  index                   [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory143Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        EMSObject *object_list,
        S32 *n_items,
        S32 *index,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 shortcut_width, n = 0;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    EMS_view_mode = 1;
    initialize_EMS_objects();
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 0;

    clear_left_softkey();
    clear_right_softkey();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    MMI_title_icon = get_image(title_icon);
    MMI_title_string = get_string(title);
    category_143_object_list = object_list;
    category_143_object_list_index = index;

    h_flag = set_object_list_category_history(MMI_CATEGORY143_ID, history_buffer, category_143_object_list_index);
    if (h_flag)
    {
        *index = *category_143_object_list_index;
    }
    if (category_143_object_list == NULL)
    {
        n = 0;
        category_143_current_object = NULL;
    }
    else
    {
        S32 i;
        EMSObject *p = object_list->next;

        ++n;
        while (p != NULL)
        {
            p = p->next;
            ++n;
        }
        if (*index < 0)
        {
            *index = 0;
        }
        if (*index >= n)
        {
            *index = n - 1;
        }
        category_143_current_object = category_143_object_list;
        for (i = 0; i < *index; i++)
        {
            category_143_current_object = category_143_current_object->next;
        }
    }
    *n_items = n;
    MMI_menu_shortcut_number = *index + 1;
    category_143_object_list_n_items = n;
    category_143_object_list_index = index;
    if (*category_143_object_list_index < 0)
    {
        *category_143_object_list_index = 0;
    }
    if (*category_143_object_list_index >= category_143_object_list_n_items)
    {
        *category_143_object_list_index = category_143_object_list_n_items - 1;
    }
    gui_create_vertical_scrollbar(
        &category143_vbar,
        UI_device_width - current_MMI_theme->scrollbar_size,
        (MMI_title_y + MMI_title_height),
        current_MMI_theme->scrollbar_size,
        MMI_content_height);
    /* ShortCut */
    register_fixed_list_shortcut_handler();
    shortcut_width = set_menu_item_count(*n_items) + 7;
    resize_menu_shortcut_handler(shortcut_width, (MMI_title_height));
    move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
    register_hide_menu_shortcut(draw_title);

    register_keyboard_key_handler(category_143_key_handler);
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(category_143_goto_item);
    SetKeyHandler(category_143_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(category_143_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(category_143_goto_previous_item, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(category_143_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory143Screen;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory143History, GetCategory143HistorySize);
    dm_register_category_controlled_callback(DrawCate143CategoryControlArea);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(category_143_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(category_143_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(category_143_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(category_143_pen_repeat_hdlr, MMI_PEN_EVENT_REPEAT);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY143_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_LITE_DISP_WALLPAPER;//071007 ems bg
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory143Screen
 * DESCRIPTION
 *  Exits the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory143Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_view_mode = 0;
    EMS_cancel_object_focus();
    close_EMS_objects();
    reset_menu_shortcut_handler();
    category_143_object_list = NULL;
    category_143_object_list_index = NULL;
    category_143_object_list_n_items = 0;
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory143HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory143HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(object_list_category_history));
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory143History
 * DESCRIPTION
 *  Gets the history buffer for the object list screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory143History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_object_list_category_history(MMI_CATEGORY143_ID, history_buffer, category_143_object_list_index);
    return (history_buffer);
}

/* Supports only user defined objects  */


/*****************************************************************************
 * FUNCTION
 *  GetCategory143DataType
 * DESCRIPTION
 *  get category 143 data type
 * PARAMETERS
 *  void
 * RETURNS
 *  data type of category 143
 *****************************************************************************/
U8 GetCategory143DataType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (category_143_current_object->Type)
    {
        case EMS_TYPE_PIC:
            return (EMS_USERDEFINED_PICTURE);
        case EMS_TYPE_USERDEF_ANM:
            return (EMS_USERDEFINED_ANIMATION);
            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_TYPE_USERDEF_SND:
            return (EMS_USERDEFINED_MELODY);
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
    return (0);
}

/* Supports only user defined objects  */


/*****************************************************************************
 * FUNCTION
 *  GetCategory143DataSize
 * DESCRIPTION
 *  get category 143 data size
 * PARAMETERS
 *  void
 * RETURNS
 *  size of 143 data
 *****************************************************************************/
S32 GetCategory143DataSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (category_143_current_object->Type)
    {
        case EMS_TYPE_PIC:
            size = 9 + category_143_current_object->data->picture.pdu_length;
            break;
        case EMS_TYPE_USERDEF_ANM:
            size = 12 + category_143_current_object->data->animation.pdu_length;
            break;
            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_TYPE_USERDEF_SND:
            size = 4 + category_143_current_object->data->sound.pdu_length;
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
    return (size);
}

/* Supports only user defined objects  */


/*****************************************************************************
 * FUNCTION
 *  GetCategory143Data
 * DESCRIPTION
 *  Get cateogyr 143 data
 * PARAMETERS
 *  data        [OUT]     buffer to get data
 * RETURNS
 *  
 *****************************************************************************/
U8 *GetCategory143Data(U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data != NULL)
    {
        switch (category_143_current_object->Type)
        {
            case EMS_TYPE_PIC:
                data[0] = (U8) EMS_USERDEFINED_PICTURE;
                data[1] = (U8) category_143_current_object->data->picture.bitsPerPixel;
                data[2] = (U8) category_143_current_object->data->picture.attribute;
                data[3] = (U8) category_143_current_object->data->picture.hDim;
                data[4] = (U8) (category_143_current_object->data->picture.hDim >> 8);
                data[5] = (U8) category_143_current_object->data->picture.vDim;
                data[6] = (U8) (category_143_current_object->data->picture.vDim >> 8);
                data[7] = (U8) category_143_current_object->data->picture.pdu_length;
                data[8] = (U8) (category_143_current_object->data->picture.pdu_length >> 8);
                gui_memcpy(
                    data + 9,
                    category_143_current_object->data->picture.pdu,
                    category_143_current_object->data->picture.pdu_length);
                break;

            case EMS_TYPE_USERDEF_ANM:
                data[0] = (U8) EMS_USERDEFINED_ANIMATION;
                data[1] = (U8) category_143_current_object->data->animation.bitsPerPixel;
                data[2] = (U8) category_143_current_object->data->animation.attribute;
                data[3] = (U8) category_143_current_object->data->animation.cFrame;
                data[4] = (U8) category_143_current_object->data->animation.cRepeat;
                data[5] = (U8) category_143_current_object->data->animation.Duration;
                data[6] = (U8) category_143_current_object->data->animation.hDim;
                data[7] = (U8) (category_143_current_object->data->animation.hDim >> 8);
                data[8] = (U8) category_143_current_object->data->animation.vDim;
                data[9] = (U8) (category_143_current_object->data->animation.vDim >> 8);
                data[10] = (U8) category_143_current_object->data->animation.pdu_length;
                data[11] = (U8) (category_143_current_object->data->animation.pdu_length >> 8);
                gui_memcpy(
                    data + 12,
                    category_143_current_object->data->animation.pdu,
                    category_143_current_object->data->animation.pdu_length);
                break;
                /* MTK Joy added for customization, 1014 */
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_TYPE_USERDEF_SND:
                data[0] = (U8) EMS_USERDEFINED_MELODY;
                data[1] = (U8) category_143_current_object->data->sound.attribute;
                data[2] = (U8) category_143_current_object->data->sound.pdu_length;
                data[3] = (U8) (category_143_current_object->data->sound.pdu_length >> 8);
                gui_memcpy(
                    data + 4,
                    category_143_current_object->data->sound.pdu,
                    category_143_current_object->data->sound.pdu_length);
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
                /* MTK end */
        }
    }
    return (data);
}

#define EMS_PREDEFINED_PICTURE_HEADER_SIZE         3
#define EMS_USERDEFINED_PICTURE_HEADER_SIZE        3
#define EMS_PREDEFINED_ANIMATION_HEADER_SIZE    1
#define EMS_USERDEFINED_ANIMATION_HEADER_SIZE      3
#define EMS_PREDEFINED_SOUND_HEADER_SIZE        1
#define EMS_PREDEFINED_MELODY_HEADER_SIZE       1
#define EMS_USERDEFINED_MELODY_HEADER_SIZE         1


/*****************************************************************************
 * FUNCTION
 *  InsertEMSObjectUIHeader
 * DESCRIPTION
 *  Insert object UI header
 * PARAMETERS
 *  object_type     [IN]        object type
 *  object_size     [IN]        object size
 *  source          [IN]        object source data
 *  destination     [OUT]       object destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
void InsertEMSObjectUIHeader(U32 object_type, S32 object_size, U8 *source, U8 *destination)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type & 0xff)
    {
        case EMS_USERDEFINED_MELODY:
            gui_memcpy((destination + 3), source, object_size);
            destination[0] = (U8) EMS_USERDEFINED_MELODY;
            destination[1] = (U8) object_size;
            destination[2] = (U8) object_size >> 8;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RemoveEMSObjectUIHeader
 * DESCRIPTION
 *  remove object UI header
 * PARAMETERS
 *  object_type     [IN]        object type
 *  source          [IN]        object source data
 *  destination     [OUT]       object destination buffer
 * RETURNS
 *  void
 *****************************************************************************/
void RemoveEMSObjectUIHeader(U32 object_type, U8 *source, U8 *destination)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 object_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type & 0xff)
    {
        case EMS_USERDEFINED_MELODY:
            object_size = destination[1];
            object_size |= destination[2] << 8;
            gui_memcpy(destination, (source + 3), object_size);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetEMSObjectPDUSize
 * DESCRIPTION
 *  get object PDU size
 * PARAMETERS
 *  data        [IN]     data of obj
 *  size        [OUT]    size of obj 
 * RETURNS
 *  void
 *****************************************************************************/
void GetEMSObjectPDUSize(U8 *data, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data != NULL)
    {
        U8 ID = data[0];

        switch (ID)
        {
            case EMS_PREDEFINED_PICTURE:
                *size = *size - 8;
                *size = *size + EMS_PREDEFINED_PICTURE_HEADER_SIZE;
                break;
            case EMS_USERDEFINED_PICTURE:
                *size = *size - 8;
                *size = *size + EMS_USERDEFINED_PICTURE_HEADER_SIZE;
                break;
            case EMS_PREDEFINED_ANIMATION:
                *size = *size + EMS_PREDEFINED_ANIMATION_HEADER_SIZE;
                break;
            case EMS_USERDEFINED_ANIMATION:
                *size = *size - 8;
                *size = *size + EMS_USERDEFINED_ANIMATION_HEADER_SIZE;
                break;
            case EMS_PREDEFINED_SOUND:
                *size = *size + EMS_PREDEFINED_SOUND_HEADER_SIZE;
                break;
            case EMS_USERDEFINED_MELODY:
                *size = *size - 3;
                *size = *size + EMS_USERDEFINED_MELODY_HEADER_SIZE;
                break;
            case EMS_PREDEFINED_MELODY:
                *size = *size - 3;
                *size = *size + EMS_PREDEFINED_MELODY_HEADER_SIZE;
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetEMSPredefinedObjectPDUSize
 * DESCRIPTION
 *  get predefined object PDU size
 * PARAMETERS
 *  object_type     [IN]        object type
 * RETURNS
 *  
 *****************************************************************************/
S32 GetEMSPredefinedObjectPDUSize(U32 object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type & 0xff)
    {
        case EMS_PREDEFINED_ANIMATION:
            size = (1 + EMS_PREDEFINED_ANIMATION_HEADER_SIZE);
        case EMS_PREDEFINED_SOUND:
            size = (1 + EMS_PREDEFINED_SOUND_HEADER_SIZE);
    }
    return (size);
}

const U8 EMS_invalid_object_symbol[] = {EMS_PREDEFINED_PICTURE, 0x01, 0x18, 0x00, 0x18, 0x00, 0x48, 0x00,
    0x00, 0xFF, 0x00, 0x03, 0x00, 0xC0, 0x04, 0x00, 0x20, 0x18, 0x7E, 0x18, 0x11, 0xFF, 0x88, 0x23,
    0xFF, 0xC4, 0x47, 0xC3, 0xE2, 0x4F, 0x81, 0xF2, 0x8F, 0x3C, 0xF1, 0x9F, 0x3C, 0xF9, 0x9F, 0xFC,
    0xF9, 0x9F, 0xF9, 0xF9, 0x9F, 0xF3, 0xF9, 0x9F, 0xE7, 0xF9, 0x9F, 0xE7, 0xF9, 0x8F, 0xFF, 0xF1,
    0x4F, 0xFF, 0xF2, 0x47, 0xE7, 0xE2, 0x23, 0xE7, 0xC4, 0x11, 0xFF, 0x88, 0x18, 0x7E, 0x18, 0x04,
    0x00, 0x20, 0x03, 0x00, 0xC0, 0x00, 0xFF, 0x00,
};


S32 *category_144_object_list_index = NULL;
S32 category_144_object_list_n_items = 0;
S32 category_144_object_list_default_index = 0;
vertical_scrollbar category144_vbar;
EMSObject category_144_current_object;
EMSObjData category_144_current_object_data;
U8 **category_144_userdefined_objects = NULL;
U16 *category_144_predefined_objects = NULL;
U8 **category_144_list_of_titles = NULL;
U32 category_144_object_list_flags = 0;

/* image pre-loading for objects stored on a file system */
U8 category_144_object_file_flag = 0;
U8 *(*load_EMS_object_file) (S32 index) = NULL;
U8 category_144_autodetect_object_type;
U8 *category_144_data_ptr[1];
static U8 *category_144_file_data = NULL;
/*****************************************************************************
 * FUNCTION
 *  category_144_load_invalid_object_symbol
 * DESCRIPTION
 *  Redraws the object list screen
 * PARAMETERS
 *  obj     [OUT]     object pointer
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_load_invalid_object_symbol(EMSObject *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObjData *object = obj->data;
    U8 *data = (U8*) EMS_invalid_object_symbol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj->Type = EMS_TYPE_PIC;
    object->picture.bitsPerPixel = data[1];
    object->picture.hDim = data[2] | (data[3] << 8);
    object->picture.vDim = data[4] | (data[5] << 8);
    object->picture.pdu_length = data[6] | (data[7] << 8);
    data += 8;
    object->picture.pdu = data;
}


/*****************************************************************************
 * FUNCTION
 *  category_144_load_object
 * DESCRIPTION
 *  load object by index
 * PARAMETERS
 *  index       [IN]        index to load
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_load_object(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 object_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index < 0) || (index >= category_144_object_list_n_items))
    {
        return;
    }
    object_type = (U8) (category_144_object_list_flags & 0x0f);
    /* image pre-loading for objects stored on a file system */
    if ((category_144_object_file_flag) || (category_144_autodetect_object_type))
    {
        U8 *object_data;

        if (load_EMS_object_file != NULL)
        {
            object_data = (U8*) load_EMS_object_file(index);
            if (object_data != NULL)
            {
                if (category_144_autodetect_object_type)
                {
                    object_type = (U8) object_data[0];
                }
                switch (object_type)
                {
                    case EMS_PREDEFINED_PICTURE:
                        category_144_current_object.Type = EMS_TYPE_PIC;
                        EMS_predefined_pictures[index] = object_data;
                        break;

                    case EMS_USERDEFINED_PICTURE:
                        category_144_current_object.Type = EMS_TYPE_PIC;
                        category_144_userdefined_objects[index] = object_data;
                        break;

                    case EMS_USERDEFINED_ANIMATION:
                        category_144_current_object.Type = EMS_TYPE_USERDEF_ANM;
                        category_144_userdefined_objects[index] = object_data;
                        break;

                        /* MTK Joy added for customization, 1014 */
                #if defined(__MMI_IMELODY_SUPPORT__)

                    case EMS_PREDEFINED_MELODY:
                        category_144_current_object.Type = EMS_TYPE_USERDEF_SND;
                        EMS_predefined_melodies[index] = object_data;
                        break;

                    case EMS_USERDEFINED_MELODY:
                        category_144_current_object.Type = EMS_TYPE_USERDEF_SND;
                        category_144_userdefined_objects[index] = object_data;
                        break;
                #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
                        /* MTK end */
                }
            }
        }
    }
    switch (object_type)
    {
        case EMS_PREDEFINED_PICTURE:
    #ifdef __EMS_REL5__
            if (EMS_load_object
                (object_type, NULL, category_144_predefined_objects[index],
                 category_144_current_object.data) == EMS_INVALID_OBJECT &&
                category_144_current_object.data->picture.attribute != 1)
    #else /* __EMS_REL5__ */ 
            if (EMS_load_object
                (object_type, NULL, category_144_predefined_objects[index],
                 category_144_current_object.data) == EMS_INVALID_OBJECT)
    #endif /* __EMS_REL5__ */ 
                category_144_load_invalid_object_symbol(&category_144_current_object);
            break;

        case EMS_USERDEFINED_PICTURE:
    #ifdef __EMS_REL5__
            if (EMS_load_object
                (object_type, category_144_userdefined_objects[index], 0,
                 category_144_current_object.data) == EMS_INVALID_OBJECT &&
                category_144_current_object.data->picture.attribute != 1)
    #else /* __EMS_REL5__ */ 
            if (EMS_load_object
                (object_type, category_144_userdefined_objects[index], 0,
                 category_144_current_object.data) == EMS_INVALID_OBJECT)
    #endif /* __EMS_REL5__ */ 
                category_144_load_invalid_object_symbol(&category_144_current_object);
            break;

        case EMS_USERDEFINED_ANIMATION:
    #ifdef __EMS_REL5__
            if (EMS_load_object
                (object_type, category_144_userdefined_objects[index], 0,
                 category_144_current_object.data) == EMS_INVALID_OBJECT &&
                category_144_current_object.data->animation.attribute != 1)
    #else /* __EMS_REL5__ */ 
            if (EMS_load_object
                (object_type, category_144_userdefined_objects[index], 0,
                 category_144_current_object.data) == EMS_INVALID_OBJECT)
    #endif /* __EMS_REL5__ */ 
                category_144_load_invalid_object_symbol(&category_144_current_object);
            break;

        case EMS_PREDEFINED_ANIMATION:
            category_144_current_object.Type = EMS_TYPE_PREDEF_ANM;
            category_144_current_object.PredefNo = (U8) category_144_predefined_objects[index];
            break;

        case EMS_PREDEFINED_SOUND:
            category_144_current_object.Type = EMS_TYPE_PREDEF_SND;
            category_144_current_object.PredefNo = (U8) category_144_predefined_objects[index];
            break;

            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)

        case EMS_PREDEFINED_MELODY:
    #ifdef __EMS_REL5__
            if (EMS_load_object
                (EMS_PREDEFINED_MELODY, NULL, category_144_predefined_objects[index],
                 category_144_current_object.data) == EMS_INVALID_OBJECT &&
                category_144_current_object.data->sound.attribute != 1)
    #else /* __EMS_REL5__ */ 
            if (EMS_load_object
                (EMS_PREDEFINED_MELODY, NULL, category_144_predefined_objects[index],
                 category_144_current_object.data) == EMS_INVALID_OBJECT)
    #endif /* __EMS_REL5__ */ 
                category_144_load_invalid_object_symbol(&category_144_current_object);
            break;

        case EMS_USERDEFINED_MELODY:
    #ifdef __EMS_REL5__
            if (EMS_load_object
                (EMS_USERDEFINED_MELODY, category_144_userdefined_objects[index], 0,
                 category_144_current_object.data) == EMS_INVALID_OBJECT &&
                category_144_current_object.data->sound.attribute != 1)
    #else /* __EMS_REL5__ */ 
            if (EMS_load_object
                (EMS_USERDEFINED_MELODY, category_144_userdefined_objects[index], 0,
                 category_144_current_object.data) == EMS_INVALID_OBJECT)
    #endif /* __EMS_REL5__ */ 
                category_144_load_invalid_object_symbol(&category_144_current_object);
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
}


/*****************************************************************************
 * FUNCTION
 *  category_144_redraw_highlighted_item
 * DESCRIPTION
 *  redraw highlight item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_redraw_highlighted_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    color c;
    S32 index = 0;
#if 0
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (category_144_object_list_index != NULL)
    {
        index = *category_144_object_list_index;
    }
    EMS_cancel_object_focus();
    gui_reset_clip();
    c = gui_color(255, 255, 255);
#ifdef __MMI_WALLPAPER_ON_BOTTOM__//071007 ems bg
    gdi_draw_solid_rect(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1,
        GDI_COLOR_TRANSPARENT);
#else
    gui_fill_rectangle(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1,
        c);
#endif
    gui_set_clip(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - current_MMI_theme->scrollbar_size,
        MMI_content_height + 2);
    gui_EMS_input_box_measure_object(&category_144_current_object, &w, &h);
    x = (UI_device_width >> 1) - (w >> 1);
    y = (UI_device_height >> 1) - (h >> 1);
    gui_EMS_input_box_display_object(x, y, &category_144_current_object, 1);
    if (category_144_list_of_titles != NULL)
    {
        MMI_title_string = (UI_string_type) category_144_list_of_titles[index];
        draw_title();
    }
    /* Uncomment below line for auto-disable scrollbar    */
    if (category_144_object_list_n_items > 1)
    {
        gui_set_vertical_scrollbar_range(&category144_vbar, category_144_object_list_n_items);
        gui_set_vertical_scrollbar_scale(&category144_vbar, 1);
        gui_set_vertical_scrollbar_value(&category144_vbar, *category_144_object_list_index);

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
/* under construction !*/
#endif
        
        if (r2lMMIFlag)
        {
            /* move vertical scrollbar to the left side */
            gui_move_vertical_scrollbar(
                    &category144_vbar, 
                    0, 
                    category144_vbar.y);
        }

        gui_show_vertical_scrollbar(&category144_vbar);
    }
    gui_BLT_double_buffer(
        0,
        (MMI_title_y + MMI_title_height),
        UI_device_width - 1,
        UI_device_height - MMI_button_bar_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  category_144_highlight_handler
 * DESCRIPTION
 *  category 144 highlight handler
 * PARAMETERS
 *  index       [IN]        index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_menu_shortcut_number = index + 1;
    if (!menu_shortcut_handler_display)
    {
        draw_title();
    }
    MMI_list_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  category_144_goto_item
 * DESCRIPTION
 *  goto item by index
 * PARAMETERS
 *  index       [IN]        index of item
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_goto_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
    {
        return;
    }
    if (index > (category_144_object_list_n_items - 1))
    {
        return;
    }
    if (!whether_no_small_screen())
    {
        *category_144_object_list_index = index;
    }
    category_144_load_object(index);
    if (!whether_no_small_screen())
    {
        category_144_redraw_highlighted_item();
    }
    category_144_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  category_144_goto_previous_item
 * DESCRIPTION
 *  goto previous item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_144_object_list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index--;
    if (index < 0)
    {
        index = category_144_object_list_n_items - 1;
    }
    *category_144_object_list_index = index;
#ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
    /* do not load object if the small screen is on because redraw_small_image_selector_images will take care of it */
    if (whether_no_small_screen())
    {
        small_image_selector_configure_current_display(&small_image_selector, *category_144_object_list_index);
        redraw_small_image_selector_images();
    }
    else
#endif /* UI_SMALL_IMAGE_SELECTOR_SCREEN */ 
    {
        category_144_load_object(index);
        category_144_redraw_highlighted_item();
        category_144_highlight_handler(index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  category_144_goto_next_item
 * DESCRIPTION
 *  category 144 goto next item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_144_object_list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index++;
    if (index > (category_144_object_list_n_items - 1))
    {
        index = 0;
    }
    *category_144_object_list_index = index;
#ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
    /* do not load object if the small screen is on because redraw_small_image_selector_images will take care of it */
    if (whether_no_small_screen())
    {
        small_image_selector_configure_current_display(&small_image_selector, *category_144_object_list_index);
        redraw_small_image_selector_images();
    }
    else
#endif /* UI_SMALL_IMAGE_SELECTOR_SCREEN */ 
    {
        category_144_load_object(index);
        category_144_redraw_highlighted_item();
        category_144_highlight_handler(index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  category_144_key_handler
 * DESCRIPTION
 *  category 144 keypad handler
 * PARAMETERS
 *  vkey_code       [IN]        virtual key code
 *  key_state       [IN]        key state
 * RETURNS
 *  void
 *****************************************************************************/
void category_144_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:    /* left */
                break;
            case 39:    /* right */
                break;
            case 38:
                category_144_goto_previous_item();
                break;
            case 40:
                category_144_goto_next_item();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  RegisterCategory144ObjectLoader
 * DESCRIPTION
 *  register category 144 object load callback
 * PARAMETERS
 *  f       [IN]        callback function
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterCategory144ObjectLoader(U8 *(*f) (S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    load_EMS_object_file = f;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  category_144_pen_down_hdlr
 * DESCRIPTION
 *  category 144 pen down handler
 * PARAMETERS
 *  pos     [IN]        pen down position
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL category_144_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category144_vbar.x, category144_vbar.y, category144_vbar.width, category144_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category144_vbar,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_144_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  category_144_pen_up_hdlr
 * DESCRIPTION
 *  category 144 pen up handler
 * PARAMETERS
 *  pos     [IN]        pen up position
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL category_144_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category144_vbar.x, category144_vbar.y, category144_vbar.width, category144_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category144_vbar,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_144_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  category_144_pen_move_hdlr
 * DESCRIPTION
 *  category 144 pen move handler
 * PARAMETERS
 *  pos     [IN]        pen move position
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL category_144_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category144_vbar.x, category144_vbar.y, category144_vbar.width, category144_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category144_vbar,
            MMI_PEN_EVENT_MOVE,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_144_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  category_144_pen_repeat_hdlr
 * DESCRIPTION
 *  category 144 pen repeat handler
 * PARAMETERS
 *  pos     [IN]        pen repeat position
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL category_144_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (pos.x, pos.y, category144_vbar.x, category144_vbar.y, category144_vbar.width, category144_vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &category144_vbar,
            MMI_PEN_EVENT_REPEAT,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            category_144_goto_item((S32) scrollbar_param._u.i);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  DrawCate144CategoryControlArea
 * DESCRIPTION
 *  Draws the category144 category control area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate144CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    category_144_redraw_highlighted_item();
}

#ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN

extern U16 title_bg_id;
U16 g_small_image_selector = 0;
static S16 small_image_selector_index[MAX_IMAGE_SELECTOR_ROW][MAX_IMAGE_SELECTOR_COL];


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_configure_current_display
 * DESCRIPTION
 *  function used to configure the current items to be displayed on the small screen
 *  calculates the first item to be displayed
 * PARAMETERS
 *  s                           [IN]        Small image sleector structure
 *  new_highlighted_image       [IN]        New highlighted image
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_configure_current_display(small_image_selector_struct *s, S32 new_highlighted_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_highlighted_row, new_highlighted_column;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_highlighted_row = new_highlighted_image / s->n_columns;
    new_highlighted_column = new_highlighted_image % s->n_columns;

    if (s->flags & UI_SMALL_IMAGE_SELECTOR_SHOW_VERTICAL_SCROLLBAR)
    {
        if (new_highlighted_row == 0)
        {
            s->first_displayed_row = 0;
        }
        else if (new_highlighted_row > s->highlighted_row)
        {
            if (new_highlighted_row == s->n_rows - 1 && s->highlighted_row == 0)
            {
                s->first_displayed_row = new_highlighted_row - s->displayed_rows + 1;
            }
            else if ((new_highlighted_row - s->first_displayed_row) >= s->displayed_rows &&
                     (s->n_rows - new_highlighted_row) > s->displayed_rows)
            {
                s->first_displayed_row = new_highlighted_row;
            }
            else if ((new_highlighted_row - s->first_displayed_row) >= s->displayed_rows &&
                     (s->n_rows - new_highlighted_row) > 0)
            {
                s->first_displayed_row = new_highlighted_row - 1;
            }
        }
        else if (new_highlighted_row <= (s->first_displayed_row - 1))
        {
            if (new_highlighted_row == s->n_rows - 1)
            {
                s->first_displayed_row = new_highlighted_row - s->displayed_rows + 1;
            }
            else if (new_highlighted_row >= s->displayed_rows - 1)
            {
                s->first_displayed_row = new_highlighted_row - s->displayed_rows + 1;
            }
            else
            {
                s->first_displayed_row = new_highlighted_row - 1;
            }
        }
    }
    if (s->flags & UI_SMALL_IMAGE_SELECTOR_SHOW_HORIZONTAL_SCROLLBAR)
    {
        if (new_highlighted_column == 0)
        {
            s->first_displayed_column = 0;
        }
        else if (new_highlighted_column > s->highlighted_column)
        {
            if (new_highlighted_column == s->n_columns - 1 && s->highlighted_column == 0)
            {
                s->first_displayed_column = new_highlighted_column - s->displayed_columns + 1;
            }
            else if ((new_highlighted_column - s->first_displayed_column) >= s->displayed_columns &&
                     (s->n_columns - new_highlighted_column) > s->displayed_columns)
            {
                s->first_displayed_column = new_highlighted_column;
            }
            else if ((new_highlighted_column - s->first_displayed_column) >= s->displayed_columns &&
                     (s->n_columns - new_highlighted_column) > 0)
            {
                s->first_displayed_column = new_highlighted_column - 1;
            }

        }
        else if (new_highlighted_column <= (s->first_displayed_column - 1))
        {
            if (new_highlighted_column == s->n_columns - 1)
            {
                s->first_displayed_column = new_highlighted_column - s->displayed_columns + 1;
            }
            else if (new_highlighted_column >= s->displayed_columns - 1)
            {
                s->first_displayed_column = new_highlighted_column - s->displayed_columns + 1;
            }
            else
            {
                s->first_displayed_column = new_highlighted_column - 1;
            }

        }
    }
    s->first_displayed_image = s->first_displayed_row * s->n_columns + s->first_displayed_column;
    s->highlighted_column = new_highlighted_column;
    s->highlighted_row = new_highlighted_row;
}


/*****************************************************************************
 * FUNCTION
 *  associate_small_image_selector
 * DESCRIPTION
 *  function used to initialize the small image selector structure
 * PARAMETERS
 *  s       [IN]        Small image sleector structure
 * RETURNS
 *  void
 *****************************************************************************/
void associate_small_image_selector(small_image_selector_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->displayed_columns = 0;
    s->displayed_rows = 0;
    s->first_displayed_column = 0;
    s->first_displayed_row = 0;
    s->first_displayed_image = 0;
    s->highlighted_column = 0;
    s->highlighted_row = 0;
    s->highlighted_image = 0;
    s->n_columns = 0;
    s->n_rows = 0;
    s->flags = 0;
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_auto_calculate
 * DESCRIPTION
 *  Function used to auto calculate the no. of rows and columns depending upon the display area.
 * PARAMETERS
 *  s       [IN]        Small image sleector structure
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_auto_calculate(small_image_selector_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->n_columns = s->displayed_columns;

    if (s->displayed_rows == 1)
    {
        s->n_columns = s->n_images;
        s->n_rows = 1;
    }
    else if (s->displayed_columns == 1)
    {
        s->n_columns = 1;
        s->n_rows = s->n_images;
    }
    else
    {
        s->n_rows = pixtel_highdivide(s->n_images, s->n_columns);
    }
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_auto_configure
 * DESCRIPTION
 *  Function used to auto configure the no. of rows and columns to be displayed depending upon the display area.
 * PARAMETERS
 *  s       [IN]        Small image sleector structure
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_auto_configure(small_image_selector_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 show_vbar = 0, show_hbar = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((s->n_columns <= 0) && (s->image_width <= 0))
    {
        return;
    }
    if ((s->n_rows <= 0) && (s->image_height <= 0))
    {
        return;
    }
    if (s->n_images == 0)
    {
        return;
    }

    /* Calculate the number of displayed rows and columns    */
    s->displayed_rows = s->height / s->image_height;
    s->displayed_columns = s->width / s->image_width;

    small_image_selector_auto_calculate(s);

    if (s->displayed_rows < s->n_rows)
    {
        small_image_selector_auto_calculate(s);
    }

    if ((s->n_rows > s->displayed_rows))
    {
        show_vbar = 1;
        s->flags |= UI_SMALL_IMAGE_SELECTOR_SHOW_VERTICAL_SCROLLBAR;
    }
    if ((s->n_columns > s->displayed_columns))
    {
        show_hbar = 1;
        s->flags |= UI_SMALL_IMAGE_SELECTOR_SHOW_HORIZONTAL_SCROLLBAR;
    }

    if (show_vbar)
    {
        s->width = s->width - s->vbar.width + 1;
    }
    if (show_hbar)
    {
        s->height = s->height - s->hbar.height + 1;
    }

    /* Recalculate the number of rows that can be displayed  */
    s->displayed_rows = s->height / s->image_height;
    s->displayed_columns = s->width / s->image_width;

    /* Fix the number of displayed rows and columns       */
    if (s->displayed_columns > s->n_columns)
    {
        s->displayed_columns = s->n_columns;
    }
    if (s->displayed_rows > s->n_rows)
    {
        s->displayed_rows = s->n_rows;
    }

    s->h_gap = (s->width - s->displayed_columns * s->image_width) / (s->displayed_columns + 1);
    s->v_gap = (s->height - s->displayed_rows * s->image_height) / (s->displayed_rows + 1);

    if (show_vbar && (!show_hbar))
    {
        gui_resize_vertical_scrollbar(&s->vbar, s->vbar.width, s->height);
    }
    if (show_hbar && (!show_vbar))
    {
        gui_resize_horizontal_scrollbar(&s->hbar, s->width, s->hbar.height);
    }
    if (show_vbar && show_hbar)
    {
        gui_resize_vertical_scrollbar(&s->vbar, s->vbar.width, s->height - s->hbar.height);
        gui_resize_horizontal_scrollbar(&s->hbar, s->width - s->vbar.width, s->hbar.height);
    }
    gui_move_vertical_scrollbar(&s->vbar, s->x + s->width, s->y);
    gui_move_horizontal_scrollbar(&s->hbar, s->x, s->y + s->height);
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_set_up
 * DESCRIPTION
 *  set up function for small image selector
 * PARAMETERS
 *  s               [IN]        Small image sleector structure
 *  n_images        [IN]        Total no. of images
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_set_up(small_image_selector_struct *s, S32 n_images)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2, y1, y2;
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = MMI_SMALL_SCREEN_X_OFFSET;
    x2 = UI_device_width - MMI_SMALL_SCREEN_X_OFFSET;
    y1 = MMI_title_y + MMI_title_height;
    y2 = UI_device_height - (MMI_button_bar_height + MMI_SMALL_SCREEN_Y_OFFSET);
    category_144_load_object(0);
    gui_EMS_input_box_measure_object(&category_144_current_object, &w, &h);
    s->x = x1;
    s->y = y1;
    s->height = y2 - y1;
    s->width = x2 - x1;
    s->image_height = h;
    s->image_width = w;
    s->n_images = n_images;

    gui_create_vertical_scrollbar(
        &s->vbar,
        s->x + s->width - current_MMI_theme->scrollbar_size - 1,
        s->y + 2,
        current_MMI_theme->scrollbar_size,
        s->height - current_MMI_theme->scrollbar_size - 3);
    gui_create_horizontal_scrollbar(
        &s->hbar,
        s->x + 2,
        s->y + s->height - current_MMI_theme->scrollbar_size - 1,
        s->width - current_MMI_theme->scrollbar_size - 3,
        current_MMI_theme->scrollbar_size);
    small_image_selector_auto_configure(s);
}

/*****************************************************************************
 * FUNCTION
 *  redraw_small_image_selector_images
 * DESCRIPTION
 *  redraw function for the small image selector screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_small_image_selector_images(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, x, y, w, h, start_x, end_x, end_y, row, col, displayed_column;
    S32 current_row = 0;
    small_image_selector_struct *s = &small_image_selector;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_draw_filled_area(
        MMI_title_x - 1,
        MMI_title_y - 1,    /* 101706 image select */
        UI_device_width - MMI_SMALL_SCREEN_X_OFFSET,
        UI_device_height - MMI_button_bar_height - MMI_SMALL_SCREEN_Y_OFFSET + 2,
        current_UI_theme->EMS_inputbox_theme->disabled_filler);

    x = s->x + s->h_gap;
    y = s->y + s->v_gap;
    end_x = s->x + s->width - 1;
    end_y = s->y + s->height - 1;
    start_x = x;

    for (row = 0; row < s->n_rows; row++)
    {
        for (col = 0; col < s->n_columns; col++)
        {
            small_image_selector_index[row][col] = col + row * s->n_columns;
        }
    }

    i = s->first_displayed_image;
    row = s->first_displayed_row;
    col = s->first_displayed_column;
    displayed_column = s->displayed_columns;
    for (; i < category_144_object_list_n_items; i = col + row * displayed_column)
    {
        category_144_goto_item(i);
        gui_EMS_input_box_measure_object(&category_144_current_object, &w, &h);
        start_x += w;
        if (start_x > end_x)
        {
            y += h + s->v_gap;
            current_row++;
            if (y >= end_y || current_row >= s->displayed_rows)
            {
                break;
            }
            x = MMI_SMALL_SCREEN_X_OFFSET + s->h_gap;
            start_x = x + w;
            row++;
            col = s->first_displayed_column;
            col++;
        }
        else
        {
            start_x += s->h_gap;
            col++;
        }
        if (i == *category_144_object_list_index)
        {
            /* highlight currently selected item */
            gui_draw_rectangle(x - 1, y - 1, x + w, y + h, UI_COLOR_BLACK);
            /* show animation only when the highlight is on it */
            gui_EMS_input_box_display_object(x, y, &category_144_current_object, 1);
        }
        else
        {
            /* show single frame for animation when the highlight is not on it */
            gui_EMS_input_box_display_object(x, y, &category_144_current_object, 0);
        }
        x += w + s->h_gap;
    }

    category_144_goto_item(*category_144_object_list_index);
    if (s->flags & UI_SMALL_IMAGE_SELECTOR_SHOW_VERTICAL_SCROLLBAR)
    {
        gui_set_vertical_scrollbar_range(&s->vbar, s->n_rows);
        gui_set_vertical_scrollbar_scale(&s->vbar, s->displayed_rows);
        gui_set_vertical_scrollbar_value(&s->vbar, s->first_displayed_row);
        gui_show_vertical_scrollbar(&s->vbar);
    }
    if (s->flags & UI_SMALL_IMAGE_SELECTOR_SHOW_HORIZONTAL_SCROLLBAR)
    {
        gui_set_horizontal_scrollbar_range(&s->hbar, s->n_columns);
        gui_set_horizontal_scrollbar_scale(&s->hbar, s->displayed_columns);
        gui_set_horizontal_scrollbar_value(&s->hbar, s->first_displayed_column);
        gui_show_horizontal_scrollbar(&s->hbar);
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_SMALL_SCREEN_X_OFFSET,
        MMI_title_y,
        UI_device_width - MMI_SMALL_SCREEN_X_OFFSET,
        UI_device_height - MMI_button_bar_height - 5);
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_goto_previous_item
 * DESCRIPTION
 *  Selects the previous image in the image selector screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_144_object_list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index--;
    if (index < 0)
    {
        index = category_144_object_list_n_items - 1;
    }
    *category_144_object_list_index = index;
    redraw_small_image_selector_images();
    category_144_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_goto_next_item
 * DESCRIPTION
 *  Selects the next image in the image selector screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_144_object_list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index++;
    if (index > (category_144_object_list_n_items - 1))
    {
        index = 0;
    }
    *category_144_object_list_index = index;
    redraw_small_image_selector_images();
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_compute_row_col
 * DESCRIPTION
 *  Calculates the row and column number of the image in the list
 * PARAMETERS
 *  index       [IN]        index to calculates
 *  row         [OUT]       row of index
 *  col         [OUT]       col of index
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_compute_row_col(S32 index, S32 *row, S32 *col)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 r, c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *row = -1;
    *col = -1;

    MMI_ASSERT(index >= 0 && index < category_144_object_list_n_items);

    for (r = 0; r < small_image_selector.n_rows; r++)
    {
        for (c = 0; c < small_image_selector.n_columns; c++)
        {
            if (small_image_selector_index[r][c] == index)
            {
                *row = r;
                *col = c;
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_compute_previous_row_image_index
 * DESCRIPTION
 *  Calculates the actual index of the image in the list
 * PARAMETERS
 *  index       [IN]        index of previous row
 * RETURNS
 *  S32
 *****************************************************************************/
S32 small_image_selector_compute_previous_row_image_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 row, col, new_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index >= 0 && index < category_144_object_list_n_items);
    small_image_selector_compute_row_col(index, &row, &col);
    MMI_ASSERT(row != -1 || col != -1);
    if (row == 0)
    {
        if (col + (small_image_selector.n_rows - 1) * small_image_selector.n_columns >= small_image_selector.n_images)
        {
            new_index = small_image_selector.n_images - 1;
        }
        else
        {
            new_index = small_image_selector_index[small_image_selector.n_rows - 1][col];
        }
        if (new_index == -1)
        {
            new_index = small_image_selector_index[small_image_selector.n_rows - 2][col];
        }
    }
    else
    {
        new_index = small_image_selector_index[row - 1][col];
    }
    return new_index;
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_compute_next_row_image_index
 * DESCRIPTION
 *  Calculates the actual index of the image in the list
 * PARAMETERS
 *  index       [IN]        index of next row
 * RETURNS
 *  S32
 *****************************************************************************/
S32 small_image_selector_compute_next_row_image_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 row, col, new_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index >= 0 && index < category_144_object_list_n_items);
    small_image_selector_compute_row_col(index, &row, &col);
    MMI_ASSERT(row != -1 || col != -1);
    if (row == small_image_selector.n_rows - 1)
    {
        new_index = small_image_selector_index[0][col];
        if (new_index == -1)
        {
            new_index = small_image_selector_index[1][col];
        }
    }
    else
    {
        if ((col + (row + 1) * small_image_selector.n_columns) >= small_image_selector.n_images)
        {
            new_index = small_image_selector.n_images - 1;
        }
        else
        {
            new_index = small_image_selector_index[row + 1][col];
        }
        if (new_index == -1)
        {
            new_index = small_image_selector_index[0][col];
        }
    }
    return new_index;
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_goto_previous_row
 * DESCRIPTION
 *  Calculates the previous row
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_goto_previous_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_144_object_list_index, new_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_index = small_image_selector_compute_previous_row_image_index(index);
    if (new_index < 0)
    {
        new_index = category_144_object_list_n_items - 1;
    }
    *category_144_object_list_index = new_index;
    small_image_selector_configure_current_display(&small_image_selector, *category_144_object_list_index);
    redraw_small_image_selector_images();
    category_144_highlight_handler(new_index);
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_goto_next_row
 * DESCRIPTION
 *  Calculates the next row
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_goto_next_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = *category_144_object_list_index, new_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_index = small_image_selector_compute_next_row_image_index(index);
    if (new_index > (category_144_object_list_n_items - 1))
    {
        new_index = 0;
    }
    *category_144_object_list_index = new_index;
    small_image_selector_configure_current_display(&small_image_selector, *category_144_object_list_index);
    redraw_small_image_selector_images();
    category_144_highlight_handler(new_index);
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_key_handler
 * DESCRIPTION
 *  Executes the function depending upon the key pressed
 * PARAMETERS
 *  vkey_code       [IN]        virtual key code
 *  key_state       [IN]        key state
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                category_144_goto_previous_item();  /* left */
                break;
            case 39:
                category_144_goto_next_item();      /* right */
                break;
            case 38:
                small_image_selector_goto_next_row();
                break;
            case 40:
                small_image_selector_goto_previous_row();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  small_image_selector_goto_item
 * DESCRIPTION
 *  Calculates the item based on the index passed
 * PARAMETERS
 *  index       [IN]        index to select
 * RETURNS
 *  void
 *****************************************************************************/
void small_image_selector_goto_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
    {
        return;
    }
    if (index > (category_144_object_list_n_items - 1))
    {
        return;
    }
    category_144_load_object(index);
    category_144_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSmallImageSelectorScreen
 * DESCRIPTION
 *  Exit the small image selector screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSmallImageSelectorScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    close_EMS_objects();
    EMS_view_mode = 0;

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    reset_small_screen();
#endif 

    title_bg_id = 0;

    show_status_icon_bar(0); /* 052906 early status icon */

    MMI_title_x = MMI_TITLE_X;
    MMI_title_y = MMI_TITLE_Y;
    MMI_title_width = UI_device_width;

    category_144_object_list_index = NULL;
    category_144_object_list_n_items = 0;
    category_144_list_of_titles = NULL;
    category_144_object_list_flags = 0;
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    load_EMS_object_file = NULL;
    entry_full_screen();
    
    if (category_144_file_data!=NULL)
    {
        mmi_frm_scrmem_free(category_144_file_data);
        category_144_file_data = NULL;
    }
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  small_image_selector_pen_down_hdlr
*
* DESCRIPTION
*   This is the pen event down handler.
*
* PARAMETERS
* pos     [IN]        co-ordinates to the point of contact of pen on LCD.
* 
*  
* RETURNS                 
* BOOL
*
* GLOBALS AFFECTED        
*   
*****************************************************************************/
MMI_BOOL small_image_selector_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PEN_CHECK_BOUND(pos.x,pos.y, small_image_selector.x, small_image_selector.y,small_image_selector.width, small_image_selector.height))
    {
        S32 i,x,y,w,h,start_x,end_x,end_y,row,col,displayed_column;
        S32 current_row=0;
        small_image_selector_struct *s = &small_image_selector;

        x = s->x + s->h_gap;
        y = s->y    + s->v_gap;
        end_x = s->x + s->width -1;
        end_y = s->y + s->height -1;
        start_x = x;
        i = s->first_displayed_image;
        row = s->first_displayed_row;
        col = s->first_displayed_column;
        displayed_column = s->displayed_columns;
        for(;i<category_144_object_list_n_items;i = col+row*displayed_column)
        {
            w = s->image_width;
            h = s->image_height; 
            start_x+=w;
            if(start_x > end_x)
            {
                y+=h+s->v_gap;
                current_row++;
                if(y>=end_y || current_row>=s->displayed_rows)
                    break;
                x = MMI_SMALL_SCREEN_X_OFFSET  + s->h_gap;
                start_x = x + w;
                row++;
                col = s->first_displayed_column;
                col++;
            }
            else
            {
                start_x+=s->h_gap;
                col++;
            }
            if(PEN_CHECK_BOUND(pos.x,pos.y,x,y,w,h))
            {
                *category_144_object_list_index = i;
                small_image_selector_configure_current_display(&small_image_selector,*category_144_object_list_index);
                redraw_small_image_selector_images();
                return MMI_TRUE;
            }
            x+=w+s->h_gap;
        }
    }

    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  small_image_selector_pen_up_hdlr
*
* DESCRIPTION
*   This is the pen event up handler.
*
* PARAMETERS
*  pos     [IN]        co-ordinates to the point of contact of pen on LCD.
* 
*  
* RETURNS                 
* BOOL
*
* GLOBALS AFFECTED        
*   
*****************************************************************************/

MMI_BOOL small_image_selector_pen_up_hdlr(mmi_pen_point_struct pos)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PEN_CHECK_BOUND(pos.x,pos.y, small_image_selector.x, small_image_selector.y,small_image_selector.width, small_image_selector.height))
    {
        S32 i,x,y,w,h,start_x,end_x,end_y,row,col,displayed_column;
        S32 current_row=0;
        small_image_selector_struct *s = &small_image_selector;

        x = s->x + s->h_gap;
        y = s->y    + s->v_gap;
        end_x = s->x + s->width -1;
        end_y = s->y + s->height -1;
        start_x = x;
        i = s->first_displayed_image;
        row = s->first_displayed_row;
        col = s->first_displayed_column;
        displayed_column = s->displayed_columns;
        for(;i<category_144_object_list_n_items;i = col+row*displayed_column)
        {
            w = s->image_width;
            h = s->image_height;
            start_x+=w;
            if(start_x > end_x)
            {
                y+=h+s->v_gap;
                current_row++;
                if(y>=end_y || current_row>=s->displayed_rows)
                    break;
                x = MMI_SMALL_SCREEN_X_OFFSET  + s->h_gap;
                start_x = x + w;
                row++;
                col = s->first_displayed_column;
                col++;
            }
            else
            {
                start_x+=s->h_gap;
                col++;
            }
            if(PEN_CHECK_BOUND(pos.x,pos.y,x,y,w,h))
            {
                *category_144_object_list_index = i;
                small_image_selector_configure_current_display(&small_image_selector,*category_144_object_list_index);
                PreviewEmsObjectIsDone();
                return MMI_TRUE;
            }
            x+=w+s->h_gap;
        }
    }
    
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  small_image_selector_pen_move_hdlr
*
* DESCRIPTION
*   This is the pen event move handler.
*
* PARAMETERS
*  pos     [IN]        co-ordinates to the point of contact of pen on LCD.
* 
*  
* RETURNS                 
* BOOL
*
* GLOBALS AFFECTED        
*   
*****************************************************************************/

MMI_BOOL small_image_selector_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PEN_CHECK_BOUND(pos.x,pos.y, small_image_selector.x, small_image_selector.y,small_image_selector.width, small_image_selector.height))
    {
        S32 i,x,y,w,h,start_x,end_x,end_y,row,col,displayed_column;
        S32 current_row=0;
        small_image_selector_struct *s = &small_image_selector;

        x = s->x + s->h_gap;
        y = s->y    + s->v_gap;
        end_x = s->x + s->width -1;
        end_y = s->y + s->height -1;
        start_x = x;
        i = s->first_displayed_image;
        row = s->first_displayed_row;
        col = s->first_displayed_column;
        displayed_column = s->displayed_columns;
        for(;i<category_144_object_list_n_items;i = col+row*displayed_column)
        {
            w = s->image_width;
            h = s->image_height;
            start_x+=w;
            if(start_x > end_x)
            {
                y+=h+s->v_gap;
                current_row++;
                if(y>=end_y || current_row>=s->displayed_rows)
                    break;
                x = MMI_SMALL_SCREEN_X_OFFSET  + s->h_gap;
                start_x = x + w;
                row++;
                col = s->first_displayed_column;
                col++;
            }
            else
            {
                start_x+=s->h_gap;
                col++;
            }
            if(PEN_CHECK_BOUND(pos.x,pos.y,x,y,w,h))
            {
                *category_144_object_list_index = i;
                small_image_selector_configure_current_display(&small_image_selector,*category_144_object_list_index);
                redraw_small_image_selector_images();
                return MMI_TRUE;
            }
            x+=w+s->h_gap;
        }
    }

    return MMI_FALSE;
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  RedrawSmallImageSelectorScreen
 * DESCRIPTION
 *  Redraws the image selector screen for the small screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawSmallImageSelectorScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_greyscale_rectangle(
        0,
        0,
        UI_device_width - 1,
        UI_device_height - 1,
        MMI_BG_GREYSCALE_VALUE,
        MMI_BG_GREYSCALE_BLACK_VALUE);
    gui_set_clip(0, MMI_title_y, UI_device_width - 1, UI_device_height - 1);
    gui_lock_double_buffer();
    gui_hide_animations();

    draw_title();
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
    small_image_selector_set_up(&small_image_selector, category_144_object_list_n_items);
    redraw_small_image_selector_images();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*----------------------------------------------------------------------------
Function:         ShowImageSelectorScreen
Description:      Displays the object list screen
Input Parameters:[1] S8*      title,            Title for the screen
               [2]   U16   title_icon           Icon shown with the title
               [3]   U16   left_softkey,        Left softkey label
               [4]   U16   left_softkey_icon,   Icon for the left softkey
               [5]   U16   right_softkey,       Right softkey label
               [6]   U16   right_softkey_icon,  Icon for the right softkey
               [7]   U32   object type flags
               [8]   S32   number of objects in the list
               [9]   U8**  list of object titles
               [10]  U16*  ist of predefined objects (EMS specific IDs)
               [11]  U8**  list of user defined objects (list of EMS data)
               [12]  S32 * index                highlighted item index
               [13]  U8*   history_buffer       history buffer
Output Parameters:   none
Returns:       void
----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  dm_category_144_controlled_area
 * DESCRIPTION
 *  This function is used to draw the category controlled area of idle screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void dm_category_144_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    small_image_selector_set_up(&small_image_selector, category_144_object_list_n_items);
    redraw_small_image_selector_images();
}


/*****************************************************************************
 * FUNCTION
 *  ShowImageSelectorScreen
 * DESCRIPTION
 *  Show image selector screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  object_type             [IN]        Object type
 *  n_items                 [IN]        itmes count
 *  object_titles           [IN]        String list of object title
 *  predefined_objects      [IN]        Predefined object file path
 *  userdefined_objects     [IN]        User defined object list
 *  index                   [IN]        Index list
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowImageSelectorScreen(
        S8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U32 object_type,
        S32 n_items,
        U8 **object_titles,
        U16 *predefined_objects,
        U8 **userdefined_objects,
        S32 *index,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    color c = *(current_MMI_theme->UI_black_color);
    U8 h_flag;

    MMI_disable_title_shortcut_display = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_x = MMI_SMALL_SCREEN_X_OFFSET + 1;
    MMI_title_y = MMI_title_y + MMI_title_height + MMI_SMALL_SCREEN_Y_OFFSET;
    MMI_title_width = UI_device_width - 2 * MMI_SMALL_SCREEN_X_OFFSET - 1;

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 
    hide_status_icon_bar(0);
    
#if (defined(__MMI_FILE_MANAGER__))
    if (object_type & CATEGORY144_FMGR_PREVIEW)
    {
        S32 str_len;
        S32 i;
        S8 buf_filename_no_ext[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

        MMI_disable_title_shortcut_display = 1;
        index = &category_144_object_list_default_index;

        if (predefined_objects == NULL)
        {
            GoBackToHistory(SCR_ID_MSG_EMS_INSERT_OBJECT);
            return;
        }
        else
        {
            S32 errorCode = 0;
            FS_HANDLE emsObjectFilePtr = NULL;
            U32 filesize = 0;
            S8 *filename = (S8*) predefined_objects;

            str_len = mmi_ucs2strlen((S8*) filename);

            /* find file name - by finding "\\" */
            for (i = str_len * 2 - 2; i >= 2; i -= 2)
            {
                if (mmi_ucs2ncmp((PS8) & filename[i], (PS8) L"\\", 1) == 0)
                {
                    i += 2;
                    break;
                }
            }

            mmi_ucs2cpy((PS8) buf_filename_no_ext, (PS8) (&(filename[i])));
            ChangeTitle(title_icon, (PU8) (buf_filename_no_ext));

            userdefined_objects = category_144_data_ptr;
            category_144_file_data = mmi_frm_scrmem_alloc(CAT_144_DATA_FILE_SIZE);
            MMI_ASSERT(category_144_file_data != NULL);
            memset(category_144_file_data, 0, CAT_144_DATA_FILE_SIZE);
            emsObjectFilePtr = FS_Open((WCHAR*) predefined_objects, FS_READ_ONLY);
            if (emsObjectFilePtr > 0)
            {
                FS_GetFileSize(emsObjectFilePtr, &filesize);
                if (filesize > 1600 /* bytes */ )
                {
                    FS_Close(emsObjectFilePtr);
                    userdefined_objects[0] = NULL;
                }
                FS_Read(emsObjectFilePtr, category_144_file_data, filesize, (U32*)&errorCode);
                FS_Close(emsObjectFilePtr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                {
                    userdefined_objects[0] = category_144_file_data;
                }
            }
            else
            {
                userdefined_objects[0] = NULL;
            }
        }
    }
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

    if (!history_buffer)
    {
        associate_small_image_selector(&small_image_selector);
    }
    gdi_layer_lock_frame_buffer();
    initialize_EMS_objects();
    EMS_view_mode = 1;
    category_144_object_file_flag = 0;
    category_144_object_list_flags = object_type;
    category_144_current_object.data = &category_144_current_object_data;
    category_144_autodetect_object_type = 0;

    switch (object_type & 0x0f)
    {
            /* small screen is only applicable to picture and animation */
        case EMS_PREDEFINED_PICTURE:
            category_144_current_object.Type = EMS_TYPE_PIC;
            category_144_object_file_flag = 1;
            break;
        case EMS_USERDEFINED_PICTURE:
            category_144_current_object.Type = EMS_TYPE_PIC;
            category_144_object_file_flag = 1;
            break;
        case EMS_PREDEFINED_ANIMATION:
            category_144_current_object.Type = EMS_TYPE_PREDEF_ANM;
            break;
        case EMS_USERDEFINED_ANIMATION:
            category_144_current_object.Type = EMS_TYPE_USERDEF_ANM;
            category_144_object_file_flag = 1;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    clear_left_softkey();
    clear_right_softkey();
    SetupCategoryKeyHandlers();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);

    MMI_title_icon = get_image(title_icon);
    if (!((object_type & CATEGORY144_FMGR_PREVIEW) && (!(object_type & CATEGORY144_EMAIL_PREVIEW))))
    {
        MMI_title_string = (UI_string_type) title;
    }
    category_144_object_list_index = index;
    category_144_userdefined_objects = userdefined_objects;
    category_144_predefined_objects = predefined_objects;
    h_flag = set_object_list_category_history(MMI_CATEGORY146_ID, history_buffer, category_144_object_list_index);
    if (h_flag)
    {
        *index = *category_144_object_list_index;
    }

    category_144_object_list_n_items = n_items;
    if (*index < 0)
    {
        *index = 0;
    }
    if (*index >= n_items)
    {
        *index = n_items - 1;
    }
    if ((!(object_type & CATEGORY144_DISABLE_PREVIEW)) && (!(object_type & CATEGORY144_FMGR_PREVIEW)))
    {
        register_keyboard_key_handler(small_image_selector_key_handler);
        SetKeyHandler(small_image_selector_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(small_image_selector_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(category_144_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(category_144_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(small_image_selector_goto_previous_row, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(small_image_selector_goto_next_row, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }

    title_bg_id = IMG_FLEXIBLE_TITLEBAR_BG;

    gdi_layer_unlock_frame_buffer();

    if (!(object_type & CATEGORY144_DISABLE_PREVIEW))
    {
        ExitCategoryFunction = ExitSmallImageSelectorScreen;
        dm_setup_category_functions(dm_redraw_category_screen, GetCategory146History, GetCategory144HistorySize);
        dm_register_category_controlled_callback(DrawCate144CategoryControlArea);
        dm_data.s32ScrId = (S32) GetActiveScreenId();
        dm_data.s32CatId = MMI_CATEGORY146_ID;
        dm_data.s32flags = DM_NO_FLAGS;
        dm_add_rectangle(c, DM_RECTANGLE_FILL_GRAYSCALE);
        dm_setup_data(&dm_data);
        dm_register_category_controlled_callback(dm_category_144_controlled_area);
        dm_redraw_category_screen();
    }
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(small_image_selector_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(small_image_selector_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(small_image_selector_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */ 

}
#endif /* UI_SMALL_IMAGE_SELECTOR_SCREEN */ 


/*****************************************************************************
 * FUNCTION
 *  ShowCategory144Screen
 * DESCRIPTION
 *  Displays the object list screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  object_type             [IN]        Object type
 *  n_items                 [IN]        itmes count
 *  object_titles           [IN]        String list of object title
 *  predefined_objects      [IN]        Predefined object file path
 *  is_short_name           [IN]        Is short file name
 *  userdefined_objects     [IN]        User defined object list
 *  index                   [IN]        Index list
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory144Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U32 object_type,
        S32 n_items,
        U8 **object_titles,
        U16 *predefined_objects,
        MMI_BOOL is_short_name,
        U8 **userdefined_objects,
        S32 *index,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 shortcut_width;
    U8 h_flag;

    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_FILE_MANAGER__))
    if (object_type & CATEGORY144_FMGR_PREVIEW)
    {
        S32 str_len;
        S32 i;
        S8 buf_filename_no_ext[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

        MMI_disable_title_shortcut_display = 1;
        index = &category_144_object_list_default_index;

        if (predefined_objects == NULL)
        {
            GoBackToHistory(SCR_ID_MSG_EMS_INSERT_OBJECT);
            return;
        }
        else
        {
            S32 errorCode = 0;
            FS_HANDLE emsObjectFilePtr = NULL;
            U32 filesize = 0;
            S8 *filename = (S8*) predefined_objects;

            str_len = mmi_ucs2strlen((S8*) filename);

            /* find file name - by finding "\\" */
            for (i = str_len * 2 - 2; i >= 2; i -= 2)
            {
                if (mmi_ucs2ncmp((PS8) & filename[i], (PS8) L"\\", 1) == 0)
                {
                    i += 2;
                    break;
                }
            }

            if (is_short_name)
            {
                mmi_chset_mixed_text_to_ucs2_str(
                    (U8*) buf_filename_no_ext,
                    (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
                    (U8*) & filename[i],
                    PhnsetGetDefEncodingType());
            }
            else
            {
                mmi_ucs2cpy((PS8) buf_filename_no_ext, (PS8) (&(filename[i])));
            }

            ChangeTitle(title_icon, (PU8) (buf_filename_no_ext));

            userdefined_objects = category_144_data_ptr;
            category_144_file_data = mmi_frm_scrmem_alloc(CAT_144_DATA_FILE_SIZE);
            MMI_ASSERT(category_144_file_data != NULL);
            memset(category_144_file_data, 0, CAT_144_DATA_FILE_SIZE);
            emsObjectFilePtr = FS_Open((WCHAR*) predefined_objects, FS_READ_ONLY);
            if (emsObjectFilePtr > 0)
            {
                FS_GetFileSize(emsObjectFilePtr, &filesize);
                if (filesize > 1600 /* bytes */ )
                {
                    FS_Close(emsObjectFilePtr);
                    userdefined_objects[0] = NULL;
                }
                FS_Read(emsObjectFilePtr, category_144_file_data, filesize, (U32*)&errorCode);
                FS_Close(emsObjectFilePtr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                {
                    userdefined_objects[0] = category_144_file_data;
                }
            }
            else
            {
                userdefined_objects[0] = NULL;
            }
        }
    }
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

    gdi_layer_lock_frame_buffer();
    initialize_EMS_objects();
    EMS_view_mode = 1;
    category_144_object_file_flag = 0;
    category_144_object_list_flags = object_type;
    category_144_current_object.data = &category_144_current_object_data;
    category_144_autodetect_object_type = 0;

    switch (object_type & 0x0f)
    {
        case EMS_PREDEFINED_PICTURE:
            category_144_current_object.Type = EMS_TYPE_PIC;
            category_144_object_file_flag = 1;
            break;
        case EMS_USERDEFINED_PICTURE:
            category_144_current_object.Type = EMS_TYPE_PIC;
            category_144_object_file_flag = 1;
            break;
        case EMS_PREDEFINED_ANIMATION:
            category_144_current_object.Type = EMS_TYPE_PREDEF_ANM;
            break;
        case EMS_USERDEFINED_ANIMATION:
            category_144_current_object.Type = EMS_TYPE_USERDEF_ANM;
            category_144_object_file_flag = 1;
            break;
        case EMS_PREDEFINED_SOUND:
            category_144_current_object.Type = EMS_TYPE_PREDEF_SND;
            break;

            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)

        case EMS_PREDEFINED_MELODY:
            category_144_current_object.Type = EMS_TYPE_USERDEF_SND;
            category_144_object_file_flag = 1;
            break;
        case EMS_USERDEFINED_MELODY:
            category_144_current_object.Type = EMS_TYPE_USERDEF_SND;
            category_144_object_file_flag = 1;
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */

        default:
            category_144_autodetect_object_type = 1;
            break;
    }

    clear_left_softkey();
    clear_right_softkey();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    MMI_title_icon = get_image(title_icon);
    if (!((object_type & CATEGORY144_FMGR_PREVIEW) && (!(object_type & CATEGORY144_EMAIL_PREVIEW))))
    {
        MMI_title_string = (UI_string_type) title;
    }
    category_144_object_list_index = index;
    category_144_userdefined_objects = userdefined_objects;
    category_144_predefined_objects = predefined_objects;

    h_flag = set_object_list_category_history(MMI_CATEGORY144_ID, history_buffer, category_144_object_list_index);
    if (h_flag)
    {
        *index = *category_144_object_list_index;
    }

    category_144_object_list_n_items = n_items;
    if (*index < 0)
    {
        *index = 0;
    }
    if (*index >= n_items)
    {
        *index = n_items - 1;
    }
    category_144_load_object(*index);
    MMI_menu_shortcut_number = *index + 1;
    category_144_object_list_index = index;
    if ((!(object_type & CATEGORY144_DISABLE_PREVIEW)) && (!(object_type & CATEGORY144_FMGR_PREVIEW)))
    {
        gui_create_vertical_scrollbar(
            &category144_vbar,
            UI_device_width - current_MMI_theme->scrollbar_size,
            (MMI_title_y + MMI_title_height),
            current_MMI_theme->scrollbar_size,
            MMI_content_height);
        register_fixed_list_shortcut_handler();
        shortcut_width = set_menu_item_count(n_items) + 7;
        resize_menu_shortcut_handler(shortcut_width, (MMI_title_height));
        move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
        register_hide_menu_shortcut(draw_title);
        register_keyboard_key_handler(category_144_key_handler);
        register_menu_shortcut_keys();
        register_menu_shortcut_handler(category_144_goto_item);
        SetKeyHandler(category_144_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(category_144_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(category_144_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(category_144_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
    gdi_layer_unlock_frame_buffer();

    if (!(object_type & CATEGORY144_DISABLE_PREVIEW))
    {
        ExitCategoryFunction = ExitCategory144Screen;
        dm_setup_category_functions(dm_redraw_category_screen, GetCategory144History, GetCategory144HistorySize);
        dm_register_category_controlled_callback(DrawCate144CategoryControlArea);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_category_screen_control_area_pen_handlers(category_144_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
        wgui_register_category_screen_control_area_pen_handlers(category_144_pen_up_hdlr, MMI_PEN_EVENT_UP);
        wgui_register_category_screen_control_area_pen_handlers(category_144_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
        wgui_register_category_screen_control_area_pen_handlers(category_144_pen_repeat_hdlr, MMI_PEN_EVENT_REPEAT);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        dm_data.s32ScrId = (S32) GetActiveScreenId();
        dm_data.s32CatId = MMI_CATEGORY144_ID;
        dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_LITE_DISP_WALLPAPER;//071007 ems bg
        dm_setup_data(&dm_data);
        dm_redraw_category_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory144Screen
 * DESCRIPTION
 *  Exits the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory144Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    close_EMS_objects();
    reset_menu_shortcut_handler();
    EMS_view_mode = 0;
    category_144_object_list_index = NULL;
    category_144_object_list_n_items = 0;
    category_144_list_of_titles = NULL;
    category_144_object_list_flags = 0;
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    load_EMS_object_file = NULL;
    
    if (category_144_file_data!=NULL)
    {
        mmi_frm_scrmem_free(category_144_file_data);
        category_144_file_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory144HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for the object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory144HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(object_list_category_history));
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory144History
 * DESCRIPTION
 *  Gets the history buffer for the object list screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory144History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_object_list_category_history(MMI_CATEGORY144_ID, history_buffer, category_144_object_list_index);
    return (history_buffer);
}

#if defined UI_SMALL_IMAGE_SELECTOR_SCREEN


/*****************************************************************************
 * FUNCTION
 *  GetCategory146History
 * DESCRIPTION
 *  Gets the history buffer for the object list screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory146History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_object_list_category_history(MMI_CATEGORY146_ID, history_buffer, category_144_object_list_index);
    return (history_buffer);
}
#endif /* defined UI_SMALL_IMAGE_SELECTOR_SCREEN */ 

EMSObjData EMS_playback_object_data;
EMSObject EMS_playback_object;


/*****************************************************************************
 * FUNCTION
 *  EMSObjectPlayback
 * DESCRIPTION
 *  start object play
 * PARAMETERS
 *  object_type     [IN]        Object type
 *  data            [IN]        Object data
 *  index           [IN]        Object index
 * RETURNS
 *  EMSTATUS EMS function status
 *****************************************************************************/
EMSTATUS EMSObjectPlayback(U32 object_type, U8 *data, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS r = EMS_load_object(object_type, data, index, &EMS_playback_object_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    if (r != EMS_OK)
    {
        return (r);
    }
    EMS_playback_object.data = &EMS_playback_object_data;
    EMS_playback_object.prev = NULL;
    EMS_playback_object.next = NULL;
    EMS_playback_object.OffsetToText = 0;
    EMS_playback_object.PredefNo = (U8) index;
    switch (object_type & 0xff)
    {
        case EMS_PREDEFINED_SOUND:
            EMS_playback_object.Type = EMS_TYPE_PREDEF_SND;
            gui_EMS_playback_object(&EMS_playback_object);
            break;
            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_PREDEFINED_MELODY:
            EMS_playback_object.Type = EMS_TYPE_USERDEF_SND;
            gui_EMS_playback_object(&EMS_playback_object);
            break;
        case EMS_USERDEFINED_MELODY:
            EMS_playback_object.Type = EMS_TYPE_USERDEF_SND;
            gui_EMS_playback_object(&EMS_playback_object);
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
    return (EMS_OK);
}


/*****************************************************************************
 * FUNCTION
 *  EMSObjectStopPlayBack
 * DESCRIPTION
 *  stop object play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMSObjectStopPlayBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
}
#endif /* __MMI_MESSAGES_EMS__ */ 

#define CAT145_SCROLL_DY   20

color cat145_message_title_color;
vertical_scrollbar cat145_vbar;
S32 cat145_h1, cat145_h2, cat145_h3, cat145_total_height, cat145_available_height;
S32 cat145_y = 0, cat145_image_x, cat145_message_title_x;
S32 cat145_clip_x1, cat145_clip_y1, cat145_clip_x2, cat145_clip_y2;
U32 cat145_flags;
U8 cat145_scrollbar_flag = 0;


/*****************************************************************************
 * FUNCTION
 *  cat145_display
 * DESCRIPTION
 *  category 145 redraw
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat145_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y = cat145_y + (MMI_title_y + MMI_title_height) + 2;
    color text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(cat145_clip_x1, cat145_clip_y1, cat145_clip_x2, cat145_clip_y2);
    gdi_image_draw(cat145_image_x, y, (U8*) MMI_message_icon);
    y += cat145_h1 + 2;
    switch (cat145_flags & 0xff)
    {
        case CAT145_BLACK_TITLE:
            text_color = gui_color(0, 0, 0);
            break;

        case CAT145_BLUE_TITLE:
            text_color = gui_color(0, 0, 196);
            break;

        case CAT145_RED_TITLE:
            text_color = gui_color(196, 0, 0);
            break;

        case CAT145_GREEN_TITLE:
            text_color = gui_color(0, 196, 0);
            break;
        default:
            text_color = gui_color(0, 0, 0);
    }
    gui_set_font(&MMI_default_font);
    gui_set_text_color(text_color);
    /* MTK Elvis for R2L characters */
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(cat145_message_title_x + gui_get_string_width((UI_string_type) MMI_message_string), y);
    }
    else
    {
        gui_move_text_cursor(cat145_message_title_x, y);
    }
    /* MTk end */
    gui_print_text(MMI_message_string);
    y += cat145_h2;
    gui_move_multi_line_input_box(&MMI_multiline_inputbox, MMI_multiline_inputbox.x, y);
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  cat145_previous_line
 * DESCRIPTION
 *  change to previous line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat145_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(0, cat145_clip_y1, UI_device_width - 1, cat145_clip_y2);
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->general_background_filler);
    cat145_y += CAT145_SCROLL_DY;
    if (cat145_y > 0)
    {
        cat145_y = 0;
    }
    gui_set_vertical_scrollbar_value(&cat145_vbar, -cat145_y);
    
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
/* under construction !*/
#endif

    if (r2lMMIFlag)
    {
        /* move vertical scrollbar to the left side */
        gui_move_vertical_scrollbar(
                &cat145_vbar, 
                0, 
                cat145_vbar.y);
    }

    gui_show_vertical_scrollbar(&cat145_vbar);

    cat145_display();

    gdi_layer_blt_previous(0, cat145_clip_y1, UI_device_width - 1, cat145_clip_y2);

}


/*****************************************************************************
 * FUNCTION
 *  cat145_next_line
 * DESCRIPTION
 *  change to next line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat145_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(0, cat145_clip_y1, UI_device_width - 1, cat145_clip_y2);
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->general_background_filler);
    cat145_y -= CAT145_SCROLL_DY;
    if (cat145_y < -(cat145_total_height - cat145_available_height))
    {
        cat145_y = -(cat145_total_height - cat145_available_height);
    }
    gui_set_vertical_scrollbar_value(&cat145_vbar, -cat145_y);
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
/* under construction !*/
#endif

    if (r2lMMIFlag)
    {
        /* move vertical scrollbar to the left side */
        gui_move_vertical_scrollbar(
                &cat145_vbar, 
                0, 
                cat145_vbar.y);
    }

    gui_show_vertical_scrollbar(&cat145_vbar);

    cat145_display();

    gdi_layer_blt_previous(0, cat145_clip_y1, UI_device_width - 1, cat145_clip_y2);

}


/*****************************************************************************
 * FUNCTION
 *  cat145_keyboard_key_handler
 * DESCRIPTION
 *  category 145 keypad handler
 * PARAMETERS
 *  vkey_code       [IN]        virtual key code
 *  key_state       [IN]        key state
 * RETURNS
 *  void
 *****************************************************************************/
void cat145_keyboard_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 38:    /* up */
                cat145_previous_line();
                break;
            case 40:    /* down */
                cat145_next_line();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate145CategoryControlArea
 * DESCRIPTION
 *  Draws the category145 category control area
 * PARAMETERS
 *  coordinate      [IN]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate145CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RedrawCategory145Screen();
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory145Screen
 * DESCRIPTION
 *  Redraws the Delivery report screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory145Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat145_scrollbar_flag)
    {
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
/* under construction !*/
#endif

        if (r2lMMIFlag)
        {
            /* move vertical scrollbar to the left side */
            gui_move_vertical_scrollbar(
                    &cat145_vbar, 
                    0, 
                    cat145_vbar.y);
        }

        gui_show_vertical_scrollbar(&cat145_vbar);
    }
    cat145_display();
}


/*****************************************************************************
 * FUNCTION
 *  ChangeCategory145MessageString
 * DESCRIPTION
 *  Change category 145 string.
 * PARAMETERS
 *  new_string      [IN]     string to change
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeCategory145MessageString(U8 *new_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.text = (UI_buffer_type) new_string;
    MMI_multiline_inputbox.cursor_p = new_string;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory145Screen
 * DESCRIPTION
 *  Displays the Delivery report screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  message_icon            [IN]        Icon displayed with the message
 *  message_title           [IN]        Colored text that appears above the message
 *  message                 [IN]        Message
 *  flags                   [IN]        Flags
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory145Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 message_icon,
        U8 *message_title,
        U8 *message,
        U32 flags,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 l, width, height, content_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    cat145_scrollbar_flag = 0;
    gui_create_vertical_scrollbar(
        &cat145_vbar,
        UI_device_width - current_MMI_theme->scrollbar_size,
        (MMI_title_y + MMI_title_height),
        current_MMI_theme->scrollbar_size,
        (UI_device_height - (MMI_title_y + MMI_title_height) - MMI_button_bar_height + 1));
    content_width = UI_device_width;
    l = gui_strlen((UI_string_type) message);
    create_multiline_inputbox_set_buffer((UI_string_type) message, l, l, 0);
    resize_multiline_inputbox(content_width, MMI_content_height);
    show_multiline_inputbox_no_draw();
    resize_multiline_inputbox(MMI_multiline_inputbox.width, MMI_multiline_inputbox.text_height + 6);
    cat145_h3 = MMI_multiline_inputbox.height;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR
        | UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY;
    MMI_multiline_inputbox.normal_text_color = gui_color(0, 0, 0);

    MMI_message_string = (UI_string_type) message_title;
    gui_set_font(&MMI_default_font);
    gui_measure_string(MMI_message_string, &width, &height);
    cat145_h2 = height;
    cat145_message_title_x = (content_width >> 1) - (width >> 1);
    MMI_title_string = (UI_string_type) title;
    MMI_title_icon = (PU8) get_image(title_icon);

    MMI_message_icon = (PU8) get_image(message_icon);
    gui_measure_image(MMI_message_icon, &width, &height);
    cat145_h1 = height + 4;
    cat145_image_x = (content_width >> 1) - (width >> 1);

    cat145_flags = flags;
    cat145_y = 0;
    cat145_clip_x1 = 0;
    cat145_clip_x2 = content_width;
    cat145_clip_y1 = (MMI_title_y + MMI_title_height);
    cat145_clip_y2 = UI_device_height - MMI_button_bar_height - 1;
    cat145_total_height = (cat145_h1 + cat145_h2 + cat145_h3);
    cat145_available_height = cat145_clip_y2 - cat145_clip_y1 + 1;
    if (cat145_total_height > cat145_available_height)
    {
        cat145_scrollbar_flag = 1;
        register_keyboard_key_handler(cat145_keyboard_key_handler);
        SetKeyHandler(cat145_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(cat145_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(cat145_previous_line, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(cat145_next_line, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        gui_set_vertical_scrollbar_range(&cat145_vbar, cat145_total_height);
        gui_set_vertical_scrollbar_scale(&cat145_vbar, cat145_available_height);
        gui_set_vertical_scrollbar_value(&cat145_vbar, -cat145_y);
    }
    else
    {
        cat145_y = (cat145_available_height >> 1) - (cat145_total_height >> 1);
    }

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory145Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    dm_register_category_controlled_callback(DrawCate145CategoryControlArea);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY145_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory145Screen
 * DESCRIPTION
 *  Exits the Delivery report screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory145Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat145_scrollbar_flag = 0;
    reset_softkeys();
    reset_multiline_inputbox();
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory145HistorySize
 * DESCRIPTION
 *  Gets the size of the history buffer for the Delivery report screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory145HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory145History
 * DESCRIPTION
 *  Gets the history buffer for the Delivery report screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  Pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory145History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (history_buffer);
}


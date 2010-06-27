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
 * widget_paint.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget paint
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
#include "TimerEvents.h"
#include "wgui_categories.h"
#include "EventsDcl.h"  /* ShutdownSystemOperation */
#include "L4Dr.h"
#include "gui.h"        /* UI_cross_hatch_fill_rectangle */
#include "gui_themes.h"
#include "StatusIconRes.h"
#include "wgui_status_icons.h"
#include "gui_scrollbars.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "TouchScreenGprot.h"
#include "wgui_touch_screen.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 
#include "wgui_softkeys.h"
#include "gpio/gpioInc/GPIOInc.h"				/* Vibration/Backlight */
#include "ProfileGprots.h"

#include "mdi_datatype.h"
#include "mdi_video.h"

extern void mmi_phnset_disable_partial_ss(void);
extern void mmi_phnset_enable_partial_ss(void);

extern icontext_button MMI_softkeys[];

/****************************************************************
 paint system
 ***************************************************************/

/////////////////////////////////////////////////////////////////////////////////////
// global variables
/////////////////////////////////////////////////////////////////////////////////////

/* previous focus candidate gadget position/size */
widget_header_struct *widget_prev_keyfocus;
MsfPosition widget_prev_widget_position;
MsfSize widget_prev_widget_size;

/* next focus candidate gadget position/size */
widget_header_struct *widget_next_keyfocus;
MsfPosition widget_next_widget_position;
MsfSize widget_next_widget_size;

/* current focused gadget position/size */
static MsfPosition widget_current_widget_position;
static kal_bool widget_current_widget_position_is_set;

/* currently, the min/max size of paintbox content */
int widget_min_x;
int widget_min_y;
int widget_max_x;
int widget_max_y;

extern BOOL r2lMMIFlag;

#ifndef __MTK_TARGET__


/*****************************************************************************
 * FUNCTION
 *  widget_dump_hex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf     [IN]         
 *  len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_dump_hex(unsigned char *buf, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (pos = 0; pos < len; pos += 16)
    {
        printf("%06d  ", pos);
        for (i = 0; i < 16; i++)
            if (pos + i < len)
            {
                printf(" %02x", buf[pos + i]);
            }
            else
            {
                printf("   ");
            }

        printf("  ");

        for (i = 0; i < 16; i++)
            if (pos + i < len)
            {
                unsigned char c = buf[pos + i];

                if (32 <= c && c <= 126)
                {
                    printf("%c", c);
                }
                else
                {
                    printf(".");
                }
            }

        printf("\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_show_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_show_info(widget_header_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (_H(handle)->data_type)
    {
        case WIDGET_STYLE_TYPE:
            printf("STYLE");
            break;
        case WIDGET_IMAGE_TYPE:
            printf("IMAGE");
            switch (_IMG(handle)->image_format)
            {
                case MsfPbmPI:
                    printf("(PBM)");
                    break;
                case MsfAbmPI:
                    printf("(ABM)");
                    break;
                case MsfGifPI:
                    printf("(GIF_PI)");
                    break;
                case MsfBmpPI:
                    printf("(BMP_PI)");
                    break;
                case MsfJpegPI:
                    printf("(JPEG_PI)");
                    break;
                case MsfPngPI:
                    printf("(PNG_PI)");
                    break;
                case MsfGif:
                    printf("(GIF)");
                    break;
                case MsfBmp:
                    printf("(BMP)");
                    break;
                case MsfWbmp:
                    printf("(WBMP)");
                    break;
                case MsfJpeg:
                    printf("(JPG)");
                    break;
                case MsfPng:
                    printf("(PNG)");
                    break;
                case MsfPictogram:
                    printf("(PIC)");
                    break;
            }
            if (_IMG(handle)->is_done)
            {
                printf("DONE");
            }
            break;
        case WIDGET_ROOT_TYPE:
            printf("ROOT");
            break;
        case WIDGET_SCREEN_TYPE:
            printf("SCREEN");
            break;
        case WIDGET_STRING_TYPE:
            printf("STRING");
            break;
        case WIDGET_PRE_STRING_TYPE:
            printf("PRE_STRING");
            break;
        case WIDGET_PRE_IMAGE_TYPE:
            printf("PRE_IMAGE");
            break;
        case WIDGET_CHOICE_ELEMENT_TYPE:
            printf("CHOICE_ELEMENT");
            break;
        case WIDGET_ACTION_TYPE:
            printf("ACTION");
            break;
        case WIDGET_SOUND_TYPE:
            printf("SOUND");
            break;
        case WIDGET_RAW_DATA_TYPE:
            printf("RAW_DATA");
            break;
        case WIDGET_PAINTBOX_TYPE:
            printf("PAINTBOX");
            if (_P(handle)->flag & WIDGET_FLAG_HAS_FOCUS)
            {
                printf("[FOCUS]");
            }
            break;
        case WIDGET_FORM_TYPE:
            printf("FORM");
            break;
        case WIDGET_DIALOG_TYPE:
            printf("DIALOG");
            break;
        case WIDGET_MENU_TYPE:
            printf("MENU");
            break;
        case WIDGET_EDITOR_TYPE:
            printf("EDITOR");
            break;
        case WIDGET_CTK_TYPE:
            printf("CTK");
            break;
        case WIDGET_ICON_TYPE:
            printf("ICON");
            break;
        case WIDGET_GADGET_STRING_TYPE:
            printf("GADGET_STRING");
            break;
        case WIDGET_GADGET_SELECT_GROUP_TYPE:
            printf("GADGET_SELECT_GROUP");
            break;
        case WIDGET_GADGET_IMAGE_TYPE:
            printf("GADGET_IMAGE ");
            break;
        case WIDGET_GADGET_DATE_TYPE:
            printf("GADGET_DATE");
            break;
        case WIDGET_GADGET_BAR_TYPE:
            printf("GADGET_BAR");
            break;
        case WIDGET_GADGET_INPUT_TYPE:
            printf("GADGET_INPUT");
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_show_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_show_action(widget_action_struct *action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action->action_mask)
    {
        case (1 << MsfHelp):
            printf("MsfHelp\t");
            break;
        case (1 << MsfBack):
            printf("MsfBack\t");
            break;
        case (1 << MsfCancel):
            printf("MsfCancel\t");
            break;
        case (1 << MsfStop):
            printf("MsfStop\t");
            break;
        case (1 << MsfExit):
            printf("MsfExit\t");
            break;
        case (1 << MsfMenu):
            printf("MsfMenu\t");
            break;
        case (1 << MsfSelect):
            printf("MsfSelect\t");
            break;
        case (1 << MsfOk):
            printf("MsfOk\t");
            break;
    }
}

#define if_print_bit(V,O,X)            \
   if( O & (1<<X) ) printf("[");       \
   if( V & (1<<X) ) {printf( #X " " );}\
   if( O & (1<<X) ) printf("]");


/*****************************************************************************
 * FUNCTION
 *  widget_show_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_show_event(widget_window_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int E = handle->event_mask;
    int O = handle->event_override;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    printf("Event:");
    if_print_bit(E, O, MsfKey_0);
    if_print_bit(E, O, MsfKey_1);
    if_print_bit(E, O, MsfKey_2);
    if_print_bit(E, O, MsfKey_3);
    if_print_bit(E, O, MsfKey_4);
    if_print_bit(E, O, MsfKey_5);
    if_print_bit(E, O, MsfKey_6);
    if_print_bit(E, O, MsfKey_7);
    if_print_bit(E, O, MsfKey_8);
    if_print_bit(E, O, MsfKey_9);
    if_print_bit(E, O, MsfKey_Star);
    if_print_bit(E, O, MsfKey_Pound);
    if_print_bit(E, O, MsfKey_Up);
    if_print_bit(E, O, MsfKey_Down);
    if_print_bit(E, O, MsfKey_Left);
    if_print_bit(E, O, MsfKey_Right);
    if_print_bit(E, O, MsfKey_Select);
    if_print_bit(E, O, MsfKey_Clear);
    if_print_bit(E, O, MsfKey_Yes);
    if_print_bit(E, O, MsfKey_No);
    if_print_bit(E, O, MsfKey_Menu);
    if_print_bit(E, O, MsfKey_Soft1);
    if_print_bit(E, O, MsfKey_Soft2);
    if_print_bit(E, O, MsfKey_Soft3);
    if_print_bit(E, O, MsfKey_Soft4);
    if_print_bit(E, O, MsfKey_Function1);
    if_print_bit(E, O, MsfKey_Function2);
    if_print_bit(E, O, MsfKey_Function3);
    if_print_bit(E, O, MsfKey_Function4);
    if_print_bit(E, O, MsfPointer);

    printf("\n");
}
#endif /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  widget_paint_display_clipping_region
 * DESCRIPTION
 *  Get the display clipping region. We should not overlap paintbox scrollbar in browser.
 *  
 *  It implies that widget screen will be repainted if scrollbars appear or disappear
 *  
 *  Note: WGUI->current_vertical_scrollbar is set after gadget bars are painted,
 *  Case1: this function is invoked in widget_paint_hdlr before gadget bars are painted
 *  => we do not know the bar size yet, however, the overlaped region with scrollbars
 *  will be erased after the scrollbars are painted
 *  Case 2: this function is invoked after gadget bars are painted
 *  => we should set clipping region according to the size and position of scrollbar
 * PARAMETERS
 *  x1      [OUT]       Left
 *  y1      [OUT]       Top
 *  x2      [OUT]       Right
 *  y2      [OUT]       Bottom
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_display_clipping_region(int *x1, int *y1, int *x2, int *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x1 = WGUI_CTX->display_pos.x;
    *x2 = WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width - 1;
    *y1 = WGUI_CTX->display_pos.y;
    *y2 = WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height - 1;
    if (WGUI_CTX->in_paintbox)
    {
        if (WGUI_CTX->current_vertical_scrollbar)
        {
            *x2 -= WGUI_CTX->current_vertical_scrollbar->size.width;
        }

        if (WGUI_CTX->current_horizontal_scrollbar)
        {
            *y2 -= WGUI_CTX->current_horizontal_scrollbar->size.height;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_set_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_set_title(MsfStringHandle h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    void *src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen);  /* We should not set title outside of widget screen */

    src = widget_string_content(h);
    len = widget_string_length(h);
    if (len > WIDGET_MAX_TITLE_LEN)
    {
        len = WIDGET_MAX_TITLE_LEN;
    }

    if (src)
    {
        memcpy((void*)WGUI_CTX->title_buffer, src, len * 2);
    }
    else
    {
        len = 0;
    }

    WGUI_CTX->title_buffer[len] = 0;

    MMI_title_string = (UI_string_type) WGUI_CTX->title_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  widget_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]     
 *  pos         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_clear(MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;
    gui_push_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_fill_rectangle(pos->x, pos->y, pos->x + size->width, pos->y + size->height, c);
    gui_pop_clip();

    /* no blit double buffer */
}

/* widget_set_current_object is invoked on passive focus */


/*****************************************************************************
 * FUNCTION
 *  widget_set_current_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_set_current_object(widget_header_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!obj)
    {
        return;
    }

    if (IS_GADGET_TYPE(obj))
    {
        WGUI_CTX->current_focused_gadget = obj;
        return; /* Keep WGUI_CTX->in_paintbox & WGUI_CTX->in_editor unchanged */
    }

    if (IS_SCREEN_TYPE(obj))
    {
        switch (obj->module_id)
        {
            case MSF_MODID_MEA:
            case MSF_MODID_MMS:
            case MSF_MODID_SMA:
            case MSF_MODID_SLS:
                WGUI_CTX->MMS_screen_is_active = 1;
                break;
            default:
                WGUI_CTX->MMS_screen_is_active = 0;
                break;
        }
        return; /* Keep WGUI_CTX->in_paintbox & WGUI_CTX->in_editor unchanged */
    }

    if (!IS_WINDOW_TYPE(obj))   /* Not gadget nor screen */
    {
        WAP_DBG_ASSERT(0);
    }

    /* Obj is a window or screen now (not gadget) */
    WGUI_CTX->in_paintbox = 0;
    WGUI_CTX->in_editor = 0;

    if (IS_CTK_TYPE(obj))
    {
        widget_prepare_to_enter_ctk_window(_CTK(obj));
    }
    else if (IS_PAINTBOX_TYPE(obj))
    {
        WGUI_CTX->in_paintbox = 1;
        WGUI_CTX->current_focused_paintbox = _P(obj);
        enable_bit_flag(obj->flag, WIDGET_FLAG_HAS_FOCUS);
    }
    else if (IS_EDITOR_TYPE(obj))
    {
        WGUI_CTX->in_editor = 1;
    }

    /* Example. The SEC dialog shows and disappears, we need to restore the busy flag */
    if (IS_WINDOW_TYPE(obj) && !IS_SCREEN_TYPE(obj))
    {
        if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY)
        {
            if (!(_W(obj)->property_mask & MSF_WINDOW_PROPERTY_BUSY))
            {
                widget_disable_status_bar(WIDGET_STATUS_BAR_BUSY);
            }
        }
        else
        {
            if (_W(obj)->property_mask & MSF_WINDOW_PROPERTY_BUSY)
            {
                widget_enable_status_bar(WIDGET_STATUS_BAR_BUSY);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_add_widget_screen_in_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_add_widget_screen_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = WAP_SCREEN_WIDGET;
    currHistory.entryFuncPtr = wap_entry_widget_screen;
    SET_CHR_AT(currHistory.inputBuffer, 0, 0);
    GetCategoryHistory (currHistory.guiBuffer);
    AddHistory (currHistory);
}

/* widget_set_current_focus is invoked on active focus */


/*****************************************************************************
 * FUNCTION
 *  widget_set_current_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj             [IN]         
 *  has_focus       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_set_current_focus(widget_header_struct *obj, kal_bool has_focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!obj)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    /* we don't use widget_resume_screen here in order to increment WGUI_CTX->current_screen_level */
    if (!WGUI_CTX->is_widget_screen)
    {
        if (IS_WINDOW_TYPE(obj) && wap_status == WAP_RUNNING && !WGUI_CTX->is_shutdown_UI)
        {
            WGUI_CTX->tried_to_enter_widget_screen = 1;
        }

        /*
         * If we allow to goto widget screen when another widget screen is paused.
         * It will cause a lot of problems. For example:
         * 1. widget->CTK->widget->CTK
         * 2. widget (BRA)->MO call->widget (error dialog) .
         *
         * Reference Chicago #631:
         * BRAif_destroyUI and MEA UI termination might invoke HDIa_widgetSetInFocus(),
         * but we do not want to goto widget screen when the WAP UI is terminating.
         * (The focused window might be destroyed immediately)
         *
         */
        // TODO: maybe it is not necesssary to check WGUI_CTX->current_screen_level at all !
        if (IS_WINDOW_TYPE(obj) &&                  /* We don't check IS_SCREEN_TYPE() because MsfScreen are resident */
            /* It should never overlap MO/MT screen. If CSD call is active after WAP out-of-memory, we should allow enter widget screen */
            (WGUI_CTX->current_screen_level == 0    /* Widget screen not paused in history. Should we set this if WAP reset. XXX */
             || !IsScreenPresent(WAP_SCREEN_WIDGET)) &&
            wap_status == WAP_RUNNING && !WGUI_CTX->is_shutdown_UI && !mmi_shutdown_is_in_power_off_period())
        {
            if (!IsScreenPresent(WAP_SCREEN_WIDGET))
            {
                /* Certain MMI applications might delete previous history of widget in wrong way */
                WGUI_CTX->current_screen_level = 0; /* Redundant. Set by wap_entry_widget_screen */
            }

            if (WIPC_CTX->wait_message_notification_in_idle_screen)
                /* If MMI is blocked, we should not enter widget screen here */
            {
                WIPC_CTX->pending_to_enter_widget_screen = 1;
            }
            else
            {
                if (WGUI_CTX->who_want_to_enter_widget_screen != 0 && 
                    WGUI_CTX->who_want_to_enter_widget_screen != WIDGET_VIRTUAL_SCREEN_ID &&
                    WGUI_CTX->who_want_to_enter_widget_screen != GetExitScrnID())
                {
                    /*
                     * Someone want to enter the widget screen, but the interrupt occurs.
                     * We add the widget screen in the history.
                     */
                    widget_execute_MMI(widget_MMI_add_widget_screen_in_history, KAL_FALSE);
                    WGUI_CTX->who_want_to_enter_widget_screen = WIDGET_VIRTUAL_SCREEN_ID;
                }
                else
                {
                #ifndef __UNIFIED_MSG_SUPPORT__
    				if (widget_check_no_call_or_wap_call())
                #endif /* __UNIFIED_MSG_SUPPORT__ */
    				{
    				    /* 
    				     * It should never overlap MO/MT screen. 
    				     * If CSD call is active after WAP out-of-memory, we should allow enter widget screen 
    				     */
    					widget_execute_MMI(widget_MMI_entry_new_screen_with_check, KAL_TRUE);
    				}
                }
            } /* if (WIPC_CTX->wait_message_notification_in_idle_screen) */
        }
    }

    /*
     * For screens that will put widget into History and go to new category screen, 
     * we set special flag on here (HDIa_widgetSetFocus),
     * and we only go to new category screen if these flags are set
     *
     * FIXME move to widget_set_current_object
     */

    /* 
     * If it goes back to widget screen from full-screen editor, WEDITOR_CTX->current_state is 
     * FULLSCREEN_EDITOR_RETURN_DONE or FULLSCREEN_EDITOR_RETURN_CANCEL
     *
     * wap_entry_widget_screen() invokes widget_paintbox_redraw(), which 
     * might set focus to the input gadget again. we should not override the value of WEDITOR_CTX->current_state
     */
    if ((IS_GADGET_INPUT_TYPE(obj) || IS_EDITOR_TYPE(obj)) &&
        (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_NONE))
    {
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_WANT_EXECUTE;
    }

    if (IS_GADGET_SELECT_GROUP_TYPE(obj) && !IS_WINDOW_TYPE(obj)        /* gadget */
        && (_M(obj)->choice_type == MsfExclusiveChoice || _M(obj)->choice_type == MsfMultipleChoice)
        && WENTER_MENU_CTX->state == WIDGET_ENTER_MENU_NONE)
    {
        widget_init_fullscreen_menu();
        WENTER_MENU_CTX->target_menu = _M(obj);
        WENTER_MENU_CTX->state = WIDGET_ENTER_MENU_PREPARE_TO_ENTER;
    }

    /*
     * For direct paint mode, 
     */
    if (WGUI_CTX->in_paintbox)
    {
        if (WIDGET_WANT_FOCUS_LIST & (1 << obj->data_type))
        {
            /*
             * If paintbox is defocused, then it's active child will get focus 
             * * because our rule is the active child (first added child) will be focused if the parent is focused
             * * but we don't want the first child gadget in paintbox automatically get focused.
             */
            if (IS_PAINTBOX_TYPE(obj))
            {
                set_bit_flag(WGUI_CTX->current_focused_paintbox->flag, WIDGET_FLAG_HAS_FOCUS, has_focus);
            }
            else
            {
                set_bit_flag(WGUI_CTX->current_focused_paintbox->flag, WIDGET_FLAG_HAS_FOCUS, !has_focus);
            }
            widget_paint();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_clear_keyfocus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_clear_keyfocus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* widget_curr_keyfocus= */
    widget_prev_keyfocus = widget_next_keyfocus = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_register_keyfocus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_register_keyfocus(widget_header_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->in_paintbox)
    {
        if (WGUI_CTX->current_focused_paintbox->flag & WIDGET_FLAG_HAS_FOCUS)
        {
            return KAL_FALSE;
        }

        /* Set paintbox as the previous and next object to focus */
        widget_prev_keyfocus = widget_next_keyfocus = _H(WGUI_CTX->current_focused_paintbox);

        if (handle == WGUI_CTX->current_focused_gadget)
        {
            /* widget_curr_keyfocus = handle; */
            return KAL_TRUE;
        }
        else    /* For example: two inputboxs in a paintbox at the same time */
        {
            return KAL_FALSE;
        }
    }
    else
    {
        if (handle == WGUI_CTX->current_focused_gadget)
        {
            return KAL_TRUE;
        }
        else    /* For example: two inputboxs in a paintbox at the same time */
        {
            return KAL_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_position_compare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ax      [IN]        
 *  ay      [IN]        
 *  bx      [IN]        
 *  by      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_position_compare(int ax, int ay, int bx, int by)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ay == by)
    {
        return ax - bx;
    }
    else
    {
        return ay - by;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_reset_used_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_reset_used_range(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_current_widget_position_is_set = KAL_FALSE;

    widget_max_x = -10000;
    widget_max_y = -10000;
    widget_min_x = 10000;
    widget_min_y = 10000;

    widget_prev_widget_position.x = -10000;
    widget_prev_widget_position.y = -10000;

    widget_next_widget_position.x = 10000;
    widget_next_widget_position.y = 10000;
}

/*
 * Only when !WGUI_CTX->in_paintbox 
 * * Input arguments x1, y1, x2, y2 are absolute coordinate on the device screen.
 */


/*****************************************************************************
 * FUNCTION
 *  widget_record_used_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h                   [IN]         
 *  is_want_focus       [IN]        
 *  is_focus            [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_record_used_range(
        widget_header_struct *h,
        kal_bool is_want_focus,
        kal_bool is_focus,
        int x1,
        int y1,
        int x2,
        int y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->in_paintbox)
    {
        return;
    }

    /* 20040226. Tmp check. To remove  in the future */
    // TODO: menu window (not 'gadget') do not need to record used region
    if (!widget_form_gadget_want_focus(h) && !IS_MENU_TYPE(h) && is_want_focus)
    {
        WAP_DBG_ASSERT(0);
        is_want_focus = KAL_FALSE;
    }

    if (widget_max_x < x2)
    {
        widget_max_x = x2;
    }
    if (widget_min_x > x1)
    {
        widget_min_x = x1;
    }

    if (widget_max_y < y2)
    {
        widget_max_y = y2;
    }
    if (widget_min_y > y1)
    {
        widget_min_y = y1;
    }

    if (is_want_focus)  // TODO: I don't understand the code
    {
        if (is_focus)   /* always the first one component */
        {
            widget_current_widget_position.x = x1;
            widget_current_widget_position.y = y1;
            widget_current_widget_position_is_set = KAL_TRUE;
        }
        else if (widget_current_widget_position_is_set) // TODO: It is WRONG if the focused gadget is not the first one and widget_paint is invoked for only one time
        {
            if (widget_position_compare(widget_current_widget_position.x, widget_current_widget_position.y, x1, y1) > 0)
            {
                /* upside component */
                if (widget_position_compare(
                        widget_prev_widget_position.x,
                        widget_prev_widget_position.y,
                        x1,
                        y1) < 0
                    && WGUI_CTX->display_pos.x <= x1 && WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width >= x1)
                {
                    widget_prev_widget_position.x = x1;
                    widget_prev_widget_position.y = y1;
                    widget_prev_widget_size.width = x2 - x1;
                    widget_prev_widget_size.height = y2 - y1;
                    widget_prev_keyfocus = h;
                }
            }
            else
            {
                /* downside component */
                if (widget_position_compare(
                        widget_next_widget_position.x,
                        widget_next_widget_position.y,
                        x1,
                        y1) > 0
                    && WGUI_CTX->display_pos.x <= x1 && WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width >= x1)
                {
                    widget_next_widget_position.x = x1;
                    widget_next_widget_position.y = y1;
                    widget_next_widget_size.width = x2 - x1;
                    widget_next_widget_size.height = y2 - y1;
                    widget_next_keyfocus = h;
                }
            }
        }
    }
}

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
/* store the image id of wallpaper */


/*****************************************************************************
 * FUNCTION
 *  widget_paint_wallpaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_bool        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_paint_wallpaper(kal_bool is_drawn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img;
    S8 fname[100] = {0};
    S8 *pfn = fname;
    S32 x, y;
    U8 opacity;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_drawn)
    {
        if (WGUI_CTX->current_video != NULL &&
            (WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING ||
             WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD))
        {
            /* If playing the video in MMS viewer, we should not allow to set wallpaper. */
            return;
        }

        /* only get the opacity */
        dm_get_scr_bg_image(&img, &pfn, &x, &y, &opacity);

        gdi_layer_multi_layer_enable();
        gdi_layer_get_base_handle(&wgui_base_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        if (wgui_layer_1 == (gdi_handle) NULL)
        {
            ret = gdi_layer_create(0, 0, UI_device_width, UI_device_height, &wgui_layer_1);
            /* Create layer fail */
            if (ret < 0)
            {
                return;
            }
        }

        gdi_layer_push_and_set_active(wgui_layer_1);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_image_abm_set_source_layer(wgui_layer_1);
        gdi_layer_set_opacity(TRUE, (U8)(current_MMI_theme->bg_opacity_full));
        gdi_layer_clear(GDI_COLOR_WHITE);

	    /* refer the function dm_draw_scr_bg_image() */
	    gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, gdi_layer_get_background());
	    gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);

        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(wgui_layer_1, wgui_base_layer, 0, 0);
        wgui_set_wallpaper_on_bottom(MMI_TRUE);
    #if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
        gui_set_transparent_source_layer(wgui_layer_1); /* 110705 WAP menu Calvin added */
    #endif 

    }
    else
    {

        gdi_layer_get_base_handle(&wgui_base_layer);
        gdi_image_abm_set_source_layer(wgui_base_layer);
        if (WGUI_CTX->current_video == NULL)
        {
            /* If playing the video in MMS viewer, we should not allow to set wallpaper. */
            gdi_layer_set_blt_layer(wgui_base_layer, 0, 0, 0);
        }

        wgui_set_wallpaper_on_bottom(MMI_FALSE);
    }
}
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ /* #ifdef __MMI_WALLPAPER_ON_BOTTOM__ */


/*****************************************************************************
 * FUNCTION
 *  widget_paint_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]     
 *  size        [IN]     
 *  pos         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_paint_object(widget_header_struct *handle, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int paint_level = -1;    /* only for MNT display tabs */
    kal_uint8 is_draw_child = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

    if (!handle)
    {
        return; /* null pointer should not be processed. */
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OBJECT);

    paint_level++;

    WAP_DBG_ASSERT(widget_check_object_validity(handle));

    /* ////////////////////////////////////////////////////////// */
    /* Draw itself */

    /* Draw title of current active window */
    if (IS_WINDOW_TYPE(handle))
    {
        /* show title */
        if (_W(handle)->property_mask & MSF_WINDOW_PROPERTY_TITLE)
        {
            if (_W(handle)->title)
            {
                widget_set_title(_W(handle)->title);
            }
        }
        if (IS_DIALOG_TYPE(handle) && 
             (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_DONE ||
              WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_CANCEL))
        {
            /*
             * When the user finish the inputbox of the dialog (goback from the fullscreen editor),
             * we will back to the browser (paintbox in widget screen).
             * Because MsfDialog doesn't have the title, we use the previous paintbox's title.
             */
            if (WGUI_CTX->current_focused_paintbox->title)
            {
                widget_set_title(WGUI_CTX->current_focused_paintbox->title);
            }
        }
        if (_W(handle)->property_mask & MSF_WINDOW_PROPERTY_EXT_STATUS_ICON)
        {
            WAP_DBG_ASSERT(IS_DIALOG_TYPE(handle)); /* Restricted to MsfDialog */
            widget_setup_status_icons();
        }
    }

    switch (_H(handle)->data_type)
    {
        case WIDGET_PAINTBOX_TYPE:
            /*
             * Note that we do not clear background since that text is drawn with HDIa_widgetDrawXXX
             * * If returned from another MMI screen, widget_paintbox_redraw() in wap_entry_widget_screen
             */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OBJECT_PAINTBOX);
            WGUI_CTX->in_form = 0;
        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            widget_paint_wallpaper(KAL_FALSE);
        #endif 

            /*
             * We need to disable source key before browsing the page, 
             * or the text will be transparent (can't be watched)
             */
            gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);

            /* reset the widget volume value from the profile setting */
            WSND_CTX->volume = GetRingVolumeLevel();
            break;
        case WIDGET_FORM_TYPE:
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OBJECT_FORM);
        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            widget_paint_wallpaper(KAL_FALSE);
        #endif 

    #ifdef WIDGET_SLIDING_SMIL_SUPPORT
            {
                widget_sliding_info_struct *sliding_info = _FORM(handle)->sliding_info;

                if (sliding_info)
                {
                    if (sliding_info->restore_scroll_offset_before_paint)
                    {
                        pos->y = WGUI_CTX->current_pos.y = sliding_info->scroll_offset_backup;
                        sliding_info->restore_scroll_offset_before_paint = 0;
                        sliding_info->scroll_offset_backup = 0;
                    }
                }
            }
    #endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 
            /*
             * We need to disable source key in play MMS SMIL because if the
             * number in MMS, applications can foucus them
             */
            gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
            
            /* reset the widget volume value from the profile setting */
            WSND_CTX->volume = GetRingVolumeLevel();

            widget_paint_form(_FORM(handle), size, pos);
            break;
        case WIDGET_EDITOR_TYPE:
            /* Enter another MMI screen, unnecessary to clear screen */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OBJECT_EDITOR);
        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            widget_paint_wallpaper(KAL_TRUE);
        #endif 
            widget_paint_editor(_EDITOR(handle), size, pos);
            break;
        case WIDGET_DIALOG_TYPE:
            /* Do not clear screen to retain the previous display content unless status icons are displayed */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OBJECT_DIALOG);
            if (_W(handle)->property_mask & MSF_WINDOW_PROPERTY_EXT_STATUS_ICON)
            {
                clear_screen();
            }
            else if (_DIALOG(handle)->dialog_type == MsfPrompt &&
                     (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_DONE ||
                      WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_CANCEL))
            {
                /* Back to MsfDialog and send the action event */
                break;
            }
            else    /* if (_DIALOG(handle)->dialog_type == MsfConfirmation) */
            {
                /* Reference: RedrawCategory164Screen */
                WGUI_CTX->last_screen_is_dialog = 1;
                gdi_layer_flatten_previous_to_base();
                gui_push_clip();
                gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
                gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, MMI_BG_GREYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE); /* 102605 greyscale Calvin modified */
                gui_pop_clip();
            #ifdef WIDGET_RESIDENT_STATUS_ICON
                /* Otherwise, animated status icons will redraw status icon pane again */
                if (!WGUI_CTX->dialog_with_hatch_background)
                {
                    WGUI_CTX->dialog_with_hatch_background = 1;
                    close_title_status_icon();
                }
            #endif /* WIDGET_RESIDENT_STATUS_ICON */ 
            }

        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            widget_paint_wallpaper(KAL_FALSE);
        #endif 

            widget_paint_dialog(_DIALOG(handle), size, pos);
            break;
        case WIDGET_MENU_TYPE:
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OBJECT_MENU);
        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            widget_paint_wallpaper(KAL_TRUE);
        #endif 
            widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);
            widget_paint_menu(_M(handle), size, pos);
            is_draw_child = 0;
            break;
        case WIDGET_CTK_TYPE:
            /* Enter another MMI screen , unnecessary to clear screen */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OBJECT_CTK);
        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            widget_paint_wallpaper(KAL_FALSE);
        #endif 

            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            widget_paint_ctk(_CTK(handle));
            break;
        case WIDGET_GADGET_IMAGE_TYPE:
            widget_paint_gadget_image(_GIMG(handle), size, pos);
            is_draw_child = 0;
            break;
        case WIDGET_GADGET_SELECT_GROUP_TYPE:
            widget_paint_menu(_M(handle), size, pos);
            is_draw_child = 0;
            break;
        case WIDGET_GADGET_BAR_TYPE:
            /*
             * In direct_paint_mode, delay the painting of scrollbar to widget_paint_outside_look 
             */
            widget_paint_gadget_bar(_GBAR(handle), size, pos, WGUI_CTX->in_paintbox ? KAL_FALSE : KAL_TRUE);
            is_draw_child = 0;
            break;
        case WIDGET_GADGET_STRING_TYPE:
            widget_paint_gadget_string(_GSTR(handle), size, pos);
            is_draw_child = 0;
            break;
        case WIDGET_GADGET_INPUT_TYPE:
            widget_paint_gadget_input(_GINP(handle), size, pos);
            is_draw_child = 0;
            break;
    }

    /* widget_paint_editor, widget_paint_ctk, ... might leave widget screen */
    if (WGUI_CTX->is_widget_screen)
    {
        /* Paint softkeys */
        if (IS_SCREEN_TYPE(handle) || (_H(handle)->flag & WIDGET_FLAG_WINDOW))  // TODO: should not include gadget
            if (_W(handle)->total_action_mask)
            {
                widget_paint_action(handle);
            }

        /* Draw childs */
        if (is_draw_child)
        {
            widget_header_struct *node;

            if (IS_SCREEN_TYPE(handle)) /* currently, one screen only show one window */
            {
                widget_get_active_childs(node, handle);
                WGUI_CTX->current_screen = _SCREEN(handle);
                if (node)
                {
                    if (WGUI_CTX->current_window != _W(node))
                    {
                        WGUI_CTX->current_window = _W(node);
                        *pos = WGUI_CTX->current_pos = WGUI_CTX->display_pos;
                        *size = WGUI_CTX->display_size;
                        WGUI_CTX->in_form = 1;
                    }
                }
                else    /* no windows in this screen */
                {
                    /* Should not happen. Already checked in widget_paint_hdlr() */
                    WAP_DBG_ASSERT(0);
                }
                /* When painting the screen, we reset last_screen_is_dialog to 0 */
                WGUI_CTX->last_screen_is_dialog = 0;

                widget_paint_object(node, size, pos);
            }
            else
            {
                foreach_childs(handle, node,
                               {
                               if (!IS_FLAG_STATIC(node)
                                   && (node->flag & WIDGET_FLAG_WINDOW)) widget_paint_object(node, size, pos);}
                );
            }
        }
    }
    paint_level--;
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_scrollbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_scrollbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In direct paint mode, we need to paint the scrollbar after something is drawed on the paintbox */

    if (WGUI_CTX->in_paintbox)
    {
        MsfSize size;
        MsfPosition pos;

        size = WGUI_CTX->display_size;
        pos = WGUI_CTX->display_pos;

        if (WGUI_CTX->current_vertical_scrollbar)
        {
            widget_paint_gadget_bar(WGUI_CTX->current_vertical_scrollbar, &size, &pos, KAL_TRUE);
        }

        size = WGUI_CTX->display_size;
        pos = WGUI_CTX->display_pos;

        if (WGUI_CTX->current_horizontal_scrollbar)
        {
            widget_paint_gadget_bar(WGUI_CTX->current_horizontal_scrollbar, &size, &pos, KAL_TRUE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_get_title_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imageid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ctk_image_id widget_get_title_icon(ctk_image_id imageid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_message_applicaion = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imageid != 0)
    {
        return imageid;
    }

    if (WGUI_CTX->current_window && (_W(WGUI_CTX->current_window)->property_mask & MSF_WINDOW_PROPERTY_EXT_IS_MESSAGE_APPLICATION))
    {
        /* If the property_mask of widget_window_struct assign the application, we use its title icon */
        is_message_applicaion = KAL_TRUE;
    }

#ifdef MMS_SUPPORT
    if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_SOUND_IND && widget_is_current_window_type(WIDGET_FORM_TYPE))
    {
        imageid = MEA_IMG_TITLE_RING;
    }
#ifdef __UNIFIED_MSG_SUPPORT__
    /*
     * Because MSF_MODID_MEA is always running in unified message supported,
     *  we change the condition to check the current active application.
     */
    else if (is_message_applicaion || (!MSF_moduleIsRunning(MSF_MODID_BRS) && WGUI_CTX->MMS_screen_is_active))
#else
    else if (is_message_applicaion || MSF_moduleIsRunning(MSF_MODID_MEA) || WGUI_CTX->MMS_screen_is_active)
#endif
    {
        imageid = MEA_IMG_TITLE_NORMAL;
    }
    else
#endif /* MMS_SUPPORT */ 
    {
        if (WGUI_CTX->in_paintbox)
        {
            imageid = 0;    /* Default no icon. If it is connecting, widget will draw animation */
        }
        else
        {
        #ifdef WIDGET_DUAL_SIM_SUPPORT
            if (WGUI_CTX->service_on_sim == WAP_SERVICE_ON_MASTER_SIM)
            {
                imageid = WAP_IMAGE_WAP_LOGO_MASTER_SIM;
            }
            else if (WGUI_CTX->service_on_sim == WAP_SERVICE_ON_SLAVE_SIM)
            {
                imageid = WAP_IMAGE_WAP_LOGO_SLAVE_SIM;
            }
            else
       #endif /* #ifdef WIDGET_DUAL_SIM_SUPPORT */
            {
                /* If the application doesn't assign the SIM service, we show the default title icon */
                imageid = WAP_IMAGE_WAP_LOGO;
            }
        }

//        if (imageid == 0) /* always need to check bearer_type because in_paintbox is 0 when entry option menu in the browser */
        {
            switch (WGUI_CTX->bearer_type)
            {
                case WIDGET_CSD:
                #ifdef WIDGET_DUAL_SIM_SUPPORT
                    if (WGUI_CTX->service_on_sim == WAP_SERVICE_ON_SLAVE_SIM)
                    {
                        if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY)
                        {
                            imageid = WAP_IMAGE_CSD_CONNECTING_SLAVE_SIM; /* animation on title icon */
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_CSD)
                        {
                            imageid = WAP_IMAGE_CSD_CONNECTED_SLAVE_SIM;
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_DISCONNECT)
                        {
                            imageid = WAP_IMAGE_CSD_DISCONNECT_SLAVE_SIM;
                        }
                    }
                    else
                #endif /* #ifdef WIDGET_DUAL_SIM_SUPPORT */
                    {
                        if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY)
                        {
                            imageid = WAP_IMAGE_CSD_CONNECTING; /* animation on title icon */
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_CSD)
                        {
                            imageid = WAP_IMAGE_CSD_CONNECTED;
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_DISCONNECT)
                        {
                            imageid = WAP_IMAGE_CSD_DISCONNECT;
                        }
                    }
                    break;
                case WIDGET_GPRS:
                #ifdef WIDGET_DUAL_SIM_SUPPORT
                    if (WGUI_CTX->service_on_sim == WAP_SERVICE_ON_SLAVE_SIM)
                    {
                        if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY)
                        {
                            imageid = WAP_IMAGE_GPRS_CONNECTING_SLAVE_SIM;    /* animation on title icon */
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_GPRS)
                        {
                            imageid = WAP_IMAGE_GPRS_CONNECTED_SLAVE_SIM;
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_DISCONNECT)
                        {
                            imageid = WAP_IMAGE_GPRS_DISCONNECT_SLAVE_SIM;
                        }
                    }
                    else
                #endif /* #ifdef WIDGET_DUAL_SIM_SUPPORT */
                    {
                        if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY)
                        {
                            imageid = WAP_IMAGE_GPRS_CONNECTING;    /* animation on title icon */
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_GPRS)
                        {
                            imageid = WAP_IMAGE_GPRS_CONNECTED;
                        }
                        else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_DISCONNECT)
                        {
                            imageid = WAP_IMAGE_GPRS_DISCONNECT;
                        }
                    }
                    break;
            #ifdef __WIFI_SUPPORT__
                case WIDGET_WIFI:
                    if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_BUSY)
                    {
                        imageid = WAP_IMAGE_WIFI_CONNECTING;    /* animation on title icon */
                    }
                    else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_WIFI)
                    {
                        imageid = WAP_IMAGE_WIFI_CONNECTED;
                    }
                    else if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_DISCONNECT)
                    {
                        imageid = WAP_IMAGE_WIFI_DISCONNECT;
                    }
                    break;
            #endif /* __WIFI_SUPPORT__ */
            }
        } /* if (imageid == 0) */
    }

    return imageid;
}


/*****************************************************************************
 * FUNCTION
 *  widget_setup_security_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_setup_security_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->status_bar_flags & WIDGET_STATUS_BAR_SECURITY)
    {
        MMI_title_icon2 = get_image(WAP_IMAGE_SECURITY);
    }
    else
    {
        MMI_title_icon2 = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_reset_security_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_reset_security_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_icon2 = NULL;
}

static const UI_filled_area widget_title_count_down_filler =
    {UI_FILLED_AREA_TYPE_CROSS_HATCH_COLOR | UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_ROUNDED_BORDER,
    NULL,
    NULL,
    {120, 120, 120, 100},
    {0, 0, 0, 0},
    {100, 100, 100, 100},
    {0, 0, 0, 0},
    0
};

#ifdef WIDGET_SMIL_SLIDING_BAR


/*****************************************************************************
 * FUNCTION
 *  widget_paint_smil_sliding_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_smil_sliding_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form;
    S32 x1, y1, x2, y2, x3;
    S32 img_w = 0, img_h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->current_window || !IS_FORM_TYPE(WGUI_CTX->current_window))
    {
        /* widget_on_window_focus_changed should stop all paint command */
        WAP_DBG_ASSERT(0);
        return;
    }

    form = _FORM(WGUI_CTX->current_window);

    x1 = 0;
    y1 = UI_device_height - MMI_BUTTON_BAR_HEIGHT - WIDGET_SLIDING_BAR_REGION_HEIGHT;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT - 1;

    gui_lock_double_buffer();
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    /* draw the sliding bar backgroud image */
    gui_measure_image((PU8) GetImage(MEA_IMG_SMIL_SLIDING_BAR_REGION), &img_w, &img_h);
    gui_fill_rectangle(x1, y1, x2, y2, gui_color(255, 255, 255));
    if ((x2 - x1) > img_w)
    {
        x1 = ((x2 - x1) - img_w) >> 1;
    }
    if (WIDGET_SLIDING_BAR_REGION_HEIGHT > img_h)
    {
        y1 = y1 + ((WIDGET_SLIDING_BAR_REGION_HEIGHT - img_h) >> 1);
    }
    gui_show_image(x1, y1, (PU8) GetImage(MEA_IMG_SMIL_SLIDING_BAR_REGION));

    x2 = x1 + img_w - WIDGET_SMIL_SLIDING_BAR_H_SPACE;
    y2 = y1 + img_h - WIDGET_SMIL_SLIDING_BAR_V_SPACE;
    x1 = x1 + WIDGET_SMIL_SLIDING_BAR_H_SPACE;  /* 4 */
    y1 = y1 + WIDGET_SMIL_SLIDING_BAR_V_SPACE;  /* 3 */

    x1++;
    y1++;
    x2--;
    y2--;

    if (form->total_sec)
    {
        x3 = x1 + ((x2 - x1) * (form->total_sec - (form->remain_sec < 0 ? 0 : form->remain_sec)) / form->total_sec);
    }
    else
    {
        /* sliding time is 0 second */
        x3 = x2;
    }
    if (x3 > x2)
    {
        WAP_DBG_ASSERT(0);
        x3 = x2;
    }
    if (x3 < x1)
    {
        WAP_DBG_ASSERT(0);
        x3 = x1;
    }

    gui_fill_rectangle(
        x1,
        y1,
        x3,
        y2,
        gui_color(WIDGET_SMIL_SLIDING_BAR_FG_R, WIDGET_SMIL_SLIDING_BAR_FG_G, WIDGET_SMIL_SLIDING_BAR_FG_B));

    /* show the text */
    {
        /* draw the text, height: 20 */
        int sec = _FORM(WGUI_CTX->current_window)->remain_sec;
        char buf[6];
        kal_uint8 buf_u[STR_SIZE(6)];
        S32 text_width, character_height;
        S32 x_start;

        if (sec < 0)
        {
            /* time out */
            sec = 0;
        }
        sprintf(buf, "%01d:%02d", sec / 60 /* +10 */ , sec % 60);
        widget_utf8_to_ucs2_string((kal_uint8*) buf_u, sizeof(buf_u), (const kal_uint8*)buf);

        gui_push_text_clip();
        gui_set_text_clip(x1, y1, x2, y2);

        gui_set_font(&MMI_small_font);
        gui_measure_string((UI_string_type) buf_u, &text_width, &character_height);
        gui_set_text_color(*current_MMI_theme->title_text_color);
        gui_set_text_border_color(*current_MMI_theme->title_text_border_color);
        if (r2lMMIFlag)
        {
            x_start = x2 - (x2 - x1 - text_width) / 2;
        }
        else
        {
            x_start = (UI_device_width - text_width) / 2;
        }
        if ((y2 - y1) > character_height)
        {
            y1 += ((y2 - y1) >> 1) - (character_height >> 1);
        }
        else
        {
            y1++;
        }
        /* y+1 is for bordered text */
        gui_move_text_cursor(x_start, y1+1);
        gui_print_bordered_text((UI_string_type) buf_u);
        gui_pop_text_clip();
    }

    gui_pop_clip();
    gui_unlock_double_buffer();

	if (form->remain_sec > 0 && form->remain_sec >= form->total_sec-1)
	{
        /* stop lcd sleep at the beginning of playing MMS */
        TurnOnBacklight(0);
        mmi_phnset_disable_partial_ss();
    }
    else if (form->remain_sec <= 0)
    {
        /* let MMI can sleep */
        TurnOffBacklight();
        mmi_phnset_enable_partial_ss();
    }

}

#endif /* WIDGET_SMIL_SLIDING_BAR */


#if defined(WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON)
/*****************************************************************************
 * FUNCTION
 *  widget_draw_sliding_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_id      [IN]        
 *  x           [IN]        
 *  y           [IN]        
 *  w           [IN]        
 *  h           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_draw_MMS_viewer_title_button(U16 img_id, S16 x, S16 y, S16 w, S16 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button button;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_icontext_button(&button, x, y, w, h, NULL, get_image(img_id));
    button.flags |=
        UI_BUTTON_DISABLE_BACKGND_DISPLAY | UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_ICON_X | UI_BUTTON_CENTER_ICON_Y;
    button.clicked_down_icon = get_image(img_id);

    gdi_layer_push_clip();
    /*
     * we will clear the region first, and the clear region will be larger than the botton.
     * The position of pressed botton and released botton has 1 pixtel difference in x- and y- axes.
     */
    gdi_layer_set_clip(x - 1, y - 1, x + w, y + h);
    gui_fill_rectangle(x - 1, y - 1, x + w + 1, y + h + 1, gui_color(255, 255, 255));
    gui_show_icontext_button(&button);
    gdi_layer_pop_clip();
    widget_copy_title_from_base_layer(WGUI_CTX->top_gdi_layer);
    gui_BLT_double_buffer(x - 1, y - 1, x + w + 1, y + h + 1);
}



/*****************************************************************************
 * FUNCTION
 *  widget_paint_sliding_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_MMS_viewer_title()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_MMS_viewer_title_struct * title = _FORM(WGUI_CTX->current_window)->MMs_view_title;
    U8 *icon = MMI_title_icon;
    U16 bg_id = title_bg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_icon = 0;                     /* no need title icon */
    title_bg_id = IMAGE_VIEW_TITLEBAR_BG;   /* for showing different title bar. */
    wgui_set_title_bknd_display(MMI_TRUE);
#ifdef WIDGET_RESIDENT_STATUS_ICON
    show_title_status_icon();
#endif

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    /*
     * We don't show battery & signal status icon in MMS viewer title
     * The users could create their Downloadable theme and assign the status bar's background image.
     * The status bar's background image will conflict the background color of MMS viewer's title.
     */
    wgui_status_icon_integrated_enable(MMI_FALSE);
#endif

    if (WGUI_CTX->in_paintbox)
    {
        draw_title_wap();
    }
    else
    {
        draw_title();
    }
    MMI_title_icon = icon;
    title_bg_id = bg_id;

    /* setup buttons */
    widget_draw_MMS_viewer_title_button(
        title->prev_botton_img,
        title->prev_botton_x,
        title->prev_botton_y,
        title->button_width,
        title->button_height);

    widget_draw_MMS_viewer_title_button(
        title->next_botton_img,
        title->next_botton_x,
        title->next_botton_y,
        title->button_width,
        title->button_height);

}

#endif /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */ 

/* Used by widget screen only */


/*****************************************************************************
 * FUNCTION
 *  widget_paint_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    /* we do not display title for MsfDialog */
    if (!WGUI_CTX->is_widget_screen || 
        (widget_is_current_window_type(WIDGET_DIALOG_TYPE) && 
         (WEDITOR_CTX->current_state != FULLSCREEN_EDITOR_RETURN_DONE &&
          WEDITOR_CTX->current_state != FULLSCREEN_EDITOR_RETURN_CANCEL)))
    {
        /* If not in widget screen or in MsfDialog without the inputbox, we don't show the title */
        return;
    }

    /* default title icon */
    MMI_title_icon = get_image(widget_get_title_icon(0));
    widget_setup_security_icon();

    /* Draw title timeout count-down for MMS SMIL playing */
#if defined(WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON)
    /* Show sliding bar in MMS viewer */
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window) &&
        !MSF_moduleIsRunning(MSF_MODID_BRS) &&
        _H(WGUI_CTX->current_window)->module_id != MSF_MODID_BRA &&
        _H(WGUI_CTX->current_window)->module_id != MSF_MODID_BRS)
    {
        /* in MMS viewer */
        widget_paint_MMS_viewer_title();
    }
#else /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */ 
    /* WIDGET_MMS_VIEWER_TITLE_WITH_TIMESTAMP : We show remainder time in title bar */
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window) &&
        _H(WGUI_CTX->current_window)->module_id != MSF_MODID_BRA &&
        _H(WGUI_CTX->current_window)->module_id != MSF_MODID_BRS &&
        _FORM(WGUI_CTX->current_window)->total_sec > 0 && _FORM(WGUI_CTX->current_window)->remain_sec > 0)
    {
        int sec = _FORM(WGUI_CTX->current_window)->remain_sec;
        char buf[6];
        kal_uint8 buf_u[STR_SIZE(6)];
        S32 text_width, character_height;
        S32 x_start, x_end;

        sprintf(buf, "%01d:%02d", sec / 60 /* +10 */ , sec % 60);
        widget_utf8_to_ucs2_string((kal_uint8*) buf_u, sizeof(buf_u), (const kal_uint8*)buf);

        gui_lock_double_buffer();

    #ifdef __MMI_WALLPAPER_ON_BOTTOM__
        /* 
         * Because the status bar of the previous screen may have the wallpaper,
         * wWe need to reset status bar here. 
         * The background color of status bar in painbox in white.
         */
        if (WGUI_CTX->in_paintbox)
        {
            reset_title_status_icon();
        }
    #endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 
        /* Hold draw title until count-down indication is updated */
    #ifdef WIDGET_RESIDENT_STATUS_ICON
        show_title_status_icon();
    #endif
        if (WGUI_CTX->in_paintbox)
        {
            draw_title_wap();
        }
        else
        {
            draw_title();
        }

    /* Don't show slide timer information in MMS viewer when support non-blocking image drawing */
        gui_push_clip();
        gui_push_text_clip();
        gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
        gui_set_text_clip(
            MMI_title_x,
            MMI_title_y,
            MMI_title_x + MMI_title_width - 1,
            MMI_title_y + MMI_title_height - 1);

        gui_set_font((UI_font_type) (current_MMI_theme->window_title_font));
        gui_measure_string((UI_string_type) buf_u, &text_width, &character_height);
        gui_set_text_color(*current_MMI_theme->title_shortcut_text_color);

        if (r2lMMIFlag)
        {
            x_end = 3;
            x_start = x_end + text_width;

            gui_draw_filled_area(
                x_end - 2,
                MMI_title_y,
                x_start + 2,
                MMI_title_y + MMI_title_height - 1,
                (UI_filled_area*)&widget_title_count_down_filler);
        }
        else
        {
            x_end = MMI_title_x + MMI_title_width - 1 - 3;
            x_start = x_end - text_width + 1;

            gui_draw_filled_area(
                x_start - 2,
                MMI_title_y,
                x_end + 2,
                MMI_title_y + MMI_title_height - 1,
                (UI_filled_area*)&widget_title_count_down_filler);
        }
        gui_move_text_cursor(x_start, MMI_title_y + ((MMI_title_height - character_height) >> 1));
        gui_print_text((UI_string_type) buf_u);

        gui_pop_text_clip();
        gui_pop_clip();

        gui_unlock_double_buffer();

        if (_FORM(WGUI_CTX->current_window)->remain_sec > 0)
        {
            mmi_phnset_disable_partial_ss();
        }
        else if (_FORM(WGUI_CTX->current_window)->remain_sec <= 1)
        {
            mmi_phnset_enable_partial_ss();
        }

    }
#endif /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */ 
    else
    {

    #ifdef __MMI_WALLPAPER_ON_BOTTOM__
        /* 
         * Because the status bar of the previous screen may have the wallpaper,
         * wWe need to reset status bar here. 
         * The background color of status bar in painbox in white.
         */
        if (WGUI_CTX->in_paintbox)
        {
            reset_title_status_icon();
        }
    #endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

    #ifdef WIDGET_RESIDENT_STATUS_ICON
        show_title_status_icon();
    #endif
        if (WGUI_CTX->in_paintbox)
        {
            draw_title_wap();
        }
        else
        {
            draw_title();
        }
    }

    if (WGUI_CTX->animate_busy_status_bar)
    {
        WGUI_CTX->animate_busy_status_bar = 0;
        widget_paint_status_bar_busy_animator(KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_outside_look
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_outside_look(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_OUTSIDE_LOOK);

    if (!widget_has_status_icons())
    {
        widget_paint_title();
    #ifdef WIDGET_RESIDENT_STATUS_ICON
        if (WGUI_CTX->redraw_status_icons_pane)
        {
            ShowStatusIconsTitle();     // TODO: tmp fix in w04.38 that sometimes it will not draw icon pane
            widget_redraw_status_icons();
            WGUI_CTX->redraw_status_icons_pane = 0;
        }
    #endif /* WIDGET_RESIDENT_STATUS_ICON */ 
    }
    else
    {
        widget_redraw_status_icons();
    }

    /*
     * Draw scrollbar. Although scrollbars are similar to other gadgets,
     * * we draw it last such that it would not be overlapped by other gagets.
     */
    widget_paint_scrollbar();

#ifdef WIDGET_SMIL_SLIDING_BAR
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window) &&
        _FORM(WGUI_CTX->current_window)->sliding_info != NULL)
    {
        widget_paint_smil_sliding_bar();
    }
#endif /* WIDGET_SMIL_SLIDING_BAR */ 

    show_softkey_background();

    /* show arrow indication */
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window))
    {
        kal_uint32 flags = _FORM(WGUI_CTX->current_window)->form_flags;

        if (flags &
            (WIDGET_FORM_FLAG_SHOW_UP_ARROW | WIDGET_FORM_FLAG_SHOW_DOWN_ARROW |
             WIDGET_FORM_FLAG_SHOW_LEFT_ARROW | WIDGET_FORM_FLAG_SHOW_RIGHT_ARROW))
        {
            draw_arrow_indication(
                (S8) ((flags & WIDGET_FORM_FLAG_SHOW_LEFT_ARROW) ? 1 : 0),
                (S8) ((flags & WIDGET_FORM_FLAG_SHOW_RIGHT_ARROW) ? 1 : 0),
                (S8) ((flags & WIDGET_FORM_FLAG_SHOW_UP_ARROW) ? 1 : 0),
                (S8) ((flags & WIDGET_FORM_FLAG_SHOW_DOWN_ARROW) ? 1 : 0));
        }
    }

    redraw_left_softkey();
    redraw_right_softkey();

    if (WGUI_CTX->top_gdi_layer != 0)
    {
        if (WGUI_CTX->top_gdi_layer_is_button_bar == 0)
        {
            widget_copy_title_from_base_layer(WGUI_CTX->top_gdi_layer);
        }
        else if (WGUI_CTX->top_gdi_layer_is_button_bar == 1)
        {
            widget_copy_bar_from_base_layer(WGUI_CTX->top_gdi_layer);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]         
 *  size        [IN]        
 *  pos         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_area(widget_header_struct *handle, MsfSize size, MsfPosition pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_integrated_enable(MMI_TRUE);
#endif
    if (!widget_is_current_window_type(WIDGET_EDITOR_TYPE) ||
        WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_WANT_EXECUTE)
    {
        kal_uint8 lock_level_tmp;

        /*
         * Lock double buffer
         */
        gui_lock_double_buffer();
        WGUI_CTX->lock_buffer_level++;
        lock_level_tmp = WGUI_CTX->lock_buffer_level;

        /*
         * clear MMI-related data
         */
        MMI_title_string = NULL;
        MMI_title_icon = NULL;
        set_left_softkey_label((UI_string_type) NULL);
        set_right_softkey_label((UI_string_type) NULL);
        clear_left_softkey();
        clear_right_softkey();
        register_default_hide_softkeys();
        MMI_disable_title_shortcut_display = 0;
        MMI_menu_shortcut_number = -1;

        /* We need to reset gdi image cache because the different image may use the same cache file name. */
        gdi_image_cache_reset();
        /* 
         * clear widget internal data
         */
        WGUI_CTX->current_vertical_scrollbar = NULL;
        WGUI_CTX->current_horizontal_scrollbar = NULL;
        widget_reset_used_range();
        widget_clear_keyfocus();

    #ifdef __MMI_TOUCH_SCREEN__
        WPEN_CTX->current_RSK = WPEN_CTX->current_LSK = NULL;
    #endif 

        /*
         * start to paint
         */
        widget_paint_object(handle, &size, &pos);

        /*
         * For example, widget_paint_gadget_input enter a full-screen editor
         * * then it should not draw anymore
         */
        if (!WGUI_CTX->is_widget_screen)
        {
            if (lock_level_tmp == WGUI_CTX->lock_buffer_level)
            {
                gui_unlock_double_buffer();
                WGUI_CTX->lock_buffer_level--;
            }
            return;
        }

        /*
         * Finalize the painting
         */
        widget_paint_outside_look();

        if (WGUI_CTX->animate_GIF_after_screen_painted)
        {
            WGUI_CTX->animate_GIF_after_screen_painted = 0;
            widget_paint_GIF_animation_hdlr(NULL);
        }

        gui_unlock_double_buffer();
        WGUI_CTX->lock_buffer_level--;

        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
        
        if (widget_check_in_playing_video())
        {
            widget_MMI_play_video_gadget();
        }

    }
    else
    {
        /*
         * For example, MEA create an MsfEditor object, and add MsfOk and MsfCancel on it.
         * * Widget will enter full-screen editor in widget_paint_editor().
         * * After the user press "Done", it will go back to widget screen (MsfEditor is still focused),
         * * and the following code will emulate LSK pressed and fire MsfAction to MEA module. 
         * * As a result, MEA will set focus to another window and paint again.
         * * This will let the screen flicker for a second.
         */

        /* We still need to setup MsfAction for later use. */
        widget_window_struct *window = widget_get_current_focused_window();

        WAP_DBG_ASSERT(window);
        if (window)
        {
            widget_paint_action((widget_header_struct*) window);
        }
    }
    
    if (WGUI_CTX->current_window_audio_cb)
    {
        (MsfFormAudioCallBack)(WGUI_CTX->current_window_audio_cb)();
    }

    /* Play pending sound */
    widget_resume_pending_sound_on_displayed(WGUI_CTX->current_window);

    /* /////////////////////////////////////////////////// */
    /*
     * This is called after full-screen editor is closed (wap_entry_widget_screen),
     * * and the screen was already paint, we simulate a key press
     */

    /*
     * If we return from Fullscreen Editor, we should simulation user to press Left/Right softkey
     * * because BRS use LSK (OK) and RSK (Cancel) for text input and option group in browser
     * *
     * * For MsfEditor, application should already add MsfActions to it.
     */

    // TODO: We should move the following code before widget_paint_area. Otherwise, widget_paint might execute when WGUI_CTX->in_form == KAL_FALSE
    if (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_DONE)
    {
        if (WGUI_CTX->in_paintbox || WGUI_CTX->in_editor)
        {
            widget_key_ind_handler(KEY_LSK, KEY_EVENT_UP);
            WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
        }
        else if (WGUI_CTX->current_dialog)
        {
            if (_DIALOG(WGUI_CTX->current_dialog)->dialog_input)
            {
                /* Send the action event in MsfDialog when goback from fullscreen editor. */
                widget_key_ind_handler(KEY_LSK, KEY_EVENT_UP);
                WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
            }
            else
            {
                /*
                 * CDS disconnect in fullscreen editor and then back to the browser 
                 * BRA will show dialog first, and we avoid re-entry fullscreen editor when back to the browser 
                 */
                WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_DENY_ENTRY;
            }
        }
        else
        {
            WAP_DBG_ASSERT(!WGUI_CTX->in_form);
            widget_choice_focus();  /* Switch to browse mode */
            WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
        }

    }
    else if (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_RETURN_CANCEL)
    {
        if (WGUI_CTX->in_paintbox || WGUI_CTX->in_editor)
        {
            widget_key_ind_handler(KEY_RSK, KEY_EVENT_UP);
            WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
        }
        else if (WGUI_CTX->current_dialog)
        {
            if (_DIALOG(WGUI_CTX->current_dialog)->dialog_input)
            {
                /* Send the action event in MsfDialog when goback from fullscreen editor. */
                widget_key_ind_handler(KEY_RSK, KEY_EVENT_UP);
                WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
            }
            else
            {
                WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_DENY_ENTRY;
            }
        }
        else
        {
            WAP_DBG_ASSERT(!WGUI_CTX->in_form);
            widget_choice_focus();  /* Switch to browse mode */
            WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
        }

    }
    else if (WEDITOR_CTX->current_state == FULLSCREEN_EDITOR_DENY_ENTRY)
    {
        WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE;
    }

     

    if (WENTER_MENU_CTX->state == WIDGET_ENTER_MENU_RETURN_OK)
    {
        if (WGUI_CTX->in_paintbox)  /* Default actions are created by BRS */
        {
            if (WGUI_CTX->is_access_key_trigger == KAL_TRUE)
            {
                /* If enter fullscreen menu by access key, we don't need to execute LSK, EVENT_IP action */
                WGUI_CTX->is_access_key_trigger = KAL_FALSE;
            }
            else
            {
                widget_key_ind_handler(KEY_LSK, KEY_EVENT_UP);
            }
        }
        else
        {
            WAP_DBG_ASSERT(0);  /* We do not handle choice menu in MsfForm */
        }
        widget_init_fullscreen_menu();
    }
    else if (WENTER_MENU_CTX->state == WIDGET_ENTER_MENU_RETURN_CANCEL)
    {
        if (WGUI_CTX->in_paintbox)
        {
            if (WGUI_CTX->is_access_key_trigger == KAL_TRUE)
            {
                /* If enter fullscreen menu by access key, we don't need to execute LSK, EVENT_IP action */
                WGUI_CTX->is_access_key_trigger = KAL_FALSE;
            }
            else
            {
                widget_key_ind_handler(KEY_RSK, KEY_EVENT_UP);
            }
        }
        else
        {
            WAP_DBG_ASSERT(0);
        }
        widget_init_fullscreen_menu();
    }

    widget_enable_clear_all_handler();
    WGUI_CTX->is_access_key_trigger = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_clear_all_mmi_scrolling_animator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_clear_all_mmi_scrolling_animator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_text_menuitem_stop_scroll();
    gui_fixed_icontext_list_menuitem_stop_scroll();
    gui_fixed_icontext_menuitem_stop_scroll();
    /* Including the case option group inside of a paintbox */
    gui_fixed_twostate_menuitem_stop_scroll();
}


/*****************************************************************************
 * FUNCTION
 *  widget_clear_animator_on_key_accepted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_clear_animator_on_key_accepted()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * some animation should be stopped after key is pressed but before widget_paint 
     * * The list of these timers are by heuristics
     */

    widget_clear_all_mmi_scrolling_animator();
    StopTimer(BLINKING_CURSOR);
}


/*****************************************************************************
 * FUNCTION
 *  widget_enable_clear_all_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enable_clear_all_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->is_all_handler_cleared = 0;
}

/*
 * On
 * * 1. Redraw screen 
 * * 2. Exit widget screen
 */


/*****************************************************************************
 * FUNCTION
 *  widget_clear_all_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_clear_all_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_all_handler_cleared)
    {
        /* Sometimes we also invoke these cleanups in widget_on_window_focus_changed() */

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CLEAR_ALL_HANDLER);

        widget_stop_animate(KAL_FALSE); /* Remove all GIF animation in queue. It will be inserted again in widget_paint_gadget_image() */
        widget_stop_timer(WIDGET_PAINT_TIMER);
        widget_stop_all_blinking();     /* Blinking text in paintbox */
        widget_stop_all_marquee();
        /* wgui_hide_animation(); */
    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        gui_stop_list_highlight_effect();
    #endif 

        /* gui_cancel_timer(UI_inputbox_blink_cursor); */
        StopTimer(BLINKING_CURSOR);
        gui_hide_animations();

        /* clear all handler (FIXME, not exclusive, maybe we should not call lowlevel MMI function directly) */
        clear_key_input_handler();
        clear_key_down_handler();
        clear_key_up_handler();
        clear_keyboard_key_handler();
        clear_left_softkey_handler();
        clear_right_softkey_handler();
        widget_clear_all_mmi_scrolling_animator();
        disable_active_multitap();
        reset_softkeys();   /* I don't know if we need these */
        reset_fixed_list(); /* Otherwise, there might be wrong flags in fixed list */
        reset_menu_shortcut_handler();
        /* reset_pop_up_descriptions(); */

        /* set default key handlers */
        SetGroupKeyHandler(widget_MMI_key_handler, widget_all_keys, MAX_KEYS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(widget_MMI_key_handler, widget_all_keys, MAX_KEYS, KEY_EVENT_UP);
        SetGroupKeyHandler(widget_MMI_key_handler, widget_all_keys, MAX_KEYS, KEY_REPEAT);

        /* WAP/MMS supports KEY_LONG_PRESS and KEY_REAT in navigation keys */
        SetKeyHandler(widget_MMI_key_handler, KEY_UP_ARROW, KEY_REPEAT);
        SetKeyHandler(widget_MMI_key_handler, KEY_DOWN_ARROW, KEY_REPEAT);
        SetKeyHandler(widget_MMI_key_handler, KEY_RIGHT_ARROW, KEY_REPEAT);
        SetKeyHandler(widget_MMI_key_handler, KEY_LEFT_ARROW, KEY_REPEAT);
        SetKeyHandler(widget_MMI_key_handler, KEY_UP_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(widget_MMI_key_handler, KEY_DOWN_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(widget_MMI_key_handler, KEY_RIGHT_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(widget_MMI_key_handler, KEY_LEFT_ARROW, KEY_LONG_PRESS);

        /* 
         * Reference: PowerAndEndKeyHandler()
         *
         * END key handler
         * (Deprecated)
         * Down - hangup connection
         * Long-press - power-off
         * Up - goto idle screen
         * 
         * As a result, power-off will hangup the CSD connection first. Otherwise, we might not be able to play
         * poweroff tones due to the limitation of DSP of MT6205.
         *
         * (New Approach) Fix for  __MMI_CLAMCLOSE_BACK2IDLE__
         * Down - hangup connection & goto idle screen
         * Long-press - power-off
         *
         */
        SetKeyHandler(widget_goto_idlescreen, KEY_END, KEY_EVENT_DOWN);
        
        mmi_frm_set_default_power_onoff_key();

    #ifdef __UNIFIED_MSG_SUPPORT__
        if (!MSF_moduleIsRunning(MSF_MODID_BRS) || widget_check_is_in_non_wap_call())
        {
            /* We only don't execute the end key handler in normal procedure when launching the browser without in the call */
            PowerAndEndKeyHandler();
        }
    #endif 

    #ifdef __MMI_TOUCH_SCREEN__
        widget_MMI_setup_pen_handler();
    #endif 

        WGUI_CTX->is_all_handler_cleared = 1;

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CLEAR_ALL_HANDLER_END);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_pause_paint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_pause_paint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->paint_level++;
}


/*****************************************************************************
 * FUNCTION
 *  widget_resume_paint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_resume_paint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->paint_level--;
}

// TODO: if we want to do widget paint in MMI task, we should be careful of "out-of-memory"


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_paint_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __PRODUCTION_RELEASE__
    ASSERT(WIDGET_IS_MMI_TASK());
#endif 

    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

#ifdef WIDGET_PROFILING
    WPROF_CTX->cnt_paint++;
#endif 

    widget_clear_all_handler();

    /*
     * must have at least one screen to display
     * * Scenario: create a BRA window in BRA screen from MEA (e.g. profile), and close it.
     * * We did not check this scenario in HDIa_widgetRemove because we are afraid that 
     * * the application might add another window to the current screen immediately after removing the last window.
     */
    if (WGUI_CTX->widget_root.childs_sum)
    {
        widget_header_struct *last_activescreen, *activescreen, *activewindow;

        widget_get_active_childs(activescreen, (&WGUI_CTX->widget_root));
        last_activescreen = activescreen;

        /*
         * We must handle the case that a screen does not have any window
         * * Scenario: exit wap main menu, an empty screen will display for 0.5 sec if we don't check this
         */
        while (activescreen)
        {
            widget_get_active_childs(activewindow, activescreen);
            if (activewindow)
            {
                if (activescreen != last_activescreen)  /* the screen is changed */
                {
                    HDIa_widgetSetInFocus((MsfScreenHandle) activescreen, 1);   /* invoke another widget_paint */
                    break;
                }

                /* We only show the status icon bar when call widget_paint_area() */
                if (!WGUI_CTX->is_painted)
                {
                    WGUI_CTX->is_painted = 1;
                #ifdef WIDGET_RESIDENT_STATUS_ICON
                    /* Refer to wap_entry_widget_screen() */
                    show_status_icon_bar(0);
                #endif /* WIDGET_RESIDENT_STATUS_ICON */ 
                }

                widget_paint_area(activescreen, WGUI_CTX->display_size, WGUI_CTX->current_pos);
                break;
            }
            widget_get_next_active_childs(activescreen, (&WGUI_CTX->widget_root));
        }
    }
    /*
     * If it is in MsfWindow, we reset WEDITOR_CTX->leave_from_fullscreen.
     * WEDITOR_CTX->leave_from_fullscreen will be TRUE when leaving from widget fullscreen option menu.
     */
    WEDITOR_CTX->leave_from_fullscreen = KAL_FALSE;
    WGUI_CTX->is_painted_after_first_focus_changed = 1;
    WGUI_CTX->paint_seqnum++;
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_UNUSED(arg);

    widget_stop_all_paint_command();

    /* In widget shutdown UI procedure, we don't need to execute the paint handler */
    if (!WGUI_CTX->is_widget_screen || WGUI_CTX->is_shutdown_UI == 1)
    {
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_HDLR);

    WGUI_CTX->paint_level++;

    if (WGUI_CTX->paint_level == 1)
    {
        widget_execute_MMI(widget_MMI_paint_hdlr, KAL_TRUE);
    }
    else
    {
        widget_start_timer(WIDGET_PAINT_TIMER, widget_paint_hdlr, NULL, WIDGET_PAINT_DELAY_TIME);
    }

    WGUI_CTX->paint_level--;
}

/* timer handler */


/*****************************************************************************
 * FUNCTION
 *  widget_paintbox_redraw_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_paintbox_redraw_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->in_paintbox)
    {
        /* This is required to make BRS repaint */
        if (WGUI_CTX->current_focused_paintbox)
        {
            widget_notify(_H(WGUI_CTX->current_focused_paintbox), MsfNotifyStateChange);
        }
        widget_send_update_event_to_wap();
    }

}

/* asking paintbox to redraw (when exiting MMI and entering paintbox) */


/*****************************************************************************
 * FUNCTION
 *  widget_paintbox_redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paintbox_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In widget shutdown UI procedure, we don't need to execute the paint handler */
    if (!WGUI_CTX->is_widget_screen || WGUI_CTX->is_shutdown_UI == 1)
    {
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINTBOX_REDRAW);

    /*
     * We should not simply call widget_notify here because this function might be invoked from MMI.
     * * and it might insert internal queue when WAP is still processing it.
     */
    widget_start_timer(
        WIDGET_PAINTBOX_REDRAW_TIMER,
        (widget_timer_func) widget_paintbox_redraw_hdlr,
        (void*)NULL,
        WIDGET_PAINTBOX_REDRAW_DELAY_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In widget shutdown UI procedure, we don't need to execute the paint handler */
    if (!WGUI_CTX->is_widget_screen || WGUI_CTX->is_shutdown_UI == 1)
    {
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT);

#ifdef WIDGET_PROFILING
    WPROF_CTX->cnt_try_paint++;
#endif 

    // TODO: check widget_clear_animator_on_key_accepted()

    gui_hide_animations();
    widget_stop_all_paint_command();

    RedrawCategoryFunction = widget_paint;  /* Sometimes we will override it */

    widget_start_timer(WIDGET_PAINT_TIMER, widget_paint_hdlr, NULL, WIDGET_PAINT_DELAY_TIME);
}

/*************************************************************************
 * Paint command queue - Redraw (part of) the screen
 *************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_release_paint_command_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_release_paint_command_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_paint_command_struct *p = WGUI_CTX->paint_cmd_head;
    widget_paint_command_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (p)
    {
        next = p->next;
        MSF_MEM_FREE(MSF_MODID_WIDGET, p);
        p = next;
    }

    WGUI_CTX->paint_cmd_head = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_enqueue_paint_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cmd     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_enqueue_paint_command(widget_paint_command_struct *cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(cmd->next == NULL);

    cmd->next = WGUI_CTX->paint_cmd_head;
    WGUI_CTX->paint_cmd_head = cmd;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_command_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_paint_command_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_paint_command_struct *p = WGUI_CTX->paint_cmd_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_widget_screen)
    {
        /* It will repaint all after returning to widget screen */
        widget_release_paint_command_queue();
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_COMMAND_HDLR);
#ifndef __PRODUCTION_RELEASE__
    ASSERT(WIDGET_IS_MMI_TASK());
#endif 

    while (p)
    {
        switch (p->type)
        {
            case WIDGET_PAINT_CMD_TITLE:
                widget_paint_title();
                widget_copy_title_from_base_layer(WGUI_CTX->top_gdi_layer);
                gui_BLT_double_buffer(
                    MMI_title_x,
                    MMI_title_y,
                    MMI_title_x + MMI_title_width - 1,
                    MMI_title_y + MMI_title_height - 1);
                break;
            case WIDGET_PAINT_CMD_GADGET:
                ASSERT(p->gadget);
                switch (_H(p->gadget)->data_type)
                {
                        /* Reference: widget_MMI_paint_marquee_hdlr */
                    case WIDGET_GADGET_IMAGE_TYPE:
                    {
                        widget_draw_queued_operation_from_gadget_image(_GIMG(p->gadget), KAL_TRUE, KAL_TRUE, 0, 0);
                    }
                        break;

                    case WIDGET_GADGET_BAR_TYPE:
                    {
                        MsfSize size;
                        MsfPosition pos;
                        S32 x1, y1, x2, y2;

                        size = WGUI_CTX->display_size;
                        pos = WGUI_CTX->display_pos;

                        x1 = pos.x + _GBAR(p->gadget)->position.x;
                        y1 = pos.y + _GBAR(p->gadget)->position.y;
                        x2 = x1 + _GBAR(p->gadget)->size.width - 1;
                        y2 = y1 + _GBAR(p->gadget)->size.height - 1;
                        gui_lock_double_buffer();
                        widget_paint_gadget_bar(_GBAR(p->gadget), &size, &pos, KAL_TRUE);
                        gui_unlock_double_buffer();

                        gui_BLT_double_buffer(x1, y1, x2, y2);
                    }
                        break;

                    default:
                        WAP_DBG_ASSERT(0);
                }
                break;

            #ifdef WIDGET_SMIL_SLIDING_BAR
            case WIDGET_PAINT_CMD_SLIDING_BAR:
                widget_paint_smil_sliding_bar();
                widget_copy_bar_from_base_layer(WGUI_CTX->top_gdi_layer);
                gui_BLT_double_buffer(
                    0,
                    UI_device_height - 1 - MMI_BUTTON_BAR_HEIGHT - WIDGET_SLIDING_BAR_REGION_HEIGHT,
                    UI_device_width - 1,
                    UI_device_height - 1 - MMI_BUTTON_BAR_HEIGHT);
                break;
            #endif /* WIDGET_SMIL_SLIDING_BAR */ 

            default:
                ASSERT(0);
        }
        p = p->next;
    }

    widget_release_paint_command_queue();
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_command_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_paint_command_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In widget shutdown UI procedure, we don't need to execute the paint handler */
    if (!WGUI_CTX->is_widget_screen || WGUI_CTX->is_shutdown_UI == 1)
    {
        /* It will repaint all after returning to widget screen */
        widget_release_paint_command_queue();
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_COMMAND_HDLR);
    widget_execute_MMI(widget_MMI_paint_command_hdlr, KAL_TRUE);
}




#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_scrollbar_ind_hdlr
 * DESCRIPTION
 *  Release the scroll bar indication button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_paint_scrollbar_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfSize size;
    MsfPosition pos;
    S32 vbar_x1, vbar_y1, vbar_x2, vbar_y2;
    S32 hbar_x1, hbar_y1, hbar_x2, hbar_y2;
    vertical_scrollbar vbar_tmp;
    vertical_scrollbar *vbar_b = &vbar_tmp;
    horizontal_scrollbar hbar_tmp;
    horizontal_scrollbar *hbar_b = &hbar_tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = WGUI_CTX->display_size;
    pos = WGUI_CTX->display_pos;

    if (WGUI_CTX->scrollbar_indication_info)
    {
        WGUI_CTX->allow_to_update_scrollbar_indication = 0;
        if (WGUI_CTX->in_paintbox && WGUI_CTX->current_vertical_scrollbar)
        {
            vbar_x1 = pos.x + _GBAR(WGUI_CTX->current_vertical_scrollbar)->position.x;
            vbar_y1 = pos.y + _GBAR(WGUI_CTX->current_vertical_scrollbar)->position.y;
            vbar_x2 = vbar_x1 + _GBAR(WGUI_CTX->current_vertical_scrollbar)->size.width - 1;
            vbar_y2 = vbar_y1 + _GBAR(WGUI_CTX->current_vertical_scrollbar)->size.height - 1;
            gui_create_vertical_scrollbar(
                vbar_b, 
                vbar_x1, 
                vbar_y1, 
                _GBAR(WGUI_CTX->current_vertical_scrollbar)->size.width, 
                _GBAR(WGUI_CTX->current_vertical_scrollbar)->size.height);
            gui_lock_double_buffer();
            widget_paint_gadget_bar(WGUI_CTX->current_vertical_scrollbar, &size, &pos, KAL_TRUE);
            gui_vertical_scrollbar_redraw_button(vbar_b, GUI_SCROLLBAR_BUTTON_UP, MMI_FALSE);
            gui_vertical_scrollbar_redraw_button(vbar_b, GUI_SCROLLBAR_BUTTON_DOWN, MMI_FALSE);
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(vbar_x1, vbar_y1, vbar_x2, vbar_y2);
        }

        if (WGUI_CTX->in_paintbox && WGUI_CTX->current_horizontal_scrollbar)
        {
            hbar_x1 = pos.x + _GBAR(WGUI_CTX->current_horizontal_scrollbar)->position.x;
            hbar_y1 = pos.y + _GBAR(WGUI_CTX->current_horizontal_scrollbar)->position.y;
            hbar_x2 = hbar_x1 + _GBAR(WGUI_CTX->current_horizontal_scrollbar)->size.width - 1;
            hbar_y2 = hbar_y1 + _GBAR(WGUI_CTX->current_horizontal_scrollbar)->size.height - 1;
            gui_create_horizontal_scrollbar(
                hbar_b, 
                hbar_x1, 
                hbar_y1, 
                _GBAR(WGUI_CTX->current_horizontal_scrollbar)->size.width, 
                _GBAR(WGUI_CTX->current_horizontal_scrollbar)->size.height);
            gui_lock_double_buffer();
            widget_paint_gadget_bar(WGUI_CTX->current_horizontal_scrollbar, &size, &pos, KAL_TRUE);
            gui_horizontal_scrollbar_redraw_button(hbar_b, GUI_SCROLLBAR_BUTTON_LEFT, MMI_FALSE);
            gui_horizontal_scrollbar_redraw_button(hbar_b, GUI_SCROLLBAR_BUTTON_RIGHT, MMI_FALSE);
            gui_unlock_double_buffer();

            gui_BLT_double_buffer(hbar_x1, hbar_y1, hbar_x2, hbar_y2);
        }
        WGUI_CTX->allow_to_update_scrollbar_indication = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_scrollbar_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_scrollbar_ind_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 KeyCode, KeyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In widget shutdown UI procedure, we don't need to execute the paint handler */
    if (!WGUI_CTX->is_widget_screen || WGUI_CTX->is_shutdown_UI == 1)
    {
        return;
    }

    GetkeyInfo(&KeyCode, &KeyType);
    if (KeyCode >= KEY_UP_ARROW && KeyCode <= KEY_RIGHT_ARROW && KeyType != KEY_EVENT_UP)
    {
        /* If the key is pressed, don't need to release the scroll bar indication button */
        widget_start_timer(WIDGET_PAINTBOX_SCROLL_INDICATION_TIMER, widget_paint_scrollbar_ind_hdlr, NULL, WIDGET_PAINTBOX_SCROLL_INDICATION_DELAY_TIMER/2);
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_SCROLLBAR_IND_HDLR);
    if (WGUI_CTX->in_paintbox)
    {
        /* Release the scroll bar indication button */
        widget_execute_MMI(widget_MMI_paint_scrollbar_ind_hdlr, KAL_TRUE);
    }
}
#endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */


/*****************************************************************************
 * FUNCTION
 *  widget_stop_all_paint_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_all_paint_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_stop_timer(WIDGET_PAINT_COMMAND_TIMER);
    widget_release_paint_command_queue();
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_paint_gadget_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_paint_gadget_command(widget_header_struct *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_paint_command_struct *p = WGUI_CTX->paint_cmd_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (p)
    {
        if (p->gadget == h)
        {
            widget_stop_all_paint_command();
            widget_paint();
            return;
        }
        p = p->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_add_paint_gadget_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_add_paint_gadget_command(widget_header_struct *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_paint_command_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(h);

    p = WGUI_CTX->paint_cmd_head;
    while (p)   /* Prevent duplicated command */
    {
        if (p->gadget == h)
        {
            return;
        }
        p = p->next;
    }

    p = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_paint_command_struct));
    p->type = WIDGET_PAINT_CMD_GADGET;
    p->gadget = h;
    p->next = NULL;

    widget_enqueue_paint_command(p);

    widget_start_timer(WIDGET_PAINT_COMMAND_TIMER, widget_paint_command_hdlr, NULL, WIDGET_PAINT_DELAY_TIME);

}


/*****************************************************************************
 * FUNCTION
 *  widget_add_paint_title_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_add_paint_title_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_paint_command_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = WGUI_CTX->paint_cmd_head;
    while (p)   /* Prevent duplicated command */
    {
        if (p->type == WIDGET_PAINT_CMD_TITLE)
        {
            return;
        }
        p = p->next;
    }

    p = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_paint_command_struct));
    p->type = WIDGET_PAINT_CMD_TITLE;
    p->gadget = NULL;
    p->next = NULL;

    widget_enqueue_paint_command(p);

    widget_start_timer(WIDGET_PAINT_COMMAND_TIMER, widget_paint_command_hdlr, NULL, WIDGET_PAINT_DELAY_TIME);
}

#ifdef WIDGET_SMIL_SLIDING_BAR


/*****************************************************************************
 * FUNCTION
 *  widget_add_paint_sliding_bar_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_add_paint_sliding_bar_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_paint_command_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = WGUI_CTX->paint_cmd_head;
    while (p)   /* Prevent duplicated command */
    {
        if (p->type == WIDGET_PAINT_CMD_SLIDING_BAR)
        {
            return;
        }
        p = p->next;
    }

    p = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_paint_command_struct));
    p->type = WIDGET_PAINT_CMD_SLIDING_BAR;
    p->gadget = NULL;
    p->next = NULL;

    widget_enqueue_paint_command(p);

    widget_start_timer(WIDGET_PAINT_COMMAND_TIMER, widget_paint_command_hdlr, NULL, WIDGET_PAINT_DELAY_TIME);
}
#endif /* WIDGET_SMIL_SLIDING_BAR */ 

/****************************************************************
 * WAP status indication (as title icon)
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_paint_status_bar_busy_animator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_off_to_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_status_bar_busy_animator(kal_bool is_off_to_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* widget_stop_timer(WIDGET_PAINT_BUSY_TIMER); */
    /* In widget shutdown UI procedure, we don't need to execute the paint handler */
    if (!WGUI_CTX->is_widget_screen || WGUI_CTX->is_shutdown_UI == 1)
    {
        return;
    }

    if (is_off_to_on)
    {
        PU8 busy_image;
        S32 w, h;
        int image_length;
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        S32 padding_w, padding_h;
#endif

        if (WGUI_CTX->bearer_type == WIDGET_CSD)
        {
            busy_image = get_image(WAP_IMAGE_CSD_CONNECTING);
        }
    #ifdef __WIFI_SUPPORT__
        else if (WGUI_CTX->bearer_type == WIDGET_WIFI)
        {
            busy_image = get_image(WAP_IMAGE_WIFI_CONNECTING);
        }
	#endif /* __WIFI_SUPPORT__ */
        else
        {
            busy_image = get_image(WAP_IMAGE_GPRS_CONNECTING);
        }

        image_length = _read_image_length((U8*) busy_image);
        gui_measure_image(busy_image, &w, &h);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        gui_measure_image(get_image(IMG_SI_BATTERY_STRENGTH), &padding_w, &padding_h);
#endif
        WIMG_CTX->busy_indication_icon = widget_show_animate_image_by_raw_data(
                                            NULL,
                                            NULL,
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
                                            r2lMMIFlag ? MMI_title_width - (w + padding_w) - 1 : MMI_title_x + padding_w + 1,
#else
                                            r2lMMIFlag ? MMI_title_width - w - 1 : MMI_title_x + 1,
#endif
                                            MMI_title_y + ((MMI_title_height - h) >> 1),
                                            MsfGif,
                                            (void*)(busy_image + WIDGET_MMI_PREIMAGE_OFFSET_GIF),
                                            image_length,
                                            w,
                                            h,
                                            NULL,
                                            MsfImageZoom100,
                                            KAL_FALSE,
                                            KAL_FALSE,
                                            KAL_FALSE,
                                            KAL_TRUE,
                                            KAL_TRUE);
    }
    else
    {
        if (WIMG_CTX->busy_indication_icon)
        {
            kal_bool ret = widget_stop_animate_by_ptr(WIMG_CTX->busy_indication_icon);

            WAP_DBG_ASSERT(ret);

            WIMG_CTX->busy_indication_icon = NULL;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  widget_enable_status_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  indicator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_enable_status_bar(int indicator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int old_indicator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_indicator = (WGUI_CTX->status_bar_flags & indicator);
    enable_bit_flag(WGUI_CTX->status_bar_flags, indicator);

    if (indicator & WIDGET_STATUS_BAR_CSD)
    {
        WGUI_CTX->bearer_type = WIDGET_CSD;
    }
    else if (indicator & WIDGET_STATUS_BAR_GPRS)
    {
        WGUI_CTX->bearer_type = WIDGET_GPRS;
    }
#ifdef __WIFI_SUPPORT__
    else if (indicator & WIDGET_STATUS_BAR_WIFI)
    {
        WGUI_CTX->bearer_type = WIDGET_WIFI;
    }
#endif /* __WIFI_SUPPORT__ */    

    switch (indicator)
    {
        case WIDGET_STATUS_BAR_BUSY:
            if (!old_indicator)
            {
                WGUI_CTX->animate_busy_status_bar = 1;
                widget_paint();
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_disable_status_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  indicator       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_disable_status_bar(int indicator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int old_indicator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_indicator = (WGUI_CTX->status_bar_flags & indicator);
    disable_bit_flag(WGUI_CTX->status_bar_flags, indicator);

    switch (indicator)
    {
        case WIDGET_STATUS_BAR_BUSY:
            if (old_indicator)
            {
                widget_paint_status_bar_busy_animator(KAL_FALSE);
                WGUI_CTX->animate_busy_status_bar = 0;
                widget_paint(); /* to redraw the title */
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtPaintDirectly
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtPaintDirectly(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_stop_timer(WIDGET_PAINT_TIMER);
    widget_paint_hdlr(NULL);
}

/****************************************************************
 * Status icons 
 * (Currently used by MsfDialog for New Message Indication)
 *
 * Reference: RedrawCategory154Screen
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_setup_status_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_setup_status_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->title_use_status_icons)
    {
        WGUI_CTX->title_use_status_icons = 1;
    #ifdef WIDGET_RESIDENT_STATUS_ICON
        ShowStatusIconsTitle();
    #else
        if (WGUI_CTX->in_paintbox)
        {
            draw_title_wap();
        }
        else
        {
            draw_title();
        }
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_has_status_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_has_status_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WGUI_CTX->title_use_status_icons ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_redraw_status_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_redraw_status_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_status_icons();
}


/*****************************************************************************
 * FUNCTION
 *  widget_close_status_icons_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_close_status_icons_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->title_use_status_icons)
    {
    #ifndef WIDGET_RESIDENT_STATUS_ICON
        close_status_icons();
    #endif 
        WGUI_CTX->title_use_status_icons = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtEnableSIMService
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool HDIa_widgetExtEnableSIMService(widget_service_on_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WIDGET_DUAL_SIM_SUPPORT
    WGUI_CTX->service_on_sim = sim_id;
#endif /* #ifdef WIDGET_DUAL_SIM_SUPPORT */
    return KAL_TRUE;
}


/****************************************************************
 * 
 * Touch screen support
 *
 * Reference: wgui_touch_screen.c
 *
 ***************************************************************/

#ifdef __MMI_TOUCH_SCREEN__

extern void widget_menu_update_selection_after_focus_changed(void);


/*****************************************************************************
 * FUNCTION
 *  widget_WAP_notify_paintbox_state_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object               [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static void widget_WAP_notify_paintbox_state_changed(void *object)
{
    widget_send_update_event_to_wap();
    widget_notify(_H(object), MsfNotifyStateChange);
}

/*****************************************************************************
 * FUNCTION
 *  wiget_MMI_paintbox_scroll_by_pen
 * DESCRIPTION
 *  Scroll the paintbox by pen
 * PARAMETERS
 *  paintbox            [IN]        The paintbox
 *  vbar                [IN]         
 *  scroll_offset       [IN]       
 *  is_blocking         [IN]       
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
static void wiget_MMI_paintbox_scroll_by_pen(widget_header_struct *paintbox, widget_header_struct *bar, int scroll_offset, kal_bool is_blocking)
{
    WIDGET_UNUSED(paintbox);

    if (_GBAR(bar) == WGUI_CTX->current_vertical_scrollbar)
    {
        WPEN_CTX->last_vbar_indication_offset = scroll_offset;
    }
    else if (_GBAR(bar) == WGUI_CTX->current_horizontal_scrollbar)
    {
        WPEN_CTX->last_hbar_indication_offset = scroll_offset;
    }
    else
    {
        WAP_DBG_ASSERT(0);
    }

    /*
     * Notify BRS module to handle it:
     * Because MMI processes the pen event may not sync with WAP task render the content,
     * we will send MsfNotifyStateChange all the time.
     * BRS will use HDIa_widgetBarGetValues()
     */
    if (!WPEN_CTX->vbar_indication_in_queue)
    {
        /* Update the gadget bar value */
        _GBAR(bar)->value = scroll_offset;
        /*
         * If there are multiple pen events before WAP task process the scrollbar event, 
         * we only put at most one MsfNotifyStateChange to avoid internal queue full.
         */
        WPEN_CTX->vbar_indication_in_queue = 1;
        if (_GBAR(bar) == WGUI_CTX->current_vertical_scrollbar)
        {
            WPEN_CTX->current_vbar_indication_offset = scroll_offset;
        }
        else if (_GBAR(bar) == WGUI_CTX->current_horizontal_scrollbar)
        {
            WPEN_CTX->current_hbar_indication_offset = scroll_offset;
        }
        else
        {
            WAP_DBG_ASSERT(0);
        }
        widget_execute_WAP_p(
                widget_WAP_notify_paintbox_state_changed, 
                (void*)_H(bar),
                is_blocking);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_general_pen_object_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h               [IN]         
 *  point           [IN]        
 *  pen_event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static BOOL widget_general_pen_object_handler(
                widget_header_struct *h,
                mmi_pen_point_struct point,
                mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    U32 type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Reference: widget_MMI_key_handler()
     *
     * If MsfHandler is NULL or widget didn't paint after first focus,
     * We don't process the pen event.
     */
    if (WGUI_CTX->LSK_mask != MsfWidgetUsing && (!h || !WGUI_CTX->is_painted_after_first_focus_changed))
    {
        return MMI_FALSE;
    }

    if (!WGUI_CTX->is_widget_screen)
    {
        WAP_DBG_ASSERT(0);
        return MMI_FALSE;
    }

    if (wap_status != WAP_RUNNING)
    {
        GoBackHistory();
        return MMI_FALSE;
    }

    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WAP_DBG_ASSERT(h->data_type < WIDGET_MAX_TYPE); /* Not released */

    if (WGUI_CTX->LSK_mask == MsfWidgetUsing)
    {
        type = WIDGET_ACTION_TYPE;
    }
    else
    {
        type = h->data_type;
    }
    switch (type)
    {
        case WIDGET_GADGET_BAR_TYPE:
        {
            gui_scrollbar_pen_enum scrollbar_event;
            gui_pen_event_param_struct scrollbar_param;

            if (h == _H(WGUI_CTX->current_vertical_scrollbar))
            {
                widget_gadget_bar_struct *bar;
                vertical_scrollbar *v;

                bar = WGUI_CTX->current_vertical_scrollbar;
                v = &WGUI_CTX->vbar;

                ret = gui_vertical_scrollbar_translate_pen_event(
                        v,
                        pen_event,
                        point.x,
                        point.y,
                        &scrollbar_event,
                        &scrollbar_param);

                if (ret)
                {
                    if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                    {
                        bar->value = scrollbar_param._u.i;
                    }
                    /*
                     * Because MMI processes the pen event may not sync with WAP task render the content,
                     * we will trigger WAP task processes the pen event all the time.
                     */
                    if (bar->parent && IS_FORM_TYPE(bar->parent))
                    {
                        /* Handle scrollbar event in MsfForm */
                        widget_MMI_form_scroll_by_pen(bar->parent, _H(bar), bar->value);
                    }
                    else
                    {
                        /* Notify BRS module to handle it. BRS will use HDIa_widgetBarGetValues()  */
                        wiget_MMI_paintbox_scroll_by_pen(
                            bar->parent, 
                            _H(bar), 
                            bar->value, 
                            KAL_FALSE); /* is_blocking */
                    }
                }
            }
            else if (h == _H(WGUI_CTX->current_horizontal_scrollbar))
            {
                widget_gadget_bar_struct *bar;
                horizontal_scrollbar *v;

                bar = WGUI_CTX->current_horizontal_scrollbar;
                v = &WGUI_CTX->hbar;

                ret = gui_horizontal_scrollbar_translate_pen_event(
                        v,
                        pen_event,
                        point.x,
                        point.y,
                        &scrollbar_event,
                        &scrollbar_param);

                if (ret)
                {
                    if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                    {
                        bar->value = scrollbar_param._u.i;
                    }
                    /* Notify BRS module to handle it. BRS will use HDIa_widgetBarGetValues()  */
                    wiget_MMI_paintbox_scroll_by_pen(
                        bar->parent, 
                        _H(bar), 
                        bar->value, 
                        KAL_FALSE); /* is_blocking */
                }
            }
            else
            {
                ret = MMI_FALSE;
            }
        }
            break;

        case WIDGET_PAINTBOX_TYPE:
        {
            if (pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_UP)
            {
                MsfEvent evt;

                evt.eventMode = 0;
                evt.eventClass = (pen_event == MMI_PEN_EVENT_DOWN) ? MsfPress : MsfRelease;
                evt.eventType = MsfPointer;
                evt.position.x = point.x - WGUI_CTX->display_pos.x;
                evt.position.y = point.y - WGUI_CTX->display_pos.y;
                if (evt.position.x > 0 && evt.position.y > 0)
                {
                    HDIc_widgetUserEvent(h->module_id, (MSF_UINT32) h, &evt);
                    widget_send_update_event_to_wap();
    
                    if (pen_event == MMI_PEN_EVENT_UP)
                    {
                        /* Do not enqueue another pen event until MSF_fsm returns */
                        WPEN_CTX->pen_disabled_by_widget = 1;
                        mmi_pen_disable();  /* mmi_pen_disable() might invoke PEN_ABORT handler again */
                    }
                }
            }
        }
            break;

        case WIDGET_FORM_TYPE:
        {
            widget_MMI_form_pen_handler(h, point, pen_event);
        }
            break;

        case WIDGET_MENU_TYPE:
        {
            gui_list_pen_enum menu_event;

            ret = gui_fixed_list_menu_translate_pen_event(&MMI_fixed_list_menu, pen_event, point.x, point.y, &menu_event);

            if (ret)
            {
                switch (menu_event)
                {
                    case GUI_LIST_PEN_NONE:
                        /* Do nothing */
                        break;

                    case GUI_LIST_PEN_HIGHLIGHT_CHANGED:
                        if (!IS_GADGET_SELECT_GROUP_TYPE(h) && _M(h)->choice_type == MsfExclusiveChoice)
                        {
                            widget_menu_update_selection_after_focus_changed();
                        }
						/* 
						 * Because BRA want to change softkey string when highlight the different menu item
						 * , we send the notify here 
						 */
						widget_notify(_H(WGUI_CTX->current_menu), MsfNotifyStateChange);
						widget_send_update_event_to_wap();

                        /* FALLTHROUGH no break */
                    case GUI_LIST_PEN_NEED_REDRAW:
                        /* Reference: show_fixed_list(). Widget menu does not contain popup description. */
                    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
                        gui_stop_list_highlight_effect();
                    #endif 
                        /*
                         * update menu's first_displayed_item and last_displayed_item 
                         * when the users touch in WIDGET_MENU_TYPE screen
                         */
                        WGUI_CTX->current_menu->first_displayed_item = MMI_fixed_list_menu.first_displayed_item;
                        WGUI_CTX->current_menu->last_displayed_item = MMI_fixed_list_menu.last_displayed_item;
                        gui_lock_double_buffer();
                        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
                        gui_unlock_double_buffer();
                        gui_BLT_double_buffer(
                            MMI_fixed_list_menu.x,
                            MMI_fixed_list_menu.y,
                            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
                            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);

                        break;

                    case GUI_LIST_PEN_ITEM_SELECTED:
                    case GUI_TWOSTATE_PEN_TOGGLE:
                        widget_enqueue_keypad_event(KEY_LSK, KEY_EVENT_UP);
                        break;

                    default:
                        WAP_BYPASS_ASSERT(0);
                }
            }
        }
            break;

        case WIDGET_ACTION_TYPE:
        {
            gui_button_pen_enum button_event;

            if ((WGUI_CTX->LSK_mask == MsfWidgetUsing) || (h == WPEN_CTX->current_LSK))
            {
                ret = gui_icontext_button_translate_pen_event(
                        &MMI_left_softkey,
                        pen_event,
                        point.x,
                        point.y,
                        &button_event);

                switch (button_event)
                {
                    case GUI_BUTTON_PEN_DOWN:
                        /* Currently ignored by widget */
                        break;

                    case GUI_BUTTON_PEN_REPEAT:
                    case GUI_BUTTON_PEN_LONGTAP:
                        /* Currently ignored by widget */
                        break;

                    case GUI_BUTTON_PEN_UP_INSIDE:
                        if (WGUI_CTX->LSK_mask == MsfWidgetUsing)
                        {
                            execute_left_softkey_function(KEY_EVENT_UP);
                        }
                        else
                        {
                            widget_enqueue_keypad_event(KEY_LSK, KEY_EVENT_UP);
                        }
                        break;

                    default:
                        /* Ignore other button events */
                        break;
                }
            }
            else if (h == WPEN_CTX->current_RSK)
            {
                ret = gui_icontext_button_translate_pen_event(
                        &MMI_right_softkey,
                        pen_event,
                        point.x,
                        point.y,
                        &button_event);

                switch (button_event)
                {
                    case GUI_BUTTON_PEN_DOWN:
                        /* Currently ignored by widget */
                        break;

                    case GUI_BUTTON_PEN_REPEAT:
                    case GUI_BUTTON_PEN_LONGTAP:
                        /* Currently ignored by widget */
                        break;

                    case GUI_BUTTON_PEN_UP_INSIDE:
                        widget_enqueue_keypad_event(KEY_RSK, KEY_EVENT_UP);
                        break;

                    default:
                        /* Ignore other button events */
                        break;
                }
            }
            else
            {
                WAP_BYPASS_ASSERT(0);
            }
        }
            break;

    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  widget_general_pen_down_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_general_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *h;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WPEN_CTX->handler = NULL;

    h = (widget_header_struct*) widget_get_current_focused_window();

    /* 
     * If MsfHandler is NULL or widget didn't paint after first focus,
     * We don't process the pen event.
     */
    if (!h || !WGUI_CTX->is_painted_after_first_focus_changed)
    {
        return;
    }

#if defined(WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON)
    /*
     * Because the title bar supports prev/next buttoms in MMS player,
     * we need to check the pen events from (0, 0)
     */
    if (PEN_CHECK_BOUND(
            point.x,
            point.y,
            0,
            0,
            WGUI_CTX->display_pos.x + WGUI_CTX->default_display_size.width,
            WGUI_CTX->display_pos.y + WGUI_CTX->default_display_size.height))
#else /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */ 
    if (PEN_CHECK_BOUND(
            point.x,
            point.y,
            WGUI_CTX->display_pos.x,
            WGUI_CTX->display_pos.y,
            WGUI_CTX->display_size.width,
            WGUI_CTX->display_size.height))
#endif /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */ 
    {
        /* In current design, display area belongs to the focused MsfWindow */
        switch (h->data_type)
        {
            case WIDGET_FORM_TYPE:
                /* FALLTHROUGH no break */
            case WIDGET_PAINTBOX_TYPE:
                /* Scrollbar needs to be handled separately because it maps to MsfGadgetBar */
                if (WGUI_CTX->current_vertical_scrollbar)
                {
                    if (widget_general_pen_object_handler
                        (_H(WGUI_CTX->current_vertical_scrollbar), point, MMI_PEN_EVENT_DOWN))
                    {
                        /* Vertical scrollbar in paintbox */
                        WPEN_CTX->handler = _H(WGUI_CTX->current_vertical_scrollbar);
                    }
                }
                if (!WPEN_CTX->handler && WGUI_CTX->current_horizontal_scrollbar)
                {
                    if (widget_general_pen_object_handler
                        (_H(WGUI_CTX->current_horizontal_scrollbar), point, MMI_PEN_EVENT_DOWN))
                    {
                        /* Horizontal scrollbar in paintbox */
                        WPEN_CTX->handler = _H(WGUI_CTX->current_horizontal_scrollbar);
                    }
                }
                if (!WPEN_CTX->handler)
                {
                    if (widget_general_pen_object_handler(h, point, MMI_PEN_EVENT_DOWN))
                    {
                        /* Paintbox or Form */
                        WPEN_CTX->handler = h;
                    }
                }
                break;

            case WIDGET_MENU_TYPE:
                /* Scrollbar is handled by MMI GUI menu */
                if (widget_general_pen_object_handler(h, point, MMI_PEN_EVENT_DOWN))
                {
                    WPEN_CTX->handler = h;
                }
                break;

            default:
                /* Other types are not supported */
                break;
        }
    }
    else
    {
        gui_button_pen_enum button_event;

        /* Widget only use Pen Up for softkey */

        ret = MMI_FALSE;
        if ((WGUI_CTX->LSK_mask == MsfWidgetUsing) || (WPEN_CTX->current_LSK))
        {
            ret = gui_icontext_button_translate_pen_event(
                    &MMI_left_softkey,
                    MMI_PEN_EVENT_DOWN,
                    point.x,
                    point.y,
                    &button_event);
            if (ret)
            {
                WPEN_CTX->handler = WPEN_CTX->current_LSK;
            }
        }

        if (!ret && WPEN_CTX->current_RSK)
        {
            ret = gui_icontext_button_translate_pen_event(
                    &MMI_right_softkey,
                    MMI_PEN_EVENT_DOWN,
                    point.x,
                    point.y,
                    &button_event);

            if (ret)
            {
                WPEN_CTX->handler = WPEN_CTX->current_RSK;
            }
        }

        if (WGUI_CTX->top_gdi_layer != 0)
        {
            if (WGUI_CTX->top_gdi_layer_is_button_bar == 0)
            {
                widget_copy_title_from_base_layer(WGUI_CTX->top_gdi_layer);
            }
            else if (WGUI_CTX->top_gdi_layer_is_button_bar == 1)
            {
                widget_copy_bar_from_base_layer(WGUI_CTX->top_gdi_layer);
            }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_general_pen_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_general_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_general_pen_object_handler(WPEN_CTX->handler, point, MMI_PEN_EVENT_UP);
    WPEN_CTX->handler = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_general_pen_move_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_general_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_general_pen_object_handler(WPEN_CTX->handler, point, MMI_PEN_EVENT_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_general_pen_abort_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_general_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WPEN_CTX->pen_disabled_by_widget)  /* block PEN_ABORT from mmi_pen_disable() */
    {
        widget_general_pen_object_handler(WPEN_CTX->handler, point, MMI_PEN_EVENT_ABORT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_general_pen_repeat_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_general_pen_repeat_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_general_pen_object_handler(WPEN_CTX->handler, point, MMI_PEN_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  widget_general_pen_long_tap_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_general_pen_long_tap_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_general_pen_object_handler(WPEN_CTX->handler, point, MMI_PEN_EVENT_LONG_TAP);
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_setup_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_setup_pen_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_pen_down_handler(widget_general_pen_down_handler);
    wgui_register_pen_up_handler(widget_general_pen_up_handler);
    wgui_register_pen_move_handler(widget_general_pen_move_handler);
    wgui_register_pen_abort_handler(widget_general_pen_abort_handler);
    wgui_register_pen_repeat_handler(widget_general_pen_repeat_handler);
    wgui_register_pen_long_tap_handler(widget_general_pen_long_tap_handler);
}

/* Abort pen event if keypad event is coming */


/*****************************************************************************
 * FUNCTION
 *  widget_WAP_pen_on_keypad_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_WAP_pen_on_keypad_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Sometimes we use a timer to delay the screen updation, and we might need to abort the
     * timer on keypad event.
     */

    widget_MMS_viewer_abort_pen_scroll_if_necessary(NULL, KAL_TRUE);
}

/* h == NULL to remove pen handler without checking its value */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_remove_pen_handler_if_necessary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_remove_pen_handler_if_necessary(widget_header_struct *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Because the form is removed, we do not need to redraw it */
    widget_MMS_viewer_abort_pen_scroll_if_necessary(h, KAL_FALSE);

    if (!h)
    {
        WPEN_CTX->handler = NULL;
        WPEN_CTX->current_LSK = NULL;
        WPEN_CTX->current_RSK = NULL;
        WGUI_CTX->current_vertical_scrollbar = NULL;
        WGUI_CTX->current_horizontal_scrollbar = NULL;
    }

    /* 
     * Although some of the following flags are reset in widget_paint_area()
     * There is a race condition when Pen Down between HDIa_widgetRemove() and widget_paint_hdlr()
     */
    if (h == WPEN_CTX->handler)
    {
        WPEN_CTX->handler = NULL;
    }
    if (h == WPEN_CTX->current_LSK)
    {
        WPEN_CTX->current_LSK = NULL;
    }
    if (h == WPEN_CTX->current_RSK)
    {
        WPEN_CTX->current_RSK = NULL;
    }
    if (h == (widget_header_struct*) WGUI_CTX->current_vertical_scrollbar)
    {
        WGUI_CTX->current_vertical_scrollbar = NULL;
    }
    if (h == (widget_header_struct*) WGUI_CTX->current_horizontal_scrollbar)
    {
        WGUI_CTX->current_horizontal_scrollbar = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_reset_pen_on_screen_switch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_reset_pen_on_screen_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Widget still needs to handle MMI_PEN_EVENT_ABORT inside mmi_pen_reset() */
    mmi_pen_reset();

    /* Reset context after mmi_pen_reset() */
    WPEN_CTX->handler = NULL;
    WPEN_CTX->current_LSK = NULL;
    WPEN_CTX->current_RSK = NULL;
    WGUI_CTX->current_vertical_scrollbar = NULL;
    WGUI_CTX->current_horizontal_scrollbar = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_pen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_widget_context.pen_cntx, 0, sizeof(widget_pen_context_struct));
}

/* WAP is reset (typically out-of-memory) */


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_pen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WPEN_CTX->pen_disabled_by_widget)
    {
        mmi_pen_enable();
        WPEN_CTX->pen_disabled_by_widget = 0;
    }
}

/* Hook function after Msf FSM is processed */

/*****************************************************************************
 * FUNCTION
 *  widget_process_pending_pen_event
 * DESCRIPTION
 *    Check if having the pending scroll bar's pen events and notify to BRS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define WIDGET_SCROLL_BAR_SYNC_COUNTER    3
static void widget_process_pending_pen_event(void)
{
    static int count = 0;
    /* Check if in the browser screen */
    if (WGUI_CTX->current_window && 
        WGUI_CTX->current_window == WGUI_CTX->current_focused_paintbox)
    {
        /* Update the horizontal scroll bar value */
        if (WPEN_CTX->last_hbar_indication_offset != WPEN_CTX->current_hbar_indication_offset)
        {
            WPEN_CTX->current_hbar_indication_offset = WPEN_CTX->last_hbar_indication_offset;
            if (WGUI_CTX->current_horizontal_scrollbar)
            {
				/* Need to notify BRS module to update the browser if having pending pen events */
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PROCESS_PENDING_PEN_EVENT_H_BAR);
                wiget_MMI_paintbox_scroll_by_pen(
                    WGUI_CTX->current_horizontal_scrollbar->parent,
                    _H(WGUI_CTX->current_horizontal_scrollbar),
                    WPEN_CTX->current_hbar_indication_offset,
                    KAL_FALSE); /* is_blocking */
            }
        }
        else
        {
            if (WGUI_CTX->current_horizontal_scrollbar)
            {
                WPEN_CTX->current_hbar_indication_offset = WGUI_CTX->current_horizontal_scrollbar->value;
                WPEN_CTX->last_hbar_indication_offset = WGUI_CTX->current_horizontal_scrollbar->value;
            }
        }

        /* Update the vertical scroll bar value */
        if (WPEN_CTX->last_vbar_indication_offset != WPEN_CTX->current_vbar_indication_offset)
        {
            if (count >= WIDGET_SCROLL_BAR_SYNC_COUNTER)
            {
                /* 
                 * Becuase BRS may not accept the widget's vbar_offset,
                 * we add the mechanism to check this situation.
                 *
                 * If the paintbox has the hbar, BRS will not includes hbar height in its rendering area
                 * but the widget will includes hbar height in the vbar setting.
                 */
                WPEN_CTX->last_vbar_indication_offset = WPEN_CTX->current_vbar_indication_offset;
            }
            count ++;
            WPEN_CTX->current_vbar_indication_offset = WPEN_CTX->last_vbar_indication_offset;
            if (WGUI_CTX->current_vertical_scrollbar)
            {
				/* Need to notify BRS module to update the browser if having pending pen events */
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PROCESS_PENDING_PEN_EVENT_V_BAR);
                wiget_MMI_paintbox_scroll_by_pen(
                    WGUI_CTX->current_vertical_scrollbar->parent,
                    _H(WGUI_CTX->current_vertical_scrollbar),
                    WPEN_CTX->current_vbar_indication_offset,
                    KAL_TRUE); /* is_blocking */
            }
        }
        else
        {
            count = 0;
            if (WGUI_CTX->current_vertical_scrollbar)
            {
                WPEN_CTX->current_vbar_indication_offset = WGUI_CTX->current_vertical_scrollbar->value;
                WPEN_CTX->last_vbar_indication_offset = WGUI_CTX->current_vertical_scrollbar->value;
            }
        }
        /* Need to notify BRS module to update the browser if having pending pen events */
    }
}

/*****************************************************************************
 * FUNCTION
 *  widget_pen_on_post_msf_fsm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_pen_on_post_msf_fsm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WPEN_CTX->vbar_indication_in_queue = 0;
    WPEN_CTX->hbar_indication_in_queue = 0;
    widget_process_pending_pen_event();
    if (WPEN_CTX->pen_disabled_by_widget)
    {
        mmi_pen_enable();
        WPEN_CTX->pen_disabled_by_widget = 0;
    }
}


#endif /* __MMI_TOUCH_SCREEN__ */ 


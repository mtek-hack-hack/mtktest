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
 * widget_form.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Widget form
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "wgui_categories.h"
#include "gdi_include.h"
#include "lcd_sw_rnd.h"

/****************************************************************
 FORM 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetFormCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  size                [IN]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetFormCreate(MSF_UINT8 modId, MsfSize *size, int propertyMask, MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = widget_create_form(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    if (size)
    {
        w->size = *size;
    }
    else
    {
        w->size = WGUI_CTX->default_display_size;
    }

    w->property_mask = propertyMask;
    widget_set_attrib(w, style, defaultStyle);

    return (MsfWindowHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFromSetMMSViewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                         [IN]        The MsfForm
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFromSetMMSViewer(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (w->MMs_view_title)
    {
        /* WAP_DBG_ASSERT(0); */
        return;
    }

#ifdef GUI_SUBMENU_USE_THICK_TITLE
    /*
     * Because MMS application will call this function first and then entry the widget screen,
     * we need to setup the title layout here.
     */
	gui_setup_submenu_layout();
    wgui_title_set_thick(MMI_TRUE);
    Trace2(TRACE_GROUP_2, "[widget] gui_setup_submenu_layout MMI_title_height:%d ", MMI_title_height);
#endif

#if defined(WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON)
    w->MMs_view_title = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_MMS_viewer_title_struct));
    w->MMs_view_title->prev_botton_img = LEFT_RED_ARROW;
    w->MMs_view_title->prev_botton_x = MMI_TITLEBAR_BUTTON_GAP;
#ifdef WIDGET_RESIDENT_STATUS_ICON
    w->MMs_view_title->prev_botton_y =
        (MMI_STATUS_BAR_HEIGHT) + (MMI_title_height >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
#else
    w->MMs_view_title->prev_botton_y =
        (MMI_title_height >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
#endif /* WIDGET_RESIDENT_STATUS_ICON */

    w->MMs_view_title->next_botton_img = RIGHT_RED_ARROW;
    w->MMs_view_title->next_botton_x = UI_device_width - (MMI_TITLEBAR_BUTTON_GAP) - (MMI_TITLEBAR_BUTTON_WIDTH);
#ifdef WIDGET_RESIDENT_STATUS_ICON
    w->MMs_view_title->next_botton_y =
        (MMI_STATUS_BAR_HEIGHT) + (MMI_title_height >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
#else
    w->MMs_view_title->next_botton_y =
        (MMI_title_height >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1);
#endif /* WIDGET_RESIDENT_STATUS_ICON */
    w->MMs_view_title->button_width = MMI_TITLEBAR_BUTTON_WIDTH;
    w->MMs_view_title->button_height = MMI_TITLEBAR_BUTTON_HEIGHT;
    w->MMs_view_title->pen_by_prev_button = 0;
    w->MMs_view_title->pen_by_next_button = 0;
    w->MMs_view_title->prev_button_pressed = 0;
    w->MMs_view_title->next_button_pressed = 0;
#endif /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */ 

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFromClearMMSViewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd                         [IN]        The MsfForm
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFromClearMMSViewer(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    if (!wnd)
    {
        return;
    }
    if (!IS_FORM_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    if (form->MMs_view_title)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, form->MMs_view_title);
        form->MMs_view_title = NULL;
    }

#ifdef __MMI_TOUCH_SCREEN__
    memset(&(form->mob_pen_info), 0, sizeof(widget_MOB_pen_struct));
#endif

    WGUI_CTX->display_size = WGUI_CTX->default_display_size;

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormGetSmilDisplaySize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFormGetSmilDisplaySize(MsfSize *size)
{
#if defined (WIDGET_SMIL_SLIDING_BAR) && defined(WIDGET_LARGE_RESOLUTION)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_w = 0, img_h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * SMA call this function before HDIa_widgetExtFormSetSlidingSMIL(),
     * we calculate MMS form display size here.
     */

    gui_measure_image((PU8) GetImage(MEA_IMG_SMIL_SLIDING_BAR_REGION), &img_w, &img_h);
    WGUI_CTX->display_size.height = WGUI_CTX->default_display_size.height - (img_h + WIDGET_SMIL_SLIDING_BAR_V_SPACE);
    size->width = WGUI_CTX->display_size.width;
    size->height = WGUI_CTX->display_size.height;

#else  /* WIDGET_SMIL_SLIDING_BAR && WIDGET_LARGE_RESOLUTION */
    size->width = WGUI_CTX->default_display_size.width;
    size->height = WGUI_CTX->default_display_size.height;
#endif  /* WIDGET_SMIL_SLIDING_BAR && WIDGET_LARGE_RESOLUTION */
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormDisableGadgetBorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd             [IN]        
 *  do_disable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFormDisableGadgetBorder(MsfWindowHandle wnd, kal_bool do_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_FORM_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    if (do_disable)
    {
        w->form_flags |= WIDGET_FORM_FLAG_DISABLE_GADGET_BORDER;
    }
    else
    {
        w->form_flags &= ~WIDGET_FORM_FLAG_DISABLE_GADGET_BORDER;
    }

    if (widget_is_window_gadget_displayed(wnd))
    {
        widget_paint();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormSetArrowIndication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wnd         [IN]        
 *  left        [IN]        
 *  right       [IN]        
 *  up          [IN]        
 *  down        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFormSetArrowIndication(MsfWindowHandle wnd, int left, int right, int up, int down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_FORM_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }
    w = _FORM(wnd);
    if (left)
    {
        enable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_LEFT_ARROW);
    }
    else
    {
        disable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_LEFT_ARROW);
    }
    if (right)
    {
        enable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_RIGHT_ARROW);
    }
    else
    {
        disable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_RIGHT_ARROW);
    }
    if (up)
    {
        enable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_UP_ARROW);
    }
    else
    {
        disable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_UP_ARROW);
    }
    if (down)
    {
        enable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_DOWN_ARROW);
    }
    else
    {
        disable_bit_flag(w->form_flags, WIDGET_FORM_FLAG_SHOW_DOWN_ARROW);
    }

    if (widget_is_window_gadget_displayed(wnd))
    {
        widget_paint();
    }
}

/* Not Implemented */
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormSetSmilTotalTime
 * DESCRIPTION
 *  Used by MMS SMIL player to indicate the remaining seconds in title.
 * PARAMETERS
 *  wnd             [IN]        Tareget MsfForm
 *  sec             [IN]        Number of seconds.-1 to disable title index.
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFormSetSmilTotalTime(MsfWindowHandle wnd, int sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_FORM_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    _FORM(wnd)->total_sec = (kal_int16) sec;

    if (widget_is_window_gadget_displayed(wnd))
    {
    #ifdef WIDGET_SMIL_SLIDING_BAR
        widget_add_paint_sliding_bar_command();
    #else 
        widget_add_paint_title_command();
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormSetSmilRemainTime
 * DESCRIPTION
 *  Used by MMS SMIL player to indicate the remaining seconds in title.
 * PARAMETERS
 *  wnd             [IN]        Tareget MsfForm
 *  sec             [IN]        Number of seconds.-1 to disable title index.
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFormSetSmilRemainTime(MsfWindowHandle wnd, int sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_FORM_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }

#ifdef WIDGET_SMIL_SLIDING_BAR
    /* Better display during slide switching */
    if (sec > 0)
    {
        sec--;
    }
#endif /* WIDGET_SMIL_SLIDING_BAR */ 

    _FORM(wnd)->remain_sec = (kal_int16) sec;

    if (widget_is_window_gadget_displayed(wnd))
    {
#ifdef WIDGET_SMIL_SLIDING_BAR
        widget_add_paint_sliding_bar_command();
#else
        widget_add_paint_title_command();
#endif  /* WIDGET_SMIL_SLIDING_BAR */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFromSetMMSAudioCallBack
 * DESCRIPTION
 *  Used by MMS player to register audio callback function
 * PARAMETERS
 *  wnd             [IN]        Tareget MsfForm
 *  cb              [IN]        the audio callback function
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFromSetAudioCallBack(MsfWindowHandle wnd, MsfFormAudioCallBack cb)
{
    if (IS_FORM_TYPE(wnd))
    {
        WGUI_CTX->current_window_audio_cb = cb;
    }
}


/****************************************************************
 * Sliding SMIL Style Support
 ***************************************************************/

#ifdef WIDGET_SLIDING_SMIL_SUPPORT

/* Compute the new size of image gadget by shrinking to screen width and meet 
   the requirements of JPEG decoder and GDI layer memory constraints */


/*****************************************************************************
 * FUNCTION
 *  widget_form_sliding_SMIL_fit_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gimg        [IN]     
 *  info        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_form_sliding_SMIL_fit_image(widget_gadget_image_struct *gimg, widget_sliding_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 width, height;   /* Gadget width and height */
    kal_uint32 img_width = 0, img_height = 0;
    kal_uint32 width_round, height_round;   /* round to muliply of 16 */
    kal_int32 output_x, output_y, output_width, output_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width = (kal_uint32) gimg->size.width;
    height = (kal_uint32) gimg->size.height;
    if (gimg->image)
    {
        img_width = (kal_uint32) widget_image_width(gimg->image);
        img_height = (kal_uint32) widget_image_height(gimg->image);
    }

    if (width == 0 || height == 0 || !gimg->image || img_width == 0 || img_height == 0)
    {
        gimg->size.width = 0;
        gimg->size.height = 0;
        return KAL_FALSE;
    }

    if (width > (kal_uint32) WGUI_CTX->display_size.width)
    {
        /* SMA has problem */
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    /* the rule need to ve the samw with displayImageObject() [saui.c] */
    if (img_width > width || img_height > height)
    {
            HDIa_widgetExtImageUtilFixBox(
                width,
                height,
                img_width,
                img_height,
                &output_x,
                &output_y,
                &output_width,
                &output_height);

            width = output_width;
            height = output_height;
    }
    else
    {
        width = img_width;
        height = img_height;
    }

    /*
     * Note that check A does not imply check B and check B does not imply check A neither. 
     * * Example1: an image meets check B might still use more memory than than JPEG framebuffer
     * *       35x1100 <176x220=38720, but it use 3x69=207 (16x16) blocks = 207*256 = 52992 bytes.
     * * Example2: an image meets check A does not meet check B
     * *    176x224 can be put in JPEG framebuffer in 176x220 projects.
     */

    /*
     * Check A: Test if we can display it due to JPEG decoder limitation 
     */

    /* NUM_JPEG_BUFFER_PIXELS_16: The number of 16x16 blocks available in JPEG frame buffer. */
#define NUM_JPEG_BUFFER_PIXELS_16   ((GDI_LCD_WIDTH/16+1)*((GDI_LCD_HEIGHT/16+1)))

    width_round = (width + 15) / 16;
    height_round = (height + 15) / 16;
    if (width_round * height_round > NUM_JPEG_BUFFER_PIXELS_16) /* Compare number of 16x16 blocks */
    {
        do
        {
            if (img_width > img_height)
            {
                width_round--;
                width = width_round * 16;
                height = width * img_height / img_width;
                height_round = (height + 15) / 16;
            }
            else
            {
                height_round--;
                height = height_round * 16;
                width = height * img_width / img_height;
                width_round = (width + 15) / 16;
            }
        } while (width_round * height_round > NUM_JPEG_BUFFER_PIXELS_16);
    }

    if (width == 0 || height == 0)
    {
        /* For a very strange image */
        WAP_DBG_ASSERT(0);
        width = img_width;
        height = img_height;
    }

#ifdef WIDGET_PRECACHE_IMAGE

    /* Check B: To guarentee that width * height < GDI_LCD_WIDTH * GDI_LCD_HEIGHT */
    if (width * height > GDI_LCD_WIDTH * GDI_LCD_HEIGHT)
    {
        kal_uint32 tmp;

        /* We will shrink but not enlarge width/height here */
        if (img_width > img_height)
        {
            tmp = (kal_uint32) floor(sqrt((double)GDI_LCD_WIDTH * GDI_LCD_HEIGHT * img_width / img_height));

            WAP_DBG_ASSERT(tmp < width);
            if (tmp < width)
            {
                width = tmp;
                height = width * img_height / img_width;
                height = (height) ? height : 1;
            }
        }
        else
        {
            tmp = (kal_uint32) floor(sqrt((double)GDI_LCD_WIDTH * GDI_LCD_HEIGHT * img_height / img_width));

            WAP_DBG_ASSERT(tmp < height);
            if (tmp < height)
            {
                height = tmp;
                width = height * img_width / img_height;
                width = (width) ? width : 1;
            }
        }

        WAP_DBG_ASSERT(((width + 15) / 16) * ((height + 15) / 16) <= NUM_JPEG_BUFFER_PIXELS_16);
        while (width * height > GDI_LCD_WIDTH * GDI_LCD_HEIGHT
               || ((width + 15) / 16) * ((height + 15) / 16) > NUM_JPEG_BUFFER_PIXELS_16 /* Be paranoid */ )
        {
            if (--width == 0)
            {
                width = 1;
            }
            if (--height == 0)
            {
                height = 1;
            }
        }
    }

#endif /* WIDGET_PRECACHE_IMAGE */ 

    gimg->size.width = (MSF_UINT16) width;
    gimg->size.height = (MSF_UINT16) height;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_sliding_SMIL_fit_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gimg            [IN]         
 *  info            [IN]         
 *  max_height      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_form_sliding_SMIL_fit_text(
                    widget_gadget_image_struct *gimg,
                    widget_sliding_info_struct *info,
                    MSF_INT16 max_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Width is defined by SMA SMTR rendering engine. We do (should) not change gadget width */

    /* Actually SMA already set text gadget widget/height, we do it again for customized padding in widget */
    /* Potential issue: Can we shrink the height of text gadget without notifying SMA? */
    if (info->max_text_gadget_height != 0)
    {
        if (info->max_text_gadget_height >= max_height)
        {
            gimg->size.height = max_height;
        }
        else
        {
            gimg->size.height = info->max_text_gadget_height;
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_sliding_SMIL_center_align_gadget
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gadget              [IN]     
 *  sliding_info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_sliding_SMIL_center_align_gadget(
                widget_gadget_image_struct *gadget,
                widget_sliding_info_struct *sliding_info)
{
#ifdef WIDGET_SLIDING_SMIL_VBAR
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sliding_info->vbar)
    {
        gadget->position.x = (WGUI_CTX->display_size.width - MSF_CFG_SCROLLBAR_WIDTH - gadget->size.width) / 2;
        if (r2lMMIFlag)
        {
            gadget->position.x += MSF_CFG_SCROLLBAR_WIDTH;
        }
    }
    else
    {
        gadget->position.x = (WGUI_CTX->display_size.width - gadget->size.width) / 2;
    }
#else /* WIDGET_SLIDING_SMIL_VBAR */ 
    gadget->position.x = (WGUI_CTX->display_size.width - gadget->size.width) / 2;
#endif /* WIDGET_SLIDING_SMIL_VBAR */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_update_for_sliding_SMIL
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_form_update_for_sliding_SMIL(widget_form_struct *form)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *node;
    widget_gadget_image_struct *gimg_text, *gimg_image;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!form->sliding_info)    /* Sliding not enabled for this form */
    {
        return KAL_FALSE;
    }

    i = 0;
    gimg_text = gimg_image = NULL;
    foreach(_H(form), GADGET_IMAGE, node,
            {
            if (_GIMG(node)->image && _IMG(_GIMG(node)->image)->is_drawn_image) gimg_text = _GIMG(node);
            else
            gimg_image = _GIMG(node); i++;}
    );

    if (i == 0 || i > 2)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FORM_UPDATE_FOR_SLIDING_SMIL);
        return KAL_FALSE;
    }

    /* Fit to content width */
    /* the image will have top & bottom padding */
    if (gimg_image)
    {
        widget_form_sliding_SMIL_fit_image(gimg_image, form->sliding_info);
        widget_form_sliding_SMIL_center_align_gadget(gimg_image, form->sliding_info);
    }

    /* the text doesn't have top & bottom padding */
    if (gimg_text)
    {
        /*
         * Padding when scrolling down with text gadget at bottom 
         * * Text gadget must be scrolled inside of the screen as a whole.
         * * If text gadget is larger than the screen height (scrollable), do not display text and image gadget together
         */
        MSF_INT16 max_height = WGUI_CTX->display_size.height;

        widget_form_sliding_SMIL_fit_text(gimg_text, form->sliding_info, max_height);
        widget_form_sliding_SMIL_center_align_gadget(gimg_text, form->sliding_info);
    }

    WAP_DBG_ASSERT(!gimg_image || gimg_image->size.width <= WGUI_CTX->display_size.width);
    WAP_DBG_ASSERT(!gimg_text || gimg_text->size.width <= WGUI_CTX->display_size.width);

    /* Layout for single object < content size */
    if (gimg_image && !gimg_text && gimg_image->size.width <= WGUI_CTX->display_size.width /* unnecessary */  &&
        gimg_image->size.height <= WGUI_CTX->display_size.height - WIDGET_SLIDING_SMIL_TOP * 2)
    {
        gimg_image->position.y = (WGUI_CTX->display_size.height - gimg_image->size.height) >> 1;
        goto return_true;
    }

    if (gimg_text && !gimg_image && gimg_text->size.width <= WGUI_CTX->display_size.width /* unnecessary */  &&
        gimg_text->size.height <= WGUI_CTX->display_size.height)
    {
        gimg_text->position.y = (WGUI_CTX->display_size.height - gimg_text->size.height) >> 1;
        goto return_true;
    }

    /* Layout for two object < content size */
    if (gimg_image && gimg_text &&
        (gimg_image->size.height + gimg_text->size.height + WIDGET_SLIDING_SMIL_TOP * 3 /* Padding reserved */  <=
         WGUI_CTX->display_size.height))
    {
        MSF_INT16 spacing = (WGUI_CTX->display_size.height - gimg_image->size.height - gimg_text->size.height) / 3;
        MSF_INT16 curr_y = spacing;

        if (form->sliding_info->image_on_top)
        {
            gimg_image->position.y = curr_y;
            curr_y += gimg_image->size.height + spacing;
            gimg_text->position.y = curr_y;
        }
        else
        {
            gimg_text->position.y = curr_y;
            curr_y += gimg_text->size.height + spacing;
            gimg_image->position.y = curr_y;
        }
        goto return_true;
    }

    /* Format for two object > content size */
    if (form->sliding_info->image_on_top)
    {
        MSF_INT16 curr_y = WIDGET_SLIDING_SMIL_TOP;

        if (gimg_image)
        {
            gimg_image->position.y = curr_y;
            curr_y += gimg_image->size.height + WIDGET_SLIDING_SMIL_BOTTOM;
        }

        if (gimg_text)
        {
            gimg_text->position.y = curr_y;
        }

        if (gimg_image && WGUI_CTX->current_focused_gadget != _H(gimg_image))
        {
            HDIa_widgetSetInFocus((MsfGadgetHandle) gimg_image, 1);     /* Send MsfNotifyLostFocus to text gadget if present */
            /* SMA expects MsfNotifyFocus from text gadget, we should not send it here */
        }
    }
    else
    {
        MSF_INT16 curr_y = WIDGET_SLIDING_SMIL_TOP;

        if (gimg_text)
        {
            gimg_text->position.y = curr_y;
            curr_y += gimg_text->size.height + WIDGET_SLIDING_SMIL_BOTTOM;
        }

        if (gimg_image)
        {
            gimg_image->position.y = curr_y;
        }

        if (gimg_text && WGUI_CTX->current_focused_gadget != _H(gimg_text))
        {
            HDIa_widgetSetInFocus((MsfGadgetHandle) gimg_text, 1);
            widget_notify(_H(gimg_text), MsfNotifyFocus);
        }
    }

    WAP_DBG_ASSERT(!gimg_image || gimg_image->position.y >= WIDGET_SLIDING_SMIL_TOP);
    WAP_DBG_ASSERT(!gimg_text || gimg_text->position.y >= WIDGET_SLIDING_SMIL_TOP);

  return_true:

#ifdef WIDGET_SLIDING_SMIL_VBAR
    {
        /* Update form height */
        int form_height, text_bottom, image_bottom;
        int total_height_without_text;

        if (gimg_image == NULL)
        {
            /* the text doesn't have top & bottom padding */
            text_bottom = image_bottom = 0;
            text_bottom = gimg_text->position.y + gimg_text->size.height;
        }
        else
        {
            /* the image will have top & bottom padding */
            text_bottom = image_bottom = WIDGET_SLIDING_SMIL_TOP;
            if (gimg_text)
            {
                text_bottom = gimg_text->position.y + gimg_text->size.height;
            }
            if (gimg_image)
            {
                image_bottom = gimg_image->position.y + gimg_image->size.height + WIDGET_SLIDING_SMIL_BOTTOM;
            }

        }

        form_height = WIDGET_MAX(image_bottom, text_bottom);

        total_height_without_text = form_height;
        if (gimg_text)
        {
            /*
             * the gadget image size.height doesn't include the top and bottom padding space,
             * but total_height_without_text includes gadget image height and all padding space.
             */
            total_height_without_text -= gimg_text->size.height;
        }

        if (gimg_text)
        {
            form->sliding_info->text_gadget_height = gimg_text->size.height;
        }
        else
        {
            form->sliding_info->text_gadget_height = 0;
        }
        /* total_height_without_text will have top & bottom padding */
        form->sliding_info->total_height_without_text = total_height_without_text;
        form->sliding_info->total_height = form->sliding_info->total_text_height + total_height_without_text;
        if (form->sliding_info->vbar)
        {
            _GBAR(form->sliding_info->vbar)->max_value = form->sliding_info->total_height;
            widget_add_paint_gadget_command(_H(form->sliding_info->vbar));
        }
    }
#endif /* WIDGET_SLIDING_SMIL_VBAR */ 

    return KAL_TRUE;
}

/* When releasing a form object */


/*****************************************************************************
 * FUNCTION
 *  widget_form_remove_sliding_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_remove_sliding_info(widget_form_struct *form)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (form->sliding_info)
    {
        if (form->sliding_info->vbar)
        {
            HDIa_widgetRemove((MSF_UINT32) form, form->sliding_info->vbar);
            HDIa_widgetRelease(form->sliding_info->vbar);
            form->sliding_info->vbar = 0;
        }

        MSF_MEM_FREE(MSF_MODID_WIDGET, form->sliding_info);
        form->sliding_info = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormSetSlidingSMIL
 * DESCRIPTION
 *  Set sliding-SMIL style and change the position of child gadgets in this MsfForm
 * PARAMETERS
 *  wnd                         [IN]        The MsfForm
 *  image_on_top                [IN]        Whether image or text area is on top
 *  max_text_gadget_height      [IN]        Maximum possible height of text area (not exceeding screen height)
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFormSetSlidingSMIL(MsfWindowHandle wnd, kal_bool image_on_top, kal_int16 max_text_gadget_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);
    MsfSize vbar_size;
    MsfPosition vbar_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (w->sliding_info)
    {
        /* WAP_DBG_ASSERT(0); */
        return;
    }

    HDIa_widgetExtFromSetMMSViewer(wnd);
    HDIa_widgetExtFormGetSmilDisplaySize(&WGUI_CTX->display_size);
    w->size = WGUI_CTX->display_size;

    w->sliding_info = MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_sliding_info_struct));
    w->sliding_info->image_on_top = image_on_top ? 1 : 0;
    w->sliding_info->max_text_gadget_height = max_text_gadget_height;
    w->sliding_info->scroll_offset_backup = 0;
    w->sliding_info->restore_scroll_offset_before_paint = 0;

#ifdef WIDGET_SLIDING_SMIL_VBAR
    w->sliding_info->total_text_height = max_text_gadget_height;        /* Temp value */
    w->sliding_info->text_scroll_offset = 0;
    w->sliding_info->total_height_without_text = 0;
    w->sliding_info->total_height = max_text_gadget_height; /* Temp value */

    vbar_size.width = MSF_CFG_SCROLLBAR_WIDTH;
    vbar_size.height = WGUI_CTX->display_size.height;
    w->sliding_info->vbar = HDIa_widgetBarCreate(
                                w->module_id,
                                MsfVerticalScrollBar,
                                w->sliding_info->total_height,
                                0,
                                &vbar_size,
                                0,
                                0);
    vbar_pos.y = 0;
    if (r2lMMIFlag)
    {
        vbar_pos.x = 0;
    }
    else
    {
        vbar_pos.x = WGUI_CTX->display_size.width - MSF_CFG_SCROLLBAR_WIDTH;
    }
    HDIa_widgetWindowAddGadget(wnd, w->sliding_info->vbar, &vbar_pos, NULL);

#ifdef __MMI_TOUCH_SCREEN__
    w->sliding_info->text_scroll_notification_hdlr = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */

#endif /* WIDGET_SLIDING_SMIL_VBAR */ 

    widget_form_update_for_sliding_SMIL(w);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormClearSlidingSMIL
 * DESCRIPTION
 *  When switch to next/prev slide. Reset sliding informatin.
 * PARAMETERS
 *  wnd     [IN]        The MsfForm
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtFormClearSlidingSMIL(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wnd)
    {
        return;
    }
    if (!IS_FORM_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    if (widget_is_window_gadget_displayed(wnd))
    {
        /* Reset scrolling position */
        WGUI_CTX->current_pos.y = WGUI_CTX->display_pos.y;
    }

    widget_form_remove_sliding_info(_FORM(wnd));
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_stop_all_image_nb_draw();
#endif
    HDIa_widgetExtFromClearMMSViewer(wnd);

#if defined(__MMI_TOUCH_SCREEN__)
    WPEN_CTX->MMS_viewer_scroll_offset = 0;
#endif 

}

#ifdef WIDGET_SLIDING_SMIL_VBAR


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormSetSlidingSMILTextHeight
 * DESCRIPTION
 *  Configure the height of SMIL text
 * PARAMETERS
 *  wnd                     [IN]        The form
 *  total_text_height       [IN]        Total text height (which might exceed the screen size)
 *  text_line_height        [IN]        The single line height
 * RETURNS
 *  void
 * REMARKS
 *  Used after HDIa_widgetExtFormSetSlidingSMIL.
 *****************************************************************************/
void HDIa_widgetExtFormSetSlidingSMILTextHeight(MsfWindowHandle wnd, int total_text_height, int text_line_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (w->sliding_info)
    {
        if (w->sliding_info->total_text_height != total_text_height)
        {
            /* total_text_height doesn't have top & bottom padding */
            w->sliding_info->total_text_height = total_text_height;
            /* total_height_without_text will have top & bottom padding */
            w->sliding_info->total_height = w->sliding_info->total_text_height + w->sliding_info->total_height_without_text;
            w->sliding_info->text_line_height = text_line_height;
            if (w->sliding_info->vbar)
            {
                _GBAR(w->sliding_info->vbar)->max_value = w->sliding_info->total_height;
                widget_add_paint_gadget_command(_H(w->sliding_info->vbar));
            }
        }
    }
    else
    {
        WAP_DBG_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormUpdateSlidingSMILTextOffset
 * DESCRIPTION
 *  Update the scrolling offset of SMIL text
 *  (SMIL text is scrolled inside the text gadget by SMA module)
 * PARAMETERS
 *  wnd                     [IN]        The form
 *  text_scroll_offset      [IN]        Positive scrolling offset in pixels
 * RETURNS
 *  void
 * REMARKS
 *  Used after HDIa_widgetExtFormSetSlidingSMIL.
 *****************************************************************************/
void HDIa_widgetExtFormUpdateSlidingSMILTextOffset(MsfWindowHandle wnd, int text_scroll_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (w->sliding_info)
    {
        if (w->sliding_info->text_scroll_offset != text_scroll_offset)
        {
            w->sliding_info->text_scroll_offset = text_scroll_offset;
            if (w->sliding_info->vbar)
            {
                _GBAR(w->sliding_info->vbar)->value =
                    text_scroll_offset + (WGUI_CTX->display_pos.y - WGUI_CTX->current_pos.y);
                widget_add_paint_gadget_command(_H(w->sliding_info->vbar));
            }
        }
    }
    else
    {
        WAP_DBG_ASSERT(0);
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormRegisterSlidingSMILScrollNotification
 * DESCRIPTION
 *  Set the scroll notification handler (typically by SMA module)
 *  The handler is invoked when the scrollbar is scrollbed by touch screen in MMI task.
 * PARAMETERS
 *  wnd                                 [IN]        The form
 *  text_scroll_notification_hdlr       [IN]        
 * RETURNS
 *  void
 * REMARKS
 *  Please note that applications (i.e. SMA module) should handle multiple scrollbar pen events in one time,
 *  otherwise, application might not finish incoming pen events (which are fired very frequently)
 *  
 *  the 'text_scroll_notification_hdlr' typically sends signal to SMA module.
 *  
 *  Used after HDIa_widgetExtFormSetSlidingSMIL.
 *****************************************************************************/
void HDIa_widgetExtFormRegisterSlidingSMILScrollNotification(
        MsfWindowHandle wnd,
        void (*text_scroll_notification_hdlr) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (w->sliding_info)
    {
        w->sliding_info->text_scroll_notification_hdlr = text_scroll_notification_hdlr;
    }
    else
    {
        WAP_DBG_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormGetSlidingSMILTextOffsetByPen
 * DESCRIPTION
 *  Set the scroll notification handler (typically by SMA module)
 *  The handler is invoked when the scrollbar is scrollbed by touch screen in MMI task.
 * PARAMETERS
 *  wnd                     [IN]        The form
 *  text_scroll_offset      [OUT]       
 * RETURNS
 *  void
 * REMARKS
 *  Used after HDIa_widgetExtFormSetSlidingSMIL
 *****************************************************************************/
void HDIa_widgetExtFormGetSlidingSMILTextOffsetByPen(MsfWindowHandle wnd, int *text_scroll_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (w->sliding_info)
    {
        *text_scroll_offset = w->sliding_info->text_scroll_offset;
    }
    else
    {
        WAP_DBG_ASSERT(0);
        *text_scroll_offset = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_sliding_SMIL_adjust_gadget_focus_by_pen
 * DESCRIPTION
 *  Adjust the focus of gadget.
 * PARAMETERS
 *  form        [IN]         
 * RETURNS
 *  void
 * REMARKS
 *  1. This function should be invoked in WAP task context. (typically by SMA module)
 *  2. We need to focus or defocus text gadget properly such that SMA module can registerUp Arrow and Down Arrow key correctly.
 *  (Touch screen needs to co-work with keypad)
 *  3. Reference: widget_form_scroll_up_sliding_SMIL(), widget_form_scroll_down_sliding_SMIL()
 *****************************************************************************/
static void widget_form_sliding_SMIL_adjust_gadget_focus_by_pen(widget_form_struct *form)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *gimg_text, *gimg_image;
    int form_yoffset = WGUI_CTX->current_pos.y - WGUI_CTX->display_pos.y;
    kal_bool change_focus = KAL_FALSE;
    widget_sliding_info_struct *sliding_info;
    widget_gadget_image_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sliding_info = form->sliding_info;

    /* Get gimg_text and gimg_image */
    gimg_text = gimg_image = NULL;
    foreach(_H(form), GADGET_IMAGE, node,
            {
            if (_GIMG(node)->image && _IMG(_GIMG(node)->image)->is_drawn_image)
            {
            WAP_DBG_ASSERT(!gimg_text); gimg_text = node;}
            else
            {
            WAP_DBG_ASSERT(!gimg_image); gimg_image = node;}
            }
    );

    if (gimg_text == NULL || gimg_image == NULL || WGUI_CTX->current_focused_gadget == NULL)
    {
        /* Less than one gadget. Not required to change focus */
        return;
    }

    if (WGUI_CTX->current_focused_gadget == _H(gimg_text))
    {
        /* If text gadget is partially scrolled outside the screen, defocus it (scroll by form) */
        if (sliding_info->image_on_top)
        {
            if (sliding_info->text_scroll_offset == 0)
            {
                change_focus = KAL_TRUE;
            }
        }
        else
        {
            if (form_yoffset < 0)
            {
                change_focus = KAL_TRUE;
            }
        }

        if (change_focus)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) gimg_image, 1);  /* It send MsfNotifyLostFocus to text gadget */
            /* After SMA receives MsfNotifyLostFocus, it deregisters key up and key down */
        }
    }
    else if (WGUI_CTX->current_focused_gadget == _H(gimg_image))
    {
        /* If text gadget is scrolled inside the screen, focus it (scroll by SMA) */
        if (sliding_info->image_on_top)
        {
            /* Check if the image could be shown in display area */
            if (form_yoffset + gimg_text->position.y <= 0)
            {
                change_focus = KAL_TRUE;
            }
        }
        else
        {
            if (form_yoffset >= 0)
            {
                change_focus = KAL_TRUE;
            }
        }

        if (change_focus)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) gimg_text, 1);   /* It does not send MsfNotifyFocus */
            widget_notify(_H(gimg_text), MsfNotifyFocus);
            /* After SMA receives MsfNotifyFocus, it registers key up and key down */
        }
    }
    else
    {
        WAP_DBG_ASSERT(0);
    }
}

/*
 * Time handler for sliding SMIL scrolling 
 * * Because text scroll in SMA SMTR might be slow, we do not want to scroll text on every pen
 * * event. We use a timer to reduce text scrolling.
 */


/*****************************************************************************
 * FUNCTION
 *  widget_form_sliding_SMIL_scroll_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_sliding_SMIL_scroll_timer_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form;
    widget_sliding_info_struct *sliding_info;
    int scroll_offset;
    int max_form_scroll;    /* Max scroll in form */
    int max_text_scroll;    /* Max scroll in text gadget */
    int form_scroll, text_scroll;
    kal_bool form_is_scrolled = KAL_FALSE, text_is_scrolled = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WPEN_CTX->MMS_viewer_pending_scroll_timer = 0;
    WPEN_CTX->MMS_viewer_scroll_form = NULL;

    if (!IS_FORM_TYPE(arg) || !widget_is_window_gadget_displayed((MSF_UINT32) arg))
    {
        /*
         * It should not happen.
         * * widget_sliding_SMIL_abort_pen_scroll_if_necessary() should be invoked 
         * * before releasing or defocusing MsfForm.
         */
        WAP_BYPASS_ASSERT(0);
        return;
    }

    form = _FORM(arg);
    sliding_info = form->sliding_info;
    scroll_offset = WPEN_CTX->MMS_viewer_scroll_offset;

    if (sliding_info->total_height_without_text > WIDGET_SLIDING_SMIL_BOTTOM)
    {
        /* has image in the MMS viewer; sliding_info->text_gadget_height doesn't have WIDGET_SLIDING_SMIL_TOP & _BOTTOM */
        max_form_scroll =
            sliding_info->total_height_without_text + sliding_info->text_gadget_height - WGUI_CTX->display_size.height;
    }
    else
    {
        max_form_scroll =
            sliding_info->total_height_without_text + sliding_info->text_gadget_height - WGUI_CTX->display_size.height;
    }
    if (max_form_scroll < 0)
    {
        max_form_scroll = 0;
    }

    /* calcuate max_text_scroll for pure text (don't need consider image) */
    max_text_scroll = sliding_info->total_text_height - WGUI_CTX->display_size.height;
    if (max_text_scroll < 0)
    {
        max_text_scroll = 0;
    }

    if (sliding_info->image_on_top)
    {
        if (scroll_offset > max_form_scroll)
        {
            form_scroll = max_form_scroll;
            text_scroll = scroll_offset - max_form_scroll;
            if (text_scroll > max_text_scroll)
            {
                /* WAP_DBG_ASSERT(0); */
                text_scroll = max_text_scroll;
            }

        }
        else
        {
            form_scroll = scroll_offset;
            text_scroll = 0;
        }
    }
    else
    {
        if (scroll_offset > max_text_scroll)
        {
            text_scroll = max_text_scroll;
            form_scroll = scroll_offset - max_text_scroll;
            if (form_scroll > max_form_scroll)
            {
                /* WAP_DBG_ASSERT(0); */
                form_scroll = max_form_scroll;
            }
        }
        else
        {
            text_scroll = scroll_offset;
            form_scroll = 0;
        }
    }

    WAP_DBG_ASSERT(text_scroll >= 0 && text_scroll <= max_text_scroll && form_scroll >= 0 &&
                   form_scroll <= max_form_scroll);

    /* Adjust form scrolling */
    if (form_scroll != (WGUI_CTX->display_pos.y - WGUI_CTX->current_pos.y))
    {
        WGUI_CTX->current_pos.y = WGUI_CTX->display_pos.y - form_scroll;
        form_is_scrolled = KAL_TRUE;
    }

    /* Adjust text scrolling */
    if (text_scroll != sliding_info->text_scroll_offset)
    {
        kal_int32 line_height = sliding_info->text_line_height;

        text_scroll = ((text_scroll + line_height - 1) / line_height) * line_height;
        sliding_info->text_scroll_offset = text_scroll;
        text_is_scrolled = KAL_TRUE;
    }

    /* Adjust focus */
    widget_form_sliding_SMIL_adjust_gadget_focus_by_pen(form);

    if (form_is_scrolled)
    {
        widget_paint();
    }

    if (text_is_scrolled)
    {
        if (sliding_info->text_scroll_notification_hdlr)
        {
            sliding_info->text_scroll_notification_hdlr();
        }
    }
}

/* Start timer to scroll sliding SMIL */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sliding_SMIL_scroll_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form                [IN]         
 *  vbar                [IN]         
 *  scroll_offset       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_sliding_SMIL_scroll_by_pen(
                widget_header_struct *form,
                widget_header_struct *vbar,
                int scroll_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The value of scrollbar is controlled by widget */
    _GBAR(vbar)->value = scroll_offset;

    if (scroll_offset == WPEN_CTX->MMS_viewer_scroll_offset)
    {
        return;
    }

    WPEN_CTX->MMS_viewer_pending_scroll_timer = 1;
    WPEN_CTX->MMS_viewer_scroll_offset = scroll_offset;
    WPEN_CTX->MMS_viewer_scroll_form = _H(form);

    widget_start_timer(
        WIDGET_MMS_VIEWER_SCROLL_TIMER,
        widget_form_sliding_SMIL_scroll_timer_hdlr,
        form,
        WIDGET_MMS_VIEWER_PEN_SCROLL_DELAY_TIME);
}



#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* WIDGET_SLIDING_SMIL_VBAR */ 

#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

/****************************************************************
 * MOB (mixed 
 ***************************************************************/


#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormRegisterMOBScrollNotification
 * DESCRIPTION
 *  Set the scroll notification handler for mixed MMS viewer
 *  The handler is invoked when the scrollbar is scrollbed by touch screen in MMI task.
 * PARAMETERS
 *  wnd                                 [IN]        The form
 *  text_scroll_notification_hdlr       [IN]        
 * RETURNS
 *  void
 * REMARKS
 *  Please note that applications should handle multiple scrollbar pen events in one time,
 *  otherwise, application might not finish incoming pen events (which are fired very frequently)
 *  
 *  the 'text_scroll_notification_hdlr' typically sends signal to SMA module.
 *  
 *  Used after HDIa_widgetExtFormSetMOBStyle.
 *****************************************************************************/
void HDIa_widgetExtFormRegisterMOBScrollNotification(
        MsfWindowHandle wnd,
		MsfGadgetHandle v_bar,
        void (*text_scroll_notification_hdlr) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->mob_pen_info.vbar = v_bar;
    w->mob_pen_info.text_scroll_notification_hdlr = text_scroll_notification_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormGetMOBTextOffsetByPen
 * DESCRIPTION
 *  Set the scroll notification handler for mixed MMS viewer
 *  The handler is invoked when the scrollbar is scrollbed by touch screen in MMI task.
 * PARAMETERS
 *  wnd                     [IN]        The form
 *  text_scroll_offset      [OUT]       
 * RETURNS
 *  void
 * REMARKS
 *  Used after HDIa_widgetExtFormSetMOBStyle
 *****************************************************************************/
void HDIa_widgetExtFormGetMOBTextOffsetByPen(MsfWindowHandle wnd, int *text_scroll_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *w = _FORM(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *text_scroll_offset = w->mob_pen_info.text_scroll_offset;
 
    widget_add_paint_gadget_command(_H(w->mob_pen_info.vbar));
}


/*
 * Time handler for mixed MMS viewer scrolling 
 * * Because processing text scroll might be slow, we do not want to scroll text on every pen
 * * event. We use a timer to reduce text scrolling.
 */


/*****************************************************************************
 * FUNCTION
 *  widget_form_mob_scroll_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_mob_scroll_timer_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form;
    widget_gadget_image_struct *gimg_text = NULL;
    widget_gadget_image_struct *node = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WPEN_CTX->MMS_viewer_pending_scroll_timer = 0;
    WPEN_CTX->MMS_viewer_scroll_form = NULL;

    if (!IS_FORM_TYPE(arg) || !widget_is_window_gadget_displayed((MSF_UINT32) arg))
    {
        /*
         * It should not happen.
         * * widget_sliding_SMIL_abort_pen_scroll_if_necessary() should be invoked 
         * * before releasing or defocusing MsfForm.
         */
        WAP_BYPASS_ASSERT(0);
        return;
    }

    form = _FORM(arg);

    form->mob_pen_info.text_scroll_offset = WPEN_CTX->MMS_viewer_scroll_offset;

    /* Get mixed MMS viewer's gimg_text */
    foreach(_H(form), GADGET_IMAGE, node,
            {
                if (_GIMG(node)->image && _IMG(_GIMG(node)->image)->is_drawn_image)
                {
                    WAP_DBG_ASSERT(!gimg_text); gimg_text = node;
                }
            }
    );
    
    widget_notify(_H(gimg_text), MsfNotifyStateChange);
    widget_paint();

    if (_FORM(arg)->mob_pen_info.text_scroll_notification_hdlr)
    {
        _FORM(arg)->mob_pen_info.text_scroll_notification_hdlr();
    }
}

/* Start timer to scroll MOB */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_mob_scroll_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form                [IN]         
 *  vbar                [IN]         
 *  scroll_offset       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_mob_scroll_by_pen(
                widget_header_struct *form,
                widget_header_struct *vbar,
                int scroll_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (scroll_offset == WPEN_CTX->MMS_viewer_scroll_offset)
    {
        return;
    }

    WPEN_CTX->MMS_viewer_pending_scroll_timer = 1;
    WPEN_CTX->MMS_viewer_scroll_offset = scroll_offset;
    WPEN_CTX->MMS_viewer_scroll_form = _H(form);

    widget_start_timer(
        WIDGET_MMS_VIEWER_SCROLL_TIMER,
        widget_form_mob_scroll_timer_hdlr,
        form,
        WIDGET_MMS_VIEWER_PEN_SCROLL_DELAY_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  widget_mms_viewer_abort_pen_scroll_if_necessary
 * DESCRIPTION
 *  Abort scroll timer in MMS viewer (sliding SMIL/mixed).
 * PARAMETERS
 *  h               [IN]        The form (NULL to terminate current form)
 *  need_redraw     [IN]        Because scrollbar is scrolled in MMI task before the scroll timer expires, we need to reset the scrollbar position.
 * RETURNS
 *  void
 * REMARKS
 *  This function should be invoked when
 *  1. the form is removed or released
 *  2. user press keypad
 *****************************************************************************/
void widget_MMS_viewer_abort_pen_scroll_if_necessary(widget_header_struct *h, kal_bool need_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WPEN_CTX->MMS_viewer_pending_scroll_timer && (!h || h == WPEN_CTX->MMS_viewer_scroll_form))
    {
        form = _FORM(WPEN_CTX->MMS_viewer_scroll_form);

        widget_stop_timer(WIDGET_MMS_VIEWER_SCROLL_TIMER);

        WPEN_CTX->MMS_viewer_pending_scroll_timer = 0;
        WPEN_CTX->MMS_viewer_scroll_offset = -1;  /* Assign an invalid value such that it can be scrolled again */
        WPEN_CTX->MMS_viewer_scroll_form = NULL;

        /* The scrollbar is already scrolled in MMI task before scroll timer expires */
        if (need_redraw)
        {
            if (form->mob_pen_info.vbar)
            {
                //kal_printf("\n !!! widget_MMS_viewer_abort_pen_scroll_if_necessary v_bar : %d", form->mob_pen_info->text_scroll_offset);
                _GBAR(form->mob_pen_info.vbar)->value = form->mob_pen_info.text_scroll_offset;
                widget_add_paint_gadget_command(_H(form->mob_pen_info.vbar));
            }

        #if defined(WIDGET_SLIDING_SMIL_SUPPORT) && defined(WIDGET_SLIDING_SMIL_VBAR)
            if (form->sliding_info && form->sliding_info->vbar)
            {
                _GBAR(form->sliding_info->vbar)->value = form->sliding_info->text_scroll_offset +
                    (WGUI_CTX->display_pos.y - WGUI_CTX->current_pos.y);
                widget_add_paint_gadget_command(_H(form->sliding_info->vbar));
            }
        #endif

        }
    }
}





/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFormSetMOBStyle
 * DESCRIPTION
 *  Configure the mixed object style (put up/down icon to emulate Up Key and Down Key)
 * PARAMETERS
 *  wnd     [IN]        Form handle
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void HDIa_widgetExtFormSetMOBStyle(MsfWindowHandle wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wnd || !IS_FORM_TYPE(wnd))
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    form = _FORM(wnd);

    memset(&(form->mob_pen_info), 0, sizeof(widget_MOB_pen_struct));

}



#endif /* __MMI_TOUCH_SCREEN__ */ 

 /****************************************************************
 * Pen handlers
 ***************************************************************/

#ifdef __MMI_TOUCH_SCREEN__

#if defined(WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON)


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_form_change_slide_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form            [IN]         
 *  point           [IN]        
 *  pen_event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_form_change_slide_pen_handler(
                widget_form_struct *form,
                mmi_pen_point_struct point,
                mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_MMS_viewer_title_struct * title = form->MMs_view_title;
    mmi_pen_point_struct prev_pos[4];
    mmi_pen_point_struct next_pos[4];
    mmi_pen_polygon_area_struct prev_polygon, next_polygon;
    kal_bool in_prev_button, in_next_button;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!form)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    prev_pos[0].x = title->prev_botton_x;
    prev_pos[0].y = title->prev_botton_y;
    prev_pos[1].x = title->prev_botton_x;
    prev_pos[1].y = title->prev_botton_y + title->button_height;
    prev_pos[2].x = title->prev_botton_x + title->button_width;
    prev_pos[2].y = title->prev_botton_y + title->button_height;
    prev_pos[3].x = title->prev_botton_x + title->button_width;
    prev_pos[3].y = title->prev_botton_y;
    prev_polygon.num = 4;
    prev_polygon.points = prev_pos;
    if (mmi_pen_check_inside_polygon(&prev_polygon, point))
    {
        in_prev_button = KAL_TRUE;
    }
    else
    {
        in_prev_button = KAL_FALSE;
    }

    next_pos[0].x = title->next_botton_x;
    next_pos[0].y = title->next_botton_y;
    next_pos[1].x = title->next_botton_x;
    next_pos[1].y = title->next_botton_y + title->button_height;
    next_pos[2].x = title->next_botton_x + title->button_width;
    next_pos[2].y = title->next_botton_y + title->button_height;
    next_pos[3].x = title->next_botton_x + title->button_width;
    next_pos[3].y = title->next_botton_y;
    next_polygon.num = 4;
    next_polygon.points = next_pos;
    if (mmi_pen_check_inside_polygon(&next_polygon, point))
    {
        in_next_button = KAL_TRUE;
    }
    else
    {
        in_next_button = KAL_FALSE;
    }

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            title->pen_by_prev_button = title->pen_by_next_button = 0;

            if (in_prev_button)
            {
                title->pen_by_prev_button = 1;
                title->prev_button_pressed = 1;
                widget_draw_MMS_viewer_title_button(
                    title->prev_botton_img,
                    (S16) (title->prev_botton_x + 1),
                    (S16) (title->prev_botton_y + 1),
                    title->button_width,
                    title->button_height);
            }
            else if (in_next_button)
            {
                title->pen_by_next_button = 1;
                title->next_button_pressed = 1;
                widget_draw_MMS_viewer_title_button(
                    title->next_botton_img,
                    (S16) (title->next_botton_x + 1),
                    (S16) (title->next_botton_y + 1),
                    title->button_width,
                    title->button_height);
            }
            break;

        case MMI_PEN_EVENT_UP:
            if (title->pen_by_prev_button)
            {
                if (in_prev_button)
                {
                    if (title->prev_button_pressed)
                    {
                        title->prev_button_pressed = 0;
                        widget_draw_MMS_viewer_title_button(
                            title->prev_botton_img,
                            title->prev_botton_x,
                            title->prev_botton_y,
                            title->button_width,
                            title->button_height);
                    }

                    widget_enqueue_keypad_event(KEY_LEFT_ARROW, KEY_EVENT_UP);
                }
            }
            else if (title->pen_by_next_button)
            {
                if (in_next_button)
                {
                    if (title->next_button_pressed)
                    {
                        title->next_button_pressed = 0;
                        widget_draw_MMS_viewer_title_button(
                            title->next_botton_img,
                            title->next_botton_x,
                            title->next_botton_y,
                            title->button_width,
                            title->button_height);
                    }

                    widget_enqueue_keypad_event(KEY_RIGHT_ARROW, KEY_EVENT_UP);
                }
            }

            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            break;

        case MMI_PEN_EVENT_MOVE:
            if (title->pen_by_prev_button)
            {
                if (in_prev_button)
                {
                    if (!title->prev_button_pressed)
                    {
                        title->prev_button_pressed = 1;
                        widget_draw_MMS_viewer_title_button(
                            title->prev_botton_img,
                            (S16) (title->prev_botton_x + 1),
                            (S16) (title->prev_botton_y + 1),
                            title->button_width,
                            title->button_height);
                    }
                }
                else
                {
                    if (title->prev_button_pressed)
                    {
                        title->prev_button_pressed = 0;
                        widget_draw_MMS_viewer_title_button(
                            title->prev_botton_img,
                            title->prev_botton_x,
                            title->prev_botton_y,
                            title->button_width,
                            title->button_height);
                    }
                }
            }
            else if (title->pen_by_next_button)
            {
                if (in_next_button)
                {
                    if (!title->next_button_pressed)
                    {
                        title->next_button_pressed = 1;
                        widget_draw_MMS_viewer_title_button(
                            title->next_botton_img,
                            (S16) (title->next_botton_x + 1),
                            (S16) (title->next_botton_y + 1),
                            title->button_width,
                            title->button_height);
                    }
                }
                else
                {
                    if (title->next_button_pressed)
                    {
                        title->next_button_pressed = 0;
                        widget_draw_MMS_viewer_title_button(
                            title->next_botton_img,
                            title->next_botton_x,
                            title->next_botton_y,
                            title->button_width,
                            title->button_height);
                    }
                }
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            if (title->prev_button_pressed || title->next_button_pressed)
            {
                title->prev_button_pressed = title->next_button_pressed = 0;
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
            break;

    }
}
#endif /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */ 


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_form_scroll_by_pen
 * DESCRIPTION
 *  Scroll the form by pen
 * PARAMETERS
 *  form                [IN]        The form
 *  vbar                [IN]         
 *  scroll_offset       [OUT]       
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void widget_MMI_form_scroll_by_pen(widget_header_struct *form, widget_header_struct *vbar, int scroll_offset)
{
#if defined(WIDGET_SLIDING_SMIL_SUPPORT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (_FORM(form)->sliding_info)
    {
        widget_MMI_sliding_SMIL_scroll_by_pen(form, vbar, scroll_offset);
    }
    else if (_FORM(form)->mob_pen_info.text_scroll_notification_hdlr)
    {
        widget_MMI_mob_scroll_by_pen(form, vbar, scroll_offset);
    }
    else
    {
        /* Widget does not support it. Applications should not add scrollbar in form */
        WAP_DBG_ASSERT(0);
    }
#endif /* defined(WIDGET_SLIDING_SMIL_SUPPORT) && defined(WIDGET_SLIDING_SMIL_VBAR) */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_form_pen_handler
 * DESCRIPTION
 *  Pen handler of MsfForm
 * PARAMETERS
 *  h               [IN]        The form
 *  point           [IN]        
 *  pen_event       [IN]        
 * RETURNS
 *  void
 * REMARKS
 *  Process pen events in MsfForm
 *****************************************************************************/
void widget_MMI_form_pen_handler(
        widget_header_struct *h,
        mmi_pen_point_struct point,
        mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    form = _FORM(h);

#if defined(WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON)
    if (form->MMs_view_title)
    {
        widget_MMI_form_change_slide_pen_handler(form, point, pen_event);
    }
#endif /* WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON */
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/****************************************************************
 * Utility function of MsfForm
 ***************************************************************/

/* Draw border of selected gadget */


/*****************************************************************************
 * FUNCTION
 *  widget_form_draw_border
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h       [IN]         
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_draw_border(widget_header_struct *h, int x1, int y1, int x2, int y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *p = h->parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_FORM_TYPE(p));
    if (IS_FORM_TYPE(p) && (_FORM(p)->form_flags & WIDGET_FORM_FLAG_DISABLE_GADGET_BORDER))
    {
        return;
    }

    // TODO: push clip?
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
#else /* 0 */ 
    {
        static const kal_uint8 dotted_line_bitvalues[] = {1, 0};
        gdi_color bcolor = gdi_act_color_from_rgb(
                            255,
                            WIDGET_SMIL_BORDER_COLOR_R,
                            WIDGET_SMIL_BORDER_COLOR_G,
                            WIDGET_SMIL_BORDER_COLOR_B);
        gui_set_clip(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
        gdi_draw_line_style(
            x1 - 1,
            y1 - 1,
            x1 - 1,
            y2 + 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
        gdi_draw_line_style(
            x1 - 1,
            y1 - 1,
            x2 + 1,
            y1 - 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
        gdi_draw_line_style(
            x2 + 1,
            y1 - 1,
            x2 + 1,
            y2 + 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
        gdi_draw_line_style(
            x1 - 1,
            y2 + 1,
            x2 + 1,
            y2 + 1,
            bcolor,
            sizeof(dotted_line_bitvalues),
            dotted_line_bitvalues);
    }
#endif /* 0 */ 
}

// TODO: Use widget_in_form_window() to replace "(!WGUI_CTX->in_paintbox)"


/*****************************************************************************
 * FUNCTION
 *  widget_in_form_window
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_in_form_window(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->current_window && IS_FORM_TYPE(WGUI_CTX->current_window))
    {
        WAP_DBG_ASSERT(!WGUI_CTX->in_paintbox); /* Be paranoid */
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_gadget_want_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gadget      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_form_gadget_want_focus(widget_header_struct *gadget)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(WIDGET_GADGET_WANT_FOCUS_LIST & (1 << gadget->data_type)))
    {
        return KAL_FALSE;
    }

    if (IS_GADGET_STRING_TYPE(gadget))
    {
        /* A string gadget can be focused in MsfForm only if MSF_GADGET_PROPERTY_FOCUS */
        if (_GADGET_STRING(gadget)->property_mask & MSF_GADGET_PROPERTY_FOCUS)
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else if (IS_GADGET_IMAGE_TYPE(gadget))
    {
        // TODO: Note that Marquee objects have MSF_GADGET_PROPERTY_NOTIFY but not MSF_GADGET_PROPERTY_FOCUS
        if (_GIMG(gadget)->property_mask & MSF_GADGET_PROPERTY_FOCUS    /* ||
                                                                           _GIMG(gadget)->property_mask & MSF_GADGET_PROPERTY_NOTIFY */ )
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else if (IS_GADGET_INPUT_TYPE(gadget))
    {
        if (_GINP(gadget)->is_string_gadget_emulation && !(_GINP(gadget)->property_mask & MSF_GADGET_PROPERTY_FOCUS))
        {
            return KAL_FALSE;
        }
        else
        {
            return KAL_TRUE;
        }
    }
    else
    {
        return KAL_TRUE;
    }
}

/*
 * We set focus of gadget in form when it is focused
 */


/*****************************************************************************
 * FUNCTION
 *  widget_form_on_focused
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_on_focused(widget_header_struct *form)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *gadget;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_FORM_TYPE(form));

    /* When a form is focused, set focus to it's first gadget (which is created first or was active last time) */
    widget_get_active_childs(gadget, form);
    while (gadget)
    {
        if (widget_form_gadget_want_focus(gadget))
        {
            HDIa_widgetSetInFocus((MsfGadgetHandle) gadget, 1);
            /*
             * SMA/MEA require setting focus on gadgets on forms. 
             * * FIXME. However, we may already send the notification twice in HDIa_widgetSetInFocus or not.
             */
            widget_notify(gadget, MsfNotifyFocus);
            break;
        }

        widget_get_next_active_childs(gadget, form);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_on_defocused
 * DESCRIPTION
 *  
 * PARAMETERS
 *  w       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_on_defocused(widget_header_struct *w)
{
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_form_struct *form = _FORM(w);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (form->sliding_info)
    {
        /* We do not store offset coordination in every window. As a result, we need to store it in sliding_info */
        if (form->sliding_info->restore_scroll_offset_before_paint == 0)
        {
            form->sliding_info->scroll_offset_backup = WGUI_CTX->current_pos.y;
            form->sliding_info->restore_scroll_offset_before_paint = 1;
        }
        else
        {
            /*
             * defocused -> focus -> defocused before painted 
             * * It is possible to happen (For example, when invoking "Save As")
             */
            /* WAP_DBG_ASSERT(0); */
        }
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 
}

/*
 * We set focus of gadget in form when it is focused
 */


/*****************************************************************************
 * FUNCTION
 *  widget_form_on_gadget_added
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form                [IN]     
 *  gadget_added        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_on_gadget_added(widget_header_struct *form, widget_header_struct *gadget_added)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *gadget;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_FORM_TYPE(form));

    /* When a form is focused, set focus to it's first gadget (which is created first or was active last time) */
    widget_get_active_childs(gadget, form);
    while (gadget)
    {
        if (widget_form_gadget_want_focus(gadget))
        {
            /* If the added gadget is not focused, we do not need to send notification to the previously-focused gadget */
            if (gadget == gadget_added)
            {
                HDIa_widgetSetInFocus((MsfGadgetHandle) gadget, 1);
                widget_notify(gadget, MsfNotifyFocus);
            }
            break;
        }

        widget_get_next_active_childs(gadget, form);
    }

#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    if (IS_GADGET_IMAGE_TYPE(gadget_added))
    {
        widget_form_update_for_sliding_SMIL(_FORM(form));
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_on_gadget_removed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form                [IN]     
 *  gadget_removed      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_form_on_gadget_removed(widget_header_struct *form, widget_header_struct *gadget_removed)
{
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_GADGET_IMAGE_TYPE(gadget_removed))
    {
        widget_form_update_for_sliding_SMIL(_FORM(form));
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_form
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form        [IN]     
 *  size        [IN]     
 *  pos         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_form(widget_form_struct *form, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We only draw the skeleton here. widget_paint_area will draw each gadgets */
    widget_style_struct *style = _STYLE(widget_get_style((MSF_UINT32) form));
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!style)
    {
        return;
    }

    x1 = WGUI_CTX->display_pos.x;
    y1 = WGUI_CTX->display_pos.y;
    x2 = x1 + WGUI_CTX->display_size.width - 1;
    y2 = y1 + WGUI_CTX->display_size.height - 1;

    gui_push_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    if (!widget_is_transparent_color(&(style->bg_color)))
    {
        gdi_draw_solid_rect(
            x1,
            y1,
            x2,
            y2,
            (gdi_color) gdi_act_color_from_rgb(255, style->bg_color.r, style->bg_color.g, style->bg_color.b));
    }
    else
    {
        gdi_draw_solid_rect(
            x1,
            y1,
            x2,
            y2,
            (gdi_color) gdi_act_color_from_rgb(255, 255, 255, 255));
    }
    gui_pop_clip();
}


/* This check is unnecessary in BRS paintbox because BRS will do this checking first */
// TODO: Incorrect name. This also applies to paintbox.


/*****************************************************************************
 * FUNCTION
 *  widget_gadget_in_form
 * DESCRIPTION
 *  
 * PARAMETERS
 *  form_size       [IN]        
 *  gadget_pos      [IN]        
 *  gadget_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_gadget_in_form(const MsfSize *form_size, const MsfPosition *gadget_pos, const MsfSize *gadget_size)
{
#if 0   // TODO: This check is incorrect to handle WGUI_CTX->curr_display_pos
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


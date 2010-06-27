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
 * widget_paint_gadget_image.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 1. GIF animation
 * 2. Image gadget paint routines
 * 3. Marquee
 * 4. Precached image in layer memory
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
#include "fs_type.h"
#include "SubLCDHistoryGprot.h"
#include "gdi_include.h"
#include "gdi_image_bmp.h"
#include "gdi_image_wbmp.h"
#include "gdi_image_gif.h"
#include "gdi_image_jpeg.h"
#include "gdi_image_png.h"
#include "lcd_sw_rnd.h"
#include "gd_primitive.h"
#include "gdi_util.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_camera.h"
#include "mdi_video.h"
#include "mdi_audio.h"
#include "lcd_if.h"
#include "ProfileGprots.h"
#include "ScrMemMgrGprot.h"
#include "wgui_status_icons.h"
#include "wgui_categories_multimedia.h"
#include "gpio/gpioInc/GPIOInc.h"				/* Vibration/Backlight */


static void widget_show_animate_image(S32 x, S32 y, widget_gadget_image_struct *gimg);
/* 
 * NOTE: there are potential problems if out-of-memory when MSF_MEM_ALLOC in MMI task.
 */

extern kal_bool widget_image_is_precached(
                    widget_image_struct *img, 
                    MSF_UINT16 width, 
                    MSF_UINT16 height, 
                    MsfImageZoom zoom);
extern kal_bool widget_MMI_prepare_precache_image(
                    widget_image_struct *img,
                    MSF_UINT16 width,
                    MSF_UINT16 height,
                    MsfImageZoom zoom);
extern void widget_MMI_finish_precache_image(void);


#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING

widget_nb_image_struct g_widget_nb_image_array[WIDGET_MAX_NB_DRAW_IMAGE_NUM];


/*****************************************************************************
 * FUNCTION
 *  widget_query_index_of_nb_image_array
 * DESCRIPTION
 *  check the image width and height first.
 *  If the width and height fit to draw the image in non-blocking,
 *  try to get the index of the nb_image_array to keep the information.
 *
 * PARAMETERS
 *  img_width       [IN]        
 *  img_height      [IN]        
 *  gimg            [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 widget_query_index_of_nb_image_array(S32 img_width, S32 img_height, widget_gadget_image_struct *gimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    int first_empty = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img_width > WIDGET_IMAGE_WIDTH_LIMITATION || img_height > WIDGET_IMAGE_HEIGHT_LIMITATION)
    {
        for (i = 0; i < WIDGET_MAX_NB_DRAW_IMAGE_NUM; i++)
        {
            if (g_widget_nb_image_array[i].is_used)
            {
                if (g_widget_nb_image_array[i].gimg == gimg)
                {
                    gdi_image_nb_stop (g_widget_nb_image_array[i].handle);
                    return i;
                }
            }
            else
            {
                /* find the available index */
                if (first_empty == -1)
                {
                    first_empty = i;
                }
            }
        }
    }

    return first_empty;
}


/*****************************************************************************
 * FUNCTION
 *  widget_find_index_of_nb_image_array
 * DESCRIPTION
 *  Find the index according the gdi_handle
 *
 * PARAMETERS
 *  handle          [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 widget_find_index_of_nb_image_array(gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_MAX_NB_DRAW_IMAGE_NUM; i++)
    {
        if (g_widget_nb_image_array[i].is_used == KAL_TRUE &&
            g_widget_nb_image_array[i].handle == handle)
        {
            /* find the available index */
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_find_index_of_nb_image_array_by_image
 * DESCRIPTION
 *  Find the index according the MsfImageHandle
 *
 * PARAMETERS
 *  img_width       [IN]        
 *  img_height      [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 widget_find_index_of_nb_image_array_by_image(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_MAX_NB_DRAW_IMAGE_NUM; i++)
    {
        if (g_widget_nb_image_array[i].is_used == KAL_TRUE)
        {
            if (g_widget_nb_image_array[i].gimg && 
                g_widget_nb_image_array[i].gimg->image == (MsfImageHandle)img)
            {
                /* find the available index */
                return i;
            }
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_image_nb_draw_done_callback
 * DESCRIPTION
 *  the callback function when decoding the image finish
 *
 * PARAMETERS
 *  result          [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_image_nb_draw_done_callback(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    widget_gadget_image_struct *gimg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_IMAGE_NB_DRAW_DONE_CALLBACK, result);
    index = widget_find_index_of_nb_image_array(handle);
    if (index >= 0 && index < WIDGET_MAX_NB_DRAW_IMAGE_NUM)
    {
        if (result == GDI_SUCCEED)
        {
            gimg = g_widget_nb_image_array[index].gimg;
            if (gimg)
            {
                WAP_DBG_ASSERT(IS_IMAGE_TYPE(gimg->image));

                if (_IMG(gimg->image)->image_format == MsfGif)
                {
                    /* updatet the information in WIMG_CTX->gif_head */
                    widget_gif_animation_struct *curr = WIMG_CTX->gif_head;
                    while (curr)
                    {
                        if (curr->image_gadget == (MsfGadgetHandle)gimg)
                        {
                            curr->draw_in_nonblocking = KAL_FALSE;
                            break;
                        }
                        else
                        {
                            curr = curr->next;
                            continue;
                        }
                    } /* while (curr) */
                } /* if (_IMG(gimg->image)->image_format == MsfGif) */
            } /* if (gimg) */
            /* if paint_seqnum is incorrect, we don't blt the image */
            if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_DRAW_IN_CB)
            {
                widget_paint();
            }
            else if (WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_PROCESSING)
			{
				gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
			}

            memset(&g_widget_nb_image_array[index], 0, sizeof(widget_nb_image_struct));

            if (WIMG_CTX->gif_head && _IMG(gimg->image)->GIF_frames > 1)
            {
                /* Restart oneshot timer */
                widget_stop_timer(WIDGET_ANIMATE_TIMER);
                widget_start_timer(WIDGET_ANIMATE_TIMER, widget_paint_GIF_animation_hdlr, (void*)WIDGET_DRAW_IMAGE_IN_NONBLOCKING, WIDGET_GIF_ANIMATION_BASE_TIME);
            }
            result = KAL_TRUE;
        }
        else
        { /* result != GDI_SUCCEED */
            gimg = g_widget_nb_image_array[index].gimg;
            if (gimg)
            {
                WAP_DBG_ASSERT(IS_IMAGE_TYPE(gimg->image));

                if (_IMG(gimg->image)->image_format == MsfGif)
                {
                    /* updatet the information in WIMG_CTX->gif_head */
                    widget_gif_animation_struct *curr = WIMG_CTX->gif_head;
                    while (curr)
                    {
                        if (curr->image_gadget == (MsfGadgetHandle)gimg)
                        {
                            curr->total_frames = curr->curr_frame;  /* Set the total frame count */
                            curr->curr_frame = 0;
                            curr->draw_in_nonblocking = KAL_FALSE;
                            break;
                        }
                        else
                        {
                            curr = curr->next;
                            continue;
                        }
                    } /* while (curr) */
                } /* if (_IMG(gimg->image)->image_format == MsfGif) */
            } /* if (gimg) */
        } /* if (result == GDI_SUCCEED) */
    } /* if (index >= 0 && index < WIDGET_MAX_NB_DRAW_IMAGE_NUM) */
    
    /* If we are in pre-cache non-blocking image drawing, we need to notify the caller */
    if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_PROCESSING)
    {
        if (result >= GDI_SUCCEED)
        {
            /* pre-cache non-blocking image done */
            WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_DONE; //WIDGET_PRECACHE_NB_IMAEG_NONE;
            if (WGUI_CTX->precache_nb_image_cb)
            {
                WGUI_CTX->precache_nb_image_cb(KAL_TRUE);
                WGUI_CTX->precache_nb_image_cb = NULL;
            }
        }
        else
        {
            /* pre-cache non-blocking image failed */
            WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_DONE;	//WIDGET_PRECACHE_NB_IMAEG_NONE;
            if (WGUI_CTX->precache_nb_image_cb)
            {
                /* we calls precache_nb_image_cb with KAL_TRUE because the application doesn't know need to do what */
                WGUI_CTX->precache_nb_image_cb(KAL_TRUE);
                WGUI_CTX->precache_nb_image_cb = NULL;
            }
        }
//    Trace2(TRACE_GROUP_2, "[Widget] widget_MMI_image_nb_draw_done_callback is done in pre-cache");

    }/* if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_PROCESSING) */
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_image_nb_draw
 * DESCRIPTION
 *  stop the image that draw in non-blocking
 *
 * PARAMETERS
 *  img
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_image_nb_draw(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_MAX_NB_DRAW_IMAGE_NUM; i++)
    {
        if (g_widget_nb_image_array[i].is_used == KAL_TRUE)
        {
            if (g_widget_nb_image_array[i].gimg && 
                g_widget_nb_image_array[i].gimg->image == (MsfImageHandle)img)
            {
                /* find the available index */
                gdi_image_nb_stop (g_widget_nb_image_array[i].handle);
                /* close the virtual file */
                memset(&g_widget_nb_image_array[i], 0, sizeof(widget_nb_image_struct));
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_STOP_IMAGE_NB_DRAW, img);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_all_image_nb_draw
 * DESCRIPTION
 *  stop all image that draw in non-blocking
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_all_image_nb_draw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_MAX_NB_DRAW_IMAGE_NUM; i++)
    {
        if (g_widget_nb_image_array[i].is_used == KAL_TRUE)
        {
            /* stop to draw none-blocking image */
            gdi_image_nb_stop (g_widget_nb_image_array[i].handle);
            memset(&g_widget_nb_image_array[i], 0, sizeof(widget_nb_image_struct));
        }
    }
    /* When stop non-blocking image drawing, we need to unlock the status bar rendering */

}


/*****************************************************************************
 * FUNCTION
 *  widget_image_nb_draw_default
 * DESCRIPTION
 *  draw the default background when non-blocking draw the image
 *  The caller needs to set the active layer and clip
 * PARAMETERS
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_image_nb_draw_default(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.alpha = 100;
    c.r = 192;
    c.g = 192;
    c.b = 192;
    gui_fill_rectangle(x1, y1, x2, y2, c);

    c.alpha = 100;
    c.r = 0;
    c.g = 0;
    c.b = 0;
    gui_fill_rectangle(x1, y1, x2, y2, c);
}


#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_precache_image
 * DESCRIPTION
 *  execute precache image process for non-blocking image drawing
 * PARAMETERS
 *  arg                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_precache_image(void * arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct* gimg = (widget_gadget_image_struct*)arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_show_animate_image(0, 0, gimg);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCacheNonBlockingImage
 * DESCRIPTION
 *  Request to cache the non-blocking image first
 *  When cache the image, we call the callback function to notify the caller 
 * PARAMETERS
 *  image               [IN]        
 *  gadget              [IN]        
 *  precache_cb         [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool HDIa_widgetExtCacheNonBlockingImage(MsfImageHandle image, MsfGadgetHandle gadget, FuncPtrShort precache_cb)
{
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct* img = _IMG(image);
    widget_gadget_image_struct* gimg = _GIMG(gadget);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (precache_cb == NULL)
    {
        return KAL_FALSE;
    }

    if (img == NULL && gimg == NULL)
    {
        /* no need to pre-cache the image */
        precache_cb(KAL_TRUE);
        return KAL_FALSE;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXT_CACHE_NONBLOCKING_IMAGE, precache_cb);
    /* reset the precache first */
    widget_precache_image_reset_all();

    WGUI_CTX->precache_nb_image_cb = precache_cb;
    WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_START;
    widget_execute_MMI_p((func_ptr) widget_MMI_precache_image, (void*)gimg, KAL_TRUE);

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_EXT_CACHE_NONBLOCKING_IMAGE_RESULT, WGUI_CTX->precache_nb_image_state);
    if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_NO_NEED)
    {
        /* no need to pre-cache the image */
        widget_precache_image_reset_all();

        WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
        WGUI_CTX->precache_nb_image_cb(KAL_TRUE);
        WGUI_CTX->precache_nb_image_cb = NULL;
    }
    else if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_ERROR)
    {
        /* pre-cache tnon-blocking image drawing failed */
        widget_precache_image_reset_all();
        WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
        /* we calls precache_nb_image_cb with KAL_TRUE because the application doesn't know need to do what */
        WGUI_CTX->precache_nb_image_cb(KAL_TRUE);
        WGUI_CTX->precache_nb_image_cb = NULL;
    }
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_gdi_image_id
 * DESCRIPTION
 *  get GDI image_id from MsfImageFromat/MsfImageFormatExt
 *
 * PARAMETERS
 *  format          [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 widget_get_gdi_image_id(MsfImageFormat format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(format)
    {
    case MsfGif:
        return GDI_IMAGE_TYPE_GIF;
    case MsfBmp:
        return GDI_IMAGE_TYPE_BMP;
    case MsfWbmp:
        return GDI_IMAGE_TYPE_WBMP;
    case MsfPng:
        return GDI_IMAGE_TYPE_PNG;
    case MsfUnsupportedMediaType:
        return GDI_IMAGE_TYPE_INVALID;
    default:
        /* we don't need tp non-block draw in other image format (ABM, PBM...) */
        return GDI_IMAGE_TYPE_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_image_draw_file
 * DESCRIPTION
 *  widget draw image in this function.
 *  If MCU power is low and needs to support non-block drawing, we handle here.
 *
 * PARAMETERS
 *  gimg            [IN]        
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  org_width       [IN]        
 *  org_height      [IN]        
 *  resized_width   [IN]        
 *  resized_height  [IN]        
 *  file_name       [IN]    
 *  frame_id        [IN]    
 *  is_resized      [IN]   
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 widget_MMI_image_draw_file(
                widget_gadget_image_struct *gimg,
                S32 offset_x,
                S32 offset_y,
                S32 resized_width,
                S32 resized_height,
                S8 *file_name,
                U16 frame_id,
                kal_bool is_resized)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED; /* WIDGET_DRAW_IMAGE_IN_BLOCKING */
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_image_struct* img = NULL;
    S32 org_width;
    S32 org_height;
    S32 index = -1;
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __PRODUCTION_RELEASE__
    ASSERT(WIDGET_IS_MMI_TASK());
#endif 

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    if (gimg && gimg->image && !IS_PRE_IMAGE_TYPE(gimg->image))
    {
        img = _IMG(gimg->image);
        org_width = widget_image_width((MsfImageHandle)img);
        org_height = widget_image_height((MsfImageHandle)img);
        index = widget_query_index_of_nb_image_array(org_width, org_height, gimg);
    }
    if (index >= 0 && index < WIDGET_MAX_NB_DRAW_IMAGE_NUM)
    {
        kal_bool cached = KAL_FALSE;

        /* execute async image drawing */
        if (frame_id == 0)
        {
            widget_image_nb_draw_default(
                offset_x,
                offset_y,
                offset_x + resized_width - 1,
                offset_y + resized_height - 1);
        }

        /*
         * gdi_image_nb_draw process
         * gdi_nb_set_blt(IS_BLT,IS_PRORESS_BLT)
         * We can set IS_BLT to TRUE and PROGRESS_BLT to TRUE to progress update the LCD. 
         * (GDC_TASK will call gdi_lcd_repaint() to update lcd)
         * Some image decoder can support progress update LCD, 
         * it will output current status to LCD. 
         * Support image codec are :
         * BMP / SW GIF / SW JPEG / PNG  
         * (HW GIF / HW JPEG didn't support progress update)
         *
         * We blt the image in callback function by ourselves because
         * we could do more check there
         */
        gdi_nb_set_blt(FALSE, FALSE);
        gdi_nb_set_done_callback(widget_MMI_image_nb_draw_done_callback);

        if (is_resized)
        {
            g_widget_nb_image_array[index].handle = gdi_image_nb_draw_resized_file_frames(
                                                        (cached)?0:offset_x, 
                                                        (cached)?0:offset_y, 
                                                        resized_width, 
                                                        resized_height, 
                                                        file_name,
                                                        frame_id);
        }
        else
        {
            g_widget_nb_image_array[index].handle = gdi_image_nb_draw_file_frames(
                                                        (cached)?0:offset_x, 
                                                        (cached)?0:offset_y, 
                                                        file_name,
                                                        frame_id); 

        }

        if (g_widget_nb_image_array[index].handle)
        {
            g_widget_nb_image_array[index].is_used = KAL_TRUE;
            g_widget_nb_image_array[index].gimg = gimg;
            g_widget_nb_image_array[index].offset_x = offset_x;
            g_widget_nb_image_array[index].offset_y = offset_y;
            ret = WIDGET_DRAW_IMAGE_IN_NONBLOCKING;
        }
        else
        {
            /* reguest to non-block drawing fail */
            ret = WIDGET_MAX_NB_DRAW_IMAGE_NUM;
        }
        
        if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_START)
        {
            /* Update the state in pre-cache non-blocking image_procedure */
            if (ret == WIDGET_MAX_NB_DRAW_IMAGE_NUM)
            {
                WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_ERROR;
            }
            else
            {
                WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_PROCESSING;
            }
        }
    }
    else if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_START)
    {
        /* Don't need to nonblocking image drawing in pre-cache non-blocking image_procedure */
        WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NO_NEED;
    }
    else
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
    {
        if (is_resized)
        {
            ret = gdi_image_draw_resized_file_frames(
                    offset_x,
                    offset_y,
                    resized_width,
                    resized_height,
                    file_name,
                    frame_id);
        }
        else
        {
            ret = gdi_image_draw_file_frames(
                    offset_x,
                    offset_y,
                    file_name,
                    frame_id);
        }
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_IMAGE_DRAW_FILE, is_resized, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_image_draw
 * DESCRIPTION
 *  widget draw image in this function.
 *  If MCU power is low and needs to support non-block drawing, we handle here.
 *
 * PARAMETERS
 *  gimg            [IN]        
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  resized_width   [IN]        
 *  resized_height  [IN]        
 *  image_ptr       [IN]        
 *  image_id        [IN]        
 *  image_size      [IN]     
 *  frame_id        [IN]    
 *  is_resized      [IN]   
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 widget_MMI_image_draw(
            widget_gadget_image_struct *gimg,
            S32 offset_x,
            S32 offset_y,
            S32 resized_width,
            S32 resized_height,
            U8 *image_ptr,
            U8  image_id,
            U16 image_size,
            U16 frame_id,
            kal_bool is_resized)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED; /* WIDGET_DRAW_IMAGE_IN_BLOCKING */
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_image_struct* img = NULL;
    S32 org_width;
    S32 org_height;
    S32 index = -1;
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __PRODUCTION_RELEASE__
    ASSERT(WIDGET_IS_MMI_TASK());
#endif 

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    if (gimg && gimg->image && !IS_PRE_IMAGE_TYPE(gimg->image))
    {
        img = _IMG(gimg->image);
        org_width = widget_image_width((MsfImageHandle)img);
        org_height = widget_image_height((MsfImageHandle)img);
        index = widget_query_index_of_nb_image_array(org_width, org_height, gimg);
    }
    if (index >= 0 && index < WIDGET_MAX_NB_DRAW_IMAGE_NUM)
    {
        kal_bool cached = KAL_FALSE;

        /* execute async image drawing */
        if (frame_id == 0)
        {

            widget_image_nb_draw_default(
                offset_x,
                offset_y,
                offset_x + resized_width - 1,
                offset_y + resized_height - 1);
        }

        /*
         * gdi_image_nb_draw process
         * gdi_nb_set_blt(IS_BLT,IS_PRORESS_BLT)
         * We can set IS_BLT to TRUE and PROGRESS_BLT to TRUE to progress update the LCD. 
         * (GDC_TASK will call gdi_lcd_repaint() to update lcd)
         * Some image decoder can support progress update LCD, 
         * it will output current status to LCD. 
         * Support image codec are :
         * BMP / SW GIF / SW JPEG / PNG  
         * (HW GIF / HW JPEG didn't support progress update)
         *
         * We blt the image in callback function by ourselves because
         * we could do more check there
         */
        gdi_nb_set_blt(FALSE, FALSE);
        gdi_nb_set_done_callback(widget_MMI_image_nb_draw_done_callback);

        if (is_resized)
        {
            g_widget_nb_image_array[index].handle = gdi_image_nb_draw_resized_frames(
                                                        (cached)?0:offset_x, 
                                                        (cached)?0:offset_y, 
                                                        resized_width, 
                                                        resized_height, 
                                                        image_ptr,
                                                        frame_id);//, 
                                                        //image_id, 
                                                        //image_size);
        }
        else
        {
            g_widget_nb_image_array[index].handle = gdi_image_nb_draw_frames(
                                                        (cached)?0:offset_x, 
                                                        (cached)?0:offset_y, 
                                                        image_ptr,
                                                        frame_id);//, 
                                                        //image_id, 
                                                        //image_size);

        }

        if (g_widget_nb_image_array[index].handle)
        {
            g_widget_nb_image_array[index].is_used = KAL_TRUE;
            g_widget_nb_image_array[index].gimg = gimg;
            g_widget_nb_image_array[index].offset_x = offset_x;
            g_widget_nb_image_array[index].offset_y = offset_y;
            ret = WIDGET_DRAW_IMAGE_IN_NONBLOCKING;
        }
        else
        {
            /* reguest to non-block drawing fail */
            ret = WIDGET_MAX_NB_DRAW_IMAGE_NUM;
        }

        if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_START)
        {
            /* Update the state in pre-cache non-blocking image_procedure */
            if (ret == WIDGET_MAX_NB_DRAW_IMAGE_NUM)
            {
                WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_ERROR;
            }
            else
            {
                WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_PROCESSING;
            }
        }
    }
    else if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_START)
    {
        /* Don't need to nonblocking image drawing in pre-cache non-blocking image_procedure */
        WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NO_NEED;
    }
    else
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
    {
        if (is_resized)
        {
            ret = gdi_image_draw_resized_frames(
                    offset_x,
                    offset_y,
                    resized_width,
                    resized_height,
                    image_ptr,
                    frame_id);//,
                    //image_id,
                    //image_size);
        }
        else
        {
            ret = gdi_image_draw_frames(
                    offset_x,
                    offset_y,
                    image_ptr,
                    frame_id);//,
                    //image_id,
                    //image_size);
        }
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_IMAGE_DRAW, is_resized, image_id, ret);
    return ret;
}


#ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
/*****************************************************************************
 * FUNCTION
 *  widget_MMI_image_draw_enlarge_resized_file
 * DESCRIPTION
 *  The function is for zoom in the image (doesn't include JPG format)
 *  The gdi API supports zoom in .JPG image.
 *  We don't support enlarge resized (zoom-in) at low MCU power projects.
 *  We support async gdi_image_nb_draw_xxx in low MCU power projects and 
 *  support this feature will increase the code complexity.
 *
 * PARAMETERS
 *  org_width       [IN]    the width of orginal image
 *  org_height      [IN]    the height of original image
 *  x               [IN]
 *  y               [IN]
 *  width           [IN]    the width of enlarged size
 *  height          [IN]    the height of enlarged size
 *  full_name       [IN]    the image file name
 *  is_animation_frmae    [IN]     if the animation
 *  frame           [IN]    the frame index of the animation file
 * RETURNS
 *  void
 *****************************************************************************/
static int widget_MMI_image_draw_enlarge_resized_file(
            S32 org_width,
            S32 org_height,
            S32 x,
            S32 y,
            S32 width,
            S32 height,
            kal_int8* full_name,
            kal_bool  is_animation_frame,
            kal_uint16 frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 src_buffer_size;
    kal_uint8 *src_image_ptr = NULL;
    kal_uint8 *base_layer_ptr = NULL;
    kal_int32 base_w, base_h;
    int clip_x1, clip_x2, clip_y1, clip_y2;
    int bound_x1, bound_x2, bound_y1, bound_y2;
    gdi_handle resizer_src_layer;
    gdi_handle base_layer;
    GDI_RESULT draw_result = -1;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __PRODUCTION_RELEASE__
    ASSERT(WIDGET_IS_MMI_TASK());
#endif 
    /* Check if the enlarged image size */
    if (width * height > GDI_LCD_WIDTH * GDI_LCD_HEIGHT)
    {
        width = org_width;
        height = org_height;

        return -1;
    }

    src_buffer_size = (org_width * org_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
    src_image_ptr = (kal_uint8*) mmi_frm_scrmem_alloc(src_buffer_size);
    if (src_image_ptr != NULL)
    {
        gdi_layer_create_using_outside_memory(
            0,
            0,
            org_width,
            org_height,
            &resizer_src_layer,
            (PU8) src_image_ptr,
            (S32) src_buffer_size);
        gdi_layer_get_base_handle(&base_layer);
        gdi_layer_get_buffer_ptr(&base_layer_ptr);
        gdi_layer_get_dimension(&base_w, &base_h);

        /* set the clip region */
        clip_x1 = x;
        clip_y1 = y;
        clip_x2 = x + width;
        clip_y2 = y + height;
        
        widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);        
        if (!widget_clipping_intersection
            (&clip_x1, &clip_y1, &clip_x2, &clip_y2, bound_x1, bound_y1, bound_x2, bound_y2))
        {
            /* Should never go here */
            WAP_DBG_ASSERT(0);
            /* Image out of content region, return 0 directly */
            gdi_layer_free(resizer_src_layer);
            mmi_frm_scrmem_free((void*)src_image_ptr);
            return 0;
        }
        gdi_layer_push_and_set_active(resizer_src_layer);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_set_opacity(FALSE, 255);
        if (is_animation_frame)
        {
            /* reset gdi cache */
            gdi_image_gif_reset();

            draw_result = gdi_image_gif_draw_file((S32) 0, (S32) 0, (const S8*)full_name, (U16) frame);
        }
        else
        {
            draw_result = gdi_image_draw_file((S32) 0, (S32) 0, (S8*)full_name);
        }
        gdi_layer_pop_and_restore_active();
        gdi_layer_set_clip(clip_x1,clip_y1,clip_x2,clip_y2);
        gdi_resize_bitblt(
            resizer_src_layer,
            0,0,
            org_width-1,
            org_height-1,
            x,y,
            x+width-1,y+height-1);

        gdi_layer_free(resizer_src_layer);
        mmi_frm_scrmem_free((void*)src_image_ptr);

        return draw_result;
    }
    else
    {
        /* maybe allocate memory succeed for one image pointer */ 
        if (src_image_ptr != NULL)
        {
            mmi_frm_scrmem_free((void*)src_image_ptr);
        }
    }
    
    return -1;
}

#endif /* #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE */


/****************************************************************
 *
 *  GIF Animation
 *
 ****************************************************************/

/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_GIF_animation_hdlr
 * DESCRIPTION
 *  Timer handler for GIF animation
 *  
 *  NOTE 1: This code is NOT trivial. Be careful to modify it.
 *  NOTE 2: We cannot use gdi_image_draw_animation because the number of GIF animation
 *  is limited.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Part of  widget_paint_GIF_animation_hdlr() executed in MMI task */
static void widget_MMI_paint_GIF_animation_hdlr(int in_blocking_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gif_animation_struct *animation_ptr;
    widget_gif_animation_struct *curr, *prev;
    GDI_RESULT draw_result = -1;
    kal_bool   is_single_animation = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __PRODUCTION_RELEASE__
    ASSERT(WIDGET_IS_MMI_TASK());
#endif 

    /* Setup RPC parameter */
    if (WIPC_CTX->GIF_animation_ptr)
    {
        is_single_animation = KAL_TRUE;
    }
    animation_ptr = WIPC_CTX->GIF_animation_ptr;
    WIPC_CTX->GIF_animation_ptr = NULL;

    /* Check conditions */
    if (!WGUI_CTX->is_widget_screen)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR_END_WRONG_SCREEN);
        widget_stop_animate(KAL_TRUE);
        return;
    }

    if (!WIMG_CTX->gif_head)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR_END_NO_IMAGE);
        return;
    }

    /*
     * Sometimes the widget screen only display for a very short time, and animation might be drawn
     * * before widget_paint_hdlr() is invoked, i.e. the screen is not yet redrawed. 
     * * As a result, the busy icon in the title might appears on non-WAP screen.
     */
    if (!WGUI_CTX->is_painted)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR_END_WRONG_STATE);
        WGUI_CTX->animate_GIF_after_screen_painted = 1;
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR);

    /* Save clipping */
    gui_push_clip();

    curr = WIMG_CTX->gif_head;
    while (curr)
    {
        if (animation_ptr && curr != animation_ptr)
        {
            curr = curr->next;
            continue;
        }
        WAP_DBG_ASSERT(!curr->mark_to_delete);

        if (curr->remain_tick_count > 0)
        {
            if (curr->draw_in_nonblocking == KAL_FALSE)
            {
                /* we only update remain_tick_count when the image was drawn */
                curr->remain_tick_count--;
            }
            curr = curr->next;
            continue;
        }

        gui_lock_double_buffer();
        gui_set_clip(curr->clip[0], curr->clip[1], curr->clip[2], curr->clip[3]);
        gdi_image_clear_work_buffer();
        if (curr->data)
        {
            if (curr->resized_width > 0 && curr->resized_height > 0)
            {
                /* draw the resized image */
                draw_result = widget_MMI_image_draw(
                                _GIMG(curr->image_gadget),
                                curr->x,
                                curr->y,
                                curr->resized_width,
                                curr->resized_height,
                                curr->data,
                                GDI_IMAGE_TYPE_GIF,
                                (U16)curr->size,
                                curr->curr_frame,
                                KAL_TRUE);
            }
            else
            {
                /* draw the original image */
                draw_result = widget_MMI_image_draw(
                                _GIMG(curr->image_gadget),
                                curr->x,
                                curr->y,
                                curr->width,
                                curr->height,
                                curr->data,
                                GDI_IMAGE_TYPE_GIF,
                                (U16)curr->size,
                                curr->curr_frame,
                                KAL_FALSE);
            }
        }
        else
        {
            /* draw the image from file */
            S8 *full_name;

            ASSERT(curr->filename);
            full_name = (S8*) HDI_FileNameTranslate(curr->filename);

            if (curr->resized_width > 0 && curr->resized_height > 0)
            {
              #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
                kal_int16 w = _IMG(curr->image)->size.width;
                kal_int16 h = _IMG(curr->image)->size.height;

                if (curr->resized_width > w||
                    curr->resized_height > h)
                {
                    /* Zoom In: enlarge the image */
                    draw_result = widget_MMI_image_draw_enlarge_resized_file(
                                    w,
                                    h,
                                    curr->x,
                                    curr->y,
                                    curr->resized_width,
                                    curr->resized_height,
                                    (kal_int8*)full_name,
                                    KAL_TRUE,
                                    (kal_uint16)curr->curr_frame);
                    if (draw_result < 0)
                    {
                        draw_result = gdi_image_gif_draw_file((S32) curr->x, (S32) curr->y, full_name, (U16) curr->curr_frame);
                    }
                }
                else
            #endif /* #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE */
                {
                    /* draw the resized image */
                    draw_result = widget_MMI_image_draw_file(
                                    _GIMG(curr->image_gadget),
                                    curr->x,
                                    curr->y,
                                    curr->resized_width,
                                    curr->resized_height,
                                    full_name,
                                    curr->curr_frame,
                                    KAL_TRUE);
                }
            }
            else
            {
                /* draw the original image */
                draw_result = widget_MMI_image_draw_file(
                                _GIMG(curr->image_gadget),
                                curr->x,
                                curr->y,
                                curr->width,
                                curr->height,
                                full_name,
                                curr->curr_frame,
                                KAL_FALSE);
            }

            HDI_FileNameFree((kal_uint8*) full_name);
        }
        gui_unlock_double_buffer();

    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        if (draw_result == WIDGET_DRAW_IMAGE_IN_NONBLOCKING)
        {
            curr->draw_in_nonblocking = KAL_TRUE;
        }
    #endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

        /* GIF decoder returns GDI_GIF_SUCCESS for success.
           Both return codes are greater or equal to zero. */

        if (draw_result < 0)    /* Decoding fail */
        {
            if (curr->curr_frame == 0       /* Error on first-time display. The image has problem. */
                || curr->curr_frame == 1)   /* The image has only one frame, we do not need to put it in animation queue */
            {
                curr->mark_to_delete = 1;   /* Delete animation */
                curr = curr->next;
            }
            else    /* The current frame has problem */
            {
                curr->total_frames = curr->curr_frame;  /* Set the total frame count */
                curr->curr_frame = 0;
                /* Let 'curr' stay unchanged and re-display it. */
            }

            // i--;
            // TODO: do more test on it
            continue;
        }
        else    /* GDI_GIF_SUCCESS */
        {
            U32 remain_tick;

            WAP_DBG_ASSERT(draw_result == GDI_GIF_SUCCEED);

            remain_tick = gdi_image_get_animation_delay();

            /* Round to multiple of minimum time unit */
            remain_tick /= WIDGET_GIF_ANIMATION_BASE_TIME;
            if (remain_tick == 0)
            {
                remain_tick = 1;
            }
            else if (remain_tick > 255)
            {
                remain_tick = 255;
            }
            curr->remain_tick_count = (kal_uint8) remain_tick;

            if (curr->total_frames > 0 /* The number of frames is already known */  &&
                curr->curr_frame >= curr->total_frames - 1 /* The last frame */ )
            {
                curr->curr_frame = 0;   /* Back to the first frame */
            }
            else
            {
                curr->curr_frame++;
            }
        }

        /*
         * Blt double buffer when there are more than one frame
         * *
         * * If it is drawed from widget_paint_hdlr, we don't need to blit by ourself.
         * *
         * * For the first round, curr->total_frames is always 0, 
         * * A. curr->curr_frame == 0, BLT later when widget_paint is finished
         * * B. curr->curr_frame > 0, we already know that it contains more than one frame
         */
        if ((draw_result >= 0) && (curr->force_blt || curr->curr_frame > 0 || curr->total_frames > 0))
            /* Or we can use (curr->force_blt || arg == NULL) instead? */
        {
            if (curr->resized_width > 0 && curr->resized_height > 0)
            {
                gui_BLT_double_buffer(
                    curr->x,
                    curr->y,
                    curr->x + curr->resized_width - 1,
                    curr->y + curr->resized_height - 1);
            }
            else
            {
                gui_BLT_double_buffer(curr->x, curr->y, curr->x + curr->width - 1, curr->y + curr->height - 1);
            }
        }

        curr = curr->next;
    }

    /* Restore clipping */
    gui_pop_clip();

    /* Remove non-animated images from WIMG_CTX->gif_head */
    if (WIMG_CTX->gif_head)
    {
        prev = WIMG_CTX->gif_head;
        curr = prev->next;
        while (curr)
        {
            if (curr->mark_to_delete)
            {
                prev->next = curr->next;
                MSF_MEM_FREE(MSF_MODID_WIDGET, curr);
            }
            else
            {
                prev = curr;
            }
            curr = prev->next;
        }

        /* Remove WIMG_CTX->gif_head */
        curr = WIMG_CTX->gif_head;
        WAP_DBG_ASSERT(curr);
        if (curr->mark_to_delete)
        {
            WIMG_CTX->gif_head = curr->next;
            MSF_MEM_FREE(MSF_MODID_WIDGET, curr);
        }
    }

    if (WIMG_CTX->gif_head && draw_result != WIDGET_DRAW_IMAGE_IN_NONBLOCKING)
    {
        /* Restart oneshot timer */
        widget_start_timer(WIDGET_ANIMATE_TIMER, widget_paint_GIF_animation_hdlr, NULL, WIDGET_GIF_ANIMATION_BASE_TIME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_GIF_animation_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_GIF_animation_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->is_widget_screen)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_GIF_ANOMATION_HDLR_END_WRONG_SCREEN);
        widget_stop_animate(KAL_TRUE);
        return;
    }

    if (!WIMG_CTX->gif_head)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_GIF_ANOMATION_HDLR_END_NO_IMAGE);
        return;
    }

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    if ((int)arg == WIDGET_DRAW_IMAGE_IN_NONBLOCKING)
    {
        /* draw all of non-blocking animation */
        widget_execute_MMI_i(widget_MMI_paint_GIF_animation_hdlr, 0, KAL_TRUE);
    }
    else
#endif /* #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

    {
        /*
         * draw blocking animation:
         * 1. WIPC_CTX->GIF_animation_ptr != NULL
         *        draw the single animation 
         * 2. WIPC_CTX->GIF_animation_ptr == NULL
         *        draw all of animation
         */

        WIPC_CTX->GIF_animation_ptr = (widget_gif_animation_struct*) arg;

        widget_execute_MMI_i(widget_MMI_paint_GIF_animation_hdlr, 1, KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_animate
 * DESCRIPTION
 *  Stop the GIF animation
 * PARAMETERS
 *  is_force        [IN]        Remove all GIF animation or only those with 'auto_remove' flag set
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_animate(kal_bool is_force)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gif_animation_struct *prev, *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WIMG_CTX->gif_head)
    {
        return;
    }

    /* Remove animation except for WIMG_CTX->gif_head */
    prev = WIMG_CTX->gif_head;
    curr = prev->next;
    while (curr)
    {
        if (is_force || curr->auto_remove)
        {
            if (curr == WIMG_CTX->busy_indication_icon)
            {
                WIMG_CTX->busy_indication_icon = NULL;
            }
            prev->next = curr->next;
            MSF_MEM_FREE(MSF_MODID_WIDGET, curr);
        }
        else
        {
            prev = curr;
        }
        curr = prev->next;
    }

    /* Remove WIMG_CTX->gif_head */
    curr = WIMG_CTX->gif_head;
    WAP_DBG_ASSERT(curr);
    if (is_force || curr->auto_remove)
    {
        if (curr == WIMG_CTX->busy_indication_icon)
        {
            WIMG_CTX->busy_indication_icon = NULL;
        }
        WIMG_CTX->gif_head = curr->next;
        MSF_MEM_FREE(MSF_MODID_WIDGET, curr);
    }

    /* Stop timer */
    if (!WIMG_CTX->gif_head)
    {
        widget_stop_timer(WIDGET_ANIMATE_TIMER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_animate_by_ptr
 * DESCRIPTION
 *  Stop GIF animation indicated by a pointer
 * PARAMETERS
 *  ptr     [IN]        The pointer indicating the GIF animation
 * RETURNS
 *  whether the animation is found and stopped.
 *****************************************************************************/
kal_bool widget_stop_animate_by_ptr(widget_gif_animation_struct *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gif_animation_struct *curr, *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ptr || !WIMG_CTX->gif_head)
    {
        return KAL_FALSE;   /* Exit */
    }

    if (ptr == WIMG_CTX->gif_head)
    {
        WIMG_CTX->gif_head = WIMG_CTX->gif_head->next;
        MSF_MEM_FREE(MSF_MODID_WIDGET, ptr);
        if (!WIMG_CTX->gif_head)
        {
            widget_stop_timer(WIDGET_ANIMATE_TIMER);
        }
        return KAL_TRUE;    /* Exit */
    }

    prev = WIMG_CTX->gif_head;
    curr = prev->next;
    while (curr)
    {
        if (ptr == curr)
        {
            prev->next = curr->next;
            MSF_MEM_FREE(MSF_MODID_WIDGET, curr);
            return KAL_TRUE;    /* Exit */
        }
        prev = curr;
        curr = curr->next;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_animate_by_image
 * DESCRIPTION
 *  Stop GIF animation indicated by a MsfImage or MsfPredefinedImage
 * PARAMETERS
 *  image       [IN]        The image generating the animation to be removed
 * RETURNS
 *  whether the animation is found and stopped.
 *****************************************************************************/
kal_bool widget_stop_animate_by_image(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL found = MMI_FALSE;
    widget_gif_animation_struct *curr, *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!image || !WIMG_CTX->gif_head)
    {
        return KAL_FALSE;
    }

    /*
     * Because BRS may use one MsfImage in multiple MsfImageGadgets, 
     * * There might be multiple animations mapped to one MsfImage.
     */

    /* Mark animations to delete */
    curr = WIMG_CTX->gif_head;
    while (curr)
    {
        if (curr->image == image)
        {
            curr->mark_to_delete = 1;
            found = MMI_TRUE;
        }
        prev = curr;
        curr = curr->next;
    }

    /* Deletae animations */
    prev = WIMG_CTX->gif_head;
    curr = prev->next;
    while (curr)
    {
        if (curr->mark_to_delete)
        {
            prev->next = curr->next;
            MSF_MEM_FREE(MSF_MODID_WIDGET, curr);
        }
        else
        {
            prev = curr;
        }
        curr = prev->next;
    }

    /* Remove WIMG_CTX->gif_head */
    curr = WIMG_CTX->gif_head;
    WAP_DBG_ASSERT(curr);
    if (curr->mark_to_delete)
    {
        WIMG_CTX->gif_head = curr->next;
        MSF_MEM_FREE(MSF_MODID_WIDGET, curr);
    }

    if (!WIMG_CTX->gif_head)
    {
        widget_stop_timer(WIDGET_ANIMATE_TIMER);
    }

    return found ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_show_animate_image_by_raw_data
 * DESCRIPTION
 *  General function to draw an image and register animation if necessary.
 * PARAMETERS
 *  gimg                            [IN]         
 *  img                             [IN]        The corresponding image object. This is used for stop decoding when releasing the object later.
 *  x                               [IN]        X-axis position to draw the image
 *  y                               [IN]        Y-axis position to draw the image
 *  image_format                    [IN]        Image format
 *  data                            [IN]        1. image raw data or 2. file name
 *  size                            [IN]        Image data size or file size. (however, we don't use size if use_source_file is set)
 *  width                           [IN]        Image original width
 *  height                          [IN]        Image original height
 *  maxSize                         [IN]        NULL or max displayable size (also used by image zooming)
 *  imageZoom                       [IN]        Only MsfImageZoomAutofit is supported
 *  use_source_file                 [IN]        Whether 'data' is raw data or filename
 *  auto_remove                     [IN]        See widget_stop_animate()
 *  clipping_to_content_size        [IN]        Clipping to display region (not including title bar and softkey)
 *  force_blt                       [IN]        Invoke UI_BLT_double_buffer() even for single-frame GIF.
 *  do_animation                    [IN]        Register animation if this is GIF image; otherwise, do not animate the image
 * RETURNS
 *  NULL     if animation is not available for this image
 *  Otherwise,  the pointer indicating this animation
 *****************************************************************************/
widget_gif_animation_struct *widget_show_animate_image_by_raw_data(
                                widget_gadget_image_struct *gimg,
                                widget_image_struct *img,
                                S32 x,
                                S32 y,
                                int image_format,
                                void *data,
                                int size,
                                int width,
                                int height,
                                MsfSize *maxSize,
                                MsfImageZoom imageZoom,
                                kal_bool use_source_file,
                                kal_bool auto_remove,
                                kal_bool clipping_to_content_size,
                                kal_bool force_blt,
                                kal_bool do_animation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gif_animation_struct *return_value = NULL;
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    S32 zoom_offset_x, zoom_offset_y;
    S32 zoom_size_width, zoom_size_height;
#ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
    kal_bool enlarge_resize = KAL_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (width <= 0 || height <= 0)
    {
        return return_value;
    }

    /* Set clip to the image dimension */
    clip_x1 = x;
    clip_y1 = y;
    clip_x2 = x + width - 1;
    clip_y2 = y + height - 1;

    if (maxSize)
    {
        /* support zoom in the image */
        if (maxSize->width > 0)
        {
            clip_x2 = x + maxSize->width - 1;
        }
        if (maxSize->height > 0)
        {
            clip_y2 = y + maxSize->height - 1;
        }
    }

    if (maxSize && (maxSize->width <= 0 || maxSize->height <= 0))
    {
        maxSize = NULL;
    }

#ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
    /* we don't support enlarge resize in low power project */
    if (maxSize && (maxSize->width > width || maxSize->height > height))
    {
        enlarge_resize = KAL_TRUE;
    }
#endif /* #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE */

    if (imageZoom == MsfImageZoomAutofit && maxSize)
    {
    #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
        if (enlarge_resize)
        {
            zoom_offset_x = gimg->border_offset.x = 0;
            zoom_offset_y = gimg->border_offset.y = 0;
            zoom_size_width = gimg->border_size.width = maxSize->width;
            zoom_size_height = gimg->border_size.height = maxSize->height;
        }
        else
    #endif /* #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE */
        {
            gdi_image_util_fit_bbox(
                maxSize->width,
                maxSize->height,
                width,
                height,
                &zoom_offset_x,
                &zoom_offset_y,
                &zoom_size_width,
                &zoom_size_height);

            zoom_size_width = (zoom_size_width) ? zoom_size_width : 1;
            zoom_size_height = (zoom_size_height) ? zoom_size_height : 1;
            /* Update border size/position */
            if (gimg && zoom_size_width > 0 && zoom_size_height > 0)
            {
                gimg->border_offset.x = zoom_offset_x;
                gimg->border_offset.y = zoom_offset_y;
                gimg->border_size.width = zoom_size_width;
                gimg->border_size.height = zoom_size_height;
            }
        }
    }
    else
    {
        zoom_offset_x = zoom_offset_y = 0;
        zoom_size_width = zoom_size_height = -1;
    }

    if (clipping_to_content_size)
    {
        int bound_x1, bound_x2, bound_y1, bound_y2;

        widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);

        if (!widget_clipping_intersection
            (&clip_x1, &clip_y1, &clip_x2, &clip_y2, bound_x1, bound_y1, bound_x2, bound_y2))
        {
            return return_value;    /* Image out of content region */
        }
        
        /* If the image is in the marquee, we need to check marquee's image is drawn in marquee area. */
        if (img->data_type != WIDGET_PRE_IMAGE_TYPE && img->is_in_drawing_marquee &&
            img->draw_op_border_size.width != 0 && img->draw_op_border_size.height != 0)
        {
            bound_x1 = /*WGUI_CTX->display_pos.x + */img->draw_op_border_position.x;
            bound_y1 = /*WGUI_CTX->display_pos.y + */img->draw_op_border_position.y;
            bound_x2 = bound_x1 + img->draw_op_border_size.width - 1;
            bound_y2 = bound_y1 + img->draw_op_border_size.height - 1;
            
            img->is_in_drawing_marquee = 0;
            if (!widget_clipping_intersection
                (&clip_x1, &clip_y1, &clip_x2, &clip_y2, bound_x1, bound_y1, bound_x2, bound_y2))
            {
                return return_value;    /* Image out of content region */
            }
        }
    }
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    switch (image_format)
    {
        case MsfGif:
        case MsfGifPI:
            if (do_animation)
            {
                widget_gif_animation_struct *ani, *curr, *tmp;

                /* Stop timer (it will be restarted later) */
                widget_stop_timer(WIDGET_ANIMATE_TIMER);

                /* Create animation data or use existing one */
                ani = NULL;
                curr = WIMG_CTX->gif_head;
                while (curr)
                {
                    /* BRS put the same MsfImage into multiple MsfImageGadgets */
                    if (((MsfGadgetHandle) gimg == curr->image_gadget) &&
                        ((img && curr->image == (MsfImageHandle) img) ||
                         (!use_source_file && curr->data == data) ||
                         (use_source_file && curr->filename[0] && strcmp(curr->filename, data) == 0)))
                    {
                        ani = curr;
                        break;
                    }

                    curr = curr->next;
                }

                if (ani == NULL)    /* No existing entry */
                {
                    ani =
                        (widget_gif_animation_struct*) MSF_MEM_ALLOC(
                                                        MSF_MODID_WIDGET,
                                                        sizeof(widget_gif_animation_struct));
                    if (!ani)
                    {
                        WAP_BYPASS_ASSERT(0);
                        break;
                    }
                    ani->next = WIMG_CTX->gif_head;
                    WIMG_CTX->gif_head = ani;
                }

                /* Fill animation data */
                tmp = ani->next;
                memset(ani, 0, sizeof(widget_gif_animation_struct));
                ani->next = tmp;

                ani->image = (MsfImageHandle) img;
                ani->image_gadget = (MsfGadgetHandle) gimg;
                if (use_source_file)
                {
                    ASSERT(strlen(data) <= WIDGET_RAWFILE_NAMELEN);
                    strcpy(ani->filename, data);
                    ani->data = NULL;
                }
                else
                {
                    ani->filename[0] = '\0';
                    ani->data = data;
                }
                ani->size = size;
                ani->width = width;
                ani->height = height;
                ani->resized_width = zoom_size_width;
                ani->resized_height = zoom_size_height;
                ani->clip[0] = clip_x1;
                ani->clip[1] = clip_y1;
                ani->clip[2] = clip_x2;
                ani->clip[3] = clip_y2;
                ani->x = x + zoom_offset_x;
                ani->y = y + zoom_offset_y;
                ani->total_frames = 0;  /* we do not know the number of frames at first time */
                ani->curr_frame = 0;
                ani->force_blt = force_blt ? 1 : 0;
                ani->auto_remove = auto_remove ? 1 : 0;
                ani->mark_to_delete = 0;
                ani->remain_tick_count = 0;
                ani->draw_in_nonblocking = KAL_FALSE;

                return_value = ani;

                widget_paint_GIF_animation_hdlr(ani);
            }
            else    /* !do_animation */
            {
                gdi_image_clear_work_buffer();
                if (use_source_file)
                {
                    S8 *full_name;

                    full_name = (S8*) HDI_FileNameTranslate(data);
                    if (zoom_size_width < 0)
                    {
                        /* draw the original image */
                        widget_MMI_image_draw_file(gimg, x, y, width, height, full_name, 0, KAL_FALSE);
                    }
                    else
                    {
                    #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
                        if (enlarge_resize)
                        {
                            /* Zoom In: enlarge the image */
                            if (widget_MMI_image_draw_enlarge_resized_file(
                                    width,
                                    height,
                                    x + zoom_offset_x,
                                    y + zoom_offset_y,
                                    zoom_size_width,
                                    zoom_size_height,
                                    (kal_int8*)full_name,
                                    KAL_FALSE,
                                    0) < 0)
                            {
                                /* If enlarge image fail, draw the original image */
                                gdi_image_draw_file((S32) x, (S32) y, full_name);
                            }
                        }
                        else
                    #endif /* #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE */
                        {
                            /* draw the resized image */                            
                            widget_MMI_image_draw_file(
                                gimg,
                                x + zoom_offset_x,
                                y + zoom_offset_y,
                                zoom_size_width,
                                zoom_size_height,
                                full_name,
                                0,
                                KAL_TRUE);
                        }
                    }

                    HDI_FileNameFree((kal_uint8*) full_name);
                }
                else
                {
                    /* draw image from memory */
                    if (zoom_size_width < 0)
                    {
                        /* draw the original image */
                        widget_MMI_image_draw(gimg, x, y, width, height, (U8*)data, GDI_IMAGE_TYPE_GIF, (U16)size, 0, KAL_FALSE);
                    }
                    else
                    {
                        /* draw the resized image */
                        widget_MMI_image_draw(
                            gimg,
                            x + zoom_offset_x,
                            y + zoom_offset_y,
                            zoom_size_width,
                            zoom_size_height,
                            data,
                            GDI_IMAGE_TYPE_GIF,
                            (U16)size,
                            0,
                            KAL_TRUE);
                    }
                }
            }

            break;

        case MsfBmp:
        case MsfWbmp:
    #ifdef GDI_USING_PNG
        case MsfPng:
    #endif
    #ifdef WIDGET_JPEG_SUPPORT
        case MsfJpeg:
    #endif
            if (use_source_file)
            {
                S8 *full_name;

                full_name = (S8*) HDI_FileNameTranslate(data);
                if (zoom_size_width < 0)
                {
                    /* draw the original image */
                    widget_MMI_image_draw_file(gimg, x, y, width, height, full_name, 0, KAL_FALSE);
                }
                else
                {
                #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
                    if (enlarge_resize)
                    {
                        /* Zoom In: enlarge the image */
                        if (widget_MMI_image_draw_enlarge_resized_file(
                                width,
                                height,
                                x + zoom_offset_x,
                                y + zoom_offset_y,
                                zoom_size_width,
                                zoom_size_height,
                                (kal_int8*)full_name,
                                KAL_FALSE,
                                0) < 0)
                        {
                            /* If enlarge image fail, draw the original image */
                            gdi_image_draw_file((S32) x, (S32) y, full_name);
                        }
                    }
                    else
                #endif /* #ifdef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE */
                    {
                        /* draw the resized image */
                        widget_MMI_image_draw_file(
                            gimg,
                            x + zoom_offset_x,
                            y + zoom_offset_y,
                            zoom_size_width,
                            zoom_size_height,
                            full_name,
                            0,
                            KAL_TRUE);
                    }
                }

                HDI_FileNameFree((kal_uint8*) full_name);
            }
            else
            {
                /* draw image from memory */
                if (zoom_size_width < 0)
                {
                    /* draw the original image */
                    widget_MMI_image_draw(gimg, x, y, width, height, (U8*)data, widget_get_gdi_image_id(image_format), (U16)size, 0, KAL_FALSE);
                }
                else
                {
                    /* draw the resized image */
                    widget_MMI_image_draw(
                        gimg,
                        x + zoom_offset_x,
                        y + zoom_offset_y,
                        zoom_size_width,
                        zoom_size_height,
                        data,
                        widget_get_gdi_image_id(image_format),
                        (U16)size,
                        0,
                        KAL_TRUE);
                }
            }

            break;

        case MsfPbmPI:
        case MsfAbmPI:
        case MsfBmpPI:
        case MsfJpegPI:
        case MsfPngPI:
            /* The current GUI implementation cannot display Pbm Image from file */
            WAP_DBG_ASSERT(!use_source_file);
            if (!use_source_file)
            {
                gdi_image_draw(x, y, (PU8)data);
            }
            break;

/*******************************************************/
#if 0 /* remove it later */
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
        #ifdef GDI_USING_PNG
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
        #endif /* GDI_USING_PNG */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef WIDGET_JPEG_SUPPORT
        #if !defined(WIDGET_SUPPORT_LARGE_JPEG)
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
        #else /* !defined(WIDGET_SUPPORT_LARGE_JPEG) */ 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* !defined(WIDGET_SUPPORT_LARGE_JPEG) */ /* Support output by clipping */
        #endif /* WIDGET_JPEG_SUPPORT */ 
/* under construction !*/
#endif /* #if 0 */
/*******************************************************/
        default:
            break;
    }

    return return_value;
}

/****************************************************************
 *
 *  Image gadget paint routines
 *
 ****************************************************************/

/* Internal function used by widget_paint_gadget_image() */


/*****************************************************************************
 * FUNCTION
 *  widget_show_animate_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  gimg        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_show_animate_image(S32 x, S32 y, widget_gadget_image_struct *gimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfImageHandle image = gimg->image;
    void *source;
    kal_bool use_source_file;
    kal_bool do_animation;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!image || !widget_image_is_ready(image))    /* Image not ready */
    {
        return;
    }
    if ((source = widget_image_content(image)) != NULL)
    {
        use_source_file = KAL_FALSE;
    }
    else if ((source = widget_image_content_file(image)) != NULL)
    {
        use_source_file = KAL_TRUE;
    }
    else
    {
        /* Should not happen */
        WAP_DBG_ASSERT(0);
        return;
    }

    /* Initialize GIF frame count in MMI task */
    if (IS_IMAGE_TYPE(image) && !_IMG(image)->GIF_frames_initialized)
    {
        widget_MMI_initialize_image_frame_count(image);
        _IMG(image)->GIF_frames_initialized = 1;
    }

#ifdef WIDGET_PRECACHE_IMAGE
    /* No matter gimg->zoom == MsfImageZoomAutofit, maximum dimension is bounded by gimg->size */
    if (IS_IMAGE_TYPE(image) && widget_image_is_precached(_IMG(image), gimg->size.width, gimg->size.height, gimg->zoom))
    {
/*		Trace2(TRACE_GROUP_2, "[Widget] show_animate_image - show Precached image [cache_layer:0x%x, enable:%d, created:%d]",
			WPCACHE_CTX->cache_layer, WPCACHE_CTX->layer_enabled,WPCACHE_CTX->layer_created); */
        widget_MMI_show_precached_image(x, y, KAL_TRUE);
    }
    else
    {
        kal_bool cached = KAL_FALSE;
        kal_bool prepare_precache = KAL_FALSE;
        kal_bool conflict = KAL_FALSE; /* The current image is different with the pre-cache one */

    #ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        if (IS_IMAGE_TYPE(image) && 
            _IMG(image)->GIF_frames <= 1)
        {
            /*
             * If drawing disable animation directly, we don't use pre-cache mechanism
             * Doesn't support in WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
             */
            prepare_precache = KAL_TRUE;
        }
    #else
        if (IS_IMAGE_TYPE(image) && 
            ((_IMG(image)->GIF_frames <= 1) || (_IMG(image)->disable_animation)) &&
            _IMG(image)->precache_state != WIDGET_PRECACHE_IMAGE_NONE)
        {
            prepare_precache = KAL_TRUE;
        }
    #endif /* #ifndef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

        if (prepare_precache)
        {
            /* we will cache the image if drawing the image in blocking */
//			Trace2(TRACE_GROUP_2, "[Widget] show_animate_image - Prepare Precached image");
            if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_DONE)
            {
                conflict = KAL_TRUE;
                WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_START;
            }

            cached = widget_MMI_prepare_precache_image(_IMG(image), gimg->size.width, gimg->size.height, gimg->zoom);
        }

        if (cached)
        {
            do_animation = KAL_FALSE;
        }
        else if (IS_IMAGE_TYPE(image) && (_IMG(image)->GIF_frames <= 1 || _IMG(image)->disable_animation))
        {
            do_animation = KAL_FALSE;
        }
        else
        {
            do_animation = KAL_TRUE;
        }

        widget_show_animate_image_by_raw_data(
            gimg,
            _IMG(image), // TODO: wrong typecast, it might be MsfPredefinedImage
            cached ? 0 : x,
            cached ? 0 : y,
            widget_image_format(image),
            source,
            widget_image_length(image),
            widget_image_width(image),
            widget_image_height(image),
            &gimg->size,
            gimg->zoom,
            use_source_file,
            KAL_TRUE,
            cached ? KAL_FALSE : KAL_TRUE,
            KAL_FALSE,
            do_animation);

    #ifndef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
        /* the general precache image mechanism */
        if (cached)
        {
            widget_MMI_finish_precache_image();
            widget_MMI_show_precached_image(x, y, KAL_TRUE);
        }
    #else
        /* the image precache mechanism for nonblocking image drawing */
        if (cached)
        {
            widget_MMI_finish_precache_image();

            if (conflict && WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_PROCESSING)
            {
                /* If the current image is different with the pre-cache one and need to draw in non-blocking,
                 * we change the state and draw the image in widget_MMI_image_nb_draw_done_callback()
                 */
                WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_DRAW_IN_CB;
            }

            if (WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_PROCESSING &&
                WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_DRAW_IN_CB &&
                WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_NO_NEED)
			{
				widget_MMI_show_precached_image(x, y, KAL_TRUE);
			}
        }
        else
        {
            if ((_IMG(image)->image_format == MsfGif) &&
                (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_START))
            {
                /* If drawing the animation, we don't precache the image. */
                /* If in precache nb image, we reset the state */
                WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NO_NEED;
            }
        }
    #endif /* WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */
    }
#else /* WIDGET_PRECACHE_IMAGE */ 
    if (IS_IMAGE_TYPE(image) && (_IMG(image)->GIF_frames <= 1 || _IMG(image)->disable_animation))
    {
        do_animation = KAL_FALSE;
    }
    else
    {
        do_animation = KAL_TRUE;
    }

    widget_show_animate_image_by_raw_data(
        gimg,
        _IMG(image), // TODO: wrong typecast, it might be MsfPredefinedImage
        x,
        y,
        widget_image_format(image),
        source,
        widget_image_length(image),
        widget_image_width(image),
        widget_image_height(image),
        &gimg->size,
        gimg->zoom,
        use_source_file,
        KAL_TRUE,
        KAL_TRUE,
        KAL_FALSE,
        do_animation);
#endif /* WIDGET_PRECACHE_IMAGE */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_draw_queued_operation_from_gadget_image
 * DESCRIPTION
 *  Draw the drawing operations enqueued in an image gadget
 * PARAMETERS
 *  gimg                    [IN]        Image gadget
 *  erase_background        [IN]        Whether to erase the background of the gadget first
 *  force_blit              [IN]        Whether to blit the double buffer
 *  x_offset                [IN]        X-axis offset to drawn content (used by marquee)
 *  y_offset                [IN]        Y-axis offset to drawn content (used by marquee)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool widget_draw_queued_operation_from_gadget_image(
            widget_gadget_image_struct *gimg,
            kal_bool erase_background,
            kal_bool force_blit,
            kal_int16 x_offset,
            kal_int16 y_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img;
    int x1, y1, x2, y2;
    int bound_x1, bound_x2, bound_y1, bound_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(gimg);

    img = _IMG(gimg->image);

    if (!img || !img->draw_op_head)
    {
        if (erase_background)
        {
            widget_gadget_clear_background(_W(gimg), KAL_TRUE);    /* BLT here */
        }

        return KAL_FALSE;
    }

    x1 = WGUI_CTX->current_pos.x + gimg->position.x;
    y1 = WGUI_CTX->current_pos.y + gimg->position.y;
    x2 = x1 + gimg->size.width - 1;
    y2 = y1 + gimg->size.height - 1;

    widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);

    if (!widget_clipping_intersection(&x1, &y1, &x2, &y2, bound_x1, bound_y1, bound_x2, bound_y2))
    {
        return KAL_FALSE;
    }

    if (force_blit)
    {
        gui_lock_double_buffer();
    }

    if (erase_background)
    {
        widget_gadget_clear_background(_W(gimg), KAL_FALSE);    /* No BLT here */
    }

    widget_draw_image_from_queued_op(img, &gimg->position, &gimg->size, x_offset, y_offset);

    if (force_blit)
    {
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_gadget_clear_background
 * DESCRIPTION
 *  Clear the background of a gadget
 * PARAMETERS
 *  w               [IN]        Target gadget
 *  force_blt       [IN]        Whether to blit the double buffer
 * RETURNS
 *  Whether the operation succeed
 *****************************************************************************/
kal_bool widget_gadget_clear_background(widget_window_struct *w, kal_bool force_blt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    int x1, y1, x2, y2;
    int bound_x1, bound_x2, bound_y1, bound_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_GADGET_TYPE(w))
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

#ifdef WIDGET_TMPFIX_MARQUEE_BGCOLOR
    if (IS_GADGET_IMAGE_TYPE(w) && _GIMG(w)->marquee)
    {
        c.alpha = 100;
        c.r = _STYLE(widget_get_style((MSF_UINT32) w))->bg_color.r;
        c.g = _STYLE(widget_get_style((MSF_UINT32) w))->bg_color.g;
        c.b = _STYLE(widget_get_style((MSF_UINT32) w))->bg_color.b;
    }
    else
#endif /* WIDGET_TMPFIX_MARQUEE_BGCOLOR */ 
    {
        widget_window_struct *parent = NULL;
        widget_style_struct *pstyle = NULL;

        if (w->parent && IS_WINDOW_TYPE(w->parent))
        {
            parent = _W(w->parent);
        }
        if (parent)
        {
            pstyle = _STYLE(widget_get_style((MSF_UINT32) parent));
        }

        if (pstyle && !widget_is_transparent_color(&(pstyle->bg_color)))
        {
            /* Background color was drawn by widget_paint_form(MsfForm) or BRS(MsfPaintbox) */
            c.alpha = 100;
            c.r = pstyle->bg_color.r;
            c.g = pstyle->bg_color.g;
            c.b = pstyle->bg_color.b;
        }
        else
        {
            c.alpha = 100;
            c.r = c.g = c.b = 255;
        }
    }

    x1 = WGUI_CTX->current_pos.x + w->position.x;
    y1 = WGUI_CTX->current_pos.y + w->position.y;
    x2 = x1 + w->size.width - 1;
    y2 = y1 + w->size.height - 1;

    widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);

    if (!widget_clipping_intersection(&x1, &y1, &x2, &y2, bound_x1, bound_y1, bound_x2, bound_y2))
    {
        return KAL_FALSE;
    }

    if (force_blt)
    {
        gui_lock_double_buffer();
    }

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    gui_fill_rectangle(x1, y1, x2, y2, c);

    gui_pop_clip();

    if (force_blt)
    {
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }

    return KAL_TRUE;
}

/* The base layer need to be active */
#ifdef WIDGET_SMIL_SLIDING_BAR	/* WIDGET_LARGE_RESOLUTION && !WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

#ifdef WIDGET_RESIDENT_STATUS_ICON
#define TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO   (GDI_LCD_WIDTH*(MMI_title_height+MMI_STATUS_BAR_HEIGHT)*((gdi_act_layer->bits_per_pixel)>>3))
#define TOP_GDI_LAYER_BAR_SIZE_IN_VIDEO     (GDI_LCD_WIDTH*(MMI_BUTTON_BAR_HEIGHT+WIDGET_SLIDING_BAR_REGION_HEIGHT)*((gdi_act_layer->bits_per_pixel)>>3))
#else
#define TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO   (GDI_LCD_WIDTH*MMI_title_height*((gdi_act_layer->bits_per_pixel)>>3))
#define TOP_GDI_LAYER_BAR_SIZE_IN_VIDEO     (GDI_LCD_WIDTH*(MMI_BUTTON_BAR_HEIGHT+WIDGET_SLIDING_BAR_REGION_HEIGHT)*((gdi_act_layer->bits_per_pixel)>>3))
#endif

#define TOP_GDI_LAYER_SIZE_IN_VIDEO         ((TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO)>(TOP_GDI_LAYER_BAR_SIZE_IN_VIDEO)?(TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO):(TOP_GDI_LAYER_BAR_SIZE_IN_VIDEO))

#else /* WIDGET_SMIL_SLIDING_BAR */ 

#ifdef WIDGET_RESIDENT_STATUS_ICON
#define TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO   (GDI_LCD_WIDTH*(MMI_title_height+MMI_STATUS_BAR_HEIGHT)*((gdi_act_layer->bits_per_pixel)>>3))
#else
#define TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO   (GDI_LCD_WIDTH*MMI_title_height*((gdi_act_layer->bits_per_pixel)>>3))
#endif

/* TOP_GDI_LAYER_BAR_SIZE_IN_VIDEO will less than TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO */
#define TOP_GDI_LAYER_SIZE_IN_VIDEO         TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO

#endif /* WIDGET_SMIL_SLIDING_BAR */ 

#ifdef __MMI_SUBLCD__

static void widget_video_exit_sublcd_screen(void);


/*****************************************************************************
 * FUNCTION
 *  widget_video_entry_sublcd_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_video_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(widget_video_exit_sublcd_screen);
}


/*****************************************************************************
 * FUNCTION
 *  widget_video_exit_sublcd_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_video_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    /* also stop preview here */

    SubLCDHistory.entryFuncPtr = widget_video_entry_sublcd_screen;
    AddSubLCDHistory(&SubLCDHistory);
}

static widget_is_sub_lcd_freeze = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  widget_freeze_sub_lcd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_freeze       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_freeze_sub_lcd(MMI_BOOL is_freeze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_freeze == MMI_TRUE)
    {
        if (widget_is_sub_lcd_freeze == MMI_FALSE)
        {
            /* gdi_lcd_freeze */
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_freeze(TRUE);
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            ShowSubLCDScreen(widget_video_entry_sublcd_screen);
            widget_is_sub_lcd_freeze = MMI_TRUE;
        }
    }
    else
    {
        if (widget_is_sub_lcd_freeze == MMI_TRUE)
        {
            GoBackSubLCDHistory();
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_lcd_freeze(FALSE);
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            widget_is_sub_lcd_freeze = MMI_FALSE;
        }
    }
}

#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  widget_copy_title_from_base_layer
 * DESCRIPTION
 *  Because video gdi_layer is the second layer, we need the third gdi_layer overlap the video gdi_layer
 *  If the video gdi_layer is scroll up, the thrid gdi_layer should be the status bar and title bar.
 * PARAMETERS
 *  dest        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_copy_title_from_base_layer(gdi_handle dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *src_ptr = NULL, *dest_ptr = NULL;
    gdi_handle  base_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((WGUI_CTX->top_gdi_layer != 0) && (WGUI_CTX->top_gdi_layer_is_button_bar == 0))
    {
        ASSERT(wgui_base_layer);

        gdi_layer_get_base_handle(&base_layer);
        gdi_layer_push_and_set_active(base_layer);
        gdi_layer_get_buffer_ptr(&src_ptr);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(dest);
        gdi_layer_set_position(0, 0);
    	gdi_layer_toggle_double();
        gdi_layer_get_buffer_ptr(&dest_ptr);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_clip(0, 0, GDI_LCD_WIDTH - 1, WGUI_CTX->display_pos.y - 1);
        memcpy(dest_ptr, src_ptr, TOP_GDI_LAYER_TITLE_SIZE_IN_VIDEO);
        gdi_layer_pop_and_restore_active();

    	if (WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING ||
            WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD)
    	{
    	    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
    	}
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_copy_bar_from_base_layer
 * DESCRIPTION
 *  Because video gdi_layer is the second layer, we need the third gdi_layer overlap the video gdi_layer
 *  If the video gdi_layer is scroll down, the thrid gdi_layer should be the buttom bar.
 * PARAMETERS
 *  dest        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_copy_bar_from_base_layer(gdi_handle dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *src_ptr = NULL, *dest_ptr = NULL;
    gdi_handle  base_layer;
    kal_uint32 buf_offset;
    kal_uint32 buf_size;
    S32 y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((WGUI_CTX->top_gdi_layer != 0) && (WGUI_CTX->top_gdi_layer_is_button_bar == 1))
    {
        ASSERT(wgui_base_layer);

        gdi_layer_get_base_handle(&base_layer);
        gdi_layer_push_and_set_active(base_layer);
        gdi_layer_get_buffer_ptr(&src_ptr);
        gdi_layer_pop_and_restore_active();

    #ifdef WIDGET_SMIL_SLIDING_BAR
        buf_offset =
        GDI_LCD_WIDTH * (GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT -
                         WIDGET_SLIDING_BAR_REGION_HEIGHT) * ((gdi_act_layer->bits_per_pixel) >> 3);
        buf_size =
        GDI_LCD_WIDTH * (MMI_BUTTON_BAR_HEIGHT + WIDGET_SLIDING_BAR_REGION_HEIGHT) * ((gdi_act_layer->bits_per_pixel) >> 3);
        y = GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WIDGET_SLIDING_BAR_REGION_HEIGHT;
    #else /* WIDGET_SMIL_SLIDING_BAR */ 
        buf_offset = GDI_LCD_WIDTH * (GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT) * ((gdi_act_layer->bits_per_pixel) >> 3);
        buf_size = GDI_LCD_WIDTH * MMI_BUTTON_BAR_HEIGHT * ((gdi_act_layer->bits_per_pixel) >> 3);
        y = GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT;
    #endif /* WIDGET_SMIL_SLIDING_BAR */ 

        gdi_layer_push_and_set_active(dest);
        gdi_layer_set_position(0, y);
    	gdi_layer_toggle_double();
        gdi_layer_get_buffer_ptr(&dest_ptr);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    #ifdef WIDGET_RESIDENT_STATUS_ICON
    	gdi_layer_set_clip(0, 0, GDI_LCD_WIDTH-1, MMI_title_height+MMI_STATUS_BAR_HEIGHT-1);
    #else
        gdi_layer_set_clip(0, 0, GDI_LCD_WIDTH-1, MMI_title_height-1);
    #endif
        memcpy(dest_ptr, src_ptr + buf_offset, buf_size);
        gdi_layer_pop_and_restore_active();

    	if (WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING ||
            WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD)
    	{
    	    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
    	}
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_video_gdi_layer
 * DESCRIPTION
 *  When we play the video, we need to prepare the gdi_layer for rendering the video.
 *  We allocate the memory from media task.
 * PARAMETERS
 *  size        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_get_video_gdi_layer(MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *image_ptr = NULL;
    kal_int32 buffer_size = 0;
    gdi_handle  base_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wgui_base_layer)
    {
        gdi_layer_get_base_handle(&wgui_base_layer);
    }
    /* 0. create the gdi_layer for title and status */
    if (WGUI_CTX->top_gdi_layer == 0)
    {
        gdi_layer_get_base_handle(&base_layer);
        gdi_layer_push_and_set_active(base_layer);
        image_ptr = (kal_uint8 *)mmi_frm_scrmem_alloc((TOP_GDI_LAYER_SIZE_IN_VIDEO>>2)<<3);
        ASSERT(image_ptr != NULL);
        gdi_layer_create_cf_double_using_outside_memory(
            gdi_act_layer->cf,  /* the color format of the gdi base layer */
            0,
            0,
            GDI_LCD_WIDTH,
            (TOP_GDI_LAYER_SIZE_IN_VIDEO/(GDI_LCD_WIDTH*((gdi_act_layer->bits_per_pixel)>>3))),
            &WGUI_CTX->top_gdi_layer,
            (PU8)image_ptr,
            (S32)(TOP_GDI_LAYER_SIZE_IN_VIDEO>>2)<<2,
            (PU8)image_ptr+((TOP_GDI_LAYER_SIZE_IN_VIDEO>>2)<<2),
            (S32)(TOP_GDI_LAYER_SIZE_IN_VIDEO>>2)<<2);
        WGUI_CTX->top_gdi_layer_buffer = image_ptr;
        gdi_layer_pop_and_restore_active();
        ASSERT(WGUI_CTX->top_gdi_layer != 0);

        gdi_layer_push_and_set_active(WGUI_CTX->top_gdi_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_set_opacity(FALSE, 255);
        gdi_layer_clear(GDI_COLOR_WHITE);
		gdi_layer_toggle_double();
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_set_opacity(FALSE, 255);
		gdi_layer_clear(GDI_COLOR_WHITE);
		gdi_layer_toggle_double();
        gdi_layer_pop_and_restore_active();
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GET_TOP_GDI_LAYER);
    }

    /* 1. check the gdi_layer size if the same with gadget_image size */
    if (WGUI_CTX->video_gdi_layer != 0)
    {
        kal_int32 video_width = 0, video_height = 0;

        gdi_layer_push_and_set_active(WGUI_CTX->video_gdi_layer);
        gdi_layer_get_dimension(&video_width, &video_height);
        gdi_layer_get_buffer_ptr(&image_ptr);
        gdi_layer_pop_and_restore_active();

        if ((video_width * video_height) < (size->width * size->height))
        {
            /* Trace2(TRACE_GROUP_2, "[G] widget_paint_gadget_image play video - free gdi_layer: %x ", WGUI_CTX->video_gdi_layer); */
            gdi_layer_free(WGUI_CTX->video_gdi_layer);
            WGUI_CTX->video_gdi_layer = 0;
            mmi_frm_scrmem_free((void*)image_ptr);
        }
    }

    /* 2. allocate the memory if gdi_layer doesn't exit */
    if (WGUI_CTX->video_gdi_layer == 0)
    {
        buffer_size = (size->width * size->height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
        buffer_size = ((buffer_size + 3) / 4) * 4;  /* the size should be 4 times */
        image_ptr = (kal_uint8*) mmi_frm_scrmem_alloc(buffer_size);
        if (image_ptr != NULL)
        {
            gdi_layer_create_using_outside_memory(
                0,
                0,
                size->width,
                size->height,
                &(WGUI_CTX->video_gdi_layer),
                (PU8) image_ptr,
                (S32) buffer_size);

            gdi_layer_push_and_set_active(WGUI_CTX->video_gdi_layer);
            gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
            gdi_layer_set_opacity(FALSE, 255);
            gdi_layer_pop_and_restore_active();

        }
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GET_VIDEO_GDI_LAYER);
    }   /* WGUI_CTX->video_gdi_layer==0 */
}



/*****************************************************************************
 * FUNCTION
 *  widget_free_video_gdi_layer
 * DESCRIPTION
 *  When changing the screen, we need to release the video resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARK
 *  It should be called in MMI thread
 *****************************************************************************/
void widget_free_video_gdi_layer(void)
{
    if (WGUI_CTX->video_gdi_layer != 0)
    {
        kal_uint8 *image_ptr = NULL;

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_FREE_VIDEO_GDI_LAYER);
        if (WGUI_CTX->top_gdi_layer != 0)
        {
            gdi_layer_push_and_set_active(WGUI_CTX->top_gdi_layer);
            gdi_layer_get_buffer_ptr(&image_ptr);
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(WGUI_CTX->top_gdi_layer);
            mmi_frm_scrmem_free((void*)WGUI_CTX->top_gdi_layer_buffer);
            WGUI_CTX->top_gdi_layer_buffer = NULL;
            WGUI_CTX->top_gdi_layer = 0;
            WGUI_CTX->top_gdi_layer_is_button_bar = 1;
        }

        gdi_layer_push_and_set_active(WGUI_CTX->video_gdi_layer);
        gdi_layer_get_buffer_ptr(&image_ptr);
        gdi_layer_pop_and_restore_active();

        gdi_layer_free(WGUI_CTX->video_gdi_layer);
        mmi_frm_scrmem_free((void*)image_ptr);

        WGUI_CTX->video_gdi_layer = 0;
        
        gdi_layer_set_blt_layer(wgui_base_layer, 0, 0, 0);
    }
}


#ifdef __MMI_VIDEO_PLAYER__

/*****************************************************************************
 * FUNCTION
 *  widget_MMI_play_video_gadget_finish_hdlr
 * DESCRIPTION
 *  The callback function when play the video finish.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_play_video_gadget_finish_hdlr(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show the preview image when play finish */
    gdi_layer_set_blt_layer(wgui_base_layer, 0, 0, 0);
    gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
    mdi_video_ply_stop();
    mdi_video_ply_seek_and_get_frame(0, WGUI_CTX->video_gdi_layer);
    mdi_video_ply_close_clip_file();

    gdi_layer_push_and_set_active(WGUI_CTX->video_gdi_layer);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();
    WGUI_CTX->current_video_state = WIDGET_VIDEO_STOP;

   /****************************************************************************
   * Reset proper state for stoping video
   *****************************************************************************/
    /* resume background audio */
    mdi_audio_resume_background_play();
    /* let MMI can sleep */
    TurnOffBacklight();

#ifdef __MMI_SUBLCD__
    widget_freeze_sub_lcd(MMI_FALSE);
#endif 
}

#endif /* __MMI_VIDEO_PLAYER__ */ /* #ifdef __MMI_VIDEO_PLAYER__ */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_prepare_play_vido_gadget
 * DESCRIPTION
 *  Prepare to play the video gadget
 * PARAMETERS
 *  gadget_img      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_prepare_play_vido_gadget(widget_gadget_image_struct *gadget_img)
{
#ifdef __MMI_VIDEO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *video_fname;
    MDI_RESULT mdi_ret;
    mdi_video_info_struct video_clip = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    widget_get_video_gdi_layer(&(gadget_img->size));
    if (WGUI_CTX->video_gdi_layer != 0)
    {
      /****************************************************************************
      * Init proper state for playing video
      *****************************************************************************/
        /* suspend background play */
        mdi_audio_suspend_background_play();
        /* stop lcd sleep */
        TurnOnBacklight(0);
    #ifdef __MMI_SUBLCD__
        /* gdi_lcd_freeze */
        widget_freeze_sub_lcd(MMI_TRUE);
    #endif /* __MMI_SUBLCD__ */ 

        gdi_layer_set_blt_layer(wgui_base_layer, WGUI_CTX->video_gdi_layer, WGUI_CTX->top_gdi_layer, 0);
        if (WGUI_CTX->current_video_state == WIDGET_VIDEO_READY_TO_PLAY)
        {
            video_fname = (char*)HDI_FileNameTranslate(widget_image_content_file(gadget_img->image));
            /* Because mdi_api is designed for MMI task, we need to call mdi_api in MMI thread */
            mdi_ret = mdi_video_ply_open_clip_file((const S8*)video_fname, &video_clip);
            if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PREPARE_PLAY_VIDEO_GADGET_FIRST_OPEN);
                mdi_video_ply_seek_and_get_frame(0, WGUI_CTX->video_gdi_layer);
                WGUI_CTX->current_video_state = WIDGET_VIDEO_PLAYING;
            }
            HDI_FileNameFree((kal_uint8*) video_fname);
        }
        else if (WGUI_CTX->current_video_state == WIDGET_VIDEO_OPENED_WAIT_PLAY)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PREPARE_PLAY_VIDEO_GADGET_DIRECTLY);
            /* draw the first frame of the video */
            WGUI_CTX->current_video_state = WIDGET_VIDEO_PLAYING;
        }

    }
#endif /* __MMI_VIDEO_PLAYER__ */ /* #ifdef __MMI_VIDEO_PLAYER__ */
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_play_video_gadget
 * DESCRIPTION
 *  Play the video gadget
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_play_video_gadget(void)
{
#ifdef __MMI_VIDEO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ALERT_TYPE alertType;
    BOOL palyAudio = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (WGUI_CTX->video_gdi_layer != 0)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PLAY_VIDEO_GADGET);

        gdi_layer_set_blt_layer(wgui_base_layer, WGUI_CTX->video_gdi_layer, WGUI_CTX->top_gdi_layer, 0);
        alertType = GetMtCallAlertTypeEnum();
        if ((alertType == MMI_VIBRATION_AND_RING || alertType == MMI_VIBRATION_THEN_RING || alertType == MMI_RING) &&
            (widget_check_no_call_or_wap_call()))
        {
            palyAudio = TRUE;
        }

        /* draw the first frame of the video */
        mdi_video_ply_enable_partial_display();
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, WSND_CTX->volume);
        mdi_video_ply_play(
            WGUI_CTX->video_gdi_layer,
            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2,   /* blt layer */
            GDI_LAYER_ENABLE_LAYER_1,   /* play_layer */
            1,                          /* repeat */
            TRUE,                      /* wait widget_paint to update video's visual */
            palyAudio,                  /* play aud or not */
            MDI_DEVICE_SPEAKER2,        /* audio path */
            MDI_VIDEO_LCD_ROTATE_0,     /* rotate */
            100,                        /* 1x play speed */
            widget_MMI_play_video_gadget_finish_hdlr);
    }
#endif /* __MMI_VIDEO_PLAYER__ */ /* #ifdef __MMI_VIDEO_PLAYER__ */
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_show_vido_gadget_preview
 * DESCRIPTION
 *  Display the video preview screen
 * PARAMETERS
 *  gadget_img      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_show_vido_gadget_preview(widget_gadget_image_struct *gadget_img)
{
#ifdef __MMI_VIDEO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *video_fname;
    MDI_RESULT mdi_ret;
    mdi_video_info_struct video_clip = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
    WAP_DBG_ASSERT(WGUI_CTX->current_video_state == WIDGET_VIDEO_PREVIEW);

    widget_get_video_gdi_layer(&(gadget_img->size));
    if (WGUI_CTX->video_gdi_layer != 0)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SHOW_VIDEO_GADGET_PREVIEW);
        gdi_layer_set_blt_layer(wgui_base_layer, WGUI_CTX->video_gdi_layer, WGUI_CTX->top_gdi_layer, 0);
        WAP_DBG_ASSERT(_IMG(gadget_img->image)->is_done);
        video_fname = (char*)HDI_FileNameTranslate(widget_image_content_file(gadget_img->image));
        /* Because mdi_api is designed for MMI task, we need to call mdi_api in MMI thread */
        mdi_ret = mdi_video_ply_open_clip_file((const S8*)video_fname, &video_clip);
        if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            /* draw the first frame of the video */
            /* Trace2(TRACE_GROUP_2, "[G] widget_MMI_show_vido_gadget_preview gadget_img:%x, gdi_layer: %x ", gadget_img, WGUI_CTX->video_gdi_layer); */
            mdi_video_ply_seek_and_get_frame(0, WGUI_CTX->video_gdi_layer);
            mdi_video_ply_close_clip_file();
        }
        HDI_FileNameFree((kal_uint8*) video_fname);
        
    }
#endif /* __MMI_VIDEO_PLAYER__ */ /* #ifdef __MMI_VIDEO_PLAYER__ */
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_in_playing_video
 * DESCRIPTION
 *  Check if playing the video in widget (MMS viewer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool widget_check_in_playing_video()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAYER__
    if (WGUI_CTX->current_video != NULL &&
        (WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING ||
         WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD))
    {
        return KAL_TRUE;
    }
    else
#endif /* #ifdef __MMI_VIDEO_PLAYER__ */
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_paint_gadget_image
 * DESCRIPTION
 *  Paint routine for image gadget
 *  Note: MSF_GADGET_PROPERTY_ALWAYSONTOP is not implemented
 * PARAMETERS
 *  gadget_img      [IN]        Image gadget
 *  size            [IN]        Dimension of drawn region
 *  pos             [IN]        Offset position of drawn region
 * RETURNS
 *  void
 *****************************************************************************/
void widget_paint_gadget_image(widget_gadget_image_struct *gadget_img, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* NOTE: gadget_image->image might be MsfPredefinedImage or MsfImage */
    if (!widget_gadget_in_form(size, &gadget_img->position, &gadget_img->size))
    {
        return;
    }

    // TODO: we can safely ignore the next line of code (pos != WGUI_CTX->display_pos if scrolled)
    gui_set_clip(pos->x, pos->y, pos->x + size->width - 1, pos->y + size->height - 1);

    /* Draw it */
    if (gadget_img->image && IS_IMAGE_TYPE(gadget_img->image) &&
        (MsfVideoFormat) (_IMG(gadget_img->image)->image_format) >= MsfVideoFormatStart)
    {
        int bound_x1, bound_x2, bound_y1, bound_y2;
        int clip_x1 = 0, clip_y1 = 0, clip_x2 = 0, clip_y2 = 0;

        /* 1 - full video in LCD, 2 - partial video at top LCD, 3 - partial video at bottom LCD, -1 - out LCD */
        int is_in_lcd = 1;
        static int prev_x = -1, prev_y = -1;

        clip_x1 = pos->x + gadget_img->position.x;
        clip_y1 = pos->y + gadget_img->position.y;
        clip_x2 = clip_x1 + gadget_img->size.width - 1;
        clip_y2 = clip_y1 + gadget_img->size.height - 1;

        widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);

        if (!widget_clipping_intersection
            (&clip_x1, &clip_y1, &clip_x2, &clip_y2, bound_x1, bound_y1, bound_x2, bound_y2))
        {
            is_in_lcd = -1;
        }

        widget_get_video_gdi_layer(&(gadget_img->size));
        /* prepare the gdi_layer for playing the video */

        /* draw video */
        if (WGUI_CTX->video_gdi_layer != 0)
        {
            int ox1, oy1, ox2, oy2; /* the offset in gdi_layer */
            int vid_x, vid_y;

            ox1 = clip_x1 - (pos->x + gadget_img->position.x);
            oy1 = clip_y1 - (pos->y + gadget_img->position.y);
            ox2 = clip_x2 - (pos->x + gadget_img->position.x - 1);
            oy2 = clip_y2 - (pos->y + gadget_img->position.y - 1);

            if (is_in_lcd > 0)
            {
                /* video is in display content region */
                if (((clip_y2 - clip_y1) < (gadget_img->size.height - 1)) && (clip_y1 == bound_y1))
                {
                    /* Display partial video at the top of LCD */
                    WGUI_CTX->top_gdi_layer_is_button_bar = 0;
                    if (WGUI_CTX->top_gdi_layer != 0)
                    {
                        widget_copy_title_from_base_layer(WGUI_CTX->top_gdi_layer);
                    }
                    is_in_lcd = 2;
                }
                else if (((clip_y2 - clip_y1) < (gadget_img->size.height - 1)) && (clip_y2 == bound_y2))
                {
                    /* Display partial video at the bottom of LCD */
                    WGUI_CTX->top_gdi_layer_is_button_bar = 1;
                    if (WGUI_CTX->top_gdi_layer != 0)
                    {
                        widget_copy_bar_from_base_layer(WGUI_CTX->top_gdi_layer);
                    }
                    is_in_lcd = 3;
                }

                vid_x = pos->x + gadget_img->position.x;
                vid_y = pos->y + gadget_img->position.y;
            }
            else
            {
                /* video is out of display content region completely */
                vid_x = GDI_LCD_WIDTH;
                vid_y = GDI_LCD_HEIGHT;
            }

            if ((WGUI_CTX->current_video_state == WIDGET_VIDEO_READY_TO_PLAY) ||
                (WGUI_CTX->current_video_state == WIDGET_VIDEO_PREVIEW) ||
                ((WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING || WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD) && 
                 (prev_x != vid_x || prev_y != vid_y)))
            {
                /* If play the new video or the video's coordinate changed, we oparate the video */
                prev_x = vid_x;
                prev_y = vid_y;

                if (WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING ||
                    WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD)
                {
                    /* 
                     * When scrolling SIML, we should stop video first, set the 
                     * new gdi_layer coordination and then play it.
                     */
                #ifdef __MMI_VIDEO_PLAYER__
                    mdi_video_ply_stop();
                #endif 
                    WGUI_CTX->current_video_state = WIDGET_VIDEO_OPENED_WAIT_PLAY;
                }

                /* video gdi layer is in the LCD region */
                gdi_layer_push_and_set_active(WGUI_CTX->video_gdi_layer);
                gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
                gdi_layer_set_opacity(FALSE, 255);
                gdi_layer_set_position(vid_x, vid_y);
                gui_set_clip(ox1, oy1, ox2, oy2);
                gdi_layer_pop_and_restore_active();

                if (_IMG(gadget_img->image)->video_in_preview == 1)
                {
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_VIDEO_GADGET_IN_PREVIEW);
                    /* 
                     * current_video_state == WIDGET_VIDEO_FILE_ALREADY_CHECKED
                     * draw the first frame of the video 
                     */
                    widget_MMI_show_vido_gadget_preview(_GIMG(gadget_img));
                    if (is_in_lcd < 0)
                    {
                        gdi_layer_set_blt_layer(wgui_base_layer, WGUI_CTX->video_gdi_layer, 0, 0);
                    }
                }
                else if (_IMG(gadget_img->image)->video_in_preview == 0)
                {
                    if (WGUI_CTX->current_video_state == WIDGET_VIDEO_READY_TO_PLAY ||
                        WGUI_CTX->current_video_state == WIDGET_VIDEO_OPENED_WAIT_PLAY)
                    {
                        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAINT_VIDEO_GADGET_PLAY_VIDEO);
                        /* adjust the position of the gdi_layer */
                        widget_MMI_prepare_play_vido_gadget(_GIMG(gadget_img));
                    }

                    /* update the current_video_state again */
                    if (is_in_lcd > 0)
                    {
                        /* video is in display content region */
                        WGUI_CTX->current_video_state = WIDGET_VIDEO_PLAYING;
                    }
                    else    /* if (is_in_lcd < 0) */
                    {
                        /* video is out of display content region completely */
                        WGUI_CTX->current_video_state = WIDGET_VIDEO_PLAYING_OUT_OF_LCD;
                        gdi_layer_set_blt_layer(wgui_base_layer, 0, 0, 0);
                    }
                }   /* end - (_IMG(gadget_img->image)->video_in_preview==1) */
                gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
            }       /* end - ((prev_x != vid_x) && (prev_y != vid_y)) */

        }   /* end - (WGUI_CTX->video_gdi_layer!=0) */
    }
    else
    {
        /* draw image */
        if (gadget_img->image && IS_IMAGE_TYPE(gadget_img->image) && _IMG(gadget_img->image)->draw_op_head)
        {
            if (gadget_img->marquee)
            {
                _IMG(gadget_img->image)->is_in_drawing_marquee = 1;
                widget_setup_marquee(gadget_img);
            }
            else
            {
                widget_draw_queued_operation_from_gadget_image(gadget_img, KAL_FALSE, KAL_FALSE, 0, 0);
            }
        }
        else
        {
            _IMG(gadget_img->image)->is_in_drawing_marquee = 0;
            widget_show_animate_image(pos->x + gadget_img->position.x, pos->y + gadget_img->position.y, gadget_img);
        }
    }

    /* Record drawn region and draw border */
    if (WGUI_CTX->in_paintbox)
    {
        /* Maybe the following code can be removed */
        widget_register_keyfocus(_H(gadget_img));
    }
    else
    {
        kal_bool is_want_focus = widget_form_gadget_want_focus(_H(gadget_img));
        kal_bool is_key_focus = is_want_focus ? widget_register_keyfocus(_H(gadget_img)) : KAL_FALSE;

        widget_record_used_range(
            _H(gadget_img),
            is_want_focus,
            is_key_focus,
            pos->x + gadget_img->position.x,
            pos->y + gadget_img->position.y,
            pos->x + gadget_img->position.x + gadget_img->size.width,
            pos->y + gadget_img->position.y + gadget_img->size.height);

        if (is_key_focus)
        {
            if (gadget_img->border_size.width > 0 && gadget_img->border_size.height > 0)
            {
                widget_form_draw_border(
                    _H(gadget_img),
                    gadget_img->position.x + gadget_img->border_offset.x + pos->x,
                    gadget_img->position.y + gadget_img->border_offset.y + pos->y,
                    gadget_img->position.x + gadget_img->border_offset.x + pos->x + gadget_img->border_size.width - 1,
                    gadget_img->position.y + gadget_img->border_offset.y + pos->y + gadget_img->border_size.height - 1);
            }
            else
            {
                widget_form_draw_border(
                    _H(gadget_img),
                    gadget_img->position.x + pos->x,
                    gadget_img->position.y + pos->y,
                    gadget_img->position.x + pos->x + gadget_img->size.width - 1,
                    gadget_img->position.y + pos->y + gadget_img->size.height - 1);
            }
        }
    }
}

/****************************************************************
 *
 *  Marquee
 * (Reference: Blinking text)
 *
 ***************************************************************/

/* Declaration of local functions for marquee */
static kal_bool widget_enqueue_marquee(widget_gadget_image_struct *gimg);
static kal_bool widget_dequeue_marquee(widget_gadget_image_struct *gimg);
static kal_bool widget_has_marquee_displayed(void);
static void widget_MMI_paint_marquee_hdlr(void);
static void widget_paint_marquee_hdlr(void *arg);
static void widget_start_marquee_animation(void);
static void widget_stop_marquee_animation(void);

/* En-queue to WGUI_CTX->marquee_head */


/*****************************************************************************
 * FUNCTION
 *  widget_enqueue_marquee
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gimg        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_enqueue_marquee(widget_gadget_image_struct *gimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We need to check the existence first */
    curr = WGUI_CTX->marquee_head;
    while (curr)
    {
        if (curr == gimg)
        {
            return KAL_FALSE;
        }
        curr = curr->marquee_next;
    }

    /* Insert it */
    WAP_DBG_ASSERT(gimg->marquee_next == NULL);
    gimg->marquee_next = WGUI_CTX->marquee_head;
    WGUI_CTX->marquee_head = gimg;
    return KAL_TRUE;
}

/* De-queue from WGUI_CTX->marquee_head */


/*****************************************************************************
 * FUNCTION
 *  widget_dequeue_marquee
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gimg        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_dequeue_marquee(widget_gadget_image_struct *gimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *curr, *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(gimg);

    if (WGUI_CTX->marquee_head == gimg)
    {
        WGUI_CTX->marquee_head = gimg->marquee_next;
        gimg->marquee_next = NULL;
        return KAL_TRUE;
    }

    prev = WGUI_CTX->marquee_head;
    curr = prev->marquee_next;

    while (curr)
    {
        if (curr == gimg)
        {
            prev->marquee_next = gimg->marquee_next;
            gimg->marquee_next = NULL;
            return KAL_TRUE;
        }
        prev = curr;
        curr = curr->marquee_next;
    }

    return KAL_FALSE;
}

/* Is there any marquee objects animated? */


/*****************************************************************************
 * FUNCTION
 *  widget_has_marquee_displayed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_has_marquee_displayed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *curr = WGUI_CTX->marquee_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr)
    {
        ASSERT(curr->marquee);
        if (curr->marquee->displayed && curr->marquee->enabled)
        {
            return KAL_TRUE;
        }

        curr = curr->marquee_next;
    }
    return KAL_FALSE;
}

/* Paint a marquee object in MMI task */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_marquee_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gimg                    [IN]         
 *  marquee                 [IN]         
 *  erase_background        [IN]        
 *  do_BLT                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_paint_marquee_object(
                widget_gadget_image_struct *gimg,
                widget_marquee_struct *marquee,
                kal_bool erase_background,
                kal_bool do_BLT)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool loop_finished = KAL_FALSE;
    kal_int16 cwidth, swidth;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(IS_GADGET_IMAGE_TYPE(gimg));

    cwidth = 0;
    if (gimg->image)
    {
        cwidth = (kal_int16) _IMG(gimg->image)->draw_op_content_size.width;
    }
#if 0   /* workaround for previous BRS bug */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
    swidth = gimg->size.width;
#endif /* 0 */ 

    if (!marquee->enabled || marquee->marqueeType == MsfMarqueeNone)
    {
        /* Otherwise, marqueeing image is not clipped well */
        if (marquee->x_offset > -cwidth && marquee->x_offset < swidth)
        {
            widget_draw_queued_operation_from_gadget_image(
                gimg,
                erase_background,
                do_BLT,
                marquee->x_offset,
                marquee->y_offset);
        }
        else if (erase_background)  /* Clear background for scroll marquee */
        {
            widget_gadget_clear_background(_W(gimg), do_BLT);
        }
        return;
    }

    /* Here marquee->enabled == TRUE. Animating... 
       Check delay time */
    marquee->elapsed_time += WIDGET_MARQUEE_DELAY_TIME;
    if (marquee->elapsed_time < marquee->scrollDelay)
    {
        return;
    }

    if (marquee->is_new_loop)
    {
        marquee->is_new_loop = KAL_FALSE;
        marquee->curr_direction = marquee->direction;

        switch (marquee->marqueeType)
        {
            case MsfMarqueeScroll:
                if (marquee->direction) /* Right to left */
                {
                    marquee->x_offset = swidth;
                }
                else
                {
                    marquee->x_offset = -cwidth;
                }
                break;
            case MsfMarqueeSlide:
                if (marquee->direction) /* Right to left */
                {
                    marquee->x_offset = swidth;
                }
                else
                {
                    marquee->x_offset = -cwidth;
                }
                break;
            case MsfMarqueeInsideScroll:
                WAP_DBG_ASSERT(0);
                /* FALLTHROUGH no break */
            case MsfMarqueeAlternate:
                if (cwidth < swidth)
                {
                    if (marquee->direction) /* Right to left */
                    {
                        marquee->x_offset = swidth - cwidth - 1;
                    }
                    else
                    {
                        marquee->x_offset = 0;
                    }
                }
                else
                {
                    if (marquee->direction) /* Right to left */
                    {
                        marquee->x_offset = 0;
                    }
                    else
                    {
                        marquee->x_offset = swidth - cwidth - 1;
                    }
                }
                break;
            default:
                WAP_DBG_ASSERT(0);
                return;
        }
    }
    else
    {
        int step;
        int round = marquee->elapsed_time / marquee->scrollDelay;

        WAP_DBG_ASSERT(round > 0);

        marquee->elapsed_time %= marquee->scrollDelay;

        if (marquee->curr_direction)
        {
            step = -1;
        }
        else
        {
            step = 1;
        }
        step = step * marquee->scrollAmount * round;

        marquee->x_offset += step;

        /* Check upper bound and whether the loop is finished */
        switch (marquee->marqueeType)
        {
            case MsfMarqueeScroll:
                if (marquee->direction) /* Right to left */
                {
                    if (marquee->x_offset <= -cwidth)
                    {
                        loop_finished = KAL_TRUE;
                    }
                }
                else
                {
                    if (marquee->x_offset >= swidth)
                    {
                        loop_finished = KAL_TRUE;
                    }
                }
                break;
            case MsfMarqueeSlide:
                if (cwidth < swidth)
                {
                    if (marquee->direction) /* Right to left */
                    {
                        if (marquee->x_offset <= 0)
                        {
                            marquee->x_offset = 0;
                            loop_finished = KAL_TRUE;
                        }
                    }
                    else
                    {
                        if (marquee->x_offset + cwidth >= swidth - 1)
                        {
                            marquee->x_offset = swidth - cwidth - 1;
                            loop_finished = KAL_TRUE;
                        }
                    }
                }
                else    /* cwidth >= swidth */
                {
                    if (marquee->direction) /* Right to left */
                    {
                        if (marquee->x_offset + cwidth <= swidth - 1)
                        {
                            marquee->x_offset = swidth - cwidth - 1;    /* negative */
                            loop_finished = KAL_TRUE;
                        }
                    }
                    else
                    {
                        if (marquee->x_offset >= 0)
                        {
                            marquee->x_offset = 0;
                            loop_finished = KAL_TRUE;
                        }
                    }
                }
                break;
            case MsfMarqueeInsideScroll:    /* FALLTHROUGH no break */
                WAP_DBG_ASSERT(0);
            case MsfMarqueeAlternate:
                if (cwidth < swidth)
                {
                    if (marquee->curr_direction)    /* Right to left */
                    {
                        if (marquee->x_offset <= 0)
                        {
                            marquee->x_offset = 0;
                            goto next_alternate;
                        }
                    }
                    else
                    {
                        if (marquee->x_offset + cwidth >= swidth - 1)
                        {
                            marquee->x_offset = swidth - cwidth - 1;
                            goto next_alternate;
                        }
                    }
                }
                else    /* cwidth >= swidth */
                {
                    if (marquee->curr_direction)    /* Right to left */
                    {
                        if (marquee->x_offset + cwidth <= swidth - 1)
                        {
                            marquee->x_offset = swidth - cwidth - 1;    /* negative */
                            goto next_alternate;
                        }
                    }
                    else
                    {
                        if (marquee->x_offset >= 0)
                        {
                            marquee->x_offset = 0;
                            goto next_alternate;
                        }
                    }
                }
                break;

              next_alternate:
                if (marquee->curr_direction == marquee->direction)
                {
                    marquee->curr_direction = !marquee->curr_direction;
                }
                else
                {
                    loop_finished = KAL_TRUE;
                }
                break;

            default:
                WAP_DBG_ASSERT(0);
                loop_finished = KAL_TRUE;
                break;
        }
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_MARQUEE_OBJECT, marquee->x_offset);

    /* Draw it */
    if (marquee->x_offset > -cwidth && marquee->x_offset < swidth)      /* Otherwise, marqueeing image is not clipped well */
    {
        widget_draw_queued_operation_from_gadget_image(
            gimg,
            erase_background,
            do_BLT,
            marquee->x_offset,
            marquee->y_offset);
    }
    else if (erase_background)  /* Clear background for scroll marquee */
    {
        widget_gadget_clear_background(_W(gimg), do_BLT);
    }

    if (loop_finished)
    {
        marquee->is_new_loop = KAL_TRUE;
        marquee->loop_count++;

        if (marquee->repeat && marquee->loop_count >= marquee->repeat)
        {
            marquee->enabled = KAL_FALSE;
            if (marquee->x_offset + cwidth <= 0 ||
                marquee->x_offset + cwidth > WGUI_CTX->display_size.width)
            {
                /* When the marquee content is out of screen, we set it */
                marquee->x_offset = marquee->y_offset = 0;
            }
            widget_notify(_H(gimg), MsfNotifyMarqueeDone);
        }
    }
}

/* Timer handler of marquee text animation executed in MMI task */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_paint_marquee_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_paint_marquee_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *gimg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_has_marquee_displayed())
    {
        return;
    }
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_PAINT_MARQUEE_HDLR);

    gimg = WGUI_CTX->marquee_head;
    while (gimg)
    {
        ASSERT(gimg->marquee);
        WAP_DBG_ASSERT(IS_GADGET_IMAGE_TYPE(gimg));

        /* Paint it */
        if (gimg->marquee->displayed && gimg->marquee->enabled)
        {
            widget_MMI_paint_marquee_object(gimg, gimg->marquee, KAL_TRUE, KAL_TRUE);
            if (!gimg->marquee->enabled)
            {
                /* Paint again to display the content when loop count finished, 
                   it is required in the conformance test. */
                widget_MMI_paint_marquee_object(gimg, gimg->marquee, KAL_TRUE, KAL_TRUE);
            }
        }

        gimg = gimg->marquee_next;
    }

    if (widget_has_marquee_displayed()) /* Otherwise, max loop count reached */
    {
        widget_start_marquee_animation();
    }
}

/* Timer handler of marquee text animation */


/*****************************************************************************
 * FUNCTION
 *  widget_paint_marquee_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_paint_marquee_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_has_marquee_displayed())
    {
        return;
    }
    if (!WGUI_CTX->is_widget_screen)
    {
        return;
    }

    widget_execute_MMI(widget_MMI_paint_marquee_hdlr, KAL_TRUE);
}

/* Start marquee timer */


/*****************************************************************************
 * FUNCTION
 *  widget_start_marquee_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_start_marquee_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!widget_has_marquee_displayed())
    {
        return;
    }

    widget_start_timer(WIDGET_MARQUEE_TIMER, widget_paint_marquee_hdlr, NULL, WIDGET_MARQUEE_DELAY_TIME);
}

/* Stop marquee timer */


/*****************************************************************************
 * FUNCTION
 *  widget_stop_marquee_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_stop_marquee_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_stop_timer(WIDGET_MARQUEE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  widget_setup_marquee
 * DESCRIPTION
 *  Enable marquee of an image gadget and start marquee timer
 *  (typically invoked from widget_paint)
 * PARAMETERS
 *  gimg        [IN]        Image gadget to setup marquee
 * RETURNS
 *  void
 *****************************************************************************/
void widget_setup_marquee(widget_gadget_image_struct *gimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(gimg->marquee);
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    gimg->marquee->displayed = 1;

    if (!gimg->marquee->enabled)    /* No animation. Draw it directly */
    {
        widget_MMI_paint_marquee_object(gimg, gimg->marquee, KAL_FALSE, KAL_FALSE);
    }
    else
    {
        widget_start_marquee_animation();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_all_marquee
 * DESCRIPTION
 *  Stop all marquee text when repaint or exit widget screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_all_marquee(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *curr = WGUI_CTX->marquee_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr)
    {
        ASSERT(curr->marquee);
        curr->marquee->displayed = 0;
        curr = curr->marquee_next;
    }

    WAP_DBG_ASSERT(!widget_has_marquee_displayed());    /* Be paranoid */
    widget_stop_marquee_animation();
}


/*****************************************************************************
 * FUNCTION
 *  widget_remove_marquee
 * DESCRIPTION
 *  Remove marquee information on deleting an image gadget
 * PARAMETERS
 *  gimg        [IN]        Image gadget to be released
 * RETURNS
 *  void
 *****************************************************************************/
void widget_remove_marquee(widget_gadget_image_struct *gimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gimg->marquee)
    {
        kal_bool res;

        res = widget_dequeue_marquee(gimg);
        WAP_DBG_ASSERT(res);

        MSF_MEM_FREE(MSF_MODID_WIDGET, gimg->marquee);
        gimg->marquee = NULL;

        if (!widget_has_marquee_displayed())
        {
            widget_stop_marquee_animation();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetMarquee
 * DESCRIPTION
 *  Standard Widget API
 *****************************************************************************/
int HDIa_widgetSetMarquee(
        MSF_UINT32 handle,
        MsfMarqueeType marqueeType,
        int direction,
        int repeat,
        int scrollAmount,
        int scrollDelay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gadget_image_struct *gimg;
    kal_bool res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_GADGET_IMAGE_TYPE(handle))
    {
        /* We only support Marquee on MsfGadgetImage */
        WAP_DBG_ASSERT(0);
        return 0;
    }

    gimg = _GIMG(handle);

    widget_remove_marquee(gimg);

    if (marqueeType == MsfMarqueeNone)
    {
        return 1;
    }

    switch (marqueeType)
    {
        case MsfMarqueeScroll:
        case MsfMarqueeInsideScroll:
        case MsfMarqueeSlide:
        case MsfMarqueeAlternate:
            break;
        default:
            WAP_DBG_ASSERT(0);
            return 0;
    }

    gimg->marquee = (widget_marquee_struct*) MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_marquee_struct));
    memset(gimg->marquee, 0, sizeof(widget_marquee_struct));

    gimg->marquee->marqueeType = marqueeType;
    gimg->marquee->direction = direction;
    gimg->marquee->repeat = repeat;
    gimg->marquee->scrollAmount = scrollAmount;
    gimg->marquee->scrollDelay = scrollDelay ? scrollDelay : (50) /* 0.05 sec */ ;
    /* internal data */
    gimg->marquee->displayed = 0;
    gimg->marquee->enabled = KAL_TRUE;
    gimg->marquee->is_new_loop = KAL_TRUE;
    gimg->marquee->curr_direction = 0;
    gimg->marquee->loop_count = 0;
    gimg->marquee->x_offset = 0;
    gimg->marquee->y_offset = 0;
    gimg->marquee->elapsed_time = 0;
    res = widget_enqueue_marquee(gimg);
    ASSERT(res);

    /* widget_paint will start animation */

    return 1;
}

/****************************************************************
 *
 * Precache Image in layer memory
 *
 * Note: we delay the creation of GDI layer until displaying images because
 * we do not know image dimension in advance.
 *
 ****************************************************************/

// TODO: Re-test WAP out-of-memory with cached image

#if defined(WIDGET_PRECACHE_IMAGE)

#if defined(WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING)
extern U8 g_widget_image_cache_buf[];
#endif /* WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING */

/* Reset global context related to target precached image */

/*****************************************************************************
 * FUNCTION
 *  widget_precache_image_reset_image_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_precache_image_reset_image_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WPCACHE_CTX->cached_image = NULL;
    WPCACHE_CTX->height = 0;
    WPCACHE_CTX->width = 0;
    WPCACHE_CTX->zoom = MsfImageZoom100;
}

/* Reset global context related to GDI layer */


/*****************************************************************************
 * FUNCTION
 *  widget_precache_image_reset_layer_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_precache_image_reset_layer_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WPCACHE_CTX->layer_enabled = 0;
    WPCACHE_CTX->layer_created = 0;
    WPCACHE_CTX->base_layer = GDI_LAYER_EMPTY_HANDLE;

    if (WPCACHE_CTX->cache_layer != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(WPCACHE_CTX->cache_layer);
    }
    WPCACHE_CTX->cache_layer = GDI_LAYER_EMPTY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_precache_image
 * DESCRIPTION
 *  Initialization of precached image data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_precache_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Layer context must stay unchanged after WAP reset due to out-of-memory */
    if (!WPCACHE_CTX->initialized)
    {
        WPCACHE_CTX->initialized = 1;
        widget_precache_image_reset_layer_data();
    }
    widget_precache_image_reset_image_data();

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
	WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
    memset(g_widget_nb_image_array, 0, sizeof(widget_nb_image_struct)*WIDGET_MAX_NB_DRAW_IMAGE_NUM);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_precache_image
 * DESCRIPTION
 *  De-initialization of precached image data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_precache_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * We do not  invoke gdi_layer function because it is not MMI task. 
     * * Instead, we let screen management functions to handle it.
     */
    widget_precache_image_reset_image_data();
	WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_free_precached_image_if_any
 * DESCRIPTION
 *  Free all precached image and release GDI layer (typically on leaving widget screen)
 *  It should be invoked in MMI task because it manipulates GDI layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_free_precached_image_if_any(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (WPCACHE_CTX->layer_enabled)
    {
        WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen);     // TODO: Fix a bug in widget_init() that might clear WGUI_CTX->is_widget_screen
        if (WPCACHE_CTX->cache_layer != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(WPCACHE_CTX->cache_layer);
			WPCACHE_CTX->cache_layer = GDI_LAYER_EMPTY_HANDLE;
        }
        gdi_layer_multi_layer_disable();
        widget_precache_image_reset_layer_data();
    }
#ifndef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
	/* If enable non-blocking drawing, we don't reset image data in cache */
    widget_precache_image_reset_image_data();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  widget_precache_image_reset_all
 * DESCRIPTION
 *  Reset context of precached image data
 *  (typically on entering widget screen from MMI screens)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_precache_image_reset_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_precache_image_reset_image_data();
    widget_precache_image_reset_layer_data();
}


/*****************************************************************************
 * FUNCTION
 *  widget_reset_precached_image_by_image
 * DESCRIPTION
 *  Reset context of precached image data related to target image (typically on releasing MsfImage object)
 *  Note that it does not reset layer data and we delayed  releasing of GDI layer later in MMI task.
 * PARAMETERS
 *  img     [IN]        The MsfImage to be released
 * RETURNS
 *  void
 *****************************************************************************/
void widget_reset_precached_image_by_image(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img == WPCACHE_CTX->cached_image)
    {
        widget_precache_image_reset_image_data();
		WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_prepare_precache_image
 * DESCRIPTION
 *  Setup new GDI layer and set as active layer.
 *  
 *  It should be paired with widget_MMI_finish_precache_image()
 * PARAMETERS
 *  img         [IN]        The target image to cache
 *  width       [IN]        Width of the image
 *  height      [IN]        Height of the image
 *  zoom        [IN]        Zoom type of the image to cache (only used to check if the cache is valid later)
 * RETURNS
 *  whether the operation succeeded
 *****************************************************************************/
kal_bool widget_MMI_prepare_precache_image(
            widget_image_struct *img,
            MSF_UINT16 width,
            MSF_UINT16 height,
            MsfImageZoom zoom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
/*	Trace2(TRACE_GROUP_2, "[Widget] widget_MMI_prepare_precache_image [precache_nb_image_state:%d, img:(%d, %d), h:(%d, %d), w:(%d, %d), zoom:(%d, %d)",
		WGUI_CTX->precache_nb_image_state, WPCACHE_CTX->cached_image, img, WPCACHE_CTX->height, height, WPCACHE_CTX->width, width, \WPCACHE_CTX->zoom, zoom); */

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
	if (!WGUI_CTX->is_widget_screen &&
		WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_START &&
        WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_NO_NEED &&
		WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_PROCESSING)
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

	if (WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_PROCESSING &&
		(WPCACHE_CTX->cached_image != img ||
		WPCACHE_CTX->height != height ||
		WPCACHE_CTX->width != width ||
		WPCACHE_CTX->zoom != zoom))
	{
		return KAL_FALSE;
	}

#else		
    if (!WGUI_CTX->is_widget_screen)
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }
#endif

#if defined(__GDI_MEMORY_PROFILE_2__) || defined(WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING)
    /* Layer memory has no pixel padding. We can simply multiple width and height to get data size */
    if ((kal_uint32) width * height > (kal_uint32) GDI_LCD_WIDTH * GDI_LCD_HEIGHT)
    {
        /* We should prevent draw an image too large */
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }
#else /* __GDI_MEMORY_PROFILE_2__ || __MMI_NONBLOCKING_DECODE__ */ 
    WAP_DBG_ASSERT(0);  /* We expect at least two layer support for MMS */
    return KAL_FALSE;
#endif /* __GDI_MEMORY_PROFILE_2__ || __MMI_NONBLOCKING_DECODE__ */ 

    if (width == 0 || height == 0)
    {
        return KAL_FALSE;
    }

//	Trace2(TRACE_GROUP_2, "[Widget] widget_MMI_prepare_precache_image (processing)");

    widget_precache_image_reset_image_data();

    /* Enable multi-layer */
    if (!WPCACHE_CTX->layer_enabled)
    {
        gdi_layer_multi_layer_enable();
        gdi_layer_get_base_handle(&WPCACHE_CTX->base_layer);

        WPCACHE_CTX->layer_enabled = 1;
        WPCACHE_CTX->layer_created = 0;
    }

    /* Remove previous layer */
    if (WPCACHE_CTX->layer_created)
    {
        WAP_DBG_ASSERT(WPCACHE_CTX->cache_layer != GDI_LAYER_EMPTY_HANDLE);
        if (WPCACHE_CTX->cache_layer != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(WPCACHE_CTX->cache_layer);
        }
    }
    else
    {
        WAP_DBG_ASSERT(WPCACHE_CTX->cache_layer == GDI_LAYER_EMPTY_HANDLE);
    }

    /* Create new layer */
#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    gdi_layer_create_using_outside_memory(
            0,
            0,
            width,
            height,
            &WPCACHE_CTX->cache_layer,
            (PU8)g_widget_image_cache_buf,
            (S32)width*height*GDI_MAINLCD_BIT_PER_PIXEL>>3);//GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL>>3);

//    Trace2(WIDGET_LOG_GROUP, "[Widget] widget_MMI_prepare_precache_image create gdi layer\n");

#else
	#ifdef __GDI_MEMORY_PROFILE_2__
		gdi_layer_create(0, 0, width, height, &WPCACHE_CTX->cache_layer);
	#else
		#error "We don't support WIDGET_PRECACHE_IMAGE in GDI_MEMORY_PROFILE_1"
	#endif
#endif

    gdi_layer_push_and_set_active(WPCACHE_CTX->cache_layer);
    WPCACHE_CTX->layer_created = 1;

    /* Fill white (quick fix for resized image) */
    gdi_draw_solid_rect(0, 0, width - 1, height - 1, gdi_act_color_from_rgb(0xff, 255, 255, 255));

    /* Setup image data */
    WPCACHE_CTX->cached_image = img;
    WPCACHE_CTX->height = height;
    WPCACHE_CTX->width = width;
    WPCACHE_CTX->zoom = zoom;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_finish_precache_image
 * DESCRIPTION
 *  Restore the active layer after the precached image is drawn
 *  
 *  It should be paired with widget_MMI_prepare_precache_image()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_finish_precache_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
	if (!WGUI_CTX->is_widget_screen &&
		WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_START &&
        WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_NO_NEED &&
		WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_PROCESSING)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
#else		
    if (!WGUI_CTX->is_widget_screen)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
#endif

    if (!WPCACHE_CTX->layer_enabled || !WPCACHE_CTX->layer_created)
    {
        WAP_DBG_ASSERT(0);
        return;
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_is_precached
 * DESCRIPTION
 *  Check whether the image is cached in GDI layer memory
 * PARAMETERS
 *  img         [IN]        The target MsfImage
 *  width       [IN]        Width of the image
 *  height      [IN]        Height of the image
 *  zoom        [IN]        The current zooming type of this image
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_image_is_precached(widget_image_struct *img, MSF_UINT16 width, MSF_UINT16 height, MsfImageZoom zoom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(img);
/*	Trace2(TRACE_GROUP_2, "[Widget] widget_image_is_precached [precache_nb_image_state:%d, img:(%d, %d), h:(%d, %d), w:(%d, %d), zoom:(%d, %d)",
		WGUI_CTX->precache_nb_image_state, WPCACHE_CTX->cached_image, img, WPCACHE_CTX->height, height, WPCACHE_CTX->width, width, WPCACHE_CTX->zoom, zoom); */

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
	if ((!WPCACHE_CTX->layer_enabled || !WPCACHE_CTX->layer_created) &&
		(img != WPCACHE_CTX->cached_image && WGUI_CTX->precache_nb_image_state != WIDGET_PRECACHE_NB_IMAEG_DONE))
	{
		return KAL_FALSE;
	}
#else
    if (!WPCACHE_CTX->layer_enabled || !WPCACHE_CTX->layer_created)
    {
        return KAL_FALSE;
    }
#endif


    if (img && img == WPCACHE_CTX->cached_image &&
        width == WPCACHE_CTX->width && height == WPCACHE_CTX->height && zoom == WPCACHE_CTX->zoom)
    {
	#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
		if ((WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_NONE ||
             WGUI_CTX->precache_nb_image_state == WIDGET_PRECACHE_NB_IMAEG_DONE)
			&& !WPCACHE_CTX->layer_enabled && WPCACHE_CTX->cached_image)
		{
			/* Enable multi-layer */
			if (!WPCACHE_CTX->layer_enabled)
			{
				gdi_layer_multi_layer_enable();
				gdi_layer_get_base_handle(&WPCACHE_CTX->base_layer);

				WPCACHE_CTX->layer_enabled = 1;
				WPCACHE_CTX->layer_created = 0;
			}
			gdi_layer_create_using_outside_memory(
					0,
					0,
					width,
					height,
					&WPCACHE_CTX->cache_layer,
					(PU8)g_widget_image_cache_buf,
					(S32)width*height*GDI_MAINLCD_BIT_PER_PIXEL>>3);//(S32)GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL>>3);
			WPCACHE_CTX->layer_created = 1;
		}

	#endif

        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_show_precached_image
 * DESCRIPTION
 *  Redraw the precached image from GDI layer memory
 * PARAMETERS
 *  offset_x                        [IN]        X-axis position to draw the image
 *  offset_y                        [IN]        Y-axis position to draw the image
 *  clipping_to_content_size        [IN]        Clipping to content region (without title, softkey and scrollbar)
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_show_precached_image(int offset_x, int offset_y, kal_bool clipping_to_content_size)
{
#ifdef WIDGET_USE_LAYER_FLATTEN_WITH_CLIPPING
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int clip_x1, clip_y1, clip_x2, clip_y2;
    gdi_handle base_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clip_x1 = offset_x;
    clip_y1 = offset_y;
    clip_x2 = offset_x + WPCACHE_CTX->width - 1;
    clip_y2 = offset_y + WPCACHE_CTX->height - 1;
    if (clipping_to_content_size)
    {
        int bound_x1, bound_x2, bound_y1, bound_y2;

        widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);

        if (!widget_clipping_intersection
            (&clip_x1, &clip_y1, &clip_x2, &clip_y2, bound_x1, bound_y1, bound_x2, bound_y2))
        {
            return; /* Image out of content region */
        }
    }

    gdi_layer_get_base_handle(&base_layer);

    gdi_layer_push_and_set_active(WPCACHE_CTX->cache_layer);
    gdi_layer_set_position(offset_x, offset_y);
    gdi_layer_pop_and_restore_active();

    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    gdi_layer_flatten_with_clipping(base_layer, WPCACHE_CTX->cache_layer, 0, 0);

    gui_pop_clip();

#else /* WIDGET_USE_LAYER_FLATTEN_WITH_CLIPPING */ 
    int clip_x1, clip_y1, clip_x2, clip_y2;
    int x, y, y_multiple;
    U16 *cached_buffer;

    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());
//    Trace2(TRACE_GROUP_2, "[Widget] widget_MMI_show_precached_image <checking>");
    if (!WPCACHE_CTX->layer_enabled || !WPCACHE_CTX->layer_created ||
        WPCACHE_CTX->cache_layer == GDI_LAYER_EMPTY_HANDLE)
    {
        WAP_DBG_ASSERT(0);
        return;
    }
//    Trace2(TRACE_GROUP_2, "[Widget] widget_MMI_show_precached_image <processing>");

    gdi_layer_push_and_set_active(WPCACHE_CTX->cache_layer);

    gdi_layer_get_buffer_ptr((U8 **) & cached_buffer);

    gdi_layer_pop_and_restore_active();

    /* Set clip to the image dimension */
    clip_x1 = offset_x;
    clip_y1 = offset_y;
    clip_x2 = offset_x + WPCACHE_CTX->width - 1;
    clip_y2 = offset_y + WPCACHE_CTX->height - 1;

    if (clipping_to_content_size)
    {
        int bound_x1, bound_x2, bound_y1, bound_y2;

        widget_paint_display_clipping_region(&bound_x1, &bound_y1, &bound_x2, &bound_y2);

        if (!widget_clipping_intersection
            (&clip_x1, &clip_y1, &clip_x2, &clip_y2, bound_x1, bound_y1, bound_x2, bound_y2))
        {
            return; /* Image out of content region */
        }
    }
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    clip_y1 -= offset_y;
    clip_y2 -= offset_y;
    clip_x1 -= offset_x;
    clip_x2 -= offset_x;

    WAP_DBG_ASSERT(clip_x1 >= 0 && clip_x2 >= 0 && clip_y1 >= 0 && clip_y2 >= 0);

    for (y = clip_y1; y <= clip_y2; y++)
    {
        y_multiple = y * WPCACHE_CTX->width;
        for (x = clip_x1; x <= clip_x2; x++)
        {
            GDI_SET_BUFFER_PIXEL2(x + offset_x, y + offset_y, cached_buffer[y_multiple + x]);
        }
    }
#endif /* WIDGET_USE_LAYER_FLATTEN_WITH_CLIPPING */ 
//	Trace2(TRACE_GROUP_2, "[Widget] widget_MMI_show_precached_image <end>");
}

#endif /* WIDGET_PRECACHE_IMAGE */ 


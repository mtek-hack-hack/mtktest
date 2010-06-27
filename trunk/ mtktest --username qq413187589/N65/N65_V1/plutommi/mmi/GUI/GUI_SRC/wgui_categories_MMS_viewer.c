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
 *  wgui_categories_MMS_viewer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Viewer Related Categories 
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __UI_MMS_VIEWER_CATEGORY__
#include "StdC.h"
#include "L4Dr1.h"
#include "wgui.h"
#include "wgui_inputs.h"
#include "wgui_categories.h"
#include "wgui_categories_defs.h"
#include "wgui_draw_manager.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "Fs_type.h"    /* Drm_def.h needs this */
#include "Fs_func.h"
#include "Fs_errcode.h" /* File Err Code */
#include "Conversions.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"
#include "wgui_categories_MMS_viewer.h"

/* Audio/Video */
#include "Device.h" 
#include "mdi_datatype.h"
#include "Mdi_video.h"
#include "Mdi_audio.h"

#include "DebugInitDef.h"
#include "GlobalDefs.h"
#include "Lcd_if.h"
#include "gpioinc.h"
#include "PhoneSetupGprots.h"

/* Utility Functions */
static S16 wgui_mv_get_drawable_object_height(void);
static void wgui_mv_convert_from_gdi_color_to_color(color *out_color, GDI_COLOR incolor_32);
static void wgui_mv_error_condition(S32 line_num);
static void wgui_mv_media_stopped_callback(mdi_result result);

/* Paging Related Functions */
static void wgui_mv_load_paging_data(U32 start_id, U32 end_id, PU8 buffer_local);

#ifdef __MMI_TOUCH_SCREEN__
static void wgui_mv_get_data_during_scrolling(S32 percentage_val, PU8 buffer_local);
#endif 

/* Draw Related Functions */
static MMI_BOOL wgui_mv_show_drm_icon(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static MMI_BOOL wgui_mv_show_image(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static MMI_BOOL wgui_mv_show_video(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static void wgui_mv_show_media(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static MMI_BOOL wgui_mv_show_alternative_text(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static void wgui_mv_drawable_media_hide(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static void wgui_mv_drawable_media_play(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static void wgui_mv_drawable_media_show_stopped(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static void wgui_mv_drawable_media_scroll(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);
static void wgui_mv_drawable_media_dummy(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2);

static void wgui_mv_show_drawable_object(
                MMI_BOOL is_draw,
                S32 yoffset,
                S32 height,
                S32 clip_x1,
                S32 clip_y1,
                S32 clip_x2,
                S32 clip_y2);
static void wgui_mv_show_infobar(void);
static void wgui_mv_show_viewarea(void);
static void wgui_mv_show_progressbar(void);
static void wgui_mv_draw_viewer(void);

/* layout Related Functions */
static void wgui_mv_setup_screen_layout(void);
static void wgui_mv_set_multiline_object_viewable_area(void);

/* State Machine Implemenatation Functions */
static void wgui_mv_init_slide(void);
static void wgui_mv_deinit_slide(void);

static void wgui_mv_start_show(void);
static void wgui_mv_start_play(void);
static void wgui_mv_prepare_for_show(void);
static void wgui_mv_stop_slide_playing(void);

static void wgui_mv_show_active_slide(void);
static void wgui_mv_play_active_slide(void);

static void wgui_mv_set_next_slide_active(void);
static void wgui_mv_set_previous_slide_active(void);

/* Event Handlers Functions */
static void wgui_mv_smc_event_handler(const wgui_mv_event_enum event);
static void wgui_mv_handle_timer_event(void);

/* Globals Variables */
extern BOOL r2lMMIFlag;
static U16 g_wgui_mv_drawable_media_vf[WGUI_MV_VFN_LEN];
static U16 g_wgui_mv_audio_vf[WGUI_MV_VFN_LEN];
static S32 g_wgui_mv_audio_file_handle;
static S32 g_wgui_mv_drawable_media_file_handle;

static wgui_mv_context_struct g_wgui_mv_cat_cntx;   /* memset from showcategory function */
static wgui_mv_layout_struct g_wgui_mv_cat_layout;       /* memset from showcategory function */
static wgui_mv_paging_context g_wgui_mv_paging_cntx; /* memset from showcategory function */


/* This is the state machine for drawable media - image & video, 
 * see wgui_mv_drawable_media_state_enum & wgui_mv_drawable_media_event_enum */
static const wgui_mv_drawable_media_cb
    drawable_media_cb[WGUI_MV_DRAWABLE_MEDIA_EVENT_MAX][WGUI_MV_DRAWABLE_MEDIA_STATE_MAX] = 
{
    /* STATE_HIDDEN, STATE_PLAYING,	STATE_SHOWING, STATE_SROLLING */
    {wgui_mv_drawable_media_dummy, wgui_mv_drawable_media_hide, wgui_mv_drawable_media_hide,
     wgui_mv_drawable_media_hide}, /* HIDE EVENT */
    {wgui_mv_drawable_media_play, wgui_mv_drawable_media_dummy, wgui_mv_drawable_media_play,
     wgui_mv_drawable_media_play}, /* PLAY EVENT */
    {wgui_mv_drawable_media_show_stopped, wgui_mv_drawable_media_show_stopped, wgui_mv_drawable_media_show_stopped,
     wgui_mv_drawable_media_show_stopped}, /* SHOW EVENT */
    {wgui_mv_drawable_media_hide, wgui_mv_drawable_media_scroll, wgui_mv_drawable_media_scroll,
     wgui_mv_drawable_media_scroll}, /* SCROLL EVENT */
    {wgui_mv_drawable_media_dummy, wgui_mv_drawable_media_play, wgui_mv_drawable_media_show_stopped,
    wgui_mv_drawable_media_dummy,} /* REDRAW EVENT */
};


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_set_media_position
 * DESCRIPTION
 *  sets media positions
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_set_media_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 preview_width, preview_height;
    S32 img_width, img_height;
    U16 drm_id = 0;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    preview_width = MMI_content_width - (current_MMI_theme->scrollbar_size) * 2 - (CAT630_HMARGIN << 1);
    preview_height = g_wgui_mv_cat_layout.viewarea.s16Height - (CAT630_VMARGIN << 1);

    g_wgui_mv_cat_layout.resized_xoffset = 0;
    g_wgui_mv_cat_layout.resized_yoffset = 0;
    g_wgui_mv_cat_layout.resized_width = 0;
    g_wgui_mv_cat_layout.resized_height = 0;

    /* DRM check */
    if (CURRENT_SLIDE->video.id)
    {
        if (MMI_TRUE == g_wgui_mv_cat_cntx.is_drm_locked(CURRENT_SLIDE->video.id))
        {
            drm_id = WGUI_MV_DRM_VIDEO_LOCK_ID;
        }
    }
    else if (CURRENT_SLIDE->image.id)
    {
        if (MMI_TRUE == g_wgui_mv_cat_cntx.is_drm_locked(CURRENT_SLIDE->image.id))
        {
            drm_id = WGUI_MV_DRM_IMAGE_LOCK_ID;
        }
    }

    if (drm_id != 0)
    {
        if (gdi_image_get_dimension_id(
                    drm_id, &img_width, &img_height) < GDI_SUCCEED)
        {
            return MMI_FALSE;
        }
    }
    else if (CURRENT_SLIDE->video.id)
    {
    #ifdef __MMI_VIDEO_PLAYER__
        mdi_video_info_struct video_clip;

        memset(&video_clip, 0, sizeof(mdi_video_info_struct));
        /* This function doesn't consume any rights */
        if (mdi_video_ply_open_clip_file(
                    (S8*)g_wgui_mv_cat_cntx.drawable_media_file_path,
                    &video_clip) == MDI_RES_VDOPLY_SUCCEED)
        {
            img_height = video_clip.height;
            img_width = video_clip.width;
            mdi_video_ply_close_clip_file();
        }
        else
    #endif /* __MMI_VIDEO_PLAYER__ */ 
        {
            return MMI_FALSE;
        }
    }
    else if (CURRENT_SLIDE->image.id)
    {
        PS8 err_str_ptr;

        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (S8*)g_wgui_mv_cat_cntx.drawable_media_file_path, (PS8*)&err_str_ptr))
        {
            return MMI_FALSE;
        }

        if (gdi_image_get_dimension_file(
                    (S8*)g_wgui_mv_cat_cntx.drawable_media_file_path,
                    &img_width, &img_height) < GDI_SUCCEED)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }

    /* drawable region larger than image */
    if ((preview_width > img_width) && (preview_height > img_height))
    {
        /* align image at the center */
        g_wgui_mv_cat_layout.resized_xoffset = ((preview_width - img_width) >> 1);
        g_wgui_mv_cat_layout.resized_yoffset = 0;
        g_wgui_mv_cat_layout.resized_width = img_width;
        g_wgui_mv_cat_layout.resized_height = img_height;
    }
    else
    {
        /* set height */
        if (preview_height > img_height)
        {
            preview_height = img_height;
        }

        /* resize image */
        gdi_image_util_fit_bbox(
            preview_width,
            preview_height,
            img_width,
            img_height,
            &g_wgui_mv_cat_layout.resized_xoffset,
            &g_wgui_mv_cat_layout.resized_yoffset,
            &g_wgui_mv_cat_layout.resized_width,
            &g_wgui_mv_cat_layout.resized_height);

        /* check resized width and height */
        if (g_wgui_mv_cat_layout.resized_width == 0)
        {
            g_wgui_mv_cat_layout.resized_width = 1;
        }
        if (g_wgui_mv_cat_layout.resized_height == 0)
        {
            g_wgui_mv_cat_layout.resized_height = 1;
        }
    }

    g_wgui_mv_cat_layout.resized_xoffset += ((current_MMI_theme->scrollbar_size) + CAT630_HMARGIN);
    g_wgui_mv_cat_layout.resized_yoffset = CAT630_VMARGIN;

    return MMI_TRUE;
}

/* Utility Functions */


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_get_drawable_object_height
 * DESCRIPTION
 *  sizes in wgui_mv_show_drawable_object depend on this functions return value
 * PARAMETERS
 *  void
 * RETURNS
 *  the height of the object you want to display after any resizing
 *****************************************************************************/
static S16 wgui_mv_get_drawable_object_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_mv_set_media_position() == MMI_TRUE)
    {
        if (CURRENT_SLIDE->video.id)
        {
#ifdef __MMI_VIDEO_PLAYER__
            gdi_layer_create(0, 0, g_wgui_mv_cat_layout.resized_width, g_wgui_mv_cat_layout.resized_height, &g_wgui_mv_cat_layout.vlayer);
            gdi_layer_push_and_set_active(g_wgui_mv_cat_layout.vlayer);
            gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
#endif 
        }
        return g_wgui_mv_cat_layout.resized_height;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_convert_from_gdi_color_to_color
 * DESCRIPTION
 *  convert from GDI to UI Color
 * PARAMETERS
 *  out_color       [?]         
 *  incolor_32      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_convert_from_gdi_color_to_color(color *out_color, GDI_COLOR incolor_32)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_color->r = (U8) ((0xFF000000 & incolor_32) >> 24);
    out_color->g = (U8) ((0x00FF0000 & incolor_32) >> 16);
    out_color->b = (U8) ((0x0000FF00 & incolor_32) >> 8);
    out_color->alpha = (U8) ((0x000000FF & incolor_32));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_error_condition
 * DESCRIPTION
 *  called incase of some error condition
 * PARAMETERS
 *  start_id            [IN]        
 *  end_id              [IN]        
 *  buffer_local        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_error_condition(S32 line_num)
{

    PRINT_INFORMATION("WGUI_CATEGORIES_MMS_VIEWER:: file error %d", line_num);
    g_wgui_mv_cat_cntx.current_state = WGUI_MV_STATE_ERROR;
    g_wgui_mv_cat_cntx.stop_app_cb();    
}

/*****************************************************************************
 * FUNCTION
 *  wgui_mv_media_stopped_callback
 * DESCRIPTION
 *  called by media API when media playing is stopped
 * PARAMETERS
 *  result            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_media_stopped_callback(mdi_result result)
{
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;
    
    /* Only work incase of playing or showing states */
    if (!(g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING ||
        g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING))
    {
        return;
    }

    if (CURRENT_SLIDE->audio.id)
    {
        if (g_wgui_mv_cat_cntx.is_audio_play == MMI_TRUE)
        {
            g_wgui_mv_cat_cntx.is_audio_play = MMI_FALSE;
        }
    }
    else if (CURRENT_SLIDE->video.id)
    {
#ifdef __MMI_VIDEO_PLAYER__
        if (g_wgui_mv_cat_cntx.is_video_play == MMI_TRUE)
        {
            g_wgui_mv_cat_cntx.is_video_play = MMI_FALSE;
        }
#endif /* __MMI_VIDEO_PLAYER__ */
    }
    
    switch (result)
    {
        case MDI_AUDIO_DRM_TIMEOUT:
        case MDI_AUDIO_DRM_PROHIBIT:
            if (CURRENT_SLIDE->audio.id)
            {
                /* Rights Expired Midway */
                g_wgui_mv_cat_cntx.update_rights(CURRENT_SLIDE->audio.id, MMI_TRUE);
                g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NEEDED;
                mdi_audio_stop_file();
            }
            break;
        case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
        case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
            if (CURRENT_SLIDE->video.id)
            {
                /* Rights Expired Midway */
                g_wgui_mv_cat_cntx.update_rights(CURRENT_SLIDE->video.id, MMI_TRUE);
                g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
                g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_REDRAW;
            }
            break;
    }

    /* Force refresh on a slide with zero duration: it won't auto refresh */
    /* Force redraw on a stopped slide? Audio/Video won't be playing in stopped state */
    if (CURRENT_SLIDE->duration == 0)
    {
        wgui_mv_draw_viewer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_load_paging_data
 * DESCRIPTION
 *  loads data for page required
 * PARAMETERS
 *  start_id            [IN]        
 *  end_id              [IN]        
 *  buffer_local        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_load_paging_data(U32 start_id, U32 end_id, PU8 buffer_local)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    U32 pages = end_id - start_id + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buffer_local, 0, pages * GUI_PAGE_SIZE * ENCODING_LENGTH);
    len = mmi_ucs2strlen((PS8) (g_wgui_mv_cat_cntx.ptxtbuffer + (GUI_PAGE_SIZE * start_id)));

    if (len < (GUI_PAGE_SIZE * pages))
    {
        mmi_ucs2ncat(
            (PS8) buffer_local,
            (PS8) (g_wgui_mv_cat_cntx.ptxtbuffer + (GUI_PAGE_SIZE * start_id)),
            GUI_PAGE_SIZE * pages);
    }
    else
    {
        memcpy(
            buffer_local,
            g_wgui_mv_cat_cntx.ptxtbuffer + (GUI_PAGE_SIZE * start_id * ENCODING_LENGTH),
            GUI_PAGE_SIZE * pages * ENCODING_LENGTH);
    }
  
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_mv_get_data_during_scrolling
 * DESCRIPTION
 *  loads data into buffer during scrolling on touch screen
 * PARAMETERS
 *  percentage_val      [IN]        
 *  buffer_local        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_get_data_during_scrolling(S32 percentage_val, PU8 buffer_local)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_id, end_id, jump_offset_from_app;
    U32 last_page_id, total_page_id, current_page_id;
#ifdef MMS_VIEWER_DIFFERENT_FONTS
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Calculate total pages & last page id */
    last_page_id = g_wgui_mv_cat_cntx.ucs2_txt_len / GUI_PAGE_SIZE;
    last_page_id -= (g_wgui_mv_cat_cntx.ucs2_txt_len % GUI_PAGE_SIZE) ? (0) : (1);
    total_page_id = last_page_id + 1;

    /* Calculate current pages id */
    current_page_id = (total_page_id * percentage_val) / 100;
    current_page_id = (current_page_id > last_page_id) ? (last_page_id) : (current_page_id);

    /* Calculate start & end page ids */
    if (total_page_id <= PAGE_MAX)
    {
        start_id = 0;
        end_id = last_page_id;
    }
    else if (current_page_id == 0)
    {
        start_id = current_page_id;
        end_id = current_page_id + PAGE_MAX - 1;
    }
    else
    {
        start_id = current_page_id - 1;
        end_id = start_id + PAGE_MAX - 1;
        end_id = (end_id < last_page_id) ? (end_id) : (last_page_id);
    }

    //jump_offset_from_app = (current_page_id - start_id) * GUI_PAGE_SIZE;
    jump_offset_from_app = (g_wgui_mv_cat_cntx.ucs2_txt_len * percentage_val / 100) - (start_id * GUI_PAGE_SIZE);
    wgui_paging_multiline_set_page(start_id, end_id);

    wgui_mv_load_paging_data(start_id, end_id, buffer_local);
#ifdef MMS_VIEWER_DIFFERENT_FONTS
    wgui_paging_multiline_set_font(CURRENT_SLIDE->text.txtSize, CURRENT_SLIDE->text.txtStyle);
#endif 
    MMI_multiline_inputbox.page_offset = 0;
    MMI_multiline_inputbox.jump_offset_from_app = jump_offset_from_app;
    MMI_multiline_inputbox.search_flag_is_on = 0;

}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/* Draw Related Functions */
/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_drm_icon
 * DESCRIPTION
 *  show drm lock icon
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_show_drm_icon(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id = 0;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return MMI_TRUE;
    }

    id = (CURRENT_SLIDE->video.id) ? WGUI_MV_DRM_VIDEO_LOCK_ID : id;
    id = (CURRENT_SLIDE->image.id) ? WGUI_MV_DRM_IMAGE_LOCK_ID : id;

    if (id != 0)
    {
        S32 x, y, w, h, img_w, img_h;

        gdi_image_get_dimension_id(id, &img_w, &img_h);

        if ((img_w > (clip_x2 - clip_x1 + 1)) || (img_h > height))
        {
            gdi_image_util_fit_bbox(
                clip_x2 - clip_x1 + 1,
                height,
                img_w,
                img_h,
                &x,
                &y,
                &w,
                &h);
            x += clip_x1;
            y += yoffset;
        }
        else
        {
            w = img_w;
            h = img_h;
            x = (clip_x2 - clip_x1 + 1 - w) >> 1;
            y = yoffset + ((height - h) >> 1);
        }

        gdi_image_draw_resized_id(x, y, w, h, id);
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_image
 * DESCRIPTION
 *  show image part
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_show_image(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CURRENT_SLIDE->image.id)
    {
        /* set frame number */
        if (g_wgui_mv_cat_cntx.image_handle != GDI_NULL_HANDLE)
        {
            gdi_anim_stop(g_wgui_mv_cat_cntx.image_handle);
            g_wgui_mv_cat_cntx.image_handle = GDI_NULL_HANDLE;
        }

        if (is_draw == MMI_FALSE)
        {
            return MMI_TRUE;
        }

        if (g_wgui_mv_cat_cntx.drawable_media_state == WGUI_MV_DRAWABLE_MEDIA_STATE_PLAYING)
        {
            if (gdi_anim_draw_file_resized(
                    g_wgui_mv_cat_layout.resized_xoffset,
                    g_wgui_mv_cat_layout.resized_yoffset + yoffset,
                    g_wgui_mv_cat_layout.resized_width,
                    g_wgui_mv_cat_layout.resized_height,
                    g_wgui_mv_cat_cntx.drawable_media_file_path,
                    &g_wgui_mv_cat_cntx.image_handle) < GDI_SUCCEED)
            {
                return MMI_FALSE;
            }
        }
        else
        {
            if (gdi_image_draw_resized_file(
                    g_wgui_mv_cat_layout.resized_xoffset,
                    g_wgui_mv_cat_layout.resized_yoffset + yoffset,
                    g_wgui_mv_cat_layout.resized_width,
                    g_wgui_mv_cat_layout.resized_height,
                    (S8*)g_wgui_mv_cat_cntx.drawable_media_file_path) < GDI_SUCCEED)
            {
                return MMI_FALSE;
            }
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_video
 * DESCRIPTION
 *  show video part
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_show_video(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CURRENT_SLIDE->video.id)
    {
    #ifdef __MMI_VIDEO_PLAYER__
        U64 video_frame = 0;

        if (g_wgui_mv_cat_cntx.is_video_open == MMI_FALSE)
        {
            return MMI_FALSE;
        }

        /* stop video */
        if (g_wgui_mv_cat_cntx.is_video_play == MMI_TRUE)
        {
            mdi_video_ply_stop();
            g_wgui_mv_cat_cntx.is_video_play = MMI_FALSE;
        }

        /* move layer */
        gdi_layer_push_and_set_active(g_wgui_mv_cat_layout.vlayer);
        {
            /* move to a specific position if out of screen */
            S32 x_offset = -256;
            S32 y_offset = -256;

            if (is_draw == MMI_TRUE)
            {
                x_offset = g_wgui_mv_cat_layout.resized_xoffset;
                y_offset = g_wgui_mv_cat_layout.resized_yoffset + yoffset;
            }

            gdi_layer_set_position(x_offset, y_offset);
        }
        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
        gdi_layer_set_blt_layer(g_wgui_mv_cat_layout.baselayer, g_wgui_mv_cat_layout.vlayer, g_wgui_mv_cat_layout.tlayer, g_wgui_mv_cat_layout.blayer);
       
        /* set video configuration */
        mdi_video_ply_enable_partial_display(); 

        /* seek video and play the first fram at current time */
        mdi_video_ply_get_cur_play_time(&video_frame);
        mdi_video_ply_seek_and_get_frame((U64)video_frame, g_wgui_mv_cat_layout.vlayer);

        /* play video */
        if (g_wgui_mv_cat_cntx.drawable_media_state == WGUI_MV_DRAWABLE_MEDIA_STATE_PLAYING)
        {
            g_wgui_mv_cat_cntx.is_video_start_play = MMI_TRUE;
        }
        else
        {
            g_wgui_mv_cat_cntx.is_video_start_play = MMI_FALSE;
        }
    #else /* __MMI_VIDEO_PLAYER__ */ 
        return MMI_FALSE;
    #endif /* __MMI_VIDEO_PLAYER__ */ 
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_media
 * DESCRIPTION
 *  show image or video
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_mv_show_media(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = g_wgui_mv_cat_cntx.is_media_valid;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret == MMI_TRUE)
    {
        MMI_BOOL show_drm = MMI_FALSE;

        /* DRM check */
        if (CURRENT_SLIDE->video.id) 
        {
            show_drm = g_wgui_mv_cat_cntx.is_drm_locked(CURRENT_SLIDE->video.id);
        }
        else if (CURRENT_SLIDE->image.id)
        {
            show_drm = g_wgui_mv_cat_cntx.is_drm_locked(CURRENT_SLIDE->image.id);
        }

        if (show_drm == MMI_TRUE)
        {
            ret = wgui_mv_show_drm_icon(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
        }
        else if (CURRENT_SLIDE->video.id)
        {
            ret = wgui_mv_show_video(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
        }
        else if (CURRENT_SLIDE->image.id)
        {
            MMI_BOOL ret_val;

            /* we want to consume first and then display: see mmi_audply_entry_detail() */
            ret_val= g_wgui_mv_cat_cntx.start_consume_rights(CURRENT_SLIDE->image.id, 
                        g_wgui_mv_cat_cntx.drawable_media_file_path);
            if (MMI_TRUE == ret_val)
            {
                ret = wgui_mv_show_image(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
            }
            else
            {
                ret = wgui_mv_show_drm_icon(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
            }
        }
    }

    if (ret == MMI_FALSE)
    {
        wgui_mv_show_alternative_text(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_alternative_text
 * DESCRIPTION
 *  show alternative text while the media is not available
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_show_alternative_text(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;
    UI_string_type str = NULL;
    color tc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw != MMI_FALSE)
    {
        if (CURRENT_SLIDE->video.id)
        {
            str = (UI_string_type)CURRENT_SLIDE->video.alt_str;
        }
        else if (CURRENT_SLIDE->image.id)
        {
            str = (UI_string_type)CURRENT_SLIDE->image.alt_str;
        }

#ifdef __MMI_VIDEO_PLAYER__
        gdi_layer_push_and_set_active(g_wgui_mv_cat_layout.baselayer);
#endif /* __MMI_VIDEO_PLAYER__ */
        gui_push_clip();
        gui_push_text_clip();
        gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
        gui_set_text_clip(clip_x1, clip_y1, clip_x2, yoffset + height);

        if (CURRENT_SLIDE->text.id != 0)    
        {
            wgui_mv_convert_from_gdi_color_to_color(&tc, g_wgui_mv_cat_cntx.current_msg->current_slide->text.background_color);
        }
        else
        {
            wgui_mv_convert_from_gdi_color_to_color(&tc, g_wgui_mv_cat_cntx.current_msg->background_color);
        }

        gui_fill_rectangle(clip_x1, clip_y1, clip_x2, yoffset + height, tc);

        if (str != NULL)
        {
            if (!r2lMMIFlag)
            {
                gui_move_text_cursor(clip_x1, yoffset);
            }
            else
            {
                gui_move_text_cursor(clip_x2, yoffset);
            }

            gui_set_font(&MMI_medium_font);

            if (CURRENT_SLIDE->text.id != 0)    
            {
                wgui_mv_convert_from_gdi_color_to_color(&tc, g_wgui_mv_cat_cntx.current_msg->current_slide->text.foreground_color);
            }
            else
            {
                wgui_mv_convert_from_gdi_color_to_color(&tc, g_wgui_mv_cat_cntx.current_msg->foreground_color);
            }
            gui_set_text_color(tc);

            gui_print_text(str);
        }
        else
        {
            S32 x, y, w, h, img_w, img_h;

            gdi_image_get_dimension_id(WGUI_DEFAULT_PREVIEW_IMAGE_ID, &img_w, &img_h);

            if ((img_w > (clip_x2 - clip_x1 + 1)) || (img_h > height))
            {
                gdi_image_util_fit_bbox(
				    clip_x2 - clip_x1 + 1,
				    height,
				    img_w,
				    img_h,
				    &x,
				    &y,
				    &w,
				    &h);
			    x += clip_x1;
			    y += yoffset;
            }
            else
            {
                w = img_w;
                h = img_h;
                x = (clip_x2 - clip_x1 + 1 - w) >> 1;
                y = yoffset + ((height - h) >> 1);
            }

            gdi_image_draw_resized_id(x, y, w, h, WGUI_DEFAULT_PREVIEW_IMAGE_ID);
        }
        
        gui_pop_text_clip();
        gui_pop_clip();

#ifdef __MMI_VIDEO_PLAYER__
        gdi_layer_pop_and_restore_active();
#endif /* __MMI_VIDEO_PLAYER__ */
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_drawable_media_hide
 * DESCRIPTION
 *  hide callback fro drawable media
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_mv_drawable_media_hide(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: Stop playing media and clear the area */
    g_wgui_mv_cat_cntx.drawable_media_state = WGUI_MV_DRAWABLE_MEDIA_STATE_HIDDEN;

    if (CURRENT_SLIDE->video.id)
    {
    #ifdef __MMI_VIDEO_PLAYER__
        /* stop video */
        if (g_wgui_mv_cat_cntx.is_video_play == MMI_TRUE)
        {
            mdi_video_ply_stop();
            g_wgui_mv_cat_cntx.is_video_play = MMI_FALSE;

            if (g_wgui_mv_cat_layout.vlayer > 0)
            {
                gdi_layer_push_and_set_active(g_wgui_mv_cat_layout.vlayer);
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
            }
        }
    #endif /* __MMI_VIDEO_PLAYER__ */ 
    }
    else if (CURRENT_SLIDE->image.id)
    {
        if (g_wgui_mv_cat_cntx.image_handle != GDI_NULL_HANDLE)
        {
            gdi_anim_stop(g_wgui_mv_cat_cntx.image_handle);
            g_wgui_mv_cat_cntx.image_handle = GDI_NULL_HANDLE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_drawable_media_play
 * DESCRIPTION
 *  play callback for drawable media
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_mv_drawable_media_play(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: start to play media (start animation or play video) if playable */
    g_wgui_mv_cat_cntx.drawable_media_state = WGUI_MV_DRAWABLE_MEDIA_STATE_PLAYING;

    wgui_mv_show_media(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_drawable_media_show_stopped
 * DESCRIPTION
 *  callback for showing media in stopped state
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_mv_drawable_media_show_stopped(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: show first frame of video or animation or image */
    g_wgui_mv_cat_cntx.drawable_media_state = WGUI_MV_DRAWABLE_MEDIA_STATE_SHOWING;

    wgui_mv_show_media(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_drawable_media_scroll
 * DESCRIPTION
 *  callback during scrolling
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_mv_drawable_media_scroll(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: move layers etc if necessary */
    wgui_mv_show_media(is_draw, yoffset, height, clip_x1, clip_y1, clip_x2, clip_y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_drawable_media_dummy
 * DESCRIPTION
 *  dummy function may or may not be used
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_mv_drawable_media_dummy(
                    MMI_BOOL is_draw,
                    S32 yoffset,
                    S32 height,
                    S32 clip_x1,
                    S32 clip_y1,
                    S32 clip_x2,
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: probably do nothing here */

}

/* 1 This function is called from Multiline input through the header/footer callback */


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_drawable_object
 * DESCRIPTION
 *  main callback from multiline input
 * PARAMETERS
 *  is_draw     [IN]        
 *  yoffset     [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_show_drawable_object(
                MMI_BOOL is_draw,
                S32 yoffset,
                S32 height,
                S32 clip_x1,
                S32 clip_y1,
                S32 clip_x2,
                S32 clip_y2)
{
#ifdef MMSVIEWER_UNIT_TEST
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 draw_x, draw_y, draw_width, draw_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Draw Wire Frame To Contain Image */
    if (r2lMMIFlag)
    {
        draw_x = current_MMI_theme->scrollbar_size + CAT630_HMARGIN - 1;
        draw_width = MMI_content_width - current_MMI_theme->scrollbar_size - (CAT630_HMARGIN << 1);
    }
    else
    {
        draw_x = CAT630_HMARGIN - 1;
        draw_width = MMI_content_width - current_MMI_theme->scrollbar_size - (CAT630_HMARGIN << 1);
    }

    draw_y = yoffset + CAT630_VMARGIN;
    draw_height = 60 - (CAT630_VMARGIN << 1);
#endif /* MMSVIEWER_UNIT_TEST */ 

    /* Callback table is maintained above: drawable_media_cb */
    gdi_layer_lock_frame_buffer();
    drawable_media_cb[g_wgui_mv_cat_cntx.drawable_media_event][g_wgui_mv_cat_cntx.drawable_media_state] (is_draw, yoffset, height,
                                                                                               clip_x1, clip_y1,
                                                                                               clip_x2, clip_y2);
    gdi_layer_unlock_frame_buffer();

    /* Unless some event comes next time this function is called due to multiline inputbox being redrawn */
    g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_REDRAW;

#ifdef MMSVIEWER_UNIT_TEST
    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    gui_draw_rectangle(draw_x, draw_y, draw_x + draw_width, draw_y + draw_height, UI_COLOR_BLACK);
    /* ASSERT( draw_y+draw_height < clip_y2); */
    gui_pop_clip();
#endif /* MMSVIEWER_UNIT_TEST */ 

}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_infobar
 * DESCRIPTION
 *  display infobar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_show_infobar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 x1 = g_wgui_mv_cat_layout.infobar.s16X;
    U16 x2 = g_wgui_mv_cat_layout.infobar.s16X + g_wgui_mv_cat_layout.infobar.s16Width - 1;
    U16 y1 = g_wgui_mv_cat_layout.infobar.s16Y;
    U16 y2 = g_wgui_mv_cat_layout.infobar.s16Y + g_wgui_mv_cat_layout.infobar.s16Height - 1;
    U16 str[10];

    S32 icon_x, icon_y;
    S32 w = 0, h = 0;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This function does GetImage four times when a new slide is show */
    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);

    gui_set_font(CAT630_FONT);
    gui_set_text_color(CAT630_IBAR_FONT_COLOR);

    gui_show_image(x1, y1, (PU8) GetImage(WGUI_MV_TITLE_ICON_IMAGE_ID));

    icon_x = 0;

    if (g_wgui_mv_cat_cntx.current_msg->show_attachment_icon == MMI_TRUE)
    {
        PU8 attach_icon = (PU8) GetImage(WGUI_MV_ATTACHFILE_ICON_IMAGE_ID);

        /* Display Attachment Icon Here */
        gui_measure_image(attach_icon, &w, &h);
        icon_y = y1 + (y2 - y1 - h) / 2;
        icon_x = CAT630_ARROW_GAP;
        gui_show_image(icon_x, icon_y, attach_icon);
    }

    if (CURRENT_SLIDE->audio.id)
    {
        PU8 audio_icon;

        /* There is no way to know if rights expired mid way. */
        /* So, the status may change to rights expired and we */
        /* still maybe showing unblocked image */
        if (MMI_TRUE == g_wgui_mv_cat_cntx.is_drm_locked(CURRENT_SLIDE->audio.id))
        {
            audio_icon = (PU8) GetImage(WGUI_MV_RING_STOP_ICON_IMAGE_ID);
        }
        else
        {
            audio_icon = (PU8) GetImage(WGUI_MV_RING_ICON_IMAGE_ID);
        }

        /* Display Audio Icon Here */
        gui_measure_image(audio_icon, &w, &h);
        icon_x += w + CAT630_ARROW_GAP;
        icon_y = y1 + (y2 - y1 - h) / 2;
        gui_show_image(icon_x, icon_y, audio_icon);
    }

    gui_sprintf(str, "%d/%d", CURRENT_SLIDE->slide_num, g_wgui_mv_cat_cntx.current_msg->total_slide_num);
    gui_measure_string(str, &w, &h);

    if (g_wgui_mv_cat_layout.larrow.Flags == WGUI_MV_BUTTON_PRESSED_STATE)
    {
        gui_show_image(
            g_wgui_mv_cat_layout.larrow.s16X,
            g_wgui_mv_cat_layout.larrow.s16Y,
            (PU8) GetImage(WGUI_MV_LEFT_ARROW_DOWN_ICON_IMAGE_ID));
    }
    else
    {
        gui_show_image(
            g_wgui_mv_cat_layout.larrow.s16X,
            g_wgui_mv_cat_layout.larrow.s16Y,
            (PU8) GetImage(WGUI_MV_LEFT_ARROW_ICON_IMAGE_ID));
    }

    if (g_wgui_mv_cat_layout.rarrow.Flags == WGUI_MV_BUTTON_PRESSED_STATE)
    {
        gui_show_image(
            g_wgui_mv_cat_layout.rarrow.s16X,
            g_wgui_mv_cat_layout.rarrow.s16Y,
            (PU8) GetImage(WGUI_MV_RIGHT_ARROW_DOWN_ICON_IMAGE_ID));
    }
    else
    {
        gui_show_image(
            g_wgui_mv_cat_layout.rarrow.s16X,
            g_wgui_mv_cat_layout.rarrow.s16Y,
            (PU8) GetImage(WGUI_MV_RIGHT_ARROW_ICON_IMAGE_ID));
    }

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            g_wgui_mv_cat_layout.rarrow.s16X - ((g_wgui_mv_cat_layout.rarrow.s16X - g_wgui_mv_cat_layout.larrow.s16X - g_wgui_mv_cat_layout.larrow.s16Width - w) / 2),
            y1 + ((y2 - y1 - h) / 2));
    }
    else
    {
        gui_move_text_cursor(
            g_wgui_mv_cat_layout.larrow.s16X + ((g_wgui_mv_cat_layout.rarrow.s16X - g_wgui_mv_cat_layout.larrow.s16X + g_wgui_mv_cat_layout.larrow.s16Width - w) / 2),
            y1 + ((y2 - y1 - h) / 2));
    }
    gui_print_text(str);

    gui_pop_text_clip();
    gui_pop_clip();

    g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NOT_NEEDED;
    gui_BLT_double_buffer(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_viewarea
 * DESCRIPTION
 *  dispaly view area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_show_viewarea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_multiline_inputbox();
    g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NOT_NEEDED;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_progressbar
 * DESCRIPTION
 *  display progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_show_progressbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 x1 = g_wgui_mv_cat_layout.pbar_area.s16X;
    U16 x2 = g_wgui_mv_cat_layout.pbar_area.s16X + g_wgui_mv_cat_layout.pbar_area.s16Width - 1;
    U16 y1 = g_wgui_mv_cat_layout.pbar_area.s16Y;
    U16 y2 = g_wgui_mv_cat_layout.pbar_area.s16Y + g_wgui_mv_cat_layout.pbar_area.s16Height - 1;

    /* center the pbar image which maybe smaller than pbar area */
    U16 progressbar_x = g_wgui_mv_cat_layout.pbar_area.s16X + ((g_wgui_mv_cat_layout.pbar_area.s16Width - g_wgui_mv_cat_layout.pbar_img_width) >> 1);
    color tc;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note: incase WGUI_MV_LAYOUT_TYPE_OVERLAPPING_PROGRESS_BAR wgui_mv_show_active_slide will not redraw progressbar */


    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    /* Start: Draw BG same as multiline inputbox */
    if (CURRENT_SLIDE->text.id != 0 && CURRENT_SLIDE->text.str_id == 0)    
    {
        wgui_mv_convert_from_gdi_color_to_color(&tc, CURRENT_SLIDE->text.background_color);
    }
    else
    {
        wgui_mv_convert_from_gdi_color_to_color(&tc, g_wgui_mv_cat_cntx.current_msg->background_color);
    }
    
    gui_fill_rectangle(x1, y1, x2, y2, tc);

    if (g_wgui_mv_cat_layout.type == WGUI_MV_LAYOUT_TYPE_OVERLAPPING_PROGRESS_BAR)
    {
        gui_show_image(progressbar_x, y1, g_wgui_mv_cat_layout.pbar_img);
    }
    else
    {
        gui_show_image(progressbar_x, y1, g_wgui_mv_cat_layout.pbar_img);
    }

    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING)
    {
        S32 w, h;
        U16 str[6];
        S16 pbar_w = g_wgui_mv_cat_layout.pbar_img_width - (CAT630_PBAR_HMARGIN << 1);

        /* Draw Progress Indication */
        x1 = progressbar_x + CAT630_PBAR_HMARGIN;
        y1 = y1 + CAT630_PBAR_VMARGIN;
        y2 = y2 - CAT630_PBAR_VMARGIN;
        x2 = pbar_w - 1;

        if (CURRENT_SLIDE->duration != 0)
        {
            pbar_w = (pbar_w * g_wgui_mv_cat_cntx.slide_time) / (CURRENT_SLIDE->duration);
        }
        else
        {
            pbar_w = (pbar_w * g_wgui_mv_cat_cntx.slide_time);
        }

        if (pbar_w)
        {
            gui_fill_rectangle(x1, y1, x1 + pbar_w, y2, CAT630_PBAR_BG_COLOR);
        }

        /* Draw Remaining Time Text */
        gui_push_text_clip();
        gui_set_text_clip(x1, y1, x2, y2);
        gui_set_font(&MMI_medium_font);
        gui_set_text_color(CAT630_PBAR_FONT_COLOR);
        if (g_wgui_mv_cat_cntx.slide_time > 59)
        {
            gui_sprintf(str, "%02d:%02d", g_wgui_mv_cat_cntx.slide_time / 60, g_wgui_mv_cat_cntx.slide_time % 60);
        }
        else
        {
            gui_sprintf(str, "00:%02d", g_wgui_mv_cat_cntx.slide_time);
        }
        gui_measure_string(str, &w, &h);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x2 - (x2 - x1 - w) / 2, y1 + 1 + (y2 - y1 - h) / 2);
        }
        else
        {
            gui_move_text_cursor(x1 + (x2 - x1 - w) / 2, y1 + 1 + (y2 - y1 - h) / 2);
        }
        gui_print_text(str);
        gui_pop_text_clip();
    }

    gui_pop_clip();
    g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NOT_NEEDED;
}

/* 1 This is main redraw function from where all controls are redrawn depending upon need */


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_draw_viewer
 * DESCRIPTION
 *  main draw routine that calls other display functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_draw_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAYER__
    /* setup layer blt sequence */
    if (CURRENT_SLIDE->video.id != 0)
    {
        gdi_layer_set_blt_layer(g_wgui_mv_cat_layout.baselayer, g_wgui_mv_cat_layout.vlayer, g_wgui_mv_cat_layout.tlayer, g_wgui_mv_cat_layout.blayer);
    }
    else
    {
        gdi_layer_set_blt_layer(g_wgui_mv_cat_layout.baselayer, GDI_NULL_HANDLE, g_wgui_mv_cat_layout.tlayer, g_wgui_mv_cat_layout.blayer);
    }

    gdi_layer_restore_base_active();
#endif /* __MMI_VIDEO_PLAYER__ */
    
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);

    gdi_layer_lock_frame_buffer();

    if (g_wgui_mv_cat_layout.infobar.Flags == WGUI_MV_REDRAW_NEEDED)
    {
        wgui_mv_show_infobar();
    }
    if (g_wgui_mv_cat_layout.viewarea.Flags == WGUI_MV_REDRAW_NEEDED)
    {
        wgui_mv_show_viewarea();
    }

    if (g_wgui_mv_cat_layout.pbar_area.Flags == WGUI_MV_REDRAW_NEEDED)
    {
        wgui_mv_show_progressbar();
    }

    gdi_layer_unlock_frame_buffer();
    gui_BLT_double_buffer(0, 0, LCD_WIDTH, LCD_HEIGHT);

#ifdef __MMI_VIDEO_PLAYER__
    if (g_wgui_mv_cat_cntx.is_video_start_play == MMI_TRUE)
    {
        MMI_BOOL ret_val;

        g_wgui_mv_cat_cntx.is_video_start_play = MMI_FALSE;
        /* Already shown DRM default image in wgui_mv_show_media    *
         * incase ret_val false below                               */
        ret_val= g_wgui_mv_cat_cntx.start_consume_rights(CURRENT_SLIDE->video.id, 
                    g_wgui_mv_cat_cntx.drawable_media_file_path);

        if (MMI_TRUE == ret_val)
        {
            BOOL playaudio = (g_wgui_mv_cat_cntx.allow_audio_play() == MMI_TRUE) ? TRUE : FALSE;

#ifdef __DRM_SUPPORT__
            if (g_wgui_mv_cat_cntx.is_video_playing == MMI_TRUE)
            {
                /* do not consume right while start playing, that is, during scrolling, etc. */
                mdi_video_ply_drm_disable_consume_count();
            }
#endif /* __DRM_SUPPORT__ */
            if (mdi_video_ply_play(
                        g_wgui_mv_cat_layout.vlayer,
                        GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3,
                        GDI_LAYER_ENABLE_LAYER_1,
                        1,
                        TRUE,
                        playaudio,
                        MDI_DEVICE_SPEAKER_BOTH,
                        MDI_VIDEO_LCD_ROTATE_0,
                        100,
                        wgui_mv_media_stopped_callback) >= 0)
            {
                g_wgui_mv_cat_cntx.is_video_play = MMI_TRUE;
#ifdef __DRM_SUPPORT__
                g_wgui_mv_cat_cntx.is_video_playing = MMI_TRUE;
#endif /* __DRM_SUPPORT__ */
            }
        }
    } else
#endif /* __MMI_VIDEO_PLAYER__ */
    if (g_wgui_mv_cat_cntx.is_audio_start_play == MMI_TRUE)
    {
        g_wgui_mv_cat_cntx.is_audio_start_play = MMI_FALSE;
        if (mdi_audio_play_file(
                    g_wgui_mv_cat_cntx.audio_file_path, 
                    DEVICE_AUDIO_PLAY_ONCE, 
                    NULL, 
                    wgui_mv_media_stopped_callback) >= 0)
        {
            g_wgui_mv_cat_cntx.is_audio_play = MMI_TRUE;
        }
    }

    /* If state is playing then we need to start the timer for another term */
    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING
        && CURRENT_SLIDE->duration != 0)
    {
        if (g_wgui_mv_cat_cntx.slide_time >= (CURRENT_SLIDE->duration-1))
        {
            gui_start_timer(CAT630_SLIDE_TIME_UNIT-CAT630_SLIDE_SWITCH_GAP_TIME, wgui_mv_handle_timer_event);
        }
        else
        {
            gui_start_timer(CAT630_SLIDE_TIME_UNIT, wgui_mv_handle_timer_event);
        }
    }
}

/* layout Related */
/* 1 This function calculates the screen layout for once on entering the category */


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_setup_screen_layout
 * DESCRIPTION
 *  setup screen layout and save layout. Is called only once from show category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_setup_screen_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width, text_height;
    S32 img_width, img_height;

#ifdef __MMI_VIDEO_PLAYER__
    S32 result;
    S32 bytesperpx;
    PU8 baselayerptr;
#endif /* __MMI_VIDEO_PLAYER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_wgui_mv_cat_layout, 0, sizeof(wgui_mv_layout_struct));

    /* WGUI_MV_TITLE_ICON_IMAGE_ID should be 2 px larger in height than WGUI_MV_BAR_ICON_IMAGE_ID */
    g_wgui_mv_cat_layout.pbar_img = (PU8) GetImage(WGUI_MV_BAR_ICON_IMAGE_ID);
    ASSERT(g_wgui_mv_cat_layout.pbar_img);

    gui_measure_image(g_wgui_mv_cat_layout.pbar_img, &g_wgui_mv_cat_layout.pbar_img_width, &g_wgui_mv_cat_layout.pbar_img_height);

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    g_wgui_mv_cat_layout.type = WGUI_MV_LAYOUT_TYPE_INDEPENDENT_PROGRESS_BAR;
#else 
    g_wgui_mv_cat_layout.type = WGUI_MV_LAYOUT_TYPE_OVERLAPPING_PROGRESS_BAR;
#endif 

    /* Infobar */
    g_wgui_mv_cat_layout.infobar.s16X = MMI_CONTENT_X;
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
    g_wgui_mv_cat_layout.infobar.s16Y = MMI_STATUS_BAR_HEIGHT;
#else 
    g_wgui_mv_cat_layout.infobar.s16Y = 0;
#endif 
    g_wgui_mv_cat_layout.infobar.s16Width = MMI_CONTENT_WIDTH;
    g_wgui_mv_cat_layout.infobar.s16Height = g_wgui_mv_cat_layout.pbar_img_height;      /*  + 1 */
    g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NEEDED;

    /* Progress Bar */
    memcpy(&g_wgui_mv_cat_layout.pbar_area, &g_wgui_mv_cat_layout.infobar, sizeof(dm_coordinates));

    if (g_wgui_mv_cat_layout.type == WGUI_MV_LAYOUT_TYPE_INDEPENDENT_PROGRESS_BAR)
    {
        g_wgui_mv_cat_layout.pbar_area.s16Y = UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - g_wgui_mv_cat_layout.infobar.s16Height;
    }
    g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NEEDED;

    /* Viewer Area */
    g_wgui_mv_cat_layout.viewarea.s16X = MMI_CONTENT_X;
    g_wgui_mv_cat_layout.viewarea.s16Y = g_wgui_mv_cat_layout.infobar.s16Y + g_wgui_mv_cat_layout.infobar.s16Height;
    g_wgui_mv_cat_layout.viewarea.s16Width = MMI_CONTENT_WIDTH;
    g_wgui_mv_cat_layout.viewarea.s16Height = UI_DEVICE_HEIGHT - g_wgui_mv_cat_layout.viewarea.s16Y - MMI_BUTTON_BAR_HEIGHT;
    if (g_wgui_mv_cat_layout.type == WGUI_MV_LAYOUT_TYPE_INDEPENDENT_PROGRESS_BAR)
    {
        g_wgui_mv_cat_layout.viewarea.s16Height -= g_wgui_mv_cat_layout.infobar.s16Height;
    }
    g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;

    /* Multiline Inputbox */
    MMI_multiline_inputbox_x = g_wgui_mv_cat_layout.viewarea.s16X;
    MMI_multiline_inputbox_y = g_wgui_mv_cat_layout.viewarea.s16Y;
    MMI_multiline_inputbox_width = g_wgui_mv_cat_layout.viewarea.s16Width;
    MMI_multiline_inputbox_height = g_wgui_mv_cat_layout.viewarea.s16Height;

    /* Info & Progress bar */
    if (g_wgui_mv_cat_cntx.current_msg->total_slide_num > 99)
    {
        gui_measure_string(L"555/555", &text_width, &text_height);
    }
    else
    {
        gui_measure_string(L"55/55", &text_width, &text_height);
    }

    gui_measure_image((PU8) GetImage(WGUI_MV_LEFT_ARROW_ICON_IMAGE_ID), &img_width, &img_height);

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    /* Draw Slide Navigation Center Aligned */
    g_wgui_mv_cat_layout.larrow.s16X =
        g_wgui_mv_cat_layout.infobar.s16X + (g_wgui_mv_cat_layout.infobar.s16Width -
                                   (text_width + (img_width << 1) + (CAT630_ARROW_GAP << 1))) / 2;
    g_wgui_mv_cat_layout.rarrow.s16X = g_wgui_mv_cat_layout.larrow.s16X + img_width + CAT630_ARROW_GAP + text_width + CAT630_ARROW_GAP;

#else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) */ 
    /* Draw Slide Navigation Left Aligned */
    g_wgui_mv_cat_layout.larrow.s16X =
        g_wgui_mv_cat_layout.infobar.s16X + g_wgui_mv_cat_layout.infobar.s16Width - text_width - (img_width << 1) - (CAT630_ARROW_GAP << 1);
    g_wgui_mv_cat_layout.rarrow.s16X = g_wgui_mv_cat_layout.infobar.s16X + g_wgui_mv_cat_layout.infobar.s16Width - img_width;

#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) */ 
    g_wgui_mv_cat_layout.rarrow.s16Y = g_wgui_mv_cat_layout.larrow.s16Y =
        g_wgui_mv_cat_layout.infobar.s16Y + ((g_wgui_mv_cat_layout.infobar.s16Height - img_height) >> 1);
    g_wgui_mv_cat_layout.rarrow.s16Width = g_wgui_mv_cat_layout.larrow.s16Width = img_width;
    g_wgui_mv_cat_layout.rarrow.s16Height = g_wgui_mv_cat_layout.larrow.s16Height = img_height;

#ifdef __MMI_VIDEO_PLAYER__
    /* Create Necessary Layers */

    /*
     * We use four layers
     * * 0 - for content area (baselayer) 
     * * 1 - for video (this layer maybe empty when no video is playing but we have to create anyway) (vlayer)
     * * 2 - for statusbar and infobar (tlayer)
     * * 3 - for progressbar and buttonbar (blayer)
     */

    result = gdi_layer_get_base_handle(&g_wgui_mv_cat_layout.baselayer);
    ASSERT(result >= 0);

    result = gdi_layer_get_buffer_ptr(&baselayerptr);
    ASSERT(result >= 0);
    bytesperpx = (gdi_layer_get_bit_per_pixel()) >> 3;

    g_wgui_mv_cat_layout.vlayer = 0;

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
    result = gdi_layer_create_using_outside_memory(
                MMI_CONTENT_X,
                0,
                MMI_CONTENT_WIDTH,
                MMI_STATUS_BAR_HEIGHT + g_wgui_mv_cat_layout.infobar.s16Height,
                &g_wgui_mv_cat_layout.tlayer,
                baselayerptr,
                (MMI_STATUS_BAR_HEIGHT + g_wgui_mv_cat_layout.infobar.s16Height) * (MMI_CONTENT_WIDTH) * bytesperpx);
    ASSERT(result >= 0);

#else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
    result = gdi_layer_create_using_outside_memory(
                MMI_CONTENT_X,
                0,
                MMI_CONTENT_WIDTH,
                g_wgui_mv_cat_layout.infobar.s16Height,
                &g_wgui_mv_cat_layout.tlayer,
                baselayerptr,
                (g_wgui_mv_cat_layout.infobar.s16Height) * (MMI_CONTENT_WIDTH) * bytesperpx);
    ASSERT(result >= 0);

#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 

    baselayerptr =
        baselayerptr + (bytesperpx * (MMI_CONTENT_WIDTH) * (g_wgui_mv_cat_layout.viewarea.s16Y + g_wgui_mv_cat_layout.viewarea.s16Height));
    if (g_wgui_mv_cat_layout.type == WGUI_MV_LAYOUT_TYPE_INDEPENDENT_PROGRESS_BAR)
    {
        result = gdi_layer_create_using_outside_memory(
                    MMI_CONTENT_X,
                    g_wgui_mv_cat_layout.viewarea.s16Y + g_wgui_mv_cat_layout.viewarea.s16Height,
                    MMI_CONTENT_WIDTH,
                    MMI_BUTTON_BAR_HEIGHT + g_wgui_mv_cat_layout.pbar_area.s16Height,
                    &g_wgui_mv_cat_layout.blayer,
                    baselayerptr,
                    MMI_CONTENT_WIDTH * (MMI_BUTTON_BAR_HEIGHT + g_wgui_mv_cat_layout.pbar_area.s16Height) * bytesperpx);
    }
    else
    {
        result = gdi_layer_create_using_outside_memory(
                    MMI_CONTENT_X,
                    g_wgui_mv_cat_layout.viewarea.s16Y + g_wgui_mv_cat_layout.viewarea.s16Height,
                    MMI_CONTENT_WIDTH,
                    MMI_BUTTON_BAR_HEIGHT,
                    &g_wgui_mv_cat_layout.blayer,
                    baselayerptr,
                    MMI_CONTENT_WIDTH * MMI_BUTTON_BAR_HEIGHT * bytesperpx);
    }
    ASSERT(result >= 0);
#endif /* __MMI_VIDEO_PLAYER__ */ 
}

/* 1 This fn is called everytime a slide is intialised */


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_set_multiline_object_viewable_area
 * DESCRIPTION
 *  find drawable media height
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_set_multiline_object_viewable_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 height;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((CURRENT_SLIDE->video.id) || (CURRENT_SLIDE->image.id))
    {
        U8 test;
        
        height = wgui_mv_get_drawable_object_height();
        g_wgui_mv_cat_cntx.is_media_valid = (height <= 0) ? MMI_FALSE : MMI_TRUE;
        height = (height < CAT630_ERROR_TEXT_HEIGHT) ? CAT630_ERROR_TEXT_HEIGHT : (height + (CAT630_VMARGIN << 1));

        /* Depending on Layout of MMS set the following two */
        test = (g_wgui_mv_cat_cntx.current_msg->layout == WGUI_MV_DRAWABLE_MEDIA_ON_BOTTOM) ? 1 : 0;

        MMI_multiline_inputbox.header_height = (test) ? 0 : height;
        MMI_multiline_inputbox.footer_height = (test) ? height : 0;
        MMI_multiline_inputbox.header_callback = (test) ? NULL : wgui_mv_show_drawable_object;
        MMI_multiline_inputbox.footer_callback = (test) ? wgui_mv_show_drawable_object : NULL;
    }
    else
    {
        MMI_multiline_inputbox.header_height = 0;
        MMI_multiline_inputbox.footer_height = 0;
        MMI_multiline_inputbox.header_callback = NULL;
        MMI_multiline_inputbox.footer_callback = NULL;
    }

    MMI_multiline_inputbox.min_text_height = 0;
        //CAT630_MIN_LINE_HEIGHT * 2 + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height;
    MMI_multiline_inputbox.min_line_height = CAT630_MIN_LINE_HEIGHT;
}

/* State Machine Implemenatation */
/*****************************************************************************
 * FUNCTION
 *  wgui_mv_init_slide
 * DESCRIPTION
 *  Initial Slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_init_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    color tc;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_mv_cat_cntx.current_state = WGUI_MV_STATE_INIT_SLIDE;

    /* Handle Text Object */
    g_wgui_mv_cat_cntx.ucs2_txt_len = 0;
    memset(g_wgui_mv_cat_cntx.pinputboxbuffer, 0, ENCODING_LENGTH);

    if (CURRENT_SLIDE->text.str_id)
    {
        /*STR ID has more precedence than obj id text buffer */
        mmi_ucs2ncpy(
            (PS8) g_wgui_mv_cat_cntx.ptxtbuffer,
            (PS8) GetString(CURRENT_SLIDE->text.str_id),
            GUI_PAGE_SIZE);
        g_wgui_mv_cat_cntx.ucs2_txt_len = mmi_ucs2strlen((PS8) g_wgui_mv_cat_cntx.ptxtbuffer);

    } 
    else if (CURRENT_SLIDE->text.id != 0)
    {
        result = g_wgui_mv_cat_cntx.load_paging_txt (g_wgui_mv_cat_cntx.ptxtbuffer,
                    g_wgui_mv_cat_cntx.ptxtbuffersize, CURRENT_SLIDE->text.id);
        if (result == MMI_FALSE)
        {
            wgui_mv_error_condition(__LINE__);
            return;
        }

        g_wgui_mv_cat_cntx.ucs2_txt_len = mmi_ucs2strlen((PS8)g_wgui_mv_cat_cntx.ptxtbuffer);
    }

    /* Handle Audio Object */
    if (CURRENT_SLIDE->audio.id != 0)
    {
        result = g_wgui_mv_cat_cntx.get_filename_by_id(CURRENT_SLIDE->audio.id, g_wgui_mv_audio_vf, 
            &g_wgui_mv_cat_cntx.audio_file_path, &g_wgui_mv_audio_file_handle);

        if (result == MMI_FALSE)
        {
            wgui_mv_error_condition(__LINE__);
            return;
        }
        g_wgui_mv_cat_cntx.update_rights(CURRENT_SLIDE->audio.id, MMI_FALSE);
    }
    g_wgui_mv_cat_cntx.is_audio_start_play = MMI_FALSE;

    /* Handle Drawable Object */
    if (CURRENT_SLIDE->image.id != 0)
    {
        result = g_wgui_mv_cat_cntx.get_filename_by_id(CURRENT_SLIDE->image.id, g_wgui_mv_drawable_media_vf, 
            &g_wgui_mv_cat_cntx.drawable_media_file_path, &g_wgui_mv_drawable_media_file_handle);

        if (result == MMI_FALSE)
        {
            wgui_mv_error_condition(__LINE__);
            return;
        }
        g_wgui_mv_cat_cntx.update_rights(CURRENT_SLIDE->image.id, MMI_FALSE);
    }
    else if (CURRENT_SLIDE->video.id != 0)
    {
        result = g_wgui_mv_cat_cntx.get_filename_by_id(CURRENT_SLIDE->video.id, g_wgui_mv_drawable_media_vf, 
            &g_wgui_mv_cat_cntx.drawable_media_file_path, &g_wgui_mv_drawable_media_file_handle);

        if (result == MMI_FALSE)
        {
            wgui_mv_error_condition(__LINE__);
            return;
        }
        g_wgui_mv_cat_cntx.update_rights(CURRENT_SLIDE->video.id, MMI_FALSE);
    }
    
    /* suspend background audio */
    if ((CURRENT_SLIDE->audio.id != 0) || (CURRENT_SLIDE->video.id != 0))
    {
        mdi_audio_suspend_background_play();
    }

    /* Setup Multiline Input Box:: Setup Paging */
    if (g_wgui_mv_cat_cntx.ucs2_txt_len <= (GUI_PAGE_SIZE * PAGE_MAX))
    {
        U8 end_page_id = 0;

        if (g_wgui_mv_cat_cntx.ucs2_txt_len != 0)
        {
            mmi_ucs2ncpy((PS8) g_wgui_mv_cat_cntx.pinputboxbuffer, (PS8) g_wgui_mv_cat_cntx.ptxtbuffer, g_wgui_mv_cat_cntx.ucs2_txt_len);
            end_page_id = g_wgui_mv_cat_cntx.ucs2_txt_len / (GUI_PAGE_SIZE);
            end_page_id -= (g_wgui_mv_cat_cntx.ucs2_txt_len % GUI_PAGE_SIZE) ? (0) : (1);
        }
        create_multiline_inputbox_set_buffer(
            (UI_string_type) g_wgui_mv_cat_cntx.pinputboxbuffer,
            g_wgui_mv_cat_cntx.ucs2_txt_len * ENCODING_LENGTH,
            g_wgui_mv_cat_cntx.ucs2_txt_len,
            0);
        MMI_multiline_inputbox.end_id = end_page_id;
    }
    else
    {
        memcpy(g_wgui_mv_cat_cntx.pinputboxbuffer, g_wgui_mv_cat_cntx.ptxtbuffer, GUI_PAGE_SIZE * PAGE_MAX * ENCODING_LENGTH);
        create_multiline_inputbox_set_buffer(
            (UI_string_type) g_wgui_mv_cat_cntx.pinputboxbuffer,
            GUI_PAGE_SIZE * PAGE_MAX * ENCODING_LENGTH,
            GUI_PAGE_SIZE * PAGE_MAX,
            0);
        MMI_multiline_inputbox.end_id = PAGE_MAX - 1;
    }

    wgui_mv_set_multiline_object_viewable_area();

    MMI_multiline_inputbox.flags |= (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
                                     | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                                     UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR);
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;
    MMI_multiline_inputbox.scroll_type = WGUI_PAGING_SCROLL_LINE_BY_LINE;
    MMI_multiline_inputbox.start_id = g_wgui_mv_paging_cntx.page_id;
    MMI_multiline_inputbox.page_offset = g_wgui_mv_paging_cntx.text_offset;
    MMI_multiline_inputbox.jump_offset_from_app = 0;
    MMI_multiline_inputbox.search_flag_is_on = 0;
    show_multiline_inputbox_no_draw();
    wgui_paging_set_scrollbar_range(g_wgui_mv_cat_cntx.ucs2_txt_len);
    wgui_paging_multiline_set_get_page_callback(wgui_mv_load_paging_data);
    wgui_paging_reset_show_percentage_flag();
    wgui_paging_multiline_clear_last_percentage();
#ifdef MMS_VIEWER_DIFFERENT_FONTS
    wgui_paging_multiline_set_font(CURRENT_SLIDE->text.txtSize, CURRENT_SLIDE->text.txtStyle);
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    wgui_paging_multiline_set_scroll_data_cb(wgui_mv_get_data_during_scrolling);
#endif 
    if (g_wgui_mv_paging_cntx.text_offset)
    {
        wgui_paging_multiline_set_percentage(g_wgui_mv_paging_cntx.page_id, (S16)g_wgui_mv_paging_cntx.text_offset);
    }

    if (g_wgui_mv_paging_cntx.text_offset != 0)
    {
        if (MMI_multiline_inputbox.text_offset_y != g_wgui_mv_paging_cntx.last_text_offset_y)
        {
            MMI_multiline_inputbox.text_offset_y = g_wgui_mv_paging_cntx.last_text_offset_y;
        }
    } 

    /* Set Multiline Inputbox BG&FG Color */
    memset(&g_wgui_mv_cat_cntx.bgfiller, 0, sizeof(UI_filled_area));
    if (CURRENT_SLIDE->text.id != 0 && CURRENT_SLIDE->text.str_id == 0)
    {
        wgui_mv_convert_from_gdi_color_to_color(&tc, CURRENT_SLIDE->text.foreground_color);
    }
    else
    {
        wgui_mv_convert_from_gdi_color_to_color(&tc, g_wgui_mv_cat_cntx.current_msg->foreground_color);
    }
    
    MMI_multiline_inputbox.normal_text_color = tc;
    if (CURRENT_SLIDE->text.id != 0 && CURRENT_SLIDE->text.str_id == 0)
    {
        wgui_mv_convert_from_gdi_color_to_color(&tc, CURRENT_SLIDE->text.background_color);
    }
    else
    {
        wgui_mv_convert_from_gdi_color_to_color(&tc, g_wgui_mv_cat_cntx.current_msg->background_color);
    }
        
    g_wgui_mv_cat_cntx.bgfiller.c = tc;
    g_wgui_mv_cat_cntx.bgfiller.flags = UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_TYPE_NO_BORDER;
    MMI_multiline_inputbox.normal_filler = &g_wgui_mv_cat_cntx.bgfiller;
    MMI_multiline_inputbox.boundary_color = tc;
    MMI_multiline_inputbox.vbar.normal_bar_filler = &g_wgui_mv_cat_cntx.bgfiller;

    g_wgui_mv_cat_cntx.slide_time = 0;

    g_wgui_mv_cat_cntx.image_handle = GDI_NULL_HANDLE;
#ifdef __MMI_VIDEO_PLAYER__
    g_wgui_mv_cat_cntx.is_video_open = MMI_FALSE;
    g_wgui_mv_cat_cntx.is_video_play = MMI_FALSE;
#ifdef __DRM_SUPPORT__
    g_wgui_mv_cat_cntx.is_video_playing = MMI_FALSE;
#endif /* __DRM_SUPPORT__ */
    g_wgui_mv_cat_cntx.is_video_start_play = MMI_FALSE;

    if (g_wgui_mv_cat_cntx.is_media_valid == MMI_TRUE)
    {
        if (CURRENT_SLIDE->video.id != 0)
        {
            mdi_video_info_struct video_clip;

            if (mdi_video_ply_open_clip_file((S8*) g_wgui_mv_cat_cntx.drawable_media_file_path, &video_clip) ==
                MDI_RES_VDOPLY_SUCCEED)
            {
                g_wgui_mv_cat_cntx.is_video_open = MMI_TRUE;
            }
        }
    }
#endif /* __MMI_VIDEO_PLAYER__ */
    g_wgui_mv_cat_cntx.is_audio_play = MMI_FALSE;

    /* apply context only once */
    memset(&g_wgui_mv_paging_cntx, 0, sizeof(wgui_mv_paging_context));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_deinit_slide
 * DESCRIPTION
 *  correct place for any cleanup actions after the slide has been played
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_deinit_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(wgui_mv_handle_timer_event);
    g_wgui_mv_cat_cntx.current_state = WGUI_MV_STATE_DEINIT_SLIDE;
    g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_HIDE;
    g_wgui_mv_cat_cntx.drawable_media_state = WGUI_MV_DRAWABLE_MEDIA_STATE_HIDDEN;
    g_wgui_mv_cat_cntx.drawable_media_file_path = NULL;
    /* reset_multiline_inputbox */
    wgui_multiline_inputbox_hide_text_content(MMI_FALSE);

    /* Txt File handle is not kept open  */

    if (CURRENT_SLIDE->audio.id)
    {
        if (g_wgui_mv_cat_cntx.is_audio_play == MMI_TRUE)
        {
            mdi_audio_stop_file();
            g_wgui_mv_cat_cntx.is_audio_play = MMI_FALSE;
        }

        /* Destory Virtual Files */
        if (g_wgui_mv_audio_file_handle != 0)
        {
            FS_Close(g_wgui_mv_audio_file_handle);
            g_wgui_mv_audio_file_handle = 0;
        }
        memset((PS8) & g_wgui_mv_audio_vf, 0, WGUI_MV_VFN_LEN);
    }
    if (CURRENT_SLIDE->image.id)
    {
        g_wgui_mv_cat_cntx.stop_consume_rights (CURRENT_SLIDE->image.id);
        if ((g_wgui_mv_cat_cntx.image_handle != GDI_NULL_HANDLE) 
            && (g_wgui_mv_cat_cntx.image_handle != GDI_ERROR_HANDLE))
        {
            gdi_anim_stop(g_wgui_mv_cat_cntx.image_handle);
        }
        g_wgui_mv_cat_cntx.image_handle = GDI_NULL_HANDLE;  
        /* Destory Virtual Files */
        if (g_wgui_mv_drawable_media_file_handle != 0)
        {
            FS_Close(g_wgui_mv_drawable_media_file_handle);
            g_wgui_mv_drawable_media_file_handle = 0;
        }
        memset((PS8) & g_wgui_mv_drawable_media_vf, 0, WGUI_MV_VFN_LEN);
    }
    else if (CURRENT_SLIDE->video.id)
    {
#ifdef __MMI_VIDEO_PLAYER__
        if (g_wgui_mv_cat_cntx.is_video_play == MMI_TRUE)
        {
            mdi_video_ply_stop();
            g_wgui_mv_cat_cntx.is_video_play = MMI_FALSE;
        }
#ifdef __DRM_SUPPORT__
        g_wgui_mv_cat_cntx.is_video_playing = MMI_FALSE;
#endif /* __DRM_SUPPORT__ */
        if (g_wgui_mv_cat_cntx.is_video_open == MMI_TRUE)
        {
            mdi_video_ply_close_clip_file();
            g_wgui_mv_cat_cntx.is_video_open = MMI_FALSE;
        }
        /* This layer is alloc through init slide so free in deinit */
        if (g_wgui_mv_cat_layout.vlayer != GDI_NULL_HANDLE)
        {
            gdi_layer_free(g_wgui_mv_cat_layout.vlayer);
            g_wgui_mv_cat_layout.vlayer = GDI_NULL_HANDLE;
        }        
#endif /* __MMI_VIDEO_PLAYER__ */ 

        /* Destory Virtual Files */
        if (g_wgui_mv_drawable_media_file_handle != 0)
        {
            FS_Close(g_wgui_mv_drawable_media_file_handle);
            g_wgui_mv_drawable_media_file_handle = 0;
        }
        memset((PS8) & g_wgui_mv_drawable_media_vf, 0, WGUI_MV_VFN_LEN);
    }

    /* resume background audio */
    if ((CURRENT_SLIDE->audio.id != 0) || (CURRENT_SLIDE->video.id != 0))
    {
        mdi_audio_resume_background_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_start_show
 * DESCRIPTION
 *  start to show
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_start_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set first slide active */
    wgui_mv_init_slide();
    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_ERROR)
    {
        return;
    }
    g_wgui_mv_cat_cntx.current_state = WGUI_MV_STATE_SHOWING;
    wgui_multiline_inputbox_hide_text_content(MMI_FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_start_play
 * DESCRIPTION
 *  start to play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_start_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set first slide active */
    wgui_mv_init_slide();
    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_ERROR)
    {
      return;
    }
    g_wgui_mv_cat_cntx.current_state = WGUI_MV_STATE_PLAYING;
    wgui_multiline_inputbox_hide_text_content(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_prepare_for_show
 * DESCRIPTION
 *  prepare for show after playing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_prepare_for_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_left_softkey(g_wgui_mv_cat_cntx.lsk_str_id, IMAGE_ID_NULL);
    change_right_softkey(STR_GLOBAL_BACK, IMAGE_ID_NULL);
    SetLeftSoftkeyFunction(g_wgui_mv_cat_cntx.lsk_fn, KEY_EVENT_UP);
    SetRightSoftkeyFunction(g_wgui_mv_cat_cntx.rsk_fn, KEY_EVENT_UP);
    /*redraw_left_softkey();*/
    /*redraw_right_softkey();*/
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_stop_slide_playing
 * DESCRIPTION
 *  stop playing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_stop_slide_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(wgui_mv_handle_timer_event);
    wgui_mv_smc_event_handler(WGUI_MV_EVENT_STOP_PLAY_START_SHOW);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_show_active_slide
 * DESCRIPTION
 *  show the currently active slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_show_active_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_ERROR)
    {
       return;
    }
    g_wgui_mv_cat_cntx.current_state = WGUI_MV_STATE_SHOWING;
    g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NEEDED;
    g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
    g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NEEDED;
    wgui_multiline_inputbox_hide_text_content(MMI_FALSE);
    if (CURRENT_SLIDE->audio.id)
    {
        if (g_wgui_mv_cat_cntx.is_audio_play == MMI_TRUE)
        {
            mdi_audio_stop_file();
            g_wgui_mv_cat_cntx.is_audio_play = MMI_FALSE;
        }
    }
    g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_SHOW_STOPPED;
    if (g_wgui_mv_cat_layout.type == WGUI_MV_LAYOUT_TYPE_OVERLAPPING_PROGRESS_BAR)
    {
        g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NOT_NEEDED;
    }
    wgui_mv_draw_viewer();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_play_active_slide
 * DESCRIPTION
 *  play the currently active slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_play_active_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_ERROR)
    {
      return;
    }
    g_wgui_mv_cat_cntx.current_state = WGUI_MV_STATE_PLAYING;
    g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NEEDED;
    g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
    g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NEEDED;
    wgui_multiline_inputbox_hide_text_content(MMI_TRUE);
    wgui_mv_handle_timer_event();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_set_next_slide_active
 * DESCRIPTION
 *  set next slide as active slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_set_next_slide_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We have already Deinit the last slide so there has to be a next slide */
    ASSERT(CURRENT_SLIDE->next != NULL);
    g_wgui_mv_cat_cntx.current_msg->current_slide = CURRENT_SLIDE->next;
    wgui_mv_init_slide();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_set_previous_slide_active
 * DESCRIPTION
 *  set previous slide as the active slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_set_previous_slide_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We have already Deinit the last slide so there has to be a previous slide */
    ASSERT(CURRENT_SLIDE->previous != NULL);
    g_wgui_mv_cat_cntx.current_msg->current_slide = CURRENT_SLIDE->previous;
    wgui_mv_init_slide();
}

/* Event Handler */

/*****************************************************************************
 * FUNCTION
 *  wgui_mv_smc_event_handler
 * DESCRIPTION
 *  We have two state machines in viewer cat
 *  One is the slide state machine which controls a slide's lifetime etc
 *  Another state machine which controls the event's within a slide's lifetime
 *  Following is the event handler for a slide's lifetime related events
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_smc_event_handler(const wgui_mv_event_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case WGUI_MV_EVENT_SHOW_START:
            /* InitialiseViewerCategory functionality is in ShowCategory630Screen */
            wgui_mv_start_show();
            break;
        case WGUI_MV_EVENT_SHOW_NEXT_SLIDE:
            wgui_mv_deinit_slide();
            wgui_mv_set_next_slide_active();
            wgui_mv_show_active_slide();
            break;
        case WGUI_MV_EVENT_SHOW_PREVIOUS_SLIDE:
            wgui_mv_deinit_slide();
            wgui_mv_set_previous_slide_active();
            wgui_mv_show_active_slide();
            break;
        case WGUI_MV_EVENT_PLAY_START:
            /* InitialiseViewerCategory functionality is in ShowCategory630Screen */
            wgui_mv_start_play();
            break;
        case WGUI_MV_EVENT_PLAY_PREVIOUS_SLIDE:
            wgui_mv_deinit_slide();
            wgui_mv_set_previous_slide_active();
            wgui_mv_play_active_slide();
            break;
        case WGUI_MV_EVENT_PLAY_NEXT_SLIDE:
            wgui_mv_deinit_slide();
            wgui_mv_set_next_slide_active();
            wgui_mv_play_active_slide();
            break;
        case WGUI_MV_EVENT_STOP_EVENT:
            wgui_mv_deinit_slide();
            /* deinitialiseViewerCategory functionality is in wgui_mv_exit_category */
            break;
        case WGUI_MV_EVENT_STOP_PLAY_START_SHOW:
            /* Slide is already initialised */
            wgui_mv_prepare_for_show(); /* Stop Audio, Copy Image/Video first frame etc */
            wgui_mv_show_active_slide();
            break;
        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_mv_switch_slide_with_time_gap
 * DESCRIPTION
 *  goto next slide because of timed event
 *  made to wait for last step of progressbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_switch_slide_with_time_gap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Current Slide has played itself out */
    g_wgui_mv_cat_cntx.slide_time = 0;

    if (CURRENT_SLIDE->slide_num < g_wgui_mv_cat_cntx.current_msg->total_slide_num)
    {
        wgui_mv_smc_event_handler(WGUI_MV_EVENT_PLAY_NEXT_SLIDE);
    }
    else
    {
        wgui_mv_smc_event_handler(WGUI_MV_EVENT_STOP_PLAY_START_SHOW);
    }
}


/* 1 We generate timed events here */


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_handle_timer_event
 * DESCRIPTION
 *  handle timer event for Timed events like hide media etc.
 *  these events take place within one slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_handle_timer_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(CURRENT_SLIDE);

    gui_cancel_timer(wgui_mv_handle_timer_event);

    if (CURRENT_SLIDE->duration == 0)
    {
        /* Current Slide is still playing */
        g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NEEDED;
        g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
        g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NEEDED;
        g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_PLAY;
        
        if (CURRENT_SLIDE->audio.id && CURRENT_SLIDE->video.id == 0)
        {
            /* Start Audio Playing */
            if (CURRENT_SLIDE->audio.id != 0 )
            {
                if (MMI_FALSE == g_wgui_mv_cat_cntx.is_drm_locked(CURRENT_SLIDE->audio.id))
                {
                    MMI_BOOL ret_val;
                    ret_val= g_wgui_mv_cat_cntx.start_consume_rights(CURRENT_SLIDE->audio.id, 
                                g_wgui_mv_cat_cntx.drawable_media_file_path);

                    if (MMI_TRUE == ret_val)
                    {
                        if (g_wgui_mv_cat_cntx.allow_audio_play() == MMI_TRUE)
                        {
                            g_wgui_mv_cat_cntx.is_audio_start_play = MMI_TRUE;
                        }
                    }
                }
            }
        }

        wgui_multiline_inputbox_hide_text_content(MMI_FALSE);
        wgui_mv_draw_viewer();        
        return;
    }


    if (g_wgui_mv_cat_cntx.slide_time >= CURRENT_SLIDE->duration)
    {
        U16 x1 = g_wgui_mv_cat_layout.pbar_area.s16X;
        U16 x2 = g_wgui_mv_cat_layout.pbar_area.s16X + g_wgui_mv_cat_layout.pbar_area.s16Width - 1;
        U16 y1 = g_wgui_mv_cat_layout.pbar_area.s16Y;
        U16 y2 = g_wgui_mv_cat_layout.pbar_area.s16Y + g_wgui_mv_cat_layout.pbar_area.s16Height - 1;
        
        gdi_layer_lock_frame_buffer();
        wgui_mv_show_progressbar();
        gdi_layer_unlock_frame_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
        
        gui_start_timer(CAT630_SLIDE_SWITCH_GAP_TIME, wgui_mv_switch_slide_with_time_gap);
    }
    else
    {
        /* Current Slide is still playing */
        /* Some other control may have turned on redraw for a particular control */
        //g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NOT_NEEDED;
        //g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NOT_NEEDED;
        
        /* we NEED to redraw progressbar definitely */
        g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NEEDED;

        if (CURRENT_SLIDE->audio.id)
        {
            if (g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->audio.end)
            {
                /* Stop Audio Playing */
                if (g_wgui_mv_cat_cntx.is_audio_play == MMI_TRUE)
                {
                    mdi_audio_stop_file();
                    g_wgui_mv_cat_cntx.is_audio_play = MMI_FALSE;
                }
            }
            else if ((g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->audio.begin)
#ifdef __MMI_VIDEO_PLAYER__
                     && (g_wgui_mv_cat_cntx.is_video_play == MMI_FALSE)
#endif /* __MMI_VIDEO_PLAYER__ */
                     )
            {
                /* Start Audio Playing */
                if (CURRENT_SLIDE->audio.id != 0 )
                {
                    if (MMI_FALSE == g_wgui_mv_cat_cntx.is_drm_locked(CURRENT_SLIDE->audio.id))
                    {
                        MMI_BOOL ret_val;

                        ret_val= g_wgui_mv_cat_cntx.start_consume_rights(CURRENT_SLIDE->audio.id, 
                                    g_wgui_mv_cat_cntx.drawable_media_file_path);

                        if (MMI_TRUE == ret_val)
                        {
                            if (g_wgui_mv_cat_cntx.allow_audio_play() == MMI_TRUE)
                            {
                                g_wgui_mv_cat_cntx.is_audio_start_play = MMI_TRUE;
                            }
                        }
                    }
                }
            }
        }

        if (CURRENT_SLIDE->image.id)
        {
            if (g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->image.end)
            {
                /* Image maybe scrolled out but may still be consuming rights? */
                g_wgui_mv_cat_cntx.stop_consume_rights (CURRENT_SLIDE->image.id);
                g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_HIDE;
                g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
            }
            else if (g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->image.begin)
            {
                g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_PLAY;
                g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
            }
        }
        else if (CURRENT_SLIDE->video.id)
        {
            if (g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->video.end)
            {
                g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_HIDE;
                g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
            }
            else if (g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->video.begin)
            {
                g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_PLAY;
                g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
            }
        }
        if (CURRENT_SLIDE->text.id && CURRENT_SLIDE->text.str_id == 0)
        {
            if (g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->text.end)
            {
                /* Stop text Showing */
                wgui_multiline_inputbox_hide_text_content(MMI_TRUE);
                g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
            }
            else if (g_wgui_mv_cat_cntx.slide_time == CURRENT_SLIDE->text.begin)
            {
                /* Start text Showing */
                wgui_multiline_inputbox_hide_text_content(MMI_FALSE);
                g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
            }
        }
        else if (g_wgui_mv_cat_cntx.slide_time == 0)
        {
            wgui_multiline_inputbox_hide_text_content(MMI_FALSE);
            g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
        }

        if (g_wgui_mv_cat_cntx.slide_time == 0)
        {
            g_wgui_mv_cat_layout.infobar.Flags = WGUI_MV_REDRAW_NEEDED;
            g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
        }

        wgui_mv_draw_viewer();
        ++g_wgui_mv_cat_cntx.slide_time;
    }

}

/* Category related functions Exit handlers, category draw function, key handlers */


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_start_viewing
 * DESCRIPTION
 *  start viewing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_start_viewing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING 
        && g_wgui_mv_cat_layout.type == WGUI_MV_LAYOUT_TYPE_OVERLAPPING_PROGRESS_BAR)
    {
        g_wgui_mv_cat_layout.pbar_area.Flags = WGUI_MV_REDRAW_NOT_NEEDED;
    }

    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING)
    {
        wgui_mv_handle_timer_event();
    }
    else if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING)
    {
        g_wgui_mv_cat_cntx.drawable_media_state = WGUI_MV_DRAWABLE_MEDIA_STATE_SHOWING;
        g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_SHOW_STOPPED;
        wgui_mv_draw_viewer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_draw_category_controlled_area
 * DESCRIPTION
 *  draw category function
 * PARAMETERS
 *  coordinate      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_draw_category_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_exit_category
 * DESCRIPTION
 *  exit category function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_exit_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 shared_bytes;
    U8 last_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(wgui_mv_handle_timer_event);
    gui_cancel_timer(wgui_mv_switch_slide_with_time_gap);

    wgui_paging_multiline_get_current_page(
        &g_wgui_mv_paging_cntx.page_id,
        &g_wgui_mv_paging_cntx.text_offset,
        &shared_bytes,
        &last_percentage,
        &g_wgui_mv_paging_cntx.last_text_offset_y);

    wgui_mv_deinit_slide();/* Close any open file handles etc */

#ifdef __MMI_VIDEO_PLAYER__
    if (g_wgui_mv_cat_layout.vlayer != 0)
    {
        gdi_layer_free(g_wgui_mv_cat_layout.vlayer);
    }
    gdi_layer_free(g_wgui_mv_cat_layout.tlayer);
    gdi_layer_free(g_wgui_mv_cat_layout.blayer);
#endif /* __MMI_VIDEO_PLAYER__ */ 

    /* enable backlight turn-off & screen saver */
    TurnOffBacklight();
    mmi_phnset_enable_partial_ss();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_up_key_handler
 * DESCRIPTION
 *  key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_up_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING || g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING)
    {
        g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_SCROLL;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        {
            g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_SCROLL;
            wgui_paging_multiline_inputbox_previous_line_in_paging();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_down_key_handler
 * DESCRIPTION
 *  key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_down_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING || g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        {
            g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_SCROLL;
            wgui_paging_multiline_inputbox_next_line_in_paging_scroll();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_left_key_down_handler
 * DESCRIPTION
 *  left key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_left_key_down_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(CURRENT_SLIDE);
    if (CURRENT_SLIDE->previous != NULL)
    {
        g_wgui_mv_cat_layout.larrow.Flags = WGUI_MV_BUTTON_PRESSED_STATE;
        wgui_mv_show_infobar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_right_key_down_handler
 * DESCRIPTION
 *  right key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_right_key_down_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(CURRENT_SLIDE);
    if (CURRENT_SLIDE->next != NULL)
    {
        g_wgui_mv_cat_layout.rarrow.Flags = WGUI_MV_BUTTON_PRESSED_STATE;
        wgui_mv_show_infobar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_left_key_up_handler
 * DESCRIPTION
 *  left key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_left_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(CURRENT_SLIDE);
    g_wgui_mv_cat_layout.larrow.Flags = WGUI_MV_BUTTON_RELEASED_STATE;

    if (CURRENT_SLIDE->previous != NULL)
    {
        if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING)
        {
            wgui_mv_smc_event_handler(WGUI_MV_EVENT_SHOW_PREVIOUS_SLIDE);
        }
        else if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING)
        {
            wgui_mv_smc_event_handler(WGUI_MV_EVENT_PLAY_PREVIOUS_SLIDE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_right_key_up_handler
 * DESCRIPTION
 *  right key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_mv_right_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(CURRENT_SLIDE);
    g_wgui_mv_cat_layout.rarrow.Flags = WGUI_MV_BUTTON_RELEASED_STATE;

    if (CURRENT_SLIDE->next != NULL)
    {
        if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING)
        {
            wgui_mv_smc_event_handler(WGUI_MV_EVENT_SHOW_NEXT_SLIDE);
        }
        else if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING)
        {
            wgui_mv_smc_event_handler(WGUI_MV_EVENT_PLAY_NEXT_SLIDE);
        }
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_translate_viewarea_pen_event
 * DESCRIPTION
 *  translate pen event and take ownership of event if owned
 * PARAMETERS
 *  pos         [IN]        
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_translate_viewarea_pen_event(mmi_pen_point_struct pos, mmi_pen_event_type_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (wgui_paging_pen_down_hdlr(pos) == MMI_TRUE)
            {
                return MMI_TRUE;
            }
            break;
        case MMI_PEN_EVENT_MOVE:
            if (wgui_paging_pen_move_hdlr(pos) == MMI_TRUE)
            {
                return MMI_TRUE;
            }
            break;
        case MMI_PEN_EVENT_UP:
            if (wgui_paging_pen_up_hdlr(pos) == MMI_TRUE)
            {
                return MMI_TRUE;
            }
            break;
        default:
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_translate_infobar_pen_event
 * DESCRIPTION
 *  see if infobar event
 * PARAMETERS
 *  pos         [IN]        
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_translate_infobar_pen_event(mmi_pen_point_struct pos, mmi_pen_event_type_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            g_wgui_mv_cat_layout.larrow.s16X,
            g_wgui_mv_cat_layout.larrow.s16Y,
            g_wgui_mv_cat_layout.larrow.s16Width,
            g_wgui_mv_cat_layout.larrow.s16Height))
    {
        switch (event)
        {
            case MMI_PEN_EVENT_MOVE:
            case MMI_PEN_EVENT_DOWN:
                wgui_mv_left_key_down_handler();
                return MMI_TRUE;
            case MMI_PEN_EVENT_UP:
                wgui_mv_left_key_up_handler();
                return MMI_TRUE;
            default:
                return MMI_FALSE;
        }

    }
    else if (PEN_CHECK_BOUND(
                pos.x,
                pos.y,
                g_wgui_mv_cat_layout.rarrow.s16X,
                g_wgui_mv_cat_layout.rarrow.s16Y,
                g_wgui_mv_cat_layout.rarrow.s16Width,
                g_wgui_mv_cat_layout.rarrow.s16Height))
    {
        switch (event)
        {
            case MMI_PEN_EVENT_MOVE:
            case MMI_PEN_EVENT_DOWN:
                wgui_mv_right_key_down_handler();
                return MMI_TRUE;
            case MMI_PEN_EVENT_UP:
                wgui_mv_right_key_up_handler();
                return MMI_TRUE;
            default:
                return MMI_FALSE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_translate_category_pen_event
 * DESCRIPTION
 *  see if category has control
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_translate_category_pen_event(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            g_wgui_mv_cat_layout.infobar.s16X,
            g_wgui_mv_cat_layout.infobar.s16Y,
            g_wgui_mv_cat_layout.infobar.s16Width + g_wgui_mv_cat_layout.viewarea.s16Width,
            g_wgui_mv_cat_layout.infobar.s16Height + g_wgui_mv_cat_layout.viewarea.s16Height))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_pen_down_hldr
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_pen_down_hldr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_mv_translate_infobar_pen_event(pos, MMI_PEN_EVENT_DOWN) == MMI_TRUE)
    {
        /* Only Infobar Buttons to get further events */
        g_wgui_mv_cat_layout.cat_pen_event = WGUI_MV_CAT_PEN_INFOBAR_EVENT;
        return MMI_TRUE;
    }
    else if (wgui_mv_translate_viewarea_pen_event(pos, MMI_PEN_EVENT_DOWN) == MMI_TRUE)
    {
        /* Only View Area to get further events */
        g_wgui_mv_cat_layout.cat_pen_event = WGUI_MV_CAT_PEN_VIEW_EVENT;
        return MMI_TRUE;
    }
    else if (wgui_mv_translate_category_pen_event(pos) == MMI_TRUE)
    {
        /* Category will get and ignore further events */
        g_wgui_mv_cat_layout.cat_pen_event = WGUI_MV_CAT_PEN_IGNORE_EVENT;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_pen_move_hldr
 * DESCRIPTION
 *  pen move handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_pen_move_hldr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_mv_cat_layout.cat_pen_event == WGUI_MV_CAT_PEN_INFOBAR_EVENT)
    {
        if (wgui_mv_translate_infobar_pen_event(pos, MMI_PEN_EVENT_MOVE) == MMI_TRUE)
        {
            return MMI_TRUE;
        }
        else if (g_wgui_mv_cat_layout.larrow.Flags == WGUI_MV_BUTTON_PRESSED_STATE
                 || g_wgui_mv_cat_layout.rarrow.Flags == WGUI_MV_BUTTON_PRESSED_STATE)
        {
            /* Stuck Button Syndrome */
            g_wgui_mv_cat_layout.larrow.Flags = WGUI_MV_BUTTON_RELEASED_STATE;
            g_wgui_mv_cat_layout.rarrow.Flags = WGUI_MV_BUTTON_RELEASED_STATE;
            wgui_mv_show_infobar();
        }

    }
    else if (g_wgui_mv_cat_layout.cat_pen_event == WGUI_MV_CAT_PEN_VIEW_EVENT)
    {
        if (wgui_mv_translate_viewarea_pen_event(pos, MMI_PEN_EVENT_MOVE) == MMI_TRUE)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_pen_repeat_hldr
 * DESCRIPTION
 *  pen repeat handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_pen_repeat_hldr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_pen_up_hldr
 * DESCRIPTION
 *  pen up handler
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_mv_pen_up_hldr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wgui_mv_cat_layout.cat_pen_event == WGUI_MV_CAT_PEN_INFOBAR_EVENT)
    {
        if (wgui_mv_translate_infobar_pen_event(pos, MMI_PEN_EVENT_UP) == MMI_TRUE)
        {
            return MMI_TRUE;
        }
    }
    else if (g_wgui_mv_cat_layout.cat_pen_event == WGUI_MV_CAT_PEN_VIEW_EVENT)
    {
        if (wgui_mv_translate_viewarea_pen_event(pos, MMI_PEN_EVENT_UP) == MMI_TRUE)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}
#endif /* __MMI_TOUCH_SCREEN__ */

static MMI_BOOL wgui_mv_check_rights_by_id_dummy(U32 object_id)
{
    return MMI_FALSE; /* We always have rights */
}

static MMI_BOOL wgui_mv_start_consume_rights_dummy(U32 object_id, PU16 file_path)
{
    /* DUMMY CALLBACK */
    return MMI_TRUE; /* We always have Rights! */
}

static void wgui_mv_stop_consume_rights_dummy(U32 object_id)
{
    /* DUMMY CALLBACK */
}

static void wgui_mv_update_rights_by_id_dummy(U32 object_id, MMI_BOOL rights_expired)
{
    /* DUMMY CALLBACK */
}

/* External Interfaces Category */
void Category630Initialize(wgui_mv_initialize_struct *init)
{
    memset(&g_wgui_mv_cat_cntx, 0, sizeof(wgui_mv_context_struct));

    /* Data Members */
    g_wgui_mv_cat_cntx.current_msg = init->current_msg;
    g_wgui_mv_cat_cntx.ptxtbuffer = init->ptxtbuffer;
    g_wgui_mv_cat_cntx.ptxtbuffersize = init->ptxtbuffersize;
    g_wgui_mv_cat_cntx.pinputboxbuffer = init->pinputboxbuffer;

    ASSERT(g_wgui_mv_cat_cntx.current_msg);
    ASSERT(g_wgui_mv_cat_cntx.ptxtbuffer);
    ASSERT(g_wgui_mv_cat_cntx.ptxtbuffersize);
    ASSERT(g_wgui_mv_cat_cntx.pinputboxbuffer);

    /* Callbacks to APP */
    g_wgui_mv_cat_cntx.get_filename_by_id = init->get_filename_by_id_cb;
    g_wgui_mv_cat_cntx.load_paging_txt = init->load_slide_txt_cb;
    g_wgui_mv_cat_cntx.is_drm_locked = init->check_rights_cb;
    g_wgui_mv_cat_cntx.start_consume_rights = init->consume_rights_cb;
    g_wgui_mv_cat_cntx.stop_consume_rights = init->stop_consume_rights_cb;
    g_wgui_mv_cat_cntx.update_rights = init->update_rights_cb;
    g_wgui_mv_cat_cntx.stop_app_cb = init->stop_app_cb;
    g_wgui_mv_cat_cntx.allow_audio_play = init->allow_audio_cb;

    /* Image/Video/Audio/Text all depend upon following CB */
    ASSERT(g_wgui_mv_cat_cntx.get_filename_by_id);
    /* Loading Txt into Buffer is APP's responsibility */
    ASSERT(g_wgui_mv_cat_cntx.load_paging_txt);
    /* Stop APP incase of Error */
    ASSERT(g_wgui_mv_cat_cntx.stop_app_cb);
    /* Allow audio playing */
    ASSERT(g_wgui_mv_cat_cntx.allow_audio_play);
    
    if (!g_wgui_mv_cat_cntx.is_drm_locked)
    {
        g_wgui_mv_cat_cntx.is_drm_locked = wgui_mv_check_rights_by_id_dummy;
    }

    if (!g_wgui_mv_cat_cntx.start_consume_rights)
    {
        g_wgui_mv_cat_cntx.start_consume_rights = wgui_mv_start_consume_rights_dummy;
    }

    if (!g_wgui_mv_cat_cntx.stop_consume_rights)
    {
        g_wgui_mv_cat_cntx.stop_consume_rights = wgui_mv_stop_consume_rights_dummy;
    }

    if (!g_wgui_mv_cat_cntx.update_rights)
    {
        g_wgui_mv_cat_cntx.update_rights = wgui_mv_update_rights_by_id_dummy;
    }
}

/*****************************************************************************
 * FUNCTION
 *  Category630ImageRightExpiredNotify
 * DESCRIPTION
 *  Called from APP when Image rights expired an image current on slide
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void Category630ImageRightExpiredNotify (void)
{
    wgui_mv_slide_struct *CURRENT_SLIDE = g_wgui_mv_cat_cntx.current_msg->current_slide;

    if (!(g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_PLAYING
        || g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING))
    {
        /*Viewer is Not playing or Showing let's not mess with states */
        return;
    }

    /* Current slide image have expired either */
    /* Set redraw flag if playing with non zero duration */
    /* Else force redraw */
    g_wgui_mv_cat_layout.viewarea.Flags = WGUI_MV_REDRAW_NEEDED;
    g_wgui_mv_cat_cntx.drawable_media_event = WGUI_MV_DRAWABLE_MEDIA_EVENT_REDRAW;

    /* Force refresh on a slide with zero duration: it won't auto refresh */
    /* Force redraw on a stopped slide? Audio/Video won't be playing in stopped state */
    if (CURRENT_SLIDE->duration == 0 || g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_SHOWING)
    {
        wgui_mv_draw_viewer();
    }
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory630Screen
 * DESCRIPTION
 *  Show Category Function
 * PARAMETERS
 *  startshowing        [IN]        
 *  lsk_function        [IN]        
 *  lsk_str_id          [IN]        
 *  rsk_function        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory630Screen (BOOL startshowing, softkey_fn lsk_function, U16 lsk_str_id, softkey_fn rsk_function, PU8 guibuffer)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disable backlight turn-off & screen saver */
    TurnOnBacklight(0);
    mmi_phnset_disable_partial_ss();

    g_wgui_mv_cat_cntx.lsk_fn = lsk_function;
    g_wgui_mv_cat_cntx.lsk_str_id = lsk_str_id;
    g_wgui_mv_cat_cntx.rsk_fn = rsk_function;

    if (NULL == guibuffer)
    {
        memset(&g_wgui_mv_paging_cntx, 0, sizeof(wgui_mv_paging_context));
    }

    wgui_mv_setup_screen_layout();

    if (startshowing)
    {
        wgui_mv_smc_event_handler(WGUI_MV_EVENT_SHOW_START);
        if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_ERROR)
        {
            return;
        }

        change_left_softkey(g_wgui_mv_cat_cntx.lsk_str_id, IMAGE_ID_NULL);
        change_right_softkey(STR_GLOBAL_BACK, IMAGE_ID_NULL);
        SetLeftSoftkeyFunction(g_wgui_mv_cat_cntx.lsk_fn, KEY_EVENT_UP);
        SetRightSoftkeyFunction(g_wgui_mv_cat_cntx.rsk_fn, KEY_EVENT_UP);

    }
    else
    {
        wgui_mv_smc_event_handler(WGUI_MV_EVENT_PLAY_START);
        if (g_wgui_mv_cat_cntx.current_state == WGUI_MV_STATE_ERROR)
        {
            return;
        }

        change_left_softkey(STRING_ID_NULL, IMAGE_ID_NULL);
        change_right_softkey(STR_GLOBAL_STOP, IMAGE_ID_NULL);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetRightSoftkeyFunction(wgui_mv_stop_slide_playing, KEY_EVENT_UP);
    }

    register_default_hide_softkeys();
    /* clear_category_screen_key_handlers(); */

    SetKeyHandler(wgui_mv_up_key_handler, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_mv_down_key_handler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_mv_left_key_down_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_mv_right_key_down_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_mv_left_key_up_handler, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(wgui_mv_right_key_up_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);

    /* Setup standard category handler */
    ExitCategoryFunction = wgui_mv_exit_category;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY630_ID;
    dm_data.s32flags = DM_NO_BLT;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(wgui_mv_draw_category_controlled_area);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_mv_pen_down_hldr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_mv_pen_move_hldr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(wgui_mv_pen_repeat_hldr, MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(wgui_mv_pen_up_hldr, MMI_PEN_EVENT_UP);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_redraw_category_screen();    /* This will redraw status bar and buttonbar */
    wgui_mv_start_viewing();
}

#else /* defined(__UI_MMS_VIEWER_CATEGORY__) */ 

/* here a dummy function just for removing compile warning */
void wgui_viewer_screen_dummy(void)
{
}

#endif /* __UI_MMS_VIEWER_CATEGORY__ */ 


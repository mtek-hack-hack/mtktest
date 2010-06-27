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
 *  PhotoArt.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Photo Art Applcation Header of PhotoEditor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PHOEDT_PHOART_H_
#define _PHOEDT_PHOART_H_

#ifdef __MMI_PHOTOEDITOR__

#ifndef _PHOTOEDITOR_H_
#error "please include photoeditor.h"
#endif /* _PHOTOEDITOR_H_ */
/***************************************************************************** 
* Define
*****************************************************************************/
#define PHOART_MAX_FILENAME_CHAR          (FMGR_MAX_FILE_LEN - FMGR_MAX_EXT_LEN - 1) /* max file name len */
#define PHOART_TEXT_MAX_CHAR              (10)  /* max edit char */
#define PHOART_MIN_IMG_WIDTH              (4)  /* mininum editable source image width */
#define PHOART_MIN_IMG_HEIGHT             (4)  /* mininum editable source image height */

/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
    PHOART_AUTO_RESIZE,
    PHOART_MAINLCD_CLIP,
    PHOART_SUBLCD_CLIP
} phoart_clip_type_enum;

typedef enum
{
    PHOART_TEXT_TEXT_COLOR,
    PHOART_TEXT_BORDER_COLOR,
    PHOART_TEXT_SHADOW_COLOR,
    PHOART_TEXT_ITALIC,
    PHOART_TEXT_SELECT_COUNT
} phoart_text_select_enum;

typedef enum
{
    PHOART_TEXT_SIZE_SMALL,
    PHOART_TEXT_SIZE_MEDIUM,
    PHOART_TEXT_SIZE_LARGE
} phoart_text_size_enum;


#ifdef __MMI_PHOART_EFFECT_SUPPORT__
typedef enum
{
    PHOART_ADJUST_IMAGE_TYPE,
    PHOART_ADJUST_COLOR_TYPE
} phoart_adjust_type_enum;

typedef enum
{
    PHOART_ADJUST_COLOR_R,
    PHOART_ADJUST_COLOR_G,
    PHOART_ADJUST_COLOR_B,
    PHOART_ADJUST_COLOR_TYPE_COUNT
} phoart_adjust_color_type_enum;

typedef enum
{
    PHOART_ADJUST_IMAGE_BRIGHTNESS,
    PHOART_ADJUST_IMAGE_CONTRAST,
    PHOART_ADJUST_IMAGE_SATURATION,
    PHOART_ADJUST_IMAGE_HUE,
    PHOART_ADJUST_IMAGE_TYPE_COUNT
} phoart_adjust_image_type_enum;
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */

typedef struct
{
    phoart_clip_type_enum clip_type;

    gdi_handle base_layer_handle;
    gdi_handle osd_layer_handle;
    
    gdi_color old_source_key;

    BOOL is_edited;
    BOOL is_free_memory;
    BOOL is_up_arrow_pressed;
    BOOL is_down_arrow_pressed;
    BOOL is_left_arrow_pressed;
    BOOL is_right_arrow_pressed;
    BOOL is_clip_pressed;
    BOOL is_clip;
    BOOL is_flip_ver_pressed;
    BOOL is_flip_hor_pressed;
    BOOL is_short_filename;
    BOOL is_edit_from_fmgr;

    BOOL is_lsk_pressed;
    BOOL is_rsk_pressed;
    BOOL is_scale_up_pressed;
    BOOL is_scale_down_pressed;
    BOOL is_stamp_pressed;
    BOOL was_source_key_enable;

    S32 resized_image_offset_x;
    S32 resized_image_offset_y;
    S32 resized_image_width;
    S32 resized_image_height;
    S32 image_width;
    S32 image_height;
    S32 clip_rect_center_x;
    S32 clip_rect_center_y;
    S32 clip_rect_width;
    S32 clip_rect_height;
    S32 clip_size_width;
    S32 clip_size_height;
    S32 clip_rect_x1;
    S32 clip_rect_x2;
    S32 clip_rect_y1;
    S32 clip_rect_y2;
    U16 scale_ratio;    /* 100% = origianl size */
    U16 move_count;

    S32 clip_x1;
    S32 clip_x2;
    S32 clip_y1;
    S32 clip_y2;

    U16 selected_effect;
    U16 selected_frame;
    U16 selected_icon;

    S32 icon_offset_x;
    S32 icon_offset_y;
    S32 icon_width;
    S32 icon_height;

    color text_color;
    color text_border_color;

    S32 text_info_x1;
    S32 text_info_y1;
    S32 text_info_x2;
    S32 text_info_y2;

    S32 text_select_highlight_index;

    S32 text_offset_x;
    S32 text_offset_y;
    S32 text_width;
    S32 text_height;
    BOOL is_text_select_ready;
    BOOL is_user_goback;
    
#ifdef __MMI_PHOART_EFFECT_SUPPORT__
    U16 adjust_type;
    U16 adjust_image_index;
    U16 adjust_image_value[PHOART_ADJUST_IMAGE_TYPE_COUNT];
    U16 adjust_image_min_value[PHOART_ADJUST_IMAGE_TYPE_COUNT];
    U16 adjust_image_max_value[PHOART_ADJUST_IMAGE_TYPE_COUNT];
    U16 adjust_image_step_value[PHOART_ADJUST_IMAGE_TYPE_COUNT];

    U16 adjust_color_index;
    U16 adjust_color_value[PHOART_ADJUST_COLOR_TYPE_COUNT];
    U16 adjust_color_min_value[PHOART_ADJUST_COLOR_TYPE_COUNT];
    U16 adjust_color_max_value[PHOART_ADJUST_COLOR_TYPE_COUNT];
    U16 adjust_color_step_value[PHOART_ADJUST_COLOR_TYPE_COUNT];
#endif /* #ifdef __MMI_PHOART_EFFECT_SUPPORT__ */
    stFontAttribute text_font;
    FuncPtr end_key_hdlr;

    /* text inline selection */
    UI_string_type italic_str[2];   /* off, on */
    UI_string_type size_str[3];     /* small, medium, large */

    gdi_handle icon_layer_handle;
    gdi_handle text_layer_handle;

    S8 filename_edit_buf[(PHOART_MAX_FILENAME_CHAR + FMGR_MAX_EXT_LEN + 1) *ENCODING_LENGTH];      /* file name+dot+ext name */
    PU8 origin_image_buf;
    PU8 interrupt_backup_buf;
    PU8 add_item_buf;

#ifdef __MMI_TOUCH_SCREEN__
    S32 pen_offset_x;
    S32 pen_offset_y;
#endif /* __MMI_TOUCH_SCREEN__ */ 

} phoart_cntx_struct;

/* Touch Screen */
#ifdef __MMI_TOUCH_SCREEN__

#include "wgui_touch_screen.h"
#define  PHOART_UPDATE_ICON_TIMER   300
#define  PHOART_UPDATE_TEXT_TIMER   300

typedef enum
{
    PHOART_NONE,
    PHOART_LSK,
    PHOART_RSK,
    PHOART_EDIT_EFFECT_PREV,
    PHOART_EDIT_EFFECT_NEXT,
    PHOART_EDIT_FRAME_PREV,
    PHOART_EDIT_FRAME_NEXT,
    PHOART_EDIT_ICON,
    PHOART_EDIT_TEXT,
    PHOART_CLIP_RECT,
    PHOART_ADJUST_ICON,
    PHOART_ADJUST_BAR,
    PHOART_ADJUST_SLIDER,
    PHOART_CLIP_SCALE_UP,
    PHOART_CLIP_SCALE_DOWN,
    PHOART_CLIP_CLIP_RECT,
    PHOART_FLIP_VER,
    PHOART_FLIP_HOR,
    PHOART_EDIT_ICON_STAMP,
    PHOART_EDIT_TEXT_STAMP
} phoart_touch_item_enum;

typedef struct
{
    U32 pen_event_on_object;
    S32 init_x;
    S32 init_y;
    S32 slider_width;
    S32 slider_height;
    S32 bar_x;
    S32 bar_y;
    S32 bar_width;
    S32 bar_height;
    MMI_BOOL icon_edit_update_icon;
    MMI_BOOL text_edit_update_text;
    wgui_component_info_struct lsk;
    wgui_component_info_struct rsk;
    wgui_component_info_struct prev_arrow;
    wgui_component_info_struct next_arrow;
    wgui_component_info_struct scale_up;
    wgui_component_info_struct scale_down;
    wgui_component_info_struct flip_ver;
    wgui_component_info_struct flip_hor;
    wgui_component_info_struct edit_stamp;
} phoart_touch_screen_context_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __MMI_PHOTOEDITOR__ */ 
#endif /* _PHOEDT_PHOART_H_ */ 


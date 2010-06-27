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
 *  IamgeTile.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Tile Applcation Header of PhotoEditor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PHOEDT_IMGTILE_H_
#define _PHOEDT_IMGTILE_H_

#include "MMI_features.h"
#ifdef __MMI_PHOTOEDITOR__

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif

/***************************************************************************** 
* Define
*****************************************************************************/

#define IMGTILE_MAX_FILENAME_CHAR            (FMGR_MAX_FILE_LEN-5)      /* max file name len */

#define IMGTILE_FRAME_BUFFER_SIZE            ((UI_DEVICE_WIDTH*UI_DEVICE_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)

#if ((LCD_WIDTH == 176) && (LCD_HEIGHT == 220))
#define IMGTILE_SAVE_PREDICT_SIZE   (30*1024)   /* 30k */
#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) || ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240))
#define IMGTILE_SAVE_PREDICT_SIZE   (50*1024)   /* 50k */
#else 
#define IMGTILE_SAVE_PREDICT_SIZE   (20*1024)   /* 20k */
#endif 
#define MAX_TILE                                  (9)

#define __MMI_IMGTILE_TILE_2__
/* reserved definition */
/* #define __MMI_IMGTILE_TILE_4__ */
/* #define __MMI_IMGTILE_TILE_9__ */

#ifdef __MMI_IMGTILE_TILE_2__
    #if LCD_WIDTH > LCD_HEIGHT
        #define __MMI_IMGTILE_TILE_2_HORI__         /* horizontal two tile */
    #endif
#endif /* __MMI_IMGTILE_TILE_2__ */

/***************************************************************************** 
* typedef 
*****************************************************************************/


/***************************************************************************** 
* tile position custmize struct 
*****************************************************************************/

typedef enum
{
    MMI_IMGTILE_T2 = 0,       
    
    MMI_IMGTILE_STYLE_TOTAL
}mmi_imgtile_style_e;

typedef struct
{
    U16 x;
    U16 y;
}mmi_imgtile_pos_t;

typedef struct
{
    U16 w;
    U16 h;
}mmi_imgtile_size_t;


typedef struct
{
    mmi_imgtile_pos_t  t2_pos[2];
    mmi_imgtile_size_t t2_size;
}mmi_imgtile_tile_t;



/***************************************************************************** 
* image tile application context 
*****************************************************************************/
typedef struct
{

    gdi_handle base_layer_handle;
    gdi_handle osd_layer_handle;

    BOOL is_edited;
    BOOL is_free_memory;
    BOOL is_up_arrow_pressed;
    BOOL is_down_arrow_pressed;
    BOOL is_left_arrow_pressed;
    BOOL is_right_arrow_pressed;
    BOOL is_flip_hor_pressed;
    BOOL is_clip_pressed;
    BOOL is_clip[MAX_TILE];
    BOOL is_auto_resize[MAX_TILE];

    BOOL is_lsk_pressed;
    BOOL is_rsk_pressed;
    BOOL is_scale_up_pressed;
    BOOL is_scale_down_pressed;
    BOOL is_back_from_clip;
    BOOL save_file;
    S32 image_array[MAX_TILE];

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

    S32 clipx1[MAX_TILE];
    S32 clipx2[MAX_TILE];
    S32 clipy1[MAX_TILE];
    S32 clipy2[MAX_TILE];
    S32 res_width[MAX_TILE];
    S32 res_height[MAX_TILE];

    color text_color;
    color text_border_color;

    /* stFontAttribute      text_font; */
    FuncPtr end_key_hdlr;

    S8 filename_edit_buf[(IMGTILE_MAX_FILENAME_CHAR + 5 /* ext */  + 1) *ENCODING_LENGTH];     /* file name+dot+ext name */
    PU8 origin_image_buf;
    //PU8        interrupt_backup_buf;
    //PU8        add_item_buf;

#ifdef __MMI_TOUCH_SCREEN__
    S32 pen_offset_x;
    S32 pen_offset_y;
#endif /* __MMI_TOUCH_SCREEN__ */ 

} imgtile_cntx_struct;

/* Touch Screen */
#ifdef __MMI_TOUCH_SCREEN__

typedef enum
{
    IMGTILE_NONE,
    IMGTILE_LSK,
    IMGTILE_RSK,
    IMGTILE_CLIP_SCALE_UP,
    IMGTILE_CLIP_SCALE_DOWN,
    IMGTILE_CLIP_RECT,
    IMGTILE_FLIP_HOR
} imgtile_touch_item_enum;

typedef struct
{
    U32 pen_event_on_object;
    wgui_component_info_struct lsk;
    wgui_component_info_struct rsk;
    wgui_component_info_struct scale_up;
    wgui_component_info_struct scale_down;
    wgui_component_info_struct flip_hor;
} imgtile_touch_screen_context_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __MMI_PHOTOEDITOR__ */ 
#endif /* _PHOEDT_IMGTILE_H_ */ 


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
 *  gui_effect_oem.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GUI Effect Engine Header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GUI_EFFECT_OEM_H__
#define __GUI_EFFECT_OEM_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_UI_LIST_SLIDE_EFFECT__)
#define __MMI_UI_EFFECT_ENGINE__
#endif /* defined(__MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__) || defined(__MMI_UI_LIST_SLIDE_EFFECT__) */
 
#define GUI_EFFECT_MAX(a, b)   ((a) > (b) ? (a) : (b))
#define GUI_EFFECT_MIN(a, b)   ((a) < (b) ? (a) : (b))

#define GUI_EFFECT_LAYER_COLOR_FORMAT       GDI_COLOR_FORMAT_16
#define GUI_EFFECT_LAYER_BYTE_PER_PIXEL     GUI_EFFECT_LAYER_COLOR_FORMAT

/*
 *  decide the effect layer size
 */
// TODO: calculate the effect layer size more precisely. 
#ifdef __MMI_UI_EFFECT_ENGINE__
#define GUI_EFFECT_LAYER_SIZE  (MAIN_LCD_DEVICE_WIDTH * 80 * GUI_EFFECT_LAYER_BYTE_PER_PIXEL)
#else /* __MMI_UI_EFFECT_ENGINE__ */
#define GUI_EFFECT_LAYER_SIZE 4
#endif /* __MMI_UI_EFFECT_ENGINE__ */

/* rectangle helper macros */
#define GUI_RECT_TO_POINT(rect, x1, y1, x2, y2) \
    do                                  \
    {                                   \
        x1 = (rect).x;                  \
        y1 = (rect).y;                  \
        x2 = (x1) + (rect).width - 1;     \
        y2 = (y1) + (rect).height - 1;    \
    }                                   \
    while (0)

#define GUI_RECT(rect, _x, _y, _w, _h) \
    do \
    { \
        (rect).x = _x; \
        (rect).y = _y; \
        (rect).width = _w; \
        (rect).height = _h; \
    } while (0)

/* effect parameters */
#define GUI_EFFECT_LIST_SLIDE_DURATION                  150
#define GUI_EFFECT_MAIN_MENU_MATRIX_SLIDE_DURATION      150

/* GUI effect time resolution unit */
#define GUI_EFFECT_TIME_UNIT                            50  
    
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    S32 x, y;
    S32 width, height;
} gui_rect;

typedef struct
{
    gui_rect    rect;
    PU8         image;
} gui_image_rect;

typedef enum
{
    GUI_EFFECT_FRAME_FIRST = 0,
    GUI_EFFECT_FRAME_LAST = -1
} gui_effect_frame_enum;

typedef enum
{
    GUI_EFFECT_STATE_READY,
    GUI_EFFECT_STATE_RUNNING,
    GUI_EFFECT_STATE_CANCEL,
    GUI_EFFECT_STATE_DONE
} gui_effect_state_enum;

typedef void (*gui_effect_funcptr_type)(S32, S32, S32, S32);

typedef struct
{
    S32 start_x, start_y, end_x, end_y;
    S32 old_x, old_y;
    S32 width, height;
    S32 frame_count;
    S32 current_frame_index;
    
    gui_effect_state_enum   state;

    S32 is_executed;

    gui_effect_funcptr_type finish_callback;
    gui_effect_funcptr_type show_callback;
    gui_effect_funcptr_type hide_callback;
} gui_effect_struct;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern S32 gui_rect_get_intersection(gui_rect *rect1, gui_rect *rect2, gui_rect *result_rect);
extern void gui_draw_image_with_alpha(S32 x, S32 y, gui_rect *out_rect, PU8 image, gdi_handle output_layer);

extern void gui_effect_set_blt_layer(void);
extern void gui_effect_restore_blt_layer(void);
extern void gui_effect_register_hide_callback(gui_effect_funcptr_type hide_cb);

extern void gui_effect_slide_create(S32 start_x, S32 start_y, S32 end_x, S32 end_y, S32 width, S32 height, S32 duration, gui_effect_funcptr_type show_cb, gui_effect_funcptr_type finish_cb, S32 start_frame_index);
extern void gui_effect_slide_close(void);
extern void gui_effect_slide_draw_last_frame(void);

extern void gui_effect_create(void);
extern void gui_effect_close(void);

#endif /* __GUI_EFFECT_OEM_H__ */

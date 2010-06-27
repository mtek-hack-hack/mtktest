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
 *   gui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Primitive UI variables & wrappers
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      gui.h
   Author:        manju
   Date Created:  August-13-2002
   Contains:      PixTel UI routines header
               Contains several parts and has been split to multiple
               code files. See other files named gui_*.c and gui_*.h
               This file contains common functions and data (prototypes only).
**********************************************************************************/

#ifndef __GUI_H__
#define __GUI_H__

#include "stdC.h"
#include "CustDataRes.h"
#include "gui_config.h"
#include "CustThemesRes.h"
#include "MMI_features.h"

#include "gui_resource_type.h"

#include "gdi_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* global device screen size                    */
    extern S32 UI_device_width;
    extern S32 UI_device_height;

    /* UI globals                                */
    extern S32 UI_clip_x1;
    extern S32 UI_clip_y1;
    extern S32 UI_clip_x2;
    extern S32 UI_clip_y2;
    extern S32 UI_old_clip_x1;
    extern S32 UI_old_clip_y1;
    extern S32 UI_old_clip_x2;
    extern S32 UI_old_clip_y2;
    extern S32 UI_text_x;
    extern S32 UI_text_y;
    extern S32 UI_text_height;
    extern S32 UI_pointer_x;
    extern S32 UI_pointer_y;
    extern color UI_text_color;
    extern color UI_text_border_color;
    extern U8 UI_printf_buffer[];

    /* MACRO:   calculates the percentage              */
#define pixtel_percent(x,p)   ((x)*(p)/(100))

    /* MACRO:   toggles a value                        */
#define pixtel_toggle(x)   x=(U8)((x)?0:1)

    /* MACRO:   divides, adds 1 if there is a remainder      */
#define pixtel_highdivide(x,y)   ((((x)%(y))>0)?(((x)/(y))+1):((x)/(y)))

    /* Base functions required by the UI system:    */
    /* All UI components will use these functions      */
    /* And will not directly use any other OS/system   */
    /* related functions.                        */

    extern void (*gui_putpixel) (S32 x, S32 y, color c);
    extern void (*gui_draw_vertical_line) (S32 y1, S32 y2, S32 x, color c);
    extern void (*gui_draw_vert_line_type) (S32 y1, S32 y2, S32 x, color c, S32 type_line);
    extern void (*gui_draw_hori_line_type) (S32 x1, S32 x2, S32 y, color c, S32 type_line);
    extern void (*gui_draw_rectangle_type) (S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 type_line);
    extern void (*gui_draw_horizontal_line) (S32 x1, S32 x2, S32 y, color c);
    extern void (*gui_line) (S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern void (*gui_wline) (S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 w);
    extern void (*gui_draw_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern void (*gui_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern void (*gui_cross_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern void (*gui_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern void (*gui_alternate_cross_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2);
    extern void (*gui_alternate_hatch_fill_rectangle) (S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2);

    extern void (*gui_set_text_clip) (S32 x1, S32 y1, S32 x2, S32 y2);
    extern void (*gui_get_text_clip) (S32 *x1, S32 *y1, S32 *x2, S32 *y2);
    extern void (*gui_set_text_clip_preset) (S32 x1, S32 y1, S32 x2, S32 y2);
    extern void (*gui_set_clip) (S32 x1, S32 y1, S32 x2, S32 y2);
    extern void (*gui_set_clip_with_bounding_box) (S32 x1, S32 y1, S32 x2, S32 y2, S32 bx1, S32 by1, S32 bx2, S32 by2);
    extern void (*gui_get_clip) (S32 *x1, S32 *y1, S32 *x2, S32 *y2);
    extern void (*gui_set_clip_preset) (S32 x1, S32 y1, S32 x2, S32 y2);
    extern void (*gui_reset_clip) (void);
    extern void (*gui_push_text_clip) (void);
    extern void (*gui_pop_text_clip) (void);
    extern void (*gui_push_clip) (void);
    extern void (*gui_pop_clip) (void);
    extern void (*gui_reset_text_clip) (void);

    extern void (*gui_set_line_height) (S32 height);
    extern void (*gui_move_text_cursor) (S32 x, S32 y);
    extern void (*gui_set_text_color) (color c);
    extern void (*gui_set_text_border_color) (color c);
    extern S32(*gui_printf) (const S8 *format, ...);
    extern S32(*gui_sprintf) (UI_string_type _text, const S8 *format, ...);
    extern void (*gui_print_text) (UI_string_type _text);
    extern void (*gui_print_text_n) (UI_string_type _text, int _n);
    extern void (*gui_print_bordered_text_n) (UI_string_type _text, int _n);
    extern void (*gui_print_bordered_text) (UI_string_type _text);
    extern void (*gui_print_character) (UI_character_type _c);
    extern void (*gui_print_character_at_xy) (UI_character_type c, S32 x, S32 y);
    extern void (*gui_print_stacked_character) (UI_character_type _curCh, UI_character_type _pre2Ch,
                                                UI_character_type _preCh);
    extern void (*gui_print_bordered_stacked_character) (UI_character_type _curCh, UI_character_type _pre2Ch,
                                                         UI_character_type _preCh);

    extern void (*gui_print_bordered_character) (UI_character_type _c);

    extern U8 gui_print_truncated_text2(S32 x, S32 y, S32 xwidth, UI_string_type *s);
    extern U8 gui_print_truncated_bordered_text2(S32 x, S32 y, S32 xwidth, UI_string_type *s);

    extern void *(*gui_malloc) (size_t size);
    extern void (*gui_free) (void *ptr);

    extern S32(*gui_get_character_width) (UI_character_type c);
    extern void (*gui_measure_character) (UI_character_type c, S32 *width, S32 *height);
    extern S32(*gui_get_character_height) (void);
    extern S32(*gui_get_string_width) (UI_string_type text);
    extern S32(*gui_get_string_width_n) (UI_string_type text, S32 n);
    extern S32(*gui_get_string_width_w) (UI_string_type text, S32 w);
    extern S32(*gui_get_string_width_wn) (UI_string_type text, S32 w, S32 n);
    extern S32(*gui_get_string_height) (UI_string_type text);
    extern void (*gui_measure_string) (UI_string_type text, S32 *width, S32 *height);
    extern void (*gui_measure_string_n) (UI_string_type text, S32 n, S32 *width, S32 *height);
    extern void (*gui_measure_string_w) (UI_string_type text, S32 w, S32 *width, S32 *height);
    extern void (*gui_measure_string_wn) (UI_string_type text, S32 w, S32 n, S32 *width, S32 *height);

    extern void (*gui_set_font) (UI_font_type f);
    extern void (*gui_show_image) (S32 x, S32 y, PU8 i);
    extern void (*gui_show_transparent_image) (S32 x, S32 y, PU8 i, UI_transparent_color_type t);
    extern void (*gui_measure_image) (PU8 i, S32 *width, S32 *height);
    extern S32(*gui_image_n_frames) (PU8 i);
    extern void (*gui_start_timer) (S32 count, void (*callback) (void));
    extern void (*gui_cancel_timer) (void (*callback) (void));
    extern void (*gui_hide_animated_image) (S32 x, S32 y, UI_animated_image_handle i);
    extern void (*gui_register_hide_animation_frame) (UI_animated_image_handle i,
                                                      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
    extern U8(*gui_show_transparent_animated_image_frame) (S32 x, S32 y, PU8 i, UI_transparent_color_type t,
                                                           S16 frame_number);
    extern U8(*gui_show_animated_image_frame) (S32 x, S32 y, PU8 i, S16 frame_number);
    extern void (*gui_hide_animations) (void);

    /* extern UI_animated_image_handle              (*gui_show_transparent_animated_image)(S32 x,S32 y,PU8 i,UI_transparent_color_type t); */
    extern UI_animated_image_handle(*gui_show_transparent_animated_image_frames) (S32 x, S32 y, PU8 i,
                                                                                  UI_transparent_color_type t,
                                                                                  S16 start_frame, S16 end_frame);
    /* extern UI_animated_image_handle              (*gui_show_animated_image)(S32 x,S32 y,PU8 i); */
    extern UI_transparent_color_type(*gui_transparent_color) (U8 r, U8 g, U8 b);
    extern color(*gui_color) (U8 r, U8 g, U8 b);
    extern color(*gui_color32) (U8 r, U8 g, U8 b, U8 alpha);
    extern void (*gui_color_RGB) (color c, U8 *r, U8 *g, U8 *b);
    extern UI_string_type(*gui_strcpy) (UI_string_type text1, UI_string_type text2);
    extern UI_string_type(*gui_strncpy) (UI_string_type text1, UI_string_type text2, S32 n);
    extern S32(*gui_strcmp) (UI_string_type text1, UI_string_type text2);
    extern S32(*gui_strlen) (UI_string_type text);
    extern S32(*gui_strncmp) (UI_string_type text1, UI_string_type text2, S32 n);
    extern UI_string_type(*gui_strcat) (UI_string_type text1, UI_string_type text2);
    extern UI_string_type(*gui_itoa) (S32 value, UI_string_type s, S32 radix);
    extern S32(*gui_atoi) (UI_string_type s);
    extern void *(*gui_memcpy) (void *d, const void *s, S32 n);
    extern UI_character_type(*gui_get_next_character) (UI_string_type *s);
    extern UI_character_type(*gui_get_previous_character) (UI_string_type *s);

    /* Double buffer */
    extern void (*gui_BLT_double_buffer) (S32 x1, S32 y1, S32 x2, S32 y2);
    extern void (*gui_lock_double_buffer) (void);
    extern void (*gui_unlock_double_buffer) (void);

    /* Layout */
    extern void gui_setup_default_layout(void);
    extern void gui_setup_common_layout(void);
    extern void gui_setup_mainmenu_layout(void);
    extern void gui_setup_submenu_layout(void);

    /* Right-to-left flag */
    extern BOOL r2lMMIFlag;

    /* Some standard functions: Need to be implemented through wrappers.    */
    /* See the character set support functions, gui_get_next_character   */
    /* and gui_get_previous_character                           */

    extern U8 gui_linebreak_character(UI_character_type c);
    extern U8 gui_endofstring_character(UI_character_type c);

    extern color gui_blend_two_color(color c1, color c2, S32 weight1, S32 weight2);

#define  UI_GRADIENT_COLOR_VERTICAL          0x00000100
#define  UI_GRADIENT_COLOR_HORIZONTAL        0x00000000
#define UI_GRADIENT_COLOR_FLIP               0x00000200

    extern void gui_initialize_gradient_color(gradient_color *gc, color *c, U8 *p, U8 n);
    extern void gui_gradient_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, gradient_color *gc, U32 flags);

    /* Filled Area border theme                  */
    typedef struct _UI_filled_area_border_theme
    {
        color filled_area_outer_light_border;
        color filled_area_inner_light_border;
        color filled_area_outer_dark_border;
        color filled_area_inner_dark_border;
    } UI_filled_area_border_theme;

    extern UI_filled_area_border_theme *current_filled_area_border_theme;

    /*
     * UI filled area structure
     * -------------------
     * bits 0-7:         filler types
     * bit    8:            1=vertical filler, 0=horizontal filler (used for gradients and textures)
     * bit  9:           flip filler
     * bit    10:        (reserved)
     * bit  11:       (reserved)
     * bit    12:        border yes/no
     * bit  13:       border size 0=single line, 1=double line
     * bit  14:       3D border
     * bit  15:       rounded border
     * bit    16:        1=elevated border, 0=depressed border
     * bit    17:        1=filled area with shadow
     * bit  18:            1=filled area with double line shadow, 0=single line shadow
     * bit  19:       (reserved)
     * bit  20:       left rounded border
     * bit  21:       right rounded border
     * bit  22:       Draw only horizontal lines in borders
     * bit  24:       transparent color
     */

    /* Bits 0-7: filler type */
#define UI_FILLED_AREA_MASK_TYPE                            0x000000FF
    /* --- */
#define UI_FILLED_AREA_TYPE_COLOR                           0x00000000
#define UI_FILLED_AREA_TYPE_GRADIENT_COLOR                  0x00000001
#define UI_FILLED_AREA_TYPE_TEXTURE                         0x00000002
#define UI_FILLED_AREA_TYPE_BITMAP                          0x00000003
#define UI_FILLED_AREA_TYPE_HATCH_COLOR                     0x00000004
#define UI_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR           0x00000005
#define UI_FILLED_AREA_TYPE_CROSS_HATCH_COLOR               0x00000006
#define UI_FILLED_AREA_TYPE_ALTERNATE_CROSS_HATCH_COLOR     0x00000007
#define UI_FILLED_AREA_TYPE_NO_BACKGROUND                   0x00000008
#define UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1               0x00000009  /* Popup description 1 */
#define UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE2               0x0000000A  /* Popup description 2 */
#define UI_FILLED_AREA_TYPE_3D_BORDER                       0x0000000B

    /* Bit 8: horiztonal or vertical fill for gradient color */
#define UI_FILLED_AREA_MASK_FILL_DIRECTION                  0x00000100
    /* --- */
#define UI_FILLED_AREA_HORIZONTAL_FILL                      0x00000000
#define UI_FILLED_AREA_VERTICAL_FILL                        0x00000100

    /* Bit 9: flip fill or not */
#define UI_FILLED_AREA_FLIP_FILL                            0x00000200

    /* Bits 12-13: single-double-border */
#define UI_FILLED_AREA_MASK_BORDER_WIDTH                    0x00003000
    /* --- */
#define UI_FILLED_AREA_TYPE_NO_BORDER                       0x00000000
#define UI_FILLED_AREA_BORDER                               0x00001000
#define UI_FILLED_AREA_SINGLE_BORDER                        0x00001000  /* Contain UI_FILLED_AREA_BORDER */
#define UI_FILLED_AREA_DOUBLE_BORDER                        0x00003000  /* Contain UI_FILLED_AREA_BORDER */

    /* Bits 14: 3D border */
#define UI_FILLED_AREA_3D_BORDER                            0x00004000

    /* Bits 15: Rounded border */
#define UI_FILLED_AREA_ROUNDED_BORDER                       0x00008000

    /* Bits 16: Elevated or depressed border */
#define UI_FILLED_AREA_MASK_ELEVATION                       0x00010000
    /* --- */
#define UI_FILLED_AREA_ELEVATED_BORDER                      0x00010000
#define UI_FILLED_AREA_DEPRESSED_BORDER                     0x00000000

    /* Combination of Bit 14 and 16 */
#define UI_FILLED_AREA_3D_ELEVATED_BORDER                   (UI_FILLED_AREA_ELEVATED_BORDER | UI_FILLED_AREA_3D_BORDER)
#define UI_FILLED_AREA_3D_DEPRESSED_BORDER                  (UI_FILLED_AREA_DEPRESSED_BORDER | UI_FILLED_AREA_3D_BORDER)

    /* Bits 17-18: single-double-shadown */
#define UI_FILLED_AREA_MASK_SHADOW                          0x00060000
    /* --- */
#define UI_FILLED_AREA_SHADOW                               0x00020000
#define UI_FILLED_AREA_SHADOW_DOUBLE_LINE                   0x00040000

    /* Bit 20: Left rounded border for Dalmatian style */
#define UI_FILLED_AREA_LEFT_ROUNDED_BORDER                  0x00100000

    /* Bit 21: Right rounded border for Dalmatian style */
#define UI_FILLED_AREA_RIGHT_ROUNDED_BORDER                 0x00200000

    /* Bit 22: Draw only horizontal lines w/o vertical lines in UI_FILLED_AREA_BORDER */
#define UI_FILLED_AREA_NO_VERTICAL_LINE                     0x00400000

    /* Bit 24: Transparent color filler */
#define UI_FILLED_AREA_TYPE_TRANSPARENT_COLOR               0x01000000

    extern UI_filled_area *current_UI_filler;

    //PMT VIKAS START 20050520
    //PMT VIKAS START 20051217
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) || defined(__MMI_UI_TRANSPARENT_EFFECT_IN_DALMATIAN_CALENDAR__) || defined (UI_SCROLLBAR_STYLE_4)      /* 072505 Calvin modified */
    /* PMT VIKAS END 20051217 */
    extern void gui_fill_transparent_color(S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern void gui_transparent_color_filler(S32 x1, S32 y1, S32 x2, S32 y2, color c);
    extern U8 gui_transparent_color_part_value(S32 color_value, S32 opacity_value);
    extern void gui_set_transparent_source_layer(S32);
    extern gdi_handle gui_get_transparent_source_layer(void);   /* 110705 WAP menu Clavin add */
    extern void gui_reset_transparent_source_layer(void);

    /* PMT VIKAS START 20050630 */
    extern S32 gui_is_current_transparency_with_multi_layer(void);
    /* PMT VIKAS END 20050630 */
#endif /* defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) || defined(__MMI_UI_TRANSPARENT_EFFECT_IN_DALMATIAN_CALENDAR__) || defined (UI_SCROLLBAR_STYLE_4) */ 
    //PMT VIKAS END
    //PMT VIKAS START 20050707
    extern void gui_fill_left_rounded_border(S32 rx1, S32 ry1, S32 rx2, S32 ry2, UI_filled_area *f);
    extern void gui_fill_right_rounded_border(S32 rx1, S32 ry1, S32 rx2, S32 ry2, UI_filled_area *f);
    /* PMT VIKAS END 20050707 */
    extern void gui_shadow_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
    extern void gui_draw_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);

    /* void gui_greyscale_rectangle(S32 x1,S32 y1,S32 x2,S32 y2, S32 white_value); */
    extern void gui_greyscale_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, S32 white_value, S32 black_value);      /* 102605 greyscale Calvin chnaged */

    /* PMT HIMANSHU START 20050916 */

    typedef enum
    {
        MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_LEFT = 0,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_TOP_RIGHT,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_LEFT,
        MMI_GRADIENT_RECT_ROUNDED_CORNER_BOTTOM_RIGHT
    } mmi_gradient_rect_rounded_corner_style_enum;

    extern void gui_draw_rounded_corner(
                    S32 x1,
                    S32 y1,
                    S32 size,
                    color rect_color_start,
                    color rect_color_end,
                    S32 levle,
                    mmi_gradient_rect_rounded_corner_style_enum corner_style);

    extern void gui_draw_gradient_rounded_rectangle(
                    S32 x1,
                    S32 y1,
                    S32 x2,
                    S32 y2,
                    color start_color,
                    color end_color,
                    S32 border_width);

    /* PMT HIMANSHU END 20050916 */

    typedef struct _UI_HLS_color
    {
        /* Hue */
        U16 h;  /* 0-360 */
        /* Lightness */
        U8 l;   /* 0-255 */
        /* Saturation */
        U8 s;   /* 0-255 */
    } UI_HLS_color;
    extern void gui_RGB_to_HLS(color rgb, UI_HLS_color *hls);
    extern void gui_HLS_to_RGB(UI_HLS_color hls, color *rgb);

    /* UI object co-ordinates structure       */

    typedef struct _UI_object_coordinates
    {
        S32 x;
        S32 y;
        S32 width;
        S32 height;
    } UI_object_coordinates;

    /* Dummy functions called by UI elements by default, during events
       Do not remove any of these functions.  */

    extern void UI_dummy_function(void);
    extern void UI_dummy_function_byte(U8 a);
    extern void UI_dummy_function_s32(S32 a);
    extern void UI_dummy_function_character(UI_character_type c);

    /* Functions for switching graphics context  */

    extern void UI_set_main_LCD_graphics_context(void);
    extern void UI_set_sub_LCD_graphics_context(void);
    extern U8 UI_test_sub_LCD_graphics_context(void);

    /* Function to print truncated text */
    extern void gui_print_truncated_text(S32 x, S32 y, S32 xwidth, UI_string_type s);
    extern void gui_print_truncated_borderd_text(S32 x, S32 y, S32 xwidth, UI_string_type s);

    /* Functions to print texts by forcing the reading direction */
    extern void gui_print_text_by_direction(UI_string_type str);
    extern void gui_print_bordered_text_by_direction(UI_string_type str);

    /* Common string macros */

#ifdef __ASCII

#define UI_STRING_GET_NEXT_CHARACTER(p,c)                                                 \
      {                                                                                   \
         (c)=*((U8*)(p))++;                                                               \
      }

#define UI_STRING_GET_PREVIOUS_CHARACTER(p,c)                                                \
      {                                                                                      \
         (c)=*(--((U8*)(p)));                                                                \
      }

#define UI_STRING_INSERT_CHARACTER(p,c)                                                      \
      {                                                                                      \
         *((U8*)(p))++=(c);                                                                  \
      }

#endif /* __ASCII */ 

#ifdef __UCS2_ENCODING

    /* Warning: Currently, these macros assume Little endian format only */

#define UI_STRING_GET_NEXT_CHARACTER(p,c)                                                    \
      {                                                                                      \
         c=(UI_character_type)((*((p)+0))|((*((p)+1))<<8));                                  \
         (p)+=2;                                                                             \
      }

#define UI_STRING_GET_PREVIOUS_CHARACTER(p,c)                                                \
      {                                                                                      \
         p-=2;                                                                               \
         c=(UI_character_type)((*((p)+0))|((*((p)+1))<<8));                                  \
      }

#define UI_STRING_INSERT_CHARACTER(p,c)                                                      \
      {                                                                                      \
         (*((p))++)=(U8)(((c)&0xff));                                                        \
         (*((p))++)=(U8)(((c)>>8));                                                          \
      }

#endif /* __UCS2_ENCODING */ 

#define UI_TEST_CR_CHARACTER1(c)              (((UI_character_type)(c)==(UI_character_type)0x0D)?(1):(0))
#define UI_TEST_CR_CHARACTER(c)               (((*(UI_character_type*)&(c))==(UI_character_type)0x0D)?(1):(0))

#define UI_TEST_LF_CHARACTER1(c)              (((UI_character_type)(c)==(UI_character_type)0x0A)?(1):(0))
#define UI_TEST_LF_CHARACTER(c)               (((*(UI_character_type*)&(c))==(UI_character_type)0x0A)?(1):(0))

#define UI_TEST_ESC_CHARACTER1(c)             (((UI_character_type)(c)==(UI_character_type)0x1B)?(1):(0))
#define UI_TEST_ESC_CHARACTER(c)              (((*(UI_character_type*)&(c))==(UI_character_type)0x1B)?(1):(0))


#define UI_STRING_LINE_BREAK_CHARACTER1(c)    (((UI_character_type)(c)==(UI_character_type)'\n')?(1):(0))
#define UI_STRING_LINE_BREAK_CHARACTER(c)     (((*(UI_character_type*)&(c))==(UI_character_type)'\n')?(1):(0))


#define UI_STRING_END_OF_STRING_CHARACTER1(c) (((UI_character_type)(c)==(UI_character_type)'\0')?(1):(0))
#define UI_STRING_END_OF_STRING_CHARACTER(c)  (((*(UI_character_type*)&(c))==(UI_character_type)'\0')?(1):(0))


#define UI_STRING_SPACE_CHARACTER1(c)         (((UI_character_type)(c)==(UI_character_type)' ')?(1):(0))
#define UI_STRING_SPACE_CHARACTER(c)          (((*(UI_character_type*)&(c))==(UI_character_type)' ')?(1):(0))


#define UI_TEST_8895_1_CHAR_IN_GSM_DEF_CHAR(c)  (((c)==163 ||(c)==165 || (c)==232 ||(c)==233 ||(c)==249 ||(c)==236 ||(c)==242 ||(c)==199 ||(c)==216 ||(c)==248 ||(c)==197 ||(c)==229 ||(c)==198 ||(c)==230 ||(c)==223 ||(c)==200 ||(c)==164 ||(c)==161 ||(c)==196 ||(c)==214 ||(c)==209 ||(c)==220 ||(c)==167 ||(c)==191 ||(c)==228 ||(c)==246 ||(c)==241 ||(c)==252 ||(c)==224)?(1):(0))

#define UI_TEST_UCS2_CHARACTER(c)            ((((c)&0xff80) && ( !UI_TEST_8895_1_CHAR_IN_GSM_DEF_CHAR(c)))?(1):(0))

#define UI_TEST_UCS2_INCREMENT_COUNT(c,count)   if(UI_TEST_UCS2_CHARACTER(c)) ((count)++)

#define UI_TEST_UCS2_DECREMENT_COUNT(c,count)   if(UI_TEST_UCS2_CHARACTER(c) && ((count)>0)) ((count)--)

#define UI_UCS2_STRING_HALF_LENGTH(x)        (((x)&3)?(((x)>>1)+1):((x)>>1))

    /* For Phone Book Name Length */
    // #define UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(x)      (((x)&3)?(((x)>>1)-1):(((x)>>1)-2))
#define UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(x) (((x)&3)?(((x)>>1)-1):(((x)>>1)))

#define UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(x) (((x)&3)?(((x)>>1)-87):(((x)>>1)-88))

#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length)                   \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                             \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH(allocated_length);                  \
            (count)++;                                                                             \
         }                                                                                         \
      }

    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(c,count,allocated_length,length)                \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                                \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(allocated_length);           \
            (count)++;                                                                                \
         }                                                                                            \
      }
    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(c,count,allocated_length,length)                      \
      {  if(UI_TEST_UCS2_CHARACTER(c))                                                                      \
         {  if((count)==0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(allocated_length);           \
            (count)++;                                                                                      \
         }                                                                                                  \
      }

#define UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length)                   \
      {  if(UI_TEST_UCS2_CHARACTER(c) && ((count)>0))                                              \
         {  ((count)--);                                                                           \
            if((count)==0) (length)=(allocated_length);                                            \
         }                                                                                         \
      }

#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(old_c,c,count,allocated_length,length)                   \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c,count,allocated_length,length);                    \
      }

    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(old_c,c,count,allocated_length,length)             \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(c,count,allocated_length,length);              \
      }

    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(old_c,c,count,allocated_length,length)             \
      {  UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(old_c,count,allocated_length,length);                \
         UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(c,count,allocated_length,length);              \
      }

#define UI_TEST_UCS2_COUNT_SET_LENGTH(count,allocated_length,length)                            \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH(allocated_length);                   \
      }

    /* Added for n/2-1 Chinese characters input mode   */
#define UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE2(count,allocated_length,length)                            \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(allocated_length);               \
      }

    /* Added for n/2-44 Chinese characters input mode  */
#define UI_TEST_UCS2_COUNT_SET_LENGTH_TYPE3(count,allocated_length,length)                                  \
      {  if((count)>0) (length)=UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(allocated_length);               \
      }

    extern void UI_disable_alignment_timers(void);
    extern void UI_enable_alignment_timers(void);

    /* Page break character equivalent needs to be added  */
    /* Euro character equivalent = 0xA2             */

#define UI_TEST_GSM_EXTENDED(c)     \
(     (c==0xA2)                     \
   || (c=='^')                      \
   || (c=='{')                      \
   || (c=='}')                      \
   || (c=='\\')                     \
   || (c=='[')                      \
   || (c=='~')                      \
   || (c==']')                      \
   || (c=='|')                      \
)                                   \

    /* 
     * Painter Component: encapsulates various painting operations with common interface
     */

    /* Custom-defined callback type to draw a rectangle region 
       (x, y) is the left-top corner of drawing
       (clip_x1, clip_y1, clip_x2, clip_y2) is the clipping area. */
    typedef void (*gui_util_painter_callback_type)(
                    S32 x, 
                    S32 y, 
                    S32 clip_x1, 
                    S32 clip_y1, 
                    S32 clip_x2, 
                    S32 clip_y2);

    /* Types of painting operations */
    typedef enum 
    {
        /* Do nothing */
        GUI_UTIL_PAINTER_TYPE_EMPTY = 0,
        /* Fill transparent color */
        GUI_UTIL_PAINTER_TYPE_TRANSPARENT,
        /* Draw an image */
        GUI_UTIL_PAINTER_TYPE_IMAGEID,
        /* Call a custom-defined callback routine */
        GUI_UTIL_PAINTER_TYPE_CALLBACK,
        /* Use a filler */
        GUI_UTIL_PAINTER_TYPE_FILLER,
        /* Last dummy enum type */
        GUI_UTIL_PAINTER_TYPE_END_OF_ENUM
    } gui_util_painter_type_enum;

    /* Painter UI component */
    typedef struct
    {
        gui_util_painter_type_enum type;
        union
        {
            MMI_ID_TYPE imageid;
            gui_util_painter_callback_type callback;
            const UI_filled_area *filler;
        } _u;
    } gui_util_painter_struct;

    extern void gui_util_painter_create_empty(gui_util_painter_struct *p);
    extern void gui_util_painter_create_transparent(gui_util_painter_struct *p);
    extern void gui_util_painter_create_imageid(
                    gui_util_painter_struct *p, 
                    MMI_ID_TYPE imageid);
    extern void gui_util_painter_create_callback(
                    gui_util_painter_struct *p, 
                    gui_util_painter_callback_type callback);
    extern void gui_util_painter_create_filler(
                    gui_util_painter_struct *p, 
                    const UI_filled_area *filler);

    extern void gui_util_painter_show_clipped(
        const gui_util_painter_struct *p, 
        S32 x, 
        S32 y, 
        S32 clip_x1, 
        S32 clip_y1, 
        S32 clip_x2, 
        S32 clip_y2);
        
    extern void gui_util_painter_show(const gui_util_painter_struct *p, S32 x1, S32 y1, S32 x2, S32 y2);

    /* 
     * Clean-up of GUI components 
     * To avoid clean-up each UI component explicitly in WGUI/draw manager/widget, 
     * general cleanup mechanism is provided here.
     */

#define GUI_MAX_CLEANUP_HOOK  16

    typedef void (*gui_cleanup_hook_hdlr) (void);

    extern void gui_add_cleanup_hook(gui_cleanup_hook_hdlr fp);
    extern void gui_remove_cleanup_hook(gui_cleanup_hook_hdlr fp);
    extern void gui_cleanup(void);

    /* PMT VIKAS START 20051209 */
    /* Pre cleanup functions for GUI components */

    typedef void (*gui_pre_cleanup_hook_hdlr) (void);

    extern void gui_add_pre_cleanup_hook(gui_cleanup_hook_hdlr fp);
    extern void gui_remove_pre_cleanup_hook(gui_cleanup_hook_hdlr fp);
    extern void gui_pre_cleanup(void);
    /* PMT VIKAS END 20051209 */
    /* Touch Panel Events */

    typedef enum
    {
        GUI_PEN_EVENT_PARAM_VOID,
        GUI_PEN_EVENT_PARAM_INTEGER,
        GUI_PEN_EVENT_PARAM_INTEGER2,
        GUI_PEN_EVENT_PARAM_INTEGER3,
        GUI_PEN_EVENT_PARAM_POINTER,
        GUI_PEN_EVENT_PARAM_POINTER_INTEGER,
        GUI_PEN_EVENT_PARAM_POINTER_INTEGER2
    } gui_pen_event_param_enum;

    typedef struct _mmi_gui_pen_event_param_struct
    {
        gui_pen_event_param_enum type;
        union
        {
            int i;
            void *p;
        } _u;
        int i2;
        int i3;
    } gui_pen_event_param_struct;

#define GUI_PEN_EVENT_PARAM_SET_VOID(_s) do {_s->type = GUI_PEN_EVENT_PARAM_VOID;} while (0)

#define GUI_PEN_EVENT_PARAM_SET_INTEGER(_s, _i) do {_s->type = GUI_PEN_EVENT_PARAM_INTEGER;  \
                                                   _s->_u.i = _i;                            \
                                                   } while (0)

#define GUI_PEN_EVENT_PARAM_SET_INTEGER2(_s, _i, _i2) do {_s->type = GUI_PEN_EVENT_PARAM_INTEGER2; \
                                                   _s->_u.i = _i;                                  \
                                                   _s->i2 = _i2;                                   \
                                                   } while (0)

#define GUI_PEN_EVENT_PARAM_SET_INTEGER3(_s, _i, _i2, _i3) do {_s->type = GUI_PEN_EVENT_PARAM_INTEGER3;  \
                                                   _s->_u.i = _i;                                        \
                                                   _s->i2 = _i2;                                         \
                                                   _s->i3 = _i3;                                         \
                                                   } while (0)

#define GUI_PEN_EVENT_PARAM_SET_POINTER(_s, _p) do {_s->type = GUI_PEN_EVENT_PARAM_POINTER;  \
                                                   _s->_u.p = _p;                            \
                                                   } while (0)

#define GUI_PEN_EVENT_PARAM_SET_POINTER_INTEGER(_s, _p, _i2) do {_s->type = GUI_PEN_EVENT_PARAM_POINTER_INTEGER;  \
                                                   _s->_u.p = _p;                                                 \
                                                   _s->i2 = _i2;                                                  \
                                                   } while (0)

#define GUI_PEN_EVENT_PARAM_SET_POINTER_INTEGER2(_s, _p, _i2, _i3) do {_s->type = GUI_PEN_EVENT_PARAM_POINTER_INTEGER2; \
                                                   _s->_u.p = _p;                                                       \
                                                   _s->i2 = _i2;                                                        \
                                                   _s->i3 = _i3;                                                        \
                                                   } while (0)

#ifdef __cplusplus
}
#endif 

#endif /* __GUI_H__ */ 


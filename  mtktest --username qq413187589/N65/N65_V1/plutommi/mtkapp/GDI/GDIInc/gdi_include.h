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
 *  gdi_include.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Include file for full set GDI function.
 *
 * Author:
 * -------
 * -------
 * -------
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_INCLUDE_H_
#define _GDI_INCLUDE_H_

#define act_bit_per_pixel           bits_per_pixel
#define act_buf_ptr              buf_ptr
#define act_pitch                width
#define act_rows                 height



/* those function will be out-of-date. */
#define gdi_layer_clear_background gdi_layer_clear
#define gdi_image_gif_draw_java     gdi_image_gif_draw_with_background_color

#define gdi_layer_get_text_clip     gdi_layer_get_clip
#define gdi_layer_set_text_clip     gdi_layer_set_clip
#define gdi_layer_reset_text_clip      gdi_layer_reset_clip
#define gdi_layer_push_text_clip    gdi_layer_push_clip
#define gdi_layer_pop_text_clip     gdi_layer_pop_clip

#include "gdi_features.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_lcd_config.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GENERAL API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern void gdi_init(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PIXEL INFORMATION
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GDI_MAINLCD_BIT_PER_PIXEL                  DRV_MAINLCD_BIT_PER_PIXEL
#ifdef __MMI_SUBLCD__
#define GDI_SUBLCD_BIT_PER_PIXEL                   DRV_SUBLCD_BIT_PER_PIXEL
#endif 
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PRIMITIVE API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern U32 gdi_rgb565_to_rgb888(U32 p);
extern void gdi_draw_point(S32 x, S32 y, gdi_color pixel_color);
extern void gdi_draw_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color);
extern void gdi_draw_line_style(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color, U8 cycle, const U8 *bitvalues);
extern void gdi_draw_antialiasing_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color);
extern void gdi_draw_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color);
extern void gdi_draw_solid_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color);
extern void gdi_draw_circle(S32 x, S32 y, S32 r, gdi_color circle_color);
extern void gdi_draw_solid_circle(S32 x, S32 y, S32 r, gdi_color circle_color);
extern void gdi_draw_arc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color);
extern void gdi_draw_solid_arc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color);

extern void gdi_draw_frame_rect(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                gdi_color rect_color,
                gdi_color frame_color,
                S32 frame_width);
extern void gdi_draw_round_rect(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                gdi_color rect_color,
                gdi_color frame_color,
                S32 frame_width);
extern void gdi_draw_button_rect(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                gdi_color rect_color,
                gdi_color frame_color,
                U16 frame_width,
                U16 button_height,
                BOOL invert);
extern void gdi_draw_shadow_rect(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                gdi_color rect_color,
                gdi_color frame_color,
                S32 frame_width,
                gdi_color shadow_color,
                S32 shadow_height);
extern void gdi_draw_gradient_rect(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                gdi_color rect_color_start,
                gdi_color rect_color_end,
                gdi_color frame_color,
                S32 frame_width,
                gdi_gradient_rect_style_enum style);
extern void gdi_draw_darken_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 brightness_value);                
extern void gdi_draw_greyscale_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 white_value, S32 black_value);
extern void gdi_effect_alpha_blending_rect(
                gdi_handle src_layer_handle,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                U32 transparent_color_a,
                U32 transparent_color_r,
                U32 transparent_color_g,
                U32 transparent_color_b);
extern void gdi_2d_memory_blt(
                U8 *src_ptr,
                S32 src_pitch,
                S32 src_offset_x,
                S32 src_offset_y,
                S32 src_width,
                S32 src_height,
                U8 *dest_ptr,
                S32 dest_pitch,
                S32 dest_offset_x,
                S32 dest_offset_y,
                gdi_rect_struct dest_clip,
                S32 bits_per_pixel);

extern void gdi_2d_memory_blt_without_transpant_check(
                U8 *src_ptr,
                S32 src_pitch,
                S32 src_offset_x,
                S32 src_offset_y,
                S32 src_width,
                S32 src_height,
                U8 *dest_ptr,
                S32 dest_pitch,
                S32 dest_offset_x,
                S32 dest_offset_y,
                gdi_rect_struct dest_clip,
                S32 bits_per_pixel);
extern void gdi_fill_dot_rect(S32 x1,S32 y1,S32 x2,S32 y2,gdi_color c);
extern void gdi_bitblt_internal(U8* src_ptr, U32 src_pitch, 
			S32 src_offset_x, S32 src_offset_y, 
			U32 src_width, U32 src_height,
			gdi_color_format src_cf,
			U8* dest_ptr, U32 dest_pitch,
			S32 dest_offset_x, S32 dest_offset_y,
			S32 dest_clip_x1, S32 dest_clip_y1, S32 dest_clip_x2, S32 dest_clip_y2,
			gdi_color_format dest_cf, U32 dest_buf_size,
			BOOL tilt,
			BOOL enable_src_key, gdi_color src_key,
			BOOL is_alpha_blending, U8 alpha_value,
			BOOL is_rop_mode, U8 rop_value,
			U8 transform_value,
			U8 transform_direction);
extern void gdi_bits_draw(S32 x,S32 y,U8* src,S32 src_size,S32 w,S32 h,S32 bits_per_pixel,gdi_color palette[]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// MUTEX API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef GDI_USING_MUTEX
#define GDI_LOCK     gdi_fast_mutex_lock()
#define GDI_UNLOCK      gdi_fast_mutex_unlock()
#define GDI_UNLOCK_N(N) while(N< gdi_mutex.cnt) {gdi_fast_mutex_unlock();}
#else /* GDI_USING_MUTEX */ 
#define GDI_LOCK
#define GDI_UNLOCK
#define GDI_UNLOCK_N(N)
#endif /* GDI_USING_MUTEX */ 

extern void gdi_fast_mutex_lock(void);
extern void gdi_fast_mutex_unlock(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// COLOR API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GDI_COLOR_WHITE       gdi_act_color_from_rgb(255, 255, 255, 255)
#define GDI_COLOR_BLACK       gdi_act_color_from_rgb(255, 0, 0, 0)
#define GDI_COLOR_GRAY           gdi_act_color_from_rgb(255, 127, 127, 127)
#define GDI_COLOR_RED            gdi_act_color_from_rgb(255, 255,    0,     0)
#define GDI_COLOR_BLUE           gdi_act_color_from_rgb(255,    0,     0, 255)
#define GDI_COLOR_GREEN       gdi_act_color_from_rgb(255,    0, 255,      0)

#ifdef GDI_USING_LAYER
#define GDI_COLOR_TRANSPARENT    gdi_act_color_from_rgb(0,    0,     0, 255)
#else
#define GDI_COLOR_TRANSPARENT    gdi_act_color_from_rgb(255,    255,     255, 255)
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// LAYER API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GDI_LAYER_EMPTY_HANDLE               (0)        /* handle 0 is empty handle, not used */
#define GDI_LAYER_MEDIA_HW_TRIGGER_LAYER     (1)

#define GDI_LAYER_ENABLE_LAYER_0       LCD_LAYER0_ENABLE
#define GDI_LAYER_ENABLE_LAYER_1       LCD_LAYER1_ENABLE
#define GDI_LAYER_ENABLE_LAYER_2       LCD_LAYER2_ENABLE
#define GDI_LAYER_ENABLE_LAYER_3       LCD_LAYER3_ENABLE
#ifdef GDI_6_LAYERS
#define GDI_LAYER_ENABLE_LAYER_4       LCD_LAYER4_ENABLE
#define GDI_LAYER_ENABLE_LAYER_5       LCD_LAYER5_ENABLE
#endif /* GDI_6_LAYERS */ 

#ifdef GDI_USING_LAYER_ROTATE
#define GDI_LAYER_ROTATE_0             LCD_LAYER_ROTATE_NORMAL
#define GDI_LAYER_ROTATE_90            LCD_LAYER_ROTATE_90
#define GDI_LAYER_ROTATE_180           LCD_LAYER_ROTATE_180
#define GDI_LAYER_ROTATE_270           LCD_LAYER_ROTATE_270
#define GDI_LAYER_ROTATE_0_MIRROR      LCD_LAYER_MIRROR
#define GDI_LAYER_ROTATE_90_MIRROR     LCD_LAYER_MIRROR_ROTATE_90
#define GDI_LAYER_ROTATE_180_MIRROR    LCD_LAYER_MIRROR_ROTATE_180
#define GDI_LAYER_ROTATE_270_MIRROR    LCD_LAYER_MIRROR_ROTATE_270
#else /* GDI_USING_LAYER_ROTATE */ 
#define GDI_LAYER_ROTATE_0             0
#define GDI_LAYER_ROTATE_90            1
#define GDI_LAYER_ROTATE_180           2
#define GDI_LAYER_ROTATE_270           3
#define GDI_LAYER_ROTATE_0_MIRROR      4
#define GDI_LAYER_ROTATE_90_MIRROR     5
#define GDI_LAYER_ROTATE_180_MIRROR    6
#define GDI_LAYER_ROTATE_270_MIRROR    7
#endif /* GDI_USING_LAYER_ROTATE */ 

/* post effect */
#if defined(GDI_USING_ISP)
#define GDI_LAYER_POST_EFFECT_NORMAL         0
#define GDI_LAYER_POST_EFFECT_GRAYSCALE      1
#define GDI_LAYER_POST_EFFECT_SEPIA          2
#define GDI_LAYER_POST_EFFECT_SEPIAGREEN     3
#define GDI_LAYER_POST_EFFECT_SEPIABLUE      4
#define GDI_LAYER_POST_EFFECT_COLORINV       5
#define GDI_LAYER_POST_EFFECT_GRAYINV        6
#define GDI_LAYER_POST_EFFECT_WATERCOLOR     7
#define GDI_LAYER_POST_EFFECT_LIGHTBLUR      8  /* DONT USE! 6219 HW BUG */
#define GDI_LAYER_POST_EFFECT_BLUR           9
#define GDI_LAYER_POST_EFFECT_STRONGBLUR     10
#define GDI_LAYER_POST_EFFECT_UNSHARP        11 /* DONT USE! 6219 HW BUG */
#define GDI_LAYER_POST_EFFECT_SHARPEN        12 /* DONT USE! 6219 HW BUG */
#define GDI_LAYER_POST_EFFECT_MORESHARPEN    13
#define GDI_LAYER_POST_EFFECT_MEDIAN         14
#define GDI_LAYER_POST_EFFECT_DILATION       15
#define GDI_LAYER_POST_EFFECT_EROSION        16

#define GDI_LAYER_ADJUSMENT_BRIGHTNESS       0
#define GDI_LAYER_ADJUSMENT_CONTRAST         1
#define GDI_LAYER_ADJUSMENT_SATURATION       2
#define GDI_LAYER_ADJUSMENT_HUE              3
#define GDI_LAYER_ADJUSMENT_ADJR             4
#define GDI_LAYER_ADJUSMENT_ADJG             5
#define GDI_LAYER_ADJUSMENT_ADJB             6
#endif /* defined(GDI_USING_ISP) */ 

#define GDI_LAYER_MAIN_BASE_LAYER_HANDLE     ((gdi_handle)(&GDI_LAYERS[0]))
#ifdef __MMI_SUBLCD__
#define GDI_LAYER_SUB_BASE_LAYER_HANDLE         ((gdi_handle)(&GDI_LAYERS[1]))
#endif 

/* 
 * In current design, GDI_MAINLCD_BIT_PER_PIXEL is always 16. 
 * 
 * Assume MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 24 bit, then 
 * GDI_MAINLCD_BIT_PER_PIXEL != MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL.
 * We need to convert cache buffer (16-bit) to base layer (24-bit) in some applications
 */
#if defined(GDI_USING_LAYER_COLOR_FORMAT) && (GDI_MAINLCD_BIT_PER_PIXEL != MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL)
    #if MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL==24
        #define  GDI_SET_BUFFER_PIXEL2(X,Y,VALUE)        gdi_act_put_pixel(X,Y,gdi_rgb565_to_rgb888(VALUE));
    #elif MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL==32
        #define  GDI_SET_BUFFER_PIXEL2(X,Y,VALUE)        gdi_act_put_pixel(X,Y,gdi_rgb565_to_rgb888(VALUE)|0xff000000);
    #else
        #error "didn't support this color format!!"
    #endif
#else
#define  GDI_SET_BUFFER_PIXEL2                  GDI_SET_BUFFER_PIXEL
#endif

#define  GDI_SET_BUFFER_PIXEL(X,Y,VALUE)        gdi_act_put_pixel(X,Y,VALUE)
#define  GDI_GET_BUFFER_PIXEL(X,Y,VALUE)     VALUE=gdi_act_get_pixel(X,Y)

typedef struct gdi_layer_struct
{
    U32 id;
    U32 flag;
    S32 layer_size; /* bytes */
    U16 width, height;
    S16 clipx1, clipy1, clipx2, clipy2;
    U8 *buf_ptr;
    U8 *buf_ptr1;
    gdi_rect_struct clips[GDI_LAYER_CLIP_STACK_COUNT];
    U8 bits_per_pixel;
    U8 clips_top;
    U8 cf;          /* real color format ( it will support LCD color format) */
    U8 vcf;         /* virtual color format (convert to standard color format) */
    gd_get_pixel_func get_pixel;
    gd_put_pixel_func put_pixel;
    struct gdi_layer_struct *child;
    struct gdi_layer_struct *sib;
    S32 offset_x, offset_y;
    S32 offset_x_from_parent;
    S32 offset_y_from_parent;
    void (*lazy_free_callback)(gdi_handle handle);

    gdi_color background;   /* only valide when this layer is the "lowest" layer. */
    U8 rotate_value;
} gdi_layer_struct;

extern gdi_layer_struct GDI_LAYERS[GDI_LAYER_TOTAL_LAYER_COUNT];
extern gdi_layer_struct *gdi_act_layer;
extern gd_color_from_rgb_func gdi_act_color_from_rgb;
extern gd_color_to_rgb_func gdi_act_color_to_rgb;
extern gd_put_pixel_func gdi_act_put_pixel;
extern gd_get_pixel_func gdi_act_get_pixel;

#define GDI_LAYER (*gdi_act_layer)
extern GDI_RESULT gdi_layer_create_cf(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr);
extern GDI_RESULT gdi_layer_create_cf_double(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr);
extern GDI_RESULT gdi_layer_create_cf_using_outside_memory(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr,
                    U8 *outside_memory,
                    S32 outside_memory_size);
extern GDI_RESULT gdi_layer_create_cf_double_using_outside_memory(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr,
                    U8 *outside_memory1,
                    S32 outside_memory_size_1,
                    U8 *outside_memory2,
                    S32 outside_memory_size_2);
extern GDI_RESULT gdi_layer_free(gdi_handle handle);
extern GDI_RESULT gdi_layer_lazy_free(gdi_handle handle,void (*lazy_free_callback)(gdi_handle handle));
extern void gdi_layer_set_active(gdi_handle handle);
extern GDI_RESULT gdi_layer_toggle_double(void);
extern GDI_RESULT gdi_layer_get_base_handle(gdi_handle *handle_ptr);
extern void gdi_layer_restore_base_active(void);
extern GDI_RESULT gdi_layer_rotate(U16 rotate);
extern void gdi_layer_get_active(gdi_handle *handle_ptr);
extern void gdi_layer_push_and_set_active(gdi_handle handle);
extern void gdi_layer_pop_and_restore_active(void);
extern BOOL gdi_layer_is_double(gdi_handle layer);
/* layer setting */
extern GDI_RESULT gdi_layer_set_position(S32 offset_x, S32 offset_y);
extern GDI_RESULT gdi_layer_set_source_key(BOOL source_key_enable, gdi_color source_key_value);
extern GDI_RESULT gdi_layer_get_source_key(BOOL *source_key_enable, gdi_color *source_key_value);
extern GDI_RESULT gdi_layer_set_opacity(BOOL opacity_enable, U8 opacity_value);
extern GDI_RESULT gdi_layer_get_opacity(BOOL *opacity_enable, U8 *opacity_value);

/* clip */
extern void gdi_layer_get_clip(S32 *x1, S32 *y1, S32 *x2, S32 *y2);
extern void gdi_layer_set_clip(S32 x1, S32 y1, S32 x2, S32 y2);
extern void gdi_layer_reset_clip(void);
extern void gdi_layer_push_clip(void);
extern void gdi_layer_pop_clip(void);
extern void gdi_layer_set_clip_preset(S32 x1, S32 y1, S32 x2, S32 y2);

/* get buffer info */
extern GDI_RESULT gdi_layer_get_buffer_ptr(U8 **buf_ptr);
extern GDI_RESULT gdi_layer_get_dimension(S32 *width, S32 *height);
extern GDI_RESULT gdi_layer_get_position(S32 *offset_x, S32 *offset_y);

/* blt */
extern GDI_RESULT gdi_layer_blt_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3,
#ifdef GDI_6_LAYERS
                                    gdi_handle handle4, gdi_handle handle5,
#endif 
                                    S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_layer_blt_previous(S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_layer_blt_base_layer(S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_layer_set_blt_layer_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2,
                                              gdi_handle handle3
#ifdef GDI_6_LAYERS
                                              , gdi_handle handle4, gdi_handle handle5
#endif 
    );
extern GDI_RESULT gdi_layer_get_blt_layer_ext(gdi_handle *handle0, gdi_handle *handle1, gdi_handle *handle2,
                                              gdi_handle *handle3
#ifdef GDI_6_LAYERS
                                              , gdi_handle *handle4, gdi_handle *handle5
#endif 
    );
extern void gdi_layer_lock_frame_buffer(void);
extern void gdi_layer_unlock_frame_buffer(void);

/* clear background */
extern GDI_RESULT gdi_layer_clear(gdi_color color);

/* multi-layering flag */
extern GDI_RESULT gdi_layer_multi_layer_enable(void);
extern GDI_RESULT gdi_layer_multi_layer_disable(void);
extern BOOL gdi_layer_is_multi_layer_enable(void);
extern GDI_RESULT gdi_layer_flatten_previous_to_base(void);
extern GDI_RESULT gdi_layer_flatten_to_base_ext(gdi_handle src_handle0, gdi_handle src_handle1, gdi_handle src_handle2,
                                                gdi_handle src_handle3
#ifdef GDI_6_LAYERS
                                                , gdi_handle src_handle4, gdi_handle src_handle5
#endif 
    );
extern GDI_RESULT gdi_layer_flatten_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3
#ifdef GDI_6_LAYERS
                                        , gdi_handle handle4, gdi_handle handle5
#endif 
    );
extern GDI_RESULT gdi_layer_flatten_with_clipping_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2,
                                                      gdi_handle handle3
#ifdef GDI_6_LAYERS
                                                      , gdi_handle handle4, gdi_handle handle5
#endif 
    );

/* debug use, for print debug info, this will print base layer, ignore all locked flag */
extern void gdi_layer_debug_blt(void);
extern GDI_RESULT gdi_layer_save_jpeg_file(gdi_handle layer_handle, PS8 file_name);
extern GDI_RESULT gdi_layer_save_pbm_file(gdi_handle layer_handle, PS8 file_name);
extern int gdi_layer_get_bit_per_pixel(void);
extern void gdi_layer_resize(S32 width, S32 height);

extern void gdi_layer_set_rotate(U8 rotate_value);
extern U8 gdi_layer_get_base_layer_rotation(void);
extern void gdi_layer_rotate_base_layer(U8 rotate_value);
extern void gdi_layer_map_rotated_coordinates(U8 rotate_value, S32 *x, S32 *y);
extern void gdi_layer_inverse_map_rotated_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2);

extern void gdi_layer_copy_double(void);
extern void gdi_layer_set_palette(U8 index, gdi_color color);
extern gdi_color *gdi_layer_get_palette(void);
extern void gdi_waiting_blt_finish(void);
extern void gdi_enable_non_block_blt(void);
extern void gdi_disable_non_block_blt(void);
extern void gdi_layer_enter_draw_section(void);
extern void gdi_layer_exit_draw_section(void);
extern void gdi_layer_blt_finish_handler(void);
extern void gdi_layer_blt_tree(gdi_handle root, S32 x1, S32 y1, S32 x2, S32 y2);
extern BOOL gdi_layer_del(gdi_handle parent, gdi_handle child);
extern void gdi_layer_add(gdi_handle parent, gdi_handle child, S32 offset_x, S32 offset_y);
extern void gdi_layer_del_all_child(gdi_handle parent);
extern BOOL gdi_layer_set_background(gdi_color color);
extern gdi_color gdi_layer_get_background(void);
extern GDI_RESULT gdi_layer_add_post_effect(U16 effect_id);
extern GDI_RESULT gdi_layer_add_post_adjustment(U16 adjustment_id, S32 value);
extern void gdi_layer_apply_gray_effect(void);

#define gdi_layer_create(OFFSET_X,OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR) \
      gdi_layer_create_cf(GDI_LCD->cf,OFFSET_X,OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR)

#define gdi_layer_create_double(OFFSET_X, OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR) \
      gdi_layer_create_cf_double(GDI_LCD->cf,OFFSET_X,OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR)

#define gdi_layer_create_using_outside_memory(X,Y,WIDTH,HEIGHT,HANDLE_PTR,OUTMEM_PTR,OUTMEM_SIZE) \
      gdi_layer_create_cf_using_outside_memory(GDI_LCD->cf,X,Y,WIDTH,HEIGHT,HANDLE_PTR,OUTMEM_PTR,OUTMEM_SIZE)

#define gdi_layer_create_double_using_outside_memory(X,Y, WIDTH,HEIGHT,HANDLE_PTR,OUTMEM_PTR,OUTMEM_SIZE) \
         gdi_layer_create_cf_double_using_outside_memory                                                  \
            (GDI_LCD->cf,X,Y,WIDTH,HEIGHT,HANDLE_PTR,                                                     \
             OUTMEM_PTR,(OUTMEM_SIZE)>>1,OUTMEM_PTR+(OUTMEM_SIZE>>1),(OUTMEM_SIZE)>>1)

#ifdef GDI_6_LAYERS
#define gdi_layer_blt(H1,H2,H3,H4,X1,Y1,X2,Y2)        gdi_layer_blt_ext(H1,H2,H3,H4,0,0,X1,Y1,X2,Y2)
#define gdi_layer_get_blt_layer(H1,H2,H3,H4)       gdi_layer_get_blt_layer_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_set_blt_layer(H1,H2,H3,H4)       gdi_layer_set_blt_layer_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_flatten_to_base(H1,H2,H3,H4)     gdi_layer_flatten_to_base_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_flatten(H1,H2,H3,H4)             gdi_layer_flatten_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_flatten_with_clipping(H1,H2,H3,H4)  gdi_layer_flatten_with_clipping_ext(H1,H2,H3,H4,0,0)
#else /* GDI_6_LAYERS */ 
#define gdi_layer_blt                           gdi_layer_blt_ext
#define gdi_layer_get_blt_layer                 gdi_layer_get_blt_layer_ext
#define gdi_layer_set_blt_layer                 gdi_layer_set_blt_layer_ext
#define gdi_layer_flatten_to_base                  gdi_layer_flatten_to_base_ext
#define gdi_layer_flatten                       gdi_layer_flatten_ext
#define gdi_layer_flatten_with_clipping            gdi_layer_flatten_with_clipping_ext
#endif /* GDI_6_LAYERS */ 
extern U8 gdi_layer_get_rotate(void);
extern void gdi_rotate_map_layer_to_lcd(U8 rotate_value, S32 *x, S32 *y);
extern void gdi_rotate_map_lcd_to_layer(U8 rotate_value, S32 *x, S32 *y);
extern void gdi_layer_set_actual_rotate(gdi_handle layer_handle, U8 actual_rotate_value);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// LCD API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GDI_LCD_MAIN_LCD_HANDLE  (1)
#define GDI_LCD_SUB_LCD_HANDLE   (2)
#define GDI_LCD_TVOUT_HANDLE  (3)
#define GDI_LCD_ESD_RECOVERY_TIME 2000

typedef struct
{
    /* active LCD */
    gdi_handle act_handle;
    gdi_handle act_layer_handle;
    gdi_handle bind_handle;
    S32 act_width;
    S32 act_height;
    gdi_handle blt_handle[GDI_LAYER_HW_LAYER_COUNT];
    gdi_color_format cf;
    BOOL is_freeze;
    gdi_lcd_type_enum lcd_type;

    /* validate update area. */
    S32 blt_lock;
    gdi_rect_struct blt_rect;       /* blt region */
    BOOL blt_rect_is_used;    /* blt_rect is validate */
    U8 rotate_value;
    BOOL rotate_by_layer;
} gdi_lcd_cntx_struct;

extern gdi_lcd_cntx_struct *GDI_LCD;
extern void gdi_lcd_set_active(gdi_handle lcd_handle);
extern void gdi_lcd_get_active(gdi_handle *lcd_handle_ptr);
extern void gdi_lcd_get_dimension(S32 *width, S32 *height);
extern int gdi_lcd_get_bits_per_pixel(void);
extern void gdi_lcd_freeze(BOOL is_freeze);
extern BOOL gdi_lcd_get_freeze(void);
extern void gdi_lcd_esd_recovery(void);
extern void gdi_lcd_stop_esd_recovery_timer(void);
extern void gdi_lcd_start_esd_recovery_timer(void);
extern void gdi_rotate_map_lcd_to_absolute_hw_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
extern void gdi_rotate_map_absolute_hw_to_lcd_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
extern void gdi_lcd_set_actual_rotate(U8 rotate_value);
extern U8 gdi_lcd_get_rotate(void);
extern void gdi_lcd_set_rotate(U8 rotate_value);
extern void gdi_lcd_set_bind(gdi_handle lcd_handle);
extern void gdi_lcd_set_rotate(U8 rotate_value);
extern U8 gdi_lcd_get_rotate(void);
extern void gdi_lcd_set_rotate_by_layer(BOOL rotate_by_layer);
extern BOOL gdi_lcd_get_rotate_by_layer(void);
extern void gdi_rotate_map_absolute_hw_to_lcd(S32 *x, S32 *y);
extern void gdi_rotate_map_lcd_to_absolute_hw(S32 *x, S32 *y);
extern GDI_RESULT gdi_lcd_blt(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3);
extern void gdi_lcd_set_blt_handle_rotate(void);
extern GDI_RESULT gdi_lcd_paint_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3,
#ifdef GDI_6_LAYERS
                                    gdi_handle handle4, gdi_handle handle5,
#endif 
                                    S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_lcd_repaint(S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_lcd_paint_all_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3
#ifdef GDI_6_LAYERS
                                        , gdi_handle handle4, gdi_handle handle5
#endif 
    );
extern GDI_RESULT gdi_lcd_repaint_all(void);

#ifdef GDI_6_LAYERS
#define gdi_lcd_paint(H1,H2,H3,H4,X1,Y1,X2,Y2)        gdi_lcd_paint_ext(H1,H2,H3,H4,0,0,X1,Y1,X2,Y2)
#define gdi_lcd_paint_all(H1,H2,H3,H4)       gdi_lcd_paint_all_ext(H1,H2,H3,H4,0,0)
#else /* GDI_6_LAYERS */ 
#define gdi_lcd_paint                           gdi_lcd_paint_ext
#define gdi_lcd_paint_all                 gdi_lcd_paint_all_ext
#endif /* GDI_6_LAYERS */ 
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// IMAGE API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    S32 width;
    S32 height;
    U8 *buf_ptr;
} gdi_image_cache_bmp_struct;

typedef enum
{
    GDI_IMAGE_SRC_FROM_RESOURCE,
    GDI_IMAGE_SRC_FROM_MEMORY,
    GDI_IMAGE_SRC_FROM_FILE,
    GDI_IMAGE_SRC_FROM_RESOURCE_WITHOUT_HEADER
} gdi_image_src_enum;

extern U32 gdi_work_buffer[];
extern U32 gdi_work_buffer_size;

extern GDI_RESULT gdi_image_codec_draw(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U32 flag,
                    U32 frame_pos);
////////////////
// RESOURCE
////////////////
#define gdi_image_draw(OFFSET_X,OFFSET_Y,IMAGE_PTR) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                0)
                                
#define gdi_image_draw_resized(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                0)


#define gdi_image_draw_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                (U32) FRAME_NO)

#define gdi_image_draw_resized_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                (U32) FRAME_NO)

#define gdi_image_draw_id(OFFSET_X,OFFSET_Y,IMAGE_ID)           gdi_image_draw(OFFSET_X,OFFSET_Y,(U8*) GetImage(IMAGE_ID))
#define gdi_image_draw_id_frames(OFFSET_X,OFFSET_Y,IMAGE_ID,FRAME_NO) gdi_image_draw_frames(OFFSET_X,OFFSET_Y,(U8*) GetImage(IMAGE_ID),FRAME_NO)
#define gdi_image_draw_resized_id(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_ID) \
                    gdi_image_draw_resized(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,(U8*) GetImage(IMAGE_ID))

#define gdi_image_draw_id_with_transparent_color(OFFSET_X,OFFSET_Y,IMAGE_ID) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                (U8*) GetImage(IMAGE_ID),       \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                GDI_IMAGE_CODEC_FLAG_DISABLE_SRC_KEY,\
                                0)

////////////////
// MEMORY
////////////////
#define gdi_image_draw_mem(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_LENGTH) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_MEMORY,      \
                                IMAGE_PTR,                      \
                                IMAGE_TYPE,                     \
                                IMAGE_LENGTH,                   \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                0)

#define gdi_image_draw_resized_mem(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_LENGTH) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_MEMORY,      \
                                IMAGE_PTR,                      \
                                IMAGE_TYPE,                     \
                                IMAGE_LENGTH,                   \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                0)
#define gdi_image_draw_mem_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_LENGTH,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_MEMORY,      \
                                IMAGE_PTR,                      \
                                IMAGE_TYPE,                     \
                                IMAGE_LENGTH,                   \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                (U32)FRAME_NO)

#define gdi_image_draw_resized_mem_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_LENGTH,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_MEMORY,      \
                                IMAGE_PTR,                      \
                                IMAGE_TYPE,                     \
                                IMAGE_LENGTH,                   \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                (U32)FRAME_NO)

////////////////
// FILE
////////////////

#define gdi_image_draw_file(OFFSET_X,OFFSET_Y,IMAGE_NAME) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                0)

#define gdi_image_draw_resized_file(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                0)
#define gdi_image_draw_file_frames(OFFSET_X,OFFSET_Y,IMAGE_NAME,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                (U32)FRAME_NO)

#define gdi_image_draw_resized_file_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                (U32)FRAME_NO)

extern GDI_RESULT gdi_image_get_frame_count(U8 *image_ptr, S32 *frame_count);
extern GDI_RESULT gdi_image_get_frame_count_id(U16 image_id, S32 *frame_count);
extern GDI_RESULT gdi_image_get_frame_count_file(U8 *image_ptr, S32 *frame_count);
extern GDI_RESULT gdi_image_get_dimension(U8 *image_ptr, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_get_dimension_id(U16 image_id, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_get_dimension_file(S8 *image_name, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_get_dimension_mem(U8 img_type,U8 *img_ptr,S32 img_size,S32 *width, S32 *height);

extern U16 gdi_image_get_type_from_file(S8 *file_name);
extern U16 gdi_image_get_type_from_mem(PS8 ptr);

extern U16 gdi_image_get_buf_type(U8 * image_ptr);
extern S32 gdi_image_get_buf_len(U8* image);
extern U8 *gdi_image_get_buf_ptr(U8* image);

#define gdi_image_get_buf_len_from_id(ID) gdi_image_get_buf_len((U8*)GetImage(ID))
#define gdi_image_get_buf_ptr_from_id(ID) gdi_image_get_buf_ptr((U8*)GetImage(ID))
#define gdi_image_get_type_from_id(ID)    gdi_image_get_buf_type((U8*)GetImage(ID))

extern void gdi_image_util_fit_bbox(
                S32 bbox_width,
                S32 bbox_height,
                S32 src_width,
                S32 src_height,
                S32 *offset_x,
                S32 *offset_y,
                S32 *dest_width,
                S32 *dest_height);
extern void gdi_util_fit_box(
                S32 mode,
                S32 bbox_width,
                S32 bbox_height,
                S32 src_width,
                S32 src_height,
                S32 *offset_x,
                S32 *offset_y,
                S32 *dest_width,
                S32 *dest_height);
extern void gdi_resize_bitblt(gdi_handle src_layer, S32 sx1,S32 sy1,S32 sx2,S32 sy2,S32 dx1,S32 dy1,S32 dx2,S32 dy2);

extern GDI_RESULT gdi_image_util_check_decoder_cap(U16 image_type, S32 image_width, S32 image_height);
extern GDI_RESULT gdi_image_cache_bmp_get(S32 x1, S32 y1, S32 x2, S32 y2, gdi_image_cache_bmp_struct *bmp_ptr);
extern GDI_RESULT gdi_image_cache_bmp_draw(S32 offset_x, S32 offset_y, gdi_image_cache_bmp_struct *bmp_ptr);
extern void gdi_image_set_encoding_flag(U32 flag);
extern GDI_RESULT gdi_image_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name);
extern GDI_RESULT gdi_image_encode_file_to_jpeg(
                    S8 *src_file_name,
                    S8 *dest_file_name,
                    S32 dest_width,
                    S32 dest_height,
                    U8 *buf_ptr,
                    S32 buf_size);
extern const U16 *gdi_image_get_ext_name_from_file(S8 *file_name);
extern const U16 *gdi_image_get_ext_name_from_file_type(U16 file_type); /* deepali */
extern GDI_RESULT gdi_image_output_another_buffer(BOOL enable, U8 *src, U32 size, U16 width, U16 height);
extern void gdi_image_clear_work_buffer(void);
extern void gdi_image_codec_set_flag_begin(U32 flag);
extern void gdi_image_codec_set_flag_end(void);
extern void gdi_image_cache_reset(void);
extern void gdi_image_cache_reset_entry(U8* src,U32 size);
extern void gdi_image_set_progress_callback(void (*ptr)(void *,S32,S32,S32,S32),void* arg);
extern S32  gdi_image_progress_callback(void);
extern void gdi_image_set_update_area(S32 x1,S32 y1,S32 x2,S32 y2);
extern void gdi_image_get_update_area(S32 *x1,S32 *y1,S32 *x2,S32 *y2);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ANIMATION API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern GDI_RESULT gdi_anim_codec_draw_internal(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U32 flag,
                    gdi_handle *handle_ptr,
                    U32 frame_pos,
                    S32 draw_count);

extern void gdi_anim_set_count(S32 count);
extern S32 gdi_anim_get_count(U8* res_src);
extern GDI_RESULT gdi_anim_set_last_frame_callback(void (*callback_ptr) (GDI_RESULT result));
extern GDI_RESULT gdi_anim_stop_all(void);
extern GDI_RESULT gdi_anim_stop(gdi_handle a_handle);
extern U32 gdi_anim_get_delay(void);
extern GDI_RESULT gdi_anim_set_draw_before_callback(void (*callback_ptr)(GDI_RESULT result));
extern GDI_RESULT gdi_anim_set_blt_before_callback(void (*callback_ptr)(GDI_RESULT result));
extern GDI_RESULT gdi_anim_set_blt_after_callback(void (*callback_ptr)(GDI_RESULT result));
extern GDI_RESULT gdi_anim_set_disable_blt(void);
extern GDI_RESULT gdi_anim_stop_all_by_layer(gdi_handle layer);


////////////////
// RESOURCE
////////////////
#define gdi_anim_draw_id(OFFSET_X,OFFSET_Y,MMI_ID_TYPE,HANDLE_PTR)       \
            gdi_anim_codec_draw_internal(                                \
                     GDI_IMAGE_SRC_FROM_RESOURCE,                        \
                     (U8*)GetImage(MMI_ID_TYPE),GDI_IMAGE_TYPE_INVALID,0,\
                     OFFSET_X,OFFSET_Y,                                  \
                     0,0,/* resized width,height */                        \
                     0,/* flag */                                          \
                     HANDLE_PTR,                                         \
                     0,/* start_frame */                                   \
                     -1)/* is_draw_once */                              \

#define gdi_anim_draw_id_once(OFFSET_X,OFFSET_Y,MMI_ID_TYPE, HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                \
                     GDI_IMAGE_SRC_FROM_RESOURCE,                        \
                     (U8*)GetImage(MMI_ID_TYPE),GDI_IMAGE_TYPE_INVALID,0,\
                     OFFSET_X,OFFSET_Y,                                  \
                     0,0,/* resized width,height */                        \
                     0,/* flag */                                          \
                     HANDLE_PTR,                                         \
                     0,/* start_frame */                                   \
                     1)/* is_draw_once */                               \

#define gdi_anim_draw_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,HANDLE_PTR,START_FRAME) \
            gdi_anim_codec_draw_internal(                                        \
                     GDI_IMAGE_SRC_FROM_RESOURCE,                                \
                     (U8*)IMAGE_PTR,GDI_IMAGE_TYPE_INVALID,0,                    \
                     OFFSET_X,OFFSET_Y,                                          \
                     0,0,/* resized width,height */                                \
                     0,/* flag */                                                  \
                     HANDLE_PTR,                                                 \
                     START_FRAME,/* start_frame */                                 \
                     -1)/* is_draw_once */                                      \

#define gdi_anim_draw_resized_frames(OFFSET_X,OFFSET_Y,RESIZED_W,RESIZED_H,IMAGE_PTR,HANDLE_PTR,START_FRAME) \
            gdi_anim_codec_draw_internal(                                        \
                     GDI_IMAGE_SRC_FROM_RESOURCE,                                \
                     (U8*)IMAGE_PTR,GDI_IMAGE_TYPE_INVALID,0,                    \
                     OFFSET_X,OFFSET_Y,                                          \
                     RESIZED_W,RESIZED_H,/* resized width,height */                         \
                     0,/* flag */                                                  \
                     HANDLE_PTR,                                                 \
                     START_FRAME,/* start_frame */                                 \
                     -1)/* is_draw_once */                                      \

#define gdi_anim_draw(OFFSET_X,OFFSET_Y,IMAGE_PTR,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                     \
                     GDI_IMAGE_SRC_FROM_RESOURCE,             \
                     (U8*)IMAGE_PTR,GDI_IMAGE_TYPE_INVALID,0, \
                     OFFSET_X,OFFSET_Y,                       \
                     0,0,/* resized width,height */             \
                     0,/* flag */                               \
                     HANDLE_PTR,                              \
                     0,/* start_frame */                        \
                     -1)/* is_draw_once */                   \

#define gdi_anim_draw_resized(OFFSET_X,OFFSET_Y,RESIZED_W,RESIZED_H,IMAGE_PTR,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                                 \
                     GDI_IMAGE_SRC_FROM_RESOURCE,                                         \
                     (U8*)IMAGE_PTR,GDI_IMAGE_TYPE_INVALID,0,                             \
                     OFFSET_X,OFFSET_Y,                                                   \
                     RESIZED_W,RESIZED_H,/* resized width,height */                         \
                     0,/* flag */                                                           \
                     HANDLE_PTR,                                                          \
                     0,/* start_frame */                                                    \
                     -1)/* is_draw_once */                                               \

#define gdi_anim_draw_once(OFFSET_X,OFFSET_Y,IMAGE_PTR,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                          \
                     GDI_IMAGE_SRC_FROM_RESOURCE,                  \
                     (U8*)IMAGE_PTR,GDI_IMAGE_TYPE_INVALID,0,      \
                     OFFSET_X,OFFSET_Y,                            \
                     0,0,/* resized width,height */                  \
                     0,/* flag */                                    \
                     HANDLE_PTR,                                   \
                     0,/* start_frame */                             \
                     1)/* is_draw_once */                         \

////////////////
// FILE
////////////////
#define gdi_anim_draw_file(OFFSET_X,OFFSET_Y,IMAGE_NAME,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                           \
                     GDI_IMAGE_SRC_FROM_FILE,                       \
                     (U8*)IMAGE_NAME,GDI_IMAGE_TYPE_INVALID,0,      \
                     OFFSET_X,OFFSET_Y,                             \
                     0,0,/* resized width,height */                   \
                     0,/* flag */                                     \
                     HANDLE_PTR,                                    \
                     0,/* start_frame */                              \
                     -1)/* is_draw_once */                         \

#define gdi_anim_draw_file_resized(OFFSET_X,OFFSET_Y,RESIZED_W,RESIZED_H,IMAGE_NAME,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                                       \
                     GDI_IMAGE_SRC_FROM_FILE,                                                   \
                     (U8*)IMAGE_NAME,GDI_IMAGE_TYPE_INVALID,0,                                  \
                     OFFSET_X,OFFSET_Y,                                                         \
                     RESIZED_W,RESIZED_H,/* resized width,height */                               \
                     0,/* flag */                                                                 \
                     HANDLE_PTR,                                                                \
                     0,/* start_frame */                                                          \
                     -1)/* is_draw_once */                                                     \

#define gdi_anim_draw_file_frames(OFFSET_X,OFFSET_Y,IMAGE_NAME,HANDLE_PTR,START_FRAME) \
            gdi_anim_codec_draw_internal(                                              \
                     GDI_IMAGE_SRC_FROM_FILE,                                          \
                     (U8*)IMAGE_NAME,GDI_IMAGE_TYPE_INVALID,0,                         \
                     OFFSET_X,OFFSET_Y,                                                \
                     0,0,/* resized width,height */                                      \
                     0,/* flag */                                                        \
                     HANDLE_PTR,                                                       \
                     START_FRAME,/* start_frame */                                       \
                     -1)/* is_draw_once */                                            \

////////////////
// Memory
////////////////
#define gdi_anim_draw_mem(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                               \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                         \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                              \
                     OFFSET_X,OFFSET_Y,                                                 \
                     0,0,/* resized width,height */                                       \
                     0,/* flag */                                                         \
                     HANDLE_PTR,                                                        \
                     0,/* start_frame */                                                  \
                     -1)/* is_draw_once */                                             \

#define gdi_anim_draw_mem_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR,START_FRAME) \
            gdi_anim_codec_draw_internal(                                                                  \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                                            \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                                                 \
                     OFFSET_X,OFFSET_Y,                                                                    \
                     0,0,/* resized width,height */                                                          \
                     0,/* flag */                                                                            \
                     HANDLE_PTR,                                                                           \
                     START_FRAME,/* start_frame */                                                           \
                     -1)/* is_draw_once */                                                                \

#define gdi_anim_draw_mem_resized_frames(OFFSET_X,OFFSET_Y,RESIZED_W,RESIZED_H,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR,START_FRAME) \
            gdi_anim_codec_draw_internal(                                                                  \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                                            \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                                                 \
                     OFFSET_X,OFFSET_Y,                                                                    \
                     RESIZED_W,RESIZED_H,/* resized width,height */                                                   \
                     0,/* flag */                                                                            \
                     HANDLE_PTR,                                                                           \
                     START_FRAME,/* start_frame */                                                           \
                     -1)/* is_draw_once */                                                                \

#define gdi_anim_draw_mem_resized(OFFSET_X,OFFSET_Y,RESIZED_W,RESIZED_H,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                                                           \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                                                     \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                                                          \
                     OFFSET_X,OFFSET_Y,                                                                             \
                     RESIZED_W,RESIZED_H,/* resized width,height */                                                   \
                     0,/* flag */                                                                                     \
                     HANDLE_PTR,                                                                                    \
                     0,/* start_frame */                                                                              \
                     -1)/* is_draw_once */                                                                         \

#define gdi_anim_draw_mem_once(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                                    \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                              \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                                   \
                     OFFSET_X,OFFSET_Y,                                                      \
                     0,0,/* resized width,height */                                            \
                     0,/* flag */                                                              \
                     HANDLE_PTR,                                                             \
                     0,/* start_frame */                                                       \
                     1)/* is_draw_once */                                                   \

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// NON-BLOCKING API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum
{
    GDC_JOB_IS_USED         =1<<0,
    GDC_JOB_IS_ANIM         =1<<1,
    GDC_JOB_IS_NO_BLT       =1<<2,
    GDC_JOB_IS_DRAW_ONCE    =1<<3,    
    GDC_JOB_IS_PROGRESS_BLT =1<<4,
    GDC_JOB_DUMMY
} gdc_job_flag_enum;

extern gdi_handle gdi_image_nb_draw_internal(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag);

extern GDI_RESULT gdi_image_nb_stop(gdi_handle handle);
extern GDI_RESULT gdi_image_nb_stop_all(void);

extern void gdi_nb_set_blt(BOOL is_blt,BOOL is_progress);
extern void gdi_nb_set_anim_before_frame_callback(void (*callback)(GDI_RESULT result,gdi_handle handle));
extern void gdi_nb_set_anim_after_frame_callback(void (*callback)(GDI_RESULT result,gdi_handle handle));
extern void gdi_nb_set_anim_last_frame_callback(void (*callback)(GDI_RESULT result));
extern void gdi_nb_set_done_callback(void (*callback)(GDI_RESULT result,gdi_handle handle));
extern void gdi_nb_set_anim_count(S32 anim_count);
extern void gdi_nb_set_high_priority(BOOL is_nb_first);

#define gdi_anim_nb_stop            gdi_image_nb_stop
#define gdi_anim_nb_stop_all        gdi_image_nb_stop_all


////////////////
// IMAGE RESOURCE
////////////////
#define gdi_image_nb_draw(OFFSET_X,OFFSET_Y,IMAGE_PTR)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0)

#define gdi_image_nb_draw_resized(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    0)
#define gdi_image_nb_draw_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,FRAME_NO)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    (U32)FRAME_NO,                              \
                                    0)

#define gdi_image_nb_draw_resized_frames(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    0)
////////////////
// IMAGE MEMORY
////////////////
#define gdi_image_nb_draw_mem(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0)

#define gdi_image_nb_draw_resized_mem(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    0)
                                    
#define gdi_image_nb_draw_mem_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,FRAME_NO)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    0)

#define gdi_image_nb_draw_resized_mem_frames(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    0)

////////////////
// IMAGE FILE
////////////////
#define gdi_image_nb_draw_file(OFFSET_X,OFFSET_Y,IMAGE_NAME) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),                     \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0)

#define gdi_image_nb_draw_resized_file(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),                     \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    0)

#define gdi_image_nb_draw_file_frames(OFFSET_X,OFFSET_Y,IMAGE_NAME,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),              \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    0)

#define gdi_image_nb_draw_resized_file_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),              \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    0)
////////////////
// ANIMATE RESOURCE
////////////////
#define gdi_anim_nb_draw(OFFSET_X,OFFSET_Y,IMAGE_PTR) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_IS_ANIM)

#define gdi_anim_nb_draw_resized(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_IS_ANIM)
////////////////
// ANIMATE MEMORY
////////////////
#define gdi_anim_nb_draw_mem(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_IS_ANIM)

#define gdi_anim_nb_draw_resized_mem(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_IS_ANIM)
////////////////
// ANIMATE FILE
////////////////
#define gdi_anim_nb_draw_file(OFFSET_X,OFFSET_Y,IMAGE_NAME) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),                     \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_IS_ANIM)

#define gdi_anim_nb_draw_resized_file(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),                     \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_IS_ANIM)


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// DECODER API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Create and free decoder, related hw will be powered on after deocder is created 
extern GDI_RESULT gdi_image_decoder_create(S32 max_img_width, S32 max_img_height,
                                           void (*result_callback_ptr) (GDI_RESULT decode_result, gdi_handle handle));
extern GDI_RESULT gdi_image_decoder_free(void);

/* Decoder functions */
extern GDI_RESULT gdi_image_decoder_decode_file(
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    BOOL is_blt,
                    S8 *image_name,
                    gdi_handle *handle_ptr);
extern GDI_RESULT gdi_image_decoder_decode_file_with_output_clipping(
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    S32 clipx1,
                    S32 clipy1,
                    S32 clipx2,
                    S32 clipy2,
                    BOOL is_blt,
                    S8 *image_name,
                    gdi_handle *handle_ptr);

extern GDI_RESULT gdi_image_decoder_stop(gdi_handle handle);
extern GDI_RESULT gdi_image_decoder_stop_all(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// JPEG API
///////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    U8 make[35];
    U8 model[35];
    U8 orientation[11];
    U8 x_resolution[24];
    U8 y_resolution[24];
    U8 resolution_unit[12];
    U8 software[35];
    U8 date_time[35];
    U8 ycbcr_positioning[9];
    U8 exif_ifd[14];

    U8 exposure_time[24];
    U8 fnumber[24];
    U8 exposure_program[18];
    U8 iso_speed_ratings[8];
    U8 exif_version[20];
    U8 date_time_original[35];
    U8 date_time_digitized[35];
    U8 components_config[6];
    U8 exposure_bias_value[24];
    U8 metering_mode[24];
    U8 light_source[17];
    U8 flash[80];
    U8 maker_note[20];
    U8 flashpix_version[20];
    U8 color_space[13];
    U8 pixel_x_dimension[14];
    U8 pixel_y_dimension[14];
    U8 exposure_mode[16];
    U8 digital_zoom_ratio[24];
    U8 scene_capture_type[12];
} gdi_image_jpeg_exif_info_struct;
extern GDI_RESULT gdi_image_jpeg_get_exif_info(S8 *filename, gdi_image_jpeg_exif_info_struct *info);
extern GDI_RESULT gdi_image_jpeg_draw_to_buffer(
                    S32 width,
                    S32 height,
                    U8 *jpeg_src,
                    U32 size,
                    U8 *buf,
                    S32 buf_size,
                    S32 *decoded_image_width);

extern GDI_RESULT gdi_image_jpeg_draw_file_to_buffer(
                    S32 width,
                    S32 height,
                    U8 *jpeg_file,
                    U8 *buf,
                    S32 buf_size,
                    S32 *decoded_image_width);

extern GDI_RESULT gdi_image_jpeg_get_dimension(U8 *jpeg_src, U32 size, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_jpeg_get_dimension_file(S8 *image_name, S32 *width, S32 *height);

extern GDI_RESULT gdi_image_jpeg_draw_internal(
                    S32 ox,
                    S32 oy,
                    S32 resized_width,
                    S32 resized_height,
                    S32 output_clipx1,
                    S32 output_clipy1,
                    S32 output_clipx2,
                    S32 output_clipy2,
                    U8 *src,
                    U32 size,
                    BOOL is_file,
                    BOOL is_resized,
                    BOOL retry_thumbnail,
                    U8 *dest_buf,
                    S32 dest_buf_size,
                    S32 *decoded_image_width,
                    gdi_color_format dest_buf_cf);

#define gdi_image_jpeg_draw(ox, oy, jpeg_src, size)\
         gdi_image_jpeg_draw_internal(             \
                  ox, oy,                          \
                  0, 0,                            \
                  -1, -1,                          \
                  -1, -1,                          \
                  jpeg_src,size,                    \
                  FALSE,FALSE,TRUE,                 \
                  NULL, /* dest buf */              \
                  0,    /* dest buf size */         \
                  NULL, /* decode image width */    \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_file(ox, oy, filename)\
         gdi_image_jpeg_draw_internal(            \
                  ox, oy,                         \
                  0, 0,                           \
                  -1, -1,                         \
                  -1, -1,                         \
                  (U8*)filename,0,                \
                  TRUE,FALSE,TRUE,                \
                  NULL, /* dest buf */             \
                  0,    /* dest buf size */        \
                  NULL, /* decode image width */   \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized(                       \
                     ox, oy, resized_width, resized_height,\
                     jpeg_src, size)                       \
         gdi_image_jpeg_draw_internal(                     \
                  ox, oy,                                  \
                  resized_width,resized_height,            \
                  0, 0,                                    \
                  resized_width-1, resized_height-1,       \
                  jpeg_src,size,                           \
                  FALSE,TRUE,TRUE,                          \
                  NULL, /* dest buf */                      \
                  0,    /* dest buf size */                 \
                  NULL, /* decode image width */            \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_with_output_clipping(  \
                     ox, oy,                       \
                     output_clipx1, output_clipy1, \
                     output_clipx2, output_clipy2, \
                     jpeg_src,size)                \
         gdi_image_jpeg_draw_internal(             \
                  ox, oy,                          \
                  0, 0,                            \
                  output_clipx1, output_clipy1,    \
                  output_clipx2, output_clipy2,    \
                  jpeg_src,size,                    \
                  FALSE,FALSE,TRUE,                 \
                  NULL, /* dest buf */              \
                  0,    /* dest buf size */         \
                  NULL, /* decode image width */    \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized_with_output_clipping( \
                  ox, oy, resized_width,resized_height,   \
                  output_clipx1, output_clipy1,           \
                  output_clipx2, output_clipy2,           \
                  jpeg_src, size)                         \
         gdi_image_jpeg_draw_internal(                    \
                  ox, oy,                                 \
                  resized_width, resized_height,          \
                  output_clipx1, output_clipy1,           \
                  output_clipx2, output_clipy2,           \
                  jpeg_src,size,                          \
                  FALSE,TRUE,TRUE,                         \
                  NULL, /* dest buf */                     \
                  0,    /* dest buf size */                \
                  NULL, /* decode image width */           \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_file_with_output_clipping( \
                        ox, oy,                        \
                        output_clipx1, output_clipy1,  \
                        output_clipx2, output_clipy2,  \
                        filename)                      \
         gdi_image_jpeg_draw_internal(                 \
                  ox, oy,                              \
                  0, 0,                                \
                  output_clipx1, output_clipy1,        \
                  output_clipx2, output_clipy2,        \
                  (U8*)filename,0,                     \
                  TRUE,FALSE,TRUE,                     \
                  NULL, /* dest buf */                  \
                  0,    /* dest buf size */             \
                  NULL, /* decode image width */        \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized_file(           \
                  ox, oy,                           \
                  resized_width, resized_height,    \
                  filename)                         \
         gdi_image_jpeg_draw_internal(              \
                  ox, oy,                           \
                  resized_width, resized_height,    \
                  0, 0,                             \
                  resized_width-1, resized_height-1,\
                  (U8*)filename,0,                  \
                  TRUE,TRUE,TRUE,                   \
                  NULL, /* dest buf */               \
                  0,    /* dest buf size */          \
                  NULL, /* decode image width */     \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized_file_with_output_clipping( \
                  ox,oy,                                       \
                  resized_width, resized_height,               \
                  output_clipx1, output_clipy1,                \
                  output_clipx2, output_clipy2,                \
                  filename)                                    \
         gdi_image_jpeg_draw_internal(                         \
                  ox, oy,                                      \
                  resized_width, resized_height,               \
                  output_clipx1, output_clipy1,                \
                  output_clipx2, output_clipy2,                \
                  (U8*)filename,0,                             \
                  TRUE,TRUE,TRUE,                              \
                  NULL, /* dest buf */                          \
                  0,    /* dest buf size */                     \
                  NULL, /* decode image width */                \
                  0)    /* dest buf color format */
/* Add Macro not to retry to decode thumbnail of jpeg when time out */
#define gdi_image_jpeg_draw_disable_retry(ox, oy, jpeg_src, size)\
         gdi_image_jpeg_draw_internal(             \
                  ox, oy,                          \
                  0, 0,                            \
                  -1, -1,                          \
                  -1, -1,                          \
                  jpeg_src,size,                    \
                  FALSE,FALSE,FALSE,                 \
                  NULL, /* dest buf */              \
                  0,    /* dest buf size */         \
                  NULL, /* decode image width */    \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_file_disable_retry(ox, oy, filename)\
         gdi_image_jpeg_draw_internal(            \
                  ox, oy,                         \
                  0, 0,                           \
                  -1, -1,                         \
                  -1, -1,                         \
                  (U8*)filename,0,                \
                  TRUE,FALSE,FALSE,                \
                  NULL, /* dest buf */             \
                  0,    /* dest buf size */        \
                  NULL, /* decode image width */   \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized_disable_retry(                       \
                     ox, oy, resized_width, resized_height,\
                     jpeg_src, size)                       \
         gdi_image_jpeg_draw_internal(                     \
                  ox, oy,                                  \
                  resized_width,resized_height,            \
                  0, 0,                                    \
                  resized_width-1, resized_height-1,       \
                  jpeg_src,size,                           \
                  FALSE,TRUE,FALSE,                          \
                  NULL, /* dest buf */                      \
                  0,    /* dest buf size */                 \
                  NULL, /* decode image width */            \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_with_output_clipping_disable_retry(  \
                     ox, oy,                       \
                     output_clipx1, output_clipy1, \
                     output_clipx2, output_clipy2, \
                     jpeg_src,size)                \
         gdi_image_jpeg_draw_internal(             \
                  ox, oy,                          \
                  0, 0,                            \
                  output_clipx1, output_clipy1,    \
                  output_clipx2, output_clipy2,    \
                  jpeg_src,size,                   \
                  FALSE,FALSE,FALSE,               \
                  NULL, /* dest buf */              \
                  0,    /* dest buf size */         \
                  NULL, /* decode image width */    \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized_with_output_clipping_disable_retry( \
                  ox, oy, resized_width,resized_height,   \
                  output_clipx1, output_clipy1,           \
                  output_clipx2, output_clipy2,           \
                  jpeg_src, size)                         \
         gdi_image_jpeg_draw_internal(                    \
                  ox, oy,                                 \
                  resized_width, resized_height,          \
                  output_clipx1, output_clipy1,           \
                  output_clipx2, output_clipy2,           \
                  jpeg_src,size,                          \
                  FALSE,TRUE,FALSE,                        \
                  NULL, /* dest buf */                     \
                  0,    /* dest buf size */                \
                  NULL, /* decode image width */           \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_file_with_output_clipping_disable_retry( \
                        ox, oy,                        \
                        output_clipx1, output_clipy1,  \
                        output_clipx2, output_clipy2,  \
                        filename)                      \
         gdi_image_jpeg_draw_internal(                 \
                  ox, oy,                              \
                  0, 0,                                \
                  output_clipx1, output_clipy1,        \
                  output_clipx2, output_clipy2,        \
                  (U8*)filename,0,                     \
                  TRUE,FALSE,FALSE,                     \
                  NULL, /* dest buf */                  \
                  0,    /* dest buf size */             \
                  NULL, /* decode image width */        \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized_file_disable_retry(           \
                  ox, oy,                           \
                  resized_width, resized_height,    \
                  filename)                         \
         gdi_image_jpeg_draw_internal(              \
                  ox, oy,                           \
                  resized_width, resized_height,    \
                  0, 0,                             \
                  resized_width-1, resized_height-1,\
                  (U8*)filename,0,                  \
                  TRUE,TRUE,FALSE,                   \
                  NULL, /* dest buf */               \
                  0,    /* dest buf size */          \
                  NULL, /* decode image width */     \
                  0)    /* dest buf color format */

#define gdi_image_jpeg_draw_resized_file_with_output_clipping_disable_retry( \
                  ox,oy,                                       \
                  resized_width, resized_height,               \
                  output_clipx1, output_clipy1,                \
                  output_clipx2, output_clipy2,                \
                  filename)                                    \
         gdi_image_jpeg_draw_internal(                         \
                  ox, oy,                                      \
                  resized_width, resized_height,               \
                  output_clipx1, output_clipy1,                \
                  output_clipx2, output_clipy2,                \
                  (U8*)filename,0,                             \
                  TRUE,TRUE,FALSE,                              \
                  NULL, /* dest buf */                          \
                  0,    /* dest buf size */                     \
                  NULL, /* decode image width */                \
                  0)    /* dest buf color format */

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PNG API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern GDI_RESULT gdi_image_png_get_dimension_internal(U8 *src, U32 size, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_png_draw_internal(S32 ox, S32 oy,
                                              S32 resized_width, S32 resized_height,
                                              U8 *src, U32 size, BOOL is_file, BOOL is_blocking,
                                              void (*callback) (GDI_RESULT result));

#define gdi_image_png_get_dimension(src,size,width,height) \
      gdi_image_png_get_dimension_internal(src,size,width,height)

#define gdi_image_png_get_dimension_file(src,width,height) \
      gdi_image_png_get_dimension_internal((U8*)src,0,width,height)

#define gdi_image_png_draw(ox, oy, src, size)\
         gdi_image_png_draw_internal(        \
                  ox, oy,                    \
                  0, 0,                      \
                  src,size,FALSE,TRUE,NULL)

#define gdi_image_png_draw_file(ox, oy, filename)\
         gdi_image_png_draw_internal(            \
                  ox, oy,                        \
                  0, 0,                          \
                  (U8*)filename,0,TRUE,TRUE,NULL)

#define gdi_image_png_draw_resized(                        \
                     ox, oy, resized_width, resized_height,\
                     src, size)                            \
         gdi_image_png_draw_internal(                      \
                  ox, oy,                                  \
                  resized_width,resized_height,            \
                  src,size,FALSE,TRUE,NULL)

#define gdi_image_png_draw_resized_file(         \
                  ox, oy,                        \
                  resized_width, resized_height, \
                  filename)                      \
         gdi_image_png_draw_internal(            \
                  ox, oy,                        \
                  resized_width, resized_height, \
                  (U8*)filename,0,TRUE,TRUE,NULL)


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ABM API
///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern gdi_handle gdi_image_abm_set_source_layer(gdi_handle src_layer_handle);
extern void gdi_image_abm_get_source_layer(gdi_handle *src_layer_handle);
extern void gdi_image_abm_set_source_layer_position(S32 offset_x, S32 offset_y);
extern void gdi_image_abm_get_source_layer_position(S32 *offset_x, S32 *offset_y);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// M3D/M3G API
///////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GDI Catcher Support
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define GDI_CATCHER_MAX_LCD_COUNT 3
#define GDI_CATCHER_MAX_LAYER_COUNT 8
typedef struct
{
    gdi_handle layer_handle;
    S32 width, height;
    S32 clipx1, clipy1, clipx2, clipy2;
    U8 *buf_ptr;
    U8 *buf_ptr1;
    S32 offset_x, offset_y;
    U32 source_key_value;
    U32 background; /* only valide when this layer is the "lowest" layer. */
    U32 layer_size; /* Buffer Size */
    U8 cf;
    U8 opacity_value;
    U8 rotate_value;
    U8 opacity_enable;
    U8 source_key_enable;
} gdi_catcher_layer_info_struct;

typedef struct
{
    S32 act_width;
    S32 act_height;
    S32 layer_count;
    S32 ROIx1;  /* blt region */
    S32 ROIy1;  /* blt region */
    S32 ROIx2;  /* blt region */
    S32 ROIy2;  /* blt region */
    U8 blt_handle[GDI_LAYER_HW_LAYER_COUNT];
    U8 cf;
    U8 rotate_value;
} gdi_catcher_lcd_info_struct;

typedef struct
{
    S32 lcd_count;
    gdi_catcher_lcd_info_struct lcd_array[GDI_CATCHER_MAX_LCD_COUNT];
    S32 layer_count;
    gdi_catcher_layer_info_struct layer_array[GDI_LAYER_TOTAL_LAYER_COUNT];
} gdi_catcher_info_struct;
extern GDI_RESULT gdi_catcher_fill_info(gdi_catcher_info_struct *catcher_info);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// estimate image decoding time
///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern U32 gdi_image_estimate_decoding_time(U8 img_type,S32 width,S32 height);
extern U32 gdi_image_estimate_show_fullscreen_time(void);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// NEED TO REMOVE!!!
///////////////////////////////////////////////////////////////////////////////////////////////////////////
extern U16 gdi_image_gif_get_transparent_index(void);
extern U8 gdi_image_gif_get_palette_size(void);

/* W05.39 Remove Compile Warnings */
extern GDI_RESULT gdi_image_gif_get_frame_count(U8 *GIF_src, U32 size, S32 *frame_count);
extern GDI_RESULT gdi_image_gif_get_frame_count_file(const S8 *filename, S32 *frame_count);

extern void gdi_image_gif_reset(void);
extern void gdi_image_gif_reset_entry(U8* src,U32 size);

#define GDI_RGB_TO_BUFFER_FORMAT(R,G,B)      DRV_RGB_TO_HW(R,G,B)
#define GDI_BUFFER_FORMAT_TO_RGB_R(VALUE)    DRV_HW_TO_RGB_R(VALUE)
#define GDI_BUFFER_FORMAT_TO_RGB_G(VALUE)    DRV_HW_TO_RGB_G(VALUE)
#define GDI_BUFFER_FORMAT_TO_RGB_B(VALUE)    DRV_HW_TO_RGB_B(VALUE)
#define GDI_MAINLCD_GET_BUFFER_PIXEL(X,Y,VALUE)    DRV_MAINLCD_GET_BUFFER_PIXEL(X,Y,VALUE)
#define GDI_MAINLCD_SET_BUFFER_PIXEL(X,Y,VALUE)    DRV_MAINLCD_SET_BUFFER_PIXEL(X,Y,VALUE)
#ifdef __MMI_SUBLCD__
#define GDI_SUBLCD_BUFFER_FORMAT(R,G,B)               SUBMMI_RGB_TO_HW_FORMAT(R,G,B)
#define GDI_SUBLCD_BUFFER_FORMAT_TO_RGB_R(VALUE)      HW_FORMAT_TO_SUBMMI_R(VALUE)
#define GDI_SUBLCD_BUFFER_FORMAT_TO_RGB_G(VALUE)      HW_FORMAT_TO_SUBMMI_G(VALUE)
#define GDI_SUBLCD_BUFFER_FORMAT_TO_RGB_B(VALUE)      HW_FORMAT_TO_SUBMMI_B(VALUE)

#define GDI_SUBLCD_GET_BUFFER_PIXEL(X,Y,VALUE)     DRV_SUBLCD_GET_BUFFER_PIXEL(X,Y,VALUE)
#define GDI_SUBLCD_SET_BUFFER_PIXEL(X,Y,VALUE)     DRV_SUBLCD_SET_BUFFER_PIXEL(X,Y,VALUE)
#endif /* __MMI_SUBLCD__ */ 

#define gdi_image_get_animation_delay                 gdi_anim_get_delay
#define gdi_image_stop_animation_all                     gdi_anim_stop_all
#define gdi_image_stop_animation                   gdi_anim_stop
#define gdi_image_set_animation_last_frame_callback         gdi_anim_set_last_frame_callback

#define gdi_image_draw_animation_id          gdi_anim_draw_id
#define gdi_image_draw_animation_once_id     gdi_anim_draw_id_once

#define gdi_image_draw_animation          gdi_anim_draw
#define gdi_image_draw_animation_frames      gdi_anim_draw_frames
#define gdi_image_draw_animation_resized     gdi_anim_draw_resized
#define gdi_image_draw_animation_once        gdi_anim_draw_once

#define gdi_image_draw_animation_file        gdi_anim_draw_file
#define gdi_image_draw_animation_resized_file   gdi_anim_draw_file_resized
#define gdi_image_draw_animation_frames_file gdi_anim_draw_file_frames

#define gdi_image_draw_ext                              gdi_image_draw_mem
#define gdi_image_draw_animation_single_frame           gdi_image_draw_frames
#define gdi_image_draw_animation_single_frame_id        gdi_image_draw_id_frames
#define gdi_image_draw_resized_ext                      gdi_image_draw_resized_mem
#define gdi_layer_save_jpeg_file                        gdi_image_encode_layer_to_jpeg
#endif /* _GDI_INCLUDE_H_ */ 


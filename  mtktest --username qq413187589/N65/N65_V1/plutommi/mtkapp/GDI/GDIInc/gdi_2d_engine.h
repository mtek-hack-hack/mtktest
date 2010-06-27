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
 *  gdi_mutex.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Hardware Gif related.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef GDI_USING_2D_ENGINE_V2
#include "2d_engine.h"
#endif 

extern void gdi_2d_engine_init(void);

#ifdef GDI_USING_2D_ENGINE

#define GDI_TRANSFORM_NONE          BITBLT_TRANSFORM_COPY
#define GDI_TRANSFORM_MIRROR           BITBLT_TRANSFORM_MIRROR

#define GDI_TRANSFORM_MIRROR_ROTATE_90 BITBLT_TRANSFORM_MIRROR_ROTATE_90
#define GDI_TRANSFORM_MIRROR_ROTATE_180   BITBLT_TRANSFORM_MIRROR_ROTATE_180
#define GDI_TRANSFORM_MIRROR_ROTATE_270   BITBLT_TRANSFORM_MIRROR_ROTATE_270

#define GDI_TRANSFORM_ROTATE_90        BITBLT_TRANSFORM_ROTATE_90
#define GDI_TRANSFORM_ROTATE_180       BITBLT_TRANSFORM_ROTATE_180
#define GDI_TRANSFORM_ROTATE_270       BITBLT_TRANSFORM_ROTATE_270

extern void gdi_2d_fill_rectangle(int x1, int y1, int x2, int y2, gdi_color color);
extern void gdi_2d_line(S16 x1, S16 y1, S16 x2, S16 y2, gdi_color color, BOOL is_dotted);
#endif /* GDI_USING_2D_ENGINE */ 

#ifdef GDI_USING_2D_ENGINE_V2

#define GDI_TRANSFORM_NONE          BITBLT_TRANSFORM_COPY
#define GDI_TRANSFORM_MIRROR           BITBLT_TRANSFORM_MIRROR

#define GDI_TRANSFORM_MIRROR_ROTATE_90 BITBLT_TRANSFORM_MIRROR_ROTATE_90
#define GDI_TRANSFORM_MIRROR_ROTATE_180   BITBLT_TRANSFORM_MIRROR_ROTATE_180
#define GDI_TRANSFORM_MIRROR_ROTATE_270   BITBLT_TRANSFORM_MIRROR_ROTATE_270

#define GDI_TRANSFORM_ROTATE_90        BITBLT_TRANSFORM_ROTATE_90
#define GDI_TRANSFORM_ROTATE_180       BITBLT_TRANSFORM_ROTATE_180
#define GDI_TRANSFORM_ROTATE_270       BITBLT_TRANSFORM_ROTATE_270

#define GDI_TRANSFORM_DIRECTION_RB     BITBLT_TRANSFORM_DIRECTION_RB_CORNER
#define GDI_TRANSFORM_DIRECTION_LB     BITBLT_TRANSFORM_DIRECTION_LB_CORNER
#define GDI_TRANSFORM_DIRECTION_RT     BITBLT_TRANSFORM_DIRECTION_RT_CORNER
#define GDI_TRANSFORM_DIRECTION_LT     BITBLT_TRANSFORM_DIRECTION_LT_CORNER

typedef enum
{
    GDI_2D_BUFFER_SRC_COLOR_8BPP_LUT_DIS = 0x0000,
    GDI_2D_BUFFER_SRC_COLOR_16BPP_RGB565 = 0x0200,
    GDI_2D_BUFFER_SRC_COLOR_32BPP_ARGB8888 = 0x0400,
    GDI_2D_BUFFER_SRC_COLOR_24BPP_RGB888 = 0x0600,
    GDI_2D_BUFFER_SRC_COLOR_16BPP_ARGB4444 = 0x0A00
} gdi_2d_buffer_color_mode_enum;

#define GDI_BITBLT_TRANSFORM_MIRROR_ROTATE_90      0x00
#define GDI_BITBLT_TRANSFORM_ROTATE_90          0x01
#define GDI_BITBLT_TRANSFORM_ROTATE_270            0x02
#define GDI_BITBLT_TRANSFORM_MIRROR_ROTATE_270     0x03
#define GDI_BITBLT_TRANSFORM_ROTATE_180            0x04
#define GDI_BITBLT_TRANSFORM_MIRROR             0x05
#define GDI_BITBLT_TRANSFORM_MIRROR_ROTATE_180     0x06
#define GDI_BITBLT_TRANSFORM_COPY                  0x07

typedef struct
{
    U32 base_address;
    S16 x;
    S16 y;
    U16 pitch;
    U16 width;
    U16 height;
    U16 color_mode; /* must use gdi_2d_buffer_color_mode_enum */
    U16 clip_x1;
    U16 clip_x2;
    U16 clip_y1;
    U16 clip_y2;
} gdi_2d_buffer_struct;

extern void gdi_2d_begin(void);
extern void gdi_2d_end(void);
extern void gdi_2d_set_layer_as_dest_buffer(gdi_handle handle);
extern void gdi_2d_set_buffer(
                gdi_2d_buffer_struct *dest,
                U8 *dest_ptr,
                U32 dest_pitch,
                U32 width,
                U32 height,
                S32 x,
                S32 y,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color_format cf);
extern void gdi_2d_set_dest_buffer(
                U8 *dest,
                U32 dest_pitch,
                U32 width,
                U32 height,
                S32 x,
                S32 y,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color_format cf);
extern void gdi_2d_fill_triangle(S32 x1, S32 y1, S32 x2, S32 y2, S32 x3, S32 y3, gdi_color color);
extern void gdi_2d_fill_polygon(S16 point[], U16 point_sum, gdi_color color);
extern void gdi_2d_set_font_attr(
                BOOL is_tilt,
                BOOL is_bold,
                BOOL is_border,
                BOOL enable_bg_color,
                gdi_color fg_color,
                gdi_color bg_color);
extern void gdi_2d_draw_font(S32 x, S32 y, U8 *font_addr, U32 bit_offset, U32 font_width, U32 font_height);
extern void gdi_2d_draw_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color color, BOOL is_antialias, BOOL is_dotted);
extern void gdi_2d_draw_polygon(S16 point[], U16 point_sum, gdi_color color, BOOL is_antialias, BOOL is_dotted);
extern void gdi_2d_fill_rect(S32 x, S32 y, S32 width, S32 height, gdi_color color);
extern void gdi_2d_fill_gradient_rect(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                gdi_color color,
                BOOL is_tilt,
                BOOL is_gradient,
                U32 delta_gradient[8]);
extern void gdi_2d_draw_arc(S32 x, S32 y, S32 radius, gdi_color color, U32 start_angle, U32 end_angle);
extern void gdi_2d_bitblt(
                BOOL is_tilt,
                BOOL enable_src_key,
                gdi_color src_key,
                BOOL is_alpha_blending,
                U8 alpha_value,
                BOOL is_rop_mode,
                U8 rop_value,
                U8 transform_value,
                U8 transform_direction,
                gdi_2d_buffer_struct *src_list,
                kal_uint16 list_count);
extern void gdi_2d_draw_curve(S32 x1, S32 y1, S32 x2, S32 y2, S32 x3, S32 y3, gdi_color color);
extern void gdi_2d_draw_gradient_h_line(
                S16 pos[],
                /* line_number x 2 */ U16 line_width[],
                /* line_number */ U16 line_number,
                S32 delta_gradient[],
                /* line_number x 4 */ gdi_color line_color);
extern void gdi_2d_copy_h_line(
                gdi_2d_buffer_struct *src,
                U32 *mask_address,
                U32 mask_length,
                S16 pos[],
                /* line_number x2 */ U16 line_width[],
                /* line_number */ U16 line_number);
extern void gdi_2d_set_tilt_table(const U32 *tilt_table, U32 table_size);
#endif /* GDI_USING_2D_ENGINE_V2 */ 


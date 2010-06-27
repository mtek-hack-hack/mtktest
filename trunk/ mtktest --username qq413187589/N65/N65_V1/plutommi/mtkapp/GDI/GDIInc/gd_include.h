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
 *  gd_include.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GD API interface
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
#ifndef __GD_INCLUDE_H__
#define __GD_INCLUDE_H__

#define GD_CLIP_RECT_TEST(X1, Y1, X2, Y2,CX1,CY1,CX2,CY2)\
{                                                        \
   if(X1 > X2  ) { return; }                             \
   if(Y1 > Y2  ) { return; }                             \
   if(X2 < CX1) { return; }                              \
   if(Y2 < CY1) { return; }                              \
   if(X1 > CX2) { return; }                              \
   if(Y1 > CY2) { return; }                              \
   if(X1 < CX1) { X1 = CX1; }                            \
   if(Y1 < CY1) { Y1 = CY1; }                            \
   if(X2 > CX2) { X2 = CX2; }                            \
   if(Y2 > CY2) { Y2 = CY2; }                            \
}

typedef void (*gd_draw_line_func) (U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
typedef void (*gd_draw_rect_func) (U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
typedef void (*gd_fill_rect_func) (U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color);
typedef void (*gd_draw_round_rect_func) (U16 *dstPtr, int destWidth, int xo, int yo, int width, int height, int arcWidth, int arcHeight, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
typedef void (*gd_fill_round_rect_func) (U16 *dstPtr, int destWidth, int xo, int yo, int width, int height, int arcWidth, int arcHeight, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color);
typedef void (*gd_draw_arc_func) (U16 *dstPtr, int destWidth, int x, int y, int width, int height, int startAngle, int arcAngle, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted); 
typedef void (*gd_draw_ellipse_func) (U16 *dstPtr, int destWidth, int x, int y,
                                      int arcWidth, int arcHeight, int clipx1, 
                                      int clipy1, int clipx2, int clipy2, 
                                      gdi_color color, BOOL dotted); extern 
                                      void gd_draw_ellipse16( U16 *dstPtr, int 
                                      destWidth, int x, int y, int arcWidth, 
                                      int arcHeight, int clipx1, int clipy1, 
                                      int clipx2, int clipy2, gdi_color color, 
                                      BOOL dotted);
typedef void (*gd_fill_ellipse_func) (U16 *dstPtr, int destWidth,
                                      int x, int y,
                                      int arcWidth, int arcHeight,
                                      int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color);
typedef void (*gd_fill_arc_func) (U16 *dstPtr, int destWidth,
                                  int x, int y,
                                  int width, int height,
                                  int startAngle, int arcAngle,
                                  int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color);
typedef void (*gd_fill_triangle_func) (U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int x3, int y3, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);

extern int gdi_atan(int sita); 
extern void gd_draw_line16( U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
extern void gd_draw_rect16( U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
extern void gd_fill_rect16( U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color);
extern void gd_draw_round_rect16( U16 *dstPtr, int destWidth, int xo, int yo, int width, int height, int arcWidth, int arcHeight, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
extern void gd_fill_round_rect16( U16 *dstPtr, int destWidth, int xo, int yo, int width, int height, int arcWidth, int arcHeight, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color);
extern void gd_draw_arc16( U16 *dstPtr, int destWidth, int x, int y, int width, int height, int startAngle, int arcAngle, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
extern void gd_fill_ellipse16(U16 *dstPtr, int destWidth, int x, int y, int arcWidth, int arcHeight, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color);
extern void gd_fill_arc16(U16 *dstPtr, int destWidth, int x, int y, int width, int height, int startAngle, int arcAngle, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color); 
extern void gd_fill_triangle16(U16 *imgp, int destWidth, int x1, int y1, int x2, int y2, int x3, int y3, int clipx1, int clipy1, int clipx2, int clipy2, gdi_color color, BOOL dotted);
extern void gd_gray_16(U8* address,int size);
extern void gd_null_pointer_function(void);

extern gdi_color gd_color_from_rgb_8(U32 A, U32 R, U32 G, U32 B);
extern gdi_color gd_color_from_rgb_16(U32 A, U32 R, U32 G, U32 B);
extern gdi_color gd_color_from_rgb_24(U32 A, U32 R, U32 G, U32 B);
extern gdi_color gd_color_from_rgb_32(U32 A, U32 R, U32 G, U32 B);

extern void gd_color_to_rgb_8(U32 *R, U32 *A, U32 *G, U32 *B, gdi_color c);
extern void gd_color_to_rgb_16(U32 *R, U32 *A, U32 *G, U32 *B, gdi_color c);
extern void gd_color_to_rgb_24(U32 *R, U32 *A, U32 *G, U32 *B, gdi_color c);
extern void gd_color_to_rgb_32(U32 *R, U32 *A, U32 *G, U32 *B, gdi_color c);

extern void gd_put_pixel_8(int x, int y, gdi_color c);
extern void gd_put_pixel_16(int x, int y, gdi_color c);
extern void gd_put_pixel_24(int x, int y, gdi_color c);
extern void gd_put_pixel_32(int x, int y, gdi_color c);

extern gdi_color gd_get_pixel_8(int x, int y);
extern gdi_color gd_get_pixel_16(int x, int y);
extern gdi_color gd_get_pixel_24(int x, int y);
extern gdi_color gd_get_pixel_32(int x, int y);

extern void gd_put_buf_pixel_8(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c);
extern void gd_put_buf_pixel_16(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c);
extern void gd_put_buf_pixel_24(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c);
extern void gd_put_buf_pixel_32(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c);

extern gdi_color gd_get_buf_pixel_8(U8 *buf_ptr, U32 buf_width, int x, int y);
extern gdi_color gd_get_buf_pixel_16(U8 *buf_ptr, U32 buf_width, int x, int y);
extern gdi_color gd_get_buf_pixel_24(U8 *buf_ptr, U32 buf_width, int x, int y);
extern gdi_color gd_get_buf_pixel_32(U8 *buf_ptr, U32 buf_width, int x, int y);

extern void gd_replace_src_key_8(
                U8 *dest_ptr,
                S32 dest_pitch,
                S32 dest_offset_x,
                S32 dest_offset_y,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                S32 width,
                S32 height);
extern void gd_replace_src_key_16(
                U8 *dest_ptr,
                S32 dest_pitch,
                S32 dest_offset_x,
                S32 dest_offset_y,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                S32 width,
                S32 height);
extern void gd_replace_src_key_24(
                U8 *dest_ptr,
                S32 dest_pitch,
                S32 dest_offset_x,
                S32 dest_offset_y,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                S32 width,
                S32 height);
extern void gd_replace_src_key_32(
                U8 *dest_ptr,
                S32 dest_pitch,
                S32 dest_offset_x,
                S32 dest_offset_y,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                S32 width,
                S32 height);

extern void gd_resize_bitblt_8(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);
extern void gd_resize_bitblt_16(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);
extern void gd_resize_bitblt_24(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);
extern void gd_resize_bitblt_32(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);

extern void gd_bitblt_8(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);
extern void gd_bitblt_16(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);
extern void gd_bitblt_24(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);
extern void gd_bitblt_32(
                U8 *dest,
                S32 dw,
                S32 dh,
                S32 dx1,
                S32 dy1,
                S32 dx2,
                S32 dy2,
                U8 *src,
                S32 sw,
                S32 sh,
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 clipx1,
                S32 clipy1,
                S32 clipx2,
                S32 clipy2,
                gdi_color src_key,
                gdi_color layer_key);

extern void gd_fill_dot_rect_8(U8 *dest,S32 dw,S32 dh,S32 dx1,S32 dy1,S32 dx2,S32 dy2,S32 clipx1,S32 clipy1,S32 clipx2,S32 clipy2,gdi_color c);
extern void gd_fill_dot_rect_16(U8 *dest,S32 dw,S32 dh,S32 dx1,S32 dy1,S32 dx2,S32 dy2,S32 clipx1,S32 clipy1,S32 clipx2,S32 clipy2,gdi_color c);
extern void gd_fill_dot_rect_24(U8 *dest,S32 dw,S32 dh,S32 dx1,S32 dy1,S32 dx2,S32 dy2,S32 clipx1,S32 clipy1,S32 clipx2,S32 clipy2,gdi_color c);
extern void gd_fill_dot_rect_32(U8 *dest,S32 dw,S32 dh,S32 dx1,S32 dy1,S32 dx2,S32 dy2,S32 clipx1,S32 clipy1,S32 clipx2,S32 clipy2,gdi_color c);

extern void gd_memset_8(U8 *dest, U32 value, U32 len);
extern void gd_memset_16(U8 *dest, U32 value, U32 len);
extern void gd_memset_24(U8 *dest, U32 value, U32 len);
extern void gd_memset_32(U8 *dest, U32 value, U32 len);

extern void gd_image_bits_draw_8(U8 *dest,S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2, U8 *src, S32 sw,S32 sh,S32 sx1,S32 sy1, S32 sx2, S32 sy2, S32 src_size,S32 bits_per_pixel,gdi_color palette[],S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2);
extern void gd_image_bits_draw_16(U8 *dest,S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2, U8 *src, S32 sw,S32 sh,S32 sx1,S32 sy1, S32 sx2, S32 sy2, S32 src_size,S32 bits_per_pixel,gdi_color palette[],S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2);
extern void gd_image_bits_draw_24(U8 *dest,S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2, U8 *src, S32 sw,S32 sh,S32 sx1,S32 sy1, S32 sx2, S32 sy2, S32 src_size,S32 bits_per_pixel,gdi_color palette[],S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2);
extern void gd_image_bits_draw_32(U8 *dest,S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2, U8 *src, S32 sw,S32 sh,S32 sx1,S32 sy1, S32 sx2, S32 sy2, S32 src_size,S32 bits_per_pixel,gdi_color palette[],S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2);

extern const unsigned short gd_sqrt[1025];
extern const unsigned short gd_sin_table[91];
extern const unsigned short gd_tan_table[91];

extern const gd_draw_line_func gd_draw_line[];
extern const gd_draw_rect_func gd_draw_rect[];
extern const gd_fill_rect_func gd_fill_rect[];
extern const gd_draw_round_rect_func gd_draw_round_rect[];
extern const gd_fill_round_rect_func gd_fill_round_rect[];
extern const gd_draw_arc_func gd_draw_arc[];
extern const gd_draw_ellipse_func gd_draw_ellipse[];
extern const gd_fill_ellipse_func gd_fill_ellipse[];
extern const gd_fill_arc_func gd_fill_arc[];
extern const gd_fill_triangle_func gd_fill_triangle[];

extern const gd_color_from_rgb_func gd_color_from_rgb[];
extern const gd_color_to_rgb_func gd_color_to_rgb[];
extern const gd_get_pixel_func gd_get_pixel[];
extern const gd_put_pixel_func gd_put_pixel[];
extern const gd_get_buf_pixel_func gd_get_buf_pixel[];
extern const gd_put_buf_pixel_func gd_put_buf_pixel[];
extern const gd_replace_src_key_func gd_replace_src_key[];
extern const gd_bitblt_func gd_resize_bitblt[];
extern const gd_bitblt_func gd_bitblt[];
extern const gd_memset_func gd_memset[];
extern const gd_fill_dot_rect_func gd_fill_dot_rect[];
extern const gd_image_bits_draw_func gd_image_bits_draw[];


#endif

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
 *  gd_primitive24.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GD Primitive related.
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
#include "gdi_internal.h"

#include "gd_primitive.h"

#if defined(__MTK_TARGET__)
#pragma arm section code = "INTERNCODE"
#endif 


/*****************************************************************************
 * FUNCTION
 *  gd_color_from_rgb_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  A       [IN]        
 *  R       [IN]        
 *  G       [IN]        
 *  B       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_color_from_rgb_8(U32 A, U32 R, U32 G, U32 B)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gdi_color) ((A << 24) | (R << 16) | (G << 8) | A);
}


/*****************************************************************************
 * FUNCTION
 *  gd_color_to_rgb_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  A       [?]         
 *  R       [?]         
 *  G       [?]         
 *  B       [?]         
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_color_to_rgb_8(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *A = (U32) ((U8) (c >> 24));
    *R = (U32) ((U8) (c >> 16));
    *G = (U32) ((U8) (c >> 8));
    *A = (U32) ((U8) (c));
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_pixel_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_get_pixel_8(int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gdi_color) * (U8*) (gdi_act_layer->buf_ptr + ((y * gdi_act_layer->width + x)));
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_pixel_8(int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(U8*) (gdi_act_layer->buf_ptr + ((y * gdi_act_layer->width + x))) = (U8) c;
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_buf_pixel_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf_ptr         [?]         
 *  buf_width       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_get_buf_pixel_8(U8 *buf_ptr, U32 buf_width, int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gdi_color) * (U8*) (buf_ptr + ((y * buf_width + x)));
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_buf_pixel_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf_ptr         [?]         
 *  buf_width       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  c               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_buf_pixel_8(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(U8*) (buf_ptr + ((y * buf_width + x))) = (U8) c;
}


/*****************************************************************************
 * FUNCTION
 *  gd_replace_src_key_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_ptr            [?]         
 *  dest_pitch          [IN]        
 *  dest_offset_x       [IN]        
 *  dest_offset_y       [IN]        
 *  clipx1              [IN]        
 *  clipy1              [IN]        
 *  clipx2              [IN]        
 *  clipy2              [IN]        
 *  src_key             [IN]        
 *  width               [IN]        
 *  height              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_replace_src_key_8(
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
        S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gd_replace_src_key_8)
    U8 *dest_buf_ptr;
    U8 *dest_line_start_ptr;

    /* S32  i; */
    S32 y_jump = 0;
    S32 jump_size;
    S32 start, end;
    S32 x_draw_count, y_draw_count;

    dest_buf_ptr = dest_ptr;

    /* if not totally out of clip region */
    if (!((dest_offset_x > clipx2) ||
          (dest_offset_y > clipy2) || (dest_offset_x + width < clipx1) || (dest_offset_y + height < clipy1)))
    {
        /* adjust dest ptr to the start of drawing point */
        /* find start ptr for actual drawing */
        if (dest_offset_x < clipx1)
        {
            jump_size = (((y_jump + dest_offset_y) * dest_pitch + clipx1) * 8) >> 3;
            dest_line_start_ptr = dest_ptr + jump_size;
        }
        else
        {
            jump_size = (((y_jump + dest_offset_y) * dest_pitch + dest_offset_x) * 8) >> 3;
            dest_line_start_ptr = dest_ptr + jump_size;
        }

        /* find x_draw_count and y_draw_count */
        start = (dest_offset_x < clipx1) ? clipx1 : dest_offset_x;
        end = (dest_offset_x + (S32) width - 1 > clipx2) ? clipx2 : dest_offset_x + (S32) width - 1;
        x_draw_count = end - start + 1;

        start = (dest_offset_y < clipy1) ? clipy1 : dest_offset_y;
        end = (dest_offset_y + (S32) height - 1 > clipy2) ? clipy2 : dest_offset_y + (S32) height - 1;
        y_draw_count = end - start + 1;

        {
            U8 *dest;
            S32 x, y;

            for (y = 0; y < y_draw_count; y++)
            {
                dest = (U8*) (dest_line_start_ptr + ((dest_pitch * y * 8) >> 3));

                for (x = 0; x < x_draw_count; x++)
                {
                    U8 c = *dest;

                    if (c == src_key)
                    {
                        c ^= 1;
                    }

                    *dest = c;

                    dest++;
                }
            }
        }
    }
    GDI_EXIT_CRITICAL_SECTION(gd_replace_src_key_16)
}

#define PIXEL_TYPE                  U8
#define PIXEL_BYTES                 1
#define GET_PIXEL(C,PTR)            C=*((PIXEL_TYPE*)(PTR))
#define PUT_PIXEL(C,PTR)            *(PIXEL_TYPE*)(PTR) = (PIXEL_TYPE) C
#define JUMP_PIXEL(PTR,N)           PTR = (((U8*)PTR)+(N)* PIXEL_BYTES)

#define GD_RESIZE_BITBLT            gd_resize_bitblt_8
#define GD_BITBLT                   gd_bitblt_8
#define GD_MEMSET                   gd_memset_8
#define GD_FILL_DOT_RECTANGLE       gd_fill_dot_rect_8
#define GD_IMAGE_BITS_DRAW          gd_image_bits_draw_8
#include "gd_primitive_internal.h"

#if defined(__MTK_TARGET__)
#pragma arm section code
#endif 


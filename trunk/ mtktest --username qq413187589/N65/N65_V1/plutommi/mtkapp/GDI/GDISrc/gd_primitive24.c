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
 *  gd_color_from_rgb_24
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
gdi_color gd_color_from_rgb_24(U32 A, U32 R, U32 G, U32 B)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gdi_color) ((R << 16) | (G << 8) | B);
}


/*****************************************************************************
 * FUNCTION
 *  gd_color_to_rgb_24
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
void gd_color_to_rgb_24(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *A = 0xFF;
    *R = (U32) ((U8) (c >> 16));
    *G = (U32) ((U8) (c >> 8));
    *B = (U32) ((U8) (c));
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_pixel_24
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_get_pixel_24(int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *ptr = (U32*) (gdi_act_layer->buf_ptr + ((y * gdi_act_layer->width + x) * 3));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((U32) ptr) & 0x3)
    {
        case 0:
            return ((*ptr) & 0x00ffffff);
        case 1:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            return ((*ptr) >> 8);
        case 2:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            return ((*ptr) >> 16) | ((*(ptr + 1) & 0x0ff) << 16);
        default:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            return ((*ptr) >> 24) | ((*(ptr + 1) & 0x0ffff) << 8);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_24
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_pixel_24(int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *ptr = (U32*) (gdi_act_layer->buf_ptr + ((y * gdi_act_layer->width + x) * 3));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((U32) ptr) & 0x3)
    {
        case 0:
            *ptr = (*ptr & 0xff000000) | (c & 0x00ffffff);
            break;
        case 1:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            *ptr = (*ptr & 0x000000ff) | (c << 8);
            break;
        case 2:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            *ptr = (*ptr & 0x0000ffff) | (c << 16);
            ptr++;
            *ptr = (*ptr & 0xffffff00) | ((c & 0x00ff0000) >> 16);
            break;
        default:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            *ptr = (*ptr & 0x00ffffff) | (c << 24);
            ptr++;
            *ptr = (*ptr & 0xffff0000) | ((c & 0x00ffff00) >> 8);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_buf_pixel_24
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
gdi_color gd_get_buf_pixel_24(U8 *buf_ptr, U32 buf_width, int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *ptr = (U32*) (buf_ptr + ((y * buf_width + x) * 3));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((U32) ptr) & 0x3)
    {
        case 0:
            return ((*ptr) & 0x00ffffff);
        case 1:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            return ((*ptr) >> 8);
        case 2:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            return ((*ptr) >> 16) | ((*(ptr + 1) & 0x0ff) << 16);
        default:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            return ((*ptr) >> 24) | ((*(ptr + 1) & 0x0ffff) << 8);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_buf_pixel_24
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
void gd_put_buf_pixel_24(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *ptr = (U32*) (buf_ptr + ((y * buf_width + x) * 3));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((U32) ptr) & 0x3)
    {
        case 0:
            *ptr = (*ptr & 0xff000000) | (c & 0x00ffffff);
            break;
        case 1:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            *ptr = (*ptr & 0x000000ff) | (c << 8);
            break;
        case 2:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            *ptr = (*ptr & 0x0000ffff) | (c << 16);
            ptr++;
            *ptr = (*ptr & 0xffffff00) | ((c & 0x00ff0000) >> 16);
            break;
        default:
            ptr = (U32*) (((U32) ptr) & (~0x3));
            *ptr = (*ptr & 0x00ffffff) | (c << 24);
            ptr++;
            *ptr = (*ptr & 0xffff0000) | ((c & 0x00ffff00) >> 8);
    }
}

#define  REPLACE_U24_0(PTR,SRCKEY)                   \
   {                                                 \
      gdi_color c = (*PTR)&0x00ffffff;               \
      if (SRCKEY == c)                               \
      {                                              \
         *PTR = (*PTR&0xff000000)|((c^1)&0x00ffffff);\
      }                                              \
   }while(0)                                         \

#define  REPLACE_U24_1(PTR,SRCKEY)                     \
   {                                                   \
      U32 *temp_ptr = (U32*)(((U32)PTR)&(~0x3));       \
      gdi_color c = (*temp_ptr)>>8;                    \
      if (SRCKEY == c)                                 \
      {                                                \
         *temp_ptr = (*temp_ptr&0x000000ff)|((c^1)<<8);\
      }                                                \
   }while(0)                                           \

#define  REPLACE_U24_2(PTR,SRCKEY)                                     \
   {                                                                   \
      U32 *temp_ptr = (U32*)(((U32)PTR)&(~0x3));                       \
      gdi_color c = ((*temp_ptr)>>16) | ((*(temp_ptr+1)&0x0ff  ) <<16);\
      if (SRCKEY == c)                                                 \
      {                                                                \
         *temp_ptr = (*temp_ptr&0x0000ffff)|((c^1)<<16); temp_ptr++;   \
         *temp_ptr = (*temp_ptr&0xffffff00)|(((c^1)&0x00ff0000)>>16);  \
      }                                                                \
   }while(0)                                                           \

#define  REPLACE_U24_3(PTR,SRCKEY)                                     \
   {                                                                   \
      U32 *temp_ptr = (U32*)(((U32)PTR)&(~0x3));                       \
      gdi_color c = ((*temp_ptr)>>24) | ((*(temp_ptr+1)&0x0ffff) << 8);\
      if (SRCKEY == c)                                                 \
      {                                                                \
         *temp_ptr = (*temp_ptr&0x00ffffff)|((c^1)<<24); temp_ptr++;   \
         *temp_ptr = (*temp_ptr&0xffff0000)|(((c^1)&0x00ffff00)>>8);   \
      }                                                                \
   }while(0)                                                           \


/*****************************************************************************
 * FUNCTION
 *  gd_replace_src_key_24
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
void gd_replace_src_key_24(
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
    GDI_ENTER_CRITICAL_SECTION(gd_replace_src_key_24)
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
            jump_size = (((y_jump + dest_offset_y) * dest_pitch + clipx1) * 24) >> 3;
            dest_line_start_ptr = dest_ptr + jump_size;
        }
        else
        {
            jump_size = (((y_jump + dest_offset_y) * dest_pitch + dest_offset_x) * 24) >> 3;
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
            S32 x_draw_count_afer_shift;

            for (y = 0; y < y_draw_count; y++)
            {
                dest = (dest_line_start_ptr + ((dest_pitch * y * 24) >> 3));
                x = 0;

                switch (((U32) dest) & 0x3)
                {
                    case 3:
                        REPLACE_U24_3(dest, src_key);
                        dest += 3;
                        if (++x >= x_draw_count)
                        {
                            break;
                        }
                    case 2:
                        REPLACE_U24_2(dest, src_key);
                        dest += 3;
                        if (++x >= x_draw_count)
                        {
                            break;
                        }
                    case 1:
                        REPLACE_U24_1(dest, src_key);
                        dest += 3;
                        if (++x >= x_draw_count)
                        {
                            break;
                        }
                        break;
                }
                x_draw_count_afer_shift = x_draw_count - x;
                if (x_draw_count_afer_shift > 3)
                {
                    for (x = 0; x < (x_draw_count_afer_shift & (~0x3)); x += 4)
                    {
                        REPLACE_U24_0(dest, src_key);
                        dest += 3;
                        REPLACE_U24_3(dest, src_key);
                        dest += 3;
                        REPLACE_U24_2(dest, src_key);
                        dest += 3;
                        REPLACE_U24_1(dest, src_key);
                        dest += 3;
                    }
                }
                switch (((U32) x_draw_count_afer_shift) & 0x3)
                {
                    case 3:
                        REPLACE_U24_2(dest + 6, src_key);
                    case 2:
                        REPLACE_U24_3(dest + 3, src_key);
                    case 1:
                        REPLACE_U24_0(dest, src_key);
                        break;
                }
            }
        }
    }
    GDI_EXIT_CRITICAL_SECTION(gd_replace_src_key_24)
}

#define PIXEL_TYPE                  U32
#define PIXEL_BYTES                 3
#define GET_PIXEL(C,PTR)                                  \
         do                                               \
         {                                                \
            U32 *SS = (U32*)PTR;                          \
            switch(((U32)SS)&0x3)                         \
            {                                             \
            case 0:                                       \
               C = ((*SS)&0x00ffffff);                    \
               break;                                     \
            case 1:                                       \
               SS= (U32*)(((U32)SS)&(~0x3));              \
               C =((*SS)>>8);                             \
               break;                                     \
            case 2:                                       \
               SS= (U32*)(((U32)SS)&(~0x3));              \
               C = ((*SS)>>16) | ((*(SS+1)&0x0ff  ) <<16);\
               break;                                     \
            default:                                      \
               SS= (U32*)(((U32)SS)&(~0x3));              \
               C = ((*SS)>>24) | ((*(SS+1)&0x0ffff) << 8);\
               break;                                     \
            }                                             \
         }while(0)

#define PUT_PIXEL(C,PTR)                                   \
         do                                                \
         {                                                 \
            U32 *DD = (U32*)PTR;                           \
            switch(((U32)DD)&0x3)                          \
            {                                              \
            case 0:                                        \
               *DD = (*DD&0xff000000)|(C&0x00ffffff);      \
               break;                                      \
            case 1:                                        \
               DD = (U32*)(((U32)DD)&(~0x3));              \
               *DD = (*DD&0x000000ff)|(C<<8);              \
               break;                                      \
            case 2:                                        \
               DD = (U32*)(((U32)DD)&(~0x3));              \
               *DD = (*DD&0x0000ffff)|(C<<16); DD++;       \
               *DD = (*DD&0xffffff00)|((C&0x00ff0000)>>16);\
               break;                                      \
            default:                                       \
               DD = (U32*)(((U32)DD)&(~0x3));              \
               *DD = (*DD&0x00ffffff)|(C<<24); DD++;       \
               *DD = (*DD&0xffff0000)|((C&0x00ffff00)>>8); \
               break;                                      \
            }                                              \
         }while(0)

#define JUMP_PIXEL(PTR,N)           PTR = (((U8*)PTR)+(N)* PIXEL_BYTES)
#define GD_RESIZE_BITBLT            gd_resize_bitblt_24
#define GD_BITBLT                   gd_bitblt_24
#define GD_MEMSET                   gd_memset_24
#define GD_FILL_DOT_RECTANGLE       gd_fill_dot_rect_24
#define GD_IMAGE_BITS_DRAW          gd_image_bits_draw_24
#include "gd_primitive_internal.h"

#if defined(__MTK_TARGET__)
#pragma arm section code
#endif 


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
 *  gd_primitive_internal.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef GD_PRIMITIVE_INTERNAL_H
#define GD_PRIMITIVE_INTERNAL_H


/*****************************************************************************
 * FUNCTION
 *  GD_RESIZE_BITBLT
 * DESCRIPTION
 *****************************************************************************/
void GD_RESIZE_BITBLT(
        U8 *dest, S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2,
        U8 *src,  S32 sw, S32 sh, S32 sx1, S32 sy1, S32 sx2, S32 sy2,
        S32 clipx1,S32 clipy1,S32 clipx2,S32 clipy2,
        gdi_color src_key,gdi_color layer_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *d;
    S32 rx1, ry1, rx2, ry2; /* real destination */
    S32 rox, roy;           /* (dx1,dy1) is (0,0) , (rox,roy) is the distance of (rx1,ry1) to (0,0) */
    S32 rw, rh;
    U32 xratio;
    U32 yratio;

    /* calculate (xratio,yratio) */
    {
        S32 dw1;
        S32 dh1;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        dw1 = dx2 - dx1 + 1;
        dh1 = dy2 - dy1 + 1;
        if (dw1 <= 0 || dh1 <= 0)
        {
            return; /* nothing to do */
        }

        xratio = ((sx2 - sx1 + 1) << 16) / dw1;
        yratio = ((sy2 - sy1 + 1) << 16) / dh1;
    }

    rx1 = dx1;
    ry1 = dy1;
    rx2 = dx2;
    ry2 = dy2;
    GDI_CLIP_TWO_RECT(rx1, ry1, rx2, ry2, clipx1, clipy1, clipx2, clipy2, return);

    rw = rx2 - rx1 + 1;
    rh = ry2 - ry1 + 1;

    rox = rx1 - dx1;
    roy = ry1 - dy1;

    d = (U8*) (dest + (rx1 + ry1 * dw) * PIXEL_BYTES);

    /* start to resample */
    {
        S32 dx, dy, sx, sy;

        for (dy = 0; dy < rh; dy++)
        {
            sy = (((dy + roy) * yratio) >> 16) + sy1;
            if(sy<0) sy=0; else if(sy>=sh) sy=sh-1;
			
            for (dx = 0; dx < rw; dx++, JUMP_PIXEL(d, 1))
            {
                PIXEL_TYPE c;

                sx = (((dx + rox) * xratio) >> 16) + sx1;
				if(sx<0) sx=0; else if(sx>=sw) sx=sw-1;
                GET_PIXEL(c, src + (sy * sw + sx) * PIXEL_BYTES);
                if (c != src_key)
                {
                    if (c == layer_key)
                    {
                        c ^= 1;
                    }
                    PUT_PIXEL(c, d);
                }

            }
            JUMP_PIXEL(d, (dw - rw));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GD_BITBLT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dw              [IN]        
 *  dh              [IN]        
 *  dx1             [IN]        
 *  dy1             [IN]        
 *  dx2             [IN]        
 *  dy2             [IN]        
 *  src             [?]         
 *  sw              [IN]        
 *  sh              [IN]        
 *  sx1             [IN]        
 *  sy1             [IN]        
 *  sx2             [IN]        
 *  sy2             [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  src_key         [IN]        
 *  layer_key       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GD_BITBLT(
        U8 *dest,S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2,
        U8 *src,S32 sw,S32 sh,S32 sx1,S32 sy1, S32 sx2, S32 sy2,
        S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2,
        gdi_color src_key, gdi_color layer_key)
{
    S32 w, h;

    /* process clipping */
    {
        S32 old_dx, old_dy;
        S32 offset_x, offset_y;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        old_dx = dx1;
        old_dy = dy1;

        GDI_CLIP_TWO_RECT(dx1, dy1, dx2, dy2, clipx1, clipy1, clipx2, clipy2, return);
        offset_x = dx1 - old_dx;
        offset_y = dy1 - old_dy;

        sx1 += offset_x;
        sy1 += offset_y;
    }

    /* calculate the copy area */
    {
        S32 a, b;

        a = dx2 - dx1 + 1;
        b = sx2 - sx1 + 1;
        w = GDI_MIN(a, b);

        a = dy2 - dy1 + 1;
        b = sy2 - sy1 + 1;
        h = GDI_MIN(a, b);
        if (w <= 0 || h <= 0)
        {
            return;
        }
    }

    /* start to copy data */
    {
        U8 *s;
        U8 *d;
        S32 x, y;

        s = (U8*) (src + (sx1 + sy1 * sw) * PIXEL_BYTES);
        d = (U8*) (dest + (dx1 + dy1 * dw) * PIXEL_BYTES);

        for (y = h - 1; y >= 0; y--)
        {
            for (x = w - 1; x >= 0; x--)
            {
                PIXEL_TYPE c;

                GET_PIXEL(c, s);
                if (c != src_key)
                {
                    if (c == layer_key)
                    {
                        c ^= 1;
                    }
                    PUT_PIXEL(c, d);
                }
                JUMP_PIXEL(d, 1);
                JUMP_PIXEL(s, 1);
            }
            JUMP_PIXEL(s, (sw - w));
            JUMP_PIXEL(d, (dw - w));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GD_MEMSET
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [?]         
 *  value       [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GD_MEMSET(U8 *dest, U32 value, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PIXEL_TYPE c = (PIXEL_TYPE) value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len--)
    {
        PUT_PIXEL(c, dest);
        JUMP_PIXEL(dest, 1);
    }
}

void GD_FILL_DOT_RECTANGLE(
        U8 *dest,
        S32 dw,
        S32 dh,
        S32 dx1,
        S32 dy1,
        S32 dx2,
        S32 dy2,
        S32 clipx1,
        S32 clipy1,
        S32 clipx2,
        S32 clipy2,
        gdi_color c)
{
        U8 *d;
        S32 x, y;
        S32 w, h;
        
        /* process clipping */
        GDI_CLIP_TWO_RECT(dx1, dy1, dx2, dy2, clipx1, clipy1, clipx2, clipy2, return);
        w = dx2-dx1+1;
        h = dy2-dy1+1;

        d = (U8*) (dest + (dx1 + dy1 * dw) * PIXEL_BYTES);
        for (y = h - 1; y >= 0; y--)
        {
            if((y&1))
            {
                x = w-1;
            }
            else
            {
                x = w-2;
                JUMP_PIXEL(d,1);
            }
            for (; x >= 0; x-=2)
            {
                PUT_PIXEL(c, d);
                JUMP_PIXEL(d, 2);
            }
            JUMP_PIXEL(d, (dw - w+x+1));
        }
}
void GD_IMAGE_BITS_DRAW(
                            U8 *dest,S32 dw, S32 dh, S32 dx1, S32 dy1, S32 dx2, S32 dy2,
                            U8 *src, S32 sw,S32 sh,S32 sx1,S32 sy1, S32 sx2, S32 sy2,
                            S32 src_size,S32 bits_per_pixel,gdi_color palette[],
                            S32 clipx1, S32 clipy1, S32 clipx2, S32 clipy2)

{
    S32 w, h;
    S32 drop_cnt;

    if(src==NULL || src_size<=0) return;
    
    /* process clipping */
    {
        S32 old_dx, old_dy;
        S32 offset_x, offset_y;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        old_dx = dx1;
        old_dy = dy1;

        GDI_CLIP_TWO_RECT(dx1, dy1, dx2, dy2, clipx1, clipy1, clipx2, clipy2, return);
        offset_x = dx1 - old_dx;
        offset_y = dy1 - old_dy;

        drop_cnt = offset_y * sw + offset_x;
        sx1 += offset_x;
        sy1 += offset_y;
    }

    /* calculate the copy area */
    {
        S32 a, b;

        a = dx2 - dx1 + 1;
        b = sx2 - sx1 + 1;
        w = GDI_MIN(a, b);

        a = dy2 - dy1 + 1;
        b = sy2 - sy1 + 1;
        h = GDI_MIN(a, b);
        if (w <= 0 || h <= 0)
            return;
    }

    /* start to copy data */
    {
        U8 *s,*s_end;
        U8 *d,*d_end;
        U32 data;
        S32 data_bits;
        U32 index;
        U32 bit_mask = (1<<bits_per_pixel)-1;
           
        // only support bits_per_pixel <=24 otherwise this algorithm need to be rewrite
        GDI_DEBUG_ASSERT(bits_per_pixel<=24); 

        s = (U8*) src;
        s_end = ((U8*) src) + src_size;
        d = (U8*) (dest + (dx1 + dy1 * dw) * PIXEL_BYTES);
        d_end  = (U8*) (dest + (dx2 + dy2 * dw) * PIXEL_BYTES);
        data = data_bits = 0;

        
        while(1)
        {
            if(data_bits<bits_per_pixel) 
			{
				data = (data<<8) | *s;s++;data_bits+=8;// read 1 byte data
				if(s >= s_end && data_bits<bits_per_pixel) break; // still not enough
				continue;
			}
            
            // fetch one pixel data
            data_bits -= bits_per_pixel;
            index = (data >> data_bits) & bit_mask;

            // put pixel
            drop_cnt--;
            if(drop_cnt<0)
            {
                PUT_PIXEL(palette[index], d);
                JUMP_PIXEL(d, 1);
                if(drop_cnt<= -w)  // move to next line
                {
                    drop_cnt = sw-w;
                    JUMP_PIXEL(d, (dw-w));
                    if(d>d_end) break;
                }
            }
            
        }
    }
}

#endif /* GD_PRIMITIVE_INTERNAL_H */ 


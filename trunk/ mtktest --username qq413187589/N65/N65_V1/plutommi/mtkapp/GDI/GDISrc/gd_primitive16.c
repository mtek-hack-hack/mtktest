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
 *  gd_primitive.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"

#include "gd_primitive.h"

#define BYTES_PER_PIXEL    2


/*****************************************************************************
 * FUNCTION
 *  gd_draw_line16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imgp            [?]         
 *  destWidth       [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_draw_line16(
        U16 *imgp,
        int destWidth,
        int x1,
        int y1,
        int x2,
        int y2,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color,
        BOOL dotted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int xscan;
    int rate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((x1 == x2) && (y1 == y2))
    {
        if ((x1 < clipx1) || (x1 > clipx2))
        {
            return;
        }
        if ((y1 < clipy1) || (y1 > clipy2))
        {
            return;
        }
        imgp[x1 + y1 * destWidth] = color;
        return;
    }

    {
        int dx = x2 - x1;
        int dy = y2 - y1;

        /* calculate slope rate */
        {
            int absdx;
            int absdy;

            if (dx < 0)
            {
                dx --;
                x1 ++;
				absdx = -dx;
            }
            else
            {
                if(dx != 0)
                {
                    dx ++;
                    x2 ++;
                }
				absdx = dx;
            }

            if (dy < 0)
            {
                dy --;
                y1 ++;
				absdy = -dy;
            }
            else
            {
                if(dy != 0)
                {
                    dy ++;
                    y2 ++;
                }
				absdy = dy;
            }

            if (absdx >= absdy)
            {
                xscan = 1;
                if (x1 > x2)
                {   /* exchange */
                    int temp = x1;

                    x1 = x2;
                    x2 = temp;
                    temp = y1;
                    y1 = y2;
                    y2 = temp;
                }
                rate = (dy << 20) / dx;
            }
            else
            {
                xscan = 0;
                if (y1 > y2)
                {   /* exchange */
                    int temp = x1;

                    x1 = x2;
                    x2 = temp;
                    temp = y1;
                    y1 = y2;
                    y2 = temp;
                }
                rate = (dx << 20) / dy;
            }
        }

        /* clipping */
        if (xscan)
        {
            if (y1 <= y2)
            {
                if (y1 < clipy1)
                {
                    int orgy = y1;

                    y1 = clipy1;
                    if (y1 > y2)
                    {
                        return;
                    }
                    x1 = x1 - ((orgy - y1) * dx) / dy;
                }

                if (y2 > clipy2)
                {
                    int orgy = y2;

                    y2 = clipy2;
                    if (y1 > y2)
                    {
                        return;
                    }
                    x2 = x2 - ((orgy - y2) * dx) / dy;
                }
            }
            else
            {   /* y1 > y2 */
                if (y2 < clipy1)
                {
                    int orgy = y2;

                    y2 = clipy1;
                    if (y2 > y1)
                    {
                        return;
                    }
                    x2 = x2 - ((orgy - y2) * dx) / dy;
                }

                if (y1 > clipy2)
                {
                    int orgy = y1;

                    y1 = clipy2;
                    if (y2 > y1)
                    {
                        return;
                    }
                    x1 = x1 - ((orgy - y1) * dx) / dy;
                }
            }

            if (x1 < clipx1)
            {
                int orgx = x1;

                x1 = clipx1;
                if (x1 > x2)
                {
                    return;
                }
                y1 = y1 - (((orgx - x1) * rate) >> 20);
            }

            if (x2 > clipx2)
            {
                int orgx = x2;

                x2 = clipx2;
                if (x1 > x2)
                {
                    return;
                }
                y2 = y2 - (((orgx - x2) * rate) >> 20);
            }

        }
        else
        {   /* Yscan */
            if (x1 <= x2)
            {
                if (x1 < clipx1)
                {
                    int orgx = x1;

                    x1 = clipx1;
                    if (x1 > x2)
                    {
                        return;
                    }
                    y1 = y1 - ((orgx - x1) * dy) / dx;  /* dx will not be zero */
                }

                if (x2 > clipx2)
                {
                    int orgx = x2;

                    x2 = clipx2;
                    if (x1 > x2)
                    {
                        return;
                    }
                    y2 = y2 - ((orgx - x2) * dy) / dx;  /* dx will not be zero */
                }
            }
            else
            {   /* x1 > x2 */
                if (x2 < clipx1)
                {
                    int orgx = x2;

                    x2 = clipx1;
                    if (x2 > x1)
                    {
                        return;
                    }
                    y2 = y2 - ((orgx - x2) * dy) / dx;  /* dx will not be zero */
                }

                if (x1 > clipx2)
                {
                    int orgx = x1;

                    x1 = clipx2;
                    if (x2 > x1)
                    {
                        return;
                    }
                    y1 = y1 - ((orgx - x1) * dy) / dx;  /* dx will not be zero */
                }
            }

            if (y1 < clipy1)
            {
                int orgy = y1;

                y1 = clipy1;
                if (y1 > y2)
                {
                    return;
                }
                x1 = x1 - (((orgy - y1) * rate) >> 20);
            }

            if (y2 > clipy2)
            {
                int orgy = y2;

                y2 = clipy2;
                if (y1 > y2)
                {
                    return;
                }
                x2 = x2 - (((orgy - y2) * rate) >> 20);
            }
        }
    }

    if (dotted == 0)
    {
        if (xscan == 0)
        {
            int tempWidth = destWidth;
            int tempx = 0;

            /*            unsigned short * dstImageReg = &dst_->data[x1];//+ y1 * destWidth; */
            unsigned short *dstImageReg = &imgp[x1];    /* + y1 * destWidth; */
            unsigned short *endAddrReg = dstImageReg + y2 * tempWidth;

            dstImageReg += y1 * tempWidth;
            if (dstImageReg >= endAddrReg)
            {
                return;
            }
            do
            {
                dstImageReg[tempx >> 20] = color;
                dstImageReg += tempWidth;
                tempx += rate;
            } while (dstImageReg < endAddrReg);
        }
        else
        {
            int tempWidth = destWidth;
            int temprate = 0;

            /*            unsigned short * dstImageReg = &dst_->data[y1 * tempWidth]; */
            unsigned short *dstImageReg = &imgp[y1 * tempWidth];
            unsigned short *endAddrReg = dstImageReg + x2;

            dstImageReg += x1;
            if (dstImageReg >= endAddrReg)
            {
                return;
            }
            do
            {
                dstImageReg[(temprate >> 20) * tempWidth] = color;
                dstImageReg++;
                temprate += rate;
            } while (dstImageReg < endAddrReg);
        }
    }
    else
    {   /* dotted */
        if (xscan == 0)
        {
            int tempWidth = destWidth;
            int tempx = 0;

            /*            unsigned short * dstImageReg = &dst_->data[x1];//+ y1 * destWidth; */
            unsigned short *dstImageReg = &imgp[x1];    /* + y1 * destWidth; */
            unsigned short *endAddrReg = dstImageReg + y2 * tempWidth;

            dstImageReg += y1 * tempWidth;
            tempWidth += tempWidth;
            rate += rate;
            if (dstImageReg >= endAddrReg)
            {
                return;
            }
            do
            {
                dstImageReg[tempx >> 20] = color;
                dstImageReg += tempWidth;
                tempx += rate;
            } while (dstImageReg < endAddrReg);
        }
        else
        {
            int tempWidth = destWidth;
            int temprate = 0;

            /*            unsigned short * dstImageReg = &dst_->data[y1 * tempWidth]; */
            unsigned short *dstImageReg = &imgp[y1 * tempWidth];
            unsigned short *endAddrReg = dstImageReg + x2;

            dstImageReg += x1;
            rate += rate;
            if (dstImageReg >= endAddrReg)
            {
                return;
            }
            do
            {
                dstImageReg[(temprate >> 20) * tempWidth] = color;
                dstImageReg += 2;
                temprate += rate;
            } while (dstImageReg < endAddrReg);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_draw_rect16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imgp            [?]         
 *  destWidth       [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_draw_rect16(
        U16 *imgp,
        int destWidth,
        int x1,
        int y1,
        int x2,
        int y2,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color,
        BOOL dotted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int width, height;
    int clipsides = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width = x2 - x1 + 1;
    height = y2 - y1 + 1;

    if (x1 < clipx1)
    {
        width -= clipx1 - x1;
        x1 = clipx1;
        clipsides |= 0x110;
    }
    if (y1 < clipy1)
    {
        height -= clipy1 - y1;
        y1 = clipy1;
        clipsides |= 0x101;
    }

    if (width + x1 > clipx2)
    {
        width = clipx2 - x1;
        clipsides |= 0x120;
    }

    if (height + y1 > clipy2)
    {
        height = clipy2 - y1;
        clipsides |= 0x102;
    }

    if ((width <= 1) || (height <= 1))
    {
        if ((width == 1) && (height == 1))
        {
            /* dst_->data[y * destWidth + x] = color; */
            imgp[y1 * destWidth + x1] = color;
            return;
        }
        if ((width <= 0) || (height <= 0))
        {
            return;
        }
    }

    if (dotted == 0)
    {
        int widthTemp = width - 1;

        /* unsigned short  * dstImageReg    = (unsigned short *)(dst_->data + x + y * destWidth); */
        unsigned short *dstImageReg = (unsigned short*)(imgp + x1 + y1 * destWidth);
        unsigned short *dstImageEndReg = (unsigned short*)(dstImageReg + (height - 1) * destWidth);

        if (widthTemp < 0)
        {
            widthTemp = 0;
        }
        width <<= 1;

        if (clipsides == 0)
        {
            gdi_memset16((U8*) dstImageReg, (U16) color, width);
            dstImageReg += destWidth;
            while (dstImageReg < dstImageEndReg)
            {
                dstImageReg[0] = color;
                dstImageReg[widthTemp] = color;
                dstImageReg += destWidth;
            }
            gdi_memset16((U8*) dstImageEndReg, (U16) color, width);
        }
        else
        {

            if ((clipsides & 1) == 0)
            {
                gdi_memset16((U8*) dstImageReg, (U16) color, width);
            }

            /* width -= 2; */
            if ((clipsides & 0x30) == 0)
            {
                /* width += 2; */
                while (dstImageReg < dstImageEndReg)
                {
                    dstImageReg[0] = color;
                    dstImageReg[widthTemp] = color;
                    dstImageReg += destWidth;
                }
            }
            else if (((clipsides >> 4) & 1) == 0)
            {
                while (dstImageReg < dstImageEndReg)
                {
                    dstImageReg[0] = color;
                    dstImageReg += destWidth;
                }
            }
            else if (((clipsides >> 5) & 1) == 0)
            {
                /* width += 2; */
                while (dstImageReg < dstImageEndReg)
                {
                    dstImageReg[widthTemp] = color;
                    dstImageReg += destWidth;
                }
            }

            if ((clipsides & 2) == 0)
            {
                gdi_memset16((U8*) dstImageEndReg, (U16) color, width);
            }

        }
    }
    else
    {
        int tempx;
        int widthTemp = width - 1;

        /*  unsigned short * dstImageReg    = (unsigned short *)(dst_->data + x + y * destWidth); */
        unsigned short *dstImageReg = (unsigned short*)(imgp + x1 + y1 * destWidth);
        unsigned short *dstImageEndReg = (unsigned short*)(dstImageReg + (height - 1) * destWidth);

        if (widthTemp < 0)
        {
            widthTemp = 0;
        }

        if (clipsides == 0)
        {
            for (tempx = 0; tempx <= width; tempx += 2)
            {
                dstImageReg[tempx] = color;
            }
            dstImageReg[width] = color;
            while (dstImageReg <= dstImageEndReg)
            {
                dstImageReg[0] = color;
                dstImageReg[widthTemp] = color;
                dstImageReg += destWidth << 1;
            }
            for (tempx = 0; tempx <= width; tempx += 2)
            {
                dstImageEndReg[tempx] = color;
            }
            dstImageEndReg[width] = color;
        }
        else
        {
            if ((clipsides & 1) == 0)
            {
                for (tempx = 0; tempx <= width; tempx += 2)
                {
                    dstImageReg[tempx] = color;
                }
                dstImageReg[width] = color;
            }
            if ((clipsides & 0x30) == 0)
            {
                while (dstImageReg <= dstImageEndReg)
                {
                    dstImageReg[0] = color;
                    dstImageReg[widthTemp] = color;
                    dstImageReg += destWidth << 1;
                }
            }
            else if (((clipsides >> 4) & 1) == 0)
            {
                while (dstImageReg <= dstImageEndReg)
                {
                    dstImageReg[0] = color;
                    dstImageReg += destWidth << 1;
                }
            }
            else if (((clipsides >> 5) & 1) == 0)
            {
                while (dstImageReg <= dstImageEndReg)
                {
                    dstImageReg[widthTemp] = color;
                    dstImageReg += destWidth << 1;
                }
            }
            if ((clipsides & 2) == 0)
            {
                for (tempx = 0; tempx <= width; tempx += 2)
                {
                    dstImageEndReg[tempx] = color;
                }
                dstImageEndReg[width] = color;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_rect16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imgp            [?]         
 *  destWidth       [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_fill_rect16(
        U16 *imgp,
        int destWidth,
        int x1,
        int y1,
        int x2,
        int y2,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GD_CLIP_RECT_TEST(x1, y1, x2, y2, clipx1, clipy1, clipx2, clipy2);
    {
        U8 *dest = ((U8*) imgp) + ((x1 + y1 * destWidth) * BYTES_PER_PIXEL);

        y2 -= y1;
        y2++;

        x2 -= x1;
        x2++;
        x2 <<= 1;
        x1 = destWidth * BYTES_PER_PIXEL;

        while (y2--)
        {
            gdi_memset16(dest, (U16) color, x2);
            dest += x1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_draw_round_rect16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_draw_round_rect16(
        U16 *dstPtr,
        int destWidth,
        int x,
        int y,
        int width,
        int height,
        int arcWidth,
        int arcHeight,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color,
        BOOL dotted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int xo = 0, yo = 0, width_ = 0, height_ = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width_ = width >> 1;
    height_ = height >> 1;
    arcWidth = (arcWidth > width) ? width_ : arcWidth >> 1;
    arcHeight = (arcHeight > height) ? height_ : arcHeight >> 1;
    xo = x + width_;
    yo = y + height_;

    if (arcWidth < 2 || arcHeight < 2 || ((width < 5) && (height < 5)))
    {
        gd_draw_rect16(
            dstPtr,
            destWidth,
            xo - width,
            yo - height,
            xo + width,
            yo + height,
            clipx1,
            clipy1,
            clipx2,
            clipy2,
            color,
            dotted);
        return;
    }
    width = width_;
    height = height_;
    {

        int xo_ = xo + width - arcWidth;
        int yo_ = yo - height + arcHeight;
        int xo2_ = xo - width + arcWidth;
        int yo2_ = yo + height - arcHeight;

        int i, sqr;
        int x_, y_, x2_, y2_;
        int pre_x1, pre_x2;
        int mid_x1, mid_x2, dotted_flag = 0;

        int index, d, Di;

        /* 2003 0920 Hsu */
        if (arcHeight == 0)
        {
            arcHeight = 1;
        }
        d = 1048576 / arcHeight;    /* (1024*1024/arcHeight) */

        if (dotted)
        {
            dotted_flag = 1;
        }
        x_ = (xo_ + arcWidth - 1 < clipx1) ? clipx1 : ((xo_ + arcWidth - 1 > clipx2) ? clipx2 : xo_ + arcWidth - 1);
        x2_ = (xo2_ - arcWidth + 1 < clipx1) ? clipx1 : ((xo2_ - arcWidth + 1 > clipx2) ? clipx2 : xo2_ - arcWidth + 1);
        y_ = (yo_ < clipy1) ? clipy1 : ((yo_ > clipy2) ? clipy2 : yo_);
        y2_ = (yo2_ < clipy1) ? clipy1 : ((yo2_ > clipy2) ? clipy2 : yo2_);

        Di = 0; /* c*x_start;// start_point_shift_value */
        for (i = 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }

            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;
            pre_x1 = x_;
            pre_x2 = x2_;

            x_ = (xo_ + sqr - 1 < clipx1) ? clipx1 : ((xo_ + sqr - 1 > clipx2) ? clipx2 : xo_ + sqr - 1);
            x2_ = (xo2_ - sqr + 1 < clipx1) ? clipx1 : ((xo2_ - sqr + 1 > clipx2) ? clipx2 : xo2_ - sqr + 1);
            y_ = (yo_ - i < clipy1) ? clipy1 : ((yo_ - i > clipy2) ? clipy2 : yo_ - i);
            y2_ = (yo2_ + i < clipy1) ? clipy1 : ((yo2_ + i > clipy2) ? clipy2 : yo2_ + i);

            /* 2003 1127 MaoSheng */
            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }
            if ((x_ != clipx1) && (x_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
            {
                *(dstPtr + y2_ * destWidth + x_) = color;
            }
            if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x2_) = color;
            }
            if ((x2_ != clipx1) && (x2_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
            {
                *(dstPtr + y2_ * destWidth + x2_) = color;
            }

            if (dotted)
            {

                /* 2003 1127 MaoSheng */
                if (((pre_x1 - x_) > 3) || ((x2_ - pre_x2) > 3))
                {
                    if (pre_x1 - x_ > 3)
                    {
                        dotted_flag = (pre_x1 - x_) >> 1;
                    }
                    else if ((x2_ - pre_x2) > 3)
                    {
                        dotted_flag = (x2_ - pre_x2) >> 1;
                    }

                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);
                    mid_x2 = pre_x2 + dotted_flag;
                    mid_x2 = (mid_x2 < clipx1) ? clipx1 : ((mid_x2 > clipx2) ? clipx2 : mid_x2);

                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ < clipx2))
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;  /* right_top_arc */
                        }
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y2_ - 1) != clipy1) && ((y2_ - 1) != clipy2))
                        if ((y2_ < clipy2) && (x_ < clipx2))
                        {
                            *(dstPtr + (y2_ - 1) * destWidth + mid_x1) = color; /* right_bottom_arc */
                        }
                    if ((mid_x2 != clipx1) && (mid_x2 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x2_ > clipx1))
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x2) = color;  /* left_top_arc */
                        }

                    if ((mid_x2 != clipx1) && (mid_x2 != clipx2) && ((y2_ - 1) != clipy1) && ((y2_ - 1) != clipy2))
                        if ((y2_ < clipy2) && (x2_ > clipx1))
                        {
                            *(dstPtr + (y2_ - 1) * destWidth + mid_x2) = color; /* left_bottom_arc */
                        }
                }
                dotted_flag = 1;

            }
            else
            {

                /* 2003 1127 MaoSheng */
                if ((((pre_x1 - x_) > 1) || ((x2_ - pre_x2) > 1)) && (y_ != clipy1) && (y_ != clipy2))
                {
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    if (x2_ != pre_x2)
                    {
                        gdi_memset16(
                            (U8*) (dstPtr + 1 + (pre_x2) + (y_) * destWidth),
                            (U16) color,
                            (x2_ - pre_x2) << 1);
                    }
                }

                if ((((pre_x1 - x_) > 1) || ((x2_ - pre_x2) > 1)) && (y2_ != clipy1) && (y2_ != clipy2))
                {
                    if (x2_ != pre_x2)
                    {
                        gdi_memset16(
                            (U8*) (dstPtr + 1 + (pre_x2) + (y2_) * destWidth),
                            (U16) color,
                            (x2_ - pre_x2) << 1);
                    }

                    gdi_memset16((U8*) (dstPtr + x_ + y2_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                }
            }   /* end if(dotted) */

        }   /* end for(i=1;i<=arcHeight;i++) */

        /* i = arcHeight, drawing the lines of top and bottom  */
        if (dotted)
        {
            x_ = (xo < clipx1) ? clipx1 : ((xo > clipx2) ? clipx2 : xo);
            y_ = (yo - height < clipy1) ? clipy1 : ((yo - height > clipy2) ? clipy2 : yo - height);
            y2_ = (yo + height < clipy1) ? clipy1 : ((yo + height > clipy2) ? clipy2 : yo + height);

            /* 2003 1128 MaoSheng */
            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + (y_ * destWidth) + x_) = color;  /* draw top_center point */
            }
            if ((y2_ != clipy1) && (y2_ != clipy2))
            {
                *(dstPtr + y2_ * destWidth + x_) = color;   /* draw bottom_center point */
            }

            if (dotted)
            {
                dotted_flag = 1;
            }
            for (i = 1; i < (width - arcWidth); i++)
            {

                if (dotted_flag)
                {
                    dotted_flag = 0;
                    continue;
                }
                x_ = (xo - i < clipx1) ? clipx1 : ((xo - i > clipx2) ? clipx2 : xo - i);
                x2_ = (xo + i < clipx1) ? clipx1 : ((xo + i > clipx2) ? clipx2 : xo + i);

                if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
                {
                    *(dstPtr + y_ * destWidth + x_) = color;    /* top_left_half_line */
                }
                if ((x_ != clipx1) && (x_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
                {
                    *(dstPtr + y2_ * destWidth + x_) = color;   /* bottom_left_half_line */
                }
                if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
                {
                    *(dstPtr + y_ * destWidth + x2_) = color;   /* top_right_half_line */
                }
                if ((x2_ != clipx1) && (x2_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
                {
                    *(dstPtr + y2_ * destWidth + x2_) = color;  /* bottom_right_half_line */
                }

                if (dotted)
                {
                    dotted_flag = 1;
                }

            }

        }
        else
        {

            if ((x_-x2_)>0 ) 
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
            if ((x_-x2_)>0 ) 
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y2_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

        /* drawing the lines of left and right */
        x_ = (xo + width - 2 < clipx1) ? clipx1 : ((xo + width - 2 > clipx2) ? clipx2 : xo + width - 2);
        x2_ = (xo - width + 2 < clipx1) ? clipx1 : ((xo - width + 2 > clipx2) ? clipx2 : xo - width + 2);
        y_ = (yo < clipy1) ? clipy1 : ((yo > clipy2) ? clipy2 : yo);

        /* 2003 1127 MaoSheng */
        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }
        if ((x2_ != clipx1) && (x2_ != clipx2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        if (dotted)
        {
            dotted_flag = 1;
        }
        for (i = 1; i <= (height - arcHeight); i++)
        {

            if (dotted_flag && (i != (height - arcHeight)))
            {
                dotted_flag = 0;
                continue;
            }
            y_ = (yo - i < clipy1) ? clipy1 : ((yo - i > clipy2) ? clipy2 : yo - i);
            y2_ = (yo + i < clipy1) ? clipy1 : ((yo + i > clipy2) ? clipy2 : yo + i);

            /* 2003 1127 MaoSheng */
            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;    /* draw right_top_half_line */
            }
            if ((x_ != clipx1) && (x_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
            {
                *(dstPtr + y2_ * destWidth + x_) = color;   /* draw right_bottom_half_line */
            }
            if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x2_) = color;   /* draw left_top_half_line */
            }
            if ((x2_ != clipx1) && (x2_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
            {
                *(dstPtr + y2_ * destWidth + x2_) = color;  /* draw left_bottom_half_line */
            }

            if (dotted)
            {
                dotted_flag = 1;
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_round_rect16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_fill_round_rect16(
        U16 *dstPtr,
        int destWidth,
        int x,
        int y,
        int width,
        int height,
        int arcWidth,
        int arcHeight,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int xo = 0, yo = 0, width_ = 0, height_ = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width_ = width >> 1;
    height_ = height >> 1;
    arcWidth = (arcWidth > width) ? width_ : arcWidth >> 1;
    arcHeight = (arcHeight > height) ? height_ : arcHeight >> 1;
    xo = x + width_;
    yo = y + height_;

    if (arcWidth < 2 || arcHeight < 2 || ((arcWidth<4) && (arcHeight<4)) || ((width < 5) && (height < 5)))
    {
        width >>= 1;
        height >>= 1;
        gd_fill_rect16(
            dstPtr,
            destWidth,
            xo - width,
            yo - height,
            xo + width,
            yo + height,
            clipx1,
            clipy1,
            clipx2,
            clipy2,
            color);
        return;
    }
    width = width_;
    height = height_;
    {
        int xo_ = xo + width - arcWidth;
        int yo_ = yo - height + arcHeight;
        int xo2_ = xo - width + arcWidth;
        int yo2_ = yo + height - arcHeight;

        int i, sqr;
        int x_, y_, x2_, y2_;

        int index, d, Di;

        /* 2003 0920 Hsu */
        if (arcHeight == 0)
        {
            arcHeight = 1;
        }
        d = 1048576 / arcHeight;    /* (1024*1024/arcHeight) */
        if ((clipy2--) < 0)
        {
            clipy2 = 0;
        }
        x_ = (xo_ + arcWidth - 1 < clipx1) ? clipx1 : ((xo_ + arcWidth - 1 > clipx2) ? clipx2 : xo_ + arcWidth - 1);
        x2_ = (xo_ - arcWidth + 1 < clipx1) ? clipx1 : ((xo_ - arcWidth + 1 > clipx2) ? clipx2 : xo_ - arcWidth + 1);
        y_ = (yo_ < clipy1) ? clipy1 : ((yo_ > clipy2) ? clipy2 : yo_);
        y2_ = (yo2_ < clipy1) ? clipy1 : ((yo2_ > clipy2) ? clipy2 : yo2_);
        /* 2003 0825 Hsu */
        if ((y_ >= clipy1) && (y_ <= clipy2) && ((x_-x2_) > 0))
        {
            gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }
        if ((y2_ >= clipy1) && (y2_ <= clipy2) && ((x_-x2_) > 0))
        {
            gdi_memset16((U8*) (dstPtr + x2_ + y2_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }
        Di = 0;

        for (i = 1; i <= arcHeight; i++)
        {
            Di += d;
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            x_ = (xo_ + sqr - 1 < clipx1) ? clipx1 : ((xo_ + sqr - 1 > clipx2) ? clipx2 : xo_ + sqr - 1);
            x2_ = (xo2_ - sqr + 1 < clipx1) ? clipx1 : ((xo2_ - sqr + 1 > clipx2) ? clipx2 : xo2_ - sqr + 1);
            y_ = (yo_ - i < clipy1) ? clipy1 : ((yo_ - i > clipy2) ? clipy2 : yo_ - i);
            y2_ = (yo2_ + i < clipy1) ? clipy1 : ((yo2_ + i > clipy2) ? clipy2 : yo2_ + i);

            if ((y_ >= clipy1) && (y_ <= clipy2) && ((x_ - x2_) > 0))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }

            if ((y2_ >= clipy1) && (y2_ <= clipy2) && ((x_ - x2_) > 0))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y2_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

        /* fill the Rectangle  */
        x_ = (xo + width - 1 < clipx1) ? clipx1 : ((xo + width - 1 > clipx2) ? clipx2 : xo + width - 1);
        x2_ = (xo - width + 1 < clipx1) ? clipx1 : ((xo - width + 1 > clipx2) ? clipx2 : xo - width + 1);
        y_ = (yo < clipy1) ? clipy1 : ((yo > clipy2) ? clipy2 : yo);

        if ((y_ >= clipy1) && (y_ <= clipy2))
        {
            gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }

        for (i = 1; i <= (height - arcHeight); i++)
        {
            y_ = (yo - i < clipy1) ? clipy1 : ((yo - i > clipy2) ? clipy2 : yo - i);
            y2_ = (yo + i < clipy1) ? clipy1 : ((yo + i > clipy2) ? clipy2 : yo + i);

            if ((y_ >= clipy1) && (y_ <= clipy2) && ((x_ - x2_) > 0))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }

            if ((y2_ >= clipy1) && (y2_ <= clipy2) && ((x_ - x2_) > 0))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y2_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_draw_ellipse16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_draw_ellipse16(
        U16 *dstPtr,
        int destWidth,
        int x,
        int y,
        int arcWidth,
        int arcHeight,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color,
        BOOL dotted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, sqr;
    int x_, y_, x2_, y2_;
    int pre_x1, pre_x2;
    int mid_x1, mid_x2, dotted_flag = 0;

    int index, d, Di;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2003 0920 Hsu */
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcHeight) */

    if (dotted)
    {
        dotted_flag = 1;
    }
    x_ = (x + arcWidth - 1 < clipx1) ? clipx1 : ((x + arcWidth - 1 > clipx2) ? clipx2 : x + arcWidth - 1);
    x2_ = (x - arcWidth + 1 < clipx1) ? clipx1 : ((x - arcWidth + 1 > clipx2) ? clipx2 : x - arcWidth + 1);
    y_ = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);

    if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
    {
        *(dstPtr + y_ * destWidth + x_ - 1) = color;
    }
    if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
    {
        *(dstPtr + y_ * destWidth + x2_ + 1) = color;
    }

    Di = 0; /* c*x_start; // start_point_shift_value */
    for (i = 1; i <= arcHeight; i++)
    {
        Di += d;

        if (dotted_flag && (i != arcHeight))
        {
            dotted_flag = 0;
            continue;
        }

        index = Di >> 10;
        sqr = (arcWidth * gd_sqrt[index]) >> 10;
        pre_x1 = x_;
        pre_x2 = x2_;

        x_ = (x + sqr - 1 < clipx1) ? clipx1 : ((x + sqr - 1 > clipx2) ? clipx2 : x + sqr - 1);
        x2_ = (x - sqr + 1 < clipx1) ? clipx1 : ((x - sqr + 1 > clipx2) ? clipx2 : x - sqr + 1);
        y_ = (y - i < clipy1) ? clipy1 : ((y - i > clipy2) ? clipy2 : y - i);
        y2_ = (y + i < clipy1) ? clipy1 : ((y + i > clipy2) ? clipy2 : y + i);

        /* 2003 1127 MaoSheng */
        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }
        if ((x_ != clipx1) && (x_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
        {
            *(dstPtr + y2_ * destWidth + x_) = color;
        }
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y2_ != clipy1) && (y2_ != clipy2))
        {
            *(dstPtr + y2_ * destWidth + x2_) = color;
        }

        if (dotted)
        {

            if (((pre_x1 - x_) > 3) || ((x2_ - pre_x2) > 3))
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                }
                else if ((x2_ - pre_x2) > 3)
                {
                    dotted_flag = (x2_ - pre_x2) >> 1;
                }

                mid_x1 = x_ + dotted_flag;
                mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);
                mid_x2 = pre_x2 + dotted_flag;
                mid_x2 = (mid_x2 < clipx1) ? clipx1 : ((mid_x2 > clipx2) ? clipx2 : mid_x2);

                if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                    if ((y_ > clipy1) && (x_ < clipx2))
                    {
                        *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                    }
                if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y2_ - 1) != clipy1) && ((y2_ - 1) != clipy2))
                    if ((y2_ < clipy2) && (x_ < clipx2))
                    {
                        *(dstPtr + (y2_ - 1) * destWidth + mid_x1) = color;
                    }
                if ((mid_x2 != clipx1) && (mid_x2 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                    if ((y_ > clipy1) && (x2_ > clipx1))
                    {
                        *(dstPtr + (y_ + 1) * destWidth + mid_x2) = color;
                    }
                if ((mid_x2 != clipx1) && (mid_x2 != clipx2) && ((y2_ - 1) != clipy1) && ((y2_ - 1) != clipy2))
                    if ((y2_ < clipy2) && (x2_ > clipx1))
                    {
                        *(dstPtr + (y2_ - 1) * destWidth + mid_x2) = color;
                    }

            }
            dotted_flag = 1;

        }
        else
        {
            /* 2003 1201 MaoSheng */
            if ((((pre_x1 - x_) > 1) || ((x2_ - pre_x2) > 1)) && (y_ != clipy1) && (y_ != clipy2))
            {
                if (i < arcHeight)
                {
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                }
                else
                {
                    gdi_memset16(
                        (U8*) (dstPtr + x_ - (x_ - x2_) + y_ * destWidth),
                        (U16) color,
                        (x_ - x2_) * 2 + ((pre_x1 - x_) << 1));
                }
                if (x2_ != pre_x2)
                {
                    if ((i < arcHeight))
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x2 + y_ * destWidth), (U16) color, (x2_ - pre_x2) << 1);
                    }
                    else
                    {
                        if ((1 + x2_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x2 + y_ * destWidth),
                                (U16) color,
                                ((x2_ - pre_x2) << 1));
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x2 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x2 - 1) << 1);
                        }
                    }
                }
            }
            if ((((pre_x1 - x_) > 1) || ((x2_ - pre_x2) > 1)) && (y2_ != clipy1) && (y2_ != clipy2))
            {
                if (x2_ != pre_x2)
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x2 + y2_ * destWidth), (U16) color, (x2_ - pre_x2) << 1);
                    }
                    else
                    {
                        if ((1 + x2_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x2 + y2_ * destWidth),
                                (U16) color,
                                ((x2_ - pre_x2) << 1));
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x2 + y2_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x2 - 1) << 1);
                        }
                    }
                }
                if (i < arcHeight)
                {
                    gdi_memset16((U8*) (dstPtr + x_ + y2_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                }
                else
                {
                    gdi_memset16(
                        (U8*) (dstPtr + x_ - (x_ - x2_) + y2_ * destWidth),
                        (U16) color,
                        (x_ - x2_) * 2 + ((pre_x1 - x_) << 1));
                }
            }

        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  gd_draw_quarter_arc16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_draw_quarter_arc16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                unsigned short color,
                int dotted,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, sqr;
    int x_, y_;
    int pre_x1;
    int mid_x1, dotted_flag = 0;
    int x_length, y_length;

    int index, d, Di = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcHeight) */
    if (dotted)
    {
        dotted_flag = 1;
    }
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }
    /* 2003 1203 */
    x_length = x;
    y_length = y;

    /* diection: "clockwise" */
    if (arcCase == 1)
    {   /* phase 1 */
        x_ = (x + arcWidth - 1 < clipx1) ? clipx1 : ((x + arcWidth - 1 > clipx2) ? clipx2 : x + arcWidth - 1);
        y_ = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= arcHeight; i++)
        {
            Di += d;

            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }

            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 < clipx1) ? clipx1 : ((x + sqr - 1 > clipx2) ? clipx2 : x + sqr - 1);
            y_ = (y - i < clipy1) ? clipy1 : ((y - i > clipy2) ? clipy2 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ < clipx2))
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;
            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {

                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }

                    }
                }
            }

        }
    }
    else if (arcCase == 4)
    {   /* phase 4 */
        x_ = (x + arcWidth - 1 < clipx1) ? clipx1 : ((x + arcWidth - 1 > clipx2) ? clipx2 : x + arcWidth - 1);
        y_ = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }

            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 < clipx1) ? clipx1 : ((x + sqr - 1 > clipx2) ? clipx2 : x + sqr - 1);
            y_ = (y + i < clipy1) ? clipy1 : ((y + i > clipy2) ? clipy2 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ < clipx2)) /* modified_2003 1203_MaoSheng */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 3)
    {   /* phase 3 */
        x_ = (x - arcWidth + 1 < clipx1) ? clipx1 : ((x - arcWidth + 1 > clipx2) ? clipx2 : x - arcWidth + 1);
        y_ = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }

            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 < clipx1) ? clipx1 : ((x - sqr + 1 > clipx2) ? clipx2 : x - sqr + 1);
            y_ = (y + i < clipy1) ? clipy1 : ((y + i > clipy2) ? clipy2 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ > clipx1)) /* modified_2003 1203_MaoSheng */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 2)
    {   /* phase 2 */
        x_ = (x - arcWidth + 1 < clipx1) ? clipx1 : ((x - arcWidth + 1 > clipx2) ? clipx2 : x - arcWidth + 1);
        y_ = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }

            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 < clipx1) ? clipx1 : ((x - sqr + 1 > clipx2) ? clipx2 : x - sqr + 1);
            y_ = (y - i < clipy1) ? clipy1 : ((y - i > clipy2) ? clipy2 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ > clipx1)) /* modified_2003 1203_MaoSheng */
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }

                    }
                }
            }

        }   /* end for() */
    }       /* end if() */
}


/*****************************************************************************
 * FUNCTION
 *  gd_draw_arc2_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  arcAn           [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_draw_arc2_16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int arcAn,
                unsigned short color,
                int dotted,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, x_, y_, ye, xe, slope;
    int sitaValue, sqr, arct;
    int mid_x1, dotted_flag = 0;

    int pre_x1;
    int index, d, Di = 0;

    /* 2003 1203 MaoSheng */
    int x_length, y_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_length = x;
    y_length = y;
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }

    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcWidth) */
    if (dotted)
    {
        dotted_flag = 1;
    }

    if (arcCase == 1)
    {
        slope = gd_tan_table[arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;     /* we don't execute the operation ">>10" 
                                                           because we need the scaled value to  
                                                           search the value of act_tangent  */
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x_ = (x + arcWidth - 1 > clipx2) ? clipx2 : ((x + arcWidth - 1 < clipx1) ? clipx1 : x + arcWidth - 1);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= ye; i++)
        {
            Di += d;
            if (dotted_flag && (i != ye))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ < clipx2)) /* modified 2003 1204 */
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 2)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xe = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        Di = d * ye;    /* start_point_shift_value */
        x_ = (x - xe + 1 > clipx2) ? clipx2 : ((x - xe + 1 < clipx1) ? clipx1 : x - xe + 1);
        y_ = (y - ye > clipy2) ? clipy2 : ((y - ye < clipy1) ? clipy1 : y - ye);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ye + 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ > clipx1)) /* modified */
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 3)
    {
        slope = gd_tan_table[arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x_ = (x - arcWidth + 1 > clipx2) ? clipx2 : ((x - arcWidth + 1 < clipx1) ? clipx1 : x - arcWidth + 1);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= ye; i++)
        {
            Di += d;
            if (dotted_flag && (i != ye))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ > clipx1)) /* modified */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 4)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xe = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        Di = d * ye;    /* start_point_shift_value */
        x_ = (x + xe - 1 > clipx2) ? clipx2 : ((x + xe - 1 < clipx1) ? clipx1 : x + xe - 1);
        y_ = (y + ye > clipy2) ? clipy2 : ((y + ye < clipy1) ? clipy1 : y + ye);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ye + 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1203 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ < clipx2)) /* modified */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }
                    }
                }
            }
        }

    }
}

/*****************************************************************************
  (x, y) center point
  clip area (clipx1,clipy1) ~~ (clipx2,clipy2)   
  fillMode  1: fill
  startAn : start angle (0~~360) 
  arcAn   : arc angle   (less then 90)
  startAn+arcAn :  only at 90,180,270,360
*/


/*****************************************************************************
 * FUNCTION
 *  gd_draw_arc3_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  arcAn           [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_draw_arc3_16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int arcAn,
                unsigned short color,
                int dotted,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int i, x_, y_, ys, xs, slope;
    int sitaValue, sqr, arct;
    int mid_x1, dotted_flag = 0;

    int pre_x1;
    int index, d, Di = 0;

    /* 2003 1205 MaoSheng */
    int x_length, y_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_length = x;
    y_length = y;

    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }
    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcWidth) */
    if (dotted)
    {
        dotted_flag = 1;
    }

    if (arcCase == 1)
    {
        slope = gd_tan_table[arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x_ = (x + arcWidth - 1 > clipx2) ? clipx2 : ((x + arcWidth - 1 < clipx1) ? clipx1 : x + arcWidth - 1);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= ys; i++)
        {
            Di += d;
            if (dotted_flag && (i != ys))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1205 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ < clipx2)) /* 2003 1204 */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 2)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xs = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        Di = d * ys;    /* start_point_shift_value */
        x_ = (x - xs + 1 > clipx2) ? clipx2 : ((x - xs + 1 < clipx1) ? clipx1 : x - xs + 1);
        y_ = (y + ys > clipy2) ? clipy2 : ((y + ys < clipy1) ? clipy1 : y + ys);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ys + 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1205 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ > clipx1)) /* modified_2003 1204_MaoSheng */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }

                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }   /* x_length-(x_length-x_)=x_ */
                    }
                }
            }
        }

    }
    else if (arcCase == 3)
    {
        slope = gd_tan_table[arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x_ = (x - arcWidth + 1 > clipx2) ? clipx2 : ((x - arcWidth + 1 < clipx1) ? clipx1 : x - arcWidth + 1);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = 1; i <= ys; i++)
        {
            Di += d;
            if (dotted_flag && (i != ys))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1205 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ > clipx1)) /* 2003 1204 */
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }

                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 4)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xs = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        Di = d * ys;    /* start_point_shift_value */
        x_ = (x + xs - 1 > clipx2) ? clipx2 : ((x + xs - 1 < clipx1) ? clipx1 : x + xs - 1);
        y_ = (y - ys > clipy2) ? clipy2 : ((y - ys < clipy1) ? clipy1 : y - ys);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ys + 1; i <= arcHeight; i++)
        {
            Di += d;
            if (dotted_flag && (i != arcHeight))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1205 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ < clipx2)) /* modified_2003 1204 */
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }
                    }
                }
            }
        }

    }   /* end if(arcCase)  */
}


/*****************************************************************************
 * FUNCTION
 *  gd_draw_arc4_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  startAn         [IN]        
 *  arcAn           [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_draw_arc4_16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int startAn,
                int arcAn,
                unsigned short color,
                int dotted,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int i, x_, y_, ys, ye, xx, slope_s, slope_e;
    int sitaValue, sqr, arct;
    int mid_x1, dotted_flag = 0;

    int pre_x1;
    int index, d, Di = 0;

    /* 2003 1205 MaoSheng */
    int x_length, y_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_length = x;
    y_length = y;
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }

    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcWidth) */
    if (dotted)
    {
        dotted_flag = 1;
    }

    if (arcCase == 1)
    {
        slope_s = gd_tan_table[startAn];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        slope_e = gd_tan_table[arcAn + startAn];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        Di = d * ys;    /* start_point_shift_value */
        x_ = (x + xx - 1 > clipx2) ? clipx2 : ((x + xx - 1 < clipx1) ? clipx1 : x + xx - 1);
        y_ = (y - ys > clipy2) ? clipy2 : ((y - ys < clipy1) ? clipy1 : y - ys);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ys + 1; i <= ye; i++)
        {
            Di += d;
            if (dotted_flag && (i != ye))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1204 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ < clipx2)) /* modified_2003 1204 */
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 2)
    {
        slope_s = gd_tan_table[180 - startAn];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        slope_e = gd_tan_table[180 - arcAn - startAn];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        Di = d * ye;    /* start_point_shift_value */
        x_ = (x - xx + 1 > clipx2) ? clipx2 : ((x - xx + 1 < clipx1) ? clipx1 : x - xx + 1);
        y_ = (y - ye > clipy2) ? clipy2 : ((y - ye < clipy1) ? clipy1 : y - ye);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ye + 1; i <= ys; i++)
        {
            Di += d;
            if (dotted_flag && (i != ys))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1204 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ + 1) != clipy1) && ((y_ + 1) != clipy2))
                        if ((y_ > clipy1) && (x_ > clipx1)) /* modified_2003 1204 */
                        {
                            *(dstPtr + (y_ + 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }

                            gdi_memset16(
                                (U8*) (dstPtr + (y_length - arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }
                    }
                }
            }
        }

    }
    else if (arcCase == 3)
    {
        slope_s = gd_tan_table[startAn - 180];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        slope_e = gd_tan_table[arcAn + startAn - 180];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        Di = d * ys;    /* start_point_shift_value */
        x_ = (x - xx + 1 > clipx2) ? clipx2 : ((x - xx + 1 < clipx1) ? clipx1 : x - xx + 1);
        y_ = (y + ys > clipy2) ? clipy2 : ((y + ys < clipy1) ? clipy1 : y + ys);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ys + 1; i <= ye; i++)
        {
            Di += d;
            if (dotted_flag && (i != ye))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (x_ - pre_x1 > 3)
                {
                    dotted_flag = (x_ - pre_x1) >> 1;
                    mid_x1 = pre_x1 + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1204 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ > clipx1)) /* modified_2003 1204 */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((x_ - pre_x1 > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth), (U16) color, (x_ - pre_x1) << 1);
                    }
                    else
                    {
                        if ((1 + x_) <= clipx2)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (x_ - pre_x1) << 1);
                        }
                        else
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + 1 + pre_x1 + y_ * destWidth),
                                (U16) color,
                                (clipx2 - pre_x1 - 1) << 1);
                        }
                        if (x_length < clipx2)
                        {
                            if (2 * x_length - x_ < clipx2)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                    (U16) color,
                                    (x_length - x_) << 1);
                            }

                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_),
                                (U16) color,
                                (x_length - x_) << 1);
                        }   /* x_length-(x_length-x_)=x_ */
                    }
                }
            }
        }

    }
    else if (arcCase == 4)
    {
        slope_s = gd_tan_table[360 - startAn];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        slope_e = gd_tan_table[360 - arcAn - startAn];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        Di = d * ye;    /* start_point_shift_value */
        x_ = (x + xx - 1 > clipx2) ? clipx2 : ((x + xx - 1 < clipx1) ? clipx1 : x + xx - 1);
        y_ = (y + ye > clipy2) ? clipy2 : ((y + ye < clipy1) ? clipy1 : y + ye);

        if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x_) = color;
        }

        for (i = ye + 1; i <= ys; i++)
        {
            Di += d;
            if (dotted_flag && (i != ys))
            {
                dotted_flag = 0;
                continue;
            }
            index = Di >> 10;
            sqr = (arcWidth * gd_sqrt[index]) >> 10;

            pre_x1 = x_;
            x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);

            if ((x_ != clipx1) && (x_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
            {
                *(dstPtr + y_ * destWidth + x_) = color;
            }

            if (dotted)
            {
                if (pre_x1 - x_ > 3)
                {
                    dotted_flag = (pre_x1 - x_) >> 1;
                    mid_x1 = x_ + dotted_flag;
                    mid_x1 = (mid_x1 < clipx1) ? clipx1 : ((mid_x1 > clipx2) ? clipx2 : mid_x1);

                    /* 2003 1204 MaoSheng */
                    if ((mid_x1 != clipx1) && (mid_x1 != clipx2) && ((y_ - 1) != clipy1) && ((y_ - 1) != clipy2))
                        if ((y_ < clipy2) && (x_ < clipx2)) /* modified_2003 1204 */
                        {
                            *(dstPtr + (y_ - 1) * destWidth + mid_x1) = color;
                        }
                }
                dotted_flag = 1;

            }
            else
            {
                if ((pre_x1 - x_ > 1) && (y_ != clipy1) && (y_ != clipy2))
                {
                    if (i < arcHeight)
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                    }
                    else
                    {
                        gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (pre_x1 - x_) << 1);
                        if (x_length > clipx1)
                        {
                            gdi_memset16(
                                (U8*) (dstPtr + (y_length + arcHeight) * destWidth + x_length),
                                (U16) color,
                                (x_ - x_length) << 1);
                            if ((2 * x_length - x_) >= clipx1)
                            {
                                gdi_memset16(
                                    (U8*) (dstPtr + (y_length + arcHeight) * destWidth + 2 * x_length - x_),
                                    (U16) color,
                                    (x_ - x_length) << 1);
                            }
                        }
                    }
                }
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  gd_draw_arc16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  startAngle      [IN]        
 *  arcAngle        [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_draw_arc16(
        U16 *dstPtr,
        int destWidth,
        int x,
        int y,
        int width,
        int height,
        int startAngle,
        int arcAngle,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color,
        BOOL dotted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int arcWidth, arcHeight;
    int xo, yo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arcWidth = width >> 1;
    arcHeight = height >> 1;
    xo = x + arcWidth;
    yo = y + arcHeight;

    if ((width < 3) || (height < 3))
    {
        return;
    }

    if ((width < 6) && (height < 6))
    {
        int sp = 0, ep = 0, tempx = 0, tempy = 0, i = 0;

        if (startAngle < 45)
        {
            sp = 1;
        }
        else if ((startAngle >= 45) && (startAngle < 90))
        {
            sp = 2;
        }
        else if ((startAngle >= 90) && (startAngle < 135))
        {
            sp = 3;
        }
        else if ((startAngle >= 135) && (startAngle < 180))
        {
            sp = 4;
        }
        else if ((startAngle >= 180) && (startAngle < 225))
        {
            sp = 5;
        }
        else if ((startAngle >= 225) && (startAngle < 270))
        {
            sp = 6;
        }
        else if ((startAngle >= 270) && (startAngle < 315))
        {
            sp = 7;
        }
        else if ((startAngle >= 315))
        {
            sp = 8;
        }

        if ((arcAngle + startAngle) < 45)
        {
            ep = 1;
        }
        else if (((arcAngle + startAngle) >= 45) && ((arcAngle + startAngle) < 90))
        {
            ep = 2;
        }
        else if (((arcAngle + startAngle) >= 90) && ((arcAngle + startAngle) < 135))
        {
            ep = 3;
        }
        else if (((arcAngle + startAngle) >= 135) && ((arcAngle + startAngle) < 180))
        {
            ep = 4;
        }
        else if (((arcAngle + startAngle) >= 180) && ((arcAngle + startAngle) < 225))
        {
            ep = 5;
        }
        else if (((arcAngle + startAngle) >= 225) && ((arcAngle + startAngle) < 270))
        {
            ep = 6;
        }
        else if (((arcAngle + startAngle) >= 270) && ((arcAngle + startAngle) < 315))
        {
            ep = 7;
        }
        else if (((arcAngle + startAngle) >= 315))
        {
            ep = 8;
        }

        if (ep < sp)
        {
            return;
        }
        for (i = sp; i <= ep; i++)
        {
            switch (i)
            {
                case 1:
                    tempx = (x + width - 1 < clipx1) ? clipx1 : ((x + width - 1 > clipx2) ? clipx2 : x + width - 1);
                    if (height == 5)
                    {
                        tempy = (y + 2 < clipy1) ? clipy1 : ((y + 2 > clipy2) ? clipy2 : y + 2);
                        if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                        {
                            *(dstPtr + (tempy * destWidth + tempx)) = color;
                        }
                    }
                    tempy = (y + 1 < clipy1) ? clipy1 : ((y + 1 > clipy2) ? clipy2 : y + 1);
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

                case 2:
                    tempy = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);
                    if (width == 5)
                    {
                        tempx = (x + 3 < clipx1) ? clipx1 : ((x + 3 > clipx2) ? clipx2 : x + 3);
                    }
                    else if (width == 4)
                    {
                        tempx = (x + 2 < clipx1) ? clipx1 : ((x + 2 > clipx2) ? clipx2 : x + 2);
                    }
                    else if (width == 3)
                    {
                        tempx = (x + 1 < clipx1) ? clipx1 : ((x + 1 > clipx2) ? clipx2 : x + 1);
                    }
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

                case 3:
                    tempy = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);
                    if (width == 5)
                    {
                        tempx = (x + 2 < clipx1) ? clipx1 : ((x + 2 > clipx2) ? clipx2 : x + 2);
                        if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                        {
                            *(dstPtr + (tempy * destWidth + tempx)) = color;
                        }
                    }
                    tempx = (x + 1 < clipx1) ? clipx1 : ((x + 1 > clipx2) ? clipx2 : x + 1);
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

                case 4:
                    tempx = (x < clipx1) ? clipx1 : ((x > clipx2) ? clipx2 : x);

                    if (height == 5)
                    {
                        tempy = (y + 2 < clipy1) ? clipy1 : ((y + 2 > clipy2) ? clipy2 : y + 2);
                        if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                        {
                            *(dstPtr + (tempy * destWidth + tempx)) = color;
                        }
                    }

                    tempy = (y + 1 < clipy1) ? clipy1 : ((y + 1 > clipy2) ? clipy2 : y + 1);
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

                case 5:
                    tempx = (x < clipx1) ? clipx1 : ((x > clipx2) ? clipx2 : x);

                    if (height == 5)
                    {
                        tempy = (y + 3 < clipy1) ? clipy1 : ((y + 3 > clipy2) ? clipy2 : y + 3);
                    }
                    else if (height == 4)
                    {
                        tempy = (y + 2 < clipy1) ? clipy1 : ((y + 2 > clipy2) ? clipy2 : y + 2);
                    }
                    else if (height == 3)
                    {
                        tempy = (y + 1 < clipy1) ? clipy1 : ((y + 1 > clipy2) ? clipy2 : y + 1);
                    }
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

                case 6:
                    tempy = (y + height - 1 < clipy1) ? clipy1 : ((y + height - 1 > clipy2) ? clipy2 : y + height - 1);
                    if (width == 5)
                    {
                        tempx = (x + 2 < clipx1) ? clipx1 : ((x + 2 > clipx2) ? clipx2 : x + 2);
                        if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                        {
                            *(dstPtr + (tempy * destWidth + tempx)) = color;
                        }
                    }
                    tempx = (x + 1 < clipx1) ? clipx1 : ((x + 1 > clipx2) ? clipx2 : x + 1);
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

                case 7:
                    tempy = (y + height - 1 < clipy1) ? clipy1 : ((y + height - 1 > clipy2) ? clipy2 : y + height - 1);
                    if (width == 5)
                    {
                        tempx = (x + 3 < clipx1) ? clipx1 : ((x + 3 > clipx2) ? clipx2 : x + 3);
                    }
                    else if (width == 4)
                    {
                        tempx = (x + 2 < clipx1) ? clipx1 : ((x + 2 > clipx2) ? clipx2 : x + 2);
                    }
                    else if (width == 3)
                    {
                        tempx = (x + 1 < clipx1) ? clipx1 : ((x + 1 > clipx2) ? clipx2 : x + 1);
                    }
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

                case 8:
                    tempx = (x + width - 1 < clipx1) ? clipx1 : ((x + width - 1 > clipx2) ? clipx2 : x + width - 1);

                    if (height == 5)
                    {
                        tempy = (y + 3 < clipy1) ? clipy1 : ((y + 3 > clipy2) ? clipy2 : y + 3);
                    }
                    else if (height == 4)
                    {
                        tempy = (y + 2 < clipy1) ? clipy1 : ((y + 2 > clipy2) ? clipy2 : y + 2);
                    }
                    else if (height == 3)
                    {
                        tempy = (y + 1 < clipy1) ? clipy1 : ((y + 1 > clipy2) ? clipy2 : y + 1);
                    }
                    if ((tempx != clipx1) && (tempx != clipx2) && (tempy != clipy1) && (tempy != clipy2))
                    {
                        *(dstPtr + (tempy * destWidth + tempx)) = color;
                    }
                    break;

            }
        }

    }
    else
    {

        if ((arcAngle >= 360) && (width == height))
        {   /* draw circle */
            gd_draw_ellipse16(
                dstPtr,
                destWidth,
                xo,
                yo,
                arcWidth,
                arcHeight,
                clipx1,
                clipy1,
                clipx2,
                clipy2,
                (U16) color,
                dotted);
        }
        else
        {   /* draw arc */
            if (arcAngle >= 360)
            {
                gd_draw_ellipse16(
                    dstPtr,
                    destWidth,
                    xo,
                    yo,
                    arcWidth,
                    arcHeight,
                    clipx1,
                    clipy1,
                    clipx2,
                    clipy2,
                    (U16) color,
                    dotted);
            }
            else if (startAngle == 0)
            {

                if (arcAngle < 90)
                {
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if (arcAngle == 90)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if (arcAngle == 180)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if (arcAngle == 270)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }

            }
            else if (startAngle == 90)
            {
                if (arcAngle < 90)
                {
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if (arcAngle == 90)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if (arcAngle == 180)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if (arcAngle == 270)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }

            }
            else if (startAngle == 180)
            {
                if (arcAngle < 90)
                {
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if (arcAngle == 90)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if (arcAngle == 180)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if (arcAngle == 270)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }

            }
            else if (startAngle == 270)
            {
                if (arcAngle < 90)
                {

                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if (arcAngle == 90)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if (arcAngle == 180)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if (arcAngle == 270)
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_draw_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_draw_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        dotted,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }

            }
            else
            {
                if ((arcAngle + startAngle) == 360)
                {
                    if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }
                    else if (startAngle < 90)
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }

                }
                else if (((arcAngle + startAngle) == 270) || ((arcAngle + startAngle) == 630))
                {
                    if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }
                    else if (startAngle < 90)
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }

                }
                else if (((arcAngle + startAngle) == 180) || ((arcAngle + startAngle) == 540))
                {
                    if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }
                    else if (startAngle < 90)
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }

                }
                else if (((arcAngle + startAngle) == 90) || ((arcAngle + startAngle) == 450))
                {
                    if (startAngle < 90)
                    {
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_draw_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_draw_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            dotted,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }

                }
                else
                {

                    if (startAngle < 90)
                    {
                        if ((startAngle + arcAngle) < 90)
                        {
                            gd_draw_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 90) && ((startAngle + arcAngle) < 180))
                        {
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 90),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 180) && ((startAngle + arcAngle) < 270))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 180),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 270),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {

                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }

                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        if (((startAngle + arcAngle) > 90) && ((startAngle + arcAngle) < 180))
                        {
                            gd_draw_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 180) && ((startAngle + arcAngle) < 270))
                        {
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 180),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 270),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 450) && ((startAngle + arcAngle) < 540))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 450),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        if (((startAngle + arcAngle) > 180) && ((startAngle + arcAngle) < 270))
                        {
                            gd_draw_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 270),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 450) && ((startAngle + arcAngle) < 540))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 450),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 540) && ((startAngle + arcAngle) < 630))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 540),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_draw_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 450) && ((startAngle + arcAngle) < 540))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 450),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 540) && ((startAngle + arcAngle) < 630))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 540),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 630) && ((startAngle + arcAngle) < 720))
                        {
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_draw_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_draw_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_draw_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 630),
                                (U16) color,
                                dotted,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                    }   /* end if(startAngle<90)   */
                }       /* end if( ((arcAngle+startAngle)==360) || ((arcAngle+startAngle)==270) || ((arcAngle+startAngle)==180) || ((arcAngle+startAngle)==900) )   */
            }           /* end if( arcAngle>=360 ) */
        }               /* end if(  (arcAngle>=360) && (width == h) ) */

    }   /* end if((w < 2) || (h < 2)) */
}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_ellipse16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_fill_ellipse16(
        U16 *dstPtr,
        int destWidth,
        int x,
        int y,
        int arcWidth,
        int arcHeight,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, sqr;
    int x_, y_, x2_, y2_;

    int index, d, Di;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcHeight) */
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }
    y_ = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);
    if ((y_ != clipy1) && (y_ != clipy2))
    {
        x_ = (x + arcWidth - 1 < clipx1) ? clipx1 : ((x + arcWidth - 1 > clipx2) ? clipx2 : x + arcWidth - 1);
        x2_ = (x - arcWidth + 1 < clipx1) ? clipx1 : ((x - arcWidth + 1 > clipx2) ? clipx2 : x - arcWidth + 1);
        gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
    }

    Di = 0; /* start_point_shift_value */
    for (i = 1; i < arcHeight; i++)
    {
        Di += d;
        index = Di >> 10;
        sqr = (arcWidth * gd_sqrt[index]) >> 10;

        x_ = (x + sqr < clipx1) ? clipx1 : ((x + sqr > clipx2) ? clipx2 : x + sqr);
        x2_ = (x - sqr < clipx1) ? clipx1 : ((x - sqr > clipx2) ? clipx2 : x - sqr);
        y_ = (y - i < clipy1) ? clipy1 : ((y - i > clipy2) ? clipy2 : y - i);
        y2_ = (y + i < clipy1) ? clipy1 : ((y + i > clipy2) ? clipy2 : y + i);

        if ((y_ >= clipy1) && (y_ <= clipy2) && ((x_ - x2_) > 0))
        {
            gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }

        if ((y2_ >= clipy1) && (y2_ <= clipy2) && ((x_ - x2_) > 0))
        {
            gdi_memset16((U8*) (dstPtr + x2_ + y2_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_quarter_arc16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  color           [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_fill_quarter_arc16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                unsigned short color,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, sqr;
    int x_, y_, x2_;

    int index, d, Di = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcHeight) */
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }
    x2_ = (x < clipx1) ? clipx1 : ((x > clipx2) ? clipx2 : x);
    y_ = (y < clipy1) ? clipy1 : ((y > clipy2) ? clipy2 : y);

    if (arcCase == 1)
    {
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + arcWidth - 1 < clipx1) ? clipx1 : ((x + arcWidth - 1 > clipx2) ? clipx2 : x + arcWidth - 1);
            gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }
        for (i = 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y - i < clipy1) ? clipy1 : ((y - i > clipy2) ? clipy2 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 < clipx1) ? clipx1 : ((x + sqr - 1 > clipx2) ? clipx2 : x + sqr - 1);
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

    }
    else if (arcCase == 4)
    {
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + arcWidth - 1 < clipx1) ? clipx1 : ((x + arcWidth - 1 > clipx2) ? clipx2 : x + arcWidth - 1);
            gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }

        for (i = 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y + i < clipy1) ? clipy1 : ((y + i > clipy2) ? clipy2 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 < clipx1) ? clipx1 : ((x + sqr - 1 > clipx2) ? clipx2 : x + sqr - 1);
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

    }
    else if (arcCase == 3)
    {
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - arcWidth + 1 < clipx1) ? clipx1 : ((x - arcWidth + 1 > clipx2) ? clipx2 : x - arcWidth + 1);
            gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
        }

        for (i = 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y + i < clipy1) ? clipy1 : ((y + i > clipy2) ? clipy2 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 < clipx1) ? clipx1 : ((x - sqr + 1 > clipx2) ? clipx2 : x - sqr + 1);
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }

    }
    else if (arcCase == 2)
    {
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - arcWidth + 1 < clipx1) ? clipx1 : ((x - arcWidth + 1 > clipx2) ? clipx2 : x - arcWidth + 1);
            gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
        }

        for (i = 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y - i < clipy1) ? clipy1 : ((y - i > clipy2) ? clipy2 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 < clipx1) ? clipx1 : ((x - sqr + 1 > clipx2) ? clipx2 : x - sqr + 1);
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_arc2_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  arcAn           [IN]        
 *  color           [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_fill_arc2_16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int arcAn,
                unsigned short color,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, x_, y_, x2_, ye, xe, slope;
    int sitaValue, sqr, arct;

    int index, d, Di = 0, lineSlope;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcWidth)  */
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }

    if (arcCase == 1)
    {
        slope = gd_tan_table[arcAn];
        lineSlope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;     /* we don't execute the operation ">>10" 
                                                           because we need the scaled value to  
                                                           search the value of act_tangent */
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);

        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + arcWidth - 1 > clipx2) ? clipx2 : ((x + arcWidth - 1 < clipx1) ? clipx1 : x + arcWidth - 1);
            if ((x_ != clipx1) && (x2_ != clipx2))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

        for (i = 1; i < ye; i++)
        {
            Di += d;
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);

                x2_ = x + ((i * lineSlope) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

    }
    else if (arcCase == 2)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);

        lineSlope = gd_tan_table[arcAn];
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xe = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ye; i++)
        {
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x - ((i * lineSlope) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    if ((x2_ - x_) == 0)
                    {
                        x2_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

        Di = d * ye;    /* start_point_shift_value */
        y_ = (y - ye > clipy2) ? clipy2 : ((y - ye < clipy1) ? clipy1 : y - ye);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - xe + 1 > clipx2) ? clipx2 : ((x - xe + 1 < clipx1) ? clipx1 : x - xe + 1);
            gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
        }
        for (i = ye + 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }

    }
    else if (arcCase == 3)
    {
        slope = gd_tan_table[arcAn];
        lineSlope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - arcWidth + 1 > clipx2) ? clipx2 : ((x - arcWidth + 1 < clipx1) ? clipx1 : x - arcWidth + 1);
            if ((x_ != clipx2) && (x2_ != clipx1))
            {
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }

        for (i = 1; i < ye; i++)
        {
            Di += d;
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);

                x2_ = x - ((i * lineSlope) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

    }
    else if (arcCase == 4)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);

        lineSlope = gd_tan_table[arcAn];
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xe = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ye; i++)
        {
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x + ((i * lineSlope) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    if ((x_ - x2_) == 0)
                    {
                        x_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

        Di = d * ye;    /* start_point_shift_value */
        y_ = (y + ye > clipy2) ? clipy2 : ((y + ye < clipy1) ? clipy1 : y + ye);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + xe - 1 > clipx2) ? clipx2 : ((x + xe - 1 < clipx1) ? clipx1 : x + xe - 1);
            gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }

        for (i = ye + 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_arc3_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  arcAn           [IN]        
 *  color           [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_fill_arc3_16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int arcAn,
                unsigned short color,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int i, x_, y_, x2_, ys, xs, slope;
    int sitaValue, sqr, arct;

    int index, d, Di = 0, lineSlope;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcWidth) */
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }

    if (arcCase == 1)
    {
        slope = gd_tan_table[arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);

        lineSlope = gd_tan_table[90 - arcAn];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + arcWidth - 1 > clipx2) ? clipx2 : ((x + arcWidth - 1 < clipx1) ? clipx1 : x + arcWidth - 1);
            if ((x_ != clipx1) && (x2_ != clipx2))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }
        for (i = 1; i < ys; i++)
        {
            Di += d;
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);

                x2_ = x + ((i * lineSlope) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

    }
    else if (arcCase == 2)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);

        lineSlope = gd_tan_table[arcAn];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xs = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ys; i++)
        {
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x - ((i * lineSlope) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    if ((x2_ - x_) == 0)
                    {
                        x2_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

        Di = d * ys;    /* start_point_shift_value */
        y_ = (y + ys > clipy2) ? clipy2 : ((y + ys < clipy1) ? clipy1 : y + ys);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - xs + 1 > clipx2) ? clipx2 : ((x - xs + 1 < clipx1) ? clipx1 : x - xs + 1);
            gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
        }

        for (i = ys + 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }

    }
    else if (arcCase == 3)
    {
        slope = gd_tan_table[arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);

        lineSlope = gd_tan_table[90 - arcAn];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - arcWidth + 1 > clipx2) ? clipx2 : ((x - arcWidth + 1 < clipx1) ? clipx1 : x - arcWidth + 1);
            if ((x_ != clipx2) && (x2_ != clipx1))
            {
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }

        for (i = 1; i < ys; i++)
        {
            Di += d;
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);

                x2_ = x - ((i * lineSlope) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

    }
    else if (arcCase == 4)
    {
        slope = gd_tan_table[90 - arcAn];
        sitaValue = (arcWidth * slope) / arcHeight;
        arct = gdi_atan(sitaValue);

        lineSlope = gd_tan_table[arcAn];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xs = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ys; i++)
        {
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x + ((i * lineSlope) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    if ((x_ - x2_) == 0)
                    {
                        x_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

        Di = d * ys;    /* start_point_shift_value */
        y_ = (y - ys > clipy2) ? clipy2 : ((y - ys < clipy1) ? clipy1 : y - ys);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + xs - 1 > clipx2) ? clipx2 : ((x + xs - 1 < clipx1) ? clipx1 : x + xs - 1);
            gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
        }

        for (i = ys + 1; i < arcHeight; i++)
        {
            Di += d;
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_arc4_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  arcWidth        [IN]        
 *  arcHeight       [IN]        
 *  startAn         [IN]        
 *  arcAn           [IN]        
 *  color           [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  arcCase         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gd_fill_arc4_16(
                U16 *dstPtr,
                int destWidth,
                int x,
                int y,
                int arcWidth,
                int arcHeight,
                int startAn,
                int arcAn,
                unsigned short color,
                int clipx1,
                int clipy1,
                int clipx2,
                int clipy2,
                int arcCase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, x_, y_, x2_, ys, xx, ye, slope_s, slope_e;
    int sitaValue, sqr, arct;

    int index, d, Di, lineSlope_e, lineSlope_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2003 0920 Hsu */
    if (arcHeight == 0)
    {
        arcHeight = 1;
    }
    d = 1048576 / arcHeight;    /* (1024*1024/arcWidth) */
    if ((clipy2--) < 0)
    {
        clipy2 = 0;
    }

    if (arcCase == 1)
    {
        slope_s = gd_tan_table[startAn];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_s = gd_tan_table[90 - startAn];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        slope_e = gd_tan_table[arcAn + startAn];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_e = gd_tan_table[90 - (arcAn + startAn)];
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ys; i++)
        {
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x + ((i * lineSlope_s) >> 10);
                x2_ = x + ((i * lineSlope_e) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    if ((x_ - x2_) == 0)
                    {
                        x_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

        Di = d * ys;    /* start_point_shift_value */
        y_ = (y - ys > clipy2) ? clipy2 : ((y - ys < clipy1) ? clipy1 : y - ys);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + xx - 1 > clipx2) ? clipx2 : ((x + xx - 1 < clipx1) ? clipx1 : x + xx - 1);

            x2_ = x + ((ys * lineSlope_e) >> 10);
            x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
            if ((x_ != clipx1) && (x2_ != clipx2))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

        for (i = ys + 1; i < ye; i++)
        {
            Di += d;
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);

                x2_ = x + ((i * lineSlope_e) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

    }
    else if (arcCase == 2)
    {
        slope_s = gd_tan_table[180 - startAn];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_s = gd_tan_table[startAn - 90];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        slope_e = gd_tan_table[180 - arcAn - startAn];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_e = gd_tan_table[(arcAn + startAn) - 90];
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ye; i++)
        {
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x - ((i * lineSlope_e) >> 10);
                x2_ = x - ((i * lineSlope_s) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    if ((x2_ - x_) == 0)
                    {
                        x2_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

        Di = d * ye;    /* start_point_shift_value */
        y_ = (y - ye > clipy2) ? clipy2 : ((y - ye < clipy1) ? clipy1 : y - ye);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - xx + 1 > clipx2) ? clipx2 : ((x - xx + 1 < clipx1) ? clipx1 : x - xx + 1);

            x2_ = x - ((ye * lineSlope_s) >> 10);
            x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
            if ((x_ != clipx2) && (x2_ != clipx1))
            {
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }
        for (i = ye + 1; i < ys; i++)
        {
            Di += d;
            y_ = (y - i > clipy2) ? clipy2 : ((y - i < clipy1) ? clipy1 : y - i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);

                x2_ = x - ((i * lineSlope_s) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

    }
    else if (arcCase == 3)
    {
        slope_s = gd_tan_table[startAn - 180];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_s = gd_tan_table[270 - startAn];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        slope_e = gd_tan_table[arcAn + startAn - 180];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_e = gd_tan_table[270 - (arcAn + startAn)];
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ys; i++)
        {
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x - ((i * lineSlope_s) >> 10);
                x2_ = x - ((i * lineSlope_e) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    if ((x2_ - x_) == 0)
                    {
                        x2_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

        Di = d * ys;    /* start_point_shift_value */
        y_ = (y + ys > clipy2) ? clipy2 : ((y + ys < clipy1) ? clipy1 : y + ys);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x - xx + 1 > clipx2) ? clipx2 : ((x - xx + 1 < clipx1) ? clipx1 : x - xx + 1);

            x2_ = x - ((ys * lineSlope_e) >> 10);
            x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
            if ((x_ != clipx2) && (x2_ != clipx1))
            {
                gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
            }
        }

        for (i = ys + 1; i < ye; i++)
        {
            Di += d;
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x - sqr + 1 > clipx2) ? clipx2 : ((x - sqr + 1 < clipx1) ? clipx1 : x - sqr + 1);

                x2_ = x - ((i * lineSlope_e) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx2) && (x2_ != clipx1))
                {
                    gdi_memset16((U8*) (dstPtr + x_ + y_ * destWidth), (U16) color, (x2_ - x_) << 1);
                }
            }
        }

    }
    else if (arcCase == 4)
    {
        slope_s = gd_tan_table[360 - startAn];
        sitaValue = (arcWidth * slope_s) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_s = gd_tan_table[startAn - 270];
        ys = (int)((arcHeight * gd_sin_table[arct]) >> 10);

        slope_e = gd_tan_table[360 - arcAn - startAn];
        sitaValue = (arcWidth * slope_e) / arcHeight;
        arct = gdi_atan(sitaValue);
        lineSlope_e = gd_tan_table[(arcAn + startAn) - 270];
        ye = (int)((arcHeight * gd_sin_table[arct]) >> 10);
        xx = (int)((arcWidth * gd_sin_table[90 - arct]) >> 10);

        x2_ = (x > clipx2) ? clipx2 : ((x < clipx1) ? clipx1 : x);
        y_ = (y > clipy2) ? clipy2 : ((y < clipy1) ? clipy1 : y);
        if ((x2_ != clipx1) && (x2_ != clipx2) && (y_ != clipy1) && (y_ != clipy2))
        {
            *(dstPtr + y_ * destWidth + x2_) = color;
        }

        for (i = 1; i < ye; i++)
        {
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                x_ = x + ((i * lineSlope_e) >> 10);
                x2_ = x + ((i * lineSlope_s) >> 10);
                x_ = (x_ > clipx2) ? clipx2 : ((x_ < clipx1) ? clipx1 : x_);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    if ((x_ - x2_) == 0)
                    {
                        x_ += 1;
                    }
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

        Di = d * ye;    /* start_point_shift_value */
        y_ = (y + ye > clipy2) ? clipy2 : ((y + ye < clipy1) ? clipy1 : y + ye);
        if ((y_ != clipy1) && (y_ != clipy2))
        {
            x_ = (x + xx - 1 > clipx2) ? clipx2 : ((x + xx - 1 < clipx1) ? clipx1 : x + xx - 1);

            x2_ = x + ((ye * lineSlope_s) >> 10);
            x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
            if ((x_ != clipx1) && (x2_ != clipx2))
            {
                gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
            }
        }

        for (i = ye + 1; i < ys; i++)
        {
            Di += d;
            y_ = (y + i > clipy2) ? clipy2 : ((y + i < clipy1) ? clipy1 : y + i);
            if ((y_ != clipy1) && (y_ != clipy2))
            {
                index = Di >> 10;
                sqr = (arcWidth * gd_sqrt[index]) >> 10;
                x_ = (x + sqr - 1 > clipx2) ? clipx2 : ((x + sqr - 1 < clipx1) ? clipx1 : x + sqr - 1);
                x2_ = x + ((i * lineSlope_s) >> 10);
                x2_ = (x2_ > clipx2) ? clipx2 : ((x2_ < clipx1) ? clipx1 : x2_);
                if ((x_ != clipx1) && (x2_ != clipx2))
                {
                    gdi_memset16((U8*) (dstPtr + x2_ + y_ * destWidth), (U16) color, (x_ - x2_) << 1);
                }
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  gd_fill_arc16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dstPtr          [?]         
 *  destWidth       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  startAngle      [IN]        
 *  arcAngle        [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_fill_arc16(
        U16 *dstPtr,
        int destWidth,
        int x,
        int y,
        int width,
        int height,
        int startAngle,
        int arcAngle,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int arcWidth, arcHeight;
    int xo, yo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arcWidth = width >> 1;
    arcHeight = height >> 1;
    xo = x + arcWidth;
    yo = y + arcHeight;

    if ((width < 3) || (height < 3))
    {
        return;
    }
    else
    {

        if ((arcAngle >= 360) && (width == height))
        {   /* fill circle */
            gd_fill_ellipse16(
                dstPtr,
                destWidth,
                xo,
                yo,
                arcWidth,
                arcHeight,
                clipx1,
                clipy1,
                clipx2,
                clipy2,
                (U16) color);
        }
        else
        {   /* fill arc */
            if (arcAngle >= 360)
            {
                gd_fill_ellipse16(
                    dstPtr,
                    destWidth,
                    xo,
                    yo,
                    arcWidth,
                    arcHeight,
                    clipx1,
                    clipy1,
                    clipx2,
                    clipy2,
                    (U16) color);
            }
            else if (startAngle == 0)
            {

                if (arcAngle < 90)
                {
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if (arcAngle == 90)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if (arcAngle == 180)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if (arcAngle == 270)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }

            }
            else if (startAngle == 90)
            {
                if (arcAngle < 90)
                {
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if (arcAngle == 90)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if (arcAngle == 180)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if (arcAngle == 270)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }

            }
            else if (startAngle == 180)
            {
                if (arcAngle < 90)
                {
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if (arcAngle == 90)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if (arcAngle == 180)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if (arcAngle == 270)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }

            }
            else if (startAngle == 270)
            {
                if (arcAngle < 90)
                {
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        arcAngle,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if (arcAngle == 90)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                }
                else if ((arcAngle > 90) && (arcAngle < 180))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 90),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if (arcAngle == 180)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                }
                else if ((arcAngle > 180) && (arcAngle < 270))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 180),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if (arcAngle == 270)
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                }
                else if ((arcAngle > 270) && (arcAngle < 360))
                {
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        4);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        1);
                    gd_fill_quarter_arc16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        2);
                    gd_fill_arc2_16(
                        dstPtr,
                        destWidth,
                        xo,
                        yo,
                        arcWidth,
                        arcHeight,
                        (arcAngle - 270),
                        (U16) color,
                        clipx1,
                        clipy1,
                        clipx2,
                        clipy2,
                        3);
                }

            }
            else
            {
                if ((arcAngle + startAngle) == 360)
                {
                    if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }
                    else if (startAngle < 90)
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }

                }
                else if (((arcAngle + startAngle) == 270) || ((arcAngle + startAngle) == 630))
                {
                    if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }
                    else if (startAngle < 90)
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }

                }
                else if (((arcAngle + startAngle) == 180) || ((arcAngle + startAngle) == 540))
                {
                    if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }
                    else if (startAngle < 90)
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }

                }
                else if (((arcAngle + startAngle) == 90) || ((arcAngle + startAngle) == 450))
                {
                    if (startAngle < 90)
                    {
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            arcAngle,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 90),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 180),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            2);
                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            1);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            4);
                        gd_fill_quarter_arc16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                        gd_fill_arc3_16(
                            dstPtr,
                            destWidth,
                            xo,
                            yo,
                            arcWidth,
                            arcHeight,
                            (arcAngle - 270),
                            (U16) color,
                            clipx1,
                            clipy1,
                            clipx2,
                            clipy2,
                            3);
                    }

                }
                else
                {

                    if (startAngle < 90)
                    {
                        if ((startAngle + arcAngle) < 90)
                        {
                            gd_fill_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 90) && ((startAngle + arcAngle) < 180))
                        {
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 90),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 180) && ((startAngle + arcAngle) < 270))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 180),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 270),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {

                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (90 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }

                    }
                    else if ((startAngle > 90) && (startAngle < 180))
                    {
                        if (((startAngle + arcAngle) > 90) && ((startAngle + arcAngle) < 180))
                        {
                            gd_fill_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 180) && ((startAngle + arcAngle) < 270))
                        {
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 180),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 270),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 450) && ((startAngle + arcAngle) < 540))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (180 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 450),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                    }
                    else if ((startAngle > 180) && (startAngle < 270))
                    {
                        if (((startAngle + arcAngle) > 180) && ((startAngle + arcAngle) < 270))
                        {
                            gd_fill_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 270),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 450) && ((startAngle + arcAngle) < 540))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 450),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 540) && ((startAngle + arcAngle) < 630))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (270 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 540),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                    }
                    else if ((startAngle > 270) && (startAngle < 360))
                    {
                        if (((startAngle + arcAngle) > 270) && ((startAngle + arcAngle) < 360))
                        {
                            gd_fill_arc4_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                startAngle,
                                arcAngle,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                        else if (((startAngle + arcAngle) > 360) && ((startAngle + arcAngle) < 450))
                        {
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 360),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                        }
                        else if (((startAngle + arcAngle) > 450) && ((startAngle + arcAngle) < 540))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 450),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                        }
                        else if (((startAngle + arcAngle) > 540) && ((startAngle + arcAngle) < 630))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 540),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                        }
                        else if (((startAngle + arcAngle) > 630) && ((startAngle + arcAngle) < 720))
                        {
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                2);
                            gd_fill_quarter_arc16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                3);
                            gd_fill_arc3_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (360 - startAngle),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                1);
                            gd_fill_arc2_16(
                                dstPtr,
                                destWidth,
                                xo,
                                yo,
                                arcWidth,
                                arcHeight,
                                (startAngle + arcAngle - 630),
                                (U16) color,
                                clipx1,
                                clipy1,
                                clipx2,
                                clipy2,
                                4);
                        }
                    }   /* end if(startAngle<90)   */
                }       /* end if( ((arcAngle+startAngle)==360) || ((arcAngle+startAngle)==270) || ((arcAngle+startAngle)==180) || ((arcAngle+startAngle)==900) )      */
            }           /* end if( arcAngle>=360 ) */
        }               /* end if(  (arcAngle>=360) && (width == h) ) */

    }   /* end if((width < 2) || (h < 2)) */
}

/* Maximum width for this function is only 512 */


/*****************************************************************************
 * FUNCTION
 *  gd_fill_triangle16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imgp            [?]         
 *  destWidth       [IN]        
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  x3              [IN]        
 *  y3              [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  color           [IN]        
 *  dotted          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_fill_triangle16(
        U16 *imgp,
        int destWidth,
        int x1,
        int y1,
        int x2,
        int y2,
        int x3,
        int y3,
        int clipx1,
        int clipy1,
        int clipx2,
        int clipy2,
        gdi_color color,
        BOOL dotted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int x[3], y[3];
    int yStart = 0, yEnd = 0;
    int i = 0, yStop = 0, yStart2 = 0;

    // int LB=0;    /* xB<xC  */
    int Drawing = 0;    /* drawing second part of triangle   
                           0->normal, 1->only first, 2->only second  */
    int slope[3];
    int constant[3];
    int p1 = 0, p2 = 0;
    int xf1 = 0, xf2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arrange the vertics in sequence from top to bottom  */
    if (y1 < y2)
    {
        y[0] = y1;
        x[0] = x1;
        y[1] = y2;
        x[1] = x2;
        y[2] = y3;
        x[2] = x3;
    }
    else
    {
        y[0] = y2;
        x[0] = x2;
        y[1] = y1;
        x[1] = x1;
        y[2] = y3;
        x[2] = x3;
    }

    if (y3 < y[0])
    {
        y[2] = y[1];
        x[2] = x[1];
        y[1] = y[0];
        x[1] = x[0];
        y[0] = y3;
        x[0] = x3;
    }
    else if (y3 < y[1])
    {
        y[2] = y[1];
        x[2] = x[1];
        y[1] = y3;
        x[1] = x3;
    }

    /* check the position of pB and pC */
    /* if (x[1] > x[2]) LB=1; */

    /* check if the desired triangle out of clipping area */
    if ((y[0] > clipy2) || (y[2] < clipy1))
    {
        return;
    }

    {
        int xMax = 0, xMin = 9999;

        for (i = 0; i < 3; i++)
        {
            if (x[i] > xMax)
            {
                xMax = x[i];
            }
            if (x[i] < xMin)
            {
                xMin = x[i];
            }
        }
        if ((xMin > clipx2) || (xMax < clipx1))
        {
            return;
        }
    }

    /* decide the start and finish y-position */
    yStart = (y[0] < clipy1) ? clipy1 : y[0];
    yEnd = (y[2] > clipy2) ? clipy2 : y[2];
    yStart2 = yStop = y[1];

    if (y[1] < yStart)
    {
        Drawing = 2;
        yStart2 = yStart;
    }
    else if (y[1] > clipy2)
    {
        yEnd = clipy2;
        yStop = yEnd;
        Drawing = 1;
    }

    /* start to draw triangle... */
    {
        int dx, dy;

        for (i = 0; i < 3; i++)
        {
            if (i == 2)
            {
                dx = x[i] - x[0];
                dy = y[i] - y[0];
            }
            else
            {
                dx = x[i + 1] - x[i];
                dy = y[i + 1] - y[i];
            }

            if (dy == 0)
            {
                slope[i] = 0;
            }
            /* 13 + 9 + 9 = 31  max width will be 512 */
            else
            {
                slope[i] = (dx << 13) / dy;
            }
            constant[i] = x[i] - ((slope[i] * y[i]) >> 13);
        }
    }

    if ((Drawing == 0) || (Drawing == 1))
    {
        /* 2006 0323 Hsu */
        for (i = yStart; i < yStop; i++)
        {
            p1 = constant[0] + ((slope[0] * i) >> 13);
            p2 = constant[2] + ((slope[2] * i) >> 13);
            xf1 = (p1 > clipx2) ? clipx2 : ((p1 < clipx1) ? clipx1 : p1);
            xf2 = (p2 > clipx2) ? clipx2 : ((p2 < clipx1) ? clipx1 : p2);
            if (xf2 > xf1)
            {
                /* int len = (xf2-xf1)<<1; */
                gdi_memset16((U8*) (imgp + xf1 + i * destWidth), (U16) color, (xf2 - xf1) << 1);
                /*          MEMSET_16_((dst_->data + xf1 + j * destWidth)  ,color, (xf2-xf1)); */
            }
            else if (xf2 < xf1)
            {
                gdi_memset16((U8*) (imgp + xf2 + i * destWidth), (U16) color, (xf1 - xf2) << 1);
            }
        }

    }

    if ((Drawing == 0) || (Drawing == 2))
    {
        /* 2006 0323 Hsu */
        for (i = yStart2; i < yEnd; i++)
        {
            p1 = constant[1] + ((slope[1] * i) >> 13);
            p2 = constant[2] + ((slope[2] * i) >> 13);
            xf1 = (p1 > clipx2) ? clipx2 : ((p1 < clipx1) ? clipx1 : p1);
            xf2 = (p2 > clipx2) ? clipx2 : ((p2 < clipx1) ? clipx1 : p2);

            if (xf2 > xf1)
            {
                /* int len = (xf2-xf1)<<1; */
                gdi_memset16((U8*) (imgp + xf1 + i * destWidth), (U16) color, (xf2 - xf1) << 1);
                /*          MEMSET_16_( (dst_->data + xf1 + j * destWidth)  ,color, (xf2-xf1)); */
            }
            else if (xf2 < xf1)
            {
                gdi_memset16((U8*) (imgp + xf2 + i * destWidth), (U16) color, (xf1 - xf2) << 1);
            }
        }

    }
}

#if defined(__MTK_TARGET__)
#pragma arm section code = "INTERNCODE"
#endif 


/*****************************************************************************
 * FUNCTION
 *  gd_color_from_rgb_16
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
gdi_color gd_color_from_rgb_16(U32 A, U32 R, U32 G, U32 B)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gdi_color) ((((B) & 0xf8) >> 3) | (((G) & 0xfc) << 3) | (((R) & 0xf8) << 8));
}


/*****************************************************************************
 * FUNCTION
 *  gd_color_to_rgb_16
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
void gd_color_to_rgb_16(U32 *A, U32 *R, U32 *G, U32 *B, gdi_color c)
{
    int t;
    *A = 0xFF;

    t = ((U32) (((c) & 0xf800) >> 8));
    *R = t | (t>>5);
    
    t = ((U32) (((c) & 0x07e0) >> 3));
    *G = t | (t>>6);

    t = ((U32) (((c) & 0x001f) << 3));
    *B = t | (t>>5);
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_pixel_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gd_get_pixel_16(int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return *(U16*) (gdi_act_layer->buf_ptr + ((y * gdi_act_layer->width + x) << 1));
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_pixel_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_put_pixel_16(int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(U16*) (gdi_act_layer->buf_ptr + ((y * gdi_act_layer->width + x) << 1)) = (U16) c;
}


/*****************************************************************************
 * FUNCTION
 *  gd_get_buf_pixel_16
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
gdi_color gd_get_buf_pixel_16(U8 *buf_ptr, U32 buf_width, int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return *(U16*) (buf_ptr + ((y * buf_width + x) << 1));
}


/*****************************************************************************
 * FUNCTION
 *  gd_put_buf_pixel_16
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
void gd_put_buf_pixel_16(U8 *buf_ptr, U32 buf_width, int x, int y, gdi_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(U16*) (buf_ptr + ((y * buf_width + x) << 1)) = (U16) c;
}


/*****************************************************************************
 * FUNCTION
 *  gd_replace_src_key_16
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
void gd_replace_src_key_16(
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
    GDI_ENTER_CRITICAL_SECTION(gd_replace_src_key_16)
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
            jump_size = (((y_jump + dest_offset_y) * dest_pitch + clipx1) * 16) >> 3;
            dest_line_start_ptr = dest_ptr + jump_size;
        }
        else
        {
            jump_size = (((y_jump + dest_offset_y) * dest_pitch + dest_offset_x) * 16) >> 3;
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
            U16 *dest;
            S32 x, y;

            for (y = 0; y < y_draw_count; y++)
            {
                dest = (U16*) (dest_line_start_ptr + ((dest_pitch * y * 16) >> 3));

                for (x = 0; x < x_draw_count; x++)
                {
                    U16 c = *dest;

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

#define PIXEL_TYPE                  U16
#define PIXEL_BYTES                 2
#define GET_PIXEL(C,PTR)            C=*((PIXEL_TYPE*)(PTR))
#define PUT_PIXEL(C,PTR)            *(PIXEL_TYPE*)(PTR) = (PIXEL_TYPE) C
#define JUMP_PIXEL(PTR,N)           PTR = (((U8*)PTR)+((N)* PIXEL_BYTES))

#define GD_RESIZE_BITBLT            gd_resize_bitblt_16
#define GD_BITBLT                   gd_bitblt_16
#define GD_MEMSET                   gd_memset_16
#define GD_FILL_DOT_RECTANGLE       gd_fill_dot_rect_16
#define GD_IMAGE_BITS_DRAW          gd_image_bits_draw_16
#include "gd_primitive_internal.h"

#if defined(__MTK_TARGET__)
#pragma arm section code
#endif 
/*****************************************************************************
 * FUNCTION
 *  gd_gray_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  address          [IN]        
 *  size             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gd_gray_16(U8* address,int size)
{
    GDI_ASSERT(!(size&0xf)&&(size > 0));
    #if defined(__MTK_TARGET__)
    GDI_GRAY16SET((int)address+size,(int)address);
    #else
    do
    {
        U32 color_of_two_pixels = ((U32*)address)[0]; //BBBBBGGGGGGRRRRRBBBBBGGGGGGRRRRR
        U32 r, g, b;

        b = (color_of_two_pixels & 0xF000F000) >> 11; // B : 00000000000BBBB0|00000000000BBBB0
        g = (color_of_two_pixels & 0x07800780) >> 5;  //2G : 0000000000GGGG00|0000000000GGGG00
        r = color_of_two_pixels & 0x001E001E;         // R : 00000000000RRRR0|00000000000RRRR0
        

        r = (r + g + b) >> 2; //(R+2G+B)/4
        r = r & 0x1F001F;     // To clear unneeded bits
        
        ((U32*)address)[0] = (r << 11) | (r << 6) | (r); //RRRRRRRRRR0RRRRR|RRRRRRRRRR0RRRRR
        
        (int)address += 4;
        
    }while ((int)address < (int)address+size);
    #endif
}

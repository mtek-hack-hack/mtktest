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
 *  gdi_font_show_char.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI low-level font library
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  __GDI_SHOW_CHAR__
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  color               [IN]        
 *  font_data           [?]         
 *  font_data_size      [IN]        
 *  char_width          [IN]        
 *  char_height         [IN]        
 *  font_attr           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void __GDI_SHOW_CHAR__(
                S32 x,
                S32 y,
                gdi_color color,
                U8 *font_data,
                U32 font_data_size,
                U16 char_width,
                U16 char_height,
                U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 X1, Y1;
    S32 X2 = 0, Y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    X1 = x;
    Y1 = y;
    X2 = 0;

    /* draw underline */
    if (font_attr & FONTATTRIB_UNDERLINE)
    {
        S32 underline_y;

        underline_y = y + char_height;
        if (underline_y < GDI_LAYER.clipy2)
        {
            S32 i, endi;

            i = x;
            endi = x + char_width;

            if (font_attr & FONTATTRIB_ITALIC) endi +=(S32) gdi_tilt_table[char_height];
            else if (font_attr & FONTATTRIB_OBLIQUE) endi +=(S32) gdi_tilt_table[char_height]/2;
    
            if (endi > GDI_LAYER.clipx2)
            {
                endi = GDI_LAYER.clipx2;
            }
            if (i < GDI_LAYER.clipx1)
            {
                i = GDI_LAYER.clipx1;
            }

            for (; i <= endi; i++)
            {
                __GDI_SET_PIXEL__(i, underline_y, color);
            }
        }
    }

    while (font_data_size--)
    {
        U8 pattern = *font_data++;

        if (!pattern)
        {
            U32 nTemp;

            X2 += 8;
            nTemp = X2 / char_width;
            if (nTemp)
            {
                Y1 += nTemp;
                char_height -= (U16) nTemp;
                if (!char_height)
                {
                    return;
                }
            }
            X2 %= char_width;
            X1 = x + X2;
        }
        else
        {
#define FONT_DRAW_PATTERN(SET_PIXEL,XFUNC,YFUNC)                              \
            {                                                                          \
               for(Y2 = 0; Y2 < 8; Y2++)                                               \
               {                                                                       \
                  if(pattern&1)                                                        \
                     SET_PIXEL(XFUNC, YFUNC, color);                                   \
                  ++X2;                                                                \
                  if(X2 == (S32)( char_width ) )                                       \
                  {                                                                    \
                     X1=x;                                                             \
                     char_height--;                                                    \
                     ++Y1;                                                             \
                                                                                       \
                     if(char_height == 0)                                              \
                        return ;                                                       \
                     X2=0;                                                             \
                  }                                                                    \
                  else                                                                 \
                  {                                                                    \
                     ++X1;                                                             \
                  }                                                                    \
                  pattern >>=1;                                                        \
               }                                                                       \
            }

            if ((font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE)) == 0)    /* normal font */
                FONT_DRAW_PATTERN(__GDI_SET_PIXEL__, X1, Y1)
                else
            if (font_attr & FONTATTRIB_ITALIC)
                FONT_DRAW_PATTERN(__GDI_SET_PIXEL__, X1 + (S32) gdi_tilt_table[char_height], Y1)
                else    /* if(font_attr&FONTATTRIB_OBLIQUE) */
                FONT_DRAW_PATTERN(__GDI_SET_PIXEL__, X1 + (S32) gdi_tilt_table[char_height] / 2, Y1)}
                }
                }


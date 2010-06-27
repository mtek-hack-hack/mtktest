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
 * mtkgif.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the optimized version GIF decoder
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#if !defined(__BW_MMI__) && !defined(WIN32)     /* Target version shall use this library */

#pragma Otime
#pragma no_check_printf_formats
#pragma no_check_scanf_formats
#pragma no_check_stack


#ifdef MMI_ON_HARDWARE_P
#include "gui.h"
#include "lcd_sw_inc.h"
#include "lcd_sw.h"
#include "lcd_sw_rnd.h"
//#else
//#include "global.h"
#endif /* MMI_ON_HARDWARE_P */ 

#include "gui_bytestream.h"

#define  IMAGE_STATIC_ROW_DATA_SIZE          1024
#define GIF_MAX_CODES   4095
#define MAX_GIF_FRAME_SUM 32

static U16 palette[256];

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif 
static U16 transparent_index;
U16 GIF_delay_time;

#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif 

#define GIF_mtk_stack GIF_stack
#define GIF_mtk_suffix GIF_suffix
#define GIF_mtk_prefix GIF_prefix

extern S16 GIF_mtk_stack[1026];
extern S16 GIF_mtk_suffix[GIF_MAX_CODES + 1];
extern S16 GIF_mtk_prefix[GIF_MAX_CODES + 1];

////////////////////////////////////////////////////////////////////////
//To support decoding the n frame without decoding from 0 to n frame.
static U8 *gif_cache[MAX_GIF_FRAME_SUM];

#define FETCH_WORD(X)                                   \
   {                                                    \
      X = ((U16)(GIF_src[1] << 8 ))| (U16)(GIF_src[0]); \
      GIF_src+=2;                                       \
   }

#define GIF_interlace_pass(y,pass,ysize) \
   {                                     \
      if(pass<2) y+=8;                   \
      else if(pass==2) y+=4;             \
      else y+=2;                         \
      if(y>=ysize)                       \
      {                                  \
         y=GIF_oy+(4>>pass);             \
         pass++;                         \
      }                                  \
   }                                     \

#define GIF_INITIALIZE_DECODER(size)                     \
{   GIF_current_code_size=(S16)(size+1);                 \
   GIF_top_slot=(S16)(1<<GIF_current_code_size);         \
    GIF_clear_code=(S16)(1<<size);                       \
    GIF_end_code=(S16)(GIF_clear_code+1);                \
    GIF_slot=(GIF_new_codes)=(S16)(GIF_end_code+1);      \
   bitstream_available_bits=0;                           \
   bytestream_available=0;                               \
   bitstream=0;                                          \
}                                                        \

#define GIF_GET_NEXT_CODE(ret)                                                \
{                                                                             \
   while(GIF_current_code_size> bitstream_available_bits)                     \
   {                                                                          \
      if(bytestream_available==0) bytestream_available=*GIF_src++;            \
      bitstream |= *GIF_src<<bitstream_available_bits;                        \
      bitstream_available_bits +=8;                                           \
      GIF_src++;                                                              \
      bytestream_available--;                                                 \
   }                                                                          \
   bitstream_available_bits -= GIF_current_code_size;                         \
   ret =  bitstream & ((1<<GIF_current_code_size)-1);                         \
   bitstream >>= GIF_current_code_size;                                       \
}                                                                             \

#define GIF_PUT_PIXEL(c)                                                   \
   {                                                                       \
      U16 color = c;                                                       \
      if(y<=UI_clip_y2)                                                    \
      {                                                                    \
         if(begin_jump<=0)                                                 \
         {                                                                 \
            if(color!=transparent_index)                                   \
               SHADOW_BUF_PIXEL_DATA(y,x)=palette[color];                  \
            visible_width--;                                               \
            if(visible_width<=0)                                           \
            {                                                              \
               visible_width = width - next_jump;                          \
               begin_jump = next_jump;                                     \
            }                                                              \
         }                                                                 \
         else                                                              \
         {                                                                 \
            begin_jump--;                                                  \
         }                                                                 \
      }                                                                    \
      x++;                                                                 \
      if(x>=xsize)                                                         \
      {                                                                    \
         x=GIF_ox;                                                         \
         y++;                                                              \
      }                                                                    \
   }                                                                       \

#define GIF_PUT_PIXEL_INTERLACE(c)                                         \
   {                                                                       \
      U16 color = c;                                                       \
      if(y<=UI_clip_y2 && y>= UI_clip_y1)                                  \
         {                                                                 \
         if(begin_jump<=0)                                                 \
         {                                                                 \
            if(color!=transparent_index)                                   \
               SHADOW_BUF_PIXEL_DATA(y,x)=palette[color];                  \
            visible_width--;                                               \
            if(visible_width<=0)                                           \
            {                                                              \
               visible_width = width - next_jump;                          \
               begin_jump = next_jump;                                     \
            }                                                              \
         }                                                                 \
         else                                                              \
         {                                                                 \
            begin_jump--;                                                  \
         }                                                                 \
      }                                                                    \
      x++;                                                                 \
      if(x>=xsize)                                                         \
      {                                                                    \
         x=GIF_ox;                                                         \
            GIF_interlace_pass(y,pass,ysize);                              \
         }                                                                 \
      }                                                                    \

/* Start of internal RAM */
#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE"
#endif 


/*****************************************************************************
 * FUNCTION
 *  GIF_image_decoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  GIF_src                 [?]         
 *  GIF_src_end             [?]         
 *  GIF_ox                  [IN]        
 *  GIF_oy                  [IN]        
 *  transparent_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *GIF_image_decoder(U8 *GIF_src, U8 *GIF_src_end, int GIF_ox, int GIF_oy, U16 transparent_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 code, fc, oc, c, size;
    S16 *stack_pointer;
    S16 GIF_current_code_size, GIF_clear_code, GIF_end_code, GIF_new_codes, GIF_top_slot, GIF_slot;
    int bitstream_available_bits;
    int bytestream_available;
    unsigned int bitstream;
    int x, y, xsize, ysize;

    int width;
    int begin_jump;
    int visible_width;
    int next_jump;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FETCH_WORD(x);
    FETCH_WORD(y);
    FETCH_WORD(xsize);
    FETCH_WORD(ysize);

    {
        int n;

        n = *GIF_src++;
        if (GIF_src >= GIF_src_end)
        {
            return GIF_src;
        }

        if (n & 0x80)
        {
            int i;

            n = 1 << ((n & 0x7) + 1);
            /* Read the local color palette  */
            for (i = 0; i < n; i++)
            {
                U8 R = *GIF_src++;
                U8 G = *GIF_src++;
                U8 B = *GIF_src++;

                palette[i] = MMI_RGB_TO_HW_FORMAT(R, G, B);
            }
        }
    }

    size = *GIF_src++;

    GIF_INITIALIZE_DECODER(size);
    oc = fc = 0;
    stack_pointer = GIF_mtk_stack;
    width = xsize;

    /* calculate coordinate */
    GIF_ox += x;
    GIF_oy += y;

    xsize += GIF_ox;
    x = GIF_ox;

    ysize += GIF_oy;
    y = GIF_oy;

    if (xsize < UI_clip_x1)
    {
        return GIF_src_end;
    }
    if (ysize < UI_clip_y1)
    {
        return GIF_src_end;
    }
    if (x > UI_clip_x2)
    {
        return GIF_src_end;
    }
    if (y > UI_clip_y2)
    {
        return GIF_src_end;
    }

    begin_jump = 0;
    visible_width = width;

    if (x < UI_clip_x1)
    {
        begin_jump = UI_clip_x1 - x;
        visible_width -= (UI_clip_x1 - x);
    }

    if (y < UI_clip_y1)
    {
        begin_jump += (UI_clip_y1 - y) * width;
    }

    if (UI_clip_x2 + 1 < xsize)
    {
        visible_width -= (xsize - UI_clip_x2 - 1);
    }

    next_jump = width - visible_width;

    /* begin decoding */
    while (1)
    {
        GIF_GET_NEXT_CODE(c);
        if (c == GIF_end_code)
        {
            break;
        }
        if (GIF_src >= GIF_src_end)
        {
            return GIF_src;
        }

        if (c == GIF_clear_code)
        {
            GIF_current_code_size = (S16) (size + 1);
            GIF_slot = GIF_new_codes;
            GIF_top_slot = (S16) (1 << GIF_current_code_size);

            GIF_GET_NEXT_CODE(c);
            if (c == GIF_end_code)
            {
                break;
            }
            if (GIF_src >= GIF_src_end)
            {
                return GIF_src;
            }

            if (c >= GIF_slot)
            {
                c = 0;
            }
            oc = fc = c;

            GIF_PUT_PIXEL(c);
        }
        else
        {
            code = c;
            if (code >= GIF_slot)
            {
                code = oc;
                *stack_pointer++ = fc;
            }
            while (code >= GIF_new_codes)
            {
                *stack_pointer++ = GIF_mtk_suffix[code];
                code = GIF_mtk_prefix[code];
            }
            *stack_pointer++ = code;
            if (GIF_slot < GIF_top_slot)
            {
                GIF_mtk_suffix[GIF_slot] = fc = code;
                GIF_mtk_prefix[GIF_slot++] = oc;
                oc = c;
            }
            if (GIF_slot >= GIF_top_slot)
            {
                if (GIF_current_code_size < 12)
                {
                    GIF_top_slot <<= 1;
                    GIF_current_code_size++;
                }
            }
            while (stack_pointer > GIF_mtk_stack)
            {
                GIF_PUT_PIXEL(*(--stack_pointer));
            }
        }
    }
    return GIF_src;
}


/*****************************************************************************
 * FUNCTION
 *  GIF_image_interlace_decoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  GIF_src                 [?]         
 *  GIF_src_end             [?]         
 *  GIF_ox                  [IN]        
 *  GIF_oy                  [IN]        
 *  transparent_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *GIF_image_interlace_decoder(U8 *GIF_src, U8 *GIF_src_end, int GIF_ox, int GIF_oy, U16 transparent_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 code, fc, oc, c, size, pass = 0;
    S16 *stack_pointer;
    S16 GIF_current_code_size, GIF_clear_code, GIF_end_code, GIF_new_codes, GIF_top_slot, GIF_slot;
    int bitstream_available_bits;
    int bytestream_available;
    unsigned int bitstream;
    int x, y, xsize, ysize;

    int width;
    int begin_jump;
    int visible_width;
    int next_jump;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FETCH_WORD(x);
    FETCH_WORD(y);
    FETCH_WORD(xsize);
    FETCH_WORD(ysize);

    {
        int n;

        n = *GIF_src++;
        if (GIF_src >= GIF_src_end)
        {
            return GIF_src;
        }

        if (n & 0x80)
        {
            int i;

            n = 1 << ((n & 0x7) + 1);
            /* Read the local color palette  */
            for (i = 0; i < n; i++)
            {
                U8 R = *GIF_src++;
                U8 G = *GIF_src++;
                U8 B = *GIF_src++;

                palette[i] = MMI_RGB_TO_HW_FORMAT(R, G, B);
            }
        }
    }

    size = *GIF_src++;

    GIF_INITIALIZE_DECODER(size);
    oc = fc = 0;
    stack_pointer = GIF_mtk_stack;
    width = xsize;

    /* calculate coordinate */
    GIF_ox += x;
    GIF_oy += y;

    xsize += GIF_ox;
    x = GIF_ox;

    ysize += GIF_oy;
    y = GIF_oy;

    if (xsize < UI_clip_x1)
    {
        return GIF_src_end;
    }
    if (ysize < UI_clip_y1)
    {
        return GIF_src_end;
    }
    if (x > UI_clip_x2)
    {
        return GIF_src_end;
    }
    if (y > UI_clip_y2)
    {
        return GIF_src_end;
    }

    begin_jump = 0;
    visible_width = width;

    if (x < UI_clip_x1)
    {
        begin_jump = UI_clip_x1 - x;
        visible_width -= (UI_clip_x1 - x);
    }

    if (UI_clip_x2 + 1 < xsize)
    {
        visible_width -= (xsize - UI_clip_x2 - 1);
    }

    next_jump = width - visible_width;

    /* begin decoding */
    while (1)
    {
        GIF_GET_NEXT_CODE(c);
        if (c == GIF_end_code)
        {
            break;
        }
        if (GIF_src >= GIF_src_end)
        {
            return GIF_src;
        }

        if (c == GIF_clear_code)
        {
            GIF_current_code_size = (S16) (size + 1);
            GIF_slot = GIF_new_codes;
            GIF_top_slot = (S16) (1 << GIF_current_code_size);

            GIF_GET_NEXT_CODE(c);
            if (c == GIF_end_code)
            {
                break;
            }
            if (GIF_src >= GIF_src_end)
            {
                return GIF_src;
            }

            if (c >= GIF_slot)
            {
                c = 0;
            }
            oc = fc = c;

            GIF_PUT_PIXEL_INTERLACE(c);
        }
        else
        {
            code = c;
            if (code >= GIF_slot)
            {
                code = oc;
                *stack_pointer++ = fc;
            }
            while (code >= GIF_new_codes)
            {
                *stack_pointer++ = GIF_mtk_suffix[code];
                code = GIF_mtk_prefix[code];
            }
            *stack_pointer++ = code;
            if (GIF_slot < GIF_top_slot)
            {
                GIF_mtk_suffix[GIF_slot] = fc = code;
                GIF_mtk_prefix[GIF_slot++] = oc;
                oc = c;
            }
            if (GIF_slot >= GIF_top_slot)
            {
                if (GIF_current_code_size < 12)
                {
                    GIF_top_slot <<= 1;
                    GIF_current_code_size++;
                }
            }
            while (stack_pointer > GIF_mtk_stack)
            {
                GIF_PUT_PIXEL_INTERLACE(*(--stack_pointer));
            }
        }
    }
    return GIF_src;
}

/* MTK added, Max: to clear gif_cache 0202, modified by JF */


/*****************************************************************************
 * FUNCTION
 *  GIF_clear_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GIF_clear_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gif_cache[0] = 0;
}

/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  GIF_display
 * DESCRIPTION
 *  Displays a given frame of the GIF file
 * PARAMETERS
 *  ox                  [IN]        Position at which the GIF image is to be displayed
 *  oy                  [IN]        Position at which the GIF image is to be displayed
 *  file                [IN]        The GIF file in bytestream format
 *  color_depth         [IN]        Output color depth.
 *  frame_number        [IN]        Frame number to load for animated GIF.
 * RETURNS
 *  0  if GIF_load failed (invalid GIF image)
 *  1  if GIF_load is successful
 *****************************************************************************/
U8 GIF_display(S16 ox, S16 oy, bytestream *file, S8 color_depth, S32 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 gif_done;
    S16 frame_counter = 0;
    U8 *GIF_src;
    U8 *GIF_src_end;

    /* word transparent_index=256; // assign an invalid color index value */
    int i, n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file == NULL)
    {
        return (0);
    }
    ///////////////////////////////////////////////////////////
    // initialize global variable
    GIF_src = file->data;
    GIF_src_end = GIF_src + file->size;

    ///////////////////////////////////////////////////////////
    // try to hit the cache data
    if (gif_cache[0] == GIF_src)
    {
        i = (frame_number >= MAX_GIF_FRAME_SUM) ? MAX_GIF_FRAME_SUM - 1 : frame_number;
        for (; i >= 0; i--)
            if (gif_cache[i])
            {
                frame_counter = i;
                break;
            }
        GIF_src = gif_cache[i];
    }
    else
    {
        memset(gif_cache, 0, sizeof(U8*) * MAX_GIF_FRAME_SUM);
        gif_cache[0] = GIF_src;
        transparent_index = 256;    /* assign an invalid color index value */
        frame_counter = 0;
    }
    /* ///////////////////////////////////////////////////////// */
    /*   read the GIF file signature   */
    if (frame_counter == 0)
    {
        if (*GIF_src++ != 'G' || *GIF_src++ != 'I' || *GIF_src != 'F')
        {
            return 0;
        }

        /* ///////////////////////////////////////////////////////// */
        /* Read the global color palette */
        n = GIF_src[8];
        GIF_src += 11;

        if (n & 0x80)
        {
            int i;

            n = 1 << ((n & 0x7) + 1);

            /* Read the global color palette */
            for (i = 0; i < n; i++)
            {
                U8 R = *GIF_src++;
                U8 G = *GIF_src++;
                U8 B = *GIF_src++;

                palette[i] = MMI_RGB_TO_HW_FORMAT(R, G, B);
            }
        }
    }
    ///////////////////////////////////////////////////////////
    // start decoding
    //MTK added, JF 0822
    if (GIF_src >= GIF_src_end)
    {
        return 0;
    }
    /* MTK end */

    gif_done = 0;
    do
    {
        switch (*GIF_src++)
        {
            case '!':   /* Process the GIF extension block */
                if (*GIF_src++ == 0xf9)
                {
                    if (GIF_src[1] & 0x01)
                    {
                        transparent_index = GIF_src[4];
                    }
                    GIF_delay_time = ((U16) (GIF_src[3] << 8)) | (U16) (GIF_src[2]);
                    GIF_delay_time = GIF_delay_time * 10;
                    GIF_src += 6;
                }
                else
                {
                    int offset;

                    while (1)
                    {
                        offset = *GIF_src++;
                        if (offset == 0)
                        {
                            break;
                        }
                        GIF_src += offset;
                    }
                }
                break;
            case ',':
                /* xx = frame_counter; */
                if (GIF_src[8] & 0x40)  /* is interlace */
                {
                    GIF_src = GIF_image_interlace_decoder(GIF_src, GIF_src_end, ox, oy, transparent_index);
                }
                else
                {
                    GIF_src = GIF_image_decoder(GIF_src, GIF_src_end, ox, oy, transparent_index);
                }
                if (frame_counter >= frame_number)
                {
                    gif_done = 1;
                }
                frame_counter++;
                if (frame_counter < MAX_GIF_FRAME_SUM)
                {
                    gif_cache[frame_counter] = GIF_src;
                }
                break;
            case '\0':

                if (GIF_src >= GIF_src_end)
                {
                    return 2;   /* gif_done=1; */
                }
                break;
            case ';':
                return 2;
                //gif_done=1;
                //break;
        }
    } while (!gif_done && GIF_src < GIF_src_end);

    return (1);
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif 

#endif /* !defined(__BW_MMI__) && !defined(WIN32) */ 


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
 *  GIFLoader.c
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
 *  
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ResDevice.h"
#include "ResBytestream.h"
#include "ImgDecoderDef.h"

extern U32 image_static_row_data[];
extern U32 image_static_palette[];
extern U32 image_static_buffer[];

/* GIF code from WINGUI.C  */


/*****************************************************************************
 * FUNCTION
 *  GIF_get_byte
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 GIF_get_byte(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (bytestream_fgetbyte(file));
}

#if(!WINGUI_DIRECT_IMAGE_DISPLAY)


/*****************************************************************************
 * FUNCTION
 *  GIF_write_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ix                          [IN]        
 *  iy                          [IN]        
 *  b                           [?]         
 *  buffer                      [?]         
 *  length                      [IN]        
 *  y                           [IN]        
 *  palette                     [?]         
 *  transparent_GIF             [IN]        
 *  transparent_color_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void GIF_write_line(
        S32 ix,
        S32 iy,
        bitmap *b,
        U8 *buffer,
        S16 length,
        S16 y,
        U8 palette[][3],
        U8 transparent_GIF,
        U8 transparent_color_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b == NULL)
    {
        return;
    }
    if (transparent_GIF)
    {
        {
            S32 i;
            U8 color_index;
            U32 offset = (y + iy) * b->xsize + ix;
            U16 *bitmap_data = (U16*) b->data;
            U16 d;

            for (i = 0; i < length; i++)
            {
                color_index = (U8) buffer[i];
                d = MMI_RGB_TO_HW_FORMAT(palette[color_index][0], palette[color_index][1], palette[color_index][2]);
                if (color_index == transparent_color_index)
                {
                    SET_RGB_TRANSPARENT_COLOR_16(d);
                }
                bitmap_data[offset++] = d;
            }
        }
    }
    else
    {
        {
            S32 i;
            U8 color_index;
            U32 offset = (y + iy) * b->xsize + ix;
            U16 *bitmap_data = (U16*) b->data;
            U16 d;

            for (i = 0; i < length; i++)
            {
                color_index = (U8) buffer[i];
                d = MMI_RGB_TO_HW_FORMAT(palette[color_index][0], palette[color_index][1], palette[color_index][2]);
                bitmap_data[offset++] = d;
            }
        }
    }
}

#endif /* (!WINGUI_DIRECT_IMAGE_DISPLAY) */ 

#define GIF_MAX_CODES   4095

S16 GIF_current_code_size, GIF_clear_code, GIF_end_code, GIF_new_codes, GIF_top_slot, GIF_slot;
S16 GIF_navailable_bytes, GIF_nbits_left, GIF_b1;
U8 GIF_byte_buffer[257], *GIF_pbytes;

U16 GIF_code_mask[13] = {0x0000,
    0x0001, 0x0003,
    0x0007, 0x000f,
    0x001f, 0x003f,
    0x007f, 0x00ff,
    0x01ff, 0x03ff,
    0x07ff, 0x0fff
};


/*****************************************************************************
 * FUNCTION
 *  GIF_initialize_decoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void GIF_initialize_decoder(S16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GIF_current_code_size = (S16) (size + 1);
    GIF_top_slot = (S16) (1 << GIF_current_code_size);
    GIF_clear_code = (S16) (1 << size);
    GIF_end_code = (S16) (GIF_clear_code + 1);
    GIF_slot = (GIF_new_codes) = (S16) (GIF_end_code + 1);
    GIF_navailable_bytes = GIF_nbits_left = (S16) 0;
}


/*****************************************************************************
 * FUNCTION
 *  GIF_get_next_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S16 GIF_get_next_code(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, x, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GIF_nbits_left == 0)
    {
        if (GIF_navailable_bytes <= 0)
        {
            GIF_pbytes = GIF_byte_buffer;
            GIF_navailable_bytes = GIF_get_byte(file);
            if (GIF_navailable_bytes < 0)
            {
                return (GIF_navailable_bytes);
            }
            else if (GIF_navailable_bytes > 0)
            {
                for (i = 0; i < GIF_navailable_bytes; i++)
                {
                    x = GIF_get_byte(file);
                    if (x < 0)
                    {
                        return (x);
                    }
                    GIF_byte_buffer[i] = (U8) x;
                }
            }
        }
        GIF_b1 = *GIF_pbytes++;
        GIF_nbits_left = 8;
        GIF_navailable_bytes--;
    }
    ret = (S16) (GIF_b1 >> (8 - GIF_nbits_left));
    while (GIF_current_code_size > GIF_nbits_left)
    {
        if (GIF_navailable_bytes <= 0)
        {
            GIF_pbytes = GIF_byte_buffer;
            GIF_navailable_bytes = GIF_get_byte(file);
            if (GIF_navailable_bytes < 0)
            {
                return (GIF_navailable_bytes);
            }
            else if (GIF_navailable_bytes > 0)
            {
                for (i = 0; i < GIF_navailable_bytes; i++)
                {
                    x = GIF_get_byte(file);
                    if (x < 0)
                    {
                        return (x);
                    }
                    GIF_byte_buffer[i] = (U8) x;
                }
            }
        }
        GIF_b1 = *GIF_pbytes++;
        ret |= GIF_b1 << GIF_nbits_left;
        GIF_nbits_left += 8;
        GIF_navailable_bytes--;
    }
    GIF_nbits_left = (S16) (GIF_nbits_left - GIF_current_code_size);
    ret &= GIF_code_mask[GIF_current_code_size];
    return (ret);
}

S16 GIF_stack[GIF_MAX_CODES + 1];
S16 GIF_suffix[GIF_MAX_CODES + 1];
S16 GIF_prefix[GIF_MAX_CODES + 1];


/*****************************************************************************
 * FUNCTION
 *  GIF_interlace_pass
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y           [?]         
 *  pass        [?]         
 *  ysize       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void GIF_interlace_pass(S16 *y, S16 *pass, S16 ysize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (*pass)
    {
        case 0:
            (*y) += 8;
            if (*y >= ysize)
            {
                *y = 4;
                (*pass)++;
            }
            break;
        case 1:
            (*y) += 8;
            if (*y >= ysize)
            {
                *y = 2;
                (*pass)++;
            }
            break;
        case 2:
            (*y) += 4;
            if (*y >= ysize)
            {
                *y = 1;
                (*pass)++;
            }
            break;
        case 3:
            (*y) += 2;
            break;
    }
}

// #if(!WINGUI_DIRECT_IMAGE_DISPLAY)


/*****************************************************************************
 * FUNCTION
 *  GIF_decoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ix                          [IN]        
 *  iy                          [IN]        
 *  file                        [?]         
 *  b                           [?]         
 *  xsize                       [IN]        
 *  ysize                       [IN]        
 *  interlaced                  [IN]        
 *  palette                     [?]         
 *  transparent_GIF             [IN]        
 *  transparent_color_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void GIF_decoder(
        S32 ix,
        S32 iy,
        bytestream *file,
        bitmap *b,
        S16 xsize,
        S16 ysize,
        U8 interlaced,
        U8 palette[][3],
        U8 transparent_GIF,
        U8 transparent_color_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 *stack_pointer;
    U8 *buffer_pointer;
    U8 *buffer;
    S16 code, fc, oc, buffer_count, c, size, y = 0, pass = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = GIF_get_byte(file);
    if (size < 0)
    {
        return;
    }
    GIF_initialize_decoder(size);
    oc = fc = 0;
    buffer = (U8*) image_static_row_data;
    stack_pointer = GIF_stack;
    buffer_pointer = buffer;
    buffer_count = xsize;
    while ((c = GIF_get_next_code(file)) != GIF_end_code)
    {
        if (c < 0)
        {
            return;
        }
        if (c == GIF_clear_code)
        {
            GIF_current_code_size = (S16) (size + 1);
            GIF_slot = GIF_new_codes;
            GIF_top_slot = (S16) (1 << GIF_current_code_size);
            while ((c = GIF_get_next_code(file)) == GIF_clear_code);
            if (c == GIF_end_code)
            {
                break;
            }
            if (c >= GIF_slot)
            {
                c = 0;
            }
            oc = fc = c;
            *buffer_pointer++ = (U8) c;
            if (--buffer_count == 0)
            {
                GIF_write_line(ix, iy, b, buffer, xsize, y, palette, transparent_GIF, transparent_color_index);
                if (interlaced)
                {
                    GIF_interlace_pass(&y, &pass, ysize);
                }
                else
                {
                    y++;
                }
                buffer_pointer = buffer;
                buffer_count = xsize;
            }
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
                *stack_pointer++ = GIF_suffix[code];
                code = GIF_prefix[code];
            }
            *stack_pointer++ = code;
            if (GIF_slot < GIF_top_slot)
            {
                GIF_suffix[GIF_slot] = fc = code;
                GIF_prefix[GIF_slot++] = oc;
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
            while (stack_pointer > GIF_stack)
            {
                *buffer_pointer++ = (U8) * (--stack_pointer);
                if (--buffer_count == 0)
                {
                    GIF_write_line(ix, iy, b, buffer, xsize, y, palette, transparent_GIF, transparent_color_index);
                    if (interlaced)
                    {
                        GIF_interlace_pass(&y, &pass, ysize);
                    }
                    else
                    {
                        y++;
                    }
                    buffer_pointer = buffer;
                    buffer_count = xsize;
                }
            }
        }
    }
    if (buffer_count != xsize)
    {
        GIF_write_line(ix, iy, b, buffer, xsize, y, palette, transparent_GIF, transparent_color_index);
    }
    if (interlaced)
    {
        GIF_interlace_pass(&y, &pass, ysize);
    }
    else
    {
        y++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Load_GIF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file                [?]     
 *  total_frames        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 Load_GIF(bytestream *file, S32 *total_frames)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 gif_signature[4];
    S8 descriptor_flags;
    S16 bits_per_pixel;
    S16 i, j, ncolors;
    S16 x, y, xsize, ysize;
    S8 interlace = 0;
    S8 gif_done;
    S16 screen_xsize, screen_ysize;
    U8 transparent_color_index = 0;
    U8 transparent_GIF = 0;
    U8 palette[256][3];
    S16 frame_counter = 0;
    S16 dest_row_bytes = 0;
    S32 bitmap_size;
    S32 first_frame_xsize = -1, first_frame_ysize = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file == NULL)
    {
        return (0);
    }
    /*   read the GIF file signature   */
    bytestream_fseek(file, 0, SEEK_SET);
    bytestream_fread((U8*) gif_signature, 1, 3, file);
    gif_signature[3] = '\0';
    if (strcmp((const char*)gif_signature, (const char*)"GIF"))
    {
        return (0);
    }
    bytestream_fseek(file, 3, SEEK_CUR);
    screen_xsize = bytestream_fgetword(file);
    screen_ysize = bytestream_fgetword(file);
    printf("Screen Width=%d, Screen Height=%d\n", screen_xsize, screen_ysize);
    descriptor_flags = bytestream_fgetbyte(file);
    bytestream_fseek(file, 2, SEEK_CUR);
    if (descriptor_flags & 0x80)
    {
        bits_per_pixel = (S16) ((descriptor_flags & 0x07) + 1);
        ncolors = (S16) (1 << bits_per_pixel);
        /*  Read the global color palette */
        for (i = 0; i < ncolors; i++)
        {
            for (j = 0; j < 3; j++)
            {
                palette[i][j] = bytestream_fgetbyte(file);
            }
        }
    }
    gif_done = 0;
    do
    {
        char block_type = bytestream_fgetbyte(file);

        switch (block_type)
        {
            case '!':   /* Process the GIF extension block  */
            {
                S32 block_size;
                S32 i;
                U8 label = bytestream_fgetbyte(file);
                U8 flags, color_index;

                if (label == 0xf9)
                {
                    bytestream_fgetbyte(file);
                    flags = bytestream_fgetbyte(file);
                    bytestream_fgetbyte(file);
                    bytestream_fgetbyte(file);
                    color_index = bytestream_fgetbyte(file);
                    if (flags & 0x01)
                    {
                        transparent_GIF = 1;
                        transparent_color_index = color_index;
                        printf("The image is has transparent color:");
                        printf(
                            "(%d,%d,%d)\n",
                            palette[color_index][0],
                            palette[color_index][1],
                            palette[color_index][2]);
                    }
                }
                else
                {
                    while ((block_size = bytestream_fgetbyte(file)) != 0)
                    {
                        for (i = 0; i < block_size; i++)
                        {
                            bytestream_fgetbyte(file);
                        }
                    }
                }
            }
                break;
            case ',':   /* Process the GIF image   */
            {
                x = bytestream_fgetword(file);
                y = bytestream_fgetword(file);
                xsize = bytestream_fgetword(file);
                ysize = bytestream_fgetword(file);
                descriptor_flags = bytestream_fgetbyte(file);
                if (descriptor_flags & 0x80)
                {
                    bits_per_pixel = (S16) ((descriptor_flags & 0x07) + 1);
                    ncolors = (S16) (1 << bits_per_pixel);
                    /* Read the local color palette  */
                    for (i = 0; i < ncolors; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            palette[i][j] = bytestream_fgetbyte(file);
                        }
                    }
                    printf("number of color:%d\n", ncolors);
                }
                if (descriptor_flags & 0x40)
                {
                    interlace = 1;
                }
                if (first_frame_xsize < 0)
                {
                    first_frame_xsize = xsize;
                    first_frame_ysize = ysize;
                    bitmap_size = dest_row_bytes * ysize;
                }
                //                                                      GIF_decoder(x,y,file,b,xsize,ysize,interlace,palette,transparent_GIF,transparent_color_index);
                //                                                      if((frame_counter>=frame_number) && (b!=NULL)) gif_done=1;
                frame_counter++;
            }
                break;
            case '\0':
                if (bytestream_feof(file))
                {
                    gif_done = 1;
                }
                break;
            case ';':
                gif_done = 1;
                break;
        }
    } while (!gif_done);
    *total_frames = frame_counter;
    printf("Number of frames:%d\n", frame_counter);
    return (1);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  GIFLoader
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_filename         [?]     
 *  out_filename        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int GIFLoader(char *in_filename, char *out_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bitmap outimage;
    FILE *infile;
    FILE *outfile;
    bytestream inimage;
    S32 file_length;
    U8 *buffer;
    S32 i, bitmap_size;
    S32 n_frames, frame_counter, temp_n_frames;
    S32 total_data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infile = fopen(in_filename, "rb");
    if (infile == NULL)
    {
        printf("\nError opening %s", in_filename);
        return 0;
    }

    fseek(infile, 0, SEEK_END);
    file_length = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    buffer = (U8*) malloc(file_length);
    if (buffer == NULL)
    {
        printf("\nError allocating memory of size %d bytes", file_length);
        fclose(infile);
        return 0;
    }

    fread(buffer, 1, file_length, infile);
    fclose(infile);
    bytestream_initialize(&inimage, buffer, file_length);
    /* Get the number of frames   */
    Load_GIF(&inimage, &n_frames);
    /* GIF_load(&inimage,NULL,DEVICE_COLOR_DEPTH,0,&n_frames); */
    frame_counter = 0;

    free(buffer);
    return 1;
}


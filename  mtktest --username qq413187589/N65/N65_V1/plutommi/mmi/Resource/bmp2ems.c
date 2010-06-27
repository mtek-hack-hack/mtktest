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
 *  bmp2ems.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "ResDevice.h"
#include "ResBytestream.h"
#include "ImgDecoderDef.h"
#include "mmi_features.h"

extern FILE *dest_file;
extern int toolFlag;

U8 binary_mode = 0;
U8 verbose_mode = 0;
FILE *out_file = NULL;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern FILE *enfb_img_data_file;
extern int enfbFlag;
extern U32 enfb_offset;
extern U32 enfb_size;
extern MMI_BOOL ENFBAssociatedIDAdded;

#include "ImageGetDimension.h"
#endif

extern S32 g_ressize;


/*****************************************************************************
 * FUNCTION
 *  EMS_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file            [?]     
 *  filename        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 EMS_load(bytestream *file, char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bitmap_file_header file_header;
    bitmap_info_header info_header;
    S32 i, j, k;
    S32 bits_per_pixel, width, height, PDU_length;
    U8 buffer[2048];
    U8 mask;
    U8 data;
    char cmdbuf[1024];
    FILE *file_ptr;
    S32 file_length;
    U8 *file_buffer;
    bytestream *rgb_image;
    U8 scale_data;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BMP_load_file_header(&file_header, file);
    if ((file_header.file_type & 0xff) != 'B')
    {
        printf("\nNot a valid BMP file");
        return (0);
    }
    if ((file_header.file_type >> 8) != 'M')
    {
        printf("\nNot a valid BMP file");
        return (0);
    }
    BMP_load_info_header(&info_header, file);
    width = info_header.width;
    height = info_header.height;
    if (info_header.bits_per_pixel == 1)
    {
        bits_per_pixel = 1;
        PDU_length = ((width * height) + 7) >> 3;

    }
    else if (info_header.bits_per_pixel == 4)
    {
        bits_per_pixel = 2;
        PDU_length = (((width * height) << 1) + 7) >> 3;
    }
    else if (info_header.bits_per_pixel == 8)
    {
        bits_per_pixel = 6;
        PDU_length = (((width * height) * 6) + 7) >> 3;
    }
    else
    {
        return (0);
    }

    g_ressize = PDU_length;

    bytestream_fseek(file, file_header.bitmap_offset, SEEK_SET);
    sprintf(cmdbuf, "%s %s %s", "..\\..\\Customer\\ResGenerator\\convert.exe", filename, "temp.rgb");
    system(cmdbuf);
    file_ptr = fopen("temp.rgb", "rb");
    fseek(file_ptr, 0, SEEK_END);
    file_length = ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);
    file_buffer = (U8*) malloc(file_length);
    fread(file_buffer, 1, file_length, file_ptr);
    fclose(file_ptr);
    bytestream_initialize(&rgb_image, file_buffer, file_length);
    free(file_buffer);

    if (binary_mode)
    {
        if (bits_per_pixel == 1)
        {
            for (i = 0; i < PDU_length; i++)
            {
                buffer[i] = 0x00;
                for (k = 8; k; k--)
                {
                    data =
                        (bytestream_fgetbyte(&rgb_image) + bytestream_fgetbyte(&rgb_image) +
                         bytestream_fgetbyte(&rgb_image)) / 3;
                    if (data >= 0 && data < 128)
                    {
                        scale_data = 0x01;
                    }
                    else
                    {
                        scale_data = 0x00;
                    }
                    buffer[i] |= scale_data << (k - 1);
                }
            }
        }
        else if (bits_per_pixel == 2)
        {
            for (i = 0; i < PDU_length; i++)
            {
                buffer[i] = 0x00;
                for (k = 8; k; k = k - 2)
                {
                    data =
                        (bytestream_fgetbyte(&rgb_image) + bytestream_fgetbyte(&rgb_image) +
                         bytestream_fgetbyte(&rgb_image)) / 3;
                    if (data >= 0 && data < 64)
                    {
                        scale_data = 0x00;
                    }
                    else if (data >= 64 && data < 128)
                    {
                        scale_data = 0x01;
                    }
                    else if (data >= 128 && data < 192)
                    {
                        scale_data = 0x02;
                    }
                    else
                    {
                        scale_data = 0x03;
                    }
                    buffer[i] |= scale_data << (k - 2);
                }
            }
        }
        else if (bits_per_pixel == 6)
        {
            for (i = 0; i < PDU_length; i++)
            {
                buffer[i] = 0x00;
                for (k = 8; k; k = k - 2)
                {
                    data = bytestream_fgetbyte(&rgb_image);
                    if (data >= 0 && data < 64)
                    {
                        scale_data = 0x00;
                    }
                    else if (data >= 64 && data < 128)
                    {
                        scale_data = 0x01;
                    }
                    else if (data >= 128 && data < 192)
                    {
                        scale_data = 0x02;
                    }
                    else
                    {
                        scale_data = 0x03;
                    }
                    buffer[i] |= scale_data << (k - 2);
                }
            }
        }
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        enfb_ret = Image_Test(filename, &enfb_width, &enfb_height);
        if (enfb_ret != ENFB_IMAGE_NONE)
        {
            enfbFlag = 1;
            if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
            {
                ENFBAssociatedIDAdded = MMI_TRUE;
            }
        }
    #endif
        if (toolFlag == 1)  /* Write to file in binary format */
        {
            fprintf(
                dest_file,
                "%c%c%c%c%c%c%c%c%c",
                (U8) 1,
                (U8) bits_per_pixel,
                (U8) 0,
                (U8) (width & 0xff),
                (U8) ((width >> 8) & 0xff),
                (U8) (height & 0xff),
                (U8) ((height >> 8) & 0xff),
                (U8) ((PDU_length) & 0xff),
                (U8) ((PDU_length) >> 8) & 0xff);
            for (i = 0; i < PDU_length; i++)
            {
                fprintf(dest_file, "%c", buffer[i]);
            }
        }
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        else if (enfbFlag == 1) /* write ENFB header to CustImgDataxxx.h and image header/data to ENFB image data file */
        {
            enfb_size = 9 + PDU_length;
            
            /* write ENFB header to CustImgDataxxx.h */
            fprintf(
                out_file,
                "\n{\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t};\n",
                (U8) 255,//type
                (U8) ENFBAssociatedIDAdded,//associated id
                (U8) 0,//reserved
                (U8) 0,//reserved
                (U8) (enfb_offset & 0xff),
                (U8) ((enfb_offset >> 8) & 0xff),
                (U8) ((enfb_offset >> 16) & 0xff),
                (U8) ((enfb_offset >> 24) & 0xff),
                (U8) (enfb_size & 0xff),
                (U8) ((enfb_size >> 8) & 0xff),
                (U8) ((enfb_size >> 16) & 0xff),
                (U8) ((enfb_size >> 24) & 0xff));
            
            /* image header/data to ENFB image data file */
            fprintf(
                enfb_img_data_file,
                "%c%c%c%c%c%c%c%c%c",
                (U8) 1,
                (U8) bits_per_pixel,
                (U8) 0,
                (U8) (width & 0xff),
                (U8) ((width >> 8) & 0xff),
                (U8) (height & 0xff),
                (U8) ((height >> 8) & 0xff),
                (U8) ((PDU_length) & 0xff),
                (U8) ((PDU_length) >> 8) & 0xff);
            for (i = 0; i < PDU_length; i++)
            {
                fprintf(enfb_img_data_file, "%c", buffer[i]);
            }
            
            enfb_offset += enfb_size;
            enfbFlag = 0;
        }
    #endif
        else    /* Write to .c .h file */
        {
            fprintf(
                out_file,
                "\n{\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,",
                (U8) 1,
                (U8) bits_per_pixel,
                (U8) 0,
                (U8) (width & 0xff),
                (U8) ((width >> 8) & 0xff),
                (U8) (height & 0xff),
                (U8) ((height >> 8) & 0xff),
                (U8) ((PDU_length) & 0xff),
                (U8) ((PDU_length) >> 8) & 0xff);
            for (i = 0; i < PDU_length; i++)
            {
                if ((i % 16) == 0)
                {
                    fprintf(out_file, "\n\t");
                }
                fprintf(out_file, "0x%02X, ", buffer[i]);
            }
            fprintf(out_file, "\n};\n");
        }
    }
    else
    {
        if (verbose_mode)
        {
            printf("\nWidth=%d, Height=%d, Size=%d bytes", width, height, PDU_length);
        }
        if (bits_per_pixel == 1)
        {
            for (i = 0; i < PDU_length; i++)
            {
                buffer[i] = 0x00;
                for (k = 8; k; k--)
                {
                    data =
                        (bytestream_fgetbyte(&rgb_image) + bytestream_fgetbyte(&rgb_image) +
                         bytestream_fgetbyte(&rgb_image)) / 3;
                    if (data >= 0 && data < 128)
                    {
                        scale_data = 0x01;
                    }
                    else
                    {
                        scale_data = 0x00;
                    }
                    buffer[i] |= scale_data << (k - 1);
                }
            }
        }
        else if (bits_per_pixel == 2)
        {
            for (i = 0; i < PDU_length; i++)
            {
                buffer[i] = 0x00;
                for (k = 8; k; k = k - 2)
                {
                    data =
                        (bytestream_fgetbyte(&rgb_image) + bytestream_fgetbyte(&rgb_image) +
                         bytestream_fgetbyte(&rgb_image)) / 3;
                    if (data >= 0 && data < 64)
                    {
                        scale_data = 0x00;
                    }
                    else if (data >= 64 && data < 128)
                    {
                        scale_data = 0x01;
                    }
                    else if (data >= 128 && data < 192)
                    {
                        scale_data = 0x02;
                    }
                    else
                    {
                        scale_data = 0x03;
                    }
                    buffer[i] |= scale_data << (k - 2);
                }
            }
        }
        else if (bits_per_pixel == 6)
        {
            for (i = 0; i < PDU_length; i++)
            {
                buffer[i] = 0x00;
                for (k = 8; k; k = k - 2)
                {
                    data = bytestream_fgetbyte(&rgb_image);
                    if (data >= 0 && data < 64)
                    {
                        scale_data = 0x00;
                    }
                    else if (data >= 64 && data < 128)
                    {
                        scale_data = 0x01;
                    }
                    else if (data >= 128 && data < 192)
                    {
                        scale_data = 0x02;
                    }
                    else
                    {
                        scale_data = 0x03;
                    }
                    buffer[i] |= scale_data << (k - 2);
                }
            }
        }
        if (verbose_mode)
        {
            printf("\nImage Data:");
        }
        printf(
            "\n{\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,",
            (U8) 1,
            (U8) bits_per_pixel,
            (U8) 0,
            (U8) (width & 0xff),
            (U8) ((width >> 8) & 0xff),
            (U8) (height & 0xff),
            (U8) ((height >> 8) & 0xff),
            (U8) ((PDU_length) & 0xff),
            (U8) ((PDU_length) >> 8) & 0xff);
    }
    if (verbose_mode)
    {
        printf("\nConvert OK\n");
    }
    return (1);
}


/*****************************************************************************
 * FUNCTION
 *  bmp2ems
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_filename         [?]         
 *  out_filename        [?]         
 *  binary_flag         [IN]        
 *  verbose_flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int bmp2ems(char *in_filename, char *out_filename, int binary_flag, int verbose_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *infile;
    bytestream inimage;
    S32 file_length;
    U8 *buffer;
    S32 i, bitmap_size, total_data_size;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infile = fopen(in_filename, "rb");
    if (infile == NULL)
    {
        printf("\nError opening %s", in_filename);
        return 0;
    }

    if (binary_flag == 1)
    {
        out_file = fopen(out_filename, "ab");
        while (!out_file)
        {
            //printf("\nError opening output file %s. Dumping image data to console ...", out_filename);
            Sleep(50);
            out_file = fopen(out_filename, "ab");
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
        #endif
        binary_mode = 1;
    }

    if (verbose_flag == 1)
    {
        verbose_mode = 1;
    }

    if (verbose_mode)
    {
        printf("\nBMP to EMS PDU converter");
        printf("\n(c) 2003 Pixtel communications Inc.");
    }

    fseek(infile, 0, SEEK_END);
    file_length = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    buffer = (U8*) malloc(file_length);
    if (buffer == NULL)
    {
        if (binary_mode)
        {
            fclose(out_file);
        }

        printf("\nError allocating memory of size %d bytes", file_length);
        fclose(infile);
        return 0;
    }

    fread(buffer, 1, file_length, infile);
    fclose(infile);
    bytestream_initialize(&inimage, buffer, file_length);
    ret = EMS_load(&inimage, in_filename);
    free(buffer);
    if (binary_mode)
    {
        fclose(out_file);
    }
    return ret;
}

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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  ImageGetDimension.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  get image dimension
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mmi_features.h"
#include "CustDataRes.h"
#include "ImageGetDimension.h"

/* header info size */
#define BMP_INFO_SIZE	26
#define GIF_INFO_SIZE	10
#define PNG_INFO_SIZE	24

/* markers of JPEG standard */
#define JPEG_MARKER_SOF0	0xC0
#define JPEG_MARKER_SOF1	0xC1
#define JPEG_MARKER_SOF2	0xC2
#define JPEG_MARKER_SOF3	0xC3
#define JPEG_MARKER_SOF15	0xCF
#define JPEG_MARKER_SOS		0xDA
#define JPEG_MARKER_DQT		0xDB
#define JPEG_MARKER_DNL		0xDC
#define JPEG_MARKER_DRI		0xDD
#define JPEG_MARKER_DHP		0xDE
#define JPEG_MARKER_EXP		0xDF
#define JPEG_MARKER_COM		0xFE
#define JPEG_MARKER_APP0	0xE0
#define JPEG_MARKER_APP15	0xEF

/* macros to get data (X) from buffer (SRC) */
#define GET_U8(SRC,X)           \
	do                          \
	{                           \
		X = ((U8) *(SRC)++);    \
	} while(0)

#define GET_U16(SRC,X)              \
	do                              \
	{                               \
		X = ((U16) (U8)*(SRC)++);   \
		X |= ((U16) *(SRC)++)<<8;   \
	} while(0)

#define GET_U24(SRC,X)                  \
	do                                  \
	{                                   \
		X = ((U32) (U8)*(SRC)++);       \
		X |= ((U32) (U8)*(SRC)++)<<8;   \
		X |= ((U32) (U8)*(SRC)++)<<16;  \
	} while(0)

#define GET_U32(SRC,X)                  \
	do                                  \
	{                                   \
		(X) = ((U32) (U8)*(SRC)++);     \
		(X) |= ((U32) (U8)*(SRC)++)<<8; \
		(X) |= ((U32) (U8)*(SRC)++)<<16;\
		(X) |= ((U32) (U8)*(SRC)++)<<24;\
	} while(0)

#define PEEK_U8(SRC,X)      \
	do                      \
	{                       \
        (X) = (U8) *(SRC);  \
	} while(0)

#define PEEK_U8_N(SRC,X,N)      \
	do                          \
	{                           \
        (X) = (U8) *(SRC + N);  \
	} while(0)

#define FLUSH(SRC,X)    \
	do                  \
	{                   \
		(SRC) += (X);   \
	} while(0)

#define MYFCLOSE(fp)    \
    do                  \
    {                   \
        if (fp != NULL) \
        {               \
            fclose(fp); \
            fp = NULL;  \
        }               \
    } while(0)

#define GDI_GIF_STACK_SIZE  (0x1000 + 4)
#define GDI_GIF_TREE_SIZE   (0x4000 + 4)

#define STR_SIZE    256

static char Video_Ext[][4] = {"AVI", "3GP", "MP4"};
static char PNG_seq_to_ENFB_str[][STR_SIZE] =
    { "SS_MAG",
      "SS_VOMAL",
      "SS_SEND",
      "SS_WARN",
      "SS_SUCES",
      "EM_CON",
      "EM_SEND",
      "EM_REVEIVE",
      "EM_SUCCESS",
      "EM_FAIL",
      "CL_END",
      "SYNCHRONZING",
      "ALARM",
      "LOADING",
      "PROGRESS",
      "SPEAKING",
      "SCALING",
      "SEARCH",
      "POPUPPAGE"
    };

extern MMI_BOOL ENFBAssociatedIDFlag;
extern MMI_BOOL ENFBAssociatedIDAdded;	

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern int disableENFB;
#endif

/*****************************************************************************
 * FUNCTION
 *  image_bmp_get_dimension
 * DESCRIPTION
 *  get dimension of a bmp from file
 * PARAMETERS
 *  filename    [IN]
 *  width       [OUT]
 *  height      [OUT]
 * RETURNS
 *  MMI_BOOL	MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL image_bmp_get_dimension(S8 *filename, U32 *width, U32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;
    U8 buf[BMP_INFO_SIZE];
    U8 *src;
    U16 bfType;
    U32 bfSize;
    U32 biWidth;
    U32 biHeight;
    U32 biSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* open file and read header to buffer */
    fp = fopen((char *)filename, "rb");
	if (fp == NULL)
	{
        fprintf(stderr, "Open file error:\t%s\n", filename);
        fprintf(stderr, "\t%s\n", strerror(errno));
		return MMI_FALSE;
	}
	if (fread(buf, sizeof(char), BMP_INFO_SIZE, fp) != BMP_INFO_SIZE)
	{
		fprintf(stderr, "Read file error:\t%s\n", filename);
        MYFCLOSE(fp);
		return MMI_FALSE;
	}
	src = buf;
    MYFCLOSE(fp);

	/* read file header */
	GET_U16(src, bfType);
	GET_U32(src, bfSize);
	FLUSH(src, 8);

	/* read info header */
    GET_U32(src, biSize);
	if (biSize == 12)
	{
		GET_U16(src, biWidth);
		GET_U16(src, biHeight);
	}
	else
	{
		GET_U32(src, biWidth);
		GET_U32(src, biHeight);
	}

	*width = biWidth;
	*height = biHeight;

	/* test if it is BMP file */
	if (bfType != 0x4d42)	/* BM */
	{
		fprintf(stderr, "Non-standard file error:\t%s\n", filename);
		return MMI_FALSE;
	}
	/* core info header, currently not support */
	if (bfSize == BMP_INFO_SIZE)
	{
		fprintf(stderr, "Non-standard file error:\t%s\n", filename);
		return MMI_FALSE;
	}

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  image_gif_get_dimension
 * DESCRIPTION
 *  get dimension of a gif from file
 * PARAMETERS
 *  filename    [IN]
 *  width       [OUT]
 *  height      [OUT]
 * RETURNS
 *  MMI_BOOL	MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL image_gif_get_dimension(S8 *filename, U32 *width, U32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;
    U8 buf[GIF_INFO_SIZE];
    U8 *src;
    U32 header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file and read header to buffer */
    fp = fopen((char *)filename, "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "Open file error:\t%s\n", filename);
        //fprintf(stderr, "\t%s\n", strerror(errno));
		return MMI_FALSE;
	}
	if (fread(buf, sizeof(char), GIF_INFO_SIZE, fp) != GIF_INFO_SIZE)
	{
		fprintf(stderr, "Read file error:\t%s\n", filename);
        MYFCLOSE(fp);
		return MMI_FALSE;
	}
	src = buf;
    MYFCLOSE(fp);

    /* test if it is BMP file */
    GET_U24(src, header);
    if (header != 0x464947) /* 'GIF' */
    {
        *width = 0;
        *height = 0;
        return MMI_FALSE;
    }
    
    /* read GIF dimention */
    FLUSH(src, 3);
    GET_U16(src, *width);
    GET_U16(src, *height);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  image_gif_get_frame_count
 * DESCRIPTION
 *  get frame count of a gif from file
 * PARAMETERS
 *  filename    [IN]
 *  framecount  [OUT]
 * RETURNS
 *  MMI_BOOL	MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL image_gif_get_frame_count(S8 *filename, U32 *framecount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;
	U8 *buf, *src;
    U32 header;
    U32 file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file and read header to buffer */
    fp = fopen((char *)filename, "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "Open file error:\t%s\n", filename);
        fprintf(stderr, "\t%s\n", strerror(errno));
		return MMI_FALSE;
	}

    fseek(fp, 0, SEEK_END);
    file_size = (U32)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    buf = (U8*)malloc(file_size*sizeof(U8));
    if (buf == NULL)
    {
		fprintf(stderr, "Memory allocation failed:\t%s\n", filename);
        MYFCLOSE(fp);
		return MMI_FALSE;
    }
    if (fread(buf, sizeof(char), file_size, fp) != file_size)
    {
		fprintf(stderr, "Read file error:\t%s\n", filename);
        MYFCLOSE(fp);
		return MMI_FALSE;
    }
    src = buf;
    MYFCLOSE(fp);

    /* init the return frame_count value */
    *framecount = 0;
    
    /* read the GIF file signature */
    {
        U8 sig[3];

        GET_U8(src, sig[0]);
        GET_U8(src, sig[1]);
        GET_U8(src, sig[2]);

        if (sig[0] != 'G' || sig[1] != 'I' || sig[2] != 'F')
        {
            return MMI_FALSE;
        }
    }

    /* skip dimension value */
    {
        S16 img_w, img_h;

        FLUSH(src, 3);
        GET_U16(src, img_w);
        GET_U16(src, img_h);
        if(img_w < 0 || img_h < 0 || img_w >= 10240 || img_h >= 10240)
        {
            return MMI_FALSE;
        }
    }

    /* read the global color palette */
    {
        S32 palette_count;
        
        GET_U8(src, palette_count);
        FLUSH(src, 2);


        if (palette_count & 0x80)
        {
            palette_count = 1 << ((palette_count & 0x7) + 1);
            FLUSH(src, (palette_count * 3));
        }
    }

    /* start decoding */
    do
    {
        U8 symbol;

        GET_U8(src, symbol);
        switch(symbol)
        {
            /* Process the GIF extension block */
            case '!':
                {
                    U8 ext;

                    GET_U8(src, ext);
                    
                    if (ext == 0xf9)
                    {
                        FLUSH(src, 6);
                    }
                    else
                    {
                        U8 boffset;
                        S32 offset;

                        while (1)
                        {
                            GET_U8(src, boffset);
                            offset = (S32)boffset;
                            if (offset == 0)
                            {
                                break;
                            }
                            FLUSH(src, offset);
                        }
                    }
                }
                break;
                
            case ',':
                /* gdi_image_gif_dummy_decoder(); */
                {
                    S32 want_pixels;
                    S32 bitstream_available_bits, bytestream_available;
                    S32 GDI_TREE_BUFFER[GDI_GIF_TREE_SIZE / sizeof(S32)];
                    U32 bitstream;
                    S16 GIF_current_code_size, GIF_clear_code, GIF_end_code, GIF_new_codes, GIF_top_slot, GIF_slot;
                    S16 size, c, oc, fc, code;
                    S16 *stack_pointer;
                    S16 GIF_mtk_stack[GDI_GIF_STACK_SIZE / sizeof(S16)];
                    S16 *GIF_mtk_suffix = (S16 *) GDI_TREE_BUFFER;
                    S16 *GIF_mtk_prefix = (S16 *) (((U8 *) GDI_TREE_BUFFER) + sizeof(GDI_TREE_BUFFER) / 2);
                    U16 temp;
                    U8 finished_decoding = 0;

                    {
                        S32 x, y, xsize, ysize;

                        GET_U16(src, temp);     x = (S32)temp;
                        GET_U16(src, temp);     y = (S32)temp;
                        GET_U16(src, temp);     xsize = (S32)temp;
                        GET_U16(src, temp);     ysize = (S32)temp;
                        
                        want_pixels = xsize * ysize;
                    }

                    {
                        S32 n;

                        GET_U8(src, n);

                        if (src >= buf + file_size)
                        {
                            return MMI_FALSE;
                        }

                        if (n & 0x80)
                        {
                            n = 1 << ((n & 0x7) + 1);

                            /* skip reading palette */
                            FLUSH(src, n * 3);
                        }
                    }

                    GET_U8(src, temp);  size = (S16)temp;

                    /* GIF_INITIALIZE_DECODER(size);*/
                    GIF_current_code_size = (S16)(size + 1);
                    GIF_top_slot = (S16)(1 << GIF_current_code_size);
                    GIF_clear_code = (S16)(1 << size);
                    GIF_end_code = (S16)(GIF_clear_code + 1);
                    GIF_slot = (GIF_new_codes) = (S16)(GIF_end_code + 1);
                    bitstream_available_bits = 0;
                    bytestream_available = 0;
                    bitstream = 0;

                    oc = fc = 0;
                    stack_pointer = GIF_mtk_stack;

                    /* begin decoding */
                    while (!finished_decoding)
                    {
                        /* GIF_GET_NEXT_CODE(c); */
                        while(GIF_current_code_size > bitstream_available_bits)
                        {
                            if(bytestream_available == 0)
                            {
                                GET_U8(src, temp);  bytestream_available = (S32)temp;
                            }
                            GET_U8(src, temp);
                            bitstream |= temp << bitstream_available_bits;
                            bitstream_available_bits +=8;
                            bytestream_available--;
                        }
                        bitstream_available_bits -= GIF_current_code_size;
                        c = (S16) bitstream & ((1 << GIF_current_code_size) - 1);
                        bitstream >>= GIF_current_code_size;

                        if (c == GIF_end_code)
                        {
                            break;
                        }

                        if (src >= buf + file_size)
                        {
                            return MMI_FALSE;
                        }

                        if (c == GIF_clear_code)
                        {
                            GIF_current_code_size = (S16) (size + 1);
                            GIF_slot = GIF_new_codes;
                            GIF_top_slot = (S16) (1 << GIF_current_code_size);

                            /* GIF_GET_NEXT_CODE(c); */
                            while(GIF_current_code_size > bitstream_available_bits)
                            {
                                if(bytestream_available == 0)
                                {
                                    GET_U8(src, temp);  bytestream_available = (S32)temp;
                                }
                                GET_U8(src, temp);
                                bitstream |= temp << bitstream_available_bits;
                                bitstream_available_bits +=8;
                                bytestream_available--;
                            }
                            bitstream_available_bits -= GIF_current_code_size;
                            c = (S16) bitstream & ((1 << GIF_current_code_size) - 1);
                            bitstream >>= GIF_current_code_size;

                            if (c == GIF_end_code)
                            {
                                break;
                            }

                            if (src >= buf + file_size)
                            {
                                return MMI_FALSE;
                            }

                            if (c >= GIF_slot)
                            {
                                c = 0;
                            }

                            oc = fc = c;
                            if ((--want_pixels) < 0)
                            {
                                finished_decoding = 1;
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
                                if(stack_pointer >= (S16*)(((U8*)GIF_mtk_stack) + sizeof(GIF_mtk_stack)))
                                {
                                    return MMI_FALSE;
                                }

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
                                if ((--want_pixels) < 0)
                                {
                                    finished_decoding = 1;
                                    break;
                                }
                                --stack_pointer;
                            }
                        }
                    }
                }

                (*framecount) += 1;

                /* peek if is last frame */
                {
                    U8 test1, test2;

                    PEEK_U8(src, test1);
                    PEEK_U8_N(src, test2, 1);
                    if ((test1 == '\0') && (test2 == ';'))
                    {
                        /* GDI_GIF_LAST_FRAME;; */
                        return MMI_TRUE;
                    }
                }
                break;

            case '\0':
                if (src >= buf + file_size)
                {
                    /* GDI_GIF_LAST_FRAME */
                    return MMI_TRUE;
                }
                break;

            case ';':
                /* GDI_GIF_LAST_FRAME;; */
                return MMI_TRUE;
                break;
        }
    } while (src < buf + file_size);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  image_png_get_dimension
 * DESCRIPTION
 *  get dimension of a png from file
 * PARAMETERS
 *  filename    [IN]
 *  width       [OUT]
 *  height      [OUT]
 * RETURNS
 *  MMI_BOOL	MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL image_png_get_dimension(S8 *filename, U32 *width, U32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;
	U8 buf[PNG_INFO_SIZE];
    U8 *src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file and read header to buffer */
    fp = fopen((char *)filename, "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "Open file error:\t%s\n", filename);
        fprintf(stderr, "\t%s\n", strerror(errno));
		return MMI_FALSE;
	}
	if (fread(buf, sizeof(char), PNG_INFO_SIZE, fp) != PNG_INFO_SIZE)
	{
		fprintf(stderr, "Read file error:\t%s\n", filename);
        MYFCLOSE(fp);
		return MMI_FALSE;
	}
    src = buf;
    MYFCLOSE(fp);

    /* test if it is BMP file and get PNG dimension */
    if (memcmp(src, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)  /* PNG signature */
    {
        if (*((U32*) (src + 8)) == 13 << 24)             /* must be IHDR, length = 13,but LSB */
        {
            if (memcmp(src + 12, "IHDR", 4) == 0)        /* must be 'IHDR' */
            {
                src += 16;
                *width = (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | (src[3]);
                src += 4;
                *height = (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | (src[3]);
                return MMI_TRUE;
            }
        }
    }
        
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  image_jpg_get_dimension
 * DESCRIPTION
 *  get dimension of a jpg from file
 * PARAMETERS
 *  filename    [IN]
 *  width       [OUT]
 *  height      [OUT]
 * RETURNS
 *  MMI_BOOL	MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL image_jpg_get_dimension(S8 *filename, U32 *width, U32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;

	U32 index, index_offset;
	U16 marker_length;
	U8 jpg_byte1, jpg_byte2, tmp_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* open file and read header to buffer */
    fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "Open file error:\t%s\n", filename);
        fprintf(stderr, "\t%s\n", strerror(errno));
		return MMI_FALSE;
	}

	index = 0;

	jpg_byte1 = fgetc(fp);
	jpg_byte2 = fgetc(fp);

	/* check first two byte to see if is valid jpeg file */
    if ((jpg_byte1 != 0xFF) || (jpg_byte2 != 0xD8))
	{
        MYFCLOSE(fp);
		return MMI_FALSE;
	}

    *width = *height = 0;

	/* parse bytestream */
	do
	{
		if (feof(fp))
		{
			break;
		}

		do
		{
			tmp_byte = fgetc(fp);
		} while (tmp_byte != 0xFF);

		jpg_byte1 = 0xFF;
		jpg_byte2 = fgetc(fp);

		switch (jpg_byte2)
		{
			case JPEG_MARKER_SOF0:
			case JPEG_MARKER_SOF2:
				marker_length = fgetc(fp) << 8;
				marker_length |= fgetc(fp);
				marker_length -= 2;

				fgetc(fp);  /* precision */
				*height = fgetc(fp) << 8;
				*height |= fgetc(fp);
				*width = fgetc(fp) << 8;
				*width |= fgetc(fp);

				/* set terminate byte */
				jpg_byte2 = 0xD9;
				break;

			case JPEG_MARKER_SOS:
				break;

			case 0xC8:
			case 0x00:
				break;

			default:
				if ((jpg_byte2 == JPEG_MARKER_SOF1) ||
				    ((jpg_byte2 >= JPEG_MARKER_SOF3) && (jpg_byte2 <= JPEG_MARKER_SOF15)) ||
					(jpg_byte2 == JPEG_MARKER_DQT) || (jpg_byte2 == JPEG_MARKER_DNL) ||
					(jpg_byte2 == JPEG_MARKER_DRI) || (jpg_byte2 == JPEG_MARKER_DHP) ||
					(jpg_byte2 == JPEG_MARKER_EXP) || (jpg_byte2 == JPEG_MARKER_COM) ||
					((jpg_byte2 >= JPEG_MARKER_APP0) && (jpg_byte2 <= JPEG_MARKER_APP15)))
				{
					U8 *dummy;

					index_offset = fgetc(fp) << 8;
					index_offset |= fgetc(fp);
					index_offset -= 2;

					dummy = (U8 *)malloc(index_offset*sizeof(U8));
					fread(dummy, sizeof(U8), index_offset, fp);
					free(dummy);
				}
				break;
		}
	} while (!((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD9)));
	
    MYFCLOSE(fp);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Image_Get_Dimensions
 * DESCRIPTION
 *  Get the dimensions of the image resource
 * PARAMETERS
 *  filename    [IN]
 *  width       [OUT]
 *  height      [OUT]
 * RETURNS
 *  int			>=0: frame count, <0: failed
 *****************************************************************************/
S32 Image_Get_Dimensions(S8 *filename, U32 *width, U32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ext[4] = {0};	/* filename extension */
    U32 i = 0;
    MMI_BOOL ret = 0;
    S32 framecount = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get filename extension and convert it to upper case */
    for(i = 0; i < 3; i++)
    {
        ext[i] = toupper(filename[strlen(filename) - 3 + i]);
    }
    ext[3] = '\0';

    *width = *height = 0;

    /* get dimension of BMP or PBM file */
    if ((strncmp(ext, "BMP", 3) == 0) ||
        (strncmp(ext, "PBM", 3) == 0))
    {
        ret = image_bmp_get_dimension(filename, width, height);
    }
    /* get dimension of GIF file */
    else if ((strncmp(ext, "GIF", 3) == 0))
    {
        ret = image_gif_get_dimension(filename, width, height);
        if (ret == MMI_TRUE)
        {
            ret = image_gif_get_frame_count(filename, &framecount);
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
        }
    }
    /* get dimension of PNG file */
    else if ((strncmp(ext, "PNG", 3) == 0) ||
             (strncmp(ext, "PPN", 3) == 0))
    {
        ret = image_png_get_dimension(filename, width, height);
    }
    /* get dimension of JPG file */
    else if ((strncmp(ext, "JPG", 3) == 0))
    {
        ret = image_jpg_get_dimension(filename, width, height);
    }
    /* other files will return false directly */
    else
    {
        ret = MMI_FALSE;
    }

    if (ret == MMI_FALSE)
    {
        fprintf(stderr, "File error:\t\t%s\n", filename);
        return 0;
    }
    else
    {
        return framecount;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Image_Test
 * DESCRIPTION
 *  test the resource is video, over-half-size image, or others
 * PARAMETERS
 *  filename    [IN]
 *  width       [OUT]
 *  height      [OUT]
 * RETURNS
 *  int			>0: video or over-half-size image, =0: others
 *****************************************************************************/
S32 Image_Test(S8 *filename, U32 *width, U32 *height)
{
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 ext[4];	/* filename extension */
	U32 lw, lh;		/* resolution of LCD size */
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (disableENFB)
    {
        return ENFB_IMAGE_NONE;
    }
    else if (ENFBAssociatedIDFlag == MMI_TRUE)
    {
        //ENFBAssociatedIDAdded = MMI_TRUE;
        return ENFB_IMAGE_ASSOCIATE;
    }

	/* get filename extension and convert it to upper case */
	for(i = 0; i < 3; i++)
	{
		ext[i] = toupper(filename[strlen(filename) - 3 + i]);
	}
    ext[3] = '\0';

	*width = *height = 0;

    /* if video file, return true */
    for (i = 0; i < (sizeof(Video_Ext) / 4); i++)
    {
        if (strncmp(ext, Video_Ext[i], 3) == 0)
        {
            return ENFB_IMAGE_VIDEO;
        }
    }

	/* get dimension of BMP or PBM file */
    if ((strncmp(ext, "BMP", 3) == 0) ||
        (strncmp(ext, "PBM", 3) == 0))
	{
		if(image_bmp_get_dimension(filename, width, height) == MMI_FALSE)
		{
			return ENFB_IMAGE_NONE;
		}
	}
	/* get dimension of GIF file */
	else if ((strncmp(ext, "GIF", 3) == 0))
	{
		if(image_gif_get_dimension(filename, width, height) == MMI_FALSE)
		{
			return ENFB_IMAGE_NONE;
		}
	}
	/* get dimension of PNG file */
	else if ((strncmp(ext, "PNG", 3) == 0) ||
             (strncmp(ext, "PPN", 3) == 0))
	{
	    /* if PNG pop-up, force to be E-NFB */
        for (i = 0; i < (sizeof(PNG_seq_to_ENFB_str) / STR_SIZE); i++)
        {   
	        if (strstr(filename, PNG_seq_to_ENFB_str[i]) != NULL)
            {
                return ENFB_IMAGE_DIMENSION;
            }
        }
	    
		if(image_png_get_dimension(filename, width, height) == MMI_FALSE)
		{
			return ENFB_IMAGE_NONE;
		}
	}
	/* get dimension of JPG file */
	else if ((strncmp(ext, "JPG", 3) == 0))
	{
		if(image_jpg_get_dimension(filename, width, height) == MMI_FALSE)
		{
			return ENFB_IMAGE_NONE;
		}
	}
	/* other files will return false directly */
	else
	{
		return ENFB_IMAGE_NONE;
	}

	/* set main LCD size */
	lw = lh = 0;
#ifdef __MMI_MAINLCD_128X128__
	lw = 128;
	lh = 128;
#elif __MMI_MAINLCD_128X160__
	lw = 128;
	lh = 160;
#elif __MMI_MAINLCD_176X220__
	lw = 176;
	lh = 220;
#elif __MMI_MAINLCD_240X320__
	lw = 240;
	lh = 320;
#elif __MMI_MAINLCD_320X240__
	lw = 320;
	lh = 240;
#else
#error "No specific resolution in ImageGetDimension.c"
#endif

    //printf("\nPBM --> %s --> %d x %d\n", filename, *width, *height);

	/* test whether the image file is over half of the LCD size */
	if ((*width) * (*height) >= 0.5 * lw * lh)
	{
	    printf("enfb file = %s\n", filename);
		return ENFB_IMAGE_DIMENSION;
	}

	return ENFB_IMAGE_NONE;
#else
	return 0;   // ENFB_IMAGE_NONE;
#endif
}

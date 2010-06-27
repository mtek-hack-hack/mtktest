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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  ABMLoader.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Alpha BitMap (ABM) encoder
 *
 *  1. The search algorithm of the color index table is binary search.
 *  2. The ABM encoder only support 8, 24, and 32-bit bitmap input.
 *  3. ABM only supports up to 65536 colors.
 *  4. The ABM palette color format is:
 *     a. 16-bit for 16-bit MAIN BASE LAYER (MOST CASE)
 *     b. 24-bit for 24-bit and 32-bit MAIN BASE LAYER
 * 
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *============================================================================
 ****************************************************************************/

/*
 * THIS FILE IS USED FOR RESOURCE GENERATOR AND MTE ONLY.
 */
#if !defined(__MTK_TARGET__) || defined(__RESOURCE_GEN_)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include <stdio.h>
#include "MMI_features.h"
#include "ABMLoader.h"
#include "gui_resource_type.h"

#include "gdi_include.h"

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#include "ImageGetDimension.h"
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

/***************************************************************************** 
 * extern variable
 *****************************************************************************/
extern S32 g_ressize;
extern int toolFlag;
extern FILE *dest_file;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern FILE *enfb_img_data_file;
extern int enfbFlag;
extern U32 enfb_offset;
extern U32 enfb_size;
extern MMI_BOOL ENFBAssociatedIDAdded;
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* check 16-bit RGB color format */
#define RGB_16_BIT_TYPE         DRV_RGB_TO_HW(0, 255, 0)
#define COLOR_FORMAT_RGB3553    0xE007  /* 6205B, 6218 */
#define COLOR_FORMAT_RGB565     0x07E0  /* other than 6205B and 6218 */


/*
 * color primitives
 */
#define GET_32(bp)  ((U32)((bp)[0] | ((bp)[1] << 8) | ((bp)[2] << 16) | ((bp)[3] << 24)))
#define GET_24(bp)  ((U32)((bp)[0] | ((bp)[1] << 8)) | ((bp)[2] << 16))
#define GET_16(bp)  ((U32)((bp)[0] | ((bp)[1] << 8)))
    
#define PUT_16(mem, c)  *((U16*)(mem)) = (c)
#define PUT_24(mem, c)             \
    do                             \
    {                              \
        U8 *mem_8 = (U8*)(mem);    \
        mem_8[0] = (c);            \
        mem_8[1] = (c) >> 8;       \
        mem_8[2] = (c) >> 16;      \
    } while (0)
    
#define ARGB(a, r, g, b)            (((a) << 24) | ((r) << 16) | ((g) << 8) | (b))
#define RGB(r, g, b)                (((r) << 16) | ((g) << 8) | (b))
    
/* RGB888 */
#define R_OF_RGB888(c)              (((c) << 8) >> 24)
#define G_OF_RGB888(c)              (((c) << 16) >> 24)
#define B_OF_RGB888(c)              (((c) << 24) >> 24)
    
/* ARGB8888 */
#define A_OF_ARGB8888(c)            ((c) >> 24)
#define R_OF_ARGB8888(c)            R_OF_RGB888(c)
#define G_OF_ARGB8888(c)            G_OF_RGB888(c)
#define B_OF_ARGB8888(c)            B_OF_RGB888(c)
    
/* RGB565 */
#define R_OF_RGB565(c)              (((c) << 16) >> 27)
#define G_OF_RGB565(c)              (((c) << 21) >> 26)
#define B_OF_RGB565(c)              (((c) << 27) >> 27)
    
/* RGB3553 */
#define R_OF_RGB3553(c)             (((c) << 24) >> 27)
#define G_OF_RGB3553(c)             ((((c) & 0x7) << 3) | (((c) >> 13) & 0x7))
#define B_OF_RGB3553(c)             (((c) << 19) >> 27)
 
/* RGB16 */
#define R_OF_RGB16(c)               ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? R_OF_RGB565(c) : R_OF_RGB3553(c))
#define G_OF_RGB16(c)               ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? G_OF_RGB565(c) : G_OF_RGB3553(c))
#define B_OF_RGB16(c)               ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? B_OF_RGB565(c) : B_OF_RGB3553(c))

#define RGB565(r, g, b)             (((r) << 11) | ((g) << 5) | (b))
#define RGB3553(r, g, b)            (((r) << 3) | ((b) << 8) | ((g) >> 3) | (((g) & 0x7) << 13))
    
#define ARGB8888_TO_RGB565(c)       RGB565(R_OF_ARGB8888(c) >> 3, G_OF_ARGB8888(c) >> 2, B_OF_ARGB8888(c) >> 3)
#define ARGB8888_TO_RGB3553(c)      RGB3553(R_OF_ARGB8888(c) >> 3, G_OF_ARGB8888(c) >> 2, B_OF_ARGB8888(c) >> 3)

#define ARGB8888_TO_RGB16(c)        ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? ARGB8888_TO_RGB565(c) : ARGB8888_TO_RGB3553(c))


/* 
 * color reduction algorithms
 */
#define COLOR_REDUCE_24_TO_16(c)    ((c) & 0xFFF8FCF8)  /* clear R[2:0], G[1:0], B[2:0] */
#define COLOR_REDUCE_24_TO_18(c)    ((c) & 0xFFFCFCFC)  /* clear R[1:0], G[1:0], B[1:0] */

// TODO: SHOULD USE COLOR_REDUCE_24_TO_18 for 18-bit panels (to reduce unique colors)
#define COLOR_REDUCE(c)             ((ABM_PALETTE_BPP == 16) ? COLOR_REDUCE_24_TO_16(c) : (c))


/*
 * ABM bitstream writer
 */
/* initialize bitstream variables */
#define BW_INIT(mem_ptr)                \
    {                                   \
        U32 bits_buf;                   \
        U16 *bits_mem_ptr;              \
        U32 bits_left;                  \
                                        \
        bits_mem_ptr = mem_ptr;         \
        bits_buf = 0;                   \
        bits_left = 0;

/* flush bitstream buffer */
#define BW_END()                        \
        if (bits_left > 0)              \
        {                               \
            *bits_mem_ptr++ = bits_buf; \
        }                               \
    }

/* write bpp bits of data into the bitstream */
#define BW_WRITE(data, bpp)                                     \
    bits_buf |= ((data) & ((1 << (bpp)) - 1)) << bits_left;     \
    bits_left += bpp;                                           \
    if (bits_left >= 16)                                        \
    {                                                           \
        *bits_mem_ptr++ = bits_buf;                             \
        bits_buf >>= 16;                                        \
        bits_left -= 16;                                        \
    }


/* PBM header size */
#define PBM_HEADER_SIZE             13


/*
 * windows bitmap
 */
#define BITMAPFILEHEADER_SIZE       14
#define BITMAPINFO_HEADER_SIZE      40


/*
 * ABM encoder
 */
#define ABM_MAX_COLOR_NUM   65536                       /* ABM supports up to 65536 colors */
#define ABM_HEADER_SIZE     12
#define ABM_PALETTE_BPP     ((MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16) ? 16 : 24)

#define TRANSPARENT_COLOR_24        RGB(10, 11, 12)         /* transparent color of 24-bit bitmap */
#define TRANSPARENT_COLOR_32        ARGB(255, 10, 11, 12)   /* transparent color of 32-bit bitmap */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef U32 mycolor;

/* abm encoder structure*/
typedef struct
{
    S32     bmp_width;                  /* bitmap width */
    S32     bmp_height;                 /* bitmap height */
    S32     bmp_bpp;                    /* bitmap bits per pixel */
    S32     bmp_palette_num;            /* number of colors in the palette */  
    mycolor bmp_palette[256];           /* bitmap palette (8-bit bpp max) */    
    U8      *bmp_pixel_start_p;         /* pointer to bitmap data */
    U32     line_padding_bytes;         /* line padding bytes */
    
    S32     x1, y1, x2, y2;             /* image bounding box */

    S32     src_key_color_enable;       /* for PBM source key color */
    S32     is_windows_bmp;             /* windows BMP 32-bit is always XRGB8888, not expected ARGB8888. */
} abm_enc_struct;

/* color index table */
typedef struct
{
    mycolor color_table[ABM_MAX_COLOR_NUM]; /* color index table */
    S32     color_num;                      /* number of colors in the table */
    
    S32     last_search_idx;                /* last search index */
} color_index_table_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* file buffer to keep the whole bitmap file */
static U8 g_file_buf[ABMENC_BMP_FILE_BUFFER_SIZE];

/* color index table */
static color_index_table_struct g_color_idx_tab;
static color_index_table_struct * const cit = &g_color_idx_tab; /* Color Index Table -> cit */

/* abm encoder context */
static abm_enc_struct g_abm_enc;
static abm_enc_struct * const abm_enc = &g_abm_enc;

/* table to calculate ceiling(log2(x)) */
static const U16 log2_table[15] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};


/***************************************************************************** 
 * static Function
 *****************************************************************************/
static S32  search_color(mycolor search_color);
static void insert_color_at(mycolor c, S32 insert_idx);
static void add_color_if_new(mycolor c);
static U32  get_normal_color_num(void);

static U32  get_file_size(FILE *fp);
static S32  parse_bitmap(U8* bmp_data_p, U32 input_bmp_file_size);

static void update_image_bounding_box(S32 x, S32 y);
static void limit_image_bounding_box(void);

static U32  log2_ceiling(U32 x);

static void abmenc_build_color_index_table(void);
static U32  abmenc_encode(U8* out_mem_p);


/*****************************************************************************
 * FUNCTION
 *  search_color
 * DESCRIPTION
 *  search a color in the color table (binary search)
 * PARAMETERS
 *  search_color       [IN] color to search
 * RETURNS
 *  color index in the color table if found, otherwise ABMENC_COLOR_NOT_FOUND (-1)
 *****************************************************************************/
static S32 search_color(mycolor search_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     start_idx, end_idx, center_idx;
    mycolor c;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_idx = 0;
    end_idx = cit->color_num - 1;

    while (start_idx <= end_idx) 
    {
        center_idx = (start_idx + end_idx) / 2;
        c = cit->color_table[center_idx];

        if (search_color < c)
        {
            start_idx = center_idx + 1;
        }
        else if (search_color > c)
        {
            end_idx = center_idx - 1;
        }
        else
        {
            return center_idx;
        }
    } 

    /* keep the search index to speed up the search-and-insert operation, add_color_if_new() */
    cit->last_search_idx = start_idx;

    return ABMENC_COLOR_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  insert_color_at
 * DESCRIPTION
 *  insert a color at a specified index in the color table
 * PARAMETERS
 *  c                [IN] color to add  
 *  insert_idx       [IN] insertion index of the table
 * RETURNS
 *  void
 *****************************************************************************/
static void insert_color_at(mycolor c, S32 insert_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (insert_idx >= ABM_MAX_COLOR_NUM)
    {
        return;
    }    
    
    /* insert at insert_idx */
    for (i = cit->color_num - 1; i >= insert_idx; i--)
    {
        cit->color_table[i + 1] = cit->color_table[i];
    }

    cit->color_table[insert_idx] = c;
    cit->color_num++;    
}


/*****************************************************************************
 * FUNCTION
 *  add_color_if_new
 * DESCRIPTION
 *  add a color if the color does not exist in the table
 * PARAMETERS
 *  c       [IN] color to add
 * RETURNS
 *  void
 *****************************************************************************/
static void add_color_if_new(mycolor c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     insert_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    insert_idx = search_color(c);

    if (insert_idx == ABMENC_COLOR_NOT_FOUND)
    {
        insert_idx = cit->last_search_idx;
    }
    else
    {   /* found in the table, return */
        return;
    }

    insert_color_at(c, insert_idx);
}


/*****************************************************************************
 * FUNCTION
 *  get_normal_color_num
 * DESCRIPTION
 *  get the number of NORMAL colors
 * PARAMETERS
 *  void
 * RETURNS
 *  number of OPAQUE colors (alpha = 255) in the color index table
 *****************************************************************************/
static U32 get_normal_color_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cit->color_num; i++)
    {
        if (A_OF_ARGB8888(cit->color_table[i]) != 255)
        {
            break;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  get_file_size
 * DESCRIPTION
 *  return the file size in bytes
 * PARAMETERS
 *  fp       [IN]   file pointer
 * RETURNS
 *  file size in bytes
 *****************************************************************************/
static U32 get_file_size(FILE *fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32     fpos, file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* save the current file position */
    fpos = ftell(fp);

    /* seek to the EOF */    
    fseek(fp, 0, SEEK_END);

    /* get file size */
    file_size = ftell(fp);

    /* restore the old file position */
    fseek(fp, fpos, SEEK_SET);

    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  parse_bitmap
 * DESCRIPTION
 *  parse and verify the bitmap header (BITMAPFILEHEADER and BITMAPINFO)
 * PARAMETERS
 *  bitmap_p       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 parse_bitmap(U8* bmp_data_p, U32 input_bmp_file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32     bmp_w, bmp_h, bmp_bpp;
    S32     i;
    U32     bi_size;

    U32     line_size;

    U8      *pal_color_p;

    mycolor pal_first_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the "BM" magic number */
    if ((bmp_data_p[0] != 'B') || (bmp_data_p[1] != 'M'))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* verify the bitmap file size */
    if (GET_32(bmp_data_p + 2) != input_bmp_file_size)
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* verify the BITMAPINFO HEADER size field */
    bi_size = GET_32(bmp_data_p + 14);
    if (bi_size < BITMAPINFO_HEADER_SIZE)
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* get bitmap width, height, and bits per pixel */
    bmp_w = GET_32(bmp_data_p + 18);
    bmp_h = GET_32(bmp_data_p + 22);
    bmp_bpp = GET_16(bmp_data_p + 28);

    /* only support 8, 24, and 32 bpp */
    if ((bmp_bpp != 8) && (bmp_bpp != 24) && (bmp_bpp != 32))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* only support bottom-up bitmap */
    if (((S32)bmp_h <= 0) || ((S32)bmp_w <= 0))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* limit image dimension to 1024x1024 */
    if (((S32)bmp_h > 1024) || ((S32)bmp_w > 1024))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* get the palette color num */
    if (bmp_bpp == 8)
    {
        abm_enc->bmp_palette_num = GET_32(bmp_data_p + 46);
        if (abm_enc->bmp_palette_num == 0)
        {
            abm_enc->bmp_palette_num = 256;
        }
    }
    else
    {
        abm_enc->bmp_palette_num = 0;
    }

    /* make sure palette color number is 256 maximally */
    if (abm_enc->bmp_palette_num > 256)
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* line size in bytes */
    line_size = bmp_bpp * bmp_w / 8;

    abm_enc->line_padding_bytes = (line_size + 3) / 4 * 4 - line_size;

    abm_enc->bmp_width = bmp_w;
    abm_enc->bmp_height = bmp_h;
    abm_enc->bmp_bpp = bmp_bpp;

    /* get palette */
    pal_color_p = bmp_data_p + BITMAPFILEHEADER_SIZE + bi_size;
    pal_first_color = GET_32(pal_color_p);

    for (i = 0; i < abm_enc->bmp_palette_num; i++)
    {
        abm_enc->bmp_palette[i] = GET_32(pal_color_p + i * 4);

        /* A of ARGB quad is reserved as 0, convert it to opacity 255 */
        if (abm_enc->src_key_color_enable && (abm_enc->bmp_palette[i] == pal_first_color))
        {   
            /* 
             * The transparency color is the first color in the palette.
             * Any equivalent color is also the transpareny color.
             *
             * ONLY VALID FOR PBM AND BMP FILES.
             */
            abm_enc->bmp_palette[i] = 0;    /* force alpha value 0 */
        }
        else
        {
            abm_enc->bmp_palette[i] |= 0xFF000000; /* opaque color, alpha value 255 */
        }
    }

    /* bitmap pixel start offset */
    abm_enc->bmp_pixel_start_p = bmp_data_p + GET_32(bmp_data_p + 10);

    return ABM_ENC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  update_image_bounding_box
 * DESCRIPTION
 *  update image bounding box (piggy-back in the first pass)
 * PARAMETERS
 *  x       [IN] x coordinate of non-transparent color
 *  y       [IN] y coordinate of non-transparent color
 * RETURNS
 *  void
 *****************************************************************************/
static void update_image_bounding_box(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = abm_enc->x1;
    y1 = abm_enc->y1;
    x2 = abm_enc->x2;
    y2 = abm_enc->y2;

    /* x1 = min(x of non-transparent color) */
    if (x < x1)
    {
        x1 = x;
    }

    /* y1 = min(y of non-transparent color) */
    if (y < y1)
    {
        y1 = y;
    }

    /* x2 = max(x of non-transparent color) */
    if (x > x2)
    {
        x2 = x;
    }

    /* y2 = max(y of non-transparent color) */
    if (y > y2)
    {
        y2 = y;
    }

    abm_enc->x1 = x1;
    abm_enc->y1 = y1;
    abm_enc->x2 = x2;
    abm_enc->y2 = y2;
}


/*****************************************************************************
 * FUNCTION
 *  limit_image_bounding_box
 * DESCRIPTION
 *  limit the x1, y1, x2, and y2 within 8-bit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void limit_image_bounding_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     w, h, bottom_right_off_w, bottom_right_off_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    w = abm_enc->bmp_width;
    h = abm_enc->bmp_height;

    if (abm_enc->x1 > 255)
    {
        abm_enc->x1 = 255;
    }

    if (abm_enc->y1 > 255)
    {
        abm_enc->y1 = 255;
    }

    bottom_right_off_w = w - 1 - abm_enc->x2;
    if (bottom_right_off_w > 255)
    {
        abm_enc->x2 = w - 1 - bottom_right_off_w;
    }

    bottom_right_off_h = h - 1 - abm_enc->y2;
    if (bottom_right_off_h > 255)
    {
        abm_enc->y2 = h - 1 - bottom_right_off_h;
    }
}


/*****************************************************************************
 * FUNCTION
 *  abmenc_build_color_index_table
 * DESCRIPTION
 *  build the color index table (first pass)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void abmenc_build_color_index_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x, y, w, h;
    S32     line_padding_bytes;
    U8      *pixel_p, *img_p;

    U32     bmp_bpp;
    mycolor c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w = abm_enc->bmp_width;
    h = abm_enc->bmp_height;
    line_padding_bytes = abm_enc->line_padding_bytes;
    bmp_bpp = abm_enc->bmp_bpp;
    img_p = abm_enc->bmp_pixel_start_p;    

    /* initialize image bounding box */
    abm_enc->x1 = w;
    abm_enc->y1 = h;
    abm_enc->x2 = 0;
    abm_enc->y2 = 0;

    /* first pass: build color index table and find the image bounding box */
    pixel_p = img_p;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            /* read pixel */
            if (bmp_bpp == 32)
            {   /* 32-bit bitmap */
                c = GET_32(pixel_p);
                pixel_p += 4;
               
                /* Windows 32-bit BMP is always 0x00RRGGBB. */                    
                if (abm_enc->is_windows_bmp)
                {
                    c |= 0xFF000000;
                }

                if (abm_enc->src_key_color_enable && (c == TRANSPARENT_COLOR_32))
                {   /* transparent color, alpha = 0 */
                    c = 0;
                }                
            }
            else if (bmp_bpp == 24)
            {   /* 24-bit bitmap */
                c = GET_24(pixel_p);
                pixel_p += 3;

                if (abm_enc->src_key_color_enable && (c == TRANSPARENT_COLOR_24))
                {   /* transparent color, alpha = 0 */
                    c = 0;
                }
                else
                {   /* opaque color, alpha = 255 */                    
                    c |= 0xFF000000;
                }
            }
            else
            {   /* 8-bit bitmap */
                c = abm_enc->bmp_palette[*pixel_p++];                
            }

            /* add color if the color is not transparent color */
            if (A_OF_ARGB8888(c) != 0)
            {               
                /* only add unique color */
                add_color_if_new(COLOR_REDUCE(c));

                /* update image bounding box (notice bitmap is flipped, so we have to invert y here) */
                update_image_bounding_box(x, h - 1 - y);
            }
        }
        
        pixel_p += line_padding_bytes;
    }

    limit_image_bounding_box();
    
    /* handle special case, all transparent color */
    if (abm_enc->x2 < abm_enc->x1)
    {
        abm_enc->x1 = 0;
        abm_enc->y1 = 0;
        abm_enc->x2 = 0;
        abm_enc->y2 = 0;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  log2_ceiling
 * DESCRIPTION
 *  calculate ceiling(log2(x))
 * PARAMETERS
 *  x       [IN]    x must be in the range of [0, 65535]
 * RETURNS
 *  ceiling(log2(x))
 *****************************************************************************/
static U32 log2_ceiling(U32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 15; i++)
    {
        if (x <= log2_table[i])
            break;
    }

    return i + 1;
}


/*****************************************************************************
 * FUNCTION
 *  abmenc_encode
 * DESCRIPTION
 *  abm encoder main routine
 * PARAMETERS
 *  out_mem_p       [OUT] output memory pointer
 * RETURNS
 *  ABM data size
 *****************************************************************************/
static U32 abmenc_encode(U8* out_mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x, y, w, h, bottom_right_off_w, bottom_right_off_h;
    S32     bound_box_w, bound_box_h;
    S32     line_padding_bytes;
    U8      *pixel_p, *img_p, *mem8_p;
    U32     p;
    U32     bpp;
    U16     *mem16_p;
    S32     normal_color_num, alpha_color_num, color_num;
    S32     i;

    U32     abm_size;
    U32     bmp_bpp;
    mycolor c, color16;
    mycolor a, r, g, b;
    U32     bytes_per_pixel;

    U32     bitstream_padding_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w = abm_enc->bmp_width;
    h = abm_enc->bmp_height;   
    
    bmp_bpp = abm_enc->bmp_bpp;
    line_padding_bytes = abm_enc->line_padding_bytes;

    /* 1st pass, build the unique color index table */
    abmenc_build_color_index_table();

    /* out of ABM limit, return a large size to prevent choosing ABM */
    if (cit->color_num >= ABM_MAX_COLOR_NUM)
    {
        return 0xFFFFFFFF;
    }

    color_num = cit->color_num + 1;                 /* 1 for transparent color 0 */
    normal_color_num = get_normal_color_num() + 1;  /* 1 for transparent color 0 */
    alpha_color_num = color_num - normal_color_num;
    bpp = log2_ceiling(color_num);
    
    /* 
     * fill the ABM 12-byte header 
     */
    mem16_p = (U16*)out_mem_p;
    mem16_p[0] = w;    
    
    if (ABM_PALETTE_BPP == 16)
    {
        mem16_p[1] = h;
    }    
    else
    {
        mem16_p[1] = h | 0x8000;    /* bit 15 is 1 to indicate it's 24-bit palette. */
    }
    
    mem16_p[2] = normal_color_num;  /* number of normal colors */
    mem16_p[3] = alpha_color_num;   /* number of alpha colors */

    /* bounding box info header (width and height offsets, not bounding box coordinates) */
    mem16_p[4] = (abm_enc->y1 << 8) | abm_enc->x1;
    bottom_right_off_w = w - 1 - abm_enc->x2;
    bottom_right_off_h = h - 1 - abm_enc->y2;
    mem16_p[5] = (bottom_right_off_h << 8) | bottom_right_off_w;

    mem16_p += 6;    

    mem8_p = (U8*)mem16_p;

    /* output color palette */
    for (i = 0; i < color_num - 1; i++)
    {
        c = cit->color_table[i];

        a = A_OF_ARGB8888(c);

        /* prevent blue channel from saturation to get rid of source key checking in the decoder */
        if (ABM_PALETTE_BPP == 16)
        {   /* 16-bit */
            color16 = ARGB8888_TO_RGB16(c);
            if (B_OF_RGB16(color16) == 0x1F)
            {
                c -= 1 << 3;    /* 5-bit B: 0x1F -> 0x1E */
            }
        }
        else
        {   /* 24-bit and 32-bit ABM both use 24-bit palette */
            if (B_OF_ARGB8888(c) == 0xFF)
            {
                c -= 1;         /* 8-bit B: 0xFF -> 0xFE */
            }
        }

        /* pre-calculate alpha color */
        if (a != 255)
        {
            r = R_OF_ARGB8888(c);
            g = G_OF_ARGB8888(c);
            b = B_OF_ARGB8888(c);

            r = (r * a) / 256;
            g = (g * a) / 256;
            b = (b * a) / 256;

            c = RGB(r, g, b);
        }        

        if (ABM_PALETTE_BPP == 16)
        {   /* 16-bit palette */
            PUT_16(mem8_p, ARGB8888_TO_RGB16(c));
            mem8_p += 2;
        }
        else
        {   /* 24-bit palette */
            PUT_24(mem8_p, c);
            mem8_p += 3;
        }
    }

    /* output 1-byte alpha values of alpha colors */
    for (i = normal_color_num - 1; i < color_num - 1; i++)
    {
        /* inverted alpha due to precalculation */
        *mem8_p++ = 255 - A_OF_ARGB8888(cit->color_table[i]);
    }

    /* add a padding byte to meet 2-byte alignment for the bitstream */
    if ((U32)mem8_p & 1)
    {
        /* padding with 0xFF */
        *mem8_p++ = 0xFF;
        bitstream_padding_byte = 1;
    }
    else
    {
        bitstream_padding_byte = 0;
    }

    img_p = abm_enc->bmp_pixel_start_p;
    bytes_per_pixel = abm_enc->bmp_bpp / 8;

    /* calculate bounding box width and height */
    bound_box_w = abm_enc->x2 - abm_enc->x1 + 1;
    bound_box_h = abm_enc->y2 - abm_enc->y1 + 1;

    /* initialize the bitstream writer */
    BW_INIT((U16*)mem8_p);

    /* 2nd pass, output ABM packed pixels, and do vertical flipping (BMP nature) */
    for (y = abm_enc->y1; y <= abm_enc->y2; y++)
    {
        /* point pixel_p to the start of the line (notice the vertical flip) */
        pixel_p = img_p + (w * bytes_per_pixel + line_padding_bytes) * (h - 1 - y) + abm_enc->x1 * bytes_per_pixel;

        for (x = 0; x < bound_box_w; x++)
        {
            /* read pixel */
            if (bmp_bpp == 32)
            {   /* 32-bit bitmap */
                c = GET_32(pixel_p);
                pixel_p += 4;

                /* Windows 32-bit BMP is always 0x00RRGGBB. */                    
                if (abm_enc->is_windows_bmp)
                {
                    c |= 0xFF000000;
                }

                if (abm_enc->src_key_color_enable && (c == TRANSPARENT_COLOR_32))
                {   /* transparent color, alpha = 0 */
                    c = 0;
                }                
            }
            else if (bmp_bpp == 24)
            {   /* 24-bit bitmap */
                c = GET_24(pixel_p);
                pixel_p += 3;

                if (abm_enc->src_key_color_enable && (c == TRANSPARENT_COLOR_24))
                {   /* transparent color, alpha = 0 */
                    c = 0;
                }
                else
                {   /* opaque color, alpha = 255 */                    
                    c |= 0xFF000000;
                }
            }
            else
            {   /* 8-bit bitmap */
                c = abm_enc->bmp_palette[*pixel_p++];
            }

            /* search color from the color table */
            if (A_OF_ARGB8888(c) == 0)
            {   /* alpha = 0 -> transparent color, output directly without searching */
                p = 0;
            }
            else
            {   /* go search the color, the color WILL and MUST exist in the table */
                /* color 0 is reserved for transparent color, so +1 */
                p = search_color(COLOR_REDUCE(c)) + 1;
            }

            /* write the ABM pixel data into the bitstream */
            BW_WRITE(p, bpp);
        }
    }

    /* flush bitstream writer */
    BW_END();

    abm_size = ABM_HEADER_SIZE +                            /* header size */
               (color_num - 1) * ABM_PALETTE_BPP / 8 +      /* palette size */
               alpha_color_num +                            /* 8-bit alpha channel */
               bitstream_padding_byte +                     /* a padding byte or not */
               (bound_box_w * bound_box_h * bpp + 15) / 16 * 16 / 8;    /* pixel data size (2-byte align) */

    return abm_size;
}


/*****************************************************************************
 * FUNCTION
 *  ABM_load
 * DESCRIPTION
 *  ABM encoder interface
 * PARAMETERS
 *  in_bmp_filename       [IN]  input bitmap filename
 *  dev_bmp_bpp           [IN]  PBM color depth in bits
 *  image_type            [IN]  for decision whether to use ABM
 *  data                  [OUT] output memory
 *  size                  [OUT] size of ABM image
 *  width                 [OUT] width of ABM image
 *  height                [OUT] height of ABM image
 * RETURNS
 *  return code to use ABM or not
 *  + ABM_ENC_RETURN_KEEP_ORIGINAL  0   donot use ABM  
 *  + ABM_ENC_RETURN_USE_ABM        1   use ABM
 *****************************************************************************/
S32 ABM_load(
        U8  *in_bmp_filename,
        S32 dev_bmp_bpp,
        U8  image_type,
        U8  *data,
        S32 *size,
        S32 *width,
        S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE    *fp;

    U32     input_bmp_file_size;
    S32     pbm_size;
    S32     w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do not support bpps lower than 16-bit */
#if defined(DRV_MAINLCD_BIT_PER_PIXEL) && (DRV_MAINLCD_BIT_PER_PIXEL < 16)
    return ABM_ENC_RETURN_KEEP_ORIGINAL;
#endif
    
    /* initialize color index table and abm encoder context */
    cit->color_num = 0;
    memset(abm_enc, 0, sizeof(abm_enc_struct));

    /* enable source key color only for PBM and BMP */
    if ((image_type == IMAGE_TYPE_DEVICE_BITMAP) || (image_type == IMAGE_TYPE_BMP))
    {
       abm_enc->src_key_color_enable = 1;
    }

    /* It is necessary to identify PNG to BMP or originally BMP for 32-bit BMP files. */
    if (image_type != IMAGE_TYPE_PNG)
    {
       abm_enc->is_windows_bmp = 1;
    }

    /* open the input bitmap file */
    fp = fopen(in_bmp_filename, "rb");
    if (fp == NULL)
    {
        printf("[ABM enc] open file error: %s\n", in_bmp_filename);
        return ABM_ENC_RETURN_KEEP_ORIGINAL;
    }

    /* get the file size of the input BMP file */
    input_bmp_file_size = get_file_size(fp);

    /* make sure the file buffer size is enough */
    if (input_bmp_file_size > ABMENC_BMP_FILE_BUFFER_SIZE)
    {
        fclose(fp);

        printf("[ABM enc] over buffer size: %s\n", in_bmp_filename);
        return ABM_ENC_RETURN_KEEP_ORIGINAL;
    }

    /* read the whole file into the memory */
    if (fread(g_file_buf, input_bmp_file_size, 1, fp) != 1)
    {
        fclose(fp);
        
        printf("[ABM enc] read buffer error: %s\n", in_bmp_filename);
        return ABM_ENC_RETURN_KEEP_ORIGINAL;
    }

    /* parse bitmap header */
    if (parse_bitmap(g_file_buf, input_bmp_file_size) == ABM_ENC_INPUT_BITMAP_ERROR)
    {
        fclose(fp);

        printf("[ABM enc] parse BMP error, %s\n", in_bmp_filename);
        return ABM_ENC_RETURN_KEEP_ORIGINAL;
    }

    fclose(fp);

    /* ABM encode */
    *size = abmenc_encode(data);

    /* return width and height */
    w = abm_enc->bmp_width;
    h = abm_enc->bmp_height;
    *width = w;
    *height = h;

    /* calculate PBM size */
    pbm_size = PBM_HEADER_SIZE +        /* PBM header */
               w * h * dev_bmp_bpp / 8; /* PBM pixel data */
           
    /* choose ABM if the ABM size is smaller */
    switch (image_type)
    {
        case IMAGE_TYPE_PNG:
            return ABM_ENC_RETURN_USE_ABM;
            break;

        case IMAGE_TYPE_BMP:
            if (*size <= input_bmp_file_size)
            {
                return ABM_ENC_RETURN_USE_ABM;
            }        
            break;
            
        case IMAGE_TYPE_DEVICE_BITMAP:
            if (*size <= pbm_size)
            {
                return ABM_ENC_RETURN_USE_ABM;
            }
            break;           
            
        default:           
            break;
    }

    return ABM_ENC_RETURN_KEEP_ORIGINAL;
}


/* 
 * RESOURCE GENERATOR ONLY FUNCTIONS
 */
#if defined(__RESOURCE_GEN_)

#ifdef ABM_ENC_UNIT_TEST
#include <time.h>
/* 
 * unit test for abm encoder
 *
 * return 0: successful, otherwise: failed
 */
S32 abmenc_unit_test(void)
{
    S32 si, i;

    cit->color_num = 0;
    srand((unsigned)time(NULL));

    si = search_color(ARGB(255, 255, 255, 255));
    add_color_if_new(ARGB(255, 255, 255, 255));
    si = search_color(ARGB(255, 255, 255, 255));
    add_color_if_new(ARGB(255, 255, 255, 254));
    si = search_color(ARGB(255, 255, 255, 0));
    add_color_if_new(ARGB(0, 255, 255, 254));
    si = search_color(ARGB(255, 255, 255, 254));

    for (i = 0; i < 1000; i++)
    {
        add_color_if_new(rand());
    }

    /* make sure the color table is descending */        
    for (i = 0; i < cit->color_num - 1; i++)
    {        
        if (cit->color_table[i + 1] > cit->color_table[i])
        {
            return ABMENC_UNIT_TEST_FAILED;
        }
    }

    return ABMENC_UNIT_TEST_SUCCESSFUL;
}
#endif /* ABM_ENC_UNIT_TEST */


/*****************************************************************************
 * FUNCTION
 *  ABMLoader
 * DESCRIPTION
 *  ABM loader
 * PARAMETERS
 *  in_filename     [IN] input filename
 *  out_filename    [IN] output filename
 * RETURNS
 *  return value
 *****************************************************************************/
S32 ABMLoader(U8 *in_filename, U8 *out_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffer[ABMENC_BMP_FILE_BUFFER_SIZE];
    S32 width, height, size, ret, i;
    U32 width_height;
    FILE *outfile;
    U8 image_type = 0;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* temp solution:
     * check whether the input file is PBM */
    {
        int l;
        
        l = strlen(in_filename);
        if ((in_filename[l - 1] == 'M') &&
            (in_filename[l - 2] == 'B') &&
            (in_filename[l - 3] == 'P'))
        { 
            image_type = IMAGE_TYPE_DEVICE_BITMAP;
        }
        else if ((in_filename[l - 1] == 'P') &&
                 (in_filename[l - 2] == 'M') &&
                 (in_filename[l - 3] == 'B'))
        {
            image_type = IMAGE_TYPE_BMP;
        }
        else if ((in_filename[l - 1] == 'A') &&
                 (in_filename[l - 2] == 'P') &&
                 (in_filename[l - 3] == 'M') &&
                 (in_filename[l - 4] == 'B'))
        {
            image_type = IMAGE_TYPE_PNG;
        }
    }

    ret = ABM_load(
            in_filename,
            __MMI_DEVICE_BMP_FORMAT__,
            image_type,
            buffer,
            &size,
            &width,
            &height);

    switch(ret)
    {
        case ABM_ENC_RETURN_USE_ABM:
            break;

        case ABM_ENC_RETURN_KEEP_ORIGINAL:
        case ABMENC_COLOR_NOT_FOUND:
        case ABM_ENC_INPUT_BITMAP_ERROR:
        default:
            return ret;
    }

    if ((size >> 24) > 0)
    {
        printf("image is too big:%s\n", in_filename);
    }
    g_ressize = size + 8;
    width_height = (((U32)width & 0XFFF) << 12) | ((U32)height & 0XFFF);

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    enfb_ret = Image_Test(in_filename, &enfb_width, &enfb_height);
    if (enfb_ret != ENFB_IMAGE_NONE)
    {
        enfbFlag = 1;
        if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
        {
            ENFBAssociatedIDAdded = MMI_TRUE;
        }
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* open output file */
    outfile = fopen(out_filename, "wb+");
    if (outfile == NULL)
    {
        printf("\nError creating %s", out_filename);
        return 0;
    }

    /* write to CustPack */
    if (toolFlag == 1)
    {
        /* resource header */
        fprintf(dest_file, "%c", IMAGE_TYPE_ABM);
        fprintf(dest_file, "%c", 0x01);
        fprintf(dest_file, "%c%c%c",
                (size & 0x000000ff),
                (size & 0x0000ff00) >> 8,
                (size & 0x00ff0000) >> 16);
        fprintf(dest_file, "%c%c%c",
                (width_height & 0x000000ff),
                (width_height & 0x0000ff00) >> 8,
                (width_height & 0x00ff0000) >> 16);

        /* ABM raw data */
        for (i = 0; i < size; i++)
        {
            fprintf(dest_file, "%c", buffer[i]);
        }
    }
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* write ENFB header to CustImgDataxxx.h and
     * image header/data to ENFB image data file */
    else if (enfbFlag == 1) 
    {
        enfb_size = 8 + size;
        
        /* write ENFB header to CustImgDataxxx.h */
        fprintf(outfile,
                "\n{\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t};\n",
                (U8) 255,                       //type
                (U8) ENFBAssociatedIDAdded,     //associated id
                (U8) 0,                         //reserved
                (U8) 0,                         //reserved
                (U8) (enfb_offset & 0xff),
                (U8) ((enfb_offset >> 8) & 0xff),
                (U8) ((enfb_offset >> 16) & 0xff),
                (U8) ((enfb_offset >> 24) & 0xff),
                (U8) (enfb_size & 0xff),
                (U8) ((enfb_size >> 8) & 0xff),
                (U8) ((enfb_size >> 16) & 0xff),
                (U8) ((enfb_size >> 24) & 0xff));
        
        /* image header/data to ENFB image data file */
        /* resource header */
        fprintf(enfb_img_data_file, "%c", IMAGE_TYPE_ABM);
        fprintf(enfb_img_data_file, "%c", 0x01);
        fprintf(enfb_img_data_file,
                "%c%c%c",
                (size & 0x000000ff),
                (size & 0x0000ff00) >> 8,
                (size & 0x00ff0000) >> 16);
        fprintf(enfb_img_data_file,
                "%c%c%c",
                (width_height & 0x000000ff),
                (width_height & 0x0000ff00) >> 8,
                (width_height & 0x00ff0000) >> 16);

        for (i = 0; i < size; i++)
        {
            fprintf(enfb_img_data_file, "%c", buffer[i]);
        }

        enfb_offset += enfb_size;
        enfbFlag = 0;
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    else
    {
        fprintf(outfile, "{\n\t");

        /* resource header */
        fprintf(outfile, "0x%02X, ", IMAGE_TYPE_ABM);
        fprintf(outfile, "0x%02X, ", 0x01);
        fprintf(outfile,
                "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,",
                (size & 0x000000ff),
                (size & 0x0000ff00) >> 8,
                (size & 0x00ff0000) >> 16,
                (width_height & 0x000000ff),
                (width_height & 0x0000ff00) >> 8,
                (width_height & 0x00ff0000) >> 16);

        for (i = 0; i < size; i++)
        {
            if ((i % 16) == 0)
            {
                fprintf(outfile, "\n\t");
            }
            fprintf(outfile, "0x%02X, ", buffer[i]);
        }
        fprintf(outfile, "\n};");
    }

    fclose(outfile);

    return ABM_ENC_RETURN_USE_ABM;
}

#endif /* defined(__RESOURCE_GEN_) */

#else /* !defined(__MTK_TARGET__) || defined(__RESOURCE_GEN_) */

/* avoid the target compilation warning */
char g_abm_loader_avoid_warning;

#endif /* !defined(__MTK_TARGET__) || defined(__RESOURCE_GEN_) */


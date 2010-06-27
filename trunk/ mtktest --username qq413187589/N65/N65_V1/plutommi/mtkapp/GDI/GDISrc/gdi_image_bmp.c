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
 *  gdi_image_bmp.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Bitmap related.
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
#include "drm_gprot.h"

//Enable this compile option will expand to lots of deocder for each color format.
//It will increase the performance, but use 2 ~ 4 times code size
#undef OPTIMIZE_COLOR_FORMAT_OUTPUT

#if defined(__MTK_TARGET__)
#pragma Otime
#pragma no_check_stack
#endif /* defined(__MTK_TARGET__) */ 
/****************************************************************************
* Struct
*****************************************************************************/

typedef struct
{
    U16 bfType;
    U32 bfSize;
    U16 bfReserved1;
    U16 bfReserved2;
    U32 bfOffBits;
} bitmap_file_header;

typedef struct
{
    U32 biSize;
    U32 biWidth;
    U32 biHeight;
    U16 biPlanes;
    U16 biBitCount;
    U32 biCompression;
    U32 biSizeImage;
    U32 biXPelsPerMeter;
    U32 biYPelsPerMeter;
    U32 biClrUsed;
    U32 biClrImportant;
} bitmap_info_header;

typedef struct
{
    U32 biSize;
    U16 biWidth;
    U16 biHeight;
    U16 biPlanes;
    U16 biBitCount;
} bitmap_core_header;

#define GDI_BI_RGB  0
#define GDI_BI_RLE8  1
#define GDI_BI_RLE4  2
#define GDI_BI_BITFIELDS  3

static BOOL gdi_image_bmp_compression;
static S32 gdi_image_bmp_width;
static S32 gdi_image_bmp_height;
static S32 gdi_image_bmp_src_x;
static S32 gdi_image_bmp_src_y;
static S32 gdi_image_bmp_run_length;
static S32 gdi_image_bmp_run_length_used;
static U8 gdi_image_bmp_code;
////////////////////////////////////////////////////////////////////////////////////////////
/// BMP file internal decoder
////////////////////////////////////////////////////////////////////////////////////////////
#undef INIT_SRC
#undef GET_U8
#undef GET_U16
#undef GET_U24
#undef GET_U32
#undef FLUSH
#undef SEEK
#undef IS_FROM_FILE
#undef GDI_IMAGE_BMP_DRAW_INTERNAL
#undef GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL
#undef COMPRESSION_MODE

#define SUPPORT_BMP_COMPRESSION



#define GET_U8(SRC,X)                        GDI_BYTESTREAM_GET_BYTE_FILE(X)
#define FLUSH(SRC,X)                         GDI_BYTESTREAM_FLUSH_FILE(X)
#define GET_U16(SRC,X)                       GDI_BYTESTREAM_GET_WORD_FILE(X)
#define GET_U24(SRC,X)                       GDI_BYTESTREAM_GET_3BYTES_FILE(X)
#define GET_U32(SRC,X)                       GDI_BYTESTREAM_GET_DWORD_FILE(X)

#define IS_FROM_FILE                1
#define INIT_SRC(SRC,INPUT)
#define SEEK(SRC,BMP_SRC,OFFSET)             gdi_bytestream_seek_file(OFFSET)

//////////////////////////////////
//// GENERAL FILE RESIZER DECODER
/////////////////////////////////
#define GET_U8_FROM_RUN_LENGTH                  gdi_image_bmp_get_u8_rle_from_file
#define GDI_IMAGE_BMP_DRAW_INTERNAL             gdi_image_bmp_draw_internal_from_file
#define GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL    gdi_image_bmp_get_dimension_internal_from_file
#define GDI_IMAGE_BMP_USING_RESIZER
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_USING_RESIZER
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
#undef  GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL
#undef  GET_U8_FROM_RUN_LENGTH


#ifdef OPTIMIZE_COLOR_FORMAT_OUTPUT
//////////////////////////////////
//// COLOR_FORMAT  FILE NON_RESIZER DECODER
/////////////////////////////////
#undef  GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL    /* we don't need get_dimension for each color format */

#if GDI_MAINLCD_BIT_PER_PIXEL == 1 || !defined(GDI_USING_LAYER)
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_MAINLCD
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_file_main
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
#define gdi_image_bmp_draw_internal_from_file_main gdi_image_bmp_draw_internal_from_file_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
#define gdi_image_bmp_draw_internal_from_file_main gdi_image_bmp_draw_internal_from_file_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
#define gdi_image_bmp_draw_internal_from_file_main gdi_image_bmp_draw_internal_from_file_32
#endif 

#ifdef __MMI_SUBLCD__
#if GDI_SUBLCD_BIT_PER_PIXEL == 1 || !defined(GDI_USING_LAYER)
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_SUBLCD
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_file_sub
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
#elif GDI_SUBLCD_BIT_PER_PIXEL == 16
#define gdi_image_bmp_draw_internal_from_file_sub  gdi_image_bmp_draw_internal_from_file_16
#elif GDI_SUBLCD_BIT_PER_PIXEL == 24
#define gdi_image_bmp_draw_internal_from_file_sub  gdi_image_bmp_draw_internal_from_file_24
#elif GDI_SUBLCD_BIT_PER_PIXEL == 32
#define gdi_image_bmp_draw_internal_from_file_sub  gdi_image_bmp_draw_internal_from_file_32
#endif 
#endif /* __MMI_SUBLCD__ */ 

// we must provide each color format decoder
// color format 8 bit
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_8
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_file_8
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL

/* color format 16 bit */
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_16
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_file_16
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL

/* color format 24 bit */
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_24
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_file_24
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
/* color format 32 bit */
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_32
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_file_32
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
#endif
////////////////////////////////////////////////////////////////////////////////////////////
/// BMP mem internal decoder
////////////////////////////////////////////////////////////////////////////////////////////

#undef INIT_SRC
#undef GET_U8
#undef GET_U16
#undef GET_U24
#undef GET_U32
#undef FLUSH
#undef SEEK
#undef IS_FROM_FILE
#undef GDI_IMAGE_BMP_DRAW_INTERNAL
#undef GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL
#undef COMPRESSION_MODE

/* source from memory, will not support compression mode, because we need speed up decode time. */
//#undef SUPPORT_BMP_COMPRESSION
#define INIT_SRC(SRC,INPUT)   SRC = INPUT;

#define GET_U8(SRC,X)     \
   {                      \
      X =   ((U8) *SRC++);\
   }

#define GET_U16(SRC,X)         \
   {                           \
      X =   ((U16) (U8)*SRC++);\
      X |=((U16) *SRC++)<<8;   \
   }
#define GET_U24(SRC,X)           \
   {                             \
      X =   ((U32) (U8)*SRC++);  \
      X |=((U32) (U8)*SRC++)<<8; \
      X |=((U32) (U8)*SRC++)<<16;\
   }

#define GET_U32(SRC,X)           \
   {                             \
      X =   ((U32) (U8)*SRC++);  \
      X |=((U32) (U8)*SRC++)<<8; \
      X |=((U32) (U8)*SRC++)<<16;\
      X |=((U32) (U8)*SRC++)<<24;\
   }

//////////////////////////////////
//// GENERAL MEM RESIZER DECODER
/////////////////////////////////

#define IS_FROM_FILE                0
#define FLUSH(SRC,X)                SRC+=X
#define SEEK(SRC,BMP_SRC,OFFSET)    SRC = BMP_SRC+OFFSET
#define GET_U8_FROM_RUN_LENGTH                  gdi_image_bmp_get_u8_rle_from_mem
#define GDI_IMAGE_BMP_DRAW_INTERNAL             gdi_image_bmp_draw_internal_from_mem
#define GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL gdi_image_bmp_get_dimension
#define GDI_IMAGE_BMP_USING_RESIZER
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_USING_RESIZER
#undef GDI_IMAGE_BMP_DRAW_INTERNAL
#undef GDI_IMAGE_BMP_GET_DIMENSION_INTERNAL
#undef GET_U8_FROM_RUN_LENGTH

#if defined(__MTK_TARGET__)
#pragma arm section code = "INTERNCODE"
#endif 

#ifdef OPTIMIZE_COLOR_FORMAT_OUTPUT
//////////////////////////////////
//// COLOR_FORMAT  MEM NON_RESIZER DECODER
/////////////////////////////////

#if GDI_MAINLCD_BIT_PER_PIXEL == 1 || !defined(GDI_USING_LAYER)
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_MAINLCD
#define GDI_IMAGE_BMP_DRAW_INTERNAL             gdi_image_bmp_draw_internal_from_mem_main
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
#define gdi_image_bmp_draw_internal_from_mem_main  gdi_image_bmp_draw_internal_from_mem_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
#define gdi_image_bmp_draw_internal_from_mem_main  gdi_image_bmp_draw_internal_from_mem_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
#define gdi_image_bmp_draw_internal_from_mem_main  gdi_image_bmp_draw_internal_from_mem_32
#endif 

#ifdef __MMI_SUBLCD__
#if GDI_SUBLCD_BIT_PER_PIXEL == 1 || !defined(GDI_USING_LAYER)
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_SUBLCD
#define GDI_IMAGE_BMP_DRAW_INTERNAL             gdi_image_bmp_draw_internal_from_mem_sub
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
#elif GDI_SUBLCD_BIT_PER_PIXEL == 16
#define gdi_image_bmp_draw_internal_from_mem_sub   gdi_image_bmp_draw_internal_from_mem_16
#elif GDI_SUBLCD_BIT_PER_PIXEL == 24
#define gdi_image_bmp_draw_internal_from_mem_sub   gdi_image_bmp_draw_internal_from_mem_24
#elif GDI_SUBLCD_BIT_PER_PIXEL == 32
#define gdi_image_bmp_draw_internal_from_mem_sub   gdi_image_bmp_draw_internal_from_mem_32
#endif 
#endif /* __MMI_SUBLCD__ */ 

// we must provide each color format decoder
// color format 8 bit
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_8
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_mem_8
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL

/* color format 16 bit */
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_16
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_mem_16
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL

/* color format 24 bit */
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_24
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_mem_24
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL
/* color format 32 bit */
#define GDI_IMAGE_BMP_CODEC_COLOR_FORMAT        GDI_COLOR_FORMAT_32
#define GDI_IMAGE_BMP_DRAW_INTERNAL          gdi_image_bmp_draw_internal_from_mem_32
#include "gdi_image_bmp_codec.h"
#undef GDI_IMAGE_BMP_CODEC_COLOR_FORMAT
#undef  GDI_IMAGE_BMP_DRAW_INTERNAL

#if defined(__MTK_TARGET__)
#pragma arm section code
#endif 

typedef GDI_RESULT(*gdi_image_bmp_draw_func) (S32 offset_x, S32 offset_y,
                                              BOOL is_resized, S32 resized_width, S32 resized_height,
                                              U8 *BMP_src, U32 size);

/* / Reduce the code size */
#if !defined(GDI_USING_LAYER_COLOR_FORMAT)
#if GDI_MAINLCD_BIT_PER_PIXEL != 8 && GDI_SUBLCD_BIT_PER_PIXEL != 8
#define gdi_image_bmp_draw_internal_from_mem_8  (gdi_image_bmp_draw_func)gd_null_pointer_function
#define gdi_image_bmp_draw_internal_from_file_8 (gdi_image_bmp_draw_func)gd_null_pointer_function
#endif /* GDI_MAINLCD_BIT_PER_PIXEL != 8 && GDI_SUBLCD_BIT_PER_PIXEL != 8 */ 
#if GDI_MAINLCD_BIT_PER_PIXEL != 16 && GDI_SUBLCD_BIT_PER_PIXEL != 16
#define gdi_image_bmp_draw_internal_from_mem_16 (gdi_image_bmp_draw_func)gd_null_pointer_function
#define gdi_image_bmp_draw_internal_from_file_16   (gdi_image_bmp_draw_func)gd_null_pointer_function
#endif /* GDI_MAINLCD_BIT_PER_PIXEL != 16 && GDI_SUBLCD_BIT_PER_PIXEL != 16 */ 
#if GDI_MAINLCD_BIT_PER_PIXEL != 24 && GDI_SUBLCD_BIT_PER_PIXEL != 24
#define gdi_image_bmp_draw_internal_from_mem_24 (gdi_image_bmp_draw_func)gd_null_pointer_function
#define gdi_image_bmp_draw_internal_from_file_24   (gdi_image_bmp_draw_func)gd_null_pointer_function
#endif /* GDI_MAINLCD_BIT_PER_PIXEL != 24 && GDI_SUBLCD_BIT_PER_PIXEL != 24 */ 
#if GDI_MAINLCD_BIT_PER_PIXEL != 32 && GDI_SUBLCD_BIT_PER_PIXEL != 32
#define gdi_image_bmp_draw_internal_from_mem_32 (gdi_image_bmp_draw_func)gd_null_pointer_function
#define gdi_image_bmp_draw_internal_from_file_32   (gdi_image_bmp_draw_func)gd_null_pointer_function
#endif /* GDI_MAINLCD_BIT_PER_PIXEL != 32 && GDI_SUBLCD_BIT_PER_PIXEL != 32 */ 
#endif /* !defined(GDI_USING_LAYER_COLOR_FORMAT) */ 

/* decoder table */
const static gdi_image_bmp_draw_func gdi_image_bmp_draw_mem_decoders[] = 
{
    (gdi_image_bmp_draw_func) gd_null_pointer_function, /* 1 */
    gdi_image_bmp_draw_internal_from_mem_8,             /* 8 */
    gdi_image_bmp_draw_internal_from_mem_16,            /* 16 */
    gdi_image_bmp_draw_internal_from_mem_24,            /* 24 */
    gdi_image_bmp_draw_internal_from_mem_32,            /* 32 */
    gdi_image_bmp_draw_internal_from_mem_main,          /* main */
#ifdef __MMI_SUBLCD__
    gdi_image_bmp_draw_internal_from_mem_sub
#else 
    (gdi_image_bmp_draw_func) gd_null_pointer_function, /* sub */
#endif 
};

const static gdi_image_bmp_draw_func gdi_image_bmp_draw_file_decoders[] = 
{
    (gdi_image_bmp_draw_func) gd_null_pointer_function, /* 1 */
    gdi_image_bmp_draw_internal_from_file_8,            /* 8 */
    gdi_image_bmp_draw_internal_from_file_16,           /* 16 */
    gdi_image_bmp_draw_internal_from_file_24,           /* 24 */
    gdi_image_bmp_draw_internal_from_file_32,           /* 32 */
    gdi_image_bmp_draw_internal_from_file_main,         /* main */
#ifdef __MMI_SUBLCD__
    gdi_image_bmp_draw_internal_from_file_sub
#else 
    (gdi_image_bmp_draw_func) gd_null_pointer_function, /* sub */
#endif 
};

#endif
/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw
 * DESCRIPTION
 *  draw bmp from memory
 * PARAMETERS
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  BMP_src         [IN]        
 *  size            [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_draw(S32 offset_x, S32 offset_y, U8 *BMP_src, U32 size)
{
    GDI_RESULT ret;
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_draw)
    {
        GDI_TRY
        {
            #ifdef OPTIMIZE_COLOR_FORMAT_OUTPUT
            ret = gdi_image_bmp_draw_mem_decoders[gdi_act_layer->cf] (offset_x, offset_y, FALSE, 0, 0, BMP_src, size);
            #else
            ret = gdi_image_bmp_draw_internal_from_mem               (offset_x, offset_y, FALSE, 0, 0, BMP_src, size);
            #endif
        }
        GDI_CATCH_BEGIN
        {
            ret = GDI_FAILED;

            GDI_CATCH(GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP)
            {
                ret = GDI_SUCCEED;
            }
        }
        GDI_CATCH_END
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_draw)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_file
 * DESCRIPTION
 *  draw bmp from file
 * PARAMETERS
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  filename        [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_draw_file(S32 offset_x, S32 offset_y, S8 *filename)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_draw_file)
    GDI_RESULT ret;

    if (filename == NULL || gdi_bytestream_create_file((PS8) filename) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        #ifdef OPTIMIZE_COLOR_FORMAT_OUTPUT
        ret = gdi_image_bmp_draw_file_decoders[gdi_act_layer->cf] (offset_x, offset_y, FALSE, 0, 0, (U8*) filename, 0);
        #else
        ret = gdi_image_bmp_draw_internal_from_file               (offset_x, offset_y, FALSE, 0, 0, (U8*) filename, 0);       
        #endif
    }
    GDI_CATCH_BEGIN
    {
        ret = GDI_FAILED;
        
        GDI_CATCH(GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP)
        {
            ret = GDI_SUCCEED;
        }
    }
    GDI_CATCH_END
    gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_draw_file)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_resized
 * DESCRIPTION
 *  draw resized bmp from memory
 * PARAMETERS
 *  offset_x            [IN]        
 *  offset_y            [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  BMP_src             [IN]        
 *  size                [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_draw_resized(
            S32 offset_x,
            S32 offset_y,
            S32 resized_width,
            S32 resized_height,
            U8 *BMP_src,
            U32 size)
{
    GDI_RESULT ret;
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_draw_resized)
    {
        GDI_TRY
        {
            ret = gdi_image_bmp_draw_internal_from_mem(
                                                offset_x,
                                                offset_y,
                                                TRUE,
                                                resized_width,
                                                resized_height,
                                                BMP_src,
                                                size);
        }
        GDI_CATCH_BEGIN
        {
            ret = GDI_FAILED;
            
            GDI_CATCH(GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP)
            {
                ret = GDI_SUCCEED;
            }
        }
        GDI_CATCH_END
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_draw_resized)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_resized_file
 * DESCRIPTION
 *  draw resized bmp from file
 * PARAMETERS
 *  offset_x            [IN]        
 *  offset_y            [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  filename            [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_draw_resized_file(
            S32 offset_x,
            S32 offset_y,
            S32 resized_width,
            S32 resized_height,
            S8 *filename)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_draw_resized_file)
    GDI_RESULT ret;

    if (filename == NULL || gdi_bytestream_create_file((PS8) filename) != GDI_SUCCEED)
    {
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_bmp_draw_internal_from_file(
                offset_x,
                offset_y,
                TRUE,
                resized_width,
                resized_height,
                (U8*) filename,
                0);
    }
    GDI_CATCH_BEGIN
    {
        ret = GDI_FAILED;
        GDI_CATCH(GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP)
        {
            ret = GDI_SUCCEED;
        }

    }
    GDI_CATCH_END
    gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_draw_resized_file)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_get_dimension_file
 * DESCRIPTION
 *  get dimension of a bmp from file
 * PARAMETERS
 *  filename        [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_get_dimension_file(S8 *filename, S32 *width, S32 *height)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_bmp_get_dimension_file)
    GDI_RESULT ret;

    if (filename == NULL || gdi_bytestream_create_file((PS8) filename) != GDI_SUCCEED)
    {
        *width = *height = 0;
        GDI_RETURN(GDI_FAILED);
    }

    GDI_TRY
    {
        ret = gdi_image_bmp_get_dimension_internal_from_file((U8*) filename, width, height);
    }
    GDI_CATCH_BEGIN
    {
        *width = *height = 0;
        ret = GDI_FAILED;
    }
    GDI_CATCH_END 
    gdi_bytestream_free();

    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_bmp_get_dimension_file)
}

/****************************************************************************
* Cache Bitmap
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gdi_image_cache_bmp_get
 * DESCRIPTION
 *  cache a region from a layer
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 *  bmp_ptr     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_cache_bmp_get(S32 x1, S32 y1, S32 x2, S32 y2, gdi_image_cache_bmp_struct *bmp_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_cache_bmp_get)
    S32 i;
    S32 layer_width;
    S32 layer_height;
    S32 layer_clip_x1;
    S32 layer_clip_x2;
    S32 layer_clip_y1;
    S32 layer_clip_y2;
    S32 start_x, end_x, start_y, end_y;
    U8 *layer_buf_ptr;
    U8 *bmp_data_ptr;
    S32 byte_per_row;

    /* get src and dest buffer ptr */
    bmp_data_ptr = bmp_ptr->buf_ptr;            /* dest */
    gdi_layer_get_buffer_ptr(&layer_buf_ptr);   /* src */

    gdi_layer_get_clip(&layer_clip_x1, &layer_clip_y1, &layer_clip_x2, &layer_clip_y2);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    /* out of clip region */
    if ((x1 > layer_clip_x2) || (y1 > layer_clip_y2) || (x2 < layer_clip_x1) || (y2 < layer_clip_y1))
    {
        bmp_ptr->width = 0;
        bmp_ptr->height = 0;
        GDI_RETURN(GDI_SUCCEED);
    }

    /* Calculate valid region */
    if (x1 < layer_clip_x1)
    {
        start_x = layer_clip_x1;
    }
    else
    {
        start_x = x1;
    }

    if (x2 > layer_clip_x2)
    {
        end_x = layer_clip_x2;
    }
    else
    {
        end_x = x2;
    }

    if (y1 < layer_clip_y1)
    {
        start_y = layer_clip_y1;
    }
    else
    {
        start_y = y1;
    }

    if (y2 > layer_clip_y2)
    {
        end_y = layer_clip_y2;
    }
    else
    {
        end_y = y2;
    }

    /* fill bitmap info */
    bmp_ptr->width = end_x - start_x + 1;
    bmp_ptr->height = end_y - start_y + 1;

    byte_per_row = (bmp_ptr->width * GDI_LAYER.bits_per_pixel) >> 3;

    /* find source buffer start position of the active layer */
    layer_buf_ptr += ((start_y * layer_width + start_x) * GDI_LAYER.bits_per_pixel) >> 3;       /* 16-bit */

    /* fill bitmap buffer */
    for (i = 0; i < bmp_ptr->height; i++)
    {
        memcpy(bmp_data_ptr, layer_buf_ptr, byte_per_row);

        bmp_data_ptr += byte_per_row;
        layer_buf_ptr += (layer_width * GDI_LAYER.bits_per_pixel) >> 3; /* just to next row */
    }

    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_cache_bmp_get)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_cache_bmp_draw
 * DESCRIPTION
 *  draw cached image to a layer
 * PARAMETERS
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  bmp_ptr         [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_cache_bmp_draw(S32 offset_x, S32 offset_y, gdi_image_cache_bmp_struct *bmp_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_cache_bmp_draw)
    S32 i;
    S32 layer_width;
    S32 layer_height;
    S32 layer_clip_x1;
    S32 layer_clip_x2;
    S32 layer_clip_y1;
    S32 layer_clip_y2;
    S32 start_x, end_x, start_y, end_y;
    U8 *layer_buf_ptr;
    U8 *bmp_data_ptr;
    S32 x1, y1, x2, y2;
    S32 vlaid_width;
    S32 byte_per_row;

    /* get src and dest buffer ptr */
    bmp_data_ptr = bmp_ptr->buf_ptr;            /* src */
    gdi_layer_get_buffer_ptr(&layer_buf_ptr);   /* dest */

    byte_per_row = (bmp_ptr->width * GDI_LAYER.bits_per_pixel) >> 3;

    gdi_layer_get_clip(&layer_clip_x1, &layer_clip_y1, &layer_clip_x2, &layer_clip_y2);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    x1 = offset_x;
    y1 = offset_y;

    x2 = x1 + bmp_ptr->width - 1;
    y2 = y1 + bmp_ptr->height - 1;

    /* out of clip region */
    if ((x1 > layer_clip_x2) || (y1 > layer_clip_y2) || (x2 < layer_clip_x1) || (y2 < layer_clip_y1))
    {
        GDI_RETURN(GDI_SUCCEED);
    }

    /* Calculate valid region */
    if (x1 < layer_clip_x1)
    {
        start_x = layer_clip_x1;
    }
    else
    {
        start_x = x1;
    }

    if (x2 > layer_clip_x2)
    {
        end_x = layer_clip_x2;
    }
    else
    {
        end_x = x2;
    }

    if (y1 < layer_clip_y1)
    {
        start_y = layer_clip_y1;
    }
    else
    {
        start_y = y1;
    }

    if (y2 > layer_clip_y2)
    {
        end_y = layer_clip_y2;
    }
    else
    {
        end_y = y2;
    }

    /* find update width */
    vlaid_width = end_x - start_x + 1;

    /* shift to bmp buffer start position */
    bmp_data_ptr += (start_y - y1) * byte_per_row + (start_x - x1);

    /* shift to layer buffer start position */
    layer_buf_ptr += ((start_y * layer_width + start_x) * GDI_LAYER.bits_per_pixel) >> 3;

    /* fill bitmap buffer */
    for (i = start_y; i <= end_y; i++)
    {
        memcpy(layer_buf_ptr, bmp_data_ptr, (vlaid_width * GDI_LAYER.bits_per_pixel) >> 3);
        bmp_data_ptr += byte_per_row;
        layer_buf_ptr += (layer_width * GDI_LAYER.bits_per_pixel) >> 3;
    }

    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_cache_bmp_draw)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_draw_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  frame_pos       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        if (w && h)
        {
            return gdi_image_bmp_draw_resized_file(x, y, w, h, (S8*) data_ptr);
        }
        else
        {
            return gdi_image_bmp_draw_file(x, y, (S8*) data_ptr);
        }
    }
    else
    {
        if (w && h)
        {
            return gdi_image_bmp_draw_resized(x, y, w, h, data_ptr, img_size);
        }
        else
        {
            return gdi_image_bmp_draw(x, y, data_ptr, img_size);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_bmp_get_dimension_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 *  width           [?]         
 *  height          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_bmp_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_bmp_get_dimension_file((S8*) data_ptr, width, height);
    }
    else
    {
        return gdi_image_bmp_get_dimension(data_ptr, width, height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_bmp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_image_is_bmp_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    U8 buf[2];
    U32 len;
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f = gdi_lfs_open(gdi_lfs_handle,(U16*) file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, 0);
    if (f < 0) return FALSE;
    f = gdi_lfs_handle;

    result = gdi_lfs_read(f, buf, 2, &len);

    gdi_lfs_close(f);

    if (result == FS_NO_ERROR)
        if (len == 2)
            if (buf[0] == 'B' && buf[1] == 'M')
            {
                return TRUE;
            }
    return FALSE;
}


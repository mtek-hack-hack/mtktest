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
 *  gdi_const.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI const header file.
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
#ifndef _GDI_CONST_H_
#define _GDI_CONST_H_

typedef enum
{
    GDI_GRADIENT_RECT_HOR = 0,
    GDI_GRADIENT_RECT_VER,
    GDI_GRADIENT_RECT_DIA,
    GDI_GRADIENT_RECT_DIA_INV,
    GDI_GRADIENT_RECT_FLIP
} gdi_gradient_rect_style_enum;

typedef enum
{
    GDI_LCD_TYPE_NULL = 0,
    GDI_LCD_TYPE_LCD,
    GDI_LCD_TYPE_TVOUT
} gdi_lcd_type_enum;

typedef enum
{
    GDI_ANIM_POS_TYPE_INDEX,
    GDI_ANIM_POS_TYPE_TIME
} gdi_anim_pos_type_enum;

/* Image Codec flag */
typedef enum
{
    GDI_IMAGE_CODEC_FLAG_DISABLE_SRC_KEY        =   (1<<0),
    GDI_IMAGE_CODEC_FLAG_IS_FILE                =   (1<<1),
    GDI_IMAGE_CODEC_FLAG_IS_MEM                 =   (1<<2),
    GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_BEFORE    =   (1<<3),
    GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW           =   (1<<4),
    GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_AFTER     =   (1<<5),
    GDI_IMAGE_CODEC_FLAG_DISABLE_BLT            =   (1<<6),
    GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE          =   (1<<7),
    GDI_IMAGE_CODEC_FLAG_DRAW_ONCE              =   (1<<8),
    GDI_IMAGE_CODEC_FLAG_RETRY                  =   (1<<9),
    GDI_IMAGE_CODEC_FLAG_END
} gdi_image_codec_flag_enum;


#define GDI_COLOR_FORMAT_1          0   /* 1-bit , black/white color */
#define GDI_COLOR_FORMAT_8          1   /* 8-bit , index color */
#define GDI_COLOR_FORMAT_16            2        /* 16-bit, rgb 565 */
#define GDI_COLOR_FORMAT_24            3        /* 24-bit, B,G,R       8,8,8 */
#define GDI_COLOR_FORMAT_32            4        /* 32-bit, B,G,R,A  8,8,8,8 */
#define GDI_COLOR_FORMAT_STANDARD_END  5        /* standard color format end marker */
#define GDI_COLOR_FORMAT_LCD0          5        /* this usually mapping to main lcd */
#define GDI_COLOR_FORMAT_LCD1          6        /* this usually mapping to sub lcd */
#define GDI_COLOR_FORMAT_END           7

#if !defined(LCD_LAYER_SOURCE_COLOR_ARGB8888)   /* in MNT should support those format */
#define GDI_HW_COLOR_FORMAT_8       0
#define GDI_HW_COLOR_FORMAT_16         1
#define GDI_HW_COLOR_FORMAT_24         2
#define GDI_HW_COLOR_FORMAT_32         3
#else /* !defined(LCD_LAYER_SOURCE_COLOR_ARGB8888) */ 
#define GDI_HW_COLOR_FORMAT_8       LCD_LAYER_SOURCE_COLOR_8BPP_INDEX
#define GDI_HW_COLOR_FORMAT_16         LCD_LAYER_SOURCE_COLOR_RGB565
#define GDI_HW_COLOR_FORMAT_24         LCD_LAYER_SOURCE_COLOR_RGB888
#define GDI_HW_COLOR_FORMAT_32         LCD_LAYER_SOURCE_COLOR_ARGB8888
#endif /* !defined(LCD_LAYER_SOURCE_COLOR_ARGB8888) */ 


// device bmp (PBM) transparent define
#define	DEVICE_BMP_TRANSPARENT_COLOR_16 (0x1234)
#define	DEVICE_BMP_TRANSPARENT_COLOR_24 (0x123456)
#define	DEVICE_BMP_TRANSPARENT_COLOR_32 (0x12345678)


#define GDI_COLOR_FORMAT_MAINLCD       GDI_COLOR_FORMAT_LCD0
#define GDI_COLOR_FORMAT_SUBLCD        GDI_COLOR_FORMAT_LCD1
#define GDI_IMAGE_TYPE_INVALID                  0
#define GDI_IMAGE_TYPE_BMP                      1
#define GDI_IMAGE_TYPE_BMP_SEQUENCE             2
#define GDI_IMAGE_TYPE_GIF                      3
#define GDI_IMAGE_TYPE_DEVICE_BITMAP            4
#define GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE   5
#define GDI_IMAGE_TYPE_BMP_FILE                 6
#define GDI_IMAGE_TYPE_GIF_FILE                 7
#define GDI_IMAGE_TYPE_WBMP_FILE                8
#define GDI_IMAGE_TYPE_JPG                      9
#define GDI_IMAGE_TYPE_JPG_FILE                 10
#define GDI_IMAGE_TYPE_WBMP                     11
#define GDI_IMAGE_TYPE_AVI                      12
#define GDI_IMAGE_TYPE_AVI_FILE                 13
#define GDI_IMAGE_TYPE_3GP                      14
#define GDI_IMAGE_TYPE_3GP_FILE                 15
#define GDI_IMAGE_TYPE_MP4                      16
#define GDI_IMAGE_TYPE_MP4_FILE                 17
#define GDI_IMAGE_TYPE_JPG_SEQUENCE             18
#define GDI_IMAGE_TYPE_PNG                      19
#define GDI_IMAGE_TYPE_PNG_FILE                 20
#define GDI_IMAGE_TYPE_PNG_SEQUENCE             21
#define GDI_IMAGE_TYPE_DEVICE_BMP_FILE          22
#define GDI_IMAGE_TYPE_BMP_FILE_OFFSET          23
#define GDI_IMAGE_TYPE_GIF_FILE_OFFSET          24
#define GDI_IMAGE_TYPE_M3D                      25
#define GDI_IMAGE_TYPE_M3D_FILE                 26
#define GDI_IMAGE_TYPE_SVG                      27
#define GDI_IMAGE_TYPE_SVG_FILE                 28
#define GDI_IMAGE_TYPE_SWFLASH                  29
#define GDI_IMAGE_TYPE_SWFLASH_FILE             30

#define GDI_IMAGE_TYPE_JPG_FILE_OFFSET          31
#define GDI_IMAGE_TYPE_PNG_FILE_OFFSET          32
#define GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET   33
#define GDI_IMAGE_TYPE_WBMP_FILE_OFFSET         34
#define GDI_IMAGE_TYPE_M3D_FILE_OFFSET          35
#define GDI_IMAGE_TYPE_SVG_FILE_OFFSET          36
#define GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET      37
#define GDI_IMAGE_TYPE_AVATAR                   38

#define GDI_IMAGE_TYPE_ABM_FILE_OFFSET          39
#define GDI_IMAGE_TYPE_ABM                      40
#define GDI_IMAGE_TYPE_ABM_SEQUENCE             41
#define GDI_IMAGE_TYPE_ABM_FILE                 42

#define GDI_IMAGE_TYPE_MPG                      43
#define GDI_IMAGE_TYPE_MPG_FILE                 44
#define GDI_IMAGE_TYPE_MPG_FILE_OFFSET          45

#define GDI_IMAGE_TYPE_3G2                      46
#define GDI_IMAGE_TYPE_3G2_FILE                 47
#define GDI_IMAGE_TYPE_3G2_FILE_OFFSET          48

#define GDI_IMAGE_TYPE_VIS                      49
#define GDI_IMAGE_TYPE_VIS_FILE                 50

#define GDI_IMAGE_TYPE_SUM                      51

#define GDI_ERROR_HANDLE                        (-1)
#define GDI_NULL_HANDLE                         (0)

/////////////////////////////////////////////////////////////////////////////////////////////////
// GDI return code
/////////////////////////////////////////////////////////////////////////////////////////////////
#define GDI_SUCCEED                             0
#define GDI_IMAGE_IS_STILL_IMAGE                1
#define GDI_IMAGE_OUT_OF_CLIP_REGION            2

#define GDI_FAILED                              -1

#define GDI_GIF_LAST_FRAME                      1    /* this will be remove after 05B */
#define GDI_JPEG_SUCCEED                        GDI_SUCCEED  /* this will be remove after 05B */
#define GDI_GIF_ERR_OUT_OF_CLIP_REGION          GDI_SUCCEED  /* this will be remove after 05B */
#define GDI_BMP_ERR_OUT_OF_CLIP_REGION          GDI_SUCCEED  /* this will be remove after 05B */
#define GDI_IMAGE_SUCCEED                       GDI_SUCCEED  /* this will be remove after 05B */
#define GDI_LAYER_SUCCEED                       GDI_SUCCEED  /* this will be remove after 05B */
#define GDI_GIF_SUCCEED                         GDI_SUCCEED     /* this will be remove after 05B */


/* Image 1400, -1400 */
#define GDI_IMAGE_ERR_CANT_FIND_IMG_BY_ID          -1402
#define GDI_IMAGE_ERR_NULL_IMG_PTR                 -1403
#define GDI_IMAGE_ERR_INVALID_IMG_TYPE             -1404
#define GDI_IMAGE_ERR_NO_VALID_ANIMATOR            -1405
#define GDI_IMAGE_ERR_FILE_EXT_NOT_SUPPOTR         -1406
#define GDI_IMAGE_ERR_INVALID_FILE                 -1407
#define GDI_IMAGE_ERR_DECODE_FAILED                -1408
#define GDI_IMAGE_ERR_IMAGE_TOO_LARGE              -1409
#define GDI_IMAGE_ERR_OPEN_FILE_FAILED             -1410
#define GDI_IMAGE_ERR_NO_DECODER_SUPPORT           -1411
#define GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH			-1412	
#define GDI_IMAGE_ERR_FILE_FORMAT_WRONG					-1413
#define GDI_IMAGE_ERR_NO_DECODER					    -1414
#define GDI_IMAGE_ERR_INVALID_IMAGE_SIZE				-1415	
#define GDI_IMAGE_ERR_DECODE_TIME_OUT					-1416
#define GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE              -1417
#define GDI_IMAGE_ERR_RESOURCE_NOT_AVAILABLE            -1418

/* JPEG Map to Image */
#define GDI_JPEG_ERR_FRAME_BUFFER_NOT_ENOUGH			GDI_IMAGE_ERR_FRAME_BUFFER_NOT_ENOUGH	
#define GDI_JPEG_ERR_OPEN_FILE_FAILED					GDI_IMAGE_ERR_OPEN_FILE_FAILED	
#define GDI_JPEG_ERR_FILE_FORMAT_WRONG					GDI_IMAGE_ERR_FILE_FORMAT_WRONG
#define GDI_JPEG_ERR_NO_DECODER							GDI_IMAGE_ERR_NO_DECODER
#define GDI_JPEG_ERR_INVALID_IMAGE_SIZE			    	GDI_IMAGE_ERR_INVALID_IMAGE_SIZE	
#define GDI_JPEG_ERR_IMAGE_TOO_LARGE					GDI_IMAGE_ERR_IMAGE_TOO_LARGE
#define GDI_JPEG_ERR_DECODE_TIME_OUT					GDI_IMAGE_ERR_DECODE_TIME_OUT


/* Layer 1500, -1500 */
#define GDI_LAYER_DOUBLE_BUFFER_LOCKED             -1501
#define GDI_LAYER_ERR_NO_VALID_LAYER_HANDLE        -1502
#define GDI_LAYER_ERR_ALLOCATE_MEMORY_FAIL         -1503
#define GDI_LAYER_ERR_INVALID_BLT_REGION           -1504
#define GDI_LAYER_ERR_NO_VALID_DOUBLE_LAYER_ENTRY  -1505
#define GDI_LAYER_ERR_HANDLE_OUT_OF_VALID_RANGE    -1506

/* Image Decode 1700, - 1700 */
#define GDI_IMAGE_DECODER_ERR_WRONG_PARA           -1701
#define GDI_IMAGE_DECODER_ERR_NO_ITEM_ENTRY        -1702
#define GDI_IMAGE_DECODER_ERR_FILE_BUF_NOT_ENOUGH  -1703
#define GDI_IMAGE_DECODER_ERR_FRAME_BUF_NOT_ENOUGH -1704
#define GDI_IMAGE_DECODER_ERR_OPEN_FILE_FAILED     -1705
#define GDI_IMAGE_DECODER_ERR_INVALID_IMG_TYPE     -1706
#define GDI_IMAGE_DECODER_ERR_WRONG_HANDLE         -1707
#define GDI_IMAGE_DECODER_ERR_LIST_IS_EMPTY        -1708

/* ByteStream 1800, -1800 */
#define GDI_BYTESTREAM_ERR_OPEN_FILE_FAILED        -1801
#define GDI_BYTESTREAM_ERR_OPEN_BUFFER_FAILED      -1802

/* Image Encode 1900, - 1900 */
#define GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH    -1901
#define GDI_IMAGE_ENCODER_ERR_DISK_FULL         -1902
#define GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION     -1903
#define GDI_IMAGE_ENCODER_ERR_NO_DISK        -1904

/* Non-blocking -2000 */
#define GDI_ERR_NB_ABORT                            -2000


/* Util mode */
#define GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT      0
#define GDI_UTIL_MODE_NO_RESIZE_OR_SHORT_SIDE_FIT     1
#define GDI_UTIL_MODE_LONG_SIDE_FIT                2
#define GDI_UTIL_MODE_SHORT_SIDE_FIT                  3

#define GDI_HANDLE   gdi_handle
#define GDI_RESULT   gdi_result
#define GDI_COLOR gdi_color

#define GDI_MIN(A,B)    ((A)<(B)?(A):(B))
#define GDI_MAX(A,B)    ((A)>(B)?(A):(B))

#define GDI_LCD_LAYER_ROTATE_0            0x00
#define GDI_LCD_LAYER_ROTATE_90           0x01
#define GDI_LCD_LAYER_ROTATE_180          0x02
#define GDI_LCD_LAYER_ROTATE_270       0x03
#define GDI_LCD_LAYER_ROTATE_0_MIRROR        0x80
#define GDI_LCD_LAYER_ROTATE_90_MIRROR          0x81
#define GDI_LCD_LAYER_ROTATE_180_MIRROR         0x82
#define GDI_LCD_LAYER_ROTATE_270_MIRROR         0x83
#define GDI_LCD_LAYER_ROTATE_ALL_MASK        0x83
#define GDI_LCD_LAYER_ROTATE_MIRROR_MASK     0x80
#define GDI_LCD_LAYER_ROTATE_ANGLE_MASK         0x03



#define GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_440    0     // default value
#define GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_GRAY   (1<<0)
#define GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_442    (1<<1)

//////////////////////////////////////////////////////////////////////////////////
// general layer information
//////////////////////////////////////////////////////////////////////////////////
#define GDI_LAYER_CLIP_STACK_COUNT        (16)
#define GDI_LAYER_ACT_LAYER_STACK_COUNT      (8)
#define GDI_LAYER_OFFSET                  (1024/2)
#if defined(GDI_USING_LAYER) && !defined(LOW_COST_SUPPORT)
#define GDI_LAYER_TOTAL_LAYER_COUNT          (16)
#else 
#define GDI_LAYER_TOTAL_LAYER_COUNT          (4)
#endif 

//////////////////////////////////////////////////////////////////////////////////
// main lcd layers
//////////////////////////////////////////////////////////////////////////////////
#define GDI_MAINLCD_MAX_LAYERS                     1

#if defined(__MMI_CAMERA__) && GDI_MAINLCD_MAX_LAYERS       <2
#undef GDI_MAINLCD_MAX_LAYERS
#define GDI_MAINLCD_MAX_LAYERS                  2
#endif /* defined(__MMI_CAMERA__) && GDI_MAINLCD_MAX_LAYERS       <2 */ 

/* tmp, wait leo fix :P */
#if defined(__GDI_MEMORY_PROFILE_2__) && GDI_MAINLCD_MAX_LAYERS   <2
#undef GDI_MAINLCD_MAX_LAYERS
#define GDI_MAINLCD_MAX_LAYERS                  2
#endif /* defined(__GDI_MEMORY_PROFILE_2__) && GDI_MAINLCD_MAX_LAYERS   <2 */ 

//////////////////////////////////////////////////////////////////////////////////
// sub lcd layers
//////////////////////////////////////////////////////////////////////////////////
#ifdef __MMI_SUBLCD__
#define GDI_SUBLCD_MAX_LAYERS                   1
#else 
#define GDI_SUBLCD_MAX_LAYERS                   0
#endif 

#endif /* _GDI_CONST_H_ */ 


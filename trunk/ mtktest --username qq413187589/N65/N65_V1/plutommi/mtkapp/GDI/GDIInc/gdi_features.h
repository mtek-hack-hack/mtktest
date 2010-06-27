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
 *  gdi_features.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Features Set.
 *
 * Author:
 * -------
 * -------
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_FEATURES_H_
#define _GDI_FEATURES_H_

#include "drv_features.h"

#if DRV_LAYER_TOTAL_COUNT == 6
    #define GDI_USING_MUTEX
    #define GDI_USING_LAYER
    #define GDI_6_LAYERS
    #define GDI_LAYER_HW_LAYER_COUNT       DRV_LAYER_TOTAL_COUNT
    #define GDI_LAYER_TREE_MAX_DEPTH       8
#elif DRV_LAYER_TOTAL_COUNT == 4
    #define GDI_USING_MUTEX
    #define GDI_USING_LAYER
    #define GDI_4_LAYERS
    #define GDI_LAYER_HW_LAYER_COUNT       DRV_LAYER_TOTAL_COUNT
    #define GDI_LAYER_TREE_MAX_DEPTH       8
#elif DRV_LAYER_TOTAL_COUNT == 2 /* in 6223, code use 2 layer internally, but 4 layer in the interface */
    #define GDI_USING_MUTEX
    #define GDI_USING_LAYER
    #define GDI_2_LAYERS
    /* in 6223, the interface still use 4 layer to simplify code */
    #define GDI_LAYER_HW_LAYER_COUNT        4
    #define GDI_LAYER_TREE_MAX_DEPTH        8
#elif DRV_LAYER_TOTAL_COUNT == 1 /* in 6205B , code still use 4 layer, but no hardware layer feature */
    #define GDI_LAYER_HW_LAYER_COUNT 4
    #define GDI_LAYER_TREE_MAX_DEPTH 4
#else
    #error "GDI don't understand DRV_LAYER_TOTAL_COUNT"
#endif


#if defined(TV_OUT_SUPPORT) && defined(DRV_LCD_MEMORY_OUTPUT)
    #define GDI_USING_TV_OUTPUT
#endif

#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
    #define GDI_USING_LAYER_BACKGROUND
#endif

#if defined(DRV_LCD_MEMORY_OUTPUT)
    #define GDI_USING_LAYER_OUTPUT_ANOTHER_MEMORY
#endif

#if defined(DRV_LAYER_COLOR_FORMAT)
#define GDI_USING_LAYER_COLOR_FORMAT
#endif

#ifdef USE_HW_GIF_DECODER_V1
#define GDI_USING_HW_GIF
#endif

#ifdef USE_HW_GIF_DECODER_V2
#define GDI_USING_HW_GIF_V2
#endif

#if defined(DRV_2D_ENGINE_V1)
#define GDI_USING_2D_ENGINE
#endif

#if defined(DRV_2D_ENGINE_V2)
#define GDI_USING_2D_ENGINE_V2
#endif

#if defined(DRV_LAYER_ROTATE)
#define GDI_USING_LAYER_ROTATE
#endif

#if defined(LCM_ROTATE_SUPPORT)
#define GDI_USING_LCD_ROTATE
#endif

#if defined(SVG_SUPPORT)
#define GDI_USING_SVG
#endif

#if defined(ISP_SUPPORT) && defined(__MTK_TARGET__) && !defined(MT6225)
    #define GDI_USING_ISP
#endif

///////////////////////////////////////////////////////////////
/// JPEG
#if defined (JPG_DECODE) || defined (JPG_ENCODE)
    #define GDI_USING_JPEG
    #define GDI_USING_HW_JPEG

    #ifdef DRV_IMG_CLIP_SUPPORT
    #define GDI_HW_JPEG_SUPPORT_OUTPUT_CLIPPING
    #endif

    #ifdef DRV_IMG_MEM_OUTPUT_SUPPORT
    #define GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER
    #endif

    #ifdef DRV_IMG_PITCH_MODE_SUPPORT
    #define GDI_HW_JPEG_SUPPORT_DIRECT_OUTPUT_BUFFER
    #endif

    #if defined(DRV_JPG_DEC_28_SERIES)
    #define GDI_HW_JPEG_SUPPORT_COLOR_FORMAT
    #endif

    #if defined(DRV_JPG_DEC_17_SERIES)
    #define GDI_HW_JPEG_PADDING_PITCH
    #endif

    #ifdef EXIF_SUPPORT
    #define GDI_USING_JPEG_EXIF
    #endif

    #ifdef JPG_ENCODE
    #define GDI_USING_JPEG_ENCODE
        #if defined(DRV_JPG_ENC_THUMBNAIL_SUPPORT)
            #define JPEG_ENCODE_THUMBNAIL_MODE
        #endif
    #endif
#endif /* defined (JPG_DECODE) || defined (JPG_ENCODE) */

//////////////////////////////////////////////////////////////
/// RESIZER

#ifdef DRV_RGB_RESIZE_SUPPORT
    #define GDI_USING_HW_RESIZER
    #ifdef DRV_IMG_PITCH_MODE_SUPPORT
        #define GDI_HW_RESIZER_PITCH_MODE
    #endif
#endif

//////////////////////////////////////////////////////////////
/// PNG
#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
#define GDI_USING_PNG
#define GDI_USING_HW_PNG
#endif /* USE_HW_PNG_DECODER_V1 */

//////////////////////////////////////////////////////////////
/// Palette control
#if DRV_PALETTE_COUNT
    #define GDI_SUPPORT_PALETTES     DRV_PALETTE_COUNT
#endif

#if defined (DRV_PALETTE_RGB_888)
    #define GDI_PALETTE_COLOR_FROM_RGB     gd_color_from_rgb_24
    #define GDI_PALETTE_COLOR_TO_RGB       gd_color_to_rgb_24
#elif defined(DRV_PALETTE_RGB_565)
    #define GDI_PALETTE_COLOR_FROM_RGB     gd_color_from_rgb_16
    #define GDI_PALETTE_COLOR_TO_RGB       gd_color_to_rgb_16
#else
    #define GDI_PALETTE_COLOR_FROM_RGB     gd_color_from_rgb_16
    #define GDI_PALETTE_COLOR_TO_RGB       gd_color_to_rgb_16
#endif


// For MOS/Windows simulator.
#ifdef WIN32
#undef GDI_USING_HW_GIF
#undef GDI_USING_HW_GIF_V2
#undef GDI_USING_2D_ENGINE
#undef GDI_USING_2D_ENGINE_V2
#undef GDI_USING_HW_RESIZER
#undef GDI_USING_LCD_ROTATE
#endif /* WIN32 */


//////////////////////////////////////////////////////////////
/// Single bank
#ifdef __SINGLE_BANK_NOR_FLASH_SUPPORT__
    /* With hardware decoder, data in RO section must be moved to RAM before
       decoding in single-bank NOR flash (to avoid NOR flash accessed by DMA) */
    #if defined(GDI_USING_HW_GIF_V2)
        #error "GIF v2 not yet supported in single-bank NOR flash"
    #endif

    #if defined(GDI_USING_HW_GIF) || (defined(GDI_USING_HW_JPEG) && !defined(__SW_JPEG_CODEC_SUPPORT__))
        #define GDI_USING_IMAGE_SINGLE_BANK_CACHE
        #if defined(__MMI_MAINLCD_240X320__)
            #define GDI_IMAGE_SINGLE_BANK_CACHE_SIZE    (200 * 1024)
        #elif defined(__MMI_MAINLCD_176X220__)
            #define GDI_IMAGE_SINGLE_BANK_CACHE_SIZE    (150 * 1024)
        #else
            #define GDI_IMAGE_SINGLE_BANK_CACHE_SIZE    (100 * 1024)
        #endif
    #endif

    #undef GDI_USING_2D_ENGINE
    #undef GDI_USING_2D_ENGINE_V2
    // single bank use 2d engine font still has bug
    //#if defined(GDI_USING_2D_ENGINE) || defined(GDI_USING_2D_ENGINE_V2)
        //#define GDI_USING_FONT_SINGLE_BANK_CACHE
        //#define GDI_FONT_SINGLE_BANK_CACHE_SIZE         (160)
    //#endif
#endif


#if defined(M3D_MMI_SUPPORT)
    #define GDI_USING_M3D
    #if defined(MMI_MAIN_LCD_DEFAULT_FORMAT)
    #if (MMI_MAIN_LCD_DEFAULT_FORMAT != 16) && !defined(GDI_USING_2D_ENGINE_V2)
        #undef GDI_USING_M3D
    #endif
    #endif
#endif

#ifdef GDI_USING_M3D
    #ifdef __MMI_AVATAR__
        #define GDI_USING_AVATAR
    #endif
#endif

#if defined(GDI_USING_HW_GIF) || defined(GDI_USING_HW_GIF_V2) || defined(GDI_USING_JPEG) || defined(GDI_USING_M3D) || defined(GDI_USING_PNG) || defined(GDI_USING_HW_RESIZER)
    #define GDI_USING_LCD_WORK_BUFFER // gdi will prepare a LCD size work buffer, not 512 bytes work buffer
#endif

#endif /* _GDI_FEATURES_H_ */


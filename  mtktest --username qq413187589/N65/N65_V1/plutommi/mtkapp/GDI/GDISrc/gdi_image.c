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
 *  gdi_image.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI image drawing functions..
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
#include "gdc_include.h"
#include "gdi_util.h"

#include "gui.h"
#include "drm_gprot.h"


/* GraphicLib's header */
#ifdef GDI_USING_TV_OUTPUT
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* GDI_USING_TV_OUTPUT */ 

#ifdef GDI_USING_JPEG_ENCODE
#include "jpeg.h"
#endif

#include "Unicodexdcl.h"

#include "med_global.h"
#include "med_api.h"    /* media task */
#include "med_main.h"
#include "med_utility.h"

#include "wrappergprot.h"
#include "ucs2prot.h"

#if defined(GDI_IMAGE_PROFILE)
    #include "gui_themes.h"
    #include "app_str.h"
    #include "ucs2prot.h"
    #include "ProfilingEngine.h"


    #if  (defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) && defined(__MTK_TARGET__)
        extern kal_bool   NFB_SecondaryImageLoaded;
    #endif
#endif

const U16 *gdi_image_ext_name[] = 
{
    // #define GDI_IMAGE_TYPE_INVALID                               0
    L"",
    // #define GDI_IMAGE_TYPE_BMP                                   1
    L".bmp",
    // #define GDI_IMAGE_TYPE_BMP_SEQUENCE                          2
    L".bmp",
    // #define GDI_IMAGE_TYPE_GIF                                   3
    L".gif",
    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP                         4
    L".pbm",
    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE                5
    L".pbm",
    // #define GDI_IMAGE_TYPE_BMP_FILE                              6
    L".bmp",
    // #define GDI_IMAGE_TYPE_GIF_FILE                              7
    L".gif",
    // #define GDI_IMAGE_TYPE_WBMP_FILE                             8
    L".wbmp",
    // #define GDI_IMAGE_TYPE_JPG                                   9
    L".jpg",
    // #define GDI_IMAGE_TYPE_JPG_FILE                              10
    L".jpg",
    // #define GDI_IMAGE_TYPE_WBMP                                  11
    L".wbmp",
    // #define GDI_IMAGE_TYPE_AVI                                   12
    L".avi",
    // #define GDI_IMAGE_TYPE_AVI_FILE                              13
    L".avi",
    // #define GDI_IMAGE_TYPE_3GP                                   14
    L".3gp",
    // #define GDI_IMAGE_TYPE_3GP_FILE                              15
    L".3gp",
    // #define GDI_IMAGE_TYPE_MP4                                   16
    L".mp4",
    // #define GDI_IMAGE_TYPE_MP4_FILE                              17
    L".mp4",
    // #define GDI_IMAGE_TYPE_JPG_SEQUENCE                          18
    L".jpg",
    // #define GDI_IMAGE_TYPE_PNG                                   19
    L".png",
    // #define GDI_IMAGE_TYPE_PNG_FILE                              20
    L".png",
    // #define GDI_IMAGE_TYPE_PNG_SEQUENCE                          21
    L".png",
    // #define GDI_IMAGE_TYPE_DEVICE_BMP_FILE                       22
    L".pbm",
    // #define GDI_IMAGE_TYPE_BMP_FILE_OFFSET                       23
    L".bmp",
    // #define GDI_IMAGE_TYPE_GIF_FILE_OFFSET                       24
    L".gif",
    // #define GDI_IMAGE_TYPE_M3D                                   25
    L".m3d",
    // #define GDI_IMAGE_TYPE_M3D_FILE                              26
    L".m3d",
    // #define GDI_IMAGE_TYPE_SVG                                   27
    L".svg",
    // #define GDI_IMAGE_TYPE_SVG_FILE                              28
    L".svg",
    //#define GDI_IMAGE_TYPE_SWFLASH                                29
    L".cmp",
    //#define GDI_IMAGE_TYPE_SWFLASH_FILE                           30
    L".cmp",
    //#define GDI_IMAGE_TYPE_JPG_FILE_OFFSET                        31
    L".jpg",
    //#define GDI_IMAGE_TYPE_PNG_FILE_OFFSET                        32
    L".png",
    //#define GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET                 33
    L".pbm",
    //#define GDI_IMAGE_TYPE_WBMP_FILE_OFFSET                       34
    L".wbmp",
    //#define GDI_IMAGE_TYPE_M3D_FILE_OFFSET                        35
    L".m3d",
    //#define GDI_IMAGE_TYPE_SVG_FILE_OFFSET                        36
    L".svg",
    //#define GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET                    37
    L".cmp",
    //#define GDI_IMAGE_TYPE_AVATAR                                 38    
    L".m3d",
    // #define GDI_IMAGE_TYPE_ABM_FILE_OFFSET                       39
    L".abm",
    // #define GDI_IMAGE_TYPE_ABM                                   40
    L".abm",    
    // #define GDI_IMAGE_TYPE_ABM_SEQUENCE                          41
    L".abm",    
    // #define GDI_IMAGE_TYPE_ABM_FILE                              42
    L".abm",    
    //#define GDI_IMAGE_TYPE_MPG                                    43
    L".mpg",
    //#define GDI_IMAGE_TYPE_MPG_FILE                               44
    L".mpg",
    //#define GDI_IMAGE_TYPE_MPG_FILE_OFFSET                        45
    L".mpg",
    //#define GDI_IMAGE_TYPE_3G2                                    46
    L".3g2",
    //#define GDI_IMAGE_TYPE_3G2_FILE                               47
    L".3g2",
    //#define GDI_IMAGE_TYPE_3G2_FILE_OFFSET                        48
    L".3g2",
    //#define GDI_IMAGE_TYPE_VIS                                    49
    L".vis",
    //#define GDI_IMAGE_TYPE_VIS_FILE                               50
    L".vis",
    //#define GDI_IMAGE_TYPE_SUM                                    51
    L""
};

#define GDI_IMAGE_ENCODER_JPEG_RESIZER_UPPER_BOUND (640*480*GDI_MAINLCD_BIT_PER_PIXEL)>>3

/****************************************************************************
* Local Variable
*****************************************************************************/
#if defined(GDI_USING_LCD_WORK_BUFFER)
    #define GDI_WORK_BUFFER_SIZE (((GDI_LCD_WIDTH + 16) * (GDI_LCD_HEIGHT + 16) * GDI_MAINLCD_BIT_PER_PIXEL) >> 3) // default size
    #ifdef GDI_WORK_BUFFER_FORMAT
        #if (GDI_WORK_BUFFER_FORMAT == GDI_COLOR_FORMAT_32)
            #undef GDI_WORK_BUFFER_SIZE
            #define GDI_WORK_BUFFER_SIZE (((GDI_LCD_WIDTH + 16) * (GDI_LCD_HEIGHT + 16) * 32) >> 3) 
        #elif (GDI_WORK_BUFFER_FORMAT == GDI_COLOR_FORMAT_24)
            #undef GDI_WORK_BUFFER_SIZE
            #define GDI_WORK_BUFFER_SIZE (((GDI_LCD_WIDTH + 16) * (GDI_LCD_HEIGHT + 16) * 24) >> 3)
        #endif
    #endif
#else
    #define GDI_WORK_BUFFER_SIZE (512)
#endif

U32 gdi_work_buffer[GDI_WORK_BUFFER_SIZE/4];
U32 gdi_work_buffer_size = GDI_WORK_BUFFER_SIZE;

#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
static const U8 *gdi_image_single_bank_cache_src;
static S32 gdi_image_single_bank_cache_size;
static U32 gdi_image_single_bank_cache_buf[GDI_IMAGE_SINGLE_BANK_CACHE_SIZE/4];
#endif

const gdi_image_codecs_struct gdi_image_codecs[GDI_IMAGE_TYPE_SUM + 1] = 
{
    // #define GDI_IMAGE_TYPE_INVALID                                       0
    {NULL, NULL, NULL, NULL, NULL, NULL},
    // #define GDI_IMAGE_TYPE_BMP                                           1
    {
     NULL,
     gdi_image_bmp_draw_handler,
     NULL,
     gdi_image_bmp_get_dimension_handler,
     NULL,
     NULL},
    // #define GDI_IMAGE_TYPE_BMP_SEQUENCE                          2
    {
     NULL,
     gdi_image_sequence_draw_handler,
     NULL,
     gdi_image_sequence_get_dimension_handler,
     gdi_image_sequence_get_pos_info_handler,
     NULL},
    // #define GDI_IMAGE_TYPE_GIF                                                   3
    {
     NULL,
     gdi_image_gif_draw_handler,
     NULL,
     gdi_image_gif_get_dimension_handler,
     gdi_image_gif_get_pos_info_handler,
     NULL},

    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP                         4
    {
     NULL,
     gdi_image_dev_bmp_draw_handler,
     NULL,
     gdi_image_dev_bmp_get_dimension_handler,
     NULL,
     NULL,
     },
    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE        5
    {
     NULL,
     gdi_image_sequence_draw_handler,
     NULL,
     gdi_image_sequence_get_dimension_handler,
     gdi_image_sequence_get_pos_info_handler,
     NULL},

    // #define GDI_IMAGE_TYPE_BMP_FILE                                      6
    {
     NULL,
     gdi_image_bmp_draw_handler,
     NULL,
     gdi_image_bmp_get_dimension_handler,
     NULL,
     gdi_image_is_bmp_file,
     },
    // #define GDI_IMAGE_TYPE_GIF_FILE                                      7
    {
     NULL,
     gdi_image_gif_draw_handler,
     NULL,
     gdi_image_gif_get_dimension_handler,
     gdi_image_gif_get_pos_info_handler,
     gdi_image_is_gif_file},
    // #define GDI_IMAGE_TYPE_WBMP_FILE                                     8
    {
     NULL,
     gdi_image_wbmp_draw_handler,
     NULL,
     gdi_image_wbmp_get_dimension_handler,
     NULL,
     gdi_image_is_wbmp_file},
    // #define GDI_IMAGE_TYPE_JPG                                                   9
    {
     NULL,
     gdi_image_jpeg_draw_handler,
     NULL,
     gdi_image_jpeg_get_dimension_handler,
     NULL,
     NULL},
    // #define GDI_IMAGE_TYPE_JPG_FILE                                      10
    {
     NULL,
     gdi_image_jpeg_draw_handler,
     NULL,
     gdi_image_jpeg_get_dimension_handler,
     NULL,
     gdi_image_is_jpeg_file},
    // #define GDI_IMAGE_TYPE_WBMP                                          11
    {
     NULL,
     gdi_image_wbmp_draw_handler,
     NULL,
     gdi_image_wbmp_get_dimension_handler,
     NULL,
     NULL},
    // #define GDI_IMAGE_TYPE_AVI                                                   12
    {NULL, NULL, NULL, NULL, NULL, NULL},
    // #define GDI_IMAGE_TYPE_AVI_FILE                                      13
    {NULL, NULL, NULL, NULL, NULL, NULL},
    // #define GDI_IMAGE_TYPE_3GP                                                   14
    {NULL, NULL, NULL, NULL, NULL, NULL},
    // #define GDI_IMAGE_TYPE_3GP_FILE                                      15
    {NULL, NULL, NULL, NULL, NULL, NULL},
    // #define GDI_IMAGE_TYPE_MP4                                           16
    {NULL, NULL, NULL, NULL, NULL, NULL},
    // #define GDI_IMAGE_TYPE_MP4_FILE                                      17
    {NULL, NULL, NULL, NULL, NULL, NULL},
    // #define GDI_IMAGE_TYPE_JPG_SEQUENCE                          18
    {
     NULL,
     gdi_image_sequence_draw_handler,
     NULL,
     gdi_image_sequence_get_dimension_handler,
     gdi_image_sequence_get_pos_info_handler,
     NULL},
    // #define GDI_IMAGE_TYPE_PNG                                           19
    {
     NULL,
     gdi_image_png_draw_handler,
     NULL,
     gdi_image_png_get_dimension_handler,
     NULL,
     NULL},
    // #define GDI_IMAGE_TYPE_PNG_FILE                                      20
    {
     NULL,
     gdi_image_png_draw_handler,
     NULL,
     gdi_image_png_get_dimension_handler,
     NULL,
     gdi_image_is_png_file},
    // #define GDI_IMAGE_TYPE_PNG_SEQUENCE                          21
    {
     NULL,
     gdi_image_sequence_draw_handler,
     NULL,
     gdi_image_sequence_get_dimension_handler,
     gdi_image_sequence_get_pos_info_handler,
     NULL},
    // #define GDI_IMAGE_TYPE_DEVICE_BMP_FILE                       22
    {
     NULL,
     gdi_image_dev_bmp_draw_handler,
     NULL,
     gdi_image_dev_bmp_get_dimension_handler,
     NULL,
     gdi_image_is_device_bmp_file},
    // #define GDI_IMAGE_TYPE_BMP_FILE_OFFSET                       23
    {
     NULL,
     gdi_image_virtualfile_draw_handler,
     NULL,
     gdi_image_virtualfile_get_dimension_handler,
     gdi_image_virtualfile_get_pos_info_handler,
     NULL},
    // #define GDI_IMAGE_TYPE_GIF_FILE_OFFSET                       24
    {
     NULL,
     gdi_image_virtualfile_draw_handler,
     NULL,
     gdi_image_virtualfile_get_dimension_handler,
     gdi_image_virtualfile_get_pos_info_handler,
     NULL},
    //#define GDI_IMAGE_TYPE_M3D                                 25
    //#define GDI_IMAGE_TYPE_M3D_FILE                         26
 #ifdef GDI_USING_M3D
    {
     gdi_image_m3d_draw_before_handler,
     gdi_image_m3d_draw_handler,
     gdi_image_m3d_draw_after_handler,
     gdi_image_m3d_get_dimension_handler,
     gdi_image_m3d_get_pos_info_handler,
     NULL},
    {
     gdi_image_m3d_draw_before_handler,
     gdi_image_m3d_draw_handler,
     gdi_image_m3d_draw_after_handler,
     gdi_image_m3d_get_dimension_handler,
     gdi_image_m3d_get_pos_info_handler,
     gdi_image_is_m3d_file},
 #else /* GDI_USING_M3D */ 
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},
 #endif /* GDI_USING_M3D */ 

    // #define GDI_IMAGE_TYPE_SVG                                   27
    // #define GDI_IMAGE_TYPE_SVG_FILE                              28
#ifdef GDI_USING_SVG
    {
        gdi_image_svg_draw_before_handler,
        gdi_image_svg_draw_handler,
        gdi_image_svg_draw_after_handler,
        gdi_image_svg_get_dimension_handler,
        gdi_image_svg_get_pos_info_handler,
        NULL
    },
    {
        gdi_image_svg_draw_before_handler,
        gdi_image_svg_draw_handler,
        gdi_image_svg_draw_after_handler,
        gdi_image_svg_get_dimension_handler,
        gdi_image_svg_get_pos_info_handler,
        gdi_image_is_svg_file
    },
#else
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},
#endif
    //#define GDI_IMAGE_TYPE_MFLASH                                 29
    //#define GDI_IMAGE_TYPE_MFLASH_FILE                            30
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},
        
    //#define GDI_IMAGE_TYPE_JPG_FILE_OFFSET                        31
    //#define GDI_IMAGE_TYPE_PNG_FILE_OFFSET                        32
    //#define GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET                 33
    //#define GDI_IMAGE_TYPE_WBMP_FILE_OFFSET                       34
    //#define GDI_IMAGE_TYPE_M3D_FILE_OFFSET                        35
    //#define GDI_IMAGE_TYPE_SVG_FILE_OFFSET                        36
    //#define GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET                    37
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    //#define GDI_IMAGE_TYPE_AVATAR                                 38
#ifdef GDI_USING_AVATAR
    {
     gdi_image_m3d_avatar_draw_before_handler,
     gdi_image_m3d_draw_handler,
     gdi_image_m3d_draw_after_handler,
     gdi_image_m3d_get_dimension_handler,
     gdi_image_m3d_avatar_get_pos_info_handler,
     gdi_image_is_m3d_file},
#else
    {NULL, NULL, NULL, NULL, NULL, NULL},
#endif
    //#define GDI_IMAGE_TYPE_ABM_FILE_OFFSET                        39
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL},
    //#define GDI_IMAGE_TYPE_ABM                                    40
    {
        NULL,
        gdi_image_abm_draw_handler,
        NULL,
        gdi_image_abm_get_dimension_handler,
        NULL,
        NULL
    },
    //#define GDI_IMAGE_TYPE_ABM_SEQUENCE                           41
    {
        NULL,
        gdi_image_sequence_draw_handler,
        NULL,
        gdi_image_sequence_get_dimension_handler,
        gdi_image_sequence_get_pos_info_handler,
        NULL
    },
    //#define GDI_IMAGE_TYPE_ABM_FILE                               42
    {
        NULL,
        gdi_image_abm_draw_handler,
        NULL,
        gdi_image_abm_get_dimension_handler,
        NULL,
        gdi_image_is_device_bmp_file
    },    
    
    //#define GDI_IMAGE_TYPE_MPG                                    43
    //#define GDI_IMAGE_TYPE_MPG_FILE                               44
    //#define GDI_IMAGE_TYPE_MPG_FILE_OFFSET                        45
    //#define GDI_IMAGE_TYPE_3G2                                    46
    //#define GDI_IMAGE_TYPE_3G2_FILE                               47
    //#define GDI_IMAGE_TYPE_3G2_FILE_OFFSET                        48
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},

    //#define GDI_IMAGE_TYPE_VIS                                    49
    //#define GDI_IMAGE_TYPE_VIS_FILE                               50
    {NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL},

    //#define GDI_IMAGE_TYPE_SUM                                    51
    {NULL, NULL, NULL, NULL, NULL, NULL}
};

BOOL gdi_memory_output = FALSE;
U16 gdi_memory_output_width;
U16 gdi_memory_output_height;
U32 gdi_memory_output_buffer_address;
U32 gdi_memory_output_buffer_size;
static U32 gdi_image_codec_flag_stack[8] = {0};
static U32 gdi_image_codec_flag_index = 0;

static kal_timerid gdi_image_timer; // this timer is for codec used
static S32 gdi_image_timer_count; // it is the total number of 0.5 seconds
static S32 gdi_image_timer_timeout_count ; // if gdi_image_timer_count > this value , it should be timeout
static BOOL gdi_image_timer_timeout_flag;

static BOOL gdi_image_abort_flag = FALSE;
static BOOL gdi_nb_is_high_priority_flag = FALSE;

static void (*gdi_image_progress_callback_ptr)(void *,S32,S32,S32,S32) = NULL;
static void*  gdi_image_progress_callback_arg;
static S32 gdi_image_progress_count; // this value is the previous progress callback timer_count

static S32 gdi_image_update_area_x1;
static S32 gdi_image_update_area_y1;
static S32 gdi_image_update_area_x2;
static S32 gdi_image_update_area_y2;

static U32 gdi_image_encoding_flag;
/****************************************************************************
* Gif Anim Internal Functions
*****************************************************************************/
static void gdi_image_timeout_handler(void *param)
{
    gdi_image_timer_count++;
    
    if(gdi_image_timer_count >= gdi_image_timer_timeout_count)
        gdi_image_timer_timeout_flag = TRUE;
    else
        kal_set_timer(gdi_image_timer, gdi_image_timeout_handler, (void*)0, KAL_TICKS_100_MSEC*5, 0); // 0.5 seconds
}

void gdi_image_set_timeout(S32 seconds)
{
    MMI_TRACE(GDI_TRC, GDI_TRC_53,//"gdi_image_codec set timeout = %d seconds"
        seconds);

    gdi_image_timer_timeout_count = seconds *2; // 1 count is 0.5 seconds 
    gdi_image_timer_count = 0;
    gdi_image_timer_timeout_flag = FALSE;
    kal_set_timer(gdi_image_timer, gdi_image_timeout_handler, (void*)0, KAL_TICKS_100_MSEC*5, 0); // 0.5 seconds
}

void gdi_image_clear_timeout(void)
{
    MMI_TRACE(GDI_TRC, GDI_TRC_54//"gdi_image_codec clean timeout"
        );
    kal_cancel_timer(gdi_image_timer);
}

void gdi_image_set_progress_callback(void (*ptr)(void *,S32,S32,S32,S32),void* arg)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_set_progress_callback)
    gdi_image_progress_callback_ptr = ptr;
    gdi_image_progress_callback_arg = arg;
    gdi_image_progress_count        = 0;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_set_progress_callback)
}

BOOL gdi_image_is_timeout(void)
{
    return gdi_image_timer_timeout_flag;
}

void gdi_image_set_abort(BOOL is_abort)
{
    gdi_image_abort_flag = is_abort;
}
BOOL gdi_image_is_abort(void)
{
    return gdi_image_abort_flag;
}

S32 gdi_image_progress_callback(void)
{
    if(gdi_image_abort_flag) 
    {
        MMI_TRACE(GDI_TRC, GDI_TRC_55//"FORCE ABORT SUCCEED"
        );
        return 0;
    }
    if(gdi_image_timer_timeout_flag)
    {
        return 0;
    }

    if(gdi_image_progress_callback_ptr != NULL)
    if(gdi_image_progress_count < gdi_image_timer_count)
    {
        gdi_image_progress_count = gdi_image_timer_count;
        gdi_image_progress_callback_ptr (
                gdi_image_progress_callback_arg,
                gdi_image_update_area_x1,
                gdi_image_update_area_y1,
                gdi_image_update_area_x2,
                gdi_image_update_area_y2
                );
    }        

    return 1;
}

void gdi_image_set_update_area(S32 x1,S32 y1,S32 x2,S32 y2)
{
    MMI_TRACE(GDI_TRC, GDI_TRC_56,//"gdi_image_set_update_area %d %d %d %d"
        x1,y1,x2,y2
        );
    gdi_image_update_area_x1 = x1;
    gdi_image_update_area_y1 = y1;
    gdi_image_update_area_x2 = x2;
    gdi_image_update_area_y2 = y2;
}

void gdi_image_get_update_area(S32 *x1,S32 *y1,S32 *x2,S32 *y2)
{
    *x1 = gdi_image_update_area_x1;
    *y1 = gdi_image_update_area_y1;
    *x2 = gdi_image_update_area_x2;
    *y2 = gdi_image_update_area_y2;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_init
 * DESCRIPTION
 *  Init GDI Iamge module.
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_init(void)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_init)
    {
        gdi_image_timer = kal_create_timer("GDIMG");
        gdi_image_timer_timeout_flag = FALSE;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_init)
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_parse_resource_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res_src         [?]         
 *  data_ptr        [IN]        
 *  img_type        [?]         
 *  img_size        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_parse_resource_internal(U8 *res_src, U8 **data_ptr, U8 *img_type, S32 *img_size, S32 *frame_number, S32 *width, S32 *height)
{
    GDI_DEBUG_ASSERT(res_src);
    
    *img_type = res_src[0];
	*frame_number = (S32)(U32) res_src[1];

    switch (*img_type)
    {
        case GDI_IMAGE_TYPE_M3D:
        case GDI_IMAGE_TYPE_SVG:
            *frame_number = -1;
            *img_size = (S32) (res_src[2]) | (S32) ((S32) res_src[3] << 8) | (S32) ((S32) res_src[4] << 16);
            *data_ptr = res_src + 8;
            break;

        case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
        case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
        case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
	    	*img_size = (S32)(((U32)res_src[4])<<16)|(((U32)res_src[3])<<8)|(((U32)res_src[2]));
    		*data_ptr = res_src;
		    break;
            
        default:
			*width 		  = (S32)(( ((U32)res_src[7])     <<4) | (((U32)res_src[6]&0xF0)>>4));
			*height		  = (S32)(((((U32)res_src[6])&0xF)<<8) |  ((U32)res_src[5]         ));
        	*img_size = (S32) (res_src[2]) | (S32) ((S32) res_src[3] << 8) | (S32) ((S32) res_src[4] << 16);
            *data_ptr = res_src + 8;
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension_id
 * DESCRIPTION
 *  stop a animation by handle
 * PARAMETERS
 *  image_id        [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension_id(U16 image_id, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            (U8*) GetImage(image_id),
            GDI_IMAGE_TYPE_INVALID,
            0,
            width,
            height,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension_file
 * DESCRIPTION
 *  get image dimension from a file
 * PARAMETERS
 *  image_name      [?]         
 *  width           [OUT]       
 *  height          [OUT]       
 *  U16(?)          [IN]        Image_id
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension_file(S8 *image_name, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_FILE,
            (U8*) image_name,
            GDI_IMAGE_TYPE_INVALID,
            0,
            width,
            height,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension
 * DESCRIPTION
 *  get image dimesion from resource
 * PARAMETERS
 *  image_ptr       [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension(U8 *image_ptr, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            width,
            height,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension_mem
 * DESCRIPTION
 *  get image dimesion from memory
 * PARAMETERS
 *  image_ptr       [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension_mem(U8 img_type,U8 *img_ptr,S32 img_size,S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_MEMORY,
            img_ptr,
            img_type,
            img_size,
            width,
            height,
            0);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count_id
 * DESCRIPTION
 *  get frame count of an animation from id
 * PARAMETERS
 *  image_id        [IN]        
 *  frame_count     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_count_id(U16 image_id, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            (U8*) GetImage(image_id),
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count
 * DESCRIPTION
 *  get frame count of an animation from memory
 * PARAMETERS
 *  image_ptr       [IN]        
 *  frame_count     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_count(U8 *image_ptr, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count_file
 * DESCRIPTION
 *  get frame count of an animation from file
 * PARAMETERS
 *  image_ptr       [IN]        
 *  frame_count     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_count_file(U8 *image_ptr, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_FILE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_mem
 * DESCRIPTION
 *  check gdi decoder's capability
 * PARAMETERS
 *  ptr        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_type_from_mem_internal(U8 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef GDI_USING_AVATAR
        if (*p == GDI_IMAGE_TYPE_AVATAR)
            return (GDI_IMAGE_TYPE_AVATAR);
    #endif
    
    if (p[0] == 'B' && p[1] == 'M')
        return GDI_IMAGE_TYPE_BMP;

    if (p[0] == 'G' && p[1] == 'I' && p[2] == 'F')
        return GDI_IMAGE_TYPE_GIF;

    if (p[0] == 0xff && p[1] == 0xd8 && p[2] == 0xff)
        return GDI_IMAGE_TYPE_JPG;

    if (memcmp((void*)p, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)
        return GDI_IMAGE_TYPE_PNG;

    return (GDI_IMAGE_TYPE_INVALID);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_mem
 * DESCRIPTION
 *  check gdi decoder's capability
 * PARAMETERS
 *  ptr        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_type_from_mem(PS8 ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_type_from_mem)
    GDI_RETURN(gdi_image_get_type_from_mem_internal((U8*)ptr));
    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_type_from_mem)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_file_internal
 * DESCRIPTION
 *  get image type from file
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_type_from_file_internal(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 type;
    U16 *ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* null string */
    if (file_name == NULL)
    {
        return (GDI_IMAGE_TYPE_INVALID);
    }

    /* search the '.' from end of file_name */
    {
        U16 *pos = (U16*) file_name;

        ext = NULL;
        while (*pos != 0)
        {
            if (*pos == L'.')
            {
                ext = pos + 1;
            }
            pos++;
        }
    }

    if (ext)    /* have ext name */
    {
		for(type=1;type<GDI_IMAGE_TYPE_SUM;type++)
			if(gdi_image_codecs[type].is_match_file_type)
				if(gdi_ucs2_stricmp((U16*)ext,(U16*)(gdi_image_ext_name[type]+1))==0)
					if(gdi_image_codecs[type].is_match_file_type((U8*)file_name))
						return type;
    }

	// try again without ext information
	for(type=1;type<GDI_IMAGE_TYPE_SUM;type++)
		if(gdi_image_codecs[type].is_match_file_type)
			if(gdi_image_codecs[type].is_match_file_type((U8*)file_name))
				return type;

    return (GDI_IMAGE_TYPE_INVALID);

#undef IC
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 gdi_image_get_type_from_file(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_type_from_file)
    GDI_RETURN(gdi_image_get_type_from_file_internal(file_name));
    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_type_from_file)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_ext_name_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
const U16 *gdi_image_get_ext_name_from_file(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_ext_name_from_file)
    GDI_RETURN_TYPE(const U16 *, gdi_image_ext_name[gdi_image_get_type_from_file_internal(file_name)]);

    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_ext_name_from_file)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_ext_name_from_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *gdi_image_get_ext_name_from_file_type(U16 file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_ext_name_from_file_type)
    GDI_ASSERT(file_type < GDI_IMAGE_TYPE_SUM);
    GDI_RETURN_TYPE(const U16 *, gdi_image_ext_name[file_type]);

    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_ext_name_from_file_type)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_output_another_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable      [IN]        
 *  src         [?]         
 *  size        [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_output_another_buffer(BOOL enable, U8 *src, U32 size, U16 width, U16 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_output_another_buffer)
#ifdef GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER
    gdi_memory_output = enable;
    gdi_memory_output_width = width;
    gdi_memory_output_height = height;
    gdi_memory_output_buffer_size = size;
    gdi_memory_output_buffer_address = (U32) src;
    GDI_RETURN(GDI_SUCCEED);
#else /* GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER */ 
    GDI_RETURN(GDI_FAILED);
#endif /* GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER */ 
    GDI_EXIT_CRITICAL_SECTION(gdi_image_output_another_buffer)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type
 * DESCRIPTION
 *  check gdi decoder's capability
 * PARAMETERS
 *  image_id        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_buf_type(U8 * image_ptr)
{
    if (image_ptr == NULL)
        return GDI_IMAGE_TYPE_INVALID;

    return (U16) image_ptr[0];
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_buf_len
 * DESCRIPTION
 *  
 *****************************************************************************/
S32 gdi_image_get_buf_len(U8* res_src)
{
	U8* data_ptr;
	U8   img_type;
	S32 img_size;
	S32 frame_number;
	S32 width;
	S32 height;

    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_buf_len);
	gdi_image_parse_resource_internal(res_src, &data_ptr, &img_type, &img_size, &frame_number, &width, &height);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_buf_len);
    
	return img_size;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_buf_ptr
 * DESCRIPTION
 *  
 *****************************************************************************/
U8 *gdi_image_get_buf_ptr(U8* res_src)
{
	U8* data_ptr;
	U8   img_type;
	S32 img_size;
	S32 frame_number;
	S32 width;
	S32 height;

    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_buf_ptr);
	gdi_image_parse_resource_internal(res_src, &data_ptr, &img_type, &img_size, &frame_number, &width, &height);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_buf_ptr);
	
	return data_ptr;
}

void gdi_image_set_encoding_flag(U32 flag)
{
    gdi_image_encoding_flag = flag;
}
GDI_RESULT gdi_image_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_encode_layer_to_jpeg)
#if defined(GDI_USING_JPEG_ENCODE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    img_encode_struct encode_data;
    S32 image_width;
    S32 image_height;
    PU8 image_ptr;
    U32 file_size;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&image_width, &image_height);
    gdi_layer_get_buffer_ptr(&image_ptr);
    gdi_layer_pop_and_restore_active();

    encode_data.image_width = image_width;
    encode_data.image_height = image_height;

    encode_data.image_quality = CAM_JPG_QTY_HIGH;
    encode_data.image_buffer_p = (void*)image_ptr;
    encode_data.image_buffer_size = (image_width * image_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;

    encode_data.target_width = image_width;
    encode_data.target_height = image_height;
    encode_data.media_mode = MED_MODE_FILE;
    encode_data.media_type = MED_TYPE_JPG;

    encode_data.data = (void*)file_name;
    encode_data.file_size_p = (kal_uint32*) & file_size;
    encode_data.blocking = (kal_bool) TRUE;         /* blocking */
    encode_data.seq_num = (kal_uint16) 0;           /* not used */
    encode_data.file_buffer_len = (kal_uint32) 0;   /* not used */
    encode_data.gray_mode = 0;

#ifdef JPEG_ENCODE_THUMBNAIL_MODE

    if(gdi_image_encoding_flag & GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_GRAY)
        encode_data.jpeg_yuv_mode = JPEG_FORMAT_GRAY;
    else if(gdi_image_encoding_flag & GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_442)
        encode_data.jpeg_yuv_mode = JPEG_FORMAT_YUV422;
    else
        encode_data.jpeg_yuv_mode = JPEG_FORMAT_YUV420;
    
    gdi_image_encoding_flag = 0; // reset to default flag
    
    encode_data.thumbnail_mode = FALSE;
    encode_data.overlay_frame_mode = FALSE;
#endif 

    ret = media_img_encode(stack_int_get_active_module_id(), &encode_data);

    if (ret == MED_RES_OK)
    {
        GDI_RETURN(GDI_SUCCEED);
    }
    else if (ret == MED_RES_DISC_FULL)
    {
        GDI_RETURN(GDI_IMAGE_ENCODER_ERR_DISK_FULL);
    }
    else if (ret == MED_RES_WRITE_PROTECTION)
    {
        GDI_RETURN(GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION);
    }
    else if (ret == MED_RES_NO_DISC)
    {
        GDI_RETURN(GDI_IMAGE_ENCODER_ERR_NO_DISK);
    }
    else
    {
        GDI_RETURN(GDI_FAILED);
    }

#else
    GDI_RETURN(GDI_FAILED);
#endif
    GDI_EXIT_CRITICAL_SECTION(gdi_image_encode_layer_to_jpeg)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_file_to_jpeg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_file_name       [?]         
 *  dest_file_name      [?]         
 *  dest_width          [IN]        
 *  dest_height         [IN]        
 *  buf_ptr             [?]         
 *  buf_size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_encode_file_to_jpeg(
            S8 *src_file_name,
            S8 *dest_file_name,
            S32 dest_width,
            S32 dest_height,
            U8 *buf_ptr,
            S32 buf_size)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_encode_file_to_jpeg)
    GDI_RESULT result = GDI_FAILED;
#if defined(GDI_USING_JPEG_ENCODE)
    gdi_handle dest_layer;

    if (buf_size > GDI_IMAGE_ENCODER_JPEG_RESIZER_UPPER_BOUND)
    {
        GDI_RETURN(GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH);
    }

    ASSERT(buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(0, 0, dest_width, dest_height, &dest_layer, (PU8) buf_ptr, (S32) buf_size);
    gdi_layer_push_and_set_active(dest_layer);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_image_clear_work_buffer();
    do
    {
        result = gdi_image_draw_resized_file(0, 0, dest_width, dest_height, src_file_name);
        if (GDI_SUCCEED != result) break;

        result = gdi_image_encode_layer_to_jpeg(dest_layer, dest_file_name);
    } while(0);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(dest_layer);
#endif
    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_encode_file_to_jpeg)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_parse_mem_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res_src         [?]         
 *  data_ptr        [IN]        
 *  img_type        [?]         
 *  img_size        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_parse_mem_internal(U8 *res_src, U8 **data_ptr, U8 *img_type, S32 *img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U8* src;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *img_type = res_src[0];

    switch (*img_type)
    {
        case GDI_IMAGE_TYPE_AVATAR:
            *data_ptr = res_src;
            *img_size = 
                 (S32) (res_src[4]) 
               | (S32) ((S32) res_src[5] << 8) 
               | (S32) ((S32) res_src[6] << 16) 
               | (S32) ((S32) res_src[7] << 24);
            break;
        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_M3D:
        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
            *data_ptr = res_src + 8;
            break;
	    case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
	    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
        case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
	    	*img_size = (((S32)res_src[2])<<16)  |  (((S32)res_src[3])<<8)  |  (((S32)res_src[4]));
    		*data_ptr = res_src;
		    break;
        default:
            *data_ptr = res_src + 6;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_parse_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  data_ptr        [IN]        
 *  img_type        [?]         
 *  img_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_parse_info(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 **data_ptr,
            U8 *img_type,
            S32 *img_size,
            S32 *frame_number,
            S32 *width,
            S32 *height)
{
    *width = *height = *frame_number = -1;

    if (img_src == NULL)
        return (GDI_IMAGE_ERR_NULL_IMG_PTR);

    /* Detect image type if unknown */
    *data_ptr = img_src;    /* default data is from begin of img_src */
    switch (src_type)
    {
        case GDI_IMAGE_SRC_FROM_RESOURCE:
            gdi_image_parse_resource_internal(img_src, data_ptr, img_type, img_size,frame_number,width,height);
            break;
        case GDI_IMAGE_SRC_FROM_RESOURCE_WITHOUT_HEADER:
        case GDI_IMAGE_SRC_FROM_MEMORY:
            if (*img_type == GDI_IMAGE_TYPE_INVALID)
            {
                return (GDI_IMAGE_ERR_INVALID_IMG_TYPE);
            }
            else if (*img_type == GDI_IMAGE_TYPE_AVATAR)
            {
                gdi_image_parse_mem_internal(img_src, data_ptr, img_type,img_size);
            } 
            break;
        case GDI_IMAGE_SRC_FROM_FILE:
            if (*img_type == GDI_IMAGE_TYPE_INVALID)
            {
                *img_type = (U8)gdi_image_get_type_from_file_internal((S8*) img_src);
            }
            break;
        default:
            GDI_ASSERT(0);  /* unknown src type */
    }
    return (GDI_SUCCEED);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_get_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  img_type        [IN]        
 *  img_size        [IN]        
 *  width           [?]         
 *  height          [?]         
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_codec_get_dimension(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 *width,
            S32 *height,
            U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_codec_get_dimension)
    U8 *data_ptr;
    GDI_RESULT ret;
    S32 tmp;
    const gdi_image_codecs_struct *codec;

    ret = gdi_image_parse_info(src_type, img_src, &data_ptr, &img_type, &img_size, &tmp, width, height);
    
    if (ret != GDI_SUCCEED) GDI_RETURN(ret);
    
    if(*width ==-1 && *height ==-1)
    {
	    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
	        GDI_RETURN(GDI_IMAGE_ERR_INVALID_IMG_TYPE);
	
	    codec = &gdi_image_codecs[img_type];
	
	    if (src_type == GDI_IMAGE_SRC_FROM_FILE)
	        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
        else if(src_type == GDI_IMAGE_SRC_FROM_MEMORY)
            flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
	
	    ret = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
	    *width = *height = 0;
        gdi_image_codec_set_flag_begin(flag);
	    if (codec->get_dimension)
	        ret = codec->get_dimension(flag, data_ptr, img_size, width, height);
        gdi_image_codec_set_flag_end();
	}    
    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_codec_get_dimension)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_get_frame_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  img_type        [IN]        
 *  img_size        [IN]        
 *  frame_count     [?]         
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_codec_get_frame_count(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 *frame_count,
            U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_codec_get_frame_count)
    U8 *data_ptr;
    S32 tmp1,tmp2;
    GDI_RESULT ret;
    const gdi_image_codecs_struct *codec;
    gdi_anim_pos_type_enum pos_type;

    ret = gdi_image_parse_info(src_type, img_src, &data_ptr, &img_type, &img_size,frame_count,&tmp1,&tmp2);
    if (ret != GDI_SUCCEED) GDI_RETURN(ret);

    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
        GDI_RETURN(GDI_IMAGE_ERR_INVALID_IMG_TYPE);

	if(*frame_count==-1)
	{
	    codec = &gdi_image_codecs[img_type];
	
	    if (src_type == GDI_IMAGE_SRC_FROM_FILE)
	        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
        else if(src_type == GDI_IMAGE_SRC_FROM_MEMORY)
            flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
	    gdi_image_codec_set_flag_begin(flag);
	    ret = GDI_SUCCEED;  /* normal is single frame if no decoder */
	    if (codec->get_pos_info)
	        ret = codec->get_pos_info(flag, data_ptr, img_size, FALSE, frame_count, &pos_type);
	    else
	        *frame_count = 1;
        gdi_image_codec_set_flag_end();
	}
    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_codec_get_frame_count)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  img_type        [IN]        
 *  img_size        [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 *  flag            [IN]        
 *  frame_pos       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_codec_draw(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U32 flag,
            U32 frame_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_codec_draw)
    U8 *data_ptr;
    GDI_RESULT ret,ret1;
    const gdi_image_codecs_struct *codec;
	U32 start_time, end_time;
    U32 decode_ms = 0;
    U32 delay_time = 0;
	S32 tmp;

    MMI_TRACE(GDI_TRC, GDI_TRC_1,//"******* gdi_image_codec_draw PRE type=%d src=%d size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d"
        src_type,img_src,img_size,x,y,w,h,flag,frame_pos);
    ret = gdi_image_parse_info(src_type, img_src, &data_ptr, &img_type, &img_size,&tmp,&tmp,&tmp);
    if (ret != GDI_SUCCEED)
    {
        GDI_RETURN(ret);
    }

    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
    {
        GDI_RETURN(GDI_IMAGE_ERR_INVALID_IMG_TYPE);
    }
    MMI_TRACE(GDI_TRC, GDI_TRC_2,//"gdi_image_codec_draw image type=%d src=%d size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d"
            img_type,img_src,img_size,x,y,w,h,flag,frame_pos);

    codec = &gdi_image_codecs[img_type];

    if (src_type == GDI_IMAGE_SRC_FROM_FILE)
        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
    else if(src_type == GDI_IMAGE_SRC_FROM_MEMORY)
        flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;

    ret = GDI_SUCCEED;

    kal_get_time(&start_time);
    gdi_image_codec_set_flag_begin(flag);
    gdi_image_set_timeout(GDI_IMAGE_CODEC_TIMEOUT);
    
    gdi_image_set_update_area(x,y,x+w,y+h);

    if (codec->draw_before)
        if ((flag & GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_BEFORE) == 0)
        {
            ret = codec->draw_before(flag, frame_pos, x, y, w, h, data_ptr, img_size);
            if(ret < GDI_SUCCEED && gdi_image_is_abort()) 
                ret = GDI_ERR_NB_ABORT;
        }
    if (ret >= GDI_SUCCEED)
    if (codec->draw)
        if ((flag & GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW) == 0)
        {
            ret = codec->draw(flag, frame_pos, x, y, w, h, data_ptr, img_size);
            if(ret < GDI_SUCCEED && gdi_image_is_abort()) 
                ret = GDI_ERR_NB_ABORT;
        }

    if (codec->draw_after)
        if ((flag & GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_AFTER) == 0)
        {
            ret1 = codec->draw_after(flag, frame_pos, x, y, w, h, data_ptr, img_size);
            if (ret >= GDI_SUCCEED && ret1 <GDI_SUCCEED)
                ret =ret1;
            if(ret < GDI_SUCCEED && gdi_image_is_abort()) 
                ret = GDI_ERR_NB_ABORT;
        }

    gdi_image_clear_timeout();
    gdi_image_codec_set_flag_end();
    gdi_image_set_progress_callback(NULL,NULL);
    gdi_image_set_abort(FALSE);
    gdi_nb_set_high_priority(FALSE);
    
    kal_get_time(&end_time);
    decode_ms = kal_ticks_to_milli_secs(end_time - start_time);

    delay_time = gdi_anim_get_delay();
    if (delay_time < decode_ms)
    {
        gdi_anim_set_delay(1);
    }
    else
    {
        gdi_anim_set_delay(delay_time - decode_ms);
    }
    MMI_TRACE(GDI_TRC, GDI_TRC_3,//"------- decode time=%d delay time=%d ret=%d", 
                decode_ms, delay_time,ret);
    
    if(GDI_DEBUG_FLAG == GDI_DEBUG_FLAG_IMAGE_DUMP)
    {
        U16 tmp_name[48];
        kal_wsprintf(tmp_name, "%s%03d.jpg", GDI_DEBUG_ARG,GDI_DEBUG_CNT++);
        gdi_layer_save_pbm_file((gdi_handle)gdi_act_layer, (S8*)tmp_name);
    }

#if defined(GDI_IMAGE_PROFILE)
    if (
    #if (defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) && defined(__MTK_TARGET__)
        NFB_SecondaryImageLoaded && 
    #endif 
        mmi_frm_profiling_gdi_profile_is_enabled()
        )
    {
        if (src_type == GDI_IMAGE_SRC_FROM_FILE)
        {
            app_ucs2_str_to_asc_str((kal_int8*)gdi_work_buffer, (kal_int8*)img_src);
        }
        else
        {
            kal_sprintf((S8*)gdi_work_buffer, "Img Address : 0x%x.", (U32)img_src);
        }
        PRINT_INFORMATION("file name : %s",gdi_work_buffer);
        if (0 == w && 0 == h)
        {
            gdi_image_codec_get_dimension(
                src_type,
                img_src,
                img_type,
                img_size,
                &w,
                &h,
                flag);
        }
        {
            int str_w, str_h;
            char *str_tmp = (char*)gdi_work_buffer;
            UI_character_type *str_buf = (UI_character_type*) gdi_work_buffer+32;
            color text_color = gui_color(255, 255, 255);
            gdi_color rect_frame_color = GDI_COLOR_WHITE;
            U32 r, g, b;
            
            if (decode_ms > 500)
            {
                r = 255;
                g = 0;
                b = 0;
            }
            else if (decode_ms > 300)
            {
                r = 255;
                g = 255 - (decode_ms - 300);
                b = 0;
            } 
            else if (decode_ms > 200)
            {
                r = 255;
                g = 255 - (decode_ms - 200);
                b = 255 - (decode_ms - 200);
            }
            else if (decode_ms > 100)
            {
                r = 0;
                g = 255;
                b = 255 - (decode_ms - 100);
            }
            else
            {
                r = 255;
                g = 255;
                b = 255 - decode_ms;
            }
            text_color = gui_color((U8)r, (U8)g, (U8)b);
            rect_frame_color = gdi_act_color_from_rgb(255, r, g, b);
            gui_set_text_color(text_color);
            gdi_layer_reset_clip();
            kal_sprintf(str_tmp, "%d.", decode_ms);
            mmi_asc_to_ucs2((char*)str_buf, str_tmp);
            gui_measure_string((UI_string_type) str_buf, &str_w, &str_h);
            gdi_draw_rect(x, y, x + w - 1, y + h - 1, rect_frame_color);
            if (str_h < h)
            {
                y = y + ((h - str_h)>> 1);
            }
            gdi_draw_solid_rect(x, y, x + str_w - 1, y + str_h - 1, GDI_COLOR_BLACK);

            gui_move_text_cursor(x, y);
            gui_print_text(str_buf);
        }
    }
#endif
    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_codec_draw)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_clear_work_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_clear_work_buffer(void)
{
#if defined(GDI_USING_LAYER)
    gdi_memset16((U8*)gdi_work_buffer,0xffff,gdi_work_buffer_size);
#endif
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_estimate_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/

U32 gdi_image_estimate_decoding_time(U8 img_type,S32 width,S32 height)
{
    U32 ms=0;
    switch(img_type)
    {
    case GDI_IMAGE_TYPE_DEVICE_BITMAP:
    default:
        ms = 300;
        break;
    }
    ms *= width*height;
    ms /=176*220;

    #if defined(MCU_13M)
        ms = ms *52/13;
    #elif defined(MCU_26M)
        ms = ms *52/26;
    #elif defined(MCU_39M)
        ms = ms *52/39;
    #elif defined(MCU_52M)
        ms = ms;
    #elif defined(MCU_104M)
        ms = ms *52/104;
    #else
        ms = ms *52/122; //It should be fast enough, should not detect higher CPU .. #error "Unknown MCU clock"
    #endif
    return ms;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_estimate_show_fullscreen_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/

U32 gdi_image_estimate_show_fullscreen_time(void)
{
    return gdi_image_estimate_decoding_time(GDI_IMAGE_TYPE_DEVICE_BITMAP,GDI_LCD_WIDTH,GDI_LCD_HEIGHT);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_nb_set_callback
 * DESCRIPTION
 *  settint the callback for non-blocking job
 *****************************************************************************/
void gdi_nb_set_blt(BOOL is_blt,BOOL is_progress)
{
    if(!is_blt)
        gdc_job_set_parameter(GDC_JOB_IS_NO_BLT,-1,NULL,NULL,NULL,NULL);
    else if(is_progress)
        gdc_job_set_parameter(GDC_JOB_IS_PROGRESS_BLT,-1,NULL,NULL,NULL,NULL);
}

void gdi_nb_set_anim_before_frame_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{
    gdc_job_set_parameter(0,-1,callback,NULL,NULL,NULL);
}
void gdi_nb_set_anim_after_frame_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{
    gdc_job_set_parameter(0,-1,NULL,callback,NULL,NULL);
}
void gdi_nb_set_anim_last_frame_callback(void (*callback)(GDI_RESULT result))
{
    gdc_job_set_parameter(0,-1,NULL,NULL,callback,NULL);
}
void gdi_nb_set_done_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{
    gdc_job_set_parameter(0,-1,NULL,NULL,NULL,callback);
}
void gdi_nb_set_anim_count(S32 anim_count)
{
    gdc_job_set_parameter(0,anim_count,NULL,NULL,NULL,NULL);
}

void gdi_nb_set_high_priority(BOOL is_nb_first)
{
    gdi_nb_is_high_priority_flag = is_nb_first;
}
BOOL gdi_nb_is_high_priority(void)
{
    return gdi_nb_is_high_priority_flag;
}

gdi_handle gdi_image_nb_draw_internal(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag)
{
    gdi_handle job_handle;
    gdc_job_add_image(
                            src_type,
                            img_src,
                            img_type,
                            img_size,
                            x,
                            y,
                            w,
                            h,
                            img_flag,
                            frame_pos,
                            job_flag,
                            &job_handle);
    return job_handle;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_nb_stop
 * DESCRIPTION
 *  non-blocking draw resource image 
 *****************************************************************************/
GDI_RESULT gdi_image_nb_stop(gdi_handle handle)
{
    return gdc_job_del_image(handle);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_nb_stop_all
 * DESCRIPTION
 *  non-blocking draw resource image 
 *****************************************************************************/
GDI_RESULT gdi_image_nb_stop_all(void)
{
    return gdc_job_del_all();

}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_set_flag_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_codec_set_flag_begin(U32 flag)
{
    GDI_ASSERT(gdi_image_codec_flag_index < (sizeof(gdi_image_codec_flag_stack) / sizeof(U32)));
    GDI_LOCK;
    gdi_image_codec_flag_index++;
    gdi_image_codec_flag_stack[gdi_image_codec_flag_index] = gdi_image_codec_flag_stack[gdi_image_codec_flag_index - 1] | flag;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_set_flag_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_codec_set_flag_end(void)
{
    GDI_ASSERT(gdi_image_codec_flag_index > 0);
    gdi_image_codec_flag_index--;
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_get_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
U32 gdi_image_codec_get_flag(void)
{
    return gdi_image_codec_flag_stack[gdi_image_codec_flag_index];
}


void gdi_image_cache_reset(void)
{
    gdi_image_gif_reset();
    gdi_lfs_initialize();
}
void gdi_image_cache_reset_entry(U8* src,U32 size)
{
    gdi_image_gif_reset_entry(src,size);
    gdi_image_gif_reset_entry(src+8,size);     // from resource need skip 8 bytes header 
}


#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_load
 * DESCRIPTION
 *  load image data to single bank cache
 * PARAMETERS
 *  img_src         [IN]
 *  img_size        [IN]
 *  reloaded        [OUT]       whether data is reloaded (if FALSE, data was already in cache)
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_single_bank_cache_load(const U8 *img_src, S32 img_size, BOOL *reloaded)
{
    if (!img_src)
    {
        return GDI_FAILED;
    }

    if (img_src == gdi_image_single_bank_cache_src && 
        img_size == gdi_image_single_bank_cache_size)
    {
        if (reloaded)
        {
            *reloaded = FALSE;
        }
        return GDI_SUCCEED;
    }
    else
    {
        if (img_size > GDI_IMAGE_SINGLE_BANK_CACHE_SIZE)
        {
            return GDI_FAILED;
        }
        else
        {
            memcpy(gdi_image_single_bank_cache_buf, img_src, img_size);
            gdi_image_single_bank_cache_src = img_src;
            gdi_image_single_bank_cache_size = img_size;
            if (reloaded)
            {            
                *reloaded = TRUE;
            }
            return GDI_SUCCEED;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_get_buffer
 * DESCRIPTION
 *  Get the buffer pointer of single-bank cache
 * PARAMETERS
 *  void
 * RETURNS
 *  buffer pointer
 *****************************************************************************/
U8 *gdi_image_single_bank_cache_get_buffer(void)
{
    return (U8*) gdi_image_single_bank_cache_buf;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_reset
 * DESCRIPTION
 *  Reset single bank cache for image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_single_bank_cache_reset(void)
{
    gdi_image_single_bank_cache_src = NULL;
    gdi_image_single_bank_cache_size = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_reset_entry
 * DESCRIPTION
 *  Reset single bank cache for certain image
 * PARAMETERS
 *  img_src         [IN]
 *  img_size        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_single_bank_cache_reset_entry(const U8 *img_src, S32 img_size)
{
    (void) img_size; /* avoid warning */
    if (img_src == gdi_image_single_bank_cache_src) /* loose check without size checking */
    {
        gdi_image_single_bank_cache_reset();
    }
}


#endif /* GDI_USING_IMAGE_SINGLE_BANK_CACHE */

GDI_RESULT gdi_intram_malloc(U32 size,gdi_intram_type_enum *mem_type,U32 *mem_begin)
{
    *mem_type = GDI_INTRAM_TYPE_INVALID;
    *mem_begin = NULL;

    #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
    if(size <= MED_INT_STACK_MEM_SIZE && *mem_begin==NULL)
    {
        med_get_med_int_stack_mem(mem_begin);
        *mem_type = GDI_INTRAM_TYPE_MED_INT_STACK_MEM;
    }
    #endif

    
    return (*mem_begin)?GDI_SUCCEED:GDI_FAILED;
}

void gdi_intram_free(gdi_intram_type_enum mem_type,S32 mem_begin)
{
    if(mem_begin)
    {
        switch(mem_type)
        {
        #if defined(__SW_JPEG_CODEC_SUPPORT__) && !defined(WIN32)
        case GDI_INTRAM_TYPE_MED_INT_STACK_MEM:
            med_free_med_int_stack_mem();
            break;
        #endif

        default:
            break;
        }

    }
}


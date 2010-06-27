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
 *   widget.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Widget internal definition, configuration, and prototypes.
 *
 *   This file should "not" be included outside of widget library.
 *
 * Author:
 * -------
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
#ifndef _WIDGET_H_
#define _WIDGET_H_

/* common header files */
#include "stdarg.h"
#include "stdio.h"

/* kal header files */
#include "kal_release.h"        /* Basic data type */
#include "custom_config.h"      /* for MOD_WAP */
#include "stack_common.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "kal_active_module.h"  /* Get active module */
#include "fs_type.h"    /* Get virtual file information */

/* au system header files */
#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "Msf_env.h"
#include "msf_mem.h"
#include "msf_log.h"

/* pixtel header files */
#include "GlobalConstants.h"
#include "GlobalDefs.h"
#include "FrameworkStruct.h"
#include "EventsDef.h"
#include "HistoryGprot.h"
#include "wgui_inputs.h"        /* MMI_multiline_inputbox_XXX */
#include "DebugInitDef.h"       /* MMI logging */
#include "mmi_trc.h"

/* GDI */
#include "gdi_include.h"        /* For GDI_USING_HW_JPEG, etc. */
#include "gdi_datatype.h"

/* fmt datat type */
#include "fmt_def.h"

/* Wap/MMI interface */
#include "WapProt.h"
#include "mmiapi_func.h"
#include "brs_cfg.h"

/* Wap adaptation definition */
#include "wapadp.h"

/************************************************************************
 * Debug/Experimental Configuration                                           
 ************************************************************************/

/* Because wapadp is not branched out */
#define WIDGET_EXPERIMENTAL_FEATURE

/* Press '*' to enter unit test */
#undef WIDGET_UNIT_TEST
#undef WIDGET_TEST_CHINESE_TEXT_INPUT

/* Press '#' to simulate the Out-Of-Memory error */
#undef WIDGET_TEST_OUT_OF_MEMORY

/* Verbose debugging */
#undef WIDGET_VERBOSE_DEBUG

/* Performance profiling */
#undef WIDGET_PROFILING

/************************************************************************
 * Common Configuration                                           
 ************************************************************************/


#ifdef __MMI_DUAL_SIM__
#define WIDGET_DUAL_SIM_SUPPORT
#endif


#if defined (GUI_SUBMENU_SHOW_STATUS_ICON) && !defined(WIDGET_LANDSCAPE_STYLE)
/* Resident status icons bar on top of titlebar  */
#define WIDGET_RESIDENT_STATUS_ICON
#endif /* defined (GUI_SUBMENU_SHOW_STATUS_ICON) && !defined(WIDGET_LANDSCAPE_STYLE) */ 

/*
 * Allocate widget objects by owner modules instead  of MSF_MODID_WIDGET 
 * * If we want to use ASM for MEA/BRS module, we should allocate widget objects
 * * by each individual module.
 */
#define WIDGET_MALLOC_IN_OWNER_MODULE

#ifdef GDI_USING_HW_JPEG
#define WIDGET_JPEG_SUPPORT
#if !defined(MT6205B) && !defined(MT6218) && !defined(MT6218B) && !defined(MT6217)
/* Display JPEG image of any size */
#define WIDGET_SUPPORT_LARGE_JPEG
#else /* !defined(MT6205B) && !defined(MT6218) && !defined(MT6218B) && !defined(MT6217) */ 
#undef WIDGET_SUPPORT_LARGE_JPEG
#endif /* !defined(MT6205B) && !defined(MT6218) && !defined(MT6218B) && !defined(MT6217) */ /* After MT6219 */
#endif /* GDI_USING_HW_JPEG */ 


/* support zoom-in to view the image */
#define WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE


#if defined(__MMI_NONBLOCKING_DECODE__)
/*
 * If MCU power is low and spend a lot of time to decode the image,
 * we support draw the image in non-blocking method.
 * But we don't support zoom-in to view the image
 */
#undef WIDGET_SUPPORT_DRAW_ENLARGE_IMAGE
#define WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
/* in nonblocking image drawing, we need widget precache mechanism to cache the image */

#ifndef WIDGET_PRECACHE_IMAGE
#define WIDGET_PRECACHE_IMAGE
#endif

#endif /* #if defined(MT6223P) && defined(MT6223) */


#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
/* Resident status icons bar on top of titlebar  */
#define WIDGET_RESIDENT_STATUS_ICON
#endif /* GUI_SUBMENU_SHOW_STATUS_ICON */ 

/* Temp patch for dynamic list of MEA (task synchronization with MMI task) */
#define WIDGET_TMPFIX_DYNAMIC_LIST

/*
 * Marqueeing is implemented with  drawing on MsfImage inside of a MsfImageGadget
 * configured with HDIa_widgetSetMarquee().
 *
 * Obigo framework assumes that MsfImage contains an memory buffer to drawed image.
 * However, we can not afford so much memory. As a result, we en-queue the drawing 
 * operations inside the MsfImage widget. 
 *
 * However, there is some troubles here. First, BRS will change the background color of 
 * the MsfImage (different from background color of web page). Second, the background color
 * of the MsfString drawn is also changed. 
 *
 * In order to solve this, we disable background color of MsfString, disable
 * HDIa_widgetDrawRect in marquee, and use the background color of MsfImageGadget to 
 * draw marquee background.
 *
 */
#define WIDGET_TMPFIX_MARQUEE_BGCOLOR

/* Reduce the memory used when HDIa_widgetDrawXXX on a MsfImage.
   This compile option will be removed after the change is proved stable. */
#define WIDGET_COMPACT_IMAGE_DRAW_OP

/*
 * Drop all keypad events after MsfAction is fired. 
 * * It will re-configure keypad handler after widget_paint_hdlr() 
 * * Some issues are known.
 */
#define WIDGET_DROP_KEY_ON_ACTION_SIGNALED         1

#define WIDGET_ENABLE_TRANSITION_ANIMATION

/* Optimization on runtime data structure. 
   This compile option will be removed after the change is proved stable. */
#define WIDGET_COMPACT_RUNTIME_STRUCT              1

/****************************
 * Experimental features
 ****************************/

/* Store each style of HDIa_widgetDrawRect on MsfImage */
#define WIDGET_DRAW_RECT_STORE_STYLE

/* Leave fullscreen editor if the corresponding MsfEditor/MsfInputGadget is released */
#define WIDGET_LEAVE_EDITOR_IF_RELEASED

#if !defined(WIDGET_SUPPORT_LARGE_JPEG)
/* Because MT6217/MT6218 has JPEG image size limitation due to memory restrction.
   We need to shrink the JPEG image in order to display it. */
#define WIDGET_BROWSER_AUTORESIZE_JPEG
#endif /* !defined(WIDGET_SUPPORT_LARGE_JPEG) */ 

/* gdi_layer_flatten_with_clipping is faster than copying image data by MCU, but it is not supported 
   on Simulator yet. */
#if 0   /* !defined(WIN32) */
/* under construction !*/
#else /* 0 */ 
#undef WIDGET_USE_LAYER_FLATTEN_WITH_CLIPPING
#endif /* 0 */ 

/*
 * Cache the result of HDIa_widgetStringGetVisible by HDIa_widgetExtStringSetCacheGetVisible 
 * * Useful with touch screen (we can use pen to scroll from top to bottom or vice versa) 
 */
#define WIDGET_STRING_GET_VISIBLE_USE_CACHE
#ifdef __MMI_TOUCH_SCREEN__
/*
 * On 176x220 screen with SMIL msg of  all chinese characters (14x14), 
 * it takes 60 cache items (10 chars/line)
 * 256 cache items should be enough for most cases. 256 * 16 bytes = 4KB
 */
#define WIDGET_STRING_GET_VISIBLE_CACHE_NITEMS  256
#else /* __MMI_TOUCH_SCREEN__ */ 
/*
 * Without touch panel, SMIL scrolls 1 line one time. We do not need to cache too many items.
 */
#define WIDGET_STRING_GET_VISIBLE_CACHE_NITEMS  64
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef WIDGET_EXPERIMENTAL_FEATURE

/* Declaration of experimental features */

#endif /* WIDGET_EXPERIMENTAL_FEATURE */ 

/****************************
 * Compile options related to memory reduction 
 ****************************/

/* Reduce memory for predefined MsfImage */
#define WIDGET_COMPACT_PRE_IMAGE          1
/* Reduce memory for predefined MsfString */
#define WIDGET_COMPACT_PRE_STRING         1
/* Put predefined MsfString into RO section instead of ZI section */
#define WIDGET_RO_PRE_STRING              1
/* Internal memory optimization
   This compile option will be removed after the change is proved stable. */
#define WIDGET_USE_MMI_ICONTEXT_MENU      1

#if defined(WIDGET_RO_PRE_STRING) && !defined(WIDGET_COMPACT_PRE_STRING)
#error "compile option dependency fail"
#endif 

/****************************
 * Compile options that should stay unchanged
 ****************************/

/* Device capability */
#ifdef __MMI_TOUCH_SCREEN__
#define WIDGET_HAVE_TOUCH_SCREEN          KAL_TRUE
#else 
#define WIDGET_HAVE_TOUCH_SCREEN          KAL_FALSE
#endif 

#define WIDGET_HAVE_DRAG_ABILITY          KAL_FALSE

/* Memory allocator */
#undef  USING_WINDOWS_MALLOC
#undef  USING_CONTROL_BUFFER
#define USING_OBIGO_MALLOC

/* Whether to skip wrong bytes of an UTF-8 string */
#define WIDGET_UTF8_FAULT_TOLERANT        1

/* UTF-8 allow to decode Byte-Order-Marker (BOM) */
#define WIDGET_UTF8_ALLOW_BOM             1

/* Internal text encoding. This should "not" be changed directly. */
#define WIDGET_ENCODING                   ((MsfStringFormat)MsfUcs2)

// TODO: GDI should provide global definition for it
#define WIDGET_MMI_PREIMAGE_OFFSET        (6)
#define WIDGET_MMI_PREIMAGE_OFFSET_GIF    (8)

/* Working buffer when creating an image/sound from file/pipe */
#ifdef LOW_COST_SUPPORT
#define WIDGET_LOAD_BUFFER_SIZE  1024
#else 
#define WIDGET_LOAD_BUFFER_SIZE  2048
#endif 

/************************************************************************
 * Widget Common Header
 ************************************************************************/

#include "widget_extension.h"
#include "widget_datatype.h"
#include "wap.h"

/******************************************************************************
 * Internal configuration and MACRO
 ******************************************************************************/

#ifdef __MTK_TARGET__
#define printf                CAN_NOT_USE_PRINTF        /* Unsupported in ADS library */
#endif 

#define WIDGET_LOG_GROUP         (TRACE_GROUP_2)

#ifdef __MTK_TARGET__

  #ifndef __PRODUCTION_RELEASE__
    #define WIDGET_LOG          kal_trace
  #else /* __PRODUCTION_RELEASE__ */ 
    /* KAL may define kal_trace to be NULL on the target, but PC compiler doesn't know (...) in the macro */
    #define WIDGET_LOG(...)        
  #endif /* __PRODUCTION_RELEASE__ */ 

#else /* __MTK_TARGET__ */ 

    /* KAL always has kal_trace() on PC simulator */
    #define WIDGET_LOG          kal_trace

#endif /* __MTK_TARGET__ */ 

/* static resource */
/* Default size of widget_header_struct.childs. Tradeoff between performance and space. */
#define WIDGET_BASIC_LINK_SIZE               4

/* Maximum number of source file for loading image/sound */
#define MAX_WIDGET_FILE_NOTIFY_SUM           10

/* Maximum number of source pipe for loading image/sound */
#define MAX_WIDGET_PIPE_NOTIFY_SUM           10

/* receiving data from pipe WIDGET_PIPE_DELAY_COUNTER timew will break to avoid MMI task is starving when WAP and WPS download data in high speed */
#define WIDGET_PIPE_DELAY_COUNTER			(10)

/*
 * Maximum number of images that can be created.
 * * XHTML web pages can easily exceed 10 animated images
 * * msf_dlg, and msf_sas might use about 10 images when SMA module is active
 */
#define MAX_WIDGET_CREATED_IMAGE_SUM         (40)

/* Maximum number of sound that can be created. */
#define MAX_WIDGET_CREATED_SOUND_SUM         (10)

/* Maximum number of rawfile */
#define MAX_WIDGET_CREATED_RAWFILE_SUM \
      (MAX_WIDGET_CREATED_IMAGE_SUM+MAX_WIDGET_CREATED_SOUND_SUM)

/* Maximum queued key */
#define WIDGET_KEY_QUEUE_SIZE                (64)

#if defined(WIN32)
//Huyanwei Add It For PC 
#define HDI_EXTERNAL_LEN 256

#endif
/* widget won't create image/sound resource file in wcache. The application will handle the situation when the resource files are removed. */
#define WIDGET_RAWFILE_NAMELEN               (HDI_EXTERNAL_LEN+256)

#define WIDGET_RESERVE_FILENAME              (WIDGET_RAWFILE_DIRECTORY "reserve.dat")


#define WIDGET_VIRTUAL_SCREEN_ID             (0xA0A0)

/* Check the image in detail (not only check the dimension) */
#if !defined(MT6223) && !defined(MT6223P)
/* MT6223 serial is low cost project and will have poor performance when enable this feature */
#define WIDGET_CHECK_IMAGE_IN_DETAIL
#endif


// TODO: use FS_GetDiskInfo() to retrieve real value
/* NOR flash: 512. Other flash device: 1024, 4096. */
 /* Larger cluster size produces better performance but increases the chance of race condition */
#ifndef __MTK_TARGET__
#define WIDGET_CLUSTER_SIZE                  (2048)
#else 
#define WIDGET_CLUSTER_SIZE                  (512)
#endif 

#ifdef __DRM_V01__

/*
 * DRM version 2 can save a file at any path, but DRM version 1 need to save it 
 * * in a tmp folder and move it to Z:\@DRM later.
 * * Note that the tmp folder Z:\drm_dnl will be re-created at boot and each time 
 * * when we download a DRM object.
 */

#define WIDGET_DRM_TMP_FOLDER_MSF            "/external/Z:\\drm_dnl\\"
#define WIDGET_DRM_TMP_FOLDER_UCS2           (L"Z:\\drm_dnl\\")

#endif /* __DRM_V01__ */ 

/* It does not count in terminating zero ('\0') */
#define WIDGET_MAX_INPUT_LEN                 120
#define WIDGET_MAX_TITLE_LEN                 64

/* Filter out abnormal images */
#define WIDGET_IMAGE_MAX_WIDTH               1280
#define WIDGET_IMAGE_MAX_HEIGHT              1280

/* Filter out too large images in resizing procedure */
#define WIDGET_IMAGE_MAX_WIDTH_IN_RESIZING   2048
#define WIDGET_IMAGE_MAX_HEIGHT_IN_RESIZING  2048


#define WIDGET_SCROLL_UP_SIZE                (MMI_content_height/4)
#define WIDGET_SCROLL_DOWN_SIZE              (MMI_content_height/4)
#define WIDGET_SCROLL_LEFT_SIZE              (MMI_content_width/4)
#define WIDGET_SCROLL_RIGHT_SIZE             (MMI_content_width/4)

/* Note. it will have cursor not cleared if height of multiline input box 
   < "font height" + b->text_y*2 */
#define WIDGET_DEFAULT_SINGLE_LINE_INPUT_WIDTH     (MMI_content_width*3/4)
#define WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT    (MMI_singleline_inputbox_height)

#define WIDGET_DEFAULT_MULTI_LINE_INPUT_WIDTH   (MMI_content_width*3/4)
// #define WIDGET_DEFAULT_MULTI_LINE_INPUT_HEIGHT  (MMI_content_height*2/3)
#define WIDGET_DEFAULT_MULTI_LINE_INPUT_HEIGHT  \
      WIDGET_DEFAULT_SINGLE_LINE_INPUT_HEIGHT


#define WIDGET_DEFAULT_DIALOG_X              (MMI_content_x)
#define WIDGET_DEFAULT_DIALOG_Y              (MMI_content_y)

#define WIDGET_DEFAULT_DIALOG_WIDTH          (MMI_content_width)
#define WIDGET_DEFAULT_DIALOG_HEIGHT         (MMI_content_height*3/4)

#define WIDGET_DEFAULT_SELECT_GROUP_WIDTH    (MMI_content_width*2/3 - BRS_CFG_LE_CSS_BODY_PADDING_PIXELS*2)
#define WIDGET_DEFAULT_SELECT_GROUP_HEIGHT   (MMI_content_height*2/3)



/* For drawing image in non-blocking */
#define WIDGET_MAX_NB_DRAW_IMAGE_NUM        (20)

#define WIDGET_DRAW_IMAGE_IN_BLOCKING       (0)
#define WIDGET_DRAW_IMAGE_IN_NONBLOCKING    (10)
#define WIDGET_NB_DRAW_IMAGE_FAIL           (-8000)

#define WIDGET_IMAGE_WIDTH_LIMITATION       (176)
#define WIDGET_IMAGE_HEIGHT_LIMITATION      (220)


#ifdef WIDGET_SLIDING_SMIL_SUPPORT

#if defined(WIDGET_LARGE_RESOLUTION)/* && !defined (WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING)*/
/* MMS viewer has title buttons and sliding bar */
#define WIDGET_SMIL_SLIDING_BAR
#define WIDGET_MMS_VIEWER_TITLE_WITH_BUTTON

#define WIDGET_SLIDING_SMIL_TOP              (3)

#else /* #if defined(WIDGET_LARGE_RESOLUTION) && !defined (WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING) */ 

#define WIDGET_MMS_VIEWER_TITLE_WITH_TIMESTAMP

#define WIDGET_SLIDING_SMIL_TOP              (1)

#endif /* #if defined(WIDGET_LARGE_RESOLUTION) && !defined (WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING) */ 

/* top & bottom padding must be the same */
#define WIDGET_SLIDING_SMIL_BOTTOM           (WIDGET_SLIDING_SMIL_TOP)

/* 
 * We don't reserve the border "WIDGET_SLIDING_SMIL_BORDER" of the image 
 * because MEA won't know this information. 
 */

#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 


#ifdef WIDGET_SMIL_SLIDING_BAR

#define WIDGET_SLIDING_BAR_REGION_HEIGHT  (MMI_content_height - WGUI_CTX->display_size.height)

#define WIDGET_SMIL_SLIDING_BAR_BG_R         (255)
#define WIDGET_SMIL_SLIDING_BAR_BG_G         (195)
#define WIDGET_SMIL_SLIDING_BAR_BG_B         (57)
#define WIDGET_SMIL_SLIDING_BAR_FG_R         (148)
#define WIDGET_SMIL_SLIDING_BAR_FG_G         (227)
#define WIDGET_SMIL_SLIDING_BAR_FG_B         (255)
#define WIDGET_SMIL_SLIDING_BAR_FRAME_R      (66)
#define WIDGET_SMIL_SLIDING_BAR_FRAME_G      (89)
#define WIDGET_SMIL_SLIDING_BAR_FRAME_B      (156)
#define WIDGET_SMIL_SLIDING_BAR_H_SPACE      (8)
#define WIDGET_SMIL_SLIDING_BAR_V_SPACE      (4)

#endif /* WIDGET_SMIL_SLIDING_BAR */ 

#define WIDGET_CURSOR_COLOR_R                170
#define WIDGET_CURSOR_COLOR_G                170
#define WIDGET_CURSOR_COLOR_B                170
#define WIDGET_CURSOR_COLOR_A                100

#define WIDGET_CURSOR_SHADOW_COLOR_R         120
#define WIDGET_CURSOR_SHADOW_COLOR_G         120
#define WIDGET_CURSOR_SHADOW_COLOR_B         120
#define WIDGET_CURSOR_SHADOW_COLOR_A         100

#define WIDGET_SMIL_BORDER_COLOR_R           200
#define WIDGET_SMIL_BORDER_COLOR_G           0
#define WIDGET_SMIL_BORDER_COLOR_B           0

#define WIDGET_WANT_FOCUS_LIST                              \
   (                                                        \
   0                                                        \
   |(1<<WIDGET_GADGET_INPUT_TYPE)                           \
   |(1<<WIDGET_GADGET_STRING_TYPE)                          \
   |(1<<WIDGET_GADGET_SELECT_GROUP_TYPE)                    \
   |(1<<WIDGET_GADGET_IMAGE_TYPE)                           \
   |(1<<WIDGET_ROOT_TYPE)  /* It might not be required */   \
   |(1<<WIDGET_SCREEN_TYPE)                                 \
   |(1<<WIDGET_PAINTBOX_TYPE)                               \
   |(1<<WIDGET_FORM_TYPE)                                   \
   |(1<<WIDGET_DIALOG_TYPE)                                 \
   |(1<<WIDGET_MENU_TYPE)                                   \
   |(1<<WIDGET_EDITOR_TYPE)                                 \
   |(1<<WIDGET_CTK_TYPE)                                    \
   )

/* Note that we check MSF_GADGET_PROPERTY_FOCUS for string gadget */
#define WIDGET_GADGET_WANT_FOCUS_LIST                    \
   (                                                     \
   0                                                     \
   |(1<<WIDGET_GADGET_INPUT_TYPE)                        \
   |(1<<WIDGET_GADGET_STRING_TYPE)                       \
   |(1<<WIDGET_GADGET_SELECT_GROUP_TYPE)                 \
   |(1<<WIDGET_GADGET_IMAGE_TYPE)                        \
   )

#define WIDGET_FONT_TOP_SPACING              (1)

#define WIDGET_FONT_BOTTOM_SPACING           (3)


/*
 * Timer period (milli-seconds) 
 * * Be careful if you want to change these values
 * * 
 * * The value of WIDGET_PAINT_DELAY_TIME is decided heuristically.
 * * If it is set too large, user might perceive delay in screen redraw.
 * * If it is set too smal, the screen might be redrawn for too many times.
 * * Please do complete test if you have to modify this value. 
 * *
 */
#define WIDGET_PAINT_DELAY_TIME              (5)	/* Original value is 100 */
// #define WIDGET_ANIMATE_DELAY_TIME                    600
#define WIDGET_GIF_ANIMATION_BASE_TIME       (100)
#define WIDGET_MESSAGBOX_DELAY_TIME          (1000)
#define WIDGET_PAINTBOX_REDRAW_DELAY_TIME    (5)
#define WIDGET_EXIT_DELAY_TIME               (250)        /* 2004.03.16 Original 500 */
#define WIDGET_BLINKING_DELAY_TIME           (1000)
#define WIDGET_MARQUEE_DELAY_TIME            (50)
/* Delay time of scrolling in SMIL to reduce scrolling computation  
   If customers want to modify this value, please test on a MMS message with largest text input. */
#define WIDGET_MMS_VIEWER_PEN_SCROLL_DELAY_TIME     (200)

#define WIDGET_PAINTBOX_SCROLL_INDICATION_DELAY_TIMER     (500)

/* add mechanism to avoid MMI task is starving when WAP and WPS download data in high speed */
#define WIDGET_PIPE_NOTIFY_DELAY_TIME        		(200)

/* Timer Id */
enum
{
    WIDGET_PAINT_TIMER,
    WIDGET_ANIMATE_TIMER,
    WIDGET_PAINTBOX_REDRAW_TIMER,
    WIDGET_EXIT_DELAY_TIMER,
    WIDGET_PAINT_COMMAND_TIMER,
    WIDGET_BLINKING_TIMER,
    WIDGET_MARQUEE_TIMER,
    WIDGET_MMS_VIEWER_SCROLL_TIMER,
    WIDGET_PAINTBOX_SCROLL_INDICATION_TIMER,
    WIDGET_PIPE_NOTIFY_DELAY_TIMER,
    WIDGET_MAX_TIMER
};

typedef enum
{
    WIDGET_CTK_STATE_NONE,
    WIDGET_CTK_STATE_PREPARE_TO_ENTER,
    WIDGET_CTK_STATE_ENTERED,
    WIDGET_CTK_STATE_PAUSED
} widget_ctk_state_enum;

typedef void (*widget_timer_func) (void *);
typedef struct
{
    eventid id;
    widget_timer_func callback;
    void *callback_arg;
} widget_timer_struct;

/* Misc. macros */

#define WIDGET_ALLOC_TYPE(_modid, _type) (_type*)(MSF_MEM_ALLOC(_modid,sizeof(_type)))

#define HAS_REF(w)   (_H(w)->parent_cnt!=0)

#define DEC_REF(w)   do {                                \
      WAP_DBG_ASSERT(!IS_FLAG_STATIC(w));                \
      if(_H(w)->parent_cnt) _H(w)->parent_cnt--;         \
   } while (0)

#define INC_REF(w)   do {                                \
      WAP_DBG_ASSERT(!IS_FLAG_STATIC(w));                \
      _H(w)->parent_cnt++;                               \
   } while (0)

#define NO_REF(w) _H(w)->parent_cnt=0

#define enable_bit_flag(field,bit_value)  field |= (bit_value)
#define disable_bit_flag(field,bit_value) field &= (~(bit_value))

#define set_bit_flag(field,bit_value,bool_value)         \
   {                                                     \
      if(bool_value) enable_bit_flag(field,bit_value);   \
      else           disable_bit_flag(field,bit_value);  \
   }

#define get_bit_flag(widget,bit_value) ((((widget_header_struct*)widget)->flag)&bit_value)

#define WIDGET_UNUSED(x)      (void)(x)

#define WIDGET_MAX(a, b)      ((a)>(b)?(a):(b))
#define WIDGET_MAX3(a, b, c)  (WIDGET_MAX(WIDGET_MAX((a), (b)), (c)))
#define WIDGET_MIN(a, b)      ((a)>(b)?(b):(a))
#define WIDGET_SET_MAX(target, value)  do {if ((target)<(value))  (target)=(value);} while (0)

/* HDIa_widgetHoldDraw */
#define WIDGET_FLAG_HOLD_DRAW       (1<<1)
/* only for paintbox use. Whether the paintbox or its child MsfGadgets receive input */
#define WIDGET_FLAG_HAS_FOCUS       (1<<2)
/* currently ignored */
#define WIDGET_FLAG_RESOURCE        (1<<3)
/* currently ignored */
#define WIDGET_FLAG_INTERNAL        (1<<4)
/* It is MsfWindow or MsfGadget, i.e. it share common data structure for window widgets */
#define WIDGET_FLAG_WINDOW          (1<<5)
/* MsfGadget specific */
#define WIDGET_FLAG_GADGET          (1<<6)
/* No need for reference count and never be released. No owner module (w/o S_HEADER) */
#define WIDGET_FLAG_STATIC          (1<<7)

/* widget connection type */
typedef enum
{
    WIDGET_GPRS,
    WIDGET_CSD,
    WIDGET_WIFI,
    
    WIDGET_BEARER_TYPE_END
} widget_bearer_type_enum;

#define WIDGET_DEFAULT_PROPERTY_MASK 0x8000

/* Async. pipe/file reading */
#define WIDGET_READ_FINISH          0
#define WIDGET_WAIT_SELECT          1
#define WIDGET_READ_ERROR           2


/* DRM right notification type */
#define WIDGET_DRM_RIGHT_NOTIFICATION_TYPE_NONE         (0)
#define WIDGET_DRM_RIGHT_NOTIFICATION_TYPE_NORMAL       (1)
#define WIDGET_DRM_RIGHT_NOTIFICATION_TYPE_IMMEDIATELY  (2)


/* Define HDIa_widgetExtShowPopup & HDIa_widgetExtForcePopup type */
#define WIDGET_EXT_DISPLAY_POPUP_FLAG           (0)
#define WIDGET_EXT_FORCE_POPUP_FLAG             (1)
#define WIDGET_EXT_FORCE_POPUP_IN_IDLE_CHECKING (2)


/* window/gadgets structure definition */
#include "widget_struct.h"

/*************************************************************************
 * PlutoMMI functions (We should include the appropriate header files in the future)
 *************************************************************************/
// TODO: include the corresponding header files
extern pBOOL isInCall(void);
extern pBOOL GetWapCallPresent(void);
extern void wgui_measure_set_animation_image_y(S32 x, S32 y, S32 *width, S32 *height, PU8 img);
extern void wgui_show_transparent_animation(void);
extern void wgui_set_animation_image_y(S32 x, S32 y, PU8 img);
extern void wgui_set_touch_title_bar_buttons(void);
extern S32 _read_image_length(U8 *image);
extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void UI_set_current_text_color(color c);
extern /* MMI_FONT_SIZE_ENUM */ U8 FontSizeEnum(void);
extern U16 StopMyTimer(U16 nTimerId);
extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);
extern void mmi_phnset_enable_partial_ss(void);

extern UI_filled_area wgui_pop_up_dialog_background;
extern BOOL r2lMMIFlag;
extern S32 GUI_current_fixed_icontext_list_menuitem_column;

extern U16 title_bg_id; /* drawing buttoms in title bar for WIDGET_SMIL_SLIDING_BAR */

/* store the image id of wallpaper */
extern U16 idle_screen_wallpaper_ID;
extern S8 *idle_screen_wallpaper_name;
extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;

extern void TurnOffBacklight(void);

/*************************************************************************
 * WAP/WAPADP functions used by widget (We should move it to wapadp.h in the future)
 *************************************************************************/
/* Module */
extern int MSF_moduleIsRunning(MSF_UINT8 modId);
extern MSF_BOOL bra_win_any_win_exists(void);
extern MSF_BOOL IsReachMEAMaxNumofMsg(MSF_UINT32 meaNoMaxMSG);

/* Messsage notification */

/* Provision */
extern void bra_prs_install_prov(void);

/* Push */
extern void bra_psl_notification_handler(void);
extern void bra_psl_SLhigh_notification_handler(void);
extern void bra_psl_SIhigh_notification_handler(void);
extern void bra_psl_unread_check(void);

/* MMS */
extern void handleNewMessage(MSF_UINT32 msgId);
extern void handleDownloadMessage(MSF_UINT32 msgId, MSF_UINT32 size);

/*************************************************************************
 * Global context
 *
 * Note: we may further reduce some static memory by optimize global context.
 *************************************************************************/

typedef enum
{
    WIDGET_NOTIFICATION_SYSTEM_MSG,
    WIDGET_NOTIFICATION_PUSH,
    WIDGET_NOTIFICATION_PROVISION,
    WIDGET_NOTIFICATION_DRM_RIGHT,
    WIDGET_NOTIFICATION_MMS,
    WIDGET_NOTIFICATION_OTHERS,
    WIDGET_NOTIFICATION_NONE,
    
    WIDGET_NOTIFICATION_END
}widget_notification_type;


typedef enum
{
    WIDGET_MSG_NOTIFICATION_NO_MSG,
    WIDGET_MSG_NOTIFICATION_HAS_MSG,
    WIDGET_MSG_NOTIFICATION_WANT_TO_SHOW_IN_IDLE,
    WIDGET_MSG_NOTIFICATION_SHOWN_IN_KEYPAD_LOCK,
    
    WIDGET_MSG_NOTIFICATION_END
}widget_notification_status_enum;


/* 
 * Sound
 * 
 * WIDGET_SOUND_ACTIVE_BEGIN ~ WIDGET_SOUND_ACTIVE_END represents that 
 * the current sound is enqueued in MDI.
 */
typedef enum
{
    WIDGET_SOUND_NONE,                  /* current_sound == NULL */
    WIDGET_SOUND_ACTIVE_BEGIN,
    WIDGET_SOUND_CMD_PROCESSING         /* Is issuing playing command */
        = WIDGET_SOUND_ACTIVE_BEGIN,
    WIDGET_SOUND_PLAYING,               /* Is playing */
    WIDGET_SOUND_ACTIVE_END = WIDGET_SOUND_PLAYING,
    WIDGET_SOUND_INTERRUPTED,           /* Widget screen overlapped by MMI */
    WIDGET_SOUND_PENDING_ON_DISPLAYED,  /* Pending until its window is displayed */
    WIDGET_SOUND_PENDING_FOR_PLAYING,   /* Request to play sound at non-widget screen, and play it when back to widget screen */
    WIDGET_SOUND_PLAY_FAILED,           /* Error in playing */
    WIDGET_SOUND_PLAY_FINISHED,         /* Sound ended, HDIa_widgetSoundStop not yet invoked */
    WIDGET_SOUND_TERMINATED,            /* Terminated by another sound */
    
    WIDGET_SOUND_END
} widget_sound_state_enum;

typedef struct
{
    kal_uint8 volume;
    kal_uint8 to_stop_by_WAP;           /* mdi_audio_stop_file() by WAP */
    kal_uint8 to_play_by_WAP;           /* mdi_audio_play_file() by WAP */
    kal_int8  wait_more_data;           /* continue to get more data */
    widget_sound_struct *waiting_sound; /* the previous waiting sound */
    widget_sound_struct *current_sound; /* Current sound file by HDIa_widgetSoundPlay */
    widget_window_struct *owner_window; /* WIDGET_SOUND_PENDING_ON_DISPLAYED */
    widget_sound_state_enum state;      /* Current state of current_sound */
} widget_sound_context_struct;

/* video state */
typedef enum
{
    WIDGET_VIDEO_NONE,                  /* initial state */
    WIDGET_VIDEO_FILE_ALREADY_CHECKED,  /* check the video file ready (file is closed) */
    WIDGET_VIDEO_READY_TO_PLAY,         /* video file is closed but want to play video */
    WIDGET_VIDEO_OPENED_WAIT_PLAY,      /* video file is opened and want to play video */
    WIDGET_VIDEO_PLAYING,               /* video is playing */
    WIDGET_VIDEO_PLAYING_OUT_OF_LCD,    /* video is playing, but it is out of LCD */
    WIDGET_VIDEO_STOP,                  /* video is stopped */
    WIDGET_VIDEO_PREVIEW                /* video is in preview mode */
} widget_video_state;

/* pre-cache non-blocking image */
typedef enum
{
    WIDGET_PRECACHE_NB_IMAEG_NONE,
    WIDGET_PRECACHE_NB_IMAEG_START,
    WIDGET_PRECACHE_NB_IMAEG_PROCESSING,
    WIDGET_PRECACHE_NB_IMAEG_NO_NEED,
    WIDGET_PRECACHE_NB_IMAEG_ERROR,
    WIDGET_PRECACHE_NB_IMAEG_DONE,
    WIDGET_PRECACHE_NB_IMAEG_DRAW_IN_CB
}widget_precache_state_enum;


/* Image */
#ifdef WIDGET_COMPACT_PRE_IMAGE
typedef struct
{
    MsfImageFormat image_format;
    MsfSize size;
    kal_uint8 *src;
    int length;
} widget_pre_image_result_data;
#endif /* WIDGET_COMPACT_PRE_IMAGE */ 

typedef struct widget_gif_animation_struct
{
    struct widget_gif_animation_struct *next;
    /* 0 if animation data is not provided by MsfImage or MsfPredefinedImage */
    MsfImageHandle image;
    MsfGadgetHandle image_gadget;
    /* Case 1: (from file) source filename */
    char filename[WIDGET_RAWFILE_NAMELEN + 1];
    /* Case2: (from memory) image data */
    void *data;
    /* Case 1: image file size. Case 2: image data size */
    kal_int32 size;
    /* Image original width */
    kal_int16 width;
    /* Image original height */
    kal_int16 height;
    /* > 0 for width of resized image */
    kal_int16 resized_width;
    /* > 0 for height of resized image */
    kal_int16 resized_height;
    kal_int16 clip[4];
    /* Display position */
    kal_int16 x;
    kal_int16 y;
    /* The number of frames in GIF animation */
    kal_int16 total_frames;
    /* Current frame to display */
    kal_int16 curr_frame;
    /* BLT on the screen immediately or draw on shadow buffer only */
    kal_uint8 force_blt;
    /* Whether this animation should be stopped after the screen is repainted. */
    kal_uint8 auto_remove;
    /* Used by widget_paint_GIF_animation_hdlr() internally */
    kal_uint8 mark_to_delete;
    /* remaining tick count (mutiply WIDGET_GIF_ANIMATION_BASE_TIME) */
    kal_uint8 remain_tick_count;
    /* draw the animation in non-blocking */
    kal_uint8 draw_in_nonblocking;
} widget_gif_animation_struct;

typedef struct
{
#ifdef WIDGET_COMPACT_PRE_IMAGE
    /* Cache the data of the last used MsfPredefinedImage.  */
    widget_pre_image_result_data pre_image_cache_data;
    widget_image_id pre_image_cache_id;
#endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    widget_gif_animation_struct *gif_head;
    widget_gif_animation_struct *busy_indication_icon;
} widget_image_context_struct;

/* Font */

#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE
/* 16 byte per entry */
typedef struct
{
    kal_uint32 seqnum;  /* 0 if the cache item is not used */

    /* Input */
    kal_int16 includeInitialWhiteSpaces;
    kal_int16 start_index;
    kal_int16 width;

    /* Output */
    kal_int16 nbrOfCharacters;
    kal_int16 nbrOfEndingWhiteSpaces;
    kal_int16 nbrOfInitialWhiteSpaces;
} widget_string_get_visible_cache_struct;

typedef enum
{
    WIDGET_STRING_GET_VISIBLE_CACHE_FOUND,
    WIDGET_STRING_GET_VISIBLE_CACHE_NEW_ENTRY
} widget_string_get_visible_cache_result_enum;

#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 

typedef struct
{
#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE
    /* MsfString to cache */
    MsfStringHandle cache_string;
    /* Cache items */
    widget_string_get_visible_cache_struct *cache;

    /* 'handle' parameter in HDIa_widgetStringGetVisible (debug only) */
    MSF_UINT32 cache_handle;
    /* Sequence number. Start from 1 */
    kal_uint32 cache_seqnum;
    /* number of items cached */
    kal_int32 cache_item_cnt;

    /* Statistics */
    kal_int32 cache_miss_cnt;
    kal_int32 cache_hit_cnt;
    kal_int32 cache_invalidation_cnt;
#else /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 
    int dummy;
#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 
} widget_font_context_struct;

/* GUI */

typedef struct
{
    // TODO: Use widget_is_current_window_type() to replace WGUI_CTX->in_paintbox, WGUI_CTX->in_form, etc
   /**********************
    * widget screen startup/termination and misc. UI parameters
    **********************/
    /* TRUE: in wap screen. FALSE: in MMI screen */
    kal_bool is_widget_screen;
    /* current key is access_key event */
    kal_bool is_access_key_trigger;
    /* (Deprecated) the first widget screen is 0, and second widget_screen is 1 ... */
    kal_uint8 current_screen_level;
    /* Entered or tried to enter widget screen since last visit of idle screen */
    unsigned int tried_to_enter_widget_screen:1;
    /* When mobile suite is not initialized */
    unsigned int in_not_ready_screen:1;
    unsigned int not_ready_for_MMS:1;   /* 1: MMS 0: WAP */
    /* If we are shutdowning MEA or BRA UI, we should not allow entering widget screen */
    unsigned int is_shutdown_UI:1;
    /* Used by widget_clear_all_handler() */
    unsigned int is_all_handler_cleared:1;
    /* Inside of wap_entry_widget_screen */
    unsigned int is_entering_widget_screen:1;
    /* Block GIF animation before widget screen is painted at the first time */
    unsigned int is_painted:1;
    /* We will drop the key between painting the sceen and first focus changed */
    unsigned int is_painted_after_first_focus_changed:1;
    unsigned int animate_GIF_after_screen_painted:1;
    /* Animation of busy icon after widget_paint_hdlr() */
    unsigned int animate_busy_status_bar:1;
    /* To use proper title icon */
    unsigned int MMS_screen_is_active:1;
    /* widget_is_current_window_type(WIDGET_PAINTBOX_TYPE) */
    unsigned int in_paintbox:1;
    /* It should indicate in MsfForm window, but the current implementation always set it except for in_paintbox == 1 */
    unsigned int in_form:1;
    /* widget_is_current_window_type(WIDGET_EDITOR_TYPE) */
    unsigned int in_editor:1;
    /* (Deprecated by WIDGET_DROP_KEY_ON_ACTION_SIGNALED) Hack. prevent duplicated YES key event */
    unsigned int disable_yes_key_in_paintbox:1;
    /* UI elements */
    unsigned int title_use_status_icons:1;
    /*
     * Whether we overrided list menu filler and need to restore it 
     * * This will be deprecated if we draw multiple-choice list menu in fullscreen category.
     */
    unsigned int is_list_menu_filler_overrided:1;
    /* check if widget's last screen is MsfDialog */
    unsigned int last_screen_is_dialog:1;

    /* need show popup in idle screen */
    unsigned int has_popup_in_idle_screen:1;

    /* need show popup in idle screen */
    unsigned int is_in_goto_idle_screen:1;

    /*
     * In MsfMenu case, the users press number keys to select the menu item. 
     * The GUI component, menu list, will start the timer to select the index one,
     * and we need to avoid the user press LSK or MsfYes at the same time.
     */
    unsigned int is_menu_item_index_selection_process:1;

#ifdef WIDGET_RESIDENT_STATUS_ICON
    /* It sometimes needs to redraw status icon to draw over gadgets in paintbox */
    unsigned int redraw_status_icons_pane:1;
    /* For confirmation dialog, we will draw mask over status icon pane */
    unsigned int dialog_with_hatch_background:1;
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 

#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
    unsigned int allow_to_update_scrollbar_indication:1;
#endif

    /* To pause widget_paint() */
    kal_int8 paint_level;
    /* Double buffer lock counter */
    kal_uint8 lock_buffer_level;
    /* displayable size which WAP can used. (regions of softkey and titlebar are excluded) */
    MsfSize display_size;
    /* default displayable size for general cases. (regions of softkey and title-bar are excluded) */
    MsfSize default_display_size;
    /* Start position of WAP display (not including the title area) */
    MsfPosition display_pos;
    /* Offset position of WAP display relative to the device coordinate */
    MsfPosition current_pos;
#ifdef WIDGET_RESIDENT_STATUS_ICON
    /* top/bottom position of status icons in title */
    MsfPosition status_icons_pane_top;
    MsfPosition status_icons_pane_bottom;
#endif /* WIDGET_RESIDENT_STATUS_ICON */ 
    /*
     * Assigned as (1<<MsfActionType). Only one action type is handled at one time 
     * * Because we LSK or RSK can be mapped by multiple MsfActionType, LSK_mask and RSK_mask
     * * describe the real MsfActionType that maps to the softkey.
     */
    kal_uint32 LSK_mask;
    kal_uint32 RSK_mask;
    /* Hack. The current selected input gadget in browser. It might not be "focused". */
    MsfGadgetHandle selected_input_in_paintbox;
    /* Widget status bar (include CSD/GPRS/busy/security icon) */
    kal_uint32 status_bar_flags;
#ifdef WIDGET_DUAL_SIM_SUPPORT
    /* Keep the sim card of widget service */
    widget_service_on_sim_enum service_on_sim;
#endif /* WIDGET_DUAL_SIM_SUPPORT */ 
    /* An unique sequence number incremented at each widget paint */
    kal_uint32 paint_seqnum;
    /* Current 'paint_seqnum' when scroll in form. */
    kal_uint32 paint_seqnum_on_form_scroll;
    /* current bearer type */
    widget_bearer_type_enum bearer_type;
    
    /* the screen ID wants to enter the widget screen */
    kal_uint16 who_want_to_enter_widget_screen;
    
    /* we need to store title bar string in 'static' buffer to get rid of headache */
    kal_uint16 title_buffer[WIDGET_MAX_TITLE_LEN + 1];
    /* Colors */
    color cursor_shadow_color;
    /*
     * backuped list menu filler when we draw an option group 
     * * Reference: is_list_menu_filler_overrided
     */
    UI_filled_area *backup_list_focussed_filler;
    UI_filled_area *backup_list_normal_filler;

    /* The root of all widget objects */
    widget_header_struct widget_root;

   /**********************
    * Queues
    **********************/
    /* Paint command */
    widget_paint_command_struct *paint_cmd_head;
    /* Blinking text */
    widget_gadget_string_struct *blinking_head;
    kal_bool blinking_on;
    /* Marquee */
    widget_gadget_image_struct *marquee_head;
    /* Access key */
    widget_accesskey_struct *accesskey_head;

   /**********************
    * MMI UI components
    **********************/
#ifdef __MMI_TOUCH_SCREEN__
    vertical_scrollbar vbar;
    horizontal_scrollbar hbar;
#endif /* __MMI_TOUCH_SCREEN__ */ 

   /**********************
    * Current widget object 
    **********************/
    /* current "focused" paintbox. Its value is set at HDIa_widgetSetInFocus, not widget_paint() */
    widget_paintbox_struct *current_focused_paintbox;
    /* current "focused" gadget.  Its value is set at HDIa_widgetSetInFocus, not widget_paint() */
    widget_header_struct *current_focused_gadget;

    /* current displayed screen. FIXME. It is unsed now. */
    widget_screen_struct *current_screen;
    /* current displayed window */
    widget_window_struct *current_window;
    /* current displayed vertical scrollbar */
    widget_gadget_bar_struct *current_vertical_scrollbar;
    /* current displayed horizontal scrollbar */
    widget_gadget_bar_struct *current_horizontal_scrollbar;
    /* current displayed dialog */
    widget_dialog_struct *current_dialog;
    /* current displayed menu or "focused and displayed" option group */
    widget_menu_struct *current_menu;
    
    /* the audio callback of the current window*/
    int (*current_window_audio_cb)(void);

    /* for check switching the widget screen */
    void (*switch_widget_screen_cb)(kal_uint16);
    widget_window_struct *previous_focused_window;
    
    /* for pre-cache non-blocking image procedure */
    void (*precache_nb_image_cb)(kal_uint16);
    widget_precache_state_enum precache_nb_image_state;

    /* widget_create_video_resource */
    widget_image_struct *current_video;
    widget_image_struct *second_video;
    /* current video resource state */
    widget_video_state current_video_state;
    /* current video gdi layer handle */
    gdi_handle video_gdi_layer;
    /* the topest gdi layer handle when playing video resource */
    gdi_handle top_gdi_layer;
    /* the topest gdi layer buffer when playing video resource */
    kal_uint8  *top_gdi_layer_buffer;
    /* the topest gdi layer handle when playing video resource is "status/title bar" or "buttom bar" */
    U32 top_gdi_layer_is_button_bar;


    /* HDIa_widgetExtShowPopupExt() & HDIa_widgetExtForcePopup() */
    U8 *popup_text;
    U8 popup_imageOnBottom;
    U8 popup_toneid;
    U16 popup_imageid;
    U32 popup_timeout;

    /* HDIa_widgetExtShowConfirm() */
    U8 *confirm_text;
    U8 confirm_imageOnBottom;
    U8 confirm_toneid;
    U16 confirm_imageid;
    U32 confirm_timeout;

#ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
    S32 v_scrollbar_value;
    S32 h_scrollbar_value;
    S32 scrollbar_indication_info;
    
#endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */

} widget_gui_context_struct;

/* Inter-Task Communication */
typedef struct
{
    /* Whether this data structure is initialized */
    unsigned int initialized:1;

    /* 
     * widget_execute_MMI and widget_execute_WAP
     */
    /* by WIDGET_WAIT_MMI_LOCK() */
    unsigned int wait_MMI_lock:1;
    /* WAP is waiting for MMI to WIDGET_SIGNAL_MMI_LOCK */
    unsigned int WAP_is_waiting:1;
    /* MMI is waiting for WAP to WIDGET_SIGNAL_MMI_LOCK */
    unsigned int MMI_is_waiting:1;

    /* 
     * MMI wait WAP to display message notification in idle screen 
     */
    /* MMI enters a loop to wait for Obigo modules to display a new message window */
    unsigned int wait_message_notification_in_idle_screen:1;
    /* When wait_message_notification_in_idle_screen == 1, HDIa_widgetSetInFocus 
       does not enter widget screen. Instead, it set this flag. */
    unsigned int pending_to_enter_widget_screen:1;

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    unsigned int extq_mutex_locked_by_WAP:1;
    unsigned int extq_mutex_locked_by_MMI:1;
    unsigned int MMI_try_to_lock_extq_mutex:1;
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 

    /* we send a primitive to trigger wap task receiving internal queue.
       but we didn't need to send more then primitive */
    unsigned int update_event_is_sent:1;

    /* 
     * RPC Callback 
     */
    /* Whether a remote procedure call is executing "in WAP task" */
    unsigned int is_executing_RPC:1;
    /* Copy the value of mmiapi_remote_proc_call_struct.finish_callback 
       when WAP task received MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ. 
       Invocation of 'RPC_finish_callback' is delayed until MSF finish processing 
       internal queue of all Obigo modules. */
    void (*RPC_finish_callback) (void);
    /* The sequence number incremented by 1 each time when idle screen is entered. 
       This is used to abort invalid RPC to MMI task. */
    kal_uint32 idlescreen_seq_no;

    /* Widget event group object used by WAP and MMI to implement blocking RPC. */
    kal_eventgrpid event_group;

#ifdef WIDGET_TMPFIX_DYNAMIC_LIST
    /* Block WAP before receiving external queue */
    kal_mutexid WAP_extq_mutex;
#endif /* WIDGET_TMPFIX_DYNAMIC_LIST */ 

    /* HDIa_widgetExtFmgrMediaInput() */
    FMGR_FILTER fmgr_input_filter;

    /* widget_paint_GIF_animation_hdlr() */
    widget_gif_animation_struct *GIF_animation_ptr;

    /* Editor message box */
    void (*editor_message_callback) (void);

    /* HDIa_widgetExtSavePhoneNumber() */
    kal_uint8 *save_phonebook_number;

    /* HDIa_widgetDrawImage() */
    MsfImageHandle draw_image;
    MSF_UINT32 draw_image_msfHandle;
    MsfPosition draw_image_position;
    MsfSize *draw_image_maxSize;
    MsfImageZoom draw_image_imageZoom;

    /* HDIa_widgetExtDisplayTransitionAnimation() */
    kal_bool transition_animation_for_MMS;
    kal_bool transition_animation_disable_END;

} widget_IPC_context_struct;

/* Profiling statistics */
#ifdef WIDGET_PROFILING
typedef struct
{
    /* Invocation count of widget_paint */
    kal_uint16 cnt_try_paint;
    /* Invocation count of widget_paint_hdlr */
    kal_uint16 cnt_paint;

    /* Invocation count of widget_malloc */
    kal_uint16 malloc_counter;

    /* Invocation count of widget_malloc grouped by data type */
    kal_uint16 malloc_counter_by_type[WIDGET_MAX_TYPE];

    /* Allocated data size of widget_malloc grouped by data type */
    kal_uint16 malloc_size_by_type[WIDGET_MAX_TYPE];

    /* Current memory consumption by widget_malloc 
       (It might not belong to MSF_MODID_WIDGET) */
    kal_int32 current_memory_usage;

    /* Max memory consumption by widget_malloc 
       (It might not belong to MSF_MODID_WIDGET) */
    kal_int32 max_memory_usage;
} widget_profiling_struct;
#endif /* WIDGET_PROFILING */ 

/* File manager */
typedef struct
{
    kal_uint8 *default_path;    /* UCS2 */

    /* HDIa_widgetExtFmgrMediaInput() */
    widget_fmgr_input_callback input_callback;
    void *input_arg;

    /* HDIa_widgetExtFmgrGetSaveFileName */
    widget_fmgr_filename_callback filename_callback;
    void *filename_arg;
    kal_uint8 *filename_suggested_name;
    kal_uint8 *filename_ext;
    kal_uint8 *filename_folder;
    char *filename_result_pathname;
    kal_uint8 *filename_warning_prompt;
} widget_fmgr_struct;

/* Display of message notification (Push/Provision/MMS) */
typedef struct
{
    unsigned int has_system_msg:1;
    unsigned int has_SLhigh:1;
    unsigned int has_SIhigh:1;
    unsigned int has_push:1;
    unsigned int has_provision:1;
	unsigned int has_DRM_right : 1;
    unsigned int has_MMS:1;

    unsigned int pending_by_call:1; /* Message was received in MO/MT screen */

    /* HDIa_widgetExtRegisterNewMMS */
    unsigned int MMS_type:4;
    kal_uint32 MMS_msgid;
    kal_uint32 MMS_size;
    kal_uint8 MMS_count;

    U8 tone_id;
    U8 DRM_right_tone_id;           /* HDIa_widgetExtRegisterDRMRightNotification */

    U8 check_msg_in_idle_screen;    /* If need to check that shows msg in idle screen (ref. widget_notification_type) */

    U8 *msg_text_in_keypadlock; /* keep the last message in keypad lock idle screen */
    U8 *DRM_right_text;         /* HDIa_widgetExtRegisterDRMRightNotification */
    U8 *provision_text;         /* HDIa_widgetExtRegisterNewProvision */
    U8 *MMS_text;               /* HDIa_widgetExtRegisterNewMMS */

    widget_notification_type notifycation_type;

    U16 DRM_right_image_id;         /* HDIa_widgetExtRegisterDRMRightNotification */

    /* HDIa_widgetExtRegisterSystemMsg */
    widget_image_id system_msg_icon;
    widget_string_id system_msg_title;
    widget_string_id system_msg_msg;

} widget_msg_notification_struct;

/* Widget Key Queue */
typedef struct
{
    /* Used to drop key to prevent key queue full */
    kal_uint32 last_enqueue_time;
    /* Used to drop key to prevent key queue full */
    kal_uint32 last_process_time;
    /* WAP is currently processing key indication primitive */
    kal_uint8 is_processing_key;
    /* Queue head & tail */
    kal_uint8 head, tail;
    kal_uint8 keycode[WIDGET_KEY_QUEUE_SIZE];
} widget_key_queue_struct;

/* Raw file */
typedef struct
{
    /* handle = 0 for empty slot */
    MSF_UINT32 handle;
    /* Absolute pathname in UTF-8 */
    char filename[WIDGET_RAWFILE_NAMELEN + 1];
    /* MsfUnsupport when filename extension is not yet configured 
       MsfSoundFormat or MsfImageFormat */
    kal_int16 format;

    /* indicate the data for raw file or virtual file */
    kal_bool is_virtual_file;

    /* org_handle keep the orginal file handle of the virtual file  */
    /* (only used in is_virtual_file == KAL_TRUE) */
    int org_file_handle;
    /*
     * size > 0 when file created 
     * * size = 0 when file is not yet created
     * * size = -1 for invalid image 
     */
    int size;

    int allocated_size; /* Aligned to WIDGET_CLUSTER_SIZE */
} widget_rawfile_item_struct;

typedef struct
{
    /* Whether the rawfile subsystem works */
    kal_bool enabled;
    /* for debug purpose */
    int total_size;
    widget_rawfile_item_struct *ptrs[MAX_WIDGET_CREATED_RAWFILE_SUM];
    char *working_buffer;

    kal_uint32 reserved_size;   /* Preallocated size */
} widget_rawfile_struct;

/* Fullscreen editor */
typedef enum
{
    FULLSCREEN_EDITOR_WANT_EXECUTE,
    FULLSCREEN_EDITOR_RETURN_NONE,
    FULLSCREEN_EDITOR_RETURN_DONE,
    FULLSCREEN_EDITOR_RETURN_CANCEL,
    FULLSCREEN_EDITOR_DENY_ENTRY,

    FULLSCREEN_EDITOR_STATE_END
} widget_fullscreen_editor_state_enum;

// TODO: use bit fields to reduce 2 bytes
typedef struct
{
    /* Current status */
    widget_header_struct *active_object;    /* MsfEditor or MsfInputGadget */
    widget_fullscreen_editor_state_enum current_state;

    /* 
     * The following values are setup by widget_setup_fullscreen_editor
     */

    /* data buffer */
    kal_uint8 *input_buffer;
    /* Max UCS2 character count including terminating character ('\0') */
    int input_buffer_max_len;
    /* current widget_fullscreen_editor type */
    MsfTextType texttype;
    /* 1: true 0: false -1: none */
    kal_int8 input_required;
    /* 1: true 0: false */
    kal_int8 in_replace_mode;
    /* MMI input type */
    S16 input_type;
    /* disable switching input method */
    kal_bool disable_switch_IM;
    /* disable switching input method */
    kal_bool disable_symbol_picker;
    /* disable reading history data */
    kal_bool disable_gui_buffer;
    /* enter fullscreen editor? */
    kal_bool entered;
    /* back to paintbox from fullscreen editor */
    kal_bool leave_from_fullscreen;

    /* title of fullscreen editor */
    MsfStringHandle title;
    /* WCSS input-format */
    const char *CSS_format;
} widget_fullscreen_editor_struct;

/* Fullscreen menu for option group in WAP pages */
typedef enum
{
    WIDGET_ENTER_MENU_NONE,
    WIDGET_ENTER_MENU_PREPARE_TO_ENTER,
    WIDGET_ENTER_MENU_ENTERED,
    WIDGET_ENTER_MENU_RETURN_OK,
    WIDGET_ENTER_MENU_RETURN_CANCEL
} widget_enter_menu_enum;

typedef struct
{
    widget_enter_menu_enum state;
    widget_menu_struct *target_menu;
    int highlighted, last_highlighted;
} widget_enter_menu_struct;

/* Precache image */
#ifdef WIDGET_PRECACHE_IMAGE
typedef struct
{
    unsigned int initialized:1;

    unsigned int layer_enabled:1;
    unsigned int layer_created:1;
    gdi_handle base_layer;
    gdi_handle cache_layer;

    widget_image_struct *cached_image;
    MSF_INT16 height;
    MSF_INT16 width;
    MsfImageZoom zoom;  /* Used to check image identify only */
} widget_precache_image_struct;
#endif /* WIDGET_PRECACHE_IMAGE */ 

/* System data */
typedef struct
{
    /* Widget object free list */
    widget_header_struct *free_obj_list[MSF_NUMBER_OF_MODULES];

    /* Widget Timer */
    event_scheduler *scheduler;
    widget_timer_struct event_timers[WIDGET_MAX_TIMER];

    /* file polling */
    int fn_sum;
    int fn_handle[MAX_WIDGET_FILE_NOTIFY_SUM];
    widget_header_struct *fn_data[MAX_WIDGET_FILE_NOTIFY_SUM];
    long fn_size[MAX_WIDGET_FILE_NOTIFY_SUM];

    /* pipe polling */
    int pn_sum;
    int pn_handle[MAX_WIDGET_PIPE_NOTIFY_SUM];
    widget_header_struct *pn_data[MAX_WIDGET_PIPE_NOTIFY_SUM];

    /* pipe delay buffer: to avoid MMI task is starving when WAP and WPS download data in high speed */
    int pn_delay_cnt;
    int pn_delay_handle[MAX_WIDGET_PIPE_NOTIFY_SUM/2];
    int pn_delay_eventType[MAX_WIDGET_PIPE_NOTIFY_SUM/2];
} widget_system_context_struct;

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    /* Current widget object that handles pen events. */
    widget_header_struct *handler;
    /* Current RSK MsfAction object */
    widget_header_struct *current_LSK;
    /* Current LSK MsfAction object */
    widget_header_struct *current_RSK;

    /* last indicated vertical scrollbar value */
    kal_int32 last_vbar_indication_offset;
    /* current indicated vertical scrollbar value */
    kal_int32 current_vbar_indication_offset;
    /* last indicated horizontal scrollbar value */
    kal_int32 last_hbar_indication_offset;
    /* current indicated vertical scrollbar value */
    kal_int32 current_hbar_indication_offset;

    /* A notification, which indicates vertical scrollbar moving, is already enqueued in BRS signal queue */
    kal_uint32 vbar_indication_in_queue:1;
    /* A notification, which indicates horizontal scrollbar moving, is already enqueued in BRS signal queue */
    kal_uint32 hbar_indication_in_queue:1;
    /* Touch screen is temporarily disabled by widget */
    kal_uint32 pen_disabled_by_widget:1;

    kal_uint32 MMS_viewer_pending_scroll_timer:1;
    widget_header_struct *MMS_viewer_scroll_form;
    int MMS_viewer_scroll_offset;

} widget_pen_context_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* Widget global context */
typedef struct
{
    widget_gui_context_struct gui_cntx;
    widget_sound_context_struct sound_cntx;                 /* Sound */
#ifdef WIDGET_PROFILING
    widget_profiling_struct profiling_data;                 /* Profiling */
#endif 
    widget_fmgr_struct fmgr_cntx;                           /* File Manager */
    widget_enter_menu_struct enter_menu_cntx;               /* Enter fullscreen menu */
    widget_fullscreen_editor_struct fullscreen_editor_cntx;
    widget_key_queue_struct key_queue;
    widget_msg_notification_struct msg_notification_cntx;   /* Push/Provision/MMS notification */
    widget_IPC_context_struct IPC_cntx;                     /* IPC */
    widget_rawfile_struct rawfile_cntx;
    widget_image_context_struct image_cntx;
    widget_font_context_struct font_cntx;
#ifdef WIDGET_PRECACHE_IMAGE
    widget_precache_image_struct precache_image_cntx;
#endif 
    widget_system_context_struct system_cntx;
#ifdef __MMI_TOUCH_SCREEN__
    widget_pen_context_struct pen_cntx;
#endif 
} widget_context_struct;

extern widget_context_struct g_widget_context;

#define WIDGET_CTX      (&g_widget_context)
#define WGUI_CTX        (&g_widget_context.gui_cntx)
#define WSND_CTX        (&g_widget_context.sound_cntx)
#define WIMG_CTX        (&g_widget_context.image_cntx)
#define WFONT_CTX       (&g_widget_context.font_cntx)
#ifdef WIDGET_PROFILING
#define WPROF_CTX       (&g_widget_context.profiling_data)
#endif 
#define WFMGR_CTX       (&g_widget_context.fmgr_cntx)
#define WEDITOR_CTX     (&g_widget_context.fullscreen_editor_cntx)
#define WENTER_MENU_CTX (&g_widget_context.enter_menu_cntx)
#define WKEY_CTX        (&g_widget_context.key_queue)
#define WNOTI_CTX       (&g_widget_context.msg_notification_cntx)
#define WIPC_CTX        (&g_widget_context.IPC_cntx)
#define WRAW_CTX        (&g_widget_context.rawfile_cntx)
#define WSYS_CTX        (&g_widget_context.system_cntx)
#ifdef WIDGET_PRECACHE_IMAGE
#define WPCACHE_CTX     (&g_widget_context.precache_image_cntx)
#endif 
#ifdef __MMI_TOUCH_SCREEN__
#define WPEN_CTX        (&g_widget_context.pen_cntx)
#endif 


/* the array to keep image that in nonblocking drawing */
typedef struct
{
    widget_gadget_image_struct  *gimg;
    gdi_handle                  handle;
    S32                         offset_x;
    S32                         offset_y;
    kal_bool                    is_used;
}widget_nb_image_struct;


/*************************************************************************
 * Task 
 *************************************************************************/

/* 
 * We only need one lock with one task; otherwise, it may introduce deadlock.
 * We may synchronize with other tasks in the future.
 */
#define  WIDGET_EVT_NOWAIT          0
#define  WIDGET_EVT_MMI_FLAG        0x01

#define WIDGET_WAIT_EVENT(evt_) do{                               \
         kal_uint32 retrieved_events;                             \
         kal_retrieve_eg_events(WIPC_CTX->event_group, (evt_),    \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define WIDGET_SET_EVENT(evt_) kal_set_eg_events(WIPC_CTX->event_group, (evt_),KAL_OR)

#define WIDGET_WAIT_MMI_LOCK() do {                               \
      WAP_DBG_ASSERT(WIPC_CTX->initialized);                      \
      ASSERT(!WIPC_CTX->wait_MMI_lock);                           \
      WIPC_CTX->wait_MMI_lock = 1;                                \
      WIDGET_WAIT_EVENT(WIDGET_EVT_MMI_FLAG);                     \
   } while(0)

#define WIDGET_SIGNAL_MMI_LOCK() do {                             \
      WAP_DBG_ASSERT(WIPC_CTX->initialized);                      \
      ASSERT(WIPC_CTX->wait_MMI_lock);                            \
      WIPC_CTX->wait_MMI_lock = 0;                                \
      WIDGET_SET_EVENT(WIDGET_EVT_MMI_FLAG);                      \
   } while (0)

#define WIDGET_TRY_MMI_LOCK() (WIPC_CTX->wait_MMI_lock == 0)

#define WIDGET_IS_MMI_TASK()  mmiapi_is_MMI_task()
#define WIDGET_IS_WAP_TASK()  (stack_get_active_module_id() == MOD_WAP)

#define WIDGET_IS_WAP_RUNNING (wap_status==WAP_RUNNING)

/*************************************************************************
 * global variable not in g_widget_context
 *************************************************************************/

extern kal_bool wap_is_busy;

extern U16 widget_all_keys[MAX_KEYS];

extern widget_header_struct *widget_prev_keyfocus;
extern widget_header_struct *widget_next_keyfocus;

extern MsfPosition widget_prev_widget_position;
extern MsfSize widget_prev_widget_size;
extern MsfPosition widget_next_widget_position;
extern MsfSize widget_next_widget_size;
extern int widget_min_x;
extern int widget_min_y;
extern int widget_max_x;
extern int widget_max_y;

extern const MsfColor widget_transparent_color;

/****************************
 * Modified category screens
 ****************************/
extern void widget_RedrawCategory123Screen(void);
extern void widget_ShowCategory123Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
extern void widget_ShowCategory123Screen_ImageBottom(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
extern void widget_messagebox(U16 message_icon, void *message, void (*callback) (void));

/****************************
 * Screen management
 ****************************/
extern void widget_MMI_entry_new_screen_with_check(void);

extern void wap_entry_widget_screen(void);
extern void wap_exit_widget_screen(void);

extern void widget_goback_to_widget_screen(void);

extern void widget_goback_history1(void);

extern kal_bool widget_ready_to_leave_screen(void);
extern void widget_prepare_to_leave_screen(void);

extern void widget_MMI_shutdown_WAP_Widget_UI(void);

/****************************
 * Task
 ****************************/
extern void widget_goto_idlescreen(void);
extern void widget_send_update_event_to_wap(void);

typedef void (*func_void) (void);
typedef void (*func_int) (int);
typedef void (*func_ptr) (void *);

extern int WIDGETc_wantsToRun(void);
extern void WIDGETc_run(void);
extern void WIDGETc_kill(void);
extern void WIDGETc_start(void);

extern void widget_execute_MMI(func_void func, kal_bool is_blocking);
extern void widget_execute_WAP(func_void func, kal_bool is_blocking);
extern void widget_execute_MMI_i(func_int func, int arg, kal_bool is_blocking);
extern void widget_execute_WAP_i(func_int func, int arg, kal_bool is_blocking);
extern void widget_execute_MMI_p(func_ptr func, void *arg, kal_bool is_blocking);
extern void widget_execute_WAP_p(func_ptr func, void *arg, kal_bool is_blocking);

extern void widget_unlock_MMI_lock_hdlr(void);

/****************************
 * Initialization routine of code module
 ****************************/
extern void widget_init_system(void);

#ifdef WIDGET_PROFILING
extern void widget_init_profiling(void);
#endif 
#ifdef __MMI_TOUCH_SCREEN__
extern void widget_init_pen(void);
extern MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 
extern void widget_init_paint_input_gadget(void);
extern void widget_init_ctk(void);
extern void widget_init_IPC(void);
extern void widget_init_GUI(void);
extern void widget_init_rawfile(void);
extern void widget_init_space_reservation(void);
extern void widget_init_sound(void);
extern void widget_init_image(void);
extern void widget_init_font(void);
extern void widget_init_fmgr(void);
extern void widget_init_key_queue(void);
extern void widget_init_fullscreen_menu(void);
extern void widget_init_fullscreen_editor(void);
extern void widget_init_message_notification(void);

#ifdef WIDGET_PRECACHE_IMAGE
extern void widget_init_precache_image(void);
extern void widget_precache_image_reset_layer_data(void);
#endif 

/****************************
 * Code module deinitialization
 ****************************/
extern void widget_deinit_system(void);
extern void widget_deinit_sound(void);
extern void widget_deinit_image(void);
extern void widget_deinit_font(void);
extern void widget_deinit_ctk(void);
extern void widget_deinit_GUI(void);
extern void widget_deinit_fmgr(void);
extern void widget_deinit_rawfile(void);

#ifdef WIDGET_PRECACHE_IMAGE
extern void widget_deinit_precache_image(void);
#endif 
#ifdef __MMI_TOUCH_SCREEN__
extern void widget_deinit_pen(void);
#endif 

/****************************
 * Custom object deinitialization
 ****************************/
extern void widget_image_release(widget_image_struct *img);
extern void widget_sound_release(widget_sound_struct *snd);

/****************************
 * Pipe/file polling
 ****************************/
extern void widget_add_file_poll(int f, widget_header_struct *object, int size);
extern void widget_add_pipe_poll(int f, widget_header_struct *object);

/****************************
 * Fullscreen editor
 ****************************/
extern void widget_setup_fullscreen_editor(
                widget_header_struct *object,
                kal_uint8 *src,
                int maxlen,
                MsfTextType type,
                kal_int8 input_required,
                MsfStringHandle title,
                const char *CSS_format);
extern void widget_enter_fullscreen_editor(void);

extern void widget_leave_fullscreen_editor_screen_if_present(widget_header_struct *object);

extern void widget_restore_editor_buffer(kal_uint8 *);
extern void widget_backup_editor_buffer(kal_uint8 *);
extern void widget_discard_editor_buffer(void);
extern kal_uint8 *widget_get_temp_editor_buffer(void);



/****************************
 * Misc. screens
 ****************************/
extern void widget_exit_please_wait_screen(void);
extern void widget_enter_please_wait_screen(void);

extern kal_bool widget_check_is_incoming_call(void);
extern kal_bool widget_check_is_in_call(void);
extern kal_bool widget_check_is_in_non_wap_call(void);
extern kal_bool widget_check_no_call_or_wap_call(void);

/****************************
 * Fullscreen menu
 ****************************/

extern void widget_enter_fullscreen_menu(widget_menu_struct *menu);

/****************************
 * Memory manager
 ****************************/
#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
extern void *widget_malloc_mem(MSF_UINT8 modId, int size);
extern void widget_free_mem(MSF_UINT8 modId, void *pointer);
#else /* WIDGET_MALLOC_IN_OWNER_MODULE */ 
extern void *widget_malloc_mem(int size);
extern void widget_free_mem(void *pointer);
#endif /* WIDGET_MALLOC_IN_OWNER_MODULE */ 
extern widget_header_struct *widget_malloc(MSF_UINT8 modId, widget_data_type_enum datatype, int extra_size);
extern kal_bool widget_free(widget_header_struct *w);
extern void widget_release_all(MSF_UINT8 modId);

/****************************
 * Dialog
 ****************************/
extern void dm_set_popup_screen_background(MMI_BOOL state);

extern void widget_dialog_get_attributes(
                MsfDialogType type,
                ctk_image_id *imageid,
                ctk_tone_id *toneid,
                kal_bool *imageOnBottom);

/****************************
 * Object format
 ****************************/
extern const char *widget_sound_file_ext_to_mime_type(const char *ext);

/****************************
 * Rawfile
 ****************************/
extern kal_bool widget_rawfile_allow_to_create_image(MsfImageFormat image_format, int size);
extern kal_bool widget_rawfile_allow_to_create_sound(void);
extern kal_int16 widget_rawfile_register(MSF_UINT32 handle);
extern void widget_rawfile_deregister(kal_int16 file_id);
extern char *widget_rawfile_getname(kal_int16 file_id);
extern int widget_rawfile_getsize(kal_int16 file_id);
extern void widget_rawfile_write(kal_int16 file_id, const char *data, int size);
extern kal_bool widget_rawfile_write_failed(kal_int16 file_id);
extern void widget_rawfile_configure_format(kal_int16 file_id, int format, const char *file_ext);
extern kal_bool widget_rawfile_gen_virtual_file(kal_int16 file_id, int org_fd, int offset, int size);

extern kal_uint32 widget_decrease_space_reservation(kal_uint32 diff);
extern kal_uint32 widget_increase_space_reservation(kal_uint32 diff);

/****************************
 * Image handling
 ****************************/
extern kal_bool widget_image_is_ready(MsfImageHandle image);
extern int widget_image_resid(MsfImageHandle image);
extern int widget_image_width(MsfImageHandle image);
extern int widget_image_height(MsfImageHandle image);
extern MsfSize *widget_image_dimension(MsfImageHandle image);
extern kal_uint8 *widget_image_content(MsfImageHandle image);
extern char *widget_image_content_file(MsfImageHandle image);
extern int widget_image_length(MsfImageHandle image);
extern MsfImageFormat widget_image_format(MsfImageHandle image);
extern int widget_image_frame_count(MsfImageHandle image);
extern kal_bool widget_is_rawfile_full(void);
extern int widget_open_check_original_file_for_virtual_file(MsfPartialFileData *data);

extern kal_bool widget_MMI_initialize_image_frame_count(MsfImageHandle image);

extern char *widget_video_content_file(MsfImageHandle image);
extern void widget_copy_title_from_base_layer(gdi_handle dest);
extern void widget_copy_bar_from_base_layer(gdi_handle dest);
extern void widget_free_video_gdi_layer(void);
extern void widget_MMI_play_video_gadget(void);
extern kal_bool widget_check_in_playing_video(void);

#ifdef __MMI_SUBLCD__
extern void widget_freeze_sub_lcd(MMI_BOOL is_freeze);
#endif 

/****************************
 * Image paint/animation
 ****************************/
extern void widget_paint_GIF_animation_hdlr(void *arg);

extern void widget_stop_animate(kal_bool is_force);
extern kal_bool widget_stop_animate_by_ptr(widget_gif_animation_struct *ptr);
extern kal_bool widget_stop_animate_by_image(MsfImageHandle image);

extern widget_gif_animation_struct *widget_show_animate_image_by_raw_data(
                                        widget_gadget_image_struct *gimg,
                                        widget_image_struct *img,
                                        S32 x,
                                        S32 y,
                                        int image_format,
                                        void *data,
                                        int size,
                                        int width,
                                        int height,
                                        MsfSize *maxSize,
                                        MsfImageZoom imageZoom,
                                        kal_bool use_source_file,
                                        kal_bool auto_remove,
                                        kal_bool clipping_to_content_size,
                                        kal_bool force_blt,
                                        kal_bool do_animation);

extern void widget_image_nb_draw_default(S32 x1, S32 y1, S32 x2, S32 y2);
extern void widget_stop_image_nb_draw(widget_image_struct *img);
extern void widget_stop_all_image_nb_draw(void);
extern U8 widget_get_gdi_image_id(MsfImageFormat format);

/****************************
 * Precache image
 ****************************/
#ifdef WIDGET_PRECACHE_IMAGE
extern void widget_MMI_free_precached_image_if_any(void);
extern void widget_precache_image_reset_all(void);
extern void widget_reset_precached_image_by_image(widget_image_struct *img);

extern kal_bool widget_MMI_prepare_precache_image(
                    widget_image_struct *img,
                    MSF_UINT16 width,
                    MSF_UINT16 height,
                    MsfImageZoom zoom);
extern void widget_MMI_finish_precache_image(void);

extern kal_bool widget_image_is_precached(
                    widget_image_struct *img,
                    MSF_UINT16 resized_width,
                    MSF_UINT16 resized_height,
                    MsfImageZoom zoom);
extern void widget_MMI_show_precached_image(int x, int y, kal_bool clipping_to_content_size);
#endif /* WIDGET_PRECACHE_IMAGE */ 

/****************************
 * Low-level drawing
 ****************************/
extern void widget_draw_image_from_queued_op(
                widget_image_struct *img,
                MsfPosition *position,
                MsfSize *maxSize,
                kal_int16 x_offset,
                kal_int16 y_offset);
extern void widget_draw_op_release(widget_draw_op_struct *draw_op);
extern void widget_enqueue_draw_op(
                widget_draw_op_struct **head,
                widget_draw_op_struct **tail,
                widget_draw_op_struct *draw_op);

extern kal_bool widget_draw_queued_operation_from_gadget_image(
                    widget_gadget_image_struct *gimg,
                    kal_bool erase_background,
                    kal_bool force_blit,
                    kal_int16 x_offset,
                    kal_int16 y_offset);

extern kal_bool widget_clipping_intersection(int *x1, int *y1, int *x2, int *y2, int ax1, int ay1, int ax2, int ay2);

/****************************
 * Sound playing
 ****************************/
extern kal_bool widget_is_sound_playing(void);
extern void widget_stop_sound_if_present(void);
extern void widget_pause_sound_if_present(void);
extern void widget_resume_pending_sound_if_present(void);
extern void widget_resume_pending_sound_on_displayed(widget_window_struct *wnd);
extern void widget_check_play_waiting_sound(void);

extern void widget_setup_volume_key(void);
extern void widget_press_inc_volume(void);
extern void widget_press_dec_volume(void);

/****************************
 * Style
 ****************************/
extern MsfStyleHandle widget_get_style(MSF_UINT32 handle);
extern MsfStyleHandle widget_style_copy(MSF_UINT8 modId, MsfStyleHandle src);
extern kal_bool widget_is_transparent_color(MsfColor *c);

/****************************
 * Event handling
 ****************************/
extern kal_bool widget_fire_action_internal(widget_window_struct *node, kal_uint32 action_mask);
extern kal_bool widget_fire_action(widget_window_struct *node, MsfEventType key_event);
extern kal_bool widget_fire_RSK(widget_window_struct *node);
extern kal_bool widget_fire_LSK(widget_window_struct *node);
extern void widget_update_action_total_mask(widget_window_struct *w);

extern void widget_MMI_key_handler(void);
extern void widget_enqueue_keypad_event(U16 Keycode, U16 Keytype);

extern void widget_general_keyboard_handler(kal_uint16 Keycode, kal_uint16 Keytype);
extern kal_bool widget_key_ind_handler(kal_uint16 keycode, kal_uint16 keytype);

extern void widget_enable_clear_all_handler(void);
extern void widget_clear_all_handler(void);
extern void widget_clear_animator_on_key_accepted(void);

extern void widget_notify(widget_header_struct *h, MsfNotificationType type);

/****************************
 * String
 ****************************/
extern void *widget_string_content(MsfStringHandle str);
extern MsfStringHandle widget_copy_string(MSF_UINT8 modId, MsfStringHandle s);
extern MsfStringHandle widget_copy_partial_string(
                        MSF_UINT8 modId,
                        MsfStringHandle s,
                        int index,
                        int nbrOfChars,
                        kal_bool copy_style);
extern void widget_resize_string(widget_string_struct *str, int max_len);

extern void widget_get_string_width_height(
                kal_uint8 *str,
                int s_id,
                int e_id,
                int *w,
                int *h);

extern int widget_string_length(MsfStringHandle str);
extern int widget_string_length_in_bytes(MsfStringHandle str);
extern void widget_string_copy_content_to_utf8(kal_uint8 *buffer, MsfStringHandle str);

/****************************
 * Blinking text
 ****************************/
extern void widget_setup_blinking(widget_gadget_string_struct *gstr, MsfColor bgcolor);
extern void widget_remove_blinking(widget_gadget_string_struct *gstr);
extern void widget_stop_all_blinking(void);

/****************************
 * Marquee
 ****************************/
extern void widget_setup_marquee(widget_gadget_image_struct *gimg);
extern void widget_remove_marquee(widget_gadget_image_struct *gimg);
extern void widget_stop_all_marquee(void);

/****************************
 * Accesskey
 ****************************/
extern kal_bool widget_delete_accesskey_by_window(MSF_UINT32 wnd);
extern MsfAccessKeyHandle widget_lookup_accesskey(MSF_UINT32 wnd, kal_uint16 key);

/****************************
 * Font
 ****************************/
extern stFontAttribute widget_convert_to_system_font(MsfFont *font);

extern int widget_get_string_width_deviation(stFontAttribute font, int height);

#ifdef WIDGET_STRING_GET_VISIBLE_USE_CACHE

extern void widget_release_get_visible_cache_by_string(MsfStringHandle str);

extern widget_string_get_visible_cache_result_enum
widget_lookup_string_get_visible_cache(
    MSF_UINT32 handle,
    MsfSize *size,
    int startIndex,
    int includeInitialWhiteSpaces,
    widget_string_get_visible_cache_struct **item);

#endif /* WIDGET_STRING_GET_VISIBLE_USE_CACHE */ 

/****************************
 * Raw data
 ****************************/
extern widget_raw_data_struct *widget_create_raw_data_ext(kal_uint8 module_id, int size);
extern void widget_set_raw_data(widget_raw_data_struct *raw, const void *src, int length);

/****************************
 * Debug
 ****************************/
extern void widget_dump_hex(unsigned char *buf, int len);
extern void widget_show_info(widget_header_struct *handle);
extern void widget_show_action(widget_action_struct *action);
extern void widget_dump_memory_usage(void);
extern kal_bool widget_check_object_validity(widget_header_struct *handle);

/****************************
 * MsfForm
 ****************************/
extern kal_bool widget_register_keyfocus(widget_header_struct *handle);
extern kal_bool widget_goto_prev_keyfocus_keyboard_handler(void);
extern kal_bool widget_goto_next_keyfocus_keyboard_handler(void);
extern void widget_record_used_range(
                widget_header_struct *h,
                kal_bool is_want_focus,
                kal_bool is_focus,
                int x1,
                int y1,
                int x2,
                int y2);

extern void widget_choice_focus(void);
extern void widget_set_current_object(widget_header_struct *obj);
extern void widget_set_current_focus(widget_header_struct *obj, kal_bool has_focus);

extern void widget_form_draw_border(widget_header_struct *h, int x1, int y1, int x2, int y2);
extern void widget_form_on_focused(widget_header_struct *form);
extern void widget_form_on_defocused(widget_header_struct *form);
extern void widget_form_on_gadget_added(widget_header_struct *form, widget_header_struct *gadget_added);
extern void widget_form_on_gadget_removed(widget_header_struct *form, widget_header_struct *gadget_removed);
extern kal_bool widget_form_gadget_want_focus(widget_header_struct *gadget);

#ifdef __MMI_TOUCH_SCREEN__
extern void widget_MMS_viewer_abort_pen_scroll_if_necessary(widget_header_struct *h, kal_bool need_redraw);

extern void widget_MMI_form_scroll_by_pen(widget_header_struct *form, widget_header_struct *vbar, int scroll_offset);
extern void widget_MMI_form_pen_handler(
                widget_header_struct *h,
                mmi_pen_point_struct point,
                mmi_pen_event_type_enum pen_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef WIDGET_SLIDING_SMIL_SUPPORT
extern kal_bool widget_form_update_for_sliding_SMIL(widget_form_struct *form);
extern void widget_form_remove_sliding_info(widget_form_struct *form);
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */ 

/****************************
 * Menu
 ****************************/
extern void widget_restore_menu_background_if_required(void);

/****************************
 * Paint
 ****************************/
extern void widget_set_title(MsfStringHandle h);
extern void widget_set_previous_MMI_title(void);
extern void widget_clear(MsfSize *size, MsfPosition *pos);
extern void widget_paint_outside_look(void);
extern void widget_paint_scrollbar(void);
extern void widget_paint_smil_sliding_bar(void);
extern void widget_paint_title(void);
extern void widget_paint(void);
extern void widget_paint_hdlr(void *arg);
extern void widget_resume_paint(void);
extern void widget_pause_paint(void);
extern void widget_paint_display_clipping_region(int *x1, int *y1, int *x2, int *y2);

extern void widget_paint_area(widget_header_struct *handle, MsfSize size, MsfPosition pos);
extern void widget_paint_action(widget_header_struct *parent);
extern void widget_paint_menu(widget_menu_struct *menu, MsfSize *size, MsfPosition *pos);
extern void widget_paint_gadget_bar(
                widget_gadget_bar_struct *bar,
                MsfSize *size,
                MsfPosition *pos,
                kal_bool force_paint);
extern void widget_paint_gadget_string(widget_gadget_string_struct *str, MsfSize *size, MsfPosition *pos);
extern void widget_paint_gadget_input(widget_gadget_input_struct *inp, MsfSize *size, MsfPosition *pos);
extern void widget_paint_gadget_image(widget_gadget_image_struct *img, MsfSize *size, MsfPosition *pos);
extern void widget_paint_dialog(widget_dialog_struct *dialog, MsfSize *size, MsfPosition *pos);
extern void widget_paint_editor(widget_editor_struct *editor, MsfSize *size, MsfPosition *pos);
extern void widget_paint_form(widget_form_struct *form, MsfSize *size, MsfPosition *pos);
extern void widget_paint_status_bar_busy_animator(kal_bool is_off_to_on);
extern void widget_paint_ctk(widget_ctk_struct *ctk);

extern void widget_paintbox_redraw(void);
extern ctk_image_id widget_get_title_icon(ctk_image_id imageid);
extern void widget_setup_security_icon(void);
extern void widget_reset_security_icon(void);
extern kal_bool widget_gadget_clear_background(widget_window_struct *w, kal_bool force_blt);

extern void widget_paint_scrollbar_ind_hdlr(void *arg);

/****************************
 * For redraw performance
 ****************************/
extern kal_bool widget_gadget_in_form(
                    const MsfSize *form_size,
                    const MsfPosition *gadget_pos,
                    const MsfSize *gadget_size);
extern kal_bool widget_is_window_gadget_displayed(MSF_UINT32 msfHandle);
extern kal_bool widget_is_current_window_type(widget_data_type_enum type);
extern widget_window_struct *widget_get_current_focused_window(void);

extern void widget_add_paint_title_command(void);

extern void wgui_set_title_bknd_display(MMI_BOOL state);

extern void widget_paint_MMS_viewer_title(void);
extern void widget_draw_MMS_viewer_title_button(U16 img_id, S16 x, S16 y, S16 w, S16 h);
extern void widget_add_paint_sliding_bar_command(void);

extern void widget_add_paint_gadget_command(widget_header_struct *h);
extern void widget_stop_all_paint_command(void);
extern void widget_stop_paint_gadget_command(widget_header_struct *h);

extern void widget_release_paint_command_queue(void);

/****************************
 * Image/Sound data source
 ****************************/
extern int widget_read_sound_from_pipe(int f, widget_sound_struct *snd, kal_bool need_add_select);
extern int widget_read_sound_from_file(
            int f,
            int size,
            widget_sound_struct *snd,
            kal_bool need_add_select,
            kal_bool is_DRM);
extern int widget_read_image_from_pipe(int f, widget_image_struct *img, kal_bool need_add_select);
extern int widget_read_image_from_file(
            int f,
            int size,
            widget_image_struct *img,
            kal_bool need_add_select,
            kal_bool is_DRM);

/****************************
 * Status Icons
 ****************************/
extern void widget_setup_status_icons(void);
extern kal_bool widget_has_status_icons(void);
extern void widget_redraw_status_icons(void);
extern void widget_close_status_icons_if_present(void);

/****************************
 * CTK adaptation
 ****************************/
extern void widget_prepare_to_enter_ctk_window(widget_ctk_struct *ctk);
extern void widget_ctk_leave_screen_if_present(widget_header_struct *to_remove_handle, int to_remove_modId);
extern void widget_release_ctk_data(widget_ctk_struct *ctk);
extern widget_ctk_state_enum widget_current_ctk_state(void);
extern ctk_MMI_screen_id widget_current_ctk_MMI_screen_id(void);

/****************************
 * Touch screen
 ****************************/

#ifdef __MMI_TOUCH_SCREEN__
extern void widget_WAP_pen_on_keypad_event(void);
extern void widget_MMI_setup_pen_handler(void);
extern void widget_MMI_remove_pen_handler_if_necessary(widget_header_struct *h);
extern void widget_MMI_reset_pen_on_screen_switch(void);
extern void widget_pen_on_post_msf_fsm(void);
#endif /* __MMI_TOUCH_SCREEN__ */ 

/****************************
 * Unit test
 ****************************/
extern void widget_start_unit_test(void);
extern void widget_simulate_out_of_memory(void);

/****************************
 * Timer
 ****************************/
extern void widget_start_timer(int timer, widget_timer_func func, void *func_arg, unsigned long msec);
extern void widget_stop_timer(int timer);

/****************************
 * Object creation
 ****************************/
#define widget_remove(X)                  HDIa_widgetRemove(0,(MSF_UINT32)X)
#define widget_release(X)                 HDIa_widgetRelease((MSF_UINT32)X)

#define widget_create_screen(modId)       (widget_screen_struct*)    widget_malloc(modId,WIDGET_SCREEN_TYPE,0)
#define widget_create_style(modId)        (widget_style_struct*)     widget_malloc(modId,WIDGET_STYLE_TYPE,0)
#define widget_create_form(modId)         (widget_form_struct*)      widget_malloc(modId,WIDGET_FORM_TYPE,0)
#define widget_create_paintbox(modId)     (widget_paintbox_struct*)  widget_malloc(modId,WIDGET_PAINTBOX_TYPE,0)
#define widget_create_ctk(modId)          (widget_ctk_struct*)       widget_malloc(modId,WIDGET_CTK_TYPE,0)
#define widget_create_icon(modId)         (widget_icon_struct*)      widget_malloc(modId,WIDGET_ICON_TYPE,0)
#define widget_create_editor(modId)       (widget_editor_struct*)    widget_malloc(modId,WIDGET_EDITOR_TYPE,0)
#define widget_create_string(modId)       (widget_string_struct*)    widget_malloc(modId,WIDGET_STRING_TYPE,0)
#define widget_create_image(modId)        (widget_image_struct*)     widget_malloc(modId,WIDGET_IMAGE_TYPE,0)
#define widget_create_sound(modId)        (widget_sound_struct*)     widget_malloc(modId,WIDGET_SOUND_TYPE,0)
#define widget_create_action(modId)       (widget_action_struct*)    widget_malloc(modId,WIDGET_ACTION_TYPE,0)
#define widget_create_menu(modId)         (widget_menu_struct*)      widget_malloc(modId,WIDGET_MENU_TYPE,0)
#define widget_create_dialog(modId)       (widget_dialog_struct*)    widget_malloc(modId,WIDGET_DIALOG_TYPE,0)
#define widget_create_gadget_string(modId)   (widget_gadget_string_struct*)   widget_malloc(modId,WIDGET_GADGET_STRING_TYPE,0)
#define widget_create_gadget_input(modId) (widget_gadget_input_struct*)       widget_malloc(modId,WIDGET_GADGET_INPUT_TYPE,0)
#define widget_create_gadget_select_group(modId)   (widget_gadget_select_group_struct*)   widget_malloc(modId,WIDGET_GADGET_SELECT_GROUP_TYPE,0)
#define widget_create_gadget_image(modId) (widget_gadget_image_struct*)       widget_malloc(modId,WIDGET_GADGET_IMAGE_TYPE,0)
#define widget_create_gadget_date(modId)  (widget_gadget_date_struct*)        widget_malloc(modId,WIDGET_GADGET_DATE_TYPE,0)
#define widget_create_gadget_bar(modId)      (widget_gadget_bar_struct*)      widget_malloc(modId,WIDGET_GADGET_BAR_TYPE,0)
#define widget_create_choice_element(modId)  (widget_choice_element_struct*)  widget_malloc(modId,WIDGET_CHOICE_ELEMENT_TYPE,0)
#define widget_create_raw_data(modId,size)   (widget_raw_data_struct*)        widget_malloc(modId,WIDGET_RAW_DATA_TYPE,size)
#include "widget_linklist.h"

#endif /* _WIDGET_H_ */ 


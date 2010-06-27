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
 *  app_mem_config.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Register application-based ASM
 *
 *  Note: screen-based ASM is registered in ScrMemMgr.h because it belongs to MMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef APP_MEM_CONFIG_H
#define APP_MEM_CONFIG_H

#ifdef __J2ME__
#include "j2me_custom_param.h"
#endif

#ifndef APP_MEM_H
#error "Please include app_mem.h before this file"
#endif

#ifndef APP_MEM_C
/* This file may include application header files in other folders, 
   and modules other than applib may not have the appropriate include paths.
   It is easy to have compile errors. */
#error "app_mem_config.h can only be included in app_mem.c"
#endif /* APP_MEM_C */

#ifndef __MMI_FEATURES__
#include "mmi_features.h"
#endif

/*
 * Updated ASM pool size configuration mechanism:
 * Please define pool size you need follow the rule as below,
 * then add the corresponding item in the union at the bottom of this file
 * which could calculate the maximal size of ASM pool.
 */

/*
 * WARNING!!!
 * After modifying this file, please notify the file owner to review your changes.
 */

#ifdef APPLIB_MEM_UNIT_TEST
    #define APPMEM_TEST_POOL_SIZE  (100*1024)
#endif /* APPLIB_MEM_UNIT_TEST */

#ifdef __MMI_3D_GAME__
    #ifdef  GE_BROGENT
    #include "bgl_adaptation.h"

        #define APPMEM_BGL_BUFFER_POOL_SIZE BGL_BUFFER_POOL_SIZE
    #endif /* GE_BROGENT */
    #ifdef GE_INTERGRAFX
    #include "ig_mem.h"

        #define APPMEM_IGL_POOL_SIZE IGL_POOL_SIZE
    #endif /* GE_INTERGRAFX */
#endif /* __MMI_3D_GAME__ */

#if defined(__MMI_MAPBAR_GIS__)
    #include "MMIDataType.h"
    #include "MB_GISGProt.h"
    #define APPMEM_GIS_BUFFER_POOL_SIZE GIS_MEM_POOL_SIZE
#elif defined(__MMI_SUNAVI_GIS__)
    #include "MMIDataType.h"
    #include "SN_GISGProt.h"
    #define APPMEM_GIS_BUFFER_POOL_SIZE GIS_MEM_POOL_SIZE
#else 
    #define APPMEM_GIS_BUFFER_POOL_SIZE (0)
#endif /* __MMI_MAPBAR_GIS__ || __MMI_SUNAVI_GIS__*/

#ifdef __MMI_AVATAR__
    #define APPMEM_AVATAR_POOL_SIZE (240*320*2)
#endif /* __MMI_AVATAR__ */

#ifdef __MMI_BARCODEREADER__
    #include "lcd_sw_rnd.h"
    #include "PixtelDataTypes.h"
    #include "gdi_include.h"
    #include "barcodereaderGprot.h"
    #include "custom_mmi_default_value.h"

    #define APPMEM_BR_APP_TOTAL_SIZE BR_APP_TOTAL_SIZE
#endif /* __MMI_BARCODEREADER__ */

#ifdef __J2ME__
    #define APPMEM_JAVA_POOL_SIZE  DEFAULTHEAPSIZE
    #define APPMEM_JAVA_MIN_POOL_SIZE   DEFAULTHEAPSIZEFORJAM
#endif /* __J2ME__ */

/********* INSERT NEW APPLICATION HERE *********/
#ifdef __MMI_PHOTOEDITOR__
     #if defined(__MMI_MAINLCD_240X320__)
         #define APPMEM_PHOEDT_POOL_SIZE (240*320*2*2)
     #elif defined(__MMI_MAINLCD_176X220__)
         #define APPMEM_PHOEDT_POOL_SIZE (176*220*2*2)
     #elif defined(__MMI_MAINLCD_128X160__)
         #define APPMEM_PHOEDT_POOL_SIZE (128*160*2*2)
     #elif defined(__MMI_MAINLCD_128X128__)
         #define APPMEM_PHOEDT_POOL_SIZE (128*128*2*2)    
     #else
         #define APPMEM_PHOEDT_POOL_SIZE (240*320*2*2)    
     #endif
#endif /* __MMI_PHOTOEDITOR__ */

#ifdef JATAAYU_SUPPORT
    #include "jdd_config.h"

    #if defined(JBROWSER_USE_ASM)
        #define APPMEM_JATAAYU_WAP_POOL_SIZE  (250*1024)
    #endif /*JBROWSER_USE_ASM*/
#endif /*JATAAYU_SUPPORT*/

#ifdef OBIGO_Q05A
    #include "custom_wap_config.h"

    #define APPMEM_BROWSER_POOL_SIZE  (WAP_CUSTOM_CFG_BROWSER_MEM_SIZE) + (50*1024)
#endif /* OBIGO_Q05A */

#ifdef __MMI_VIDEO_EDITOR__
    #include "VdoedtMem.h"

    #define APPMEM_VDOEDT_POOL_SIZE MMI_VDOEDT_APPMEM_POOL_SIZE
#endif /* __MMI_VIDEO_EDITOR__ */

/* Camera */
#ifdef __MMI_CAMERA__
    #include "lcd_sw_rnd.h"
    #include "PixtelDataTypes.h"
    #include "gdi_include.h"
    #include "jpeg.h"
    #include "CameraGprot.h"

    #define APPMEM_CAMERA_POOL_SIZE     (CAMERA_DIRECT_COUPLE_BUFFER_SIZE)
#endif /* __MMI_CAMERA__ */ 

#ifdef __MMI_DICTIONARY__
    #if defined (__MMI_DICT_GV__) || defined(__MMI_DICT_TRILOGY__)
        #define APPMEM_DICTIONARY_POOL_SIZE (10 * 1024)
    #elif defined(__MMI_DICT_MOTECH__)
        #define APPMEM_DICTIONARY_POOL_SIZE (40 * 1024)  
    #endif
#endif /*__MMI_DICTIONARY__*/

#ifdef __MMI_LANGLN__
    #define APPMEM_LANGLN_POOL_SIZE (256*1024)
#endif

#ifdef __MMI_MOBILE_TV_PLAYER__
    #include "lcd_sw_rnd.h"
    #include "PixtelDataTypes.h"
    #include "gdi_include.h"
    #include "MobileTVPlayerGprot.h"

    #define APPMEM_MTV_PLAYER_POOL_SIZE MMI_MTV_PLAYER_APP_MEM_SIZE 
#endif


#ifdef __MMI_SLIDESHOW__
    #include "SlideShowMem.h"

    #define APPMEM_SLIDESHOW_POOL_SIZE MMI_SSHOW_POOL_SIZE
#endif /* __MMI_SLIDESHOW__ */

#ifdef __MMI_AB_REPEATER__
    #define APP_MEM_ABREPEAT_BUILD_CACHE_POOL_SIZE (40*1024)
#endif /*__MMI_AB_REPEATER__*/

#ifdef __MMI_BIP_SUPPORT__
    #define APPMEM_BT_BIP_SIZE (60*1024)
#endif

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    #include "lcd_sw_inc.h"
    #define APPMEM_PICT_BRIDGE_POOL_SIZE (UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT * 2)
#endif

/*
 * 1. APPLIB_MEM_AP_POOL_SIZE
 * 
 * The size of the app-based ASM pool
 *
 * 2. APPLIB_MEM_AP_POOL_ALIGN
 *
 * Memory alignment of the app-based ASM pool
 *
 * If APPLIB_MEM_AP_POOL_ALIGN > 0, it set the required alignment of the whole ASM pool.
 * For example, we may need to align the pool to 256KB or 512KB for Java FBBR.
 */


#define APPMEM_ALIGN_TO_4(_x)  (((_x) + 3) & ~3) 

#if defined(__J2ME__) && defined(J2ME_ALIGN)

    #define APPLIB_MEM_AP_POOL_ALIGN    (J2ME_ALIGN)
    
#else /* defined(__J2ME__) && defined(J2ME_ALIGN) */

    #define APPLIB_MEM_AP_POOL_ALIGN    (4)

#endif /* defined(__J2ME__) && defined(J2ME_ALIGN) */


/* Add extra space for ADM internal data structures.
  (Assume that there are at most 10 concurrent memory blocks) */
#ifdef LOW_COST_SUPPORT
	#define APPLIB_MEM_AP_POOL_OVERHEAD     (APPLIB_MEM_GET_POOL_EXTRA_SIZE(3))
#else
	#define APPLIB_MEM_AP_POOL_OVERHEAD     (APPLIB_MEM_GET_POOL_EXTRA_SIZE(10))
#endif

/* APPMEM_POOL_SIZE is multiple of 4 */
#define APPLIB_MEM_AP_POOL_DEFAULT_SIZE     (0 + APPLIB_MEM_AP_POOL_OVERHEAD)

#define APPLIB_MEM_AP_POOL_SIZE_CONFIG(size)    \
	(APPMEM_ALIGN_TO_4(size) + APPLIB_MEM_AP_POOL_OVERHEAD) 

#define APPLIB_MEM_CONC2_AP_POOL_SIZE(size1, size2)    \
    (APPMEM_ALIGN_TO_4(size1) + APPMEM_ALIGN_TO_4(size2) + APPLIB_MEM_AP_POOL_OVERHEAD) 

#define APPLIB_MEM_CONC3_AP_POOL_SIZE(size1, size2, size3)    \
    (APPMEM_ALIGN_TO_4(size1) + APPMEM_ALIGN_TO_4(size2) + APPMEM_ALIGN_TO_4(size3) + APPLIB_MEM_AP_POOL_OVERHEAD)

/***************************************************************************** 
 * Please define your pool size to zero if it is not defined before!
 *****************************************************************************/
#if !defined(APPLIB_MEM_AP_POOL_DEFAULT_SIZE)
    #define APPLIB_MEM_AP_POOL_DEFAULT_SIZE (0)
#endif
#if !defined(APPMEM_TEST_POOL_SIZE)
    #define APPMEM_TEST_POOL_SIZE (0)
#endif
#if !defined(APPMEM_BGL_BUFFER_POOL_SIZE)
    #define APPMEM_BGL_BUFFER_POOL_SIZE (0)
#endif
#if !defined(APPMEM_IGL_POOL_SIZE)
    #define APPMEM_IGL_POOL_SIZE (0)
#endif
#if !defined(APPMEM_AVATAR_POOL_SIZE)
    #define APPMEM_AVATAR_POOL_SIZE (0)
#endif
#if !defined(APPMEM_BR_APP_TOTAL_SIZE)
    #define APPMEM_BR_APP_TOTAL_SIZE (0)
#endif
#if !defined(APPMEM_JAVA_POOL_SIZE)
    #define APPMEM_JAVA_POOL_SIZE (0)
#endif
#if !defined(APPMEM_PHOEDT_POOL_SIZE)
    #define APPMEM_PHOEDT_POOL_SIZE (0)
#endif
#if !defined(APPMEM_JATAAYU_WAP_POOL_SIZE)
    #define APPMEM_JATAAYU_WAP_POOL_SIZE (0)
#endif
#if !defined(APPMEM_BROWSER_POOL_SIZE)
    #define APPMEM_BROWSER_POOL_SIZE (0)
#endif
#if !defined(APPMEM_VDOEDT_POOL_SIZE)
    #define APPMEM_VDOEDT_POOL_SIZE (0)
#endif
#if !defined(APPMEM_CAMERA_POOL_SIZE)
    #define APPMEM_CAMERA_POOL_SIZE (0)
#endif
#if !defined(APPMEM_DICTIONARY_POOL_SIZE)
    #define APPMEM_DICTIONARY_POOL_SIZE (0)
#endif
#if !defined(APPMEM_LANGLN_POOL_SIZE)
    #define APPMEM_LANGLN_POOL_SIZE (0)
#endif
#if !defined(APPMEM_MTV_PLAYER_POOL_SIZE)
    #define APPMEM_MTV_PLAYER_POOL_SIZE (0)
#endif
#if !defined(APPMEM_SLIDESHOW_POOL_SIZE)
    #define APPMEM_SLIDESHOW_POOL_SIZE (0)
#endif
#if !defined(APP_MEM_ABREPEAT_BUILD_CACHE_POOL_SIZE)
    #define APP_MEM_ABREPEAT_BUILD_CACHE_POOL_SIZE (0)
#endif 
#if !defined(APPMEM_JAVA_MIN_POOL_SIZE)
    #define APPMEM_JAVA_MIN_POOL_SIZE (0)
#endif
#if !defined(APPMEM_BT_BIP_SIZE)
    #define APPMEM_BT_BIP_SIZE (0)
#endif
#if !defined(APPMEM_PICT_BRIDGE_POOL_SIZE)
    #define APPMEM_PICT_BRIDGE_POOL_SIZE (0)
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

typedef union
{
    kal_uint8 DUFAULT_POOL[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPLIB_MEM_AP_POOL_DEFAULT_SIZE)];
    kal_uint8 APP_UNIT_TEST[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_TEST_POOL_SIZE)];
    kal_uint8 APP_BLG[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_BGL_BUFFER_POOL_SIZE)];
    kal_uint8 APP_IGL[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_IGL_POOL_SIZE)]; 
    kal_uint8 APP_AVATAR[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_AVATAR_POOL_SIZE)];
    kal_uint8 APP_BR[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_BR_APP_TOTAL_SIZE)];
    kal_uint8 APP_J2ME[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_JAVA_POOL_SIZE)];
    kal_uint8 APP_PHOEDT[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_PHOEDT_POOL_SIZE)];
    kal_uint8 APP_JATAAYU[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_JATAAYU_WAP_POOL_SIZE)];
    kal_uint8 APP_BROWSER[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_BROWSER_POOL_SIZE)];
    kal_uint8 APP_VDOEDT[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_VDOEDT_POOL_SIZE)];
    kal_uint8 APP_CAMERA[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_CAMERA_POOL_SIZE)];
    kal_uint8 APP_DICTIONARY[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_DICTIONARY_POOL_SIZE)];
    kal_uint8 APP_LANGLN[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_LANGLN_POOL_SIZE)];
    kal_uint8 APP_MTV[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_MTV_PLAYER_POOL_SIZE)];
    kal_uint8 APP_GIS[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_GIS_BUFFER_POOL_SIZE)];    
    kal_uint8 APP_SLIDESHOW[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_SLIDESHOW_POOL_SIZE)];
    kal_uint8 APP_ABREPEAT[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APP_MEM_ABREPEAT_BUILD_CACHE_POOL_SIZE)];
    kal_uint8 APP_BT_BIP[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_BT_BIP_SIZE)];
    kal_uint8 APP_BR_JATAYU[APPLIB_MEM_CONC2_AP_POOL_SIZE(APPMEM_BR_APP_TOTAL_SIZE, APPMEM_JATAAYU_WAP_POOL_SIZE)];
    kal_uint8 APP_BR_OBIGO[APPLIB_MEM_CONC2_AP_POOL_SIZE(APPMEM_BR_APP_TOTAL_SIZE, APPMEM_BROWSER_POOL_SIZE)];
    kal_uint8 APP_J2ME_OBIGO[APPLIB_MEM_CONC2_AP_POOL_SIZE(APPMEM_JAVA_MIN_POOL_SIZE, APPMEM_BROWSER_POOL_SIZE)];
    kal_uint8 APP_PICT_BRIDGE[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_PICT_BRIDGE_POOL_SIZE)];
} app_asm_pool_union;

#define APPLIB_MEM_AP_POOL_SIZE sizeof(app_asm_pool_union)

#endif /* APP_MEM_CONFIG_H */ 

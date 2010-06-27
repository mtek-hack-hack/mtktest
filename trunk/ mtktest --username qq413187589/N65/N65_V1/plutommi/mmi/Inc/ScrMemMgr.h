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
 *  ScrMemMgr.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Register Screen-Based ASM
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
#ifndef _SCR_MEM_MGR_H_
#define _SCR_MEM_MGR_H_

/***************************************************************************** 
* Include
*****************************************************************************/

#ifndef __MMI_FEATURES__
#error "Please include MMI_features.h first"
#endif 

#include "app_mem.h"        /* macro for computing pool size */

/***************************************************************************** 
* Define
*****************************************************************************/
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

/* NOTE: We use byte to calculate buffer size */

/* Video Category */ //061506 double buffer
#ifdef __MMI_VIDEO_PLAYER__
    #include "wgui_categories_multimedia.h"

    #define VIDEO_CATEGORY_POOL_SIZE   (BLACK_BUFFER_SIZE+STATUS_ICON_BAR_DOUBLE_BUFFER_SIZE)
    S32 vdo_cat_mem = (VIDEO_CATEGORY_POOL_SIZE);
#endif

/* Camera */
#ifdef __MMI_CAMERA__
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"
    #include "mdi_datatype.h"
    #include "mdi_camera.h"
    #include "MMI_features_camera.h"
    #include "CameraApp.h"

    #define SCRMEM_CAMERA_POOL_SIZE     (CAMERA_OSD_BUFFER_SIZE+CAMERA_TILE_RESULT_BUFFER_SIZE+CAMERA_OVERLAY_FRAME_BUFFER_SIZE)
    S32 cam_mem = (SCRMEM_CAMERA_POOL_SIZE);
#endif /* __MMI_CAMERA__ */ 

/* Imageviewer */
#ifdef __MMI_IMAGE_VIEWER__
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"
    #include "FileManagerGprot.h"
    #include "filemgr.h"
    #include "Imageviewer.h"

    #define SCRMEM_IMAGEVIEWER_POOL_SIZE      (MMI_IMGADV_TOTAL_MEMORY_SIZE)
    S32 imageviewer_mem = (SCRMEM_IMAGEVIEWER_POOL_SIZE);
#endif /* __MMI_IMAGE_VIEWER__ */ 

/* Mobile TV player */
#ifdef __MMI_MOBILE_TV_PLAYER__
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"
    #include "MobileTVPlayerGprot.h"

    #define SCRMEM_MTVPLAYER_POOL_SIZE      (MMI_MTV_PLAYER_SCR_MEM_SIZE)
#endif /* __MMI_MOBILE_TV_PLAYER__ */ 

/* Video Player */
#ifdef __MMI_VIDEO_PLAYER__
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"
    #include "VdoPlyGProt.h"

    #define SCRMEM_VDOPLY_POOL_SIZE     (VDOPLY_OSD_BUFFER_SIZE)
    S32 vdoply_mem = (SCRMEM_VDOPLY_POOL_SIZE);
#endif /* __MMI_VIDEO_PLAYER__ */ 

/* Video Recorder */
#ifdef __MMI_VIDEO_RECORDER__
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"
    #include "VdoRecGProt.h"

    #define SCRMEM_VDOREC_POOL_SIZE     (VDOREC_OSD_BUFFER_SIZE+VDOREC_OVERLAY_FRAME_BUFFER_SIZE)
    S32 vdorec_mem = (SCRMEM_VDOREC_POOL_SIZE);
#endif /* __MMI_VIDEO_RECORDER__ */ 

/* AUDPLY LYRICS */
#ifdef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
    #include "AudioPlayerDef.h"

    #define SCRMEM_LYRICS_POOL_SIZE     (AUDPLY_LYRIC_STR_BUFF_MAX_SIZE)
    S32 lyrics_mem = (SCRMEM_LYRICS_POOL_SIZE);
#endif /* __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__ */ 

/* AUDPLY Progress Bar */
#ifdef __MMI_AUDIO_PLAYER__
    #include "AudioPlayerDef.h"

    #define SCRMEM_AUDPLY_PROGRESS_POOL_SIZE     (BUILD_CACHE_FILE_BUF_SIZE + BUILD_CACHE_PROC_BUF_SIZE)
    S32 audply_progrss_mem = (SCRMEM_AUDPLY_PROGRESS_POOL_SIZE);
#endif /* __MMI_AUDIO_PLAYER__ */ 

/* File Manager UI */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_SLIM_FILE_MANAGER__)
	#include "FileManagerGProt.h"

	#define SCRMEM_FMGR_POOL_SIZE		(FMGR_THUMB_IMAGE_BUFFER_SIZE)
	S32 fmgr_mem = (SCRMEM_FMGR_POOL_SIZE);		
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_SLIM_FILE_MANAGER__) */

/* Touch Ring Composer */
#ifdef __MMI_TOUCH_RING_COMPOSER__
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"

    #ifdef __MMI_MAINLCD_176X220__
        #define SCRMEM_TOUCH_RING_COMP_POOL_SIZE  (41*23*__MMI_MAIN_BASE_LAYER_FORMAT__)
    #elif defined (__MMI_MAINLCD_240X320__)
        #define SCRMEM_TOUCH_RING_COMP_POOL_SIZE  (63*31*__MMI_MAIN_BASE_LAYER_FORMAT__)
    #elif defined (__MMI_MAINLCD_320X240__)
        #define SCRMEM_TOUCH_RING_COMP_POOL_SIZE  (70*30*__MMI_MAIN_BASE_LAYER_FORMAT__)
    #else 
        #define SCRMEM_TOUCH_RING_COMP_POOL_SIZE  (63*31*__MMI_MAIN_BASE_LAYER_FORMAT__)
    #endif /* __MMI_MAINLCD_176X220 __*/
    S32 touch_ring_comp_mem = (SCRMEM_TOUCH_RING_COMP_POOL_SIZE);
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

/* Handwriting Stroke Layer */
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"

    #define SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE ((GDI_LCD_WIDTH *GDI_LCD_HEIGHT * (GDI_MAINLCD_BIT_PER_PIXEL>>3) + 3) & (~3))
    S32 handwriting_stroke_layer_mem = (SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE);
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

/* Barcode Reader */
#ifdef __MMI_BARCODEREADER__
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"
    #include "BarcodeReaderGprot.h"

    #define SCRMEM_BARCODEREADER_POOL_SIZE     (BR_SCR_TOTAL_SIZE)
    S32 barcodereader_mem = (SCRMEM_BARCODEREADER_POOL_SIZE);
#endif /* __MMI_BARCODEREADER__ */ 

/* 062206 EMS category Start */
/* EMS category */
#ifdef __MMI_MESSAGES_EMS__
    #include "wgui_categories_ems.h"

    #define EMS_CATEGORY_POOL_SIZE  (CAT_144_DATA_FILE_SIZE)
    S32 ems_category_mem = (EMS_CATEGORY_POOL_SIZE);
#endif 
/* 062206 EMS buffer End */

#ifdef __MMI_MESSAGES_CHAT__
	#include "wgui_categories_inputs.h"

	#define SCRMEM_CHATMSG_BUFFER_SIZE  CHAT_MESSAGE_BUFFER
	S32 chat_msg_buffer_mem = SCRMEM_CHATMSG_BUFFER_SIZE;
#endif /* __MMI_MESSAGES_CHAT__ */



/* NEW APPLICATIONS: add here! */
/* Calendar */
#ifdef __MMI_CALENDAR_V2__
    #include "wgui_calendar.h"

    #ifdef __MMI_BPP_SUPPORT__
        #include "wgui_categories_calendar.h"
        #include "CalendarDef.h"
        
        #define CALENDAR_SNAPSHOT_POOL_SIZE  (T_SIZE)
	#else
		#define CALENDAR_SNAPSHOT_POOL_SIZE  (0)
	#endif
    #define CALENDAR_POOL_SIZE  (CALENDAR_CACHE_CELL_SIZE+CALENDAR_CACHE_POPUP_SIZE+CALENDAR_SNAPSHOT_POOL_SIZE)
    S32 calendar_mem = CALENDAR_POOL_SIZE;
#endif /* __MMI_CALENDAR_V2__ */

/*Birthday Reminder*/
#ifdef __MMI_BIRTHDAY_REMINDER__
    #include "PhoneBookTypes.h"
    #include "nvram_common_defs.h"
    #include "ToDoListDef.h"
    
    #define BIRTHDAY_REMINDER_POOL_SIZE (NVRAM_EF_PHB_BIRTHDAY_SIZE * NVRAM_EF_PHB_BIRTHDAY_TOTAL + TDL_BIRTHDAY_INDEX_POOL)    
#endif /*__MMI_BIRTHDAY_REMINDER__*/

/* Unified Composer */
#ifdef __MMI_UNIFIED_COMPOSER__
    #include "UnifiedMessageGProt.h"
    #include "UnifiedComposerGProt.h"

	#define SCRMEM_UC_POOL_SIZE MMI_UC_UTF8_TEXT_BUFFER_SIZE
	S32 uc_mem = (SCRMEM_UC_POOL_SIZE);
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
	/*SMS Archive box*/
	#ifdef __MMI_MESSAGES_SMSARCH__
        #define SMS_ARCH_MAX_BUF_SIZE (100+ MMI_SMS_MAX_MSG_SEG *160)
        #define SMSARCH_CATEGORY_POOL_SIZE  (SMS_ARCH_MAX_BUF_SIZE)
        S32 smsarch_category_mem = (SMSARCH_CATEGORY_POOL_SIZE);
    #endif /* __MMI_MESSAGES_SMSARCH__ */
#endif/*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

/* PS_EMS */
#if defined(__EMS_REL5__)
	#include "customer_ps_inc.h"

	#define EMS_BUFFER_SIZE  (MMI_SMS_MAX_MSG_SEG * 140 * EMS_RATIO_OF_OBJ_PDU_BUFF) /* EMS_ONE_MSG_OCTET = 140 */
	S32 ems_buffer_mem = EMS_BUFFER_SIZE;
#endif /* __EMS_REL5__ */

/* Q03C MMS SMIL Editor (none Unified Composer), may be concurrent with the handwriting */
#if defined (__MMI_MMS__) && defined (OBIGO_Q03C) && !defined (JATAAYU_SUPPORT) && !defined (__MMI_UNIFIED_COMPOSER__) && (defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)) /* ref. msf_cfg.h */
    #include "widget_ctk.h"   
    #define SCRMEM_MMS_SMIL_EDITOR_POOL_SIZE    (WIDGET_CTK_SE_IMAGE_CACHE_BUF_SIZE)
#endif

/* Q03C MMS viewer support the video */
#if defined (__MMI_MMS__) && defined (OBIGO_Q03C) && !defined (JATAAYU_SUPPORT) && !defined (__MMI_UNIFIED_COMPOSER__) && defined(__MMI_VIDEO_PLAYER__)
    #define SCRMEM_MMS_VIEWER_VIDEO_POOL_SIZE    ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT* __MMI_MAIN_BASE_LAYER_FORMAT__)*3/2)
#endif

/* cat265 for channel list */
#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
    #include "wgui_categories_list.h"
    #define SCRMEM_CAT265_POOL_SIZE (CAT265_PREVIEW_AREA_SIZE)
    S32 cat265_buffer_mem = SCRMEM_CAT265_POOL_SIZE;
#endif

/*language learning*/
#if defined (__MMI_LANGLN__)
    #define LANGLN_MAX_BUF_SIZE (10 * 1024)
#endif /* __MMI_LANGLN__ */

/* Main Menu Category */
#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
    #include "wgui.h"
    
    #define SCRMEM_MAINMENU_CATEGORY_POOL_SIZE  (MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE)
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */

/* avatar */
#if defined(__MMI_AVATAR__)
    #include "avatargprot.h"
    #define SCRMEM_AVATAR_MAX_BUF_SIZE (MMI_AVATAR_SCR_MEM_SIZE)
#endif

/* Round to multiple of 4 */
#define SCRMEM_ALIGN_TO_4(_x)  (((_x) + 3) & ~3)

/* Image viewer may allocate 50 image cache entries */
#ifdef LOW_COST_SUPPORT
	#define APPLIB_MEM_SCREEN__POOL_OVERHEAD     (APPLIB_MEM_GET_POOL_EXTRA_SIZE(10))
#else
	#define APPLIB_MEM_SCREEN__POOL_OVERHEAD     (APPLIB_MEM_GET_POOL_EXTRA_SIZE(50))
#endif

/*Ebook*/
#ifdef __MMI_BPP_SUPPORT__
    #include "EbookGprot.h"

    #define EBOOK_POOL_SIZE (EBR_RECORD_SIZE_MAX * 2 + 10)
#endif /*__MMI_BPP_SUPPORT__*/

/* 
 * All unregistered screen can use memory up to APPLIB_MEM_SCREEN_MIN_POOL_SIZE 
 * Add extra size for overheads of 3 blocks per screen 
 */
#define APPLIB_MEM_SCREEN_POOL_DEFAULT_SIZE (APPLIB_MEM_SCREEN_MIN_POOL_SIZE + APPLIB_MEM_GET_POOL_EXTRA_SIZE(3))

#define APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(size)    \
	(SCRMEM_ALIGN_TO_4(size) + APPLIB_MEM_SCREEN__POOL_OVERHEAD) 

#define APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(size1, size2)    \
    (SCRMEM_ALIGN_TO_4(size1) + SCRMEM_ALIGN_TO_4(size2) + APPLIB_MEM_SCREEN__POOL_OVERHEAD) 

#define APPLIB_MEM_CONC3_SCREEN_POOL_SIZE(size1, size2, size3)    \
    (SCRMEM_ALIGN_TO_4(size1) + SCRMEM_ALIGN_TO_4(size2) + SCRMEM_ALIGN_TO_4(size3) + APPLIB_MEM_SCREEN__POOL_OVERHEAD)

/***************************************************************************** 
 * Please define your pool size to zero if it is not defined before!
 *****************************************************************************/
#if !defined(APPLIB_MEM_SCREEN_POOL_DEFAULT_SIZE)
    #define APPLIB_MEM_SCREEN_POOL_DEFAULT_SIZE (0)
#endif
#if !defined(VIDEO_CATEGORY_POOL_SIZE)
    #define VIDEO_CATEGORY_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_CAMERA_POOL_SIZE)
    #define SCRMEM_CAMERA_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_IMAGEVIEWER_POOL_SIZE)
    #define SCRMEM_IMAGEVIEWER_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_VDOPLY_POOL_SIZE)
    #define SCRMEM_VDOPLY_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_VDOREC_POOL_SIZE)
    #define SCRMEM_VDOREC_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_LYRICS_POOL_SIZE)
    #define SCRMEM_LYRICS_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_AUDPLY_PROGRESS_POOL_SIZE)
    #define SCRMEM_AUDPLY_PROGRESS_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_FMGR_POOL_SIZE)
    #define SCRMEM_FMGR_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_TOUCH_RING_COMP_POOL_SIZE)
    #define SCRMEM_TOUCH_RING_COMP_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE)
    #define SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_BARCODEREADER_POOL_SIZE)
    #define SCRMEM_BARCODEREADER_POOL_SIZE (0)
#endif
#if !defined(EMS_CATEGORY_POOL_SIZE)
    #define EMS_CATEGORY_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_CHATMSG_BUFFER_SIZE)
    #define SCRMEM_CHATMSG_BUFFER_SIZE (0)
#endif
#if !defined(CALENDAR_POOL_SIZE)
    #define CALENDAR_POOL_SIZE (0)
#endif
#if !defined(BIRTHDAY_REMINDER_POOL_SIZE)
    #define BIRTHDAY_REMINDER_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_UC_POOL_SIZE)
    #define SCRMEM_UC_POOL_SIZE (0)
#endif
#if !defined(SMSARCH_CATEGORY_POOL_SIZE)
    #define SMSARCH_CATEGORY_POOL_SIZE (0)
#endif
#if !defined(EMS_BUFFER_SIZE)
    #define EMS_BUFFER_SIZE (0)
#endif
#if !defined(SCRMEM_MMS_SMIL_EDITOR_POOL_SIZE)
    #define SCRMEM_MMS_SMIL_EDITOR_POOL_SIZE (0)
#endif

#if !defined(SCRMEM_MMS_VIEWER_VIDEO_POOL_SIZE)
    #define SCRMEM_MMS_VIEWER_VIDEO_POOL_SIZE (0)
#endif

#if !defined(SCRMEM_CAT265_POOL_SIZE)
    #define SCRMEM_CAT265_POOL_SIZE (0)
#endif
#if !defined(LANGLN_MAX_BUF_SIZE)
    #define LANGLN_MAX_BUF_SIZE (0)
#endif
#if !defined(SCRMEM_MTVPLAYER_POOL_SIZE)
    #define SCRMEM_MTVPLAYER_POOL_SIZE (0)
#endif
#if !defined(SCRMEM_MAINMENU_CATEGORY_POOL_SIZE)
    #define SCRMEM_MAINMENU_CATEGORY_POOL_SIZE (0)
#endif

#if !defined(SCRMEM_AVATAR_MAX_BUF_SIZE)
    #define SCRMEM_AVATAR_MAX_BUF_SIZE (0)
#endif

#if !defined(EBOOK_POOL_SIZE)
    #define EBOOK_POOL_SIZE (0)
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef union
{
    U8 DEFAULT_POOL[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(APPLIB_MEM_SCREEN_POOL_DEFAULT_SIZE)];
    U8 SCR_VIDEO_CATEGORY[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(VIDEO_CATEGORY_POOL_SIZE)]; 					/* Video Category *///061506 double buffer
    U8 SCR_CAMERA[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_CAMERA_POOL_SIZE)];								/* Camera */
    U8 SCR_IMAGEVIEWER[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_IMAGEVIEWER_POOL_SIZE)];					/* Imageviewer */
	U8 SCR_VDOPLY[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_VDOPLY_POOL_SIZE)];								/* Video Player */
	U8 SCR_VDOREC[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_VDOREC_POOL_SIZE)];								/* Video Recorder */
	U8 SCR_LYRICS[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_LYRICS_POOL_SIZE)];								/* Audply Lyrics */ 
	U8 SCR_AUDPLY_PROGRESS[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_AUDPLY_PROGRESS_POOL_SIZE)];			/* Audply Progress Bar */
	U8 SCR_FMGR[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_FMGR_POOL_SIZE)];									/* File Manager UI */
	U8 SCR_TOUCH_RING_COMP[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_TOUCH_RING_COMP_POOL_SIZE)];			/* Touch Ring Composer */
	U8 SCR_TOUCH_HANDWRITING[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE)];	/* Handwriting */
	U8 SCR_BARCODEREADER_COMP[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_BARCODEREADER_POOL_SIZE)];			/* Barcode Reader*/
	U8 SCR_EMS_CATEGORY[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(EMS_CATEGORY_POOL_SIZE)];						/* 062206 EMS category */
	U8 SCR_CHATMSG[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_CHATMSG_BUFFER_SIZE)];
	U8 SCR_CALENDAR[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(CALENDAR_POOL_SIZE)];								/* Calendar */
	U8 SCR_BIRTHDAY_REMINDER[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(BIRTHDAY_REMINDER_POOL_SIZE)];				/*BIRTHDAY_REMINDER*/
	U8 SCR_UC[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_UC_POOL_SIZE)];										/* Unified Composer */
	U8 SCR_SMS_CATEGORY[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SMSARCH_CATEGORY_POOL_SIZE)];					/*SMS Archive box*/    
	U8 SCR_EMS[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(EMS_BUFFER_SIZE)];										/* PS_EMS */
    U8 SCR_MMS_EDITOR[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_MMS_SMIL_EDITOR_POOL_SIZE)];                /* MMS editor */
    U8 SCR_MMS_VIEWER[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_MMS_VIEWER_VIDEO_POOL_SIZE)];               /* MMS viewer */
    U8 SCR_CAT265[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_CAT265_POOL_SIZE)];                             /* CAT265 */
    U8 SCR_LANGLN[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(LANGLN_MAX_BUF_SIZE)];                                 /* LANGLN */
    U8 SCR_MTV[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_MTVPLAYER_POOL_SIZE)];                             /* MOBILE TV */
    U8 SCR_MAINMENU_CATEGORY[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_MAINMENU_CATEGORY_POOL_SIZE)];       /* Main Menu Category */
    U8 SCR_AVATAR[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(SCRMEM_AVATAR_MAX_BUF_SIZE)];                             /* AVATAR */
    U8 SCR_AUDPLY_LYRICS[APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(SCRMEM_AUDPLY_PROGRESS_POOL_SIZE, SCRMEM_LYRICS_POOL_SIZE)];    
    U8 SCR_HANDWRITING_DEFAULT[APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE, APPLIB_MEM_SCREEN_POOL_DEFAULT_SIZE)];
    U8 SCR_HANDWRITING_CHATMSG[APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE, SCRMEM_CHATMSG_BUFFER_SIZE)];
    U8 SCR_HANDWRITING_UC[APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE, SCRMEM_UC_POOL_SIZE)];
    U8 SCR_HANDWRITING_EMS[APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE, EMS_BUFFER_SIZE)];
    U8 SCR_HANDWRITING_MMS[APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(SCRMEM_HANDWRITING_STROKE_LAYER_POOL_SIZE, SCRMEM_MMS_SMIL_EDITOR_POOL_SIZE)];
    U8 SCR_CALENDAR_BIRTHDAY_REMINDER[APPLIB_MEM_CONC2_SCREEN_POOL_SIZE(CALENDAR_POOL_SIZE, BIRTHDAY_REMINDER_POOL_SIZE)];   
    U8 SCR_EBOOK_BUFFER[APPLIB_MEM_SCREEN_POOL_SIZE_CONFIG(EBOOK_POOL_SIZE)];				/*BIRTHDAY_REMINDER*/
} screen_asm_pool_union;

/*
 * Define MMI_FRM_SCRMEM_POOL_SIZE
 */
#define MMI_FRM_SCRMEM_POOL_SIZE sizeof(screen_asm_pool_union)
/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/

#endif /* _SCR_MEM_MGR_H_ */ 


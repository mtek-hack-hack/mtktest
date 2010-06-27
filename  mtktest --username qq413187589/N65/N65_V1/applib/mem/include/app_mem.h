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
 *  app_mem.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public interface of ASM (application-shared memory)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef APP_MEM_H
#define APP_MEM_H

#ifndef _KAL_NON_SPECIFIC_GENERAL_TYPES_H
#error "Please include kal_release.h/kal_non_specific_general_types.h before this file"
#endif

/* Toggle ASM unit test */
#undef APPLIB_MEM_UNIT_TEST

/* Number of dwords in header/footer guard patterns
   Ex: APPLIB_MEM_GUARDPAT_LEN is 1 -> 4 byte. 
   Increasing the length may help catch memory corruption  */
#define APPLIB_MEM_GUARDPAT_LEN             (1)

/* Guard pattern in header of allocated chunk */
#define APPLIB_MEM_HEADER_PATTERN1          (0xAAAAAAAA)
/* Guard pattern in header of released chunk */
#define APPLIB_MEM_HEADER_PATTERN2          (0xBBBBBBBB)
/* Guard pattern in footer of allocated chunk */
#define APPLIB_MEM_FOOTER_PATTERN1          (0xCCCCCCCC)
/* Guard pattern in footer of released chunk */
#define APPLIB_MEM_FOOTER_PATTERN2          (0xDDDDDDDD)

/* Header of a chunk (4n bytes) */
typedef struct _applib_mem_header_struct
{
    kal_uint32 owner_id;                                   /* screen ID or application ID */
    kal_uint32 chunk_size;                                 /* allocated size round to 4 */
    kal_uint32 guard_pattern[APPLIB_MEM_GUARDPAT_LEN];     /* guard pattern */
    struct _applib_mem_header_struct *next;                /* next allocated chunk */
} applib_mem_header_struct;

/* Footer of a chunk (4n bytes) */
typedef struct
{
    kal_uint32 guard_pattern[APPLIB_MEM_GUARDPAT_LEN];     /* guard pattern */
} applib_mem_footer_struct;

/* (Inaccurate) upper bound of internal structures used by KAL ADM */
#define APPLIB_MEM_POOL_EXTRA_SIZE          (256)

/* Overhead used by each block.
   12 byte (KAL ADM) + chunk header + chunk footer */
#define APPLIB_MEM_CHUNK_EXTRA_SIZE         \
            (12 + sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct))

/* Get extra space needed for memory pool.
   Parameter 'n' is the expected number of allocations */
#define APPLIB_MEM_GET_POOL_EXTRA_SIZE(n)   \
            (APPLIB_MEM_POOL_EXTRA_SIZE + (n) * APPLIB_MEM_CHUNK_EXTRA_SIZE)

/***************************************************************************** 
 * Application-based ASM 
 *****************************************************************************/

/* 
 * Please register the application that use ASM in app_mem_config.h before
 * using the following API
 */
typedef enum {
    APPLIB_MEM_AP_ID_DUMMY = 0,
#ifdef APPLIB_MEM_UNIT_TEST
    APPLIB_MEM_AP_ID_TEST1,
    APPLIB_MEM_AP_ID_TEST2,
    APPLIB_MEM_AP_ID_TEST3,
    APPLIB_MEM_AP_ID_TEST4,
    APPLIB_MEM_AP_ID_TEST5,
#endif /* APPLIB_MEM_UNIT_TEST */    

    /********* INSERT NEW APPLICATION HERE *********/
    APPLIB_MEM_AP_3D_GAME,
    APPLIB_MEM_AP_ID_PHOEDT,
#ifdef __J2ME__
    APPLIB_MEM_AP_ID_JAVA,
#endif
    APPLIB_MEM_AP_ID_BARCODEREADER,
    APPLIB_MEM_AP_ID_UNIFIED_COMPOSER,
#if defined(JATAAYU_SUPPORT) && defined(WAP_SUPPORT) && !defined(JMMS_IN_OBIGO)
    APPLIB_MEM_AP_ID_JATAAYU_WAP,
#endif
#ifdef OBIGO_Q05A
    APPLIB_MEM_AP_ID_BROWSER,
#endif
    APPLIB_MEM_AP_ID_VDOEDT,
    APPLIB_MEM_AP_ID_MMS_VIEWER,
    APPLIB_MEM_AP_ID_AVATAR,
    APPLIB_MEM_AP_ID_DICTIONARY,
    APPLIB_MEM_AP_ID_PICT_BRIDGE,
    APPLIB_MEM_AP_ID_CAMERA,
    APPLIB_MEM_AP_ID_LANGLN,
    APPLIB_MEM_AP_ID_GIS,
    APPLIB_MEM_AP_ID_MTV_PLAYER,
    APPLIB_MEM_AP_ID_SLIDESHOW,
    APPLIB_MEM_AP_ID_AB_REPEATER,
    APPLIB_MEM_AP_ID_BT_BIP,

    APPLIB_MEM_AP_ID_TOTAL
} applib_mem_ap_id_enum;

/* output by applib_mem_ap_get_current_usage */
typedef struct {
    kal_uint32 app_id;
    kal_uint32 string_id;
    kal_uint32 icon_id;
    kal_uint32 mem_size;
    kal_bool is_stopping;
} applib_mem_ap_usage_struct;

/* system-level API invoked by MMI framework, not for applications */
extern void applib_mem_ap_init(void (*stop_finish_callback_by_MMI)(kal_uint32, kal_uint32, kal_bool));
extern void applib_mem_ap_stop_app_by_MMI_task(kal_uint32 app_id);
extern kal_uint32 applib_mem_ap_get_current_usage(
                    applib_mem_ap_usage_struct *applist, 
                    kal_uint32 max_items);

/* application registeration & stop callback */
extern void applib_mem_ap_register(
                kal_uint32 app_id, 
                kal_uint32 app_string_id, 
                kal_uint32 app_icon_id,
                void (*stop_callback_by_MMI)(void));
extern void applib_mem_ap_notify_stop_finished(kal_uint32 app_id, kal_bool result);

/* alloc/free */
extern void *applib_mem_ap_alloc(kal_uint32 app_id, kal_uint32 mem_size);
extern void *applib_mem_ap_alloc_full_pool(kal_uint32 app_id, kal_uint32 *pool_size);

extern void applib_mem_ap_free(void *mem_ptr);
extern void applib_mem_ap_free_all(kal_uint32 app_id);

/* query status */
extern kal_uint32 applib_mem_ap_get_total_left_size(void);
extern kal_uint32 applib_mem_ap_get_max_alloc_size(void);
extern kal_uint32 applib_mem_ap_get_pool_size(void);
extern kal_uint32 applib_mem_ap_get_alloc_count(void);

/* integrity check */
extern kal_bool applib_mem_ap_is_valid_block(void *mem_ptr);
extern void applib_mem_ap_check_integrity(void);

/* let applications check if app-asm is initialized */
extern kal_bool applib_mem_ap_is_initialized(void);

/***************************************************************************** 
 * Screen-based ASM 
 *****************************************************************************/

/* 
 * 1. Please register the screens using ASM in ScrMemMgr.h 
 * 2. If a screen uses memory under APPLIB_MEM_SCREEN_MIN_POOL_SIZE,  
 *    it's not required to register it in ScrMemMgr.h 
 */
#define APPLIB_MEM_SCREEN_MIN_POOL_SIZE     (512)

extern void applib_mem_screen_init(
                kal_uint32 (*screen_id_callback)(void), 
                kal_uint32 pool_size, 
                void *pool_ptr);

extern void *applib_mem_screen_alloc(kal_uint32 mem_size);
extern void applib_mem_screen_free(void *mem_ptr);
extern void applib_mem_screen_free_all(void);

extern kal_uint32 applib_mem_screen_get_total_left_size(void);
extern kal_uint32 applib_mem_screen_get_max_alloc_size(void);
extern kal_uint32 applib_mem_screen_get_pool_size(void);
extern kal_uint32 applib_mem_screen_get_alloc_count(void);

extern kal_bool applib_mem_screen_is_valid_block(void *mem_ptr);
extern void applib_mem_screen_check_integrity(void);

#endif /* APP_MEM_H */ 


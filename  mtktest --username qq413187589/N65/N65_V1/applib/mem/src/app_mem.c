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
 *  app_mem.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  ASM (Application Shared Memory)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define APP_MEM_C

/* Only applied to Pluto MMI */
#if !defined(NEPTUNE_MMI) && !defined(MMI_NOT_PRESENT) && !defined(EMPTY_MMI)

#include "kal_release.h"
#include "app_mem.h"
#include "app_mem_config.h"
#include "kal_adm.h"
#include "QueueGprot.h"
#include "mmiapi_func.h"

#define APPLIB_MEM_USE_ADM

/* Check if _ptr is 4-byte aligned */
#define APPLIB_MEM_ALIGNED_4(_ptr)          ((((kal_uint32)(_ptr)) & 3) == 0)

/* Check if _n is power of 2 */
#define APPLIB_MEM_TEST_POWER_2(_n)         ((_n) && !((_n) & ((_n) - 1)))

/* Check if _ptr is n-byte aligned */
#define APPLIB_MEM_ALIGNED_N(_ptr, _n)      (APPLIB_MEM_TEST_POWER_2(_n) && \
                                             !(((kal_uint32)(_ptr)) & ((_n) - 1)))
#ifdef WIN32
#define __align(x)
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* Context */

typedef void (*ap_stop_hdlr_type)(void);

typedef struct
{
    /* Initialized */
    kal_bool app_pool_inited;

    /* ADM pool ID of app-based ASM. If it is 0, applib_mem_ap_alloc_full_pool() was invoked. */
    KAL_ADM_ID app_pool_id;

    /* Count of allocated app-based blocks */
    kal_int32 app_alloc_count;

    /* Callback handler to process the result of stopping application in MMI task */
    void (*app_stop_finish_callback)(kal_uint32 app_id, kal_uint32 string_id, kal_bool result);

    /* Head node of app-based chunk */
    applib_mem_header_struct app_head;

    /* Application using applib_mem_ap_alloc_full_pool() */
    kal_uint32 app_id_of_full_pool;
    
    /* Handlers to stop application (executed in MMI task) */
    ap_stop_hdlr_type app_stop_callbacks[APPLIB_MEM_AP_ID_TOTAL];
    /* Application name table */
    kal_uint32 app_names[APPLIB_MEM_AP_ID_TOTAL];
    /* Application icon table */
    kal_uint32 app_icons[APPLIB_MEM_AP_ID_TOTAL];
    /* Application has not finished stopping */
    kal_bool app_is_stopping[APPLIB_MEM_AP_ID_TOTAL];
    /* Multi-thread mutex */
    kal_mutexid app_asm_mutex;

    /* ADM pool ID of screen-based ASM */
    KAL_ADM_ID screen_pool_id;
    /* Size of screen-based ASM pool */
    kal_uint32 screen_pool_size;    
    /* Count of allocated screen-based blocks */
    kal_int32 screen_alloc_count;
    /* Callback handler to get the current screen ID */
    kal_uint32 (*screen_id_callback)(void);
    /* Head node of screen-based chunk */
    applib_mem_header_struct screen_head;
} applib_mem_cntx_struct;

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/
    
/* Context of screen-based memory */
static applib_mem_cntx_struct g_applib_mem_cntx;

/* memory pool */
#ifdef __MTK_TARGET__
#pragma arm section zidata = "LARGEPOOL_FIRST_ZI"
#endif 

#if APPLIB_MEM_AP_POOL_ALIGN > 0
/* 
 * There is an ARM ADS issue.
 * 
 * If APPLIB_MEM_AP_POOL_SIZE is 1.2MB and __align(512*1024),
 * the pool g_applib_mem_ap_pool[] will take 1.5MB. 
 *
 * As a result, we do not set __align here. Instead, the alignment
 * is configured in the scatter files.
 *
 * (Note: this issue no longer exists in ARM RVCT)
 */
// __align(APPLIB_MEM_AP_POOL_ALIGN)
#endif
/* Use kal_uint32 to be 4-byte aligned */
static kal_uint32 g_applib_mem_ap_pool[APPLIB_MEM_AP_POOL_SIZE/4];

#ifdef __MTK_TARGET__
#pragma arm section zidata
#endif 

/* for KAL ADM */
static const kal_uint32 g_applib_mem_pool_chunk_size[11] = 
{
    16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 0xffffffff, 0
};

#define ASM_USING_MUTEX     /* Default solution is to open mutex */

#ifdef ASM_USING_MUTEX
#define APP_ASM_LOCK        kal_take_mutex(g_applib_mem_cntx.app_asm_mutex)
#define APP_ASM_UNLOCK      kal_give_mutex(g_applib_mem_cntx.app_asm_mutex)
#else  /* ASM_USING_MUTEX */
#define APP_ASM_LOCK
#define APP_ASM_UNLOCK
#endif /* ASM_USING_MUTEX */

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

 
/*****************************************************************************
 * FUNCTION
 *  APPLIB_MEM_SET_PATTERN
 * DESCRIPTION
 *  Fill guard pattern
 * PARAMETERS
 *  ptr         [OUT]       data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  void
 *****************************************************************************/
#if APPLIB_MEM_GUARDPAT_LEN == 1
#define APPLIB_MEM_SET_PATTERN(ptr, pattern)  do {(*ptr) = (pattern);} while (0)
#else /* APPLIB_MEM_GUARDPAT_LEN == 1 */
static void APPLIB_MEM_SET_PATTERN(kal_uint32 *ptr, kal_uint32 pattern)
{
    kal_int32 i;
    for (i = 0; i < APPLIB_MEM_GUARDPAT_LEN; i++)
    {
        ptr[i] = pattern;
    }
}
#endif /* APPLIB_MEM_GUARDPAT_LEN == 1 */


/*****************************************************************************
 * FUNCTION
 *  APPLIB_MEM_COMP_PATTERN
 * DESCRIPTION
 *  Compare if the guard pattern is correct
 * PARAMETERS
 *  ptr         [IN]        data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  return KAL_FALSE if the guard pattern is corrupted
 *****************************************************************************/
#if APPLIB_MEM_GUARDPAT_LEN == 1
#define APPLIB_MEM_COMP_PATTERN(ptr, pattern)	((kal_bool)((*ptr) == (pattern)))
#else /* APPLIB_MEM_GUARDPAT_LEN == 1 */
static kal_bool APPLIB_MEM_COMP_PATTERN(const kal_uint32 *ptr, kal_uint32 pattern)
{
    kal_int32 i;
    for (i = 0; i < APPLIB_MEM_GUARDPAT_LEN; i++)
    {
        if (ptr[i] != pattern)
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}
#endif /* APPLIB_MEM_GUARDPAT_LEN == 1 */

/*****************************************************************************              
 * Extern Global Variable                                                                    
 *****************************************************************************/

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/

/***************************************************************************** 
 * Application-based ASM 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_init
 * DESCRIPTION
 *  Initialize app-based ASM.
 *  (The API is used by MMI framework only)
 * PARAMETERS
 *  stop_finish_callback_by_MMI    [IN]    callback to handle stopping application result (executed in MMI task)
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_init(void (*stop_finish_callback_by_MMI)(kal_uint32 app_id, kal_uint32 string_id, kal_bool result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    /* 
     * Check the alignment of the whole pool. 
     * 
     * When Java FBBR is enabled, the whole pool must be aligned to 256-KB or 512-KB.
     *
     * Scatter files should set the alignment. For example:
     * 
     * ------------------------------------------------
     *
     * EXTSRAM_LARGEPOOL_NORMAL 0x08000000  (The address is subject to change)
     * {
     *     ;app-based ASM always at first due to Java FBBR
     *     app_mem.obj (LARGEPOOL_FIRST_ZI) 
     *
     *     ...
     */
    EXT_ASSERT(
        (APPLIB_MEM_AP_POOL_ALIGN == 0) || APPLIB_MEM_ALIGNED_N(g_applib_mem_ap_pool, APPLIB_MEM_AP_POOL_ALIGN),
        (kal_uint32) g_applib_mem_ap_pool,
        APPLIB_MEM_AP_POOL_ALIGN,
        0);
#endif /* __MTK_TARGET__ */
    
    if (g_applib_mem_cntx.app_pool_inited)
    {
        /* Already initialized */
        return;
    }
    
#ifdef APPLIB_MEM_USE_ADM
    g_applib_mem_cntx.app_pool_id = kal_adm_create(
                                        g_applib_mem_ap_pool,
                                        APPLIB_MEM_AP_POOL_SIZE,
                                        (kal_uint32*) g_applib_mem_pool_chunk_size,
                                        KAL_FALSE);
#else /* APPLIB_MEM_USE_ADM */
    g_applib_mem_cntx.app_pool_id = APPLIB_DUMMY_POOL_ID;
#endif /* APPLIB_MEM_USE_ADM */

    g_applib_mem_cntx.app_alloc_count = 0;
    
    ASSERT(stop_finish_callback_by_MMI != NULL);
    g_applib_mem_cntx.app_stop_finish_callback = stop_finish_callback_by_MMI;

    g_applib_mem_cntx.app_head.next = NULL;

    g_applib_mem_cntx.app_pool_inited = KAL_TRUE;

    #ifdef ASM_USING_MUTEX
    g_applib_mem_cntx.app_asm_mutex = kal_create_mutex("app_asm_mutex");
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_is_initialized
 * DESCRIPTION
 *  check if applib app-asm is initialized
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool applib_mem_ap_is_initialized(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.app_pool_inited;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_stop_app_by_MMI_task
 * DESCRIPTION
 *  Stop an application. This function must be invoked by MMI task only.
 *  (The API is used by MMI framework only)
 * PARAMETERS
 *  app_id    [IN]    ID of the application to be stopped
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_stop_app_by_MMI_task(kal_uint32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(app_id < APPLIB_MEM_AP_ID_TOTAL &&
           !g_applib_mem_cntx.app_is_stopping[app_id]); /* Not stopped before */

    g_applib_mem_cntx.app_is_stopping[app_id] = KAL_TRUE;
    (g_applib_mem_cntx.app_stop_callbacks[app_id])();
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_current_usage
 * DESCRIPTION
 *  List memory consumption by current applications 
 *  (The API is used by MMI framework only) 
 * PARAMETERS
 *  applist     [OUT]    List of applications and its memory consumption
 *  max_items   [IN]     The maximum size of 'applist'
 * RETURNS
 *  the number of applications listed
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_current_usage(applib_mem_ap_usage_struct *applist, kal_uint32 max_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 item_count;
    applib_mem_header_struct *node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    if (g_applib_mem_cntx.app_pool_id)  /* Normal mode */
    {
        item_count = 0;
        node = g_applib_mem_cntx.app_head.next;
        while (node)
        {
            kal_int32 idx;
            for (idx = 0; idx < item_count; idx++)
            {
                if (applist[idx].app_id == node->owner_id)
                {
                    break;
                }
            }
            
            if (idx == item_count)
            {
                if (item_count == max_items)
                {
                    node = node->next;
                    continue;
                }
                else
                {
                    applist[item_count].app_id = node->owner_id;
                    applist[item_count].string_id = g_applib_mem_cntx.app_names[node->owner_id];
                    applist[item_count].icon_id = g_applib_mem_cntx.app_icons[node->owner_id];
                    applist[item_count].mem_size = 0;
                    applist[item_count].is_stopping = g_applib_mem_cntx.app_is_stopping[node->owner_id];
                    item_count++;
                }
            }

            applist[idx].mem_size += node->chunk_size + APPLIB_MEM_CHUNK_EXTRA_SIZE;
            
            node = node->next;
        }
    }
    else  /* Full pool mode */
    {
        item_count = 0;
        if (g_applib_mem_cntx.app_alloc_count)
        {
            kal_uint32 app_id = g_applib_mem_cntx.app_id_of_full_pool;
            applist[item_count].app_id = app_id;
            applist[item_count].string_id = g_applib_mem_cntx.app_names[app_id];
            applist[item_count].icon_id = g_applib_mem_cntx.app_icons[app_id];
            applist[item_count].mem_size = APPLIB_MEM_AP_POOL_SIZE;
            applist[item_count].is_stopping = g_applib_mem_cntx.app_is_stopping[app_id];
			item_count++;
        }
    }
    APP_ASM_UNLOCK;
    
    return item_count;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_register
 * DESCRIPTION
 *  Register an application that uses app-based ASM
 *
 *  Remark: 
 *  1. This function should be used when an application is initialized at boot
 *  2. 'stop_callback_by_MMI' is executed in MMI task. If we need to notify another 
 *     task to stop the application, please send primitive (source module: MOD_MMI) 
 *     to the destination task inside the registered function 'stop_callback_by_MMI'.
 * 
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  app_id                  [IN]    Application ID defined in applib_mem_ap_id_enum
 *  app_string_id           [IN]    The MMI string ID of application name
 *  app_icon_id             [IN]    The MMI image ID of application icon
 *  stop_callback_by_MMI    [IN]    Callback function when user chooses to stop the application
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_register(
        kal_uint32 app_id, 
        kal_uint32 app_string_id, 
        kal_uint32 app_icon_id, 
        void (*stop_callback_by_MMI)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(app_id < APPLIB_MEM_AP_ID_TOTAL && 
           app_string_id &&
           stop_callback_by_MMI);
    g_applib_mem_cntx.app_stop_callbacks[app_id] = stop_callback_by_MMI;
    g_applib_mem_cntx.app_names[app_id] = app_string_id;
    g_applib_mem_cntx.app_icons[app_id] = app_icon_id;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_notify_stop_finished
 * DESCRIPTION
 *  This function is invoked by an application to notify MMI framework when 
 *  it was requested to be stopped and it finished the stop operation.
 *  (Memory used by it are all released)
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_id      [IN]    ID of the application requested to stop (applib_mem_ap_id_enum)
 *  result      [IN]    Whether the stop operation succeeded or not
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_notify_stop_finished(kal_uint32 app_id, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: We should handle non-MMI task in the future!
    ASSERT(mmiapi_is_MMI_task());

#ifdef DEBUG_KAL
    /* Note: If memory allocated by applib_mem_ap_alloc_full_pool() is released,  
       it should create ADM pool again. */
    ASSERT(g_applib_mem_cntx.app_pool_id);
    if (result)
    {
        /* Its memory should be released */
        applib_mem_header_struct *node;
        APP_ASM_LOCK;
        node = g_applib_mem_cntx.app_head.next;
        while (node)
        {
            ASSERT(node->owner_id != app_id);
            node = node->next;
        }
        APP_ASM_UNLOCK;
    }
#endif /* DEBUG_KAL */

    g_applib_mem_cntx.app_is_stopping[app_id] = KAL_FALSE;

    g_applib_mem_cntx.app_stop_finish_callback(app_id, g_applib_mem_cntx.app_names[app_id], result);
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_max_alloc_size_int
 * DESCRIPTION
 *  internal api of applib_mem_ap_get_max_alloc_size
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum available allocation size in byte
 *****************************************************************************/
static kal_uint32 applib_mem_ap_get_max_alloc_size_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APPLIB_MEM_USE_ADM
    if (g_applib_mem_cntx.app_pool_id)
    {
         result = kal_adm_get_max_alloc_size(g_applib_mem_cntx.app_pool_id);
         if (result <= (sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct)))
         {
             result = 0;
         }
         else
         {
             result -= (sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct));
         }
    }
    return result;
#else /* APPLIB_MEM_USE_ADM */ 
    return (10 * 1024 * 1024);  /* Return dummy value */
#endif /* APPLIB_MEM_USE_ADM */
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc
 * DESCRIPTION
 *  Allocate app-based ASM
 *
 *  Remark:
 *  1. It might return NULL if the allocation failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using applib_mem_ap_alloc() 100 times.
 *
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  app_id          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  mem_size        [IN]        Memory size
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
void *applib_mem_ap_alloc(kal_uint32 app_id, kal_uint32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;
    applib_mem_footer_struct *footer;
    kal_uint32 chunk_size;
    void *chunk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    if (!g_applib_mem_cntx.app_pool_id)  /* The whole pool was allocated by applib_mem_ap_alloc_full_pool() */
    {
        APP_ASM_UNLOCK;
        return NULL;
    }
    
    ASSERT(g_applib_mem_cntx.app_stop_callbacks[app_id] && g_applib_mem_cntx.app_names[app_id]); /* App registered */
    
    chunk_size = (((mem_size + 3) >> 2) << 2);  /* round to multiple of 4 */
    if (chunk_size == 0)
    {
        /* To avoid return NULL when allocated size = 0 */
        chunk_size = 4;
    }

    if (chunk_size > applib_mem_ap_get_max_alloc_size_int())    /* Make sure there are enough memory to use now */
    {
        APP_ASM_UNLOCK;
        return NULL;
    }

#ifdef APPLIB_MEM_USE_ADM
    chunk = kal_adm_alloc(
                g_applib_mem_cntx.app_pool_id,
                chunk_size + sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct));
#else /* APPLIB_MEM_USE_ADM */
    chunk = malloc((size_t) chunk_size + sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct));
#endif /* APPLIB_MEM_USE_ADM */

    if (chunk == NULL)
    {
        APP_ASM_UNLOCK;
        return NULL;
    }

    header = (applib_mem_header_struct*) chunk;
    chunk = header + 1;
    footer = (applib_mem_footer_struct*) (((char*)chunk) + chunk_size);

    /* header */
    header->owner_id = app_id;
    header->chunk_size = chunk_size;
    APPLIB_MEM_SET_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN1);    
    
    /* footer */    
    APPLIB_MEM_SET_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN1);

    /* update linked list */
    header->next = g_applib_mem_cntx.app_head.next;
    g_applib_mem_cntx.app_head.next = header;

    /* system context */
    g_applib_mem_cntx.app_alloc_count++;
    APP_ASM_UNLOCK;

    return chunk;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_alloc_full_pool
 * DESCRIPTION
 *  Allocate the whole pool of app-based ASM
 *
 *  Note: it is typically used with APPLIB_MEM_AP_POOL_ALIGN to get a aligned 
 *  buffer pool (Example: Java FBBR requires 256KB or 512KB alignment)
 * PARAMETERS
 *  app_id          [IN]        ID of owner application (applib_mem_ap_id_enum)
 *  pool_size       [OUT]       Allocated size (== the whole pool size)
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
void *applib_mem_ap_alloc_full_pool(kal_uint32 app_id, kal_uint32 *pool_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    if (g_applib_mem_cntx.app_alloc_count)
    {
        APP_ASM_UNLOCK;
        return NULL;
    }

    if (g_applib_mem_cntx.app_pool_id)
    {
    #ifdef APPLIB_MEM_USE_ADM
        kal_adm_delete(g_applib_mem_cntx.app_pool_id);
    #endif
        g_applib_mem_cntx.app_pool_id = 0;
    }

    g_applib_mem_cntx.app_id_of_full_pool = app_id;
    g_applib_mem_cntx.app_alloc_count = 1;
    APP_ASM_UNLOCK;
    *pool_size = APPLIB_MEM_AP_POOL_SIZE;
    return g_applib_mem_ap_pool;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free_int
 * DESCRIPTION
 *  Internal api to free app-based ASM
 *
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to be released
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_mem_ap_free_int(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header, *prev_node, *remove_node;
    applib_mem_footer_struct *footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_applib_mem_cntx.app_pool_id)    /* Normal mode */
    {
        ASSERT(mem_ptr && APPLIB_MEM_ALIGNED_4(mem_ptr));
        
        header = ((applib_mem_header_struct*) mem_ptr) - 1;
        footer = (applib_mem_footer_struct*) (((char*)mem_ptr) + header->chunk_size);

        ASSERT(APPLIB_MEM_COMP_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN1) && 
               APPLIB_MEM_COMP_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN1));

        /* 
         * Remove the block from linked list 
         *
         * It is not a fast algorithm, we can improve it by using double linked list, 
         * but we choose simpler design because
         * 1. Typically total allocation count is small
         * 2. We don't want to increase space overheads
         * 3. We don't want to access KAL ADM internal data structure
         */
        prev_node = &g_applib_mem_cntx.app_head;    
        ASSERT(prev_node->next);
        for (remove_node = prev_node->next;
             remove_node; 
             prev_node = remove_node, remove_node = prev_node->next)
        {
            if (remove_node == header)
            {
                break;
            }
        }
        ASSERT(remove_node);
        prev_node->next = remove_node->next;
        
        /* Set guard pattern */
        APPLIB_MEM_SET_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN2);    
        APPLIB_MEM_SET_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN2);

        /* Release the block */
    #ifdef APPLIB_MEM_USE_ADM
        kal_adm_free(g_applib_mem_cntx.app_pool_id, header);
    #else 
        free(header);
    #endif 

        ASSERT(g_applib_mem_cntx.app_alloc_count > 0);
        g_applib_mem_cntx.app_alloc_count--;
    }
    else /* Full pool mode */
    {
        ASSERT(mem_ptr == g_applib_mem_ap_pool && g_applib_mem_cntx.app_alloc_count == 1);
        g_applib_mem_cntx.app_alloc_count = 0;
        g_applib_mem_cntx.app_id_of_full_pool = APPLIB_MEM_AP_ID_DUMMY; /* 0 */
        
    #ifdef APPLIB_MEM_USE_ADM    
        g_applib_mem_cntx.app_pool_id = kal_adm_create(
                                            g_applib_mem_ap_pool,
                                            APPLIB_MEM_AP_POOL_SIZE,
                                            (kal_uint32*) g_applib_mem_pool_chunk_size,
                                            KAL_FALSE);
    #else /* APPLIB_MEM_USE_ADM */
        g_applib_mem_cntx.app_pool_id = APPLIB_DUMMY_POOL_ID;
    #endif /* APPLIB_MEM_USE_ADM */
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free
 * DESCRIPTION
 *  Free app-based ASM
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to be released
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_free(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    applib_mem_ap_free_int(mem_ptr);
    APP_ASM_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_free_all
 * DESCRIPTION
 *  Release all app-based ASM belong to an application
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_free_all(kal_uint32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *node, *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    if (g_applib_mem_cntx.app_pool_id)  /* Normal mode */
    {
        node = g_applib_mem_cntx.app_head.next;
        while (node)
        {
            next = node->next;
            if (node->owner_id == app_id)
            {
                applib_mem_ap_free_int(node + 1);
            }
            node = next;
        }
    }
    else /* Full pool mode */
    {
        ASSERT(g_applib_mem_cntx.app_alloc_count == 1);
        g_applib_mem_cntx.app_alloc_count = 0;
        g_applib_mem_cntx.app_id_of_full_pool = APPLIB_MEM_AP_ID_DUMMY; /* 0 */
        
    #ifdef APPLIB_MEM_USE_ADM    
        g_applib_mem_cntx.app_pool_id = kal_adm_create(
                                            g_applib_mem_ap_pool,
                                            APPLIB_MEM_AP_POOL_SIZE,
                                            (kal_uint32*) g_applib_mem_pool_chunk_size,
                                            KAL_FALSE);
    #else /* APPLIB_MEM_USE_ADM */
        g_applib_mem_cntx.app_pool_id = APPLIB_DUMMY_POOL_ID;
    #endif /* APPLIB_MEM_USE_ADM */        
    }
    APP_ASM_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_total_left_size
 * DESCRIPTION
 *  Get available size of app-based ASM.
 *
 *  Remark: this function is only suggested for *debug* purpose because
 *  1. The memory pool may be fragmented (total left free space is meaningless 
 *     if the pool has serious memory fragmentation)
 *  2. Even if the free space is contiguous, sometimes we still cannot allocate 10 * 10KB blocks 
 *     with 100KB free space because of the overheads of memory management bookkeeping
 *
 *  Please use applib_mem_ap_get_max_alloc_size() or applib_mem_ap_get_pool_size()
 *  instead.
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left space in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APPLIB_MEM_USE_ADM
    APP_ASM_LOCK;
    if (g_applib_mem_cntx.app_pool_id)
    {
        result = kal_adm_get_total_left_size(g_applib_mem_cntx.app_pool_id); 
        if (result <= (sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct)))
        {
            result = 0;
        }
        else
        {
            result -= (sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct));
        }
    }
    APP_ASM_UNLOCK;
    return result;
#else /* APPLIB_MEM_USE_ADM */ 
    return (10 * 1024 * 1024);  /* Return dummy value */
#endif /* APPLIB_MEM_USE_ADM */ 
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_max_alloc_size
 * DESCRIPTION
 *  Get the max possible size of single allocation from app-based ASM. 
 *  Return value of it is typically less than applib_mem_ap_get_total_left_size()
 *  if the pool is fragmented.
 *
 *  Remark: we can use this function to dynamically decide the allocation size 
 *  (for example, use larger image cache when there is more memory)
 *  
 *  However, sometimes we cannot allocate 2 * 10KB blocks if the maximum allocation size 
 *  is 20KB because of the overheads of memory management bookkeeping. 
 *
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according
 *  to the free space
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task.
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum available allocation size in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_max_alloc_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APPLIB_MEM_USE_ADM
    APP_ASM_LOCK;
    result = applib_mem_ap_get_max_alloc_size_int();
    APP_ASM_UNLOCK;
    return result;
#else /* APPLIB_MEM_USE_ADM */ 
    return (10 * 1024 * 1024);  /* Return dummy value */
#endif /* APPLIB_MEM_USE_ADM */
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_pool_size
 * DESCRIPTION
 *  Return the fixed size of app-based ASM pool
 *
 *  Remark: we can use this function to decide the maximum possible memory 
 *  we can allocate (the whole pool size).
 * 
 *  However, sometimes we cannot allocate 10 * 10KB blocks in an 100KB memory pool
 *  because of the overheads of memory management bookkeeping. 
 *  
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according
 *  to the pool size:
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Pool size in byte
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_pool_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return APPLIB_MEM_AP_POOL_SIZE - APPLIB_MEM_POOL_EXTRA_SIZE - APPLIB_MEM_CHUNK_EXTRA_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_get_alloc_count
 * DESCRIPTION
 *  Return the number of allocated blocks
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of allocated blocks
 *****************************************************************************/
kal_uint32 applib_mem_ap_get_alloc_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.app_alloc_count;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_is_valid_block_int
 * DESCRIPTION
 *  Internal static function of applib_mem_ap_is_valid_block
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to check
 * RETURNS
 *  Return KAL_TRUE if 'mem_ptr' is a valid block
 *****************************************************************************/
static kal_bool applib_mem_ap_is_valid_block_int(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;
    applib_mem_footer_struct *footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_applib_mem_cntx.app_pool_id)
    {
        if (!mem_ptr || !APPLIB_MEM_ALIGNED_4(mem_ptr))
        {
            return KAL_FALSE;
        }
        
        header = ((applib_mem_header_struct*) mem_ptr) - 1;
        footer = (applib_mem_footer_struct*) (((char*)mem_ptr) + header->chunk_size);

        if (APPLIB_MEM_COMP_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN1) &&
            APPLIB_MEM_COMP_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN1) &&
            header->owner_id < APPLIB_MEM_AP_ID_TOTAL)
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else
    {
        if (g_applib_mem_cntx.app_alloc_count > 0 && 
            mem_ptr == g_applib_mem_ap_pool)
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_is_valid_block
 * DESCRIPTION
 *  Check if a app-based ASM memory block is valid by inspecting its guard patterns.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to check
 * RETURNS
 *  Return KAL_TRUE if 'mem_ptr' is a valid block
 *****************************************************************************/
kal_bool applib_mem_ap_is_valid_block(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    result = applib_mem_ap_is_valid_block_int(mem_ptr);
    APP_ASM_UNLOCK;    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_check_integrity
 * DESCRIPTION
 *  Check if the internal state of app-based ASM is correct. 
 *  If not, then ASSERT!
 *
 *  Remark: This function takes a lot of computation time, and it should not be
 *  used in normal case. 
 *  The function call can be inserted in application code when we need to locate 
 *  hard-to-find memory corruption issue.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_check_integrity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    APP_ASM_LOCK;
    if (g_applib_mem_cntx.app_pool_id)
    {
        
        node = g_applib_mem_cntx.app_head.next;
        while (node)
        {
            ASSERT(applib_mem_ap_is_valid_block_int(node + 1));
            node = node->next;
        }
    }
    APP_ASM_UNLOCK;
}

/***************************************************************************** 
 * Screen-based ASM 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_init
 * DESCRIPTION
 *  Initialize screen-based ASM.
 * PARAMETERS
 *  screen_id_callback  [IN]    callback handler to get current MMI screen ID
 *  pool_size           [IN]    size for screen-based ASM 
 *  pool_ptr            [IN]    pre-allocated memory pool for screen-based ASM 
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_screen_init(
        kal_uint32 (*screen_id_callback)(void), 
        kal_uint32 pool_size, 
        void *pool_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(APPLIB_MEM_ALIGNED_4(pool_ptr));
    if (g_applib_mem_cntx.screen_pool_id != 0)
    {
        /* Already initialized */
        return;
    }
    
#ifdef APPLIB_MEM_USE_ADM
    g_applib_mem_cntx.screen_pool_id = kal_adm_create(
                                        pool_ptr,
                                        pool_size,
                                        (kal_uint32*) g_applib_mem_pool_chunk_size,
                                        KAL_FALSE);
#else /* APPLIB_MEM_USE_ADM */
    g_applib_mem_cntx.screen_pool_id = 0;
#endif /* APPLIB_MEM_USE_ADM */

    g_applib_mem_cntx.screen_pool_size = pool_size;

    g_applib_mem_cntx.screen_alloc_count = 0;
    
    ASSERT(screen_id_callback != NULL);
    g_applib_mem_cntx.screen_id_callback = screen_id_callback;

    g_applib_mem_cntx.screen_head.next = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_alloc
 * DESCRIPTION
 *  Allocate screen-based ASM
 *
 *  Remark:
 *  1. It might return NULL if the allocate failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using applib_mem_screen_alloc() 100 times.
 *
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_size        [IN]        Memory size
 * RETURNS
 *  Allocated memory block
 *****************************************************************************/
void *applib_mem_screen_alloc(kal_uint32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;
    applib_mem_footer_struct *footer;
    kal_uint32 chunk_size;
    void *chunk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chunk_size = (((mem_size + 3) >> 2) << 2);  /* round to multiple of 4 */
    if (chunk_size == 0)
    {
        /* To avoid return NULL when allocated size = 0 */
        chunk_size = 4;
    }

#ifdef APPLIB_MEM_USE_ADM
    chunk = kal_adm_alloc(
                g_applib_mem_cntx.screen_pool_id,
                chunk_size + sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct));
#else /* APPLIB_MEM_USE_ADM */
    chunk = malloc((size_t) chunk_size + sizeof(applib_mem_header_struct) + sizeof(applib_mem_footer_struct));
#endif /* APPLIB_MEM_USE_ADM */

    if (chunk == NULL)
    {
        return NULL;
    }

    header = (applib_mem_header_struct*) chunk;
    chunk = header + 1;
    footer = (applib_mem_footer_struct*) (((char*)chunk) + chunk_size);

    /* header */
    header->owner_id = g_applib_mem_cntx.screen_id_callback();
    header->chunk_size = chunk_size;
    APPLIB_MEM_SET_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN1);    
    
    /* footer */    
    APPLIB_MEM_SET_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN1);

    /* update linked list */
    header->next = g_applib_mem_cntx.screen_head.next;
    g_applib_mem_cntx.screen_head.next = header;

    /* system context */
    g_applib_mem_cntx.screen_alloc_count++;

    return chunk;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_free
 * DESCRIPTION
 *  Free screen-based ASM
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to be released
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_screen_free(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header, *prev_node, *remove_node;
    applib_mem_footer_struct *footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mem_ptr && APPLIB_MEM_ALIGNED_4(mem_ptr));
    
    header = ((applib_mem_header_struct*) mem_ptr) - 1;
    footer = (applib_mem_footer_struct*) (((char*)mem_ptr) + header->chunk_size);

    ASSERT(APPLIB_MEM_COMP_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN1) && 
           APPLIB_MEM_COMP_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN1));

    /* 
     * Remove the block from linked list 
     *
     * It is not a fast algorithm, we can improve it by using double linked list, 
     * but we choose simpler design because
     * 1. Typically total allocation count is small
     * 2. We don't want to increase space overheads
     * 3. We don't want to access KAL ADM internal data structure
     */
    prev_node = &g_applib_mem_cntx.screen_head;    
    ASSERT(prev_node->next);
    for (remove_node = prev_node->next;
         remove_node; 
         prev_node = remove_node, remove_node = prev_node->next)
    {
        if (remove_node == header)
        {
            break;
        }
    }
    ASSERT(remove_node);
    prev_node->next = remove_node->next;
    
    /* Set guard pattern */
    APPLIB_MEM_SET_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN2);    
    APPLIB_MEM_SET_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN2);

    /* Release the block */
#ifdef APPLIB_MEM_USE_ADM
    kal_adm_free(g_applib_mem_cntx.screen_pool_id, header);
#else 
    free(header);
#endif 

    ASSERT(g_applib_mem_cntx.screen_alloc_count > 0);
    g_applib_mem_cntx.screen_alloc_count--;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_free_all
 * DESCRIPTION
 *  Release all screen-based ASM
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_screen_free_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *node, *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = g_applib_mem_cntx.screen_head.next;
    while (node)
    {
        next = node->next;
        applib_mem_screen_free(node + 1);
        node = next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_total_left_size
 * DESCRIPTION
 *  Get available size of screen-based ASM.
 *
 *  Remark: this function is only suggested for *debug* purpose because
 *  1. The memory pool may be fragmented (total left free space is meaningless 
 *     if the pool has serious memory fragmentation)
 *  2. Even if the free space is contiguous, we still cannot allocate 10 * 10KB blocks 
 *     with 100KB free space because of the overheads of memory management bookkeeping
 *
 *  Please use applib_mem_screen_get_max_alloc_size() or applib_mem_screen_get_pool_size()
 *  instead.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left space in byte
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APPLIB_MEM_USE_ADM
    return kal_adm_get_total_left_size(g_applib_mem_cntx.screen_pool_id) -
        sizeof(applib_mem_header_struct) - sizeof(applib_mem_footer_struct);
#else /* APPLIB_MEM_USE_ADM */ 
    return (10 * 1024 * 1024);  /* Return dummy value */
#endif /* APPLIB_MEM_USE_ADM */ 
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_max_alloc_size
 * DESCRIPTION
 *  Get the max possible size of single allocation of screen-based ASM.
 *  Return value of it is typically less than applib_mem_screen_get_total_left_size()
 *  if the pool is fragmented.
 *
 *  Remark: we can use this function to dynamically decide the allocation size 
 *  (for example, use larger image cache when there is more memory)
 *  
 *  However, sometimes we cannot allocate 2 * 10KB blocks if the maximum allocation size 
 *  is 20KB because of overheads of memory management bookkeeping. 
 *
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively according to 
 *  the free space.
 *  Step 1. Decide the size of free space => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Maximum allocation size in byte
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_max_alloc_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APPLIB_MEM_USE_ADM
    return kal_adm_get_max_alloc_size(g_applib_mem_cntx.screen_pool_id) -
        sizeof(applib_mem_header_struct) - sizeof(applib_mem_footer_struct);
#else /* APPLIB_MEM_USE_ADM */ 
    return (10 * 1024 * 1024);  /* Return dummy value */
#endif /* APPLIB_MEM_USE_ADM */
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_pool_size
 * DESCRIPTION
 *  Return the fixed size of screen-based ASM pool
 *
 *  Remark: we can use this function to decide the maximum possible memory 
 *  we can allocate (the whole pool size)
 * 
 *  However, we still cannot allocate 10 * 10KB blocks in an 100KB memory pool
 *  because of the overheads of memory management bookkeeping. 
 *  
 *  It is suggested to use "fail-safe" allocation regardless the internal 
 *  implementation of ASM if we want to allocate more memory adaptively 
 *  according to the pool size:
 *  Step 1. Decide pool size => e.g. 100KB
 *  Step 2. Allocate 100KB
 *  Step 3. If failed, allocate 95 KB
 *  Step 4. If failed, allocate 90 KB
 *  Step 5. ...
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  Pool size in byte
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_pool_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.screen_pool_size - 
           APPLIB_MEM_POOL_EXTRA_SIZE - APPLIB_MEM_CHUNK_EXTRA_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_get_alloc_count
 * DESCRIPTION
 *  Return the number of allocated blocks
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of allocated blocks
 *****************************************************************************/
kal_uint32 applib_mem_screen_get_alloc_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_applib_mem_cntx.screen_alloc_count;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_is_valid_block
 * DESCRIPTION
 *  Check if a screen-based ASM memory block is valid by 
 *      1. Inspecting its guard patterns
 *      2. Checking if it belongs to the current MMI screen.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to check
 * RETURNS
 *  Return KAL_TRUE if 'mem_ptr' is a valid block
 *****************************************************************************/
kal_bool applib_mem_screen_is_valid_block(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *header;
    applib_mem_footer_struct *footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mem_ptr || !APPLIB_MEM_ALIGNED_4(mem_ptr))
    {
        return KAL_FALSE;
    }
    
    header = ((applib_mem_header_struct*) mem_ptr) - 1;
    footer = (applib_mem_footer_struct*) (((char*)mem_ptr) + header->chunk_size);

    if (APPLIB_MEM_COMP_PATTERN(header->guard_pattern, APPLIB_MEM_HEADER_PATTERN1) &&
        APPLIB_MEM_COMP_PATTERN(footer->guard_pattern, APPLIB_MEM_FOOTER_PATTERN1) && 
        header->owner_id == g_applib_mem_cntx.screen_id_callback())
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_check_integrity
 * DESCRIPTION
 *  Check if the internal state of screen-based ASM is correct. 
 *  If not, then ASSERT!
 *
 *  Remark: This function takes a lot of computation time, and it should not be
 *  used in normal case. 
 *  The function call can be inserted in application code when we need to locate 
 *  hard-to-find memory corruption issue.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_screen_check_integrity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_header_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = g_applib_mem_cntx.screen_head.next;
    while (node)
    {
        ASSERT(applib_mem_screen_is_valid_block(node + 1));
        node = node->next;
    }
}


/***************************************************************************** 
 * Unit Test 
 *****************************************************************************/

#ifdef APPLIB_MEM_UNIT_TEST

#include "stdlib.h"


/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_simple_test
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_screen_simple_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *ptr_list[100];
    kal_int32 i, count, free_space_original, tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_screen_free_all();
    free_space_original = applib_mem_screen_get_total_left_size();

#define ALLOC_SIZE(_idx)    ((_idx) + (_idx) * 256)
#define PTR_LIST_SIZE       (sizeof(ptr_list) / sizeof(void*))

    for (i = 0; i < PTR_LIST_SIZE; i++)
    {
        if ((ptr_list[i] = applib_mem_screen_alloc(ALLOC_SIZE(i))) == NULL)
        {
            ASSERT(applib_mem_screen_get_max_alloc_size() < ALLOC_SIZE(i));
            break;
        }
    }

    count = i;
    ASSERT(count > 0);
    ASSERT(applib_mem_screen_get_alloc_count() == count);

    applib_mem_screen_check_integrity();

    tmp = 0;
    for (i = 0; i < count; i += 2)
    {
        tmp += ALLOC_SIZE(i);
        applib_mem_screen_free(ptr_list[i]);
    }

    ASSERT(tmp < free_space_original - applib_mem_screen_get_total_left_size());

    applib_mem_screen_check_integrity();

    if (count >= 2)
    {
        for (i = 1; i < count; i += 2)
        {
            ASSERT(applib_mem_screen_is_valid_block(ptr_list[i]));
        }
    }

    applib_mem_screen_check_integrity();

    applib_mem_screen_free_all();

    ASSERT(free_space_original == applib_mem_screen_get_total_left_size());
    ASSERT(applib_mem_screen_get_alloc_count() == 0);    

    /* Random alloc/free */

    for (i = 0; i < PTR_LIST_SIZE; i++)
    {
        ptr_list[i] = NULL;
    }

    for (;;)
    {
        kal_int32 key = rand();
        if ((key % 1000) == 0)
        {
            break;
        }
        
        if (applib_mem_screen_get_alloc_count() == PTR_LIST_SIZE ||
            key % 3 == 0)
        {
            i = ((key + 1) % PTR_LIST_SIZE);
            for (; i != key % PTR_LIST_SIZE; i++, i %= PTR_LIST_SIZE)
            {
                if (ptr_list[i])
                {
                    applib_mem_screen_free(ptr_list[i]);
                    ptr_list[i] = NULL;
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i < PTR_LIST_SIZE; i++)
            {
                if (!ptr_list[i])
                {
                    kal_uint32 size = key % applib_mem_screen_get_pool_size();
                    ptr_list[i] = applib_mem_screen_alloc(size);
                    /* Test memory corruption detection */
                    // ptr_list[i][size/4] = 1;
                    // ptr_list[i][size/4 + 1] = 1;
                    // ptr_list[i][size/4 + 2] = 1;
                    break;
                }
            }
        }
        applib_mem_screen_check_integrity();
    }

    applib_mem_screen_free_all();
    ASSERT(free_space_original == applib_mem_screen_get_total_left_size());
    ASSERT(applib_mem_screen_get_alloc_count() == 0);        
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_unit_test_stress_test
 * DESCRIPTION
 *  Stress test for app-based asm synchronization
 * PARAMETERS
 *  app_id    [IN]    application ID
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_unit_test_stress_test(kal_uint32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *ptr_list[100];
    kal_uint32 i, alloc_count, tmp_size;
    kal_uint32 original_free_space, full_pool_size;
    void *full_pool_ptr;
    static kal_uint8 first = 1;
    kal_uint32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    #define ALLOC_MEM_SIZE(_idx)    (_idx + _idx * 32)
    #define PTR_LIST_ARRAY_SIZE       (sizeof(ptr_list) / sizeof(void *))
    APP_ASM_LOCK;
    if (first)
    {
        first = 0;
        APP_ASM_UNLOCK;
        kal_get_my_task_index(&index);
        ASSERT(applib_mem_ap_get_alloc_count() == 0);

        full_pool_ptr = applib_mem_ap_alloc_full_pool(app_id, &full_pool_size);
        ASSERT(applib_mem_ap_is_valid_block(full_pool_ptr));
        ASSERT(applib_mem_ap_get_alloc_count() == 1);

        applib_mem_ap_free(full_pool_ptr);
        ASSERT(!applib_mem_ap_is_valid_block(full_pool_ptr));
        ASSERT(applib_mem_ap_get_alloc_count() == 0);
               
    }
	else
	{
		APP_ASM_UNLOCK;
	}
    kal_get_my_task_index(&index);
   
    applib_mem_ap_free_all(app_id);
    original_free_space = applib_mem_ap_get_total_left_size();

    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        if (applib_mem_ap_get_total_left_size() < applib_mem_ap_get_max_alloc_size())
        {
            /* Test if software could stop here */
            int i, j;
            i = 5;
            j = 6;
            i += j;
        }
        if ((ptr_list[i] = applib_mem_ap_alloc(app_id, ALLOC_MEM_SIZE(i))) == NULL)
        {
            /* can't make sure ASSERT(applib_mem_ap_get_max_alloc_size() < ALLOC_MEM_SIZE(i)) for this api between multi-thread */
            break;
        }
        else
        {
            memset(ptr_list[i], 0, ALLOC_MEM_SIZE(i));
        }
    }
    alloc_count = i;
    ASSERT(applib_mem_ap_get_alloc_count() >= alloc_count);
    applib_mem_ap_check_integrity();

    tmp_size = 0;
    for (i = 0; i < alloc_count; i++)
    {
        if (i & 0x1)
        {
            /* Keep odd nodes allocated */
            tmp_size += ALLOC_MEM_SIZE(i);
        }
        else
        {
            /* Free even nodes allocated */
            applib_mem_ap_free(ptr_list[i]);
        }
    }
    applib_mem_ap_check_integrity();

    if (alloc_count >= 2)
    {
        for (i = 1; i < alloc_count; i += 2)
        {
            ASSERT(applib_mem_ap_is_valid_block(ptr_list[i]));
        }
    }

    applib_mem_ap_free_all(app_id);
    applib_mem_ap_check_integrity();

    /* Random stress test */
    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        ptr_list[i] = NULL;
    }

    for ( ; ; )
    {
        kal_uint32 key = rand();                        /* random start position */
        if (key % 10 == 0)
        {
            break;                                      /* exit for loop */
        }

        i = (key + 1) % PTR_LIST_ARRAY_SIZE;
        if (key % 2 == 0)
        {
            while(i != key % PTR_LIST_ARRAY_SIZE)        /* random operation position */
            {
                if (ptr_list[i])
                {
                    applib_mem_ap_free(ptr_list[i]);
                    ptr_list[i] = NULL;
                    break;
                }
                 i = rand() % PTR_LIST_ARRAY_SIZE;
            }
        }
        else
        {
            for (; i != key % PTR_LIST_ARRAY_SIZE; i++, i %= PTR_LIST_ARRAY_SIZE)
            {
                if (!ptr_list[i])
                {
                    kal_uint32 size = key % applib_mem_ap_get_pool_size();
                    ptr_list[i] = applib_mem_ap_alloc(app_id, size);
                    if (ptr_list[i])
                    {
                        memset(ptr_list[i], 0, size);
                    }
                    break;
                }
            }
        }
        applib_mem_ap_check_integrity();
    }
    applib_mem_ap_free_all(app_id);
    applib_mem_ap_check_integrity();
}

#endif /* APPLIB_MEM_UNIT_TEST */

#endif /* !defined(NEPTUNE_MMI) && !defined(MMI_NOT_PRESENT) && !defined(EMPTY_MMI) */



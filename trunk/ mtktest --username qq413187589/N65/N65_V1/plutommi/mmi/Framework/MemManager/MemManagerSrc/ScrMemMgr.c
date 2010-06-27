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
 *  ScrMemMgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Screen-Based Shared Memory Manager
 *
 *  Screen-based shared memory is allocated after entering a screen, and 
 *  released before leaving a screen. 
 *
 *  Screen-based memory must be released before or inside screen exit function;
 *  otherwise, it asserts.
 * 
 *  Screen-based shared memory is deterministic. Because all memory are released
 *  when switching screens, memory fragmentation is restricted inside a screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "GlobalDefs.h"
#include "ScrMemMgr.h"
#include "app_mem.h"
#include "FrameworkGprot.h"
#include "FrameworkProt.h"
#include "DebugInitDef.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

/* memory pool */
#ifdef __MTK_TARGET__
#pragma arm section zidata = "LARGEPOOL_ZI"
#endif 

static U32 g_mmi_frm_scrmem_memory_pool[MMI_FRM_SCRMEM_POOL_SIZE/4];

#ifdef __MTK_TARGET__
#pragma arm section zidata
#endif 

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_get_screen_id
 * DESCRIPTION
 *  This function is callback from mcu/applib/, and it should be thread-safe.
 *  (However, it's not suggested to use screen-based ASM in non-MMI task)
 *
 *  Reference: GetExitScrnID()
 * PARAMETERS
 *  void
 * RETURNS
 *  Current screen ID
 *****************************************************************************/
static kal_uint32 mmi_frm_scrmem_get_screen_id(void)
{
    return (kal_uint32) GetExitScrnID_r();
}


/*****************************************************************************              
 * Extern Global Variable                                                                    
 *****************************************************************************/

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_init
 * DESCRIPTION
 *  Initialize screen-based memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_scrmem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_screen_init(
        mmi_frm_scrmem_get_screen_id, 
        MMI_FRM_SCRMEM_POOL_SIZE, 
        g_mmi_frm_scrmem_memory_pool);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_alloc
 * DESCRIPTION
 *  Allocate screen-based shared memory
 *  NOTE: it might returns NULL if we fail to allocate memory block of "mem_size".
 * PARAMETERS
 *  mem_size        [IN]        Memory size
 * RETURNS
 *  allocated chunk
 *****************************************************************************/
void *mmi_frm_scrmem_alloc(U32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_mem_screen_alloc((kal_uint32)mem_size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_free
 * DESCRIPTION
 *  Free screen-based shared memory
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to be free-ed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_scrmem_free(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_screen_free(mem_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_get_available_size
 * DESCRIPTION
 *  Get available size of screen-based memory
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left space
 *****************************************************************************/
U32 mmi_frm_scrmem_get_available_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U32)applib_mem_screen_get_total_left_size();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_is_all_free
 * DESCRIPTION
 *  Check if there is allocated screen-based memory
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if all memory are released
 *****************************************************************************/
MMI_BOOL mmi_frm_scrmem_is_all_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(applib_mem_screen_get_alloc_count() == 0 ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_is_valid_block
 * DESCRIPTION
 *  Check if a memory block is valid. In other words, it should belong to the
 *  current screen.
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to check
 * RETURNS
 *  Return MMI_TRUE if all memory are released
 *****************************************************************************/
MMI_BOOL mmi_frm_scrmem_is_valid_block(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(applib_mem_screen_is_valid_block(mem_ptr) ? MMI_TRUE : MMI_FALSE);
}


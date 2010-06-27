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
 *  Sample_Memory.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for memory management (Contrl Buffer, Scrmem, ASM, etc)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "DebugInitDef.h"       /* MMI_ASSERT */

#include "app_buff_alloc.h"     /* dependent fucntion for OslMemory */
#include "OslMemory.h"  /* Osl memory interface */
#include "ScrMemMgrGprot.h"     /* Screen memory manager */

/****************************************************************************
*
*  [Sample]
*
*  Get samll memory fragment (1-4096 byte) from control buffer 
*
*  NOTICE: Control buffer have size limit (4096 byte) and number limit!!!
*          Avoid to allocate too much control buffer!
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_memory_ctrl_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_memory_ctrl_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *filepath;
    S32 filepath_len = 520;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory */
    filepath = OslMalloc(filepath_len);

    if (filepath == NULL)
    {
        /* 
         * We cant 100% gaurantee to get buffer from OslMalloc.
         * Add assert to find the problem, or add some error handling 
         */

        MMI_ASSERT(0);
    }

    /* 
     * filepath manipluate
     * ...
     * ..
     */

    /* free memory */
    OslMfree(filepath);
}

/****************************************************************************
*
*  [Sample]
*
*  Get screen based memory. 
*
*  NOTICE: This memory can only be allocated within a screen's scope.
*          We usually allocate when enter screen and free when exit screen.
*
*  NOTICE: To use this memory, u need to add ur upper bound to ScrMemMgr.h.
*          You may able to expand the upper bound if you have plutommi sorce code.    
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_memory_screen_base
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_memory_screen_base(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *data;
    S32 data_len = 100 * 1024;  /* 100K */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory */
    data = (S8*) mmi_frm_scrmem_alloc(data_len);

    if (data == NULL)
    {
        /* 
         * We cant 100% gaurantee to get buffer from screen memory manager.
         * Add assert to find the problem, or add some error handling 
         */

        MMI_ASSERT(0);
    }

    /* 
     * data manipluate
     * ...
     * ..
     */

    /* free memory */
    mmi_frm_scrmem_free(data);
}


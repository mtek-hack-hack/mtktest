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
 * phb_control_block.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the control_block
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define PHB_CONTROL_BLOCK_C

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

/* Prerequisite of phb_se.h */
#include "phb_defs.h"

#include "phb_control_block.h"

#include "phb_data_desc.h"
#include "phb_data_entry_table.h"
#include "phb_pindex.h"
#include "phb_name_num_index.h"
#include "phb_se.h"
#include "phb_context.h"

extern phb_context_type *phb_ptr;


/*****************************************************************************
 * FUNCTION
 *  phb_control_block_construct
 * DESCRIPTION
 *  Initializer of control_block.
 *  
 *  Note:
 *  control_block_init() DOES NOT free local_param_ptr,  peer_buf_ptr and data.
 *  It just set the pointers NULL.
 *  Hence, to prevent memory leak, user of control_block must explicitly frees the memory
 *  before calling control_block_alloc().
 * PARAMETERS
 *  control_block       [IN]        The control_block
 *  ID                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_control_block_construct(control_block_type *control_block, kal_uint8 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    if (control_block->IO_stage == IO_WAIT || control_block->IO_stage == IO_REASSEMBLY)
    {
        /* kal_prompt_trace(MOD_PHB, "reset need to drop cnf\0"); */
        phb_ptr->drop_cnf = KAL_TRUE;
    }

    if ((control_block->need_free_peer) && (control_block->peer_buf_ptr != NULL))
    {
        free_peer_buff((peer_buff_struct*) control_block->peer_buf_ptr);
    }

    kal_mem_set(control_block, (unsigned char)0, sizeof(control_block_type));

    control_block->ID = ID;
}


/*****************************************************************************
 * FUNCTION
 *  phb_control_block_set_param
 * DESCRIPTION
 *  Set parameters of control_block.
 * PARAMETERS
 *  control_block       [IN]        The control_block
 *  proc_stage          [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_control_block_set_param(
        control_block_type *control_block,
        kal_uint8 proc_stage,
        void *local_param_ptr,
        void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    control_block->proc_stage = proc_stage;
    control_block->local_param_ptr = local_param_ptr;
    control_block->peer_buf_ptr = peer_buf_ptr;
}   /* end of control_block_alloc */


/*****************************************************************************
 * FUNCTION
 *  phb_control_block_set
 * DESCRIPTION
 *  Sets the control_block
 * PARAMETERS
 *  control_block       [IN]        The control_block to set
 *  return_location     [IN]        
 *  controller          [IN]        
 *  err_handler         [IN]        
 *  proc_stage          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_control_block_set(
        control_block_type *control_block,
        return_func_type return_location,
        controller_func_type controller,
        err_handler_func_type err_handler,
        kal_uint8 proc_stage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    control_block->return_location = return_location;
    control_block->controller = controller;
    control_block->err_handler = err_handler;

    control_block->proc_stage = proc_stage;
}   /* end of phb_control_block_set */


/*****************************************************************************
 * FUNCTION
 *  phb_control_block_set_IO
 * DESCRIPTION
 *  Sets the control_block when loop is needed to access several records stored in device.
 * PARAMETERS
 *  control_block       [IN]        The control_block to set
 *  type                [IN]        
 *  index               [IN]        
 *  total               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_control_block_set_IO(
        control_block_type *control_block,
        phb_type_enum type,
        kal_uint16 index,
        kal_uint16 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    control_block->type = type;
    control_block->index = index;
    control_block->actual_count = 0;
    control_block->total = total;
}   /* end of phb_control_block_set_IO */


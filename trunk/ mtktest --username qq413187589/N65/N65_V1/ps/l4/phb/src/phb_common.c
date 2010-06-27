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
 * phb_issue_IO.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is startup handler of PHB module.
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
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

#include "phb_defs.h"
#include "phb_control_block.h"

#include "phb_sim_access.h"
#include "phb_nvram_access.h"

#include "phb_common.h"

#include "phb_utils.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_COMMON_C_


/*****************************************************************************
 * FUNCTION
 *  phb_is_type_valid
 * DESCRIPTION
 *  Tests whether a given phb_type_enum type is valid.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  Return corresponding sim_file_id of data descriptor type
 *****************************************************************************/
kal_bool phb_is_type_valid(phb_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_IS_TYPE_VALID);

    switch (type)
    {
        case PHB_ECC:
        case PHB_PHONEBOOK:
        case PHB_FDN:
        case PHB_BDN:
        case PHB_MSISDN:
        case PHB_SDN:
        case PHB_GAS:
        case PHB_ANR:
        case PHB_SNE:
            return KAL_TRUE;

        default:
            return KAL_TRUE;
    }
}   /* end of phb_is_type_valid */


/*****************************************************************************
 * FUNCTION
 *  phb_IO_return
 * DESCRIPTION
 *  This function is called when leaving sim/nvram_???_cnf() functions.
 *  Log a `subop' exit event, then called return_location or err_handler of control_block,
 *  depending on `is_success'.
 *  
 *  Prerequisite:
 *  The responsibility of destructing control_block is return_location or err_handler.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr             [IN]        The primitives
 *  is_success          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void phb_IO_return(control_block_type *control_block, ilm_struct *ilm_ptr, kal_bool is_success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_IO_RETURN);

    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    if (is_success)
    {
        control_block->IO_stage = IO_NONE;
        control_block->IO_cnf_receive = NULL;

        /* Referenced control_block->return location shall not be NULL) */
        ASSERT(control_block->return_location != NULL);

        (*control_block->return_location) (ilm_ptr, control_block);
    }
    else
    {
        /* Referenced control_block->return location shall not be NULL) */
        ASSERT(control_block->err_handler != NULL);

        (*control_block->err_handler) (ilm_ptr, control_block);
    }
}   /* end of phb_error_occured */


/*****************************************************************************
 * FUNCTION
 *  phb_issue_IO_read
 * DESCRIPTION
 *  This is phb_issue_read function of PHB module.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_issue_IO_read(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_ISSUE_IO_READ);

    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    if (control_block->storage == PHB_SIM)
    {
        return phb_sim_read(control_block);
    }
    else
    {
        return phb_nvram_read(control_block);
    }
}   /* end of phb_issue_IO_read */


/*****************************************************************************
 * FUNCTION
 *  phb_issue_IO_write
 * DESCRIPTION
 *  This is phb_issue_write function of PHB module.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_issue_IO_write(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_ISSUE_IO_WRITE);

    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    if (control_block->storage == PHB_SIM)
    {
        return phb_sim_write(control_block);
    }
    else
    {
        return phb_nvram_write(control_block);
    }
}   /* end of phb_issue_IO_write */


/*****************************************************************************
 * FUNCTION
 *  phb_issue_IO_delete
 * DESCRIPTION
 *  This is phb_issue_write function of PHB module.
 * PARAMETERS
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  KAL_TRUE if success, KAL_FALSE otherwise.
 *****************************************************************************/
kal_bool phb_issue_IO_delete(control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_ISSUE_IO_DELETE);

    /* Referenced control_block shall not be NULL) */
    ASSERT(control_block != NULL);

    if (control_block->storage == PHB_SIM)
    {
        return phb_sim_delete(control_block);
    }
    else
    {
        return phb_nvram_delete(control_block);
    }
}   /* end of phb_issue_IO_write */


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
 * phb_ilm.c
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
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

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

#include "phb_ilm.h"

/* For alignment macro */
#include "phb_sap.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_ILM_C_


/*****************************************************************************
 * FUNCTION
 *  phb_send_ilm
 * DESCRIPTION
 *  This is phb_send_ilm function of PHB module.
 * PARAMETERS
 *  dest_id             [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_send_ilm(kal_uint8 dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SEND_ILM);

#ifdef __GEMINI__
    if (phb_current_mod == MOD_PHB)
    {
        ilm_ptr = allocate_ilm(MOD_PHB);
    }
    else
    {
        ilm_ptr = allocate_ilm(MOD_PHB_2);
    }
#else /* __GEMINI__ */
    ilm_ptr = allocate_ilm(MOD_PHB);
#endif /* __GEMINI__ */

    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

#ifdef __GEMINI__
    if (phb_current_mod == MOD_PHB)
    {
        if (dest_id == MOD_SIM)
        {
            SEND_ILM(MOD_PHB, MOD_SIM, PS_SIM_SAP, ilm_ptr);
        }
        else if (dest_id == MOD_NVRAM)
        {
            SEND_ILM(MOD_PHB, MOD_NVRAM, PS_NVRAM_SAP, ilm_ptr);
        }
        else if (dest_id == MOD_L4C)
        {
            SEND_ILM(MOD_PHB, MOD_L4C, PHB_L4C_SAP, ilm_ptr);
        }
    }
    else
    {
        if (dest_id == MOD_SIM)
        {
            SEND_ILM(MOD_PHB_2, MOD_SIM_2, PS_SIM_SAP, ilm_ptr);
        }
        else if (dest_id == MOD_NVRAM)
        {
            SEND_ILM(MOD_PHB_2, MOD_NVRAM, PS_NVRAM_SAP, ilm_ptr);
        }
        else if (dest_id == MOD_L4C)
        {
            SEND_ILM(MOD_PHB_2, MOD_L4C_2, PHB_L4C_SAP, ilm_ptr);
        }
    }
#else /* __GEMINI__ */
    if (dest_id == MOD_SIM)
    {
        SEND_ILM(MOD_PHB, MOD_SIM, PS_SIM_SAP, ilm_ptr);
    }
    else if (dest_id == MOD_NVRAM)
    {
        SEND_ILM(MOD_PHB, MOD_NVRAM, PS_NVRAM_SAP, ilm_ptr);
    }
    else if (dest_id == MOD_L4C)
    {
        SEND_ILM(MOD_PHB, MOD_L4C, PHB_L4C_SAP, ilm_ptr);
    }
#endif /* __GEMINI__ */
}   /* End of phb_send_ilm */


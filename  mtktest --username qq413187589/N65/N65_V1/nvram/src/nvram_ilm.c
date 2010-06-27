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
 * nvram_ilm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is startup handler of NVRAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

#include "nvram.h"

#include "nvram_ilm.h"

/* __SHADOW_NVRAM__ */
#include "nvram_defs.h"
#include "nvram_io.h"
#include "stacklib.h"
#include "stack_timer.h"
#include "event_shed.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _NVRAM_ILM_C_

#ifdef __SHADOW_SUPPORT_SB__
stack_timer_struct nvram_shadow_timer;
#endif 


/*****************************************************************************
 * FUNCTION
 *  nvram_send_ilm
 * DESCRIPTION
 *  This is nvram_send_ilm function of NVRAM module.
 * PARAMETERS
 *  dest_id             [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_send_ilm(module_type dest_id, msg_type msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest_id == MOD_RTC_HISR || dest_id == MOD_SIM)
    {
        if (local_param_ptr)
            free_ctrl_buffer(local_param_ptr);
        if (peer_buf_ptr)
            free_peer_buff(peer_buf_ptr);
            
        return;
    }
    ilm_ptr = allocate_ilm(MOD_NVRAM);

    ASSERT(ilm_ptr != NULL);

    ilm_ptr->src_mod_id = MOD_NVRAM;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    ilm_ptr->dest_mod_id = dest_id;
    ilm_ptr->sap_id = PS_NVRAM_SAP;

   /**
    * Sigh, since SEND_ILM is a macro uses ## directive, 
    * the formal parameter of dest_mod_id must be hardcoded.
    * So NVRAM DOES NOT use it. >=P
    */
    msg_send_ext_queue(ilm_ptr);
}   /* End of nvram_send_ilm */

#ifdef __SHADOW_SUPPORT_SB__


/*****************************************************************************
 * FUNCTION
 *  nvram_restart_timer
 * DESCRIPTION
 *  Restart schedule event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_restart_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer(&nvram_shadow_timer, 0, 10 * KAL_TICKS_1_SEC);    /* 10sec */

}


/*****************************************************************************
 * FUNCTION
 *  nvram_stop_timer
 * DESCRIPTION
 *  Stop schedule event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer(&nvram_shadow_timer);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_timer_init
 * DESCRIPTION
 *  Create timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_timer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_init_timer(&nvram_shadow_timer, "NVRAM Shadow Timer", MOD_NVRAM);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_timer_expiry_hdlr
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_timer_expiry_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;
    kal_uint16 msg_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) get_local_para_ptr(local_para_ptr, &msg_len);
    if (stack_timer_ptr == &nvram_shadow_timer)
    {
        if (stack_is_time_out_valid(&nvram_shadow_timer))
        {
            nvram_flush_shadow();
        }
        stack_process_time_out(&nvram_shadow_timer);
    }

}

#endif /* __SHADOW_SUPPORT_SB__ */ 


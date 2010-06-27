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
 * gdd_daemon.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is entry point of GDI Daemon
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

#include "stack_config.h"
#include "task_main_func.h"
#include "stack_timer.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stack_init.h"
#include "stacklib.h"
#include "event_shed.h"
/* for tst inject message */
#include "tst_sap.h"


#include "gdi_internal.h"
#include "gdd_include.h"

gdd_context_struct gdd_context;

extern kal_taskid kal_get_current_thread_ID(void);

/*****************************************************************************
 * FUNCTION
 *  gdd_start_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]         
 *  time_out            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdd_start_base_timer(void *base_timer_ptr, kal_uint32 time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_ptr, 0, time_out);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  gdd_stop_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdd_stop_base_timer(void *base_timer_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer((stack_timer_struct*) base_timer_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  gdd_timer_expiry_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdd_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) timer_id < (kal_uint32) GDD_TIMER_MAX_NUM)
    {
        gdd_context.timer_table[(kal_uint32) (timer_id)].event_id = NULL;
        (gdd_context.timer_table[(kal_uint32) (timer_id)].callback_func) (gdd_context.timer_table[(kal_uint32) (timer_id)].arg);
    }
}
void gdd_timer_expiry_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) ilm_ptr->local_para_ptr;

    /* Check if the base timer is stopped or not */
    if (stack_is_time_out_valid(&gdd_context.base_timer))
    {
        /* Execute event's timeout handler */
        evshed_timer_handler(gdd_context.event_scheduler_ptr);
    }
    /* Should be paired with stack_is_time_out_valid() */
    stack_process_time_out(&gdd_context.base_timer);
}

/*****************************************************************************
 * FUNCTION
 *  gdd_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id            [IN]        
 *  period              [IN]        
 *  timer_expiry        [IN]        
 *  arg                 [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdd_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = (period * 7) >> 5;    /* ~= x 1/4.615 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == 0)
    {
        temp = 1;
    }
    gdd_context.timer_table[timer_id].callback_func = timer_expiry;
    gdd_context.timer_table[timer_id].arg = arg;
    gdd_context.timer_table[timer_id].event_id = evshed_set_event(
                                            gdd_context.event_scheduler_ptr,
                                            (kal_timer_func_ptr) gdd_timer_expiry_callback,
                                            (void*)timer_id,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  gdd_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdd_stop_timer(kal_uint8 timer_id)
{
    if (gdd_context.timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(gdd_context.event_scheduler_ptr, &(gdd_context.timer_table[timer_id].event_id));
        gdd_context.timer_table[timer_id].event_id = NULL;
    }

}



/*****************************************************************************
 * FUNCTION
 *  gdd_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool gdd_init(task_indx_type task_indx)
{
    memset(&gdd_context,0,sizeof(gdd_context));
    stack_init_timer(&gdd_context.base_timer, "GDD Base Timer", MOD_GDD);

    gdd_context.event_scheduler_ptr = new_evshed(
                                            &gdd_context.base_timer,
                                            gdd_start_base_timer,
                                            gdd_stop_base_timer,
                                            0,
                                            kal_evshed_get_mem,
                                            kal_evshed_free_mem,
                                            0);

    gdd_context.event = kal_create_event_group("gdd_event");
    return KAL_TRUE;
}   /* end of gdd_reset */

/*****************************************************************************
 * FUNCTION
 *  gdd_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool gdd_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}   /* end of gdd_reset */
/*****************************************************************************
 * FUNCTION
 *  gdd_task_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdd_msg_handler(ilm_struct *ilm)
{
    kal_uint32 i;
    if (ilm->msg_id == MSG_ID_TIMER_EXPIRY)
    {
        gdd_timer_expiry_hdlr(ilm);
    }
    else if (ilm->msg_id == MSG_ID_TST_INJECT_STRING)
    {
        tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm->local_para_ptr;
        gdi_debug_handler((S32)tst_inject->index,(U8*)tst_inject->string);
    }
    else /* try message handlers */
    {
        for(i=0;i<gdd_context.msg_count;i++)
			if(gdd_context.msg_handler[i])
            if(gdd_context.msg_handler_id[i] == ilm->msg_id)
            {
                gdd_context.msg_handler[i](ilm);
            }
    }
}

/*****************************************************************************
 * FUNCTION
 *  gdd_task_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdd_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;
	kal_uint32 my_index;
    
	kal_get_my_task_index(&my_index);
    stack_set_active_module_id( my_index, MOD_GDD);

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        gdd_msg_handler(&current_ilm);
        free_ilm(&current_ilm);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gdd_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool gdd_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static comptask_handler_struct gdd_handler_info = 
    {
        gdd_task_main, /* task entry function */
        gdd_init,      /* task initialization function */
        NULL,           /* task configuration function */
        gdd_reset,     /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & gdd_handler_info;
    return KAL_TRUE;
}

void gdd_send_img_codec_ind(void* data,U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdd_img_codec_event_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (gdd_img_codec_event_ind_struct*)
        construct_local_para((U16)(sizeof(gdd_img_codec_event_ind_struct)+size), TD_CTRL);

    memcpy(&(ind_p->header),data,size);

    ilm_ptr = allocate_ilm(MOD_GDD);
    ilm_ptr->src_mod_id = MOD_GDD;
    ilm_ptr->dest_mod_id = MOD_GDD;
    ilm_ptr->sap_id = GDD_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

}
kal_bool gdd_register_msg_handler(msg_type msg,gdd_msg_handler_func func)
{
    kal_uint32 i;
    for(i=0;i<gdd_context.msg_count;i++)
        if(gdd_context.msg_handler_id[i] == msg)
            break;
        
    GDI_DEBUG_ASSERT(i<GDD_MAX_MSG_HANDLER);
    if(func) // insert
    {
        gdd_context.msg_handler_id[i] = msg;
        gdd_context.msg_handler[i] = func;
        if(i==gdd_context.msg_count)
            gdd_context.msg_count++;
    }
    else // delete
    {
        gdd_context.msg_count--;
        gdd_context.msg_handler_id[i] = gdd_context.msg_handler_id[gdd_context.msg_count];
        gdd_context.msg_handler[i] = gdd_context.msg_handler[gdd_context.msg_count];
    }
    return KAL_TRUE;
}



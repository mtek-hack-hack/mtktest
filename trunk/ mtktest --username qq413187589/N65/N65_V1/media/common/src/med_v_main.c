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
 *   med_v_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media v task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_V_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */

/* local include */
#include "aud_build_cache.h"
#include "med_global.h"
#include "med_v_struct.h"
#include "med_v_context.h"
#include "med_v_main.h"
#ifdef __MED_MTV_MOD__
#include "mtv_main.h"
#include "mtv_comm.h"
#endif

/* global variables */
med_v_context_struct med_v_context;
med_v_context_struct *med_v_context_p = &med_v_context;
med_v_timer_table_struct med_v_timer_table[MAX_NUM_OF_MED_V_TIMER];

/*==== FUNCTIONS ===========*/
extern void aud_in_proc_call_req_hdlr(ilm_struct *ilm_ptr);



/*****************************************************************************
 * FUNCTION
 *  med_v_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void med_v_timer_expiry_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) ilm_ptr->local_para_ptr;

    if (stack_timer_ptr->timer_indx == MED_V_BASE_TIMER_ID)
    {
        /* Check if the base timer is stopped or not */
        if (stack_is_time_out_valid(&med_v_context_p->base_timer))
        {
            /* Execute event's timeout handler */
            evshed_timer_handler(med_v_context_p->event_scheduler_ptr);
        }
        
        /* Should be paired with stack_is_time_out_valid() */
        stack_process_time_out(&med_v_context_p->base_timer);
    }
#if defined(__MED_MTV_MOD__)
    mtv_process_time_out(stack_timer_ptr);
#endif /* __MED_MTV_MOD__ */
}



/*****************************************************************************
 * FUNCTION
 *  med_v_start_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [IN]         
 *  time_out            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void med_v_start_base_timer(void *base_timer_ptr, kal_uint32 time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_ptr, MED_V_BASE_TIMER_ID, time_out);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  med_v_stop_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void med_v_stop_base_timer(void *base_timer_ptr)
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
 *  med_v_timer_expiry_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void med_v_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32)timer_id < (kal_uint32)MAX_NUM_OF_MED_V_TIMER)
    {
        med_v_timer_table[(kal_uint32)(timer_id)].event_id = NULL;
        (med_v_timer_table[(kal_uint32)(timer_id)].callback_func)(med_v_timer_table[(kal_uint32)(timer_id)].arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_v_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id            [IN]        
 *  period              [IN]        
 *  timer_expiry        [IN]        
 *  arg                 [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
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
    
    med_v_timer_table[timer_id].callback_func = timer_expiry;
    med_v_timer_table[timer_id].arg = arg;
    med_v_timer_table[timer_id].event_id 
        = evshed_set_event(
            med_v_context_p->event_scheduler_ptr,
            (kal_timer_func_ptr)med_v_timer_expiry_callback,
            (void*)timer_id,
            temp);
}


/*****************************************************************************
 * FUNCTION
 *  med_v_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_stop_timer(kal_uint8 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (med_v_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(med_v_context_p->event_scheduler_ptr, &(med_v_timer_table[timer_id].event_id));
        med_v_timer_table[timer_id].event_id = NULL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  med_v_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of media v task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}


/*****************************************************************************
 * FUNCTION
 *  med_v_main
 * DESCRIPTION
 *  This function is main message dispatching function of media v task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
         case MSG_ID_TIMER_EXPIRY:
            med_v_timer_expiry_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_IN_PROC_CALL_REQ:
            aud_in_proc_call_req_hdlr(ilm_ptr);
            break;
    #if defined(__MED_VID_MOD__)
        case MSG_ID_MEDIA_VISUAL_STOP_REQ:
            vis_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_PLAY_REQ:
            vis_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_SEEK_REQ:
            vis_seek_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_DECODE_VISUAL_DATA_IND:
            vis_decode_visual_data_ind_hdlr(ilm_ptr);
            break;
    #endif /* defined(__MED_VID_MOD__) */ 

    #if defined(__MED_VID_ENC_MOD__)
        case MSG_ID_MEDIA_VISUAL_RECORD_REQ:
            vis_record_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VISUAL_FILE_MERGE_REQ:
            vis_file_merge_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_ENCODE_VISUAL_DATA_IND:
            vis_encode_visual_data_ind_hdlr(ilm_ptr);
            break;
    #endif /* defined(__MED_VID_ENC_MOD__) */
    
    #if defined(__MED_MJPG_MOD__)
        case MSG_ID_MEDIA_VISUAL_PLAY_REQ:
            vis_play_req_hdlr(ilm_ptr);
            break;    
        case MSG_ID_MEDIA_VISUAL_STOP_REQ:
            vis_stop_req_hdlr(ilm_ptr);
            break;
    #endif /* defined(__MED_MJPG_MOD__) */ 

    #if defined(__MED_MJPG_ENC_MOD__)
        case MSG_ID_MEDIA_VISUAL_RECORD_REQ:
            vis_record_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_ENCODE_VISUAL_DATA_IND:
            vis_encode_visual_data_ind_hdlr(ilm_ptr);
            break;
    #endif /* defined(__MED_MJPG_ENC_MOD__) */
    
    #ifdef __RICH_AUDIO_PROFILE__
        case MSG_ID_MEDIA_AUDIO_START_BUILD_CACHE_REQ:
            audio_start_build_cache(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_STOP_BUILD_CACHE_REQ:
            audio_stop_build_cache(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_CLOSE_BUILD_CACHE_REQ:
            audio_close_build_cache(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_PROCESS_BUILD_CACHE_REQ:
            audio_process_build_cache(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUDIO_RESET_BUILD_CACHE_VARS_REQ:
            audio_reset_build_cache_variables(ilm_ptr);
            break;
    #endif /*__RICH_AUDIO_PROFILE__*/
    
        case MSG_ID_MEDIA_V_AUDIO_START_RECORD_REQ:
            med_v_aud_start_record_req_hdlr(ilm_ptr);
            break;    
        case MSG_ID_MEDIA_V_AUDIO_STOP_RECORD_REQ:
            med_v_aud_stop_record_req_hdlr(ilm_ptr);
            break;    
        case MSG_ID_MEDIA_V_AUDIO_PAUSE_RECORD_REQ:
            med_v_aud_pause_record_req_hdlr(ilm_ptr);
            break;    
        case MSG_ID_MEDIA_V_AUDIO_RESUME_RECORD_REQ:
            med_v_aud_resume_record_req_hdlr(ilm_ptr);
            break;    
        case MSG_ID_MEDIA_V_AUDIO_READ_DATA_IND:
            med_v_aud_read_data_ind_hdlr(ilm_ptr);
            break;

        default:
        #ifdef __MED_MTV_MOD__
            if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_MTV_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_MTV_CODE_END) ||
                (ilm_ptr->msg_id >= MSG_ID_TDMB_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_TDMB_CODE_END))
            {
                mtv_main(ilm_ptr);
            }
        #endif /* __MED_MTV_MOD__ */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_v_task_main
 * DESCRIPTION
 *  This function is main function of media v task.
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        med_v_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }

}


/*****************************************************************************
 * FUNCTION
 *  med_v_init
 * DESCRIPTION
 *  This function is used to init media v task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_v_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VIS_ENTER_STATE(VISUAL_IDLE);
    med_v_context_p->aud_cache_event = kal_create_event_group("aud_cache_events");

    /* init stack timer */
    stack_init_timer(&med_v_context_p->base_timer, "MED_V Base Timer", MOD_MED_V);

    med_v_context_p->event_scheduler_ptr 
        = new_evshed(
            &med_v_context_p->base_timer,
            med_v_start_base_timer,
            med_v_stop_base_timer,
            0,
            kal_evshed_get_mem,
            kal_evshed_free_mem,
            0);

    for (i = 0; i < MAX_NUM_OF_MED_V_TIMER; i++)
    {
        med_v_timer_table[i].event_id = NULL;
    }

    /* Init record in low priority task */
    med_v_aud_record_init();

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  med_v_reset
 * DESCRIPTION
 *  This function is used to reset media v task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_v_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  med_v_create
 * DESCRIPTION
 *  This function is used to create media v task configuration info.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_v_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct med_v_handler_info = 
    {
        med_v_task_main,    /* task entry function */
        med_v_init,         /* task initialization function */
        NULL,               /* task configuration function */
        med_v_reset,        /* task reset handler */
        NULL,               /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & med_v_handler_info;

    return KAL_TRUE;
}

#endif /* MED_V_NOT_PRESENT */ 


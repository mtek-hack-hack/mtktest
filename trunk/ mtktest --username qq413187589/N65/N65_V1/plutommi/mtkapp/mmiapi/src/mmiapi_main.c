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
 * mmiapi_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to dispatch the message
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== *******************************************************************************/
#include "MMI_include.h"

/*  Include: MMI header file */


#define MMIAPI_USING_SMS
#define MMIAPI_USING_UI

#include "mmiapi_struct.h"
#include "mmiapi.h"
#include "mmiapi_func.h"

#define MMIAPI_MAX_CLIENTS    4


/* global data */
static kal_mutexid mmiapi_mutex_control = NULL;

static kal_eventgrpid mmiapi_mutex_table[MMIAPI_MAX_CLIENTS];
static module_type mmiapi_mutex_index[MMIAPI_MAX_CLIENTS];

#ifdef __MTK_TARGET__
static kal_taskid mmiapi_MMI_task_id;
#else 
static kal_uint32 mmiapi_MMI_task_index;
#endif 

mmiapi_blocking_data_struct mmiapi_blocking_data[MMIAPI_MAX_CLIENTS];

#define BEGIN_PROTECT_MUTEX_TABLE         \
   if(mmiapi_mutex_control==NULL)         \
      mmiapi_init_blocking();             \
   kal_take_mutex(mmiapi_mutex_control);  \

#define END_PROTECT_MUTEX_TABLE           \
   kal_give_mutex(mmiapi_mutex_control);  \


/*****************************************************************************
 * FUNCTION
 *  mmiapi_init_engine
 * DESCRIPTION
 *  initialize the mmiapi engine, and register all mmiapi message handler
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_init_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    mmiapi_MMI_task_id = kal_get_task_self_id();
#else 
    kal_get_my_task_index(&mmiapi_MMI_task_index);
#endif 

    /* SMS service */
    SetProtocolEventHandler((PsFuncPtr) mmiapi_sms_send_req, (U16) MSG_ID_MMIAPI_SMS_SEND_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmiapi_sms_register_port_req, (U16) MSG_ID_MMIAPI_SMS_REGISTER_PORT_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmiapi_sms_check_incoming_msg_req,
        (U16) MSG_ID_MMIAPI_SMS_CHECK_INCOMING_MSG_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmiapi_sms_get_incoming_msg_timestamp_req,
        (U16) MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_TIMESTAMP_REQ);
    SetProtocolEventHandler(
        (PsFuncPtr) mmiapi_sms_get_incoming_msg_address_req,
        (U16) MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_ADDRESS_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmiapi_sms_get_incoming_msg_req, (U16) MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_REQ);
    SetProtocolEventHandler((PsFuncPtr) mmiapi_ui_enter_idle_screen_req, (U16) MSG_ID_MMIAPI_UI_ENTER_IDLE_SCREEN_REQ);

    /* Remote procedure call */
    SetProtocolEventHandler((PsFuncPtr) mmiapi_remote_proc_call_req, (U16) MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ);

#if defined(WAP_SUPPORT)
    SetProtocolEventHandler((PsFuncPtr) mmiapi_message_action_register_ind, MSG_ID_MMIAPI_ACTION_REGISTER_IND);
    SetProtocolEventHandler((PsFuncPtr) mmiapi_unread_push_icon_ind, MSG_ID_MMIAPI_UNREAD_PUSH_ICON_IND);
    SetProtocolEventHandler((PsFuncPtr) mmiapi_mms_icon_ind, MSG_ID_MMIAPI_MMS_IND);
#endif /* defined(WAP_SUPPORT) */ 

#ifdef __J2ME__
    /* UI service */
    SetProtocolEventHandler(
        (PsFuncPtr) mmiapi_ui_enter_fullscreen_editor_req,
        (U16) MSG_ID_MMIAPI_UI_ENTER_FULLSCREEN_EDITOR_REQ);
#endif /* __J2ME__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_init_blocking
 * DESCRIPTION
 *  initialize the blocking mutex variable
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_init_blocking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmiapi_mutex_table, 0, sizeof(mmiapi_mutex_table));
    mmiapi_mutex_control = kal_create_mutex("mmiapi");
    memset(mmiapi_mutex_index, 0, sizeof(mmiapi_mutex_index));
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_mod_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int mmiapi_mod_index(module_type mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMIAPI_MAX_CLIENTS; i++)
        if (mmiapi_mutex_index[i] == mod)
        {
            return i;
        }

    /* remember it */
    for (i = 0; i < MMIAPI_MAX_CLIENTS; i++)
        if (mmiapi_mutex_index[i] == 0)
        {
            mmiapi_mutex_index[i] = mod;
            return i;
        }

    ASSERT(0);  /* you should enlarge MMIAPI_MAX_CLIENTS !! */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_register_blocking
 * DESCRIPTION
 *  each module want use blocking mmiapi, it should register blocking feature first.
 * CALLS
 *  
 * PARAMETERS
 *  mod             [IN]        
 *  mutex_name      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_register_blocking(module_type mod, kal_char *mutex_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    BEGIN_PROTECT_MUTEX_TABLE index = mmiapi_mod_index(mod);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mmiapi_mutex_table[index] == NULL);

    mmiapi_mutex_table[index] = kal_create_event_group(mutex_name);

END_PROTECT_MUTEX_TABLE}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_unregister_blocking
 * DESCRIPTION
 *  each module didn't want use mmiapi blocking anymore, it should call this function to free mutex .
 * CALLS
 *  
 * PARAMETERS
 *  mod     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_unregister_blocking(module_type mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    BEGIN_PROTECT_MUTEX_TABLE index = mmiapi_mod_index(mod);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_mutex_table[index])
    {
        kal_delete_eventgrp(mmiapi_mutex_table[index]);
    }

    mmiapi_mutex_table[index] = NULL;
END_PROTECT_MUTEX_TABLE}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_lock
 * DESCRIPTION
 *  blocking and waiting the mmiapi engine process.
 * CALLS
 *  
 * PARAMETERS
 *  mod     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_lock(module_type mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmiapi_mod_index(mod);

    ASSERT(mmiapi_mutex_table[index] != NULL);
    kal_retrieve_eg_events(mmiapi_mutex_table[index], 1, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_unlock
 * DESCRIPTION
 *  when mmiapi engine process finish, it should call this function to release the waiting module.
 * CALLS
 *  
 * PARAMETERS
 *  mod     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_unlock(module_type mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    BEGIN_PROTECT_MUTEX_TABLE index = mmiapi_mod_index(mod);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mmiapi_mutex_table[index] != NULL);
    if (mmiapi_blocking_data[index].is_blocking)
    {
        kal_set_eg_events(mmiapi_mutex_table[index], 1, KAL_OR);
        mmiapi_blocking_data[index].is_blocking = KAL_FALSE;
    }
END_PROTECT_MUTEX_TABLE}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_get_blocking_data
 * DESCRIPTION
 *  when mmiapi engine process finish, it should call this function to release the waiting module.
 * CALLS
 *  
 * PARAMETERS
 *  mod     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmiapi_blocking_data_struct *mmiapi_get_blocking_data(module_type mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmiapi_mod_index(mod);
    mmiapi_blocking_data[index].is_blocking = KAL_TRUE;
    mmiapi_blocking_data[index].is_gui = KAL_FALSE;
    return &(mmiapi_blocking_data[index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_enter_idle_screen_notify
 * DESCRIPTION
 *  when mmi enter idle screen, it should unblocking all module which had screen in history before.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_enter_idle_screen_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(mmiapi_blocking_data) / sizeof(mmiapi_blocking_data[0]); i++)
        if (mmiapi_mutex_table[i])
            if (mmiapi_blocking_data[i].is_blocking)
                /* if(mmiapi_blocking_data[i].is_gui) */
            {
                mmiapi_unlock(mmiapi_mutex_index[i]);
            }
}



/*****************************************************************************
 * FUNCTION
 *  mmiapi_is_MMI_task
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmiapi_is_MMI_task(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_get_task_self_id() == mmiapi_MMI_task_id);
#else /* __MTK_TARGET__ */ 
    kal_uint32 index;

    kal_get_my_task_index(&index);
    return (index == mmiapi_MMI_task_index);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_remote_proc_call_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_remote_proc_call_req(mmiapi_remote_proc_call_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RPC_REQ_MESSAGE, (unsigned int)msg->func_ptr);

    if (msg->validate_callback && !msg->validate_callback(msg->optional_param))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RPC_REQ_MESSAGE_CANCELED);
        return;
    }

    BLOCKING_INIT(mod_src, msg);

    switch (msg->type)
    {
        case MMIAPI_RPC_VOID:
        {
            void (*func) (void);

            func = (void (*)(void))msg->func_ptr;
            func();
            break;
        }

        case MMIAPI_RPC_INTEGER:
        {
            void (*func) (int);

            func = (void (*)(int))msg->func_ptr;
            func(msg->_u.i);
            break;
        }

        case MMIAPI_RPC_POINTER:
        {
            void (*func) (void*);

            func = (void (*)(void*))msg->func_ptr;
            func(msg->_u.p);
            break;
        }

        default:
            ASSERT(0);
    }

    if (msg->finish_callback)
    {
        msg->finish_callback();
    }

    BLOCKING_FINISH(mod_src);
    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RPC_REQ_MESSAGE_END, (unsigned int)msg->func_ptr);
}


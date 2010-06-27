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
 *    SyncMLHandler.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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

#include "MMI_include.h"

#include "ProtocolEvents.h"
#include "App_mine.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "ToDoListDef.h"
#include "ToDoListEnum.h"
#include "CommonScreens.h"
#include "AlarmFrameWorkProt.h"
#include "CallManagementGprot.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "syncml_common_customize.h"


/*
 * External Function
 */
extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);


/*
 * Local Variable
 */
static syncml_sync_request_struct g_syncml_sync_context;
static U16 temp_luid[MAX_SYNC_ITEMS];


/*
 * Global Variable
 */
extern syncml_context_struct g_syncml_context;
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
extern syncml_sas_struct g_sas_context;
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_free_vobj_buffer
 * DESCRIPTION
 *  Free the vObject buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_free_vobj_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_sync_context.vobj_ptr != NULL)
    {
        OslMfree(g_syncml_sync_context.vobj_ptr);
        g_syncml_sync_context.vobj_ptr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_message_handlers
 * DESCRIPTION
 *  Protocol event handlers of SyncML messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_message_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_syncml_set_record_req_ind, MSG_ID_MMI_SYNCML_SET_RECORD_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_get_record_req_ind, MSG_ID_MMI_SYNCML_GET_RECORD_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_query_luid_list_req_ind, MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_clean_luid_list_req_ind, MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_finish_sync_ind, MSG_ID_MMI_SYNCML_FINISH_SYNC_IND);
    SetProtocolEventHandler(mmi_syncml_progress_info_ind, MSG_ID_MMI_SYNCML_PROGRESS_INFO_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_record_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_record_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_set_record_req_ind_struct *local_data = (mmi_syncml_set_record_req_ind_struct*) info;

    FS_HANDLE fs_handle;
    U32 written_length;

    U16 temp_count, i, tdl_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
    {
        return;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML] Set record, LUID = %d, op = %d, db = %d...", local_data->luid, local_data->operation_type, local_data->database_type);

    g_syncml_sync_context.luid = (local_data->operation_type != SYNCML_RECORD_ADD) ? local_data->luid : 0xFFFF;
    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;
    g_syncml_sync_context.more_data = local_data->more_data;

    if (local_data->operation_type != SYNCML_RECORD_DELETE)
    {
        fs_handle = FS_Open(SYNCML_VOBJ_PATH, FS_CREATE | FS_READ_WRITE);
        FS_Seek(fs_handle, 0, FS_FILE_END);
        FS_Write(fs_handle, (void*) local_data->data, local_data->data_length, &written_length);
        FS_Close(fs_handle);
    }

    if (g_syncml_sync_context.more_data)
    {
        g_syncml_sync_context.result = SYNCML_OK;
        mmi_syncml_set_record_res_req();
        return;
    }

    if (local_data->database_type == SYNCML_DB_PHONEBOOK) /* phb */
    {
        if (local_data->operation_type == SYNCML_RECORD_MODIFY)
        {
            /* REPLACE: modify the record or add new record if LUID is not present */
            temp_count = mmi_phb_get_phone_index_arrary(temp_luid);
            for (i = 0; i < temp_count; i++)
            {
                if (temp_luid[i] == g_syncml_sync_context.luid)
                {
                    break;
                }
            }
            if (i == temp_count)
            {
                g_syncml_sync_context.operation = SYNCML_RECORD_ADD;
                g_syncml_sync_context.luid = 0xFFFF;
            }
        }

        mmi_phb_sync_vcard(g_syncml_sync_context.operation, (S8*) SYNCML_VOBJ_PATH, g_syncml_sync_context.luid, 
                local_data->charset);
    }
    else if (local_data->database_type == SYNCML_DB_TODOLIST) /* tdl */
    {
        if (local_data->operation_type == SYNCML_RECORD_MODIFY)
        {
            /* REPLACE: modify the record or add new record if LUID is not present */
            temp_count = mmi_tdl_get_total_index(temp_luid);
            for (i = 0; i < temp_count; i++)
            {
                if (temp_luid[i] == g_syncml_sync_context.luid)
                {
                    break;
                }
            }
            if (i == temp_count)
            {
                g_syncml_sync_context.operation = SYNCML_RECORD_ADD;
                g_syncml_sync_context.luid = 0xFFFF;
            }
        }

        tdl_result = mmi_tdl_sync_task(g_syncml_sync_context.operation, (S8*) SYNCML_VOBJ_PATH, &g_syncml_sync_context.luid, 
                local_data->charset);
        switch (tdl_result)
        {
            case MMI_TDL_SYNCML_ERR_NO_ERROR:
               g_syncml_sync_context.result = SYNCML_OK;
               break;

            case MMI_TDL_SYNCML_ERR_MEMORY_FULL:
               g_syncml_sync_context.result = SYNCML_DEVICE_FULL;
               break;

            default:
               g_syncml_sync_context.result = SYNCML_FAIL;
               break;
        }
        mmi_syncml_set_record_res_req();
    }
    else
    {

    }

    /* mmi_syncml_set_record_res_req(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_record_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_record_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_syncml_set_record_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_SET_RECORD_RES_REQ;

    dataPtr =
        (mmi_syncml_set_record_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_set_record_res_req_struct));

    dataPtr->result = g_syncml_sync_context.result;
    dataPtr->luid = g_syncml_sync_context.luid;

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    /* sync report */
    if (g_syncml_sync_context.result == SYNCML_OK)
    {
	if (g_syncml_sync_context.more_data == 0)
	{
            if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
            {
                g_syncml_context.contact_ok_cnt[g_syncml_sync_context.operation - SYNCML_RECORD_ADD]++;
            }
            else if (g_syncml_sync_context.database == SYNCML_DB_TODOLIST)
            {
                g_syncml_context.calendar_ok_cnt[g_syncml_sync_context.operation - SYNCML_RECORD_ADD]++;
            }
            else
            {
                /* other database*/
            }
        }
    }
    else
    {
        if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
        {
            g_syncml_context.contact_ng_cnt++;
        }
        else if (g_syncml_sync_context.database == SYNCML_DB_TODOLIST)
        {
            g_syncml_context.calendar_ng_cnt++;
        }
        else
        {
            /* other database*/
        }
    }

    if (g_syncml_sync_context.more_data == 0)
    {
        FS_Delete(SYNCML_VOBJ_PATH);
    }
    
    /* update to show the current progress */
    if (g_syncml_sync_context.more_data == 0)
    {
        if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
        {
            g_syncml_context.contact_recv_current++;
            mmi_syncml_update_progress_string(PROGRESS_CONTACT_DATASTORE_RECEIVED);
        }
        else if (g_syncml_sync_context.database == SYNCML_DB_TODOLIST)
        {
            g_syncml_context.calendar_recv_current++;
            mmi_syncml_update_progress_string(PROGRESS_TASK_DATASTORE_RECEIVED);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_record_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_get_record_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_get_record_req_ind_struct *local_data = (mmi_syncml_get_record_req_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
    {
        return;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML] Get record, LUID = %d, db = %d...", local_data->luid, local_data->database_type);


    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;
    g_syncml_sync_context.luid = local_data->luid;

    /* if get deletion , only to reponse directly without geting data actually. */
    if (g_syncml_sync_context.operation == SYNCML_RECORD_GET_DEL_NOTIFY)
    {
        g_syncml_sync_context.result = SYNCML_OK;
        mmi_syncml_get_record_res_req();
        return;
    }

    if (local_data->database_type == SYNCML_DB_PHONEBOOK) /* phb */
    {
        mmi_phb_sync_vcard(MMI_PHB_VCARD_READ, (S8*) SYNCML_VOBJ_PATH, g_syncml_sync_context.luid, 0);
    }
    else if (local_data->database_type == SYNCML_DB_TODOLIST) /* tdl */
    {
        g_syncml_sync_context.result = (mmi_tdl_sync_task(MMI_TDL_SYNCML_GET, (S8*) SYNCML_VOBJ_PATH, &g_syncml_sync_context.luid, 0) == MMI_TDL_SYNCML_ERR_NO_ERROR) ? SYNCML_OK : SYNCML_FAIL;
        mmi_syncml_get_record_res_req();
    }
    else
    {

    }

    /* mmi_syncml_get_record_res_req(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_record_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_get_record_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_syncml_get_record_res_req_struct *dataPtr;

    FS_HANDLE fs_handle;
    U32 read_length, fs_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_syncml_sync_context.operation != SYNCML_RECORD_GET_DEL_NOTIFY)
    {
        if (g_syncml_sync_context.result == SYNCML_OK)
        {
            fs_handle = FS_Open(SYNCML_VOBJ_PATH, FS_READ_ONLY);
            FS_GetFileSize(fs_handle, &fs_size);
            mmi_syncml_free_vobj_buffer();
            g_syncml_sync_context.vobj_ptr = OslMalloc(fs_size);
            FS_Read(fs_handle, (void*) g_syncml_sync_context.vobj_ptr, fs_size, &read_length);
            FS_Close(fs_handle);
            FS_Delete(SYNCML_VOBJ_PATH);
         }
         else
        {
            mmi_syncml_free_vobj_buffer();
            fs_size = 0;
            g_syncml_sync_context.result = SYNCML_FAIL;
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML] Get record fail");
        }
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_GET_RECORD_RES_REQ;

    dataPtr =
        (mmi_syncml_get_record_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_get_record_res_req_struct));

    dataPtr->result = g_syncml_sync_context.result;
    if (g_syncml_sync_context.operation != SYNCML_RECORD_GET_DEL_NOTIFY)
    {
        dataPtr->data_length = fs_size;
        dataPtr->data = g_syncml_sync_context.vobj_ptr;
        dataPtr->more_data = 0;
    }

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    /* update to show the current progress */
 
    if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
    {
        g_syncml_context.contact_send_current++;
        mmi_syncml_update_progress_string(PROGRESS_CONTACT_DATASTORE_SENDING);
    }
    else if (g_syncml_sync_context.database == SYNCML_DB_TODOLIST)
    {
        g_syncml_context.calendar_send_current++;
        mmi_syncml_update_progress_string(PROGRESS_TASK_DATASTORE_SENDING);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_query_luid_list_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_query_luid_list_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_query_luid_list_req_ind_struct *local_data = (mmi_syncml_query_luid_list_req_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
    {
        return;
    }

    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;
    g_syncml_sync_context.luid_buf = local_data->luid_buf;

    mmi_syncml_query_luid_list_res_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_query_luid_list_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_query_luid_list_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_syncml_query_luid_list_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_RES_REQ;

    dataPtr =
        (mmi_syncml_query_luid_list_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_query_luid_list_res_req_struct));

    dataPtr->luid = g_syncml_sync_context.luid_buf;

    if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK) /* phb */
    {
        if ( g_syncml_sync_context.operation == SYNCML_RECORD_ALL ||
            (g_syncml_sync_context.operation == SYNCML_RECORD_ADD && g_syncml_context.last_phb_anchor[g_syncml_context.active_profile - 1] == 0) )
        {
            /* sync all records */
            dataPtr->count = mmi_phb_get_phone_index_arrary(dataPtr->luid); /* How to fix 1000 phb entries? */
        }
        else if(g_syncml_context.last_phb_anchor[g_syncml_context.active_profile - 1] == 0)
        {
            dataPtr->count = 0;
        }
        else
        {
            dataPtr->count = mmi_syncml_query_change_log(g_syncml_sync_context.operation, g_syncml_sync_context.database, dataPtr->luid);
        }
    }

    if (g_syncml_sync_context.database == SYNCML_DB_TODOLIST) /* tdl */
    {
        if ( g_syncml_sync_context.operation == SYNCML_RECORD_ALL ||
            (g_syncml_sync_context.operation == SYNCML_RECORD_ADD && g_syncml_context.last_tdl_anchor[g_syncml_context.active_profile - 1] == 0) )
        {
            /* sync all records */
            dataPtr->count = mmi_tdl_get_total_index(dataPtr->luid);
        }
        else if(g_syncml_context.last_tdl_anchor[g_syncml_context.active_profile - 1] == 0)
        {
            dataPtr->count = 0;
        }
        else
        {
            dataPtr->count = mmi_syncml_query_change_log(g_syncml_sync_context.operation, g_syncml_sync_context.database, dataPtr->luid);
        }
    }

    dataPtr->more_data = 0;
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML] Query change log, op = %d, total %d records...", g_syncml_sync_context.operation, dataPtr->count);

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_clean_luid_list_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_clean_luid_list_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_clean_luid_list_req_ind_struct *local_data = (mmi_syncml_clean_luid_list_req_ind_struct*) info;
#if 0
/* under construction !*/
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
    {
        return;
    }

    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;

/* do not clean luid one by one, delete log file directly. 
 * Because when it is a large number , MMI will hang, MMI queue will be full.*/
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    mmi_syncml_clearall_change_log(g_syncml_context.active_profile, local_data->database_type);

    mmi_syncml_clean_luid_list_res_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_clean_luid_list_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_clean_luid_list_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_syncml_clean_luid_list_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_RES_REQ;

    dataPtr =
        (mmi_syncml_clean_luid_list_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_clean_luid_list_res_req_struct));
    dataPtr->result = SYNCML_OK;

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_start_sync_req
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_start_sync_req(U8 *imei)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_syncml_start_sync_req_struct *dataPtr;

    syncml_profile_struct active_profile;
    applib_mime_type_struct *mime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_read_profile_from_nvram(g_syncml_context.active_profile, &active_profile);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_START_SYNC_REQ;

    dataPtr =
        (mmi_syncml_start_sync_req_struct*) construct_local_para(sizeof(mmi_syncml_start_sync_req_struct), TD_CTRL|TD_RESET);

    strcpy((S8*) dataPtr->server_uri, (S8*) active_profile.server_address);
    strcpy((S8*) dataPtr->server_username, (S8*) active_profile.server_username);
    strcpy((S8*) dataPtr->server_password, (S8*) active_profile.server_password);

    if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
    {
        strcpy((S8*) dataPtr->contact_database_uri, (S8*) active_profile.contact_address);
        strcpy((S8*) dataPtr->contact_database_username, (S8*) active_profile.contact_username);
        strcpy((S8*) dataPtr->contact_database_password, (S8*) active_profile.contact_password);
        mime = mime_type_look_up(NULL, NULL, 0, MIME_SUBTYPE_XVCARD);
        strcpy((S8*) dataPtr->contact_mime_type, mime->mime_string);
        dataPtr->contact_last_anchor = g_syncml_context.last_phb_anchor[g_syncml_context.active_profile - 1];
        dataPtr->contact_next_anchor = g_syncml_context.next_phb_anchor;

    #ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
        if (mmi_syncml_is_sync_started_from_server())
        {
            /* replace the database URI by the specified one */
            strcpy((S8*) dataPtr->contact_database_uri, (S8*) g_sas_context.sas_contact_database_uri);
        }
    #endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

        g_syncml_context.contact_sync_state = 1; /* synchronizing */
    }

    dataPtr->contact_free_id = MAX_PB_PHONE_ENTRIES - mmi_phb_get_phone_index_arrary(NULL);
    dataPtr->contact_free_mem = dataPtr->contact_free_id * mmi_phb_sync_get_record_size();

    if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
    {
        strcpy((S8*) dataPtr->calendar_database_uri, (S8*) active_profile.calendar_address);
        strcpy((S8*) dataPtr->calendar_database_username, (S8*) active_profile.calendar_username);
        strcpy((S8*) dataPtr->calendar_database_password, (S8*) active_profile.calendar_password);
        mime = mime_type_look_up(NULL, NULL, 0, MIME_SUBTYPE_XVCALENDAR);
        strcpy((S8*) dataPtr->calendar_mime_type, mime->mime_string);
        dataPtr->calendar_last_anchor = g_syncml_context.last_tdl_anchor[g_syncml_context.active_profile - 1];
        dataPtr->calendar_next_anchor = g_syncml_context.next_tdl_anchor;

    #ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
        if (mmi_syncml_is_sync_started_from_server())
        {
            /* replace the database URI by the specified one */
            strcpy((S8*) dataPtr->calendar_database_uri, (S8*) g_sas_context.sas_calendar_database_uri);
        }
    #endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

        g_syncml_context.calendar_sync_state = 1; /* synchronizing */
        AlmDisableExpiryHandler(); /* disable alarm */
    }

    dataPtr->calendar_free_id = NUM_OF_TDL - mmi_tdl_get_total_index(NULL);
    dataPtr->calendar_free_mem = dataPtr->calendar_free_id * NVRAM_TODO_LIST_RECORD_SIZE;

    memcpy(&dataPtr->imei[0], "IMEI:", 5);
    memcpy(&dataPtr->imei[5], imei, 15);
    dataPtr->imei[20] = 0;

#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    if (g_syncml_context.sync_type == SYNCML_TYPE_BACKUP)
    {
        dataPtr->sync_type = SYNCML_SYNC_CLIENT_ONE_WAY_REFRESH;
    }
    else if (g_syncml_context.sync_type == SYNCML_TYPE_RESTORE)
    {
        dataPtr->sync_type = SYNCML_SYNC_SERVER_ONE_WAY_REFRESH;
    }
    else if (g_syncml_context.sync_type == SYNCML_TYPE_EXPORT)
    {
        dataPtr->sync_type = SYNCML_SYNC_CLIENT_ONE_WAY_SYNC;
    }
    else if (g_syncml_context.sync_type == SYNCML_TYPE_IMPORT)
    {
        dataPtr->sync_type = SYNCML_SYNC_SERVER_ONE_WAY_SYNC;
    }
    else
    {
        dataPtr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;
    }
#else
    dataPtr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    if (g_syncml_context.active_profile > MAX_SYNCML_SV_PROFILES)
    {
        dataPtr->transport_type = SYNCML_TRANS_USB + active_profile.net_id;
    }
    else
    {
        dataPtr->transport_type = (active_profile.conn_type == SYNCML_TRANS_HTTP) ? SYNCML_TRANS_HTTP : SYNCML_TRANS_WSP;
        dataPtr->net_id = active_profile.net_id;
        if (active_profile.use_proxy)
        {
            memcpy(dataPtr->proxy_server_ip, active_profile.proxy_ip, 4);
            dataPtr->proxy_server_port = (active_profile.conn_type == SYNCML_TRANS_HTTP) ? active_profile.proxy_port : 9201;
            strcpy((S8*) dataPtr->proxy_username, (S8*) active_profile.proxy_username);
            strcpy((S8*) dataPtr->proxy_password, (S8*) active_profile.proxy_password);
        }
        else
        {
            memset(dataPtr->proxy_server_ip, 0, 4);
            dataPtr->proxy_server_port = 0;
            memset(dataPtr->proxy_username, 0, MAX_SYNCML_PROXY_USERNAME);
            memset(dataPtr->proxy_password, 0, MAX_SYNCML_PROXY_PASSWORD);
        }
    }

    g_syncml_context.abort_state = 0;

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_finish_sync_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_finish_sync_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_finish_sync_ind_struct *local_data = (mmi_syncml_finish_sync_ind_struct*) info;

    U16 string_id = STR_ID_SYNC_DEFAULT_FAIL;
    U16 image_id = IMG_GLOBAL_UNFINISHED;
    U8 tone_id = ERROR_TONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_phb_sync_now() && !mmi_syncml_is_tdl_sync_now())
    {
        return;
    }

    g_syncml_context.contact_sync_state = 0;
    g_syncml_context.calendar_sync_state = 0;
    g_syncml_context.abort_state = 0;
    g_syncml_context.sync_progress = 0xFF;
    g_syncml_context.contact_send_noc = 0;
    g_syncml_context.contact_send_current = 0;
    g_syncml_context.contact_recv_noc = 0;
    g_syncml_context.contact_recv_current = 0;
    g_syncml_context.calendar_send_noc = 0;
    g_syncml_context.calendar_send_current = 0;
    g_syncml_context.calendar_recv_noc = 0;
    g_syncml_context.calendar_recv_current = 0;

    mmi_syncml_free_vobj_buffer();

    switch (local_data->result)
    {
        /* process local err */
        case SYNCML_LOCAL_DB_FULL:
            string_id = STR_ID_SYNC_LOCALDB_FULL; 
            break;
            
        /* process server err */
        case SYNCML_OK: /* 200 */
            string_id = STR_ID_SYNC_DONE;
            image_id = IMG_GLOBAL_ACTIVATED;
            tone_id = SUCCESS_TONE;
            break;

        case SYNCML_INVALID_CREDENTIAL: /* 401 */
            string_id = STR_ID_SYNC_INVALID_CREDENTIAL;
            break;

        case SYNCML_MISSING_CREDENTIAL: /* 407 */
            string_id = STR_ID_SYNC_MISSING_CREDENTIAL;
            break;

        case SYNCML_PAYMENT_REQUIRED: /* 402 */
            string_id = STR_ID_SYNC_PAYMENT_REQUIRED;
            image_id = IMG_GLOBAL_WARNING;
            tone_id = WARNING_TONE;
            break;

        case SYNCML_CODE_FORBIDDEN: /* 403 */
            string_id = STR_ID_SYNC_CODE_FORBIDDEN;
            break;
            
        case SYNCML_INCOMPLETE_CMD: /* 412 */
            string_id = STR_ID_SYNC_INCOMPLETE_CMD;
            break;
            
        case SYNCML_DEVICE_FULL: /* 420 */
            string_id = STR_ID_SYNC_SVR_DEVICE_FULL;
            break;

        case SYNCML_SERVICE_UNAVAILABLE: /* 503 */
            string_id = STR_ID_SYNC_SERVICE_UNAVAILABLE;
            break;
            
        case SYNCML_DATASTORE_FAIL: /* 510 */
            string_id = STR_ID_SYNC_DATASTORE_FAIL;
            break;
            
        case SYNCML_SVR_FAIL: /* 511 */
            string_id = STR_ID_SYNC_SVR_FAIL;
            break;
            
        case SYNCML_ERR_OCCUR: /* 512 */
            string_id = STR_ID_SYNC_ERR_OCCUR;
            break;

        case SYNCML_PROTOCOL_UNSUPPORT: /* 513 */
            string_id = STR_ID_SYNC_PROTOCOL_UNSUPPORT;
            break;

        case SYNCML_FAIL: /* 500 */
			string_id = STR_ID_SYNC_FAIL;
			break;
		case SYNCML_ABORT_SYNC:
        default:
            break;
    }

    DisplayPopup(
        (U8*) GetString(string_id),
        image_id,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        tone_id);

    SetDelScrnIDCallbackHandler(SCR_ID_SYNC_NOW, NULL);

    DeleteScreenIfPresent(SCR_ID_SYNC_ABORT);
    DeleteScreenIfPresent(SCR_ID_SYNC_BACKGROUND_QUERY);

    if (local_data->result == SYNCML_OK)
    {
        /* update the last anchor because of sync completion */
        if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
        {
            g_syncml_context.last_phb_anchor[g_syncml_context.active_profile - 1] = g_syncml_context.next_phb_anchor;
          
            memcpy(g_syncml_context.svr_contact_ok_cnt, 
                local_data->svr_contact_ok_cnt, 
                sizeof(g_syncml_context.svr_contact_ok_cnt));
            g_syncml_context.svr_contact_ng_cnt = local_data->svr_contact_ng_cnt;
        }
        if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
        {
            g_syncml_context.last_tdl_anchor[g_syncml_context.active_profile - 1] = g_syncml_context.next_tdl_anchor;
            
            memcpy(g_syncml_context.svr_calendar_ok_cnt, 
                local_data->svr_calendar_ok_cnt, 
                sizeof(g_syncml_context.svr_calendar_ok_cnt));
            g_syncml_context.svr_calendar_ng_cnt = local_data->svr_calendar_ng_cnt;
        }
        mmi_syncml_update_settings_to_nvram();
        /* sync report */
        if (g_syncml_context.sync_report_status)
        {
            if (IsScreenPresent(SCR_ID_SYNC_NOW))
            {
                HistoryReplace(SCR_ID_SYNC_NOW, SCR_ID_SYNC_REPORT, mmi_syncml_entry_sync_report);
            }
            else if (isInCall())
            {
                mmi_frm_add_history_before_cm_marker(SCR_ID_SYNC_REPORT, mmi_syncml_entry_sync_report);
            }
            else
            {
                GenericExitScreen(SCR_ID_SYNC_REPORT, mmi_syncml_entry_sync_report);
            }
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_SYNC_NOW);
        }
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_SYNC_NOW);
        if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
        {
            g_syncml_context.next_phb_anchor = g_syncml_context.last_phb_anchor[g_syncml_context.active_profile - 1];
        }
        if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
        {
            g_syncml_context.next_tdl_anchor = g_syncml_context.last_tdl_anchor[g_syncml_context.active_profile - 1];
        }
    }

    if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
    {
        AlmEnableExpiryHandler(); /* enable alarm */
    }

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
    mmi_syncml_sas_finish();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_abort_sync_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_abort_sync_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.abort_state = 1;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_SYNCML;
    Message.oslMsgId = MSG_ID_MMI_SYNCML_ABORT_SYNC_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_imei_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_get_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_NW_GET_IMEI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    SetProtocolEventHandler(mmi_syncml_get_imei_rsp, MSG_ID_MMI_NW_GET_IMEI_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_finish_sync_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_get_imei_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_imei_rsp_struct *dataPtr = (mmi_nw_get_imei_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);

    if (dataPtr->result == 1)
    {
        mmi_syncml_start_sync_req(dataPtr->imei);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_phb_sync_rsp
 * DESCRIPTION
 *  Callback for phonebook access
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_phb_sync_rsp(U16 phb_result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    if (g_syncml_context.sync_type == SYNCML_TYPE_RESTORE && mmi_syncml_is_phb_sync_now() == MMI_FALSE)
    {
        if (phb_result == MMI_PHB_SYNC_SUCCESS)
        {
            /* delete phb for RESTORE sync type */
            mmi_syncml_perform_delete_phb_one_by_one();
        }
        else
        {
            DisplayPopup(
            (U8*) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_SYNC_DELETE_ALL);
        }
        return;
    }
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    switch (phb_result)
    {
        case MMI_PHB_SYNC_SUCCESS:
           g_syncml_sync_context.result = SYNCML_OK;
           break;

        case MMI_PHB_SYNC_STORAGE_FULL:
           g_syncml_sync_context.result = SYNCML_DEVICE_FULL;
           break;

        default:
           g_syncml_sync_context.result = SYNCML_FAIL;
           break;
    }

    if (g_syncml_sync_context.operation == SYNCML_RECORD_ADD)
    {
        g_syncml_sync_context.luid = store_index;
    }

    if (g_syncml_sync_context.operation == SYNCML_RECORD_GET)
    {
        mmi_syncml_get_record_res_req();
    }
    else
    {
        mmi_syncml_set_record_res_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_progress_info_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_progress_info_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_progress_info_ind_struct *dataPtr = (mmi_syncml_progress_info_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[SyncML] progression info = %d...", dataPtr->progress_info);

    /*  get numberofchanges and sending progress info*/
    switch (dataPtr->progress_info)
    {
        case PROGRESS_TASK_LOCAL_NOC:
            g_syncml_context.calendar_send_noc = dataPtr->numberofchange;
            return;
            
        case PROGRESS_CONTACT_LOCAL_NOC:
            g_syncml_context.contact_send_noc = dataPtr->numberofchange;
            return;
                     
        case PROGRESS_TASK_REMOTE_NOC:
            g_syncml_context.calendar_recv_noc = dataPtr->numberofchange;
            return;
                     
        case PROGRESS_CONTACT_REMOTE_NOC:
            g_syncml_context.contact_recv_noc = dataPtr->numberofchange;
            return;
            
        default:
            break;
            
    }

    
    mmi_syncml_update_progress_string(dataPtr->progress_info);

    /* sync report */
    if (g_syncml_context.sync_report_status)
    {
        if (dataPtr->progress_info == PROGRESS_CONTACT_DATASTORE_FAILED)
        {
            mmi_syncml_set_database_sync_fail(SYNCML_DB_PHONEBOOK);
        }

        if (dataPtr->progress_info == PROGRESS_TASK_DATASTORE_FAILED)
        {
            mmi_syncml_set_database_sync_fail(SYNCML_DB_TODOLIST);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_compare_sync_server
 * DESCRIPTION
 *  Compare the active server with a specific string
 * PARAMETERS
 *  comp_server_address        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_syncml_compare_sync_server(U8 *comp_server_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_profile_struct active_profile;
    U8 complen1, complen2, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_read_profile_from_nvram(g_syncml_context.active_profile, &active_profile);

    complen1 = strlen((S8*) active_profile.server_address); 
    complen2 = strlen((S8*) comp_server_address); 

    if (complen2 > complen1)
    {
        return 0;
    }

    for (i = 0; i < complen1 - complen2 + 1; i++)
    {
        if (strncmp((S8*) (active_profile.server_address + i), (S8*)comp_server_address, complen2) == 0)
        {
            return 1;
        }
    }

    return 0;
}


#endif /* __SYNCML_SUPPORT__ */


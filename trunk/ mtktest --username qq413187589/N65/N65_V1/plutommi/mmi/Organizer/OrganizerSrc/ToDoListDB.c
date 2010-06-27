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
 * ToDoListDB.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for providing phonebook interface for java package
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
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef __PIMEVTDB_C__
#define __PIMEVTDB_C__


/*  Include: MMI header file */
#ifdef __MMI_TODOLIST__
#include "CommonScreens.h"
#include "ToDoListEnum.h"
#include "ToDoListDef.h"
#include "SettingProfile.h"


#include "AlarmFrameWorkProt.h"
#include "AlarmDef.h"
#include "DateTimeGprot.h"

#include "ToDoListDB.h"
#include "vObjects.h"
#include "vCalendar.h"
#include "ToDoListDef.h"

#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif /*__J2ME__*/

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGProt.h"
#endif


/*
** Typedef
*/

/*
** Define
*/

/*
** Local Variable
*/

/*
** Local Function
*/

/*
** Global Variable
*/
extern tdl_context_struct g_tdl_cntx;

#ifdef __MMI_VCALENDAR__
extern S32 mmi_vclndr_reader(S8 *file_path_name, ToDoListNode *TdlNode);
extern S32 mmi_vclndr_writer(ToDoListNode *TDLNode, S8 *file_path_name);
#endif

/*
** Global Function
*/
#if defined(SUPPORT_JSR_75_PIM)
/*****************************************************************************
* FUNCTION
*  mmi_phb_handler_init
* DESCRIPTION
*   This function initializes phonebook handler app.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_evtdb_handler_init(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   SetProtocolEventHandler(mmi_tdl_pim_evtdb_wirte_req		,MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ);
   SetProtocolEventHandler(mmi_tdl_pim_evtdb_read_req		,MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_REQ);

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_evtdb_wirte_req
* DESCRIPTION
*   This function write a todolist entry from pim request
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_evtdb_wirte_req(void* info)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_evtdb_java_set_entry_req_struct* LocalPtr;
   mmi_evtdb_java_entry_struct evtdbEntry;
   mmi_evtdb_java_error_enum errorCode = MMI_EVTDB_JAVA_SUCCESS;
   U8  deleteResult, recordindex = 0;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    LocalPtr = (mmi_evtdb_java_set_entry_req_struct*)info;

    /* Init check */
    if ((&g_tdl_cntx == NULL)
#ifdef __SYNCML_SUPPORT__        
        || mmi_syncml_is_tdl_sync_now()
#endif        
        )
    {
        errorCode = MMI_EVTDB_JAVA_TDL_NOT_READY;
    }
    else if(LocalPtr->sort_type != MMI_EVTDB_SORT_BY_TIME)
    {
        errorCode = MMI_EVTDB_JAVA_NOT_SUPPORT;
    }
    else if (LocalPtr->entry_ptr == NULL)
    {
        /* delete record */
        recordindex = LocalPtr->index;

        if (recordindex < NUM_OF_TDL)
        {
            deleteResult = mmi_tdl_delete_record(recordindex);
            if (!deleteResult)
            {
                errorCode = MMI_EVTDB_JAVA_DELETE_FAIL;
            }
        }
        else
        {
            errorCode = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        }
    }
    else /* Add and updaet new record */
    {
        memcpy(&evtdbEntry,LocalPtr->entry_ptr,sizeof(mmi_evtdb_java_entry_struct));

        if (LocalPtr->index == 0xFFFF) /* Add */
        {
            recordindex = mmi_tdl_pim_util_get_new_index();
        }
        else /* Update */
        {
            recordindex = LocalPtr->index;
        }

        if (recordindex < NUM_OF_TDL)
        {
	    errorCode = mmi_tdl_pim_update_record(recordindex, &evtdbEntry);

            if (errorCode <= MMI_EVTDB_JAVA_SUCCESS)
            {
            #ifdef __SYNCML_SUPPORT__
                /* send notification to SyncML */
                if (LocalPtr->index == 0xFFFF)
                {
                    mmi_syncml_tdl_data_changed_notification(SYNCML_RECORD_ADD, recordindex);
                }
                else
                {
                    mmi_syncml_tdl_data_changed_notification(SYNCML_RECORD_MODIFY, recordindex);
                }
            #endif
				TDLWriteToNvram(recordindex);
				/* alarm is canceled */
				if(evtdbEntry.alarm== TODO_LIST_ALARM_OFF)
					AlmCancelAlarm((U8)(recordindex+ALM_TDL_START));
				else if(evtdbEntry.alarm== TODO_LIST_ALARM_ON)
					AlmSetAlarm((U8)(recordindex+ALM_TDL_START));
			}
		}
		else
		{
			errorCode = MMI_EVTDB_JAVA_OUT_OF_INDEX;
		}


    }

    mmi_tdl_pim_write_rsp((U16) errorCode,recordindex);

}

/*****************************************************************************
* FUNCTION
*  mmi_phb_java_write_rsp
* DESCRIPTION
*   This function return write result to JAVA
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_write_rsp(U16 result, U16 store_index)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_evtdb_java_set_entry_rsp_struct *MsgPtr;
   MYQUEUE Message;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   MsgPtr = (mmi_evtdb_java_set_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_evtdb_java_set_entry_rsp_struct));
   MsgPtr->index = MsgPtr->handle = store_index;
   MsgPtr->result = result;


   Message.oslSrcId=MOD_MMI;
   Message.oslDestId=MOD_JASYN;
   Message.oslMsgId = MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_RSP;
   Message.oslDataPtr = (oslParaType *)MsgPtr;
   Message.oslPeerBuffPtr= NULL;

   OslMsgSendExtQueue(&Message);

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_evtdb_read_req
* DESCRIPTION
*   This function read a todolist entry from pim.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_evtdb_read_req(void* info)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   mmi_evtdb_java_get_entry_req_struct* LocalPtr;
   mmi_evtdb_java_error_enum errorCode = MMI_EVTDB_JAVA_SUCCESS;
   U16 count = 0;
//   ToDoListNode tdlItem;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   LocalPtr = (mmi_evtdb_java_get_entry_req_struct*)info;

    /* Init check */
    if ((&g_tdl_cntx == NULL)
#ifdef __SYNCML_SUPPORT__        
                || mmi_syncml_is_tdl_sync_now()
#endif        
        
        )
    {
        errorCode = MMI_EVTDB_JAVA_TDL_NOT_READY;
    }
    else if(LocalPtr->sort_type != MMI_EVTDB_SORT_BY_TIME)
    {
        errorCode = MMI_EVTDB_JAVA_NOT_SUPPORT;
    }

    /* tdl does not init yet */
    if (errorCode > MMI_EVTDB_JAVA_SUCCESS)
    {
        mmi_tdl_pim_read_rsp((U16) errorCode,count);
        return;
    }

    /* init tdl list, sort by date */
    if(LocalPtr->index == 0)
    {
        TDLMakeListOfAllTask();
    }

    if (LocalPtr->count == 0)
    {
        /* get total event amount*/
        count = g_tdl_cntx.TotalListedTask;
    }
    else if (LocalPtr->count != 0)
    {
        /* get a record */
        if (LocalPtr->index < NUM_OF_TDL)
        {
            count = mmi_tdl_pim_get_tdl_field(LocalPtr->index, LocalPtr->entry_ptr);
            if (count == 0)
            {
                errorCode = MMI_EVTDB_JAVA_NOT_FOUND;
            }            
        }
        else
        {
            errorCode = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        }
    }

   mmi_tdl_pim_read_rsp((U16) errorCode,count);

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_read_rsp
* DESCRIPTION
*   This function return read result to JAVA
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_read_rsp(U16 result, U16 count)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_evtdb_java_get_entry_rsp_struct *MsgPtr;
   MYQUEUE Message;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   MsgPtr = (mmi_evtdb_java_get_entry_rsp_struct*) OslConstructDataPtr(sizeof(mmi_evtdb_java_get_entry_rsp_struct));

   MsgPtr->result = result;
   MsgPtr->count = count;

   Message.oslSrcId=MOD_MMI;
   Message.oslDestId=MOD_JASYN;
   Message.oslMsgId = MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_RSP;
   Message.oslDataPtr = (oslParaType *)MsgPtr;
   Message.oslPeerBuffPtr= NULL;

   OslMsgSendExtQueue(&Message);

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_update_record
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
U16 mmi_tdl_pim_update_record(U16 index, mmi_evtdb_java_entry_struct* evtdbEntry)
{
   U16 result;
   ToDoListNode tdlItem;
   mmi_evtdb_java_error_enum errorCode;

    {
        /* Check date/time */
        if (!mmi_dt_is_valid((MYTIME*)&evtdbEntry->startTime))
        {
            return MMI_EVTDB_JAVA_TDL_INVALID_START_TIME;
        }
        else if (!mmi_dt_is_valid((MYTIME*)&evtdbEntry->endTime))
        {
            return MMI_EVTDB_JAVA_TDL_INVALID_END_TIME;
        }

        memcpy(&tdlItem.StartTime, &evtdbEntry->startTime, sizeof(MYTIME));
    #ifdef __MMI_ADVANCED_TODO__
        memcpy(&tdlItem.EndTime, &evtdbEntry->endTime, sizeof(MYTIME));
        if (g_tdl_cntx.TaskList[index].Present == 1)    /* modify */
        {
            tdlItem.Type = g_tdl_cntx.TaskList[index].Type;
            tdlItem.Priority = g_tdl_cntx.TaskList[index].Priority;
            memcpy(tdlItem.Location, g_tdl_cntx.TaskList[index].Location, MAX_TODO_LIST_NOTE);

            if (g_tdl_cntx.TaskList[index].Type != TDL_TASK_REMINDER)
            {
                if (evtdbEntry->startTime.nYear != evtdbEntry->endTime.nYear ||
                    evtdbEntry->startTime.nMonth != evtdbEntry->endTime.nMonth ||
                    evtdbEntry->startTime.nDay!= evtdbEntry->endTime.nDay)
                {
                    return MMI_EVTDB_JAVA_INVALID_DATE;
                }
            }
        }
        else    /* add */
        {
            tdlItem.Type = TDL_TASK_REMINDER;
            tdlItem.Priority = TDL_TASK_PRIORITY_MEDIUM;
            memset(tdlItem.Location, 0, MAX_TODO_LIST_NOTE);
        }
    #else /* __MMI_ADVANCED_TODO__ */ 
        tdlItem.EndHour = evtdbEntry->endTime.nHour;
        tdlItem.EndMin= evtdbEntry->endTime.nMin;
    #endif /* __MMI_ADVANCED_TODO__ */ 
        memcpy(&tdlItem.Note,&evtdbEntry->note,MAX_TODO_LIST_NOTE);
        tdlItem.Alarm = evtdbEntry->alarm;
        //tdlItem.Repeat = evtdbEntry->repeat;
		tdlItem.Repeat = mmi_alm_get_freq_order(TODO_FREQ_NUM + 1, g_tdl_freq_set, evtdbEntry->repeat);
        tdlItem.Days = evtdbEntry->days;
        tdlItem.Present = 1;
        result = mmi_tdl_is_valid_fields(&tdlItem);

        if (result == MMI_TDL_SUCCESS)
        {
            memcpy(&g_tdl_cntx.TaskList[index],&tdlItem,sizeof(ToDoListNode));
            errorCode = MMI_EVTDB_JAVA_SUCCESS;
        }
        else if(result == MMI_TDL_EXPIRED_ALARM)
        {
			memcpy(&g_tdl_cntx.TaskList[index],&tdlItem,sizeof(ToDoListNode));
        	g_tdl_cntx.TaskList[index].Alarm = 0;
        	errorCode = MMI_EVTDB_JAVA_TDL_EXPIRED_ALARM;
        }
        else
        {
            errorCode = (result-MMI_TDL_SUCCESS) + MMI_EVTDB_JAVA_INVALID_DATE;
        }
    }

    return errorCode;

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_get_tdl_field
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
U8 mmi_tdl_pim_get_tdl_field(U16 index, mmi_evtdb_java_entry_struct *entry)
{
    ToDoListNode tdlItem;
    memcpy(&tdlItem, &(g_tdl_cntx.TaskList[g_tdl_cntx.SortedList[index]]), sizeof(ToDoListNode));

    if (tdlItem.Present == 1)
    {
    #ifdef __MMI_ADVANCED_TODO__
        memcpy(&entry->startTime, &tdlItem.StartTime, sizeof(MYTIME));
        memcpy(&entry->endTime, &tdlItem.EndTime, sizeof(MYTIME));
        entry->Type = tdlItem.Type;
        entry->Priority = tdlItem.Priority;
        memcpy(&entry->Location, &tdlItem.Location, MAX_TODO_LIST_NOTE);
        switch (tdlItem.Alarm)
        {
            case TODO_LIST_ALARM_OFF:
                entry->alarm = TODO_LIST_ALARM_OFF;
                break;
            case TODO_LIST_ALARM_ON:
            case TODO_LIST_ALARM_BEFORE_5_MINS:                
            case TODO_LIST_ALARM_BEFORE_15_MINS:
            case TODO_LIST_ALARM_BEFORE_30_MINS:
                entry->alarm = TODO_LIST_ALARM_ON;
                break;
            default:
                break;
        }  
    #else /* __MMI_ADVANCED_TODO__ */ 
        memcpy(&entry->startTime, &tdlItem.StartTime, sizeof(MYTIME));
        entry->endTime.nYear = tdlItem.StartTime.nYear;
        entry->endTime.nMonth = tdlItem.StartTime.nMonth;
        entry->endTime.nDay = tdlItem.StartTime.nDay;
        entry->endTime.nHour= tdlItem.EndHour;
        entry->endTime.nMin= tdlItem.EndMin;
        entry->endTime.nSec = 0;
        entry->alarm= tdlItem.Alarm;
    #endif /* __MMI_ADVANCED_TODO__ */ 
        memcpy(&entry->note,&tdlItem.Note,MAX_TODO_LIST_NOTE);
        entry->repeat= g_tdl_freq_set[tdlItem.Repeat];
        entry->days= tdlItem.Days;

        entry->index= index;
        entry->handle= g_tdl_cntx.SortedList[index];
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_get_handle
* DESCRIPTION
*   This function gets handle by sorted index.
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S16 mmi_tdl_pim_get_handle(U16 index, U8 sort_type)
{
    /* Required index should not be larger than NUM_OF_TDL*/
    if (index >= NUM_OF_TDL)
    {
        return -1;
    }
    
    switch (sort_type)
    {
        case MMI_EVTDB_SORT_BY_TIME:
            /* sort the tdl by date */
        	TDLMakeListOfAllTask();

        	/* if the index is not exist */
            if (g_tdl_cntx.SortedList[index] == 0xFF)
                return -1;
            else
                return (S16)g_tdl_cntx.SortedList[index];
        default:
                return -1;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_get_tdl_field
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S16 mmi_tdl_pim_get_sorted_index(U16 handle, U8 sort_type)
{
    U8 i = 0;

    switch (sort_type)
    {
        case MMI_EVTDB_SORT_BY_TIME:
            /* If the handle point to invalid data */
            if (g_tdl_cntx.TaskList[handle].Present == 0)
                return -1;

            /* sort the tdl by date */
            TDLMakeListOfAllTask();

            for (i=0; i < NUM_OF_TDL ; i++)
            {
                if (g_tdl_cntx.SortedList[i] == handle)
                    break;
            }

            if(i >= NUM_OF_TDL)
            {
                return -1;
            }
            else
            {
                return (S16)i;
            }
        default:
            return -1;
    }
}

#endif /* SUPPORT_JSR_75_PIM */

#if defined(__MMI_VCALENDAR__)
/*****************************************************************************
* FUNCTION
*  mmi_tdl_handler_init
* DESCRIPTION
*   This function initializes todolist handler for at command.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_handler_init(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   SetProtocolEventHandler(mmi_tdl_at_req_ind		,MSG_ID_MMI_EQ_VCALENDAR_REQ_IND);
   PRINT_INFORMATION("[vCalendarAT] Init");
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_req_ind
* DESCRIPTION
*   This function handle AT command to request todolist record.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_req_ind(void* info)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_eq_vcalendar_req_ind_struct* LocalPtr;
   U8 file_path[TDL_FOR_AT_MAX_FILE_PATH_LEN];
   U8 total_task = 0, recordindex, delete_result, i;
   U8 sorted_list[NUM_OF_TDL];
   ToDoListNode task;
   S32 vclndr_error_code;
   U16 checkTDL;
   BOOL result = MMI_TRUE;
   
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    LocalPtr = (mmi_eq_vcalendar_req_ind_struct*)info;

    /* Init check */
    if ((&g_tdl_cntx == NULL)
#ifdef __SYNCML_SUPPORT__        
        || mmi_syncml_is_tdl_sync_now()
#endif        
        )
    {
        //errorCode = MMI_EVTDB_JAVA_TDL_NOT_READY;
    }    

    switch (LocalPtr->mode)
    {
        /*ADD*/
        case MMI_TDL_AT_ADD:
            /* file path check */
            if (LocalPtr->file_path == NULL)
            {
                PRINT_INFORMATION("[vCalendarAT] ADD - file path is null");
                result = MMI_FALSE;
                break;
            }
            
            recordindex = mmi_tdl_pim_util_get_new_index();
            vclndr_error_code = mmi_vclndr_reader((S8*)LocalPtr->file_path, &task);            
            if (vclndr_error_code == VOBJ_ERR_NO_ERROR)
            {
                task.Present = 1;
                checkTDL = mmi_tdl_is_valid_fields(&task);
                
                if (checkTDL > MMI_TDL_SUCCESS)
                {
                    PRINT_INFORMATION("[vCalendarAT] ADD - is not valid tdl");
                    result = MMI_FALSE;
                    break;
                }
                
                if (task.Alarm == TODO_LIST_ALARM_ON && checkTDL == MMI_TDL_SUCCESS)
                {
                    AlmSetAlarm((U8) (recordindex + ALM_TDL_START));
                }
                memcpy(&g_tdl_cntx.TaskList[recordindex], &task, sizeof(ToDoListNode));            
                TDLWriteToNvram(recordindex);

            #ifdef __SYNCML_SUPPORT__
                /* SyncML notification */
                mmi_syncml_tdl_data_changed_notification(SYNCML_RECORD_ADD, recordindex);
            #endif
                
            }
            else
            {
                result = MMI_FALSE;
            }
        break;
        /*UPDATE*/
        case MMI_TDL_AT_UPDATE:
            total_task =mmi_tdl_at_get_sorted_list(sorted_list);
            /* index and file path check */
            if (LocalPtr->file_path == NULL || LocalPtr->index >= NUM_OF_TDL || \
                g_tdl_cntx.TaskList[sorted_list[LocalPtr->index]].Present != 1)
            {
                PRINT_INFORMATION("[vCalendarAT] UPDATE - file path is null");
                PRINT_INFORMATION("[vCalendarAT] UPDATE - LocalPtr->index = %d", LocalPtr->index);
                PRINT_INFORMATION("[vCalendarAT] UPDATE - g_tdl_cntx.TaskList[sorted_list[LocalPtr->index]].Present = %d", g_tdl_cntx.TaskList[sorted_list[LocalPtr->index]].Present);
                result = MMI_FALSE;
                break;
            }
            
            vclndr_error_code = mmi_vclndr_reader((S8*)LocalPtr->file_path, &task);
            
            if (vclndr_error_code == VOBJ_ERR_NO_ERROR)
            {
                task.Present = 1;
                checkTDL = mmi_tdl_is_valid_fields(&task);
                
                if (checkTDL > MMI_TDL_SUCCESS)
                {
                    PRINT_INFORMATION("[vCalendarAT] UPDATE - is not valid tdl");
                    result = MMI_FALSE;
                    break;
                }
                
                if (task.Alarm == TODO_LIST_ALARM_ON && checkTDL == MMI_TDL_SUCCESS)
                {
                    AlmSetAlarm((U8) (sorted_list[LocalPtr->index] + ALM_TDL_START));
                }
                memcpy(&g_tdl_cntx.TaskList[sorted_list[LocalPtr->index]], &task, sizeof(ToDoListNode));            
                TDLWriteToNvram(sorted_list[LocalPtr->index]);

            #ifdef __SYNCML_SUPPORT__
                /* SyncML notification */
                mmi_syncml_tdl_data_changed_notification(SYNCML_RECORD_MODIFY, sorted_list[LocalPtr->index]);
            #endif
            }    
            else
            {
                result = MMI_FALSE;		
            }        
        break;
        /*DELETE*/
        case MMI_TDL_AT_DELETE:
            total_task =mmi_tdl_at_get_sorted_list(sorted_list);

            if (LocalPtr->index >= NUM_OF_TDL)
            {
                PRINT_INFORMATION("[vCalendarAT] DELETE - LocalPtr->index = %d", LocalPtr->index);
                result = MMI_FALSE;
                break;
            }

            delete_result = mmi_tdl_delete_record(sorted_list[LocalPtr->index]);
            /* delete fail */
            if (delete_result != MMI_TRUE)
            {
                PRINT_INFORMATION("[vCalendarAT] DELETE - Delete failed");
                result = MMI_FALSE;
                break;
            }                       
        break;
        /*READ*/
        case MMI_TDL_AT_READ:
            total_task =mmi_tdl_at_get_sorted_list(sorted_list);

            /* index check*/
            if (LocalPtr->index >= NUM_OF_TDL)
            {
                PRINT_INFORMATION("[vCalendarAT] READ - LocalPtr->index = %d", LocalPtr->index);
                result = MMI_FALSE;
                break;
            }
            memset(file_path, 0, TDL_FOR_AT_MAX_FILE_PATH_LEN);
            mmi_vclndr_uti_get_default_at_command_filename((S8*)file_path);
            vclndr_error_code = mmi_vclndr_writer(&g_tdl_cntx.TaskList[sorted_list[LocalPtr->index]], (S8*)file_path);

            if (vclndr_error_code != VOBJ_ERR_NO_ERROR)
            {
                PRINT_INFORMATION("[vCalendarAT] READ - is not valid tdl");
                result = MMI_FALSE;
                break;
            }
    
        break;
        /*QUERY*/
        case MMI_TDL_AT_QUERY:
            total_task = 0;
            for (i = 0; i < NUM_OF_TDL; i++)
            {
                if (g_tdl_cntx.TaskList[i].Present == 1)
                {
                    total_task++;
                }
            }
            PRINT_INFORMATION("[vCalendarAT] QUERY - total_task = %d", total_task);
        break;
        
    }

    mmi_tdl_at_res_req(LocalPtr->mode,result, total_task, file_path);

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_res_req
* DESCRIPTION
*   This function return result to AT command
*
* PARAMETERS
*  
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_res_req(U8 mode, BOOL result, U8 number, U8 *file_path)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_eq_vcalendar_res_req_struct *MsgPtr;
   MYQUEUE Message;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   MsgPtr = (mmi_eq_vcalendar_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_vcalendar_res_req_struct));
   MsgPtr->mode = mode;
   MsgPtr->result = result;
    if (MsgPtr->mode == MMI_TDL_AT_QUERY)
    {
        MsgPtr->number = number;
    }
    else if (MsgPtr->mode == MMI_TDL_AT_READ)
    {
        memcpy(MsgPtr->file_path, file_path, TDL_FOR_AT_MAX_FILE_PATH_LEN);
    }
 
   Message.oslSrcId=MOD_MMI;
   Message.oslDestId=MOD_L4C;
   Message.oslMsgId = MSG_ID_MMI_EQ_VCALENDAR_RES_REQ;
   Message.oslDataPtr = (oslParaType *)MsgPtr;
   Message.oslPeerBuffPtr= NULL;

   OslMsgSendExtQueue(&Message);

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_get_sorted_list
* DESCRIPTION
*   This function sort all todolist items for AT command
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
U8 mmi_tdl_at_get_sorted_list(U8 *sorted_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, total_task;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_task = 0;
    memset(sorted_list, 0xFF, sizeof(sorted_list));
    for (i = 0; i < NUM_OF_TDL; i++)
    {
        if (g_tdl_cntx.TaskList[i].Present == 1)
        {
            sorted_list[total_task] = i;
            total_task++;
        }
    }

    TDLSortTask(sorted_list, total_task);
    
    return total_task;
}
#endif /*defined(__MMI_VCALENDAR__)*/
#endif /*__MMI_TODOLIST__*/
#endif /*__PIMEVTDB_C__*/


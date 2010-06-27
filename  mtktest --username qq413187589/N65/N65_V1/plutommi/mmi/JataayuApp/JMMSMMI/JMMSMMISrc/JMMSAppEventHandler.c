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
 *  JMMSAppEventHandler.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the ui for template folder in mms
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JMMSAPPEVENTHANDLER_C
#define _MMI_JMMSAPPEVENTHANDLER_C

/***************************************************************************** 
* Include
*****************************************************************************/
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

/* Task Message Communication */

#include "wgui.h"
#include "IdleAppProt.h"
#include "ProtocolEvents.h"
#include "DateTimeType.h"
#include "ThrdOsInterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MiscFunctions.h"
#include "TaskInit.h"

#ifdef MMI_ON_HARDWARE_P
#include "custom_util.h"
#endif /* MMI_ON_HARDWARE_P */ 

/* JDD */
#include "jdd_config.h"
#include "ddl.h"
#include "jcal.h"
#include "wap_ps_struct.h"
#include "jcalnet.h"
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include "jdd_memapi.h"
// #include "transport.h"

// #include <jdi_miscutils.h>
#include <jdi_communicator.h>

#include "JMMSExdcl.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/* have to declare it here as its decalartion is not present in any .h */


/*****************************************************************************
 * FUNCTION
 *  jMMSAppProcessEventsInQueue
 * DESCRIPTION
 *  This function is used by MMS ui to process one event in its jQueue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jMMSAppProcessEventsInQueue()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code;
    JC_EVENT_DATA event_data;
    JC_TASK_INFO task_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    task_info.iAppID = (JC_INT32) E_TASK_MMS_UI;
    task_info.iTaskID = (JC_INT32) E_TASK_MMS_UI;


    jc_memset(&event_data, 0, sizeof(JC_EVENT_DATA));
    error_code = jdd_QueueRecv(&task_info, &event_data);

    if (error_code == JC_ERR_QUEUE_EMPTY)
    {
        return;
    }

    if (error_code != JC_OK)
    {
        ASSERT(0);
    }
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    if (E_TASK_TRANSPORT == event_data.srcTaskInfo.iTaskID)
    {
        error_code = jdi_CommunicationEventHandler(g_jmms_context->comm_handle, &event_data);

    }
    else if (E_TASK_MMS_UI == event_data.srcTaskInfo.iTaskID)
    {
        mmi_jmms_ui_events_hdlr(&event_data);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jMMSCoreProcessEventsInQueue
 * DESCRIPTION
 *  This function is used by broser core to process one event in its jQueue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jMMSCoreProcessEventsInQueue()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code;
    JC_EVENT_DATA event_data;
    JC_TASK_INFO task_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    task_info.iAppID = (JC_INT32) E_TASK_MMS_CORE;
    task_info.iTaskID = (JC_INT32) E_TASK_MMS_CORE;


    jc_memset(&event_data, 0, sizeof(JC_EVENT_DATA));
    error_code = jdd_QueueRecv(&task_info, &event_data);

    if (error_code == JC_ERR_QUEUE_EMPTY)
    {
        return;
    }
    jdd_MemSetActiveModuleID(E_TASK_MMS_CORE);
    if (error_code != JC_OK)
    {
        ASSERT(0);  /* In our implementation, we don't allow it happen */
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_mms_queue
 * DESCRIPTION
 *  Used to create MMS queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_mms_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_QueueCreate(
        (JC_INT32) E_TASK_MMS_UI,
        "MMS UI QUEUE",
        sizeof(JC_EVENT_DATA),
        MAX_NUMBER_OF_EVENTS_IN_MMS_QUEUE,
        E_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_ui_events_hdlr
 * DESCRIPTION
 *  Handles UI events
 * PARAMETERS
 *  event_data_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_ui_events_hdlr(JC_EVENT_DATA *event_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_ui_events_hdlr");

    switch (event_data_p->iEventType)
    {
        case E_MMS_GET_MSG_LIST_EVENT:
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Event: E_MMS_GET_MSG_LIST_EVENT");

            mmi_jmms_recieve_get_msg_list_event(event_data_p->pEventInfo);

            break;
        }
        case E_COMM_ERROR_INDICATION_EVENT:
        {

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Event: E_COMM_ERROR_INDICATION_EVENT");

            mmi_jmms_retry_for_error_in_comm(event_data_p->pEventInfo);

            break;
        }
    }
    if (NULL != event_data_p->pEventInfo)   /* remove memory leak */
    {
        jdd_QueueFree(event_data_p);
    }
}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#endif /* _MMI_JMMSAPPEVENTHANDLER_C */ 


/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  jBrowserAppEventHandler.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JBROWSERAPPEVENTHANDLER_C
#define _MMI_JBROWSERAPPEVENTHANDLER_C

/***************************************************************************** 
* Include
*****************************************************************************/
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
/* Task Message Communication */

#include "wgui.h"
#include "IdleAppProt.h"
#include "ProtocolEvents.h"
#include "DateTimeType.h"
#include "ThrdOsInterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MiscFunctions.h"
#include "TaskInit.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"

#ifdef MMI_ON_HARDWARE_P
#include "custom_util.h"
#endif /* MMI_ON_HARDWARE_P */ 

/* JDD */
#include "jdd_config.h"
#include "ddl.h"
#include "jcal.h"
#include "wap_ps_struct.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_app_process_events_in_queue
 * DESCRIPTION
 *  This function is used by browser ui to process one event in its jQueue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_app_process_events_in_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;
    JC_EVENT_DATA eventdata;
    JC_TASK_INFO taskinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    taskinfo.iAppID = (JC_INT32) E_TASK_BROWSER_UI;
    taskinfo.iTaskID = (JC_INT32) E_TASK_BROWSER_UI;

    /* jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI); */

    jc_memset(&eventdata, 0, sizeof(JC_EVENT_DATA));
    ret = jdd_QueueRecv(&taskinfo, &eventdata);

    if (ret == JC_ERR_QUEUE_EMPTY)
    {
        return;
    }
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);
    if (ret != JC_OK)
    {
        ASSERT(0);  /* In our implementation, we don't allow it happen */
    }
    if (E_TASK_TRANSPORT == eventdata.srcTaskInfo.iTaskID)
    {
    #if defined(JBROWSER_USE_ASM)
        if (g_mmi_brw_cntx.is_layout_initialized &&
            ((eventdata.iEventType != E_TR_PUSH_HEADER_IND_EVENT) &&
             (eventdata.iEventType != E_TR_PUSH_CONTENT_IND_EVENT)))
        {
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        }
    #endif /* defined(JBROWSER_USE_ASM) */ 

        ret = jdi_BrowserHandleTransportResponse(g_mmi_brw_pbrowser_ctxt, &eventdata);
    }
    else if (E_TASK_BROWSER_UI == eventdata.srcTaskInfo.iTaskID)        /* addded by pranav */
    {
        mmi_jdd_browser_ui_events_hdlr(&eventdata);
    }
    else
    {
        ASSERT(0);
    }
    /* To-Do: Add function here to process the Event */
    // mmi_jdd_browser_ui_events_hdlr(&eventdata);  /* addded by shantanu -20051124 */
    if (eventdata.iEventType == 5566)               /* For Auto Test only */
        //autoTest_MMI();
        //process_browoser_ui_event(&eventdata);

        /* To avoid to block other MMI application too long, we process one event at one time. */
        /* If there are events in jQueue, we send MSG_ID_MMI_JATAAYU_QUEUE_RECV_IND to MMI task again. */

    {
        return;
    }
}   /* end of jBrowserAppProcessEventsInQueue */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_jbrowser_core_process_events_in_queue
 * DESCRIPTION
 *  This function is used by broser core to process one event in its jQueue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_jbrowser_core_process_events_in_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;
    JC_EVENT_DATA eventdata;
    JC_TASK_INFO taskinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    taskinfo.iAppID = (JC_INT32) E_TASK_BROWSER_CORE;
    taskinfo.iTaskID = (JC_INT32) E_TASK_BROWSER_CORE;

    jc_memset(&eventdata, 0, sizeof(JC_EVENT_DATA));
    ret = jdd_QueueRecv(&taskinfo, &eventdata);

    if (ret == JC_ERR_QUEUE_EMPTY)
    {
        return;
    }

    if (ret != JC_OK)
    {
        ASSERT(0);  /* In our implementation, we don't allow it happen */
    }

    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    /* To-Do: Add function here to process the Event */
    mmi_brw_jdd_browser_core_events_hdlr(&eventdata);
    /* process_browoser_core_event(&eventdata); */

    /* To avoid to block other MMI application too long, we process one event at one time. */
    /* If there are events in jQueue, we send MSG_ID_MMI_JATAAYU_QUEUE_RECV_IND to MMI task again. */

    return;
}   /* end of jBrowserAppProcessEventsInQueue */
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _MMI_JBROWSERAPPEVENTHANDLER_C */ 


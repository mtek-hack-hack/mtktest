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
 *   wps_env.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements WPS modules thread related function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_errc.h"
#include "msf_wid.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_lib.h"

#include "stk_if.h"
#ifdef WAP_SEC_SUPPORT
#include "sec_if.h"
#endif 
#include "wps_if.h"

#include "wps_main.h"

#ifdef WPS_SUPPORT
/**********************************************************************
 * Function declarations
 **********************************************************************/

static void wps_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p);

/**********************************************************************
 * Function definitions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  WPSc_start
 * DESCRIPTION
 *  this function will be called when module jas is initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WPSc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wps_inside_run = FALSE;
    wps_initial();
}


/*****************************************************************************
 * FUNCTION
 *  WPSc_wantsToRun
 * DESCRIPTION
 *  this function will be called when MSF environment want to known module jas have something to do or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int WPSc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int returnVal;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    returnVal = (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_WPS) > 0);

    return returnVal;
}


/*****************************************************************************
 * FUNCTION
 *  WPSc_run
 * DESCRIPTION
 *  this function will be called when module JAS want process something.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WPSc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (setjmp(wps_jmp_buf) == 0)
    {
        wps_inside_run = TRUE;

        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_WPS, wps_receive));

        wps_inside_run = FALSE;
    }
    else
    {
        /*
         * A longjmp from wps_exception_handler. If we are here there is no more
         * * memory, and the situation could not be worse.
         * * Send out an error and terminate.
         */
        MSF_ERROR(MSF_MODID_WPS, MSF_ERR_MODULE_OUT_OF_MEMORY);
        MSF_PIPE_CLOSE_ALL(MSF_MODID_WPS);
        MSF_FILE_CLOSE_ALL(MSF_MODID_WPS);
        MSF_WIDGET_RELEASE_ALL(MSF_MODID_WPS);
        MSF_MEM_FREE_ALL(MSF_MODID_WPS);
        MSF_MODULE_IS_TERMINATED(MSF_MODID_WPS);
        MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_WPS);
        MSF_KILL_TASK(MSF_MODID_WPS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WPSc_kill
 * DESCRIPTION
 *  this function will be called MSF environment want terminate jas module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WPSc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_PIPE_CLOSE_ALL(MSF_MODID_WPS);
    MSF_FILE_CLOSE_ALL(MSF_MODID_WPS);
    MSF_WIDGET_RELEASE_ALL(MSF_MODID_WPS);
    MSF_MEM_FREE_ALL(MSF_MODID_WPS);
    MSF_KILL_TASK(MSF_MODID_WPS);
}


/*****************************************************************************
 * FUNCTION
 *  wps_receive
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  srcModule       [IN]        
 *  signal          [IN]        
 *  p               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        case MSF_SIG_PIPE_NOTIFY:
            wps_pipe_notify(p);
            break;
        case STK_SIG_HTTP_REPLY:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WPS,
                         WPS_ENV_DB6448E8936FC5E3250305F37C7664C0, "WPS: received STK_SIG_HTTP_REPLY, requestId=%d"
                         ", status=%d\n", ((stk_http_reply_t*) p)->requestId, ((stk_http_reply_t*) p)->status));
            wps_http_reply(p);
            break;
        case STK_SIG_HTTP_REQUEST_ABORTED:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WPS,
                         WPS_ENV_27D1665225B854A69D662FC3AC6FF10C, "WPS: received STK_SIG_HTTP_REQUEST_ABORTED, requestId=%d"
                         ", errorCode=%d\n", ((stk_http_request_aborted_t*) p)->requestId,
                         ((stk_http_request_aborted_t*) p)->errorCode));
            wps_http_abort(p);
            break;
        case STK_SIG_STREAM_CONNECTION_CREATED:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WPS,
                         WPS_ENV_79573B9BA7F2100EB263FEAC6BD4458B, "WPS: received STK_SIG_STREAM_CONNECTION_CREATED, channel_id=%d, socket=%d\n",
                         ((stk_stream_connection_created_t*) p)->connectionId, ((stk_stream_connection_created_t*) p)->socketId));
            wps_stream_connection_created(p);
            break;
        case STK_SIG_CONNECTION_CLOSED:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_WPS,
                         WPS_ENV_DE284A5301653194AEA2D45ADB5A8333, "WPS: received STK_SIG_CONNECTION_CLOSED, channel_id=%d, errorCode=%d\n",
                         ((stk_connection_closed_t*) p)->connectionId, ((stk_connection_closed_t*) p)->errorCode));
            wps_stream_connection_closed(p);
            break;
        case MSF_SIG_MODULE_TERMINATE:
            wps_terminate();
            break;
        case MSF_SIG_MODULE_EXECUTE_COMMAND:
            wps_handle_command(p);
            break;
    #ifdef WAP_SEC_SUPPORT
        case SEC_SIG_GET_SESSION_INFO_RESPONSE:
            wps_get_session_info_rsp(p);
            break;
        case SEC_SIG_GET_CURRENT_CERT_RESPONSE:
            wps_get_current_cert_rsp(p);
            break;
        case SEC_SIG_GET_CERT_IDS_RESPONSE:
            wps_get_cert_ids_rsp(p);
            break;
        case SEC_SIG_GET_CERT_RESPONSE:
            wps_get_cert_rsp(p);
            break;            
        case SEC_SIG_VERIFY_CERT_CHAIN_RESPONSE:
            wps_verify_cert_chain_rsp(p);
            break;
    #endif /* WAP_SEC_SUPPORT */ 
        case WPS_SIG_CONFIGURE_CHANNEL:
        case WPS_SIG_CONFIGURE_PROXY_CHANNEL:
        case WPS_SIG_REMOVE_CHANNEL:
        case WPS_SIG_HTTP_REQUEST:
        case WPS_SIG_CANCEL_REQUEST:
        case WPS_SIG_CLEAR:
            MSF_MEM_FREE(MSF_MODID_WPS, p);
            break;
        case WPS_SIG_HTTP_AUTH_INDICATION:
            wps_http_auth_ind(p);
            break;
        default:
            MSF_MEM_FREE(MSF_MODID_WPS, p);
            break;
    }
}

#endif /* WPS_SUPPORT */ 


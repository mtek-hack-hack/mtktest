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
 * msf_socket.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating WAP socket APIs.
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

#ifndef __MTK_TARGET__
#include <windows.h>
#endif

#include "msf_int.h"
#include "msf_lib.h"
#include "msf_log.h"

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

#include "app_buff_alloc.h"

#include "stdarg.h"
#include "stdio.h"

#include "msf_cfg.h"
#include "msm_int.h"
#include "msf_env.h"
#include "msf_sock.h"

/* for socket */
#include "soc_api.h"
#include "app2soc_struct.h"
#include "soc2tcpip_struct.h"
#include "mnsms_struct.h"

#include "bra_if.h"
#include "bra_int.h"

#define HDISOCKDBG_     MSF_LOG_MSG_ARGS

eventid msf_start_timer(MSF_UINT32 timeInterval, kal_timer_func_ptr timer_hdlr, void *event_param);

/**********************************************************************
 * HDI Socket 
 **********************************************************************/

#define HDI_SOCKET_CNTX(X)             (HDIa_socket_cntx.X)
#define SOCKET_RET_CODE_TO_HDI(errno)  HDIa_socket_retcode(errno)
#define SOCKET_TYPE_FROM_HDI(type)     (type == HDI_SOCKET_TYPE_UDP) ? SOCK_DGRAM : ((type == HDI_SOCKET_TYPE_TCP) ? SOCK_STREAM : SOCK_SMS)
#define HDI_INVALID_MODID              0xff
#define HDI_WAIT_CONN_TIME_WHEN_FAIL   10       /* 100 ms as 1 unit */
#define MAX_SOC_ACCOUNT_NUM            2
#define SOC_INVALID_ACCOUNT_ID         0xff
#define HDI_MAX_SOCKET_NUM             30


typedef struct
{
    kal_uint8 mod_id;
    kal_uint8 identifier;
    eventid event_id;
    int result;
} HDIa_socket_event_struct;

typedef struct
{
    kal_uint8 mod_id[HDI_MAX_SOCKET_NUM];   /* store the mod id */
    kal_uint8 soc_type[HDI_MAX_SOCKET_NUM]; /* store the soc type */
    kal_uint32 acc_id[HDI_MAX_SOCKET_NUM];
    HDIa_socket_event_struct event[HDI_MAX_SOCKET_NUM];
    kal_uint32 act_acc_id;
    kal_uint32 wait_disc_account[MAX_SOC_ACCOUNT_NUM];
} HDIa_socket_cntx_struct;

MSF_INT32 last_error;

HDIa_socket_cntx_struct HDIa_socket_cntx;

#ifdef WAP_QUEUE_SMS_PUSH
static kal_int8 sms_push_socketid = -1;
static kal_int8 sms_push_wait_recv = -1;
#endif /* WAP_QUEUE_SMS_PUSH */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_getLastError
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT32 HDIa_getLastError(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 error = last_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_error = 0;
    return error;
}


/*****************************************************************************
 * FUNCTION
 *  HDI_get_empty_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 HDI_get_empty_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < HDI_MAX_SOCKET_NUM; i++)
    {
        if (HDI_SOCKET_CNTX(event[i].event_id) == NULL)
        {
            return i;
        }
    }
    ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketTermBearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketTermBearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDI_SOCKET_CNTX(act_acc_id) = 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketDiscBearerById
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketDiscBearerById(MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 s, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void wap_disc_bearer_by_id(MSF_INT32 networkAccountID);

    /* Disconnect the bearer anyways if account id is 0xff */
    if (networkAccountID == 0xff)
    {
        wap_disc_bearer_by_id(networkAccountID);
        return;
    }
    
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_F207B8B8D2DFADD2F3E2E42FA5DF8E67,
        "HDIa_socketDiscBearer: networkAccountID=%d\n", networkAccountID));

    for (s = 0; s < HDI_MAX_SOCKET_NUM; s++)
    {
        if (HDI_SOCKET_CNTX(acc_id[s]) != networkAccountID)
        {
            continue;
        }

        if (HDI_SOCKET_CNTX(mod_id[s]) != HDI_INVALID_MODID
            && HDI_SOCKET_CNTX(soc_type[s]) != MSF_SOCKET_TYPE_SMS_DATA
            && HDI_SOCKET_CNTX(soc_type[s]) != MSF_SOCKET_TYPE_SMS_RAW)
        {
            kal_uint8 reg_event;

            soc_getsockopt(s, SOC_SILENT_LISTEN, &reg_event, sizeof(reg_event));

            if (!reg_event)
            {
                for (i = 0; i < MAX_SOC_ACCOUNT_NUM; i++)
                {
                    if (HDI_SOCKET_CNTX(wait_disc_account[i]) == SOC_INVALID_ACCOUNT_ID)
                    {
                        HDI_SOCKET_CNTX(wait_disc_account[i]) = HDI_SOCKET_CNTX(acc_id[s]);
                        return;
                    }
                    else if (HDI_SOCKET_CNTX(wait_disc_account[i]) == networkAccountID)
                    {
                        return;
                    }
                }
                ASSERT(0);
            }
        }
    }

    if (networkAccountID == (MSF_INT32) BRAif_getNetAccId())
    {
        BRAa_setBearerState(SOC_DEACTIVATING);
    }

    wap_disc_bearer_by_id(networkAccountID);

    for (i = 0; i < MAX_SOC_ACCOUNT_NUM; i++)
    {
        if (HDI_SOCKET_CNTX(wait_disc_account[i]) == networkAccountID)
        {
            HDI_SOCKET_CNTX(wait_disc_account[i]) = SOC_INVALID_ACCOUNT_ID;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socket_retcode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socket_retcode(kal_int8 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret >= 0)
    {
        return ret; /* success case */
    }

    switch (ret)
    {
        case SOC_INVALID_SOCKET:
            return HDI_SOCKET_ERROR_BAD_ID;

        case SOC_INVAL:
            return HDI_SOCKET_ERROR_INVALID_PARAM;

        case SOC_WOULDBLOCK:
            return HDI_SOCKET_ERROR_DELAYED;

        case SOC_MSGSIZE:
            return HDI_SOCKET_ERROR_MSG_SIZE;

        case SOC_LIMIT_RESOURCE:
            return HDI_SOCKET_ERROR_RESOURCE_LIMIT;
            //case SOC_NOTCONN:
            //     return 
        default:
            return HDI_SOCKET_ERROR_INVALID_PARAM;
    }
}

#ifdef WAP_QUEUE_SMS_PUSH       /* johnnie 20050116 */


/*****************************************************************************
 * FUNCTION
 *  HDI_notifySmsPush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_notifySmsPush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_BAE339718EDE8D301D6CBFCFB71042A9,
        "HDI_notifySmsPush: sms_push_wait_recv=%d\n", sms_push_wait_recv));
    if (sms_push_wait_recv > 0)
    {
        HDIc_socketNotify(MSF_MODID_STK, sms_push_socketid, HDI_SOCKET_EVENT_RECV);
        sms_push_wait_recv = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDI_registerSmsPush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_registerSmsPush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_sockaddr_t addr;
    kal_int8 socketid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_push_socketid = -1;
    sms_push_wait_recv = -1;

    socketid = HDIa_socketCreate(MSF_MODID_STK, HDI_SOCKET_TYPE_SMS_DATA, 0);
    ASSERT(socketid >= 0);

    addr.addrLen = 0;
    addr.port = 2948;
    ASSERT(HDIa_socketBind(socketid, &addr) >= 0);

    sms_push_socketid = socketid;
    sms_push_wait_recv = 0;
}
#endif /* WAP_QUEUE_SMS_PUSH */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_holdBearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                   [IN]        
 *  networkAccountID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_holdBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID)
{
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_releaseBearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                   [IN]        
 *  networkAccountID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_releaseBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_socketDiscBearerById(networkAccountID);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&HDIa_socket_cntx, 0xff, sizeof(HDIa_socket_cntx_struct));
    kal_mem_set(HDI_SOCKET_CNTX(event), 0, (HDI_MAX_SOCKET_NUM * sizeof(HDIa_socket_event_struct)));

    last_error = 0;

    for (i = 0; i < MAX_SOC_ACCOUNT_NUM; i++)
    {
        HDI_SOCKET_CNTX(wait_disc_account[i]) = SOC_INVALID_ACCOUNT_ID;
    }
#ifdef WAP_QUEUE_SMS_PUSH
    if (sms_push_socketid == -1)
    {
        /* register in wap_task_main() when task Init */
    }
    else
    {
        HDI_SOCKET_CNTX(mod_id[sms_push_socketid]) = MSF_MODID_STK;
        HDI_SOCKET_CNTX(soc_type[sms_push_socketid]) = HDI_SOCKET_TYPE_SMS_DATA;
        /* HDI_registerSmsPush(); */
    }
#endif /* WAP_QUEUE_SMS_PUSH */ 

}


/*****************************************************************************
 * FUNCTION
 *  HDI_waitConnExpiry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_param     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_waitConnExpiry(void *event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDIa_socket_event_struct *event_ptr;
    kal_uint8 socketId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_ptr = (HDIa_socket_event_struct*) event_param;
    socketId = event_ptr->identifier;

    event_ptr->event_id = NULL;

    if (HDI_SOCKET_CNTX(mod_id[socketId]) == HDI_INVALID_MODID)
    {
        return;
    }

    HDIc_socketConnectResponse(HDI_SOCKET_CNTX(mod_id[socketId]), socketId, event_ptr->result);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketNotify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketNotify(local_para_struct *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *ind_ptr;
    kal_uint8 event = 0;
    kal_uint8 reg_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(local_para_ptr != NULL);

    ind_ptr = (app_soc_notify_ind_struct*) local_para_ptr;

    if ((ind_ptr->socket_id < 0) || (ind_ptr->socket_id >= HDI_MAX_SOCKET_NUM))
    {
        /* LOG ERROR */
        return;
    }

    switch (ind_ptr->event_type)
    {
        case SOC_READ:
            event = HDI_SOCKET_EVENT_RECV;
            /* no break */
        case SOC_WRITE:
            if (ind_ptr->event_type == SOC_WRITE)
            {
                event = HDI_SOCKET_EVENT_SEND;
            }

            soc_getsockopt(ind_ptr->socket_id, SOC_ASYNC, &reg_event, sizeof(reg_event));

            if ((reg_event & ind_ptr->event_type))
            {
                reg_event &= ~ind_ptr->event_type;
                soc_setsockopt(ind_ptr->socket_id, SOC_ASYNC, &reg_event, sizeof(reg_event));
            }
            else
            {
                return; /* already clear this event, ignore !! */
            }

            break;

        case SOC_CLOSE:
            event = HDI_SOCKET_EVENT_CLOSED;
            break;

    case SOC_CONNECT:
        event = HDI_SOCKET_EVENT_CONNECTED;
        break;

    case SOC_ACCEPT:
        event = HDI_SOCKET_EVENT_ACCEPT;
        break;

    default:
        /* LOG ERROR */
        break;
    }   /* switch */

#ifdef WAP_QUEUE_SMS_PUSH
    {
        extern int MSF_wapIsInit(void);
        extern kal_uint8 wap_status;

        if (wap_status != WAP_RUNNING || MSF_wapIsInit())
        {
            if (event == HDI_SOCKET_EVENT_RECV && ind_ptr->socket_id == sms_push_socketid)
            {
                sms_push_wait_recv++;
                return;
            }
        }
    }
#endif /* WAP_QUEUE_SMS_PUSH */ 

    if (event == HDI_SOCKET_EVENT_CONNECTED)
    {
        if (ind_ptr->result == KAL_FALSE)
        {
            kal_uint8 idx = HDI_get_empty_event();

            HDI_SOCKET_CNTX(event[idx].mod_id) = HDI_SOCKET_CNTX(mod_id[ind_ptr->socket_id]);
            HDI_SOCKET_CNTX(event[idx].identifier) = ind_ptr->socket_id;
            HDI_SOCKET_CNTX(event[idx].result) = HDI_SOCKET_ERROR_CONNECTION_FAILED;
            HDI_SOCKET_CNTX(event[idx].event_id) = msf_start_timer(
                                                    HDI_WAIT_CONN_TIME_WHEN_FAIL,
                                                    HDI_waitConnExpiry,
                                                    (void*)&(HDI_SOCKET_CNTX(event[idx])));
            if (ind_ptr->error_cause == SOC_BEARER_FAIL)
            {
                last_error = ind_ptr->detail_cause;
            }

            if (HDI_SOCKET_CNTX(event[idx].event_id))
            {
                return;
            }

            HDIc_socketConnectResponse(
                HDI_SOCKET_CNTX(mod_id[ind_ptr->socket_id]),
                ind_ptr->socket_id,
                HDI_SOCKET_ERROR_CONNECTION_FAILED);
            return;
        }

        HDIc_socketConnectResponse(HDI_SOCKET_CNTX(mod_id[ind_ptr->socket_id]), ind_ptr->socket_id, 0 /* succ */ );

    }
    else
    {
        HDIc_socketNotify(HDI_SOCKET_CNTX(mod_id[ind_ptr->socket_id]), ind_ptr->socket_id, event);
    }
}   /* end of HDIa_socketNotify */


/*****************************************************************************
 * FUNCTION
 *  HDI_waitDnsExpiry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_param     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_waitDnsExpiry(void *event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HDIa_socket_event_struct *event_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_ptr = (HDIa_socket_event_struct*) event_param;

    event_ptr->event_id = NULL;

    HDIc_socketHostByName(
        event_ptr->mod_id,  /* mod id */
        event_ptr->identifier,
        event_ptr->result,
        NULL,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketGetHostAddr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketGetHostAddr(local_para_struct *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_get_host_by_name_ind_struct *ind_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(local_para_ptr != NULL);

    ind_ptr = (app_soc_get_host_by_name_ind_struct*) local_para_ptr;

    if (ind_ptr->result == KAL_FALSE)
    {
        kal_uint8 idx = HDI_get_empty_event();

        if(ind_ptr->error_cause == SOC_BEARER_FAIL)
        {
            last_error =  (ind_ptr->detail_cause) ? ind_ptr->detail_cause : SOC_BEARER_FAIL;
        }
        
        HDI_SOCKET_CNTX(event[idx].mod_id) = ind_ptr->access_id;
        HDI_SOCKET_CNTX(event[idx].identifier) = ind_ptr->request_id;
        HDI_SOCKET_CNTX(event[idx].result) = HDI_SOCKET_ERROR_HOST_NOT_FOUND;
        HDI_SOCKET_CNTX(event[idx].event_id) = msf_start_timer(HDI_WAIT_CONN_TIME_WHEN_FAIL, HDI_waitDnsExpiry, (void*)&(HDI_SOCKET_CNTX(event[idx])));
        if (HDI_SOCKET_CNTX(event[idx].event_id))
        {
            return;
        }

        HDIc_socketHostByName(
            ind_ptr->access_id, /* mod id */
            ind_ptr->request_id,
            HDI_SOCKET_ERROR_HOST_NOT_FOUND,
            ind_ptr->addr,
            ind_ptr->addr_len);
        return;
    }

    HDIc_socketHostByName(
        ind_ptr->access_id, /* mod id */
        ind_ptr->request_id,
        0,                  /* succ */
        ind_ptr->addr,
        ind_ptr->addr_len);

}   /* end of HDIa_socketGetHostAddr */


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketMsgHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketMsgHdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr->msg_id == MSG_ID_APP_SOC_NOTIFY_IND)
    {
        HDIa_socketNotify(ilm_ptr->local_para_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND)
    {
        HDIa_socketGetHostAddr(ilm_ptr->local_para_ptr);
    }
    else
    {
        /* LOG ERROR */
    }   /* msgid */

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                   [IN]        
 *  socketType              [IN]        
 *  networkAccountID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketCreate(MSF_UINT8 modId, int socketType, MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;
    kal_uint8 val;  /* johnnie */
    kal_int8 socketid;
    kal_uint8 so_type = SOCKET_TYPE_FROM_HDI(socketType);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_D5362F4ABEB897D83BE0AFF5C0336739,
        "HDIa_socketCreate: modId=%d socketType=%d networkAccountID=%d\n", modId, socketType, networkAccountID));

#ifdef WAP_QUEUE_SMS_PUSH
    if (modId == MSF_MODID_STK && socketType == MSF_SOCKET_TYPE_SMS_DATA && networkAccountID == 0 &&
        sms_push_socketid != -1)
    {
        /* SMS push socket already created when task create */
        return sms_push_socketid;
    }
#endif /* WAP_QUEUE_SMS_PUSH */ 

    /* if(socketType != MSF_SOCKET_TYPE_SMS_DATA && socketType != MSF_SOCKET_TYPE_SMS_RAW)
       {
       if(HDI_SOCKET_CNTX(act_acc_id) != 0xff)
       {
       if(HDIa_networkAccountGetBearer(HDI_SOCKET_CNTX(act_acc_id)) == HDI_SOCKET_BEARER_GSM_CSD
       && HDIa_networkAccountGetBearer(networkAccountID) != HDI_SOCKET_BEARER_GSM_CSD)
       {
       return HDI_SOCKET_ERROR_RESOURCE_LIMIT;
       }
       }         
       networkAccountID = (HDI_SOCKET_CNTX(act_acc_id) == 0xff)?networkAccountID:HDI_SOCKET_CNTX(act_acc_id);
       } */

    socketid = soc_create(PF_INET, so_type, 0, MOD_WAP, networkAccountID);

    if (socketid >= 0)
    {
        /* 
         * if socket is created successfully, 
         * set this socket to non-blocking & async. 
         */
        val = KAL_TRUE;
        soc_setsockopt(socketid, SOC_NBIO, &val, sizeof(val));
        val = SOC_ACCEPT | SOC_CONNECT | SOC_CLOSE;
        soc_setsockopt(socketid, SOC_ASYNC, &val, sizeof(val));

        HDI_SOCKET_CNTX(mod_id[socketid]) = modId;
        HDI_SOCKET_CNTX(soc_type[socketid]) = socketType;
        if (socketType != MSF_SOCKET_TYPE_SMS_DATA && socketType != MSF_SOCKET_TYPE_SMS_RAW)
        {
            HDI_SOCKET_CNTX(acc_id[socketid]) = networkAccountID;
            for (i = 0; i < MAX_SOC_ACCOUNT_NUM; i++)
            {
                if (HDI_SOCKET_CNTX(wait_disc_account[i]) == networkAccountID)
                {
                    HDI_SOCKET_CNTX(wait_disc_account[i]) = SOC_INVALID_ACCOUNT_ID;
                }
            }
        }
    }

    return SOCKET_RET_CODE_TO_HDI(socketid);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketClose(int socketId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (socketId == sms_push_socketid)  /* don't close SMS socket */
    {
        return 0;
    }

    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_72CBB8CE90677A6C630855C2FEE07B87, "HDIa_socketClose: socketId=%d\n", socketId));

    HDI_SOCKET_CNTX(mod_id[socketId]) = HDI_INVALID_MODID;
    for (i = 0; i < MAX_SOC_ACCOUNT_NUM; i++)
    {
        if (HDI_SOCKET_CNTX(wait_disc_account[i]) == HDI_SOCKET_CNTX(acc_id[socketId]))
        {
            HDIa_socketDiscBearerById(HDI_SOCKET_CNTX(acc_id[socketId]));
        }
    }
    HDI_SOCKET_CNTX(acc_id[socketId]) = 0xff;

    return SOCKET_RET_CODE_TO_HDI(soc_close((kal_int8) socketId));
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketAccept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  addr            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketAccept(int socketId, msf_sockaddr_t *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 error;
    sockaddr_struct socaddr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_93364A6F683180E949C8997C75BA6573, "HDIa_socketAccept: socketId=%d\n", socketId));

    error = soc_accept((kal_int8) socketId, &socaddr);

    addr->addrLen = socaddr.addr_len;
    memcpy(addr->addr, socaddr.addr, sizeof(addr->addr));
    addr->port = socaddr.port;
    

    return SOCKET_RET_CODE_TO_HDI(error);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketBind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  addr            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketBind(int socketId, msf_sockaddr_t *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 error;
    kal_uint8 onoff = KAL_TRUE;
    kal_uint8 bearer = SOC_BEARER_ANY;
    sockaddr_struct socaddr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_6F8DD9A7E161E1BB4F87A3E0A4750D32,
        "HDIa_socketBind: socketId=%d %d.%d.%d.%d:%d\n", socketId,
                 addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3], addr->port));

#ifdef WAP_QUEUE_SMS_PUSH
    if (socketId == sms_push_socketid && addr->port == 2948 && sms_push_wait_recv != -1)
    {
        /* SMS push socket bind already bind */
        return 0;
    }
#endif /* WAP_QUEUE_SMS_PUSH */ 

    socaddr.addr_len = addr->addrLen;
    memcpy(socaddr.addr, addr->addr, addr->addrLen);
    socaddr.port = addr->port;

    soc_setsockopt((kal_int8) socketId, SOC_SILENT_LISTEN, &onoff, sizeof(onoff));
    error = soc_bind((kal_int8) socketId, &socaddr);

    if(addr->port == 2948)
    {
    	soc_setsockopt((kal_int8) socketId, SOC_LISTEN_BEARER, &bearer, sizeof(kal_uint8));
    }
    return SOCKET_RET_CODE_TO_HDI(error);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketConnect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  addr            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketConnect(int socketId, msf_sockaddr_t *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 error;
    sockaddr_struct socaddr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_B01338D83F98AF4CB797F71C8F27DA16,
        "HDIa_socketConnect: socketId=%d %d.%d.%d.%d:%d\n", socketId,
                 addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3], addr->port));

    socaddr.addr_len = addr->addrLen;
    memcpy(socaddr.addr, addr->addr, addr->addrLen);
    socaddr.port = addr->port;

    error = soc_connect((kal_int8) socketId, &socaddr);

    if (error == SOC_WOULDBLOCK)
    {
        HDI_SOCKET_CNTX(act_acc_id) = HDI_SOCKET_CNTX(acc_id[socketId]);
        return 0;   /* success */
    }
    else if (error == SOC_SUCCESS)
    {
        HDIc_socketConnectResponse(HDI_SOCKET_CNTX(mod_id[socketId]), socketId, 0 /* succ */ );
        return 0;   /* success */
    }
    else
    {
        return SOCKET_RET_CODE_TO_HDI(error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketGetName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  addr            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketGetName(int socketId, msf_sockaddr_t *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketListen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketListen(int socketId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_38DBAF5207919B68A4638A14BB5CDED9, "HDIa_socketListen: socketId=%d\n", socketId));

    error = soc_listen((kal_int8) socketId, 3);

    return SOCKET_RET_CODE_TO_HDI(error);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketRecv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  buf             [?]         [?]
 *  bufLen          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_socketRecv(int socketId, void *buf, long bufLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = soc_recv((kal_int8) socketId, (kal_uint8*) buf, bufLen, 0);

    if (error > 0)
    {
        HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_F51AFF7470E4E8FA43EA9BA637587AD7,
            "HDIa_socketRecv: socketId=%d %d bytes\n", socketId, error));

        return error;
    }

    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_8FFC9BAED6C26A654EA462EEEEA4FB41,
        "HDIa_socketRecv: socketId=%d error_code=%d\n", socketId, error));

    return SOCKET_RET_CODE_TO_HDI((kal_int8) error);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketRecvFrom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  buf             [?]         [?]
 *  bufLen          [IN]        
 *  fromAddr        [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_socketRecvFrom(int socketId, void *buf, long bufLen, msf_sockaddr_t *fromAddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error;
    sockaddr_struct sockaddr;
    sms_addr_struct *smsaddr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_QUEUE_SMS_PUSH
    extern int MSF_wapIsReady(void);

    if (!MSF_wapIsReady())
    {
        if (socketId == sms_push_socketid)
        {
            return HDI_SOCKET_ERROR_DELAYED;
        }
    }
#endif /* WAP_QUEUE_SMS_PUSH */ 

    error = soc_recvfrom((kal_int8) socketId, (kal_uint8*) buf, bufLen, 0, &sockaddr);

    if (error > 0)
    {
        if (fromAddr)
        {
            if(sockaddr.sock_type == SOCK_SMS)
            {
                ASSERT(sizeof(sms_addr_struct) == 12);
                memcpy(fromAddr->addr + sizeof(sms_addr_struct), sockaddr.addr + 2 * sizeof(sms_addr_struct), sizeof(kal_uint32));
#if MSF_CFG_PUSH_ADDRESS_OPTION == 1 /* Obtain sender address */
                smsaddr = (sms_addr_struct *)(sockaddr.addr + sizeof(sms_addr_struct));
                memcpy(fromAddr->addr, smsaddr->addr_bcd, smsaddr->addr_length);
#else /* Obtain SMSC address */
                smsaddr = (sms_addr_struct *)(sockaddr.addr);
                memcpy(fromAddr->addr, smsaddr->addr_bcd, smsaddr->addr_length);
#endif           
                fromAddr->addrLen = smsaddr->addr_length;
            }            
            else
            {
                ASSERT(sockaddr.addr_len <= sizeof(fromAddr->addr));
                fromAddr->addrLen = sockaddr.addr_len;
                memcpy(fromAddr->addr, sockaddr.addr, sockaddr.addr_len);
            }
            fromAddr->port = sockaddr.port;

            HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_72C5162E9887C1B13E48E931F56C9E6F,
                "HDIa_socketRecvFrom: socketId=%d %d bytes %d.%d.%d.%d:%d\n", socketId, error,
                fromAddr->addr[0], fromAddr->addr[1], fromAddr->addr[2], fromAddr->addr[3], fromAddr->port));
        }
        else
        {
            HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_D7DA0D1F6197F8DB79DF364EDFC13141,
                "HDIa_socketRecvFrom: socketId=%d %d bytes\n", socketId, error));
        }

        return error;
    }

    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_B0E92228B087B41E27D0B0E573CA808A,
        "HDIa_socketRecvFrom: socketId=%d error_code=%d\n", socketId, error));

    return SOCKET_RET_CODE_TO_HDI((kal_int8) error);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketSend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  data            [?]         [?]
 *  dataLen         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_socketSend(int socketId, void *data, long dataLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = soc_send((kal_int8) socketId, (kal_uint8*) data, dataLen, 0);

    if (error > 0)
    {
        HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_0B3EB9AD18D97C9B790887EF993C06EC,
            "HDIa_socketSend: socketId=%d %d bytes\n", socketId, error));

        return error;
    }

    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_7915A2634F7045B9C003717013D5E9C4,
        "HDIa_socketSend: socketId=%d error_code=%d\n", socketId, error));

    return SOCKET_RET_CODE_TO_HDI((kal_int8) error);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketSendTo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  data            [?]         [?]
 *  dataLen         [IN]        
 *  toAddr          [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_socketSendTo(int socketId, void *data, long dataLen, msf_sockaddr_t *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error;
    sockaddr_struct socaddr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    socaddr.addr_len = addr->addrLen;
    memcpy(socaddr.addr, addr->addr, addr->addrLen);
    socaddr.port = addr->port;

    error = soc_sendto((kal_int8) socketId, (kal_uint8*) data, dataLen, 0, &socaddr);

    if (error > 0)
    {
        if (addr)
        {
            HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_E8C7ABAB77E180F7D5A1A86E06A83147,
                "HDIa_socketSendTo: socketId=%d %d bytes %d.%d.%d.%d:%d\n", socketId, error,
                addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3], addr->port));
        }
        else
        {
            HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_B96C82FA48B566A588EF3412E536F8D6,
                "HDIa_socketSendTo: socketId=%d %d bytes\n", socketId, error));
        }

        return error;
    }

    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_15B26F6A3E71FB7A72308DDF2374B41F,
        "HDIa_socketSendTo: socketId=%d error_code=%d\n", socketId, error));

    return SOCKET_RET_CODE_TO_HDI((kal_int8) error);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketSelect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_socketSelect(int socketId, int eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 error;
    kal_uint8 reg_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_D691F225DDEC4F8F583571B15C9ACAD0,
        "HDIa_socketSelect: socketId=%d type=%d\n", socketId, eventType));

    if (eventType != HDI_SOCKET_EVENT_RECV && eventType != HDI_SOCKET_EVENT_SEND)
    {
        return HDI_SOCKET_ERROR_INVALID_PARAM;
    }

    if(eventType == HDI_SOCKET_EVENT_RECV && soc_ready_for_read(socketId))
    {
        HDIc_socketNotify(HDI_SOCKET_CNTX(mod_id[socketId]), socketId, HDI_SOCKET_EVENT_RECV);
    }
    
    error = soc_getsockopt((kal_uint8) socketId, SOC_ASYNC, &reg_event, sizeof(reg_event));

    if (error)
    {
        return SOCKET_RET_CODE_TO_HDI(error);
    }

    if (eventType == HDI_SOCKET_EVENT_RECV)
    {
        reg_event |= SOC_READ;
    }
    else
    {
        reg_event |= SOC_WRITE;
    }

    error = soc_setsockopt((kal_uint8) socketId, SOC_ASYNC, &reg_event, sizeof(reg_event));

    return SOCKET_RET_CODE_TO_HDI(error);
}


/*****************************************************************************
 * FUNCTION
 *  HDI_socketGetHostByName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                   [IN]        
 *  requestId               [IN]        
 *  domainName              [IN]        
 *  networkAccountID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDI_socketGetHostByName(MSF_UINT8 modId, int requestId, const char *domainName, MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret;
    kal_uint8 addr[16];
    kal_uint8 addr_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_07EA1490A7B32FF9FD6E5365FB0FD361,
        "HDI_socketGetHostByName: modId=%d requestId=%d domainName=%s nwtacc_id=%d\n", modId, requestId,
                 domainName, networkAccountID));

    /* networkAccountID = (HDI_SOCKET_CNTX(act_acc_id) == 0xff)?networkAccountID:HDI_SOCKET_CNTX(act_acc_id); */
    ret = soc_gethostbyname(KAL_FALSE, MOD_WAP, requestId, domainName, addr, &addr_len, modId, networkAccountID);

    if (ret == SOC_SUCCESS)
    {
        /* IP already in cache */
        HDIc_socketHostByName(
            modId,
            requestId,
            0,  /* success */
            addr,
            addr_len);
    }
    else if (ret != SOC_WOULDBLOCK)
    {
        /* occurred error */
        HDIc_socketHostByName(
            modId,
            requestId,
            -1, /* failed */
            addr,
            addr_len);
    }
    else
    {
        HDI_SOCKET_CNTX(act_acc_id) = networkAccountID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketGetHostByName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  requestId       [IN]        
 *  domainName      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketGetHostByName(MSF_UINT8 modId, int requestId, const char *domainName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDI_socketGetHostByName(modId, requestId, domainName, (kal_uint32) BRAif_getNetAccId());
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketGetHostByNameNId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId                   [IN]        
 *  requestId               [IN]        
 *  domainName              [IN]        
 *  networkAccountID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketGetHostByNameNId(MSF_UINT8 modId, int requestId, const char *domainName, MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDI_socketGetHostByName(modId, requestId, domainName, networkAccountID);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_socketCloseAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_socketCloseAll(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_uint8 s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDISOCKDBG_ ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_SOCKET_51E35F7CD8ECC43F8B3BEED3A09ABEC4,
        "HDIa_socketCloseAll: modId=%d\n", modId));

    for (s = 0; s < HDI_MAX_SOCKET_NUM; s++)
    {
        if (s == sms_push_socketid) /* don't close SMS socket */
        {
            continue;
        }
        if (HDI_SOCKET_CNTX(mod_id[s]) == modId)
        {
            soc_close(s);
            HDI_SOCKET_CNTX(mod_id[s]) = HDI_INVALID_MODID;
        }
    }

    for (i = 0; i < MAX_SOC_ACCOUNT_NUM; i++)
    {
        if (HDI_SOCKET_CNTX(wait_disc_account[i]) != 0xff)
        {
            HDIa_socketDiscBearerById(HDI_SOCKET_CNTX(wait_disc_account[i]));
        }
    }
}



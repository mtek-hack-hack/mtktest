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
 * soc_win32.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Socket APIs on WIN32 environment.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(WIN32) && defined(WIN_SOC) && defined(__TCPIP__)
#include <windows.h>
#include "kal_non_specific_general_types.h"
#include "stdafx.h"

#include "MMIDataType.h"

#include "CustDataRes.h"
#include "EventsGprot.h"
#include "historyGprot.h"
#include "ProtocolEvents.h"
#include "CustMenuRes.h"
#include "wgui_categories.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"

#include "TimerEvents.h"
#include "MainMenuDef.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"
#include "MMIDataType.h"
#include "CustomCfg.h"
#include "Unicodexdcl.h"
#include "audioInc.h"
#include "IdleAppDef.h"
#include "BootUp.h"
#include "GlobalDefs.h"

#include "soc_api.h"
#include "app2soc_struct.h"     /* interface with Applications */

/* Trace */

static fd_set read_fd, write_fd, except_fd;
struct timeval soc_timeout_win32;
int soc_free[MAX_SOCKET_NUM];

typedef struct
{
    int socket_id;
    int event_type;
} soc_retry_select_struct;

#define SOC_MAX_NOTIFY_RETRY 100
int soc_notify_retry_select_sum = 0;
soc_retry_select_struct soc_notify_retry_select[SOC_MAX_NOTIFY_RETRY];


/*****************************************************************************
 * FUNCTION
 *  socketSelect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int socketSelect(int socketId, kal_uint8 eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    soc_notify_retry_select[soc_notify_retry_select_sum].socket_id = socketId;
    soc_notify_retry_select[soc_notify_retry_select_sum].event_type = eventType;
    soc_notify_retry_select_sum++;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  soc_notify_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketid        [IN]        
 *  event           [IN]        
 *  result          [IN]        
 *  cause           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void soc_notify_app(int socketid, kal_uint8 event, kal_bool result, kal_int8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    app_soc_notify_ind_struct *ind_ptr;
    kal_int8 s = -1;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_SOCKET_NUM; i++)
    {
        if (soc_free[i] == socketid)
        {
            s = i;
            break;
        }
    }

    if (s == -1)
    {
        return;
    }

    ind_ptr = (app_soc_notify_ind_struct*) OslConstructDataPtr(sizeof(app_soc_notify_ind_struct));

    ind_ptr->socket_id = s;
    ind_ptr->event_type = event;
    ind_ptr->result = result;
    ind_ptr->error_cause = cause;

    Message.oslSrcId = MOD_SOC;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_APP_SOC_NOTIFY_IND;

    Message.oslDataPtr = (oslParaType*) ind_ptr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  soc_reselect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  socketId        [IN]        
 *  eventType       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int soc_reselect(int socketId, int eventType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FD_ZERO(&read_fd);
    FD_ZERO(&write_fd);
    FD_ZERO(&except_fd);

    switch (eventType)
    {
        case SOC_READ:
            FD_SET((SOCKET) socketId, &read_fd);
            FD_SET((SOCKET) socketId, &except_fd);
            select(0, &read_fd, NULL, &except_fd, &soc_timeout_win32);
            if (FD_ISSET(socketId, &read_fd))
            {
                soc_notify_app(socketId, SOC_READ, KAL_TRUE, 0);
                return 1;
            }

            break;
        case SOC_WRITE:
            FD_SET((SOCKET) socketId, &write_fd);
            FD_SET((SOCKET) socketId, &except_fd);
            select(0, NULL, &write_fd, &except_fd, &soc_timeout_win32);
            if (FD_ISSET(socketId, &write_fd))
            {
                soc_notify_app(socketId, SOC_WRITE, KAL_TRUE, 0);
                return 1;
            }
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  soc_notify_thread
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void soc_notify_thread(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    printf("here is notify thread\n");

    while (1)
    {
        if (soc_notify_retry_select_sum)
        {
            int i;

            for (i = 0; i < soc_notify_retry_select_sum; i++)
            {
                if (soc_reselect(soc_notify_retry_select[i].socket_id, soc_notify_retry_select[i].event_type))
                {
                    soc_notify_retry_select[i] = soc_notify_retry_select[soc_notify_retry_select_sum - 1];
                    soc_notify_retry_select_sum--;
                    i--;
                }
            }
        }
        Sleep(1000);
    }   /* while */
}


/*****************************************************************************
 * FUNCTION
 *  soc_init_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void soc_init_win32(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    static int is_start = 0;

    WSADATA info;
    int thread_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_start == 0)
    {
        is_start = 1;

        for (i = 0; i < MAX_SOCKET_NUM; i++)
        {
            soc_free[i] = -1;
        }

        if (WSAStartup(MAKEWORD(1, 1), &info) != 0)
        {
            MessageBox(NULL, "Cannot initialize WinSock!", "WSAStartup", MB_OK);
        }

        soc_timeout_win32.tv_usec = 50;
        soc_timeout_win32.tv_sec = 0;

        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) soc_notify_thread, 0, 0, &thread_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  soc_create_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  domain              [IN]        
 *  type                [IN]        
 *  protocol            [IN]        
 *  mod_id              [IN]        
 *  nwk_account_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_create_win32(
            kal_uint8 domain,
            kal_uint8 type,
            kal_uint8 protocol,
            kal_uint16 mod_id,
            kal_uint32 nwk_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* with initial values */
    kal_int8 s = SOC_ERROR;
    kal_int8 error = SOC_SUCCESS;

    int i;
    SOCKET id = INVALID_SOCKET;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SOCK_DGRAM:
            id = socket(AF_INET, SOCK_DGRAM, 0);
            break;
        case SOCK_STREAM:
            id = socket(AF_INET, SOCK_STREAM, 0);
            break;
        default:
            id = socket(AF_INET, SOCK_STREAM, 0);
            break;
    }

    if (INVALID_SOCKET == id)
    {
        printf("Could not create socket %d\n", WSAGetLastError());
    }

    for (i = 0; i < MAX_SOCKET_NUM; i++)
    {
        if (soc_free[i] == -1)
        {
            break;
        }
    }

    if (i < MAX_SOCKET_NUM)
    {
        soc_free[i] = id;
    }
    else
    {
        i = SOC_LIMIT_RESOURCE;
    }

    return i;

}   /* end of soc_create */


/*****************************************************************************
 * FUNCTION
 *  soc_close_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_close_win32(kal_int8 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    closesocket(soc_free[s]);
    soc_free[s] = -1;

    return SOC_SUCCESS;

}   /* end of soc_close */


/*****************************************************************************
 * FUNCTION
 *  soc_bind_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  addr        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_bind_win32(kal_int8 s, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct sockaddr_in A;
    int socketid = soc_free[s];
    char buf[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf, "%d.%d.%d.%d", addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);

    A.sin_addr.s_addr = inet_addr(buf);

    if (bind(socketid, (const struct sockaddr*)&A, sizeof(A)) == SOCKET_ERROR)
    {
        return -1;
    }

    return SOC_SUCCESS;

}   /* end of soc_bind */


/*****************************************************************************
 * FUNCTION
 *  soc_listen_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  backlog     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_listen_win32(kal_int8 s, kal_uint8 backlog)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int socketid = soc_free[s];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (listen(socketid, backlog))
    {
        return -1;
    }

    return 0;

}   /* end of soc_listen */


/*****************************************************************************
 * FUNCTION
 *  soc_convert_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  win32_addr      [?]     
 *  addr            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void soc_convert_addr(struct sockaddr_in *win32_addr, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    char *s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr->port = ntohs(win32_addr->sin_port);
    addr->addr_len = 4;

    s = inet_ntoa(win32_addr->sin_addr);

    for (i = 0; i < 4; i++)
    {
        addr->addr[i] = 0;
    }

    for (i = 0; i < 4; i++)
    {
        addr->addr[i] = (kal_uint8) atoi(s);
        s = strchr(s, '.');
        if (s == NULL)
        {
            break;
        }
        s++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  soc_accept_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  addr        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_accept_win32(kal_int8 s, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int socketid = soc_free[s];
    struct sockaddr_in their_addr;  /* connector's address information */
    int addr_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_len = sizeof(struct sockaddr);

    if (accept(socketid, (struct sockaddr*)&their_addr, &addr_len))
    {
        return -1;
    }

    soc_convert_addr(&their_addr, addr);

    return 0;

}   /* end of soc_accept */


/*****************************************************************************
 * FUNCTION
 *  soc_connect_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  addr        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_connect_win32(kal_int8 s, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buf[128];
    struct sockaddr_in A;
    int socketid = soc_free[s];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf, "%d.%d.%d.%d", addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf);

    if (connect(socketid, (const struct sockaddr*)&A, sizeof(A)) == SOCKET_ERROR)
    {
        if (WSAGetLastError() != WSAEWOULDBLOCK)
        {
            return -1;
        }

        FD_ZERO(&write_fd);
        FD_ZERO(&except_fd);

        while (KAL_TRUE)
        {
            FD_SET((SOCKET) socketid, &write_fd);
            FD_SET((SOCKET) socketid, &except_fd);

            select(0, NULL, &write_fd, &except_fd, &soc_timeout_win32);
            if (FD_ISSET(socketid, &write_fd))
            {
                return 0;
            }
            if (FD_ISSET(socketid, &except_fd))
            {
                return -1;
            }
            Sleep(200); /* Sleep for 2 milliseconds */
        }
    }
    return 0;

}   /* end of soc_connect */


/*****************************************************************************
 * FUNCTION
 *  soc_shutdown_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 *  how     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_shutdown_win32(kal_int8 s, kal_uint8 how)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SOC_ERROR;   /* NOT SUPPORT */

}   /* end of soc_shutdown */


/*****************************************************************************
 * FUNCTION
 *  soc_sendto_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  buf         [?]         
 *  len         [IN]        
 *  flags       [IN]        
 *  addr        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 soc_sendto_win32(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int send_size;
    int socketid = soc_free[s];
    struct sockaddr_in A;
    char buf_tmp[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf_tmp, "%d.%d.%d.%d", addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf_tmp);

    send_size = sendto(socketid, (void*)buf, len, 0, (const struct sockaddr*)&A, sizeof(A));
    if (send_size < 0)
    {
        int error = WSAGetLastError();

        printf("send error %d\n", error);
        return -1;
    }
    else
    {
        return send_size;
    }
}


/*****************************************************************************
 * FUNCTION
 *  soc_send_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  buf         [?]         
 *  len         [IN]        
 *  flags       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 soc_send_win32(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int send_size;
    int socketid = soc_free[s];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_size = send(socketid, (void*)buf, len, 0);
    if (send_size < 0)
    {
        int error = WSAGetLastError();

        printf("send error %d\n", error);
        return -1;
    }
    else
    {
        return send_size;
    }

}


/*****************************************************************************
 * FUNCTION
 *  soc_recvfrom_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s               [IN]        
 *  buf             [?]         
 *  len             [IN]        
 *  flags           [IN]        
 *  fromaddr        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 soc_recvfrom_win32(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *fromaddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int recv_size;
    int socketid = soc_free[s];
    struct sockaddr_in their_addr;  /* connector's address information */
    int addr_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_len = sizeof(struct sockaddr);
    recv_size = recvfrom(socketid, (void*)buf, len, 0, (struct sockaddr*)&their_addr, &addr_len);
    if (recv_size < 0)
    {
        switch (WSAGetLastError())
        {
            case WSAEWOULDBLOCK:
                socketSelect(socketid, SOC_READ);
                return SOC_WOULDBLOCK;
            case WSAEMSGSIZE:
                return SOC_MSGSIZE;

            case WSAECONNABORTED:
                printf("WSAECONNABORTED\r\n");

            default:
                printf("recv error %d\n", WSAGetLastError());
                printf("socket close\n", recv_size);
                return SOC_ERROR;
        }
    }
    else if (recv_size == 0)
    {
        return SOC_ERROR;
    }

    soc_convert_addr(&their_addr, fromaddr);

    return recv_size;
}


/*****************************************************************************
 * FUNCTION
 *  soc_recv_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  buf         [?]         
 *  len         [IN]        
 *  flags       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 soc_recv_win32(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int recv_size;
    int socketid = soc_free[s];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_size = recv(socketid, (void*)buf, len, 0);
    if (recv_size < 0)
    {
        switch (WSAGetLastError())
        {
            case WSAEWOULDBLOCK:
                socketSelect(socketid, SOC_READ);
                return SOC_WOULDBLOCK;
            case WSAEMSGSIZE:
                return SOC_MSGSIZE;

            case WSAECONNABORTED:
                printf("WSAECONNABORTED\r\n");

            default:
                printf("recv error %d\n", WSAGetLastError());
                printf("socket close\n", recv_size);
                return SOC_ERROR;
        }
    }
    else if (recv_size == 0)
    {
        return SOC_ERROR;
    }

    return recv_size;

}   /* end of soc_recv */


/*****************************************************************************
 * FUNCTION
 *  soc_select_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ndesc       [IN]        
 *  in          [?]         
 *  out         [?]         
 *  ex          [?]         
 *  tv          [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_select_win32(kal_uint8 ndesc, fd_set *in, fd_set *out, fd_set *ex, soc_timeval_struct *tv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;

}   /* end of soc_select */


/*****************************************************************************
 * FUNCTION
 *  soc_setsockopt_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s               [IN]        
 *  option          [IN]        
 *  val             [?]         
 *  val_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_setsockopt_win32(kal_int8 s, kal_uint16 option, kal_uint8 *val, kal_uint8 val_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    u_long nNonBlocking;
    int socketid = soc_free[s];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (option == SOC_NBIO)
    {
        ioctlsocket(socketid, FIONBIO, (u_long FAR*) & nNonBlocking);
    }
    else if (option == SOC_ASYNC)
    {

    }

    return 0;

}   /* end of soc_setsockopt */


/*****************************************************************************
 * FUNCTION
 *  soc_getsockopt_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s               [IN]        
 *  option          [IN]        
 *  val             [?]         
 *  val_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_getsockopt_win32(kal_int8 s, kal_uint16 option, kal_uint8 *val, kal_uint8 val_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;

}   /* end of soc_getsockopt */


/*****************************************************************************
 * FUNCTION
 *  soc_gethostbyname_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_blocking         [IN]        
 *  mod_id              [IN]        
 *  request_id          [IN]        
 *  domain_name         [IN]        
 *  addr                [?]         
 *  addr_len            [?]         
 *  access_id           [IN]        
 *  nwk_account_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_gethostbyname_win32(
            kal_bool is_blocking,
            kal_uint16 mod_id,
            kal_int32 request_id,
            const kal_char *domain_name,
            kal_uint8 *addr,
            kal_uint8 *addr_len,
            kal_uint8 access_id,
            kal_uint32 nwk_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    struct hostent *HOST;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HOST = gethostbyname(domain_name);

    if (HOST == NULL)
    {
        return SOC_ERROR;
    }
    else
    {
        int i;
        char *s;
        char *host = inet_ntoa(*(struct in_addr*)HOST->h_addr_list[0]);

        *addr_len = 4;
        for (i = 0; i < 4; i++)
        {
            addr[i] = 0;
        }

        for (i = 0, s = host; i < 4; i++)
        {
            addr[i] = (kal_uint8) atoi(s);
            s = strchr(s, '.');
            if (s == NULL)
            {
                break;
            }
            s++;
        }
        return SOC_SUCCESS;
    }

}   /* end of soc_gethostbyname */


/*****************************************************************************
 * FUNCTION
 *  soc_gethostbyaddr_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_blocking         [IN]        
 *  mod_id              [IN]        
 *  request_id          [IN]        
 *  domain_name         [?]         
 *  addr                [IN]        
 *  addr_len            [IN]        
 *  access_id           [IN]        
 *  nwk_account_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_gethostbyaddr_win32(
            kal_bool is_blocking,
            kal_uint16 mod_id,
            kal_int32 request_id,
            kal_char *domain_name,
            const kal_uint8 *addr,
            kal_uint8 addr_len,
            kal_uint8 access_id,
            kal_uint32 nwk_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return -1;  /* not support */
}


/*****************************************************************************
 * FUNCTION
 *  soc_getsockaddr_win32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s               [IN]        
 *  is_local        [IN]        
 *  addr            [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 soc_getsockaddr_win32(kal_int8 s, kal_bool is_local, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return -1;  /* not support */
}


/*****************************************************************************
 * FUNCTION
 *  soc_create
 * DESCRIPTION
 *  This function get a free socket slot from socket pool.
 * PARAMETERS
 *  domain              [IN]        
 *  type                [IN]        
 *  protocol            [IN]        
 *  mod_id              [IN]        
 *  nwk_account_id      [IN]        
 *  a(?)                [IN]        Domain
 *  d(?)                [IN]        Mod_id
 *  e(?)                [IN]        Nwk_account_id
 *  c(?)                [IN]        Protocol
 *  b(?)                [IN]        Type
 * RETURNS
 *  non-negative: sokcet id
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_create(kal_uint8 domain, kal_uint8 type, kal_uint8 protocol, kal_uint16 mod_id, kal_uint32 nwk_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_create_win32(domain, type, protocol, mod_id, nwk_account_id);

}   /* end of soc_create */


/*****************************************************************************
 * FUNCTION
 *  soc_close
 * DESCRIPTION
 *  This function free a free socket slot from socket pool and
 *  trigger ABM to close the corresponding bearer if required.
 * PARAMETERS
 *  s           [IN]        
 *  a(?)        [IN]        S, socket id
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_close(kal_int8 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_close_win32(s);

}   /* end of soc_close */


/*****************************************************************************
 * FUNCTION
 *  soc_bind
 * DESCRIPTION
 *  This function binds a local address which contain IP and port to a socket.
 * PARAMETERS
 *  s           [IN]        
 *  addr        [?]         
 *  a(?)        [IN]        S, socket id
 *  c(?)        [IN]        Namelen
 *  b(?)        [IN]        *name
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_bind(kal_int8 s, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_bind_win32(s, addr);
}   /* end of soc_bind */


/*****************************************************************************
 * FUNCTION
 *  soc_listen
 * DESCRIPTION
 *  This function makes socket to a server for waiting connections.
 * PARAMETERS
 *  s           [IN]        
 *  backlog     [IN]        
 *  a(?)        [IN]        S, socket id
 *  b(?)        [IN]        Backlog, max no. of connections
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_listen(kal_int8 s, kal_uint8 backlog)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_listen_win32(s, backlog);

}   /* end of soc_listen */


/*****************************************************************************
 * FUNCTION
 *  soc_accept
 * DESCRIPTION
 *  This function waits the incoming connections and return a socket id
 *  of new connection.
 * PARAMETERS
 *  s           [IN]            
 *  addr        [?]             
 *  a(?)        [IN]            S, socket id
 *  b(?)        [IN/OUT]        Addr, address of foreign host
 * RETURNS
 *  non-negative: socket id of new connection
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_accept(kal_int8 s, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_accept_win32(s, addr);

}   /* end of soc_accept */


/*****************************************************************************
 * FUNCTION
 *  soc_connect
 * DESCRIPTION
 *  This function connects to the server and
 *  trigger ABM to establish the corresponding bearer if the bearer is
 *  not established.
 * PARAMETERS
 *  s           [IN]            
 *  addr        [?]             
 *  a(?)        [IN]            S, socket id
 *  b(?)        [IN/OUT]        Addr, pointer of server address
 * RETURNS
 *  non-negative: socket id of new connection
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_connect(kal_int8 s, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_connect_win32(s, addr);

}   /* end of soc_connect */


/*****************************************************************************
 * FUNCTION
 *  soc_shutdown
 * DESCRIPTION
 *  This function shutdowns the connection in aspects of reading, writing
 *  or both.
 * PARAMETERS
 *  s           [IN]        
 *  how         [IN]        
 *  a(?)        [IN]        S, socket id
 *  b(?)        [IN]        How, specify shutdown read/write/both
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_shutdown(kal_int8 s, kal_uint8 how)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SOC_ERROR;   /* not support */

}   /* end of soc_shutdown */


/*****************************************************************************
 * FUNCTION
 *  soc_sendto
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  buf         [?]         
 *  len         [IN]        
 *  flags       [IN]        
 *  addr        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 soc_sendto(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_sendto_win32(s, buf, len, flags, addr);
}


/*****************************************************************************
 * FUNCTION
 *  soc_send
 * DESCRIPTION
 *  This function sends data to a host which already connected previously.
 * PARAMETERS
 *  s           [IN]        
 *  buf         [?]         
 *  len         [IN]        
 *  flags       [IN]        
 *  a(?)        [IN]        S, socket id
 *  d(?)        [IN]        Flags
 *  c(?)        [IN]        Len, data length
 *  b(?)        [IN]        *buf, hold the data
 * RETURNS
 *  non-negative: no. of bytes sent
 *  negative: fail
 *****************************************************************************/
kal_int32 soc_send(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_send_win32(s, buf, len, flags);
}


/*****************************************************************************
 * FUNCTION
 *  soc_recvfrom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s               [IN]        
 *  buf             [?]         
 *  len             [IN]        
 *  flags           [IN]        
 *  fromaddr        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 soc_recvfrom(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags, sockaddr_struct *fromaddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_recvfrom_win32(s, buf, len, flags, fromaddr);
}


/*****************************************************************************
 * FUNCTION
 *  soc_recv
 * DESCRIPTION
 *  This function receives data from a host connected previously.
 * PARAMETERS
 *  s           [IN]            
 *  buf         [?]             
 *  len         [IN]            
 *  flags       [IN]            
 *  a(?)        [IN]            S, socket id
 *  d(?)        [IN]            Flags
 *  c(?)        [IN]            Buffer length for receiving
 *  b(?)        [IN/OUT]        *buf, hold the data
 * RETURNS
 *  non-negative: no. of bytes received
 *  negative: fail
 *****************************************************************************/
kal_int32 soc_recv(kal_int8 s, kal_uint8 *buf, kal_int32 len, kal_uint8 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_recv_win32(s, buf, len, flags);
}   /* end of soc_recv */

#ifndef SOC_NOT_SUPPORT_SELECT


/*****************************************************************************
 * FUNCTION
 *  soc_select
 * DESCRIPTION
 *  This function receives data from a host connected previously.
 * PARAMETERS
 *  ndesc       [IN]            
 *  in          [?]             
 *  out         [?]             
 *  ex          [?]             
 *  tv          [?]             
 *  a(?)        [IN]            Ndesc, no. of descriptors
 *  d(?)        [IN/OUT]        *ex, exception fd_set
 *  e(?)        [IN]            *tv, specify the timeout value
 *  c(?)        [IN/OUT]        *out, output fd_set
 *  b(?)        [IN/OUT]        *in, input fd_set
 * RETURNS
 *  non-negative: no. of socket be set
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_select(kal_uint8 ndesc, fd_set *in, fd_set *out, fd_set *ex, soc_timeval_struct *tv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SOC_ERROR;   /* not support */
}                       /* end of soc_select */

#endif /* SOC_NOT_SUPPORT_SELECT */ 


/*****************************************************************************
 * FUNCTION
 *  soc_setsockopt
 * DESCRIPTION
 *  This function sets the socket options.
 * PARAMETERS
 *  s               [IN]        
 *  option          [IN]        
 *  val             [?]         
 *  val_size        [IN]        
 *  a(?)            [IN]        S, socket id
 *  d(?)            [IN]        Val_size
 *  c(?)            [IN]        *val
 *  b(?)            [IN]        Option
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_setsockopt(kal_int8 s, kal_uint16 option, kal_uint8 *val, kal_uint8 val_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_setsockopt_win32(s, option, val, val_size);
}   /* end of soc_setsockopt */


/*****************************************************************************
 * FUNCTION
 *  soc_getsockopt
 * DESCRIPTION
 *  This function gets the socket options.
 * PARAMETERS
 *  s               [IN]        
 *  option          [IN]        
 *  val             [?]         
 *  val_size        [IN]        
 *  a(?)            [IN]        S, socket id
 *  d(?)            [IN]        Val_size
 *  c(?)            [IN]        *val
 *  b(?)            [IN]        Option
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_getsockopt(kal_int8 s, kal_uint16 option, kal_uint8 *val, kal_uint8 val_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_getsockopt_win32(s, option, val, val_size);

}   /* end of soc_getsockopt */


/*****************************************************************************
 * FUNCTION
 *  soc_gethostbyname
 * DESCRIPTION
 *  This function gets the IP of the given domain name.
 * PARAMETERS
 *  is_blocking         [IN]            
 *  mod_id              [IN]            
 *  request_id          [IN]            
 *  domain_name         [IN]            
 *  addr                [?]             
 *  addr_len            [?]             
 *  access_id           [IN]            
 *  nwk_account_id      [IN]            
 *  a(?)                [IN]            Is_blocking, indicate whether block or non-block mode are used, currently only non-block mode support
 *  d(?)                [IN]            Domain_name
 *  h(?)                [IN]            Nwk_account_id
 *  g(?)                [IN]            Access_id, embedded in response message
 *  f(?)                [IN/OUT]        Addr_len
 *  e(?)                [IN/OUT]        Addr
 *  c(?)                [IN]            Request_id, embedded in response message
 *  b(?)                [IN]            Mod_id
 * RETURNS
 *  SOC_SUCCESS: success, return ip address in 'addr'
 *  negative: fail excpet for
 *  SOC_WOULDBLOCK is for waiting DNS reply from network
 *****************************************************************************/
kal_int8 soc_gethostbyname(
            kal_bool is_blocking,
            kal_uint16 mod_id,
            kal_int32 request_id,
            const kal_char *domain_name,
            kal_uint8 *addr,
            kal_uint8 *addr_len,
            kal_uint8 access_id,
            kal_uint32 nwk_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_gethostbyname_win32(
            is_blocking,
            mod_id,
            request_id,
            domain_name,
            addr,
            addr_len,
            access_id,
            nwk_account_id);

}   /* end of soc_gethostbyname */


/*****************************************************************************
 * FUNCTION
 *  soc_gethostbyaddr
 * DESCRIPTION
 *  This function gets the domain name of the given IP.
 * PARAMETERS
 *  is_blocking         [IN]            
 *  mod_id              [IN]            
 *  request_id          [IN]            
 *  domain_name         [?]             
 *  addr                [IN]            
 *  addr_len            [IN]            
 *  access_id           [IN]            
 *  nwk_account_id      [IN]            
 *  a(?)                [IN]            Is_blocking, indicate whether block or non-block mode are used, currently only non-block mode support
 *  d(?)                [IN/OUT]        Domain_name
 *  h(?)                [IN]            Nwk_account_id
 *  g(?)                [IN]            Access_id, embedded in response message
 *  f(?)                [IN]            Addr_len, must be 4.
 *  e(?)                [IN]            Addr
 *  c(?)                [IN]            Request_id, embedded in response message
 *  b(?)                [IN]            Mod_id
 * RETURNS
 *  SOC_SUCCESS: success, return domain name in 'domain_name' which
 *  terminated by null character
 *  negative: fail excpet for
 *  SOC_WOULDBLOCK is for waiting DNS reply from network
 *****************************************************************************/
kal_int8 soc_gethostbyaddr(
            kal_bool is_blocking,
            kal_uint16 mod_id,
            kal_int32 request_id,
            kal_char *domain_name,
            const kal_uint8 *addr,
            kal_uint8 addr_len,
            kal_uint8 access_id,
            kal_uint32 nwk_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_gethostbyaddr_win32(
            is_blocking,
            mod_id,
            request_id,
            domain_name,
            addr,
            addr_len,
            access_id,
            nwk_account_id);

}   /* end of soc_gethostbyaddr */


/*****************************************************************************
 * FUNCTION
 *  soc_close_nwk_account
 * DESCRIPTION
 *  This function closes the network account opened by that module.
 *  If the corresponding account is closed, socket will send a
 *  MSG_ID_APP_SOC_DEACTIVATE_CNF to application.
 * PARAMETERS
 *  mod_id      [IN]        
 *  a(?)        [IN]        Mod_id
 * RETURNS
 *  void
 *****************************************************************************/
void soc_close_nwk_account(kal_uint16 mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return; /* NOT SUPPORT */

}   /* end of soc_close_nwk_account */


/*****************************************************************************
 * FUNCTION
 *  soc_getlocalip
 * DESCRIPTION
 *  This function returns the local IP address.
 * PARAMETERS
 *  local_ip        [?]             
 *  a(?)            [IN/OUT]        *local_ip, copy the IP address, used as return
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: bearer is not activated, no IP address info
 *****************************************************************************/
kal_int8 soc_getlocalip(kal_uint8 *local_ip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SOC_ERROR;   /* not support */

}   /* end of soc_getlocalip */


/*****************************************************************************
 * FUNCTION
 *  soc_getsockaddr
 * DESCRIPTION
 *  This function returns the remote or local address assoicated
 *  with given socket.
 * PARAMETERS
 *  s               [IN]            
 *  is_local        [IN]            
 *  addr            [?]             
 *  a(?)            [IN]            S, socket id
 *  c(?)            [IN/OUT]        *addr, copy the address, used as return
 *  b(?)            [IN]            Is_local, true: local
 * RETURNS
 *  SOC_SUCCESS: success
 *  negative: fail
 *****************************************************************************/
kal_int8 soc_getsockaddr(kal_int8 s, kal_bool is_local, sockaddr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_getsockaddr_win32(s, is_local, addr);

}   /* end of soc_getsockaddr */


/*****************************************************************************
 * FUNCTION
 *  soc_get_last_error
 * DESCRIPTION
 *  This function is used to get the last network error.
 *  A successful function call, or a call to soc_get_last_error,
 *  does not reset the error cause.
 * PARAMETERS
 *  s                   [IN]            
 *  error               [?]             Cause
 *  detail_cause        [?]             
 *  a(?)                [IN]            S, socket id
 *  c(?)                [IN/OUT]        *detail_cause, minor error cause
 *  b(?)                [IN/OUT]        *error, major error cause
 * RETURNS
 *  SOC_SUCCESS: success
 *  SOC_INVALID_SOCKET: invalid socket id
 *****************************************************************************/
kal_int8 soc_get_last_error(kal_int8 s, kal_int8 *error, kal_int32 *detail_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SOC_ERROR;   /* NOT SUPPORT */

}   /* end of soc_get_last_error */


/*****************************************************************************
 * FUNCTION
 *  soc_set_last_error
 * DESCRIPTION
 *  This function is used to set the last network error.
 * PARAMETERS
 *  s                   [IN]        
 *  error               [IN]        
 *  detail_cause        [IN]        
 *  a(?)                [IN]        S, socket id
 *  c(?)                [IN]        Detail_cause, minor error cause
 *  b(?)                [IN]        Error, major error cause
 * RETURNS
 *  SOC_SUCCESS: success
 *  SOC_INVALID_SOCKET: invalid socket id
 *****************************************************************************/
kal_int8 soc_set_last_error(kal_int8 s, kal_int8 error, kal_int32 detail_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SOC_ERROR;   /* NOT SUPPORT */

}   /* end of soc_set_last_error */

#endif /* defined(WIN32) && defined(WIN_SOC) && defined(__TCPIP__) */ 


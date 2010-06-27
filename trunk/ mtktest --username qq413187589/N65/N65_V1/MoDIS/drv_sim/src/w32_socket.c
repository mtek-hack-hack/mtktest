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
 * w32_socket.c
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define SOC_SUPPORT_INFO_IN_ACCT     1
#ifdef SOC_SUPPORT_INFO_IN_ACCT
#ifdef __CBM_ALWAYS_ASK_FEATURE__
#define SOC_SUPPORT_ALWAYS_ASK  1
#endif
#ifdef __GEMINI__
#define SOC_SUPPORT_DUAL_SIM    1
#endif
#endif

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"    /* local/peer struct */

#include "soc_api.h"
#include "app2soc_struct.h"   /* interface with Applications */
#include "abm_soc_enums.h"
#include "soc2mmi_struct.h"
#include "mmi2soc_struct.h"

#include "ConnectManageGprot.h"
#include <ctype.h>
#include <stdio.h>

#define _W32_SOCKET_C_

/* if you want to print dbg info in console, pls turn on SOC_DBG_ENABLE */
//#define SOC_DBG_ENABLE
#define SOC_MAX_APP_NWK_NUM  50
#define SOC_SMS_ID -2

typedef enum
{
    W32_BEARER_CLOSED         = 0,
    W32_BEARER_OPENED         = 1
} bearer_state_enum;

typedef struct
{
    kal_uint32                  options;
    kal_uint16                  tv_sec; /* unit: seconds */
    kal_uint16                  tv_usec; /*unit: micro seconds */
} soc_app_option_struct;

typedef struct
{
    int mod_id;
#ifdef SOC_SUPPORT_INFO_IN_ACCT
    int app_id;
#endif
#ifdef SOC_SUPPORT_ALWAYS_ASK
    kal_bool is_always_ask_sent;
#endif
    int nwk_account_id;
    int no_so; 
    soc_app_option_struct app_options;
    bearer_state_enum state;
} soc_app_nwk_state_struct;

static fd_set read_fd, write_fd, except_fd;
static struct timeval soc_timeout_win32;

int soc_free[MAX_SOCKET_NUM];    /* storing socket id */
int soc_state[MAX_SOCKET_NUM];   /* state of each socket */

static int soc_modid[MAX_SOCKET_NUM];   /* storing module id */
#ifdef SOC_SUPPORT_INFO_IN_ACCT
static int soc_appid[MAX_SOCKET_NUM];
#endif
#ifdef SOC_SUPPORT_DUAL_SIM
static always_ask_sim_info_enum soc_sim_src[MAX_SOCKET_NUM];
#endif
#ifdef SOC_SUPPORT_ALWAYS_ASK
static kal_bool soc_always_ask[MAX_SOCKET_NUM];
sockaddr_struct soc_peer_addr[MAX_SOCKET_NUM];
#endif /* SOC_SUPPORT_ALWAYS_ASK */
static int soc_account_id[MAX_SOCKET_NUM]; /* storing network account id */

static int soc_events[MAX_SOCKET_NUM];
static int soc_want_events[MAX_SOCKET_NUM];
static soc_app_nwk_state_struct soc_app_nwk[SOC_MAX_APP_NWK_NUM];
static int created_socket_num = 0;      /* total created sockets */
static int soc_polling_timer_running = 0;
static kal_semid soc_lock;

#define SOC_LOCK          kal_take_sem(soc_lock, KAL_INFINITE_WAIT)
#define SOC_UNLOCK        kal_give_sem(soc_lock)

typedef enum
{
    W32_SOC_S_NOUSE         = 0,
    W32_SOC_S_INUSE         = 0x0001,
    W32_SOC_S_CONNECTING    = 0x0200,   /* in process of connecting to peer */
    W32_SOC_S_CONNECTED     = 0x0400,   /* socket connected to a peer */
    W32_SOC_S_SENDING       = 0x0800,
    W32_SOC_S_RECVING       = 0x1000,
    W32_SOC_S_FINED         = 0x00200000,     /* received TCP FIN from peer */
} soc_state_enum;


static unsigned char state_str[][16] = {
    "ACTIVATING",
    "ACTIVATED",
    "DEACTIVATED",
    "DEACTIVATING",
    "UNKNOWN"
};

static unsigned char event_str[][16] = {
    "1 READ",
    "2 WRITE",
    "4 ACCEPT",
    "8 CONNECT",
    "16 CLOSE",
    "UNKNOWN"
};

static unsigned char winsock_errstr[][32] = {
    "0 WSABASEERR",            /* No Error */
    "10004 WSAEINTR",          /* Interrupted system call */
    "10009 WSAEBADF",          /* Bad file number */
    "10013 WSAEACCES",         /* Permission denied */
    "10014 WSAEFAULT",         /* Bad address */
    "10022 WSAEINVAL",         /* Invalid argument */
    "10024 WSAEMFILE",         /* Too many open files */
    "10035 WSAEWOULDBLOCK",    /* Operation would block */
    "10036 WSAEINPROGRESS",    /* Operation now in progress */
    "10037 WSAEALREADY",       /* Operation already in progress */
    "10038 WSAENOTSOCK",       /* Socket operation on non-socket */
    "10039 WSAEDESTADDRREQ",   /* Destination address required */
    "10040 WSAEMSGSIZE",       /* Message too long */
    "10041 WSAEPROTOTYPE",     /* Protocol wrong type for socket */
    "10042 WSAENOPROTOOPT",    /* Bad protocol option */
    "10043 WSAEPROTONOSUPPORT",/* Protocol not supported */
    "10044 WSAESOCKTNOSUPPORT",/* Socket type not supported */
    "10045 WSAEOPNOTSUPP",     /* Operation not supported on socket */
    "10046 WSAEPFNOSUPPORT",   /* Protocol family not supported */
    "10047 WSAEAFNOSUPPORT",   /* Address family not supported by protocol family */
    "10048 WSAEADDRINUSE",     /* Address already in use */
    "10049 WSAEADDRNOTAVAIL",  /* Can't assign requested address */
    "10050 WSAENETDOWN",       /* Network is down */
    "10051 WSAENETUNREACH",    /* Network is unreachable */
    "10052 WSAENETRESET",      /* Net dropped connection or reset */
    "10053 WSAECONNABORTED",   /* Software caused connection abort */
    "10054 WSAECONNRESET",     /* Connection reset by peer */
    "10055 WSAENOBUFS",        /* No buffer space available */
    "10056 WSAEISCONN",        /* Socket is already connected */
    "10057 WSAENOTCONN",       /* Socket is not connected */
    "10058 WSAESHUTDOWN",      /* Can't send after socket shutdown */
    "10059 WSAETOOMANYREFS",   /*  Too many references, can't splice */
    "10060 WSAETIMEDOUT",      /*  Connection timed out */
    "10061 WSAECONNREFUSED",   /*  Connection refused */
    "10062 WSAELOOP",          /*  Too many levels of symbolic links */
    "10063 WSAENAMETOOLONG",   /*  File name too long */
    "10064 WSAEHOSTDOWN",      /*  Host is down */
    "10065 WSAEHOSTUNREACH",   /*  No Route to Host */
    "10066 WSAENOTEMPTY",      /*  Directory not empty */
    "10067 WSAEPROCLIM",       /*  Too many processes */
    "10068 WSAEUSERS",         /*  Too many users */
    "10069 WSAEDQUOT",         /*  Disc Quota Exceeded */
    "10070 WSAESTALE",         /*  Stale NFS file handle */
    "10091 WSASYSNOTREADY",    /*  Network SubSystem is unavailable */
    "10092 WSAVERNOTSUPPORTED",/*  WINSOCK DLL Version out of range */
    "10093 WSANOTINITIALISED", /*  Successful WSASTARTUP not yet performed */
    "10071 WSAEREMOTE",        /*  Too many levels of remote in path */
    "11001 WSAHOST_NOT_FOUND", /*  Host not found  */
    "11002 WSATRY_AGAIN",      /*  Non-Authoritative Host not found */
    "11003 WSANO_RECOVERY",    /*  Non-Recoverable errors: FORMERR, REFUSED, NOTIMP */
    "11004 WSANO_DATA",        /* Valid name, no data record of requested type */
    "11004 WSANO_ADDRESS"      /* No address, look for MX record */
};


static kal_int8 socgetlocalip(kal_uint8 *local_ip);
static unsigned char *err_str(int error);

static
void soc_dump_hex(unsigned char *buf, int len)
{
    int i, pos;

    for (pos = 0; pos < len; pos += 16)
    {
        kal_printf("%06d  ", pos);
        for (i = 0; i < 16; i++)
            if (pos + i < len)
                kal_printf("%02x%s", buf[pos+i], (i+1)%8 ? " " : "  ");
            else
                kal_printf("  %s", (i+1)%8 ? " " : "  ");

        kal_printf("  ");

        for (i = 0; i < 16 && pos+i < len; i++)
            kal_printf("%c%s", isprint(buf[pos+i]) ? buf[pos+i] : '.',
                               (i+1)%8 ? "" : " ");
        kal_printf("\n");
    }
}


static
int soc_find_soc_app_slot(int mod_id, 
                #ifdef SOC_SUPPORT_INFO_IN_ACCT
                          int app_id,
                #endif
                          int nwk_account_id, 
                          int *idx)
{
    int i;
    ASSERT(idx);
    for (i = 0 ; i < SOC_MAX_APP_NWK_NUM ; i++)
    {
    #ifdef SOC_SUPPORT_INFO_IN_ACCT
        if (((app_id != 0 && soc_app_nwk[i].app_id == app_id) ||
             (app_id == 0 && soc_app_nwk[i].mod_id == mod_id &&
              soc_app_nwk[i].app_id == app_id)) &&
            ((nwk_account_id == 0xff && soc_app_nwk[i].nwk_account_id != -1) ||
              soc_app_nwk[i].nwk_account_id == nwk_account_id))
    #else /* SOC_SUPPORT_INFO_IN_ACCT */
        if (soc_app_nwk[i].mod_id == mod_id &&
            ((nwk_account_id == 0xff && soc_app_nwk[i].nwk_account_id != -1) ||
             soc_app_nwk[i].nwk_account_id == nwk_account_id))
    #endif /* SOC_SUPPORT_INFO_IN_ACCT */
        {
            *idx = i;
            return 1;
        }
    }
    return 0;
}


static
int soc_find_free_soc_app_slot(int *idx)
{
    int found;

    ASSERT(idx);
    found = soc_find_soc_app_slot(-1,
                        #ifdef SOC_SUPPORT_INFO_IN_ACCT
                                  -1,
                        #endif
                                  -1, 
                                  idx);
    ASSERT(found == 1);

    return found;
}


static
void soc_free_soc_app_slot(int idx)
{
    ASSERT(idx >= 0 && idx < SOC_MAX_APP_NWK_NUM);

    soc_app_nwk[idx].mod_id = -1;
#ifdef SOC_SUPPORT_INFO_IN_ACCT
    soc_app_nwk[idx].app_id = -1;
#endif
#ifdef SOC_SUPPORT_ALWAYS_ASK
    soc_app_nwk[idx].is_always_ask_sent = KAL_FALSE;
#endif
    soc_app_nwk[idx].no_so = 0;
    soc_app_nwk[idx].app_options.options = 0;
    soc_app_nwk[idx].app_options.tv_sec = 0;
    soc_app_nwk[idx].app_options.tv_usec = 0;
    soc_app_nwk[idx].nwk_account_id = -1;
    soc_app_nwk[idx].state = W32_BEARER_CLOSED;
}


static
void soc_deactivate_cnf_to_app(kal_bool result, 
                               module_type mod_id,
                               kal_uint32 account_id)
{
    app_soc_deactivate_cnf_struct *cnf;
#ifdef SOC_SUPPORT_INFO_IN_ACCT
        kal_uint8 app_id;
#endif


    cnf = (app_soc_deactivate_cnf_struct*)
          construct_local_para(sizeof(app_soc_deactivate_cnf_struct),
                TD_CTRL);

#ifdef SOC_SUPPORT_INFO_IN_ACCT
    always_ask_decode_data_account_id(account_id, NULL, &app_id, 
                                      NULL, NULL);
    cnf->ap_id = app_id;
#endif /* SOC_SUPPORT_INFO_IN_ACCT */

    cnf->account_id = account_id;
    cnf->result = result;
    cnf->recv_bytes = 0;
    cnf->sent_bytes = 0;
    cnf->conn_time  = 0;

    soc_send_msg_to_app(mod_id,
                        MSG_ID_APP_SOC_DEACTIVATE_CNF,
                        (local_para_struct*)cnf,
                        NULL);
}


static
void soc_bearer_info_to_app(int mod_id,
                            int account_id,
                            soc_auto_disc_state_enum state,
                            soc_error_enum error)
{
    kal_uint8 bearer;
    kal_uint8 ip_addr[4];
    app_soc_bearer_info_ind_struct *ind_ptr;
    kal_uint8 soc_bearer = SOC_CSD;
#ifdef SOC_SUPPORT_INFO_IN_ACCT
    kal_uint8 app_id;
    kal_uint32 ori_account_id;
#endif /* SOC_SUPPORT_INFO_IN_ACCT */

    if (mod_id == MOD_SOC) /* Don't send bearer_info to SOC itself */
        return;

#ifdef SOC_SUPPORT_INFO_IN_ACCT
    always_ask_decode_data_account_id(account_id, NULL, &app_id, 
                                      NULL, &ori_account_id);
#endif

    bearer = soc_abm_get_bearer(ori_account_id);
    socgetlocalip(ip_addr);

    ind_ptr = (app_soc_bearer_info_ind_struct*)
        construct_local_para(sizeof(app_soc_bearer_info_ind_struct),
                             TD_CTRL);

    ind_ptr->state = (kal_uint8)state;

    if (bearer == ABM_E_SOCKET_BEARER_GSM_CSD)
        soc_bearer = SOC_CSD;
    else if (bearer == ABM_E_SOCKET_BEARER_GSM_GPRS)
        soc_bearer = SOC_GPRS;

#ifdef SOC_SUPPORT_INFO_IN_ACCT
    ind_ptr->ap_id = app_id;
#endif
    ind_ptr->account_id = account_id;
    ind_ptr->bearer = soc_bearer;
    ind_ptr->error = error;
    ind_ptr->error_cause = 0;

    if (state == SOC_ACTIVATED)
        kal_mem_cpy(ind_ptr->ip_addr, ip_addr, 4);
    else
        kal_mem_set(ind_ptr->ip_addr, 0, 4);

    ind_ptr->sent_bytes = 0;
    ind_ptr->recv_bytes = 0;
    ind_ptr->conn_time  = 0;

#ifdef SOC_DBG_ENABLE
    kal_printf("bearer_info account_id=%d state=%s\n",
               account_id, state_str[state]);
#endif /* SOC_DBG_ENABLE */

    soc_send_msg_to_app((kal_uint16)mod_id,
                        MSG_ID_APP_SOC_BEARER_INFO_IND,
                        (local_para_struct*)ind_ptr,
                        NULL);
}


static
kal_int8 soc_activate_account(int s)
{
    int id;
    int account_id;


    if (soc_find_soc_app_slot(soc_modid[s], 
                #ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
                #endif
                              soc_account_id[s], 
                              &id) == 0)
    {
        if (soc_find_free_soc_app_slot(&id))
        {
            soc_app_nwk[id].mod_id = soc_modid[s];
            #ifdef SOC_SUPPORT_INFO_IN_ACCT
            soc_app_nwk[id].app_id = soc_appid[s];
            #endif
            soc_app_nwk[id].nwk_account_id = soc_account_id[s];
            soc_app_nwk[id].state = W32_BEARER_CLOSED;
        }
    }
    
    ASSERT(soc_app_nwk[id].state == W32_BEARER_CLOSED ||
           soc_app_nwk[id].state == W32_BEARER_OPENED);

#ifdef SOC_SUPPORT_ALWAYS_ASK
    if (soc_always_ask[s])
    {
        if (!soc_app_nwk[id].is_always_ask_sent)
        {
            /* send account request to CBM to ask account */
        #ifdef SOC_SUPPORT_DUAL_SIM
            soc_send_ask_acct_req_to_mmi(MOD_SOC,
                                         soc_app_nwk[id].app_id,
                                         soc_app_nwk[id].mod_id,
                                         soc_sim_src[s],
                                         SOC_DEFAULT_ASK_ACCT_STATUS);  
        #else /* SOC_SUPPORT_DUAL_SIM */
            soc_send_ask_acct_req_to_mmi(MOD_SOC,
                                         soc_app_nwk[id].app_id,
                                         soc_app_nwk[id].mod_id,
                                         0,
                                         SOC_DEFAULT_ASK_ACCT_STATUS);
        #endif /* SOC_SUPPORT_DUAL_SIM */
            soc_app_nwk[id].is_always_ask_sent = KAL_TRUE;
        }
        
        return SOC_WOULDBLOCK;
    }
#endif /* SOC_SUPPORT_ALWAYS_ASK */
   
    if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
    {
    #ifdef SOC_SUPPORT_INFO_IN_ACCT
        account_id = always_ask_encode_app_id_data_account_id(
                            soc_account_id[s], soc_appid[s]);
    #else
        account_id = soc_account_id[s];
    #endif
        soc_bearer_info_to_app(soc_modid[s],
                               account_id, 
                               SOC_ACTIVATING,
                               0);
        soc_bearer_info_to_app(soc_modid[s],
                               account_id, 
                               SOC_ACTIVATED,
                               0);   
        
        soc_app_nwk[id].state = W32_BEARER_OPENED;
    }

    return SOC_SUCCESS;
}


static
void soc_notify_app(int socketid,
                    soc_event_enum event,
                    kal_bool result,
                    kal_int8 cause)
{
    app_soc_notify_ind_struct *ind_ptr;
    kal_int8 s = -1;
    kal_uint8 i;
#ifdef SOC_DBG_ENABLE
    unsigned char *ev;
#endif

    for (i = 0; i < MAX_SOCKET_NUM; i++)
    {
        if (soc_free[i] == socketid)
        {
            s = i;
            break;
        }
    }

    if (s == -1)
        return;

    ind_ptr = (app_soc_notify_ind_struct*)
        construct_local_para(sizeof(app_soc_notify_ind_struct),
                             TD_CTRL);

    ind_ptr->socket_id   = s;
    ind_ptr->event_type  = event;
    ind_ptr->result      = result;
    ind_ptr->error_cause = cause;

    if (event == SOC_CONNECT)
    {
        soc_state[s] &= ~W32_SOC_S_CONNECTING;
        if (result == KAL_TRUE)
            soc_state[s] |= W32_SOC_S_CONNECTED;
    }

    if (event == SOC_READ)
    {
        soc_state[s] &= ~W32_SOC_S_RECVING;
    }

    if (event == SOC_WRITE)
    {
        soc_state[s] &= ~W32_SOC_S_SENDING;
    }

#ifdef SOC_DBG_ENABLE
    for (i = 0; i < sizeof(event_str) / sizeof(event_str[0]); i++)
        if (atoi(event_str[i]) == event)
        {
            ev = strchr(event_str[i], ' ') + 1;
            break;
        }
    if (i == sizeof(event_str) / sizeof(event_str[0]))
        ev = event_str[i-1];
    kal_printf("notify socket=%d event=%s\n", s, ev);
#endif /* SOC_DBG_ENABLE */

    soc_send_msg_to_app(soc_modid[s],
                        MSG_ID_APP_SOC_NOTIFY_IND,
                        (local_para_struct*)ind_ptr,
                        NULL);
}


static
int soc_reselect(int socket_id, int wantEventType, int *eventType)
{
    int rt;
    int ret = 0;  //reset
    int i = 0;
    int max_fd = 0;

    FD_ZERO(&read_fd);
    FD_ZERO(&write_fd);
    FD_ZERO(&except_fd);

    if ((wantEventType & SOC_READ) && (*eventType & SOC_READ))
        FD_SET((SOCKET)socket_id, &read_fd);

    if ((wantEventType & SOC_ACCEPT) && (*eventType & SOC_ACCEPT))
        FD_SET((SOCKET)socket_id, &read_fd);

    if ((wantEventType & SOC_CONNECT) && (*eventType & SOC_CONNECT))
        FD_SET((SOCKET)socket_id, &write_fd);

    if ((wantEventType & SOC_WRITE) && (*eventType & SOC_WRITE))
        FD_SET((SOCKET)socket_id, &write_fd);

    if ((wantEventType & SOC_CLOSE) && (*eventType & SOC_CLOSE))
        FD_SET((SOCKET)socket_id, &read_fd);


    for (i = 0; i < sizeof(read_fd.fd_array) / sizeof(read_fd.fd_array[0]); i++)
        max_fd = max_fd < read_fd.fd_array[i] ? read_fd.fd_array[i] : max_fd;
    
    for (i = 0; i < sizeof(write_fd.fd_array) / sizeof(write_fd.fd_array[0]); i++)
        max_fd = max_fd < write_fd.fd_array[i] ? write_fd.fd_array[i] : max_fd;
    
    for (i = 0; i < sizeof(except_fd.fd_array) / sizeof(except_fd.fd_array[0]); i++)
        max_fd = max_fd < except_fd.fd_array[i] ? except_fd.fd_array[i] : max_fd;
        
    max_fd += 1;

    if (max_fd > 1)
        rt = select(max_fd, &read_fd, &write_fd, &except_fd, &soc_timeout_win32);
    else
        return 0;

    if (rt == SOCKET_ERROR) /* error */
    {
    #ifdef SOC_DBG_ENABLE
        int error = WSAGetLastError();
        kal_printf("select error: %s (%d)\n", err_str(error), error);
    #endif /* SOC_DBG_ENABLE */
    }
    else if (0 < rt)    /* success, rt = the number of descriptors */
    {
        if (FD_ISSET(socket_id, &read_fd))
        {
            if (*eventType & SOC_READ)
            {
                soc_notify_app(socket_id, SOC_READ, KAL_TRUE, 0);
                *eventType &= ~SOC_READ;
                ret++;
            }
            else if (*eventType & SOC_ACCEPT)
            {
                soc_notify_app(socket_id, SOC_ACCEPT, KAL_TRUE, 0);
                *eventType &= ~SOC_ACCEPT;
                ret++;
            }
            else if (*eventType & SOC_CLOSE)
            {
                soc_notify_app(socket_id, SOC_READ, KAL_TRUE, 0);
                *eventType &= ~SOC_CLOSE;
                ret++;
            }
        }

        if (FD_ISSET(socket_id, &write_fd))
        {
            if (*eventType & SOC_CONNECT)
            {
                soc_notify_app(socket_id, SOC_CONNECT, KAL_TRUE, 0);
                *eventType &= ~SOC_CONNECT;
                ret++;
            }
            else if (*eventType & SOC_WRITE)
            {
                soc_notify_app(socket_id, SOC_WRITE, KAL_TRUE, 0);
                *eventType &= ~SOC_WRITE;
                ret++;
            }
        }
    }

    return ret;
}


void soc_notify_thread(void)
{
    int i;

    int batch   = 0;
    int wait_wb = 0;

    if (created_socket_num <= 0 || soc_polling_timer_running == 1)
        return;

    for (i = 0 ; i < MAX_SOCKET_NUM ; i++)
    {
        if (soc_free[i] >= 0 && soc_want_events[i] && soc_events[i] > 0)
        {
            batch += soc_reselect(soc_free[i],
                                  soc_want_events[i],
                                  &soc_events[i]);

            if (batch == 10)
            {
                /* do not send too many IND to application at the same time,
                 * otherwise, application's queue may be full */
                kal_sleep_task(KAL_TICKS_100_MSEC);
                batch = 0;
            }
            wait_wb++;
        }
    }

    /* start a polling timer */
    if (wait_wb > 0)
    {
        soc_start_timer(0 /* dummy timer_id */,
                        0 /* dummy invoke_id */,
                        0 /* dummy sub_id */,
                        KAL_TICKS_100_MSEC * 2);
        soc_polling_timer_running = 1;
    }
}

/*
 * Called by soc_expiry_hanlder() at the condition of
 * !defined(__MTK_TARGET__) || defined(WIN_SOC)
 */
void soc_polling_timer_expiry(void)
{
    SOC_LOCK;

    ASSERT(soc_polling_timer_running == 1);
    soc_polling_timer_running = 0;
    soc_notify_thread();

    SOC_UNLOCK;
}


void soc_init_win32(void)
{
    int i;
    WSADATA info;

    soc_lock = kal_create_sem ("soc lock", 1);

    for (i = 0 ; i < MAX_SOCKET_NUM ; i++)
    {
        soc_free[i]        = -1;
        soc_modid[i]       = -1;
  #ifdef SOC_SUPPORT_INFO_IN_ACCT
        soc_appid[i]       = -1;
  #endif
  #ifdef SOC_SUPPORT_DUAL_SIM
        soc_sim_src[i] = 0;
  #endif
  #ifdef SOC_SUPPORT_ALWAYS_ASK
        soc_always_ask[i]   = KAL_FALSE;
  #endif
        soc_account_id[i]  = -1;
        soc_events[i]      = 0;
        soc_want_events[i] = 0;
    }

    for (i = 0 ; i < SOC_MAX_APP_NWK_NUM ; i++)
    {
        soc_app_nwk[i].mod_id         = -1;
    #ifdef SOC_SUPPORT_INFO_IN_ACCT
        soc_app_nwk[i].app_id         = -1;
    #endif
    #ifdef SOC_SUPPORT_ALWAYS_ASK
        soc_app_nwk[i].is_always_ask_sent = KAL_FALSE;
    #endif
        soc_app_nwk[i].app_options.options = 0;
        soc_app_nwk[i].app_options.tv_sec = 0;
        soc_app_nwk[i].app_options.tv_usec = 0;
        soc_app_nwk[i].nwk_account_id = -1;
        soc_app_nwk[i].no_so = 0;
        soc_app_nwk[i].state          = W32_BEARER_CLOSED;
    }

    if (WSAStartup(MAKEWORD(1,1), &info) != 0)
    {
        MessageBox(NULL, "Cannot initialize WinSock!", "WSAStartup", MB_OK);
    }
    else /* initiate WinSock successfully, start periodic timer */
    {
        soc_timeout_win32.tv_sec = 0;
        soc_timeout_win32.tv_usec = 50; /* wait for 50 usec */

        kal_printf("socket simulation activated\n");
    }
}

void soc_hostname_ind(kal_bool result,
                 module_type mod_id,
                 kal_int32 request_id,
                 kal_uint8 access_id,
                 kal_uint8 *ip_addr,
                 kal_uint8 addr_len,
                 kal_int8 error_cause,
                 kal_int32 detail_cause)
{
    app_soc_get_host_by_name_ind_struct *ind_ptr;
  
    ind_ptr = (app_soc_get_host_by_name_ind_struct*)
               construct_local_para(sizeof(app_soc_get_host_by_name_ind_struct),
               TD_CTRL | TD_RESET);
    ind_ptr->result = result;

    if (result == KAL_TRUE)
    {
        ind_ptr->num_entry = addr_len/4;
        kal_mem_cpy(ind_ptr->entry, ip_addr, addr_len);
    }
    else    /* fail */
    {
        ind_ptr->num_entry = 0;
        kal_mem_set(ind_ptr->entry, 0, sizeof(ind_ptr->entry));
    }
    
    kal_mem_cpy(ind_ptr->addr, ip_addr, addr_len);
    ind_ptr->addr_len = addr_len;

    ind_ptr->request_id = request_id;
    ind_ptr->access_id = access_id;
    ind_ptr->error_cause = error_cause;
    ind_ptr->detail_cause = detail_cause;

    soc_send_msg_to_app(mod_id,
                        MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND,
                        (local_para_struct*)ind_ptr,
                        NULL);
 
}


void soc_convert_addr(struct sockaddr_in *win32_addr,
                      sockaddr_struct *addr)
{
    addr->port = ntohs(win32_addr->sin_port);
    addr->addr_len = 4;

    memset(addr->addr, 0, sizeof(addr->addr));
    memcpy(addr->addr, &win32_addr->sin_addr, 4);
}


kal_int8 soc_create(kal_uint8  domain,
                    socket_type_enum  type,
                    kal_uint8  protocol,
                    module_type mod_id,
                    kal_uint32 nwk_account_id)
{
#ifdef SOC_SUPPORT_DUAL_SIM
    always_ask_sim_info_enum sim_src;
#endif
#ifdef SOC_SUPPORT_INFO_IN_ACCT
    kal_uint8 ap_id;
    kal_bool always_ask = KAL_FALSE;
#endif /* SOC_SUPPORT_INFO_IN_ACCT */
    int idx;
    int i;
    
    /* with initial values */
    kal_int8 s = SOC_ERROR;
    kal_int8 error = SOC_SUCCESS;
    SOCKET id = INVALID_SOCKET;

    

    SOC_LOCK;

#if defined(SOC_SUPPORT_DUAL_SIM)
    /* decode network account */
    always_ask_decode_data_account_id(nwk_account_id, &sim_src, &ap_id, 
                               &always_ask, &nwk_account_id);
    nwk_account_id = always_ask_encode_data_account_id(nwk_account_id, sim_src, 0, 0);
#elif defined(SOC_SUPPORT_INFO_IN_ACCT)
    /* decode network account */
    always_ask_decode_data_account_id(nwk_account_id, NULL, &ap_id, 
                               &always_ask, &nwk_account_id);
#endif
    switch (type)
    {
    case SOCK_DGRAM:
        id = socket(AF_INET, SOCK_DGRAM, 0);
        break;

    case SOCK_STREAM:
        id = socket(AF_INET, SOCK_STREAM, 0);
        break;

    case SOCK_SMS:
        id = SOC_SMS_ID;
        nwk_account_id = 0xff;
        break;

    default:
        id = socket(AF_INET, SOCK_STREAM, 0);
        break;
    }

    if (id == INVALID_SOCKET)
    {
    #ifdef SOC_DBG_ENABLE
        int err = WSAGetLastError();
        kal_printf("socket create error: %s (%d)\n", err_str(err), err);
    #endif /* SOC_DBG_ENABLE */
        SOC_UNLOCK;
        return -1;
    }

    /* Find the first slot with soc_free[i] equals -1(unused) */
    for (i = 0; i < MAX_SOCKET_NUM; i++)
    {
        if (soc_free[i] == -1)
            break;
    }

    if (i < MAX_SOCKET_NUM)
    {
        /* found free slot */
       

        soc_free[i] = id;
        soc_modid[i] = mod_id;
    #ifdef SOC_SUPPORT_INFO_IN_ACCT
        soc_appid[i] = (int)ap_id;
    #endif

    #ifdef SOC_SUPPORT_DUAL_SIM
        soc_sim_src[i] = sim_src;
    #endif
    
    #ifdef SOC_SUPPORT_ALWAYS_ASK    
        if (always_ask)
        {
            nwk_account_id = 0xff;
            
        }
    #endif /* SOC_SUPPORT_ALWAYS_ASK */        
       
        if (soc_find_soc_app_slot(mod_id,
        #ifdef SOC_SUPPORT_INFO_IN_ACCT
            (int)ap_id,
        #endif
            nwk_account_id, 
            &idx) == 0)
        {
            if (soc_find_free_soc_app_slot(&idx))
            {
                soc_app_nwk[idx].mod_id = mod_id;
            #ifdef SOC_SUPPORT_INFO_IN_ACCT
                soc_app_nwk[idx].app_id = (int)ap_id;
            #endif
                soc_app_nwk[idx].nwk_account_id = nwk_account_id;
                soc_app_nwk[idx].state = W32_BEARER_CLOSED;
            }
        }

        soc_account_id[i] = soc_app_nwk[idx].nwk_account_id;
        
    #ifdef SOC_SUPPORT_ALWAYS_ASK
        if (always_ask)
        {
            if (soc_account_id[i] != 0xff)
            {
                soc_always_ask[i] = KAL_FALSE;
            }
            else
            {
                soc_always_ask[i] = KAL_TRUE;
            }
        }
    #endif /* SOC_SUPPORT_ALWAYS_ASK */
           
        soc_app_nwk[idx].no_so++;
        created_socket_num++;
        ASSERT(created_socket_num <= MAX_SOCKET_NUM);
    }
    else
    {
        /* All MAX_SOCKET_NUM socket slots are occupied */
        i = SOC_LIMIT_RESOURCE;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("return socket id = %d, (win32 socket id = %d)\n", i, id);
#endif /* SOC_DBG_ENABLE */

    soc_state[i] = W32_SOC_S_INUSE;
    soc_events[i] |= SOC_READ;

    SOC_UNLOCK;

    return i;
}


kal_int8 soc_close(kal_int8 s)
{
    int i;
    int opt_idx;
    int ap_soc_no = 0;
    int options;
    int account_id;


    if (s < 0 || MAX_SOCKET_NUM <= s)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] < 0 && soc_free[s] != SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_free[s] != SOC_SMS_ID)
        closesocket(soc_free[s]);

    if (soc_find_soc_app_slot(soc_modid[s],
#ifdef SOC_SUPPORT_INFO_IN_ACCT
            (int)soc_appid[s],
#endif
            -1, 
            &opt_idx))
    {
        if (soc_app_nwk[opt_idx].app_options.options & SOC_AUTO_DEACT_BEARER)
        {
            for (i = 0 ; i < SOC_MAX_APP_NWK_NUM ; i++)
            {
            #ifdef SOC_SUPPORT_INFO_IN_ACCT
                if (((soc_appid[s] != 0 && soc_app_nwk[i].app_id == soc_appid[s]) ||
                    (soc_appid[s] == 0 && soc_app_nwk[i].mod_id == soc_modid[s] &&
                     soc_app_nwk[i].app_id == soc_appid[s])) &&
                    (soc_app_nwk[i].nwk_account_id != -1))
            #else /* SOC_SUPPORT_INFO_IN_ACCT */
                if (soc_app_nwk[i].mod_id == soc_modid[s] &&
                    soc_app_nwk[i].nwk_account_id != -1)
            #endif /* SOC_SUPPORT_INFO_IN_ACCT */
                {
                    ap_soc_no += soc_app_nwk[i].no_so;
                }
            }
            
            if (ap_soc_no <= 1)
            {
                
                #ifdef SOC_SUPPORT_INFO_IN_ACCT
                account_id = always_ask_encode_data_account_id(0xff, 
                                                        0, 
                                                       (kal_uint8)soc_appid[s], 
                                                        KAL_FALSE);  
                #else /* SOC_SUPPORT_INFO_IN_ACCT */
                account_id = 0xff;
                #endif /* SOC_SUPPORT_INFO_IN_ACCT */
                soc_close_nwk_account_by_id(soc_modid[s] , account_id);
            }
        
        }
    }


    if (soc_find_soc_app_slot(soc_modid[s],
    #ifdef SOC_SUPPORT_INFO_IN_ACCT
       (int)soc_appid[s],
    #endif
        soc_account_id[s], 
        &opt_idx))
    {
        soc_app_nwk[opt_idx].no_so--;
    }
            
    soc_free[s] = -1;
    soc_state[s] = W32_SOC_S_NOUSE;

    ASSERT(created_socket_num > 0);

    created_socket_num--;

    SOC_UNLOCK;

    return SOC_SUCCESS;
}


kal_int8 soc_bind(kal_int8 s, sockaddr_struct *addr)
{
    struct sockaddr_in A;
    int socketid;
    char buf[128];
    int last_error;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return 0;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (addr->addr_len == 0)
    {
        memset(addr->addr, 0, MAX_SOCK_ADDR_LEN);
    }

    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf,"%d.%d.%d.%d",
            addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf);

#ifdef SOC_DBG_ENABLE
    kal_printf("Socket %d bind %s:%d\n", s, buf, addr->port);
#endif /* SOC_DBG_ENABLE */

    if (bind(socketid, (const struct sockaddr*)&A, sizeof(A)) == SOCKET_ERROR)
    {
        last_error = WSAGetLastError();
        SOC_UNLOCK;
        if (last_error == WSAEADDRINUSE)
            return SOC_ADDRINUSE;
        else
            return -1;
    }

    SOC_UNLOCK;

    return SOC_SUCCESS;
}


kal_int8 soc_listen(kal_int8 s, kal_uint8 backlog)
{
    int socketid;
    int id;
    kal_bool is_non_auto_set = KAL_FALSE;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid < 0)
    {
        SOC_UNLOCK;
       
        if(socketid == SOC_SMS_ID)
            return SOC_OPNOTSUPP;
        else
            return SOC_INVALID_SOCKET;
    }

#ifdef SOC_SUPPORT_ALWAYS_ASK
    if (soc_always_ask[s])
    {
         SOC_UNLOCK;
         return SOC_OPNOTSUPP;
    }
#endif /* SOC_SUPPORT_ALWAYS_ASK */
    
    if (listen(socketid, backlog))
    {
        SOC_UNLOCK;
        return -1;
    }

    soc_events[s] |= SOC_ACCEPT;

    if (soc_find_soc_app_slot(soc_modid[s], 
#ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
#endif
                              -1, 
                              &id))
    {
        if (soc_app_nwk[id].app_options.options & SOC_NON_AUTO_ACT_BEARER)
        {
            is_non_auto_set = KAL_TRUE;
        }
        
    }

    if (!is_non_auto_set)
    {
        soc_activate_account(s);
    }
    
    SOC_UNLOCK;

    return 0;
}


kal_int8 soc_accept(kal_int8 s, sockaddr_struct *addr)
{
    int socketid, i, opt_idx;
    SOCKET newid;

    struct sockaddr_in their_addr; /* connector's address information */
    int addr_len;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    addr_len = sizeof(struct sockaddr);

    newid = accept(socketid, (struct sockaddr *)&their_addr, &addr_len);
    if (newid == INVALID_SOCKET)
    {
        int last_error = WSAGetLastError();

        soc_events[s] |= SOC_ACCEPT;

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("accept(%d) error: %s (%d)\n",
                       s, err_str(last_error), last_error);
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return -1;
        }

        soc_notify_thread();

        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }

    soc_events[s] |= SOC_ACCEPT;

    soc_convert_addr(&their_addr, addr);


    for (i = 0; i < MAX_SOCKET_NUM; i++)
    {
        if (soc_free[i] == -1)
            break;
    }

    if (i < MAX_SOCKET_NUM)
    {
        soc_free[i] = newid;
        soc_modid[i] = soc_modid[s];
    #ifdef SOC_SUPPORT_INFO_IN_ACCT
        soc_appid[i] = soc_appid[s];
    #endif
    #ifdef SOC_SUPPORT_ALWAYS_ASK
        soc_sim_src[i] = soc_sim_src[s];
    #endif
        soc_account_id[i] = soc_account_id[s];
    
        if (soc_find_soc_app_slot(soc_modid[s],
            #ifdef SOC_SUPPORT_INFO_IN_ACCT
            (int)soc_appid[s],
            #endif
            soc_account_id[s], 
            &opt_idx))
        {
            soc_app_nwk[opt_idx].no_so++;
        }
        created_socket_num++;
        ASSERT(created_socket_num <= MAX_SOCKET_NUM);
    }
    else
    {
        closesocket(newid);
        SOC_UNLOCK;
        return SOC_LIMIT_RESOURCE;
    }

    SOC_UNLOCK;
    return (kal_int8)i;
}


kal_int8 sooconnect(kal_int8 s, sockaddr_struct *addr)
{
    char buf[128];
    struct sockaddr_in A;
    int socketid;
    kal_int8 ret;
    int id;
    kal_bool is_non_auto_set = KAL_FALSE;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    if (soc_state[s] & (W32_SOC_S_CONNECTING | W32_SOC_S_CONNECTED))
        return SOC_ALREADY;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        return SOC_OPNOTSUPP;
    }

    if (socketid < 0)
    {
        return SOC_INVALID_SOCKET;
    }

    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf,"%d.%d.%d.%d",
            addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf);

#ifdef SOC_DBG_ENABLE
    kal_printf("Socket %d connect to %s:%d\n", s, buf, addr->port);
#endif /* SOC_DBG_ENABLE */

    if (soc_find_soc_app_slot(soc_modid[s], 
                #ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
                #endif
                              -1, 
                              &id))
    {
        if (soc_app_nwk[id].app_options.options & SOC_NON_AUTO_ACT_BEARER)
        {
            if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
            {
                return SOC_OPNOTSUPP;
            }

            soc_state[s] |= W32_SOC_S_CONNECTING;
            is_non_auto_set = KAL_TRUE;
        }
    }
    

    if (!is_non_auto_set)
    {
        soc_state[s] |= W32_SOC_S_CONNECTING;
    #ifdef SOC_SUPPORT_ALWAYS_ASK
        memcpy(&soc_peer_addr[s], addr, sizeof(sockaddr_struct));
    #endif
            
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            return SOC_WOULDBLOCK;
        }
    }
                     
    if (connect(socketid, (const struct sockaddr*)&A, sizeof(A)) == SOCKET_ERROR)
    {
        int last_error = WSAGetLastError();

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("connect(%d) error: %s (%d)\n",
                       s, err_str(last_error), last_error);
        #endif /* SOC_DBG_ENABLE */
            soc_state[s] &= ~W32_SOC_S_CONNECTING;
            return -1;
        }

        soc_events[s] |= SOC_CONNECT;

        soc_notify_thread();
        
        return SOC_WOULDBLOCK;
    }

    soc_state[s] &= ~W32_SOC_S_CONNECTING;
    soc_state[s] |= W32_SOC_S_CONNECTED;

    return 0;
}


kal_int8 soc_connect(kal_int8 s, sockaddr_struct *addr)
{
    kal_int8 ret;
    
    SOC_LOCK;

    ret = sooconnect(s, addr);
        
    SOC_UNLOCK;

    return ret;
}


kal_int8 soc_shutdown(kal_int8 s, kal_uint8 how)
{
    return shutdown(soc_free[s], how);
}


kal_int32 soc_sendto(kal_int8 s,
                     kal_uint8 *buf,
                     kal_int32 len,
                     kal_uint8 flags,
                     sockaddr_struct *addr)
{
    int send_size;
    int socketid;
    struct sockaddr_in A;
    char buf_tmp[128];
    kal_int8 ret;
    int id;
    kal_bool is_non_auto_set = KAL_FALSE;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_OPNOTSUPP;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_find_soc_app_slot(soc_modid[s], 
#ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
#endif
                              -1, 
                              &id))
    {
        if (soc_app_nwk[id].app_options.options & SOC_NON_AUTO_ACT_BEARER)
        {
            if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
            {
                SOC_UNLOCK;
                return SOC_OPNOTSUPP;
            }

            soc_state[s] |= W32_SOC_S_SENDING;
            is_non_auto_set = KAL_TRUE;
        }
    }

    if (!is_non_auto_set)
    {
        soc_state[s] |= W32_SOC_S_SENDING;
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }
                  
    A.sin_family = AF_INET;
    A.sin_port = htons(addr->port);

    sprintf(buf_tmp, "%d.%d.%d.%d",
            addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
    A.sin_addr.s_addr = inet_addr(buf_tmp);

    send_size = sendto(socketid, (void*)buf, len, 0,
                       (const struct sockaddr*)&A, sizeof(A));
    if (send_size < 0)
    {
        int last_error = WSAGetLastError();

        if (last_error == WSAEWOULDBLOCK)
        {
            soc_events[s] |= SOC_WRITE;
        #ifdef SOC_DBG_ENABLE
            kal_printf("sendto(%d) wouldblock, event: %x\n", s, soc_events[s]);
        #endif /* SOC_DBG_ENABLE */
            soc_notify_thread();
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;        
        }

    #ifdef SOC_DBG_ENABLE
        kal_printf("send error %d\n", last_error);
    #endif /* SOC_DBG_ENABLE */

        soc_state[s] &= ~W32_SOC_S_SENDING;
        SOC_UNLOCK;
        return -1;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("Send to: %d.%d.%d.%d port=%d %d bytes\n", 
               addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3],
               addr->port, send_size);
    soc_dump_hex(buf, send_size);
#endif /* SOC_DBG_ENABLE */

    soc_state[s] &= ~W32_SOC_S_SENDING;
    SOC_UNLOCK;

    return send_size;
}


kal_int32 soc_send(kal_int8 s,
                   kal_uint8 *buf,
                   kal_int32 len,
                   kal_uint8 flags)
{
    int send_size;
    int socketid;
    kal_int8 ret;
    int id;
    kal_bool is_non_auto_set = KAL_FALSE;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_OPNOTSUPP;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_find_soc_app_slot(soc_modid[s], 
#ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
#endif
                              -1, 
                              &id))
    {
        if (soc_app_nwk[id].app_options.options & SOC_NON_AUTO_ACT_BEARER)
        {
            if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
            {
                SOC_UNLOCK;
                return SOC_OPNOTSUPP;
            }

            soc_state[s] |= W32_SOC_S_SENDING;
            is_non_auto_set = KAL_TRUE;
        }
    }

    if (!is_non_auto_set)
    {
        soc_state[s] |= W32_SOC_S_SENDING;
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }

    send_size = send(socketid, (void*)buf, len, 0);
    if (send_size <0)
    {
        int last_error = WSAGetLastError();

        if (last_error == WSAEWOULDBLOCK)
        {
            soc_events[s] |= SOC_WRITE;
        #ifdef SOC_DBG_ENABLE
            kal_printf("send(%d) wouldblock, event: %x\n", s, soc_events[s]);
        #endif /* SOC_DBG_ENABLE */
            soc_notify_thread();
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;        
        }

    #ifdef SOC_DBG_ENABLE
        kal_printf("send error %d\n", last_error);
    #endif /* SOC_DBG_ENABLE */

        soc_state[s] &= ~W32_SOC_S_SENDING;
        SOC_UNLOCK;
        return -1;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("Send: %d bytes\n", send_size);
    soc_dump_hex(buf, send_size);
#endif /* SOC_DBG_ENABLE */

    soc_state[s] &= ~W32_SOC_S_SENDING;
    SOC_UNLOCK;

    return send_size;
}


kal_int32 soc_recvfrom(kal_int8 s,
                       kal_uint8 *buf,
                       kal_int32 len,
                       kal_uint8 flags,
                       sockaddr_struct *fromaddr)
{
    int recv_size;
    int socketid;
    struct sockaddr_in their_addr; /* connector's address information */
    int addr_len;
    int error;
    int opt_val;
    int opt_len = sizeof(int);
    kal_int8 ret;
    int id;
    kal_bool is_non_auto_set = KAL_FALSE;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

     if (getsockopt(socketid, 
           SOL_SOCKET, 
           SO_TYPE, 
           (char*)&opt_val, 
           &opt_len) == SOCKET_ERROR)        
    {
        SOC_UNLOCK;
        return SOC_ERROR;
           
    }

    if (soc_find_soc_app_slot(soc_modid[s], 
#ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
#endif
                              -1, 
                              &id))
    {
        if (soc_app_nwk[id].app_options.options & SOC_NON_AUTO_ACT_BEARER)
        {
            if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
            {
                SOC_UNLOCK;
                return SOC_OPNOTSUPP;
            }

            soc_state[s] |= W32_SOC_S_RECVING;
            is_non_auto_set = KAL_TRUE;
        }
    }

    if (!is_non_auto_set)
    {
        soc_state[s] |= W32_SOC_S_RECVING;
            
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }
    
    addr_len = sizeof(struct sockaddr);
    recv_size = recvfrom(socketid, (void*)buf, len, 0,
                         (struct sockaddr *)&their_addr, &addr_len);
    if (recv_size < 0)
    {
        error = WSAGetLastError();
        switch (error)
        {
        case WSAEWOULDBLOCK:
            soc_events[s] |= SOC_READ;
        #ifdef SOC_DBG_ENABLE
            kal_printf("recvfrom(%d) wouldblock, evnent %x\n", s, soc_events[s]);
        #endif /* SOC_DBG_ENABLE */
            soc_notify_thread();
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;

        case WSAEMSGSIZE:
            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_MSGSIZE;

        case WSAECONNABORTED:
        #ifdef SOC_DBG_ENABLE
            kal_printf("WSAECONNABORTED\r\n");
        #endif /* SOC_DBG_ENABLE */
            /* fall through */

        default:
        #ifdef SOC_DBG_ENABLE
            kal_printf("recvfrom(%d) returns error %d\n", s, recv_size);
            kal_printf("recvfrom(%d) error %s (%d)\n", s, err_str(error), error);
        #endif /* SOC_DBG_ENABLE */

            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_ERROR;
        }
    }
    else if (recv_size == 0)
    {
        /* found if there is available function to obtain the socket type (TCP or UDP)*/
        /* Only TCP need the len == 0 */
        /* added by Leona */
        if(opt_val == SOCK_STREAM)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("socket %d closed by peer\n", s);
        #endif /* SOC_DBG_ENABLE */
            if (!(soc_state[s] & W32_SOC_S_FINED))  /* notify once */
            {
                soc_state[s] |= W32_SOC_S_FINED;
                soc_notify_app(socketid, SOC_CLOSE, KAL_FALSE, SOC_CONNRESET);
            }
        }
       
        soc_state[s] &= ~W32_SOC_S_RECVING;
        SOC_UNLOCK;
        return 0;
    }

    /* For UDP sockets, recvfrom() returns 0 indicating that
     * the received datagram contains data of length 0.
     */
#ifdef SOC_DBG_ENABLE
    kal_printf("Recv: %d bytes\n", recv_size);
    soc_dump_hex(buf, recv_size);
#endif /* SOC_DBG_ENABLE */

    /*  Windows recvfrom API didn't return address for TCP. Find another API to get the address*/
   if(fromaddr)
    {
        memset(fromaddr, 0, sizeof(sockaddr_struct));
        if(opt_val == SOCK_STREAM)
        {
            addr_len = sizeof(struct sockaddr);
            error = getpeername(socketid,(struct sockaddr *)&their_addr, &addr_len);
            if(error < 0)
            {
                SOC_UNLOCK;
                return SOC_ERROR;
            }

            fromaddr->sock_type = SOCK_STREAM;      
        }
        else
        {
            fromaddr->sock_type = SOCK_DGRAM;
        }
        
        soc_convert_addr(&their_addr, fromaddr);
        
    }

    soc_events[s] |= SOC_READ;

    soc_state[s] &= ~W32_SOC_S_RECVING;
    SOC_UNLOCK;

    return recv_size;
}


kal_int32 soc_recv(kal_int8 s,
                   kal_uint8 *buf,
                   kal_int32 len,
                   kal_uint8 flags)
{
    int recv_size;
    int socketid;
    int error;
    kal_int8 ret;
    int id;
    kal_bool is_non_auto_set = KAL_FALSE;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return SOC_WOULDBLOCK;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    {
        static int a = 0;

        if (a)
        {
            soc_send_msg_to_app(soc_modid[s],
                                MSG_ID_MMI_EMAIL_ABORT_REQ,
                                NULL,
                                NULL);
               
            SOC_UNLOCK;
            return -2;
        }
    }

     if (soc_find_soc_app_slot(soc_modid[s], 
#ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
#endif
                              -1, 
                              &id))
    {
        if (soc_app_nwk[id].app_options.options & SOC_NON_AUTO_ACT_BEARER)
        {
            if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
            {
                SOC_UNLOCK;
                return SOC_OPNOTSUPP;
            }

            soc_state[s] |= W32_SOC_S_RECVING;
            is_non_auto_set = KAL_TRUE;
        }
    }

    if (!is_non_auto_set)
    {
        soc_state[s] |= W32_SOC_S_RECVING;
            
        ret = soc_activate_account(s);
        if (ret == SOC_WOULDBLOCK)
        {
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;
        }
    }
 
    recv_size = recv(socketid, (void*)buf, len, 0);
    if (recv_size < 0)
    {
        error = WSAGetLastError();
        switch (error)
        {
        case WSAEWOULDBLOCK:
        #ifdef SOC_DBG_ENABLE
            kal_printf("recv(%d) wouldblock\n", s);
        #endif /* SOC_DBG_ENABLE */
            soc_events[s] |= SOC_READ;
            soc_notify_thread();
            SOC_UNLOCK;
            return SOC_WOULDBLOCK;

        case WSAEMSGSIZE:
            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_MSGSIZE;

        case WSAECONNABORTED:
        #ifdef SOC_DBG_ENABLE
            kal_printf("WSAECONNABORTED\r\n");
        #endif /* SOC_DBG_ENABLE */
            /* fall through */

        default:
        #ifdef SOC_DBG_ENABLE
            kal_printf("recv(%d) returns error %d\n", s, recv_size);
            kal_printf("recv(%d) error %s (%d)\n", s, err_str(error), error);
        #endif /* SOC_DBG_ENABLE */
            soc_state[s] &= ~W32_SOC_S_RECVING;
            SOC_UNLOCK;
            return SOC_ERROR;
        }
    }
    else if (recv_size == 0)
    {
    #ifdef SOC_DBG_ENABLE
        kal_printf("socket %d closed by peer\n", s);
    #endif /* SOC_DBG_ENABLE */
        if (!(soc_state[s] & W32_SOC_S_FINED))  /* notify once */
        {
            soc_state[s] |= W32_SOC_S_FINED;
            soc_notify_app(socketid, SOC_CLOSE, KAL_FALSE, SOC_CONNRESET);
        }

        soc_state[s] &= ~W32_SOC_S_RECVING;
        SOC_UNLOCK;
        return 0;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("Recv: %d bytes\n", recv_size);
    soc_dump_hex(buf, recv_size);
#endif /* SOC_DBG_ENABLE */

    soc_events[s] |= SOC_READ;

    soc_state[s] &= ~W32_SOC_S_RECVING;
    SOC_UNLOCK;

    return recv_size;
}


kal_int8 soc_select(kal_uint8 ndesc,
                    fd_set *in,
                    fd_set *out,
                    fd_set *ex,
                    soc_timeval_struct *tv)
{
    int rt;
    int max_ndesc = -1;
    int i;

    struct timeval to_val, *to_val_ptr = NULL;

    SOC_LOCK;

    if (tv)
    {
        to_val.tv_sec = tv->tv_sec;
        to_val.tv_usec = tv->tv_usec;
        to_val_ptr = &to_val;
    }

    /* ndesc is the largest socket id in the SET plus one,
     *               i =   0,  1,  2,  3,  4,  5,  6
     * say, soc_free[] = {34, 27, -1, 14, 21, -1, -1};
     * the app wants to select the socket 1, 3, and 4, it will call
     * FD_SET(1, &readfds);
     * FD_SET(3, &readfds);
     * FD_SET(4, &readfds);
     * select(4+1, &readfds, NULL, NULL, &tv);
     *
     * To this adaptation layer, we have to
     * 1. translate FD_SET(1, &readfds); to
     *              FD_SET(soc_free[1], &readfds);
     *    translate FD_SET(3, &readfds); to
     *              FD_SET(soc_free[3], &readfds);
     *    translate FD_SET(4, &readfds); to
     *              FD_SET(soc_free[4], &readfds);
     * 2. try to get the real ndesc, which is given as (4+1) = 5.
     *    loop over the soc_free[], from 0 to (5-1) to find the max socket id.
     *    e.g., max(37, 27, -1, 24, 21) = 37, the real ndesc is (37+1) = 38.
     */

    for (i = 0; i < ndesc; i++)
        max_ndesc = soc_free[i] > max_ndesc ? soc_free[i] : max_ndesc;
    max_ndesc += 1;
    
    rt = select((int)max_ndesc, in, out, ex, to_val_ptr);

    if (rt < 0)
    {
    #ifdef SOC_DBG_ENABLE
        int error = WSAGetLastError();
        kal_printf("select() error %s (%d)\n", err_str(error), error);
    #endif /* SOC_DBG_ENABLE */
        SOC_UNLOCK;
        return -1;
    }

#ifdef SOC_DBG_ENABLE
    kal_printf("select return: %d\n", rt);
#endif /* SOC_DBG_ENABLE */
            
    SOC_UNLOCK;
    return (kal_int8)rt;
}

kal_int8 soc_getappopt(module_type mod_id, kal_uint8 app_id, 
                       kal_uint32 option, void *val, kal_uint8 val_size)
{
    return 0;
}

kal_int8 soc_setappopt(module_type mod_id, kal_uint8 app_id, 
                       kal_uint32 option, void *val, kal_uint8 val_size)
{
    kal_int8 error = SOC_SUCCESS;
    soc_app_bearer_deact_struct *deact_time;
    int idx;

    if (soc_find_soc_app_slot(mod_id,
#ifdef SOC_SUPPORT_INFO_IN_ACCT
        (int)app_id,
#endif
       -1, 
        &idx) == 0)
    {
        if (soc_find_free_soc_app_slot(&idx))
        {
            soc_app_nwk[idx].mod_id = mod_id;
        #ifdef SOC_SUPPORT_INFO_IN_ACCT
            soc_app_nwk[idx].app_id = (int)app_id;
        #endif
            soc_app_nwk[idx].nwk_account_id = -1;
            soc_app_nwk[idx].state = W32_BEARER_CLOSED;
        }
    }
      
    
    if (option == SOC_NON_AUTO_ACT_BEARER)
    {
        if (val == NULL || val_size != sizeof(kal_uint8) || 
        ((*(kal_uint8 *)val != KAL_TRUE) && (*(kal_uint8 *)val != KAL_FALSE)))
        {
            error = SOC_INVAL;
            return error;
        }

        if (*(kal_uint8 *)val == KAL_TRUE)
            soc_app_nwk[idx].app_options.options |= option;
        else
            soc_app_nwk[idx].app_options.options &= ~option;
    }
    else if(option == SOC_AUTO_DEACT_BEARER)
    {
        if (val == NULL || val_size != sizeof(soc_app_bearer_deact_struct))
        {
            error = SOC_INVAL;
            return error;
        }

        deact_time = (soc_app_bearer_deact_struct *) val;

        if (deact_time->onoff == KAL_TRUE)
        {
            soc_app_nwk[idx].app_options.options |= option;
            soc_app_nwk[idx].app_options.tv_sec = deact_time->time.tv_sec;
            soc_app_nwk[idx].app_options.tv_usec = deact_time->time.tv_usec;  
                    
        }
        else /* linger_ptr->onoff == KAL_FALSE */
        {
            soc_app_nwk[idx].app_options.options &= ~option;
            soc_app_nwk[idx].app_options.tv_sec = 0;
            soc_app_nwk[idx].app_options.tv_usec = 0;  
        }
    }
   
    return error;
}

kal_int8 soc_setsockopt(kal_int8 s,
                        kal_uint32 option,
                        void *val,
                        kal_uint8 val_size)
{
    u_long non_blocking;
    int socketid;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return 0;
    }

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (option == SOC_NBIO)
    {
        if (val == NULL || val_size != sizeof(kal_uint8) || 
            ((*(kal_uint8 *)val != KAL_TRUE) && (*(kal_uint8 *)val != KAL_FALSE)))
        {
            SOC_UNLOCK;
            return SOC_INVAL;
        }
       
        non_blocking = (u_long)(*(kal_uint8 *)val);
        
        ioctlsocket(socketid, FIONBIO, (u_long FAR*)&non_blocking);
    }
    else if (option == SOC_ASYNC)
    {
        if (val == NULL || val_size != sizeof(kal_uint8))
        {
           SOC_UNLOCK;
           return SOC_INVAL;
        }
        soc_want_events[s] = (int)(*(kal_uint8 *)val);
    }
    else
    {
        /* do nothing */
    }

    SOC_UNLOCK;

    return 0;
}


kal_int8 soc_getsockopt(kal_int8 s,
                        kal_uint32 option,
                        void *val,
                        kal_uint8 val_size)
{
    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] == SOC_SMS_ID)
    {
        SOC_UNLOCK;
        return 0;
    }

    if (soc_free[s] < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (option == SOC_NBIO)
    {
        /* do nothing */
    }
    else if (option == SOC_ASYNC)
    {
        *(kal_uint8*)val = (kal_uint8)soc_want_events[s];
    }
    else
    {
        /* do nothing */
    }

    SOC_UNLOCK;

    return 0;
}


kal_int8 socgethostbyname(kal_bool is_blocking,
                          module_type mod_id,
                          kal_int32 request_id,
                          const kal_char *domain_name,
                          kal_uint8 *addr,
                          kal_uint8 *addr_len,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id)
{
    struct hostent *HOST;

    HOST = gethostbyname(domain_name);

    if (HOST == NULL)
        return SOC_ERROR;
    else
    {
        *addr_len = 4;
        memset(addr, 0, 4);
		memcpy(addr, HOST->h_addr_list[0], 4);

        return SOC_SUCCESS;
    }
}


kal_int8 soc_gethostbyname(kal_bool is_blocking,
                           module_type mod_id,
                           kal_int32 request_id,
                           const kal_char *domain_name,
                           kal_uint8 *addr,
                           kal_uint8 *addr_len,
                           kal_uint8 access_id,
                           kal_uint32 nwk_account_id)
{
    kal_int8 ret;

    SOC_LOCK;

    ret = socgethostbyname(is_blocking,
                           mod_id,
                           request_id,
                           domain_name,
                           addr,
                           addr_len,
                           access_id,
                           nwk_account_id);

    if (ret == SOC_SUCCESS)
    {

        soc_hostname_ind(KAL_TRUE,
                         mod_id,
                         request_id,
                         access_id,
                         addr,
                         *addr_len,
                         0,
                         0);
    }
    else
    {
        soc_hostname_ind(KAL_FALSE,
                         mod_id,
                         request_id,
                         access_id,
                         addr,
                         *addr_len,
                         SOC_BEARER_FAIL,
                         0);
    }
        
    SOC_UNLOCK;

    return SOC_WOULDBLOCK;

}


kal_int8 soc_gethostbyname2(kal_bool is_blocking,
                           module_type mod_id,
                           kal_int32 request_id,
                           const kal_char *domain_name,
                           kal_uint8 *addr,
                           kal_uint8 *addr_len,
                           kal_uint8 access_id,
                           kal_uint32 nwk_account_id,
                           kal_uint8 in_entry_num,
                           kal_uint8 *out_entry_num)
{
    return 0;
}


kal_int8 soc_gethostbyaddr(kal_bool is_blocking,
                           module_type mod_id,
                           kal_int32 request_id,
                           kal_char *domain_name,
                           kal_uint32 *domain_name_len,
                           const kal_uint8 *addr,
                           kal_uint8 addr_len,
                           kal_uint8 access_id,
                           kal_uint32 nwk_account_id)
{
    return 0;
}


kal_int8 soc_getsockaddr(kal_int8 s,
                         kal_bool is_local,
                         sockaddr_struct *addr)
{
    struct sockaddr_in saddr;  /* connector's address information */
    int addr_len = sizeof(saddr);
    int socketid;

    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    socketid = soc_free[s];

    if (socketid < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (is_local)
    {
        if (getsockname(socketid, (struct sockaddr *)&saddr, &addr_len))
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("getsockname error %d\n", WSAGetLastError());
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return -1;
        }
    }
	else
	{
        if (getpeername(socketid, (struct sockaddr *)&saddr, &addr_len))
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("getpeername error %d\n", WSAGetLastError());
        #endif /* SOC_DBG_ENABLE */
            SOC_UNLOCK;
            return -1;
        }
    }

    soc_convert_addr(&saddr, addr);
    SOC_UNLOCK;
    return 0;
}

kal_int8 soc_open_nwk_account(module_type mod_id, 
                              kal_uint32 account_id)
{
    int id;
#ifdef SOC_SUPPORT_INFO_IN_ACCT
    kal_uint8 ap_id;
    kal_uint32 nwk_acct_id;
#endif /* SOC_SUPPORT_INFO_IN_ACCT */
#ifdef SOC_SUPPORT_DUAL_SIM
    always_ask_sim_info_enum sim_src;
#endif
    kal_bool is_always_ask;


#if defined(SOC_SUPPORT_DUAL_SIM)
    always_ask_decode_data_account_id(account_id, &sim_src, &ap_id, &is_always_ask, &nwk_acct_id);
    nwk_acct_id = always_ask_encode_data_account_id(nwk_acct_id, sim_src, 0, 0);
#elif defined(SOC_SUPPORT_INFO_IN_ACCT)
    always_ask_decode_data_account_id(account_id, NULL, &ap_id, &is_always_ask, &nwk_acct_id);
#endif

#ifdef SOC_SUPPORT_INFO_IN_ACCT
    if (is_always_ask)
    {
        nwk_acct_id = 0xff;
    }
#endif /* SOC_SUPPORT_INFO_IN_ACCT */

    if (soc_find_soc_app_slot(mod_id, 
                #ifdef SOC_SUPPORT_INFO_IN_ACCT
                              ap_id,
                #endif
                              nwk_acct_id, 
                              &id) == 0)
    {
        if (soc_find_free_soc_app_slot(&id))
        {
            soc_app_nwk[id].mod_id = mod_id;
        #ifdef SOC_SUPPORT_INFO_IN_ACCT
            soc_app_nwk[id].app_id = ap_id;
        #endif
            soc_app_nwk[id].nwk_account_id = nwk_acct_id;
            soc_app_nwk[id].state = W32_BEARER_CLOSED;
        }
    }

    ASSERT(soc_app_nwk[id].state == W32_BEARER_CLOSED ||
           soc_app_nwk[id].state == W32_BEARER_OPENED);

#ifdef SOC_SUPPORT_ALWAYS_ASK
    if (is_always_ask)
    {   
        if (!soc_app_nwk[id].is_always_ask_sent)
        {
            /* send account request to CBM to ask account */
        #ifdef SOC_SUPPORT_DUAL_SIM
            soc_send_ask_acct_req_to_mmi(MOD_SOC,
                                         soc_app_nwk[id].app_id,
                                         soc_app_nwk[id].mod_id,
                                         sim_src,
                                         SOC_DEFAULT_ASK_ACCT_STATUS);  
        #else /* SOC_SUPPORT_DUAL_SIM */
            soc_send_ask_acct_req_to_mmi(MOD_SOC,
                                         soc_app_nwk[id].app_id,
                                         soc_app_nwk[id].mod_id,
                                         0,
                                         SOC_DEFAULT_ASK_ACCT_STATUS); 
        #endif /* SOC_SUPPORT_DUAL_SIM */
        }
        soc_app_nwk[id].is_always_ask_sent = KAL_TRUE;
        return SOC_WOULDBLOCK;
    
    }
#endif /* SOC_SUPPORT_ALWAYS_ASK */
    
    if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
    {
        soc_bearer_info_to_app(mod_id,
                               account_id, 
                               SOC_ACTIVATING,
                               0);
        soc_bearer_info_to_app(mod_id,
                               account_id, 
                               SOC_ACTIVATED,
                               0);   
        
        soc_app_nwk[id].state = W32_BEARER_OPENED;
    }
    
    return SOC_SUCCESS;
}

kal_int8 soc_open_bearer(kal_int8 s)
{
    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    soc_activate_account(s);

    SOC_UNLOCK;

    return 0;
}


kal_int8 soc_close_bearer(kal_int8 s)
{
    int id;
    kal_uint32 account_id;

    
    if (s < 0 || s >= MAX_SOCKET_NUM)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_find_soc_app_slot(soc_modid[s], 
        #ifdef SOC_SUPPORT_INFO_IN_ACCT
        soc_appid[s],
        #endif
        soc_account_id[s], 
        &id))
    {
 
#ifdef SOC_SUPPORT_INFO_IN_ACCT
        account_id = always_ask_encode_app_id_data_account_id(
                                    soc_account_id[s], soc_appid[s]);     
#else
        account_id = soc_account_id[s];
#endif
        
        soc_close_nwk_account_by_id((module_type)soc_modid[s], account_id);
    }
    else
    {
        SOC_UNLOCK;
        return SOC_ERROR;
    }

    SOC_UNLOCK;
    
    return SOC_SUCCESS;
}


kal_bool soc_ip_check(kal_char *asci_addr,
                      kal_uint8 *ip_addr,
                      kal_bool *ip_validity)
{
    kal_uint8 len;
    kal_uint8 i,octet_cnt;
    kal_int32 ip_digit;

    len = strlen(asci_addr);

    for (i = 0 ; i < len ; i++)
    {
        if (!isdigit((int)*(asci_addr+i)) && *(asci_addr+i) != '.' )
            return KAL_FALSE;
    }

    *ip_validity = KAL_TRUE;

    /* Extract the IP adress from character array */
    for (octet_cnt = 0 ; octet_cnt < 4 ; octet_cnt++)
    {
        if (*asci_addr == '\0') /* in case of "1.2.3." */
        {
            *ip_validity = KAL_FALSE;
            return KAL_TRUE;
        }

        ip_digit = atoi(asci_addr);

        if (ip_digit < 0 || ip_digit > 255)
        {
            *ip_validity = KAL_FALSE;
            return KAL_TRUE;
        }

        ip_addr[octet_cnt] = (kal_uint8)ip_digit;

        if (octet_cnt == 3)
            continue;

        asci_addr = strstr(asci_addr,".");
        if (asci_addr)
            asci_addr++;
        else
            break;
    }

    if (octet_cnt != 4)
    {
        return KAL_FALSE;
    }

    if (ip_addr[0] == 0 && ip_addr[1] == 0 && ip_addr[2] == 0 && ip_addr[3] == 0)
    {
        *ip_validity = KAL_FALSE;
    }

    return KAL_TRUE;
}


static kal_int8 socgetlocalip(kal_uint8 *local_ip)
{
    kal_uint8       ip_addr[4];
    kal_uint8       addr_len;

    if (local_ip == NULL)
        return SOC_INVAL;

    if (socgethostbyname(KAL_FALSE,
                        0,
                        0,
                        "",
                        ip_addr,
                        &addr_len,
                        0,
                        0) != SOC_SUCCESS)
    {
        int last_error = WSAGetLastError();

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("soc_getlocalip error: %d\n", last_error);
        #endif /* SOC_DBG_ENABLE */
        }

        return SOC_ERROR;
    }

    kal_mem_cpy(local_ip, ip_addr, 4);

    return SOC_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  soc_getlocalip
* DESCRIPTION
*   This function returns the local IP address.
*
* PARAMETERS
*  a  IN/OUT      *local_ip, copy the IP address, used as return
* RETURNS
*  SOC_SUCCESS: success
*  negative: bearer is not activated, no IP address info
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int8 soc_getlocalip(kal_uint8 *local_ip)
{
    kal_uint8       ip_addr[4];
    kal_uint8       addr_len;

    if (local_ip == NULL)
        return SOC_INVAL;

    SOC_LOCK;

    if (socgethostbyname(KAL_FALSE,
                        0,
                        0,
                        "",
                        ip_addr,
                        &addr_len,
                        0,
                        0) != SOC_SUCCESS)
    {
        int last_error = WSAGetLastError();

        if (last_error != WSAEWOULDBLOCK)
        {
        #ifdef SOC_DBG_ENABLE
            kal_printf("soc_getlocalip error: %d\n", last_error);
        #endif /* SOC_DBG_ENABLE */
        }

        SOC_UNLOCK;

        return SOC_ERROR;
    }

    kal_mem_cpy(local_ip, ip_addr, 4);

    SOC_UNLOCK;

    return SOC_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  soc_get_account_localip
* DESCRIPTION
*   This function returns the local IP address per account.
*
* PARAMETERS
*  s  IN          socket id
*  a  IN/OUT      *local_ip, copy the IP address, used as return
* RETURNS
*  SOC_SUCCESS: success
*  negative: bearer is not activated, no IP address info
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int8 soc_get_account_localip(kal_int8 s, kal_uint8 *local_ip)
{
    if (s < 0 || MAX_SOCKET_NUM <= s)
        return SOC_INVALID_SOCKET;

    SOC_LOCK;

    if (soc_free[s] < 0)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    SOC_UNLOCK;

    return soc_getlocalip(local_ip);
}


/*****************************************************************************
* FUNCTION
*  soc_app_deactivate_req_hdlr
* DESCRIPTION
*   This function closes the network account opened by that module.
*   If the corresponding account is closed, socket will send a
*   MSG_ID_APP_SOC_DEACTIVATE_CNF to application.
*
*   If application opened several accounts, SOC will close these accounts,
*   after all accounts been closed, SOC will send DEACTIVATE_CNF.
*
* PARAMETERS
*  mod_id       IN          module id
*  account_id   IN          account id (0xff: all bearers)
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
void soc_app_deactivate_req_hdlr(module_type mod_id, kal_uint32 account_id)
{
    int idx;
    int acc_id;
    kal_bool ret=KAL_FALSE;//reset
#ifdef SOC_SUPPORT_INFO_IN_ACCT
    int i;
    kal_uint8 ap_id;
    kal_uint32 nwk_acct_id;
#endif /* SOC_SUPPORT_INFO_IN_ACCT */
#ifdef SOC_SUPPORT_DUAL_SIM
    always_ask_sim_info_enum sim_src;
#endif

    SOC_LOCK;

#if defined(SOC_SUPPORT_DUAL_SIM)
    always_ask_decode_data_account_id(account_id, &sim_src, &ap_id, NULL, &nwk_acct_id);
    nwk_acct_id = always_ask_encode_data_account_id(nwk_acct_id, sim_src, 0, 0);
#elif defined(SOC_SUPPORT_INFO_IN_ACCT)
    always_ask_decode_data_account_id(account_id, NULL, &ap_id, NULL, &nwk_acct_id);

#endif    

#ifdef SOC_SUPPORT_ALWAYS_ASK   
    for (i = 0; i < MAX_SOCKET_NUM; i++)
    {
        if ((ap_id != 0 && soc_appid[i] == ap_id) ||
            (ap_id == 0 && soc_modid[i] == mod_id &&
             soc_appid[i] == ap_id))
        {
            soc_always_ask[i] = KAL_FALSE;
        }
    }
    
    if (soc_find_soc_app_slot(mod_id,
#ifdef SOC_SUPPORT_INFO_IN_ACCT
        (int)ap_id,
#endif
        0xff, 
        &idx))
    {   
        if (soc_app_nwk[idx].is_always_ask_sent)
        {
            if (soc_app_nwk[idx].nwk_account_id == 0xff)
            {
            #ifdef SOC_SUPPORT_DUAL_SIM
                soc_send_ask_acct_req_to_mmi(MOD_SOC,
                                             ap_id,
                                             mod_id,
                                             sim_src,
                                             SOC_ASK_ACCT_CANCEL_SCREEN); 
            #else /* SOC_SUPPORT_DUAL_SIM */
                soc_send_ask_acct_req_to_mmi(MOD_SOC,
                                             ap_id,
                                             mod_id,
                                             0,
                                             SOC_ASK_ACCT_CANCEL_SCREEN); 
            #endif /* SOC_SUPPORT_DUAL_SIM */
                soc_free_soc_app_slot(idx);
                soc_deactivate_cnf_to_app(ret, 
                              mod_id, 
                              account_id);
                SOC_UNLOCK;
                return;
            }
        }           
    }   
#endif /* SOC_SUPPORT_ALWAYS_ASK */

    while(1)
    {
        if (soc_find_soc_app_slot(mod_id, 
    #ifdef SOC_SUPPORT_INFO_IN_ACCT
            ap_id,
    #endif
            nwk_acct_id, 
            &idx))
        {
            acc_id = soc_app_nwk[idx].nwk_account_id;
            if (soc_app_nwk[idx].state == W32_BEARER_OPENED)
            {
                ret = KAL_TRUE;
           
            #ifdef SOC_SUPPORT_INFO_IN_ACCT
                acc_id = always_ask_encode_app_id_data_account_id(acc_id, ap_id);
            #endif
                soc_bearer_info_to_app(mod_id,
                    acc_id, 
                    SOC_DEACTIVATING,
                    0);
                soc_bearer_info_to_app(mod_id,
                    acc_id, 
                    SOC_DEACTIVATED,
                    0);
            }
            soc_free_soc_app_slot(idx);
        }
        else
        {
            break;
        }
    }

    soc_deactivate_cnf_to_app(ret, 
                              mod_id, 
                              account_id);

    SOC_UNLOCK;
}

#ifdef SOC_SUPPORT_ALWAYS_ASK
/*****************************************************************************
 * FUNCTION
 *  mmi_soc_ask_acct_cnf_hdlr
 * DESCRIPTION
 *  This function handles ASK ACCT CNF from MMI(CBM).
 * PARAMETERS
 *  cnf_ptr      [?]         cnf_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_soc_ask_acct_cnf_hdlr(mmi_soc_ask_acct_cnf_struct *cnf)
{
    kal_uint8 i;
    int id;

    SOC_LOCK;
    
    if (cnf->result)
    {
        
        if (soc_find_soc_app_slot(cnf->mod_id, 
                            #ifdef SOC_SUPPORT_INFO_IN_ACCT
                                  cnf->app_id,
                            #endif
                                  0xff, 
                                  &id))
        {
            soc_app_nwk[id].nwk_account_id = cnf->account_id;
            if (soc_app_nwk[id].state == W32_BEARER_CLOSED)
            {
            #ifdef SOC_SUPPORT_INFO_IN_ACCT
                cnf->account_id = always_ask_encode_app_id_data_account_id(
                                                cnf->account_id, cnf->app_id);
            #endif
                soc_bearer_info_to_app(cnf->mod_id,
                                       cnf->account_id, 
                                       SOC_ACTIVATING,
                                       0);
                soc_bearer_info_to_app(cnf->mod_id,
                                       cnf->account_id, 
                                       SOC_ACTIVATED,
                                       0);
        
                soc_app_nwk[id].state = W32_BEARER_OPENED;
            }
        }
        else
        {
            /* wrong confirm message */
            SOC_UNLOCK;
            return;
        }
                            
        for (i = 0; i < MAX_SOCKET_NUM; i++)
        {                  
            if (soc_always_ask[i] &&
               ((cnf->app_id != 0 && soc_appid[i] == cnf->app_id) ||
               (cnf->app_id == 0 && soc_modid[i] == cnf->mod_id &&
                soc_appid[i] == cnf->app_id)))
            {
                soc_account_id[i] = soc_app_nwk[id].nwk_account_id;
                soc_always_ask[i] = KAL_FALSE;
               
                if (soc_state[i] & W32_SOC_S_CONNECTING)
                {
                    soc_state[i] &= ~W32_SOC_S_CONNECTING;
                    sooconnect(i, &soc_peer_addr[i]);
                }
                else if (soc_state[i] & W32_SOC_S_SENDING)
                {
                    soc_events[i] |= SOC_WRITE;
                    soc_notify_thread();
                }
                else if (soc_state[i] & W32_SOC_S_RECVING)
                {
                    soc_events[i] |= SOC_READ;
                    soc_notify_thread();
                }
            }
        }
    }
    else
    {
        if (cnf->status & SOC_NEED_NOTIFY)
        {
            for (i = 0; i < MAX_SOCKET_NUM; i++)
            {
                if (soc_always_ask[i] &&
                    ((cnf->app_id != 0 && soc_appid[i] == cnf->app_id) ||
                    (cnf->app_id == 0 && soc_modid[i] == cnf->mod_id &&
                    soc_appid[i] == cnf->app_id)))
                {
               
                    if (soc_state[i] & W32_SOC_S_CONNECTING)
                    {
                        soc_notify_app(soc_free[i], SOC_CONNECT, 
                        KAL_FALSE, SOC_CANCEL_ACT_BEARER);
                    }
                    else if (soc_state[i] & W32_SOC_S_SENDING) 
                    {
                        soc_notify_app(soc_free[i], SOC_WRITE, 
                        KAL_FALSE, SOC_CANCEL_ACT_BEARER);
                    }
                    else if (soc_state[i] & W32_SOC_S_RECVING)
                    {
                        soc_notify_app(soc_free[i], SOC_READ, 
                        KAL_FALSE, SOC_CANCEL_ACT_BEARER);
                    }
                }
            }   
       
            if (soc_find_soc_app_slot(cnf->mod_id, 
                            #ifdef SOC_SUPPORT_INFO_IN_ACCT
                                  cnf->app_id,
                            #endif
                                  0xff, 
                                  &id))
            {

                if (soc_app_nwk[id].is_always_ask_sent)
                {
                
                #ifdef SOC_SUPPORT_INFO_IN_ACCT
                    cnf->account_id = always_ask_encode_app_id_data_account_id(
                    0, soc_appid[i]);
                #endif
                    soc_bearer_info_to_app(soc_modid[i],
                                           cnf->account_id, 
                                           SOC_DEACTIVATED,
                                           SOC_CANCEL_ACT_BEARER);
                
                
                }
                       
            }
        }
  
    }

    SOC_UNLOCK;
    return;
}
#endif /* SOC_SUPPORT_ALWAYS_ASK */

kal_int8 soc_abort_dns_query(kal_bool   by_mod_id,
                             module_type mod_id,
                             kal_bool   by_request_id,
                             kal_uint32 request_id,
                             kal_bool   by_access_id,
                             kal_uint8  access_id,
                             kal_bool   by_nwk_account_id,
                             kal_uint32 nwk_account_id)
{
    return 0;
}


kal_int8 soc_get_last_error(kal_int8 s,
                            kal_int8 *error,
                            kal_int32 *detail_cause)
{
    if (error)
        *error = 0;

    if (detail_cause)
        *detail_cause = 0;

    return 0;
}


kal_int8 soc_set_last_error(kal_int8 s,
                            kal_int8 error,
                            kal_int32 detail_cause)
{
    return 0;
}


kal_int8 soc_gethostbysrv(module_type mod_id,
                          kal_int32 request_id,
                          const kal_char *domain_name,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id,
                          soc_dns_srv_struct *entry,
                          kal_uint8 in_entry_num,
                          kal_uint8 *out_entry_num)
{
    return 0;
}


kal_int8 soc_gethostbynaptr(module_type mod_id,
                          kal_int32 request_id,
                          const kal_char *domain_name,
                          kal_uint8 access_id,
                          kal_uint32 nwk_account_id,
                          soc_dns_naptr_struct *entry,
                          kal_uint8 in_entry_num,
                          kal_uint8 *out_entry_num)
{
    return 0;
}


/*
 * Return KAL_TRUE if there is data in the socket's receive queue indicating
 * the socket is ready for read.
 * Otherwise, return KAL_FALSE.
 */
kal_bool soc_ready_for_read(kal_int8 s)
{
    int sock = soc_free[s];
    fd_set readfds;
    struct timeval tv;
    int ret;

    if (sock == SOC_SMS_ID)
        return KAL_FALSE;
        
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    if (!IS_VALID_SOCKET_NUM(s) || soc_state[s] & W32_SOC_S_FINED)
        return KAL_FALSE;

    ret = select(sock + 1, &readfds, NULL, NULL, &tv);
    if (ret > 0)
        return KAL_TRUE;
    else /* XXX, error return value -1 is not handled */
        return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  soc_set_module
 *
 * DESCRIPTION
 *  This function sets the module id associate to the socket id.
 *  The notification from SOC to application will be sent to the new module.
 * 
 *  Note that this function should not be called inside a socket protection
 *  segment, which causes a dead-lock.
 *
 * PARAMETERS
 *  s       [IN]        socket id
 *  mod     [IN]        new module id
 * RETURNS
 *  >0                     the id of original module id associated to the socket
 *  SOC_INVALID_SOCKET     given an invalid socket id.
 *  0                      error occurs.
 *****************************************************************************/
kal_int32 soc_set_module(kal_uint8 s, module_type mod)
{
    kal_int8 error;
    int idx;
    module_type orig_mod;

    SOC_LOCK;

    if (s < 0 || MAX_SOCKET_NUM <= s || soc_state[s] == W32_SOC_S_NOUSE)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    if (soc_find_soc_app_slot(soc_modid[s], 
#ifdef SOC_SUPPORT_INFO_IN_ACCT
                              soc_appid[s],
#endif
                              soc_account_id[s], 
                              &idx) == 0)
    {
        SOC_UNLOCK;
        return 0;
    }

    orig_mod = soc_modid[s];

    soc_modid[s] = mod;

    SOC_UNLOCK;
    return orig_mod;
}


/*****************************************************************************
 * FUNCTION
 *  soc_get_socket_acct
 * DESCRIPTION
 *  Get network account id associated with the given socket id
 *  
 * PARAMETERS
 *  s      [IN]        socket id
 * RETURNS
 *  account id associate with the socket while application calling soc_create()
 *****************************************************************************/
kal_int32 soc_get_socket_acct(kal_uint8 s)
{
    kal_int32 acct_id;

    SOC_LOCK;
    if (s < 0 || MAX_SOCKET_NUM <= s || soc_state[s] == W32_SOC_S_NOUSE)
    {
        SOC_UNLOCK;
        return SOC_INVALID_SOCKET;
    }

    acct_id = soc_account_id[s];
        
    SOC_UNLOCK;
    return acct_id;
}


unsigned char *err_str(int error)
{
    int i;
    unsigned char *str;
    
    for (i = 0; i < sizeof(winsock_errstr) / sizeof(winsock_errstr[0]); i++)
        if (atoi(winsock_errstr[i]) == error)
        {
            str = strchr(winsock_errstr[i], ' ') + 1;
            break;
        }
    return str;
}


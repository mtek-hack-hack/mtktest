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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include "MMI_include.h"

#if defined (__MMI_DOWNLOAD_AGENT__)

#include "ProtocolEvents.h"

#include "Wap_ps_struct.h"
#include "Wapadp.h"

#include "DLAgentWPS.h"

#if defined(OBIGO_Q03C)
#define MMI_DA_WPS_SLOW_BG_DL_SUPPORT
#endif

/****************************************************************************
* Define
*****************************************************************************/

#define MMI_DA_WPS_TRACE_GROUP      MMI_CONN_TRC_G1_DLAGENT

#define MMI_DA_WPS_MAX_SESSION      5
#define MMI_DA_WPS_INVALID_CHANNEL  0xFF

#define MMI_DA_WPS_REQUEST_ID_BASE  32
#define MMI_DA_WPS_REQUEST_ID_RANGE MMI_DA_WPS_MAX_SESSION
#define MMI_DA_WPS_REQUEST_ID_END   (MMI_DA_WPS_REQUEST_ID_BASE+MMI_DA_WPS_REQUEST_ID_RANGE)

#define MMI_DA_WPS_USER_AGENT_SIZE  256

/****************************************************************************
* Define - Macro
*****************************************************************************/

#define DA_WPS_TRACE_FUNC2(func, p1, p2)        mmi_da_trace_func_ex(DA_TRACE_##func, p1, p2, 0)
#define DA_WPS_TRACE_FUNC3(func, p1, p2, p3)    mmi_da_trace_func_ex(DA_TRACE_##func, p1, p2, p3)

#if 0//defined(WIN32)
/* under construction !*/
#else
#define DA_WPS_TRACE                            MMI_TRACE
#endif

#define DA_WPS_VALID_ID(id)         (id) >= MMI_DA_WPS_REQUEST_ID_BASE && (id) < MMI_DA_WPS_REQUEST_ID_END


/****************************************************************************
* Typedef - Enum
*****************************************************************************/

enum
{
    DA_TRACE_mmi_da_wps_create_session = 0x000A0000,
    DA_TRACE_mmi_da_wps_free_session,

    DA_TRACE_WPS_END
}; /* this enum is for TRACE usage */

enum
{
    MMI_DA_WPS_SESSION_STATE_READY = 0,
    MMI_DA_WPS_SESSION_STATE_HTTP_REQUEST,
    MMI_DA_WPS_SESSION_STATE_ABORT_ING,

    MMI_DA_WPS_SESSION_STATE_INIT,
    
    MMI_DA_WPS_SESSION_STATE_NUM
};

enum
{
    MMI_DA_WPS_STATE_FREE = 0,
    MMI_DA_WPS_STATE_BUSY_SET,
    MMI_DA_WPS_STATE_BUSY_UNSET,

    MMI_DA_WPS_STATE_NUM
};

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct
{
    /* Session infomation */
    U8                      request_id;
    U8                      result;

    U16                     http_status;
    U16                     dl_status;
    MMI_BOOL                more;

    /* run-time */
    U8                      state;
    U8                      seq_num;

    /* Client infomation */
    U32                                     arg;
    mmi_da_wps_session_created_funcptr_type create_cb;
    mmi_da_wps_http_response_funcptr_type   http_rsp_cb;
    mmi_da_wps_http_auth_ind_funcptr_type   http_auth_cb;
    mmi_da_wps_dl_progress_funcptr_type     dl_progress_cb;
    mmi_da_wps_session_aborted_funcptr_type abort_cb;
    
} mmi_da_wps_session;

typedef struct
{
    MMI_BOOL                inited_flag;// channel is set or not.
    U8                      busy_flag;  // during set/unset channel
    
    U8                      channel_id;

    U8                      session_num;
    mmi_da_wps_session      *session_table[MMI_DA_WPS_MAX_SESSION];

    U8                      user_agent[MMI_DA_WPS_USER_AGENT_SIZE];
    
} mmi_da_wps_context;

/****************************************************************************
* Static Variable
*****************************************************************************/

static mmi_da_wps_context da_wps_context;

/****************************************************************************
* Global Variable
*****************************************************************************/

extern void mmi_da_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, S32 dst_id);
extern void mmi_da_trace_func_ex(S32 func_enum, S32 p1, S32 p2, S32 p3);

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
static void mmi_da_wps_free_session(mmi_da_wps_session *session);

static BOOL mmi_da_wps_send_get_user_agent_req(void);
//static BOOL mmi_da_wps_recv_get_user_agent_rsp(void *MsgStruct);
static BOOL mmi_da_wps_send_set_channel_req(void);
static void mmi_da_wps_recv_set_channel_rsp(void *MsgStruct);
static BOOL mmi_da_wps_send_unset_channel_req(void);
static void mmi_da_wps_recv_unset_channel_rsp(void *MsgStruct);
static BOOL mmi_da_wps_send_http_req(U8 request_id, U8 http_method,
                                     S8 * url, S8 * post_data, PU16 file_path);
static void mmi_da_wps_recv_http_rsp(void *MsgStruct);
static BOOL mmi_da_wps_send_cancel_req(U8 request_id);
static void mmi_da_wps_recv_cancel_rsp(void *MsgStruct);
static void mmi_da_wps_recv_dl_progress_ind(void *MsgStruct);
static BOOL mmi_da_wps_send_dl_progress_res(U8 request_id, S32 seq_num);
static void mmi_da_wps_recv_http_auth_ind(void *MsgStruct);
static BOOL mmi_da_wps_send_http_auth_res(U8 request_id, U8 *username, U8 *password);

#if defined(MMI_DA_WPS_SLOW_BG_DL_SUPPORT)
static void _mmi_da_wps_timer_handler(void* param);
#endif
#define END_OF_FUNCTION_DECLARATION

void mmi_da_wps_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&da_wps_context, 0, sizeof(da_wps_context));
    da_wps_context.channel_id = MMI_DA_WPS_INVALID_CHANNEL;
}

void mmi_da_wps_create_session(U32 arg, 
                               mmi_da_wps_session_created_funcptr_type create_cb,
                               mmi_da_wps_http_response_funcptr_type http_rsp_cb,
                               mmi_da_wps_http_auth_ind_funcptr_type http_auth_cb,
                               mmi_da_wps_dl_progress_funcptr_type dl_progress_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_da_wps_session  *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* find a empty slot */
    if(da_wps_context.session_num == MMI_DA_WPS_MAX_SESSION)
    {
        create_cb(MMI_DA_INVALID_SESSION_HANDLE, arg);
        return;
    }

    for(i=0; i<MMI_DA_WPS_MAX_SESSION; i++)
    {
        if(!da_wps_context.session_table[i])
            break;
    }
    ASSERT(i != MMI_DA_WPS_MAX_SESSION);

    /* alloc resource */
    session = OslMalloc(sizeof(mmi_da_wps_session));
    if(!session)
    {
        create_cb(MMI_DA_INVALID_SESSION_HANDLE, arg);
        return;
    }

    memset(session, 0, sizeof(mmi_da_wps_session));

    da_wps_context.session_table[i] = session;
    da_wps_context.session_num++;

    session->request_id = i;

    session->arg = arg;
    session->create_cb = create_cb;
    session->http_rsp_cb = http_rsp_cb;
    session->http_auth_cb = http_auth_cb;
    session->dl_progress_cb = dl_progress_cb;
    session->state = MMI_DA_WPS_SESSION_STATE_INIT;

    DA_WPS_TRACE_FUNC3(mmi_da_wps_create_session, da_wps_context.busy_flag, da_wps_context.session_num, i);

    if(da_wps_context.inited_flag)
    {
        switch(da_wps_context.busy_flag)
        {
        case MMI_DA_WPS_STATE_FREE:
            session->state = MMI_DA_WPS_SESSION_STATE_READY;
            create_cb((wps_session_handle)session, arg);
            break;
        case MMI_DA_WPS_STATE_BUSY_UNSET:
            /* do nothing, when unset_rsp we will check if there are session or not */
            break;

        case MMI_DA_WPS_STATE_BUSY_SET:
        default:
            ASSERT(0);
            goto func_err;
            break;
        }
    }
    else /* not inited yet */
    {
        switch(da_wps_context.busy_flag)
        {
        case MMI_DA_WPS_STATE_FREE:
            /* init now */
            mmi_da_wps_send_get_user_agent_req();
            break;
            
        case MMI_DA_WPS_STATE_BUSY_SET:
            /* already in setting. do nothing */
            break;

        case MMI_DA_WPS_STATE_BUSY_UNSET:
        default:
            ASSERT(0);
            goto func_err;
            break;
        }
    }
    return;
    
func_err:
    da_wps_context.session_table[i] = NULL;
    da_wps_context.session_num--;
    OslMfree(session);
    create_cb(MMI_DA_INVALID_SESSION_HANDLE, arg);
    return;
}

MMI_BOOL mmi_da_wps_http_req(wps_session_handle session_id, 
                         U8 method,
                         S8 *url,
                         S8 *post_data,
                         U16 *filepath,
                         U8 reply_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_wps_session *s;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!da_wps_context.inited_flag)
        return MMI_FALSE;
    
    s = (mmi_da_wps_session*)session_id;
    ASSERT(s);

    if(s->state != MMI_DA_WPS_SESSION_STATE_READY)
        return MMI_FALSE;
    
    if(mmi_da_wps_send_http_req(s->request_id, method, url, post_data, filepath))
    {
        s->state = MMI_DA_WPS_SESSION_STATE_HTTP_REQUEST;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

MMI_BOOL mmi_da_wps_session_auth(wps_session_handle session_id, U8 *username, U8 *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_wps_session *s;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    s = (mmi_da_wps_session*)session_id;
    ASSERT(s);
    ASSERT(s->state == MMI_DA_WPS_SESSION_STATE_HTTP_REQUEST);
    
    return (MMI_BOOL)mmi_da_wps_send_http_auth_res(s->request_id, username, password);
}

MMI_BOOL mmi_da_wps_session_auth_UCS2(wps_session_handle session, U16 *username, U16 *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8          *usr, *pwd;
    MMI_BOOL    bret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(username && password);
    usr = OslMalloc(mmi_ucs2strlen((S8*)username)+1);
    mmi_ucs2_to_asc((S8*)usr, (S8*)username);
    pwd = OslMalloc(mmi_ucs2strlen((S8*)password)+1);
    mmi_ucs2_to_asc((S8*)pwd, (S8*)password);

    bret = mmi_da_wps_session_auth(session, usr, pwd);

    OslMfree(usr);
    OslMfree(pwd);
    return bret;
}

void mmi_da_wps_close_session(wps_session_handle session_id,
                              mmi_da_wps_session_aborted_funcptr_type abort_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_wps_session *s;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    s = (mmi_da_wps_session*)session_id;
    ASSERT(s);

    if(s->state != MMI_DA_WPS_SESSION_STATE_READY)
    {
        /* still running, abort it */
        s->abort_cb = abort_cb;
        s->state = MMI_DA_WPS_SESSION_STATE_ABORT_ING;
        mmi_da_wps_send_cancel_req(s->request_id);
    }
    else
    {
        if(abort_cb)
            abort_cb(s->arg);
        mmi_da_wps_free_session(s);
    }
}

static void mmi_da_wps_free_session(mmi_da_wps_session *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(s);
    ASSERT(s->state == MMI_DA_WPS_SESSION_STATE_READY);
    
    ASSERT(da_wps_context.session_table[s->request_id] == s);
    da_wps_context.session_table[s->request_id] = NULL;
    da_wps_context.session_num--;
    OslMfree(s);

    DA_WPS_TRACE_FUNC2(mmi_da_wps_free_session, da_wps_context.busy_flag, da_wps_context.session_num);
    if(da_wps_context.session_num == 0)
        mmi_da_wps_send_unset_channel_req();
    
}

S16 mmi_da_wps_get_session_id(wps_session_handle session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_wps_session *session;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    session = (mmi_da_wps_session*)session_id;

    if(!session)
        return 0;

    return (S16)session->request_id | (da_wps_context.channel_id << 8);

}

void mmi_da_wps_cancel_create_session(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(da_wps_context.busy_flag != MMI_DA_WPS_STATE_FREE);
    
    for(i=0;i<MMI_DA_WPS_MAX_SESSION;i++)
    {
        if(da_wps_context.session_table[i] && 
            da_wps_context.session_table[i]->state == MMI_DA_WPS_SESSION_STATE_INIT &&
            da_wps_context.session_table[i]->arg == arg)
        {
            OslMfree(da_wps_context.session_table[i]);
            da_wps_context.session_num--;
            da_wps_context.session_table[i] = NULL;
        }
    }
}



#define STATIC_IMPLEMENT

static BOOL _da_wps_is_ready(void)
{
    return da_wps_context.inited_flag &&
            da_wps_context.channel_id != MMI_DA_WPS_INVALID_CHANNEL &&
            da_wps_context.busy_flag == MMI_DA_WPS_STATE_FREE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_send_get_user_agent_req
* DESCRIPTION
*   get User Agent
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static BOOL mmi_da_wps_send_get_user_agent_req(void)
{
    char* user_agent;
    S32 i;

    ASSERT(!da_wps_context.inited_flag);
    if(da_wps_context.busy_flag != MMI_DA_WPS_STATE_FREE)
    {
        ASSERT(0);
        return MMI_FALSE;
    }

    da_wps_context.busy_flag = MMI_DA_WPS_STATE_BUSY_SET;

    user_agent = wap_get_user_agent();
    if(user_agent)
    {
        i = strlen(user_agent);
        if(i >= MMI_DA_WPS_USER_AGENT_SIZE)
            i = MMI_DA_WPS_USER_AGENT_SIZE-1;

        strncpy((S8*)da_wps_context.user_agent, user_agent, i);
    }
    else
    {
        da_wps_context.user_agent[0] = 0;
    }

    mmi_da_wps_send_set_channel_req();
    
//    mmi_da_send_ilm(NULL, NULL, MSG_ID_WAP_GET_USER_AGENT_REQ, MOD_WAP);
//    SetProtocolEventHandler((PsFuncPtr) mmi_da_wps_recv_get_user_agent_rsp, MSG_ID_WAP_GET_USER_AGENT_RSP);
    return MMI_TRUE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_send_set_channel_req
* DESCRIPTION
*   send setup channel request
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
//#define STATIC_HEADER "Content-Type: text/plain; charset=UTF-8\r\nUser-Agent: Nokia7260/2.0 (04.91) Profile/MIDP-2.0 Configuration/CLDC-1.1\r\nAccept-Charset: *\r\nAccept-Encoding: gzip, deflate\r\nTE: deflate, gzip\r\nAccept: */*\r\n"
#define STATIC_HEADER "Accept-Charset: *\r\nAccept: */*\r\n"

static BOOL mmi_da_wps_send_set_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct      *set_channel_req;
    peer_buff_struct                *peer_buff_ptr = NULL;
    wps_set_channel_req_var_struct  set_channel_req_var;
    U16                             len, pdu_length;
    U16                             msg_len, ref_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_SEND_SET_CHANNEL_REQ);

    set_channel_req = (wps_set_channel_req_struct *) construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL);
    msg_len = set_channel_req->msg_len;
    ref_count = set_channel_req->ref_count;
    memset(set_channel_req, 0 , sizeof(wps_set_channel_req_struct));
    set_channel_req->msg_len = msg_len;
    set_channel_req->ref_count = ref_count;
    set_channel_req->use_default = KAL_TRUE;
    set_channel_req_var.static_header_len = len =
        strlen("User-Agent: ")+
        strlen((S8*)da_wps_context.user_agent)+
        strlen("\r\n")+
        strlen(STATIC_HEADER);
    set_channel_req_var.static_header = get_ctrl_buffer((len+1));
    sprintf((S8*)set_channel_req_var.static_header,"User-Agent: %s\r\n%s",
            da_wps_context.user_agent, STATIC_HEADER);

    pdu_length= wps_pun_var_part(WPS_PUN_SIZE,MSG_ID_WPS_SET_CHANNEL_REQ,&set_channel_req_var,NULL);

    if( pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, get_pdu_ptr(peer_buff_ptr, &len)) !=
            pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    free_ctrl_buffer(set_channel_req_var.static_header);

    mmi_da_send_ilm(set_channel_req, peer_buff_ptr, MSG_ID_WPS_SET_CHANNEL_REQ, MOD_WPS);

    SetProtocolEventHandler((PsFuncPtr) mmi_da_wps_recv_set_channel_rsp, MSG_ID_WPS_SET_CHANNEL_RSP);
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*   mmi_da_wps_recv_set_channel_rsp
* DESCRIPTION
*   Handler function to handle set channel response, save channel_id to context
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_wps_recv_set_channel_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct *) MsgStruct;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_RECV_SET_CHANNEL_RSP);

    ASSERT(da_wps_context.busy_flag == MMI_DA_WPS_STATE_BUSY_SET);
    ASSERT(!da_wps_context.inited_flag);

    if (p->result == WPS_OK)
    {
        da_wps_context.channel_id = p->channel_id;
        da_wps_context.inited_flag = MMI_TRUE;
    }

    da_wps_context.busy_flag = MMI_DA_WPS_STATE_FREE;
    
    /* if there is pending action */
    if(da_wps_context.inited_flag)
    {
        if(da_wps_context.session_num == 0)
        {
            mmi_da_wps_send_unset_channel_req();
            return;
        }
        
        for(i=0;i<MMI_DA_WPS_MAX_SESSION;i++)
        {
            if(da_wps_context.session_table[i] && da_wps_context.session_table[i]->state == MMI_DA_WPS_SESSION_STATE_INIT)
            {
                da_wps_context.session_table[i]->state = MMI_DA_WPS_SESSION_STATE_READY;
                da_wps_context.session_table[i]->create_cb((wps_session_handle)da_wps_context.session_table[i], da_wps_context.session_table[i]->arg);
            }
        }
    }
    else
    {
        /* error, clear all session */
        for(i=0;i<MMI_DA_WPS_MAX_SESSION;i++)
        {
            if(da_wps_context.session_table[i])
            {
                da_wps_context.session_table[i]->create_cb(MMI_DA_INVALID_SESSION_HANDLE, da_wps_context.session_table[i]->arg);
                OslMfree(da_wps_context.session_table[i]);
                da_wps_context.session_table[i] = NULL;
            }
        }
        da_wps_context.session_num = 0;
    }
    }

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_send_unset_channel_req
* DESCRIPTION
*   Send "Unset channel" request to wap to destory channel
* PARAMETERS
*   void
* RETURNS
*   MMI_TRUE: OK
*   MMI_FALSE: FAIL
*****************************************************************************/
static BOOL mmi_da_wps_send_unset_channel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wps_unset_channel_req_struct *unset_channel_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_SEND_UNSET_CHANNEL_REQ);

    if(da_wps_context.busy_flag != MMI_DA_WPS_STATE_FREE)
        return MMI_FALSE;

    /* only unset when no session */
    ASSERT(!da_wps_context.session_num);

    if (da_wps_context.channel_id != MMI_DA_WPS_INVALID_CHANNEL)
    {
        unset_channel_req =
            (wps_unset_channel_req_struct *) construct_local_para(sizeof(wps_unset_channel_req_struct), TD_CTRL);
        unset_channel_req->channel_id = da_wps_context.channel_id;
        mmi_da_send_ilm(unset_channel_req, NULL, MSG_ID_WPS_UNSET_CHANNEL_REQ, MOD_WPS);

        SetProtocolEventHandler((PsFuncPtr) mmi_da_wps_recv_unset_channel_rsp, MSG_ID_WPS_UNSET_CHANNEL_RSP);
        da_wps_context.busy_flag = MMI_DA_WPS_STATE_BUSY_UNSET;
        return MMI_TRUE;
    }
    else
    {
        ASSERT(0);
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*   mmi_da_wps_recv_unset_channel_rsp
* DESCRIPTION
*   Handler function: To handle "unset channel response", reset the channel_id
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_wps_recv_unset_channel_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_rsp_struct *p = (wps_unset_channel_rsp_struct *) MsgStruct;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_RECV_UNSET_CHANNEL_RSP);

    if(da_wps_context.busy_flag != MMI_DA_WPS_STATE_BUSY_UNSET)
    {
        ASSERT(0);
        return;
    }

    if (p->result == WPS_OK)
    {
        da_wps_context.channel_id = MMI_DA_WPS_INVALID_CHANNEL;
        da_wps_context.inited_flag = MMI_FALSE;
    }
    
    da_wps_context.busy_flag = MMI_DA_WPS_STATE_FREE;

    /* if there is session */
    if(da_wps_context.session_num)
    {
        if(da_wps_context.inited_flag)
        {
            /* unset channel failed, channel still VALID, call back */
            for(i=0;i<MMI_DA_WPS_MAX_SESSION;i++)
            {
                if(da_wps_context.session_table[i] && da_wps_context.session_table[i]->state == MMI_DA_WPS_SESSION_STATE_INIT)
                {
                    da_wps_context.session_table[i]->state = MMI_DA_WPS_SESSION_STATE_READY;
                    da_wps_context.session_table[i]->create_cb((wps_session_handle)da_wps_context.session_table[i], da_wps_context.session_table[i]->arg);
                }
            }            
        }
        else
        {
            /* set channel again */
            mmi_da_wps_send_get_user_agent_req();
        }
    }
    
}


static BOOL mmi_da_wps_send_http_req(U8 request_id, U8 http_method,
                                     S8 * url, S8 * post_data, PU16 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wps_http_req_struct     *http_req;
    wps_http_req_var_struct http_req_var;
    peer_buff_struct        *peer_buff_ptr = NULL;
    U16                     pdu_length;
    U16                     len;
    FS_HANDLE               hd;
    static S8               range_header[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_SEND_HTTP_REQ, request_id);

    ASSERT(_da_wps_is_ready());
    ASSERT(request_id < MMI_DA_WPS_REQUEST_ID_RANGE);

    http_req = (wps_http_req_struct *) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);
    http_req->channel_id = da_wps_context.channel_id;
    http_req->request_id = request_id + MMI_DA_WPS_REQUEST_ID_BASE;
    http_req->method = http_method;
    http_req->option = WPS_HTTP_OPTION_NO_CACHE;

    http_req_var.request_url_len = (kal_uint32) strlen(url);
    http_req_var.request_url = (kal_uint8 *) url;
    http_req_var.request_header_len = 0;
    http_req_var.request_header = NULL;

    if (http_method == WPS_HTTP_METHOD_POST)
    {
        ASSERT(post_data != NULL);
        http_req->reply_type = WPS_DATA_TYPE_BUFFER;
        http_req->reply_segment_len = 0;        /* no use here */
        http_req->post_type = WPS_DATA_TYPE_BUFFER;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = strlen(post_data);
        http_req->more_post = MMI_FALSE;
        http_req_var.post_segment_len = strlen(post_data);
        http_req_var.post_segment = (kal_uint8 *) post_data;
        http_req_var.request_header_len = strlen("Content-Type: text/plain; charset=UTF-8\r\n");
        http_req_var.request_header = (kal_uint8 *)"Content-Type: text/plain; charset=UTF-8\r\n";
    }
    else
    {
        ASSERT(file_path != NULL && mmi_ucs2strlen((S8 *) file_path) < 256);
        http_req->reply_type = WPS_DATA_TYPE_FILE;
        mmi_ucs2cpy((S8 *) http_req->reply_path, (S8 *) file_path);
        http_req->reply_segment_len = 0;        /* no use here */
        http_req->post_type = WPS_DATA_TYPE_BUFFER;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = 0;
        http_req->more_post = MMI_FALSE;
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
        
        // If the target file exist, it means RESUME
        if ((hd = FS_Open((PU16)file_path, FS_READ_ONLY)) >= 0)
        {
            UINT file_size;
            FS_GetFileSize(hd, &file_size);
            sprintf(range_header, "Range:bytes=%d-", file_size);
            FS_Close(hd);
            http_req_var.request_header_len = strlen(range_header);
            http_req_var.request_header = (kal_uint8 *)range_header;
        }
    }

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &len)) !=
            pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    mmi_da_send_ilm(http_req, peer_buff_ptr, MSG_ID_WPS_HTTP_REQ, MOD_WPS);

    SetProtocolEventHandler((PsFuncPtr) mmi_da_wps_recv_http_rsp, MSG_ID_WPS_HTTP_RSP);
    SetProtocolEventHandler((PsFuncPtr) mmi_da_wps_recv_dl_progress_ind, MSG_ID_WPS_DL_PROGRESS_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_da_wps_recv_http_auth_ind, MSG_ID_WPS_HTTP_AUTH_IND);

    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_recv_http_rsp
* DESCRIPTION
*   Handler function: To handle "http response". We will save content_type at oma_content
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_wps_recv_http_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *p = (wps_http_rsp_struct *) MsgStruct;
//    S32                 len = 0;
    mmi_da_wps_session  *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_RECV_HTTP_RSP);

    ASSERT(DA_WPS_VALID_ID(p->request_id));

    session = da_wps_context.session_table[p->request_id - MMI_DA_WPS_REQUEST_ID_BASE];

    switch(session->state)
    {
    case MMI_DA_WPS_SESSION_STATE_ABORT_ING:
        // We are aborting / waiting cancel rsp, do nothing
        break;

    case MMI_DA_WPS_SESSION_STATE_HTTP_REQUEST:
        session->http_status = p->status;
        session->more = p->more;
        if(p->result != WPS_OK)
        {
            session->state = MMI_DA_WPS_SESSION_STATE_READY;
        }
    //    if(!p->more)
    //        session->state = MMI_DA_WPS_SESSION_STATE_READY;

        session->http_rsp_cb(session->arg, p->result, p->status, (S8*)p->content_type, p->content_length);
        break;

    default:
        ASSERT(0);
        break;
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_send_cancel_req
* DESCRIPTION
*   Send "cancel request" to WAP task to cancel an action.
* PARAMETERS
*   request_id  IN  action, reference to mmi_da_oma_request_id_enum
* RETURNS
*   MMI_TRUE:  OK
*   MMI_FALSE:  false
*****************************************************************************/
static BOOL mmi_da_wps_send_cancel_req(U8 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_req_struct   *abort_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_SEND_CANCEL_REQ);

    ASSERT(_da_wps_is_ready());

    abort_req = (wps_cancel_req_struct *) construct_local_para(sizeof(wps_cancel_req_struct), TD_CTRL);
    abort_req->request_id = request_id + MMI_DA_WPS_REQUEST_ID_BASE;
    abort_req->channel_id = da_wps_context.channel_id;
    mmi_da_send_ilm(abort_req, NULL, MSG_ID_WPS_CANCEL_REQ, MOD_WPS);

    SetProtocolEventHandler((PsFuncPtr) mmi_da_wps_recv_cancel_rsp, MSG_ID_WPS_CANCEL_RSP);

    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_recv_cancel_rsp
* DESCRIPTION
*   Handler function: To handle "cancel response".
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_wps_recv_cancel_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_rsp_struct   *p = (wps_cancel_rsp_struct *) MsgStruct;
    mmi_da_wps_session      *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_RECV_CANCEL_RSP);

    ASSERT(DA_WPS_VALID_ID(p->request_id));

    session = da_wps_context.session_table[p->request_id - MMI_DA_WPS_REQUEST_ID_BASE];

    ASSERT(session->state == MMI_DA_WPS_SESSION_STATE_ABORT_ING);

    session->state = MMI_DA_WPS_SESSION_STATE_READY;
    if(session->abort_cb)
        session->abort_cb(session->arg);
    mmi_da_wps_free_session(session);

}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_recv_dl_progress_ind
* DESCRIPTION
*   Handler function: To handle "progress indication". We will save status,
    sequence number, and total size to oma_context
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_wps_recv_dl_progress_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_dl_progress_ind_struct *p = (wps_dl_progress_ind_struct *) MsgStruct;
    mmi_da_wps_session  *s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_WPS_TRACE(MMI_DA_WPS_TRACE_GROUP, MMI_DA_OMA_RECV_DL_PROGRESS_IND, p->seq_num, p->acc_size);

    ASSERT(DA_WPS_VALID_ID(p->request_id));

    s = da_wps_context.session_table[p->request_id - MMI_DA_WPS_REQUEST_ID_BASE];

    switch(s->state)
    {
    case MMI_DA_WPS_SESSION_STATE_ABORT_ING:
        return;

    case MMI_DA_WPS_SESSION_STATE_HTTP_REQUEST:
        break;

    default:
        ASSERT(0);
        return;
    }

#if defined(MMI_DA_WPS_SLOW_BG_DL_SUPPORT)
    {
        ASSERT(MMI_DA_WPS_TIMER_END > s->request_id);
        
        /* in Slow mode, we start a timer to send response to WPS */
        s->seq_num = p->seq_num;
        StartTimerEx((U16)(MMI_DA_WPS_TIMER_1 + s->request_id), 
            10, _mmi_da_wps_timer_handler, 
            (void*)s->request_id);
    }
#else
    {
        mmi_da_wps_send_dl_progress_res(s->request_id, p->seq_num);
    }
#endif

    switch(p->status)
    {
        case WPS_DL_STATUS_ABORT:
        case WPS_DL_STATUS_COMPLETE:
            s->state = MMI_DA_WPS_SESSION_STATE_READY;
            break;
            
        case WPS_DL_STATUS_DOWNLOADING:
            break;

        default:
            ASSERT(0);
            break;
    }
    
    s->dl_status = p->status;
    s->dl_progress_cb(s->arg, p->status, p->acc_size, p->cause);

}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_send_dl_progress_res
* DESCRIPTION
*   Send "progress rsp" to WAP task
* PARAMETERS
*   request_id  IN  action, reference to mmi_da_oma_request_id_enum
* RETURNS
*   MMI_TRUE:  OK
*   MMI_FALSE:  false
*****************************************************************************/
static BOOL mmi_da_wps_send_dl_progress_res(U8 request_id, S32 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_dl_progress_res_struct *progress_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    progress_res = (wps_dl_progress_res_struct *) construct_local_para(sizeof(wps_dl_progress_res_struct), TD_CTRL);
    progress_res->request_id = request_id + MMI_DA_WPS_REQUEST_ID_BASE;
    progress_res->channel_id = da_wps_context.channel_id;
    progress_res->seq_num = seq_num;
    mmi_da_send_ilm(progress_res, NULL, MSG_ID_WPS_DL_PROGRESS_RES, MOD_WPS);
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_recv_get_user_agent_rsp
* DESCRIPTION
*   Handler to get user agent from WAP
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static void mmi_da_wps_recv_http_auth_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_ind_struct    *p;
    mmi_da_wps_session          *session;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p = (wps_http_auth_ind_struct*) MsgStruct;
    ASSERT(DA_WPS_VALID_ID(p->request_id));
    ASSERT(p->channel_id == da_wps_context.channel_id);

    session = da_wps_context.session_table[p->request_id - MMI_DA_WPS_REQUEST_ID_BASE];

    switch(session->state)
    {
    case MMI_DA_WPS_SESSION_STATE_HTTP_REQUEST:
        session->http_auth_cb(session->arg);
        break;

    case MMI_DA_WPS_SESSION_STATE_ABORT_ING:
        break;

    default:
        ASSERT(0);
        break;
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_da_wps_send_get_user_agent_req
* DESCRIPTION
*   get User Agent
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static BOOL mmi_da_wps_send_http_auth_res(U8 request_id, U8 *username, U8 *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct * p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p = (wps_http_auth_res_struct *) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);

    p->channel_id = da_wps_context.channel_id;
    p->request_id = request_id + MMI_DA_WPS_REQUEST_ID_BASE;
    strcpy((S8*)p->username, (S8*)username);
    strcpy((S8*)p->password, (S8*)password);

    mmi_da_send_ilm(p, NULL, MSG_ID_WPS_HTTP_AUTH_RES, MOD_WPS);
    return MMI_TRUE;

}


#if defined(MMI_DA_WPS_SLOW_BG_DL_SUPPORT)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*   void
*****************************************************************************/
static void _mmi_da_wps_timer_handler(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_wps_session  *session;
    S32                 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = (S32)param;

    if(id < 0 || id >= MMI_DA_WPS_REQUEST_ID_RANGE)
        return;

    session = da_wps_context.session_table[id];

    if(!session || session->state != MMI_DA_WPS_SESSION_STATE_HTTP_REQUEST)
        return;

    mmi_da_wps_send_dl_progress_res(session->request_id, session->seq_num);
}
#endif /* MMI_DA_WPS_SLOW_BG_DL_SUPPORT */

#endif /* __MMI_DOWNLOAD_AGENT__ */


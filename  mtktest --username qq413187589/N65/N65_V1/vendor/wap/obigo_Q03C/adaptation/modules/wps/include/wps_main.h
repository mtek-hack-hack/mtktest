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
 *   wps_main.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file comprise WPS module constant/enum/global context structure
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

#ifndef _wps_main_h
#define _wps_main_h

/************************************************************
 * Constants
 ************************************************************/
#define WPS_MAX_CHANNELS         4
#define WPS_MAX_REQUESTS         3
#define WPS_MAX_X509_CA_QUERY    1

#define WPS_FLAG_FILE_NO_PROG_IND        0x01
#define WPS_FLAG_FILE_RESUME             0x02

/************************************************************
 * Macro
 ************************************************************/
#define WPS_GET_CHANNEL_ID wps_get_channel_id
#define WPS_GET_REQUEST_ID wps_get_request_id

/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef enum
{
    WPS_CHANNEL_DEACTIVATED,
    WPS_CHANNEL_ACTIVATED
} wps_channel_state_enum;

typedef enum
{
    WPS_REQ_NULL,
    WPS_REQ_POSTING,
    WPS_REQ_WAIT_RSP,
    WPS_REQ_RSP_SENT,
    WPS_REQ_WAIT_CONTENT,
    WPS_REQ_CANCELING,
    WPS_REQ_CONNECTING,
    WPS_REQ_CONNECTED
} wps_request_state_enum;

typedef enum
{
    WPS_READ_SEGMENT,
    WPS_READ_SOURCE_CLOSED,
    WPS_READ_DELAYED,
    WPS_READ_UNKNOWN_ERROR
} wps_read_pipe_result_enum;

typedef enum
{
    WPS_WRITE_SEGMENT,
    WPS_WRITE_SOURCE_CLOSED,
    WPS_WRITE_DELAYED,
    WPS_WRITE_UNKNOWN_ERROR
} wps_write_pipe_result_enum;

typedef struct
{
    kal_uint8 idx;
    kal_uint8 channel_id;
    kal_uint8 request_id;
    int stk_request_id;
    kal_uint8 state;
    kal_uint8 *url;
    kal_uint8 reply_type;
    kal_wchar *reply_path;
    kal_wchar *post_path;
    kal_uint32 post_total_len;
    kal_uint8 method;
    kal_uint8 *req_header;
    kal_uint32 acc_size;
    kal_uint8 *buff;
    kal_uint32 buff_pos;
    kal_uint32 post_buff_size;
    kal_bool more_post;
    kal_uint32 assigned_reply_buff_size; /* The buffer size assigned by application */
    kal_uint32 reply_buff_size;
    int pipe_handle;
    int file_handle;
    kal_uint8 seq_num;
    stk_http_reply_t *rep;
    kal_uint8 *username;
    kal_uint8 *password;
    kal_uint8 ind_sent;
    /* For SSL connection */
    int send_pipe_handle;
    kal_uint8 *send_buff;
    kal_uint32 send_buff_pos;
    kal_uint32 send_buff_size;
    kal_uint8 send_seq_num;
    char *recv_pipe_name;
    kal_int32 last_error;
    kal_uint8 flag;
} wps_req_info_struct;

typedef struct
{
    module_type mod_id;
    kal_uint8 channel_id;
    kal_uint8 conn_type;
    kal_uint32 net_id;
    kal_int32 socket_id;
    kal_int32 security_id;
    kal_uint8 *static_header;
    kal_uint32 timeout;
    kal_uint8 *server_auth_username;
    kal_uint8 *server_auth_password;
    wps_req_info_struct *request_info[WPS_MAX_REQUESTS];
} wps_chl_info_struct;

typedef struct wps_ses_job_st
{
    struct wps_ses_job_st *next;
    int request_id;
    MSF_INT16 src;
} wps_ses_job_struct;

typedef struct
{
    wps_chl_info_struct *channel_info[WPS_MAX_CHANNELS];
    wps_ses_job_struct *wps_ses_queued_requests;
} wps_context_struct;

/************************************************************
 * Global variables declaration
 ************************************************************/

extern jmp_buf wps_jmp_buf;
extern int wps_inside_run;
extern wps_context_struct g_wps_cntx;

/************************************************************
 * Function declaration
 ************************************************************/

extern void wps_initial(void);

extern void wps_terminate(void);

extern void wps_clear_request_buff(wps_req_info_struct *req_info);

extern void wps_clear_send_request_buff(wps_req_info_struct *req_info);

extern int wps_get_available_channel(void);

extern wps_chl_info_struct *wps_create_channel(kal_uint8 channel_id);

extern void wps_clear_request(kal_uint8 channel_id, kal_uint8 request_idx);

extern void wps_clear_channel(kal_uint8 channel_id);

extern wps_req_info_struct *wps_create_request(kal_uint8 channel_id, kal_uint8 request_id);

extern void wps_read_reply_content(wps_req_info_struct *req_info);

extern void wps_write_post_content(wps_req_info_struct *req_info);

extern void wps_write_to_sink(wps_req_info_struct *req_info);

extern void wps_http_reply(stk_http_reply_t *p);

extern void wps_http_abort(stk_http_request_aborted_t *p);

extern void wps_pipe_notify(msf_pipe_notify_t *p);

extern void wps_handle_command(msf_module_execute_cmd_t *p);

extern int wps_channel_in_use(int net_id);

extern int wps_get_channel_id(int stk_request_id);

extern int wps_get_request_id(int stk_request_id);

extern void wps_hold_bearer(int net_id);

extern void wps_release_bearer(int net_id);

#ifdef WAP_SEC_SUPPORT
extern void wps_get_session_info_rsp(sec_get_session_info_response_t *p);

extern void wps_get_current_cert_rsp(sec_get_current_cert_response_t *p);

extern void wps_verify_cert_chain_rsp(sec_verify_cert_chain_response_t *p);

extern void wps_get_cert_ids_rsp(sec_get_cert_ids_response_t *p);

extern void wps_get_cert_rsp(sec_get_cert_response_t *p);

#endif /* WAP_SEC_SUPPORT */ 

extern void wps_http_auth_ind(wps_http_auth_ind_t *p);

extern void wps_stream_connection_created(stk_stream_connection_created_t *p);

extern void wps_stream_connection_closed(stk_connection_closed_t* p);

#endif /* _wps_main_h */ 


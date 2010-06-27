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

/*******************************************************************************
 * Filename:
 * ---------
 *  inet_msg_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines structs in inet message library.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _INET_MSG_STRUCT_H
#define _INET_MSG_STRUCT_H

typedef void *(*inet_mem_alloc_fn) (kal_uint32);
typedef void (*inet_mem_free_fn) (void *);

/***************************************************************************** 
* Typedef Struct: Fundamental Structure
*****************************************************************************/

typedef struct
{
    kal_char *name;
    kal_char *value;
} inet_param_struct;

typedef struct inet_param_list_st
{
    inet_param_struct *object;
    struct inet_param_list_st *next;
} inet_param_list_struct;

typedef struct
{
    kal_int32 value;
} inet_int_struct;

typedef struct inet_int_list_st
{
    kal_int32 value;
    struct inet_int_list_st *next;
} inet_int_list_struct;

typedef struct
{
    kal_int32 value;
    struct inet_param_list_struct *param_list;
} inet_int_param_struct;

typedef struct inet_int_param_list_st
{
    inet_int_param_struct *object;
    struct inet_int_param_list_st *next;
} inet_int_param_list_struct;

typedef struct
{
    kal_char *value;
} inet_str_struct;

typedef struct inet_str_list_st
{
    kal_char *value;
    struct inet_str_list_st *next;
} inet_str_list_struct;

typedef struct
{
    kal_char *value;
    inet_param_list_struct *param_list;
} inet_str_param_struct;

typedef struct inet_str_param_list_st
{
    inet_str_param_struct *object;
    struct inet_str_param_list_st *next;
} inet_str_param_list_struct;

typedef struct
{
    kal_int32 int_value;
    kal_char *str_value;
} inet_int_str_struct;

typedef struct inet_int_str_list_st
{
    inet_int_str_struct *object;
    struct inet_int_str_list_st *next;
} inet_int_str_list_struct;

typedef struct
{
    inet_uri_scheme_enum scheme;
    kal_char *scheme_str;   /* for unrecognized scheme */
    kal_char *host;
    kal_char *path;
    kal_uint16 port;
    inet_param_list_struct *param_list;
} inet_uri_struct;

typedef struct
{
    inet_auth_type_enum auth_type;
    inet_int_str_struct algorithm;
    kal_uint8 stale;
    kal_char *realm;
    inet_str_list_struct *domains;
    kal_char *nonce;
    kal_char *opaque;
    inet_int_str_list_struct *qop;
    inet_param_list_struct *param_list;
} inet_authenticate_struct;

typedef struct
{
    kal_uint8 auth_type;
    kal_char *username;
    kal_char *realm;
    kal_char *nonce;
    kal_char *digest_uri;
    kal_char *response;
    inet_auth_algorithm_enum algo;
    kal_char *cnonce;
    kal_char *opaque;
    inet_auth_qop_enum qop;
    kal_char *nc;
} inet_authorization_struct;

typedef struct
{
    kal_char *next_nonce;
    kal_char *cnonce;
    kal_char *rspauth;
    inet_int_str_list_struct *qop;
    kal_uint32 nc;
} inet_authentication_info_struct;

typedef struct
{
    kal_uint32 disp_charset;
    kal_char *display_name;
    inet_uri_struct *uri;
    inet_param_list_struct *param_list;
} inet_addr_struct;

typedef struct inet_addr_list_st
{
    inet_addr_struct *object;
    struct inet_addr_list_st *next;
} inet_addr_list_struct;

typedef struct
{
    kal_char *unit_name;
    kal_int32 first_pos;        /*-1 means unknown */
    kal_int32 last_pos;         /*-1 means unknown */
    kal_int32 instance_length;  /*-1 means unknown */
} inet_content_range_struct;

typedef struct
{
    kal_char *name;
    kal_char *value;
    kal_uint8 version;
    kal_char *domain;
    kal_bool discard;
    kal_int32 max_age;
    kal_char *path;
    inet_int_list_struct *portlist;
    kal_bool secure;
    kal_uint32 expiry_time;
    kal_char *comment;
    kal_char *comment_url;
} inet_cookie_struct;

typedef struct inet_cookie_list_st
{
    inet_cookie_struct *object;
    struct inet_cookie_list_st *next;
} inet_cookie_list_struct;

typedef struct
{
    kal_char *mime_type;
    kal_char *mime_subtype;
    inet_param_list_struct *param_list;
} inet_content_type_struct;

typedef struct inet_content_type_list_st
{
    inet_content_type_struct *object;
    struct inet_content_type_list_st *next;
} inet_content_type_list_struct;

typedef struct
{
    kal_uint32 seq;
    kal_uint32 method;
    kal_char *method_str;   /* for unrecognized method *//* 0903 */
} inet_cseq_struct;

typedef struct
{
    kal_uint8 app_type;
    kal_char *proto_name;
    kal_char *version;
    kal_char *transport;
    kal_char *host;
    kal_uint16 port;
    kal_char *comment;
    inet_param_list_struct *param_list;
} inet_via_struct;

typedef struct inet_via_list_st
{
    inet_via_struct *object;
    struct inet_via_list_st *next;
} inet_via_list_struct;

typedef struct
{
    kal_bool isDateString;
    kal_uint32 time;
} inet_retry_after_struct;

typedef struct
{
    kal_uint32 expires;
    inet_param_list_struct *param_list;
} inet_session_expires_struct;  /* added by kevin */

typedef struct
{
    kal_char *event;
    inet_param_list_struct *param_list;
} inet_event_struct;    /* added by kevin */

typedef struct
{
    kal_char *state;
    inet_param_list_struct *param_list;
} inet_subscription_state_struct;   /* added by kevin */

typedef struct
{
    kal_char *answer_mode;
    inet_param_list_struct *param_list;
} inet_answer_mode_struct;  /* added by kevin */

typedef struct
{
    kal_char *call_id;
    inet_param_list_struct *param_list;
} inet_replaces_struct; /* added by kevin */

typedef struct
{
    kal_uint32 newmsgs;
    kal_uint32 oldmsgs;
    kal_bool is_urgent_present;
    kal_uint32 new_urgentmsgs;
    kal_uint32 old_urgentmsgs;
} inet_msg_context_struct;  /* added by kevin */

typedef struct
{
    kal_uint32 seq; /* sequence no in RSeq */
    inet_cseq_struct *cseq;
} inet_rack_struct; /* added by kevin */

typedef struct
{
    double ts;              /* timestamp in second */
    kal_bool delay_present;
    double delay;           /* delay in second */
} inet_timestamp_struct;    /* added by kevin */

typedef struct
{
    kal_uint8   bearer;             /* INET_TRANS_UDP or INET_TRANS_TCP or INET_TRANS_UNRECOGNIZED*/
    kal_uint8   cast_type;          /* inet_transport_broadcase_type_enum */
    kal_uint16  client_port_start;
    kal_uint16  client_port_end;
    kal_uint16  server_port_start;
    kal_uint16  server_port_end;
} inet_rtsp_transport_struct;

typedef struct
{
    kal_uint64  start;              /* now = INET_MSG_RTSP_RANGE_NOW */
    kal_uint64  end;                /* na = INET_MSG_RTSP_RANGE_NA */
} inet_rtsp_range_struct;


typedef struct
{
    kal_char *url;
    kal_uint16 seq;
    kal_uint32 rtptime;
} inet_rtsp_rtpinfo_element_struct;


typedef struct inet_rtsp_rtpinfo_
{
    inet_rtsp_rtpinfo_element_struct  *object;
    struct inet_rtsp_rtpinfo_ *next;
} inet_rtsp_rtpinfo_struct;

typedef struct
{
    kal_char *protocol;
    inet_param_list_struct *param_list;
} inet_reason_struct;

typedef struct inet_reason_list_st
{
    inet_reason_struct *object;
    struct inet_reason_list_st *next;
} inet_reason_list_struct;


/***************************************************************************** 
* Typedef Struct
*****************************************************************************/
typedef struct
{
    module_type mod_id;
    inet_mem_alloc_fn alloc_fn;
    inet_mem_free_fn free_fn;
} inet_mem_func_struct;

typedef struct inet_header_st
{
    inet_header_field_enum header_id;
    kal_char *header_name;
    kal_uint32 value;                       /* value may store pointer, the details can be found the following table */
    struct inet_header_st *next_dup_hdr;    /* for duplicate header node */
} inet_header_struct;

typedef struct inet_header_list_st
{
    inet_header_struct *object;
    struct inet_header_list_st *next;
} inet_header_list_struct;

typedef struct
{
    inet_header_list_struct *header_list;
    inet_data_type_enum data_type;
    kal_wchar *body_file;
    kal_char *body_buf;    
    kal_uint32 body_file_offset;
    kal_int32 body_len;
} inet_body_struct;

typedef struct inet_body_list_st
{
    inet_body_struct *object;
    struct inet_body_list_st *next;
} inet_body_list_struct;

typedef struct
{
    kal_uint8 app_type; /* kevin */
    inet_mem_func_struct mem_func;
    kal_wchar *filepath;
    kal_wchar *folder_store_bodies;
    inet_header_list_struct *header_list;
    inet_body_list_struct *body_list;
} inet_message_struct;

typedef struct
{
    kal_uint32 type;
    kal_char compact;
} inet_compact_header_table_struct;

typedef struct
{
    inet_mem_func_struct mem_func;
    inet_data_type_enum data_type;
    kal_char *buffer;
    kal_char *pos;
    kal_uint32 size;
    kal_wchar *file_path;
    kal_int32 file_handle;
    kal_uint32 file_pos;    
    kal_uint32 file_size;
    kal_char *file_buf; //Woking buffer
    kal_char *file_buf_pos; //Woking buffer
    kal_uint32 file_buf_size; //Woking buffer
    inet_result_enum last_error;
} inet_mem_struct;

typedef struct
{
    kal_wchar *filepath;
    kal_int32 handle;
    kal_uint32 pos;
} inet_file_struct;

/* Mempry function */
typedef void (*inet_struct_free_fn) (inet_mem_func_struct *, void *);
typedef void *(*inet_struct_copy_fn) (inet_mem_func_struct *mem_func, void *src);

/* Pack function */
typedef inet_result_enum(*inet_header_pack_fn)
    (kal_uint8 app_type, void *arg, kal_char *buf, kal_int32 buf_len, kal_int32 *r_size);

/* Unpack function */
typedef kal_uint32(*inet_header_unpack_fn)
    (kal_uint8 app_type, inet_mem_func_struct *mem_func, kal_char *field_value);

/* Header value add to link list function, it can be used in addr_list */
typedef kal_bool(*inet_header_value_add_to_list_fn) (kal_uint32 value_list_head, kal_uint32 value_node);

#endif /* _INET_MSG_STRUCT_H */ 


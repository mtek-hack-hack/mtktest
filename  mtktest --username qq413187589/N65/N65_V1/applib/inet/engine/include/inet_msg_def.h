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
 *  inet_msg_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains data strcutures, enum and definitions in inet message library.
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
#ifndef _INET_MSG_DEF_H
#define _INET_MSG_DEF_H

/* if some header should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included before inet_msg_def.h"
#endif 

#define win32
/***************************************************************************** 
* Define
*****************************************************************************/

/* INET Pack and npack Mode Constants:
   These constants are used to indicate the pack/unpack policies. */
#define INET_MSG_PACK_REQ_STATUS_LINE  0x01
#define INET_MSG_PACK_HEADER  0x02
#define INET_MSG_PACK_BODY 0x04
#define INET_MSG_PACK_BODY_TO_MEM   0x08
#define INET_MSG_PACK_BODY_TO_FILE  0x10
#define INET_MSG_UNPACK_REQ_STATUS_LINE 0x20
#define INET_MSG_UNPACK_HEADER   0x40
#define INET_MSG_UNPACK_HEADER_MERGE   0x80     /* Merge the same header to one, if the header value can be multiple */
#define INET_MSG_UNPACK_BODY  0x100
#define INET_MSG_UNPACK_BODY_TO_MEM 0x200
#define INET_MSG_UNPACK_BODY_TO_FILE   0x400
#define INET_MSG_UNPACK_BODY_TO_VFILE   0x800

#define INET_MSG_WORKING_BUF_SIZE 3072

/* INET Process Part Type Constants:
   These constants are used to indicate the prcess part in pack/unpack operations. */
#define INET_MSG_PROCESS_HEADER  0x01
#define INET_MSG_PROCESS_BODY 0x02



/* INET Content-Encoding Constant:
   This constants are used to indicate the content-encoding constant. */
#define INET_MSG_CONTENT_ENCODING_UNRECOGNIZED  0x00
#define INET_MSG_CONTENT_ENCODING_GZIP 0x01
#define INET_MSG_CONTENT_ENCODING_COMPRESS   0x02
#define INET_MSG_CONTENT_ENCODING_DEFLATE 0x04
#define INET_MSG_CONTENT_ENCODING_IDENTITY   0x08

/* INET Transfer-Encoding Constant:
   This constants are used to indicate the transfer-encoding constant. */
#define INET_MSG_TRANSFER_ENCODING_UNRECOGNIZED 0x00
#define INET_MSG_TRANSFER_ENCODING_CHUNK  0x01

/* INET Authenticate Type Constant
   This constant are used to indicate the authentication type. */
#define INET_MSG_AUTH_TYPE_WWW_AUTH 0x01
#define INET_MSG_AUTH_TYPE_PROXY_AUTH  0x02

/* INET Header Field Value Form Constants
   This constants are used to indicate the header field value form. */
#define INET_MSG_HDR_VAL_STRUCT  0x01
#define INET_MSG_HDR_VAL_STRING  0x02

#define INET_HDR_IM_ADD_TO_FIRST 0x01
#define INET_HDR_IM_ADD_TO_LAST  0x02
#define INET_HDR_IM_MV_DUP_FIRST 0x04
#define INET_HDR_IM_MV_DUP_LAST  0x08
#define INET_HDR_IM_MERGE  0x10 /* Merge the same header */

#ifdef WIN32
#define INET_MSG_ASSERT(x) printf("ASSERT")
#define INET_MSG_EASSERT(x,a1,a2,a3)   printf("ASSERT")
#define INET_MSG_ASSERT_DBG(x)   printf("ASSERT")
#define INET_MSG_EASSERT_DBG(x,a1,a2,a3)  printf("ASSERT")
#define INET_MSG_LOG(x)  printf("ASSERT")
#else /* WIN32 */ 
#define INET_MSG_ASSERT(x) ASSERT(x)
#define INET_MSG_EASSERT(x,a1,a2,a3)   EXT_ASSERT(x,a1,a2,a3)
#define INET_MSG_ASSERT_DBG(x)   ASSERT(x)
#define INET_MSG_EASSERT_DBG(x,a1,a2,a3)  EXT_ASSERT(x,a1,a2,a3)
#define INET_MSG_LOG(x)  kal_prompt_trace(MOD_MMI,x)
#endif /* WIN32 */ 

/***************************************************************************** 
* Typedef Enum
*****************************************************************************/

typedef enum
{
    INET_MSG_APP_SIP = 0,
    INET_MSG_APP_HTTP,
    INET_MSG_APP_EMAIL,
    INET_MSG_APP_RTSP,
    INET_MSG_APP_NUM
} inet_app_enum;

typedef enum
{
    INET_RES_PACK_FN = 0,
    INET_RES_UNPACK_FN,
    INET_RES_COPY_FN,
    INET_RES_FREE_FN,
    INET_RES_VAL_ADD_FN,
    INET_RES_HDR_STR,
    INET_RES_NUM
} inet_res_type_enum;

/* This enum is used to indicate the transport protocol. */
typedef enum
{
    INET_TRANS_UDP = 0,
    INET_TRANS_TCP,
    INET_TRANS_TLS,
    INET_TRANS_SCTP,
    INET_TRANS_NUM,
    INET_TRANS_UNRECOGNIZED
} inet_transport_enum;

typedef enum
{
    INET_RESULT_OK,
    INET_RESULT_INVALID_REQ_ID,
    INET_RESULT_UNSUPPORTED_METHOD,
    INET_RESULT_BEARER_ERROR,
    INET_RESULT_SOCKET_ERROR,
    INET_RESULT_FS_ERROR,
    INET_RESULT_FS_INVALID_FILE_PATH,     
    INET_RESULT_FS_INVALID_ACCESS,         
    INET_RESULT_FS_FULL,
    INET_RESULT_FS_EXIST,
    INET_RESULT_FS_INVALID_FILE_SIZE,    
    INET_RESULT_MSG_TOO_LARGE,
    INET_RESULT_MSG_UNPACK_ERROR,
    INET_RESULT_MSG_PACK_ERROR,
    INET_RESULT_WOULDBLOCK,
    INET_RESULT_HEADER_NOT_FOUND,
    INET_RESULT_HEADER_LIST_NOT_FOUND,
    INET_RESULT_BODY_NOT_FOUND,
    INET_RESULT_BODY_LIST_NOT_FOUND,
    INET_RESULT_NO_MEMORY,
    INET_RESULT_NO_WORKING_BUF,
    INET_RESULT_NO_ENBUF,
    INET_RESULT_NO_RESOURCE,
    INET_RESULT_NO_INET_MSG,
    INET_RESULT_INVALID_PARAM,
    INET_RESULT_OP_EXIST,
    INET_RESULT_OP_NOT_ALLOW,
    INET_RESULT_ERROR
} inet_result_enum;

typedef enum
{
    INET_METHOD_SIP_REGISTER,
    INET_METHOD_SIP_INVITE,
    INET_METHOD_SIP_REFER,
    INET_METHOD_SIP_UPDATE,
    INET_METHOD_SIP_CANCEL,
    INET_METHOD_SIP_MESSAGE,
    INET_METHOD_SIP_ACK,
    INET_METHOD_SIP_BYE,
    INET_METHOD_SIP_OPTIONS,
    INET_METHOD_SIP_SUBSCRIBE,
    INET_METHOD_SIP_NOTIFY,
    INET_METHOD_SIP_PUBLISH,
    INET_METHOD_SIP_INFO,
    INET_METHOD_SIP_PRACK,
    INET_METHOD_HTTP_GET,
    INET_METHOD_HTTP_POST,
    INET_METHOD_HTTP_TRACE,
    INET_METHOD_HTTP_HEAD,
    INET_METHOD_HTTP_PUT,
    INET_METHOD_HTTP_DELETE,
    INET_METHOD_HTTP_CONNECT,
    INET_METHOD_RTSP_OPTIONS,
    INET_METHOD_RTSP_REDIRECT,
    INET_METHOD_RTSP_DESCRIBE,
    INET_METHOD_RTSP_SETUP,
    INET_METHOD_RTSP_PLAY,
    INET_METHOD_RTSP_PAUSE,
    INET_METHOD_RTSP_TEARDOWN,
    INET_METHOD_RTSP_SET_PARAMETER,
    INET_METHOD_UNRECOGNIZED,
    INET_METHOD_NUM
} inet_method_enum;

typedef enum
{
    INET_HDR_ACCEPT,                    /* 0 */
    INET_HDR_ACCEPT_CHARSET,            /* 01 */
    INET_HDR_ACCEPT_CONTACT,            /* 02 */
    INET_HDR_ACCEPT_ENCODING,           /* 03 */
    INET_HDR_ACCEPT_LANGUAGE,           /* 04 */
    INET_HDR_ACCEPT_RANGES,             /* 05 */
    INET_HDR_AGE,                       /* 06 */
    INET_HDR_ALERT_INFO,                /* 07 */
    INET_HDR_ALLOW,                     /* 08 */
    INET_HDR_AUTH_INFO,                 /* 09 */
    INET_HDR_AUTHORIZATION,             /* 10 */
    INET_HDR_CACHE_CONTROL,             /* 11 */
    INET_HDR_CALL_ID,                   /* 12 */
    INET_HDR_CONTACT,                   /* 13 */
    INET_HDR_CONNECTION,                /* 14 */
    INET_HDR_CONTENT_DISPOSITION,       /* 15 */
    INET_HDR_CONTENT_ENCODING,          /* 16 */
    INET_HDR_CONTENT_LANGUAGE,          /* 17 */
    INET_HDR_CONTENT_LENGTH,            /* 18 */
    INET_HDR_CONTENT_TYPE,              /* 19 */
    INET_HDR_CONTENT_ID,                /* 20 */
    INET_HDR_CONTENT_LOCATION,          /* 21 */
    INET_HDR_CONTENT_MD5,               /* 22 */
    INET_HDR_CONTENT_RANGE,             /* 23 */
    INET_HDR_CONTENT_TRANSER_ENCODING,  /* 24 */
    INET_HDR_COOKIE,                    /* 25 */
    INET_HDR_CSEQ,                      /* 26 */
    INET_HDR_DATE,                      /* 27 */
    INET_HDR_ERROR_INFO,                /* 28 */
    INET_HDR_EXPECT,                    /* 29 */
    INET_HDR_EXPIRES,                   /* 30 */
    INET_HDR_ETAG,                      /* 31 */
    INET_HDR_FROM,                      /* 32 */
    INET_HDR_HOST,                      /* 33 */
    INET_HDR_IF_MATCH,                  /* 34 */
    INET_HDR_IF_MODIFIED_SINCE,         /* 35 */
    INET_HDR_IF_NONE_MATCH,             /* 36 */
    INET_HDR_IF_RANGE,                  /* 37 */
    INET_HDR_IF_UNMODIFIED_SINCE,       /* 38 */
    INET_HDR_IN_REPLY_TO,               /* 39 */
    INET_HDR_LAST_MODIFIED,             /* 40 */
    INET_HDR_LOCATION,                  /* 41 */
    INET_HDR_MAX_FORWARDS,              /* 42 */
    INET_HDR_METHOD,                    /* 43 */
    INET_HDR_MIN_EXPIRES,               /* 44 */
    INET_HDR_MIME_VERSION,              /* 45 */
    INET_HDR_ORGANIZATION,              /* 46 */
    INET_HDR_PRAGMA,                    /* 47 */
    INET_HDR_PRIORITY,                  /* 48 */
    INET_HDR_PROXY_AUTHENTICATE,        /* 49 */
    INET_HDR_PROXY_AUTHORIZATION,       /* 50 */
    INET_HDR_PROXY_REQUIRE,             /* 51 */
    INET_HDR_RANGE,                     /* 52 */
    INET_HDR_REASON_PHRASE,             /* 53 */
    INET_HDR_RECORD_ROUTE,              /* 54 */
    INET_HDR_REPLY_TO,                  /* 55 */
    INET_HDR_REFER,                     /* 56 */
    INET_HDR_REFER_TO,                  /* 57 */
    INET_HDR_REQUIRE,                   /* 58 */
    INET_HDR_RESP_CODE,                 /* 59 */
    INET_HDR_RETRY_AFTER,               /* 60 */
    INET_HDR_ROUTE,                     /* 61 */
    INET_HDR_SERVER,                    /* 62 */
    INET_HDR_SET_COOKIE,                /* 63 */
    INET_HDR_SET_COOKIE2,               /* 64 */
    INET_HDR_SESSION_EXPIRES,           /* 65 */
    INET_HDR_SUBJECT,                   /* 66 */
    INET_HDR_SUPPORTED,                 /* 67 */
    INET_HDR_TIMESTAMP,                 /* 68 */
    INET_HDR_TRAILER,                   /* 69 */
    INET_HDR_TRANSFER_ENCODING,         /* 70 */
    INET_HDR_TE,                        /* 71 */
    INET_HDR_TO,                        /* 72 */
    INET_HDR_UNSUPPORTED,               /* 73 */
    INET_HDR_UPGRADE,                   /* 74 */
    INET_HDR_URI,                       /* 75 */
    INET_HDR_USER_AGENT,                /* 76 */
    INET_HDR_VIA,                       /* 77 */
    INET_HDR_VARY,                      /* 78 */
    INET_HDR_WARNING,                   /* 79 */
    INET_HDR_WWW_AUTHENTICATE,          /* 80 */
    INET_HDR_REQUEST_URI,               /* 81 */
    INET_HDR_START_LINE_PROTO,          /* 82 */
    INET_HDR_MIN_SE,                    /* 83 */
    INET_HDR_EVENT,                     /* 84 */
    INET_HDR_SUBSCRIPTION_STATE,        /* 85 */
    INET_HDR_SIP_IF_MATCH,              /* 86 */
    INET_HDR_SIP_ETAG,                  /* 87 */
    INET_HDR_P_ALERTING_MODE,           /* 88 */
    INET_HDR_P_PREFERRED_IDENTITY,      /* 89 */
    INET_HDR_PRIVACY,                   /* 90 */
    INET_HDR_PRIV_ANSWER_MODE,          /* 91 */
    INET_HDR_ANSWER_MODE,               /* 92 */
    INET_HDR_REFERRED_BY,               /* 93 */
    INET_HDR_REPLACES,                  /* 94 */
    INET_HDR_JOIN,                      /* 95 */
    INET_HDR_ALLOW_EVENTS,              /* 96 */
    INET_HDR_MSG_WAITING,               /* 97 */
    INET_HDR_MSG_ACCOUNT,               /* 98 */
    INET_HDR_MW_VOICE_MSG,              /* 99 */
    INET_HDR_MW_FAX_MSG,                /* 100 */
    INET_HDR_MW_PAGER_MSG,              /* 101 */
    INET_HDR_MW_MM_MSG,                 /* 102 */
    INET_HDR_MW_TEXT_MSG,               /* 103 */
    INET_HDR_MW_NONE_MSG,               /* 104 */
    INET_HDR_RACK,                      /* 105 */
    INET_HDR_RSEQ,                      /* 106 */
    INET_HDR_SESSION,                   /* 107 */    
    INET_HDR_TRANSPORT,                 /* 108 */    
    INET_HDR_RTPINFO,                   /* 109 */
    INET_HDR_REASON,                    /* 110 */
    INET_HDR_REJECT_CONTACT,            /* 111 */
    INET_HDR_UNRECOGNIZED,
    INET_HDR_NUM
} inet_header_field_enum;

typedef enum
{
    INET_CACHE_CONTROL_NO_CACHE,
    INET_CACHE_CONTROL_NO_STORE,
    INET_CACHE_CONTROL_NO_TRANSFORM,
    INET_CACHE_CONTROL_MAX_AGE,
    INET_CACHE_CONTROL_MAX_STALE,
    INET_CACHE_CONTROL_MIN_FRESH,
    INET_CACHE_CONTROL_MUST_REVALIDATE,
    INET_CACHE_CONTROL_ONLY_IF_CACHED,
    INET_CACHE_CONTROL_PROXY_REVALIDATE,
    INET_CACHE_CONTROL_PRIVATE,
    INET_CACHE_CONTROL_PUBLIC,
    INET_CACHE_CONTROL_S_MAXAGE,
    INET_CACHE_CONTROL_NUM,
    INET_CACHE_CONTROL_UNRECOGNIZED
} inet_cache_control_enum;

typedef enum
{
    INET_URI_SCHEME_SIP,
    INET_URI_SCHEME_SIPS,
    INET_URI_SCHEME_HTTP,
    INET_URI_SCHEME_HTTPS,
    INET_URI_SCHEME_RTSP,    
    INET_URI_SCHEME_CID,    /* kevin */
    INET_URI_SCHEME_TEL,    /* kevin */
    INET_URI_SCHEME_NUM,
    INET_URI_SCHEME_UNRECOGNIZED
} inet_uri_scheme_enum;

typedef enum
{
    INET_DATA_TYPE_MEMORY,
    INET_DATA_TYPE_FILE,
    INET_DATA_TYPE_VFILE    
} inet_data_type_enum;

/* Basic and Digest authentication mechanisms are defined in RFC2617: 
   HTTP Authentication Basic and Digest Access Authentication */
typedef enum
{
    INET_AUTH_BASIC,
    INET_AUTH_DIGEST,
    INET_AUTH_UNSUPPORT
} inet_auth_type_enum;

/* MD5 and MD5-Session are defined in RFC2617: 
   HTTP Authentication Basic and Digest Access Authentication */
typedef enum
{
    INET_AUTH_ALGO_UNSPECIFIED,
    INET_AUTH_ALGO_MD5,
    INET_AUTH_ALGO_MD5_SESS,
    INET_AUTH_ALGO_UNSUPPORT
} inet_auth_algorithm_enum;

/* Auth and Auth-Integrity are defined in RFC2617: 
   HTTP Authentication Basic and Digest Access Authentication */
typedef enum
{
    INET_AUTH_QOP_UNSPECIFIED,
    INET_AUTH_QOP_AUTH,
    INET_AUTH_QOP_AUTH_INT,
    INET_AUTH_QOP_UNSUPPORT
} inet_auth_qop_enum;

typedef enum
{
    inet_kal_uint32_struct_,
    inet_kal_string_struct_,
    inet_param_struct_,
    inet_param_list_struct_,
    inet_int_struct_,
    inet_int_list_struct_,
    inet_int_param_struct_,
    inet_int_param_list_struct_,
    inet_str_struct_,
    inet_str_list_struct_,
    inet_str_param_struct_,
    inet_str_param_list_struct_,
    inet_int_str_struct_,
    inet_int_str_list_struct_,
    inet_uri_struct_,
    inet_authenticate_struct_,
    inet_authorization_struct_,
    inet_authentication_info_struct_,
    inet_addr_struct_,
    inet_addr_list_struct_,
    inet_content_range_struct_,
    inet_cookie_struct_,
    inet_cookie_list_struct_,
    inet_content_type_struct_,
    inet_content_type_list_struct_,
    inet_cseq_struct_,
    inet_via_struct_,
    inet_via_list_struct_,
    inet_retry_after_struct_,
    inet_session_expires_struct_,
    inet_event_struct_,
    inet_subscription_state_struct_,
    inet_answer_mode_struct_,
    inet_struct_num
} inet_struct_enum;

typedef enum
{
    INET_STATUS_IDLE,
    INET_STATUS_PROCESSING,
    INET_STATUS_FILE_WRITING,
    INET_STATUS_FILE_READING,
    INET_STATUS_UNPACK_HDR,
    INET_STATUS_UNPACK_BODY,
    INET_STATUS_PACK_HDR,
    INET_STATUS_PACK_BODY
} inet_status_enum;

typedef enum
{
    INET_TRANSPORT_CAST_UNI,
    INET_TRANSPORT_CAST_MULTI,        
    INET_TRANSPORT_CAST_NONE
} inet_transport_broadcase_type_enum;

#define CHECK_INET_PARAM(x,y) \
{                             \
   if(!x){return y;}          \
}

#define CHECK_INET_PACK_ENBUF(x)          \
{                                         \
   if(x<0){return INET_RESULT_NO_ENBUF;}  \
}

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#endif /* _INET_MSG_DEF_H */ 


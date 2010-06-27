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
 *   wps_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains common definitions for WPS module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _wps_defs_h
#define _wps_defs_h

/************************************************************
 * Constants
 ************************************************************/
#define WPS_DEFAULT_PRX_PORT     8080
#define WPS_DEFAULT_WSP_CO_PORT  9201
#define WPS_DEFAULT_WSP_CL_PORT  9200
#define WPS_DEFAULT_READ_BUFF_SIZE 512
#define WPS_DEFAULT_FOLDER "/wps"

/************************************************************
 * Macro
 ************************************************************/
#define WPS_MAX_REPLY_FILE_PATH_LEN      256
#define WPS_MAX_POST_FILE_PATH_LEN       256
#define WPS_MAX_PUSH_FILE_PATH_LEN       256
#define WPS_MAX_USERNAME_LEN              30
#define WPS_MAX_PASSWORD_LEN              30
#define WPS_MAX_CONTENT_TYPE_LEN         256

#define WPS_DEFAULT_STK_AUTH_OPTIONS    STK_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD
#define WPS_CONN_TYPE_HTTP    1 /* STK_CONNECTION_TYPE_HTTP */
#define WPS_CONN_TYPE_WSP_CL  2 /* STK_CONNECTION_TYPE_WSP_CL */
#define WPS_CONN_TYPE_WSP_CO  3 /* STK_CONNECTION_TYPE_WSP_CO */
#define WPS_CONN_TYPE_TLS     4 /* STK_CONNECTION_TYPE_TLS */

#define WPS_HTTP_METHOD_GET   0x40      /* STK_METHOD_GET */
#define WPS_HTTP_METHOD_HEAD  0x42      /* STK_METHOD_HEAD */
#define WPS_HTTP_METHOD_POST  0x60      /* STK_METHOD_POST */
#define WPS_HTTP_METHOD_PUT   0x61      /* STK_METHOD_PUT */
#define WPS_HTTP_METHOD_DELETE 0x43     /* STK_METHOD_DELETE */

#define WPS_HTTP_OPTION_NO_CACHE             0x0001     /* STK_OPTION_NO_CACHE */
#define WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY   0x0002     /* STK_OPTION_DO_NOT_CACHE_REPLY */
#define WPS_HTTP_OPTION_ALWAYS_CACHE         0x0004     /* STK_OPTION_ALWAYS_CACHE */
#define WPS_HTTP_OPTION_CACHE_ONLY           0x0008     /* STK_OPTION_CACHE_ONLY */
#define WPS_HTTP_OPTION_STALE_CACHE          0x0010     /* STK_OPTION_STALE_CACHE */

#define WPS_HTTP_AUTH_SERVER                 1  /* STK_AUTH_SERVER */
#define WPS_HTTP_AUTH_PROXY                  2  /* STK_AUTH_PROXY */

#define WPS_CLEAR_CACHE_URL_MATCH   1   /* STK_CLEAR_CACHE_URL_MATCH */
#define WPS_CLEAR_CACHE_URL_PREFIX  2   /* STK_CLEAR_CACHE_URL_PREFIX */
#define WPS_CLEAR_CACHE_ALL         3   /* STK_CLEAR_CACHE_ALL */
#define WPS_CLEAR_AUTH_HOST         4   /* STK_CLEAR_AUTH_HOST */
#define WPS_CLEAR_AUTH_PROXY        5   /* STK_CLEAR_AUTH_PROXY */
#define WPS_CLEAR_AUTH_ALL          6   /* STK_CLEAR_AUTH_ALL */
#define WPS_CLEAR_COOKIES_ALL       7   /* STK_CLEAR_COOKIES_ALL */

#define WPS_PROTOCOL_WSP_CL                       1     /* STK_PROTOCOL_WSP_CL */
#define WPS_PROTOCOL_WSP_CL_WTLS                  2     /* STK_PROTOCOL_WSP_CL_WTLS */
#define WPS_PROTOCOL_WSP_CO                       3     /* STK_PROTOCOL_WSP_CO */
#define WPS_PROTOCOL_WSP_CO_WTLS                  4     /* STK_PROTOCOL_WSP_CO_WTLS */
#define WPS_PROTOCOL_HTTP                         5     /* STK_PROTOCOL_HTTP */
#define WPS_PROTOCOL_HTTP_TLS                     6     /* STK_PROTOCOL_HTTP_TLS */
#define WPS_PROTOCOL_HTTP_SSL                     7     /* STK_PROTOCOL_HTTP_SSL */
#define WPS_PROTOCOL_CACHE                        8     /* STK_PROTOCOL_CACHE */
#define WPS_PROTOCOL_FILE                         9     /* STK_PROTOCOL_FILE */
#define WPS_PROTOCOL_OTHER                        10    /* STK_PROTOCOL_OTHER */

/* The WTLS key exchange of cipher suite */
#define WPS_SEC_WTLS_KEY_EXCH_NULL              0
#define WPS_SEC_WTLS_KEY_EXCH_SHARED_SECRET     1
#define WPS_SEC_WTLS_KEY_EXCH_DH_ANON           2
#define WPS_SEC_WTLS_KEY_EXCH_DH_ANON_512       3
#define WPS_SEC_WTLS_KEY_EXCH_DH_ANON_768       4
#define WPS_SEC_WTLS_KEY_EXCH_RSA_ANON          5
#define WPS_SEC_WTLS_KEY_EXCH_RSA_ANON_512      6
#define WPS_SEC_WTLS_KEY_EXCH_RSA_ANON_768      7
#define WPS_SEC_WTLS_KEY_EXCH_RSA               8
#define WPS_SEC_WTLS_KEY_EXCH_RSA_512           9
#define WPS_SEC_WTLS_KEY_EXCH_RSA_768           10
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON         11
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON_113     12
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON_131     13
#define WPS_SEC_WTLS_KEY_EXCH_ECDH_ECDSA        14

/* The TLS key exchange of cipher suite */
#define WPS_SEC_TLS_KEYEXCH_NULL                          0
#define WPS_SEC_TLS_KEYEXCH_RSA                           1
#define WPS_SEC_TLS_KEYEXCH_RSA_EXPORT                    2
#define WPS_SEC_TLS_KEYEXCH_DH_DSS_EXPORT                 3
#define WPS_SEC_TLS_KEYEXCH_DH_DSS                        4
#define WPS_SEC_TLS_KEYEXCH_DH_RSA_EXPORT                 5
#define WPS_SEC_TLS_KEYEXCH_DH_RSA                        6
#define WPS_SEC_TLS_KEYEXCH_DHE_DSS_EXPORT                7
#define WPS_SEC_TLS_KEYEXCH_DHE_DSS                       8
#define WPS_SEC_TLS_KEYEXCH_DHE_RSA_EXPORT                9
#define WPS_SEC_TLS_KEYEXCH_DHE_RSA                       10
#define WPS_SEC_TLS_KEYEXCH_DH_ANON_EXPORT                11
#define WPS_SEC_TLS_KEYEXCH_DH_ANON                       12

/* The cipher algorithms of cipher suite */
#define WPS_SEC_CIPHER_NULL             0
#define WPS_SEC_CIPHER_RC5_CBC_40       1
#define WPS_SEC_CIPHER_RC5_CBC_56       2
#define WPS_SEC_CIPHER_RC5_CBC          3
#define WPS_SEC_CIPHER_DES_CBC_40       4
#define WPS_SEC_CIPHER_DES_CBC          5
#define WPS_SEC_CIPHER_3DES_CBC_EDE     6
#define WPS_SEC_CIPHER_IDEA_CBC_40      7
#define WPS_SEC_CIPHER_IDEA_CBC_56      8
#define WPS_SEC_CIPHER_IDEA_CBC         9
#define WPS_SEC_CIPHER_RC5_CBC_64      10
#define WPS_SEC_CIPHER_IDEA_CBC_64     11
#define WPS_SEC_CIPHER_RC2_CBC_40      20
#define WPS_SEC_CIPHER_RC4_40          21
#define WPS_SEC_CIPHER_RC4_128         22
#define WPS_SEC_CIPHER_AES_CBC_128     30

/* The hash algorithms of cipher suite */
#define WPS_SEC_HASH_NULL                  0
#define WPS_SEC_HASH_MD5                   1
#define WPS_SEC_HASH_SHA                   2
#define WPS_SEC_HASH_MD2                   3

#define WPS_SEC_CONNECTION_TYPE_TLS         1   /* SEC_CONNECTION_TYPE_TLS */
#define WPS_SEC_CONNECTION_TYPE_WTLS        2   /* SEC_CONNECTION_TYPE_WTLS */
#define WPS_SEC_CONNECTION_TYPE_SSL         3   /* SEC_CONNECTION_TYPE_WTLS */

#define WPS_SEC_CERT_FORMAT_WTLS              1 /* SEC_CERT_FORMAT_WTLS */
#define WPS_SEC_CERT_FORMAT_X509              2 /* SEC_CERT_FORMAT_WTLS */

#define WPS_SEC_GET_USER_CERT	1
#define WPS_SEC_GET_ROOT_CERT	2

#define WPS_DLG_ERROR               0 /* SEC_DLG_ERROR */
#define WPS_DLG_INFO                1 /* SEC_DLG_INFO */
#define WPS_DLG_ALERT               2 /* SEC_DLG_ALERT */

#define WPS_DLG_OK                  0 /* SEC_DLG_SELECT */
#define WPS_DLG_CANCEL              1 /* SEC_DLG_CANCEL */

#define WPS_DLG_BUTTON_OK           0
#define WPS_DLG_BUTTON_YESNO        1

#define WPS_SEC_KP_SERVER_AUTH             0x0001
#define WPS_SEC_KP_CLIENT_AUTH             0x0002
#define WPS_SEC_KP_CODE_SIGNING            0x0004
#define WPS_SEC_KP_EMAIL_PROTECTION        0x0008
#define WPS_SEC_KP_IPSEC_ENDSYSTEM         0x0010
#define WPS_SEC_KP_IPSEC_TUNNEL            0x0020
#define WPS_SEC_KP_IPSEC_USER              0x0040
#define WPS_SEC_KP_TIME_STAMPING           0x0080
#define WPS_SEC_KP_OCSP_SIGNING            0x0100

typedef enum
{
    WPS_OK,
    WPS_ERROR_UNKNOWN,   	
    WPS_ERROR_SEND,
    WPS_ERROR_INVALID_PARAM,
    WPS_ERROR_INVALID_HEADER,
    WPS_ERROR_INVALID_CHANNEL_ID,
    WPS_ERROR_INVALID_REQUEST_ID,
    WPS_ERROR_INVALID_SEQUENCE_NUM,
    WPS_ERROR_INVALID_DEFAULT_PROFILE,   
    WPS_ERROR_INACTIVE_CHANNEL,
    WPS_ERROR_INVALID_CONN_TYPE,   
    WPS_ERROR_NO_RESOURCE,
    WPS_ERROR_ACCESS_DENY,
    WPS_ERROR_PENDING_REQ_EXIST,
    WPS_ERROR_FILE_ACCESS,
    WPS_ERROR_REQ_ABORT,
    WPS_ERROR_NOT_FOUND,
    WPS_ERROR_REQ_MSG_TOO_LARGE,
    WPS_ERROR_REQ_NOT_SUPPORT,
    WPS_ERROR_DNS_RESOLVE,
    WPS_ERROR_USE_PROXY,
    WPS_ERROR_TLS_BAD_RECORD,
    WPS_ERROR_TLS_DECRYPTION_FAILED,
    WPS_ERROR_TLS_RECEIVED_ALERT,
    WPS_ERROR_TLS_HANDSHAKE_FAILURE,
    WPS_ERROR_TLS_UNSUPPORTED_CERT,
    WPS_ERROR_TLS_UNKNOWN_CA,
    WPS_ERROR_TLS_BAD_CERTIFICATE,
    WPS_ERROR_TLS_CERTIFICATE_EXPIRED,
    WPS_ERROR_TLS_INTERNAL_ERROR,
    WPS_ERROR_TLS_CANCEL
} wps_result_error_enum;

typedef enum
{
    WPS_SEC_OK,
    WPS_SEC_ERR_INSUFFICIENT_MEMORY,
    WPS_SEC_ERR_INVALID_PARAMETER,
    WPS_SEC_ERR_CRYPTOLIB_NOT_INITIALISED,
    WPS_SEC_ERR_INVALID_KEY,
    WPS_SEC_ERR_UNKNOWN_CERTIFICATE_TYPE,
    WPS_SEC_ERR_BAD_CERTIFICATE,
    WPS_SEC_ERR_CERTIFICATE_EXPIRED,
    WPS_SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE,
    WPS_SEC_ERR_GENERAL_ERROR
} wps_sec_result_error_enum;

typedef enum
{
    WPS_DATA_TYPE_BUFFER,
    WPS_DATA_TYPE_FILE,
    WPS_DATA_TYPE_FILE_NO_PROG_IND,
    WPS_DATA_TYPE_FILE_RESUME
} wps_data_type_enum;

typedef enum
{
    WPS_DL_STATUS_DOWNLOADING,
    WPS_DL_STATUS_COMPLETE,
    WPS_DL_STATUS_ABORT
} wps_dl_status_enum;

typedef enum
{
    WPS_PUN_PACK,
    WPS_PUN_UNPACK,
    WPS_PUN_SIZE
} wps_pun_enum;

typedef enum
{
    WPS_READY_STATUS_NULL,
    WPS_READY_STATUS_OK
} wps_ready_status_enum;

extern kal_int32 wps_pun_var_part(kal_uint8 op, kal_uint32 msg_id, void *p, kal_uint8 *buf);

#endif /* _wps_defs_h */ 

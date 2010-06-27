/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * stk_if.h
 *
 * Created by Anders Edenbrandt, Tue Apr 30 15:03:33 2002.
 *
 * Revision  history:
 *   020610, AED: Added server API, to support Push.
 *
 */
#ifndef _stk_if_h
#define _stk_if_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif

/**********************************************************************
 * Signals in the HTTP request API:
 **********************************************************************/

/* Signals sent to the Protocol Stack */
#define STK_SIG_CONFIGURE_CHANNEL                 ((MSF_MODID_STK << 8) + 0x01)
#define STK_SIG_CONFIGURE_PROXY_CHANNEL           ((MSF_MODID_STK << 8) + 0x02)
#define STK_SIG_REMOVE_CHANNEL                    ((MSF_MODID_STK << 8) + 0x03)
#define STK_SIG_HTTP_REQUEST                      ((MSF_MODID_STK << 8) + 0x04)
#define STK_SIG_CANCEL_REQUEST                    ((MSF_MODID_STK << 8) + 0x05)
#define STK_SIG_CLEAR                             ((MSF_MODID_STK << 8) + 0x06)
#define STK_SIG_SET_CACHE_CONTROL                 ((MSF_MODID_STK << 8) + 0x07)

/* Signals sent from the Protocol Stack */
#define STK_SIG_HTTP_REPLY                        ((MSF_MODID_STK << 8) + 0x08)
#define STK_SIG_HTTP_STATUS                       ((MSF_MODID_STK << 8) + 0x09)
#define STK_SIG_HTTP_REQUEST_ABORTED              ((MSF_MODID_STK << 8) + 0x0a)
#define STK_SIG_CLEAR_DONE                        ((MSF_MODID_STK << 8) + 0x0b)


/**********************************************************************
 * Signals in the lower-level messaging API:
 **********************************************************************/

/* Signals sent to the Protocol Stack */
#define STK_SIG_CREATE_CLIENT_CONNECTION          ((MSF_MODID_STK << 8) + 0x0c)
#define STK_SIG_CREATE_SERVER_CONNECTION          ((MSF_MODID_STK << 8) + 0x0d)
#define STK_SIG_CREATE_STREAM_CONNECTION          ((MSF_MODID_STK << 8) + 0x0e)
#define STK_SIG_CLOSE_CONNECTION                  ((MSF_MODID_STK << 8) + 0x0f)
#define STK_SIG_SEND_REQUEST                      ((MSF_MODID_STK << 8) + 0x10)
#define STK_SIG_SEND_REPLY                        ((MSF_MODID_STK << 8) + 0x11)
#define STK_SIG_ABORT_REQUEST                     ((MSF_MODID_STK << 8) + 0x12)
#define STK_SIG_CONFIRM_REQUEST                   ((MSF_MODID_STK << 8) + 0x13)


/* Signals sent from the Protocol Stack */
#define STK_SIG_CONNECTION_CREATED                ((MSF_MODID_STK << 8) + 0x14)
#define STK_SIG_STREAM_CONNECTION_CREATED         ((MSF_MODID_STK << 8) + 0x15)
#define STK_SIG_CONNECTION_CLOSED                 ((MSF_MODID_STK << 8) + 0x16)
#define STK_SIG_RECV_REQUEST                      ((MSF_MODID_STK << 8) + 0x17)
#define STK_SIG_RECV_REPLY                        ((MSF_MODID_STK << 8) + 0x18)
#define STK_SIG_REQUEST_ABORTED                   ((MSF_MODID_STK << 8) + 0x19)


/**********************************************************************
 * Other constants:
 **********************************************************************/

/* Channel options: */
#define STK_CHANNEL_OPTION_USE_WTP_SAR            0x01
#define STK_CHANNEL_OPTION_ALWAYS_SECURE          0x02

/* Default channel: */
#define STK_DEFAULT_CHANNEL                       0

/* HTTP request methods: */
#define STK_METHOD_GET                            0x40
#define STK_METHOD_OPTIONS                        0x41
#define STK_METHOD_HEAD                           0x42
#define STK_METHOD_DELETE                         0x43
#define STK_METHOD_TRACE                          0x44
#define STK_METHOD_POST                           0x60
#define STK_METHOD_PUT                            0x61
#define STK_METHOD_CONNECT                        0x80

/* HTTP request options: */
#define STK_OPTION_NO_CACHE                       0x0001
#define STK_OPTION_DO_NOT_CACHE_REPLY             0x0002
#define STK_OPTION_ALWAYS_CACHE                   0x0004
#define STK_OPTION_CACHE_ONLY                     0x0008
#define STK_OPTION_STALE_CACHE                    0x0010
#define STK_OPTION_REPORT_STATUS                  0x0020
#define STK_OPTION_REPLY_BUFFER                   0x0040
#define STK_OPTION_REPLY_FILE                     0x0080
#define STK_OPTION_APPEND_TO_FILE                 0x0100
#define STK_OPTION_DO_NOT_HANDLE_SERVER_AUTH      0x00008000
#define STK_OPTION_DO_NOT_HANDLE_PROXY_AUTH       0x00010000

/* Connection types */
#define STK_CONNECTION_TYPE_HTTP                  1
#define STK_CONNECTION_TYPE_WSP_CL                2
#define STK_CONNECTION_TYPE_WSP_CO                3
#define STK_CONNECTION_TYPE_SMS_DATA              4
#define STK_CONNECTION_TYPE_SMS_RAW               5
#define STK_CONNECTION_TYPE_TLS                   6
#define STK_CONNECTION_TYPE_WSP_CL_WTLS           7 /* Only used for Push sockets */
#define STK_CONNECTION_TYPE_HTTP_PUSH             8

/* Message body types */

#define STK_BODY_BUFFER                           MSF_CONTENT_DATA_RAW 
#define STK_BODY_PIPE                             MSF_CONTENT_DATA_PIPE
#define STK_BODY_FILE                             MSF_CONTENT_DATA_FILE
#define STK_BODY_NONE                             MSF_CONTENT_DATA_NONE


/*Protocol types */
#define STK_PROTOCOL_WSP_CL                       1
#define STK_PROTOCOL_WSP_CL_WTLS                  2
#define STK_PROTOCOL_WSP_CO                       3
#define STK_PROTOCOL_WSP_CO_WTLS                  4
#define STK_PROTOCOL_HTTP                         5
#define STK_PROTOCOL_HTTP_TLS                     6
#define STK_PROTOCOL_HTTP_SSL                     7
#define STK_PROTOCOL_CACHE                        8
#define STK_PROTOCOL_FILE                         9
#define STK_PROTOCOL_OTHER                        10


/*Clear operation*/
#define STK_CLEAR_CACHE_URL_MATCH                 1
#define STK_CLEAR_CACHE_URL_PREFIX                2
#define STK_CLEAR_CACHE_ALL                       3
#define STK_CLEAR_AUTH_HOST                       4
#define STK_CLEAR_AUTH_PROXY                      5
#define STK_CLEAR_AUTH_ALL                        6
#define STK_CLEAR_VOLATILE_AUTH                   7
#define STK_CLEAR_COOKIES_ALL                     8
#define STK_CLEAR_COOKIES_OLD                     9

#define STK_CLEAR_SIGNAL_WHEN_DONE                0x8000

/**********************************************************************
 * STK status codes
 **********************************************************************/

#define STK_STATUS_USING_NETWORK                  1
#define STK_STATUS_USING_CACHE                    2
#define STK_STATUS_USING_FILE                     3
#define STK_STATUS_CHECKING_IF_MODIFIED           4
#define STK_STATUS_REDIRECTING                    5
#define STK_STATUS_AUTH_REQUIRED                  6
#define STK_STATUS_RECEIVING_CONTENT              7


/**********************************************************************
 * HTTP status codes
 **********************************************************************/

#define STK_HTTP_CONTINUE                         100
#define STK_HTTP_SWITCHING_PROTOCOLS              101

#define STK_HTTP_OK                               200
#define STK_HTTP_CREATED                          201
#define STK_HTTP_ACCEPTED                         202
#define STK_HTTP_NON_AUTH_INFORMATION             203
#define STK_HTTP_NO_CONTENT                       204
#define STK_HTTP_RESET_CONTENT                    205
#define STK_HTTP_PARTIAL_CONTENT                  206

#define STK_HTTP_MULTIPLE_CHOICES                 300
#define STK_HTTP_MOVED_PERMANENTLY                301
#define STK_HTTP_FOUND                            302
#define STK_HTTP_SEE_OTHER                        303
#define STK_HTTP_NOT_MODIFIED                     304
#define STK_HTTP_USE_PROXY                        305
#define STK_HTTP_TEMPORARY_REDIRECT               307

#define STK_HTTP_BAD_REQUEST                      400
#define STK_HTTP_UNAUTHORIZED                     401
#define STK_HTTP_PAYMENT_REQUIRED                 402
#define STK_HTTP_FORBIDDEN                        403
#define STK_HTTP_NOT_FOUND                        404
#define STK_HTTP_METHOD_NOT_ALLOWED               405
#define STK_HTTP_NOT_ACCEPTABLE                   406
#define STK_HTTP_PROXY_AUTH_REQUIRED              407
#define STK_HTTP_REQUEST_TIMEOUT                  408
#define STK_HTTP_CONFLICT                         409
#define STK_HTTP_GONE                             410
#define STK_HTTP_LENGTH_REQUIRED                  411
#define STK_HTTP_PRECONDITION_FAILED              412
#define STK_HTTP_REQUEST_TOO_LARGE                413
#define STK_HTTP_REQUEST_URI_TOO_LARGE            414
#define STK_HTTP_UNSUPPORTED_MEDIA_TYPE           415
#define STK_HTTP_RANGE_NOT_SATISFIABLE            416
#define STK_HTTP_EXPECTATION_FAILED               417

#define STK_HTTP_INTERNAL_SERVER_ERROR            500
#define STK_HTTP_NOT_IMPLEMENTED                  501
#define STK_HTTP_BAD_GATEWAY                      502
#define STK_HTTP_SERVICE_UNAVAILABLE              503
#define STK_HTTP_GATEWAY_TIMEOUT                  504
#define STK_HTTP_VERSION_NOT_SUPPORTED            505

#define STK_HTTP_HIGHEST_STATUS_ALLOWED           599

/**********************************************************************
 * Protocol Stack Error Codes
 **********************************************************************/

/* Main error code categories */
#define STK_ERR_INVALID                           0
#define STK_ERR_COMM                              20
#define STK_ERR_WTLS                              40
#define STK_ERR_TLS                               60
#define STK_ERR_INTERNAL                          80
#define STK_ERR_SKT_SECURITY                      1000


/* 'Invalid input' error codes */
#define STK_ERR_INVALID_URL                       STK_ERR_INVALID + 1
#define STK_ERR_INVALID_SCHEME                    STK_ERR_INVALID + 2
#define STK_ERR_INVALID_CONNECTION                STK_ERR_INVALID + 3
#define STK_ERR_INVALID_DATA_SIZE                 STK_ERR_INVALID + 4
#define STK_ERR_INVALID_CHANNEL_ID                STK_ERR_INVALID + 5
#define STK_ERR_INVALID_PARAMETER                 STK_ERR_INVALID + 6

/* 'Communication' errors */
#define STK_ERR_COMM_NO_RESPONSE                  STK_ERR_COMM + 1
#define STK_ERR_COMM_WSP                          STK_ERR_COMM + 2
#define STK_ERR_COMM_WTP                          STK_ERR_COMM + 3
#define STK_ERR_COMM_WDP                          STK_ERR_COMM + 4
#define STK_ERR_COMM_HTTP                         STK_ERR_COMM + 5
#define STK_ERR_COMM_TCP                          STK_ERR_COMM + 6
#define STK_ERR_COMM_HOST_NOT_FOUND               STK_ERR_COMM + 7
#define STK_ERR_COMM_CONNECTION_CLOSED            STK_ERR_COMM + 8
#define STK_ERR_COMM_SOCKET_SETUP_FAILED          STK_ERR_COMM + 9
#define STK_ERR_COMM_REQUEST_ABORTED              STK_ERR_COMM + 10
#define STK_ERR_COMM_SOCKET_CLOSED                STK_ERR_COMM + 11
#define STK_ERR_COMM_RESEND_POST_REQUEST          STK_ERR_COMM + 12
#define STK_ERR_COMM_RESEND_PUT_REQUEST           STK_ERR_COMM + 13
#define STK_ERR_COMM_AUTHENTICATION               STK_ERR_COMM + 14
#define STK_ERR_COMM_CONTENT_SIZE                 STK_ERR_COMM + 15
#define STK_ERR_COMM_NOT_IN_CACHE                 STK_ERR_COMM + 16

/* 'WTLS' errors */
#define STK_ERR_WTLS_BAD_RECORD                   STK_ERR_WTLS + 1
#define STK_ERR_WTLS_HANDSHAKE_FAILURE            STK_ERR_WTLS + 2
#define STK_ERR_WTLS_TIMED_OUT                    STK_ERR_WTLS + 3
#define STK_ERR_WTLS_UNSUPPORTED_CERT             STK_ERR_WTLS + 4
#define STK_ERR_WTLS_UNKNOWN_CA                   STK_ERR_WTLS + 5
#define STK_ERR_WTLS_BAD_CERTIFICATE              STK_ERR_WTLS + 6
#define STK_ERR_WTLS_CERTIFICATE_EXPIRED          STK_ERR_WTLS + 7
#define STK_ERR_WTLS_CRYPTOLIB                    STK_ERR_WTLS + 8
#define STK_ERR_WTLS_FATAL_ALERT                  STK_ERR_WTLS + 9
#define STK_ERR_WTLS_CRITICAL_ALERT               STK_ERR_WTLS + 10
#define STK_ERR_WTLS_TOO_MANY_WARNINGS            STK_ERR_WTLS + 11
#define STK_ERR_WTLS_INTERNAL_ERROR               STK_ERR_WTLS + 12
#define STK_ERR_WTLS_CANCEL                       STK_ERR_WTLS + 13

/* 'TLS' errors */
#define STK_ERR_TLS_BAD_RECORD                    STK_ERR_TLS + 1
#define STK_ERR_TLS_DECRYPTION_FAILED             STK_ERR_TLS + 2
#define STK_ERR_TLS_RECEIVED_ALERT                STK_ERR_TLS + 3
#define STK_ERR_TLS_HANDSHAKE_FAILURE             STK_ERR_TLS + 4
#define STK_ERR_TLS_UNSUPPORTED_CERT              STK_ERR_TLS + 5
#define STK_ERR_TLS_UNKNOWN_CA                    STK_ERR_TLS + 6
#define STK_ERR_TLS_BAD_CERTIFICATE               STK_ERR_TLS + 7
#define STK_ERR_TLS_CERTIFICATE_EXPIRED           STK_ERR_TLS + 8
#define STK_ERR_TLS_INTERNAL_ERROR                STK_ERR_TLS + 9
#define STK_ERR_TLS_CANCEL                        STK_ERR_TLS + 10

/* 'Internal' errors */
#define STK_ERR_INTERNAL_REDIRECT                 STK_ERR_INTERNAL + 1
#define STK_ERR_INTERNAL_MEMORY_WARNING           STK_ERR_INTERNAL + 2
#define STK_ERR_INTERNAL_OUT_OF_MEMORY            STK_ERR_INTERNAL + 3
#define STK_ERR_INTERNAL_TOO_MANY_CONNECTIONS     STK_ERR_INTERNAL + 4

/* 'SKT Security' errors */
#define STK_ERR_SKT_SECURITY_CLIENTHELLO          STK_ERR_SKT_SECURITY + 1
#define STK_ERR_SKT_SECURITY_SERVERHELLO          STK_ERR_SKT_SECURITY + 2
#define STK_ERR_SKT_SECURITY_KEYEXCHANGE          STK_ERR_SKT_SECURITY + 3
#define STK_ERR_SKT_SECURITY_FINISHED             STK_ERR_SKT_SECURITY + 4
#define STK_ERR_SKT_SECURITY_ENCRYPT              STK_ERR_SKT_SECURITY + 5
#define STK_ERR_SKT_SECURITY_DECRYPT              STK_ERR_SKT_SECURITY + 6
#define STK_ERR_SKT_SECURITY_TIMEOUT              STK_ERR_SKT_SECURITY + 7


/**********************************************************************
 * Type definitions
 **********************************************************************/

/* Entries of this kind are used to hold the message content of a
 * HTTP message. */
typedef struct {
  /* These two fields correspond to the following header:
   *   Content-Type: contentType; charset="charset"
   * In case of multipart/form-data, each part has such a header. */
  char          *contentType;
  MSF_INT16      charset;

  /* These two fields are used in case of multipart/form-data,
   * and are then included with each part as follows:
   *   Content-Disposition: form-data; name="name"; filename="fileName" */
  char          *name;
  char          *fileName;

  /* The actual data of the message can be supplied in one of three forms:
   *   as a data buffer,
   *   as a named pipe,
   *   as a file.
   */
  MSF_INT16      dataType; /* One of STK_BODY_BUFFER, etc. */
  MSF_INT32      dataLen;  /* Required for STK_BODY_BUFFER,
                            * recommended for all versions */
  union {
    unsigned char *data;
    char          *pipeName;
    char          *pathName;
  } _u;
} stk_content_t;


/**********************************************************************
 * Signal parameters for signals in the HTTP request API:
 **********************************************************************/

/* For the signal STK_SIG_CONFIGURE_CHANNEL */
typedef struct {
  MSF_INT16  channelId;
  MSF_INT16  connectionType;
  MSF_INT32  networkAccountId;
  MSF_INT16  timeOut;
  MSF_INT16  options;
  char      *staticHeaders;
} stk_configure_channel_t;

/* For the signal STK_SIG_CONFIGURE_PROXY_CHANNEL */
typedef struct {
  MSF_INT16       channelId;
  MSF_INT16       connectionType;
  MSF_INT32       networkAccountId;
  MSF_INT16       timeOut;
  msf_sockaddr_t  proxyAddress;
  MSF_UINT16      securePort;
  char           *userName;
  char           *password;
  char           *realm;
  MSF_INT16       options;
  char           *staticHeaders;
} stk_configure_proxy_channel_t;

/* For the signal STK_SIG_REMOVE_CHANNEL */
typedef struct {
  MSF_INT16 channelId;
} stk_remove_channel_t;

/* For the signal STK_SIG_HTTP_REQUEST */
typedef struct {
  MSF_INT16        channelId;
  MSF_INT16        requestId;
  char            *url;
  MSF_INT16        method;
  MSF_INT16        options;
  char            *headers;
  char            *replyFileName;
  MSF_INT32        replyFileSize;

  MSF_INT16        numEntries;
  stk_content_t   *content;
} stk_http_request_t;

/* For the signal STK_SIG_HTTP_REPLY */
typedef struct {
  MSF_INT16      requestId;
  MSF_INT16      status;
  char          *newUrl;
  char          *headers;
  MSF_INT32      socketId;
  MSF_INT32      securityId;
  MSF_INT16      protocol;
  char          *cacheFileName;

  MSF_INT16      numEntries;
  stk_content_t *content;
} stk_http_reply_t;

/* For the signal STK_SIG_CANCEL_REQUEST */
typedef struct {
  MSF_INT16 requestId;
} stk_cancel_request_t;

/* For the signal STK_SIG_CLEAR */
typedef struct {
  MSF_UINT16       operation;
  char            *url;
} stk_clear_t;

/* For the signal STK_SIG_SET_CACHE_CONTROL */
typedef struct {
  char            *url;
  char            *cacheControl;
} stk_set_cache_control_t;

/* For the signal STK_SIG_CLEAR_DONE */
typedef struct {
  MSF_UINT16       operation;
} stk_clear_done_t;

/* For the signal STK_SIG_HTTP_STATUS */
typedef struct {
  MSF_INT16 requestId;
  MSF_INT16 status;
} stk_http_status_t;

/* For the signal STK_SIG_HTTP_REQUEST_ABORTED */
typedef struct {
  MSF_INT16 requestId;
  MSF_INT16 errorCode;
} stk_http_request_aborted_t;


/**********************************************************************
 * Signal parameters for signals in the lower-level messaging API:
 **********************************************************************/

/* For the signal STK_SIG_CREATE_CLIENT_CONNECTION */
typedef struct {
  MSF_INT16      connectionId;
  msf_sockaddr_t addr;
  MSF_INT16      connectionType;
  MSF_INT32      networkAccountId;
} stk_create_client_connection_t;

/* For the signal STK_SIG_CREATE_SERVER_CONNECTION */
typedef struct {
  MSF_INT16  connectionId;
  MSF_UINT16 portNumber;
  MSF_INT16  connectionType;
  MSF_INT32  networkAccountId;
} stk_create_server_connection_t;

typedef struct {
  MSF_INT16      connectionId;
  msf_sockaddr_t addr;
  MSF_INT16      connectionType;
  MSF_INT32      networkAccountId;
  char          *sendPipeName;
  char          *domainName;
} stk_create_stream_connection_t;
/* For the signal STK_SIG_CLOSE_CONNECTION */
typedef struct {
  MSF_INT16 connectionId;
} stk_close_connection_t;

/* For the signal STK_SIG_SEND_REQUEST */
typedef struct {
  MSF_INT16      connectionId;
  MSF_INT16      requestId;
  MSF_INT16      method;
  char          *url;
  char          *headers;
  MSF_INT16      numEntries;
  stk_content_t *content;
} stk_send_request_t;

/* For the signal STK_SIG_SEND_REPLY */
typedef struct {
  MSF_INT16      connectionId;
  MSF_INT16      requestId;
  MSF_INT16      status;
  char          *headers;
  MSF_INT16      numEntries;
  stk_content_t *content;
} stk_send_reply_t;

/* For the signal STK_SIG_ABORT_REQUEST */
typedef struct {
  MSF_INT16 connectionId;
  MSF_INT16 requestId;
  MSF_INT16 confirm;
  MSF_INT16 reason;
} stk_abort_request_t;

/* For the signal STK_SIG_CONFIRM_REQUEST */
typedef struct {
  MSF_INT16 connectionId;
  MSF_INT16 requestId;
  MSF_INT16 confirm;
} stk_confirm_request_t;

/* For the signal STK_SIG_CONNECTION_CREATED */
typedef struct {
  MSF_INT16 connectionId;
} stk_connection_created_t;

/* For the signal STK_SIG_STREAM_CONNECTION_CREATED */
typedef struct {
  MSF_INT16 connectionId;
  char     *receivePipeName;
  MSF_INT32 socketId;
} stk_stream_connection_created_t;

/* For the signal STK_SIG_CONNECTION_CLOSED */
typedef struct {
  MSF_INT16 connectionId;
  MSF_INT16 errorCode;
} stk_connection_closed_t;

/* For the signal STK_SIG_RECV_REQUEST */
typedef struct {
  MSF_INT16       connectionId;
  MSF_INT16       parentId;
  MSF_INT16       requestId;
  msf_sockaddr_t  fromAddr;
  MSF_INT16       method;
  char           *url;
  char           *headers;
  MSF_INT16       numEntries;
  stk_content_t  *content;
} stk_recv_request_t;

/* For the signal STK_SIG_RECV_REPLY */
typedef struct {
  MSF_INT16      connectionId;
  MSF_INT16      requestId;
  MSF_INT16      status;
  char          *headers;
  MSF_INT16      numEntries;
  stk_content_t *content;
} stk_recv_reply_t;

/* For the signal STK_SIG_REQUEST_ABORTED */
typedef struct {
  MSF_INT16 connectionId;
  MSF_INT16 requestId;
  MSF_INT16 errorCode;
} stk_request_aborted_t;

/*
 * Called by any other module that wants to use the STK module.
 */
void
STKif_startInterface (void);


/**********************************************************************
 * Signal-sending API
 * These functions should be used by any other module that wants to
 * send a signal to the STK module.
 **********************************************************************/

/*
 * Configure a channel over which to send HTTP requests.
 */
void
STKif_configureChannel (MSF_UINT8 src, int channelId, int connectionType,
                        MSF_INT32 networkAccountId,  int timeOut,
                        int options, const char *staticHeaders);

/*
 * Configure a channel over which to send HTTP requests, via a proxy.
 */
void
STKif_configureProxyChannel (MSF_UINT8 src, int channelId, int connectionType,
                             MSF_INT32 networkAccountId,  int timeOut,
                             msf_sockaddr_t *proxyAddress, int securePort,
                             const char *userName, const char *password,
                             const char *realm,
                             int options, const char *staticHeaders);

/*
 * Remove a previously configured channel.
 */
void
STKif_removeChannel (MSF_UINT8 src, int channelId);

/*
 * Send a HTTP request, using a previously configured channel.
 */
void
STKif_httpRequest (MSF_UINT8 src, int channelId, int requestId,
                   const char *url, int method, int options,
                   const char *headers,
                   const char *replyFileName, long replyFileSize,
                   int numEntries, stk_content_t *content);

/*
 * Cancel a HTTP request.
 */
void
STKif_cancelRequest (MSF_UINT8 src, int requestId);


/*
 * Clears items in the STK that are shared by all users
 */
void 
STKif_clear (MSF_UINT8 src, int operation, const char *url);

/*
 * Sets the cache control parameters for the page in cache pointed to by url
 */
void 
STKif_setCacheControl (MSF_UINT8 modId, const char *url, const char *cacheControl);


/*
 * Open a client connection to a specified address
 */
void
STKif_createClientConnection (MSF_UINT8 modId, int connectionId,
                              msf_sockaddr_t addr, int connectionType,
                              MSF_INT32 networkAccountId);

/*
 * Open a server connection on a specified port number
 */
void
STKif_createServerConnection (MSF_UINT8 modId, int connectionId,
                              MSF_UINT16 portNumber, int connectionType,
                              MSF_INT32 networkAccountId);

/*
 * Create a stream connection that can be used to transfer data using the 
 * TLS/SSL protocol. 
 */
void 
STKif_createStreamConnection (MSF_UINT8 modId, int connectionId, 
                              msf_sockaddr_t addr, int connectionType, 
                              MSF_INT32 networkAccountId, 
                              const char *sendPipeName, 
                              const char *domainName);

/*
 * Close a connection
 */
void
STKif_closeConnection (MSF_UINT8 modId, int connectionId);

/*
 * Send a request on a previously opened client connection
 */
void
STKif_sendRequest (MSF_UINT8 modId, int connectionId, int requestId,
                   int method, const char *url, const char *headers,
                   int numEntries, stk_content_t *content);

/*
 * Send a reply on a previously opened server connection
 */
void
STKif_sendReply (MSF_UINT8 modId, int connectionId, int requestId,
                 int status, const char *headers,
                 int numEntries, stk_content_t *content);

/*
 * Abort request
 */
void
STKif_abortRequest (MSF_UINT8 modId, int connectionId, int requestId, int reason);

/*
 * Confirm request
 */
void
STKif_confirmRequest (MSF_UINT8 modId, int connectionId, int requestId);


/**********************************************************************
 * Conversion routines for all signals owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/

int
stk_cvt_configure_channel (msf_dcvt_t *obj, stk_configure_channel_t *p);

int
stk_cvt_configure_proxy_channel (msf_dcvt_t *obj, stk_configure_proxy_channel_t *p);

int
stk_cvt_remove_channel (msf_dcvt_t *obj, stk_remove_channel_t *p);

int
stk_cvt_http_request (msf_dcvt_t *obj, stk_http_request_t *p);

int
stk_cvt_http_reply (msf_dcvt_t *obj, stk_http_reply_t *p);

int
stk_cvt_cancel_request (msf_dcvt_t *obj, stk_cancel_request_t *p);

int
stk_cvt_clear (msf_dcvt_t *obj, stk_clear_t *p);

int
stk_cvt_set_cache_control (msf_dcvt_t *obj, stk_set_cache_control_t *p);

int
stk_cvt_clear_done (msf_dcvt_t *obj, stk_clear_done_t *p);

int
stk_cvt_http_status (msf_dcvt_t *obj, stk_http_status_t *p);

int
stk_cvt_http_request_aborted (msf_dcvt_t *obj, stk_http_request_aborted_t *p);

int
stk_cvt_create_client_connection (msf_dcvt_t *obj, stk_create_client_connection_t *p);

int
stk_cvt_create_server_connection (msf_dcvt_t *obj, stk_create_server_connection_t *p);

int
stk_cvt_create_stream_connection (msf_dcvt_t *obj, stk_create_stream_connection_t *p);

int
stk_cvt_close_connection (msf_dcvt_t *obj, stk_close_connection_t *p);

int
stk_cvt_send_request (msf_dcvt_t *obj, stk_send_request_t *p);

int
stk_cvt_send_reply (msf_dcvt_t *obj, stk_send_reply_t *p);

int
stk_cvt_abort_request (msf_dcvt_t *obj, stk_abort_request_t *p);

int
stk_cvt_confirm_request (msf_dcvt_t *obj, stk_confirm_request_t *p);

int
stk_cvt_connection_created (msf_dcvt_t *obj, stk_connection_created_t *p);

int
stk_cvt_stream_connection_created (msf_dcvt_t *obj, stk_stream_connection_created_t *p);

int
stk_cvt_connection_closed (msf_dcvt_t *obj, stk_connection_closed_t *p);

int
stk_cvt_recv_request (msf_dcvt_t *obj, stk_recv_request_t *p);

int
stk_cvt_recv_reply (msf_dcvt_t *obj, stk_recv_reply_t *p);

int
stk_cvt_request_aborted (msf_dcvt_t *obj, stk_request_aborted_t *p);


void *
stk_convert (MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

void
stk_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);


#endif

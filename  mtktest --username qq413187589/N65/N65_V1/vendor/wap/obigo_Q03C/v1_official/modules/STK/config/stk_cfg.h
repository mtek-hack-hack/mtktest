/*
 * Copyright (C) Obigo AB, 2002-2006.
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
 * stk_cfg.h
 *
 * Created by Anders Edenbrandt, Thu May 02 15:51:11 2002.
 *
 * Revision history:
 *
 */
#ifndef _stk_cfg_h
#define _stk_cfg_h

#define STK_CONFIG_WDP
#define STK_CONFIG_WTP
#define STK_CONFIG_WTP_SAR
#define STK_CONFIG_WSP
#ifdef WAP2
#define STK_CONFIG_HTTP
#endif
#define STK_CONFIG_SERVER
#define STK_CONFIG_CACHE
#ifdef WAP_SEC_SUPPORT
#define STK_CONFIG_WTLS
#ifdef WAP2
#define STK_CONFIG_TLS
#define STK_CONFIG_SSL
#endif
#define STK_CONFIG_DIGEST_AUTH
#endif
#define STK_CONFIG_FILE
#define STK_CONFIG_MULTIPART

/*
 * How to handle redirections:
 *   1      Normal:   always automatic redirection, and anything but (GET and) HEAD 
 *                      is changed into GET (this is what most browsers do)
 *   2      Cautious: responses with status codes 301 and 307 are always
 *                      shown to the user
 *   3      Special:  for responses with status codes 301, 302, 307:
 *                      if GET or HEAD, do automatic redirection,
 *                      else, ask for user confirmation (according to HTTP spec)
 */
extern unsigned int bra_cfg_brs_redirect_handling (void);
#define STK_CFG_REDIRECT   (bra_cfg_brs_redirect_handling())

#define STK_CFG_WAP_MAX_PDU_SIZE                  1472/*5120*/
#define STK_CFG_MAX_SOCKETS                       4/*5*/
#define STK_CFG_MAX_CONNECTIONS                   10
#define STK_CFG_MAX_CONNECTIONS_PER_SERVER        3 
#define STK_CFG_TRH_MAX_REQUESTS_PER_HTTP_CONN    4
#define STK_CFG_USE_MAX_SOCKETS_BEFORE_PIPELINING
#define STK_CFG_TRH_MAX_REQUESTS_PER_WSP_CONN     2/*3*/
#define STK_CFG_TRH_MAX_NO_OF_TRANSACTIONS        2/*40*/
#define STK_CFG_MAX_DATASIZE_BUFFER               STK_CFG_WAP_MAX_PDU_SIZE/*200*/
#define STK_CFG_USE_KEEP_ALIVE_HEADER
#define STK_CFG_CACHE_PRIVATE               
#define STK_CFG_CACHE_MAX_INDEX_RAM_USAGE         0           
#define STK_CFG_LOCAL_DNS
#define STK_CFG_ALWAYS_CACHE

/* The maximum number of items stored in the Cookies list. */
#define STK_CFG_COOKIE_MAX_ITEMS                  20
#define STK_CFG_COOKIE_MAX_SIZE                   4000
/*#define STK_CFG_COOKIE_RELAX_DOMAIN_MATCH*/

#define STK_CFG_COOKIE_PERSISTENT_STORAGE
#ifdef STK_CFG_COOKIE_PERSISTENT_STORAGE
#define STK_CFG_COOKIE_WRITE_THROUGH
#endif

/* The maximum number of items stored in the Auth list. */
#define STK_CFG_AUTH_MAX_ITEMS                    20
#define STK_CFG_AUTH_MAX_SIZE                     4000

#define STK_CFG_AUTH_PERSISTENT_STORAGE
#ifdef STK_CFG_AUTH_PERSISTENT_STORAGE
#define STK_CFG_AUTH_WRITE_THROUGH
#endif

/* If STK receives a notification about socket closure, default 
 * behavior is to abort all outstanding requests on that socket. 
 * For requests where no reply has yet been received, it's possible
 * to enable automatic retransmission using this define. 
 * (Applicable to HTTP only.) */
#define STK_CFG_AUTO_RETRANS_UNANSWERED_REQ

/*
 * When using STK_OPTION_REPLY_FILE with an HTTP request, one may choose 
 * to receive the response signal, STK_SIG_HTTP_REPLY, (containing the 
 * headers) as soon as the output file has been opened. (Default 
 * behaviour is to receive the response signal when download has 
 * finished and file is closed.) In this case no signal is sent when 
 * the file is closed, so it's up to the integration to trigger on file 
 * closure if it is necessary to receive a notification.
 */
/* #define STK_CFG_REPLY_FILE_RESPONSE_IMMEDIATELY */

/* Maximum HTTP Connection buffer size. When reading headers, an entire
 * line must fit in this buffer. Thus this define limits how long lines
 * are supported in HTTP headers (and Multipart/Mixed entry headers).
 * Originally the buffer size is STK_HTTP_DEFAULT_BUFSIZE (defined in
 * stk_http.c). STK_CFG_HTTP_MAX_BUFSIZE should be between 
 * STK_HTTP_DEFAULT_BUFSIZE and 32k.
 */
#define STK_CFG_HTTP_MAX_BUFSIZE                      4096

/* To prevent problems with servers sending incorrect Content-Location
 * headers, it's possible to get these headers removed from the
 * response before it's sent to the application. Content-Location is
 * needed to handle Multipart/Mixed responses though. */
/*#define STK_CFG_IGNORE_CONTENT_LOCATION_ON_NON_MULTIPART*/

/**********************************************************************
 * WTP timeout values
 **********************************************************************/
/*
 * All times are in 1/10ths of a second, and are
 * as suggested in the WTP specification. 
 */
#define STK_CFG_WTP_SHORT_ACK_INTERVAL_UDP        10
#define STK_CFG_WTP_LONG_ACK_INTERVAL_UDP         40
#define STK_CFG_WTP_BASE_RETRY_INTERVAL_UDP       80
#define STK_CFG_WTP_SHORT_RETRY_INTERVAL_UDP      40
#define STK_CFG_WTP_WAIT_TIMEOUT_INTERVAL_UDP     80/*400*/

#define STK_CFG_WTP_MAX_RETRANSMISSIONS_UDP       8
#define STK_CFG_WTP_MAX_ACK_TIMER_EXPIRATIONS_UDP 6

/**********************************************************************
 * WTP SAR constants
 **********************************************************************/

#ifdef WIN32
#define STK_CFG_WTP_SAR_GROUP_SIZE                8000
#else
#define STK_CFG_WTP_SAR_GROUP_SIZE                8000/*8000*/
#endif
#define STK_CFG_WTP_SAR_SEGMENT_SIZE              1400
#define STK_CFG_WTP_SAR_MAX_PDU_SIZE              MSF_MAX_DOWNLOAD_SIZE/*200000*/

/*
 * When sending a Segmented Invoke, the retry interval is
 * calculated as:
 *   CFG_WTP_SAR_GROUP_RETRY_INTERVAL + num_segments * CFG_WTP_SAR_SEGMENT_RETRY_INTERVAL
 * With the default values of '30' and '20', the retry interval
 * for a one-segment Invoke will be 5.0 seconds, and for
 * a four-segment Invoke it will be 11.0 seconds, etc.
 */
#define STK_CFG_WTP_SAR_GROUP_RETRY_INTERVAL      60/*30*/
#define STK_CFG_WTP_SAR_SEGMENT_RETRY_INTERVAL    20

/*
 * When a large result is received over WTP SAR, the protocol only
 * allows for timers on the sending side. Hence, if the sender should
 * unexpectedly disappear, the client may hang waiting for more data.
 * To prevent this, STK maintains a timer that is started when STK
 * is ready to receive a new group, and is stopped when all segments
 * of that group have been received. Should the timer ever expire,
 * then the transaction is aborted. It is therefore important to
 * set this value large enough that it never expires except in the
 * case that the Gateway has stopped sending.
 */
#define STK_CFG_WTP_SAR_RECEIVE_GROUP_TIMEOUT         600

 /**************************************************
 * WTLS
 **************************************************/

/*
 * How often should the encryption keys be refreshed, i.e.,
 * calculated anew from the master secret. A value of n means
 * that it is refreshed every 2^n messages.
 */
#define STK_CFG_WTLS_KEY_REFRESH_RATE_UDP    8
#define STK_CFG_WTLS_KEY_REFRESH_RATE_SMS    6

/*
 * Max number of retransmissions during handshake.
 * (The default is to use the same value as WTP.)
 */
#define STK_CFG_WTLS_MAX_RETRANSMISSIONS_UDP  STK_CFG_WTP_MAX_RETRANSMISSIONS_UDP
#define STK_CFG_WTLS_MAX_RETRANSMISSIONS_SMS  STK_CFG_WTP_MAX_RETRANSMISSIONS_SMS

/*
 * The time between to retransmissions.
 * The value should be given in 1/10ths of a second.
 * (The default is to use the same value as WTP.)
 */
#define STK_CFG_WTLS_RETRANSMISSION_INTERVAL_UDP  STK_CFG_WTP_BASE_RETRY_INTERVAL_UDP
#define STK_CFG_WTLS_RETRANSMISSION_INTERVAL_SMS  STK_CFG_WTP_BASE_RETRY_INTERVAL_SMS

/* The keyed MAC algorithms defined by WTLS. */
#define MAC_SHA_0               0
#define MAC_SHA_40              1
#define MAC_SHA_80              2
#define MAC_SHA                 3
#define MAC_SHA_XOR_40          4
#define MAC_MD5_40              5
#define MAC_MD5_80              6
#define MAC_MD5                 7

/*
 * Which MAC lengths should be used, given in order of
 * preference, with the highest preference first.
 */
#define STK_CFG_WTLS_MAC_SHA_UDP_1   MAC_SHA_80
#define STK_CFG_WTLS_MAC_SHA_UDP_2   MAC_SHA
#define STK_CFG_WTLS_MAC_SHA_UDP_3   MAC_SHA_40

#define STK_CFG_WTLS_MAC_SHA_SMS_1   MAC_SHA_40
#define STK_CFG_WTLS_MAC_SHA_SMS_2   MAC_SHA_80
#define STK_CFG_WTLS_MAC_SHA_SMS_3   MAC_SHA

#define STK_CFG_WTLS_MAC_MD5_UDP_1   MAC_MD5
#define STK_CFG_WTLS_MAC_MD5_UDP_2   MAC_MD5_80
#define STK_CFG_WTLS_MAC_MD5_UDP_3   MAC_MD5_40

#define STK_CFG_WTLS_MAC_MD5_SMS_1   MAC_MD5_40
#define STK_CFG_WTLS_MAC_MD5_SMS_2   MAC_MD5_80
#define STK_CFG_WTLS_MAC_MD5_SMS_3   MAC_MD5

/*
 * How many Alerts with alert level "warning" do we accept,
 * before terminating the connection.
 */
#define STK_CFG_WTLS_MAX_NUM_WARNINGS   5



/**************************************************
 * TLS
 **************************************************/

#define STK_CFG_TLS_MAX_RECORD_LENGTH   5192


/*************************************************
 * Configuration constants due to GW bugs
 **************************************************/

/*
 * Possible WSP Encoding Version header values 
 */
#define STK_ENCODING_VERSION_1_2            0x12
#define STK_ENCODING_VERSION_1_3            0x13
#define STK_ENCODING_VERSION_1_4            0x14

/*
 * Encoding version supported by STK
 */

#define STK_CFG_SUPPORTED_ENCODING_VERSION  STK_ENCODING_VERSION_1_3

/*
 * Module id for default push receiver.  
 * When this parameter is defined, WSP sessions created by HTTP request API 
 * includes Confirmed Push and Push facilities in Protocol Options. When a 
 * Confirmed Push or Push message arrives on such session it is sent to 
 * the default push receiver.
 */
#define STK_CFG_DEFAULT_PUSH_RECEIVER       MSF_MODID_PHS

#endif

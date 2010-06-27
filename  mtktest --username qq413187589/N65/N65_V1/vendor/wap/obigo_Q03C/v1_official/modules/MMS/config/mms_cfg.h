/*
 * Copyright (C) Obigo AB, 2002-2005.
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
 
/*! \file mms_cfg.h
 *  \brief  Configuration definitions for the MMS Service. Defines with names 
 *          starting with MMS_DEFAULT is used as the default value for 
 *          configurations settings in the registry. Once the corresponding 
 *          setting in the registry has got a value, the registry setting will 
 *          be used.
 */

#ifndef _MMS_CFG_H
#define _MMS_CFG_H

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

#ifndef _CUSTOM_WAP_CONFIG_H
#include "custom_wap_config.h"
#endif

/****************************************************************************
 * Change, comment or uncomment the defines below in order to alter the 
 * behaviour and/or functionality of the MMS Client.
 ****************************************************************************/
/* If there is a transaction in mms message, we will return M_ACK to server. */
#define MMS_NO_ID_CHECK_FOR_M_ACK
/*!
 * This define is used to include the optional Unified-inbox
 * functionallity into the MMS service code.
 *
 * Comment the below define to leave out Unified-inbox functions.
 */
#ifdef MSF_MODID_UIS
//#define MMS_UIS_IN_USE 0 //Jo- don't send signal to UIS
#endif


 
/*! Defines if a read report has an ending null-byte or not.
*  1 for Null-byte
*  0  if not
*/

#define MMS_READ_REPORT_END_OF_STRING_TOKEN 1 
 
 /*! Defines which folder an MMS should be stored in during the send operation.
 *  Default is outbox (MMS_OUTBOX).
 */

#define MSG_STORE_FOLDER_BEFORE_SEND MMS_HIDDEN
/*! Defines if UTF8 or US_ASCII should be used to encode the Subject 
 * in a 1.0 readreport
 */

#define MMS_RR_SUBJECT_CHARSET MMS_AUTO_RR

/*! Time in tenth of seconds before the MMS Service terminates outstanding 
 *  file operations. This setting is used during termination of the MMS Service.
 *  The time is given in tenth of seconds so a value of 50 means 5 seconds.
 */
#define MMS_TERMINATE_FILE_TIMEOUT  50

/*! Defines the channel ID that the MMS Service uses towards the protocol 
 *  stack. */
#define MMS_STK_CHANNEL_ID 0

/*! Defines the connection type that the MMS Service uses towards the protocol 
 *  stack. This value is the default value for the registry setting 
 *  #MMS_REG_KEY_STK_CONNECTION_TYPE. */
#define MMS_DEFAULT_STK_CONNECTION_TYPE STK_CONNECTION_TYPE_HTTP

/*! Defines the name of the MMS Client as presented to the MMSC in the HTTP 
 *  header User-Agent. As long as no name is given, the HTTP header User-Agent
 *  will not be used. This value is the default value for the registry setting 
 *  #MMS_REG_KEY_USER_AGENT. */
/*scottie: If you give value to user agent, it leads to memory leak issue in configureChannel(). Be careful. */
#define MMS_DEFAULT_USER_AGENT ((char*)wap_custom_get_mms_user_agent())/*"MediaTek Maui MMS Agent"*/

/*! Defines the network account that the MMS Service should use. 
 *  This value is the default value for the registry setting 
 *  #MMS_REG_KEY_NETWORK_ACCOUNT. */
#define MMS_DEFAULT_NETWORK_ACCOUNT 0

/*! Defines the scheme used to send messages to the MMS Proxy-Relay server. 
 *  This value is the default value for the registry setting 
 *  #MMS_REG_KEY_PROXY_RELAY_SCHEME. */
#define MMS_DEFAULT_PROXY_RELAY_SCHEME     "http://"

/*! Defines the MMS Proxy-Relay server to send messages to. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_PROXY_RELAY. The MMS 
 *  Proxy-Relay can be specified in the form of an IP 4 address, e.g. 
 *  "127.0.0.1". */
#define MMS_DEFAULT_PROXY_RELAY             "mmsc"

/*! Port on the MMS Proxy-Relay to use. This value is the default value for
 *  the registry setting #MMS_REG_KEY_PORT. 
 *  If set to zero the default scheme port is used.
 */
#define MMS_DEFAULT_PORT                    0

/*! URI for POST operations towards the MMS Proxy-Relay. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_POST_URI. */
#define MMS_DEFAULT_POST_URI                "/"

/*! Defines if a WAP Gateway will be used. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_GW_ADDRESS. */
#define MMS_DEFAULT_GW_ADDRESS              NULL

/*! HTTP port of the WAP Gateway. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_GW_HTTP_PORT. */
#define MMS_DEFAULT_GW_HTTP_PORT            0

/*! Password used to log in to the WAP Gateway. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_GW_PASSWORD. */
#define MMS_DEFAULT_GW_PASSWORD             NULL

/*! Realm used for HTTP authentication at the WAP Gateway. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_GW_REALM. */
#define MMS_DEFAULT_GW_REALM                NULL

/*! Secure port at the WAP Gateway. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_GW_SECURE_PORT. */
#define MMS_DEFAULT_GW_SECURE_PORT          0

/*! Username used to log in to the WAP Gateway. This value is the 
 *  default value for the registry setting #MMS_REG_KEY_GW_USERNAME. */
#define MMS_DEFAULT_GW_USERNAME             NULL

 /*! Defines additional HTTP headers that can be appended to every POST and
 *  GET operation towards the MMSC. If a value is set, it will be appended 
 *  as a HTTP header for all GET and POST operations. 
 *
 *  Default value for the registry setting #MMS_REG_KEY_CLIENT_HTTP_HEADER
 *
 *  These additional HTTP headers can be used for example for the X-MSISDN
 *  header that some MMSCs need. Other MMSCs instead need the HTTP header
 *  X-NOKIA-MSISDN or an equivalent header to identify the handset. 
 *
 *  So this configuration variable can for example have values like:
 *      "X-MSISDN:+46701234567"
 *      "X-NOKIA-MSISDN:+46701234567"
 *      "X-YOUR_COMPANY_NAME-MDN:1234567890"
 *      "X-MY-HEADER-1:xyz\nX-MY-HEADER-2:abc\nX-MY-HEADER-3:def"
*/
#define MMS_DEFAULT_CLIENT_HTTP_HEADER     "Accept: application/vnd.wap.mms-message\n" \
"Accept: image/jpeg\n" \
"Accept: image/bmp\n" \
"Accept: image/gif\n" \
"Accept: image/vnd.wap.wbmp\n" \
"Accept: audio/imelody\n" \
"Accept: audio/midi\n" \
"Accept: audio/wav\n" \
"Accept: audio/sp-midi\n" \
"Accept: audio/amr\n" \
"Accept: audio/mp3\n" \
"Accept: audio/mpeg\n" \
"Accept: audio/aac\n" \
"Accept: audio/m4a\n" \
"Accept: audio/x-wav\n" \
"Accept: text/plain\n" \
"Accept: text/x-imelody\n" \
"Accept: text/x-vCalendar\n" \
"Accept: text/x-vCard\n" \
"Accept: text/vnd.sun.j2me.app-descriptor\n" \
"Accept: text/calendar\n" \
"Accept: text/css\n" \
"Accept: video/3gpp\n" \
"Accept: video/mp4\n" \
"Accept: multipart/related\n" \
"Accept: multipart/mixed\n" \
"Accept: application/vnd.wap.multipart.related\n" \
"Accept: application/vnd.wap.multipart.mixed\n" \
"Accept: application/vnd.oma.drm.message\n" \
"Accept: application/vnd.oma.drm.content\n" \
"Accept: application/vnd.oma.drm.rights+xml\n" \
"Accept: application/vnd.oma.drm.rights+wbxml\n" \
"Accept: application/smil\n" \
"Accept: application/vnd.oma.dd+xml\n" \
"Accept: application/java-archive\n" \
"Accept: application/vnd.wap.connectivity-wbxml\n" \
"Accept-Charset:utf-8\n"\
"Accept-Charset:iso-8859-1\n"\
"Accept-Charset:us-ascii\n"\
"Accept-Charset:iso-10646-ucs-2\n"

/*! We accept data with all headers although we could restrict it to be 
*  "application/vnd.wap.mms-message". By accepting all headers we could
*  receive wrong data but since we do sanity checks of the PDUs, it won't
*  cause any harm. Instead we get better control of the data in the MMS 
*  Client which also can be used during debugging. In order to minimze 
*  the amount of data passed to the MMS Client (I don't know if it can 
*  happen), change these defines to "applic..." as described above. */
#define MMS_GET_HTTP_HEADER  "Accept: */*\n"
#define MMS_POST_HTTP_HEADER "Accept: */*\n" \
"Content-Type: " MMS_CONTENT "\n\n"

/*! Number of attempts before a GET operation is considered to have failed. */
extern int mmsa_get_max_mms_get_retry_num(void);
extern int mmsa_get_max_mms_post_pdu_retry_num(void);
extern int mmsa_get_max_mms_post_msg_retry_num(void);

#define MMS_GET_RETRY               (mmsa_get_max_mms_get_retry_num())

/*! Number of retries before a POST operation is considered to have failed. */
#define MMS_POST_RETRY              (mmsa_get_max_mms_post_pdu_retry_num())

/*! Number of retries before a POST operation is considered to have failed if it is a MMS_M_SEND_REQ. */
#define MMS_POST_MSG_RETRY          (mmsa_get_max_mms_post_msg_retry_num())


/*! Time before a GET operation is considered to have timed out. The time
 *  is given in tenth of seconds so a value of 300 means 30 seconds.
 */
#define MMS_GET_TIMEOUT             (wap_custom_get_max_mms_get_retry_timeout()) /*400*/ /*300*/

/*! Time before a POST operation is considered to have timed out. The time
 *  is given in tenth of seconds so a value of 300 means 30 seconds.
 */
#define MMS_POST_TIMEOUT            (wap_custom_get_max_mms_post_retry_timeout()) /*1200*/ /*300*/

/*! Time before a connect operation (i.e. the operation of starting 
 *  a WSP/HTTP session) is considered to have timed out. 
 *  The time is given in tenth of seconds so a value of 600 means 60 seconds.
 */
#define MMS_CONNECT_TIMEOUT         600

/*! Defines if the MMS Client will disconnect from the network when idle.
 *  This value is the default value for the registry setting
 *  #MMS_REG_KEY_DISCONNECT_ON_IDLE.
 */
#define MMS_DEFAULT_DISCONNECT_ON_IDLE      TRUE /*FALSE*/

/*! Time in seconds before the MMS Client disconnects if the 
 *  registry setting #MMS_REG_KEY_DISCONNECT_ON_IDLE is set to TRUE.
 *  The time is given in tenth of seconds so a value of 150 means 15 seconds.
 */
#ifdef __MMS_DUAL_SIM_SUPPORT__
#define MMS_DISCONNECT_ON_IDLE_TIMEOUT  30 /*50 150*/
#else
#define MMS_DISCONNECT_ON_IDLE_TIMEOUT  100 /*50 150*/
#endif

/*! This is a non-standard extension to the WAP Forum MMS Standard. 
 *  This define determines if M-NotifyResp is sent when a notification is 
 *  received.
 *
 *  This value is the default value for the registry setting
 *  #MMS_REG_KEY_NO_SMS_NOTIFY.
 *
 *  Set to FALSE Always send.
 *  Set to TRUE Only when bearer wasn't SMS.
 */
#define MMS_DEFAULT_NO_SMS_NOTIFY_RESP      FALSE

/*! Whether to silently discard notifications where the hostname portion of the
 *  content location does not match the hostname portion of the configured MMSC
 *
 *  This value is the default value for the registry setting 
 *  #MMS_REG_KEY_NOTIF_MATCH_TO_MMSC
 *
 *  FALSE: Nofifications are not discarded.
 *  TRUE:  Notifications silently discarded at mismatch.
 */
#define MMS_DEFAULT_NOTIF_MATCH_TO_MMSC     FALSE

/*! Decides how the MMS Service respond to message notifications from the
 *  MMS Proxy-Relay. Can be used to silently discard M-Notification.ind
 *  PDUs or to reject them with M-NotifyResp.ind PDUs.
 *
 *  This value is the default value for the registry setting 
 *  #MMS_REG_KEY_NOTIFY_RESP_MODE
 */
#define MMS_DEFAULT_NOTIFY_RESP_MODE        MMS_NOTIFY_RESPONSE_NORMAL

/*! The maximal size (in bytes) of messages to automatically download from the 
 *  MMS Proxy-Relay. This value is used when Immediate Retrieval is active and
 *  it is the default value for the registry setting 
 *  #MMS_REG_KEY_MAX_SIZE_OF_MSG. 
 */
#define MMS_DEFAULT_MAX_MSG_SIZE        (wap_custom_get_max_mms_msg_size())/*50000*/ /*32000*/

 /*! During message retrieval, defines the maximum size for a message. If 
 *  this limit is reached during delayed retrieval, the download is stopped
 *  and MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED is returned in the call to 
 *  MMSa_newMessage. If this limit is reached during immediate retrieval,
 *  the download is stopped and MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED 
 *  is returned in the call to MMSa_newMessage.
 *  This value is the default value for the 
*  #MMS_CFG_MAX_RETRIEVAL_SIZE configuration variable. */
#define MMS_DEFAULT_MAX_RETRIEVAL_SIZE   0

/*! Default roaming status.
 * Only used when MMS_ROAMING_USE_REGISTRY is defined
 */
#define MMS_DEFAULT_ROAMING_STATUS         MMS_NOT_ROAMING  

/*! Default network bearer availablilty status.
 */
#define MMS_DEFAULT_BEARER_STATUS          MMS_BEARER_AVAILABLE  

/*! Default retrieval method while in roaming.
 */
#define MMS_DEFAULT_ROAMING_MODE           MMS_ROAM_DELAYED


/*! Defines the maximum numbers of messages that can be stored in the 
 *  MMS folders.
 *
 *  NOTE!
 *  This value has to be set to 'max number of visible messages in folders' + 1.
 *  This is to be able to handle the temporary extra message the immediate
 *  retrievel requires. E.g 33 -> 32 visible messages in mms folders.
 */
#define MMS_MAX_NO_OF_MSG       (wap_custom_get_max_mms_num())

/*! Defines the threshold of how many messages in the MMS folders before a warning
 *  message or the result code MMS_RESULT_MANY_MSG_WARNING is issued.
 */
#define MMS_NO_OF_MSG_WARNING   (wap_custom_get_max_mms_warning_num())


/* This feature is used to cache received mms push messages to files when number of mms reaches MMS_MAX_NO_OF_MSG*/
/* When user deletes mms message, MMS service will retrieve cached push and process it.*/
#define __MMS_CACHE_PUSH__
#ifdef __MMS_CACHE_PUSH__
#define MMS_MAX_NO_CACHE_PUSH 10 // This value MUST be larger than 0. MMS service can cache MMS_MAX_NO_CACHE_PUSH to file when MMS_MAX_NO_OF_MSG is reached.
#endif
/*! MMS keeps a table with information on all messages in all folders. This 
 *  table must be stored in persistent storage. The following definitions 
 *  defines which events that will write the table to persistent storage.
 *  One or more events can be chosen. If more events are chosen, the number of
 *  "disk" operations will increase. If less events are chosen, more data can
 *  be lost in case of a malfunction. Data that may be lost are e.g. what
 *  folder a message is stored in, if it has been read, received Read Reports
 *  and Delivery Reports and the Server Message ID.
 *
 *  Message done, stored and parsed */
#define MMS_FLDRMGR_MSG_DATA_SET   1
/*! Empty message is created */
#define MMS_FLDRMGR_CREATE         0
/*! Deletion of a message */
#define MMS_FLDRMGR_DELETE         0
/*! Move a message between folder */
#define MMS_FLDRMGR_MOVE           1
/*! New notif received */
#define MMS_FLDRMGR_NOTIF          1
/*! Read.status changed */
#define MMS_FLDRMGR_READMARK       1

/*! When the MMS Service creates a read report, the Date field value in the
 *  header could either be provided by the cellular or the MMSC
 *  [OMA-MMS-ENC-v1_2-20030915-C, Table 1 and Table 10].
 *  The advantage of letting the MMSC providing the date is that the cellular
 *  time and date migth be set wrongly by the user.
 *
 *  The MMS Standard [OMA-MMS-ENC-v1_2-20030915-C, 7.2.6] states that the Date
 *  field in the PDUs represents seconds since 1970-01-01 00:00:00 GMT.
 *
 *  - A value of 0 => Date set by MMSC
 *  - A value of 1 => Date set by Cellular
 */
#ifndef MMS_READ_REPORT_DATE
#define MMS_READ_REPORT_DATE       0
#endif

/*! Setting for sending read reports as multipart mixed. A read report for
 *  MMS Version 1.0 is normally sent with content type set to text/plain,
 *  but some operators requires them to be multipart mixed.
 *
 *  0 => RR 1.0 sent as text/plain (default)
 *  1 => RR 1.0 sent as multipart mixed
 */
#define MMS_READ_REPORT_MULTIPART_MIXED  1

/*! Settings for using local time instead of GMT in 1.0 read report.
*
*   0=> Use GMT (default)
*   1=> Use local time
*/

#define MMS_READ_REPORT_LOCAL_TIME  1


/*!
 * Text length related configurations. These defines determines how long
 * text fields may be. Values is number of bytes.
 *
 * Max length for one address field. */
#define MAX_ADDRESS_LEN                 128
/*! Max length for content type. */
#define MAX_CONTENT_TYPE_LEN            100
/*! Max length for message class. */
#define MAX_STR_LEN_MSG_CLASS           64
/*! Max length for subject. */
#define MAX_SUBJECT_LEN                 121  /* 40x3+1 Quote 127 *//*100*/
/*! Max length for Entry header values. */
#define MAX_MMS_ENTRY_HEADER_VALUE_LEN  780 /*100*/
/*! Max length for Server Msg Id */
#define MAX_SERVER_MSG_ID               2 /*42*/
/*! Max length for Transaction Id */
#define MAX_LEN_TRANSACTION_ID          41

/*!
 * Length of strings held in the Master Message Table (MMT). This table is
 * used when listing messages in folders. The entire fields will always be 
 * stored in the message, these definitions only determine how much of the 
 * field that could be shown in listings. 
 *
 * Server message id length */
#define MAX_MMT_SERVER_MSG_ID_LEN  MAX_SERVER_MSG_ID
/*! Address length */ 
#define MAX_MMT_ADDRESS_LEN        1
/*! Subject field length */
#define MAX_MMT_SUBJECT_LEN        1


/*!
 * For from, to, cc, bcc address in MMS header without specifying address 
 * type, conduct validation.
 */
#define MMS_VALIDATE_UNKOWN_ADDRESS_TYPE

/****************************************************************************
 * Memory related configuration definitions. The defines below determines how 
 * the MMS Client uses memory. Please read the manual for a longer description 
 * of them. All sizes for the following definitions is given in bytes.
 ****************************************************************************/

/*! Defines the maximum size of a pushed notification. If the notification is 
 * larger than this value, the notification cannot be handled. A value of 
 * 300 is sufficient in most cases. */
#define MMS_MAX_NOTIFICATION_SIZE   512

/*! Defines the maximum size of a chunk. Larger data items will be stored on
 *  file. If chosen to small, all messages cannot be handled, e.g. if the
 *  MMS header does not fit within one memory chunk. */
#define MMS_MAX_CHUNK_SIZE          5120UL /* 4096UL */

/*! Defines if incoming PDUs shall be checked for a strict conformance to the
 *  MMS standard. For example, by allowing M-Retrieve.conf to not have a date 
 *  tag (which is mandatory) a blank date field MAY be shown to the user (if 
 *  the MMSC doesn't send it). This does not cause any problems in the MMS
 *  Service but can be valuable when running towards MMSCs that are not
 *  following the standard.

 *  Possible values:1 - a strict check will be performed.
 *                  0 - non-vital fields may be missing */
#define MMS_STRICT_PDU_CHECK        0

/*! Defines how many notifications that can be queued during
 *	start-up of the MMS service.
 */
#define MMS_NOTIF_QUEUE_SIZE 4


#endif /* _MMS_CFG_H */


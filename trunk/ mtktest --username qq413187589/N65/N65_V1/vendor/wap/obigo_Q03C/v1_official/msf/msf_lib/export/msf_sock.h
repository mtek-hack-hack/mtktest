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
 * msf_sock.h
 *
 * Created by Anders Edenbrandt, Tue Apr 30 16:41:33 2002.
 *
 * Revision  history:
 *   020905, AED: Added error codes
 *   021014, IPN: Added MSF_SOCKET_CLOSE_ALL
 *
 */
#ifndef _msf_sock_h
#define _msf_sock_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif


/**********************************************************************
 * Constants
 **********************************************************************/

/* Socket types */
#define MSF_SOCKET_TYPE_UDP             HDI_SOCKET_TYPE_UDP
#define MSF_SOCKET_TYPE_TCP             HDI_SOCKET_TYPE_TCP
#define MSF_SOCKET_TYPE_SMS_DATA        HDI_SOCKET_TYPE_SMS_DATA
#define MSF_SOCKET_TYPE_SMS_RAW         HDI_SOCKET_TYPE_SMS_RAW

/* Bearers */
#define MSF_SOCKET_BEARER_IP_ANY        HDI_SOCKET_BEARER_IP_ANY
#define MSF_SOCKET_BEARER_GSM_SMS       HDI_SOCKET_BEARER_GSM_SMS
#define MSF_SOCKET_BEARER_GSM_CSD       HDI_SOCKET_BEARER_GSM_CSD
#define MSF_SOCKET_BEARER_GSM_GPRS      HDI_SOCKET_BEARER_GSM_GPRS
#define MSF_SOCKET_BEARER_BT            HDI_SOCKET_BEARER_BT
#define MSF_SOCKET_BEARER_ANY           HDI_SOCKET_BEARER_ANY

/* Notification types */
#define MSF_SOCKET_EVENT_ACCEPT         HDI_SOCKET_EVENT_ACCEPT
#define MSF_SOCKET_EVENT_CLOSED         HDI_SOCKET_EVENT_CLOSED
#define MSF_SOCKET_EVENT_RECV           HDI_SOCKET_EVENT_RECV
#define MSF_SOCKET_EVENT_SEND           HDI_SOCKET_EVENT_SEND

/* Error codes */
#define MSF_SOCKET_ERROR_BAD_ID                   HDI_SOCKET_ERROR_BAD_ID
#define MSF_SOCKET_ERROR_INVALID_PARAM            HDI_SOCKET_ERROR_INVALID_PARAM
#define MSF_SOCKET_ERROR_MSG_SIZE                 HDI_SOCKET_ERROR_MSG_SIZE
#define MSF_SOCKET_ERROR_DELAYED                  HDI_SOCKET_ERROR_DELAYED
#define MSF_SOCKET_ERROR_RESOURCE_LIMIT           HDI_SOCKET_ERROR_RESOURCE_LIMIT
#define MSF_SOCKET_ERROR_CONNECTION_FAILED        HDI_SOCKET_ERROR_CONNECTION_FAILED
#define MSF_SOCKET_ERROR_HOST_NOT_FOUND           HDI_SOCKET_ERROR_HOST_NOT_FOUND
#define MSF_SOCKET_ERROR_CLOSED                   HDI_SOCKET_ERROR_CLOSED


/**********************************************************************
 * API Functions
 **********************************************************************/

#define MSF_SOCKET_CREATE               HDIa_socketCreate
#define MSF_SOCKET_CLOSE                HDIa_socketClose
#define MSF_SOCKET_ACCEPT               HDIa_socketAccept
#define MSF_SOCKET_BIND                 HDIa_socketBind
#define MSF_SOCKET_CONNECT              HDIa_socketConnect
#define MSF_SOCKET_GET_NAME             HDIa_socketGetName
#define MSF_SOCKET_LISTEN               HDIa_socketListen
#define MSF_SOCKET_RECV                 HDIa_socketRecv
#define MSF_SOCKET_RECV_FROM            HDIa_socketRecvFrom
#define MSF_SOCKET_SEND                 HDIa_socketSend
#define MSF_SOCKET_SEND_TO              HDIa_socketSendTo
#define MSF_SOCKET_SELECT               HDIa_socketSelect
#define MSF_SOCKET_CLOSE_ALL            HDIa_socketCloseAll
#define MSF_SOCKET_GET_HOST_BY_NAME     HDIa_socketGetHostByName
#define MSF_SOCKET_GET_HOST_BY_NAME_NID HDIa_socketGetHostByNameNId

#endif

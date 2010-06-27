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
 *   soc_consts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains constants of socket APIs.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SOC_CONSTS_H
#define _SOC_CONSTS_H


/*=============================
 * Constants
 *=============================*/

/* couting total socket numbers by compile options */
/* Define number of socket used by applications */
/* WARNING: THESE CONSTANTS SHOULD BE CONFORM WITH FLOW CONTROL POOL BLOCKS */
/* TFTP */
#ifdef __TFTP__
#define TFTP_SOCKETS    0   /* 1, use spared */
#else /* !__TFTP__ */
#define TFTP_SOCKETS    0
#endif /* !__TFTP__ */

/* DHCP */
#ifdef __WIFI_SUPPORT__
#define DHCP_SOCKETS   0    /* 1, use spared */
#else /* !__WIFI_SUPPORT__ */
#define DHCP_SOCKETS   0
#endif /* !__WIFI_SUPPORT__ */

/* IPERF, iperf will block the screen, use the spared sockets */

/* DNS */
#ifdef __TCPIP__
#define DNS_SOCKETS     2
#else /* !__TCPIP__ */
#define DNS_SOCKETS     0
#endif /* !__TCPIP__ */

/* WAP: 1 SMS, 1 SMS UDP, 5 general sockets */
#ifdef WAP_SUPPORT
#define WAP_SOCKETS     5   /* 6 */
#else /* !WAP_SUPPORT */
#define WAP_SOCKETS     0
#endif /* !WAP_SUPPORT */

/* Streaming */
#ifdef STREAM_SUPPORT
#define STREAM_SOCKETS     5
#else /* !STREAM_SUPPORT */
#define STREAM_SOCKETS     0
#endif /* !STREAM_SUPPORT */

/* POC, RTP, RTCP, SIP */
#if defined(__POC__) || defined(__J2ME__)
#define POC_J2ME_SOCKETS     3
#else /* !__POC__ && !__J2ME__ */
#define POC_J2ME_SOCKETS     0
#endif /* !__POC__ && !__J2ME__ */

/* EMAIL */
#ifdef __EMAIL__
#define EMAIL_SOCKETS     0 /* 1, use spared */
#else /* !__EMAIL__ */
#define EMAIL_SOCKETS     0
#endif /* !__EMAIL__*/

/* VOIP, 7 max 4 calls in MMI (3x3-way conf + 1 single), 2 UDP, 1 TCP */
#ifdef __VOIP__
#define VOIP_SOCKETS     6  /* 7 */
#else /* !__VOIP__ */
#define VOIP_SOCKETS     0
#endif /* !__VOIP__*/


enum
{
    SOCKET_SPARED = 4,                                  /*  4 */
    TFTP_SOCKET_END = SOCKET_SPARED + TFTP_SOCKETS,     /*  0 */
    DHCP_SOCKET_END = TFTP_SOCKET_END + DHCP_SOCKETS,   /*  0 */
    DNS_SOCKET_END = DHCP_SOCKET_END + DNS_SOCKETS,     /*  2 */
    WAP_SOCKET_END = DNS_SOCKET_END + WAP_SOCKETS,      /*  5 */
    STREAM_SOCKET_END = WAP_SOCKET_END + STREAM_SOCKETS,/*  5 */
    POC_J2ME_SOCKET_END = STREAM_SOCKET_END + POC_J2ME_SOCKETS,   /*  3 */
    EMAIL_SOCKET_END = POC_J2ME_SOCKET_END + EMAIL_SOCKETS,  /*  0 */
    VOIP_SOCKET_END = EMAIL_SOCKET_END + VOIP_SOCKETS,  /*  6 */

    MAX_IP_SOCKET_NUM = VOIP_SOCKET_END                 /* 25 */
};


#define MAX_SMS_SOCKET_NUM  (3)     /* max SMS sockets supported */

#define MAX_SOCKET_NUM      (MAX_IP_SOCKET_NUM + MAX_SMS_SOCKET_NUM)

#define IS_IP_SOCKET_NUM(s)     (0 <= (s) && (s) < MAX_IP_SOCKET_NUM)
#define IS_SMS_SOCKET_NUM(s)    (MAX_IP_SOCKET_NUM <= (s) && (s) < MAX_SOCKET_NUM)
#define IS_VALID_SOCKET_NUM(s)  (0 <= (s) && (s) < MAX_SOCKET_NUM)


/* Number of socket slots in TCPIP */
/* latter half part is temp socket id for incoming connections */
#define MAX_TCPIP_SOC_NUM     (MAX_IP_SOCKET_NUM * 2)

#define MAX_NWK_ACCT_SIZE           (4)

#define MAX_SOCK_ADDR_LEN           (28)

#define  IP_ADDR_LEN    (4)     /* length of an IP address */
#define  ETHER_ADDR_LEN     (6) /* length of an Ethernet address */

#if defined(__MTK_TARGET__) && !defined(WIN_SOC)


/* Protocol Familty */
#define PF_INET (0) /* currently only support Internet */


/* Protocols (RFC 1700) */


/* currently, only allow applicaion to set this type when RAW_SOCKET is used */
#define IPPROTO_ICMP    (1)     /* control message protocol */


/* for SOC/TCP/IP internal use, application shall NOT use */
#define IPPROTO_IP      (0)     /* dummy for IP */
#define IPPROTO_HOPOPTS (0)     /* IP6 hop-by-hop options */
#define IPPROTO_IGMP    (2)     /* group mgmt protocol */
#define IPPROTO_IPV4    (4)     /* IPv4 encapsulation */
#define IPPROTO_IPIP    IPPROTO_IPV4    /* for compatibility */
#define IPPROTO_TCP     (6)             /* tcp */
#define IPPROTO_UDP     (17)    /* user datagram protocol */
#define IPPROTO_RAW     (255)   /* raw IP packet */


/* Socket Type */
typedef enum
{
    SOCK_STREAM = 0,  /* stream socket, TCP */
    SOCK_DGRAM,       /* datagram socket, UDP */
    SOCK_SMS,         /* SMS bearer */
    SOCK_RAW          /* raw socket */
} socket_type_enum;


#else /* !defined(__MTK_TARGET__) || defined(WIN_SOC) */ 

typedef enum
{
    SOCK_SMS = 100         /* SMS bearer */
} socket_type_enum;

#endif /* !defined(__MTK_TARGET__) || defined(WIN_SOC) */ 

#define SOC_MSG_OOB         0x1     /* process out-of-band data */
#define SOC_MSG_PEEK        0X2     /* peek at incoming message */
#define SOC_MSG_DONTROUTE   0x4     /* send without using routing tables */
#define SOC_MSG_EOR         0x8     /* data completes record  */
#define SOC_MSG_TRUNC       0x10    /* data discarded before delivery  */
#define SOC_MSG_CTRUNC      0x20    /* control data lost before delivery */
#define SOC_MSG_WAITALL     0x40    /* wait for full request or error */
#define SOC_MSG_DONTWAIT    0x80    /* this message should be nonblocking */
#define SOC_MSG_EOF         0x100   /* data completes connection */
#define SOC_MSG_COMPAT      0x8000  /* used in sendit() */


/* Enums */
typedef enum
{
    TCPIP_ENOBUF = -20,
    TCPIP_ENOBUFS,        /* -19 */
    TCPIP_EINVAL,         /* -18 */
    TCPIP_EAFNOSUPPORT,   /* -17 */
    TCPIP_EPNOSUPPORT,    /* -16 */
    TCPIP_ECONNRESET,     /* -15 */
    TCPIP_EADDRINUSE,     /* -14 */
    TCPIP_EADDRNOTAVAIL,  /* -13 */
    TCPIP_EACCES,         /* -12 */
    TCPIP_EMSGSIZE,       /* -11 */
    TCPIP_EHOSTUNREACH,   /* -10 */
    TCPIP_ENETDOWN,       /*  -9 */
    TCPIP_EISCONN,        /*  -8 */
    TCPIP_ENOTCONN,       /*  -7 */
    TCPIP_ECONNREFUSED,   /*  -6 */
    TCPIP_EBEARERFAIL     /*  -5 */
} tcpip_error_cause;


/* howto arguments for shutdown(2), specified by Posix.1g. */
typedef enum
{
    SHUT_RD   = 0x01,         /* shut down the reading side */
    SHUT_WR   = 0x02,         /* shut down the writing side */
    SHUT_RDWR = SHUT_RD | SHUT_WR   /* shut down both sides */
} soc_shutdown_enum;


/* Socket Options */
typedef enum
{
    SOC_OOBINLINE     = 0x01 << 0,  /* not support yet */
    SOC_LINGER        = 0x01 << 1,  /* linger on close */
    SOC_NBIO          = 0x01 << 2,  /* Nonblocking */
    SOC_ASYNC         = 0x01 << 3,  /* Asynchronous notification */   

    SOC_NODELAY       = 0x01 << 4,  /* disable Nagle algorithm or not */
    SOC_KEEPALIVE     = 0x01 << 5,  
    SOC_RCVBUF        = 0x01 << 6,  
    SOC_SENDBUF       = 0x01 << 7,

    SOC_NREAD         = 0x01 << 8,  /* no. of bytes for read, only for soc_getsockopt */
    SOC_PKT_SIZE      = 0x01 << 9,  /* datagram max packet size */
    SOC_SILENT_LISTEN = 0x01 << 10, /* SOCK_SMS property */
    SOC_QOS           = 0x01 << 11,

    SOC_TCP_MAXSEG    = 0x01 << 12,
    SOC_IP_TTL        = 0x01 << 13,
    SOC_LISTEN_BEARER = 0x01 << 14,
    SOC_UDP_ANY_FPORT = 0x01 << 15,

    SOC_WIFI_NOWAKEUP = 0x01 << 16, /* send packet in power saving mode */
    SOC_UDP_NEED_ICMP = 0x01 << 17, /* deliver NOTIFY(close) for ICMP error */
    SOC_IP_HDRINCL    = 0x01 << 18,  /* IP header included for raw sockets */
    SOC_NON_AUTO_ACT_BEARER = 0x01 << 19, /* Non-auto activate bearer */
    SOC_AUTO_DEACT_BEARER   = 0x01 << 20 /* auto deactivate bearer */
} soc_option_enum;


typedef enum
{
    SOC_QOS_BEST_EFFORT = 0x00,  /* (DSCP, ToS) = (0x00, 0x00), (0x18, 0x60) */
    SOC_QOS_BACKGROUND  = 0x40,  /* (DSCP, ToS) = (0x10, 0x40), (0x08, 0x20) */
    SOC_QOS_VIDEO       = 0x80,  /* (DSCP, ToS) = (0x20, 0x80), (0x28, 0xA0) */
    SOC_QOS_VOICE       = 0xC0   /* (DSCP, ToS) = (0x30, 0xC0), (0x38, 0xE0) */
} soc_qos_enum;


/* Socket return codes, negative values stand for errors */
typedef enum
{
    SOC_SUCCESS           = 0,
    SOC_ERROR             = -1,
    SOC_WOULDBLOCK        = -2,
    SOC_LIMIT_RESOURCE    = -3,    /* limited resource */
    SOC_INVALID_SOCKET    = -4,    /* invalid socket */
    SOC_INVALID_ACCOUNT   = -5,    /* invalid account id */
    SOC_NAMETOOLONG       = -6,    /* address too long */
    SOC_ALREADY           = -7,    /* operation already in progress */
    SOC_OPNOTSUPP         = -8,    /* operation not support */
    SOC_CONNABORTED       = -9,    /* Software caused connection abort */
    SOC_INVAL             = -10,   /* invalid argument */
    SOC_PIPE              = -11,   /* broken pipe */
    SOC_NOTCONN           = -12,   /* socket is not connected */
    SOC_MSGSIZE           = -13,   /* msg is too long */
    SOC_BEARER_FAIL       = -14,   /* bearer is broken */
    SOC_CONNRESET         = -15,   /* TCP half-write close, i.e., FINED */
    SOC_DHCP_ERROR        = -16,
    SOC_IP_CHANGED        = -17,
    SOC_ADDRINUSE         = -18,
    SOC_CANCEL_ACT_BEARER = -19    /* cancel the activation of bearer */
} soc_error_enum;


/* event */
typedef enum
{
    SOC_READ    = 0x01,  /* Notify for read */
    SOC_WRITE   = 0x02,  /* Notify for write */
    SOC_ACCEPT  = 0x04,  /* Notify for accept */
    SOC_CONNECT = 0x08,  /* Notify for connect */
    SOC_CLOSE   = 0x10   /* Notify for close */
} soc_event_enum;


/* bearer */
typedef enum
{
    SOC_CSD  = 0x01,
    SOC_BEARER_CSD = SOC_CSD,
    SOC_GPRS = 0x02,
    SOC_BEARER_GPRS = SOC_GPRS,
    SOC_WIFI = 0x04,
    SOC_BEARER_WIFI = SOC_WIFI,
    SOC_BEARER_ANY = 0xff
} soc_bearer_enum;


typedef enum
{
    SOC_ACTIVATING,	
    SOC_ACTIVATED,
    SOC_DEACTIVATED,
    SOC_DEACTIVATING,
    SOC_AUTO_DISC_TIMEOUT
} soc_auto_disc_state_enum;



#endif /* !_SOC_CONSTS_H */



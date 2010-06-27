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
 * SOC2TCPIP_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCPIP and SOC.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _SOC2TCPIP_STRUCT_H
#define _SOC2TCPIP_STRUCT_H

#ifdef __FLC2__
#define SID2SPDU_UL_ID(_s_)     (FLC2_POOL_ID_SPDU_UL_0+(_s_))
#define SPDU_UL_ID2SID(_flcid_) ((_flcid_)-FLC2_POOL_ID_SPDU_UL_0)
#endif /* __FLC2__ */

#define MBUF_LENGTH (((sizeof(struct mbuf) + 3) >> 2) << 2)

#define TCPIP_OPT_DATA_LEN (52)

#define	ptom(p)	 ((mbuf*)((kal_uint8 *)p + (((sizeof(struct peer_buff_struct) + 3) >> 2) << 2)))
#define	mtop(m)  ((peer_buff_struct*)((kal_uint8 *)m - (((sizeof(struct peer_buff_struct) + 3) >> 2) << 2)))
#define	mtod(m, t)	((t)((m)->m_data))


typedef unsigned long	u_long;
typedef unsigned short	u_short;
typedef unsigned int	u_int;
typedef unsigned char	u_char;
typedef unsigned char	u_int8_t;
typedef char*           caddr_t;
typedef unsigned long	u_int32_t;
typedef unsigned short	u_int16_t;

typedef enum
{
    TCPIP_OPT_GETADDR,
    TCPIP_OPT_NODELAY,   /* disable Nagle algorithm or not */
    TCPIP_OPT_KEEPALIVE, 
    TCPIP_OPT_RCVBUF,  
    TCPIP_OPT_SENDBUF,
    TCPIP_OPT_QOS,
    TCPIP_OPT_TCP_MAXSEG,
    TCPIP_OPT_IP_TTL,
#if 0 /* TODO: Add support for linger option */
/* under construction !*/
#endif /* TODO: Add support for linger option */
    TCPIP_OPT_LISTEN_BEARER,
    TCPIP_OPT_UDP_ANY_FPORT,
    TCPIP_OPT_WIFI_NOWAKEUP,
    TCPIP_OPT_IP_HDRINCL
} soc_tcpip_option_enum;


typedef enum
{
	CLOSED = 0,
	FINED  = 1
} pcb_status;

typedef enum
{
	CONN_SUCCESS = 0,
	CONN_FAIL
} connect_status;

typedef enum
{
	DETACH_SUCCESS = 0,
	DETACH_FAIL
} detach_status;


/*UPLINK*/

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 socket_id;
    kal_uint8 sock_type;
    kal_uint8 protocol;
    kal_uint8 profile_id;
} soc_tcpip_attach_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 o_socket_id;   /* old */
    kal_int8 n_socket_id;   /* new */
    kal_uint8 profile_id;
} soc_tcpip_accept_res_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_int8 socket_id;
    kal_uint8 sock_type;
    sockaddr_struct so_addr;
    kal_uint8 profile_id;   
} soc_tcpip_bind_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_int8 socket_id;
    kal_uint8 sock_type;
    sockaddr_struct so_addr;
    kal_uint8 flags;
    kal_uint8 profile_id;
} soc_tcpip_send_req_struct;

typedef struct 
{
    kal_uint8    ref_count;
    kal_uint16   msg_len;
    /*kal_uint8    profile_id;*/
    kal_uint32    profile_id;
    kal_bool     is_activated;
    kal_uint8    bearer;         /* soc_bearer_enum */
    kal_uint16   mtu;   
    kal_uint8    ip_addr[4];
    kal_uint8    netmask[4];
    kal_uint8    gateway[4];
    kal_uint8    mac_addr[6];
} soc_tcpip_bearer_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 socket_id;
    kal_uint8 sock_type;
    kal_uint8 max_socket_no;
    kal_uint8 profile_id;
} soc_tcpip_listen_req_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 profile_id;
    kal_int8 socket_id;
    kal_uint8 sock_type;
    kal_uint16 option;

    kal_bool   is_set;
    kal_uint8 data_length;
    kal_uint32 data[TCPIP_OPT_DATA_LEN/4];
} soc_tcpip_option_req_struct;

typedef soc_tcpip_attach_req_struct soc_tcpip_close_req_struct;
typedef soc_tcpip_attach_req_struct soc_tcpip_shutdown_req_struct;
typedef soc_tcpip_attach_req_struct soc_tcpip_detach_req_struct;
typedef soc_tcpip_attach_req_struct soc_tcpip_disconnect_req_struct;

typedef soc_tcpip_bind_req_struct soc_tcpip_connect_req_struct;

/*DOWNLINK*/

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 socket_id;   
    kal_int8 result;
} soc_tcpip_attach_cnf_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 l_socket_id; /* listen */
    kal_int8 a_socket_id; /* temp */
    sockaddr_struct so_addr;
} soc_tcpip_accept_ind_struct;

/* obsoleted, embeded these info to mbuf structure */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 socket_id;
    kal_uint8 flags;
} soc_tcpip_receive_ind_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 result;   
    kal_int8 socket_id;   
    kal_uint16 option;
    kal_uint8 data_length;
    kal_uint32 data[TCPIP_OPT_DATA_LEN/4];
} soc_tcpip_option_cnf_struct;

typedef struct {
#define TCPIP_ERRMSG_LEN	(16)
	kal_uint8		ref_count;
	kal_uint16	msg_len;

	kal_int8	profile_id;
	kal_int8	socket_id;
	kal_uint8	protocol;		// IP, TCP, UDP, ICMP, ...
	kal_uint16	cause;		// IP conflict, ...

	kal_uint8		errmsg1_len;
	kal_uint32	errmsg1[TCPIP_ERRMSG_LEN/4];	/* for 4 byte aligmnent */
	kal_uint8		errmsg2_len;
	kal_uint32	errmsg2[TCPIP_ERRMSG_LEN/4];	/* for 4 byte aligmnent */
} soc_tcpip_errmsg_ind_struct;

typedef enum {
	IP_CONFLICT		/* IP conflict in LAN */
} tcpip_errmsg_cause_enum;

typedef soc_tcpip_attach_cnf_struct soc_tcpip_bind_cnf_struct;
typedef soc_tcpip_attach_cnf_struct soc_tcpip_connect_cnf_struct;
typedef soc_tcpip_attach_cnf_struct soc_tcpip_listen_cnf_struct;
typedef soc_tcpip_attach_cnf_struct soc_tcpip_shutdown_cnf_struct;
typedef soc_tcpip_attach_cnf_struct soc_tcpip_detach_cnf_struct;
typedef soc_tcpip_attach_cnf_struct soc_tcpip_close_ind_struct;
typedef soc_tcpip_attach_cnf_struct soc_tcpip_disconnect_cnf_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 socket_id;
    kal_uint16 release_amount;
} soc_tcpip_srpdu_release_res_struct;

struct PKTHDR
{
	kal_uint32	len;			/* total packet length */
	kal_uint8*	header;
} ;

typedef struct 
{
    kal_int16	addr_len;
    kal_uint8	addr[IP_ADDR_LEN];
    kal_uint16	port;
    kal_uint32	account;    
} ipv4_sockaddr_struct;

typedef struct mbuf
{
    struct mbuf    *m_nextpkt;	/* next packet */
    kal_uint8      *m_data;		/* location of data */
    kal_uint16	    m_len;		/* amount of data in this mbuf */
    kal_uint16 	    m_flags;    /* masking, ref M_SOC_ID, M_TPDU, M_FRAG, M_SMALL */
    struct mbuf    *m_next;		/* next fragment */
    struct PKTHDR   m_pkthdr;
    kal_int8        socket_id;  /* identifiers for SOC */
    kal_uint8       flags;      /* currently not used */
    ipv4_sockaddr_struct      sockaddr; /* reserved for ipv4_sockaddr_struct */
} mbuf;


typedef struct 
{
    kal_uint8    ref_count;
    kal_uint16   msg_len;
    kal_int8     socket_id;
    kal_uint16   mtu;
} soc_tcpip_mtu_update_ind_struct;

/*define for CBM.*/
typedef struct 
{
    kal_uint8    ref_count;
    kal_uint16   msg_len;
    kal_int8     socket_id;/*socket ID*/
    kal_uint8    profile_id;/*network account id*/
} soc_tcpip_set_acct_req_struct;

#endif /* ~_TCPIP2SOC_STRUCT_H */


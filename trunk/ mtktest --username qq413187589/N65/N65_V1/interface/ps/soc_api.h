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
 *	soc_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains structs and function prototypes of Socket API.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SOC_API_H
#define _SOC_API_H

#ifndef _APP2SOC_STRUCT_H
#include "app2soc_struct.h" /* soc_enums.h is included by app2soc_struct.h */
#endif /* !_APP2SOC_STRUCT_H */

#if (!defined(__MTK_TARGET__) || defined(WIN_SOC)) && !defined(GEN_FOR_PC)

/* PixtelDataTypes.h would like to define BOOL and CONST
 * Because soc_api.h includes windows.h implicitly, we dis-allow this order
 * whichs BOOL and CONST are overridden by windows.h
 *
 * PixtelDataTypes.h
 * soc_api.h (windows.h + soc_consts.h + socket API prototypes)
 */
#if !defined(_WINDOWS_) && defined(_PIXCOM_DATA_TYPES_H)
#error "Please include Windows.h before PixtelDataTypes.h in non __MTK_TARGET__ compile option"
#endif

#ifndef _WINSOCKAPI_
#include <winsock2.h>
#endif /* !_WINSOCKAPI_ */

#endif /* (!defined(__MTK_TARGET__) || defined(WIN_SOC)) && !defined(GEN_FOR_PC) */ 

#ifndef _SOC_CONSTS_H
#include "soc_consts.h"
#endif /* !_SOC_CONSTS_H */

/* Macros for SOC_SELECT */
#if defined(__MTK_TARGET__) && !defined(WIN_SOC)
typedef struct
{
    kal_uint8	fds_bits[MAX_IP_SOCKET_NUM];
} fd_set;

#define	SOC_FD_SET(s, p)            ((p)->fds_bits[s] |= 0x01)
#define	SOC_FD_CLR(s, p)            ((p)->fds_bits[s] &= ~(0x01))
#define	SOC_FD_ISSET(s, p)          ((p)->fds_bits[s] & 0x02)
#define	SOC_FD_ZERO(p)              kal_mem_set(p, 0x00, sizeof(*(p)))
#define	SOC_FD_COPY(orig, copy)     kal_mem_cpy(copy, orig, sizeof(*(orig)))

#else /* !defined(__MTK_TARGET__) || defined(WIN_SOC) */
extern int soc_free[];              /* storing socket id */
#define	SOC_FD_SET(s, p)            FD_SET(soc_free[s], p)
#define	SOC_FD_CLR(s, p)            FD_CLR(soc_free[s], p)
#define	SOC_FD_ISSET(s, p)          FD_ISSET(soc_free[s], p)
#define	SOC_FD_ZERO(p)              FD_ZERO(p)
#define	SOC_FD_COPY(orig, copy)     FD_COPY(orig, copy)
#endif /* !defined(__MTK_TARGET__) || defined(WIN_SOC) */ 

#define	SOCK_ACCT_ID(addr) (kal_uint8 *)((kal_uint8 *)addr + (MAX_SOCK_ADDR_LEN - MAX_NWK_ACCT_SIZE))

/*=============================
 * structs 
 *=============================*/
typedef struct 
{
    kal_uint32 tv_sec;  /* no. of second */
    kal_uint32 tv_usec; /* no. of microsecond */
} soc_timeval_struct;

typedef struct 
{
    socket_type_enum	sock_type;
    kal_int16	addr_len;
    kal_uint16	port;
    /* For keep the 4-byte boundary */
    /* please do not declare other variables above addr */
    kal_uint8	addr[MAX_SOCK_ADDR_LEN];
} sockaddr_struct;

typedef struct
{
    kal_bool   onoff;
    kal_uint16 linger_time; /* unit: sec */
} soc_linger_struct;

typedef struct
{
    kal_uint16                  tv_sec; /* unit: seconds */
    kal_uint16                  tv_usec; /*unit: micro seconds */
} soc_app_deact_timeval_struct;

typedef struct 
{ 
    kal_bool                     onoff; /* on: TRUE, off: FALSE */
    soc_app_deact_timeval_struct time;
} soc_app_bearer_deact_struct;


/*=================================================== 
 *
 * Socket APIs prototypes
 *
 *===================================================*/
extern kal_int8 soc_create(kal_uint8         domain,
                           socket_type_enum  type,
                           kal_uint8         protocol,
                           module_type       mod_id,
                           kal_uint32        nwk_account_id);

extern kal_int8 soc_close(kal_int8 s);

extern kal_int8 soc_bind(kal_int8 s, sockaddr_struct *addr);

extern kal_int8 soc_listen(kal_int8 s, kal_uint8 backlog);

extern kal_int8 soc_accept(kal_int8 s, sockaddr_struct *addr);

extern kal_int8 soc_connect(kal_int8 s, sockaddr_struct *addr);

extern kal_int32 soc_sendto(kal_int8	     s,
                            kal_uint8       *buf,
                            kal_int32	     len,
                            kal_uint8 	     flags,
                            sockaddr_struct *addr);

extern kal_int32 soc_send(kal_int8	 s,
                          kal_uint8  *buf,
                          kal_int32  len,
                          kal_uint8	 flags);

extern kal_int32 soc_recvfrom(kal_int8        s,
                              kal_uint8       *buf,
                              kal_int32       len,
                              kal_uint8       flags,
                              sockaddr_struct *fromaddr);

extern kal_int32 soc_recv(kal_int8  s,
                          kal_uint8 *buf,
                          kal_int32 len,
                          kal_uint8 flags);

#ifndef GEN_FOR_PC
extern kal_int8 soc_select(kal_uint8  ndesc,
                           fd_set     *in,
                           fd_set     *out,
                           fd_set     *ex,
                           soc_timeval_struct *tv);
#endif /* !GEN_FOR_PC */

extern kal_int8 soc_shutdown(kal_int8 s, kal_uint8 how);

extern
kal_int8 soc_setappopt(module_type mod_id,
                       kal_uint8 app_id, 
                       kal_uint32 option, void *val, 
                       kal_uint8 val_size);

extern
kal_int8 soc_getappopt(module_type mod_id,
                       kal_uint8 app_id, 
                       kal_uint32 option, void *val, 
                       kal_uint8 val_size);

extern kal_int8 soc_setsockopt(kal_int8   s,
                               kal_uint32 option,
                               void       *val,
                               kal_uint8  val_size);

extern kal_int8 soc_getsockopt(kal_int8   s,
                               kal_uint32 option,
                               void       *val,
                               kal_uint8  val_size);

/* currently, this function only support non-blocking mode */
extern
kal_int8 soc_gethostbyname(kal_bool is_blocking,
                           module_type     mod_id,
                           kal_int32       request_id,
                           const kal_char  *domain_name,
                           kal_uint8       *addr,
                           kal_uint8       *addr_len,
                           kal_uint8       access_id,
                           kal_uint32      nwk_account_id);


/* New API for resolving one domain name mapping to multiple IP addresses */
extern
kal_int8 soc_gethostbyname2(kal_bool is_blocking,
                           module_type     mod_id,
                           kal_int32       request_id,
                           const kal_char  *domain_name,
                           kal_uint8       *addr,
                           kal_uint8       *addr_len,
                           kal_uint8       access_id,
                           kal_uint32      nwk_account_id,
                           kal_uint8       in_entry_num,
                           kal_uint8       *out_entry_num);


/* currently, this function only support non-blocking mode */
extern
kal_int8 soc_gethostbyaddr(kal_bool         is_blocking,
                           module_type      mod_id,
                           kal_int32        request_id,
                           kal_char         *domain_name,
                           kal_uint32       *domain_name_len, 
                           const kal_uint8  *addr,
                           kal_uint8	    addr_len,
                           kal_uint8        access_id,
                           kal_uint32       nwk_account_id);

extern
kal_int8 soc_gethostbysrv(module_type         mod_id,
                          kal_int32           request_id,
                          const kal_char      *domain_name,
                          kal_uint8           access_id,
                          kal_uint32          nwk_account_id,
                          soc_dns_srv_struct  *entry,
                          kal_uint8           in_entry_num,
                          kal_uint8           *out_entry_num);

extern
kal_int8 soc_gethostbynaptr(module_type           mod_id,
                            kal_int32             request_id,
                            const kal_char        *domain_name,
                            kal_uint8             access_id,
                            kal_uint32            nwk_account_id,
                            soc_dns_naptr_struct  *entry,
                            kal_uint8             in_entry_num,
                            kal_uint8             *out_entry_num);

extern
kal_int8 soc_abort_dns_query(kal_bool     by_mod_id,
                             module_type  mod_id,
                             kal_bool     by_request_id,
                             kal_uint32   request_id,
                             kal_bool     by_access_id,
                             kal_uint8    access_id,
                             kal_bool     by_nwk_account_id,
                             kal_uint32   nwk_account_id);
                             
extern void soc_close_nwk_account(module_type mod_id);

extern void soc_close_nwk_account_by_id(module_type  mod_id,
                                        kal_uint32    account_id);
  
extern kal_int8 soc_getlocalip(kal_uint8 *local_ip);

extern 
kal_int8 soc_get_account_localip(kal_int8 s, kal_uint8 *local_ip);

extern 
kal_int8 soc_getsockaddr(kal_int8         s, 
                         kal_bool         is_local,
                         sockaddr_struct  *addr);

extern
kal_int8 soc_get_last_error(kal_int8   s,
                            kal_int8   *error, 
                            kal_int32  *detail_cause);

extern
kal_int8 soc_set_last_error(kal_int8   s,
                            kal_int8   error, 
                            kal_int32  detail_cause);

extern
kal_int8 soc_open_nwk_account(module_type mod_id, 
                              kal_uint32 account_id);

extern
kal_int8 soc_open_bearer(kal_int8 s);

extern
kal_int8 soc_close_bearer(kal_int8 s);

extern
kal_bool soc_ip_check(kal_char   *asci_addr, 
                      kal_uint8  *ip_addr, 
                      kal_bool   *ip_validity);

extern void soc_read_notify(kal_int8 s, kal_bool set);

extern kal_bool soc_ready_for_read(kal_int8 s);
extern kal_bool soc_set_csd_auto_disconnect_timer(kal_uint16 sec);
extern kal_uint16 soc_cksum(kal_uint16 *buf, kal_int32 len);
extern kal_int32 soc_set_module(kal_uint8 s, module_type mod);
extern kal_int32 soc_get_socket_acct(kal_uint8 s);

                      
#ifdef __MTK_TARGET__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
extern kal_uint32 htonl(kal_uint32 a);
#define ntohl(a)    htonl(a)
extern kal_uint16 htons(kal_uint16 a);
#define ntohs(a)    htons(a)
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __MTK_TARGET__ */
#define	NTOHL(x)	(x) = ntohl((kal_uint32)(x))
#define	NTOHS(x)	(x) = ntohs((kal_uint16)(x))
#define	HTONL(x)	(x) = htonl((kal_uint32)(x))
#define	HTONS(x)	(x) = htons((kal_uint16)(x))

#define IP_ALL_ZEROS(a)     (!(a[0] | a[1] | a[2] | a[3]))
#define IP_ALL_ONES(a)      (!((a[0] & a[1] & a[2] & a[3]) ^ 0xff))
#define IP_ALL_MATCH(a, b)  (!((a[0] ^ b[0]) | (a[1] ^ b[1]) | (a[2] ^ b[2]) | (a[3] ^ a[3])))

#endif /* !_SOC_API_H */



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
 * APP2SOC_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of Applications and SOC.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _APP2SOC_STRUCT_H
#define _APP2SOC_STRUCT_H

#ifndef _SOC_CONSTS_H
#include "soc_consts.h"
#endif /* !_SOC_CONSTS_H */

#define SOC_MAX_A_ENTRY              (5)
#define SOC_MAX_PTR_ENTRY            (1)
#define SOC_MAX_SRV_ENTRY            (2)
#define SOC_MAX_NAPTR_ENTRY          (3)
#define SOC_MAX_DNS_NAME_LEN         (255)
#define SOC_MAX_NAPTR_SRV_LEN        (70)
#define SOC_MAX_NAPTR_FLAGS_LEN      (3)
#define SOC_MAX_NAPTR_REGEXP_LEN     (100)


/* The structure for DNS A RR entry */
typedef struct
{
    kal_uint8 address[4];   /* resolved IP address for queried domain name */
} soc_dns_a_struct;


/* The structure for DNS PTR RR entry */
typedef struct
{
    kal_char ptrname[SOC_MAX_DNS_NAME_LEN];    /* resolved domain name
                                                 * for specific IP address */
} soc_dns_ptr_struct;


/* The structure for DNS SRV RR entry */
typedef struct
{
    kal_uint16  priority;   /* the client MUST attempt to use target host 
                             * with the lowest-numbered priority. */
    kal_uint16  weight;     /* relative weight for entries with the same
                             * priority.
                             * Larger weights SHOULD be given a proportionately
                             * higher probability of being selected. */
    kal_uint16  port;
    kal_char    target[SOC_MAX_DNS_NAME_LEN];  /* null terminated */

} soc_dns_srv_struct;


/* The structure for DNS NAPTR RR entry */
typedef struct
{
    kal_uint16  order;
    kal_uint16  pref;                              /* preference */
    kal_char    flag;     /* flags, RFC 3403, some chars */
    kal_char    flags[SOC_MAX_NAPTR_FLAGS_LEN];     /* flags, RFC 3403, some chars */
    kal_char    service[SOC_MAX_NAPTR_SRV_LEN];    /* null terminated */
    kal_char    regexp[SOC_MAX_NAPTR_REGEXP_LEN];  /* regular expression, null terminated */
    kal_char    replacement[SOC_MAX_DNS_NAME_LEN]; /* null terminated */
} soc_dns_naptr_struct;


typedef struct
{
   kal_uint8       ref_count;
   kal_uint16      msg_len;	
   kal_int8        socket_id;    /* socket ID */
   soc_event_enum  event_type;   /* soc_event_enum */
   kal_bool        result;
   soc_error_enum  error_cause;  /* used only when EVENT is close/connect */
   kal_int32       detail_cause; /* refer to ps_cause_enum if error_cause is
                                  * SOC_BEARER_FAIL */
} app_soc_notify_ind_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool    result;
    kal_int32	request_id;
    kal_uint8   access_id;
    kal_uint8	addr_len;   /* the first record in entry,  */
    kal_uint8	addr[16];   /* for backward compatibility */
    kal_uint8   num_entry;
    soc_dns_a_struct entry[SOC_MAX_A_ENTRY];

    /* New for DNS query reply for reporting bearer fail */
    kal_int8    error_cause;   /* bearer fail */
    kal_int32   detail_cause;  /* refer to ps_cause_enum if error_cause
                                * is SOC_BEARER_FAIL */
} app_soc_get_host_by_name_ind_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool	result;
    kal_int32   request_id;
    kal_uint8   access_id;
    kal_char    name[SOC_MAX_DNS_NAME_LEN];    /* null terminated */
    kal_uint8   num_entry;
    soc_dns_ptr_struct entry[SOC_MAX_PTR_ENTRY];
} app_soc_get_host_by_addr_ind_struct;


/* Notification to application the result of DNS SRV RR query */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool    result;
    kal_int32   request_id;
    kal_uint8   access_id;
    kal_uint8   num_entry;
    soc_dns_srv_struct entry[SOC_MAX_SRV_ENTRY];
} app_soc_get_host_by_srv_ind_struct;


/* Notification to application the result of DNS NAPTR RR query */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool    result;
    kal_int32   request_id;
    kal_uint8   access_id;
    kal_uint8   num_entry;
    soc_dns_naptr_struct entry[SOC_MAX_NAPTR_ENTRY];
} app_soc_get_host_by_naptr_ind_struct;


typedef struct
{
    kal_uint8        ref_count;
    kal_uint16       msg_len;	
    kal_uint8        ap_id;
    kal_uint32       account_id;
    soc_auto_disc_state_enum state; /* soc_auto_disc_state_enum (soc_api.h) */
    soc_bearer_enum  bearer;        /* soc_bearer_enum (soc_api.h) */
    kal_uint8        ip_addr[4];    /* valid only when state is SOC_ACTIVATED */

    /* connection statistics, valid only when state is SOC_DEACTIVATED */
    kal_uint32       conn_time;   /* unit: secs */
    kal_uint32       sent_bytes;
    kal_uint32       recv_bytes;

    kal_int32        error_cause; /* bearer error cause, refer cm_cause_enum */
    soc_error_enum   error;       /* SOC_BEARER_FAIL, or SOC_DHCP_ERROR */
} app_soc_bearer_info_ind_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;	
    kal_uint8   ap_id;
    kal_uint32   account_id;
    kal_bool    result;
    /* valid only when result is TRUE */
    kal_uint32  conn_time;   /* unit: secs */
    kal_uint32  sent_bytes;
    kal_uint32  recv_bytes;
} app_soc_deactivate_cnf_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;	
    kal_uint32   account_id; /* 0xff: all bearers */
} app_soc_deactivate_req_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  ret;
    kal_uint32  len;
    kal_bool    mf;
} app_ssl_data_output_msg_struct;
typedef app_ssl_data_output_msg_struct app_ssl_data_input_msg_struct;

#endif /* !_APP2SOC_STRUCT_H */ 


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
 * MMI2ABM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of data passed from MMI to ABM.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI2ABM_STRUCT_H
#define _MMI2ABM_STRUCT_H

#ifdef __WIFI_SUPPORT__
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mac_addr[WNDRV_MAC_ADDRESS_LEN];
} mmi_abm_wifi_init_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool use_dhcp;
    kal_uint8 ip_addr[4];
    kal_uint8 gateway[4];
    kal_uint8 netmask[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
} mmi_abm_ipaddr_change_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 selection_mode; //supc_ap_selection_mode_enum
    kal_uint16 num_of_profile;
    kal_uint8 more_flag;
    kal_uint8 connect_type;
    kal_uint8 always_ask_connect_flag;
    kal_uint8 always_ask_before_connect_flag;
    wifi_data_account_profile_struct profile_header_ptr[2];
} mmi_abm_wifi_connect_req_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool    result;
    kal_uint8   cause;
    kal_uint8   bssid[ WNDRV_MAC_ADDRESS_LEN ];
    kal_uint16  ssid_len;
    kal_uint8   ssid[ WNDRV_SSID_MAX_LEN ];
    kal_uint32  channel_number;
    kal_uint32  profile_id;
} mmi_abm_wifi_connect_cnf_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   bssid[ WNDRV_MAC_ADDRESS_LEN ];
    kal_uint16  ssid_len;
    kal_uint8   ssid[ WNDRV_SSID_MAX_LEN ];
    kal_uint32  channel_number;
    kal_uint32  profile_id;
} mmi_abm_wifi_connect_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_uint8 cause;
    kal_uint8 ip_addr[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
    kal_uint8 gateway[4];
    kal_uint8 netmask[4];
} mmi_abm_ipaddr_update_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 cause;
    kal_uint8 num;
    kal_uint8 more_flag;
    supc_abm_bss_info_struct ap_list[WNDRV_SCAN_RESULTS_NUM];
} mmi_abm_wifi_ap_list_cnf_struct;

typedef enum
{
    WLAN_NOT_AVAILABLE,
    WLAN_CONNECTING
} activate_req_rej_cause_enum;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    activate_req_rej_cause_enum cause;
} mmi_abm_wifi_activate_req_rej_struct;

#endif /* __WIFI_SUPPORT__ */

/* CBM Struct */
typedef struct
{
    kal_uint8  connect_type;
    kal_uint8  call_id;
    kal_uint8  context_id;
}mmi_abm_cbm_dialup_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 profile_id;
    kal_uint8  connect_type;
    mmi_abm_cbm_dialup_struct dailup_info;
}mmi_abm_cbm_active_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 profile_id;
    kal_uint8  connect_type;
    mmi_abm_cbm_dialup_struct dailup_info;
}mmi_abm_cbm_deactive_ind_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 profile_id;
    kal_uint8  connect_type;
    mmi_abm_cbm_dialup_struct dailup_info;
}mmi_abm_cbm_disconect_req_struct;

typedef struct  
{
    kal_uint32 profile_id;
    kal_uint8  connect_type;
    kal_uint8  result;
    mmi_abm_cbm_dialup_struct dailup_info;
}mmi_abm_cbm_bearer_req_count_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8  count;
    mmi_abm_cbm_bearer_req_count_struct bearer_req_count[20];
}mmi_abm_cbm_get_bearer_info_req_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8  count;
    kal_uint32 profile_id;
    kal_uint8  connect_type;
    kal_uint8  result;
    mmi_abm_cbm_dialup_struct dailup_info;
}mmi_abm_cbm_disconnect_cnf_struct;


typedef struct  
{
    kal_uint32 profile_id;
    kal_uint8  result;
    kal_uint32 send_data_size;
    kal_uint32 receive_data_size;
}mmi_abm_cbm_bearer_cnf_count_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8  count;
    kal_uint8  connect_type;
    mmi_abm_cbm_bearer_cnf_count_struct bearer_cnf_count[20];
}mmi_abm_cbm_get_bearer_info_cnf_struct;

#ifdef __UCM_SUPPORT__

typedef struct
{
	kal_uint8 ref_count;
       kal_uint16 msg_len;
       kal_uint8     prof_id;
        kal_uint8 call_num_len;
        kal_uint8  call_num_type;
#define ABM_MAX_CC_ADDR_LEN          41
     kal_uint8 call_num[ABM_MAX_CC_ADDR_LEN];
	kal_uint8	sim_info;
} mmi_abm_csd_call_approve_req_struct;


typedef struct
{
	kal_uint8 ref_count;
       kal_uint16 msg_len;
       kal_uint8     prof_id; 
	kal_uint8	sim_info;
    kal_bool result;
} mmi_abm_csd_call_approve_cnf_struct;

#endif /* __UCM_SUPPORT__ */

#endif /* _MMI2ABM_STRUCT_H */


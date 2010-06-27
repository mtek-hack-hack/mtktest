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
 *   bluetooth_bm_struct.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defines SAP for MTK Bluetooth.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_BM_STRUCT_H_
#define __BLUETOOTH_BM_STRUCT_H_

#define BTBM_ADP_MAX_NAME_LEN (59)
#define BTBM_ADP_MAX_SDAP_UUID_NO (15)

#define  BTBM_ADP_SUCCESS   (0)
#define  BTBM_ADP_FAILED     (1)
#define BTBM_ADP_BUSY           (2)
#define BTBM_ADP_NOT_ALLOW  (3)


#define BTBM_ADP_P_OFF_I_OFF (0x0)
#define BTBM_ADP_P_OFF_I_ON (0x1)
#define BTBM_ADP_P_ON_I_OFF (0x2)
#define BTBM_ADP_P_ON_I_ON (0x3)
#define BTBM_ADP_P_ON_I_ON_L (0x13)

#define BT_JSR82_SERVICE_SEARCH_REQ                          (0x00)
#define BT_JSR82_SERVICE_ATTRIBUTE_REQ                      (0x01)
#define BT_JSR82_SERVICE_SEARCH_ATTRIBUTE_REQ        (0x02)

typedef struct {
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
} btbm_bd_addr_t;

typedef enum 
{
    BTBM_ADP_NONVISIBLE = 0,
    BTBM_ADP_VISIBLE
}btbm_visual_mode;

typedef enum 
{
    BTBM_ADP_NONPAGEABLE = 0,
    BTBM_ADP_PAGEABLE
}btbm_page_mode;


typedef enum 
{
    BTBM_AUTHENTICATION_DISABLE = 0,
    BTBM_AUTHENTICATION_ENABLE,
    BTBM_AUTHENTICATION_ENABLE_LEVEL3_ENCRYPT_OFF,
    BTBM_AUTHENTICATION_ENABLE_LEVEL3_ENCRYPT_ON
}btbm_authentication_mode;

typedef enum 
{
    BTBM_GENERAL_INQUIRY = 0,
    BTBM_LIMITED_INQUIRY
}btbm_inquiry_channel_mode;


typedef enum 
{
    BTBM_DISCOVERY_WITH_NAME = 0,
    BTBM_DISCOVERY_WITHOUT_NAME
}btbm_discovery_mode;

typedef enum 
{
    BTBM_TYPE_PAIRING = 0,
    BTBM_TYPE_BONDING
}btbm_pairing_mode;

#ifdef __GEMINI__
/* MSG_ID_BT_POWERON_REQ: Add for GEMIMI Project 2008-0107 */
typedef struct
{
    kal_uint8 	ref_count;
    kal_uint16 	msg_len;
    kal_uint8    dual_sim_uart_setting;
}bt_poweron_req_struct;
#endif

typedef struct  
{
    LOCAL_PARA_HDR
    kal_uint32	cod;
    kal_uint8	inquiry_length;
    kal_uint8	inquiry_number;
    btbm_inquiry_channel_mode	access_mode;
    btbm_discovery_mode	discovery_mode;
}bt_bm_discovery_req_struct;


typedef struct  
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint32	cod;
    kal_uint8	name_len;
    kal_uint8	name[BTBM_ADP_MAX_NAME_LEN];
}bt_bm_discovery_result_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    kal_uint8	total_number;
}bt_bm_discovery_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    kal_uint8	total_number;
}bt_bm_discovery_cancel_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	name_len;
    kal_uint8	name[BTBM_ADP_MAX_NAME_LEN];
}bt_bm_write_local_name_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
}bt_bm_write_local_name_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	name_len;
    kal_uint8	name[BTBM_ADP_MAX_NAME_LEN];
}bt_bm_read_local_name_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
}bt_bm_read_remote_name_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
    kal_uint8	name_len;
    kal_uint8	name[BTBM_ADP_MAX_NAME_LEN];
    kal_uint32  cod;
}bt_bm_read_remote_name_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	modenotconnected;
    kal_uint8	modeconnected;
}bt_bm_write_scanenable_mode_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
}bt_bm_write_scanenable_mode_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8      result;
    kal_uint8	modenotconnected;
    kal_uint8	modeconnected;
}bt_bm_read_scanenable_mode_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t  bd_addr;
}bt_bm_read_local_addr_cnf_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    kal_uint32	cod;
}bt_bm_read_local_cod_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32	cod;
}bt_bm_write_local_cod_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8	result;
}bt_bm_write_local_cod_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    kal_uint8	spec_version;
    kal_uint8	master_switch;
    kal_uint8	retrievable_max;
    kal_uint8	connected_max;
    kal_uint16	received_l2cap_mtu;
    kal_uint8	sdp_transaction_max;
    btbm_visual_mode	        connected_inquiry_scan;
    btbm_page_mode	connected_page_scan;
    btbm_visual_mode	        connected_inquiry;
    btbm_page_mode	connected_page;
}bt_bm_read_property_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_authentication_mode	mode;
}bt_bm_write_authentication_mode_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
}bt_bm_write_authentication_mode_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint8	name_len;
    kal_uint8	name[BTBM_ADP_MAX_NAME_LEN];
}bt_bm_pin_code_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint8	pin_len;
    kal_uint8	pin_code[16];
}bt_bm_pin_code_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
}bt_bm_delete_trust_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
}bt_bm_delete_trust_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
}bt_bm_delete_trust_all_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
}bt_bm_bonding_cancel_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
}bt_bm_bonding_cancel_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
}bt_bm_pairing_cancel_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
}bt_bm_pairing_cancel_cnf_struct;

    
typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint8	sdap_len;
    kal_uint32	sdap_uuid[BTBM_ADP_MAX_SDAP_UUID_NO];
}bt_bm_bonding_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
}bt_bm_bonding_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
}bt_bm_acl_link_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
}bt_bm_acl_link_close_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
    kal_uint32  cod;
}bt_bm_bonding_result_ind_struct;



typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint8	sdap_len;
    kal_uint32	sdap_uuid[BTBM_ADP_MAX_SDAP_UUID_NO];
}bt_bm_service_search_req_struct;

			
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32	uuid;
    btbm_bd_addr_t	bd_addr;
}bt_bm_service_search_result_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
    kal_uint8   searched_number;
}bt_bm_service_search_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint32	sdap_uuid;
    kal_uint16	attribute_id;
}bt_bm_search_attribute_req_struct;

#define BT_MAX_SDAP_RAW_SIZE 150

typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint8 search_type;
    kal_uint8 search_pattern[BT_MAX_SDAP_RAW_SIZE];
    kal_uint8 search_pattern_size;

}bt_bm_search_raw_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint16	len;
    kal_uint8	data[100];
}bt_bm_search_raw_result_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint8 result;
}bt_bm_search_raw_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
    kal_uint16	len;
    kal_uint8	data[56];
}bt_bm_search_attribut_result_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
}bt_bm_search_attribute_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
}bt_bm_save_setting_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
}bt_bm_restore_setting_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 string[100];
}bt_test_cmd_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 uuid;
}  bt_sdpdb_register_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 uuid;
}  bt_sdpdb_deregister_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    kal_uint32 uuid;
}  bt_sdpdb_register_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    kal_uint32 uuid;
}  bt_sdpdb_deregister_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    btbm_bd_addr_t	bd_addr;
}bt_bm_link_connect_accept_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
    btbm_bd_addr_t	bd_addr;
}bt_bm_link_connect_accept_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	max_number;
    kal_uint8	current_number;
}bt_bm_link_state_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bdaddr[6];
}bt_bm_get_link_state_req;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_bool is_master;
    kal_bool is_authenticated;    
    kal_bool is_encrypted;        
}bt_bm_get_link_state_cnf;
#endif


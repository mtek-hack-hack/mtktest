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
 * bt_hidd_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for hidd adp sap
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_HIDD_STRUCT_H
#define BT_HIDD_STRUCT_H

#ifdef __BT_HIDD_PROFILE__



#ifndef BT_DM_STRUCT_H
#error "bt_dm_struct.h should be included"
#endif
/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef enum
{
	hidd_state_idle, /* hidd_deactivated */
	hidd_state_activated,
	hidd_state_connected,

	hidd_state_activating,
	hidd_state_deactivating,
	hidd_state_connecting,
	hidd_state_disconnecting,
	hidd_state_authorizing,	
	hidd_state_total
		
} bt_hidd_state;

typedef enum
{
	hidd_result_ok,
	hidd_result_failed,
        hidd_result_sco_reject,
	hidd_result_total
	
} bt_hidd_result_enum;

typedef enum
{
	hidd_connect_authorization_result_accepted,
	hidd_connect_authorization_result_rejected,
	hidd_connect_authorization_total
	
} bt_hidd_connect_authorization_enum;

typedef enum 
{
	hidda_ctrl_eq_unknow,
	hidda_ctrl_eq_keyboard,
	hidda_ctrl_eq_mouse,
	hidda_ctrl_eq_total

} hidda_ctrl_eq_struct;

typedef enum
{
	hidd_ctrl_op_nop,
	hidd_ctrl_op_hard_reset,
	hidd_ctrl_op_soft_reset,
	hidd_ctrl_op_suspend,
	hidd_ctrl_op_exit_suspend,
	hidd_ctrl_op_virtual_cable_unplug,
	hidd_ctrl_op_total
	
} bt_hidd_ctrl_op_enum;

typedef enum
{
	hidd_report_other,
	hidd_report_input,
	hidd_report_output,
	hidd_report_feature,
	hidd_report_total
	
} bt_hidd_report_type_enum;

typedef enum
{
	hidd_protocol_bool,
	hidd_protocol_report,
	hidd_protocol_total
	
} bt_hidd_protocol_type_enum;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
} bt_hidd_activate_cnf_struct;


typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
} bt_hidd_deactivate_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
} bt_hidd_connect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hidd_connect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;    
} bt_hidd_connect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hidd_connection_authorize_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hidd_connection_authorize_rsp_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;    
} bt_hidd_disconnect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hidd_disconnect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hidd_disconnect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_ctrl_op_enum ctrl_op;
} bt_hidd_control_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_ctrl_op_enum ctrl_op;
} bt_hidd_control_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_ctrl_op_enum ctrl_op;
} bt_hidd_control_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_report_type_enum	report_type;    
    kal_uint16	data_len;
    kal_uint8		*data_ptr;    
} bt_hidd_interrupt_data_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_report_type_enum	report_type;    
} bt_hidd_interrupt_data_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_report_type_enum	report_type;    
    kal_uint16	data_len;
    kal_uint8		*data_ptr;    
} bt_hidd_interrupt_data_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_report_type_enum	report_type;    
    kal_uint8	report_id;
    kal_uint16	buffer_size;
} bt_hidd_get_report_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_report_type_enum	report_type;    
    kal_uint16	data_len;
    kal_uint8		*data_ptr;    
} bt_hidd_get_report_rsp_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_report_type_enum	report_type;    
    kal_uint16	data_len;
    kal_uint8		*data_ptr;    
} bt_hidd_set_report_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_report_type_enum	report_type;    
} bt_hidd_set_report_rsp_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hidd_get_protocol_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_protocol_type_enum protocol_type;
} bt_hidd_get_protocol_rsp_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_protocol_type_enum protocol_type;
} bt_hidd_set_protocol_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    bt_hidd_protocol_type_enum protocol_type;
} bt_hidd_set_protocol_rsp_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hidd_get_idle_rate_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    kal_uint8	idle_rate;
} bt_hidd_get_idle_rate_rsp_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    kal_uint8	idle_rate;
} bt_hidd_set_idle_rate_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hidd_result_enum	result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    kal_uint8	idle_rate;
} bt_hidd_set_idle_rate_rsp_struct;



/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/             
                                                                                           
/*****************************************************************************              
* Functions                                                                    
*****************************************************************************/     


#endif //__BT_HIDD_PROFILE__

#endif//BT_HIDD_STRUCT_H


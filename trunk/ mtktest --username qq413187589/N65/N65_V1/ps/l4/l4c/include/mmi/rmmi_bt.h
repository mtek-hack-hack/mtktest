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
 * Filename:
 * ---------
 * rmmi_bt.h
 *
 * Description:
 * ------------
 *   This file implements the AT parser and command handler for Bluetooth.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *
*****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef RMMI_BT_H
#define RMMI_BT_H

#include "uart_sw.h"

#define RMMI_BT_STATE_CHANGE(a) { \
	kal_trace(TRACE_GROUP_3, RMMI_BT_STATE_TRANS, RMMI_PTR->BT_action, RMMI_PTR->BT_action, a, a );\
	RMMI_PTR->BT_action = a;\
	}

#define RMMI_BT_LOG_STATE()  kal_trace(TRACE_GROUP_3, RMMI_BT_ACTION, RMMI_PTR->BT_action )


#ifdef __BT_DEBUG__
#define RMMI_BT_ASSERT(a) { \
	if(!a) l4c_bt_close_log_file(2); \
	ASSERT(a); \
	}
#else
#define RMMI_BT_ASSERT(a){\
	extern kal_bool g_mmi_frm_enable_debug_assert;\
	if(!a) l4c_bt_close_log_file(2); \
	do{if (g_mmi_frm_enable_debug_assert) ASSERT(a);} while(0);\
	}
#endif

#define RMMI_BT_MAX_FNAME_LEN 20
#define RMMI_BT_SCO_PROTECT_CNT 3
#define RMMI_BT_MAX_CMD_QUEUE_CNT 5

typedef struct {
	kal_uint8 index;
	kal_uint8 bd_addr[6];
}bt_trust_device_struct;

typedef struct _bt_cmd_struct{
	kal_uint8 *bt_cmd;
}bt_cmd_struct;

typedef struct _bt_cmd_queue_struct{
	kal_uint16 cmd_count;
	bt_cmd_struct bt_cmd_queue[RMMI_BT_MAX_CMD_QUEUE_CNT];
}bt_cmd_queue_struct;

typedef enum{
	BT_PAIR_COMPLETE,
	BT_PAIR_TIMEOUT,
	BT_PAIR_CANCEL,
	BT_PAIR_FAIL,
	BT_PAIR_NOT_FINISH
}bt_pin_verify_err_enum;

typedef enum{
	BT_NO_AUTH,
	BT_AUTH
}bt_authenticate_type_enum;

typedef enum{
	BT_PROF_RESERVED = 0,
	BT_PROF_HS = 1, 	//Audio Gateway
	BT_PROF_SPP= 2, 	//Serial port
	BT_PROF_DUN = 3, 	//Dial-up Networking
	BT_PROF_HF = 4, 	//Handsfree Profile
	BT_PROF_FAX = 5	//Fax Profile
}bt_profile_enum;

typedef enum{
	BT_RFC_CONN_COMPLETE,
	BT_RFC_CONN_TIMEOUT,
	BT_RFC_CONN_CANCEL,
	BT_RFC_CONN_DISCONN,
	BT_RFC_CONN_ABNORM,
	BT_RFC_CONN_REFUSED,
	BT_RFC_CONN_NOT_SUP,
	BT_RFC_CONN_FAILED
}bt_rfcomm_status_enum;

typedef enum{
	BT_SCO_CONN_COMPLETE,
	BT_SCO_CONN_TIMEOUT,
	BT_SCO_CONN_CANCEL,
	BT_SCO_CONN_DISCONN,
	BT_SCO_CONN_ABNORM,
	BT_SCO_CONN_REFUSED,
	BT_SCO_CONN_NOT_SUP,
	BT_SCO_CONN_FAIL
}bt_sco_status_enum;

typedef enum{
	BT_ERR_CONN_REQ_WHEN_NOT_IDLE,
	BT_ERR_PAIR_REQ_WHEN_NOT_IDLE,
	BT_ERR_CANCEL_REQ_WHEN_IDLE, 
	BT_ERR_DATA_REQ_WHEN_NOT_IDLE,
	BT_ERR_INQ_REQ_WHEN_NOT_IDLE,
	BT_ERR_SCO_CONNECTED,
	BT_ERR_DISCON_WHEN_NOT_CONN,
	BT_ERR_SM_DEVICE_DB_ERROR,
	BT_ERR_UNSUPPORTED,
	BT_WARNING_LOCAL_SNIFF_NOT_ENABLE,
	BT_WARNING_LOCAL_PARK_NOT_ENABLE,
	BT_WARNING_LOW_POWER_MODE_NOT_ENABLE,
	BT_WARNING_REMOTE_NOT_SUPPORT_SNIFF,
	BT_WARNING_REMOTE_NOT_SUPPORT_PARK,
	BT_WARNING_REMOTE_NOT_ENABLE_LOW_POWER,
	
	BT_ERR_RECOVERED = 99,

	BT_ERR_LAST
}bt_error_reason_enum;

typedef enum{
	BT_INQ_COMPLETE,
	BT_INQ_CANCEL,
	BT_INQ_MAX_RECV, 
	BT_INQ_NOT_FINISH
}bt_inq_status_enum;

typedef enum{
	BT_GATEWAY_UNKNOWN_ERROR,
       BT_GATEWAY_IDLE,
       BT_GATEWAY_CONNECTING = 6,
       BT_GATEWAY_CONNECTABLE,
       BT_GATEWAY_CONNECTED,
       BT_GATEWAY_DISCOVERBABLE,
       BT_GATEWAY_INQUIRING,
       BT_GATEWAY_HOST_INQUIRING_ALL,
       BT_GATEWAY_HOST_INQUIRING_AUDIO,
       BT_GATEWAY_PAIRING_AS_SLAVE,
       BT_GATEWAY_PAIRING_AS_MASTER,
       BT_GATEWAY_PAIRING_TO_DEVICE,
       BT_GATEWAY_PAIR_SUCCESSFUL,
       BT_GATEWAY_PAIR_UNSUCCESSFUL,
       BT_GATEWAY_CONNECT_PENDING
}bt_gateway_status_enum;

typedef enum{
		
   /* Power off */
   RMMI_BT_PWROFF,    /* 0 */
   
   /* Power on  Procedure */
	RMMI_BT_PWRON,
	RMMI_BT_PWRON_SETADDR,
	RMMI_BT_PWRON_SETNAME,
	RMMI_BT_PWRON_SETGFLAG,
	RMMI_BT_PWRON_SETHFPFEATURE,	
	RMMI_BT_PWRON_SETMAXTXPOWER,	
	RMMI_BT_PWRON_SET_USR17,
	RMMI_BT_PWRON_SET_USR18,	
	RMMI_BT_PWRON_SETDEFAULTTXPOWER,	
	RMMI_BT_PWRON_SETPCM, /* 5 */
	RMMI_BT_PWRON_SETSCODEC,
	RMMI_BT_PWRON_SETPROF,
	RMMI_BT_PWRON_SETWKSIG,
	RMMI_BT_PWRON_RESET,
	
   /* Idle Mode */
   RMMI_BT_IDLE,
   
   /* Trust Device Control */
   RMMI_BT_SET_TD_WAIT,     /* 10 */
   RMMI_BT_DEL_TD_WAIT, /* Reserved, the device won't return ok/error */
   
   /* Inquiry Request */	
   RMMI_BT_INQ_WAIT,
   RMMI_BT_INQ_RES,
   
   /* Authentication */
	RMMI_BT_PAIR_WAIT,
   RMMI_BT_PIN_REQ_WAIT,
   RMMI_BT_SET_PIN_WAIT,
   
   /* Page Request */
   RMMI_BT_PAGE_WAIT,
   RMMI_BT_CONNECTED,
   RMMI_BT_DISCON_WAIT,
   
   /* Page/Inquiry Scan */
   RMMI_BT_SCAN,    /* 20 */
   RMMI_BT_SCAN_CANCEL,

	/* SCO Link establish */
	RMMI_BT_SCO_WAIT,

   /* Friendly name Request */
	RMMI_BT_SET_NAME,
   
   /* Set PS KEY Request */
	RMMI_BT_SET_PSKEY,

   /* Cancel OP */
   RMMI_CANCELOP_WAIT,    /* 25 */
   
	//following state is for Test mode power on
	RMMI_BT_TEST_PWRON,
	RMMI_BT_TEST_SETPROF,
	RMMI_BT_TEST_RESET,
	RMMI_BT_TEST_CDIS,
   RMMI_BT_TEST_CEDUT,     /* 30 */
   RMMI_BT_TEST_MODE,
   
   
   //following state is for internal debugging
   RMMI_BT_GET_STAT,

   /* Force State */
   RMMI_BT_FORCE_IDLE,
   RMMI_BT_FORCE_IDLE_WAIT,
   RMMI_BT_FORCE_SCAN,
   RMMI_BT_FORCE_SCAN_WAIT,
   
   
   RMMI_BT_STAT_LAST
}rmmi_bt_action_enum;
 
typedef enum{
	RMMI_BT_DEV_PHONE_UNCLASSIFIED,
	RMMI_BT_DEV_PHONE_CELLULAR,
	RMMI_BT_DEV_PHONE_CORDLESS,
	RMMI_BT_DEV_PHONE_SMARTPHONE,
	RMMI_BT_DEV_PHONE_WIRED_MODAM,
	RMMI_BT_DEV_AUDIO_UNCLASSIFIED,
	RMMI_BT_DEV_AUDIO_HEADSET,
	RMMI_BT_DEV_COMPUTER_UNCLASSIFIED,
	RMMI_BT_DEV_COMPUTER_DESKTOP,
	RMMI_BT_DEV_COMPUTER_SERVER,
	RMMI_BT_DEV_COMPUTER_LAPTOP,
	RMMI_BT_DEV_COMPUTER_HANDHELD,
	RMMI_BT_DEV_COMPUTER_PALM,
	RMMI_BT_DEV_OTHERS
}rmmi_bt_dev_class_enum;


extern void l4c_bt_ccnr(void);
extern void	rmmi_bt_error_recover(rmmi_bt_action_enum act, bt_error_reason_enum cause, bt_gateway_status_enum bc_state, bt_sco_status_enum sco);
extern void rmmi_bt_sync_state(bt_gateway_status_enum bc_state, bt_sco_status_enum sco_state);

extern void rmmi_bt_init(void);
extern kal_bool rmmi_bt_cmd_processor (rmmi_string_struct *source_string_ptr, kal_uint16 cmd_length);                        
extern kal_bool rmmi_bt_cmd_validator ( rmmi_string_struct *source_string_ptr);

extern void rmmi_bt_cinqres_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_cinqcfm_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_cpinreq_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_clink_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_cpincfm_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_crfcstat_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_cscostat_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_vgs_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_ckpd_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_ok_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_error_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_cprofile_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_nrec_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_bvra_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_binq_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_cstat_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_cbd_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_getps_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_lname_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_crreg_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_rnr_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_ccfg_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_wakeok_hdlr (rmmi_string_struct *source_string_ptr);
extern void rmmi_bt_dlist_hdlr(rmmi_string_struct *source_string_ptr);

extern void rmmi_bt_send_btcmd(kal_uint8 *string);
extern void rmmi_bt_write_to_uart(kal_uint8 *string);
extern void rmmi_bt_send_cwup(void);
extern void rmmi_bt_cwup_timeout_hdlr(void);
extern void rmmi_bt_start_timer(kal_uint8 time); //time unit is 100ms
extern void rmmi_bt_stop_timer(void);

extern void rmmi_bt_poll_data_select_timeout_hdlr(void);
extern void rmmi_bt_poll_data_select_start_timer(kal_uint8 time);
extern void rmmi_bt_poll_data_select_stop_timer(void);

extern void rmmi_bt_eint_hdlr(void);

extern void rmmi_bt_cmd_queue_init(void);
extern void rmmi_bt_add_cmd_to_queue(kal_uint8* string);
extern kal_bool rmmi_bt_get_bc_state(void);
extern UART_PORT rmmi_BT_GetPort_Setting(UARTDCBStruct *DCB);
extern kal_uint8 rmmi_BT_GetResetGpio(void);
extern void rmmi_bt_pwron(void);
extern void rmmi_bt_pwroff(void);

extern void l4c_bt_pwron_req(kal_uint8 src_id, kal_uint8* my_bd_addr, kal_uint8* name, kal_uint8 visibility, bt_authenticate_type_enum auth);
extern void l4c_bt_pwron_lrsp(kal_bool result);
extern void l4c_bt_pwroff_req(kal_uint8 src_id);
extern void l4c_bt_pwroff_lrsp(void);
extern void l4c_bt_panic_lind(void);
extern void l4c_bt_set_name_req(kal_uint8 src_id, kal_uint8* name);
extern void l4c_bt_set_name_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_set_pskey_req(kal_uint8 src_id, kal_uint8* pskey, kal_uint8* data, kal_uint8* store);
extern void l4c_bt_set_pskey_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_get_pskey_req(kal_uint8 src_id, kal_uint8* pskey);
extern void l4c_bt_get_pskey_lrsp(kal_uint8* data);
extern void l4c_bt_info_lind(kal_uint8* my_bd_addr);
extern void l4c_bt_reg_dev_lind(void);
extern void l4c_bt_set_tr_dev_req(kal_uint8 src_id,  kal_uint8* bd_addr, kal_uint8* link_key);
extern void l4c_bt_set_tr_dev_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_del_tr_dev_req(kal_uint8 src_id, kal_uint8 idx, kal_uint8* bd_addr);
extern void l4c_bt_del_tr_dev_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_get_tr_dev_req(kal_uint8 src_id);
extern void l4c_bt_get_tr_dev_lrsp(kal_uint8 num, bt_trust_device_struct* devs);
extern void l4c_bt_inq_req(kal_uint8 src_id, kal_uint8 code, kal_uint8 no_rsp);
extern void l4c_bt_inq_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_inq_lind(bt_inq_status_enum status, kal_uint8 idx, kal_uint8* name, kal_uint8* bd_addr, kal_uint8 type);
extern void l4c_bt_pair_req(kal_uint8 src_id, kal_uint8 idx, kal_uint8* bd_addr);
extern void l4c_bt_pair_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_pin_req_lind(kal_uint32 handle, kal_uint8* bd_addr);
extern void l4c_bt_set_pin_req(kal_uint8 src_id, kal_uint32 handle, kal_uint8 idx, kal_uint8* bd_addr, kal_uint8* link_key);
extern void l4c_bt_set_pin_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_linkkey_lind(bt_pin_verify_err_enum result, kal_uint8* bd_addr, kal_uint8* link_key, kal_uint32 handle);
extern void l4c_bt_page_scn_req(kal_uint8 src_id, bt_authenticate_type_enum auth);
extern void l4c_bt_page_req(kal_uint8 src_id, kal_uint8 source, kal_uint8 idx, kal_uint8* bd_addr, bt_authenticate_type_enum auth, bt_profile_enum prof);
extern void l4c_bt_page_lrsp(kal_bool  result,kal_uint8  cause);
extern void l4c_bt_inq_scan_req(kal_uint8 src_id, kal_uint8 visibility, bt_authenticate_type_enum auth);
extern void l4c_bt_inq_scan_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_rf_conn_lind(kal_uint32 handle, kal_uint8* bd_addr, bt_rfcomm_status_enum status);
extern void l4c_bt_prof_conn_lind(bt_profile_enum prof);
extern void l4c_bt_ring_req(kal_uint8 src_id);
extern void l4c_bt_nocarrier_req(kal_uint8 src_id);
extern void l4c_bt_ckpd_lind(kal_uint8 keycode, kal_uint8 keytype);
extern void l4c_bt_cancel_op_req(kal_uint8 src_id);
extern void l4c_bt_cancel_op_lrsp(void);  //mtk00714 add on 20050223
extern void l4c_bt_add_sco_req(kal_uint8 src_id, kal_uint8 sco_type);
extern void l4c_bt_rmv_sco_req(kal_uint8 src_id);
extern void l4c_bt_sco_state_lind(kal_uint32 handle, bt_sco_status_enum status);
extern void l4c_bt_pair_as_slave_req(kal_uint8 src_id);
extern void l4c_bt_pair_as_slave_lrsp(kal_bool result, kal_uint8 cause);
extern void l4c_bt_get_state_req(kal_uint8 src_id);
extern void l4c_bt_get_state_lrsp(bt_gateway_status_enum conn_status, bt_sco_status_enum sco_status);
extern void l4c_bt_rmv_rfcomm_req(kal_uint8 src_id);
extern void l4c_bt_call_answer_lind(void);
extern void l4c_bt_call_hangup_lind(void);
extern void l4c_bt_error_lind(bt_error_reason_enum reason);
extern void l4c_bt_volume_level_lind(kal_uint8 level);
extern void l4c_bt_disconnect_req(void);
extern void l4c_bt_disconnect_lrsp(void);
extern void l4c_bt_data_accept_req(kal_bool accept);
extern void l4c_bt_data_accept_lrsp(void);
extern void l4c_bt_fcty_set_param_lind(kal_uint8* name, kal_uint8* bd_addr, kal_uint8 dcs);
extern void l4c_bt_enter_testmode_req(kal_uint8 mode);
extern void l4c_bt_enter_testmode_lrsp(kal_bool result);
extern void l4c_bt_poweron_status_lind(kal_uint8 count);
extern void l4c_bt_enter_testmode_rsp(kal_uint8 src_id, kal_bool result);
extern void l4c_bt_set_testmode(kal_uint8 src_id, kal_uint8 mode);
extern void l4c_bt_start_guard_timer(void);
extern void l4c_bt_clear_guard_timer(void);
extern void l4c_bt_guard_timeout_hdlr(void);
extern void l4c_bt_sco_protection_timeout_hdlr(void);
extern void l4c_bt_start_sco_protection(void);
extern void l4c_bt_stop_sco_protection(void);
extern void l4c_bt_force_idle_req(kal_uint8 type);
extern void l4c_bt_force_scan_req(kal_uint8 vis, kal_uint8 auth);

extern void l4c_bt_force_idle_lrsp(kal_uint8 result, kal_uint8 stat);
extern void l4c_bt_force_scan_lrsp(kal_uint8 result, kal_uint8 stat);

#endif



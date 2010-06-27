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
 *	sim_trc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is trace map definition.
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
 *==============================================================================
 *******************************************************************************/

#ifndef _SIM_TRC_H
#define _SIM_TRC_H


#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

BEGIN_TRACE_MAP(MOD_SIM)

   /* TRACE_FUNC trace class */   
   TRC_MSG(FUNC_SIM_ERROR_HANDLE,"sim_error_handler()")			
   TRC_MSG(FUNC_SIM_SMU_ERROR_HANDLE,"sim_smu_error_handler()")			
   TRC_MSG(FUNC_SIM_READ_ECC_ELP,"sim_read_ecc_elp()")			
   TRC_MSG(FUNC_SIM_PROFILE_DOWNLOAD,"sim_profile_download()")	
   TRC_MSG(FUNC_SIM_READ_PHASE,"sim_read_phase()")				
   TRC_MSG(FUNC_SIM_GET_DN_TYPE,"sim_get_dn_type()")				
   TRC_MSG(FUNC_SIM_GET_PS_INFO,"sim_get_ps_info()")				
   TRC_MSG(FUNC_SIM_READ_SERVICE_TABLE,"sim_read_service_table()")	
   TRC_MSG(FUNC_SIM_INITIALIZATION,"sim_initialization()")				
   TRC_MSG(FUNC_SIM_GET_CHV_INFO,"sim_get_chv_info()")				
   TRC_MSG(FUNC_SIM_TIMER_EXPIRY_HANDLER,"sim_timer_expiry_handler()")   
   TRC_MSG(FUNC_SIM_STARTUP_READ,"sim_startup_read()")                  	
   TRC_MSG(FUNC_SIM_START_REQ_HANDLER,"sim_start_req_handler()") 	
   TRC_MSG(FUNC_SIM_WRITE_REQ_HANDLER,"sim_write_req_handler()")   
   TRC_MSG(FUNC_SIM_READ_REQ_HANDLER,"sim_read_req_handler()")	
   TRC_MSG(FUNC_SIM_INCREASE_REQ_HANDLER,"sim_increase_req_handler()")		
   TRC_MSG(FUNC_SIM_SECURITY_REQ_HANDLER,"sim_security_req_handler()")  
   TRC_MSG(FUNC_SIM_RUN_ALGO_REQ_HANDLER,"sim_run_algo_req_handler()")
   TRC_MSG(FUNC_SIM_SEEK_REQ_HANDLER,"sim_seek_req_handler()")
   TRC_MSG(FUNC_SIM_FILE_INFO_REQ_HANDLER,"sim_file_info_req_handler()")
   TRC_MSG(FUNC_SIM_DIAL_MODE_REQ_HANDLER,"sim_dial_mode_req_handler()")
   TRC_MSG(FUNC_SIM_STATUS_REQ_HANDLER,"sim_status_req_handler()")   
   TRC_MSG(FUNC_SIM_POWEROFF_REQ_HANDLER,"sim_poweroff_req_handler()")
   TRC_MSG(FUNC_ECODE_TEXT_STRING,"ecode_text_string()")
   TRC_MSG(FUNC_DECODE_TEXT_STRING,"decode_text_string()")
   TRC_MSG(FUNC_DECODE_ICON_ID,"decode_icon_id()")
   TRC_MSG(FUNC_DECODE_ALPHA_ID,"decode_alpha_id()")
   TRC_MSG(FUNC_DECODE_ONLY_DATA_BLOCK,"decode_only_data_block()")  	
   TRC_MSG(FUNC_DECODE_ONLY_U8,"decode_only_u8()")
   TRC_MSG(FUNC_DECODE_DURATION,"decode_duration()") 
   TRC_MSG(FUNC_DECODE_ITEM,"decode_item()")   
   TRC_MSG(FUNC_DECODE_ITEM_NEXT_ACTION_IND,"decode_item_next_action_ind()")
   TRC_MSG(FUNC_DECODE_ITEM_ICON_ID_LIST,"decode_item_icon_id_list")	
   TRC_MSG(FUNC_DECODE_FILE_LIST,"decode_file_list()")   
   TRC_MSG(FUNC_ENCODE_TEXT_STRING,"encode_text_string()")

   TRC_MSG(FUNC_SIM_START_TIMER,"sim_start_timer()") 			//Benson 0204
   TRC_MSG(FUNC_SIM_STOP_TIMER,"sim_stop_timer()")   			//Benson 0204
   TRC_MSG(FUNC_SIM_AL_RESET,"sim_al_reset()")					//Benson 0204
   TRC_MSG(FUNC_SIM_SELECT,"sim_select()")						//Benson 0204
   TRC_MSG(FUNC_SIM_RESET_ABNORMAL,"sim_reset_abnormal()") 	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_VERIFY_CHV,"sim_al_verify_chv()")		//Benson 0204
   TRC_MSG(FUNC_SIM_AL_UNBLOCK_CHV,"sim_al_unblock_chv()")	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_CHANGE_CHV,"sim_al__change_chv()")	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_ENABLE_CHV,"sim_al_enable_chv()")		//Benson 0204
   TRC_MSG(FUNC_SIM_AL_DISABLE_CHV,"sim_al_disable_chv()")		//Benson 0204
   TRC_MSG(FUNC_SIM_AL_READ_BINARY,"sim_al_read_binary()")		//Benson 0204
   TRC_MSG(FUNC_SIM_AL_UPDATE_BINARY,"sim_al_update_binary()")	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_UPDATE_RECORD,"sim_al_update_record()")	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_RUN_GSM_ALGO,"sim_al_run_gsm_algo()")	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_SEEK,"sim_al_run_gsm_algo()")			//Benson 0204
   TRC_MSG(FUNC_SIM_AL_STATUS,"sim_al_status()")				//Benson 0204
   TRC_MSG(FUNC_SIM_AL_REHABILITATE,"sim_al_rehabilitate()")		//Benson 0204
   TRC_MSG(FUNC_SIM_AL_INVALIDATE,"sim_al_invalidate()")			//Benson 0204
   TRC_MSG(FUNC_SIM_AL_INCREASE,"sim_al_increase()")			//Benson 0204
   TRC_MSG(FUNC_SIM_AL_POWEROFF,"sim_al_poweroff()")			//Benson 0204	
   TRC_MSG(FUNC_SIM_AL_READ_RECORD,"sim_al_read_record()")	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_GET_RESPONSE,"sim_al_get_response()")	//Benson 0204
   TRC_MSG(FUNC_SIM_AL_FETCH,"sim_al_fetch()")
   TRC_MSG(FUNC_SIM_AL_TERMINAL_RESPONSE,"sim_al_terminal_response()")
   TRC_MSG(FUNC_SIM_AL_TERMINAL_PROFILE,"sim_al_terminal_profile()")
   TRC_MSG(FUNC_SIM_AL_ENVELOPE,"sim_al_envelope()")

   TRC_MSG(FUNC_SIM_BT_SAP_CONNECT_REQ_HANDLER, "bt_sim_connect_req_handler()")		//Nick 20070117
   TRC_MSG(FUNC_SIM_BT_SAP_RESET_REQ_HANDLER, "bt_sim_reset_req_handler()")			//Nick 20070117
   TRC_MSG(FUNC_SIM_BT_SAP_APDU_REQ_HANDLER, "bt_sim_apdu_req_handler()")				//Nick 20070117
   TRC_MSG(FUNC_SIM_BT_SAP_DISCONNECT_REQ_HANDLER, "bt_sim_disconnect_req_handler()")	//Nick 20070117
   TRC_MSG(FUNC_SIM_BT_SAP_POWER_OFF_REQ_HANDLER, "bt_sim_power_off_req_handler()")	//Nick 20070117

   /* TRACE_STATE trace class */   
  TRC_MSG(STATE_SIM_RESET,"SIM: RESET SIM STATE")			//Benson 0204
  TRC_MSG(STATE_SIM_PUK1,"SIM: SIM PUK1 STATE")				//Benson 0204
  TRC_MSG(STATE_SIM_REFRESH,"SIM: SIM REFRESH STATE")		//Benson 0204
  TRC_MSG(STATE_SIM_CARD_NOT_INSERTED,"SIM: SIM Card Not Inserted")	//Benson 0204
  TRC_MSG(STATE_SIM_SELECT_CMD_SUCCESS,"SIM: sim_select() success!")		//Benson 0204
  TRC_MSG(STATE_SAT_REFRESH_BUSY,"SAT REFRESH BUSY: send file change ind")			//Benson 0204
  TRC_MSG(STATE_SIM_CMD_SUCCESS,"SIM: SIM_CMD_SUCCESS")				//Benson 0204
  TRC_MSG(STATE_SIM_CMD_FAIL,"SIM: SIM_CMD_FAIL")						//Benson 0204
  TRC_MSG(STATE_SIM_FATAL_ERROR,"SIM: SIM_FATAL_ERROR")					//Benson 0204
  TRC_MSG(STATE_SIM_CHV_NOT_INIT,"SIM: SIM_CHV_NOT_INIT")				//Benson 0204
  TRC_MSG(STATE_SIM_CHV_RETRY_ALLOW,"SIM: SIM_CHV_RETRY_ALLOW")		//Benson 0204
  TRC_MSG(STATE_SIM_CHV_BLOCK,"SIM: SIM_CHV_BLOCK")					//Benson 0204
  TRC_MSG(STATE_SIM_ACCESS_NOT_ALLOW,"SIM: SIM_ACCESS_NOT_ALLOW")	//Benson 0204
  TRC_MSG(STATE_SIM_SAT_CMD_BUSY,"SIM: SIM_SAT_CMD_BUSY")				//Benson 0204
  TRC_MSG(STATE_SIM_DL_ERROR,"SIM: SIM_DL_ERROR")						//Benson 0204
  TRC_MSG(STATE_SIM_MEMORY_PROBLEM,"SIM: SIM_MEMORY_PROBLEM")			//Benson 0204
  TRC_MSG(STATE_SIM_TECHNICAL_PROBLEM,"SIM: SIM_TECHNICAL_PROBLEM")	//Benson 0204
  TRC_MSG(STATE_SIM_PUK_UNLOCK,"SIM: SIM_PUK_UNLOCK")					//Benson 0204
  TRC_MSG(STATE_SIM_30V,"SIM: 3.0 V SIM")									//Benson 04142004
  TRC_MSG(STATE_SIM_18V,"SIM: 1.8V SIM")									//Benson 04142004
  TRC_MSG(STATE_SIM_RESET_30V,"SIM RESET at 3.0V")						//Benson 04142004
  TRC_MSG(STATE_SIM_RESET_18V,"SIM RESET at 1.8V")						//Benson 04142004
  TRC_MSG(STATE_SIM_FILE_NOT_FOUND,"FILE_NOT_FOUND")
  TRC_MSG(STATE_SIM_BT_SAP_APDU_PROTOCOL_TYPE_0,"Transport Protocol Type: 0")			//Nick 20070117
  TRC_MSG(STATE_SIM_BT_SAP_APDU_PROTOCOL_TYPE_1,"Transport Protocol Type: 1")			//Nick 20070117
   /* TRACE_INFO trace class */   
   TRC_MSG(INFO_SIM_SELECT_FILE, "SIM_FILE_SELECTED: %02X %02X ")
   TRC_MSG(INFO_SIM_STATUS_WORD, "SIM_STATUS_WORD:   %02X %02X")
   TRC_MSG(INFO_SAT_TIMER_EXPIRE_MESSAGE_RCVD,"Timer Expiry Message is received")
   TRC_MSG(INFO_SIM_BT_SAP_CONNECT_SUCCESS,"BT_SAP_CONNECT_SUCCESS")			//Nick 20070117
   TRC_MSG(INFO_SIM_BT_SAP_CONNECT_FAILED,"BT_SAP_CONNECT_FAILED")					//Nick 20070117
   TRC_MSG(INFO_SIM_BT_SAP_RESET_SUCCESS,"BT_SAP_RESET_SUCCESS")					//Nick 20070117
   TRC_MSG(INFO_SIM_BT_SAP_RESET_FAILED,"BT_SAP_RESET_FAILED")						//Nick 20070117
   TRC_MSG(INFO_SIM_BT_SAP_DISCONNECT_SUCCESS,"BT_SAP_DISCONNECT_SUCCESS")		//Nick 20070117
   TRC_MSG(INFO_SIM_BT_SAP_DISCONNECT_FAILED,"BT_SAP_DISCONNECT_FAILED")			//Nick 20070117
   /* TRACE_GROUP SIM_CMD_APDU */
   TRC_MSG(GROUP3_SIM_CMD_TX, "%Msim_instruction_code_enum : length: %d")
   TRC_MSG(GROUP3_SIM_CMD_RX, "APDU_rx length: %d")
   TRC_MSG(GROUP3_SIM_CMD_APDU_TX, "APDU_tx %d: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")
   TRC_MSG(GROUP3_SIM_CMD_APDU_RX, "APDU_rx %d: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")

/*------------------ usim_driver_interface.c -------------------------------------*/ 
   TRC_MSG(INFO_USIM_AL_SELECT,"SELECT:%Musim_file_index_enum PATH: %02X%02X,%02X%02X,%02X%02X => %Musim_sw_enum") 
   TRC_MSG(INFO_USIM_AL_STATUS,"STATUS => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_READ_BINARY,"READ BINARY  offset: %d length: %d => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_UPDATE_BINARY,"UPDATE BINARY offset: %d length: %d => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_READ_RECORD,"READ RECORD rec# %d size: %d => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_UPDATE_RECORD,"UPDATE_RECORD rec# %d size: %d => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_SEARCH_RECORD,"SEARCH RECORD => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_INCREASE,"INCREASE size: %d => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_VERIFY,"VERIFY => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_CHANGE_PIN,"CHANGE PIN => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_DISABLE_PIN,"DISABLE PIN => %Musim_sw_enum") 
   TRC_MSG(INFO_USIM_AL_ENABLE_PIN,"ENABLE PIN => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_UNBLOCK_PIN,"UNBLOCK PIN => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_DEACTIVATE_FILE,"DEACTIVATE FILE: %Musim_file_index_enum PATH: %02X%02X,%02X%02X,%02X%02X => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_ACTIVATE_FILE,"ACTIVATE FILE: %Musim_file_index_enum PATH: %02X%02X,%02X%02X,%02X%02X => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_AUTHENTICATE,"AUTHENTICATE => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_GET_CHALLENGE,"GET CHALLENGE: %d bytes => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_TERMINAL_PROFILE,"TERMINAL PROFILE => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_ENVELOPE,"ENVELOPE: send %d bytes recv %d bytes => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_FETCH,"FETCH %d bytes => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_TERMINAL_RESPONSE,"TERMINAL RESPONSE => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_MANAGE_CHANNEL,"MANAGE CHANNEL %Musim_channel_op_enum %Musim_logic_channel_enum => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_AL_GET_RESPONSE,"GET RESPONSE => %Musim_sw_enum")
   TRC_MSG(INFO_USIM_STATUS_WORD,"USIM CMD STATUS: %Musim_sw_enum")

   /* TRACE_WARNING trace class */   


   /* TRACE_ERROR trace class */   
   TRC_MSG(ERROR_SIM_CARD_REMOVED,"SIM_ERROR: SIM_CARD_REMOVED")	//Benson 0204
   TRC_MSG(ERROR_SIM_ACCESS_ERROR,"SIM_ERROR: SIM_ACCESS_ERROR")	//Benson 0204
   TRC_MSG(ERROR_SIM_REFRESH,"SIM_ERROR: SIM_REFRESH")				//Benson 0204
   TRC_MSG(ERROR_SIM_PUK1,"SIM_ERROR: SIM_PUK1")					//Benson 0204
   TRC_MSG(ERROR_SIM_RESET_ABNORMAL_CMD_RETRY,"SIM_RESET_ABNORMAL: command retry") //Benson 0209
   
    /* TRACE_GROUP trace class*/
   TRC_MSG(GROUP2_BUILD_TERMINAL_RESPONSE,"build_terminal_response()")
   TRC_MSG(GROUP2_SAT_PROCOMM_DISPLAY_TEXT,"sat_procomm_display_text()")   
   TRC_MSG(GROUP2_SAT_PROCOMM_GET_INKEY,"sat_procomm_get_inkey()")
   TRC_MSG(GROUP2_SAT_PROCOMM_GET_INPUT,"sat_procomm_get_input()")
   TRC_MSG(GROUP2_SAT_PROCOMM_PLAY_TONE,"sat_procomm_play_tone()")
   TRC_MSG(GROUP2_SAT_PROCOMM_SETUP_MENU,"sat_procomm_setup_menu()")   
   TRC_MSG(GROUP2_SAT_PROCOMM_SELECT_ITEM,"sat_procomm_select_item()")   
   TRC_MSG(GROUP2_SAT_PROCOMM_SEND_SMS,"sat_procomm_send_sms()")    
   TRC_MSG(GROUP2_SAT_PROCOMM_SEND_SS,"sat_procomm_send_ss()")   
   TRC_MSG(GROUP2_SAT_PROCOMM_SEND_USSD,"sat_procomm_send_ussd()")   
   TRC_MSG(GROUP2_SAT_PROCOMM_SETUP_CALL,"sat_procomm_setup_call()")   
   TRC_MSG(GROUP2_SAT_PROCOMM_MORE_TIME,"sat_procomm_more_time()")
   TRC_MSG(GROUP2_SAT_PROCOMM_REFRESH,"sat_procomm_refresh()")  
   TRC_MSG(GROUP2_SAT_PROCOMM_POLL_INTERVAL,"sat_procomm_poll_interval()") 
   TRC_MSG(GROUP2_SAT_PROCOMM_POLLING_OFF,"sat_procomm_polling_off") 	
   TRC_MSG(GROUP2_SAT_PROCOMM_PROVIDE_LOCAL_INFO,"sat_procomm_provide_local_info()")
   TRC_MSG(GROUP2_SAT_PROCOMM_SETUP_EVENT_LIST,"sat_procomm_setup_event_list()")
   TRC_MSG(GROUP2_SAT_PROCOMM_PERFORM_CARD_APDU,"sat_procomm_perform_card_apdu()")
   TRC_MSG(GROUP2_SAT_PROCOMM_POWER_OFF_CARD,"sat_procomm_power_off_card()")
   TRC_MSG(GROUP2_SAT_PROCOMM_POWER_ON_CARD,"sat_procomm_power_on_card()")
   TRC_MSG(GROUP2_SAT_PROCOMM_GET_READER_STATUS,"sat_procomm_get_reader_status()")
   TRC_MSG(GROUP2_SAT_PROCOMM_TIMER_MANAGEMENT,"sat_procomm_timer_management()")
   TRC_MSG(GROUP2_SAT_PROCOMM_SET_UP_IDLE_MODE_TEXT,"sat_procomm_set_up_idle_mode_text()")
   TRC_MSG(GROUP2_SAT_PROCOMM_RUN_AT_COMMAND,"sat_procomm_run_at_command()")
   TRC_MSG(GROUP2_SAT_PROCOMM_SEND_DTMF,"sat_procomm_send_dtmf()")
   TRC_MSG(GROUP2_SAT_PROCOMM_LANGUAGE_NOTIFICATION,"sat_procomm_language_notification()")
   TRC_MSG(GROUP2_SAT_PROCOMM_LAUNCH_BROWSER,"sat_procomm_launch_browser()")
   TRC_MSG(GROUP2_SAT_PROCOMM_OPEN_CHANNEL,"sat_procomm_open_channel()")
   TRC_MSG(GROUP2_SAT_PROCOMM_CLOSE_CHANNEL,"sat_procomm_close_channel()")
   TRC_MSG(GROUP2_SAT_PROCOMM_RECEIVE_DATA,"sat_procomm_recv_data()")
   TRC_MSG(GROUP2_SAT_PROCOMM_SEND_DATA,"sat_procomm_send_data()")
   TRC_MSG(GROUP2_SAT_PROCOMM_GET_CHANNEL_STATUS,"sat_procomm_ch_status()")
//   TRC_MSG(GROUP2_FIND_MODIFIED_TYPE,"find_modified_type()")
   TRC_MSG(GROUP2_SAT_SET_UP_IDLE_MODE_TEXT_RES_HANDLER,"sat_set_up_idle_mode_text_res_handler()")
   TRC_MSG(GROUP2_SAT_RUN_AT_COMMAND_RES_HANDLER,"sat_run_at_command_res_handler()")
   TRC_MSG(GROUP2_SAT_SEND_DTMF_RES_HANDLER,"sat_send_dtmf_res_handler()")
   TRC_MSG(GROUP2_SAT_LANGUAGE_NOTIFICATION_RES_HANDLER,"sat_language_notification_res_handler()")
   TRC_MSG(GROUP2_SAT_LAUNCH_BROWSER_RES_HANDLER,"sat_launch_browser_res_handler()")
   TRC_MSG(GROUP2_SAT_OPEN_GPRS_CHANNEL_RES_HANDLER,"sat_open_gprs_channel_res_handler()")
   TRC_MSG(GROUP2_SAT_OPEN_CSD_CHANNEL_RES_HANDLER,"sat_open_csd_channel_res_handler()")
   TRC_MSG(GROUP2_SAT_CLOSE_CHANNEL_RES_HANDLER,"sat_close_channel_res_handler()")
   TRC_MSG(GROUP2_SAT_SEND_DATA_RES_HANDLER,"sat_send_data_res_handler()")
   TRC_MSG(GROUP2_SAT_RECV_DATA_RES_HANDLER,"sat_recv_data_res_handler()")
   TRC_MSG(GROUP2_SAT_CH_STATUS_RES_HANDLER,"sat_ch_status_res_handler()")   

   TRC_MSG(GROUP2_SAT_PROVIDE_LOCAL_INFORMATION_HANDLER,"sat_provide_local_information_handler()")   
   TRC_MSG(GROUP2_SAT_PROACTIVE_CMD_PROCESS,"sat_proactive_cmd_process()")

   TRC_MSG(GROUP2_SAT_FILE_CHANGE_RES_HANDLER,"sat_file_change_res_handler()")  
   TRC_MSG(GROUP2_SAT_DSPL_TEXT_RES_HANDLER,"sat_dspl_text_res_handler()")   
   TRC_MSG(GROUP2_SAT_GET_INKEY_RES_HANDLER,"sat_get_inkey_res_handler()")
   TRC_MSG(GROUP2_SAT_GET_INPUT_RES_HANDLER,"sat_get_input_res_handler()")
   TRC_MSG(GROUP2_SAT_PLAY_TONE_RES_HANDLER,"sat_play_tone_res_handler()")   
   TRC_MSG(GROUP2_SAT_SETUP_MENU_RES_HANDLER,"sat_setup_menu_res_handler()")   
   TRC_MSG(GROUP2_SAT_SELECT_ITEM_RES_HANDLER,"sat_select_item_res_handler()")   
   TRC_MSG(GROUP2_SAT_SEND_SMS_RES_HANDLER,"sat_send_sms_res_handler()")   
   TRC_MSG(GROUP2_SAT_SEND_SS_RES_HANDLER,"sat_send_ss_res_handler()")   
   TRC_MSG(GROUP2_SAT_SEND_USSD_RES_HANDLER,"sat_send_ussd_res_handler()")   
   TRC_MSG(GROUP2_SAT_SETUP_CALL_RES_HANDLER,"sat_setup_call_res_handler()")   
   TRC_MSG(GROUP2_SAT_SMS_DL_REQ_HANDLER,"sat_sms_dl_req_handler()")
   TRC_MSG(GROUP2_SAT_CB_DL_REQ_HANDLER,"sat_cb_dl_req_handler()")   
   TRC_MSG(GROUP2_SAT_MENU_SELECT_REQ_HANDLER,"sat_menu_select_req_handler()")   
   TRC_MSG(GROUP2_SAT_CALL_CTRL_BY_SIM_REQ_HANDLER,"sat_call_ctrl_by_sim_req_handler()")
   TRC_MSG(GROUP2_SAT_EVDL_MT_CALL,"sat_evdl_mt_call()")
   TRC_MSG(GROUP2_SAT_EVDL_CALL_CONNECT,"sat_evdl_call_connect()")
   TRC_MSG(GROUP2_SAT_EVDL_CALL_DISCONNECT,"sat_evdl_call_disconnect()")
   TRC_MSG(GROUP2_SAT_EVDL_LOCATION_STATUS,"sat_evdl_location_status()")
   TRC_MSG(GROUP2_SAT_EVDL_USER_ACTIVITY,"sat_evdl_user_activity()")
   TRC_MSG(GROUP2_SAT_EVDL_IDLE_SCREEN_AVAILABLE,"sat_evdl_idle_screen_available()")
   TRC_MSG(GROUP2_SAT_EVDL_CARD_READER_STATUS,"sat_evdl_card_reader_status()")
   TRC_MSG(GROUP2_SAT_EVDL_LANGUAGE_SELECTION,"sat_evdl_language_selection()")
   TRC_MSG(GROUP2_SAT_EVDL_BROWSER_TERMINATION,"sat_evdl_browser_termination()")
   TRC_MSG(GROUP2_SAT_EVDL_DATA_AVAILABLE,"sat_evdl_data_available()")
   TRC_MSG(GROUP2_SAT_EVDL_CHANNEL_STATUS,"sat_evdl_channel_status()")
   TRC_MSG(GROUP2_SAT_TIMER_EXPIRATION,"sat_timer_expiration()")


//   TRC_MSG(GROUP2_SAT_CALL_CTRL_CHECK,"sat_call_ctrl_check()")
//   TRC_MSG(GROUP2_SAT_SMS_CTRL_CHECK,"sat_sms_ctrl_check()")
   TRC_MSG(GROUP2_SAT_SEND_SMS_CTRL_BY_SIM_REQ_HANDLER,"sat_send_sms_ctrl_by_sim_req_handler()")
   TRC_MSG(GROUP2_SAT_CALL_STATUS_IND_HANDLER,"sat_call_status_ind_handler()")
   TRC_MSG(GROUP2_SAT_START_BASE_TIMER,"sat_start_base_timer()")
   TRC_MSG(GROUP2_SAT_STOP_BASE_TIMER,"sat_stop_base_timer()")
   TRC_MSG(GROUP2_SAT_START_TIMER,"sat_start_timer()")
   TRC_MSG(GROUP2_SAT_STOP_TIMER,"sat_stop_timer()")
   TRC_MSG(GROUP2_SAT_TIMER_EXPIRY_HDLR,"sat_timer_expiry_hdlr()")
#ifdef __USIM_SUPPORT__  
   TRC_MSG(GROUP3_USIM_CMD_TX, "%Musim_instruction_code_enum : length: %d")
   TRC_MSG(GROUP3_USIM_CMD_RX, "APDU_rx length: %d") 
   TRC_MSG(GROUP3_USIM_CMD_APDU_TX, "APDU_tx %d: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")
   TRC_MSG(GROUP3_USIM_CMD_APDU_RX, "APDU_rx %d: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")
#endif /* __USIM_SUPPORT__ */
#ifdef __GEMINI__
   //dual SIM control message (driver)
   TRC_MSG(SIM_GEMINI_CMD1, "[SIM_CMD1] %x %x %x %x, %x %x %x %x")
   TRC_MSG(SIM_GEMINI_CMD2, "[SIM_CMD2] %x %x %x %x, %x %x %x %x")
   TRC_MSG(SIM_GEMINI_CMD3, "[SIM_CMD3] %x %x %x %x, %x %x %x %x")
   TRC_MSG(SIM_GEMINI_GEN1, "[SIM_GEN1] file %x, line %x, %x %x, %x %x %x %x")
#endif /* __GEMINI__ */
END_TRACE_MAP(MOD_SIM)
#endif





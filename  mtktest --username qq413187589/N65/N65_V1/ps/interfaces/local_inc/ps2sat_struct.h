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
 * PS2SAT_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SIM toolkit's message
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : ps2sat_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _PS2SAT_STRUCT_H
#define _PS2SAT_STRUCT_H

#define MAX_SIM_ADDR_LEN          41
#define MAX_SIM_ADDR_BCD_LEN      21
#define MAX_SIM_SUB_ADDR_LEN      41
#define MAX_SIM_SUB_ADDR_BCD_LEN  21
#define MAX_TERMINAL_PROFILE_LEN 20

typedef struct {
    kal_uint8 icon_attr;
    kal_uint8 icon_id;
} sat_icon_struct;

/* PH 03042005 Remote SAT */
typedef struct {
    kal_uint8 length;
    kal_uint8 profile[MAX_TERMINAL_PROFILE_LEN];
} rsat_terminal_profile_struct;

typedef enum
{
   RSAT_BY_TE,
   RSAT_BY_SIM,
   RSAT_BY_L4C,
   RSAT_NULL   
} rsat_config_enum;


typedef enum
{
    RSAT_DISPLAY_TEXT,
    RSAT_GET_INKEY,
    RSAT_GET_INPUT,
    RSAT_MORE_TIME,
    RSAT_PLAY_TONE,
    RSAT_POLL_INTERVAL,
    RSAT_REFRESH_I,
    RSAT_REFRESH_II,
    RSAT_REFRESH_III,
    RSAT_REFRESH_IV,
    RSAT_REFRESH_V,
    RSAT_SETUP_MENU,
    RSAT_SELECT_ITEM,
    RSAT_SEND_SMS,
    RSAT_SEND_SS,
    RSAT_SEND_USSD,
    RSAT_SETUP_CALL,
    RSAT_POLLING_OFF,
    RSAT_LOCAL_INFO_I,
    RSAT_LOCAL_INFO_II,
    RSAT_LOCAL_INFO_III,
    RSAT_LOCAL_INFO_IV,
    RSAT_LOCAL_INFO_V,
    RSAT_LOCAL_INFO_VI,
    RSAT_SETUP_EVENT_LIST,
    RSAT_TIMER_MANAGEMENT,
    RSAT_SETUP_IDLE_TEXT,
    RSAT_SEND_DTMF,
    RSAT_LANG_NOTIFY,
    RSAT_SIZE
} rsat_type_enum;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 proactive_cmd_len;
    kal_uint8 proactive_cmd[260];
} sat_proactive_cmd_ind_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 procomm[256];
    rsat_config_enum is_wait_for_rsp;
} sat_procomm_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 length;
    kal_uint8 terminal_rsp[261];
} sat_terminal_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    rsat_terminal_profile_struct terminal_profile;
    kal_uint8 rsat_setting[RSAT_SIZE];
} sat_profile_download_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint16 result;  /* sim_cmd_result_enum */
    kal_uint8 sim_phase; /* sim_phase_enum */
} sat_profile_download_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_moretime_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_poll_interval_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 length;
    kal_uint8 envelope[261];
} sat_envelope_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint16 result; /* sim_cmd_result_enum */
} sat_envelope_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_refresh_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_polling_off_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_provide_local_info_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_setup_event_list_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_timer_management_ind_struct;

/* ----End Remote SAT---- */

typedef struct {
    kal_uint8 qos_length; /* QOS identifer bit*/
    kal_uint8 unused1; /* Unused Bit*/
    kal_uint8 delay_class;
    kal_uint8 reliability_class;
    kal_uint8 peak_throughput;
    kal_uint8 unused2; /* Unused Bit*/
    kal_uint8 precedence_class;
    kal_uint8 unused3; /* Unused Bit*/
    kal_uint8 mean_throughput;
    kal_uint8 traffic_class;
    kal_uint8 delivery_order;
    kal_uint8 delivery_of_err_sdu;
    kal_uint8 max_sdu_size;
    kal_uint8 max_bitrate_up_lnk;
    kal_uint8 max_bitrate_down_lnk;
    kal_uint8 residual_bit_err_rate;
    kal_uint8 sdu_err_ratio;
    kal_uint8 transfer_delay;
    kal_uint8 traffic_hndl_priority;
    kal_uint8 guarntd_bit_rate_up_lnk;
    kal_uint8 guarntd_bit_rate_down_lnk;
} sat_gprs_qos_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_more_time_res_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 priority;
    kal_uint8 clear_text_type;
    kal_uint8 immediate_res;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */
} sat_dspl_text_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 additional_info;
} sat_dspl_text_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 type_of_input;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */
} sat_get_inkey_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 is_yes_selected;
} sat_get_inkey_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 type_of_input;
    kal_uint8 is_input_revealed_to_user;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 len_of_min_input;
    kal_uint8 len_of_max_input;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_get_input_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_get_input_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 is_softkey_preferred;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 num_of_item;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_setup_menu_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_setup_menu_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 is_softkey_preferred;
    kal_uint8 type_of_presentation;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 is_item_id_available;
    kal_uint8 item_id;
    kal_uint8 num_of_item;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_select_item_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 item_id;
} sat_select_item_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 tone_id;
    kal_uint32 duration;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_play_tone_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_play_tone_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 condition;
    kal_uint32 duration;
    kal_uint8 type_of_modification;
    kal_uint8 is_icon1_available;
    sat_icon_struct icon_info1;
    kal_uint8 is_icon2_available;
    sat_icon_struct icon_info2;
    kal_uint8 size_of_ccp;
    kal_uint8 ccp[13];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_setup_call_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
} sat_setup_call_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 is_sms_packed_required;
    kal_uint8 size_of_addr;
    kal_uint8 addr[MAX_SIM_ADDR_LEN];
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_sms_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
} sat_send_sms_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 type_of_modification;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_ss_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 size_of_additional_info;
    kal_uint8 additional_info[255];
} sat_send_ss_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 type_of_modification;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_ussd_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 size_of_additional_info;
    kal_uint8 additional_info[255];
} sat_send_ussd_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 type;
    kal_uint8 size_of_ccp1;
    kal_uint8 ccp1[13];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_SUB_ADDR_BCD_LEN];
    kal_uint8 size_of_ccp2;
    kal_uint8 ccp2[13];
} sat_call_ctrl_by_sim_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 res;
    kal_uint8 type;
    kal_uint8 size_of_ccp1;
    kal_uint8 ccp1[13];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_SUB_ADDR_BCD_LEN];
    kal_uint8 is_bc_repeat_ind_avail;
    kal_uint8 bc_repeat_ind;
    kal_uint8 size_of_ccp2;
    kal_uint8 ccp2[13];
} sat_call_ctrl_by_sim_cnf_struct;

typedef sat_call_ctrl_by_sim_req_struct sat_ss_ctrl_by_sim_req_struct;
typedef sat_call_ctrl_by_sim_cnf_struct sat_ss_ctrl_by_sim_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 size_of_addr1;
    kal_uint8 addr1[MAX_SIM_ADDR_LEN];
    kal_uint8 size_of_addr2;
    kal_uint8 addr2[MAX_SIM_ADDR_LEN];
} sat_send_sms_ctrl_by_sim_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 res;
    kal_uint8 size_of_addr1;
    kal_uint8 addr1[MAX_SIM_ADDR_LEN];
    kal_uint8 size_of_addr2;
    kal_uint8 addr2[MAX_SIM_ADDR_LEN];
} sat_send_sms_ctrl_by_sim_cnf_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 size_of_addr;
    kal_uint8 addr[MAX_SIM_ADDR_LEN];
} sat_sms_dl_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 is_successful;
    kal_uint8 size_of_sim_ack_data;
    kal_uint8 sim_ack_data[128];
    kal_uint8 cause;
} sat_sms_dl_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 size_of_cb_page_data;
    kal_uint8 cb_page_data[88];
} sat_cb_dl_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_successful;
} sat_cb_dl_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 item_id;
    kal_uint8 is_help_info_requested;
} sat_menu_select_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_successful;
} sat_menu_select_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_bool is_full_changed;
    kal_uint8 refresh_type; /* Add for SIM REFRESH type */
    kal_uint8 num_of_file;
    kal_uint8 file_list[120];
} sat_file_change_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 is_successful;
} sat_file_change_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_imei_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_imei_valid;
    kal_uint8 imei[8];
} sat_imei_info_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mm_status;
    kal_uint8 location_info[7];
    /* mtk00714, 20080108: Remove the unused proactive cmd in the structure to decrease buffer usage */
    //sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
    kal_uint8 rat;	 /* rat_enum, in l3_inc_enums.h */     
} sat_location_info_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_time_zone_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 time_zone;
} sat_time_zone_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_current_time_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 time_info[6];
} sat_current_time_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mmi_info_type;
    kal_uint8 len_of_address;
    kal_uint8 address[MAX_SIM_ADDR_BCD_LEN];    
} sat_mmi_info_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_me_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 me_status;
    kal_uint8 timing_advance;    
} sat_me_status_cnf_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_nmr_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mm_status;
    kal_uint8 nmr[16];
    kal_uint8 size_of_bcch;
    kal_uint8 bcch[40];
} sat_nmr_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_language_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 language[2];
} sat_language_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_status;
} sat_call_status_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_setup_idle_dspl_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_setup_idle_dspl_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
} sat_run_at_command_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 size_of_at_response;
    kal_uint8 at_response[240];
} sat_run_at_command_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_dtmf_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 additional_info;
} sat_send_dtmf_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_language_specified;
    kal_uint8 iso639_language[2];
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_lang_notify_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_lang_notify_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 browser_mode;
    kal_uint8 browser_identity;
    kal_uint8 provision_file_id[10];
} sat_launch_browser_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 size_of_additional_info;
    kal_uint8 additional_info[255];
} sat_launch_browser_res_struct;

typedef struct {
    kal_uint8 addr_length; /* Address Length*/
    kal_uint8 addr_bcd[MAX_SIM_ADDR_BCD_LEN];
} sim_addr_bcd_struct;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ti;
    kal_bool is_mt_call;
} sat_evdl_call_connect_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ti;
    kal_bool is_far_end;
    //kal_bool cause_p;	
    //kal_uint8 cause;	
    kal_uint8 cause_len;				// Change data type [2006-9-5 Nick]
    kal_uint8 cause[30];				// Change data type [2006-9-5 Nick]
} sat_evdl_call_disconnect_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mm_status;
    kal_uint8 location_info[7];
} sat_evdl_location_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_evdl_user_activity_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_evdl_idle_screen_available_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 iso639_language[2];
} sat_evdl_language_selection_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 card_reader_status;
} sat_evdl_card_reader_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 browser_termination_cause;
} sat_evdl_browser_termination_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 channel_status[2];
    kal_uint8 channel_data_length;
} sat_evdl_data_available_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 channel_status[2];
} sat_evdl_channel_status_req_struct;

typedef struct {
    kal_uint8 p_class;
    kal_uint8 d_class;
    kal_uint8 r_class;
    kal_uint8 peak_rate;
    kal_uint8 mean_rate;
    kal_uint8 proto_type;
} sat_gprs_bearer_para_struct;

typedef struct {
    kal_uint8 speed;
    kal_uint8 service_name;
    kal_uint8 ce;
} sat_csd_bearer_para_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct gprs_bearer;
    sat_csd_bearer_para_struct csd_bearer;
    kal_uint16 buffer_size;
    kal_uint8 size_of_address;
    kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint32 duration1;
    kal_uint32 duration2;
    kal_uint16 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_uint16 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_uint8 protocol_type;  /* '01' UDP '02' TCP */
    kal_uint16 port_num;
    kal_int16 no_local_addr;
    kal_uint8 local_addr[16];
    kal_int16 no_dest_addr;
    kal_uint8 dest_addr[16];
    kal_uint8 dns[4];
    kal_uint8 apn[50];
    kal_uint8 apn_length;
} sat_open_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct gprs_bearer;
    sat_csd_bearer_para_struct csd_bearer;
    kal_uint16 buffer_size;
    kal_uint8 size_of_address;
    kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint32 duration1;
    kal_uint32 duration2;
    kal_uint16 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_uint16 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_uint8 protocol_type;  /* '01' UDP '02' TCP */
    kal_uint16 port_num;
    kal_int16 no_local_addr;
    kal_uint8 local_addr[16];
    kal_int16 no_dest_addr;
    kal_uint8 dest_addr[16];
    kal_uint8 dns[4];
    kal_uint8 apn[50];
    kal_uint8 apn_length;
} sat_open_gprs_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct gprs_bearer;
    sat_csd_bearer_para_struct csd_bearer;
    kal_uint16 buffer_size;
    kal_uint8 size_of_address;
    kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint32 duration1;
    kal_uint32 duration2;
    kal_uint16 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_uint16 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_uint8 protocol_type;  /* '01' UDP '02' TCP */
    kal_uint16 port_num;
    kal_int16 no_local_addr;
    kal_uint8 local_addr[16];
    kal_int16 no_dest_addr;
    kal_uint8 dest_addr[16];
    kal_uint8 dns[4];
    kal_uint8 apn[50];
    kal_uint8 apn_length;    
} sat_open_csd_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_status[2];
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct bearer_para;
    kal_uint16 buffer_size;
} sat_open_gprs_channel_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_status[2];
    kal_uint8 bearer;
    sat_csd_bearer_para_struct bearer_para;
    kal_uint16 buffer_size;
} sat_open_csd_channel_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_id;  // sat_channel_id_enum
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
} sat_close_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
} sat_close_channel_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_id; //sat_channel_id_enum
    kal_uint8 ch_type;
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 data_size;
} sat_send_data_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_type;
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_data_length;
} sat_send_data_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_id; //sat_channel_id_enum
    kal_uint8 ch_type;
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 ch_data_length;
} sat_recv_data_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_type;
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_data_length;
} sat_recv_data_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
} sat_ch_status_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 channel_status[2];
} sat_ch_status_res_struct;

#endif



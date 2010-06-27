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
 *  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES
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
 * MCD_PS2SAT_PEER_H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _MCD_PS2SAT_PEER_H
#define _MCD_PS2SAT_PEER_H
typedef struct sat_dspl_text_ind_peer_struct
{
	kal_uint16 no_text_string;
	kal_uint8 *text_string;
	kal_uint8 dcs_of_text_string;
} sat_dspl_text_ind_peer_struct;


typedef struct sat_get_inkey_ind_peer_struct
{
	kal_uint16 no_text_string;
	kal_uint8 *text_string;
	kal_uint8 dcs_of_text_string;
} sat_get_inkey_ind_peer_struct;


typedef struct sat_get_inkey_res_peer_struct
{
	kal_uint8 no_text_string;
	kal_uint8 *text_string;
	kal_uint8 dcs_of_text_string;
} sat_get_inkey_res_peer_struct;


typedef struct sat_get_input_ind_peer_struct
{
	kal_uint16 no_text_string;
	kal_uint8 *text_string;
	kal_uint8 dcs_of_text_string;
	kal_uint16 no_default_text;
	kal_uint8 *default_text;
	kal_uint8 dcs_of_default_text;
} sat_get_input_ind_peer_struct;


typedef struct sat_get_input_res_peer_struct
{
	kal_uint8 no_text_string;
	kal_uint8 *text_string;
	kal_uint8 dcs_of_text_string;
} sat_get_input_res_peer_struct;


typedef struct sat_setup_menu_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 dcs_of_alpha_id;
	kal_uint16 no_item_data;
	kal_uint8 *item_data;
	kal_uint8 no_item_icon_id_list;
	kal_uint8 *item_icon_id_list;
	kal_uint8 item_icon_list_attr;
	kal_uint8 no_next_action_ind_list;
	kal_uint8 *next_action_ind_list;
} sat_setup_menu_ind_peer_struct;


typedef struct sat_select_item_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 dcs_of_alpha_id;
	kal_uint16 no_item_data;
	kal_uint8 *item_data;
	kal_uint8 item_icon_list_attr;
	kal_uint8 no_item_icon_id_list;
	kal_uint8 *item_icon_id_list;
	kal_uint8 no_next_action_ind_list;
	kal_uint8 *next_action_ind_list;
} sat_select_item_ind_peer_struct;


typedef struct sat_play_tone_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 is_alpha_id_present;
} sat_play_tone_ind_peer_struct;


typedef struct sat_setup_call_ind_peer_struct
{
	kal_uint8 no_alpha_id1;
	kal_uint8 *alpha_id1;
	kal_uint8 is_alpha_id1_present;
	kal_uint8 dcs_of_alpha_id1;
	kal_uint8 no_addr;
	kal_uint8 *addr;
	kal_uint8 no_alpha_id2;
	kal_uint8 *alpha_id2;
	kal_uint8 is_alpha_id2_present;
	kal_uint8 dcs_of_alpha_id2;
} sat_setup_call_ind_peer_struct;


typedef struct sat_send_sms_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 no_sms_tpdu;
	kal_uint8 *sms_tpdu;
} sat_send_sms_ind_peer_struct;


typedef struct sat_send_ss_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 no_ss_string;
	kal_uint8 *ss_string;
} sat_send_ss_ind_peer_struct;


typedef struct sat_send_ussd_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 no_ussd_string;
	kal_uint8 *ussd_string;
	kal_uint8 dcs_of_ussd_string;
} sat_send_ussd_ind_peer_struct;


typedef struct sat_mmi_info_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} sat_mmi_info_ind_peer_struct;


typedef struct sat_addr_struct
{
	kal_uint8 no_addr;
	kal_uint8 *addr;
} sat_addr_struct;


typedef struct sat_setup_idle_dspl_ind_peer_struct
{
	kal_uint16 no_text_string;
	kal_uint8 *text_string;
	kal_uint8 dcs_of_text_string;
} sat_setup_idle_dspl_ind_peer_struct;


typedef struct sat_run_at_command_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 no_at_command;
	kal_uint8 *at_command;
} sat_run_at_command_ind_peer_struct;


typedef struct sat_send_dtmf_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 no_dtmf;
	kal_uint8 *dtmf;
} sat_send_dtmf_ind_peer_struct;


typedef struct sat_launch_browser_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 no_url;
	kal_uint8 *url;
	kal_uint8 no_bearer;
	kal_uint8 *bearer;
	kal_uint16 no_gateway;
	kal_uint8 *gateway;
	kal_uint8 dcs_of_gateway;
} sat_launch_browser_ind_peer_struct;


typedef struct sat_open_gprs_channel_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} sat_open_gprs_channel_ind_peer_struct;


typedef struct sat_open_csd_channel_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} sat_open_csd_channel_ind_peer_struct;


typedef struct sat_close_channel_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} sat_close_channel_ind_peer_struct;


typedef struct sat_send_data_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
	kal_uint8 no_data;
	kal_uint8 *data;
} sat_send_data_ind_peer_struct;


typedef struct sat_recv_data_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} sat_recv_data_ind_peer_struct;


typedef struct sat_recv_data_res_peer_struct
{
	kal_uint8 no_data;
	kal_uint8 *data;
} sat_recv_data_res_peer_struct;


typedef struct l4csat_open_channel_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} l4csat_open_channel_ind_peer_struct;


typedef struct l4csat_close_channel_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} l4csat_close_channel_ind_peer_struct;


typedef struct l4csat_send_data_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} l4csat_send_data_ind_peer_struct;


typedef struct l4csat_recv_data_ind_peer_struct
{
	kal_uint8 no_alpha_id;
	kal_uint8 *alpha_id;
	kal_uint8 is_alpha_id_present;
	kal_uint8 dcs_of_alpha_id;
} l4csat_recv_data_ind_peer_struct;


#endif /*_MCD_PS2SAT_PEER_H*/
